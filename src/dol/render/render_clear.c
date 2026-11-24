#include "types.h"
#include "dolphin/gx.h"
#include "dolphin/gx/GXPriv.h"

extern void fn_800744F8(GXColor, u32);
extern void fn_80008204(GXColor *color);

extern GXColor lbl_801A6408;
s32 lbl_801A6728;

static inline void RenderSetClearColor(GXColor color) {
    lbl_801A6408.r = color.r;
    lbl_801A6408.g = color.g;
    lbl_801A6408.b = color.b;
    lbl_801A6408.a = color.a;
    fn_800744F8(lbl_801A6408, 0x00FFFFFF);
}

void fn_80007A44(void) {
    GXColor black = {0, 0, 0, 0xFF};

    RenderSetClearColor(black);
    fn_80008204(&lbl_801A6408);
    lbl_801A6728 = 0;
}

void fn_80007AB4(GXColor color) {
    if (lbl_801A6408.r != color.r || lbl_801A6408.g != color.g || lbl_801A6408.b != color.b ||
        lbl_801A6408.a != color.a) {
        RenderSetClearColor(color);
        fn_80008204(&lbl_801A6408);
    }
    lbl_801A6728 = 1;
}

/* The same steps as fn_80007AB4 for black. Calling it inlines the same code but puts the two color copies in the
 * opposite stack slots. */
void fn_80007B68(void) {
    GXColor compare;
    GXColor next;
    GXColor black = {0, 0, 0, 0xFF};

    compare = black;
    next = black;
    if (lbl_801A6408.r != compare.r || lbl_801A6408.g != compare.g || lbl_801A6408.b != compare.b ||
        lbl_801A6408.a != compare.a) {
        RenderSetClearColor(next);
        fn_80008204(&lbl_801A6408);
    }
    lbl_801A6728 = 1;
}

void fn_80007C2C(void) {
    fn_800744F8(lbl_801A6408, 0x00FFFFFF);
}

void fn_80007C60(s32 force) {
    if (force || !lbl_801A6728) {
        GXColor black = {0, 0, 0, 0xFF};

        RenderSetClearColor(black);
    }
    lbl_801A6728 = 0;
}

