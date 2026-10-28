/* Integrated MAX34 application transaction: internal stage, parent handoff,
 * automatic reboot resume and explicit repair after an ambiguous migration.
 * common.h is generated from the pinned, tested issue56 file/SHA/UI helpers.
 * All kernel/MCU payload entries remain source-only. No formatting or flashing.
 */
#include "common.h"
typedef struct {U magic,seq,pass,index,block;B package[32],check[32];} Journal;
static Journal cursor;
static B chunk[CHUNK_BYTES];
static U had_receipt;
static U delegated_mode,resume_mode,approved_repair,parent_held,completed_resume;
static W source_root[PATH];
static const W complete_path[]=L"\\Storage Card3\\MAX34-applications.complete";
static const W *slots[]={L"\\Storage Card3\\MAX34-progress-0.bin",L"\\Storage Card3\\MAX34-progress-1.bin"};
static const W bootflag[]=L"\\Storage Card3\\MAXboot.flag";
static const W desktopflag[]=L"\\Storage Card3\\StartWinCE";
static U has_flag(const W *s,const W *flag){if(!s)return 0;for(U n=0;s[n]&&n<1024;n++){if(n&&s[n-1]!=' ')continue;U k=0;while(flag[k]&&s[n+k]==flag[k])k++;if(!flag[k]&&(!s[n+k]||s[n+k]==' '))return 1;}return 0;}
static U exactread(H h,B *p,U n){while(n){U got=0;if(!readfile(h,p,n,&got)||!got||got>n)return 0;p+=got;n-=got;}return 1;}
static U exactwrite(H h,const B *p,U n){while(n){U got=0;if(!writefile(h,p,n,&got)||!got||got>n)return 0;p+=got;n-=got;}return 1;}
static U seek(H h,U n){return FN(SEEK,U(*)(H,U,U*,U))(h,n,0,0)==n;}
static void digest(const B *p,U n,B out[32]){SHA s;sha_init(&s);sha_add(&s,p,n);sha_end(&s,out);}
static U journal_valid(Journal *j){
    B h[32];digest((const B*)j,sizeof(*j)-32,h);
    if(j->magic!=0x59333031||!j->seq||j->pass>2||j->index>ITEM_COUNT||!samehash(j->package,package_hash)||!samehash(j->check,h))return 0;
    if(j->pass==2)return !j->index&&!j->block;
    if(j->index==ITEM_COUNT)return !j->block;
    return j->block<=items[j->index].count;
}
static U read_journal(U slot,Journal *j){
    H h=openfile(slots[slot],RO,1,3);if(h==BAD)return 0;U n=0,ok=file_size(h,&n)&&n==sizeof(*j)&&exactread(h,(B*)j,n);if(!close(h))ok=0;return ok&&journal_valid(j);
}
static U save_journal(void){
    if(cursor.seq==0xffffffffu){remember(L"Repair progress sequence",534);return 0;}
    Journal next=cursor;next.magic=0x59333031;next.seq++;memcpy(next.package,package_hash,32);digest((const B*)&next,sizeof(next)-32,next.check);
    U slot=next.seq&1;const W *p=slots[slot];if(!delete_if_present(p))return 0;
    H h=openfile(p,WO,0,1);if(h==BAD){remember(p,last());return 0;}U ok=exactwrite(h,(const B*)&next,sizeof(next))&&flush(h);U e=last();if(!close(h))ok=0;
    Journal check;if(!ok||!read_journal(slot,&check)||check.seq!=next.seq||check.pass!=next.pass||check.index!=next.index||check.block!=next.block){remember(p,e?e:23);return 0;}
    cursor=next;return 1;
}
static U load_progress(void){
    Journal a,b;U x=read_journal(0,&a),y=read_journal(1,&b);
    if(x||y){cursor=x&&(!y||a.seq>b.seq)?a:b;return 1;}
    /* The independently verified package receipt permits starting from the
     * beginning when an interruption damaged the very first progress slot.
     * Recopying is safe; no settings migration is being replayed. */
    if(!had_receipt&&(!absent(slots[0])||!absent(slots[1]))){remember(L"Repair progress receipts",23);return 0;}
    memset(&cursor,0,sizeof(cursor));return save_journal();
}
static U known_updater(void){return hash_file(L"\\Storage Card\\System\\UpgradeManager.exe",UPDATER_BYTES,updater_hash);}
typedef struct {U size,usage,pid,heap,module,threads,parent,priority,flags;W exe[260];U base,key;} Process;
static const W *base_name(const W *s){const W *p=s;while(*s){if(*s=='\\'||*s=='/')p=s+1;s++;}return p;}
/* Only the pinned updater, verified stopped at a nonzero error/phase3007,
 * may be stopped. A delegated parent at 6001/3008 is held, never terminated.
 * Never terminate a firmware operation or a hardware manager by name alone. */
