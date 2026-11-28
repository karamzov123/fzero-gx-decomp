#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"

extern u32 lbl_1_bss_6C8DC[2];
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, void *arg2, u32 arg3);
extern void fn_1_727BC(u32 arg0, u32 arg1, void *arg2);
extern void fn_1_76A94(void *arg0, u32 arg1);
extern void fn_1_76DBC(void);
extern void fn_1_4E500(void);
extern void fn_1_4E638(int);
extern void fn_1_4E6F4(void);
extern void fn_80073778(void *arg0, int arg1);
extern s32 fn_1_A5D9C(void);
extern const f32 lbl_1_rodata_31AC;
extern u32 fn_80008E84(u32 arg);
extern void fn_1_77238(void);
extern void fn_1_772E0(void);
extern void fn_1_77384(void *arg);
extern void fn_80072864(int arg0);
extern void fn_800745A4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
extern void fn_80074660(int arg0);
extern void fn_80073678(int arg0);
extern void fn_80073898(int arg0);
extern void fn_80074788(int arg0);
extern void fn_800738E0(int arg0, int arg1, int arg2);
extern void fn_80073D60(int arg0, int arg1, int arg2, int arg3, int arg4);
extern void fn_800734A8(int arg0, int arg1, int arg2, int arg3);
extern void fn_80072EDC(int arg0, int arg1);
extern f32 lbl_1_rodata_31B0[10];
extern const f64 lbl_1_rodata_31A0;
extern void lbl_8006D784(f32 *arg);
extern void fn_80073A58(int arg0, f32 *arg1, int arg2);
extern void fn_800739E0(int arg0, int arg1, int arg2);
extern void GXLoadTexMtxImm(f32 *arg0, int arg1, int arg2);
extern void fn_8006FDEC(void);
extern void fn_8006FEFC(void);
extern void fn_8006FD1C(void);
extern void fn_1_79810(void);
extern void fn_1_79948(void);
extern void fn_1_791B0(void);
extern void fn_1_9A1E8(void);
extern void fn_1_9A864(void);
extern u8 fn_1_7B074(void);
extern void fn_80071718(void *arg);
extern void fn_800711A8(void *arg);
extern void fn_1_14CB4(void);
extern void fn_1_FA84(void);
extern const f32 lbl_1_rodata_32CC;
extern void fn_1_79C88(void *arg0, s32 arg1, f32 arg2, s32 arg3);
extern void lbl_8006DBAC(void *arg0);
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern void sprintf(char *dst, const char *format, ...);
extern void fn_1_465D0(char *text, int arg);
extern void fn_1_14D5C(void *object, int arg);
extern void fn_1_46EA8(int value);
extern void fn_1_12620(void *object);
extern void fn_1_46DC4(void *obj);

extern void fn_1_727BC();
extern void fn_8006FDEC(void);
extern void fn_80071718(void *);
extern void fn_800711A8(void *);
extern u32 fn_8003526C(u32, u32);
extern u32 fn_80074300(u32, u32, u32, u32);
extern u32 fn_80074438(u32, u32, u32, u32);

/* fzgx:begin fn_1_789E8 */
#include "rel/main_rel/car.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"

/* begin game/main_rel/car_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_CAR_TYPES_H
#define GAME_MAIN_REL_CAR_TYPES_H

// Types (and the externs that name them) of car.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


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

/* begin game/vec3.h (deltawave784/fzgx, CC0) */
#ifndef GAME_VEC3_H
#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,
// live_camera each carried an identical private copy); Vec3f likewise (car, screen_effect,
// stcoli). Hand-owned (librarian).


typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

#endif  // GAME_VEC3_H

/* end game/vec3.h */

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

/* game/vec3.h: inlined above */

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

typedef struct {
    u8 pad_0[0x400];
    u8 mtx[0x70];
    u8 mtx2[0x30];
} CamObj;

typedef struct {
    u8 pad_0[0x118];
    u32 unk_118;
    u32 unk_11C;
    u8 pad_120[0x20];
    s32 unk_140;
    f32 unk_144;
    f32 unk_148;
    f32 unk_14C;
    f32 unk_150;
} CarSound;

typedef struct {
    u32 flags;
    u8 pad_4[0x498];
    CarSound *sound;
} fn_1_85F90_Car;

extern s32 fn_1_8D210(fn_1_8D210_car *car, fn_1_8D210_callback callback, u32 arg, s32 enable);
extern void fn_1_95158(Fn195158Car *car);
extern s32 fn_1_97174(EventNode *arg0, s32 arg1, void *arg2);
extern void fn_1_93734(CarObject *arg0, void *arg1);
extern Fn1967A8Resource *fn_1_41518(void *arg0);
extern void fn_1_41C18(Fn1967A8Resource *arg0, void *arg1);
extern void fn_1_41F58(Fn1967A8Resource *arg0, s32 arg1, void (*arg2)(void), void *arg3);
extern u16 fn_1_96968(Fn196968Object *object, void *arg1);
extern u16 fn_1_969E8(Fn1969E8Owner *owner, void *arg1);
extern u16 fn_1_96BC0(Fn196BC0Object *object, void *arg1);
extern u16 fn_1_96A68(Fn196A68Object *object, void *arg1);
extern CarR29 *fn_80071268(void *, void *);
extern void lbl_8006E1F0(Vec3f *, f32, f32, f32);
extern void lbl_8006E2C0(Vec3f *, f32, f32, f32);
extern void fn_8006E250(Vec3f *, Vec3f *);
extern void fn_1_B81C(Vec3f *, Vec3f *, s32);
extern void fn_1_8E3A4(fn_1_8E3A4_Object *obj);
extern f32 lbl_8006D534(Vec3 *a, Vec3 *b);
extern Triple lbl_1_rodata_3BE8;
extern void fn_1_55210(struct Model *);
/* retail takes (obj, idx, mask, mask2) (fn_1_8F198 passes all four); non-prototype until fn_1_8F45C passes its own four through */
extern void fn_1_8E7D0();
extern void fn_1_966A0(Fn1_8F494_Object *obj);
extern void fn_1_8F5A4(Fn1_8F5A4_Object *obj);
extern void fn_1_968FC(Fn1_8F5A4_Object *obj);
extern void fn_1_943F8(Fn935E4Car *, f32, void *);

#endif  // GAME_MAIN_REL_CAR_TYPES_H

/* end game/main_rel/car_types.h */
/* game/vec3.h: inlined above */

/* Colour/intensity key of one fade channel. */
typedef struct {
    s8 unk_0;
    f32 unk_4;
    f32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    s8 unk_F;
    s32 unk_10;
} ScreenFadeKey;

/* A key plus the preset it is heading to, interpolated over 32 frames. */
typedef struct ScreenFadeChannel {
    ScreenFadeKey key;
    struct ScreenFadeChannel *src;
} ScreenFadeChannel;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
Obj_1_bss_6D600 fzgx_obj_lbl_1_bss_6D600;
static ScreenFadeChannel lbl_1_bss_6D620__fzgx_offset_0[4];
static ScreenFadeChannel lbl_1_bss_6D620__fzgx_offset_60[4];
static ScreenFadeChannel lbl_1_bss_6D620__fzgx_offset_C0[4];
static ScreenFadeChannel lbl_1_bss_6D620__fzgx_offset_120;
static ScreenFadeChannel lbl_1_bss_6D758__fzgx_offset_0;

#pragma section code_type ".fzgxpool"
static void fn_1_789E8_fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D600;
    s = *(u8 *)&lbl_1_bss_6D620__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_6D620__fzgx_offset_60;
    s = *(u8 *)&lbl_1_bss_6D620__fzgx_offset_C0;
    s = *(u8 *)&lbl_1_bss_6D620__fzgx_offset_120;
    s = *(u8 *)&lbl_1_bss_6D758__fzgx_offset_0;
}
#pragma section code_type ".text"

extern s16 fn_1_6B48(s32);
extern s32 fn_1_58C4(void);
extern s32 fn_1_6F84(void);
extern u32 fn_1_1FB80(Vec3f *, u32);
extern u32 fn_1_7A6B4(void);
extern u32 fn_1_7AA50(f32);
extern void fn_1_681C(u32, u32 *);
extern void fn_1_7A9B8(void);
extern void fn_1_862D4(int, Triple *);

#pragma push
static inline int fade_more(u32 channel, s32 *arg) {
    u32 count = fn_1_58C4();
    *arg = channel;
    return channel < count;
}
#pragma pop

void fn_1_789E8(void) {
    ScreenFadeChannel *cur;
    ScreenFadeChannel *prev;
    ScreenFadeChannel *next;
    u32 i;
    s32 idx;
    ScreenFadeChannel *src;
    f32 t;
    f32 s;
    Vec3f pos;

    if (lbl_1_data_1DFA4.unk_8 != -1) {
        lbl_1_data_1DFA4.unk_0 = (s32)lbl_1_data_1DFA4.unk_4;
        fn_1_7A6B4();
        fn_1_7A9B8();
        if (lbl_1_bss_3BE0 != NULL) {
            if (lbl_1_bss_3BE0->unk_80 != 0) {
                fn_1_7AA50(lbl_1_data_1DFA4.unk_0);
            }
            cur = lbl_1_bss_6D620__fzgx_offset_0;
            prev = lbl_1_bss_6D620__fzgx_offset_60;
            next = lbl_1_bss_6D620__fzgx_offset_C0;
            for (i = 0; fade_more(i, &idx); cur++, prev++, next++, i++) {
                idx = fn_1_6B48(idx);
                if (idx >= 0) {
                    if (fn_1_6F84() != 0) {
                        fn_1_681C((u8)i, (u32 *)&pos);
                    } else {
                        fn_1_862D4(idx, (Triple *)&pos);
                    }
                    if (fn_1_1FB80(&pos, 0x4000) & 0x4000) {
                        src = &lbl_1_bss_6D620__fzgx_offset_120;
                    } else {
                        src = &lbl_1_bss_6D758__fzgx_offset_0;
                    }
                } else {
                    src = &lbl_1_bss_6D758__fzgx_offset_0;
                }
                if (src != cur->src) {
                    prev->key = cur->key;
                    prev->src = cur->src;
                    *cur = *src;
                    *next = *src;
                    if (prev->key.unk_F == 0) {
                        prev->key.unk_0 = next->key.unk_0;
                        prev->key.unk_4 = next->key.unk_8;
                        prev->key.unk_8 = next->key.unk_8 + (next->key.unk_8 - next->key.unk_4);
                        prev->key.unk_C = next->key.unk_C;
                        prev->key.unk_D = next->key.unk_D;
                        prev->key.unk_E = next->key.unk_E;
                    }
                    if (next->key.unk_F == 0) {
                        next->key.unk_0 = prev->key.unk_0;
                        cur->key.unk_F = prev->key.unk_F;
                        next->key.unk_4 = prev->key.unk_8;
                        next->key.unk_8 = prev->key.unk_8 + (prev->key.unk_8 - prev->key.unk_4);
                        next->key.unk_C = prev->key.unk_C;
                        next->key.unk_D = prev->key.unk_D;
                        next->key.unk_E = prev->key.unk_E;
                    }
                    cur->src = src;
                    cur->key.unk_10 = (next->key.unk_0 == prev->key.unk_0) ? 0 : 32;
                }
                if (next->key.unk_F != 0) {
                    *next = *src;
                }
                src = cur->src;
                if (cur->key.unk_10 < 32) {
                    cur->key.unk_10++;
                } else {
                    cur->key.unk_F = src->key.unk_F;
                }
                t = cur->key.unk_10 / 32.0f;
                s = 1.0f - t;
                if (prev->key.unk_4 != next->key.unk_4) {
                    cur->key.unk_4 = (s * prev->key.unk_4) + (t * next->key.unk_4);
                } else {
                    cur->key.unk_4 = next->key.unk_4;
                }
                if (prev->key.unk_8 != next->key.unk_8) {
                    cur->key.unk_8 = (s * prev->key.unk_8) + (t * next->key.unk_8);
                } else {
                    cur->key.unk_8 = next->key.unk_8;
                }
                if (prev->key.unk_C != next->key.unk_C) {
                    cur->key.unk_C = (s * prev->key.unk_C) + (t * next->key.unk_C);
                } else {
                    cur->key.unk_C = next->key.unk_C;
                }
                if (prev->key.unk_D != next->key.unk_D) {
                    cur->key.unk_D = (s * prev->key.unk_D) + (t * next->key.unk_D);
                } else {
                    cur->key.unk_D = next->key.unk_D;
                }
                if (prev->key.unk_E != next->key.unk_E) {
                    cur->key.unk_E = (s * prev->key.unk_E) + (t * next->key.unk_E);
                } else {
                    cur->key.unk_E = next->key.unk_E;
                }
            }
        }
        lbl_1_data_1DFA4.unk_4++;
    }
}
/* fzgx:end fn_1_789E8 */

/* fzgx:begin fn_1_78EBC noprologue */
#include "types.h"
#include "rel/main_rel/screen_effect.h"

typedef struct { u32 flags; s32 count; void *nodes; } Sig_fn_1_79C88_EffectManager;
typedef struct { u8 unk_00[8]; u32 unk_08,unk_0C,unk_10; f32 unk_14; } Sig_fn_1_556F8_Fn1_556F8Object;
typedef Sig_fn_1_556F8_Fn1_556F8Object Sig_fn_1_5575C_Fn1_5575CObject;
typedef struct { u8 pad[0xD4]; u32 count; u8 pad2[0x4b0-0xD8]; } Rec_D4;
extern f32 lbl_1_rodata_32E0;
extern s32 fn_1_79C88(Sig_fn_1_79C88_EffectManager *, u32 *, s32, f32);
extern u32 fn_1_56018(s32);
extern u32 fn_1_7A648(Sig_fn_1_79C88_EffectManager *);
extern u32 lbl_8006DAEC(void);
extern u32 lbl_8006DBE4(void);
extern u32 lbl_8006DCA4(void);
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern void fn_1_556F8(Sig_fn_1_556F8_Fn1_556F8Object *);
extern void fn_1_5575C(Sig_fn_1_5575C_Fn1_5575CObject *);
extern void fn_1_55FC4(f32);
extern void fn_1_5616C(s32,f32,f32);
extern void fn_80072558(void);
extern void lbl_8006DC20(void);
extern void lbl_8006DFE8(u32);
extern void lbl_8006E0A4(u32);
extern void lbl_8006E13C(void *);
extern u32 mathutil_mtxA_rotate_z(u32);
void fn_1_78EBC(void) {
    Obj_1_bss_3BE0_Target **v0;
    u8 *v13;
    u32 v4;
    u32 v3;
    u8 *v1;
    u32 v11;
    u32 *v10;
    u8 *v18;
    Obj_1_data_2A7E0 *v2;
    u32 v14;
    struct { u32 value; } v19;
    f32 v6,v16,v20;
    if(lbl_1_data_1DFA4.unk_8 != -1) {
        v0=&lbl_1_bss_3BE0;
        if(*v0) {
            v1=(u8 *)(*v0)->unk_1C;
            v3=*(u32 *)&lbl_1_bss_3BE4;
            v2=&lbl_1_data_2A7E0;
            v4=0;
            while(v4 < (*v0)->unk_18) {
                if(v4==0) lbl_8006DCA4();
                else lbl_8006DFE8(v3+44);
                fn_80072558();
                v10=*(u32 **)(v1+224);
                v11=0;
                while(v11 < *(u32 *)(v1+220)) {
                    v14=fn_1_7A648((Sig_fn_1_79C88_EffectManager *)*v10);
                    if(v14) {
                        if(*(u32 *)(v1+272) || *(u32 *)(v1+276) || *(u32 *)(v1+280) || *(u32 *)(v1+284)) {
                            v20=lbl_1_rodata_32E0;
{
    s32 v12;
                            v13=v1; v12=0;
                            do {
                                f32 *v15=*(f32 **)(v13+272);
                                if(v15) {
                                    v16=v20*v2->unk_1C;
                                    fn_1_5616C(v12,v15[0]*v16,v15[1]*v16);
                                }
                                v12++; v13+=4;
                            }while(v12<4);
}
                            fn_1_556F8((Sig_fn_1_556F8_Fn1_556F8Object *)v14);
                            fn_1_56018(0);
                        } else fn_1_556F8((Sig_fn_1_556F8_Fn1_556F8Object *)v14);
                    }
                    v11++; v10++;
                }
                v18=*(u8 **)(((u8 *)(*v0)->unk_1C + 216) + v4*1200);
                lbl_8006DAEC();
                v19.value=0;
                while(v19.value < ((Rec_D4 *)(*v0)->unk_1C)[v4].count) {
                    lbl_8006DBE4();
                    lbl_8006E0A4((u32)(v18+4));
                    mathutil_mtxA_rotate_z(*(s16 *)(v18+20));
                    mathutil_mtxA_rotate_y(*(s16 *)(v18+18));
                    mathutil_mtxA_rotate_x(*(s16 *)(v18+16));
                    lbl_8006E13C(v18+24);
                    v6=*(f32 *)(v18+24)>*(f32 *)(v18+28)?*(f32 *)(v18+24):*(f32 *)(v18+28);
                    v20=*(f32 *)(v18+32)>v6?*(f32 *)(v18+32):v6;
                    fn_1_55FC4(v20);
                    {u32 v8=fn_1_79C88(*(Sig_fn_1_79C88_EffectManager **)v18,0,0,v20);
                    if(v8) fn_1_5575C((Sig_fn_1_5575C_Fn1_5575CObject *)v8);}
                    v19.value++; v18+=36;
                }
                lbl_8006DC20();
                v4++; v3+=160; v1+=1200;
            }
        }
    }
}
/* fzgx:end fn_1_78EBC */

