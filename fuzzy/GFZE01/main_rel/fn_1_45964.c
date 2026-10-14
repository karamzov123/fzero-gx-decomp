/* Non-matching: best partial attempt (85.23% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/load.h"
typedef struct Sig_fn_1_45B2C_Fn145B2CData {
    s32 kind;
    u8 pad[0x50];
    u32 value;
} Sig_fn_1_45B2C_Fn145B2CData;
typedef void (*Sig_ARQPostRequest_ARQCallback)(u32);
typedef struct Sig_ARQPostRequest_ARQRequest {
    struct Sig_ARQPostRequest_ARQRequest *next;
    u32 owner, type, priority, source, dest, length;
    Sig_ARQPostRequest_ARQCallback callback;
} Sig_ARQPostRequest_ARQRequest;
extern void ARQPostRequest(Sig_ARQPostRequest_ARQRequest *, u32, u32, u32, u32, void *, u32, Sig_ARQPostRequest_ARQCallback);
extern void DCInvalidateRange(void *, u32);
extern u32 fn_1_45A58(void);
extern u32 fn_80006DAC(void *, void *, u32, u32, void (*)(void), void (*)(void), u32);

#pragma opt_propagation off
u32 fn_1_45964(Sig_fn_1_45B2C_Fn145B2CData *arg0, void *arg1, u32 arg2, u32 arg3, u32 arg4) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    Sig_ARQPostRequest_ARQRequest *req;
    struct State {
        u8 pad_0[0x14];
        u8 unk_14;
        u8 pad_15[0x5824 - 0x15];
        u32 flags[52];
        Sig_ARQPostRequest_ARQRequest requests[16];
        u32 values[16];
    } *state = (struct State *)&lbl_1_bss_384C0;
    struct { u32 *value; } flags, values;
    struct { Sig_ARQPostRequest_ARQRequest *value; } requests;
    struct { u32 value; } len;
    v0 = state->unk_14;
    flags.value = state->flags;
    values.value = state->values;
    v1 = v0 + 1;
    v2 = v0 << 2;
    v3 = v1 & 0xFF;
    state->unk_14 = v1;
    v1 = v3 > 15 ? 0 : v3;
    v0 = v0 << 5;
    requests.value = state->requests;
    *(u32 *)((u8 *)flags.value + v2) = 1;
    req = (Sig_ARQPostRequest_ARQRequest *)((u8 *)requests.value + v0);
    *(u32 *)((u8 *)values.value + v2) = arg4;
    state->unk_14 = v1;
    switch(arg0->kind) {
    case 1:
        len.value = arg2;
        DCInvalidateRange(arg1, len.value);
        ARQPostRequest(req, 0, 1, 1, arg0->value + arg3, arg1, len.value, (Sig_ARQPostRequest_ARQCallback)fn_1_45A58);
        return 1;
    default:
        return fn_80006DAC((u8 *)arg0 + 4, arg1, arg2, arg3, (void (*)(void))fn_1_45A58, (void (*)(void))fn_1_45A58, 0);
    }
}
