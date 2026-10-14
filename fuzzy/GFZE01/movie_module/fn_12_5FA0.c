/* Non-matching: best partial attempt (98.50% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_12_5FA0_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
};

extern s32 fn_12_670C(const u8 *);

static inline u8 * fn_12_5FA0_address_3651(u8 * base, s32 offset) {
    return base + offset;
}
void fn_12_5FA0(struct fn_12_5FA0_Arg0 *arg0, const void *arg1, int *arg2) {
    u32 acc;
    s32 bit;
    u32 nxt_2;
    struct { u32 value; } nxt;
    u8 *q = (u8 *)(((u32)arg1 + 4) & ~3u);
    u8 *end;

    bit = (s32)(((u32)arg1 + 4 - (u32)q) << 3);
    acc = *(u32 *)q;
    nxt.value = *(u32 *)(q + 4);
    acc <<= bit;
    q += 8;

    if (bit >= 16) {
        bit -= 16;
        if (bit != 0) {
            acc |= nxt.value >> (16 - bit);
            arg0->unk_0 = acc >> 16;
            acc = nxt.value << bit;
        } else {
            arg0->unk_0 = acc >> 16;
            acc = nxt.value;
        }
        nxt_2 = *(u32 *)q;
        q += 4;
    } else {
        arg0->unk_0 = acc >> 16;
        bit += 16;
        acc <<= 16;
    }

    bit++;
    if (bit >= 32) {
        bit -= 32;
        acc = nxt_2 << bit;
        nxt_2 = *(u32 *)q;
        q += 4;
    } else {
        acc <<= 1;
    }

    if (bit >= 10) {
        bit -= 10;
        if (bit != 0) {
            acc |= nxt_2 >> (22 - bit);
            arg0->unk_4 = acc >> 10;
            acc = nxt_2 << bit;
        } else {
            arg0->unk_4 = acc >> 10;
            acc = nxt_2;
        }
        nxt_2 = *(u32 *)q;
        q += 4;
    } else {
        arg0->unk_4 = acc >> 10;
        bit += 22;
        acc <<= 22;
    }

    bit++;
    if (bit >= 32) {
        bit -= 32;
        acc = nxt_2 << bit;
        nxt_2 = *(u32 *)q;
        q += 4;
    } else {
        acc <<= 1;
    }

    if (bit >= 26) {
        bit -= 26;
        if (bit != 0) {
            acc |= nxt_2 >> (6 - bit);
            arg0->unk_8 = acc >> 26;
            acc = nxt_2 << bit;
        } else {
            arg0->unk_8 = acc >> 26;
            acc = nxt_2;
        }
        nxt_2 = *(u32 *)q;
        q += 4;
    } else {
        arg0->unk_8 = acc >> 26;
        bit += 6;
        acc <<= 6;
    }

    arg0->unk_10 = acc >> 31;
    if (bit == 31) {
        acc = nxt_2;
        nxt_2 = *(u32 *)q;
        bit = 0;
        q += 4;
    } else {
        bit++;
        acc <<= 1;
    }

    arg0->unk_14 = acc >> 31;
    if (bit == 31) {
        acc = nxt_2;
        nxt_2 = *(u32 *)q;
        bit = 0;
        q += 4;
    } else {
        bit++;
        acc <<= 1;
    }

    arg0->unk_18 = acc >> 31;
    if (bit == 31) {
        acc = nxt_2;
        nxt_2 = *(u32 *)q;
        bit = 0;
        q += 4;
    } else {
        acc <<= 1;
        bit++;
    }

    arg0->unk_1C = acc >> 31;
    if (bit == 31) {
        acc = nxt_2;
        nxt_2 = *(u32 *)q;
        bit = 0;
        q += 4;
    } else {
        bit++;
        acc <<= 1;
    }

    bit++;
    if (bit >= 32) {
        bit -= 32;
        acc = nxt_2 << bit;
        nxt_2 = *(u32 *)q;
        q += 4;
    } else {
        acc <<= 1;
    }

    if (bit >= 27) {
        bit -= 27;
        if (bit != 0) {
            acc |= nxt_2 >> (5 - bit);
            arg0->unk_C = acc >> 27;
            acc = nxt_2 << bit;
        } else {
            arg0->unk_C = acc >> 27;
            acc = nxt_2;
        }
        nxt_2 = *(u32 *)q;
        q += 4;
    } else {
        arg0->unk_C = acc >> 27;
        bit += 5;
        acc <<= 5;
    }

    bit += 8;
    if (bit >= 32) {
        bit -= 32;
        acc = nxt_2 << bit;
        nxt_2 = *(u32 *)q;
        q += 4;
    } else {
        acc <<= 8;
    }

    for (;;) {
        if ((acc >> 31) == 0) {
            break;
        }
        bit += 24;
        if (bit >= 32) {
            bit -= 32;
            acc = nxt_2 << bit;
            nxt_2 = *(u32 *)q;
            q += 4;
        } else {
            acc <<= 24;
        }
    }

    end = fn_12_5FA0_address_3651(q, (u32)((bit + 7) / 8) - 8);
    *arg2 = (int)(end - (u8 *)arg1);
    if (fn_12_670C(end) == 0) {
        u32 tag = (u32)fn_12_670C(end + 1);
        if (tag - 4 != 0) {
            return;
        }
        *arg2 = *arg2 + 1;
    }
}
