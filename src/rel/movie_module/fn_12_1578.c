#include "types.h"
#pragma use_lmw_stmw on
#pragma pool_data on
#pragma readonly_strings on
typedef struct Sig_fn_12_1578_MovieData {
    int mode;
    int value;
    unsigned char pad[0x3c];
    int field44;
    int field48;
} Sig_fn_12_1578_MovieData;
typedef struct Sig_fn_12_1578_MovieState {
    int pad0;
    int value;
} Sig_fn_12_1578_MovieState;
typedef struct Sig_fn_12_748_MovieModule {
    u8 pad30[0x30];
    int value;
} Sig_fn_12_748_MovieModule;
typedef struct Sig_fn_12_34DC_MovieModuleObject {
    int field_0;
    int field_4;
} Sig_fn_12_34DC_MovieModuleObject;
typedef struct Sig_fn_12_3508_MovieModuleObject {
    int field_0;
    int field_4;
    void *field_8;
    void *field_C;
    void *field_10;
    int field_14;
} Sig_fn_12_3508_MovieModuleObject;

struct fn_12_1578_lbl_12_rodata_60 {
    u8 pad_0[0xF4];
    f32 unk_F4;
    f64 unk_F8;
};

extern int fn_12_34DC(Sig_fn_12_34DC_MovieModuleObject *);
extern int fn_12_748(Sig_fn_12_748_MovieModule *);
extern const struct fn_12_1578_lbl_12_rodata_60 lbl_12_rodata_60;
extern u32 fn_12_3D740(u32);
extern void fn_12_309C(u32, u32, u32);
extern void fn_12_34E4(void *, void *, void *);
extern void fn_12_3508(Sig_fn_12_3508_MovieModuleObject *, void *, void *);
extern void fn_12_3D730();
extern void fn_12_3D734();
extern void fn_12_3D73C();

#pragma force_active on
#pragma section code_type ".fzgxpool"
static f32 fzgx_pool_primer_before(s32 value) {
    fn_12_309C(0, 0, (u32)"E201312: sfxcnv_IsCnvUpHalf : compo is invalid.");
    fn_12_309C(0, 0, (u32)"E301282: CnvToRgb888 : compo is not support.");
    fn_12_309C(0, 0, (u32)"COMPO");
    fn_12_309C(0, 0, (u32)"E301281: SFX_CnvFrmRgb888 : frmfmt is not support.");
    fn_12_309C(0, 0, (u32)"E202281: SFX_MakeTblZ32 : zclip is not set.");
    fn_12_309C(0, 0, (u32)"E202282: SFX_MakeTblZ16 : zclip is not set.");
    return 1.164f * (f32)value;
}
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_after(void) {
    fn_12_309C(0, 0, (u32)"E201311: sfxcnv_MakeTable : compo is not support.");
    fn_12_309C(0, 0, (u32)"E201313: sfxcnv_CnvZbitToCft : zbit is invalid.");
    fn_12_309C(0, 0, (u32)"E201315: sfxcnv_CnvFrmZcmn : zclip is not set.");
    fn_12_309C(0, 0, (u32)"E201191: SFX_CnvFrmZcmn : frmfmt is not support.");
    fn_12_309C(0, 0, (u32)"E201192: CnvToY84C44 : compo is not support.");
    fn_12_309C(0, 0, (u32)"E201193: SFX_CnvFrmY84C44 : frmfmt is not support.");
    fn_12_309C(0, 0, (u32)"E201182: CnvToYuv422 : compo is not support.");
    fn_12_309C(0, 0, (u32)"E201183: SFX_CnvFrmYUV422 : frmfmt is not support.");
    fn_12_309C(0, 0, (u32)"E212182: CnvToArgb8888mb : compo is not support.");
    fn_12_309C(0, 0, (u32)"E212173: sfxcnv_CnvFrmYcc420mbToArgb8888mb() : compo is not support.");
    fn_12_309C(0, 0, (u32)"E212171: SFX_CnvFrmARGB8888Mb : function is not support.");
    fn_12_309C(0, 0, (u32)"E212172: SFX_CnvFrmMbARGB8888 : frmfmt is not support.");
}
#pragma section code_type ".text"
#pragma force_active off

static inline void fn_12_1578_MakeTable(u8 *v30) {
    s32 v23;
    for (v23 = 0; v23 <= 15; v23++) {
        v30[v23] = 0;
    }
    for (v23 = 16; v23 <= 235; v23++) {
        v30[v23] = (u8)(1.164f * (f32)(v23 - 16));
    }
    for (v23 = 236; v23 <= 255; v23++) {
        v30[v23] = 255;
    }
}

