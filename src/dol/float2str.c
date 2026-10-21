
#include "types.h"
#pragma pool_strings on

typedef struct decimal {
    char sign;
    char reserved;
    s16 exp;
    struct {
        u8 length;
        u8 text[36];
        u8 reserved;
    } sig;
} decimal;

typedef struct decform {
    char style;
    char reserved;
    s16 digits;
} decform;

enum justification_options { left_justification, right_justification, zero_fill };

enum sign_options { only_minus, sign_always, space_holder };

enum argument_options {
    normal_argument,
    char_argument,
    short_argument,
    long_argument,
    long_long_argument,
    long_double_argument,
    wchar_argument
};

typedef struct {
    unsigned char justification_options;
    unsigned char sign_options;
    unsigned char precision_specified;
    unsigned char alternate_form;
    unsigned char argument_options;
    unsigned char conversion_char;
    int field_width;
    int precision;
} print_format;

char *float2str(long double num, char *buff, print_format format);

extern double exp(double);

void __num2dec(const decform *, f64, decimal *);

char *fn_80083DB0(char *destination, const char *source);

extern unsigned char lbl_8015B100[];

static inline int isupper(int c) { return (int)(lbl_8015B100[(unsigned char)c] & 0x80); }

void fn_800818C8(decimal *dec, int new_length);

#pragma section code_type ".fzgxpool"
static void printf_string_pool(void) {
    const char *volatile s; /* fzgx-allow: S2 pooled string first-use order */
    s = "";
}
#pragma section code_type ".text"

char *float2str(long double num, char *buff, print_format format) {
    decimal dec;
    decform form;
    char *p;
    char *q;
    int n, digits, sign;
    int int_digits, frac_digits;
    if (format.precision > 509) {
        return 0;
    }
    form.style = 0;
    form.digits = 0x20;
    __num2dec(&form, num, &dec);
    p = (char *)dec.sig.text + dec.sig.length;
    while (dec.sig.length > 1 && *--p == '0') {
        --dec.sig.length;
        ++dec.exp;
    }
    switch (*dec.sig.text) {
    case '0':
        dec.exp = 0;
        break;
    case 'I':
        if (num < 0) {
            p = buff - 5;
            if (isupper(format.conversion_char)) {
                fn_80083DB0(p, "-INF");
            } else {
                fn_80083DB0(p, "-inf");
            }
        } else {
            p = buff - 4;
            if (isupper(format.conversion_char)) {
                fn_80083DB0(p, "INF");
            } else {
                fn_80083DB0(p, "inf");
            }
        }
        return p;
    case 'N':
        if (dec.sign) {
            p = buff - 5;
            if (isupper(format.conversion_char)) {
                fn_80083DB0(p, "-NAN");
            } else {
                fn_80083DB0(p, "-nan");
            }
        } else {
            p = buff - 4;
            if (isupper(format.conversion_char)) {
                fn_80083DB0(p, "NAN");
            } else {
                fn_80083DB0(p, "nan");
            }
        }
        return p;
    }
    dec.exp += dec.sig.length - 1;
    p = buff;
    *--p = 0;
    switch (format.conversion_char) {
    case 'g':
    case 'G':
        if (dec.sig.length > format.precision) {
            fn_800818C8(&dec, format.precision);
        }
        if (dec.exp < -4 || dec.exp >= format.precision) {
            if (format.alternate_form) {
                --format.precision;
            } else {
                format.precision = dec.sig.length - 1;
            }
            if (format.conversion_char == 'g') {
                format.conversion_char = 'e';
            } else {
                format.conversion_char = 'E';
            }
            goto e_format; // Preserve the verified SDK control flow.
        }
        if (format.alternate_form) {
            format.precision -= dec.exp + 1;
        } else if ((format.precision = dec.sig.length - (dec.exp + 1)) < 0) {
            format.precision = 0;
        }
        goto f_format; // Preserve the verified SDK control flow.
    case 'e':
    case 'E':
    e_format:
        if (dec.sig.length > format.precision + 1) {
            fn_800818C8(&dec, format.precision + 1);
        }
        n = dec.exp;
        sign = '+';
        if (n < 0) {
            n = -n;
            sign = '-';
        }
        for (digits = 0; n || digits < 2; ++digits) {
            *--p = n % 10 + '0';
            n /= 10;
        }
        *--p = sign;
        *--p = format.conversion_char;
        if (buff - p + format.precision > 509) {
            return 0;
        }
        if (dec.sig.length < format.precision + 1) {
            for (n = format.precision + 1 - dec.sig.length + 1; --n;) {
                *--p = '0';
            }
        }
        for (n = dec.sig.length, q = (char *)dec.sig.text + dec.sig.length; --n;) {
            *--p = *--q;
        }
        if (format.precision || format.alternate_form) {
            *--p = '.';
        }
        *--p = *dec.sig.text;
        if (dec.sign)
            *--p = '-';
        else if (format.sign_options == sign_always)
            *--p = '+';
        else if (format.sign_options == space_holder)
            *--p = ' ';
        break;
    case 'f':
    case 'F':
    f_format:
        if ((frac_digits = -dec.exp + dec.sig.length - 1) < 0)
            frac_digits = 0;
        if (frac_digits > format.precision) {
            fn_800818C8(&dec, dec.sig.length - (frac_digits - format.precision));
            if ((frac_digits = -dec.exp + dec.sig.length - 1) < 0)
                frac_digits = 0;
        }
        if ((int_digits = dec.exp + 1) < 0)
            int_digits = 0;
        if (int_digits + frac_digits > 509)
            return 0;
        q = (char *)dec.sig.text + dec.sig.length;
        for (digits = 0; digits < (format.precision - frac_digits); ++digits)
            *--p = '0';
        for (digits = 0; digits < frac_digits && digits < dec.sig.length; ++digits)
            *--p = *--q;
        for (; digits < frac_digits; ++digits)
            *--p = '0';
        if (format.precision || format.alternate_form)
            *--p = '.';
        if (int_digits) {
            for (digits = 0; digits < int_digits - dec.sig.length; ++digits) {
                *--p = '0';
            }
            for (; digits < int_digits; ++digits) {
                *--p = *--q;
            }
        } else {
            *--p = '0';
        }
        if (dec.sign) {
            *--p = '-';
        } else if (format.sign_options == sign_always) {
            *--p = '+';
        } else if (format.sign_options == space_holder) {
            *--p = ' ';
        }
        break;
    }
    return p;
}
