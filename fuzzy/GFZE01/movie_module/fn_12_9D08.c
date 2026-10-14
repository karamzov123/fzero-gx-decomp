/* Non-matching: best partial attempt (98.16% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "sofdec/sj.h"

typedef void (*fnA_t)(void *, u32, u32, void *);
typedef void (*fnB_t)(void *, u32, void *);
typedef void (*fn1_t)(void *);
typedef void (*fn0_t)(u32);

struct fn_12_9D08_sj {
    void **vtable;
};

struct fn_12_9D08_ctx {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_c;
    u32 pad1[103];
    u32 unk_1ac;
    fn0_t unk_1b0;
    u32 unk_1b4;
    u32 pad2[57];
    fn1_t unk_29c;
    u32 pad3;
    fn1_t unk_2a4;
    u32 pad4[5];
    u32 unk_2bc;
    u32 pad5[18];
    s32 unk_308;
    s32 unk_30c;
    s32 unk_310;
    u32 pad6[1005];
    u32 unk_12c8;
    u32 unk_12cc;
    s32 unk_12d0;
    u32 pad7[8];
    s32 unk_12f4;
};

struct fn_12_9D08_s { u32 unk_0; u32 unk_4; };

extern s16 *lbl_12_bss_6944;
extern s16 *lbl_12_bss_6940;
extern int MPV_GoNextDelimSj(SJ *);
extern u32 fn_800589BC(void *, u32, void *, void *);

#pragma opt_dead_assignments off
static inline s16 fn_12_9D08_array_read(s16 *array, s32 index) { return array[index]; }
#pragma opt_dead_assignments reset

#pragma opt_propagation off
void fn_12_9D08(struct fn_12_9D08_ctx *arg0, struct fn_12_9D08_sj *arg1) {
    struct fn_12_9D08_s localA;
    struct fn_12_9D08_s localB;
    s32 sh8;
    u32 w0;
    u32 w1;
    s32 sh;
    u32 *ptr;
    u32 v_2;
    u32 *base;
    u32 v;
    u32 code;
    u32 t;
    s32 len;
    s32 old;
    s32 n;
    u32 lab_t1;

    ((fnA_t)arg1->vtable[6])(arg1, 1, 0x7FFFFFFF, &arg0->unk_12c8);

    base = (u32 *)(arg0->unk_12c8 & ~3);
    sh = (arg0->unk_12c8 - (u32)base) * 8;
    w0 = base[0] << sh;
    w1 = base[1];
    ptr = base + 2;
    sh += arg0->unk_12d0;
    if (sh >= 32) {
        sh -= 32;
        w0 = w1 << sh;
        w1 = ptr[0];
        ptr++;
    } else {
        w0 <<= arg0->unk_12d0;
    }

    for (;;) {
        v = w0 >> 9;
        if (sh > 9) {
            v |= w1 >> (41 - sh);
        }
        if (v == 0) {
            break;
        }
        old = arg0->unk_308;
        code = w0 >> 20;
        if (sh > 20) {
            code |= w1 >> (52 - sh);
        }
        if ((code >> 8) == 0) {
            t = fn_12_9D08_array_read(lbl_12_bss_6944, code);
        } else {
            t = fn_12_9D08_array_read(lbl_12_bss_6940, code & 0x1F);
        }
        v_2 = t & 0xF;
        sh += v_2;
        if (sh >= 32) {
            sh -= 32;
            w0 = w1 << sh;
            w1 = ptr[0];
            ptr++;
        } else {
            w0 <<= v_2;
        }
        len = (t >> 8) & 0x7FF;
        len = len >> 2;
        if (len == 0x22) {
            continue;
        }
        if (len == 0x23) {
            arg0->unk_308 += 0x21;
            continue;
        }
        if (len == 0x24) {
            v_2 = -2;
            goto tail;
        }
        arg0->unk_308 = (*(s32 volatile *)&(arg0->unk_308)) /* Retail reloads this field. */ + len;
        arg0->unk_310 = t >> 10;
        if (arg0->unk_308 > arg0->unk_30c) {
            v_2 = -2;
        } else {
            v_2 = arg0->unk_308 - old;
        }
    tail:
        v_2 = v_2 + 0x10000;
        if ((u32)v_2 == 0xFFFE) {
            break;
        }
        if (arg0->unk_310 & 0x10) {
            if (sh >= 27) {
                sh -= 27;
                if (sh != 0) {
                    w0 |= w1 >> (5 - sh);
                    v_2 = w0 >> 27;
                    w0 = w1 << sh;
                } else {
                    v_2 = w0 >> 27;
                    w0 = w1;
                }
                w1 = ptr[0];
                ptr++;
            } else {
                v_2 = w0 >> 27;
                w0 <<= 5;
                sh += 5;
            }
            arg0->unk_2bc = v_2;
        }
        arg0->unk_0 = w0;
        arg0->unk_4 = w1;
        arg0->unk_8 = sh;
        arg0->unk_c = (u32)ptr;
        arg0->unk_29c(arg0);
        arg0->unk_2a4(arg0);
        if (--arg0->unk_12f4 <= 0) {
            arg0->unk_12f4 = arg0->unk_1ac;
            arg0->unk_1b0(arg0->unk_1b4);
        }
        w0 = arg0->unk_0;
        w1 = arg0->unk_4;
        sh = arg0->unk_8;
        ptr = (u32 *)arg0->unk_c;
        sh8 = sh & 7;
        n = (u32)ptr;
        n += ((sh - sh8 + 7) >> 3);
        n -= 8;
        n = arg0->unk_12c8 - n;
        n -= arg0->unk_12cc;
        if (n > 0x800) {
            continue;
        }
        fn_800589BC(&arg0->unk_12c8, n, &arg0->unk_12c8, &localA);
        ((fnB_t)arg1->vtable[8])(arg1, 0, &arg0->unk_12c8);
        ((fnB_t)arg1->vtable[7])(arg1, 1, &localA);
        ((fnA_t)arg1->vtable[6])(arg1, 1, 0x7FFFFFFF, &arg0->unk_12c8);
        base = (u32 *)(arg0->unk_12c8 & ~3);
        sh = (arg0->unk_12c8 - (u32)base) * 8;
        w0 = base[0] << sh;
        w1 = base[1];
        ptr = base + 2;
        sh += sh8;
        if (sh >= 32) {
            sh -= 32;
            w0 = w1 << sh;
            w1 = ptr[0];
            ptr++;
        } else {
            w0 <<= sh8;
        }
    }

    arg0->unk_12d0 = sh & 7;
    ptr = (u32 *)((u8 *)ptr + ((arg0->unk_12d0 - sh + 7) >> 3));
    ptr = (u32 *)((u8 *)ptr - 8);
    lab_t1 = arg0->unk_12c8;
    fn_800589BC(&arg0->unk_12c8, (lab_t1 - (u32)ptr), &arg0->unk_12c8, &localB);
    ((fnB_t)arg1->vtable[8])(arg1, 0, &arg0->unk_12c8);
    ((fnB_t)arg1->vtable[7])(arg1, 1, &localB);
    MPV_GoNextDelimSj((SJ *)arg1);
}
#pragma opt_propagation reset

