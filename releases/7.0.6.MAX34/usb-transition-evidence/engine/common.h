/* Freestanding, little-endian MIPS/o32 Windows CE application repair.
 * No CRT, registry, formatter, firmware flasher or reboot API.
 * Only the pinned stopped application updater may be quiesced.
 * Built-in manifest and API ordinals are generated from pinned local inputs.
 */
typedef unsigned int U;
typedef unsigned short W;
typedef unsigned char B;
typedef void *H;
#define BAD ((H)0xffffffffu)
#define PATH 260
#define RO 0x80000000u
#define WO 0x40000000u
#define DIR 16u
#define NONE 0xffffffffu
enum { OPEN, READ, WRITE, CLOSE, SIZE, ATTR, MKDIR, REMOVE, MOVE, FLUSH,
       MODULE, LAST, SPACE, BOX, MUTEX, RELEASE, TICK, SNAPSHOT, FIRSTPROC,
       NEXTPROC, CLOSESNAP, WINDOW, TEXT, UPDATE, DESTROY, PEEK, TRANSLATE,
       DISPATCH, SEEK, OPENPROC, RPM, TERM, WAIT, CMDLINE, PROCESS, RMDIR, API_COUNT };
volatile U imports[API_COUNT];
#define FN(n,t) ((t)(imports[n]))
#define close(h) FN(CLOSE,U(*)(H))(h)
#define attrs(p) FN(ATTR,U(*)(const W*))(p)
#define last() FN(LAST,U(*)(void))()
#define box(s,f) FN(BOX,U(*)(H,const W*,const W*,U))(0,s,L"MediaNav application repair",f)
#define remove(p) FN(REMOVE,U(*)(const W*))(p)
#define move(a,b) FN(MOVE,U(*)(const W*,const W*))(a,b)
typedef struct {const W *path; U bytes; B hash[32]; U volume; U action; U first; U count;} Item;
/* action 0 = application file, 1 = version last, 2 = never written by this worker (active boot files pinned separately). */
#include "manifest.h"
static W root[PATH], src[PATH], dst[PATH], temp[PATH], status[600], failed_path[PATH];
static B io[16384];
static H logfile, window;
static U rootlen, failed_error, written_count, phase, log_ok;
static const W pending[]=L"\\Storage Card3\\MAX34-repair.pending";
static const W scan[]=L"\\Storage Card2\\scan_done_flag.bin";
static const W stage[]=L"\\Storage Card3\\upgrade";
static const W quarantine[]=L"\\Storage Card3\\MAX34-retained-upgrade";
static const W *volumes[]={L"\\Storage Card",L"\\Storage Card2",L"\\Storage Card3",L"\\Storage Card4"};

