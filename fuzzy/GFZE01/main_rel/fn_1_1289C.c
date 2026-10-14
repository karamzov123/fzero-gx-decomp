/* Non-matching: best partial attempt (95.16% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/live_camera.h"

u32 *fn_1_1289C(u32 *state) {
    u8 win[0x1000];
    u8 *src = (u8 *)state[0];
    void (*done)(u32) = (void (*)(u32))state[2];
    int off;
    u32 pos;
    s32 bits;
    u8 *out = (u8 *)state[1];
    u32 limit = __lwbrx((u32 *)src, 0) + 8;
    u32 out_size = __lwbrx((u32 *)src, 4);
    u8 *cur;
    s32 i;

    if (limit == 0 || out_size == 0) {
        return 0;
    }

    cur = src + 8;

    for (i = 0; i < 0xfee; i++) {
        win[i] = 0;
    }

    pos = 0xfee;
    bits = 0;

    for (;;) {
        bits >>= 1;
        if ((bits & 0x100) == 0) {
            if ((u32)(cur - src) >= limit) break;
            bits = *cur++ | 0xff00;
        }

        if (bits & 1) {
            u8 v;
            if ((u32)(cur - src) >= limit) break;
            v = *cur++;
            *out++ = v;
            win[pos] = v;
            pos++;
            pos &= 0xfff;
        } else {
            int len;
            if ((u32)(cur - src) >= limit) break;
            if ((u32)((1 + cur) - src) >= limit) break;
            off = cur[0];
            len = cur[1];
            cur += 2;
            off |= (0xf0 & len) << 4;
            len = (len & 0xf) + 2;
            {
                int i;
                for (i = 0; i <= len; i++) {
                    u8 v = win[(off + i) & 0xfff];
                    *out++ = v;
                    win[pos] = v;
                    pos++;
                    pos &= 0xfff;
                }
            }
        }
    }

    if (done != 0) {
        done(out_size);
    }
    return &out_size;
}
