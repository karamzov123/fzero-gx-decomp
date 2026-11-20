#include "types.h"
#include "dol/globals.h"

extern void fn_80063F38(void *arg0, u32 arg1);

struct fn_8006413C_lbl_801A6C80_T {
    u32 unk_0;
    u8 pad_4[0xC];
};

void fn_8006413C(void *arg0) {
    u32 i;

    i = 0;
    while ((i & 0xFF) < 0x10) {
        if (*(u32 *)(lbl_801A6C80 + (((u8)i) << 4)) + 0x10000 != 0xFFFF) {
            fn_80063F38(arg0, i);
        }
        i++;
    }
}
