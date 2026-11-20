#include "types.h"


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

/* --- dol/fn_80045FEC.c --- */
extern u32 fn_8008023C(u32, u32, u32);
extern u32 lbl_80090928[];

u32 fn_80045FEC(u32 arg0) {
    u32 t0;
    t0 = fn_8008023C(arg0, (u32)&lbl_80090928, 4);
    return ((u32)__cntlzw(t0) >> 5);
}
