#include "types.h"
#include "msl/decimal_internal.h"


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

s32 fn_8007B0B4(void) {
    s32 result;
    FileEntry *entry;

    result = 0;
    entry = (FileEntry *)&__files;
    while (entry != 0) {
        if (((entry->unk04 >> 6) & 7) != 0) {
            if (fflush(entry) != 0) {
                result = -1;
            }
        }
        entry = entry->next;
    }
    return result;
}

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

void __close_all(void) {
    File *file;

    file = (File *)&__files;
    __begin_critical_region(2);
    while (file != 0) {
        if (file->mode != 0) {
            fclose(file);
        }
        {
            File *current;
            current = file;
            file = file->next;
            if (current->in_use != 0) {
                fn_8007A150(current);
            } else {
                current->mode = 3;
                if (file != 0 && file->in_use != 0) {
                    current->next = 0;
                }
            }
        }
    }
    __end_critical_region(2);
}

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
extern s32 fn_8008D7CC(u32, u32, s32);
extern s32 fn_8008DB5C(u32, u32, u32 *);
extern s32 fn_8008DAA8(u32, u32, u32 *);
extern s32 fn_8008D8A8(u32);

void fn_8007B1CC(Sig_setvbuf_FILE *file, Sig_setvbuf_FileMode mode, char *buf, u32 size) {
    file->handle = 0;
    file->mode = mode;
    file->state.io_state = 0;
    file->state.free_buffer = 0;
    file->state.eof = 0;
    file->state.error = 0;
    file->position = 0;
    if (size != 0) {
        setvbuf(file, buf, 2, size);
    } else {
        setvbuf(file, 0, 0, 0);
    }
    file->buffer_ptr = file->buffer;
    file->buffer_length = 0;
    if (file->mode.file_kind == 1) {
        file->position_proc = fn_8008D7CC;
        file->read_proc = fn_8008DB5C;
        file->write_proc = fn_8008DAA8;
        file->close_proc = fn_8008D8A8;
    }
    file->idle_proc = 0;
}

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

u32 fn_8007B2A8(void) {
    FileNode *node;
    FileNode *new_node;
    FileNode *last;

    node = ((FileRoot *)__files)->next;
    while (node != 0) {
        if (!(((node->flags >> 6) & 7) != 0)) {
            return (u32)node;
        } else {
            last = node;
            node = node->next;
        }
    }
    new_node = (FileNode *)fn_8007A1C0(0x50);
    if (new_node != 0) {
        memset(new_node, 0, 0x50);
        new_node->active = 1;
        last->next = new_node;
        return (u32)new_node;
    }
    return 0;
}

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
        extern f64 lbl_8015AF98[8];
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
