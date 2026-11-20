#include "types.h"


/* --- dol/fn_800424B8.c --- */
extern u32 lbl_801798C0[];
extern u32 memset(u32, u32, u32);

void fn_800424B8(void) {
    memset((u32)&lbl_801798C0, 0, 2496);
}

/* --- dol/fn_800424E8.c --- */
extern u32 fn_80045FA4(void);

void fn_800424E8(void) {
    fn_80045FA4();
    memset((u32)&lbl_801798C0, 0, 2496);
}

/* --- dol/fn_8004251C.c --- */
struct fn_8004251C_Arg0 {
    u8 pad_0[0x9A];
    s16 unk_9A;
};

extern u32 ADXB_ExecOneWav4(u32);
extern u32 ADXB_ExecOneWav8(u32);
extern u32 fn_80042D24(u32);

void fn_8004251C(struct fn_8004251C_Arg0 *arg0) {
    if (arg0->unk_9A == 2) {
    ADXB_ExecOneWav4((u32)arg0);
    } else {
    if (arg0->unk_9A == 1) {
    ADXB_ExecOneWav8((u32)arg0);
    } else {
    if (arg0->unk_9A == 0) {
    fn_80042D24((u32)arg0);
    }
    }
    }
}

/* --- dol/fn_80042568.c --- */
extern u32 fn_8008023C(u32, u32, u32);
extern u32 lbl_80090070[];
extern u32 lbl_80090078[];

s32 fn_80042568(u32 arg0) {
    u32 v0;
    if ((s32)fn_8008023C(arg0, (u32)&lbl_80090070, 4) == 0 && (s32)fn_8008023C((arg0 + 8), (u32)&lbl_80090078, 4) == 0) {
    v0 = 1;
    } else {
    v0 = 0;
    }
    return v0;
}
