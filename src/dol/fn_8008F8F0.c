#include "types.h"
#include "sdk_addresses.h"
#include <dolphin/types.h>


/* --- dol/fn_8008F8F0.c --- */
extern u32 lbl_801A6E28;
extern u8 lbl_801A6E3C;

void fn_8008F8F0(void) {
    lbl_801A6E3C = 1;
    if (lbl_801A6E28 != 0) {
        ((void (*)(s32))lbl_801A6E28)(0);
    }
}

/* --- dol/fn_8008F92C.c --- */
/* --- dol/fn_8008F92C.c --- */
BOOL fn_8008F92C(u32 *value);

// Hardware or OS state can change asynchronously.
volatile u32 __EXIRegs[] : FZGX_ADDR___EXIRegs;

BOOL fn_8008FC3C(void *buffer, s32 bytecounter, u32 write);

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

BOOL fn_8008F92C(u32 *value) { return _DBGReadStatus(value); }

/* --- dol/fn_8008F9D8.c --- */
BOOL fn_8008F9D8(u32 count, const void *buffer, s32 size);

// Hardware or OS state can change asynchronously.

BOOL fn_8008FC3C(void *buffer, s32 bytecounter, u32 write);




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

/* --- dol/fn_8008FAB4.c --- */
BOOL fn_8008FAB4(u32 count, u32 *buffer, s32 size);

// Hardware or OS state can change asynchronously.

BOOL fn_8008FC3C(void *buffer, s32 bytecounter, u32 write);




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

/* --- dol/fn_8008FB90.c --- */
BOOL fn_8008FB90(u32 *value);

// Hardware or OS state can change asynchronously.

BOOL fn_8008FC3C(void *buffer, s32 bytecounter, u32 write);




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

/* --- dol/fn_8008FC3C.c --- */
/* --- dol/fn_8008FC3C.c --- */
vu32 __EXIRegs[16] : FZGX_ADDR___EXIRegs;

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
