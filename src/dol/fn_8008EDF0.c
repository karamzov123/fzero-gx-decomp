#include "types.h"
#include "dolphin/types.h"
#include "sdk_addresses.h"


/* --- dol/fn_8008EDF0.c --- */
/* --- dol/fn_8008EDF0.c --- */
struct fn_8008EDF0_Arg0 {
    u32 unk_0;
};

extern u32 OSDisableInterrupts(void);
extern u32 OSRestoreInterrupts(u32);
extern u32 fn_8008E770(u32, u32, u32, u32);
extern u32 fn_8008E9B4(u32);
extern u32 fn_8008EBF8(u32);
extern u32 fn_8008EC78(u32);
extern u32 fn_8008ED70(void);
extern u32 lbl_801A6680;
extern u32 lbl_801A6E20;

u32 fn_8008EDF0(struct fn_8008EDF0_Arg0 *arg0, u32 arg1) {
    s32 v0;
    u32 t1, t3;
    u32 loc_20;
    u32 loc_1C;
    u32 t5, t7;
    u32 loc_10;
    u32 t0, t4, t6, t8, t9, t10;
    arg0->unk_0 = lbl_801A6680;
    t0 = OSDisableInterrupts();
    lbl_801A6E20 = arg1;
    t1 = OSRestoreInterrupts(t0);
    fn_8008ED70();
    loc_20 = 0;
    loc_1C = (0x1000000 + 3);
    v0 = 0;
    while (v0 == 0) {
    v0 = 5;
    t3 = fn_8008EBF8(v0);
    v0 = t3;
    }
    loc_10 = 0x80000000;
    v0 = (u32)&loc_10;
    t4 = fn_8008E770(v0, 2, 1, 0);
    v0 = t4;
    t5 = fn_8008E9B4(v0);
    v0 = t5;
    v0 = (u32)&loc_1C;
    t6 = fn_8008E770(v0, 4, 1, 0);
    v0 = t6;
    t7 = fn_8008E9B4(v0);
    v0 = t7;
    v0 = (u32)&loc_20;
    t8 = fn_8008E770(v0, 4, 1, 0);
    v0 = t8;
    t9 = fn_8008E9B4(v0);
    v0 = t9;
    t10 = fn_8008EC78(v0);
    v0 = t10;
    return v0;
}

/* --- dol/fn_8008EEAC.c --- */
extern void fn_8008EDB0(void);
extern void fn_8008EB8C(void (*callback)(void));
extern void fn_8008ED30(void);

void fn_8008EEAC(void) {
    fn_8008EB8C(fn_8008EDB0);
    fn_8008ED30();
}

/* --- dol/fn_8008EED8.c --- */
extern s32 lbl_801A6E1C;
extern char lbl_8015B900[25];
extern int printf(const char *, ...);

vu32 __PIRegs[16] : FZGX_ADDR___PIRegs;
#define PI_INTSR (__PIRegs[0])

u32 fn_8008EED8(void) {
    u32 loc_18;
    u32 loc_14;
    u32 loc_8[3];
    s32 status;
    if ((PI_INTSR & 0x1000) == 0 && *(u8 *)lbl_801A6680 == 0) {
        loc_18 = 0;
    } else {
        if (lbl_801A6E1C == 0) {
            status = 0;
            while (status == 0) {
                status = fn_8008EBF8(5);
            }
            if (status == 0) {
                printf("Can't select EXI2 port!\n");
            } else {
                lbl_801A6E1C = 1;
                loc_8[0] = 0;
                fn_8008E9B4(fn_8008E770((u32)loc_8, 2, 1, 0));
                fn_8008E9B4(fn_8008E770((u32)&loc_14, 2, 0, 0));
            }
        }
        fn_8008E9B4(fn_8008E770((u32)&loc_18, 4, 0, 0));
        if (*(u8 *)lbl_801A6680 == 0) {
            u16 pi = PI_INTSR;
            *(u8 *)lbl_801A6680 = 1;
            PI_INTSR = pi & 0x1000;
        }
    }
    return loc_18;
}
