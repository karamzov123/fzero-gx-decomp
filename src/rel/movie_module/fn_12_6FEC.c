#include "types.h"

struct fn_12_6FEC_lbl_12_bss_68F8 {
    u32 unk_0;
};
struct fn_12_6FEC_lbl_12_bss_68FC {
    u32 unk_0;
};
struct fn_12_6FEC_lbl_12_bss_6900 {
    u32 unk_0;
};
struct fn_12_6FEC_lbl_12_bss_6904 {
    u32 unk_0;
};
struct fn_12_6FEC_lbl_12_bss_6908 {
    u32 unk_0;
};

extern struct fn_12_6FEC_lbl_12_bss_68F8 lbl_12_bss_68F8;
extern struct fn_12_6FEC_lbl_12_bss_68FC lbl_12_bss_68FC;
extern struct fn_12_6FEC_lbl_12_bss_6900 lbl_12_bss_6900;
extern struct fn_12_6FEC_lbl_12_bss_6904 lbl_12_bss_6904;
extern struct fn_12_6FEC_lbl_12_bss_6908 lbl_12_bss_6908;
extern u8 lbl_12_bss_4DC0[64];
extern u32 lbl_12_bss_68F4;
extern u8 lbl_12_bss_4E00[64];
extern void * memcpy(void *, const void *, u32);
extern void DCT_FsriInitScanTbl(const signed char *, signed char *);
extern void fn_12_33364(u32 *, u32 *, u32);

/* lbl_12_rodata_6A0: the MPEG tables of this TU, one .rodata section */
static const u16 fzgx_pool_bit_masks[16] = {
    0xFFFF, 0x7FFF, 0x3FFF, 0x1FFF, 0x0FFF, 0x07FF, 0x03FF, 0x01FF,
    0x00FF, 0x007F, 0x003F, 0x001F, 0x000F, 0x0007, 0x0003, 0x0001,
};
static const s8 fzgx_pool_zigzag[64] = {
    0x00, 0x01, 0x08, 0x10, 0x09, 0x02, 0x03, 0x0A, 0x11, 0x18, 0x20, 0x19, 0x12, 0x0B, 0x04, 0x05,
    0x0C, 0x13, 0x1A, 0x21, 0x28, 0x30, 0x29, 0x22, 0x1B, 0x14, 0x0D, 0x06, 0x07, 0x0E, 0x15, 0x1C,
    0x23, 0x2A, 0x31, 0x38, 0x39, 0x32, 0x2B, 0x24, 0x1D, 0x16, 0x0F, 0x17, 0x1E, 0x25, 0x2C, 0x33,
    0x3A, 0x3B, 0x34, 0x2D, 0x26, 0x1F, 0x27, 0x2E, 0x35, 0x3C, 0x3D, 0x36, 0x2F, 0x37, 0x3E, 0x3F,
};
static const u8 fzgx_pool_intra_quant[64] = {
    0x08, 0x10, 0x13, 0x16, 0x1A, 0x1B, 0x1D, 0x22, 0x10, 0x10, 0x16, 0x18, 0x1B, 0x1D, 0x22, 0x25,
    0x13, 0x16, 0x1A, 0x1B, 0x1D, 0x22, 0x22, 0x26, 0x16, 0x16, 0x1A, 0x1B, 0x1D, 0x22, 0x25, 0x28,
    0x16, 0x1A, 0x1B, 0x1D, 0x20, 0x23, 0x28, 0x30, 0x1A, 0x1B, 0x1D, 0x20, 0x23, 0x28, 0x30, 0x3A,
    0x1A, 0x1B, 0x1D, 0x22, 0x26, 0x2E, 0x38, 0x45, 0x1B, 0x1D, 0x23, 0x26, 0x2E, 0x38, 0x45, 0x53,
};
static const u8 fzgx_pool_defaults[32] = {
    5, 4, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1,
};

void fn_12_6FEC(u8 *arg0) {
    signed char tbl[64];
    signed char scan[64];
    s32 i;
    u32 *q;

    for (i = 0; i < 64; i++) {
        tbl[i] = i;
    }
    DCT_FsriInitScanTbl(tbl, scan);
    for (i = 0; i < 64; i++) {
        lbl_12_bss_4E00[i] = scan[fzgx_pool_zigzag[i]];
        lbl_12_bss_4DC0[scan[i]] = fzgx_pool_intra_quant[i];
    }
    q = (u32 *)(arg0 + 32);
    if (q != 0) {
        fn_12_33364(q, (u32 *)lbl_12_bss_4E00, 16);
    }
    if (arg0 != 0) {
        fn_12_33364((u32 *)arg0, (u32 *)fzgx_pool_bit_masks, 8);
    }
    memcpy(arg0 + 0x160, fzgx_pool_defaults, 32);
    *(u32 *)(arg0 + 0x180) = lbl_12_bss_68F4 - 16;
    *(u32 *)(arg0 + 0x184) = 21;
    *(u32 *)(arg0 + 0x188) = lbl_12_bss_68F8.unk_0 - 32;
    *(u32 *)(arg0 + 0x18c) = 19;
    *(u32 *)(arg0 + 0x190) = lbl_12_bss_68FC.unk_0 - 32;
    *(u32 *)(arg0 + 0x194) = 18;
    *(u32 *)(arg0 + 0x198) = lbl_12_bss_6900.unk_0 - 32;
    *(u32 *)(arg0 + 0x19c) = 17;
    *(u32 *)(arg0 + 0x1a0) = lbl_12_bss_6904.unk_0 - 32;
    *(u32 *)(arg0 + 0x1a4) = 16;
    *(u32 *)(arg0 + 0x1a8) = lbl_12_bss_6908.unk_0 - 32;
    *(u32 *)(arg0 + 0x1ac) = 15;
}
