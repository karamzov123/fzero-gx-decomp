#include "types.h"


/* --- dol/fn_80023228.c --- */
extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32);

typedef struct Fn80023228Work {
    u8 _pad0[0x1c];
    u32 flags;
    u8 _pad1[0x158];
    s16 field_178;
    s16 field_17a;
} Fn80023228Work;

void fn_80023228(Fn80023228Work *work, s16 field_178, s16 field_17a) {
    u32 interrupts;
    interrupts = OSDisableInterrupts();
    work->field_178 = field_178;
    work->field_17a = field_17a;
    work->flags = work->flags | 0x40;
    OSRestoreInterrupts(interrupts);
}

/* --- dol/fn_80023284.c --- */
typedef struct fn_80023284_Work {
    u8 _pad0[0x1c];
    u32 flags;
} fn_80023284_Work;

void fn_80023284(fn_80023284_Work *work, u8 *src) {
    BOOL old;
    u8 *dst;
    dst = (u8 *)work + 0x1a6;
    old = OSDisableInterrupts();

    *(u32 *)(dst + 0x0) = *(u32 *)(src + 0x0);
    *(u32 *)(dst + 0x4) = *(u32 *)(src + 0x4);
    *(u32 *)(dst + 0x8) = *(u32 *)(src + 0x8);
    *(u32 *)(dst + 0xc) = *(u32 *)(src + 0xc);

    switch (*(u16 *)(src + 2)) {
    case 0:
        break;
    case 10:
        *(u32 *)(dst + 0x10) = 0;
        *(u32 *)(dst + 0x14) = 0;
        *(u32 *)(dst + 0x18) = 0;
        *(u32 *)(dst + 0x1c) = 0;
        *(u32 *)(dst + 0x20) = 0;
        *(u32 *)(dst + 0x24) = 0;
        *(u32 *)(dst + 0x28) = 0;
        *(u32 *)(dst + 0x2c) = 0;
        *(u32 *)(dst + 0x30) = 0x08000000;
        *(u32 *)(dst + 0x34) = 0;
        break;
    case 25:
        *(u32 *)(dst + 0x10) = 0;
        *(u32 *)(dst + 0x14) = 0;
        *(u32 *)(dst + 0x18) = 0;
        *(u32 *)(dst + 0x1c) = 0;
        *(u32 *)(dst + 0x20) = 0;
        *(u32 *)(dst + 0x24) = 0;
        *(u32 *)(dst + 0x28) = 0;
        *(u32 *)(dst + 0x2c) = 0;
        *(u32 *)(dst + 0x30) = 0x01000000;
        *(u32 *)(dst + 0x34) = 0;
        break;
    }

    work->flags = work->flags & 0xFFFE1FFF;
    work->flags = (work->flags | 0x20000) | 0x1000;
    OSRestoreInterrupts(old);
}
