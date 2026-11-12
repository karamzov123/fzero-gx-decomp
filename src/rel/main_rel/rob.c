#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/rob.h"

extern void fn_1_12ABB4(void *arg0);
extern void fn_1_96230(void *arg0, void *arg1, void *arg2, void *arg3, int arg4);
extern void fn_1_41850(void *arg0);
extern u32 lbl_1_bss_6E98C;
extern u16 fn_1_96B14(void *base, void *arg1, s32 index);
extern s32 fn_80083BCC(void *arg0, void *arg1);
extern void ADXT_Stop(u32 arg0);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, u8 *, u32);
extern void fn_80008BEC(void *, u32, u32);

extern const char *lbl_1_data_20D1C[];
extern void sprintf(char *buffer, u8 *format, ...);
extern s32 fn_1_12A32C(char *buffer);
extern s16 fn_1_98104(void);

/* fzgx:begin fn_1_95EF0 noprologue */
#include "types.h"

struct fn_1_95EF0_Arg0 {
    u8 pad_0[0x14C];
    u32 unk_14C;
};
struct fn_1_95EF0_lbl_801A6410 {
    u32 unk_0;
};
extern struct fn_1_95EF0_lbl_801A6410 lbl_801A6410;
extern u8 lbl_1_data_27C00[];
extern void fn_1_12ABB4(void *);
extern void fn_1_46B4(u32, u32, const char *, int);

void fn_1_95EF0(void *arg0, s32 arg_sp0) {
    void *var_r28;
    void *temp_r3_7;
    void *temp_r3_6;
    void *temp_r3_5;
    void *temp_r3_4;
    void *temp_r3_3;
    void *temp_r3_2;
    void *temp_r3;
    u32 var_r27;
    u32 temp_r4_7;
    u32 temp_r4_6;
    u32 temp_r4_5;
    u32 temp_r4_4;
    u32 temp_r4_3;
    u32 temp_r4_2;
    u32 temp_r4;

    temp_r3 = (void *)(*(void **)((u8 *)(arg0) + 332));
    if (temp_r3 != NULL) {
        fn_1_12ABB4((void *)(temp_r3));
        (*(void **)((u8 *)(arg0) + 332)) = (void *)(NULL);
    }
    temp_r4 = *(u32 *)((u8 *)(arg0) + 336);
    if (temp_r4 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4, (const char *)((s8 *) lbl_1_data_27C00), 0xB44);
        (*(u32 *)((u8 *)(arg0) + 336)) = 0U;
    }
    temp_r3_2 = (void *)(*(void **)((u8 *)(arg0) + 364));
    if (temp_r3_2 != NULL) {
        fn_1_12ABB4((void *)(temp_r3_2));
        (*(void **)((u8 *)(arg0) + 364)) = (void *)(NULL);
    }
    temp_r4_2 = *(u32 *)((u8 *)(arg0) + 368);
    if (temp_r4_2 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_2, (const char *)((s8 *) lbl_1_data_27C00), 0xB49);
        (*(u32 *)((u8 *)(arg0) + 368)) = 0U;
    }
    temp_r3_3 = (void *)(*(void **)((u8 *)(arg0) + 396));
    if (temp_r3_3 != NULL) {
        fn_1_12ABB4((void *)(temp_r3_3));
        (*(void **)((u8 *)(arg0) + 396)) = (void *)(NULL);
    }
    temp_r4_3 = *(u32 *)((u8 *)(arg0) + 400);
    if (temp_r4_3 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_3, (const char *)((s8 *) lbl_1_data_27C00), 0xB4B);
        (*(u32 *)((u8 *)(arg0) + 400)) = 0U;
    }
    temp_r3_4 = (void *)(*(void **)((u8 *)(arg0) + 428));
    if (temp_r3_4 != NULL) {
        fn_1_12ABB4((void *)(temp_r3_4));
        (*(void **)((u8 *)(arg0) + 428)) = (void *)(NULL);
    }
    temp_r4_4 = *(u32 *)((u8 *)(arg0) + 432);
    if (temp_r4_4 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_4, (const char *)((s8 *) lbl_1_data_27C00), 0xB4D);
        (*(u32 *)((u8 *)(arg0) + 432)) = 0U;
    }
    temp_r3_5 = (void *)(*(void **)((u8 *)(arg0) + 460));
    if (temp_r3_5 != NULL) {
        fn_1_12ABB4((void *)(temp_r3_5));
        (*(void **)((u8 *)(arg0) + 460)) = (void *)(NULL);
    }
    temp_r4_5 = *(u32 *)((u8 *)(arg0) + 464);
    if (temp_r4_5 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_5, (const char *)((s8 *) lbl_1_data_27C00), 0xB4F);
        (*(u32 *)((u8 *)(arg0) + 464)) = 0U;
    }
    temp_r3_6 = (void *)(*(void **)((u8 *)(arg0) + 492));
    if (temp_r3_6 != NULL) {
        fn_1_12ABB4((void *)(temp_r3_6));
        (*(void **)((u8 *)(arg0) + 492)) = (void *)(NULL);
    }
    temp_r4_6 = *(u32 *)((u8 *)(arg0) + 496);
    if (temp_r4_6 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_6, (const char *)((s8 *) lbl_1_data_27C00), 0xB51);
        (*(u32 *)((u8 *)(arg0) + 496)) = 0U;
    }
    var_r28 = (void *)(arg0);
    var_r27 = 0U;
    do {
        temp_r3_7 = (void *)(*(void **)((u8 *)(var_r28) + 524));
        if (temp_r3_7 != NULL) {
            fn_1_12ABB4((void *)(temp_r3_7));
            (*(void **)((u8 *)(var_r28) + 524)) = (void *)(NULL);
        }
        temp_r4_7 = *(u32 *)((u8 *)(var_r28) + 528);
        if (temp_r4_7 != 0) {
            fn_1_46B4(lbl_801A6410.unk_0, temp_r4_7, (const char *)((s8 *) lbl_1_data_27C00), 0xB54);
            (*(u32 *)((u8 *)(var_r28) + 528)) = 0U;
        }
        var_r27 += 1;
        var_r28 = (void *)((u8 *)(var_r28) + 0x20);
    } while (var_r27 < 0x14U);
}
/* fzgx:end fn_1_95EF0 */

/* fzgx:begin fn_1_96130 noprologue */
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
extern void GXGetScissor(u32 *left, u32 *top, u32 *width, u32 *height);
extern void GXGetProjectionv(f32* out);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
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
extern u8 lbl_1_bss_6DA5C__fzgx_offset_1E;
extern u8 lbl_1_bss_6DA5C__fzgx_offset_1F[5];
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

void fn_1_96130(void *arg0) {
    fn_1_12AB38(lbl_1_data_27BA4);
    fn_1_465D0( (s32)(void *)(arg0), 1);
    fn_1_12AB38(&lbl_1_data_278AC);
}
/* fzgx:end fn_1_96130 */

/* fzgx:begin fn_1_9617C noprologue */
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
extern void GXGetScissor(u32 *left, u32 *top, u32 *width, u32 *height);
extern void GXGetProjectionv(f32* out);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
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
extern u8 lbl_1_bss_6DA5C__fzgx_offset_1E;
extern u8 lbl_1_bss_6DA5C__fzgx_offset_1F[5];
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

/* fzgx:begin fn_1_961F0 */
typedef struct Fn1961F0Owner Fn1961F0Owner;

struct Fn1961F0Owner {
    u8 unk_00[0x0C];
    void *resource;
};

void fn_1_961F0(Fn1961F0Owner *owner) {
    if (owner->resource != 0) {
        fn_1_12ABB4(owner->resource);
        owner->resource = 0;
    }
}
/* fzgx:end fn_1_961F0 */

/* fzgx:begin fn_1_96230 noprologue */
#include "types.h"

typedef struct Fn196230Obj {
    u8 unk_00[0x4];
    s32 ids[5];
    u8 unk_18[0xE4 - 0x18];
    u32 handles[5];
    void *files[5][4];
} Fn196230Obj;

typedef struct Fn196230Data {
    u8 pad_0[0x35C];
    const char *names[(0x6ED8 - 0x35C) / 4];
    u8 lock_6ED8[8];
    char fmt_6EE0[0xC];
    u8 unlock_6EEC[0x7278 - 0x6EEC];
    char fmt_7278[0xC];
    char fmt_7284[4];
} Fn196230Data;

extern Fn196230Data lbl_1_data_209C0;

static const char *const fzgx_pool_sDirs[5] = {0};
static const char *const fzgx_pool_sPacks[5] = {0};
static const char *const fzgx_pool_sExts[4] = {0};

extern void fn_1_12AB38(void *);
extern s32 fn_1_465D0(char *, s32);
extern void fn_1_12A2B8(u32);
extern void fn_1_12A2D0(s32);
extern void *fn_1_12AC00(char *);
extern u32 fn_1_12ADA0(char *, void *);
extern int sprintf(char *, const char *, ...);

/* bit n of a mask counted from the most significant bit */
#define MASK_BIT(mask, n) __rlwnm((mask), ((n) + 1) & 0x1F, 31, 31)

extern u8 fn_1_9012C__fzgx_offset_3D4[];
extern u8 fn_1_9012C__fzgx_offset_40C[];
extern u8 fn_1_9012C__fzgx_offset_440[];
extern u8 fn_1_9012C__fzgx_offset_468[];
extern u8 fn_1_9012C__fzgx_offset_488[];
extern u8 fn_1_9012C__fzgx_offset_4A8[];
extern u8 fn_1_9012C__fzgx_offset_4FC[];
extern u8 fn_1_9012C__fzgx_offset_53C[];
extern u8 fn_1_9012C__fzgx_offset_5B0[];
extern u8 fn_1_9012C__fzgx_offset_624[];
extern u8 fn_1_9012C__fzgx_offset_698[];
extern u8 fn_1_9012C__fzgx_offset_70C[];
extern u8 fn_1_9012C__fzgx_offset_780[];
extern u8 fn_1_9012C__fzgx_offset_7EC[];
extern u8 lbl_1_bss_6E990__fzgx_offset_0[];
extern u8 lbl_1_data_209C0__fzgx_offset_0[];
extern u8 lbl_1_data_209C8__fzgx_offset_0[];
extern u8 lbl_1_data_209D0__fzgx_offset_0[];
extern u8 lbl_1_data_209D8__fzgx_offset_0[];
extern u8 lbl_1_data_209E0__fzgx_offset_0[];
extern u8 lbl_1_data_209E8__fzgx_offset_0[];
extern u8 lbl_1_data_209F0__fzgx_offset_0[];
extern u8 lbl_1_data_209F8__fzgx_offset_0[];
extern u8 lbl_1_data_20A00__fzgx_offset_0[];
extern u8 lbl_1_data_20A04__fzgx_offset_0[];
extern u8 lbl_1_data_20A0C__fzgx_offset_0[];
extern u8 lbl_1_data_20A14__fzgx_offset_0[];
extern u8 lbl_1_data_20A1C__fzgx_offset_0[];
extern u8 lbl_1_data_20A24__fzgx_offset_0[];
extern u8 lbl_1_data_20A2C__fzgx_offset_0[];
extern u8 lbl_1_data_20A30__fzgx_offset_0[];
extern u8 lbl_1_data_20A38__fzgx_offset_0[];
extern u8 lbl_1_data_20A40__fzgx_offset_0[];
extern u8 lbl_1_data_20A4C__fzgx_offset_0[];
extern u8 lbl_1_data_20A54__fzgx_offset_0[];
extern u8 lbl_1_data_20A5C__fzgx_offset_0[];
extern u8 lbl_1_data_20A60__fzgx_offset_0[];
extern u8 lbl_1_data_20A68__fzgx_offset_0[];
extern u8 lbl_1_data_20A70__fzgx_offset_0[];
extern u8 lbl_1_data_20A78__fzgx_offset_0[];
extern u8 lbl_1_data_20A80__fzgx_offset_0[];
extern u8 lbl_1_data_20A88__fzgx_offset_0[];
extern u8 lbl_1_data_20A90__fzgx_offset_0[];
extern u8 lbl_1_data_20A98__fzgx_offset_0[];
extern u8 lbl_1_data_20AA0__fzgx_offset_0[];
extern u8 lbl_1_data_20AA8__fzgx_offset_0[];
extern u8 lbl_1_data_20AB0__fzgx_offset_0[];
extern u8 lbl_1_data_20AB4__fzgx_offset_0[];
extern u8 lbl_1_data_20ABC__fzgx_offset_0[];
extern u8 lbl_1_data_20AC0__fzgx_offset_0[];
extern u8 lbl_1_data_20AC8__fzgx_offset_0[];
extern u8 lbl_1_data_20AD4__fzgx_offset_0[];
extern u8 lbl_1_data_20ADC__fzgx_offset_0[];
extern u8 lbl_1_data_20AE4__fzgx_offset_0[];
extern u8 lbl_1_data_20AE8__fzgx_offset_0[];
extern u8 lbl_1_data_20AEC__fzgx_offset_0[];
extern u8 lbl_1_data_20AF8__fzgx_offset_0[];
extern u8 lbl_1_data_20B00__fzgx_offset_0[];
extern u8 lbl_1_data_20B04__fzgx_offset_0[];
extern u8 lbl_1_data_20B08__fzgx_offset_0[];
extern u8 lbl_1_data_20BC8__fzgx_offset_0[];
extern u8 lbl_1_data_20BD0__fzgx_offset_0[];
extern u8 lbl_1_data_20BD8__fzgx_offset_0[];
extern u8 lbl_1_data_20BE0__fzgx_offset_0[];
extern u8 lbl_1_data_20BE8__fzgx_offset_0[];
extern u8 lbl_1_data_20BF0__fzgx_offset_0[];
extern u8 lbl_1_data_20BF8__fzgx_offset_0[];
extern u8 lbl_1_data_20C00__fzgx_offset_0[];
extern u8 lbl_1_data_20C08__fzgx_offset_0[];
extern u8 lbl_1_data_20C0C__fzgx_offset_0[];
extern u8 lbl_1_data_20C14__fzgx_offset_0[];
extern u8 lbl_1_data_20C1C__fzgx_offset_0[];
extern u8 lbl_1_data_20C24__fzgx_offset_0[];
extern u8 lbl_1_data_20C2C__fzgx_offset_0[];
extern u8 lbl_1_data_20C34__fzgx_offset_0[];
extern u8 lbl_1_data_20C38__fzgx_offset_0[];
extern u8 lbl_1_data_20C40__fzgx_offset_0[];
extern u8 lbl_1_data_20C48__fzgx_offset_0[];
extern u8 lbl_1_data_20C54__fzgx_offset_0[];
extern u8 lbl_1_data_20C5C__fzgx_offset_0[];
extern u8 lbl_1_data_20C64__fzgx_offset_0[];
extern u8 lbl_1_data_20C68__fzgx_offset_0[];
extern u8 lbl_1_data_20C70__fzgx_offset_0[];
extern u8 lbl_1_data_20C78__fzgx_offset_0[];
extern u8 lbl_1_data_20C80__fzgx_offset_0[];
extern u8 lbl_1_data_20C88__fzgx_offset_0[];
extern u8 lbl_1_data_20C90__fzgx_offset_0[];
extern u8 lbl_1_data_20C98__fzgx_offset_0[];
extern u8 lbl_1_data_20CA0__fzgx_offset_0[];
extern u8 lbl_1_data_20CA8__fzgx_offset_0[];
extern u8 lbl_1_data_20CB0__fzgx_offset_0[];
extern u8 lbl_1_data_20CB8__fzgx_offset_0[];
extern u8 lbl_1_data_20CBC__fzgx_offset_0[];
extern u8 lbl_1_data_20CC4__fzgx_offset_0[];
extern u8 lbl_1_data_20CC8__fzgx_offset_0[];
extern u8 lbl_1_data_20CD0__fzgx_offset_0[];
extern u8 lbl_1_data_20CDC__fzgx_offset_0[];
extern u8 lbl_1_data_20CE4__fzgx_offset_0[];
extern u8 lbl_1_data_20CEC__fzgx_offset_0[];
extern u8 lbl_1_data_20CF0__fzgx_offset_0[];
extern u8 lbl_1_data_20CF4__fzgx_offset_0[];
extern u8 lbl_1_data_20D00__fzgx_offset_0[];
extern u8 lbl_1_data_20D08__fzgx_offset_0[];
extern u8 lbl_1_data_20D0C__fzgx_offset_0[];
extern u8 lbl_1_data_20D10__fzgx_offset_0[];
extern u8 lbl_1_data_20DD0__fzgx_offset_0[];
extern u8 lbl_1_data_20DE4__fzgx_offset_0[];
extern u8 lbl_1_data_20DF4__fzgx_offset_0[];
extern u8 lbl_1_data_20E0C__fzgx_offset_0[];
extern u8 lbl_1_data_20E14__fzgx_offset_0[];
extern u8 lbl_1_data_20E24__fzgx_offset_0[];
extern u8 lbl_1_data_20E2C__fzgx_offset_0[];
extern u8 lbl_1_data_20E44__fzgx_offset_0[];
extern u8 lbl_1_data_20E50__fzgx_offset_0[];
extern u8 lbl_1_data_20E6C__fzgx_offset_0[];
extern u8 lbl_1_data_20E84__fzgx_offset_0[];
extern u8 lbl_1_data_20E8C__fzgx_offset_0[];
extern u8 lbl_1_data_20E9C__fzgx_offset_0[];
extern u8 lbl_1_data_20EA4__fzgx_offset_0[];
extern u8 lbl_1_data_20EB4__fzgx_offset_0[];
extern u8 lbl_1_data_20EC4__fzgx_offset_0[];
extern u8 lbl_1_data_20ED0__fzgx_offset_0[];
extern u8 lbl_1_data_20EE4__fzgx_offset_0[];
extern u8 lbl_1_data_20EF4__fzgx_offset_0[];
extern u8 lbl_1_data_20EFC__fzgx_offset_0[];
extern u8 lbl_1_data_20F0C__fzgx_offset_0[];
extern u8 lbl_1_data_20F1C__fzgx_offset_0[];
extern u8 lbl_1_data_20F2C__fzgx_offset_0[];
extern u8 lbl_1_data_20F40__fzgx_offset_0[];
extern u8 lbl_1_data_20F54__fzgx_offset_0[];
extern u8 lbl_1_data_20F68__fzgx_offset_0[];
extern u8 lbl_1_data_20F78__fzgx_offset_0[];
extern u8 lbl_1_data_20F80__fzgx_offset_0[];
extern u8 lbl_1_data_20F94__fzgx_offset_0[];
extern u8 lbl_1_data_20FA8__fzgx_offset_0[];
extern u8 lbl_1_data_20FBC__fzgx_offset_0[];
extern u8 lbl_1_data_20FC8__fzgx_offset_0[];
extern u8 lbl_1_data_20FD8__fzgx_offset_0[];
extern u8 lbl_1_data_20FE4__fzgx_offset_0[];
extern u8 lbl_1_data_20FF8__fzgx_offset_0[];
extern u8 lbl_1_data_21004__fzgx_offset_0[];
extern u8 lbl_1_data_21010__fzgx_offset_0[];
extern u8 lbl_1_data_2101C__fzgx_offset_0[];
extern u8 lbl_1_data_21024__fzgx_offset_0[];
extern u8 lbl_1_data_21030__fzgx_offset_0[];
extern u8 lbl_1_data_21040__fzgx_offset_0[];
extern u8 lbl_1_data_21050__fzgx_offset_0[];
extern u8 lbl_1_data_21058__fzgx_offset_0[];
extern u8 lbl_1_data_21060__fzgx_offset_0[];
extern u8 lbl_1_data_21068__fzgx_offset_0[];
extern u8 lbl_1_data_2112C__fzgx_offset_0[];
extern u8 lbl_1_data_2113C__fzgx_offset_0[];
extern u8 lbl_1_data_21148__fzgx_offset_0[];
extern u8 lbl_1_data_21154__fzgx_offset_0[];
extern u8 lbl_1_data_21164__fzgx_offset_0[];
extern u8 lbl_1_data_21174__fzgx_offset_0[];
extern u8 lbl_1_data_2117C__fzgx_offset_0[];
extern u8 lbl_1_data_21184__fzgx_offset_0[];
extern u8 lbl_1_data_21194__fzgx_offset_0[];
extern u8 lbl_1_data_211A0__fzgx_offset_0[];
extern u8 lbl_1_data_211AC__fzgx_offset_0[];
extern u8 lbl_1_data_211B4__fzgx_offset_0[];
extern u8 lbl_1_data_211C0__fzgx_offset_0[];
extern u8 lbl_1_data_211D0__fzgx_offset_0[];
extern u8 lbl_1_data_211DC__fzgx_offset_0[];
extern u8 lbl_1_data_211E8__fzgx_offset_0[];
extern u8 lbl_1_data_211F8__fzgx_offset_0[];
extern u8 lbl_1_data_21208__fzgx_offset_0[];
extern u8 lbl_1_data_21218__fzgx_offset_0[];
extern u8 lbl_1_data_21228__fzgx_offset_0[];
extern u8 lbl_1_data_21234__fzgx_offset_0[];
extern u8 lbl_1_data_21244__fzgx_offset_0[];
extern u8 lbl_1_data_21250__fzgx_offset_0[];
extern u8 lbl_1_data_21260__fzgx_offset_0[];
extern u8 lbl_1_data_2126C__fzgx_offset_0[];
extern u8 lbl_1_data_21278__fzgx_offset_0[];
extern u8 lbl_1_data_21284__fzgx_offset_0[];
extern u8 lbl_1_data_21290__fzgx_offset_0[];
extern u8 lbl_1_data_21298__fzgx_offset_0[];
extern u8 lbl_1_data_212A0__fzgx_offset_0[];
extern u8 lbl_1_data_2135C__fzgx_offset_0[];
extern u8 lbl_1_data_21384__fzgx_offset_0[];
extern u8 lbl_1_data_213A0__fzgx_offset_0[];
extern u8 lbl_1_data_213B0__fzgx_offset_0[];
extern u8 lbl_1_data_213C4__fzgx_offset_0[];
extern u8 lbl_1_data_213D4__fzgx_offset_0[];
extern u8 lbl_1_data_213E4__fzgx_offset_0[];
extern u8 lbl_1_data_213EC__fzgx_offset_0[];
extern u8 lbl_1_data_21414__fzgx_offset_0[];
extern u8 lbl_1_data_21434__fzgx_offset_0[];
extern u8 lbl_1_data_21444__fzgx_offset_0[];
extern u8 lbl_1_data_21454__fzgx_offset_0[];
extern u8 lbl_1_data_21464__fzgx_offset_0[];
extern u8 lbl_1_data_2146C__fzgx_offset_0[];
extern u8 lbl_1_data_21494__fzgx_offset_0[];
extern u8 lbl_1_data_214B4__fzgx_offset_0[];
extern u8 lbl_1_data_214C4__fzgx_offset_0[];
extern u8 lbl_1_data_214D4__fzgx_offset_0[];
extern u8 lbl_1_data_214E4__fzgx_offset_0[];
extern u8 lbl_1_data_214EC__fzgx_offset_0[];
extern u8 lbl_1_data_21514__fzgx_offset_0[];
extern u8 lbl_1_data_2153C__fzgx_offset_0[];
extern u8 lbl_1_data_2154C__fzgx_offset_0[];
extern u8 lbl_1_data_2155C__fzgx_offset_0[];
extern u8 lbl_1_data_2156C__fzgx_offset_0[];
extern u8 lbl_1_data_21574__fzgx_offset_0[];
extern u8 lbl_1_data_2159C__fzgx_offset_0[];
extern u8 lbl_1_data_215B8__fzgx_offset_0[];
extern u8 lbl_1_data_215C8__fzgx_offset_0[];
extern u8 lbl_1_data_215D8__fzgx_offset_0[];
extern u8 lbl_1_data_215E8__fzgx_offset_0[];
extern u8 lbl_1_data_215F0__fzgx_offset_0[];
extern u8 lbl_1_data_21618__fzgx_offset_0[];
extern u8 lbl_1_data_21628__fzgx_offset_0[];
extern u8 lbl_1_data_21638__fzgx_offset_0[];
extern u8 lbl_1_data_21648__fzgx_offset_0[];
extern u8 lbl_1_data_21658__fzgx_offset_0[];
extern u8 lbl_1_data_21660__fzgx_offset_0[];
extern u8 lbl_1_data_216A8__fzgx_offset_0[];
extern u8 lbl_1_data_216C0__fzgx_offset_0[];
extern u8 lbl_1_data_216D0__fzgx_offset_0[];
extern u8 lbl_1_data_216E4__fzgx_offset_0[];
extern u8 lbl_1_data_216F8__fzgx_offset_0[];
extern u8 lbl_1_data_21700__fzgx_offset_0[];
extern u8 lbl_1_data_21728__fzgx_offset_0[];
extern u8 lbl_1_data_2174C__fzgx_offset_0[];
extern u8 lbl_1_data_2175C__fzgx_offset_0[];
extern u8 lbl_1_data_2176C__fzgx_offset_0[];
extern u8 lbl_1_data_2177C__fzgx_offset_0[];
extern u8 lbl_1_data_2178C__fzgx_offset_0[];
extern u8 lbl_1_data_21798__fzgx_offset_0[];
extern u8 lbl_1_data_217C0__fzgx_offset_0[];
extern u8 lbl_1_data_217E8__fzgx_offset_0[];
extern u8 lbl_1_data_217F8__fzgx_offset_0[];
extern u8 lbl_1_data_217FC__fzgx_offset_0[];
extern u8 lbl_1_data_21810__fzgx_offset_0[];
extern u8 lbl_1_data_21824__fzgx_offset_0[];
extern u8 lbl_1_data_21830__fzgx_offset_0[];
extern u8 lbl_1_data_21860__fzgx_offset_0[];
extern u8 lbl_1_data_21878__fzgx_offset_0[];
extern u8 lbl_1_data_21888__fzgx_offset_0[];
extern u8 lbl_1_data_2189C__fzgx_offset_0[];
extern u8 lbl_1_data_218B0__fzgx_offset_0[];
extern u8 lbl_1_data_218B8__fzgx_offset_0[];
extern u8 lbl_1_data_218D8__fzgx_offset_0[];
extern u8 lbl_1_data_21900__fzgx_offset_0[];
extern u8 lbl_1_data_21910__fzgx_offset_0[];
extern u8 lbl_1_data_21914__fzgx_offset_0[];
extern u8 lbl_1_data_21924__fzgx_offset_0[];
extern u8 lbl_1_data_21934__fzgx_offset_0[];
extern u8 lbl_1_data_2193C__fzgx_offset_0[];
extern u8 lbl_1_data_21964__fzgx_offset_0[];
extern u8 lbl_1_data_21980__fzgx_offset_0[];
extern u8 lbl_1_data_21990__fzgx_offset_0[];
extern u8 lbl_1_data_219A4__fzgx_offset_0[];
extern u8 lbl_1_data_219B8__fzgx_offset_0[];
extern u8 lbl_1_data_219C0__fzgx_offset_0[];
extern u8 lbl_1_data_219E8__fzgx_offset_0[];
extern u8 lbl_1_data_21A04__fzgx_offset_0[];
extern u8 lbl_1_data_21A14__fzgx_offset_0[];
extern u8 lbl_1_data_21A24__fzgx_offset_0[];
extern u8 lbl_1_data_21A34__fzgx_offset_0[];
extern u8 lbl_1_data_21A3C__fzgx_offset_0[];
extern u8 lbl_1_data_21A64__fzgx_offset_0[];
extern u8 lbl_1_data_21A80__fzgx_offset_0[];
extern u8 lbl_1_data_21A90__fzgx_offset_0[];
extern u8 lbl_1_data_21AA0__fzgx_offset_0[];
extern u8 lbl_1_data_21AB0__fzgx_offset_0[];
extern u8 lbl_1_data_21AB8__fzgx_offset_0[];
extern u8 lbl_1_data_21AD8__fzgx_offset_0[];
extern u8 lbl_1_data_21ADC__fzgx_offset_0[];
extern u8 lbl_1_data_21AEC__fzgx_offset_0[];
extern u8 lbl_1_data_21AFC__fzgx_offset_0[];
extern u8 lbl_1_data_21B0C__fzgx_offset_0[];
extern u8 lbl_1_data_21B14__fzgx_offset_0[];
extern u8 lbl_1_data_21B3C__fzgx_offset_0[];
extern u8 lbl_1_data_21B60__fzgx_offset_0[];
extern u8 lbl_1_data_21B70__fzgx_offset_0[];
extern u8 lbl_1_data_21B80__fzgx_offset_0[];
extern u8 lbl_1_data_21B90__fzgx_offset_0[];
extern u8 lbl_1_data_21BA0__fzgx_offset_0[];
extern u8 lbl_1_data_21BAC__fzgx_offset_0[];
extern u8 lbl_1_data_21BD4__fzgx_offset_0[];
extern u8 lbl_1_data_21BF0__fzgx_offset_0[];
extern u8 lbl_1_data_21C00__fzgx_offset_0[];
extern u8 lbl_1_data_21C10__fzgx_offset_0[];
extern u8 lbl_1_data_21C20__fzgx_offset_0[];
extern u8 lbl_1_data_21C30__fzgx_offset_0[];
extern u8 lbl_1_data_21C38__fzgx_offset_0[];
extern u8 lbl_1_data_21C60__fzgx_offset_0[];
extern u8 lbl_1_data_21C7C__fzgx_offset_0[];
extern u8 lbl_1_data_21C8C__fzgx_offset_0[];
extern u8 lbl_1_data_21C9C__fzgx_offset_0[];
extern u8 lbl_1_data_21CAC__fzgx_offset_0[];
extern u8 lbl_1_data_21CB4__fzgx_offset_0[];
extern u8 lbl_1_data_21CDC__fzgx_offset_0[];
extern u8 lbl_1_data_21CF4__fzgx_offset_0[];
extern u8 lbl_1_data_21D08__fzgx_offset_0[];
extern u8 lbl_1_data_21D18__fzgx_offset_0[];
extern u8 lbl_1_data_21D28__fzgx_offset_0[];
extern u8 lbl_1_data_21D30__fzgx_offset_0[];
extern u8 lbl_1_data_21D58__fzgx_offset_0[];
extern u8 lbl_1_data_21D70__fzgx_offset_0[];
extern u8 lbl_1_data_21D80__fzgx_offset_0[];
extern u8 lbl_1_data_21D90__fzgx_offset_0[];
extern u8 lbl_1_data_21DA0__fzgx_offset_0[];
extern u8 lbl_1_data_21DA8__fzgx_offset_0[];
extern u8 lbl_1_data_21DBC__fzgx_offset_0[];
extern u8 lbl_1_data_21DD0__fzgx_offset_0[];
extern u8 lbl_1_data_21DE0__fzgx_offset_0[];
extern u8 lbl_1_data_21DF0__fzgx_offset_0[];
extern u8 lbl_1_data_21E00__fzgx_offset_0[];
extern u8 lbl_1_data_21E08__fzgx_offset_0[];
extern u8 lbl_1_data_21E30__fzgx_offset_0[];
extern u8 lbl_1_data_21E54__fzgx_offset_0[];
extern u8 lbl_1_data_21E64__fzgx_offset_0[];
extern u8 lbl_1_data_21E74__fzgx_offset_0[];
extern u8 lbl_1_data_21E84__fzgx_offset_0[];
extern u8 lbl_1_data_21E8C__fzgx_offset_0[];
extern u8 lbl_1_data_21EB4__fzgx_offset_0[];
extern u8 lbl_1_data_21ECC__fzgx_offset_0[];
extern u8 lbl_1_data_21EDC__fzgx_offset_0[];
extern u8 lbl_1_data_21EEC__fzgx_offset_0[];
extern u8 lbl_1_data_21EFC__fzgx_offset_0[];
extern u8 lbl_1_data_21F04__fzgx_offset_0[];
extern u8 lbl_1_data_21F2C__fzgx_offset_0[];
extern u8 lbl_1_data_21F50__fzgx_offset_0[];
extern u8 lbl_1_data_21F60__fzgx_offset_0[];
extern u8 lbl_1_data_21F70__fzgx_offset_0[];
extern u8 lbl_1_data_21F80__fzgx_offset_0[];
extern u8 lbl_1_data_21F88__fzgx_offset_0[];
extern u8 lbl_1_data_21FB0__fzgx_offset_0[];
extern u8 lbl_1_data_21FD4__fzgx_offset_0[];
extern u8 lbl_1_data_21FE4__fzgx_offset_0[];
extern u8 lbl_1_data_21FF4__fzgx_offset_0[];
extern u8 lbl_1_data_22004__fzgx_offset_0[];
extern u8 lbl_1_data_2200C__fzgx_offset_0[];
extern u8 lbl_1_data_2203C__fzgx_offset_0[];
extern u8 lbl_1_data_22058__fzgx_offset_0[];
extern u8 lbl_1_data_22068__fzgx_offset_0[];
extern u8 lbl_1_data_2207C__fzgx_offset_0[];
extern u8 lbl_1_data_22090__fzgx_offset_0[];
extern u8 lbl_1_data_22098__fzgx_offset_0[];
extern u8 lbl_1_data_220C0__fzgx_offset_0[];
extern u8 lbl_1_data_220E8__fzgx_offset_0[];
extern u8 lbl_1_data_220F8__fzgx_offset_0[];
extern u8 lbl_1_data_22108__fzgx_offset_0[];
extern u8 lbl_1_data_22118__fzgx_offset_0[];
extern u8 lbl_1_data_22120__fzgx_offset_0[];
extern u8 lbl_1_data_22148__fzgx_offset_0[];
extern u8 lbl_1_data_22160__fzgx_offset_0[];
extern u8 lbl_1_data_22170__fzgx_offset_0[];
extern u8 lbl_1_data_22180__fzgx_offset_0[];
extern u8 lbl_1_data_22190__fzgx_offset_0[];
extern u8 lbl_1_data_22198__fzgx_offset_0[];
extern u8 lbl_1_data_221C0__fzgx_offset_0[];
extern u8 lbl_1_data_221E4__fzgx_offset_0[];
extern u8 lbl_1_data_221F4__fzgx_offset_0[];
extern u8 lbl_1_data_22204__fzgx_offset_0[];
extern u8 lbl_1_data_22214__fzgx_offset_0[];
extern u8 lbl_1_data_2221C__fzgx_offset_0[];
extern u8 lbl_1_data_22244__fzgx_offset_0[];
extern u8 lbl_1_data_22264__fzgx_offset_0[];
extern u8 lbl_1_data_22274__fzgx_offset_0[];
extern u8 lbl_1_data_22278__fzgx_offset_0[];
extern u8 lbl_1_data_22288__fzgx_offset_0[];
extern u8 lbl_1_data_22298__fzgx_offset_0[];
extern u8 lbl_1_data_222A0__fzgx_offset_0[];
extern u8 lbl_1_data_222D8__fzgx_offset_0[];
extern u8 lbl_1_data_222F4__fzgx_offset_0[];
extern u8 lbl_1_data_22310__fzgx_offset_0[];
extern u8 lbl_1_data_2232C__fzgx_offset_0[];
extern u8 lbl_1_data_22334__fzgx_offset_0[];
extern u8 lbl_1_data_2235C__fzgx_offset_0[];
extern u8 lbl_1_data_22360__fzgx_offset_0[];
extern u8 lbl_1_data_22374__fzgx_offset_0[];
extern u8 lbl_1_data_22384__fzgx_offset_0[];
extern u8 lbl_1_data_22394__fzgx_offset_0[];
extern u8 lbl_1_data_223A0__fzgx_offset_0[];
extern u8 lbl_1_data_223B4__fzgx_offset_0[];
extern u8 lbl_1_data_223CC__fzgx_offset_0[];
extern u8 lbl_1_data_223D0__fzgx_offset_0[];
extern u8 lbl_1_data_223DC__fzgx_offset_0[];
extern u8 lbl_1_data_223EC__fzgx_offset_0[];
extern u8 lbl_1_data_223FC__fzgx_offset_0[];
extern u8 lbl_1_data_22404__fzgx_offset_0[];
extern u8 lbl_1_data_2242C__fzgx_offset_0[];
extern u8 lbl_1_data_22454__fzgx_offset_0[];
extern u8 lbl_1_data_22464__fzgx_offset_0[];
extern u8 lbl_1_data_22474__fzgx_offset_0[];
extern u8 lbl_1_data_22484__fzgx_offset_0[];
extern u8 lbl_1_data_2248C__fzgx_offset_0[];
extern u8 lbl_1_data_224AC__fzgx_offset_0[];
extern u8 lbl_1_data_224B4__fzgx_offset_0[];
extern u8 lbl_1_data_224B8__fzgx_offset_0[];
extern u8 lbl_1_data_224C8__fzgx_offset_0[];
extern u8 lbl_1_data_224D8__fzgx_offset_0[];
extern u8 lbl_1_data_224E4__fzgx_offset_0[];
extern u8 lbl_1_data_22514__fzgx_offset_0[];
extern u8 lbl_1_data_22520__fzgx_offset_0[];
extern u8 lbl_1_data_22528__fzgx_offset_0[];
extern u8 lbl_1_data_2253C__fzgx_offset_0[];
extern u8 lbl_1_data_22550__fzgx_offset_0[];
extern u8 lbl_1_data_2255C__fzgx_offset_0[];
extern u8 lbl_1_data_22584__fzgx_offset_0[];
extern u8 lbl_1_data_225AC__fzgx_offset_0[];
extern u8 lbl_1_data_225BC__fzgx_offset_0[];
extern u8 lbl_1_data_225CC__fzgx_offset_0[];
extern u8 lbl_1_data_225DC__fzgx_offset_0[];
extern u8 lbl_1_data_225E4__fzgx_offset_0[];
extern u8 lbl_1_data_2260C__fzgx_offset_0[];
extern u8 lbl_1_data_22630__fzgx_offset_0[];
extern u8 lbl_1_data_22640__fzgx_offset_0[];
extern u8 lbl_1_data_22650__fzgx_offset_0[];
extern u8 lbl_1_data_22660__fzgx_offset_0[];
extern u8 lbl_1_data_22670__fzgx_offset_0[];
extern u8 lbl_1_data_2267C__fzgx_offset_0[];
extern u8 lbl_1_data_226A4__fzgx_offset_0[];
extern u8 lbl_1_data_226C0__fzgx_offset_0[];
extern u8 lbl_1_data_226D4__fzgx_offset_0[];
extern u8 lbl_1_data_226E4__fzgx_offset_0[];
extern u8 lbl_1_data_226F4__fzgx_offset_0[];
extern u8 lbl_1_data_226FC__fzgx_offset_0[];
extern u8 lbl_1_data_22724__fzgx_offset_0[];
extern u8 lbl_1_data_22744__fzgx_offset_0[];
extern u8 lbl_1_data_22754__fzgx_offset_0[];
extern u8 lbl_1_data_22764__fzgx_offset_0[];
extern u8 lbl_1_data_22774__fzgx_offset_0[];
extern u8 lbl_1_data_2277C__fzgx_offset_0[];
extern u8 lbl_1_data_227A4__fzgx_offset_0[];
extern u8 lbl_1_data_227C0__fzgx_offset_0[];
extern u8 lbl_1_data_227D0__fzgx_offset_0[];
extern u8 lbl_1_data_227E0__fzgx_offset_0[];
extern u8 lbl_1_data_227F0__fzgx_offset_0[];
extern u8 lbl_1_data_22800__fzgx_offset_0[];
extern u8 lbl_1_data_22808__fzgx_offset_0[];
extern u8 lbl_1_data_2281C__fzgx_offset_0[];
extern u8 lbl_1_data_22834__fzgx_offset_0[];
extern u8 lbl_1_data_2284C__fzgx_offset_0[];
extern u8 lbl_1_data_2285C__fzgx_offset_0[];
extern u8 lbl_1_data_2286C__fzgx_offset_0[];
extern u8 lbl_1_data_2287C__fzgx_offset_0[];
extern u8 lbl_1_data_22884__fzgx_offset_0[];
extern u8 lbl_1_data_228AC__fzgx_offset_0[];
extern u8 lbl_1_data_228CC__fzgx_offset_0[];
extern u8 lbl_1_data_228DC__fzgx_offset_0[];
extern u8 lbl_1_data_228EC__fzgx_offset_0[];
extern u8 lbl_1_data_228FC__fzgx_offset_0[];
extern u8 lbl_1_data_22904__fzgx_offset_0[];
extern u8 lbl_1_data_2292C__fzgx_offset_0[];
extern u8 lbl_1_data_2294C__fzgx_offset_0[];
extern u8 lbl_1_data_2295C__fzgx_offset_0[];
extern u8 lbl_1_data_22964__fzgx_offset_0[];
extern u8 lbl_1_data_22974__fzgx_offset_0[];
extern u8 lbl_1_data_22984__fzgx_offset_0[];
extern u8 lbl_1_data_2298C__fzgx_offset_0[];
extern u8 lbl_1_data_229B4__fzgx_offset_0[];
extern u8 lbl_1_data_229D8__fzgx_offset_0[];
extern u8 lbl_1_data_229E8__fzgx_offset_0[];
extern u8 lbl_1_data_229F8__fzgx_offset_0[];
extern u8 lbl_1_data_22A08__fzgx_offset_0[];
extern u8 lbl_1_data_22A10__fzgx_offset_0[];
extern u8 lbl_1_data_22A14__fzgx_offset_0[];
extern u8 lbl_1_data_22A18__fzgx_offset_0[];
extern u8 lbl_1_data_22A1C__fzgx_offset_0[];
extern u8 lbl_1_data_22A24__fzgx_offset_0[];
extern u8 lbl_1_data_22A2C__fzgx_offset_0[];
extern u8 lbl_1_data_22A34__fzgx_offset_0[];
extern u8 lbl_1_data_22A3C__fzgx_offset_0[];
extern u8 lbl_1_data_22A44__fzgx_offset_0[];
extern u8 lbl_1_data_22A4C__fzgx_offset_0[];
extern u8 lbl_1_data_22B24__fzgx_offset_0[];
extern u8 lbl_1_data_22BD8__fzgx_offset_0[];
extern u8 lbl_1_data_22C8C__fzgx_offset_0[];
extern u8 lbl_1_data_22D40__fzgx_offset_0[];
extern u8 lbl_1_data_22DF4__fzgx_offset_0[];
extern u8 lbl_1_data_22E00__fzgx_offset_0[];
extern u8 lbl_1_data_22E0C__fzgx_offset_0[];
extern u8 lbl_1_data_22F08__fzgx_offset_0[];
extern u8 lbl_1_data_22FBC__fzgx_offset_0[];
extern u8 lbl_1_data_23028__fzgx_offset_0[];
extern u8 lbl_1_data_230DC__fzgx_offset_0[];
extern u8 lbl_1_data_23190__fzgx_offset_0[];
extern u8 lbl_1_data_23198__fzgx_offset_0[];
extern u8 lbl_1_data_23270__fzgx_offset_0[];
extern u8 lbl_1_data_23324__fzgx_offset_0[];
extern u8 lbl_1_data_23420__fzgx_offset_0[];
extern u8 lbl_1_data_23428__fzgx_offset_0[];
extern u8 lbl_1_data_23500__fzgx_offset_0[];
extern u8 lbl_1_data_235FC__fzgx_offset_0[];
extern u8 lbl_1_data_236B0__fzgx_offset_0[];
extern u8 lbl_1_data_236B8__fzgx_offset_0[];
extern u8 lbl_1_data_23790__fzgx_offset_0[];
extern u8 lbl_1_data_23844__fzgx_offset_0[];
extern u8 lbl_1_data_238F8__fzgx_offset_0[];
extern u8 lbl_1_data_239AC__fzgx_offset_0[];
extern u8 lbl_1_data_23A60__fzgx_offset_0[];
extern u8 lbl_1_data_23B14__fzgx_offset_0[];
extern u8 lbl_1_data_23BC8__fzgx_offset_0[];
extern u8 lbl_1_data_23C7C__fzgx_offset_0[];
extern u8 lbl_1_data_23D30__fzgx_offset_0[];
extern u8 lbl_1_data_23DE4__fzgx_offset_0[];
extern u8 lbl_1_data_23E98__fzgx_offset_0[];
extern u8 lbl_1_data_23F4C__fzgx_offset_0[];
extern u8 lbl_1_data_24000__fzgx_offset_0[];
extern u8 lbl_1_data_240B4__fzgx_offset_0[];
extern u8 lbl_1_data_24168__fzgx_offset_0[];
extern u8 lbl_1_data_2421C__fzgx_offset_0[];
extern u8 lbl_1_data_24318__fzgx_offset_0[];
extern u8 lbl_1_data_24320__fzgx_offset_0[];
extern u8 lbl_1_data_243F8__fzgx_offset_0[];
extern u8 lbl_1_data_244AC__fzgx_offset_0[];
extern u8 lbl_1_data_24560__fzgx_offset_0[];
extern u8 lbl_1_data_24638__fzgx_offset_0[];
extern u8 lbl_1_data_2463C__fzgx_offset_0[];
extern u8 lbl_1_data_24714__fzgx_offset_0[];
extern u8 lbl_1_data_247C8__fzgx_offset_0[];
extern u8 lbl_1_data_2487C__fzgx_offset_0[];
extern u8 lbl_1_data_24930__fzgx_offset_0[];
extern u8 lbl_1_data_249E4__fzgx_offset_0[];
extern u8 lbl_1_data_249F4__fzgx_offset_0[];
extern u8 lbl_1_data_24A04__fzgx_offset_0[];
extern u8 lbl_1_data_24A14__fzgx_offset_0[];
extern u8 lbl_1_data_24A24__fzgx_offset_0[];
extern u8 lbl_1_data_24A30__fzgx_offset_0[];
extern u8 lbl_1_data_24A3C__fzgx_offset_0[];
extern u8 lbl_1_data_24A48__fzgx_offset_0[];
extern u8 lbl_1_data_24A54__fzgx_offset_0[];
extern u8 lbl_1_data_24A5C__fzgx_offset_0[];
extern u8 lbl_1_data_24A64__fzgx_offset_0[];
extern u8 lbl_1_data_24A6C__fzgx_offset_0[];
extern u8 lbl_1_data_24A74__fzgx_offset_0[];
extern u8 lbl_1_data_24A7C__fzgx_offset_0[];
extern u8 lbl_1_data_24A84__fzgx_offset_0[];
extern u8 lbl_1_data_24A8C__fzgx_offset_0[];
extern u8 lbl_1_data_24A94__fzgx_offset_0[];
extern u8 lbl_1_data_24D88__fzgx_offset_0[];
extern u8 lbl_1_data_24E3C__fzgx_offset_0[];
extern u8 lbl_1_data_24EF0__fzgx_offset_0[];
extern u8 lbl_1_data_24EF8__fzgx_offset_0[];
extern u8 lbl_1_data_24F1C__fzgx_offset_0[];
extern u8 lbl_1_data_24F40__fzgx_offset_0[];
extern u8 lbl_1_data_24F64__fzgx_offset_0[];
extern u8 lbl_1_data_24F88__fzgx_offset_0[];
extern u8 lbl_1_data_24FAC__fzgx_offset_0[];
extern u8 lbl_1_data_24FD0__fzgx_offset_0[];
extern u8 lbl_1_data_24FF4__fzgx_offset_0[];
extern u8 lbl_1_data_25018__fzgx_offset_0[];
extern u8 lbl_1_data_2503C__fzgx_offset_0[];
extern u8 lbl_1_data_25060__fzgx_offset_0[];
extern u8 lbl_1_data_250A8__fzgx_offset_0[];
extern u8 lbl_1_data_250CC__fzgx_offset_0[];
extern u8 lbl_1_data_250F0__fzgx_offset_0[];
extern u8 lbl_1_data_25138__fzgx_offset_0[];
extern u8 lbl_1_data_2515C__fzgx_offset_0[];
extern u8 lbl_1_data_25180__fzgx_offset_0[];
extern u8 lbl_1_data_251A4__fzgx_offset_0[];
extern u8 lbl_1_data_251EC__fzgx_offset_0[];
extern u8 lbl_1_data_25210__fzgx_offset_0[];
extern u8 lbl_1_data_25234__fzgx_offset_0[];
extern u8 lbl_1_data_25258__fzgx_offset_0[];
extern u8 lbl_1_data_2527C__fzgx_offset_0[];
extern u8 lbl_1_data_252A0__fzgx_offset_0[];
extern u8 lbl_1_data_252C4__fzgx_offset_0[];
extern u8 lbl_1_data_252E8__fzgx_offset_0[];
extern u8 lbl_1_data_25354__fzgx_offset_0[];
extern u8 lbl_1_data_253C0__fzgx_offset_0[];
extern u8 lbl_1_data_253E4__fzgx_offset_0[];
extern u8 lbl_1_data_25408__fzgx_offset_0[];
extern u8 lbl_1_data_2542C__fzgx_offset_0[];
extern u8 lbl_1_data_25450__fzgx_offset_0[];
extern u8 lbl_1_data_25474__fzgx_offset_0[];
extern u8 lbl_1_data_25498__fzgx_offset_0[];
extern u8 lbl_1_data_254E0__fzgx_offset_0[];
extern u8 lbl_1_data_25504__fzgx_offset_0[];
extern u8 lbl_1_data_25528__fzgx_offset_0[];
extern u8 lbl_1_data_25570__fzgx_offset_0[];
extern u8 lbl_1_data_255B8__fzgx_offset_0[];
extern u8 lbl_1_data_25624__fzgx_offset_0[];
extern u8 lbl_1_data_25690__fzgx_offset_0[];
extern u8 lbl_1_data_256FC__fzgx_offset_0[];
extern u8 lbl_1_data_25720__fzgx_offset_0[];
extern u8 lbl_1_data_25984__fzgx_offset_0[];
extern u8 lbl_1_data_259A8__fzgx_offset_0[];
extern u8 lbl_1_data_259CC__fzgx_offset_0[];
extern u8 lbl_1_data_259F0__fzgx_offset_0[];
extern u8 lbl_1_data_25A14__fzgx_offset_0[];
extern u8 lbl_1_data_25A38__fzgx_offset_0[];
extern u8 lbl_1_data_25A5C__fzgx_offset_0[];
extern u8 lbl_1_data_25A80__fzgx_offset_0[];
extern u8 lbl_1_data_25AA4__fzgx_offset_0[];
extern u8 lbl_1_data_25AC8__fzgx_offset_0[];
extern u8 lbl_1_data_25AEC__fzgx_offset_0[];
extern u8 lbl_1_data_25B10__fzgx_offset_0[];
extern u8 lbl_1_data_25B34__fzgx_offset_0[];
extern u8 lbl_1_data_25B58__fzgx_offset_0[];
extern u8 lbl_1_data_25B7C__fzgx_offset_0[];
extern u8 lbl_1_data_25BA0__fzgx_offset_0[];
extern u8 lbl_1_data_25BC4__fzgx_offset_0[];
extern u8 lbl_1_data_25BE8__fzgx_offset_0[];
extern u8 lbl_1_data_25C0C__fzgx_offset_0[];
extern u8 lbl_1_data_25C30__fzgx_offset_0[];
extern u8 lbl_1_data_25C54__fzgx_offset_0[];
extern u8 lbl_1_data_25C78__fzgx_offset_0[];
extern u8 lbl_1_data_25C9C__fzgx_offset_0[];
extern u8 lbl_1_data_25CC0__fzgx_offset_0[];
extern u8 lbl_1_data_25CE4__fzgx_offset_0[];
extern u8 lbl_1_data_25D08__fzgx_offset_0[];
extern u8 lbl_1_data_25D2C__fzgx_offset_0[];
extern u8 lbl_1_data_25D50__fzgx_offset_0[];
extern u8 lbl_1_data_25D74__fzgx_offset_0[];
extern u8 lbl_1_data_25D98__fzgx_offset_0[];
extern u8 lbl_1_data_25DBC__fzgx_offset_0[];
extern u8 lbl_1_data_25DE0__fzgx_offset_0[];
extern u8 lbl_1_data_25E04__fzgx_offset_0[];
extern u8 lbl_1_data_25E28__fzgx_offset_0[];
extern u8 lbl_1_data_25E4C__fzgx_offset_0[];
extern u8 lbl_1_data_25E70__fzgx_offset_0[];
extern u8 lbl_1_data_25E94__fzgx_offset_0[];
extern u8 lbl_1_data_25EB8__fzgx_offset_0[];
extern u8 lbl_1_data_25EDC__fzgx_offset_0[];
extern u8 lbl_1_data_25F00__fzgx_offset_0[];
extern u8 lbl_1_data_25F24__fzgx_offset_0[];
extern u8 lbl_1_data_25F48__fzgx_offset_0[];
extern u8 lbl_1_data_25F6C__fzgx_offset_0[];
extern u8 lbl_1_data_25F90__fzgx_offset_0[];
extern u8 lbl_1_data_25FB4__fzgx_offset_0[];
extern u8 lbl_1_data_25FD8__fzgx_offset_0[];
extern u8 lbl_1_data_25FFC__fzgx_offset_0[];
extern u8 lbl_1_data_26020__fzgx_offset_0[];
extern u8 lbl_1_data_26044__fzgx_offset_0[];
extern u8 lbl_1_data_26068__fzgx_offset_0[];
extern u8 lbl_1_data_2608C__fzgx_offset_0[];
extern u8 lbl_1_data_260B0__fzgx_offset_0[];
extern u8 lbl_1_data_260D4__fzgx_offset_0[];
extern u8 lbl_1_data_260F8__fzgx_offset_0[];
extern u8 lbl_1_data_2611C__fzgx_offset_0[];
extern u8 lbl_1_data_26140__fzgx_offset_0[];
extern u8 lbl_1_data_26164__fzgx_offset_0[];
extern u8 lbl_1_data_26188__fzgx_offset_0[];
extern u8 lbl_1_data_261AC__fzgx_offset_0[];
extern u8 lbl_1_data_261D0__fzgx_offset_0[];
extern u8 lbl_1_data_261F4__fzgx_offset_0[];
extern u8 lbl_1_data_26218__fzgx_offset_0[];
extern u8 lbl_1_data_2623C__fzgx_offset_0[];
extern u8 lbl_1_data_26260__fzgx_offset_0[];
extern u8 lbl_1_data_26284__fzgx_offset_0[];
extern u8 lbl_1_data_262A8__fzgx_offset_0[];
extern u8 lbl_1_data_262CC__fzgx_offset_0[];
extern u8 lbl_1_data_262F0__fzgx_offset_0[];
extern u8 lbl_1_data_26314__fzgx_offset_0[];
extern u8 lbl_1_data_26338__fzgx_offset_0[];
extern u8 lbl_1_data_2635C__fzgx_offset_0[];
extern u8 lbl_1_data_26380__fzgx_offset_0[];
extern u8 lbl_1_data_263A4__fzgx_offset_0[];
extern u8 lbl_1_data_263C8__fzgx_offset_0[];
extern u8 lbl_1_data_263EC__fzgx_offset_0[];
extern u8 lbl_1_data_26410__fzgx_offset_0[];
extern u8 lbl_1_data_26434__fzgx_offset_0[];
extern u8 lbl_1_data_26458__fzgx_offset_0[];
extern u8 lbl_1_data_2647C__fzgx_offset_0[];
extern u8 lbl_1_data_264A0__fzgx_offset_0[];
extern u8 lbl_1_data_264C4__fzgx_offset_0[];
extern u8 lbl_1_data_264E8__fzgx_offset_0[];
extern u8 lbl_1_data_2650C__fzgx_offset_0[];
extern u8 lbl_1_data_26530__fzgx_offset_0[];
extern u8 lbl_1_data_26554__fzgx_offset_0[];
extern u8 lbl_1_data_26578__fzgx_offset_0[];
extern u8 lbl_1_data_2659C__fzgx_offset_0[];
extern u8 lbl_1_data_265C0__fzgx_offset_0[];
extern u8 lbl_1_data_265E4__fzgx_offset_0[];
extern u8 lbl_1_data_26608__fzgx_offset_0[];
extern u8 lbl_1_data_2662C__fzgx_offset_0[];
extern u8 lbl_1_data_26650__fzgx_offset_0[];
extern u8 lbl_1_data_26D8C__fzgx_offset_0[];
extern u8 lbl_1_data_26D94__fzgx_offset_0[];
extern u8 lbl_1_data_26D9C__fzgx_offset_0[];
extern u8 lbl_1_data_26DA4__fzgx_offset_0[];
extern u8 lbl_1_data_26DAC__fzgx_offset_0[];
extern u8 lbl_1_data_26DB4__fzgx_offset_0[];
extern u8 lbl_1_data_26DDC__fzgx_offset_0[];
extern u8 lbl_1_data_26DE4__fzgx_offset_0[];
extern u8 lbl_1_data_26DEC__fzgx_offset_0[];
extern u8 lbl_1_data_26DF4__fzgx_offset_0[];
extern u8 lbl_1_data_26E00__fzgx_offset_0[];
extern u8 lbl_1_data_26E0C__fzgx_offset_0[];
extern u8 lbl_1_data_26E14__fzgx_offset_0[];
extern u8 lbl_1_data_26E1C__fzgx_offset_0[];
extern u8 lbl_1_data_26E24__fzgx_offset_0[];
extern u8 lbl_1_data_26E2C__fzgx_offset_0[];
extern u8 lbl_1_data_26E34__fzgx_offset_0[];
extern u8 lbl_1_data_26E3C__fzgx_offset_0[];
extern u8 lbl_1_data_26E44__fzgx_offset_0[];
extern u8 lbl_1_data_26E4C__fzgx_offset_0[];
extern u8 lbl_1_data_26E54__fzgx_offset_0[];
extern u8 lbl_1_data_26E5C__fzgx_offset_0[];
extern u8 lbl_1_data_26E64__fzgx_offset_0[];
extern u8 lbl_1_data_26E6C__fzgx_offset_0[];
extern u8 lbl_1_data_26E74__fzgx_offset_0[];
extern u8 lbl_1_data_26E7C__fzgx_offset_0[];
extern u8 lbl_1_data_26E84__fzgx_offset_0[];
extern u8 lbl_1_data_26E8C__fzgx_offset_0[];
extern u8 lbl_1_data_26E94__fzgx_offset_0[];
extern u8 lbl_1_data_26E9C__fzgx_offset_0[];
extern u8 lbl_1_data_26EA4__fzgx_offset_0[];
extern u8 lbl_1_data_26EB0__fzgx_offset_0[];
extern u8 lbl_1_data_26EBC__fzgx_offset_0[];
extern u8 lbl_1_data_26EC8__fzgx_offset_0[];
extern u8 lbl_1_data_26ED4__fzgx_offset_0[];
extern u8 lbl_1_data_26EE0__fzgx_offset_0[];
extern u8 lbl_1_data_26EEC__fzgx_offset_0[];
extern u8 lbl_1_data_26EF8__fzgx_offset_0[];
extern u8 lbl_1_data_26F04__fzgx_offset_0[];
extern u8 lbl_1_data_26F10__fzgx_offset_0[];
extern u8 lbl_1_data_26F1C__fzgx_offset_0[];
extern u8 lbl_1_data_26F28__fzgx_offset_0[];
extern u8 lbl_1_data_26F34__fzgx_offset_0[];
extern u8 lbl_1_data_26F40__fzgx_offset_0[];
extern u8 lbl_1_data_26F4C__fzgx_offset_0[];
extern u8 lbl_1_data_26F58__fzgx_offset_0[];
extern u8 lbl_1_data_26F64__fzgx_offset_0[];
extern u8 lbl_1_data_26F70__fzgx_offset_0[];
extern u8 lbl_1_data_26F7C__fzgx_offset_0[];
extern u8 lbl_1_data_26F88__fzgx_offset_0[];
extern u8 lbl_1_data_27048__fzgx_offset_0[];
extern u8 lbl_1_data_27058__fzgx_offset_0[];
extern u8 lbl_1_data_27060__fzgx_offset_0[];
extern u8 lbl_1_data_2706C__fzgx_offset_0[];
extern u8 lbl_1_data_2707C__fzgx_offset_0[];
extern u8 lbl_1_data_27088__fzgx_offset_0[];
extern u8 lbl_1_data_27094__fzgx_offset_0[];
extern u8 lbl_1_data_270A0__fzgx_offset_0[];
extern u8 lbl_1_data_270B0__fzgx_offset_0[];
extern u8 lbl_1_data_270C0__fzgx_offset_0[];
extern u8 lbl_1_data_270CC__fzgx_offset_0[];
extern u8 lbl_1_data_270D8__fzgx_offset_0[];
extern u8 lbl_1_data_270E4__fzgx_offset_0[];
extern u8 lbl_1_data_270F0__fzgx_offset_0[];
extern u8 lbl_1_data_270FC__fzgx_offset_0[];
extern u8 lbl_1_data_27108__fzgx_offset_0[];
extern u8 lbl_1_data_27114__fzgx_offset_0[];
extern u8 lbl_1_data_27124__fzgx_offset_0[];
extern u8 lbl_1_data_27134__fzgx_offset_0[];
extern u8 lbl_1_data_27144__fzgx_offset_0[];
extern u8 lbl_1_data_27150__fzgx_offset_0[];
extern u8 lbl_1_data_2715C__fzgx_offset_0[];
extern u8 lbl_1_data_27168__fzgx_offset_0[];
extern u8 lbl_1_data_27174__fzgx_offset_0[];
extern u8 lbl_1_data_27184__fzgx_offset_0[];
extern u8 lbl_1_data_27194__fzgx_offset_0[];
extern u8 lbl_1_data_271A0__fzgx_offset_0[];
extern u8 lbl_1_data_271B0__fzgx_offset_0[];
extern u8 lbl_1_data_271BC__fzgx_offset_0[];
extern u8 lbl_1_data_271C8__fzgx_offset_0[];
extern u8 lbl_1_data_271D4__fzgx_offset_0[];
extern u8 lbl_1_data_271E4__fzgx_offset_0[];
extern u8 lbl_1_data_271F0__fzgx_offset_0[];
extern u8 lbl_1_data_271FC__fzgx_offset_0[];
extern u8 lbl_1_data_2720C__fzgx_offset_0[];
extern u8 lbl_1_data_27218__fzgx_offset_0[];
extern u8 lbl_1_data_27224__fzgx_offset_0[];
extern u8 lbl_1_data_27234__fzgx_offset_0[];
extern u8 lbl_1_data_27244__fzgx_offset_0[];
extern u8 lbl_1_data_27250__fzgx_offset_0[];
extern u8 lbl_1_data_2725C__fzgx_offset_0[];
extern u8 lbl_1_data_27268__fzgx_offset_0[];
extern u8 lbl_1_data_27278__fzgx_offset_0[];
extern u8 lbl_1_data_27284__fzgx_offset_0[];
extern u8 lbl_1_data_27290__fzgx_offset_0[];
extern u8 lbl_1_data_2729C__fzgx_offset_0[];
extern u8 lbl_1_data_272A8__fzgx_offset_0[];
extern u8 lbl_1_data_272B0__fzgx_offset_0[];
extern u8 lbl_1_data_272BC__fzgx_offset_0[];
extern u8 lbl_1_data_272C0__fzgx_offset_0[];
extern u8 lbl_1_data_272D0__fzgx_offset_0[];
extern u8 lbl_1_data_272D4__fzgx_offset_0[];
extern u8 lbl_1_data_272E4__fzgx_offset_0[];
extern u8 lbl_1_data_272EC__fzgx_offset_0[];
extern u8 lbl_1_data_272F8__fzgx_offset_0[];
extern u8 lbl_1_data_27300__fzgx_offset_0[];
extern u8 lbl_1_data_27304__fzgx_offset_0[];
extern u8 lbl_1_data_27318__fzgx_offset_0[];
extern u8 lbl_1_data_27324__fzgx_offset_0[];
extern u8 lbl_1_data_27338__fzgx_offset_0[];
extern u8 lbl_1_data_27344__fzgx_offset_0[];
extern u8 lbl_1_data_27358__fzgx_offset_0[];
extern u8 lbl_1_data_27364__fzgx_offset_0[];
extern u8 lbl_1_data_27378__fzgx_offset_0[];
extern u8 lbl_1_data_27384__fzgx_offset_0[];
extern u8 lbl_1_data_27398__fzgx_offset_0[];
extern u8 lbl_1_data_273A8__fzgx_offset_0[];
extern u8 lbl_1_data_273BC__fzgx_offset_0[];
extern u8 lbl_1_data_273CC__fzgx_offset_0[];
extern u8 lbl_1_data_273E0__fzgx_offset_0[];
extern u8 lbl_1_data_273F0__fzgx_offset_0[];
extern u8 lbl_1_data_27404__fzgx_offset_0[];
extern u8 lbl_1_data_27414__fzgx_offset_0[];
extern u8 lbl_1_data_27424__fzgx_offset_0[];
extern u8 lbl_1_data_2742C__fzgx_offset_0[];
extern u8 lbl_1_data_2743C__fzgx_offset_0[];
extern u8 lbl_1_data_27444__fzgx_offset_0[];
extern u8 lbl_1_data_27454__fzgx_offset_0[];
extern u8 lbl_1_data_2745C__fzgx_offset_0[];
extern u8 lbl_1_data_2746C__fzgx_offset_0[];
extern u8 lbl_1_data_27474__fzgx_offset_0[];
extern u8 lbl_1_data_27484__fzgx_offset_0[];
extern u8 lbl_1_data_2748C__fzgx_offset_0[];
extern u8 lbl_1_data_2749C__fzgx_offset_0[];
extern u8 lbl_1_data_274A4__fzgx_offset_0[];
extern u8 lbl_1_data_274B4__fzgx_offset_0[];
extern u8 lbl_1_data_274BC__fzgx_offset_0[];
extern u8 lbl_1_data_274CC__fzgx_offset_0[];
static u32 fzgx_pool_native_lbl_1_data_209C0_gap_0[215] = {0x47415A45, 0x4C4C4500, 0x4A4F4459, 0x00000000, 0x53544557, 0x41525400, 0x42414241, 0x00000000, 0x474F524F, 0x48000000, 0x5049434F, 0x00000000, 0x46414C43, 0x4F4E0000, 0x4F43544D, 0x414E0000, 0x45414400, 0x4A414D45, 0x53000000, 0x42494C4C, 0x59000000, 0x4B415445, 0x00000000, 0x5A4F4441, 0x00000000, 0x4A41434B, 0x00000000, 0x52455800, 0x474F5244, 0x4F4E0000, 0x47555354, 0x45520000, 0x42454153, 0x544D414E, 0x00000000, 0x4C454F4E, 0x00000000, 0x4152524F, 0x57000000, 0x4D525300, 0x5348494F, 0x00000000, 0x4E45454C, 0x53454E00, 0x4D494348, 0x41454C00, 0x424C4F4F, 0x44000000, 0x54414E41, 0x4B410000, 0x44524151, 0x00000000, 0x524F4745, 0x52000000, 0x434C4153, 0x48000000, 0x53484144, 0x4F570000, 0x424F5353, 0x00000000, 0x444F4E00, 0x44494749, 0x424F5900, 0x44414900, 0x53504144, 0x45000000, 0x44414947, 0x4F524F48, 0x00000000, 0x50524953, 0x49410000, 0x4C494C59, 0x00000000, 0x504A0000, 0x51515100, 0x53484552, 0x4C4F434B, 0x00000000, 0x474F4D41, 0x00000000, 0x53414E00, 0x47454E00, 0x494E5445, 0x52564945, 0x57455200, (u32)lbl_1_data_209C0__fzgx_offset_0, (u32)lbl_1_data_209C8__fzgx_offset_0, (u32)lbl_1_data_209D0__fzgx_offset_0, (u32)lbl_1_data_209D8__fzgx_offset_0, (u32)lbl_1_data_209E0__fzgx_offset_0, (u32)lbl_1_data_209E8__fzgx_offset_0, (u32)lbl_1_data_209F0__fzgx_offset_0, (u32)lbl_1_data_209F8__fzgx_offset_0, (u32)lbl_1_data_20A00__fzgx_offset_0, (u32)lbl_1_data_20A04__fzgx_offset_0, (u32)lbl_1_data_20A0C__fzgx_offset_0, (u32)lbl_1_data_20A14__fzgx_offset_0, (u32)lbl_1_data_20A1C__fzgx_offset_0, (u32)lbl_1_data_20A24__fzgx_offset_0, (u32)lbl_1_data_20A2C__fzgx_offset_0, (u32)lbl_1_data_20A30__fzgx_offset_0, (u32)lbl_1_data_20A38__fzgx_offset_0, (u32)lbl_1_data_20A40__fzgx_offset_0, (u32)lbl_1_data_20A4C__fzgx_offset_0, (u32)lbl_1_data_20A54__fzgx_offset_0, (u32)lbl_1_data_20A5C__fzgx_offset_0, (u32)lbl_1_data_20A60__fzgx_offset_0, (u32)lbl_1_data_20A68__fzgx_offset_0, (u32)lbl_1_data_20A70__fzgx_offset_0, (u32)lbl_1_data_20A78__fzgx_offset_0, (u32)lbl_1_data_20A80__fzgx_offset_0, (u32)lbl_1_data_20A88__fzgx_offset_0, (u32)lbl_1_data_20A90__fzgx_offset_0, (u32)lbl_1_data_20A98__fzgx_offset_0, (u32)lbl_1_data_20AA0__fzgx_offset_0, (u32)lbl_1_data_20AA8__fzgx_offset_0, (u32)lbl_1_data_20AB0__fzgx_offset_0, (u32)lbl_1_data_20AB4__fzgx_offset_0, (u32)lbl_1_data_20ABC__fzgx_offset_0, (u32)lbl_1_data_20AC0__fzgx_offset_0, (u32)lbl_1_data_20AC8__fzgx_offset_0, (u32)lbl_1_data_20AD4__fzgx_offset_0, (u32)lbl_1_data_20ADC__fzgx_offset_0, (u32)lbl_1_data_20AE4__fzgx_offset_0, (u32)lbl_1_data_20AE8__fzgx_offset_0, (u32)lbl_1_data_20AEC__fzgx_offset_0, (u32)lbl_1_data_20AF8__fzgx_offset_0, (u32)lbl_1_data_20B00__fzgx_offset_0, (u32)lbl_1_data_20B04__fzgx_offset_0, (u32)lbl_1_data_20B08__fzgx_offset_0, 0x67617A65, 0x6C6C6500, 0x6A6F6479, 0x00000000, 0x73746577, 0x61727400, 0x62616261, 0x00000000, 0x676F726F, 0x68000000, 0x7069636F, 0x00000000, 0x66616C63, 0x6F6E0000, 0x6F63746D, 0x616E0000, 0x65616400, 0x6A616D65, 0x73000000, 0x62696C6C, 0x79000000, 0x6B617465, 0x00000000, 0x7A6F6461, 0x00000000, 0x6A61636B, 0x00000000, 0x72657800, 0x676F7264, 0x6F6E0000, 0x67757374, 0x65720000, 0x62656173, 0x746D616E, 0x00000000, 0x6C656F6E, 0x00000000, 0x6172726F, 0x77000000, 0x6D727300, 0x7368696F, 0x00000000, 0x6E65656C, 0x73656E00, 0x6D696368, 0x61656C00, 0x626C6F6F, 0x64000000, 0x74616E61, 0x6B610000, 0x64726171, 0x00000000, 0x726F6765, 0x72000000, 0x636C6173, 0x68000000, 0x73686164, 0x6F770000, 0x626F7373, 0x00000000, 0x646F6E00, 0x64696769, 0x626F7900, 0x64616900, 0x73706164, 0x65000000, 0x64616967, 0x6F726F68, 0x00000000, 0x70726973, 0x69610000, 0x6C696C79, 0x00000000, 0x706A0000, 0x71717100, 0x73686572, 0x6C6F636B, 0x00000000, 0x676F6D61, 0x00000000, 0x73616E00, 0x67656E00, 0x696E7465, 0x72766965, 0x77657200}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union {u32 words[6879]; const char *view[(0x6ED8 - 0x35C) / 4];} fzgx_pool_native_lbl_1_data_209C0_names = {{(u32)lbl_1_data_20BC8__fzgx_offset_0, (u32)lbl_1_data_20BD0__fzgx_offset_0, (u32)lbl_1_data_20BD8__fzgx_offset_0, (u32)lbl_1_data_20BE0__fzgx_offset_0, (u32)lbl_1_data_20BE8__fzgx_offset_0, (u32)lbl_1_data_20BF0__fzgx_offset_0, (u32)lbl_1_data_20BF8__fzgx_offset_0, (u32)lbl_1_data_20C00__fzgx_offset_0, (u32)lbl_1_data_20C08__fzgx_offset_0, (u32)lbl_1_data_20C0C__fzgx_offset_0, (u32)lbl_1_data_20C14__fzgx_offset_0, (u32)lbl_1_data_20C1C__fzgx_offset_0, (u32)lbl_1_data_20C24__fzgx_offset_0, (u32)lbl_1_data_20C2C__fzgx_offset_0, (u32)lbl_1_data_20C34__fzgx_offset_0, (u32)lbl_1_data_20C38__fzgx_offset_0, (u32)lbl_1_data_20C40__fzgx_offset_0, (u32)lbl_1_data_20C48__fzgx_offset_0, (u32)lbl_1_data_20C54__fzgx_offset_0, (u32)lbl_1_data_20C5C__fzgx_offset_0, (u32)lbl_1_data_20C64__fzgx_offset_0, (u32)lbl_1_data_20C68__fzgx_offset_0, (u32)lbl_1_data_20C70__fzgx_offset_0, (u32)lbl_1_data_20C78__fzgx_offset_0, (u32)lbl_1_data_20C80__fzgx_offset_0, (u32)lbl_1_data_20C88__fzgx_offset_0, (u32)lbl_1_data_20C90__fzgx_offset_0, (u32)lbl_1_data_20C98__fzgx_offset_0, (u32)lbl_1_data_20CA0__fzgx_offset_0, (u32)lbl_1_data_20CA8__fzgx_offset_0, (u32)lbl_1_data_20CB0__fzgx_offset_0, (u32)lbl_1_data_20CB8__fzgx_offset_0, (u32)lbl_1_data_20CBC__fzgx_offset_0, (u32)lbl_1_data_20CC4__fzgx_offset_0, (u32)lbl_1_data_20CC8__fzgx_offset_0, (u32)lbl_1_data_20CD0__fzgx_offset_0, (u32)lbl_1_data_20CDC__fzgx_offset_0, (u32)lbl_1_data_20CE4__fzgx_offset_0, (u32)lbl_1_data_20CEC__fzgx_offset_0, (u32)lbl_1_data_20CF0__fzgx_offset_0, (u32)lbl_1_data_20CF4__fzgx_offset_0, (u32)lbl_1_data_20D00__fzgx_offset_0, (u32)lbl_1_data_20D08__fzgx_offset_0, (u32)lbl_1_data_20D0C__fzgx_offset_0, (u32)lbl_1_data_20D10__fzgx_offset_0, 0x837D8343, 0x83658342, 0x815B2083, 0x4B835B83, 0x8B000000, 0x83578387, 0x83668342, 0x20835483, 0x7D815B00, 0x8368834E, 0x835E815B, 0x20835883, 0x60838583, 0x8F815B83, 0x67000000, 0x836F836F, 0x00000000, 0x83548380, 0x83898343, 0x20835383, 0x8D815B00, 0x83738352, 0x00000000, 0x834C8383, 0x83768365, 0x83932083, 0x74834083, 0x8B835283, 0x93000000, 0x8349834E, 0x8367837D, 0x83930000, 0x837E8358, 0x835E815B, 0x20834381, 0x5B814583, 0x47834381, 0x45836683, 0x42000000, 0x83578346, 0x815B8380, 0x83592083, 0x7D834E83, 0x89834583, 0x68000000, 0x8372838A, 0x815B0000, 0x83508343, 0x83672083, 0x41838C83, 0x93000000, 0x835D815B, 0x835F0000, 0x83578383, 0x8362834E, 0x20838C83, 0x72839300, 0x836F8343, 0x83492083, 0x8C836283, 0x4E835800, 0x83552083, 0x58834A83, 0x8B000000, 0x83418393, 0x8367836A, 0x83492083, 0x4B835883, 0x5E815B00, 0x8372815B, 0x83588367, 0x837D8393, 0x00000000, 0x838C8349, 0x83930000, 0x8358815B, 0x8370815B, 0x20834183, 0x8D815B00, 0x837E835A, 0x83582083, 0x41838D81, 0x5B000000, 0x8353837D, 0x815B8195, 0x83568349, 0x815B0000, 0x8356838B, 0x836F815B, 0x20836A81, 0x5B838B83, 0x5A839300, 0x837D8343, 0x8350838B, 0x20836083, 0x46815B83, 0x93000000, 0x83758389, 0x83628368, 0x20837483, 0x40838B83, 0x52839300, 0x83578387, 0x83932083, 0x5E836983, 0x4A000000, 0x83688389, 0x834E0000, 0x838D8357, 0x8383815B, 0x20836F83, 0x58835E81, 0x5B000000, 0x8368834E, 0x835E815B, 0x20834E83, 0x89836283, 0x56838500, 0x83758389, 0x8362834E, 0x20835683, 0x83836881, 0x5B000000, 0x83668358, 0x837B815B, 0x83930000, 0x83688393, 0x20835781, 0x5B836A81, 0x5B000000, 0x83668357, 0x20837B81, 0x5B834300, 0x835F8343, 0x81458354, 0x83938145, 0x83518393, 0x00000000, 0x83588379, 0x815B8368, 0x00000000, 0x835F8343, 0x8353838D, 0x815B0000, 0x8376838A, 0x83938356, 0x83410000, 0x838A838A, 0x815B0000, 0x8373815B, 0x83578346, 0x83430000, 0x834C8385, 0x815B8358, 0x838A815B, 0x00000000, 0x83748346, 0x836A8362, 0x834E8358, 0x00000000, 0x8353837D, 0x815B0000, 0x83548393, 0x00000000, 0x83518393, 0x00000000, 0x83438393, 0x835E8372, 0x8385838F, 0x815B0000, (u32)lbl_1_data_20DD0__fzgx_offset_0, (u32)lbl_1_data_20DE4__fzgx_offset_0, (u32)lbl_1_data_20DF4__fzgx_offset_0, (u32)lbl_1_data_20E0C__fzgx_offset_0, (u32)lbl_1_data_20E14__fzgx_offset_0, (u32)lbl_1_data_20E24__fzgx_offset_0, (u32)lbl_1_data_20E2C__fzgx_offset_0, (u32)lbl_1_data_20E44__fzgx_offset_0, (u32)lbl_1_data_20E50__fzgx_offset_0, (u32)lbl_1_data_20E6C__fzgx_offset_0, (u32)lbl_1_data_20E84__fzgx_offset_0, (u32)lbl_1_data_20E8C__fzgx_offset_0, (u32)lbl_1_data_20E9C__fzgx_offset_0, (u32)lbl_1_data_20EA4__fzgx_offset_0, (u32)lbl_1_data_20EB4__fzgx_offset_0, (u32)lbl_1_data_20EC4__fzgx_offset_0, (u32)lbl_1_data_20ED0__fzgx_offset_0, (u32)lbl_1_data_20EE4__fzgx_offset_0, (u32)lbl_1_data_20EF4__fzgx_offset_0, (u32)lbl_1_data_20EFC__fzgx_offset_0, (u32)lbl_1_data_20F0C__fzgx_offset_0, (u32)lbl_1_data_20F1C__fzgx_offset_0, (u32)lbl_1_data_20F2C__fzgx_offset_0, (u32)lbl_1_data_20F40__fzgx_offset_0, (u32)lbl_1_data_20F54__fzgx_offset_0, (u32)lbl_1_data_20F68__fzgx_offset_0, (u32)lbl_1_data_20F78__fzgx_offset_0, (u32)lbl_1_data_20F80__fzgx_offset_0, (u32)lbl_1_data_20F94__fzgx_offset_0, (u32)lbl_1_data_20FA8__fzgx_offset_0, (u32)lbl_1_data_20FBC__fzgx_offset_0, (u32)lbl_1_data_20FC8__fzgx_offset_0, (u32)lbl_1_data_20FD8__fzgx_offset_0, (u32)lbl_1_data_20FE4__fzgx_offset_0, (u32)lbl_1_data_20FF8__fzgx_offset_0, (u32)lbl_1_data_21004__fzgx_offset_0, (u32)lbl_1_data_21010__fzgx_offset_0, (u32)lbl_1_data_2101C__fzgx_offset_0, (u32)lbl_1_data_21024__fzgx_offset_0, (u32)lbl_1_data_21030__fzgx_offset_0, (u32)lbl_1_data_21040__fzgx_offset_0, (u32)lbl_1_data_21050__fzgx_offset_0, (u32)lbl_1_data_21058__fzgx_offset_0, (u32)lbl_1_data_21060__fzgx_offset_0, (u32)lbl_1_data_21068__fzgx_offset_0, 0x4D494748, 0x54592047, 0x415A454C, 0x4C450000, 0x4A4F4459, 0x2053554D, 0x4D455200, 0x44722E20, 0x53544557, 0x41525400, 0x53414D55, 0x52414920, 0x474F524F, 0x48000000, 0x43415054, 0x41494E20, 0x46414C43, 0x4F4E0000, 0x4F43544F, 0x4D414E00, 0x4D722E20, 0x45414400, 0x4A414D45, 0x53204D63, 0x434C4F55, 0x44000000, 0x4B415445, 0x20414C45, 0x4E000000, 0x4A41434B, 0x204C4556, 0x494E0000, 0x42494F20, 0x52455800, 0x54484520, 0x534B554C, 0x4C000000, 0x414E544F, 0x4E494F20, 0x47555354, 0x45520000, 0x53555045, 0x52204152, 0x524F5700, 0x4D72732E, 0x20415252, 0x4F570000, 0x474F4D41, 0x52202620, 0x5348494F, 0x48000000, 0x53494C56, 0x4552204E, 0x45454C53, 0x454E0000, 0x4D494348, 0x41454C20, 0x43484149, 0x4E000000, 0x424C4F4F, 0x44204641, 0x4C434F4E, 0x00000000, 0x4A4F484E, 0x2054414E, 0x414B4100, 0x524F4745, 0x52204255, 0x53544552, 0x00000000, 0x44722E20, 0x434C4153, 0x48000000, 0x424C4143, 0x4B205348, 0x41444F57, 0x00000000, 0x44454154, 0x48424F52, 0x4E000000, 0x444F4E20, 0x47454E49, 0x45000000, 0x44494749, 0x2D424F59, 0x00000000, 0x44414920, 0x53414E20, 0x47454E00, 0x5052494E, 0x43494100, 0x50484F45, 0x4E495800, 0x474F4D41, 0x52000000, (u32)lbl_1_data_2112C__fzgx_offset_0, (u32)lbl_1_data_2113C__fzgx_offset_0, (u32)lbl_1_data_21148__fzgx_offset_0, (u32)lbl_1_data_209D8__fzgx_offset_0, (u32)lbl_1_data_21154__fzgx_offset_0, (u32)lbl_1_data_209E8__fzgx_offset_0, (u32)lbl_1_data_21164__fzgx_offset_0, (u32)lbl_1_data_21174__fzgx_offset_0, (u32)lbl_1_data_2117C__fzgx_offset_0, (u32)lbl_1_data_21184__fzgx_offset_0, (u32)lbl_1_data_20A0C__fzgx_offset_0, (u32)lbl_1_data_21194__fzgx_offset_0, (u32)lbl_1_data_20A1C__fzgx_offset_0, (u32)lbl_1_data_211A0__fzgx_offset_0, (u32)lbl_1_data_211AC__fzgx_offset_0, (u32)lbl_1_data_211B4__fzgx_offset_0, (u32)lbl_1_data_211C0__fzgx_offset_0, (u32)lbl_1_data_20A40__fzgx_offset_0, (u32)lbl_1_data_20A4C__fzgx_offset_0, (u32)lbl_1_data_211D0__fzgx_offset_0, (u32)lbl_1_data_211DC__fzgx_offset_0, (u32)lbl_1_data_211E8__fzgx_offset_0, (u32)lbl_1_data_211F8__fzgx_offset_0, (u32)lbl_1_data_21208__fzgx_offset_0, (u32)lbl_1_data_21218__fzgx_offset_0, (u32)lbl_1_data_21228__fzgx_offset_0, (u32)lbl_1_data_20A88__fzgx_offset_0, (u32)lbl_1_data_21234__fzgx_offset_0, (u32)lbl_1_data_21244__fzgx_offset_0, (u32)lbl_1_data_21250__fzgx_offset_0, (u32)lbl_1_data_21260__fzgx_offset_0, (u32)lbl_1_data_2126C__fzgx_offset_0, (u32)lbl_1_data_21278__fzgx_offset_0, (u32)lbl_1_data_21284__fzgx_offset_0, (u32)lbl_1_data_20AC0__fzgx_offset_0, (u32)lbl_1_data_20AC8__fzgx_offset_0, (u32)lbl_1_data_21290__fzgx_offset_0, (u32)lbl_1_data_20ADC__fzgx_offset_0, (u32)lbl_1_data_20AE4__fzgx_offset_0, (u32)lbl_1_data_20AE8__fzgx_offset_0, (u32)lbl_1_data_21298__fzgx_offset_0, (u32)lbl_1_data_212A0__fzgx_offset_0, (u32)lbl_1_data_20B00__fzgx_offset_0, (u32)lbl_1_data_20B04__fzgx_offset_0, (u32)lbl_1_data_20B08__fzgx_offset_0, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x00010708, 0x09030405, 0x0A101112, 0x0C0D0E1D, 0x1E1F2021, 0x22232427, 0x282B2C00, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x0205080B, 0x0E0F1113, 0x14161B1E, 0x22232425, 0x292A2B2C, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x01030506, 0x07080B0C, 0x0D101718, 0x1A1B1213, 0x15160000, 0x01030506, 0x07080B0C, 0x0D101718, 0x1A1B1213, 0x15160000, 0x00010304, 0x05070809, 0x0A0C0D0E, 0x1011121D, 0x1E1F2021, 0x22232426, 0x2728292A, 0x2B2C2D00, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x00010304, 0x05070809, 0x0A101112, 0x0C0D0E1D, 0x1E1F2021, 0x22232426, 0x2728292A, 0x2B2C2D00, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x00010708, 0x09030405, 0x0A0C0D0E, 0x1011121D, 0x1E1F2021, 0x22232426, 0x2728292A, 0x2B2C2D19, 0x1A1B1516, 0x17000000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x01050708, 0x0A0C0D0F, 0x1017181A, 0x12131500, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x01050607, 0x080B0C0D, 0x10121315, 0x1617181A, 0x1B000000, 0x01050607, 0x080B0C0D, 0x10121315, 0x1617181A, 0x1B000000, 0x00010304, 0x05070809, 0x0A101112, 0x0C0D0E2B, 0x2C272822, 0x23241E1F, 0x20000000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x01030507, 0x080A0C0D, 0x0F101213, 0x1517181A, 0x10121315, 0x17181A01, 0x03050708, 0x0A0C0D0F, 0x01030507, 0x080C0D10, 0x010B0C0D, 0x06070805, 0x10121315, 0x1617181A, 0x1B000000, 0x010B0C0D, 0x06070805, 0x10121315, 0x1617181A, 0x1B000000, 0x001E1F20, 0x2223242C, 0x2813191A, 0x1B151617, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x10121315, 0x17181A01, 0x0C0D0F07, 0x080A0305, 0x10121315, 0x17181A01, 0x0C0D0F07, 0x080A0305, 0x10010C0D, 0x07080305, 0x010B0C0D, 0x05060708, 0x1D1E2025, 0x26212223, 0x2428292B, 0x2E2F2C2D, 0x30311012, 0x13151617, 0x181A1B00, 0x010B0C0D, 0x05060708, 0x1D1E2025, 0x26212223, 0x2428292B, 0x2E2F2C2D, 0x30311012, 0x13151617, 0x181A1B00, 0x00010304, 0x05070809, 0x0A0C0D0E, 0x10111219, 0x1A1B1516, 0x17000000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x10121315, 0x17181A01, 0x0C0D0F05, 0x07080A1D, 0x1E282900, 0x10121315, 0x17181A01, 0x0C0D0F05, 0x07080A1D, 0x1E282900, 0x10010C0D, 0x05070800, 0x0103050B, 0x0C0D0607, 0x08101213, 0x15161718, 0x1A1B0000, 0x0103050B, 0x0C0D0607, 0x08101213, 0x15161718, 0x1A1B0000, 0x00010304, 0x05070809, 0x1011120C, 0x0D0E1319, 0x1A1B1516, 0x172B2C2D, 0x27282922, 0x23241E1F, 0x20000000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x10121315, 0x17181A01, 0x03050C0D, 0x07080000, 0x000F1001, 0x02030405, 0x06070809, 0x0A0B0C00, 0x0103050C, 0x0D0F0708, 0x0A101213, 0x1517181A, 0x01050C0D, 0x07081012, 0x17000000, 0x01050B0C, 0x0D060708, 0x10121315, 0x1617181A, 0x1B000000, 0x01050B0C, 0x0D060708, 0x10121315, 0x1617181A, 0x1B000000, 0x00010708, 0x09030405, 0x0A0C0D0E, 0x10111219, 0x1A1B1516, 0x171D1E1F, 0x20212223, 0x24262728, 0x292A2B2C, 0x2D2F3000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x01000000, 0x10121315, 0x1617181A, 0x1B01050C, 0x0D0F0708, 0x0A000000, 0x10121315, 0x1617181A, 0x1B01050C, 0x0D0E0708, 0x09000000, 0x10121701, 0x050C0D07, 0x08000000, 0x01060708, 0x0B0C0D03, 0x05101213, 0x15161D1E, 0x2017181A, 0x1B000000, 0x01060708, 0x0B0C0D03, 0x05101213, 0x15161D1E, 0x2017181A, 0x1B000000, 0x00010304, 0x05070809, 0x0A101112, 0x0C0D0E15, 0x1617191A, 0x1B000000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x0107080A, 0x0C0D0F05, 0x10121315, 0x1D1E1F17, 0x181A0000, 0x0107080A, 0x0C0D0F05, 0x10121315, 0x1D1E1F17, 0x181A0000, 0x0107080C, 0x0D051000, 0x01060708, 0x0B0C0D10, 0x12131516, 0x17181A1B, 0x01060708, 0x0B0C0D10, 0x12131516, 0x17181A1B, 0x00010304, 0x05070809, 0x0A0C0D0E, 0x1011121D, 0x1E1F2021, 0x2223242A, 0x2B2C2D26, 0x27282919, 0x1A1B1516, 0x17000000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x01000000, 0x01050708, 0x0A0C0D0F, 0x10121315, 0x17181A00, 0x01050708, 0x0A0C0D0F, 0x10121315, 0x17181A00, 0x01050708, 0x0C0D1000, 0x01050708, 0x0C0D1017, 0x181A1B12, 0x1315161D, 0x20210000, 0x01050708, 0x0C0D1017, 0x181A1B12, 0x1315161D, 0x20210000, 0x00010304, 0x05070809, 0x0C0D0E10, 0x11121D1E, 0x1F202122, 0x23242728, 0x292B2C2D, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x1213151D, 0x20010305, 0x07080A0C, 0x0D0F0000, 0x1017181A, 0x1213151D, 0x20010305, 0x07080A0C, 0x0D0F0000, 0x10010507, 0x080A0C0D, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x00010708, 0x09030405, 0x0A0C0D0E, 0x10111215, 0x1617191A, 0x1B1E1F20, 0x22232400, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x12131501, 0x03050708, 0x0A0C0D0F, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x01050607, 0x080B0C0D, 0x10121315, 0x1617181A, 0x1B000000, 0x01050607, 0x080B0C0D, 0x10121315, 0x1617181A, 0x1B000000, 0x00010304, 0x05070809, 0x0A101112, 0x0C0D0E2B, 0x2C2D2728, 0x29222324, 0x1E1F2000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x10121315, 0x17181A01, 0x03050708, 0x0A0C0D0F, 0x10121315, 0x17181A01, 0x03050708, 0x0A0C0D0F, 0x10010507, 0x080C0D00, 0x01060708, 0x0B0C0D10, 0x17181A1B, 0x12131516, 0x01060708, 0x0B0C0D10, 0x17181A1B, 0x12131516, 0x002F3000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x0103050B, 0x0C0D0607, 0x08101213, 0x15161718, 0x1A1B0000, 0x0103050B, 0x0C0D0607, 0x08101213, 0x15161718, 0x1A1B0000, 0x00010304, 0x05070809, 0x1011120C, 0x0D0E1319, 0x1A1B1516, 0x172B2C2D, 0x27282922, 0x23241E1F, 0x20000000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x10121315, 0x17181A01, 0x03050C0D, 0x07080000, 0x000F1001, 0x02030405, 0x06070809, 0x0A0B0C00, 0x0103050C, 0x0D0F0708, 0x0A101213, 0x1517181A, 0x01050C0D, 0x07081012, 0x17000000, 0x01050B0C, 0x0D060708, 0x1017181A, 0x1B121315, 0x16000000, 0x01050B0C, 0x0D060708, 0x1017181A, 0x1B121315, 0x16000000, 0x00101112, 0x0C0D0E01, 0x03040507, 0x08092B2C, 0x2D272829, 0x2223241E, 0x1F200000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x0103050C, 0x0D070810, 0x17181A12, 0x13150000, 0x000F1001, 0x02030405, 0x06070809, 0x0A0B0C00, 0x0103050C, 0x0D0F0708, 0x0A101718, 0x1A121315, 0x01050C0D, 0x07081000, 0x01030507, 0x080A0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01030507, 0x080A0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x00010708, 0x09030405, 0x0A0F1011, 0x120B0C0D, 0x0E13191A, 0x1B151617, 0x2F300000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x010B0C0D, 0x06070803, 0x05101213, 0x15161718, 0x1A1B0000, 0x010B0C0D, 0x06070803, 0x05101213, 0x15161718, 0x1A1B0000, 0x00010304, 0x05070809, 0x0A0C0D0E, 0x10111213, 0x15161719, 0x1A1B0000, 0x000D0E0F, 0x10010203, 0x04050607, 0x08090A0B, 0x0C000000, 0x10121315, 0x17181A01, 0x0C0D0F07, 0x080A0305, 0x10121315, 0x17181A01, 0x0C0D0F07, 0x080A0305, 0x10010C0D, 0x07080500, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x00010304, 0x05070809, 0x0A101112, 0x0C0D0E19, 0x1A1B1516, 0x17000000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x01030506, 0x07080B0C, 0x0D101213, 0x15161718, 0x1A1B0000, 0x00010708, 0x09030405, 0x0A0F1011, 0x120B0C0D, 0x0E000000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x01050B0C, 0x0D060708, 0x10121315, 0x1617181A, 0x1B000000, 0x01050B0C, 0x0D060708, 0x10121315, 0x1617181A, 0x1B000000, 0x00010708, 0x09030405, 0x0A0C0D0E, 0x10111219, 0x1A1B1516, 0x172F3022, 0x23241E1F, 0x202B2C2D, 0x27282900, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x10121315, 0x17181A01, 0x03050C0D, 0x0F07080A, 0x10121315, 0x17181A01, 0x03050C0D, 0x0F07080A, 0x10010305, 0x0C0D0708, 0x01050607, 0x080B0C0D, 0x10121315, 0x1617181A, 0x1B000000, 0x01050607, 0x080B0C0D, 0x10121315, 0x1617181A, 0x1B000000, 0x00010708, 0x09030405, 0x0A101112, 0x0C0D0E15, 0x1617191A, 0x1B000000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x10121315, 0x17181A01, 0x03050708, 0x0A0C0D0F, 0x10121315, 0x17181A01, 0x03050708, 0x0A0C0D0F, 0x10010507, 0x080C0D00, 0x01050B0C, 0x0D060708, 0x10121315, 0x1617181A, 0x1B000000, 0x01050B0C, 0x0D060708, 0x10121315, 0x1617181A, 0x1B000000, 0x00010708, 0x09030405, 0x0A0C0D0E, 0x10111219, 0x1A1B1516, 0x171E1F20, 0x22232427, 0x28292B2C, 0x2D302F00, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x10121315, 0x17181A01, 0x050C0D0F, 0x07080A00, 0x10121315, 0x17181A01, 0x050C0D0F, 0x07080A00, 0x1001050C, 0x0D070800, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x00010708, 0x09030405, 0x0A0C0D0E, 0x10111213, 0x15161719, 0x1A1B2F30, 0x1E1F2022, 0x23242728, 0x292B2C2D, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x161D2023, 0x24000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x161D2023, 0x24000000, 0x00010809, 0x0304050A, 0x0C0D0E10, 0x11122F30, 0x2223241E, 0x1F202B2C, 0x2D272800, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x1D202324, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x1D202324, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x01060708, 0x0B0C0D03, 0x05101213, 0x15161718, 0x1A1B0000, 0x01060708, 0x0B0C0D03, 0x05101213, 0x15161718, 0x1A1B0000, 0x00010708, 0x09030405, 0x2F302B2C, 0x2D272829, 0x15161719, 0x1A1B0A0F, 0x1011120B, 0x0C0D0E21, 0x2223241D, 0x1E1F2000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x10121315, 0x17181A01, 0x07080A0C, 0x0D0F0500, 0x10121315, 0x17181A01, 0x07080A0C, 0x0D0F0500, 0x10010708, 0x0C0D0500, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x00010708, 0x09030405, 0x0A0C0D0E, 0x10111215, 0x1617191A, 0x1B000000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x01050708, 0x0C0D1000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x00010708, 0x09030405, 0x0A0C0D0E, 0x10111215, 0x1617191A, 0x1B2F301E, 0x1F202223, 0x24272829, 0x2B2C2D00, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x01050607, 0x080B0C0D, 0x10121315, 0x1617181A, 0x1B000000, 0x01050607, 0x080B0C0D, 0x10121315, 0x1617181A, 0x1B000000, 0x00010708, 0x09030405, 0x0A101112, 0x0C0D0E13, 0x191A1B15, 0x16172122, 0x23241D1E, 0x1F200000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x01000000, 0x10121315, 0x17181A01, 0x0507080A, 0x0C0D0F00, 0x10121315, 0x17181A01, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x1017181A, 0x1B121315, 0x162B2E2F, 0x26292A01, 0x0C0D0F07, 0x080A1C1F, 0x20212425, 0x1017181A, 0x1B121315, 0x162B2E2F, 0x26292A01, 0x0C0D0F07, 0x080A1C1F, 0x20212425, 0x00030405, 0x0708090C, 0x0D0E1011, 0x121E1F20, 0x2223242B, 0x2C2D2728, 0x29000000, 0x010C0D0F, 0x07080A05, 0x1C1F2021, 0x24251017, 0x181A1213, 0x152B2E2F, 0x26292A00, 0x010C0D0F, 0x07080A05, 0x1C1F2021, 0x24251017, 0x181A1213, 0x152B2E2F, 0x26292A00, 0x010C0D07, 0x08051000, 0x010B0C0D, 0x06070803, 0x05101213, 0x15161718, 0x1A1B0000, 0x010B0C0D, 0x06070803, 0x05101213, 0x15161718, 0x1A1B0000, 0x00010A00, 0x000D0E0F, 0x10010203, 0x04050607, 0x08090A0B, 0x0C000000, 0x10121315, 0x17181A01, 0x0C0D0F07, 0x080A0500, 0x10121315, 0x17181A01, 0x0C0D0F07, 0x080A0500, 0x10121701, 0x0C0D0708, 0x05000000, 0x01060708, 0x0B0C0D05, 0x10121315, 0x1617181A, 0x1B000000, 0x01000000, 0x01060708, 0x0B0C0D05, 0x10121315, 0x1617181A, 0x1B000000, 0x00010A00, 0x000E0F10, 0x0405060A, 0x0B0C0000, 0x0107080A, 0x0C0D0F05, 0x10121315, 0x17181A00, 0x0107080A, 0x0C0D0F05, 0x10121315, 0x17181A00, 0x0107080C, 0x0D051000, 0x01050B0C, 0x0D060708, 0x10121315, 0x1617181A, 0x1B000000, 0x01050B0C, 0x0D060708, 0x10121315, 0x1617181A, 0x1B000000, 0x00010304, 0x05070809, 0x0A101112, 0x0C0D0E15, 0x1617191A, 0x1B222324, 0x1D1E1F20, 0x2A2B2C2D, 0x26272829, 0x302F0000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x01050C0D, 0x0F07080A, 0x10121315, 0x17181A00, 0x01050C0D, 0x0F07080A, 0x10121315, 0x17181A00, 0x1001050C, 0x0D070800, 0x01030708, 0x0C0D1017, 0x181A1B12, 0x13151600, 0x01030708, 0x0C0D1017, 0x181A1B12, 0x13151600, 0x0001120E, 0x2E000000, 0x000E0A00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10171201, 0x05070809, 0x0C0D0E00, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x161D2023, 0x26000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x161D2023, 0x26000000, 0x00010A0C, 0x0D0E1011, 0x12000000, 0x000E0F04, 0x050A0B0C, 0x1017181A, 0x1213151D, 0x20232601, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x1213151D, 0x20232601, 0x0507080A, 0x0C0D0F00, 0x101D2023, 0x01050708, 0x0C0D0000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x00010708, 0x09030405, 0x0A101112, 0x0C0D0E2F, 0x301D1E1F, 0x20212223, 0x24262728, 0x292A2B2C, 0x2D191A1B, 0x15161700, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x01050708, 0x0A0C0D0F, 0x1017181A, 0x12131500, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x0103050B, 0x0C0D0607, 0x08101213, 0x15161718, 0x1A1B0000, 0x0103050B, 0x0C0D0607, 0x08101213, 0x15161718, 0x1A1B0000, 0x00010304, 0x05070809, 0x1011120C, 0x0D0E1319, 0x1A1B1516, 0x172B2C2D, 0x27282922, 0x23241E1F, 0x20000000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x10121315, 0x17181A01, 0x03050C0D, 0x07080000, 0x000F1001, 0x02030405, 0x06070809, 0x0A0B0C00, 0x0103050C, 0x0D0F0708, 0x0A101213, 0x1517181A, 0x01050C0D, 0x07081012, 0x17000000, 0x010B0C0D, 0x06070805, 0x1017181A, 0x1B121315, 0x16000000, 0x010B0C0D, 0x06070805, 0x1017181A, 0x1B121315, 0x16000000, 0x00010708, 0x09030405, 0x0A101112, 0x0C0D0E22, 0x23241E1F, 0x20272829, 0x2B2C2D00, 0x000D0E0F, 0x10010203, 0x04050607, 0x08090A0B, 0x0C000000, 0x1017181A, 0x12131501, 0x0C0D0F07, 0x080A0500, 0x010C0D0F, 0x07080A05, 0x1017181A, 0x12131500, 0x010C0D07, 0x08051000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x00010708, 0x09030405, 0x0A0C0D0E, 0x10111226, 0x2728292A, 0x2B2C2D1D, 0x1E1F2021, 0x22232400, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x1017181A, 0x12131501, 0x0507080A, 0x0C0D0F00, 0x10010507, 0x080C0D00, 0x01060708, 0x050B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01060708, 0x050B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x000F1011, 0x120B0C0D, 0x0E010304, 0x05070809, 0x2223241E, 0x1F202B2C, 0x2D272829, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x01070803, 0x050C0D10, 0x17181A12, 0x13150000, 0x000F1001, 0x02030405, 0x06070809, 0x0A0B0C00, 0x0107080A, 0x03050C0D, 0x0F101718, 0x1A121315, 0x01070803, 0x050C0D10, 0x010B0C0D, 0x03050607, 0x08101213, 0x15161718, 0x1A1B0000, 0x01000000, 0x010B0C0D, 0x03050607, 0x08101213, 0x15161718, 0x1A1B0000, 0x00191A1B, 0x15161727, 0x28292B2C, 0x2D1E1F20, 0x2223242E, 0x302F0000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x10121315, 0x17181A01, 0x0C0D0F03, 0x0507080A, 0x10121315, 0x17181A01, 0x0C0D0F03, 0x0507080A, 0x10010C0D, 0x05070800, 0x010B0C0D, 0x06070803, 0x05101213, 0x15161718, 0x1A1B0000, 0x010B0C0D, 0x06070803, 0x05101213, 0x15161718, 0x1A1B0000, 0x00010304, 0x05070809, 0x0A0C0D0E, 0x10111214, 0x15161718, 0x191A1B21, 0x2223241D, 0x1E1F2000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x10121315, 0x17181A01, 0x0C0D0F07, 0x080A0500, 0x10121315, 0x17181A01, 0x0C0D0F07, 0x080A0500, 0x10010C0D, 0x07080500, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x01050607, 0x080B0C0D, 0x1017181A, 0x1B121315, 0x16000000, 0x00010708, 0x09030405, 0x0A101112, 0x0C0D0E13, 0x191A1B15, 0x16171D1E, 0x1F202122, 0x23240000, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x020B0C06, 0x07000000, 0x1017181A, 0x12131501, 0x03050708, 0x0A0C0D0F, 0x1017181A, 0x12131501, 0x03050708, 0x0A0C0D0F, 0x10010507, 0x080C0D00, 0x010B0C0D, 0x06070805, 0x1017181A, 0x1B121315, 0x16000000, 0x010B0C0D, 0x06070805, 0x1017181A, 0x1B121315, 0x16000000, 0x00010708, 0x09030405, 0x0A101112, 0x0C0D0E13, 0x191A1B15, 0x16172B2C, 0x2D272829, 0x2223241E, 0x1F20302F, 0x000E0F10, 0x01020304, 0x05060708, 0x090A0B0C, 0x1017181A, 0x12131501, 0x0C0D0F07, 0x080A0305, 0x1017181A, 0x12131501, 0x0C0D0F07, 0x080A0305, 0x10010C0D, 0x07080500, 0x01000000, 0x0C000000, 0x07000000, 0x424F4459, 0x00000000, 0x46414345, 0x00000000, 0x48414E44, 0x4C000000, 0x48414E44, 0x52000000, 0x4B415441, 0x41544500, 0x5F424F41, 0x52440000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21A3C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21A64__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21A80__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21A80__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A3C__fzgx_offset_0, (u32)lbl_1_data_22A14__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_215F0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21618__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21628__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21628__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21CB4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21CDC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21CF4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21CF4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_22334__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_2235C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22360__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22360__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_22884__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_228AC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_228CC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_228CC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x4B415441, 0x4154455F, 0x52000000, 0x4B415441, 0x4154455F, 0x4C000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21F04__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21F2C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21F50__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21F50__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22DF4__fzgx_offset_0, (u32)lbl_1_data_22A14__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22E00__fzgx_offset_0, (u32)lbl_1_data_22A18__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21E08__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21E30__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21E54__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21E54__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_222A0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_222D8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21660__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_216A8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_216C0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_216C0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2193C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21964__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21980__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21980__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x5F535449, 0x434B0000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2221C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_22244__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22264__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22264__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_23190__fzgx_offset_0, (u32)lbl_1_data_22274__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2255C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_22584__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_225AC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_225AC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2146C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21494__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_214B4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_214B4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22DF4__fzgx_offset_0, (u32)lbl_1_data_22A14__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22E00__fzgx_offset_0, (u32)lbl_1_data_22A18__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x5F4D454B, 0x41000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_22904__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_2292C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_2294C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_2294C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_23420__fzgx_offset_0, (u32)lbl_1_data_2295C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_213EC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21414__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21434__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21434__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22DF4__fzgx_offset_0, (u32)lbl_1_data_22A14__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22E00__fzgx_offset_0, (u32)lbl_1_data_22A18__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21F88__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21FB0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21FD4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21FD4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x5F4F574C, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2135C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21384__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_213A0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_213A0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_236B0__fzgx_offset_0, (u32)lbl_1_data_213B0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2200C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_2203C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22058__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22058__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21C38__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21C60__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21C7C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21C7C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_22120__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_22148__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22160__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22160__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21D30__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21D58__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21D70__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21D70__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21E8C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21EB4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21ECC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21ECC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21574__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_2159C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_215B8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_215B8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2267C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_226A4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_226C0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_226C0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_22198__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_221C0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_221E4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_221E4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21BAC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21BD4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21BF0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21BF0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2277C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_227A4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_227C0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_227C0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_219C0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_219E8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21A04__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21A04__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2298C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_229B4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_229D8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_229D8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_214EC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21514__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_2153C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_2153C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21AB8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21AD8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21ADC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21ADC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_224E4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_22514__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22520__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22520__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_22404__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_2242C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22454__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22454__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22DF4__fzgx_offset_0, (u32)lbl_1_data_22A14__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22E00__fzgx_offset_0, (u32)lbl_1_data_22A18__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x5F4B4154, 0x414E4100, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21798__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_217C0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_217E8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_217E8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24318__fzgx_offset_0, (u32)lbl_1_data_217F8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2248C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_224AC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_224B4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_224B4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21830__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21860__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21878__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21878__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_218B8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_218D8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21900__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21900__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_23190__fzgx_offset_0, (u32)lbl_1_data_21910__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x5F4F5000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_223A0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_223CC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_223D0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_223D0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24638__fzgx_offset_0, (u32)lbl_1_data_223B4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21700__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21728__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_2174C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_2174C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_225E4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_2260C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22630__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22630__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21B14__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21B3C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21B60__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21B60__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_22098__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_220C0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_220E8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_220E8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x5F434152, 0x445F4A4F, 0x4B455230, 0x31000000, 0x5F434152, 0x445F4A4F, 0x4B455230, 0x32000000, 0x5F434152, 0x445F4A4F, 0x4B455230, 0x33000000, 0x5F434152, 0x445F4A4F, 0x4B455230, 0x34000000, 0x5F434152, 0x445F4143, 0x45303100, 0x5F434152, 0x445F4143, 0x45303200, 0x5F434152, 0x445F4143, 0x45303300, 0x5F434152, 0x445F4143, 0x45303400, 0x5F42414C, 0x4C303100, 0x5F42414C, 0x4C303200, 0x5F42414C, 0x4C303300, 0x5F42414C, 0x4C303400, 0x5F42414C, 0x4C303500, 0x5F42414C, 0x4C303600, 0x5F42414C, 0x4C303700, 0x5F42414C, 0x4C303800, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_22808__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_22834__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_2284C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_2284C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_249E4__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_249F4__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A04__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A14__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A24__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A30__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A3C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A48__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A54__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A5C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A64__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A6C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A74__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A7C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A84__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A8C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_226FC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_22724__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22744__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22744__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21DA8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21DBC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21DD0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21DD0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x635F6861, 0x72610000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21A90__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21638__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21D08__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22374__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_228DC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21F60__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_222F4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_216D0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21990__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21E64__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22278__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_23190__fzgx_offset_0, (u32)lbl_1_data_22274__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_225BC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_214C4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22964__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_23420__fzgx_offset_0, (u32)lbl_1_data_2295C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21444__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21FE4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22068__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_213C4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_236B0__fzgx_offset_0, (u32)lbl_1_data_213B0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21C8C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22170__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21D80__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21EDC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_215C8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_226D4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_221F4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21C00__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21C10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21C10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_227D0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_227E0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_227E0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21A14__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_229E8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21AEC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2154C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22528__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22464__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_217FC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24318__fzgx_offset_0, (u32)lbl_1_data_217F8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_224B8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21888__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21914__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_23190__fzgx_offset_0, (u32)lbl_1_data_21910__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_223DC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24638__fzgx_offset_0, (u32)lbl_1_data_223B4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2175C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_2176C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_2176C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22640__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22650__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22650__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21B70__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21B80__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21B80__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_220F8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2285C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_249E4__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_249F4__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A04__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A14__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A24__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A30__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A3C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A48__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A54__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A5C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A64__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A6C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A74__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A7C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A84__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A8C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22754__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21DE0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21AA0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21648__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21D18__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22384__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_228EC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21F70__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22310__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_216E4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_219A4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21E74__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22288__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_225CC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_214D4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22974__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21454__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21FF4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2207C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_213D4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21C9C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22180__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21D90__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21EEC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_215D8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_226E4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22204__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21C20__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_227F0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21A24__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_229F8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21AFC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2155C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2253C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22474__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21810__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_224C8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2189C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21924__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_223EC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2177C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22660__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21B90__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22108__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2286C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22764__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21DF0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21AB0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21658__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21D28__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22394__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_228FC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21F80__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2232C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_216F8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_219B8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21E84__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22298__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_225DC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_214E4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22984__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21464__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22004__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22090__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_213E4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21CAC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22190__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21DA0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21EFC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_215E8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_226F4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22214__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21C30__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22800__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21A34__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22A08__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21B0C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2156C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22550__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22484__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21824__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_224D8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_218B0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21934__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_223FC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2178C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22670__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21BA0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22118__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2287C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22774__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21E00__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xF4000000, 0xFC000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xB4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xFC000000, 0xF4000000, 0xFC000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xFC000000, 0xF4000000, 0xFC000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xFC000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xFC000000, 0xFC000000, 0xFC000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF4000000, 0xF0000000, (u32)lbl_1_data_240B4__fzgx_offset_0, (u32)lbl_1_data_22E0C__fzgx_offset_0, (u32)lbl_1_data_22D40__fzgx_offset_0, (u32)lbl_1_data_23500__fzgx_offset_0, (u32)lbl_1_data_22BD8__fzgx_offset_0, (u32)lbl_1_data_22C8C__fzgx_offset_0, (u32)lbl_1_data_22A4C__fzgx_offset_0, (u32)lbl_1_data_22FBC__fzgx_offset_0, (u32)lbl_1_data_23E98__fzgx_offset_0, (u32)lbl_1_data_23A60__fzgx_offset_0, (u32)lbl_1_data_24000__fzgx_offset_0, (u32)lbl_1_data_235FC__fzgx_offset_0, (u32)lbl_1_data_23F4C__fzgx_offset_0, (u32)lbl_1_data_22F08__fzgx_offset_0, (u32)lbl_1_data_24168__fzgx_offset_0, (u32)lbl_1_data_23844__fzgx_offset_0, (u32)lbl_1_data_239AC__fzgx_offset_0, (u32)lbl_1_data_23324__fzgx_offset_0, (u32)lbl_1_data_23790__fzgx_offset_0, (u32)lbl_1_data_236B8__fzgx_offset_0, (u32)lbl_1_data_23C7C__fzgx_offset_0, (u32)lbl_1_data_23DE4__fzgx_offset_0, (u32)lbl_1_data_23198__fzgx_offset_0, (u32)lbl_1_data_238F8__fzgx_offset_0, (u32)lbl_1_data_23B14__fzgx_offset_0, (u32)lbl_1_data_23428__fzgx_offset_0, (u32)lbl_1_data_230DC__fzgx_offset_0, (u32)lbl_1_data_23270__fzgx_offset_0, (u32)lbl_1_data_23028__fzgx_offset_0, (u32)lbl_1_data_23BC8__fzgx_offset_0, (u32)lbl_1_data_22B24__fzgx_offset_0, (u32)lbl_1_data_24560__fzgx_offset_0, (u32)lbl_1_data_244AC__fzgx_offset_0, (u32)lbl_1_data_24714__fzgx_offset_0, (u32)lbl_1_data_24A94__fzgx_offset_0, (u32)lbl_1_data_24320__fzgx_offset_0, (u32)lbl_1_data_2421C__fzgx_offset_0, (u32)lbl_1_data_24930__fzgx_offset_0, (u32)lbl_1_data_2463C__fzgx_offset_0, (u32)lbl_1_data_243F8__fzgx_offset_0, (u32)lbl_1_data_24D88__fzgx_offset_0, (u32)lbl_1_data_23D30__fzgx_offset_0, (u32)lbl_1_data_247C8__fzgx_offset_0, (u32)lbl_1_data_2487C__fzgx_offset_0, (u32)lbl_1_data_24E3C__fzgx_offset_0, 0x00000005, 0x00000007, 0x00000005, 0x00000007, 0x00000005, 0x00000005, 0x00000006, 0x00000003, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000007, 0x00000005, 0x00000006, 0x00000005, 0x00000005, 0x00000006, 0x00000005, 0x00000005, 0x00000006, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000006, 0x00000005, 0x00000005, 0x00000015, 0x00000006, 0x00000007, 0x00000005, 0x00000006, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000005, (u32)lbl_1_data_25408__fzgx_offset_0, (u32)lbl_1_data_24FAC__fzgx_offset_0, (u32)lbl_1_data_24F88__fzgx_offset_0, (u32)lbl_1_data_25138__fzgx_offset_0, (u32)lbl_1_data_24F40__fzgx_offset_0, (u32)lbl_1_data_24F64__fzgx_offset_0, (u32)lbl_1_data_24EF8__fzgx_offset_0, (u32)lbl_1_data_24FD0__fzgx_offset_0, (u32)lbl_1_data_253C0__fzgx_offset_0, (u32)lbl_1_data_25258__fzgx_offset_0, (u32)lbl_1_data_2542C__fzgx_offset_0, (u32)lbl_1_data_2515C__fzgx_offset_0, (u32)lbl_1_data_253E4__fzgx_offset_0, (u32)lbl_1_data_2503C__fzgx_offset_0, (u32)lbl_1_data_25450__fzgx_offset_0, (u32)lbl_1_data_251EC__fzgx_offset_0, (u32)lbl_1_data_25234__fzgx_offset_0, (u32)lbl_1_data_250CC__fzgx_offset_0, (u32)lbl_1_data_25180__fzgx_offset_0, (u32)lbl_1_data_251A4__fzgx_offset_0, (u32)lbl_1_data_252C4__fzgx_offset_0, (u32)lbl_1_data_25354__fzgx_offset_0, (u32)lbl_1_data_25060__fzgx_offset_0, (u32)lbl_1_data_25210__fzgx_offset_0, (u32)lbl_1_data_2527C__fzgx_offset_0, (u32)lbl_1_data_250F0__fzgx_offset_0, (u32)lbl_1_data_25018__fzgx_offset_0, (u32)lbl_1_data_250A8__fzgx_offset_0, (u32)lbl_1_data_24FF4__fzgx_offset_0, (u32)lbl_1_data_252A0__fzgx_offset_0, (u32)lbl_1_data_24F1C__fzgx_offset_0, (u32)lbl_1_data_25528__fzgx_offset_0, (u32)lbl_1_data_25504__fzgx_offset_0, (u32)lbl_1_data_255B8__fzgx_offset_0, (u32)lbl_1_data_25720__fzgx_offset_0, (u32)lbl_1_data_25498__fzgx_offset_0, (u32)lbl_1_data_25474__fzgx_offset_0, (u32)lbl_1_data_256FC__fzgx_offset_0, (u32)lbl_1_data_25570__fzgx_offset_0, (u32)lbl_1_data_254E0__fzgx_offset_0, (u32)lbl_1_data_25984__fzgx_offset_0, (u32)lbl_1_data_252E8__fzgx_offset_0, (u32)lbl_1_data_25624__fzgx_offset_0, (u32)lbl_1_data_25690__fzgx_offset_0, (u32)lbl_1_data_259A8__fzgx_offset_0, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000002, 0x00000001, 0x00000003, 0x00000002, 0x00000001, 0x00000001, 0x00000002, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000002, 0x00000001, 0x00000003, 0x00000011, 0x00000002, 0x00000001, 0x00000001, 0x00000002, 0x00000001, 0x00000001, 0x00000003, 0x00000003, 0x00000003, 0x00000001, (u32)lbl_1_data_25DE0__fzgx_offset_0, (u32)lbl_1_data_25A80__fzgx_offset_0, (u32)lbl_1_data_25A5C__fzgx_offset_0, (u32)lbl_1_data_25BC4__fzgx_offset_0, (u32)lbl_1_data_25A14__fzgx_offset_0, (u32)lbl_1_data_25A38__fzgx_offset_0, (u32)lbl_1_data_259CC__fzgx_offset_0, (u32)lbl_1_data_25AA4__fzgx_offset_0, (u32)lbl_1_data_25D98__fzgx_offset_0, (u32)lbl_1_data_25CC0__fzgx_offset_0, (u32)lbl_1_data_25E04__fzgx_offset_0, (u32)lbl_1_data_25BE8__fzgx_offset_0, (u32)lbl_1_data_25DBC__fzgx_offset_0, (u32)lbl_1_data_25B10__fzgx_offset_0, (u32)lbl_1_data_25E28__fzgx_offset_0, (u32)lbl_1_data_25C54__fzgx_offset_0, (u32)lbl_1_data_25C9C__fzgx_offset_0, (u32)lbl_1_data_25B7C__fzgx_offset_0, (u32)lbl_1_data_25C0C__fzgx_offset_0, (u32)lbl_1_data_25C30__fzgx_offset_0, (u32)lbl_1_data_25D2C__fzgx_offset_0, (u32)lbl_1_data_25D74__fzgx_offset_0, (u32)lbl_1_data_25B34__fzgx_offset_0, (u32)lbl_1_data_25C78__fzgx_offset_0, (u32)lbl_1_data_25CE4__fzgx_offset_0, (u32)lbl_1_data_25BA0__fzgx_offset_0, (u32)lbl_1_data_25AEC__fzgx_offset_0, (u32)lbl_1_data_25B58__fzgx_offset_0, (u32)lbl_1_data_25AC8__fzgx_offset_0, (u32)lbl_1_data_25D08__fzgx_offset_0, (u32)lbl_1_data_259F0__fzgx_offset_0, (u32)lbl_1_data_25EDC__fzgx_offset_0, (u32)lbl_1_data_25EB8__fzgx_offset_0, (u32)lbl_1_data_25F24__fzgx_offset_0, (u32)lbl_1_data_25FB4__fzgx_offset_0, (u32)lbl_1_data_25E70__fzgx_offset_0, (u32)lbl_1_data_25E4C__fzgx_offset_0, (u32)lbl_1_data_25F90__fzgx_offset_0, (u32)lbl_1_data_25F00__fzgx_offset_0, (u32)lbl_1_data_25E94__fzgx_offset_0, (u32)lbl_1_data_25FD8__fzgx_offset_0, (u32)lbl_1_data_25D50__fzgx_offset_0, (u32)lbl_1_data_25F48__fzgx_offset_0, (u32)lbl_1_data_25F6C__fzgx_offset_0, (u32)lbl_1_data_25FFC__fzgx_offset_0, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, (u32)lbl_1_data_26434__fzgx_offset_0, (u32)lbl_1_data_260D4__fzgx_offset_0, (u32)lbl_1_data_260B0__fzgx_offset_0, (u32)lbl_1_data_26218__fzgx_offset_0, (u32)lbl_1_data_26068__fzgx_offset_0, (u32)lbl_1_data_2608C__fzgx_offset_0, (u32)lbl_1_data_26020__fzgx_offset_0, (u32)lbl_1_data_260F8__fzgx_offset_0, (u32)lbl_1_data_263EC__fzgx_offset_0, (u32)lbl_1_data_26314__fzgx_offset_0, (u32)lbl_1_data_26458__fzgx_offset_0, (u32)lbl_1_data_2623C__fzgx_offset_0, (u32)lbl_1_data_26410__fzgx_offset_0, (u32)lbl_1_data_26164__fzgx_offset_0, (u32)lbl_1_data_2647C__fzgx_offset_0, (u32)lbl_1_data_262A8__fzgx_offset_0, (u32)lbl_1_data_262F0__fzgx_offset_0, (u32)lbl_1_data_261D0__fzgx_offset_0, (u32)lbl_1_data_26260__fzgx_offset_0, (u32)lbl_1_data_26284__fzgx_offset_0, (u32)lbl_1_data_26380__fzgx_offset_0, (u32)lbl_1_data_263C8__fzgx_offset_0, (u32)lbl_1_data_26188__fzgx_offset_0, (u32)lbl_1_data_262CC__fzgx_offset_0, (u32)lbl_1_data_26338__fzgx_offset_0, (u32)lbl_1_data_261F4__fzgx_offset_0, (u32)lbl_1_data_26140__fzgx_offset_0, (u32)lbl_1_data_261AC__fzgx_offset_0, (u32)lbl_1_data_2611C__fzgx_offset_0, (u32)lbl_1_data_2635C__fzgx_offset_0, (u32)lbl_1_data_26044__fzgx_offset_0, (u32)lbl_1_data_26530__fzgx_offset_0, (u32)lbl_1_data_2650C__fzgx_offset_0, (u32)lbl_1_data_26578__fzgx_offset_0, (u32)lbl_1_data_26608__fzgx_offset_0, (u32)lbl_1_data_264C4__fzgx_offset_0, (u32)lbl_1_data_264A0__fzgx_offset_0, (u32)lbl_1_data_265E4__fzgx_offset_0, (u32)lbl_1_data_26554__fzgx_offset_0, (u32)lbl_1_data_264E8__fzgx_offset_0, (u32)lbl_1_data_2662C__fzgx_offset_0, (u32)lbl_1_data_263A4__fzgx_offset_0, (u32)lbl_1_data_2659C__fzgx_offset_0, (u32)lbl_1_data_265C0__fzgx_offset_0, (u32)lbl_1_data_26650__fzgx_offset_0, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x18000000, 0x00000000, 0x18000000, 0x00010000, 0x18000000, 0x00020000, 0x18000000, 0x00030000, 0x18000000, 0x00040000, 0x18000000, 0x00050000, 0x18000000, 0x00060000, 0x18000000, 0x00070000, 0x18000000, 0x00080000, 0x18000000, 0x00090000, 0x18000000, 0x000A0000, 0x18000000, 0x000B0000, 0x18000000, 0x000C0000, 0x18000000, 0x000D0000, 0x18000000, 0x000E0000, 0x18000000, 0x000F0000, 0x18000000, 0x00100000, 0x00000000, 0x5F313030, 0x30000000, 0x5F353030, 0x00000000, 0x5F313030, 0x00000000, 0x5F333030, 0x30000000, 0x5F637631, 0x00000000, 0x5F637632, 0x00000000, 0x5F637633, 0x00000000, 0x4C49505F, 0x41000000, 0x4C49505F, 0x49000000, 0x4C49505F, 0x55000000, 0x4C49505F, 0x45000000, 0x4C49505F, 0x4F000000, 0x46414345, 0x5F444546, 0x00000000, (u32)lbl_1_data_26D8C__fzgx_offset_0, (u32)lbl_1_data_26D94__fzgx_offset_0, (u32)lbl_1_data_26D9C__fzgx_offset_0, (u32)lbl_1_data_26DA4__fzgx_offset_0, (u32)lbl_1_data_26DAC__fzgx_offset_0, (u32)lbl_1_data_26DB4__fzgx_offset_0, 0x42480000, 0x696E745F, 0x30320000, 0x696E745F, 0x30330000, 0x696E745F, 0x30340000, 0x696E745F, 0x30345F66, 0x65617200, 0x696E745F, 0x30355F66, 0x65617200, 0x696E745F, 0x31340000, 0x696E745F, 0x31350000, 0x696E745F, 0x31360000, 0x696E745F, 0x31380000, 0x696E745F, 0x32300000, 0x696E745F, 0x32310000, 0x696E745F, 0x32330000, 0x696E745F, 0x32340000, 0x696E745F, 0x32370000, 0x696E745F, 0x32380000, 0x696E745F, 0x33310000, 0x696E745F, 0x33330000, 0x696E745F, 0x33340000, 0x696E745F, 0x33350000, 0x696E745F, 0x33360000, 0x696E745F, 0x33370000, 0x696E745F, 0x35300000, 0x696E745F, 0x35310000, 0x696E745F, 0x35320000, 0x696E745F, 0x636F6D5F, 0x31000000, 0x696E745F, 0x636F6D5F, 0x32000000, 0x696E745F, 0x636F6D5F, 0x33000000, 0x696E745F, 0x636F6D5F, 0x34000000, 0x696E745F, 0x636F6D5F, 0x35000000, 0x696E745F, 0x636F6D5F, 0x36000000, 0x696E745F, 0x636F6D5F, 0x37000000, 0x696E745F, 0x636F6D5F, 0x38000000, 0x696E745F, 0x636F6D5F, 0x39000000, 0x696E745F, 0x636F6D5F, 0x31300000, 0x696E745F, 0x636F6D32, 0x5F310000, 0x696E745F, 0x636F6D32, 0x5F320000, 0x696E745F, 0x636F6D32, 0x5F330000, 0x696E745F, 0x636F6D32, 0x5F340000, 0x696E745F, 0x636F6D32, 0x5F350000, 0x696E745F, 0x636F6D32, 0x5F360000, 0x696E745F, 0x636F6D32, 0x5F370000, 0x696E745F, 0x636F6D32, 0x5F380000, 0x696E745F, 0x636F6D32, 0x5F390000, 0x696E745F, 0x636F6D32, 0x5F313000, (u32)lbl_1_data_26DDC__fzgx_offset_0, (u32)lbl_1_data_26DE4__fzgx_offset_0, (u32)lbl_1_data_26DEC__fzgx_offset_0, (u32)lbl_1_data_26DF4__fzgx_offset_0, (u32)lbl_1_data_26E00__fzgx_offset_0, (u32)lbl_1_data_26E0C__fzgx_offset_0, (u32)lbl_1_data_26E14__fzgx_offset_0, (u32)lbl_1_data_26E1C__fzgx_offset_0, (u32)lbl_1_data_26E24__fzgx_offset_0, (u32)lbl_1_data_26E2C__fzgx_offset_0, (u32)lbl_1_data_26E34__fzgx_offset_0, (u32)lbl_1_data_26E3C__fzgx_offset_0, (u32)lbl_1_data_26E44__fzgx_offset_0, (u32)lbl_1_data_26E4C__fzgx_offset_0, (u32)lbl_1_data_26E54__fzgx_offset_0, (u32)lbl_1_data_26E5C__fzgx_offset_0, (u32)lbl_1_data_26E5C__fzgx_offset_0, (u32)lbl_1_data_26E64__fzgx_offset_0, (u32)lbl_1_data_26E6C__fzgx_offset_0, (u32)lbl_1_data_26E74__fzgx_offset_0, (u32)lbl_1_data_26E7C__fzgx_offset_0, (u32)lbl_1_data_26E84__fzgx_offset_0, (u32)lbl_1_data_26E8C__fzgx_offset_0, (u32)lbl_1_data_26E94__fzgx_offset_0, (u32)lbl_1_data_26E9C__fzgx_offset_0, (u32)lbl_1_data_26EA4__fzgx_offset_0, (u32)lbl_1_data_26EB0__fzgx_offset_0, (u32)lbl_1_data_26EBC__fzgx_offset_0, (u32)lbl_1_data_26EC8__fzgx_offset_0, (u32)lbl_1_data_26ED4__fzgx_offset_0, (u32)lbl_1_data_26EE0__fzgx_offset_0, (u32)lbl_1_data_26EEC__fzgx_offset_0, (u32)lbl_1_data_26EF8__fzgx_offset_0, (u32)lbl_1_data_26F04__fzgx_offset_0, (u32)lbl_1_data_26F10__fzgx_offset_0, (u32)lbl_1_data_26F1C__fzgx_offset_0, (u32)lbl_1_data_26F28__fzgx_offset_0, (u32)lbl_1_data_26F34__fzgx_offset_0, (u32)lbl_1_data_26F40__fzgx_offset_0, (u32)lbl_1_data_26F4C__fzgx_offset_0, (u32)lbl_1_data_26F58__fzgx_offset_0, (u32)lbl_1_data_26F64__fzgx_offset_0, (u32)lbl_1_data_26F70__fzgx_offset_0, (u32)lbl_1_data_26F7C__fzgx_offset_0, (u32)lbl_1_data_26F88__fzgx_offset_0, 0x67617A65, 0x6C6C655F, 0x626F6172, 0x64000000, 0x424F4152, 0x44000000, 0x6A6F6479, 0x5F626F61, 0x72640000, 0x73746577, 0x6172745F, 0x626F6172, 0x64000000, 0x62616261, 0x5F626F61, 0x72640000, 0x676F726F, 0x685F626F, 0x61726400, 0x7069636F, 0x5F626F61, 0x72640000, 0x66616C63, 0x6F6E5F62, 0x6F617264, 0x00000000, 0x6F63746D, 0x616E5F62, 0x6F617264, 0x00000000, 0x6561645F, 0x626F6172, 0x64000000, 0x6A616D65, 0x735F626F, 0x61726400, 0x62696C6C, 0x795F626F, 0x61726400, 0x6B617465, 0x5F626F61, 0x72640000, 0x7A6F6461, 0x5F626F61, 0x72640000, 0x6A61636B, 0x5F626F61, 0x72640000, 0x7265785F, 0x626F6172, 0x64000000, 0x676F7264, 0x6F6E5F62, 0x6F617264, 0x00000000, 0x67757374, 0x65725F62, 0x6F617264, 0x00000000, 0x62656173, 0x746D616E, 0x5F626F61, 0x72640000, 0x6C656F6E, 0x5F626F61, 0x72640000, 0x6172726F, 0x775F626F, 0x61726400, 0x6D72735F, 0x626F6172, 0x64000000, 0x7368696F, 0x5F626F61, 0x72640000, 0x6E65656C, 0x73656E5F, 0x626F6172, 0x64000000, 0x6D696368, 0x61656C5F, 0x626F6172, 0x64000000, 0x626C6F6F, 0x645F626F, 0x61726400, 0x74616E61, 0x6B615F62, 0x6F617264, 0x00000000, 0x64726171, 0x5F626F61, 0x72640000, 0x726F6765, 0x725F626F, 0x61726400, 0x636C6173, 0x685F626F, 0x61726400, 0x73686164, 0x6F775F62, 0x6F617264, 0x00000000, 0x626F7373, 0x5F626F61, 0x72640000, 0x646F6E5F, 0x626F6172, 0x64000000, 0x64696769, 0x626F795F, 0x626F6172, 0x64000000, 0x6461695F, 0x626F6172, 0x64000000, 0x73706164, 0x655F626F, 0x61726400, 0x64616967, 0x6F726F68, 0x5F626F61, 0x72640000, 0x70726973, 0x69615F62, 0x6F617264, 0x00000000, 0x6C696C79, 0x5F626F61, 0x72640000, 0x706A5F62, 0x6F617264, 0x00000000, 0x7171715F, 0x626F6172, 0x64000000, 0x73686572, 0x6C6F636B, 0x5F626F61, 0x72640000, 0x676F6D61, 0x5F626F61, 0x72640000, 0x73616E5F, 0x626F6172, 0x64000000, 0x67656E5F, 0x626F6172, 0x64000000, 0x74616E61, 0x6B615F6D, 0x656B6100, 0x4D454B41, 0x00000000, 0x6172726F, 0x775F6F77, 0x6C000000, 0x4F574C00, 0x6E65656C, 0x73656E5F, 0x73746963, 0x6B000000, 0x54554500, 0x64616967, 0x6F726F68, 0x5F6B6174, 0x616E6100, 0x4B415441, 0x4E410000, 0x646F6E5F, 0x73746963, 0x6B000000, 0x706A5F6F, 0x70000000, 0x4F500000, 0x73706164, 0x655F6361, 0x72645F61, 0x63653031, 0x00000000, 0x43415244, 0x5F414345, 0x30310000, 0x73706164, 0x655F6361, 0x72645F61, 0x63653032, 0x00000000, 0x43415244, 0x5F414345, 0x30320000, 0x73706164, 0x655F6361, 0x72645F61, 0x63653033, 0x00000000, 0x43415244, 0x5F414345, 0x30330000, 0x73706164, 0x655F6361, 0x72645F61, 0x63653034, 0x00000000, 0x43415244, 0x5F414345, 0x30340000, 0x73706164, 0x655F6361, 0x72645F6A, 0x6F6B6572, 0x30310000, 0x43415244, 0x5F4A4F4B, 0x45523031, 0x00000000, 0x73706164, 0x655F6361, 0x72645F6A, 0x6F6B6572, 0x30320000, 0x43415244, 0x5F4A4F4B, 0x45523032, 0x00000000, 0x73706164, 0x655F6361, 0x72645F6A, 0x6F6B6572, 0x30330000, 0x43415244, 0x5F4A4F4B, 0x45523033, 0x00000000, 0x73706164, 0x655F6361, 0x72645F6A, 0x6F6B6572, 0x30340000, 0x43415244, 0x5F4A4F4B, 0x45523034, 0x00000000, 0x73706164, 0x655F6261, 0x6C6C3031, 0x00000000, 0x42414C4C, 0x30310000, 0x73706164, 0x655F6261, 0x6C6C3032, 0x00000000, 0x42414C4C, 0x30320000, 0x73706164, 0x655F6261, 0x6C6C3033, 0x00000000, 0x42414C4C, 0x30330000, 0x73706164, 0x655F6261, 0x6C6C3034, 0x00000000, 0x42414C4C, 0x30340000, 0x73706164, 0x655F6261, 0x6C6C3035, 0x00000000, 0x42414C4C, 0x30350000, 0x73706164, 0x655F6261, 0x6C6C3036, 0x00000000, 0x42414C4C, 0x30360000, 0x73706164, 0x655F6261, 0x6C6C3037, 0x00000000, 0x42414C4C, 0x30370000, 0x73706164, 0x655F6261, 0x6C6C3038, 0x00000000, 0x42414C4C, 0x30380000, 0x00000000, (u32)lbl_1_data_27048__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00010000, (u32)lbl_1_data_27060__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00020000, (u32)lbl_1_data_2706C__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00030000, (u32)lbl_1_data_2707C__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00040000, (u32)lbl_1_data_27088__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00050000, (u32)lbl_1_data_27094__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00060000, (u32)lbl_1_data_270A0__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00070000, (u32)lbl_1_data_270B0__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00080000, (u32)lbl_1_data_270C0__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00090000, (u32)lbl_1_data_270CC__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x000A0000, (u32)lbl_1_data_270D8__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x000B0000, (u32)lbl_1_data_270E4__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x000C0000, (u32)lbl_1_data_270F0__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x000D0000, (u32)lbl_1_data_270FC__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x000E0000, (u32)lbl_1_data_27108__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x000F0000, (u32)lbl_1_data_27114__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00100000, (u32)lbl_1_data_27124__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00110000, (u32)lbl_1_data_27134__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00120000, (u32)lbl_1_data_27144__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00130000, (u32)lbl_1_data_27150__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00140000, (u32)lbl_1_data_2715C__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00150000, (u32)lbl_1_data_27168__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00160000, (u32)lbl_1_data_27174__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00170000, (u32)lbl_1_data_27184__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00180000, (u32)lbl_1_data_27194__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00190000, (u32)lbl_1_data_271A0__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x001A0000, (u32)lbl_1_data_271B0__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x001B0000, (u32)lbl_1_data_271BC__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x001C0000, (u32)lbl_1_data_271C8__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x001D0000, (u32)lbl_1_data_271D4__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x001E0000, (u32)lbl_1_data_271E4__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x001F0000, (u32)lbl_1_data_271F0__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00200000, (u32)lbl_1_data_271FC__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00210000, (u32)lbl_1_data_2720C__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00220000, (u32)lbl_1_data_27218__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00230000, (u32)lbl_1_data_27224__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00240000, (u32)lbl_1_data_27234__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00250000, (u32)lbl_1_data_27244__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00260000, (u32)lbl_1_data_27250__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00270000, (u32)lbl_1_data_2725C__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00280000, (u32)lbl_1_data_27268__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00290000, (u32)lbl_1_data_27278__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x002A0000, (u32)lbl_1_data_27284__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x002B0000, (u32)lbl_1_data_27290__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00190001, (u32)lbl_1_data_2729C__fzgx_offset_0, (u32)lbl_1_data_272A8__fzgx_offset_0, 0x00130001, (u32)lbl_1_data_272B0__fzgx_offset_0, (u32)lbl_1_data_272BC__fzgx_offset_0, 0x00160001, (u32)lbl_1_data_272C0__fzgx_offset_0, (u32)lbl_1_data_272D0__fzgx_offset_0, 0x00230001, (u32)lbl_1_data_272D4__fzgx_offset_0, (u32)lbl_1_data_272E4__fzgx_offset_0, 0x001F0001, (u32)lbl_1_data_272EC__fzgx_offset_0, (u32)lbl_1_data_272D0__fzgx_offset_0, 0x00260001, (u32)lbl_1_data_272F8__fzgx_offset_0, (u32)lbl_1_data_27300__fzgx_offset_0, 0x00220001, (u32)lbl_1_data_27304__fzgx_offset_0, (u32)lbl_1_data_27318__fzgx_offset_0, 0x00220002, (u32)lbl_1_data_27324__fzgx_offset_0, (u32)lbl_1_data_27338__fzgx_offset_0, 0x00220003, (u32)lbl_1_data_27344__fzgx_offset_0, (u32)lbl_1_data_27358__fzgx_offset_0, 0x00220004, (u32)lbl_1_data_27364__fzgx_offset_0, (u32)lbl_1_data_27378__fzgx_offset_0, 0x00220005, (u32)lbl_1_data_27384__fzgx_offset_0, (u32)lbl_1_data_27398__fzgx_offset_0, 0x00220006, (u32)lbl_1_data_273A8__fzgx_offset_0, (u32)lbl_1_data_273BC__fzgx_offset_0, 0x00220007, (u32)lbl_1_data_273CC__fzgx_offset_0, (u32)lbl_1_data_273E0__fzgx_offset_0, 0x00220008, (u32)lbl_1_data_273F0__fzgx_offset_0, (u32)lbl_1_data_27404__fzgx_offset_0, 0x00220009, (u32)lbl_1_data_27414__fzgx_offset_0, (u32)lbl_1_data_27424__fzgx_offset_0, 0x0022000A, (u32)lbl_1_data_2742C__fzgx_offset_0, (u32)lbl_1_data_2743C__fzgx_offset_0, 0x0022000B, (u32)lbl_1_data_27444__fzgx_offset_0, (u32)lbl_1_data_27454__fzgx_offset_0, 0x0022000C, (u32)lbl_1_data_2745C__fzgx_offset_0, (u32)lbl_1_data_2746C__fzgx_offset_0, 0x0022000D, (u32)lbl_1_data_27474__fzgx_offset_0, (u32)lbl_1_data_27484__fzgx_offset_0, 0x0022000E, (u32)lbl_1_data_2748C__fzgx_offset_0, (u32)lbl_1_data_2749C__fzgx_offset_0, 0x0022000F, (u32)lbl_1_data_274A4__fzgx_offset_0, (u32)lbl_1_data_274B4__fzgx_offset_0, 0x00220010, (u32)lbl_1_data_274BC__fzgx_offset_0, (u32)lbl_1_data_274CC__fzgx_offset_0, 0x00000042, 0xC7382A7E, 0x25735F77, 0x696E2E6D, 0x74610000, 0x25735F74, 0x6573742E, 0x6D746100, 0x25735F68, 0x616E642E, 0x6D746100, 0x25735F66, 0x6163652E, 0x6D746100, 0x25735F6C, 0x69702E6D, 0x74610000, 0x25735F65, 0x79652E6D, 0x74610000, 0x25732E6D, 0x74610000, 0x2E6D7461, 0x00000000, 0x25735F63, 0x6F6D6D6F, 0x6E2E6D61, 0x6C000000, 0x54455F52, 0x00000000, 0x54455F52, 0x4D000000, 0x4C495000, 0x45594500, 0x41434345, 0x00000000, 0x2F636861, 0x72612F61, 0x72632F00, 0x5F73656C, 0x00000000, 0x2E617263, 0x2E6C7A00}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u8 fzgx_pool_native_lbl_1_data_209C0_lock_6ED8[8] = {0x63, 0x68, 0x61, 0x72, 0x61, 0x00, 0x00, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static char fzgx_pool_native_lbl_1_data_209C0_fmt_6EE0[0xC] = {0x25, 0x73, 0x25, 0x73, 0x25, 0x73, 0x2E, 0x74, 0x70, 0x6C, 0x00, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union {u32 words[227]; u8 view[0x7278 - 0x6EEC];} fzgx_pool_native_lbl_1_data_209C0_unlock_6EEC = {{0x2E2E0000, 0x46414345, 0x5F4C4155, 0x47480000, 0x626F6479, 0x20000000, 0x68616E64, 0x72000000, 0x68616E64, 0x6C000000, 0x66616365, 0x20000000, 0x6C697020, 0x20000000, 0x65796520, 0x20000000, 0x61636365, 0x20000000, 0x3E000000, 0x20000000, 0x25730000, 0x3A5B2530, 0x33645D00, 0x5B25352E, 0x31662F25, 0x352E3166, 0x5D000000, 0x2573200A, 0x00000000, (u32)lbl_1_bss_6E990__fzgx_offset_0, 0x00000001, 0x25735F25, 0x64000000, 0x3E5B2532, 0x645D2573, 0x200A0000, 0x205B2532, 0x645D2573, 0x200A0000, 0x2D3E204C, 0x69737420, 0x506C6179, 0x20202028, 0x4C522062, 0x7574746F, 0x6E290000, 0x2D3E204E, 0x6F726D61, 0x6C20506C, 0x61792028, 0x4C522062, 0x7574746F, 0x6E290000, 0x5B25735D, 0x200A0000, 0x48490000, 0x33303030, 0x00000000, 0x31303030, 0x00000000, 0x35303000, 0x31303000, 0x63686172, 0x615F636F, 0x6C203A20, 0x5B25645D, 0x0A000000, 0x63686172, 0x5F646973, 0x70203A20, 0x5B25735D, 0x0A000000, 0x4F4E0000, 0x4F464600, 0x62675F63, 0x6F6C6F72, 0x20203A20, 0x5B25735D, 0x0A000000, 0x47524159, 0x00000000, 0x424C4143, 0x4B000000, 0x70657273, 0x70656374, 0x20203A20, 0x5B25342E, 0x31665D0A, 0x00000000, 0x5B25735F, 0x25645D20, 0x0A000000, 0x564F4C20, 0x3A202534, 0x2E326620, 0x0A000000, (u32)fn_1_9012C__fzgx_offset_3D4, (u32)fn_1_9012C__fzgx_offset_40C, (u32)fn_1_9012C__fzgx_offset_440, (u32)fn_1_9012C__fzgx_offset_468, (u32)fn_1_9012C__fzgx_offset_488, (u32)fn_1_9012C__fzgx_offset_4A8, (u32)fn_1_9012C__fzgx_offset_4FC, (u32)fn_1_9012C__fzgx_offset_53C, (u32)fn_1_9012C__fzgx_offset_5B0, (u32)fn_1_9012C__fzgx_offset_624, (u32)fn_1_9012C__fzgx_offset_698, (u32)fn_1_9012C__fzgx_offset_70C, (u32)fn_1_9012C__fzgx_offset_780, (u32)fn_1_9012C__fzgx_offset_7EC, 0x5B25735D, 0x0A000000, 0x2020201F, 0x2025342E, 0x316C660A, 0x00000000, 0x5B454E44, 0x5D0A0000, 0x544F5441, 0x4C5B2535, 0x2E316C66, 0x2F25352E, 0x316C665D, 0x00000000, 0x544F5441, 0x4C5B2D2D, 0x2D2D2D2F, 0x2D2D2D2D, 0x2D5D0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x5F434152, 0x445F4A4F, 0x4B455200, 0x5F434152, 0x445F4143, 0x45000000, 0x5F42414C, 0x4C000000, 0x25735F54, 0x55450000, 0x25732573, 0x00000000, 0x494E545F, 0x00000000, 0x494E545F, 0x31340000, 0x47555354, 0x45525F48, 0x454C4D45, 0x54000000, 0x47555354, 0x45525F4D, 0x4F484900, 0x47555354, 0x45525F41, 0x46524F00, 0x47555354, 0x45525F4D, 0x4F48495F, 0x44000000, 0x494E545F, 0x31350000, 0x474F524F, 0x485F4649, 0x47555245, 0x00000000, 0x53594152, 0x494E5F52, 0x5F460000, 0x25735F54, 0x455F524D, 0x00000000, 0x25735F54, 0x455F5200, 0x25735F46, 0x41434500, 0x494E5400, 0x494E545F, 0x46414345, 0x5F544553, 0x54000000, 0x25735F4C, 0x49500000, 0x25735F45, 0x59450000, 0x25735F25, 0x73000000, 0x6D6F7469, 0x6F6E0000, 0x25732E73, 0x6B6C0000, 0x25735F68, 0x616E6472, 0x2E736B6C, 0x00000000, 0x25735F68, 0x616E646C, 0x2E736B6C, 0x00000000, 0x25735F66, 0x6163652E, 0x736B6C00, 0x25735F6C, 0x69702E73, 0x6B6C0000, 0x25735F65, 0x79652E73, 0x6B6C0000, 0x2E736B6C, 0x00000000, 0x726F622E, 0x63000000, 0x73616E5F, 0x626F6172, 0x642E736B, 0x6C000000, 0x67656E5F, 0x626F6172, 0x642E736B, 0x6C000000, 0x676F6D61, 0x5F626F61, 0x72642E73, 0x6B6C0000}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static char fzgx_pool_native_lbl_1_data_209C0_fmt_7278[0xC] = {0x25, 0x73, 0x25, 0x73, 0x2E, 0x74, 0x70, 0x6C, 0x00, 0x00, 0x00, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static char fzgx_pool_native_lbl_1_data_209C0_fmt_7284[4] = {0x25, 0x73, 0x25, 0x73}; /* fzgx-allow: A1 measured pool bytes and bindings */


#pragma section code_type ".fzgxpool"
static void fzgx_base_order_data(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: the TU references .data before its other sections */
    s = *(u8 *)&fzgx_pool_native_lbl_1_data_209C0_gap_0;
    s = *(u8 *)&fzgx_pool_native_lbl_1_data_209C0_lock_6ED8;
    s = *(u8 *)&fzgx_pool_native_lbl_1_data_209C0_fmt_6EE0;
    s = *(u8 *)&fzgx_pool_native_lbl_1_data_209C0_fmt_7278;
    s = *(u8 *)&fzgx_pool_native_lbl_1_data_209C0_fmt_7284;
}
#pragma section code_type ".text"

void fn_1_96230(Fn196230Obj *obj, s32 idx, u32 mask1, u32 mask2, s32 flag) {
    char buf[0x40];
    s32 ok[5][4];
    const char *name;
    s32 i;
    s32 j;
    s32 id;

    
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            ok[i][j] = 0;
        }
    }
    name = fzgx_pool_native_lbl_1_data_209C0_names.view[idx];
    for (i = 0; i < 5; i++) {
        if (!MASK_BIT(mask1, i)) {
            continue;
        }
        for (j = 0; j < 4; j++) {
            if (!MASK_BIT(mask2, j)) {
                continue;
            }
            if (flag == 0 && obj->ids[i] != -1 &&
                (mask2 == 0x80000000 || mask2 == 0x40000000 || mask2 == 0x20000000 ||
                 mask2 == 0x10000000)) {
                sprintf(buf, fzgx_pool_native_lbl_1_data_209C0_fmt_6EE0, name, fzgx_pool_sDirs[i], fzgx_pool_sExts[0]);
            } else {
                sprintf(buf, fzgx_pool_native_lbl_1_data_209C0_fmt_6EE0, name, fzgx_pool_sDirs[i], fzgx_pool_sExts[j]);
            }
            if (flag) {
                fn_1_12AB38(fzgx_pool_native_lbl_1_data_209C0_lock_6ED8);
                ok[i][j] = fn_1_465D0(buf, 1) >= 0;
                fn_1_12AB38(fzgx_pool_native_lbl_1_data_209C0_unlock_6EEC.view);
            } else {
                void *file;
                if (obj->ids[i] != -1) {
                    fn_1_12A2B8(1);
                    fn_1_12A2D0(obj->ids[i]);
                } else {
                    fn_1_12A2B8(0);
                }
                fn_1_12AB38(fzgx_pool_native_lbl_1_data_209C0_lock_6ED8);
                file = fn_1_12AC00(buf);
                obj->files[i][j] = file;
                ok[i][j] = ((u32)file | -(u32)file) >> 31;
                fn_1_12AB38(fzgx_pool_native_lbl_1_data_209C0_unlock_6EEC.view);
            }
            if (ok[i][j] == 0) {
                sprintf(buf, fzgx_pool_native_lbl_1_data_209C0_fmt_7278, name, fzgx_pool_sDirs[i]);
                if (flag) {
                    fn_1_12AB38(fzgx_pool_native_lbl_1_data_209C0_lock_6ED8);
                    ok[i][j] = fn_1_465D0(buf, 1) >= 0;
                    fn_1_12AB38(fzgx_pool_native_lbl_1_data_209C0_unlock_6EEC.view);
                } else {
                    void *file;
                    if (obj->ids[i] != -1) {
                        fn_1_12A2B8(1);
                        fn_1_12A2D0(obj->ids[i]);
                    } else {
                        fn_1_12A2B8(0);
                    }
                    fn_1_12AB38(fzgx_pool_native_lbl_1_data_209C0_lock_6ED8);
                    file = fn_1_12AC00(buf);
                    obj->files[i][j] = file;
                    ok[i][j] = ((u32)file | -(u32)file) >> 31;
                    fn_1_12AB38(fzgx_pool_native_lbl_1_data_209C0_unlock_6EEC.view);
                }
            }
        }
        for (j = 0; j < 4; j++) {
            if (ok[i][j]) {
                sprintf(buf, fzgx_pool_native_lbl_1_data_209C0_fmt_7284, name, fzgx_pool_sPacks[i]);
                if (flag) {
                    fn_1_12AB38(fzgx_pool_native_lbl_1_data_209C0_lock_6ED8);
                    fn_1_465D0(buf, 1);
                    fn_1_12AB38(fzgx_pool_native_lbl_1_data_209C0_unlock_6EEC.view);
                } else {
                    if (obj->ids[i] != -1) {
                        fn_1_12A2B8(1);
                        fn_1_12A2D0(obj->ids[i]);
                    } else {
                        fn_1_12A2B8(0);
                    }
                    fn_1_12AB38(fzgx_pool_native_lbl_1_data_209C0_lock_6ED8);
                    obj->handles[i] = fn_1_12ADA0(buf, obj->files[i][j]);
                    fn_1_12AB38(fzgx_pool_native_lbl_1_data_209C0_unlock_6EEC.view);
                }
                break;
            }
        }
    }
    if (flag == 0) {
        Fn196230Obj *scan;
        id = -1;
        for (j = 0, scan = obj; j < 5; scan = (Fn196230Obj *)((u8 *)scan + 4), j++) {
            if (scan->ids[0] != -1) {
                id = obj->ids[j];
                break;
            }
        }
        if (id != -1) {
            fn_1_12A2B8(1);
            fn_1_12A2D0(id);
        } else {
            fn_1_12A2B8(0);
        }
    }
}
/* fzgx:end fn_1_96230 */

/* fzgx:begin fn_1_96630 */
typedef struct Fn196630Object Fn196630Object;

struct Fn196630Object {
    u8 unk_00[0x88];
    void *value_88;
};

void fn_1_96630(Fn196630Object *object, void *arg1, void *arg2) {
    fn_1_96230(object, object->value_88, arg1, arg2, 0);
}
/* fzgx:end fn_1_96630 */

/* fzgx:begin fn_1_96664 */
void fn_1_96664(void *arg0, void *arg1, void *arg2) {
    fn_1_96230(0, arg0, arg1, arg2, 1);
}
/* fzgx:end fn_1_96664 */

/* fzgx:begin fn_1_966A0 */
typedef struct Fn1966A0Object Fn1966A0Object;
struct Fn1966A0Object {
    u32 entries[0x39];
    u32 resource_e4;
    u8 unk_E8[0x10];
    u32 resource_f8;
};

extern void fn_1_12A2D0(s32 arg0);
extern void fn_80071718(u32 arg0);
extern void fn_800711A8(u32 arg0);

void fn_1_966A0(Fn1966A0Object *object) {
    u8 *slot;
    u8 *group;
    u8 *outer;
    int i;
    int j;
    s32 value;
    u8 *walk;

    group = (u8 *)object;
    outer = (u8 *)object;
    for (i = 0; i < 5; i++) {
        slot = group;
        for (j = 0; j < 4; j++) {
            if (((Fn1966A0Object *)slot)->resource_f8 != 0) {
                if (*(s32 *)(outer + 4) != -1) {
                    fn_1_12A2D0(*(s32 *)(outer + 4));
                }
                fn_80071718(((Fn1966A0Object *)slot)->resource_f8);
                ((Fn1966A0Object *)slot)->resource_f8 = 0;
            }
            slot += 4;
        }
        if (((Fn1966A0Object *)outer)->resource_e4 != 0) {
            if (*(s32 *)(outer + 4) != -1) {
                fn_1_12A2D0(*(s32 *)(outer + 4));
            }
            fn_800711A8(((Fn1966A0Object *)outer)->resource_e4);
            ((Fn1966A0Object *)outer)->resource_e4 = 0;
        }
        group += 0x10;
        outer += 4;
    }

    value = -1;
    walk = (u8 *)object;
    for (i = 0; i < 5; i++) {
        if (*(s32 *)(walk + 4) != -1) {
            value = object->entries[i + 1];
            break;
        }
        walk += 4;
    }
    if (value != -1) {
        fn_1_12A2D0(value);
    }
}
/* fzgx:end fn_1_966A0 */

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

/* fzgx:begin fn_1_968FC */
typedef struct Fn1968FCChild Fn1968FCChild;
typedef struct Fn1968FCObject Fn1968FCObject;

struct Fn1968FCChild {
    u8 unk_00[0x08];
    u32 unk_08;
    u8 unk_0c[0x10];
    u32 unk_1c;
};

struct Fn1968FCObject {
    u8 unk_00[0x1c];
    Fn1968FCChild *unk_1c;
    void *unk_20;
};

void fn_1_968FC(Fn1968FCObject *object) {
    if (object->unk_20 != 0) {
        fn_1_12ABB4(object->unk_20);
        object->unk_20 = 0;
    }

    if (object->unk_1c != 0) {
        object->unk_1c->unk_1c = 0;
        object->unk_1c->unk_08 = 0;
        fn_1_41850(object->unk_1c);
        object->unk_1c = 0;
    }
}
/* fzgx:end fn_1_968FC */

/* fzgx:begin fn_1_96968 noprologue */
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
extern void GXGetScissor(u32 *left, u32 *top, u32 *width, u32 *height);
extern void GXGetProjectionv(f32* out);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
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
extern u8 lbl_1_bss_6DA5C__fzgx_offset_1E;
extern u8 lbl_1_bss_6DA5C__fzgx_offset_1F[5];
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

/* fzgx:begin fn_1_969E8 noprologue */
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
extern void GXGetScissor(u32 *left, u32 *top, u32 *width, u32 *height);
extern void GXGetProjectionv(f32* out);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
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
extern u8 lbl_1_bss_6DA5C__fzgx_offset_1E;
extern u8 lbl_1_bss_6DA5C__fzgx_offset_1F[5];
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

/* fzgx:begin fn_1_96A68 noprologue */
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
extern void GXGetScissor(u32 *left, u32 *top, u32 *width, u32 *height);
extern void GXGetProjectionv(f32* out);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
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
extern u8 lbl_1_bss_6DA5C__fzgx_offset_1E;
extern u8 lbl_1_bss_6DA5C__fzgx_offset_1F[5];
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

/* fzgx:begin fn_1_96AE8 */
void fn_1_96AE8(void *base, void *arg1) {
    fn_1_96B14(base, arg1, lbl_1_bss_6E98C);
}
/* fzgx:end fn_1_96AE8 */

/* fzgx:begin fn_1_96B14 noprologue */
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
extern void GXGetScissor(u32 *left, u32 *top, u32 *width, u32 *height);
extern void GXGetProjectionv(f32* out);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
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
extern u8 lbl_1_bss_6DA5C__fzgx_offset_1E;
extern u8 lbl_1_bss_6DA5C__fzgx_offset_1F[5];
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

/* fzgx:begin fn_1_96BC0 noprologue */
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
extern void GXGetScissor(u32 *left, u32 *top, u32 *width, u32 *height);
extern void GXGetProjectionv(f32* out);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
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
extern u8 lbl_1_bss_6DA5C__fzgx_offset_1E;
extern u8 lbl_1_bss_6DA5C__fzgx_offset_1F[5];
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

/* fzgx:begin fn_1_96C40 */
#include "dolphin/hw_regs.h"

extern void fn_1_12ABB4(void *arg0);
extern void fn_1_96230(void *arg0, void *arg1, void *arg2, void *arg3, int arg4);
extern void fn_1_41850(void *arg0);
extern u32 lbl_1_bss_6E98C;
extern u16 fn_1_96B14(void *base, void *arg1, s32 index);
extern s32 fn_80083BCC(void *arg0, void *arg1);
extern void ADXT_Stop(u32 arg0);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, u8 *, u32);
extern void fn_80008BEC(void *, u32, u32);

extern const char *lbl_1_data_20D1C[];
extern void sprintf(char *buffer, u8 *format, ...);
extern s32 fn_1_12A32C(char *buffer);
extern s16 fn_1_98104(void);


typedef struct {
    u8 r, g, b, a;
} RobColor;

extern u32 lbl_801A6D00;
extern u32 GXLoadPosMtxImm(u32, u32);
extern u32 lbl_8006DCA4(void);
extern void fn_8003462C(u32, u32, u32);
extern void fn_8007245C(u32);
extern void fn_800724C8(void);
extern void fn_800725DC(RobColor *);
extern void fn_80072614(RobColor *);
extern void fn_80072864(u32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072EDC(s32, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073678(u32);
extern void fn_80073C6C(s32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);

/* Pool primer: reproduces the TU literal pool (lbl_1_rodata_3E48 .. +0x1D0) ahead of
   this function's own initializers and literals; .fzgxpool is dropped at integration. */
extern void fzgx_sink(const void *p);
extern void fzgx_sinkf(f32 f);
extern s32 fzgx_int;

#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_primer(void) {
    /* lbl_1_rodata_3E48 / 3E70: string pointer tables (relocated words, zero in the file) */
    u32 names[0x49] = {0};

    fzgx_sink(names);
    fzgx_sinkf(0.0f);
    fzgx_sinkf(1.0f);
    fzgx_sinkf(100.0f);
    fzgx_sinkf(180.0f);
    fzgx_sinkf(32767.0f);
    fzgx_sinkf((f32)fzgx_int);
}

__declspec(section ".fzgxpool") void fzgx_pool_primer2(void) {
    u32 words[36] = {
        0xFFFFFFFF, 0xBF800000, 0xFFFFFFFF, 0x425C0000, 0x41F00000, 0x447A0000,
        0x404040FF, 0x00000000, 0x00000000, 0x00000000,
        0x3B963DC5, 0xBD6DD053, 0xBD953A3F, 0x3B963DC5, 0xBD6DD053, 0x3CF0307F,
        0xBB963DC5, 0xBD6DD053, 0xBD953A3F, 0xBB963DC5, 0xBD6DD053, 0x3CF0307F,
        0x43360B61, 0x3E4F5C29, 0x3D851EB8, 0x3DAE147B, 0x3FA99999, 0x9999999A,
        0x3D4CCCCD, 0x3BA3D70A, 0xBC8F5C29, 0x477FFF00, 0x43300000, 0x00000000,
        0x42480000, 0xBF800000,
    };

    fzgx_sink(words);
}

/* GX write-gather FIFO: every store is a hardware write, hence volatile. */
#define GX_FIFO_F32 (*(volatile f32 *)GX_FIFO_BASE)

#pragma defer_codegen on
static void fn_1_96C40_grid(s32 cx, s32 cz);

void fn_1_96C40(void *arg0) {
    RobColor colA = {0x40, 0x40, 0x60, 0x80};
    RobColor colB = {0x00, 0x00, 0x00, 0x00};
    s32 cx;
    s32 cz;
    RobColor c0;
    RobColor c1;

    lbl_8006DCA4();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    cx = (s32)*(f32 *)((u8 *)arg0 + 0xA8);
    cz = (s32)*(f32 *)((u8 *)arg0 + 0xB0);
    fn_800724C8();
    fn_8007245C(0x2200);
    fn_80074788(1);
    c0 = colA;
    fn_800725DC(&c0);
    c1 = colB;
    fn_80072614(&c1);
    fn_800747D0(4, 0, 0, 0, 0, 0, 2);
    fn_80074660(0);
    fn_80073678(1);
    fn_80073C6C(0);
    fn_80072AB0(0, 0, 0);
    fn_800734A8(0, 255, 255, 4);
    fn_80072EDC(0, 4);
    fn_80072864(0);
    fn_1_96C40_grid(cx, cz);
}

/* Draws a 21x21 checkerboard of unit quads around (cx, cz), one colour per pass. */
static inline void fn_1_96C40_grid(s32 cx, s32 cz) {
    s32 j;
    s32 i;
    s32 pass;
    f32 z1;
    f32 z0;
    f32 x1;
    f32 x0;

    for (pass = 0; pass < 2; pass++) {
        for (i = -10; i <= 10; i++) {
            x0 = (f32)(cx + i) - 0.5f;
            x1 = 0.5f + (f32)(cx + i);
            for (j = -10; j <= 10; j++) {
                if ((u32)pass == ((i + j) & 1)) {
                    continue;
                }
                z0 = (f32)(cz + j) - 0.5f;
                z1 = 0.5f + (f32)(cz + j);
                fn_8003462C(0x80, 7, 4);
                GX_FIFO_F32 = x0;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = z0;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = x1;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = z0;
                GX_FIFO_F32 = 1.0f;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = x1;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = z1;
                GX_FIFO_F32 = 1.0f;
                GX_FIFO_F32 = 1.0f;
                GX_FIFO_F32 = x0;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = z1;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = 1.0f;
            }
        }
        {
            RobColor colC = {0x00, 0x20, 0x40, 0x80};

            fn_800725DC(&colC);
        }
    }
}
#pragma defer_codegen reset
/* fzgx:end fn_1_96C40 */

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

/* fzgx:begin fn_1_97174 */
typedef struct Fn197174Owner Fn197174Owner;
typedef struct Fn197174Root Fn197174Root;
typedef struct Fn197174Entry Fn197174Entry;

struct Fn197174Owner {
    u8 unk_00[0x14];
    u8 *base;
};

struct Fn197174Root {
    u8 unk_00[0x08];
    u16 count;
};

struct Fn197174Entry {
    u8 unk_00[0x1C];
    u32 offset;
};

extern Fn197174Root *fn_1_41BDC(void);
extern Fn197174Entry *fn_1_41B18(Fn197174Owner *owner, void *arg1, s32 index);

s32 fn_1_97174(Fn197174Owner *owner, void *arg1, void *arg2) {
    Fn197174Root *root = fn_1_41BDC();
    s32 index = 0;

    while (index < (s32)root->count) {
        Fn197174Entry *entry = fn_1_41B18(owner, arg1, index);
        if (fn_80083BCC(owner->base + entry->offset, arg2) == 0) {
            return index;
        }
        index++;
    }
    return -1;
}
/* fzgx:end fn_1_97174 */

/* fzgx:begin fn_1_97204 */
extern void fn_1_9724C(void *arg0, void *arg1);
extern u8 fn_1_97F80(void *arg0, void *arg1);

void fn_1_97204(void *arg0, void *arg1) {
    fn_1_9724C(arg0, arg1);
    if (fn_1_97F80(arg0, arg1)) {
        return;
    }
}
/* fzgx:end fn_1_97204 */

/* fzgx:begin fn_1_9724C */
// Loads the active resource value when the initialization check has not completed.
void fn_1_9724C(void) {
    if (fn_1_98104() == 0) {
        ADXT_Stop(lbl_1_bss_6EAD0.unk_0->unk_4);
    }
}
/* fzgx:end fn_1_9724C */

/* fzgx:begin fn_1_97288 noprologue */
#include "types.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/motasglist.h"
#include "dolphin/hw_regs.h"
#include "types.h"
#include "sofdec/sj.h"
#include "rel/main_rel/rob.h"

#ifndef GAME_MAIN_REL_MOTASGLIST_TYPES_H
#define GAME_MAIN_REL_MOTASGLIST_TYPES_H

/* begin game/main_rel/shared_types.h (fork-deltawave784/windows-and-types@215f1cd8) */
#ifndef GAME_MAIN_REL_SHARED_TYPES_H
#define GAME_MAIN_REL_SHARED_TYPES_H

// Types that two or more main_rel TU type headers defined identically; one definition here so
// the TU headers can be included together. Hand-owned (librarian).


typedef struct Sig_fn_1_41488_Fn41488Data {
    u32 count;
    char *strings;
} Sig_fn_1_41488_Fn41488Data;

#endif  // GAME_MAIN_REL_SHARED_TYPES_H

typedef struct Fn142AD0Pair {
    u32 a;
    u32 b;
} Fn142AD0Pair;

typedef struct Fn142AD0Entry {
    u8 pad0[0x88];
    u8 value88[0x0C];
    f32 x;
    u8 pad98[0x0C];
    f32 y;
    u8 padA8[0x0C];
    f32 z;
    Fn142AD0Pair sourceB8;
    u32 sourceC0;
    Fn142AD0Pair sourceC4;
    u32 sourceCC;
    u8 padD0[4];
    u16 keys[6][2][3];
    u32 keysF[3][2][3];
    u8 quat[0x10];
    Fn142AD0Pair value174;
    u32 value17C;
    Fn142AD0Pair value180;
    u32 value188;
} Fn142AD0Entry;

typedef struct Fn142AD0Key {
    u16 value0;
    u16 value1;
    u16 value2;
    u16 value3;
    f32 value4;
    f32 value5;
    f32 value6;
} Fn142AD0Key;

typedef struct Fn142AD0Object {
    u16 count;
    u16 flags;
    u8 pad4[4];
    Fn142AD0Entry *entries;
    u8 padC[0x20];
    f32 value2C;
    f32 value30;
    f32 value34;
    f32 value38;
    u8 pad3C[4];
    Fn142AD0Key cur;
    u8 pad54[4];
    Fn142AD0Key prev;
} Fn142AD0Object;

typedef struct Fn142E74Pair {
    u32 a;
    u32 b;
} Fn142E74Pair;

typedef struct Fn142E74Entry {
    u8 pad0[0xB8];
    Fn142E74Pair sourceB8;
    u32 sourceC0;
    Fn142E74Pair sourceC4;
    u32 sourceCC;
    u8 padD0[0xA4];
    Fn142E74Pair value174;
    u32 value17C;
    Fn142E74Pair value180;
    u32 value188;
} Fn142E74Entry;

typedef struct Fn142E74Object {
    u16 count;
    u16 flags;
    u8 pad4[4];
    Fn142E74Entry *entries;
    u8 padC[0x0C];
    f32 value0;
    f32 value1;
    f32 value2;
    u8 pad24[0x1C];
    u16 flags40;
} Fn142E74Object;

extern int fn_1_41488(Sig_fn_1_41488_Fn41488Data *, const char *);
extern void fn_1_4270C(Fn142AD0Object *object, void *arg1, u32 arg2);

#endif  // GAME_MAIN_REL_MOTASGLIST_TYPES_H

/* end game/main_rel/motasglist_types.h */
/* begin sofdec/adxt.h (fork-deltawave784/windows-and-types@215f1cd8) */
#ifndef SOFDEC_ADXT_H
#define SOFDEC_ADXT_H

/* CRI ADX talker (ADXT) handle, shared by the ADXT_* / adxt_* units of the DOL. */

/* begin layout_check.h (fork-deltawave784/windows-and-types@215f1cd8) */
#ifndef LAYOUT_CHECK_H
#define LAYOUT_CHECK_H

/* Compile-time layout checks for owned types. They declare array typedefs
 * only, so they emit no code or data under MWCC: a wrong size or offset is
 * a negative array bound and fails the compile. */
#define LAYOUT_CHECK_JOIN2(a, b) a##b
#define LAYOUT_CHECK_JOIN(a, b) LAYOUT_CHECK_JOIN2(a, b)
#define CHECK_SIZE(T, size) \
    typedef char LAYOUT_CHECK_JOIN(layout_size_, T)[(sizeof(T) == (size)) ? 1 : -1]
#define CHECK_OFFSET(T, field, offset) \
    typedef char LAYOUT_CHECK_JOIN(LAYOUT_CHECK_JOIN(layout_offset_, T), __LINE__) \
        [((unsigned long)&((T *)0)->field == (offset)) ? 1 : -1]

#endif

/* end layout_check.h */

typedef struct AdxSjdHandle AdxSjdHandle;

typedef struct ADXStream ADXStream;

typedef struct AXRNAHandle AXRNAHandle;

typedef struct LSCObject LSCObject;

typedef struct ADX_AMP ADX_AMP;

typedef struct ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    AdxSjdHandle *decoder;
    ADXStream *stream;
    AXRNAHandle *rna;
    SJ *stream_sj;
    SJ *input_sj;
    SJ *output_sj[2];
    u8 *input_buffer;
    s32 input_buffer_size;
    s32 input_extra_size;
    u8 *output_buffer;
    s32 output_buffer_size;
    s32 output_buffer_distance;
    s32 server_frequency;
    s16 stream_buffer_sectors;
    s16 minimum_buffer_sectors;
    s16 output_volume;
    s16 output_pan[2];
    s16 field_46;
    s32 maximum_decode_samples;
    s32 loop_count;
    s32 link_data_length;
    s32 field_54;
    s32 field_58;
    s32 field_5C;
    s16 error_code;
    u8 reserved_62[2];
    s32 field_64;
    s16 field_68;
    s16 field_6A;
    s8 stream_loop_enabled;
    s8 auto_receiver;
    u8 reserved_6E[2];
    s8 suppress_playback;
    s8 decoder_ready;
    s8 paused;
    u8 reserved_73;
    ADX_AMP *amplifier;
    SJ *amplifier_input[2];
    SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    LSCObject *linked_stream_controller;
    s8 link_enabled;
    u8 reserved_99[3];
    u32 playback_time;
    s32 playback_start_vsync;
    s32 linked_decoded_samples;
    s8 pending_stream_start;
    u8 reserved_A9[3];
    u8 *work_end;
    const char *pending_filename;
    void *pending_directory;
    s32 pending_file_offset;
    s32 pending_file_sectors;
} ADXTHandle;

CHECK_OFFSET(ADXTHandle, decoder, 0x4);
CHECK_OFFSET(ADXTHandle, output_volume, 0x40);
CHECK_OFFSET(ADXTHandle, error_code, 0x60);
CHECK_OFFSET(ADXTHandle, stream_loop_enabled, 0x6C);
CHECK_OFFSET(ADXTHandle, amplifier, 0x74);
CHECK_OFFSET(ADXTHandle, linked_stream_controller, 0x94);
CHECK_OFFSET(ADXTHandle, playback_time, 0x9C);
CHECK_OFFSET(ADXTHandle, pending_file_sectors, 0xBC);
CHECK_SIZE(ADXTHandle, 0xC0);

#endif

/* end sofdec/adxt.h */

#pragma section code_type ".fzgxpool"
extern u8 lbl_1_data_26D50__fzgx_offset_0[];
extern u8 lbl_1_data_26D54__fzgx_offset_0[];
extern u8 lbl_1_data_26D5C__fzgx_offset_0[];
extern u8 lbl_1_data_26D64__fzgx_offset_0[];
extern u8 lbl_1_data_26D6C__fzgx_offset_0[];
extern u8 lbl_1_data_26D74__fzgx_offset_0[];
extern u8 lbl_1_data_26D7C__fzgx_offset_0[];
extern u8 lbl_1_data_26D84__fzgx_offset_0[];
static const union { u32 w[73]; const unsigned long v[73]; } fzgx_pool_init_fzgx_pool_table1 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_1_data_26D50__fzgx_offset_0, (u32)lbl_1_data_26D50__fzgx_offset_0, (u32)lbl_1_data_26D54__fzgx_offset_0, (u32)lbl_1_data_26D5C__fzgx_offset_0, (u32)lbl_1_data_26D64__fzgx_offset_0, (u32)lbl_1_data_26D50__fzgx_offset_0, (u32)lbl_1_data_26D6C__fzgx_offset_0, (u32)lbl_1_data_26D54__fzgx_offset_0,
    (u32)lbl_1_data_26D5C__fzgx_offset_0, (u32)lbl_1_data_26D64__fzgx_offset_0, (u32)lbl_1_data_26D50__fzgx_offset_0, (u32)lbl_1_data_26D74__fzgx_offset_0, (u32)lbl_1_data_26D7C__fzgx_offset_0, (u32)lbl_1_data_26D84__fzgx_offset_0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table1.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 1.0f;
    s = 100.0f;
    s = 180.0f;
    s = 32767.0f;
    d = 4503601774854144.0;
}
static const union { u32 w[3]; const unsigned long v[3]; } fzgx_pool_init_fzgx_pool_table3 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFFFFFF, 0xBF800000, 0xFFFFFFFF
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table3.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 55.0f;
    s = 30.0f;
    s = 1000.0f;
    s = 3.003967046737671f;
}
static const union { u32 w[15]; const unsigned long v[15]; } fzgx_pool_init_fzgx_pool_table5 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x0, 0x3B963DC5, 0xBD6DD053, 0xBD953A3F, 0x3B963DC5, 0xBD6DD053,
    0x3CF0307F, 0xBB963DC5, 0xBD6DD053, 0xBD953A3F, 0xBB963DC5, 0xBD6DD053, 0x3CF0307F
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table5.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 182.04444885253906f;
    s = 0.20250000059604645f;
    s = 0.06499999761581421f;
    s = 0.08500000089406967f;
    d = 0.05;
    s = 0.05000000074505806f;
    s = 0.004999999888241291f;
    s = -0.017500000074505806f;
    s = 65535.0f;
    d = 4503599627370496.0;
    s = 50.0f;
    s = -1.0f;
}
static const union { u32 w[3]; const unsigned long v[3]; } fzgx_pool_init_fzgx_pool_table7 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x40406080, 0x0, 0x204080
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table7.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
}
static const union { u32 w[2]; const unsigned long v[2]; } fzgx_pool_init_fzgx_pool_table9 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table9.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.08500000089406967f;
}
static const union { u32 w[18]; const unsigned long v[18]; } fzgx_pool_init_fzgx_pool_table11 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0xBDAE147B, 0x0, 0x0, 0x3F800000, 0x0, 0x3F800000, 0x0,
    0x0, 0x0, 0x3F800000, 0x0, 0x0, 0x0, 0x3F800000, 0x0,
    0x0, 0x3F800000
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table11.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.25f;
    s = 0.15000000596046448f;
    s = 65536.0f;
}
#pragma section code_type ".text"

struct fn_1_97288_Arg0 {
    u8 pad_0[0x1E4];
    u32 unk_1E4;
};
struct fn_1_97288_lbl_1_rodata_3E48 {
    u8 pad_0[0x124];
    f32 unk_124;
    u8 pad_128[0x4];
    f32 unk_12C;
    u8 pad_130[0x8];
    f64 unk_138;
    u8 pad_140[0x80];
    f64 unk_1C0;
    u8 pad_1C8[0x74];
    f32 unk_23C;
};
struct fn_1_97288_lbl_1_data_209C0 {
    u8 pad_0[0x6400];
    u32 unk_6400[6];
    f32 unk_6418;
};

extern int sprintf(char *, const char *, ...);
extern const struct fn_1_97288_lbl_1_rodata_3E48 lbl_1_rodata_3E48;
extern u8 * fn_80083970(u8 *, const u8 *);
extern void ADXT_Stop(ADXTHandle *);
extern void fn_1_4270C(struct Fn142AD0Object *, void *, u32);
extern void fn_1_42AD0(Fn142AD0Object *, void *, u32, u16, u16);
extern void fn_1_42E74(Fn142E74Object *);
extern void fn_8004D18C(ADXTHandle *, u32);

static inline f32 fn97288_ufloat(u32 x, f64 bias) { return (f32)x; }
static inline f32 fn97288_sfloat(s32 x, f64 bias) { return (f32)x; }
static inline f32 fn97288_clamp(f32 x, const struct fn_1_97288_lbl_1_rodata_3E48 *r, struct fn_1_97288_lbl_1_data_209C0 *d) {
    return x < (0.0f) ? (0.0f) : x > d->unk_6418 ? d->unk_6418 : x;
}
/* integer address sum keeps the table base (addi rT, base, 0x6400) separate from the lwzx index */
#pragma opt_propagation off
static inline const char *fn97288_table(u32 base, s32 index) { const char **table = (const char **)(base + 0x6400); return table[index]; }
#pragma opt_propagation off

#pragma opt_lifetimes off
#pragma opt_common_subs on
#pragma opt_strength_reduction off
void fn_1_97288(struct fn_1_97288_Arg0 *arg0, f32 arg1) {
    const struct fn_1_97288_lbl_1_rodata_3E48 *p_lbl_1_rodata_3E48;
    struct fn_1_97288_lbl_1_data_209C0 *p_lbl_1_data_209C0;
    u32 v0;
    u32 v2;
    u8 v3;
    int v4;
    u32 v5;
    u32 v6;
    u32 v8;
    u32 v7;
    struct { f32 value; } zero;
    f32 v9;
    u32 v13;
    u32 v14;
    u32 v15;
    u32 v12;
    u32 v16;
    u8 v17;
    f64 v18;
    f32 v19;
    f32 v20;
    f32 v21;
    f32 v22;
    f32 v1;
    int v23;
    s32 v24;
    int v25;
    f32 v26;
    s32 v27;
    s32 v28;
    f32 v10;
    struct { u32 a[16]; } loc_50;
    struct { u16 a[12]; } loc_38;
    struct { u16 a[12]; } loc_20;
    struct { u16 a[12]; } loc_8;
    int t0;
    u8 * t3;
    int t4;
    u8 * t5;
    u8 * t6;
    int t7;
    u8 * t8;
    u8 * t9;
    u8 * t10;
    int t11;
    int t12;
    int t14;
    int t17;
    u32 v0_2;
    p_lbl_1_rodata_3E48 = (const struct fn_1_97288_lbl_1_rodata_3E48 *)&lbl_1_rodata_3E48;
    arg0->unk_1E4 = 0;
    p_lbl_1_data_209C0 = (struct fn_1_97288_lbl_1_data_209C0 *)&lbl_1_data_209C0;
    v1 = arg1;
    if ((s8)*(u8 *)((u8 *)(u32)arg0 + 1161) != 0) {
    v0 = *(u32 *)((u8 *)(u32)arg0 + 1200);
    v2 = *(u32 *)((u8 *)(u32)arg0 + 464);
    v3 = *(u8 *)((u8 *)v0 + (*(u32 *)((u8 *)(u32)arg0 + 1184) << 2));
    v0 = *(u32 *)((u8 *)v2 + 36);
    v4 = fn_1_41488((Sig_fn_1_41488_Fn41488Data *)v0, fn97288_table((u32)p_lbl_1_data_209C0, v3 >> 5));
    if ((u32)v4 == 0xFFFFFFFF) {
    v4 = 0;
    }
    v0 = *(u32 *)((u8 *)(u32)arg0 + 464);
    *(u16 *)((u8 *)(u32)arg0 + 456) = v4;
    fn_1_4270C((struct Fn142AD0Object *)v0, (void *)0, (v4 & 0xFFFF));
    ADXT_Stop((ADXTHandle *)lbl_1_bss_6EAD0.unk_0->unk_4);
    v0 = *(u32 *)((u8 *)(u32)arg0 + 1204);
    t3 = (u8 *)(fn_80083970((u8 *)v0, (const u8 *)((u8 *)(u32)p_lbl_1_data_209C0 + 29384)));
    v0 = (u32)(t3);
    if ((u32)v0 != 0) {
    v0 = (u32)&loc_50;
    t4 = sprintf((char *)(u32)v0, (const char *)(u32)((u8 *)(u32)p_lbl_1_data_209C0 + 29392), *(u32 *)((u8 *)(u32)arg0 + 1204));
    v0 = t4;
    } else {
    if (fn_80083970(*(u8 **)((u8 *)arg0 + 1204), (u8 *)p_lbl_1_data_209C0 + 832) ||
        fn_80083970(*(u8 **)((u8 *)arg0 + 1204), (u8 *)p_lbl_1_data_209C0 + 680)) {
    v0 = (u32)&loc_50;
    t7 = sprintf((char *)(u32)v0, (const char *)(u32)((u8 *)(u32)p_lbl_1_data_209C0 + 29408), (*(u32 *)((u8 *)(u32)arg0 + 1204) + 5));
    v0 = t7;
    } else {
    if (fn_80083970(*(u8 **)((u8 *)arg0 + 1204), (u8 *)p_lbl_1_data_209C0 + 29436) ||
        fn_80083970(*(u8 **)((u8 *)arg0 + 1204), (u8 *)p_lbl_1_data_209C0 + 840) ||
        fn_80083970(*(u8 **)((u8 *)arg0 + 1204), (u8 *)p_lbl_1_data_209C0 + 844)) {
    v0 = (u32)&loc_50;
    t11 = sprintf((char *)(u32)v0, (const char *)(u32)((u8 *)(u32)p_lbl_1_data_209C0 + 29444), (*(u32 *)((u8 *)(u32)arg0 + 1204) + 4));
    v0 = t11;
    } else {
    v0 = (u32)&loc_50;
    t12 = sprintf((char *)(u32)v0, (const char *)(u32)((u8 *)(u32)p_lbl_1_data_209C0 + 29392), *(u32 *)((u8 *)(u32)arg0 + 1204));
    v0 = t12;
    }
    }
    }
    fn_8004D18C((ADXTHandle *)lbl_1_bss_6EAD0.unk_0->unk_4, (u32)&loc_50);
    *(u8 *)((u8 *)(u32)arg0 + 1161) = 0;
    v0 = *(u32 *)((u8 *)(u32)arg0 + 1200);
    v5 = ((*(u8 *)((u8 *)v0 + (*(u32 *)((u8 *)(u32)arg0 + 1184) << 2)) >> 5) & 0x7);
    *(u8 *)((u8 *)(u32)arg0 + 1163) = v5;
    *(u8 *)((u8 *)(u32)arg0 + 1162) = v5;
    *(u32 *)((u8 *)(u32)arg0 + 1164) = 0;
    } else {
    v0 = *(u32 *)((u8 *)(u32)arg0 + 1196);
    v6 = *(u32 *)((u8 *)(u32)arg0 + 1184);
    if ((s32)v6 < (s32)(v0 - 1)) {
    v0 = (v6 + 1);
    *(u32 *)((u8 *)(u32)arg0 + 1184) = v0;
    v0 = *(u32 *)((u8 *)(u32)arg0 + 1184);
    v7 = *(u32 *)((u8 *)(u32)arg0 + 1200);
    v8 = (v0 << 2);
    v1 = fn97288_ufloat(*(u32 *)((u8 *)v7 + v8) & 0x1FFFFFFF, (4503599627370496.0));
    v9 = (f32)(v1 / (65536.0f));
    v10 = fn97288_clamp(v9, p_lbl_1_rodata_3E48, p_lbl_1_data_209C0);
    v0 = *(u8 *)((u8 *)(u32)arg0 + 1162);
    v0 = (s8)v0;
    if ((s32)v0 == (s32)((*(u8 *)((u8 *)v7 + v8) >> 5) & 0x7)) {
    v0 = *(u32 *)((u8 *)(u32)arg0 + 1164);
    *(u32 *)((u8 *)(u32)arg0 + 1164) = (v0 + 1);
    } else {
    *(u32 *)((u8 *)(u32)arg0 + 1164) = 1;
    *(u8 *)((u8 *)(u32)arg0 + 1163) = *(u8 *)((u8 *)(u32)arg0 + 1162);
    v1 = *(f32 *)((u8 *)(u32)arg0 + 1176);
    *(f32 *)((u8 *)(u32)arg0 + 1180) = v1;
    v0 = *(u32 *)((u8 *)(u32)arg0 + 1200);
    *(u8 *)((u8 *)(u32)arg0 + 1162) = ((*(u8 *)((u8 *)v0 + (*(u32 *)((u8 *)(u32)arg0 + 1184) << 2)) >> 5) & 0x7);
    *(f32 *)((u8 *)(u32)arg0 + 1172) = ((0.0f));
    v0 = *(u32 *)((u8 *)(u32)arg0 + 1196);
    v12 = *(u32 *)((u8 *)(u32)arg0 + 1184);
    v0--;
    v16 = v12;
    v15 = (v12 << 2);
    for (; (s32)v16 < (s32)v0; v15 += 4, v16++) {
    if ((s8)*(u8 *)((u8 *)arg0 + 1162) != (s32)((*(u8 *)(*(u8 **)((u8 *)arg0 + 1200) + v15) >> 5) & 7)) break;
    }
    v0 = (v16 - v12);
    *(u32 *)((u8 *)(u32)arg0 + 1168) = (s32)v0 < 2 ? 2 : (s32)v0 > 8 ? 8 : v0;
    }
    v1 = ((f32)*(s32 *)((u8 *)arg0 + 1168) - (f32)*(s32 *)((u8 *)arg0 + 1164)) /
         (f32)*(s32 *)((u8 *)arg0 + 1168);
    *(f32 *)((u8 *)arg0 + 1172) = v1;
    v1 = *(f32 *)((u8 *)arg0 + 1172);
    if (v1 < 0.0f) {
        *(f32 *)((u8 *)arg0 + 1172) = 0.0f;
    }
    v1 = v10 / p_lbl_1_data_209C0->unk_6418;
    *(f32 *)((u8 *)arg0 + 1176) = v1;
    v1 = *(f32 *)((u8 *)arg0 + 1176);
    if (v1 < (0.0f)) {
        *(f32 *)((u8 *)arg0 + 1176) = (0.0f);
    }
    if (*(f32 *)((u8 *)arg0 + 1172) > (0.0f)) {
    v0 = *(u32 *)((u8 *)(u32)arg0 + 464);
    v0 = *(u32 *)((u8 *)v0 + 36);
    v23 = fn_1_41488((Sig_fn_1_41488_Fn41488Data *)v0, fn97288_table((u32)p_lbl_1_data_209C0, (s8)*(u8 *)((u8 *)(u32)arg0 + 1163)));
    if ((u32)v23 == 0xFFFFFFFF) {
    v23 = 0;
    }
    v24 = (s32)((100.0f) * *(f32 *)((u8 *)arg0 + 1180));
    loc_38.a[2] = 0xFFFF;
    loc_38.a[3] = v24;
    loc_38.a[1] = v24;
    v0 = *(u32 *)((u8 *)(u32)arg0 + 464);
    *(u16 *)((u8 *)(u32)arg0 + 456) = v23;
    fn_1_4270C((struct Fn142AD0Object *)v0, (void *)&loc_38, (v23 & 0xFFFF));
    v0 = *(u32 *)((u8 *)(u32)arg0 + 464);
    fn_1_42E74((Fn142E74Object *)v0);
    }
    v0 = *(u32 *)((u8 *)(u32)arg0 + 464);
    v0 = *(u32 *)((u8 *)v0 + 36);
    v25 = fn_1_41488((Sig_fn_1_41488_Fn41488Data *)v0, fn97288_table((u32)p_lbl_1_data_209C0, (s8)*(u8 *)((u8 *)(u32)arg0 + 1162)));
    if ((u32)v25 == 0xFFFFFFFF) {
    v25 = 0;
    }
    v27 = (s32)((100.0f) * *(f32 *)((u8 *)arg0 + 1176));
    loc_20.a[2] = 0xFFFF;
    loc_20.a[3] = v27;
    loc_20.a[1] = v27;
    v1 = *(f32 *)((u8 *)(u32)arg0 + 1172);
    if (v1 <= (0.0f)) {
    v0 = *(u32 *)((u8 *)(u32)arg0 + 464);
    *(u16 *)((u8 *)(u32)arg0 + 456) = v25;
    fn_1_4270C((struct Fn142AD0Object *)v0, (void *)&loc_20, (v25 & 0xFFFF));
    } else {
    v0 = *(u32 *)((u8 *)(u32)arg0 + 464);
    *(u16 *)((u8 *)(u32)arg0 + 456) = v25;
    fn_1_42AD0((Fn142AD0Object *)v0, (void *)&loc_20, (v25 & 0xFFFF), 100, 84);
    }
    v0_2 = *(u32 *)((u8 *)(u32)arg0 + 432);
    if (v0_2 != 0 && *(u32 *)((u8 *)(u32)arg0 + 436) != 0) {
    v28 = (s32)((100.0f) * *(f32 *)((u8 *)arg0 + 1176));
    loc_8.a[2] = 0xFFFF;
    loc_8.a[3] = v28;
    loc_8.a[1] = v28;
    fn_1_4270C((struct Fn142AD0Object *)v0_2, (void *)&loc_8, *(u16 *)((u8 *)(u32)arg0 + 424));
    }
    }
    }
    return;
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_97288 */

/* fzgx:begin fn_1_977BC noprologue */
#include "types.h"

/* fzgx:begin fn_1_977BC noprologue */

typedef struct { f32 x, y, z; } RobVec;
typedef struct { u32 count; char *strings; } RobNames;
typedef struct { u8 pad[0x4C]; f32 frame; } RobMotion;
typedef struct { u16 id; u8 pad[6]; RobMotion *motion; RobNames *names; } RobAnim;
typedef struct {
    u8 pad0[0x8C]; u32 active;
    u8 pad90[0x10]; s16 rot_y, rot_x, rot_z; u8 padA6[2];
    RobVec pos; f32 height; f32 scale;
    u8 padBC[0x28]; void *models[5];
    u8 padF8[0x50]; RobAnim anim;
} Rob;
typedef struct { u8 pad[8]; u8 *view; } RobView;
typedef struct { RobVec pos; const char *name; } RobPart;
typedef struct { u8 pad[0x7330]; RobPart parts[8]; char names[4][8]; } RobData;
typedef struct { u32 flags; u8 pad[0x1C]; } RobMaterial;
typedef struct { u8 pad[0x18]; u16 count; u8 pad1A[0x26]; RobMaterial materials[1]; } RobModel;
extern u8 lbl_1_data_209C0__fzgx_offset_0[];
extern u8 lbl_1_data_209C8__fzgx_offset_0[];
extern u8 lbl_1_data_209D0__fzgx_offset_0[];
extern u8 lbl_1_data_209D8__fzgx_offset_0[];
extern u8 lbl_1_data_209E0__fzgx_offset_0[];
extern u8 lbl_1_data_209E8__fzgx_offset_0[];
extern u8 lbl_1_data_209F0__fzgx_offset_0[];
extern u8 lbl_1_data_209F8__fzgx_offset_0[];
extern u8 lbl_1_data_20A00__fzgx_offset_0[];
extern u8 lbl_1_data_20A04__fzgx_offset_0[];
extern u8 lbl_1_data_20A0C__fzgx_offset_0[];
extern u8 lbl_1_data_20A14__fzgx_offset_0[];
extern u8 lbl_1_data_20A1C__fzgx_offset_0[];
extern u8 lbl_1_data_20A24__fzgx_offset_0[];
extern u8 lbl_1_data_20A2C__fzgx_offset_0[];
extern u8 lbl_1_data_20A30__fzgx_offset_0[];
extern u8 lbl_1_data_20A38__fzgx_offset_0[];
extern u8 lbl_1_data_20A40__fzgx_offset_0[];
extern u8 lbl_1_data_20A4C__fzgx_offset_0[];
extern u8 lbl_1_data_20A54__fzgx_offset_0[];
extern u8 lbl_1_data_20A5C__fzgx_offset_0[];
extern u8 lbl_1_data_20A60__fzgx_offset_0[];
extern u8 lbl_1_data_20A68__fzgx_offset_0[];
extern u8 lbl_1_data_20A70__fzgx_offset_0[];
extern u8 lbl_1_data_20A78__fzgx_offset_0[];
extern u8 lbl_1_data_20A80__fzgx_offset_0[];
extern u8 lbl_1_data_20A88__fzgx_offset_0[];
extern u8 lbl_1_data_20A90__fzgx_offset_0[];
extern u8 lbl_1_data_20A98__fzgx_offset_0[];
extern u8 lbl_1_data_20AA0__fzgx_offset_0[];
extern u8 lbl_1_data_20AA8__fzgx_offset_0[];
extern u8 lbl_1_data_20AB0__fzgx_offset_0[];
extern u8 lbl_1_data_20AB4__fzgx_offset_0[];
extern u8 lbl_1_data_20ABC__fzgx_offset_0[];
extern u8 lbl_1_data_20AC0__fzgx_offset_0[];
extern u8 lbl_1_data_20AC8__fzgx_offset_0[];
extern u8 lbl_1_data_20AD4__fzgx_offset_0[];
extern u8 lbl_1_data_20ADC__fzgx_offset_0[];
extern u8 lbl_1_data_20AE4__fzgx_offset_0[];
extern u8 lbl_1_data_20AE8__fzgx_offset_0[];
extern u8 lbl_1_data_20AEC__fzgx_offset_0[];
extern u8 lbl_1_data_20AF8__fzgx_offset_0[];
extern u8 lbl_1_data_20B00__fzgx_offset_0[];
extern u8 lbl_1_data_20B04__fzgx_offset_0[];
extern u8 lbl_1_data_20B08__fzgx_offset_0[];
extern u8 lbl_1_data_20BC8__fzgx_offset_0[];
extern u8 lbl_1_data_20BD0__fzgx_offset_0[];
extern u8 lbl_1_data_20BD8__fzgx_offset_0[];
extern u8 lbl_1_data_20BE0__fzgx_offset_0[];
extern u8 lbl_1_data_20BE8__fzgx_offset_0[];
extern u8 lbl_1_data_20BF0__fzgx_offset_0[];
extern u8 lbl_1_data_20BF8__fzgx_offset_0[];
extern u8 lbl_1_data_20C00__fzgx_offset_0[];
extern u8 lbl_1_data_20C08__fzgx_offset_0[];
extern u8 lbl_1_data_20C0C__fzgx_offset_0[];
extern u8 lbl_1_data_20C14__fzgx_offset_0[];
extern u8 lbl_1_data_20C1C__fzgx_offset_0[];
extern u8 lbl_1_data_20C24__fzgx_offset_0[];
extern u8 lbl_1_data_20C2C__fzgx_offset_0[];
extern u8 lbl_1_data_20C34__fzgx_offset_0[];
extern u8 lbl_1_data_20C38__fzgx_offset_0[];
extern u8 lbl_1_data_20C40__fzgx_offset_0[];
extern u8 lbl_1_data_20C48__fzgx_offset_0[];
extern u8 lbl_1_data_20C54__fzgx_offset_0[];
extern u8 lbl_1_data_20C5C__fzgx_offset_0[];
extern u8 lbl_1_data_20C64__fzgx_offset_0[];
extern u8 lbl_1_data_20C68__fzgx_offset_0[];
extern u8 lbl_1_data_20C70__fzgx_offset_0[];
extern u8 lbl_1_data_20C78__fzgx_offset_0[];
extern u8 lbl_1_data_20C80__fzgx_offset_0[];
extern u8 lbl_1_data_20C88__fzgx_offset_0[];
extern u8 lbl_1_data_20C90__fzgx_offset_0[];
extern u8 lbl_1_data_20C98__fzgx_offset_0[];
extern u8 lbl_1_data_20CA0__fzgx_offset_0[];
extern u8 lbl_1_data_20CA8__fzgx_offset_0[];
extern u8 lbl_1_data_20CB0__fzgx_offset_0[];
extern u8 lbl_1_data_20CB8__fzgx_offset_0[];
extern u8 lbl_1_data_20CBC__fzgx_offset_0[];
extern u8 lbl_1_data_20CC4__fzgx_offset_0[];
extern u8 lbl_1_data_20CC8__fzgx_offset_0[];
extern u8 lbl_1_data_20CD0__fzgx_offset_0[];
extern u8 lbl_1_data_20CDC__fzgx_offset_0[];
extern u8 lbl_1_data_20CE4__fzgx_offset_0[];
extern u8 lbl_1_data_20CEC__fzgx_offset_0[];
extern u8 lbl_1_data_20CF0__fzgx_offset_0[];
extern u8 lbl_1_data_20CF4__fzgx_offset_0[];
extern u8 lbl_1_data_20D00__fzgx_offset_0[];
extern u8 lbl_1_data_20D08__fzgx_offset_0[];
extern u8 lbl_1_data_20D0C__fzgx_offset_0[];
extern u8 lbl_1_data_20D10__fzgx_offset_0[];
extern u8 lbl_1_data_20DD0__fzgx_offset_0[];
extern u8 lbl_1_data_20DE4__fzgx_offset_0[];
extern u8 lbl_1_data_20DF4__fzgx_offset_0[];
extern u8 lbl_1_data_20E0C__fzgx_offset_0[];
extern u8 lbl_1_data_20E14__fzgx_offset_0[];
extern u8 lbl_1_data_20E24__fzgx_offset_0[];
extern u8 lbl_1_data_20E2C__fzgx_offset_0[];
extern u8 lbl_1_data_20E44__fzgx_offset_0[];
extern u8 lbl_1_data_20E50__fzgx_offset_0[];
extern u8 lbl_1_data_20E6C__fzgx_offset_0[];
extern u8 lbl_1_data_20E84__fzgx_offset_0[];
extern u8 lbl_1_data_20E8C__fzgx_offset_0[];
extern u8 lbl_1_data_20E9C__fzgx_offset_0[];
extern u8 lbl_1_data_20EA4__fzgx_offset_0[];
extern u8 lbl_1_data_20EB4__fzgx_offset_0[];
extern u8 lbl_1_data_20EC4__fzgx_offset_0[];
extern u8 lbl_1_data_20ED0__fzgx_offset_0[];
extern u8 lbl_1_data_20EE4__fzgx_offset_0[];
extern u8 lbl_1_data_20EF4__fzgx_offset_0[];
extern u8 lbl_1_data_20EFC__fzgx_offset_0[];
extern u8 lbl_1_data_20F0C__fzgx_offset_0[];
extern u8 lbl_1_data_20F1C__fzgx_offset_0[];
extern u8 lbl_1_data_20F2C__fzgx_offset_0[];
extern u8 lbl_1_data_20F40__fzgx_offset_0[];
extern u8 lbl_1_data_20F54__fzgx_offset_0[];
extern u8 lbl_1_data_20F68__fzgx_offset_0[];
extern u8 lbl_1_data_20F78__fzgx_offset_0[];
extern u8 lbl_1_data_20F80__fzgx_offset_0[];
extern u8 lbl_1_data_20F94__fzgx_offset_0[];
extern u8 lbl_1_data_20FA8__fzgx_offset_0[];
extern u8 lbl_1_data_20FBC__fzgx_offset_0[];
extern u8 lbl_1_data_20FC8__fzgx_offset_0[];
extern u8 lbl_1_data_20FD8__fzgx_offset_0[];
extern u8 lbl_1_data_20FE4__fzgx_offset_0[];
extern u8 lbl_1_data_20FF8__fzgx_offset_0[];
extern u8 lbl_1_data_21004__fzgx_offset_0[];
extern u8 lbl_1_data_21010__fzgx_offset_0[];
extern u8 lbl_1_data_2101C__fzgx_offset_0[];
extern u8 lbl_1_data_21024__fzgx_offset_0[];
extern u8 lbl_1_data_21030__fzgx_offset_0[];
extern u8 lbl_1_data_21040__fzgx_offset_0[];
extern u8 lbl_1_data_21050__fzgx_offset_0[];
extern u8 lbl_1_data_21058__fzgx_offset_0[];
extern u8 lbl_1_data_21060__fzgx_offset_0[];
extern u8 lbl_1_data_21068__fzgx_offset_0[];
extern u8 lbl_1_data_2112C__fzgx_offset_0[];
extern u8 lbl_1_data_2113C__fzgx_offset_0[];
extern u8 lbl_1_data_21148__fzgx_offset_0[];
extern u8 lbl_1_data_21154__fzgx_offset_0[];
extern u8 lbl_1_data_21164__fzgx_offset_0[];
extern u8 lbl_1_data_21174__fzgx_offset_0[];
extern u8 lbl_1_data_2117C__fzgx_offset_0[];
extern u8 lbl_1_data_21184__fzgx_offset_0[];
extern u8 lbl_1_data_21194__fzgx_offset_0[];
extern u8 lbl_1_data_211A0__fzgx_offset_0[];
extern u8 lbl_1_data_211AC__fzgx_offset_0[];
extern u8 lbl_1_data_211B4__fzgx_offset_0[];
extern u8 lbl_1_data_211C0__fzgx_offset_0[];
extern u8 lbl_1_data_211D0__fzgx_offset_0[];
extern u8 lbl_1_data_211DC__fzgx_offset_0[];
extern u8 lbl_1_data_211E8__fzgx_offset_0[];
extern u8 lbl_1_data_211F8__fzgx_offset_0[];
extern u8 lbl_1_data_21208__fzgx_offset_0[];
extern u8 lbl_1_data_21218__fzgx_offset_0[];
extern u8 lbl_1_data_21228__fzgx_offset_0[];
extern u8 lbl_1_data_21234__fzgx_offset_0[];
extern u8 lbl_1_data_21244__fzgx_offset_0[];
extern u8 lbl_1_data_21250__fzgx_offset_0[];
extern u8 lbl_1_data_21260__fzgx_offset_0[];
extern u8 lbl_1_data_2126C__fzgx_offset_0[];
extern u8 lbl_1_data_21278__fzgx_offset_0[];
extern u8 lbl_1_data_21284__fzgx_offset_0[];
extern u8 lbl_1_data_21290__fzgx_offset_0[];
extern u8 lbl_1_data_21298__fzgx_offset_0[];
extern u8 lbl_1_data_212A0__fzgx_offset_0[];
extern u8 lbl_1_data_22A1C__fzgx_offset_0[];
extern u8 lbl_1_data_21A3C__fzgx_offset_0[];
extern u8 lbl_1_data_22A24__fzgx_offset_0[];
extern u8 lbl_1_data_21A64__fzgx_offset_0[];
extern u8 lbl_1_data_22A2C__fzgx_offset_0[];
extern u8 lbl_1_data_21A80__fzgx_offset_0[];
extern u8 lbl_1_data_22A34__fzgx_offset_0[];
extern u8 lbl_1_data_22A3C__fzgx_offset_0[];
extern u8 lbl_1_data_22A14__fzgx_offset_0[];
extern u8 lbl_1_data_22A44__fzgx_offset_0[];
extern u8 lbl_1_data_22A10__fzgx_offset_0[];
extern u8 lbl_1_data_215F0__fzgx_offset_0[];
extern u8 lbl_1_data_21618__fzgx_offset_0[];
extern u8 lbl_1_data_21628__fzgx_offset_0[];
extern u8 lbl_1_data_21CB4__fzgx_offset_0[];
extern u8 lbl_1_data_21CDC__fzgx_offset_0[];
extern u8 lbl_1_data_21CF4__fzgx_offset_0[];
extern u8 lbl_1_data_22334__fzgx_offset_0[];
extern u8 lbl_1_data_2235C__fzgx_offset_0[];
extern u8 lbl_1_data_22360__fzgx_offset_0[];
extern u8 lbl_1_data_22884__fzgx_offset_0[];
extern u8 lbl_1_data_228AC__fzgx_offset_0[];
extern u8 lbl_1_data_228CC__fzgx_offset_0[];
extern u8 lbl_1_data_21F04__fzgx_offset_0[];
extern u8 lbl_1_data_21F2C__fzgx_offset_0[];
extern u8 lbl_1_data_21F50__fzgx_offset_0[];
extern u8 lbl_1_data_22DF4__fzgx_offset_0[];
extern u8 lbl_1_data_22E00__fzgx_offset_0[];
extern u8 lbl_1_data_22A18__fzgx_offset_0[];
extern u8 lbl_1_data_21E08__fzgx_offset_0[];
extern u8 lbl_1_data_21E30__fzgx_offset_0[];
extern u8 lbl_1_data_21E54__fzgx_offset_0[];
extern u8 lbl_1_data_222A0__fzgx_offset_0[];
extern u8 lbl_1_data_222D8__fzgx_offset_0[];
extern u8 lbl_1_data_21660__fzgx_offset_0[];
extern u8 lbl_1_data_216A8__fzgx_offset_0[];
extern u8 lbl_1_data_216C0__fzgx_offset_0[];
extern u8 lbl_1_data_2193C__fzgx_offset_0[];
extern u8 lbl_1_data_21964__fzgx_offset_0[];
extern u8 lbl_1_data_21980__fzgx_offset_0[];
extern u8 lbl_1_data_2221C__fzgx_offset_0[];
extern u8 lbl_1_data_22244__fzgx_offset_0[];
extern u8 lbl_1_data_22264__fzgx_offset_0[];
extern u8 lbl_1_data_23190__fzgx_offset_0[];
extern u8 lbl_1_data_22274__fzgx_offset_0[];
extern u8 lbl_1_data_2255C__fzgx_offset_0[];
extern u8 lbl_1_data_22584__fzgx_offset_0[];
extern u8 lbl_1_data_225AC__fzgx_offset_0[];
extern u8 lbl_1_data_2146C__fzgx_offset_0[];
extern u8 lbl_1_data_21494__fzgx_offset_0[];
extern u8 lbl_1_data_214B4__fzgx_offset_0[];
extern u8 lbl_1_data_22904__fzgx_offset_0[];
extern u8 lbl_1_data_2292C__fzgx_offset_0[];
extern u8 lbl_1_data_2294C__fzgx_offset_0[];
extern u8 lbl_1_data_23420__fzgx_offset_0[];
extern u8 lbl_1_data_2295C__fzgx_offset_0[];
extern u8 lbl_1_data_213EC__fzgx_offset_0[];
extern u8 lbl_1_data_21414__fzgx_offset_0[];
extern u8 lbl_1_data_21434__fzgx_offset_0[];
extern u8 lbl_1_data_21F88__fzgx_offset_0[];
extern u8 lbl_1_data_21FB0__fzgx_offset_0[];
extern u8 lbl_1_data_21FD4__fzgx_offset_0[];
extern u8 lbl_1_data_2135C__fzgx_offset_0[];
extern u8 lbl_1_data_21384__fzgx_offset_0[];
extern u8 lbl_1_data_213A0__fzgx_offset_0[];
extern u8 lbl_1_data_236B0__fzgx_offset_0[];
extern u8 lbl_1_data_213B0__fzgx_offset_0[];
extern u8 lbl_1_data_2200C__fzgx_offset_0[];
extern u8 lbl_1_data_2203C__fzgx_offset_0[];
extern u8 lbl_1_data_22058__fzgx_offset_0[];
extern u8 lbl_1_data_21C38__fzgx_offset_0[];
extern u8 lbl_1_data_21C60__fzgx_offset_0[];
extern u8 lbl_1_data_21C7C__fzgx_offset_0[];
extern u8 lbl_1_data_22120__fzgx_offset_0[];
extern u8 lbl_1_data_22148__fzgx_offset_0[];
extern u8 lbl_1_data_22160__fzgx_offset_0[];
extern u8 lbl_1_data_21D30__fzgx_offset_0[];
extern u8 lbl_1_data_21D58__fzgx_offset_0[];
extern u8 lbl_1_data_21D70__fzgx_offset_0[];
extern u8 lbl_1_data_21E8C__fzgx_offset_0[];
extern u8 lbl_1_data_21EB4__fzgx_offset_0[];
extern u8 lbl_1_data_21ECC__fzgx_offset_0[];
extern u8 lbl_1_data_21574__fzgx_offset_0[];
extern u8 lbl_1_data_2159C__fzgx_offset_0[];
extern u8 lbl_1_data_215B8__fzgx_offset_0[];
extern u8 lbl_1_data_2267C__fzgx_offset_0[];
extern u8 lbl_1_data_226A4__fzgx_offset_0[];
extern u8 lbl_1_data_226C0__fzgx_offset_0[];
extern u8 lbl_1_data_22198__fzgx_offset_0[];
extern u8 lbl_1_data_221C0__fzgx_offset_0[];
extern u8 lbl_1_data_221E4__fzgx_offset_0[];
extern u8 lbl_1_data_21BAC__fzgx_offset_0[];
extern u8 lbl_1_data_21BD4__fzgx_offset_0[];
extern u8 lbl_1_data_21BF0__fzgx_offset_0[];
extern u8 lbl_1_data_2277C__fzgx_offset_0[];
extern u8 lbl_1_data_227A4__fzgx_offset_0[];
extern u8 lbl_1_data_227C0__fzgx_offset_0[];
extern u8 lbl_1_data_219C0__fzgx_offset_0[];
extern u8 lbl_1_data_219E8__fzgx_offset_0[];
extern u8 lbl_1_data_21A04__fzgx_offset_0[];
extern u8 lbl_1_data_2298C__fzgx_offset_0[];
extern u8 lbl_1_data_229B4__fzgx_offset_0[];
extern u8 lbl_1_data_229D8__fzgx_offset_0[];
extern u8 lbl_1_data_214EC__fzgx_offset_0[];
extern u8 lbl_1_data_21514__fzgx_offset_0[];
extern u8 lbl_1_data_2153C__fzgx_offset_0[];
extern u8 lbl_1_data_21AB8__fzgx_offset_0[];
extern u8 lbl_1_data_21AD8__fzgx_offset_0[];
extern u8 lbl_1_data_21ADC__fzgx_offset_0[];
extern u8 lbl_1_data_224E4__fzgx_offset_0[];
extern u8 lbl_1_data_22514__fzgx_offset_0[];
extern u8 lbl_1_data_22520__fzgx_offset_0[];
extern u8 lbl_1_data_22404__fzgx_offset_0[];
extern u8 lbl_1_data_2242C__fzgx_offset_0[];
extern u8 lbl_1_data_22454__fzgx_offset_0[];
extern u8 lbl_1_data_21798__fzgx_offset_0[];
extern u8 lbl_1_data_217C0__fzgx_offset_0[];
extern u8 lbl_1_data_217E8__fzgx_offset_0[];
extern u8 lbl_1_data_24318__fzgx_offset_0[];
extern u8 lbl_1_data_217F8__fzgx_offset_0[];
extern u8 lbl_1_data_2248C__fzgx_offset_0[];
extern u8 lbl_1_data_224AC__fzgx_offset_0[];
extern u8 lbl_1_data_224B4__fzgx_offset_0[];
extern u8 lbl_1_data_21830__fzgx_offset_0[];
extern u8 lbl_1_data_21860__fzgx_offset_0[];
extern u8 lbl_1_data_21878__fzgx_offset_0[];
extern u8 lbl_1_data_218B8__fzgx_offset_0[];
extern u8 lbl_1_data_218D8__fzgx_offset_0[];
extern u8 lbl_1_data_21900__fzgx_offset_0[];
extern u8 lbl_1_data_21910__fzgx_offset_0[];
extern u8 lbl_1_data_223A0__fzgx_offset_0[];
extern u8 lbl_1_data_223CC__fzgx_offset_0[];
extern u8 lbl_1_data_223D0__fzgx_offset_0[];
extern u8 lbl_1_data_24638__fzgx_offset_0[];
extern u8 lbl_1_data_223B4__fzgx_offset_0[];
extern u8 lbl_1_data_21700__fzgx_offset_0[];
extern u8 lbl_1_data_21728__fzgx_offset_0[];
extern u8 lbl_1_data_2174C__fzgx_offset_0[];
extern u8 lbl_1_data_225E4__fzgx_offset_0[];
extern u8 lbl_1_data_2260C__fzgx_offset_0[];
extern u8 lbl_1_data_22630__fzgx_offset_0[];
extern u8 lbl_1_data_21B14__fzgx_offset_0[];
extern u8 lbl_1_data_21B3C__fzgx_offset_0[];
extern u8 lbl_1_data_21B60__fzgx_offset_0[];
extern u8 lbl_1_data_22098__fzgx_offset_0[];
extern u8 lbl_1_data_220C0__fzgx_offset_0[];
extern u8 lbl_1_data_220E8__fzgx_offset_0[];
extern u8 lbl_1_data_22808__fzgx_offset_0[];
extern u8 lbl_1_data_22834__fzgx_offset_0[];
extern u8 lbl_1_data_2284C__fzgx_offset_0[];
extern u8 lbl_1_data_249E4__fzgx_offset_0[];
extern u8 lbl_1_data_2281C__fzgx_offset_0[];
extern u8 lbl_1_data_249F4__fzgx_offset_0[];
extern u8 lbl_1_data_24A04__fzgx_offset_0[];
extern u8 lbl_1_data_24A14__fzgx_offset_0[];
extern u8 lbl_1_data_24A24__fzgx_offset_0[];
extern u8 lbl_1_data_24A30__fzgx_offset_0[];
extern u8 lbl_1_data_24A3C__fzgx_offset_0[];
extern u8 lbl_1_data_24A48__fzgx_offset_0[];
extern u8 lbl_1_data_24A54__fzgx_offset_0[];
extern u8 lbl_1_data_24A5C__fzgx_offset_0[];
extern u8 lbl_1_data_24A64__fzgx_offset_0[];
extern u8 lbl_1_data_24A6C__fzgx_offset_0[];
extern u8 lbl_1_data_24A74__fzgx_offset_0[];
extern u8 lbl_1_data_24A7C__fzgx_offset_0[];
extern u8 lbl_1_data_24A84__fzgx_offset_0[];
extern u8 lbl_1_data_24A8C__fzgx_offset_0[];
extern u8 lbl_1_data_226FC__fzgx_offset_0[];
extern u8 lbl_1_data_22724__fzgx_offset_0[];
extern u8 lbl_1_data_22744__fzgx_offset_0[];
extern u8 lbl_1_data_21DA8__fzgx_offset_0[];
extern u8 lbl_1_data_21DBC__fzgx_offset_0[];
extern u8 lbl_1_data_21DD0__fzgx_offset_0[];
extern u8 lbl_1_data_24EF0__fzgx_offset_0[];
extern u8 lbl_1_data_21A90__fzgx_offset_0[];
extern u8 lbl_1_data_21638__fzgx_offset_0[];
extern u8 lbl_1_data_21D08__fzgx_offset_0[];
extern u8 lbl_1_data_22374__fzgx_offset_0[];
extern u8 lbl_1_data_228DC__fzgx_offset_0[];
extern u8 lbl_1_data_21F60__fzgx_offset_0[];
extern u8 lbl_1_data_222F4__fzgx_offset_0[];
extern u8 lbl_1_data_216D0__fzgx_offset_0[];
extern u8 lbl_1_data_21990__fzgx_offset_0[];
extern u8 lbl_1_data_21E64__fzgx_offset_0[];
extern u8 lbl_1_data_22278__fzgx_offset_0[];
extern u8 lbl_1_data_225BC__fzgx_offset_0[];
extern u8 lbl_1_data_214C4__fzgx_offset_0[];
extern u8 lbl_1_data_22964__fzgx_offset_0[];
extern u8 lbl_1_data_21444__fzgx_offset_0[];
extern u8 lbl_1_data_21FE4__fzgx_offset_0[];
extern u8 lbl_1_data_22068__fzgx_offset_0[];
extern u8 lbl_1_data_213C4__fzgx_offset_0[];
extern u8 lbl_1_data_21C8C__fzgx_offset_0[];
extern u8 lbl_1_data_22170__fzgx_offset_0[];
extern u8 lbl_1_data_21D80__fzgx_offset_0[];
extern u8 lbl_1_data_21EDC__fzgx_offset_0[];
extern u8 lbl_1_data_215C8__fzgx_offset_0[];
extern u8 lbl_1_data_226D4__fzgx_offset_0[];
extern u8 lbl_1_data_221F4__fzgx_offset_0[];
extern u8 lbl_1_data_21C00__fzgx_offset_0[];
extern u8 lbl_1_data_21C10__fzgx_offset_0[];
extern u8 lbl_1_data_227D0__fzgx_offset_0[];
extern u8 lbl_1_data_227E0__fzgx_offset_0[];
extern u8 lbl_1_data_21A14__fzgx_offset_0[];
extern u8 lbl_1_data_229E8__fzgx_offset_0[];
extern u8 lbl_1_data_21AEC__fzgx_offset_0[];
extern u8 lbl_1_data_2154C__fzgx_offset_0[];
extern u8 lbl_1_data_22528__fzgx_offset_0[];
extern u8 lbl_1_data_22464__fzgx_offset_0[];
extern u8 lbl_1_data_217FC__fzgx_offset_0[];
extern u8 lbl_1_data_224B8__fzgx_offset_0[];
extern u8 lbl_1_data_21888__fzgx_offset_0[];
extern u8 lbl_1_data_21914__fzgx_offset_0[];
extern u8 lbl_1_data_223DC__fzgx_offset_0[];
extern u8 lbl_1_data_2175C__fzgx_offset_0[];
extern u8 lbl_1_data_2176C__fzgx_offset_0[];
extern u8 lbl_1_data_22640__fzgx_offset_0[];
extern u8 lbl_1_data_22650__fzgx_offset_0[];
extern u8 lbl_1_data_21B70__fzgx_offset_0[];
extern u8 lbl_1_data_21B80__fzgx_offset_0[];
extern u8 lbl_1_data_220F8__fzgx_offset_0[];
extern u8 lbl_1_data_2285C__fzgx_offset_0[];
extern u8 lbl_1_data_22754__fzgx_offset_0[];
extern u8 lbl_1_data_21DE0__fzgx_offset_0[];
extern u8 lbl_1_data_21AA0__fzgx_offset_0[];
extern u8 lbl_1_data_21648__fzgx_offset_0[];
extern u8 lbl_1_data_21D18__fzgx_offset_0[];
extern u8 lbl_1_data_22384__fzgx_offset_0[];
extern u8 lbl_1_data_228EC__fzgx_offset_0[];
extern u8 lbl_1_data_21F70__fzgx_offset_0[];
extern u8 lbl_1_data_22310__fzgx_offset_0[];
extern u8 lbl_1_data_216E4__fzgx_offset_0[];
extern u8 lbl_1_data_219A4__fzgx_offset_0[];
extern u8 lbl_1_data_21E74__fzgx_offset_0[];
extern u8 lbl_1_data_22288__fzgx_offset_0[];
extern u8 lbl_1_data_225CC__fzgx_offset_0[];
extern u8 lbl_1_data_214D4__fzgx_offset_0[];
extern u8 lbl_1_data_22974__fzgx_offset_0[];
extern u8 lbl_1_data_21454__fzgx_offset_0[];
extern u8 lbl_1_data_21FF4__fzgx_offset_0[];
extern u8 lbl_1_data_2207C__fzgx_offset_0[];
extern u8 lbl_1_data_213D4__fzgx_offset_0[];
extern u8 lbl_1_data_21C9C__fzgx_offset_0[];
extern u8 lbl_1_data_22180__fzgx_offset_0[];
extern u8 lbl_1_data_21D90__fzgx_offset_0[];
extern u8 lbl_1_data_21EEC__fzgx_offset_0[];
extern u8 lbl_1_data_215D8__fzgx_offset_0[];
extern u8 lbl_1_data_226E4__fzgx_offset_0[];
extern u8 lbl_1_data_22204__fzgx_offset_0[];
extern u8 lbl_1_data_21C20__fzgx_offset_0[];
extern u8 lbl_1_data_227F0__fzgx_offset_0[];
extern u8 lbl_1_data_21A24__fzgx_offset_0[];
extern u8 lbl_1_data_229F8__fzgx_offset_0[];
extern u8 lbl_1_data_21AFC__fzgx_offset_0[];
extern u8 lbl_1_data_2155C__fzgx_offset_0[];
extern u8 lbl_1_data_2253C__fzgx_offset_0[];
extern u8 lbl_1_data_22474__fzgx_offset_0[];
extern u8 lbl_1_data_21810__fzgx_offset_0[];
extern u8 lbl_1_data_224C8__fzgx_offset_0[];
extern u8 lbl_1_data_2189C__fzgx_offset_0[];
extern u8 lbl_1_data_21924__fzgx_offset_0[];
extern u8 lbl_1_data_223EC__fzgx_offset_0[];
extern u8 lbl_1_data_2177C__fzgx_offset_0[];
extern u8 lbl_1_data_22660__fzgx_offset_0[];
extern u8 lbl_1_data_21B90__fzgx_offset_0[];
extern u8 lbl_1_data_22108__fzgx_offset_0[];
extern u8 lbl_1_data_2286C__fzgx_offset_0[];
extern u8 lbl_1_data_22764__fzgx_offset_0[];
extern u8 lbl_1_data_21DF0__fzgx_offset_0[];
extern u8 lbl_1_data_21AB0__fzgx_offset_0[];
extern u8 lbl_1_data_21658__fzgx_offset_0[];
extern u8 lbl_1_data_21D28__fzgx_offset_0[];
extern u8 lbl_1_data_22394__fzgx_offset_0[];
extern u8 lbl_1_data_228FC__fzgx_offset_0[];
extern u8 lbl_1_data_21F80__fzgx_offset_0[];
extern u8 lbl_1_data_2232C__fzgx_offset_0[];
extern u8 lbl_1_data_216F8__fzgx_offset_0[];
extern u8 lbl_1_data_219B8__fzgx_offset_0[];
extern u8 lbl_1_data_21E84__fzgx_offset_0[];
extern u8 lbl_1_data_22298__fzgx_offset_0[];
extern u8 lbl_1_data_225DC__fzgx_offset_0[];
extern u8 lbl_1_data_214E4__fzgx_offset_0[];
extern u8 lbl_1_data_22984__fzgx_offset_0[];
extern u8 lbl_1_data_21464__fzgx_offset_0[];
extern u8 lbl_1_data_22004__fzgx_offset_0[];
extern u8 lbl_1_data_22090__fzgx_offset_0[];
extern u8 lbl_1_data_213E4__fzgx_offset_0[];
extern u8 lbl_1_data_21CAC__fzgx_offset_0[];
extern u8 lbl_1_data_22190__fzgx_offset_0[];
extern u8 lbl_1_data_21DA0__fzgx_offset_0[];
extern u8 lbl_1_data_21EFC__fzgx_offset_0[];
extern u8 lbl_1_data_215E8__fzgx_offset_0[];
extern u8 lbl_1_data_226F4__fzgx_offset_0[];
extern u8 lbl_1_data_22214__fzgx_offset_0[];
extern u8 lbl_1_data_21C30__fzgx_offset_0[];
extern u8 lbl_1_data_22800__fzgx_offset_0[];
extern u8 lbl_1_data_21A34__fzgx_offset_0[];
extern u8 lbl_1_data_22A08__fzgx_offset_0[];
extern u8 lbl_1_data_21B0C__fzgx_offset_0[];
extern u8 lbl_1_data_2156C__fzgx_offset_0[];
extern u8 lbl_1_data_22550__fzgx_offset_0[];
extern u8 lbl_1_data_22484__fzgx_offset_0[];
extern u8 lbl_1_data_21824__fzgx_offset_0[];
extern u8 lbl_1_data_224D8__fzgx_offset_0[];
extern u8 lbl_1_data_218B0__fzgx_offset_0[];
extern u8 lbl_1_data_21934__fzgx_offset_0[];
extern u8 lbl_1_data_223FC__fzgx_offset_0[];
extern u8 lbl_1_data_2178C__fzgx_offset_0[];
extern u8 lbl_1_data_22670__fzgx_offset_0[];
extern u8 lbl_1_data_21BA0__fzgx_offset_0[];
extern u8 lbl_1_data_22118__fzgx_offset_0[];
extern u8 lbl_1_data_2287C__fzgx_offset_0[];
extern u8 lbl_1_data_22774__fzgx_offset_0[];
extern u8 lbl_1_data_21E00__fzgx_offset_0[];
extern u8 lbl_1_data_240B4__fzgx_offset_0[];
extern u8 lbl_1_data_22E0C__fzgx_offset_0[];
extern u8 lbl_1_data_22D40__fzgx_offset_0[];
extern u8 lbl_1_data_23500__fzgx_offset_0[];
extern u8 lbl_1_data_22BD8__fzgx_offset_0[];
extern u8 lbl_1_data_22C8C__fzgx_offset_0[];
extern u8 lbl_1_data_22A4C__fzgx_offset_0[];
extern u8 lbl_1_data_22FBC__fzgx_offset_0[];
extern u8 lbl_1_data_23E98__fzgx_offset_0[];
extern u8 lbl_1_data_23A60__fzgx_offset_0[];
extern u8 lbl_1_data_24000__fzgx_offset_0[];
extern u8 lbl_1_data_235FC__fzgx_offset_0[];
extern u8 lbl_1_data_23F4C__fzgx_offset_0[];
extern u8 lbl_1_data_22F08__fzgx_offset_0[];
extern u8 lbl_1_data_24168__fzgx_offset_0[];
extern u8 lbl_1_data_23844__fzgx_offset_0[];
extern u8 lbl_1_data_239AC__fzgx_offset_0[];
extern u8 lbl_1_data_23324__fzgx_offset_0[];
extern u8 lbl_1_data_23790__fzgx_offset_0[];
extern u8 lbl_1_data_236B8__fzgx_offset_0[];
extern u8 lbl_1_data_23C7C__fzgx_offset_0[];
extern u8 lbl_1_data_23DE4__fzgx_offset_0[];
extern u8 lbl_1_data_23198__fzgx_offset_0[];
extern u8 lbl_1_data_238F8__fzgx_offset_0[];
extern u8 lbl_1_data_23B14__fzgx_offset_0[];
extern u8 lbl_1_data_23428__fzgx_offset_0[];
extern u8 lbl_1_data_230DC__fzgx_offset_0[];
extern u8 lbl_1_data_23270__fzgx_offset_0[];
extern u8 lbl_1_data_23028__fzgx_offset_0[];
extern u8 lbl_1_data_23BC8__fzgx_offset_0[];
extern u8 lbl_1_data_22B24__fzgx_offset_0[];
extern u8 lbl_1_data_24560__fzgx_offset_0[];
extern u8 lbl_1_data_244AC__fzgx_offset_0[];
extern u8 lbl_1_data_24714__fzgx_offset_0[];
extern u8 lbl_1_data_24A94__fzgx_offset_0[];
extern u8 lbl_1_data_24320__fzgx_offset_0[];
extern u8 lbl_1_data_2421C__fzgx_offset_0[];
extern u8 lbl_1_data_24930__fzgx_offset_0[];
extern u8 lbl_1_data_2463C__fzgx_offset_0[];
extern u8 lbl_1_data_243F8__fzgx_offset_0[];
extern u8 lbl_1_data_24D88__fzgx_offset_0[];
extern u8 lbl_1_data_23D30__fzgx_offset_0[];
extern u8 lbl_1_data_247C8__fzgx_offset_0[];
extern u8 lbl_1_data_2487C__fzgx_offset_0[];
extern u8 lbl_1_data_24E3C__fzgx_offset_0[];
extern u8 lbl_1_data_25408__fzgx_offset_0[];
extern u8 lbl_1_data_24FAC__fzgx_offset_0[];
extern u8 lbl_1_data_24F88__fzgx_offset_0[];
extern u8 lbl_1_data_25138__fzgx_offset_0[];
extern u8 lbl_1_data_24F40__fzgx_offset_0[];
extern u8 lbl_1_data_24F64__fzgx_offset_0[];
extern u8 lbl_1_data_24EF8__fzgx_offset_0[];
extern u8 lbl_1_data_24FD0__fzgx_offset_0[];
extern u8 lbl_1_data_253C0__fzgx_offset_0[];
extern u8 lbl_1_data_25258__fzgx_offset_0[];
extern u8 lbl_1_data_2542C__fzgx_offset_0[];
extern u8 lbl_1_data_2515C__fzgx_offset_0[];
extern u8 lbl_1_data_253E4__fzgx_offset_0[];
extern u8 lbl_1_data_2503C__fzgx_offset_0[];
extern u8 lbl_1_data_25450__fzgx_offset_0[];
extern u8 lbl_1_data_251EC__fzgx_offset_0[];
extern u8 lbl_1_data_25234__fzgx_offset_0[];
extern u8 lbl_1_data_250CC__fzgx_offset_0[];
extern u8 lbl_1_data_25180__fzgx_offset_0[];
extern u8 lbl_1_data_251A4__fzgx_offset_0[];
extern u8 lbl_1_data_252C4__fzgx_offset_0[];
extern u8 lbl_1_data_25354__fzgx_offset_0[];
extern u8 lbl_1_data_25060__fzgx_offset_0[];
extern u8 lbl_1_data_25210__fzgx_offset_0[];
extern u8 lbl_1_data_2527C__fzgx_offset_0[];
extern u8 lbl_1_data_250F0__fzgx_offset_0[];
extern u8 lbl_1_data_25018__fzgx_offset_0[];
extern u8 lbl_1_data_250A8__fzgx_offset_0[];
extern u8 lbl_1_data_24FF4__fzgx_offset_0[];
extern u8 lbl_1_data_252A0__fzgx_offset_0[];
extern u8 lbl_1_data_24F1C__fzgx_offset_0[];
extern u8 lbl_1_data_25528__fzgx_offset_0[];
extern u8 lbl_1_data_25504__fzgx_offset_0[];
extern u8 lbl_1_data_255B8__fzgx_offset_0[];
extern u8 lbl_1_data_25720__fzgx_offset_0[];
extern u8 lbl_1_data_25498__fzgx_offset_0[];
extern u8 lbl_1_data_25474__fzgx_offset_0[];
extern u8 lbl_1_data_256FC__fzgx_offset_0[];
extern u8 lbl_1_data_25570__fzgx_offset_0[];
extern u8 lbl_1_data_254E0__fzgx_offset_0[];
extern u8 lbl_1_data_25984__fzgx_offset_0[];
extern u8 lbl_1_data_252E8__fzgx_offset_0[];
extern u8 lbl_1_data_25624__fzgx_offset_0[];
extern u8 lbl_1_data_25690__fzgx_offset_0[];
extern u8 lbl_1_data_259A8__fzgx_offset_0[];
extern u8 lbl_1_data_25DE0__fzgx_offset_0[];
extern u8 lbl_1_data_25A80__fzgx_offset_0[];
extern u8 lbl_1_data_25A5C__fzgx_offset_0[];
extern u8 lbl_1_data_25BC4__fzgx_offset_0[];
extern u8 lbl_1_data_25A14__fzgx_offset_0[];
extern u8 lbl_1_data_25A38__fzgx_offset_0[];
extern u8 lbl_1_data_259CC__fzgx_offset_0[];
extern u8 lbl_1_data_25AA4__fzgx_offset_0[];
extern u8 lbl_1_data_25D98__fzgx_offset_0[];
extern u8 lbl_1_data_25CC0__fzgx_offset_0[];
extern u8 lbl_1_data_25E04__fzgx_offset_0[];
extern u8 lbl_1_data_25BE8__fzgx_offset_0[];
extern u8 lbl_1_data_25DBC__fzgx_offset_0[];
extern u8 lbl_1_data_25B10__fzgx_offset_0[];
extern u8 lbl_1_data_25E28__fzgx_offset_0[];
extern u8 lbl_1_data_25C54__fzgx_offset_0[];
extern u8 lbl_1_data_25C9C__fzgx_offset_0[];
extern u8 lbl_1_data_25B7C__fzgx_offset_0[];
extern u8 lbl_1_data_25C0C__fzgx_offset_0[];
extern u8 lbl_1_data_25C30__fzgx_offset_0[];
extern u8 lbl_1_data_25D2C__fzgx_offset_0[];
extern u8 lbl_1_data_25D74__fzgx_offset_0[];
extern u8 lbl_1_data_25B34__fzgx_offset_0[];
extern u8 lbl_1_data_25C78__fzgx_offset_0[];
extern u8 lbl_1_data_25CE4__fzgx_offset_0[];
extern u8 lbl_1_data_25BA0__fzgx_offset_0[];
extern u8 lbl_1_data_25AEC__fzgx_offset_0[];
extern u8 lbl_1_data_25B58__fzgx_offset_0[];
extern u8 lbl_1_data_25AC8__fzgx_offset_0[];
extern u8 lbl_1_data_25D08__fzgx_offset_0[];
extern u8 lbl_1_data_259F0__fzgx_offset_0[];
extern u8 lbl_1_data_25EDC__fzgx_offset_0[];
extern u8 lbl_1_data_25EB8__fzgx_offset_0[];
extern u8 lbl_1_data_25F24__fzgx_offset_0[];
extern u8 lbl_1_data_25FB4__fzgx_offset_0[];
extern u8 lbl_1_data_25E70__fzgx_offset_0[];
extern u8 lbl_1_data_25E4C__fzgx_offset_0[];
extern u8 lbl_1_data_25F90__fzgx_offset_0[];
extern u8 lbl_1_data_25F00__fzgx_offset_0[];
extern u8 lbl_1_data_25E94__fzgx_offset_0[];
extern u8 lbl_1_data_25FD8__fzgx_offset_0[];
extern u8 lbl_1_data_25D50__fzgx_offset_0[];
extern u8 lbl_1_data_25F48__fzgx_offset_0[];
extern u8 lbl_1_data_25F6C__fzgx_offset_0[];
extern u8 lbl_1_data_25FFC__fzgx_offset_0[];
extern u8 lbl_1_data_26434__fzgx_offset_0[];
extern u8 lbl_1_data_260D4__fzgx_offset_0[];
extern u8 lbl_1_data_260B0__fzgx_offset_0[];
extern u8 lbl_1_data_26218__fzgx_offset_0[];
extern u8 lbl_1_data_26068__fzgx_offset_0[];
extern u8 lbl_1_data_2608C__fzgx_offset_0[];
extern u8 lbl_1_data_26020__fzgx_offset_0[];
extern u8 lbl_1_data_260F8__fzgx_offset_0[];
extern u8 lbl_1_data_263EC__fzgx_offset_0[];
extern u8 lbl_1_data_26314__fzgx_offset_0[];
extern u8 lbl_1_data_26458__fzgx_offset_0[];
extern u8 lbl_1_data_2623C__fzgx_offset_0[];
extern u8 lbl_1_data_26410__fzgx_offset_0[];
extern u8 lbl_1_data_26164__fzgx_offset_0[];
extern u8 lbl_1_data_2647C__fzgx_offset_0[];
extern u8 lbl_1_data_262A8__fzgx_offset_0[];
extern u8 lbl_1_data_262F0__fzgx_offset_0[];
extern u8 lbl_1_data_261D0__fzgx_offset_0[];
extern u8 lbl_1_data_26260__fzgx_offset_0[];
extern u8 lbl_1_data_26284__fzgx_offset_0[];
extern u8 lbl_1_data_26380__fzgx_offset_0[];
extern u8 lbl_1_data_263C8__fzgx_offset_0[];
extern u8 lbl_1_data_26188__fzgx_offset_0[];
extern u8 lbl_1_data_262CC__fzgx_offset_0[];
extern u8 lbl_1_data_26338__fzgx_offset_0[];
extern u8 lbl_1_data_261F4__fzgx_offset_0[];
extern u8 lbl_1_data_26140__fzgx_offset_0[];
extern u8 lbl_1_data_261AC__fzgx_offset_0[];
extern u8 lbl_1_data_2611C__fzgx_offset_0[];
extern u8 lbl_1_data_2635C__fzgx_offset_0[];
extern u8 lbl_1_data_26044__fzgx_offset_0[];
extern u8 lbl_1_data_26530__fzgx_offset_0[];
extern u8 lbl_1_data_2650C__fzgx_offset_0[];
extern u8 lbl_1_data_26578__fzgx_offset_0[];
extern u8 lbl_1_data_26608__fzgx_offset_0[];
extern u8 lbl_1_data_264C4__fzgx_offset_0[];
extern u8 lbl_1_data_264A0__fzgx_offset_0[];
extern u8 lbl_1_data_265E4__fzgx_offset_0[];
extern u8 lbl_1_data_26554__fzgx_offset_0[];
extern u8 lbl_1_data_264E8__fzgx_offset_0[];
extern u8 lbl_1_data_2662C__fzgx_offset_0[];
extern u8 lbl_1_data_263A4__fzgx_offset_0[];
extern u8 lbl_1_data_2659C__fzgx_offset_0[];
extern u8 lbl_1_data_265C0__fzgx_offset_0[];
extern u8 lbl_1_data_26650__fzgx_offset_0[];
extern u8 lbl_1_data_26D8C__fzgx_offset_0[];
extern u8 lbl_1_data_26D94__fzgx_offset_0[];
extern u8 lbl_1_data_26D9C__fzgx_offset_0[];
extern u8 lbl_1_data_26DA4__fzgx_offset_0[];
extern u8 lbl_1_data_26DAC__fzgx_offset_0[];
extern u8 lbl_1_data_26DB4__fzgx_offset_0[];
extern u8 lbl_1_data_26DDC__fzgx_offset_0[];
extern u8 lbl_1_data_26DE4__fzgx_offset_0[];
extern u8 lbl_1_data_26DEC__fzgx_offset_0[];
extern u8 lbl_1_data_26DF4__fzgx_offset_0[];
extern u8 lbl_1_data_26E00__fzgx_offset_0[];
extern u8 lbl_1_data_26E0C__fzgx_offset_0[];
extern u8 lbl_1_data_26E14__fzgx_offset_0[];
extern u8 lbl_1_data_26E1C__fzgx_offset_0[];
extern u8 lbl_1_data_26E24__fzgx_offset_0[];
extern u8 lbl_1_data_26E2C__fzgx_offset_0[];
extern u8 lbl_1_data_26E34__fzgx_offset_0[];
extern u8 lbl_1_data_26E3C__fzgx_offset_0[];
extern u8 lbl_1_data_26E44__fzgx_offset_0[];
extern u8 lbl_1_data_26E4C__fzgx_offset_0[];
extern u8 lbl_1_data_26E54__fzgx_offset_0[];
extern u8 lbl_1_data_26E5C__fzgx_offset_0[];
extern u8 lbl_1_data_26E64__fzgx_offset_0[];
extern u8 lbl_1_data_26E6C__fzgx_offset_0[];
extern u8 lbl_1_data_26E74__fzgx_offset_0[];
extern u8 lbl_1_data_26E7C__fzgx_offset_0[];
extern u8 lbl_1_data_26E84__fzgx_offset_0[];
extern u8 lbl_1_data_26E8C__fzgx_offset_0[];
extern u8 lbl_1_data_26E94__fzgx_offset_0[];
extern u8 lbl_1_data_26E9C__fzgx_offset_0[];
extern u8 lbl_1_data_26EA4__fzgx_offset_0[];
extern u8 lbl_1_data_26EB0__fzgx_offset_0[];
extern u8 lbl_1_data_26EBC__fzgx_offset_0[];
extern u8 lbl_1_data_26EC8__fzgx_offset_0[];
extern u8 lbl_1_data_26ED4__fzgx_offset_0[];
extern u8 lbl_1_data_26EE0__fzgx_offset_0[];
extern u8 lbl_1_data_26EEC__fzgx_offset_0[];
extern u8 lbl_1_data_26EF8__fzgx_offset_0[];
extern u8 lbl_1_data_26F04__fzgx_offset_0[];
extern u8 lbl_1_data_26F10__fzgx_offset_0[];
extern u8 lbl_1_data_26F1C__fzgx_offset_0[];
extern u8 lbl_1_data_26F28__fzgx_offset_0[];
extern u8 lbl_1_data_26F34__fzgx_offset_0[];
extern u8 lbl_1_data_26F40__fzgx_offset_0[];
extern u8 lbl_1_data_26F4C__fzgx_offset_0[];
extern u8 lbl_1_data_26F58__fzgx_offset_0[];
extern u8 lbl_1_data_26F64__fzgx_offset_0[];
extern u8 lbl_1_data_26F70__fzgx_offset_0[];
extern u8 lbl_1_data_26F7C__fzgx_offset_0[];
extern u8 lbl_1_data_26F88__fzgx_offset_0[];
extern u8 lbl_1_data_27048__fzgx_offset_0[];
extern u8 lbl_1_data_27058__fzgx_offset_0[];
extern u8 lbl_1_data_27060__fzgx_offset_0[];
extern u8 lbl_1_data_2706C__fzgx_offset_0[];
extern u8 lbl_1_data_2707C__fzgx_offset_0[];
extern u8 lbl_1_data_27088__fzgx_offset_0[];
extern u8 lbl_1_data_27094__fzgx_offset_0[];
extern u8 lbl_1_data_270A0__fzgx_offset_0[];
extern u8 lbl_1_data_270B0__fzgx_offset_0[];
extern u8 lbl_1_data_270C0__fzgx_offset_0[];
extern u8 lbl_1_data_270CC__fzgx_offset_0[];
extern u8 lbl_1_data_270D8__fzgx_offset_0[];
extern u8 lbl_1_data_270E4__fzgx_offset_0[];
extern u8 lbl_1_data_270F0__fzgx_offset_0[];
extern u8 lbl_1_data_270FC__fzgx_offset_0[];
extern u8 lbl_1_data_27108__fzgx_offset_0[];
extern u8 lbl_1_data_27114__fzgx_offset_0[];
extern u8 lbl_1_data_27124__fzgx_offset_0[];
extern u8 lbl_1_data_27134__fzgx_offset_0[];
extern u8 lbl_1_data_27144__fzgx_offset_0[];
extern u8 lbl_1_data_27150__fzgx_offset_0[];
extern u8 lbl_1_data_2715C__fzgx_offset_0[];
extern u8 lbl_1_data_27168__fzgx_offset_0[];
extern u8 lbl_1_data_27174__fzgx_offset_0[];
extern u8 lbl_1_data_27184__fzgx_offset_0[];
extern u8 lbl_1_data_27194__fzgx_offset_0[];
extern u8 lbl_1_data_271A0__fzgx_offset_0[];
extern u8 lbl_1_data_271B0__fzgx_offset_0[];
extern u8 lbl_1_data_271BC__fzgx_offset_0[];
extern u8 lbl_1_data_271C8__fzgx_offset_0[];
extern u8 lbl_1_data_271D4__fzgx_offset_0[];
extern u8 lbl_1_data_271E4__fzgx_offset_0[];
extern u8 lbl_1_data_271F0__fzgx_offset_0[];
extern u8 lbl_1_data_271FC__fzgx_offset_0[];
extern u8 lbl_1_data_2720C__fzgx_offset_0[];
extern u8 lbl_1_data_27218__fzgx_offset_0[];
extern u8 lbl_1_data_27224__fzgx_offset_0[];
extern u8 lbl_1_data_27234__fzgx_offset_0[];
extern u8 lbl_1_data_27244__fzgx_offset_0[];
extern u8 lbl_1_data_27250__fzgx_offset_0[];
extern u8 lbl_1_data_2725C__fzgx_offset_0[];
extern u8 lbl_1_data_27268__fzgx_offset_0[];
extern u8 lbl_1_data_27278__fzgx_offset_0[];
extern u8 lbl_1_data_27284__fzgx_offset_0[];
extern u8 lbl_1_data_27290__fzgx_offset_0[];
extern u8 lbl_1_data_2729C__fzgx_offset_0[];
extern u8 lbl_1_data_272A8__fzgx_offset_0[];
extern u8 lbl_1_data_272B0__fzgx_offset_0[];
extern u8 lbl_1_data_272BC__fzgx_offset_0[];
extern u8 lbl_1_data_272C0__fzgx_offset_0[];
extern u8 lbl_1_data_272D0__fzgx_offset_0[];
extern u8 lbl_1_data_272D4__fzgx_offset_0[];
extern u8 lbl_1_data_272E4__fzgx_offset_0[];
extern u8 lbl_1_data_272EC__fzgx_offset_0[];
extern u8 lbl_1_data_272F8__fzgx_offset_0[];
extern u8 lbl_1_data_27300__fzgx_offset_0[];
extern u8 lbl_1_data_27304__fzgx_offset_0[];
extern u8 lbl_1_data_27318__fzgx_offset_0[];
extern u8 lbl_1_data_27324__fzgx_offset_0[];
extern u8 lbl_1_data_27338__fzgx_offset_0[];
extern u8 lbl_1_data_27344__fzgx_offset_0[];
extern u8 lbl_1_data_27358__fzgx_offset_0[];
extern u8 lbl_1_data_27364__fzgx_offset_0[];
extern u8 lbl_1_data_27378__fzgx_offset_0[];
extern u8 lbl_1_data_27384__fzgx_offset_0[];
extern u8 lbl_1_data_27398__fzgx_offset_0[];
extern u8 lbl_1_data_273A8__fzgx_offset_0[];
extern u8 lbl_1_data_273BC__fzgx_offset_0[];
extern u8 lbl_1_data_273CC__fzgx_offset_0[];
extern u8 lbl_1_data_273E0__fzgx_offset_0[];
extern u8 lbl_1_data_273F0__fzgx_offset_0[];
extern u8 lbl_1_data_27404__fzgx_offset_0[];
extern u8 lbl_1_data_27414__fzgx_offset_0[];
extern u8 lbl_1_data_27424__fzgx_offset_0[];
extern u8 lbl_1_data_2742C__fzgx_offset_0[];
extern u8 lbl_1_data_2743C__fzgx_offset_0[];
extern u8 lbl_1_data_27444__fzgx_offset_0[];
extern u8 lbl_1_data_27454__fzgx_offset_0[];
extern u8 lbl_1_data_2745C__fzgx_offset_0[];
extern u8 lbl_1_data_2746C__fzgx_offset_0[];
extern u8 lbl_1_data_27474__fzgx_offset_0[];
extern u8 lbl_1_data_27484__fzgx_offset_0[];
extern u8 lbl_1_data_2748C__fzgx_offset_0[];
extern u8 lbl_1_data_2749C__fzgx_offset_0[];
extern u8 lbl_1_data_274A4__fzgx_offset_0[];
extern u8 lbl_1_data_274B4__fzgx_offset_0[];
extern u8 lbl_1_data_274BC__fzgx_offset_0[];
extern u8 lbl_1_data_274CC__fzgx_offset_0[];
extern u8 lbl_1_bss_6E990__fzgx_offset_0[];
extern u8 fn_1_9012C__fzgx_offset_3D4[];
extern u8 fn_1_9012C__fzgx_offset_40C[];
extern u8 fn_1_9012C__fzgx_offset_440[];
extern u8 fn_1_9012C__fzgx_offset_468[];
extern u8 fn_1_9012C__fzgx_offset_488[];
extern u8 fn_1_9012C__fzgx_offset_4A8[];
extern u8 fn_1_9012C__fzgx_offset_4FC[];
extern u8 fn_1_9012C__fzgx_offset_53C[];
extern u8 fn_1_9012C__fzgx_offset_5B0[];
extern u8 fn_1_9012C__fzgx_offset_624[];
extern u8 fn_1_9012C__fzgx_offset_698[];
extern u8 fn_1_9012C__fzgx_offset_70C[];
extern u8 fn_1_9012C__fzgx_offset_780[];
extern u8 fn_1_9012C__fzgx_offset_7EC[];
static u32 fzgx_pool_data_prefix[7372] = { /* fzgx-allow: A1 measured retail bytes and bindings */
    0x47415a45, 0x4c4c4500, 0x4a4f4459, 0x00000000, 0x53544557, 0x41525400, 0x42414241, 0x00000000,
    0x474f524f, 0x48000000, 0x5049434f, 0x00000000, 0x46414c43, 0x4f4e0000, 0x4f43544d, 0x414e0000,
    0x45414400, 0x4a414d45, 0x53000000, 0x42494c4c, 0x59000000, 0x4b415445, 0x00000000, 0x5a4f4441,
    0x00000000, 0x4a41434b, 0x00000000, 0x52455800, 0x474f5244, 0x4f4e0000, 0x47555354, 0x45520000,
    0x42454153, 0x544d414e, 0x00000000, 0x4c454f4e, 0x00000000, 0x4152524f, 0x57000000, 0x4d525300,
    0x5348494f, 0x00000000, 0x4e45454c, 0x53454e00, 0x4d494348, 0x41454c00, 0x424c4f4f, 0x44000000,
    0x54414e41, 0x4b410000, 0x44524151, 0x00000000, 0x524f4745, 0x52000000, 0x434c4153, 0x48000000,
    0x53484144, 0x4f570000, 0x424f5353, 0x00000000, 0x444f4e00, 0x44494749, 0x424f5900, 0x44414900,
    0x53504144, 0x45000000, 0x44414947, 0x4f524f48, 0x00000000, 0x50524953, 0x49410000, 0x4c494c59,
    0x00000000, 0x504a0000, 0x51515100, 0x53484552, 0x4c4f434b, 0x00000000, 0x474f4d41, 0x00000000,
    0x53414e00, 0x47454e00, 0x494e5445, 0x52564945, 0x57455200, (u32)lbl_1_data_209C0__fzgx_offset_0, (u32)lbl_1_data_209C8__fzgx_offset_0, (u32)lbl_1_data_209D0__fzgx_offset_0,
    (u32)lbl_1_data_209D8__fzgx_offset_0, (u32)lbl_1_data_209E0__fzgx_offset_0, (u32)lbl_1_data_209E8__fzgx_offset_0, (u32)lbl_1_data_209F0__fzgx_offset_0, (u32)lbl_1_data_209F8__fzgx_offset_0, (u32)lbl_1_data_20A00__fzgx_offset_0, (u32)lbl_1_data_20A04__fzgx_offset_0, (u32)lbl_1_data_20A0C__fzgx_offset_0,
    (u32)lbl_1_data_20A14__fzgx_offset_0, (u32)lbl_1_data_20A1C__fzgx_offset_0, (u32)lbl_1_data_20A24__fzgx_offset_0, (u32)lbl_1_data_20A2C__fzgx_offset_0, (u32)lbl_1_data_20A30__fzgx_offset_0, (u32)lbl_1_data_20A38__fzgx_offset_0, (u32)lbl_1_data_20A40__fzgx_offset_0, (u32)lbl_1_data_20A4C__fzgx_offset_0,
    (u32)lbl_1_data_20A54__fzgx_offset_0, (u32)lbl_1_data_20A5C__fzgx_offset_0, (u32)lbl_1_data_20A60__fzgx_offset_0, (u32)lbl_1_data_20A68__fzgx_offset_0, (u32)lbl_1_data_20A70__fzgx_offset_0, (u32)lbl_1_data_20A78__fzgx_offset_0, (u32)lbl_1_data_20A80__fzgx_offset_0, (u32)lbl_1_data_20A88__fzgx_offset_0,
    (u32)lbl_1_data_20A90__fzgx_offset_0, (u32)lbl_1_data_20A98__fzgx_offset_0, (u32)lbl_1_data_20AA0__fzgx_offset_0, (u32)lbl_1_data_20AA8__fzgx_offset_0, (u32)lbl_1_data_20AB0__fzgx_offset_0, (u32)lbl_1_data_20AB4__fzgx_offset_0, (u32)lbl_1_data_20ABC__fzgx_offset_0, (u32)lbl_1_data_20AC0__fzgx_offset_0,
    (u32)lbl_1_data_20AC8__fzgx_offset_0, (u32)lbl_1_data_20AD4__fzgx_offset_0, (u32)lbl_1_data_20ADC__fzgx_offset_0, (u32)lbl_1_data_20AE4__fzgx_offset_0, (u32)lbl_1_data_20AE8__fzgx_offset_0, (u32)lbl_1_data_20AEC__fzgx_offset_0, (u32)lbl_1_data_20AF8__fzgx_offset_0, (u32)lbl_1_data_20B00__fzgx_offset_0,
    (u32)lbl_1_data_20B04__fzgx_offset_0, (u32)lbl_1_data_20B08__fzgx_offset_0, 0x67617a65, 0x6c6c6500, 0x6a6f6479, 0x00000000, 0x73746577, 0x61727400,
    0x62616261, 0x00000000, 0x676f726f, 0x68000000, 0x7069636f, 0x00000000, 0x66616c63, 0x6f6e0000,
    0x6f63746d, 0x616e0000, 0x65616400, 0x6a616d65, 0x73000000, 0x62696c6c, 0x79000000, 0x6b617465,
    0x00000000, 0x7a6f6461, 0x00000000, 0x6a61636b, 0x00000000, 0x72657800, 0x676f7264, 0x6f6e0000,
    0x67757374, 0x65720000, 0x62656173, 0x746d616e, 0x00000000, 0x6c656f6e, 0x00000000, 0x6172726f,
    0x77000000, 0x6d727300, 0x7368696f, 0x00000000, 0x6e65656c, 0x73656e00, 0x6d696368, 0x61656c00,
    0x626c6f6f, 0x64000000, 0x74616e61, 0x6b610000, 0x64726171, 0x00000000, 0x726f6765, 0x72000000,
    0x636c6173, 0x68000000, 0x73686164, 0x6f770000, 0x626f7373, 0x00000000, 0x646f6e00, 0x64696769,
    0x626f7900, 0x64616900, 0x73706164, 0x65000000, 0x64616967, 0x6f726f68, 0x00000000, 0x70726973,
    0x69610000, 0x6c696c79, 0x00000000, 0x706a0000, 0x71717100, 0x73686572, 0x6c6f636b, 0x00000000,
    0x676f6d61, 0x00000000, 0x73616e00, 0x67656e00, 0x696e7465, 0x72766965, 0x77657200, (u32)lbl_1_data_20BC8__fzgx_offset_0,
    (u32)lbl_1_data_20BD0__fzgx_offset_0, (u32)lbl_1_data_20BD8__fzgx_offset_0, (u32)lbl_1_data_20BE0__fzgx_offset_0, (u32)lbl_1_data_20BE8__fzgx_offset_0, (u32)lbl_1_data_20BF0__fzgx_offset_0, (u32)lbl_1_data_20BF8__fzgx_offset_0, (u32)lbl_1_data_20C00__fzgx_offset_0, (u32)lbl_1_data_20C08__fzgx_offset_0,
    (u32)lbl_1_data_20C0C__fzgx_offset_0, (u32)lbl_1_data_20C14__fzgx_offset_0, (u32)lbl_1_data_20C1C__fzgx_offset_0, (u32)lbl_1_data_20C24__fzgx_offset_0, (u32)lbl_1_data_20C2C__fzgx_offset_0, (u32)lbl_1_data_20C34__fzgx_offset_0, (u32)lbl_1_data_20C38__fzgx_offset_0, (u32)lbl_1_data_20C40__fzgx_offset_0,
    (u32)lbl_1_data_20C48__fzgx_offset_0, (u32)lbl_1_data_20C54__fzgx_offset_0, (u32)lbl_1_data_20C5C__fzgx_offset_0, (u32)lbl_1_data_20C64__fzgx_offset_0, (u32)lbl_1_data_20C68__fzgx_offset_0, (u32)lbl_1_data_20C70__fzgx_offset_0, (u32)lbl_1_data_20C78__fzgx_offset_0, (u32)lbl_1_data_20C80__fzgx_offset_0,
    (u32)lbl_1_data_20C88__fzgx_offset_0, (u32)lbl_1_data_20C90__fzgx_offset_0, (u32)lbl_1_data_20C98__fzgx_offset_0, (u32)lbl_1_data_20CA0__fzgx_offset_0, (u32)lbl_1_data_20CA8__fzgx_offset_0, (u32)lbl_1_data_20CB0__fzgx_offset_0, (u32)lbl_1_data_20CB8__fzgx_offset_0, (u32)lbl_1_data_20CBC__fzgx_offset_0,
    (u32)lbl_1_data_20CC4__fzgx_offset_0, (u32)lbl_1_data_20CC8__fzgx_offset_0, (u32)lbl_1_data_20CD0__fzgx_offset_0, (u32)lbl_1_data_20CDC__fzgx_offset_0, (u32)lbl_1_data_20CE4__fzgx_offset_0, (u32)lbl_1_data_20CEC__fzgx_offset_0, (u32)lbl_1_data_20CF0__fzgx_offset_0, (u32)lbl_1_data_20CF4__fzgx_offset_0,
    (u32)lbl_1_data_20D00__fzgx_offset_0, (u32)lbl_1_data_20D08__fzgx_offset_0, (u32)lbl_1_data_20D0C__fzgx_offset_0, (u32)lbl_1_data_20D10__fzgx_offset_0, 0x837d8343, 0x83658342, 0x815b2083, 0x4b835b83, /* fzgx-allow: A1 measured retail string bytes, not addresses */
    0x8b000000, 0x83578387, 0x83668342, 0x20835483, 0x7d815b00, 0x8368834e, 0x835e815b, 0x20835883,
    0x60838583, 0x8f815b83, 0x67000000, 0x836f836f, 0x00000000, 0x83548380, 0x83898343, 0x20835383,
    0x8d815b00, 0x83738352, 0x00000000, 0x834c8383, 0x83768365, 0x83932083, 0x74834083, 0x8b835283,
    0x93000000, 0x8349834e, 0x8367837d, 0x83930000, 0x837e8358, 0x835e815b, 0x20834381, 0x5b814583,
    0x47834381, 0x45836683, 0x42000000, 0x83578346, 0x815b8380, 0x83592083, 0x7d834e83, 0x89834583, /* fzgx-allow: A1 measured retail string bytes, not addresses */
    0x68000000, 0x8372838a, 0x815b0000, 0x83508343, 0x83672083, 0x41838c83, 0x93000000, 0x835d815b, /* fzgx-allow: A1 measured retail string bytes, not addresses */
    0x835f0000, 0x83578383, 0x8362834e, 0x20838c83, 0x72839300, 0x836f8343, 0x83492083, 0x8c836283,
    0x4e835800, 0x83552083, 0x58834a83, 0x8b000000, 0x83418393, 0x8367836a, 0x83492083, 0x4b835883,
    0x5e815b00, 0x8372815b, 0x83588367, 0x837d8393, 0x00000000, 0x838c8349, 0x83930000, 0x8358815b,
    0x8370815b, 0x20834183, 0x8d815b00, 0x837e835a, 0x83582083, 0x41838d81, 0x5b000000, 0x8353837d,
    0x815b8195, 0x83568349, 0x815b0000, 0x8356838b, 0x836f815b, 0x20836a81, 0x5b838b83, 0x5a839300, /* fzgx-allow: A1 measured retail string bytes, not addresses */
    0x837d8343, 0x8350838b, 0x20836083, 0x46815b83, 0x93000000, 0x83758389, 0x83628368, 0x20837483,
    0x40838b83, 0x52839300, 0x83578387, 0x83932083, 0x5e836983, 0x4a000000, 0x83688389, 0x834e0000,
    0x838d8357, 0x8383815b, 0x20836f83, 0x58835e81, 0x5b000000, 0x8368834e, 0x835e815b, 0x20834e83,
    0x89836283, 0x56838500, 0x83758389, 0x8362834e, 0x20835683, 0x83836881, 0x5b000000, 0x83668358,
    0x837b815b, 0x83930000, 0x83688393, 0x20835781, 0x5b836a81, 0x5b000000, 0x83668357, 0x20837b81,
    0x5b834300, 0x835f8343, 0x81458354, 0x83938145, 0x83518393, 0x00000000, 0x83588379, 0x815b8368, /* fzgx-allow: A1 measured retail string bytes, not addresses */
    0x00000000, 0x835f8343, 0x8353838d, 0x815b0000, 0x8376838a, 0x83938356, 0x83410000, 0x838a838a, /* fzgx-allow: A1 measured retail string bytes, not addresses */
    0x815b0000, 0x8373815b, 0x83578346, 0x83430000, 0x834c8385, 0x815b8358, 0x838a815b, 0x00000000, /* fzgx-allow: A1 measured retail string bytes, not addresses */
    0x83748346, 0x836a8362, 0x834e8358, 0x00000000, 0x8353837d, 0x815b0000, 0x83548393, 0x00000000, /* fzgx-allow: A1 measured retail string bytes, not addresses */
    0x83518393, 0x00000000, 0x83438393, 0x835e8372, 0x8385838f, 0x815b0000, (u32)lbl_1_data_20DD0__fzgx_offset_0, (u32)lbl_1_data_20DE4__fzgx_offset_0, /* fzgx-allow: A1 measured retail string bytes, not addresses */
    (u32)lbl_1_data_20DF4__fzgx_offset_0, (u32)lbl_1_data_20E0C__fzgx_offset_0, (u32)lbl_1_data_20E14__fzgx_offset_0, (u32)lbl_1_data_20E24__fzgx_offset_0, (u32)lbl_1_data_20E2C__fzgx_offset_0, (u32)lbl_1_data_20E44__fzgx_offset_0, (u32)lbl_1_data_20E50__fzgx_offset_0, (u32)lbl_1_data_20E6C__fzgx_offset_0,
    (u32)lbl_1_data_20E84__fzgx_offset_0, (u32)lbl_1_data_20E8C__fzgx_offset_0, (u32)lbl_1_data_20E9C__fzgx_offset_0, (u32)lbl_1_data_20EA4__fzgx_offset_0, (u32)lbl_1_data_20EB4__fzgx_offset_0, (u32)lbl_1_data_20EC4__fzgx_offset_0, (u32)lbl_1_data_20ED0__fzgx_offset_0, (u32)lbl_1_data_20EE4__fzgx_offset_0,
    (u32)lbl_1_data_20EF4__fzgx_offset_0, (u32)lbl_1_data_20EFC__fzgx_offset_0, (u32)lbl_1_data_20F0C__fzgx_offset_0, (u32)lbl_1_data_20F1C__fzgx_offset_0, (u32)lbl_1_data_20F2C__fzgx_offset_0, (u32)lbl_1_data_20F40__fzgx_offset_0, (u32)lbl_1_data_20F54__fzgx_offset_0, (u32)lbl_1_data_20F68__fzgx_offset_0,
    (u32)lbl_1_data_20F78__fzgx_offset_0, (u32)lbl_1_data_20F80__fzgx_offset_0, (u32)lbl_1_data_20F94__fzgx_offset_0, (u32)lbl_1_data_20FA8__fzgx_offset_0, (u32)lbl_1_data_20FBC__fzgx_offset_0, (u32)lbl_1_data_20FC8__fzgx_offset_0, (u32)lbl_1_data_20FD8__fzgx_offset_0, (u32)lbl_1_data_20FE4__fzgx_offset_0,
    (u32)lbl_1_data_20FF8__fzgx_offset_0, (u32)lbl_1_data_21004__fzgx_offset_0, (u32)lbl_1_data_21010__fzgx_offset_0, (u32)lbl_1_data_2101C__fzgx_offset_0, (u32)lbl_1_data_21024__fzgx_offset_0, (u32)lbl_1_data_21030__fzgx_offset_0, (u32)lbl_1_data_21040__fzgx_offset_0, (u32)lbl_1_data_21050__fzgx_offset_0,
    (u32)lbl_1_data_21058__fzgx_offset_0, (u32)lbl_1_data_21060__fzgx_offset_0, (u32)lbl_1_data_21068__fzgx_offset_0, 0x4d494748, 0x54592047, 0x415a454c, 0x4c450000, 0x4a4f4459,
    0x2053554d, 0x4d455200, 0x44722e20, 0x53544557, 0x41525400, 0x53414d55, 0x52414920, 0x474f524f,
    0x48000000, 0x43415054, 0x41494e20, 0x46414c43, 0x4f4e0000, 0x4f43544f, 0x4d414e00, 0x4d722e20,
    0x45414400, 0x4a414d45, 0x53204d63, 0x434c4f55, 0x44000000, 0x4b415445, 0x20414c45, 0x4e000000,
    0x4a41434b, 0x204c4556, 0x494e0000, 0x42494f20, 0x52455800, 0x54484520, 0x534b554c, 0x4c000000,
    0x414e544f, 0x4e494f20, 0x47555354, 0x45520000, 0x53555045, 0x52204152, 0x524f5700, 0x4d72732e,
    0x20415252, 0x4f570000, 0x474f4d41, 0x52202620, 0x5348494f, 0x48000000, 0x53494c56, 0x4552204e,
    0x45454c53, 0x454e0000, 0x4d494348, 0x41454c20, 0x43484149, 0x4e000000, 0x424c4f4f, 0x44204641,
    0x4c434f4e, 0x00000000, 0x4a4f484e, 0x2054414e, 0x414b4100, 0x524f4745, 0x52204255, 0x53544552,
    0x00000000, 0x44722e20, 0x434c4153, 0x48000000, 0x424c4143, 0x4b205348, 0x41444f57, 0x00000000,
    0x44454154, 0x48424f52, 0x4e000000, 0x444f4e20, 0x47454e49, 0x45000000, 0x44494749, 0x2d424f59,
    0x00000000, 0x44414920, 0x53414e20, 0x47454e00, 0x5052494e, 0x43494100, 0x50484f45, 0x4e495800,
    0x474f4d41, 0x52000000, (u32)lbl_1_data_2112C__fzgx_offset_0, (u32)lbl_1_data_2113C__fzgx_offset_0, (u32)lbl_1_data_21148__fzgx_offset_0, (u32)lbl_1_data_209D8__fzgx_offset_0, (u32)lbl_1_data_21154__fzgx_offset_0, (u32)lbl_1_data_209E8__fzgx_offset_0,
    (u32)lbl_1_data_21164__fzgx_offset_0, (u32)lbl_1_data_21174__fzgx_offset_0, (u32)lbl_1_data_2117C__fzgx_offset_0, (u32)lbl_1_data_21184__fzgx_offset_0, (u32)lbl_1_data_20A0C__fzgx_offset_0, (u32)lbl_1_data_21194__fzgx_offset_0, (u32)lbl_1_data_20A1C__fzgx_offset_0, (u32)lbl_1_data_211A0__fzgx_offset_0,
    (u32)lbl_1_data_211AC__fzgx_offset_0, (u32)lbl_1_data_211B4__fzgx_offset_0, (u32)lbl_1_data_211C0__fzgx_offset_0, (u32)lbl_1_data_20A40__fzgx_offset_0, (u32)lbl_1_data_20A4C__fzgx_offset_0, (u32)lbl_1_data_211D0__fzgx_offset_0, (u32)lbl_1_data_211DC__fzgx_offset_0, (u32)lbl_1_data_211E8__fzgx_offset_0,
    (u32)lbl_1_data_211F8__fzgx_offset_0, (u32)lbl_1_data_21208__fzgx_offset_0, (u32)lbl_1_data_21218__fzgx_offset_0, (u32)lbl_1_data_21228__fzgx_offset_0, (u32)lbl_1_data_20A88__fzgx_offset_0, (u32)lbl_1_data_21234__fzgx_offset_0, (u32)lbl_1_data_21244__fzgx_offset_0, (u32)lbl_1_data_21250__fzgx_offset_0,
    (u32)lbl_1_data_21260__fzgx_offset_0, (u32)lbl_1_data_2126C__fzgx_offset_0, (u32)lbl_1_data_21278__fzgx_offset_0, (u32)lbl_1_data_21284__fzgx_offset_0, (u32)lbl_1_data_20AC0__fzgx_offset_0, (u32)lbl_1_data_20AC8__fzgx_offset_0, (u32)lbl_1_data_21290__fzgx_offset_0, (u32)lbl_1_data_20ADC__fzgx_offset_0,
    (u32)lbl_1_data_20AE4__fzgx_offset_0, (u32)lbl_1_data_20AE8__fzgx_offset_0, (u32)lbl_1_data_21298__fzgx_offset_0, (u32)lbl_1_data_212A0__fzgx_offset_0, (u32)lbl_1_data_20B00__fzgx_offset_0, (u32)lbl_1_data_20B04__fzgx_offset_0, (u32)lbl_1_data_20B08__fzgx_offset_0, 0x01050607,
    0x080b0c0d, 0x1017181a, 0x1b121315, 0x16000000, 0x01050607, 0x080b0c0d, 0x1017181a, 0x1b121315,
    0x16000000, 0x00010708, 0x09030405, 0x0a101112, 0x0c0d0e1d, 0x1e1f2021, 0x22232427, 0x282b2c00,
    0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c, 0x0205080b, 0x0e0f1113, 0x14161b1e, 0x22232425,
    0x292a2b2c, 0x1017181a, 0x12131501, 0x0507080a, 0x0c0d0f00, 0x1017181a, 0x12131501, 0x0507080a,
    0x0c0d0f00, 0x10010507, 0x080c0d00, 0x01030506, 0x07080b0c, 0x0d101718, 0x1a1b1213, 0x15160000,
    0x01030506, 0x07080b0c, 0x0d101718, 0x1a1b1213, 0x15160000, 0x00010304, 0x05070809, 0x0a0c0d0e,
    0x1011121d, 0x1e1f2021, 0x22232426, 0x2728292a, 0x2b2c2d00, 0x000e0f10, 0x01020304, 0x05060708,
    0x090a0b0c, 0x1017181a, 0x12131501, 0x0507080a, 0x0c0d0f00, 0x1017181a, 0x12131501, 0x0507080a,
    0x0c0d0f00, 0x10010507, 0x080c0d00, 0x01050607, 0x080b0c0d, 0x1017181a, 0x1b121315, 0x16000000,
    0x01050607, 0x080b0c0d, 0x1017181a, 0x1b121315, 0x16000000, 0x00010304, 0x05070809, 0x0a101112,
    0x0c0d0e1d, 0x1e1f2021, 0x22232426, 0x2728292a, 0x2b2c2d00, 0x000e0f10, 0x01020304, 0x05060708,
    0x090a0b0c, 0x1017181a, 0x12131501, 0x0507080a, 0x0c0d0f00, 0x1017181a, 0x12131501, 0x0507080a,
    0x0c0d0f00, 0x10010507, 0x080c0d00, 0x01050607, 0x080b0c0d, 0x1017181a, 0x1b121315, 0x16000000,
    0x01050607, 0x080b0c0d, 0x1017181a, 0x1b121315, 0x16000000, 0x00010708, 0x09030405, 0x0a0c0d0e,
    0x1011121d, 0x1e1f2021, 0x22232426, 0x2728292a, 0x2b2c2d19, 0x1a1b1516, 0x17000000, 0x000e0f10,
    0x01020304, 0x05060708, 0x090a0b0c, 0x01050708, 0x0a0c0d0f, 0x1017181a, 0x12131500, 0x1017181a,
    0x12131501, 0x0507080a, 0x0c0d0f00, 0x10010507, 0x080c0d00, 0x01050607, 0x080b0c0d, 0x10121315,
    0x1617181a, 0x1b000000, 0x01050607, 0x080b0c0d, 0x10121315, 0x1617181a, 0x1b000000, 0x00010304,
    0x05070809, 0x0a101112, 0x0c0d0e2b, 0x2c272822, 0x23241e1f, 0x20000000, 0x000e0f10, 0x01020304,
    0x05060708, 0x090a0b0c, 0x01030507, 0x080a0c0d, 0x0f101213, 0x1517181a, 0x10121315, 0x17181a01,
    0x03050708, 0x0a0c0d0f, 0x01030507, 0x080c0d10, 0x010b0c0d, 0x06070805, 0x10121315, 0x1617181a,
    0x1b000000, 0x010b0c0d, 0x06070805, 0x10121315, 0x1617181a, 0x1b000000, 0x001e1f20, 0x2223242c,
    0x2813191a, 0x1b151617, 0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c, 0x10121315, 0x17181a01,
    0x0c0d0f07, 0x080a0305, 0x10121315, 0x17181a01, 0x0c0d0f07, 0x080a0305, 0x10010c0d, 0x07080305,
    0x010b0c0d, 0x05060708, 0x1d1e2025, 0x26212223, 0x2428292b, 0x2e2f2c2d, 0x30311012, 0x13151617,
    0x181a1b00, 0x010b0c0d, 0x05060708, 0x1d1e2025, 0x26212223, 0x2428292b, 0x2e2f2c2d, 0x30311012,
    0x13151617, 0x181a1b00, 0x00010304, 0x05070809, 0x0a0c0d0e, 0x10111219, 0x1a1b1516, 0x17000000,
    0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c, 0x10121315, 0x17181a01, 0x0c0d0f05, 0x07080a1d,
    0x1e282900, 0x10121315, 0x17181a01, 0x0c0d0f05, 0x07080a1d, 0x1e282900, 0x10010c0d, 0x05070800,
    0x0103050b, 0x0c0d0607, 0x08101213, 0x15161718, 0x1a1b0000, 0x0103050b, 0x0c0d0607, 0x08101213,
    0x15161718, 0x1a1b0000, 0x00010304, 0x05070809, 0x1011120c, 0x0d0e1319, 0x1a1b1516, 0x172b2c2d,
    0x27282922, 0x23241e1f, 0x20000000, 0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c, 0x10121315,
    0x17181a01, 0x03050c0d, 0x07080000, 0x000f1001, 0x02030405, 0x06070809, 0x0a0b0c00, 0x0103050c,
    0x0d0f0708, 0x0a101213, 0x1517181a, 0x01050c0d, 0x07081012, 0x17000000, 0x01050b0c, 0x0d060708,
    0x10121315, 0x1617181a, 0x1b000000, 0x01050b0c, 0x0d060708, 0x10121315, 0x1617181a, 0x1b000000,
    0x00010708, 0x09030405, 0x0a0c0d0e, 0x10111219, 0x1a1b1516, 0x171d1e1f, 0x20212223, 0x24262728,
    0x292a2b2c, 0x2d2f3000, 0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c, 0x01000000, 0x10121315,
    0x1617181a, 0x1b01050c, 0x0d0f0708, 0x0a000000, 0x10121315, 0x1617181a, 0x1b01050c, 0x0d0e0708,
    0x09000000, 0x10121701, 0x050c0d07, 0x08000000, 0x01060708, 0x0b0c0d03, 0x05101213, 0x15161d1e,
    0x2017181a, 0x1b000000, 0x01060708, 0x0b0c0d03, 0x05101213, 0x15161d1e, 0x2017181a, 0x1b000000,
    0x00010304, 0x05070809, 0x0a101112, 0x0c0d0e15, 0x1617191a, 0x1b000000, 0x000e0f10, 0x01020304,
    0x05060708, 0x090a0b0c, 0x0107080a, 0x0c0d0f05, 0x10121315, 0x1d1e1f17, 0x181a0000, 0x0107080a,
    0x0c0d0f05, 0x10121315, 0x1d1e1f17, 0x181a0000, 0x0107080c, 0x0d051000, 0x01060708, 0x0b0c0d10,
    0x12131516, 0x17181a1b, 0x01060708, 0x0b0c0d10, 0x12131516, 0x17181a1b, 0x00010304, 0x05070809,
    0x0a0c0d0e, 0x1011121d, 0x1e1f2021, 0x2223242a, 0x2b2c2d26, 0x27282919, 0x1a1b1516, 0x17000000,
    0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c, 0x01000000, 0x01050708, 0x0a0c0d0f, 0x10121315,
    0x17181a00, 0x01050708, 0x0a0c0d0f, 0x10121315, 0x17181a00, 0x01050708, 0x0c0d1000, 0x01050708,
    0x0c0d1017, 0x181a1b12, 0x1315161d, 0x20210000, 0x01050708, 0x0c0d1017, 0x181a1b12, 0x1315161d,
    0x20210000, 0x00010304, 0x05070809, 0x0c0d0e10, 0x11121d1e, 0x1f202122, 0x23242728, 0x292b2c2d,
    0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c, 0x1017181a, 0x1213151d, 0x20010305, 0x07080a0c,
    0x0d0f0000, 0x1017181a, 0x1213151d, 0x20010305, 0x07080a0c, 0x0d0f0000, 0x10010507, 0x080a0c0d,
    0x01050607, 0x080b0c0d, 0x1017181a, 0x1b121315, 0x16000000, 0x01050607, 0x080b0c0d, 0x1017181a,
    0x1b121315, 0x16000000, 0x00010708, 0x09030405, 0x0a0c0d0e, 0x10111215, 0x1617191a, 0x1b1e1f20,
    0x22232400, 0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c, 0x1017181a, 0x12131501, 0x03050708,
    0x0a0c0d0f, 0x1017181a, 0x12131501, 0x0507080a, 0x0c0d0f00, 0x10010507, 0x080c0d00, 0x01050607,
    0x080b0c0d, 0x10121315, 0x1617181a, 0x1b000000, 0x01050607, 0x080b0c0d, 0x10121315, 0x1617181a,
    0x1b000000, 0x00010304, 0x05070809, 0x0a101112, 0x0c0d0e2b, 0x2c2d2728, 0x29222324, 0x1e1f2000,
    0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c, 0x10121315, 0x17181a01, 0x03050708, 0x0a0c0d0f,
    0x10121315, 0x17181a01, 0x03050708, 0x0a0c0d0f, 0x10010507, 0x080c0d00, 0x01060708, 0x0b0c0d10,
    0x17181a1b, 0x12131516, 0x01060708, 0x0b0c0d10, 0x17181a1b, 0x12131516, 0x002f3000, 0x000e0f10,
    0x01020304, 0x05060708, 0x090a0b0c, 0x1017181a, 0x12131501, 0x0507080a, 0x0c0d0f00, 0x1017181a,
    0x12131501, 0x0507080a, 0x0c0d0f00, 0x10010507, 0x080c0d00, 0x0103050b, 0x0c0d0607, 0x08101213,
    0x15161718, 0x1a1b0000, 0x0103050b, 0x0c0d0607, 0x08101213, 0x15161718, 0x1a1b0000, 0x00010304,
    0x05070809, 0x1011120c, 0x0d0e1319, 0x1a1b1516, 0x172b2c2d, 0x27282922, 0x23241e1f, 0x20000000,
    0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c, 0x10121315, 0x17181a01, 0x03050c0d, 0x07080000,
    0x000f1001, 0x02030405, 0x06070809, 0x0a0b0c00, 0x0103050c, 0x0d0f0708, 0x0a101213, 0x1517181a,
    0x01050c0d, 0x07081012, 0x17000000, 0x01050b0c, 0x0d060708, 0x1017181a, 0x1b121315, 0x16000000,
    0x01050b0c, 0x0d060708, 0x1017181a, 0x1b121315, 0x16000000, 0x00101112, 0x0c0d0e01, 0x03040507,
    0x08092b2c, 0x2d272829, 0x2223241e, 0x1f200000, 0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c,
    0x0103050c, 0x0d070810, 0x17181a12, 0x13150000, 0x000f1001, 0x02030405, 0x06070809, 0x0a0b0c00,
    0x0103050c, 0x0d0f0708, 0x0a101718, 0x1a121315, 0x01050c0d, 0x07081000, 0x01030507, 0x080a0c0d,
    0x1017181a, 0x1b121315, 0x16000000, 0x01030507, 0x080a0c0d, 0x1017181a, 0x1b121315, 0x16000000,
    0x00010708, 0x09030405, 0x0a0f1011, 0x120b0c0d, 0x0e13191a, 0x1b151617, 0x2f300000, 0x000e0f10,
    0x01020304, 0x05060708, 0x090a0b0c, 0x1017181a, 0x12131501, 0x0507080a, 0x0c0d0f00, 0x1017181a,
    0x12131501, 0x0507080a, 0x0c0d0f00, 0x10010507, 0x080c0d00, 0x010b0c0d, 0x06070803, 0x05101213,
    0x15161718, 0x1a1b0000, 0x010b0c0d, 0x06070803, 0x05101213, 0x15161718, 0x1a1b0000, 0x00010304,
    0x05070809, 0x0a0c0d0e, 0x10111213, 0x15161719, 0x1a1b0000, 0x000d0e0f, 0x10010203, 0x04050607,
    0x08090a0b, 0x0c000000, 0x10121315, 0x17181a01, 0x0c0d0f07, 0x080a0305, 0x10121315, 0x17181a01,
    0x0c0d0f07, 0x080a0305, 0x10010c0d, 0x07080500, 0x01050607, 0x080b0c0d, 0x1017181a, 0x1b121315,
    0x16000000, 0x01050607, 0x080b0c0d, 0x1017181a, 0x1b121315, 0x16000000, 0x00010304, 0x05070809,
    0x0a101112, 0x0c0d0e19, 0x1a1b1516, 0x17000000, 0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c,
    0x1017181a, 0x12131501, 0x0507080a, 0x0c0d0f00, 0x1017181a, 0x12131501, 0x0507080a, 0x0c0d0f00,
    0x10010507, 0x080c0d00, 0x01030506, 0x07080b0c, 0x0d101213, 0x15161718, 0x1a1b0000, 0x00010708,
    0x09030405, 0x0a0f1011, 0x120b0c0d, 0x0e000000, 0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c,
    0x1017181a, 0x12131501, 0x0507080a, 0x0c0d0f00, 0x1017181a, 0x12131501, 0x0507080a, 0x0c0d0f00,
    0x10010507, 0x080c0d00, 0x01050b0c, 0x0d060708, 0x10121315, 0x1617181a, 0x1b000000, 0x01050b0c,
    0x0d060708, 0x10121315, 0x1617181a, 0x1b000000, 0x00010708, 0x09030405, 0x0a0c0d0e, 0x10111219,
    0x1a1b1516, 0x172f3022, 0x23241e1f, 0x202b2c2d, 0x27282900, 0x000e0f10, 0x01020304, 0x05060708,
    0x090a0b0c, 0x10121315, 0x17181a01, 0x03050c0d, 0x0f07080a, 0x10121315, 0x17181a01, 0x03050c0d,
    0x0f07080a, 0x10010305, 0x0c0d0708, 0x01050607, 0x080b0c0d, 0x10121315, 0x1617181a, 0x1b000000,
    0x01050607, 0x080b0c0d, 0x10121315, 0x1617181a, 0x1b000000, 0x00010708, 0x09030405, 0x0a101112,
    0x0c0d0e15, 0x1617191a, 0x1b000000, 0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c, 0x10121315,
    0x17181a01, 0x03050708, 0x0a0c0d0f, 0x10121315, 0x17181a01, 0x03050708, 0x0a0c0d0f, 0x10010507,
    0x080c0d00, 0x01050b0c, 0x0d060708, 0x10121315, 0x1617181a, 0x1b000000, 0x01050b0c, 0x0d060708,
    0x10121315, 0x1617181a, 0x1b000000, 0x00010708, 0x09030405, 0x0a0c0d0e, 0x10111219, 0x1a1b1516,
    0x171e1f20, 0x22232427, 0x28292b2c, 0x2d302f00, 0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c,
    0x10121315, 0x17181a01, 0x050c0d0f, 0x07080a00, 0x10121315, 0x17181a01, 0x050c0d0f, 0x07080a00,
    0x1001050c, 0x0d070800, 0x01050607, 0x080b0c0d, 0x1017181a, 0x1b121315, 0x16000000, 0x01050607,
    0x080b0c0d, 0x1017181a, 0x1b121315, 0x16000000, 0x00010708, 0x09030405, 0x0a0c0d0e, 0x10111213,
    0x15161719, 0x1a1b2f30, 0x1e1f2022, 0x23242728, 0x292b2c2d, 0x000e0f10, 0x01020304, 0x05060708,
    0x090a0b0c, 0x1017181a, 0x12131501, 0x0507080a, 0x0c0d0f00, 0x1017181a, 0x12131501, 0x0507080a,
    0x0c0d0f00, 0x10010507, 0x080c0d00, 0x01050607, 0x080b0c0d, 0x1017181a, 0x1b121315, 0x161d2023,
    0x24000000, 0x01050607, 0x080b0c0d, 0x1017181a, 0x1b121315, 0x161d2023, 0x24000000, 0x00010809,
    0x0304050a, 0x0c0d0e10, 0x11122f30, 0x2223241e, 0x1f202b2c, 0x2d272800, 0x000e0f10, 0x01020304,
    0x05060708, 0x090a0b0c, 0x1017181a, 0x1d202324, 0x12131501, 0x0507080a, 0x0c0d0f00, 0x1017181a,
    0x1d202324, 0x12131501, 0x0507080a, 0x0c0d0f00, 0x10010507, 0x080c0d00, 0x01060708, 0x0b0c0d03,
    0x05101213, 0x15161718, 0x1a1b0000, 0x01060708, 0x0b0c0d03, 0x05101213, 0x15161718, 0x1a1b0000,
    0x00010708, 0x09030405, 0x2f302b2c, 0x2d272829, 0x15161719, 0x1a1b0a0f, 0x1011120b, 0x0c0d0e21,
    0x2223241d, 0x1e1f2000, 0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c, 0x10121315, 0x17181a01,
    0x07080a0c, 0x0d0f0500, 0x10121315, 0x17181a01, 0x07080a0c, 0x0d0f0500, 0x10010708, 0x0c0d0500,
    0x01050607, 0x080b0c0d, 0x1017181a, 0x1b121315, 0x16000000, 0x01050607, 0x080b0c0d, 0x1017181a,
    0x1b121315, 0x16000000, 0x00010708, 0x09030405, 0x0a0c0d0e, 0x10111215, 0x1617191a, 0x1b000000,
    0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c, 0x1017181a, 0x12131501, 0x0507080a, 0x0c0d0f00,
    0x1017181a, 0x12131501, 0x0507080a, 0x0c0d0f00, 0x01050708, 0x0c0d1000, 0x01050607, 0x080b0c0d,
    0x1017181a, 0x1b121315, 0x16000000, 0x01050607, 0x080b0c0d, 0x1017181a, 0x1b121315, 0x16000000,
    0x00010708, 0x09030405, 0x0a0c0d0e, 0x10111215, 0x1617191a, 0x1b2f301e, 0x1f202223, 0x24272829,
    0x2b2c2d00, 0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c, 0x1017181a, 0x12131501, 0x0507080a,
    0x0c0d0f00, 0x1017181a, 0x12131501, 0x0507080a, 0x0c0d0f00, 0x10010507, 0x080c0d00, 0x01050607,
    0x080b0c0d, 0x10121315, 0x1617181a, 0x1b000000, 0x01050607, 0x080b0c0d, 0x10121315, 0x1617181a,
    0x1b000000, 0x00010708, 0x09030405, 0x0a101112, 0x0c0d0e13, 0x191a1b15, 0x16172122, 0x23241d1e,
    0x1f200000, 0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c, 0x01000000, 0x10121315, 0x17181a01,
    0x0507080a, 0x0c0d0f00, 0x10121315, 0x17181a01, 0x0507080a, 0x0c0d0f00, 0x10010507, 0x080c0d00,
    0x1017181a, 0x1b121315, 0x162b2e2f, 0x26292a01, 0x0c0d0f07, 0x080a1c1f, 0x20212425, 0x1017181a,
    0x1b121315, 0x162b2e2f, 0x26292a01, 0x0c0d0f07, 0x080a1c1f, 0x20212425, 0x00030405, 0x0708090c,
    0x0d0e1011, 0x121e1f20, 0x2223242b, 0x2c2d2728, 0x29000000, 0x010c0d0f, 0x07080a05, 0x1c1f2021,
    0x24251017, 0x181a1213, 0x152b2e2f, 0x26292a00, 0x010c0d0f, 0x07080a05, 0x1c1f2021, 0x24251017,
    0x181a1213, 0x152b2e2f, 0x26292a00, 0x010c0d07, 0x08051000, 0x010b0c0d, 0x06070803, 0x05101213,
    0x15161718, 0x1a1b0000, 0x010b0c0d, 0x06070803, 0x05101213, 0x15161718, 0x1a1b0000, 0x00010a00,
    0x000d0e0f, 0x10010203, 0x04050607, 0x08090a0b, 0x0c000000, 0x10121315, 0x17181a01, 0x0c0d0f07,
    0x080a0500, 0x10121315, 0x17181a01, 0x0c0d0f07, 0x080a0500, 0x10121701, 0x0c0d0708, 0x05000000,
    0x01060708, 0x0b0c0d05, 0x10121315, 0x1617181a, 0x1b000000, 0x01000000, 0x01060708, 0x0b0c0d05,
    0x10121315, 0x1617181a, 0x1b000000, 0x00010a00, 0x000e0f10, 0x0405060a, 0x0b0c0000, 0x0107080a,
    0x0c0d0f05, 0x10121315, 0x17181a00, 0x0107080a, 0x0c0d0f05, 0x10121315, 0x17181a00, 0x0107080c,
    0x0d051000, 0x01050b0c, 0x0d060708, 0x10121315, 0x1617181a, 0x1b000000, 0x01050b0c, 0x0d060708,
    0x10121315, 0x1617181a, 0x1b000000, 0x00010304, 0x05070809, 0x0a101112, 0x0c0d0e15, 0x1617191a,
    0x1b222324, 0x1d1e1f20, 0x2a2b2c2d, 0x26272829, 0x302f0000, 0x000e0f10, 0x01020304, 0x05060708,
    0x090a0b0c, 0x01050c0d, 0x0f07080a, 0x10121315, 0x17181a00, 0x01050c0d, 0x0f07080a, 0x10121315,
    0x17181a00, 0x1001050c, 0x0d070800, 0x01030708, 0x0c0d1017, 0x181a1b12, 0x13151600, 0x01030708,
    0x0c0d1017, 0x181a1b12, 0x13151600, 0x0001120e, 0x2e000000, 0x000e0a00, 0x1017181a, 0x12131501,
    0x0507080a, 0x0c0d0f00, 0x1017181a, 0x12131501, 0x0507080a, 0x0c0d0f00, 0x10171201, 0x05070809,
    0x0c0d0e00, 0x01050607, 0x080b0c0d, 0x1017181a, 0x1b121315, 0x161d2023, 0x26000000, 0x01050607,
    0x080b0c0d, 0x1017181a, 0x1b121315, 0x161d2023, 0x26000000, 0x00010a0c, 0x0d0e1011, 0x12000000,
    0x000e0f04, 0x050a0b0c, 0x1017181a, 0x1213151d, 0x20232601, 0x0507080a, 0x0c0d0f00, 0x1017181a,
    0x1213151d, 0x20232601, 0x0507080a, 0x0c0d0f00, 0x101d2023, 0x01050708, 0x0c0d0000, 0x01050607,
    0x080b0c0d, 0x1017181a, 0x1b121315, 0x16000000, 0x01050607, 0x080b0c0d, 0x1017181a, 0x1b121315,
    0x16000000, 0x00010708, 0x09030405, 0x0a101112, 0x0c0d0e2f, 0x301d1e1f, 0x20212223, 0x24262728,
    0x292a2b2c, 0x2d191a1b, 0x15161700, 0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c, 0x01050708,
    0x0a0c0d0f, 0x1017181a, 0x12131500, 0x1017181a, 0x12131501, 0x0507080a, 0x0c0d0f00, 0x10010507,
    0x080c0d00, 0x0103050b, 0x0c0d0607, 0x08101213, 0x15161718, 0x1a1b0000, 0x0103050b, 0x0c0d0607,
    0x08101213, 0x15161718, 0x1a1b0000, 0x00010304, 0x05070809, 0x1011120c, 0x0d0e1319, 0x1a1b1516,
    0x172b2c2d, 0x27282922, 0x23241e1f, 0x20000000, 0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c,
    0x10121315, 0x17181a01, 0x03050c0d, 0x07080000, 0x000f1001, 0x02030405, 0x06070809, 0x0a0b0c00,
    0x0103050c, 0x0d0f0708, 0x0a101213, 0x1517181a, 0x01050c0d, 0x07081012, 0x17000000, 0x010b0c0d,
    0x06070805, 0x1017181a, 0x1b121315, 0x16000000, 0x010b0c0d, 0x06070805, 0x1017181a, 0x1b121315,
    0x16000000, 0x00010708, 0x09030405, 0x0a101112, 0x0c0d0e22, 0x23241e1f, 0x20272829, 0x2b2c2d00,
    0x000d0e0f, 0x10010203, 0x04050607, 0x08090a0b, 0x0c000000, 0x1017181a, 0x12131501, 0x0c0d0f07,
    0x080a0500, 0x010c0d0f, 0x07080a05, 0x1017181a, 0x12131500, 0x010c0d07, 0x08051000, 0x01050607,
    0x080b0c0d, 0x1017181a, 0x1b121315, 0x16000000, 0x01050607, 0x080b0c0d, 0x1017181a, 0x1b121315,
    0x16000000, 0x00010708, 0x09030405, 0x0a0c0d0e, 0x10111226, 0x2728292a, 0x2b2c2d1d, 0x1e1f2021,
    0x22232400, 0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c, 0x1017181a, 0x12131501, 0x0507080a,
    0x0c0d0f00, 0x1017181a, 0x12131501, 0x0507080a, 0x0c0d0f00, 0x10010507, 0x080c0d00, 0x01060708,
    0x050b0c0d, 0x1017181a, 0x1b121315, 0x16000000, 0x01060708, 0x050b0c0d, 0x1017181a, 0x1b121315,
    0x16000000, 0x000f1011, 0x120b0c0d, 0x0e010304, 0x05070809, 0x2223241e, 0x1f202b2c, 0x2d272829,
    0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c, 0x01070803, 0x050c0d10, 0x17181a12, 0x13150000,
    0x000f1001, 0x02030405, 0x06070809, 0x0a0b0c00, 0x0107080a, 0x03050c0d, 0x0f101718, 0x1a121315,
    0x01070803, 0x050c0d10, 0x010b0c0d, 0x03050607, 0x08101213, 0x15161718, 0x1a1b0000, 0x01000000,
    0x010b0c0d, 0x03050607, 0x08101213, 0x15161718, 0x1a1b0000, 0x00191a1b, 0x15161727, 0x28292b2c,
    0x2d1e1f20, 0x2223242e, 0x302f0000, 0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c, 0x10121315,
    0x17181a01, 0x0c0d0f03, 0x0507080a, 0x10121315, 0x17181a01, 0x0c0d0f03, 0x0507080a, 0x10010c0d,
    0x05070800, 0x010b0c0d, 0x06070803, 0x05101213, 0x15161718, 0x1a1b0000, 0x010b0c0d, 0x06070803,
    0x05101213, 0x15161718, 0x1a1b0000, 0x00010304, 0x05070809, 0x0a0c0d0e, 0x10111214, 0x15161718,
    0x191a1b21, 0x2223241d, 0x1e1f2000, 0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c, 0x10121315,
    0x17181a01, 0x0c0d0f07, 0x080a0500, 0x10121315, 0x17181a01, 0x0c0d0f07, 0x080a0500, 0x10010c0d,
    0x07080500, 0x01050607, 0x080b0c0d, 0x1017181a, 0x1b121315, 0x16000000, 0x01050607, 0x080b0c0d,
    0x1017181a, 0x1b121315, 0x16000000, 0x00010708, 0x09030405, 0x0a101112, 0x0c0d0e13, 0x191a1b15,
    0x16171d1e, 0x1f202122, 0x23240000, 0x000e0f10, 0x01020304, 0x05060708, 0x090a0b0c, 0x020b0c06,
    0x07000000, 0x1017181a, 0x12131501, 0x03050708, 0x0a0c0d0f, 0x1017181a, 0x12131501, 0x03050708,
    0x0a0c0d0f, 0x10010507, 0x080c0d00, 0x010b0c0d, 0x06070805, 0x1017181a, 0x1b121315, 0x16000000,
    0x010b0c0d, 0x06070805, 0x1017181a, 0x1b121315, 0x16000000, 0x00010708, 0x09030405, 0x0a101112,
    0x0c0d0e13, 0x191a1b15, 0x16172b2c, 0x2d272829, 0x2223241e, 0x1f20302f, 0x000e0f10, 0x01020304,
    0x05060708, 0x090a0b0c, 0x1017181a, 0x12131501, 0x0c0d0f07, 0x080a0305, 0x1017181a, 0x12131501,
    0x0c0d0f07, 0x080a0305, 0x10010c0d, 0x07080500, 0x01000000, 0x0c000000, 0x07000000, 0x424f4459,
    0x00000000, 0x46414345, 0x00000000, 0x48414e44, 0x4c000000, 0x48414e44, 0x52000000, 0x4b415441,
    0x41544500, 0x5f424f41, 0x52440000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21A3C__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21A64__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21A80__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0,
    (u32)lbl_1_data_21A80__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_22A3C__fzgx_offset_0, (u32)lbl_1_data_22A14__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_215F0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21618__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21628__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21628__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0,
    (u32)lbl_1_data_21CB4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005,
    (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21CDC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21CF4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21CF4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_22334__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_2235C__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22360__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0,
    (u32)lbl_1_data_22360__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_22884__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_228AC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_228CC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_228CC__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x4b415441, 0x4154455f, 0x52000000,
    0x4b415441, 0x4154455f, 0x4c000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21F04__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21F2C__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21F50__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0,
    (u32)lbl_1_data_21F50__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_22DF4__fzgx_offset_0, (u32)lbl_1_data_22A14__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_22E00__fzgx_offset_0, (u32)lbl_1_data_22A18__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21E08__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21E30__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21E54__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21E54__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0,
    (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_222A0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_222D8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21660__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_216A8__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_216C0__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_216C0__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0,
    (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2193C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21964__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21980__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21980__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x5f535449, 0x434b0000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0,
    (u32)lbl_1_data_2221C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005,
    (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_22244__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22264__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22264__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_23190__fzgx_offset_0, (u32)lbl_1_data_22274__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2255C__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_22584__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0,
    (u32)lbl_1_data_225AC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000f,
    (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_225AC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2146C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21494__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_214B4__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_214B4__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22DF4__fzgx_offset_0, (u32)lbl_1_data_22A14__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22E00__fzgx_offset_0,
    (u32)lbl_1_data_22A18__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x5f4d454b, 0x41000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_22904__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_2292C__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_2294C__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_2294C__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_23420__fzgx_offset_0,
    (u32)lbl_1_data_2295C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_213EC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21414__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21434__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21434__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22DF4__fzgx_offset_0, (u32)lbl_1_data_22A14__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22E00__fzgx_offset_0, (u32)lbl_1_data_22A18__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0,
    (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21F88__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21FB0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21FD4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21FD4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x5f4f574c, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0,
    (u32)lbl_1_data_2135C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005,
    (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21384__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_213A0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_213A0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_236B0__fzgx_offset_0, (u32)lbl_1_data_213B0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2200C__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_2203C__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0,
    (u32)lbl_1_data_22058__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000f,
    (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22058__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21C38__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21C60__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21C7C__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21C7C__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0,
    (u32)lbl_1_data_22120__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005,
    (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_22148__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22160__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22160__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21D30__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21D58__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21D70__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0,
    (u32)lbl_1_data_21D70__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21E8C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21EB4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21ECC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21ECC__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21574__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0,
    (u32)lbl_1_data_2159C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000a,
    (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_215B8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_215B8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2267C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_226A4__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_226C0__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_226C0__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0,
    (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_22198__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_221C0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_221E4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_221E4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21BAC__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21BD4__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0,
    (u32)lbl_1_data_21BF0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000f,
    (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21BF0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2277C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_227A4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_227C0__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_227C0__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0,
    (u32)lbl_1_data_219C0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005,
    (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_219E8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21A04__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21A04__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_2298C__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_229B4__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_229D8__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0,
    (u32)lbl_1_data_229D8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_214EC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21514__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_2153C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_2153C__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21AB8__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0,
    (u32)lbl_1_data_21AD8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000a,
    (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21ADC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21ADC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_224E4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_22514__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22520__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22520__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0,
    (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_22404__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_2242C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22454__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22454__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22DF4__fzgx_offset_0, (u32)lbl_1_data_22A14__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22E00__fzgx_offset_0, (u32)lbl_1_data_22A18__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x5f4b4154, 0x414e4100,
    0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21798__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_217C0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_217E8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_217E8__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24318__fzgx_offset_0, (u32)lbl_1_data_217F8__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0,
    (u32)lbl_1_data_2248C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005,
    (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_224AC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_224B4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_224B4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21830__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21860__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21878__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0,
    (u32)lbl_1_data_21878__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_218B8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_218D8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21900__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21900__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_23190__fzgx_offset_0, (u32)lbl_1_data_21910__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x5f4f5000, 0x00000000,
    (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_223A0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_223CC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_223D0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_223D0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24638__fzgx_offset_0, (u32)lbl_1_data_223B4__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21700__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0,
    (u32)lbl_1_data_21728__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000a,
    (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_2174C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_2174C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_225E4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_2260C__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22630__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22630__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0,
    (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21B14__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21B3C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21B60__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21B60__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_22098__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_220C0__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0,
    (u32)lbl_1_data_220E8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000f,
    (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_220E8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x5f434152, 0x445f4a4f, 0x4b455230, 0x31000000, 0x5f434152, 0x445f4a4f, 0x4b455230,
    0x32000000, 0x5f434152, 0x445f4a4f, 0x4b455230, 0x33000000, 0x5f434152, 0x445f4a4f, 0x4b455230,
    0x34000000, 0x5f434152, 0x445f4143, 0x45303100, 0x5f434152, 0x445f4143, 0x45303200, 0x5f434152,
    0x445f4143, 0x45303300, 0x5f434152, 0x445f4143, 0x45303400, 0x5f42414c, 0x4c303100, 0x5f42414c,
    0x4c303200, 0x5f42414c, 0x4c303300, 0x5f42414c, 0x4c303400, 0x5f42414c, 0x4c303500, 0x5f42414c,
    0x4c303600, 0x5f42414c, 0x4c303700, 0x5f42414c, 0x4c303800, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_22808__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0,
    (u32)lbl_1_data_22834__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000a,
    (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_2284C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_2284C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_249E4__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_249F4__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A04__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A14__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A24__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A30__fzgx_offset_0,
    (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_24A3C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_24A48__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_24A54__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A5C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A64__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A6C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A74__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A7C__fzgx_offset_0,
    (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_24A84__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_24A8C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_226FC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_22724__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22744__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22744__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0,
    (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_22A1C__fzgx_offset_0, (u32)lbl_1_data_21DA8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000005, (u32)lbl_1_data_22A24__fzgx_offset_0, (u32)lbl_1_data_21DBC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21DD0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21DD0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_22A44__fzgx_offset_0, (u32)lbl_1_data_22A10__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x635f6861, 0x72610000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0,
    (u32)lbl_1_data_21A90__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21638__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21D08__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22374__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_228DC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21F60__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_222F4__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_216D0__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0,
    (u32)lbl_1_data_21990__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21E64__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22278__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_23190__fzgx_offset_0, (u32)lbl_1_data_22274__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_225BC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_214C4__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22964__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_23420__fzgx_offset_0, (u32)lbl_1_data_2295C__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0,
    (u32)lbl_1_data_21444__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21FE4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22068__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_213C4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_236B0__fzgx_offset_0, (u32)lbl_1_data_213B0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21C8C__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22170__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21D80__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0,
    (u32)lbl_1_data_21EDC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_215C8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_226D4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_221F4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21C00__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21C10__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_21C10__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_227D0__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0,
    (u32)lbl_1_data_227E0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000f,
    (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_227E0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21A14__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_229E8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21AEC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2154C__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22528__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22464__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0,
    (u32)lbl_1_data_217FC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_24318__fzgx_offset_0, (u32)lbl_1_data_217F8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_224B8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21888__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21914__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_23190__fzgx_offset_0, (u32)lbl_1_data_21910__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_223DC__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24638__fzgx_offset_0, (u32)lbl_1_data_223B4__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0,
    (u32)lbl_1_data_2175C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000a,
    (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_2176C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_2176C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22640__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_22650__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0, (u32)lbl_1_data_22650__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21B70__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000a, (u32)lbl_1_data_22A2C__fzgx_offset_0, (u32)lbl_1_data_21B80__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000f, (u32)lbl_1_data_22A34__fzgx_offset_0,
    (u32)lbl_1_data_21B80__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_220F8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2285C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_249E4__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_249F4__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A04__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A14__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A24__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A30__fzgx_offset_0,
    (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_24A3C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_24A48__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_24A54__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A5C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A64__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A6C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A74__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24A7C__fzgx_offset_0,
    (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_24A84__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_24A8C__fzgx_offset_0, (u32)lbl_1_data_2281C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22754__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21DE0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21AA0__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21648__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21D18__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0,
    (u32)lbl_1_data_22384__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_228EC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21F70__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22310__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_216E4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_219A4__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21E74__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22288__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0,
    (u32)lbl_1_data_225CC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_214D4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22974__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21454__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21FF4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2207C__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_213D4__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21C9C__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0,
    (u32)lbl_1_data_22180__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21D90__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21EEC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_215D8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_226E4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22204__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21C20__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_227F0__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0,
    (u32)lbl_1_data_21A24__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_229F8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21AFC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2155C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2253C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22474__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21810__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_224C8__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0,
    (u32)lbl_1_data_2189C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21924__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_223EC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2177C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22660__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21B90__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22108__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2286C__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0,
    (u32)lbl_1_data_22764__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21DF0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21AB0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21658__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21D28__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22394__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_228FC__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21F80__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0,
    (u32)lbl_1_data_2232C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_216F8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_219B8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21E84__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22298__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_225DC__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_214E4__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22984__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0,
    (u32)lbl_1_data_21464__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22004__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22090__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_213E4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21CAC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22190__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21DA0__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21EFC__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0,
    (u32)lbl_1_data_215E8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_226F4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22214__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21C30__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22800__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21A34__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22A08__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21B0C__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0,
    (u32)lbl_1_data_2156C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22550__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22484__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21824__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_224D8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_218B0__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21934__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_223FC__fzgx_offset_0,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0,
    (u32)lbl_1_data_2178C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22670__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21BA0__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22118__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_2287C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_22774__fzgx_offset_0, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_1_data_24EF0__fzgx_offset_0, (u32)lbl_1_data_21E00__fzgx_offset_0, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xf4000000, 0xfc000000, 0xf4000000,
    0xf4000000, 0xf4000000, 0xf4000000, 0xf4000000, 0xb4000000, 0xf4000000, 0xf4000000, 0xf4000000,
    0xfc000000, 0xf4000000, 0xfc000000, 0xf4000000, 0xf4000000, 0xf4000000, 0xf4000000, 0xfc000000,
    0xf4000000, 0xfc000000, 0xf4000000, 0xf4000000, 0xf4000000, 0xf4000000, 0xf4000000, 0xf4000000,
    0xfc000000, 0xf4000000, 0xf4000000, 0xf4000000, 0xf4000000, 0xf4000000, 0xf4000000, 0xf4000000,
    0xfc000000, 0xfc000000, 0xfc000000, 0xf4000000, 0xf4000000, 0xf4000000, 0xf4000000, 0xf4000000,
    0xf4000000, 0xf0000000, (u32)lbl_1_data_240B4__fzgx_offset_0, (u32)lbl_1_data_22E0C__fzgx_offset_0, (u32)lbl_1_data_22D40__fzgx_offset_0, (u32)lbl_1_data_23500__fzgx_offset_0, (u32)lbl_1_data_22BD8__fzgx_offset_0, (u32)lbl_1_data_22C8C__fzgx_offset_0,
    (u32)lbl_1_data_22A4C__fzgx_offset_0, (u32)lbl_1_data_22FBC__fzgx_offset_0, (u32)lbl_1_data_23E98__fzgx_offset_0, (u32)lbl_1_data_23A60__fzgx_offset_0, (u32)lbl_1_data_24000__fzgx_offset_0, (u32)lbl_1_data_235FC__fzgx_offset_0, (u32)lbl_1_data_23F4C__fzgx_offset_0, (u32)lbl_1_data_22F08__fzgx_offset_0,
    (u32)lbl_1_data_24168__fzgx_offset_0, (u32)lbl_1_data_23844__fzgx_offset_0, (u32)lbl_1_data_239AC__fzgx_offset_0, (u32)lbl_1_data_23324__fzgx_offset_0, (u32)lbl_1_data_23790__fzgx_offset_0, (u32)lbl_1_data_236B8__fzgx_offset_0, (u32)lbl_1_data_23C7C__fzgx_offset_0, (u32)lbl_1_data_23DE4__fzgx_offset_0,
    (u32)lbl_1_data_23198__fzgx_offset_0, (u32)lbl_1_data_238F8__fzgx_offset_0, (u32)lbl_1_data_23B14__fzgx_offset_0, (u32)lbl_1_data_23428__fzgx_offset_0, (u32)lbl_1_data_230DC__fzgx_offset_0, (u32)lbl_1_data_23270__fzgx_offset_0, (u32)lbl_1_data_23028__fzgx_offset_0, (u32)lbl_1_data_23BC8__fzgx_offset_0,
    (u32)lbl_1_data_22B24__fzgx_offset_0, (u32)lbl_1_data_24560__fzgx_offset_0, (u32)lbl_1_data_244AC__fzgx_offset_0, (u32)lbl_1_data_24714__fzgx_offset_0, (u32)lbl_1_data_24A94__fzgx_offset_0, (u32)lbl_1_data_24320__fzgx_offset_0, (u32)lbl_1_data_2421C__fzgx_offset_0, (u32)lbl_1_data_24930__fzgx_offset_0,
    (u32)lbl_1_data_2463C__fzgx_offset_0, (u32)lbl_1_data_243F8__fzgx_offset_0, (u32)lbl_1_data_24D88__fzgx_offset_0, (u32)lbl_1_data_23D30__fzgx_offset_0, (u32)lbl_1_data_247C8__fzgx_offset_0, (u32)lbl_1_data_2487C__fzgx_offset_0, (u32)lbl_1_data_24E3C__fzgx_offset_0, 0x00000005,
    0x00000007, 0x00000005, 0x00000007, 0x00000005, 0x00000005, 0x00000006, 0x00000003, 0x00000005,
    0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000005,
    0x00000007, 0x00000005, 0x00000006, 0x00000005, 0x00000005, 0x00000006, 0x00000005, 0x00000005,
    0x00000006, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000006, 0x00000005,
    0x00000005, 0x00000015, 0x00000006, 0x00000007, 0x00000005, 0x00000006, 0x00000005, 0x00000005,
    0x00000005, 0x00000005, 0x00000005, 0x00000005, (u32)lbl_1_data_25408__fzgx_offset_0, (u32)lbl_1_data_24FAC__fzgx_offset_0, (u32)lbl_1_data_24F88__fzgx_offset_0, (u32)lbl_1_data_25138__fzgx_offset_0,
    (u32)lbl_1_data_24F40__fzgx_offset_0, (u32)lbl_1_data_24F64__fzgx_offset_0, (u32)lbl_1_data_24EF8__fzgx_offset_0, (u32)lbl_1_data_24FD0__fzgx_offset_0, (u32)lbl_1_data_253C0__fzgx_offset_0, (u32)lbl_1_data_25258__fzgx_offset_0, (u32)lbl_1_data_2542C__fzgx_offset_0, (u32)lbl_1_data_2515C__fzgx_offset_0,
    (u32)lbl_1_data_253E4__fzgx_offset_0, (u32)lbl_1_data_2503C__fzgx_offset_0, (u32)lbl_1_data_25450__fzgx_offset_0, (u32)lbl_1_data_251EC__fzgx_offset_0, (u32)lbl_1_data_25234__fzgx_offset_0, (u32)lbl_1_data_250CC__fzgx_offset_0, (u32)lbl_1_data_25180__fzgx_offset_0, (u32)lbl_1_data_251A4__fzgx_offset_0,
    (u32)lbl_1_data_252C4__fzgx_offset_0, (u32)lbl_1_data_25354__fzgx_offset_0, (u32)lbl_1_data_25060__fzgx_offset_0, (u32)lbl_1_data_25210__fzgx_offset_0, (u32)lbl_1_data_2527C__fzgx_offset_0, (u32)lbl_1_data_250F0__fzgx_offset_0, (u32)lbl_1_data_25018__fzgx_offset_0, (u32)lbl_1_data_250A8__fzgx_offset_0,
    (u32)lbl_1_data_24FF4__fzgx_offset_0, (u32)lbl_1_data_252A0__fzgx_offset_0, (u32)lbl_1_data_24F1C__fzgx_offset_0, (u32)lbl_1_data_25528__fzgx_offset_0, (u32)lbl_1_data_25504__fzgx_offset_0, (u32)lbl_1_data_255B8__fzgx_offset_0, (u32)lbl_1_data_25720__fzgx_offset_0, (u32)lbl_1_data_25498__fzgx_offset_0,
    (u32)lbl_1_data_25474__fzgx_offset_0, (u32)lbl_1_data_256FC__fzgx_offset_0, (u32)lbl_1_data_25570__fzgx_offset_0, (u32)lbl_1_data_254E0__fzgx_offset_0, (u32)lbl_1_data_25984__fzgx_offset_0, (u32)lbl_1_data_252E8__fzgx_offset_0, (u32)lbl_1_data_25624__fzgx_offset_0, (u32)lbl_1_data_25690__fzgx_offset_0,
    (u32)lbl_1_data_259A8__fzgx_offset_0, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001,
    0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001,
    0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000002, 0x00000001, 0x00000003, 0x00000002,
    0x00000001, 0x00000001, 0x00000002, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001,
    0x00000002, 0x00000001, 0x00000003, 0x00000011, 0x00000002, 0x00000001, 0x00000001, 0x00000002,
    0x00000001, 0x00000001, 0x00000003, 0x00000003, 0x00000003, 0x00000001, (u32)lbl_1_data_25DE0__fzgx_offset_0, (u32)lbl_1_data_25A80__fzgx_offset_0,
    (u32)lbl_1_data_25A5C__fzgx_offset_0, (u32)lbl_1_data_25BC4__fzgx_offset_0, (u32)lbl_1_data_25A14__fzgx_offset_0, (u32)lbl_1_data_25A38__fzgx_offset_0, (u32)lbl_1_data_259CC__fzgx_offset_0, (u32)lbl_1_data_25AA4__fzgx_offset_0, (u32)lbl_1_data_25D98__fzgx_offset_0, (u32)lbl_1_data_25CC0__fzgx_offset_0,
    (u32)lbl_1_data_25E04__fzgx_offset_0, (u32)lbl_1_data_25BE8__fzgx_offset_0, (u32)lbl_1_data_25DBC__fzgx_offset_0, (u32)lbl_1_data_25B10__fzgx_offset_0, (u32)lbl_1_data_25E28__fzgx_offset_0, (u32)lbl_1_data_25C54__fzgx_offset_0, (u32)lbl_1_data_25C9C__fzgx_offset_0, (u32)lbl_1_data_25B7C__fzgx_offset_0,
    (u32)lbl_1_data_25C0C__fzgx_offset_0, (u32)lbl_1_data_25C30__fzgx_offset_0, (u32)lbl_1_data_25D2C__fzgx_offset_0, (u32)lbl_1_data_25D74__fzgx_offset_0, (u32)lbl_1_data_25B34__fzgx_offset_0, (u32)lbl_1_data_25C78__fzgx_offset_0, (u32)lbl_1_data_25CE4__fzgx_offset_0, (u32)lbl_1_data_25BA0__fzgx_offset_0,
    (u32)lbl_1_data_25AEC__fzgx_offset_0, (u32)lbl_1_data_25B58__fzgx_offset_0, (u32)lbl_1_data_25AC8__fzgx_offset_0, (u32)lbl_1_data_25D08__fzgx_offset_0, (u32)lbl_1_data_259F0__fzgx_offset_0, (u32)lbl_1_data_25EDC__fzgx_offset_0, (u32)lbl_1_data_25EB8__fzgx_offset_0, (u32)lbl_1_data_25F24__fzgx_offset_0,
    (u32)lbl_1_data_25FB4__fzgx_offset_0, (u32)lbl_1_data_25E70__fzgx_offset_0, (u32)lbl_1_data_25E4C__fzgx_offset_0, (u32)lbl_1_data_25F90__fzgx_offset_0, (u32)lbl_1_data_25F00__fzgx_offset_0, (u32)lbl_1_data_25E94__fzgx_offset_0, (u32)lbl_1_data_25FD8__fzgx_offset_0, (u32)lbl_1_data_25D50__fzgx_offset_0,
    (u32)lbl_1_data_25F48__fzgx_offset_0, (u32)lbl_1_data_25F6C__fzgx_offset_0, (u32)lbl_1_data_25FFC__fzgx_offset_0, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001,
    0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001,
    0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001,
    0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001,
    0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001,
    0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001,
    (u32)lbl_1_data_26434__fzgx_offset_0, (u32)lbl_1_data_260D4__fzgx_offset_0, (u32)lbl_1_data_260B0__fzgx_offset_0, (u32)lbl_1_data_26218__fzgx_offset_0, (u32)lbl_1_data_26068__fzgx_offset_0, (u32)lbl_1_data_2608C__fzgx_offset_0, (u32)lbl_1_data_26020__fzgx_offset_0, (u32)lbl_1_data_260F8__fzgx_offset_0,
    (u32)lbl_1_data_263EC__fzgx_offset_0, (u32)lbl_1_data_26314__fzgx_offset_0, (u32)lbl_1_data_26458__fzgx_offset_0, (u32)lbl_1_data_2623C__fzgx_offset_0, (u32)lbl_1_data_26410__fzgx_offset_0, (u32)lbl_1_data_26164__fzgx_offset_0, (u32)lbl_1_data_2647C__fzgx_offset_0, (u32)lbl_1_data_262A8__fzgx_offset_0,
    (u32)lbl_1_data_262F0__fzgx_offset_0, (u32)lbl_1_data_261D0__fzgx_offset_0, (u32)lbl_1_data_26260__fzgx_offset_0, (u32)lbl_1_data_26284__fzgx_offset_0, (u32)lbl_1_data_26380__fzgx_offset_0, (u32)lbl_1_data_263C8__fzgx_offset_0, (u32)lbl_1_data_26188__fzgx_offset_0, (u32)lbl_1_data_262CC__fzgx_offset_0,
    (u32)lbl_1_data_26338__fzgx_offset_0, (u32)lbl_1_data_261F4__fzgx_offset_0, (u32)lbl_1_data_26140__fzgx_offset_0, (u32)lbl_1_data_261AC__fzgx_offset_0, (u32)lbl_1_data_2611C__fzgx_offset_0, (u32)lbl_1_data_2635C__fzgx_offset_0, (u32)lbl_1_data_26044__fzgx_offset_0, (u32)lbl_1_data_26530__fzgx_offset_0,
    (u32)lbl_1_data_2650C__fzgx_offset_0, (u32)lbl_1_data_26578__fzgx_offset_0, (u32)lbl_1_data_26608__fzgx_offset_0, (u32)lbl_1_data_264C4__fzgx_offset_0, (u32)lbl_1_data_264A0__fzgx_offset_0, (u32)lbl_1_data_265E4__fzgx_offset_0, (u32)lbl_1_data_26554__fzgx_offset_0, (u32)lbl_1_data_264E8__fzgx_offset_0,
    (u32)lbl_1_data_2662C__fzgx_offset_0, (u32)lbl_1_data_263A4__fzgx_offset_0, (u32)lbl_1_data_2659C__fzgx_offset_0, (u32)lbl_1_data_265C0__fzgx_offset_0, (u32)lbl_1_data_26650__fzgx_offset_0, 0x00000001, 0x00000001, 0x00000001,
    0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001,
    0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001,
    0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001,
    0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001,
    0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001,
    0x00000001, 0x00000001, 0x18000000, 0x00000000, 0x18000000, 0x00010000, 0x18000000, 0x00020000,
    0x18000000, 0x00030000, 0x18000000, 0x00040000, 0x18000000, 0x00050000, 0x18000000, 0x00060000,
    0x18000000, 0x00070000, 0x18000000, 0x00080000, 0x18000000, 0x00090000, 0x18000000, 0x000a0000,
    0x18000000, 0x000b0000, 0x18000000, 0x000c0000, 0x18000000, 0x000d0000, 0x18000000, 0x000e0000,
    0x18000000, 0x000f0000, 0x18000000, 0x00100000, 0x00000000, 0x5f313030, 0x30000000, 0x5f353030,
    0x00000000, 0x5f313030, 0x00000000, 0x5f333030, 0x30000000, 0x5f637631, 0x00000000, 0x5f637632,
    0x00000000, 0x5f637633, 0x00000000, 0x4c49505f, 0x41000000, 0x4c49505f, 0x49000000, 0x4c49505f,
    0x55000000, 0x4c49505f, 0x45000000, 0x4c49505f, 0x4f000000, 0x46414345, 0x5f444546, 0x00000000,
    (u32)lbl_1_data_26D8C__fzgx_offset_0, (u32)lbl_1_data_26D94__fzgx_offset_0, (u32)lbl_1_data_26D9C__fzgx_offset_0, (u32)lbl_1_data_26DA4__fzgx_offset_0, (u32)lbl_1_data_26DAC__fzgx_offset_0, (u32)lbl_1_data_26DB4__fzgx_offset_0, 0x42480000, 0x696e745f,
    0x30320000, 0x696e745f, 0x30330000, 0x696e745f, 0x30340000, 0x696e745f, 0x30345f66, 0x65617200,
    0x696e745f, 0x30355f66, 0x65617200, 0x696e745f, 0x31340000, 0x696e745f, 0x31350000, 0x696e745f,
    0x31360000, 0x696e745f, 0x31380000, 0x696e745f, 0x32300000, 0x696e745f, 0x32310000, 0x696e745f,
    0x32330000, 0x696e745f, 0x32340000, 0x696e745f, 0x32370000, 0x696e745f, 0x32380000, 0x696e745f,
    0x33310000, 0x696e745f, 0x33330000, 0x696e745f, 0x33340000, 0x696e745f, 0x33350000, 0x696e745f,
    0x33360000, 0x696e745f, 0x33370000, 0x696e745f, 0x35300000, 0x696e745f, 0x35310000, 0x696e745f,
    0x35320000, 0x696e745f, 0x636f6d5f, 0x31000000, 0x696e745f, 0x636f6d5f, 0x32000000, 0x696e745f,
    0x636f6d5f, 0x33000000, 0x696e745f, 0x636f6d5f, 0x34000000, 0x696e745f, 0x636f6d5f, 0x35000000,
    0x696e745f, 0x636f6d5f, 0x36000000, 0x696e745f, 0x636f6d5f, 0x37000000, 0x696e745f, 0x636f6d5f,
    0x38000000, 0x696e745f, 0x636f6d5f, 0x39000000, 0x696e745f, 0x636f6d5f, 0x31300000, 0x696e745f,
    0x636f6d32, 0x5f310000, 0x696e745f, 0x636f6d32, 0x5f320000, 0x696e745f, 0x636f6d32, 0x5f330000,
    0x696e745f, 0x636f6d32, 0x5f340000, 0x696e745f, 0x636f6d32, 0x5f350000, 0x696e745f, 0x636f6d32,
    0x5f360000, 0x696e745f, 0x636f6d32, 0x5f370000, 0x696e745f, 0x636f6d32, 0x5f380000, 0x696e745f,
    0x636f6d32, 0x5f390000, 0x696e745f, 0x636f6d32, 0x5f313000, (u32)lbl_1_data_26DDC__fzgx_offset_0, (u32)lbl_1_data_26DE4__fzgx_offset_0, (u32)lbl_1_data_26DEC__fzgx_offset_0,
    (u32)lbl_1_data_26DF4__fzgx_offset_0, (u32)lbl_1_data_26E00__fzgx_offset_0, (u32)lbl_1_data_26E0C__fzgx_offset_0, (u32)lbl_1_data_26E14__fzgx_offset_0, (u32)lbl_1_data_26E1C__fzgx_offset_0, (u32)lbl_1_data_26E24__fzgx_offset_0, (u32)lbl_1_data_26E2C__fzgx_offset_0, (u32)lbl_1_data_26E34__fzgx_offset_0,
    (u32)lbl_1_data_26E3C__fzgx_offset_0, (u32)lbl_1_data_26E44__fzgx_offset_0, (u32)lbl_1_data_26E4C__fzgx_offset_0, (u32)lbl_1_data_26E54__fzgx_offset_0, (u32)lbl_1_data_26E5C__fzgx_offset_0, (u32)lbl_1_data_26E5C__fzgx_offset_0, (u32)lbl_1_data_26E64__fzgx_offset_0, (u32)lbl_1_data_26E6C__fzgx_offset_0,
    (u32)lbl_1_data_26E74__fzgx_offset_0, (u32)lbl_1_data_26E7C__fzgx_offset_0, (u32)lbl_1_data_26E84__fzgx_offset_0, (u32)lbl_1_data_26E8C__fzgx_offset_0, (u32)lbl_1_data_26E94__fzgx_offset_0, (u32)lbl_1_data_26E9C__fzgx_offset_0, (u32)lbl_1_data_26EA4__fzgx_offset_0, (u32)lbl_1_data_26EB0__fzgx_offset_0,
    (u32)lbl_1_data_26EBC__fzgx_offset_0, (u32)lbl_1_data_26EC8__fzgx_offset_0, (u32)lbl_1_data_26ED4__fzgx_offset_0, (u32)lbl_1_data_26EE0__fzgx_offset_0, (u32)lbl_1_data_26EEC__fzgx_offset_0, (u32)lbl_1_data_26EF8__fzgx_offset_0, (u32)lbl_1_data_26F04__fzgx_offset_0, (u32)lbl_1_data_26F10__fzgx_offset_0,
    (u32)lbl_1_data_26F1C__fzgx_offset_0, (u32)lbl_1_data_26F28__fzgx_offset_0, (u32)lbl_1_data_26F34__fzgx_offset_0, (u32)lbl_1_data_26F40__fzgx_offset_0, (u32)lbl_1_data_26F4C__fzgx_offset_0, (u32)lbl_1_data_26F58__fzgx_offset_0, (u32)lbl_1_data_26F64__fzgx_offset_0, (u32)lbl_1_data_26F70__fzgx_offset_0,
    (u32)lbl_1_data_26F7C__fzgx_offset_0, (u32)lbl_1_data_26F88__fzgx_offset_0, 0x67617a65, 0x6c6c655f, 0x626f6172, 0x64000000, 0x424f4152, 0x44000000,
    0x6a6f6479, 0x5f626f61, 0x72640000, 0x73746577, 0x6172745f, 0x626f6172, 0x64000000, 0x62616261,
    0x5f626f61, 0x72640000, 0x676f726f, 0x685f626f, 0x61726400, 0x7069636f, 0x5f626f61, 0x72640000,
    0x66616c63, 0x6f6e5f62, 0x6f617264, 0x00000000, 0x6f63746d, 0x616e5f62, 0x6f617264, 0x00000000,
    0x6561645f, 0x626f6172, 0x64000000, 0x6a616d65, 0x735f626f, 0x61726400, 0x62696c6c, 0x795f626f,
    0x61726400, 0x6b617465, 0x5f626f61, 0x72640000, 0x7a6f6461, 0x5f626f61, 0x72640000, 0x6a61636b,
    0x5f626f61, 0x72640000, 0x7265785f, 0x626f6172, 0x64000000, 0x676f7264, 0x6f6e5f62, 0x6f617264,
    0x00000000, 0x67757374, 0x65725f62, 0x6f617264, 0x00000000, 0x62656173, 0x746d616e, 0x5f626f61,
    0x72640000, 0x6c656f6e, 0x5f626f61, 0x72640000, 0x6172726f, 0x775f626f, 0x61726400, 0x6d72735f,
    0x626f6172, 0x64000000, 0x7368696f, 0x5f626f61, 0x72640000, 0x6e65656c, 0x73656e5f, 0x626f6172,
    0x64000000, 0x6d696368, 0x61656c5f, 0x626f6172, 0x64000000, 0x626c6f6f, 0x645f626f, 0x61726400,
    0x74616e61, 0x6b615f62, 0x6f617264, 0x00000000, 0x64726171, 0x5f626f61, 0x72640000, 0x726f6765,
    0x725f626f, 0x61726400, 0x636c6173, 0x685f626f, 0x61726400, 0x73686164, 0x6f775f62, 0x6f617264,
    0x00000000, 0x626f7373, 0x5f626f61, 0x72640000, 0x646f6e5f, 0x626f6172, 0x64000000, 0x64696769,
    0x626f795f, 0x626f6172, 0x64000000, 0x6461695f, 0x626f6172, 0x64000000, 0x73706164, 0x655f626f,
    0x61726400, 0x64616967, 0x6f726f68, 0x5f626f61, 0x72640000, 0x70726973, 0x69615f62, 0x6f617264,
    0x00000000, 0x6c696c79, 0x5f626f61, 0x72640000, 0x706a5f62, 0x6f617264, 0x00000000, 0x7171715f,
    0x626f6172, 0x64000000, 0x73686572, 0x6c6f636b, 0x5f626f61, 0x72640000, 0x676f6d61, 0x5f626f61,
    0x72640000, 0x73616e5f, 0x626f6172, 0x64000000, 0x67656e5f, 0x626f6172, 0x64000000, 0x74616e61,
    0x6b615f6d, 0x656b6100, 0x4d454b41, 0x00000000, 0x6172726f, 0x775f6f77, 0x6c000000, 0x4f574c00,
    0x6e65656c, 0x73656e5f, 0x73746963, 0x6b000000, 0x54554500, 0x64616967, 0x6f726f68, 0x5f6b6174,
    0x616e6100, 0x4b415441, 0x4e410000, 0x646f6e5f, 0x73746963, 0x6b000000, 0x706a5f6f, 0x70000000,
    0x4f500000, 0x73706164, 0x655f6361, 0x72645f61, 0x63653031, 0x00000000, 0x43415244, 0x5f414345,
    0x30310000, 0x73706164, 0x655f6361, 0x72645f61, 0x63653032, 0x00000000, 0x43415244, 0x5f414345,
    0x30320000, 0x73706164, 0x655f6361, 0x72645f61, 0x63653033, 0x00000000, 0x43415244, 0x5f414345,
    0x30330000, 0x73706164, 0x655f6361, 0x72645f61, 0x63653034, 0x00000000, 0x43415244, 0x5f414345,
    0x30340000, 0x73706164, 0x655f6361, 0x72645f6a, 0x6f6b6572, 0x30310000, 0x43415244, 0x5f4a4f4b,
    0x45523031, 0x00000000, 0x73706164, 0x655f6361, 0x72645f6a, 0x6f6b6572, 0x30320000, 0x43415244,
    0x5f4a4f4b, 0x45523032, 0x00000000, 0x73706164, 0x655f6361, 0x72645f6a, 0x6f6b6572, 0x30330000,
    0x43415244, 0x5f4a4f4b, 0x45523033, 0x00000000, 0x73706164, 0x655f6361, 0x72645f6a, 0x6f6b6572,
    0x30340000, 0x43415244, 0x5f4a4f4b, 0x45523034, 0x00000000, 0x73706164, 0x655f6261, 0x6c6c3031,
    0x00000000, 0x42414c4c, 0x30310000, 0x73706164, 0x655f6261, 0x6c6c3032, 0x00000000, 0x42414c4c,
    0x30320000, 0x73706164, 0x655f6261, 0x6c6c3033, 0x00000000, 0x42414c4c, 0x30330000, 0x73706164,
    0x655f6261, 0x6c6c3034, 0x00000000, 0x42414c4c, 0x30340000, 0x73706164, 0x655f6261, 0x6c6c3035,
    0x00000000, 0x42414c4c, 0x30350000, 0x73706164, 0x655f6261, 0x6c6c3036, 0x00000000, 0x42414c4c,
    0x30360000, 0x73706164, 0x655f6261, 0x6c6c3037, 0x00000000, 0x42414c4c, 0x30370000, 0x73706164,
    0x655f6261, 0x6c6c3038, 0x00000000, 0x42414c4c, 0x30380000, 0x00000000, (u32)lbl_1_data_27048__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0,
    0x00010000, (u32)lbl_1_data_27060__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00020000, (u32)lbl_1_data_2706C__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00030000, (u32)lbl_1_data_2707C__fzgx_offset_0,
    (u32)lbl_1_data_27058__fzgx_offset_0, 0x00040000, (u32)lbl_1_data_27088__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00050000, (u32)lbl_1_data_27094__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00060000,
    (u32)lbl_1_data_270A0__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00070000, (u32)lbl_1_data_270B0__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00080000, (u32)lbl_1_data_270C0__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0,
    0x00090000, (u32)lbl_1_data_270CC__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x000a0000, (u32)lbl_1_data_270D8__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x000b0000, (u32)lbl_1_data_270E4__fzgx_offset_0,
    (u32)lbl_1_data_27058__fzgx_offset_0, 0x000c0000, (u32)lbl_1_data_270F0__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x000d0000, (u32)lbl_1_data_270FC__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x000e0000,
    (u32)lbl_1_data_27108__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x000f0000, (u32)lbl_1_data_27114__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00100000, (u32)lbl_1_data_27124__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0,
    0x00110000, (u32)lbl_1_data_27134__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00120000, (u32)lbl_1_data_27144__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00130000, (u32)lbl_1_data_27150__fzgx_offset_0,
    (u32)lbl_1_data_27058__fzgx_offset_0, 0x00140000, (u32)lbl_1_data_2715C__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00150000, (u32)lbl_1_data_27168__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00160000,
    (u32)lbl_1_data_27174__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00170000, (u32)lbl_1_data_27184__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00180000, (u32)lbl_1_data_27194__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0,
    0x00190000, (u32)lbl_1_data_271A0__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x001a0000, (u32)lbl_1_data_271B0__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x001b0000, (u32)lbl_1_data_271BC__fzgx_offset_0,
    (u32)lbl_1_data_27058__fzgx_offset_0, 0x001c0000, (u32)lbl_1_data_271C8__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x001d0000, (u32)lbl_1_data_271D4__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x001e0000,
    (u32)lbl_1_data_271E4__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x001f0000, (u32)lbl_1_data_271F0__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00200000, (u32)lbl_1_data_271FC__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0,
    0x00210000, (u32)lbl_1_data_2720C__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00220000, (u32)lbl_1_data_27218__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00230000, (u32)lbl_1_data_27224__fzgx_offset_0,
    (u32)lbl_1_data_27058__fzgx_offset_0, 0x00240000, (u32)lbl_1_data_27234__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00250000, (u32)lbl_1_data_27244__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00260000,
    (u32)lbl_1_data_27250__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00270000, (u32)lbl_1_data_2725C__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x00280000, (u32)lbl_1_data_27268__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0,
    0x00290000, (u32)lbl_1_data_27278__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x002a0000, (u32)lbl_1_data_27284__fzgx_offset_0, (u32)lbl_1_data_27058__fzgx_offset_0, 0x002b0000, (u32)lbl_1_data_27290__fzgx_offset_0,
    (u32)lbl_1_data_27058__fzgx_offset_0, 0x00190001, (u32)lbl_1_data_2729C__fzgx_offset_0, (u32)lbl_1_data_272A8__fzgx_offset_0, 0x00130001, (u32)lbl_1_data_272B0__fzgx_offset_0, (u32)lbl_1_data_272BC__fzgx_offset_0, 0x00160001,
    (u32)lbl_1_data_272C0__fzgx_offset_0, (u32)lbl_1_data_272D0__fzgx_offset_0, 0x00230001, (u32)lbl_1_data_272D4__fzgx_offset_0, (u32)lbl_1_data_272E4__fzgx_offset_0, 0x001f0001, (u32)lbl_1_data_272EC__fzgx_offset_0, (u32)lbl_1_data_272D0__fzgx_offset_0,
    0x00260001, (u32)lbl_1_data_272F8__fzgx_offset_0, (u32)lbl_1_data_27300__fzgx_offset_0, 0x00220001, (u32)lbl_1_data_27304__fzgx_offset_0, (u32)lbl_1_data_27318__fzgx_offset_0, 0x00220002, (u32)lbl_1_data_27324__fzgx_offset_0,
    (u32)lbl_1_data_27338__fzgx_offset_0, 0x00220003, (u32)lbl_1_data_27344__fzgx_offset_0, (u32)lbl_1_data_27358__fzgx_offset_0, 0x00220004, (u32)lbl_1_data_27364__fzgx_offset_0, (u32)lbl_1_data_27378__fzgx_offset_0, 0x00220005,
    (u32)lbl_1_data_27384__fzgx_offset_0, (u32)lbl_1_data_27398__fzgx_offset_0, 0x00220006, (u32)lbl_1_data_273A8__fzgx_offset_0, (u32)lbl_1_data_273BC__fzgx_offset_0, 0x00220007, (u32)lbl_1_data_273CC__fzgx_offset_0, (u32)lbl_1_data_273E0__fzgx_offset_0,
    0x00220008, (u32)lbl_1_data_273F0__fzgx_offset_0, (u32)lbl_1_data_27404__fzgx_offset_0, 0x00220009, (u32)lbl_1_data_27414__fzgx_offset_0, (u32)lbl_1_data_27424__fzgx_offset_0, 0x0022000a, (u32)lbl_1_data_2742C__fzgx_offset_0,
    (u32)lbl_1_data_2743C__fzgx_offset_0, 0x0022000b, (u32)lbl_1_data_27444__fzgx_offset_0, (u32)lbl_1_data_27454__fzgx_offset_0, 0x0022000c, (u32)lbl_1_data_2745C__fzgx_offset_0, (u32)lbl_1_data_2746C__fzgx_offset_0, 0x0022000d,
    (u32)lbl_1_data_27474__fzgx_offset_0, (u32)lbl_1_data_27484__fzgx_offset_0, 0x0022000e, (u32)lbl_1_data_2748C__fzgx_offset_0, (u32)lbl_1_data_2749C__fzgx_offset_0, 0x0022000f, (u32)lbl_1_data_274A4__fzgx_offset_0, (u32)lbl_1_data_274B4__fzgx_offset_0,
    0x00220010, (u32)lbl_1_data_274BC__fzgx_offset_0, (u32)lbl_1_data_274CC__fzgx_offset_0, 0x00000042, 0xc7382a7e, 0x25735f77, 0x696e2e6d, 0x74610000,
    0x25735f74, 0x6573742e, 0x6d746100, 0x25735f68, 0x616e642e, 0x6d746100, 0x25735f66, 0x6163652e,
    0x6d746100, 0x25735f6c, 0x69702e6d, 0x74610000, 0x25735f65, 0x79652e6d, 0x74610000, 0x25732e6d,
    0x74610000, 0x2e6d7461, 0x00000000, 0x25735f63, 0x6f6d6d6f, 0x6e2e6d61, 0x6c000000, 0x54455f52,
    0x00000000, 0x54455f52, 0x4d000000, 0x4c495000, 0x45594500, 0x41434345, 0x00000000, 0x2f636861,
    0x72612f61, 0x72632f00, 0x5f73656c, 0x00000000, 0x2e617263, 0x2e6c7a00, 0x63686172, 0x61000000,
    0x25732573, 0x25732e74, 0x706c0000, 0x2e2e0000, 0x46414345, 0x5f4c4155, 0x47480000, 0x626f6479,
    0x20000000, 0x68616e64, 0x72000000, 0x68616e64, 0x6c000000, 0x66616365, 0x20000000, 0x6c697020,
    0x20000000, 0x65796520, 0x20000000, 0x61636365, 0x20000000, 0x3e000000, 0x20000000, 0x25730000,
    0x3a5b2530, 0x33645d00, 0x5b25352e, 0x31662f25, 0x352e3166, 0x5d000000, 0x2573200a, 0x00000000,
    (u32)lbl_1_bss_6E990__fzgx_offset_0, 0x00000001, 0x25735f25, 0x64000000, 0x3e5b2532, 0x645d2573, 0x200a0000, 0x205b2532,
    0x645d2573, 0x200a0000, 0x2d3e204c, 0x69737420, 0x506c6179, 0x20202028, 0x4c522062, 0x7574746f,
    0x6e290000, 0x2d3e204e, 0x6f726d61, 0x6c20506c, 0x61792028, 0x4c522062, 0x7574746f, 0x6e290000,
    0x5b25735d, 0x200a0000, 0x48490000, 0x33303030, 0x00000000, 0x31303030, 0x00000000, 0x35303000,
    0x31303000, 0x63686172, 0x615f636f, 0x6c203a20, 0x5b25645d, 0x0a000000, 0x63686172, 0x5f646973,
    0x70203a20, 0x5b25735d, 0x0a000000, 0x4f4e0000, 0x4f464600, 0x62675f63, 0x6f6c6f72, 0x20203a20,
    0x5b25735d, 0x0a000000, 0x47524159, 0x00000000, 0x424c4143, 0x4b000000, 0x70657273, 0x70656374,
    0x20203a20, 0x5b25342e, 0x31665d0a, 0x00000000, 0x5b25735f, 0x25645d20, 0x0a000000, 0x564f4c20,
    0x3a202534, 0x2e326620, 0x0a000000, (u32)fn_1_9012C__fzgx_offset_3D4, (u32)fn_1_9012C__fzgx_offset_40C, (u32)fn_1_9012C__fzgx_offset_440, (u32)fn_1_9012C__fzgx_offset_468, (u32)fn_1_9012C__fzgx_offset_488,
    (u32)fn_1_9012C__fzgx_offset_4A8, (u32)fn_1_9012C__fzgx_offset_4FC, (u32)fn_1_9012C__fzgx_offset_53C, (u32)fn_1_9012C__fzgx_offset_5B0, (u32)fn_1_9012C__fzgx_offset_624, (u32)fn_1_9012C__fzgx_offset_698, (u32)fn_1_9012C__fzgx_offset_70C, (u32)fn_1_9012C__fzgx_offset_780,
    (u32)fn_1_9012C__fzgx_offset_7EC, 0x5b25735d, 0x0a000000, 0x2020201f, 0x2025342e, 0x316c660a, 0x00000000, 0x5b454e44,
    0x5d0a0000, 0x544f5441, 0x4c5b2535, 0x2e316c66, 0x2f25352e, 0x316c665d, 0x00000000, 0x544f5441,
    0x4c5b2d2d, 0x2d2d2d2f, 0x2d2d2d2d, 0x2d5d0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x5f434152, 0x445f4a4f, 0x4b455200, 0x5f434152, 0x445f4143, 0x45000000, 0x5f42414c, 0x4c000000,
    0x25735f54, 0x55450000, 0x25732573, 0x00000000, 0x494e545f, 0x00000000, 0x494e545f, 0x31340000,
    0x47555354, 0x45525f48, 0x454c4d45, 0x54000000, 0x47555354, 0x45525f4d, 0x4f484900, 0x47555354,
    0x45525f41, 0x46524f00, 0x47555354, 0x45525f4d, 0x4f48495f, 0x44000000, 0x494e545f, 0x31350000,
    0x474f524f, 0x485f4649, 0x47555245, 0x00000000, 0x53594152, 0x494e5f52, 0x5f460000, 0x25735f54,
    0x455f524d, 0x00000000, 0x25735f54, 0x455f5200, 0x25735f46, 0x41434500, 0x494e5400, 0x494e545f,
    0x46414345, 0x5f544553, 0x54000000, 0x25735f4c, 0x49500000, 0x25735f45, 0x59450000, 0x25735f25,
    0x73000000, 0x6d6f7469, 0x6f6e0000, 0x25732e73, 0x6b6c0000, 0x25735f68, 0x616e6472, 0x2e736b6c,
    0x00000000, 0x25735f68, 0x616e646c, 0x2e736b6c, 0x00000000, 0x25735f66, 0x6163652e, 0x736b6c00,
    0x25735f6c, 0x69702e73, 0x6b6c0000, 0x25735f65, 0x79652e73, 0x6b6c0000, 0x2e736b6c, 0x00000000,
    0x726f622e, 0x63000000, 0x73616e5f, 0x626f6172, 0x642e736b, 0x6c000000, 0x67656e5f, 0x626f6172,
    0x642e736b, 0x6c000000, 0x676f6d61, 0x5f626f61, 0x72642e73, 0x6b6c0000, 0x25732573, 0x2e74706c,
    0x00000000, 0x25732573, 0x2e676d61, 0x00000000, 0x25735f31, 0x30302e67, 0x6d610000, 0x25735f35,
    0x30302e67, 0x6d610000, 0x25735f31, 0x3030302e, 0x676d6100, 0x25735f33, 0x3030302e, 0x676d6100,
    0x25732e67, 0x6d610000, 0x696e745f, 0x00000000, 0x736e642f, 0x6168782f, 0x25732e61, 0x68780000,
    0x736e642f, 0x6168782f, 0x676f6d61, 0x725f7368, 0x696f685f, 0x25732e61, 0x68780000, 0x6461695f,
    0x00000000, 0x736e642f, 0x6168782f, 0x64616973, 0x616e6765, 0x6e5f2573, 0x2e616878, 0x00000000,
    0x46495245, 0x31000000, 0x46495245, 0x32000000,
};
extern u8 lbl_1_data_27CE0__fzgx_offset_0[];
extern u8 lbl_1_data_27CE8__fzgx_offset_0[];
static RobPart fzgx_pool_parts[8] = {
    {{-0.019215000793337822f, 0.004004999995231628f, 0.026499999687075615f}, (const char *)lbl_1_data_27CE0__fzgx_offset_0},
    {{-0.019215000793337822f, 0.004004999995231628f, -0.026499999687075615f}, (const char *)lbl_1_data_27CE0__fzgx_offset_0},
    {{-0.019215000793337822f, -0.01699499972164631f, 0.026499999687075615f}, (const char *)lbl_1_data_27CE8__fzgx_offset_0},
    {{-0.019215000793337822f, -0.01699499972164631f, -0.026499999687075615f}, (const char *)lbl_1_data_27CE8__fzgx_offset_0},
    {{0.0097850002348423f, 0.0330049991607666f, 0.013000000268220901f}, (const char *)lbl_1_data_27CE8__fzgx_offset_0},
    {{0.0097850002348423f, 0.0330049991607666f, -0.013000000268220901f}, (const char *)lbl_1_data_27CE8__fzgx_offset_0},
    {{0.0097850002348423f, 0.0460049994289875f, 0.016499999910593033f}, (const char *)lbl_1_data_27CE8__fzgx_offset_0},
    {{0.0097850002348423f, 0.0460049994289875f, -0.016499999910593033f}, (const char *)lbl_1_data_27CE8__fzgx_offset_0},
};
static char fzgx_pool_name0[8] = {87, 73, 78, 95, 51, 82, 68, 0};
static char fzgx_pool_name1[8] = {83, 69, 76, 95, 68, 69, 67, 0};
static char fzgx_pool_name2[8] = {87, 73, 78, 95, 49, 83, 84, 0};
static char fzgx_pool_name3[8] = {87, 73, 78, 95, 50, 78, 68, 0};
#pragma section code_type ".fzgxpool"
static void fzgx_data_prime(void) {
    volatile u8 sink; /* fzgx-allow: S2 measured TU section first-access primer */
    sink = *(u8 *)fzgx_pool_data_prefix;
    sink = *(u8 *)fzgx_pool_parts;
    sink = *(u8 *)fzgx_pool_name0;
    sink = *(u8 *)fzgx_pool_name1;
    sink = *(u8 *)fzgx_pool_name2;
    sink = *(u8 *)fzgx_pool_name3;
}
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
extern u8 lbl_1_data_26D50__fzgx_offset_0[];
extern u8 lbl_1_data_26D54__fzgx_offset_0[];
extern u8 lbl_1_data_26D5C__fzgx_offset_0[];
extern u8 lbl_1_data_26D64__fzgx_offset_0[];
extern u8 lbl_1_data_26D6C__fzgx_offset_0[];
extern u8 lbl_1_data_26D74__fzgx_offset_0[];
extern u8 lbl_1_data_26D7C__fzgx_offset_0[];
extern u8 lbl_1_data_26D84__fzgx_offset_0[];
static const union { u32 w[73]; const unsigned long v[73]; } fzgx_pool_init_fzgx_pool_table1 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_1_data_26D50__fzgx_offset_0, (u32)lbl_1_data_26D50__fzgx_offset_0, (u32)lbl_1_data_26D54__fzgx_offset_0, (u32)lbl_1_data_26D5C__fzgx_offset_0, (u32)lbl_1_data_26D64__fzgx_offset_0, (u32)lbl_1_data_26D50__fzgx_offset_0, (u32)lbl_1_data_26D6C__fzgx_offset_0, (u32)lbl_1_data_26D54__fzgx_offset_0,
    (u32)lbl_1_data_26D5C__fzgx_offset_0, (u32)lbl_1_data_26D64__fzgx_offset_0, (u32)lbl_1_data_26D50__fzgx_offset_0, (u32)lbl_1_data_26D74__fzgx_offset_0, (u32)lbl_1_data_26D7C__fzgx_offset_0, (u32)lbl_1_data_26D84__fzgx_offset_0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table1.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 1.0f;
    s = 100.0f;
    s = 180.0f;
    s = 32767.0f;
    d = 4503601774854144.0;
}
static const union { u32 w[3]; const unsigned long v[3]; } fzgx_pool_init_fzgx_pool_table3 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFFFFFF, 0xBF800000, 0xFFFFFFFF
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table3.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 55.0f;
    s = 30.0f;
    s = 1000.0f;
    s = 3.003967046737671f;
}
static const union { u32 w[15]; const unsigned long v[15]; } fzgx_pool_init_fzgx_pool_table5 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x0, 0x3B963DC5, 0xBD6DD053, 0xBD953A3F, 0x3B963DC5, 0xBD6DD053,
    0x3CF0307F, 0xBB963DC5, 0xBD6DD053, 0xBD953A3F, 0xBB963DC5, 0xBD6DD053, 0x3CF0307F
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table5.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 182.04444885253906f;
    s = 0.20250000059604645f;
    s = 0.06499999761581421f;
    s = 0.08500000089406967f;
    d = 0.05;
    s = 0.05000000074505806f;
    s = 0.004999999888241291f;
    s = -0.017500000074505806f;
    s = 65535.0f;
    d = 4503599627370496.0;
    s = 50.0f;
    s = -1.0f;
}
static const union { u32 w[3]; const unsigned long v[3]; } fzgx_pool_init_fzgx_pool_table7 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x40406080, 0x0, 0x204080
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table7.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
}
static const union { u32 w[2]; const unsigned long v[2]; } fzgx_pool_init_fzgx_pool_table9 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table9.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.08500000089406967f;
}
static const union { u32 w[18]; const unsigned long v[18]; } fzgx_pool_init_fzgx_pool_table11 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0xBDAE147B, 0x0, 0x0, 0x3F800000, 0x0, 0x3F800000, 0x0,
    0x0, 0x0, 0x3F800000, 0x0, 0x0, 0x0, 0x3F800000, 0x0,
    0x0, 0x3F800000
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table11.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.25f;
    s = 0.15000000596046448f;
    s = 65536.0f;
}
#pragma section code_type ".text"


extern u32 lbl_801A63C0;
extern char *fn_1_41418(RobNames *, u32);
extern int fn_80083BCC(const char *, const char *);
extern void lbl_8006DCA4(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern void mathutil_mtxA_rotate_z(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern void lbl_8006E14C(f32);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80072558(void);
extern void lbl_8006E1B0(void *, void *);
extern RobModel *fn_80071268(void *, const char *);
extern void fn_1_56018(s32);
extern void lbl_8006D784(void *);
extern void fn_1_560F0(s32, void *);
extern void lbl_8006D7B0(void);
extern void lbl_8006E15C(f32, f32, f32);
extern void *fn_1_5448C(void *);
extern s32 fn_1_548EC(void *);
extern void fn_1_55924(void *, u32);
static inline char *rob_name(RobAnim *anim) {
    return anim == 0 ? 0 : fn_1_41418(anim->names, anim->id);
}
static inline s32 rob_rand(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}
static inline void rob_transform(Rob *rob, u8 *view) {
    lbl_8006DCA4();
    lbl_8006E0B4(rob->pos.x, rob->pos.y + rob->height, rob->pos.z);
    mathutil_mtxA_rotate_z(rob->rot_z);
    mathutil_mtxA_rotate_y(rob->rot_y);
    mathutil_mtxA_rotate_x(rob->rot_x);
    lbl_8006E14C(rob->scale);
    lbl_8006DFC4(view + 0x3A0);
}
static inline void fn_1_977BC_loop4(RobModel *model) {
    RobMaterial *material;
    f32 offset;
    u32 j;
    f32 matrix[3][4];
        offset = 0.5f * ((f32)rob_rand() / 32767.0f);
        material = model->materials;
        for (j = 0; j < model->count; material++, j++) {
            if (material->flags & 0x20000) {
                fn_1_56018(1);
                lbl_8006D784(matrix);
                matrix[1][3] = offset;
                matrix[0][0] = 1.0f;
                matrix[1][1] = 1.0f;
                matrix[2][2] = 1.0f;
                fn_1_560F0(0, matrix);
            }
        }
}

void fn_1_977BC(Rob *rob, RobView *arg1) {
    f32 depth[8];
    u32 order[8];
    u32 i;
    u32 j;
    u32 draw_i;
    u32 index;
    void *model_set;
    u8 *view;
    f32 scale;
    RobPart *parts;
    scale = 1.0f;
    /* WARNING: compiler-diff device, not original code: value-preserving 64-bit round trip; puts view in a
     * fresh temp so it ranks below rob (retail r30/r31). Honest form `view = arg1->view;` swaps rob/view (37 rows). */
    view = (u8 *)(u32)((u64)arg1->view | 0x100000000ull);
    model_set = rob->models[rob->active];
    if (fn_80083BCC(rob_name(&rob->anim), fzgx_pool_name0) == 0) {
        f32 t = rob->anim.motion->frame;
        if (320.0f <= t && t <= 420.0f) return;
        if (315.0f <= t && t <= 320.0f) scale = (320.0f - t) / 5.0f;
        else if (420.0f <= t && t <= 435.0f) scale = (4.0f * (t - 420.0f)) / 15.0f;
        else if (435.0f <= t && t <= 450.0f) scale = 1.0f + (3.0f * (450.0f - t)) / 15.0f;
    } else if (fn_80083BCC(rob_name(&rob->anim), fzgx_pool_name1) == 0) {
        f32 t = rob->anim.motion->frame;
        if (80.0f <= t && t <= 175.0f) return;
        if (175.0f <= t && t <= 195.0f) scale = (4.0f * (t - 175.0f)) / 20.0f;
        else if (195.0f <= t && t <= 215.0f) scale = 1.0f + (3.0f * (215.0f - t)) / 20.0f;
    } else if (fn_80083BCC(rob_name(&rob->anim), fzgx_pool_name2) == 0) {
        f32 t = rob->anim.motion->frame;
        if (330.0f <= t && t <= 355.0f) return;
        if (355.0f <= t && t <= 375.0f) scale = (4.0f * (t - 355.0f)) / 20.0f;
        else if (375.0f <= t && t <= 390.0f) scale = 1.0f + (3.0f * (390.0f - t)) / 15.0f;
    } else if (fn_80083BCC(rob_name(&rob->anim), fzgx_pool_name3) == 0) {
        f32 t = rob->anim.motion->frame;
        if (395.0f <= t && t <= 482.0f) return;
        if (482.0f <= t && t <= 500.0f) scale = (4.0f * (t - 482.0f)) / 18.0f;
        else if (500.0f <= t && t <= 520.0f) scale = 1.0f + (3.0f * (520.0f - t)) / 20.0f;
    }
    parts = fzgx_pool_parts;
    for (i = 0; i < 8; i++) {
        order[i] = i;
        {
        RobVec pos = { 0.0f, 0.0f, 0.0f };
        rob_transform(rob, view);
        lbl_8006E0A4(&parts[i]);
        fn_80072558();
        lbl_8006E1B0(&pos, &pos);
        depth[i] = pos.z;
        }
    }
    for (i = 0; i < 8; i++) {
        for (j = i; j < 8; j++) {
            if (depth[j] > depth[i]) {
                f32 z = depth[i];
                u32 k = order[i];
                depth[i] = depth[j];
                order[i] = order[j];
                depth[j] = z;
                order[j] = k;
            }
        }
    }
    for (draw_i = 0; draw_i < 8; draw_i++) {
{
    RobModel *model;
        model = fn_80071268(model_set, fzgx_pool_parts[order[draw_i]].name);
        fn_1_977BC_loop4(model);
        rob_transform(rob, view);
        {
            RobPart *p = fzgx_pool_parts;
            lbl_8006E0A4(p + order[draw_i]);
        }
        lbl_8006D7B0();
        lbl_8006E15C(scale * (2.5f + (f32)(0.4f * ((f32)rob_rand() / 32767.0f))),
                    scale * (1.4f + (f32)(0.5f * ((f32)rob_rand() / 32767.0f))), 1.0f);
        fn_80072558();
        if (draw_i == 0) index = fn_1_548EC(fn_1_5448C((u8 *)model + 8));
        if (index + draw_i < 0x1000) fn_1_55924(model, index + draw_i);
}
    }
}
/* fzgx:end fn_1_977BC */

/* fzgx:begin fn_1_97F1C */
typedef struct {
    u8 unk_000[0x4A4];
    s32 unk_4A4;
} Fn197F1CObject;

/* Formats the indexed message and stores its parsed value in the object. */
s16 fn_1_97F1C(Fn197F1CObject *object, s16 index) {
    char buffer[0x80];

    sprintf(buffer, lbl_1_data_27D90, lbl_1_data_20D1C[index]);
    object->unk_4A4 = fn_1_12A32C(buffer);
    return (s16)object->unk_4A4;
}
/* fzgx:end fn_1_97F1C */

/* fzgx:begin fn_1_97F80 noprologue */
#include "types.h"

extern u32 lbl_801A6410;

typedef struct Fn197F80Object Fn197F80Object;
struct Fn197F80Object {
    u8 unk_000[0x488];
    u8 unk_488;
    u8 unk_489;
    u8 unk_48A[0x1A];
    void *unk_4A4;
    void *unk_4A8;
    void *unk_4AC;
    void *unk_4B0;
    void *unk_4B4;
};

extern u32 lbl_1_data_209C0;



extern void *fn_80083970(const char *, const char *);
extern void sprintf(char *, const char *, ...);
extern int fn_80083BCC(const char *, const char *);
extern void fn_1_12A2D0(void *);
extern void fn_1_12A2B8(int);
extern void fn_1_12AB38(const char *);
extern int fn_1_12A8A4(const char *, void **);
extern void *fn_1_4630(u32, u32, const char *, u32);
extern void fn_80083DB0(void *, const char *);
extern u32 strlen(const char *);

u32 fn_1_97F80(Fn197F80Object *rob, const char *name) {
    void *resource = 0;
    char path[0x40];
    u8 *data = (u8 *)&lbl_1_data_209C0;
    u32 length;

    if (name == 0 || fn_80083970(name, (const char *)(data + 0x6390)) == 0) {
        return 0;
    }

    sprintf(path, (const char *)(data + 0x73e0), name);
    if (fn_80083BCC(path, (const char *)(data + 0x73e8)) == 0 ||
        fn_80083BCC(path, (const char *)(data + 0x73f4)) == 0 ||
        fn_80083BCC(path, (const char *)(data + 0x7400)) == 0 ||
        fn_80083BCC(path, (const char *)(data + 0x740c)) == 0) {
        return 1;
    }

    fn_1_12A2D0(rob->unk_4A4);
    fn_1_12A2B8(1);
    fn_1_12AB38((const char *)(data + 0x7418));
    if (fn_1_12A8A4(path, &resource) == 0) {
        return 0;
    }

    fn_1_12AB38((const char *)(data + 0x6eec));
    fn_1_12A2B8(0);
    length = strlen(name);
    rob->unk_488 = 1;
    rob->unk_489 = 1;
    rob->unk_4A8 = resource;
    rob->unk_4AC = *(void **)resource;
    rob->unk_4B0 = (u8 *)resource + 4;
    rob->unk_4B4 = fn_1_4630(*(u32 *)&lbl_801A6410,
                            (length + 0x20) & ~0x1f,
                            (const char *)(data + 0x7240), 0xfa9);
    fn_80083DB0(rob->unk_4B4, name);
    return 1;
}
/* fzgx:end fn_1_97F80 */

/* fzgx:begin fn_1_98104 noprologue */
#include "types.h"

extern u8 lbl_1_data_27C00[0xE0];
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, u8 *, u32);
extern void fn_80008BEC(void *, u32, u32);

typedef struct Fn198104Obj {
    u8 unk_00[0x1C];
    u32 value_1C;
    u8 unk_20[0x0C];
    u32 value_2C;
} Fn198104Obj;

s32 fn_1_98104(Fn198104Obj *obj) {
    Fn198104Obj *ptr = (Fn198104Obj *)((u8 *)obj + 0x488);
    u32 saved;

    if (ptr == 0) {
        return 0;
    }

    saved = ptr->value_1C;
    if (ptr->value_2C != 0) {
        fn_1_46B4(lbl_801A6410, ptr->value_2C, lbl_1_data_27C00, 0xfc0);
        ptr->value_2C = 0;
    }

    fn_80008BEC(ptr, 0, 0x30);
    ptr->value_1C = saved;
    return 1;
}
/* fzgx:end fn_1_98104 */

/* fzgx:begin fn_1_9818C */
extern u32 fn_1_12A734(u32);

s32 fn_1_9818C(u32 arg0) {
    s16 v0;
    s32 v1;
    u32 t0;
    v0 = (s16)arg0;
    v1 = v0;
    if (v0 != -1) {
    t0 = fn_1_12A734(v1);
    v1 = t0;
    v1 = 1;
    } else {
    v1 = 0;
    }
    return v1;
}
/* fzgx:end fn_1_9818C */
