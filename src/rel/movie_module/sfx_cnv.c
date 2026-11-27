#include "types.h"

typedef struct Sig_fn_12_748_MovieModule {
    u8 pad30[0x30];
    int value;
} Sig_fn_12_748_MovieModule;

typedef struct MovieState {
    int pad0;
    int value;
} MovieState;

typedef struct MovieData {
    int mode;
    int value;
    unsigned char pad[0x3c];
    int field44;
    int field48;
} MovieData;

typedef struct Fn12_A5C_3 {
    s32 f00;
    s32 f04;
    s32 f08;
    s32 f0C;
    s32 f10;
    s32 f14;
    s32 f18;
} Fn12_A5C_3;

typedef struct Fn12_A5C_2 {
    u32 f00;
    s32 f04;
    s32 f08;
    s32 f0C;
    s32 f10;
    s32 f14;
} Fn12_A5C_2;

struct fn_12_1578_lbl_12_rodata_60 {
    u8 pad_0[0xF4];
    f32 unk_F4;
    f64 unk_F8;
};

typedef struct fn_12_D88_Arg1 {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    u8 pad_10[0x4];
    s32 unk_14;
    s32 unk_18;
    u8 pad_1C[0x8];
    s32 unk_24;
    s32 unk_28;
} fn_12_D88_Arg1;

typedef struct Fn12_A5C_0 {
    u8 pad0[8];
    s32 field_08;
    s32 field_0C;
    u8 pad10[0x10];
    s32 field_20;
    u8 pad24[0x10];
    s32 field_34;
    s32 field_38;
} Fn12_A5C_0;

typedef struct Fn12_A5C_1 {
    u8 pad0[4];
    s32 field_04;
    s32 field_08;
    s32 field_0C;
    u8 pad10[4];
    s32 field_14;
    s32 field_18;
    u8 pad1C[8];
    s32 field_24;
    s32 field_28;
    u8 pad2C[0x20];
    s32 field_4C;
} Fn12_A5C_1;

typedef struct Fn12_8E4_Self {
    u32 unk_00;
    u32 unk_04;
    s32 field_08;
    s32 field_0c;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1c;
    u32 field_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2c;
    u32 unk_30;
    s32 field_34;
    u32 field_38;
} Fn12_8E4_Self;

typedef struct Fn12_8E4_Arg1 {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    s32 unk_0c;
    u32 unk_10[15];
    u32 unk_4c;
} Fn12_8E4_Arg1;

typedef struct MovieModule {
    u8 unk0[4];
    s32 field4;
    u8 unk8[0x18];
    u32 field20;
} MovieModule;

typedef struct MovieArg {
    s32 value;
} MovieArg;

typedef struct {
    s32 a[10];
} fn_12_D88_Loc;

struct fn_12_F70_Arg0 {
    u8 pad_0[0x4];
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    u8 pad_10[0x28];
    u32 unk_38;
};

typedef struct Sig_fn_12_740_MovieModule {
    u8 pad[0x60];
    int value;
} Sig_fn_12_740_MovieModule;

typedef struct Sig_fn_12_49D8_MovieState {
    u8 pad[0x58];
    s32 value;
} Sig_fn_12_49D8_MovieState;

struct Sig_fn_12_49AC_fn_12_49AC_Arg0 {
    u8 pad_0[0x58];
    u32 unk_58;
};

struct Sig_fn_12_738_MovieData {
    u8 pad[0x64];
    int value;
};

typedef struct SFXHandle {
    s32 active;
    s32 stream_info;
    s32 field_count;
    u8 reserved_0c[0x20];
    void *alpha;
    u8 reserved_30[4];
    s32 table_compo;
    void *work_0;
} SFXHandle;

struct fn_12_F70_Arg1 {
    u8 pad_0[0x4];
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    u8 pad_10[0x4];
    s32 unk_14;
    s32 unk_18;
    u8 pad_1C[0x8];
    s32 unk_24;
    s32 unk_28;
    u8 pad_2C[0x18];
    s32 unk_44;
    s32 unk_48;
};

struct fn_12_13D0_Arg1 {
    u8 pad_0[0x48];
    u32 unk_48;
};

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

typedef struct MovieMatrix {
    s32 x;
    s32 y;
    s32 z;
    s32 width;
    s32 height;
    s32 depth;
    s32 pad_18;
} MovieMatrix;

typedef struct MovieSource {
    s32 object;
    s32 field_04;
    s32 field_08;
    s32 field_0c;
    s32 pad_10;
    s32 pad_14;
} MovieSource;

typedef struct CFTYcc420Planar {
    void *y;
    void *cb;
    void *cr;
    s32 y_stride;
    s32 cb_stride;
    s32 cr_stride;
    u8 reserved_18[4];
} CFTYcc420Planar;

typedef struct SFXPlaneBuffer {
    void *pixels;
    s32 width;
    s32 height;
    s32 pitch;
} SFXPlaneBuffer;

typedef struct CFTArgb8888Output {
    SFXPlaneBuffer plane;
    u8 reserved_10[8];
} CFTArgb8888Output;

typedef struct MovieArg0 {
    s32 pad_00;
    s32 format;
    s32 count;
    s32 pad_0c[11];
    u32 field_38;
} MovieArg0;

typedef struct MovieArg1 {
    s32 pad_00;
    s32 width;
    s32 height;
    s32 depth;
    s32 pad_10;
    s32 offset_x;
    s32 offset_y;
    s32 pad_1c;
    s32 pad_20;
    s32 step_x;
    s32 step_y;
    s32 pad_2c[6];
    s32 field_44;
    s32 field_48;
    s32 pad_4c[10];
    s32 field_74;
} MovieArg1;

typedef struct SFXFrameInfo {
    s32 format;
    SFXPlaneBuffer y;
    SFXPlaneBuffer cb;
    SFXPlaneBuffer cr;
    u8 reserved_34[0x10];
    s32 field_44;
    s32 field_48;
    s32 color_adjustment;
    u8 reserved_50[0x24];
    s32 field_74;
} SFXFrameInfo;

