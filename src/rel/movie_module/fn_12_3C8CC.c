#include "types.h"
#include "sofdec/cft_y84c44_ppc.h"
#include "sofdec/cft_yuyv_ppc.h"
#pragma use_lmw_stmw on

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

/* CRI CFT/GC: Ycc420 planar -> Ycc422 (YUYV) packed. Each pass of the outer loop converts two luma rows,
 * which share one chroma row, into two output rows; the inner loop consumes two words of Cb and Cr and
 * four words of each luma row (16 pixels) per iteration. The packing itself is the inline-assembly kernel
 * in sofdec/cft_yuyv_ppc.h, which is why a, b, u, v, row0 and row1 are register variables.
 *
 * The cache prefetch is CFT_CACHE_TOUCH from sofdec/cft_cache_ppc.h (inline assembly, as in the sibling
 * converters fn_12_3C17C and fn_12_3C4A8), so prefetch, y0 and y1 are register variables too. Retail shows
 * a function that got no IR-level optimisation: it reloads dst->buffer_width and src->y_stride in every
 * block, keeps the prefetch distance in a register set at entry, and has the scaled pointer steps hoisted
 * by the back end. The declaration order and the order of the five set-up statements before the loop give
 * retail's registers. */
void fn_12_3C8CC(const CFTYcc420Planar *src, CFTYcc422Output *dst) {
    register s32 prefetch;
    u32 *out0;
    u32 *out1;
    register const u32 *y0;
    register const u32 *y1;
    const u32 *cb;
    const u32 *cr;
    u32 *row_end;
    u32 *out_end;
    register u32 a;
    register u32 b;
    register u32 u;
    register u32 v;
    register u32 row0;
    register u32 row1;
    s32 width;
    u32 height;
    s32 y_skip;
    s32 c_skip;
    u32 out_skip;

    prefetch = 0x20;
    width = src->y_stride;
    y0 = (const u32 *)src->y - 1;
    y1 = y0 + width / sizeof(u32);
    cb = (const u32 *)src->cb - 1;
    cr = (const u32 *)src->cr - 1;
    out0 = (u32 *)dst->data - 1;
    if (width > dst->buffer_width) {
        width = dst->buffer_width;
    } else {
        out0 += (dst->buffer_width - dst->width) * 2 / 2 / 4;
    }
    if (dst->height > dst->buffer_height) {
        height = dst->buffer_height;
    } else {
        height = dst->height;
        out0 += dst->buffer_width * (dst->buffer_height - dst->height * dst->line_step) / 4;
    }
    out1 = out0 + dst->buffer_width * dst->line_step / 2;
    y_skip = src->y_stride / 4 * 2 - width / 4;
    c_skip = (src->cb_stride - width / 2) / 4;
    out_skip = (dst->line_step * (dst->buffer_width * 2) - width) / 2;
    out_end = out0 + dst->line_step * (dst->buffer_width / 2 * height);
    while (out_end > out0) {
        row_end = out0 + width * 2 * sizeof(u16) / 2 / sizeof(u32);
        while (row_end > out0) {
            CFT_CACHE_TOUCH(y0, prefetch);
            u = *++cb;
            v = *++cr;
            a = *++y0;
            b = *++y1;
            CFT_YUYV_PACK_C0_Y01(row0, row1, u, v, a, b);
            *++out0 = row0;
            *++out1 = row1;
            CFT_YUYV_PACK_C1_Y23(row0, row1, u, v, a, b);
            a = *++y0;
            b = *++y1;
            *++out0 = row0;
            *++out1 = row1;
            CFT_YUYV_PACK_C2_Y01(row0, row1, u, v, a, b);
            *++out0 = row0;
            *++out1 = row1;
            CFT_YUYV_PACK_C3_Y23(row0, row1, u, v, a, b);
            *++out0 = row0;
            *++out1 = row1;
            CFT_CACHE_TOUCH(y1, prefetch);
            u = *++cb;
            v = *++cr;
            a = *++y0;
            b = *++y1;
            CFT_YUYV_PACK_C0_Y01(row0, row1, u, v, a, b);
            *++out0 = row0;
            *++out1 = row1;
            CFT_YUYV_PACK_C1_Y23(row0, row1, u, v, a, b);
            a = *++y0;
            b = *++y1;
            *++out0 = row0;
            *++out1 = row1;
            CFT_YUYV_PACK_C2_Y01(row0, row1, u, v, a, b);
            *++out0 = row0;
            *++out1 = row1;
            CFT_YUYV_PACK_C3_Y23(row0, row1, u, v, a, b);
            *++out0 = row0;
            *++out1 = row1;
        }
        out0 += out_skip;
        out1 += out_skip;
        y0 += y_skip;
        y1 += y_skip;
        cb += c_skip;
        cr += c_skip;
    }
}
