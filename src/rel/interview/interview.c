#include "types.h"

/* fzgx:begin _epilog */
extern const f32 lbl_17_rodata_20;
extern u32 lbl_17_bss_14[1];
extern u32 lbl_17_bss_18[1];

extern void fn_8006CE1C(f32 value);
extern void fn_1_48140(int value);
extern void fn_1_435C(u32 value);
extern void fn_1_41A8(void);

void _epilog(void) {
    fn_8006CE1C(lbl_17_rodata_20);
    fn_1_48140(140);
    fn_1_48140(161);
    fn_1_435C(lbl_17_bss_14[0]);
    fn_1_41A8();
    fn_1_435C(lbl_17_bss_18[0]);
    fn_1_41A8();
}
/* fzgx:end _epilog */

/* fzgx:begin fn_17_23C */
extern s32 lbl_17_bss_58[2];
extern s32 lbl_17_bss_24[4];
extern void fn_17_6C8(void);

void fn_17_23C(void) {
    if (lbl_17_bss_58[0] & 0x10000000) {
        if (lbl_17_bss_24[0] != 0) {
            lbl_17_bss_24[0]--;
        }
        if (lbl_17_bss_24[0] == 0) {
            lbl_17_bss_24[0] = 30;
            lbl_17_bss_58[0] &= ~0x10000000;
            fn_17_6C8();
        }
    }
}
/* fzgx:end fn_17_23C */

/* fzgx:begin fn_17_2B4 */
extern u32 lbl_17_bss_14;
extern u8 lbl_17_rodata_0[];
extern u32 lbl_17_bss_18[2];
extern void *lbl_801A6D00;
extern void *lbl_801A66CC;

