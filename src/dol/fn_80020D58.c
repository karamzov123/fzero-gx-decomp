#include "types.h"


/* --- dol/fn_80020CB0.c --- */
struct fn_80020CB0_object {
    struct fn_80020CB0_object *next;
    struct fn_80020CB0_object *prev;
    u8 pad_8[4];
    u32 index;
};

extern struct fn_80020CB0_object *lbl_8015D100[];
extern struct fn_80020CB0_object *lbl_8015D180[];
extern u32 OSDisableInterrupts(u32);
extern u32 OSRestoreInterrupts(u32);
extern u32 fn_80020A28(u32);

void fn_80020CB0(struct fn_80020CB0_object *arg0, u32 arg1);

/* --- dol/fn_80020D58.c --- */
struct fn_80020D58_entry_a {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3C;
};

struct fn_80020D58_entry_b {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3C;
};

extern struct fn_80020D58_entry_a lbl_8015D200[];
extern struct fn_80020D58_entry_b lbl_8015E880[];
extern u32 lbl_801A6AC0;
extern u32 lbl_801A6AC4;
extern u32 lbl_801A6AC8;
extern u32 lbl_801A6ACC;
extern u32 lbl_801A6AE0;
extern u32 lbl_801A6AE4;
extern u32 lbl_801A6AE8;
extern u32 lbl_801A6AEC;
extern u32 lbl_801A6AF0;

void fn_80020D58(void) {
    struct fn_80020D58_entry_a *entry_a;
    struct fn_80020D58_entry_b *entry_b;
    u32 i;

    lbl_801A6AC0 = 0;
    lbl_801A6AC4 = 0;
    lbl_801A6AC8 = 0;
    lbl_801A6ACC = 0;
    lbl_801A6AE0 = 0;
    lbl_801A6AE4 = 1;
    lbl_801A6AE8 = 0;
    lbl_801A6AEC = 1;
    lbl_801A6AF0 = 2;
    entry_a = lbl_8015D200;
    entry_b = lbl_8015E880;
    for (i = 0; i < 30; i++) {
        entry_a->unk_0 = 0;
        entry_b->unk_0 = 0;
        entry_a->unk_4 = 0;
        entry_b->unk_4 = 0;
        entry_a->unk_8 = 0;
        entry_b->unk_8 = 0;
        entry_a->unk_C = 0;
        entry_b->unk_C = 0;
        entry_a->unk_10 = 0;
        entry_b->unk_10 = 0;
        entry_a->unk_14 = 0;
        entry_b->unk_14 = 0;
        entry_a->unk_18 = 0;
        entry_b->unk_18 = 0;
        entry_a->unk_1C = 0;
        entry_b->unk_1C = 0;
        entry_a->unk_20 = 0;
        entry_b->unk_20 = 0;
        entry_a->unk_24 = 0;
        entry_b->unk_24 = 0;
        entry_a->unk_28 = 0;
        entry_b->unk_28 = 0;
        entry_a->unk_2C = 0;
        entry_b->unk_2C = 0;
        entry_a->unk_30 = 0;
        entry_b->unk_30 = 0;
        entry_a->unk_34 = 0;
        entry_b->unk_34 = 0;
        entry_a->unk_38 = 0;
        entry_b->unk_38 = 0;
        entry_a->unk_3C = 0;
        entry_b->unk_3C = 0;
        entry_a++;
        entry_b++;
    }
}

/* --- dol/fn_80020E3C.c --- */
void fn_80020E3C(void) {
    lbl_801A6AC0 = 0;
    lbl_801A6AC4 = 0;
}
