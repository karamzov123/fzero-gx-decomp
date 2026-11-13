#include "types.h"
#include "sofdec/cft_y84c44_ppc.h"

typedef struct CFTYcc420Planar {
    const u8 *y;
    const u8 *cb;
    const u8 *cr;
    s32 y_stride;
    s32 cb_stride;
    s32 cr_stride;
} CFTYcc420Planar;

typedef struct CFTYcc422Output {
    u8 *data;
    u32 width;
    u32 height;
    u32 buffer_width;
    u32 line_step;
    s32 reserved_14;
    u32 buffer_height;
} CFTYcc422Output;

#pragma use_lmw_stmw on

/* CRI CFT/GC: Ycc420 planar -> Ycc422 (YUYV) packed through lookup tables. `y_hi` points at four
 * consecutive 256-entry tables (luma in the high byte position of a pixel pair, luma in the low one,
 * Cb, Cr), each entry already shifted into place, so one output word is the OR of four lookups.
 * Each pass of the outer loop converts two luma rows, which share one chroma row, into two output
 * rows; the inner loop consumes two words of Cb and Cr and four words of each luma row (16 pixels),
 * as eight pixel pairs.
 *
 * The prefetch is CFT_CACHE_TOUCH from sofdec/cft_y84c44_ppc.h (inline assembly, as in the
 * neighbouring converters). That keeps the IR optimiser off for the whole function, so every
 * statement below reaches the back end as written: fields are reloaded, and statement and
 * declaration order decide the registers. `prefetch`, `y0` and `y1` are `register` because they are
 * operands of the assembly statement.
 *
 * The statement order inside a pixel pair carries the match in two ways:
 * - The back end starts a new block at the first statement after a block has passed 100
 *   instructions, and it merges an index extraction with its table scaling only inside one block.
 *   Retail has exactly two unmerged extractions (the Cb index of pair 4 and the row-0 low index of
 *   pair 7). That fixes how much code comes before each of them, hence `j` first and `k` and the
 *   row-0 low index before the chroma lookups.
 * - Pairs 2 and 6 are written chroma first, then row 0, then row 1, and they take the address of
 *   row 1's low-table entry before `i` is reused for the row-1 high lookup. The compiler numbers its
 *   scaled-index temporaries in source order and colours them in reverse; retail's registers in
 *   these two pairs (row 1's high index in r3, row 0's in r4) need row 1's low index scaled before
 *   its high index. With `d1 |= y_lo[i]` after the store instead, 59 of 265 words differ. */
