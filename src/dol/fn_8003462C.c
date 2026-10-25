#include "types.h"

typedef struct GXState {
    u32 state;
    u8 pad0[0x4f0];
    u32 flags;
} GXState;

extern GXState *gx;

extern u32 __GXSetSUTexRegs(void);
extern u32 fn_80036F24(void);
extern u32 __GXSetGenMode(void);
extern u32 __GXSetVCD(void);
extern u32 fn_80033650(void);
extern u32 __GXCalculateVLim(void);
extern void __GXSendFlushPrim(void);

void fn_8003462C(u32 arg0, u32 arg1, u32 arg2) {
    if (gx->flags != 0) {
        if (gx->flags & 1) {
            __GXSetSUTexRegs();
        }
        if (gx->flags & 2) {
            fn_80036F24();
        }
        if (gx->flags & 4) {
            __GXSetGenMode();
        }
        if (gx->flags & 8) {
            __GXSetVCD();
        }
        if (gx->flags & 0x10) {
            fn_80033650();
        }
        if (gx->flags & 0x18) {
            __GXCalculateVLim();
        }
        gx->flags = 0;
    }

    if (gx->state == 0) {
        __GXSendFlushPrim();
    }

    *(volatile u8 *)((u8 *)0xCC010000 + -32768) = (u8)(arg1 | arg0); /* fzgx-allow: A1,A2 GX FIFO hardware register */
    *(volatile u16 *)((u8 *)0xCC010000 + -32768) = arg2; /* fzgx-allow: A1,A2 GX FIFO hardware register */
}
