/* Previously matched Japan/PAL units of driver.c, retained until that TU matches those releases as one unit. */
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/driver.h"
#include "rel/main_rel/prog.h"
#include "psvec.h"
#include "rel/main_rel/car.h"
#include "dolphin/hw_regs.h"








struct fn_1_A7F84_lbl_801A6D00 {
    u32 unk_0;
};

struct fn_1_A7F84_lbl_1_rodata_4A28 {
    f32 unk_0;
};

typedef struct FnA8528Config {
    u8 pad_0c[0x0c];
    f32 unk_0c;
    u8 pad_10[0x0c];
    f32 unk_1c;
    u8 pad_20[0x0c];
    f32 unk_2c;
} FnA8528Config;

struct fn_1_A9868_lbl_1_rodata_4AA0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    f32 unk_30;
};

struct FzgxCopy_88 { u32 words[22]; };

typedef struct FnA861CVehicle {
    u8 pad_0[8];
    f32 unk_8;
    u8 pad_c[0xa4 - 0xc];
    f32 unk_a4;
    u8 pad_a8[0xb0 - 0xa8];
    f32 unk_b0;
    u8 pad_b4[0xb8 - 0xb4];
    f32 unk_b8;
    u8 pad_bc[0xc0 - 0xbc];
    f32 unk_c0;
} FnA861CVehicle;

typedef struct Sig_fn_1_41488_Fn41488Data {
    u32 count;
    char *strings;
} Sig_fn_1_41488_Fn41488Data;

struct Sig_fn_800737E4_fn_800737E4_Arg0 {
    f32 unk_0;
    u8 pad_4[0x4];
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x4];
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    u8 pad_20[0x8];
    f32 unk_28;
    f32 unk_2C;
};

typedef struct {
    u8 kind;
    u8 callback;
    u8 flags;
    u8 pad3;
    s16 x;
    s16 y;
    s16 z;
    s16 padA;
    void *data;
} Fn1A9250Entry;

typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
} DriverAsset;

typedef struct FnA8834Camera {
    u8 pad_0[0x90];
    u8 unk_90[0x48];
    f32 unk_d8;
    f32 unk_dc;
    u8 pad_e0[4];
    f32 unk_e4;
    u8 pad_e8[0x18c - 0xe8];
    u8 unk_18c[4];
} FnA8834Camera;

struct Sig_fn_80077B64_fn_80077B64_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

typedef struct FnA8834Vehicle {
    u8 pad_0[8];
    f32 unk_8;
    u8 pad_c[0xa4 - 0xc];
    f32 unk_a4;
    u8 pad_a8[0xb0 - 0xa8];
    f32 unk_b0;
    u8 pad_b4[0xc0 - 0xb4];
    f32 unk_c0;
    u8 pad_c4[0x1fc - 0xc4];
    f32 unk_1fc;
} FnA8834Vehicle;

struct fn_1_A9868_lbl_801A6D00 {
    u32 unk_0;
};

struct Sig_fn_80077B14_fn_80077B14_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x18];
    u32 unk_20;
};

typedef struct {
    signed char gpr;
    signed char fpr;
    unsigned short reserved;
    char *input_arg_area;
    char *reg_save_area;
} Sig_parse_format_MkVaListState;

typedef struct Sig_fn_80015EE8_Fn80015EE8Out {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;
    f32 f5;
    f32 f6;
    f32 f7;
    f32 f8;
    f32 f9;
    f32 f10;
    f32 f11;
    f32 f12;
    f32 f13;
    f32 f14;
    f32 f15;
} Sig_fn_80015EE8_Fn80015EE8Out;

typedef struct FnA861CCamera {
    u8 pad_0[0xdc];
    f32 yaw;      /* 0xdc */
    f32 roll;     /* 0xe0 */
    f32 pitch;    /* 0xe4 */
    u8 unk_e8;
    u8 unk_e9;
    u8 pad_ea[0x15c - 0xea];
    u8 unk_15c[4];
} FnA861CCamera;

typedef union {
    u8 u8;
    f32 f32;
} PPCWGPipe;

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} GXColor;

typedef struct FnA7E60Object {
    u8 pad_fc[0xfc];
    s32 unk_fc;
    s32 unk_100;
    s32 unk_104;
    void *unk_108;
} FnA7E60Object;

