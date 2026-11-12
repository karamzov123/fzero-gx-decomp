#include "types.h"
#include "sofdec/cft_y84c44_ppc.h"
#pragma use_lmw_stmw on

typedef struct CFTYcc420Planar {
    const u8 *y;
    const u8 *cb;
    const u8 *cr;
    s32 y_stride;
    s32 cb_stride;
    s32 cr_stride;
} CFTYcc420Planar;

/* CRI CFT/GC: Ycc420 planar -> Y8 + C44 tiles (CFT_Ycc420plnToY84C44 in CRI's library). The luma plane
 * becomes 8x4 tiles (four 8-byte rows per tile), the two chroma planes become tiles of four rows of two
 * words, each word interleaving two Cb and two Cr samples. Cache control and the luma tile store are the
 * inline-assembly macros of sofdec/cft_y84c44_ppc.h, which is why their operands are register variables.
 *
 * The rows of a tile are read at a variable offset from the first row's pointer; the compiler turns the
 * three offsets of each plane into pointers of their own. stride, stride2 and stride3 are used by both
 * halves, in bytes for luma and in words for chroma. */
void fn_12_3C17C(const CFTYcc420Planar *src, u8 *dst_y, register u32 *c_output, s32 width, s32 height) {
    register f64 *y_output = (f64 *)dst_y;
    register const f64 *y_row;
    const u32 *cb_row;
    const u32 *cr_row;
    register s32 next;
    s32 stride;
    s32 stride2;
    s32 stride3;
    s32 cb_stride;
    s32 count;
    s32 rows;
    s32 advance;
    s32 y_skip;
    s32 skip;
    s32 tile_x;
    s32 tile_y;
    u32 cb;
    u32 cr;

    y_output--;
    next = sizeof(f64);
    stride = src->y_stride;
    y_row = (const f64 *)src->y;
    stride2 = stride * 2;
    stride3 = stride * 3;
    advance = stride3 / 8;
    count = stride / 8;
    rows = height / 4;
    y_skip = (width - stride) / 8;
    for (tile_y = 0; tile_y < rows; tile_y++) {
        for (tile_x = 0; tile_x < count; tile_x++) {
            register f64 row0, row1, row2, row3;

            CFT_CACHE_ZERO(y_output, next);
            row0 = *y_row;
            row1 = *(const f64 *)((const u8 *)y_row + stride);
            row2 = *(const f64 *)((const u8 *)y_row + stride2);
            row3 = *(const f64 *)((const u8 *)y_row + stride3);
            CFT_CACHE_TOUCH(y_row, next);
            y_row++;
            CFT_STORE_Y8_TILE(y_output, row0, row1, row2, row3);
        }
        y_output += y_skip * 4;
        y_row += advance;
    }

    c_output--;
    next = sizeof(u32);
    cb_stride = src->cb_stride;
    cb_row = (const u32 *)src->cb;
    cr_row = (const u32 *)src->cr;
    count = src->y_stride / 2 / 4;
    skip = (cb_stride - src->y_stride / 2) / 4;
    rows = height / 2 / 4;
    stride = cb_stride / 4;
    stride2 = stride * 2;
    stride3 = stride * 3;
    for (tile_y = 0; tile_y < rows; tile_y++) {
        for (tile_x = 0; tile_x < count; tile_x++) {
            CFT_CACHE_ZERO(c_output, next);
#define STORE_CHROMA_ROW(offset)                                         \
    cr = cr_row[offset];                                                 \
    cb = cb_row[offset];                                                 \
    *++c_output = (cb & 0xff000000) | ((cr >> 8) & 0x00ff0000) |         \
                  ((cb >> 8) & 0x0000ff00) | ((cr >> 16) & 0x000000ff);  \
    *++c_output = ((cb << 16) & 0xff000000) | ((cr << 8) & 0x00ff0000) | \
                  ((cb << 8) & 0x0000ff00) | (cr & 0x000000ff)
            STORE_CHROMA_ROW(0);
            STORE_CHROMA_ROW(stride);
            STORE_CHROMA_ROW(stride2);
            STORE_CHROMA_ROW(stride3);
#undef STORE_CHROMA_ROW
            cb_row++;
            cr_row++;
        }
        c_output += skip * 8;
        cb_row += stride3 + skip;
        cr_row += stride3 + skip;
    }
}
