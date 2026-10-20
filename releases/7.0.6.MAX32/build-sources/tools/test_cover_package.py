"""Portable ZIP/name, preservation and input-guard regressions for the cover tool."""
import contextlib
import io
from pathlib import Path
import struct
import tempfile
import unittest
from unittest.mock import patch
import zipfile
import zlib
import lgu_repack as L
import patch_cover_final_packet as cover


def encrypted_zip(entries, comment=b''):
    """Small real ZipCrypto/DEFLATE ZIPs, including raw Windows member names."""
    out = bytearray()
    cd = bytearray()
    for name,data in entries:
        encoded = name.encode('ascii')
        crc = zlib.crc32(data)
        compressor = zlib.compressobj(6,zlib.DEFLATED,-15)
        compressed = compressor.compress(data)+compressor.flush()
        body = L.Cipher(L.PW).enc(b'fixture1234'+bytes([crc>>24])+compressed)
        offset = len(out)
        out += struct.pack('<I5H3I2H',0x04034b50,20,1,8,0,0,crc,len(body),len(data),len(encoded),0)+encoded+body
        cd += struct.pack('<I6H3I5H2I',0x02014b50,20,20,1,8,0,0,crc,len(body),len(data),
                          len(encoded),0,0,0,0,0,offset)+encoded
    offset = len(out)
    out += cd
    out += struct.pack('<I4H2IH',0x06054b50,0,0,len(entries),len(entries),len(cd),offset,len(comment))+comment
    return bytes(out)


class CoverPackageTests(unittest.TestCase):
    def test_read_raw_and_normalized_member_names(self):
        for separator in ('/','\\'):
            raw = encrypted_zip([(separator.join(['upgrade','Storage Card','Blue.exe']),b'blue')])
            with zipfile.ZipFile(io.BytesIO(raw)) as archive:
                self.assertEqual(L.read_member(archive,'upgrade/Storage Card/Blue.exe'),b'blue')
                self.assertEqual(L.read_member(archive,r'upgrade\Storage Card\Blue.exe'),b'blue')

    def test_replacement_preserves_raw_names_and_untouched_encrypted_member(self):
        raw = encrypted_zip([(r'upgrade\Storage Card\Blue.exe',b'old'),
                             (r'upgrade\Storage Card\NK.bin',b'keep this byte exact')],b'retained comment')
        new = L.rebuild(raw,{'upgrade/Storage Card/Blue.exe':b'new image'})
        old_rows,_,_ = L.parse(raw)
        new_rows,_,_ = L.parse(new)
        self.assertEqual([r['name'] for r in old_rows],[r['name'] for r in new_rows])
        for source,rows in [(raw,old_rows),(new,new_rows)]:
            row = rows[1]
            nl,xl = struct.unpack_from('<HH',source,row['off']+26)
            local = source[row['off']:row['off']+30+nl+xl+row['csize']]
            if source is raw:
                retained = local
            else:
                self.assertEqual(local,retained)
        with zipfile.ZipFile(io.BytesIO(new)) as archive:
            self.assertEqual(L.read_member(archive,'upgrade/Storage Card/Blue.exe'),b'new image')
            self.assertEqual(L.read_member(archive,'upgrade/Storage Card/NK.bin'),b'keep this byte exact')
            self.assertEqual(archive.comment,b'retained comment')

    def test_missing_replacement_is_rejected_instead_of_silently_ignored(self):
        with self.assertRaisesRegex(ValueError,'absent'):
            L.rebuild(encrypted_zip([('file',b'data')]),{'missing':b'new'})

    def test_normalized_duplicates_are_rejected(self):
        raw = encrypted_zip([(r'a\file',b'one'),('a/file',b'two')])
        with zipfile.ZipFile(io.BytesIO(raw)) as archive:
            with self.assertRaisesRegex(ValueError,'Duplicate'):
                L.zip_index(archive)
        with self.assertRaisesRegex(ValueError,'Duplicate'):
            L.rebuild(raw,{'a/file':b'new'})

    def test_unsafe_paths_are_rejected(self):
        for name in ('../file','/file','C:/file','a/../file','a//file'):
            with self.subTest(name=name),self.assertRaises(ValueError):
                L.canonical(name)

    def test_version_label_cannot_resize_header(self):
        for invalid in ('','X'*20,'é','version\x00extra'):
            with self.subTest(version=invalid),self.assertRaises(ValueError):
                L.version_bytes(invalid)
        header = bytearray(1024)
        header[:4] = b'LGU0'
        struct.pack_into('<II',header,4,7,1024)
        z = encrypted_zip([('file',b'data')])
        packed = L.pack(header,z,'7.0.6.COVERTEST')
        self.assertEqual(len(packed),1024+len(z))
        self.assertEqual(L.unpack(packed),z)

    def test_wrong_baselines_are_rejected(self):
        with self.assertRaisesRegex(ValueError,'MAX31'):
            cover.patch_package(b'not the official LGU')
        with self.assertRaisesRegex(ValueError,'MAX31'):
            cover.patch_blue(b'not Blue.exe')

    def test_lgu_crc_corruption_is_rejected(self):
        header = bytearray(1024)
        header[:4] = b'LGU0'
        struct.pack_into('<II',header,4,7,1024)
        packed = bytearray(L.pack(header,encrypted_zip([('file',b'data')])))
        packed[-1] ^= 1
        with self.assertRaisesRegex(ValueError,'CRC'):
            L.unpack(packed)

    def test_existing_output_is_preserved(self):
        with tempfile.TemporaryDirectory() as folder:
            output = Path(folder)/'existing.lgu'
            output.write_bytes(b'preserve me')
            with patch('sys.argv',['patch_cover_final_packet.py','missing-source',str(output)]):
                with contextlib.redirect_stderr(io.StringIO()),self.assertRaises(SystemExit):
                    cover.main()
            self.assertEqual(output.read_bytes(),b'preserve me')


if __name__=='__main__':
    unittest.main()
