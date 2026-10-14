/* Non-matching: best partial attempt (80.21% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
typedef struct Sig_fn_8006F038_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Sig_fn_8006F038_Vec3;
struct Sig_fn_1_9F4B4_fn_1_9F4B4_Arg0 {
    u8 pad_0[0xC];
    f32 unk_C;
    s16 unk_10;
    u16 unk_12;
    u32 unk_14;
};

struct fn_3_2C290_bss {
    u8 pad_0[0x34];
    s16 unk_34;
    u8 pad_36[0x2];
    u32 unk_38[2];
    u32 unk_40;
    u32 unk_44[2];
};
struct fn_3_2C290_ro {
    f32 unk_0;
    u8 pad_4[0x94];
    f64 unk_98;
    u8 pad_A0[0xE8];
    f32 unk_188;
    f32 unk_18C;
    u8 pad_190[0x40];
    f32 unk_1D0;
    u8 pad_1D4[0x24];
    f64 unk_1F8;
    u8 pad_200[0x28];
    f32 unk_228;
    u8 pad_22C[0xD4];
    f32 unk_300;
    u8 pad_304[0xCC];
    f32 unk_3D0;
};
struct fn_3_2C290_data {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
};
struct fn_3_2C290_bss38460 {
    u8 pad_0[0xC];
    u32 unk_C;
};
struct fn_3_2C290_frame {
    f32 loc_8[3];
    struct { u32 a[13]; } loc_14;
    struct { u32 a[12]; } loc_48;
};

extern f32 lbl_8006D188(u32);
extern struct fn_3_2C290_bss38460 lbl_1_bss_38460;
extern struct fn_3_2C290_data lbl_1_data_1E5C0;
extern struct fn_3_2C290_bss lbl_3_bss_A2460;
extern struct fn_3_2C290_ro lbl_3_rodata_768;
extern u32 lbl_801A66A0;
extern struct { u32 unk_0; } lbl_801A6D00;
extern u32 fn_1_14E2DC(u32, u32, f32);
extern u32 fn_1_56018(s32);
extern u32 fn_1_870BC(u32, u32, u32, u32, u32, f32);
extern u32 lbl_8006DB74(u32);
extern u32 lbl_8006DBAC(u32);
extern u32 lbl_8006DCA4(void);
extern u32 lbl_8006E0A4(struct Sig_fn_1_9F4B4_fn_1_9F4B4_Arg0 *);
extern u32 mathutil_mtxA_rotate_y(u32);
extern void fn_1_55210(void *);
extern void fn_1_560F0(s32, void *);
extern void fn_1_F7870(u32);
extern void fn_1_FCFA4(void *);
extern void fn_8006F038(Sig_fn_8006F038_Vec3 *, Sig_fn_8006F038_Vec3 *, s16);
extern void fn_80072558(void);
extern void fn_80077B04(f32);
extern void lbl_8006D784(u32);
extern void lbl_8006DCDC(void);

void fn_3_2C290(void *arg0) {
    struct fn_3_2C290_frame fr;
    u32 v0;
    s16 i;
    void *node;
    struct fn_3_2C290_bss *pB;
    struct fn_3_2C290_ro *pR;
    struct fn_3_2C290_data *pD;
    f32 ang;
    f32 a;
    f32 b;
    u32 tick;
    v0 = *(u32 *)arg0;
    pB = (struct fn_3_2C290_bss *)&lbl_3_bss_A2460;
    pR = (struct fn_3_2C290_ro *)&lbl_3_rodata_768;
    fn_8006F038((Sig_fn_8006F038_Vec3 *)((u8 *)pB + 0x38), (Sig_fn_8006F038_Vec3 *)((u8 *)pB + 0x44), 0);
    lbl_8006DCDC();
    pD = (struct fn_3_2C290_data *)&lbl_1_data_1E5C0;
    a = pD->unk_C * pR->unk_0;
    b = pD->unk_10 * pR->unk_0;
    fr.loc_14.a[3] = *(u32 *)&pD->unk_C;
    fr.loc_14.a[4] = *(u32 *)&pD->unk_10;
    fr.loc_14.a[5] = *(u32 *)&pD->unk_14;
    *(f32 *)((u8 *)&fr.loc_14 + 0xC) = a - b;
    *(f32 *)((u8 *)&fr.loc_14 + 0x10) = a + b;
    *(f32 *)((u8 *)&fr.loc_14 + 0x14) = pD->unk_14;
    fr.loc_14.a[0] = pD->unk_0;
    fr.loc_14.a[1] = pD->unk_4;
    fr.loc_14.a[2] = pD->unk_8;
    fr.loc_14.a[6] = pD->unk_18;
    fr.loc_14.a[7] = pD->unk_1C;
    fr.loc_14.a[8] = pD->unk_20;
    fr.loc_14.a[9] = pD->unk_24;
    fr.loc_14.a[10] = pD->unk_28;
    fr.loc_14.a[11] = pD->unk_2C;
    fr.loc_14.a[12] = pD->unk_30;
    fn_1_F7870((u32)&fr.loc_14);
    fr.loc_8[1] = pR->unk_1D0;
    ang = pR->unk_228 * (f32)(u32)(0x8000 - 360 * (0xB60B60B7 * 0 / 256));
    lbl_8006D188((u32)(s32)ang);
    ang = -pR->unk_300;
    fr.loc_8[0] = ang * (f32)(u32)(0x8000 - 360 * (0xB60B60B7 * 0 / 256));
    lbl_8006D188((u32)(s16)((s32)ang + 16384));
    fr.loc_8[2] = ang * (f32)(u32)(0x8000 - 360 * (0xB60B60B7 * 0 / 256));
    lbl_8006DCA4();
    fr.loc_8[1] = fr.loc_8[1] - pR->unk_18C;
    lbl_8006E0A4((struct Sig_fn_1_9F4B4_fn_1_9F4B4_Arg0 *)fr.loc_8);
    tick = *(u32 *)&lbl_801A66A0;
    mathutil_mtxA_rotate_y((u32)(s32)(pR->unk_228 * (f32)(u32)(360 - (tick % 360))));
    {
        s32 c;
        c = -pB->unk_34;
        if (c < 0) {
            c = 0;
        } else if (c > 15) {
            c = 15;
        }
        fn_80077B04(pR->unk_188 - (f32)(u32)(0x8000 | c) / pR->unk_3D0);
    }
    if (pB->unk_34 >= -1) {
        node = *(void **)(*(u32 *)((u8 *)lbl_1_bss_38460.unk_C + 8));
        {
            u32 *el = (u32 *)((u8 *)node + 0x40);
            for (i = 0; i < (s32)*(u16 *)((u8 *)node + 0x18); i++) {
                if ((el[i * 8] & 0x20000) != 0) {
                    fn_1_56018(1);
                    lbl_8006D784(*(u32 *)&lbl_801A6D00 + 0x60);
                    ang = pR->unk_228 * (f32)(u32)(*(u32 *)&lbl_801A66A0 % 180);
                    ang = lbl_8006D188((u32)(s16)((s32)ang + 16384));
                    *(f32 *)((u8 *)lbl_801A6D00.unk_0 + 0x6C) = pR->unk_188 - ang;
                    fn_1_560F0(0, (void *)(lbl_801A6D00.unk_0 + 0x60));
                }
            }
        }
        fn_80072558();
        fn_1_55210(node);
    }
    fn_80077B04(pR->unk_188);
    lbl_8006DCA4();
    lbl_8006E0A4((struct Sig_fn_1_9F4B4_fn_1_9F4B4_Arg0 *)fr.loc_8);
    if ((*(u32 *)((u8 *)v0 + 0x390) & 0x4000000) != 0) {
        mathutil_mtxA_rotate_y((u32)(s32)(pR->unk_228 * (f32)(u32)(360 - (*(u32 *)&lbl_801A66A0 % 360))));
        lbl_8006DB74((u32)&fr.loc_48);
        fn_1_14E2DC(*(u32 *)((u8 *)v0 + 0x3A0), 0, pR->unk_188);
        lbl_8006DBAC((u32)&fr.loc_48);
        fn_1_FCFA4(arg0);
    } else {
        mathutil_mtxA_rotate_y((u32)(s32)(pR->unk_228 * (f32)(u32)(360 - (*(u32 *)&lbl_801A66A0 % 360))));
        fn_1_870BC(v0, 0, v0, 0, 4, pR->unk_188);
        fn_1_FCFA4(arg0);
    }
}
