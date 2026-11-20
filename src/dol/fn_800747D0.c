#include "types.h"


/* --- dol/fn_800747D0.c --- */
extern u32 lbl_801A6D38;
extern u32 fn_80035960(u32, u32, u32, u32, u32, u32, u32);

typedef struct {
    u8 unk_00;
    s32 unk_04;
    s32 unk_08;
    u32 unk_0C;
    s32 unk_10;
    s32 unk_14;
} fn_800747D0_Entry;

void fn_800747D0(u32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6) {
    fn_800747D0_Entry *entry;
    u32 id;

    id = arg0;
    switch (arg0) {
    case 0:
        entry = (fn_800747D0_Entry *)(lbl_801A6D38 + 3120);
        break;
    case 1:
        entry = (fn_800747D0_Entry *)(lbl_801A6D38 + 3144);
        break;
    case 2:
        entry = (fn_800747D0_Entry *)(lbl_801A6D38 + 3168);
        break;
    case 3:
        break;
    case 4:
        fn_800747D0(0, arg1, arg2, arg3, arg4, arg5, arg6);
        id = 2;
        entry = (fn_800747D0_Entry *)(lbl_801A6D38 + 3168);
        break;
    case 5:
        fn_800747D0(1, arg1, arg2, arg3, arg4, arg5, arg6);
        id = 3;
        entry = (fn_800747D0_Entry *)(lbl_801A6D38 + 3192);
        break;
    }
    if (entry->unk_00 != (arg1 & 0xFF) || entry->unk_04 != arg2 || entry->unk_08 != arg3 || entry->unk_0C != arg4 || entry->unk_10 != arg5 || entry->unk_14 != arg6) {
        fn_80035960(id, arg1, arg2, arg3, arg4, arg5, arg6);
        entry->unk_00 = arg1;
        entry->unk_04 = arg2;
        entry->unk_08 = arg3;
        entry->unk_0C = arg4;
        entry->unk_10 = arg5;
        entry->unk_14 = arg6;
    }
}

/* --- dol/fn_80074918.c --- */
extern void fn_80037BC0(u8 arg0, s32 arg1, u8 arg2);

typedef struct CacheData {
    u8 unk_00;
    u8 unk_01[3];
    s32 unk_04;
    u8 unk_08;
} CacheData;

void fn_80074918(u8 arg0, s32 arg1, u8 arg2) {
    CacheData *cache;

    cache = (CacheData *)lbl_801A6D38;
    if (cache->unk_00 == arg0 && cache->unk_04 == arg1 && cache->unk_08 == arg2) {
        return;
    }

    fn_80037BC0(arg0, arg1, arg2);
    ((CacheData *)lbl_801A6D38)->unk_00 = arg0;
    ((CacheData *)lbl_801A6D38)->unk_04 = arg1;
    ((CacheData *)lbl_801A6D38)->unk_08 = arg2;
}
