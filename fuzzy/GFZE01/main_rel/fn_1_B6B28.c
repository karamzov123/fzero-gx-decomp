/* Non-matching: best partial attempt (0.00% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_1_B6B28_lbl_1_rodata_4AE0 {
    u8 pad_0[0x1C8];
    f32 unk_1C8;
    u8 pad_1CC[0x4];
    f64 unk_1D0;
    u8 pad_1D8[0x8];
    f32 unk_1E0;
    u8 pad_1E4[0x20];
    f32 unk_204;
    u8 pad_208[0x28];
    f32 unk_230;
    f32 unk_234;
    f32 unk_238;
    f32 unk_23C;
    f32 unk_240;
    f32 unk_244;
    u8 pad_248[0x8];
    f32 unk_250;
    u8 pad_254[0xA8];
    f32 unk_2FC;
    u8 pad_300[0x48];
    f32 unk_348;
    u8 pad_34C[0x34];
    f32 unk_380;
    f32 unk_384;
    u8 pad_388[0x8];
    u32 unk_390;
    u32 unk_394;
    u32 unk_398;
    u32 unk_39C;
    u32 unk_3A0;
    u32 unk_3A4;
    u32 unk_3A8;
    f32 unk_3AC;
    f32 unk_3B0;
    f32 unk_3B4;
    f32 unk_3B8;
    f32 unk_3BC;
    f32 unk_3C0;
    f32 unk_3C4;
    f32 unk_3C8;
    f32 unk_3CC;
    f32 unk_3D0;
};
struct fn_1_B6B28_lbl_1_data_35AC8 {
    u8 pad_0[0x5FFC];
    u32 unk_5FFC[1];
    u8 pad_6000[0x14];
    u32 unk_6014[1];
    u8 pad_6018[0x704];
    u32 unk_671C;
};
struct fn_1_B6B28_lbl_1_bss_716C0 {
    u8 pad_0[0x148];
    u32 unk_148;
    u8 pad_14C[0xA5];
    u8 unk_1F1;
    u8 unk_1F2;
    u8 pad_1F3[0x5A0D];
    u32 unk_5C00;
    u8 pad_5C04[0x58];
    u32 unk_5C5C;
    u32 unk_5C60;
    u32 unk_5C64;
    u32 unk_5C68;
};
struct fn_1_B6B28_lbl_801A66B4 {
    u32 unk_0;
};

extern f32 fn_1_B7C00(void);
extern int sprintf(char *, const char *, ...);
extern s16 lbl_1_bss_960;
extern s32 fn_1_4B16C(s32);
extern struct fn_1_B6B28_lbl_1_bss_716C0 lbl_1_bss_716C0;
extern struct fn_1_B6B28_lbl_1_data_35AC8 lbl_1_data_35AC8;
extern struct fn_1_B6B28_lbl_1_rodata_4AE0 lbl_1_rodata_4AE0;
extern struct fn_1_B6B28_lbl_801A66B4 lbl_801A66B4;
extern u32 fn_1_4AEC0(u32);
extern u32 fn_1_B5310(void);
extern u32 fn_1_B5654(void);
extern u32 fn_1_B5A3C(void);
extern u32 fn_1_B5F20(void);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_49514(u32 *);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495A0(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_49614(void);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4AEB4(f32);
extern void fn_1_4D0A0(void);
extern void fn_1_4D274(u32 *, f32);
extern void fn_1_4FD64(f32);
extern void fn_1_54278(u32, u32);
extern void fn_1_5428C(f32);
extern void fn_1_A2DC4(u32);
extern void fn_1_B5258(char *, void *, const char *, const char *);

void fn_1_B6B28(u32 arg0) {
    struct fn_1_B6B28_lbl_1_rodata_4AE0 *p_lbl_1_rodata_4AE0;
    struct fn_1_B6B28_lbl_1_data_35AC8 *p_lbl_1_data_35AC8;
    struct fn_1_B6B28_lbl_1_bss_716C0 *p_lbl_1_bss_716C0;
    u32 unk_1;
    u32 v1;
    u8 v2;
    u32 v3;
    f32 v4;
    s32 v5;
    u32 v6;
    u32 v7;
    f32 v8;
    f32 v9;
    f32 v10;
    u32 v11;
    u32 v12;
    u32 v13;
    s32 v14;
    u32 v15;
    s32 v16;
    s32 v17;
    s32 v18;
    u32 v19;
    u32 v20;
    s32 v21;
    void * v22;
    void * v23;
    void * v24;
    u32 v25;
    void * v26;
    u32 v27;
    f32 v28;
    f32 v29;
    f32 v30;
    u32 v31;
    u32 v32;
    s32 v33;
    u32 v34;
    u32 v35;
    u32 v36;
    f32 v37;
    f32 v38;
    f32 v39;
    u32 v40;
    u32 v41;
    s32 v42;
    u32 v43;
    u32 v44;
    u8 v45;
    u32 v46;
    f32 v47;
    f32 v48;
    f32 v49;
    u32 v50;
    u32 v51;
    s32 v52;
    u32 v53;
    u32 v54;
    s16 v55;
    s32 v56;
    s32 v57;
    u32 v58;
    s16 v59;
    u32 v60;
    u32 v61;
    u32 v62;
    s16 v63;
    void * v64;
    u32 v65;
    f32 v66;
    f32 v67;
    f32 v68;
    u32 v69;
    u32 v70;
    s32 v71;
    u32 v72;
    u32 v73;
    void * v74;
    u32 v75;
    u32 v76;
    u32 v77;
    void * v78;
    void * v79;
    u32 v80;
    u32 v81;
    u32 v82;
    u32 v83;
    void * v84;
    u32 v85;
    void * v86;
    void * v87;
    void * v88;
    void * v89;
    void * v90;
    void * v91;
    u32 v92;
    struct { u8 a[1]; } loc_470;
    struct { u32 a[256]; } loc_70;
    struct { u32 a[4]; } loc_60;
    struct { u32 a[4]; } loc_50;
    u32 loc_44[3];
    u32 loc_3C[2];
    u32 loc_34[2];
    u32 loc_30;
    u32 loc_2C;
    u32 loc_28;
    u32 loc_24;
    u32 loc_20;
    u32 loc_1C;
    u32 loc_18;
    u8 loc_17;
    u32 loc_14;
    u8 loc_13;
    u32 loc_10;
    u8 loc_F;
    u32 loc_C;
    u8 loc_B;
    u32 loc_8;
    /* frame */
    f32 t0;
    u32 t14;
    f32 t18;
    f32 t30;
    f32 t31;
    f32 t40;
    u32 t43;
    f32 t52;
    u32 t61;
    f32 t70;
    u32 t73;
    f32 t82;
    int t100;
    int t102;
    int t104;
    s32 t112;
    u32 t127;
    /* 1 instruction(s) not lifted: see the ??? markers */
    p_lbl_1_rodata_4AE0 = (struct fn_1_B6B28_lbl_1_rodata_4AE0 *)&lbl_1_rodata_4AE0;
    p_lbl_1_data_35AC8 = (struct fn_1_B6B28_lbl_1_data_35AC8 *)&lbl_1_data_35AC8;
    p_lbl_1_bss_716C0 = (struct fn_1_B6B28_lbl_1_bss_716C0 *)&lbl_1_bss_716C0;
    if (lbl_1_bss_960 == 9) {
    t0 = fn_1_B7C00();
    /* ??? clrlwi. r0, r3, 24 (r3 read after it was clobbered) */
    if (lbl_1_bss_960 != 9) {
    fn_1_4FD64(t0);
    }
    }
    v1 = p_lbl_1_bss_716C0->unk_148;
    p_lbl_1_bss_716C0->unk_148 = (v1 + 1);
    fn_1_4D0A0();
    fn_1_4AEC0(1);
    fn_1_4AEB4(p_lbl_1_rodata_4AE0->unk_3AC);
    v2 = p_lbl_1_bss_716C0->unk_1F1;
    if (v2 != 5) {
    v5 = (v2 * 160);
    v3 = (u32)((u8 *)((u8 *)(u32)p_lbl_1_bss_716C0 + 8) + v5);
    v6 = *(u32 *)((u8 *)v3 + 36);
    if (v6 != 0) {
    if ((*(u32 *)((u8 *)v6 + 8) & 0x2000) != 0 && *(u8 *)((u8 *)v3 + 4) != 1 && *(u8 *)((u8 *)v3 + 4) != 5 && *(u8 *)((u8 *)v3 + 4) != 2) {
    v3 = 0;
    fn_1_54278(v3, 0);
    v4 = p_lbl_1_rodata_4AE0->unk_1E0;
    fn_1_5428C(v4);
    } else {
    v3 = (u32)((u8 *)((u8 *)(u32)p_lbl_1_bss_716C0 + 8) + v5);
    if ((*(u32 *)((u8 *)v6 + 8) & 0x8000) != 0 && *(u8 *)((u8 *)v3 + 4) == 1) {
    v3 = 0;
    fn_1_54278(v3, 0);
    v4 = p_lbl_1_rodata_4AE0->unk_1E0;
    fn_1_5428C(v4);
    } else {
    }
    }
    } else {
    }
    } else {
    if (p_lbl_1_bss_716C0->unk_1F2 != 255 && p_lbl_1_bss_716C0->unk_1F2 != 2) {
    v7 = p_lbl_1_bss_716C0->unk_5C5C;
    if ((s32)v7 <= 10) {
    if ((s32)v7 == 0) {
    v3 = 0xA9010000;
    v3 += 1536;
    fn_1_A2DC4(v3);
    }
    v3 = p_lbl_1_bss_716C0->unk_5C5C;
    v8 = p_lbl_1_rodata_4AE0->unk_204;
    v4 = p_lbl_1_rodata_4AE0->unk_1E0;
    v9 = (f32)(s32)v3;
    v10 = (f32)(v9 / v8);
    v4 = (f32)(v4 - v10);
    v3 = (s32)(f32)((f32)(p_lbl_1_rodata_4AE0->unk_244 * v4) * v4);
    fn_1_54278(v3, 0);
    v4 = (f32)(v10 * v10);
    fn_1_5428C(v4);
    } else {
    v3 = 0;
    fn_1_54278(v3, 0);
    v4 = p_lbl_1_rodata_4AE0->unk_1E0;
    fn_1_5428C(v4);
    }
    v11 = p_lbl_1_bss_716C0->unk_5C5C;
    v3 = v11;
    p_lbl_1_bss_716C0->unk_5C5C = (v3 + 1);
    t14 = fn_1_B5310();
    v3 = t14;
    v12 = p_lbl_1_rodata_4AE0->unk_390;
    v4 = p_lbl_1_rodata_4AE0->unk_3B0;
    v3 = (u32)&loc_30;
    loc_34[0] = v12;
    *(u8 *)((u8 *)loc_34 + 3) = 255;
    loc_30 = loc_34[0];
    fn_1_4D274((u32 *)v3, v4);
    v3 = 0;
    fn_1_54278(v3, 0);
    v4 = p_lbl_1_rodata_4AE0->unk_1E0;
    fn_1_5428C(v4);
    } else {
    p_lbl_1_bss_716C0->unk_5C5C = 0;
    t18 = fn_1_B7C00();
    v4 = t18;
    v13 = (v3 & 0xFF);
    v14 = 0;
    if ((v3 & 0x1) != 0) {
    v3 = (u32)((u8 *)(u32)p_lbl_1_bss_716C0 + 8);
    if (*(u8 *)((u8 *)v3 + 2) == 2) {
    v3 = *(u8 *)((u8 *)v3 + 42);
    if ((v3 & 0x8) == 0 && (v3 & 0x4) == 0) {
    v14 = (v14 | 1);
    } else {
    if ((*(u8 *)((u8 *)v3 + 42) & 0x4) == 0) {
    v14 = (v14 | 1);
    }
    }
    }
    }
    v15 = v14;
    if ((v13 & 0x2) != 0) {
    v3 = (u32)((u8 *)(u32)p_lbl_1_bss_716C0 + 8);
    if (*(u8 *)((u8 *)v3 + 162) == 2) {
    v3 = *(u8 *)((u8 *)v3 + 202);
    if ((v3 & 0x8) == 0 && (v3 & 0x4) == 0) {
    v15 = (v15 | 1);
    } else {
    if ((*(u8 *)((u8 *)v3 + 202) & 0x4) == 0) {
    v15 = (v15 | 1);
    }
    }
    }
    }
    if ((s32)v15 != 0) {
    fn_1_49410();
    v3 = 42;
    fn_1_494DC(v3);
    v3 = 9;
    fn_1_495C8(v3);
    v3 = (u32)&loc_2C;
    loc_2C = p_lbl_1_rodata_4AE0->unk_394;
    fn_1_49514((u32 *)v3);
    v4 = p_lbl_1_rodata_4AE0->unk_2FC;
    fn_1_4954C(v4);
    fn_1_49614();
    v4 = p_lbl_1_rodata_4AE0->unk_230;
    fn_1_4955C(v4, v4);
    v4 = p_lbl_1_rodata_4AE0->unk_234;
    fn_1_4966C(v4, p_lbl_1_rodata_4AE0->unk_238);
    if ((s32)lbl_801A66B4.unk_0 != 5) {
    v3 = 0x80000000;
    fn_1_495B0(v3);
    v4 = p_lbl_1_rodata_4AE0->unk_23C;
    fn_1_49590(v4);
    v4 = p_lbl_1_rodata_4AE0->unk_234;
    fn_1_4966C(v4, p_lbl_1_rodata_4AE0->unk_240);
    }
    t30 = fn_1_B7C00();
    v4 = t30;
    v3 = (v3 & 0xFF);
    v16 = 0;
    v17 = 79;
    if ((v3 & 0x1) != 0) {
    v3 = (u32)((u8 *)(u32)p_lbl_1_bss_716C0 + 8);
    if (*(u8 *)((u8 *)v3 + 2) == 2 && ((s32)*(u8 *)((u8 *)v3 + 4) != 22 && ((s32)*(u8 *)((u8 *)v3 + 4) >= 22 || (s32)*(u8 *)((u8 *)v3 + 4) >= 7 || (s32)*(u8 *)((u8 *)v3 + 4) < 5))) {
    v16 = 1;
    }
    v3 = (u32)((u8 *)(u32)p_lbl_1_bss_716C0 + 8);
    v3 = *(u32 *)((u8 *)v3 + 36);
    if (v3 != 0) {
    v3 = *(u32 *)((u8 *)v3 + 140);
    v17 = *(u8 *)((u8 *)v3 + 63);
    } else {
    if ((v3 & 0x2) != 0) {
    v3 = (u32)((u8 *)(u32)p_lbl_1_bss_716C0 + 8);
    if (*(u8 *)((u8 *)v3 + 162) == 2 && ((s32)*(u8 *)((u8 *)v3 + 4) != 22 && ((s32)*(u8 *)((u8 *)v3 + 4) >= 22 || (s32)*(u8 *)((u8 *)v3 + 4) >= 7 || (s32)*(u8 *)((u8 *)v3 + 4) < 5))) {
    v16 = 1;
    }
    v3 = (u32)((u8 *)(u32)p_lbl_1_bss_716C0 + 8);
    v3 = *(u32 *)((u8 *)v3 + 196);
    if (v3 != 0) {
    v3 = *(u32 *)((u8 *)v3 + 140);
    v17 = *(u8 *)((u8 *)v3 + 63);
    }
    }
    }
    }
    v18 = 71;
    if (v16 != 0) {
    v18 = 70;
    }
    t31 = fn_1_B7C00();
    v4 = t31;
    v19 = (v3 & 0x1);
    v20 = (v3 & 0xFF);
    v21 = v18;
    if ((v3 & 0x1) != 0) {
    v22 = (void *)(((u8 *)(u32)p_lbl_1_bss_716C0 + 8));
    v3 = *(u32 *)((u8 *)v22 + 36);
    if (*(u8 *)((u8 *)v3 + 0) == 4 && *(u8 *)((u8 *)v22 + 2) == 0 && *(u8 *)((u8 *)v22 + 4) == 11) {
    v21 = -1;
    } else {
    v23 = (void *)(((u8 *)(u32)p_lbl_1_bss_716C0 + 8));
    v3 = *(u32 *)((u8 *)v23 + 196);
    if ((v20 & 0x2) != 0 && *(u8 *)((u8 *)v3 + 0) == 4 && *(u8 *)((u8 *)v23 + 162) == 0 && *(u8 *)((u8 *)v23 + 164) == 11) {
    v21 = -1;
    }
    }
    }
    if (v21 != -1) {
    v24 = (void *)(((u8 *)(u32)p_lbl_1_data_35AC8 + 23684));
    v3 = (u32)&loc_470;
    v25 = (lbl_801A66B4.unk_0 << 2);
    fn_1_B5258((char *)v3, (void *)*(u32 *)((u8 *)v24 + ((v21 * 24) + v25)), (const char *)((u8 *)(u32)p_lbl_1_data_35AC8 + 29480), (const char *)*(u32 *)((u8 *)v24 + ((v17 * 24) + v25)));
    if (v19 != 0) {
    v3 = (u32)&loc_470;
    fn_1_B5258((char *)v3, (void *)v3, (const char *)((u8 *)(u32)p_lbl_1_data_35AC8 + 29472), (const char *)p_lbl_1_data_35AC8->unk_5FFC[lbl_801A66B4.unk_0]);
    } else {
    if ((v20 & 0x2) != 0) {
    v3 = (u32)&loc_470;
    fn_1_B5258((char *)v3, (void *)v3, (const char *)((u8 *)(u32)p_lbl_1_data_35AC8 + 29472), (const char *)p_lbl_1_data_35AC8->unk_6014[lbl_801A66B4.unk_0]);
    }
    }
    {
    loc_470.a[0] = 0;
    }
    }
    }
    v26 = (void *)(((u8 *)(u32)p_lbl_1_bss_716C0 + 8));
    if (*(u8 *)((u8 *)v26 + 4) != 5) {
    v3 = *(u8 *)((u8 *)v26 + 164);
    if (v3 == 5) {
    }
    }
    v27 = p_lbl_1_bss_716C0->unk_5C60;
    if ((s32)v27 <= 10) {
    if ((s32)v27 == 0) {
    v3 = 0xA9010000;
    v3 += 1536;
    fn_1_A2DC4(v3);
    }
    v3 = p_lbl_1_bss_716C0->unk_5C60;
    v28 = p_lbl_1_rodata_4AE0->unk_204;
    v4 = p_lbl_1_rodata_4AE0->unk_1E0;
    v29 = (f32)(s32)v3;
    v30 = (f32)(v29 / v28);
    v4 = (f32)(v4 - v30);
    v3 = (s32)(f32)((f32)(p_lbl_1_rodata_4AE0->unk_244 * v4) * v4);
    fn_1_54278(v3, 0);
    v4 = (f32)(v30 * v30);
    fn_1_5428C(v4);
    } else {
    v3 = 0;
    fn_1_54278(v3, 0);
    v4 = p_lbl_1_rodata_4AE0->unk_1E0;
    fn_1_5428C(v4);
    }
    v31 = p_lbl_1_bss_716C0->unk_5C60;
    v3 = v31;
    p_lbl_1_bss_716C0->unk_5C60 = (v3 + 1);
    t40 = fn_1_B7C00();
    v4 = t40;
    v32 = (v3 & 0xFF);
    v33 = 0;
    if ((v3 & 0x1) != 0) {
    v3 = (u32)((u8 *)(u32)p_lbl_1_bss_716C0 + 8);
    if (*(u8 *)((u8 *)v3 + 2) == 2) {
    v3 = *(u8 *)((u8 *)v3 + 42);
    if ((v3 & 0x8) == 0 && (v3 & 0x4) == 0) {
    v33 = (v33 | 1);
    } else {
    if ((*(u8 *)((u8 *)v3 + 42) & 0x4) == 0) {
    v33 = (v33 | 1);
    }
    }
    }
    }
    v34 = v33;
    if ((v32 & 0x2) != 0) {
    v3 = (u32)((u8 *)(u32)p_lbl_1_bss_716C0 + 8);
    if (*(u8 *)((u8 *)v3 + 162) == 2) {
    v3 = *(u8 *)((u8 *)v3 + 202);
    if ((v3 & 0x8) == 0 && (v3 & 0x4) == 0) {
    v34 = (v34 | 1);
    } else {
    if ((*(u8 *)((u8 *)v3 + 202) & 0x4) == 0) {
    v34 = (v34 | 1);
    }
    }
    }
    }
    if ((s32)v34 != 0) {
    v4 = p_lbl_1_rodata_4AE0->unk_244;
    fn_1_496FC(v4, p_lbl_1_rodata_4AE0->unk_3B4);
    v3 = (u32)&loc_470;
    fn_1_4A0D8((const char *)v3);
    }
    t43 = fn_1_B5654();
    v3 = t43;
    v35 = p_lbl_1_rodata_4AE0->unk_398;
    v4 = p_lbl_1_rodata_4AE0->unk_3B0;
    v3 = (u32)&loc_28;
    loc_8 = v35;
    loc_B = 255;
    loc_28 = loc_8;
    fn_1_4D274((u32 *)v3, v4);
    v3 = 0;
    fn_1_54278(v3, 0);
    v4 = p_lbl_1_rodata_4AE0->unk_1E0;
    fn_1_5428C(v4);
    }
    {
    p_lbl_1_bss_716C0->unk_5C60 = 0;
    if (*(u8 *)((u8 *)v26 + 4) == 11 || v3 == 11) {
    v36 = p_lbl_1_bss_716C0->unk_5C64;
    if ((s32)v36 <= 10) {
    if ((s32)v36 == 0) {
    v3 = 0xA9010000;
    v3 += 1536;
    fn_1_A2DC4(v3);
    }
    v3 = p_lbl_1_bss_716C0->unk_5C64;
    v37 = p_lbl_1_rodata_4AE0->unk_204;
    v4 = p_lbl_1_rodata_4AE0->unk_1E0;
    v38 = (f32)(s32)v3;
    v39 = (f32)(v38 / v37);
    v4 = (f32)(v4 - v39);
    v3 = (s32)(f32)((f32)(p_lbl_1_rodata_4AE0->unk_244 * v4) * v4);
    fn_1_54278(v3, 0);
    v4 = (f32)(v39 * v39);
    fn_1_5428C(v4);
    } else {
    v3 = 0;
    fn_1_54278(v3, 0);
    v4 = p_lbl_1_rodata_4AE0->unk_1E0;
    fn_1_5428C(v4);
    }
    v40 = p_lbl_1_bss_716C0->unk_5C64;
    v3 = v40;
    p_lbl_1_bss_716C0->unk_5C64 = (v3 + 1);
    t52 = fn_1_B7C00();
    v4 = t52;
    v41 = (v3 & 0xFF);
    v42 = 0;
    if ((v3 & 0x1) != 0) {
    v3 = (u32)((u8 *)(u32)p_lbl_1_bss_716C0 + 8);
    if (*(u8 *)((u8 *)v3 + 2) == 2) {
    v3 = *(u8 *)((u8 *)v3 + 42);
    if ((v3 & 0x8) == 0 && (v3 & 0x4) == 0) {
    v42 = (v42 | 1);
    } else {
    if ((*(u8 *)((u8 *)v3 + 42) & 0x4) == 0) {
    v42 = (v42 | 1);
    }
    }
    }
    }
    v43 = v42;
    if ((v41 & 0x2) != 0) {
    v3 = (u32)((u8 *)(u32)p_lbl_1_bss_716C0 + 8);
    if (*(u8 *)((u8 *)v3 + 162) == 2) {
    v3 = *(u8 *)((u8 *)v3 + 202);
    if ((v3 & 0x8) == 0 && (v3 & 0x4) == 0) {
    v43 = (v43 | 1);
    } else {
    if ((*(u8 *)((u8 *)v3 + 202) & 0x4) == 0) {
    v43 = (v43 | 1);
    }
    }
    }
    }
    if ((s32)v43 != 0) {
    v3 = (u32)((u8 *)(u32)p_lbl_1_bss_716C0 + 8);
    v3 = (u32)((u8 *)v3 + 160);
    if (*(u8 *)((u8 *)v26 + 4) == 11) {
    v3 = (u32)((u8 *)(u32)p_lbl_1_bss_716C0 + 8);
    }
    v3 = *(u32 *)((u8 *)v3 + 36);
    if (*(u8 *)((u8 *)v3 + 0) == 4) {
    v4 = p_lbl_1_rodata_4AE0->unk_244;
    fn_1_496FC(v4, p_lbl_1_rodata_4AE0->unk_3B4);
    v4 = p_lbl_1_rodata_4AE0->unk_3B8;
    fn_1_495A0(v4);
    v3 = (u32)((u8 *)(u32)p_lbl_1_data_35AC8 + 29468);
    fn_1_4A0D8((const char *)v3);
    v4 = p_lbl_1_rodata_4AE0->unk_1E0;
    fn_1_495A0(v4);
    v4 = p_lbl_1_rodata_4AE0->unk_244;
    fn_1_496FC(v4, p_lbl_1_rodata_4AE0->unk_3BC);
    v3 = (u32)&loc_470;
    fn_1_4A0D8((const char *)v3);
    } else {
    v4 = p_lbl_1_rodata_4AE0->unk_244;
    fn_1_496FC(v4, p_lbl_1_rodata_4AE0->unk_3B4);
    v3 = (u32)&loc_470;
    fn_1_4A0D8((const char *)v3);
    }
    }
    t61 = fn_1_B5A3C();
    v3 = t61;
    v44 = p_lbl_1_rodata_4AE0->unk_39C;
    v4 = p_lbl_1_rodata_4AE0->unk_3B0;
    v3 = (u32)&loc_24;
    loc_C = v44;
    loc_F = 255;
    loc_24 = loc_C;
    fn_1_4D274((u32 *)v3, v4);
    v3 = 0;
    fn_1_54278(v3, 0);
    v4 = p_lbl_1_rodata_4AE0->unk_1E0;
    fn_1_5428C(v4);
    } else {
    v3 = *(u8 *)((u8 *)v26 + 42);
    v45 = *(u8 *)((u8 *)v26 + 202);
    p_lbl_1_bss_716C0->unk_5C64 = 0;
    if (((v3 | v45) & 0x2) != 0) {
    v46 = p_lbl_1_bss_716C0->unk_5C68;
    if ((s32)v46 <= 10) {
    if ((s32)v46 == 0) {
    v3 = 0xA9010000;
    v3 += 1536;
    fn_1_A2DC4(v3);
    }
    v3 = p_lbl_1_bss_716C0->unk_5C68;
    v47 = p_lbl_1_rodata_4AE0->unk_204;
    v4 = p_lbl_1_rodata_4AE0->unk_1E0;
    v48 = (f32)(s32)v3;
    v49 = (f32)(v48 / v47);
    v4 = (f32)(v4 - v49);
    v3 = (s32)(f32)((f32)(p_lbl_1_rodata_4AE0->unk_244 * v4) * v4);
    fn_1_54278(v3, 0);
    v4 = (f32)(v49 * v49);
    fn_1_5428C(v4);
    } else {
    v3 = 0;
    fn_1_54278(v3, 0);
    v4 = p_lbl_1_rodata_4AE0->unk_1E0;
    fn_1_5428C(v4);
    }
    v50 = p_lbl_1_bss_716C0->unk_5C68;
    v3 = v50;
    p_lbl_1_bss_716C0->unk_5C68 = (v3 + 1);
    t70 = fn_1_B7C00();
    v4 = t70;
    v51 = (v3 & 0xFF);
    v52 = 0;
    if ((v3 & 0x1) != 0) {
    v3 = (u32)((u8 *)(u32)p_lbl_1_bss_716C0 + 8);
    if (*(u8 *)((u8 *)v3 + 2) == 2) {
    v3 = *(u8 *)((u8 *)v26 + 42);
    if ((v3 & 0x8) == 0 && (v3 & 0x4) == 0) {
    v52 = (v52 | 1);
    } else {
    if ((*(u8 *)((u8 *)v26 + 42) & 0x4) == 0) {
    v52 = (v52 | 1);
    }
    }
    }
    }
    v53 = v52;
    if ((v51 & 0x2) != 0) {
    v3 = (u32)((u8 *)(u32)p_lbl_1_bss_716C0 + 8);
    if (*(u8 *)((u8 *)v3 + 162) == 2) {
    v3 = *(u8 *)((u8 *)v26 + 202);
    if ((v3 & 0x8) == 0 && (v3 & 0x4) == 0) {
    v53 = (v53 | 1);
    } else {
    if ((*(u8 *)((u8 *)v26 + 202) & 0x4) == 0) {
    v53 = (v53 | 1);
    }
    }
    }
    }
    if ((s32)v53 != 0) {
    v4 = p_lbl_1_rodata_4AE0->unk_244;
    fn_1_496FC(v4, p_lbl_1_rodata_4AE0->unk_3B4);
    v3 = (u32)&loc_470;
    fn_1_4A0D8((const char *)v3);
    }
    t73 = fn_1_B5F20();
    v3 = t73;
    v54 = p_lbl_1_rodata_4AE0->unk_3A0;
    v4 = p_lbl_1_rodata_4AE0->unk_3B0;
    v3 = (u32)&loc_20;
    loc_10 = v54;
    loc_13 = 255;
    loc_20 = loc_10;
    fn_1_4D274((u32 *)v3, v4);
    v3 = 0;
    fn_1_54278(v3, 0);
    v4 = p_lbl_1_rodata_4AE0->unk_1E0;
    fn_1_5428C(v4);
    } else {
    v55 = *(s16 *)((u8 *)v26 + 8);
    p_lbl_1_bss_716C0->unk_5C68 = 0;
    loc_44[1] = -1;
    loc_44[2] = -1;
    v56 = 0;
    v57 = 0;
    if (v55 != -1) {
    v58 = *(u32 *)((u8 *)v26 + 36);
    v56 = (v56 | 1);
    v3 = *(u32 *)((u8 *)v58 + 140);
    v57 = *(u32 *)((u8 *)v58 + 8);
    v3 = *(u8 *)((u8 *)v3 + 63);
    loc_44[1] = v55;
    loc_3C[1] = *(s16 *)((u8 *)v26 + 10);
    loc_34[1] = v3;
    }
    v3 = (u32)((u8 *)(u32)p_lbl_1_bss_716C0 + 8);
    v59 = *(s16 *)((u8 *)v3 + 168);
    v60 = v56;
    v61 = v57;
    if (v59 != -1) {
    v62 = *(u32 *)((u8 *)v3 + 196);
    v60 = (v60 | 2);
    v63 = *(s16 *)((u8 *)v3 + 170);
    v3 = *(u32 *)((u8 *)v62 + 140);
    v3 = *(u8 *)((u8 *)v3 + 63);
    loc_44[2] = v59;
    v61 = (*(u32 *)((u8 *)v62 + 8) | v61);
    loc_44[0] = v63;
    loc_3C[0] = v3;
    }
    v3 = loc_44[1];
    if ((s32)p_lbl_1_bss_716C0->unk_5C00 != (s32)v3) {
    p_lbl_1_data_35AC8->unk_671C = 0;
    }
    v64 = (void *)(((u8 *)(u32)p_lbl_1_bss_716C0 + 23552));
    if ((s32)*(u32 *)((u8 *)v64 + 4) != (s32)loc_44[2]) {
    p_lbl_1_data_35AC8->unk_671C = 0;
    }
    v65 = p_lbl_1_data_35AC8->unk_671C;
    p_lbl_1_bss_716C0->unk_5C00 = v3;
    *(u32 *)((u8 *)v64 + 4) = loc_44[2];
    if ((s32)v65 <= 10) {
    if ((s32)v65 == 0) {
    v3 = 0xA9010000;
    v3 += 1536;
    fn_1_A2DC4(v3);
    }
    v3 = p_lbl_1_data_35AC8->unk_671C;
    v66 = p_lbl_1_rodata_4AE0->unk_204;
    v4 = p_lbl_1_rodata_4AE0->unk_1E0;
    v67 = (f32)(s32)v3;
    v68 = (f32)(v67 / v66);
    v4 = (f32)(v4 - v68);
    v3 = (s32)(f32)((f32)(p_lbl_1_rodata_4AE0->unk_244 * v4) * v4);
    fn_1_54278(v3, 0);
    v4 = (f32)(v68 * v68);
    fn_1_5428C(v4);
    } else {
    v3 = 0;
    fn_1_54278(v3, 0);
    v4 = p_lbl_1_rodata_4AE0->unk_1E0;
    fn_1_5428C(v4);
    }
    v69 = p_lbl_1_data_35AC8->unk_671C;
    v3 = v69;
    p_lbl_1_data_35AC8->unk_671C = (v3 + 1);
    t82 = fn_1_B7C00();
    v4 = t82;
    v70 = (v3 & 0xFF);
    v71 = 0;
    if ((v3 & 0x1) != 0) {
    v3 = (u32)((u8 *)(u32)p_lbl_1_bss_716C0 + 8);
    if (*(u8 *)((u8 *)v3 + 2) == 2) {
    v3 = *(u8 *)((u8 *)v26 + 42);
    if ((v3 & 0x8) == 0 && (v3 & 0x4) == 0) {
    v71 = (v71 | 1);
    } else {
    if ((*(u8 *)((u8 *)v26 + 42) & 0x4) == 0) {
    v71 = (v71 | 1);
    }
    }
    }
    }
    v72 = v71;
    if ((v70 & 0x2) != 0) {
    v3 = (u32)((u8 *)(u32)p_lbl_1_bss_716C0 + 8);
    if (*(u8 *)((u8 *)v3 + 162) == 2) {
    v3 = *(u8 *)((u8 *)v26 + 202);
    if ((v3 & 0x8) == 0 && (v3 & 0x4) == 0) {
    v72 = (v72 | 1);
    } else {
    if ((*(u8 *)((u8 *)v26 + 202) & 0x4) == 0) {
    v72 = (v72 | 1);
    }
    }
    }
    }
    if ((s32)v72 != 0) {
    v4 = p_lbl_1_rodata_4AE0->unk_244;
    fn_1_496FC(v4, p_lbl_1_rodata_4AE0->unk_3B4);
    v3 = (u32)&loc_470;
    fn_1_4A0D8((const char *)v3);
    }
    if (v60 != 0) {
    fn_1_49410();
    v3 = 42;
    fn_1_494DC(v3);
    v3 = 9;
    fn_1_495C8(v3);
    v3 = (u32)&loc_1C;
    loc_1C = p_lbl_1_rodata_4AE0->unk_3A4;
    fn_1_49514((u32 *)v3);
    v4 = p_lbl_1_rodata_4AE0->unk_2FC;
    fn_1_4954C(v4);
    fn_1_49614();
    v4 = p_lbl_1_rodata_4AE0->unk_230;
    fn_1_4955C(v4, v4);
    v4 = p_lbl_1_rodata_4AE0->unk_234;
    fn_1_4966C(v4, p_lbl_1_rodata_4AE0->unk_238);
    if ((s32)lbl_801A66B4.unk_0 != 5) {
    v3 = 0x80000000;
    fn_1_495B0(v3);
    v4 = p_lbl_1_rodata_4AE0->unk_23C;
    fn_1_49590(v4);
    v4 = p_lbl_1_rodata_4AE0->unk_234;
    fn_1_4966C(v4, p_lbl_1_rodata_4AE0->unk_240);
    }
    if (v60 < 3) {
    v73 = (v60 << 2);
    if ((s32)*(u32 *)((u8 *)loc_44 + v73) == 42 || (s32)*(u32 *)((u8 *)loc_44 + v73) == 44) {
    v4 = p_lbl_1_rodata_4AE0->unk_348;
    fn_1_4955C(v4, v4);
    }
    v3 = (u32)&lbl_801A66B4;
    v74 = (void *)(((u8 *)(u32)p_lbl_1_data_35AC8 + 23684));
    v3 = *(u32 *)((u8 *)v3 + 0);
    v75 = (v3 << 2);
    v3 = (u32)&loc_70;
    v76 = v75;
    if ((v60 - 1) == 0) {
    v76 = (u32)((u8 *)v74 + v76);
    v76 = *(u32 *)((u8 *)v76 + 888);
    } else {
    v76 = (u32)((u8 *)v74 + v76);
    v76 = *(u32 *)((u8 *)v76 + 912);
    }
    fn_1_B5258((char *)v3, (void *)*(u32 *)((u8 *)v74 + ((*(u32 *)((u8 *)loc_44 + v73) * 24) + v75)), (const char *)((u8 *)(u32)p_lbl_1_data_35AC8 + 29472), (const char *)v76);
    v3 = (u32)&loc_70;
    if ((v60 - 1) == 0) {
    v77 = (u32)((u8 *)((u8 *)(u32)p_lbl_1_data_35AC8 + 23684) + (lbl_801A66B4.unk_0 << 2));
    v77 = *(u32 *)((u8 *)v77 + 888);
    } else {
    v78 = (void *)(((u8 *)(u32)p_lbl_1_data_35AC8 + 23684));
    v77 = (u32)((u8 *)v78 + (lbl_801A66B4.unk_0 << 2));
    v77 = *(u32 *)((u8 *)v77 + 912);
    }
    fn_1_B5258((char *)v3, (void *)v3, (const char *)((u8 *)(u32)p_lbl_1_data_35AC8 + 29472), (const char *)v77);
    v3 = (u32)&loc_70;
    fn_1_B5258((char *)v3, (void *)v3, (const char *)((u8 *)(u32)p_lbl_1_data_35AC8 + 29480), (const char *)*(u32 *)((u8 *)((u8 *)(u32)p_lbl_1_data_35AC8 + 23684) + ((*(u32 *)((u8 *)loc_34 + v73) * 24) + (lbl_801A66B4.unk_0 << 2))));
    v79 = (void *)(((u8 *)((u8 *)(u32)p_lbl_1_bss_716C0 + 8) + (v60 * 160)));
    v3 = *(u32 *)((u8 *)v79 + -124);
    if (v3 != 0) {
    v81 = *(u32 *)((u8 *)v3 + 16);
    v3 = (u32)&loc_60;
    t100 = sprintf((char *)(u32)v3, (const char *)(u32)((u8 *)(u32)p_lbl_1_data_35AC8 + 29544), ((s32)v81 / 8192));
    v3 = t100;
    v3 = (u32)&loc_70;
    v80 = (u32)&loc_60;
    fn_1_B5258((char *)v3, (void *)v3, (const char *)((u8 *)(u32)p_lbl_1_data_35AC8 + 29548), (const char *)v80);
    } else {
    v3 = (u32)&loc_60;
    t102 = sprintf((char *)(u32)v3, (const char *)(u32)((u8 *)(u32)p_lbl_1_data_35AC8 + 29544), *(u32 *)((u8 *)((u8 *)((u8 *)(u32)p_lbl_1_bss_716C0 + 8) + (v60 * 160)) + -100));
    v3 = t102;
    v3 = (u32)&loc_70;
    v80 = (u32)&loc_60;
    fn_1_B5258((char *)v3, (void *)v3, (const char *)((u8 *)(u32)p_lbl_1_data_35AC8 + 29548), (const char *)v80);
    }
    v3 = *(u32 *)((u8 *)((u8 *)v79 + -124) + 0);
    if (v3 != 0) {
    v82 = *(u32 *)((u8 *)v3 + 12);
    v3 = (u32)&loc_50;
    t104 = sprintf((char *)(u32)v3, (const char *)(u32)((u8 *)(u32)p_lbl_1_data_35AC8 + 29544), ((u32)v82 >> 13));
    v3 = t104;
    v3 = (u32)&loc_70;
    fn_1_B5258((char *)v3, (void *)v3, (const char *)((u8 *)(u32)p_lbl_1_data_35AC8 + 29556), (const char *)&loc_50);
    }
    if ((v61 & 0x4) != 0) {
    v4 = p_lbl_1_rodata_4AE0->unk_244;
    fn_1_496FC(v4, p_lbl_1_rodata_4AE0->unk_3C0);
    v3 = (u32)&loc_70;
    fn_1_4A0D8((const char *)v3);
    } else {
    if ((s32)*(u32 *)((u8 *)loc_44 + v73) == 42 || (s32)*(u32 *)((u8 *)loc_44 + v73) == 44) {
    v4 = p_lbl_1_rodata_4AE0->unk_244;
    fn_1_496FC(v4, p_lbl_1_rodata_4AE0->unk_3C4);
    v3 = (u32)&loc_70;
    fn_1_4A0D8((const char *)v3);
    v4 = p_lbl_1_rodata_4AE0->unk_244;
    fn_1_496FC(v4, p_lbl_1_rodata_4AE0->unk_384);
    v3 = (u32)loc_3C;
    v83 = *(u32 *)((u8 *)v3 + v73);
    if ((s32)v83 != -1) {
    v84 = (void *)(((u8 *)(u32)p_lbl_1_data_35AC8 + 23684));
    v3 = (v83 * 24);
    v3 = *(u32 *)((u8 *)v84 + (v3 + (lbl_801A66B4.unk_0 << 2)));
    fn_1_4A0D8((const char *)v3);
    } else {
    v3 = (u32)&loc_70;
    t112 = fn_1_4B16C(v3);
    v3 = t112;
    v4 = p_lbl_1_rodata_4AE0->unk_244;
    fn_1_496FC(v4, p_lbl_1_rodata_4AE0->unk_3C8);
    v3 = (u32)&loc_70;
    fn_1_4A0D8((const char *)v3);
    v4 = p_lbl_1_rodata_4AE0->unk_244;
    fn_1_496FC(v4, p_lbl_1_rodata_4AE0->unk_380);
    v3 = (u32)loc_3C;
    v85 = *(u32 *)((u8 *)v3 + v73);
    if ((s32)v85 != -1) {
    v86 = (void *)(((u8 *)(u32)p_lbl_1_data_35AC8 + 23684));
    v3 = (v85 * 24);
    v3 = *(u32 *)((u8 *)v86 + (v3 + (lbl_801A66B4.unk_0 << 2)));
    fn_1_4A0D8((const char *)v3);
    }
    }
    } else {
    v4 = p_lbl_1_rodata_4AE0->unk_244;
    fn_1_496FC(v4, p_lbl_1_rodata_4AE0->unk_3B4);
    v87 = (void *)(((u8 *)(u32)p_lbl_1_data_35AC8 + 23684));
    v3 = (loc_44[1] * 24);
    v3 = *(u32 *)((u8 *)v87 + (v3 + (lbl_801A66B4.unk_0 << 2)));
    fn_1_4A0D8((const char *)v3);
    v3 = (u32)((u8 *)(u32)p_lbl_1_bss_716C0 + 8);
    v88 = (void *)(((u8 *)v3 + (v60 * 160)));
    v3 = *(u32 *)((u8 *)v88 + -124);
    if ((*(u32 *)((u8 *)v3 + 8) & 0x4) == 0) {
    v4 = p_lbl_1_rodata_4AE0->unk_244;
    fn_1_496FC(v4, p_lbl_1_rodata_4AE0->unk_3CC);
    if ((s32)loc_3C[1] != -1) {
    v89 = (void *)(((u8 *)(u32)p_lbl_1_data_35AC8 + 23684));
    v3 = (loc_3C[1] * 24);
    v3 = *(u32 *)((u8 *)v89 + (v3 + (lbl_801A66B4.unk_0 << 2)));
    fn_1_4A0D8((const char *)v3);
    }
    }
    v4 = p_lbl_1_rodata_4AE0->unk_244;
    fn_1_496FC(v4, p_lbl_1_rodata_4AE0->unk_250);
    v90 = (void *)(((u8 *)(u32)p_lbl_1_data_35AC8 + 23684));
    v3 = (loc_44[2] * 24);
    v3 = *(u32 *)((u8 *)v90 + (v3 + (lbl_801A66B4.unk_0 << 2)));
    fn_1_4A0D8((const char *)v3);
    v3 = *(u32 *)((u8 *)((u8 *)v88 + -124) + 0);
    if ((*(u32 *)((u8 *)v3 + 8) & 0x4) == 0) {
    v4 = p_lbl_1_rodata_4AE0->unk_244;
    fn_1_496FC(v4, p_lbl_1_rodata_4AE0->unk_3D0);
    if ((s32)loc_44[0] != -1) {
    v91 = (void *)(((u8 *)(u32)p_lbl_1_data_35AC8 + 23684));
    v3 = (loc_44[0] * 24);
    v3 = *(u32 *)((u8 *)v91 + (v3 + (lbl_801A66B4.unk_0 << 2)));
    fn_1_4A0D8((const char *)v3);
    }
    }
    }
    }
    }
    fn_1_49410();
    }
    v92 = p_lbl_1_rodata_4AE0->unk_3A8;
    v4 = p_lbl_1_rodata_4AE0->unk_3B0;
    v3 = (u32)&loc_18;
    loc_14 = v92;
    loc_17 = 255;
    loc_18 = loc_14;
    fn_1_4D274((u32 *)v3, v4);
    v3 = 0;
    t127 = fn_1_4AEC0(v3);
    v3 = t127;
    v4 = p_lbl_1_rodata_4AE0->unk_1C8;
    fn_1_4AEB4(v4);
    v3 = 0;
    fn_1_54278(v3, 0);
    v4 = p_lbl_1_rodata_4AE0->unk_1E0;
    fn_1_5428C(v4);
    }
    }
    }
    }
}
