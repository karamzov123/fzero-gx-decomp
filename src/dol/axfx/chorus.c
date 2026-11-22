#include "types.h"

typedef struct AXFXChorusSrc {
    u32 *unk_0;
    u32 *unk_4;
    u32 *unk_8;
} AXFXChorusSrc;

typedef struct AXFXChorus {
    s32 *lastLeft[3];
    s32 *lastRight[3];
    s32 *lastSur[3];
    u8 currentLast;
    u8 pad_25[3];
    s32 oldLeft[4];
    s32 oldRight[4];
    s32 oldSur[4];
    u32 unk_58;
    u32 unk_5c;
    s32 unk_60;
    u32 unk_64;
    u32 unk_68;
    u32 *unk_6c;
    u32 *unk_70;
    void *unk_74;
    u32 unk_78;
    u32 unk_7c;
    u32 unk_80;
    s32 unk_84;
    u32 trigger;
    u32 target;
    u32 unk_90;
    u32 unk_94;
    u32 unk_98;
} AXFXChorus;

extern void *(*lbl_801A64F8)(u32);
extern u32 (*lbl_801A64FC)(void *);
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);
extern void fn_80024E6C(void *);
extern void fn_80025004(void *);

u32 fn_80025440(AXFXChorus *arg0);

s32 fn_800251F0(AXFXChorus *c) {
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

s32 fn_800253F0(AXFXChorus *arg0) {
    u32 t0;
    t0 = OSDisableInterrupts();
    lbl_801A64FC(arg0->lastLeft[0]);
    OSRestoreInterrupts(t0);
    return 1;
}

#pragma peephole off
u32 fn_80025440(AXFXChorus *arg0) {
    u32 t0;

    t0 = OSDisableInterrupts();
    arg0->unk_5c = 0x140 - ((arg0->unk_90 - 5) * 32);
    arg0->unk_58 = 0;
    arg0->unk_5c = (arg0->unk_5c + ((arg0->currentLast - 1) * 160)) % 480;
    arg0->unk_68 = (((arg0->unk_98 / 5) + 1) & ~1);
    arg0->unk_64 = arg0->unk_68 / 2;
    arg0->unk_60 = (arg0->unk_94 << 16) / (arg0->unk_68 * 5);
    OSRestoreInterrupts(t0);
    return 1;
}

#pragma opt_dead_assignments off
void fn_80025504(AXFXChorusSrc *arg0, AXFXChorus *arg1) {
    u32 v0;
    s32 v1;
    u8 v5;

    u32 *v12;
    u32 *v13;
    u32 *v14;
    u32 *v15;
    u32 *v16;
    u32 *v17;
    u32 v11;
    u32 v42;
    s32 v43;

    v1 = arg1->currentLast + 1;
    v15 = arg0->unk_0;
    v16 = arg0->unk_4;
    v17 = arg0->unk_8;
    v5 = v1 % 3;
    v12 = (u32 *)arg1->lastLeft[v5];
    v13 = (u32 *)arg1->lastRight[v5];
    v14 = (u32 *)arg1->lastSur[v5];
    for (v11 = 0; v11 < 160; v11++) {
        *v12++ = *v15++;
        *v13++ = *v16++;
        *v14++ = *v17++;
    }
    arg1->unk_84 = ((arg1->unk_60 >> 16) + 1);
    arg1->unk_80 = ((arg1->unk_60 & 0xFFFF) << 16);
    v42 = (arg1->unk_64 - 1);
    arg1->unk_64 = v42;
    if (v42 == 0) {
        arg1->unk_64 = arg1->unk_68;
        arg1->unk_60 = (-arg1->unk_60);
    }
    for (v43 = 0; (u32)v43 < 3; v43++) {
        arg1->unk_7c = arg1->unk_5c;
        arg1->unk_78 = arg1->unk_58;
        switch (v43) {
        case 0:
            arg1->unk_70 = (u32 *)arg1->lastLeft[0];
            arg1->unk_6c = arg0->unk_0;
            arg1->unk_74 = arg1->oldLeft;
            break;
        case 1:
            arg1->unk_70 = (u32 *)arg1->lastRight[0];
            arg1->unk_6c = arg0->unk_4;
            arg1->unk_74 = arg1->oldRight;
            break;
        case 2:
            arg1->unk_70 = (u32 *)arg1->lastSur[0];
            arg1->unk_6c = arg0->unk_8;
            arg1->unk_74 = arg1->oldSur;
            break;
        }
        switch (arg1->unk_84) {
        case 0:
            fn_80024E6C(&arg1->unk_6c);
            break;
        case 1:
            fn_80025004(&arg1->unk_6c);
            break;
        }
    }
    arg1->unk_5c = arg1->unk_7c % 480;
    arg1->unk_58 = arg1->unk_78;
    arg1->currentLast = v5;
}
#pragma opt_dead_assignments reset
#pragma peephole reset
