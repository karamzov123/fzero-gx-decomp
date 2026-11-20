#include "types.h"
#include "dol/globals.h"
#pragma opt_common_subs off

/* --- dol/fn_800789D8.c --- */
typedef u32 (*fn_800789D8_Fn0)(void *);
struct fn_800789D8_Arg0 { u8 pad_0[4]; u32 unk_4; };
struct fn_800789D8_Arg1 { u32 unk_0; };

extern u32 fn_80075908(u32, u32);
extern u32 fn_80078344(u32, u32);
extern u32 lbl_801A6D90;
extern u32 lbl_801A6D94;
extern u32 lbl_801A6D98;
extern void fn_8003458C(void);
extern void fn_8007245C(u32);
extern void fn_80078BC4(u8 *);
extern void fn_80078D60(s32);

u32 fn_800789D8(struct fn_800789D8_Arg0 *arg0, struct fn_800789D8_Arg1 *entry, u32 arg2) {
    u32 v0;
    u32 v1;
    u32 v2;
    u8 v3;
    u32 v9;
    s32 v10;
    s32 v5;
    s32 v4;
    u32 v6;
    u32 v7;
    struct fn_800789D8_Arg1 *arg1 = entry;
    u32 v8;
    u8 v11;
    u32 v13;
    u32 v12;
    struct { u32 a[16]; } loc_8;
    v8 = arg2;
    arg2 = lbl_801A6D98 ^ 2;
    entry = (struct fn_800789D8_Arg1 *)entry->unk_0;
    v0 = (u32)entry;
    v1 = arg2;
    if (v0 & 2) v1 = 0;
    v4 = v1;
    if (arg0->unk_4 & 4) fn_80078BC4((u8 *)arg1 + 32);
    fn_8007245C(*(u32 *)((u8 *)arg1 + 28));
    v7 = (u32)arg1 + 96;
    if (lbl_801A6D90 != 0) {
        loc_8.a[1] = (u32)arg1;
        loc_8.a[2] = v8;
        v3 = ((fn_800789D8_Fn0)lbl_801A6D90)(&loc_8);
    } else {
        if ((s32)lbl_801A6D94 == 0) fn_80075908((u32)arg1, v8);
        v3 = 1;
    }
    if (v3) {
        fn_8003458C();
        for (v5 = 0; v5 < 2; v5++) {
            if (*(u8 *)((u8 *)arg1 + 19) & (1 << v5)) {
                fn_80078D60(v4);
                fn_80078344(v7, *(u32 *)((u8 *)arg1 + 40 + v5 * 4));
                v7 += *(u32 *)((u8 *)arg1 + 40 + v5 * 4);
            }
            if (v4 != 0) v4 = lbl_801A6D98 ^ 1;
        }
        if (*(u8 *)((u8 *)arg1 + 19) & 12) {
            fn_80078BC4((u8 *)v7);
            v9 = v7;
            v7 += 32;
            for (v10 = 0; v10 < 2; v10++) {
                if (v10 == 0) fn_80078D60(lbl_801A6D98 ^ 2);
                else fn_80078D60(lbl_801A6D98 ^ 1);
                fn_80078344(v7, *(u32 *)(v9 + 8));
                v7 += *(u32 *)(v9 + 8);
                v9 += 4;
            }
        }
    } else {
        v2 = (u32)arg1 + 96;
        for (v5 = 0; v5 < 2; v5++) {
            if (*(u8 *)((u8 *)arg1 + 19) & (1 << v5))
                v2 += *(u32 *)((u8 *)arg1 + 40 + v5 * 4);
        }
        if (*(u8 *)((u8 *)arg1 + 19) & 12) {
            v12 = *(u32 *)(v2 + 8);
            v13 = *(u32 *)(v2 + 12);
            v2 += 32;
            v2 += v12;
            v2 += v13;
        }
        return v2;
    }
    return v7;
}

/* --- dol/fn_80078BC4.c --- */
/* --- dol/fn_80078BC4.c --- */
extern u32 lbl_801A6DA8;
extern void u_gxutil_upload_some_mtx(u32, s32);

void fn_80078BC4(u8 *arg0) {
    u8 *ptr;
    s32 i;

    ptr = arg0;
    i = 0;
    do {
        if ((s32)*ptr != 0xFF) {
            u_gxutil_upload_some_mtx(lbl_801A6DA8 + *ptr * 48, i + 1);
        }
        i++;
        ptr++;
    } while (i < 8);
}

/* --- dol/fn_80078C28.c --- */
typedef struct {
    u8 pad_00[0x1e];
    u8 count;
    u8 pad_1f[0x9];
    u8 entries[8];
} Fn80078C28Arg0;

extern u32 lbl_801A6D00;
extern u32 lbl_801A6DA4;
extern void lbl_8006DFFC(u32, u32, u32);

static inline void fn_80078C28_upload(Fn80078C28Arg0 *arg0) {
    s32 i;

    i = 0;
    do {
        if ((s32)arg0->entries[i] != 0xFF) {
            u_gxutil_upload_some_mtx(lbl_801A6DA8 + arg0->entries[i] * 0x30, i + 1);
        }
        i++;
    } while (i < 8);
}

void fn_80078C28(Fn80078C28Arg0 *arg0) {
    u32 index;

    index = 0;
    while (index < arg0->count) {
        lbl_8006DFFC(lbl_801A6D00,
                     *(u32 *)((u8 *)(u32)lbl_801A6DA4 + index * 4),
                     lbl_801A6DA8 + index * 0x30);
        index++;
    }

    fn_80078C28_upload(arg0);
}

/* --- dol/fn_80078CDC.c --- */
extern void GXSetCurrentMtx(s32);
extern u32 lbl_801A6D9C;
extern f32 lbl_8019F130[7];
extern f32 lbl_801A74A8;
extern void fn_8007264C(s32, s32, s32, s32, s32);

typedef struct {
    u8 pad_00[0x18];
    u32 unk_18;
} Fn80078CDCData;

void fn_80078CDC(s32 arg0) {
    s32 value;
    Fn80078CDCData *data;

    if (arg0 != 0) {
        GXSetCurrentMtx(0);
    }

    value = lbl_801A6D9C;
    lbl_8019F130[3] = lbl_801A74A8;
    if (value != 0) {
        value ^= 3;
    }
    data = (Fn80078CDCData *)lbl_801A6D38;
    data->unk_18 = value;
    fn_8007264C(0, 10, 0, 4, 0);
}
