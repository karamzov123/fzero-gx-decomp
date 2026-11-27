#include "types.h"
#include "msl/decimal_internal.h"

static f64 lbl_8015AF98[8] __attribute__((aligned(8))) = {
    10.0, 100.0, 1000.0, 10000.0, 100000.0, 1000000.0, 10000000.0, 100000000.0
};

/* --- dol/fn_8007B338.c --- */
/* --- dol/fn_8007B0B4.c --- */
/* --- dol/fn_8007B0B4.c --- */
/* --- dol/fn_8007B0B4.c --- */
typedef struct FileEntry {
    u8 pad00[4];
    u16 unk04;
    u8 pad06[0x46];
    struct FileEntry *next;
} FileEntry;

extern u8 __files[320];
extern s32 fflush(FileEntry *);

s32 fn_8007B0B4(void);

/* --- dol/__close_all.c --- */
extern u32 __begin_critical_region(u32);
extern void fclose(void *);
extern void fn_8007A150(void *);
extern u32 __end_critical_region(u32);

typedef struct File {
    u8 pad0[4];
    u16 unused0:7;
    u16 mode:3;
    u16 unused1:6;
    u8 pad6[6];
    u8 in_use;
    u8 padD[0x3f];
    struct File *next;
} File;

void __close_all(void);

/* --- dol/fn_8007B1CC.c --- */
typedef u32 Sig_setvbuf_file_handle;
typedef struct Sig_setvbuf_FileMode {
    u32 open_mode : 2;
    u32 io_mode : 3;
    u32 buffer_mode : 2;
    u32 file_kind : 3;
    u32 file_orientation : 2;
    u32 binary_io : 1;
} Sig_setvbuf_FileMode;
typedef struct Sig_setvbuf_FileState {
    u32 io_state : 3;
    u32 free_buffer : 1;
    u8 eof;
    u8 error;
} Sig_setvbuf_FileState;
typedef void (*Sig_setvbuf_IdleProc)(void);
typedef s32 (*Sig_setvbuf_PositionProc)(u32, u32, s32);
typedef s32 (*Sig_setvbuf_IOProc)(u32, u32, u32 *);
typedef s32 (*Sig_setvbuf_CloseProc)(u32);
typedef struct Sig_setvbuf_FILE {
    Sig_setvbuf_file_handle handle;
    Sig_setvbuf_FileMode mode;
    Sig_setvbuf_FileState state;
    u8 is_dynamically_allocated;
    u8 char_buffer;
    u8 char_buffer_overflow;
    u8 ungetc_buffer[2];
    u16 ungetc_wide_buffer[2];
    u32 position;
    u8 *buffer;
    u32 buffer_size;
    u8 *buffer_ptr;
    u32 buffer_length;
    u32 buffer_alignment;
    u32 saved_buffer_length;
    u32 buffer_position;
    Sig_setvbuf_PositionProc position_proc;
    Sig_setvbuf_IOProc read_proc;
    Sig_setvbuf_IOProc write_proc;
    Sig_setvbuf_CloseProc close_proc;
    Sig_setvbuf_IdleProc idle_proc;
    struct Sig_setvbuf_FILE *next_file;
} Sig_setvbuf_FILE;

extern int setvbuf(Sig_setvbuf_FILE *, char *, int, size_t);

void fn_8007B1CC(Sig_setvbuf_FILE *file, Sig_setvbuf_FileMode mode, char *buf, u32 size);

/* --- dol/fn_8007B2A8.c --- */
extern u32 fn_8007A1C0(u32);
extern void *memset(void *, u32, u32);

typedef struct FileNode {
    u8 pad0[4];
    u16 flags;
    u8 pad6[6];
    u8 active;
    u8 padd[0x3f];
    struct FileNode *next;
} FileNode;

typedef struct FileRoot {
    u8 pad0[0xec];
    FileNode *next;
} FileRoot;

u32 fn_8007B2A8(void);

/* --- dol/fn_8007B338.c --- */
f64 fn_8007B338(const decimal *d);

extern double exp(double);

extern double ldexp(double, int);

extern double fn_80088598(double, double);

extern double fn_80087E58(double, double);

extern int lbl_801A6658[];

extern int lbl_801A664C[];

static inline int __fpclassifyf(f32 x) {
    switch ((*(s32 *)&x) & 0x7F800000) {
    case 0x7F800000: {
        if ((*(s32 *)&x) & 0x007FFFFF)
            return 1;
        return 2;
    }
    case 0: {
        if ((*(s32 *)&x) & 0x007FFFFF)
            return 5;
        return 3;
    }
    }
    return 4;
}

static inline int __fpclassifyd(f64 x) {
    switch (*(int *)&x & 0x7FF00000) {
    case 0x7FF00000: {
        if ((*(int *)&x & 0x000FFFFF) || (*(1 + (int *)&x) & 0xFFFFFFFF))
            return 1;
        return 2;
    }
    case 0: {
        if ((*(int *)&x & 0x000FFFFF) || (*(1 + (int *)&x) & 0xFFFFFFFF))
            return 5;
        return 3;
    }
    }
    return 4;
}

extern unsigned char lbl_8015B100[];

extern unsigned char lbl_8015B200[];

static inline int isdigit(int c) { return (lbl_8015B100[(unsigned char)c] & 0x10); }

static inline int _tolower(int c) { return c == -1 ? -1 : lbl_8015B200[(unsigned char)c]; }

void __num2dec_internal(decimal *d, f64 x);

void fn_8007C910(decimal *z, const decimal *x, const decimal *y);

BOOL __equals_dec(const decimal *x, const decimal *y);

static inline void __str2dec(decimal *d, const char *s, s16 exp) {
    int i;
    d->exp = exp;
    d->sign = 0;
    for (i = 0; i < 36 && *s;) {
        d->sig.text[i++] = *s++ - '0';
    }
    d->sig.length = i;
    if (*s != 0) {
        const char *p;
        if (*s < 5)
            return;
        if (*s > 5)
            goto round; /* shared rounding tail; the test chain is not a loop */
        p = s + 1;
        while (*p != 0) {
            if (*p != '0')
                goto round; /* stray nonzero digit forces the rounding tail */
            p++;
        }
        if ((d->sig.text[i - 1] & 1) == 0)
            return;
    round:
        __dorounddecup(d, d->sig.length);
    }
}

static inline BOOL __less_dec(const decimal *x, const decimal *y) {
    if (x->sig.text[0] == 0) {
        if (y->sig.text[0] != 0)
            return 1;
        return 0;
    }
    if (y->sig.text[0] == 0) {
        return 0;
    }
    if (x->exp == y->exp) {
        int i;
        int l = x->sig.length;
        if (l > y->sig.length) {
            l = y->sig.length;
        }
        for (i = 0; i < l; i++) {
            if (x->sig.text[i] < y->sig.text[i]) {
                return 1;
            } else if (y->sig.text[i] < x->sig.text[i]) {
                return 0;
            }
        }
        if (l == x->sig.length) {
            for (; i < y->sig.length; i++) {
                if (y->sig.text[i] != 0) {
                    return 1;
                }
            }
        }
        return 0;
    }
    return x->exp < y->exp;
}

