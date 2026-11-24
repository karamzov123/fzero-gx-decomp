#include "types.h"


/* --- dol/fn_8007F48C.c --- */
extern void __begin_critical_region(int region);
extern int fn_8007F13C(int arg0, int arg1, int arg2, int arg3);
extern void __end_critical_region(int region);

int fn_8007F48C(int arg0, int arg1, int arg2, int arg3) {
    u32 result;

    __begin_critical_region(2);
    result = fn_8007F13C(arg0, arg1, arg2, arg3);
    __end_critical_region(2);
    return result;
}
