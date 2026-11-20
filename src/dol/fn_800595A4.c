#include "types.h"

typedef void (*fn_800595A4_Fn0)(u32, void *);
struct fn_800595A4_lbl_8018FF60 {
    u32 unk_0;
    u32 unk_4;
};

extern struct fn_800595A4_lbl_8018FF60 lbl_8018FF60[];
extern u8 lbl_8018FEE0[];
extern void strncpy(void *, void *, int);

void fn_800595A4(u32 arg0) {
    strncpy(&lbl_8018FEE0, (void *)arg0, 127);
    if (lbl_8018FF60[0].unk_0 != 0) {
        ((fn_800595A4_Fn0)lbl_8018FF60[0].unk_0)(
            lbl_8018FF60[0].unk_4, &lbl_8018FEE0);
    }
}