typedef struct Sig_fn_12_1578_MovieState {
    int pad0;
    int value;
} Sig_fn_12_1578_MovieState;

typedef struct Sig_fn_12_1578_MovieData {
    int mode;
    int value;
    unsigned char pad[0x3c];
    int field44;
    int field48;
} Sig_fn_12_1578_MovieData;

typedef struct MovieArgs {
    int a;
    int b;
    int c;
    int pad[3];
} MovieArgs;
extern u8 lbl_12_rodata_194[248];
extern void fn_12_309C(u32 a, u32 b, u32 c);
extern void fn_12_3710(u32, u32, u32);
extern void fn_12_3DBDC();
extern void fn_12_3DCEC();
extern void fn_12_3DBE0(Fn12_A5C_3 *, Fn12_A5C_2 *, s32);
extern void fn_12_3A64(s32, s32, s32);
extern f64 lbl_12_rodata_60[12];
extern int fn_12_3074();
extern s32 fn_12_3630(const MovieData *movie);
extern void fn_12_A5C(Fn12_A5C_0 *param0, Fn12_A5C_1 *param1, s32 type, s32 param3);
extern void fn_12_8E4(Fn12_8E4_Self *self, Fn12_8E4_Arg1 *arg1, s32 arg2, void *arg3);
extern void fn_12_C60(MovieModule *module, MovieArg *arg1, s32 arg2, void *arg3);
extern void fn_12_3C17C(fn_12_D88_Loc *, s32, s32, s32, s32);
extern void fn_12_3C4A8(void *, void *, u32);
extern void fn_12_3C8CC(void *, void *);
extern int fn_12_740(MovieModule *self);
extern int fn_12_49D8(MovieState *state);
extern int fn_12_49AC(struct fn_12_F70_Arg0 *);
extern int fn_12_738(struct MovieData *movie);
extern u32 lbl_12_rodata_28C;
extern int fn_12_748(Sig_fn_12_748_MovieModule *);
extern void fn_12_F70();
extern void fn_12_3D968(void* table);
extern void fn_12_3D740(void* buffer);
extern u8 lbl_12_rodata_C0[212];
extern void fn_12_11A8(Sig_fn_12_748_MovieModule *arg0, u32 arg1, void *arg2);
extern u8 lbl_12_rodata_2BC[396];
extern void fn_12_132C(void *arg0, void *arg1, void *arg2);
extern u32 fn_12_68C(u32, u32);
extern u32 fn_12_6B8(u32, u32);
extern void fn_12_8B4(void *, void *, void *);
extern u32 fn_12_307C(void);
extern void fn_12_13D0(u32 arg0, struct fn_12_13D0_Arg1 *arg1, u32 arg2);
extern int fn_12_34DC(void *alpha);
extern void fn_12_34E4(void *arg0, void *arg1, void *arg2);
extern void fn_12_3508(void *alpha, s32 adjustment, void *table);
extern void fn_12_3D730();
extern void fn_12_3D734();
extern void fn_12_3D73C();
extern u32 fn_12_308C(void);
extern void fn_12_3D144(MovieMatrix *matrix, MovieSource *source);
extern u32 fn_12_3DCF0(const CFTYcc420Planar *source, const CFTArgb8888Output *destination, const u8 *table);
extern void fn_12_3DF08(const CFTYcc420Planar *source, const CFTArgb8888Output *destination);
extern void fn_12_3CB74(CFTYcc420Planar *source, CFTArgb8888Output *destination, void *table);
extern void fn_12_3E09C(const void *source, void *destination, s32 width, s32 height);
extern void fn_12_1F84(MovieArg0 *arg0, MovieArg1 *arg1, s32 arg2);
extern void fn_12_21C8(SFXHandle *handle, SFXFrameInfo *frame, void *output);
extern void fn_12_1578();
extern void fn_12_3D738();
extern void fn_12_2F04();

/* fzgx:begin fn_12_8E4 */
/* --- rel/movie_module/fn_12_8E4.c --- */



void fn_12_8E4(Fn12_8E4_Self *self, Fn12_8E4_Arg1 *arg1, s32 arg2, void *arg3) {
    struct { u32 v[6]; } vec_a;
    struct { u32 v[6]; } vec_b;
    s32 x;
    s32 y;
    u32 mode;
    s32 cond;

    vec_a.v[0] = arg1->unk_04;
    vec_a.v[1] = arg1->unk_08;
    vec_a.v[2] = arg1->unk_0c;
    vec_a.v[3] = 0x40;

    if (self->field_08 == 0) {
        x = (s32)arg1->unk_08;
    } else {
        x = self->field_08;
    }
    if (self->field_0c == 0) {
        y = arg1->unk_0c / 2;
    } else {
        y = self->field_0c;
    }

    switch (arg2) {
    case 0x10:
        mode = 1;
        break;
    case 0x18:
        mode = 2;
        break;
    case 0x20:
        mode = 3;
        break;
    case 0:
    default:
        fn_12_309C(0, 0, (u32)(void *)(lbl_12_rodata_194));
        mode = 0;
        break;
    }

    vec_b.v[0] = mode;
    vec_b.v[1] = (u32)arg3;
    vec_b.v[2] = (u32)x;
    vec_b.v[3] = (u32)y;
    vec_b.v[4] = arg1->unk_08;
    vec_b.v[5] = (u32)(arg1->unk_0c / 2);

    switch (arg2) {
    case 0x10:
        break;
    case 0x20:
        cond = (self->field_34 != 100);
        if (cond == 1) {
            self->field_34 = 13;
            fn_12_3710(self->field_20, arg1->unk_4c, self->field_38);
        }
        fn_12_3DBDC(&vec_a, &vec_b, self->field_38);
        break;
    }
}
/* fzgx:end fn_12_8E4 */

/* fzgx:begin fn_12_A5C */
#pragma opt_propagation off







