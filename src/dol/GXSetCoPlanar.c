#include "types.h"

struct fn_800348DC_gx_T {
    u8 pad_0[0x204];
    u32 unk_204;
};

extern u32 gx;

void GXSetCoPlanar(u32 arg0) {
    struct fn_800348DC_gx_T *data;
    u32 value;

    data = (struct fn_800348DC_gx_T *)gx;
    value = (arg0 & 0xFF) << 19;
    data->unk_204 = (data->unk_204 & 0xFFF7FFFF) | value;
    *(volatile u8 *)((u8 *)0xCC010000 + -32768) = 0x61; /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile u32 *)((u8 *)0xCC010000 + -32768) = 0xFE080000; /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile u8 *)((u8 *)0xCC010000 + -32768) = 0x61; /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile u32 *)((u8 *)0xCC010000 + -32768) = data->unk_204; /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
}