/* fzgx:begin fn_1_79100 */
// Release the active screen-effect resources and reset the effect state.
void fn_1_79100(void) {
    fn_1_9A864();

    if (!fn_1_7B074()) {
        if (lbl_1_bss_6D770 != 0 || lbl_1_bss_6D774 != 0) {
            fn_8006FDEC();
        }

        if (lbl_1_bss_6D770 != 0) {
            fn_80071718((void *)lbl_1_bss_6D770);
            lbl_1_bss_6D770 = 0;
        }

        if (lbl_1_bss_6D774 != 0) {
            fn_800711A8((void *)lbl_1_bss_6D774);
            lbl_1_bss_6D774 = 0;
        }
    }

    fn_1_14CB4();
    fn_1_FA84();
    lbl_1_data_1DFA4.unk_8 = -1;
}
/* fzgx:end fn_1_79100 */

/* fzgx:begin fn_1_791B0 */
typedef struct {
    Obj_1_bss_6D778_At0 *unk_0;
    const u8 *unk_4;
} ScreenEffectEntry;

typedef struct {
    s32 count;
    u8 pad_4[0x4];
    ScreenEffectEntry *entries;
} ScreenEffectTable;

#pragma opt_common_subs off
void fn_1_791B0(void) {
    struct { s32 value; } i;
    ScreenEffectTable *table;

    lbl_1_bss_6D778.unk_0 = 0;
    if (lbl_1_data_1DFA4.unk_8 < 0) {
        return;
    }

    table = (ScreenEffectTable *)lbl_1_bss_6D774;
    if (table == 0) {
        return;
    }

    for (i.value = 0; i.value < table->count; i.value++) {
        if (((ScreenEffectEntry *)(table->entries))[i.value].unk_4[0] == 'C' &&
            ((ScreenEffectEntry *)(table->entries))[i.value].unk_4[3] == '_' &&
            ((ScreenEffectEntry *)(table->entries))[i.value].unk_4[4] == 'M' &&
            ((ScreenEffectEntry *)(table->entries))[i.value].unk_4[5] == 'A' &&
            ((ScreenEffectEntry *)(table->entries))[i.value].unk_4[6] == 'P' &&
            ((ScreenEffectEntry *)(table->entries))[i.value].unk_4[7] == '\0') {
            lbl_1_bss_6D778.unk_0 = ((ScreenEffectEntry *)(table->entries))[i.value].unk_0;
            return;
        }
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_791B0 */

/* fzgx:begin fn_1_7926C */
#include "font.h"

#pragma section code_type ".fzgxpool"
static const u32 fn_1_7926C_fzgx_pool_table1[1] = {0x04050000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_7926C_fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fn_1_7926C_fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_7926C_fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -200.0f;
    s = 1000.0f;
}
static const u32 fn_1_7926C_fzgx_pool_table3[3] = {0x006E9600, 0x08050000, 0xC3480000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_7926C_fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fn_1_7926C_fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_7926C_fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2000.0f;
}
static const u32 fn_1_7926C_fzgx_pool_table5[3] = {0x0A0A2800, 0x07040000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_7926C_fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fn_1_7926C_fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_7926C_fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3000.0f;
}
static const u32 fn_1_7926C_fzgx_pool_table7[3] = {0x171A1D00, 0x0C020000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_7926C_fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fn_1_7926C_fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_7926C_fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 820.0f;
}
static const u32 fn_1_7926C_fzgx_pool_table9[3] = {0x6E787900, 0xFF040000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_7926C_fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fn_1_7926C_fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_7926C_fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
}
static const u32 fn_1_7926C_fzgx_pool_table11[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_7926C_fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fn_1_7926C_fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_7926C_fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.03125f;
    s = 1.0f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 0.01666666753590107f;
}
static const u32 fn_1_7926C_fzgx_pool_table13[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_7926C_fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fn_1_7926C_fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_7926C_fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 640.0f;
    s = 480.0f;
    s = 320.0f;
    s = 240.0f;
    s = 0.029999999329447746f;
    s = 0.75f;
    s = 0.019999999552965164f;
    s = 1.5f;
    s = 360.0f;
    s = 128.0f;
    s = 0.5f;
    s = 8.0f;
    s = 408.0f;
}
#pragma section code_type ".text"

typedef struct Sig_fn_80036070_Fn80036070Data {
    u32 flags;
    u8 pad_04[4];
    u32 dimensions;
    u32 scaled_value;
    u8 pad_10[4];
    u32 value_14;
    u8 pad_18[7];
    u8 enabled;
} Sig_fn_80036070_Fn80036070Data;

typedef struct fn_1_7926C_Entry {
    f32 unk_0;
    f32 unk_4[3];
    f32 unk_10[3];
} fn_1_7926C_Entry;

extern FontDrawPacket lbl_1_rodata_26F8;
extern void fn_1_51914(const FontDrawPacket *);
extern void fn_1_51990(FontDrawPacket *);
extern void fn_1_D07E0(f32, f32, f32);
extern void fn_80038EEC(f32, f32, f32, f32, f32, f32);
extern void fn_80074188(s32, s32, s32, s32);
extern void fn_80036070(const Sig_fn_80036070_Fn80036070Data *, u32 *, u16 *, u16 *, u32 *, u32 *, u32 *, u8 *);
extern void fn_8006F120(void *, void *);
extern f32 fn_8006F774(f32, f32);

#define fn_1_7926C_color fn_1_7926C_fzgx_pool_table13

void fn_1_7926C(s32 arg0) {
    f32 fzgx_live;
    FontDrawPacket packet;
    FontDrawPacket packet2;
    u32 texture;
    u32 texture2;
    u32 format;
    u32 unused14;
    u32 unused10;
    u16 width;
    u16 height;
    u8 flag;
    fn_1_7926C_Entry *entry;
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    f32 dx;
    f32 dy;
    s32 idx;

    fn_80038EEC(0.0f, 0.0f, 640.0f, 480.0f, 0.0f, 1.0f);
    fn_80074188(0, 0, 640, 480);
    fn_1_4E638(0);

    if (arg0 != 0) {
        packet = lbl_1_rodata_26F8;
        packet.image = 0x9458;
        packet.x = 320.0f;
        packet.y = 240.0f;
        packet.z += 0.03f;
        packet.alpha = 0.75f;
        fn_1_4F734(&packet);
    }

    if (lbl_1_bss_6D778.unk_0->unk_18 > 1) {
        fn_80036070((const Sig_fn_80036070_Fn80036070Data *)(lbl_1_bss_6D778.unk_0->unk_24 + 0x20),
                    &texture2, &width, &height, &format, &unused14, &unused10, &flag);
        texture2 += 0x80000000;
        packet2 = lbl_1_rodata_26F8;
        packet2.x = 0.0f;
        packet2.y = 0.0f;
        packet2.z += 0.02f;
        packet2.flags |= 0x800000;
        packet2.format = format;
        packet2.width = width;
        packet2.height = height;
        packet2.pixels = (void *)texture2;
    }

    fn_80036070((const Sig_fn_80036070_Fn80036070Data *)lbl_1_bss_6D778.unk_0->unk_24,
                &texture, &width, &height, &format, &unused14, &unused10, &flag);
    texture += 0x80000000;
    packet = lbl_1_rodata_26F8;

    if (arg0 != 0) {
        packet.scale_x = 1.5f;
        packet.scale_y = 1.5f;
        x = 480.0f;
        y = 360.0f + (128.0f * (0.5f * packet.scale_x));
    } else {
        packet.scale_x = 1.0f;
        packet.scale_y = 1.0f;
        x = (640.0f - (128.0f * (0.5f * packet.scale_x))) - 8.0f;
        y = 408.0f;
    }

    w = width;
    h = height;
    dx = (0.5f * w) * packet.scale_x;
    dy = h * packet.scale_y;
    x -= dx;
    y -= dy;
    packet.x = x;
    packet.y = y;
    packet.z += 0.02f;
    packet.flags |= 0x800000;
    packet.format = format;
    packet.width = width;
    packet.height = height;
    packet.pixels = (void *)texture;
    *(u32 *)packet.color = fn_1_7926C_color[0];

    if (lbl_1_bss_6D778.unk_0->unk_18 > 1) {
        fn_1_51914(&packet2);
        fn_1_51990(&packet);
    }
    fn_1_4F734(&packet);

    idx = lbl_1_data_1DFA4.unk_8;
    idx = ((u32)idx < 46) ? idx : 0;
    entry = &((fn_1_7926C_Entry *)&lbl_1_data_1DFB0)[idx];
    fn_8006F120(entry->unk_4, entry->unk_10);
    fn_8006F774(width * packet.scale_x, height * packet.scale_y);
    fzgx_live = entry->unk_0;
    fn_1_D07E0(fzgx_live, x, y);
    fn_8006F774(640.0f, 480.0f);
}
/* fzgx:end fn_1_7926C */

/* fzgx:begin fn_1_79654 */
typedef struct {
    u8 pad[0x30];
    f32 mtx[3][4];
} Cam_801A6D00;

extern Cam_801A6D00 *lbl_801A6D00[];
extern s8 camera_get_state(void);
extern u8 fn_1_5348(void);
extern u32 fn_1_58C4(void);
extern void fn_1_550A8(void);
extern void fn_1_7926C(s32);
extern void fn_1_550E0(void);
extern void lbl_8006DD14(void *, void *);
extern void fn_80038F10(f32 *);
extern void GXGetScissor(u32 *, u32 *, u32 *, u32 *);
extern void GXGetProjectionv(f32 *);
extern void fn_80072270(f32 *);
extern void fn_80074188(u32, u32, u32, u32);
extern void fn_80038EEC(f32, f32, f32, f32, f32, f32);

void fn_1_79654(void) {
    f32 mtx[3][4];
    f32 proj[6];
    f32 vp[7];
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    u8 mode;
    u32 i;
    s8 state;
    struct { s32 value; } flag;

    if ((lbl_1_bss_960 == 2 || lbl_1_bss_960 == 9) && lbl_1_bss_6D778.unk_0 != 0) {
        mode = 0;
        state = camera_get_state();
        if (state == 0) {
            if ((((u32 *)&lbl_1_data_3D544)[0] >> 23) & 1) {
                mode = 1;
            }
        } else if (state == 7 || (state == 6 && fn_1_5348() == 4)) {
            for (i = 0; i < fn_1_58C4(); i++) {
                if ((((u32 *)&lbl_1_data_3D544)[i] >> 23) & 1) {
                    mode = fn_1_58C4();
                }
            }
        }
        if (mode == 1 || (u8)(mode - 3) <= 1) {
            lbl_8006DD14(lbl_801A6D00[0]->mtx, mtx);
            fn_80038F10(proj);
            GXGetScissor(&a, &b, &c, &d);
            GXGetProjectionv(vp);
            fn_1_550A8();
            flag.value = 1;
            if (!((u8)(mode - 3) <= 1)) {
                flag.value = 0;
            }
            fn_1_7926C(flag.value);
            fn_1_550E0();
            fn_80072270(vp);
            fn_80074188(a, b, c, d);
            fn_80038EEC(proj[0], proj[1], proj[2], proj[3], proj[4], proj[5]);
            lbl_8006DD14(mtx, lbl_801A6D00[0]->mtx);
        }
    }
}
/* fzgx:end fn_1_79654 */

/* fzgx:begin fn_1_79810 */
typedef struct {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    s16 unk_C;
    s16 unk_E;
    s16 unk_10;
    u8 pad_12[0x6];
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    u8 pad_24[0xd0];
    void *unk_F4;
    u8 pad_F8[0xc];
    u32 unk_104;
} ScreenEffectSource;

extern void fn_80008BEC(void *arg0, s32 arg1, u32 arg2);
extern void lbl_8006D758(void);
extern void lbl_8006DB74(void *arg);
extern void lbl_8006E0C8(void *arg);

void fn_1_79810(void) {
    u32 source_flags;
    Obj_1_bss_3BE4 *dst;
    ScreenEffectSource *src;
    s32 i;

    i = 0;
    dst = *(Obj_1_bss_3BE4 **)&lbl_1_bss_3BE4;
    src = (ScreenEffectSource *)lbl_1_bss_3BE0->unk_1C;
    while (i < (s32)lbl_1_bss_3BE0->unk_18) {
        source_flags = dst->unk_9C;
        fn_80008BEC(dst, 0, 0xa0);
        dst->unk_9C = source_flags;
        dst->unk_8 = src->unk_0;
        dst->unk_C = src->unk_4;
        dst->unk_10 = src->unk_8;
        dst->unk_14 = src->unk_0 - src->unk_18;
        dst->unk_18 = src->unk_4 - src->unk_1C;
        dst->unk_1C = src->unk_8 - src->unk_20;
        dst->unk_20 = src->unk_C;
        dst->unk_22 = src->unk_E;
        dst->unk_24 = src->unk_10;
        dst->unk_26 = src->unk_C;
        dst->unk_28 = src->unk_E;
        dst->unk_2A = src->unk_10;
        lbl_8006D758();
        lbl_8006DB74((u8 *)dst + 0x2c);
        lbl_8006E0C8((u8 *)src + 0x18);
        lbl_8006DB74((u8 *)dst + 0x5c);
        if (src->unk_F4 != 0) {
            dst->unk_98 = *(f32 *)((u8 *)src->unk_F4 + 0xc);
        }
        source_flags = src->unk_104;
        dst->unk_0 |= source_flags;
        i++;
        src = (ScreenEffectSource *)((u8 *)src + 0x4b0);
        dst = (Obj_1_bss_3BE4 *)((u8 *)dst + 0xa0);
    }
}
/* fzgx:end fn_1_79810 */

/* fzgx:begin fn_1_79948 */
extern u32 lbl_1_bss_6C8DC[2];
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, void *arg2, u32 arg3);
extern void fn_1_727BC(u32 arg0, u32 arg1, void *arg2);
extern void fn_1_76A94(void *arg0, u32 arg1);
extern void fn_1_76DBC(void);
extern void fn_1_4E500(void);
extern void fn_1_4E638(int);
extern void fn_1_4E6F4(void);
extern void fn_80073778(void *arg0, int arg1);
extern s32 fn_1_A5D9C(void);
extern const f32 lbl_1_rodata_31AC;
extern u32 fn_80008E84(u32 arg);
extern void fn_1_77238(void);
extern void fn_1_772E0(void);
extern void fn_1_77384(void *arg);
extern void fn_80072864(int arg0);
extern void fn_800745A4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
extern void fn_80074660(int arg0);
extern void fn_80073678(int arg0);
extern void fn_80073898(int arg0);
extern void fn_80074788(int arg0);
extern void fn_800738E0(int arg0, int arg1, int arg2);
extern void fn_80073D60(int arg0, int arg1, int arg2, int arg3, int arg4);
extern void fn_800734A8(int arg0, int arg1, int arg2, int arg3);
extern void fn_80072EDC(int arg0, int arg1);
extern f32 lbl_1_rodata_31B0[10];
extern const f64 lbl_1_rodata_31A0;
extern void lbl_8006D784(f32 *arg);
extern void fn_80073A58(int arg0, f32 *arg1, int arg2);
extern void fn_800739E0(int arg0, int arg1, int arg2);
extern void GXLoadTexMtxImm(f32 *arg0, int arg1, int arg2);
extern void fn_8006FDEC(void);
extern void fn_8006FEFC(void);
extern void fn_8006FD1C(void);
extern void fn_1_79810(void);
extern void fn_1_79948(void);
extern void fn_1_791B0(void);
extern void fn_1_9A1E8(void);
extern void fn_1_9A864(void);
extern u8 fn_1_7B074(void);
extern void fn_80071718(void *arg);
extern void fn_800711A8(void *arg);
extern void fn_1_14CB4(void);
extern void fn_1_FA84(void);
extern const f32 lbl_1_rodata_32CC;
extern void fn_1_79C88(void *arg0, s32 arg1, f32 arg2, s32 arg3);
extern void lbl_8006DBAC(void *arg0);
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern void sprintf(char *dst, const char *format, ...);
extern void fn_1_465D0(char *text, int arg);
extern void fn_1_14D5C(void *object, int arg);
extern void fn_1_46EA8(int value);
extern void fn_1_12620(void *object);
extern void fn_1_46DC4(void *obj);

extern void fn_1_727BC();
extern void fn_8006FDEC(void);
extern void fn_80071718(void *);
extern void fn_800711A8(void *);
extern u32 fn_8003526C(u32, u32);
extern u32 fn_80074300(u32, u32, u32, u32);
extern u32 fn_80074438(u32, u32, u32, u32);

extern u32 lbl_1_bss_6C8DC[2];
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, void *arg2, u32 arg3);
extern void fn_1_727BC(u32 arg0, u32 arg1, void *arg2);
extern void fn_1_76A94(void *arg0, u32 arg1);
extern void fn_1_76DBC(void);
extern void fn_1_4E500(void);
extern void fn_1_4E638(int);
extern void fn_1_4E6F4(void);
extern void fn_80073778(void *arg0, int arg1);
extern s32 fn_1_A5D9C(void);
extern const f32 lbl_1_rodata_31AC;
extern u32 fn_80008E84(u32 arg);
extern void fn_1_77238(void);
extern void fn_1_772E0(void);
extern void fn_1_77384(void *arg);
extern void fn_80072864(int arg0);
extern void fn_800745A4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
extern void fn_80074660(int arg0);
extern void fn_80073678(int arg0);
extern void fn_80073898(int arg0);
extern void fn_80074788(int arg0);
extern void fn_800738E0(int arg0, int arg1, int arg2);
extern void fn_80073D60(int arg0, int arg1, int arg2, int arg3, int arg4);
extern void fn_800734A8(int arg0, int arg1, int arg2, int arg3);
extern void fn_80072EDC(int arg0, int arg1);
extern f32 lbl_1_rodata_31B0[10];
extern const f64 lbl_1_rodata_31A0;
extern void lbl_8006D784(f32 *arg);
extern void fn_80073A58(int arg0, f32 *arg1, int arg2);
extern void fn_800739E0(int arg0, int arg1, int arg2);
extern void GXLoadTexMtxImm(f32 *arg0, int arg1, int arg2);
extern void fn_8006FDEC(void);
extern void fn_8006FEFC(void);
extern void fn_8006FD1C(void);
extern void fn_1_79810(void);
extern void fn_1_79948(void);
extern void fn_1_791B0(void);
extern void fn_1_9A1E8(void);
extern void fn_1_9A864(void);
extern u8 fn_1_7B074(void);
extern void fn_80071718(void *arg);
extern void fn_800711A8(void *arg);
extern void fn_1_14CB4(void);
extern void fn_1_FA84(void);
extern const f32 lbl_1_rodata_32CC;
extern void fn_1_79C88(void *arg0, s32 arg1, f32 arg2, s32 arg3);
extern void lbl_8006DBAC(void *arg0);
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern void sprintf(char *dst, const char *format, ...);
extern void fn_1_465D0(char *text, int arg);
extern void fn_1_14D5C(void *object, int arg);
extern void fn_1_46EA8(int value);
extern void fn_1_12620(void *object);
extern void fn_1_46DC4(void *obj);

