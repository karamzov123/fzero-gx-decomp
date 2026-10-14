/* Non-matching: best partial attempt (47.99% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct FnFlags {
    u8 pad[0x98];
    u32 flags;
};
struct FnObj {
    u8 pad0[0x92];
    s16 mode;
    u8 pad1[0x98];
    s16 values[8];
};
extern struct FnFlags lbl_1_bss_8B3A0;
extern u8 lbl_1_bss_9C8[];
extern u8 lbl_1_bss_9F8[];
extern u32 lbl_801A66A8;
extern void fn_1_12F128(s16);
extern u32 fn_1_13FA88(s16);
extern void fn_1_12F150(s16, u32, u32);
extern void fn_1_A2D84(u32);

s32 fn_10_5E94(struct FnObj *obj) {
    s32 delta = 0;
    s32 result = 0;
    s16 i;
    s16 oldMode;
    s16 x;
    u16 left;
    u16 right;

    for (i = 0; i < 4; i++) {
        u16 *buttons = (u16 *)(lbl_1_bss_9F8 + i * 0x14 + 0x10);
        if ((s8)lbl_1_bss_9C8[i * 12 + 10] != -1 &&
            ((lbl_1_bss_8B3A0.flags << ((i + 1) & 31)) & 0x80000000)) {
            if ((buttons[0] & 8) || (buttons[1] & 8))
                delta--;
            if ((buttons[0] & 4) || (buttons[1] & 4))
                delta++;
            left = buttons[0];
            right = buttons[1];
            if ((left & 4) || (right & 4))
                fn_1_12F128(i);
            else if ((left & 8) || (right & 8))
                fn_1_12F128(i);
        }
    }

    oldMode = obj->mode;
    if (delta != 0) {
        x = delta;
        do {
            s32 next = obj->mode + x;
            if (next > 8)
                next = 0;
            else if (next < 0)
                next = 8;
            obj->mode = next;
        } while (fn_1_13FA88(obj->mode) != 0);
    }
    if (oldMode != obj->mode) {
        fn_1_A2D84(0xA9010000);
        lbl_801A66A8 = 0;
    }

    delta = 0;
    if (obj->mode == 8) {
        for (i = 0; i < 4; i++) {
            u16 b = *(u16 *)(lbl_1_bss_9F8 + i * 0x14 + 8);
            if ((s8)lbl_1_bss_9C8[i * 12 + 10] != -1 &&
                ((lbl_1_bss_8B3A0.flags >> ((i + 1) & 31)) & 1)) {
                if (b & 0x200) delta--;
                if (b & 0x100) delta = (s16)(delta + 1);
                if (b & 0x100)
                    fn_1_12F150(i, 9, 1);
                else if (b & 0x200)
                    fn_1_12F150(i, 9, 0);
            }
        }
        if (delta != 0)
            fn_1_A2D84(0xA9010100);
        result = delta;
    } else {
        s32 vertical = 0;
        for (i = 0; i < 4; i++) {
            u16 b = *(u16 *)(lbl_1_bss_9F8 + i * 0x14 + 8);
            if ((s8)lbl_1_bss_9C8[i * 12 + 10] != -1 &&
                ((lbl_1_bss_8B3A0.flags >> ((i + 1) & 31)) & 1)) {
                if (b & 0x200) vertical--;
                if (b & 0x100) vertical = (s16)(vertical + 1);
                if (b & 0x100)
                    fn_1_12F150(i, 9, 1);
                else if (b & 0x200)
                    fn_1_12F150(i, 9, 0);
            }
        }
        if ((s16)vertical < 0) {
            result = -1;
            fn_1_A2D84(0xA9010200);
        } else if ((s16)vertical > 0) {
            obj->mode = 8;
            fn_1_A2D84(0xA9010100);
        }
        for (i = 0; i < 4; i++) {
            u16 *buttons = (u16 *)(lbl_1_bss_9F8 + i * 0x14 + 0x10);
            u16 left = buttons[0];
            u16 right = buttons[1];
            if ((s8)lbl_1_bss_9C8[i * 12 + 10] != -1 &&
                ((lbl_1_bss_8B3A0.flags >> ((i + 1) & 31)) & 1)) {
                if ((left & 1) || (right & 1)) delta--;
                if ((left & 2) || (right & 2)) delta++;
                if ((left & 2) || (right & 2))
                    fn_1_12F128(i);
                else if ((left & 1) || (right & 1))
                    fn_1_12F128(i);
            }
        }
        oldMode = obj->mode;
        switch (oldMode) {
        case 0: x = 0; break;
        case 1: x = 1; break;
        case 2: x = 2; break;
        case 3: x = 3; break;
        case 4: x = 4; break;
        case 5: x = 5; break;
        case 6: x = 6; break;
        case 7: x = 7; break;
        default: x = 0; break;
        }
        switch (x) {
        case 0: {
            s16 old = obj->values[0]; s32 v = old + (s16)delta;
            obj->values[0] = v > 29 ? 0 : (v < 0 ? 29 : v);
            if (old != obj->values[0]) { fn_1_A2D84(0xA9010000); lbl_801A66A8 = 0; }
            break;
        }
        case 1: case 3: case 6: case 7: {
            int index = x == 1 ? 1 : x == 3 ? 3 : x == 6 ? 6 : 7;
            s16 old = obj->values[index]; s32 v = old + (s16)delta;
            obj->values[index] = v > 1 ? 0 : (v < 0 ? 1 : v);
            if (old != obj->values[index]) { fn_1_A2D84(0xA9010000); lbl_801A66A8 = 0; }
            break;
        }
        case 2: case 5: {
            int index = x == 2 ? 5 : 4;
            s16 old = obj->values[index]; s32 v = old + (s16)delta;
            obj->values[index] = v > 1 ? 0 : (v < 0 ? 1 : v);
            if (old != obj->values[index]) { fn_1_A2D84(0xA9010000); lbl_801A66A8 = 0; }
            break;
        }
        case 4: {
            s16 old = obj->values[2]; s32 v = old + (s16)delta;
            obj->values[2] = v > 1 ? 0 : (v < 0 ? 1 : v);
            if (old != obj->values[2]) { fn_1_A2D84(0xA9010000); lbl_801A66A8 = 0; }
            break;
        }
        }
        if (oldMode != obj->mode) {
            fn_1_A2D84(0xA9010000);
            lbl_801A66A8 = 0;
        }
    }
    return result;
}
