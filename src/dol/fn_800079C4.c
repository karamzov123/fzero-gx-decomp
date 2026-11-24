#include "types.h"


/* --- dol/fn_800079C4.c --- */
/* --- dol/fn_800079C4.c --- */
extern u32 fn_80007654(u32);

u32 fn_800079C4(u32 arg0) {
    u32 t0;
    t0 = fn_80007654(arg0);
    return ((((arg0 >> 12) & 0xFFFF) ^ (t0 & 0x7FFFF)) << 6);
}

/* --- dol/fn_80007A00.c --- */

u32 fn_80007A00(u32 value) {
    s32 result;

    result = fn_80007654(value);
    result = ((((value >> 12) & 0xffff) ^ (result & 0x7ffff)) << 6);
    return (result ^ 0x01ff0000) ^ 0xffc0;
}
