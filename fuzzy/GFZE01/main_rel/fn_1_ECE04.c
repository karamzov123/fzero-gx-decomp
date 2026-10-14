/* Non-matching: best partial attempt (94.89% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/phys.h"

extern void *fn_1_8627C(s32 arg);
extern const f32 lbl_1_rodata_6B60;
extern s32 fn_1_F2F34(void);
extern u32 fn_1_ECF88(void);
extern const f32 lbl_1_rodata_6C90;
extern void fn_1_98634(f32 arg);
extern void fn_1_983CC(void *dst, u32 src);

typedef struct {
    u32 unk_00[0x16E4 / 4];
    u32 unk_16E4;
    u32 unk_16E8;
    u32 unk_16EC[0x60 / 4];
    u8 unk_174C;
    u8 unk_174D;
    u8 unk_174E;
    u8 unk_174F[0x1794 - 0x174F];
    u32 unk_1794[5];
    u32 unk_17A8[13];
    s32 unk_17DC[17];
    u32 unk_1820;
    u32 unk_1824[(0x19C8 - 0x1824) / 4];
    u8 unk_19C8[5][0x620];
    u8 unk_3868[0x3894 - 0x3868];
    u32 unk_3894;
    void *unk_3898;
    f32 unk_389C;
    f32 unk_38A0;
    u8 unk_38A4;
    u8 unk_38A5;
    u8 unk_38A6;
    u8 unk_38A7;
    u32 unk_38A8;
    u32 unk_38AC;
    u32 unk_38B0;
    u32 unk_38B4;
    u32 unk_38B8;
} FzGlobal;

void fn_1_ECE04(void)
{
    FzGlobal *g = (FzGlobal *)&lbl_1_bss_7B180;

    g->unk_3894 = 0;
    g->unk_174C = 0;
    g->unk_174D = 0;
    g->unk_3898 = fn_1_8627C(0);
    g->unk_38A4 = 0;
    g->unk_389C = lbl_1_rodata_6B60;
    g->unk_38A0 = lbl_1_rodata_6B60;
    g->unk_38A5 = 0;
    g->unk_38A6 = 0;
    g->unk_38A8 = 0;

    if (fn_1_F2F34() == 0) {
        u32 v0 = g->unk_16E4;
        u32 v1 = g->unk_16E8;

        g->unk_1820 = 0;
        g->unk_38AC = v0;
        g->unk_38B0 = v1;
        g->unk_00[3] = 0;
        g->unk_00[0] = 0;
        g->unk_00[5] = 0;
        fn_1_ECF88();
        g->unk_38B4 = 0;
        lbl_1_data_3E530 = 2;
        g->unk_38B8 = 0;
    } else {
        lbl_1_data_3E530 = 3;
    }

    {
        s32 *flags = &g->unk_17DC[0];
        u32 *tableA = &g->unk_1794[0];
        u8 *entries = &g->unk_19C8[0][0];
        u32 *tableB = &g->unk_17A8[0];
        u32 i;

        for (i = 0; i < (u32)g->unk_174E; i++) {
        if (flags[i] == 0) {
            fn_1_98634(lbl_1_rodata_6C90);
            fn_1_983CC(&entries[i * 0x620], tableA[i]);
            fn_1_98634(lbl_1_rodata_6B60);
        } else {
            fn_1_98634(lbl_1_rodata_6C90);
            fn_1_983CC(&entries[i * 0x620], tableB[i] + 0x6E0);
            fn_1_98634(lbl_1_rodata_6B60);
        }
    }
    }
}
