#include "types.h"
#include "dolphin/gx.h"

typedef struct _GXColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} GXColor;

typedef struct _GXData {
    u16 vNumNot;
    u16 bpSentNot;
} GXData;

typedef struct FogState {
    u8 pad_0[0x20];
    GXColor color;
    u8 pad_24[0x4];
    u32 colorReg;
} FogState;

extern GXData *const gx;
extern FogState lbl_8019E250;

#define SET_REG_FIELD(reg, size, shift, val)     ((reg) = ((u32)(val) << (shift)) | ((reg) & ~(((1 << (size)) - 1) << (shift))))

#pragma opt_lifetimes off
#pragma opt_propagation off
static inline void WriteBPReg(u32 value) {
    u8 command = 0x61; /* GX_LOAD_BP_REG */
    gx->bpSentNot = 0;
    GXWGFifo.u8 = command;
    GXWGFifo.u32 = value;
}

void fn_80072014(GXColor color) {
    u32 reg;

    if (lbl_8019E250.color.r == color.r && lbl_8019E250.color.g == color.g && lbl_8019E250.color.b == color.b) {
        return;
    }
    lbl_8019E250.color.r = color.r;
    lbl_8019E250.color.g = color.g;
    lbl_8019E250.color.b = color.b;
    reg = color.b;
    SET_REG_FIELD(reg, 8, 8, color.g);
    SET_REG_FIELD(reg, 8, 16, color.r);
    SET_REG_FIELD(reg, 8, 24, 0xF2);
    lbl_8019E250.colorReg = reg;
    WriteBPReg(reg);
}
#pragma opt_propagation reset
#pragma opt_lifetimes reset
