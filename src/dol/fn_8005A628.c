#include "types.h"
#pragma opt_propagation off

/* --- dol/fn_8005A588.c --- */
extern u32 lbl_80190178[];
extern u32 lbl_8019017C[];

void fn_8005A588(u32 arg0, u32 arg1);

/* --- dol/fn_8005A59C.c --- */
void fn_8005A59C(void);

/* --- dol/fn_8005A5A8.c --- */
/* --- dol/fn_8005A5A8.c --- */
// The retail code performs this read even though its value is discarded.
extern volatile u32 lbl_80092528[36];
extern u8 lbl_801324F0[104];

u8 *fn_8005A5A8(void);

/* --- dol/fn_8005A5BC.c --- */
typedef void (*fn_8005A5BC_Fn0)(u32, u32);
struct fn_8005A5BC_lbl_80190B70 {
    u32 unk_0;
    u32 unk_4;
    char buffer[1];
};

extern u32 lbl_80190B70[];
extern void strncpy(void *, void *, int);

void fn_8005A5BC(u32 arg0);

/* --- dol/fn_8005A614.c --- */
extern u32 lbl_80190B74[];

void fn_8005A614(u32 arg0, u32 arg1);

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
