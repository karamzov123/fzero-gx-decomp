#include "types.h"


/* --- dol/fn_800420F4.c --- */
/* --- dol/fn_800420F4.c --- */
extern u32 fn_80045354(u32);

struct fn_800420F4_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

void fn_800420F4(struct fn_800420F4_Arg0 *arg0) {
    fn_80045354(arg0->unk_4);
    *(u8 *)((u8 *)(u32)arg0 + 1) = 0;
}

/* --- dol/fn_8004212C.c --- */
struct fn_8004212C_Arg0 {
    u8 pad_0[0x1];
    u8 unk_1;
    u8 pad_2[0x1];
    u8 unk_3;
    u8 pad_4[0x28];
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3C;
    u32 unk_40;
    u32 unk_44;
    u8 pad_48[0x50];
    u32 unk_98;
};

void fn_8004212C(struct fn_8004212C_Arg0 *arg0) {
    arg0->unk_98 = 0;
    arg0->unk_2C = 0;
    arg0->unk_30 = 0;
    arg0->unk_34 = 0;
    arg0->unk_38 = (0x80000000 - 1);
    arg0->unk_3C = -1;
    arg0->unk_40 = 0;
    arg0->unk_44 = 0;
    arg0->unk_3 = 0;
    arg0->unk_1 = 1;
}

/* --- dol/fn_8004216C.c --- */
// fn_8004216C: empty in retail (single blr).
void fn_8004216C(void) {
}

/* --- dol/fn_80042170.c --- */
/* --- dol/fn_80042170.c --- */
extern u32 fn_800433D0(u32, u32);

struct fn_80042170_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x30];
    u32 unk_38;
};

void fn_80042170(struct fn_80042170_Arg0 *arg0, u32 arg1) {
    arg0->unk_38 = arg1;
    fn_800433D0(arg0->unk_4, arg1);
}

/* --- dol/fn_80042198.c --- */
extern u32 fn_800433F4(u32, u32);

struct fn_80042198_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
};

void fn_80042198(struct fn_80042198_Arg0 *arg0, u32 arg1) {
    arg0->unk_8 = arg1;
    fn_800433F4(arg0->unk_4, arg1);
}