void fn_12_A5C(Fn12_A5C_0 *param0, Fn12_A5C_1 *param1, s32 type, s32 param3) {
    s32 *fzgx_value;
    Fn12_A5C_3 var3;
    Fn12_A5C_2 var2;
    s32 product;
    s32 half;
    s32 quarter;
    s32 local1;
    s32 local2;
    s32 code;
    product = param1->field_08 * param1->field_0C;
    half = product / 2;

    var3.f00 = param1->field_04 + half;
    var3.f04 = ((quarter = half / 2) + (param1->field_14));
    var3.f08 = param1->field_24 + quarter;
    var3.f0C = param1->field_08;
    var3.f10 = param1->field_18;
    var3.f14 = param1->field_28;
    var3.f18 = 0;

    local1 = param0->field_08 == 0 ? param1->field_08 : param0->field_08;
    local2 = param0->field_0C == 0 ? param1->field_0C / 2 : param0->field_0C;

    switch (type) {
    case 0x10:
        code = 1;
        break;
    case 0x18:
        code = 2;
        break;
    case 0x20:
        code = 3;
        break;
    case 0:
    default:
        fn_12_309C(0, 0, (u32)lbl_12_rodata_194);
        code = 0;
        break;
    }

    var2.f00 = code;
    var2.f04 = param3;
    var2.f08 = local1;
    var2.f0C = local2;
    var2.f10 = param1->field_08;
    var2.f14 = param1->field_0C / 2;

    switch (type) {
    case 0x10: {
        s32 flag = (param0->field_34 != 100);
        if (flag == 1) {
            param0->field_34 = 11;
            fn_12_3A64(param0->field_20, param1->field_4C, param0->field_38);
        }
        fn_12_3DCEC(&var3, &var2, param0->field_38);
        break;
    }
    case 0x20: {
        s32 flag = (param0->field_34 != 100);
        if (flag == 1) {
            fzgx_value = &(param0->field_34);
            *fzgx_value = 13;
            fn_12_3710(param0->field_20, param1->field_4C, param0->field_38);
        }
        fn_12_3DBE0(&var3, &var2, param0->field_38);
        break;
    }
    }
}
/* fzgx:end fn_12_A5C */

/* fzgx:begin fn_12_C60 */




void fn_12_C60(MovieModule *module, MovieArg *arg1, s32 arg2, void *arg3) {
    u8 *table = (u8 *)((u8 *)&lbl_12_rodata_60);

    if (module->field4 == 0) {
        module->field4 = ((u32)fn_12_3074(arg1, table + 0x60));
    }

    if (fn_12_3630( (const MovieData *)(u32)(module->field20)) != 1) {
        fn_12_309C( (u32)(void *)(module), (u32)(void *)(arg1), (u32)(const void *)(table + 0x164));
    } else {
        switch (arg1->value) {
        case 3:
            fn_12_A5C( (Fn12_A5C_0 *)(void *)(module), (Fn12_A5C_1 *)(void *)(arg1), arg2, (s32)(void *)(arg3));
            break;
        case 2:
            fn_12_8E4( (Fn12_8E4_Self *)(void *)(module), (Fn12_8E4_Arg1 *)(void *)(arg1), arg2, arg3);
            break;
        case 1:
        default:
            fn_12_309C( (u32)(void *)(module), (u32)(void *)(arg1), (u32)(const void *)(table + 0x194));
            break;
        }
    }
}
/* fzgx:end fn_12_C60 */

/* fzgx:begin fn_12_D38 */

void fn_12_D38(u32 arg0, u32 arg1, u32 arg2) {
    fn_12_C60( (MovieModule *)(u32)(arg0), (MovieArg *)(u32)(arg1), 0x20, (void *)(u32)(arg2));
}
/* fzgx:end fn_12_D38 */

/* fzgx:begin fn_12_D60 */
/* --- rel/movie_module/fn_12_D60.c --- */

void fn_12_D60(void *arg0, void *arg1, void *arg2) {
    fn_12_C60( (MovieModule *)(void *)(arg0), (MovieArg *)(void *)(arg1), 16, arg2);
}
/* fzgx:end fn_12_D60 */

/* fzgx:begin fn_12_D88 */
/* --- rel/movie_module/fn_12_D88.c --- */
#pragma use_lmw_stmw on
#pragma pool_data on
#pragma readonly_strings on

typedef struct fn_12_D88_Arg0 {
    u8 pad_0[0x4];
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
} fn_12_D88_Arg0;


/* retail's 0x50 frame holds ten words here; fn_12_D88 fills the first six */


#pragma force_active on
#pragma section code_type ".fzgxpool"
static f32 fzgx_pool_primer_before(s32 value) {
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E201312: sfxcnv_IsCnvUpHalf : compo is invalid."));
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E301282: CnvToRgb888 : compo is not support."));
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("COMPO"));
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E301281: SFX_CnvFrmRgb888 : frmfmt is not support."));
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E202281: SFX_MakeTblZ32 : zclip is not set."));
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E202282: SFX_MakeTblZ16 : zclip is not set."));
    return 1.164f * (f32)value;
}
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_after(void) {
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E201311: sfxcnv_MakeTable : compo is not support."));
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E201313: sfxcnv_CnvZbitToCft : zbit is invalid."));
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E201315: sfxcnv_CnvFrmZcmn : zclip is not set."));
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E201191: SFX_CnvFrmZcmn : frmfmt is not support."));
}
#pragma section code_type ".text"
#pragma force_active off