extern void fn_1_727BC();
extern void fn_8006FDEC(void);
extern void fn_80071718(void *);
extern void fn_800711A8(void *);
extern u32 fn_8003526C(u32, u32);
extern u32 fn_80074300(u32, u32, u32, u32);
extern u32 fn_80074438(u32, u32, u32, u32);


typedef struct ScreenFx {
    s8 type;
    u8 pad_1[3];
    f32 unk_4;
    f32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    u8 active;
    u32 unk_10;
    void *unk_14;
} ScreenFx;

typedef struct ScreenFxEntry {
    s8 key;
    s8 type;
    u8 pad_2[2];
    f32 unk_4;
    f32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    u8 pad_F;
} ScreenFxEntry;

extern u32 fn_1_7AA50(f32);
extern void fn_1_7E8F4(void);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
Obj_1_bss_6D600 lbl_1_bss_6D600;
ScreenFx lbl_1_bss_6D620[4];
ScreenFx lbl_1_bss_6D620__fzgx_offset_60[4];
ScreenFx lbl_1_bss_6D620__fzgx_offset_C0[4];
ScreenFx lbl_1_bss_6D620__fzgx_offset_120;
ScreenFx lbl_1_bss_6D758;

const ScreenFxEntry lbl_1_rodata_3278[5] = {
    { 4, 5, { 0, 0 }, -200.0f, 1000.0f, 0x00, 0x6E, 0x96, 0 },
    { 8, 5, { 0, 0 }, -200.0f, 2000.0f, 0x0A, 0x0A, 0x28, 0 },
    { 7, 4, { 0, 0 }, 0.0f, 3000.0f, 0x17, 0x1A, 0x1D, 0 },
    { 12, 2, { 0, 0 }, 0.0f, 820.0f, 0x6E, 0x78, 0x79, 0 },
    { -1, 4, { 0, 0 }, 0.0f, 100.0f, 0, 0, 0, 0 },
};

#pragma section code_type ".fzgxpool"
static void fn_1_79948_fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_1_bss_6D600;
    s = *(u8 *)&lbl_1_bss_6D620;
    s = *(u8 *)&lbl_1_bss_6D620__fzgx_offset_60;
    s = *(u8 *)&lbl_1_bss_6D620__fzgx_offset_C0;
    s = *(u8 *)&lbl_1_bss_6D620__fzgx_offset_120;
    s = *(u8 *)&lbl_1_bss_6D758;
}

extern void fzgx_pool_sink_p(const void *);
extern void fzgx_pool_sink_f(f32);
extern void fzgx_pool_sink_d(f64);
static const f32 fzgx_pool_word_50[1] = { 0.03125f };
static const f32 fzgx_pool_word_54[1] = { 1.0f };
static const f64 fzgx_pool_dword_58[1] = { 4503601774854144.0 };
static const f64 fzgx_pool_dword_60[1] = { 4503599627370496.0 };
static const f32 fzgx_pool_word_68[1] = { 0.016666668f };
static const u32 fzgx_pool_word_6C[1] = { 0xFFFFFFFF };

/* primes the TU literal pool in retail order behind the table */
static void fzgx_pool_primer(void) {
    fzgx_pool_sink_p(lbl_1_rodata_3278);
    fzgx_pool_sink_p(fzgx_pool_word_50);
    fzgx_pool_sink_p(fzgx_pool_word_54);
    fzgx_pool_sink_p(fzgx_pool_dword_58);
    fzgx_pool_sink_p(fzgx_pool_dword_60);
    fzgx_pool_sink_p(fzgx_pool_word_68);
    fzgx_pool_sink_p(fzgx_pool_word_6C);
    fzgx_pool_sink_f(0.0f);
    fzgx_pool_sink_f(640.0f);
    fzgx_pool_sink_f(480.0f);
    fzgx_pool_sink_f(320.0f);
    fzgx_pool_sink_f(240.0f);
    fzgx_pool_sink_f(0.03f);
    fzgx_pool_sink_f(0.75f);
    fzgx_pool_sink_f(0.02f);
    fzgx_pool_sink_f(1.5f);
    fzgx_pool_sink_f(360.0f);
    fzgx_pool_sink_f(128.0f);
    fzgx_pool_sink_f(0.5f);
    fzgx_pool_sink_f(8.0f);
    fzgx_pool_sink_f(408.0f);
    fzgx_pool_sink_f(100.0f);
}
#pragma section code_type ".text"

static inline void fx_reset(ScreenFx *e) {
    e->active = 0;
    e->type = 5;
    e->unk_4 = 0.0f;
    e->unk_8 = 100.0f;
    e->unk_C = 0;
    e->unk_D = 0;
    e->unk_E = 0;
}

static inline void fx_lookup(ScreenFx *e, s32 key) {
    const ScreenFxEntry *ent;

    fx_reset(e);
    for (ent = lbl_1_rodata_3278; ent->key != -1; ent++) {
        if (ent->key == lbl_1_data_2A7E0.unk_0) {
            e->active = 1;
            e->type = ent->type;
            e->unk_4 = ent->unk_4;
            e->unk_8 = ent->unk_8;
            e->unk_C = ent->unk_C;
            e->unk_D = ent->unk_D;
            e->unk_E = ent->unk_E;
        }
    }
}


void fn_1_79948(void) {
    ScreenFx *e;
    const ScreenFxEntry *ent;
    s32 i;

    if (lbl_1_bss_3BE0 != NULL && lbl_1_bss_3BE0->unk_80 != 0) {
        lbl_1_bss_6D758.active = 1;
        lbl_1_bss_6D758.type = lbl_1_bss_3BE0->unk_84 != 0 ? *(s8 *)lbl_1_bss_3BE0->unk_84 : 4;
        fn_1_7AA50(0.0f);
    } else {
        fx_reset(&lbl_1_bss_6D758);
    }

    e = &lbl_1_bss_6D620__fzgx_offset_120;
    fx_reset(e);
    for (ent = lbl_1_rodata_3278; ent->key != -1; ent++) {
        if (ent->key == lbl_1_data_2A7E0.unk_0) {
            e->active = 1;
            lbl_1_bss_6D620__fzgx_offset_120.type = ent->type;
            e->unk_4 = ent->unk_4;
            e->unk_8 = ent->unk_8;
            e->unk_C = ent->unk_C;
            e->unk_D = ent->unk_D;
            e->unk_E = ent->unk_E;
        }
    }

    for (i = 0; i < 4; i++) {
        lbl_1_bss_6D620[i] = lbl_1_bss_6D758;
        lbl_1_bss_6D620[i].unk_14 = &lbl_1_bss_6D758;
        lbl_1_bss_6D620[i].unk_10 = 0x20;
        lbl_1_bss_6D620__fzgx_offset_60[i] = lbl_1_bss_6D620[i];
        lbl_1_bss_6D620__fzgx_offset_C0[i] = lbl_1_bss_6D620[i];
    }
    fn_1_7E8F4();
}
/* fzgx:end fn_1_79948 */

/* fzgx:begin fn_1_79C88 noprologue */
#include "types.h"

typedef struct {
    u32 flags;
    s32 count;
    void *nodes;
} EffectManager;

typedef struct {
    u32 type;
    u32 unk04;
    void *resource;
    f32 threshold;
} EffectNode;

typedef struct {
    u8 unk00[0x14];
    f32 scale;
} EffectData;

typedef struct {
    u8 unk00[0x8];
    f32 angle;
} EffectResult;

typedef struct {
    u8 unk00[0x2c];
    f32 value;
} GlobalData;

extern f32 lbl_1_rodata_3278[20];
extern GlobalData *lbl_801A6D00;
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern f32 fn_1_A71AC(void);

static inline f32 fn_1_79C88_operand(f32 left, f32 right) { return left * right; }
s32 fn_1_79C88(EffectManager *manager, u32 *out, s32 reverse, f32 value) {
    void * fzgx_live;
    EffectData *data;
    f32 *rodata = lbl_1_rodata_3278;
    EffectNode *node;
    EffectResult result;
    f32 phase;
    f32 limit;
    f32 inv;
    f32 factor;
    f32 tmp;
    s32 index;
    s32 i;

    node = (EffectNode *)manager->nodes;
    data = (EffectData *)node->resource;
    if (((0) == data)) {
        return 0;
    }

    lbl_8006E1B0((u8 *)data + 8, &result);
    phase = -result.angle;
    limit = -lbl_801A6D00->value;
    if ((manager->flags & 2) != 0) {
        if (limit < rodata[43]) {
            index = 0;
        } else {
            index = 0;
            while (index < manager->count) {
                if (limit < node->threshold) {
                    break;
                }
                index++;
                node++;
            }
        }
    } else {
        if (phase < rodata[43]) {
            index = 0;
        } else {
            tmp = rodata[44] * data->scale;
            value = tmp * value;
            factor = phase * fn_1_A71AC();
            inv = rodata[32];
            index = 0;
            while (index < manager->count) {
                if (value > fn_1_79C88_operand((node->threshold / inv), factor)) {
                    break;
                }
                index++;
                node++;
            }
        }
    }

    if (node->resource != 0 && index < manager->count) {
        if (reverse != 0) {
            for (i = index; i < manager->count; i++) {
                if (node->resource == 0) {
                    break;
                }
                node++;
            }
            node--;
        }
        if (out != 0) {
            *out = node->type;
        }
        fzgx_live = node->resource;
        return (s32)fzgx_live;
    }
    if (out != 0) {
        *out = 0;
    }
    return 0;
}
/* fzgx:end fn_1_79C88 */

/* fzgx:begin fn_1_79E54 */
typedef signed long s32;


typedef unsigned char u8;


typedef unsigned long u32;


typedef float f32;


typedef struct {
f32 x;
f32 y;
f32 z;
} Fn183D28Vec3;