f64 fn_8007B338(const decimal *d) {
    if (d->sig.length <= 0) {
        return fn_80087E58(0.0, d->sign == 0 ? 1.0 : -1.0);
    }
    switch (d->sig.text[0]) {
    case '0':
        return fn_80087E58(0.0, d->sign == 0 ? 1.0 : -1.0);
    case 'I':
        return fn_80087E58((*(f32 *)lbl_801A664C), d->sign == 0 ? 1.0 : -1.0);
    case 'N': {
        f64 result;
        u64 *ll = (u64 *)&result;
        *ll = 0x7FF0000000000000;
        if (d->sign)
            *ll |= 0x8000000000000000;
        if (d->sig.length == 1)
            *ll |= 0x8000000000000;
        else {
            u8 *p = (u8 *)&result + 1;
            int placed_non_zero = 0;
            int low = 1;
            int i;
            int e = d->sig.length;
            if (e > 14)
                e = 14;
            for (i = 1; i < e; ++i) {
                u8 c = d->sig.text[i];
                if (isdigit(c)) {
                    c -= '0';
                } else {
                    c = (_tolower(c) - 'a' + 10);
                }
                if (c != 0) {
                    placed_non_zero = 1;
                }
                if (low) {
                    *p++ |= c;
                } else {
                    *p = (u8)(c << 4);
                }
                low = !low;
            }
            if (!placed_non_zero) {
                *ll |= 0x0008000000000000;
            }
        }
        return result;
    }
    }
    {

        decimal dec = *d;
        u8 *i = dec.sig.text;
        u8 *e = i + dec.sig.length;
        f64 first_guess;
        int exponent;
        for (; i < e; ++i)
            *i -= '0';
        dec.exp += dec.sig.length - 1;
        exponent = dec.exp;
        i = dec.sig.text;
        first_guess = *i++;
        while (i < e) {
            u32 ival = 0;
            int j;
            f64 temp1, temp2;
            int ndig = (e - i) % 8;
            if (ndig == 0)
                ndig = 8;
            for (j = 0; j < ndig; ++j, ++i) {
                ival = ival * 10 + *i;
            }
            temp1 = first_guess * lbl_8015AF98[ndig - 1];
            temp2 = temp1 + ival;
            if (ival != 0 && temp1 == temp2)
                break;
            first_guess = temp2;
            exponent -= ndig;
        }
        if (exponent < 0) {
            first_guess /= fn_80088598(5.0, -exponent);
        } else {
            first_guess *= fn_80088598(5.0, exponent);
        }
        first_guess = ldexp(first_guess, exponent);
        do {
            decimal max;
            decimal feedback1;
            if ((((sizeof(first_guess) == sizeof(f32)) ? __fpclassifyf(first_guess)
                                                       : __fpclassifyd(first_guess)) == 2)) {
                __str2dec(&max, "179769313486231580793729011405303420", 308);
                if (__less_dec(&max, &dec))
                    break;
                first_guess = (*(f64 *)lbl_801A6658);
            }
            __num2dec_internal(&feedback1, first_guess);
            if (__equals_dec(&feedback1, &dec))
                break;
            if (__less_dec(&feedback1, &dec)) {
                decimal feedback2, difflow, diffhigh;
                f64 next_guess = first_guess;
                u64 *ull = (u64 *)&next_guess;
                ++*ull;
                if ((((sizeof(next_guess) == sizeof(f32))
                          ? __fpclassifyf(next_guess)
                          : __fpclassifyd(next_guess)) == 2)) {
                    first_guess = next_guess;
                    break;
                }
                __num2dec_internal(&feedback2, next_guess);
                while (__less_dec(&feedback2, &dec)) {
                    feedback1 = feedback2;
                    first_guess = next_guess;
                    ++*ull;
                    if ((((sizeof(next_guess) == sizeof(f32))
                              ? __fpclassifyf(next_guess)
                              : __fpclassifyd(next_guess)) == 2)) {
                        first_guess = next_guess;
                        goto done; /* next_guess reached infinity: value settled */
                    }
                    __num2dec_internal(&feedback2, next_guess);
                }
                fn_8007C910(&difflow, &dec, &feedback1);
                fn_8007C910(&diffhigh, &feedback2, &dec);
                if (__equals_dec(&difflow, &diffhigh)) {
                    if (*(u64 *)&first_guess & 1) {
                        first_guess = next_guess;
                    }
                } else if (!__less_dec(&difflow, &diffhigh)) {
                    first_guess = next_guess;
                }
            } else {
                decimal feedback2, difflow, diffhigh;
                f64 next_guess = first_guess;
                u64 *ull = (u64 *)&next_guess;
                --*ull;
                __num2dec_internal(&feedback2, next_guess);
                while (__less_dec(&dec, &feedback2)) {
                    feedback1 = feedback2;
                    first_guess = next_guess;
                    --*ull;
                    __num2dec_internal(&feedback2, next_guess);
                }
                fn_8007C910(&difflow, &dec, &feedback2);
                fn_8007C910(&diffhigh, &feedback1, &dec);
                if (__equals_dec(&difflow, &diffhigh)) {
                    if (*(u64 *)&first_guess & 1) {
                        first_guess = next_guess;
                    }
                } else if (__less_dec(&difflow, &diffhigh)) {
                    first_guess = next_guess;
                }
            }
        } while (0);
    done:
        if (dec.sign) {
            first_guess = -first_guess;
        }
        return first_guess;
    }
}

