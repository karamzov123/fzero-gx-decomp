#include "types.h"
#include <types.h>


/* --- dol/fn_8008580C.c --- */
/* --- dol/fn_8008580C.c --- */
/* --- dol/fn_8008580C.c --- */
// fn_8008580C: returns a constant.
int fn_8008580C(void) {
    return 0;
}

/* --- dol/fn_80085814.c --- */
extern u32 OSGetConsoleType(void *arg);
extern s32 lbl_801A6DE8;
extern s32 InitializeUART(u32 arg);
extern s32 WriteUARTN(void *arg0, u32 arg1);
extern void fn_8008DC10(void *arg0, void *arg1, u32 *arg2, void *arg3);

s32 fn_80085814(void *arg0, void *arg1, u32 *arg2, void *arg3) {
    u32 flags = OSGetConsoleType(arg0);
    if ((flags & 0x20000000) == 0) {
        s32 result = 0;
        if (lbl_801A6DE8 == 0) {
            result = InitializeUART(0xE100);
            if (result == 0) {
                lbl_801A6DE8 = 1;
            }
        }
        if (result != 0) {
            return 1;
        }
        if (WriteUARTN(arg1, *arg2) != 0) {
            *arg2 = 0;
            return 1;
        }
    }

    fn_8008DC10(arg0, arg1, arg2, arg3);
    return 0;
}

/* --- dol/wchar_io.c --- */
typedef unsigned long __file_handle;

typedef unsigned long fpos_t;

typedef unsigned short wchar_t;

enum __file_kinds {
    __closed_file,
    __disk_file,
    __console_file,
    __unavailable_file,
};

enum __file_orientation {
    UNORIENTED,
    CHAR_ORIENTED,
    WIDE_ORIENTED,
};

typedef struct _file_modes {
    unsigned int open_mode : 2;
    unsigned int io_mode : 3;
    unsigned int buffer_mode : 2;
    unsigned int file_kind : 3;
    unsigned int file_orientation : 2;
    unsigned int binary_io : 1;
} file_modes;

typedef struct _file_states {
    unsigned int io_state : 3;
    unsigned int free_buffer : 1;
    unsigned char eof;
    unsigned char error;
} file_states;

typedef void (*__idle_proc)(void);

typedef int (*__pos_proc)(__file_handle file, fpos_t *position, int mode, __idle_proc idle_proc);

typedef int (*__io_proc)(__file_handle file, unsigned char *buff, size_t *count,
                         __idle_proc idle_proc);

typedef int (*__close_proc)(__file_handle file);

typedef struct _FILE {
    __file_handle handle;
    file_modes file_mode;
    file_states file_state;
    unsigned char is_dynamically_allocated;
    char char_buffer;
    char char_buffer_overflow;
    char ungetc_buffer[2];
    wchar_t ungetc_wide_buffer[2];
    unsigned long position;
    unsigned char *buffer;
    unsigned long buffer_size;
    unsigned char *buffer_ptr;
    unsigned long buffer_length;
    unsigned long buffer_alignment;
    unsigned long save_buffer_length;
    unsigned long buffer_position;
    __pos_proc position_fn;
    __io_proc read_fn;
    __io_proc write_fn;
    __close_proc close_fn;
    __idle_proc idle_fn;
    struct _FILE *next_file;
} FILE;

int fwide(FILE *file, int mode);

int fwide(FILE *file, int mode) {
    if (file == 0 || file->file_mode.file_kind == __closed_file) {
        return 0;
    }
    switch (file->file_mode.file_orientation) {
    case UNORIENTED:
        if (mode > 0) {
            file->file_mode.file_orientation = WIDE_ORIENTED;
        } else if (mode < 0) {
            file->file_mode.file_orientation = CHAR_ORIENTED;
        }
        return mode;
    case WIDE_ORIENTED:
        return 1;
    case CHAR_ORIENTED:
        return -1;
    }
}

/* --- dol/fn_8008596C.c --- */
/* MSL __float_nan / __float_huge */
extern unsigned long lbl_801A6648[];
extern unsigned long lbl_801A664C[];

#define NAN (*(float *)lbl_801A6648)
#define INFINITY (*(float *)lbl_801A664C)

static const double one = 1.00000000000000000000e+00;
static const double pi = 3.14159265358979311600e+00;
static const double pio2_hi = 1.57079632679489655800e+00;
static const double pio2_lo = 6.12323399573676603587e-17;
static const double pS0 = 1.66666666666666657415e-01;
static const double pS1 = -3.25565818622400915405e-01;
static const double pS2 = 2.01212532134862925881e-01;
static const double pS3 = -4.00555345006794114027e-02;
static const double pS4 = 7.91534994289814532176e-04;
static const double pS5 = 3.47933107596021167570e-05;
static const double qS1 = -2.40339491173441421878e+00;
static const double qS2 = 2.02094576023350569471e+00;
static const double qS3 = -6.88283971605453293030e-01;
static const double qS4 = 7.70381505559019352791e-02;

static inline double sqrt(double x) {
    if (x > 0.0) {
        double guess = __frsqrte(x);
        guess = .5 * guess * (3.0 - guess * guess * x);
        guess = .5 * guess * (3.0 - guess * guess * x);
        guess = .5 * guess * (3.0 - guess * guess * x);
        guess = .5 * guess * (3.0 - guess * guess * x);
        return x * guess;
    } else if (x == 0) {
        return 0;
    } else if (x) {
        return NAN;
    }
    return INFINITY;
}

double fn_8008596C(double x) {
    double z;
    double p;
    double q;
    double r;
    double w;
    double s;
    double c;
    double df;
    int hx;
    int ix;
    hx = *(int *)&x;
    ix = hx & 0x7fffffff;
    if (ix >= 0x3ff00000) {
        if (((ix - 0x3ff00000) | *(1 + (int *)&x)) == 0) {
            if (hx > 0)
                return 0.0;
            else
                return pi + 2.0 * pio2_lo;
        }
        return NAN;
    }
    if (ix < 0x3fe00000) {
        if (ix <= 0x3c600000)
            return pio2_hi + pio2_lo;
        z = x * x;
        p = z * (pS0 + z * (pS1 + z * (pS2 + z * (pS3 + z * (pS4 + z * pS5)))));
        q = one + z * (qS1 + z * (qS2 + z * (qS3 + z * qS4)));
        r = p / q;
        return pio2_hi - (x - (pio2_lo - x * r));
    } else if (hx < 0) {
        z = (one + x) * 0.5;
        p = z * (pS0 + z * (pS1 + z * (pS2 + z * (pS3 + z * (pS4 + z * pS5)))));
        q = one + z * (qS1 + z * (qS2 + z * (qS3 + z * qS4)));
        s = sqrt(z);
        r = p / q;
        w = r * s - pio2_lo;
        return pi - 2.0 * (s + w);
    } else {
        z = (one - x) * 0.5;
        s = sqrt(z);
        df = s;
        *(1 + (int *)&df) = 0;
        c = (z - df * df) / (s + df);
        p = z * (pS0 + z * (pS1 + z * (pS2 + z * (pS3 + z * (pS4 + z * pS5)))));
        q = one + z * (qS1 + z * (qS2 + z * (qS3 + z * qS4)));
        r = p / q;
        w = r * s + c;
        return 2.0 * (df + w);
    }
}