typedef struct {
u32 id;
u32 unk_4;
void *unk_8;
f32 time;
} EffectEntry;
typedef struct {
u32 flags;
s32 count;
void *entries;
} Sig_fn_1_7A67C_EffectTable;
typedef struct {
u8 pad_0[0x8];
u8 unk_8[0xC];
f32 unk_14;
} EffectObj;
typedef struct {
u8 pad_0[0x8];
EffectObj *obj;
} EffectHolder;
typedef struct {
u8 pad_0[0x2C];
f32 unk_2C;
} CameraLike;
struct fn_1_7A240_lbl_1_rodata_3278 {
u8 pad_0[0x54];
f32 unk_54;
u8 pad_58[0x18];
f32 unk_70;
u8 pad_74[0xC];
f32 unk_80;
u8 pad_84[0x28];
f32 unk_AC;
f32 unk_B0;
};
extern f32 fn_1_A71AC(void);
extern struct fn_1_7A240_lbl_1_rodata_3278 lbl_1_rodata_3278;
extern CameraLike *lbl_801A6D00;
extern void *fn_1_7A67C(Sig_fn_1_7A67C_EffectTable *);
static inline f32 fn_1_79E54_effect_clamp_final(f32 low, f32 high, f32 value)
{
if (value < low) {
return low;
} else {
return value > high ? high : value;
}
}
void *fn_1_79E54(Sig_fn_1_7A67C_EffectTable *arg0, u32 *outId, f32 *outF,
s32 advance, f32 scale)
{
s32 n31;
s32 n30;
struct fn_1_7A240_lbl_1_rodata_3278 *c;
Sig_fn_1_7A67C_EffectTable *tbl;
EffectObj *obj;
EffectEntry *e;
s32 i;
s32 has1;
s32 has40;
s32 count;
f32 result;
f32 depth;
f32 dist;
f32 blend;
f32 factor;
f32 t;
f32 k;
f32 prevTime;
EffectEntry *p;
Fn183D28Vec3 pos;
blend = scale;
c = &lbl_1_rodata_3278;
*outF = c->unk_54;
e = (EffectEntry *)arg0->entries;
obj = (EffectObj *)e->unk_8;
if (obj == ((void *)0) ) {
return ((void *)0) ;
}
tbl = arg0;
count = tbl->count;
has40 = tbl->flags & 0x40;
has1 = tbl->flags & 1;
n30 = has40 ? count - 2 : count;
n31 = has1 ? n30 - 1 : n30;
if (tbl->flags & 0x80) {
result = c->unk_70;
} else {
result = lbl_1_data_4;
}
lbl_8006E1B0((Fn183D28Vec3 *)obj->unk_8, &pos);
depth = -pos.z;
dist = -lbl_801A6D00->unk_2C;
if (tbl->flags & 2) {
if (dist < c->unk_AC) {
i = 0;
} else {
for (i = 0; i < tbl->count; i++, e++) {
if (dist < e->time) {
if (has1) {
result = dist;
p = (EffectEntry *)tbl->entries + n30 - 1;
prevTime = p[-1].time;
t = (dist - prevTime) / (p->time - prevTime);
*outF = ((t) < c->unk_70 ? c->unk_70 : ((t) > c->unk_54 ? c->unk_54 : (t))) ;
}
if (has40) {
if (!(tbl->flags & 0x80)) {
factor = c->unk_B0 * obj->unk_14;
blend = factor * blend;
result = c->unk_80 * blend / (depth * fn_1_A71AC());
} else if (!has1) {
result = dist;
}
}
break;
}
}
}
} else {
if (depth < c->unk_AC) {
i = 0;
} else {
f32 factorB = c->unk_B0 * obj->unk_14;
blend = factorB * blend;
k = depth * fn_1_A71AC();
for (i = 0; i < n31; i++, e++) {
t = e->time / c->unk_80;
if (blend > t * k) {
if (has1) {
result = c->unk_80 * blend / k;
p = (EffectEntry *)tbl->entries + n30 - 1;
prevTime = p[-1].time;
t = (result - prevTime) / (p->time - prevTime);
*outF = ((t) < c->unk_70 ? c->unk_70 : ((t) > c->unk_54 ? c->unk_54 : (t))) ;
}
if (has40) {
if (tbl->flags & 0x80) {
result = dist;
} else if (!has1) {
result = c->unk_80 * blend / k;
}
}
break;
}
}
}
}
if (e->unk_8 != ((void *)0) && i < n31) {
if (advance && i != n31 - 1) {
    s32 j;
    for (j = i; j < n31 - 1; j++) {
        e++;
        if (!e->unk_8) {
            e--;
            break;
        }
    }
}
if (has40) {
struct { f32 low; f32 high; } bounds;
f32 endTime;
if (*outF >= (bounds.high = c->unk_54)) {
p = (EffectEntry *)tbl->entries + count - 1;
endTime = p->time;
t = (endTime - result) / (endTime - p[-1].time);
bounds.low = c->unk_70;
*outF = fn_1_79E54_effect_clamp_final(bounds.low, bounds.high, t);
}
}
if (*outF > c->unk_70) {
if (outId != ((void *)0) ) {
*outId = e->id;
}
return e->unk_8;
}
}
if (outId != ((void *)0) ) {
*outId = 0;
}
return ((void *)0) ;
}
/* fzgx:end fn_1_79E54 */

/* fzgx:begin fn_1_7A240 */
typedef signed long s32;


typedef unsigned char u8;


typedef unsigned long u32;


typedef float f32;


typedef struct {
f32 x;
f32 y;
f32 z;
} Fn183D28Vec3;






typedef struct {
u32 id;
u32 unk_4;
void *unk_8;
f32 time;
} EffectEntry;
typedef struct {
u32 flags;
s32 count;
void *entries;
} Sig_fn_1_7A67C_EffectTable;
typedef struct {
u8 pad_0[0x8];
u8 unk_8[0xC];
f32 unk_14;
} EffectObj;
typedef struct {
u8 pad_0[0x8];
EffectObj *obj;
} EffectHolder;
typedef struct {
u8 pad_0[0x2C];
f32 unk_2C;
} CameraLike;
struct fn_1_7A240_lbl_1_rodata_3278 {
u8 pad_0[0x54];
f32 unk_54;
u8 pad_58[0x18];
f32 unk_70;
u8 pad_74[0xC];
f32 unk_80;
u8 pad_84[0x28];
f32 unk_AC;
f32 unk_B0;
};
extern f32 fn_1_A71AC(void);
extern struct fn_1_7A240_lbl_1_rodata_3278 lbl_1_rodata_3278;
extern CameraLike *lbl_801A6D00;
extern void *fn_1_7A67C(Sig_fn_1_7A67C_EffectTable *);
static inline f32 fn_1_7A240_effect_clamp_final(f32 low, f32 high, f32 value)
{
if (value < low) {
return low;
} else {
return value > high ? high : value;
}
}
void *fn_1_7A240(Sig_fn_1_7A67C_EffectTable *arg0, u32 *outId, f32 *outF,
Sig_fn_1_7A67C_EffectTable *arg3, f32 scale)
{
s32 n31;
s32 n30;
struct fn_1_7A240_lbl_1_rodata_3278 *c;
Sig_fn_1_7A67C_EffectTable *tbl;
EffectObj *obj;
EffectEntry *e;
s32 i;
s32 has1;
s32 has40;
s32 count;
f32 result;
f32 depth;
f32 dist;
f32 factor;
f32 t;
f32 k;
f32 prevTime;
EffectEntry *p;
Fn183D28Vec3 pos;
c = &lbl_1_rodata_3278;
*outF = c->unk_54;
obj = ((EffectHolder *)arg0->entries)->obj;
if (obj == ((void *)0) ) {
return ((void *)0) ;
}
if (arg3 != ((void *)0) ) {
tbl = arg3;
} else {
tbl = arg0;
}
count = tbl->count;
has40 = tbl->flags & 0x40;
e = (EffectEntry *)tbl->entries;
has1 = tbl->flags & 1;
n30 = has40 ? count - 2 : count;
n31 = has1 ? n30 - 1 : n30;
if (tbl->flags & 0x80) {
result = c->unk_70;
} else {
result = lbl_1_data_4;
}
lbl_8006E1B0((Fn183D28Vec3 *)obj->unk_8, &pos);
depth = -pos.z;
if (arg0->flags & 2) {
dist = -lbl_801A6D00->unk_2C;
} else {
dist = depth;
}
if (arg3 != ((void *)0) ) {
dist -= obj->unk_14;
}
if (tbl->flags & 2) {
if (dist < c->unk_AC) {
i = 0;
} else {
for (i = 0; i < tbl->count; i++, e++) {
if (dist < e->time) {
if (has1) {
result = dist;
p = (EffectEntry *)tbl->entries + n30 - 1;
prevTime = p[-1].time;
t = (dist - prevTime) / (p->time - prevTime);
*outF = ((t) < c->unk_70 ? c->unk_70 : ((t) > c->unk_54 ? c->unk_54 : (t))) ;
}
if (has40) {
if (!(tbl->flags & 0x80)) {
factor = c->unk_B0 * obj->unk_14;
scale = factor * scale;
result = c->unk_80 * scale / (depth * fn_1_A71AC());
} else if (!has1) {
result = dist;
}
}
break;
}
}
}
} else {
if (depth < c->unk_AC) {
i = 0;
} else {
f32 factorB = c->unk_B0 * obj->unk_14;
f32 scaled = factorB * scale;
k = depth * fn_1_A71AC();
for (i = 0; i < n31; i++, e++) {
t = e->time / c->unk_80;
if (scaled > t * k) {
if (has1) {
result = c->unk_80 * scaled / k;
p = (EffectEntry *)tbl->entries + n30 - 1;
prevTime = p[-1].time;
t = (result - prevTime) / (p->time - prevTime);
*outF = ((t) < c->unk_70 ? c->unk_70 : ((t) > c->unk_54 ? c->unk_54 : (t))) ;
}
if (has40) {
if (tbl->flags & 0x80) {
result = dist;
} else if (!has1) {
result = c->unk_80 * scaled / k;
}
}
break;
}
}
}
}
if (e->unk_8 != ((void *)0) && i < n31) {
if (arg3 != ((void *)0) ) {
obj = fn_1_7A67C(arg0);
}
if (has40) {
struct { f32 low; f32 high; } bounds;
f32 endTime;
if (*outF >= (bounds.high = c->unk_54)) {
p = (EffectEntry *)tbl->entries + count - 1;
endTime = p->time;
t = (endTime - result) / (endTime - p[-1].time);
bounds.low = c->unk_70;
*outF = fn_1_7A240_effect_clamp_final(bounds.low, bounds.high, t);
}
}
if (*outF > c->unk_70 && obj != ((void *)0) ) {
if (outId != ((void *)0) ) {
*outId = e->id;
}
return obj;
}
}
if (outId != ((void *)0) ) {
*outId = 0;
}
return ((void *)0) ;
}
/* fzgx:end fn_1_7A240 */

/* fzgx:begin fn_1_7A648 */
void fn_1_7A648(void *arg0) {
    fn_1_79C88(arg0, 0, lbl_1_rodata_32CC, 0);
}
/* fzgx:end fn_1_7A648 */

/* fzgx:begin fn_1_7A67C */
typedef struct {
    u32 flags;
    s32 count;
    void *entries;
} EffectTable;

typedef struct {
    u8 unk00[0x8];
    void *value;
    u32 unk0c;
} EffectEntry;

void *fn_1_7A67C(EffectTable *table) {
    s32 index;
    EffectEntry *entry;

    index = table->count - 1;
    if ((table->flags & 1) != 0) {
        index--;
    }
    if ((table->flags & 0x40) != 0) {
        index -= 2;
    }
    entry = (EffectEntry *)table->entries;
    entry += index;
    return entry->value;
}
/* fzgx:end fn_1_7A67C */

/* fzgx:begin fn_1_7A6B4 */
#include "fpscr.h"

typedef struct fn_1_7A6B4_Curve {
    void *keys;
    u32 count;
} fn_1_7A6B4_Curve;

typedef struct fn_1_7A6B4_Anim {
    fn_1_7A6B4_Curve rot[3];
    fn_1_7A6B4_Curve pos[3];
} fn_1_7A6B4_Anim;

typedef struct fn_1_7A6B4_Source {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    s16 rot_x;
    s16 rot_y;
    s16 rot_z;
    u16 flags;
    fn_1_7A6B4_Anim *anim;
    f32 base_x;
    f32 base_y;
    f32 base_z;
    u8 pad_24[0xE4];
    f32 start;
    f32 end;
    u8 pad_110[0x3A0];
} fn_1_7A6B4_Source;

extern const f32 lbl_1_rodata_332C;
extern const f32 lbl_1_rodata_3330;
extern f32 fn_1_9E14C(void *, u32, f32);
extern void lbl_8006D7DC(void *);
extern void lbl_8006E0C8(void *);
extern void lbl_8006DB74(void *);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_z(s16);

void fn_1_7A6B4(void) {
    Obj_1_bss_3BE0_Target **manager;
    Obj_1_bss_3BE4 *dst;
    fn_1_7A6B4_Source *src;
    s32 i;
    fn_1_7A6B4_Anim *anim;
    f32 t;
    f32 len;


    manager = &lbl_1_bss_3BE0;
    dst = (Obj_1_bss_3BE4 *)lbl_1_bss_3BE4.unk_0;
    i = 0;
    src = (fn_1_7A6B4_Source *)(*manager)->unk_1C;
    while (i < (s32)(*manager)->unk_18) {
        anim = src->anim;
        if (anim != 0) {
            t = lbl_1_data_1DFA4.unk_0;
            if (!(src->flags & 1)) {
                len = src->end - src->start;
                t -= (len * fpscr_floor(t / len));
                t += src->start;
            }
            t /= lbl_1_rodata_332C;
            if (anim->rot[0].count != 0) {
                dst->unk_26 = dst->unk_20;
                dst->unk_20 = lbl_1_rodata_3330 * fn_1_9E14C(anim->rot[0].keys, anim->rot[0].count, t);
            }
            if (anim->rot[1].count != 0) {
                dst->unk_28 = dst->unk_22;
                dst->unk_22 = lbl_1_rodata_3330 * fn_1_9E14C(anim->rot[1].keys, anim->rot[1].count, t);
            }
            if (anim->rot[2].count != 0) {
                dst->unk_2A = dst->unk_24;
                dst->unk_24 = lbl_1_rodata_3330 * fn_1_9E14C(anim->rot[2].keys, anim->rot[2].count, t);
            }
            if (anim->pos[0].count != 0) {
                dst->unk_14 = dst->unk_8 - src->base_x;
                dst->unk_8 = fn_1_9E14C(anim->pos[0].keys, anim->pos[0].count, t);
            }
            if (anim->pos[1].count != 0) {
                dst->unk_18 = dst->unk_C - src->base_y;
                dst->unk_C = fn_1_9E14C(anim->pos[1].keys, anim->pos[1].count, t);
            }
            if (anim->pos[2].count != 0) {
                dst->unk_1C = dst->unk_10 - src->base_z;
                dst->unk_10 = fn_1_9E14C(anim->pos[2].keys, anim->pos[2].count, t);
            }
            lbl_8006D7DC(&dst->unk_8);
            mathutil_mtxA_rotate_z(dst->unk_24);
            mathutil_mtxA_rotate_y(dst->unk_22);
            mathutil_mtxA_rotate_x(dst->unk_20 - src->rot_x);
            mathutil_mtxA_rotate_y(-src->rot_y);
            mathutil_mtxA_rotate_z(-src->rot_z);
            lbl_8006E0C8(src);
            lbl_8006DB74((u8 *)dst + 0x2c);
            lbl_8006D7DC(&dst->unk_14);
            mathutil_mtxA_rotate_z(dst->unk_2A);
            mathutil_mtxA_rotate_y(dst->unk_28);
            mathutil_mtxA_rotate_x(dst->unk_26 - src->rot_x);
            mathutil_mtxA_rotate_y(-src->rot_y);
            mathutil_mtxA_rotate_z(-src->rot_z);
            lbl_8006E0C8(src);
            lbl_8006DB74((u8 *)dst + 0x5c);
        }
        i++;
        dst++;
        src++;
    }
}
/* fzgx:end fn_1_7A6B4 */

/* fzgx:begin fn_1_7A9B8 */
typedef struct {
    u8 pad_0[0xf4];
    void *resource;
    u8 pad_f8[0x4b0 - 0xf8];
} fn_1_7A9B8_ScreenEffect;

typedef struct {
    u8 pad_0[0x2c];
    u8 reset_data[0x60];
    u8 load_data[0x14];
} fn_1_7A9B8_ScreenEffectEntry;

