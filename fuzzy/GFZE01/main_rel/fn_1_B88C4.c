/* Non-matching: best partial attempt (43.46% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/memcard.h"

extern f32 lbl_1_rodata_4AE0[114];
extern s32 fn_1_45D0(u32, u32, const char *, int);
extern void fn_1_46B4(u32, const void *, const char *, int);
extern u32 lbl_801A6410;
extern u32 fn_1_B8170(s32);
extern s32 fn_8002DFE0(s32, void *, void *);
extern Obj_1_data_3C7B8 lbl_1_data_3C7B8;
extern u8 lbl_1_bss_716C0;
extern s16 lbl_1_bss_962;

static s32 wait_ready(s32 card, void *work) {
    s32 result;
    do {
        result = fn_8002DFE0(card, work, 0);
    } while (result == -1);
    return result;
}

static s32 ceil_blocks(u32 value) {
    s32 n = (s32)((value + 0x405f) & ~0x1fff);
    return (n >> 13) + (n < 0 && (n & 0x1fff) != 0);
}

static s32 quota(u8 *table, u32 offset, u32 unitOffset) {
    u32 v = *(u32 *)(table + offset);
    s32 n;
    if (v != 0) {
        n = ceil_blocks(v);
    } else {
        u8 c = table[unitOffset];
        n = (c == 4 || c == 2) ? 3 : (c == 5 ? 13 : 0);
    }
    return n;
}

s32 fn_1_B88C4(void) {
    u8 *base = (u8 *)&lbl_1_bss_716C0;
    u8 *entry;
    s32 card;
    s32 result;
    s32 freeBlocks;
    s32 usedBlocks;
    s32 q0, q1, q2, q3, q4;
    s32 a0, a1, a2, a3, a4;
    u32 flags;
    u32 value;
    u8 *table;

    *(u32 *)(base + 0x5c74) = 0;
    base[0x5c78] = 1;
    result = 0;
    if ((s8)base[9] != -1 && (s8)base[9] != -3)
        result = 1;
    if (result == 0 && (s8)base[0xa9] != -1 && (s8)base[0xa9] != -3)
        result = 1;
    if (result == 0)
        return 0;
    card = base[0x1f1];
    if ((u32)card > 1)
        return 0;
    entry = base + 8 + card * 0xa0;
    *(u32 *)(entry + 0xc) = fn_1_45D0(lbl_801A6410, 0xa000,
                                       (const char *)&lbl_1_data_3C7B8, 0x256d);
    for (;;) {
        result = wait_ready(card, *(void **)(entry + 0xc));
        if (result != 0 && result != -6) {
            if (*(u32 *)(entry + 0xc) != 0) {
                fn_1_46B4(*(u32 *)0x801A6410, (const char *)&lbl_1_data_3C7B8,
                          (const char *)&lbl_1_data_3C7B8, 0x2573);
                *(u32 *)(entry + 0xc) = 0;
            }
        } else {
            do {
                result = CARDCheck(card);
            } while (result == -1);
        }
        break;
    }
    if (result != 0) {
        do {
            result = CARDUnmount(card);
        } while (result == -1);
        if (*(u32 *)(entry + 0xc) != 0) {
            fn_1_46B4(*(u32 *)0x801A6410, (const char *)&lbl_1_data_3C7B8,
                      (const char *)&lbl_1_data_3C7B8, 0x258c);
            *(u32 *)(entry + 0xc) = 0;
        }
        return 0;
    }

    do {
        result = CARDFreeBlocks(card, (s32 *)(entry + 0x3c), (s32 *)(entry + 0x40));
    } while (result == -1);
    if (result != 0) {
        *(s32 *)(entry + 0x3c) = -1;
        *(s32 *)(entry + 0x40) = -1;
    } else {
        *(s32 *)(entry + 0x3c) = *(s32 *)(entry + 0x3c) / 8192;
    }
    flags = fn_1_B8170(card);
    table = (u8 *)lbl_1_rodata_4AE0;
    q0 = quota(table, 0x8c, 0x6b);
    value = *(u32 *)(entry + 0x3c);
    a0 = q0;
    if (*(s32 *)(entry + 0x40) <= 0 || (s32)(value - q0) < 0)
        a0 = -q0;

    q1 = quota(table, 0x124, 0x103);
    a1 = q1;
    if (*(s32 *)(entry + 0x40) <= 0 || (s32)(value - q1) < 0)
        a1 = -q1;
    q2 = quota(table, 0xd8, 0xb7);
    a2 = q2;
    if (*(s32 *)(entry + 0x40) <= 0 || (s32)(value - q2) < 0)
        a2 = -q2;
    q3 = quota(table, 0x170, 0x14f);
    a3 = q3;
    if (*(s32 *)(entry + 0x40) <= 0 || (s32)(value - q3) < 0)
        a3 = -q3;
    q4 = quota(table, 0x1bc, 0x19b);
    a4 = q4;
    if (*(s32 *)(entry + 0x40) <= 0 || (s32)(value - q4) < 0)
        a4 = -q4;

    do {
        result = CARDUnmount(card);
    } while (result == -1);
    if (*(u32 *)(entry + 0xc) != 0) {
        fn_1_46B4(*(u32 *)0x801A6410, (const char *)&lbl_1_data_3C7B8,
                  (const char *)&lbl_1_data_3C7B8, 0x258c);
        *(u32 *)(entry + 0xc) = 0;
    }
    if (lbl_1_bss_962 == 100) {
        if (a3 < 0 && (flags & 0x10) == 0)
            return 1;
        return *(s32 *)(entry + 0x40) > 0 ? 0 : 1;
    }
    if (a1 < 0 && (flags & 4) == 0)
        return 1;
    if (a2 < 0 && (flags & 8) == 0)
        return 1;
    if (a3 < 0 && (flags & 2) == 0)
        return 1;
    if (a4 < 0 && (flags & 0x10) == 0)
        return 1;
    if (a0 < 0 && (flags & 0x20) == 0)
        return 1;
    return *(s32 *)(entry + 0x40) > 0 ? 0 : 1;
}
