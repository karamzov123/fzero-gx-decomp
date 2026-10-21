#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"




typedef struct {
    u8 pad0[0x1c];
    void *field_1c;
} CarObject;

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
    u8 pad0[0x24];
    void *field_24;
} EventData;

typedef struct {
    u8 pad0[0x8];
    EventData *field_8;
    void *field_c;
} EventObject;

struct fn_1_7F954_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_7FA04_lbl_801A6410 {
    u32 unk_0;
};

typedef struct {
    u8 pad0[0x40];
    void *value;
} ResourceHolder;

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} RawVec3;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    u8 _pad_000[0x7c];
    Vec3 field_07c;
    u8 _pad_088[0xc4];
    Vec3 field_14c;
} Fn184644Object;

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Triple;

typedef struct Fn195158Object Fn195158Object;

struct Fn195158Object {
    u8 unk_00[0x0C];
    f32 unk_0C;
    u8 unk_10[0x1C];
    f32 unk_2C;
    u8 unk_30[0x58];
    u8 unk_88[0x04];
};

struct TargetObj {
    char pad[0x60];
    char field_0x60[0xc];
    f32 field_0x6c;
    char pad2[0xc];
    f32 field_0x7c;
};

struct ModelItem {
    u32 flags;
    char pad[0x1c];
};

struct Model {
    char pad[0x18];
    u16 count;
    char pad2[0x26];
    struct ModelItem items[1];
};

typedef struct {
    u32 entries[41];
} FnTable;

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

typedef struct {
    u8 pad0[0x12];
    u16 field_12;
    u8 pad14[0x12];
    u8 field_26;
    void *field_28;
    u8 pad2c[8];
    void *field_34;
    u8 pad38[0x14];
    u8 field_4c;
} Node;

typedef struct Fn935E4Car {
    u8 pad0[0x1c];
    Fn935E4Node *field_1c;
} Fn935E4Car;

typedef struct {
    u8 pad0[0x24];
    void *field_24;
    f32 field_28;
    f32 field_2c;
} OutData;

typedef struct {
    u8 pad0[0x1c];
    Node *field_1c;
    u8 pad20[0x128];
    u16 field_148;
    u8 pad14a[6];
    OutData *field_150;
    void *field_154;
} Owner;

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

typedef struct Sig_fn_1_41418_Fn41418Data {
    u32 count;
    char *strings;
} Sig_fn_1_41418_Fn41418Data;

typedef struct {
    u32 w[45];
} Unk_23800000;

typedef struct {
    u8 pad_00[0x1C];
    u16 unk_1C;
} Sig_fn_1_55628_Fn1_55628Object;

typedef struct fn_1_8D988_CarObject { u8 pad_0[0x40]; void *unk_40; } fn_1_8D988_CarObject;

typedef struct fn_1_8D988_Car {
    u32 unk_0; s16 unk_4; u8 pad_6[0x46e]; s8 unk_474; u8 pad_475[0xf];
    fn_1_8D988_CarObject *unk_484; u8 pad_488[0x86]; u8 unk_50e; u8 pad_50f[0x111];
} fn_1_8D988_Car;

struct Sig_fn_800713E0_fn_800713E0_Entry {
    u8 pad_0[0x18];
    u16 count;
};

struct Sig_fn_800713E0_fn_800713E0_Arg0 {
    s32 count;
    u8 pad_4[0x4];
    struct Sig_fn_800713E0_fn_800713E0_Entry **entries;
};

typedef struct Sig_fn_1_97174_Fn197174Owner Sig_fn_1_97174_Fn197174Owner;

struct Sig_fn_1_97174_Fn197174Owner {
    u8 unk_00[0x14];
    u8 *base;
};

