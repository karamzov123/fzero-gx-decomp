#include "types.h"


/* --- dol/fn_800068F4.c --- */
extern u32 lbl_801A66E8;

u32 fn_800068F4(u32 value) {
    u32 old_value = lbl_801A66E8;
    lbl_801A66E8 = value;
    return old_value;
}

/* --- dol/fn_80006904.c --- */
extern u32 lbl_801A66E4;

u32 fn_80006904(u32 arg0) {
    u32 v0;
    v0 = lbl_801A66E4;
    lbl_801A66E4 = arg0;
    return v0;
}

/* --- dol/fn_80006914.c --- */
extern u32 lbl_801A66E0;

void fn_80006914(u32 arg0) {
    lbl_801A66E0 = arg0;
}