extern void fn_1_435C(u32 arg);
extern void fn_1_407C(void);
extern void fn_1_3CC4(void);
extern void lbl_8006DD14(void *arg0, void *arg1);
extern void fn_1_B870(void);
extern void *camera_get_state_object(void);
extern void camera_update_state(void);
extern void lbl_8006DCA4(void);
extern void fn_8006F4E0(void *arg0);
extern f32 fn_1_A6FE8(void);
extern void fn_1_549F4(void *arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
extern void fn_1_A7024(f32 arg0, f32 arg1, f32 arg2, f32 arg3);

typedef struct CameraState {
    u8 pad[0x1c];
    f32 value;
} CameraState;

void fn_17_2B4(void) {
    CameraState *state;
    f32 *constants;
    u8 local[8];
    f32 state_value;
    struct { f32 value; } angle;

    constants = (f32 *)lbl_17_rodata_0;
    fn_1_435C(lbl_17_bss_14);
    fn_1_407C();
    fn_1_3CC4();
    lbl_8006DD14((u8 *)lbl_801A6D00 + 0x30, lbl_801A66CC);
    fn_1_B870();
    state = camera_get_state_object();
    camera_update_state();
    lbl_8006DCA4();
    fn_8006F4E0(&local);
    state_value = state->value;
    angle.value = fn_1_A6FE8();
    fn_1_549F4((u8 *)state + 4, &local, state_value, angle.value, constants[8], constants[8]);
    angle.value = fn_1_A6FE8();
    fn_1_A7024(state_value, angle.value, constants[9], constants[10]);
    fn_1_435C(lbl_17_bss_18[0]);
    fn_1_407C();
}
/* fzgx:end fn_17_2B4 */

/* fzgx:begin fn_17_394 */
extern u8 lbl_17_data_63E30[32];
extern s16 lbl_1_bss_962;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;

typedef void (*InterviewFunc)(void);

typedef struct InterviewEntry {
    u32 unk_0;
    InterviewFunc func;
    u32 value_8;
    u32 value_c;
} InterviewEntry;

void fn_17_394(void) {
    InterviewEntry *entry;
    s16 index;

    entry = (InterviewEntry *)lbl_17_data_63E30;
    index = lbl_1_bss_962;
    entry += index - 0xc5;
    lbl_1_bss_71688 = entry->value_8;
    lbl_1_bss_7168C = entry->value_c;
    entry->func();
}
/* fzgx:end fn_17_394 */

/* fzgx:begin fn_17_9F8 */
struct fn_17_9F8_state {
    u8 pad_00[0x14];
    u32 unk_14;
    u32 unk_18;
    s32 unk_1c;
    u8 pad_20[4];
    u32 unk_24;
    u8 pad_28[8];
    u8 unk_30;
    u8 pad_31[0x27];
    u32 flags_58;
    u16 unk_5c;
    u8 pad_5e[0x9A];
    u8 unk_f8;
    u8 unk_f9;
    u8 unk_fa;
    u8 unk_fb;
};

struct fn_17_9F8_audio {
    u32 unk_0;
};

struct fn_17_9F8_sys {
    u8 pad_0[0xE2];
    u8 unk_E2;
};

extern struct fn_17_9F8_state lbl_17_bss_0;
extern struct fn_17_9F8_audio lbl_1_bss_6EAB4;
extern struct fn_17_9F8_sys lbl_1_bss_5138;
extern u32 *lbl_1_bss_6EAD0;

extern s32 fn_1_C24A4(void);
extern u32 fn_1_B7C00(void);
extern void fn_1_4A00(s32, s32, u32);
extern s32 fn_1_4C10(void);
extern void fn_1_A2A70(s32, s32);
extern void ADXT_Stop(u32);
extern void fn_1_3FDA8(u32, u32);

void fn_17_9F8(void) {
    s32 tmp_call12;
    u8 fzgx_value;
    struct fn_17_9F8_state *st = &lbl_17_bss_0;
    u8 flag;
    s32 lab_t1;

    if (st->flags_58 & 0x200000) {
        if (fn_1_C24A4()) {
            st->unk_24 = 0x1e;
            return;
        }
        flag = fn_1_B7C00();
        if (flag != 0) {
            st->unk_24 = 0x1e;
            return;
        }
        st->flags_58 |= 0x10000000;
        fn_1_4A00(0, 0x1e, st->unk_18);
        return;
    }

    if (st->unk_5c >= 4 && st->unk_5c <= 5) {
        return;
    }
    if (fn_1_4C10() != 0) {
        return;
    }
    if ((st->unk_f9 != 0 || st->unk_fa != 0) && st->unk_fb != 0 && st->unk_5c >= 0xb) {
        return;
    }
    if (st->flags_58 & 0x10000000) {
        return;
    }
    if (st->flags_58 & 1 && st->unk_1c < 0x3c) {
        return;
    }

    if (st->flags_58 & 1 && st->unk_5c < 4) {
        st->flags_58 |= 0x10000000;
        ADXT_Stop(lbl_1_bss_6EAD0[1]);
        fn_1_4A00(0, 0x1e, st->unk_18);
        return;
    }
    if (st->flags_58 & 1 && st->unk_5c < 0xc) {
        st->flags_58 |= 0x10000000;
        lbl_1_bss_6EAB4.unk_0 |= 0xa4;
        fn_1_A2A70(4, 1);
        ADXT_Stop(((1)[lbl_1_bss_6EAD0]));
        fn_1_4A00(0, 0x1e, st->unk_18);
        return;
    }

    if (st->unk_f8 == 3 || (st->flags_58 & 0x20000000)) {
        st->flags_58 |= 0x10000000;
        lbl_1_bss_6EAB4.unk_0 |= 0xac;
        fn_1_A2A70(0xc, 0x1d);
        fn_1_4A00(0, 0x1e, st->unk_18);
        return;
    }

    if (st->unk_30 == 0) {
        fn_1_3FDA8(st->unk_14, st->unk_18);
    }
    fzgx_value = 1;
    st->unk_30 = fzgx_value;
    if ((s32)lbl_1_bss_5138.unk_E2 != 0) {
        return;
    }
    tmp_call12 = fn_1_C24A4();
    if (tmp_call12) {
        st->unk_24 = 0x1e;
        return;
    }
    flag = fn_1_B7C00();
    if (flag != 0) {
        st->unk_24 = 0x1e;
        return;
    }
    st->flags_58 |= 0x10000000;
    lbl_1_bss_6EAB4.unk_0 |= 0x2c;
    fn_1_A2A70(0xc, 0x1d);
    lab_t1 = 0x1e;
    fn_1_4A00(0, lab_t1, st->unk_18);
    st->unk_30 = 0;
}
/* fzgx:end fn_17_9F8 */

/* fzgx:begin fn_17_C9C */
extern s16 lbl_1_bss_964;
extern s16 lbl_1_bss_96A;
extern u8 lbl_17_bss_0[];

extern void fn_1_3FDA8(void *arg0, void *arg1);
extern void fn_1_4A00(s32 arg0, u8 arg1, void *arg2);
extern void fn_1_3EF14(void *arg0);
extern u32 fn_1_3FC9C(void);
extern s32 fn_1_FA088(void);
extern s32 fn_1_FA0A0(void);
extern s32 fn_1_FA004(void);
extern s32 fn_1_FA01C(void);

typedef struct InterviewState {
    u8 field_0;
    u8 pad_1[0x13];
    u8 *unk_14;
    s8 *unk_18;
    u8 pad_1c[0x3c];
    u32 unk_58;
    u8 pad_5c[0x9c];
    u8 unk_f8;
    u8 unk_f9;
    u8 unk_fa;
    u8 unk_fb;
    s16 unk_fc;
    s16 unk_fe;
    u8 unk_100;
} InterviewState;

#pragma opt_propagation off
static inline u8 * fn_17_C9C_read_pointer(InterviewState * owner) { return owner->unk_14; }
#pragma opt_common_subs off
static inline u8 fn_17_C9C_array_read(s32 index, u8 *array) { return array[index]; }
#pragma opt_strength_reduction off
void fn_17_C9C(void) {
    InterviewState *state;
    u8 local[0x14c0];
    s16 index;

    state = (InterviewState *)&lbl_17_bss_0;
    state->unk_58 = 0;
    state->unk_58 |= 0x40000000;
    index = lbl_1_bss_964;
    state->unk_fc = 0;
    state->unk_fe = 0;
    state->unk_100 = 0;
    state->unk_f8 = 0;
    state->field_0 = 0;
    state->unk_f9 = 0;
    state->unk_fa = 0;
    state->unk_fb = 0;

    if (index == 10) {
        state->unk_58 |= 0x20000000;
    } else if (index == 8) {
        state->unk_58 |= 0x00200000;
        fn_1_3FDA8(fn_17_C9C_read_pointer(state), state->unk_18);
        fn_1_4A00(1, 0x1e, state->unk_18);
    } else {
        state->unk_58 |= 1;
        lbl_1_bss_96A = 0xc6;
        fn_1_3EF14(local);
        state->unk_100 = fn_17_C9C_array_read(0xa6, local) - 1;
        state->unk_f8 = fn_1_3FC9C();
        if (fn_1_FA088() != 0) {
            state->unk_f9 = 1;
            state->unk_fb = 1;
            fn_1_FA0A0();
        }
        if (fn_1_FA004() != 0) {
            state->unk_fa = 1;
            state->unk_fb = 1;
            fn_1_FA01C();
        }
    }
}
/* fzgx:end fn_17_C9C */

/* fzgx:begin fn_17_1794 */
// fn_17_1794: empty in retail (single blr).
void fn_17_1794(void) {
}
/* fzgx:end fn_17_1794 */

/* fzgx:begin fn_17_2B9C */
#include "rel/interview/interview.h"

typedef struct InterviewControl {
    u8 pad0[0x28];
    u8 unk_28;
    u8 pad29[7];
    u8 unk_30;
    u8 pad31[0x27];
    u32 unk_58;
    u8 pad5C[0xCC];
    u8 unk_128;
} InterviewControl;
typedef struct InterviewInput {
    u8 pad0[8];
    u16 unk_8;
    u8 padA[10];
} InterviewInput;
typedef struct InterviewTimer {
    u8 pad0[0xE0];
    u8 unk_E0;
    u8 unk_E1;
    u8 unk_E2;
} InterviewTimer;
extern InterviewInput lbl_1_bss_9F8[];
extern u8 lbl_1_bss_25E98;
extern InterviewTimer lbl_1_bss_5138;
extern u32 fn_17_1798(void);
extern void fn_17_9F8(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_FA650(void);

void fn_17_2B9C(void) {
    InterviewControl *state = (InterviewControl *)&lbl_17_bss_0;
    if (state->unk_58 & 1) {
        fn_17_1798();
    }
    if (state->unk_58 & 1) {
        if (((((lbl_1_bss_9F8[lbl_1_bss_25E98].unk_8 >> 8) & 1) ||
              ((lbl_1_bss_9F8[lbl_1_bss_25E98].unk_8 >> 12) & 1)) &&
              !fn_1_B7C00() && state->unk_28 && !state->unk_128) || state->unk_30) {
            fn_17_9F8();
        }
        if ((lbl_1_bss_9F8[lbl_1_bss_25E98].unk_8 >> 4) & 1) {
            fn_1_FA650();
        }
    } else {
        if ((((lbl_1_bss_9F8[lbl_1_bss_25E98].unk_8 >> 12) & 1) &&
             !fn_1_B7C00() && state->unk_28 && !state->unk_128) || state->unk_30) {
            fn_17_9F8();
        }
    }
    if ((s32)lbl_1_bss_5138.unk_E2 != 0) {
        s32 pressed = (lbl_1_bss_9F8[lbl_1_bss_25E98].unk_8 >> 8) & 1;
        if (lbl_1_bss_5138.unk_E2 != 0 && pressed != 0 &&
            lbl_1_bss_5138.unk_E0 >= 15 && lbl_1_bss_5138.unk_E0 <= 120) {
            lbl_1_bss_5138.unk_E0 = 120;
        }
    }
}
/* fzgx:end fn_17_2B9C */

/* fzgx:begin fn_17_2D24 */
extern u32 lbl_17_bss_14;
extern u32 lbl_17_bss_18[2];
extern void fn_17_3270(u32, u32);

void fn_17_2D24(void) {
    fn_17_3270(lbl_17_bss_14, lbl_17_bss_18[0]);
}
/* fzgx:end fn_17_2D24 */

/* fzgx:begin fn_17_2D5C pool */
typedef struct InterviewRig {
    u8 pad_0[8];
    s16 unk_8;
    u8 pad_A[2];
    s16 unk_C;
    u8 pad_E[2];
    u32 unk_10;
    u32 unk_14;
    u8 pad_18[0x5C];
} InterviewRig;

struct VecWords {
    u32 x, y, z;
};

extern u8 lbl_17_data_0[];

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_17_bss_0;
u8 fzgx_obj_lbl_17_bss_1;
u8 fzgx_obj_lbl_17_bss_2;
u8 fzgx_obj_lbl_17_bss_3;
u8 fzgx_obj_lbl_17_bss_3__b1;
u8 fzgx_obj_lbl_17_bss_3__b2;
u8 fzgx_obj_lbl_17_bss_3__b3;
u8 fzgx_obj_lbl_17_bss_3__b4;
u8 fzgx_obj_lbl_17_bss_3__b5;
u8 fzgx_obj_lbl_17_bss_3__b6;
u8 fzgx_obj_lbl_17_bss_3__b7;
u8 fzgx_obj_lbl_17_bss_3__b8;
u32 fzgx_obj_lbl_17_bss_C;
u8 *fzgx_obj_lbl_17_bss_10;
u32 fzgx_obj_lbl_17_bss_14;
u32 fzgx_obj_lbl_17_bss_18;
u32 lbl_17_bss_18__fzgx_offset_4;
u32 fzgx_obj_lbl_17_bss_20;
u32 fzgx_obj_lbl_17_bss_24[4];
u32 fzgx_obj_lbl_17_bss_34[8];
u32 fzgx_obj_lbl_17_bss_54;
u32 fzgx_obj_lbl_17_bss_58;
u16 lbl_17_bss_58__fzgx_offset_4;
u16 lbl_17_bss_58__fzgx_offset_6;
InterviewRig fzgx_obj_lbl_17_bss_60;
s16 lbl_17_bss_60__fzgx_offset_74;
s16 fzgx_obj_lbl_17_bss_D6;
void *fzgx_obj_lbl_17_bss_D8[2];
u32 lbl_17_bss_D8__fzgx_offset_8[6];
u8 lbl_17_bss_D8__fzgx_offset_20;
u8 lbl_17_bss_D8__fzgx_offset_21;
u8 fzgx_obj_lbl_17_bss_FA;
u8 lbl_17_bss_FA__fzgx_offset_1;
s16 lbl_17_bss_FA__fzgx_offset_2;
s16 lbl_17_bss_FA__fzgx_offset_4;
u8 lbl_17_bss_FA__fzgx_offset_6;
u8 lbl_17_bss_FA__fzgx_offset_7;
u8 lbl_17_bss_FA__fzgx_offset_8;
u8 lbl_17_bss_FA__fzgx_offset_9;
u32 lbl_17_bss_FA__fzgx_offset_A[10];
u32 lbl_17_bss_FA__fzgx_offset_32;
u32 lbl_17_bss_FA__fzgx_offset_36;
u32 lbl_17_bss_FA__fzgx_offset_3A;
u32 lbl_17_bss_FA__fzgx_offset_3E;
u32 lbl_17_bss_FA__fzgx_offset_42;
u32 lbl_17_bss_FA__fzgx_offset_46;
u32 lbl_17_bss_FA__fzgx_offset_4A;
u32 lbl_17_bss_FA__fzgx_offset_4E;
u32 fzgx_obj_lbl_17_bss_14C;
u32 fzgx_obj_lbl_17_bss_150;
struct VecWords lbl_17_bss_150__fzgx_offset_4;
struct VecWords fzgx_obj_lbl_17_bss_160;
s16 lbl_17_bss_160__fzgx_offset_C;
s16 lbl_17_bss_160__fzgx_offset_E;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_17_bss_0;
    s = fzgx_obj_lbl_17_bss_1;
    s = fzgx_obj_lbl_17_bss_2;
    s = fzgx_obj_lbl_17_bss_3;
    s = fzgx_obj_lbl_17_bss_3__b1;
    s = fzgx_obj_lbl_17_bss_3__b2;
    s = fzgx_obj_lbl_17_bss_3__b3;
    s = fzgx_obj_lbl_17_bss_3__b4;
    s = fzgx_obj_lbl_17_bss_3__b5;
    s = fzgx_obj_lbl_17_bss_3__b6;
    s = fzgx_obj_lbl_17_bss_3__b7;
    s = fzgx_obj_lbl_17_bss_3__b8;
    s = fzgx_obj_lbl_17_bss_C;
    s = *(u32 *)&fzgx_obj_lbl_17_bss_10;
    s = fzgx_obj_lbl_17_bss_14;
    s = fzgx_obj_lbl_17_bss_18;
    s = lbl_17_bss_18__fzgx_offset_4;
    s = fzgx_obj_lbl_17_bss_20;
    s = fzgx_obj_lbl_17_bss_24[0];
    s = fzgx_obj_lbl_17_bss_34[0];
    s = fzgx_obj_lbl_17_bss_54;
    s = fzgx_obj_lbl_17_bss_58;
    s = lbl_17_bss_58__fzgx_offset_4;
    s = lbl_17_bss_58__fzgx_offset_6;
    s = *(u32 *)&fzgx_obj_lbl_17_bss_60;
    s = lbl_17_bss_60__fzgx_offset_74;
    s = fzgx_obj_lbl_17_bss_D6;
    s = *(u32 *)&fzgx_obj_lbl_17_bss_D8;
    s = lbl_17_bss_D8__fzgx_offset_8[0];
    s = lbl_17_bss_D8__fzgx_offset_20;
    s = lbl_17_bss_D8__fzgx_offset_21;
    s = fzgx_obj_lbl_17_bss_FA;
    s = lbl_17_bss_FA__fzgx_offset_1;
    s = lbl_17_bss_FA__fzgx_offset_2;
    s = lbl_17_bss_FA__fzgx_offset_4;
    s = lbl_17_bss_FA__fzgx_offset_6;
    s = lbl_17_bss_FA__fzgx_offset_7;
    s = lbl_17_bss_FA__fzgx_offset_8;
    s = lbl_17_bss_FA__fzgx_offset_9;
    s = lbl_17_bss_FA__fzgx_offset_A[0];
    s = lbl_17_bss_FA__fzgx_offset_32;
    s = lbl_17_bss_FA__fzgx_offset_36;
    s = lbl_17_bss_FA__fzgx_offset_3A;
    s = lbl_17_bss_FA__fzgx_offset_3E;
    s = lbl_17_bss_FA__fzgx_offset_42;
    s = lbl_17_bss_FA__fzgx_offset_46;
    s = lbl_17_bss_FA__fzgx_offset_4A;
    s = lbl_17_bss_FA__fzgx_offset_4E;
    s = fzgx_obj_lbl_17_bss_14C;
    s = fzgx_obj_lbl_17_bss_150;
    s = lbl_17_bss_150__fzgx_offset_4.x;
    s = fzgx_obj_lbl_17_bss_160.x;
    s = lbl_17_bss_160__fzgx_offset_C;
    s = lbl_17_bss_160__fzgx_offset_E;
}
#pragma section code_type ".text"

extern struct VecWords lbl_17_rodata_D4;
extern f32 lbl_17_rodata_E0[54];
extern u32 lbl_801A6410[1];
extern u32 lbl_1_bss_6EAB4;
extern u8 *lbl_1_bss_6EAD0[1];
extern u32 fn_1_A0680(void);
extern void fn_1_41048(void);
extern u32 fn_17_3C5C(void);
extern u32 fn_17_424C(void);
extern u32 fn_1_7BA08(u32,u32,u32);
extern s32 fn_1_45D0(u32,void *,void *,u32);
extern void fn_1_435C(u32);
extern s32 fn_1_3F8C(void *,void *,u32,u32);
extern u32 fn_1_7BA48(u32);
extern void fn_1_7BAF8(void);
extern u32 fn_17_3090(void);
extern void fn_17_71DC(void);
extern u32 fn_17_3160(void);
extern void fn_17_72BC(void);
extern void fn_17_38C4(void);
extern void fn_17_334C(void);
extern void fn_17_48D0(void);
extern u32 fn_17_49DC(void);
extern void lbl_8006D758(void);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_x(u32);
extern void lbl_8006E1B0(void *,void *);
extern void fn_80074CF4(f32,f32,f32);
extern void camera_set_state_flag(u8);
extern u32 fn_17_7F94(void);
extern u32 fn_8004CD70(u32,void *,u32);
extern u32 fn_80051E64(u32,void *,u32);
extern u32 fn_1_A1588(u32,u32);
extern u32 fn_8004BF0C(u32,u32);
extern void fn_1_154E4C(void);
extern void fn_1_C2454(void);
extern void *memset(void *,int,u32);
extern void fn_17_71C0(void *);
extern u32 fn_17_72C0(u32);


void fn_17_2D5C(u32 arg0, u32 arg1) {
    u8 *owner;
    u8 *data = lbl_17_data_0 + 0x60000;

    lbl_17_bss_FA__fzgx_offset_32 = 0;
    lbl_17_bss_FA__fzgx_offset_36 = 0;
    lbl_17_bss_FA__fzgx_offset_3A = 0;
    lbl_17_bss_FA__fzgx_offset_3E = 0;
    lbl_17_bss_FA__fzgx_offset_42 = 0;
    lbl_17_bss_FA__fzgx_offset_46 = 0;
    lbl_17_bss_FA__fzgx_offset_4E = 0;
    lbl_17_bss_FA__fzgx_offset_4A = 0;
    owner = fzgx_obj_lbl_17_bss_10;
    fn_1_A0680();
    fn_1_41048();
    fzgx_obj_lbl_17_bss_14C = arg0;
    fzgx_obj_lbl_17_bss_150 = arg1;
    fn_17_3C5C();
    fn_17_424C();
    fzgx_obj_lbl_17_bss_C = fn_1_45D0(*lbl_801A6410, (void *)fn_1_7BA08(0x20, 0x20, 0x40), data + 0x3E50, 0x758);
    fn_1_435C(arg0);
    fn_1_3F8C(data + 0x4004, (void *)fn_17_3090, 0, 5);
    fn_1_435C(arg1);
    fn_1_7BA48(fzgx_obj_lbl_17_bss_C);
    fn_1_3F8C(data + 0x4014, (void *)fn_1_7BAF8, fzgx_obj_lbl_17_bss_C, 3);
    fn_1_3F8C(data + 0x4020, (void *)fn_17_71DC, 0, 5);
    fn_1_3F8C(data + 0x4030, (void *)fn_17_3160, 0, 0xB);
    fn_1_3F8C(data + 0x4040, (void *)fn_17_72BC, 0, 0xC);
    fn_1_3F8C(data + 0x4050, (void *)fn_17_38C4, 0, 0x1C);
    fn_17_334C();
    fn_17_48D0();
    fn_17_49DC();
    lbl_17_bss_150__fzgx_offset_4 = fzgx_obj_lbl_17_bss_160 = lbl_17_rodata_D4;
    lbl_17_bss_160__fzgx_offset_C = -0x2000;
    lbl_17_bss_160__fzgx_offset_E = 0x2000;
    lbl_8006D758();
    mathutil_mtxA_rotate_y(lbl_17_bss_160__fzgx_offset_E);
    mathutil_mtxA_rotate_x(lbl_17_bss_160__fzgx_offset_C);
    lbl_8006E1B0(&lbl_17_bss_150__fzgx_offset_4, &fzgx_obj_lbl_17_bss_160);
    fn_80074CF4(lbl_17_rodata_E0[0], lbl_17_rodata_E0[0], lbl_17_rodata_E0[0]);
    camera_set_state_flag(1);
    fn_17_7F94();
    lbl_17_bss_60__fzgx_offset_74 = -0x4B;
    fzgx_obj_lbl_17_bss_D6 = -0x14;
    if (*(u32 *)*lbl_1_bss_6EAD0 == 0) {
        *(u32 *)*lbl_1_bss_6EAD0 = fn_8004CD70(2, *lbl_1_bss_6EAD0 + 0x10, 0x4A248);
    }
    if (*(u32 *)(*lbl_1_bss_6EAD0 + 4) == 0) {
        *(u32 *)(*lbl_1_bss_6EAD0 + 4) = fn_8004CD70(2, *lbl_1_bss_6EAD0 + 0x4A258, 0x4A248);
    }
    fn_80051E64(*(u32 *)(*lbl_1_bss_6EAD0 + 4), *lbl_1_bss_6EAD0 + 0x944A0, 0x3000);
    lbl_1_bss_6EAB4 &= 0xFFFFFFD3;
    fn_1_A1588(*(u32 *)*lbl_1_bss_6EAD0, 0x12);
    fn_8004BF0C(*(u32 *)*lbl_1_bss_6EAD0, lbl_17_bss_60__fzgx_offset_74);
    fn_8004BF0C(*(u32 *)(*lbl_1_bss_6EAD0 + 4), fzgx_obj_lbl_17_bss_D6);
    memset(&fzgx_obj_lbl_17_bss_60, 0, 0x74);
    fn_17_71C0(&fzgx_obj_lbl_17_bss_60);
    fzgx_obj_lbl_17_bss_60.unk_8 = owner[5];
    fzgx_obj_lbl_17_bss_60.unk_C = 0;
    fzgx_obj_lbl_17_bss_60.unk_14 = fzgx_obj_lbl_17_bss_60.unk_10 = fn_17_72C0(fzgx_obj_lbl_17_bss_60.unk_8);
    fn_1_154E4C();
    fn_1_C2454();
}
/* fzgx:end fn_17_2D5C */

/* fzgx:begin fn_17_3090 pool */
extern void fn_17_50F0(void);
extern void fn_17_3E08(void);
extern void fn_17_4540(void);
extern void fn_17_49B8(void);
extern void fn_17_3410(void);
extern void fn_17_4E50(void);
extern void fn_17_5C24(void);

extern void fn_1_154F74(s32, s32);
extern void fn_1_154F88(f32);
extern void fn_1_154F98(s32);
extern void fn_1_154FD8(void);
extern void fn_1_49410(void);
extern void fn_1_495B0(s32);
extern void fn_1_49590(f32);

extern const f32 lbl_17_rodata_3C;
extern f32 lbl_17_rodata_24[5];

typedef struct InterviewFlags {
    u8 pad[4];
    u32 flags;
    u8 rest[0x6E];
} InterviewFlags;

/* interview.c file-scope objects, in retail order: MWCC addresses them off one section base. */
u8 lbl_17_bss_0;
u8 lbl_17_bss_1;
u8 lbl_17_bss_2;
u8 lbl_17_bss_3;
u32 lbl_17_bss_4;
u32 lbl_17_bss_8;
u32 lbl_17_bss_C;
u32 lbl_17_bss_10;
u32 lbl_17_bss_14;
u32 lbl_17_bss_18[2];
u32 lbl_17_bss_20;
u32 lbl_17_bss_24[4];
u32 lbl_17_bss_34[8];
s32 lbl_17_bss_54;
u32 lbl_17_bss_58[2];
InterviewFlags lbl_17_bss_60;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u32 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = lbl_17_bss_0;
    s = lbl_17_bss_1;
    s = lbl_17_bss_2;
    s = lbl_17_bss_3;
    s = lbl_17_bss_4;
    s = lbl_17_bss_8;
    s = lbl_17_bss_C;
    s = lbl_17_bss_10;
    s = lbl_17_bss_14;
    s = lbl_17_bss_18[0];
    s = lbl_17_bss_20;
    s = lbl_17_bss_24[0];
    s = lbl_17_bss_34[0];
    s = lbl_17_bss_54;
    s = lbl_17_bss_58[0];
    s = lbl_17_bss_60.flags;
}
#pragma section code_type ".text"

