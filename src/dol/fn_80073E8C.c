#include "types.h"
#include "dol/globals.h"

typedef struct Entry {
    u8 unk_00[0x18];
    s8 unk_18;
    u8 unk_19[3];
} Entry;

typedef struct TevEntry {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    u8 unk_18;
    u8 unk_19;
    u8 pad_1A[2];
    s32 unk_1C;
} TevEntry;

typedef struct Matrix {
    f32 a, b, c, d, e, f;
} Matrix;

extern int fn_8008023C(Entry *, void *, int);
extern void fn_80036AC4(int, void *, s8);
extern void fn_800794F0(Entry *, void *, int);
extern void GXSetTevIndirect(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern const f32 lbl_801A7474;
extern const f32 lbl_801A7470;

#pragma opt_common_subs off
void fn_80073E8C(s32 arg0, s32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    Entry *entry;
    u32 v1;
    Matrix matrix;
    TevEntry *tev;
    u32 v0;
    s32 wrap2;

    v0 = arg2 & 0xFFFF;
    switch (v0) {
    case 256: v1 = 1; break;
    case 128: v1 = 2; break;
    case 64: v1 = 3; break;
    case 32: v1 = 4; break;
    case 16: v1 = 5; break;
    default: v1 = 0; break;
    }
    switch ((arg3 & 0xFFFF)) {
    case 256: wrap2 = 1; break;
    case 128: wrap2 = 2; break;
    case 64: wrap2 = 3; break;
    case 32: wrap2 = 4; break;
    case 16: wrap2 = 5; break;
    default: wrap2 = 0; break;
    }
    matrix.a = (arg4 & 0xFFFF) * lbl_801A7470;
    matrix.b = lbl_801A7474;
    matrix.c = lbl_801A7474;
    matrix.d = lbl_801A7474;
    matrix.e = (arg5 & 0xFFFF) * lbl_801A7470;
    matrix.f = lbl_801A7474;
    if (arg7 != 0) {
        if (arg7 <= 3) {
            entry = (Entry *)(lbl_801A6D38 + (arg7 - 1) * 0x1C + 0x894);
        } else if (arg7 <= 7) {
            entry = (Entry *)(lbl_801A6D38 + (arg7 - 5) * 0x1C + 0x894);
        } else if (arg7 <= 11) {
            entry = (Entry *)(lbl_801A6D38 + (arg7 - 9) * 0x1C + 0x894);
        }
        if (entry->unk_18 != 10 || fn_8008023C(entry, &matrix, 0x18) != 0) {
            fn_80036AC4(arg7, &matrix, 10);
            fn_800794F0(entry, &matrix, 0x18);
            entry->unk_18 = 10;
        }
    }
    tev = (TevEntry *)(lbl_801A6D38 + (arg0 << 5) + 0x8E8);
    if (tev->unk_00 != arg1 ||
        tev->unk_04 != arg6 ||
        tev->unk_08 != arg8 ||
        tev->unk_0C != arg7 ||
        tev->unk_10 != (s32)v1 ||
        tev->unk_14 != wrap2 ||
        tev->unk_18 != 0 ||
        tev->unk_19 != 1 ||
        tev->unk_1C != arg9) {
        GXSetTevIndirect(arg0, arg1, arg6, arg8, arg7, v1, wrap2, 0, 1, arg9);
        tev->unk_00 = arg1;
        tev->unk_04 = arg6;
        tev->unk_08 = arg8;
        tev->unk_0C = arg7;
        tev->unk_10 = v1;
        tev->unk_14 = wrap2;
        tev->unk_18 = 0;
        tev->unk_19 = 1;
        tev->unk_1C = arg9;
    }
}
#pragma opt_common_subs reset

