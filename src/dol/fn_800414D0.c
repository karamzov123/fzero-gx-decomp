#include "types.h"


/* --- dol/fn_800414D0.c --- */
/* --- dol/fn_800414D0.c --- */
struct fn_800414D0_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

extern u32 fn_800454C4(u32);
extern u32 fn_800454CC(u32);

s32 fn_800414D0(struct fn_800414D0_Arg0 *arg0) {
    u32 v0;
    u32 t0, t1;
    t0 = fn_800454CC(arg0->unk_4);
    v0 = t0;
    if ((s32)t0 > 0 && ((s8)*((u8 *)arg0 + 1) == 2 || (s8)*((u8 *)arg0 + 1) == 3)) {
    v0 = *(u32 *)((u8 *)arg0 + 4);
    t1 = fn_800454C4(v0);
    v0 = t1;
    } else {
    v0 = 0;
    }
    return v0;
}

/* --- dol/fn_80041530.c --- */
extern u32 fn_800454D4(u32);

struct fn_80041530_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

void fn_80041530(struct fn_80041530_Arg0 *arg0) {
    fn_800454D4(arg0->unk_4);
}

/* --- dol/fn_80041554.c --- */
extern u32 fn_800454DC(u32);

struct fn_80041554_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

void fn_80041554(struct fn_80041554_Arg0 *arg0) {
    fn_800454DC(arg0->unk_4);
}

/* --- dol/fn_80041578.c --- */
extern u32 fn_800454E4(u32);

u32 fn_80041578(u32 arg0) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if (arg0 == 0) {
    v0 = 0;
    } else {
    v0 = *(u32 *)(v0 + 4);
    t0 = fn_800454E4(v0);
    v0 = t0;
    }
    return v0;
}

/* --- dol/fn_800415AC.c --- */
extern u32 fn_800454FC(u32);

struct fn_800415AC_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

void fn_800415AC(struct fn_800415AC_Arg0 *arg0) {
    fn_800454FC(arg0->unk_4);
}

/* --- dol/fn_800415D0.c --- */
extern u32 fn_80045504(u32);

struct fn_800415D0_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

void fn_800415D0(struct fn_800415D0_Arg0 *arg0) {
    fn_80045504(arg0->unk_4);
}

/* --- dol/fn_800415F4.c --- */
extern u32 fn_8004550C(u32);

struct fn_800415F4_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

void fn_800415F4(struct fn_800415F4_Arg0 *arg0) {
    fn_8004550C(arg0->unk_4);
}

/* --- dol/fn_80041618.c --- */
extern u32 fn_80045514(u32);

struct fn_80041618_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

void fn_80041618(struct fn_80041618_Arg0 *arg0) {
    fn_80045514(arg0->unk_4);
}

/* --- dol/fn_8004163C.c --- */
extern u32 fn_8004551C(u32);

struct fn_8004163C_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

void fn_8004163C(struct fn_8004163C_Arg0 *arg0) {
    fn_8004551C(arg0->unk_4);
}

/* --- dol/fn_80041660.c --- */
extern u32 fn_80045588(u32);

struct fn_80041660_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

void fn_80041660(struct fn_80041660_Arg0 *arg0) {
    fn_80045588(arg0->unk_4);
}

/* --- dol/fn_80041684.c --- */
extern u32 fn_80045594(u32);

struct fn_80041684_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

void fn_80041684(struct fn_80041684_Arg0 *arg0) {
    fn_80045594(arg0->unk_4);
}

/* --- dol/fn_800416A8.c --- */
extern u32 fn_8004559C(u32);

struct fn_800416A8_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

void fn_800416A8(struct fn_800416A8_Arg0 *arg0) {
    fn_8004559C(arg0->unk_4);
}

/* --- dol/fn_800416CC.c --- */
/* --- dol/fn_800416CC.c --- */
struct fn_800416CC_Arg0 {
    u8 pad_0[0x44];
    u32 unk_44;
};

void fn_800416CC(struct fn_800416CC_Arg0 *arg0, u32 arg1) {
    arg0->unk_44 = arg1;
}

/* --- dol/fn_800416D4.c --- */
struct fn_800416D4_Arg0 {
    u8 pad_0[0x40];
    u32 unk_40;
};

void fn_800416D4(struct fn_800416D4_Arg0 *arg0, u32 arg1) {
    arg0->unk_40 = arg1;
}

/* --- dol/fn_800416DC.c --- */
struct fn_800416DC_Arg0 {
    u8 pad_0[0x3C];
    u32 unk_3C;
};

void fn_800416DC(struct fn_800416DC_Arg0 *arg0, u32 arg1) {
    arg0->unk_3C = arg1;
}

/* --- dol/fn_800416E4.c --- */
struct fn_800416E4_Arg0 {
    u8 pad_0[0x48];
    u32 unk_48;
    u32 unk_4C;
};

void fn_800416E4(struct fn_800416E4_Arg0 *arg0, u32 arg1, u32 arg2) {
    arg0->unk_48 = arg1;
    arg0->unk_4C = arg2;
}

/* --- dol/fn_800416F0.c --- */
struct fn_800416F0_Arg0 {
    u8 pad_0[0x34];
    u32 unk_34;
};

void fn_800416F0(struct fn_800416F0_Arg0 *arg0, u32 arg1) {
    arg0->unk_34 = arg1;
}

/* --- dol/fn_800416F8.c --- */
struct fn_800416F8_Arg0 {
    u8 pad_0[0x2C];
    u32 unk_2C;
};

u32 fn_800416F8(struct fn_800416F8_Arg0 *arg0) {
    return arg0->unk_2C;
}
