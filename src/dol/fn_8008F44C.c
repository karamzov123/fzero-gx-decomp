#include "types.h"
#include "sdk_addresses.h"


/* --- dol/fn_8008F44C.c --- */
/* --- dol/fn_8008F44C.c --- */
/* --- dol/fn_8008F44C.c --- */
// fn_8008F44C: empty in retail (single blr).
void fn_8008F44C(void) {
}

/* --- dol/fn_8008F450.c --- */
// fn_8008F450: empty in retail (single blr).
void fn_8008F450(void) {
}

/* --- dol/fn_8008F454.c --- */
// fn_8008F454: empty in retail (single blr).
void fn_8008F454(void) {
}

/* --- dol/fn_8008F458.c --- */
// fn_8008F458: empty in retail (single blr).
void fn_8008F458(void) {
}

/* --- dol/fn_8008F45C.c --- */
int fn_8008F45C(const void *src, int size);

int OSDisableInterrupts(void);

int OSRestoreInterrupts(int enabled);

// Hardware or OS state can change asynchronously.
volatile u32 __EXIRegs[] : FZGX_ADDR___EXIRegs;

extern u8 lbl_801A6688;

BOOL fn_8008FC3C(void *buffer, s32 bytecounter, u32 write);

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

/* --- dol/fn_8008F6BC.c --- */
extern u32 lbl_801A6E30;
extern void fn_8008FAB4(u32, u32, u32);
extern u32 lbl_801A6E34;
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
    fn_8008FAB4(base, arg0, (arg1 + 3) & ~3);
    lbl_801A6E34 = 0;
    lbl_801A6E3C = 0;
    OSRestoreInterrupts(interrupt_state);
    return 0;
}
