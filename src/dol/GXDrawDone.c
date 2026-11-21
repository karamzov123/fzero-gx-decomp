#include "types.h"
#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
#include <dolphin/os/OSInterrupt.h>
#include <types.h>
#include <dolphin/types.h>

extern u32 OSSleepThread(u32);
extern u32 lbl_801A6C1C;
extern u8 lbl_801A6C18;
extern void GXFlush(void);

void GXDrawDone(u32 lab_unused0) {
    u32 t0, t3;
    t0 = OSDisableInterrupts();
    *(u8 *)((u8 *)0xCC010000 + -32768) = 97;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(u32 *)((u8 *)0xCC010000 + -32768) = (0x45000000 + 2);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    GXFlush();
    lbl_801A6C18 = 0;
    OSRestoreInterrupts(t0);
    t3 = OSDisableInterrupts();
    while (lbl_801A6C18 == 0) {
    OSSleepThread((u32)&lbl_801A6C1C);
    }
    OSRestoreInterrupts(t3);
}

// Hardware register block pointer; accesses must not be cached.
extern volatile u16 *__peReg;

void GXPokeAlphaMode(u32 arg0, u32 arg1) {
    __peReg[3] = (u16)((arg0 << 8) | (arg1 & 0xFF));
}

void GXPokeAlphaRead(u32 arg0) {
    u32 v0;
    v0 = (arg0 & 0xFFFFFFFB);
    __peReg[4] = (v0 | 4);
}

// Hardware register pointer; accesses must not be cached.

void GXPokeAlphaUpdate(u8 value) {
    __peReg[1] = (u16)((__peReg[1] & ~0x10) | ((u32)value << 4));
}

typedef enum _GXBlendMode {
    GX_BM_NONE,
    GX_BM_BLEND,
    GX_BM_LOGIC,
    GX_BM_SUBTRACT,
    GX_MAX_BLENDMODE,
} GXBlendMode;

typedef enum _GXBlendFactor {
    GX_BL_ZERO,
    GX_BL_ONE,
    GX_BL_SRC_COLOR,
    GX_BL_DST_COLOR = 2,
    GX_BL_INV_SRC_COLOR,
    GX_BL_INV_DST_COLOR = 3,
    GX_BL_SRC_ALPHA,
    GX_BL_INV_SRC_ALPHA,
    GX_BL_DST_ALPHA,
    GX_BL_INV_DST_ALPHA,
} GXBlendFactor;

typedef enum _GXLogicOp {
    GX_LO_CLEAR,
    GX_LO_AND,
    GX_LO_REV_AND,
    GX_LO_COPY,
    GX_LO_INV_AND,
    GX_LO_NOOP,
    GX_LO_XOR,
    GX_LO_OR,
    GX_LO_NOR,
    GX_LO_EQUIV,
    GX_LO_INV,
    GX_LO_REV_OR,
    GX_LO_INV_COPY,
    GX_LO_INV_OR,
    GX_LO_NAND,
    GX_LO_SET,
} GXLogicOp;

void GXPokeBlendMode(GXBlendMode mode, GXBlendFactor srcFactor, GXBlendFactor destFactor,
                 GXLogicOp op) {
    u32 reg;
    reg = (*(vu16 *)((vu16 *)(__peReg) + (1)));
    (reg) = (reg & ~(((1 << ((31 - 31 + 1))) - 1) << (31 - (31) - ((31 - 31 + 1)) + 1))) |
            ((int)((mode == GX_BM_BLEND) || (mode == GX_BM_SUBTRACT))
             << (31 - (31) - ((31 - 31 + 1)) + 1));
    (reg) = (reg & ~(((1 << ((20 - 20 + 1))) - 1) << (31 - (20) - ((20 - 20 + 1)) + 1))) |
            ((int)((mode == GX_BM_SUBTRACT)) << (31 - (20) - ((20 - 20 + 1)) + 1));
    (reg) = (reg & ~(((1 << ((30 - 30 + 1))) - 1) << (31 - (30) - ((30 - 30 + 1)) + 1))) |
            ((int)((mode == GX_BM_LOGIC)) << (31 - (30) - ((30 - 30 + 1)) + 1));
    (reg) = (reg & ~(((1 << ((19 - 16 + 1))) - 1) << (31 - (16) - ((19 - 16 + 1)) + 1))) |
            ((int)(op) << (31 - (16) - ((19 - 16 + 1)) + 1));
    (reg) = (reg & ~(((1 << ((23 - 21 + 1))) - 1) << (31 - (21) - ((23 - 21 + 1)) + 1))) |
            ((int)(srcFactor) << (31 - (21) - ((23 - 21 + 1)) + 1));
    (reg) = (reg & ~(((1 << ((26 - 24 + 1))) - 1) << (31 - (24) - ((26 - 24 + 1)) + 1))) |
            ((int)(destFactor) << (31 - (24) - ((26 - 24 + 1)) + 1));
    (reg) = (reg & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
            ((int)(0x41) << (31 - (0) - ((7 - 0 + 1)) + 1));
    (*(vu16 *)((vu16 *)(__peReg) + (1)) = reg);
}

// The PE register is memory-mapped hardware and must not be cached.

void GXPokeColorUpdate(u8 value) {
    u16 current = __peReg[1];
    __peReg[1] = (u16)((current & ~(1 << 3)) | ((value & 0xFF) << 3));
}

void GXPokeDstAlpha(GXBool enable, u8 alpha) {
    u32 val = 0;
    (val) = (val & ~(((1 << (8)) - 1) << (31 - (0x18) - (8) + 1))) |
            ((int)(alpha) << (31 - (0x18) - (8) + 1));
    (val) = (val & ~(((1 << (1)) - 1) << (31 - (0x17) - (1) + 1))) |
            ((int)(enable) << (31 - (0x17) - (1) + 1));
    __peReg[2] = val;
}