void fn_17_3090(void) {
    InterviewFlags *sub;

    if (lbl_17_bss_58[0] & (~0x7fffffff)) {
        fn_17_50F0();
    }
    fn_17_3E08();
    fn_17_4540();
    fn_17_49B8();
    fn_17_3410();
    fn_17_4E50();
    sub = &lbl_17_bss_60;
    if (sub->flags & 2) {
        fn_17_5C24();
        if (lbl_17_bss_54 == 5) {
            fn_1_154F74(0x50, 0x181);
            fn_1_154F88(lbl_17_rodata_3C);
            fn_1_154F98(2);
        } else {
            fn_1_154F74(0x19, 0x17e);
            fn_1_154F88(lbl_17_rodata_24[0]);
            fn_1_154F98(1);
            fn_1_49410();
            fn_1_495B0(-2147483647 - 1);
            fn_1_49590(lbl_17_rodata_3C);
        }
        fn_1_154FD8();
    }
}
/* fzgx:end fn_17_3090 */

/* fzgx:begin fn_17_3270 */
typedef struct InterviewState {
    u32 first;
    u32 second;
} InterviewState;

extern InterviewState *lbl_1_bss_6EAD0;
extern u32 lbl_801A6410;

extern void ADXT_Stop(u32 value);
extern void fn_80051E30(u32 value);
extern void fn_1_A0AA4(void);
extern void fn_17_416C(void);
extern void fn_17_4858(void);
extern void fn_17_49BC(void);
extern void fn_17_4FE0(void);
extern u32 lbl_17_bss_C;
extern u8 lbl_17_data_63E50[592];
extern void fn_1_46B4(u32, u32, void *, u32);
extern void fn_1_435C(void *);
extern void fn_1_41A8(void);
extern void fn_1_410A0(void);
extern void fn_17_602C(void);

void fn_17_3270(void *arg0, void *arg1) {
    ADXT_Stop(lbl_1_bss_6EAD0->first);
    ADXT_Stop(lbl_1_bss_6EAD0->second);
    fn_80051E30(lbl_1_bss_6EAD0->second);
    fn_1_A0AA4();
    fn_17_416C();
    fn_17_4858();
    fn_17_49BC();
    fn_17_4FE0();

    if (lbl_17_bss_C != 0) {
        fn_1_46B4(lbl_801A6410, lbl_17_bss_C, lbl_17_data_63E50, 0x81d);
        lbl_17_bss_C = 0;
    }

    fn_1_435C(arg0);
    fn_1_41A8();
    fn_1_435C(arg1);
    fn_1_41A8();
    fn_1_410A0();
    fn_17_602C();
}
/* fzgx:end fn_17_3270 */

/* fzgx:begin fn_17_334C */
typedef struct {
    f32 x;
    f32 y;
    u32 z;
} Trio;

typedef struct {
    u8 pad_000[0x108];
    Trio trio;
    f32 f_114;
    f32 f_118;
    f32 f_11c;
    f32 f_120;
    f32 f_124;
} Pool;

typedef struct {
    u8 pad_00[8];
    Trio trio;
    f32 f_14;
    u8 pad_18[6];
    s16 s_1e;
} InterviewData;

extern f32 lbl_17_rodata_0[80];
extern u16 lbl_17_bss_170[20];
extern f32 lbl_8006D21C(u32);
extern void *memset(void *, int, u32);

void fn_17_334C(void) {
    Pool *pool = (Pool *)lbl_17_rodata_0;
    f32 scale;
    f32 value;
    Trio v;
    InterviewData *data;

    scale = pool->f_118 / lbl_8006D21C(0x71c);
    value = pool->f_114 / scale;

    memset(lbl_17_bss_170, 0, 0x28);

    v = pool->trio;
    v.x = pool->f_11c * value;
    v.y = pool->f_120 * value;

    data = (InterviewData *)lbl_17_bss_170;
    data->trio = v;
    data->f_14 = pool->f_124;
    data->s_1e = -0x8000;
}
/* fzgx:end fn_17_334C */

/* fzgx:begin fn_17_38C4 */
typedef struct {
    u8 initialized;
    u8 pad_01[0x13];
    f32 value_14;
    f32 value_18;
    s16 angle_1c;
    s16 angle_1e;
    s16 angle_20;
    s16 angle_22;
    s16 angle_24;
    s16 angle_26;
} InterviewState;

extern InterviewState lbl_17_bss_170;
extern f32 lbl_17_rodata_0[];
extern u8 lbl_1_data_2A7E0[];

extern void fn_1_56000(int, int, int);
extern void fn_1_A71CC(void);
extern f32 fn_1_A6FE8(void);
extern void fn_1_A7024(f32, f32, f32, f32);
extern void lbl_8006D758(void);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E14C(f32);
extern void fn_1_55FC4(f32);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_z(s16);
extern void fn_80072558(void);
extern void fn_1_55FF0(f32);
extern void fn_1_556B8(void *);
extern void fn_1_A722C(void);

void fn_17_38C4(void) {
    f32 *rodata = lbl_17_rodata_0;
    void *object;
    s16 i;
    u8 *base;

    if (!lbl_17_bss_170.initialized)
        return;

    base = *(u8 **)(lbl_1_data_2A7E0 + 0x3c);

    fn_1_56000(1, 7, 1);
    fn_1_A71CC();
    fn_1_A7024(rodata[0x30], fn_1_A6FE8(), rodata[0x64], rodata[0x65]);

    i = 0;
    while (i < 5) {
        object = *(void **)(base + 0x114 + i * 4);
        if (object != 0) {
            lbl_8006D758();
            lbl_8006E0A4((u8 *)&lbl_17_bss_170 + 8);
            lbl_8006E14C(lbl_17_bss_170.value_14);
            fn_1_55FC4(lbl_17_bss_170.value_14);

            switch (i) {
            case 2:
                mathutil_mtxA_rotate_y(lbl_17_bss_170.angle_1e);
                break;
            case 3:
                mathutil_mtxA_rotate_y(lbl_17_bss_170.angle_20);
                mathutil_mtxA_rotate_z(lbl_17_bss_170.angle_22);
                break;
            case 4:
                mathutil_mtxA_rotate_y(lbl_17_bss_170.angle_24);
                mathutil_mtxA_rotate_z(lbl_17_bss_170.angle_26);
                break;
            case 0:
            case 1:
                mathutil_mtxA_rotate_y(lbl_17_bss_170.angle_1c);
                break;
            }

            fn_80072558();
            fn_1_55FF0(lbl_17_bss_170.value_18);
            fn_1_556B8(object);
        }
        i++;
    }

    fn_1_A722C();
    fn_1_56000(1, 3, 1);
}
/* fzgx:end fn_17_38C4 */

/* fzgx:begin fn_17_3C5C pool */
struct fn_17_3C5C_Obj {
    u8 pad_0[5];
    u8 unk_5;
    u8 pad_6[8];
    u8 unk_E;
};

struct fn_17_3C5C_Bss {
    u8 pad_0[0x10];
    struct fn_17_3C5C_Obj *unk_10;
    u8 pad_14[0xC4];
    u32 unk_D8[8];
    u8 unk_F8;
};

extern s16 fn_1_12CCB0(s16, s16);
extern s16 fn_1_12CB04(s16);
extern void fn_17_3A28(s16, s16, s16);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_17_bss_0;
u8 fzgx_obj_lbl_17_bss_1;
u8 lbl_17_bss_2;
u8 lbl_17_bss_3;
u32 lbl_17_bss_3_fill_4[2];
u32 lbl_17_bss_C;
struct fn_17_3C5C_Obj *lbl_17_bss_10;
u32 fzgx_obj_lbl_17_bss_14;
u32 fzgx_obj_lbl_17_bss_18[2];
u32 lbl_17_bss_20;
u32 lbl_17_bss_24[4];
u32 lbl_17_bss_34[8];
u32 fzgx_obj_lbl_17_bss_54;
u32 fzgx_obj_lbl_17_bss_58[2];
u32 fzgx_obj_lbl_17_bss_60[29];
u16 lbl_17_bss_60_fill_D4;
u16 fzgx_obj_lbl_17_bss_D6;
u32 fzgx_obj_lbl_17_bss_D8[8];
u8 lbl_17_bss_D8_20;
u8 lbl_17_bss_D8_fill_F9;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_17_bss_0;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_1;
    s = *(u8 *)&lbl_17_bss_2;
    s = *(u8 *)&lbl_17_bss_3;
    s = *(u8 *)&lbl_17_bss_3_fill_4;
    s = *(u8 *)&lbl_17_bss_C;
    s = *(u8 *)&lbl_17_bss_10;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_14;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_18;
    s = *(u8 *)&lbl_17_bss_20;
    s = *(u8 *)&lbl_17_bss_24;
    s = *(u8 *)&lbl_17_bss_34;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_54;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_58;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_60;
    s = *(u8 *)&lbl_17_bss_60_fill_D4;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_D6;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_D8;
    s = *(u8 *)&lbl_17_bss_D8_20;
    s = *(u8 *)&lbl_17_bss_D8_fill_F9;
}
#pragma section code_type ".text"

void fn_17_3C5C(void) {
    
    s16 i;
    struct fn_17_3C5C_Obj *obj;
    s16 id;
    s32 j;
    u32 *ptr;

    obj = lbl_17_bss_10;
    ptr = fzgx_obj_lbl_17_bss_D8;
    for (j = 0; j < 8; j++) {
        *ptr++ = 0;
    }

    for (i = 0; i < 2; i++) {
        if (i == 0) {
            id = obj->unk_5;
        } else {
            switch (lbl_17_bss_D8_20) {
            case 0:
                obj->unk_E = 1;
                break;
            case 1:
                obj->unk_E = 2;
                break;
            case 2:
                obj->unk_E = 4;
                break;
            default:
                obj->unk_E = 8;
                break;
            }
            fn_17_3A28(0x2c, 1, 1);
            return;
        }
        switch (fn_1_12CB04(id)) {
        case 2:
            fn_17_3A28(id, i, i);
            fn_17_3A28(fn_1_12CCB0(id, 0), 2, i);
            fn_17_3A28(fn_1_12CCB0(id, 1), 3, i);
            break;
        case 1:
            fn_17_3A28(id, i, i);
            fn_17_3A28(fn_1_12CCB0(id, 0), 2, i);
            break;
        case 0:
            fn_17_3A28(id, i, i);
            break;
        }
    }
}
/* fzgx:end fn_17_3C5C */

/* fzgx:begin fn_17_416C */
extern u32 lbl_17_bss_34[8];
extern u32 lbl_17_bss_D8[8];
extern u8 lbl_17_data_63E50[592];
extern u32 lbl_801A6410;

extern void fn_1_9818C(s16 value);
extern void fn_1_8F494(void *arg0);
extern void fn_1_46B4(u32 arg0, u32 arg1, u8 *arg2, s32 arg3);

void fn_17_416C(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        fn_1_9818C((s16)lbl_17_bss_34[i]);
        lbl_17_bss_34[i] = (u32)-1;
        if (lbl_17_bss_D8[i] != 0) {
            fn_1_8F494((void *)lbl_17_bss_D8[i]);
            fn_1_46B4(lbl_801A6410, lbl_17_bss_D8[i], lbl_17_data_63E50, 0x9e8);
            lbl_17_bss_D8[i] = 0;
        }
    }
}
/* fzgx:end fn_17_416C */

/* fzgx:begin fn_17_4214 */
extern u32 lbl_17_rodata_1B8;

struct fn_17_4214_Arg0 {
    u8 pad_0[0x88];
    u32 unk_88;
    u8 pad_8C[0x14];
    u16 unk_A0;
};
struct fn_17_4214_Copy12 { u32 a[3]; };

void fn_17_4214(struct fn_17_4214_Arg0 *arg0) {
    if ((s32)arg0->unk_88 != 4) { return; }
    *(struct fn_17_4214_Copy12 *)((u8 *)(u32)arg0 + 168) = *(struct fn_17_4214_Copy12 *)&lbl_17_rodata_1B8;
    arg0->unk_A0 = 12288;
}
/* fzgx:end fn_17_4214 */

/* fzgx:begin fn_17_4540 */
typedef struct {
    u8 pad[0x88];
    // Hardware-style shared state must be read exactly as published.
    volatile int value;
} InterviewState;

typedef struct {
    u8 pad[0xc];
    // Hardware-style shared state must be read exactly as published.
    volatile s16 value;
} InterviewData;

extern InterviewState *lbl_17_bss_D8;
extern InterviewData lbl_17_bss_60;

