#include "types.h"


/* --- dol/fn_8008F748.c --- */
extern s32 lbl_801A6E34;
extern u8 lbl_801A6E3C;
extern u32 OSDisableInterrupts(void);
extern void fn_8008F92C(u32 *);
extern void fn_8008FB90(u32 *);
extern u32 lbl_801A6E30;
extern u32 OSRestoreInterrupts(u32);

u32 fn_8008F748(void) {
    u32 v0;
    u32 v1;

    lbl_801A6E3C = 0;
    if (lbl_801A6E34 == 0) {
        v0 = OSDisableInterrupts();
        fn_8008F92C(&v1);
        if (v1 & 1) {
            fn_8008FB90(&v1);
            v1 &= 0x1FFFFFFF;
            if ((v1 & 0x1F000000) == 0x1F000000) {
                lbl_801A6E30 = v1;
                lbl_801A6E34 = v1 & 0x7FFF;
                lbl_801A6E3C = 1;
            }
        }
        OSRestoreInterrupts(v0);
    }
    return lbl_801A6E34;
}

/* --- dol/fn_8008F7E4.c --- */
extern u32 __OSMaskInterrupts(u32);
extern u32 __OSSetInterruptHandler(u32, u32);
extern u32 __OSUnmaskInterrupts(u32);
extern u32 lbl_801A6E2C;
extern void fn_8008F8B0(void);
extern void fn_8008F8F0(void);

u32 fn_8008F7E4(void) {
    __OSMaskInterrupts((0x20000 + -32768));
    __OSMaskInterrupts(64);
    lbl_801A6E2C = (u32)fn_8008F8F0;
    __OSSetInterruptHandler(25, (u32)fn_8008F8B0);
    return __OSUnmaskInterrupts(64);
}
