#include "types.h"
#include "sofdec/sj.h"

typedef void (*fn1_t)(void *);
typedef void (*fn0_t)(u32);

struct fn_12_8BD8_ctx {
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
    /* The buffered input chunk and bit offset within its first byte. */
    SJCK chunk;
    s32 unk_12d0;
    u32 pad7[8];
    s32 unk_12f4;
};

extern s16 *lbl_12_bss_6944;
extern s16 *lbl_12_bss_6940;
extern int MPV_GoNextDelimSj(SJ *);
extern void fn_800589BC(const SJCK *, s32, SJCK *, SJCK *);

#pragma opt_propagation off
void fn_12_8BD8(struct fn_12_8BD8_ctx *arg0, SJ *arg1) {
    SJCK localA;
    SJCK localB;
    s32 sh8;
    u32 w0;
    u32 w1;
    s32 sh;
    u32 *ptr;
    u32 v_2;
    u32 v;
    u32 code;
    u32 t;
    s32 len;
    u8 run_code;
    s32 old;
    s32 n;
    u32 lab_t1;

    arg1->interface->get_chunk(arg1, 1, 0x7FFFFFFF, &arg0->chunk);

    ptr = (u32 *)((u32)arg0->chunk.data & ~3);
    sh = ((u32)arg0->chunk.data - (u32)ptr) * 8;
    w0 = ptr[0] << sh;
    w1 = ptr[1];
    ptr += 2;
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
        /* Stuffing and escape codes retry without testing the start delimiter. */
        for (;;) {
            code = w0 >> 20;
            if (sh > 20) {
                code |= w1 >> (52 - sh);
            }
            if ((code >> 8) == 0) {
                t = lbl_12_bss_6944[code];
            } else {
                t = lbl_12_bss_6940[code >> 6];
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
            run_code = (t >> 2) & 0xFF;
            len = run_code >> 2;
            if (len == 0x22) {
                continue;
            }
            if (len == 0x23) {
                arg0->unk_308 += 0x21;
                continue;
            }
            break;
        }
        if (len == 0x24) {
            v_2 = -2;
        } else {
            arg0->unk_308 += len;
            arg0->unk_310 = t >> 10;
            if (arg0->unk_308 > arg0->unk_30c) {
                v_2 = -2;
            } else {
                v_2 = arg0->unk_308 - old;
            }
        }
        v_2 = v_2 + 0x10000;
        if ((u32)v_2 == 0xFFFE) {
            break;
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
        /* This variant reads one continuation bit after each decoded block. */
        v_2 = w0 >> 31;
        if (sh == 31) {
            w0 = w1;
            w1 = *ptr++;
            sh = 0;
        } else {
            w0 <<= 1;
            sh++;
        }
        if (v_2 != 1) {
            break;
        }
        sh8 = sh & 7;
        n = (u32)ptr;
        n += ((sh - sh8 + 7) >> 3);
        n -= 8;
        n -= (u32)arg0->chunk.data;
        /* Split off the consumed prefix when fewer than 2 KiB remain. */
        if (arg0->chunk.len - n > 0x800) {
            continue;
        }
        fn_800589BC(&arg0->chunk, n, &arg0->chunk, &localA);
        arg1->interface->put_chunk(arg1, 0, &arg0->chunk);
        arg1->interface->unget_chunk(arg1, 1, &localA);
        arg1->interface->get_chunk(arg1, 1, 0x7FFFFFFF, &arg0->chunk);
        ptr = (u32 *)((u32)arg0->chunk.data & ~3);
        sh = ((u32)arg0->chunk.data - (u32)ptr) * 8;
        w0 = ptr[0] << sh;
        w1 = ptr[1];
        ptr += 2;
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
    ptr = (u32 *)((u8 *)ptr + ((sh - arg0->unk_12d0 + 7) >> 3));
    ptr = (u32 *)((u8 *)ptr - 8);
    lab_t1 = (u32)arg0->chunk.data;
    fn_800589BC(&arg0->chunk, ((u32)ptr - lab_t1), &arg0->chunk, &localB);
    arg1->interface->put_chunk(arg1, 0, &arg0->chunk);
    arg1->interface->unget_chunk(arg1, 1, &localB);
    MPV_GoNextDelimSj(arg1);
}
#pragma opt_propagation reset