void fn_17_4540(void) {
    InterviewState *state = lbl_17_bss_D8;
    InterviewData *data = &lbl_17_bss_60;

    if (state->value != 7)
        return;
    if (data->value == 8)
        return;
}
/* fzgx:end fn_17_4540 */

/* fzgx:begin fn_17_4858 */
extern u32 lbl_17_bss_58[2];
extern u32 lbl_17_bss_198[95];
extern u8 lbl_17_data_63E50[592];
extern u32 lbl_801A6410;

extern void fn_1_8F494(void *arg0);
extern void fn_1_46B4(u32 arg0, u32 arg1, void *arg2, s32 arg3);

void fn_17_4858(void) {
    if ((lbl_17_bss_58[0] & 0x00400000) != 0 &&
        lbl_17_bss_198[0] != 0) {
        fn_1_8F494((void *)lbl_17_bss_198[0]);
        fn_1_46B4(lbl_801A6410, lbl_17_bss_198[0], lbl_17_data_63E50, 0xae9);
        lbl_17_bss_198[0] = 0;
    }
}
/* fzgx:end fn_17_4858 */

/* fzgx:begin fn_17_48D0 */
extern u32 lbl_17_bss_14C;
extern u8 lbl_17_data_0[420];
extern u32 lbl_17_bss_150[4];

extern void fn_1_435C(u32);
extern void fn_1_3F8C(void *, void (*)(void), int, int);
extern void fn_1_789E8(void);
extern void fn_1_9A5CC(void);
extern void fn_1_7E9C4(void);
extern void fn_1_7EAE8(void);
extern void fn_1_78EBC(void);
extern void fn_1_9A7BC(void);
extern void fn_1_7ACDC(int);

void fn_17_48D0(void) {
    u8 *base = lbl_17_data_0 + 0x60000;

    fn_1_435C(lbl_17_bss_14C);
    fn_1_3F8C(base + 0x40ac, fn_1_789E8, 0, 0x15);
    fn_1_3F8C(base + 0x40b8, fn_1_9A5CC, 0, 0x17);
    fn_1_435C(lbl_17_bss_150[0]);
    fn_1_3F8C(base + 0x40c8, fn_1_7E9C4, 0, 4);
    fn_1_3F8C(base + 0x40d0, fn_1_7EAE8, 0, 0x1d);
    fn_1_3F8C(base + 0x40d8, fn_1_78EBC, 0, 7);
    fn_1_3F8C(base + 0x40e4, fn_1_9A7BC, 0, 10);
    fn_1_7ACDC(0x31);
}
/* fzgx:end fn_17_48D0 */

/* fzgx:begin fn_17_49B8 */
// fn_17_49B8: empty in retail (single blr).
void fn_17_49B8(void) {
}
/* fzgx:end fn_17_49B8 */

/* fzgx:begin fn_17_49BC */
extern void fn_1_79100(void);

void fn_17_49BC(void) {
    fn_1_79100();
}
/* fzgx:end fn_17_49BC */

/* fzgx:begin fn_17_4E50 */
// fn_17_4E50: empty in retail (single blr).
void fn_17_4E50(void) {
}
/* fzgx:end fn_17_4E50 */

/* fzgx:begin fn_17_4E54 */
typedef struct InterviewState {
    u8 pad_000[0x8]; void *field_008; u8 pad_00c[0x20]; f32 angle_02c;
    u8 pad_030[0x2d8]; void *object_308;
} InterviewState;
typedef struct InterviewObject {
    u8 pad_000[0x328]; s8 kind_328; u8 pad_329[0x67]; u32 flags_390;
    u8 pad_394[0xc]; void *field_3a0; u8 pad_3a4[0x16]; s16 index_3ba;
} InterviewObject;
typedef struct InterviewValue { void *value_0; } InterviewValue;
typedef struct InterviewEntry { u8 pad_000[0x334]; InterviewValue *value_334; } InterviewEntry;
extern u8 lbl_17_bss_0;
extern f32 lbl_17_rodata_0[6];
extern u8 lbl_17_data_63E50[592];
extern u8 lbl_17_data_64150[76];
extern void lbl_8006DCA4(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern void mathutil_mtxA_rotate_y(s32);
extern void lbl_8006E14C(f32);
extern void fn_1_55FC4(f32);
extern void fn_80072558(void);
extern void lbl_8006DB74(void *);
extern void fn_1_56000(s32, s32, s32);
extern void fn_1_55FF0(f32);
extern void fn_1_14E5E4(void *, f32, s16);
extern void OSPanic(void *, s32, void *, ...);
extern void fn_1_556B8(void *);
extern void lbl_8006DAEC(void);
extern void fn_1_87610(void *, void *);
extern void fn_1_875B4(void *, f32, void *, s8);
extern void lbl_8006DC20(void);
extern void lbl_8006DBAC(void *);
extern void fn_1_FCFA4(void *);

#pragma opt_propagation off
void fn_17_4E54(void) {
    f32 *constants = lbl_17_rodata_0;
    InterviewState *state = (InterviewState *)&lbl_17_bss_0;
    InterviewObject *object;
    InterviewEntry *entry;
    f32 angle = state->angle_02c;
    u8 matrix[0x30];
    s16 index;

    lbl_8006DCA4();
    lbl_8006E0B4(constants[8], constants[131], constants[132]);
    if (state->angle_02c > constants[39]) mathutil_mtxA_rotate_y(0x3000);
    else mathutil_mtxA_rotate_y(0x2000);
    lbl_8006E14C(angle);
    fn_1_55FC4(angle);
    fn_80072558();
    lbl_8006DB74(matrix);
    fn_1_56000(1, 3, 1);
    fn_1_55FF0(constants[6]);
    object = (InterviewObject *)state->object_308;
    if (object != 0) {
        index = object->index_3ba;
        if ((object->flags_390 & 0x04000000) != 0) {
            if (object->field_3a0 == 0) return;
            fn_1_14E5E4(object->field_3a0, constants[6], index);
        } else {
            if (object->kind_328 >= 0x29)
                OSPanic(lbl_17_data_63E50, 0xc20, lbl_17_data_64150);
            entry = (InterviewEntry *)((u8 *)state->object_308 + index * 0xc);
            fn_1_556B8(entry->value_334->value_0);
            lbl_8006DAEC();
            fn_1_87610(state->object_308, state->object_308);
            fn_1_875B4(state->object_308, constants[6],
                       state->object_308,
                       (s8)((InterviewObject *)state->object_308)->index_3ba);
            lbl_8006DC20();
        }
        lbl_8006DBAC(matrix);
        fn_1_FCFA4(state->field_008);
    }
    fn_1_56000(1, 3, 1);
}
#pragma opt_propagation reset
/* fzgx:end fn_17_4E54 */

/* fzgx:begin fn_17_4FE0 */
struct fn_17_4FE0_lbl_17_bss_0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x2FC];
    u32 unk_308;
    u32 unk_30C;
};
struct fn_17_4FE0_lbl_1_bss_6D82C {
    u32 unk_0;
};
struct fn_17_4FE0_lbl_801A6410 {
    u32 unk_0;
};

extern struct fn_17_4FE0_lbl_17_bss_0 lbl_17_bss_0;
extern struct fn_17_4FE0_lbl_1_bss_6D82C lbl_1_bss_6D82C;
extern struct fn_17_4FE0_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_12A734(u32);
extern u32 fn_1_46B4(u32, u32, u32, u32);
extern u32 lbl_17_data_63E50;
extern void fn_1_14DBCC(void *);
extern void fn_1_7F934(void *);
extern void fn_1_FDFF4(void);
extern void fn_80071718(void *);

void fn_17_4FE0(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    struct fn_17_4FE0_lbl_17_bss_0 *p_lbl_17_bss_0;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    u32 v7;
    s32 v8;
    u32 v9;
    u32 v10;
    u32 v11;
    u32 v12;
    u32 t0, t2, t4, t7;
    p_lbl_17_bss_0 = (struct fn_17_4FE0_lbl_17_bss_0 *)&lbl_17_bss_0;
    v0 = p_lbl_17_bss_0->unk_308;
    v1 = v0;
    v2 = arg1;
    v3 = arg3;
    v4 = arg2;
    if (v0 != 0) {
    v1 = *(u32 *)((u8 *)v1 + 804);
    if ((s32)v1 != -1) {
    t0 = fn_1_12A734(v1);
    v1 = t0;
    v1 = p_lbl_17_bss_0->unk_308;
    *(u32 *)((u8 *)v1 + 804) = -1;
    }
    v1 = p_lbl_17_bss_0->unk_308;
    fn_1_7F934((void *)v1);
    v3 = (u32)&lbl_801A6410;
    v2 = p_lbl_17_bss_0->unk_308;
    v4 = (u32)&lbl_17_data_63E50;
    v1 = *(u32 *)((u8 *)v3 + 0);
    v3 = 3134;
    t2 = fn_1_46B4(v1, v2, (u32)v4, v3);
    v1 = t2;
    p_lbl_17_bss_0->unk_308 = 0;
    }
    v5 = p_lbl_17_bss_0->unk_30C;
    v6 = v2;
    v7 = v5;
    v8 = v3;
    v9 = v4;
    if (v5 != 0) {
    fn_1_14DBCC((void *)v7);
    v8 = (u32)&lbl_801A6410;
    v6 = p_lbl_17_bss_0->unk_30C;
    v9 = (u32)&lbl_17_data_63E50;
    v7 = *(u32 *)((u8 *)v8 + 0);
    v8 = 3139;
    t4 = fn_1_46B4(v7, v6, (u32)v9, v8);
    v7 = t4;
    p_lbl_17_bss_0->unk_30C = 0;
    }
    v10 = lbl_1_bss_6D82C.unk_0;
    v11 = v10;
    if (v10 != 0) {
    fn_80071718((void *)v11);
    lbl_1_bss_6D82C.unk_0 = 0;
    }
    v12 = v11;
    if (p_lbl_17_bss_0->unk_8 != 0) {
    fn_1_FDFF4();
    v12 = lbl_801A6410.unk_0;
    t7 = fn_1_46B4(v12, p_lbl_17_bss_0->unk_8, (u32)&lbl_17_data_63E50, 3152);
    v12 = t7;
    }
}
/* fzgx:end fn_17_4FE0 */

/* fzgx:begin fn_17_5FA8 */
typedef struct InterviewState {
    u8 pad_00[0x84];
    s16 field_84;
    u8 pad_86[0x12];
    s16 field_98;
} InterviewState;

typedef struct InterviewGlobals {
    s32 field_00;
    u8 pad_04[0x10];
    InterviewState *field_14;
} InterviewGlobals;

extern InterviewGlobals lbl_17_bss_60;
extern u32 lbl_17_bss_58[2];
extern void fn_17_60B4(void);
extern void fn_1_154F1C(void);
extern void fn_17_8C7C(s32 arg0);

void fn_17_5FA8(void) {
    InterviewGlobals *globals = &lbl_17_bss_60;
    InterviewState *state = globals->field_14;

    fn_17_60B4();
    if (globals->field_00 >= state->field_84 + 0x14a &&
        (lbl_17_bss_58[0] & 0x00800000) != 0 &&
        globals->field_00 < state->field_98) {
        fn_1_154F1C();
        fn_17_8C7C(0x140);
    }
}
/* fzgx:end fn_17_5FA8 */

/* fzgx:begin fn_17_602C */
extern u8 lbl_17_bss_60[118];
extern u8 lbl_17_data_63E50[592];
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, void *, u32);

void fn_17_602C(void) {
    u32 value;

    value = *(u32 *)(lbl_17_bss_60 + 0x10);
    if (value != 0) {
        fn_1_46B4(lbl_801A6410, value, lbl_17_data_63E50, 0xed7);
    }
}
/* fzgx:end fn_17_602C */

/* fzgx:begin fn_17_6078 */
extern u8 lbl_17_bss_D8[34];
extern void fn_17_65F4(void);

typedef struct {
    u8 pad[0x88];
    int state;
} InterviewState;

void fn_17_6078(void) {
    InterviewState *state = *(InterviewState **)lbl_17_bss_D8;

    switch (state->state) {
    case 0x1c:
        fn_17_65F4();
        break;
    default:
        break;
    }
}
/* fzgx:end fn_17_6078 */

/* fzgx:begin fn_17_60B4 */
typedef struct InterviewState {
    s32 value;
    u8 unk04[8];
    s16 status;
    u8 unk0E[6];
    void *data;
} InterviewState;

typedef struct InterviewData {
    u8 unk00[0x84];
    s16 lower_bound;
    u8 unk86[0x12];
    s16 upper_bound;
} InterviewData;

typedef struct InterviewManager {
    u8 unk00[0x18];
    u32 flags;
} InterviewManager;

extern InterviewState lbl_17_bss_60;
extern InterviewManager *lbl_17_bss_D8;
extern void fn_17_613C(void);

void fn_17_60B4(void) {
    InterviewState *state = &lbl_17_bss_60;
    InterviewData *data = state->data;

    if (state->status == 9 &&
        state->value >= data->lower_bound &&
        state->value < data->upper_bound) {
        lbl_17_bss_D8->flags |= 0x08000000;
        fn_17_613C();
    } else {
        lbl_17_bss_D8->flags &= ~0x08000000;
    }
}
/* fzgx:end fn_17_60B4 */

/* fzgx:begin fn_17_66C0 */
typedef struct InterviewState {
    u8 pad[0x88];
    s32 mode;
} InterviewState;

typedef struct InterviewGlobals {
    InterviewState *state;
    u8 *object;
} InterviewGlobals;

extern u8 lbl_17_data_0[420];
extern u8 lbl_17_bss_D8[34];
extern const f32 lbl_17_rodata_1C;
extern u8 lbl_17_bss_2;
extern void fn_1_935E4(u8 *object, u8 *message, const char *text, f32 value);

