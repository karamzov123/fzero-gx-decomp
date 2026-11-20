#include "types.h"


/* --- dol/fn_80070CF8.c --- */
extern u32 OSGetArenaHi(void);
extern u32 OSGetArenaLo(void);
extern u32 OSSetArenaHi(u32);
extern u32 OSSetArenaLo(u32);
extern u8 lbl_801A6620;

u32 fn_80070CF8(u32 arg0) {
    u32 v0;
    s32 v2;
    u32 v1;
    u32 v3;
    u32 t0, t1, t2, t3;
    v0 = (arg0 + 31);
    v1 = (v0 & ~0x1F);
    v3 = v0;
    if (lbl_801A6620 != 0) {
    t0 = OSGetArenaHi();
    v3 = t0;
    v2 = (v3 - v1);
    v3 = v2;
    t1 = OSSetArenaHi(v3);
    v3 = t1;
    } else {
    t2 = OSGetArenaLo();
    v3 = t2;
    v2 = v3;
    v3 = (v2 + v1);
    t3 = OSSetArenaLo(v3);
    v3 = t3;
    }
    return v2;
}

/* --- dol/fn_80070D60.c --- */
extern u32 lbl_801A6D10;
extern u32 lbl_801A6D14;
extern u32 lbl_801A6D18;
extern u32 lbl_801A6D1C;
extern u32 lbl_801A6D20;
extern u32 lbl_801A6D24;

struct fn_80070D60_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
};

void fn_80070D60(struct fn_80070D60_Arg0 *arg0) {
    lbl_801A6D24 = arg0->unk_0;
    lbl_801A6D20 = arg0->unk_4;
    lbl_801A6D1C = arg0->unk_8;
    lbl_801A6D18 = arg0->unk_C;
    lbl_801A6D14 = arg0->unk_10;
    lbl_801A6D10 = arg0->unk_14;
}

/* --- dol/fn_80070D94.c --- */
extern void fn_80071CB4(void);
extern void fn_80071CC0(void);
extern void fn_80071CE0(void);
extern void fn_80071CE8(void);
extern void fn_80071D0C(void);
extern void fn_80071D2C(void);

void fn_80070D94(void) {
    lbl_801A6D24 = (u32)fn_80071CB4;
    lbl_801A6D20 = (u32)fn_80071CC0;
    lbl_801A6D1C = (u32)fn_80071CE0;
    lbl_801A6D18 = (u32)fn_80071CE8;
    lbl_801A6D14 = (u32)fn_80071D0C;
    lbl_801A6D10 = (u32)fn_80071D2C;
}

/* --- dol/fn_80070DE0.c --- */
/* --- dol/fn_80070DE0.c --- */
extern u32 lbl_801A6D0C;

u32 fn_80070DE0(u32 arg0) {
    u32 v0;
    v0 = lbl_801A6D0C;
    lbl_801A6D0C = arg0;
    return v0;
}

/* --- dol/fn_80070DF0.c --- */
extern u32 lbl_801A6D08;

u32 fn_80070DF0(u32 arg0) {
    u32 v0;
    v0 = lbl_801A6D08;
    lbl_801A6D08 = arg0;
    return v0;
}

/* --- dol/fn_80070E00.c --- */
extern void fn_80071C64(void);
extern void fn_80071C8C(void);

void fn_80070E00(void) {
    lbl_801A6D0C = (u32)fn_80071C64;
    lbl_801A6D08 = (u32)fn_80071C8C;
}
