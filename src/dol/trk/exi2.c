#include "types.h"
#include "dolphin/types.h"
#include "dolphin/os/OSInterrupt.h"
#include "sdk_addresses.h"

/* AMC EXI2: the debugger's EXI channel 2 link (an EXIBios copy for channel 2 plus the EXI2_* API). */

typedef void (*EXI2Callback)(s32 chan, void *context);

typedef struct EXI2Control {
    EXI2Callback exiCallback;
    EXI2Callback tcCallback;
    EXI2Callback extCallback;
    vu32 state;
    int immLen;
    u8 *immBuf;
} EXI2Control;

#define EXI_STATE_DMA 0x01
#define EXI_STATE_IMM 0x02
#define EXI_STATE_BUSY (EXI_STATE_DMA | EXI_STATE_IMM)
#define EXI_STATE_SELECTED 0x04

#define EXI_READ 0
#define EXI_WRITE 1

extern vu32 __EXIRegs[16] : FZGX_ADDR___EXIRegs;
extern vu32 __PIRegs[16] : FZGX_ADDR___PIRegs;
extern vu32 __SIRegs[16] : FZGX_ADDR___SIRegs;

extern OSInterruptMask __OSMaskInterrupts(OSInterruptMask mask);
extern OSInterruptMask __OSUnmaskInterrupts(OSInterruptMask mask);
extern void *__OSSetInterruptHandler(s16 interrupt, void *handler);
extern void *memset(void *dst, int value, u32 size);
extern int printf(const char *format, ...);

extern EXI2Control lbl_801A6398;
extern EXI2Control *lbl_801A6678;
extern u8 *lbl_801A6680;
extern s32 lbl_801A6E1C;
void (*lbl_801A6E20)(s32) __attribute__((aligned(16)));

void fn_8008EB4C(s32 pi, s32 exi);

/* WARNING: compiler-diff device, not original code: opt_propagation off keeps chan and the loop
   index unpropagated and the unused padding array reserves retail's 8 frame bytes. */
#pragma opt_propagation off
BOOL fn_8008E770(void *arg0, s32 arg1, u32 arg2, EXI2Callback arg3) {
    s32 chan = 2;
    BOOL old;
    u32 data;
    s32 i;
    vu32 *state;
    u32 padding[2];
    old = OSDisableInterrupts();
    state = &lbl_801A6678->state;
    if ((*state & 3) || !(*state & 4)) {
        OSRestoreInterrupts(old);
        return 0;
    }
    lbl_801A6678->tcCallback = arg3;
    if (lbl_801A6678->tcCallback != 0) {
        fn_8008EB4C(0, 1);
        __OSUnmaskInterrupts(0x200000u >> (chan * 3));
    }
    lbl_801A6678->state |= 2;
    if (arg2 != 0) {
        i = 0;
        data = 0;
        for (; i < arg1; i++) {
            data |= ((u8 *)arg0)[i] << ((3 - i) * 8);
        }
        __EXIRegs[14] = data;
    }
    lbl_801A6678->immBuf = arg0;
    lbl_801A6678->immLen = arg2 != 1 ? arg1 : 0;
    __EXIRegs[13] = (arg2 << 2) | 1 | ((arg1 - 1) << 4);
    OSRestoreInterrupts(old);
    return 1;
}
#pragma opt_propagation reset

void fn_8008E9B4(void) {
    BOOL enabled;
    s32 len;
    s32 i;
    u32 data;
    u8 *buf;

    while (lbl_801A6678->state & EXI_STATE_SELECTED) {
        if (__EXIRegs[13] & 1) {
            continue;
        }
        enabled = OSDisableInterrupts();
        if (lbl_801A6678->state & EXI_STATE_BUSY) {
            if (lbl_801A6678->state & EXI_STATE_IMM) {
                len = lbl_801A6678->immLen;
                if (len != 0) {
                    buf = lbl_801A6678->immBuf;
                    data = __EXIRegs[14];
                    for (i = 0; i < len; i++) {
                        *buf++ = data >> ((3 - i) * 8);
                    }
                }
            }
            lbl_801A6678->state &= ~EXI_STATE_BUSY;
        }
        OSRestoreInterrupts(enabled);
        break;
    }
}

void fn_8008EB4C(s32 pi, s32 exi) {
    if (pi) {
        __PIRegs[0] = (__PIRegs[0] & 0x1000) | 0x1000;
    }
    if (exi) {
        __EXIRegs[10] = (__EXIRegs[10] & 0x7F5) | 0x8;
    }
}

EXI2Callback fn_8008EB8C(EXI2Callback callback) {
    BOOL enabled;
    EXI2Callback prev;

    enabled = OSDisableInterrupts();
    if (callback) {
        __OSUnmaskInterrupts(64);
    } else {
        __OSMaskInterrupts(64);
    }
    prev = lbl_801A6678->exiCallback;
    lbl_801A6678->exiCallback = callback;
    OSRestoreInterrupts(enabled);
    return prev;
}

