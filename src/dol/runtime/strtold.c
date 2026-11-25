#include "msl/decimal.h"

struct lconv {
    char *decimal_point;
    char *thousands_sep;
    char *grouping;
    char *mon_decimal_point;
    char *mon_thousands_sep;
    char *mon_grouping;
    char *positive_sign;
    char *negative_sign;
    char *currency_symbol;
    char frac_digits;
    char p_cs_precedes;
    char n_cs_precedes;
    char p_sep_by_space;
    char n_sep_by_space;
    char p_sign_posn;
    char n_sign_posn;
    char *int_curr_symbol;
    char int_frac_digits;
    char int_p_cs_precedes;
    char int_n_cs_precedes;
    char int_p_sep_by_space;
    char int_n_sep_by_space;
    char int_p_sign_posn;
    char int_n_sign_posn;
};

typedef char LConvSizeCheck[sizeof(struct lconv) == 0x38 ? 1 : -1];

enum __ReadProcActions {
    __GetAChar,
    __UngetAChar,
    __TestForError,
};

enum scan_states {
    start = 0x0001,
    sig_start = 0x0002,
    leading_sig_zeroes = 0x0004,
    int_digit_loop = 0x0008,
    frac_start = 0x0010,
    frac_digit_loop = 0x0020,
    sig_end = 0x0040,
    exp_start = 0x0080,
    leading_exp_digit = 0x0100,
    leading_exp_zeroes = 0x0200,
    exp_digit_loop = 0x0400,
    finished = 0x0800,
    failure = 0x1000,
    nan_state = 0x2000,
    infin_state = 0x4000,
    hex_state = 0x8000
};

enum hex_scan_states {
    not_hex = 0x0000,
    hex_start = 0x0001,
    hex_leading_sig_zeroes = 0x0002,
    hex_int_digit_loop = 0x0004,
    hex_frac_digit_loop = 0x0008,
    hex_sig_end = 0x0010,
    hex_exp_start = 0x0020,
    hex_leading_exp_digit = 0x0040,
    hex_leading_exp_zeroes = 0x0080,
    hex_exp_digit_loop = 0x0100
};

extern f64 lbl_801A6650[];
extern f64 lbl_801A6658[];
extern f64 lbl_801A74F8;
extern u32 lbl_801A6DE0[2];
extern int __StringRead(void *, int, int);

extern double exp(double);
extern int lbl_801A664C[];
extern f64 fn_8007B338(const decimal *);
extern struct lconv lbl_8015B400;
extern unsigned char lbl_8015B100[];
extern unsigned char lbl_8015B300[];
extern unsigned long lbl_801A6648[];
extern unsigned long lbl_801A6660[];
extern unsigned long lbl_801A6668[];
extern unsigned long lbl_801A6670[];

long double fn_80083F10(int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg,
                        int *chars_scanned, int *overflow);

void fn_80083E84(u32 arg0);
long double fn_80083F10(int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg, int *chars_scanned, int *overflow);

