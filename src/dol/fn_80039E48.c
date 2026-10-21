

typedef signed long s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef float f32;
typedef double f64;

struct fn_80039E48_Arg0 {
f32 quant[4][64];
u8 *unk_400;
u8 pad_404[0x15];
u8 unk_419;
};


static const u32 fzgx_pool_rodata_lbl_8008FF50[20] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x10810, 0x902030A, 0x11182019, 0x120B0405, 0xC131A21, 0x28302922, 0x1B140D06, 0x70E151C,
    0x232A3138, 0x39322B24, 0x1D160F17, 0x1E252C33, 0x3A3B342D, 0x261F272E, 0x353C3D36, 0x2F373E3F,
    0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F
};
static const u32 fzgx_pool_rodata_lbl_8008FF50_50[16] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3FF00000, 0x0, 0x3FF63150, 0xC0000000, 0x3FF4E7AE, 0xA0000000, 0x3FF2D062, 0xE0000000,  /* fzgx-allow: A1 retail data bytes */
    0x3FF00000, 0x0, 0x3FE92469, 0xC0000000, 0x3FE1517A, 0x80000000, 0x3FD1A855, 0xE0000000  /* fzgx-allow: A1 retail data bytes */
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_8008FF50(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_rodata_lbl_8008FF50;
    s = *(u8 *)fzgx_pool_rodata_lbl_8008FF50_50;
}
#pragma section code_type ".text"

s32 fn_80039E48(struct fn_80039E48_Arg0 *arg0) {
u16 v2;
u8 v4;
u32 v5;
u16 v20;
u16 v19;
u16 v22;
union { f64 alignment; f32 values[64]; } quantBuffer;
f64 *scale;
v2 = (arg0->unk_400[0] << 8) | arg0->unk_400[1];
arg0->unk_400 += 2;
scale = (f64 *)(((const u8 *)fzgx_pool_rodata_lbl_8008FF50_50));
v2 -= 2;
do {
v4 = *arg0->unk_400++;

for (v5 = 0; (u16)v5 < 64; v5 += 8) {
quantBuffer.values [((const u8 *)fzgx_pool_rodata_lbl_8008FF50)[v5]] = (f32)(u32)*arg0->unk_400++;
quantBuffer.values [((const u8 *)fzgx_pool_rodata_lbl_8008FF50)[(u16)(v5 + 1)]] = (f32)(u32)*arg0->unk_400++;
quantBuffer.values [((const u8 *)fzgx_pool_rodata_lbl_8008FF50)[(u16)(v5 + 2)]] = (f32)(u32)*arg0->unk_400++;
quantBuffer.values [((const u8 *)fzgx_pool_rodata_lbl_8008FF50)[(u16)(v5 + 3)]] = (f32)(u32)*arg0->unk_400++;
quantBuffer.values [((const u8 *)fzgx_pool_rodata_lbl_8008FF50)[(u16)(v5 + 4)]] = (f32)(u32)*arg0->unk_400++;
quantBuffer.values [((const u8 *)fzgx_pool_rodata_lbl_8008FF50)[(u16)(v5 + 5)]] = (f32)(u32)*arg0->unk_400++;
quantBuffer.values [((const u8 *)fzgx_pool_rodata_lbl_8008FF50)[(u16)(v5 + 6)]] = (f32)(u32)*arg0->unk_400++;
quantBuffer.values [((const u8 *)fzgx_pool_rodata_lbl_8008FF50)[(u16)(v5 + 7)]] = (f32)(u32)*arg0->unk_400++;
}
arg0->unk_419 |= 1 << v4;
v20 = 0;
for (v19 = 0; v19 < 8; v19++) {
for (v22 = 0; v22 < 8; v22++) {
arg0->quant[v4][v20] = ((f64 *)(((const u8 *)fzgx_pool_rodata_lbl_8008FF50_50)))[v22] * ((f64)quantBuffer.values [v20] * ((f64 *)(((const u8 *)fzgx_pool_rodata_lbl_8008FF50_50)))[v19]);
v20++;
}
}
v2 -= 65;
} while (v2);
return 0;
}
