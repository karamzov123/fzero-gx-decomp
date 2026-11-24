#include "types.h"


/* --- dol/fn_80051958.c --- */
struct fn_80051958_lbl_80187110 {
    u32 unk_0;
};

extern struct fn_80051958_lbl_80187110 lbl_80187110[];
extern u32 fn_80053BFC(void);
extern u32 lbl_80187330[];
extern u32 memset(u32, u32, u32);

u32 fn_80051958(u32 arg0, u32 arg1) {
    u32 v0;
    u32 v1;
    u32 t0, t1;
    v0 = arg0;
    v1 = arg1;
    if ((s32)lbl_80187110[0].unk_0 == 0) {
    t0 = fn_80053BFC();
    v0 = t0;
    v1 = 0;
    v0 = (u32)&lbl_80187330;
    t1 = memset(v0, v1, 64);
    v0 = t1;
    }
    v1 = (u32)&lbl_80187110;
    v0 = *(u32 *)(v1);
    *(u32 *)((u8 *)v1 + 0) = (v0 + 1);
    return v0;
}

/* --- dol/fn_800519B0.c --- */
#define RD_U16(p) ((u16)(((u32)(p)[0] << 8) | (p)[1]))
#define RD_U32(p) (((u32)(p)[0] << 24) | ((u32)(p)[1] << 16) | ((u32)(p)[2] << 8) | (u32)(p)[3])

typedef struct Fn800519B0Arg3 {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u32 field_4;
    u32 field_8;
    s16 field_C;
    s16 field_E;
    u8 pad_10[0x2C];
    u8 field_3C;
    u8 field_3D;
} Fn800519B0Arg3;

s32 fn_800519B0(u8 *arg0, u32 arg1, u32 *arg2, Fn800519B0Arg3 *arg3) {
    u32 value;
    s32 size;
    u8 *src;
    u8 *dst;
    s32 i;

    if (arg2 != 0) {
        *arg2 = 0;
    }
    if ((s32)arg1 < 4) {
        return -1;
    }
    value = RD_U16(arg0);
    if (value != 0x8000) {
        return -4;
    }
    size = (arg0[2] << 8) | arg0[3];
    if (arg2 != 0) {
        *arg2 = size;
    }
    if (arg3 == 0) {
        return 0;
    }
    if ((s32)arg1 < size + 4) {
        return -2;
    }
    size -= 6;
    if (size < 16) {
        return -2;
    }
    arg3->field_0 = arg0[4];
    size -= 16;
    arg3->field_1 = arg0[5];
    arg3->field_2 = arg0[6];
    arg3->field_3 = arg0[7];
    arg3->field_4 = RD_U32(arg0 + 8);
    arg3->field_8 = RD_U32(arg0 + 12);
    arg3->field_C = RD_U16(arg0 + 16);
    arg3->field_3C = arg0[18];
    arg3->field_3D = arg0[19];
    if (size < 4) {
        return -2;
    }
    arg3->field_E = RD_U16(arg0 + 22);
    src = arg0 + 0x18;
    if (size < arg3->field_E * 20) {
        return -3;
    }
    dst = (u8 *)arg3;
    for (i = 0; i < arg3->field_E; i++) {
        *(u16 *)(dst + 0x10) = RD_U16(src + 0);
        *(u16 *)(dst + 0x12) = RD_U16(src + 2);
        *(u32 *)(dst + 0x14) = RD_U32(src + 4);
        *(u32 *)(dst + 0x18) = RD_U32(src + 8);
        *(u32 *)(dst + 0x1C) = RD_U32(src + 12);
        *(u32 *)(dst + 0x20) = RD_U32(src + 16);
        dst += 0x14;
    }
    size -= arg3->field_E * 20;
    i = 0;
    dst = (u8 *)arg3;
    while (i < (s8)arg3->field_3) {
        if (size < 12) {
            return 0;
        }
        *(u16 *)(dst + 0x24) = RD_U16(src);
        if (*(s16 *)(dst + 0x24) > 0) {
            *(u16 *)(dst + 0x26) = RD_U16(src + 2);
        }
        dst[0x28] = src[4];
        if ((s8)dst[0x28] > 0) {
            dst[0x29] = src[5];
        }
        dst[0x2A] = src[6];
        if ((s8)dst[0x2A] > 0) {
            dst[0x2B] = src[7];
        }
        dst[0x2C] = src[8];
        if ((s8)dst[0x2C] > 0) {
            dst[0x2D] = src[9];
        }
        dst[0x2E] = src[10];
        if ((s8)dst[0x2E] > 0) {
            dst[0x2F] = src[11];
        }
        src += 12;
        size -= 12;
        dst += 12;
        i++;
    }
    return 0;
}
