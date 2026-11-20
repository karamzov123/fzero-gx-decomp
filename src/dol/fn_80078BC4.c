#include "types.h"
#include "dol/globals.h"


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
