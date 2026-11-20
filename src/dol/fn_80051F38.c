#include "types.h"


/* --- dol/fn_80051F38.c --- */
/* --- dol/fn_80051F38.c --- */
/* Dot products of the 32 floats at arg0 with 32-float rows of m: rows 0-15 go to out[0..15] and,
 * negated, to out[32..17]; rows 33-47 go to out[33..47] and out[63..49]; out[16] = 0 and
 * out[48] = -(sum of the 32 inputs). m is walked as a parameter: a local copy for the second
 * loop gets a different register. */
void fn_80051F38(u32 arg0, f32 *m, void *arg2) {
    s32 i;
    f32 *in = (f32 *)arg0;
    f32 *base;
    f32 *row;
    f32 *out = arg2;
    f32 *lo1;
    f32 *hi1;
    f32 *lo2;
    f32 *hi2;
    f32 *a;
    f32 sum;

    i = 16;
    base = row = m;
    lo1 = out;
    hi1 = out + 32;
    lo2 = out + 33;
    hi2 = out + 63;
    do {
        a = in;
        sum = *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        sum += *a++ * *row++;
        *lo1++ = sum;
        *hi1-- = -sum;
    } while (--i);
    out[16] = 0.0f;
    m = base + 33 * 32;
    i = 15;
    do {
        a = in;
        sum = *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        sum += *a++ * *m++;
        *lo2++ = sum;
        *hi2-- = sum;
    } while (--i);
    a = in;
    sum = *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    sum += *a++;
    out[48] = -sum;
}

/* --- dol/fn_80052430.c --- */
void fn_80052430(f32 *tile, f32 *kernel, s16 *out) {
    s32 n = 32;

    do {
        f32 acc = 0.0f;
        f32 v;

        acc += kernel[0] * tile[0x0 / 4];
        acc += kernel[1] * tile[-0xe80 / 4];
        acc += kernel[2] * tile[-0xe00 / 4];
        acc += kernel[3] * tile[-0xc80 / 4];
        acc += kernel[4] * tile[-0xc00 / 4];
        acc += kernel[5] * tile[-0xa80 / 4];
        acc += kernel[6] * tile[-0xa00 / 4];
        acc += kernel[7] * tile[-0x880 / 4];
        acc += kernel[8] * tile[-0x800 / 4];
        acc += kernel[9] * tile[-0x680 / 4];
        acc += kernel[10] * tile[-0x600 / 4];
        acc += kernel[11] * tile[-0x480 / 4];
        acc += kernel[12] * tile[-0x400 / 4];
        acc += kernel[13] * tile[-0x280 / 4];
        acc += kernel[14] * tile[-0x200 / 4];
        acc += kernel[15] * tile[-0x80 / 4];

        kernel += 16;
        tile++;

        if (acc > 2147483648.0f) {
            v = 2147483648.0f;
        } else if (acc < -2147483648.0f) {
            v = -2147483648.0f;
        } else {
            v = acc;
        }

        *out++ = (f32)((s32)v >> 16);
    } while (--n);
}

/* --- dol/fn_80052590.c --- */
void fn_80052590(f32 *tile, f32 *kernel, s16 *out) {
    s32 n = 32;

    do {
        f32 acc = 0.0f;
        f32 v;

        acc += kernel[0] * tile[0x0 / 4];
        acc += kernel[1] * tile[0x180 / 4];
        acc += kernel[2] * tile[-0xe00 / 4];
        acc += kernel[3] * tile[-0xc80 / 4];
        acc += kernel[4] * tile[-0xc00 / 4];
        acc += kernel[5] * tile[-0xa80 / 4];
        acc += kernel[6] * tile[-0xa00 / 4];
        acc += kernel[7] * tile[-0x880 / 4];
        acc += kernel[8] * tile[-0x800 / 4];
        acc += kernel[9] * tile[-0x680 / 4];
        acc += kernel[10] * tile[-0x600 / 4];
        acc += kernel[11] * tile[-0x480 / 4];
        acc += kernel[12] * tile[-0x400 / 4];
        acc += kernel[13] * tile[-0x280 / 4];
        acc += kernel[14] * tile[-0x200 / 4];
        acc += kernel[15] * tile[-0x80 / 4];

        kernel += 16;
        tile++;

        if (acc > 2147483648.0f) {
            v = 2147483648.0f;
        } else if (acc < -2147483648.0f) {
            v = -2147483648.0f;
        } else {
            v = acc;
        }

        *out++ = (f32)((s32)v >> 16);
    } while (--n);
}

