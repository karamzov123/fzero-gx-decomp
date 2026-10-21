
/* MSL formatter adapted from CC0 ShulkMaster/mk-deception, src/runtime/printf.c,
 * donor revision 33b1e0082c7630ee4f20b828559966872ae670e1.
 * The complete shared 37-byte printf pool is recovered from the linked image. */
#include "types.h"

typedef struct MkVaListState {
    signed char gpr;
    signed char fpr;
    unsigned short reserved;
    char *input_arg_area;
    char *reg_save_area;
} __va_list[1];

typedef __va_list va_list;

typedef unsigned short wchar_t;

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

int __pformatter(void *(*WriteProc)(void *, const char *, size_t), void *WriteProcArg,
                 const char *format_str, va_list arg);

int __pformatter(void *(*WriteProc)(void *, const char *, size_t), void *WriteProcArg,
                 const char *format_str, va_list arg);

void *__va_arg(__va_list args, int type);

char *strchr(const char *string, int character);

unsigned long strlen(const char *string);

const char *parse_format(const char *format_string, va_list *arg, print_format *format);

char *long2str(long num, char *buff, print_format format);

char *longlong2str(long long num, char *pBuf, print_format fmt);

char *double2hex(long double num, char *buff, print_format format);

char *float2str(long double num, char *buff, print_format format);

extern int __pformatter(void *(*WriteProc)(void *, const char *, size_t), void *WriteProcArg,
                        const char *format_str, va_list arg);

