#include "types.h"


/* --- dol/fn_80070704.c --- */
extern u8 lbl_801A6CEA;
extern u8 lbl_8012AFF4[60];
extern u8 lbl_8012AFB8[60];
extern void fn_80034ECC(u8, u8 *, u32, u8 *);

void fn_80070704(s32 arg0) {
    struct { u8 *value; } table;

    if (arg0 == lbl_801A6CEA) {
        return;
    }
    lbl_801A6CEA = arg0;
    table.value = lbl_8012AFF4;
    if ((arg0 & 0xff) != 0) {
        table.value = lbl_8012AFB8;
    }
    fn_80034ECC(table.value[0x19], table.value + 0x1a, 1, table.value + 0x32);
}

/* --- dol/fn_8007075C.c --- */
extern u32 lbl_801A6CE0;

void fn_8007075C(u32 arg0) {
    if ((s32)arg0 == 0) { return; }
    lbl_801A6CE0 = (lbl_801A6CE0 | 48);
}
