/* Non-matching: best partial attempt (67.37% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern f32 lbl_80091330[];

void fn_80051F38(f32 *arg0, f32 *arg1, f32 *arg2) {
    s32 i;
    f32 *base = arg1;
    f32 *d0 = arg2;
    f32 *d1 = arg2 + 0x20;
    f32 *e0 = arg2 + 0x21;
    f32 *e1 = arg2 + 0x3F;
    f32 t;

    i = 0x10;
loop1:
    t = arg0[0x00] * arg1[0x00];
        t += arg0[0x01] * arg1[0x01];
        t += arg0[0x02] * arg1[0x02];
        t += arg0[0x03] * arg1[0x03];
        t += arg0[0x04] * arg1[0x04];
        t += arg0[0x05] * arg1[0x05];
        t += arg0[0x06] * arg1[0x06];
        t += arg0[0x07] * arg1[0x07];
        t += arg0[0x08] * arg1[0x08];
        t += arg0[0x09] * arg1[0x09];
        t += arg0[0x0A] * arg1[0x0A];
        t += arg0[0x0B] * arg1[0x0B];
        t += arg0[0x0C] * arg1[0x0C];
        t += arg0[0x0D] * arg1[0x0D];
        t += arg0[0x0E] * arg1[0x0E];
        t += arg0[0x0F] * arg1[0x0F];
        t += arg0[0x10] * arg1[0x10];
        t += arg0[0x11] * arg1[0x11];
        t += arg0[0x12] * arg1[0x12];
        t += arg0[0x13] * arg1[0x13];
        t += arg0[0x14] * arg1[0x14];
        t += arg0[0x15] * arg1[0x15];
        t += arg0[0x16] * arg1[0x16];
        t += arg0[0x17] * arg1[0x17];
        t += arg0[0x18] * arg1[0x18];
        t += arg0[0x19] * arg1[0x19];
        t += arg0[0x1A] * arg1[0x1A];
        t += arg0[0x1B] * arg1[0x1B];
        t += arg0[0x1C] * arg1[0x1C];
        t += arg0[0x1D] * arg1[0x1D];
        t += arg0[0x1E] * arg1[0x1E];
        t += arg0[0x1F] * arg1[0x1F];
        *d0 = t;
        *d1 = -t;
        arg1 += 0x20;
        d0++;
        d1--;
    if (--i != 0) goto loop1;

    arg2[0x10] = lbl_80091330[0];

    arg1 = base + 0x420;
    for (i = 0xF; i != 0; i--) {
        t = arg0[0x00] * arg1[0x00];
        t += arg0[0x01] * arg1[0x01];
        t += arg0[0x02] * arg1[0x02];
        t += arg0[0x03] * arg1[0x03];
        t += arg0[0x04] * arg1[0x04];
        t += arg0[0x05] * arg1[0x05];
        t += arg0[0x06] * arg1[0x06];
        t += arg0[0x07] * arg1[0x07];
        t += arg0[0x08] * arg1[0x08];
        t += arg0[0x09] * arg1[0x09];
        t += arg0[0x0A] * arg1[0x0A];
        t += arg0[0x0B] * arg1[0x0B];
        t += arg0[0x0C] * arg1[0x0C];
        t += arg0[0x0D] * arg1[0x0D];
        t += arg0[0x0E] * arg1[0x0E];
        t += arg0[0x0F] * arg1[0x0F];
        t += arg0[0x10] * arg1[0x10];
        t += arg0[0x11] * arg1[0x11];
        t += arg0[0x12] * arg1[0x12];
        t += arg0[0x13] * arg1[0x13];
        t += arg0[0x14] * arg1[0x14];
        t += arg0[0x15] * arg1[0x15];
        t += arg0[0x16] * arg1[0x16];
        t += arg0[0x17] * arg1[0x17];
        t += arg0[0x18] * arg1[0x18];
        t += arg0[0x19] * arg1[0x19];
        t += arg0[0x1A] * arg1[0x1A];
        t += arg0[0x1B] * arg1[0x1B];
        t += arg0[0x1C] * arg1[0x1C];
        t += arg0[0x1D] * arg1[0x1D];
        t += arg0[0x1E] * arg1[0x1E];
        t += arg0[0x1F] * arg1[0x1F];
        *e0 = t;
        *e1 = t;
        arg1 += 0x20;
        e0++;
        e1--;
    }

    t = arg0[0x00];
    t += arg0[0x01];
    t += arg0[0x02];
    t += arg0[0x03];
    t += arg0[0x04];
    t += arg0[0x05];
    t += arg0[0x06];
    t += arg0[0x07];
    t += arg0[0x08];
    t += arg0[0x09];
    t += arg0[0x0A];
    t += arg0[0x0B];
    t += arg0[0x0C];
    t += arg0[0x0D];
    t += arg0[0x0E];
    t += arg0[0x0F];
    t += arg0[0x10];
    t += arg0[0x11];
    t += arg0[0x12];
    t += arg0[0x13];
    t += arg0[0x14];
    t += arg0[0x15];
    t += arg0[0x16];
    t += arg0[0x17];
    t += arg0[0x18];
    t += arg0[0x19];
    t += arg0[0x1A];
    t += arg0[0x1B];
    t += arg0[0x1C];
    t += arg0[0x1D];
    t += arg0[0x1E];
    t += arg0[0x1F];
    arg2[0x30] = -t;
}
