#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/alloc.h"
#define LiveCamera _cam_LiveCamera
#define live_camera _cam_live_camera
#include "rel/main_rel/camera.h"
#undef LiveCamera
#undef live_camera

extern char lbl_1_data_2C9C[20];
extern void OSPanic(const char *message, int line, const char *file, ...);
extern void fn_80009AA8(u32 value, u32 count, const char *file, int line);
extern u32 fn_1_435C(u32 value);
extern void fn_1_426C(s16 value);
extern u32 lbl_1_bss_F5C;
extern u32 lbl_1_bss_F60[2];
extern s32 memcmp(Obj_1_bss_7AC20 *, u32 *, u32);
extern u32 lbl_801A6410;
extern Obj_1_bss_F68_Target *fn_1_45D0(u32, u32, u8 *, u32);
extern void fn_800793D4(Obj_1_bss_F68_Target *, u32, u32);
extern void fn_1_6394(void);
extern void fn_1_63D4(void);
extern void fn_1_DF74(void);
extern u8 lbl_1_bss_F76;
s32 fn_1_3FC28(void);
void fn_1_3EF14(u32 *);
extern void fn_8006CE1C(f32);
extern void fn_1_4BB0(void);
extern f32 fn_1_4D14(Obj_1_data_2CDC *);
extern void fn_1_4CD8(void);
extern void fn_1_4E60(Obj_1_data_2CDC *);
extern void fn_1_4DE0(Obj_1_data_2CDC *, u32);
extern void fn_1_4010(s32, void (*)(Obj_1_data_2CDC *, u32));
extern void fn_8006CDFC(u32 *);
extern void fn_1_4060(void);


extern u16 fn_1_3F8C();

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