/* --- dol/fn_800526F0.c --- */
void fn_800526F0(f32 *tile, f32 *kernel, s16 *out) {
    s32 n = 32;

    do {
        f32 acc = 0.0f;
        f32 v;

        acc += kernel[0] * tile[0x0 / 4];
        acc += kernel[1] * tile[0x180 / 4];
        acc += kernel[2] * tile[0x200 / 4];
        acc += kernel[3] * tile[-0xc80 / 4];
        acc += kernel[4] * tile[-0xc00 / 4];
        acc += kernel[5] * tile[-0xa80 / 4];
        acc += kernel[6] * tile[-0xa00 / 4];
        acc += kernel[7] * tile[-0x880 / 4];
        acc += kernel[8] * tile[-0x800 / 4];
        acc += kernel[9] * tile[-0x680 / 4];
        acc += kernel[10] * tile[-0x600 / 4];
        acc += kernel[11] * tile[-0x480 / 4];
        acc += kernel[12] * tile[-0x400 / 4];
        acc += kernel[13] * tile[-0x280 / 4];
        acc += kernel[14] * tile[-0x200 / 4];
        acc += kernel[15] * tile[-0x80 / 4];

        kernel += 16;
        tile++;

        if (acc > 2147483648.0f) {
            v = 2147483648.0f;
        } else if (acc < -2147483648.0f) {
            v = -2147483648.0f;
        } else {
            v = acc;
        }

        *out++ = (f32)((s32)v >> 16);
    } while (--n);
}

/* --- dol/fn_80052850.c --- */
void fn_80052850(f32 *tile, f32 *kernel, s16 *out) {
    s32 n = 32;

    do {
        f32 acc = 0.0f;
        f32 v;

        acc += kernel[0] * tile[0x0 / 4];
        acc += kernel[1] * tile[0x180 / 4];
        acc += kernel[2] * tile[0x200 / 4];
        acc += kernel[3] * tile[0x380 / 4];
        acc += kernel[4] * tile[-0xc00 / 4];
        acc += kernel[5] * tile[-0xa80 / 4];
        acc += kernel[6] * tile[-0xa00 / 4];
        acc += kernel[7] * tile[-0x880 / 4];
        acc += kernel[8] * tile[-0x800 / 4];
        acc += kernel[9] * tile[-0x680 / 4];
        acc += kernel[10] * tile[-0x600 / 4];
        acc += kernel[11] * tile[-0x480 / 4];
        acc += kernel[12] * tile[-0x400 / 4];
        acc += kernel[13] * tile[-0x280 / 4];
        acc += kernel[14] * tile[-0x200 / 4];
        acc += kernel[15] * tile[-0x80 / 4];

        kernel += 16;
        tile++;

        if (acc > 2147483648.0f) {
            v = 2147483648.0f;
        } else if (acc < -2147483648.0f) {
            v = -2147483648.0f;
        } else {
            v = acc;
        }

        *out++ = (f32)((s32)v >> 16);
    } while (--n);
}

/* --- dol/fn_800529B0.c --- */
void fn_800529B0(f32 *tile, f32 *kernel, s16 *out) {
    s32 n = 32;

    do {
        f32 acc = 0.0f;
        f32 v;

        acc += kernel[0] * tile[0x0 / 4];
        acc += kernel[1] * tile[0x180 / 4];
        acc += kernel[2] * tile[0x200 / 4];
        acc += kernel[3] * tile[0x380 / 4];
        acc += kernel[4] * tile[0x400 / 4];
        acc += kernel[5] * tile[-0xa80 / 4];
        acc += kernel[6] * tile[-0xa00 / 4];
        acc += kernel[7] * tile[-0x880 / 4];
        acc += kernel[8] * tile[-0x800 / 4];
        acc += kernel[9] * tile[-0x680 / 4];
        acc += kernel[10] * tile[-0x600 / 4];
        acc += kernel[11] * tile[-0x480 / 4];
        acc += kernel[12] * tile[-0x400 / 4];
        acc += kernel[13] * tile[-0x280 / 4];
        acc += kernel[14] * tile[-0x200 / 4];
        acc += kernel[15] * tile[-0x80 / 4];

        kernel += 16;
        tile++;

        if (acc > 2147483648.0f) {
            v = 2147483648.0f;
        } else if (acc < -2147483648.0f) {
            v = -2147483648.0f;
        } else {
            v = acc;
        }

        *out++ = (f32)((s32)v >> 16);
    } while (--n);
}

