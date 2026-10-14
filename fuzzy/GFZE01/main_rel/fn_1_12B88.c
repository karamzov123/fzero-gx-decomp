/* Non-matching: best partial attempt (81.12% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/live_camera.h"

typedef struct {
    u32 unk_0;
    u8 pad_4[0x58];
} LoadCtx;

extern int fn_1_45730(void *, void *);
extern u32 fn_1_1350C(LoadCtx *, void *);
extern void fn_1_45850(LoadCtx *);

#define LWBE(p) (*(u32 *)(p))

#pragma opt_lifetimes off
#pragma opt_dead_assignments off
static inline u8 fn_1_12B88_array_read(u8 *array, s32 index) { return array[index]; }
#pragma opt_common_subs off
void *fn_1_12B88(u32 arg0, u8 *arg1, void *arg2) {
    struct { u32 value; } limit;
    u32 w1;
    u32 w0;
    u8 window[0x1000];
    u32 count;
    u8 *out;
    u32 bits;
    LoadCtx load;
    u32 bits_2;
    struct { u32 value; } wrpos;
    void *p;
    u32 off;
    s32 n;
    struct { s32 value; } i;

    lbl_1_bss_3B28 = 0;
    lbl_1_bss_3B2C = 0;
    if (fn_1_45730((void *)arg0, &load) == 0) {
        return 0;
    }
    w0 = (fn_1_1350C(&load, arg2) & 0xFF) << 24;
    w0 |= (fn_1_1350C(&load, arg2) & 0xFF) << 16;
    w0 |= (fn_1_1350C(&load, arg2) & 0xFF) << 8;
    w0 |= (fn_1_1350C(&load, arg2) & 0xFF);
    w1 = (fn_1_1350C(&load, arg2) & 0xFF) << 24;
    w1 |= (fn_1_1350C(&load, arg2) & 0xFF) << 16;
    w1 |= (fn_1_1350C(&load, arg2) & 0xFF) << 8;
    w1 |= (fn_1_1350C(&load, arg2) & 0xFF);

    limit.value = LWBE(&w0) + 8;
    if (limit.value == 0) {
        return 0;
    }
    p = (void *)LWBE(&w1);
    if (p == 0) {
        return 0;
    }

    out = arg1;
    count = 8;
    {
        s32 j;
        for (j = 0; j < 0xFEE; j++) {
            window[j] = 0;
        }
    }
    wrpos.value = 0xFEE;
    bits = 0;

    for (;;) {
        bits >>= 1;
        if ((bits & 0x00800000) == 0) {
            if (count >= limit.value) {
                break;
            }
            bits_2 = (fn_1_1350C(&load, arg2) & 0xFF) | 0xFF00;
            count++;
        }
        if (bits_2 & 1) {
            u32 b;
            if (count >= limit.value) {
                break;
            }
            b = (u8)((u8)fn_1_1350C(&load, arg2));
            count++;
            *out++ = b;
            window[wrpos.value] = b;
            wrpos.value = (wrpos.value + 1) & 0xFFF;
        } else {
            u8 b1;
            u32 b2;
            if (count >= limit.value) {
                break;
            }
            b1 = fn_1_1350C(&load, arg2);
            if (count + 1 >= limit.value) {
                break;
            }
            b2 = fn_1_1350C(&load, arg2);
            off = (b1 & 0xFF) | ((b2 & 0xF0000) << 4);
            n = (s32)(b2 & 7) + 2;
            count += 2;
            for (i.value = 0; i.value <= n; i.value++) {
                u32 b = (u8)(fn_1_12B88_array_read(window, (off + (u32)i.value) & 0xFFF));
                *out++ = b;
                window[wrpos.value] = b;
                wrpos.value = (wrpos.value + 1) & 0xFFF;
            }
        }
    }

    fn_1_45850(&load);
    return p;
}
#pragma opt_common_subs reset

#pragma opt_dead_assignments reset

#pragma opt_lifetimes reset