/* --- dol/ansi_fp_decimal.c --- */
static inline int __must_round(const decimal *d, int digits) {
    u8 const *i = d->sig.text + digits;
    if (*i > 5) {
        return 1;
    }
    if (*i < 5) {
        return -1;
    }
    {
        u8 const *e = d->sig.text + d->sig.length;
        for (i++; i < e; i++) {
            if (*i != 0) {
                return 1;
            }
        }
    }
    if (d->sig.text[digits - 1] & 1) {
        return 1;
    }
    return -1;
}

static inline void __rounddec(decimal *d, int digits) {
    if (digits > 0 && digits < d->sig.length) {
        int round_direction = __must_round(d, digits);
        d->sig.length = digits;
        if (round_direction >= 0) {
            __dorounddecup(d, digits);
        }
    }
}

void __num2dec(const decform *form, f64 x, decimal *d) {
    s16 digits = form->digits;
    int i;
    __num2dec_internal(d, x);
    if (d->sig.text[0] > 9) {
        return;
    }
    if (digits > 36) {
        digits = 36;
    }
    __rounddec(d, digits);
    while (d->sig.length < digits) {
        d->sig.text[d->sig.length++] = 0;
    }
    d->exp -= d->sig.length - 1;
    for (i = 0; i < d->sig.length; i++) {
        d->sig.text[i] += '0';
    }
}

extern double frexp(double, int *);


extern double modf(double, double *);



void fn_8007CF18(decimal *result, s32 exp);

void fn_8007E69C(decimal *result, const decimal *x, const decimal *y);

static inline int __count_trailing_zerol(u32 x) {
    int result = 0;
    int bits_not_checked = sizeof(u32) * 8;
    int n = bits_not_checked / 2;
    int mask_size = n;
    u32 mask = (~0UL) >> (bits_not_checked - n);
    while (bits_not_checked) {
        if (!(x & mask)) {
            result += mask_size;
            x >>= mask_size;
            bits_not_checked -= mask_size;
        } else if (mask == 1) {
            break;
        }
        if (n > 1) {
            n /= 2;
        }
        if (mask > 1) {
            mask >>= n;
            mask_size -= n;
        }
    }
    return result;
}

static inline int __count_trailing_zero(f64 x) {
    u32 *l = (u32 *)&x;
    if (l[1] != 0) {
        return __count_trailing_zerol(l[1]);
    }
    return (int)(sizeof(u32) * 8 + __count_trailing_zerol(l[0] | 0x00100000));
}

static inline void __ull2dec(decimal *result, u64 val) {
    result->sign = 0;
    if (val == 0) {
        result->exp = 0;
        result->sig.length = 1;
        result->sig.text[0] = 0;
        return;
    }
    result->sig.length = 0;
    for (; val != 0; val /= 10) {
        result->sig.text[result->sig.length++] = (u8)(val % 10);
    }
    {
        u8 *i = result->sig.text;
        u8 *j = result->sig.text + result->sig.length;
        for (; i < --j; ++i) {
            u8 t = *i;
            *i = *j;
            *j = t;
        }
    }
    result->exp = result->sig.length - 1;
}

