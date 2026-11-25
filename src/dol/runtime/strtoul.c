#include "types.h"

enum __ReadProcActions {
    __GetAChar,
    __UngetAChar,
    __TestForError,
};

typedef struct __InStrCtrl {
    char *NextChar;
    int NullCharDetected;
} __InStrCtrl;

enum ScanState {
    SCAN_START = 0x01,
    SCAN_CHECK_FOR_ZERO = 0x02,
    SCAN_LEADING_ZERO = 0x04,
    SCAN_NEED_DIGIT = 0x08,
    SCAN_DIGIT_LOOP = 0x10,
    SCAN_FINISHED = 0x20,
    SCAN_FAILURE = 0x40,
};

extern unsigned char lbl_8015B100[];
extern unsigned char lbl_8015B300[];
extern int lbl_801A6DE0;

int __StringRead(void *context, int character, int action);

unsigned long __strtoul(int base, int max_width, int (*read_proc)(void *, int, int),
                        void *read_context, int *chars_scanned, int *negative, int *overflow);
unsigned long long __strtoull(int base, int max_width, int (*read_proc)(void *, int, int),
                              void *read_context, int *chars_scanned, int *negative, int *overflow);

int atoi(const char *str);
unsigned long strtoul(const char *str, char **end, int base);
unsigned long long __strtoull(int base, int max_width, int (*read_proc)(void *, int, int), void *read_context, int *chars_scanned, int *negative, int *overflow);
unsigned long __strtoul(int base, int max_width, int (*read_proc)(void *, int, int), void *read_context, int *chars_scanned, int *negative, int *overflow);

unsigned long __strtoul(int base, int max_width, int (*read_proc)(void *, int, int),
                        void *read_context, int *chars_scanned, int *negative, int *overflow) {
    int scan_state = SCAN_START;
    int count = 0;
    int spaces = 0;
    unsigned long value = 0;
    unsigned long value_max = 0;
    int c;
    *negative = *overflow = 0;
    if (base < 0 || base == 1 || base > 36 || max_width < 1) {
        scan_state = SCAN_FAILURE;
    } else {
        c = (count++, read_proc(read_context, 0, __GetAChar));
    }
    if (base != 0) {
        value_max = 0xFFFFFFFFUL / base;
    }
    while (count <= max_width && c != -1 && !((scan_state) & (SCAN_FINISHED | SCAN_FAILURE))) {
        switch (scan_state) {
        case SCAN_START:
            if (isspace(c)) {
                c = (count++, read_proc(read_context, 0, __GetAChar));
                count--;
                spaces++;
                break;
            }
            if (c == '+') {
                c = (count++, read_proc(read_context, 0, __GetAChar));
            } else if (c == '-') {
                c = (count++, read_proc(read_context, 0, __GetAChar));
                *negative = 1;
            }
            scan_state = SCAN_CHECK_FOR_ZERO;
            break;
        case SCAN_CHECK_FOR_ZERO:
            if ((base == 0 || base == 16) && c == '0') {
                scan_state = SCAN_LEADING_ZERO;
                c = (count++, read_proc(read_context, 0, __GetAChar));
                break;
            }
            scan_state = SCAN_NEED_DIGIT;
            break;
        case SCAN_LEADING_ZERO:
            if (c == 'X' || c == 'x') {
                base = 16;
                scan_state = SCAN_NEED_DIGIT;
                c = (count++, read_proc(read_context, 0, __GetAChar));
                break;
            }
            if (base == 0) {
                base = 8;
            }
            scan_state = SCAN_DIGIT_LOOP;
            break;
        case SCAN_NEED_DIGIT:
        case SCAN_DIGIT_LOOP:
            if (base == 0) {
                base = 10;
            }
            if (!value_max) {
                value_max = 0xFFFFFFFFUL / base;
            }
            if (isdigit(c)) {
                if ((c -= '0') >= base) {
                    if (scan_state == SCAN_DIGIT_LOOP) {
                        scan_state = SCAN_FINISHED;
                    } else {
                        scan_state = SCAN_FAILURE;
                    }
                    c += '0';
                    break;
                }
            } else if (!isalpha(c) || (toupper(c) - 'A' + 10) >= base) {
                if (scan_state == SCAN_DIGIT_LOOP) {
                    scan_state = SCAN_FINISHED;
                } else {
                    scan_state = SCAN_FAILURE;
                }
                break;
            } else {
                c = toupper(c) - 'A' + 10;
            }
            if (value > value_max) {
                *overflow = 1;
            }
            value *= base;
            if (c > 0xFFFFFFFFUL - value) {
                *overflow = 1;
            }
            value += c;
            scan_state = SCAN_DIGIT_LOOP;
            c = (count++, read_proc(read_context, 0, __GetAChar));
            break;
        }
    }
    if (!((scan_state) & (SCAN_LEADING_ZERO | SCAN_DIGIT_LOOP | SCAN_FINISHED))) {
        count = 0;
        value = 0;
        *chars_scanned = 0;
    } else {
        count--;
        *chars_scanned = count + spaces;
    }
    read_proc(read_context, (c), __UngetAChar);
    return value;
}