#pragma opt_propagation off
void fn_17_66C0(void) {
    u8 *table = lbl_17_data_0 + 0x60000;
    InterviewGlobals *globals = (InterviewGlobals *)lbl_17_bss_D8;
    s32 mode = ((InterviewState *)globals->state)->mode;
    u8 *object = globals->object;
    s16 *modes = (s16 *)(table + 0x2c34);

    switch (modes[mode]) {
    case 2:
        fn_1_935E4(object, object + 0x148,
                   (const char *)(table + 0x4384), lbl_17_rodata_1C);
        break;
    case 1:
        fn_1_935E4(object, object + 0x148,
                   (const char *)(table + 0x4398), lbl_17_rodata_1C);
        break;
    case 0:
        fn_1_935E4(object, object + 0x148,
                   (const char *)(table + 0x43a8), lbl_17_rodata_1C);
        break;
    case 3:
        fn_1_935E4(object, object + 0x148,
                   (const char *)(table + 0x43bc), lbl_17_rodata_1C);
        break;
    case 4:
        fn_1_935E4(object, object + 0x148,
                   (const char *)(table + 0x43d4), lbl_17_rodata_1C);
        break;
    }
    lbl_17_bss_2 = 1;
}
#pragma opt_propagation reset
/* fzgx:end fn_17_66C0 */

/* fzgx:begin fn_17_67C4 */
extern u8 lbl_17_bss_0;
extern const f32 lbl_17_rodata_1C;

typedef struct InterviewObject InterviewObject;

typedef struct InterviewRef {
    u8 padding[4];
    InterviewObject *object;
} InterviewRef;

typedef struct InterviewState {
    u8 flags0[2];
    u8 flag2;
    u8 flag3;
    u8 padding[0xd4];
    InterviewRef ref;
} InterviewState;

struct InterviewObject {
    u8 padding[0x150];
    void *data;
};

typedef struct InterviewData {
    u8 padding[0x4c];
    f32 value_a;
    f32 value_b;
} InterviewData;

extern void fn_1_935E4(void *, void *, void *, f32);

