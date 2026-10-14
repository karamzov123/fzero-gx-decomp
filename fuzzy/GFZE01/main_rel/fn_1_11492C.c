/* Non-matching: best partial attempt (81.46% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#define __XORIS__(a, b) ((a) ^ ((b) << 16))
struct Sig_fn_80077B14_fn_80077B14_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x18];
    u32 unk_20;
};
typedef struct {
    u8 pad_0[0x150];
    u32 *unk_150;
} Sig_fn_1_108A90_fn_1_108A90_Mgr;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Sig_fn_1_108A90_fn_1_108A90_Vec3;
typedef struct {
    u8 unk_0;
    u8 pad_1[0xf];
    Sig_fn_1_108A90_fn_1_108A90_Vec3 vec;
    u8 pad_1c[0x28];
} Sig_fn_1_108A90_fn_1_108A90_Entry;
typedef struct {
    u8 pad_0[0xc];
    Sig_fn_1_108A90_fn_1_108A90_Mgr *unk_c;
    u8 pad_10[8];
    u32 count;
    u8 pad_1c[8];
    Sig_fn_1_108A90_fn_1_108A90_Entry *entries;
} Sig_fn_1_108A90_fn_1_108A90_Self;
typedef struct {
    u8 pad_0[0x150];
    struct {
        u8 pad_0[8];
        u8 *unk_8;
    } *unk_150;
} Sig_fn_1_109114_fn_1_109114_AccessoryData;
typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
    Sig_fn_1_109114_fn_1_109114_AccessoryData *unk_C;
    void *unk_10;
    u8 pad_14[4];
    u32 unk_18;
    u8 pad_1C[8];
    u8 *unk_24;
} Sig_fn_1_109114_fn_1_109114_AccessoryObject;

struct fn_1_11492C_lbl_1_rodata_7AB8 {
    u8 pad_0[0x58];
    f64 unk_58;
    f32 unk_60;
    u8 pad_64[0x4];
    f32 unk_68;
    u8 pad_6C[0x30];
    f32 unk_9C;
    f32 unk_A0;
    u8 pad_A4[0xB0];
    f32 unk_154;
    u8 pad_158[0x30];
    f64 unk_188;
    f64 unk_190;
    f64 unk_198;
    u8 pad_1A0[0x4];
    f32 unk_1A4;
    f32 unk_1A8;
    u8 pad_1AC[0x30];
    f32 unk_1DC;
    u8 pad_1E0[0x8];
    f32 unk_1E8;
    u8 pad_1EC[0x20];
    f32 unk_20C;
    u8 pad_210[0x28];
    f32 unk_238;
    u8 pad_23C[0x4];
    f64 unk_240;
    u8 pad_248[0x34];
    f32 unk_27C;
    u8 pad_280[0x4];
    f32 unk_284;
    u8 pad_288[0x20];
    f32 unk_2A8;
    u8 pad_2AC[0x14];
    f32 unk_2C0;
    f32 unk_2C4;
    f32 unk_2C8;
    f32 unk_2CC;
    f32 unk_2D0;
    f32 unk_2D4;
    f32 unk_2D8;
    f32 unk_2DC;
    f32 unk_2E0;
    f32 unk_2E4;
    f32 unk_2E8;
    f32 unk_2EC;
    f32 unk_2F0;
    f32 unk_2F4;
    f32 unk_2F8;
    f32 unk_2FC;
    f32 unk_300;
    f32 unk_304;
    f32 unk_308;
    f32 unk_30C;
    f32 unk_310;
    f32 unk_314;
    f32 unk_318;
    f32 unk_31C;
    f32 unk_320;
    f32 unk_324;
    f32 unk_328;
    f32 unk_32C;
    f32 unk_330;
    f32 unk_334;
    f32 unk_338;
    u8 pad_33C[0x4];
    f64 unk_340;
    f32 unk_348;
    f32 unk_34C;
    f32 unk_350;
    f32 unk_354;
    f32 unk_358;
    f32 unk_35C;
    f32 unk_360;
};
struct fn_1_11492C_lbl_801A63C0 {
    u32 unk_0;
};

extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D118(f32 *);
extern f64 __fabs(f64);
extern s32 fn_80077B14(struct Sig_fn_80077B14_fn_80077B14_Arg0 *);
extern struct fn_1_11492C_lbl_1_rodata_7AB8 lbl_1_rodata_7AB8;
extern struct fn_1_11492C_lbl_801A63C0 lbl_801A63C0;
extern u32 fn_1_1286F4(void *);
extern u32 lbl_1_data_3FFBC;
extern u32 fn_1_108A90(Sig_fn_1_108A90_fn_1_108A90_Self *, s32, f32, f32, f32, f32);
extern u32 fn_1_109114(Sig_fn_1_109114_fn_1_109114_AccessoryObject *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DBE4(void);
extern u32 lbl_8006DC20(void);
extern u32 lbl_8006E1B0(void *, void *);

u32 fn_1_11492C(u32 arg0) {
    struct fn_1_11492C_lbl_1_rodata_7AB8 *p_lbl_1_rodata_7AB8;
    u32 v0;
    f64 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    s32 v5;
    u32 v6;
    u32 v7;
    s32 v8;
    struct { u32 value; } v9;
    f32 v10;
    f32 v11;
    f32 v12;
    u32 v13;
    u32 v14;
    u32 v15;
    s32 v16;
    u32 v17;
    u32 v18;
    s32 v19;
    u32 v20;
    s32 v21;
    u32 v22;
    u32 v23;
    u32 v24;
    f32 v25;
    f32 v26;
    f32 v27;
    f32 v28;
    f32 v29;
    f32 v30;
    f32 v31;
    f32 v32;
    f32 v33;
    f32 v34;
    f32 v35;
    f32 v36;
    f32 v37;
    f32 v38;
    f32 v39;
    f32 v40;
    f32 v41;
    f32 v42;
    f32 v43;
    f32 v44;
    f32 v45;
    f32 v46;
    u32 v47;
    u32 v48;
    u32 v49;
    u32 v50;
    s32 v51;
    u32 v52;
    f64 v53;
    f32 v54;
    f64 v55;
    f32 v56;
    f32 v57;
    f32 v58;
    f32 v59;
    f32 v60;
    f32 v61;
    f32 v62;
    u32 v63;
    u32 v64;
    u32 v65;
    u32 v66;
    s32 v67;
    u32 v68;
    f64 v69;
    f32 v70;
    f64 v71;
    f32 v72;
    f32 v73;
    f32 v74;
    f32 v75;
    u32 v76;
    f64 v77;
    f64 v78;
    u32 v79;
    s32 v80;
    u32 v81;
    f64 v82;
    f32 v83;
    u32 v84;
    u32 v85;
    u32 v86;
    f64 v87;
    f32 v88;
    f32 v89;
    f32 v90;
    f32 v91;
    f32 v92;
    f32 v93;
    f64 v94;
    struct { f32 a[6]; } loc_24;
    f32 loc_18[3];
    f32 loc_C[3];
    f32 loc_8;
    /* frame */
    s32 t0;
    f32 t11;
    f32 t12;
    u32 t48;
    p_lbl_1_rodata_7AB8 = (struct fn_1_11492C_lbl_1_rodata_7AB8 *)&lbl_1_rodata_7AB8;
    if (arg0 != 0) {
    v0 = *(u32 *)((u8 *)arg0 + 16);
    if (v0 != 0) {
    t0 = fn_80077B14((struct Sig_fn_80077B14_fn_80077B14_Arg0 *)v0);
    v0 = t0;
    v0 = *(u8 *)((u8 *)arg0 + 0);
    if ((v0 & 0x2) != 0) {
    *(u8 *)((u8 *)arg0 + 0) = (v0 & 0xFFFFFFFD);
    v0 = (u32)&lbl_1_data_3FFBC;
    v2 = *(u32 *)((u8 *)*(u32 *)((u8 *)arg0 + 12) + 336);
    v0 = (*(u32 *)((u8 *)v0 + (*(u32 *)((u8 *)arg0 + 8) << 2)) * 396);
    v0 += 136;
    v0 = (*(u32 *)((u8 *)v2 + 8) + v0);
    lbl_8006DBAC((void *)v0);
    lbl_8006DAEC();
    v3 = *(u32 *)((u8 *)arg0 + 36);
    v4 = v3;
    v5 = 0;
    while ((u32)v5 < *(u32 *)((u8 *)arg0 + 24)) {
    lbl_8006DBE4();
    v0 = (v4 + 40);
    lbl_8006E1B0((void *)v0, (void *)(v4 + 16));
    v5++;
    v4 += 68;
    }
    return lbl_8006DC20();
    }
    v6 = *(u32 *)((u8 *)arg0 + 36);
    v7 = v6;
    v8 = 0;
    while ((u32)v8 < *(u32 *)((u8 *)arg0 + 24)) {
    if ((*(u8 *)((u8 *)v7 + 0) & 0x1) == 0) {
    v0 = *(u32 *)((u8 *)v7 + 16);
    v1 = p_lbl_1_rodata_7AB8->unk_58;
    v9.value = *(u32 *)((u8 *)v7 + 20);
    *(u32 *)((u8 *)v7 + 28) = v0;
    v10 = p_lbl_1_rodata_7AB8->unk_60;
    *(u32 *)((u8 *)v7 + 32) = v9.value;
    *(u32 *)((u8 *)v7 + 36) = *(u32 *)((u8 *)v7 + 24);\
    *(f32 *)((u8 *)v7 + 16) = (f32)(*(f32 *)((u8 *)v7 + 16) + *(f32 *)((u8 *)v7 + 52));
    *(f32 *)((u8 *)v7 + 20) = (f32)(*(f32 *)((u8 *)v7 + 20) + *(f32 *)((u8 *)v7 + 56));
    v11 = *(f32 *)((u8 *)v7 + 24);
    *(f32 *)((u8 *)v7 + 24) = (f32)(v11 + *(f32 *)((u8 *)v7 + 60));
    v12 = *(f32 *)((u8 *)v7 + 20);
    v1 = (f64)((f64)(v12) - (f64)(v1));
    v1 = (f32)((f32)v1);\
    *(f32 *)((u8 *)v7 + 20) = v1;
    v1 = (f32)(*(f32 *)((u8 *)v7 + 56));
    *(f32 *)((u8 *)v7 + 56) = (f32)(v1 - v10);
    }
    v8++;
    v7 += 68;
    }
    v13 = *(u32 *)((u8 *)arg0 + 12);
    v0 = (u32)&lbl_1_data_3FFBC;
    v14 = *(u32 *)((u8 *)arg0 + 36);
    v15 = *(u32 *)((u8 *)v0 + (*(u32 *)((u8 *)arg0 + 8) << 2));
    v0 = *(u32 *)((u8 *)v13 + 336);
    v0 = *(u32 *)((u8 *)v0 + 8);
    v16 = 0;
    v17 = v14;
    v18 = (v0 + (v15 * 396));
    while ((u32)v16 < *(u32 *)((u8 *)arg0 + 24)) {
    v0 = (v18 + 136);
    lbl_8006DBAC((void *)v0);
    lbl_8006DAEC();
    if ((*(u8 *)((u8 *)v17 + 0) & 0x1) != 0) {
    lbl_8006DBE4();
    v0 = (v17 + 40);
    return lbl_8006E1B0((void *)v0, (void *)(v17 + 16));
    }
    lbl_8006DC20();
    v16++;
    v17 += 68;
    }
    v19 = 0;
    do {
    v20 = *(u32 *)((u8 *)arg0 + 40);
    v21 = 0;
    v22 = v20;
    while ((u32)v21 < *(u32 *)((u8 *)arg0 + 28)) {
    v23 = *(u32 *)((u8 *)v22 + 0);
    v24 = *(u32 *)((u8 *)v22 + 4);
    if (v23 != 0 && v24 != 0) {
    v1 = (f32)(*(f32 *)((u8 *)v23 + 20));
    v25 = (f32)(*(f32 *)((u8 *)v23 + 16) - *(f32 *)((u8 *)v24 + 16));
    v26 = (f32)(v1 - *(f32 *)((u8 *)v24 + 20));
    v1 = (f32)((f32)(v25 * v25));
    v27 = (f32)(*(f32 *)((u8 *)v23 + 24) - *(f32 *)((u8 *)v24 + 24));
    loc_24.a[3] = v25;
    v1 = (f32)((f32)((v26 * v26) + v1));
    loc_24.a[4] = v26;
    v1 = (f32)((f32)((v27 * v27) + v1));
    loc_24.a[5] = v27;
    loc_8 = v1;
    v28 = (f32)(v1 - p_lbl_1_rodata_7AB8->unk_9C);
    if (v28 > *(f32 *)((u8 *)v22 + 8)) {
    v0 = (u32)&loc_8;
    t11 = lbl_8006D118(&loc_8);
    v1 = (f32)(t11);
    v29 = v1;
    v1 = (f32)(*(f32 *)((u8 *)v22 + 8));
    t12 = lbl_8006D0B4(v1);
    v1 = (f32)(t12);
    v30 = (f32)(loc_8 - v1);
    v1 = (f32)(loc_24.a[4]);
    v31 = (f32)(v29 * v30);
    loc_8 = v31;
    v32 = (f32)(loc_24.a[3] * v31);
    v33 = (f32)(v1 * v31);
    v34 = *(f32 *)((u8 *)v23 + 64);
    v35 = (f32)(loc_24.a[5] * v31);
    v36 = *(f32 *)((u8 *)v24 + 64);
    v1 = (f32)(*(f32 *)((u8 *)v23 + 16));
    loc_24.a[3] = v32;
    loc_24.a[4] = v33;
    v37 = (f32)(p_lbl_1_rodata_7AB8->unk_A0 / (f32)(v34 + v36));
    loc_24.a[5] = v35;
    v38 = (f32)(v34 * v37);
    v39 = (f32)(v36 * v37);
    v40 = (f32)(v1 - (f32)(v32 * v38));
    v1 = (f32)((f32)(v33 * v39));
    *(f32 *)((u8 *)v23 + 16) = v40;
    v41 = *(f32 *)((u8 *)v23 + 20);
    *(f32 *)((u8 *)v23 + 20) = (f32)(v41 - (f32)(v33 * v38));
    *(f32 *)((u8 *)v23 + 24) = (f32)(*(f32 *)((u8 *)v23 + 24) - (f32)(v35 * v38));
    *(f32 *)((u8 *)v24 + 16) = (f32)(*(f32 *)((u8 *)v24 + 16) + (f32)(v32 * v39));
    v1 = (f32)((f32)(*(f32 *)((u8 *)v24 + 20) + v1));
    *(f32 *)((u8 *)v24 + 20) = v1;
    v1 = (f32)(*(f32 *)((u8 *)v24 + 24));
    *(f32 *)((u8 *)v24 + 24) = (f32)(v1 + (f32)(v35 * v39));
    }
    }
    v21++;
    v22 += 12;
    }
    if ((s32)*(u32 *)((u8 *)*(u32 *)((u8 *)arg0 + 12) + 136) == 2) {
    v42 = p_lbl_1_rodata_7AB8->unk_68;
    v0 = arg0;
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_284);
    fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 1, v1, p_lbl_1_rodata_7AB8->unk_1A8, v42, v42);
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_2C0);
    v0 = arg0;
    fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 1, v1, p_lbl_1_rodata_7AB8->unk_2C4, p_lbl_1_rodata_7AB8->unk_68, p_lbl_1_rodata_7AB8->unk_2C8);
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_2C0);
    v0 = arg0;
    fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 1, v1, p_lbl_1_rodata_7AB8->unk_2C4, p_lbl_1_rodata_7AB8->unk_68, p_lbl_1_rodata_7AB8->unk_2CC);
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_2D0);
    v0 = arg0;
    fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 13, v1, p_lbl_1_rodata_7AB8->unk_2D4, p_lbl_1_rodata_7AB8->unk_2D8, p_lbl_1_rodata_7AB8->unk_68);
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_2D0);
    v0 = arg0;
    fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 13, v1, p_lbl_1_rodata_7AB8->unk_2DC, p_lbl_1_rodata_7AB8->unk_2D8, p_lbl_1_rodata_7AB8->unk_68);
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_2D0);
    v0 = arg0;
    fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 13, v1, p_lbl_1_rodata_7AB8->unk_2E0, p_lbl_1_rodata_7AB8->unk_2D8, p_lbl_1_rodata_7AB8->unk_68);
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_2D0);
    v0 = arg0;
    fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 8, v1, p_lbl_1_rodata_7AB8->unk_2D4, p_lbl_1_rodata_7AB8->unk_2E4, p_lbl_1_rodata_7AB8->unk_68);
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_2D0);
    v0 = arg0;
    fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 8, v1, p_lbl_1_rodata_7AB8->unk_2DC, p_lbl_1_rodata_7AB8->unk_2E4, p_lbl_1_rodata_7AB8->unk_68);
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_2D0);
    v0 = arg0;
    return fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 8, v1, p_lbl_1_rodata_7AB8->unk_2E0, p_lbl_1_rodata_7AB8->unk_2E4, p_lbl_1_rodata_7AB8->unk_68);
    } else {
    if ((s32)*(u32 *)((u8 *)*(u32 *)((u8 *)arg0 + 12) + 136) == 36) {
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_2E8);
    v0 = arg0;
    fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 1, v1, p_lbl_1_rodata_7AB8->unk_2EC, p_lbl_1_rodata_7AB8->unk_2F0, p_lbl_1_rodata_7AB8->unk_2F4);
    v43 = p_lbl_1_rodata_7AB8->unk_68;
    v0 = arg0;
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_2F8);
    return fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 12, v1, v43, v43, v43);
    } else {
    if ((s32)*(u32 *)((u8 *)*(u32 *)((u8 *)arg0 + 12) + 136) == 33 || (s32)*(u32 *)((u8 *)*(u32 *)((u8 *)arg0 + 12) + 136) == 42 || (s32)*(u32 *)((u8 *)*(u32 *)((u8 *)arg0 + 12) + 136) == 43) {
    v44 = p_lbl_1_rodata_7AB8->unk_68;
    v0 = arg0;
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_238);
    fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 1, v1, p_lbl_1_rodata_7AB8->unk_2FC, v44, v44);
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_300);
    v0 = arg0;
    return fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 1, v1, p_lbl_1_rodata_7AB8->unk_304, p_lbl_1_rodata_7AB8->unk_308, p_lbl_1_rodata_7AB8->unk_30C);
    } else {
    if ((s32)*(u32 *)((u8 *)*(u32 *)((u8 *)arg0 + 12) + 136) == 41) {
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_310);
    v0 = arg0;
    return fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 1, v1, p_lbl_1_rodata_7AB8->unk_314, p_lbl_1_rodata_7AB8->unk_318, p_lbl_1_rodata_7AB8->unk_68);
    } else {
    if ((s32)*(u32 *)((u8 *)*(u32 *)((u8 *)arg0 + 12) + 136) == 21) {
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_31C);
    v0 = arg0;
    return fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 1, v1, p_lbl_1_rodata_7AB8->unk_320, p_lbl_1_rodata_7AB8->unk_324, p_lbl_1_rodata_7AB8->unk_68);
    } else {
    if ((s32)*(u32 *)((u8 *)*(u32 *)((u8 *)arg0 + 12) + 136) == 24) {
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_328);
    v0 = arg0;
    fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 1, v1, p_lbl_1_rodata_7AB8->unk_32C, p_lbl_1_rodata_7AB8->unk_2D8, p_lbl_1_rodata_7AB8->unk_330);
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_328);
    v0 = arg0;
    fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 1, v1, p_lbl_1_rodata_7AB8->unk_334, p_lbl_1_rodata_7AB8->unk_2D8, p_lbl_1_rodata_7AB8->unk_338);
    v45 = p_lbl_1_rodata_7AB8->unk_68;
    v0 = arg0;
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_238);
    fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 12, v1, v45, v45, v45);
    v46 = p_lbl_1_rodata_7AB8->unk_68;
    v0 = arg0;
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_238);
    return fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 7, v1, v46, v46, v46);
    } else {
    if ((s32)*(u32 *)((u8 *)*(u32 *)((u8 *)arg0 + 12) + 136) == 4) {
    v47 = *(u32 *)((u8 *)*(u32 *)((u8 *)arg0 + 12) + 336);
    v0 = (u32)&lbl_1_data_3FFBC;
    v48 = *(u32 *)((u8 *)arg0 + 36);
    v49 = *(u32 *)((u8 *)v0 + (*(u32 *)((u8 *)arg0 + 8) << 2));
    v0 = *(u32 *)((u8 *)v47 + 8);
    v50 = v48;
    v51 = 0;
    v52 = (v0 + (v49 * 396));
    do {
    if ((*(u8 *)((u8 *)v50 + 0) & 0x1) == 0) {
    v0 = (v52 + 136);
    lbl_8006DBAC((void *)v0);
    v0 = (v50 + 40);
    lbl_8006E1B0((void *)v0, (void *)loc_18);
    v1 = (f32)(*(f32 *)((u8 *)v50 + 16));
    v53 = p_lbl_1_rodata_7AB8->unk_340;
    v54 = (f32)(v1 + (f32)(f64)((f64)(v53) * (f64)((f32)(loc_18[0] - v1))));
    v1 = (f64)((f64)(v53) * (f64)((f32)(loc_18[2] - *(f32 *)((u8 *)v50 + 24))));
    v55 = (f64)((f64)(v53) * (f64)((f32)(loc_18[1] - *(f32 *)((u8 *)v50 + 20))));
    *(f32 *)((u8 *)v50 + 16) = v54;
    v1 = (f32)((f32)v1);
    *(f32 *)((u8 *)v50 + 20) = (f32)(*(f32 *)((u8 *)v50 + 20) + (f32)v55);
    *(f32 *)((u8 *)v50 + 24) = (f32)(*(f32 *)((u8 *)v50 + 24) + v1);
    }
    v51++;
    v50 += 68;
    } while (v51 < 10);
    v56 = p_lbl_1_rodata_7AB8->unk_68;
    v0 = arg0;
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_1DC);
    fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 16, v1, p_lbl_1_rodata_7AB8->unk_348, v56, v56);
    v57 = p_lbl_1_rodata_7AB8->unk_68;
    v0 = arg0;
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_34C);
    fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 18, v1, v57, v57, v57);
    v58 = p_lbl_1_rodata_7AB8->unk_68;
    v0 = arg0;
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_334);
    fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 18, v1, p_lbl_1_rodata_7AB8->unk_1E8, v58, v58);
    v59 = p_lbl_1_rodata_7AB8->unk_68;
    v0 = arg0;
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_32C);
    fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 18, v1, p_lbl_1_rodata_7AB8->unk_350, v59, v59);
    v60 = p_lbl_1_rodata_7AB8->unk_68;
    v0 = arg0;
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_34C);
    fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 23, v1, v60, v60, v60);
    v61 = p_lbl_1_rodata_7AB8->unk_68;
    v0 = arg0;
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_334);
    fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 23, v1, p_lbl_1_rodata_7AB8->unk_1E8, v61, v61);
    v62 = p_lbl_1_rodata_7AB8->unk_68;
    v0 = arg0;
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_32C);
    return fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 23, v1, p_lbl_1_rodata_7AB8->unk_350, v62, v62);
    }
    {
    if ((s32)*(u32 *)((u8 *)*(u32 *)((u8 *)arg0 + 12) + 136) == 35) {
    v63 = *(u32 *)((u8 *)*(u32 *)((u8 *)arg0 + 12) + 336);
    v0 = (u32)&lbl_1_data_3FFBC;
    v64 = *(u32 *)((u8 *)arg0 + 36);
    v65 = *(u32 *)((u8 *)v0 + (*(u32 *)((u8 *)arg0 + 8) << 2));
    v0 = *(u32 *)((u8 *)v63 + 8);
    v66 = v64;
    v67 = 0;
    v68 = (v0 + (v65 * 396));
    do {
    if ((*(u8 *)((u8 *)v66 + 0) & 0x1) == 0) {
    v0 = (v68 + 136);
    lbl_8006DBAC((void *)v0);
    v0 = (v66 + 40);
    lbl_8006E1B0((void *)v0, (void *)loc_C);
    v1 = (f32)(*(f32 *)((u8 *)v66 + 16));
    v69 = p_lbl_1_rodata_7AB8->unk_340;
    v70 = (f32)(v1 + (f32)(f64)((f64)(v69) * (f64)((f32)(loc_C[0] - v1))));
    v1 = (f64)((f64)(v69) * (f64)((f32)(loc_C[2] - *(f32 *)((u8 *)v66 + 24))));
    v71 = (f64)((f64)(v69) * (f64)((f32)(loc_C[1] - *(f32 *)((u8 *)v66 + 20))));
    *(f32 *)((u8 *)v66 + 16) = v70;
    v1 = (f32)((f32)v1);
    *(f32 *)((u8 *)v66 + 20) = (f32)(*(f32 *)((u8 *)v66 + 20) + (f32)v71);
    *(f32 *)((u8 *)v66 + 24) = (f32)(*(f32 *)((u8 *)v66 + 24) + v1);
    }
    v67++;
    v66 += 68;
    } while (v67 < 10);
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_354);
    v0 = arg0;
    fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 16, v1, p_lbl_1_rodata_7AB8->unk_154, p_lbl_1_rodata_7AB8->unk_358, p_lbl_1_rodata_7AB8->unk_68);
    v72 = p_lbl_1_rodata_7AB8->unk_68;
    v0 = arg0;
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_2D4);
    fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 18, v1, v72, v72, v72);
    v73 = p_lbl_1_rodata_7AB8->unk_68;
    v0 = arg0;
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_2A8);
    fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 18, v1, p_lbl_1_rodata_7AB8->unk_27C, v73, v73);
    v74 = p_lbl_1_rodata_7AB8->unk_68;
    v0 = arg0;
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_2D4);
    fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 23, v1, v74, v74, v74);
    v75 = p_lbl_1_rodata_7AB8->unk_68;
    v0 = arg0;
    v1 = (f32)(p_lbl_1_rodata_7AB8->unk_2A8);
    return fn_1_108A90((Sig_fn_1_108A90_fn_1_108A90_Self *)v0, 23, v1, p_lbl_1_rodata_7AB8->unk_27C, v75, v75);
    }
    }
    }
    }
    }
    }
    }
    }
    v19++;
    } while (v19 < 4);
    v76 = *(u32 *)((u8 *)arg0 + 36);
    v77 = p_lbl_1_rodata_7AB8->unk_190;
    v78 = p_lbl_1_rodata_7AB8->unk_188;
    v79 = v76;
    v80 = 0;
    while ((u32)v80 < *(u32 *)((u8 *)arg0 + 24)) {
    v0 = (u32)&loc_24;
    t48 = fn_1_1286F4((void *)v0);
    v0 = t48;
    *(f32 *)((u8 *)v79 + 52) = (f32)(f64)((f64)(*(f32 *)((u8 *)v79 + 52)) * (f64)(v77));
    *(f32 *)((u8 *)v79 + 56) = (f32)(f64)((f64)(*(f32 *)((u8 *)v79 + 56)) * (f64)(v77));
    *(f32 *)((u8 *)v79 + 60) = (f32)(f64)((f64)(*(f32 *)((u8 *)v79 + 60)) * (f64)(v77));
    v1 = (f32)(*(f32 *)((u8 *)v79 + 16));
    *(f32 *)((u8 *)v79 + 52) = (f32)(f64)((f64)(*(f32 *)((u8 *)v79 + 52)) + (f64)((f64)((f64)(v78) * (f64)((f32)(v1 - *(f32 *)((u8 *)v79 + 28))))));
    v1 = (f32)(*(f32 *)((u8 *)v79 + 20));
    *(f32 *)((u8 *)v79 + 56) = (f32)(f64)((f64)(*(f32 *)((u8 *)v79 + 56)) + (f64)((f64)((f64)(v78) * (f64)((f32)(v1 - *(f32 *)((u8 *)v79 + 32))))));
    v1 = (f32)(*(f32 *)((u8 *)v79 + 24));
    *(f32 *)((u8 *)v79 + 60) = (f32)(f64)((f64)(*(f32 *)((u8 *)v79 + 60)) + (f64)((f64)((f64)(v78) * (f64)((f32)(v1 - *(f32 *)((u8 *)v79 + 36))))));
    v0 = *(u32 *)((u8 *)arg0 + 12);
    v0 = *(u32 *)((u8 *)v0 + 136);
    if ((s32)v0 == 4 || (s32)v0 == 35) {
        lbl_801A63C0.unk_0 = lbl_801A63C0.unk_0 * 0x676A4B6B + 13259;
        *(f32 *)((u8 *)v79 + 52) = (f32)(*(f32 *)((u8 *)v79 + 52) + (f32)(__fabs(loc_24.a[0]) * ((f32)((lbl_801A63C0.unk_0 >> 16) & 0x7FFF) / p_lbl_1_rodata_7AB8->unk_20C)));
        lbl_801A63C0.unk_0 = lbl_801A63C0.unk_0 * 0x676A4B6B + 13259;
        *(f32 *)((u8 *)v79 + 56) = (f32)(*(f32 *)((u8 *)v79 + 56) + p_lbl_1_rodata_7AB8->unk_35C * ((f32)((lbl_801A63C0.unk_0 >> 16) & 0x7FFF) / p_lbl_1_rodata_7AB8->unk_20C));
        lbl_801A63C0.unk_0 = lbl_801A63C0.unk_0 * 0x676A4B6B + 13259;
        *(f32 *)((u8 *)v79 + 60) = (f32)(*(f32 *)((u8 *)v79 + 60) + (f32)(__fabs(loc_24.a[2]) * ((f32)((lbl_801A63C0.unk_0 >> 16) & 0x7FFF) / p_lbl_1_rodata_7AB8->unk_20C)));
    } else if ((s32)v0 == 21 || (s32)v0 == 33 || (u32)(v0 - 41) <= 2 || (s32)v0 == 36) {
        lbl_801A63C0.unk_0 = lbl_801A63C0.unk_0 * 0x676A4B6B + 13259;
        *(f32 *)((u8 *)v79 + 52) = (f32)(*(f32 *)((u8 *)v79 + 52) + p_lbl_1_rodata_7AB8->unk_1A4 * ((f32)((lbl_801A63C0.unk_0 >> 16) & 0x7FFF) / p_lbl_1_rodata_7AB8->unk_20C));
        lbl_801A63C0.unk_0 = lbl_801A63C0.unk_0 * 0x676A4B6B + 13259;
        *(f32 *)((u8 *)v79 + 56) = (f32)(*(f32 *)((u8 *)v79 + 56) + p_lbl_1_rodata_7AB8->unk_360 * ((f32)((lbl_801A63C0.unk_0 >> 16) & 0x7FFF) / p_lbl_1_rodata_7AB8->unk_20C));
        lbl_801A63C0.unk_0 = lbl_801A63C0.unk_0 * 0x676A4B6B + 13259;
        *(f32 *)((u8 *)v79 + 60) = (f32)(*(f32 *)((u8 *)v79 + 60) + p_lbl_1_rodata_7AB8->unk_68);
    } else {
        v94 = p_lbl_1_rodata_7AB8->unk_198;
        *(f32 *)((u8 *)v79 + 52) = (f32)(v94 * loc_24.a[0] + *(f32 *)((u8 *)v79 + 52));
        *(f32 *)((u8 *)v79 + 56) = (f32)(v94 * loc_24.a[1] + *(f32 *)((u8 *)v79 + 56));
        *(f32 *)((u8 *)v79 + 60) = (f32)(v94 * loc_24.a[2] + *(f32 *)((u8 *)v79 + 60));
    }
    v80++;
    v79 += 68;
    }
    v0 = arg0;
    return fn_1_109114((Sig_fn_1_109114_fn_1_109114_AccessoryObject *)v0);
    }
    }
    return (u32)v13;
}
