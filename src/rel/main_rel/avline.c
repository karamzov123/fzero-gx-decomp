#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/avline.h"

extern u32 lbl_801A6410;
extern u32 fn_1_45D0(u32, u32, unsigned char *, u32);
extern void fn_1_46B4(u32, u32, void *, u32);
extern u8 lbl_1_data_1D62C[148];
extern void fn_1_9F870(void);
extern void fn_1_58158(void);

/* fzgx:begin fn_1_58114 */
void fn_1_58114(void) {
    lbl_1_bss_6C840 = fn_1_45D0(lbl_801A6410, 0x6590, lbl_1_data_1C68C, 0x39f);
}
/* fzgx:end fn_1_58114 */

/* fzgx:begin fn_1_58158 */
// fn_1_58158: loads global values and calls fn_1_46B4.
void fn_1_58158(void) {
    u32 v1 = lbl_801A6410;
    u32 v2 = lbl_1_bss_6C840;
    fn_1_46B4(v1, v2, &lbl_1_data_1C68C, 0x3a6);
}
/* fzgx:end fn_1_58158 */

/* fzgx:begin fn_1_5819C */
void fn_1_5819C(void) {
    lbl_1_bss_6C844 = 0;
}
/* fzgx:end fn_1_5819C */

/* fzgx:begin fn_1_581AC */
extern u16 lbl_1_bss_6C844;
extern u32 lbl_1_bss_6C840;

typedef struct AvLineEntry {
    u16 unk_00;
    u16 unk_02;
    u8 unk_04[0x100];
} AvLineEntry;

extern void fn_80008BA8(void*, void*, u32);

#pragma opt_propagation off
s32 fn_1_581AC(u16 value, u16 type, void* data) {
    AvLineEntry *entry;
    u8 *p;

    if (lbl_1_bss_6C844 == 0x64) {
        return 0;
    }

    ((AvLineEntry*)lbl_1_bss_6C840)[lbl_1_bss_6C844].unk_00 = value;
    p = (u8*)lbl_1_bss_6C840 + lbl_1_bss_6C844 * 0x104;
    entry = (AvLineEntry*)p;
    entry->unk_02 = type;
    fn_80008BA8(((AvLineEntry*)lbl_1_bss_6C840)[lbl_1_bss_6C844].unk_04, data, 0x100);
    lbl_1_bss_6C844++;
    return 1;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_581AC */

/* fzgx:begin fn_1_58248 */
typedef struct AvLineState {
    u8 unk_0;
    u8 pad_1[3];
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
    s32 unk_14;
} AvLineState;

typedef struct AvLineVtx {
    f32 x, y, z;
    u8 r, g, b, a;
} AvLineVtx;

typedef struct AvLineEntry2 {
    u16 unk_00;
    u16 unk_02;
    AvLineVtx unk_04[16];
} AvLineEntry2;

typedef union AvWGPipe {
    volatile u8 u8;  /* fzgx-allow: S2 AI pipe register, write-only hardware */
    volatile f32 f32;  /* fzgx-allow: S2 AI pipe register, write-only hardware */
} AvWGPipe;

#define AV_WGPIPE ((AvWGPipe *)0xCC008000)  /* fzgx-allow: A1,A2 AI pipe register block */

extern AvLineState lbl_1_data_1C670;
extern u32 lbl_801A6D00;
extern void GXLoadPosMtxImm(u32, u32);
extern void fn_800720B0(u32);
extern void fn_80072EDC(s32, u32);
extern void lbl_8006DCA4(void);
extern void fn_8003462C(u32, u32, u16);
extern void fn_8007245C(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073678(u32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_80074918(u8, s32, u8);
extern void fn_800746A8(u8, s32);

static inline void AvPos(f32 x, f32 y, f32 z) {
    AV_WGPIPE->f32 = x;
    AV_WGPIPE->f32 = y;
    AV_WGPIPE->f32 = z;
}

static inline void AvCol(s8 r, s8 g, s8 b, s8 a) {
    AV_WGPIPE->u8 = r;
    AV_WGPIPE->u8 = g;
    AV_WGPIPE->u8 = b;
    AV_WGPIPE->u8 = a;
}

#define AvDraw(a, b) AvDraw_(b, a)
static inline void AvDraw_(u16 n, AvLineVtx *v) {
    s32 j;

    if (n >= 2) {
        fn_8003462C(0xb0, 0, n);
        for (j = 0; j < n; j++) {
            AvPos(v->x, v->y, v->z);
            AvCol(v->r, v->g, v->b, v->a);
            v++;
        }
    }
}

void fn_1_58248(void) {
    s32 i;
    AvLineEntry2 *entry;

    lbl_1_data_1C670.unk_4 = 1;
    lbl_1_data_1C670.unk_8 = 1;
    lbl_1_data_1C670.unk_C = 1;
    lbl_1_data_1C670.unk_10 = 0;
    lbl_8006DCA4();
    fn_80074918(1, 3, 1);
    fn_800746A8(lbl_1_data_1C670.unk_0, lbl_1_data_1C670.unk_14);
    fn_8007245C(0xa00);
    fn_800728A8(lbl_1_data_1C670.unk_4, lbl_1_data_1C670.unk_8, lbl_1_data_1C670.unk_C, lbl_1_data_1C670.unk_10);
    fn_800720B0(0);
    fn_800747D0(4, 0, 1, 1, 0, 2, 1);
    fn_800734A8(0, 0xff, 0xff, 4);
    fn_80072EDC(0, 4);
    fn_80073C6C(0);
    fn_80073678(1);
    fn_80074660(0);
    fn_80073898(0);
    fn_80074788(1);
    GXLoadPosMtxImm(lbl_801A6D00, 0);

    for (i = 0; i < lbl_1_bss_6C844; i++) {
        entry = &((AvLineEntry2 *)lbl_1_bss_6C840)[i];
        lbl_1_data_1C670.unk_0 = entry->unk_00;
        AvDraw(entry->unk_04, entry->unk_02);
    }
    lbl_1_bss_6C844 = 0;
}
/* fzgx:end fn_1_58248 */

/* fzgx:begin fn_1_584AC */
// fn_1_584AC: linear congruential generator.
u32 fn_1_584AC(void) {
    u32 state = lbl_1_data_1D628;
    u32 next = state * 0x41c64e6du + 0x3039u;
    lbl_1_data_1D628 = next;
    return (next >> 16) & 0x7FFFu;
}
/* fzgx:end fn_1_584AC */
