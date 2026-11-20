#include "types.h"
#include "sofdec/mwsst.h"
#include "sofdec/sj.h"
#include "sofdec/cft_y84c44_ppc.h"
#include "sofdec/cft_yuyv_ppc.h"
#pragma section RX ".fzgxpool"
#pragma use_lmw_stmw on

/* --- rel/movie_module/MWSST_StartSj.c --- */
extern MwsStManager lbl_12_data_E90;

static inline int mwsst_IsValid(const MwsStHandle *handle) {
    if (lbl_12_data_E90.interface == 0) {
        return 0;
    }
    if (handle->active != 1) {
        return 0;
    }
    if (handle->backend == 0) {
        return 0;
    }
    return 1;
}

void MWSST_StartSj(MwsStHandle *handle) {
    if (mwsst_IsValid(handle) == 1) {
        void *backend = handle->backend;
        SJ *stream = handle->stream;
        if (lbl_12_data_E90.interface != 0 && lbl_12_data_E90.interface->start_sj != 0) {
            lbl_12_data_E90.interface->start_sj(backend, stream);
        }
    }
}

/* --- rel/movie_module/fn_12_3B65C.c --- */
struct fn_12_3B65C_Arg0 {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    f32 unk_54;
    f32 unk_58;
    f32 unk_5C;
    f32 unk_60;
    f32 unk_64;
    f32 unk_68;
    f32 unk_6C;
    f32 unk_70;
    f32 unk_74;
    f32 unk_78;
    f32 unk_7C;
    f32 unk_80;
    f32 unk_84;
    f32 unk_88;
    f32 unk_8C;
    f32 unk_90;
    f32 unk_94;
    f32 unk_98;
    f32 unk_9C;
    f32 unk_A0;
    f32 unk_A4;
    f32 unk_A8;
    f32 unk_AC;
    f32 unk_B0;
    f32 unk_B4;
    f32 unk_B8;
    f32 unk_BC;
    f32 unk_C0;
    f32 unk_C4;
    f32 unk_C8;
    f32 unk_CC;
    f32 unk_D0;
    f32 unk_D4;
    f32 unk_D8;
    f32 unk_DC;
    f32 unk_E0;
    f32 unk_E4;
    f32 unk_E8;
    f32 unk_EC;
    f32 unk_F0;
    f32 unk_F4;
    f32 unk_F8;
    f32 unk_FC;
    u8 pad_100[0x700];
    f32 unk_800;
    f32 unk_804;
    f32 unk_808;
    f32 unk_80C;
    f32 unk_810;
    f32 unk_814;
    f32 unk_818;
    f32 unk_81C;
    f32 unk_820;
    f32 unk_824;
    f32 unk_828;
    f32 unk_82C;
    f32 unk_830;
    f32 unk_834;
    f32 unk_838;
    f32 unk_83C;
    f32 unk_840;
    f32 unk_844;
    f32 unk_848;
    f32 unk_84C;
    f32 unk_850;
    f32 unk_854;
    f32 unk_858;
    f32 unk_85C;
    f32 unk_860;
    f32 unk_864;
    f32 unk_868;
    f32 unk_86C;
    f32 unk_870;
    f32 unk_874;
    f32 unk_878;
    f32 unk_87C;
    f32 unk_880;
    f32 unk_884;
    f32 unk_888;
    f32 unk_88C;
    f32 unk_890;
    f32 unk_894;
    f32 unk_898;
    f32 unk_89C;
    f32 unk_8A0;
    f32 unk_8A4;
    f32 unk_8A8;
    f32 unk_8AC;
    f32 unk_8B0;
    f32 unk_8B4;
    f32 unk_8B8;
    f32 unk_8BC;
    f32 unk_8C0;
    f32 unk_8C4;
    f32 unk_8C8;
    f32 unk_8CC;
    f32 unk_8D0;
    f32 unk_8D4;
    f32 unk_8D8;
    f32 unk_8DC;
    f32 unk_8E0;
    f32 unk_8E4;
    f32 unk_8E8;
    f32 unk_8EC;
    f32 unk_8F0;
    f32 unk_8F4;
    f32 unk_8F8;
    f32 unk_8FC;
};

const char lbl_12_rodata_2E10[] = "\nCRI CFT/GC Ver.1.29 Build:May  9 2003 15:17:25\n";

