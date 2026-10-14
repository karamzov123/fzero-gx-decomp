/* Non-matching: best partial attempt (0.00% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 lbl_801A6C80;
extern u8 lbl_80092C38[];
extern u8 lbl_801A6608[];
extern void fn_800692A4(u32);
extern u32 fn_80068EB4(void);

u32 fn_8006953C(u32 arg0) {
    u8 *base;
    u32 selector;
    u32 slot;
    u32 i;
    u32 j;
    u32 key;
    u32 entry;
    u32 value;
    u32 offset;
    u32 temp;

    base = (u8 *)lbl_801A6C80;
    if ((arg0 >> 24) == 0xA0) {
        selector = arg0 & 0x00FF0000;
        if (selector == 0) {
            fn_800692A4(arg0);
        } else if (selector == 0x20000) {
            key = arg0 & 0xF;
            for (i = 0; i < 16; i++) {
                slot = (u32)(base + i * 40);
                if (key == *(u8 *)(slot + 0x118A) &&
                    *(u8 *)(slot + 0x1188) != 0 &&
                    (*(u8 *)(slot + 0x1189) & 0x80) == 0)
                    *(u8 *)(slot + 0x1188) |= 1;
            }
        } else if (selector == 0x30000) {
            key = arg0 & 0xF;
            for (i = 0; i < 16; i++) {
                slot = (u32)(base + i * 40);
                if (key == *(u8 *)(slot + 0x118A) &&
                    *(u8 *)(slot + 0x1188) != 0 &&
                    (*(u8 *)(slot + 0x1189) & 0x80) == 0)
                    *(u8 *)(slot + 0x1188) &= 0xFE;
            }
        } else if (selector == 0x90000) {
            *(u8 *)(base + 0x458) = arg0 & 0xF;
            *(u32 *)(base + 0x448) = *(u16 *)(lbl_80092C38 + (((arg0 >> 7) & 0xFE)));
        } else if (selector == 0xA0000) {
            for (i = 0; i < 16; i++) {
                slot = (u32)(base + i * 40);
                if (*(u8 *)(slot + 0x1188) != 0 &&
                    (*(u8 *)(slot + 0x1189) & 0x80) != 0 &&
                    *(u8 *)(slot + 0x118A) == (arg0 & 0xF)) {
                    *(u8 *)(slot + 0x1188) |= 6;
                    offset = i * 40 + 0x11AC;
                    value = *(u16 *)(lbl_80092C38 + (((arg0 >> 7) & 0xFE)));
                    *(u32 *)(base + offset) = value;
                    *(u32 *)(base + offset) = ~(*(u32 *)(base + offset) ^ 0xFFFFFFFF) + 1;
                }
            }
        }
        return 0xFFFFFFFF;
    }

    key = arg0 >> 16;
    slot = 0xFFFFFFFF;
    for (i = 0; i < 16; i++) {
        entry = *(u32 *)(base + i * 16 + 8);
        if (entry != 0) {
            u8 *table = (u8 *)(entry + *(u32 *)(entry + 0x24));
            u32 count = table[0];
            for (j = 0; j <= count; j++) {
                if ((*(u32 *)(table + 4 + j * 4) >> 16) == key) {
                    slot = i;
                    break;
                }
            }
            if (slot != 0xFFFFFFFF)
                break;
        }
    }
    if (slot == 0xFFFFFFFF) {
        u32 (*callback)(u32, u32) = *(u32 (**)(u32, u32))(base + 0x5B1C);
        if (callback != 0)
            return callback((u32)-3, arg0);
        return 0xFFFFFFFF;
    }
    {
        u8 *table = (u8 *)(*(u32 *)(base + slot * 16 + 8) +
                           *(u32 *)(*(u32 *)(base + slot * 16 + 8) + 0x24));
        u32 count = *(u16 *)(table + 0);
        key = (arg0 >> 8) & 0xFF;
        if (key > table[count])
            return 0xFFFFFFFF;
        value = *(u32 *)(table + key * 4 + 4);
        if (value == 0)
            return 0xFFFFFFFF;
        entry = (u32)(table + value);
    }

    value = *(u8 *)entry;
    if ((value & 0x80) == 0) {
        for (i = 0; i < 16; i++) {
            slot = (u32)(base + i * 40);
            if (*(u8 *)(slot + 0x1188) != 0 &&
                *(u8 *)(slot + 0x118A) == (s8)slot &&
                (*(u8 *)(slot + 0x1189) & 0x80) == 0) {
                value = i;
                break;
            }
        }
    } else if ((value & 0x10) == 0x10) {
        key = value & 0xF;
        for (i = 0; i < 16; i++) {
            slot = (u32)(base + i * 40);
            if (*(u8 *)(slot + 0x1188) != 0 &&
                (*(u8 *)(slot + 0x1189) & 0xF) == key) {
                value = i;
                break;
            }
        }
    }

    if (value == 0x7F) {
        for (i = 0; i < 16; i++) {
            if (*(u8 *)(base + i * 40 + 0x1188) == 0) {
                value = i;
                break;
            }
        }
    }
    if (value == 0x7F) {
        for (i = 0; i < 16; i++) {
            if (*(u8 *)(base + i * 40 + 0x1189) & 0x80) {
                value = i;
                break;
            }
        }
    }
    slot = value * 40;
    *(u8 *)(base + slot + 0x118A) = (u8)slot;
    *(u32 *)(base + slot + 0x118C) = 0x10000;
    *(u32 *)(base + slot + 0x1190) = arg0;
    *(u32 *)(base + slot + 0x1194) = 0;
    *(u8 *)(base + slot + 0x1189) = *(u8 *)entry;
    if ((*(u8 *)(base + slot + 0x1189) & 0x80) == 0) {
        *(u8 *)(base + slot + 0x1188) = 0x90;
        *(u32 *)(base + slot + 0x1198) = entry;
        *(u32 *)(base + slot + 0x119C) = entry + 4;
        *(u32 *)(base + slot + 0x11A0) = (u32)lbl_801A6608;
        if (*(u32 *)(base + 0x448) == 0) {
            *(u32 *)(base + slot + 0x11A4) = 0x7F0000;
            *(u32 *)(base + slot + 0x11A8) = 0x7F0000;
        } else if (*(u8 *)(base + 0x458) == (s8)slot) {
            *(u32 *)(base + slot + 0x11AC) = *(u32 *)(base + 0x448);
            *(u32 *)(base + slot + 0x11A4) = 0;
            *(u32 *)(base + slot + 0x11A8) = 0;
            *(u8 *)(base + slot + 0x1188) ^= 0x98;
            *(u32 *)(base + 0x448) = 0;
        } else {
            *(u32 *)(base + slot + 0x11A4) = 0x7F0000;
            *(u32 *)(base + slot + 0x11A8) = 0x7F0000;
        }
    } else {
        *(u8 *)(base + slot + 0x1188) = 0x80;
        *(u32 *)(base + slot + 0x119C) = 0xFF000000;
        *(u32 *)(base + slot + 0x11A0) = entry + 1;
    }
    return fn_80068EB4();
}