void *memcpy(void *d,const void *s,U n) { B *a=d;const B *b=s;while(n--)*a++=*b++;return d; }
void *memset(void *d,int c,U n) { B *a=d;while(n--)*a++=(B)c;return d; }
static U len(const W *s){U n=0;while(s[n])n++;return n;}
static W lower(W c){return c>='A'&&c<='Z'?c+32:c;}
static int eq(const W *a,const W *b){while(*a&&lower(*a)==lower(*b)){a++;b++;}return *a==*b;}
static int prefix(const W *a,const W *b){while(*b)if(lower(*a++)!=lower(*b++))return 0;return 1;}
static int join(W *out,const W *a,const W *b){U x=len(a),y=len(b);if(x+y>=PATH)return 0;memcpy(out,a,2*x);memcpy(out+x,b,2*(y+1));return 1;}
static void remember(const W *p,U err){U n=len(p);if(n>=PATH)n=PATH-1;memcpy(failed_path,p,n*2);failed_path[n]=0;failed_error=err;}
static H openfile(const W *p,U access,U share,U create){return FN(OPEN,H(*)(const W*,U,U,H,U,U,H))(p,access,share,0,create,0x80,0);}
static U readfile(H h,void *p,U n,U *got){return FN(READ,U(*)(H,void*,U,U*,H))(h,p,n,got,0);}
static U writefile(H h,const void *p,U n,U *got){return FN(WRITE,U(*)(H,const void*,U,U*,H))(h,p,n,got,0);}
static U flush(H h){return FN(FLUSH,U(*)(H))(h);}
static U file_size(H h,U *n){U high=0;*n=FN(SIZE,U(*)(H,U*))(h,&high);return *n!=NONE&&!high;}
static U absent(const W *p){U a=attrs(p);if(a!=NONE)return 0;U e=last();return e==2||e==3;}
static U delete_if_present(const W *p){U a=attrs(p);if(a==NONE){if(absent(p))return 1;remember(p,last());return 0;}if(a&DIR){remember(p,267);return 0;}if(!remove(p)){remember(p,last());return 0;}return 1;}
static void append(W *s,const W *t){U n=len(s);while(*t&&n<598)s[n++]=*t++;s[n]=0;}
static void number(W *s,U x){W digits[12];U n=0;do{digits[n++]=(W)('0'+x%10);x/=10;}while(x);while(n){W q[2]={digits[--n],0};append(s,q);}}
static void pump(void){U msg[8];while(FN(PEEK,U(*)(void*,H,U,U,U))(msg,0,0,0,1)){FN(TRANSLATE,U(*)(void*))(msg);FN(DISPATCH,U(*)(void*))(msg);}}
static void progress(const W *label,U n){status[0]=0;append(status,label);number(status,n);append(status,L" / ");number(status,ITEM_COUNT);append(status,L"\r\nKeep power and USB connected.\r\nA detailed log is saved on internal Storage Card3.");FN(TEXT,U(*)(H,const W*))(window,status);FN(UPDATE,U(*)(H))(window);pump();}
static U logline(const W *label,const W *p){
    B b[1800];U n=0,t=FN(TICK,U(*)(void))();W d[16];d[0]=0;number(d,t);
    for(U i=0;d[i];i++)b[n++]=(B)d[i];b[n++]=' ';
    for(U i=0;label[i]&&n<1790;i++)b[n++]=(B)label[i];b[n++]=' ';
    for(U i=0;p[i]&&n<1790;i++)b[n++]=p[i]<128?(B)p[i]:'?';b[n++]='\r';b[n++]='\n';
    U done=0;while(done<n){U got=0;if(!writefile(logfile,b+done,n-done,&got)||!got||got>n-done){log_ok=0;remember(L"USB repair log",last());return 0;}done+=got;}
    if(!flush(logfile)){log_ok=0;remember(L"USB repair log",last());return 0;}return 1;
}

