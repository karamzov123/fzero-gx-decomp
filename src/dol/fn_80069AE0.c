#include "types.h"


/* --- dol/fn_80069AE0.c --- */
extern u32 lbl_801A6C80;
extern u32 fn_8006953C(void);

u32 fn_80069AE0(void) {
    u32 flags;

    flags = *(u32 *)(lbl_801A6C80 + 0x444);
    if ((flags & 0x40) == 0) {
        return fn_8006953C();
    }
    return flags;
}

/* --- dol/fn_80069B10.c --- */
extern void fn_80020ABC(u32);
extern u32 fn_80026D70(void *);
extern void fn_80023168(void *, u16);
extern void fn_80028424(void *);

void fn_80069B10(u32 arg0, u32 arg1) {
    u8 i;
    u8 kind;

    for (i = 0; i < 64; i++) {
        if (arg0 + 0x60000000 == 0x500) {
            if (*((u8 *)lbl_801A6C80 + i * 280 + 0x1408) == 4) {
                fn_80023168((void *)*(u32 *)((u8 *)lbl_801A6C80 + i * 280 + 0x1434), 0);
                fn_80026D70((void *)*(u32 *)(lbl_801A6C80 + i * 280 + 0x1434));
                fn_80020ABC(*(u32 *)(lbl_801A6C80 + i * 280 + 0x1434));
                *(u32 *)((u8 *)lbl_801A6C80 + i * 280 + 0x1434) = 0;
                fn_80028424((void *)(lbl_801A6C80 + i * 280 + 0x1438));
                if (*((u8 *)lbl_801A6C80 + i * 280 + 0x1408) != 0xFF) {
                    *(u8 *)((u8 *)lbl_801A6C80 + i * 280 + 0x1408) = 0xFF;
                    *(u32 *)((u8 *)lbl_801A6C80 + i * 280 + 0x1420) = 0;
                    *(u8 *)((u8 *)lbl_801A6C80 + i * 280 + 0x1409) = 0;
                    *(u32 *)((u8 *)lbl_801A6C80 + i * 280 + 0x1430) = 0;
                }
            }
        } else if (arg0 + 0x60000000 == 0x1500) {
            if (*((u8 *)lbl_801A6C80 + i * 280 + 0x1408) == 4) {
                kind = *((u8 *)lbl_801A6C80 + i * 280 + 0x1413);
                if (kind == (s32)(arg1 & 0xF)) {
                    fn_80023168((void *)*(u32 *)((u8 *)lbl_801A6C80 + i * 280 + 0x1434), 0);
                    fn_80026D70((void *)*(u32 *)(lbl_801A6C80 + i * 280 + 0x1434));
                    fn_80020ABC(*(u32 *)(lbl_801A6C80 + i * 280 + 0x1434));
                    *(u32 *)((u8 *)lbl_801A6C80 + i * 280 + 0x1434) = 0;
                    fn_80028424((void *)(lbl_801A6C80 + i * 280 + 0x1438));
                    if (*((u8 *)lbl_801A6C80 + i * 280 + 0x1408) != 0xFF) {
                        *(u8 *)((u8 *)lbl_801A6C80 + i * 280 + 0x1408) = 0xFF;
                        *(u32 *)((u8 *)lbl_801A6C80 + i * 280 + 0x1420) = 0;
                        *(u8 *)((u8 *)lbl_801A6C80 + i * 280 + 0x1409) = 0;
                        *(u32 *)((u8 *)lbl_801A6C80 + i * 280 + 0x1430) = 0;
                    }
                }
            }
        }
    }
}