static inline void cnv_to(fn_12_D88_Arg0 *arg0, fn_12_D88_Arg1 *arg1, s32 arg2, s32 arg3) {
    fn_12_D88_Loc loc;
    s32 width;
    s32 height;
    s32 t;

    switch (arg0->unk_4) {
    case 0x11:
    case 0x101:
        loc.a[0] = arg1->unk_4;
        loc.a[1] = arg1->unk_14;
        loc.a[2] = arg1->unk_24;
        loc.a[3] = arg1->unk_8;
        loc.a[4] = arg1->unk_18;
        loc.a[5] = arg1->unk_28;
        width = (arg0->unk_8 == 0) ? arg1->unk_8 : arg0->unk_8;
        height = arg0->unk_C;
        if (height == 0) {
            height = arg1->unk_C;
        }
        switch (arg0->unk_4) {
        case 0x11:
        case 0x31:
        case 0x41:
        case 0xf1:
        case 0x1001:
            t = 0;
            break;
        case 0x21:
        case 0x101:
            t = 1;
            break;
        default:
            fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E201312: sfxcnv_IsCnvUpHalf : compo is invalid."));
            t = 0;
            break;
        }
        if (t == 1) {
            height /= 2;
        }
        fn_12_3C17C(&loc, arg2, arg3, width, height);
        break;
    case 0x21:
    case 0x31:
    case 0x41:
    case 0xf1:
    case 0x1001:
    default:
        fn_12_309C( (u32)(void *)(arg0), (u32)(void *)(arg1), (u32)(const char *)("E201192: CnvToY84C44 : compo is not support."));
        break;
    }
}

void fn_12_D88(fn_12_D88_Arg0 *arg0, fn_12_D88_Arg1 *arg1, s32 arg2, s32 arg3) {
    s32 mode;

    mode = arg1->unk_0;
    if (arg0->unk_4 == 0) {
        arg0->unk_4 = fn_12_3074(arg1, "COMPO");
    }

    switch (mode) {
    case 3:
        cnv_to(arg0, arg1, arg2, arg3);
        break;
    case 1:
    case 2:
    default:
        fn_12_309C( (u32)(void *)(arg0), (u32)(void *)(arg1), (u32)(const char *)("E201193: SFX_CnvFrmY84C44 : frmfmt is not support."));
        break;
    }
}
/* fzgx:end fn_12_D88 */

/* fzgx:begin fn_12_F70 */



typedef struct {
    u32 a[6];
} fn_12_F70_Loc24;

typedef struct {
    u32 a[7];
} fn_12_F70_Loc8;


void fn_12_F70(arg0, arg1, arg2, arg3, arg4)
struct fn_12_F70_Arg0 *arg0;
struct fn_12_F70_Arg1 *arg1;
u32 arg2;
s32 arg3;
s32 arg4;
{
    fn_12_F70_Loc24 loc24;
    fn_12_F70_Loc8 loc8;
    s32 t;
    s32 flag;
    s32 var;

    flag = 0;
    var = 0;
    loc24.a[0] = arg1->unk_4;
    loc24.a[1] = arg1->unk_14;
    loc24.a[2] = arg1->unk_24;
    loc24.a[3] = arg1->unk_8;
    loc24.a[4] = arg1->unk_18;
    loc24.a[5] = arg1->unk_28;
    loc8.a[0] = arg2;
    loc8.a[1] = arg1->unk_44;

    switch (arg0->unk_4) {
    case 0x11:
    case 0x31:
    case 0x41:
    case 0xf1:
    case 0x1001:
        t = 0;
        break;
    case 0x21:
    case 0x101:
        t = 1;
        break;
    default:
        fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(void *)(lbl_12_rodata_60));
        t = 0;
        break;
    }

    if (t == 1) {
        loc8.a[2] = arg1->unk_48 / 2;
    } else {
        loc8.a[2] = arg1->unk_48;
    }

    if (arg0->unk_8 == 0) {
        loc8.a[3] = arg1->unk_8;
    } else {
        loc8.a[3] = arg0->unk_8;
    }

    if (arg0->unk_C == 0) {
        loc8.a[6] = arg1->unk_C;
    } else {
        loc8.a[6] = arg0->unk_C;
    }

    switch (fn_12_740( (MovieModule *)(struct fn_12_F70_Arg0 *)(arg0))) {
    case -1:
        var = 0;
        if (fn_12_49D8( (MovieState *)(struct fn_12_F70_Arg0 *)(arg0)) == 1) {
            if (fn_12_49AC(arg0) == 1) {
                if (fn_12_738( (struct MovieData *)(struct fn_12_F70_Arg0 *)(arg0)) == 0) {
                    var = 1;
                }
            }
        }
        break;
    case 0:
        var = 0;
        break;
    case 1:
        var = 1;
        break;
    default:
        var = 0;
        break;
    }

    if (var == 1) {
        loc8.a[4] = 2;
    } else {
        loc8.a[4] = 1;
    }

    if (arg3 == 1) {
        u32 x = arg0->unk_38;
        if (flag != 1) {
            fn_12_3C4A8(&loc24, &loc8, x);
        }
    } else {
        if (flag != 1) {
            fn_12_3C8CC(&loc24, &loc8);
        }
    }
}
/* fzgx:end fn_12_F70 */

/* fzgx:begin fn_12_11A8 */

