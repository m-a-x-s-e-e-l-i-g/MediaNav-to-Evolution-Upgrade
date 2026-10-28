/* Read-only WinCE/MIPS vehicle diagnosis. All writes are CREATE_NEW on USB.
 * No serial/MCU, registry-write, delete, move, termination or reboot imports. */
typedef unsigned int U;
typedef unsigned short W;
typedef unsigned char B;
typedef void *H;
#define BAD ((H)0xffffffffu)
#define NONE 0xffffffffu
enum {OPEN,READ,WRITE,CLOSE,SIZE,ATTR,MKDIR,FLUSH,LAST,BOX,TICK,SLEEP,
      REGOPEN,REGQUERY,REGCLOSE,OPENPROC,RPM,SNAPSHOT,FIRSTPROC,NEXTPROC,CLOSESNAP,API_COUNT};
volatile U imports[API_COUNT];
#define FN(n,t) ((t)(imports[n]))
#define close(h) FN(CLOSE,U(*)(H))(h)
#define last() FN(LAST,U(*)(void))()
#define attrs(p) FN(ATTR,U(*)(const W*))(p)
void *memcpy(void *d,const void *s,U n){B *a=d;const B *b=s;while(n--)*a++=*b++;return d;}
void *memset(void *d,int c,U n){B *a=d;while(n--)*a++=(B)c;return d;}
#include "probe_sha.h"
#include "probe_pin.h"
static W folder[260],path[260];
static B io[4096];
static char line[800];
static U used,failed;
static H loghandle;
static U len(const W *s){U n=0;while(s[n])n++;return n;}
static W lower(W c){return c>='A'&&c<='Z'?c+32:c;}
static U eq(const W *a,const W *b){while(*a&&lower(*a)==lower(*b)){a++;b++;}return *a==*b;}
static const W *base(const W *s){const W *p=s;while(*s){if(*s=='\\'||*s=='/')p=s+1;s++;}return p;}
static void append(W *s,const W *t){U n=len(s);while(*t&&n<258)s[n++]=*t++;s[n]=0;}
static void number(W *s,U x){W a[12];U n=0;do{a[n++]=(W)('0'+x%10);x/=10;}while(x);while(n){W q[2]={a[--n],0};append(s,q);}}
static void text(const char *s){while(*s&&used<sizeof(line)-2)line[used++]=*s++;}
static void num(U x){char a[12];U n=0;do{a[n++]=(char)('0'+x%10);x/=10;}while(x);while(n&&used<sizeof(line)-2)line[used++]=a[--n];}
static void hex(const B *p,U n){static const char h[]="0123456789abcdef";for(U i=0;i<n&&used<sizeof(line)-3;i++){line[used++]=h[p[i]>>4];line[used++]=h[p[i]&15];}}
static H openfile(const W *p,U access,U share,U create){return FN(OPEN,H(*)(const W*,U,U,H,U,U,H))(p,access,share,0,create,0x80,0);}
static U readfile(H h,void *p,U n,U *got){return FN(READ,U(*)(H,void*,U,U*,H))(h,p,n,got,0);}
static U writeall(H h,const B *b,U n){while(n){U got=0;if(!FN(WRITE,U(*)(H,const B*,U,U*,H))(h,b,n,&got,0)||!got||got>n)return 0;b+=got;n-=got;}return FN(FLUSH,U(*)(H))(h);}
static void emit(void){line[used++]='\r';line[used++]='\n';if(!writeall(loghandle,(const B*)line,used))failed=1;used=0;}
static void field(const char *s,U x){text(s);num(x);}
static U size(H h,U *n){U high=0;*n=FN(SIZE,U(*)(H,U*))(h,&high);return *n!=NONE&&!high;}
static U newfolder(void){
    if((attrs(L"\\MD")&16)==0||attrs(L"\\MD")==NONE)return 0;
    U a=attrs(L"\\MD\\MAXmade");
    if(a==NONE){if(!FN(MKDIR,U(*)(const W*,H))(L"\\MD\\MAXmade",0))return 0;}
    else if(!(a&16))return 0;
    U tick=FN(TICK,U(*)(void))();
    for(U i=0;i<100;i++){
        folder[0]=0;append(folder,L"\\MD\\MAXmade\\vehicle-config-");number(folder,tick);append(folder,L"-");number(folder,i);
        /* Never reuse any existing path, even a partial earlier capture. */
        if(attrs(folder)!=NONE)continue;
        if(FN(MKDIR,U(*)(const W*,H))(folder,0))return 1;
        if(last()!=183&&last()!=80)return 0;
    }return 0;
}
static void filename(const W *name){path[0]=0;append(path,folder);append(path,L"\\");append(path,name);}
static void capture(const W *source,const W *name,const char *label,U limit){
    text("file ");text(label);H h=openfile(source,0x80000000u,3,3);
    if(h==BAD){field(" open_error=",last());emit();return;}
    U n=0,ok=size(h,&n);field(" bytes=",n);
    if(!ok||n>limit){text(" skipped_size");close(h);emit();return;}
    U done=0;while(done<n){U got=0;if(!readfile(h,io+done,n-done,&got)||!got||got>n-done){ok=0;break;}done+=got;}
    B extra;U got=0;if(ok&&(!readfile(h,&extra,1,&got)||got))ok=0;
    if(!close(h))ok=0;
    if(!ok){text(" read_failed");emit();return;}
    filename(name);H out=openfile(path,0x40000000u,0,1);
    if(out==BAD){text(" output_open_failed");failed=1;emit();return;}
    ok=writeall(out,io,n);if(!close(out))ok=0;
    text(ok?" saved":" output_write_failed");if(!ok)failed=1;emit();
}
static const W *keys[]={L"UI_TYPE",L"UI_INVERSE",L"INVERSE_TYPE",L"HMI_TEMP_CNF",L"HMI_ECO_CNF",L"HMI_AIR_CNF",L"HMI_ADAC_CNF",L"TOOL_CONNECTED",L"CLOCK_TYPE"};
static const char *labels[]={"UI_TYPE","UI_INVERSE","INVERSE_TYPE","HMI_TEMP_CNF","HMI_ECO_CNF","HMI_AIR_CNF","HMI_ADAC_CNF","TOOL_CONNECTED","CLOCK_TYPE"};
static void registry(U sample){
    H key=0;U status=FN(REGOPEN,U(*)(H,const W*,U,U,H*))((H)0x80000002u,L"LGE\\SystemInfo",0,0x20019,&key);
    field("registry sample=",sample);field(" open_status=",status);emit();if(status)return;
    for(U i=0;i<sizeof(keys)/sizeof(keys[0])&&!failed;i++){
        U type=0,n=4,value=0;status=FN(REGQUERY,U(*)(H,const W*,U*,U*,B*,U*))(key,keys[i],0,&type,(B*)&value,&n);
        text("reg ");text(labels[i]);field(" status=",status);field(" type=",type);field(" bytes=",n);
        if(!status&&type==4&&n==4)field(" value=",value);emit();
    }FN(REGCLOSE,U(*)(H))(key);
}
/* File hash + in-memory function bytes must match before address-specific RAM reads. */
__attribute__((noinline)) static U pinned(void){
    H h=openfile(L"\\Storage Card\\System\\MicomManager.exe",0x80000000u,3,3);if(h==BAD)return 0;
    U n=0,ok=size(h,&n)&&n==MICOM_BYTES;SHA s;sha_init(&s);
    while(ok&&n){U got=0,want=n>sizeof(io)?sizeof(io):n;if(!readfile(h,io,want,&got)||!got||got>want){ok=0;break;}sha_add(&s,io,got);n-=got;}
    if(ok){U got=0;if(!readfile(h,io,1,&got)||got)ok=0;}
    if(!close(h))ok=0;B digest[32];sha_end(&s,digest);return ok&&samehash(digest,micom_hash);
}
typedef struct {U size,usage,pid,heap,module,threads,parent,priority,flags;W exe[260];U base,key;} Process;
static U rpm(H h,U at,void *b,U n){U got=0;return FN(RPM,U(*)(H,const void*,void*,U,U*))(h,(const void*)at,b,n,&got)&&got==n;}
static H micom(void){
    if(!pinned()){text("ram skipped_file_pin");emit();return 0;}
    H snapshot=FN(SNAPSHOT,H(*)(U,U))(2,0);if(!snapshot||snapshot==BAD){text("ram skipped_snapshot");emit();return 0;}
    Process p;memset(&p,0,sizeof(p));p.size=sizeof(p);U ok=FN(FIRSTPROC,U(*)(H,Process*))(snapshot,&p),count=0,pid=0;
    while(ok&&++count<=256){p.exe[259]=0;if(eq(base(p.exe),L"MicomManager.exe")&&p.base==0x10000){pid=p.pid;break;}p.size=sizeof(p);ok=FN(NEXTPROC,U(*)(H,Process*))(snapshot,&p);}
    FN(CLOSESNAP,U(*)(H))(snapshot);if(!pid){text("ram skipped_process_or_base");emit();return 0;}
    H h=FN(OPENPROC,H(*)(U,U,U))(0x10,0,pid);if(!h||h==BAD){text("ram skipped_openprocess");emit();return 0;}
    B signature[32];ok=rpm(h,0x14090,signature,32);for(U i=0;ok&&i<32;i++)if(signature[i]!=micom_signature[i])ok=0;
    if(!ok){close(h);text("ram skipped_memory_pin");emit();return 0;}
    text("ram pinned_micom");emit();return h;
}
static void temperature(H h,U sample){
    U ptr=0;field("temp sample=",sample);field(" tick=",FN(TICK,U(*)(void))());
    if(!rpm(h,0x64888,&ptr,4)||ptr<0x10000||ptr>0x7fffff00||(ptr&3)){text(" unavailable_pointer");emit();return;}
    U v[9],after=0;
    if(!rpm(h,ptr,v,sizeof(v))||!rpm(h,0x64888,&after,4)||ptr!=after){text(" unavailable_or_changed");emit();return;}
    field(" current_raw=",v[4]);field(" target_raw=",v[5]);field(" units=",v[6]);field(" enabled=",v[8]);emit();
}
U entry(void){
    if(!newfolder()){
        FN(BOX,U(*)(H,const W*,const W*,U))(0,L"No writable USB at \\MD. Capture stopped.",L"MAXmade vehicle capture",0x10);return 1;
    }
    filename(L"capture.txt");loghandle=openfile(path,0x40000000u,0,1);
    if(loghandle==BAD)return 1;
    text("MAXmade vehicle capture 1; read-only internal files/registry/process; USB output only");emit();
    if(!failed)capture(L"\\Storage Card\\System\\DSI_config.bsd",L"DSI_config.bsd","DSI_config.bsd",36);
    if(!failed)capture(L"\\Storage Card2\\EcoDrive.cfg",L"EcoDrive.cfg","EcoDrive.cfg",9);
    if(!failed)capture(L"\\Storage Card2\\MgrSys.cfg",L"MgrSys.cfg","MgrSys.cfg",128);
    if(!failed)capture(L"\\Storage Card\\System\\Version_Info.txt",L"Version_Info.txt","Version_Info.txt",64);
    if(!failed)registry(0);
    H h=failed?0:micom();
    for(U i=0;i<20&&!failed;i++){if(h)temperature(h,i);FN(SLEEP,void(*)(U))(500);}
    if(h)close(h);
    if(!failed)registry(1);
    if(!failed)text("capture complete; runtime samples are observations, not MCU packet traces");
    if(!failed)emit();if(!close(loghandle))failed=1;
    FN(BOX,U(*)(H,const W*,const W*,U))(0,failed?L"USB capture incomplete. Keep the partial vehicle-config folder for diagnosis.":L"Capture saved in \\MD\\MAXmade\\vehicle-config-... . Copy that folder from USB.",L"MAXmade vehicle capture",failed?0x10:0x40);
    return failed?1:0;
}
