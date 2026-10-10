"""Bounded projections of reviewed ROM metadata branches; no native execution."""
from parse_png_metadata import inflate_bounded

TEXT_FIELDS=[(b"Title",0x1d4,0x0320),(b"Author",0x1dc,0x013b),
    (b"Copyright",0x1e4,0x8298),(b"Description",0x1ec,0x010e),
    (b"CreationTime",0x1f4,0x9003),(b"Software",0x1fc,0x0131),
    (b"Source",0x204,0x0110),(b"Comment",0x20c,0x9286),
    (b"Disclaimer",0x20c,0x9286),(b"Warning",0x20c,0x9286)]


def classify_keyword(key):
    if len(key)>78:return dict(result="rejected_length",helper_status=0)
    for literal,pointer,tag in TEXT_FIELDS:
        if len(key)<len(literal) and literal.startswith(key):
            return dict(result="indeterminate_uninitialized_stack",literal=literal.decode())
        if key.startswith(literal):
            return dict(result="field",pointer_offset=hex(pointer),count_offset=hex(pointer+4),tag=hex(tag))
    return dict(result="ignored",helper_status=1)


def compressed_storage(data,previous=None,profile=False):
    """Valid host zlib input plus native capacity/status projection, assuming allocations succeed.

    Does not emulate inflate. A full output larger than capacity projects the
    reviewed provider's buffer-shortage status -5. Records the bad write rather
    than performing it. No huge allocation, allocator fault or native call.
    """
    output=inflate_bounded(data);capacity=len(data)*4
    assert capacity<=0xffffffff
    status=0 if len(output)<=capacity else -5
    result=dict(compressed_bytes=len(data),output_bytes=len(output),allocation_bytes=capacity,
        projected_provider_status=status,retry_on_minus4=True,retry_taken=False,
        model_scope="Valid bounded zlib stream; successful allocations; reviewed native branch projection")
    if profile:
        result.update(helper_status=1,retained_profile_bytes=len(output) if not status else 0,
            allocation_freed=bool(status),icc_internals_validated=False)
    elif previous is None:
        result.update(helper_status=0 if status else 1,allocation_freed=bool(status))
        if not status:result.update(count=len(output)+1,null_write_offset=len(output),
            null_write_outside_requested_allocation=len(output)==capacity)
    else:
        assert previous and previous[-1:]==b"\0"
        changed=previous[:-1]+b" "
        result.update(old_count=len(previous),old_buffer_after_initial_mutation_hex=changed.hex())
        if status:result.update(helper_status=0,count=len(previous),old_buffer_terminated=False,
            temporary_allocation_unreleased_bytes=capacity)
        else:
            combined=changed+output+b"\0"
            result.update(helper_status=1,count=len(combined),result_hex=combined.hex(),
                old_buffer_terminated=True,temporary_allocation_unreleased_bytes=0)
    return result


def time_string(year,month,day,hour,minute,second):
    assert 0<=year<=65535 and all(0<=n<=255 for n in [month,day,hour,minute,second])
    result=bytearray([(year//1000+48)&255,year%1000//100+48,year%100//10+48,year%10+48])
    for separator,n in zip([b":",b":",b" ",b":",b":"],[month,day,hour,minute,second]):
        result.extend(separator);result.extend([n//10+48,n%10+48])
    result.append(0);assert len(result)==20
    return bytes(result)


def lazy_property_fault(lengths,failed_index,calls):
    """Fail the same property insertion on each lazy initialization attempt."""
    count=0;total=0;nodes=[];trace=[]
    assert 0<=failed_index<len(lengths) and calls>0
    for call in range(calls):
        for i,length in enumerate(lengths):
            count+=1;total+=length
            if i==failed_index:break
            nodes.append(length)
        trace.append(dict(call=call+1,reported_count=count,reported_payload_bytes=total,
            linked_nodes=len(nodes),linked_payload_bytes=sum(nodes),initialized=False,returned_status=0))
    return dict(trace=trace,cleanup_guard_entered=False,
        skipped_node_and_payload_bytes=sum(24+n for n in nodes),
        scope="Logical allocation-failure trace; no native heap fault injection")
