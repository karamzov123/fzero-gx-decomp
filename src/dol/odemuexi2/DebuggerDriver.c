#include "types.h"
#include "sdk_addresses.h"
#include "dolphin/types.h"
#include "dolphin/os/OSInterrupt.h"
#include <dolphin/types.h>

// fn_8008F454: empty in retail (single blr).
void fn_8008F454(void) {
}

// fn_8008F458: empty in retail (single blr).
void fn_8008F458(void) {
}

int fn_8008F45C(const void *src, int size);

int OSDisableInterrupts(void);

int OSRestoreInterrupts(int enabled);

// Hardware or OS state can change asynchronously.
volatile u32 __EXIRegs[] : FZGX_ADDR___EXIRegs;

extern u8 lbl_801A6688;

BOOL fn_8008FC3C(void *buf, s32 len, u32 type);

BOOL fn_8008F9D8(u32 count, const void *buffer, s32 size);

static inline u32 DBGEXISelect(u32 device) {
    u32 state = __EXIRegs[10];
    state &= 0x405;
    state |= 0x80 | (device << 4);
    __EXIRegs[10] = state;
    return 1;
}

static inline BOOL DBGEXIDeselect(void) {
    __EXIRegs[10] &= 0x405;
    return 1;
}

static inline BOOL DBGEXISync(void) {
    while (__EXIRegs[13] & 1) {
    }
    return 1;
}

static inline BOOL DBGWriteMailbox(u32 p1) {
    u32 cmd = (3u << 30);
    u32 v;
    u32 base = p1;
    BOOL total = 0;
    DBGEXISelect(4);
    v = (base & 0x1FFFFFFF) | cmd;
    total |= !((fn_8008FC3C(&v, sizeof(v), 1)) != 0);
    total |= !((DBGEXISync()) != 0);
    total |= !((DBGEXIDeselect()) != 0);
    return !((total) != 0);
}

static inline BOOL _DBGReadStatus(u32 *p1) {
    BOOL total = 0;
    u32 v;
    DBGEXISelect(4);
    v = 1 << 30;
    total |= !((fn_8008FC3C(&v, 2, 1)) != 0);
    total |= !((DBGEXISync()) != 0);
    total |= !((fn_8008FC3C(p1, sizeof(*p1), 0)) != 0);
    total |= !((DBGEXISync()) != 0);
    total |= !((DBGEXIDeselect()) != 0);
    return !((total) != 0);
}

int fn_8008F45C(const void *src, int size) {
    u32 v;
    u32 busyFlag;
    BOOL interrupts = OSDisableInterrupts();
    do {
        _DBGReadStatus(&busyFlag);
    } while (busyFlag & 2);
    lbl_801A6688++;
    v = (lbl_801A6688 & 1) ? 0x1000 : 0;
    while (!fn_8008F9D8(v | 0x1C000, src, (((size) + (4) - 1) & (-(4))))) {
    }
    do {
        _DBGReadStatus(&busyFlag);
    } while (busyFlag & 2);
    v = lbl_801A6688;
    while (!DBGWriteMailbox((0x1F000000) | v << 0x10 | size)) {
    }
    do {
        while (!_DBGReadStatus(&busyFlag)) {
        }
    } while (busyFlag & 2);
    OSRestoreInterrupts(interrupts);
    return 0;
}

extern u32 lbl_801A6E30;
BOOL fn_8008FAB4(u32 count, u32 *buffer, s32 size);
extern s32 lbl_801A6E34;
extern u8 lbl_801A6E3C;

u32 fn_8008F6BC(u32 arg0, u32 arg1) {
    u32 interrupt_state;
    u32 base;
    interrupt_state = OSDisableInterrupts();
    if (lbl_801A6E30 & 0x10000) {
        base = 0x1000;
    } else {
        base = 0;
    }
    base += 0x20000;
    base -= 0x2000;
    fn_8008FAB4(base, (u32 *)arg0, (arg1 + 3) & ~3);
    lbl_801A6E34 = 0;
    lbl_801A6E3C = 0;
    OSRestoreInterrupts(interrupt_state);
    return 0;
}

BOOL fn_8008F92C(u32 *value);
BOOL fn_8008FB90(u32 *value);

u32 fn_8008F748(void) {
    u32 v0;
    u32 v1;

    lbl_801A6E3C = 0;
    if (lbl_801A6E34 == 0) {
        v0 = OSDisableInterrupts();
        fn_8008F92C(&v1);
        if (v1 & 1) {
            fn_8008FB90(&v1);
            v1 &= 0x1FFFFFFF;
            if ((v1 & 0x1F000000) == 0x1F000000) {
                lbl_801A6E30 = v1;
                lbl_801A6E34 = v1 & 0x7FFF;
                lbl_801A6E3C = 1;
            }
        }
        OSRestoreInterrupts(v0);
    }
    return lbl_801A6E34;
}

