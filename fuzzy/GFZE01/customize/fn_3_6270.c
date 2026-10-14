/* Non-matching: best partial attempt (91.85% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/globals.h"

struct fn_3_6270_state {
    u8 pad_0[8];
    u32 unk_8;
    u8 pad_C[0xE4];
    u32 unk_F0;
    u8 pad_F4[0x2C];
    u32 unk_120;
};
struct fn_3_6270_lbl_1_bss_6EAB4 {
    u8 lab_pad[4]; u32 unk_0; };
extern struct fn_3_6270_lbl_1_bss_6EAB4 lbl_1_bss_6EAB4;
extern int fn_1_4C10(void);
extern u16 lbl_1_bss_96A;
extern u32 lbl_1_bss_9F8;
extern u32 lbl_3_data_B4;
extern u32 lbl_801A66A8;
extern void fn_1_1280(u32);
extern void fn_1_4A00(s32, u8, void *);
extern void fn_1_A2D84(u32);
extern void fn_3_679C(void);

#pragma opt_propagation off
#pragma opt_common_subs off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_3_bss_0[2];
u32 lbl_3_bss_8;
u32 lbl_3_bss_C[3];
u32 fzgx_obj_lbl_3_bss_18[2];
u32 fzgx_obj_lbl_3_bss_20[52];
u32 fzgx_obj_lbl_3_bss_F0;
u32 lbl_3_bss_F0_fill_F4[11];
u32 lbl_3_bss_120;
u32 lbl_3_bss_120_fill_124[7];
u32 lbl_3_bss_140_fill_140[32688];
u16 lbl_3_bss_140_1FEC0;
u8 lbl_3_bss_140_fill_20001;
u16 lbl_3_bss_140_fill_20002;
u32 lbl_3_bss_140_fill_20004[528];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_3_bss_0;
    s = *(u8 *)&lbl_3_bss_8;
    s = *(u8 *)&lbl_3_bss_C;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_18;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_20;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_F0;
    s = *(u8 *)&lbl_3_bss_F0_fill_F4;
    s = *(u8 *)&lbl_3_bss_120;
    s = *(u8 *)&lbl_3_bss_120_fill_124;
    s = *(u8 *)&lbl_3_bss_140_fill_140;
    s = *(u8 *)&lbl_3_bss_140_1FEC0;
    s = *(u8 *)&lbl_3_bss_140_fill_20001;
    s = *(u8 *)&lbl_3_bss_140_fill_20002;
    s = *(u8 *)&lbl_3_bss_140_fill_20004;
}
#pragma section code_type ".text"

void fn_3_6270(void) {
    s32 v8;
    s32 v10_2;
    u32 v1;
    int v2;
    u32 v3;
    u16 v4;
    s32 v5;
    u16 *v6;
    u8 *v0;
    s32 v10;
    s16 v12;
    u32 lab_t0;
    u32 lab_t0_;
    u16 * v6_2;
    
    v0 = (u8 *)&lbl_3_bss_140_1FEC0;
    fn_3_679C();
    if ((s32)lbl_3_bss_120 == -1) fn_1_4C10();
    v1 = *(u32 *)((u8 *)&fzgx_obj_lbl_3_bss_F0 + 36);
    if ((v1 & 0x80000000) != 0 && (v1 & 1) == 0 && (fzgx_obj_lbl_3_bss_F0 & 2) == 0) {
        v2 = 1;
    } else {
        if (fn_1_4C10() != 0) v2 = 1;
        else v2 = 0;
    }
    if (v2 == 0) {
        v3 = lbl_3_bss_120;
        if ((s32)v3 != -1) {
            lbl_3_bss_120 = -1;
            lbl_1_bss_96A = v3;
        } else {
            v10 = 0;
            v4 = *(s16 *)((u8 *)(u32)((u8 *)&fzgx_obj_lbl_3_bss_F0) + 6);
            v8 = v10;
            v5 = v4 * 20;
            v6 = (u16 *)((u8 *)&lbl_1_bss_9F8 + v5);
            v6 += 8;
            if (((*v6 >> 3) & 1) != 0 || ((*(u16 *)((u8 *)&lbl_1_bss_9F8 + v5 + 18) >> 3) & 1) != 0) {
                v8 = -1;
                lab_t0 = 0xA9010000;
                lab_t0_ = lab_t0;
                fn_1_A2D84(lab_t0_);
                lbl_801A66A8 = 0;
            }
            if (((*v6 >> 2) & 1) != 0 || ((*(u16 *)((u8 *)&lbl_1_bss_9F8 + v5 + 18) >> 2) & 1) != 0) {
                v8++;
                fn_1_A2D84(0xA9010000);
                lbl_801A66A8 = 0;
            }
            v2 = *(s16 *)(v0 + 2116) + (s16)v8;
            *(u16 *)(v0 + 2116) = v2 > 2 ? 0 : v2 < 0 ? 2 : v2;
            v6_2 = (u16 *)((u8 *)&lbl_1_bss_9F8 + v5);
            v6_2 += 4;
            if (((*v6_2 >> 9) & 1) != 0) {
                v10_2 = -1;
                fn_1_A2D84(0xA9010200);
            }
            if (((*v6_2 >> 8) & 1) != 0) {
                v10_2 = 1;
                fn_1_A2D84(0xA9010100);
            }
            if ((s16)v10_2 == -1) {
                if ((s32)lbl_3_bss_8 != 0) {
                    lbl_3_bss_120 = 93;
                    fn_1_1280(1);
                    lbl_3_data_B4 = 92;
                    v5 = (fzgx_obj_lbl_3_bss_F0 | 0x1000000);
                    fzgx_obj_lbl_3_bss_F0 = v5;
                } else {
                    fn_1_4A00(0, 15, (void *)*(u32 *)(v0 + 2128));
                    v2 = (*(u32 volatile *)&(lbl_1_bss_6EAB4.unk_0)) /* Retail reloads this field. */;
                    *(u32 *)(v0 + 17320) = 0;
                    v2 |= 36;
                    lbl_1_bss_6EAB4.unk_0 = v2;
                    lbl_3_bss_120 = 92;
                }
            } else if ((s16)v10_2 != 0) {
                v12 = *(s16 *)(v0 + 2116);
                switch (v12) {
                case 0:
                    fn_1_4A00(0, 15, (void *)*(u32 *)(v0 + 2128));
                    *(u32 *)(v0 + 17320) = 0;
                    lbl_3_bss_120 = 109;
                    break;
                case 1:
                    fn_1_4A00(0, 15, (void *)*(u32 *)(v0 + 2128));
                    *(u32 *)(v0 + 17320) = 0;
                    lbl_3_bss_120 = 103;
                    break;
                case 2:
                    fn_1_4A00(0, 15, (void *)*(u32 *)(v0 + 2128));
                    *(u32 *)(v0 + 17320) = 0;
                    lbl_3_bss_120 = 111;
                }
            }
        }
    }
}
#pragma opt_common_subs reset