void fn_12_1578(Sig_fn_12_1578_MovieState * arg0, Sig_fn_12_1578_MovieData * arg1, int arg2, f32 arg3, f32 arg4) {
    int v0;
    u32 v1;
    f32 v2;
    u32 unk_1;
    int v4;
    u32 v5;
    u32 unk_2;
    int v7;
    u32 v8;
    u32 unk_3;
    int v10;
    u32 v11;
    u32 v12;
    s32 v13;
    u32 unk_4;
    int v15;
    u32 v16;
    u32 unk_5;
    int v18;
    u32 v19;
    int v20;
    u32 v21;
    f64 v22;
    s32 v23;
    f64 v24;
    u32 v25;
    int v26;
    u32 v27;
    int v28;
    int v29;
    u8 *v30;
    int v31;
    int v32;
    f32 v33;
    s32 v34;
    s32 v35;
    f32 v36;
    s32 v37;
    f32 v38;
    u32 v39;
    s32 v40;
    f64 v41;
    int v42;
    u32 v43;
    u32 unk_6;
    int v45;
    u32 v46;
    struct { u32 a[6]; } loc_C8;
    struct { u32 a[6]; } loc_B0;
    struct { u32 a[6]; } loc_98;
    struct { u32 a[6]; } loc_80;
    struct { u32 a[6]; } loc_68;
    struct { u32 a[6]; } loc_50;
    u32 loc_44[3];
    u32 loc_38[3];
    u32 loc_2C[3];
    u32 loc_20[3];
    u32 loc_14[3];
    u32 loc_8[3];
    /* frame */
    int t0;
    u32 t3;
    u32 t6;
    int t9;
    /* 6 instruction(s) not lifted: see the ??? markers */
    v0 = ((Sig_fn_12_1578_MovieState *)(arg0))->value;
    switch ((s32)v0) {
    case 17:
    t0 = fn_12_748((Sig_fn_12_748_MovieModule *)arg0);
    v1 = t0;
    if ((s32)v1 != 1) {
    loc_44[0] = ((Sig_fn_12_1578_MovieData *)(arg1))->value;
    v1 = arg1->field44;
    loc_44[1] = v1;
    loc_44[2] = ((Sig_fn_12_1578_MovieData *)(arg1))->field48;
    loc_C8.a[0] = arg2;
    loc_C8.a[1] = v1;
    v4 = ((Sig_fn_12_1578_MovieState *)(arg0))->value;
    switch ((s32)v4) {
    case 17:
case 49:
case 65:
case 241:
case 4097:
    v4 = 0;
    break;
    case 33:
case 257:
    v4 = 1;
    break;
    default:
    v1 = 0;
    fn_12_309C(v1, 0, (u32)"E201312: sfxcnv_IsCnvUpHalf : compo is invalid.");
    v4 = 0;
    }
    if (v4 == 1) {
    v1 = ((Sig_fn_12_1578_MovieData *)(arg1))->field48;
    loc_C8.a[2] = ((s32)(((u32)v1 >> 31) + v1) >> 1);
    } else {
    loc_C8.a[2] = ((Sig_fn_12_1578_MovieData *)(arg1))->field48;
    }
    if ((s32)*(u32 *)((u8 *)arg0 + 8) == 0) {
    v5 = (*(u32 *)((u8 *)arg1 + 8) << 2);
    loc_C8.a[3] = v5;
    } else {
    loc_C8.a[3] = *(u32 *)((u8 *)arg0 + 8);
    }
    fn_12_3D730(loc_44, &loc_C8);
    } else {
    v1 = *(u32 *)((u8 *)arg0 + 52);
    v0 = 1;
    if ((s32)v1 == 100) {
    v0 = 0;
    } else if ((s32)v1 == 21) {
    v0 = 0;
    }
    if (v0 == 1) {
    *(u32 *)((u8 *)arg0 + 52) = 21;
    v1 = *(u32 *)((u8 *)arg0 + 56);
    t3 = fn_12_3D740(v1);
    v1 = t3;
    }
    loc_38[0] = ((Sig_fn_12_1578_MovieData *)(arg1))->value;
    v1 = arg1->field44;
    loc_38[1] = v1;
    loc_38[2] = ((Sig_fn_12_1578_MovieData *)(arg1))->field48;
    loc_B0.a[0] = arg2;
    loc_B0.a[1] = v1;
    v7 = ((Sig_fn_12_1578_MovieState *)(arg0))->value;
    switch ((s32)v7) {
    case 17:
case 49:
case 65:
case 241:
case 4097:
    v7 = 0;
    break;
    case 33:
case 257:
    v7 = 1;
    break;
    default:
    v1 = 0;
    fn_12_309C(v1, 0, (u32)"E201312: sfxcnv_IsCnvUpHalf : compo is invalid.");
    v7 = 0;
    }
    if (v7 == 1) {
    v1 = ((Sig_fn_12_1578_MovieData *)(arg1))->field48;
    loc_B0.a[2] = ((s32)(((u32)v1 >> 31) + v1) >> 1);
    } else {
    loc_B0.a[2] = ((Sig_fn_12_1578_MovieData *)(arg1))->field48;
    }
    if ((s32)*(u32 *)((u8 *)arg0 + 8) == 0) {
    v8 = (*(u32 *)((u8 *)arg1 + 8) << 2);
    loc_B0.a[3] = v8;
    } else {
    loc_B0.a[3] = *(u32 *)((u8 *)arg0 + 8);
    }
    fn_12_3D73C(loc_38, &loc_B0, (void *)*(u32 *)((u8 *)arg0 + 56));
    break;
    case 4097:
    v1 = *(u32 *)((u8 *)arg0 + 52);
    v0 = 1;
    if ((s32)v1 == 100) {
    v0 = 0;
    } else if ((s32)v1 == 21) {
    v0 = 0;
    }
    if (v0 == 1) {
    *(u32 *)((u8 *)arg0 + 52) = 21;
    v1 = *(u32 *)((u8 *)arg0 + 56);
    t6 = fn_12_3D740(v1);
    v1 = t6;
    }
    loc_2C[0] = ((Sig_fn_12_1578_MovieData *)(arg1))->value;
    v1 = arg1->field44;
    loc_2C[1] = v1;
    loc_2C[2] = ((Sig_fn_12_1578_MovieData *)(arg1))->field48;
    loc_98.a[0] = arg2;
    loc_98.a[1] = v1;
    v10 = ((Sig_fn_12_1578_MovieState *)(arg0))->value;
    switch ((s32)v10) {
    case 17:
case 49:
case 65:
case 241:
case 4097:
    v10 = 0;
    break;
    case 33:
case 257:
    v10 = 1;
    break;
    default:
    v1 = 0;
    fn_12_309C(v1, 0, (u32)"E201312: sfxcnv_IsCnvUpHalf : compo is invalid.");
    v10 = 0;
    }
    if (v10 == 1) {
    v1 = ((Sig_fn_12_1578_MovieData *)(arg1))->field48;
    loc_98.a[2] = ((s32)(((u32)v1 >> 31) + v1) >> 1);
    } else {
    loc_98.a[2] = ((Sig_fn_12_1578_MovieData *)(arg1))->field48;
    }
    if ((s32)*(u32 *)((u8 *)arg0 + 8) == 0) {
    v11 = (*(u32 *)((u8 *)arg1 + 8) << 2);
    loc_98.a[3] = v11;
    } else {
    loc_98.a[3] = *(u32 *)((u8 *)arg0 + 8);
    }
    fn_12_3D73C(loc_2C, &loc_98, (void *)*(u32 *)((u8 *)arg0 + 56));
    break;
    case 49:
    v12 = *(u32 *)((u8 *)arg0 + 52);
    v13 = 1;
    if ((s32)v12 == 100) {
    v13 = 0;
    } else if ((s32)v12 == 2) {
    v1 = *(u32 *)((u8 *)arg0 + 44);
    t9 = fn_12_34DC((Sig_fn_12_34DC_MovieModuleObject *)v1);
    v1 = t9;
    if ((s32)v1 != 1) {
    v13 = 0;
    }
    }
    if (v13 == 1) {
    *(u32 *)((u8 *)arg0 + 52) = 2;
    v1 = *(u32 *)((u8 *)arg0 + 44);
    fn_12_3508((Sig_fn_12_3508_MovieModuleObject *)v1, (void *)*(u32 *)((u8 *)arg1 + 76), (void *)*(u32 *)((u8 *)arg0 + 56));
    }
    loc_20[0] = ((Sig_fn_12_1578_MovieData *)(arg1))->value;
    v1 = arg1->field44;
    loc_20[1] = v1;
    loc_20[2] = ((Sig_fn_12_1578_MovieData *)(arg1))->field48;
    loc_80.a[0] = arg2;
    loc_80.a[1] = v1;
    v15 = ((Sig_fn_12_1578_MovieState *)(arg0))->value;
    switch ((s32)v15) {
    case 17:
case 49:
case 65:
case 241:
case 4097:
    v15 = 0;
    break;
    case 33:
case 257:
    v15 = 1;
    break;
    default:
    v1 = 0;
    fn_12_309C(v1, 0, (u32)"E201312: sfxcnv_IsCnvUpHalf : compo is invalid.");
    v15 = 0;
    }
    if (v15 == 1) {
    v1 = ((Sig_fn_12_1578_MovieData *)(arg1))->field48;
    loc_80.a[2] = ((s32)(((u32)v1 >> 31) + v1) >> 1);
    } else {
    loc_80.a[2] = ((Sig_fn_12_1578_MovieData *)(arg1))->field48;
    }
    if ((s32)*(u32 *)((u8 *)arg0 + 8) == 0) {
    v16 = (*(u32 *)((u8 *)arg1 + 8) << 2);
    loc_80.a[3] = v16;
    } else {
    loc_80.a[3] = *(u32 *)((u8 *)arg0 + 8);
    }
    fn_12_3D73C(loc_20, &loc_80, (void *)*(u32 *)((u8 *)arg0 + 56));
    break;
    case 65:
    v1 = *(u32 *)((u8 *)arg0 + 52);
    v0 = 1;
    if ((s32)v1 == 100) {
    v0 = 0;
    } else if ((s32)v1 == 3) {
    v0 = 0;
    }
    if (v0 == 1) {
    *(u32 *)((u8 *)arg0 + 52) = 3;
    v1 = *(u32 *)((u8 *)arg0 + 44);
    fn_12_34E4((void *)v1, (void *)*(u32 *)((u8 *)arg1 + 76), (void *)*(u32 *)((u8 *)arg0 + 56));
    }
    loc_14[0] = ((Sig_fn_12_1578_MovieData *)(arg1))->value;
    v1 = arg1->field44;
    loc_14[1] = v1;
    loc_14[2] = ((Sig_fn_12_1578_MovieData *)(arg1))->field48;
    loc_68.a[0] = arg2;
    loc_68.a[1] = v1;
    v18 = ((Sig_fn_12_1578_MovieState *)(arg0))->value;
    switch ((s32)v18) {
    case 17:
case 49:
case 65:
case 241:
case 4097:
    v18 = 0;
    break;
    case 33:
case 257:
    v18 = 1;
    break;
    default:
    v1 = 0;
    fn_12_309C(v1, 0, (u32)"E201312: sfxcnv_IsCnvUpHalf : compo is invalid.");
    v18 = 0;
    }
    if (v18 == 1) {
    v1 = ((Sig_fn_12_1578_MovieData *)(arg1))->field48;
    loc_68.a[2] = ((s32)(((u32)v1 >> 31) + v1) >> 1);
    } else {
    loc_68.a[2] = ((Sig_fn_12_1578_MovieData *)(arg1))->field48;
    }
    if ((s32)*(u32 *)((u8 *)arg0 + 8) == 0) {
    v19 = (*(u32 *)((u8 *)arg1 + 8) << 2);
    loc_68.a[3] = v19;
    } else {
    loc_68.a[3] = *(u32 *)((u8 *)arg0 + 8);
    }
    fn_12_3D73C(loc_14, &loc_68, (void *)*(u32 *)((u8 *)arg0 + 56));
    break;
    case 33:
    v1 = *(u32 *)((u8 *)arg0 + 52);
    v0 = 1;
    if ((s32)v1 == 100) {
    v0 = 0;
    } else if ((s32)v1 == 1) {
    v0 = 0;
    }
    if (v0 == 1) {
    *(u32 *)((u8 *)arg0 + 52) = 1;
    fn_12_1578_MakeTable(*(u8 **)((u8 *)arg0 + 56));
    }
    loc_8[0] = ((Sig_fn_12_1578_MovieData *)(arg1))->value;
    loc_8[1] = arg1->field44;
    loc_8[2] = arg1->field48;
    loc_50.a[0] = arg2;
    loc_50.a[1] = arg1->field44;
    loc_50.a[2] = arg1->field48 / 2;
    if ((s32)*(u32 *)((u8 *)arg0 + 8) == 0) {
    v43 = (*(u32 *)((u8 *)arg1 + 8) << 2);
    loc_50.a[3] = v43;
    } else {
    loc_50.a[3] = *(u32 *)((u8 *)arg0 + 8);
    }
    fn_12_3D730(loc_8, &loc_50);
    loc_8[0] = ((Sig_fn_12_1578_MovieData *)(arg1))->value;
    v1 = arg1->field44;
    loc_8[1] = v1;
    v45 = ((Sig_fn_12_1578_MovieData *)(arg1))->field48;
    loc_8[2] = v45;
    loc_50.a[0] = arg2;
    loc_50.a[1] = v1;
    loc_50.a[2] = v45;
    if ((s32)*(u32 *)((u8 *)arg0 + 8) == 0) {
    v46 = (*(u32 *)((u8 *)arg1 + 8) << 2);
    loc_50.a[3] = v46;
    } else {
    loc_50.a[3] = *(u32 *)((u8 *)arg0 + 8);
    }
    fn_12_3D734(loc_8, &loc_50, (void *)*(u32 *)((u8 *)arg0 + 56));
    break;
    default:
    case 241:
    case 257:
    v1 = (u32)(arg0);
    fn_12_309C(v1, (u32)arg1, (u32)"E201182: SFX_CnvToArgb8888 : compo is not support.");
    }
    }
}
