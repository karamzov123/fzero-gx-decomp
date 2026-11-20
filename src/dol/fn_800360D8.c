#include "types.h"


/* --- dol/fn_800360D8.c --- */
struct fn_800360D8_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

u32 fn_800360D8(struct fn_800360D8_Arg0 *arg0) {
    return ((arg0->unk_C & 0x1FFFFF) << 5);
}

/* --- dol/GXGetTexObjWidth.c --- */
struct GXGetTexObjWidth_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

u32 GXGetTexObjWidth(struct GXGetTexObjWidth_Arg0 *arg0) {
    return ((arg0->unk_8 & 0x3FF) + 1);
}

/* --- dol/GXGetTexObjHeight.c --- */
struct GXGetTexObjHeight_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

u32 GXGetTexObjHeight(struct GXGetTexObjHeight_Arg0 *arg0) {
    return (((arg0->unk_8 >> 10) & 0x3FF) + 1);
}

/* --- dol/fn_80036104.c --- */
struct fn_80036104_Arg0 {
    u8 pad_0[0x14];
    u32 unk_14;
};

u32 fn_80036104(struct fn_80036104_Arg0 *arg0) {
    return arg0->unk_14;
}
