/* Non-matching: best partial attempt (84.49% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct Fn_17_6C8_RecA {
    f32 f_18;
    u8 pad_00[20];
    u8 pad_1C[0x1C];
    s16 f_38;
    u8 pad_3A[0x2];
    s32 f_3C;
    u8 pad_3E[0x2];
    u32 f_40;
    u16 f_44;
    u32 f_48;
    u32 f_4C;
    u16 f_50;
    u32 f_54;
    s16 f_58;
} Fn_17_6C8_RecA;

typedef struct Fn_17_6C8_RecB {
    u8 pad_00[0x40];
    s16 f_40;
} Fn_17_6C8_RecB;

typedef struct Fn_17_6C8_State {
    u8 pad_00[0x10];
    u32 f_10;
    u8 pad_14[0x4];
    u32 f_18;
    u32 f_1C;
    u8 f_20;
    u8 pad_24[0x34];
    u32 flags_58;
    u16 state_5C;
    u8 pad_5E[0x2];
    Fn_17_6C8_RecA rec_60;
    u8 pad_BC[0x18];
    s16 f_D4;
    s16 f_D6;
    u32 f_D8;
    u32 f_DC;
    u8 pad_E0[0x18];
    u8 f_F8;
} Fn_17_6C8_State;

typedef struct Fn_17_6C8_SrcBD0 {
    u8 pad_00[0xB0];
    u32 f_B0;
    u32 f_B4;
    u32 f_B8;
    u32 f_BC;
    u32 f_C0;
    u32 f_C4;
    u32 f_C8;
    u32 f_CC;
    u32 f_D0;
} Fn_17_6C8_SrcBD0;

typedef struct Fn_17_6C8_SrcD20 {
    u8 pad_00[0x80];
    u32 f_80;
    u32 f_84;
    u32 f_88;
    u32 f_8C;
    u32 f_90;
    u32 f_94;
    u32 f_98;
    u32 f_9C;
    u32 f_A0;
} Fn_17_6C8_SrcD20;

typedef struct Fn_17_6C8_Table {
    u8 pad_00[0x10];
    u32 f_10;
    u8 pad_14[0x14];
    u32 f_28;
    u8 pad_2C[0x4];
    u32 f_30;
} Fn_17_6C8_Table;

typedef struct Fn_17_6C8_Cam {
    u32 pad_0;
    u32 f_4;
    u32 f_8;
    u32 f_C;
    u32 f_10;
    u32 f_14;
    u32 f_18;
    f32 f_1C;
    s16 f_20;
} Fn_17_6C8_Cam;

typedef struct Fn_17_6C8_CamF {
    u32 pad_0;
    f32 f_4;
    u32 f_8;
    f32 f_C;
    f32 f_10;
    u32 pad_14;
    u32 pad_18;
    f32 f_1C;
    s16 f_20;
} Fn_17_6C8_CamF;

typedef struct Fn_17_6C8_Target {
    u8 pad_00[0xA8];
    f32 f_A8;
    f32 f_AC;
    f32 f_B0;
} Fn_17_6C8_Target;

typedef struct Fn_17_6C8_Mode {
    u8 pad_00[0xE2];
    s8 f_E2;
} Fn_17_6C8_Mode;

extern Fn_17_6C8_State lbl_17_bss_0;
extern Fn_17_6C8_SrcBD0 lbl_17_data_63BD0;
extern Fn_17_6C8_SrcD20 lbl_17_data_63D20;
extern Fn_17_6C8_Table lbl_17_data_63058;
extern Fn_17_6C8_Mode lbl_1_bss_5138;
extern const f32 lbl_17_rodata_18;
extern s16 lbl_1_bss_968;
extern u16 lbl_1_bss_96A;
extern u32 lbl_1_bss_6EAB4;
extern u32 lbl_1_bss_6EAD0;

extern void fn_1_9724C(u32);
extern void fn_17_71C0(Fn_17_6C8_RecA *);
extern u32 fn_17_3F0(void);
extern Fn_17_6C8_Cam *camera_get_state_object(void);
extern void fn_8004BF0C(void *, s32);
extern void fn_1_4A00(u32, u32, void *);

#pragma opt_dead_assignments off
#pragma opt_propagation off
void fn_17_6C8(void) {
    u32 fzgx_value;
    Fn_17_6C8_State *state = &lbl_17_bss_0;
    Fn_17_6C8_RecA *rec;
    Fn_17_6C8_RecB *tail;
    Fn_17_6C8_Cam *cam;
    Fn_17_6C8_Target *target;
    void **pair;
    u32 flags;
    u32 v[9];
    u32 lab_t0;

    flags = state->flags_58;
    if (flags & 0x200000) {
        lbl_1_bss_968 = 0xA;
    } else if ((flags & 0x80000000) &&
               (state->state_5C < 4 || (state->state_5C > 5 && state->state_5C < 0xC))) {
        rec = &state->rec_60;
        tail = (Fn_17_6C8_RecB *)&rec->f_18;
        if (state->state_5C < 4) {
            Fn_17_6C8_SrcBD0 *src = &lbl_17_data_63BD0;
            rec->f_58 = 2;
            v[0] = src->f_B0;
            v[1] = src->f_B4;
            v[2] = src->f_B8;
            v[3] = src->f_BC;
            v[4] = src->f_C0;
            v[5] = src->f_C4;
            v[6] = src->f_C8;
            v[7] = src->f_CC;
            v[8] = src->f_D0;
            state->state_5C = 4;
            state->f_1C = lbl_17_data_63058.f_10;
            state->f_D4 = -0x5F;
            state->f_D6 = -0x14;
            lab_t0 = state->f_D8;
            fn_1_9724C(lab_t0);
            lab_t0 = state->f_DC;
            fn_1_9724C(lab_t0);
        } else {
            Fn_17_6C8_SrcD20 *src = &lbl_17_data_63D20;
            v[7] = src->f_84;
            v[8] = src->f_A0;
            rec->f_38 = *(s16 *)&v[8];
            state->state_5C = 0xC;
            state->f_20 = lbl_17_data_63058.f_30;
            rec->f_58 = 1;
            rec->f_3C = 0;
            rec->f_40 = src->f_88;
            rec->f_44 = src->f_8C;
            rec->f_48 = src->f_90;
            fzgx_value = src->f_94;
            rec->f_4C = fzgx_value;
            rec->f_50 = src->f_9C;
            rec->f_54 = src->f_80;
            rec->f_18 = *(f32 *)&v[7];
            rec->f_38 = *(s16 *)&v[8];
            v[0] = src->f_80;
            v[1] = src->f_88;
            v[2] = src->f_8C;
            v[3] = src->f_90;
            v[4] = src->f_94;
            v[5] = src->f_9C;
            v[6] = src->f_80;
            state->f_D4 = -0x3E7;
            state->f_D6 = -0x3E7;
            fn_17_71C0(rec);
            lab_t0 = state->f_D8;
            fn_1_9724C(lab_t0);
            lab_t0 = state->f_DC;
            fn_1_9724C(lab_t0);
        }
        cam = camera_get_state_object();
        cam->f_4 = v[1];
        cam->f_8 = v[2];
        cam->f_C = v[3];
        cam->f_10 = v[4];
        cam->f_14 = v[5];
        cam->f_18 = v[6];
        cam->f_20 = *(s16 *)&v[8];
        cam->f_1C = *(f32 *)&v[7];
        if (state->flags_58 & 0x80000000) {
            if (state->state_5C < 5 && tail->f_40 >= 2) {
                target = *(Fn_17_6C8_Target **)&state->f_DC;
                ((Fn_17_6C8_CamF *)cam)->f_4 = target->f_A8;
                ((Fn_17_6C8_CamF *)cam)->f_C = target->f_B0 - lbl_17_rodata_18;
                ((Fn_17_6C8_CamF *)cam)->f_10 = target->f_A8;
            }
        }
        lbl_1_bss_6EAB4 &= -0x2D;
        fn_8004BF0C(*(void **)&lbl_1_bss_6EAD0, state->f_D4);
        pair = *(void ***)&lbl_1_bss_6EAD0;
        fn_8004BF0C(pair[1], state->f_D6);
        fn_1_4A00(1, 0x1E, (void *)state->f_18);
    } else if (!(flags & 0x20000000)) {
        if (state->f_F8 == 3) {
            fn_17_3F0();
        } else if (lbl_1_bss_5138.f_E2 == 0) {
            lbl_1_bss_968 = *(u8 *)((u8 *)state->f_10 + 0x190);
        }
    } else {
        lbl_1_bss_96A = 0xC5;
    }
}
#pragma opt_propagation reset

#pragma opt_dead_assignments reset

