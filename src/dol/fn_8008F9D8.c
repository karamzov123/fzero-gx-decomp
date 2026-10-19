#include "sdk_addresses.h"

#include "types.h"

BOOL fn_8008F9D8(u32 count, const void *buffer, s32 size);

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
