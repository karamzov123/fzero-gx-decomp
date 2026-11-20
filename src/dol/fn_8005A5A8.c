#include "types.h"


/* --- dol/fn_8005A5A8.c --- */
// The retail code performs this read even though its value is discarded.
extern volatile u32 lbl_80092528[36];
extern u8 lbl_801324F0[104];

u8 *fn_8005A5A8(void) {
    lbl_80092528[0];
    return lbl_801324F0;
}

/* --- dol/fn_8005A5BC.c --- */
typedef void (*fn_8005A5BC_Fn0)(u32, u32);
struct fn_8005A5BC_lbl_80190B70 {
    u32 unk_0;
    u32 unk_4;
    char buffer[1];
};

extern u32 lbl_80190B70[];
extern void strncpy(void *, void *, int);

void fn_8005A5BC(u32 arg0) {
    struct fn_8005A5BC_lbl_80190B70 *p_lbl_80190B70;

    p_lbl_80190B70 = (struct fn_8005A5BC_lbl_80190B70 *)&lbl_80190B70;
    strncpy((void *)((u8 *)p_lbl_80190B70 + 8), (void *)arg0, 255);
    if (p_lbl_80190B70->unk_0 != 0) {
        ((fn_8005A5BC_Fn0)p_lbl_80190B70->unk_0)(
            p_lbl_80190B70->unk_4, (u32)((u8 *)(u32)p_lbl_80190B70 + 8));
    }
}

/* --- dol/fn_8005A614.c --- */
extern u32 lbl_80190B74[];

void fn_8005A614(u32 arg0, u32 arg1) {
    lbl_80190B70[0] = arg0;
    lbl_80190B74[0] = arg1;
}

/* --- dol/fn_8005A628.c --- */
extern u32 fn_800576DC(void);

void fn_8005A628(void) {
    fn_800576DC();
}

/* --- dol/fn_8005A648.c --- */
extern u32 fn_80057728(void);

void fn_8005A648(void) {
    fn_80057728();
}
