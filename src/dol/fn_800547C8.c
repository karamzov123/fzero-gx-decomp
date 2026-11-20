#include "types.h"

typedef u32 (*fn_800547C8_Fn0)(u32, u32, u32);
typedef u32 (*fn_800547C8_Fn1)(u32);

struct fn_800547C8_lbl_80187434 {
    u32 unk_0;    u8 pad_4[0x13C];
};

extern struct fn_800547C8_lbl_80187434 lbl_80187434[];
extern char lbl_80091C80[];
extern char lbl_80091C9C[];
extern u32 lbl_80187430[];

void fn_800547C8(u32 arg0) {
    if (arg0 == 0) {
        if (lbl_80187430[0] != 0) {
            ((fn_800547C8_Fn0)lbl_80187430[0])(lbl_80187434[0].unk_0, (u32)&lbl_80091C80, 0);
        }
    } else {
        if (*(u32 *)((u8 *)*(u32 *)(arg0) + 40) != 0) {
            ((fn_800547C8_Fn1)*(u32 *)((u8 *)*(u32 *)(arg0) + 40))(*(u32 *)(arg0 + 4));
        } else {
            if (lbl_80187430[0] != 0) {
                ((fn_800547C8_Fn0)lbl_80187430[0])(lbl_80187434[0].unk_0, (u32)&lbl_80091C9C, 0);
            }
        }
    }
}