/* --- dol/fn_80052B10.c --- */
void fn_80052B10(f32 *tile, f32 *kernel, s16 *out) {
    s32 n = 32;

    do {
        f32 acc = 0.0f;
        f32 v;

        acc += kernel[0] * tile[0x0 / 4];
        acc += kernel[1] * tile[0x180 / 4];
        acc += kernel[2] * tile[0x200 / 4];
        acc += kernel[3] * tile[0x380 / 4];
        acc += kernel[4] * tile[0x400 / 4];
        acc += kernel[5] * tile[0x580 / 4];
        acc += kernel[6] * tile[-0xa00 / 4];
        acc += kernel[7] * tile[-0x880 / 4];
        acc += kernel[8] * tile[-0x800 / 4];
        acc += kernel[9] * tile[-0x680 / 4];
        acc += kernel[10] * tile[-0x600 / 4];
        acc += kernel[11] * tile[-0x480 / 4];
        acc += kernel[12] * tile[-0x400 / 4];
        acc += kernel[13] * tile[-0x280 / 4];
        acc += kernel[14] * tile[-0x200 / 4];
        acc += kernel[15] * tile[-0x80 / 4];

        kernel += 16;
        tile++;

        if (acc > 2147483648.0f) {
            v = 2147483648.0f;
        } else if (acc < -2147483648.0f) {
            v = -2147483648.0f;
        } else {
            v = acc;
        }

        *out++ = (f32)((s32)v >> 16);
    } while (--n);
}

/* --- dol/fn_80052C70.c --- */
void fn_80052C70(f32 *tile, f32 *kernel, s16 *out) {
    s32 n = 32;

    do {
        f32 acc = 0.0f;
        f32 v;

        acc += kernel[0] * tile[0x0 / 4];
        acc += kernel[1] * tile[0x180 / 4];
        acc += kernel[2] * tile[0x200 / 4];
        acc += kernel[3] * tile[0x380 / 4];
        acc += kernel[4] * tile[0x400 / 4];
        acc += kernel[5] * tile[0x580 / 4];
        acc += kernel[6] * tile[0x600 / 4];
        acc += kernel[7] * tile[-0x880 / 4];
        acc += kernel[8] * tile[-0x800 / 4];
        acc += kernel[9] * tile[-0x680 / 4];
        acc += kernel[10] * tile[-0x600 / 4];
        acc += kernel[11] * tile[-0x480 / 4];
        acc += kernel[12] * tile[-0x400 / 4];
        acc += kernel[13] * tile[-0x280 / 4];
        acc += kernel[14] * tile[-0x200 / 4];
        acc += kernel[15] * tile[-0x80 / 4];

        kernel += 16;
        tile++;

        if (acc > 2147483648.0f) {
            v = 2147483648.0f;
        } else if (acc < -2147483648.0f) {
            v = -2147483648.0f;
        } else {
            v = acc;
        }

        *out++ = (f32)((s32)v >> 16);
    } while (--n);
}

/* --- dol/fn_80052DD0.c --- */
void fn_80052DD0(f32 *tile, f32 *kernel, s16 *out) {
    s32 n = 32;

    do {
        f32 acc = 0.0f;
        f32 v;

        acc += kernel[0] * tile[0x0 / 4];
        acc += kernel[1] * tile[0x180 / 4];
        acc += kernel[2] * tile[0x200 / 4];
        acc += kernel[3] * tile[0x380 / 4];
        acc += kernel[4] * tile[0x400 / 4];
        acc += kernel[5] * tile[0x580 / 4];
        acc += kernel[6] * tile[0x600 / 4];
        acc += kernel[7] * tile[0x780 / 4];
        acc += kernel[8] * tile[-0x800 / 4];
        acc += kernel[9] * tile[-0x680 / 4];
        acc += kernel[10] * tile[-0x600 / 4];
        acc += kernel[11] * tile[-0x480 / 4];
        acc += kernel[12] * tile[-0x400 / 4];
        acc += kernel[13] * tile[-0x280 / 4];
        acc += kernel[14] * tile[-0x200 / 4];
        acc += kernel[15] * tile[-0x80 / 4];

        kernel += 16;
        tile++;

        if (acc > 2147483648.0f) {
            v = 2147483648.0f;
        } else if (acc < -2147483648.0f) {
            v = -2147483648.0f;
        } else {
            v = acc;
        }

        *out++ = (f32)((s32)v >> 16);
    } while (--n);
}

