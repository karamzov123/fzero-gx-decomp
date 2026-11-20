#include "types.h"


/* --- dol/fn_80065A7C.c --- */
struct fn_80065A7C_State {
    u8 pad_0[0x340];
    u32 unk_340[0x40];
    u8 pad_440[0x19];
    u8 unk_459;
};

extern struct fn_80065A7C_State *lbl_801A6C80;

void fn_80065A7C(u32 arg0) {
    if (lbl_801A6C80->pad_440[0] >= 0x40) {
        return;
    }
    lbl_801A6C80->unk_340[lbl_801A6C80->unk_459] = arg0;
    lbl_801A6C80->unk_459 = (lbl_801A6C80->unk_459 + 1) & 0x3f;
    lbl_801A6C80->pad_440[0] = lbl_801A6C80->pad_440[0] + 1;
}

/* --- dol/fn_80065AC4.c --- */
extern u32 lbl_801A6C7C;

void fn_80065AC4(void) {
    lbl_801A6C7C = 0;
}

/* --- dol/fn_80065AD0.c --- */
struct fn_80065AD0_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
};

extern u32 lbl_801A6410;
extern void fn_80008E5C(u32, u32);

void fn_80065AD0(struct fn_80065AD0_Arg0 *arg0) {
    u32 v0;
    u32 v1;
    v0 = arg0->unk_10;
    v1 = (u32)arg0;
    if (v0 != 0) {
    v1 = lbl_801A6410;
    fn_80008E5C(v1, v0);
    }
    lbl_801A6C7C = 0;
}
