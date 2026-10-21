#include "types.h"
#pragma pool_strings on

typedef struct decform {
    char style;
    char reserved;
    s16 digits;
} decform;

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

typedef struct print_format {
    u8 justification_options;
    u8 sign_options;
    u8 precision_specified;
    u8 alternate_form;
    u8 argument_options;
    u8 conversion_char;
    s32 field_width;
    s32 precision;
} print_format;

extern void __num2dec(const decform *, f64, decimal *);
extern char *fn_80083DB0(char *, const char *);
extern char *long2str(s32, char *, print_format);

/* Primer: an earlier function of the retail TU pooled "" at offset 0. */
#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_primer(void) {
    fn_80083DB0(0, "");
}

char *double2hex(f64 num, char *buff, print_format format) {
    char *p;
    u8 *q;
    s32 working_byte;
    f64 ld;
    s16 expbits;
    s32 exp;
    print_format exp_format;
    u8 b;
    s32 hex_precision;
    decform form;
    decimal dec;

    p = buff;
    ld = num;

    if (format.precision > 509) {
        return 0;
    }

    form.style = 0;
    form.digits = 0x20;
    __num2dec(&form, num, &dec);

    if (*dec.sig.text == 'I') {
        if (*(s16 *)&ld & 0x8000) {
            p = buff - 5;
            if (format.conversion_char == 'A')
                fn_80083DB0(p, "-INF");
            else
                fn_80083DB0(p, "-inf");
        } else {
            p = buff - 4;
            if (format.conversion_char == 'A')
                fn_80083DB0(p, "INF");
            else
                fn_80083DB0(p, "inf");
        }
        return p;
    } else if (*dec.sig.text == 'N') {
        if (*(u8 *)&num & 0x80) {
            p = buff - 5;
            if (format.conversion_char == 'A')
                fn_80083DB0(p, "-NAN");
            else
                fn_80083DB0(p, "-nan");
        } else {
            p = buff - 4;
            if (format.conversion_char == 'A')
                fn_80083DB0(p, "NAN");
            else
                fn_80083DB0(p, "nan");
        }
        return p;
    }

    exp_format.justification_options = 1;
    exp_format.sign_options = 1;
    exp_format.precision_specified = 0;
    exp_format.alternate_form = 0;
    exp_format.argument_options = 0;
    exp_format.conversion_char = 'd';
    exp_format.field_width = 0;
    exp_format.precision = 1;

    expbits = (*(s16 *)&ld & 0x7ff0) >> 4;
    exp = expbits - 1023;
    p = long2str(exp, buff, exp_format);
    if (format.conversion_char == 'a')
        *--p = 'p';
    else
        *--p = 'P';

    q = (u8 *)&num;
    for (hex_precision = format.precision; hex_precision >= 1; hex_precision--) {
        int c;
        b = q[hex_precision / 2 + 1];
        working_byte = (hex_precision % 2) ? (b & 0x0f) : (char)(b >> 4);
        if ((char)working_byte < 10)
            c = working_byte + '0';
        else if (format.conversion_char == 'a')
            c = working_byte - 10 + 'a';
        else
            c = working_byte - 10 + 'A';
        *--p = c;
    }

    if (format.precision || format.alternate_form)
        *--p = '.';

    *--p = '1';
    if (format.conversion_char == 'a')
        *--p = 'x';
    else
        *--p = 'X';
    *--p = '0';

    if (*(s16 *)&ld & 0x8000)
        *--p = '-';
    else if (format.sign_options == 1)
        *--p = '+';
    else if (format.sign_options == 2)
        *--p = ' ';

    return p;
}