void fn_12_3B65C(struct fn_12_3B65C_Arg0 *arg0) {
    s32 v12;
    s32 v24;
    s32 v55;
    f32 *v10 = (f32 *)((u8 *)arg0 + 4096);
    f32 *v11 = (f32 *)((u8 *)arg0 + 8192);
    f32 *v18 = (f32 *)arg0;
    f32 v23;
    s32 v15;

    for (v12 = 0; v12 < 256; v12++) {
        v10[v12 * 4 + 3] = 0.5f + 2.017f * (f32)(v12 - 128);
        v10[v12 * 4 + 2] = 0.5f + -0.392f * (f32)(v12 - 128);
        v10[v12 * 4 + 1] = 0.0f;
        v10[v12 * 4 + 0] = 0.0f;
        v11[v12 * 4 + 3] = 0.0f;
        v11[v12 * 4 + 2] = 0.5f + -0.813f * (f32)(v12 - 128);
        v11[v12 * 4 + 1] = 0.5f + 1.596f * (f32)(v12 - 128);
        v11[v12 * 4 + 0] = 0.0f;
    }
    for (v24 = 0; v24 < 16; v24++) {
        v18[v24 * 4 + 3] = 0.0f;
        v18[v24 * 4 + 2] = 0.0f;
        v18[v24 * 4 + 1] = 0.0f;
        v18[v24 * 4 + 0] = 0.0f;
    }
    for (v24 = 16; v24 < 128; v24++) {
        v15 = ((v24 - 16) << 8) / 112;
        v23 = 0.5f + 1.164f * (f32)(v15 - 16);
        v18[v24 * 4 + 3] = v23;
        v18[v24 * 4 + 2] = v23;
        v18[v24 * 4 + 1] = v23;
        v18[v24 * 4 + 0] = 127.0f;
    }
    for (v55 = 128; v55 < 144; v55++) {
        v18[v55 * 4 + 3] = 278.696f;
        v18[v55 * 4 + 2] = 278.696f;
        v18[v55 * 4 + 1] = 278.696f;
        v18[v55 * 4 + 0] = 255.0f;
    }
    for (v55 = 144; v55 < 256; v55++) {
        v15 = 255 - (((v55 - 144) << 8) / 112);
        v23 = 0.5f + 1.164f * (f32)(v15 - 16);
        v18[v55 * 4 + 3] = v23;
        v18[v55 * 4 + 2] = v23;
        v18[v55 * 4 + 1] = v23;
        v18[v55 * 4 + 0] = 255.0f;
    }
}

/* --- rel/movie_module/fn_12_3BEF0.c --- */
const char fzgx_pool_head[0x34] = "\nCRI CFT/GC Ver.1.29 Build:May  9 2003 15:17:25\n";

/* Literal-pool primer: fixes retail's first-use order of the TU's pooled constants.
 * Volatile stores preserve every literal in the pool rather than eliminating overwritten values. */
__declspec(section ".fzgxpool") void fzgx_pool_primer(volatile f32 *p, s32 n) { /* volatile: retain literal-pool primer stores. */
    p[0] = 0.5f;
    p[0] = 2.017f;
    p[0] = -0.392f;
    p[0] = 0.0f;
    p[0] = -0.813f;
    p[0] = 1.596f;
    p[0] = 1.164f;
    p[0] = 127.0f;
    p[0] = 278.696f;
    p[0] = 255.0f;
    p[0] = (f32)n;
}

/* YCbCr -> RGB conversion tables (Y, Cb, Cr) plus an alpha ramp in column 0. */
void fn_12_3BEF0(s32 mode, s32 lo, s32 hi, f32 *tbl) {
    s32 i;
    s32 j;
    f32 scale;
    f32 (*t)[4] = (f32 (*)[4])tbl;
    s32 k;
    s32 m;

    for (i = 0, k = 256, m = 512; i < 256; i++, k++, m++) {
        f32 y = 1.164f * (f32)(i - 16) + 0.5f;
        t[i][3] = y;
        t[i][2] = y;
        t[i][1] = y;
        t[k][3] = 2.017f * (f32)(i - 128) + 0.5f;
        t[k][2] = -0.392f * (f32)(i - 128) + 0.5f;
        t[k][1] = 0.0f;
        t[k][0] = 0.0f;
        t[m][3] = 0.0f;
        t[m][2] = -0.813f * (f32)(i - 128) + 0.5f;
        t[m][1] = 1.596f * (f32)(i - 128) + 0.5f;
        t[m][0] = 0.0f;
    }

    scale = 255.0f / (f32)(hi - lo);
    if (mode == 1) {
        for (i = 0, j = 255; i < 256; i++, j--) {
            if (i < lo) {
                tbl[i * 4] = 255.0f;
            } else if (i > hi) {
                tbl[i * 4] = 0.0f;
            } else {
                tbl[i * 4] = scale * (f32)(hi - j);
            }
        }
    } else {
        for (i = 0; i < 256; i++) {
            if (i < lo) {
                tbl[i * 4] = 0.0f;
            } else if (i > hi) {
                tbl[i * 4] = 255.0f;
            } else {
                tbl[i * 4] = scale * (f32)(i - lo);
            }
        }
    }
}

/* --- rel/movie_module/fn_12_3C17C.c --- */
/* --- rel/movie_module/fn_12_3C17C.c --- */
/* --- rel/movie_module/fn_12_3C17C.c --- */
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

/* --- rel/movie_module/fn_12_3C4A8.c --- */
typedef struct CFTYcc422Output {
    u8 *data;
    u32 width;
    u32 height;
    u32 buffer_width;
    u32 line_step;
    s32 reserved_14;
    u32 buffer_height;
} CFTYcc422Output;


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

/* --- rel/movie_module/fn_12_3C8CC.c --- */
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