void fn_12_11A8(Sig_fn_12_748_MovieModule *arg0, u32 arg1, void *arg2) {
    s32 temp_r0;
    s32 var_r0;
    s32 temp_r3;
    s32 var_r0_2;
    s32 temp_r3_2;

    temp_r0 = *(s32 *)((u8 *)(arg0) + 4);
    switch (temp_r0) {                              /* irregular */
    case 0x11:
        if (fn_12_748((Sig_fn_12_748_MovieModule *)(arg0)) != 1) {
            fn_12_F70((u32)((u32)(arg0)), (u32)(arg1), (void *)(arg2), (u32)(0U));
            return;
        }
        temp_r3 = *(s32 *)((u8 *)(arg0) + 52);
        var_r0 = 1;
        if (temp_r3 == 0x64) {
            var_r0 = 0;
        } else if (temp_r3 == 0x16) {
            var_r0 = 0;
        }
        if (var_r0 == 1) {
            (*(s32 *)((u8 *)(arg0) + 52)) = 0x16;
            fn_12_3D968( (void*)((u32)(*(u32 *)((u8 *)(arg0) + 56))));
        }
        fn_12_F70((u32)((u32)(arg0)), (u32)(arg1), (void *)(arg2), (u32)(1U));
        return;
    case 0x101:
        fn_12_F70((u32)((u32)(arg0)), (u32)(arg1), (void *)(arg2), (u32)(0U));
        return;
    case 0x1001:
        temp_r3_2 = *(s32 *)((u8 *)(arg0) + 52);
        var_r0_2 = 1;
        if (temp_r3_2 == 0x64) {
            var_r0_2 = 0;
        } else if (temp_r3_2 == 0x15) {
            var_r0_2 = 0;
        }
        if (var_r0_2 == 1) {
            (*(s32 *)((u8 *)(arg0) + 52)) = 0x15;
            fn_12_3D740( (void*)((u32)(*(u32 *)((u8 *)(arg0) + 56))));
        }
        fn_12_F70((u32)((u32)(arg0)), (u32)(arg1), (void *)(arg2), (u32)(1U));
        return;
    default:
    case 0x41:
    case 0xF1:
    case 0x21:
    case 0x31:
        fn_12_309C((u32)((u32)(arg0)), (u32)(arg1), (u32)((u32)(&lbl_12_rodata_28C)));
        return;
    }
}
/* fzgx:end fn_12_11A8 */

/* fzgx:begin fn_12_132C */

void fn_12_132C(void *arg0, void *arg1, void *arg2) {
    s32 value;
    value = *(s32 *)arg1;
    if (*(s32 *)((u8 *)arg0 + 4) == 0) {
        *(u32 *)((u8 *)arg0 + 4) = ((u32)fn_12_3074(arg1, lbl_12_rodata_C0));
    }
    switch (value) {
    case 3:
        fn_12_11A8( (Sig_fn_12_748_MovieModule *)(void *)(arg0), (u32)(void *)(arg1), arg2);
        break;
    case 2:
    default:
        fn_12_309C( (u32)(void *)(arg0), (u32)(void *)(arg1), (u32)(void *)(lbl_12_rodata_2BC));
        break;
    }
}
/* fzgx:end fn_12_132C */

/* fzgx:begin fn_12_13D0 */


void fn_12_13D0(u32 arg0, struct fn_12_13D0_Arg1 *arg1, u32 arg2) {
    u32 v0;
    u32 v1;
    s32 v2;
    u32 loc_C[1];
    u32 loc_8[1];

    v0 = arg1->unk_48;
    fn_12_8B4((void *)arg0, (void *)&loc_C, (void *)loc_8);
    v1 = *(u32 *)((u8 *)(u32)arg1 + 72);
    v2 = ((s32)(((u32)v0 >> 31) + v0) >> 1);
    *(u32 *)((u8 *)(u32)arg1 + 72) = ((s32)(((u32)v1 >> 31) + v1) >> 1);
    fn_12_68C((u32)arg1, v2);
    fn_12_132C( (void *)(u32)(arg0), (void *)((u32)arg1), (void *)(u32)(arg2));
    fn_12_68C((u32)arg1, v0);
    fn_12_6B8((u32)arg1, v2);
    fn_12_132C( (void *)(u32)(arg0), (void *)((u32)arg1), (void *)(u32)((arg2 + (loc_C[0] << 1))));
}
/* fzgx:end fn_12_13D0 */

/* fzgx:begin fn_12_147C noprologue */
#include "types.h"
/* WARNING: compiler-diff device, not original code: file-level use_lmw_stmw on (retail prologues use stmw/lmw; 21 of 296 movie_module files carry it, so it may be the vendor build setting of these Sofdec objects, circumstantial); without it 1330 dump lines */
#pragma use_lmw_stmw on
#pragma pool_data on
#pragma readonly_strings on
#pragma force_active on
#pragma force_active off

/* --- rel/movie_module/fn_12_147C.c --- */
typedef struct Sig_fn_12_740_MovieModule {
    u8 pad[0x60];
    int value;
} Sig_fn_12_740_MovieModule;

typedef struct Sig_fn_12_49D8_MovieState {
    u8 pad[0x58];
    s32 value;
} Sig_fn_12_49D8_MovieState;

struct Sig_fn_12_49AC_fn_12_49AC_Arg0 {
    u8 pad_0[0x58];
    u32 unk_58;
};

struct Sig_fn_12_738_MovieData {
    u8 pad[0x64];
    int value;
};

struct Sig_fn_12_13D0_fn_12_13D0_Arg1 {
    u8 pad_0[0x48];
    u32 unk_48;
};

extern s32 fn_12_307C(void);
extern int fn_12_740(Sig_fn_12_740_MovieModule *);
extern int fn_12_49D8(Sig_fn_12_49D8_MovieState *);
extern s32 fn_12_49AC(struct Sig_fn_12_49AC_fn_12_49AC_Arg0 *);
extern int fn_12_738(struct Sig_fn_12_738_MovieData *);
extern void fn_12_13D0(u32, struct Sig_fn_12_13D0_fn_12_13D0_Arg1 *, void *);
extern u32 fn_12_132C(u32, u32, void *);


void fn_12_147C(Sig_fn_12_740_MovieModule *arg0, struct Sig_fn_12_13D0_fn_12_13D0_Arg1 *arg1, void *arg2) {
    s32 temp_r3;
    s32 var_r31;

    if (fn_12_307C() == 0) {
        temp_r3 = fn_12_740((Sig_fn_12_740_MovieModule *)(arg0));
        switch (temp_r3) {                          /* irregular */
        case -1:
            var_r31 = 0;
            if ((fn_12_49D8((Sig_fn_12_49D8_MovieState *)((Sig_fn_12_49D8_MovieState *) arg0)) == 1) && (fn_12_49AC((struct Sig_fn_12_49AC_fn_12_49AC_Arg0 *)((struct Sig_fn_12_49AC_fn_12_49AC_Arg0 *) arg0)) == 1) && (fn_12_738((struct Sig_fn_12_738_MovieData *)((struct Sig_fn_12_738_MovieData *) arg0)) == 0)) {
                var_r31 = 1;
            }
            break;
        case 0:
            var_r31 = 0;
            break;
        case 1:
            var_r31 = 1;
            break;
        default:
            var_r31 = 0;
            break;
        }
        if (var_r31 == 1) {
            fn_12_13D0((u32)((u32)(arg0)), (struct Sig_fn_12_13D0_fn_12_13D0_Arg1 *)(arg1), (void *)(arg2));
            return;
        }
        goto block_16; /* Preserves the retail branch. */
    }
block_16:
    fn_12_132C((u32)((u32)(arg0)), (u32)((u32)(arg1)), (void *)(arg2));
}
/* fzgx:end fn_12_147C */

