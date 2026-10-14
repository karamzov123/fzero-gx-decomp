/* Non-matching: best partial attempt (94.06% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_1_A11EC_lbl_1_bss_6EA98 {
    u8 pad_0[0xD];
    u8 unk_D;
    u8 pad_E[0xE];
    u32 unk_1C;
    u8 pad_20[0x781];
    u8 unk_7A1;
    u8 pad_7A2[0x2];
    u32 unk_7A4;
    u8 unk_7A8;
    u8 unk_7A9;
    u8 unk_7AA;
    u8 unk_7AB;
    u8 unk_7AC;
    u8 pad_7AD[0x3];
    u8 unk_7B0;
    u8 pad_7B1[0xCB];
    u8 unk_87C;
    u8 unk_87D;
    u8 unk_87E;
    u8 unk_87F;
    u16 unk_880;
};

extern struct fn_1_A11EC_lbl_1_bss_6EA98 lbl_1_bss_6EA98;
extern void fn_1_A2DF4(s32, void *, s32);
extern void fn_1_A2E24(u32, u32, s32);
extern void fn_80008BEC(void *, int, u32);

#pragma peephole off
#pragma opt_propagation off
u32 fn_1_A11EC(void) {
    u32 v0;
    void * v1;
    struct fn_1_A11EC_lbl_1_bss_6EA98 *p_lbl_1_bss_6EA98;
    u32 v2;
    s32 lab_t0;
    p_lbl_1_bss_6EA98 = (struct fn_1_A11EC_lbl_1_bss_6EA98 *)&lbl_1_bss_6EA98;
    if (p_lbl_1_bss_6EA98->unk_D == 0) {
    v1 = (void *)(((u8 *)(u32)p_lbl_1_bss_6EA98 + 1868));
    *(u8 *)((u8 *)v1 + 2) = 0;
    v0 = (u32)((u8 *)(u32)p_lbl_1_bss_6EA98 + 2112);
    *(u8 *)((u8 *)v1 + 22) = 0;
    *(u8 *)((u8 *)v1 + 42) = 0;
    ((u8 *)v1)[62] = 0;
    fn_80008BEC((void *)v0, 0, 60);
    v0 = (u32)(v1);
    fn_80008BEC((void *)v0, 0, 80);
    v0 = 0xA0000000;
    *(u8 *)((u8 *)v1 + 2) = 0;
    v2 = (v0 + 768);
    v0 = 16;
    *(u8 *)((u8 *)v1 + 1) = 255;
    *(u8 *)((u8 *)v1 + 21) = 255;
    *(u8 *)((u8 *)v1 + 22) = 0;
    *(u8 *)((u8 *)v1 + 41) = 255;
    *(u8 *)((u8 *)v1 + 42) = 0;
    *(u8 *)((u8 *)v1 + 61) = 255;
    *(u8 *)((u8 *)v1 + 62) = 0;
    p_lbl_1_bss_6EA98->unk_1C = 0;
    p_lbl_1_bss_6EA98->unk_87C = 0;
    p_lbl_1_bss_6EA98->unk_87D = 0;
    p_lbl_1_bss_6EA98->unk_87E = 1;
    p_lbl_1_bss_6EA98->unk_87F = 1;
    p_lbl_1_bss_6EA98->unk_7A1 = 0;
    p_lbl_1_bss_6EA98->unk_7A4 = 0;
    p_lbl_1_bss_6EA98->unk_880 = 0;
    p_lbl_1_bss_6EA98->unk_7A8 = 0;
    p_lbl_1_bss_6EA98->unk_7A9 = 0;
    p_lbl_1_bss_6EA98->unk_7AA = 0;
    p_lbl_1_bss_6EA98->unk_7AB = 0;
    p_lbl_1_bss_6EA98->unk_7AC = 1;
    fn_1_A2E24(v0, v2, 0);
    v0 = 6;
    fn_1_A2DF4(v0, (void *)0xA6000000, 0);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    v0 = 7;
    fn_1_A2DF4(v0, (void *)0xA6000000, 0);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    v0 = 5;
    fn_1_A2DF4(v0, (void *)0xA6000000, 0);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    v0 = 4;
    lab_t0 = v0;
    fn_1_A2DF4(lab_t0, (void *)0xA6000000, 0);
    v0 = 16;
    fn_1_A2E24(v0, 0xA0100000, 127);
    v0 = (u32)((u8 *)(u32)p_lbl_1_bss_6EA98 + 1968);
    p_lbl_1_bss_6EA98->unk_7B0 = 9;
    *(u8 *)((u8 *)v0 + 1) = 9;
    *(u8 *)((u8 *)v0 + 2) = 9;
    *(u8 *)((u8 *)v0 + 3) = 9;
    }
    return (u32)v0;
}
#pragma opt_propagation reset

#pragma peephole reset

