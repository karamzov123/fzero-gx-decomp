#include "types.h"


/* --- dol/fn_800579F0.c --- */
/* --- dol/fn_800579F0.c --- */
typedef u32 (*fn_800579F0_Fn0)(u32, u32);
extern u32 fn_80057728(void);

s32 fn_800576DC();                              /* extern */

void fn_800579F0(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    s32 var_r0;
    s32 (*temp_r12)(s32, s32);
    s32 temp_r3;

    fn_80057728();
    if (arg1 == 0) {
        (*(s32 *)((u8 *)(arg3) + 4)) = 0;
        (*(s32 *)((u8 *)(arg3))) = 0;
    } else if (arg1 == 1) {
        temp_r3 = *(s32 *)((u8 *)(arg0) + 12);
        var_r0 = arg2;
        if (temp_r3 < arg2) {
            var_r0 = temp_r3;
        }
        (*(s32 *)((u8 *)(arg3) + 4)) = var_r0;
        (*(s32 *)((u8 *)(arg3))) = ((*(s32 *)((u8 *)(arg0) + 20)) + (*(s32 *)((u8 *)(arg0) + 16)));
        (*(s32 *)((u8 *)(arg0) + 16)) = ((*(s32 *)((u8 *)(arg0) + 16)) + (*(s32 *)((u8 *)(arg3) + 4)));
        (*(s32 *)((u8 *)(arg0) + 12)) = ((*(s32 *)((u8 *)(arg0) + 12)) - (*(s32 *)((u8 *)(arg3) + 4)));
    } else {
        (*(s32 *)((u8 *)(arg3) + 4)) = 0;
        (*(s32 *)((u8 *)(arg3))) = 0;
        temp_r12 = (s32 (*)(s32, s32))(*(s32 (**)(s32, s32))((u8 *)(arg0) + 28));
        if (temp_r12 != NULL) {
            temp_r12(*(s32 *)((u8 *)(arg0) + 32), -3);
        }
    }
    fn_800576DC();
}

/* --- dol/fn_80057AD8.c --- */
typedef void (*fn_80057AD8_Fn0)(u32, s32);

struct fn_80057AD8_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
    u8 pad_10[0xC];
    fn_80057AD8_Fn0 unk_1C;
    u32 unk_20;
};

s32 fn_80057AD8(struct fn_80057AD8_Arg0 *arg0, s32 arg1) {
    if (arg1 == 1) {
        return arg0->unk_C;
    } else if (arg1 == 0) {
        return 0;
    } else {
        if (arg0->unk_1C != 0) {
            arg0->unk_1C(arg0->unk_20, -3);
        }
        return 0;
    }
}

/* --- dol/fn_80057B34.c --- */
/* --- dol/fn_80057B34.c --- */
struct fn_80057B34_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
    u8 pad_14[0x4];
    u32 unk_18;
};

void fn_80057B34(struct fn_80057B34_Arg0 *arg0) {
    arg0->unk_C = arg0->unk_18;
    arg0->unk_10 = 0;
}

/* --- dol/fn_80057B48.c --- */
struct fn_80057B48_Arg0 {
    u8 pad_0[0x1C];
    u32 unk_1C;
    u32 unk_20;
};

void fn_80057B48(struct fn_80057B48_Arg0 *arg0, u32 arg1, u32 arg2) {
    arg0->unk_1C = arg1;
    arg0->unk_20 = arg2;
}

/* --- dol/fn_80057B54.c --- */
struct fn_80057B54_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

u32 fn_80057B54(struct fn_80057B54_Arg0 *arg0) {
    return arg0->unk_8;
}

/* --- dol/fn_80057B5C.c --- */
/* --- dol/fn_80057B5C.c --- */
extern u32 memset(u32, u32, u32);

void fn_80057B5C(u32 arg0) {
    if (arg0 != 0) {
    memset(arg0, 0, 36);
    *(u32 *)((u8 *)arg0 + 4) = 0;
    }
}

/* --- dol/fn_80057B9C.c --- */
typedef struct {
    void *vtable;
    int active;
    void *type;
    void *link;
    int zero;
    void *arg0;
    void *arg1;
    void *callback;
    void *self;
} Fn80057B9CEntry;

extern u8 lbl_8018AE1C[1156];
extern u8 lbl_801322D0[48];
extern u8 lbl_800922E0[16];
extern void fn_80057D60(void);

Fn80057B9CEntry *fn_80057B9C(void *arg0, void *arg1) {
    Fn80057B9CEntry *entry;
    int count;

    for (count = 0; count < 32; count++) {
        if (((Fn80057B9CEntry *)lbl_8018AE1C)[count].active == 0) {
            break;
        }
    }
    if (count == 32) {
        return 0;
    }
    entry = &((Fn80057B9CEntry *)lbl_8018AE1C)[count];
    entry->active = 1;
    entry->vtable = lbl_801322D0;
    entry->arg0 = arg0;
    entry->arg1 = arg1;
    entry->type = lbl_800922E0;
    entry->callback = fn_80057D60;
    entry->self = entry;
    entry->link = entry->arg1;
    entry->zero = 0;
    return entry;
}
