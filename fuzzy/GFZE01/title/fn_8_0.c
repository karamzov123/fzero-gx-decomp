/* Non-matching: best partial attempt (58.66% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 362.0f;
    s = 1.0f;
    s = 0.0f;
    s = 0.4000000059604645f;
    s = 3.5f;
    s = 0.6700000166893005f;
    s = 120.0f;
}
#pragma section code_type ".text"
typedef enum Sig_GXInitTexObj__GXTexFmt {
    Sig_GXInitTexObj_GX_TF_I4 = 0x0,
    Sig_GXInitTexObj_GX_TF_I8 = 0x1,
    Sig_GXInitTexObj_GX_TF_IA4 = 0x2,
    Sig_GXInitTexObj_GX_TF_IA8 = 0x3,
    Sig_GXInitTexObj_GX_TF_RGB565 = 0x4,
    Sig_GXInitTexObj_GX_TF_RGB5A3 = 0x5,
    Sig_GXInitTexObj_GX_TF_RGBA8 = 0x6,
    Sig_GXInitTexObj_GX_TF_CMPR = 0xE,
    Sig_GXInitTexObj_GX_CTF_R4 = 0x0 | 0x20,
    Sig_GXInitTexObj_GX_CTF_RA4 = 0x2 | 0x20,
    Sig_GXInitTexObj_GX_CTF_RA8 = 0x3 | 0x20,
    Sig_GXInitTexObj_GX_CTF_YUVA8 = 0x6 | 0x20,
    Sig_GXInitTexObj_GX_CTF_A8 = 0x7 | 0x20,
    Sig_GXInitTexObj_GX_CTF_R8 = 0x8 | 0x20,
    Sig_GXInitTexObj_GX_CTF_G8 = 0x9 | 0x20,
    Sig_GXInitTexObj_GX_CTF_B8 = 0xA | 0x20,
    Sig_GXInitTexObj_GX_CTF_RG8 = 0xB | 0x20,
    Sig_GXInitTexObj_GX_CTF_GB8 = 0xC | 0x20,
    Sig_GXInitTexObj_GX_TF_Z8 = 0x1 | 0x10,
    Sig_GXInitTexObj_GX_TF_Z16 = 0x3 | 0x10,
    Sig_GXInitTexObj_GX_TF_Z24X8 = 0x6 | 0x10,
    Sig_GXInitTexObj_GX_CTF_Z4 = 0x0 | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z8M = 0x9 | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z8L = 0xA | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z16L = 0xC | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_TF_A8 = Sig_GXInitTexObj_GX_CTF_A8,
} Sig_GXInitTexObj_GXTexFmt;
typedef struct Sig_GXInitTexObj__GXTexObj {
    u32 dummy[8];
} Sig_GXInitTexObj_GXTexObj;
typedef enum Sig_GXInitTexObj__GXTexWrapMode {
    Sig_GXInitTexObj_GX_CLAMP,
    Sig_GXInitTexObj_GX_REPEAT,
    Sig_GXInitTexObj_GX_MIRROR,
    Sig_GXInitTexObj_GX_MAX_TEXWRAPMODE,
} Sig_GXInitTexObj_GXTexWrapMode;

struct fn_8_0_lbl_8_rodata_0 {
    u8 pad_0[0x8];
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
};
struct fn_8_0_lbl_801A6D00 {
    u32 unk_0;
};

extern struct fn_8_0_lbl_801A6D00 lbl_801A6D00;
extern struct fn_8_0_lbl_8_rodata_0 lbl_8_rodata_0;
extern u32 GXLoadTexMtxImm(u32, u32, u32);
extern u32 OSGetTick(void);
extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006DAEC(void);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(Sig_GXInitTexObj_GXTexObj *, void *, u16, u16, Sig_GXInitTexObj_GXTexFmt, Sig_GXInitTexObj_GXTexWrapMode, Sig_GXInitTexObj_GXTexWrapMode, u8);
extern void fn_800729B0(s32, s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073678(u32);
extern void fn_80073778(void *, s32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_80074660(u32);
extern void lbl_8006DB30(void);
extern void lbl_8006E15C(f32, f32, f32);
extern u8 lbl_8_bss_C;
extern u8 lbl_8_bss_20[];

/* Byte offset of texel (x, y) in a 16x16 I8 texture (8x4 tiles); 0 outside the image. */
static inline s32 FireOfs(u32 x, u32 y, u32 buf) {
    u32 t = ((x >> 3) + (y >> 2) * 2) << 5;
    x = x;
    y = y;
    buf = buf;
    return t > 255 ? 0 : t + ((y & 3) << 3) + (x & 7) + (buf << 8);
}