void __num2dec_internal(decimal *d, f64 x) {
    s8 sign = (s8)(((int)(*(int *)&x & 0x80000000)) != 0);
    if (x == 0) {
        d->sign = sign;
        d->exp = 0;
        d->sig.length = 1;
        d->sig.text[0] = 0;
        return;
    }
    if (!(((sizeof(x) == sizeof(f32)) ? __fpclassifyf((f32)(x)) : __fpclassifyd((f64)(x))) > 2)) {
        d->sign = sign;
        d->exp = 0;
        d->sig.length = 1;
        d->sig.text[0] =
            ((sizeof(x) == sizeof(f32)) ? __fpclassifyf((f32)(x)) : __fpclassifyd((f64)(x))) == 1
                ? 'N'
                : 'I';
        return;
    }
    if (sign != 0) {
        x = -x;
    }
    {
        int exp;
        f64 frac = frexp(x, &exp);
        s32 num_bits_extract = 53 - __count_trailing_zero(frac);
        f64 integer;
        decimal int_d, pow2_d;
        fn_8007CF18(&pow2_d, exp - num_bits_extract);
        modf(ldexp(frac, num_bits_extract), &integer);
        __ull2dec(&int_d, (u64)integer);
        fn_8007E69C(d, &int_d, &pow2_d);
        d->sign = sign;
    }
}


extern double jn(int, double);

void fn_8007C910(decimal *z, const decimal *x, const decimal *y) {
    int zlen, dexp;
    u8 *ib, *i, *ie;
    u8 const *jb, *j, *jn;
    {
        u32 a, b;
        const u32 *src = (const u32 *)x;
        u32 *dst = (u32 *)z;
        a = src[0];
        b = src[1];
        dst[0] = a;
        a = src[2];
        dst[1] = b;
        b = src[3];
        dst[2] = a;
        a = src[4];
        dst[3] = b;
        b = src[5];
        dst[4] = a;
        a = src[6];
        dst[5] = b;
        b = src[7];
        dst[6] = a;
        a = src[8];
        dst[7] = b;
        b = src[9];
        dst[8] = a;
        {
            u16 h = ((const u16 *)x)[20];
            dst[9] = b;
            ((u16 *)z)[20] = h;
        }
    }
    if ((*((y->sig.text) + (0))) == 0)
        return;
    zlen = z->sig.length;
    if (zlen < y->sig.length)
        zlen = y->sig.length;
    dexp = z->exp - y->exp;
    zlen += dexp;
    if (zlen > 36)
        zlen = 36;
    while (z->sig.length < zlen) {
        (*((z->sig.text) + (z->sig.length++))) = 0;
    }
    ib = z->sig.text;
    i = ib + zlen;
    if (y->sig.length + dexp < zlen) {
        i = ib + (y->sig.length + dexp);
    }
    jb = y->sig.text;
    j = jb + (i - ib - dexp);
    jn = j;
    while (i > ib && j > jb) {
        j--;
        i--;
        if (*i < *j) {
            u8 *k = i - 1;
            while (*k == 0)
                k--;
            while (k != i) {
                --*k;
                *++k += 10;
            }
        }
        *i -= *j;
    }
    if (jn - jb < y->sig.length) {
        BOOL round_down = 0;
        if (*jn < 5)
            round_down = 1;
        else if (*jn == 5) {
            u8 const *ibPtr = y->sig.text + y->sig.length;
            ibPtr = y->sig.text + y->sig.length;
            for (j = jn + 1; j < ibPtr; j++) {
                if (*j != 0)
                    goto round_done; /* 5 + trailing zeros: not a round-up case */
            }
            i = ib + (jn - jb) + dexp - 1;
            if (*i & 1)
                round_down = 1;
        }
        if (round_down) {
            if (*i < 1) {
                u8 *k = i - 1;
                while (*k == 0)
                    k--;
                while (k != i) {
                    --*k;
                    *++k += 10;
                }
            }
            *i -= 1;
        }
round_done: ;
    }
    for (i = ib; *i == 0; ++i) {
    }
    if (i > ib) {
        u8 dl = (u8)(i - ib);
        z->exp -= dl;
        ie = ib + z->sig.length;
        for (; i < ie; ++i, ++ib)
            *ib = *i;
        z->sig.length -= dl;
    }
    ib = z->sig.text;
    for (i = ib + z->sig.length; i > ib;) {
        i--;
        if (*i != 0)
            break;
    }
    z->sig.length = (u8)(i - ib + 1);
}

