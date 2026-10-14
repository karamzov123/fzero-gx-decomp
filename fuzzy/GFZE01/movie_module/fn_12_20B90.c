/* Non-matching: best partial attempt (92.91% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct Movie {
    u8 pad_0000[0x3c];
    void (*field_003c)(void);
} Movie;

typedef struct MovieModule {
    u8 pad_0000[0x1b74];
    Movie *field_1b74;
} MovieModule;

extern s32 fn_8004B9A4(u32 arg0, s32 arg1, s32 *arg2);
extern s32 fn_8004B974(u32 arg0, u32 arg1, s32 *arg2);
extern s32 fn_12_23F34(MovieModule *arg0);
extern s32 fn_12_24A88(MovieModule *arg0, s32 arg1);
extern void fn_12_20CE8(void);

void fn_12_20B90(MovieModule *module, u8 *buf, s32 size, s32 *result) {
    u8 *limit;
    s32 found;
    u8 *best;
    u8 *best_start;
    u8 *end;
    u8 *pos;
    u8 *cur;
    s32 offset;
    s32 value;
    s32 entry;
    Movie *movie;

    *result = 0;
    movie = module->field_1b74;
    if (size < 0x120) {
        return;
    }
    if (fn_8004B9A4((u32)buf, size, &value) != 0) {
        offset = value;
    } else if (fn_12_23F34(module) >= 0x6c) {
        offset = 0;
    } else {
        found = 0;
        cur = buf;
        best = (u8 *)found;
        end = buf + size;
        best_start = (u8 *)found;
        limit = buf + 0x24;
        while (cur < limit) {
            found = 0;
            pos = cur;
            while (pos < end) {
                if (*(s8 *)pos < 0) {
                    found = 1;
                    if (fn_8004B974((u32)pos, 0x12, &entry) != 0) {
                        if (best < pos) {
                            best = pos;
                            best_start = cur;
                        }
                    }
                    break;
                }
                pos += 0x12;
            }
            if (found == 0) {
                break;
            }
            cur += 2;
        }
        if (found) {
            if (!(best_start != 0)) {
                fn_12_24A88(module, 0xff000c0a);
                cur = buf;
                (void) cur;  /* fzgx: keeps the web at its definition */
            } else {
                cur = best_start;
            }
        }
        offset = cur - buf;
    }
    movie->field_003c = fn_12_20CE8;
    *result = offset;
}
