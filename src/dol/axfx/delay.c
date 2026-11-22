#include "types.h"

typedef struct AXFXDelaySrc {
    s32 *unk_0;
    s32 *unk_4;
    s32 *unk_8;
} AXFXDelaySrc;

typedef struct AXFXDelayElem {
    s32 unk_0;
    s32 unk_4;
} AXFXDelayElem;

typedef struct AXFXDelay {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3C;
    u32 unk_40;
    u32 unk_44;
    u32 unk_48;
    u32 unk_4C;
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
    u32 unk_5C;
} AXFXDelay;

typedef void (*AXFXFreeFn)(u32);

extern u32 (*lbl_801A64F8)(u32);
extern u32 lbl_801A64FC;
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);

s32 fn_80025C70(AXFXDelay *arg0);

void fn_80025854(AXFXDelaySrc *arg0, AXFXDelay *arg1) {
    AXFXDelayElem *d;
    AXFXDelayElem *e;
    AXFXDelayElem *f;
    AXFXDelayElem *a;
    AXFXDelayElem *b;
    AXFXDelayElem *c;
    s32 x;
    s32 y;
    s32 z;
    s32 i;

    a = (AXFXDelayElem *)arg0->unk_0;
    b = (AXFXDelayElem *)arg0->unk_4;
    c = (AXFXDelayElem *)arg0->unk_8;
    d = (AXFXDelayElem *)((u8 *)arg1->unk_30 + arg1->unk_0C * 0x280);
    e = (AXFXDelayElem *)((u8 *)arg1->unk_34 + arg1->unk_10 * 0x280);
    f = (AXFXDelayElem *)((u8 *)arg1->unk_38 + arg1->unk_14 * 0x280);

    for (i = 0; i < 80; i++) {
        x = d->unk_0;
        y = e->unk_0;
        z = f->unk_0;
        d->unk_0 = a->unk_0 + ((x * arg1->unk_18) >> 7);
        e->unk_0 = b->unk_0 + ((y * arg1->unk_1C) >> 7);
        f->unk_0 = c->unk_0 + ((z * arg1->unk_20) >> 7);
        a->unk_0 = (x * arg1->unk_24) >> 7;
        b->unk_0 = (y * arg1->unk_28) >> 7;
        c->unk_0 = (z * arg1->unk_2C) >> 7;

        x = d->unk_4;
        y = e->unk_4;
        z = f->unk_4;
        d->unk_4 = a->unk_4 + ((x * arg1->unk_18) >> 7);
        e->unk_4 = b->unk_4 + ((y * arg1->unk_1C) >> 7);
        f->unk_4 = c->unk_4 + ((z * arg1->unk_20) >> 7);
        a->unk_4 = (x * arg1->unk_24) >> 7;
        b->unk_4 = (y * arg1->unk_28) >> 7;
        c->unk_4 = (z * arg1->unk_2C) >> 7;

        a++;
        b++;
        c++;
        d++;
        e++;
        f++;
    }

    arg1->unk_0C = (arg1->unk_0C + 1) % arg1->unk_00;
    arg1->unk_10 = (arg1->unk_10 + 1) % arg1->unk_04;
    arg1->unk_14 = (arg1->unk_14 + 1) % arg1->unk_08;
}

s32 fn_80025A24(AXFXDelay *arg0) {
    u32 i;
    u32 j;
    u32 t0;
    u32 *p0;
    u32 *p1;
    u32 *p2;
    s32 old;

    fn_80025C70(arg0);
    old = OSDisableInterrupts();

    arg0->unk_00 = (((arg0->unk_3C - 5) << 5) + 0x9f) / 160;
    arg0->unk_0C = 0;
    arg0->unk_18 = (arg0->unk_48 << 7) / 100;
    arg0->unk_24 = (arg0->unk_54 << 7) / 100;

    arg0->unk_04 = (((arg0->unk_40 - 5) << 5) + 0x9f) / 160;
    arg0->unk_10 = 0;
    arg0->unk_1C = (arg0->unk_4C << 7) / 100;
    arg0->unk_28 = (arg0->unk_58 << 7) / 100;

    arg0->unk_08 = (((arg0->unk_44 - 5) << 5) + 0x9f) / 160;
    arg0->unk_14 = 0;
    arg0->unk_20 = (arg0->unk_50 << 7) / 100;
    arg0->unk_2C = (arg0->unk_5C << 7) / 100;

    arg0->unk_30 = lbl_801A64F8(arg0->unk_00 * 0x280);
    arg0->unk_34 = lbl_801A64F8(arg0->unk_04 * 0x280);
    arg0->unk_38 = lbl_801A64F8(arg0->unk_08 * 0x280);

    p0 = (u32 *)arg0->unk_30;
    p1 = (u32 *)arg0->unk_34;
    p2 = (u32 *)arg0->unk_38;

    for (i = 0; i < arg0->unk_00 * 0xa0; i++) {
        *p0++ = 0;
    }
    i = 0;
    while (i < arg0->unk_04 * 0xa0) {
        *p1++ = 0;
        i++;
    }
    i = 0;
    while (i < arg0->unk_08 * 0xa0) {
        *p2++ = 0;
        i++;
    }

    OSRestoreInterrupts(old);
    return 1;
}

void fn_80025C28(AXFXDelay *state) {
    u32 interrupts;

    interrupts = OSDisableInterrupts();
    state->unk_30 = 0;
    state->unk_34 = 0;
    state->unk_38 = 0;
    OSRestoreInterrupts(interrupts);
    fn_80025A24(state);
}

#pragma opt_propagation off
s32 fn_80025C70(AXFXDelay *arg0) {
    u32 v0;
    u32 v1;
    u32 t0;

    t0 = OSDisableInterrupts();
    v0 = arg0->unk_30;
    v1 = t0;
    if (v0 != 0) {
        v1 = v0;
        ((AXFXFreeFn)lbl_801A64FC)(v0);
    }
    if (arg0->unk_34 != 0) {
        ((AXFXFreeFn)lbl_801A64FC)(arg0->unk_34);
    }
    if (arg0->unk_38 != 0) {
        ((AXFXFreeFn)lbl_801A64FC)(arg0->unk_38);
    }
    OSRestoreInterrupts(t0);
    return 1;
}
#pragma opt_propagation reset