typedef struct Resource {
    u8 pad_0[8];
    void *unk_8;
} Resource;

typedef struct {
    u8 pad_0[0x8];
    void *unk_8;
    u8 pad_C[0x4];
    u32 unk_10;
} Fn1A75dcResult;

struct fn_1_A8270_Entry {
	u32 unk_0;
	u32 unk_4;
	u32 unk_8;
	u8 pad_C[0x18];
};

struct fn_1_A8270_Arg0 {
	u8 pad_0[0xE8];
	u8 unk_E8;
	u8 unk_E9;
	s16 unk_EA;
	s16 unk_EC;
	s16 unk_EE;
	void *unk_F0;
	u8 pad_F4[8];
	struct fn_1_A8270_Entry *unk_FC;
	s32 unk_100;
	u32 unk_104;
	u8 pad_108[0x24];
	u32 *unk_12C[12];
};

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_A7E60_Vec3;

typedef struct {
    u32 w[45];
} Unk_23800000;

typedef struct {
    u8 pad_00[0x1C];
    u16 unk_1C;
} Sig_fn_1_55628_Fn1_55628Object;

struct fn_1_A8270_Rec {
	u8 pad_0[4];
	u32 unk_4;
	u8 pad_8[0x16];
	u8 count;
};

typedef struct fn_1_8D210_car {
    f32 position[6];
    f32 scale_z;
    f32 scale_y;
    f32 scale_x;
    f32 field_24;
    u16 field_28;
    u16 field_2a;
    u16 field_2c;
    u16 field_2e;
    u16 field_30;
    u16 field_32;
    u32 field_34;
    u8 field_38;
    u8 field_39;
    u8 field_3a;
    u8 pad_3b;
    u32 field_3c;
    u8 field_40;
    u8 pad_41[3];
    f32 field_44;
    f32 field_48;
    f32 field_4c;
    f32 field_50;
    s16 field_54;
    u8 pad_56[2];
    s32 field_58;
    u8 field_5c[4];
    u32 field_60;
} fn_1_8D210_car;

typedef s32 (*fn_1_8D210_callback)(u32);

typedef struct {
    u8 pad[0x15];
    u8 code;
} State;

typedef struct {
    u8 pad[4];
    State *state;
} fn_1_8E3A4_Object;

struct Sig_fn_800713E0_fn_800713E0_Entry {
    u8 pad_0[0x18];
    u16 count;
};

struct Sig_fn_800713E0_fn_800713E0_Arg0 {
    s32 count;
    u8 pad_4[0x4];
    struct Sig_fn_800713E0_fn_800713E0_Entry **entries;
};

typedef struct Fn195158Object Fn195158Object;

struct Fn195158Object {
    u8 unk_00[0x0C];
    f32 unk_0C;
    u8 unk_10[0x1C];
    f32 unk_2C;
    u8 unk_30[0x58];
    u8 unk_88[0x04];
};

typedef struct Fn195158Data Fn195158Data;

struct Fn195158Data {
    u8 unk_00[0x08];
    Fn195158Object *unk_08;
};

typedef struct Fn195158Car Fn195158Car;

struct Fn195158Car {
    u8 unk_00[0xA0];
    s16 unk_A0;
    s16 unk_A2;
    s16 unk_A4;
    u8 unk_A6[0x02];
    f32 unk_A8;
    f32 unk_AC;
    f32 unk_B0;
    f32 unk_B4;
    f32 unk_B8;
    u8 unk_BC[0x94];
    Fn195158Data *unk_150;
};

typedef struct {
    u8 pad0[0x12];
    u16 field_12;
    u8 pad14[0x12];
    u8 field_26;
    void *field_28;
    u8 pad2c[0x8];
    void *field_34;
    u8 pad38[0x14];
    u8 field_4c;
} EventNode;

typedef struct {
    u8 pad0[0x1c];
    void *field_1c;
} CarObject;

typedef f32 fzgx_Mtx[3][4];

typedef struct Fn1967A8Resource Fn1967A8Resource;

struct Fn1967A8Resource {
    u8 unk_00;
    u8 unk_01[0x07];
    u32 unk_08;
    u8 unk_0C[0x10];
    u32 unk_1C;
};

typedef struct Fn196968Object Fn196968Object;

