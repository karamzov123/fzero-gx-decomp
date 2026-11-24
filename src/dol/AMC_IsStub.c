#include "types.h"
#include "sdk_addresses.h"
#include <dolphin/types.h>


/* --- dol/fn_8008F8F0.c --- */
extern u32 lbl_801A6E28;
extern u8 lbl_801A6E3C;

void fn_8008F8F0(void);

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

BOOL fn_8008F92C(u32 *value);

/* --- dol/fn_8008F9D8.c --- */
BOOL fn_8008F9D8(u32 count, const void *buffer, s32 size);

// Hardware or OS state can change asynchronously.

BOOL fn_8008FC3C(void *buffer, s32 bytecounter, u32 write);




BOOL fn_8008F9D8(u32 count, const void *buffer, s32 size);

/* --- dol/fn_8008FAB4.c --- */
BOOL fn_8008FAB4(u32 count, u32 *buffer, s32 size);

// Hardware or OS state can change asynchronously.

BOOL fn_8008FC3C(void *buffer, s32 bytecounter, u32 write);




BOOL fn_8008FAB4(u32 count, u32 *buffer, s32 size);

/* --- dol/fn_8008FB90.c --- */
BOOL fn_8008FB90(u32 *value);

// Hardware or OS state can change asynchronously.

BOOL fn_8008FC3C(void *buffer, s32 bytecounter, u32 write);




BOOL fn_8008FB90(u32 *value);

/* --- dol/fn_8008FC3C.c --- */
/* --- dol/fn_8008FC3C.c --- */
vu32 __EXIRegs[16] : FZGX_ADDR___EXIRegs;

BOOL fn_8008FC3C(void *buf, s32 len, u32 type);

/* --- dol/AMC_IsStub.c --- */
/* --- dol/AMC_IsStub.c --- */
// AMC_IsStub: returns a constant.
int AMC_IsStub(void) {
    return 0;
}