BOOL __equals_dec(const decimal *x, const decimal *y) {
    if (x->sig.text[0] == 0) {
        if (y->sig.text[0] == 0)
            return 1;
        return 0;
    }
    if (y->sig.text[0] == 0) {
        if (x->sig.text[0] == 0)
            return 1;
        return 0;
    }
    if (x->exp == y->exp) {
        int i;
        int l = x->sig.length;
        if (l > y->sig.length) {
            l = y->sig.length;
        }
        for (i = 0; i < l; i++) {
            if (x->sig.text[i] != y->sig.text[i]) {
                return 0;
            }
        }
        if (l == x->sig.length) {
            for (; i < y->sig.length; ++i) {
                if (y->sig.text[i] != 0) {
                    return 0;
                }
            }
        } else {
            for (; i < x->sig.length; ++i) {
                if (x->sig.text[i] != 0) {
                    return 0;
                }
            }
        }
        return 1;
    }
    return 0;
}

extern char lbl_80094ED8[];

static inline void __dec_parse(decimal *d, char *s) {
    char c;
    char *q;
    int i = 0;

    while (i < 36 && *s)
        d->sig.text[i++] = *s++ - '0';
    d->sig.length = i;
    c = *s;
    if (c == 0)
        return;
    if (c < 5)
        return;
    /* the >5 path and the 5-with-nonzero-tail path share one round-up tail */
    if (c > 5)
        goto round; /* Keep the verified branch to round. */
    for (q = s + 1; *q; q++)
        /* any nonzero digit after the 5 forces a round up */
        if (*q != '0')
            goto round; /* Keep the verified branch to round. */
    if ((d->sig.text[i - 1] & 1) == 0)
        return;
round:
    __dorounddecup(d, d->sig.length);
}

static inline void __dec_str(decimal *d, int exp, char *s) {
    d->exp = exp;
    d->sign = 0;
    __dec_parse(d, s);
}

