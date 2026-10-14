/* Non-matching: best partial attempt (79.11% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/memcard.h"
typedef struct {
    u32 unk_0[9];
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
} C1394Entry;
typedef struct { u32 unk_0; u32 unk_4; } C1394Pair;
struct fn_1_C1394_lbl_1_bss_716C0 {
    u8 pad_0[0x1F4];
    s32 unk_1F4;
    u8 unk_1F8;
};
struct fn_1_C1394_arg {
    u8 pad_0[5];
    u8 unk_5;
    u8 pad_6[14];
    s8 unk_14;
    u8 pad_15;
    s16 unk_16, unk_18, unk_1A, unk_1C;
    u8 unk_1E, unk_1F;
    u8 pad_20[2];
    u8 unk_22;
    u8 pad_23[25];
    volatile u8 unk_3C;
    u8 unk_3D;
};
extern u32 lbl_801A6410;
extern void OSReport(const char *, ...);
extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_1_C17CC(void *, void *, void *);
extern u32 fn_1_C17D0(u32, void *, void *);
extern void fn_1_C1ACC(void *, void *, void *);
extern u32 fn_1_BB974(void *);

void fn_1_C1394(void *arg0) {
    struct fn_1_C1394_arg *arg = arg0;
    struct fn_1_C1394_lbl_1_bss_716C0 *p_lbl_1_bss_716C0 = (void *)&lbl_1_bss_716C0;
    u8 *v1 = (u8 *)p_lbl_1_bss_716C0 + 0x10000;
    C1394Entry *v2;
    C1394Entry *v5;
    C1394Entry loc_10;
    C1394Pair loc_8;
    int loc_40;
    int v16, v20, v21, v30;
    C1394Entry *v14;
    C1394Entry *v12;
    C1394Pair *v13;
    if (arg->unk_16 != -1 && arg->unk_18 != -1)
        v2 = (void *)((u8 *)p_lbl_1_bss_716C0 + 0x5CC0 + arg->unk_16 * 0x1800 + arg->unk_18 * 0x30);
    else v2 = 0;
    if (arg->unk_1A != -1 && arg->unk_1C != -1)
        v5 = (void *)((u8 *)p_lbl_1_bss_716C0 + 0x5CC0 + arg->unk_1A * 0x1800 + arg->unk_1C * 0x30);
    else v5 = 0;
    arg->unk_16 = arg->unk_1A;
    arg->unk_18 = 0;
    arg->unk_1A = -1;
    arg->unk_1C = -1;
    arg->unk_22 = 3;
    if (*(u32 *)(v1 - 0x7340)) {
        fn_1_46B4(lbl_801A6410, *(u32 *)(v1 - 0x7340), (const char *)&lbl_1_data_3C7B8, 0x3291);
        *(u32 *)(v1 - 0x7340) = 0;
    }
    if (p_lbl_1_bss_716C0->unk_1F8 == 0) {
        OSReport((const char *)lbl_1_data_3D108, p_lbl_1_bss_716C0->unk_1F4);
        if (p_lbl_1_bss_716C0->unk_1F4 == -123) {
            v14 = (void *)((u8 *)p_lbl_1_bss_716C0 + 0x5CC0 + arg->unk_16 * 0x1800);
            for (v16 = 0; v16 < 127; v16++) {
                if (v14[v16].unk_2C) fn_1_46B4(lbl_801A6410, v14[v16].unk_2C, (const char *)&lbl_1_data_3C7B8, 0x2776);
                *((u8 *)&v14[v16] + 1) = 0;
                *((u8 *)&v14[v16] + 2) = 0;
                v14[v16].unk_24 = 0;
                v14[v16].unk_28 = 0;
                v14[v16].unk_2C = 0;
            }
            arg->unk_5 &= ~(1 << arg->unk_16);
            if (arg->unk_16 == 0) arg->unk_1E = 0;
            if (arg->unk_16 == 1) arg->unk_1F = 0;
        }
    } else {
        switch (arg->unk_14) {
        case 1: fn_1_C17CC(arg, v2, v5); break;
        case 2: case 3: break;
        case 4: fn_1_C17D0((u32)arg, v2, v5); break;
        case 8: fn_1_C1ACC(arg, v2, v5); break;
        }
        arg->unk_3C = 0;
        arg->unk_3D = 0;
        loc_40 = 0;
        if (arg->unk_3C != 1) {
            fn_1_BB974(arg);
        } else {
            v12 = (void *)((u8 *)p_lbl_1_bss_716C0 + 0x5CC0);
            v13 = (void *)(v1 - 0x7324);
            do {
                v20 = 0;
                for (v16 = 0; v16 < 127; v16++)
                    if (v12[v16].unk_24 != 0) v20++;
                for (v21 = 0; v21 < v20 - 1; v21++) {
                    for (v30 = v21 + 1; v30 < v20; v30++) {
                        if (v12[v21].unk_28 > v12[v30].unk_28) {
                            loc_10 = v12[v21];
                            loc_8 = v13[v21];
                            v12[v21] = v12[v30];
                            v13[v21] = v13[v30];
                            v12[v30] = loc_10;
                            v13[v30] = loc_8;
                        }
                    }
                }
                v13 = (void *)((u8 *)v13 + 0x3F8);
                v12 = (void *)((u8 *)v12 + 0x1800);
                loc_40++;
            } while (loc_40 < 2);
        }
    }
}