typedef struct fn_1_95238_lbl_801A6D00 {
    u32 unk_0;
} fn_1_95238_lbl_801A6D00;

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
extern void fn_1_801F8(s16 arg0, void *arg1);
extern s32 fn_1_46C70();
extern s32 fn_1_465D0(s32 arg0, s32 arg1);
extern char *fn_80083DB0(char *dst, const char *src);
extern void fn_80006E10(u32 arg0);
extern int sprintf(char *s, const char *format, ...);
extern Unk_23800000 lbl_23800000[];
extern u8* fn_1_36AD0();
extern void fn_1_14F6F8(u8 arg0, u8 arg1, u8 arg2, void *arg3);
extern u32 lbl_801A6410;
extern void fn_1_56858(void *, int);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_12A734(s32 value);
extern void fn_1_7F658(void *arg0);
extern void fn_1_591A0(s32 id);
extern void fn_1_8E1E8(void);
extern void fn_1_FDFF4(void);
extern u32 fn_80071718(u32);
extern void fn_800711A8(u32 value);
extern void _savegpr_27(void);
extern void _restgpr_27(void);
extern void OSReport(const char *format, ...);
extern f32 lbl_1_rodata_3508[];
extern int fn_1_20A5C(f32 *, f32 *);
extern void *fn_1_21644(void *arg0, f32 *arg1, void *arg2);
extern u8 * fn_1_14F04(void);
extern void fn_1_17920(int, int, f32);
extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006DBAC(Vec3 *a);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E0B4(f32 arg0, f32 arg1, f32 arg2);
extern void fn_1_892FC(void *arg0, int arg1, int arg2);
extern void fn_1_23500();
extern f32 lbl_1_rodata_3518[6];
extern f32 lbl_1_rodata_3530[22];
extern u32 lbl_8006DBE4(void);
extern void lbl_8006DFC4(void *arg0);
extern u8 *fn_80083970(u8 *str, const u8 *needle);
extern void fn_1_55628(Sig_fn_1_55628_Fn1_55628Object *);
extern void fn_1_556B8(void *value);
extern void fn_1_55FF0(f32 value);
extern void fn_80072558(void);
extern u32 fn_800793D4(u8 *arg0, u32 arg1, u32 arg2);
extern void fn_1_8B9B8(void *);
extern s32 fn_1_8D210(fn_1_8D210_car *car, fn_1_8D210_callback callback, u32 arg, s32 enable);
extern s32 fn_1_F7BE4();
extern u8 lbl_1_rodata_3D34[164];
extern s32 fn_1_45D0();
extern void fn_1_C487C();
extern void fn_1_43E8(u32 arg0);
extern void fn_1_C4ABC(void);
extern s32 fn_1_3F8C(u32 arg3, u32 arg0, u32 arg1, u32 index);
extern void fn_1_43F4(void);
extern void fn_1_8E3A4(fn_1_8E3A4_Object *obj);
extern u32 fn_80074A7C(u32 arg0);
extern void fn_800713E0(struct Sig_fn_800713E0_fn_800713E0_Arg0 *, u32);
extern void fn_1_A8DD4(const char *format, ...);
extern void fn_1_A8F40(u8 arg0);
extern s32 fn_1_41418(void *resource, u16 id);
extern void fn_1_95210(void *arg0);
extern void fn_1_95158(Fn195158Car *car);
extern s32 fn_1_97174(EventNode *arg0, s32 arg1, void *arg2);
extern void fn_1_93734(u32, u32);
extern void fn_1_4270C(void *arg0, s32 arg1, u32 arg2);
extern const f32 lbl_1_rodata_3F6C;
extern u8 *lbl_801A6D00;
extern void mathutil_mtxA_rotate_y(int value);
extern void mathutil_mtxA_rotate_z(int value);
extern void lbl_8006D758(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006E14C(f32 arg0);
extern void mathutil_mtxA_rotate_x(s16 arg0);
extern void fn_1_12AB38(void *arg0);
extern s32 fn_1_12A8A4(u32 arg0, void *arg1);
extern u32 lbl_1_bss_6E98C;
extern void fn_1_96AE8(void *base, void *arg1);
extern Fn1967A8Resource *fn_1_41518(void *arg0);
extern void fn_1_41C18(Fn1967A8Resource *arg0, void *arg1);
extern u16 fn_1_96968(Fn196968Object *object, void *arg1);
extern u16 fn_1_969E8(Fn1969E8Owner *owner, void *arg1);
extern u16 fn_1_96BC0(Fn196BC0Object *object, void *arg1);
extern u16 fn_1_96A68(Fn196A68Object *object, void *arg1);
extern const f32 lbl_1_rodata_3E48[];
extern void *camera_get_state_object(void);
extern void camera_update_state(void *);
extern CarR29 *fn_80071268(void *, void *);
extern void lbl_8006E1F0(Vec3f *, f32, f32, f32);
extern void fn_1_A714C(f32 *a, f32 *b, f32 *c, f32 *d);
extern f32 lbl_8006D21C(s32);
extern void lbl_8006E2C0(Vec3f *, f32, f32, f32);
extern void fn_8006E250(Vec3f *, Vec3f *);
extern void fn_1_B81C(Vec3f *, Vec3f *, s32);
extern void fn_1_150464(u32 arg0);
extern void fn_1_810E4(u32 arg0);
extern u8 lbl_1_rodata_3590[984];
extern u32 fn_1_12AC00(unsigned char *value);
extern void fn_1_80294(void *arg0, void *arg1, s32 arg2);
extern u32 lbl_1_rodata_3A94[7];
extern void lbl_8006DC6C(void *, u32, u32);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006DFE8(void *);
extern f32 fn_1_A71AC(void);
extern u8 fn_1_5910();
extern void fn_1_681C(u32 index, u32 *output);
extern void fn_1_6914(u32 index, u32 *output);
extern f32 lbl_8006D534(Vec3 *a, Vec3 *b);
extern u32 lbl_1_rodata_3B20[3];
extern f32 lbl_1_rodata_3B2C[47];
extern Triple lbl_1_rodata_3BE8;
extern u32 fn_80007CDC(f32 *arg0);
extern u32 fn_80007D58(f32 *arg0);
extern void lbl_8006D784(void *);
extern void lbl_8006DD14(void *, void *);
extern u32 lbl_1_rodata_3BF4[14];
extern u32 lbl_1_bss_6D8F4[31];
extern u32 lbl_801A66A0;
extern u32 fn_1_56018(s32 value);
extern void fn_1_560F0(s32 index, void *arg);
extern void fn_1_55210(void *value);
extern f32 lbl_8006D188(s16);
extern void fn_1_87448();
extern void fn_80008BA8(void *dst, const void *src, int size);
extern void lbl_8006D7DC(void *value);
extern void lbl_8006DB74(void *value);
extern f32 lbl_1_rodata_3C2C[33];
extern u8 lbl_1_bss_8CA28;
extern void fn_80008BEC(void *dest, int value, u32 size);
extern u32 GXGetTexBufferSize(u16 width, u16 height, u32 arg2, u32 arg3, u32 arg4);
extern u32 fn_1_4630();
extern void fn_1_550A8(void);
extern void fn_1_545B8(void);
extern void fn_1_550E0(void);
extern void fn_80038F10(f32* out);
extern void fn_80038FD8(u32 *left, u32 *top, u32 *width, u32 *height);
extern void fn_80038BFC(f32* out);
extern void fn_80015E18(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
extern void fn_800737E4(void *, s32);
extern u32 fn_80038EEC();
extern s32 __cvt_fp2unsigned(f32);
extern u32 fn_80074188(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void fn_80008204(void *);
extern void fn_80074300();
extern void fn_80074438(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_8003526C(u32, u8);
extern void GXInvalidateTexAll(void);
extern void fn_80072270(void *);
extern void fn_1_4FC50(u32, u32, u16, u16, u32);
extern u32 fn_80008E84(u32 arg0);
extern void fn_1_426C(s32 value);
extern void fn_1_8E7D0(Fn1_8F45C_Object *obj);
extern void fn_1_12A2B8(u32 value);
extern void fn_1_12A2D0(s32 value);
extern void fn_1_9724C();
extern void fn_1_107C4C(void *arg);
extern void fn_1_966A0(Fn1_8F494_Object *obj);
extern void fn_1_95EF0();
extern void fn_1_8F5A4(Fn1_8F5A4_Object *obj);
extern void fn_1_968FC(Fn1_8F5A4_Object *obj);
extern s32 fn_1_41488(void *arg0, void *arg1);
extern f32 lbl_1_rodata_4010[60];
extern void fn_1_943F8(Fn935E4Car *, f32, void *);
extern void fn_1_42AD0(void *, s32, u16, s32, u16);
extern void fn_1_41328(void *arg0);
extern void fn_1_426E4(void *arg0, void *arg1);
extern u32 lbl_1_bss_6D828;
extern s32 fn_1_3F854(u32 arg0);
extern s32 fn_1_8171C(s32 value);
extern u8 lbl_1_rodata_3968[232];
extern void fn_800712E4(void *arg0, u32 arg1, void *arg2);
extern u32 lbl_1_bss_6D850;
extern u32 lbl_1_bss_6D97C;
extern u32 lbl_1_bss_6D978;
extern f32 fn_1_86A2C(void *);
extern void fn_1_85688(void);
extern void fn_1_854D4(void);
extern void fn_1_85934();
extern void fn_1_C489C(Obj_1_bss_6D838_Target *);
extern void fn_1_C40A0(Obj_1_bss_6D838_Target *);
extern u8 lbl_1_bss_6DA5C[30];
extern void fn_1_8A1B4(void *arg0, void *arg1, int arg2);
extern void fn_1_8B8A4(void *arg);
extern u8 lbl_1_bss_6DA7A;
extern u8 lbl_1_bss_6DA7B[5];
extern s32 fn_8006FDEC(void);
extern void fn_8006FEFC(void);
extern u8 lbl_1_rodata_3DD8[84];
extern u32 lbl_1_bss_6D86C[34];
extern u32 fn_1_12ADA0(unsigned char *value, u32 arg);
extern void fn_1_961F0(void *obj);
extern u32 lbl_1_bss_6E978[3];
extern s32 lbl_1_bss_6E984;
extern u32 lbl_1_rodata_3FA0[28];
extern void fn_80007AB4(u8 *arg0);
extern void fn_1_92554(void *arg0, s32 arg1);
extern f32 lbl_1_rodata_3F70[12];
extern u8 lbl_1_data_34348[12];
extern void fn_1_12A2C4(u32 value);
extern void fn_1_A7B5C(void *arg0, s32 arg1, void *arg2, s8 arg3, void *arg4);
extern u32 lbl_1_bss_6D970;
extern u32 lbl_1_bss_6D974;
extern u32 fn_1_435C(u32 value);
extern void fn_1_850C4(void);

/* fzgx:begin fn_1_7F3AC */
typedef struct CarFn_1_7F3AC {
    u8 pad_390[0x390];
    u32 field_390;
    u8 pad_394[0x10];
    u32 field_3A4;
} CarFn_1_7F3AC;


#pragma opt_propagation off
#pragma opt_common_subs off
void fn_1_7F3AC(CarFn_1_7F3AC *car, u32 lab_unused0, u32 lab_unused1, u32 lab_unused2) {
    u32 *fzgx_value;
    u32 shift;
    u32 flags;
    if (car != 0 && car->field_3A4 != 0) {
        shift = 6;
        flags = car->field_390;
        if ((__rlwnm(flags, shift, 31, 31) != 0)) {
            fn_1_150464(car->field_3A4);
        } else {
            fn_1_810E4(car->field_3A4);
        }
        fn_1_46B4(lbl_801A6410, car->field_3A4, (const char *)(u8 *)((((u8 *)&lbl_1_data_1FFF0))), 0x1F7);
        fzgx_value = &(car->field_3A4);
        *fzgx_value = 0;
    }
}
#pragma opt_common_subs reset

#pragma opt_propagation reset
/* fzgx:end fn_1_7F3AC */

/* fzgx:begin fn_1_7F428 */
u32 fn_1_7F428(u32 arg0) {
    s32 index;

    if (lbl_1_bss_6D828 == 0) {
        return 0;
    }

    index = fn_1_3F854(arg0);
    if ((u8)arg0 > index) {
        return 0;
    }

    return lbl_1_bss_6D828 + (u8)arg0 * (0x10000 + 0x440);
}
/* fzgx:end fn_1_7F428 */

/* fzgx:begin fn_1_7F49C */
typedef struct {
    u32 data[40][6];
    u8 tail[24];
} fn_1_7F49C_CarData;

void *fn_1_7F49C(s16 arg0, s16 arg1, void *arg2) {
    fn_1_7F49C_CarData local;

    local = *(fn_1_7F49C_CarData *)lbl_1_rodata_3590;
    fn_80083DB0( (char *)(void *)(arg2), (const char *)(u32)(local.data[arg0][arg1]));
    return arg2;
}
/* fzgx:end fn_1_7F49C */

/* fzgx:begin fn_1_7F658 noprologue */
#include "types.h"

struct fn_1_7F658_lbl_801A6410 {
    u32 unk_0;
};
extern struct fn_1_7F658_lbl_801A6410 lbl_801A6410;
extern u8 lbl_1_data_1FFF0[0xC];

typedef struct {
    s32 a : 25;
    s32 b : 1;
    s32 c : 6;
} Sig_fn_1_7F658_FlagBits;

typedef struct {
    u8 pad_340[0x340];
    void *field_340;
} Sig_fn_1_7F658_Item;

typedef struct {
    u8 pad_380[0x380];
    u32 unk_380;
} Sig_fn_1_7F658_Sub;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    void *unk_8;
} Sig_fn_1_7F658_E34;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    void *unk_8;
    u8 pad_C[0x320];
    u32 unk_32C;
    u32 unk_330;
    Sig_fn_1_7F658_E34 unk_334[5];
    u8 pad_370[0xC];
    u32 unk_37C[4];
    u8 pad_38C[4];
    u32 unk_390;
    u32 unk_394;
    u8 pad_398[8];
    Sig_fn_1_7F658_Item *unk_3A0;
    u32 unk_3A4;
    u8 pad_3A8[0x18];
    u32 unk_3C0[8];
    u32 unk_3E0[8];
    u32 unk_400[5];
    u32 unk_414[5];
} Sig_fn_1_7F658_Car;

extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_1_14DBCC(Sig_fn_1_7F658_Item *);
extern void fn_1_150464(u32);
extern void fn_1_810E4(u32);
extern void fn_1_A7728(Sig_fn_1_7F658_Car *);
extern void fn_800711A8(u32);
extern void fn_80071718(u32);

static inline s8 fn_1_7F658_busy(Sig_fn_1_7F658_Car *car) {
    s32 i;

    if (car == 0) {
        return 0;
    }
    if ((car->unk_390 & 0x4000000) != 0 && car->unk_3A0->field_340 != 0) {
        return 1;
    }
    for (i = 0; i < 4; i++) {
        if (car->unk_37C[i] != 0) {
            return 1;
        }
    }
    return 0;
}

void fn_1_7F658(Sig_fn_1_7F658_Car *arg0) {
    struct fn_1_7F658_lbl_801A6410 *p_lbl_801A6410;
    u32 v0;
    s8 flag;
    s16 v1;
    struct { s16 value; } v8;

    if (arg0 != 0) {
        flag = fn_1_7F658_busy(arg0);
        if (flag) {
            p_lbl_801A6410 = &lbl_801A6410;
            v1 = 0;
            while (v1 < 8) {
                v0 = arg0->unk_3C0[v1];
                if (v0 != 0) {
                    fn_1_46B4(p_lbl_801A6410->unk_0, v0, (const char *)lbl_1_data_1FFF0, 0x27D);
                    arg0->unk_3C0[v1] = 0;
                    arg0->unk_3E0[v1] = 0;
                }
                v1++;
            }
            p_lbl_801A6410 = &lbl_801A6410;
            v1 = 0;
            while (v1 < 5) {
                v0 = arg0->unk_400[v1];
                if (v0 != 0) {
                    fn_1_46B4(p_lbl_801A6410->unk_0, v0, (const char *)lbl_1_data_1FFF0, 0x284);
                    arg0->unk_400[v1] = 0;
                    arg0->unk_414[v1] = 0;
                }
                v1++;
            }
            arg0->unk_32C = 0;
            {
                struct { s16 value; } w;
                w.value = 0;
                while (w.value < 4) {
                    v0 = arg0->unk_37C[w.value];
                    if (v0 != 0) {
                        fn_80071718(v0);
                        arg0->unk_37C[w.value] = 0;
                    }
                    w.value++;
                }
                v8.value = w.value;
            }
            v8.value = 0;
            while (v8.value < 5) {
                v0 = arg0->unk_334[v8.value].unk_4;
                if (v0 != 0) {
                    fn_800711A8(v0);
                    arg0->unk_334[v8.value].unk_4 = 0;
                }
                v0 = arg0->unk_334[v8.value].unk_0;
                if (v0 != 0) {
                    fn_1_46B4(lbl_801A6410.unk_0, v0, (const char *)lbl_1_data_1FFF0, 0x290);
                    arg0->unk_334[v8.value].unk_0 = 0;
                }
                v8.value++;
            }
            v0 = arg0->unk_330;
            if (v0 != 0) {
                fn_1_46B4(lbl_801A6410.unk_0, v0, (const char *)lbl_1_data_1FFF0, 0x292);
                arg0->unk_330 = 0;
            }
            if ((void *)((u8 *)arg0 + 0x394) != 0) {
                fn_1_A7728(arg0);
            }
            if ((arg0->unk_390 & 0x4000000) != 0) {
                if (arg0->unk_3A0 != 0) {
                    fn_1_14DBCC(arg0->unk_3A0);
                }
            }
            if (arg0 != 0 && arg0 != 0) {
                if (arg0->unk_3A4 != 0) {
                    if (__rlwnm(arg0->unk_390, 6, 31, 31)) {
                        fn_1_150464(arg0->unk_3A4);
                    } else {
                        fn_1_810E4(arg0->unk_3A4);
                    }
                    fn_1_46B4(lbl_801A6410.unk_0, arg0->unk_3A4, (const char *)lbl_1_data_1FFF0, 0x1F7);
                    arg0->unk_3A4 = 0;
                }
            }
            arg0->unk_390 &= ~0x400000;
        }
    }
}
/* fzgx:end fn_1_7F658 */

/* fzgx:begin fn_1_7F934 */
// Forwards the caller's context to the common car initialization routine.
void fn_1_7F934(void *arg0) {
    fn_1_7F658(arg0);
}
/* fzgx:end fn_1_7F934 */

/* fzgx:begin fn_1_7F954 */
struct fn_1_7F954_lbl_1_bss_6D82C {
    u32 unk_0;
};


void fn_1_7F954(u32 arg0, u32 arg1) {
    s8 v0;
    u32 v2;
    u32 v3;
    u32 v4;
    v0 = (s8)arg1;
{
    s32 v1;
    v1 = 0;
    v2 = arg0;
    while ((s8)v1 < v0) {
    fn_1_7F658((void *)v2);
    v2 += 1088;
    v1++;
}
    }
    fn_1_46B4((*((struct fn_1_7F954_lbl_801A6410 *)&lbl_801A6410)).unk_0, arg0, (const char *)((u32)&(*((u32 *)&lbl_1_data_1FFF0))), 691);
    v3 = (*((struct fn_1_7F954_lbl_1_bss_6D82C *)&lbl_1_bss_6D82C)).unk_0;
    v4 = v3;
    if (v3 != 0) {
    fn_80071718( (u32)((void *)v4));
    (*((struct fn_1_7F954_lbl_1_bss_6D82C *)&lbl_1_bss_6D82C)).unk_0 = 0;
    }
}
/* fzgx:end fn_1_7F954 */

/* fzgx:begin fn_1_7FA04 */
struct fn_1_7FA04_lbl_1_bss_6D82C {
    u32 unk_0;
};


void fn_1_7FA04(u32 arg0) {
    u32 v1;
    s32 v0;
    u32 v2;
    u32 v3;
    u32 t2;
    v0 = 0;
    v1 = arg0;
    while ((s8)v0 < 41) {
    fn_1_7F658( (void *)(u32)(v1));
    v1 += 1088;
    v0++;
    }
    fn_1_46B4((*((struct fn_1_7FA04_lbl_801A6410 *)&lbl_801A6410)).unk_0, arg0, (const char *)((u32)&(*((u32 *)&lbl_1_data_1FFF0))), 709);
    v2 = (*((struct fn_1_7FA04_lbl_1_bss_6D82C *)&lbl_1_bss_6D82C)).unk_0;
    v3 = v2;
    if (v2 != 0) {
    t2 = fn_80071718(v3);
    v3 = t2;
    (*((struct fn_1_7FA04_lbl_1_bss_6D82C *)&lbl_1_bss_6D82C)).unk_0 = 0;
    }
}
/* fzgx:end fn_1_7FA04 */

/* fzgx:begin fn_1_7FD7C */
typedef struct {
    s16 unk_00;
    s16 unk_02;
    u32 unk_04;
    u8 unk_08;
    u32 unk_0C;
} Fn7FD7CArg;

typedef struct {
    char *unk_00;
} TblRow;

#pragma opt_strength_reduction on
#pragma opt_propagation off
#pragma opt_lifetimes off
#pragma opt_loop_invariants off
#pragma opt_dead_assignments off
void fn_1_7FD7C(Fn7FD7CArg *arg0)
{
    u32 tmp_call9;
    char buf[32];
    u32 off;
    const char * lab_t1__2;
    TblRow *tbl;
    u32 idx;
    s32 flag;
    u8 i;
    s16 j;
    u8 *base = (u8 *)&lbl_1_data_1F1D8;
    const char *lab_t1;
    u32 tmp_call5;
    s32 tmp_call6;
    const char * lab_t1_;
    s32 tmp_call15;

    idx = arg0->unk_02;
    flag = 0;
    if (arg0->unk_0C & 0x100000) {
        flag = 1;
    }
    off = (u32)((u64)idx << 2);
    tbl = (TblRow *)(base + 0x324);
    lab_t1 = *(char **)((u8 *)tbl + off);
    lab_t1_ = lab_t1;
    fn_80083DB0(buf, lab_t1_);
    if (((1) == (flag))) {
        fn_1_801F8(idx, (void *)(char *)(buf));
    }
    fn_80006E10( (u32)(char *)(buf));
    for (i = 0; i < 8; i++) {
        if (arg0->unk_08 & (1 << i)) {
            lab_t1__2 = *(char **)((u8 *)tbl + off);
            fn_80083DB0(buf, lab_t1__2);
            if (((1) == (flag))) {
                fn_1_801F8(idx, (void *)(char *)(buf));
            }
            if (i != 0) {
                if (i >= 4) {
                    sprintf(buf, (char *)(base + 0x1358), buf, i - 4);
                } else {
                    sprintf(buf, (char *)(base + 0x1364), buf, i);
                }
            } else {
                sprintf(buf, (char *)(base + 0x1370), buf);
            }
            if ((tmp_call5 = (u32)fn_1_46C70(buf)) == 0xFFFFFFFF) {
                tmp_call6 = fn_1_465D0( (s32)(char *)(buf), 1);
                tmp_call6;
            }
        }
    }
    {
    s16 fzgx_loop_j_1994;
for (fzgx_loop_j_1994 = 0; fzgx_loop_j_1994 < 5; fzgx_loop_j_1994++) {
        if (arg0->unk_04 & (1 << fzgx_loop_j_1994)) {
            lab_t1__2 = *(char **)((u8 *)tbl + off);
            fn_80083DB0(buf, lab_t1__2);
            if (((1) == (flag))) {
                fn_1_801F8(idx, (void *)(char *)(buf));
            }
            if (((0) == (fzgx_loop_j_1994))) {
                sprintf(buf, (char *)(base + 0x1378), buf);
            } else if (((4) == (fzgx_loop_j_1994))) {
                sprintf(buf, (char *)(base + 0x1380), buf);
            } else {
                sprintf(buf, (char *)(base + 0x1390), buf, fzgx_loop_j_1994 + 1);
            }
            tmp_call9 = (u32)fn_1_46C70(buf);
            if (tmp_call9 == 0xFFFFFFFF) {
                fn_1_465D0( (s32)(char *)(buf), 1);
            }
        }
    }
    j = fzgx_loop_j_1994;
}
    lab_t1__2 = *(char **)((u8 *)tbl + off);
    fn_80083DB0(buf, lab_t1__2);
    if (((1) == (flag))) {
        fn_1_801F8(idx, (void *)(char *)(buf));
    }
    sprintf(buf, (char *)(base + 0x139c), buf);
    if ((u32)fn_1_46C70(buf) == 0xFFFFFFFF) {
        tmp_call15 = fn_1_465D0( (s32)(char *)(buf), 1);
        tmp_call15;
    }
    fn_80006E10( (u32)((char *)(base + 0xe20)));
}
#pragma opt_dead_assignments reset
#pragma opt_loop_invariants reset
#pragma opt_lifetimes reset
#pragma opt_propagation reset
#pragma opt_strength_reduction reset
/* fzgx:end fn_1_7FD7C */

/* fzgx:begin fn_1_7FFF0 */
// Installs the default car-data entry used by the car registry.
void fn_1_7FFF0(void) {
    fn_1_465D0( (s32)(void *)(lbl_1_data_2057C), 1);
}
/* fzgx:end fn_1_7FFF0 */

/* fzgx:begin fn_1_8001C */
void fn_1_8001C(void) {
    fn_1_465D0( (s32)(void *)(lbl_1_data_20594), 1);
    fn_1_465D0( (s32)(void *)(lbl_1_data_205A8), 1);
}
/* fzgx:end fn_1_8001C */

/* fzgx:begin fn_1_80058 */
void fn_1_80058(s8 arg0, u8 *arg1) {
    u8 data[0x20];

    fn_80008BEC(data, 0, 0x20);
    *(u32 *)(data + 4) = 0xF;
    data[8] = 1;
    fn_80008BA8(arg1, data, 0x20);
    *(u16 *)(arg1 + 2) = arg0;
}
/* fzgx:end fn_1_80058 */

/* fzgx:begin fn_1_800C4 */
void fn_1_800C4(u16 arg0, u8 *arg1) {
    u8 data[0x20];

    fn_80008BEC(data, 0, 0x20);
    *(u32 *)(data + 4) = fn_1_8171C(1);
    data[8] = 0x10;
    fn_80008BA8(arg1, data, 0x20);
    *(u16 *)(arg1 + 2) = arg0;
}
/* fzgx:end fn_1_800C4 */

/* fzgx:begin fn_1_80130 */
void fn_1_80130(u16 arg0, u8 *arg1) {
    u8 data[0x20];

    fn_80008BEC(data, 0, 0x20);
    *(u32 *)(data + 4) = fn_1_8171C(0);
    data[8] = 1;
    fn_80008BA8(arg1, data, 0x20);
    *(u16 *)(arg1 + 2) = arg0;
}
/* fzgx:end fn_1_80130 */

/* fzgx:begin fn_1_8019C */
typedef struct {
    u32 words[58];
} InitData;

void fn_1_8019C(void *arg0) {
    InitData data;

    data = *(InitData *)lbl_1_rodata_3968;
    fn_800712E4(arg0, lbl_1_bss_6D82C.unk_0, &data);
}
/* fzgx:end fn_1_8019C */

/* fzgx:begin fn_1_801F8 */
void fn_1_801F8(s16 arg0, void *arg1) {
    u8 *base = (u8 *)&lbl_1_data_1F1D8;

    switch (arg0) {
    case 6:
        fn_80083DB0( (char *)(void *)(arg1), (const char *)(const void *)(base + 0x13e4));
        break;
    case 0:
        fn_80083DB0( (char *)(void *)(arg1), (const char *)(const void *)(base + 0x13ec));
        break;
    case 1:
        fn_80083DB0( (char *)(void *)(arg1), (const char *)(const void *)(base + 0x13f4));
        break;
    }
}
/* fzgx:end fn_1_801F8 */

/* fzgx:begin fn_1_80270 */
void fn_1_80270(void *arg0, void *arg1) {
    fn_1_80294(arg0, arg1, 0);
}
/* fzgx:end fn_1_80270 */

/* fzgx:begin fn_1_80C18 */
void fn_1_80C18(u8 *arg0, u8 *arg1, s8 arg2) {
    u8 *data;
    u8 *p0;
    u8 *p1;
    s8 i;
    s8 count;

    data = (u8 *)&lbl_1_data_1F1D8;
    fn_1_12AB38(data + 0xe0c);
    p0 = arg0;
    p1 = arg1;
    if (lbl_1_bss_6D82C.unk_0 == 0) {
        lbl_1_bss_6D82C.unk_0 = (u32)fn_1_12AC00( (unsigned char *)(void *)(data + 0x140c));
    }

    i = 0;
    while (i < (arg2)) {
        if (p0 == 0) {
            break;
        }
        fn_1_80294(p1, p0, 0);
        p0 += 0x440;
        p1 += 0x20;
        i++;
    }

    fn_1_12AB38(data + 0xe20);
}
/* fzgx:end fn_1_80C18 */

/* fzgx:begin fn_1_80F1C */
void fn_1_80F1C(s32 arg0, void *arg1) {
    fn_1_7F658(arg1);
    if ((s16)arg0 != -1) {
        fn_1_12A734((s16)arg0);
    }
    if (lbl_1_bss_6D82C.unk_0 != 0) {
        fn_80071718( (u32)((void *)lbl_1_bss_6D82C.unk_0));
        lbl_1_bss_6D82C.unk_0 = 0;
    }
}
/* fzgx:end fn_1_80F1C */

/* fzgx:begin fn_1_810E4 */
void fn_1_810E4(u32 arg0) {
    u32 v1;
    u32 v2;
    u32 v3;
{
    s32 v0;
    v0 = 0;
    v1 = arg0;
    while ((s16)v0 < 3) {
    v2 = *(u32 *)((u8 *)v1 + 4);
    if (v2 != 0) {
    fn_80071718( (u32)((void *)v2));
    *(u32 *)((u8 *)v1 + 4) = 0;
    }
    v3 = *(u32 *)((u8 *)v1 + 0);
    if (v3 != 0) {
    fn_800711A8( (u32)((void *)v3));
    *(u32 *)((u8 *)v1 + 0) = 0;
    }
    v1 += 8;
    v0++;
}
    }
}
/* fzgx:end fn_1_810E4 */

/* fzgx:begin fn_1_816E8 */
s8 fn_1_816E8(u32 base, s8 index) {
    if (base == 0) {
        /* shared failure block is required by the retail control flow */
        goto fail;
    }
    base += index * 12;
    base = *(u32 *)((u8 *)base + 824);
    if (base != 0) {
        /* shared success block preserves the retail branch layout */
        goto success;
    }
fail: /* shared failure block is required by the retail control flow */
    return -1;
success: /* success is reached only after the non-null entry check */
    return (s8)*(u32 *)base;
}
/* fzgx:end fn_1_816E8 */

/* fzgx:begin fn_1_8171C */
// Maps a car mode to its corresponding status code.
s32 fn_1_8171C(s32 value) {
    switch (value) {
    case 0:
        return 0xD;
    case 1:
        return 0xE;
    case 2:
        return 0xE;
    case 3:
        return 0xF;
    default:
        return -1;
    }
}
/* fzgx:end fn_1_8171C */

/* fzgx:begin fn_1_8176C */
void fn_1_8176C(u32 value) {
    lbl_1_bss_6D850 = value;
}
/* fzgx:end fn_1_8176C */

/* fzgx:begin fn_1_81778 */
void fn_1_81778(void) {
    s32 offset;
    s32 i;
    i = 0;
    offset = 0;
    while (i < *(s8 *)&lbl_1_bss_6D84A) {
        *((u32 *)((u8 *)lbl_1_bss_6D838 + offset)) |= 0x8000;
        i++;
        offset += 0x620;
    }
}
/* fzgx:end fn_1_81778 */

/* fzgx:begin fn_1_817C0 */
void fn_1_817C0(void) {
    s32 offset;
    s32 i;

    i = 0;
    offset = 0;
    while (i < (s8)lbl_1_bss_6D84A) {
        u32 *value = (u32 *)((u8 *)lbl_1_bss_6D838 + offset);
        *value &= 0xFFFF7FFF;
        i++;
        offset += 0x620;
    }
}
/* fzgx:end fn_1_817C0 */

/* fzgx:begin fn_1_81808 */
void fn_1_81808(void *arg0) {
    fn_80008BA8(arg0, &lbl_1_data_2065C, 4);
}
/* fzgx:end fn_1_81808 */

/* fzgx:begin fn_1_81834 */
void fn_1_81834(u8 value, s8 index_a, s8 index_b) {
    if (index_a != -1) {
        *((u8 *)&lbl_1_data_2065C + index_a) = value;
    }
    *((u8 *)&lbl_1_data_20660 + index_b) = value;
}
/* fzgx:end fn_1_81834 */

/* fzgx:begin fn_1_81860 */
typedef struct {
    u8 pad0[2];
    s16 id;
    u8 pad4[8];
    u32 flags;
} fn_1_81860_Obj;

s32 fn_1_81860(fn_1_81860_Obj *a, fn_1_81860_Obj *b) {
    u32 flags_a = a->flags & 0xF0000000;
    if (flags_a != 0 && (b->flags & 0xF0000000) == 0) {
        return 1;
    }
    if ((b->flags & 0xF0000000) != 0 && flags_a == 0) {
        return -1;
    }
    return a->id - b->id;
}
/* fzgx:end fn_1_81860 */

/* fzgx:begin fn_1_818AC */
typedef struct {
    u8 pad0[0x320];
    s16 value;
} fn_1_818AC_Obj;

s32 fn_1_818AC(fn_1_818AC_Obj *a, fn_1_818AC_Obj *b) {
    return a->value - b->value;
}
/* fzgx:end fn_1_818AC */

/* fzgx:begin fn_1_82EDC noprologue */
#include "types.h"

typedef struct {
    u32 w[45];
} Unk_23800000;

extern Unk_23800000 lbl_23800000[];
extern u8 *fn_1_36AD0(s16 arg0);
extern void fn_1_14F6F8(u8 arg0, u8 arg1, u8 arg2, void *arg3);

void *fn_1_82EDC(s16 arg0, s16 arg1, void *arg2) {
    u8 *data;
    u32 i;
    u32 *dst;
    u32 *src;

    if (arg1 < 41) {
        dst = (u32 *)arg2;
        src = (u32 *)(0x23800000 + arg1 * 0xB4);
        for (i = 0; i < 45; i++) {
            dst[i] = src[i];
        }
    } else {
        if (arg0 == -1) {
            return 0;
        }
        data = (u8 *)fn_1_36AD0(arg0) + arg0 * 0x81C0;
        fn_1_14F6F8(data[0x81A4], data[0x81AC], data[0x81B4], arg2);
    }
    return arg2;
}
/* fzgx:end fn_1_82EDC */

/* fzgx:begin fn_1_835E0 */
// Registers the car callbacks and publishes the supplied car context.
void fn_1_835E0(void *car_context, void *initial_state, void *callback_context) {
    fn_1_435C( (u32)(void *)(initial_state));
    lbl_1_bss_6D970 = (u32)callback_context;
    fn_1_43E8(1);
    fn_1_3F8C( (u32)(void *)(lbl_1_data_20714), (u32)(void *)(fn_1_850C4), (u32)(Obj_1_bss_6D838_Target *)(car_context), 9);
    lbl_1_bss_6D974 = (u32)fn_1_8B8A4;
    fn_1_43F4();
}
/* fzgx:end fn_1_835E0 */

/* fzgx:begin fn_1_8365C */
void fn_1_8365C(s32 enabled) {
    u32 value;

    if (enabled != 0) {
        lbl_1_bss_6D97C = 0;
        value = 0;
    } else {
        lbl_1_bss_6D97C = 1;
        value = 1;
    }
    lbl_1_bss_6D978 = value;
}
/* fzgx:end fn_1_8365C */

/* fzgx:begin fn_1_83CB0 */
typedef struct {
    u8 _pad_00[0x7c];
    f32 field_7c;
    f32 field_80;
    f32 field_84;
    u8 _pad_88[0x64];
    u8 field_ec[0x3b4];
    u8 field_4a0[0x10];
} Fn183CB0Object;

#pragma opt_propagation off
void fn_1_83CB0(Fn183CB0Object *obj) {
    u32 local[3];
    f32 x;
    f32 y;
    f32 z;

    local[0] = lbl_1_rodata_3A94[0];
    local[1] = lbl_1_rodata_3A94[1];
    local[2] = lbl_1_rodata_3A94[2];
    lbl_8006DC6C(obj->field_ec, lbl_1_rodata_3A94[1],
                 lbl_1_rodata_3A94[0]);
    z = obj->field_7c;
    y = obj->field_80;
    x = obj->field_84;
    /* Hardware register base is defined by the target address map. */
    *(volatile f32 *)(LC_BASE + 0xC) = z; /* hardware register */
    *(volatile f32 *)(LC_BASE + 0x1C) = y; /* hardware register */
    *(volatile f32 *)(LC_BASE + 0x2C) = x; /* hardware register */
    lbl_8006E1B0(local, obj->field_4a0);
}
#pragma opt_propagation reset
/* fzgx:end fn_1_83CB0 */

/* fzgx:begin fn_1_84038 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.0f;
}
static const u32 fzgx_pool_table2[2] = {0x40000000, 0x40000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.5f;
    s = 0.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.1920928955078125e-07;
    s = 1.4499999284744263f;
    s = -1.5881868392106856e-23f;
    s = 1.0f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.15000000074505807;
    s = 0.05000000074505806f;
    s = 30.0f;
    s = 0.00390625f;
    s = 182.04444885253906f;
    s = 180.0f;
    s = 44.0f;
    s = 89.0f;
    s = 360.0f;
    s = 60.0f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.12999999932944775;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table12[306] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00330000, 0x00010001, 0x00020002, 0x00030003, 0x0004002F, 0x00050004, 0x00060005, 0x00070006, 0x00080007, 0x00090008, 0x000A002A, 0x000B0009, 0x000C002B, 0x000D000A, 0x000E002C, 0x000F000B, 0x0010002D, 0x0011000C, 0x0012002E, 0x0013000D, 0x0014000E, 0x003D000F, 0x003E0010, 0x003F0011, 0x00400012, 0x00410013, 0x00420014, 0x00430015, 0x00440016, 0x00450017, 0x00460018, 0x00470019, 0x0048001A, 0x0049001B, 0x004A001C, 0x004B001D, 0x004C0034, 0x004D0035, 0x004E0036, 0x004F0037, 0x001F001E, 0x0020001F, 0x00210020, 0x00220021, 0x00230022, 0x00240023, 0x00250024, 0x00260025, 0x00270026, 0x00280027, 0x00290028, 0x002A0029, 0x00500038, 0x00510030, 0x00520031, 0x00530032, 0x00540033, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
}
static const u32 fzgx_pool_table14[3] = {0x0032001E, 0x00140004, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    d = 0.20000000298023224;
    s = 0.10000000149011612f;
    s = 0.11999999731779099f;
    s = -0.10000000149011612f;
    s = -1.0f;
    s = 0.8999999761581421f;
    s = 0.49000000953674316f;
    d = 0.800000011920929;
    s = 0.4000000059604645f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
}
static const u32 fzgx_pool_table18[1] = {0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 0.75f;
}
static const u32 fzgx_pool_table20[1] = {0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1000.0f;
}
#pragma section code_type ".text"


typedef struct {
    u8 _pad_32c[0x32c];
    void *field_32c;
    u8 _pad_330[0x70];
    void *field_3a0;
} Fn184038Object;

typedef struct {
    u8 _pad[8];
    f32 value;
} Fn184038Result;

typedef struct {
    u8 _pad[0x344];
    void *field_344;
} Fn184038TableEntry;

f32 fn_1_84038(Fn184038Object *obj, s16 index, u8 use_table, f32 value) {
    f32 saved_value = value;
    f32 *constants = lbl_1_rodata_3508;
    void *entry;
    Fn184038Result result;
    f32 factor;
    f32 output;
    f32 entry_value;
    f32 coeff;

    if (use_table != 0) {
        entry = ((void **)((u8 *)obj->field_3a0 + 0x344))[index];
        entry = *(void **)((u8 *)entry + 4);
    } else {
        entry = (u8 *)obj + (s32)index * 0xc;
        entry = *(void **)((u8 *)entry + 0x334);
        entry = *(void **)entry;
    }

    if (entry == NULL) {
        return (-1.0f);
    }

    lbl_8006DFE8((u8 *)obj->field_32c + 0x14c);
    lbl_8006E1B0((u8 *)entry + 8, &result);

    if (result.value > (-1.1920929e-07f)) {
        return (1000.0f);
    }

    return (240.0f) * ((2.0f) * *(f32 *)((u8 *)entry + 0x14) * saved_value) / (-result.value * fn_1_A71AC());
}
/* fzgx:end fn_1_84038 */

/* fzgx:begin fn_1_84124 */
typedef struct {
    u8 _pad[0x38c];
    u8 flags;
} Fn184124Object;

s8 fn_1_84124(Fn184124Object *obj, s8 direction, s8 index, u8 *count) {
    *count = 0;

    if (index == 5) {
        return index;
    }

    if (index < 0 || index > 5) {
        return index < 0 ? 0 : (index > 5 ? 5 : index);
    }

    if (direction == 1) {
        while (index < 5) {
            if (obj->flags & (1 << index)) {
                return index;
            }
            index++;
            (*count)++;
        }
    } else if (direction == -1) {
        while (index > -1) {
            if (obj->flags & (1 << index)) {
                return index;
            }
            index--;
            (*count)++;
        }
    }

    return -1;
}
/* fzgx:end fn_1_84124 */

/* fzgx:begin fn_1_8421C */
struct fn_1_8421C_Arg0 {
    u8 pad_0[0x320];
    s16 unk_320;
    u8 pad_322[0x6A];
    u8 unk_38C;
};

static inline s8 clamp_selection(s8 value) {
    return value < 0 ? 0 : value > 5 ? 5 : value;
}

static inline s8 forward_selection(struct fn_1_8421C_Arg0 *arg0, s8 arg1, s8 *distance) {
    s8 v0;
    if (arg1 == 5) return arg1;
    if (arg1 < 0 || arg1 > 5) return clamp_selection(arg1);
    v0 = arg1;
    while (v0 < 5) {
        if (arg0->unk_38C & (1 << v0)) return v0;
        v0++;
        (*distance)++;
    }
    return -1;
}

static inline s8 backward_selection(struct fn_1_8421C_Arg0 *arg0, s8 arg1, s8 *distance) {
    if (arg1 == 5) return arg1;
    if (arg1 < 0 || arg1 > 5) return clamp_selection(arg1);
    while (arg1 > -1) {
        if (arg0->unk_38C & (1 << arg1)) return arg1;
        arg1--;
        (*distance)++;
    }
    return -1;
}

static inline s8 select_result(struct fn_1_8421C_Arg0 *arg0, s8 v0, s8 v3, s8 v1, s8 v4) {
    if (v0 == -1) return v3;
    if (v3 == -1) return v0;
    if (v1 > v4) return v0;
    if (v1 < v4) return v3;
    if (lbl_1_bss_6D9A0[arg0->unk_320] == 1) return v0;
    return v3;
}

s8 fn_1_8421C(struct fn_1_8421C_Arg0 *arg0, s8 arg1) {
    s8 v0;
    s8 v1 = 0;
    s8 v3;
    s8 v4;
    v0 = forward_selection(arg0, arg1, &v1);
    v4 = 0;
    v3 = backward_selection(arg0, arg1, &v4);
    if (v0 == -1 && v3 == -1) return 3;
    return select_result(arg0, v0, v3, v1, v4);
}
/* fzgx:end fn_1_8421C */

/* fzgx:begin fn_1_843BC */
typedef struct {
    u8 _pad[0x32c];
    void *field_32c;
} Fn1843BCObject;

f32 fn_1_843BC(Fn1843BCObject *obj) {
    if (obj == NULL) {
        return lbl_1_rodata_3530[0];
    }

    if (obj->field_32c == NULL) {
        return lbl_1_rodata_3530[0];
    }

    return fn_1_86A2C(obj->field_32c);
}
/* fzgx:end fn_1_843BC */

/* fzgx:begin fn_1_84644 */
s8 fn_1_84644(Fn184644Object *obj) {
    Vec3 v0;
    Vec3 v1;
    Vec3 v2;
    Vec3 delta0;
    Vec3 delta1;
    RawVec3 basis;
    u32 index;
    f32 result;

    index = (u8)(fn_1_5910(obj));
    fn_1_681C( (u8)(index), (u32 *)(Vec3 *)(&v0));
    fn_1_6914( (u8)(index), (u32 *)(Vec3 *)(&v1));

    psvec_sub(&v1.x, &v0.x, &delta0.x);
    lbl_8006DBAC(&obj->field_14c);

    basis.x = lbl_1_rodata_3B20[0];
    basis.y = lbl_1_rodata_3B20[1];
    basis.z = lbl_1_rodata_3B20[2];
    lbl_8006E1B0( (void *)(RawVec3 *)(&basis), (void *)(Vec3 *)(&v2));

    psvec_sub(&v2.x, &obj->field_07c.x, &delta1.x);
    result = lbl_8006D534(&delta0, &delta1);
    return (s8)(result > lbl_1_rodata_3B2C[0]);
}
/* fzgx:end fn_1_84644 */

/* fzgx:begin fn_1_8472C */
typedef struct {
    u8 _pad[0x6];
    s16 field_6;
} Fn18472CObject;

void *fn_1_8472C(Fn18472CObject *obj) {
    s16 index;

    index = -1;
    if (obj->field_6 >= 0x29) {
        index = obj->field_6 - 0x32;
    }

    if (index == -1) {
        return NULL;
    }

    return (u8 *)fn_1_36AD0() + (s32)index * 0x81c0;
}
/* fzgx:end fn_1_8472C */

/* fzgx:begin fn_1_84794 */
u8 fn_1_84794(s32 index) {
    return (&lbl_1_bss_6D868)[(s16)index];
}
/* fzgx:end fn_1_84794 */

/* fzgx:begin fn_1_847A8 */
s16 fn_1_847A8(s16 value, s16 divisor) {
    s16 selected = 0;

    switch (value) {
    case 0:
    case 15:
    case 30:
        selected = 0;
        break;
    case 1:
    case 16:
    case 31:
        selected = 1;
        break;
    case 2:
    case 17:
    case 32:
        selected = 2;
        break;
    case 3:
    case 18:
    case 33:
        selected = 3;
        break;
    case 4:
    case 19:
    case 34:
        selected = 4;
        break;
    case 5:
    case 20:
    case 35:
        selected = 5;
        break;
    case 6:
    case 21:
    case 36:
        selected = 6;
        break;
    case 7:
    case 22:
    case 37:
        selected = 7;
        break;
    case 8:
    case 23:
    case 38:
        selected = 8;
        break;
    case 9:
    case 24:
    case 39:
        selected = 9;
        break;
    case 10:
    case 25:
    case 40:
        selected = 10;
        break;
    case 11:
    case 26:
        selected = 11;
        break;
    case 12:
    case 27:
        selected = 12;
        break;
    case 13:
    case 28:
        selected = 13;
        break;
    case 14:
    case 29:
        selected = 14;
        break;
    }

    return (s16)(selected % divisor);
}
/* fzgx:end fn_1_847A8 */

/* fzgx:begin fn_1_85688 pool */
typedef struct {
    u8 pad_0[0x324];
    s32 unk_324;
    u8 pad_328[0x118];
} Fn85688Car;

typedef struct {
    u32 unk_0;
    u32 unk_4;
} Fn85688Pair;

typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
    u32 unk_C;
    u8 pad_10[0xC];
    Fn85688Car *unk_1C;
    u32 unk_20;
    u32 unk_24;
    u16 unk_28;
    s8 unk_2A;
    u8 pad_2B[0xD];
    s32 unk_38;
    Fn85688Pair unk_3C;
} Fn85688State;

#pragma opt_common_subs off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6D820;
u32 fzgx_obj_lbl_1_bss_6D824;
u32 lbl_1_bss_6D828;
u32 fzgx_obj_lbl_1_bss_6D82C;
u32 lbl_1_bss_6D82C_fill_6D830[2];
u32 fzgx_obj_lbl_1_bss_6D838;
Fn85688Car *fzgx_obj_lbl_1_bss_6D83C;
u32 lbl_1_bss_6D83C_4;
u32 lbl_1_bss_6D83C_8;
u16 lbl_1_bss_6D83C_C;
s8 fzgx_obj_lbl_1_bss_6D84A;
u8 lbl_1_bss_6D84A_fill_6D84B;
u32 lbl_1_bss_6D84A_fill_6D84C;
u32 lbl_1_bss_6D850;
u32 lbl_1_bss_6D854_fill_6D854;
s32 lbl_1_bss_6D854_4;
Fn85688Pair lbl_1_bss_6D854_8;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D820;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D824;
    s = *(u8 *)&lbl_1_bss_6D828;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D82C;
    s = *(u8 *)&lbl_1_bss_6D82C_fill_6D830;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D838;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D83C;
    s = *(u8 *)&lbl_1_bss_6D83C_4;
    s = *(u8 *)&lbl_1_bss_6D83C_8;
    s = *(u8 *)&lbl_1_bss_6D83C_C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D84A;
    s = *(u8 *)&lbl_1_bss_6D84A_fill_6D84B;
    s = *(u8 *)&lbl_1_bss_6D84A_fill_6D84C;
    s = *(u8 *)&lbl_1_bss_6D850;
    s = *(u8 *)&lbl_1_bss_6D854_fill_6D854;
    s = *(u8 *)&lbl_1_bss_6D854_4;
    s = *(u8 *)&lbl_1_bss_6D854_8;
}
#pragma section code_type ".text"

