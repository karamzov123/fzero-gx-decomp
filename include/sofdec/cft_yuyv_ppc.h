#ifndef SOFDEC_CFT_YUYV_PPC_H
#define SOFDEC_CFT_YUYV_PPC_H

/* CRI CFT/GC, Ycc420 planar -> Ycc422 (YUYV) packing kernel of movie_module fn_12_3C8CC.
 *
 * This is inline assembly on the caller's register variables, like the Sofdec kernels in mpvidct_ppc.h and
 * mpvmc_ppc.h. The compiler allocates the registers and schedules the instructions together with the C
 * loads and stores around them. Retail's loop cannot be reached from C: every pair of output words reuses
 * the same two registers for the whole function (one register object each for row0 and row1), the chroma
 * word is built once, copied with `mr`, and the two luma bytes of each row are inserted in place. Written
 * as C expressions the same values become per-statement temporaries that MWCC copies and colours
 * differently (measured in the earlier rounds on this function).
 *
 * One call packs two luma samples of each of two rows with one Cb and one Cr sample:
 *
 *     row0 = y0[n] << 24 | cb[k] << 16 | y0[n + 1] << 8 | cr[k]
 *     row1 = y1[n] << 24 | cb[k] << 16 | y1[n + 1] << 8 | cr[k]
 *
 * cb, cr, y0 and y1 are big-endian words of four samples. cb_rotate and cr_rotate select chroma sample k,
 * high_rotate and low_rotate select luma samples n and n + 1 (see the four wrappers below). All operands
 * must be `register` variables. A macro is one logical line, hence the ';' after each instruction. */
#define CFT_YUYV_PACK(row0, row1, cb, cr, y0, y1, cb_rotate, cr_rotate, high_rotate, low_rotate) \
    asm { \
        rlwinm row0, cb, cb_rotate, 8, 15; \
        rlwimi row0, cr, cr_rotate, 24, 31; \
        mr row1, row0; \
        rlwimi row0, y0, high_rotate, 0, 7; \
        rlwimi row1, y1, high_rotate, 0, 7; \
        rlwimi row0, y0, low_rotate, 16, 23; \
        rlwimi row1, y1, low_rotate, 16, 23; \
    }

/* Chroma sample k of the current Cb/Cr words with the first or second half of the current luma words. */
#define CFT_YUYV_PACK_C0_Y01(row0, row1, cb, cr, y0, y1) CFT_YUYV_PACK(row0, row1, cb, cr, y0, y1, 24, 8, 0, 24)
#define CFT_YUYV_PACK_C1_Y23(row0, row1, cb, cr, y0, y1) CFT_YUYV_PACK(row0, row1, cb, cr, y0, y1, 0, 16, 16, 8)
#define CFT_YUYV_PACK_C2_Y01(row0, row1, cb, cr, y0, y1) CFT_YUYV_PACK(row0, row1, cb, cr, y0, y1, 8, 24, 0, 24)
#define CFT_YUYV_PACK_C3_Y23(row0, row1, cb, cr, y0, y1) CFT_YUYV_PACK(row0, row1, cb, cr, y0, y1, 16, 0, 16, 8)

#endif
