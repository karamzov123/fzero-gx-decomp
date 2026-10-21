/* Non-matching: best partial attempt (96.25% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    unsigned int open_mode : 2;
    unsigned int io_mode : 3;
    unsigned int buffer_mode : 2;
    unsigned int file_kind : 3;
    unsigned int file_orientation : 2;
    unsigned int binary_io : 1;
} __file_modes;

#pragma opt_strength_reduction on
int fn_8007F508(const char *mode, __file_modes *modes) {
    const char *q;
    s32 c;
    struct {
    u8 lab_pad[4]; u8 value; } c0;
    struct { s8 value; } c2;
    u8 om;
    u8 im;
    s8 t;

    modes->file_kind = 1;
    c0.value = mode[0];
    c = c0.value;
    modes->file_orientation = 0;
    modes->binary_io = 0;

    switch (c) {
    case 'r':
        om = 0;
        break;
    case 'w':
        om = 2;
        break;
    case 'a':
        om = 1;
        break;
    default:
        return 0;
    }

    c2.value = (*((mode) + (1)));
    q = mode + 2;
    modes->open_mode = om;

    switch (c2.value) {
    case 'b':
        t = (u8)*q;
        modes->binary_io = 1;
        if (t == '+') {
            c = ('+' | (c << 8));
        }
        break;
    case '+':
        c = (c << 8) | '+';
        if (*q == 'b') {
            modes->binary_io = 1;
        }
        break;
    }

    switch (c) {
    case 'r':
        im = 1;
        break;
    case 'w':
        im = 2;
        break;
    case 'a':
        im = 6;
        break;
    case 0x722B:
        im = 3;
        break;
    case 0x772B:
        im = 3;
        break;
    case 0x612B:
        im = 7;
        break;
    }

    modes->io_mode = im;
    return 1;
}
#pragma opt_strength_reduction reset
