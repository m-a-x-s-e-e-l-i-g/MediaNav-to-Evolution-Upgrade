// Regression fixtures use actual original BMP dimensions and recovered control widths.
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { fileURLToPath } from 'node:url';
import { spriteSlice } from './av_sprite_layout.mjs';

const root = fileURLToPath(new URL('../extracted/705md/upgrade/Storage Card/System/Img/M1/', import.meta.url));
const fixtures = [
  { name:'media/media_bt_control_play_pause_btn.bmp', width:187, height:83, banks:1 },
  { name:'Phone/phone_dial_btn_call.bmp', width:142, height:147, banks:2 },
  { name:'Phone/phone_keyboard_search_results_list_down_btn.bmp', width:160, height:85, banks:2 },
];
let checked = 0;
for (const fixture of fixtures) {
  const bmp = await readFile(root + fixture.name);
  const width = bmp.readInt32LE(18);
  assert.equal(bmp.toString('ascii',0,2),'BM');
  assert.equal(Math.abs(bmp.readInt32LE(22)),fixture.height);
  assert.equal(width,fixture.width * 4 * fixture.banks);
  for (const alternate of [false,true]) for (let state=0;state<4;state++) {
    const slice = spriteSlice(width,fixture.width,4,2,state,alternate);
    const expectedBank = alternate && fixture.banks===2 ? 1 : 0;
    assert.equal(slice.banks,fixture.banks,fixture.name);
    assert.equal(slice.frameWidth,fixture.width,fixture.name);
    assert.equal(slice.sourceX,(expectedBank*4+state)*fixture.width,fixture.name);
    assert.ok(slice.sourceX+slice.frameWidth<=width);
    checked++;
  }
}
console.log(`${checked} sprite selections passed against three native bitmap fixtures.`);
