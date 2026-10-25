#include "types.h"
#include "dol/globals.h"

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
