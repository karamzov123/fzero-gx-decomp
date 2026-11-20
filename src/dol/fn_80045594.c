#include "types.h"


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
