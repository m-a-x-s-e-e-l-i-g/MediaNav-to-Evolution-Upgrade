/* Recovery desktop entry uses native DBoot initialization before Explorer. */
typedef unsigned U;typedef unsigned short W;typedef void *H;
volatile U imports[8];
#define API(n,t) ((t)imports[n])
static const W flag[]=L"\\Storage Card3\\MAXboot.flag";
static U message(const W *s,U flags){return API(0,U(*)(H,const W*,const W*,U))(0,s,L"MediaNav recovery",flags);}
static U launch(const W *path,W *command){
    U info[4]={0,0,0,0};
    U ok=API(1,U(*)(const W*,W*,H,H,U,U,H,H,H,U*))(path,command,0,0,0,0,0,0,0,info);
    if(ok){API(2,U(*)(H))((H)info[0]);API(2,U(*)(H))((H)info[1]);}return ok;
}
static U desktop(void){
    static W command[]=L"-MAXmadeRecoveryCE";
    if(launch(L"\\Storage Card\\System\\dboot.exe",command))return 1;
    return launch(L"\\Windows\\explorer.exe",0);
}
int entry(void){
    H lock=API(6,H(*)(H,U,const W*))(0,1,L"MAXmade_RecoveryMenu");
    if(!lock){desktop();return 1;}
    if(API(5,U(*)(void))()==183){API(2,U(*)(H))(lock);return 0;}
    for(;;){
        U answer=message(L"A previous normal startup did not finish, or an installer reported an error.\r\n\r\nYES: allow normal startup on the next restart.\r\nNO: open Windows CE through DBoot now.\r\nCANCEL: stay in this recovery menu.\r\n\r\nThis marker alone does not prove an incomplete installation. No files will be formatted.",0x40123);
        if(!answer){U opened=desktop();API(7,U(*)(H))(lock);API(2,U(*)(H))(lock);return opened?0:1;}
        if(answer==2)continue;
        if(answer==6){
            U a=API(3,U(*)(const W*))(flag);
            if(a!=0xffffffffu){
                if((a&16)||!API(4,U(*)(const W*))(flag)){message(L"Could not enable normal startup. The recovery marker was kept. You can still open the desktop.",0x40010);continue;}
            }else{U e=API(5,U(*)(void))();if(e!=2&&e!=3){message(L"Could not check the startup marker. Recovery remains enabled.",0x40010);continue;}}
            message(L"Normal startup is enabled for the next restart.\r\n\r\nShut down normally and start MediaNav again. A repeated failure will return here.\r\n\r\nWindows CE will open through DBoot now; no installer is being started in this session.",0x40040);
        }else if(answer!=7)continue;
        if(desktop())break;
        message(L"Windows CE could not be opened. This recovery menu remains available; you can try again.",0x40010);
    }
    API(7,U(*)(H))(lock);API(2,U(*)(H))(lock);return 0;
}
