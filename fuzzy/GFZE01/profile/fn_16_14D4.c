/* Non-matching: best partial attempt (89.70% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/profile/data/lbl_16_data_0.h"

struct fn_16_14D4_ent {
    u8 pad_0[0x148];
    void *unk_148;
    void *unk_14C;
    void *unk_150;
    u8 pad_154[0x394];
};

struct fn_16_14D4_state {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x4];
    s16 unk_C;
    u8 pad_E[0x3E];
    u32 unk_4C;
    u16 unk_50;
    u16 unk_52;
    u16 unk_54;
    u8 pad_56[0x2];
    s16 unk_58;
    u32 unk_5C;
    u32 unk_60;
    u8 pad_64[0x10];
    struct fn_16_14D4_ent unk_74[2];
    u8 pad_A44[0x180];
    u32 unk_1C4;
};

struct fn_16_14D4_bss0 {
    u8 pad_0[316];
    u32 unk_14C;
    u32 unk_150;
    u8 pad_154[0xC8];
    s32 unk_21C;

    u8 fzgx_tail_padding[16];
};

struct fn_16_14D4_win {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u16 f4;
    u16 f6;
    u16 f8;
    u8 fa;
    f32 fc;
    f32 f10;
    u8 f14;
    u8 f15;
    u8 f16;
    s8 f17;
    s16 f18;
    u8 f1a;
    u8 f1b;
    u32 f1c;
};

extern struct fn_16_14D4_state lbl_1_bss_8B614;
extern struct fn_16_14D4_bss0 lbl_16_bss_0;
extern struct fn_16_14D4_win lbl_1_bss_58;
extern u32 lbl_16_bss_B0B4;
extern u16 lbl_1_bss_96A;
extern char lbl_1_bss_198[];
extern char *lbl_1_data_370[];
extern const f32 lbl_16_rodata_48[4];
extern u32 lbl_801A66B4;
extern u32 lbl_801A66C0;

extern s32 fn_1_12C930(s16);
extern s32 fn_1_12CB04(s16);
extern s32 fn_1_12CCB0(s16, s16);
extern void fn_1_8F198(void *, s16, u32, u32);
extern void fn_1_933D8(void *, void *, u32);
extern int fn_1_41488(u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_8F62C(void);
extern int fn_1_4C10(void);
extern void fn_1_4A00(s32, s32, u32);
extern s16 fn_16_1A24(void);
extern char *fn_80083DB0(char *, const char *);
extern int sprintf(char *, const char *, ...);

#pragma opt_common_subs on
static inline void fn_16_14D4_call_fn_1_8F198(void * a0, s32 a1, u32 a2, u32 a3) { fn_1_8F198(a0, (s16)a1, a2, a3); }
#pragma opt_dead_assignments on
#pragma opt_lifetimes off
#pragma opt_loop_invariants off
static inline void fn_16_14D4_call_fn_1_933D8(void * a0, void * a1, u32 a2) { fn_1_933D8(a0, a1, a2); }
void fn_16_14D4(void) {
    u16 *fzgx_value___;
    u8 *fzgx_value__;
    s16 fzgx_value_;
    u32 *fzgx_value;
    s32 t_2;
    struct fn_16_14D4_bss0 *b0 = &lbl_16_bss_0;
    s32 t;
    s16 r;
    u32 *tail = (u32 *)((u8 *)&lbl_16_data_0 + 0x80000);
    u32 v;
    struct { s16 value; } i;
    u32 c = lbl_1_bss_8B614.unk_C;
    void * lab_t1;
    u32 lab_t0;
    u32 lab_t3;

    if (lbl_1_bss_8B614.unk_58 == 2 && lbl_801A66C0 >= 0x78) {
{
        s16 n0 = fn_1_12C930(c);
    struct fn_16_14D4_ent *e0 = &lbl_1_bss_8B614.unk_74[0];
        fn_16_14D4_call_fn_1_8F198(e0, n0, lbl_1_bss_8B614.unk_5C, lbl_1_bss_8B614.unk_60);
        v = fn_1_41488(*(u32 *)((u8 *)*(u32 *)((u8 *)&lbl_1_bss_8B614 + 0x1C4) + 0x24),
                       tail[0xACD]);
        lab_t1 = &lbl_1_bss_8B614.unk_74[0].unk_148;
        fn_1_933D8(e0, lab_t1, v & 0xFFFF);
        fn_1_435C(b0->unk_14C);
        lab_t0 = (u32)(tail + 0xB4D);
        lab_t3 = 8;
        tail[0xAC1] = fn_1_3F8C(lab_t0, (u32)fn_1_8F62C, (u32)e0, lab_t3);
}
        {
            struct fn_16_14D4_ent *b = &lbl_1_bss_8B614.unk_74[1];
            u32 *p2 = tail + 0x2AC2;
            for (i.value = 0; i.value < (s16)fn_1_12CB04(c); i.value++) {
                fn_1_8F198(&b[i.value], fn_1_12CCB0(c, i.value),
                           lbl_1_bss_8B614.unk_5C, lbl_1_bss_8B614.unk_60);
                lab_t1 = &b[i.value].unk_148;
                fn_16_14D4_call_fn_1_933D8(&b[i.value], lab_t1, (u16)v);
                fn_1_435C(b0->unk_14C);
                lab_t0 = (u32)(tail + 0xB4D);
                lab_t3 = 8;
                p2[i.value] = fn_1_3F8C(lab_t0, (u32)fn_1_8F62C, (u32)&b[i.value], lab_t3);
            }
        }
        fzgx_value = &(lbl_1_bss_8B614.unk_4C);
        *fzgx_value = 0;
        lbl_1_bss_8B614.unk_4C |= 0x80000000;
        fzgx_value_ = 4;
        lbl_1_bss_8B614.unk_58 = fzgx_value_;
        lbl_1_bss_8B614.unk_4C |= 0x04000001;
        lbl_1_bss_8B614.unk_50 = 1;
        lbl_1_bss_8B614.unk_52 = 0;
        fzgx_value___ = &(lbl_1_bss_8B614.unk_54);
        *fzgx_value___ = 0x78;
    }
    if (b0->unk_21C == -1) {
        fn_1_4C10();
    }
    if ((lbl_1_bss_8B614.unk_4C & 0x80000000) && !(lbl_1_bss_8B614.unk_4C & 1)
        && !(lbl_1_bss_8B614.unk_4 & 0x10000000)) {
        t = 1;
    } else if (fn_1_4C10() != 0) {
        t = 1;
    } else {
        t = 0;
    }
    if (t != 0) {
        return;
    }
    if (b0->unk_21C != -1) {
        t_2 = b0->unk_21C;
        b0->unk_21C = -1U;
        lbl_1_bss_96A = (u16) t_2;
        return;
    }
    r = fn_16_1A24();
    (void) r;  /* fzgx: keeps the web at its definition */
    if (r != 0) {
        fn_1_4A00(0, 0xF, b0->unk_150);
        lbl_1_bss_8B614.unk_4C = 0;
        lbl_1_bss_8B614.unk_4C |= 0x80000000;
        lbl_16_bss_B0B4 = 0;
        lbl_1_bss_8B614.unk_4C |= 0x08000000;
        lbl_1_bss_8B614.unk_50 = 1;
        lbl_1_bss_8B614.unk_52 = 0;
        lbl_1_bss_8B614.unk_54 = 0xF;
    }
    if (r == -1) {
        b0->unk_21C = 0xBF;
    }
    if (r == 1) {
        b0->unk_21C = 0xC1;
        return;
    }
    if (r != 2) {
        return;
    }
    sprintf(lbl_1_bss_198, (char *)(tail + 0xB53),
            lbl_1_bss_8B614.unk_C == 0x1E
                ? 0
                : (lbl_1_bss_8B614.unk_C + 1 <= 0 ? lbl_1_bss_8B614.unk_C + 1
                                                  : lbl_1_bss_8B614.unk_C));
    sprintf(lbl_1_bss_198 + 0x40, (char *)(tail + 0xB57),
            lbl_1_data_370[lbl_1_bss_8B614.unk_C == 0x1E
                               ? 0
                               : (lbl_1_bss_8B614.unk_C + 1 <= 0
                                      ? lbl_1_bss_8B614.unk_C + 1
                                      : lbl_1_bss_8B614.unk_C)]);
    fn_80083DB0(lbl_1_bss_198 + 0x80, (char *)(tail + 0xB5B));
    lbl_1_bss_58.f2 = 0;
    lbl_1_bss_58.f4 = 0x280;
    lbl_1_bss_58.f6 = 0x150;
    lbl_1_bss_58.f14 = 7;
    lbl_1_bss_58.f0 = lbl_801A66B4;
    lbl_1_bss_58.f1 = 1;
    lbl_1_bss_58.f3 = 0;
    lbl_1_bss_58.f8 = 0;
    lbl_1_bss_58.fa = 0;
    lbl_1_bss_58.fc = lbl_16_rodata_48[0];
    lbl_1_bss_58.f10 = lbl_16_rodata_48[0];
    lbl_1_bss_58.f16 = 0;
    lbl_1_bss_58.f17 = -1;
    lbl_1_bss_58.f18 = -1;
    lbl_1_bss_58.f1c = 0;
    lbl_1_bss_58.f4 = 0x140;
    lbl_1_bss_58.f6 = 0xF0;
    lbl_1_bss_58.f14 = 2;
    fzgx_value__ = &(lbl_1_bss_58.f2);
    *fzgx_value__ = 1;
    lbl_1_bss_8B614.unk_4 |= 0x40000000;
}
#pragma opt_loop_invariants reset

#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset

#pragma opt_common_subs reset
