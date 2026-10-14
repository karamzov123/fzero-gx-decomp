/* Non-matching: best partial attempt (72.63% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/memcard.h"
#include "dolphin/card.h"

extern f32 lbl_1_rodata_4AE0[114];
extern u32 lbl_801A6410;

extern s32 fn_1_45D0(u32, u32, Obj_1_data_3C7B8 *, s32);
extern void fn_1_46B4(u32, u32, Obj_1_data_3C7B8 *, s32);
extern u32 fn_1_B8170(s32);
extern s32 fn_8002DFE0(s32, s32, CARDCallback);

typedef struct {
    u8 byte_0;
    u8 pad_1[0x20];
    u8 val_21[4];
    u8 pad_25[0x27];
} TabEntry;

typedef struct {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
    s32 unk_14;
} McSlot;

#define TAB(n) ((TabEntry *)((u8 *)lbl_1_rodata_4AE0 + 0x6b))[n]

static inline s32 calc_size(s32 value, u8 type, s32 blocks, s32 last) {
    s32 result;

    result = (value + 0x405f) / 0x2000;
    if ((u32)value == 0) {
        if (type == 4) {
            result = 3;
        } else if (type == 5) {
            result = 13;
        } else if (type == 2) {
            result = 3;
        }
    }

    if (last <= 0) {
        result = -result;
    } else if (blocks - result < 0) {
        result = -result;
    }

    return result;
}

s32 fn_1_B8338(s32 card) {
    u8 *base;
    u8 *entry;
    u32 *flagp;
    McSlot *info;
    s32 status;
    s32 result;
    s8 state;

    base = &lbl_1_bss_716C0;
    state = (base + 8 + card * 0xa0)[1];
    status = 0;
    *(s32 *)(base + 0x5c74) = status;
    base[0x5c78] = 1;
    if (state != -1 && state != -3) {
        status = 1;
    }
    base[0x5c79] = (u8)card;
    if (status == 0) {
        return 0;
    }

    entry = base + 8 + card * 0xa0;
    *(u32 *)(entry + 0xc) = fn_1_45D0(lbl_801A6410, 0xA000, &lbl_1_data_3C7B8, 0x256d);
    do {
        result = fn_8002DFE0(card, *(u32 *)(entry + 0xc), 0);
    } while (result == -1);

    if (result != 0 && result != -6) {
        if (*(u32 *)(entry + 0xc) != 0) {
            fn_1_46B4(lbl_801A6410, *(u32 *)(entry + 0xc), &lbl_1_data_3C7B8, 0x2573);
            *(u32 *)(entry + 0xc) = 0;
        }
    } else {
        do {
            result = CARDCheck(card);
        } while (result == -1);
    }

    if (result != 0) {
        do {
            result = CARDUnmount(card);
        } while (result == -1);
        if (*(u32 *)(entry + 0xc) != 0) {
            fn_1_46B4(lbl_801A6410, *(u32 *)(entry + 0xc), &lbl_1_data_3C7B8, 0x258c);
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
        *(s32 *)(entry + 0x3c) /= 0x2000;
    }

    flagp = (u32 *)(base + 0x5c7c);
    flagp[card] = fn_1_B8170(card);

    info = (McSlot *)(base + 0x5c84);

    info[card].unk_4 = calc_size((s32)*(u32 *)TAB(0).val_21, TAB(0).byte_0,
                                 *(s32 *)(entry + 0x3c), *(s32 *)(entry + 0x40));
    info[card].unk_C = calc_size((s32)*(u32 *)TAB(1).val_21, TAB(1).byte_0,
                                 *(s32 *)(entry + 0x3c), *(s32 *)(entry + 0x40));
    info[card].unk_8 = calc_size((s32)*(u32 *)TAB(2).val_21, TAB(2).byte_0,
                                 *(s32 *)(entry + 0x3c), *(s32 *)(entry + 0x40));
    info[card].unk_10 = calc_size((s32)*(u32 *)TAB(3).val_21, TAB(3).byte_0,
                                  *(s32 *)(entry + 0x3c), *(s32 *)(entry + 0x40));
    info[card].unk_14 = calc_size((s32)*(u32 *)TAB(4).val_21, TAB(4).byte_0,
                                  *(s32 *)(entry + 0x3c), *(s32 *)(entry + 0x40));

    do {
        result = CARDUnmount(card);
    } while (result == -1);
    if (*(u32 *)(entry + 0xc) != 0) {
        fn_1_46B4(lbl_801A6410, *(u32 *)(entry + 0xc), &lbl_1_data_3C7B8, 0x258c);
        *(u32 *)(entry + 0xc) = 0;
    }

    if (lbl_1_bss_962 == 100) {
        if (info[card].unk_10 < 0 && !(flagp[card] & 0x10)) {
            return 1;
        }
        return (*(s32 *)(entry + 0x40) > 0) ? 0 : 1;
    }

    if (info[card].unk_4 < 0 && !(flagp[card] & 0x2)) {
        return 1;
    }
    if (info[card].unk_C < 0 && !(flagp[card] & 0x8)) {
        return 1;
    }
    if (info[card].unk_8 < 0 && !(flagp[card] & 0x4)) {
        return 1;
    }
    if (info[card].unk_10 < 0 && !(flagp[card] & 0x10)) {
        return 1;
    }
    if (info[card].unk_14 < 0 && !(flagp[card] & 0x20)) {
        return 1;
    }
    return (*(s32 *)(entry + 0x40) > 0) ? 0 : 1;
}
