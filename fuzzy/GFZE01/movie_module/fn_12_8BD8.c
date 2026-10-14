/* Non-matching: best partial attempt (92.53% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "sofdec/sj.h"

typedef u32 (*fn_12_8BD8_Fn3)(void *, u32, void *);
typedef u32 (*fn_12_8BD8_Fn4)(void *, u32, u32, void *);

extern u32 lbl_12_bss_6944;
extern u32 lbl_12_bss_6940;

struct fn_12_8BD8_Arg1 {
    u32 unk_0;
};

struct fn_12_8BD8_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_c;
    u8 pad_10[0x19c];
    u32 unk_1ac;
    u32 unk_1b0;
    u32 unk_1b4;
    u8 pad_1b8[0xe4];
    u32 unk_29c;
    u8 pad_2a0[4];
    u32 unk_2a4;
    u8 pad_2a8[0x60];
    u32 unk_308;
    s32 unk_30c;
    s32 unk_310;
    u8 pad_314[0xfb4];
    s32 unk_12c8;
    s32 unk_12cc;
    s32 unk_12d0;
    u8 pad_12d4[0x20];
    s32 unk_12f4;
};

extern u32 fn_800589BC(void *, u32, void *, void *);

#pragma opt_dead_assignments off
#pragma opt_lifetimes off
void fn_12_8BD8(struct fn_12_8BD8_Arg0 *arg0, struct fn_12_8BD8_Arg1 *arg1,
                u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 raw;
    u32 idx;
    s32 s;
    s32 t;
    u32 w0;
    s32 bit;
    u32 t_2;
    u8 *p;
    u32 code;
    void * lab_t0_2;
    u32 field;
    s32 kind;
    s32 start;
    s32 err;
    s32 aligned;
    u32 w1;
    s32 idx_2;
    struct { u32 unk_0; u32 unk_4; } buf1;
    struct { u32 unk_0; u32 unk_4; } buf2;
    void * lab_t0;

    ((fn_12_8BD8_Fn4)(*(u32 *)((u8 *)arg1->unk_0 + 24)))(arg1, 1, 0x7FFFFFFF, &arg0->unk_12c8);

    raw = arg0->unk_12c8;
    idx = raw & ~3;
    s = (raw - idx) << 3;
    w0 = *(u32 *)idx;
    w1 = *(u32 *)(idx + 4);
    w0 <<= s;
    p = (u8 *)(idx + 8);
    bit = ((arg0->unk_12d0) + (s));
    if (bit >= 32) {
        bit -= 32;
        w0 = w1 << bit;
        w1 = *(u32 *)p;
        p += 4;
    } else {
        w0 <<= arg0->unk_12d0;
    }

    for (;;) {
        code = w0 >> 9;
        if (bit > 9) {
            code |= w1 >> (41 - bit);
        }
        if (code == 0) {
            break;
        }
        for (;;) {
            start = (*(s32 volatile *)&(arg0->unk_308)) /* Retail reloads this field. */;
            field = w0 >> 20;
            if (bit > 20) {
                field |= w1 >> (52 - bit);
            }
            if ((field >> 8) == 0) {
                field = *(s16 *)(*(u32 *)lbl_12_bss_6944 + (field << 1));
            } else {
                field = *(s16 *)(*(u32 *)lbl_12_bss_6940 + ((field >> 5) & 0x3FFFFFC));
            }
            t = field & 0xF;
            bit += t;
            if (bit >= 32) {
                bit -= 32;
                w0 = w1 << bit;
                w1 = *(u32 *)p;
                p += 4;
            } else {
                w0 <<= t;
            }
            kind = (field >> 8) & 0x1FF;
            if ((kind = kind >> 2) != 0x22) {
                continue;
            }
            if (kind == 0x23) {
                arg0->unk_308 += 0x21;
                continue;
            }
            if (kind == 0x24) {
                err = -2;
                break;
            }
            arg0->unk_308 = (*(s32 volatile *)&(arg0->unk_308)) /* Retail reloads this field. */ + kind;
            arg0->unk_310 = field >> 10;
            if ((*(s32 volatile *)&(arg0->unk_308)) /* Retail reloads this field. */ > arg0->unk_30c) {
                err = -2;
            } else {
                err = (*(s32 volatile *)&(arg0->unk_308)) /* Retail reloads this field. */ - start;
            }
            break;
        }
        if ((u32)err == 0xFFFFFFFE) {
            break;
        }
        arg0->unk_0 = w0;
        arg0->unk_4 = w1;
        arg0->unk_8 = bit;
        arg0->unk_c = (u32)p;
        ((void (*)(void *))arg0->unk_29c)(arg0);
        ((void (*)(void *))arg0->unk_2a4)(arg0);
        t = arg0->unk_12f4;
        arg0->unk_12f4 = t - 1;
        if (t - 1 <= 0) {
            arg0->unk_12f4 = arg0->unk_1ac;
            ((void (*)(u32))arg0->unk_1b0)(arg0->unk_1b4);
        }
        bit = arg0->unk_8;
        (void) bit;  /* fzgx: keeps the web at its definition */
        w0 = arg0->unk_0;
        (void) w0;  /* fzgx: keeps the web at its definition */
        p = (u8 *)arg0->unk_c;
        w1 = arg0->unk_4;
        for (;;) {
            t_2 = w0 >> 31;
            if (bit == 0x1F) {
                w0 = w1;
                w1 = *(u32 *)p;
                p += 4;
                bit = 0;
            } else {
                w0 <<= 1;
                bit += 1;
            }
            if (t_2 == 1) {
                break;
            }
        }
        if (t_2 != 1) {
            break;
        }
        aligned = bit & 0x1FFFFFFC;
        idx_2 = (bit - aligned + 7) >> 3;
        idx_2 = (s32)p + idx_2;
        idx_2 = idx_2 - 8;
        idx_2 = arg0->unk_12c8 - idx_2;
        if (arg0->unk_12cc - idx_2 > 0x800) {
            continue;
        }
        lab_t0 = &arg0->unk_12c8;
        fn_800589BC(lab_t0, idx_2, &arg0->unk_12c8, &buf1);
        ((fn_12_8BD8_Fn3)(*(u32 *)((u8 *)arg1->unk_0 + 32)))(arg1, 0, &arg0->unk_12c8);
        ((fn_12_8BD8_Fn3)(*(u32 *)((u8 *)arg1->unk_0 + 28)))(arg1, 1, &buf1);
        ((fn_12_8BD8_Fn4)(*(u32 *)((u8 *)arg1->unk_0 + 24)))(arg1, 1, 0x7FFFFFFF, &arg0->unk_12c8);
        raw = arg0->unk_12c8;
        idx_2 = raw & ~3;
        s = (raw - idx_2) << 3;
        w0 = *(u32 *)idx_2;
        w1 = *(u32 *)(idx_2 + 4);
        w0 <<= s;
        p = (u8 *)(idx_2 + 8);
        bit = s + aligned;
        if (bit >= 32) {
            bit -= 32;
            w0 = w1 << bit;
            w1 = *(u32 *)p;
            p += 4;
        } else {
            w0 <<= aligned;
        }
    }

    arg0->unk_12d0 = bit & 0x1FFFFFFC;
    w0 = (bit - arg0->unk_12d0 + 7) >> 3;
    idx = w0;
    idx_2 = idx;
    idx_2 = (s32)p + idx_2;
    idx_2 = idx_2 - 8;
    code = arg0->unk_12c8 - idx_2;
    idx_2 = code;
    fn_800589BC((lab_t0_2 = &arg0->unk_12c8), idx_2, &arg0->unk_12c8, &buf2);
    ((fn_12_8BD8_Fn3)(*(u32 *)((u8 *)arg1->unk_0 + 32)))(arg1, 0, &arg0->unk_12c8);
    ((fn_12_8BD8_Fn3)(*(u32 *)((u8 *)arg1->unk_0 + 28)))(arg1, 1, &buf2);
    MPV_GoNextDelimSj((SJ *)arg1);
}
#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset

