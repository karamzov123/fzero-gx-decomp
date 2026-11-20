#include "types.h"
#include "dolphin/hw_regs.h"


/* --- dol/fn_80039B0C.c --- */
extern u32 fn_80039954(void *, void *);

u32 fn_80039B0C(void) {
    u32 loc_C;
    u32 loc_8;
    /* frame */
    fn_80039954(&loc_C, &loc_8);
    return loc_8;
}

/* --- dol/fn_80039B38.c --- */
typedef struct GXData {
    u16 unk_000;
    u16 bp_sent_not;
    u8 pad_004[0xf4];
    u32 su_scis0;
    u32 su_scis1;
    u8 pad_100[0x30];
    u32 tevc[16];
    u32 teva[16];
    u8 pad_1b0[0x20];
    u32 cmode0;
    u32 cmode1;
    u32 zmode;
} GXData;

typedef union PPCWGPipe {
    u8 u8;
    u16 u16;
    u32 u32;
    f32 f32;
} PPCWGPipe;

extern GXData *const gx;
volatile PPCWGPipe GXWGFifo : GX_FIFO_BASE;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */

#define SET_REG_FIELD(reg, size, shift, val) \
    ((reg) = __rlwimi((reg), (val), (shift), 32 - (shift) - (size), 31 - (shift)))
#define GX_WRITE_RAS_REG(reg) \
    do { \
        GXWGFifo.u8 = 0x61; \
        GXWGFifo.u32 = (reg); \
    } while (0)

void fn_80039B38(void) {
    GX_WRITE_RAS_REG(0x2402c022);
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = 0x1006;
    GXWGFifo.u32 = 0x31000;
    gx->bp_sent_not = 1;
}