/* --- dol/fn_80052F30.c --- */
void fn_80052F30(f32 *tile, f32 *kernel, s16 *out) {
    s32 n = 32;

    do {
        f32 acc = 0.0f;
        f32 v;

        acc += kernel[0] * tile[0x0 / 4];
        acc += kernel[1] * tile[0x180 / 4];
        acc += kernel[2] * tile[0x200 / 4];
        acc += kernel[3] * tile[0x380 / 4];
        acc += kernel[4] * tile[0x400 / 4];
        acc += kernel[5] * tile[0x580 / 4];
        acc += kernel[6] * tile[0x600 / 4];
        acc += kernel[7] * tile[0x780 / 4];
        acc += kernel[8] * tile[0x800 / 4];
        acc += kernel[9] * tile[-0x680 / 4];
        acc += kernel[10] * tile[-0x600 / 4];
        acc += kernel[11] * tile[-0x480 / 4];
        acc += kernel[12] * tile[-0x400 / 4];
        acc += kernel[13] * tile[-0x280 / 4];
        acc += kernel[14] * tile[-0x200 / 4];
        acc += kernel[15] * tile[-0x80 / 4];

        kernel += 16;
        tile++;

        if (acc > 2147483648.0f) {
            v = 2147483648.0f;
        } else if (acc < -2147483648.0f) {
            v = -2147483648.0f;
        } else {
            v = acc;
        }

        *out++ = (f32)((s32)v >> 16);
    } while (--n);
}

/* --- dol/fn_80053090.c --- */
/* --- dol/fn_80053090.c --- */
void fn_80053090(f32 *tile, f32 *kernel, s16 *out) {
    s32 n = 32;

    do {
        f32 acc = 0.0f;
        f32 v;

        acc += kernel[0] * tile[0x0 / 4];
        acc += kernel[1] * tile[0x180 / 4];
        acc += kernel[2] * tile[0x200 / 4];
        acc += kernel[3] * tile[0x380 / 4];
        acc += kernel[4] * tile[0x400 / 4];
        acc += kernel[5] * tile[0x580 / 4];
        acc += kernel[6] * tile[0x600 / 4];
        acc += kernel[7] * tile[0x780 / 4];
        acc += kernel[8] * tile[0x800 / 4];
        acc += kernel[9] * tile[0x980 / 4];
        acc += kernel[10] * tile[-0x600 / 4];
        acc += kernel[11] * tile[-0x480 / 4];
        acc += kernel[12] * tile[-0x400 / 4];
        acc += kernel[13] * tile[-0x280 / 4];
        acc += kernel[14] * tile[-0x200 / 4];
        acc += kernel[15] * tile[-0x80 / 4];

        kernel += 16;
        tile++;

        if (acc > 2147483648.0f) {
            v = 2147483648.0f;
        } else if (acc < -2147483648.0f) {
            v = -2147483648.0f;
        } else {
            v = acc;
        }

        *out++ = (f32)((s32)v >> 16);
    } while (--n);
}

/* --- dol/fn_800531F0.c --- */
void fn_800531F0(f32 *tile, f32 *kernel, s16 *out) {
    s32 n = 32;

    do {
        f32 acc = 0.0f;
        f32 v;

        acc += kernel[0] * tile[0x0 / 4];
        acc += kernel[1] * tile[0x180 / 4];
        acc += kernel[2] * tile[0x200 / 4];
        acc += kernel[3] * tile[0x380 / 4];
        acc += kernel[4] * tile[0x400 / 4];
        acc += kernel[5] * tile[0x580 / 4];
        acc += kernel[6] * tile[0x600 / 4];
        acc += kernel[7] * tile[0x780 / 4];
        acc += kernel[8] * tile[0x800 / 4];
        acc += kernel[9] * tile[0x980 / 4];
        acc += kernel[10] * tile[0xa00 / 4];
        acc += kernel[11] * tile[-0x480 / 4];
        acc += kernel[12] * tile[-0x400 / 4];
        acc += kernel[13] * tile[-0x280 / 4];
        acc += kernel[14] * tile[-0x200 / 4];
        acc += kernel[15] * tile[-0x80 / 4];

        kernel += 16;
        tile++;

        if (acc > 2147483648.0f) {
            v = 2147483648.0f;
        } else if (acc < -2147483648.0f) {
            v = -2147483648.0f;
        } else {
            v = acc;
        }

        *out++ = (f32)((s32)v >> 16);
    } while (--n);
}