void fn_12_3C4A8(const CFTYcc420Planar *src, CFTYcc422Output *dst, const u32 *y_hi) {
    register s32 prefetch;
    u32 a;
    u32 d0;
    const u32 *y_lo;
    const u32 *cb_tbl;
    const u32 *cr_tbl;
    s32 width;
    u32 row_bytes;
    u32 *out0;
    u32 *out1;
    u32 *row_end;
    u32 *out_end;
    register const u32 *y0;
    register const u32 *y1;
    const u32 *cb;
    const u32 *cr;
    u32 b;
    u32 u;
    u32 v;
    u32 d1;
    u32 c;
    u32 height;
    u32 buf_width;
    u32 buf_height;
    s32 y_skip;
    s32 c_skip;
    u32 out_skip;
    const u32 *lo1;
    u32 line_step;
    u32 i;
    u32 j;
    u32 k;

    y_lo = y_hi + 256;
    cb_tbl = y_lo + 256;
    cr_tbl = cb_tbl + 256;
    prefetch = 0x20;
    y0 = (const u32 *)src->y - 1;
    y1 = y0 + src->y_stride / sizeof(u32);
    cb = (const u32 *)src->cb - 1;
    cr = (const u32 *)src->cr - 1;
    /* All six pointers start one word early: the loop uses pre-increment accesses. */
    out0 = (u32 *)dst->data;
    out0--;
    buf_width = dst->buffer_width;
    if (buf_width == 0) {
        buf_width = 640;
    }
    dst->buffer_width = buf_width;
    buf_height = dst->buffer_height;
    if (buf_height == 0) {
        buf_height = 480;
    }
    dst->buffer_height = buf_height;
    width = src->y_stride;
    if (width > dst->buffer_width) {
        width = dst->buffer_width;
    } else {
        out0 += (dst->buffer_width - dst->width) * 2 / 2 / 4;
    }
    height = dst->height;
    if (height > dst->buffer_height) {
        height = dst->buffer_height;
    } else {
        out0 += dst->buffer_width * (dst->buffer_height - height * dst->line_step) / 4;
    }
    line_step = dst->line_step;
    /* Bytes written per output row: two bytes per pixel, in whole words. */
    row_bytes = width * 2 * sizeof(u16) / 2 / sizeof(u32) * sizeof(u32);
    out1 = out0 + dst->buffer_width * line_step / 2;
    y_skip = src->y_stride / 4 * 2 - width / 4;
    c_skip = (src->cb_stride - width / 2) / 4;
    out_skip = (line_step * (dst->buffer_width * 2) - width) / 2;
    out_end = out0 + line_step * (dst->buffer_width / 2 * height);
    while (out_end > out0) {
        row_end = (u32 *)((u8 *)out0 + row_bytes);
        while (row_end > out0) {
            CFT_CACHE_TOUCH(y0, prefetch);
            u = *++cb;
            v = *++cr;
            a = *++y0;
            b = *++y1;
            /* Pair 1: luma bytes 3 and 2 of the first words, chroma byte 3. */
            j = u >> 24;
            i = a >> 24;
            d0 = y_hi[i];
            i = b >> 24;
            d1 = y_hi[i];
            k = v >> 24;
            i = (a >> 16) & 0xFF;
            c = cb_tbl[j];
            c |= cr_tbl[k];
            d0 |= c;
            d1 |= c;
            d0 |= y_lo[i];
            *++out0 = d0;
            i = (b >> 16) & 0xFF;
            d1 |= y_lo[i];
            *++out1 = d1;
            /* Pair 2: luma bytes 1 and 0, chroma byte 2: chroma, row 0, row 1 (see above). */
            j = (u >> 16) & 0xFF;
            c = cb_tbl[j];
            k = (v >> 16) & 0xFF;
            c |= cr_tbl[k];
            i = (a >> 8) & 0xFF;
            d0 = y_hi[i];
            d0 |= c;
            i = a & 0xFF;
            d0 |= y_lo[i];
            i = b & 0xFF;
            lo1 = &y_lo[i];
            i = (b >> 8) & 0xFF;
            d1 = y_hi[i];
            *++out0 = d0;
            d1 |= c;
            d1 |= *lo1;
            *++out1 = d1;
            a = *++y0;
            b = *++y1;
            /* Pair 3: luma bytes 3 and 2 of the second words, chroma byte 1. */
            j = (u >> 8) & 0xFF;
            i = a >> 24;
            d0 = y_hi[i];
            i = b >> 24;
            d1 = y_hi[i];
            k = (v >> 8) & 0xFF;
            i = (a >> 16) & 0xFF;
            c = cb_tbl[j];
            c |= cr_tbl[k];
            d0 |= c;
            d1 |= c;
            d0 |= y_lo[i];
            *++out0 = d0;
            i = (b >> 16) & 0xFF;
            d1 |= y_lo[i];
            *++out1 = d1;
            /* Pair 4: luma bytes 1 and 0, chroma byte 0. */
            j = u & 0xFF;
            i = (a >> 8) & 0xFF;
            d0 = y_hi[i];
            i = (b >> 8) & 0xFF;
            d1 = y_hi[i];
            k = v & 0xFF;
            i = a & 0xFF;
            c = cb_tbl[j];
            c |= cr_tbl[k];
            d0 |= c;
            d1 |= c;
            d0 |= y_lo[i];
            *++out0 = d0;
            i = b & 0xFF;
            d1 |= y_lo[i];
            *++out1 = d1;
            CFT_CACHE_TOUCH(y1, prefetch);
            u = *++cb;
            v = *++cr;
            a = *++y0;
            b = *++y1;
            /* Pair 5: luma bytes 3 and 2 of the first words, chroma byte 3. */
            j = u >> 24;
            i = a >> 24;
            d0 = y_hi[i];
            i = b >> 24;
            d1 = y_hi[i];
            k = v >> 24;
            i = (a >> 16) & 0xFF;
            c = cb_tbl[j];
            c |= cr_tbl[k];
            d0 |= c;
            d1 |= c;
            d0 |= y_lo[i];
            *++out0 = d0;
            i = (b >> 16) & 0xFF;
            d1 |= y_lo[i];
            *++out1 = d1;
            /* Pair 6: luma bytes 1 and 0, chroma byte 2: chroma, row 0, row 1 (see above). */
            j = (u >> 16) & 0xFF;
            c = cb_tbl[j];
            k = (v >> 16) & 0xFF;
            c |= cr_tbl[k];
            i = (a >> 8) & 0xFF;
            d0 = y_hi[i];
            d0 |= c;
            i = a & 0xFF;
            d0 |= y_lo[i];
            i = b & 0xFF;
            lo1 = &y_lo[i];
            i = (b >> 8) & 0xFF;
            d1 = y_hi[i];
            *++out0 = d0;
            d1 |= c;
            d1 |= *lo1;
            *++out1 = d1;
            a = *++y0;
            b = *++y1;
            /* Pair 7: luma bytes 3 and 2 of the second words, chroma byte 1. */
            j = (u >> 8) & 0xFF;
            i = a >> 24;
            d0 = y_hi[i];
            i = b >> 24;
            d1 = y_hi[i];
            k = (v >> 8) & 0xFF;
            i = (a >> 16) & 0xFF;
            c = cb_tbl[j];
            c |= cr_tbl[k];
            d0 |= c;
            d1 |= c;
            d0 |= y_lo[i];
            *++out0 = d0;
            i = (b >> 16) & 0xFF;
            d1 |= y_lo[i];
            *++out1 = d1;
            /* Pair 8: luma bytes 1 and 0, chroma byte 0. */
            j = u & 0xFF;
            i = (a >> 8) & 0xFF;
            d0 = y_hi[i];
            i = (b >> 8) & 0xFF;
            d1 = y_hi[i];
            k = v & 0xFF;
            i = a & 0xFF;
            c = cb_tbl[j];
            c |= cr_tbl[k];
            d0 |= c;
            d1 |= c;
            d0 |= y_lo[i];
            *++out0 = d0;
            i = b & 0xFF;
            d1 |= y_lo[i];
            *++out1 = d1;
        }
        out0 += out_skip;
        out1 += out_skip;
        y0 += y_skip;
        y1 += y_skip;
        cb += c_skip;
        cr += c_skip;
    }
}