// Resets the active screen-effect entries and releases each attached resource.
void fn_1_7A9B8(void) {
    fn_1_7A9B8_ScreenEffectEntry *entry;
    fn_1_7A9B8_ScreenEffect *effect;
    s32 i;

    i = 0;
    entry = (fn_1_7A9B8_ScreenEffectEntry *)lbl_1_bss_3BE4.unk_0;
    effect = (fn_1_7A9B8_ScreenEffect *)lbl_1_bss_3BE0->unk_1C;
    while (i < (s32)lbl_1_bss_3BE0->unk_18) {
        if (effect->resource != 0) {
            lbl_8006DBAC(&entry->reset_data);
            lbl_8006E1B0(effect->resource, &entry->load_data);
        }
        i++;
        entry++;
        effect++;
    }
}
/* fzgx:end fn_1_7A9B8 */

/* fzgx:begin fn_1_7AA50 */
#include "fpscr.h"

#pragma section code_type ".fzgxpool"
static const u32 fn_1_7AA50_fzgx_pool_table1[1] = {0x04050000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_7AA50_fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fn_1_7AA50_fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_7AA50_fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -200.0f;
    s = 1000.0f;
}
static const u32 fn_1_7AA50_fzgx_pool_table3[3] = {0x006E9600, 0x08050000, 0xC3480000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_7AA50_fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fn_1_7AA50_fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_7AA50_fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2000.0f;
}
static const u32 fn_1_7AA50_fzgx_pool_table5[3] = {0x0A0A2800, 0x07040000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_7AA50_fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fn_1_7AA50_fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_7AA50_fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3000.0f;
}
static const u32 fn_1_7AA50_fzgx_pool_table7[3] = {0x171A1D00, 0x0C020000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_7AA50_fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fn_1_7AA50_fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_7AA50_fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 820.0f;
}
static const u32 fn_1_7AA50_fzgx_pool_table9[3] = {0x6E787900, 0xFF040000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_7AA50_fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fn_1_7AA50_fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_7AA50_fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
}
static const u32 fn_1_7AA50_fzgx_pool_table11[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_7AA50_fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fn_1_7AA50_fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_7AA50_fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.03125f;
    s = 1.0f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 0.01666666753590107f;
}
static const u32 fn_1_7AA50_fzgx_pool_table13[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_7AA50_fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fn_1_7AA50_fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_7AA50_fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 640.0f;
    s = 480.0f;
    s = 320.0f;
    s = 240.0f;
    s = 0.029999999329447746f;
    s = 0.75f;
    s = 0.019999999552965164f;
    s = 1.5f;
    s = 360.0f;
    s = 128.0f;
    s = 0.5f;
    s = 8.0f;
    s = 408.0f;
}
static const u32 fzgx_pool_table15[1] = {0x42C80000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.1920928955078125e-07f;
    s = 2.0f;
    s = 60.0f;
    s = 182.04444885253906f;
    s = 255.0f;
}
#pragma section code_type ".text"

typedef struct fn_1_7AA50_Key {
    u32 unk_0;
    f32 time;
    u8 pad_8[0xC];
} fn_1_7AA50_Key;

typedef struct fn_1_7AA50_Curve {
    u32 count;
    fn_1_7AA50_Key *keys;
} fn_1_7AA50_Curve;

typedef struct fn_1_7AA50_Fx {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
} fn_1_7AA50_Fx;

extern fn_1_7AA50_Fx lbl_1_bss_6D758;
extern f32 fn_1_9E14C(u32, fn_1_7AA50_Key *, f32);

void fn_1_7AA50(f32 time) {
    fn_1_7AA50_Curve *c;
    f32 hi;
    f32 lo;
    f32 t;
    f32 len;

    c = (fn_1_7AA50_Curve *)lbl_1_bss_3BE0->unk_80;
    lo = lbl_1_data_4;
    hi = 0.0f;
    if (lo > c[0].keys[0].time) {
        lo = c[0].keys[0].time;
    }
    if (hi < c[0].keys[c[0].count - 1].time) {
        hi = c[0].keys[c[0].count - 1].time;
    }
    if (lo > c[1].keys[0].time) {
        lo = c[1].keys[0].time;
    }
    if (hi < c[1].keys[c[1].count - 1].time) {
        hi = c[1].keys[c[1].count - 1].time;
    }
    if (lo > c[2].keys[0].time) {
        lo = c[2].keys[0].time;
    }
    if (hi < c[2].keys[c[2].count - 1].time) {
        hi = c[2].keys[c[2].count - 1].time;
    }
    if (lo > c[3].keys[0].time) {
        lo = c[3].keys[0].time;
    }
    if (hi < c[3].keys[c[3].count - 1].time) {
        hi = c[3].keys[c[3].count - 1].time;
    }
    if (lo > c[4].keys[0].time) {
        lo = c[4].keys[0].time;
    }
    if (hi < c[4].keys[c[4].count - 1].time) {
        hi = c[4].keys[c[4].count - 1].time;
    }
    lo *= 60.0f;
    hi *= 60.0f;
    t = time - lo;
    len = hi - lo;
    t -= (len * fpscr_floor(t / len));
    t += lo;
    t /= 60.0f;
    lbl_1_bss_6D758.unk_4 = fn_1_9E14C(c[0].count, c[0].keys, t);
    lbl_1_bss_6D758.unk_8 = fn_1_9E14C(c[1].count, c[1].keys, t);
    lbl_1_bss_6D758.unk_C = 255.0f * fn_1_9E14C(c[2].count, c[2].keys, t);
    lbl_1_bss_6D758.unk_D = 255.0f * fn_1_9E14C(c[3].count, c[3].keys, t);
    lbl_1_bss_6D758.unk_E = 255.0f * fn_1_9E14C(c[4].count, c[4].keys, t);
}
/* fzgx:end fn_1_7AA50 */

/* fzgx:begin fn_1_7ACDC noprologue */
#include "dolphin/types.h"
#include "types.h"
#include "rel/main_rel/globals.h"

#ifndef REL_MAIN_REL_SCREEN_EFFECT_H
#define REL_MAIN_REL_SCREEN_EFFECT_H


// Generated by `fzgx headers --module main_rel --tu screen_effect.c`: globals of screen_effect.c (referenced by its
// functions or living in its .data block), layouts recovered from every access in the module.

// lbl_1_bss_6C8EC: .bss size 0x860, 10 refs from screen_effect.c
typedef struct {
    u8 pad_0[0xA0];
    u32 unk_A0;  // 1 loads, 0 stores
    u8 pad_A4[0x10];
    u32 unk_B4;  // 1 loads, 0 stores
    u8 pad_B8[0x24];
    u32 unk_DC;  // 9 loads, 1 stores
    u32 unk_E0;  // 3 loads, 1 stores
    u8 pad_E4[0x20];
    u32 unk_104;  // 1 loads, 1 stores
    u8 unk_108;  // 1 loads, 1 stores
    u8 pad_109[0x757];
} Obj_1_bss_6C8EC;
extern Obj_1_bss_6C8EC lbl_1_bss_6C8EC;

// lbl_1_data_1DFA4: .data size 0xC, 10 refs from screen_effect.c (own data block)
typedef struct {
    f32 unk_0;  // 2 loads, 1 stores
    u32 unk_4;  // 2 loads, 2 stores
    s16 unk_8;  // 6 loads, 2 stores
    u8 pad_A[0x2];
} Obj_1_data_1DFA4;
extern Obj_1_data_1DFA4 lbl_1_data_1DFA4;

// lbl_1_data_1D960: .data size 0x58, 9 refs from screen_effect.c
typedef struct {
    u8 pad_0[0x4];
    u32 unk_4;  // 1 loads, 0 stores
    u8 pad_8[0x50];
} Obj_1_data_1D960;
extern Obj_1_data_1D960 lbl_1_data_1D960;

// lbl_1_bss_6D600: .bss size 0x20, 6 refs from screen_effect.c
typedef struct {
    u8 unk_0;  // 1 loads, 0 stores
    u8 unk_1;  // 2 loads, 1 stores
    u8 pad_2[0x1E];
} Obj_1_bss_6D600;
/* Non-owning section view; the original member objects keep their definitions. */
extern u8 lbl_1_bss_6D600[0x1A0];

// lbl_1_data_1DAC0: .data size 0x44, 6 refs from screen_effect.c (own data block)
extern u8 lbl_1_data_1DAC0[0x44];

// lbl_1_data_1DCF0: .data size 0x4, 5 refs from screen_effect.c (own data block)
extern u32 lbl_1_data_1DCF0;

// lbl_1_bss_3BE4: .bss size 0x1C, 5 refs from screen_effect.c
typedef struct {
    u32 unk_0;  // 12 loads, 4 stores
    u8 pad_4[0x4];
    f32 unk_8;  // 1 loads, 3 stores
    f32 unk_C;  // 1 loads, 3 stores
    f32 unk_10;  // 1 loads, 3 stores
    f32 unk_14;  // 0 loads, 3 stores
    f32 unk_18;  // 0 loads, 3 stores
    f32 unk_1C;  // 0 loads, 3 stores
    s16 unk_20;  // 2 loads, 3 stores
    s16 unk_22;  // 2 loads, 3 stores
    s16 unk_24;  // 2 loads, 3 stores
    s16 unk_26;  // 1 loads, 3 stores
    s16 unk_28;  // 1 loads, 3 stores
    s16 unk_2A;  // 1 loads, 3 stores
    u8 pad_2C[0x6C];
    f32 unk_98;  // 0 loads, 2 stores
    u32 unk_9C;  // 2 loads, 2 stores
} Obj_1_bss_3BE4;
extern Obj_1_bss_3BE4 lbl_1_bss_3BE4;

// lbl_1_bss_6D7A8: .bss size 0x18, 5 refs from screen_effect.c
typedef struct {
    u16 unk_0;  // 1 loads, 1 stores
    u16 unk_2;  // 1 loads, 1 stores
    u16 unk_4;  // 1 loads, 1 stores
    u8 pad_6[0x2];
    u32 unk_8;  // 3 loads, 1 stores
    u32 unk_C;  // 3 loads, 1 stores
    u32 unk_10;  // 2 loads, 1 stores
    u16 unk_14;  // 4 loads, 3 stores
    u16 unk_16;  // 5 loads, 4 stores
} Obj_1_bss_6D7A8;
extern Obj_1_bss_6D7A8 lbl_1_bss_6D7A8;

// lbl_1_data_1D9B8: .data size 0x108, 5 refs from screen_effect.c
typedef struct {
    u8 pad_0[0x5];
    u8 unk_5;  // 3 loads, 0 stores
    u8 pad_6[0x102];
} Obj_1_data_1D9B8;
extern Obj_1_data_1D9B8 lbl_1_data_1D9B8;

// lbl_1_bss_6D14C: .bss size 0x5C, 5 refs from screen_effect.c
typedef struct {
    u8 unk_0;  // 2 loads, 3 stores
    u8 pad_1[0x5B];
} Obj_1_bss_6D14C;
extern Obj_1_bss_6D14C lbl_1_bss_6D14C;

// lbl_1_bss_6D774: .bss size 0x4, 4 refs from screen_effect.c
extern u32 lbl_1_bss_6D774;

// lbl_1_data_4: .data size 0x4, 3 refs from screen_effect.c
extern f32 lbl_1_data_4;

// lbl_1_bss_6D778: .bss size 0x30, 3 refs from screen_effect.c
typedef struct {
    u8 pad_0[0x18];
    u16 unk_18;  // 2 loads, 0 stores
    u8 pad_1A[0xA];
    u32 unk_24;  // 2 loads, 0 stores
} Obj_1_bss_6D778_At0;
typedef struct {
    Obj_1_bss_6D778_At0 *unk_0;  // 4 loads, 2 stores
    u8 pad_4[0x2C];
} Obj_1_bss_6D778;
extern Obj_1_bss_6D778 lbl_1_bss_6D778;

// lbl_1_bss_6C8D8: .bss size 0x4, 3 refs from screen_effect.c
extern u32 lbl_1_bss_6C8D8;

// lbl_1_bss_6C8E4: .bss size 0x4, 2 refs from screen_effect.c
extern u32 lbl_1_bss_6C8E4;

// lbl_1_bss_6C8E8: .bss size 0x4, 2 refs from screen_effect.c
extern u32 lbl_1_bss_6C8E8;

// lbl_1_data_1E558: .data size 0x34, 2 refs from screen_effect.c (own data block)
extern u8 lbl_1_data_1E558[0x34];

// lbl_1_data_1DB9C: .data size 0x24, 2 refs from screen_effect.c (own data block)
extern u8 lbl_1_data_1DB9C[0x24];

// lbl_1_bss_6D770: .bss size 0x4, 2 refs from screen_effect.c
extern u32 lbl_1_bss_6D770;

// jumptable_1_data_1DBC0: .data size 0x94, 1 refs from screen_effect.c (own data block)
extern u8 jumptable_1_data_1DBC0[0x94];

// lbl_1_data_1DFB0: .data size 0x508, 1 refs from screen_effect.c (own data block)
typedef struct {
    f32 unk_0;  // 1 loads, 0 stores
    u8 pad_4[0x504];
} Obj_1_data_1DFB0;
extern Obj_1_data_1DFB0 lbl_1_data_1DFB0;

// lbl_1_data_1E5C0: .data size 0x34, 1 refs from screen_effect.c (own data block)
typedef struct {
    u32 unk_0;  // 1 loads, 0 stores
    u32 unk_4;  // 1 loads, 0 stores
    u32 unk_8;  // 1 loads, 0 stores
    u32 unk_C;  // 1 loads, 0 stores
    u32 unk_10;  // 1 loads, 0 stores
    u32 unk_14;  // 1 loads, 0 stores
    u32 unk_18;  // 1 loads, 0 stores
    u32 unk_1C;  // 1 loads, 0 stores
    u32 unk_20;  // 1 loads, 0 stores
    u32 unk_24;  // 1 loads, 0 stores
    u32 unk_28;  // 1 loads, 0 stores
    u32 unk_2C;  // 1 loads, 0 stores
    u32 unk_30;  // 1 loads, 0 stores
} Obj_1_data_1E5C0;
extern Obj_1_data_1E5C0 lbl_1_data_1E5C0;

// lbl_1_data_1E4B8: .data size 0xA0, 1 refs from screen_effect.c (own data block)
extern u8 lbl_1_data_1E4B8[0xA0];

// jumptable_1_data_1DB04: .data size 0x98, 1 refs from screen_effect.c (own data block)
extern u8 jumptable_1_data_1DB04[0x98];

// lbl_1_data_1DC80: .data size 0x48, 1 refs from screen_effect.c (own data block)
extern u8 lbl_1_data_1DC80[0x48];

// jumptable_1_data_1DCC8: .data size 0x28, 1 refs from screen_effect.c (own data block)
extern u8 jumptable_1_data_1DCC8[0x28];

#endif  // REL_MAIN_REL_SCREEN_EFFECT_H


