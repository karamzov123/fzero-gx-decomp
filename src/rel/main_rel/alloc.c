#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/alloc.h"

extern char lbl_1_data_2C9C[20];
extern void OSPanic(const char *message, int line, const char *file, ...);
extern void fn_80009AA8(u32 value, u32 count, const char *file, int line);
extern u32 fn_1_435C(u32 value);
extern void fn_1_426C(s16 value);
extern f32 lbl_1_rodata_160;
extern f32 lbl_1_rodata_164[2];
extern u32 lbl_1_bss_F5C;
extern u32 lbl_1_bss_F60[2];
extern s32 fn_8008023C(Obj_1_bss_7AC20 *, u32 *, u32);
extern u32 lbl_801A6410;
extern Obj_1_bss_F68_Target *fn_1_45D0(u32, u32, u8 *, u32);
extern void fn_800793D4(Obj_1_bss_F68_Target *, u32, u32);
extern u16 fn_1_3F8C(u8 *, void (*)(void), u32, u32);
extern void fn_1_6394(void);
extern void fn_1_63D4(void);
extern void fn_1_DF74(void);
extern u8 lbl_1_bss_F76;
extern void fn_1_DA6C(LiveCamera *);
extern void fn_1_DE14(LiveCamera *);
extern void fn_1_E174(void);
extern void fn_1_F3D0(LiveCamera *);
s32 fn_1_3FC28(void);
void fn_1_3EF14(u32 *);
extern f32 lbl_1_rodata_16C;
extern void fn_8006CE1C(f32);

/* fzgx:begin fn_1_4928 */
typedef struct {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} Fn1_4928Entry;

extern Fn1_4928Entry lbl_1_bss_DCC[32];

void fn_1_4928(void) {
    u32 value;
    u32 count;
    s32 remaining;
    Fn1_4928Entry *entry;

    entry = lbl_1_bss_DCC;
    remaining = 0x20;
    while (remaining > 0) {
        if (entry->unk_08 != 0) {
            entry->unk_04--;
            if (entry->unk_04 == 0) {
                count = entry->unk_08;
                value = entry->unk_00;
                if (count == 0) {
                    OSPanic((const char *)&lbl_1_data_2CD0, 0x15b,
                                lbl_1_data_2C9C);
                }
                fn_80009AA8(value, count, (const char *)&lbl_1_data_2CD0,
                            0x15b);
                entry->unk_08 = 0;
            }
        }
        remaining--;
        entry++;
    }
}
/* fzgx:end fn_1_4928 */

/* fzgx:begin fn_1_49F0 */
void fn_1_49F0(u32 *value) {
    lbl_1_data_2CD8 = *value;
}
/* fzgx:end fn_1_49F0 */

/* fzgx:begin fn_1_4A00 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/alloc.h"

extern void fn_1_4BB0(void);
extern f32 fn_1_4D14(Obj_1_data_2CDC *data);
extern const f32 lbl_1_rodata_160;
extern const f32 lbl_1_rodata_164;
extern void fn_1_4CD8(void);
extern void fn_8006CE1C(f32 value);
extern u32 fn_1_435C(void *value);
extern void fn_1_4E60(void);
extern s16 fn_1_3F8C(u8 *data, void (*callback)(void), Obj_1_data_2CDC *object, u32 count);
extern void fn_1_4DE0(void);
extern void fn_1_4010(s32 value, void (*callback)(void));

void fn_1_4A00(s32 enabled, u8 mode, void *value) {
    Obj_1_data_2CDC *data = &lbl_1_data_2CDC;
    void *allocated;

    if (data->unk_6 != -1) {
        fn_1_4BB0();
        lbl_1_data_2CDC.unk_4 = (u16)(s16)(lbl_1_rodata_160 * fn_1_4D14(&lbl_1_data_2CDC));
    } else if (enabled != 0) {
        data->unk_4 = -1;
    } else {
        data->unk_4 = 0;
    }
    lbl_1_data_2CDC.unk_3 = 0;
    if (mode == 0) {
        if (enabled != 0) fn_1_4CD8();
        else fn_8006CE1C(lbl_1_rodata_164);
        return;
    }
    if (enabled != 0) {
        lbl_1_data_2CDC.unk_3 |= 2;
        if (lbl_1_data_2CDC.unk_4 < 0x100) {
            fn_1_4CD8();
            lbl_1_data_2CDC.unk_4 = 0;
            return;
        }
    } else {
        lbl_1_data_2CDC.unk_3 |= 4;
        if (lbl_1_data_2CDC.unk_4 > 0xff00) {
            fn_8006CE1C(lbl_1_rodata_164);
            lbl_1_data_2CDC.unk_4 = -1;
            return;
        }
    }
    lbl_1_data_2CDC.unk_3 |= 1;
    lbl_1_data_2CDC.unk_1 = 0;
    lbl_1_data_2CDC.unk_2 = 1;
    lbl_1_data_2CDC.unk_0 = mode;
    lbl_1_data_2CDC.unk_C = (u32)value;
    allocated = (void *)fn_1_435C(value);
    data->unk_6 = (s16)fn_1_3F8C(lbl_1_data_2CEC, fn_1_4E60, &lbl_1_data_2CDC, 0);
    fn_1_4010(data->unk_6, fn_1_4DE0);
    fn_1_435C(allocated);
}
/* fzgx:end fn_1_4A00 */