static U stopped_updater(U pid,U terminate){
    if(!known_updater())return 0;
    H h=FN(OPENPROC,H(*)(U,U,U))(0x11,0,pid);if(!h||h==BAD){remember(L"Open stopped updater",last());return 0;}
    U error=0,state=0,busy=1,got=0;
    U ok=FN(RPM,U(*)(H,const void*,void*,U,U*))(h,(void*)0x41000,&error,4,&got)&&got==4;
    if(ok)ok=FN(RPM,U(*)(H,const void*,void*,U,U*))(h,(void*)0x3784c,&state,4,&got)&&got==4;
    if(ok)ok=FN(RPM,U(*)(H,const void*,void*,U,U*))(h,(void*)0x38f10,&busy,4,&got)&&got==4&&!busy;
    if(ok&&error==6001&&state==3008)parent_held=1;
    else {ok=ok&&error&&state==3007;if(ok&&terminate){ok=FN(TERM,U(*)(H,U))(h,0);if(ok)ok=FN(WAIT,U(*)(H,U))(h,5000)==0;}}
    U e=last();if(!close(h))ok=0;if(!ok){remember(L"Updater is active or not a verified application-stage stop",e?e:170);return 0;}return 1;
}
static U processes_clear(U terminate){
    parent_held=0;
    H h=FN(SNAPSHOT,H(*)(U,U))(2,0);if(h==BAD||!h){remember(L"Process snapshot",last());return 0;}
    Process p;memset(&p,0,sizeof(p));p.size=sizeof(p);U ok=FN(FIRSTPROC,U(*)(H,Process*))(h,&p),count=0,clear=1;
    if(!ok)clear=0;
    while(ok){if(++count>256){clear=0;break;}p.exe[259]=0;const W *name=base_name(p.exe);
        if(eq(name,L"UpgradeManager.exe")){
            if(!stopped_updater(p.pid,terminate)){clear=0;break;}
        }else for(U i=0;i<ITEM_COUNT;i++)if(!items[i].action&&eq(name,base_name(items[i].path))){remember(p.exe,32);clear=0;break;}
        if(!clear)break;p.size=sizeof(p);ok=FN(NEXTPROC,U(*)(H,Process*))(h,&p);
    }
    if(clear&&!ok&&last()!=18){remember(L"Process enumeration",last());clear=0;}
    if(!FN(CLOSESNAP,U(*)(H))(h))clear=0;return clear;
}
static U layout(void){
    for(U i=0;i<4;i++){U a=attrs(volumes[i]);if(a==NONE||!(a&DIR)){remember(volumes[i],267);return 0;}}
    if(!hash_file(L"\\Storage Card\\NK.bin",NK_BYTES,nk_hash)||!known_updater()||!hash_file(L"\\Storage Card\\Recovery.exe",RECOVERY_BYTES,recovery_hash))return 0;
    U a=attrs(stage),b=attrs(quarantine);if(a!=NONE&&!(a&DIR)){remember(stage,267);return 0;}if(b!=NONE&&!(b&DIR)){remember(quarantine,267);return 0;}
    if(a!=NONE&&b!=NONE){remember(quarantine,183);return 0;}
    U p=attrs(pending);had_receipt=p!=NONE;
    if(had_receipt){if((p&DIR)||!hash_file(pending,PACKAGE_BYTES,package_hash))return 0;}
    else if(!absent(pending)||resume_mode){remember(pending,23);return 0;}
    /* Source cleanup can itself be interrupted. A committed transaction no
     * longer needs source files, but requires all independent commit evidence.
     * Never use this path while the uncommitted native stage still exists. */
    if(had_receipt&&a==NONE&&absent(stage)){
        Journal j,k;U x=read_journal(0,&j),y=read_journal(1,&k);
        Journal *latest=x&&(!y||j.seq>k.seq)?&j:&k;
        if((x||y)&&latest->pass==2&&hash_file(complete_path,COMPLETION_BYTES,completion_hash)&&hash_file(L"\\Storage Card\\System\\Version_Info.txt",VERSION_BYTES,version_hash)){
            completed_resume=1;
            if(!join(source_root,L"",quarantine)||!processes_clear(0))return 0;
            if(delegated_mode&&!parent_held){remember(L"Missing installer delegation",170);return 0;}return 1;
        }
    }
    if(a!=NONE){if(!join(source_root,L"",stage))return 0;}
    else if(b!=NONE){if(!join(source_root,L"",quarantine))return 0;}
    else {remember(stage,5002);return 0;}
    if(!join(src,source_root,L"\\filecopy_success.bin"))return 0;
    U r=attrs(src);if(r==NONE||(r&DIR)){remember(src,5002);return 0;}
    if(!join(src,source_root,L"\\Storage Card\\System\\Version_Info.txt")||!hash_file(src,VERSION_BYTES,version_hash))return 0;
    /* Bootstrap self is deliberately outside the compiled manifest to avoid a
     * self-hash cycle. Compare the installed worker with its retained source. */
    if(!join(src,source_root,L"\\Storage Card\\InstallResume.exe"))return 0;
    H left=openfile(src,RO,1,3),right=openfile(L"\\Storage Card\\InstallResume.exe",RO,1,3);U x=0,y=0,ok=left!=BAD&&right!=BAD&&file_size(left,&x)&&file_size(right,&y)&&x==y&&x&&x<2097152;
    while(ok&&x){U n=x>sizeof(io)?sizeof(io):x;ok=exactread(left,io,n)&&exactread(right,chunk,n);for(U k=0;ok&&k<n;k++)if(io[k]!=chunk[k])ok=0;x-=n;}
    if(left!=BAD&&!close(left))ok=0;if(right!=BAD&&!close(right))ok=0;if(!ok){remember(src,23);return 0;}
    if(!had_receipt){
        for(U slot=0;slot<2;slot++)if(!absent(slots[slot])){Journal j;if(!read_journal(slot,&j)||j.pass!=2||!hash_file(complete_path,COMPLETION_BYTES,completion_hash)){remember(slots[slot],23);return 0;}}
    }
    if(!processes_clear(0))return 0;if(delegated_mode&&!parent_held){remember(L"Missing installer delegation",170);return 0;}return 1;
}
static U receipt(void){
    if(had_receipt)return 1;const W *p=L"\\Storage Card3\\MAX34-repair.pending.new";
    if(!delete_if_present(p))return 0;H h=openfile(p,WO,0,1);if(h==BAD){remember(p,last());return 0;}
    U ok=exactwrite(h,package_id,PACKAGE_BYTES)&&flush(h);if(!close(h))ok=0;
    if(!ok||!hash_file(p,PACKAGE_BYTES,package_hash)||!move(p,pending)){remember(p,last());return 0;}return hash_file(pending,PACKAGE_BYTES,package_hash);
}
static U protect_boot(void){
    U a=attrs(bootflag);if(a!=NONE){if(a&DIR){remember(bootflag,267);return 0;}return 1;}
    if(!absent(bootflag))return 0;H h=openfile(bootflag,WO,0,1);if(h==BAD){remember(bootflag,last());return 0;}
    U ok=flush(h);if(!close(h))ok=0;if(!ok)remember(bootflag,last());return ok;
}
static U space_check(void){
    /* Reserve journal space. Temporary capacity is checked per file below:
     * reserving a whole second temp on every restart would reject a nearly
     * complete existing temp even though publishing it releases that space. */
    for(U i=0;i<4;i++){U a[2],t[2],f[2];if(!FN(SPACE,U(*)(const W*,U*,U*,U*))(volumes[i],a,t,f)){remember(volumes[i],last());return 0;}
        if(i==2&&!a[1]&&a[0]<65536){remember(volumes[i],112);return 0;}}
    return 1;
}
static U piece(const W *p,U total,U offset,U bytes,const B *expected,U exact_size){
    H h=openfile(p,RO,1,3);if(h==BAD){remember(p,last());return 0;}U n=0;
    U ok=file_size(h,&n)&&(exact_size?n==total:n>=offset+bytes)&&seek(h,offset)&&exactread(h,chunk,bytes);
    U e=last();if(!close(h))ok=0;B hash[32];digest(chunk,bytes,hash);
    if(!ok||!samehash(hash,expected)){remember(p,ok?23:e?e:23);return 0;}return 1;
}
static U copy_piece(const Item *r){
    const Block *b=&blocks[r->first+cursor.block];U offset=cursor.block*CHUNK_BYTES;
    if(!join(src,source_root,r->path)||!join(temp,r->path,L".max34-new")){remember(r->path,206);return 0;}
    U old=0,a=attrs(temp);if(a!=NONE){if(a&DIR){remember(temp,267);return 0;}H h=openfile(temp,RO,1,3);if(h==BAD){remember(temp,last());return 0;}U ok=file_size(h,&old);if(!close(h))ok=0;if(!ok){remember(temp,last());return 0;}}
    else if(!absent(temp)){remember(temp,last());return 0;}
    U available[2],total[2],free[2],need=r->bytes>old?r->bytes-old:0;
    if(!FN(SPACE,U(*)(const W*,U*,U*,U*))(volumes[r->volume],available,total,free)||(!available[1]&&available[0]<need+65536)){remember(volumes[r->volume],112);return 0;}
    if(!piece(src,r->bytes,offset,b->bytes,b->hash,1)||!parents(temp))return 0;
    if(!cursor.block&&!delete_if_present(temp))return 0;
    H h=openfile(temp,WO,0,cursor.block?3:1);if(h==BAD){remember(temp,last());return 0;}
    U n=0,ok=file_size(h,&n)&&n>=offset&&seek(h,offset)&&exactwrite(h,chunk,b->bytes)&&flush(h);U e=last();if(!close(h))ok=0;
    if(!ok){remember(temp,e?e:23);return 0;}
    if(!piece(temp,r->bytes,offset,b->bytes,b->hash,cursor.block+1==r->count))return 0;
    cursor.block++;return save_journal();
}
static U publish(const Item *r){
    if(!join(temp,r->path,L".max34-new")){remember(r->path,206);return 0;}
    U a=attrs(temp);
    if(a==NONE){
        if(!absent(temp))return 0;
        /* Handles interruption after rename but before next cursor commit. */
        if(!hash_file(r->path,r->bytes,r->hash)){cursor.block=0;return save_journal();}
    }else{
        H h=openfile(temp,RO,1,3);U n=0;if(h==BAD){remember(temp,last());return 0;}
        U ok=file_size(h,&n)&&n==r->bytes;if(!close(h))ok=0;if(!ok){remember(temp,23);return 0;}
        if(!delete_if_present(r->path)||!move(temp,r->path)){remember(r->path,last());return 0;}
    }
    written_count++;if(!logline(L"installed verified blocks",r->path))return 0;
    cursor.index++;cursor.block=0;return save_journal();
}
static U repair_files(void){
    while(cursor.pass<2){
        if(cursor.index==ITEM_COUNT){cursor.pass++;cursor.index=cursor.block=0;if(!save_journal())return 0;continue;}
        const Item *r=&items[cursor.index];
        if(r->action){cursor.index++;cursor.block=0;if(!save_journal())return 0;continue;}
        phase=cursor.pass?3:2;progress(cursor.pass?L"Verifying applications: ":L"Installing applications: ",cursor.index);
        if(!cursor.pass){
            if(cursor.block&&cursor.block<r->count){
                if(!join(temp,r->path,L".max34-new"))return 0;
                H h=openfile(temp,RO,1,3);U n=0,ok=h!=BAD&&file_size(h,&n)&&n>=cursor.block*CHUNK_BYTES&&n<=r->bytes;
                if(h!=BAD)close(h);if(!ok){cursor.block=0;if(!save_journal())return 0;}
            }
            if(cursor.block<r->count){if(!copy_piece(r))return 0;}
            else if(!publish(r))return 0;
        }else{
            if(cursor.block<r->count){const Block *b=&blocks[r->first+cursor.block];
                if(!piece(r->path,r->bytes,cursor.block*CHUNK_BYTES,b->bytes,b->hash,1)){
                    /* Recopy a failed target on retry; pending staging and
                     * checkpoint stay intact. Reverify the whole set after it. */
                    cursor.pass=0;cursor.block=0;if(!save_journal())return 0;return 0;
                }
                cursor.block++;if(!save_journal())return 0;
            }else {cursor.index++;cursor.block=0;if(!save_journal())return 0;}
        }
    }
    return 1;
}
static void cleanup_sources(void){
    /* Delete only manifest-owned public source paths, never unknown extras or
     * settings backups. Empty-directory removal is deliberately nonrecursive.
     * Failures leave harmless sources behind and do not undo a verified commit. */
    U left=0;
    for(U i=0;i<ITEM_COUNT;i++){
        if(!join(src,quarantine,items[i].path)){left++;continue;}
        U a=attrs(src);if(a!=NONE&&((a&DIR)||!remove(src)))left++;
    }
    const W *extra[]={L"\\Storage Card\\InstallResume.exe",L"\\filecopy_success.bin"};
    for(U i=0;i<2;i++)if(join(src,quarantine,extra[i])){U a=attrs(src);if(a!=NONE&&((a&DIR)||!remove(src)))left++;}
    for(U i=0;i<SOURCE_DIR_COUNT;i++)if(join(src,quarantine,source_dirs[i]))FN(RMDIR,U(*)(const W*))(src);
    logline(left?L"source cleanup left files":L"source cleanup complete",L"known public sources only; unknown extras retained");
}
static U run(void){
    phase=1;if(!layout()||!space_check())return 0;
    if(!(delegated_mode||resume_mode||approved_repair)&&box(L"Repair / resume the pending application installation?\r\n\r\nApplications will be copied and verified from retained staging. This does not replay settings formatting or flash the kernel/MCU. Keep power stable. Progress will resume after a restart.",0x40024)!=6)return 2;
    if(!processes_clear(1)||!processes_clear(0))return 0;
    if(!had_receipt){for(U j=0;j<2;j++)if(!delete_if_present(slots[j]))return 0;}
    if(!protect_boot()||!receipt()||!load_progress())return 0;
    if(!join(root,L"",source_root))return 0;
    if(completed_resume)goto committed;
    if(!repair_files())return 0;
    if(!hash_file(L"\\Storage Card\\NK.bin",NK_BYTES,nk_hash)||!known_updater()||!hash_file(L"\\Storage Card\\Recovery.exe",RECOVERY_BYTES,recovery_hash))return 0;
    phase=4;
    if(!logline(L"all application blocks verified",L"retained staging and settings checkpoint cleanup follows"))return 0;
    if(attrs(stage)!=NONE){if(!move(stage,quarantine)){remember(stage,last());return 0;}}
    else if(!absent(stage))return 0;
    if(!join(source_root,L"",quarantine)||!join(root,L"",quarantine))return 0;
    if(!delete_if_present(scan))return 0;
    for(U i=0;i<ITEM_COUNT;i++)if(items[i].action==1&&!install(&items[i]))return 0;
    const W *commit_temp=L"\\Storage Card3\\MAX34-applications.complete.new";
    if(!delete_if_present(commit_temp))return 0;H h=openfile(commit_temp,WO,0,1);if(h==BAD){remember(commit_temp,last());return 0;}
    U ok=exactwrite(h,completion_text,COMPLETION_BYTES)&&flush(h);if(!close(h))ok=0;
    if(!ok||!hash_file(commit_temp,COMPLETION_BYTES,completion_hash)||!delete_if_present(complete_path)||!move(commit_temp,complete_path)||!hash_file(complete_path,COMPLETION_BYTES,completion_hash)){remember(complete_path,last());return 0;}
committed:
    if(!delete_if_present(scan))return 0;
    cleanup_sources();
    /* Remove only the maintenance boot counter after commit, preventing a
     * leftover pre-upgrade count from selecting legacy settings maintenance. */
    if(!delete_if_present(L"\\Storage Card2\\pwr_count.bin")||!delete_if_present(desktopflag))return 0;
    /* Leave the final durable journal until the immutable pending receipt has
     * been removed: an interruption before that receipt deletion is retryable. */
    if(!delete_if_present(pending))return 0;
    phase=5;logline(L"SUCCESS",L"MAX34 application install finished, verified, normal startup enabled");return 1;
}
int entry(void){
    H lock=FN(MUTEX,H(*)(H,U,const W*))(0,1,L"MAXmade_Install33");if(!lock||last()==183){if(lock)close(lock);box(L"An installation worker is already running.",0x40010);return 1;}
    U n=FN(MODULE,U(*)(H,W*,U))(0,root,PATH),result=0;
    if(!n||n>=PATH||!eq(root,L"\\Storage Card\\InstallResume.exe")){box(L"Run the installed application recovery worker from Storage Card. Staged and USB copies are not execution entry points.",0x40010);goto done;}
    const W *command=FN(CMDLINE,const W*(*)(void))();delegated_mode=has_flag(command,L"-MAX34Install");resume_mode=has_flag(command,L"-MAX34Resume");approved_repair=has_flag(command,L"-MAX34Repair");
    if((delegated_mode+resume_mode+approved_repair)>1)goto done;
    if(!join(root,L"",L"\\Storage Card3\\"))goto done;rootlen=len(root);
    W name[PATH];U time=FN(TICK,U(*)(void))();logfile=BAD;
    for(U i=0;i<100;i++){status[0]=0;append(status,L"MAX34-install-");number(status,time);append(status,L"-");number(status,i);append(status,L".log");if(!join(name,root,status))break;logfile=openfile(name,WO,0,1);if(logfile!=BAD)break;if(last()!=80&&last()!=183)break;}
    if(logfile==BAD){box(L"Cannot save installation progress information. Internal staging is retained.",0x40010);goto done;}log_ok=1;
    window=FN(WINDOW,H(*)(U,const W*,const W*,U,int,int,int,int,H,H,H,H))(0,L"STATIC",L"MAX34: preparing to finish installation...",0x90800000u,40,100,720,280,0,0,0,0);
    if(!window){box(L"Cannot create status window. No application files were installed.",0x40010);close(logfile);goto done;}FN(UPDATE,U(*)(H))(window);
    if(logline(L"START",L"MAX34 internal application transaction"))result=run();
    if(!result){W saved[PATH];U e=failed_error;memcpy(saved,failed_path,sizeof(saved));status[0]=0;append(status,L"Installation paused. Phase ");number(status,phase);append(status,L", error ");number(status,e);logline(status,saved);append(status,L".\r\n");append(status,saved);append(status,L"\r\nFiles and progress are retained. Recovery offers Repair / resume update and Windows CE. No settings formatting was replayed.");box(status,0x40010);}
    else if(result==2)box(L"You chose not to install. No application files were changed.",0x40040);
    FN(DESTROY,U(*)(H))(window);close(logfile);
    if(result==1){
        if(!processes_clear(0))result=0;
        else if(!parent_held){U pi[4]={0,0,0,0};U ok=FN(PROCESS,U(*)(const W*,W*,H,H,U,U,H,H,H,U*))(L"\\Storage Card\\System\\UpgradeManager.exe",0,0,0,0,0,0,0,0,pi);if(ok){close((H)pi[0]);close((H)pi[1]);}else result=0;}
    }
    if(!result){static W args[]=L"-MAX34NoAuto";U pi[4]={0,0,0,0};if(FN(PROCESS,U(*)(const W*,W*,H,H,U,U,H,H,H,U*))(L"\\Storage Card\\Recovery.exe",args,0,0,0,0,0,0,0,pi)){close((H)pi[0]);close((H)pi[1]);}}
done:FN(RELEASE,U(*)(H))(lock);close(lock);return result==1?0:1;
}