#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("car.c");
}
#pragma section code_type ".text"

#pragma opt_loop_invariants off
void fn_1_85688(void) {
    Fn85688Pair *q;
    s8 j;
    s16 i;
    Fn85688Car *cars;
    u32 t_2;
    s32 cnt;
    u32 t;
    u32 lab_t1;

    fn_1_56858((void *)lbl_1_bss_6D83C_8, fzgx_obj_lbl_1_bss_6D84A);
    fn_1_46B4(*(u32 *)&lbl_801A6410, lbl_1_bss_6D83C_8, (const char *)"car.c", 0xdfa);

    i = 0;
    goto loop1_test; /* Keep the verified branch to loop1_test. */
loop1_body:
    if ((*((fzgx_obj_lbl_1_bss_6D83C) + (i))).unk_324 != -1) {
        fn_1_12A734((*((fzgx_obj_lbl_1_bss_6D83C) + (i))).unk_324);
        (*((fzgx_obj_lbl_1_bss_6D83C) + (i))).unk_324 = -1;
    }
    i++;
loop1_test:
    cnt = (s8)fzgx_obj_lbl_1_bss_6D84A;
    if (i < cnt) goto loop1_body; /* Keep the verified branch to loop1_body. */

    cars = fzgx_obj_lbl_1_bss_6D83C;
    for (j = 0; j < cnt; j++) {
        fn_1_7F658((void *)&cars[j]);
    }
    fn_1_46B4(*(u32 *)&lbl_801A6410, (u32)cars, (const char *)"car.c", 0x2b3);

    t = fzgx_obj_lbl_1_bss_6D82C;
    if (t) {
        fn_80071718(t);
        fzgx_obj_lbl_1_bss_6D82C = 0;
    }
    t = lbl_1_bss_6D83C_4;
    if (t) {
        lab_t1 = t;
        fn_1_46B4(*(u32 *)&lbl_801A6410, lab_t1, (const char *)"car.c", 0xdff);
        lbl_1_bss_6D83C_4 = 0;
    }
    lbl_1_bss_6D83C_C = 0;
    fn_1_591A0(1);
    q = &lbl_1_bss_6D854_8;
    lbl_1_bss_6D83C_8 = 0;
    fzgx_obj_lbl_1_bss_6D83C = 0;
    if (q->unk_4) {
        fn_80071718(q->unk_4);
        fn_800711A8(lbl_1_bss_6D854_8.unk_0);
        q->unk_4 = 0;
        lbl_1_bss_6D854_8.unk_0 = 0;
    }
    if (lbl_1_bss_6D854_4 != 0) {
        fn_1_8E1E8();
    }
    if (*(s16 *)&lbl_1_bss_960 == 14 || *(s16 *)&lbl_1_bss_960 == 2 || *(s16 *)&lbl_1_bss_960 == 12) {
        fn_1_FDFF4();
        t_2 = lbl_1_bss_6D828;
        if (t_2) {
            fn_1_46B4(*(u32 *)&lbl_801A6410, t_2, (const char *)"car.c", 0xe1b);
            lbl_1_bss_6D828 = 0;
        }
    }
}
#pragma opt_loop_invariants reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_85688 */

/* fzgx:begin fn_1_85878 */
void fn_1_85878(void) {
    fn_1_85688();
    fn_1_854D4();
}
/* fzgx:end fn_1_85878 */

/* fzgx:begin fn_1_8589C */
void fn_1_8589C(u32 value) {
    lbl_1_bss_6D864 = value;
}
/* fzgx:end fn_1_8589C */

/* fzgx:begin fn_1_858A8 */
typedef struct {
    u8 pad_0[0xA7];
    u8 unk_A7;
    u8 pad_A8[0x3A];
    u8 unk_E2[0xA0];
} Fn858A8Data;