/* fzgx:begin fn_12_1578 noprologue */
/* --- rel/movie_module/fn_12_1578.c --- */
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
    u32 loc_C8[6];
    u32 loc_B0[6];
    u32 loc_98[6];
    u32 loc_80[6];
    u32 loc_68[6];
    u32 loc_50[6];
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
    loc_C8[0] = arg2;
    loc_C8[1] = v1;
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
    loc_C8[2] = ((s32)(((u32)v1 >> 31) + v1) >> 1);
    } else {
    loc_C8[2] = ((Sig_fn_12_1578_MovieData *)(arg1))->field48;
    }
    if ((s32)*(u32 *)((u8 *)arg0 + 8) == 0) {
    v5 = (*(u32 *)((u8 *)arg1 + 8) << 2);
    loc_C8[3] = v5;
    } else {
    loc_C8[3] = *(u32 *)((u8 *)arg0 + 8);
    }
    fn_12_3D730(loc_44, loc_C8);
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
    loc_B0[0] = arg2;
    loc_B0[1] = v1;
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
    loc_B0[2] = ((s32)(((u32)v1 >> 31) + v1) >> 1);
    } else {
    loc_B0[2] = ((Sig_fn_12_1578_MovieData *)(arg1))->field48;
    }
    if ((s32)*(u32 *)((u8 *)arg0 + 8) == 0) {
    v8 = (*(u32 *)((u8 *)arg1 + 8) << 2);
    loc_B0[3] = v8;
    } else {
    loc_B0[3] = *(u32 *)((u8 *)arg0 + 8);
    }
    fn_12_3D73C(loc_38, loc_B0, (void *)*(u32 *)((u8 *)arg0 + 56));
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
    loc_98[0] = arg2;
    loc_98[1] = v1;
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
    loc_98[2] = ((s32)(((u32)v1 >> 31) + v1) >> 1);
    } else {
    loc_98[2] = ((Sig_fn_12_1578_MovieData *)(arg1))->field48;
    }
    if ((s32)*(u32 *)((u8 *)arg0 + 8) == 0) {
    v11 = (*(u32 *)((u8 *)arg1 + 8) << 2);
    loc_98[3] = v11;
    } else {
    loc_98[3] = *(u32 *)((u8 *)arg0 + 8);
    }
    fn_12_3D73C(loc_2C, loc_98, (void *)*(u32 *)((u8 *)arg0 + 56));
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
    loc_80[0] = arg2;
    loc_80[1] = v1;
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
    loc_80[2] = ((s32)(((u32)v1 >> 31) + v1) >> 1);
    } else {
    loc_80[2] = ((Sig_fn_12_1578_MovieData *)(arg1))->field48;
    }
    if ((s32)*(u32 *)((u8 *)arg0 + 8) == 0) {
    v16 = (*(u32 *)((u8 *)arg1 + 8) << 2);
    loc_80[3] = v16;
    } else {
    loc_80[3] = *(u32 *)((u8 *)arg0 + 8);
    }
    fn_12_3D73C(loc_20, loc_80, (void *)*(u32 *)((u8 *)arg0 + 56));
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
    loc_68[0] = arg2;
    loc_68[1] = v1;
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
    loc_68[2] = ((s32)(((u32)v1 >> 31) + v1) >> 1);
    } else {
    loc_68[2] = ((Sig_fn_12_1578_MovieData *)(arg1))->field48;
    }
    if ((s32)*(u32 *)((u8 *)arg0 + 8) == 0) {
    v19 = (*(u32 *)((u8 *)arg1 + 8) << 2);
    loc_68[3] = v19;
    } else {
    loc_68[3] = *(u32 *)((u8 *)arg0 + 8);
    }
    fn_12_3D73C(loc_14, loc_68, (void *)*(u32 *)((u8 *)arg0 + 56));
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
    loc_50[0] = arg2;
    loc_50[1] = arg1->field44;
    loc_50[2] = arg1->field48 / 2;
    if ((s32)*(u32 *)((u8 *)arg0 + 8) == 0) {
    v43 = (*(u32 *)((u8 *)arg1 + 8) << 2);
    loc_50[3] = v43;
    } else {
    loc_50[3] = *(u32 *)((u8 *)arg0 + 8);
    }
    fn_12_3D730(loc_8, loc_50);
    loc_8[0] = ((Sig_fn_12_1578_MovieData *)(arg1))->value;
    v1 = arg1->field44;
    loc_8[1] = v1;
    v45 = ((Sig_fn_12_1578_MovieData *)(arg1))->field48;
    loc_8[2] = v45;
    loc_50[0] = arg2;
    loc_50[1] = v1;
    loc_50[2] = v45;
    if ((s32)*(u32 *)((u8 *)arg0 + 8) == 0) {
    v46 = (*(u32 *)((u8 *)arg1 + 8) << 2);
    loc_50[3] = v46;
    } else {
    loc_50[3] = *(u32 *)((u8 *)arg0 + 8);
    }
    fn_12_3D734(loc_8, loc_50, (void *)*(u32 *)((u8 *)arg0 + 56));
    break;
    default:
    case 241:
    case 257:
    v1 = (u32)(arg0);
    fn_12_309C(v1, (u32)arg1, (u32)"E201182: SFX_CnvToArgb8888 : compo is not support.");
    }
    }
}
/* fzgx:end fn_12_1578 */