/* --- dol/fn_80053350.c --- */
void fn_80053350(f32 *tile, f32 *kernel, s16 *out) {
    s32 n = 32;

    do {
        f32 acc = 0.0f;
        f32 v;

        acc += kernel[0] * tile[0x0 / 4];
        acc += kernel[1] * tile[0x180 / 4];
        acc += kernel[2] * tile[0x200 / 4];
        acc += kernel[3] * tile[0x380 / 4];
        acc += kernel[4] * tile[0x400 / 4];
        acc += kernel[5] * tile[0x580 / 4];
        acc += kernel[6] * tile[0x600 / 4];
        acc += kernel[7] * tile[0x780 / 4];
        acc += kernel[8] * tile[0x800 / 4];
        acc += kernel[9] * tile[0x980 / 4];
        acc += kernel[10] * tile[0xa00 / 4];
        acc += kernel[11] * tile[0xb80 / 4];
        acc += kernel[12] * tile[-0x400 / 4];
        acc += kernel[13] * tile[-0x280 / 4];
        acc += kernel[14] * tile[-0x200 / 4];
        acc += kernel[15] * tile[-0x80 / 4];

        kernel += 16;
        tile++;

        if (acc > 2147483648.0f) {
            v = 2147483648.0f;
        } else if (acc < -2147483648.0f) {
            v = -2147483648.0f;
        } else {
            v = acc;
        }

        *out++ = (f32)((s32)v >> 16);
    } while (--n);
}

/* --- dol/fn_800534B0.c --- */
void fn_800534B0(f32 *tile, f32 *kernel, s16 *out) {
    s32 n = 32;

    do {
        f32 acc = 0.0f;
        f32 v;

        acc += kernel[0] * tile[0x0 / 4];
        acc += kernel[1] * tile[0x180 / 4];
        acc += kernel[2] * tile[0x200 / 4];
        acc += kernel[3] * tile[0x380 / 4];
        acc += kernel[4] * tile[0x400 / 4];
        acc += kernel[5] * tile[0x580 / 4];
        acc += kernel[6] * tile[0x600 / 4];
        acc += kernel[7] * tile[0x780 / 4];
        acc += kernel[8] * tile[0x800 / 4];
        acc += kernel[9] * tile[0x980 / 4];
        acc += kernel[10] * tile[0xa00 / 4];
        acc += kernel[11] * tile[0xb80 / 4];
        acc += kernel[12] * tile[0xc00 / 4];
        acc += kernel[13] * tile[-0x280 / 4];
        acc += kernel[14] * tile[-0x200 / 4];
        acc += kernel[15] * tile[-0x80 / 4];

        kernel += 16;
        tile++;

        if (acc > 2147483648.0f) {
            v = 2147483648.0f;
        } else if (acc < -2147483648.0f) {
            v = -2147483648.0f;
        } else {
            v = acc;
        }

        *out++ = (f32)((s32)v >> 16);
    } while (--n);
}

/* --- dol/fn_80053610.c --- */
void fn_80053610(f32 *tile, f32 *kernel, s16 *out) {
    s32 n = 32;

    do {
        f32 acc = 0.0f;
        f32 v;

        acc += kernel[0] * tile[0x0 / 4];
        acc += kernel[1] * tile[0x180 / 4];
        acc += kernel[2] * tile[0x200 / 4];
        acc += kernel[3] * tile[0x380 / 4];
        acc += kernel[4] * tile[0x400 / 4];
        acc += kernel[5] * tile[0x580 / 4];
        acc += kernel[6] * tile[0x600 / 4];
        acc += kernel[7] * tile[0x780 / 4];
        acc += kernel[8] * tile[0x800 / 4];
        acc += kernel[9] * tile[0x980 / 4];
        acc += kernel[10] * tile[0xa00 / 4];
        acc += kernel[11] * tile[0xb80 / 4];
        acc += kernel[12] * tile[0xc00 / 4];
        acc += kernel[13] * tile[0xd80 / 4];
        acc += kernel[14] * tile[-0x200 / 4];
        acc += kernel[15] * tile[-0x80 / 4];

        kernel += 16;
        tile++;

        if (acc > 2147483648.0f) {
            v = 2147483648.0f;
        } else if (acc < -2147483648.0f) {
            v = -2147483648.0f;
        } else {
            v = acc;
        }

        *out++ = (f32)((s32)v >> 16);
    } while (--n);
}

