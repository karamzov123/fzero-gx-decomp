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
