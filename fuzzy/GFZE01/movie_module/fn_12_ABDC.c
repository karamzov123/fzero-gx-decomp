/* Non-matching: best partial attempt (99.57% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "sofdec/sj.h"

typedef struct MPVContext MPVContext;
typedef void (*MPV_Fn)(void *, void *);

extern void fn_12_9744(void *);
extern void fn_12_9730(void *);
extern void fn_800589BC(const SJCK *, s32, SJCK *, SJCK *);

struct MPVContext {
    u8 pad_0[0x1D8];
    u32 width;
    u8 pad_1DC[0xB8];
    MPV_Fn decode;
    u8 pad_298[0x24];
    u32 quantizer;
    u32 predictors[2][9];
    u32 coefficient;
    u8 pad_30C[0xFBC];
    SJCK input;
    s32 bit_offset;
};

#pragma opt_common_subs off

static inline s32 consumed_bytes(u8 *cursor,s32 bits,s32 offset,const SJCK *chunk) {
    cursor += (bits-offset+7)>>3;
    cursor -= 8;
    return cursor-chunk->data;
}
void fn_12_ABDC(MPVContext *arg0, SJ *arg1, u32 arg2) {
    s32 s;
    u8 *p;
    u32 a;
    u32 w;
    u32 hi;
    SJCK chunk;

    arg1->interface->get_chunk(arg1, 1, 0x7FFFFFFF, &arg0->input);

    p = (u8 *)((u32)arg0->input.data & ~3);
    s = (arg0->input.data - p) << 3;
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
    arg0->coefficient =
        (((hi & 0xFF) - 1) * arg0->width) - 1;
    if (s >= 27) {
        s -= 27;
        if (s != 0) {
            a = (a | (w >> (5 - s)));
            arg0->quantizer = (a >> 27);
            a = (w << s);
        } else {
            arg0->quantizer = (a >> 27);
            a = w;
        }
        w = *(u32 *)p;
        p += 4;
    } else {
        arg0->quantizer = (a >> 27);
        a = (a << 5);
        s += 5;
    }
    fn_12_9744(arg0->predictors[0]);
    fn_12_9744(arg0->predictors[1]);
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
        if (arg0->input.len > consumed_bytes(p,s,0,&arg0->input)) {
            continue;
        }
        return;
    }
    arg0->bit_offset = (s & 7);
    fn_800589BC(&arg0->input, consumed_bytes(p,s,arg0->bit_offset,&arg0->input), &arg0->input, &chunk);
    arg1->interface->put_chunk(arg1, 0, &arg0->input);
    arg1->interface->unget_chunk(arg1, 1, &chunk);
    arg0->decode(arg0, arg1);
}
#pragma opt_common_subs reset
