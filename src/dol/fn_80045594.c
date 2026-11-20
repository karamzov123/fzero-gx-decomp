#include "types.h"


/* --- dol/fn_80045594.c --- */
/* --- dol/fn_80045594.c --- */
struct fn_80045594_Arg0 {
    u8 pad_0[0x14];
    u32 unk_14;
};

u32 fn_80045594(struct fn_80045594_Arg0 *arg0) {
    return arg0->unk_14;
}

/* --- dol/fn_8004559C.c --- */
typedef struct Fn8004559CObject {
    u8 pad[0x98];
    s16 value;
} Fn8004559CObject;

s16 fn_8004559C(Fn8004559CObject *self) {
    return self->value;
}

/* --- dol/fn_800455A4.c --- */
struct fn_800455A4_Arg0 {
    u8 pad_0[0x3C];
    u32 unk_3C;
};

u32 fn_800455A4(struct fn_800455A4_Arg0 *arg0) {
    return arg0->unk_3C;
}

/* --- dol/fn_800455AC.c --- */
struct fn_800455AC_Arg0 {
    u8 pad_0[0x78];
    u32 unk_78;
    u32 unk_7C;
};

void fn_800455AC(struct fn_800455AC_Arg0 *arg0, u32 arg1, u32 arg2) {
    arg0->unk_78 = arg1;
    arg0->unk_7C = arg2;
}

/* --- dol/fn_800455B8.c --- */
struct fn_800455B8_Arg1 {
    u16 type;
};

extern s32 fn_800456A0(void *arg0);
extern s32 fn_80045FEC(struct fn_800455B8_Arg1 *arg0);
extern s32 fn_800462F8(void *arg0, struct fn_800455B8_Arg1 *arg1, void *arg2);
extern s32 fn_80042568(struct fn_800455B8_Arg1 *arg0);
extern s32 fn_80043050(void *arg0, struct fn_800455B8_Arg1 *arg1, void *arg2);
extern s32 fn_80043CCC(struct fn_800455B8_Arg1 *arg0);
extern s32 fn_80043B48(void *arg0, struct fn_800455B8_Arg1 *arg1, void *arg2);
extern s32 fn_80044C0C(struct fn_800455B8_Arg1 *arg0);
extern s32 fn_80044A94(void *arg0, struct fn_800455B8_Arg1 *arg1, void *arg2);

s32 fn_800455B8(void *arg0, struct fn_800455B8_Arg1 *arg1, void *arg2) {
    if (arg1->type == 0x8000) {
        return fn_800456A0(arg0);
    }
    if (fn_80045FEC(arg1)) {
        return fn_800462F8(arg0, arg1, arg2);
    }
    if (fn_80042568(arg1)) {
        return fn_80043050(arg0, arg1, arg2);
    }
    if (fn_80043CCC(arg1)) {
        return fn_80043B48(arg0, arg1, arg2);
    }
    if (fn_80044C0C(arg1)) {
        return fn_80044A94(arg0, arg1, arg2);
    }
    return -1;
}