struct Fn196968Object {
    u8 unk_00[0x28];
    u32 unk_28;
    u8 unk_2C[0x144];
    void *unk_170;
    void *unk_174;
};

typedef struct Fn1969E8Owner Fn1969E8Owner;

struct Fn1969E8Owner {
    u8 unk_00[0x2C];
    u32 unk_2c;
    u8 unk_30[0x180];
    u32 unk_1b0;
    void *unk_1b4;
};

typedef struct Fn196BC0Object Fn196BC0Object;

struct Fn196BC0Object {
    u8 unk_00[0x30];
    void *value_30;
    u8 unk_34[0x19C];
    void *resource_1D0;
    void *resource_1D4;
};

typedef struct Fn196A68Object Fn196A68Object;

struct Fn196A68Object {
    u8 unk_00[0x34];
    u32 unk_34;
    u8 unk_38[0x1B8];
    void *unk_1F0;
    void *unk_1F4;
};

typedef struct CarR29 {
    u8 unk_00[0x14];
    f32 unk_14;
} CarR29;

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Triple;

typedef struct {
    u8 **unk_00;
    void *unk_04;
    u32 pad_08;
} Fn1_87448_Slot;

typedef struct {
    u8 pad_00[0x330];
    u32 unk_330;
    Fn1_87448_Slot unk_334[1];
} Fn1_87448_Obj;

typedef struct {
    u8 pad_00[2];
    s8 unk_02;
} Fn1_87448_Arg1;

typedef struct {
    u8 pad_0[0x4];
    s32 field_4;
    s32 field_8;
    s32 field_c;
    s32 field_10;
    s32 field_14;
} Fn1_8F45C_Object;

typedef struct {
    s32 active;
    s32 entries[5];
} Fn1_8F494_Object;

typedef struct {
    u8 pad_0[0x148];
    u8 pad_148[0x20];
    u8 pad_168[0x40];
    u8 pad_1a8[0x20];
    u8 pad_1c8[0x20];
    u8 pad_1e8[0x20];
    u8 entries[0x14][0x20];
} Fn1_8F5A4_Object;

typedef struct Fn935E4Slot {
    u8 pad0[0xa];
    u16 field_a;
} Fn935E4Slot;

typedef struct Fn935E4Node {
    u8 pad0[0xa];
    u16 field_a;
    u8 pad_c[6];
    u16 field_12;
    u8 pad14[0x12];
    u8 field_26;
    u8 pad27[1];
    Fn935E4Slot *field_28;
    u8 pad2c[8];
    Fn935E4Slot *field_34;
    u8 pad38[0x14];
    u8 field_4c;
} Fn935E4Node;

typedef struct Fn935E4Car {
    u8 pad0[0x1c];
    Fn935E4Node *field_1c;
} Fn935E4Car;

typedef struct A7B5C_Mtx {
u8 pad[0x30];
} A7B5C_Mtx;

typedef struct fn_1_A7B5C_Vec3 {
f32 x;
f32 y;
f32 z;
} fn_1_A7B5C_Vec3;

typedef struct A7B5C_Obj {
A7B5C_Mtx mtx[4];
f32 unk_c0;
f32 unk_c4;
f32 unk_c8;
f32 unk_cc;
f32 unk_d0;
f32 unk_d4;
f32 unk_d8;
f32 unk_dc;
f32 unk_e0;
f32 unk_e4;
s8 unk_e8;
u8 unk_e9;
u8 pad_ea[0x10c - 0xea];
f32 unk_10c;
f32 unk_110;
fn_1_A7B5C_Vec3 unk_114;
f32 unk_120;
f32 unk_124;
f32 unk_128;
A7B5C_Mtx parts[10];
} A7B5C_Obj;

typedef struct A7B5C_Src {
u8 pad[8];
u8 *data;
} A7B5C_Src;

typedef struct { f32 x, y, z; } fzgx_Vec;

typedef struct fn_1_A89B0_Obj {
    fzgx_Mtx mtx;           /* 0x000 */
    fzgx_Vec pos[2][4];     /* 0x030, 0x060 */
    u8 pad_90[0xC0 - 0x90];
    fzgx_Vec ofs[2];        /* 0x0C0, 0x0CC */
    u8 pad_d8[0x10C - 0xD8];
    f32 len1;               /* 0x10C */
    f32 len2;               /* 0x110 */
    u8 pad_114[0x12C - 0x114];
    fzgx_Mtx joints[7];     /* 0x12C */
} fn_1_A89B0_Obj;

