#include "types.h"

typedef struct FnState {
    char *cursor;
    s32 state;
} FnState;

typedef unsigned int uint;

typedef long double f128;

typedef unsigned short wchar_t;

typedef struct {
    char gpr;
    char fpr;
    char reserved[2];
    char *input_arg_area;
    char *reg_save_area;
} __va_list[1];

typedef __va_list va_list;

enum __ReadProcActions { __GetAChar, __UngetAChar, __TestForError };

enum argument_options {
    normal_argument,
    char_argument,
    short_argument,
    long_argument,
    long_long_argument,
    double_argument,
    long_double_argument,
    wchar_argument
};

typedef u8 char_map[32];

typedef struct {
    u8 suppress_assignment;
    u8 field_width_specified;
    u8 argument_options;
    u8 conversion_char;
    int field_width;
    char_map char_set;
} scan_format;

int fn_80082A7C(int (*ReadProc)(void *, int, int), void *ReadProcArg, const char *format_str,
                va_list arg);
int __StringRead(void *context, int character, int action);

void *__va_arg(va_list v_list, u8 type);

extern const u8 lbl_8015B100[256];

int mbtowc(wchar_t *pwc, const char *s, size_t n);

extern f128 fn_80083F10(int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg,
                        int *chars_scanned, int *overflow);

extern u32 __strtoul(int base, int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg,
                     int *chars_scanned, int *negative, int *overflow);

extern u64 __strtoull(int base, int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg,
                      int *chars_scanned, int *negative, int *overflow);

void exit(int);
const char *fn_80083428(const char *format_string, scan_format *format);

int sscanf(const char *input, const char *format_string, ...);
int __StringRead(void *context, int character, int action);
int fn_80082A7C(int (*ReadProc)(void *, int, int), void *ReadProcArg, const char *format_str, va_list arg);
const char *fn_80083428(const char *format_string, scan_format *format);

const char *fn_80083428(const char *format_string, scan_format *format) {
    const char *cursor = format_string;
    int character;
    int flag_found;
    int invert;
    scan_format parsed = {0, 0, normal_argument, 0, 0x7FFFFFFF, {0}};
    cursor++;
    character = *cursor;
    if (character == '%') {
        parsed.conversion_char = character;
        *format = parsed;
        return cursor + 1;
    }
    if (character == '*') {
        parsed.suppress_assignment = 1;
        character = *++cursor;
    }
    if (isdigit(character)) {
        parsed.field_width = 0;
        do {
            parsed.field_width = (parsed.field_width * 10) + (character - '0');
            character = *++cursor;
        } while (isdigit(character));
        if (parsed.field_width == 0) {
            parsed.conversion_char = 0xFF;
            *format = parsed;
            return cursor + 1;
        }
        parsed.field_width_specified = 1;
    }
    flag_found = 1;
    switch (character) {
    case 'h':
        parsed.argument_options = short_argument;
        if (cursor[1] == 'h') {
            parsed.argument_options = char_argument;
            character = *++cursor;
        }
        break;
    case 'l':
        parsed.argument_options = long_argument;
        if (cursor[1] == 'l') {
            parsed.argument_options = long_long_argument;
            character = *++cursor;
        }
        break;
    case 'L':
        parsed.argument_options = long_double_argument;
        break;
    default:
        flag_found = 0;
        break;
    }
    if (flag_found)
        character = *++cursor;
    parsed.conversion_char = character;
    switch (character) {
    case 'd':
    case 'i':
    case 'u':
    case 'o':
    case 'x':
    case 'X':
        if (parsed.argument_options == long_double_argument)
            parsed.conversion_char = 0xFF;
        break;
    case 'a':
    case 'f':
    case 'e':
    case 'E':
    case 'g':
    case 'G':
        if (parsed.argument_options == char_argument || parsed.argument_options == short_argument ||
            parsed.argument_options == long_long_argument) {
            parsed.conversion_char = 0xFF;
        } else if (parsed.argument_options == long_argument) {
            parsed.argument_options = double_argument;
        }
        break;
    case 'p':
        parsed.argument_options = long_argument;
        parsed.conversion_char = 'x';
        break;
    case 'c':
        if (parsed.argument_options == long_argument)
            parsed.argument_options = wchar_argument;
        else if (parsed.argument_options != normal_argument)
            parsed.conversion_char = 0xFF;
        break;
    case 's': {
        int index;
        unsigned char *entry;
        if (parsed.argument_options == long_argument)
            parsed.argument_options = wchar_argument;
        else if (parsed.argument_options != normal_argument)
            parsed.conversion_char = 0xFF;
        for (index = sizeof(parsed.char_set), entry = parsed.char_set; index != 0;
             --index)
            *entry++ = 0xFF;
        parsed.char_set[1] = 0xC1;
        parsed.char_set[4] = 0xFE;
        break;
    }
    case 'n':
        break;
    case '[':
        if (parsed.argument_options == long_argument)
            parsed.argument_options = wchar_argument;
        else if (parsed.argument_options != normal_argument)
            parsed.conversion_char = 0xFF;
        character = *++cursor;
        invert = 0;
        if (character == '^') {
            invert = 1;
            character = *++cursor;
        }
        if (character == ']') {
            ((parsed.char_set)[(unsigned char)(']') >> 3] |=
             (1 << ((unsigned char)(']') & 7)));
            character = *++cursor;
        }
        while (character != 0 && character != ']') {
            int range_end;
            ((parsed.char_set)[(unsigned char)(character) >> 3] |=
             (1 << ((unsigned char)(character) & 7)));
            if (cursor[1] == '-' && (range_end = cursor[2]) != 0 && range_end != ']') {
                while (++character <= range_end)
                    ((parsed.char_set)[(unsigned char)(character) >> 3] |=
                     (1 << ((unsigned char)(character) & 7)));
                cursor += 3;
                character = *cursor;
            } else {
                character = *++cursor;
            }
        }
        if (character == 0) {
            parsed.conversion_char = 0xFF;
        } else if (invert) {
            int index;
            unsigned char *entry = parsed.char_set;
            for (index = sizeof(parsed.char_set); index != 0; --index, ++entry)
                *entry = ~*entry;
        }
        break;
    default:
        parsed.conversion_char = 0xFF;
        break;
    }
    *format = parsed;
    return cursor + 1;
}

