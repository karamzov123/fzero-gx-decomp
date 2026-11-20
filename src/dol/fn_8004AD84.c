#include "types.h"


/* --- dol/fn_8004AD84.c --- */
extern void fn_80059B44(void);
extern void fn_80059AB4(void);

typedef struct Fn8004AD84 {
    s8 unk00;
    s8 unk01;
    s8 unk02;
    s8 unk03[0x3e];
    s8 unk41;
    s8 unk42;
    s8 unk43;
    s8 unk44;
} Fn8004AD84;

void fn_8004AD84(Fn8004AD84 *self) {
    fn_80059B44();
    if (self->unk01 == 2 && self->unk02 == 1) {
        self->unk44 = 1;
        if (self->unk43 == 1) {
            self->unk43 = 0;
        }
    } else {
        self->unk01 = 1;
    }
    fn_80059AB4();
}

/* --- dol/fn_8004ADF4.c --- */
extern void fn_80046718(void);
extern void fn_80046738(void);

s32 fn_8004ADF4(u32 arg0) {
    fn_80046738();
    *(u32 *)((u8 *)arg0 + 48) = 0;
    *(u8 *)((u8 *)arg0 + 3) = 0;
    if ((s32)*(u32 *)((u8 *)arg0 + 16) == 0) {
    *(u8 *)((u8 *)arg0 + 1) = 3;
    } else {
    *(u8 *)((u8 *)arg0 + 1) = 2;
    }
    *(u8 *)((u8 *)arg0 + 2) = 0;
    *(u32 *)((u8 *)arg0 + 32) = 0;
    *(u32 *)((u8 *)arg0 + 36) = 0;
    *(u8 *)((u8 *)arg0 + 67) = 1;
    *(u32 *)((u8 *)arg0 + 88) = (0x100000 - 1);
    fn_80046718();
    return 1;
}