typedef struct fn_1_A89B0_Arg1 {
    u8 pad_0[0x1FC];
    f32 unk_1FC;
} fn_1_A89B0_Arg1;

typedef struct {
    u8 pad_0[4];
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[0x32];
} fn_1_A948C_Font;

typedef struct DriverDesc {
    u8 pad_0[0x40];
    u32 unk_40;
    s32 unk_44;
    u32 unk_48;
} DriverDesc;

typedef Sig_parse_format_MkVaListState Sig_parse_format_va_list;

typedef void (*VIRetraceCallback)(u32 retraceCount);

typedef struct RelModule {
    void *module;
    void *bss;
} RelModule;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;
extern VIRetraceCallback fn_8001A78C(VIRetraceCallback callback);
extern VIRetraceCallback fn_8001A7D0(VIRetraceCallback callback);
extern void fn_1_3920(void);
extern char *strcpy(char *dst, const char *src);
extern size_t strlen(const char *str);
extern u32 fn_1_451C(void);
extern int sprintf(char *buffer, const char *format, ...);
extern void fn_1_A5AA0(const char *path, RelModule *rel);
extern void fn_1_A5C98(RelModule *rel);
extern s16 fn_1_12C930(s16 arg0);
extern s16 fn_1_12CCB0(s16 arg0, s16 arg1);
extern void *fn_1_14DD68(void *arg0);
extern u32 fn_1_4630();
extern void fn_1_A7E60(s8 arg0, s8 arg1, FnA7E60Object *object, s32 arg3, void *arg4);
extern void *lbl_801A6410;
extern void *fn_1_D3884(void *name);
extern void fn_80006E10(const char *path);
extern u32 fn_80077D40();
extern u32 fn_80071470(u32, u32);
extern void fn_80008BA8(void *dst, void *src, u32 size);
extern void fn_80071718(void *value);
extern void fn_1_A8270(struct fn_1_A8270_Arg0 *self, s32 arg1);
extern void fn_1_A8528(void *arg0, void *arg1);
extern void fn_1_A7F84(void *arg0, u32 arg1);
extern void lbl_8006DD14(void *, void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *arg0);
extern void lbl_8006DD7C(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DFC4(void *pos);
extern void lbl_8006DB30(void);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_800711A8(void *value);
extern void OSReport(const char *msg, ...);
extern void lbl_8006E0A4(void *arg0);
extern void lbl_8006E0B4(f32, f32, f32);
extern void fn_1_556B8(void *value);
extern void fn_80072558(void);
extern void fn_1_A8DD4(const char *format, ...);
extern void fn_1_A8F40(u8 arg0);
extern FnA8528Config *lbl_801A6D00;
extern u32 mathutil_mtxA_rotate_y(u32);
extern void mathutil_mtxA_rotate_z(s32);
extern void lbl_8006D758(void);
extern void lbl_8006E14C(f32);
extern void mathutil_mtxA_rotate_x(u32);
extern void fn_1_12AB38(void *arg0);
extern CarR29 *fn_80071268(void *, void *);
extern void lbl_8006E1F0(void *, f32, f32, f32);
extern void *fn_1_12AC00(void *arg0);
extern void fn_1_12A2B8(u32 value);
extern void fn_1_12A2D0(s32 value);
extern s32 fn_1_12ADA0(void *arg0, void *arg1);
extern void fn_1_12A2C4(u32 value);
extern void fn_1_A7B5C(A7B5C_Obj *obj, A7B5C_Src *src, s8 kind, s8 type, fn_1_A7B5C_Vec3 *pos);
extern struct fn_1_A7F84_lbl_1_rodata_4A28 lbl_1_rodata_4A28;
extern u32 lbl_8006D91C(u32);
extern u32 lbl_8006D998(u32);
extern u32 fn_80077A18(void);
extern void lbl_8006D9D8(void *);
extern void fn_80077A20(struct fn_1_A8270_Rec *, void *);
extern void fn_1_55FC4(f32 scale);
extern f32 lbl_1_rodata_4A34[25];
extern Fn1A9250Entry lbl_1_bss_70658[];
extern void fn_1_A861C(FnA861CCamera *cam, FnA861CVehicle *veh);
extern void fn_1_A8834(FnA8834Camera *cam, FnA8834Vehicle *veh);
extern void fn_1_A9420(u8 value);
extern s32 fn_8008077C(u32 arg0, u32 arg1, u32 arg2);
extern int fn_1_A948C(const char *str);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16 index);
extern void fn_1_520A0(void);
extern void fn_1_52088(void);
extern u32 lbl_1_bss_71658[6];
extern void fn_1_49714(f32 value1, f32 value2, f32 value3);
extern void fn_1_49680(f32 value1, f32 value2);
extern void fn_1_A93C4(u32 arg0);
extern void fn_1_4A0D8(const char *s);
extern void fn_1_520CC(void);
extern void fn_1_49514(u32 *value);
extern void fn_8006F6A8(void *arg0);
extern void fn_1_A89B0(fn_1_A89B0_Obj *obj, fn_1_A89B0_Arg1 *arg1, s32 side);
extern void fn_1_A943C(u32 arg0, u32 arg1);
extern void fn_1_A9464(u16 arg0, u16 arg1);
extern void fn_1_A942C(u8 value);
extern void fn_1_A96BC(void);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006D668(void *);
extern void fn_1_44884(Vec3 *dir);
extern fn_1_A948C_Font lbl_1_data_1AEA8[];
extern char *strchr(const char *str, int c);
extern char *strrchr(const char *str, int c);

