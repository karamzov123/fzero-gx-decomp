/* Non-matching: best partial attempt (91.52% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 state;
    u8 enabled;
    u8 applied;
    u8 flags;
    u8 pad[0x24];
    u32 value_28;
    u32 value_2c;
} Sig_fn_1_40710_Fn40710Object;

typedef struct {
    u8 pad_0[5];
    u8 unk_5;
    u8 pad_6[0xBE];
    u32 unk_C4;
    u8 pad_C8[0x1408];
} Fn_1_2C97C_Inner;

struct fn_1_2C97C_lbl_1_bss_3C00 {
    u8 pad_0[0x10];
    u8 unk_10;
    u8 pad_11[0xF];
    u8 unk_20;
    u8 pad_21[0x9];
    s16 unk_2A;
    u8 pad_2C[4];
    volatile Fn_1_2C97C_Inner unk_30;
    u32 unk_1500;
    s8 unk_1504;
    u8 pad_1505[3];
    volatile Sig_fn_1_40710_Fn40710Object unk_1508;
};

extern int fn_1_4C10(void);
extern void *fn_1_435C(void *);
extern s32 fn_1_3F8C(u32, u32, void *, u32);
extern struct fn_1_2C97C_lbl_1_bss_3C00 lbl_1_bss_3C00;
extern u16 lbl_1_bss_9F8[0x40][0xA];
extern u8 lbl_1_data_5F5C[0x10];
extern u32 fn_1_2C908(void);
extern u32 lbl_1_rodata_BD8;
extern void fn_1_49F0(u32 *);
extern void fn_1_4A00(s32, u8, void *);
extern void *fn_1_86254(int);
extern u8 fn_1_86624(void);
extern void fn_1_40710(Sig_fn_1_40710_Fn40710Object *);

#pragma opt_lifetimes on
#pragma opt_common_subs off
int fn_1_2C97C(void) {
    struct fn_1_2C97C_lbl_1_bss_3C00 *p_lbl_1_bss_3C00;
    volatile Sig_fn_1_40710_Fn40710Object *obj;
    u32 idx;
    u16 w10;
    s16 w12;
    u16 w8;
    s32 f4;
    s32 f5;
    s16 v;
    s16 i;
    u32 loc_8;
    u8 fl;

    p_lbl_1_bss_3C00 = &lbl_1_bss_3C00;
    if (fn_1_4C10() != 0) {
        return 4;
    }
    obj = &p_lbl_1_bss_3C00->unk_1508;
    if ((obj->flags & 1) != 0) {
        idx = p_lbl_1_bss_3C00->unk_20;
        w10 = lbl_1_bss_9F8[idx][8];
        if (((w10 & 1) != 0) || (((w12 = lbl_1_bss_9F8[idx][9]) & 1) != 0)) {
            p_lbl_1_bss_3C00->unk_1508.enabled = 0;
            return 0;
        }
        if (((w10 >> 1) & 1) != 0 || ((w12 >> 1) & 1) != 0) {
            p_lbl_1_bss_3C00->unk_1508.enabled = 1;
            return 0;
        }
        f4 = 0;
        w8 = lbl_1_bss_9F8[idx][4];
        f5 = 0;
        if (((w8 >> 9) & 1) != 0 || ((w8 >> 12) & 1) != 0) {
            f4 = 1;
        } else if (((w8 >> 8) & 1) != 0) {
            if (obj->enabled == 0) {
                f5 = 1;
            } else {
                f4 = 1;
            }
        }
        if (f4 != 0 || f5 != 0) {
            if (f4 != 0) {
                obj->flags |= 4;
            } else if (f5 != 0) {
                fl = obj->flags;
                obj->flags = fl | 2;
                if (p_lbl_1_bss_3C00->unk_2A == 41) {
                    fn_1_435C((void *)p_lbl_1_bss_3C00->unk_1500);
                    fn_1_3F8C((u32)&lbl_1_data_5F5C, (u32)fn_1_2C908, 0, 13);
                    loc_8 = lbl_1_rodata_BD8;
                    fn_1_49F0(&loc_8);
                    if (p_lbl_1_bss_3C00->unk_10 != 0) {
                        fn_1_4A00(0, 0x78, (void *)p_lbl_1_bss_3C00->unk_1500);
                    } else {
                        fn_1_4A00(0, 0x1E, (void *)p_lbl_1_bss_3C00->unk_1500);
                    }
                    if (p_lbl_1_bss_3C00->unk_30.unk_5 == 1) {
                        v = 0;
                        *(u8 *)((u8 *)fn_1_86254(0) + 0x475) = v;
{
    s16 fzgx_loop_i_3492;
                        fzgx_loop_i_3492 = 1;
                        v = -1;
                        while (fzgx_loop_i_3492 < (s8)fn_1_86624()) {
                            *(u8 *)((u8 *)fn_1_86254(fzgx_loop_i_3492) + 0x475) = v;
                            fzgx_loop_i_3492++;
                        }
    i = fzgx_loop_i_3492;
}
                    }
                }
            }
            p_lbl_1_bss_3C00->unk_1504 = -1;
            p_lbl_1_bss_3C00->unk_30.unk_C4 = 0;
        }
        fn_1_40710((Sig_fn_1_40710_Fn40710Object *)&p_lbl_1_bss_3C00->unk_1508);
        return 4;
    }
    return 0;
}
#pragma opt_common_subs reset

#pragma opt_lifetimes reset