unsigned long long __strtoull(int base, int max_width, int (*read_proc)(void *, int, int),
                              void *read_context, int *chars_scanned, int *negative,
                              int *overflow) {
    int scan_state = SCAN_START;
    int count = 0;
    int spaces = 0;
    unsigned long long value = 0;
    unsigned long long value_max = 0;
    unsigned long long ullong_max = 0xFFFFFFFFFFFFFFFFULL;
    int c;
    *negative = *overflow = 0;
    if (base < 0 || base == 1 || base > 36 || max_width < 1) {
        scan_state = SCAN_FAILURE;
    } else {
        c = (count++, read_proc(read_context, 0, __GetAChar));
    }
    if (base != 0) {
        value_max = 0xFFFFFFFFFFFFFFFFULL / base;
    }
    while (count <= max_width && c != -1 && !((scan_state) & (SCAN_FINISHED | SCAN_FAILURE))) {
        switch (scan_state) {
        case SCAN_START:
            if (isspace(c)) {
                c = (count++, read_proc(read_context, 0, __GetAChar));
                count--;
                spaces++;
                break;
            }
            if (c == '+') {
                c = (count++, read_proc(read_context, 0, __GetAChar));
            } else if (c == '-') {
                c = (count++, read_proc(read_context, 0, __GetAChar));
                *negative = 1;
            }
            scan_state = SCAN_CHECK_FOR_ZERO;
            break;
        case SCAN_CHECK_FOR_ZERO:
            if ((base == 0 || base == 16) && c == '0') {
                scan_state = SCAN_LEADING_ZERO;
                c = (count++, read_proc(read_context, 0, __GetAChar));
                break;
            }
            scan_state = SCAN_NEED_DIGIT;
            break;
        case SCAN_LEADING_ZERO:
            if (c == 'X' || c == 'x') {
                base = 16;
                scan_state = SCAN_NEED_DIGIT;
                c = (count++, read_proc(read_context, 0, __GetAChar));
                break;
            }
            if (base == 0) {
                base = 8;
            }
            scan_state = SCAN_DIGIT_LOOP;
            break;
        case SCAN_NEED_DIGIT:
        case SCAN_DIGIT_LOOP:
            if (base == 0) {
                base = 10;
            }
            if (!value_max) {
                value_max = ullong_max / base;
            }
            if (isdigit(c)) {
                if ((c -= '0') >= base) {
                    if (scan_state == SCAN_DIGIT_LOOP) {
                        scan_state = SCAN_FINISHED;
                    } else {
                        scan_state = SCAN_FAILURE;
                    }
                    c += '0';
                    break;
                }
            } else if (!isalpha(c) || (toupper(c) - 'A' + 10) >= base) {
                if (scan_state == SCAN_DIGIT_LOOP) {
                    scan_state = SCAN_FINISHED;
                } else {
                    scan_state = SCAN_FAILURE;
                }
                break;
            } else {
                c = toupper(c) - 'A' + 10;
            }
            if (value > value_max) {
                *overflow = 1;
            }
            value *= base;
            if (c > ullong_max - value) {
                *overflow = 1;
            }
            value += c;
            scan_state = SCAN_DIGIT_LOOP;
            c = (count++, read_proc(read_context, 0, __GetAChar));
            break;
        }
    }
    if (!((scan_state) & (SCAN_LEADING_ZERO | SCAN_DIGIT_LOOP | SCAN_FINISHED))) {
        count = 0;
        value = *chars_scanned = 0;
    } else {
        count--;
        *chars_scanned = count + spaces;
    }
    read_proc(read_context, (c), __UngetAChar);
    return value;
}

unsigned long strtoul(const char *str, char **end, int base) {
    unsigned long value;
    int count;
    int negative;
    int overflow;
    __InStrCtrl input;
    input.NextChar = (char *)str;
    input.NullCharDetected = 0;
    value =
        __strtoul(base, 0x7FFFFFFF, &__StringRead, (void *)&input, &count, &negative, &overflow);
    if (end != 0) {
        *end = (char *)str + count;
    }
    if (overflow) {
        value = 0xFFFFFFFFUL;
        lbl_801A6DE0 = 34;
    } else if (negative) {
        value = (unsigned long)-(long)value;
    }
    return value;
}

int atoi(const char *str) {
    unsigned long value;
    int overflow;
    int negative;
    int count;
    __InStrCtrl input;
    input.NextChar = (char *)str;
    input.NullCharDetected = 0;
    value = __strtoul(10, 0x7FFFFFFF, __StringRead, &input, &count, &negative, &overflow);
    if (overflow || (!negative && value > 0x7FFFFFFFUL) || (negative && value > 0x80000000UL)) {
        value = negative ? 0x80000000UL : 0x7FFFFFFFUL;
        lbl_801A6DE0 = 34;
    } else if (negative) {
        value = (unsigned long)-(long)value;
    }
    return (int)value;
}

static inline int toupper(int c) { return c == -1 ? -1 : (int)lbl_8015B300[(unsigned char)c]; }

static inline int isspace(int c) { return (int)(lbl_8015B100[(unsigned char)c] & (0x02 | 0x04)); }

static inline int isdigit(int c) { return (int)(lbl_8015B100[(unsigned char)c] & 0x10); }

static inline int isalpha(int c) { return (int)(lbl_8015B100[(unsigned char)c] & (0x40 | 0x80)); }