/* fzgx:begin fn_1_4BB0 */
void fn_1_4BB0(void) {
    if (lbl_1_data_2CDC.unk_3 & 1) {
        u32 value = fn_1_435C(lbl_1_data_2CDC.unk_C);
        fn_1_426C(lbl_1_data_2CDC.unk_6);
        fn_1_435C(value);
    }
}
/* fzgx:end fn_1_4BB0 */

/* fzgx:begin fn_1_4C10 */
int fn_1_4C10(void) {
    u8 value = lbl_1_data_2CDC.unk_3;
    return value & 1;
}
/* fzgx:end fn_1_4C10 */

/* fzgx:begin fn_1_4C24 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 65535.0f;
    s = 1.0f;
    s = -1.0f;
    s = 0.0f;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"

extern f32 lbl_1_rodata_160;

f32 fn_1_4C24(void) {
    f32 *rodata;
    f32 ratio;

    rodata = &lbl_1_rodata_160;

    if ((lbl_1_data_2CDC.unk_3 & 1) == 0) {
        return (-1.0f);
    }

    ratio = (f32)lbl_1_data_2CDC.unk_1 / (f32)lbl_1_data_2CDC.unk_0;
    if (ratio < (0.0f)) {
        return (0.0f);
    }
    if (ratio > (1.0f)) {
        return (1.0f);
    }
    return ratio;
}
/* fzgx:end fn_1_4C24 */

/* fzgx:begin fn_1_4CAC */
u32 fn_1_4CAC(void) {
    return (lbl_1_data_2CDC.unk_3 >> 1) & 1;
}
/* fzgx:end fn_1_4CAC */

/* fzgx:begin fn_1_4CC0 */
void fn_1_4CC0(void) {
    lbl_1_data_2CDC.unk_3 &= 0xfe;
}
/* fzgx:end fn_1_4CC0 */

/* fzgx:begin fn_1_4CD8 */
#include "types.h"

struct fn_1_4CD8_lbl_1_data_2CDC {
    u8 pad_0[0x8];
    u32 unk_8;
};