/* fzgx:begin fn_1_A8D4C */
u32 lbl_1_bss_6F640;

void fn_1_A8D4C(u32 retraceCount) {
    lbl_1_bss_6F640 += 1;
}
/* fzgx:end fn_1_A8D4C */

/* fzgx:begin fn_1_A8D64 */
void fn_1_A8D64(u32 retraceCount) {
    fn_1_3920();
}
/* fzgx:end fn_1_A8D64 */

/* fzgx:begin fn_1_A8D84 */
void fn_1_A8D84(void) {
    lbl_1_bss_6F640 = 0;
    fn_8001A78C(fn_1_A8D4C);
    fn_8001A7D0(fn_1_A8D64);
}
/* fzgx:end fn_1_A8D84 */

/* fzgx:begin fn_1_A8DC4 */
// Returns the current driver state handle.
u32 fn_1_A8DC4(void) {
    return lbl_1_bss_6F640;
}
/* fzgx:end fn_1_A8DC4 */

/* fzgx:begin fn_1_A8DD4 */
void fn_1_A8DD4(const char *format, ...) {
    char buffer[0x200];
    Sig_parse_format_va_list args;

    fn_1_A9420(0);
    __builtin_va_info(&args);
    fn_8008077C((u32)buffer, (u32)(format), (u32)(Sig_parse_format_va_list *)(&args));
    fn_1_A948C(buffer);
}
/* fzgx:end fn_1_A8DD4 */

/* fzgx:begin fn_1_A8E78 */
// fn_1_A8E78: Take an argument, call fn_1_A9420(0), then fn_1_A948C with original arg.

void fn_1_A8E78(int arg) {
    fn_1_A9420(0);
    fn_1_A948C( (const char *)(arg));
}
/* fzgx:end fn_1_A8E78 */

/* fzgx:begin fn_1_A8EB0 */
void fn_1_A8EB0(int arg0, int arg1) {
    fn_1_A9420(0);
    fn_1_A943C(arg0, arg1);
}
/* fzgx:end fn_1_A8EB0 */

/* fzgx:begin fn_1_A8EF8 */
// Reset the current selection before applying the two provided values.
void fn_1_A8EF8(u16 arg0, u16 arg1) {
    fn_1_A9420(0);
    fn_1_A9464(arg0, arg1);
}
/* fzgx:end fn_1_A8EF8 */

/* fzgx:begin fn_1_A8F40 */
// Reset the mode before forwarding the supplied value.
void fn_1_A8F40(u8 arg0) {
    fn_1_A9420(0);
    fn_1_A942C(arg0);
}
/* fzgx:end fn_1_A8F40 */

/* fzgx:begin fn_1_A8F78 */
void fn_1_A8F78(void) {
    fn_1_A9420(0);
    fn_1_A96BC();
}
/* fzgx:end fn_1_A8F78 */
