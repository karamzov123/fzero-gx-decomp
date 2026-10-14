/* Non-matching: best partial attempt (52.82% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/font.h"

extern f32 lbl_1_rodata_10C0;
extern f64 lbl_1_rodata_10F8;
extern f32 lbl_1_rodata_2678;
extern u32 lbl_1_bss_3E058;
extern s32 lbl_1_bss_4BA28[2];
extern u16 fn_1_499BC(const u8 *);
extern s8 fn_1_49B70(const u8 *, u32);
extern u32 fn_1_49794(u32);
extern u32 fn_1_49F08(u32, Obj_1_bss_4B9CC *, Obj_1_data_1AEA8 *);

#pragma opt_propagation off
#pragma opt_common_subs off
static inline const u8 fn_1_4B1D4_array_read(const u8 *array, s32 index) { return array[index]; }
#pragma opt_dead_assignments off
f32 fn_1_4B1D4(u32 mode, const u8 *text) {
    Obj_1_bss_4B9CC *cfg = &lbl_1_bss_4B9CC;
    Obj_1_data_1AEA8 *entry;
    f32 width = -cfg->unk_3C;
    f32 max_width = lbl_1_rodata_10C0;
    f32 result = lbl_1_rodata_10C0;
    s32 char_width = 0;
    s32 line = 1;
    s32 lines = 0;
    s32 max_lines = 0;
    s32 offset = 0;
    s32 pending = 0;
    s32 is_width = 0;
    s32 is_max = 0;
    s32 is_line_count = 0;
    s32 is_word_count = 0;
    s32 i;
    if (text == 0 && lbl_1_bss_4BA28[0] == 0) {
        lbl_1_bss_4BA28[0] = 1;
        return lbl_1_rodata_10C0;
    }
    switch (mode) {
    case 0: is_width = 1; break;
    case 1: is_width = 1; is_max = 1; break;
    case 2: is_line_count = 1; break;
    case 3: is_word_count = 1; break;
    case 4: is_word_count = 1; is_max = 1; break;
    }
    entry = (Obj_1_data_1AEA8 *)((u8 *)&lbl_1_data_1AEA8 +
             cfg->unk_C * 56);
    for (i = 0; fn_1_4B1D4_array_read(text, i) != 0; i++) {
        u32 ch = fn_1_4B1D4_array_read(text, i);
        u32 current;
        if (pending) {
            pending = 0;
            line++;
        }
        if (cfg->unk_2C & 0x20000000) {
            if ((ch & 0xffff) >= 97 && (ch & 0xffff) <= 122)
                ch -= 32;
        }
        current = ch;
        if (is_width)
            char_width = fn_1_49F08(current, cfg, entry) & 0xffff;
        if ((current & 0xffff) < 128) {
            if ((s32)entry->unk_0 == -1) {
                current = fn_1_499BC(text + i);
                ch = current;
                if (current >= 128) {
                    offset += 6;
                } else if (current == '/') {
                    s8 skip = (s8)fn_1_49B70(text + i, 0);
                    if (skip) {
                        offset += skip;
                        continue;
                    }
                } else {
                    current = fn_1_49794(current);
                    ch = current;
                }
                if (lbl_1_bss_3E058 && current == '[') {
                    while (fn_1_4B1D4_array_read(text, offset) != ']') offset++;
                    continue;
                }
                if (current == '\n') {
                    if (is_line_count) {
                        pending = 1;
                        continue;
                    }
                    if (is_max) {
                        if (is_width) {
                            if (!(max_width > width)) max_width = width;
                            width = -cfg->unk_3C;
                        } else if (is_word_count) {
                            if (max_lines > lines) max_lines = lines;
                            lines = 0;
                        }
                        continue;
                    }
                } else if (is_width) {
                    char_width = fn_1_49F08(current, cfg, entry) & 0xffff;
                }
            } else {
                if (current == '/') {
                    s8 skip = fn_1_49B70(text + i, 0);
                    if (skip) {
                        offset += skip;
                        continue;
                    }
                } else if (lbl_1_bss_3E058 && current == '[') {
                    while (fn_1_4B1D4_array_read(text, offset) != ']') offset++;
                    continue;
                } else if (current == '\n') {
                    if (is_line_count)
                        goto done;
                    if (is_max) {
                        if (is_width) {
                            if (max_width <= width) max_width = width;
                            width = -cfg->unk_3C;
                        } else if (is_word_count) {
                            if (max_lines > lines) max_lines = lines;
                            lines = 0;
                        }
                        continue;
                    }
                }
            }
        } else {
            offset++;
            current = (current << 8) | fn_1_4B1D4_array_read(text, offset);
            if (is_width)
                char_width = fn_1_49F08(current, cfg, entry) & 0xffff;
        }
        if (is_width) {
            width += cfg->unk_3C +
                     (f32)(char_width * entry->unk_34 * cfg->unk_1C);
        } else if (is_word_count) {
            lines++;
        }
    }
done:
    if (is_max) {
        if (is_width) {
            if (!(max_width > width)) max_width = width;
        } else if (is_word_count) {
            if (max_lines > lines) max_lines = lines;
        }
    }
    switch (mode) {
    case 0: result = width; break;
    case 1: result = max_width; break;
    case 2: result = (f32)line; break;
    case 3: result = (f32)lines; break;
    case 4: result = (f32)max_lines; break;
    default: result = lbl_1_rodata_2678;
    }
    return result;
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs reset

#pragma opt_propagation reset

