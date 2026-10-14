/* Non-matching: best partial attempt (95.13% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_1_96C40_pool {
    u8 pad_0[0x124];
    f32 unk_124;
    f32 unk_128;
    u8 pad_12C[0xC];
    f64 unk_138;
    u8 pad_140[0x90];
    u32 unk_1D0;
    u32 unk_1D4;
    u32 unk_1D8;
    f32 unk_1DC;
};

extern struct fn_1_96C40_pool lbl_1_rodata_3E48;
extern u32 *lbl_801A6D00;
extern u32 lbl_8006DCA4(u32);
extern u32 GXLoadPosMtxImm(u32, u32);
extern void fn_800724C8(void);
extern void fn_8007245C(u32);
extern void fn_80074788(u32);
extern void fn_800725DC(u32 *);
extern void fn_80072614(u32 *);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_80074660(u32);
extern void fn_80073678(u32);
extern void fn_80073C6C(s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern s32 fn_80072EDC(s32, u32);
extern void fn_80072864(u32);
extern void fn_8003462C(u32, u32, u32);

static inline f32 fn_1_96C40_read_pointer(struct fn_1_96C40_pool * owner) { return owner->unk_128; }
#pragma opt_propagation off
#pragma opt_dead_assignments off
#pragma peephole on
void fn_1_96C40(void *arg0) {
    volatile u32 v0;
    volatile u32 v0b;
    struct { s32 value; } v1;
    s32 v2;
    struct fn_1_96C40_pool *p_rodata;
    s32 v5;
    s32 v6;
    f32 v4;
    f64 v3;
    f32 v7;
    f32 v8;
    s32 v9;
    f32 v11;
    f32 v13;
    f32 v14;
    u32 loc_10;
    u32 loc_C;
    u32 loc_8;

    p_rodata = &lbl_1_rodata_3E48;
    v0 = p_rodata->unk_1D0;
    v0b = p_rodata->unk_1D4;
    lbl_8006DCA4(v0);
    GXLoadPosMtxImm(*lbl_801A6D00, 0);
    v1.value = (s32)*(f32 *)((u8 *)arg0 + 0xA8);
    v2 = (s32)*(f32 *)((u8 *)arg0 + 0xB0);
    fn_800724C8();
    fn_8007245C(0x2200);
    fn_80074788(1);
    loc_10 = v0;
    fn_800725DC(&loc_10);
    loc_C = v0b;
    fn_80072614(&loc_C);
    fn_800747D0(4, 0, 0, 0, 0, 0, 2);
    fn_80074660(0);
    fn_80073678(1);
    fn_80073C6C(0);
    fn_80072AB0(0, 0, 0);
    fn_800734A8(0, 0xFF, 0xFF, 4);
    fn_80072EDC(0, 4);
    fn_80072864(0);
    v3 = ((*(f64 volatile *)&(p_rodata->unk_138)) /* Retail reloads this field. */);
    v5 = 0;
    v4 = (p_rodata->unk_1DC);
    do {
        v6 = -10;
        do {
            v7 = (f32)(s32)(v1.value + v6) - v4;
            v8 = v4 + (f32)(s32)(v1.value + v6);
            v9 = -10;
            do {
                if ((u32)v5 != ((v6 + v9) & 1)) {
                    v11 = (p_rodata->unk_1DC);
                    v13 = (f32)(s32)(v2 + v9) - v11;
                    v14 = v11 + (f32)(s32)(v2 + v9);
                    fn_8003462C(0x80, 7, 4);
                    *(f32 *)((u8 *)0xCC010000 + -32768) = v7;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
                    *(f32 *)((u8 *)0xCC010000 + -32768) = p_rodata->unk_124;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
                    *(f32 *)((u8 *)0xCC010000 + -32768) = v13;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
                    *(f32 *)((u8 *)0xCC010000 + -32768) = p_rodata->unk_124;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
                    *(f32 *)((u8 *)0xCC010000 + -32768) = p_rodata->unk_124;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
                    *(f32 *)((u8 *)0xCC010000 + -32768) = v8;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
                    *(f32 *)((u8 *)0xCC010000 + -32768) = p_rodata->unk_124;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
                    *(f32 *)((u8 *)0xCC010000 + -32768) = v13;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
                    *(f32 *)((u8 *)0xCC010000 + -32768) = fn_1_96C40_read_pointer(p_rodata);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
                    *(f32 *)((u8 *)0xCC010000 + -32768) = p_rodata->unk_124;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
                    *(f32 *)((u8 *)0xCC010000 + -32768) = v8;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
                    *(f32 *)((u8 *)0xCC010000 + -32768) = p_rodata->unk_124;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
                    *(f32 *)((u8 *)0xCC010000 + -32768) = v14;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
                    *(f32 *)((u8 *)0xCC010000 + -32768) = fn_1_96C40_read_pointer(p_rodata);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
                    *(f32 *)((u8 *)0xCC010000 + -32768) = fn_1_96C40_read_pointer(p_rodata);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
                    *(f32 *)((u8 *)0xCC010000 + -32768) = v7;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
                    *(f32 *)((u8 *)0xCC010000 + -32768) = p_rodata->unk_124;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
                    *(f32 *)((u8 *)0xCC010000 + -32768) = v14;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
                    *(f32 *)((u8 *)0xCC010000 + -32768) = p_rodata->unk_124;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
                    *(f32 *)((u8 *)0xCC010000 + -32768) = fn_1_96C40_read_pointer(p_rodata);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
                }
                v9++;
            } while (v9 <= 10);
            v6++;
        } while (v6 <= 10);
        loc_8 = p_rodata->unk_1D8;
        fn_800725DC(&loc_8);
        v5++;
    } while (v5 < 2);
}
#pragma peephole reset

#pragma opt_dead_assignments reset

#pragma opt_propagation reset

