#include <types.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>

void GXCallDisplayList(void *list, u32 nbytes);

void fn_8003458C(void);

void __GXSendFlushPrim(void);
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

void GXCallDisplayList(void *list, u32 nbytes) {
    if (gx->dirtyState != 0) {
        fn_8003458C();
    }
    if (*(u32 *)gx == 0) {
        __GXSendFlushPrim();
    }
    GXFIFO.u8 = 0x40;
    GXFIFO.u32 = (u32)list;
    GXFIFO.u32 = nbytes;
}
