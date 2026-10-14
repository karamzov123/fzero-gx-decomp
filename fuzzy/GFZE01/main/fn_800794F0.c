/* Non-matching: best partial attempt (0.00% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

u8 *fn_800794F0(u8 *dst, u8 *src, u32 size) {
    s32 words;
    s32 i;

    words = (s32)size >> 4;
    if (words > 0) {
        for (i = words >> 2; i > 0; i--) {
            ((u32 *)dst)[0] = ((u32 *)src)[0];
            ((u32 *)dst)[1] = ((u32 *)src)[1];
            ((u32 *)dst)[2] = ((u32 *)src)[2];
            ((u32 *)dst)[3] = ((u32 *)src)[3];
            ((u32 *)dst)[4] = ((u32 *)src)[4];
            ((u32 *)dst)[5] = ((u32 *)src)[5];
            ((u32 *)dst)[6] = ((u32 *)src)[6];
            ((u32 *)dst)[7] = ((u32 *)src)[7];
            ((u32 *)dst)[8] = ((u32 *)src)[8];
            ((u32 *)dst)[9] = ((u32 *)src)[9];
            ((u32 *)dst)[10] = ((u32 *)src)[10];
            ((u32 *)dst)[11] = ((u32 *)src)[11];
            ((u32 *)dst)[12] = ((u32 *)src)[12];
            ((u32 *)dst)[13] = ((u32 *)src)[13];
            ((u32 *)dst)[14] = ((u32 *)src)[14];
            ((u32 *)dst)[15] = ((u32 *)src)[15];
            dst += 0x40;
            src += 0x40;
        }
        for (i = words & 3; i > 0; i--) {
            ((u32 *)dst)[0] = ((u32 *)src)[0];
            ((u32 *)dst)[1] = ((u32 *)src)[1];
            ((u32 *)dst)[2] = ((u32 *)src)[2];
            ((u32 *)dst)[3] = ((u32 *)src)[3];
            dst += 0x10;
            src += 0x10;
        }
    }
    size &= 0xF;
    if (size != 0) {
        for (i = size >> 3; i > 0; i--) {
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            dst[3] = src[3];
            dst[4] = src[4];
            dst[5] = src[5];
            dst[6] = src[6];
            dst[7] = src[7];
            dst += 8;
            src += 8;
        }
        for (i = size & 7; i > 0; i--) {
            *dst = *src;
            dst++;
            src++;
        }
    }
    return dst;
}