#pragma opt_propagation off
void fn_17_67C4(void *arg) {
    InterviewState *state = (InterviewState *)&lbl_17_bss_0;
    InterviewObject *object;
    InterviewData *data;
    u32 ref;

    ref = (u32)state + 0xd8;
    object = *(InterviewObject **)(ref + 4);
    data = (InterviewData *)object->data;
    if (data->value_a == data->value_b) {
        fn_1_935E4(object, (u8 *)object + 0x148, arg, lbl_17_rodata_1C);
        if (state->flag2 != 0)
            state->flag2 = 0;
        if (state->flag3 != 0)
            state->flag3 = 0;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_17_67C4 */

/* fzgx:begin fn_17_6848 */
typedef struct InterviewObject InterviewObject;

struct InterviewObject {
    u8 pad0[0x88];
    void *field88;
    u8 pad8C[0x1c];
    f32 values[3];
    u8 padB4[0x94];
    u8 field148[1];
};

typedef struct InterviewGlobals {
    InterviewObject *object0;
    u8 pad4[4];
    InterviewObject *object8;
    InterviewObject *objectC;
} InterviewGlobals;

extern InterviewGlobals lbl_17_bss_D8;
extern u8 lbl_17_bss_1;
extern const f32 lbl_17_rodata_20;

extern u32 fn_1_12C710(void *arg0);
extern s16 fn_1_12CB04(u32 arg0);
extern void fn_1_935E4(InterviewObject *arg0, void *arg1, void *arg2, f32 arg3);

void fn_17_6848(void *arg0, u8 arg1, f32 arg2) {
    f32 value = arg2;
    InterviewObject *object = lbl_17_bss_D8.object0;
    s16 mode;
    u32 state;

    state = fn_1_12C710(object->field88);
    lbl_17_bss_1 = arg1;
    mode = fn_1_12CB04(state);

    switch (mode) {
    case 2:
        fn_1_935E4(object, object->field148, arg0, value);
        fn_1_935E4(lbl_17_bss_D8.object8, (u8 *)lbl_17_bss_D8.object8 + 0x148, arg0, value);
        fn_1_935E4(lbl_17_bss_D8.objectC, (u8 *)lbl_17_bss_D8.objectC + 0x148, arg0, value);
        object->values[0] = lbl_17_rodata_20;
        object->values[1] = lbl_17_rodata_20;
        object->values[2] = lbl_17_rodata_20;
        {
            InterviewObject *o8 = lbl_17_bss_D8.object8;
            o8->values[0] = lbl_17_rodata_20;
            o8->values[1] = lbl_17_rodata_20;
            o8->values[2] = lbl_17_rodata_20;
        }
        {
            InterviewObject *oC = lbl_17_bss_D8.objectC;
            oC->values[0] = lbl_17_rodata_20;
            oC->values[1] = lbl_17_rodata_20;
            oC->values[2] = lbl_17_rodata_20;
        }
        break;
    case 1:
        fn_1_935E4(object, object->field148, arg0, value);
        fn_1_935E4(lbl_17_bss_D8.object8, (u8 *)lbl_17_bss_D8.object8 + 0x148, arg0, value);
        object->values[0] = lbl_17_rodata_20;
        object->values[1] = lbl_17_rodata_20;
        object->values[2] = lbl_17_rodata_20;
        {
            InterviewObject *o8b = lbl_17_bss_D8.object8;
            o8b->values[0] = lbl_17_rodata_20;
            o8b->values[1] = lbl_17_rodata_20;
            o8b->values[2] = lbl_17_rodata_20;
        }
        break;
    case 0:
        fn_1_935E4(object, object->field148, arg0, value);
        object->values[0] = lbl_17_rodata_20;
        object->values[1] = lbl_17_rodata_20;
        object->values[2] = lbl_17_rodata_20;
        break;
    default:
        break;
    }
}
/* fzgx:end fn_17_6848 */

/* fzgx:begin fn_17_69EC */
typedef struct Sig_fn_1_935E4_Fn935E4Slot {
    u8 pad0[0xa];
    u16 field_a;
} Sig_fn_1_935E4_Fn935E4Slot;

typedef struct Sig_fn_1_935E4_Fn935E4Node {
    u8 pad0[0xa];
    u16 field_a;
    u8 pad_c[6];
    u16 field_12;
    u8 pad14[0x12];
    u8 field_26;
    u8 pad27[1];
    Sig_fn_1_935E4_Fn935E4Slot *field_28;
    u8 pad2c[8];
    Sig_fn_1_935E4_Fn935E4Slot *field_34;
    u8 pad38[0x14];
    u8 field_4c;
} Sig_fn_1_935E4_Fn935E4Node;

typedef struct Sig_fn_1_935E4_Fn935E4Car {
    u8 pad0[0x1c];
    Sig_fn_1_935E4_Fn935E4Node *field_1c;
} Sig_fn_1_935E4_Fn935E4Car;

struct fn_17_69EC_lbl_17_bss_D8 {
    u32 unk_0;
};
extern f32 lbl_17_rodata_1C;
extern struct fn_17_69EC_lbl_17_bss_D8 lbl_17_bss_D8;
extern u8 lbl_17_bss_1;
extern s16 fn_1_12C710(int);
extern s32 fn_1_12CB04(s16);
extern void fn_1_935E4(Sig_fn_1_935E4_Fn935E4Car *, void *, void *, f32);

void fn_17_69EC(void *arg0, f32 farg0) {
    u32 base;
    u32 temp_r31;
    void *temp_r4;

    base = lbl_17_bss_D8.unk_0;
    temp_r4 = (void *)(*(void **)((u8 *)base + 336));
    temp_r31 = base;
    if ((*(f32 *)((u8 *)(temp_r4) + 76)) == (*(f32 *)((u8 *)(temp_r4) + 80))) {
        switch ((s16)fn_1_12CB04(fn_1_12C710(*(u32 *)((u8 *)base + 136)))) {  /* irregular */
        case 2:
            fn_1_935E4((Sig_fn_1_935E4_Fn935E4Car *)((Sig_fn_1_935E4_Fn935E4Car *)(temp_r31)), (void *)(temp_r31 + 0x148), (void *)(arg0), *(f32 *)((u8 *)(&lbl_17_rodata_1C) + 0));
            fn_1_935E4((Sig_fn_1_935E4_Fn935E4Car *)(*(Sig_fn_1_935E4_Fn935E4Car **)((u8 *)(&lbl_17_bss_D8) + 8)), (void *)((u8 *)((*(Sig_fn_1_935E4_Fn935E4Car **)((u8 *)(&lbl_17_bss_D8) + 8))) + 0x148), (void *)(arg0), farg0);
            fn_1_935E4((Sig_fn_1_935E4_Fn935E4Car *)(*(Sig_fn_1_935E4_Fn935E4Car **)((u8 *)(&lbl_17_bss_D8) + 12)), (void *)((u8 *)((*(Sig_fn_1_935E4_Fn935E4Car **)((u8 *)(&lbl_17_bss_D8) + 12))) + 0x148), (void *)(arg0), farg0);
            break;
        case 1:
            fn_1_935E4((Sig_fn_1_935E4_Fn935E4Car *)((Sig_fn_1_935E4_Fn935E4Car *)(temp_r31)), (void *)(temp_r31 + 0x148), (void *)(arg0), *(f32 *)((u8 *)(&lbl_17_rodata_1C) + 0));
            fn_1_935E4((Sig_fn_1_935E4_Fn935E4Car *)(*(Sig_fn_1_935E4_Fn935E4Car **)((u8 *)(&lbl_17_bss_D8) + 8)), (void *)((u8 *)((*(Sig_fn_1_935E4_Fn935E4Car **)((u8 *)(&lbl_17_bss_D8) + 8))) + 0x148), (void *)(arg0), farg0);
            break;
        case 0:
            fn_1_935E4((Sig_fn_1_935E4_Fn935E4Car *)((Sig_fn_1_935E4_Fn935E4Car *)(temp_r31)), (void *)(temp_r31 + 0x148), (void *)(arg0), farg0);
            break;
        }
        (*(u8 *)((u8 *)(&lbl_17_bss_1) + 0)) = 0;
    }
}
/* fzgx:end fn_17_69EC */

/* fzgx:begin fn_17_6B2C */
#include "rel/interview/interview.h"

extern const f32 lbl_17_rodata_1C;
extern u8 lbl_17_bss_3[9];
extern void fn_1_935E4(u8 *object, u8 *message, const char *text, f32 value);

#pragma opt_propagation off
void fn_17_6B2C(void) {
    u8 *table = (u8 *)&lbl_17_data_0 + 0x60000;
    Obj_17_bss_D8 *globals = &lbl_17_bss_D8;
    u32 mode = globals->unk_0->unk_88;
    u8 *object = (u8 *)globals->unk_4;
    s16 *modes = (s16 *)(table + 0x2c34);
    switch (modes[mode]) {
    case 2:
        fn_1_935E4(object, object + 0x148, (const char *)(table + 0x43e8), lbl_17_rodata_1C);
        break;
    case 1:
        fn_1_935E4(object, object + 0x148, (const char *)(table + 0x43fc), lbl_17_rodata_1C);
        break;
    case 0:
        fn_1_935E4(object, object + 0x148, (const char *)(table + 0x440c), lbl_17_rodata_1C);
        break;
    case 3:
        fn_1_935E4(object, object + 0x148, (const char *)(table + 0x4420), lbl_17_rodata_1C);
        break;
    case 4:
        fn_1_935E4(object, object + 0x148, (const char *)(table + 0x4438), lbl_17_rodata_1C);
        break;
    }
    lbl_17_bss_3[0] = 1;
}
#pragma opt_propagation reset
/* fzgx:end fn_17_6B2C */

/* fzgx:begin fn_17_6F30 */
typedef struct InterviewText {
    u8 pad0[0x86];
    u8 text[1];
} InterviewText;

typedef struct InterviewObject {
    u8 pad0[0x14];
    InterviewText *text;
} InterviewObject;

typedef struct InterviewCamera {
    u8 pad0[4];
    u32 flags;
    u8 rest[0x6C];
} InterviewCamera;

typedef struct InterviewSubstate {
    u8 pad0[4];
    void *field4;
    u8 rest[0x18];
} InterviewSubstate;

/* interview.c file-scope objects, in retail order: MWCC addresses them off one section base. */
u8 lbl_17_bss_0;
u8 lbl_17_bss_1;
u8 lbl_17_bss_2;
u8 lbl_17_bss_3;
u32 lbl_17_bss_3__fzgx_offset_1;
u32 lbl_17_bss_3__fzgx_offset_5;
u32 lbl_17_bss_C;
u32 lbl_17_bss_10;
u32 lbl_17_bss_14;
u32 lbl_17_bss_18[2];
u32 lbl_17_bss_20;
u32 lbl_17_bss_24[4];
u32 lbl_17_bss_34[8];
s32 lbl_17_bss_54;
u32 lbl_17_bss_58[2];
InterviewCamera lbl_17_bss_60;
u16 lbl_17_bss_60__fzgx_offset_74;
s16 lbl_17_bss_D6;
InterviewSubstate lbl_17_bss_D8;
u16 lbl_17_bss_D8__fzgx_offset_20;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u32 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = (u32)lbl_17_bss_0;
    s = (u32)lbl_17_bss_1;
    s = (u32)lbl_17_bss_2;
    s = (u32)lbl_17_bss_3;
    s = (u32)lbl_17_bss_3__fzgx_offset_1;
    s = (u32)lbl_17_bss_3__fzgx_offset_5;
    s = (u32)lbl_17_bss_C;
    s = (u32)lbl_17_bss_10;
    s = (u32)lbl_17_bss_14;
    s = (u32)lbl_17_bss_18[0];
    s = (u32)lbl_17_bss_20;
    s = (u32)lbl_17_bss_24[0];
    s = (u32)lbl_17_bss_34[0];
    s = (u32)lbl_17_bss_54;
    s = (u32)lbl_17_bss_58[0];
    s = (u32)lbl_17_bss_60.flags;
    s = (u32)lbl_17_bss_60__fzgx_offset_74;
    s = (u32)lbl_17_bss_D6;
    s = (u32)lbl_17_bss_D8.field4;
    s = (u32)lbl_17_bss_D8__fzgx_offset_20;
}
#pragma section code_type ".text"

extern u8 lbl_17_data_64458[4];
extern u8 lbl_17_data_6445C[140];
extern u32 lbl_1_bss_6EAB4;
extern u32 lbl_1_bss_6EAD0;

extern void fn_1_97204(void *arg0, void *arg1);
extern s32 fn_80083BCC(void *arg0, void *arg1);
extern void fn_8004BF0C(void *arg0, s32 arg1);

void fn_17_6F30(InterviewObject *object) {
    InterviewText *text;
    u8 *value;
    u32 flags;
    s32 result;
    InterviewSubstate *substate;
    InterviewSubstate *handle;

    text = object->text;
    if (text->text[0] == 0) {
        value = lbl_17_data_64458;
    } else {
        u8 *cursor;

        cursor = text->text;
        while (*cursor != 0x3C && *cursor != 0) {
            cursor++;
        }
        *cursor = 0;
        value = text->text;
    }
    substate = &lbl_17_bss_D8;
    fn_1_97204(substate->field4, value);
    result = fn_80083BCC(value, lbl_17_data_6445C);
    flags = lbl_17_bss_58[0];
    if (result == 0) {
        flags = flags | 0x00800000;
    } else {
        flags = flags & ~0x00800000;
    }
    lbl_17_bss_58[0] = flags;
    lbl_17_bss_D6 = -20;
    lbl_1_bss_6EAB4 &= -0x2d;
    handle = *(InterviewSubstate **)&lbl_1_bss_6EAD0;
    fn_8004BF0C(handle->field4, -20);
}
/* fzgx:end fn_17_6F30 */

/* fzgx:begin fn_17_7020 */
typedef struct InterviewObject {
    u8 pad0[0x14];
    struct InterviewText *text;
} InterviewObject;

typedef struct InterviewText {
    u8 pad0[0x9A];
    u8 text[1];
} InterviewText;

extern u8 lbl_17_data_64458[4];
extern u8 lbl_17_bss_D8[34];

extern void fn_1_97204(void *arg0, u8 *arg1);

void fn_17_7020(InterviewObject *object) {
    InterviewText *text;
    u8 *value;

    text = object->text;
    if (text->text[0] == 0) {
        value = lbl_17_data_64458;
    } else {
        u8 *cursor;

        cursor = text->text;
        while (*cursor != 0x3C && *cursor != 0) {
            cursor++;
        }
        *cursor = 0;
        value = text->text;
    }
    fn_1_97204(*(void **)(lbl_17_bss_D8 + 4), value);
}
/* fzgx:end fn_17_7020 */

/* fzgx:begin fn_17_71C0 */
typedef struct InterviewState {
    u8 pad[4];
    u32 flags;
} InterviewState;

void fn_17_71C0(InterviewState *self) {
    self->flags &= ~2;
    self->flags &= 1;
}
/* fzgx:end fn_17_71C0 */

/* fzgx:begin fn_17_71DC */
extern f32 lbl_17_bss_160[4];
extern u8 lbl_17_bss_314[64];
extern const f32 lbl_17_rodata_20;
extern u32 lbl_17_rodata_25C[50];

extern void fn_1_7BCCC(f32 *value);
extern void fn_80035680(u8 *value, f32 a, f32 b, f32 c);
extern void fn_80035690(u8 *value, f32 a, f32 b, f32 c);
extern void fn_80035420(u8 *value, int index, f32 value2);
extern void fn_800356AC(u8 *value, u32 *data);
extern void GXInitLightDistAttn(u8 *value, int index, f32 a, f32 b);
extern void fn_1_7BB80(u8 *value, int index);
extern void fn_1_7BD6C(int value);

void fn_17_71DC(void) {
    u32 data;

    fn_1_7BCCC(lbl_17_bss_160);
    fn_80035680(lbl_17_bss_314, lbl_17_bss_160[0], lbl_17_bss_160[1], lbl_17_bss_160[2]);
    fn_80035690(lbl_17_bss_314, lbl_17_bss_160[0], lbl_17_bss_160[1], lbl_17_bss_160[2]);
    fn_80035420(lbl_17_bss_314, 0, lbl_17_rodata_20);
    data = lbl_17_rodata_25C[0];
    fn_800356AC(lbl_17_bss_314, &data);
    GXInitLightDistAttn(lbl_17_bss_314, 0, 0.0f, 0.0f);
    fn_1_7BB80(lbl_17_bss_314, 1);
    fn_1_7BD6C(1);
}
/* fzgx:end fn_17_71DC */

/* fzgx:begin fn_17_72BC */
// fn_17_72BC: empty in retail (single blr).
void fn_17_72BC(void) {
}
/* fzgx:end fn_17_72BC */

/* fzgx:begin fn_17_72C0 */
#include "rel/interview/interview.h"

typedef struct {
    u8 pad[0x5C];
} File_72C0;

typedef struct {
    u8 pad[0x134];
    u32 unk_134;
} Entry_72C0;

extern int sprintf(char *, const char *, ...);
extern void fn_80006E10(char *);
extern int fn_1_12C930(s16);
extern int fn_1_45730(char *, File_72C0 *);
extern u32 fn_1_45B2C(File_72C0 *);
extern u32 fn_1_4630(u32, u32, char *, int);
extern void fn_1_458A0(File_72C0 *, u32, u32, u32);
extern void fn_1_45850(File_72C0 *);
extern u32 lbl_1_data_20D1C[];
extern u32 lbl_801A6410;

u32 fn_17_72C0(u32 arg0) {
    u8 *base = (u8 *)&lbl_17_data_0 + 0x60000;
    char buf[128];
    Entry_72C0 *q;
    Entry_72C0 *p;
    File_72C0 file;
    u32 name;
    int i;
    char * lab_t0;

    fn_80006E10((char *)(base + 0x4464));
    name = lbl_1_data_20D1C[(s16)fn_1_12C930((s16)arg0)];
    switch (lbl_17_bss_54) {
    case 5:
        lab_t0 = buf;
        sprintf(lab_t0, (char *)(base + 0x4468), name);
        break;
    case 0:
        lab_t0 = buf;
        sprintf(lab_t0, (char *)(base + 0x4474), name);
        break;
    case 1:
        lab_t0 = buf;
        sprintf(lab_t0, (char *)(base + 0x4484), name);
        break;
    case 2:
        lab_t0 = buf;
        sprintf(lab_t0, (char *)(base + 0x4494), name);
        break;
    case 3:
        lab_t0 = buf;
        sprintf(lab_t0, (char *)(base + 0x44a4), name);
        break;
    case 4:
        lab_t0 = buf;
        sprintf(lab_t0, (char *)(base + 0x44b4), name);
        break;
    }
    if (fn_1_45730(buf, &file) == 0) {
        fn_1_45730((char *)(base + 0x44c4), &file);
    }
    {
        const u32 size = (fn_1_45B2C(&file) + 0x1f) & ~0x1f;
        p = (Entry_72C0 *)fn_1_4630(lbl_801A6410, size, (char *)(base + 0x3e50), 0x118f);
        fn_1_458A0(&file, (u32)p, size, 0);
    }
    fn_1_45850(&file);
    q = p;
    for (i = 0; i < 16; i++, q++) {
        q->unk_134 += (u32)p;
    }
    fn_80006E10((char *)(base + 0x4108));
    return (u32)p;
}
/* fzgx:end fn_17_72C0 */

/* fzgx:begin fn_17_74C0 */
extern u8 lbl_17_bss_D8[34];
extern void fn_17_7728(void *);

typedef struct InterviewChild {
    u8 pad_00[0x42];
    s16 value_42;
    s16 value_44;
} InterviewChild;

typedef struct InterviewState {
    u8 pad_00[0x88];
    s32 value_88;
} InterviewState;

typedef struct Interview {
    u8 pad_00[0x0c];
    s16 value_0c;
    u8 pad_0e[0x4a];
    s16 value_58;
} Interview;

void fn_17_74C0(Interview *interview) {
    InterviewState *state = *(InterviewState **)lbl_17_bss_D8;
    InterviewChild *child = (InterviewChild *)((u8 *)interview + 0x18);

    interview->value_58 = 0;
    child->value_42 = interview->value_0c;
    child->value_44 = state->value_88;
    fn_17_7728(child);
}
/* fzgx:end fn_17_74C0 */

/* fzgx:begin fn_17_7728 */
#include "rel/interview/interview.h"

struct fn_17_7728_Arg0 {
 f32 unk_0; u8 pad_4[0x1C]; s16 unk_20; s16 unk_22; s16 unk_24; u8 pad_26[2];
 u32 unk_28,unk_2C,unk_30,unk_34,unk_38,unk_3C;
 s16 unk_40,unk_42,unk_44; u8 pad_46[2]; u32 unk_48,unk_4C,unk_50; f32 unk_54,unk_58;
};
struct Details {u8 pad[6]; s16 unk_6,unk_8; u8 pad_A[0x7A]; s16 unk_84; u8 pad_86[0x10]; s16 unk_96;};
struct Group {u32 unk_0; u8 pad[0x10]; struct Details *unk_14;};
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_17_bss_0;
u8 fzgx_obj_lbl_17_bss_1;
u8 fzgx_obj_lbl_17_bss_2;
u8 fzgx_obj_lbl_17_bss_3;
u8 lbl_17_bss_3__fzgx_offset_1;
u8 lbl_17_bss_3__fzgx_offset_2;
u8 lbl_17_bss_3__fzgx_offset_3;
u8 lbl_17_bss_3__fzgx_offset_4;
u8 lbl_17_bss_3__fzgx_offset_5;
u8 lbl_17_bss_3__fzgx_offset_6;
u8 lbl_17_bss_3__fzgx_offset_7;
u8 lbl_17_bss_3__fzgx_offset_8;
u32 fzgx_obj_lbl_17_bss_C;
u32 fzgx_obj_lbl_17_bss_10;
u32 fzgx_obj_lbl_17_bss_14;
u32 fzgx_obj_lbl_17_bss_18[2];
u32 fzgx_obj_lbl_17_bss_20;
u32 fzgx_obj_lbl_17_bss_24[4];
u32 fzgx_obj_lbl_17_bss_34[8];
u32 fzgx_obj_lbl_17_bss_54;
u32 fzgx_obj_lbl_17_bss_58;
u16 lbl_17_bss_58__fzgx_offset_4;
u16 lbl_17_bss_58__fzgx_offset_6;
struct Group fzgx_obj_lbl_17_bss_60;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_17_bss_0;
    s = fzgx_obj_lbl_17_bss_1;
    s = fzgx_obj_lbl_17_bss_2;
    s = fzgx_obj_lbl_17_bss_3;
    s = lbl_17_bss_3__fzgx_offset_1;
    s = lbl_17_bss_3__fzgx_offset_2;
    s = lbl_17_bss_3__fzgx_offset_3;
    s = lbl_17_bss_3__fzgx_offset_4;
    s = lbl_17_bss_3__fzgx_offset_5;
    s = lbl_17_bss_3__fzgx_offset_6;
    s = lbl_17_bss_3__fzgx_offset_7;
    s = lbl_17_bss_3__fzgx_offset_8;
    s = fzgx_obj_lbl_17_bss_C;
    s = fzgx_obj_lbl_17_bss_10;
    s = fzgx_obj_lbl_17_bss_14;
    s = fzgx_obj_lbl_17_bss_18[0];
    s = fzgx_obj_lbl_17_bss_20;
    s = fzgx_obj_lbl_17_bss_24[0];
    s = fzgx_obj_lbl_17_bss_34[0];
    s = fzgx_obj_lbl_17_bss_54;
    s = fzgx_obj_lbl_17_bss_58;
    s = lbl_17_bss_58__fzgx_offset_4;
    s = lbl_17_bss_58__fzgx_offset_6;
    s = fzgx_obj_lbl_17_bss_60.unk_0;
}
#pragma section code_type ".text"
struct Triple {u32 x,y,z;};
struct Payload {u32 unk_8; struct Triple triple; u32 unk_18,unk_1C,unk_20; f32 unk_24; s16 unk_28; u16 pad;};
struct Entry {s32 unk_0; u32 unk_4; struct Payload payload; u8 pad[0x28];};
extern const f32 lbl_17_rodata_20;
static inline struct Entry *get_entry(s32 mode,s32 kind,s32 index,u32 flags) {
 struct Entry *v3;
 if (flags && lbl_17_bss_58__fzgx_offset_4 < 5) v3=(void *)&lbl_17_data_63BD0;
 else if (flags && lbl_17_bss_58__fzgx_offset_4 >= 9) v3=(void *)&lbl_17_data_63D20;
 else v3=*(struct Entry **)(lbl_17_data_63190 + mode*64 + kind*4);
 if (!v3) return 0;
 if(v3->unk_0 == -1) {lbl_17_bss_3__fzgx_offset_1=1; v3=(void *)&lbl_17_data_0;}
 else lbl_17_bss_3__fzgx_offset_1=0;
 v3+=index;
 if(!v3) return 0;
 return v3;
}
#pragma opt_propagation off
static inline struct Details * fn_17_7728_read_pointer(struct Group * owner) { return owner->unk_14; }
static inline f32 fn_17_7728_read_pointer_(struct Payload * owner) { return owner->unk_24; }
void fn_17_7728(struct fn_17_7728_Arg0 *arg0, u32 lab_unused0, u32 lab_unused1) {
 struct Payload loc;
 struct Triple triple;
 struct Group *group=&fzgx_obj_lbl_17_bss_60;
 struct Details *v0=fn_17_7728_read_pointer(group);
 u32 flags=fzgx_obj_lbl_17_bss_58 & 1;
 struct Entry *v3=get_entry(arg0->unk_44,arg0->unk_42,arg0->unk_40,flags);
 struct Entry *v7=get_entry(arg0->unk_44,arg0->unk_42,arg0->unk_40+1,flags);
    u32 lab_v;
 loc=v3->payload;
 triple=loc.triple;
 *(struct Triple *)&arg0->unk_48=triple;
 arg0->unk_54=lbl_17_rodata_20; arg0->unk_58=lbl_17_rodata_20;
 if(v7->payload.unk_8==0 || v3->unk_0<0 || !v7) {
 arg0->unk_22=v3->unk_0;
 if(lbl_17_bss_3__fzgx_offset_1) {
 switch(arg0->unk_40) {
 case 1: {
 s16 v20=v0->unk_8;
 if(v20<0) arg0->unk_22=v0->unk_6-group->unk_0;
 else arg0->unk_22=v20-group->unk_0;
 if(arg0->unk_22<0) arg0->unk_22=v3->unk_0;
 break;
 }
 case 3:
 if(v0->unk_8<0) arg0->unk_22=v0->unk_84-group->unk_0;
 else arg0->unk_22=v0->unk_96-group->unk_0;
 if(arg0->unk_22<0) arg0->unk_22=v3->unk_0;
 break;
 }
 }
 } else arg0->unk_22=v7->payload.unk_8-v3->payload.unk_8;
 arg0->unk_24=arg0->unk_22;
 arg0->unk_28=triple.x; arg0->unk_2C=triple.y; arg0->unk_30=triple.z;
 arg0->unk_34=loc.unk_18;arg0->unk_38=loc.unk_1C;arg0->unk_3C=loc.unk_20;
    lab_v = loc.unk_28;
 arg0->unk_20=lab_v;arg0->unk_0=fn_17_7728_read_pointer_(&loc);arg0->unk_20=lab_v;
}
#pragma opt_propagation reset
/* fzgx:end fn_17_7728 */