/* fzgx:begin fn_1_4A00 */
void fn_1_4A00(s32 enabled, u8 mode, void *value) {
    Obj_1_data_2CDC *data = &lbl_1_data_2CDC;
    void *allocated;

    if (data->unk_6 != -1) {
        fn_1_4BB0();
        lbl_1_data_2CDC.unk_4 = (65535.0f * fn_1_4D14(&lbl_1_data_2CDC));
    } else if (enabled != 0) {
        data->unk_4 = -1;
    } else {
        data->unk_4 = 0;
    }
    lbl_1_data_2CDC.unk_3 = 0;
    if (mode == 0) {
        if (enabled != 0) fn_1_4CD8();
        else fn_8006CE1C(1.0f);
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
            fn_8006CE1C(1.0f);
            lbl_1_data_2CDC.unk_4 = -1;
            return;
        }
    }
    lbl_1_data_2CDC.unk_3 |= 1;
    lbl_1_data_2CDC.unk_1 = 0;
    lbl_1_data_2CDC.unk_2 = 1;
    lbl_1_data_2CDC.unk_0 = mode;
    lbl_1_data_2CDC.unk_C = (u32)value;
    allocated = (void *)fn_1_435C((u32)value);
    data->unk_6 = fn_1_3F8C(lbl_1_data_2CEC, (void (*)(void))fn_1_4E60, (u32)&lbl_1_data_2CDC, 0);
    fn_1_4010(data->unk_6, fn_1_4DE0);
    fn_1_435C((u32)allocated);
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
f32 fn_1_4C24(void) {
    f32 ratio;

    if ((lbl_1_data_2CDC.unk_3 & 1) == 0) {
        return (-1.0f);
    }

    ratio = (f32)lbl_1_data_2CDC.unk_1 / lbl_1_data_2CDC.unk_0;
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

/* fzgx:begin fn_1_4D14 */
f32 fn_1_4D14(Obj_1_data_2CDC *obj) {
    f32 value3;
    u8 value;
    f32 value1;
    f32 temp;

    value3 = obj->unk_4 / 65535.0f;
    value = 0x0f;
    if (obj->unk_0 != 0x3c) {
        value = obj->unk_0;
    }
    if (obj->unk_1 > value) {
        value1 = 1.0f;
    } else {
        value1 = ((f32)obj->unk_1) / value;
    }

    if (obj->unk_3 & 2) {
        value1 = value3 * (1.0f - value1);
    } else {
        temp = 1.0f - value3;
        temp = temp * value1;
        value1 = value3 + temp;
    }
    return value1;
}
/* fzgx:end fn_1_4D14 */

/* fzgx:begin fn_1_4DE0 */
#pragma opt_dead_assignments off
void fn_1_4DE0(Obj_1_data_2CDC *obj, u32 arg1) {
    if (arg1 == 1) {
        obj->unk_3 &= 0xFE;
        if (obj->unk_3 & 2) {
            Obj_1_data_2CDC *p;
            fn_8006CE1C(0.0f);
            p = &lbl_1_data_2CDC;
            p->unk_8 = lbl_1_data_2CD8;
        } else {
            fn_8006CE1C(1.0f);
        }
        obj->unk_6 = -1;
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_4DE0 */

/* fzgx:begin fn_1_4E60 */
#pragma opt_dead_assignments off
void fn_1_4E60(Obj_1_data_2CDC *obj) {
    f32 base;
    u8 max;
    u8 c1;
    f32 ratio;
    f32 value;
    u32 unk8;
    Obj_1_data_2CDC *dst;

    base = obj->unk_4 / 65535.0f;
    max = (obj->unk_0 == 0x3c) ? 0xf : obj->unk_0;
    c1 = obj->unk_1;
    if (c1 > max) {
        ratio = 1.0f;
    } else {
        ratio = (f32)c1 / max;
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
        obj->unk_4 = (65535.0f * value);
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
    if (memcmp(&lbl_1_bss_7AC20, &lbl_1_bss_7AC40, 4) == 0) {
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
    return value;
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
    return value;
}
/* fzgx:end fn_1_5348 */

/* fzgx:begin fn_1_5370 */
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
extern void fn_1_8D08(void *, f32);
extern u32 fn_1_EBE4(void *, s32, u32, f32);
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

u8 lbl_1_data_3318[0xB4] = {
    0x63U, 0x61U, 0x6DU, 0x65U, 0x72U, 0x61U, 0x2EU, 0x63U, 0x00U, 0x00U, 0x00U, 0x00U, 0x63U, 0x61U, 0x6DU, 0x65U, 0x72U, 0x61U, 0x20U, 0x6DU, 0x61U, 0x6EU, 0x61U, 0x67U, 0x65U, 0x72U, 0x20U, 0x68U, 0x61U, 0x73U, 0x20U, 0x61U, 0x6CU, 0x72U, 0x65U, 0x61U, 0x64U, 0x79U, 0x20U, 0x61U, 0x63U, 0x74U, 0x69U, 0x76U, 0x65U, 0x2EU, 0x20U, 0x62U, 0x79U, 0x20U, 0x74U, 0x65U, 0x72U, 0x61U, 0x6DU, 0x6FU, 0x74U, 0x6FU, 0x0AU, 0x00U, 0x67U, 0x61U, 0x6DU, 0x65U, 0x5FU, 0x63U, 0x61U, 0x6DU, 0x65U, 0x72U, 0x61U, 0x20U, 0x68U, 0x61U, 0x73U, 0x20U, 0x61U, 0x6CU, 0x72U, 0x65U, 0x61U, 0x64U, 0x79U, 0x20U, 0x61U, 0x63U, 0x74U, 0x69U, 0x76U, 0x65U, 0x2EU, 0x20U, 0x62U, 0x79U, 0x20U, 0x74U, 0x65U, 0x72U, 0x61U, 0x6DU, 0x6FU, 0x74U, 0x6FU, 0x0AU, 0x00U, 0x00U, 0x00U, 0x00U, 0x6CU, 0x69U, 0x76U, 0x65U, 0x5FU, 0x63U, 0x61U, 0x6DU, 0x65U, 0x72U, 0x61U, 0x20U, 0x68U, 0x61U, 0x73U, 0x20U, 0x61U, 0x6CU, 0x72U, 0x65U, 0x61U, 0x64U, 0x79U, 0x20U, 0x61U, 0x63U, 0x74U, 0x69U, 0x76U, 0x65U, 0x2EU, 0x20U, 0x62U, 0x79U, 0x20U, 0x74U, 0x65U, 0x72U, 0x61U, 0x6DU, 0x6FU, 0x74U, 0x6FU, 0x0AU, 0x00U, 0x00U, 0x00U, 0x00U, 0x43U, 0x61U, 0x6DU, 0x65U, 0x72U, 0x61U, 0x45U, 0x78U, 0x65U, 0x63U, 0x00U, 0x00U, 0x43U, 0x61U, 0x6DU, 0x65U, 0x72U, 0x61U, 0x44U, 0x69U, 0x73U, 0x70U, 0x00U, 0x00U
};
u8 lbl_1_data_33CC[0xF] = "GameCameraExec";
u8 lbl_1_data_33DC[0xF] = "LiveCameraExec";

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

    switch (state->unk_0->unk_48) {
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
            f *= 2.0;
        }
        if ((s8)kind == 2) {
            f *= 0.5;
        }
        if ((s8)kind == 0) {
            item->unk_2 = arg1;
        }
        fn_1_8D08(item, f);
        fn_1_435C(state->unk_0->unk_50);
        state->unk_0->list0[state->unk_0->num0++] =
            fn_1_3F8C(lbl_1_data_33CC, fn_1_90E0, item, 0x14);
    }

    if (flag) {
        f = fn_1_A6FE8();
        if (arg0 == 4) {
            fn_1_EBE4(state->unk_8, -1, 1, f);
        } else {
            fn_1_EBE4(state->unk_8, arg1, 0, f);
        }
        fn_1_435C(state->unk_0->unk_50);
        state->unk_0->list0[state->unk_0->num0++] =
            fn_1_3F8C(lbl_1_data_33DC, fn_1_EE44, state->unk_8, 0x14);
    }

    fn_1_435C(t);
    return old;
}
/* fzgx:end fn_1_5370 */

/* fzgx:begin fn_1_56B8 */
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
extern void fn_1_8D08(void *, f32);
extern void fn_1_8A0C(s32);
extern u32 fn_1_EBE4(void *, s32, u32, f32);
extern void fn_1_EE04(fn_1_56B8_Camera *);

void fn_1_56B8(void) {
    GameCameraEntry *entry;
    fn_1_56B8_Cluster *c = (fn_1_56B8_Cluster *)&lbl_1_bss_F68;
    u32 count = 0;
    u32 reset;
    u8 i;
    u32 mode;
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

/* fn_1_5948's messages: it reaches them off the TU .data base (lbl_1_data_32A8 + 0x1A4 on) */
char lbl_1_data_344C[] = "loop: %d, mode: %d\n";
char lbl_1_data_3460[] = "camera mode is wrong. by teramoto";
char lbl_1_data_3484[] = "camera mode is wrong. by teramoto ";
char lbl_1_data_34A8[] = "caemra mode is wrong. by teramoto";
char lbl_1_data_34CC[] = "camera.c: NaN check error!\n";
char lbl_1_data_34E8[] = "  mode: %2d\n";
char lbl_1_data_34F8[] = "  loop: %2d\n";
char lbl_1_data_3508[] = "pos->x: %8.3f\n";
char lbl_1_data_3518[] = "pos->y: %8.3f\n";
char lbl_1_data_3528[] = "pos->z: %8.3f\n";
char lbl_1_data_3538[] = "  pers: %8.3f\n";
char lbl_1_data_3548[] = "   asp: %8.3f\n";
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
u32 fn_1_5910(void) {
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
