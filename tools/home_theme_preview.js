/* Desktop reconstruction from recorded native control geometry; no firmware execution. */
(async()=>{
 const response=await fetch('home.json',{cache:'no-store'});if(!response.ok)return;
 const data=await response.json();
 const nativeTab=document.createElement('button');nativeTab.id='homeTab';nativeTab.textContent='Home preview';nativeTab.setAttribute('aria-pressed','false');
 document.querySelector('.tabs').prepend(nativeTab);
 const section=document.createElement('section');section.id='homePreview';section.hidden=true;
 section.innerHTML=`<h2>Home screen / original and charcoal skin</h2>
 <p class="note">Actual candidate M1 BMPs, decoded for preview. Original control positions. Desktop font rendering is approximate; this does not execute firmware.</p>
 <div class="toolbar"><label>Layout <select id="homeLayout" aria-label="Home layout"></select></label><label>Control <select id="homeControl" aria-label="Home control"></select></label><label>State <select id="homeState" aria-label="Home state"><option value="0">Normal</option><option value="1">Pressed</option><option value="2">Disabled</option><option value="3">Selected</option></select></label><label><input id="callPreview" type="checkbox">Call interruption</label><label><input id="hitPreview" type="checkbox">Show touch areas</label><label><input id="timePreview" type="checkbox">Set Time control</label></div>
 <p id="homeSummary" class="metadata" role="status"></p>
 <div class="home-pair"><figure><figcaption>Original / 7.0.5.MD</figcaption><canvas id="homeBefore" width="800" height="480" aria-label="Original home screen"></canvas></figure><figure><figcaption>Charcoal skin / development candidate</figcaption><canvas id="homeAfter" width="800" height="480" aria-label="Themed home screen"></canvas></figure></div>
 <p class="note">${data.white_active_labels?'Pressed and selected tiles use black backgrounds, function-colored outlines and white labels. White labels require a two-byte change to the home text-color stores in AppMain; all 24 bounded layout cases were verified.':'Pressed and selected tiles fade to lighter amber behind the existing black labels.'} The original BMP contracts remain unchanged. Click a tile to inspect its selected state; no radio, navigation or device action runs.</p>
 <p class="note">Home-only candidate: 14 image resources changed; ${data.unchanged_files.toLocaleString('en-US')} package files remain byte-identical.${data.white_active_labels?' The two text-color stores are shared by all home profiles; M0/inverse artwork still needs review before installation.':' Every executable remains unchanged.'} The separate Radio / Media / Phone tab shows the cumulative AV candidate. Other applications still use their original resources. Native loading and rendering have not been tested on the unit.</p>`;
 document.querySelector('main').prepend(section);
 const style=document.createElement('style');style.textContent='.home-pair{display:grid;grid-template-columns:repeat(2,minmax(0,1fr));gap:20px}.home-pair figure{margin:0}.home-pair figcaption{margin:0 0 8px;color:#bdc9d0}.home-pair canvas{width:100%;border:1px solid #46525b;background:#101519;cursor:pointer}.home-pair canvas:focus-visible{outline:2px solid #f9bc45}@media(max-width:1300px){.home-pair{grid-template-columns:1fr}.home-pair figure{max-width:800px}}';document.head.append(style);
 const get=id=>document.getElementById(id),cache=new Map();let generation=0;
 const option=(value,label)=>{const o=document.createElement('option');o.value=value;o.textContent=label;return o};
 for(let i=0;i<data.scenarios.length;i++){const s=data.scenarios[i];get('homeLayout').append(option(i,`${s.map_layout?(s.eco?'Five':'Four'):'Six'} functions${s.eco?' · Eco':''}${s.smartphone?' · Voice assistant':' · Phone'}`))}
 function active(s){return s.controls.filter(r=>((![0x35,0x37].includes(r.image_id))||get('timePreview').checked)&&(!(s.map_layout&&[0x30,0x31].includes(r.image_id))))}
 function scenario(){return data.scenarios[Number(get('homeLayout').value)]}
 function populateControls(){const existing=get('homeControl').value;get('homeControl').replaceChildren(...active(scenario()).filter(r=>r.kind==='button'&&r.text).map(r=>option(r.event,r.text)));get('homeControl').value=[...get('homeControl').options].some(o=>o.value===existing)?existing:'1006'}
 function load(url){if(!cache.has(url)){const image=new Image();image.src=url;cache.set(url,image.decode().then(()=>image))}return cache.get(url)}
 function uri(variant,filename){return `home/${variant}/${filename.replaceAll('\\','/').replace(/\.bmp$/i,'.png')}?v=${encodeURIComponent(data.candidate??'home-07')}`}
 async function draw(variant,canvas,s,records,serial){
  const urls=['common/home_bg.bmp','common/common_indi_clock_number_img.bmp','common/common_indi_semicolon_img.bmp',...records.map(r=>r.filename)];
  const images=await Promise.all(urls.map(name=>load(uri(variant,name))));if(serial!==generation)return;
  const context=canvas.getContext('2d');context.clearRect(0,0,800,480);context.drawImage(images[0],0,0);
  for(let i=0;i<records.length;i++){
   const r=records[i],[x,y,w,h]=r.rect;if(!w||!h)continue;
   let state=r.event===Number(get('homeControl').value)?Number(get('homeState').value):0;
   if(get('callPreview').checked&&[1001,1002,1006,1008].includes(r.event))state=2;
   context.drawImage(images[i+3],state*w,0,w,h,x,y,w,h);
   if(r.kind==='button'&&r.text){const [tx,ty,tw,th]=r.label_rect,c=r.colors[state];context.fillStyle=`rgb(${c&255},${(c>>>8)&255},${(c>>>16)&255})`;context.font=`400 ${data.font_heights[r.font_index]}px Tahoma`;context.textAlign='center';context.textBaseline='middle';context.fillText(r.text,tx+tw/2,ty+th/2,tw)}
   if(get('hitPreview').checked&&r.kind==='button'){context.strokeStyle='rgba(80,223,210,.8)';context.lineWidth=1;context.strokeRect(x+.5,y+.5,w,h);context.fillStyle='#7dded5';context.font='12px Tahoma';context.textAlign='left';context.textBaseline='top';context.fillText(String(r.event),x+6,y+5)}
  }
  for(const [i,x] of [686,708,744,766].entries()){const num=[0,9,5,8][i];context.drawImage(images[1],num*20,0,20,33,x,16,20,33)}context.drawImage(images[2],731,16);
 }
 async function render(){const serial=++generation,s=scenario(),records=active(s),original=data.original_scenarios?.[Number(get('homeLayout').value)]??s;get('homeSummary').textContent=`800 × 480 · ${get('homeLayout').selectedOptions[0].textContent} · ${get('homeControl').selectedOptions[0]?.textContent??''}: ${get('homeState').selectedOptions[0].textContent}${get('callPreview').checked?' · Radio/Media/Settings disabled during call fixture':''} · host Tahoma approximation`;try{await Promise.all([draw('original',get('homeBefore'),original,active(original),serial),draw('themed',get('homeAfter'),s,records,serial)])}catch(error){get('homeSummary').textContent=`Cannot load preview: ${error.message}`}}
 function showHome(){get('resources').hidden=true;get('concept').hidden=true;section.hidden=false;for(const id of ['assetsTab','conceptTab'])get(id).setAttribute('aria-pressed','false');nativeTab.setAttribute('aria-pressed','true');render()}
 nativeTab.onclick=showHome;for(const id of ['assetsTab','conceptTab'])get(id).addEventListener('click',()=>{section.hidden=true;nativeTab.setAttribute('aria-pressed','false')});
 get('homeLayout').onchange=()=>{populateControls();render()};get('timePreview').onchange=()=>{populateControls();render()};for(const id of ['homeControl','homeState','callPreview','hitPreview'])get(id).onchange=render;
 for(const id of ['homeBefore','homeAfter'])get(id).onclick=event=>{const canvas=get(id),bounds=canvas.getBoundingClientRect();const x=(event.clientX-bounds.left)*800/bounds.width,y=(event.clientY-bounds.top)*480/bounds.height;const records=active(scenario());const r=[...records].reverse().find(r=>r.kind==='button'&&r.text&&r.rect[0]<=x&&x<=r.rect[0]+r.rect[2]&&r.rect[1]<=y&&y<=r.rect[1]+r.rect[3]);if(r){get('homeControl').value=r.event;get('homeState').value='3';render()}};
 populateControls();if(location.hash!=='#av')showHome();
})().catch(error=>{const el=document.getElementById('error');el.hidden=false;el.textContent=String(error)});
