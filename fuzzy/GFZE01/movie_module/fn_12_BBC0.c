/* Non-matching: best partial attempt (97.67% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MovieData MovieData;
typedef struct MovieObject MovieObject;

typedef struct MovieOut {
    u32 field_00;
    u32 field_04;
} MovieOut;

typedef struct MovieVTable {
    u8 pad_0000[0x18];
    void (*method_0018)(MovieObject *, s32, s32, u32 *);
    void (*method_001c)(MovieObject *, s32, MovieOut *);
    void (*method_0020)(MovieObject *, s32, u32 *);
} MovieVTable;

struct MovieObject {
    MovieVTable *vtable;
};

struct MovieData {
    u8 pad_0000[0x1a8];
    s32 field_01a8;
    u8 pad_01ac[0x24];
    s32 field_01d0;
    s32 field_01d4;
    s32 field_01d8;
    s32 field_01dc;
    s32 field_01e0;
    u8 pad_01e4[0x90];
    s32 field_0274;
    s32 field_0278;
    s32 field_027c;
    s32 field_0280;
    u8 pad_0284[0x0c];
    s32 field_0290;
    u8 pad_0294[0x78];
    s32 field_030c;
    u8 pad_0310[0x930];
    s8 field_0c40[0x40];
    s8 field_0c80[0x40];
    u8 pad_0cc0[0x608];
    u32 field_12c8;
    s32 field_12cc;
    s32 field_12d0;
    u8 pad_12d4[0x30];
    s32 field_1304;
    u8 pad_1308[0x3c];
    u8 field_1344[0x648];
};

extern s8 lbl_12_bss_4E00[64];
extern u8 lbl_12_bss_4DC0[64];
extern s32 lbl_12_rodata_7A4[];
extern s32 lbl_12_rodata_7AC[];
extern void fn_12_33364(u32 *, u32 *, u32);
extern void fn_12_33428(u32 *, u32, u32);
extern u32 fn_800589BC(u32 *, u32, u32 *, MovieOut *);

#define GET_BITS(dst, w) \
    if (bits >= (32 - (w))) { \
        bits -= (32 - (w)); \
        if (bits) { \
            cur |= next >> ((w) - bits); \
            (dst) = cur >> (32 - (w)); \
            cur = next << bits; \
        } else { \
            (dst) = cur >> (32 - (w)); \
            cur = next; \
        } \
        next = *p++; \
    } else { \
        (dst) = cur >> (32 - (w)); \
        cur <<= (w); \
        bits += (w); \
    }

#define GET_BIT(dst) \
    { \
        (dst) = cur >> 31; \
        if (bits == 31) { \
            cur = next; \
            next = *p++; \
            bits = 0; \
        } else { \
            cur <<= 1; \
            bits++; \
        } \
    }

s32 fn_12_BBC0(MovieData *arg0, MovieObject *arg1) {
    u32 next;
    s32 bits;
    u32 cur;
    u32 *p;
    u32 v;
    u32 b0;
    u32 b1;
    s32 i;
    s32 j;
    s32 k;
    u8 *end;
    s32 idx;
    u8 *q;
    s32 col;
    s32 row;
    s32 w;
    s32 cnt;
    MovieOut out;

    arg0->field_1304 = 1;
    arg1->vtable->method_0018(arg1, 1, 0x7FFFFFFF, &arg0->field_12c8);

    p = (u32 *)(arg0->field_12c8 & ~3);
    cur = p[1];
    bits = (arg0->field_12c8 - (u32)p) * 8;
    p += 2;
    if (bits >= 32) {
        cur = *p++;
        bits -= 32;
    }
    if (bits) {
        cur <<= bits;
    }
    next = *p++;

    GET_BITS(arg0->field_01d0, 12)
    GET_BITS(arg0->field_01d4, 12)
    GET_BITS(arg0->field_0274, 4)
    GET_BITS(v, 4)
    arg0->field_01e0 = v;
    GET_BITS(arg0->field_0278, 18)

    bits++;
    if (bits >= 32) {
        bits -= 32;
        cur = next << bits;
        next = *p++;
    } else {
        cur <<= 1;
    }

    GET_BITS(arg0->field_027c, 10)

    GET_BIT(arg0->field_0280)
    GET_BIT(b0)
    if (b0) {
        for (i = 0; i < 32; i++) {
            k = i;
            for (j = 0; j < 2; j++) {
                GET_BITS(v, 8)
                arg0->field_0c40[lbl_12_bss_4E00[k]] = v;
                k++;
            }
        }
    } else {
        fn_12_33364((u32 *)arg0->field_0c40, (u32 *)lbl_12_bss_4DC0, 0x10);
    }

    GET_BIT(b1)
    if (b1) {
        for (i = 0; i < 32; i++) {
            for (j = 0; j < 2; j++) {
                GET_BITS(v, 8)
                arg0->field_0c80[lbl_12_bss_4E00[i + j]] = v;
            }
        }
    } else {
        fn_12_33428((u32 *)arg0->field_0c80, 0x10101010, 0x10);
    }

    arg0->field_01d8 = (arg0->field_01d0 + 15) >> 4;
    arg0->field_01dc = (arg0->field_01d4 + 15) >> 4;
    arg0->field_030c = arg0->field_01dc * arg0->field_01d8 - 1;

    w = arg0->field_01d8;
    idx = (arg0->field_01a8 != 3);
    if (w * arg0->field_01dc < 0x654) {
        q = arg0->field_1344;
        col = row = 0;
        end = q + 0xca8;
        while (q < end) {
            if (col >= w) {
                col = 0;
                row++;
            }
            q[0] = row;
            q[1] = col;
            q += 2;
            col++;
        }
        arg0->field_0290 = lbl_12_rodata_7A4[idx];
    } else {
        arg0->field_0290 = lbl_12_rodata_7AC[idx];
    }

    arg0->field_12d0 = bits & 7;
    cnt = (bits - arg0->field_12d0 + 7) >> 3;
    fn_800589BC(&arg0->field_12c8, arg0->field_12c8 - (((u32)p + cnt) - 8), &arg0->field_12c8, &out);
    arg1->vtable->method_0020(arg1, 0, &arg0->field_12c8);
    arg1->vtable->method_001c(arg1, 1, &out);
    return 0;
}
