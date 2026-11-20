#include "types.h"


/* --- dol/fn_800504EC.c --- */
struct fn_800504EC_Vtbl {
    u8 pad_0[0x24];
    u32 (*unk_24)(void *, u32);
};

struct fn_800504EC_Obj {
    struct fn_800504EC_Vtbl *vtbl;
};

struct fn_800504EC_Slot {
    s32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    s32 unk_14;
    s32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
};

extern struct fn_800504EC_Slot lbl_80186FAC[8];
extern void *memset(void *, int, u32);

void *fn_800504EC(struct fn_800504EC_Obj *arg0) {
    struct fn_800504EC_Slot *slot;
    s32 i;
    u32 a;
    u32 b;

    for (i = 0; i < 8; i++) {
        if (lbl_80186FAC[i].unk_0 == 0) {
            break;
        }
    }
    if (i >= 8) {
        return 0;
    }

    slot = &lbl_80186FAC[i];
    memset(slot, 0, 44);
    slot->unk_4 = (u32)arg0;
    slot->unk_10 = 0;
    a = arg0->vtbl->unk_24(arg0, 0);
    b = arg0->vtbl->unk_24(arg0, 1);
    slot->unk_14 = b + a;
    slot->unk_18 = slot->unk_14 / 4;
    slot->unk_24 = 0;
    slot->unk_1C = 0;
    slot->unk_20 = 0;
    slot->unk_28 = 0;
    slot->unk_0 = 1;
    return slot;
}

/* --- dol/fn_80050670.c --- */
struct fn_80050670_Arg1 {
    u32 unk_0;
};
struct fn_80050670_lbl_8012D9B8 {
    u32 unk_0[1];
};

extern struct fn_80050670_lbl_8012D9B8 lbl_8012D9B8[];
extern u32 lbl_8012D9BC[];

u32 fn_80050670(u32 arg0, struct fn_80050670_Arg1 *arg1) {
    arg1->unk_0 = (u32)((u8 *)&lbl_8012D9BC + (arg0 * 12288));
    return lbl_8012D9B8[0].unk_0[arg0];
}
