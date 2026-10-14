/* Non-matching: best partial attempt (79.87% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_3_5070_lbl_3_bss_0 {
    u8 pad_0[0x18];
    s16 unk_18;
    u8 pad_1A[3];
    u8 unk_1D;
};

extern struct fn_3_5070_lbl_3_bss_0 lbl_3_bss_0;
extern u32 fn_3_0(u32, u32);
extern u32 lbl_1_bss_9F8;
extern u32 lbl_3_bss_140;
extern u32 lbl_3_rodata_19C[2];
extern u8 lbl_3_bss_6DD74;
extern void fn_1_A2D84(u32);
extern void fn_3_BD00(u32, u32, u32, u32);

s32 fn_3_5070(void) {
    struct fn_3_5070_lbl_3_bss_0 *p = &lbl_3_bss_0;
    s16 mode, index;
    s32 result = 0;
    s32 direction, saved, next, limit;
    s32 buttons;
    u32 key;
    s32 i;
    s16 *vals;
    u32 *record;

    index = *(s16 *)((u8 *)p + 0xF0 + 6);
    {
        s32 count = p->unk_18 + 1;
        s32 timer = 10;
        if (count < 10)
            timer = count;
        p->unk_18 = timer;
    }
    mode = *(s16 *)((u8 *)p + 0xF0 + 0xC);

    switch (mode) {
    case 0:
        record = (u32 *)((u8 *)&lbl_1_bss_9F8 + index * 20);
        buttons = 0;
        if ((*(u16 *)((u8 *)record + 0x10) & 1) ||
            (*(u16 *)((u8 *)record + 0x12) & 1))
            buttons = -1;
        if (((*(u16 *)record >> 1) & 1) ||
            ((*(u16 *)((u8 *)record + 0x12) >> 1) & 1))
            buttons++;
        direction = buttons;
        saved = -1;
        if ((s16)direction != 0) {
            fn_1_A2D84(0xA9010000);
            vals = (s16 *)((u8 *)p + 0xF0);
            saved = vals[4];
            next = saved + (s16)direction;
            if (next > 3)
                next = 0;
            else if (next < 0)
                next = 3;
            vals[4] = next;
        }
        vals = (s16 *)((u8 *)p + 0xF0);
        fn_3_0(vals[4], 1);
        if ((s16)saved != -1) {
            u32 anglewords[2];
            s16 low, high;
            anglewords[0] = lbl_3_rodata_19C[0];
            anglewords[1] = lbl_3_rodata_19C[1];
            low = ((s16 *)anglewords)[vals[4]] * 90;
            high = ((s16 *)anglewords)[saved] * 90;
            if ((s16)direction < 0 && high < low)
                high += 360;
            if ((s16)direction > 0 && high > low)
                low += 360;
            i = direction * 5;
            fn_3_BD00(i, high, low, 0x40000000);
            result = 0;
        } else {
            record = (u32 *)((u8 *)&lbl_1_bss_9F8 + index * 20);
            key = *(u16 *)((u8 *)record + 8);
            if ((key >> 8) & 1) {
                mode = *(s16 *)((u8 *)p + 0xF0 + 0xC);
                *(s16 *)((u8 *)p + 0xF0 + 0xC) = mode + 1;
                fn_1_A2D84(0xA9010100);
                fn_3_BD00(1, 0, 16, 0x20000000);
            } else if ((key >> 9) & 1) {
                fn_1_A2D84(0xA9010200);
                result = -1;
            }
        }
        break;
    case 1:
        key = (u32)(*(s16 *)((u8 *)p + 0xF0 + 8) * (0x10000 - 0x7E40));
        key = *(u32 *)((u8 *)&lbl_3_bss_140 + key);
        if ((key & 0x80000000) == 0) {
            direction = 0;
            limit = 1;
        } else {
            direction = 0;
            limit = 3;
            if (key & 0x40000000)
                direction = 2;
        }
        vals = (s16 *)((u8 *)p + 0xF0 + 0xE);
        next = vals[mode];
        if (next < direction)
            next = direction;
        else if (next > limit)
            next = limit;
        vals[mode] = next;

        record = (u32 *)((u8 *)&lbl_1_bss_9F8 + index * 20);
        i = 0;
        if ((*(u16 *)((u8 *)record + 0x10) & 1) ||
            (*(u16 *)((u8 *)record + 0x12) & 1))
            i = -1;
        if (((*(u16 *)record >> 1) & 1) ||
            ((*(u16 *)((u8 *)record + 0x12) >> 1) & 1))
            i++;
        buttons = vals[*(s16 *)((u8 *)p + 0xF0 + 0xC)] + (s16)i;
        next = vals[*(s16 *)((u8 *)p + 0xF0 + 0xC)];
        if (buttons < direction) {
        } else {
            if (buttons > limit)
                buttons = limit;
            next = buttons;
        }
        vals[*(s16 *)((u8 *)p + 0xF0 + 0xC)] = next;
        if (vals[*(s16 *)((u8 *)p + 0xF0 + 0xC)] != direction)
            fn_1_A2D84(0xA9010000);

        record = (u32 *)((u8 *)&lbl_1_bss_9F8 + index * 20);
        key = *(u16 *)((u8 *)record + 8);
        if ((key >> 8) & 1) {
            key = (u32)(*(s16 *)((u8 *)p + 0xF0 + 8) * (0x10000 - 0x7E40));
            key = *(u32 *)((u8 *)&lbl_3_bss_140 + key);
            if ((key & 0x80000000) == 0) {
                switch (vals[*(s16 *)((u8 *)p + 0xF0 + 0xC)]) {
                case 0: result = 1; break;
                case 1: result = 2; break;
                }
            } else {
                switch (vals[*(s16 *)((u8 *)p + 0xF0 + 0xC)]) {
                case 0: result = 3; break;
                case 1: result = 4; break;
                case 2: result = 5; break;
                case 3:
                    p->unk_1D = 0;
                    result = 6;
                    lbl_3_bss_6DD74 = 1;
                    break;
                }
                *(s16 *)((u8 *)p + 0xF0 + 0xC) = 0;
            }
            fn_1_A2D84(0xA9010100);
        } else if ((key >> 9) & 1) {
            mode = *(s16 *)((u8 *)p + 0xF0 + 0xC);
            *(s16 *)((u8 *)p + 0xF0 + 0xC) = mode - 1;
            fn_1_A2D84(0xA9010200);
            fn_3_BD00(1, 0, 16, 0x10000000);
        }
        break;
    }
    return result;
}
