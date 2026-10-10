/* Native BMP preview at recovered constructor positions; external data is fixture-only. */
(async()=>{
 const {spriteSlice}=await import('./av_sprite_layout.mjs');
 const response=await fetch('av.json',{cache:'no-store'});if(!response.ok)return;const data=await response.json();
 const $=id=>document.getElementById(id),tab=document.createElement('button');
 tab.id='avTab';tab.textContent='Radio / Media / Phone';tab.setAttribute('aria-pressed','false');document.querySelector('.tabs').append(tab);
 const section=document.createElement('section');section.id='avPreview';section.hidden=true;
 section.innerHTML=`<h2>Radio, Media &amp; Phone / bestaande posities</h2><p class="note">De nieuwe native M1-afbeeldingen naast 7.0.5.MD. Zendernamen, muziek en contacten zijn voorbeelddata. Navigatie blijft buiten deze wijziging.</p>
 <div class="toolbar"><label>Scherm <select id="avScreen" aria-label="AV screen"></select></label><label>Knop <select id="avControl" aria-label="AV control"></select></label><label>Stand <select id="avState" aria-label="AV state"><option value="0">Normaal</option><option value="1">Ingedrukt</option><option value="2">Uitgeschakeld</option><option value="3">Geselecteerd</option></select></label><label><input id="avHits" type="checkbox">Aanraakvlakken</label><label><input id="avRaw" type="checkbox">Alle constructor-controls</label><label><input id="avCallBank" type="checkbox">Ophangen / pauze</label></div>
 <p id="avSummary" class="metadata" role="status"></p>
 <div class="home-pair"><figure><figcaption>Origineel / 7.0.5.MD</figcaption><canvas id="avBefore" width="800" height="480" aria-label="Original AV screen"></canvas></figure><figure><figcaption>Charcoal / ontwikkelversie</figcaption><canvas id="avAfter" width="800" height="480" aria-label="Themed AV screen"></canvas></figure></div>
 <p class="note">Klik op een knop om de geselecteerde stand te bekijken. Dit is een grafische reconstructie met native afbeeldingen; het voert geen firmware of apparaatfuncties uit. Lettertypen en dynamische zichtbaarheid zijn benaderingen. Met ‘Alle constructor-controls’ zie je ook alternatieven die normaal niet tegelijk zichtbaar zijn.</p>
 <p class="note">${data.changed_assets} radio/media/telefoon-afbeeldingen aangepast; BMP-afmetingen, transparantie en bestandsformaat behouden. Een afzonderlijke cosmetische tekstkleurwijziging is in 106 begrensde initialisatiegevallen gecontroleerd. Nog niet getest op de unit of in alle kleurprofielen.</p>`;
 document.querySelector('main').prepend(section);
 const names={
  '0xa11dc':'Radio · FM','0x9efe4':'Radio · zenderlijst','0xa79b8':'Radio · presets','0xa4054':'Radio · opties',
  '0x8b1cc':'Radio · AM','0x97a84':'Radio · DAB','0xaa42c':'Radio · bronkeuze',
  '0x4c26c':'Media · USB-speler','0x49374':'Media · USB-lijst','0x4ebd8':'Media · opties',
  '0x3b05c':'Media · Bluetooth','0x421ec':'Media · iPod','0x47bc0':'Media · bronkeuze',
  '0x55548':'Telefoon · contacten','0x5d870':'Telefoon · toetsen / gesprek','0x62458':'Telefoon · uitgaand gesprek',
  '0x6c51c':'Telefoon · zoeken'};
 const preferred=Object.keys(names),cases=[...preferred.map(e=>data.scenarios.find(s=>s.entry===e)),...data.scenarios.filter(s=>!preferred.includes(s.entry))].filter(Boolean);
 function option(v,t){const o=document.createElement('option');o.value=v;o.textContent=t;return o}
 function screenOptions(){const old=$('avScreen').value;$('avScreen').replaceChildren(...cases.map((s,i)=>({s,i})).filter(({s})=>$('avRaw').checked||names[s.entry]).map(({s,i})=>option(i,names[s.entry]??`${s.group} · constructor ${s.entry}`)));$('avScreen').value=[...$('avScreen').options].some(o=>o.value===old)?old:'0'}
 screenOptions();
 let serial=0;const cache=new Map();
 function source(variant,name){return `av/${variant}/${name.replaceAll('\\','/').replace(/\.bmp$/i,'.png')}?v=${encodeURIComponent(data.candidate??'av-03')}-${encodeURIComponent(data.asset_revision??'')}`}
 function load(url){if(!cache.has(url)){const i=new Image();i.src=url;cache.set(url,i.decode().then(()=>i))}return cache.get(url)}
 function scenario(){return cases[+$('avScreen').value]}
 function visible(s){
  if($('avRaw').checked)return s.controls;
  return s.controls.filter(r=>{
   const f=(r.filename??'').toLowerCase(),o=r.object_offset;
   if(s.entry==='0xa4054'&&['0x14e0','0x4dec','0x535c','0x58cc','0x5b78'].includes(o))return false;
   if(s.entry==='0x55548'&&/phone_list_(home|office|mobile|other)/i.test(f))return /mobile/i.test(f);
   if(s.entry==='0x6c51c'&&(/phonebook|list_press|list_scroll|scrollnumber/.test(f)||['0x28f0'].includes(o)))return false;
   // A call keypad and outgoing-call page have conditional empty labels;
   // leave these empty unless a fixture explicitly sets their content.
   return true;
  });
 }
 function label(r){return r.text||r.filename?.split('\\').pop()?.replace(/\.bmp$/i,'').replace(/^(fmradio|media|phone)_/i,'').replaceAll('_',' ')||`control ${r.object_offset}`}
 function controls(){const old=$('avControl').value;const list=visible(scenario()).filter(r=>['button','list','progress'].includes(r.kind));$('avControl').replaceChildren(option('','Geen'),...list.map(r=>option(r.object_offset,label(r))));$('avControl').value=list.some(r=>r.object_offset===old)?old:''}
 function fixture(s,r,secondary=false){
  const f=(r.filename??'').toLowerCase(),o=r.object_offset,entry=s.entry;
  if(secondary){if(/presets_list|nearby_list/.test(f))return String(s.controls.filter(c=>c.kind==='list').indexOf(r)+1);return ''}
  if(entry==='0xa11dc')return {'0x24e0':'NPO Radio 2','0x278c':'FM','0x2a38':'92.','0x2ce4':'6','0x323c':'Muziek zegt alles'}[o]??r.text??'';
  if(entry==='0x4c26c')return {'0x934':'Speed of Sound','0xbe0':'COLDPLAY','0xe8c':'1:24','0x11e0':'4:48'}[o]??r.text??'';
  // This native source header has a narrow label area next to its up arrow.
  // Use the same compact source name as its BT choice; dynamic text is a fixture.
  if(entry==='0x47bc0'&&o==='0x39c')return 'BT';
  if(entry==='0x55548'){
   if(o==='0x2c8')return 'iPhone';
   if(/phone_list_press/.test(f))return ['Nina','Sam','Alex','Robin'][Math.max(0,s.controls.filter(c=>/phone_list_press/i.test(c.filename??'')).indexOf(r))];
  }
  if(entry==='0x5d870'||entry==='0x62458')return {'0x2c8':'iPhone','0x934':'06 1234 5678','0x26b0':'00:42'}[o]??r.text??'';
  if(/presets_list/.test(f))return ['Radio 1','Radio 2','Radio 3','Radio 4','Radio 5','Radio 6'][s.controls.filter(c=>c.kind==='list').indexOf(r)]??'';
  if(r.kind==='list')return (s.group==='radio'?['NPO Radio 1','NPO Radio 2','Radio 538','Qmusic']:['Coldplay','Speed of Sound','Fix You','Talk'])[s.controls.filter(c=>c.kind==='list').indexOf(r)%4];
  if(entry==='0x49374'&&o==='0xea4')return 'Music / Coldplay';
  if(entry==='0x6c51c'){
   if(/keyboard[23]?_\d+_btn/.test(f))return r.text||'QWERTYUIOPASDFGHJKLZXCVBNM'[r.event-1014]||'';
   if(/search_results_btn/.test(f))return 'Zoeken op naam';
  }
  if(r.rect[0]===33&&r.rect[1]===0&&!r.text)return s.group==='media'?'Bluetooth':'FM';
  return r.text??'';
 }
 function drawLabel(ctx,s,r,state,secondary=false){
  const text=fixture(s,r,secondary);if(!text)return;const l=secondary?r.secondary_label:r;if(!l)return;
  const [x,y,w,h]=l.label_rect??r.rect;if(w<=0||h<=0)return;
  let color=l.colors?.[state]??0xffffff;
  ctx.save();ctx.beginPath();ctx.rect(x,y,w,h);ctx.clip();
  ctx.fillStyle=`rgb(${color&255},${(color>>>8)&255},${(color>>>16)&255})`;
  ctx.font=`400 ${data.font_heights[l.font_index??8]??26}px Tahoma`;ctx.textBaseline='middle';
  const align=l.text_flags===undefined?1:l.text_flags&3;ctx.textAlign=align===0?'left':align===2?'right':'center';
  ctx.fillText(text,align===0?x:align===2?x+w:x+w/2,y+h/2);ctx.restore();
 }
 async function draw(variant,canvas,s,generation){
  const records=visible(s),bg=`common/${s.group==='radio'?'fmradio':s.group==='phone'?'phone':'media'}_bg.bmp`;
  const names=[bg,'common/common_indi_clock_number_img.bmp','common/common_indi_semicolon_img.bmp',...records.map(r=>r.filename).filter(Boolean)];
  const pairs=await Promise.all([...new Set(names)].map(async n=>[n,await load(source(variant,n))]));if(generation!==serial)return;
  const images=new Map(pairs),ctx=canvas.getContext('2d');ctx.clearRect(0,0,800,480);ctx.drawImage(images.get(bg),0,0);
  for(const r of records){
   const [x,y,w,h]=r.rect;if(w<=0||h<=0)continue;
   const state=r.object_offset===$('avControl').value?+$('avState').value:0;
   let name=r.filename,image=name&&images.get(name);
   if($('avCallBank').checked&&/media_control_[12]_play_btn/i.test(name??'')){
    const pause=name.replace('_play_btn','_pause_btn');image=await load(source(variant,pause));
   }
   if(generation!==serial)return;
   if(image){
    const rect=r.sprite_rect??r.rect,[dx,dy,dw,dh]=rect;
    const states=/(_btn|_press)/i.test(name)?4:1;
    // The constructor's variant argument is not always a sprite-bank count.
    // BT has four complete 187px combined play/pause frames, while the call
    // and search toggles really have two banks of four native-width frames.
    const {frameWidth,sourceX:sx}=spriteSlice(image.width,dw,states,r.variant_count??1,state,$('avCallBank').checked);
    if(r.kind==='progress'){
     const fw=image.width/2;ctx.drawImage(image,fw,0,fw*.29,Math.min(dh,image.height),dx,dy,dw*.29,dh);
    }else ctx.drawImage(image,sx,0,Math.min(frameWidth,image.width-sx),Math.min(dh,image.height),dx,dy,dw,dh);
   }
   drawLabel(ctx,s,r,state);if(r.secondary_label)drawLabel(ctx,s,r,state,true);
   if($('avHits').checked&&['button','list','progress'].includes(r.kind)){ctx.strokeStyle='#70e1cf';ctx.lineWidth=1;ctx.strokeRect(x+.5,y+.5,w,h)}
  }
  if(!/keyboard/.test(records[0]?.filename??'')){
   for(const [i,x] of [686,708,744,766].entries())ctx.drawImage(images.get(names[1]),[0,9,5,8][i]*20,0,20,33,x,16,20,33);
   ctx.drawImage(images.get(names[2]),731,16);
  }
 }
 async function render(){
  const n=++serial,s=scenario(),original=data.original_scenarios.find(o=>o.entry===s.entry);
  $('avSummary').dataset.ready='false';
  $('avSummary').textContent=`800 × 480 · ${names[s.entry]??s.entry} · native constructor ${s.entry} · ${visible(s).length} controls · voorbeelddata / Tahoma-benadering`;
  try{await Promise.all([draw('original',$('avBefore'),original,n),draw('themed',$('avAfter'),s,n)]);if(n===serial)$('avSummary').dataset.ready='true'}
  catch(e){$('avSummary').textContent=`Preview niet geladen: ${e.message}`;$('avSummary').dataset.ready='error'}
 }
 function show(){for(const id of ['resources','concept','homePreview'])if($(id))$(id).hidden=true;section.hidden=false;for(const b of document.querySelectorAll('.tabs button'))b.setAttribute('aria-pressed',String(b===tab));render()}
 tab.onclick=show;for(const id of ['assetsTab','conceptTab','homeTab'])if($(id))$(id).addEventListener('click',()=>{section.hidden=true;tab.setAttribute('aria-pressed','false')});
 $('avScreen').onchange=()=>{controls();render()};$('avRaw').onchange=()=>{screenOptions();controls();render()};for(const id of ['avControl','avState','avHits','avCallBank'])$(id).onchange=render;
 for(const id of ['avBefore','avAfter'])$(id).onclick=e=>{const bounds=e.currentTarget.getBoundingClientRect(),x=(e.clientX-bounds.left)*800/bounds.width,y=(e.clientY-bounds.top)*480/bounds.height;
  const r=[...visible(scenario())].reverse().find(r=>['button','list','progress'].includes(r.kind)&&r.event&&r.rect[0]<=x&&x<=r.rect[0]+r.rect[2]&&r.rect[1]<=y&&y<=r.rect[1]+r.rect[3]);
  if(r){$('avControl').value=r.object_offset;$('avState').value='3';render()}};
 controls();if(location.hash==='#av')show();
})().catch(e=>{const error=document.getElementById('error');error.hidden=false;error.textContent=String(e)});