typedef struct {
    s32 a;
    u32 b;
    u32 c;
    u32 d;
} LoadArgs;
typedef struct {
    u32 unk_0;
    u32 busy;
    s16 course;
    u8 pad_A[2];
} CourseState;
typedef struct D1DCF0 {
    u8 pad_0[0x2B4];
    CourseState control;
    u8 pad_2C0[0x7D0 - 0x2C0];
    char str_7D0[0x7E0 - 0x7D0];
    char str_7E0[0x7E8 - 0x7E0];
    char str_7E8[0x7F0 - 0x7E8];
} D1DCF0;
typedef struct {
    s32 count;
    u32 pad4;
    struct MapEntry *entries;
} MapList;
typedef struct MapEntry {
    s32 data;
    const u8 *name;
} MapEntry;
typedef struct {
    Obj_1_bss_6D600 header;
    u8 pad20[0x150];
    void *textures;
    MapList *maps;
    u32 map;
    u8 pad17C[0x1C];
    s32 texture_size;
    u32 map_size;
} LoadState;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    s16 rx;
    s16 ry;
    s16 rz;
    u8 pad12[6];
    f32 ox;
    f32 oy;
    f32 oz;
    u8 pad24[0xD0];
    struct { u8 pad0[12]; f32 value; } *extra;
    u8 padF8[12];
    u32 flags;
    u8 pad108[0x3A8];
} CourseItem;
extern LoadArgs lbl_1_rodata_3344;
extern u32 lbl_1_bss_38460[21];
extern u8 lbl_1_bss_384B4;
extern void fn_1_9A864(void);
extern u8 fn_1_7B074(void);
extern void fn_8006FDEC(void);
extern void fn_80071718(void *);
extern void fn_800711A8(void *);
extern void fn_1_14CB4(void);
extern void fn_1_FA84(void);
extern int sprintf(char *, const char *, ...);
extern void *fn_1_D3A4C(void *);
extern MapList *fn_1_D3768(void *, void *);
extern u32 fn_80077D40(void);
extern u32 fn_80077BD4(void);
extern void fn_1_13B98(u32, u32);
extern void fn_1_F6A8(void);
extern void fn_1_9AABC(u32);
extern void fn_1_1384C(void *);
extern void fn_80008BEC(void *, int, u32);
extern void lbl_8006D758(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006E0C8(void *);
extern void fn_1_79948(void);
extern void fn_1_9A1E8(void);

#pragma opt_common_subs off
#pragma opt_propagation off
extern u8 lbl_1_data_1DCF0__fzgx_offset_0[];
extern u8 lbl_1_data_1DCF4__fzgx_offset_0[];
extern u8 lbl_1_data_1DD00__fzgx_offset_0[];
extern u8 lbl_1_data_1DD0C__fzgx_offset_0[];
extern u8 lbl_1_data_1DD18__fzgx_offset_0[];
extern u8 lbl_1_data_1DD24__fzgx_offset_0[];
extern u8 lbl_1_data_1DD2C__fzgx_offset_0[];
extern u8 lbl_1_data_1DD34__fzgx_offset_0[];
extern u8 lbl_1_data_1DD3C__fzgx_offset_0[];
extern u8 lbl_1_data_1DD44__fzgx_offset_0[];
extern u8 lbl_1_data_1DD50__fzgx_offset_0[];
extern u8 lbl_1_data_1DD60__fzgx_offset_0[];
extern u8 lbl_1_data_1DD70__fzgx_offset_0[];
extern u8 lbl_1_data_1DD78__fzgx_offset_0[];
extern u8 lbl_1_data_1DD80__fzgx_offset_0[];
extern u8 lbl_1_data_1DD8C__fzgx_offset_0[];
extern u8 lbl_1_data_1DD98__fzgx_offset_0[];
extern u8 lbl_1_data_1DDA8__fzgx_offset_0[];
extern u8 lbl_1_data_1DDB0__fzgx_offset_0[];
extern u8 lbl_1_data_1DDBC__fzgx_offset_0[];
extern u8 lbl_1_data_1DDC8__fzgx_offset_0[];
extern u8 lbl_1_data_1DDD8__fzgx_offset_0[];
extern u8 lbl_1_data_1DDE0__fzgx_offset_0[];
extern u8 lbl_1_data_1DDEC__fzgx_offset_0[];
extern u8 lbl_1_data_1DDF8__fzgx_offset_0[];
extern u8 lbl_1_data_1DE08__fzgx_offset_0[];
extern u8 lbl_1_data_1DE10__fzgx_offset_0[];
extern u8 lbl_1_data_1DE1C__fzgx_offset_0[];
extern u8 lbl_1_data_1DE24__fzgx_offset_0[];
extern u8 lbl_1_data_1DE30__fzgx_offset_0[];
extern u8 lbl_1_data_1DE40__fzgx_offset_0[];
extern u8 lbl_1_data_1DE4C__fzgx_offset_0[];
extern u8 lbl_1_data_1DE58__fzgx_offset_0[];
extern u8 lbl_1_data_1DE60__fzgx_offset_0[];
extern u8 lbl_1_data_1DE74__fzgx_offset_0[];
extern u8 lbl_1_data_1DE84__fzgx_offset_0[];
extern u8 lbl_1_data_1DE94__fzgx_offset_0[];
extern u8 lbl_1_data_1DEA0__fzgx_offset_0[];
extern u8 lbl_1_data_1DEAC__fzgx_offset_0[];
extern u8 lbl_1_data_1DEBC__fzgx_offset_0[];
extern u8 lbl_1_data_1DEC4__fzgx_offset_0[];
extern u8 lbl_1_data_1DED0__fzgx_offset_0[];
extern u8 lbl_1_data_1DED8__fzgx_offset_0[];
extern u8 lbl_1_data_1DEE0__fzgx_offset_0[];
extern u8 lbl_1_data_1DEE8__fzgx_offset_0[];
static u32 fzgx_pool_native_lbl_1_data_1DCF0_gap_0[173] = {0x4E4F4E00, 0x4D415354, 0x45522052, 0x45435600, 0x4D415354, 0x45522053, 0x454E4400, 0x534C4156, 0x45205345, 0x4E440000, 0x534C4156, 0x45205245, 0x43560000, 0x494E4954, 0x00000000, 0x54455354, 0x00000000, 0x54455354, 0x454E4400, 0x53455455, 0x50000000, 0x53455455, 0x505F444F, 0x4E450000, 0x53455455, 0x505F434F, 0x554E5445, 0x52000000, 0x53455455, 0x505F434E, 0x545F444F, 0x4E450000, 0x554E4C49, 0x4E4B0000, 0x434F494E, 0x00000000, 0x454E5452, 0x595F5741, 0x49540000, 0x4348414C, 0x4C454E47, 0x45520000, 0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000, 0x454E5452, 0x59000000, 0x454E5452, 0x595F4F4B, 0x00000000, 0x53494E47, 0x4C454348, 0x45434B00, 0x53494E47, 0x4C454348, 0x45434B5F, 0x4F4B0000, 0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F, 0x4B000000, 0x434F5552, 0x53455F44, 0x41544100, 0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000, 0x4D414348, 0x494E4500, 0x4D414348, 0x494E455F, 0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46, 0x49475F4F, 0x4B000000, 0x434F554E, 0x54455241, 0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954, 0x00000000, 0x4C494E4B, 0x57414954, 0x4F4B0000, 0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49, 0x56455259, 0x53544152, 0x54000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x00000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x4F4B0000, 0x4C494E4B, 0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649, 0x45570000, 0x434F5552, 0x53455649, 0x45575F4F, 0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B, 0x5354414E, 0x44425900, 0x4C494E4B, 0x4F4B0000, 0x4C494E4B, 0x00000000, 0x50415553, 0x45000000, 0x4552524F, 0x52000000, (u32)lbl_1_data_1DCF0__fzgx_offset_0, (u32)lbl_1_data_1DCF4__fzgx_offset_0, (u32)lbl_1_data_1DD00__fzgx_offset_0, (u32)lbl_1_data_1DD0C__fzgx_offset_0, (u32)lbl_1_data_1DD18__fzgx_offset_0, (u32)lbl_1_data_1DD24__fzgx_offset_0, (u32)lbl_1_data_1DD2C__fzgx_offset_0, (u32)lbl_1_data_1DD34__fzgx_offset_0, (u32)lbl_1_data_1DD3C__fzgx_offset_0, (u32)lbl_1_data_1DD44__fzgx_offset_0, (u32)lbl_1_data_1DD50__fzgx_offset_0, (u32)lbl_1_data_1DD60__fzgx_offset_0, (u32)lbl_1_data_1DD70__fzgx_offset_0, (u32)lbl_1_data_1DD78__fzgx_offset_0, (u32)lbl_1_data_1DD80__fzgx_offset_0, (u32)lbl_1_data_1DD8C__fzgx_offset_0, (u32)lbl_1_data_1DD98__fzgx_offset_0, (u32)lbl_1_data_1DDA8__fzgx_offset_0, (u32)lbl_1_data_1DDB0__fzgx_offset_0, (u32)lbl_1_data_1DDBC__fzgx_offset_0, (u32)lbl_1_data_1DDC8__fzgx_offset_0, (u32)lbl_1_data_1DDD8__fzgx_offset_0, (u32)lbl_1_data_1DDE0__fzgx_offset_0, (u32)lbl_1_data_1DDEC__fzgx_offset_0, (u32)lbl_1_data_1DDF8__fzgx_offset_0, (u32)lbl_1_data_1DE08__fzgx_offset_0, (u32)lbl_1_data_1DE10__fzgx_offset_0, (u32)lbl_1_data_1DE1C__fzgx_offset_0, (u32)lbl_1_data_1DE24__fzgx_offset_0, (u32)lbl_1_data_1DE30__fzgx_offset_0, (u32)lbl_1_data_1DE40__fzgx_offset_0, (u32)lbl_1_data_1DE4C__fzgx_offset_0, (u32)lbl_1_data_1DE58__fzgx_offset_0, (u32)lbl_1_data_1DE60__fzgx_offset_0, (u32)lbl_1_data_1DE74__fzgx_offset_0, (u32)lbl_1_data_1DE84__fzgx_offset_0, (u32)lbl_1_data_1DE94__fzgx_offset_0, (u32)lbl_1_data_1DEA0__fzgx_offset_0, (u32)lbl_1_data_1DEAC__fzgx_offset_0, (u32)lbl_1_data_1DEBC__fzgx_offset_0, (u32)lbl_1_data_1DEC4__fzgx_offset_0, (u32)lbl_1_data_1DED0__fzgx_offset_0, (u32)lbl_1_data_1DED8__fzgx_offset_0, (u32)lbl_1_data_1DEE0__fzgx_offset_0, (u32)lbl_1_data_1DEE8__fzgx_offset_0}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union {u32 words[3]; CourseState view;} fzgx_pool_native_lbl_1_data_1DCF0_control = {{0x00000000, 0x00000000, 0xFFFF0000}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_1_data_1DCF0_gap_2C0[324] = {0x41F00000, 0xC4AEB000, 0x453F9CCD, 0x452647D7, 0xBE2D0E56, 0x4203A1CB, 0x44562B12, 0x41F00000, 0xC4B5A333, 0x453F9CCD, 0x4523963D, 0xC25F374C, 0x4203A1CB, 0x444B64CD, 0x41F00000, 0xC4AEB000, 0x453F9CCD, 0x452647D7, 0xBE2D0E56, 0x4203A1CB, 0x44562B12, 0x41F00000, 0xC4E7499A, 0x4526559A, 0x454ED971, 0x42C96B02, 0xC3D3E666, 0x43AD5581, 0x41F00000, 0xC4AEB000, 0x453F9CCD, 0x452647D7, 0xBE2D0E56, 0x4203A1CB, 0x44562B12, 0x41F00000, 0x451BF28F, 0x4548123D, 0x4516FAE1, 0xC34570A4, 0x433CAFDF, 0x4276A8F6, 0x41F00000, 0xC4AEB000, 0x453F9CCD, 0x452647D7, 0xBE2D0E56, 0x4203A1CB, 0x44562B12, 0x42240000, 0xC46C6AE1, 0x45AA835C, 0x4532159A, 0x441E65F4, 0xC3083AE1, 0x4439AE25, 0x41F00000, 0xC4DFC000, 0x44FCBB85, 0xC525FCCD, 0x4410C5D3, 0xC1C526E9, 0xC3EBACCD, 0x41F00000, 0x4484675C, 0x460FD285, 0x448094CD, 0x444FA3C7, 0x41BB624E, 0x445ABDB2, 0x41F00000, 0x4409DD71, 0x45836D85, 0x452FAF0A, 0x447CAEB8, 0xC3413AE1, 0x4374B47B, 0x41F00000, 0xC4786B85, 0x454AED48, 0x44F978F6, 0x43AE25C3, 0xC2F9A3D7, 0x43FCC375, 0x41F00000, 0xC4AEB000, 0x453F9CCD, 0x452647D7, 0xBE2D0E56, 0x4203A1CB, 0x44562B12, 0x41F00000, 0x41CDCCCD, 0x457C0C00, 0x45B0EC7B, 0x4478F74C, 0xC3552666, 0x4463AD3F, 0x41F00000, 0x44772C9C, 0x4563BFAE, 0x44E49666, 0x44149F7D, 0x429A67F0, 0x4430EC29, 0x41F00000, 0x44EE2852, 0x458F6614, 0x45AEB71F, 0x44513106, 0xC30E3852, 0x44931000, 0x41F00000, 0x45284B5C, 0x45479B5C, 0x4530011F, 0xC3E555C3, 0x43CEFE35, 0x43416189, 0x41F00000, 0xC54E1666, 0x45F962CD, 0x452826B8, 0xC4DB3333, 0x4326E106, 0x436FAB02, 0x41F00000, 0xC4AEB000, 0x453F9CCD, 0x452647D7, 0xBE2D0E56, 0x4203A1CB, 0x44562B12, 0x41F00000, 0xC4AEB000, 0x453F9CCD, 0x452647D7, 0xBE2D0E56, 0x4203A1CB, 0x44562B12, 0x41F00000, 0xC4AEB000, 0x453F9CCD, 0x452647D7, 0xBE2D0E56, 0x4203A1CB, 0x44562B12, 0x41F00000, 0x45DC8785, 0x44E00D71, 0xC5E9F19A, 0x45128B85, 0xC4BF9333, 0x432C1E77, 0x41F00000, 0xC4AEB000, 0x453F9CCD, 0x452647D7, 0xBE2D0E56, 0x4203A1CB, 0x44562B12, 0x41F00000, 0xC4AEB000, 0x453F9CCD, 0x452647D7, 0xBE2D0E56, 0x4203A1CB, 0x44562B12, 0x41F00000, 0x4550A28F, 0x465CAD9A, 0x447E03D7, 0x448143D7, 0x439FE22D, 0xC505AB33, 0x41F00000, 0x44AE7EB8, 0x45D55985, 0xC2CD1EB8, 0x44AE7EB8, 0xC23146A8, 0xC2CD1EB8, 0x41F00000, 0xC36668F6, 0x45A9E4A4, 0x44C8251F, 0xC4086A3D, 0xC2ACAE98, 0x443FE0A4, 0x41F00000, 0x45489DEC, 0x45E7B5D7, 0x457EA35C, 0x424B6148, 0xC4208333, 0x44A1351F, 0x41F00000, 0xC323B5C3, 0x4556CB85, 0xC4465EB8, 0x43F24DD3, 0x42C6E8F6, 0x438216C9, 0x41F00000, 0x45101DC3, 0x45539F33, 0xC5149800, 0xC47E2000, 0xC404051F, 0xC31CD70A, 0x41F00000, 0xC4AEB000, 0x453F9CCD, 0x452647D7, 0xBE2D0E56, 0x4203A1CB, 0x44562B12, 0x41F00000, 0x4446D189, 0x4582E014, 0x444EAF6D, 0x4300778D, 0xC1D55604, 0x42C6947B, 0x41F00000, 0xC48C5666, 0x4511823D, 0x458DCDAE, 0x42DCCBC7, 0x42D129FC, 0x43FF7F7D, 0x41F00000, 0xC4B22000, 0x45BEE8A4, 0x4531F571, 0x435A4937, 0xC0FB3333, 0x44190A1D, 0x41F00000, 0xC4ECC666, 0x45CAABAE, 0x45A9A948, 0x434BD646, 0x42E9999A, 0x44522800, 0x42480000, 0xC3240F5C, 0x455FB99A, 0x44DF8F0A, 0x443DDD2F, 0xC2AECC4A, 0x436BAB44, 0x41F00000, 0x43D6E000, 0x45924D9A, 0x442B5333, 0xC3BD4CCD, 0x4365ADD3, 0xC25C0625, 0x41F00000, 0x43D6E000, 0x45924D9A, 0x442B5333, 0xC3BD4CCD, 0x4365ADD3, 0xC25C0625, 0x41F00000, 0xC485599A, 0x465F5933, 0xC57DF333, 0xC4947666, 0xC28AE560, 0xC5816733, 0x41F00000, 0x4407D0A4, 0x45CA091F, 0x4412D7CF, 0x43FBC625, 0xC2C15687, 0x4405C883, 0x41F00000, 0x4581711F, 0x46830D9A, 0xC53A1333, 0x4581711F, 0x430CD47B, 0xC53A1333, 0x42700000, 0x43A34831, 0x4687899A, 0xC5BB4333, 0x43A34831, 0xC1200000, 0xC5BB4333, 0x41F00000, 0x4491023D, 0x4660A133, 0xC54CE99A, 0x4491023D, 0x43F172F2, 0xC54CE99A, 0x41F00000, 0x43193BA6, 0x4571B400, 0x45637385, 0x4415F27F, 0xC31670A4, 0x4467C4DD, 0x41F00000, 0x452E5AE1, 0x456CED9A, 0x44B3F052, 0x4493C571, 0xC365028F, 0xC34FBAE1, 0x41F00000, 0x4527DE8F, 0x455FCC00, 0xC51A919A, 0x44581614, 0xC1C23958, 0xC440D0A4, 0x47524944, 0x00000000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static char fzgx_pool_native_lbl_1_data_1DCF0_str_7D0[0x7E0 - 0x7D0] = {0x25, 0x73, 0x73, 0x74, 0x25, 0x30, 0x32, 0x64, 0x2E, 0x74, 0x70, 0x6C, 0x2E, 0x6C, 0x7A, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static char fzgx_pool_native_lbl_1_data_1DCF0_str_7E0[0x7E8 - 0x7E0] = {0x73, 0x74, 0x61, 0x67, 0x65, 0x2F, 0x00, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static char fzgx_pool_native_lbl_1_data_1DCF0_str_7E8[0x7F0 - 0x7E8] = {0x25, 0x73, 0x73, 0x74, 0x25, 0x30, 0x32, 0x64}; /* fzgx-allow: A1 measured pool bytes and bindings */

static inline void fn_1_7ACDC_find_map(LoadState *state, MapList *maps) {
    s32 off;
    s32 i;
    for (i = 0, off = 0; i < maps->count; off += 8, i++) {
        const u8 *name = ((struct MapEntry *)((u8 *)maps->entries + off))->name;
        if (name[0] == 'C' && name[3] == '_' && name[4] == 'M' &&
            name[5] == 'A' && name[6] == 'P' && name[7] == 0) {
            state->map = maps->entries[i].data;
            return;
        }
    }
}
void fn_1_7ACDC(u32 course)
{
    s32 i;
    Obj_1_bss_3BE4 *dest;
    CourseState *control = &fzgx_pool_native_lbl_1_data_1DCF0_control.view;
    Obj_1_bss_3BE0_Target **manager = &lbl_1_bss_3BE0;
    MapList *maps;
    u32 previous_course;
    u32 saved;
    LoadState *state = (LoadState *)&lbl_1_bss_6D600;
    LoadArgs args = lbl_1_rodata_3344;
    char texture_file[32];
    char file[32];
    char * lab_t0;
    void * lab_t0_;
    MapList * tmp_call11;
    previous_course = control->course;
{
    u32 course_local = course;
    if (previous_course != course_local) {
        fn_1_9A864();
        if (!fn_1_7B074()) {
            if (state->textures || state->maps) {
                fn_8006FDEC();
            }
            if (state->textures) {
                lab_t0_ = state->textures;
                fn_80071718(lab_t0_);
                state->textures = 0;
            }
            if (state->maps) {
                fn_800711A8(state->maps);
                state->maps = 0;
            }
        }
        fn_1_14CB4();
        fn_1_FA84();
        control->course = -1;
        if (!fn_1_7B074()) {
            sprintf((lab_t0 = texture_file), fzgx_pool_native_lbl_1_data_1DCF0_str_7D0, fzgx_pool_native_lbl_1_data_1DCF0_str_7E0, course_local);
            sprintf((file), fzgx_pool_native_lbl_1_data_1DCF0_str_7E8, fzgx_pool_native_lbl_1_data_1DCF0_str_7E0, course_local);
            state->textures = fn_1_D3A4C(texture_file);
            state->texture_size = fn_80077D40();
            tmp_call11 = fn_1_D3768(file, state->textures);
            state->maps = tmp_call11;
            state->map_size = fn_80077BD4();
        }
        fn_1_13B98(course_local, 1);
        fn_1_F6A8();
    }
    if (!state->header.unk_1) {
        fn_1_9AABC(course_local);
    }
    args.a = (u32)&state->maps;
    args.b = (u32)&lbl_1_bss_38460[2];
    if (!state->header.unk_1) {
        args.c = (u32)&lbl_1_bss_384B4;
    }
    fn_1_1384C(&args);
    manager = &lbl_1_bss_3BE0;
    i = 0;
    control->course = course_local;
}
{
    Obj_1_bss_3BE4 **dest_base = (Obj_1_bss_3BE4 **)&lbl_1_bss_3BE4;
    CourseItem *source;
    state->header.unk_1 = i;
    source = (CourseItem *)(*manager)->unk_1C;
    dest = *dest_base;
    for (; i < (s32)(*manager)->unk_18; i++, source++, dest++) {
        saved = dest->unk_9C;
        fn_80008BEC(dest, 0, 0xA0);
        dest->unk_9C = saved;
        dest->unk_8 = source->x;
        dest->unk_C = source->y;
        dest->unk_10 = source->z;
        dest->unk_14 = source->x - source->ox;
        dest->unk_18 = source->y - source->oy;
        dest->unk_1C = source->z - source->oz;
        dest->unk_20 = source->rx;
        dest->unk_22 = source->ry;
        dest->unk_24 = source->rz;
        dest->unk_26 = source->rx;
        dest->unk_28 = source->ry;
        dest->unk_2A = source->rz;
        lbl_8006D758();
        lbl_8006DB74(dest->pad_2C);
        lbl_8006E0C8(&source->ox);
        lbl_8006DB74(dest->pad_2C + 0x30);
        if (source->extra) {
            dest->unk_98 = source->extra->value;
        }
        dest->unk_0 |= source->flags;
}
    }
    fn_1_79948();
    state->map = 0;
    if (control->course >= 0 && (maps = state->maps) != 0) {
        fn_1_7ACDC_find_map(state, maps);
    }
    fn_1_9A1E8();
    fzgx_pool_native_lbl_1_data_1DCF0_control.view.busy = 0;
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_7ACDC */

/* fzgx:begin fn_1_7B054 */
// Return the current screen effect value.
s16 fn_1_7B054(void) {
    return lbl_1_data_1DFA4.unk_8;
}
/* fzgx:end fn_1_7B054 */

/* fzgx:begin fn_1_7B064 */
u32 fn_1_7B064(void) {
    return lbl_1_bss_6D774;
}
/* fzgx:end fn_1_7B064 */

/* fzgx:begin fn_1_7B074 */
u8 fn_1_7B074(void) {
    return lbl_1_bss_6D600.unk_0;
}
/* fzgx:end fn_1_7B074 */

/* fzgx:begin fn_1_7B084 */
void fn_1_7B084(void *object, int value) {
    char text_a[32];
    char text_b[32];
    const char *data = (const char *)&lbl_1_data_1DCF0;

    sprintf(text_a, data + 0x7d0, data + 0x7e0, object);
    sprintf(text_b, data + 0x7e8, data + 0x7e0, object);
    if (value == 0) {
        fn_1_465D0(text_a, 1);
        fn_1_465D0(text_b, 1);
        fn_1_14D5C(object, 0);
    } else {
        fn_1_465D0(text_a, 2);
        fn_1_465D0(text_b, 2);
        fn_1_14D5C(object, 1);
    }
    fn_1_46EA8(value);
    fn_1_12620(object);
    sprintf(text_a, data + 0x7f8, object);
    fn_1_465D0(text_a, 1);
    fn_1_46EA8(0);
}
/* fzgx:end fn_1_7B084 */

/* fzgx:begin fn_1_7B184 */
void fn_1_7B184(void *arg) {
    char buf_48[0x20];
    char buf_28[0x20];
    char buf_08[0x20];
    u8 *base = (u8 *)&lbl_1_data_1DCF0;

    sprintf(buf_48, (const char *)(base + 0x7d0), (base + 0x7e0), arg);
    sprintf(buf_28, (const char *)(base + 0x7e8), (base + 0x7e0), arg);
    sprintf(buf_08, (const char *)(base + 0x810), arg);

    fn_1_46DC4(buf_48);
    fn_1_46DC4(buf_28);
    fn_1_46DC4(buf_08);
}
/* fzgx:end fn_1_7B184 */

/* fzgx:begin fn_1_7B218 */
typedef struct {
    u8 pad_0[0x7e0];
    char unk_7e0[0x4c];
    char unk_82c[0x14];
    char unk_840[0x20];
} ScreenEffectData;

extern u16 fn_1_12EF24(s16 value, s16 index);

void fn_1_7B218(s32 enabled) {
    char text_a[0x20];
    char text_b[0x20];
    s32 i;
    s16 index;
    ScreenEffectData *data = (ScreenEffectData *)&lbl_1_data_1DCF0;

    i = 0;
    do {
        index = fn_1_12EF24(lbl_1_bss_8B3A0.unk_8C, i);
        if (index >= 0) {
            sprintf(text_a, data->unk_82c, data->unk_7e0, index);
            sprintf(text_b, data->unk_840, data->unk_7e0, index);
            if (enabled == 0) {
                fn_1_465D0(text_a, 1);
                fn_1_465D0(text_b, 1);
            } else {
                fn_1_465D0(text_a, 2);
                fn_1_465D0(text_b, 2);
            }
        }
        i++;
    } while (i < 6);
}
/* fzgx:end fn_1_7B218 */

/* fzgx:begin fn_1_7B2E8 */
#include "psvec.h"

typedef struct {
    f32 unk_0;
    u32 unk_4;
    s16 unk_8;
} fn_1_7B2E8_State;

typedef struct {
    u8 pad_0[0x8];
    f32 unk_8[3];
    f32 unk_14;
} fn_1_7B2E8_Model;

typedef struct {
    s32 unk_0;
    u32 unk_4;
    struct {
        fn_1_7B2E8_Model *unk_0;
        char *unk_4;
    } *unk_8;
} fn_1_7B2E8_List;

/* the retail TU's .bss objects this function uses, at their retail offsets, so MWCC addresses them off one
 * section base; the fzgx_pool_gap_ object spans the retail objects in between, which this function does not touch.
 * The .bss, .rodata and .data primers below must come in that order: it sets which section base MWCC keeps in
 * which saved register. */
u8 fzgx_obj_lbl_1_bss_6D600[0x20];
u8 fzgx_pool_gap_6D620[0x150];
void *fzgx_obj_lbl_1_bss_6D770;
fn_1_7B2E8_List *fzgx_obj_lbl_1_bss_6D774;
u32 fzgx_obj_lbl_1_bss_6D778;
f32 lbl_1_bss_6D778__fzgx_offset_4[4];
f32 lbl_1_bss_6D778__fzgx_offset_14[5];

#pragma section code_type ".fzgxpool"
static void fn_1_7B2E8_fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D600;
    s = *(u8 *)&fzgx_pool_gap_6D620;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D770;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D774;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D778;
    s = *(u8 *)&lbl_1_bss_6D778__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6D778__fzgx_offset_14;
}
#pragma section code_type ".text"

extern void fzgx_pool_sink_p(void *);
extern void fzgx_pool_sink_f(f32);

/* Shared literal pool primer: screen_effect.unk_8 pools its literals behind one
   base (lbl_1_rodata_3278 here). These dummy functions, in a section the link
   ignores, reference the pooled literals in retail address order. */
#pragma section ".fzgxpool"

typedef struct { u32 a; f32 b; f32 unk_8; u32 unk_C; } fzgx_pool_Img16;
typedef struct { u8 r, g, b, a; } fzgx_pool_Color;

__declspec(section ".fzgxpool") void fzgx_pool_primer_0(void) {
    fzgx_pool_Img16 i0 = {0x04050000, -200.0f, 1000.0f, 0x006E9600};
    fzgx_pool_Img16 i1 = {0x08050000, -200.0f, 2000.0f, 0x0A0A2800};
    fzgx_pool_Img16 i2 = {0x07040000, 0.0f, 3000.0f, 0x171A1D00};
    fzgx_pool_Img16 i3 = {0x0C020000, 0.0f, 820.0f, 0x6E787900};
    fzgx_pool_Img16 i4 = {0xFF040000, 0.0f, 100.0f, 0};
    fzgx_pool_sink_p(&i0);
    fzgx_pool_sink_p(&i1);
    fzgx_pool_sink_p(&i2);
    fzgx_pool_sink_p(&i3);
    fzgx_pool_sink_p(&i4);
    fzgx_pool_sink_f(0.03125f);
    fzgx_pool_sink_f(1.0f);
}

__declspec(section ".fzgxpool") void fzgx_pool_primer_1(s32 a, u32 b) {
    fzgx_pool_sink_f((f32)a);
    fzgx_pool_sink_f((f32)b);
}

__declspec(section ".fzgxpool") void fzgx_pool_primer_2(void) {
    fzgx_pool_sink_f(0.016666668f);
}

__declspec(section ".fzgxpool") void fzgx_pool_primer_3(void) {
    fzgx_pool_Color c0 = {0xFF, 0xFF, 0xFF, 0xFF};
    fzgx_pool_sink_p(&c0);
}

__declspec(section ".fzgxpool") void fzgx_pool_primer_4(void) {
    fzgx_pool_sink_f(0.0f);
    fzgx_pool_sink_f(640.0f);
    fzgx_pool_sink_f(480.0f);
    fzgx_pool_sink_f(320.0f);
    fzgx_pool_sink_f(240.0f);
    fzgx_pool_sink_f(0.03f);
    fzgx_pool_sink_f(0.75f);
    fzgx_pool_sink_f(0.02f);
    fzgx_pool_sink_f(1.5f);
    fzgx_pool_sink_f(360.0f);
    fzgx_pool_sink_f(128.0f);
    fzgx_pool_sink_f(0.5f);
    fzgx_pool_sink_f(8.0f);
    fzgx_pool_sink_f(408.0f);
    fzgx_pool_sink_f(100.0f);
    fzgx_pool_sink_f(1.1920928955078125e-07f);
    fzgx_pool_sink_f(2.0f);
    fzgx_pool_sink_f(60.0f);
    fzgx_pool_sink_f(182.04444885f);
    fzgx_pool_sink_f(255.0f);
}

#pragma section ".text"

/* the retail TU's .data objects this function uses, at their retail offsets, so MWCC addresses them and the
 * string literals after them off one section base; the gaps span retail objects this function does not touch */
char fzgx_obj_lbl_1_data_1DCF0[4] = "NON";
u8 fzgx_pool_gap_1DCF4[0x2B0] = {1};
fn_1_7B2E8_State fzgx_obj_lbl_1_data_1DFA4 = {0.0f, 0, -1};
u8 fzgx_pool_gap_1DFB0[0x508] = {1};

extern void fzgx_touch(const void *);

#pragma section code_type ".fzgxpool"
static void fzgx_data_layout(void) {
    fzgx_touch(fzgx_obj_lbl_1_data_1DCF0);
    fzgx_touch(fzgx_pool_gap_1DCF4);
    fzgx_touch(&fzgx_obj_lbl_1_data_1DFA4);
    fzgx_touch(fzgx_pool_gap_1DFB0);
    fzgx_touch("GRID");
    fzgx_touch("%sst%02d.tpl.lz");
    fzgx_touch("stage/");
    fzgx_touch("%sst%02d.gma.lz");
    fzgx_touch("enemy_line/line%02d.bin");
    fzgx_touch("stage/COLI_COURSE%02d.lz");
}
#pragma section code_type ".text"

extern void fn_1_7B4C0(void);
extern void *fn_1_D38C4(char *path);
extern fn_1_7B2E8_List *fn_1_D35D4(char *path, void *tpl);
extern void sprintf(char *dst, const char *format, ...);
extern char *strstr(char *, char *);

/* averages the bounding-sphere centres of every model whose name does not contain "GRID" and keeps the largest
 * radius; as its own inline function its locals take the register order retail has */
static inline void fn_1_7B2E8_bounds(void) {
    f32 sum[3] = {0.0f, 0.0f, 0.0f};
    s32 off;
    s32 i;
    s32 count;
    f32 scale;
    f32 radius;  /* never initialised in retail either: the first compare reads f31 as it is */
    fn_1_7B2E8_Model *model;

    count = 0;
    for (i = 0, off = 0; i < fzgx_obj_lbl_1_bss_6D774->unk_0; off += 8, i++) {
        model = *(fn_1_7B2E8_Model **)((u8 *)fzgx_obj_lbl_1_bss_6D774->unk_8 + off);
        if (strstr(*(char **)((u8 *)fzgx_obj_lbl_1_bss_6D774->unk_8 + off + 4), "GRID") == NULL) {
            radius = model->unk_14 > radius ? model->unk_14 : radius;
            count++;
            psvec_add(sum, model->unk_8, sum);
        }
    }
    scale = 1.0f / count;
    psvec_scale(sum, scale, lbl_1_bss_6D778__fzgx_offset_4);
    lbl_1_bss_6D778__fzgx_offset_4[3] = radius;
    lbl_1_bss_6D778__fzgx_offset_14[0] = radius;
    lbl_1_bss_6D778__fzgx_offset_14[1] = 0.0f;
    lbl_1_bss_6D778__fzgx_offset_14[2] = radius;
}

void fn_1_7B2E8(u32 course) {
    char text_a[0x20];
    char text_b[0x20];

    if (fzgx_obj_lbl_1_data_1DFA4.unk_8 != course) {
        fn_1_7B4C0();
        sprintf(text_a, "%sselst%02d.tpl.lz", "stage/", course);
        sprintf(text_b, "%sselst%02d.gma.lz", "stage/", course);
        fzgx_obj_lbl_1_bss_6D770 = fn_1_D38C4(text_a);
        fzgx_obj_lbl_1_bss_6D774 = fn_1_D35D4(text_b, fzgx_obj_lbl_1_bss_6D770);
    }
    if (fzgx_obj_lbl_1_bss_6D770 != NULL && fzgx_obj_lbl_1_bss_6D774 != NULL) {
        fn_1_7B2E8_bounds();
    }
    fzgx_obj_lbl_1_data_1DFA4.unk_8 = course;
}
/* fzgx:end fn_1_7B2E8 */

/* fzgx:begin fn_1_7B4C0 */
// Releases active screen effects and resets the effect state.
void fn_1_7B4C0(void) {
    if (lbl_1_bss_6D770 != 0 || lbl_1_bss_6D774 != 0) {
        fn_8006FDEC();
    }

    if (lbl_1_bss_6D770 != 0) {
        fn_80071718((void *)lbl_1_bss_6D770);
        lbl_1_bss_6D770 = 0;
    }

    if (lbl_1_bss_6D774 != 0) {
        fn_800711A8((void *)lbl_1_bss_6D774);
        lbl_1_bss_6D774 = 0;
    }

    lbl_1_data_1DFA4.unk_8 = -1;
}
/* fzgx:end fn_1_7B4C0 */

/* fzgx:begin fn_1_7B558 noprologue */
#include "types.h"
#include "psvec.h"

typedef struct fn_1_7B558_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} fn_1_7B558_Vec3;

typedef struct fn_1_7B558_List {
    u32 count;
    u32 pad_4;
    struct {
        void *model;
        char *name;
    } *entries;
} fn_1_7B558_List;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_1_bss_6D600[0x20];
u8 lbl_1_bss_6D620__fzgx_offset_0[312];
u8 lbl_1_bss_6D758__fzgx_offset_0[24];
u32 lbl_1_bss_6D770;
fn_1_7B558_List *lbl_1_bss_6D774;
u32 fzgx_obj_lbl_1_bss_6D778;
f32 lbl_1_bss_6D778__fzgx_offset_4[4];
u8 lbl_1_bss_6D778__fzgx_offset_14[0x14];
u32 lbl_1_bss_6D778__fzgx_offset_28;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D600;
    s = *(u8 *)&lbl_1_bss_6D620__fzgx_offset_0;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_1_bss_6D758__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_6D770;
    s = *(u8 *)&lbl_1_bss_6D774;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D778;
    s = *(u8 *)&lbl_1_bss_6D778__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6D778__fzgx_offset_14;
    s = *(u8 *)&lbl_1_bss_6D778__fzgx_offset_28;
}
#pragma section code_type ".text"

typedef struct fn_1_7B558_Camera {
    u8 pad_0[0xD4];
    fn_1_7B558_Vec3 dir;
} fn_1_7B558_Camera;

extern struct { fn_1_7B558_Camera *cam; } lbl_801A66CC;
extern struct { f32 (*mtx)[4]; } lbl_801A6D00;
extern u32 lbl_801A66A0;
extern s16 lbl_1_bss_960;
extern u8 lbl_1_data_1E4B8[];
extern u8 lbl_1_data_1E5C0[];
extern struct { f32 unk_0; u32 unk_4; s16 unk_8; } lbl_1_data_1DFA4;

extern s8 fn_1_A5DC4(void);
extern u32 __cvt_fp2unsigned(f32);
extern void lbl_8006DD14(void *, void *);
extern void fn_80038F10(f32 *);
extern void GXGetScissor(u32 *, u32 *, u32 *, u32 *);
extern void fn_1_A71CC(void);
extern void fn_1_550A8(void);
extern f32 lbl_8006D188(s16);
extern void fn_1_A7024(f32, f32, f32, f32);
extern void fn_80038EEC(f32, f32, f32, f32, f32, f32);
extern void fn_80074188(u32, u32, u32, u32);
extern f32 lbl_8006D21C(s32);
extern f32 lbl_8006D668(void *);
extern void fn_8006F120(fn_1_7B558_Vec3 *, fn_1_7B558_Vec3 *);
extern void lbl_8006DCDC(void);
extern void fn_1_F7870(void *);
extern void mathutil_mtxA_rotate_y(s32);
extern void lbl_8006E0B4(f32, f32, f32);
extern void fn_1_55FF0(f32);
extern void fn_80072558(void);
extern char *strstr(char *, u8 *);
extern void fn_1_5621C(f32, f32, f32, f32);
extern void fn_1_556B8(void *);
extern f64 fn_1_550E0(void);
extern void fn_1_A722C(void);

extern void fzgx_pool_sink_p(void *);
extern void fzgx_pool_sink_f(f32);

/* Shared literal pool primer: screen_effect.c pools its literals behind one
   base (lbl_1_rodata_3278 here). These dummy functions, in a section the link
   ignores, reference the pooled literals in retail address order. */
#pragma section ".fzgxpool"

typedef struct { u32 a; f32 b; f32 c; u32 d; } fzgx_pool_Img16;
typedef struct { u8 r, g, b, a; } fzgx_pool_Color;
typedef struct { u32 w[12]; } fzgx_pool_Img48;

__declspec(section ".fzgxpool") void fzgx_pool_primer_0(void) {
    fzgx_pool_Img16 i0 = {0x04050000, -200.0f, 1000.0f, 0x006E9600};
    fzgx_pool_Img16 i1 = {0x08050000, -200.0f, 2000.0f, 0x0A0A2800};
    fzgx_pool_Img16 i2 = {0x07040000, 0.0f, 3000.0f, 0x171A1D00};
    fzgx_pool_Img16 i3 = {0x0C020000, 0.0f, 820.0f, 0x6E787900};
    fzgx_pool_Img16 i4 = {0xFF040000, 0.0f, 100.0f, 0};
    fzgx_pool_sink_p(&i0);
    fzgx_pool_sink_p(&i1);
    fzgx_pool_sink_p(&i2);
    fzgx_pool_sink_p(&i3);
    fzgx_pool_sink_p(&i4);
    fzgx_pool_sink_f(0.03125f);
    fzgx_pool_sink_f(1.0f);
}

__declspec(section ".fzgxpool") void fzgx_pool_primer_1(s32 a, u32 b) {
    fzgx_pool_sink_f((f32)a);
    fzgx_pool_sink_f((f32)b);
}

__declspec(section ".fzgxpool") void fzgx_pool_primer_2(void) {
    fzgx_pool_sink_f(0.016666668f);
}

__declspec(section ".fzgxpool") void fzgx_pool_primer_3(void) {
    fzgx_pool_Color c0 = {0xFF, 0xFF, 0xFF, 0xFF};
    fzgx_pool_sink_p(&c0);
}

__declspec(section ".fzgxpool") void fzgx_pool_primer_4(void) {
    fzgx_pool_sink_f(0.0f);
    fzgx_pool_sink_f(640.0f);
    fzgx_pool_sink_f(480.0f);
    fzgx_pool_sink_f(320.0f);
    fzgx_pool_sink_f(240.0f);
    fzgx_pool_sink_f(0.03f);
    fzgx_pool_sink_f(0.75f);
    fzgx_pool_sink_f(0.02f);
    fzgx_pool_sink_f(1.5f);
    fzgx_pool_sink_f(360.0f);
    fzgx_pool_sink_f(128.0f);
    fzgx_pool_sink_f(0.5f);
    fzgx_pool_sink_f(8.0f);
    fzgx_pool_sink_f(408.0f);
    fzgx_pool_sink_f(100.0f);
    fzgx_pool_sink_f(1.1920928955078125e-07f);
    fzgx_pool_sink_f(2.0f);
    fzgx_pool_sink_f(60.0f);
    fzgx_pool_sink_f(182.04444885f);
    fzgx_pool_sink_f(255.0f);
}

__declspec(section ".fzgxpool") void fzgx_pool_primer_5(void) {
    fzgx_pool_Img48 z0 = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00403AFF}};
    fzgx_pool_sink_p(&z0);
}

__declspec(section ".fzgxpool") void fzgx_pool_primer_6(void) {
    fzgx_pool_sink_f(63.0f);
    fzgx_pool_sink_f(0.9960784316062927f);
    fzgx_pool_sink_f(0.800000011920929f);
    fzgx_pool_sink_f(0.9411764740943909f);
    fzgx_pool_sink_f(0.8999999761581421f);
    fzgx_pool_sink_f(427.0f);
    fzgx_pool_sink_f(854.0f);
    fzgx_pool_sink_f(8192.0f);
    fzgx_pool_sink_f(4096.0f);
    fzgx_pool_sink_f(16384.0f);
    fzgx_pool_sink_f(55.0f);
    fzgx_pool_sink_f(1.2f);
    fzgx_pool_sink_f(0.1f);
    fzgx_pool_sink_f(90000.0f);
}

#pragma section ".text"

void fn_1_7B558(s32 arg0, s32 arg1, u32 x, u32 y, u32 w, u32 h, f32 scale) {
    f32 mtx[3][4];
    f32 viewport[6];
    fn_1_7B558_Vec3 at;
    fn_1_7B558_Vec3 eye;
    u32 sx;
    u32 sy;
    u32 sw;
    u32 sh;
    s32 angle;
    f32 alpha;
    f32 radius;
    f32 fov;
    f32 dist;
    struct { s32 value; s32 offset; } i;
    void *model;

    if (fn_1_A5DC4() != 0) {
        x = __cvt_fp2unsigned(320.0f - (320.0f * (320.0f - x)) / 427.0f);
        w = __cvt_fp2unsigned((640.0f * w) / 854.0f);
    }
    if (lbl_1_bss_6D770 == 0 || lbl_1_bss_6D774 == 0) {
        return;
    }
    if (arg1 != 0) {
        lbl_1_bss_6D778__fzgx_offset_28 = (lbl_801A66A0 & 0x1FF) << 7;
    } else if ((lbl_1_bss_6D778__fzgx_offset_28 & 0x3F) == 0) {
        lbl_1_bss_6D778__fzgx_offset_28 = 1;
    } else if ((lbl_1_bss_6D778__fzgx_offset_28 & 0x3F) < 63) {
        lbl_1_bss_6D778__fzgx_offset_28 = lbl_1_bss_6D778__fzgx_offset_28 + 1;
    }
    lbl_8006DD14(lbl_801A6D00.mtx + 3, mtx);
    fn_80038F10(viewport);
    GXGetScissor(&sx, &sy, &sw, &sh);
    fn_1_A71CC();
    fn_1_550A8();
    angle = (s16)lbl_1_bss_6D778__fzgx_offset_28 + 0x4000;
    eye.x = 0.0f;
    eye.y = lbl_8006D188((8192.0f + (4096.0f * lbl_8006D188(angle))));
    eye.z = lbl_8006D188((16384.0f + (8192.0f + (4096.0f * lbl_8006D188(angle)))));
    radius = lbl_1_bss_6D778__fzgx_offset_4[3];
    at.x = 0.0f;
    at.y = 0.0f;
    at.z = 0.0f;
    fn_1_A7024(55.0f, 1.2f, 0.1f, 90000.0f);
    fn_80038EEC(x, y, w, h, 0.0f, 1.0f);
    fn_80074188(x, y, w, h);
    fov = 5006.22216796875f;
    dist = (scale * radius) / lbl_8006D21C(fov);
    psvec_sub(&eye, &at, &lbl_801A66CC.cam->dir);
    lbl_8006D668(&lbl_801A66CC.cam->dir);
    psvec_scale_add(&at, &lbl_801A66CC.cam->dir, dist, &eye);
    fn_8006F120(&eye, &at);
    lbl_8006DCDC();
    if (arg0 != 0) {
        fn_1_F7870(lbl_1_data_1E5C0);
    }
    alpha = 1.0f;
    if (lbl_1_data_1DFA4.unk_8 != -1) {
        if (arg1 == 0) {
            alpha = (lbl_1_bss_6D778__fzgx_offset_28 & 0x3F) / 63.0f;
        }
        mathutil_mtxA_rotate_y((s16)(lbl_1_bss_6D778__fzgx_offset_28 + 0x4000));
        lbl_8006E0B4(-lbl_1_bss_6D778__fzgx_offset_4[0], -lbl_1_bss_6D778__fzgx_offset_4[1], -lbl_1_bss_6D778__fzgx_offset_4[2]);
        fn_1_55FF0(alpha);
        fn_80072558();
        for (i.value = 0, i.offset = 0; i.value < lbl_1_bss_6D774->count; i.offset += 8, i.value++) {
            arg1 = (s32)*(void **)((u8 *)lbl_1_bss_6D774->entries + i.offset);
            if (lbl_1_bss_960 == 5) {
                if (strstr(*(char **)((u8 *)lbl_1_bss_6D774->entries + i.offset + 4), lbl_1_data_1E4B8) == 0) {
                    fn_1_5621C(0.9960784316062927f, 0.800000011920929f, 0.9411764740943909f, 0.8999999761581421f);
                    fn_1_556B8((void *)arg1);
                    fn_1_5621C(1.0f, 1.0f, 1.0f, 1.0f);
                }
            } else {
                fn_1_556B8((void *)arg1);
            }
        }
    }
    fn_1_550E0();
    fn_1_A722C();
    fn_80074188(sx, sy, sw, sh);
    fn_80038EEC(viewport[0], viewport[1], viewport[2], viewport[3], viewport[4], viewport[5]);
    lbl_8006DD14(mtx, lbl_801A6D00.mtx + 3);
}
/* fzgx:end fn_1_7B558 */