/* fzgx:begin fn_12_1F84 */
// 0x00001F84..0x000023CC






void fn_12_1F84(MovieArg0 *arg0, MovieArg1 *arg1, s32 arg2)
{
    register s32 guard;
    MovieMatrix m2;
    MovieSource s2;
    MovieSource s1;
    MovieMatrix m;
    s32 flag;
    s32 half;
    s32 quarter;

    m.x = arg1->width;
    m.y = arg1->offset_x;
    m.z = arg1->step_x;
    m.width = arg1->height;
    m.height = arg1->offset_y;
    m.depth = arg1->step_y;

    s1.object = arg2;
    s1.field_04 = arg1->field_44;

    switch (arg0->format) {
    case 0x11:
    case 0x31:
    case 0x41:
    case 0xF1:
    case 0x1001:
        flag = 0;
        break;
    case 0x21:
    case 0x101:
        flag = 1;
        break;
    default:
        fn_12_309C(0, 0, (u32)(const char *)((((const char *)&lbl_12_rodata_60))));
        flag = 0;
        break;
    }

    if (flag == 1) {
        s1.field_08 = arg1->field_48 / 2;
    }
    else {
        s1.field_08 = arg1->field_48;
    }

    if (arg0->count == 0) {
        s1.field_0c = arg1->height * 4;
    }
    else {
        s1.field_0c = arg0->count;
    }

    guard = 0;
    (void) guard;  /* fzgx: keeps the web at its definition */
    if (arg1->field_74 == 1) {
        if (guard != 1) {
            fn_12_3D144(&m, &s1);
        }
    }
    else {
        if (guard != 1) {
            fn_12_3D144(&m, &s1);
        }
    }

    half = (arg1->height * arg1->depth) / 2;
    quarter = half;
    quarter /= 2;
    m2.x = arg1->width + half;
    m2.y = arg1->offset_x + quarter;
    m2.z = arg1->step_x + quarter;
    m2.width = arg1->height;
    m2.height = arg1->offset_y;
    m2.depth = arg1->step_y;

    s2.object = arg2;
    s2.field_04 = arg1->field_44;
    s2.field_08 = arg1->field_48 / 2;
    if (!(arg0->count)) {
        s2.field_0c = arg1->height * 4;
    }
    else {
        s2.field_0c = arg0->count;
    }

    if (((s32)fn_12_308C()) == 1) {
        fn_12_3DCF0( (const CFTYcc420Planar *)(MovieMatrix *)(&m2), (const CFTArgb8888Output *)(MovieSource *)(&s2), (const u8 *)(u32)(arg0->field_38));
    }
    else {
        fn_12_3DF08( (const CFTYcc420Planar *)(MovieMatrix *)(&m2), (const CFTArgb8888Output *)(MovieSource *)(&s2));
    }
}
/* fzgx:end fn_12_1F84 */

/* fzgx:begin fn_12_21C8 */
#pragma use_lmw_stmw on
#pragma pool_data on
#pragma readonly_strings on







#pragma force_active on
#pragma section code_type ".fzgxpool"
static f32 fzgx_pool_primer_before(s32 value) {
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E201312: sfxcnv_IsCnvUpHalf : compo is invalid."));
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E301282: CnvToRgb888 : compo is not support."));
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("COMPO"));
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E301281: SFX_CnvFrmRgb888 : frmfmt is not support."));
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E202281: SFX_MakeTblZ32 : zclip is not set."));
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E202282: SFX_MakeTblZ16 : zclip is not set."));
    return 1.164f * (f32)value;
}
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_after(void) {
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E201311: sfxcnv_MakeTable : compo is not support."));
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E201313: sfxcnv_CnvZbitToCft : zbit is invalid."));
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E201315: sfxcnv_CnvFrmZcmn : zclip is not set."));
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E201191: SFX_CnvFrmZcmn : frmfmt is not support."));
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E201192: CnvToY84C44 : compo is not support."));
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E201193: SFX_CnvFrmY84C44 : frmfmt is not support."));
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E201182: CnvToYuv422 : compo is not support."));
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E201183: SFX_CnvFrmYUV422 : frmfmt is not support."));
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E212182: CnvToArgb8888mb : compo is not support."));
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E212173: sfxcnv_CnvFrmYcc420mbToArgb8888mb() : compo is not support."));
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E212171: SFX_CnvFrmARGB8888Mb : function is not support."));
    fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E212172: SFX_CnvFrmMbARGB8888 : frmfmt is not support."));
}
#pragma section code_type ".text"
#pragma force_active off

static inline s32 sfxcnv_IsCnvUpHalf(SFXHandle *handle)
{
    switch (handle->stream_info) {
    case 0x11:
    case 0x31:
    case 0x41:
    case 0xF1:
    case 0x1001:
        return 0;
    case 0x21:
    case 0x101:
        return 1;
    default:
        fn_12_309C( (u32)(void *)(0), (u32)(void *)(0), (u32)(const char *)("E201312: sfxcnv_IsCnvUpHalf : compo is invalid."));
        return 0;
    }
}

static inline void SFX_MakeTable(SFXHandle *handle, SFXFrameInfo *frame, s32 compo)
{
    s32 cur = handle->table_compo;
    s32 make_table = 1;
    s32 i;
    u8 *table;

    if (cur == 100) {
        make_table = 0;
    } else if (cur == compo) {
        switch (compo) {
        case 2:
            if (fn_12_34DC(handle->alpha) != 1) {
                make_table = 0;
            }
            break;
        default:
            make_table = 0;
            break;
        }
    }

    if (make_table != 1) {
        return;
    }

    handle->table_compo = compo;
    switch (compo) {
    case 2:
        fn_12_3508(handle->alpha, frame->color_adjustment, handle->work_0);
        break;
    case 3:
        fn_12_34E4(handle->alpha, (void *)(s32)(frame->color_adjustment), handle->work_0);
        break;
    case 0x15:
        fn_12_3D740(handle->work_0);
        break;
    case 1:
        table = handle->work_0;
        for (i = 0; i <= 15; i++) {
            table[i] = 0;
        }
        for (i = 16; i <= 235; i++) {
            table[i] = 1.164f * (i - 16);
        }
        for (i = 236; i <= 255; i++) {
            table[i] = 255;
        }
        break;
    }
}

