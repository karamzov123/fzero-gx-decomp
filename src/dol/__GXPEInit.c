#include "types.h"


/* --- dol/__GXPEInit.c --- */
extern u32 __OSSetInterruptHandler(u32, u32);
extern u32 OSInitThreadQueue(void *);
extern u32 __OSUnmaskInterrupts(u32);
extern void GXTokenInterruptHandler(void);
extern void GXFinishInterruptHandler(void);
extern u32 lbl_801A6C1C;
// PE register block is memory-mapped hardware and must be accessed volatile.
extern volatile u16 *__peReg;

void __GXPEInit(void) {
    u32 current;

    __OSSetInterruptHandler(0x12, (u32)GXTokenInterruptHandler);
    __OSSetInterruptHandler(0x13, (u32)GXFinishInterruptHandler);
    OSInitThreadQueue(&lbl_801A6C1C);
    __OSUnmaskInterrupts(0x2000);
    __OSUnmaskInterrupts(0x1000);

    current = __peReg[5];
    current = (current & ~0x4u) | 0x4u;
    current = (current & ~0x8u) | 0x8u;
    current = (current & ~0x1u) | 0x1u;
    current = (current & ~0x2u) | 0x2u;
    __peReg[5] = current;
}

/* --- dol/fn_8003458C.c --- */
struct fn_8003458C_gx_T {
    u8 pad_0[0x4F4];
    u32 unk_4F4;
};

extern struct fn_8003458C_gx_T *gx;
extern u32 __GXSetVCD(void);
extern u32 __GXCalculateVLim(void);
extern u32 fn_80033650(void);
extern u32 __GXSetGenMode(void);
extern u32 __GXSetSUTexRegs(void);
extern u32 fn_80036F24(void);

void fn_8003458C(void) {
    if ((gx->unk_4F4 & 0x1) != 0) {
    __GXSetSUTexRegs();
    }
    if ((gx->unk_4F4 & 0x2) != 0) {
    fn_80036F24();
    }
    if ((gx->unk_4F4 & 0x4) != 0) {
    __GXSetGenMode();
    }
    if ((gx->unk_4F4 & 0x8) != 0) {
    __GXSetVCD();
    }
    if ((gx->unk_4F4 & 0x10) != 0) {
    fn_80033650();
    }
    if ((gx->unk_4F4 & 0x18) != 0) {
    __GXCalculateVLim();
    }
    gx->unk_4F4 = 0;
}
