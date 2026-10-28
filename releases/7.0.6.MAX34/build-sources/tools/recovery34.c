/* Independent menu: automatically resume only an existing transaction receipt.
 * Pending ambiguous migration requires explicit Repair; desktop stays available.
 */
typedef unsigned U;typedef unsigned short W;typedef void *H;
volatile U imports[9];
#define API(n,t) ((t)imports[n])
static const W pending[]=L"\\Storage Card3\\MAX34-repair.pending";
static U message(const W *s,U f){return API(0,U(*)(H,const W*,const W*,U))(0,s,L"MediaNav recovery",f);}
static U launch(const W *p,W *cmd){U pi[4]={0,0,0,0};U ok=API(1,U(*)(const W*,W*,H,H,U,U,H,H,H,U*))(p,cmd,0,0,0,0,0,0,0,pi);if(ok){API(2,U(*)(H))((H)pi[0]);API(2,U(*)(H))((H)pi[1]);}return ok;}
static U desktop(void){static W cmd[]=L"-MAXmadeRecoveryCE";return launch(L"\\Storage Card\\System\\dboot.exe",cmd)||launch(L"\\Windows\\explorer.exe",0);}
static U exists(const W *p){U a=API(3,U(*)(const W*))(p);return a!=0xffffffffu&&!(a&16);}
static U has(const W *s,const W *wanted){if(!s)return 0;for(U n=0;s[n]&&n<1024;n++){if(n&&s[n-1]!=' ')continue;U j=0;while(wanted[j]&&s[n+j]==wanted[j])j++;if(!wanted[j]&&(!s[n+j]||s[n+j]==' '))return 1;}return 0;}
int entry(void){
    H lock=API(6,H(*)(H,U,const W*))(0,1,L"MAXmade_RecoveryMenu");if(!lock){desktop();return 1;}if(API(5,U(*)(void))()==183){API(2,U(*)(H))(lock);return 0;}
    const W *cmd=API(8,const W*(*)(void))();static W resume[]=L"-MAX34Resume",repair[]=L"-MAX34Repair";
    if(!has(cmd,L"-MAX34NoAuto")&&exists(pending)&&launch(L"\\Storage Card\\InstallResume.exe",resume))goto done;
    for(;;){
        U staged=exists(L"\\Storage Card3\\upgrade\\filecopy_success.bin")||exists(pending);
        U answer=message(staged?L"An application installation is pending.\r\n\r\nYES: Repair / resume update.\r\nNO: Open Windows CE.\r\nCANCEL: Stay in this recovery menu.\r\n\r\nRepair verifies files and does not replay settings formatting.":L"A previous normal startup did not finish.\r\n\r\nYES: Allow normal startup on the next restart.\r\nNO: Open Windows CE.\r\nCANCEL: Stay in this recovery menu.\r\n\r\nThis marker alone does not prove an incomplete installation.",0x40123);
        if(answer==2)continue;
        if(answer==6&&staged){if(launch(L"\\Storage Card\\InstallResume.exe",repair))break;message(L"Repair could not start. You can still open Windows CE; files and checkpoints are retained.",0x40010);continue;}
        if(answer==6){
            const W *flag=L"\\Storage Card3\\MAXboot.flag";U a=API(3,U(*)(const W*))(flag);
            if(a!=0xffffffffu){if((a&16)||!API(4,U(*)(const W*))(flag)){message(L"Could not allow normal startup. Windows CE remains available.",0x40010);continue;}}
            else {U e=API(5,U(*)(void))();if(e!=2&&e!=3)continue;}
            message(L"Normal startup is enabled for the next restart. Windows CE will open through DBoot now.",0x40040);
        }else if(answer!=7&&answer)continue;
        if(desktop())break;
        message(L"Windows CE could not open. The recovery menu remains available.",0x40010);
    }
done:API(7,U(*)(H))(lock);API(2,U(*)(H))(lock);return 0;
}
