/* Non-matching: best partial attempt (94.63% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_12_3DBE0_Arg0 {
    s32 unk_0;
    u32 pad_4[2];
    u32 unk_c;
};

struct fn_12_3DBE0_Arg1 {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    u32 unk_c;
    s32 unk_10;
};

#define PIX(x) (*(u32 *)((u8 *)(pal) + (x)))

#pragma opt_dead_assignments off
void fn_12_3DBE0(struct fn_12_3DBE0_Arg0 *arg0, struct fn_12_3DBE0_Arg1 *arg1, u32 pal, u32 lab_unused0, u32 lab_unused1) {
    s32 j;
    s32 i = 0;
    s32 nj = (s32)arg1->unk_10 / 4;
    s32 ni = (s32)arg1->unk_c / 4;
    u8 *src = (u8 *)arg0->unk_0;
    u8 *d0 = (u8 *)arg1->unk_4;
    u8 *d1 = ((0x20) + (d0));
    s32 stride = ((~3) & (arg0->unk_c));
    u32 d;
    u32 pitch = (arg1->unk_8 - arg1->unk_10) << 4;
    u8 off = (u8)((arg0->unk_c >> 28) & 3);

    while (i < ni) {
        j = 0;
        while (j < nj) {
            s32 k;
            for (k = 4; k != 0; k--) {
                u32 w = *(u32 *)src;
                u32 a = (w >> 14) & 0x3FC;
                s32 b = (w >> 22) & 0x3FC;
                u32 c = (w & 0xFF) << 2;
                d = (w >> 6) & 0x3FC;
                src += stride;
                *(u32 *)d0 = ((PIX(a) >> 16) & 0xFFFF0000) | (PIX(b) & 0xFFFF);
                *(u32 *)(((4) + (d0))) = ((PIX(c) >> 16) & 0xFFFF0000) | (PIX(d) & 0xFFFF);
                d0 += 8;
                *(u32 *)d1 = (PIX(a) << 16) | (PIX(b) & 0xFFFF);
                *(u32 *)(((4) + (d1))) = (PIX(c) << 16) | (PIX(d) & 0xFFFF);
                d1 += 8;
            }
            src -= off;
            src += 4;
            j++;
            d0 += 0x20;
            d1 += 0x20;
        }
        src -= stride;
        d0 += pitch;
        d1 += pitch;
        src += off;
        i++;
    }
}
#pragma opt_dead_assignments reset
