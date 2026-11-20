#include "types.h"


/* --- dol/fn_8004F74C.c --- */
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

/* --- dol/fn_8004F818.c --- */
extern void fn_800474E4(char *);
extern char lbl_80091258[];
extern char lbl_8009127C[];
extern u32 lbl_80186768[];
extern char *strncpy(char *, const char *, size_t);

typedef struct {
    u8 pad0[8];
    u32 count;
    u8 padC[3];
    s8 type;
    u8 pad10[0x100];
    u32 field_110;
    u32 field_114;
} Entry;

s32 fn_8004F818(s32 arg0, s32 arg1, char *arg2, u32 *arg3, u32 *arg4, u32 *arg5) {
    s32 result;
    u32 *vals;
    s32 i;
    Entry *entry;
    u32 sum;

    if (arg0 < 0 || arg0 >= 0x100) {
        fn_800474E4(lbl_80091258);
        result = -3;
    } else if ((Entry *)lbl_80186768[arg0] == 0) {
        fn_800474E4(lbl_80091258);
        result = -3;
    } else if (arg1 < 0 || arg1 >= (s32)((Entry *)lbl_80186768[arg0])->count) {
        fn_800474E4(lbl_8009127C);
        result = -3;
    } else {
        result = 0;
    }

    if (result < 0) {
        *arg3 = 0;
        *arg4 = -1;
        *arg5 = -1;
        return result;
    }

    entry = (Entry *)lbl_80186768[arg0];
    if (entry->type == 1) {
        vals = (u32 *)((u8 *)entry + 0x11C);
        sum = *(u32 *)((u8 *)entry + 0x118);
        for (i = 0; i < arg1; i++) {
            sum += vals[i];
        }
        *arg5 = vals[arg1];
    } else {
        u16 *vals16 = (u16 *)((u8 *)entry + 0x11A);
        sum = *(u16 *)((u8 *)entry + 0x118);
        for (i = 0; i < arg1; i++) {
            sum += vals16[i];
        }
        *arg5 = vals16[arg1];
    }
    strncpy(arg2, (char *)entry + 0x10, 0x100);
    *arg3 = *(u32 *)((u8 *)entry + 0x110);
    *arg4 = *(u32 *)((u8 *)entry + 0x114) + sum;
    return result;
}
