"""Offline counterexamples for the reviewed staging controller, not a WinCE/filesystem emulator."""
from copy import deepcopy
from itertools import permutations,product

BLUE="Storage Card/System/Blue.exe"
VERSION="Storage Card/System/Version_Info.txt"
NAV="Storage Card4/NNG/nngnavi.exe"
MARKER="filecopy_success.bin"
FILES=(BLUE,VERSION,NAV)
SIZES={BLUE:1149952,VERSION:14,NAV:10364952,MARKER:0}


def orders():
    """Depth-first native traversal: root's marker/two dirs; two files in System."""
    result=[]
    for root in permutations((MARKER,"card1","card4")):
        for system in permutations((BLUE,VERSION)):
            leaves=[]
            for child in root:leaves.extend(system if child=="card1" else [NAV] if child=="card4" else [MARKER])
            result.append(tuple(leaves))
    return result


def initial():
    return dict(active={name:"old" for name in FILES},stage={name:"new" for name in FILES}|{MARKER:"marker"},
        stage_directory=True,progress_bytes=0,managers_launched=False)


def apply(state,order,copy_ok,guard_delete=False):
    """Coherent operations; a failed copy leaves its destination unchanged. Deletes succeed.

    The guard variant changes only per-file source deletion after failed copy.
    Neither variant is implemented as a firmware patch.
    """
    state=deepcopy(state);trace=[]
    def record(op,path=None):trace.append(dict(operation=op,path=path,state=deepcopy(state)))
    record("boot-entry")
    if state["stage_directory"]:
        if MARKER in state["stage"]:
            if NAV in state["stage"]:
                state["active"].pop(NAV,None);record("delete-existing-nav",NAV)
            # Each call takes the remaining directory leaves in a valid recursive order.
            for name in order:
                if name not in state["stage"]:continue
                ok=copy_ok.get(name,True)
                if ok:state["active"][name]=state["stage"][name]
                record("copy-success" if ok else "copy-failure",name)
                state["progress_bytes"]+=SIZES[name];record("count-attempted-bytes",name)
                if ok or not guard_delete:
                    state["stage"].pop(name,None);record("delete-source",name)
            state["stage_directory"]=bool(state["stage"])
            record("remove-staging-directory-attempt")
        # Caller also invokes recursive deletion when extraction marker is absent.
        state["stage"].clear();state["stage_directory"]=False;record("caller-recursive-cleanup")
    state["managers_launched"]=True;record("launch-manager")
    return state,trace


def complete(state):return all(state["active"].get(name)=="new" for name in FILES)


def explore():
    valid=orders();assert len(set(valid))==12
    stats={};examples={}
    for guarded in (False,True):
        label="native" if not guarded else "copy-guard-only-hypothesis"
        cases=0;incomplete=0;false_version=0;cuts=0;cut_failure=0;marker_loss=0
        for order in valid:
            for bits in product((False,True),repeat=3):
                status=dict(zip(FILES,bits));state,trace=apply(initial(),order,status,guarded);cases+=1
                if all(bits):assert complete(state)
                if not complete(state):
                    incomplete+=1;assert not state["stage"]
                    examples.setdefault(label+"-failed-copy",dict(order=order,copy_ok=status,trace=trace))
                if state["active"].get(VERSION)=="new" and not complete(state):false_version+=1
                # Cut at every coherent-operation boundary; reboot copy failures have cleared.
                # No claim is made about real FAT write durability or mid-operation power loss.
                for index,entry in enumerate(trace):
                    snapshot=deepcopy(entry["state"]);snapshot["managers_launched"]=False
                    recovered,replay=apply(snapshot,order,{},guarded);cuts+=1
                    if not complete(recovered):
                        cut_failure+=1
                        if snapshot["stage"] and MARKER not in snapshot["stage"]:
                            marker_loss+=1
                            if all(bits):examples.setdefault(label+"-marker-consumed-cut",dict(order=order,
                                cut_after=index,cut_operation=entry["operation"],prefix=trace[:index+1],reboot=replay))
        stats[label]=dict(copy_outcome_cases=cases,incomplete_after_return=incomplete,
            new_version_with_incomplete_payload=false_version,coherent_cut_reboot_cases=cuts,
            incomplete_after_reboot=cut_failure,missing_marker_nonempty_stage_failures=marker_loss)
    # Update-startup branch: marker is created BEFORE backup/format; crash BEFORE
    # format leaves it on Card2. Next startup sees it, formats Card2 and deletes TFAT.
    interrupted_backup=dict(before_cut=dict(card2={"unique-user-setting":"old","scan_done_flag.bin":"marker"},
        tfat_backup={"unique-user-setting":"old","scan_done_flag.bin":"marker"},
        main_stage_marker=True),next_update_startup=["detect-scan-marker","format-Card2","delete-TFAT-backup"],
        after=dict(card2={},tfat_backup={}),scope="Successful original backup, cut before format, staged upgrade still present")
    return dict(model="Coherent dictionary operations derived from reviewed control flow; no native filesystem execution",
        enumeration_scope="12 depth-first leaf orders; eight independent copy results; all deletes succeed",
        crash_scope="Boundary cuts followed by one reboot with successful copies; not within-call/flush/NAND faults",
        stats=stats,counterexamples=examples,config_counterexample=interrupted_backup,
        invariants_required_for_fix=["Retain extraction receipt and all needed source files until full installed-file verification",
            "Propagate copy/enumeration/directory errors through recursion, staging caller and manager startup",
            "Publish Version_Info only after required payloads are verified; preserve a separate recovery receipt",
            "Keep a verified configuration backup across format/restore failures and reboot",
            "Do not treat an existing scan marker as proof that a backup is complete or expendable"],
        not_implemented="No guarded or transactional firmware patch is written by this model")


if __name__=="__main__":
    import json
    print(json.dumps(explore()["stats"],indent=2))
