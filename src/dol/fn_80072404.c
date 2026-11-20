#include "types.h"


/* --- dol/fn_80072404.c --- */
extern u32 lbl_8015ACBC[21];
extern u32 lbl_8015AC68[21];

u32 fn_80072404(u32 mask, s32 select) {
    u32 *a = lbl_8015ACBC;
    u32 *b = lbl_8015AC68;
    u32 total = 0;
    int i;

    for (i = 0; i < 17; i++) {
        if (mask & 1) {
            if (select != 0) {
                total += *a;
            } else {
                total += *b;
            }
        }
        mask >>= 1;
        a = a + 1;
        b++;
    }
    return total;
}

/* --- dol/fn_8007245C.c --- */
extern u32 lbl_801A6D28;
extern void GXClearVtxDesc(u32 value);
extern void GXSetVtxDesc(u32 index, u32 value);

void fn_8007245C(u32 value) {
    u32 index;

    if (value != lbl_801A6D28) {
        GXClearVtxDesc(value);
        lbl_801A6D28 = value;
        index = 0;
        while (index < 0x1a) {
            if (value & 1) {
                GXSetVtxDesc(index, 1);
            }
            index++;
            value >>= 1;
        }
    }
}
