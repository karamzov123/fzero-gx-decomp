#include "types.h"


extern u32 lbl_80190178[];
extern u32 lbl_8019017C[];

void fn_8005A588(u32 arg0, u32 arg1);

void fn_8005A59C(void);

// The retail code performs this read even though its value is discarded.
extern volatile u32 lbl_80092528[36];
extern u8 lbl_801324F0[104];

u8 *fn_8005A5A8(void);

typedef void (*fn_8005A5BC_Fn0)(u32, u32);
struct fn_8005A5BC_lbl_80190B70 {
    u32 unk_0;
    u32 unk_4;
    char buffer[1];
};

extern u32 lbl_80190B70[];
extern void strncpy(void *, void *, int);

void fn_8005A5BC(u32 arg0);

extern u32 lbl_80190B74[];

void fn_8005A614(u32 arg0, u32 arg1);

extern void fn_800576DC(void);

void fn_8005A628(void) {
    fn_800576DC();
}

extern u32 fn_80057728(void);

void fn_8005A648(void) {
    fn_80057728();
}