int __pformatter(void *(*WriteProc)(void *, const char *, size_t), void *WriteProcArg,
                 const char *format_str, va_list arg) {
    int num_chars, chars_written, field_width;
    const char *format_ptr;
    const char *curr_format;
    print_format format;
    long long_num;
    long long long_long_num;
    long double long_double_num;
    char buff[512];
    char *buff_ptr;
    char *string_end;
    char fill_char = ' ';
    format_ptr = format_str;
    chars_written = 0;
    while (*format_ptr) {
        if (!(curr_format = strchr(format_ptr, '%'))) {
            num_chars = strlen(format_ptr);
            chars_written += num_chars;
            if (num_chars && !(*WriteProc)(WriteProcArg, format_ptr, num_chars)) {
                return -1;
            }
            break;
        }
        num_chars = curr_format - format_ptr;
        chars_written += num_chars;
        if (num_chars && !(*WriteProc)(WriteProcArg, format_ptr, num_chars)) {
            return -1;
        }
        format_ptr = curr_format;
        format_ptr = parse_format(format_ptr, (va_list *)arg, &format);
        switch (format.conversion_char) {
        case 'd':
        case 'i':
            if (format.argument_options == long_argument) {
                long_num = (*((long *)__va_arg((arg), _var_arg_typeof(long))));
            } else if (format.argument_options == long_long_argument) {
                long_long_num = (*((long long *)__va_arg((arg), _var_arg_typeof(long long))));
            } else {
                long_num = (*((int *)__va_arg((arg), _var_arg_typeof(int))));
            }
            if (format.argument_options == short_argument) {
                long_num = (short)long_num;
            }
            if (format.argument_options == char_argument) {
                long_num = (signed char)long_num;
            }
            if ((format.argument_options == long_long_argument)) {
                if (!(buff_ptr = longlong2str(long_long_num, buff + 512, format))) {
                    goto conversion_error; // Preserve the verified SDK control flow.
                }
            } else {
                if (!(buff_ptr = long2str(long_num, buff + 512, format))) {
                    goto conversion_error; // Preserve the verified SDK control flow.
                }
            }
            num_chars = buff + 512 - 1 - buff_ptr;
            break;
        case 'o':
        case 'u':
        case 'x':
        case 'X':
            if (format.argument_options == long_argument) {
                long_num = (*((unsigned long *)__va_arg((arg), _var_arg_typeof(unsigned long))));
            } else if (format.argument_options == long_long_argument) {
                long_long_num = (*((long long *)__va_arg((arg), _var_arg_typeof(long long))));
            } else {
                long_num = (*((unsigned int *)__va_arg((arg), _var_arg_typeof(unsigned int))));
            }
            if (format.argument_options == short_argument) {
                long_num = (unsigned short)long_num;
            }
            if (format.argument_options == char_argument) {
                long_num = (unsigned char)long_num;
            }
            if ((format.argument_options == long_long_argument)) {
                if (!(buff_ptr = longlong2str(long_long_num, buff + 512, format))) {
                    goto conversion_error; // Preserve the verified SDK control flow.
                }
            } else {
                if (!(buff_ptr = long2str(long_num, buff + 512, format))) {
                    goto conversion_error; // Preserve the verified SDK control flow.
                }
            }
            num_chars = buff + 512 - 1 - buff_ptr;
            break;
        case 'f':
        case 'F':
        case 'e':
        case 'E':
        case 'g':
        case 'G':
            if (format.argument_options == long_double_argument) {
                long_double_num = (*((long double *)__va_arg((arg), _var_arg_typeof(long double))));
            } else {
                long_double_num = (*((double *)__va_arg((arg), _var_arg_typeof(double))));
            }
            if (!(buff_ptr = float2str(long_double_num, buff + 512, format))) {
                goto conversion_error; // Preserve the verified SDK control flow.
            }
            num_chars = buff + 512 - 1 - buff_ptr;
            break;
        case 'a':
        case 'A':
            if (format.argument_options == long_double_argument) {
                long_double_num = (*((long double *)__va_arg((arg), _var_arg_typeof(long double))));
            } else {
                long_double_num = (*((double *)__va_arg((arg), _var_arg_typeof(double))));
            }
            if (!(buff_ptr = double2hex(long_double_num, buff + 512, format))) {
                goto conversion_error; // Preserve the verified SDK control flow.
            }
            num_chars = buff + 512 - 1 - buff_ptr;
            break;
        case 's':
            if (format.argument_options == wchar_argument) {
                wchar_t *wcs_ptr = (*((wchar_t **)__va_arg((arg), _var_arg_typeof(wchar_t *))));
                if (wcs_ptr == 0) {
                    wcs_ptr = L"";
                }
                if ((num_chars = wcstombs(buff, wcs_ptr, sizeof(buff))) < 0) {
                    goto conversion_error; // Preserve the verified SDK control flow.
                }
                buff_ptr = &buff[0];
            } else {
                buff_ptr = (*((char **)__va_arg((arg), _var_arg_typeof(char *))));
            }
            if (buff_ptr == 0) {
                buff_ptr = "\0-INF\0-inf\0INF\0inf\0-NAN\0-nan\0NAN\0nan";
            }
            if (format.alternate_form) {
                num_chars = (unsigned char)*buff_ptr++;
                if (format.precision_specified && num_chars > format.precision) {
                    num_chars = format.precision;
                }
            } else if (format.precision_specified) {
                num_chars = format.precision;
                if ((string_end = (char *)memchr((unsigned char *)buff_ptr, 0, num_chars)) != 0) {
                    num_chars = string_end - buff_ptr;
                }
            } else {
                num_chars = strlen(buff_ptr);
            }
            break;
        case 'n':
            buff_ptr = (*((char **)__va_arg((arg), _var_arg_typeof(char *))));
            switch (format.argument_options) {
            case normal_argument:
                *(int *)buff_ptr = chars_written;
                break;
            case short_argument:
                *(short *)buff_ptr = chars_written;
                break;
            case long_argument:
                *(long *)buff_ptr = chars_written;
                break;
            case long_long_argument:
                *(long long *)buff_ptr = chars_written;
                break;
            }
            continue;
        case 'c':
            buff_ptr = buff;
            *buff_ptr = (*((int *)__va_arg((arg), _var_arg_typeof(int))));
            num_chars = 1;
            break;
        case '%':
            buff_ptr = buff;
            *buff_ptr = '%';
            num_chars = 1;
            break;
        case 0xFF:
        default:
        conversion_error:
            num_chars = strlen(curr_format);
            chars_written += num_chars;
            if (num_chars && !(*WriteProc)(WriteProcArg, curr_format, num_chars)) {
                return -1;
            }
            return chars_written;
            break;
        }
        field_width = num_chars;
        if (format.justification_options != left_justification) {
            fill_char = (format.justification_options == zero_fill) ? '0' : ' ';
            if (((*buff_ptr == '+') || (*buff_ptr == '-') || (*buff_ptr == ' ')) &&
                (fill_char == '0')) {
                if ((*WriteProc)(WriteProcArg, buff_ptr, 1) == 0) {
                    return -1;
                }
                ++buff_ptr;
                num_chars--;
            }
            while (field_width < format.field_width) {
                if ((*WriteProc)(WriteProcArg, &fill_char, 1) == 0) {
                    return -1;
                }
                ++field_width;
            }
        }
        if (num_chars && !(*WriteProc)(WriteProcArg, buff_ptr, num_chars)) {
            return -1;
        }
        if (format.justification_options == left_justification) {
            while (field_width < format.field_width) {
                char blank = ' ';
                if ((*WriteProc)(WriteProcArg, &blank, 1) == 0) {
                    return -1;
                }
                ++field_width;
            }
        }
        chars_written += field_width;
    }
    return chars_written;
}