#pragma opt_common_subs off
s32 fn_1_858A8(s16 *a, s16 *b) {
    Fn858A8Data *obj;
    Obj_1_bss_6D838_Target *entry_a;
    Obj_1_bss_6D838_Target *entry_b;
    s16 ia = *a;
    s16 ib = *b;

    entry_a = &lbl_1_bss_6D838[ia];
    obj = (Fn858A8Data *)lbl_1_bss_6D864;
    entry_b = &lbl_1_bss_6D838[ib];

    if (((0) != (obj)) && obj->unk_A7 != 0) {
        u16 index = obj->unk_A7 - 1;
        u8 *data = obj->unk_E2;

        return (s32)(data + entry_b->unk_4 * 0xA0)[index] -
               (s32)(data + entry_a->unk_4 * 0xA0)[index];
    }
    return (s32)(s8)entry_a->unk_474 - (s32)(s8)entry_b->unk_474;
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_858A8 */

/* fzgx:begin fn_1_85F70 */
void fn_1_85F70(void) {
    fn_1_23500();
}
/* fzgx:end fn_1_85F70 */

/* fzgx:begin fn_1_85F90 */
typedef struct {
    u8 pad_0[0x118];
    u32 unk_118;
    u32 unk_11c;
    u8 pad_120[0x20];
    u32 unk_140;
    f32 unk_144;
    f32 unk_148;
    f32 unk_14c;
    f32 unk_150;
} FzgxChild;

static inline void fn_1_85F90_store(u32 *destination, u32 value) { *destination = value; }
static inline const f32 *fn_1_85F90_array_read(const f32 *array) { return array; }
#pragma opt_propagation off
void fn_1_85F90(void *obj, f32 a, f32 b, f32 c, f32 d, int mode) {
    f32 *fzgx_value;
    int active;
    int result;
    f32 value;
    f32 *base;
    f32 dd;
    u8 *p;
    const f32 *table;
    FzgxChild *child;

    table = (((const f32 *)&lbl_1_rodata_3508));
    child = *(FzgxChild **)((u8 *)obj + 0x49c);
    if (((0) == (lbl_1_bss_3BE0)) || ((0) == (child))) {
        lbl_8006D7F4(((4)[table]), ((10)[table]), ((348)[table]));
        active = 1;
    } else {
        fzgx_value = &(child->unk_148);
        dd = d;
        *fzgx_value = b;
        fzgx_value[1] = c;
        fzgx_value[2] = dd;
        base = &child->unk_148;
        if (mode < 0) {
            result = fn_1_20A5C(base, &value);
        } else {
            result = (int)fn_1_21644( (void *)(f32 *)(base), &value, (void *)(int)(mode));
        }
        child->unk_140 = result;
        child->unk_144 = value;
        if (lbl_1_bss_3BE0->unk_7D != 0 && ((0) == (result)) && value < ((4)[table])) {
            p = (u8 *)fn_1_14F04() + 0x400;
            fn_1_17920(0, 0, ((4)[table]));
            lbl_8006DBAC( (Vec3 *)(void *)(p));
            lbl_8006E0A4(p + 0x70);
            lbl_8006E0B4(b, (*(s16 *)&lbl_1_bss_960 == 9 && !(*(u32 *)obj & (1 << 10))) ? ((346)[table]) : ((10)[table]), d);
            active = 0;
        } else {
            fn_1_892FC(obj, (int)(f32 *)(&b), (int)(f32 *)(&d));
            if (0 != lbl_1_bss_3BE0->unk_7D) {
                active = 1;
            } else {
                active = 0;
            }
        }
    }
    fn_1_23500(obj, a);
    if (child != 0 && active) {
        fn_1_85F90_store(&(child->unk_11c), 0);
        child->unk_118 = 0;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_85F90 */

/* fzgx:begin fn_1_8616C */
// Passes the default handling value to the car update routine.
void fn_1_8616C(void) {
    fn_1_85934(lbl_1_rodata_3518[0]);
}
/* fzgx:end fn_1_8616C */

/* fzgx:begin fn_1_86194 */
// fn_1_86194: main_rel .text:0x00086194 size 0x20
// Wrapper that calls fn_1_85934.

void fn_1_86194(void) {
    fn_1_85934();
}
/* fzgx:end fn_1_86194 */

/* fzgx:begin fn_1_861B4 */
// Processes active car entries before finalizing the car table.
void fn_1_861B4(void) {
    u32 i;
    Obj_1_bss_6D838_Target *car;

    i = 0;
    car = lbl_1_bss_6D838;
    while (i < (s8)lbl_1_bss_6D84A) {
        if (car->unk_0 & 0x04000000) {
            fn_1_C489C(car);
        }
        i++;
        car++;
    }
    fn_1_C40A0(lbl_1_bss_6D838);
}
/* fzgx:end fn_1_861B4 */

/* fzgx:begin fn_1_8623C */
// fn_1_8623C: returns a constant.
int fn_1_8623C(void) {
    return 0;
}
/* fzgx:end fn_1_8623C */

/* fzgx:begin fn_1_86244 */
u32 fn_1_86244(void) {
    return *(u32 *)(void *)&lbl_1_bss_6D838;
}
/* fzgx:end fn_1_86244 */

/* fzgx:begin fn_1_86254 */
void *fn_1_86254(int index) {
    if (lbl_1_bss_6D838 != 0) {
        return (u8 *)lbl_1_bss_6D838 + index * 0x620;
    }
    return 0;
}
/* fzgx:end fn_1_86254 */

/* fzgx:begin fn_1_8627C */
typedef struct {
    u8 pad_0[0x49C];
    u32 value;
    u8 pad_4A0[0x180];
} CarEntry_8627C;

u32 fn_1_8627C(s32 index) {
    CarEntry_8627C *cars;

    cars = (CarEntry_8627C *)lbl_1_bss_6D838;
    if (cars != 0) {
        return cars[index].value;
    }
    return 0;
}
/* fzgx:end fn_1_8627C */

/* fzgx:begin fn_1_862A8 */
struct fn_1_862A8_Arg1 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

u32 fn_1_862A8(u32 arg0, struct fn_1_862A8_Arg1 *arg1) {
    u32 v0;
    u32 v1;
    u32 v2;
    v0 = ((*((u32 *)&lbl_1_bss_6D838)) + (arg0 * 1568));
    v1 = *(u32 *)((u8 *)v0 + 444);
    v2 = *(u32 *)((u8 *)v0 + 448);
    arg1->unk_0 = v1;
    arg1->unk_4 = v2;
    arg1->unk_8 = *(u32 *)((u8 *)v0 + 452);
    return v1;
}
/* fzgx:end fn_1_862A8 */

/* fzgx:begin fn_1_862D4 */
#pragma opt_dead_assignments off
void fn_1_862D4(int index, Triple *out) {
    int offset = index * 0x620;
    struct { u32 value; } v2;

    if ((int)fn_80007CDC( (f32 *)(void *)((u8 *)lbl_1_bss_6D838 + offset + 0x7c)) != 0) {
        *out = lbl_1_rodata_3BE8;
    } else {
        u32 v0 = (u32)lbl_1_bss_6D838 + offset;
        u32 v1 = *(u32 *)((u8 *)v0 + 0x7c);
        v2.value = *(u32 *)((u8 *)v0 + 0x80);
        out->x = v1;
        out->y = v2.value;
        out->z = *(u32 *)((u8 *)v0 + 0x84);
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_862D4 */

/* fzgx:begin fn_1_8636C */
// Dispatches the argument based on the indexed car entry's state.
void fn_1_8636C(int index, void *arg) {
    int offset = index * 0x620;

    if ((int)fn_80007D58( (f32 *)(void *)((u8 *)lbl_1_bss_6D838 + offset + 0xec)) != 0) {
        lbl_8006D784(arg);
    } else {
        lbl_8006DD14((u8 *)lbl_1_bss_6D838 + offset + 0xec, arg);
    }
}
/* fzgx:end fn_1_8636C */

/* fzgx:begin fn_1_863E4 */
// Dispatches the indexed car record to the appropriate handler.
void fn_1_863E4(int index, void *arg) {
    int offset = index * 0x620;

    if ((int)fn_80007D58( (f32 *)(void *)((u8 *)lbl_1_bss_6D838 + offset + 0x5e0)) != 0) {
        lbl_8006D784(arg);
    } else {
        lbl_8006DD14((u8 *)lbl_1_bss_6D838 + offset + 0x5e0, arg);
    }
}
/* fzgx:end fn_1_863E4 */

/* fzgx:begin fn_1_8645C */
void fn_1_8645C(int index, void *arg) {
    int offset = index * 0x620;
    f32 v;

    if ((int)fn_80007D58( (f32 *)(void *)((u8 *)lbl_1_bss_6D838 + offset + 0x14c)) != 0) {
        lbl_8006D784(arg);
        v = *(f32 *)lbl_1_rodata_3518;
        *(f32 *)((u8 *)arg + 0xc) = v;
        *(f32 *)((u8 *)arg + 0x1c) = v;
        *(f32 *)((u8 *)arg + 0x2c) = v;
    } else {
        lbl_8006DD14((u8 *)lbl_1_bss_6D838 + offset + 0x14c, arg);
    }
}
/* fzgx:end fn_1_8645C */

/* fzgx:begin fn_1_864E8 */
// Returns the indexed car record from the shared car table.
u32 fn_1_864E8(int index) {
    return ((u32 *)lbl_1_bss_6D838)[index * (0x620 / sizeof(u32))];
}
/* fzgx:end fn_1_864E8 */

/* fzgx:begin fn_1_864FC noprologue */
#include "types.h"

typedef struct {
    u8 pad_0[0x58c];
    u32 value;
    u8 pad_590[0x90];
} Fn864FCEntry;

extern Fn864FCEntry *lbl_1_bss_6D838;

u32 fn_1_864FC(u32 index) {
    return lbl_1_bss_6D838[index].value;
}
/* fzgx:end fn_1_864FC */

/* fzgx:begin fn_1_86514 */
u32 fn_1_86514(int index) {
    return lbl_1_bss_6D838[index].unk_218;
}
/* fzgx:end fn_1_86514 */

/* fzgx:begin fn_1_8652C */
f32 fn_1_8652C(int index) {
    u32 offset;

    offset = index * 0x620;
    return lbl_1_bss_6D838[index].unk_17C;
}
/* fzgx:end fn_1_8652C */

/* fzgx:begin fn_1_86544 */
f32 fn_1_86544(s32 index) {
    Obj_1_bss_6D838_Target *array;

    array = lbl_1_bss_6D838;
    return array[index].unk_224;
}
/* fzgx:end fn_1_86544 */

/* fzgx:begin fn_1_8655C */
// Returns the requested car record's stored value.
f32 fn_1_8655C(int index) {
    return lbl_1_bss_6D838[index].unk_34;
}
/* fzgx:end fn_1_8655C */

/* fzgx:begin fn_1_86574 */
f32 fn_1_86574(int index) {
    return lbl_1_bss_6D838[index].unk_38;
}
/* fzgx:end fn_1_86574 */

/* fzgx:begin fn_1_8658C */
typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Vec3U32;

#pragma opt_propagation off
void fn_1_8658C(int index, Vec3U32 *out) {
    int offset = index * 0x620;
    Obj_1_bss_6D838_Target *p;

    if ((int)fn_80007CDC( (f32 *)(void *)((u8 *)lbl_1_bss_6D838 + offset + 0x88)) != 0) {
        *out = *(Vec3U32 *)lbl_1_rodata_3BF4;
    } else {
        p = (Obj_1_bss_6D838_Target *)((u8 *)lbl_1_bss_6D838 + offset);
        *out = *(Vec3U32 *)&p->unk_88;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_8658C */

/* fzgx:begin fn_1_86624 */
u8 fn_1_86624(void) {
    return lbl_1_bss_6D84A;
}
/* fzgx:end fn_1_86624 */

/* fzgx:begin fn_1_86634 */
u8 fn_1_86634(int index) {
    return lbl_1_bss_6D838[index].unk_475;
}
/* fzgx:end fn_1_86634 */

/* fzgx:begin fn_1_8664C */
u16 fn_1_8664C(int index) {
    if (lbl_1_bss_6D838 != 0) {
        return lbl_1_bss_6D838[index].unk_214;
    }
    return 0;
}
/* fzgx:end fn_1_8664C */

/* fzgx:begin fn_1_86678 */
u8 fn_1_86678(int index) {
    return lbl_1_bss_6D838[index].unk_474;
}
/* fzgx:end fn_1_86678 */

/* fzgx:begin fn_1_86690 */
s8 fn_1_86690(s8 index) {
    return lbl_1_bss_6D838[index].unk_6;
}
/* fzgx:end fn_1_86690 */

/* fzgx:begin fn_1_866B4 pool noprologue */
#include "types.h"
#include "rel/main_rel/car.h"

struct fn_1_866B4_entry {
    u8 pad_0[4];
    s16 unk_4;
    u8 pad_6[0x46E];
    s8 unk_474;
};
struct fn_1_866B4_car {
    u8 pad_0[0x32C];
    struct fn_1_866B4_entry *unk_32C;
    u8 pad_330[0x110];
};

#pragma opt_loop_invariants on
#pragma opt_common_subs off
u32 fzgx_obj_lbl_1_bss_6D820;
u32 fzgx_obj_lbl_1_bss_6D824;
u32 lbl_1_bss_6D828;
u32 fzgx_obj_lbl_1_bss_6D82C[3];
u32 fzgx_obj_lbl_1_bss_6D838;
u8 *fzgx_obj_lbl_1_bss_6D83C;
u32 lbl_1_bss_6D83C__fzgx_offset_4[2];
u16 lbl_1_bss_6D83C__fzgx_offset_C;
s8 fzgx_obj_lbl_1_bss_6D84A;
u8 lbl_1_bss_6D84A__fzgx_offset_1;
u32 lbl_1_bss_6D84A__fzgx_offset_2;
u32 lbl_1_bss_6D850;
u32 lbl_1_bss_6D854[4];
u32 fzgx_obj_lbl_1_bss_6D864;
u32 fzgx_obj_lbl_1_bss_6D868;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D820;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D824;
    s = *(u8 *)&lbl_1_bss_6D828;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D82C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D838;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D83C;
    s = *(u8 *)&lbl_1_bss_6D83C__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6D83C__fzgx_offset_C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D84A;
    s = *(u8 *)&lbl_1_bss_6D84A__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_6D84A__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_6D850;
    s = *(u8 *)&lbl_1_bss_6D854;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D864;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D868;
}
#pragma section code_type ".text"

#pragma opt_lifetimes off
s32 fn_1_866B4(u32 arg0) {
    s16 v6;
    struct fn_1_866B4_car *v0;
    s16 v1;
    s8 v4;
    s16 v2;

    v2 = 0;
    v0 = (struct fn_1_866B4_car *)fzgx_obj_lbl_1_bss_6D83C;
    v1 = fzgx_obj_lbl_1_bss_6D84A;
    while (v2 < v1) {
        if ((s8)arg0 == ((v2)[v0]).unk_32C->unk_474) {
            v4 = (s8)((v2)[v0]).unk_32C->unk_4;
            return v4;
        }
        v2++;
    }
    {
    u8 *table = (u8 *)&fzgx_obj_lbl_1_bss_6D868;
    v2 = 0;
    while (v2 < v1) {
        if ((s32)(((s8)arg0)[table]) == ((v2)[v0]).unk_32C->unk_4) {
            return (s8)((v2)[v0]).unk_32C->unk_4;
        }
        v2++;
    }
    }
    return -1;
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_866B4 */

/* fzgx:begin fn_1_8677C */
u32 fn_1_8677C(u32 arg0) {
    u32 v0;
    u8 v1;

    v0 = (*((u32 *)&lbl_1_bss_6D838)) + (arg0 * 1568);
    v1 = 0;
    while (v1 < 4) {
        if ((*(u32 *)((u8 *)v0 + 580 + (v1 * 92)) & 0x4) != 0) {
            return 1;
        }
        v1++;
    }
    return 0;
}
/* fzgx:end fn_1_8677C */

/* fzgx:begin fn_1_867CC */
struct fn_1_867CC_Arg1 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

u32 fn_1_867CC(u32 arg0, struct fn_1_867CC_Arg1 *arg1) {
    u32 v0;
    u32 v1;
    u32 v2;
    v0 = ((*((u32 *)&lbl_1_bss_6D838)) + (arg0 * 1568));
    v1 = *(u32 *)((u8 *)v0 + 1184);
    v2 = *(u32 *)((u8 *)v0 + 1188);
    arg1->unk_0 = v1;
    arg1->unk_4 = v2;
    arg1->unk_8 = *(u32 *)((u8 *)v0 + 1192);
    return v1;
}
/* fzgx:end fn_1_867CC */

/* fzgx:begin fn_1_867F8 */
// Return the indexed car's stored float value.
f32 fn_1_867F8(int index) {
    return lbl_1_bss_6D838[index].unk_184;
}
/* fzgx:end fn_1_867F8 */

/* fzgx:begin fn_1_86810 */
// Return the indexed car object's status byte.
u8 fn_1_86810(int index) {
    u8 *object = (u8 *)lbl_1_bss_6D838[index].unk_49C;
    return object[0x115];
}
/* fzgx:end fn_1_86810 */

/* fzgx:begin fn_1_8682C */
u8 fn_1_8682C(int index) {
    return lbl_1_bss_6DA5C[index];
}
/* fzgx:end fn_1_8682C */

/* fzgx:begin fn_1_8683C */
// Return the indexed car object's stored halfword value.
s16 fn_1_8683C(int index) {
    return lbl_1_bss_6D838[index].unk_188;
}
/* fzgx:end fn_1_8683C */

/* fzgx:begin fn_1_86854 */
typedef struct {
    u8 pad_0[0x328];
    u8 id;
    u8 pad_329[0x117];
} fn_1_86854_Entry;


fn_1_86854_Entry *fn_1_86854(int id) {
    fn_1_86854_Entry *base = (*((fn_1_86854_Entry * *)&lbl_1_bss_6D83C));
    s8 count = (*((s8 *)&lbl_1_bss_6D84A));
    s8 i;

    for (i = 0; i < count; i++) {
        fn_1_86854_Entry *entry = &base[i];

        if (entry == 0) {
            break;
        }
        if ((s8)id == (s8)entry->id) {
            return &base[i];
        }
    }
    return 0;
}
/* fzgx:end fn_1_86854 */

/* fzgx:begin fn_1_868C0 */
void *fn_1_868C0(s8 index) {
    if (index < (s8)lbl_1_bss_6D84A) {
        if (lbl_1_bss_6D83C.unk_0 != 0) {
            return (void *)((u8 *)lbl_1_bss_6D83C.unk_0 + index * 0x440);
        }
    }
    return 0;
}
/* fzgx:end fn_1_868C0 */

/* fzgx:begin fn_1_86900 pool */
typedef struct {
    u8 pad_0[0x1C];
    u8 *unk_1C;
    u8 pad_20[0xA];
    s8 unk_2A;
    u8 pad_2B[0x1D];
    u16 unk_48[1];
} Manager_1_86900;

#pragma opt_loop_invariants on
#pragma opt_lifetimes off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6D820;
u32 fzgx_obj_lbl_1_bss_6D824;
u32 lbl_1_bss_6D828;
u32 fzgx_obj_lbl_1_bss_6D82C[3];
u32 fzgx_obj_lbl_1_bss_6D838;
u8 *fzgx_obj_lbl_1_bss_6D83C;
u32 lbl_1_bss_6D83C__fzgx_offset_4[2];
u16 lbl_1_bss_6D83C__fzgx_offset_C;
s8 fzgx_obj_lbl_1_bss_6D84A;
u8 lbl_1_bss_6D84A__fzgx_offset_1;
u32 lbl_1_bss_6D84A__fzgx_offset_2;
u32 lbl_1_bss_6D850;
u32 lbl_1_bss_6D854[4];
u32 fzgx_obj_lbl_1_bss_6D864;
u32 fzgx_obj_lbl_1_bss_6D868;
u8 lbl_1_bss_6D86C__fzgx_offset_0;
u16 lbl_1_bss_6D86C__fzgx_offset_2;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D820;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D824;
    s = *(u8 *)&lbl_1_bss_6D828;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D82C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D838;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D83C;
    s = *(u8 *)&lbl_1_bss_6D83C__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6D83C__fzgx_offset_C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D84A;
    s = *(u8 *)&lbl_1_bss_6D84A__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_6D84A__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_6D850;
    s = *(u8 *)&lbl_1_bss_6D854;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D864;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D868;
    s = *(u8 *)&lbl_1_bss_6D86C__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_6D86C__fzgx_offset_2;
}
#pragma section code_type ".text"

#pragma opt_common_subs off
void *fn_1_86900(s32 arg0) {
    
    s8 i;
    u8 *base = fzgx_obj_lbl_1_bss_6D83C;
    s16 count = fzgx_obj_lbl_1_bss_6D84A;
    {
        s16 fzgx_loop_i_348;
        for (fzgx_loop_i_348 = 0; fzgx_loop_i_348 < count; fzgx_loop_i_348++) {
            if ((s8)arg0 == (s8)*(u8 *)((u8 *)*(u32 *)(base + 0x32C + fzgx_loop_i_348 * 0x440) + 0x474)) {
                return base + fzgx_loop_i_348 * 0x440;
            }
        }
        i = fzgx_loop_i_348;
    }
    {
        s32 id;
        s16 fzgx_loop_i_498;
        id = (s8)((s8)arg0);
        for (fzgx_loop_i_498 = 0; fzgx_loop_i_498 < count; fzgx_loop_i_498++) {
            if (((*(u8 (*)[1])&fzgx_obj_lbl_1_bss_6D868))[id] == *(s16 *)((u8 *)*(u32 *)((((base) + (fzgx_loop_i_498 * 0x440)) + (0x32C))) + 4)) {
                return base + fzgx_loop_i_498 * 0x440;
            }
        }
        i = fzgx_loop_i_498;
    }
    return 0;
}
#pragma opt_common_subs reset

#pragma opt_lifetimes reset
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_86900 */

/* fzgx:begin fn_1_869B0 noprologue */
#include "types.h"

typedef struct {
    u8 pad_0[0x50];
    u32 value_50;
    u32 value_54;
    u32 value_58;
} Data_1_869B0;

typedef struct {
    u8 pad_0[0x49c];
    Data_1_869B0 *data;
    u8 pad_4a0[0x180];
} Entry_1_869B0;

extern Entry_1_869B0 *lbl_1_bss_6D838;

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Vec3_1_869B0;

void fn_1_869B0(int index, u32 *out) {
    Data_1_869B0 *data = (Data_1_869B0 *)lbl_1_bss_6D838[index].data;
    *(Vec3_1_869B0 *)out = *(Vec3_1_869B0 *)&data->value_50;
}
/* fzgx:end fn_1_869B0 */

/* fzgx:begin fn_1_869E0 noprologue */
#include "types.h"

typedef struct {
    u8 pad_0[0x5c];
    u32 value_5c;
    u32 value_60;
    u32 value_64;
} CarData;

typedef struct {
    u8 pad_0[0x49c];
    CarData *unk_49c;
    u8 pad_4a0[0x180];
} Car;

typedef struct {
    u32 value_0;
    u32 value_4;
    u32 value_8;
} Copy12;

extern Car *lbl_1_bss_6D838;

void fn_1_869E0(int index, u32 *out) {
    CarData *data = lbl_1_bss_6D838[index].unk_49c;
    *(Copy12 *)out = *(Copy12 *)&data->value_5c;
}
/* fzgx:end fn_1_869E0 */

/* fzgx:begin fn_1_86A10 */
u8 fn_1_86A10(u32 arg0) {
    return ((u8 *)lbl_1_bss_6D838)[arg0 * 0x620 + 0x482];
}
/* fzgx:end fn_1_86A10 */

/* fzgx:begin fn_1_87074 */
void fn_1_87074(void) {
    u32 zero;
    u8 i;

    zero = 0;
    for (i = 0; i < 30; i += 6) {
        *(u32 *)((u8 *)lbl_1_bss_6D8F4 + ((i & 0xFF) << 2)) = zero;
        *(u32 *)((u8 *)lbl_1_bss_6D8F4 + ((i & 0xFF) << 2) + 4) = zero;
        *(u32 *)((u8 *)lbl_1_bss_6D8F4 + ((i & 0xFF) << 2) + 8) = zero;
        *(u32 *)((u8 *)lbl_1_bss_6D8F4 + ((i & 0xFF) << 2) + 12) = zero;
        *(u32 *)((u8 *)lbl_1_bss_6D8F4 + ((i & 0xFF) << 2) + 16) = zero;
        *(u32 *)((u8 *)lbl_1_bss_6D8F4 + ((i & 0xFF) << 2) + 20) = zero;
    }
}
/* fzgx:end fn_1_87074 */

/* fzgx:begin fn_1_87238 */
struct CarSlot {
    struct Model **model_ptr;
    char pad[8];
};

struct fn_1_87238_Car {
    char pad[0x328];
    s8 field_0x328;
    char pad1[0xb];
    struct CarSlot slots[1];
    char pad2[0x50];
    u32 flags;
};





#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.0f;
    s = 2.0f;
}
static const u32 fzgx_pool_table2[1] = {0x40000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.5f;
    s = 0.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.1920928955078125e-07;
    s = 1.4499999284744263f;
}
static const u32 fzgx_pool_table6[1] = {0x9999999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.15000000074505807;
    s = 0.05000000074505806f;
    s = 30.0f;
    s = 0.00390625f;
    s = 182.04444885253906f;
    s = 180.0f;
    s = 44.0f;
    s = 89.0f;
    s = 360.0f;
    s = 60.0f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.12999999932944775;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table14[306] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00330000, 0x00010001, 0x00020002, 0x00030003, 0x0004002F, 0x00050004, 0x00060005, 0x00070006, 0x00080007, 0x00090008, 0x000A002A, 0x000B0009, 0x000C002B, 0x000D000A, 0x000E002C, 0x000F000B, 0x0010002D, 0x0011000C, 0x0012002E, 0x0013000D, 0x0014000E, 0x003D000F, 0x003E0010, 0x003F0011, 0x00400012, 0x00410013, 0x00420014, 0x00430015, 0x00440016, 0x00450017, 0x00460018, 0x00470019, 0x0048001A, 0x0049001B, 0x004A001C, 0x004B001D, 0x004C0034, 0x004D0035, 0x004E0036, 0x004F0037, 0x001F001E, 0x0020001F, 0x00210020, 0x00220021, 0x00230022, 0x00240023, 0x00250024, 0x00260025, 0x00270026, 0x00280027, 0x00290028, 0x002A0029, 0x00500038, 0x00510030, 0x00520031, 0x00530032, 0x00540033, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
}
static const u32 fzgx_pool_table16[3] = {0x0032001E, 0x00140004, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    d = 0.20000000298023224;
    s = 0.10000000149011612f;
    s = 0.11999999731779099f;
    s = -0.10000000149011612f;
    s = -1.0f;
    s = 0.8999999761581421f;
    s = 0.49000000953674316f;
    d = 0.800000011920929;
    s = 0.4000000059604645f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
}
static const u32 fzgx_pool_table20[3] = {0x3F000000, 0x40000000, 0xB4000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 240.0f;
    s = 0.75f;
}
static const u32 fzgx_pool_table22[1] = {0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1000.0f;
}
static const u32 fzgx_pool_table24[29] = {0xFFFFFFFF, 0xFFFFFFFF, 0x3F800000, 0x3F800000, 0x3F800000, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
}
static const u32 fzgx_pool_table26[16] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 1.0;
    s = 15.0f;
    s = 0.009999999776482582f;
    s = 255.0f;
    s = 128.0f;
}
#pragma section code_type ".text"
void fn_1_87238(struct fn_1_87238_Car *car, s8 index, f32 f1) {
    struct ModelItem *item;
    int i;
    int field_0x328;
    u32 flag;
    int is_one;
    struct Model *model;

    if (f1 == 0.0f) {
        return;
    }

    is_one = (f1 == 1.0f);
    model = *car->slots[index].model_ptr;
    if (model == NULL) {
        return;
    }

    field_0x328 = car->field_0x328;
    item = model->items;
    flag = car->flags & 0x00100000;

    for (i = 0; i < model->count; i++, item++) {
        if (!(item->flags & 0x00020000)) {
            continue;
        }

        if (field_0x328 == 0x26) {
            fn_1_56018(1);
            lbl_8006D784(&((struct TargetObj *)lbl_801A6D00)->field_0x60);
            ((struct TargetObj *)lbl_801A6D00)->field_0x6c = (f32)(u8)lbl_801A66A0 / 255.0f;
            fn_1_560F0(0, &((struct TargetObj *)lbl_801A6D00)->field_0x60);
        } else if (flag) {
            fn_1_56018(1);
            lbl_8006D784(&((struct TargetObj *)lbl_801A6D00)->field_0x60);
            ((struct TargetObj *)lbl_801A6D00)->field_0x7c = lbl_8006D188((s16)((int)((lbl_801A66A0 % 180) * 182.04445f) + 0x4000));
            fn_1_560F0(0, &((struct TargetObj *)lbl_801A6D00)->field_0x60);
        }
    }

    fn_80072558();
    if (is_one) {
        fn_1_556B8( (void *)(struct Model *)(model));
    } else {
        fn_1_55FF0(f1);
        fn_1_55210( (void *)(struct Model *)(model));
    }
    fn_1_56018(0);
}
/* fzgx:end fn_1_87238 */

/* fzgx:begin fn_1_87448 noprologue */
#include "types.h"

typedef struct {
    u8 pad_00[0x1C];
    u16 unk_1C;
} Sig_fn_1_55628_Fn1_55628Object;

typedef struct {
    u8 pad_00[2];
    s8 unk_02;
} Fn1_87448_Arg1;

typedef struct {
    u32 unk_00;
    u8 *unk_04;
} Fn1_87448_Ent;

typedef struct {
    s32 unk_00;
    u32 pad_04;
    Fn1_87448_Ent *unk_08;
} Fn1_87448_Tab;

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

extern f32 lbl_1_rodata_3518[6];
extern f32 lbl_1_rodata_3530[22];
extern u32 lbl_8006DBE4(void);
extern u32 lbl_8006DFC4(u32);
extern u8 *fn_80083970(u8 *, const u8 *);
extern void fn_1_55628(Sig_fn_1_55628_Fn1_55628Object *);
extern void fn_1_556B8(void *);
extern void fn_1_55FF0(f32);
extern void fn_80072558(void);

#pragma opt_dead_assignments off
extern void OSReport(const char *, ...);
#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("pos_");
}
#pragma section code_type ".text"

static inline f32 fn_1_87448_array_read(s32 index, f32 *array) { return array[index]; }
#pragma opt_lifetimes off
void fn_1_87448(Fn1_87448_Obj *self, Fn1_87448_Arg1 *arg1, s8 arg2, int flag, f32 f) {
    s32 k;
    u8 **row;
    s32 n;
    Fn1_87448_Tab *tab;
    s32 below;
    void *p;
    s16 lim;

    lim = 0;
    tab = (Fn1_87448_Tab *)self->unk_334[arg2].unk_04;
    if (f <= fn_1_87448_array_read(0, lbl_1_rodata_3518)) {
        return;
    }
    below = f < fn_1_87448_array_read(0, lbl_1_rodata_3530);
    if (arg1 != 0) {
        lim = arg1->unk_02;
    }
    k = 1;
    n = 0;
    for (; k < tab->unk_00; k++) {
        if (n > (s32)lim - 1) {
            break;
        }
        if (fn_80083970((*((k) + (tab->unk_08))).unk_04, (u8 *)"pos_") != tab->unk_08[k].unk_04) {
            row = self->unk_334[arg2].unk_00;
            p = row[k];
            if (p == 0) {
                n += 1;
                continue;
            }
            if (below != 0) {
                fn_1_55FF0(f);
            }
            lbl_8006DBE4();
            lbl_8006DFC4(self->unk_330 + n * 0x30);
            fn_80072558();
            if (flag != 0) {
                fn_1_556B8(p);
            } else {
                fn_1_55628((Sig_fn_1_55628_Fn1_55628Object *)p);
            }
            n += 1;
        }
    }
}
#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_87448 */

/* fzgx:begin fn_1_875B4 */
void fn_1_875B4(void *arg, int value_1, int value_2, f32 value) {
    fn_1_87448(arg, value_1, value_2, value >= 1.0f, value);
}
/* fzgx:end fn_1_875B4 */

/* fzgx:begin fn_1_875EC */
void fn_1_875EC(void *arg0, void *arg1, void *arg2) {
    fn_1_87448(arg0, arg1, arg2, 1);
}
/* fzgx:end fn_1_875EC */

/* fzgx:begin fn_1_87610 */
typedef struct Fn187610Object {
    u8 pad_000[0x328];
    s8 field_328;
    u8 pad_329[7];
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn187610Object;

typedef struct Fn187610Data {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x205];
    u8 field_208[0x120];
} Fn187610Data;

void fn_1_87610(Fn187610Object *object, Fn187610Data *data) {
    u8 value[12];
    int i;
    s16 result;

    if (data != 0) {
        for (i = 0; i < data->field_002; i++) {
            switch (object->field_328) {
            case 40:
                switch (object->field_3BA) {
                case 0:
                    switch (i) {
                    case 0:
                        result = 1;
                        break;
                    case 1:
                        result = 2;
                        break;
                    case 2:
                        result = 0;
                        break;
                    default:
                        result = 0;
                        break;
                    }
                    break;
                case 1:
                case 2:
                case 3:
                    switch (i) {
                    case 0:
                        result = 0;
                        break;
                    case 1:
                        result = 1;
                        break;
                    case 2:
                        result = 2;
                        break;
                    default:
                        result = 0;
                        break;
                    }
                    break;
                }
                break;
            default:
                result = i;
                break;
            }

            fn_80008BA8(value, &data->field_208[i * 20], 12);
            lbl_8006D7DC(value);
            lbl_8006DB74((u8 *)object->field_330 + result * 0x30);
        }
    }
}
/* fzgx:end fn_1_87610 */

/* fzgx:begin fn_1_87750 */
typedef struct Fn187750Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn187750Inner;

typedef struct Fn187750Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn187750Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn187750Object;

void fn_1_87750(Fn187750Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_87750 */

/* fzgx:begin fn_1_877E8 */
typedef struct Fn1877E8Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn1877E8Inner;

typedef struct Fn1877E8Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn1877E8Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn1877E8Object;

void fn_1_877E8(Fn1877E8Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_877E8 */

/* fzgx:begin fn_1_87880 */
typedef struct Fn187880Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn187880Inner;

typedef struct Fn187880Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn187880Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn187880Object;

void fn_1_87880(Fn187880Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_87880 */

/* fzgx:begin fn_1_87918 */
typedef struct Fn187918Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn187918Inner;

typedef struct Fn187918Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn187918Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn187918Object;

void fn_1_87918(Fn187918Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_87918 */

/* fzgx:begin fn_1_879B0 */
typedef struct Fn1879B0Inner {
    u8 pad_000[0xA4];
    f32 value_A4;
    u8 pad_A8[0x154];
    f32 value_1FC;
} Fn1879B0Inner;

typedef struct Fn1879B0Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x209];
    u8 field_20C[0x110];
    u8 field_31C[0x10];
    Fn1879B0Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn1879B0Object;

void fn_1_879B0(Fn1879B0Object *object) {
    u8 value1[12];
    u8 value2[12];
    f32 *constants;
    f32 clamped;
    f32 rate;
    f32 product;

    constants = (((f32 *)&lbl_1_rodata_3508));
    fn_80008BA8(value1, (u8 *)object + 0x208, 12);
    lbl_8006D7DC(value1);

    if (object->field_32C != 0) {
        clamped = constants[458];
        rate = clamped * object->field_32C->value_A4;
        product = rate * constants[16];
        if (product < clamped) {
            clamped = constants[458];
        } else if (product > constants[15]) {
            clamped = constants[15];
        } else {
            clamped = product;
        }
        mathutil_mtxA_rotate_y((int)(constants[17] * clamped));
    }

    lbl_8006DB74(object->field_330);

    if (object != 0 && object->field_3BA == 0 && object->field_002 - 1 >= 1) {
        fn_80008BA8(value2, (u8 *)object + 0x21c, 12);
        lbl_8006D7DC(value2);
        if (object->field_32C != 0) {
            mathutil_mtxA_rotate_z((int)(constants[457] * -object->field_32C->value_1FC));
        }
        lbl_8006DB74((u8 *)object->field_330 + 0x30);
    }
}
/* fzgx:end fn_1_879B0 */

/* fzgx:begin fn_1_87AD8 */
typedef struct Fn187AD8Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn187AD8Inner;

typedef struct Fn187AD8Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn187AD8Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn187AD8Object;

void fn_1_87AD8(Fn187AD8Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_87AD8 */

/* fzgx:begin fn_1_87B70 */
typedef struct Fn187B70Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn187B70Inner;

typedef struct Fn187B70Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn187B70Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn187B70Object;

void fn_1_87B70(Fn187B70Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_87B70 */

/* fzgx:begin fn_1_87C08 */
typedef struct Fn187C08Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn187C08Inner;

typedef struct Fn187C08Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn187C08Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn187C08Object;

void fn_1_87C08(Fn187C08Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_87C08 */

/* fzgx:begin fn_1_87CA0 */
typedef struct Fn187CA0Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn187CA0Inner;

typedef struct Fn187CA0Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn187CA0Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn187CA0Object;

void fn_1_87CA0(Fn187CA0Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_87CA0 */

/* fzgx:begin fn_1_87D38 */
typedef struct Fn187D38Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn187D38Inner;

typedef struct Fn187D38Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn187D38Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn187D38Object;

void fn_1_87D38(Fn187D38Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_87D38 */

/* fzgx:begin fn_1_87DD0 */
typedef struct Fn187DD0Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn187DD0Inner;

typedef struct Fn187DD0Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn187DD0Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn187DD0Object;

void fn_1_87DD0(Fn187DD0Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_87DD0 */

/* fzgx:begin fn_1_87E68 */
typedef struct Fn187E68Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn187E68Inner;

typedef struct Fn187E68Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn187E68Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn187E68Object;

void fn_1_87E68(Fn187E68Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_87E68 */

/* fzgx:begin fn_1_87F00 */
typedef struct Fn187F00Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn187F00Inner;

typedef struct Fn187F00Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn187F00Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn187F00Object;

void fn_1_87F00(Fn187F00Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_87F00 */

/* fzgx:begin fn_1_87F98 */
typedef struct Fn187F98Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn187F98Inner;

typedef struct Fn187F98Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn187F98Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn187F98Object;

void fn_1_87F98(Fn187F98Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_87F98 */

/* fzgx:begin fn_1_88030 */
typedef struct Fn188030Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn188030Inner;

typedef struct Fn188030Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn188030Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn188030Object;

void fn_1_88030(Fn188030Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_88030 */

/* fzgx:begin fn_1_880C8 */
typedef struct Fn1880C8Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn1880C8Inner;

typedef struct Fn1880C8Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn1880C8Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn1880C8Object;

void fn_1_880C8(Fn1880C8Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_880C8 */

/* fzgx:begin fn_1_88160 */
typedef struct Fn88160Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn88160Inner;

typedef struct Fn88160Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn88160Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn88160Object;

void fn_1_88160(Fn88160Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_88160 */

/* fzgx:begin fn_1_881F8 */
typedef struct Fn881F8Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn881F8Inner;

typedef struct Fn881F8Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn881F8Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn881F8Object;

void fn_1_881F8(Fn881F8Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_881F8 */

/* fzgx:begin fn_1_88290 */
typedef struct Fn88290Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn88290Inner;

typedef struct Fn88290Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn88290Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn88290Object;

void fn_1_88290(Fn88290Object *object) {
    s8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_88290 */

/* fzgx:begin fn_1_88328 */
typedef struct Fn88328Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn88328Inner;

typedef struct Fn88328Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn88328Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn88328Object;

void fn_1_88328(Fn88328Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_88328 */

/* fzgx:begin fn_1_883C0 */
typedef struct Fn883C0Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn883C0Inner;

typedef struct Fn883C0Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn883C0Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn883C0Object;

void fn_1_883C0(Fn883C0Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_883C0 */

/* fzgx:begin fn_1_88458 */
typedef struct Fn88458Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn88458Inner;

typedef struct Fn88458Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn88458Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn88458Object;

void fn_1_88458(Fn88458Object *object) {
    u8 value_1[12];
    u8 value_2[12];

    if (object != 0 && object->field_3BA == 0 && object->field_002 - 1 >= 0) {
        fn_80008BA8(value_1, object->field_208, 12);
        lbl_8006D7DC(value_1);

        if (object->field_32C != 0) {
            mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
        }

        lbl_8006DB74(object->field_330);
    }

    if (object != 0 && object->field_3BA == 0 && object->field_002 - 1 >= 1) {
        fn_80008BA8(value_2, &object->field_208[0x14], 12);
        lbl_8006D7DC(value_2);

        if (object->field_32C != 0) {
            mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
        }

        lbl_8006DB74((u8 *)object->field_330 + 0x30);
    }
}
/* fzgx:end fn_1_88458 */

/* fzgx:begin fn_1_8856C */
typedef struct Fn8856CInner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn8856CInner;

typedef struct Fn8856CObject {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn8856CInner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn8856CObject;

void fn_1_8856C(Fn8856CObject *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_8856C */

/* fzgx:begin fn_1_88604 */
typedef struct Fn88604Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn88604Inner;

typedef struct Fn88604Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn88604Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn88604Object;

void fn_1_88604(Fn88604Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_88604 */

/* fzgx:begin fn_1_8869C */
typedef struct Fn8869CInner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn8869CInner;

typedef struct Fn8869CObject {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn8869CInner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn8869CObject;

void fn_1_8869C(Fn8869CObject *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_8869C */

/* fzgx:begin fn_1_88734 */
typedef struct Fn1_88734Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn1_88734Inner;

typedef struct Fn1_88734Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn1_88734Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn1_88734Object;

void fn_1_88734(Fn1_88734Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_88734 */

/* fzgx:begin fn_1_887CC */
typedef struct Fn1_887CCInner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn1_887CCInner;

typedef struct Fn1_887CCObject {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn1_887CCInner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn1_887CCObject;

void fn_1_887CC(Fn1_887CCObject *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_887CC */

/* fzgx:begin fn_1_88864 */
typedef struct Fn1_88864Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn1_88864Inner;

typedef struct Fn1_88864Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn1_88864Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn1_88864Object;

void fn_1_88864(Fn1_88864Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_88864 */

/* fzgx:begin fn_1_888FC */
typedef struct Fn1_888FCInner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn1_888FCInner;

typedef struct Fn1_888FCObject {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn1_888FCInner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn1_888FCObject;

void fn_1_888FC(Fn1_888FCObject *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_888FC */

/* fzgx:begin fn_1_88994 */
typedef struct Fn1_88994Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn1_88994Inner;

typedef struct Fn1_88994Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn1_88994Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn1_88994Object;

void fn_1_88994(Fn1_88994Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_88994 */

/* fzgx:begin fn_1_88A2C */
typedef struct Fn1_88A2CInner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn1_88A2CInner;

typedef struct Fn1_88A2CObject {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn1_88A2CInner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn1_88A2CObject;

void fn_1_88A2C(Fn1_88A2CObject *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_88A2C */

/* fzgx:begin fn_1_88AC4 */
typedef struct Fn1_88AC4Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn1_88AC4Inner;

typedef struct Fn1_88AC4Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn1_88AC4Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn1_88AC4Object;

void fn_1_88AC4(Fn1_88AC4Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_88AC4 */

/* fzgx:begin fn_1_88B5C */
typedef struct Fn1_88B5CInner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn1_88B5CInner;

typedef struct Fn1_88B5CObject {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn1_88B5CInner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn1_88B5CObject;

void fn_1_88B5C(Fn1_88B5CObject *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_88B5C */

/* fzgx:begin fn_1_88BF4 */
typedef struct Fn1_88BF4Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn1_88BF4Inner;

typedef struct Fn1_88BF4Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn1_88BF4Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn1_88BF4Object;

void fn_1_88BF4(Fn1_88BF4Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_88BF4 */

/* fzgx:begin fn_1_88C8C */
typedef struct Fn1_88C8CInner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn1_88C8CInner;

typedef struct Fn1_88C8CObject {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn1_88C8CInner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn1_88C8CObject;

void fn_1_88C8C(Fn1_88C8CObject *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_88C8C */

/* fzgx:begin fn_1_88D24 */
typedef struct Fn1_88D24Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn1_88D24Inner;

typedef struct Fn1_88D24Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn1_88D24Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn1_88D24Object;

void fn_1_88D24(Fn1_88D24Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_88D24 */

/* fzgx:begin fn_1_88DBC */
typedef struct Fn1_88DBCInner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn1_88DBCInner;

typedef struct Fn1_88DBCObject {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn1_88DBCInner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn1_88DBCObject;

void fn_1_88DBC(Fn1_88DBCObject *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_88DBC */

/* fzgx:begin fn_1_88E54 */
typedef struct Fn1_88E54Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn1_88E54Inner;

typedef struct Fn1_88E54Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn1_88E54Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn1_88E54Object;

void fn_1_88E54(Fn1_88E54Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_88E54 */

/* fzgx:begin fn_1_88EEC */
typedef struct Fn88EECInner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn88EECInner;

typedef struct Fn88EECObject {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn88EECInner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn88EECObject;

void fn_1_88EEC(Fn88EECObject *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_88EEC */

/* fzgx:begin fn_1_88F84 */
typedef struct Fn1_88F84Inner {
    u8 pad_000[0x1FC];
    f32 value_1FC;
} Fn1_88F84Inner;

typedef struct Fn1_88F84Object {
    u8 pad_000[2];
    s8 field_002;
    u8 pad_003[0x208 - 3];
    u8 field_208[0x124];
    Fn1_88F84Inner *field_32C;
    void *field_330;
    u8 pad_334[0x86];
    s16 field_3BA;
} Fn1_88F84Object;

void fn_1_88F84(Fn1_88F84Object *object) {
    u8 value[12];

    if (object == 0) {
        return;
    }
    if (object->field_3BA != 0) {
        return;
    }
    if (object->field_002 - 1 < 0) {
        return;
    }

    fn_80008BA8(value, object->field_208, 12);
    lbl_8006D7DC(value);

    if (object->field_32C != 0) {
        mathutil_mtxA_rotate_z((int)(lbl_1_rodata_3C2C[0] * -object->field_32C->value_1FC));
    }

    lbl_8006DB74(object->field_330);
}
/* fzgx:end fn_1_88F84 */

/* fzgx:begin fn_1_892E8 */
#pragma optimization_level 0
void fn_1_892E8(u32 *p, u32 val) {
    val = val - val;
    p[0] = val;
    p[1] = val;
    p[2] = val;
}
/* fzgx:end fn_1_892E8 */

/* fzgx:begin fn_1_8A168 */
void fn_1_8A168(void *arg0) {
    fn_1_892FC(arg0, 0, 0);
}
/* fzgx:end fn_1_8A168 */

/* fzgx:begin fn_1_8A190 */
void fn_1_8A190(void *arg0, void *arg1) {
    fn_1_8A1B4(arg0, arg1, 0);
}
/* fzgx:end fn_1_8A190 */

/* fzgx:begin fn_1_8B880 */
void fn_1_8B880(void) {
    fn_1_8B8A4( (void *)(s32)(0));
}
/* fzgx:end fn_1_8B880 */

/* fzgx:begin fn_1_8B8A4 pool */
typedef struct CarInfo {
    u8 pad_0[0x115];
    u8 unk_115;
} CarInfo;

typedef struct CarObj {
    u8 pad_0[0x49C];
    CarInfo *info;
} CarObj;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6D820;
u32 fzgx_obj_lbl_1_bss_6D824;
u32 fzgx_obj_lbl_1_bss_6D828;
u32 fzgx_obj_lbl_1_bss_6D82C[3];
CarObj *fzgx_obj_lbl_1_bss_6D838;
u8 fzgx_obj_lbl_1_bss_6D83C[14];
u8 fzgx_obj_lbl_1_bss_6D84A;
u8 fzgx_obj_lbl_1_bss_6D84A__b1;
u8 fzgx_obj_lbl_1_bss_6D84A__b2;
u8 fzgx_obj_lbl_1_bss_6D84A__b3;
u8 fzgx_obj_lbl_1_bss_6D84A__b4;
u8 fzgx_obj_lbl_1_bss_6D84A__b5;
u32 fzgx_obj_lbl_1_bss_6D850;
u32 fzgx_obj_lbl_1_bss_6D854[4];
u32 fzgx_obj_lbl_1_bss_6D864;
u8 fzgx_obj_lbl_1_bss_6D868;
u32 fzgx_obj_lbl_1_bss_6D86C[34];
u32 fzgx_obj_lbl_1_bss_6D8F4[31];
u32 fzgx_obj_lbl_1_bss_6D970;
u32 fzgx_obj_lbl_1_bss_6D974;
u32 fzgx_obj_lbl_1_bss_6D978;
u32 fzgx_obj_lbl_1_bss_6D97C;
u32 fzgx_obj_lbl_1_bss_6D980[8];
u32 fzgx_obj_lbl_1_bss_6D9A0[39];
u8 lbl_1_bss_6D9A0__fzgx_offset_9C[0x20];
u8 fzgx_obj_lbl_1_bss_6DA5C[0x1E];
u8 fzgx_obj_lbl_1_bss_6DA7A;
u8 fzgx_obj_lbl_1_bss_6DA7B;
u8 fzgx_obj_lbl_1_bss_6DA7B__b1;
u8 fzgx_obj_lbl_1_bss_6DA7B__b2;
u8 fzgx_obj_lbl_1_bss_6DA7B__b3;
u8 fzgx_obj_lbl_1_bss_6DA7B__b4;
u32 fzgx_obj_lbl_1_bss_6DA80[440];
u32 fzgx_obj_lbl_1_bss_6E160[435];
u32 fzgx_obj_lbl_1_bss_6E82C[75];

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_6D820;
    s = fzgx_obj_lbl_1_bss_6D824;
    s = fzgx_obj_lbl_1_bss_6D828;
    s = fzgx_obj_lbl_1_bss_6D82C[0];
    s = *(u32 *)&fzgx_obj_lbl_1_bss_6D838;
    s = fzgx_obj_lbl_1_bss_6D83C[0];
    s = fzgx_obj_lbl_1_bss_6D84A;
    s = fzgx_obj_lbl_1_bss_6D84A__b1;
    s = fzgx_obj_lbl_1_bss_6D84A__b2;
    s = fzgx_obj_lbl_1_bss_6D84A__b3;
    s = fzgx_obj_lbl_1_bss_6D84A__b4;
    s = fzgx_obj_lbl_1_bss_6D84A__b5;
    s = fzgx_obj_lbl_1_bss_6D850;
    s = fzgx_obj_lbl_1_bss_6D854[0];
    s = fzgx_obj_lbl_1_bss_6D864;
    s = fzgx_obj_lbl_1_bss_6D868;
    s = fzgx_obj_lbl_1_bss_6D86C[0];
    s = fzgx_obj_lbl_1_bss_6D8F4[0];
    s = fzgx_obj_lbl_1_bss_6D970;
    s = fzgx_obj_lbl_1_bss_6D974;
    s = fzgx_obj_lbl_1_bss_6D978;
    s = fzgx_obj_lbl_1_bss_6D97C;
    s = fzgx_obj_lbl_1_bss_6D980[0];
    s = fzgx_obj_lbl_1_bss_6D9A0[0];
    s = lbl_1_bss_6D9A0__fzgx_offset_9C[0];
    s = fzgx_obj_lbl_1_bss_6DA5C[0];
    s = fzgx_obj_lbl_1_bss_6DA7A;
    s = fzgx_obj_lbl_1_bss_6DA7B;
    s = fzgx_obj_lbl_1_bss_6DA7B__b1;
    s = fzgx_obj_lbl_1_bss_6DA7B__b2;
    s = fzgx_obj_lbl_1_bss_6DA7B__b3;
    s = fzgx_obj_lbl_1_bss_6DA7B__b4;
    s = fzgx_obj_lbl_1_bss_6DA80[0];
    s = fzgx_obj_lbl_1_bss_6E160[0];
    s = fzgx_obj_lbl_1_bss_6E82C[0];
}
#pragma section code_type ".text"


void fn_1_8B8A4(void *arg) {
    s32 i;

    for (i = 0; i < 30; i++) {
        fzgx_obj_lbl_1_bss_6DA5C[i] = i;
        lbl_1_bss_6D9A0__fzgx_offset_9C[i] = i;
    }
    fn_800793D4( (u8 *)(void *)(fzgx_obj_lbl_1_bss_6DA80), 0, 0x6CC);
    fn_800793D4( (u8 *)(void *)(fzgx_obj_lbl_1_bss_6E160), 0, 0x6CC);
    fzgx_obj_lbl_1_bss_6DA7B__b1 = 0;
    fzgx_obj_lbl_1_bss_6DA7B__b2 = 0;
    fzgx_obj_lbl_1_bss_6DA7A = 1;
    fzgx_obj_lbl_1_bss_6DA7B = 1;
    if (fzgx_obj_lbl_1_bss_6D838 != NULL && fzgx_obj_lbl_1_bss_6D838->info != NULL) {
        fzgx_obj_lbl_1_bss_6DA7A = fzgx_obj_lbl_1_bss_6D838->info->unk_115;
        fzgx_obj_lbl_1_bss_6DA7B = fzgx_obj_lbl_1_bss_6D838->info->unk_115;
    }
    fn_1_8B9B8(arg);
}
/* fzgx:end fn_1_8B8A4 */

/* fzgx:begin fn_1_8C3EC */
u8 fn_1_8C3EC(void) {
    return lbl_1_bss_6DA7A;
}
/* fzgx:end fn_1_8C3EC */

/* fzgx:begin fn_1_8C3FC */
// fn_1_8C3FC: Load byte from BSS and return

u8 fn_1_8C3FC(void) {
    return lbl_1_bss_6DA7B[0];
}
/* fzgx:end fn_1_8C3FC */

/* fzgx:begin fn_1_8C40C */
typedef struct CarTarget CarTarget;
typedef struct fn_1_8C40C_CarEntry fn_1_8C40C_CarEntry;
typedef struct CarTable CarTable;

struct CarTarget {
    u8 unk_00[0xf8];
    f32 unk_f8;
};

struct fn_1_8C40C_CarEntry {
    u8 unk_00[0x49c];
    CarTarget *unk_49c;
    u8 unk_4a0[0x180];
};

struct CarTable {
    u8 unk_00[0x18];
    fn_1_8C40C_CarEntry *unk_18;
    u8 unk_1c[0xe];
    s8 unk_2a;
    u8 unk_2b[0x231];
    u8 unk_25c;
};

f32 fn_1_8C40C(void) {
    CarTable *table = (CarTable *)&lbl_1_bss_6D820;

    if (table->unk_25c >= table->unk_2a) {
        return lbl_1_rodata_3518[0];
    }
    return table->unk_18[table->unk_25c].unk_49c->unk_f8;
}
/* fzgx:end fn_1_8C40C */

/* fzgx:begin fn_1_8C44C */
typedef struct Fn1844CValue {
    char pad_0[0xf8];
    f32 value;
} Fn1844CValue;

typedef struct Fn1844CEntry {
    char pad_0[0x49c];
    Fn1844CValue *value;
    char pad_end[0x180];
} Fn1844CEntry;

typedef struct Fn1844CRoot {
    char pad_0[0x18];
    Fn1844CEntry *entries;
    char pad_0x1c[0xe];
    s8 threshold;
    char pad_0x2b[0x232];
    u8 index;
} Fn1844CRoot;

f32 fn_1_8C44C(void) {
    Fn1844CRoot *root = (Fn1844CRoot *)&lbl_1_bss_6D820;
    if (root->index >= root->threshold) {
        return lbl_1_rodata_3518[0];
    }
    return root->entries[root->index].value->value;
}
/* fzgx:end fn_1_8C44C */

/* fzgx:begin fn_1_8C48C */
// Return the selected car's handling value, or zero object's value when unavailable.
f32 fn_1_8C48C(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(f32 *)(ptr + 0x50);
}
/* fzgx:end fn_1_8C48C */

/* fzgx:begin fn_1_8C4BC */
f32 fn_1_8C4BC(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(f32 *)(ptr + 0x54);
}
/* fzgx:end fn_1_8C4BC */

/* fzgx:begin fn_1_8C4EC */
f32 fn_1_8C4EC(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(f32 *)(ptr + 0x58);
}
/* fzgx:end fn_1_8C4EC */

/* fzgx:begin fn_1_8C51C */
 // Return the indexed car's float field, or zero-base fallback when the car table is absent.
f32 fn_1_8C51C(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(f32 *)(ptr + 0x5c);
}
/* fzgx:end fn_1_8C51C */

/* fzgx:begin fn_1_8C54C */
f32 fn_1_8C54C(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(f32 *)(ptr + 0x60);
}
/* fzgx:end fn_1_8C54C */

/* fzgx:begin fn_1_8C57C */
f32 fn_1_8C57C(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(f32 *)(ptr + 0x64);
}
/* fzgx:end fn_1_8C57C */

/* fzgx:begin fn_1_8C5AC */
// Return the indexed car's float value.
f32 fn_1_8C5AC(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(f32 *)(ptr + 0x68);
}
/* fzgx:end fn_1_8C5AC */

/* fzgx:begin fn_1_8C5DC */
u32 fn_1_8C5DC(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(u32 *)(ptr + 0x118);
}
/* fzgx:end fn_1_8C5DC */

/* fzgx:begin fn_1_8C60C */
u32 fn_1_8C60C(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(u32 *)(ptr + 0x88);
}
/* fzgx:end fn_1_8C60C */

/* fzgx:begin fn_1_8C63C */
u32 fn_1_8C63C(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    ptr = *(u32 *)(ptr + 0x8c);
    return ptr;
}
/* fzgx:end fn_1_8C63C */

/* fzgx:begin fn_1_8C66C */
// Return the value stored in the indexed car's nested state object.
u32 fn_1_8C66C(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    ptr = *(u32 *)(ptr + 0x90);
    return *(u32 *)ptr;
}
/* fzgx:end fn_1_8C66C */

/* fzgx:begin fn_1_8C6A0 */
f32 fn_1_8C6A0(u32 index) {
    u32 base;
    u32 car;
    u32 state;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        car = base + index * 0x620;
    } else {
        car = 0;
    }

    state = *(u32 *)(car + 0x49c);
    state = *(u32 *)(state + 0x94);
    return *(f32 *)state;
}
/* fzgx:end fn_1_8C6A0 */

/* fzgx:begin fn_1_8C6D4 */
u32 fn_1_8C6D4(u32 index) {
    u32 base;
    u32 car;
    u32 state;

    // Return the requested car's value from its state block.
    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        car = base + index * 0x620;
    } else {
        car = 0;
    }

    state = *(u32 *)(car + 0x49c);
    return *(u32 *)(state + 0xb8);
}
/* fzgx:end fn_1_8C6D4 */

/* fzgx:begin fn_1_8C704 */
// Returns the selected car's value at offset 0xd8.
u32 fn_1_8C704(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(u32 *)(ptr + 0xd8);
}
/* fzgx:end fn_1_8C704 */

/* fzgx:begin fn_1_8C734 */
// Return the selected car's float field, or the null object's field when unavailable.
f32 fn_1_8C734(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(f32 *)(ptr + 0xf8);
}
/* fzgx:end fn_1_8C734 */

/* fzgx:begin fn_1_8C764 */
f32 fn_1_8C764(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(f32 *)(ptr + 0xfc);
}
/* fzgx:end fn_1_8C764 */

/* fzgx:begin fn_1_8C794 */
f32 fn_1_8C794(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(f32 *)(ptr + 0x100);
}
/* fzgx:end fn_1_8C794 */

/* fzgx:begin fn_1_8C7C4 */
// Return the selected car's status byte, or the null-entry status when unavailable.
u8 fn_1_8C7C4(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(u8 *)(ptr + 0x115);
}
/* fzgx:end fn_1_8C7C4 */

/* fzgx:begin fn_1_8C7F4 */
u8 fn_1_8C7F4(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(u8 *)(ptr + 0x116);
}
/* fzgx:end fn_1_8C7F4 */

/* fzgx:begin fn_1_8C824 */
u16 fn_1_8C824(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(u16 *)(ptr + 0x104);
}
/* fzgx:end fn_1_8C824 */

/* fzgx:begin fn_1_8C854 */
f32 fn_1_8C854(u32 index) {
    u32 base;
    u32 addr;
    u32 ptr;

    base = (u32)lbl_1_bss_6D838;
    if (base != 0) {
        addr = base + index * 0x620;
    } else {
        addr = 0;
    }

    ptr = *(u32 *)(addr + 0x49c);
    return *(f32 *)(ptr + 0x108);
}
/* fzgx:end fn_1_8C854 */

/* fzgx:begin fn_1_8C884 */
struct fn_1_8C884_lbl_1_bss_6D838 {
    u32 unk_0;
};


u32 fn_1_8C884(u32 arg0) {
    u32 v0;
    s32 v1;
    u32 v2;
    v0 = (*((struct fn_1_8C884_lbl_1_bss_6D838 *)&lbl_1_bss_6D838)).unk_0;
    v1 = arg0;
    v2 = v0;
    if (v0 != 0) {
    v1 = (v2 + (v1 * 1568));
    v2 = *(u32 *)((u8 *)v1 + 1180);
    } else {
    v2 = 0;
    }
    return ((*(u32 *)((u8 *)v2 + 280) << 2) + __cntlzw(*(u32 *)((u8 *)v2 + 348)));
}
/* fzgx:end fn_1_8C884 */

/* fzgx:begin fn_1_8C8C4 */
f32 fn_1_8C8C4(u32 index) {
    return lbl_1_bss_6D838[index].unk_1F4;
}
/* fzgx:end fn_1_8C8C4 */

/* fzgx:begin fn_1_8C8DC */
f32 fn_1_8C8DC(u32 index) {
    return lbl_1_bss_6D838[index].unk_1F8;
}
/* fzgx:end fn_1_8C8DC */

/* fzgx:begin fn_1_8C8F4 */
f32 fn_1_8C8F4(u32 index) {
    return lbl_1_bss_6D838[index].unk_1FC;
}
/* fzgx:end fn_1_8C8F4 */

/* fzgx:begin fn_1_8C90C */
f32 fn_1_8C90C(s32 index) {
    return lbl_1_bss_6D838[index].unk_200;
}
/* fzgx:end fn_1_8C90C */

/* fzgx:begin fn_1_8C924 */
f32 fn_1_8C924(s32 index) {
    return lbl_1_bss_6D838[index].unk_204;
}
/* fzgx:end fn_1_8C924 */

/* fzgx:begin fn_1_8C93C */
typedef struct {
    u32 unk_0;
} CarRef;

s32 fn_1_8C93C(s32 index) {
    u32 ref = lbl_1_bss_6D838[index].unk_484;
    if (ref != 0) {
        return ((CarRef *)ref)->unk_0;
    }
    return -1;
}
/* fzgx:end fn_1_8C93C */

/* fzgx:begin fn_1_8C968 */
s32 fn_1_8C968(s32 index) {
    u8 *data;

    data = (u8 *)lbl_1_bss_6D838[index].unk_484;
    if (data != 0) {
        return data[0x32];
    }
    return -1;
}
/* fzgx:end fn_1_8C968 */

/* fzgx:begin fn_1_8C994 */
// Return the shared car-state object.
Obj_1_bss_6D838_Target *fn_1_8C994(void) {
    return lbl_1_bss_6D838;
}
/* fzgx:end fn_1_8C994 */

/* fzgx:begin fn_1_8C9A4 */
// Returns the address of the object's field at offset 0x6.
u32 fn_1_8C9A4(void) {
    return (u32)&lbl_1_bss_6D838->unk_6;
}
/* fzgx:end fn_1_8C9A4 */

/* fzgx:begin fn_1_8C9B8 */
// Return the address of the object's field at offset 0x7c.
u32 fn_1_8C9B8(void) {
    return (u32)&lbl_1_bss_6D838->unk_7C;
}
/* fzgx:end fn_1_8C9B8 */

/* fzgx:begin fn_1_8C9CC */
// Return the address of the vehicle's field at offset 0x80.
u32 *fn_1_8C9CC(void) {
    return &lbl_1_bss_6D838->unk_80;
}
/* fzgx:end fn_1_8C9CC */

/* fzgx:begin fn_1_8C9E0 */
u32 *fn_1_8C9E0(void) {
    return &lbl_1_bss_6D838->unk_84;
}
/* fzgx:end fn_1_8C9E0 */

/* fzgx:begin fn_1_8C9F4 */
u8 *fn_1_8C9F4(void) {
    return &lbl_1_bss_6D84A;
}
/* fzgx:end fn_1_8C9F4 */

/* fzgx:begin fn_1_8CA0C */
u32 fn_1_8CA0C(void) {
    return lbl_1_bss_6D83C.unk_0 + 0x328;
}
/* fzgx:end fn_1_8CA0C */

/* fzgx:begin fn_1_8CA20 */
// Return the car object's data pointer adjusted to this function's subobject.
u32 fn_1_8CA20(void) {
    return lbl_1_bss_6D83C.unk_0 + 0x3a8;
}
/* fzgx:end fn_1_8CA20 */

/* fzgx:begin fn_1_8CA34 */
// Return the car object address adjusted to this function's field.
u32 fn_1_8CA34(void) {
    return lbl_1_bss_6D83C.unk_0 + 0x3ac;
}
/* fzgx:end fn_1_8CA34 */

/* fzgx:begin fn_1_8CA48 */
u32 fn_1_8CA48(void) {
    return lbl_1_bss_6D83C.unk_0 + 0x3b0;
}
/* fzgx:end fn_1_8CA48 */

/* fzgx:begin fn_1_8CA5C */
u32 fn_1_8CA5C(void) {
    return lbl_1_bss_6D83C.unk_0 + 0x3b4;
}
/* fzgx:end fn_1_8CA5C */

/* fzgx:begin fn_1_8CA70 */
extern u8 lbl_1_bss_6E160[1740];
extern f32 lbl_1_rodata_3508[];
struct rodata_3508 {
f32 f[4];
u8 pad_10[0x654];
f64 unk_668;
u8 pad_670[0x178];
f64 unk_7E8;
};
f32 fn_1_8CA70(u32 a, s32 b) {
    f32 value;
    u32 total;
    u32 half;
    u32 span;
    u32 index;
    int swapped = 0;
    struct { struct rodata_3508 *value; } constants;
    constants.value = (struct rodata_3508 *)lbl_1_rodata_3508;
    if (a == b) {
        return constants.value->f[4];
    }
    if (a > b) {
        u32 temp = a;
        a = b;
        b = temp;
        swapped = 1;
    }
    total = a * 30;
    half = (a * (a + 1)) >> 1;
    span = b - a;
    index = (total - half) + (span - 1);
    value = *((f32 *)(lbl_1_bss_6E160 + (index * 4)));
    if (!(swapped)) {
        return value;
    }
    if (constants.value->unk_668 == value) {
        return value;
    }
    return (f32)(value * constants.value->unk_7E8);
}
/* fzgx:end fn_1_8CA70 */

/* fzgx:begin fn_1_8CAF4 */
extern u8 lbl_1_bss_6DA80[1740];
extern f32 lbl_1_rodata_3508[];
struct rodata_3508 {
f32 f[4];
u8 pad_10[0x654];
f64 unk_668;
u8 pad_670[0x178];
f64 unk_7E8;
};
f32 fn_1_8CAF4(u32 a, s32 b) {
    f32 value;
    u32 total;
    u32 half;
    u32 span;
    u32 index;
    int swapped = 0;
    struct { struct rodata_3508 *value; } constants;
    constants.value = (struct rodata_3508 *)lbl_1_rodata_3508;
    if (a == b) {
        return constants.value->f[4];
    }
    if (a > b) {
        u32 temp = a;
        a = b;
        b = temp;
        swapped = 1;
    }
    total = a * 30;
    half = (a * (a + 1)) >> 1;
    span = b - a;
    index = (total - half) + (span - 1);
    value = *((f32 *)(lbl_1_bss_6DA80 + (index * 4)));
    if (!(swapped)) {
        return value;
    }
    if (constants.value->unk_668 == value) {
        return value;
    }
    return (f32)(value * constants.value->unk_7E8);
}
/* fzgx:end fn_1_8CAF4 */

/* fzgx:begin fn_1_8CB78 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"




typedef struct {
    u8 pad0[0x1c];
    void *field_1c;
} CarObject;

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
    u8 pad0[0x24];
    void *field_24;
} EventData;

typedef struct {
    u8 pad0[0x8];
    EventData *field_8;
    void *field_c;
} EventObject;

struct fn_1_7F954_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_7FA04_lbl_801A6410 {
    u32 unk_0;
};

typedef struct {
    u8 pad0[0x40];
    void *value;
} ResourceHolder;

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} RawVec3;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    u8 _pad_000[0x7c];
    Vec3 field_07c;
    u8 _pad_088[0xc4];
    Vec3 field_14c;
} Fn184644Object;

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Triple;

typedef struct Fn195158Object Fn195158Object;

struct Fn195158Object {
    u8 unk_00[0x0C];
    f32 unk_0C;
    u8 unk_10[0x1C];
    f32 unk_2C;
    u8 unk_30[0x58];
    u8 unk_88[0x04];
};

struct TargetObj {
    char pad[0x60];
    char field_0x60[0xc];
    f32 field_0x6c;
    char pad2[0xc];
    f32 field_0x7c;
};

struct ModelItem {
    u32 flags;
    char pad[0x1c];
};

struct Model {
    char pad[0x18];
    u16 count;
    char pad2[0x26];
    struct ModelItem items[1];
};

typedef struct {
    u32 entries[41];
} FnTable;

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

typedef struct {
    u8 pad0[0x12];
    u16 field_12;
    u8 pad14[0x12];
    u8 field_26;
    void *field_28;
    u8 pad2c[8];
    void *field_34;
    u8 pad38[0x14];
    u8 field_4c;
} Node;

typedef struct Fn935E4Car {
    u8 pad0[0x1c];
    Fn935E4Node *field_1c;
} Fn935E4Car;

typedef struct {
    u8 pad0[0x24];
    void *field_24;
    f32 field_28;
    f32 field_2c;
} OutData;

typedef struct {
    u8 pad0[0x1c];
    Node *field_1c;
    u8 pad20[0x128];
    u16 field_148;
    u8 pad14a[6];
    OutData *field_150;
    void *field_154;
} Owner;

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
extern void fn_1_A8DD4(u8 *, ...);

typedef struct {
    u32 count;
    u8 *data;
} EntryTable;

typedef struct {
    u8 pad0[4];
    u32 pointer;
    u16 value8;
    u16 valueA;
} fn_1_8CB78_Entry;

void fn_1_8CB78(EntryTable *table) {
    u32 offset;
    s8 index;

    offset = 0;
    index = 0;
    while (index < table->count) {
        fn_1_8CB78_Entry *entry = (fn_1_8CB78_Entry *)(table->data + offset);
        fn_1_A8DD4((((u8 *)&lbl_1_data_2090C)), index, entry->value8,
                   entry->valueA, entry->pointer);
        offset += 0x10;
        index++;
    }
}
/* fzgx:end fn_1_8CB78 */

/* fzgx:begin fn_1_8CED0 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.0f;
    s = 2.0f;
}
static const u32 fzgx_pool_table2[1] = {0x40000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.5f;
    s = 0.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.1920928955078125e-07;
    s = 1.4499999284744263f;
    s = -1.5881868392106856e-23f;
    s = 1.0f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.15000000074505807;
    s = 0.05000000074505806f;
    s = 30.0f;
    s = 0.00390625f;
    s = 182.04444885253906f;
    s = 180.0f;
    s = 44.0f;
    s = 89.0f;
    s = 360.0f;
    s = 60.0f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.12999999932944775;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table12[306] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00330000, 0x00010001, 0x00020002, 0x00030003, 0x0004002F, 0x00050004, 0x00060005, 0x00070006, 0x00080007, 0x00090008, 0x000A002A, 0x000B0009, 0x000C002B, 0x000D000A, 0x000E002C, 0x000F000B, 0x0010002D, 0x0011000C, 0x0012002E, 0x0013000D, 0x0014000E, 0x003D000F, 0x003E0010, 0x003F0011, 0x00400012, 0x00410013, 0x00420014, 0x00430015, 0x00440016, 0x00450017, 0x00460018, 0x00470019, 0x0048001A, 0x0049001B, 0x004A001C, 0x004B001D, 0x004C0034, 0x004D0035, 0x004E0036, 0x004F0037, 0x001F001E, 0x0020001F, 0x00210020, 0x00220021, 0x00230022, 0x00240023, 0x00250024, 0x00260025, 0x00270026, 0x00280027, 0x00290028, 0x002A0029, 0x00500038, 0x00510030, 0x00520031, 0x00530032, 0x00540033, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
}
static const u32 fzgx_pool_table14[3] = {0x0032001E, 0x00140004, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    d = 0.20000000298023224;
    s = 0.10000000149011612f;
    s = 0.11999999731779099f;
    s = -0.10000000149011612f;
    s = -1.0f;
    s = 0.8999999761581421f;
    s = 0.49000000953674316f;
    d = 0.800000011920929;
    s = 0.4000000059604645f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
}
static const u32 fzgx_pool_table18[2] = {0x3F000000, 0x40000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 0.75f;
}
static const u32 fzgx_pool_table20[1] = {0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1000.0f;
}
static const u32 fzgx_pool_table22[29] = {0xFFFFFFFF, 0xFFFFFFFF, 0x3F800000, 0x3F800000, 0x3F800000, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
}
static const u32 fzgx_pool_table24[16] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 1.0;
    s = 15.0f;
    s = 0.009999999776482582f;
    s = 255.0f;
    s = 128.0f;
}
static const u32 fzgx_pool_table26[28] = {0x41980000, 0x41700000, 0x41980000, 0x41980000, 0x41980000, 0x414E6666, 0x41500000, 0x41500000, 0x41500000, 0x41500000, 0x06010406, 0x02000000, 0x3F000000, 0x3F000000, 0x3F000000, 0x3F000000, 0x3E4CCCCD, 0x3F800000, 0x3F800000, 0xBF800000, 0xBF800000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 17.0f;
    s = 2.299999952316284f;
    s = 14.699999809265137f;
    s = 0.30000001192092896f;
    s = 10.0f;
    s = 7.699999809265137f;
    s = 160.0f;
    s = 25.0f;
    d = 0.2;
    s = 0.25f;
    s = 8192.0f;
    s = -30.0f;
    s = 200.0f;
    s = 40000.0f;
}
static const u32 fzgx_pool_table28[29] = {0x467FA400, 0x467FA400, 0x46822A00, 0x46822A00, 0x46848200, 0x46848200, 0x4686DA00, 0x4686DA00, 0x45C9D800, 0x45CB0000, 0x45E2D800, 0x45E40000, 0x45FBD800, 0x45FD0000, 0x46517C00, 0x4651C400, 0x46537800, 0x4653C000, 0x46557400, 0x4655BC00, 0x465CE400, 0x465D2000, 0x46847400, 0x46849400, 0x02010003, 0x02030103, 0x00020302, 0x03010001, 0x01000200};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    s = 20.0f;
    s = 40.0f;
    s = -1000.0f;
    s = -35.0f;
    s = 35.0f;
    s = 1500.0f;
}
static const u32 fzgx_pool_table30[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 50.0;
    s = 50.0f;
    s = -2.000060796737671f;
}
static const u32 fzgx_pool_table32[2] = {0x0000C0FF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 4.125f;
}
static const u32 fzgx_pool_table34[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = -1.0;
    d = 0.05;
    d = 1.5707963705062866;
    s = -0.5f;
}
static const u32 fzgx_pool_table36[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const u32 *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime37(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 32768.0;
    s = 65536.0f;
    s = 2.1415927410125732f;
    s = 32768.0f;
    s = 320.0f;
    s = 55.0f;
    s = 0.9333333373069763f;
    s = 90000.0f;
}
static const u32 fzgx_pool_table38[1] = {0x60000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const u32 *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"


typedef struct {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    u16 unk_28;
    u16 unk_2A;
    u16 unk_2C;
    u16 unk_2E;
    u16 unk_30;
    u16 unk_32;
    u32 unk_34;
    u8 unk_38;
    u8 unk_39;
    u8 unk_3A;
    u8 unk_3B;
    u32 unk_3C;
    u8 unk_40;
    u8 unk_41[3];
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    u16 unk_54;
    u16 unk_56;
    u32 unk_58;
    u8 unk_5C[4];
} Fn1_8CED0State;

void fn_1_8CED0(Fn1_8CED0State *state, u16 arg1, u16 arg2) {
    u16 h = arg2;
    u32 w = arg1;

    state->unk_00 = 0.0f;
    state->unk_04 = 0.0f;
    state->unk_08 = (f32)w;
    state->unk_0C = (f32)h;
    state->unk_10 = 0.0f;
    state->unk_14 = 1.0f;
    state->unk_18 = 0.0f;
    state->unk_1C = 0.0f;
    state->unk_20 = (f32)w;
    state->unk_24 = (f32)h;
    state->unk_28 = 0;
    state->unk_2A = 0;
    state->unk_2C = arg1;
    state->unk_2E = arg2;
    if (lbl_1_bss_8CA28 != 0) {
        state->unk_34 = 5;
    } else {
        state->unk_34 = 6;
    }
    state->unk_38 = 1;
    if (lbl_1_bss_8CA28 != 0) {
        state->unk_39 = 1;
    } else {
        state->unk_39 = 0;
    }
    w = state->unk_39;
    if ((w) != 0) {
        state->unk_30 = state->unk_2C >> 1;
        state->unk_32 = state->unk_2E >> 1;
    } else {
        state->unk_30 = state->unk_2C;
        state->unk_32 = state->unk_2E;
    }
    state->unk_3A = 1;
    state->unk_3C = 7;
    state->unk_40 = 0;
    state->unk_44 = 55.0f;
    state->unk_48 = (0.9333333373069763f * arg1) / arg2;
    state->unk_4C = 0.10000000149011612f;
    state->unk_50 = 90000.0f;    state->unk_54 = 1;
    fn_80008BEC(state->unk_5C, 0, 4);
    state->unk_58 = 1;
}
/* fzgx:end fn_1_8CED0 */

/* fzgx:begin fn_1_8D0A4 */
typedef struct {
    u8 pad_00[0x2c];
    u16 width;
    u16 height;
    u8 pad_30[4];
    u32 arg34;
    u8 pad_38[0x28];
    u32 result;
} Fn1_8D0A4State;

static inline u32 abs_value(u32 value) {
    u32 sign = value >> 31;
    u32 low = value & 1;
    return (low ^ sign) - sign;
}

void fn_1_8D0A4(Fn1_8D0A4State *state) {
    if (state->width == 0 && state->height == 0) {
        state->result = 0;
    } else {
        if (abs_value(state->width) != 0 || abs_value(state->height) != 0) {
            state->width = 0x280;
            state->height = 0x1e0;
        }
        state->result = fn_1_4630(
            (*((void * *)&lbl_801A6410)),
            GXGetTexBufferSize(state->width, state->height, state->arg34, 0, 0),
            (((u8 *)&lbl_1_data_1FFF0)),
            0x1bfc);
    }
}
/* fzgx:end fn_1_8D0A4 */

/* fzgx:begin fn_1_8D168 */
typedef struct Fn1_8D168State {
    u8 pad[0x60];
    u32 field_60;
} Fn1_8D168State;

void fn_1_8D168(Fn1_8D168State *state) {
    fn_8006FDEC();
    fn_8006FEFC();
    if (state->field_60 != 0) {
        fn_1_46B4(lbl_801A6410, state->field_60, (const char *)(u8 *)(lbl_1_data_1FFF0), 0x1c04);
        state->field_60 = 0;
    }
}
/* fzgx:end fn_1_8D168 */

/* fzgx:begin fn_1_8D1C8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car.h"

extern void fn_1_8D210(u32 arg0, u32 arg1, u32 arg2, u32 arg3);

void fn_1_8D1C8(u32 arg0, u32 arg1, u32 arg2) {
    fn_1_8D210(arg0, arg1, arg2, 1);
}
/* fzgx:end fn_1_8D1C8 */

/* fzgx:begin fn_1_8D1EC noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car.h"

extern void fn_1_8D210(u32 arg0, u32 arg1, u32 arg2, u32 arg3);

void fn_1_8D1EC(u32 arg0, u32 arg1, u32 arg2) {
    fn_1_8D210(arg0, arg1, arg2, 0);
}
/* fzgx:end fn_1_8D1EC */

/* fzgx:begin fn_1_8D210 */
s32 fn_1_8D210(fn_1_8D210_car *car, fn_1_8D210_callback callback, u32 arg, s32 enable) {
    u8 local_34[24];
    u8 local_14[4];
    u8 local_10[4];
    u8 local_c[4];
    u8 local_8[4];
    u8 local_18[0x1c];
    u8 local_8c[52];
    u8 local_4c[64];
    s32 value_a;
    s32 value_b;
    s32 value_c;
    s32 result;

    lbl_8006DD14(lbl_801A6D00 + 0x30, local_8c);
    fn_80038F10( (f32*)(void *)(local_34));
    fn_80038FD8( (u32 *)(void *)(local_14), (u32 *)(void *)(local_10), (u32 *)(void *)(local_c), (u32 *)(void *)(local_8));
    fn_80038BFC( (f32*)(void *)(local_18));
    fn_1_550A8();
    fn_80015E18( (f32 *)(void *)(local_4c), car->field_44, car->field_48, car->field_4c, car->field_50);
    fn_800737E4(local_4c, 0);
    fn_80038EEC(car->position[0], car->position[1], car->position[2], car->position[3], car->position[4], car->position[5]);
    fn_80074188(__cvt_fp2unsigned(car->scale_z), __cvt_fp2unsigned(car->scale_y),
                __cvt_fp2unsigned(car->scale_x), __cvt_fp2unsigned(car->field_24));
    lbl_8006D758();
    fn_80074918(car->field_3a, car->field_3c, car->field_40);
    if (car->field_58 != 0)
        fn_80008204(&car->field_5c);
    result = callback(arg);
    if (car->field_54 != 0)
        fn_1_545B8();
    if (enable != 0) {
        fn_80074300(car->field_28, car->field_2a, car->field_2c, car->field_2e);
        fn_80074438(car->field_30, car->field_32, car->field_34, car->field_39);
        fn_8003526C(car->field_60, car->field_38);
        GXInvalidateTexAll();
    }
    fn_80074918(1, 3, 0);
    fn_1_550E0();
    lbl_8006DD14(local_8c, lbl_801A6D00 + 0x30);
    fn_80038EEC(*(f32 *)&local_34[0], *(f32 *)&local_34[4], *(f32 *)&local_34[8], *(f32 *)&local_34[12],
                *(f32 *)&local_34[16], *(f32 *)&local_34[20]);
    fn_80074188(*(s32 *)&local_14[0], *(s32 *)&local_10[0], *(s32 *)&local_c[0], *(s32 *)&local_8[0]);
    fn_80072270(local_18);
    return result;
}
/* fzgx:end fn_1_8D210 */

/* fzgx:begin fn_1_8D3F8 */
typedef struct Fn1_8D3F8Car {
    f32 field_00;
    f32 field_04;
    f32 field_08;
    f32 field_0c;
    f32 field_10;
    f32 field_14;
    f32 field_18;
    f32 field_1c;
    f32 field_20;
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
    u8 field_40[4];
    f32 field_44;
    f32 field_48;
    f32 field_4c;
    f32 field_50;
    s16 field_54;
    u8 pad_56[2];
    s32 field_58;
    u8 field_5c[4];
    u32 field_60;
} Fn1_8D3F8Car;


u32 fn_1_8D3F8(Fn1_8D3F8Car *car, u32 arg1, u32 (*callback)(u32), u32 arg3) {
    u32 local_14;
    u32 local_10;
    u32 local_0c;
    u32 local_08;
    u8 local_30[0x1c];
    f32 local_18[6];
    u8 local_7c[0x40];
    u8 local_4c[0x30];
    u32 result;

    lbl_8006DD14(lbl_801A6D00 + 0x30, local_4c);
    fn_80038F10(local_18);
    fn_80038FD8( (u32 *)(void *)(&local_08), (u32 *)(void *)(&local_0c), (u32 *)(void *)(&local_10), (u32 *)(void *)(&local_14));
    fn_80038BFC((f32 *)local_30);
    fn_1_550A8();
    fn_80015E18( (f32 *)(void *)(local_7c), car->field_44, car->field_48, car->field_4c, car->field_50);
    fn_800737E4(local_7c, 0);
    fn_80038EEC(car->field_00, car->field_04, car->field_08, car->field_0c, car->field_10, car->field_14);
    fn_80074188((u32)__cvt_fp2unsigned(car->field_18), (u32)__cvt_fp2unsigned(car->field_1c),
                __cvt_fp2unsigned(car->field_20), (u32)__cvt_fp2unsigned(car->field_24));
    lbl_8006D758();
    fn_80074918(car->field_3a, car->field_3c, car->field_40[0]);
    if (car->field_58 != 0) {
        fn_80008204(&car->field_5c);
    }
    result = callback(arg3);
    if (car->field_54 != 0) {
        fn_1_545B8();
    }
    fn_80074300(car->field_28, car->field_2a, car->field_2c, car->field_2e);
    fn_80074438(car->field_30, car->field_32, car->field_34, car->field_39);
    fn_8003526C(car->field_60, car->field_38);
    GXInvalidateTexAll();
    fn_80074918(1, 3, 0);
    fn_1_550E0();
    lbl_8006DD14(local_4c, lbl_801A6D00 + 0x30);
    fn_80038EEC(local_18[0], local_18[1], local_18[2], local_18[3], local_18[4], local_18[5]);
    fn_80074188(local_08, local_0c, local_10, local_14);
    fn_80072270(local_30);
    fn_1_4FC50(arg1, car->field_34, car->field_30, car->field_32, car->field_60);
    return result;
}
/* fzgx:end fn_1_8D3F8 */

/* fzgx:begin fn_1_8D5F0 */
typedef struct {
    u32 data[41];
} Table;

u32 fn_1_8D5F0(s16 index) {
    Table table;

    table = *(Table *)lbl_1_rodata_3D34;
    return table.data[index];
}
/* fzgx:end fn_1_8D5F0 */

/* fzgx:begin fn_1_8D640 */
typedef struct {
    s16 values[41];
} Fn1_8D640Table;

s16 fn_1_8D640(s16 index) {
    Fn1_8D640Table table = *(Fn1_8D640Table *)lbl_1_rodata_3DD8;
    return table.values[index];
}
/* fzgx:end fn_1_8D640 */

/* fzgx:begin fn_1_8D690 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car.h"

extern int fn_1_F7BE4(s16 arg0);

typedef struct {
    u32 entries[41];
} FnTable;

extern const FnTable lbl_1_rodata_3D34;

// Return whether the indexed flag remains enabled after the preliminary check.
u32 fn_1_8D690(s16 arg0) {
    FnTable table;
    u32 valid;

    valid = 1;
    if (!fn_1_F7BE4(arg0)) {
        table = lbl_1_rodata_3D34;
        if ((table.entries[(s32)arg0] & ~0x7fffffff) == 0) {
            valid = 0;
        }
    }
    return valid != 0;
}
/* fzgx:end fn_1_8D690 */

/* fzgx:begin fn_1_8D72C */
typedef struct {
    u32 w[41];
} Table164;

u32 fn_1_8D72C(s16 index) {
    Table164 table;
    s32 result;

    result = 1;
    if (fn_1_F7BE4() == 0) {
        table = *(const Table164 *)lbl_1_rodata_3D34;
        if ((table.w[(s32)index] & 0x40000000) == 0) {
            result = 0;
        }
    }
    return result != 0;
}
/* fzgx:end fn_1_8D72C */

/* fzgx:begin fn_1_8D7C8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car.h"

extern int fn_1_F7BE4(s16 arg0);

typedef struct {
    u32 values[41];
} Fn1_8D7C8Data;

extern int fn_1_F7BE4(s16 index);
extern u8 lbl_1_rodata_3D34[164];

s16 fn_1_8D7C8(void) {
    int enabled;
    u32 *value;
    s16 index;
    s16 count;
    Fn1_8D7C8Data data;

    count = 0;
    index = 0;
    value = data.values;
    while ((s16)index < 41) {
        enabled = 1;
        if (fn_1_F7BE4(index) == 0) {
            data = *(Fn1_8D7C8Data *)lbl_1_rodata_3D34;
            if ((*value & 0x40000000) == 0) {
                enabled = 0;
            }
        }
        if (enabled != 0) {
            count = (s16)(count + 1);
        }
        value++;
        index++;
    }
    return count;
}
/* fzgx:end fn_1_8D7C8 */

/* fzgx:begin fn_1_8D894 */
void fn_1_8D894(Obj_1_bss_6D838_Target *car) {
    u32 value;
    u32 obj;

    // Initialize the car resource and register it when allocation succeeds.
    value = car->unk_0;
    car->unk_0 = value | 0x04000000;
    obj = (u32)fn_1_45D0(lbl_801A6410, 0x88, lbl_1_data_1FFF0, 0x1CB0);
    car->unk_484 = obj;
    obj = car->unk_484;
    if (obj == 0) {
        value = car->unk_0;
        car->unk_0 = value & 0xFBFFFFFF;
    } else {
        *(u32 *)((u8 *)obj + 0x40) = lbl_801A6410;
        *((u8 *)car + 0x50E) = 1;
        fn_1_C487C(car);
        fn_1_43E8(1);
        obj = (u32)fn_1_3F8C( (u32)(void *)(lbl_1_data_20700), (u32)(void *)(fn_1_C4ABC), (u32)(Obj_1_bss_6D838_Target *)(car), 3);
        lbl_1_bss_6D86C[(s8)car->unk_474] = obj;
        fn_1_43F4();
        ((u8 *)&lbl_1_bss_6D868)[(s8)car->unk_474] = car->unk_4;
        *((s8 *)car + 0x474) = -1;
    }
}
/* fzgx:end fn_1_8D894 */

/* fzgx:begin fn_1_8D988 noprologue */
#include "types.h"

typedef struct CarObject { u8 pad_0[0x40]; void *unk_40; } CarObject;
typedef struct Car {
    u32 unk_0; s16 unk_4; u8 pad_6[0x46e]; s8 unk_474; u8 pad_475[0xf];
    CarObject *unk_484; u8 pad_488[0x86]; u8 unk_50e; u8 pad_50f[0x111];
} Car;
typedef struct CarManager {
    u8 pad_0[0x18]; Car *cars; u8 pad_1c[0xe]; s8 count; u8 pad_2b[0x1d];
    s8 values[4]; CarObject *objects[16];
} CarManager;
extern CarManager lbl_1_bss_6D820;
extern u8 lbl_1_data_1FFF0[12];
extern void *lbl_801A6410;
extern char lbl_1_data_20700[17];
extern CarObject *fn_1_45D0(void *, u32, void *, u32);
extern void fn_1_C487C();
extern void fn_1_43E8(u32);
extern void fn_1_C4ABC(void);
extern CarObject *fn_1_3F8C(void *, void (*)(void), Car *, u32);
extern void fn_1_43F4(void);

#pragma opt_propagation off
static inline CarObject * fn_1_8D988_read_pointer(Car * owner) { return owner->unk_484; }
static inline s8 * fn_1_8D988_values(CarManager * m) { return m->values; }
void fn_1_8D988(void) {
    struct { CarManager *m; } mgr;
    u32 i;
    Car *car;
    u32 lab_t1;
    CarObject * tmp_call1;
    s16 val;

    mgr.m = &lbl_1_bss_6D820;
    car = mgr.m->cars;
    i = 0;
    for (; i < mgr.m->count; i++, car++) {
        if (car->unk_0 & 0x04000000) continue;
        car->unk_0 |= 0x04000000;
        tmp_call1 = fn_1_45D0(lbl_801A6410, 0x88, lbl_1_data_1FFF0, 0x1cb0);
        car->unk_484 = tmp_call1;
        if (fn_1_8D988_read_pointer(car) == 0) {
            car->unk_0 &= ~0x04000000;
            continue;
        }
        fn_1_8D988_read_pointer(car)->unk_40 = lbl_801A6410;
        car->unk_50e = 1;
        fn_1_C487C(car);
        fn_1_43E8(1);
        {
            CarObject *obj = fn_1_3F8C(lbl_1_data_20700, fn_1_C4ABC, car, 3);
            CarObject **objs = mgr.m->objects;
            objs[car->unk_474] = obj;
        }
        fn_1_43F4();
        {
            s8 *vals = fn_1_8D988_values(mgr.m);
            lab_t1 = car->unk_474;
            val = car->unk_4;
            vals[lab_t1] = val;
        }
        car->unk_474 = -1;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_8D988 */

/* fzgx:begin fn_1_8DAB4 */
typedef struct {
    u8 pad0[0x18];
    void *objects;
    u8 pad1[0x2c];
    u8 pending[4];
    s32 handles[4];
} GlobalState;


typedef struct {
    u8 pad0[0x474];
    u8 active;
    u8 pad1[0x0f];
    ResourceHolder *resource_holder;
} fn_1_8DAB4_Object;


void fn_1_8DAB4(void) {
    GlobalState *state;
    u8 *pending;
    s32 *handles;
    u32 i;
    fn_1_8DAB4_Object *object;
    u32 flags;
    void *value;

    state = &(*((GlobalState *)&lbl_1_bss_6D820));
    pending = state->pending;
    handles = state->handles;
    for (i = 0; i < 4; i++, pending++, handles++) {
        if (*pending != 0xff) {
            object = (fn_1_8DAB4_Object *)((u8 *)state->objects + *pending * 0x620);
            flags = *(u32 *)object;
            flags &= 0xfbffffff;
            *(u32 *)object = flags;
            object->active = (u8)i;
            if (object->resource_holder != 0) {
                value = (void *)fn_80008E84( (u32)(void *)(object->resource_holder->value));
                fn_1_46B4(lbl_801A6410, (u32)(ResourceHolder *)(object->resource_holder), (const char *)(u8 *)((((u8 *)&lbl_1_data_1FFF0))), 0x1ced);
                object->resource_holder = 0;
                fn_80008E84( (u32)(void *)(value));
            }
            if (*handles != -1) {
                fn_1_426C(*handles);
            }
            *pending = 0xff;
        }
    }
}
/* fzgx:end fn_1_8DAB4 */

/* fzgx:begin fn_1_8DB94 */
u8 fn_1_8DB94(void) {
    return lbl_1_bss_6D820;
}
/* fzgx:end fn_1_8DB94 */

/* fzgx:begin fn_1_8DBA4 */
void fn_1_8DBA4(u8 value) {
    lbl_1_bss_6D820 = value;
}
/* fzgx:end fn_1_8DBA4 */

/* fzgx:begin fn_1_8E188 */
void fn_1_8E188(void) {
    if (lbl_1_bss_6E958.unk_4 == 0) {
        lbl_1_bss_6E958.unk_4 = fn_1_12AC00(lbl_1_data_20994);
        lbl_1_bss_6E958.unk_0 = fn_1_12ADA0(lbl_1_data_209A8, lbl_1_bss_6E958.unk_4);
    }
}
/* fzgx:end fn_1_8E188 */

/* fzgx:begin fn_1_8E1E8 */
// Releases both pending resource handles when the secondary handle is active.
void fn_1_8E1E8(void) {
    if (lbl_1_bss_6E958.unk_4 != 0) {
        fn_80071718( (u32)((void *)lbl_1_bss_6E958.unk_4));
        fn_800711A8(lbl_1_bss_6E958.unk_0);
        lbl_1_bss_6E958.unk_4 = 0;
        lbl_1_bss_6E958.unk_0 = 0;
    }
}
/* fzgx:end fn_1_8E1E8 */

/* fzgx:begin fn_1_8E244 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.0f;
    s = 2.0f;
}
static const u32 fzgx_pool_table2[1] = {0x40000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.5f;
    s = 0.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.1920928955078125e-07;
    s = 1.4499999284744263f;
    s = -1.5881868392106856e-23f;
    s = 1.0f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.15000000074505807;
    s = 0.05000000074505806f;
    s = 30.0f;
    s = 0.00390625f;
    s = 182.04444885253906f;
    s = 180.0f;
    s = 44.0f;
    s = 89.0f;
    s = 360.0f;
    s = 60.0f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.12999999932944775;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table12[306] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00330000, 0x00010001, 0x00020002, 0x00030003, 0x0004002F, 0x00050004, 0x00060005, 0x00070006, 0x00080007, 0x00090008, 0x000A002A, 0x000B0009, 0x000C002B, 0x000D000A, 0x000E002C, 0x000F000B, 0x0010002D, 0x0011000C, 0x0012002E, 0x0013000D, 0x0014000E, 0x003D000F, 0x003E0010, 0x003F0011, 0x00400012, 0x00410013, 0x00420014, 0x00430015, 0x00440016, 0x00450017, 0x00460018, 0x00470019, 0x0048001A, 0x0049001B, 0x004A001C, 0x004B001D, 0x004C0034, 0x004D0035, 0x004E0036, 0x004F0037, 0x001F001E, 0x0020001F, 0x00210020, 0x00220021, 0x00230022, 0x00240023, 0x00250024, 0x00260025, 0x00270026, 0x00280027, 0x00290028, 0x002A0029, 0x00500038, 0x00510030, 0x00520031, 0x00530032, 0x00540033, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
}
static const u32 fzgx_pool_table14[3] = {0x0032001E, 0x00140004, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    d = 0.20000000298023224;
    s = 0.10000000149011612f;
    s = 0.11999999731779099f;
    s = -0.10000000149011612f;
    s = -1.0f;
    s = 0.8999999761581421f;
    s = 0.49000000953674316f;
    d = 0.800000011920929;
    s = 0.4000000059604645f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
}
static const u32 fzgx_pool_table18[2] = {0x3F000000, 0x40000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 0.75f;
}
static const u32 fzgx_pool_table20[1] = {0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1000.0f;
}
static const u32 fzgx_pool_table22[29] = {0xFFFFFFFF, 0xFFFFFFFF, 0x3F800000, 0x3F800000, 0x3F800000, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
}
static const u32 fzgx_pool_table24[16] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 1.0;
    s = 15.0f;
    s = 0.009999999776482582f;
    s = 255.0f;
    s = 128.0f;
}
static const u32 fzgx_pool_table26[28] = {0x41980000, 0x41700000, 0x41980000, 0x41980000, 0x41980000, 0x414E6666, 0x41500000, 0x41500000, 0x41500000, 0x41500000, 0x06010406, 0x02000000, 0x3F000000, 0x3F000000, 0x3F000000, 0x3F000000, 0x3E4CCCCD, 0x3F800000, 0x3F800000, 0xBF800000, 0xBF800000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 17.0f;
    s = 2.299999952316284f;
    s = 14.699999809265137f;
    s = 0.30000001192092896f;
    s = 10.0f;
    s = 7.699999809265137f;
    s = 160.0f;
    s = 25.0f;
    d = 0.2;
    s = 0.25f;
    s = 8192.0f;
    s = -30.0f;
    s = 200.0f;
    s = 40000.0f;
}
static const u32 fzgx_pool_table28[29] = {0x467FA400, 0x467FA400, 0x46822A00, 0x46822A00, 0x46848200, 0x46848200, 0x4686DA00, 0x4686DA00, 0x45C9D800, 0x45CB0000, 0x45E2D800, 0x45E40000, 0x45FBD800, 0x45FD0000, 0x46517C00, 0x4651C400, 0x46537800, 0x4653C000, 0x46557400, 0x4655BC00, 0x465CE400, 0x465D2000, 0x46847400, 0x46849400, 0x02010003, 0x02030103, 0x00020302, 0x03010001, 0x01000200};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    s = 20.0f;
    s = 40.0f;
    s = -1000.0f;
    s = -35.0f;
    s = 35.0f;
    s = 1500.0f;
}
static const u32 fzgx_pool_table30[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 50.0;
    s = 50.0f;
    s = -2.000060796737671f;
}
static const u32 fzgx_pool_table32[2] = {0x0000C0FF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 4.125f;
}
static const u32 fzgx_pool_table34[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = -1.0;
    d = 0.05;
    d = 1.5707963705062866;
    s = -0.5f;
}
static const u32 fzgx_pool_table36[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const u32 *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime37(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 32768.0;
    s = 65536.0f;
    s = 2.1415927410125732f;
    s = 32768.0f;
    s = 320.0f;
    s = 55.0f;
    s = 0.9333333373069763f;
    s = 90000.0f;
}
static const u32 fzgx_pool_table38[2] = {0x60000000, 0x60000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const u32 *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime39(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.0f;
}
static const u32 fzgx_pool_table40[59] = {0x60000000, 0xC0000000, 0xC0000000, 0xC0000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x60000000, 0x00000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x10000000, 0x000A0008, 0x00630007, 0x00630063, 0x00630008, 0x0007000C, 0x0008000A, 0x00080008, 0x0008000A, 0x0007000A, 0x0007000C, 0x000C000C, 0x000A0007, 0x000A0008, 0x000A000A, 0x0007000A, 0x00140014, 0x00140014, 0x00140014, 0x00140014, 0x00140014, 0x00140000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep40(void) { const u32 *volatile cp; cp = fzgx_pool_table40; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime41(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -10.0f;
    s = 8.0f;
}
#pragma section code_type ".text"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Fn18E244Vec;

typedef struct {
    void *ptr;
    s32 pad_4;
} Elem;

typedef struct {
    s32 count;
    s32 pad_4;
    Elem *items;
} CarList;


extern u32 lbl_801A66A0;
extern u32 lbl_8006DBE4(void);
extern void mathutil_mtxA_rotate_y(int);
extern void fn_1_55210(void *);
extern void fn_80072558(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DC20(void);
extern void lbl_8006DFE8(void *);
extern void lbl_8006E0A4(void *);

void fn_1_8E244(void *arg0) {
    Fn18E244Vec v = {0.0f, 1.5f, 1.0f};
    f32 s;

    if (lbl_1_bss_6E958.unk_4 != 0) {
        lbl_8006DFE8(arg0);
        s = 0.5215686559677124f;
        psvec_scale(&v.x, s, &v.x);
        lbl_8006E0A4(&v);
        lbl_8006DAEC();
        {
            s16 i;
            for (i = 0; i < ((CarList *)lbl_1_bss_6E958.unk_0)->count; i++) {
                lbl_8006DBE4();
                if (i) {
                    u32 *q = (u32 *)&lbl_801A66A0;
                    mathutil_mtxA_rotate_y((s32)(182.04444885253906f * (f32)(*q % 360)));
                }
                fn_80072558();
                fn_1_55210(((CarList *)lbl_1_bss_6E958.unk_0)->items[i].ptr);
            }
        }
        lbl_8006DC20();
    }
}
/* fzgx:end fn_1_8E244 */

/* fzgx:begin fn_1_8E3A4 */
typedef struct {
    u8 pad[0x3bc];
    u32 value;
} GlobalObject;



void fn_1_8E3A4(fn_1_8E3A4_Object *obj) {
    u32 value;
    s8 color[4];

    if ((*((GlobalObject * *)&lbl_1_bss_6D824)) != 0) {
        value = (*((GlobalObject * *)&lbl_1_bss_6D824))->value;
        if (value != 0xffffffff) {
            if (obj->state->code == (u8)value) {
                u32 b0 = value >> 24;
                u32 b1 = (value >> 16) & 0xff;
                u32 b2 = (value >> 8) & 0xff;

                color[0] = b0;
                color[1] = b1;
                color[2] = b2;
                ((u8 *)color)[3] = 0xff;
                fn_80008BA8((u8 *)obj->state + 8, color, 4);
                fn_80008BA8((u8 *)obj->state + 4, color, 4);
            }
        }
    }
}
/* fzgx:end fn_1_8E3A4 */

/* fzgx:begin fn_1_8E448 */
typedef struct {
    u8 pad[0x3bc];
    u32 value;
} fn_1_8E448_Object;

void fn_1_8E448(fn_1_8E448_Object *obj, u32 value) {
    obj->value = value;
}
/* fzgx:end fn_1_8E448 */

/* fzgx:begin fn_1_8E450 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car.h"

extern void fn_1_8E3A4(void);
extern void fn_80074A7C(void (*func)(void));

void fn_1_8E450(u32 value) {
    lbl_1_bss_6D824 = value;
    fn_80074A7C(fn_1_8E3A4);
}
/* fzgx:end fn_1_8E450 */

/* fzgx:begin fn_1_8E480 */
void fn_1_8E480(void) {
    fn_80074A7C(0);
}
/* fzgx:end fn_1_8E480 */

/* fzgx:begin fn_1_8E728 */
struct Unk_1_8E728 {
    u8 pad_0[0x98];
    u8 field_98;
    u8 pad_1[0x3];
    s32 field_9c;
    u8 pad_2[0x44];
    u32 field_e4[5];
    u32 field_f8[5][4];
};

void fn_1_8E728(struct Unk_1_8E728 *p, u8 arg1) {
    s32 i;
    u8 idx;

    if (p != 0) {
        idx = (u8)((u8)arg1 % 4);
        if ((__rlwnm(p->field_9c, ((idx + 1) & 31), 31, 31) != 0)) {
            for (i = 0; i < 5; i++) {
                u32 v0 = p->field_e4[i];
                u32 v1 = p->field_f8[i][idx];
                if (v0 != 0 && v1 != 0) {
                    fn_800713E0((struct Sig_fn_800713E0_fn_800713E0_Arg0 *)v0, v1);
                }
            }
            p->field_98 = idx;
        }
    }
}
/* fzgx:end fn_1_8E728 */

/* fzgx:begin fn_1_8F45C */
void fn_1_8F45C(Fn1_8F45C_Object *obj) {
    obj->field_4 = -1;
    obj->field_8 = -1;
    obj->field_c = -1;
    obj->field_10 = -1;
    obj->field_14 = -1;
    fn_1_8E7D0(obj);
}
/* fzgx:end fn_1_8F45C */

/* fzgx:begin fn_1_8F494 */
void fn_1_8F494(Fn1_8F494_Object *obj) {
    s32 i;
    s32 *entry;
    s32 value;
    s32 *entry2;
    s32 k;

    if (obj->active != 0) {
        value = -1;
        entry = &obj->active;
        for (i = 0; i < 5; i++) {
            if (entry[1] != -1) {
                value = obj->entries[i];
                break;
            }
            entry++;
        }
        if (value != -1) {
            fn_1_12A2B8(1);
            fn_1_12A2D0(value);
        } else {
            fn_1_12A2B8(0);
        }
        fn_1_9724C(obj);
        fn_1_107C4C( (void *)(Fn1_8F494_Object *)(obj));
        fn_1_966A0(obj);
        fn_1_95EF0(obj);
        fn_1_8F5A4( (Fn1_8F5A4_Object *)(Fn1_8F494_Object *)(obj));
        GXInvalidateTexAll();
        entry2 = (s32 *)obj;
        for (k = 0; k < 5; k++) {
            if (entry2[1] != -1) {
                fn_1_12A734(entry2[1]);
                entry2[1] = -1;
            }
            entry2++;
        }
        if (value != -1) {
            fn_1_12A2B8(0);
        }
        obj->active = 0;
    }
}
/* fzgx:end fn_1_8F494 */

/* fzgx:begin fn_1_8F5A4 */
void fn_1_8F5A4(Fn1_8F5A4_Object *obj) {
    u32 i;

    fn_1_961F0(obj->pad_148);
    fn_1_961F0(obj->pad_168);
    fn_1_961F0(obj->pad_1a8);
    fn_1_961F0(obj->pad_1c8);
    fn_1_961F0(obj->pad_1e8);
    for (i = 0; i < 0x14; i++) {
        fn_1_961F0(obj->entries[i]);
    }
    fn_1_968FC(obj);
}
/* fzgx:end fn_1_8F5A4 */

/* fzgx:begin fn_1_8FE74 */
typedef struct Fn8FE74Sub {
    u8 pad[0x4C];
    f32 unk_4C;
    f32 unk_50;
} Fn8FE74Sub;

typedef struct Fn8FE74Entry {
    u16 unk_0;
    u8 pad2[6];
    Fn8FE74Sub *unk_8;
    Sig_fn_1_41418_Fn41418Data *unk_C;
    u8 pad10[0x10];
} Fn8FE74Entry;

typedef struct Fn8FE74Obj {
    u8 pad[0x148];
    Fn8FE74Entry unk_148;
    Fn8FE74Entry unk_168;
    Fn8FE74Entry unk_188;
    Fn8FE74Entry unk_1A8;
    Fn8FE74Entry unk_1C8;
    Fn8FE74Entry unk_1E8;
    Fn8FE74Entry unk_208[20];
} Fn8FE74Obj;

void fn_1_8FE74(Fn8FE74Obj *arg0, Fn8FE74Entry *arg1, s32 arg2) {
    char *name;
    char *base = (char *)&lbl_1_data_209C0;
    char *fmt;
    s32 i;

    if (arg1->unk_8 == NULL || arg1->unk_C == NULL) {
        return;
    }
    if (arg1 == &arg0->unk_148) {
        name = base + 0x6EFC;
    } else if (arg1 == &arg0->unk_168) {
        name = base + 0x6F04;
    } else if (arg1 == &arg0->unk_188) {
        name = base + 0x6F0C;
    } else if (arg1 == &arg0->unk_1A8) {
        name = base + 0x6F14;
    } else if (arg1 == &arg0->unk_1C8) {
        name = base + 0x6F1C;
    } else if (arg1 == &arg0->unk_1E8) {
        name = base + 0x6F24;
    } else {
        for (i = 0; i < 20; i++) {
            if (arg1 == &arg0->unk_208[i]) {
                name = base + 0x6F2C;
                break;
            }
        }
    }
    fmt = base + 0x6F38;
    if (arg2) {
        fmt = base + 0x6F34;
    }
    fn_1_A8DD4(fmt);
    fn_1_A8F40(0x33);
    fn_1_A8DD4(base + 0x6F3C, name);
    fn_1_A8F40(0xFF);
    fn_1_A8DD4(base + 0x6F40, arg1->unk_0);
    fn_1_A8F40(0xF3);
    fn_1_A8DD4(base + 0x6F48, arg1->unk_8->unk_4C, arg1->unk_8->unk_50);
    fn_1_A8F40(0xFF);
    fn_1_A8DD4(base + 0x6F58, (char *)fn_1_41418( (void *)(Sig_fn_1_41418_Fn41418Data *)(arg1->unk_C), arg1->unk_0));
}
/* fzgx:end fn_1_8FE74 */

/* fzgx:begin fn_1_900B4 */
u32 fn_1_900B4(void) {
    return lbl_1_bss_6E978[0];
}
/* fzgx:end fn_1_900B4 */

/* fzgx:begin fn_1_900C4 noprologue */
#include "types.h"

struct fn_1_900C4_lbl_1_bss_6E960 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
};
struct fn_1_900C4_lbl_1_data_27920 {
    u32 unk_0;
};

extern struct fn_1_900C4_lbl_1_bss_6E960 lbl_1_bss_6E960;
extern struct fn_1_900C4_lbl_1_data_27920 lbl_1_data_27920;
extern u32 fn_1_95210(u32);
extern u32 lbl_1_data_27924;

void fn_1_900C4(void) {
    struct fn_1_900C4_lbl_1_bss_6E960 *p_lbl_1_bss_6E960;
    p_lbl_1_bss_6E960 = (struct fn_1_900C4_lbl_1_bss_6E960 *)&lbl_1_bss_6E960;
    p_lbl_1_bss_6E960->unk_1C = 1;
{
    u32 v0;
    p_lbl_1_bss_6E960->unk_18 = 0;
    p_lbl_1_bss_6E960->unk_20 = 0;
    p_lbl_1_bss_6E960->unk_0 = 0;
    p_lbl_1_bss_6E960->unk_4 = 0;
    p_lbl_1_bss_6E960->unk_8 = 0;
    p_lbl_1_bss_6E960->unk_C = 0;
    lbl_1_data_27924 = 1;
    p_lbl_1_bss_6E960->unk_10 = 0;
    p_lbl_1_bss_6E960->unk_14 = 0;
    fn_1_95210((lbl_1_data_27920.unk_0));
}
}
/* fzgx:end fn_1_900C4 */

/* fzgx:begin fn_1_924CC */
void fn_1_924CC(void) {
    u32 value;

    if (lbl_1_bss_6E984 != 0) {
        value = lbl_1_rodata_3FA0[0];
        fn_80007AB4( (u8 *)(void *)(&value));
    }
}
/* fzgx:end fn_1_924CC */

/* fzgx:begin fn_1_9250C */
void fn_1_9250C(void *arg0) {
    fn_1_92554(arg0, 0);
}
/* fzgx:end fn_1_9250C */

/* fzgx:begin fn_1_92530 */
void fn_1_92530(void *arg0) {
    fn_1_92554(arg0, 1);
}
/* fzgx:end fn_1_92530 */

/* fzgx:begin fn_1_933D8 noprologue */
#include "types.h"

typedef struct {
    u8 pad0[0x24];
    void *field_24;
} EventData;

typedef struct {
    u8 pad0[0x1c];
    void *field_1c;
} CarObject;

typedef struct {
    u8 pad0[0x8];
    EventData *field_8;
    void *field_c;
} EventObject;

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

extern void fn_1_95158(CarObject *arg0);
extern void *fn_1_41418(void *arg0, u32 arg1);
extern s32 fn_1_97174(EventNode *arg0, s32 arg1, void *arg2);
extern void fn_1_93734(CarObject *arg0, void *arg1);
extern void fn_1_4270C(void *arg0, s32 arg1, u32 arg2);

void fn_1_933D8(CarObject *arg0, EventObject *arg1, u32 arg2) {
    EventNode *node;
    s32 value;
    void *target;

    if (arg1 == (EventObject *)((u8 *)arg0 + 0x148)) {
        node = (EventNode *)arg0->field_1c;
        fn_1_95158(arg0);
        if (node != 0) {
            value = (s32)fn_1_97174(node, 0, fn_1_41418(arg1->field_8->field_24, arg2 & 0xffff));
            if (value < 0) {
                value = 0;
            }
            node->field_12 = 0;
            if ((s32)node->field_26 > 0) {
                target = node->field_28;
            } else {
                target = (void *)((u8 *)node->field_34 + -(s32)node->field_4c * 0xc);
            }
            *(u16 *)((u8 *)target + 0xa) = (u16)value;
        }
        fn_1_93734(arg0, fn_1_41418(arg1->field_c, arg2 & 0xffff));
    }
    fn_1_4270C(arg1->field_8, 0, arg2);
    *(u16 *)arg1 = (u16)arg2;
}
/* fzgx:end fn_1_933D8 */

/* fzgx:begin fn_1_934CC */
void fn_1_934CC(CarObject *arg0, EventObject *arg1, u32 arg2) {
    s32 value;
    EventNode *node;
    s32 result;
    void *target;

    result = fn_1_41488(arg1->field_8->field_24, (void *)(u32)(arg2));
    if (result + 0x10000u == 0xffff) {
        result = 0;
    }
    if (arg1 == (EventObject *)((u8 *)arg0 + 0x148)) {
        node = (EventNode *)arg0->field_1c;
        fn_1_95158( (Fn195158Car *)(CarObject *)(arg0));
        if (node != 0) {
            value = (s32)fn_1_97174(node, 0, (void *)fn_1_41418(arg1->field_8->field_24, result & 0xffff));
            if (value < 0) {
                value = 0;
            }
            node->field_12 = 0;
            if ((s32)node->field_26 > 0) {
                target = node->field_28;
            } else {
                target = (void *)((u8 *)node->field_34 + -(s32)node->field_4c * 0xc);
            }
            *(u16 *)((u8 *)target + 0xa) = (u16)value;
        }
        fn_1_93734( (u32)(CarObject *)(arg0), (u32)((void *)fn_1_41418(arg1->field_c, result & 0xffff)));
    }
    fn_1_4270C(arg1->field_8, 0, result & 0xffff);
    *(u16 *)arg1 = (u16)result;
}
/* fzgx:end fn_1_934CC */

/* fzgx:begin fn_1_935E4 */
typedef struct Fn935E4Res {
    u8 pad0[0x24];
    void *field_24;
} Fn935E4Res;
typedef struct Fn935E4Obj {
    u8 pad0[8];
    Fn935E4Res *field_8;
    void *field_c;
} Fn935E4Obj;


// Updates the selected car resource and applies the corresponding handling flags.
void fn_1_935E4(Fn935E4Car *arg0, void *arg1, void *arg2, f32 arg3) {
    u16 flags;
    u32 id;
    u16 short_value;
    Fn935E4Node *node;
    Fn935E4Slot *slot;
    s32 value;

    id = fn_1_41488(((Fn935E4Obj *)arg1)->field_8->field_24, arg2);
    if (id + 0x10000 == 0xffff) {
        id = 0;
    }

    flags = 0;
    if ((void *)arg1 == (void *)((u8 *)arg0 + 0x148)) {
        node = arg0->field_1c;
        if (node != 0) {
            value = fn_1_97174( (EventNode *)(Fn935E4Node *)(node), 0,
                (void *)fn_1_41418(((Fn935E4Obj *)arg1)->field_8->field_24, id));
            if (value < 0) {
                value = 0;
            }

            short_value = (u16)value;
            node->field_12 = 0;
            if ((s32)node->field_26 > 0) {
                slot = node->field_28;
            } else {
                slot = (Fn935E4Slot *)((u8 *)node->field_34
                    + (-(s32)node->field_4c) * 0xc);
            }
            slot->field_a = short_value;
        }

        fn_1_943F8(
            arg0, arg3,
            (void *)fn_1_41418(((Fn935E4Obj *)arg1)->field_c, id));
    }

    if (arg3 > lbl_1_rodata_4010[0]) {
        flags |= 0xc0;
    } else {
        flags |= 0x60;
    }

    fn_1_42AD0(
        ((Fn935E4Obj *)arg1)->field_8, 0, (u16)id, (s32)arg3, flags);
    ((u16 *)arg1)[0] = (u16)id;
}
/* fzgx:end fn_1_935E4 */

/* fzgx:begin fn_1_950E8 */
typedef struct Fn1950E8Data Fn1950E8Data;

struct Fn1950E8Data {
    u16 id;
    u8 unk_02[0x0A];
    void *resource;
};

s32 fn_1_950E8(Fn1950E8Data *data) {
    if (data == 0) {
        return 0;
    }
    return fn_1_41418(data->resource, data->id);
}
/* fzgx:end fn_1_950E8 */

/* fzgx:begin fn_1_95120 */
typedef struct Fn195120Data Fn195120Data;
typedef struct Fn195120Owner Fn195120Owner;

struct Fn195120Data {
    u8 unk_00[0x4C];
    f32 value_50;
    f32 value_4C;
};

struct Fn195120Owner {
    u8 unk_00[0x08];
    Fn195120Data *data;
};

s32 fn_1_95120(Fn195120Owner *owner) {
    if (owner == 0) {
        return 0;
    } else if (owner->data->value_50 >= owner->data->value_4C) {
        return 1;
    } else {
        return 0;
    }
}
/* fzgx:end fn_1_95120 */

/* fzgx:begin fn_1_95158 */
void fn_1_95158(Fn195158Car *car) {
    f32 value0;
    f32 value1;

    lbl_8006DAEC();
    lbl_8006D758();
    lbl_8006E0B4(car->unk_A8, car->unk_AC + car->unk_B4, car->unk_B0);
    mathutil_mtxA_rotate_z(car->unk_A4);
    mathutil_mtxA_rotate_y(car->unk_A0);
    mathutil_mtxA_rotate_x(car->unk_A2);
    lbl_8006E14C(car->unk_B8);
    lbl_8006DFC4(&car->unk_150->unk_08->unk_88);
    value0 = ((Fn195158Object *)lbl_801A6D00)->unk_0C;
    value1 = ((Fn195158Object *)lbl_801A6D00)->unk_2C;
    lbl_8006DB30();
    car->unk_A8 = value0;
    car->unk_B0 = value1;
}
/* fzgx:end fn_1_95158 */

/* fzgx:begin fn_1_95210 */
void fn_1_95210(void *arg0) {
    fn_80008BEC(arg0, 0, 0x70);
}
/* fzgx:end fn_1_95210 */

/* fzgx:begin fn_1_95238 */
typedef struct {
    u8 count;
    u8 field_1;
    u16 field_2;
    u8 pad04[0x3c];
    f32 field_40;
    u8 pad44[0x24];
    f32 field_68;
    f32 field_6c;
} EventList;




static inline void fn_1_95238_store(f32 *destination, f32 value) { *destination = value; }
static inline void fn_1_95238_call_fn_1_4270C(void * a0, void * a1, u32 a2) { fn_1_4270C(a0, (s32)(void *)(a1), a2); }

void fn_1_95238(u32 arg0, EventList *arg1) {
    f32 *fzgx_value;
    fn_1_95238_lbl_801A6D00 *p_lbl_801A6D00;
    struct { u16 value; } v3;
    u8 *v2;
    u8 *v1;
    u32 v0;
    u32 v4;
    u32 v5;
    s32 v7;
    void *v9;
    u32 v10;
    s32 v11;
    u32 v12;
    struct { u16 value; } v13;
    f32 v6;
    struct { f32 value; } v14;
    s32 v15;
    void *v16;

    arg1->field_1 = 0;
    fzgx_value = &(arg1->field_68);
    *fzgx_value = lbl_1_rodata_3F6C;
    p_lbl_801A6D00 = (fn_1_95238_lbl_801A6D00 *)&(*((fn_1_95238_lbl_801A6D00 *)&lbl_801A6D00));
    fn_1_95238_store(&(arg1->field_6c), lbl_1_rodata_3F6C);
    v2 = (u8 *)arg1;
    v1 = (u8 *)arg1;
    v0 = 0;
    while (v0 < arg1->count) {
        v3.value = *(u16 *)(v2 + 2);
        v4 = *(u32 *)((u8 *)arg0 + 0x1c);
        lbl_8006DAEC();
        lbl_8006D758();
        lbl_8006E0B4(*(f32 *)((u8 *)arg0 + 0xa8), (*(f32 *)((u8 *)arg0 + 0xac) + *(f32 *)((u8 *)arg0 + 0xb4)), *(f32 *)((u8 *)arg0 + 0xb0));
        mathutil_mtxA_rotate_z(*(s16 *)((u8 *)arg0 + 0xa4));
        mathutil_mtxA_rotate_y(*(s16 *)((u8 *)arg0 + 0xa0));
        mathutil_mtxA_rotate_x(*(s16 *)(((0xa2) + ((u8 *)arg0))));
        lbl_8006E14C(*(f32 *)((u8 *)arg0 + 0xb8));
        lbl_8006DFC4( (void *)(u32)((*(u32 *)((u8 *)*(u32 *)((u8 *)arg0 + 0x150) + 8) + 0x88)));
        v5 = p_lbl_801A6D00->unk_0;
        v14.value = *(f32 *)((u8 *)v5 + 12);
        v6 = *(f32 *)((u8 *)v5 + 44);
        lbl_8006DB30();
        *(f32 *)((u8 *)arg0 + 0xa8) = v14.value;
        *(f32 *)((u8 *)arg0 + 0xb0) = v6;
        if (v4) {
            v7 = fn_1_97174( (EventNode *)((Sig_fn_1_97174_Fn197174Owner *)v4), (s32)((void *)0), (char *)fn_1_41418( (void *)((Sig_fn_1_41418_Fn41418Data *)*(u32 *)((u8 *)*(u32 *)((u8 *)arg0 + 0x150) + 0x24)), v3.value));
            if (v7 < 0) {
                v7 = 0;
            }
            *(u16 *)((u8 *)v4 + 0x12) = 0;
            if ((s32)*(u8 *)((u8 *)v4 + 0x26) > 0) {
                v9 = *(void **)((u8 *)v4 + 0x28);
            } else {
                v9 = (void *)(*(u32 *)((u8 *)v4 + 0x34) + (-(s32)*(u8 *)((u8 *)v4 + 0x4c)) * 12);
            }
            *(u16 *)((u8 *)v9 + 0xa) = (u16)v7;
        }
        fn_1_93734(arg0, (u32)fn_1_41418( (void *)((Sig_fn_1_41418_Fn41418Data *)*(u32 *)((u8 *)arg0 + 0x154)), v3.value));
        fn_1_4270C((void *)*(u32 *)((u8 *)arg0 + 0x150), (s32)((void *)0), v3.value);
        *(u16 *)((u8 *)arg0 + 0x148) = v3.value;
        arg1->field_6c = arg1->field_6c + *(f32 *)((u8 *)*(u32 *)((u8 *)arg0 + 0x150) + 0x50);
        *(f32 *)(v1 + 0x40) = *(f32 *)((u8 *)*(u32 *)((u8 *)arg0 + 0x150) + 0x50);
        v2 += 2;
        v1 += 4;
        v0++;
    }
    v13.value = *(u16 *)((u8 *)arg1 + 2);
    v11 = *(u32 *)((u8 *)arg0 + 0x1c);
    lbl_8006DAEC();
    lbl_8006D758();
    lbl_8006E0B4(*(f32 *)((u8 *)arg0 + 0xa8), (*(f32 *)((u8 *)arg0 + 0xac) + *(f32 *)((u8 *)arg0 + 0xb4)), *(f32 *)((u8 *)arg0 + 0xb0));
    mathutil_mtxA_rotate_z(*(s16 *)((u8 *)arg0 + 0xa4));
    mathutil_mtxA_rotate_y(*(s16 *)((u8 *)arg0 + 0xa0));
    mathutil_mtxA_rotate_x(*(s16 *)(((0xa2) + ((u8 *)arg0))));
    lbl_8006E14C(*(f32 *)((u8 *)arg0 + 0xb8));
    lbl_8006DFC4( (void *)(u32)((*(u32 *)((u8 *)*(u32 *)((u8 *)arg0 + 0x150) + 8) + 0x88)));
    v12 = (*((fn_1_95238_lbl_801A6D00 *)&lbl_801A6D00)).unk_0;
    v14.value = *(f32 *)((u8 *)v12 + 12);
    v6 = *(f32 *)((u8 *)v12 + 44);
    lbl_8006DB30();
    *(f32 *)((u8 *)arg0 + 0xa8) = v14.value;
    *(f32 *)((u8 *)arg0 + 0xb0) = v6;
    if (v11 != 0U) {
        v15 = fn_1_97174( (EventNode *)((Sig_fn_1_97174_Fn197174Owner *)v11), (s32)((void *)0), (char *)fn_1_41418( (void *)((Sig_fn_1_41418_Fn41418Data *)*(u32 *)((u8 *)*(u32 *)((u8 *)arg0 + 0x150) + 0x24)), v13.value));
        if (v15 < 0) {
            v15 = 0;
        }
        *(u16 *)((u8 *)v11 + 0x12) = 0;
        if ((s32)*(u8 *)((u8 *)v11 + 0x26) > 0) {
            v16 = *(void **)((u8 *)v11 + 0x28);
        } else {
            v16 = (void *)(*(u32 *)((u8 *)v11 + 0x34) + (-(s32)*(u8 *)((u8 *)v11 + 0x4c)) * 12);
        }
        *(u16 *)((u8 *)v16 + 0xa) = (u16)v15;
    }
    fn_1_93734(arg0, (u32)fn_1_41418( (void *)((Sig_fn_1_41418_Fn41418Data *)*(u32 *)((u8 *)arg0 + 0x154)), v13.value));
    fn_1_95238_call_fn_1_4270C((void *)*(u32 *)((u8 *)arg0 + 0x150), (void *)0, v13.value);
    *(u16 *)((u8 *)arg0 + 0x148) = v13.value;
}
/* fzgx:end fn_1_95238 */

/* fzgx:begin fn_1_9550C */
typedef struct {
    u8 count;
    u8 current;
    u16 ids[9];
    f32 field_14[11];
    f32 field_40[10];
    f32 value;
} Config;



#pragma opt_common_subs off
#pragma opt_dead_assignments off
void fn_1_9550C(Owner *owner, Config *config) {
    s32 tmp_ra2;
    f32 value;
    s32 tmp_ra1;
    u16 flags;
    u16 id;

    value = config->value;
    {
        u32 i;
        for (i = 0; i < config->count; i++) {
            Node *state;
            f32 current_value;

            value -= config->field_40[i];
            if (value < (0.0f)) {
                tmp_ra1 = config->current;

                if (tmp_ra1 == i) {
                    break;
                }
                if (i != 0) {
                    owner->field_150->field_28 = (0.0f);
                    owner->field_150->field_2c = config->field_14[i];
                }
                state = owner->field_1c;
                current_value = owner->field_150->field_2c;
                id = config->ids[i];
                flags = 0;
                if (state != 0) {
                    void *target;
                    s32 result;

                    result = (s32)fn_1_97174( (EventNode *)(Node *)(state), 0, (void *)fn_1_41418(owner->field_150->field_24, id));
                    if (result < 0) {
                        result = 0;
                    }
                    state->field_12 = 0;
                    tmp_ra2 = state->field_26;
                    if (tmp_ra2 > 0) {
                        target = state->field_28;
                    } else {
                        target = (void *)((u8 *)state->field_34 + -(s32)state->field_4c * 0xc);
                    }
                    *(u16 *)((u8 *)target + 0xa) = (u16)result;
                }
                fn_1_943F8((Fn935E4Car *)(owner), current_value, (void *)fn_1_41418(owner->field_154, id));
                if (current_value > (50.0f)) {
                    flags |= 0xc0;
                } else {
                    flags |= 0x60;
                }
                fn_1_42AD0( (void *)(OutData *)(owner->field_150), 0, id, (s32)current_value, flags);
                owner->field_148 = id;
                config->current = i;
                break;
            }
        }
    }
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_9550C */

/* fzgx:begin fn_1_956B8 */
typedef struct Fn1956B8Data Fn1956B8Data;

struct Fn1956B8Data {
    u8 unk_00[0x68];
    f32 value;
    f32 limit;
};

void fn_1_956B8(Fn1956B8Data *data) {
    data->value += lbl_1_rodata_3F70[0];
    if (data->value >= data->limit) {
        data->value -= data->limit;
    }
}
/* fzgx:end fn_1_956B8 */

/* fzgx:begin fn_1_96130 */
void fn_1_96130(void *arg0) {
    fn_1_12AB38(lbl_1_data_27BA4);
    fn_1_465D0( (s32)(void *)(arg0), 1);
    fn_1_12AB38(&lbl_1_data_278AC);
}
/* fzgx:end fn_1_96130 */

/* fzgx:begin fn_1_9617C */
typedef struct CarResourceState CarResourceState;

struct CarResourceState {
    u8 unk_00[0x08];
    void *unk_08;
    void *unk_0C;
};

// Loads the car resource, updates its model data, and restores shared state.
void fn_1_9617C(CarResourceState *car, void *resource) {
    fn_1_12AB38(lbl_1_data_27BA4);
    if (fn_1_12A8A4( (u32)(void *)(resource), &car->unk_0C) != 0) {
        fn_1_41328(car->unk_0C);
        fn_1_426E4(car->unk_08, car->unk_0C);
    }
    fn_1_12AB38(&lbl_1_data_278AC);
}
/* fzgx:end fn_1_9617C */

/* fzgx:begin fn_1_967A8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car.h"

extern void fn_1_12AB38(void *arg0);
extern void fn_1_12A8A4(void *arg0, void *arg1);
extern u32 lbl_1_bss_6E98C;
extern void fn_1_96AE8(void);

extern void fn_1_12AB38(void *value);

typedef struct Fn1967A8Resource Fn1967A8Resource;
struct Fn1967A8Resource {
    u8 unk_00;
    u8 unk_01[0x07];
    u32 unk_08;
    u8 unk_0C[0x10];
    u32 unk_1C;
};

typedef struct Fn1967A8Object Fn1967A8Object;
struct Fn1967A8Object {
    u8 unk_00[0x1C];
    Fn1967A8Resource *unk_1C;
    void *unk_20;
    u8 unk_24[0x64];
    u32 unk_88;
    u8 unk_8C[0xC0];
    u32 unk_14C;
    u32 unk_150;
    void *unk_154;
};

extern Fn1967A8Resource *fn_1_41518(void *arg0);
extern void fn_1_41C18(Fn1967A8Resource *arg0, void *arg1);
extern void fn_1_41F58(Fn1967A8Resource *arg0, s32 arg1, void (*arg2)(void), void *arg3);
extern void fn_1_96968(void);
extern void fn_1_969E8(void);
extern void fn_1_96BC0(void);
extern void fn_1_96A68(void);

void fn_1_967A8(Fn1967A8Object *arg0, void *arg1) {
    u32 i;

    fn_1_12AB38(lbl_1_data_27BA4);
    fn_1_12A8A4(arg1, &arg0->unk_20);
    arg0->unk_1C = fn_1_41518(arg0->unk_20);
    arg0->unk_1C->unk_1C = arg0->unk_14C;
    arg0->unk_1C->unk_08 = arg0->unk_150;
    arg0->unk_1C->unk_00 = arg0->unk_88;
    fn_1_41C18(arg0->unk_1C, arg0->unk_154);
    fn_1_41F58(arg0->unk_1C, 0, fn_1_96968, arg0);
    fn_1_41F58(arg0->unk_1C, 1, fn_1_96968, arg0);
    fn_1_41F58(arg0->unk_1C, 2, fn_1_969E8, arg0);
    fn_1_41F58(arg0->unk_1C, 3, fn_1_96BC0, arg0);
    fn_1_41F58(arg0->unk_1C, 4, fn_1_96A68, arg0);
    for (i = 0; i < 0x14; i++) {
        lbl_1_bss_6E98C = i;
        fn_1_41F58(arg0->unk_1C, 5, fn_1_96AE8, arg0);
    }
    fn_1_12AB38(&lbl_1_data_278AC);
}
/* fzgx:end fn_1_967A8 */

/* fzgx:begin fn_1_96968 */
// Cache the resource key and return the requested resource sequence number.
u16 fn_1_96968(Fn196968Object *object, void *arg1) {
    if (object->unk_170 != 0 && object->unk_174 != 0) {
        object->unk_28 = fn_1_41488(object->unk_174, lbl_1_data_2785C);
        return (u16)((u32)fn_1_41488(object->unk_174, arg1) + 1);
    }

    object->unk_28 = 0;
    return 0;
}
/* fzgx:end fn_1_96968 */

/* fzgx:begin fn_1_969E8 */
// Resolve the owner's resource values and cache the associated lookup result.
u16 fn_1_969E8(Fn1969E8Owner *owner, void *arg1) {
    if (owner->unk_1b0 != 0 && owner->unk_1b4 != 0) {
        owner->unk_2c = fn_1_41488(owner->unk_1b4, &lbl_1_data_22A24);
        return (u16)(fn_1_41488(owner->unk_1b4, arg1) + 1);
    }

    owner->unk_2c = 0;
    return 0;
}
/* fzgx:end fn_1_969E8 */

/* fzgx:begin fn_1_96A68 */
// Updates the car's resource state and returns the next resource index.
u16 fn_1_96A68(Fn196A68Object *object, void *arg1) {
    if (object->unk_1F0 != 0 && object->unk_1F4 != 0) {
        object->unk_34 = fn_1_41488(object->unk_1F4, &lbl_1_data_27870);
        return (u16)(fn_1_41488(object->unk_1F4, arg1) + 1);
    }
    object->unk_34 = 0;
    return 0;
}
/* fzgx:end fn_1_96A68 */

/* fzgx:begin fn_1_96B14 */
typedef struct Fn196B14Entry Fn196B14Entry;
struct Fn196B14Entry {
    u8 unk_00[0x210];
    void *unk_210;
    void *unk_214;
};

// Computes the indexed entry value when its backing resource is available.
u16 fn_1_96B14(void *base, void *arg1, s32 index) {
    Fn196B14Entry *entry = (Fn196B14Entry *)((u8 *)base + (index << 5));

    if (entry->unk_210 != 0 && entry->unk_214 != 0) {
        ((u32 *)((u8 *)base + 0x38))[index] =
            (u32)fn_1_41488(entry->unk_214, lbl_1_data_27874);
        return (u16)(fn_1_41488(entry->unk_214, arg1) + 1);
    }

    ((u32 *)((u8 *)base + 0x38))[index] = 0;
    return 0;
}
/* fzgx:end fn_1_96B14 */

/* fzgx:begin fn_1_96BC0 */
// Updates the car's resource-derived value and returns the converted result.
u16 fn_1_96BC0(Fn196BC0Object *object, void *arg1) {
    if (object->resource_1D0 != 0 && object->resource_1D4 != 0) {
        object->value_30 = (void *)fn_1_41488(
            object->resource_1D4, &lbl_1_data_2786C);
        return (u16)(fn_1_41488(object->resource_1D4, arg1) + 1);
    }

    object->value_30 = 0;
    return 0;
}
/* fzgx:end fn_1_96BC0 */

/* fzgx:begin fn_1_96F20 noprologue */
#include "types.h"
#include "rel/main_rel/car.h"

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

typedef struct CarR29 {
    u8 unk_00[0x14];
    f32 unk_14;
} CarR29;

typedef struct CarSub2 {
    u8 unk_00[0x88];
    u8 unk_88[1];
} CarSub2;

typedef struct CarSub {
    u8 unk_00[0x8];
    CarSub2 *unk_8;
} CarSub;

typedef struct CarData {
    u8 unk_00[0x8c];
    s32 unk_8c;
    u8 unk_90[0x10];
    s16 unk_a0;
    s16 unk_a2;
    s16 unk_a4;
    u8 unk_a6[2];
    f32 unk_a8;
    f32 unk_ac;
    f32 unk_b0;
    f32 unk_b4;
    f32 unk_b8;
    u8 unk_bc[0x28];
    void *unk_e4[1];
    u8 unk_e8[0x150 - 0xe8];
    CarSub *unk_150;
} CarData;

extern const f32 lbl_1_rodata_3E48[];

extern void *camera_get_state_object(void);
extern void camera_update_state(void *);
extern CarR29 *fn_80071268(void *, void *);
extern void lbl_8006E1F0(Vec3f *, f32, f32, f32);
extern void fn_1_A714C(f32 *, s32, s32, f32 *);
extern f32 lbl_8006D21C(s32);
extern void lbl_8006DAEC(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern void mathutil_mtxA_rotate_z(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern void lbl_8006E14C(f32);
extern void lbl_8006DFC4(void *);
extern f32 (*lbl_801A6D00)[4];
extern void lbl_8006DB30(void);
extern void lbl_8006E2C0(Vec3f *, f32, f32, f32);
extern void fn_8006E250(Vec3f *, Vec3f *);
extern void fn_1_B81C(Vec3f *, Vec3f *, s32);

void fn_1_96F20(CarData *car) {
    const f32 *pool = lbl_1_rodata_3E48;
    Vec3f sp40;
    Vec3f sp34;
    Vec3f sp28;
    Vec3f sp1C;
    Vec3f sp10;
    f32 spC;
    f32 sp8;
    CarR29 *r29;
    void *cam;
    CarSub2 *sub2;
    f32 f31_val;
    f32 mtx_x, mtx_y, mtx_z;

    cam = camera_get_state_object();
    r29 = fn_80071268(car->unk_e4[car->unk_8c], &lbl_1_data_22A1C);
    if (!r29) {
        r29 = fn_80071268(car->unk_e4[car->unk_8c], &lbl_1_data_24EF0);
    }
    if (!r29) {
        return;
    }

    camera_update_state(cam);
    lbl_8006E1F0(&sp10, pool[0x49], pool[0x4A], pool[0x49]);
    fn_1_A714C(&spC, 0, 0, &sp8);

    f31_val = lbl_8006D21C((s32)(pool[0x77] * spC * pool[0x66]));

    lbl_8006DAEC();
    sub2 = car->unk_150->unk_8;
    lbl_8006E0B4(car->unk_a8, car->unk_ac + car->unk_b4, car->unk_b0);
    mathutil_mtxA_rotate_z(car->unk_a4);
    mathutil_mtxA_rotate_y(car->unk_a0);
    mathutil_mtxA_rotate_x(car->unk_a2);
    lbl_8006E14C(car->unk_b8);
    lbl_8006DFC4(&sub2->unk_88);

    mtx_x = lbl_801A6D00[0][3];
    mtx_y = lbl_801A6D00[1][3];
    mtx_z = lbl_801A6D00[2][3];
    lbl_8006DB30();

    sp28.x = mtx_x;
    sp28.y = mtx_y;
    sp28.z = mtx_z + (pool[0x8D] * r29->unk_14) / f31_val;
    sp28.x *= pool[0x8E];
    sp28.y *= pool[0x8E];
    sp28.z *= pool[0x8E];
    if (sp28.z > sp8 + (mtx_z - r29->unk_14)) {
        sp28.z = sp8 + (mtx_z - r29->unk_14);
    }

    lbl_8006E2C0(&sp1C, pool[0x49], pool[0x49], mtx_z - sp28.z);
    fn_8006E250(&sp28, &sp40);

    sp34.x = sp40.x + sp1C.x;
    sp34.y = sp40.y + sp1C.y;
    sp34.z = sp40.z + sp1C.z;

    fn_1_B81C(&sp40, &sp34, 0);
}
/* fzgx:end fn_1_96F20 */

/* fzgx:begin fn_1_A7E60 */
typedef struct FnA7E60Object {
    u8 pad_fc[0xfc];
    s32 unk_fc;
    s32 unk_100;
    s32 unk_104;
    s32 unk_108;
} FnA7E60Object;

// Initialize the selected car data and build its localized display values.
void fn_1_A7E60(void *arg0, s8 arg1, FnA7E60Object *object, s32 arg3, void *arg4) {
    char buffer[0x80];
    u8 *data;
    s32 index;
    s32 format_value;

    data = lbl_1_data_34348;
    index = (s32)arg1;
    object->unk_fc = ((s32 *)lbl_1_data_26B60)[index];
    object->unk_100 = ((s32 *)lbl_1_data_26C14)[index];

    if (arg3 != -1) {
        fn_1_12A2B8( (s32)(1));
        fn_1_12A2C4( (s32)(1));
        fn_1_12A2D0(arg3);
    } else {
        fn_1_12A2B8( (s32)(0));
    }

    fn_1_12AB38(data + 0x40);
    format_value = ((s32 *)lbl_1_data_20D1C)[index];
    sprintf(buffer, (const char *)(data + 0x18), format_value);
    object->unk_108 = fn_1_12AC00((unsigned char *)buffer);
    sprintf(buffer, (const char *)(data + 0x48), format_value);
    object->unk_104 = fn_1_12ADA0((unsigned char *)buffer, object->unk_108);
    fn_1_12AB38(data + 0x3c);
    fn_1_12A2B8( (s32)(0));
    fn_1_12A2C4( (s32)(0));
    fn_1_A7B5C(object, 0, arg0, arg1, arg4);
}
/* fzgx:end fn_1_A7E60 */