#pragma opt_dead_assignments off
void fn_8007CF18(decimal *d, s32 n) {
    decimal tmp;
    decimal save;

    switch (n) {
    case -64:
        __dec_str(d, -20, &lbl_80094ED8[37]);
        return;
    case -53:
        __dec_str(d, -16, &lbl_80094ED8[83]);
        return;
    case -32:
        __dec_str(d, -10, &lbl_80094ED8[122]);
        return;
    case -16:
        __dec_str(d, -5, &lbl_80094ED8[146]);
        return;
    case -8:
        __dec_str(d, -3, &lbl_80094ED8[159]);
        return;
    case -7:
        __dec_str(d, -3, &lbl_80094ED8[166]);
        return;
    case -6:
        __dec_str(d, -2, &lbl_80094ED8[172]);
        return;
    case -5:
        __dec_str(d, -2, &lbl_80094ED8[178]);
        return;
    case -4:
        __dec_str(d, -2, &lbl_80094ED8[183]);
        return;
    case -3:
        __dec_str(d, -1, &lbl_80094ED8[187]);
        return;
    case -2:
        __dec_str(d, -1, &lbl_80094ED8[191]);
        return;
    case -1:
        __dec_str(d, -1, &lbl_80094ED8[194]);
        return;
    case 0:
        __dec_str(d, 0, &lbl_80094ED8[196]);
        return;
    case 1:
        __dec_str(d, 0, &lbl_80094ED8[198]);
        return;
    case 2:
        __dec_str(d, 0, &lbl_80094ED8[200]);
        return;
    case 3:
        __dec_str(d, 0, &lbl_80094ED8[202]);
        return;
    case 4:
        __dec_str(d, 1, &lbl_80094ED8[204]);
        return;
    case 5:
        __dec_str(d, 1, &lbl_80094ED8[207]);
        return;
    case 6:
        __dec_str(d, 1, &lbl_80094ED8[210]);
        return;
    case 7:
        __dec_str(d, 2, &lbl_80094ED8[213]);
        return;
    case 8:
        __dec_str(d, 2, &lbl_80094ED8[217]);
        return;
    default:
        fn_8007CF18(&tmp, n / 2);
        fn_8007E69C(d, &tmp, &tmp);
        if (((1) & n)) {
            save = *d;
            if (n > 0) {
                tmp.exp = 0;
                tmp.sign = 0;
                __dec_parse(&tmp, &"179769313486231580793729011405303420"[198]);
            } else {
                char *p;
                tmp.sign = 0;
                p = &"179769313486231580793729011405303420"[194];
                tmp.exp = -1;
                __dec_parse(&tmp, p);
            }
            fn_8007E69C(d, &save, &tmp);
        }
        return;
    }
}
#pragma opt_dead_assignments reset

/* --- dol/fn_8007E69C.c --- */
/* --- dol/fn_8007E69C.c --- */
#define SIGDIGLEN 36

/* MSL ansi_fp.c __timesdec: decimal significand multiplication with round-half-even */
void fn_8007E69C(decimal *result, const decimal *x, const decimal *y) {
    u32 accumulator = 0;
    u8 mantissa[SIGDIGLEN * 2];
    int i = x->sig.length + y->sig.length - 1;
    u8 *pDigit;
    u8 *text;
    u8 *ip = mantissa + i + 1;
    u8 *ep = ip;

    result->sign = 0;

    for (; i > 0; i--) {
        int k = y->sig.length - 1;
        int j = i - k - 1;
        int l;
        int t;
        const u8 *jp;
        const u8 *kp;

        if (j < 0) {
            j = 0;
            k = i - 1;
        }

        jp = x->sig.text + j;
        kp = y->sig.text + k;
        l = k + 1;
        t = x->sig.length - j;

        if (l > t) {
            l = t;
        }

        for (; l > 0; l--, jp++, kp--) {
            accumulator += *jp * *kp;
        }

        *--ip = (u8)(accumulator % 10);
        accumulator /= 10;
    }

    result->exp = (x->exp + y->exp);

    if (accumulator > 0) {
        *--ip = (u8)accumulator;
        result->exp++;
    }

    for (i = 0; i < SIGDIGLEN && ip < ep; i++, ip++) {
        result->sig.text[i] = *ip;
    }
    result->sig.length = i;

    if (ip < ep && *ip >= 5) {
        if (*ip == 5) {
            u8 *iq = ip + 1;

            for (; iq < ep; iq++) {
                if (*iq != 0) {
                    /* goto: MSL source shape; skips the round-half-even test into rounding */
                    goto round;
                }
            }

            if ((*(ip - 1) & 1) == 0) {
                return;
            }
        }

    round:
        text = result->sig.text;
        pDigit = text + result->sig.length - 1;

        while (1) {
            if (*pDigit < 9) {
                (*pDigit)++;
                break;
            } else if (pDigit == text) {
                *pDigit = 1;
                result->exp++;
                break;
            } else {
                *pDigit-- = 0;
            }
        }
    }
}
