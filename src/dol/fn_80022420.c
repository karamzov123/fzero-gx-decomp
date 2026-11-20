#include "types.h"


/* --- dol/fn_80022420.c --- */
extern u32 lbl_801A6B38;
extern u32 lbl_801A6B3C;
extern u32 lbl_801A6B40;
extern u32 lbl_801A6B44;
extern u32 lbl_801A6B48;
extern u32 lbl_801A6B4C;
extern u32 lbl_801A6B50;
extern u32 lbl_801A6B54;
extern u32 lbl_801A6B58;

void fn_80022420(void) {
    lbl_801A6B58 = 0;
    lbl_801A6B54 = 0;
    lbl_801A6B50 = 0;
    lbl_801A6B4C = 0;
    lbl_801A6B48 = 0;
    lbl_801A6B44 = 0;
    lbl_801A6B40 = 0;
    lbl_801A6B3C = 0;
    lbl_801A6B38 = 0;
}

/* --- dol/fn_8002244C.c --- */
// fn_8002244C: empty in retail (single blr).
void fn_8002244C(void) {
}

/* --- dol/fn_80022450.c --- */
struct fn_80022450_Arg0 {
    u8 pad_0[0x52];
    s16 unk_52;
    s16 unk_54;
    s16 unk_56;
    s16 unk_58;
    s16 unk_5A;
    s16 unk_5C;
    s16 unk_5E;
    s16 unk_60;
    s16 unk_62;
};

void fn_80022450(struct fn_80022450_Arg0 *arg0) {
    lbl_801A6B38 = (lbl_801A6B38 + arg0->unk_52);
    lbl_801A6B44 = (lbl_801A6B44 + arg0->unk_54);
    lbl_801A6B50 = (lbl_801A6B50 + arg0->unk_56);
    lbl_801A6B3C = (lbl_801A6B3C + arg0->unk_58);
    lbl_801A6B48 = (lbl_801A6B48 + arg0->unk_5A);
    lbl_801A6B54 = (lbl_801A6B54 + arg0->unk_5C);
    lbl_801A6B40 = (lbl_801A6B40 + arg0->unk_5E);
    lbl_801A6B4C = (lbl_801A6B4C + arg0->unk_60);
    lbl_801A6B58 = (lbl_801A6B58 + arg0->unk_62);
}

/* --- dol/fn_800224E4.c --- */
extern u32 lbl_801A6B68;

u32 fn_800224E4(void) {
    return lbl_801A6B68;
}
