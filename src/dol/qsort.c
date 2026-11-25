#include "msl/decimal.h"


/* --- dol/printf.c --- */
/* MSL C printf.c (Metrowerks runtime library). The formatter body is adapted
 * from CC0 ShulkMaster/mk-deception, src/runtime/printf.c, donor revision
 * 33b1e0082c7630ee4f20b828559966872ae670e1. The functions are in retail order. */

typedef struct MkVaListState {
    signed char gpr;
    signed char fpr;
    unsigned short reserved;
    char *input_arg_area;
    char *reg_save_area;
} __va_list[1];

typedef __va_list va_list;

typedef unsigned short wchar_t;

typedef u32 file_handle;

typedef u32 file_position;

typedef struct FileMode {
    u32 open_mode : 2;
    u32 io_mode : 3;
    u32 buffer_mode : 2;
    u32 file_kind : 3;
    u32 file_orientation : 2;
    u32 binary_io : 1;
} FileMode;

typedef union FileModeWord {
    u32 value;
    FileMode bits;
    u16 half[2];
} FileModeWord;

typedef struct FileState {
    u32 io_state : 3;
    u32 free_buffer : 1;
    u8 eof;
    u8 error;
} FileState;

typedef void (*IdleProc)(void);

typedef int (*PositionProc)(file_handle handle, file_position *position, int mode, IdleProc idle);

typedef int (*IOProc)(file_handle handle, u8 *buffer, size_t *count, IdleProc idle);

typedef int (*CloseProc)(file_handle handle);

typedef struct FILE {
    file_handle handle;
    FileModeWord mode;
    FileState state;
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
    PositionProc position_proc;
    IOProc read_proc;
    IOProc write_proc;
    CloseProc close_proc;
    IdleProc idle_proc;
    struct FILE *next_file;
} FILE;

typedef struct __OutStrCtrl {
    char *CharStr;
    size_t MaxCharCount;
    size_t CharsWritten;
} __OutStrCtrl;

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

extern FILE __files[4];

/* __ctype_map */
extern unsigned char lbl_8015B100[];

static inline int isdigit(int c) { return (int)(lbl_8015B100[(unsigned char)c] & 0x10); }

static inline int isupper(int c) { return (int)(lbl_8015B100[(unsigned char)c] & 0x80); }

int fwide(FILE *file, int mode);
void __begin_critical_region(int region);
void __end_critical_region(int region);
size_t fwrite(const void *buffer, size_t size, size_t count, FILE *file);
void *memcpy(void *dst, const void *src, size_t n);
void *memchr(const void *src, int val, size_t n);
char *strchr(const char *string, int character);
size_t strlen(const char *string);
/* strcpy */
char *strcpy(char *destination, const char *source);
int wcstombs(char *dst, const wchar_t *src, size_t n);
void *__va_arg(__va_list args, int type);

int __pformatter(void *(*WriteProc)(void *, const char *, size_t), void *WriteProcArg,
                 const char *format_str, va_list arg);
void *fn_80080974(void *pCtrl, const char *pBuffer, size_t char_num);
void *__FileWrite(void *pFile, const char *pBuffer, size_t char_num);
const char *parse_format(const char *format_string, va_list *arg, print_format *format);
char *long2str(long num, char *buff, print_format format);
char *longlong2str(long long num, char *buff, print_format format);
char *double2hex(long double num, char *buff, print_format format);
/* round_decimal */
void fn_800818C8(decimal *dec, int new_length);
char *float2str(long double num, char *buff, print_format format);

static inline int vsnprintf(char *s, size_t n, const char *format, va_list arg) {
    int end;
    __OutStrCtrl osc;
    osc.CharStr = s;
    osc.MaxCharCount = n;
    osc.CharsWritten = 0;
    end = __pformatter(&fn_80080974, &osc, format, arg);
    if (s) {
        s[(end < n) ? end : n - 1] = '\0';
    }
    return end;
}

int sprintf(char *s, const char *format, ...);

/* vsprintf */
int fn_8008077C(char *s, const char *format, va_list arg);

int vprintf(const char *format, va_list arg);

int printf(const char *format, ...);

/* __StringWrite */
void *fn_80080974(void *pCtrl, const char *pBuffer, size_t char_num);

void *__FileWrite(void *pFile, const char *pBuffer, size_t char_num);

int __pformatter(void *(*WriteProc)(void *, const char *, size_t), void *WriteProcArg,
                 const char *format_str, va_list arg);

char *float2str(long double num, char *buff, print_format format);

void fn_800818C8(decimal *dec, int new_length);

char *double2hex(long double num, char *buff, print_format format);

char *longlong2str(long long num, char *buff, print_format format);

char *long2str(long num, char *buff, print_format format);

const char *parse_format(const char *format_string, va_list *arg, print_format *format);

/* --- dol/qsort.c --- */
/* --- dol/qsort.c --- */
extern void qsort(void *base, unsigned long count, unsigned long size,
                        int (*compare)(const void *, const void *));

void qsort(void *base, size_t count, size_t size,
                 int (*compare)(const void *, const void *)) {
    size_t root;
    size_t remaining;
    size_t child;
    unsigned char *bytes = base;
    unsigned char *root_ptr;
    unsigned char *end_ptr;
    unsigned char *parent_ptr;
    unsigned char *child_ptr;
    if (count < 2)
        return;
    remaining = count;
    root = count / 2 + 1;
    root_ptr = bytes + size * (root - 1);
    end_ptr = bytes + size * (count - 1);
    for (;;) {
        if (root > 1) {
            --root;
            root_ptr -= size;
        } else {
            signed char *destination = (signed char *)(end_ptr - 1);
            signed char *source = (signed char *)(root_ptr - 1);
            size_t index;
            int temporary;
            for (index = size + 1; --index != 0;) {
                temporary = source[1];
                source[1] = destination[1];
                destination[1] = temporary;
                ++source;
                ++destination;
            }
            --remaining;
            if (remaining == 1)
                return;
            end_ptr -= size;
        }
        child = root;
        child_ptr = bytes + size * (root - 1);
        while (child * 2 <= remaining) {
            child *= 2;
            parent_ptr = child_ptr;
            child_ptr = bytes + size * (child - 1);
            if (child < remaining) {
                unsigned char *next = child_ptr + size;
                if (compare(child_ptr, next) < 0) {
                    child_ptr = next;
                    ++child;
                }
            }
            if (compare(parent_ptr, child_ptr) < 0) {
                signed char *destination = (signed char *)(child_ptr - 1);
                signed char *source = (signed char *)(parent_ptr - 1);
                size_t index;
                int temporary;
                for (index = size + 1; --index != 0;) {
                    temporary = source[1];
                    source[1] = destination[1];
                    destination[1] = temporary;
                    ++source;
                    ++destination;
                }
            } else {
                break;
            }
        }
    }
}
