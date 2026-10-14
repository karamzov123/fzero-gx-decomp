/* Non-matching: best partial attempt (41.32% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/sel_static_disp.h"

extern u8 lbl_1_bss_8E598[148];
extern u8 lbl_1_bss_8E62C[132];
extern u16 lbl_1_rodata_9828[86];
extern u8 lbl_1_rodata_98D4[208];

extern void fn_80008BEC(void *, int, u32);
extern u8 *fn_80083970(u8 *, const u8 *);

void fn_1_14CEB8(struct fn_1_14CEB8_Arg0 *arg0) {
    u8 *input = (u8 *)arg0;
    u8 *data = (u8 *)&lbl_1_data_42878;
    u8 *names = (u8 *)lbl_1_rodata_9828;
    u8 *longNames = (u8 *)lbl_1_rodata_98D4;
    u32 first = 0;
    u32 i;
    u32 j;
    u32 changed = 0;
    u32 index = 0;
    u32 nameIndex = 0;
    u32 nameOffset = (u32)(longNames - names);

    if (input[0] == 0x81 && input[1] == 0x40) {
        first = 1;
        if (input[2] == 0x81 && input[3] == 0x40) {
            first = 2;
            if (input[4] == 0x81 && input[5] == 0x40) {
                first = 3;
                if (input[6] == 0x81 && input[7] == 0x40) {
                    first = 4;
                    if (input[8] == 0x81 && input[9] == 0x40) {
                        first = 5;
                        if (input[10] == 0x81 && input[11] == 0x40) {
                            first = 6;
                            if (input[12] == 0x81 && input[13] == 0x40) {
                                first = 7;
                                if (input[14] == 0x81 && input[15] == 0x40)
                                    first = 8;
                            }
                        }
                    }
                }
            }
        }
    }
    if (first == 8) {
        input[0] = 0;
        return;
    }
    if (input[first * 2] == 0x82 &&
        (input[first * 2 + 1] == 0x77 || input[first * 2 + 1] == 0x98)) {
        i = first + 1;
        changed = 1;
        while (input[i * 2] != 0) {
            if (input[i * 2] == 0x81 && input[i * 2 + 1] == 0x40)
                i++;
            else {
                changed = 0;
                break;
            }
        }
        if (changed)
            goto update;
    }

    fn_80008BEC(lbl_1_bss_8E598, 1, 0x91);
    fn_80008BEC(lbl_1_bss_8E62C, 1, 0x82);
    for (i = 0; i < 8 && input[i * 2] != 0; i++) {
        u8 *pairs = data + 0x450;
        int found = 0;
        if (input[i * 2] == 0x81 && input[i * 2 + 1] == 0x40) {
            index++;
            nameIndex++;
            continue;
        }
        for (j = 0; j < 9; j++) {
            if ((input[i * 2] == pairs[j * 2] &&
                 input[i * 2 + 1] == pairs[j * 2 + 1])) {
                found = 1;
                break;
            }
        }
        if (!found) {
            u8 *flags = lbl_1_bss_8E598;
            u32 *offsets = (u32 *)(data + 0x13b8);
            for (j = 0; j < 0x91; j++) {
                if (flags[j]) {
                    u32 off = offsets[j];
                    u8 pair[2];
                    pair[0] = names[off];
                    pair[1] = names[off + 1];
                    if (fn_80083970(pair, names) == 0) {
                        if (input[i * 2] != names[off] ||
                            input[i * 2 + 1] != names[off + 1])
                            flags[j] = 0;
                    } else {
                        u8 *match = fn_80083970(pair, names) + nameOffset;
                        if ((input[i * 2] != names[off] ||
                             input[i * 2 + 1] != names[off + 1]) &&
                            (input[i * 2] != match[0] ||
                             input[i * 2 + 1] != input[i * 2 + 1]))
                            flags[j] = 0;
                    }
                    if (names[off + 2] == 0 && flags[j]) {
                        changed = 1;
                        goto update;
                    }
                }
            }
            {
                u8 *flags2 = lbl_1_bss_8E62C;
                u32 *offsets2 = (u32 *)(data + 0xb98);
                for (j = 0; j < 0x82; j++) {
                    if (flags2[j]) {
                        u32 off = offsets2[j];
                        u8 value = (u8)index;
                        u8 a = value < 0x40 ? (u8)(value + 0x1f) : (u8)(value - 1);
                        u8 b = value < 0x40 ? (u8)(value + 0x1f) : (u8)(value + 0x20);
                        u8 cur = input[i * 2];
                        if (cur == 0x82 && input[i * 2 + 1] == a) {
                        } else if (cur == 0x82 && input[i * 2 + 1] == b) {
                        } else {
                            flags2[j] = 0;
                        }
                        if (input[index + 1] == 0 && flags2[j]) {
                            changed = 1;
                            goto update;
                        }
                    }
                }
            }
        }
        index++;
        nameIndex++;
    }
    if (index == 8) {
        for (j = 0; j < 0x91; j++)
            if (lbl_1_bss_8E598[j]) {
                changed = 1;
                goto update;
            }
        for (j = 0; j < 0x82; j++)
            if (lbl_1_bss_8E62C[j]) {
                changed = 1;
                goto update;
            }
    }
update:
    if (changed) {
        if (input[0] != 0) {
            for (i = 0; i < 8; i++) {
                if (input[i * 2] == 0)
                    break;
                input[i * 2] = 0x81;
                input[i * 2 + 1] = 0x96;
            }
        }
        return;
    }
}