static inline void sfxcnv_CnvNormalYcc420plnToArgb8888(SFXHandle *handle, SFXFrameInfo *frame, void *output, s32 use_table)
{
    CFTYcc420Planar source;
    CFTArgb8888Output destination;
    void *table;
    s32 err;

    source.y = frame->y.pixels;
    source.cb = frame->cb.pixels;
    source.cr = frame->cr.pixels;
    source.y_stride = frame->y.width;
    source.cb_stride = frame->cb.width;
    source.cr_stride = frame->cr.width;

    destination.plane.pixels = output;
    destination.plane.width = frame->field_44;
    if (sfxcnv_IsCnvUpHalf(handle) == 1) {
        destination.plane.height = frame->field_48 / 2;
    } else {
        destination.plane.height = frame->field_48;
    }

    if (handle->field_count == 0) {
        destination.plane.pitch = frame->y.width * 4;
    } else {
        destination.plane.pitch = handle->field_count;
    }

    err = 0;
    if (use_table == 1) {
        table = handle->work_0;
    } else {
        table = 0;
    }

    if (frame->field_74 == 1) {
        if (table != 0) {
            if (err != 1) {
                fn_12_3CB74(&source, &destination, table);
            }
        } else {
            if (err != 1) {
                fn_12_3D144( (MovieMatrix *)(CFTYcc420Planar *)(&source), (MovieSource *)(CFTArgb8888Output *)(&destination));
            }
        }
    } else {
        if (table != 0) {
            if (err != 1) {
                fn_12_3CB74(&source, &destination, table);
            }
        } else {
            if (err != 1) {
                fn_12_3D144( (MovieMatrix *)(CFTYcc420Planar *)(&source), (MovieSource *)(CFTArgb8888Output *)(&destination));
            }
        }
    }
}

void fn_12_21C8(SFXHandle *handle, SFXFrameInfo *frame, void *output)
{
    switch (handle->stream_info) {
    case 0x11:
        if (fn_12_748( (Sig_fn_12_748_MovieModule *)(SFXHandle *)(handle)) != 1) {
            sfxcnv_CnvNormalYcc420plnToArgb8888(handle, frame, output, 0);
            break;
        }
        SFX_MakeTable(handle, frame, 0x15);
        sfxcnv_CnvNormalYcc420plnToArgb8888(handle, frame, output, 1);
        break;
    case 0x101:
        sfxcnv_CnvNormalYcc420plnToArgb8888(handle, frame, output, 0);
        break;
    case 0xF1:
        fn_12_3E09C(frame->y.pixels, output, frame->y.width, frame->y.height);
        break;
    case 0x21:
        SFX_MakeTable(handle, frame, 1);
        fn_12_1F84( (MovieArg0 *)(SFXHandle *)(handle), (MovieArg1 *)(SFXFrameInfo *)(frame), (s32)(void *)(output));
        break;
    case 0x31:
        SFX_MakeTable(handle, frame, 2);
        sfxcnv_CnvNormalYcc420plnToArgb8888(handle, frame, output, 1);
        break;
    case 0x41:
        SFX_MakeTable(handle, frame, 3);
        sfxcnv_CnvNormalYcc420plnToArgb8888(handle, frame, output, 1);
        break;
    case 0x1001:
        SFX_MakeTable(handle, frame, 0x15);
        sfxcnv_CnvNormalYcc420plnToArgb8888(handle, frame, output, 1);
        break;
    default:
        fn_12_309C( (u32)(void *)(handle), (u32)(void *)(frame), (u32)(const char *)("E201182: CnvToArgb8888 : compo is not support."));
        break;
    }
}
/* fzgx:end fn_12_21C8 */

/* fzgx:begin fn_12_2F04 */





void fn_12_2F04(state, data, arg)
MovieState *state;
MovieData *data;
int arg;
{
    int value;
    char *pool;
    MovieArgs local1;
    MovieArgs local0;

    pool = (char *)lbl_12_rodata_60;
    value = data->mode;
    if (state->value == 0) {
        state->value = fn_12_3074(data, pool + 0x60);
    }

    switch (value) {
    case 3:
        fn_12_21C8( (SFXHandle *)(MovieState *)(state), (SFXFrameInfo *)(MovieData *)(data), (void *)(int)(arg));
        break;
    case 1:
        fn_12_1578(state, data, arg);
        break;
    case 2:
        switch (state->value) {
        case 0x11:
            break;
        case 0x21:
            local0.a = data->value;
            local0.b = data->field44;
            local0.c = data->field48;
            local1.a = arg;
            local1.b = data->field44;
            local1.c = data->field48;
            fn_12_3D738(&local0, &local1);
            break;
        case 0x31:
        case 0x41:
        case 0xf1:
        case 0x101:
        case 0x1001:
        default:
            fn_12_309C( (u32)(MovieState *)(state), (u32)(MovieData *)(data), (u32)(void *)(pool + 0x380));
            break;
        }
        break;
    default:
        fn_12_309C( (u32)(MovieState *)(state), (u32)(MovieData *)(data), (u32)(void *)(pool + 0x3b0));
        break;
    }
}
/* fzgx:end fn_12_2F04 */

/* fzgx:begin fn_12_3054 */
/* --- rel/movie_module/fn_12_3054.c --- */
/* --- rel/movie_module/fn_12_3054.c --- */

void fn_12_3054(void) {
    fn_12_2F04();
}
/* fzgx:end fn_12_3054 */
