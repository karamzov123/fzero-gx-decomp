#include "types.h"
#include "dolphin/hw_regs.h"


/* --- dol/fn_80005EDC.c --- */
struct Sig_fn_800737E4_fn_800737E4_Arg0 {
    f32 unk_0;
    u8 pad_4[0x4];
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x4];
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    u8 pad_20[0x8];
    f32 unk_28;
    f32 unk_2C;
    u8 pad_30[0x10]; /* callee writes past 0x2C: object is 0x40 bytes */
};

extern u32 lbl_801A6E98;
extern u32 lbl_801A6D00[2];
extern const f32 lbl_801A6E9C;
extern const f32 lbl_801A6EA0;
extern const f32 lbl_801A6EA4;
extern const f32 lbl_801A6EA8;
extern u32 GXLoadPosMtxImm(u32, u32);
extern u32 fn_800371F8(u32, void *);
extern void fn_80071ED4(u32, f32, f32);
extern u32 fn_80072CC4(u32, u32, u32, u32, u32);
extern u32 fn_80072D64(u32, u32, u32, u32, u32, u32);
extern u32 fn_80072EDC(u32, u32);
extern u32 fn_800734A8(u32, u32, u32, u32);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
extern void fn_8007245C(u32);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_80073678(u32);
extern void fn_800737E4(struct Sig_fn_800737E4_fn_800737E4_Arg0 *, s32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, u32, u32, u32, u32, u32);
extern void fn_80074918(u8, s32, u8);
extern void lbl_8006D758(void);

void fn_80005EDC(void) {
    u32 color = lbl_801A6E98;
    u32 buf0;
    u32 buf1;
    u32 buf2;
    struct Sig_fn_800737E4_fn_800737E4_Arg0 mtx;

    fn_8007245C(8704);
    fn_80074788(0);
    fn_80074660(1);
    fn_80073678(1);
    fn_80073C6C(0);
    fn_80072EDC(0, 0);
    fn_800745A4(0, 1, 4, 60, 0, 125);
    fn_800734A8(0, 0, 0, 255);
    fn_80072AB0(0, 0, 0);
    fn_80072C24(0, 15, 2, 8, 4);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 1, 4, 2);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_800747D0(4, 0, 0, 0, 0, 2, 2);
    buf0 = color;
    fn_800371F8(1, &buf0);
    fn_80074918(1, 7, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_80071ED4(0, lbl_801A6E9C, lbl_801A6EA0);
    fn_80072864(2);
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00[0], 0);
    C_MTXOrtho(&mtx, lbl_801A6E9C, lbl_801A6EA4, lbl_801A6E9C, lbl_801A6EA8, lbl_801A6E9C, lbl_801A6EA0);
    fn_800737E4(&mtx, 1);
    ((u8 *)&color)[0] = 255;
    ((u8 *)&color)[1] = 255;
    ((u8 *)&color)[2] = 255;
    ((u8 *)&color)[3] = 255;
    buf1 = color;
    fn_800371F8(1, &buf1);
    ((u8 *)&color)[0] = 0;
    ((u8 *)&color)[1] = 0;
    ((u8 *)&color)[2] = 0;
    ((u8 *)&color)[3] = 0;
    buf2 = color;
    fn_800371F8(2, &buf2);
}

/* --- dol/fn_800060D8.c --- */
typedef struct {
    void *image;
    u16 code;
    u16 width;
} FontGlyph;

typedef struct {
    u32 dummy[8];
} GXTexObj;

extern s16 lbl_801A66EC;
extern FontGlyph lbl_8015B940[];

extern s32 fn_80006334(u8 *);
extern void GXInitTexObj(GXTexObj *, void *, u16, u16, s32, s32, s32, u8);
extern void GXInvalidateTexAll(void);
extern void fn_80073778(GXTexObj *, s32);
extern void fn_8003462C(s32, s32, u16);

#define FIFO_F32(v) (*(volatile f32 *)GX_FIFO_BASE = (v))  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */

static inline FontGlyph *find_glyph(s32 code) {
    FontGlyph *glyph = lbl_8015B940;
    s32 i;

    for (i = 0; i < lbl_801A66EC; i++, glyph++) {
        if (glyph->code == code) {
            return glyph;
        }
    }
    return NULL;
}

void fn_800060D8(f32 x, f32 y, f32 z, u8 *str) {
    GXTexObj obj;
    FontGlyph *glyph;
    u32 code;
    f32 nz;
    f32 y2;
    f32 x2;

    nz = -z;
    while (*str != 0) {
        if (fn_80006334(str)) {
            code = *(u16 *)str;
            str += 2;
        } else {
            code = *str;
            str += 1;
        }
        if (code == 0x20) {
            x += 8.0;
            continue;
        }
        glyph = find_glyph(code);
        if (glyph == NULL) {
            continue;
        }
        GXInitTexObj(&obj, glyph->image, 24, 24, 0, 0, 0, 0);
        GXInvalidateTexAll();
        fn_80073778(&obj, 0);
        y2 = 24.0 + y;
        x2 = x + glyph->width;
        fn_8003462C(0x80, 7, 4);
        FIFO_F32(x);
        FIFO_F32(y);
        FIFO_F32(nz);
        FIFO_F32(0.0f);
        FIFO_F32(0.0f);
        FIFO_F32(x2);
        FIFO_F32(y);
        FIFO_F32(nz);
        FIFO_F32(glyph->width / 24.0);
        FIFO_F32(0.0f);
        FIFO_F32(x2);
        FIFO_F32(y2);
        FIFO_F32(nz);
        FIFO_F32(glyph->width / 24.0);
        FIFO_F32(1.0f);
        FIFO_F32(x);
        FIFO_F32(y2);
        FIFO_F32(nz);
        FIFO_F32(0.0f);
        FIFO_F32(1.0f);
        x += glyph->width;
    }
}