/* --- dol/fn_80053770.c --- */
void fn_80053770(f32 *tile, f32 *kernel, s16 *out) {
    s32 n = 32;

    do {
        f32 acc = 0.0f;
        f32 v;

        acc += kernel[0] * tile[0x0 / 4];
        acc += kernel[1] * tile[0x180 / 4];
        acc += kernel[2] * tile[0x200 / 4];
        acc += kernel[3] * tile[0x380 / 4];
        acc += kernel[4] * tile[0x400 / 4];
        acc += kernel[5] * tile[0x580 / 4];
        acc += kernel[6] * tile[0x600 / 4];
        acc += kernel[7] * tile[0x780 / 4];
        acc += kernel[8] * tile[0x800 / 4];
        acc += kernel[9] * tile[0x980 / 4];
        acc += kernel[10] * tile[0xa00 / 4];
        acc += kernel[11] * tile[0xb80 / 4];
        acc += kernel[12] * tile[0xc00 / 4];
        acc += kernel[13] * tile[0xd80 / 4];
        acc += kernel[14] * tile[0xe00 / 4];
        acc += kernel[15] * tile[-0x80 / 4];

        kernel += 16;
        tile++;

        if (acc > 2147483648.0f) {
            v = 2147483648.0f;
        } else if (acc < -2147483648.0f) {
            v = -2147483648.0f;
        } else {
            v = acc;
        }

        *out++ = (f32)((s32)v >> 16);
    } while (--n);
}

/* --- dol/fn_800538D0.c --- */
void fn_800538D0(f32 *tile, f32 *kernel, s16 *out) {
    s32 n = 32;

    do {
        f32 acc = 0.0f;
        f32 v;

        acc += kernel[0] * tile[0x0 / 4];
        acc += kernel[1] * tile[0x180 / 4];
        acc += kernel[2] * tile[0x200 / 4];
        acc += kernel[3] * tile[0x380 / 4];
        acc += kernel[4] * tile[0x400 / 4];
        acc += kernel[5] * tile[0x580 / 4];
        acc += kernel[6] * tile[0x600 / 4];
        acc += kernel[7] * tile[0x780 / 4];
        acc += kernel[8] * tile[0x800 / 4];
        acc += kernel[9] * tile[0x980 / 4];
        acc += kernel[10] * tile[0xa00 / 4];
        acc += kernel[11] * tile[0xb80 / 4];
        acc += kernel[12] * tile[0xc00 / 4];
        acc += kernel[13] * tile[0xd80 / 4];
        acc += kernel[14] * tile[0xe00 / 4];
        acc += kernel[15] * tile[0xf80 / 4];

        kernel += 16;
        tile++;

        if (acc > 2147483648.0f) {
            v = 2147483648.0f;
        } else if (acc < -2147483648.0f) {
            v = -2147483648.0f;
        } else {
            v = acc;
        }

        *out++ = (f32)((s32)v >> 16);
    } while (--n);
}

/* --- dol/fn_80053A30.c --- */
/* --- dol/fn_80053A30.c --- */
// fn_80053A30: returns a constant.
int fn_80053A30(void) {
    return 0;
}

/* --- dol/fn_80053A38.c --- */
extern void *memset(void *dst, int value, u32 size);
extern u32 lbl_80187380[16];

struct fn_80053A38_Arg0 {
    u8 pad_0[1];
    s8 unk_1;
};

void fn_80053A38(struct fn_80053A38_Arg0 *arg0) {
    s32 index;
    index = arg0->unk_1;
    memset(arg0, 0, 0x2014);
    lbl_80187380[index] = 0;
}
