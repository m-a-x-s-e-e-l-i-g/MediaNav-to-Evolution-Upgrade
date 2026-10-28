"""Known native-format edge cases, independent of a car's private backup."""
import struct,tempfile,unittest,zlib
from pathlib import Path
from inspect_vehicle_config import inspect

class ConfigTests(unittest.TestCase):
    def inspect(self,files):
        with tempfile.TemporaryDirectory()as temp:
            root=Path(temp)
            for name,b in files.items():
                p=root/name;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(b)
            return inspect(root)
    @staticmethod
    def dsi(profile=1,header=None):
        b=bytearray(32);b[:8]=bytes([1,1,1,6,0,3,1,profile<<6])
        if header is not None:b[0]=header
        return bytes(b)+struct.pack('<I',zlib.crc32(b))
    def test_all_native_profiles_including_zero(self):
        for profile in range(4):
            r=self.inspect({'DSI_config.bsd':self.dsi(profile)})
            self.assertTrue(r['dsi']['usable_by_native_loader']);self.assertEqual(r['dsi']['profile_bits'],profile)
    def test_crc_and_header_rejected_independently(self):
        b=bytearray(self.dsi());b[8]^=1
        r=self.inspect({'DSI_config.bsd':bytes(b)})['dsi'];self.assertFalse(r['crc_valid']);self.assertTrue(r['header_valid'])
        r=self.inspect({'DSI_config.bsd':self.dsi(header=32)})['dsi'];self.assertTrue(r['crc_valid']);self.assertFalse(r['header_valid'])
    def test_truncated_and_oversized_files_do_not_decode(self):
        for n in [0,1,31,32,35,37,100000]:
            r=self.inspect({'DSI_config.bsd':bytes(n)})['dsi'];self.assertNotIn('profile_bits',r)
        r=self.inspect({'EcoDrive.cfg':bytes(8),'MgrSys.cfg':bytes(97)})
        self.assertNotIn('temperature_units_setting',r['eco']);self.assertNotIn('inverse_preference',r['mgrsys'])
    def test_backup_layout_and_eco_checksum(self):
        eco=bytearray(struct.pack('<II',1,2));eco.append(3)
        r=self.inspect({'Storage Card/System/DSI_config.bsd':self.dsi(),'Storage Card2/EcoDrive.cfg':bytes(eco)})
        self.assertTrue(r['dsi']['usable_by_native_loader']);self.assertTrue(r['eco']['xor_valid']);self.assertEqual(r['eco']['temperature_units_setting'],2)
        eco[-1]^=1;self.assertFalse(self.inspect({'EcoDrive.cfg':bytes(eco)})['eco']['xor_valid'])
    def test_registry_failures_are_not_zero_values(self):
        log=b'registry sample=0 open_status=0\nreg UI_TYPE status=2 type=4 bytes=4\nreg HMI_TEMP_CNF status=0 type=1 bytes=4 value=0\n'
        r=self.inspect({'capture.txt':log});self.assertEqual(r['registry'][0]['values'],{});self.assertFalse(r['capture_complete'])
    def test_snapshot_mismatch_is_observation_not_repair(self):
        log=b'registry sample=0 open_status=0\nreg UI_TYPE status=0 type=4 bytes=4 value=0\ntemp sample=0 current_raw=3 target_raw=59 units=1 enabled=1\ntemp sample=1 current_raw=255 target_raw=255 units=1 enabled=1\n'
        r=self.inspect({'DSI_config.bsd':self.dsi(),'capture.txt':log})
        self.assertTrue(any('differs'in s for s in r['findings']));self.assertFalse(r['physical_resolution_confirmed'])
        self.assertEqual(r['temperature_samples'][0]['native_celsius_if_units_1'],-37);self.assertTrue(r['temperature_samples'][1]['native_invalid_sentinel'])

if __name__=='__main__':unittest.main()
