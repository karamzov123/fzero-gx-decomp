#include "types.h"


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
