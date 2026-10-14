/* Non-matching: best partial attempt (96.96% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MPVContext MPVContext;
typedef struct SJInterface SJInterface;
typedef struct SJ SJ;

struct SJInterface {
    u8 _pad_pre[0x18];
    void (*get_chunk)(SJ *, s32, s32, void *);
    void (*unget_chunk)(SJ *, s32, void *);
    void (*put_chunk)(SJ *, s32, void *);
};

struct SJ {
    const SJInterface *iface;
};

typedef void (*MPV_Fn)(void *, void *);

extern void fn_12_9744(void *);
extern void fn_12_9730(void *);
extern u32 fn_800589BC(u32, u32, void *, void *);

struct Chunk {
    u32 w0;
    u32 w1;
};

#pragma opt_common_subs off
#pragma opt_dead_assignments off
static inline u32 fn_12_ABDC_call_fn_800589BC(void * a3, void * a2, u32 a1, u32 a0) { return fn_800589BC(a0, a1, a2, a3); }
void fn_12_ABDC(MPVContext *arg0, SJ *arg1, u32 arg2) {
    s32 s;
    s32 p;
    u32 a;
    u32 w;
    u32 hi;
    struct Chunk chunk;

    arg1->iface->get_chunk(arg1, 1, 0x7FFFFFFF, (void *)((u8 *)arg0 + 0x12c8));

    p = *(u32 *)((u8 *)arg0 + 0x12c8) & ~3;
    s = (*(u32 *)((u8 *)arg0 + 0x12c8) - p) << 3;
    a = *(u32 *)p;
    w = *(u32 *)(4 + p);
    a <<= s;
    p += 8;
    if (s >= 32) {
        s -= 32;
        a = (w << s);
        w = *(u32 *)p;
        p += 4;
    }
    if (s != 0) {
        hi = (a | (w >> (32 - s)));
        a = (w << s);
    } else {
        hi = a;
        a = w;
    }
    w = *(u32 *)p;
    p += 4;
    *(u32 *)((u8 *)arg0 + 0x308) =
        (((hi & 0xFF) - 1) * *(u32 *)((u8 *)arg0 + 0x1d8)) - 1;
    if (s >= 27) {
        s -= 27;
        if (s != 0) {
            a = (a | (w >> (5 - s)));
            *(u32 *)((u8 *)arg0 + 0x2bc) = (a >> 27);
            a = (w << s);
        } else {
            *(u32 *)((u8 *)arg0 + 0x2bc) = (a >> 27);
            a = w;
        }
        w = *(u32 *)p;
        p += 4;
    } else {
        *(u32 *)((u8 *)arg0 + 0x2bc) = (a >> 27);
        a = (a << 5);
        s += 5;
    }
    fn_12_9744((void *)((u8 *)arg0 + 0x2c0));
    fn_12_9744((void *)((u8 *)arg0 + 0x2e4));
    fn_12_9730((void *)arg0);
    for (;;) {
        if (!(a >> 31)) {
            s += 1;
            if (s >= 32) {
                s -= 32;
                p += 4;
            }
            break;
        }
        s += 9;
        if (s >= 32) {
            s -= 32;
            a = (w << s);
            w = *(u32 *)p;
            p += 4;
        } else {
            a = (a << 9);
        }
        if (*(s32 *)((u8 *)arg0 + 0x12cc) >
            *(s32 *)((u8 *)arg0 + 0x12c8) -
                ((s32)((u8 *)p + ((s + 7) >> 3)) - 8)) {
            continue;
        }
        return;
    }
    *(u32 *)((u8 *)arg0 + 0x12d0) = (s & 7);
    fn_12_ABDC_call_fn_800589BC(&chunk, (void *)((u8 *)arg0 + 0x12c8), *(s32 *)((u8 *)arg0 + 0x12c8) -
                    ((p + (((s - *(s32 *)((u8 *)arg0 + 0x12d0)) + 7) >> 3)) - 8), (u32)((u8 *)arg0 + 0x12c8));
    arg1->iface->put_chunk(arg1, 0, (void *)((u8 *)arg0 + 0x12c8));
    arg1->iface->unget_chunk(arg1, 1, &chunk);
    ((MPV_Fn)(*(u32 *)((u8 *)arg0 + 0x294)))(arg0, arg1);
}
#pragma opt_dead_assignments reset
#pragma opt_common_subs reset