BOOL fn_8008EBF8(u32 freq) {
    BOOL enabled;
    u32 cpr;

    enabled = OSDisableInterrupts();
    if (lbl_801A6678->state & EXI_STATE_SELECTED) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }
    lbl_801A6678->state |= EXI_STATE_SELECTED;
    cpr = __EXIRegs[10];
    cpr &= 0x405;
    cpr |= (freq << 4) | 0x80;
    __EXIRegs[10] = cpr;
    OSRestoreInterrupts(enabled);
    return TRUE;
}

BOOL fn_8008EC78(void) {
    BOOL enabled;
    u32 cpr;

    enabled = OSDisableInterrupts();
    if (!(lbl_801A6678->state & EXI_STATE_SELECTED)) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }
    lbl_801A6678->state &= ~EXI_STATE_SELECTED;
    cpr = __EXIRegs[10];
    __EXIRegs[10] = cpr & 0x405;
    OSRestoreInterrupts(enabled);
    return TRUE;
}

void fn_8008ECE0(s16 interrupt, void *context) {
    EXI2Callback callback;

    __PIRegs[0] = (__PIRegs[0] & 0x1000) | 0x1000;
    callback = lbl_801A6678->exiCallback;
    if (callback != 0) {
        callback(2, context);
    }
}

OSInterruptMask fn_8008ED30(void) {
    __OSMaskInterrupts(0x8000);
    __OSSetInterruptHandler(25, fn_8008ECE0);
    return __OSUnmaskInterrupts(64);
}

void fn_8008ED70(void) {
    memset(&lbl_801A6398, 0, sizeof(EXI2Control));
    __EXIRegs[10] = 0;
    __SIRegs[15] = 0;
}

void fn_8008EDB0(void) {
    *lbl_801A6680 = 1;
    if (lbl_801A6E20 != 0) {
        lbl_801A6E20(0);
    }
}

BOOL fn_8008EDF0(u8 **flag, void (*callback)(s32)) {
    BOOL status;
    u32 zero;
    u32 id;
    u32 cmd[3];

    *flag = lbl_801A6680;
    status = OSDisableInterrupts();
    lbl_801A6E20 = callback;
    OSRestoreInterrupts(status);
    fn_8008ED70();
    zero = 0;
    id = 0x1000003;
    status = FALSE;
    while (!status) {
        status = fn_8008EBF8(5);
    }
    cmd[0] = 0x80000000;
    fn_8008E770(cmd, 2, EXI_WRITE, 0);
    fn_8008E9B4();
    fn_8008E770(&id, 4, EXI_WRITE, 0);
    fn_8008E9B4();
    fn_8008E770(&zero, 4, EXI_WRITE, 0);
    fn_8008E9B4();
    return fn_8008EC78();
}

void fn_8008EEAC(void) {
    fn_8008EB8C((EXI2Callback)fn_8008EDB0);
    fn_8008ED30();
}

u32 fn_8008EED8(void) {
    u32 length;
    u32 reply;
    u32 cmd[3];
    BOOL selected;

    if ((__PIRegs[0] & 0x1000) == 0 && *lbl_801A6680 == 0) {
        length = 0;
    } else {
        if (lbl_801A6E1C == 0) {
            selected = FALSE;
            while (!selected) {
                selected = fn_8008EBF8(5);
            }
            if (!selected) {
                printf("Can't select EXI2 port!\n");
            } else {
                lbl_801A6E1C = 1;
                cmd[0] = 0;
                fn_8008E770(cmd, 2, EXI_WRITE, 0);
                fn_8008E9B4();
                fn_8008E770(&reply, 2, EXI_READ, 0);
                fn_8008E9B4();
            }
        }
        fn_8008E770(&length, 4, EXI_READ, 0);
        fn_8008E9B4();
        if (*lbl_801A6680 == 0) {
            u16 pi = __PIRegs[0];
            *lbl_801A6680 = 1;
            __PIRegs[0] = pi & 0x1000;
        }
    }
    return length;
}


