#include "types.h"

extern s32 lbl_801A64B4;
extern u32 lbl_801A697C;
extern BOOL SIGetResponse(s32 channel, void *response);
extern u32 lbl_801A64BC;
extern void SISetCommand(u32 channel, u32 command);
extern u32 SIEnablePolling(u32 mask);
extern u32 lbl_801A6988;
extern u32 lbl_801A697C__fzgx_offset_4;
extern u8 lbl_8015D0C0[64];
extern void *memset(void *dst, int value, u32 size);
extern void PADTypeAndStatusCallback(void);
extern u32 SIGetTypeAsync(s32 channel, void (*callback)(void));

#pragma opt_lifetimes off
void PADProbeCallback(u32 unused, u32 value) {
    u32 response[3];
    u32 chanBit;
    u32 recalibrate;
    BOOL enable;

    if ((value & 0xf) == 0) {
{
    u32 channel;
        channel = lbl_801A64B4;
        lbl_801A697C |= 0x80000000u >> channel;
        SIGetResponse(channel, response);
        SISetCommand(channel, lbl_801A64BC | 0x400000);
        SIEnablePolling(lbl_801A697C);
        channel = lbl_801A64B4;
        lbl_801A6988 |= 0x80000000u >> channel;
}
    }

    lbl_801A64B4 = __cntlzw(lbl_801A697C__fzgx_offset_4);
    if (lbl_801A64B4 != 0x20) {
        lbl_801A697C__fzgx_offset_4 &= ~(0x80000000u >> lbl_801A64B4);
        memset(&lbl_8015D0C0[lbl_801A64B4 * 12], 0, 12);
        SIGetTypeAsync(lbl_801A64B4, PADTypeAndStatusCallback);
    }
}
#pragma opt_lifetimes reset

