#include "types.h"

extern u32 lbl_12_bss_7C64[137];
extern int fn_12_2F1B4(u8 *base, int index);
extern int fn_12_24990(void);
extern s32 fn_12_24A88(int, u32);

int fn_12_2D888(u8 *base, int index, int value) {
    int allowed;

    if (base == 0) {
        u32 entry;
        int i;
        u8 **p;
        int offset;

        offset = index << 2;
        p = (u8 **)((u8 *)&lbl_12_bss_7C64 + 0x204);
        for (i = 0; i < 8; i++, p++) {
            entry = (u32)*p;
            if (entry != 0) {
                if (((6) == (index)) && value == 1 &&
                    fn_12_2F1B4((u8 *)entry, 3) == 0) {
                    allowed = 0;
                } else if (index == 5 && value == 1 &&
                           fn_12_2F1B4((u8 *)entry, 2) == 0) {
                    allowed = 0;
                } else {
                    allowed = 1;
                }
                if (allowed != 0) {
                    *(int *)(offset + entry + 0x9a0) = value;
                }
            }
        }
        *(int *)((u8 *)lbl_12_bss_7C64 + offset) = value;
    } else {
        if (fn_12_24990() != 0) {
            return fn_12_24A88(0, 0xff000112);
        } else {
            if (((6) == (index)) && value == 1 &&
                fn_12_2F1B4(base, 3) == 0) {
                allowed = 0;
            } else if (index == 5 && value == 1 &&
                       fn_12_2F1B4(base, 2) == 0) {
                allowed = 0;
            } else {
                allowed = 1;
            }
            if (allowed != 0) {
                u8 *ptr = base;
                ptr += index << 2;
                *(int *)(ptr + 0x9a0) = value;
            }

            if (((6) == (index)) && value == 1 &&
                fn_12_2F1B4(base, 3) == 0) {
                allowed = 0;
            } else if (index == 5 && value == 1 &&
                       fn_12_2F1B4(base, 2) == 0) {
                allowed = 0;
            } else {
                allowed = 1;
            }
            if (allowed != 0) {
                u8 *ptr = base;
                ptr += index << 2;
                *(int *)(ptr + 0xb30) = value;
            }
        }
    }
    return 0;
}

