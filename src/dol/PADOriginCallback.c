#include "types.h"

extern s32 lbl_801A64B4;
extern void UpdateOrigin(s32 value);
extern u32 lbl_801A697C;
extern void SIGetResponse(u32 channel, void *status);
extern u32 lbl_801A64BC;
extern void SISetCommand(u32 channel, u32 command);
extern void SIEnablePolling(u32 mask);
extern u32 lbl_801A697C__fzgx_offset_4;
extern u8 lbl_8015D0C0[64];
extern void memset(void *dst, int value, u32 size);
extern void PADTypeAndStatusCallback(void);
extern void SIGetTypeAsync(u32 channel, void (*callback)(void));

void PADOriginCallback(u32 unused, u32 channel, u32 p3, u32 p4, u32 p5) {
    u32 extra;

    if ((channel & 0xf) == 0) {
        UpdateOrigin(lbl_801A64B4);
        channel = lbl_801A64B4;
        lbl_801A697C |= 0x80000000u >> channel;
{
    u32 response;
        SIGetResponse(channel, &response);
}
        SISetCommand(channel, lbl_801A64BC | 0x400000);
        SIEnablePolling(lbl_801A697C);
    }

    lbl_801A64B4 = __cntlzw(lbl_801A697C__fzgx_offset_4);
    if (lbl_801A64B4 != 0x20) {
        extra = lbl_801A697C__fzgx_offset_4 & ~(0x80000000u >> lbl_801A64B4);
        lbl_801A697C__fzgx_offset_4 = extra;
        memset(&lbl_8015D0C0[lbl_801A64B4 * 12], 0, 12);
        SIGetTypeAsync(lbl_801A64B4, PADTypeAndStatusCallback);
    }
}
