#include "sdk_addresses.h"

#include "types.h"

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
