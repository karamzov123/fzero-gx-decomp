#include "types.h"


/* --- dol/fn_8004F74C.c --- */
extern volatile const u32 lbl_80091250[]; /* Preserve the retail read of the version data. */

struct Fn8004F74CState {
    s32 field_0;
    s32 field_4;
    u32 field_8;
    u32 field_C;
    u32 field_10;
    u8 field_14[0x20];
    u8 field_34[0x100];
    u32 field_134;
    u8 field_138[0x400];
    u8 field_538[0x440];
};

extern struct Fn8004F74CState lbl_80186630;
extern void* memset(void* dst, int value, u32 size);

void fn_8004F74C(void) {
    struct Fn8004F74CState* state;

    state = &lbl_80186630;
    (void)lbl_80091250[0];
    if (state->field_0 == 0) {
        memset(state->field_538, 0, 0x440);
        memset(state->field_138, 0, 0x400);
        memset(state->field_34, 0xff, 0x100);
        memset(state->field_14, 0, 0x20);
        state->field_10 = 0;
        state->field_134 = 0;
        state->field_C = 0;
        state->field_8 = 0;
        state->field_4 = -1;
    }
    state->field_0++;
}

/* --- dol/fn_8004F7F8.c --- */
extern u32 DCInvalidateRange(void);

void fn_8004F7F8(void) {
    DCInvalidateRange();
}
