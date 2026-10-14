/* Non-matching: best partial attempt (52.75% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 pad_00[0x18];
    u32 unk_18;
    u8 pad_1C[0x4];
    u32 unk_20;
    u32 unk_24;
} MovieFieldArg;

void fn_12_1F1AC(MovieFieldArg *arg0) {
    u8 *src = (u8 *)arg0->unk_24;
    u32 stride = arg0->unk_20;
    u32 mode = (u32)src & 3;
    u8 *dst = (u8 *)arg0->unk_18;

    switch (mode) {
    case 0: {
        u32 hi = 0x01010101;
        u32 lo = 0xFEFEFE;
        s32 i;
        for (i = 0; i < 16; i++) {
            u32 a0 = *(u32 *)(src + 0x00);
            u32 a1 = *(u32 *)(src + 0x04);
            u32 a2 = *(u32 *)(src + 0x08);
            u32 a3 = *(u32 *)(src + 0x0C);
            u32 a4 = *(u8 *)(src + 0x10);
            u32 v0 = ((a1 >> 24) & 0xFF) | ((a0 << 8) & 0xFFFFFF00);
            u32 v1 = ((a2 >> 24) & 0xFF) | ((a1 << 8) & 0xFFFFFF00);
            u32 v2 = ((a3 >> 24) & 0xFF) | ((a2 << 8) & 0xFFFFFF00);
            u32 v3 = a4 | ((a3 << 8) & 0xFFFFFF00);
            *(u32 *)(dst + 0x00) = (a0 & v0) + (((lo & (a0 ^ v0)) >> 1) + (hi & (a0 ^ v0)));
            *(u32 *)(dst + 0x04) = (a1 & v1) + (((lo & (a1 ^ v1)) >> 1) + (hi & (a1 ^ v1)));
            *(u32 *)(dst + 0x40) = (a2 & v2) + (((lo & (a2 ^ v2)) >> 1) + (hi & (a2 ^ v2)));
            *(u32 *)(dst + 0x44) = (a3 & v3) + (((lo & (a3 ^ v3)) >> 1) + (hi & (a3 ^ v3)));
            src += stride;
            dst += 8;
            if (i == 7) {
                dst += 0x40;
            }
        }
        break;
    }
    case 1: {
        u32 hi = 0x01010101;
        u32 lo = 0xFEFEFE;
        s32 i;
        src -= 1;
        for (i = 0; i < 16; i++) {
            u32 a0 = *(u32 *)(src + 0x00);
            u32 a1 = *(u32 *)(src + 0x04);
            u32 a2 = *(u32 *)(src + 0x08);
            u32 a3 = *(u32 *)(src + 0x0C);
            u32 a4 = *(u32 *)(src + 0x10);
            u32 v0 = ((a1 >> 24) & 0xFF) | ((a0 << 8) & 0xFFFFFF00);
            u32 w0 = ((a1 >> 16) & 0xFFFF) | ((a0 << 16) & 0xFFFF0000);
            u32 v1 = ((a2 >> 24) & 0xFF) | ((a1 << 8) & 0xFFFFFF00);
            u32 w1 = ((a2 >> 16) & 0xFFFF) | ((a1 << 16) & 0xFFFF0000);
            u32 v2 = ((a3 >> 24) & 0xFF) | ((a2 << 8) & 0xFFFFFF00);
            u32 w2 = ((a3 >> 16) & 0xFFFF) | ((a2 << 16) & 0xFFFF0000);
            u32 v3 = ((a4 >> 24) & 0xFF) | ((a3 << 8) & 0xFFFFFF00);
            u32 w3 = ((a4 >> 16) & 0xFFFF) | ((a3 << 16) & 0xFFFF0000);
            *(u32 *)(dst + 0x00) = (v0 & w0) + (((lo & (v0 ^ w0)) >> 1) + (hi & (v0 ^ w0)));
            *(u32 *)(dst + 0x04) = (v1 & w1) + (((lo & (v1 ^ w1)) >> 1) + (hi & (v1 ^ w1)));
            *(u32 *)(dst + 0x40) = (v2 & w2) + (((lo & (v2 ^ w2)) >> 1) + (hi & (v2 ^ w2)));
            *(u32 *)(dst + 0x44) = (v3 & w3) + (((lo & (v3 ^ w3)) >> 1) + (hi & (v3 ^ w3)));
            src += stride;
            dst += 8;
            if (i == 7) {
                dst += 0x40;
            }
        }
        break;
    }
    case 2: {
        u32 hi = 0x01010101;
        u32 lo = 0xFEFEFE;
        s32 i;
        src -= 2;
        for (i = 0; i < 16; i++) {
            u32 a0 = *(u32 *)(src + 0x00);
            u32 a1 = *(u32 *)(src + 0x04);
            u32 a2 = *(u32 *)(src + 0x08);
            u32 a3 = *(u32 *)(src + 0x0C);
            u32 a4 = *(u32 *)(src + 0x10);
            u32 v0 = ((a1 >> 16) & 0xFFFF) | ((a0 << 16) & 0xFFFF0000);
            u32 w0 = ((a1 >> 8) & 0xFFFFFF) | ((a0 << 24) & 0xFF000000);
            u32 v1 = ((a2 >> 16) & 0xFFFF) | ((a1 << 16) & 0xFFFF0000);
            u32 w1 = ((a2 >> 8) & 0xFFFFFF) | ((a1 << 24) & 0xFF000000);
            u32 v2 = ((a3 >> 16) & 0xFFFF) | ((a2 << 16) & 0xFFFF0000);
            u32 w2 = ((a3 >> 8) & 0xFFFFFF) | ((a2 << 24) & 0xFF000000);
            u32 v3 = ((a4 >> 16) & 0xFFFF) | ((a3 << 16) & 0xFFFF0000);
            u32 w3 = ((a4 >> 8) & 0xFFFFFF) | ((a3 << 24) & 0xFF000000);
            *(u32 *)(dst + 0x00) = (v0 & w0) + (((lo & (v0 ^ w0)) >> 1) + (hi & (v0 ^ w0)));
            *(u32 *)(dst + 0x04) = (v1 & w1) + (((lo & (v1 ^ w1)) >> 1) + (hi & (v1 ^ w1)));
            *(u32 *)(dst + 0x40) = (v2 & w2) + (((lo & (v2 ^ w2)) >> 1) + (hi & (v2 ^ w2)));
            *(u32 *)(dst + 0x44) = (v3 & w3) + (((lo & (v3 ^ w3)) >> 1) + (hi & (v3 ^ w3)));
            src += stride;
            dst += 8;
            if (i == 7) {
                dst += 0x40;
            }
        }
        break;
    }
    case 3: {
        u32 hi = 0x01010101;
        u32 lo = 0xFEFEFE;
        s32 i;
        src -= 3;
        for (i = 0; i < 16; i++) {
            u32 a0 = *(u32 *)(src + 0x00);
            u32 a1 = *(u32 *)(src + 0x04);
            u32 a2 = *(u32 *)(src + 0x08);
            u32 a3 = *(u32 *)(src + 0x0C);
            u32 a4 = *(u32 *)(src + 0x10);
            u32 v0 = ((a1 >> 8) & 0xFFFFFF) | ((a0 << 24) & 0xFF000000);
            u32 v1 = ((a2 >> 8) & 0xFFFFFF) | ((a1 << 24) & 0xFF000000);
            u32 v2 = ((a3 >> 8) & 0xFFFFFF) | ((a2 << 24) & 0xFF000000);
            u32 v3 = ((a4 >> 8) & 0xFFFFFF) | ((a3 << 24) & 0xFF000000);
            *(u32 *)(dst + 0x00) = (a1 & v0) + (((lo & (a1 ^ v0)) >> 1) + (hi & (a1 ^ v0)));
            *(u32 *)(dst + 0x04) = (a2 & v1) + (((lo & (a2 ^ v1)) >> 1) + (hi & (a2 ^ v1)));
            *(u32 *)(dst + 0x40) = (a3 & v2) + (((lo & (a3 ^ v2)) >> 1) + (hi & (a3 ^ v2)));
            *(u32 *)(dst + 0x44) = (a4 & v3) + (((lo & (a4 ^ v3)) >> 1) + (hi & (a4 ^ v3)));
            src += stride;
            dst += 8;
            if (i == 7) {
                dst += 0x40;
            }
        }
        break;
    }
    }
}
