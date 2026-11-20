#include "types.h"

/* --- dol/fn_800251F0.c --- */
typedef struct fn_800251F0_Chorus {
    s32 *lastLeft[3];
    s32 *lastRight[3];
    s32 *lastSur[3];
    u8 currentLast;
    u8 pad_25[3];
    s32 oldLeft[4];
    s32 oldRight[4];
    s32 oldSur[4];
    u8 pad_58[0x30];
    u32 trigger;
    u32 target;
} fn_800251F0_Chorus;

extern void *(*lbl_801A64F8)(u32);
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);
extern s32 fn_80025440(fn_800251F0_Chorus *c);

s32 fn_800251F0(fn_800251F0_Chorus *c) {
    s32 *left;
    s32 *right;
    s32 *sur;
    u32 i;
    BOOL old;

    old = OSDisableInterrupts();
    c->lastLeft[0] = lbl_801A64F8(0x1680);
    if (c->lastLeft[0] != NULL) {
        c->lastRight[0] = c->lastLeft[0] + 480;
        c->lastSur[0] = c->lastRight[0] + 480;
        for (i = 1; i < 3; i++) {
            c->lastLeft[i] = c->lastLeft[0] + i * 160;
            c->lastRight[i] = c->lastRight[0] + i * 160;
            c->lastSur[i] = c->lastSur[0] + i * 160;
        }
        left = c->lastLeft[0];
        right = c->lastRight[0];
        sur = c->lastSur[0];
        for (i = 0; i < 320; i++) {
            *left++ = 0;
            *right++ = 0;
            *sur++ = 0;
        }
        c->currentLast = 1;
        c->oldLeft[0] = c->oldLeft[1] = c->oldLeft[2] = c->oldLeft[3] = 0;
        c->oldRight[0] = c->oldRight[1] = c->oldRight[2] = c->oldRight[3] = 0;
        c->oldSur[0] = c->oldSur[1] = c->oldSur[2] = c->oldSur[3] = 0;
        c->trigger = 480;
        c->target = 0;
        OSRestoreInterrupts(old);
        return fn_80025440(c);
    }
    OSRestoreInterrupts(old);
    return 0;
}

/* --- dol/fn_800253F0.c --- */
struct fn_800253F0_Arg0 {
    u32 unk_0;
};

extern u32 (*lbl_801A64FC)(u32);

s32 fn_800253F0(struct fn_800253F0_Arg0 *arg0) {
    u32 t0;
    t0 = OSDisableInterrupts();
    lbl_801A64FC(arg0->unk_0);
    OSRestoreInterrupts(t0);
    return 1;
}
