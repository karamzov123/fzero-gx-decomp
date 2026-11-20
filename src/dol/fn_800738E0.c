#include "types.h"
#include "dol/globals.h"


/* --- dol/fn_800738E0.c --- */
typedef struct {
    s32 unk_00;
    s32 unk_04;
    u16 unk_08;
    u16 unk_0A;
} Entry;

typedef struct {
    u8 pad_00[0x20];
    u16 unk_20;
    u16 unk_22;
} Sub;

extern void GXSetIndTexOrder(s32, s32, s32);

void fn_800738E0(s32 arg0, s32 arg1, s32 arg2) {
    Entry *entry = (Entry *)(lbl_801A6D38 + arg0 * 12 + 0x844);

    if (arg2 >= 8) {
        if (entry->unk_00 != arg0 || entry->unk_04 != arg2) {
            GXSetIndTexOrder(arg0, arg1, arg2);
            entry->unk_00 = arg1;
            entry->unk_04 = arg2;
            entry->unk_08 = 0;
            entry->unk_0A = 0;
        }
    } else {
        Sub *sub = (Sub *)(lbl_801A6D38 + arg2 * 36 + 0x720);

        if (entry->unk_00 != arg0 || entry->unk_04 != arg2 ||
            entry->unk_08 != sub->unk_20 || entry->unk_0A != sub->unk_22) {
            GXSetIndTexOrder(arg0, arg1, arg2);
            entry->unk_00 = arg1;
            entry->unk_04 = arg2;
            entry->unk_08 = sub->unk_20;
            entry->unk_0A = sub->unk_22;
        }
    }
}

/* --- dol/fn_800739E0.c --- */
typedef struct {
    s32 unk_00;
    s32 unk_04;
} Entry_u1;

extern void GXSetIndTexCoordScale(s32, s32, s32);

void fn_800739E0(s32 index, s32 arg1, s32 arg2) {
    Entry_u1 *entry;

    entry = (Entry_u1 *)(lbl_801A6D38 + (index << 3) + 0x874);
    if (entry->unk_00 != arg1 || entry->unk_04 != arg2) {
        GXSetIndTexCoordScale(index, arg1, arg2);
        entry->unk_00 = arg1;
        entry->unk_04 = arg2;
    }
}

/* --- dol/fn_80073A58.c --- */
typedef struct Entry_u2 {
    u8 unk_00[0x18];
    s8 unk_18;
    u8 unk_19[0x03];
} Entry_u2;

extern int fn_8008023C(Entry_u2 *entry, void *arg, int size);
extern void fn_80036AC4(int index, void *arg, s8 value);
extern void fn_800794F0(Entry_u2 *entry, void *arg, int size);

void fn_80073A58(int index, void *arg, s8 value) {
    Entry_u2 *entry;

    if (index == 0) {
        return;
    }

    if (index <= 3) {
        entry = (Entry_u2 *)(lbl_801A6D38 + (index - 1) * 0x1c + 0x894);
    } else if (index <= 7) {
        entry = (Entry_u2 *)(lbl_801A6D38 + (index - 5) * 0x1c + 0x894);
    } else if (index <= 11) {
        entry = (Entry_u2 *)(lbl_801A6D38 + (index - 9) * 0x1c + 0x894);
    }

    if (entry->unk_18 == value) {
        if (fn_8008023C(entry, arg, 0x18) == 0) {
            return;
        }
    }

    fn_80036AC4(index, arg, value);
    fn_800794F0(entry, arg, 0x18);
    entry->unk_18 = value;
}

/* --- dol/fn_80073B50.c --- */
typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    u8 unk_18;
    u8 unk_19;
    u8 _pad_1A[2];
    s32 unk_1C;
} Entry_u3;

extern void GXSetTevIndirect(s32, s32, s32, s32, s32, s32, s32, u8, u8, s32);

void fn_80073B50(u32 index, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, u8 arg7, u8 arg8, s32 arg9) {
    Entry_u3 *entry;

    entry = (Entry_u3 *)(lbl_801A6D38 + (index << 5) + 0x8E8);
    if (entry->unk_00 != arg1 ||
        entry->unk_04 != arg2 ||
        entry->unk_08 != arg3 ||
        entry->unk_0C != arg4 ||
        entry->unk_10 != arg5 ||
        entry->unk_14 != arg6 ||
        entry->unk_18 != arg7 ||
        entry->unk_19 != arg8 ||
        entry->unk_1C != arg9) {
        GXSetTevIndirect(index, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
        entry->unk_00 = arg1;
        entry->unk_04 = arg2;
        entry->unk_08 = arg3;
        entry->unk_0C = arg4;
        entry->unk_10 = arg5;
        entry->unk_14 = arg6;
        entry->unk_18 = arg7;
        entry->unk_19 = arg8;
        entry->unk_1C = arg9;
    }
}

/* --- dol/fn_80073C6C.c --- */
typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    u8 unk_18;
    u8 unk_19;
    u8 _pad_1A[2];
    s32 unk_1C;
} Entry_u4;


void fn_80073C6C(s32 index) {

{
    Entry_u4 *entry;
    entry = (Entry_u4 *)(lbl_801A6D38 + (index << 5) + 0x8E8);
    if (entry->unk_00 != 0 ||
        entry->unk_04 != 0 ||
        entry->unk_08 != 0 ||
        entry->unk_0C != 0 ||
        entry->unk_10 != 0 ||
        entry->unk_14 != 0 ||
        entry->unk_18 != 0 ||
        entry->unk_19 != 0 ||
        entry->unk_1C != 0) {
        GXSetTevIndirect(index, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        entry->unk_00 = 0;
        entry->unk_04 = 0;
        entry->unk_08 = 0;
        entry->unk_0C = 0;
        entry->unk_10 = 0;
        entry->unk_14 = 0;
        entry->unk_18 = 0;
        entry->unk_19 = 0;
        entry->unk_1C = 0;
}
    }
}
