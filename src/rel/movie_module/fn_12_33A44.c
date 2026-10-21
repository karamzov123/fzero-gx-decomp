#include "types.h"

struct Sig_fn_12_2DF28_fn_12_2DF28_Arg1 {
    u32 unk_0;
};

typedef struct SfdBuf {
    u8 *data;
    s32 size;
} SfdBuf;

typedef struct SfdHdr {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
    SfdBuf *unk_38;
} SfdHdr;

typedef struct SfdInfo {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3C;
    u8 *unk_40;
    s32 unk_44;
} SfdInfo;

typedef struct SfdObj {
    u8 pad_0[0x40];
    u32 unk_40;
    u8 pad_44[0xBC - 0x44];
    u8 unk_BC[0xD4 - 0xBC];
    void *unk_D4;
} SfdObj;

extern char lbl_12_rodata_1208[37];
extern u8 lbl_12_rodata_1230[80];
extern void MWSFSVM_Error(const char *, ...);
extern s32 fn_12_2DF28(u32, struct Sig_fn_12_2DF28_fn_12_2DF28_Arg1 *);
extern u32 fn_12_38AE0(void);

void fn_12_33A44(SfdObj *obj, SfdHdr *hdr, SfdInfo *info) {
    u32 handle;
    s32 v20;
    struct { s32 value; } kind;
    s32 v0;
    s32 v4;
    s32 v8;
    s32 vC;
    struct { s32 value; } type;
    s32 v34;
    struct { s32 value; } v24;
    struct { s32 value; } v28;
    s32 v18;
    s32 v30;
    void *cur;
    struct Sig_fn_12_2DF28_fn_12_2DF28_Arg1 rate;
    s32 r;
    s32 v2C;
    s32 size;
    u8 *data;
    void *base;
    struct { s32 value; } time;

    handle = obj->unk_40;
    v20 = hdr->unk_20;
    switch (hdr->unk_1C) {
    case 1:
        kind.value = 1;
        break;
    case 2:
        kind.value = 2;
        break;
    case 3:
        kind.value = 3;
        break;
    default:
        kind.value = 3;
        break;
    }
    v0 = hdr->unk_00;
    v4 = hdr->unk_04;
    v8 = hdr->unk_08;
    vC = hdr->unk_0C;
    switch (hdr->unk_10) {
    case 1:
        type.value = 1;
        break;
    case 2:
        type.value = 2;
        break;
    case 3:
        type.value = 3;
        break;
    case 4:
        type.value = 4;
        break;
    default:
        MWSFSVM_Error(lbl_12_rodata_1208);
        type.value = 1;
        break;
    }
    v24.value = hdr->unk_24;
    v34 = hdr->unk_34;
    v18 = hdr->unk_18;
    v30 = hdr->unk_30;
    v2C = hdr->unk_2C;
    v28.value = hdr->unk_28;
    if (fn_12_2DF28(handle, &rate) != 0) {
        MWSFSVM_Error((const char *)lbl_12_rodata_1230);
    }
    r = rate.unk_0;
    {
        extern s64 __div2i(s64, s64);
        time.value = (s32)__div2i((s64)v34 * r, (s64)v18 * 1000);
    }
    info->unk_00 = v20;
    info->unk_04 = kind.value;
    info->unk_08 = v0;
    info->unk_0C = v4;
    info->unk_10 = v8;
    info->unk_14 = vC;
    info->unk_18 = type.value;
    info->unk_1C = rate.unk_0;
    info->unk_20 = time.value;
    info->unk_24 = v34;
    info->unk_28 = v18;
    info->unk_2C = v2C;
    info->unk_30 = (s32)(((s64)r * (s64)v30) / ((s64)v18 * 1000));
    info->unk_34 = v30;
    info->unk_38 = v24.value;
    info->unk_3C = v28.value;

    base = obj->unk_BC;
    cur = obj->unk_D4;
    data = hdr->unk_38->data;
    size = hdr->unk_38->size;
    if ((s32)fn_12_38AE0() != 1) {
        info->unk_40 = 0;
        info->unk_44 = 0;
    } else if (cur == base) {
        info->unk_40 = 0;
        info->unk_44 = 0;
    } else {
        if (data != 0 && size > 4) {
            data += 4;
            size -= 4;
        }
        info->unk_40 = data;
        info->unk_44 = size;
    }
}