/* fzgx:begin fn_17_802C */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[5] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -10.0f;
    s = 1.0f;
    s = 30.0f;
    s = 0.0f;
    s = 0.10000000149011612f;
    s = 90000.0f;
}
static const u32 fzgx_pool_table3[4] = {0x00FF00FF, 0x808080FF, 0xFFFFFFFF, 0x80808000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 0.20000000298023224f;
}
static const u32 fzgx_pool_table5[3] = {0x82FF0000, 0xFF780000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.02;
    d = 0.1;
    d = 4503599627370496.0;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table7[2] = {0xFFFFFF00, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 1.0;
    d = 10.0;
    d = 0.9;
    s = 0.0006000000284984708f;
    s = 2.0f;
    s = 320.0f;
    s = 205.0f;
    s = 5.0f;
}
static const u32 fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.8;
    s = 250.0f;
    s = 180.0f;
    s = 10.0f;
    s = 200.0f;
    s = 48.0f;
    s = 50.0f;
    s = 75.0f;
}
static const u32 fzgx_pool_table11[3] = {0x00000000, 0x00000000, 0x43480000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6000000238418579f;
}
static const u32 fzgx_pool_table13[5] = {0x000000FF, 0x404040FF, 0x404088FF, 0xAAAAAAFF, 0xFF0000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
}
static const u32 fzgx_pool_table15[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = -0.56;
}
static const u32 fzgx_pool_table17[3] = {0x00000000, 0x00000000, 0xBC23D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.009999999776482582f;
    s = 240.0f;
    s = 650.0f;
    s = -200.0f;
    s = 0.0002099999983329326f;
}
static const u32 fzgx_pool_table19[6] = {0x00000000, 0x00000000, 0xBC23D70A, 0x00000000, 0x00000000, 0xBC23D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const u32 *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.012;
    d = 0.015;
    s = -0.009999999776482582f;
}
static const u32 fzgx_pool_table21[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const u32 *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.013;
    d = 6.450000286102295e-05;
    s = 32768.0f;
    s = 65536.0f;
    s = 1620.0f;
    s = 4096.0f;
    s = 900.0f;
    s = 600.0f;
    s = 174.0f;
    s = 90.0f;
    s = 125.0f;
    s = 1.2000000424450263e-05f;
    s = 0.0010000000474974513f;
    s = 100.0f;
}
static const u32 fzgx_pool_table23[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const u32 *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.0f;
    s = 32767.0f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table25[11] = {0x00000000, 0x00000000, 0x00000000, 0x3E23D70A, 0x00000000, 0x00000000, 0xBFE66666, 0x00000000, 0x00000000, 0xBEA3D70A, 0xC1C00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const u32 *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime26(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.5f;
    s = 0.30000001192092896f;
    s = -0.15000000596046448f;
    s = 7.200000286102295f;
    s = 0.800000011920929f;
    s = -21.0f;
    s = 9.0f;
    s = 0.03999999910593033f;
    s = 1.0399999618530273f;
    s = -1.7000000476837158f;
    s = -24.0f;
    s = 55.0f;
}
static const u32 fzgx_pool_table27[7] = {0x00FF00FF, 0x808080FF, 0xFFFFFFFF, 0x000000FF, 0x00000000, 0x00000000, 0xBC23D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep27(void) { const u32 *volatile cp; cp = fzgx_pool_table27; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime28(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 106.0f;
    s = 175.0f;
    s = 0.699999988079071f;
    s = 37.0f;
    s = -100.0f;
    s = 0.003000000026077032f;
    s = 2.299999952316284f;
    s = -21.1299991607666f;
    s = -1.7999999523162842f;
    s = -4.0f;
}
static const u32 fzgx_pool_table29[7] = {0xFFFFFFFF, 0x00000000, 0x3F59999A, 0x00000000, 0x00000000, 0x3F59999A, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep29(void) { const u32 *volatile cp; cp = fzgx_pool_table29; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime30(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 0.019999999552965164f;
    s = 413.0f;
    s = 640.0f;
    s = 94.0f;
    s = 373.0f;
    s = 67.0f;
    s = 120.0f;
}
#pragma section code_type ".text"

struct bss_s {
    u8 pad_0[0x20];
    u32 unk_20;
    u8 pad_24[0x34];
    u32 unk_58;
    u8 pad_5C[0x9C];
    u8 unk_F8;
    u8 unk_F9;
    u8 unk_FA;
    u8 unk_FB;
    u8 pad_FC[0x14];
    f32 unk_110;
    f32 unk_114;
    u8 pad_118[0x23C];
    f32 unk_354;
};
struct dat_s {
    u8 pad_0[0x28];
    u32 unk_28;
    u8 pad_2C[0x4];
    u32 unk_30;
    u8 pad_34[0x4];
    u32 unk_38;
    s32 unk_3C;
};
struct bss2_s {
    u8 pad_0[0xE2];
    u8 unk_E2;
};

extern struct bss_s lbl_17_bss_0;
extern struct dat_s lbl_17_data_63058;
extern struct bss2_s lbl_1_bss_5138;
extern u32 fn_17_849C(f32);
extern u32 fn_17_8870(f32);
extern u32 fn_17_8B44(f32);
extern u32 fn_17_8F84(void);
extern void fn_17_86C4(f32, f32, f32, f32);
extern void fn_17_87C0(f32);
extern void fn_17_8D28(void);

#pragma opt_propagation off
static inline f32 fn_17_802C_read_pointer(void) { return (0.0f); }
static inline f32 fn_17_802C_read_pointer__(void) { return (1.0f); }
void fn_17_802C(void) {
    struct bss_s *pb;
    struct dat_s *pd;
    s32 v0;
    s32 v1;
    f32 v2;
    struct { f32 value; } v3;
    struct { f32 value; } v4;
    s32 v5;
    f32 v6;
    struct { f32 value; } v9;
    f32 v10;
    s32 v11;
    s32 v12;
    struct { f32 value; } v13;
    struct { f32 value; } v14;
    struct { f32 value; } v15;
    struct { s32 value; } v16;
    f32 v17;
    s32 v22;
    s32 v23;
    u8 v24;
    f32 v25;
    f32 v26;
    s32 v31;
    s32 v32;
    u32 v33;
    f32 v34;
    u32 v36;
    f32 v37;

    pb = (struct bss_s *)&lbl_17_bss_0;
    (void) pb;  /* fzgx: keeps the web at its definition */
    if ((pb->unk_58 & 0x08000000) != 0) {
        fn_17_86C4((320.0f), (413.0f), (640.0f), (94.0f));
    }
    if ((pb->unk_58 & 0x02000000) != 0) {
        fn_17_8D28();
    }
    if ((pb->unk_58 & 0x01000000) != 0) {
        fn_17_8F84();
        fn_17_86C4((320.0f), (373.0f), (640.0f), (67.0f));
    }
    v0 = pb->unk_20;
    v1 = lbl_17_data_63058.unk_28;
    if (v0 >= v1) {
        v2 = fn_17_802C_read_pointer__();
        v3.value = v2 - ((f32)(v1 + 120 - v0) / (120.0f));
        v4.value = (v3.value < fn_17_802C_read_pointer()) ? fn_17_802C_read_pointer() : ((v3.value > v2) ? v2 : v3.value);
        v6 = v4.value;
        v5 = lbl_17_data_63058.unk_30;
        if (v0 >= v5 && pb->unk_F8 != 3) {
            v9.value = (f32)(v5 + 30 - v0) / (30.0f);
            v9.value = (v9.value < fn_17_802C_read_pointer()) ? fn_17_802C_read_pointer() : ((v9.value > fn_17_802C_read_pointer__()) ? fn_17_802C_read_pointer__() : v9.value);
            v6 = v9.value;
        }
        fn_17_87C0(v6);
    }
    v11 = pb->unk_20;
    v12 = lbl_17_data_63058.unk_30;
    if (v11 >= v12 && pb->unk_F8 != 3) {
        v13.value = fn_17_802C_read_pointer__();
        v15.value = fn_17_802C_read_pointer();
        v14.value = v13.value - ((f32)(v12 + 30 - v11) / (30.0f));
        v14.value = (v14.value < v15.value) ? v15.value : ((v14.value > v13.value) ? v13.value : v14.value);
        v17 = v14.value;
        v16.value = lbl_17_data_63058.unk_38;
        if (v11 >= v16.value && (pb->unk_F9 != 0 || pb->unk_FA != 0)) {
            v9.value = (f32)(v16.value + 30 - v11) / (30.0f);
            v9.value = (v9.value < fn_17_802C_read_pointer()) ? fn_17_802C_read_pointer() : ((v9.value > fn_17_802C_read_pointer__()) ? fn_17_802C_read_pointer__() : v9.value);
            v17 = v9.value;
        }
        fn_17_849C(v17);
    } else {
        pb->unk_354 = fn_17_802C_read_pointer();
    }
    pd = (struct dat_s *)&lbl_17_data_63058;
    v22 = pb->unk_20;
    v23 = pd->unk_38;
    if (v22 >= v23 && pb->unk_F9 != 0) {
        v24 = lbl_1_bss_5138.unk_E2;
        if (v22 >= pd->unk_3C) {
            pb->unk_FB = 0;
        } else {
            v25 = fn_17_802C_read_pointer__();
            v26 = v25 - ((f32)(v23 + 30 - v22) / (30.0f));
            v26 = (v26 < fn_17_802C_read_pointer()) ? fn_17_802C_read_pointer() : ((v26 > v25) ? v25 : v26);
            pb->unk_110 = v26;
        }
        if ((s32)v24 != 0) {
            v10 = pb->unk_110 - (0.0399999991f);
            v10 = (v10 < fn_17_802C_read_pointer()) ? fn_17_802C_read_pointer() : ((v10 > fn_17_802C_read_pointer__()) ? fn_17_802C_read_pointer__() : v10);
            pb->unk_110 = v10;
        }
        fn_17_8870(pb->unk_110);
    }
    v31 = pb->unk_20;
    v32 = pd->unk_38;
    v33 = 0;
    if (v31 >= v32 && pb->unk_FA != 0 && pb->unk_F9 == 0) {
        v36 = lbl_1_bss_5138.unk_E2;
        if (v31 >= lbl_17_data_63058.unk_3C) {
            pb->unk_FB = 0;
        } else {
            v37 = fn_17_802C_read_pointer__();
            v34 = v37 - ((f32)(v32 + 30 - v31) / (30.0f));
            v34 = (v34 < fn_17_802C_read_pointer()) ? fn_17_802C_read_pointer() : ((v34 > v37) ? v37 : v34);
            pb->unk_114 = v34;
        }
        if ((s32)v36 != 0) {
            v34 = pb->unk_114 - (0.0399999991f);
            v34 = (v34 < fn_17_802C_read_pointer()) ? fn_17_802C_read_pointer() : ((v34 > fn_17_802C_read_pointer__()) ? fn_17_802C_read_pointer__() : v34);
            pb->unk_114 = v34;
        }
        v33 = fn_17_8B44(pb->unk_114);
    }
    return;
}
#pragma opt_propagation reset
/* fzgx:end fn_17_802C */

/* fzgx:begin fn_17_86C4 */
extern f32 lbl_17_rodata_0[];
extern u32 lbl_1_rodata_26F8[];

extern int fn_1_FA638(void);
extern void fn_1_50190(void*, f32, f32, f32, f32, f32, f32);

typedef struct {
    u32 word04;
    f32 float08;
    f32 float0c;
    f32 float10;
    u32 word14[7];
    f32 float30;
    u32 word34;
    u32 word38[9];
} InterviewParams;

void fn_17_86C4(f32 a, f32 b, f32 c, f32 d) {
    f32* rodata = lbl_17_rodata_0;
    InterviewParams params;

    if (fn_1_FA638()) {
        params = *(InterviewParams*)lbl_1_rodata_26F8;
        params.word04 = 0x00008c08;
        params.float08 = a;
        params.float0c = b;
        params.float10 = rodata[108];
        params.word34 = 10;
        params.float30 = rodata[6];
        fn_1_50190(&params, c, d, rodata[8], rodata[8], rodata[108], rodata[108]);
    }
}
/* fzgx:end fn_17_86C4 */

/* fzgx:begin fn_17_87C0 */
extern f32 lbl_17_rodata_0[];
extern u32 lbl_1_rodata_26F8[];

extern u8 fn_1_B7C00(void);
extern void fn_1_4F734(void*);

typedef struct {
    u32 word04;
    f32 float08;
    f32 float0c;
    f32 float10;
    u32 word14[7];
    f32 float30;
    u32 word34;
    u32 word38[9];
} InterviewParams;

void fn_17_87C0(f32 value) {
    f32* rodata = lbl_17_rodata_0;
    InterviewParams params;

    if (!fn_1_B7C00()) {
        params = *(InterviewParams*)lbl_1_rodata_26F8;
        params.word04 = 0x00008c03;
        params.float08 = rodata[168];
        params.float0c = rodata[169];
        params.float10 = rodata[108];
        params.float30 = value;
        params.word34 = 5;
        fn_1_4F734(&params.word04);
    }
}
/* fzgx:end fn_17_87C0 */

/* fzgx:begin fn_17_8C7C */
#include "font.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[5] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -10.0f;
    s = 1.0f;
    s = 30.0f;
    s = 0.0f;
    s = 0.10000000149011612f;
    s = 90000.0f;
}
static const u32 fzgx_pool_table3[4] = {0x00FF00FF, 0x808080FF, 0xFFFFFFFF, 0x80808000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 0.20000000298023224f;
}
static const u32 fzgx_pool_table5[3] = {0x82FF0000, 0xFF780000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.02;
    d = 0.1;
    d = 4503599627370496.0;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table7[2] = {0xFFFFFF00, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 1.0;
    d = 10.0;
    d = 0.9;
    s = 0.0006000000284984708f;
    s = 2.0f;
    s = 320.0f;
    s = 205.0f;
    s = 5.0f;
}
static const u32 fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.8;
    s = 250.0f;
    s = 180.0f;
    s = 10.0f;
    s = 200.0f;
    s = 48.0f;
    s = 50.0f;
    s = 75.0f;
}
static const u32 fzgx_pool_table11[3] = {0x00000000, 0x00000000, 0x43480000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6000000238418579f;
}
static const u32 fzgx_pool_table13[5] = {0x000000FF, 0x404040FF, 0x404088FF, 0xAAAAAAFF, 0xFF0000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
}
static const u32 fzgx_pool_table15[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = -0.56;
}
static const u32 fzgx_pool_table17[3] = {0x00000000, 0x00000000, 0xBC23D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.009999999776482582f;
    s = 240.0f;
    s = 650.0f;
    s = -200.0f;
    s = 0.0002099999983329326f;
}
static const u32 fzgx_pool_table19[6] = {0x00000000, 0x00000000, 0xBC23D70A, 0x00000000, 0x00000000, 0xBC23D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const u32 *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.012;
    d = 0.015;
    s = -0.009999999776482582f;
}
static const u32 fzgx_pool_table21[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const u32 *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.013;
    d = 6.450000286102295e-05;
    s = 32768.0f;
    s = 65536.0f;
    s = 1620.0f;
    s = 4096.0f;
    s = 900.0f;
    s = 600.0f;
    s = 174.0f;
    s = 90.0f;
    s = 125.0f;
    s = 1.2000000424450263e-05f;
    s = 0.0010000000474974513f;
    s = 100.0f;
}
static const u32 fzgx_pool_table23[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const u32 *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.0f;
    s = 32767.0f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table25[11] = {0x00000000, 0x00000000, 0x00000000, 0x3E23D70A, 0x00000000, 0x00000000, 0xBFE66666, 0x00000000, 0x00000000, 0xBEA3D70A, 0xC1C00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const u32 *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime26(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.5f;
    s = 0.30000001192092896f;
    s = -0.15000000596046448f;
    s = 7.200000286102295f;
    s = 0.800000011920929f;
    s = -21.0f;
    s = 9.0f;
    s = 0.03999999910593033f;
    s = 1.0399999618530273f;
    s = -1.7000000476837158f;
    s = -24.0f;
    s = 55.0f;
}
static const u32 fzgx_pool_table27[7] = {0x00FF00FF, 0x808080FF, 0xFFFFFFFF, 0x000000FF, 0x00000000, 0x00000000, 0xBC23D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep27(void) { const u32 *volatile cp; cp = fzgx_pool_table27; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime28(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 106.0f;
    s = 175.0f;
    s = 0.699999988079071f;
    s = 37.0f;
    s = -100.0f;
    s = 0.003000000026077032f;
    s = 2.299999952316284f;
    s = -21.1299991607666f;
    s = -1.7999999523162842f;
    s = -4.0f;
}
static const u32 fzgx_pool_table29[7] = {0xFFFFFFFF, 0x00000000, 0x3F59999A, 0x00000000, 0x00000000, 0x3F59999A, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep29(void) { const u32 *volatile cp; cp = fzgx_pool_table29; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime30(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 0.019999999552965164f;
    s = 413.0f;
    s = 640.0f;
    s = 94.0f;
    s = 373.0f;
    s = 67.0f;
    s = 120.0f;
}
static const u32 fzgx_pool_table31[1] = {0xFFC800FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep31(void) { const u32 *volatile cp; cp = fzgx_pool_table31; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime32(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 20.0f;
    s = 312.0f;
    s = 404.0f;
    s = -22.0f;
    s = 238.0f;
    s = 1.399999976158142f;
    s = 146.0f;
    s = 303.0f;
    s = 308.0f;
    s = 340.0f;
    s = 330.0f;
    s = 185.0f;
    s = 242.0f;
    s = 270.0f;
    s = 412.0f;
}
#pragma section code_type ".text"

struct Copy88 {
    u32 a[22];
};

struct RoData {
    u8 pad_0[0x18];
    f32 unk_18;
    u8 pad_1C[0x4C];
    f64 unk_68;
    u8 pad_70[0x2C];
    f32 unk_9C;
    u8 pad_A0[0x234];
    f32 unk_2D4;
};

extern int fn_1_4F734(FontDrawPacket *);
extern u32 lbl_1_rodata_26F8;
extern struct RoData lbl_17_rodata_0;

// Places the interview prompt glyph for the given slot: seeds a font packet
// from the shared template, then fills in the cell position and cell size.
#pragma opt_common_subs off
void fn_17_8C7C(s16 arg0) {
    struct Copy88 loc_8;
    u8 *rodata = (u8 *)&lbl_17_rodata_0;

    loc_8 = *(struct Copy88 *)&lbl_1_rodata_26F8;
    loc_8.a[0] = 0x10000 - 0x7400;
    *(f32 *)((u8 *)&loc_8 + 4) = arg0;
    *(f32 *)((u8 *)&loc_8 + 8) = (412.0f);
    *(f32 *)((u8 *)&loc_8 + 12) = (2.0f);
    *(f32 *)((u8 *)&loc_8 + 16) = (1.0f);
    *(f32 *)((u8 *)&loc_8 + 20) = (1.0f);
    loc_8.a[12] = 10;
    fn_1_4F734((FontDrawPacket *)&loc_8);
}
#pragma opt_common_subs reset
/* fzgx:end fn_17_8C7C */

/* fzgx:begin fn_17_8D28 */
#include "font.h"

typedef struct {
    u32 words[22];
} Sig_fn_1_51914_fn_1_51914_state;


struct fn_17_8D28_Copy88 { u32 a[22]; };
struct fn_17_8D28_lbl_17_rodata_0 {
    u8 pad_0[0x20];
    f32 unk_20;
    u8 pad_24[0x84];
    f32 unk_A8;
    u8 pad_AC[0x104];
    f32 unk_1B0;
    u8 pad_1B4[0x124];
    f32 unk_2D8;
    f32 unk_2DC;
    f32 unk_2E0;
};

extern int fn_1_4F734(FontDrawPacket *);
extern struct fn_17_8D28_lbl_17_rodata_0 lbl_17_rodata_0;
extern u32 fn_17_8E68(u32, u32);
extern u32 lbl_1_rodata_26F8;
extern void fn_1_51914(const Sig_fn_1_51914_fn_1_51914_state *);
extern void fn_1_51990(void *);

void fn_17_8D28(void) {
    struct fn_17_8D28_lbl_17_rodata_0 *p_lbl_17_rodata_0;
    f32 v1;
    f32 v0;
    f32 v3;
    f32 v2;
    struct fn_17_8D28_Copy88 loc_8;
    /* frame */
    p_lbl_17_rodata_0 = (struct fn_17_8D28_lbl_17_rodata_0 *)&lbl_17_rodata_0;
    loc_8 = *(struct fn_17_8D28_Copy88 *)&lbl_1_rodata_26F8;
    loc_8.a[0] = (0x10000 - 29689);
    fn_1_51914((const Sig_fn_1_51914_fn_1_51914_state *)&loc_8);
    loc_8 = *(struct fn_17_8D28_Copy88 *)&lbl_1_rodata_26F8;
    v0 = p_lbl_17_rodata_0->unk_20;
    v1 = p_lbl_17_rodata_0->unk_2D8;
    loc_8.a[0] = (0x10000 - 29694);
    *(f32 *)((u8 *)&loc_8 + 4) = v0;
    *(f32 *)((u8 *)&loc_8 + 8) = v1;
    *(f32 *)((u8 *)&loc_8 + 12) = p_lbl_17_rodata_0->unk_A8;
    loc_8.a[12] = 5;
    fn_1_51990((void *)&loc_8);
    fn_1_4F734((FontDrawPacket *)&loc_8);
    loc_8 = *(struct fn_17_8D28_Copy88 *)&lbl_1_rodata_26F8;
    v2 = p_lbl_17_rodata_0->unk_2DC;
    v3 = p_lbl_17_rodata_0->unk_2E0;
    loc_8.a[0] = (0x10000 - 29695);
    *(f32 *)((u8 *)&loc_8 + 4) = v2;
    *(f32 *)((u8 *)&loc_8 + 8) = v3;
    *(f32 *)((u8 *)&loc_8 + 12) = p_lbl_17_rodata_0->unk_1B0;
    loc_8.a[12] = 5;
    fn_1_4F734((FontDrawPacket *)&loc_8);
    fn_17_8E68(28, 64);
}
/* fzgx:end fn_17_8D28 */

/* fzgx:begin fn_17_8E68 */
extern char lbl_17_data_644E8[16];
extern u8 lbl_17_data_644F8[102];

typedef s64 OSTime;
typedef struct OSCalendarTime {
    s32 sec;
    s32 min;
    s32 hour;
    s32 mday;
    s32 mon;
    s32 year;
    s32 wday;
    s32 yday;
    s32 msec;
    s32 usec;
} OSCalendarTime;

extern OSTime OSGetTime(void);
extern void OSTicksToCalendarTime(OSTime, OSCalendarTime *);
extern void fn_1_49410(void);
extern void fn_1_494DC(s32);
extern void fn_1_495B0(u32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495FC(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_4AE0C(const char *, ...);

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
}
static const u32 fzgx_pool_table2[4] = {0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -10.0f;
    s = 1.0f;
    s = 30.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
    s = 90000.0f;
}
static const u32 fzgx_pool_table6[4] = {0x00FF00FF, 0x808080FF, 0xFFFFFFFF, 0x80808000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 0.20000000298023224f;
}
static const u32 fzgx_pool_table8[3] = {0x82FF0000, 0xFF780000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.02;
    d = 0.1;
    d = 4503599627370496.0;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table10[2] = {0xFFFFFF00, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 1.0;
    d = 10.0;
    d = 0.9;
    s = 0.0006000000284984708f;
    s = 2.0f;
    s = 320.0f;
    s = 205.0f;
    s = 5.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.8;
    s = 250.0f;
    s = 180.0f;
    s = 10.0f;
    s = 200.0f;
    s = 48.0f;
    s = 50.0f;
    s = 75.0f;
}
static const u32 fzgx_pool_table14[3] = {0x00000000, 0x00000000, 0x43480000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6000000238418579f;
}
static const u32 fzgx_pool_table16[1] = {0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.003967046737671f;
    s = 3.008361577987671f;
}
static const u32 fzgx_pool_table18[2] = {0xAAAAAAFF, 0xFF0000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = -0.56;
}
static const u32 fzgx_pool_table22[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.009999999776482582f;
    s = 0.009999999776482582f;
    s = 240.0f;
    s = 650.0f;
    s = -200.0f;
    s = 0.0002099999983329326f;
}
static const u32 fzgx_pool_table24[6] = {0x00000000, 0x00000000, 0xBC23D70A, 0x00000000, 0x00000000, 0xBC23D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.012;
    d = 0.015;
}
static const u32 fzgx_pool_table26[2] = {0xBC23D70A, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.013;
    d = 6.450000286102295e-05;
    s = 32768.0f;
    s = 65536.0f;
    s = 1620.0f;
    s = 4096.0f;
    s = 900.0f;
    s = 600.0f;
    s = 174.0f;
    s = 90.0f;
    s = 125.0f;
    s = 1.2000000424450263e-05f;
    s = 0.0010000000474974513f;
    s = 100.0f;
}
static const u32 fzgx_pool_table28[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.0f;
    s = 32767.0f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table30[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.1599999964237213f;
}
static const u32 fzgx_pool_table32[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.7999999523162842f;
}
static const u32 fzgx_pool_table34[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.3199999928474426f;
    s = -24.0f;
    s = 1.5f;
    s = 0.30000001192092896f;
    s = -0.15000000596046448f;
    s = 7.200000286102295f;
    s = 0.800000011920929f;
    s = -21.0f;
    s = 9.0f;
    s = 0.03999999910593033f;
    s = 1.0399999618530273f;
    s = -1.7000000476837158f;
}
static const u32 fzgx_pool_table36[1] = {0xC1C00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const u32 *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime37(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 55.0f;
}
static const u32 fzgx_pool_table38[7] = {0x00FF00FF, 0x808080FF, 0xFFFFFFFF, 0x000000FF, 0x00000000, 0x00000000, 0xBC23D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const u32 *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime39(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 106.0f;
    s = 175.0f;
    s = 0.699999988079071f;
}
#pragma section code_type ".text"
void fn_17_8E68(s16 arg0, s16 arg1) {
    OSCalendarTime time;

    OSTicksToCalendarTime(OSGetTime(), &time);
    fn_1_49410();
    fn_1_494DC(6);
    fn_1_495B0(0x80000000); /* fzgx-allow: A1 non-address bit pattern */
    fn_1_4954C(2.0f);
    fn_1_4955C(0.7f, 0.7f);
    fn_1_495FC();
    fn_1_496FC((f32)arg0, (f32)arg1);
    fn_1_49590(0.5f);
    if (time.hour < 12) {
        fn_1_4AE0C(lbl_17_data_644E8, time.mon + 1, time.mday,
                   (s16)time.hour, time.min);
    } else {
        fn_1_4AE0C((char *)lbl_17_data_644F8, time.mon + 1, time.mday,
                   (s16)(time.hour - 12), time.min);
    }
}
/* fzgx:end fn_17_8E68 */