#pragma opt_dead_assignments off
void fn_1_4CD8(void) {
    u32 *fzgx_value;
    fn_8006CE1C((0.0f));
    fzgx_value = &((*(struct fn_1_4CD8_lbl_1_data_2CDC *)&lbl_1_data_2CDC).unk_8);
    *fzgx_value = lbl_1_data_2CD8;
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_4CD8 */

/* fzgx:begin fn_1_4D14 pool */
typedef struct Fn14D14Data {
    u8 value0;
    u8 value1;
    u8 unk2;
    u8 flags;
    u16 value4;
} Fn14D14Data;

f32 fn_1_4D14(Fn14D14Data *data) {
    f32 value3;
    u8 value;
    f32 value1;
    f32 temp;

    value3 = ((f32)data->value4) / lbl_1_rodata_160;
    value = 0x0f;
    if (data->value0 != 0x3c) {
        value = data->value0;
    }
    if (data->value1 > value) {
        value1 = lbl_1_rodata_164[0];
    } else {
        value1 = ((f32)data->value1) / (f32)value;
    }

    if (data->flags & 2) {
        value1 = value3 * (lbl_1_rodata_164[0] - value1);
    } else {
        temp = lbl_1_rodata_164[0] - value3;
        temp = temp * value1;
        value1 = value3 + temp;
    }
    return value1;
}
/* fzgx:end fn_1_4D14 */

/* fzgx:begin fn_1_4DE0 */
extern f32 lbl_1_rodata_16C;
extern f32 lbl_1_rodata_164[2];

void fn_8006CE1C(f32);

#pragma opt_dead_assignments off
void fn_1_4DE0(Obj_1_data_2CDC *obj, u32 arg1) {
    if (arg1 == 1) {
        obj->unk_3 &= 0xFE;
        if (obj->unk_3 & 2) {
            Obj_1_data_2CDC *p;
            fn_8006CE1C(lbl_1_rodata_16C);
            p = &lbl_1_data_2CDC;
            p->unk_8 = lbl_1_data_2CD8;
        } else {
            fn_8006CE1C((*((0) + (lbl_1_rodata_164))));
        }
        obj->unk_6 = -1;
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_4DE0 */

/* fzgx:begin fn_1_4E60 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 65535.0f;
    s = 1.0f;
    s = -1.0f;
    s = 0.0f;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"

extern u32 lbl_1_data_2CD8;
extern void fn_8006CDFC(u32 *);
extern void fn_8006CE1C(f32);
extern void fn_1_4060(void);

#pragma opt_dead_assignments off
void fn_1_4E60(Obj_1_data_2CDC *obj) {
    f32 base;
    u8 max;
    u8 c1;
    f32 ratio;
    f32 value;
    u32 unk8;
    u32 src;
    Obj_1_data_2CDC *dst;

    base = (f32)(u32)obj->unk_4 / 65535.0f;
    max = (obj->unk_0 == 0x3c) ? 0xf : obj->unk_0;
    c1 = obj->unk_1;
    if (c1 > max) {
        ratio = 1.0f;
    } else {
        ratio = (f32)c1 / (f32)max;
    }
    if (obj->unk_3 & 2) {
        value = base * (1.0f - ratio);
    } else {
{
    f32 delta;
        delta = 1.0f - base;
        delta = delta * ratio;
        value = base + delta;
}
    }
    if (0.0f == value) {
        fn_8006CE1C(0.0f);
        dst = &lbl_1_data_2CDC;
        dst->unk_8 = lbl_1_data_2CD8;
    } else {
        unk8 = obj->unk_8;
        fn_8006CDFC(&unk8);
        fn_8006CE1C(value);
    }
    obj->unk_1 = obj->unk_1 + obj->unk_2;
    if (obj->unk_1 > obj->unk_0) {
        obj->unk_3 &= 0xfe;
    }
    if ((obj->unk_3 & 1) == 0) {
        obj->unk_6 = -1;
        obj->unk_4 = (s16)(65535.0f * value);
        fn_1_4060();
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_4E60 */

/* fzgx:begin fn_1_4FEC */
void fn_1_4FEC(void) {
    lbl_1_bss_F58 = 0;
}
/* fzgx:end fn_1_4FEC */

/* fzgx:begin fn_1_4FFC */
void fn_1_4FFC(void) {
    u8 value[0x14ac];
    u32 result;

    lbl_1_bss_F5C &= ~0x20000000;
    lbl_1_bss_F5C &= ~0x08000000;
    lbl_1_bss_F5C &= 0x3fffffff;

    if (lbl_1_bss_F60[0] != 0) {
        lbl_1_bss_F60[0]--;
    }

    if (fn_1_3FC28() != 0) {
        fn_1_3EF14((u32 *)value);
        result = *(u32 *)value;
        if ((result & 0x2) != 0) {
            lbl_1_bss_7EFD8.unk_19 = 1;
        } else {
            lbl_1_bss_7EFD8.unk_19 = 0;
        }
    }
}
/* fzgx:end fn_1_4FFC */

/* fzgx:begin fn_1_509C */
// Initialize the allocation state and report whether initialization succeeded.
s32 fn_1_509C(void) {
    lbl_1_bss_7AC40 = lbl_1_bss_F58;
    if (fn_8008023C(&lbl_1_bss_7AC20, &lbl_1_bss_7AC40, 4) == 0) {
        return 0;
    }

    lbl_1_bss_7AC20.unk_0 = lbl_1_bss_7AC40;
    return 1;
}
/* fzgx:end fn_1_509C */

/* fzgx:begin fn_1_5104 */
void fn_1_5104(void) {
    lbl_1_bss_F58 = lbl_1_bss_7AC40;
    lbl_1_bss_7AC20.unk_0 = lbl_1_bss_7AC40;
}
/* fzgx:end fn_1_5104 */

/* fzgx:begin fn_1_5124 */
typedef struct {
    Obj_1_bss_F68_Target *unk_0;
    Obj_1_bss_F68_Target *unk_4;
    Obj_1_bss_F68_Target *unk_8;
    u8 pad_C[2];
    u8 unk_E;
} InitState;

void fn_1_5124(u32 arg0, u32 arg1) {
    InitState *state = (InitState *)&lbl_1_bss_F68;
    u8 *data = lbl_1_data_32A8;
    Obj_1_bss_F68_Target *allocated;

    if (state->unk_0 != 0) {
        OSPanic((const char *)(data + 0x70), 0x69, (const char *)(data + 0x7c));
    }
    state->unk_0 = fn_1_45D0(lbl_801A6410, 0x78, data + 0x70, 0x6b);
    fn_800793D4(state->unk_0, 0, 0x78);

    if (state->unk_4 != 0) {
        OSPanic((const char *)(data + 0x70), 0x70, (const char *)(data + 0xac));
    }
    state->unk_4 = fn_1_45D0(lbl_801A6410, 0x7f0, data + 0x70, 0x72);
    fn_800793D4(state->unk_4, 0, 0x7f0);

    if (state->unk_8 != 0) {
        OSPanic((const char *)(data + 0x70), 0x78, (const char *)(data + 0xdc));
    }
    allocated = fn_1_45D0(lbl_801A6410, 0x1e0, data + 0x70, 0x7a);
    state->unk_8 = allocated;
    fn_800793D4(allocated, 0, 0x1e0);

    state->unk_0->unk_50 = arg0;
    state->unk_0->unk_54 = arg1;
    state->unk_0->unk_4B = state->unk_E;
    state->unk_0->unk_4C = data[0x6c];

    fn_1_435C(state->unk_0->unk_50);
    state->unk_0->unk_24 = fn_1_3F8C(data + 0x10c, fn_1_6394, 0, 0x15);
    fn_1_435C(state->unk_0->unk_54);
    state->unk_0->unk_46 = fn_1_3F8C(data + 0x118, fn_1_63D4, 0, 0x18);
    fn_1_DF74();
}
/* fzgx:end fn_1_5124 */

/* fzgx:begin fn_1_52E0 */
// Update the shared flag and the live object state when it exists.
void fn_1_52E0(u8 value) {
    lbl_1_bss_F76 = value;
    if (lbl_1_bss_F68 != 0) {
        lbl_1_bss_F68->unk_4B = value;
    }
}
/* fzgx:end fn_1_52E0 */

/* fzgx:begin fn_1_5300 */
// Return the current state flag, or zero when the state object is unavailable.
u8 fn_1_5300(void) {
    u32 value;

    if (lbl_1_bss_F68 != 0) {
        value = lbl_1_bss_F68->unk_4B;
    } else {
        value = 0;
    }
    return (u8)value;
}
/* fzgx:end fn_1_5300 */

/* fzgx:begin fn_1_5328 */
// Copies the value to the shared state when it is available.
void fn_1_5328(u8 value) {
    lbl_1_data_3314 = value;
    if (lbl_1_bss_F68 != 0) {
        lbl_1_bss_F68->unk_4C = value;
    }
}
/* fzgx:end fn_1_5328 */

/* fzgx:begin fn_1_5348 */
// Return the current state flag, or zero when the state object is unavailable.
u8 fn_1_5348(void) {
    u32 value;

    if (lbl_1_bss_F68 != 0) {
        value = lbl_1_bss_F68->unk_4C;
    } else {
        value = 0;
    }
    return (u8)value;
}
/* fzgx:end fn_1_5348 */

/* fzgx:begin fn_1_5370 noprologue */
#include "types.h"
#include "rel/main_rel/camera.h"

extern u16 fn_1_3F8C(u8 *, void (*)(void), void *, u32);
extern void fn_1_426C(s16);
extern u32 fn_1_435C(u32);
extern u32 fn_1_434C(void);
extern u8 fn_1_86624(void);
extern void fn_1_8298(s8);
extern void fn_1_847C(s8);
extern void fn_1_857C(s8);
extern void fn_1_90E0(void);
extern void fn_1_EE44(void);
extern f32 fn_1_A6FE8(void);
extern const f64 lbl_1_rodata_178;
extern const f64 lbl_1_rodata_180;
extern void fn_1_8D08(void *, f32);
extern void fn_1_EBE4(void *, s32, u32);
extern u8 lbl_1_data_33CC[0xF];
extern u8 lbl_1_data_33DC[0xF];

typedef struct {
    u8 pad_0[4];
    s16 list0[15];
    s16 num0;
    u16 unk_24;
    s16 list1[15];
    s16 num1;
    u16 unk_46;
    s8 unk_48;
    u8 unk_49;
    u8 unk_4A;
    u8 unk_4B;
    u8 unk_4C;
    u8 unk_4D;
    u8 pad_4E[2];
    u32 unk_50;
    u32 unk_54;
    f32 unk_58;
    f32 unk_5C;
} Target;

typedef struct {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[0x1F8];
} Item;

typedef struct {
    Target *unk_0;
    Item *unk_4;
    Target *unk_8;
} State;

s8 fn_1_5370(s8 arg0, s32 arg1) {
    State *state = (State *)&lbl_1_bss_F68;
    u32 i;
    s8 old;
    u32 num = 0;
    u32 flag = 0;
    u32 t;
    Item *item;
    u32 kind;
    f32 f;

    if (state->unk_0 == 0) {
        return -1;
    }
    t = fn_1_434C();
    fn_1_86624();
    old = state->unk_0->unk_4D;
    state->unk_0->unk_4D = arg0;
    fn_1_435C(state->unk_0->unk_50);

    for (i = 0; i < state->unk_0->num0; i++) {
        fn_1_426C(state->unk_0->list0[i]);
    }
    state->unk_0->num0 = 0;
    fn_1_435C(state->unk_0->unk_54);

    for (i = 0; i < state->unk_0->num1; i++) {
        fn_1_426C(state->unk_0->list1[i]);
    }
    state->unk_0->num1 = 0;

    switch (arg0) {
    case 0:
        fn_1_8298(arg0);
        break;
    case 1:
    case 2:
    case 4:
        fn_1_847C(arg0);
        break;
    case 3:
        fn_1_857C(arg0);
        break;
    }

    switch ((s8)state->unk_0->unk_48) {
    case 0:
        num = 1;
        break;
    case 1:
    case 2:
        num = 2;
        break;
    case 3:
    case 4:
    case 5:
    case 7:
        num = 3;
        break;
    case 6:
        num = 3;
        flag = 1;
        break;
    case 8:
        num = 4;
        break;
    case 9:
        flag = 1;
        break;
    case 10:
        num = 1;
        flag = 1;
        break;
    case 11:
        num = 0;
        flag = 0;
        break;
    }
    state->unk_0->unk_49 = num + flag;

    for (i = 0, item = state->unk_4; i < num;
         i++, item = (Item *)((u8 *)item + 0x1FC)) {
        f = fn_1_A6FE8();
        kind = (u8)(state->unk_0->unk_48);
        if ((s8)kind == 1 || (i == 0 && (s8)kind == 3) ||
            (i == 1 && (s8)kind == 4) || (i == 2 && (s8)kind == 5)) {
            f = f * lbl_1_rodata_178;
        }
        if ((s8)kind == 2) {
            f = f * lbl_1_rodata_180;
        }
        if ((s8)kind == 0) {
            item->unk_2 = (u16)arg1;
        }
        fn_1_8D08(item, f);
        fn_1_435C(state->unk_0->unk_50);
        state->unk_0->list0[state->unk_0->num0++] =
            fn_1_3F8C(lbl_1_data_33CC, fn_1_90E0, item, 0x14);
    }

    if (flag) {
        fn_1_A6FE8();
        if (arg0 == 4) {
            fn_1_EBE4(state->unk_8, -1, 1);
        } else {
            fn_1_EBE4(state->unk_8, arg1, 0);
        }
        fn_1_435C(state->unk_0->unk_50);
        state->unk_0->list0[state->unk_0->num0++] =
            fn_1_3F8C(lbl_1_data_33DC, fn_1_EE44, state->unk_8, 0x14);
    }

    fn_1_435C(t);
    return old;
}
/* fzgx:end fn_1_5370 */

/* fzgx:begin fn_1_56B8 noprologue */
#include "types.h"
#include "rel/main_rel/camera.h"

typedef struct {
    u8 unk_0;
    u8 unk_1;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
    s16 unk_8;
    u8 pad_A[0x8];
    s16 unk_12;
    s16 unk_14;
    u8 pad_16[0x1E0 - 0x16];
} fn_1_56B8_Camera;

/* lbl_1_bss_F68 heads a run of three camera pointers */
typedef struct {
    Obj_1_bss_F68_Target *target;
    GameCameraEntry *entries;
    fn_1_56B8_Camera *live;
} fn_1_56B8_Cluster;

extern f32 fn_1_A6FE8(void);
extern void fn_1_8D08(GameCameraEntry *, f32);
extern void fn_1_8A0C(s32);
extern void fn_1_EBE4(fn_1_56B8_Camera *, s16, s32, f32);
extern void fn_1_EE04(fn_1_56B8_Camera *);

#pragma opt_common_subs off
void fn_1_56B8(void) {
    GameCameraEntry *entry;
    fn_1_56B8_Cluster *c = (fn_1_56B8_Cluster *)&lbl_1_bss_F68;
    u32 count = 0;
    u32 reset;
    u8 i;
    u8 mode;
    f32 scale;
    reset = 0;

    switch ((s8)c->target->unk_48) {
    case 0:
        count = 1;
        break;
    case 1:
    case 2:
        count = 2;
        break;
    case 3:
    case 4:
    case 5:
    case 7:
        count = 3;
        break;
    case 6:
        count = 3;
        reset = 1;
        break;
    case 8:
        count = 4;
        break;
    case 9:
        reset = 1;
        break;
    case 10:
        count = 1;
        reset = 1;
        break;
    case 11:
        count = 0;
        reset = 0;
        break;
    }

    entry = c->entries;
    for (i = 0; i < count; i++, entry++) {
        scale = fn_1_A6FE8();
        mode = c->target->unk_48;
        if ((s8)mode == 1 || (i == 0 && (s8)mode == 3) ||
            (i == 1 && (s8)mode == 4) ||
            (i == 2 && (s8)mode == 5)) {
            scale *= 2.0;
        }
        if ((s8)mode == 2) {
            scale *= 0.5;
        }
        fn_1_8D08(entry, scale);
        fn_1_8A0C(i);
    }

    if (reset) {
        fn_1_56B8_Camera saved;
        fn_1_56B8_Camera *live;

        scale = fn_1_A6FE8();
        live = c->live;
        saved = *live;
        fn_1_EBE4(live, 0, 0, scale);
        c->live->unk_0 = saved.unk_0;
        c->live->unk_1 = saved.unk_1;
        c->live->unk_2 = saved.unk_2;
        c->live->unk_4 = saved.unk_4;
        c->live->unk_6 = saved.unk_6;
        c->live->unk_8 = saved.unk_8;
        c->live->unk_12 = saved.unk_12;
        c->live->unk_14 = saved.unk_14;
        fn_1_EE04(c->live);
    }
}
/* fzgx:end fn_1_56B8 */

/* fzgx:begin fn_1_58C4 */
u8 fn_1_58C4(void) {
    Obj_1_bss_F68_Target *obj = lbl_1_bss_F68;

    if (obj == 0) {
        return 0;
    }
    if ((s8)obj->unk_48 == 0xB) {
        return 1;
    }
    if ((obj->unk_0 & ((u32)1 << 31)) != 0) {
        return 1;
    }
    return obj->unk_49;
}
/* fzgx:end fn_1_58C4 */

/* fzgx:begin fn_1_5910 */
u8 fn_1_5910(void) {
    Obj_1_bss_F68_Target *obj;

    obj = lbl_1_bss_F68;
    if (obj == 0) {
        return 0;
    }
    if ((obj->unk_0 & (1u << 31)) != 0) {
        return 0;
    }
    return obj->unk_4A;
}
/* fzgx:end fn_1_5910 */

/* fzgx:begin fn_1_5948 noprologue */
#include "types.h"
#include "rel/main_rel/camera.h"

struct Sig_fn_1_549F4_Sig_fn_8006F1F0_fn_8006F1F0_Arg0 { f32 unk_0; f32 unk_4; f32 unk_8; };
struct Sig_fn_1_549F4_fn_1_549F4_Arg1 { u32 unk_0; u16 unk_4; };
extern CameraState *camera_get_state_object(void);
extern u32 camera_update_state(CameraState *);
extern f32 fn_1_A6FE8(void);
extern void fn_1_549F4(struct Sig_fn_1_549F4_Sig_fn_8006F1F0_fn_8006F1F0_Arg0 *, struct Sig_fn_1_549F4_fn_1_549F4_Arg1 *, f32, f32, f32, f32);
extern void fn_8006F4E0(s16 *);
extern u32 fn_1_A7024(f32, f32, f32, f32);
extern u16 fn_1_A5D88(void);
extern u16 fn_1_A5DB0(void);
extern s32 fn_1_A5DC4(void);
extern void fn_1_54E00(void *);
extern void fn_1_727C(void);
extern void lbl_8006DD14(void *, void *);
extern void *lbl_8006D784(void *);
extern void OSReport(const char *, ...);
extern void OSPanic(const char *, int, const char *, ...);
extern u32 fn_80038EEC(f32, f32, f32, f32, f32, f32);
extern u32 fn_80074188(u32, u32, u32, u32);
extern s32 fn_80007CDC(f32 *);
extern s32 fn_80007D58(f32 *);
extern void *lbl_801A66CC;
extern void *lbl_801A6D00;
extern u8 lbl_1_data_32A8[12];
extern const f32 lbl_1_rodata_188;
extern const f32 lbl_1_rodata_18C;
extern const f32 lbl_1_rodata_190;
extern const f32 lbl_1_rodata_194;
extern const f32 lbl_1_rodata_198;
extern const f32 lbl_1_rodata_19C;
extern const f32 lbl_1_rodata_1A0;
extern const f32 lbl_1_rodata_1A4;
extern const f32 lbl_1_rodata_1A8;
extern const f32 lbl_1_rodata_1AC;
extern const f64 lbl_1_rodata_1B0;
extern const f32 lbl_1_rodata_1B8;
extern const f64 lbl_1_rodata_1C0;
extern const f32 lbl_1_rodata_1C8;
extern const f64 lbl_1_rodata_1D0;
extern const f32 lbl_1_rodata_1D8;

/* camera mode byte; retail reads it as a signed char */
#define CAM_MODE (*(s8 *)&(*p_lbl_1_bss_F68)->unk_48)

typedef struct {
    u8 pad_0[0x58];
    struct { f32 x; f32 y; } vp[4];
} CamViewport;

#pragma opt_propagation off
void fn_1_5948(u32 arg0) {
    struct Sig_fn_1_549F4_fn_1_549F4_Arg1 * lab_t1_;
    struct Sig_fn_1_549F4_Sig_fn_8006F1F0_fn_8006F1F0_Arg0 *lab_t0_;
    register f32 v6;
    f32 v7;
    Obj_1_bss_F68_Target **p_lbl_1_bss_F68;
    u8 *p_lbl_1_data_32A8;
    f32 lab_t1;
    f32 v9, v10;
    f32 v14, v11, v12, v13, v15, v16;
    f32 v40, v38;
    f32 *v39, *v41, *v42;
    void *v43;
    f32 v47;
    CameraState *v4;
    u8 *v1;
    f32 loc_C, loc_8;
    struct Sig_fn_1_549F4_fn_1_549F4_Arg1 loc_10;

    p_lbl_1_bss_F68 = &lbl_1_bss_F68;
    p_lbl_1_data_32A8 = lbl_1_data_32A8;
    if (CAM_MODE == 11) return;
    (*p_lbl_1_bss_F68)->unk_4A = arg0;
    if (((*p_lbl_1_bss_F68)->unk_0 & 0x80000000) != 0) {
        lbl_8006DD14((u8 *)lbl_801A6D00 + 0x30, lbl_801A66CC);
        v4 = camera_get_state_object();
        camera_update_state(v4);
        fn_8006F4E0((s16 *)&loc_10);
        {
            fn_1_549F4((void *)&((f32 *)v4)[1], &loc_10, *(f32 *)((u8 *)v4 + 0x1C), (v6 = fn_1_A6FE8()), 0.0f, 0.0f);
        }
        fn_1_A7024(*(f32 *)((u8 *)v4 + 0x1C), (v7 = fn_1_A6FE8()), lbl_1_rodata_18C, lbl_1_rodata_190);
        return;
    }
    v9 = (f32)(u32)fn_1_A5D88();
    v10 = (f32)(u32)fn_1_A5DB0();
    switch ((s32)arg0) {
    case 0:
        switch (CAM_MODE) {
        case 0: case 9: break;
        case 1: case 3:
            v11 = lbl_1_rodata_188;
            v12 = lbl_1_rodata_194;
            v13 = lbl_1_rodata_198;
            v14 = v11;
            (*p_lbl_1_bss_F68)->unk_58 = v12;
            v15 = v11;
            (*p_lbl_1_bss_F68)->unk_5C = v13;
            break;
        case 2:
            v11 = lbl_1_rodata_188;
            v12 = lbl_1_rodata_198;
            v13 = lbl_1_rodata_194;
            v14 = v11;
            v15 = v11;
            break;
        case 4:
            v14 = lbl_1_rodata_188;
            v11 = lbl_1_rodata_198;
            v13 = v11;
            v15 = v14;
            v12 = v11;
            break;
        case 5: case 6: case 7: case 8:
            v11 = lbl_1_rodata_188;
            v13 = lbl_1_rodata_198;
            v14 = v11;
            v12 = v13;
            v15 = v11;
            break;
        case 10:
            v11 = lbl_1_rodata_188;
            v13 = lbl_1_rodata_194;
            v12 = v13;
            v15 = lbl_1_rodata_19C;
            v14 = v11;
            break;
        default:
            OSReport((char *)p_lbl_1_data_32A8 + 0x1A4, arg0, CAM_MODE);
            OSPanic((char *)p_lbl_1_data_32A8 + 0x70, 0x252, (char *)p_lbl_1_data_32A8 + 0x1B8);
            break;
        }
        v16 = lbl_1_rodata_194;
        break;
    case 1:
        switch (CAM_MODE) {
        case 1:
            v14 = lbl_1_rodata_188;
            v11 = lbl_1_rodata_198;
            v12 = lbl_1_rodata_194;
            v13 = v11;
            v16 = v12;
            break;
        case 2:
            v14 = lbl_1_rodata_198;
            v11 = lbl_1_rodata_188;
            v13 = lbl_1_rodata_194;
            v16 = v13;
            v12 = v14;
            break;
        case 3:
            v14 = lbl_1_rodata_188;
            v11 = lbl_1_rodata_198;
            v16 = lbl_1_rodata_194;
            v13 = v11;
            v12 = v11;
            break;
        case 4:
            v11 = lbl_1_rodata_188;
            v12 = lbl_1_rodata_194;
            v16 = v12;
            v13 = lbl_1_rodata_198;
            v14 = v11;
            break;
        case 5: case 6: case 7: case 8:
            v14 = lbl_1_rodata_198;
            v11 = lbl_1_rodata_188;
            v16 = lbl_1_rodata_194;
            v13 = v14;
            v12 = v14;
            break;
        case 10:
            v11 = lbl_1_rodata_1A0;
            v13 = lbl_1_rodata_1A4;
            v12 = v13;
            v16 = lbl_1_rodata_19C;
            v14 = v11;
            break;
        default:
            OSReport((char *)p_lbl_1_data_32A8 + 0x1A4, arg0, CAM_MODE);
            OSPanic((char *)p_lbl_1_data_32A8 + 0x70, 0x28E, (char *)p_lbl_1_data_32A8 + 0x1B8);
            break;
        }
        v15 = lbl_1_rodata_188;
        break;
    case 2:
        switch (CAM_MODE) {
        case 3: case 4:
            v11 = lbl_1_rodata_198;
            v14 = v11;
            v13 = v11;
            v12 = v11;
            break;
        case 5:
            v14 = lbl_1_rodata_188;
            v11 = lbl_1_rodata_198;
            v12 = lbl_1_rodata_194;
            v13 = v11;
            break;
        case 6: case 7: case 8:
            v14 = lbl_1_rodata_188;
            v11 = lbl_1_rodata_198;
            v13 = v11;
            v12 = v11;
            break;
        default:
            OSReport((char *)p_lbl_1_data_32A8 + 0x1A4, arg0, CAM_MODE);
            OSPanic((char *)p_lbl_1_data_32A8 + 0x70, 0x2B1, (char *)p_lbl_1_data_32A8 + 0x1DC);
            break;
        }
        v15 = lbl_1_rodata_188;
        v16 = lbl_1_rodata_194;
        break;
    case 3:
        switch (CAM_MODE) {
        case 6: case 8:
            v11 = lbl_1_rodata_198;
            v14 = v11;
            v13 = v11;
            v12 = v11;
            break;
        default:
            OSReport((char *)p_lbl_1_data_32A8 + 0x1A4, arg0, CAM_MODE);
            OSPanic((char *)p_lbl_1_data_32A8 + 0x70, 0x2C6, (char *)p_lbl_1_data_32A8 + 0x200);
            break;
        }
        v15 = lbl_1_rodata_188;
        v16 = lbl_1_rodata_194;
        break;
    }
    if (CAM_MODE == 0 || CAM_MODE == 9) {
        Obj_1_bss_F68_Target *viewport;
        viewport = (Obj_1_bss_F68_Target *)((u8 *)*p_lbl_1_bss_F68 + arg0 * 8);
        viewport->unk_58 = lbl_1_rodata_194;
        viewport = (Obj_1_bss_F68_Target *)((u8 *)*p_lbl_1_bss_F68 + arg0 * 8);
        viewport->unk_5C = lbl_1_rodata_194;
        lab_t1 = lbl_1_rodata_188;
        fn_80038EEC(lbl_1_rodata_188, lab_t1, v9, v10, lbl_1_rodata_188, lbl_1_rodata_194);
        fn_80074188(0, 0, (u32)v9, (u32)v10);
    } else {
        Obj_1_bss_F68_Target *viewport;
        u32 viewportOffset;
        viewportOffset = arg0 * 8;
        v14 *= v9;
        v11 *= v10;
        viewport = (Obj_1_bss_F68_Target *)((u8 *)*p_lbl_1_bss_F68 + viewportOffset);
        viewport->unk_58 = v12;
        v12 *= v9;
        viewport = (Obj_1_bss_F68_Target *)((u8 *)*p_lbl_1_bss_F68 + viewportOffset);
        viewport->unk_5C = v13;
        v13 *= v10;
        lab_t1 = v11;
        fn_80038EEC(v14, lab_t1, v12, v13, v15, v16);
        fn_80074188((u32)v14, (u32)v11, (u32)v12, (u32)v13);
    }
    if ((arg0 == 0 && (CAM_MODE == 9 || (u8)(CAM_MODE - 9) <= 1)) ||
        (arg0 == 3 && CAM_MODE == 6)) {
        v1 = (u8 *)p_lbl_1_bss_F68[2];
        v38 = *(f32 *)(v1 + 0x58);
        v39 = (f32 *)(v1 + 0xFC);
        v40 = *(f32 *)(v1 + 0x60);
        v41 = (f32 *)(v1 + 0x12C);
        v42 = (f32 *)(v1 + 0x1C);
        v43 = v1 + 0x15C;
    } else if (arg0 == 1 && CAM_MODE == 10) {
        v1 = (u8 *)p_lbl_1_bss_F68[1];
        v38 = *(f32 *)(v1 + 8);
        v39 = (f32 *)(v1 + 0xAC);
        v40 = *(f32 *)(v1 + 0xC);
        v41 = (f32 *)(v1 + 0xDC);
        v42 = (f32 *)(v1 + 0x10);
        v43 = v1 + 0x15C;
    } else {
        v1 = (u8 *)p_lbl_1_bss_F68[1] + arg0 * 0x1FC;
        v38 = *(f32 *)(v1 + 8);
        v39 = (f32 *)(v1 + 0xAC);
        v40 = *(f32 *)(v1 + 0xC);
        v41 = (f32 *)(v1 + 0xDC);
        v42 = (f32 *)(v1 + 0x10);
        v43 = v1 + 0x15C;
    }
    if (fn_80007CDC(v42) != 0 || fn_80007D58(v41) != 0 ||
        (loc_C = v38, (*(u32 *)&loc_C & 0x7F800000) == 0x7F800000) ||
        (loc_8 = v40, (*(u32 *)&loc_8 & 0x7F800000) == 0x7F800000)) {
        OSReport((char *)p_lbl_1_data_32A8 + 0x224);
        OSReport((char *)p_lbl_1_data_32A8 + 0x240, CAM_MODE);
        OSReport((char *)p_lbl_1_data_32A8 + 0x250, arg0);
        OSReport((char *)p_lbl_1_data_32A8 + 0x260, v42[0]);
        OSReport((char *)p_lbl_1_data_32A8 + 0x270, v42[1]);
        OSReport((char *)p_lbl_1_data_32A8 + 0x280, v42[2]);
        OSReport((char *)p_lbl_1_data_32A8 + 0x290, v38);
        OSReport((char *)p_lbl_1_data_32A8 + 0x2A0, v40);
        v42[0] = lbl_1_rodata_188;
        v42[1] = lbl_1_rodata_188;
        v42[2] = lbl_1_rodata_188;
        lbl_8006D784(v41);
        v38 = lbl_1_rodata_1A8;
        v40 = fn_1_A6FE8();
    }
    lbl_8006DD14(v39, lbl_801A66CC);
    lbl_8006DD14(v41, (u8 *)lbl_801A6D00 + 0x30);
    fn_1_54E00(v43);
    v47 = lbl_1_rodata_18C;
    if (v38 < lbl_1_rodata_1AC) v47 = (f32)(v47 * lbl_1_rodata_1B0);
    else if (v38 < lbl_1_rodata_1B8) v47 = (f32)(v47 * lbl_1_rodata_1C0);
    else if (v38 < lbl_1_rodata_1C8) v47 = (f32)(v47 * lbl_1_rodata_1D0);
    if ((s8)fn_1_A5DC4() != 0) {
        switch (*((u8 *)p_lbl_1_bss_F68 + 0xD)) {
        case 0: break;
        case 1: v38 *= lbl_1_rodata_1D8; break;
        case 2: v38 *= lbl_1_rodata_1A0; break;
        }
    }
    fn_1_A7024(v38, v40, v47, lbl_1_rodata_190);
    fn_1_727C();
}
#pragma opt_propagation reset
/* fzgx:end fn_1_5948 */

/* fzgx:begin fn_1_627C */
extern char lbl_1_data_2C9C[20];
extern void OSPanic(const char *message, int line, const char *file, ...);
extern void fn_80009AA8(u32 value, u32 count, const char *file, int line);
extern u32 fn_1_435C(u32 value);
extern void fn_1_426C(s16 value);
extern f32 lbl_1_rodata_160;
extern f32 lbl_1_rodata_164[2];
extern u32 lbl_1_bss_F5C;
extern u32 lbl_1_bss_F60[2];
extern s32 fn_8008023C(Obj_1_bss_7AC20 *, u32 *, u32);
extern u32 lbl_801A6410;
extern Obj_1_bss_F68_Target *fn_1_45D0(u32, u32, u8 *, u32);
extern void fn_800793D4(Obj_1_bss_F68_Target *, u32, u32);
extern u16 fn_1_3F8C(u8 *, void (*)(void), u32, u32);
extern void fn_1_6394(void);
extern void fn_1_63D4(void);
extern void fn_1_DF74(void);
extern u8 lbl_1_bss_F76;
extern void fn_1_DA6C(LiveCamera *);
extern void fn_1_DE14(LiveCamera *);
extern void fn_1_E174(void);
extern void fn_1_F3D0(LiveCamera *);
s32 fn_1_3FC28(void);
void fn_1_3EF14(u32 *);
extern f32 lbl_1_rodata_16C;
extern void fn_8006CE1C(f32);

extern u16 fn_1_A5D88(void);
extern u16 fn_1_A5DB0(void);
extern const f64 lbl_1_rodata_1E0;
extern const f32 lbl_1_rodata_188;
extern const f32 lbl_1_rodata_194;
extern u32 fn_80038EEC(f32, f32, f32, f32, f32, f32);
extern u32 fn_80074188(u32, u32, u32, u32);

#pragma opt_propagation off
#pragma opt_common_subs off
void fn_1_627C(void) {
    f32 width;
    f32 height;
    s8 signedMode;
    Obj_1_bss_F68_Target *obj = lbl_1_bss_F68;
    u8 mode = obj->unk_48;
    signedMode = (s8)mode;
    if (signedMode == 11 || (obj->unk_0 & 0x80000000) || (s8)mode == 0 || signedMode == 9) {
        return;
    }
    width = fn_1_A5D88();
    height = fn_1_A5DB0();
    fn_80038EEC(lbl_1_rodata_188, lbl_1_rodata_188, width, height, lbl_1_rodata_188, lbl_1_rodata_194);
    fn_80074188(0, 0, (u32)width, (u32)height);
}
/* fzgx:end fn_1_627C */

/* fzgx:begin fn_1_6394 */
void fn_1_6394(void) {
    fn_1_DA6C(live_camera);
    fn_1_DE14(live_camera);
    fn_1_E174();
}
/* fzgx:end fn_1_6394 */

/* fzgx:begin fn_1_63D4 */
 // Update the camera using the active camera object.
void fn_1_63D4(void) {
    fn_1_F3D0(live_camera);
}
/* fzgx:end fn_1_63D4 */
