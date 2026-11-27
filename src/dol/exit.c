#include "types.h"


/* --- dol/fn_80079FA8.c --- */
extern u32 lbl_801A6410;
extern char lbl_80094E48[54];
extern void OSReport(const char *, ...);
extern char lbl_80094E80[57];
extern u32 OSGetArenaLo(void);
extern u32 OSGetArenaHi(void);
extern u32 fn_80008EC8(u32, u32, u32);
extern u32 OSSetArenaLo(u32);
extern u32 fn_80008F60(u32, u32);
extern u32 fn_80008E84(void);
extern u32 fn_80008E34(u32, u32);

void fn_80079FA8(u32 arg0);

/* --- dol/exit.c --- */
typedef void (*ExitFunction)(void);

void __begin_critical_region(int region);

void __end_critical_region(int region);

void __kill_critical_regions(void);

extern void __destroy_global_chain(void);

extern void _ExitProcess(void);

extern ExitFunction _dtors[];

ExitFunction __atexit_funcs[64] __attribute__((aligned(8)));

extern ExitFunction __console_exit;

extern ExitFunction __stdio_exit;

extern int __atexit_curr_func;

extern int __aborting;

void exit(int status) {
    ExitFunction *destructor;
    if (!__aborting) {
        __begin_critical_region(0);
        __end_critical_region(0);
        __destroy_global_chain();
        destructor = _dtors;
        while (*destructor != 0) {
            (*destructor)();
            ++destructor;
        }
        if (__stdio_exit != 0) {
            __stdio_exit();
            __stdio_exit = 0;
        }
    }
    __begin_critical_region(0);
    while (__atexit_curr_func > 0)
        __atexit_funcs[--__atexit_curr_func]();
    __end_critical_region(0);
    __kill_critical_regions();
    if (__console_exit != 0) {
        __console_exit();
        __console_exit = 0;
    }
    _ExitProcess();
}
