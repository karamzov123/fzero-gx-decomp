#include "types.h"


/* --- rel/movie_module/fn_12_332DC.c --- */
extern const f64 lbl_12_rodata_1100;

int fn_12_332DC(int a, int b, int c, int d);

/* --- rel/movie_module/fn_12_33364.c --- */
/* --- rel/movie_module/fn_12_33364.c --- */
void fn_12_33364(u32 *dst, u32 *src, u32 size) {
    u32 n;
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    u32 m;

    n = (size & 0xF) + 1;
    while (--n) {
        *dst++ = *src++;
    }

    m = (size >> 4) + 1;
    while (--m) {
        a = src[0];
        b = src[1];
        c = src[2];
        d = src[3];
        dst[0] = a;
        dst[1] = b;
        dst[2] = c;
        dst[3] = d;
        a = src[4];
        b = src[5];
        c = src[6];
        d = src[7];
        dst[4] = a;
        dst[5] = b;
        dst[6] = c;
        dst[7] = d;
        a = src[8];
        b = src[9];
        c = src[10];
        d = src[11];
        dst[8] = a;
        dst[9] = b;
        dst[10] = c;
        dst[11] = d;
        a = src[12];
        b = src[13];
        c = src[14];
        d = src[15];
        src += 16;
        dst[12] = a;
        dst[13] = b;
        dst[14] = c;
        dst[15] = d;
        dst += 16;
    }
}

/* --- rel/movie_module/fn_12_33428.c --- */
void fn_12_33428(u32 *dst, u32 value, u32 count);

/* --- rel/movie_module/UTY_MulDiv.c --- */
unsigned int UTY_MulDiv(int multiplicand, int multiplier, int divisor);
