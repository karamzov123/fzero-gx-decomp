#include "types.h"
#include "dolphin/hw_regs.h"

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
    (reg = __rlwimi(reg, val, shift, 32 - (shift) - size, 31 - shift))
#define GX_WRITE_RAS_REG(reg) \
    do { \
        GXWGFifo.u8 = 0x61; \
        GXWGFifo.u32 = (reg); \
    } while (0)

typedef struct GXDataLine {
    u8 pad_000[0x1e8];
    u32 unk_1e8;
} GXDataLine;
#define OLD_SET(reg, size, shift, val) ((reg) = ((u32)(reg) & ~(((1 << (size)) - 1) << (shift))) | ((u32)(val) << (shift)))
void fn_80034B7C(u16 value) {
    GXDataLine *state = (GXDataLine *)gx;
    u32 *reg;
    state->unk_1e8 = 0;
    reg = &state->unk_1e8;
    OLD_SET(*reg, 10, 0, (u16)(value << 1) >> 5);
    OLD_SET(*reg, 8, 24, 0x4d);
}
