/* Non-matching: best partial attempt (89.27% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern void *memset(void *dst, int value, u32 size);
extern s32 fn_80089244(void *out_a, void *out_b);
extern s32 TRKAppendBuffer_ui8(void *buffer, const void *data, s32 length);
extern s32 TRKReadBuffer_ui8(void *buffer, void *data, u32 length);
extern s32 fn_8008AB20(void *buffer, void *out, s32 a2, s32 a3, u32 a4);
extern void *TRKGetBuffer(u32 handle);
extern void fn_800891B4(void *arg0);
extern s32 fn_80089144(void *arg0, u32 arg1);
extern s32 fn_80088B00(void *arg0);

struct RequestBuffer {
    u32 length;
    u8 type;
    u8 unk_5[3];
    s32 unk_8;
    u32 unk_C;
    u8 unk_E[0x32];
};

#pragma peephole off
#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
#pragma opt_propagation off
#pragma opt_dead_assignments off
#pragma opt_common_subs off
s32 fn_8008AD00(u32 arg0, u32 arg1, u32 *arg2, s32 *arg3, s32 arg4, s32 arg5) {
    register void *buf;
    register u32 chunk;
    register s32 offset;
    register s32 flag;
    void * tmp_call3;
    s16 lab_t4;
    register u32 ret;
    register u32 got;
    struct RequestBuffer request;
    u32 loc_10;
    struct { u32 value; } loc_C;
    u32 loc_8;
    register s32 result;

    if (arg1 == 0 || *arg2 == 0) {
        return 2;
    }
    *arg3 = 0;
    flag = 0;
    offset = 0;
    result = 0;
    goto loop_test;
loop_body:
    memset(&request, 0, 0x40);
    chunk = 0x800;
    if (*arg2 - offset <= 0x800) {
        chunk = *arg2 - offset;
    }
    request.type = arg5 != 0 ? 0xd1 : 0xd0;
    request.length = arg5 != 0 ? 0x40 : chunk + 0x40;
    request.unk_8 = arg0;
    request.unk_C = chunk;
    fn_80089244(&loc_C.value, &loc_8);
    result = TRKAppendBuffer_ui8((void *)loc_8, &request, 0x40);
    if (arg5 == 0 && result == 0) {
        result = TRKAppendBuffer_ui8((void *)loc_8, (void *)(arg1 + offset), chunk);
    }
    if (result == 0) {
        if (arg4 != 0) {
            lab_t4 = arg5 == 0 || arg0 != 0;
            result = fn_8008AB20((void *)loc_8, &loc_10, 5, 3, lab_t4);
            if (result == 0) {
                tmp_call3 = TRKGetBuffer(loc_10);
                buf = tmp_call3;
            }
            got = *(u16 *)((u8 *)buf + 0x24);
            ret = *(u32 *)((u8 *)buf + 0x20) & 0xFF;
            if (arg5 != 0 && result == 0 && got <= chunk) {
                fn_80089144(buf, 0x40);
                result = TRKReadBuffer_ui8(buf, (void *)(arg1 + offset), got);
                if (result == 0x302) {
                    result = 0;
                }
            }
            if (got != chunk) {
                if ((arg5 == 0 || got >= chunk) && ret == 0) {
                    ret = 1;
                }
                chunk = got;
                flag = 1;
            }
            *arg3 = ret;
            fn_800891B4((void *)loc_10);
        } else {
            result = fn_80088B00((void *)loc_8);
        }
    }
    fn_800891B4((void *)loc_C.value);
    offset += chunk;
loop_test:
    if (flag == 0 && offset < *arg2 && result == 0 && *arg3 == 0) {
        goto loop_body;
    }
    *arg2 = offset;
    return result;
}
#pragma opt_common_subs reset
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma opt_loop_invariants reset
#pragma opt_strength_reduction reset
#pragma peephole reset
