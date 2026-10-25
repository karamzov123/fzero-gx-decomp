#include "types.h"
struct GXSetCPUFifo___piReg_T {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
};
extern struct GXSetCPUFifo___piReg_T *__piReg;
extern u32 lbl_801A6BF0;
extern u32 lbl_801A6BF4;
extern u8 lbl_801A6BFC;
extern u32 GXSetCPUFifo(u32);
extern BOOL OSDisableInterrupts(void);
extern void __GXWriteFifoIntReset(u8, u8);
extern void __GXWriteFifoIntEnable(u32, u32);
extern void __GXFifoLink(u8);
extern u32 fn_80009FF4(void);
extern BOOL OSRestoreInterrupts(BOOL);

u32 GXSetCPUFifo(u32 arg0) {
    s32 temp_r31;

    temp_r31 = OSDisableInterrupts();
    (*(u32 *)((u8 *)(&lbl_801A6BF0) + 0)) = arg0;
    if (arg0 == (u32) (*(u32 *)((u8 *)(&lbl_801A6BF4) + 0))) {
        (*(struct GXSetCPUFifo___piReg_T **)((u8 *)(&__piReg) + 0))->unk_C = (*(s32 *)((u8 *)(arg0) + 0)) & 0x3FFFFFFF;
        (*(struct GXSetCPUFifo___piReg_T **)((u8 *)(&__piReg) + 0))->unk_10 = (*(s32 *)((u8 *)(arg0) + 4)) & 0x3FFFFFFF;
        (*(struct GXSetCPUFifo___piReg_T **)((u8 *)(&__piReg) + 0))->unk_14 = (*(s32 *)((u8 *)(arg0) + 24)) & 0x3FFFFFE0 & 0xFBFFFFFF;
        (*(u8 *)((u8 *)(&lbl_801A6BFC) + 0)) = 1;
        __GXWriteFifoIntReset(1U, 1U);
        __GXWriteFifoIntEnable(1U, 0U);
        __GXFifoLink(1U);
    } else {
        if ((u8) (*(u8 *)((u8 *)(&lbl_801A6BFC) + 0)) != 0) {
            __GXFifoLink(0U);
            (*(u8 *)((u8 *)(&lbl_801A6BFC) + 0)) = 0;
        }
        __GXWriteFifoIntEnable(0U, 0U);
        (*(struct GXSetCPUFifo___piReg_T **)((u8 *)(&__piReg) + 0))->unk_C = (*(s32 *)((u8 *)(arg0) + 0)) & 0x3FFFFFFF;
        (*(struct GXSetCPUFifo___piReg_T **)((u8 *)(&__piReg) + 0))->unk_10 = (*(s32 *)((u8 *)(arg0) + 4)) & 0x3FFFFFFF;
        (*(struct GXSetCPUFifo___piReg_T **)((u8 *)(&__piReg) + 0))->unk_14 = (*(s32 *)((u8 *)(arg0) + 24)) & 0x3FFFFFE0 & 0xFBFFFFFF;
    }
    fn_80009FF4();
    return OSRestoreInterrupts(temp_r31);
}