#pragma opt_loop_invariants off
#pragma opt_strength_reduction on
void fn_8_0(void) {
    Sig_GXInitTexObj_GXTexObj obj;
    u32 next;
    u32 i;
    u32 y;
    u32 t;
    u32 t2;
    u32 x;
    u32 v;
    u32 src;
    u32 dst;

    fn_80074660(2);
    fn_80073678(3);
    fn_80073898(0);
    fn_800729B0(0, 0, 1, 2, 3);
    fn_800729B0(1, 0, 0, 0, 2);
    fn_80073C6C(1);
    fn_800745A4(0, 1, 4, 60, 0, 125);
    fn_80072AB0(1, 0, 1);
    fn_800734A8(1, 0, 0, 4);
    fn_80072C24(1, 8, 9, 8, 15);
    fn_80072D64(1, 8, 0, 0, 1, 3);
    fn_80072CC4(1, 7, 7, 7, 0);
    fn_80072E20(1, 0, 0, 0, 1, 0);

    next = (lbl_8_bss_C ^ 1) << 8;
    for (x = 0; x < 16; x++) {
        i = FireOfs(x, 14, lbl_8_bss_C);
        if ((x & 7) == (OSGetTick() & 7)) {
            v = 255;
        } else if (((i)[lbl_8_bss_20]) > 40) {
            v = ((i)[lbl_8_bss_20]) - 40;
        } else {
            v = 0;
        }
        lbl_8_bss_20[i] = v;
        lbl_8_bss_20[FireOfs(x, 15, lbl_8_bss_C)] = 0;
    }

    src = lbl_8_bss_C;
    dst = src ^ 1;
    for (y = 1; y < 15; y++) {
        for (x = 0; x < 16; x++) {
            v = (((FireOfs(x, y + 1, src))[lbl_8_bss_20]) + ((FireOfs(x, y - 1, src))[lbl_8_bss_20]) +
                 (((FireOfs(x, y, src))[lbl_8_bss_20]) + ((FireOfs(x + 1, y, src))[lbl_8_bss_20]) +
                  ((FireOfs(x - 1, y, src))[lbl_8_bss_20])) * 2) * 9 / 64;
            if (v > 255) {
                v = 255;
            }
            lbl_8_bss_20[FireOfs(x, y - 1, dst)] = v;
        }
    }

    DCFlushRange(lbl_8_bss_20 + next, 256);
    GXInitTexObj(&obj, lbl_8_bss_20 + next, 16, 16, Sig_GXInitTexObj_GX_TF_I8, Sig_GXInitTexObj_GX_MIRROR,
                 Sig_GXInitTexObj_GX_MIRROR, 0);
    fn_80073778(&obj, 1);
    lbl_8_bss_C ^= 1;
    lbl_8006DAEC();
    lbl_8006D7F4(0.0f, 0.4f, 0.0f);
    lbl_8006E15C(3.5f, 0.67f, 1.0f);
    GXLoadTexMtxImm(lbl_801A6D00.unk_0, 30, 1);
    GXLoadTexMtxImm(lbl_801A6D00.unk_0, 64, 0);
    lbl_8006DB30();
    fn_80072AB0(2, 0, 0);
    fn_800745A4(1, 1, 4, 30, 0, 125);
    fn_80073C6C(2);
    fn_800734A8(2, 1, 1, 4);
    fn_80072C24(2, 15, 8, 6, 0);
    fn_80072D64(2, 1, 0, 0, 1, 0);
    fn_80072CC4(2, 7, 7, 7, 0);
    fn_80072E20(2, 0, 0, 0, 1, 0);
}
#pragma opt_strength_reduction reset

#pragma opt_loop_invariants reset

