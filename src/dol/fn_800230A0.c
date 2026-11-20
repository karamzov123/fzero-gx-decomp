#include "types.h"


/* --- dol/fn_800230A0.c --- */
// fn_800230A0: empty in retail (single blr).
void fn_800230A0(void) {
}

/* --- dol/fn_800230A4.c --- */
/* --- dol/fn_800230A4.c --- */
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);

void fn_800230A4(void *arg0, s32 arg1) {
    s32 temp_r3;
    void *temp_r4;

    temp_r3 = OSDisableInterrupts();
    temp_r4 = ((u8 *)(arg0) + 0x138);
    switch (arg1) {                                 /* irregular */
    case 0:
        (*(s16 *)((u8 *)(temp_r4) + 8)) = 2;
        break;
    case 1:
        (*(s16 *)((u8 *)(temp_r4) + 8)) = 1;
        break;
    case 2:
        (*(s16 *)((u8 *)(temp_r4) + 8)) = 0;
        (*(s16 *)((u8 *)(temp_r4) + 10)) = 0;
        break;
    case 3:
        (*(s16 *)((u8 *)(temp_r4) + 8)) = 0;
        (*(s16 *)((u8 *)(temp_r4) + 10)) = 1;
        break;
    case 4:
        (*(s16 *)((u8 *)(temp_r4) + 8)) = 0;
        (*(s16 *)((u8 *)(temp_r4) + 10)) = 2;
        break;
    }
    (*(s32 *)((u8 *)(arg0) + 28)) = ((*(s32 *)((u8 *)(arg0) + 28)) | 1);
    OSRestoreInterrupts(temp_r3);
}

/* --- dol/fn_80023168.c --- */
typedef struct Fn80023168State {
    u8 pad_000[0x1c];
    u32 flags;
    u32 state;
    u8 pad_024[0x122];
    u16 value;
} Fn80023168State;

void fn_80023168(Fn80023168State *state, u16 value) {
    u32 level = OSDisableInterrupts();

    state->value = value;
    state->flags |= 4;
    if (value == 0) {
        state->state = 1;
    }

    OSRestoreInterrupts(level);
}

/* --- dol/fn_800231C4.c --- */
/* --- dol/fn_800231C4.c --- */

typedef struct Fn800231C4Work {
    u8 _pad0[0x1c];
    u32 flags;
    u8 _pad1[0x14e];
    s16 field_16e;
    u8 _pad2[4];
    s16 field_174;
    s16 field_176;
    s16 field_178;
    s16 field_17a;
} Fn800231C4Work;

void fn_800231C4(Fn800231C4Work *work) {
    u32 interrupts = OSDisableInterrupts();
    work->field_16e = 1;
    work->field_17a = 0;
    work->field_178 = 0;
    work->field_176 = 0;
    work->field_174 = 0;
    work->flags = work->flags & ~0x40;
    work->flags = work->flags | 0x20;
    OSRestoreInterrupts(interrupts);
}

/* --- dol/fn_80023228.c --- */
/* --- dol/fn_80023228.c --- */

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