long double fn_80083F10(int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg,
                        int *chars_scanned, int *overflow) {
    int scan_state = start;
    int hex_scan_state = not_hex;
    int count = 0;
    int spaces = 0;
    int c;
    decimal d = {0, 0, 0, {0, ""}};
    int sig_negative = 0;
    int exp_negative = 0;
    long exp_value = 0;
    int exp_adjust = 0;
    long double result;
    int sign_detected = 0;
    unsigned char *chptr = (unsigned char *)&result;
    unsigned char uch, uch1;
    int ui;
    int chindex;
    int NibbleIndex;
    int expsign = 0;
    int exp_digits = 0;
    int intdigits = 0;
    int RadixPointFound = 0;
    short exponent = 0;
    int dot;
    dot = *(unsigned char *)(lbl_8015B400).decimal_point;
    *overflow = 0;
    c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
    while (count <= max_width && c != -1 && !(scan_state & (finished | failure))) {
        switch (scan_state) {
        case start:
            if (isspace(c)) {
                c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
                count--;
                spaces++;
                break;
            }
            switch (toupper(c)) {
            case '-':
                sig_negative = 1;
            case '+':
                c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
                sign_detected = 1;
                break;
            case 'I':
                c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
                scan_state = infin_state;
                break;
            case 'N':
                c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
                scan_state = nan_state;
                break;
            default:
                scan_state = sig_start;
                break;
            }
            break;
        case infin_state: {
            int i = 1;
            char model[] = "INFINITY";
            while ((i < 8) && (toupper(c) == model[i])) {
                i++;
                c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
            }
            if ((i == 3) || (i == 8)) {
                if (sig_negative) {
                    result = -(*(f32 *)lbl_801A664C);
                } else {
                    result = (*(f32 *)lbl_801A664C);
                }
                *chars_scanned = spaces + i + sign_detected;
                return result;
            } else {
                scan_state = failure;
            }
            break;
        }
        case nan_state: {
            int i = 1, j = 0;
            char model[] = "NAN(";
            char nan_arg[32] = "";
            while ((i < 4) && (toupper(c) == model[i])) {
                i++;
                c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
            }
            if ((i == 3) || (i == 4)) {
                if (i == 4) {
                    while ((j < 32) && (isdigit(c) || isalpha(c))) {
                        nan_arg[j++] = c;
                        c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
                    }
                    if (c != ')') {
                        scan_state = failure;
                        break;
                    } else {
                        j++;
                    }
                }
                nan_arg[j] = '\0';
                if (sig_negative) {
                    result = -(*(float *)lbl_801A6648);
                } else {
                    result = (*(float *)lbl_801A6648);
                }
                *chars_scanned = spaces + i + j + sign_detected;
                return result;
            } else {
                scan_state = failure;
            }
            break;
        }
        case sig_start:
            if (c == dot) {
                scan_state = frac_start;
                c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
                break;
            }
            if (!isdigit(c)) {
                scan_state = failure;
                break;
            }
            if (c == '0') {
                c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
                if (toupper(c) == 'X') {
                    scan_state = hex_state;
                    hex_scan_state = hex_start;
                } else {
                    scan_state = leading_sig_zeroes;
                }
                break;
            }
            scan_state = int_digit_loop;
            break;
        case leading_sig_zeroes:
            if (c == '0') {
                c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
                break;
            }
            scan_state = int_digit_loop;
            break;
        case int_digit_loop:
            if (!isdigit(c)) {
                if (c == dot) {
                    scan_state = frac_digit_loop;
                    c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
                } else {
                    scan_state = sig_end;
                }
                break;
            }
            if (d.sig.length < 20) {
                d.sig.text[d.sig.length++] = c;
            } else {
                exp_adjust++;
            }
            c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
            break;
        case frac_start:
            if (!isdigit(c)) {
                scan_state = failure;
                break;
            }
            scan_state = frac_digit_loop;
            break;
        case frac_digit_loop:
            if (!isdigit(c)) {
                scan_state = sig_end;
                break;
            }
            if (d.sig.length < 20) {
                if (c != '0' || d.sig.length) {
                    d.sig.text[d.sig.length++] = c;
                }
                exp_adjust--;
            }
            c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
            break;
        case sig_end:
            if (toupper(c) == 'E') {
                scan_state = exp_start;
                c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
                break;
            }
            scan_state = finished;
            break;
        case exp_start:
            if (c == '+') {
                c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
            } else if (c == '-') {
                c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
                exp_negative = 1;
            }
            scan_state = leading_exp_digit;
            break;
        case leading_exp_digit:
            if (!isdigit(c)) {
                scan_state = failure;
                break;
            }
            if (c == '0') {
                scan_state = leading_exp_zeroes;
                c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
                break;
            }
            scan_state = exp_digit_loop;
            break;
        case leading_exp_zeroes:
            if (c == '0') {
                c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
                break;
            }
            scan_state = exp_digit_loop;
            break;
        case exp_digit_loop:
            if (!isdigit(c)) {
                scan_state = finished;
                break;
            }
            exp_value = exp_value * 10 + (c - '0');
            if (exp_value > 32767) {
                *overflow = 1;
            }
            c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
            break;
        case hex_state: {
            switch (hex_scan_state) {
            case hex_start:
                for (chindex = 0; chindex < 8; chindex++) {
                    *(chptr + chindex) = '\0';
                }
                NibbleIndex = 2;
                hex_scan_state = hex_leading_sig_zeroes;
                c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
                break;
            case hex_leading_sig_zeroes:
                if (c == '0') {
                    c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
                    break;
                }
                hex_scan_state = hex_int_digit_loop;
                break;
            case hex_int_digit_loop:
                if (!isxdigit(c)) {
                    if (c == dot) {
                        hex_scan_state = hex_frac_digit_loop;
                        c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
                    } else {
                        hex_scan_state = hex_sig_end;
                    }
                    break;
                }
                if (NibbleIndex < 17) {
                    intdigits++;
                    uch = *(chptr + NibbleIndex / 2);
                    ui = toupper(c);
                    if (ui >= 'A') {
                        ui = ui - 'A' + 10;
                    } else {
                        ui -= '0';
                    }
                    uch1 = ui;
                    if ((NibbleIndex % 2) != 0) {
                        uch |= uch1;
                    } else {
                        uch |= uch1 << 4;
                    }
                    *(chptr + NibbleIndex++ / 2) = uch;
                    c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
                } else {
                    c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
                }
                break;
            case hex_frac_digit_loop:
                if (!isxdigit(c)) {
                    hex_scan_state = hex_sig_end;
                    break;
                }
                if (NibbleIndex < 17) {
                    uch = *(chptr + NibbleIndex / 2);
                    ui = toupper(c);
                    if (ui >= 'A') {
                        ui = ui - 'A' + 10;
                    } else {
                        ui -= '0';
                    }
                    uch1 = ui;
                    if ((NibbleIndex % 2) != 0) {
                        uch |= uch1;
                    } else {
                        uch |= uch1 << 4;
                    }
                    *(chptr + NibbleIndex++ / 2) = uch;
                    c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
                } else {
                    c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
                }
                break;
            case hex_sig_end:
                if (toupper(c) == 'P') {
                    hex_scan_state = hex_exp_start;
                    exp_digits++;
                    c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
                } else {
                    scan_state = finished;
                }
                break;
            case hex_exp_start:
                exp_digits++;
                if (c == '-') {
                    expsign = 1;
                } else if (c != '+') {
                    c = (*ReadProc)(ReadProcArg, c, __UngetAChar);
                    exp_digits--;
                }
                hex_scan_state = hex_leading_exp_digit;
                c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
                break;
            case hex_leading_exp_digit:
                if (!isdigit(c)) {
                    scan_state = failure;
                    break;
                }
                if (c == '0') {
                    exp_digits++;
                    hex_scan_state = hex_leading_exp_zeroes;
                    c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
                    break;
                }
                hex_scan_state = hex_exp_digit_loop;
                break;
            case hex_exp_digit_loop:
                if (!isdigit(c)) {
                    scan_state = finished;
                    break;
                }
                exponent = exponent * 10 + (c - '0');
                if (exp_value > 32767) {
                    *overflow = 1;
                }
                exp_digits++;
                c = (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar));
                break;
            }
        } break;
        }
    }
    if (!(scan_state & (leading_sig_zeroes | int_digit_loop | frac_digit_loop | leading_exp_zeroes |
                        exp_digit_loop | finished))) {
        count = 0;
        *chars_scanned = 0;
    } else {
        count--;
        *chars_scanned = count + spaces;
    }
    (*ReadProc)(ReadProcArg, c, __UngetAChar);
    if (hex_scan_state == not_hex) {
        if (exp_negative) {
            exp_value = -exp_value;
        }
        {
            int n = d.sig.length;
            unsigned char *p = &d.sig.text[n];
            while (n-- && *--p == '0') {
                exp_adjust++;
            }
            d.sig.length = n + 1;
            if (d.sig.length == 0) {
                d.sig.text[d.sig.length++] = '0';
            }
        }
        exp_value += exp_adjust;
        if (exp_value < (-32768) || exp_value > 32767) {
            *overflow = 1;
        }
        if (*overflow) {
            if (exp_negative) {
                return 0.0;
            } else {
                return sig_negative ? -(*(double *)lbl_801A6660) : (*(double *)lbl_801A6660);
            }
        }
        d.exp = exp_value;
        result = fn_8007B338(&d);
        if (result != 0.0 && result < (*(double *)lbl_801A6668)) {
            *overflow = 1;
        } else if (result > (*(double *)lbl_801A6670)) {
            *overflow = 1;
            result = (*(double *)lbl_801A6660);
        }
        if (sig_negative && (scan_state & (leading_sig_zeroes | int_digit_loop | frac_digit_loop |
                                           leading_exp_zeroes | exp_digit_loop | finished))) {
            result = -result;
        }
        return result;
    } else {
        unsigned long long *uptr = (unsigned long long *)&result;
        if (result) {
            if (expsign) {
                exponent = -exponent;
            }
            while ((*(short *)(&result) & 0x00f0) != 0x0010) {
                *uptr >>= 1;
                exponent++;
            }
            exponent += 4 * (intdigits - 1);
            *(short *)&result &= 0x000f;
            *(short *)(&result) |= ((exponent + 1023) << 4);
            *chars_scanned = spaces + sign_detected + NibbleIndex + 1 + exp_digits;
            if (result != 0.0 && result < (*(double *)lbl_801A6668)) {
                *overflow = 1;
                result = 0.0;
            } else if (result > (*(double *)lbl_801A6670)) {
                *overflow = 1;
                result = (*(double *)lbl_801A6660);
            }
            if (sig_negative) {
                *(short *)(&result) |= 0x8000;
            }
        } else {
            result = 0.0;
        }
        return result;
    }
}

void fn_80083E84(u32 arg0) {
    struct {
        u32 a[2];
    } loc_10;
    int loc_C;
    int loc_8;
    f64 value;
    f64 abs_value;

    loc_10.a[0] = arg0;
    loc_10.a[1] = 0;
    value = fn_80083F10((0x80000000 - 1), __StringRead, &loc_10, &loc_8, &loc_C);
    abs_value = __fabs(value);
    if (loc_C != 0 || (lbl_801A74F8 != value && (abs_value < lbl_801A6650[0] || abs_value > lbl_801A6658[0]))) {
        lbl_801A6DE0[0] = 34;
    }
}

static inline int toupper(int c) { return c == -1 ? -1 : (int)lbl_8015B300[(unsigned char)c]; }

static inline int isxdigit(int c) { return (int)(lbl_8015B100[(unsigned char)c] & 0x20); }

static inline int isspace(int c) { return (int)(lbl_8015B100[(unsigned char)c] & (0x02 | 0x04)); }

static inline int isdigit(int c) { return (int)(lbl_8015B100[(unsigned char)c] & 0x10); }

static inline int isalpha(int c) { return (int)(lbl_8015B100[(unsigned char)c] & (0x40 | 0x80)); }
