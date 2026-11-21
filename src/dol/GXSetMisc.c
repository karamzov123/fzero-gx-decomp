#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
#include "types.h"

void GXSetMisc(u32 arg0, u32 arg1) {
    GXData *p;

    switch ((s32)arg0) {
    case 0:
        break;
    case 1:
        p = gx;
        p->vNum = arg1;
        p->vNumNot = (__cntlzw(p->vNum) >> 5) & 0xFFFF;
        p->bpSentNot = 1;
        if (p->vNum != 0) {
            p->dirtyState |= 8;
        }
        break;
    case 2:
        gx->dlSaveContext = (arg1 != 0);
        break;
    case 3:
        gx->abtWaitPECopy = (arg1 != 0);
        break;
    }
}

extern u32 fn_80009FF4(void);
extern u32 fn_8003458C(void);

void GXFlush(void) {
    if (gx->dirtyState != 0) {
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