extern u32 __OSMaskInterrupts(u32);
extern u32 __OSSetInterruptHandler(u32, u32);
extern u32 __OSUnmaskInterrupts(u32);
extern u32 lbl_801A6E2C;
void fn_8008F8B0(s32 arg0, void *arg1);
void fn_8008F8F0(void);

u32 fn_8008F7E4(void) {
    __OSMaskInterrupts((0x20000 + -32768));
    __OSMaskInterrupts(64);
    lbl_801A6E2C = (u32)fn_8008F8F0;
    __OSSetInterruptHandler(25, (u32)fn_8008F8B0);
    return __OSUnmaskInterrupts(64);
}

extern u32 lbl_801A6E38;
extern u32 lbl_801A6E28;

vu32 __EXIRegs[16] : FZGX_ADDR___EXIRegs;

void fn_8008F838(u32 *arg0, u32 arg1) {
    BOOL enabled = OSDisableInterrupts();
    lbl_801A6E38 = (u32)&lbl_801A6E3C;
    *arg0 = lbl_801A6E38;
    lbl_801A6E28 = arg1;
    __OSMaskInterrupts(0x18000);
    __EXIRegs[10] = 0;
    OSRestoreInterrupts(enabled);
}

vu32 __PIRegs[16] : FZGX_ADDR___PIRegs;

void fn_8008F8B0(s32 arg0, void *arg1) {
    __PIRegs[0] = 0x1000;
    if (lbl_801A6E2C != 0) {
        ((void (*)(s16, void *))lbl_801A6E2C)(arg0, arg1);
    }
}


void fn_8008F8F0(void) {
    lbl_801A6E3C = 1;
    if (lbl_801A6E28 != 0) {
        ((void (*)(s32))lbl_801A6E28)(0);
    }
}


// Hardware or OS state can change asynchronously.






BOOL fn_8008F92C(u32 *value) { return _DBGReadStatus(value); }


// Hardware or OS state can change asynchronously.





BOOL fn_8008F9D8(u32 count, const void *buffer, s32 size) {
    BOOL failed = 0;
    const u32 *cursor = buffer;
    u32 command;
    u32 value;
    DBGEXISelect(4);
    command = (count & 0x1FFFC) << 8 | 0xA0000000;
    failed |= !((fn_8008FC3C(&command, sizeof(command), 1)) != 0);
    failed |= !((DBGEXISync()) != 0);
    while (size != 0) {
        value = *cursor++;
        failed |= !((fn_8008FC3C(&value, sizeof(value), 1)) != 0);
        failed |= !((DBGEXISync()) != 0);
        size -= sizeof(*cursor);
        if (size < 0) {
            size = 0;
        }
    }
    failed |= !((DBGEXIDeselect()) != 0);
    return !((failed) != 0);
}


// Hardware or OS state can change asynchronously.





BOOL fn_8008FAB4(u32 count, u32 *buffer, s32 size) {
    BOOL failed = 0;
    u32 *cursor = buffer;
    u32 command;
    u32 value;
    DBGEXISelect(4);
    command = (count & 0x1FFFC) << 8 | 0x20000000;
    failed |= !((fn_8008FC3C(&command, sizeof(command), 1)) != 0);
    failed |= !((DBGEXISync()) != 0);
    while (size != 0) {
        failed |= !((fn_8008FC3C(&value, sizeof(value), 0)) != 0);
        failed |= !((DBGEXISync()) != 0);
        *cursor++ = value;
        size -= sizeof(*cursor);
        if (size < 0) {
            size = 0;
        }
    }
    failed |= !((DBGEXIDeselect()) != 0);
    return !((failed) != 0);
}


// Hardware or OS state can change asynchronously.





BOOL fn_8008FB90(u32 *value) {
    BOOL total = 0;
    u32 v;
    DBGEXISelect(4);
    v = 0x60000000;
    total |= !((fn_8008FC3C(&v, 2, 1)) != 0);
    total |= !((DBGEXISync()) != 0);
    total |= !((fn_8008FC3C(value, sizeof(*value), 0)) != 0);
    total |= !((DBGEXISync()) != 0);
    total |= !((DBGEXIDeselect()) != 0);
    return !((total) != 0);
}


BOOL fn_8008FC3C(void *buf, s32 len, u32 type) {
    u32 data;
    int i;

    if (type != 0) {
        data = 0;
        for (i = 0; i < len; i++) {
            data |= ((u8 *)buf)[i] << ((3 - i) * 8);
        }
        __EXIRegs[2 * 5 + 4] = data;
    }
    __EXIRegs[2 * 5 + 3] = 1 | (type << 2) | ((len - 1) << 4);
    while (__EXIRegs[2 * 5 + 3] & 1) {
    }
    if (type == 0) {
        data = __EXIRegs[2 * 5 + 4];
        for (i = 0; i < len; i++) {
            *((u8 *)buf)++ = (u8)(data >> ((3 - i) * 8));
        }
    }
    return TRUE;
}
