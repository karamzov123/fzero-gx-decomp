#include "types.h"


/* --- dol/fn_80045F58.c --- */
/* --- dol/fn_80045F58.c --- */
/* --- dol/fn_80045F58.c --- */
struct fn_80045F58_Arg0 {
    u8 pad_0[0x88];
    u32 unk_88;
    u32 unk_8C;
};

void fn_80045F58(struct fn_80045F58_Arg0 *arg0, u32 arg1, u32 arg2) {
    arg0->unk_8C = (arg0->unk_8C + arg2);
    arg0->unk_88 = (arg0->unk_88 + arg2);
}

/* --- dol/fn_80045F74.c --- */
struct fn_80045F74_Arg0 {
    u8 pad_0[0x18];
    u32 unk_18;
    u8 pad_1C[0x20];
    u32 unk_3C;
    u32 unk_40;
    u8 pad_44[0x44];
    u32 unk_88;
    u32 unk_8C;
};
struct fn_80045F74_Arg1 {
    u32 unk_0;
};
struct fn_80045F74_Arg2 {
    u32 unk_0;
};
struct fn_80045F74_Arg3 {
    u32 unk_0;
};

u32 fn_80045F74(struct fn_80045F74_Arg0 *arg0, struct fn_80045F74_Arg1 *arg1, struct fn_80045F74_Arg2 *arg2, struct fn_80045F74_Arg3 *arg3) {
    arg1->unk_0 = arg0->unk_8C;
    arg2->unk_0 = (arg0->unk_40 - arg0->unk_8C);
    arg3->unk_0 = (arg0->unk_18 - arg0->unk_88);
    return arg0->unk_3C;
}

/* --- dol/fn_80045FA4.c --- */
/* --- dol/fn_80045FA4.c --- */
struct fn_80045FA4_lbl_8017A288 {
    u32 unk_0;    u8 pad_4[0x10];
};

extern struct fn_80045FA4_lbl_8017A288 lbl_8017A288[];
extern u32 fn_8004E4AC(void);
extern u32 lbl_8017A29C[];
extern u32 memset(u32, u32, u32);

void fn_80045FA4(void) {
    u32 v0;
    fn_8004E4AC();
    v0 = lbl_8017A288[0].unk_0;
    lbl_8017A288[0].unk_0 = (v0 + 1);
    memset((u32)&lbl_8017A29C, 0, 3456);
}
