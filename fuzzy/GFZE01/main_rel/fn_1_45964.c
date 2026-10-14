/* Non-matching: best partial attempt (89.10% in the project ledger). Scored for the
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

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_384C0;
u32 fzgx_obj_lbl_1_bss_384C4;
u32 fzgx_obj_lbl_1_bss_384C8;
u32 fzgx_obj_lbl_1_bss_384CC;
u32 fzgx_obj_lbl_1_bss_384D0;
u8 lbl_1_bss_384D0__fzgx_offset_4;
u8 lbl_1_bss_384D0__fzgx_offset_5;
u8 lbl_1_bss_384D0__fzgx_offset_5__b1;
u8 lbl_1_bss_384D0__fzgx_offset_5__b2;
u32 fzgx_obj_lbl_1_bss_384D8[4096];
u32 lbl_1_bss_384D8__fzgx_offset_4000[1536];
u32 fzgx_obj_lbl_1_bss_3DCD8;
u32 fzgx_obj_lbl_1_bss_3DCDC[2];
u32 fzgx_obj_lbl_1_bss_3DCE4[17];
u32 fzgx_obj_lbl_1_bss_3DD28[3];
u32 lbl_1_bss_3DD28__fzgx_offset_C[14];
u32 lbl_1_bss_3DD28__fzgx_offset_44[18];
u32 lbl_1_bss_3DD28__fzgx_offset_8C[128];
u32 lbl_1_bss_3DD28__fzgx_offset_28C[16];

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_384C0;
    s = fzgx_obj_lbl_1_bss_384C4;
    s = fzgx_obj_lbl_1_bss_384C8;
    s = fzgx_obj_lbl_1_bss_384CC;
    s = fzgx_obj_lbl_1_bss_384D0;
    s = lbl_1_bss_384D0__fzgx_offset_4;
    s = lbl_1_bss_384D0__fzgx_offset_5;
    s = lbl_1_bss_384D0__fzgx_offset_5__b1;
    s = lbl_1_bss_384D0__fzgx_offset_5__b2;
    s = ((0)[fzgx_obj_lbl_1_bss_384D8]);
    s = ((0)[lbl_1_bss_384D8__fzgx_offset_4000]);
    s = fzgx_obj_lbl_1_bss_3DCD8;
    s = ((0)[fzgx_obj_lbl_1_bss_3DCDC]);
    s = ((0)[fzgx_obj_lbl_1_bss_3DCE4]);
    s = ((0)[fzgx_obj_lbl_1_bss_3DD28]);
    s = ((0)[lbl_1_bss_3DD28__fzgx_offset_C]);
    s = ((0)[lbl_1_bss_3DD28__fzgx_offset_44]);
    s = ((0)[lbl_1_bss_3DD28__fzgx_offset_8C]);
    s = ((0)[lbl_1_bss_3DD28__fzgx_offset_28C]);
}
#pragma section code_type ".text"

#pragma opt_propagation on
u32 fn_1_45964(Sig_fn_1_45B2C_Fn145B2CData *arg0, void *arg1, u32 arg2, u32 arg3, u32 arg4) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    Sig_ARQPostRequest_ARQRequest *req;
    u32 lab_t3;
    struct { u32 *value; } flags, values;
    struct { Sig_ARQPostRequest_ARQRequest *value; } requests;
    struct { s32 value; } len;
    v0 = lbl_1_bss_384D0__fzgx_offset_4;
    flags.value = fzgx_obj_lbl_1_bss_3DCE4;
    values.value = lbl_1_bss_3DD28__fzgx_offset_28C;
    v1 = v0 + 1;
    v2 = v0 << 2;
    v3 = v1 & 0xFF;
    lbl_1_bss_384D0__fzgx_offset_4 = v1;
    v0 = v0 << 5;
    requests.value = (Sig_ARQPostRequest_ARQRequest *)lbl_1_bss_3DD28__fzgx_offset_8C;
    *(u32 *)((u8 *)flags.value + v2) = 1;
    req = (Sig_ARQPostRequest_ARQRequest *)((u8 *)requests.value + v0);
    *(u32 *)((u8 *)values.value + v2) = arg4;
    lbl_1_bss_384D0__fzgx_offset_4 = (v3 > 15 ? 0 : v3);
    switch(arg0->kind) {
    case 1:
        len.value = arg2;
        DCInvalidateRange(arg1, len.value);
        lab_t3 = 1;
        ARQPostRequest(req, 0, 1, lab_t3, arg0->value + arg3, arg1, len.value, (Sig_ARQPostRequest_ARQCallback)fn_1_45A58);
        return 1;
    default:
        return fn_80006DAC((u8 *)arg0 + 4, arg1, arg2, arg3, (void (*)(void))fn_1_45A58, (void (*)(void))fn_1_45A58, 0);
    }
}

