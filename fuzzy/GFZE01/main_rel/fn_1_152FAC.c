/* Non-matching: best partial attempt (36.39% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_aur.h"

typedef struct {
    s16 id;
    u16 pad;
    u32 flags;
} Fn152FACEntry;

s32 fn_1_152FAC(s16 index, s16 key, s16 vertical, s16 horizontal,
                Fn152FACEntry *entries, s16 width, s16 height) {
    s16 row = 0;
    s16 col = 0;
    s16 found_row;
    s16 found_col;
    s16 result = key;
    s16 x;
    s16 y;
    s16 candidate;
    s16 steps;
    s16 left;
    s16 right;
    s16 start;
    s16 dx;
    s16 dy;
    s16 mode;
    s32 cell;
    u32 flags;
    s16 offset;
    Obj_1_bss_8B3A0 *state = &lbl_1_bss_8B3A0;

    mode = state->unk_94 & 0x20000;
    if (key != -1) {
        for (row = 0; row < width; row++) {
            for (col = 0; col < height; col++) {
                cell = row * height + col;
                flags = entries[cell].flags;
                if (((mode && (flags & 0xC0000000) == 0) ||
                     (!mode && (flags & 0x40000000) == 0)) &&
                    entries[cell].id == key) {
                    found_row = row;
                    found_col = col;
                    goto found_key;
                }
            }
        }
    }
found_key:
    if (horizontal != 0) {
        offset = index * 4;
        dx = horizontal + (s16)(width * height);
        start = state->unk_D0;
        for (;;) {
            candidate = (s16)((horizontal + (s16)(width * height)) + found_col);
            candidate %= height;
            cell = (start * height + candidate);
            flags = entries[cell].flags;
            result = entries[cell].id;
            if (result == -1 ||
                (mode ? (flags & 0xC0000000) != 0 : (flags & 0x40000000) != 0)) {
                left = 1;
                x = start;
                while (--x >= 0 && x < width - 1) {
                    cell = x * height + candidate;
                    flags = entries[cell].flags;
                    if (mode ? (flags & 0xC0000000) == 0 && entries[cell].id != -1
                             : (flags & 0x40000000) == 0 && entries[cell].id != -1)
                        break;
                    left++;
                }
                right = 1;
                x = start;
                while (++x >= 0 && x < width - 1) {
                    cell = x * height + candidate;
                    flags = entries[cell].flags;
                    if (mode ? (flags & 0xC0000000) == 0 && entries[cell].id != -1
                             : (flags & 0x40000000) == 0 && entries[cell].id != -1)
                        break;
                    right++;
                }
                if (left == 100 && right == 100)
                    break;
                state->unk_C0 = 0;
            } else {
                state->unk_C0 = 0;
            }
            break;
        }
        state->unk_D0 = found_col;
        state->unk_C0 = 0;
    }
    if (vertical != 0) {
        offset = index * 4;
        dx = vertical + (s16)(width * height);
        start = state->unk_D2;
        candidate = (s16)((found_row + dx) % width);
        cell = candidate * height + start;
        flags = entries[cell].flags;
        result = entries[cell].id;
        if (result == -1 ||
            (mode ? (flags & 0xC0000000) != 0 : (flags & 0x40000000) != 0)) {
            state->unk_C2 = 0;
        } else {
            state->unk_C2 = 0;
        }
        state->unk_D2 = found_row;
        state->unk_C2 = 0;
    }
    if (state->unk_94 & 0x8000) {
        if (horizontal != 0) {
            if (state->unk_B2 == found_col)
                state->unk_C2++;
            else
                state->unk_C2 = 0;
            if (state->unk_C2 > 2) {
                state->unk_C2 = 0;
                state->unk_D2 = state->unk_B2;
            }
        }
        if (vertical != 0) {
            if (state->unk_B0 == found_row)
                state->unk_C0++;
            else
                state->unk_C0 = 0;
            if (state->unk_C0 > 2) {
                state->unk_C0 = 0;
                state->unk_D0 = state->unk_B0;
            }
        }
    }
    if (mode && result != -1) {
        row = 0;
        col = 0;
        for (x = 0; x < width; x++) {
            for (y = 0; y < height; y++) {
                cell = x * height + y;
                flags = entries[cell].flags;
                if ((flags & 0xC0000000) == 0 && entries[cell].id == result) {
                    row = x;
                    col = y;
                    goto found_result;
                }
            }
        }
    } else if (result != -1) {
        row = 0;
        col = 0;
        for (x = 0; x < width; x++) {
            for (y = 0; y < height; y++) {
                cell = x * height + y;
                flags = entries[cell].flags;
                if ((flags & 0x40000000) == 0 && entries[cell].id == result) {
                    row = x;
                    col = y;
                    goto found_result;
                }
            }
        }
    }
found_result:
    state->unk_B0 = row;
    state->unk_B2 = col;
    return result;
}
