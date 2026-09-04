typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct {
    char gpr;
    char fpr;
    char reserved[2];
    char* input_arg_area;
    char* reg_save_area;
} __va_list[1];
typedef __va_list va_list;

extern void __builtin_va_info(void*);
#define va_start(ap, fmt) ((void) fmt, __builtin_va_info(&ap))
#define va_end(ap) (void) 0


typedef unsigned long size_t;

typedef struct {
    char* CharStr;
    size_t MaxCharCount;
    size_t CharsWritten;
} __OutStrCtrl;

#pragma force_active on

// MSL stdio tail 0x8008067C-0x800807F4 (__stdio_atexit, vfprintf-ish wrappers)

extern int __pformatter(void* pFunc, void* pCtrl, const char* format, va_list arg);
extern void __close_all(void);
extern void* __StringWrite(void* pCtrl, const char* pBuffer, size_t char_num);

extern unsigned char __stdio_exit[4];
// provenance: original
// harvested 2026-08-26 from hard's logged 100% attempt; spliced into the current head
void __stdio_atexit(void) { *(void (**)(void))__stdio_exit = __close_all; }

// provenance: original
// harvested 2026-08-26 from hard's logged 100% attempt; spliced into the current head
void fn_8008068C(unsigned char* p) { p[9] = 0; p[10] = 0; }

static inline int vsnprintf(char* s, size_t n, const char* format, va_list arg)
{
    int end;
    __OutStrCtrl osc;
    osc.CharStr = s;
    osc.MaxCharCount = n;
    osc.CharsWritten = 0;

    end = __pformatter(&__StringWrite, &osc, format, arg);
    if (s != 0) {
        s[(end < n) ? end : n - 1] = 0;
    }
    return end;
}

// 0x80080698 | size: 0x70
// provenance: melee:src/MSL/printf.c:1086
int sprintf(char* s, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    return vsnprintf(s, (size_t)-1, format, args);
}



// provenance: melee:src/MSL/printf.c
int fn_8008077C(char* s, const char* format, va_list arg)
{
    return vsnprintf(s, (size_t)-1, format, arg);
}

#pragma force_active off
