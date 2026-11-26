#include "types.h"
#include "dolphin/hw_regs.h"

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} GXColor;

typedef f32 Mtx44[4][4];

typedef struct Vec {
    f32 x;
    f32 y;
    f32 z;
} Vec;

typedef union {
    u8 u8;
    f32 f32;
} PPCWGPipe;

/* 2D debug drawing state: drawing is on, and the projection saved by fn_1_A9868 */
typedef struct DebugDraw {
    s32 active;
    f32 proj_0;
    f32 proj_1;
    f32 proj_2;
    f32 proj_3;
    u8 pad_14[0x1C];
} DebugDraw;

extern u32 *lbl_801A6D00;
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void fn_1_A714C(f32 *a, f32 *b, f32 *c, f32 *d);
extern void fn_1_A7024(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
extern void fn_800737E4(Mtx44 m, s32 type);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void C_MTXOrtho(Mtx44 m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 f);
extern void GXLoadPosMtxImm(u32 *m, u32 id);
extern void fn_800720B0(s32 arg0);
extern void fn_80072EDC(s32 arg0, s32 arg1);
extern void GXSetCurrentMtx(u32 value);
extern void fn_8006F1F0(Vec *pos, Vec *up, Vec *at);
extern void fn_8007245C(u32 value);
extern void fn_8007264C(u32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80073678(u32 arg0);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_80074660(u32 arg0);
extern void fn_800746A8(u8 value, s32 arg);
extern void fn_80074718(u8 value, s32 arg);
extern void fn_80074788(u32 arg0);
extern void fn_800747D0(u32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6);
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);

void fn_1_A9FFC(s16 x, s16 y, s16 w, s16 h, GXColor color);

DebugDraw lbl_1_bss_71690;

volatile PPCWGPipe GXWGFifo : GX_FIFO_BASE; /* volatile: hardware port */

/* The SDK's const-parameter vertex writers; GC/2.5 keeps the by-value color in registers across them. */
static inline void GXPosition3f32(const f32 x, const f32 y, const f32 z) {
    GXWGFifo.f32 = x;
    GXWGFifo.f32 = y;
    GXWGFifo.f32 = z;
}

static inline void GXColor4u8(const u8 r, const u8 g, const u8 b, const u8 a) {
    GXWGFifo.u8 = r;
    GXWGFifo.u8 = g;
    GXWGFifo.u8 = b;
    GXWGFifo.u8 = a;
}

/* fzgx:begin fn_1_A9868 */
void fn_1_A9868(void) {
    Mtx44 proj;
    DebugDraw *dd = (DebugDraw *)&lbl_1_bss_71690;

    fn_1_A714C(&dd->proj_0, &dd->proj_1, &dd->proj_2, &dd->proj_3);
    fn_8007245C(2560);
    fn_800720B0(0);
    fn_800747D0(4, 0, 1, 1, 0, 2, 1);
    fn_800734A8(0, 255, 255, 4);
    fn_80072EDC(0, 4);
    fn_80073C6C(0);
    fn_8007264C(0, 9, 1, 4, 8);
    fn_80074718(6, 0);
    fn_800746A8(6, 0);
    fn_80073678(1);
    fn_80074660(0);
    fn_80073898(0);
    fn_80074788(1);
    lbl_8006DAEC();
    {
        Vec pos = {0.0f, 0.0f, 100.0f};
        Vec up = {0.0f, 1.0f, 0.0f};
        Vec at = {0.0f, 0.0f, -100.0f};

        fn_8006F1F0(&pos, &up, &at);
    }
    GXSetCurrentMtx(0);
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    lbl_8006DB30();
    C_MTXOrtho(proj, 0.0f, 480.0f, 0.0f, 640.0f, 0.0f, 90000.0f);
    fn_800737E4(proj, 1);
    fn_80074918(1, 7, 0);
    dd->active = 1;
}
/* fzgx:end fn_1_A9868 */

/* fzgx:begin fn_1_A9A28 */
/* Draws one line (GXBegin 0xA8, two vertices) from (x0, y0) to (x1, y1), each coordinate offset by 0.5. */
/* Draws one line (GXBegin 0xA8, two vertices) from (x0, y0) to (x1, y1), each coordinate offset by 0.5,
 * while lbl_1_bss_71690.unk_0 is set. */
void fn_1_A9A28(s16 x0, s16 y0, s16 x1, s16 y1, GXColor color) {
    if (lbl_1_bss_71690.active != 0) {
        fn_8003462C(0xA8, 0, 2);
        GXPosition3f32(0.5f + x0, 0.5f + y0, 0.0f);
        GXColor4u8(color.r, color.g, color.b, color.a);
        GXPosition3f32(0.5f + x1, 0.5f + y1, 0.0f);
        GXColor4u8(color.r, color.g, color.b, color.a);
    }
}
/* fzgx:end fn_1_A9A28 */

/* fzgx:begin fn_1_A9B70 */
/* Outlines the w by h rectangle at (x, y) with four lines, filling it first through fn_1_A9FFC when either side
 * is 2 or less. */
/* Outlines the w by h rectangle at (x, y) with four lines, filling it first through fn_1_A9FFC when either side
 * is 2 or less, while lbl_1_bss_71690.unk_0 is set. */
/* fn_1_A9A28's body (one line, GXBegin 0xA8): retail inlines the calls here four times */
void fn_1_A9B70(s16 x, s16 y, s16 w, s16 h, GXColor color) {
    if (lbl_1_bss_71690.active == 0 || w == 0 || h == 0) {
        return;
    }
    if (w <= 2 || h <= 2) {
        fn_1_A9FFC(x, y, w, h, color);
    }
    fn_1_A9A28(x, y, x + w - 1, y, color);
    fn_1_A9A28(x + w - 1, y, x + w - 1, y + h - 1, color);
    fn_1_A9A28(x, y + 1, x, y + h, color);
    fn_1_A9A28(x + 1, y + h - 1, x + w, y + h - 1, color);
}
/* fzgx:end fn_1_A9B70 */

/* fzgx:begin fn_1_A9FFC */
/* Fills the w by h rectangle at (x, y) with one color (GXBegin 0x80, four vertices), each coordinate offset
 * by 0.5. */
/* Fills the w by h rectangle at (x, y) with one color (GXBegin 0x80, four vertices), each coordinate offset
 * by 0.5, while lbl_1_bss_71690.unk_0 is set. */
void fn_1_A9FFC(s16 x, s16 y, s16 w, s16 h, GXColor color) {
    if (lbl_1_bss_71690.active != 0) {
        fn_8003462C(0x80, 0, 4);
        GXPosition3f32(0.5f + x, 0.5f + y, 0.0f);
        GXColor4u8(color.r, color.g, color.b, color.a);
        GXPosition3f32(0.5f + (x + w), 0.5f + y, 0.0f);
        GXColor4u8(color.r, color.g, color.b, color.a);
        GXPosition3f32(0.5f + (x + w), 0.5f + (y + h), 0.0f);
        GXColor4u8(color.r, color.g, color.b, color.a);
        GXPosition3f32(0.5f + x, 0.5f + (y + h), 0.0f);
        GXColor4u8(color.r, color.g, color.b, color.a);
    }
}
/* fzgx:end fn_1_A9FFC */

/* fzgx:begin fn_1_AA188 */
/* Fills the w by h rectangle at (x, y) with one color per corner (GXBegin 0x80, four vertices, clockwise from
 * (x, y)), each coordinate offset by 0.5. */
/* Fills the w by h rectangle at (x, y) with one color per corner (GXBegin 0x80, four vertices, clockwise from
 * (x, y)), each coordinate offset by 0.5, while lbl_1_bss_71690.unk_0 is set. */
void fn_1_AA188(s16 x, s16 y, s16 w, s16 h, GXColor c0, GXColor c1, GXColor c2, GXColor c3) {
    if (lbl_1_bss_71690.active != 0) {
        fn_8003462C(0x80, 0, 4);
        GXPosition3f32(0.5f + x, 0.5f + y, 0.0f);
        GXColor4u8(c0.r, c0.g, c0.b, c0.a);
        GXPosition3f32(0.5f + (x + w), 0.5f + y, 0.0f);
        GXColor4u8(c1.r, c1.g, c1.b, c1.a);
        GXPosition3f32(0.5f + (x + w), 0.5f + (y + h), 0.0f);
        GXColor4u8(c2.r, c2.g, c2.b, c2.a);
        GXPosition3f32(0.5f + x, 0.5f + (y + h), 0.0f);
        GXColor4u8(c3.r, c3.g, c3.b, c3.a);
    }
}
/* fzgx:end fn_1_AA188 */

/* fzgx:begin fn_1_AA350 */
/* Draws n points (GXBegin 0x98) from the x and y arrays, one RGBA color per point. */
void fn_1_AA350(s16 *x, s16 *y, u8 *color, u32 n) {
    u32 i;
    if (lbl_1_bss_71690.active != 0) {
        fn_8003462C(0x98, 0, (u16)n);
        for (i = 0; i < n; i++) {
            GXPosition3f32(*x++, *y++, 0.0f);
            GXColor4u8(color[0], color[1], color[2], color[3]);
            color += 4;
        }
    }
}
/* fzgx:end fn_1_AA350 */

/* fzgx:begin fn_1_AA538 */
// Initialize the shared rendering state and submit the associated configuration.
void fn_1_AA538(void) {
    DebugDraw *dd = (DebugDraw *)&lbl_1_bss_71690;

    fn_1_A7024(dd->proj_0, dd->proj_1, dd->proj_2, dd->proj_3);
    fn_80074918(1, 3, 1);
    dd->active = 1;
}
/* fzgx:end fn_1_AA538 */
