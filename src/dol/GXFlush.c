#include "types.h"

struct fn_80033E20_gx_T {
    u8 pad_0[0x4F4];
    u32 unk_4F4;
};

extern struct fn_80033E20_gx_T *gx;
extern u32 fn_80009FF4(void);
extern u32 fn_8003458C(void);

void GXFlush(void) {
    if (gx->unk_4F4 != 0) {
    fn_8003458C();
    }
    *(u32 *)((u8 *)0xCC010000 + -32768) = 0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(u32 *)((u8 *)0xCC010000 + -32768) = 0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(u32 *)((u8 *)0xCC010000 + -32768) = 0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(u32 *)((u8 *)0xCC010000 + -32768) = 0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(u32 *)((u8 *)0xCC010000 + -32768) = 0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(u32 *)((u8 *)0xCC010000 + -32768) = 0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(u32 *)((u8 *)0xCC010000 + -32768) = 0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(u32 *)((u8 *)0xCC010000 + -32768) = 0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    fn_80009FF4();
}