/* SHA-256, including streaming and final length, independent of CE providers. */
typedef struct {U h[8],lo,hi,used;B block[64];} SHA;
static const U K[64]={0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2};
static U rr(U x,U n){return (x>>n)|(x<<(32-n));}
static void transform(SHA *s){U w[64],a,b,c,d,e,f,g,h;
    for(U i=0;i<16;i++){const B *p=s->block+4*i;w[i]=((U)p[0]<<24)|((U)p[1]<<16)|((U)p[2]<<8)|p[3];}
    for(U i=16;i<64;i++){U x=w[i-15],y=w[i-2];w[i]=w[i-16]+(rr(x,7)^rr(x,18)^(x>>3))+w[i-7]+(rr(y,17)^rr(y,19)^(y>>10));}
    a=s->h[0];b=s->h[1];c=s->h[2];d=s->h[3];e=s->h[4];f=s->h[5];g=s->h[6];h=s->h[7];
    for(U i=0;i<64;i++){U t=h+(rr(e,6)^rr(e,11)^rr(e,25))+((e&f)^((~e)&g))+K[i]+w[i];U v=(rr(a,2)^rr(a,13)^rr(a,22))+((a&b)^(a&c)^(b&c));h=g;g=f;f=e;e=d+t;d=c;c=b;b=a;a=t+v;}
    s->h[0]+=a;s->h[1]+=b;s->h[2]+=c;s->h[3]+=d;s->h[4]+=e;s->h[5]+=f;s->h[6]+=g;s->h[7]+=h;
}
static void sha_init(SHA *s){static const U h[8]={0x6a09e667,0xbb67ae85,0x3c6ef372,0xa54ff53a,0x510e527f,0x9b05688c,0x1f83d9ab,0x5be0cd19};memcpy(s->h,h,32);s->lo=s->hi=s->used=0;}
static void sha_add(SHA *s,const B *p,U n){U old=s->lo;s->lo+=n;if(s->lo<old)s->hi++;while(n){U k=64-s->used;if(k>n)k=n;memcpy(s->block+s->used,p,k);s->used+=k;p+=k;n-=k;if(s->used==64){transform(s);s->used=0;}}}
static void sha_end(SHA *s,B *out){U hi=(s->hi<<3)|(s->lo>>29),lo=s->lo<<3;B x=128,z=0;sha_add(s,&x,1);while(s->used!=56)sha_add(s,&z,1);B n[8];for(U i=0;i<4;i++){n[i]=(B)(hi>>(24-8*i));n[i+4]=(B)(lo>>(24-8*i));}sha_add(s,n,8);for(U i=0;i<32;i++)out[i]=(B)(s->h[i/4]>>(24-8*(i%4)));}
static U samehash(const B *a,const B *b){U v=0;for(U i=0;i<32;i++)v|=a[i]^b[i];return !v;}
static U hash_file(const W *p,U expected,const B *digest){
    H h=openfile(p,RO,1,3);if(h==BAD){remember(p,last());return 0;}U n,ok=file_size(h,&n)&&n==expected;SHA s;sha_init(&s);
    while(ok&&n){U got=0,want=n>sizeof(io)?sizeof(io):n;if(!readfile(h,io,want,&got)||!got||got>want){ok=0;break;}sha_add(&s,io,got);n-=got;}
    if(ok){U got=0;if(!readfile(h,io,1,&got)||got)ok=0;}
    U err=last();if(!close(h)){ok=0;err=last();}B result[32];sha_end(&s,result);if(!ok||!samehash(result,digest)){remember(p,ok?23:err?err:23);return 0;}return 1;
}
static U parents(W *p){for(U i=1;p[i];i++)if(p[i]=='\\'){W save=p[i];p[i]=0;U a=attrs(p);if(a==NONE){if(!absent(p)||!FN(MKDIR,U(*)(const W*,H))(p,0)){remember(p,last());p[i]=save;return 0;}}else if(!(a&DIR)){remember(p,267);p[i]=save;return 0;}p[i]=save;}return 1;}
static U install(const Item *r){
    if(!join(src,root,L"")||!join(src,src,r->path)||!join(dst,L"",r->path)||!join(temp,dst,L".max34-new")){remember(r->path,206);return 0;}
    if(hash_file(dst,r->bytes,r->hash))return logline(L"already verified",dst);
    if(!parents(dst)||!delete_if_present(temp))return 0;
    H in=openfile(src,RO,1,3);if(in==BAD){remember(src,last());return 0;}
    H out=openfile(temp,WO,0,1);if(out==BAD){remember(temp,last());close(in);return 0;}
    U ok=1,left=r->bytes,n;SHA s;sha_init(&s);
    if(!file_size(in,&n)||n!=left)ok=0;
    while(ok&&left){U got=0,want=left>sizeof(io)?sizeof(io):left;if(!readfile(in,io,want,&got)||!got||got>want){ok=0;break;}sha_add(&s,io,got);left-=got;U pos=0;while(pos<got){U put=0;if(!writefile(out,io+pos,got-pos,&put)||!put||put>got-pos){ok=0;break;}pos+=put;}}
    if(ok){U got=0;if(!readfile(in,io,1,&got)||got)ok=0;}B digest[32];sha_end(&s,digest);if(!samehash(digest,r->hash))ok=0;
    U err=last();if(ok&&!flush(out)){ok=0;err=last();}if(!close(out)){ok=0;err=last();}if(!close(in)){ok=0;err=last();}
    if(!ok){remember(temp,err?err:23);return 0;}
    if(!hash_file(temp,r->bytes,r->hash))return 0;
    /* The USB source survives every attempt. A power loss between delete and
       move may leave one target absent; rerunning this tool repairs it. */
    if(!delete_if_present(dst))return 0;
    if(!move(temp,dst)){remember(dst,last());return 0;}
    if(!hash_file(dst,r->bytes,r->hash))return 0;
    written_count++;return logline(L"installed and verified",dst);
}
