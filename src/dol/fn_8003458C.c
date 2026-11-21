#include "types.h"


/* --- dol/GXFinishInterruptHandler.c --- */
// The PE register is memory-mapped hardware and must not be cached.
extern volatile u16 *__peReg;
extern void (*lbl_801A6C14)(void);
extern u8 lbl_801A6C18;
extern void OSClearContext(void *);
extern void OSSetCurrentContext(void *);
extern u32 lbl_801A6C1C;
extern void OSWakeupThread(void *);

void GXFinishInterruptHandler(void *unused, void *context);

/* --- dol/__GXPEInit.c --- */
/* --- dol/__GXPEInit.c --- */
extern u32 __OSSetInterruptHandler(u32, u32);
extern u32 OSInitThreadQueue(void *);
extern u32 __OSUnmaskInterrupts(u32);
extern void GXTokenInterruptHandler(void);
// PE register block is memory-mapped hardware and must be accessed volatile.

void __GXPEInit(void);

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