/* WARNING: compiler-diff device, not original code: opt_dead_assignments off keeps the dead tail stores (status/rem/off after the loop) that shape allocation; without the pragma 56 diff lines, without only the tail stores 36 */
#pragma opt_dead_assignments off
s32 fn_8008EFE0(u8 *arg0, u32 arg1) {
    u32 loc_20;
    u32 loc_1C;
    u32 loc_14[2];
    s32 i;
    s32 v1;
    /* WARNING: compiler-diff device, not original code: one-field carrier; plain u32 flag 48 diff lines */
    struct { u32 value; } flag;
    s32 rem;
    u32 last;
    u32 off;
    u32 idx;
    u32 odd;
    u32 size;
    s32 n;
    s32 status;
    s32 v1_2;
    u32 count;
    if ((s32)lbl_801A6E1C != 0) {
        status = 1;
    } else {
        v1 = 0;
        while (0 == v1) {
            v1 = fn_8008EBF8(5);
        }
        status = v1;
        if (v1 == 0) {
            printf("Can't select EXI2 port!\n");
            status = 0;
        } else {
            lbl_801A6E1C = 1;
            loc_14[0] = 0;
            fn_8008E770(loc_14, 2, EXI_WRITE, 0);
            fn_8008E9B4();
            fn_8008E770(&loc_1C, 2, EXI_READ, 0);
            fn_8008E9B4();
        }
    }
    if (status == 0) return 1;
    if (arg1 & 3) flag.value = 1;
    else flag.value = 0;
{
    /* WARNING: compiler-diff device, not original code: lifter loop copies whose final values are stored into dead locals after the loop (kept by the pragma above); deleting the tail stores 36 diff lines */
    s32 fzgx_loop_rem_1266;
    u32 fzgx_loop_off_1266;
    count = (arg1 >> 2) + flag.value;
    odd = (arg1 & 3) + (arg1 & 1);
    fzgx_loop_rem_1266 = (s32)arg1 % 4;
    v1_2 = count - 1;
    last = v1_2;
    fzgx_loop_off_1266 = 0;
    idx = 0;
    while (fzgx_loop_off_1266 < arg1) {
        if (idx < last) size = 4;
        else if (odd == 2) size = 2;
        else size = 4;
        fn_8008E770(&loc_20, size, EXI_READ, 0);
        fn_8008E9B4();
        if (arg1 - fzgx_loop_off_1266 >= 4) n = 4;
        else n = fzgx_loop_rem_1266;
        for (i = 0; i < n; i++) {
            (arg0 + fzgx_loop_off_1266)[i] = (loc_20 >> (8 * (3 - i)));
        }
        idx++;
        fzgx_loop_off_1266 += 4;
    }
    status = fzgx_loop_rem_1266;
    rem = status;
    off = fzgx_loop_off_1266;
}
    fn_8008EC78();
    lbl_801A6E1C = 0;
    *lbl_801A6680 = 0;
    return 0;
}
#pragma opt_dead_assignments reset

/* WARNING: compiler-diff device, not original code: opt_common_subs off around fn_8008F29C; without it 12 diff lines */
#pragma opt_common_subs off
s32 fn_8008F29C(u8 *arg0, u32 arg1) {
    u8 *v0;
    s32 v1;
    s32 v8;
    u32 v3;
    /* WARNING: compiler-diff device, not original code: one-field carrier; plain u32 v5 22 diff lines (32 with the pragma also removed) */
    struct { u32 value; } v5;
    u32 v6;
    u32 v2;
    u32 loc_28;
    u32 loc_24;
    u32 loc_18[3];
    u32 loc_10[2];
    v0 = arg0;
    loc_28 = arg1;
    v1 = 0;
    while (!v1) {
        v1 = fn_8008EBF8(5);
    }
    if (v1 == 0) return 1;
    loc_18[0] = 0x80000000;
    fn_8008E770(loc_18, 2, EXI_WRITE, 0);
    fn_8008E9B4();
    fn_8008E770(&loc_28, 4, EXI_WRITE, 0);
    fn_8008E9B4();
    {
        u32 v9 = loc_28;
        if ((v9 & 3) != 0) v2 = 1;
        else v2 = 0;
        v3 = (v9 >> 2) + v2;
    }
    v5.value = 0;
    while (v5.value < v3) {
        u8 *v7;
        if (v5.value < v3 - 1) v6 = 4;
        else if ((loc_28 & 3) + (loc_28 & 1) == 2) v6 = 2;
        else v6 = 4;
        v7 = v0;
        v0 += 4;
        fn_8008E770(v7, v6, EXI_WRITE, 0);
        fn_8008E9B4();
        v5.value++;
    }
    fn_8008EC78();
    v8 = 0;
    while (((0) == v8)) {
        v8 = fn_8008EBF8(5);
    }
    if (((0) == v8)) return 1;
    loc_10[0] = 0x10000;
    fn_8008E770(loc_10, 2, EXI_WRITE, 0);
    fn_8008E9B4();
    fn_8008E770(&loc_24, 2, EXI_READ, 0);
    fn_8008E9B4();
    do {
        fn_8008E770(&loc_24, 2, EXI_READ, 0);
    fn_8008E9B4();
    } while (((loc_24 >> 16) & 1) == 0);
    fn_8008EC78();
    return 0;
}
#pragma opt_common_subs reset

void fn_8008F44C(void) {
}

void fn_8008F450(void) {
}
