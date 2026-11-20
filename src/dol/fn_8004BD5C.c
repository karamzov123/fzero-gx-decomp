#include "types.h"


/* --- dol/fn_8004BD5C.c --- */
extern u8 lbl_80090A80[284];
extern void fn_800474E4(u32);

struct fn_8004BD5C_Arg0 {
    u8 pad_0[0x71];
    s8 unk_71;
};

s32 fn_8004BD5C(struct fn_8004BD5C_Arg0 *arg0) {
    if (arg0 == 0) {
        fn_800474E4((u32)&lbl_80090A80);
        return -1;
    }
    return arg0->unk_71;
}

/* --- dol/fn_8004BD9C.c --- */
/* --- dol/fn_8004BD9C.c --- */
extern u8 lbl_80090B9C[196];

struct fn_8004BD9C_Arg0 {
    u8 pad_0[0x60];
    s16 unk_60;
};

s32 fn_8004BD9C(struct fn_8004BD9C_Arg0 *arg0) {
    if (arg0 == 0) {
        fn_800474E4((u32)&lbl_80090B9C);
        return -1;
    }
    return arg0->unk_60;
}

/* --- dol/fn_8004BDD8.c --- */
typedef struct ADXFSpu {
    s8 used;
    u8 reserved[0xBF];
} ADXFSpu;

extern s32 lbl_8017E56C[8];
extern ADXFSpu lbl_80178CBC[16];

extern void fn_80046738(void);
extern void fn_80046718(void);
extern void fn_80041700(void);
extern void fn_8004D220(void *);
extern void fn_8004EE44(void);

void fn_8004BDD8(void) {
    s32 index;

    fn_80046738();
    if (lbl_8017E56C[0] != 0) {
        fn_80046718();
    } else {
        lbl_8017E56C[0] = 1;
        fn_80046718();
        fn_80046738();
        fn_80041700();
        lbl_8017E56C[0] = 2;
        for (index = 0; index < 16; index++) {
            if (lbl_80178CBC[index].used == 1) {
                fn_8004D220(&lbl_80178CBC[index]);
            }
        }
        lbl_8017E56C[0] = 3;
        fn_8004EE44();
        lbl_8017E56C[0] = 0;
        fn_80046718();
    }
}