int fn_80082A7C(int (*ReadProc)(void *, int, int), void *ReadProcArg, const char *format_str,
                va_list arg) {
    int terminate = 0;
    int num_chars, chars_read, items_assigned, conversions;
    int base, negative, overflow;
    const char *format_ptr;
    char c;
    int format_char;
    scan_format format;
    s32 long_num;
    char *arg_ptr;
    u32 u_long_num;
    s64 long_long_num;
    u64 u_long_long_num;
    f128 long_double_num;
    format_ptr = format_str;
    chars_read = 0;
    items_assigned = 0;
    conversions = 0;
    while (!terminate && (format_char = (char)*format_ptr) != 0) {
        if (isspace(format_char)) {
            do {
                format_char = *++format_ptr;
            } while (isspace(format_char));
            while (isspace(c = (*ReadProc)(ReadProcArg, 0, __GetAChar)))
                ++chars_read;
            (*ReadProc)(ReadProcArg, c, __UngetAChar);
            continue;
        }
        if (format_char != '%') {
            if ((c = (*ReadProc)(ReadProcArg, 0, __GetAChar)) != (u8)format_char) {
                (*ReadProc)(ReadProcArg, c, __UngetAChar);
                /* Justification: the literal in the format did not match the input stream. */
                goto exit; /* justification: literal mismatch ends the scan */
            }
            chars_read++;
            format_ptr++;
            continue;
        }
        format_ptr = fn_80083428(format_ptr, &format);
        if (!format.suppress_assignment && format.conversion_char != '%') {
            arg_ptr = (*((char **)__va_arg(arg, _var_arg_typeof(char *))));
        } else {
            arg_ptr = 0;
        }
        if ((format.conversion_char != 'n') && (*ReadProc)(ReadProcArg, 0, __TestForError)) {
            terminate = 1;
            /* Justification: the read callback reported an error condition. */
            goto exit; /* justification: read error ends the scan */
        }
        switch (format.conversion_char) {
        case 'd': {
            base = 10;
            /* Justification: shared signed integer conversion code below. */
            goto signed_int; /* justification: share the conversion code */
        }
        case 'i': {
            base = 0;
        }
        signed_int: {
            if ((format.argument_options == long_long_argument))
                u_long_long_num = __strtoull(base, format.field_width, ReadProc, ReadProcArg,
                                             &num_chars, &negative, &overflow);
            else
                u_long_num = __strtoul(base, format.field_width, ReadProc, ReadProcArg, &num_chars,
                                       &negative, &overflow);
            if (!num_chars) {
                /* Justification: no digits were consumed, the conversion failed. */
                goto exit; /* justification: failed conversion ends the scan */
            }
            chars_read += num_chars;
            if ((format.argument_options == long_long_argument))
                long_long_num = (negative ? -u_long_long_num : u_long_long_num);
            else
                long_num = (negative ? -u_long_num : u_long_num);
        }
        signed_int_assign: {
            if (arg_ptr) {
                switch (format.argument_options) {
                case normal_argument:
                    *(int *)arg_ptr = long_num;
                    break;
                case char_argument:
                    *(s8 *)arg_ptr = long_num;
                    break;
                case short_argument:
                    *(s16 *)arg_ptr = long_num;
                    break;
                case long_argument:
                    *(s32 *)arg_ptr = long_num;
                    break;
                case long_long_argument:
                    *(s64 *)arg_ptr = long_long_num;
                    break;
                }
                items_assigned++;
            }
            conversions++;
            break;
        }
        case 'o': {
            base = 8;
            /* Justification: shared unsigned integer conversion code below. */
            goto unsigned_int; /* justification: share the conversion code */
        }
        case 'u': {
            base = 10;
            /* Justification: shared unsigned integer conversion code below. */
            goto unsigned_int; /* justification: share the conversion code */
        }
        case 'x':
        case 'X': {
            base = 16;
        }
        unsigned_int: {
            if ((format.argument_options == long_long_argument))
                u_long_long_num = __strtoull(base, format.field_width, ReadProc, ReadProcArg,
                                             &num_chars, &negative, &overflow);
            else
                u_long_num = __strtoul(base, format.field_width, ReadProc, ReadProcArg, &num_chars,
                                       &negative, &overflow);
            if (!num_chars) {
                /* Justification: no digits were consumed, the conversion failed. */
                goto exit; /* justification: failed conversion ends the scan */
            }
            chars_read += num_chars;
            if (negative) {
                if (format.argument_options == long_long_argument)
                    u_long_long_num = -u_long_long_num;
                else
                    u_long_num = -u_long_num;
            }
        }
        unsigned_int_assign: {
            if (arg_ptr) {
                switch (format.argument_options) {
                case normal_argument:
                    *(uint *)arg_ptr = u_long_num;
                    break;
                case char_argument:
                    *(u8 *)arg_ptr = u_long_num;
                    break;
                case short_argument:
                    *(u16 *)arg_ptr = u_long_num;
                    break;
                case long_argument:
                    *(u32 *)arg_ptr = u_long_num;
                    break;
                case long_long_argument:
                    *(u64 *)arg_ptr = u_long_long_num;
                    break;
                }
                items_assigned++;
            }
            conversions++;
            break;
        }
        case 'a':
        case 'f':
        case 'e':
        case 'E':
        case 'g':
        case 'G':
        flt: {
            long_double_num =
                fn_80083F10(format.field_width, ReadProc, ReadProcArg, &num_chars, &overflow);
            if (!num_chars) {
                /* Justification: no digits were consumed, the conversion failed. */
                goto exit; /* justification: failed conversion ends the scan */
            }
            chars_read += num_chars;
        }
        assign_float: {
            if (arg_ptr) {
                switch (format.argument_options) {
                case normal_argument:
                    *(f32 *)arg_ptr = long_double_num;
                    break;
                case double_argument:
                    *(f64 *)arg_ptr = long_double_num;
                    break;
                case long_double_argument:
                    *(f128 *)arg_ptr = long_double_num;
                    break;
                }
                items_assigned++;
            }
            conversions++;
            break;
        }
        case 'c': {
            if (!format.field_width_specified)
                format.field_width = 1;
            if (arg_ptr) {
                int read_char;
                num_chars = 0;
                while (format.field_width-- &&
                       ((read_char = ((*ReadProc)(ReadProcArg, 0, __GetAChar))) != -1)) {
                    c = read_char;
                    if (format.argument_options == wchar_argument) {
                        mbtowc(((wchar_t *)arg_ptr), &c, 1);
                        (wchar_t *)arg_ptr++;
                    } else {
                        *arg_ptr++ = c;
                    }
                    num_chars++;
                }
                if (!num_chars) {
                    /* Justification: no characters could be read at all. */
                    goto exit; /* justification: empty field ends the scan */
                }
                chars_read += num_chars;
                items_assigned++;
            } else {
                num_chars = 0;
                while (format.field_width-- &&
                       ((c = ((*ReadProc)(ReadProcArg, 0, __GetAChar))) != -1)) {
                    num_chars++;
                }
                if (!num_chars)
                    /* Justification: no characters could be read at all. */
                    goto exit; /* justification: empty field ends the scan */
            }
            conversions++;
            break;
        }
        case '%': {
            while (isspace(c = (*ReadProc)(ReadProcArg, 0, __GetAChar)))
                chars_read++;
            if (c != '%') {
                (*ReadProc)(ReadProcArg, c, __UngetAChar);
                /* Justification: a '%%' conversion saw something other than '%'. */
                goto exit; /* justification: literal mismatch ends the scan */
            }
            chars_read++;
            break;
        }
        case 's': {
            c = (*ReadProc)(ReadProcArg, 0, __GetAChar);
            while (isspace(c)) {
                chars_read++;
                c = (*ReadProc)(ReadProcArg, 0, __GetAChar);
            }
            (*ReadProc)(ReadProcArg, c, __UngetAChar);
        }
        case '[': {
            if (arg_ptr) {
                num_chars = 0;
                while (format.field_width-- &&
                       ((c = ((*ReadProc)(ReadProcArg, 0, __GetAChar))) != -1) &&
                       (format.char_set[(u8)c >> 3] & (1 << (c & 7)))) {
                    if (format.argument_options == wchar_argument) {
                        mbtowc(((wchar_t *)arg_ptr), &c, 1);
                        arg_ptr = (char *)((wchar_t *)arg_ptr + 1);
                    } else {
                        *arg_ptr++ = c;
                    }
                    num_chars++;
                }
                if (!num_chars) {
                    (*ReadProc)(ReadProcArg, c, __UngetAChar);
                    /* Justification: no characters matched the scanset. */
                    goto exit; /* justification: empty field ends the scan */
                }
                chars_read += num_chars;
                if (format.argument_options == wchar_argument)
                    *(wchar_t *)arg_ptr = L'\0';
                else
                    *arg_ptr = 0;
                items_assigned++;
            } else {
                num_chars = 0;
                while (format.field_width-- &&
                       ((c = ((*ReadProc)(ReadProcArg, 0, __GetAChar))) != -1) &&
                       (format.char_set[(u8)c >> 3] & (1 << (c & 7)))) {
                    num_chars++;
                }
                if (!num_chars) {
                    (*ReadProc)(ReadProcArg, c, __UngetAChar);
                    continue;
                }
                chars_read += num_chars;
            }
            if (format.field_width >= 0)
                (*ReadProc)(ReadProcArg, c, __UngetAChar);
            conversions++;
            break;
        }
        case 'n': {
            if (arg_ptr)
                switch (format.argument_options) {
                case normal_argument: {
                    *(int *)arg_ptr = chars_read;
                    break;
                }
                case short_argument: {
                    *(s16 *)arg_ptr = chars_read;
                    break;
                }
                case long_argument: {
                    *(s32 *)arg_ptr = chars_read;
                    break;
                }
                case char_argument: {
                    *(char *)arg_ptr = chars_read;
                    break;
                }
                case long_long_argument: {
                    *(s64 *)arg_ptr = chars_read;
                    break;
                }
                }
            continue;
        }
        case 0xFF:
        default: {
            /* Justification: unknown conversion character, nothing can be consumed. */
            goto exit; /* justification: unsupported conversion ends the scan */
        }
        }
    }
exit:
    if ((*ReadProc)(ReadProcArg, 0, __TestForError) && conversions == 0)
        return -1;
    return items_assigned;
}

static inline int isspace(int c) { return (lbl_8015B100[(u8)c] & (0x02 | 0x04)); }

static inline int isdigit(int c) { return (lbl_8015B100[(u8)c] & 0x10); }

int __StringRead(void *context, int character, int action) {
    FnState *control = (FnState *)context;
    char result;

    switch (action) {
    case __GetAChar:
        result = *control->cursor;
        if (result == '\0') {
            control->state = 1;
            return -1;
        }
        control->cursor++;
        return (unsigned char)result;
    case __UngetAChar:
        if (control->state == 0) {
            control->cursor--;
        } else {
            control->state = 0;
        }
        return character;
    case __TestForError:
        return control->state;
    }
    return 0;
}

int sscanf(const char *input, const char *format_string, ...) {
    va_list arguments;
    FnState control;

    __builtin_va_info(&arguments);
    control.cursor = (char *)input;
    if (input == 0 || *control.cursor == '\0') {
        return -1;
    }
    control.state = 0;
    return fn_80082A7C(__StringRead, &control, format_string, arguments);
}
