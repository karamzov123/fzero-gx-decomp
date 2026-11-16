#include "types.h"
struct Sig_fn_8008A1CC_TRKBuffer {
    u32 mutex;
    u32 isInUse;
    u32 length;
    u32 position;
    u8 data[(0x800 + 0x80)];
};
struct Sig_fn_8008A1CC_Response {
    u32 length;
    u8 flag;
    u8 pad_5[3];
    u8 status;
    u8 pad_9[0x40 - 9];
};
struct Sig_fn_80089144_fn_80089144_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u32 unk_C;
};
typedef int Sig_TRKReadBuffer_DSError;
typedef struct Sig_TRKReadBuffer_TRKBuffer {
    u32 mutex;
    BOOL isInUse;
    u32 length;
    u32 position;
    u8 data[(0x800 + 0x80)];
} Sig_TRKReadBuffer_TRKBuffer;
struct Sig_fn_80089174_fn_80089174_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u32 unk_C;
};
typedef int Sig_TRKAppendBuffer_DSError;
typedef struct Sig_TRKAppendBuffer_TRKBuffer {
    u32 mutex;
    BOOL isInUse;
    u32 length;
    u32 position;
    u8 data[(0x800 + 0x80)];
} Sig_TRKAppendBuffer_TRKBuffer;
struct Sig_fn_80088B00_fn_80088B00_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

extern Sig_TRKAppendBuffer_DSError TRKAppendBuffer(Sig_TRKAppendBuffer_TRKBuffer *, const void *, size_t);
extern Sig_TRKReadBuffer_DSError TRKReadBuffer(Sig_TRKReadBuffer_TRKBuffer *, void *, size_t);
extern s32 fn_80088B00(struct Sig_fn_80088B00_fn_80088B00_Arg0 *);
extern s32 fn_80089144(struct Sig_fn_80089144_fn_80089144_Arg0 *, u32);
extern s32 fn_8008C730(u32, u32, u32 *, u32, s32);
extern s32 fn_8008D398(u32, u32);
extern u32 fn_80089174(struct struct_fn_80089174_fn_80089174_Arg0 *, u32);
extern u8 lbl_80095890[52];
extern void * memset(void *, int, u32);
extern void MWTRACE(u32, ...);

static inline u8 * fn_8008A1CC_read_pointer(struct Sig_fn_8008A1CC_TRKBuffer * owner) { return owner->data; }
#pragma opt_lifetimes off
s32 fn_8008A1CC(struct Sig_fn_8008A1CC_TRKBuffer *arg0) {
    u8 *p_lbl_80095890 = lbl_80095890;
    s32 err_2;
    s32 err;
    u8 v2;
    u16 v1;
    u32 v0;
    u32 out;
    u32 buf[512];
    struct Sig_fn_8008A1CC_Response respB;
    struct Sig_fn_8008A1CC_Response respA;
    struct Sig_fn_8008A1CC_Response respC;

    v0 = *(u32 *)((u8 *)arg0 + 32);
    v1 = *(u16 *)((u8 *)arg0 + 28);
    v2 = fn_8008A1CC_read_pointer(arg0)[8];
    MWTRACE(1, (u32)((u8 *)(u32)p_lbl_80095890) + 384, fn_8008A1CC_read_pointer(arg0)[4], v0, v1, v2);
    if (v2 & 2) {
        memset(&respA, 0, 0x40);
        respA.flag = 0x80;
        respA.length = 0x40;
        respA.status = 0x12;
        fn_8008D398((u32)&respA, 0x40);
        return 0;
    }
    out = v1;
    fn_80089144((struct Sig_fn_80089144_fn_80089144_Arg0 *)arg0, 0x40);
    TRKReadBuffer((Sig_TRKReadBuffer_TRKBuffer *)arg0, (void *)&buf, out);
    err = fn_8008C730((u32)&buf, v0, &out, (((u32)v2 >> 3) & 1) ^ 1, 0);
    fn_80089174((struct struct_fn_80089174_fn_80089174_Arg0 *)arg0, 0);
    if (err == 0) {
        memset(&respB, 0, 0x40);
        respB.length = 0x40;
        respB.flag = 0x80;
        respB.status = (u8)err;
        err = TRKAppendBuffer((Sig_TRKAppendBuffer_TRKBuffer *)arg0, (const void *)&respB, 0x40);
    }
    if (err != 0) {
        switch (err) {
        case 0x702: err = 0x15; break;
        case 0x700: err = 0x13; break;
        case 0x704: err = 0x21; break;
        case 0x705: err = 0x22; break;
        case 0x706: err = 0x20; break;
        default: err = 3; break;
        }
        memset(&respC, 0, 0x40);
        respC.flag = 0x80;
        respC.length = 0x40;
        respC.status = (u8)err;
        fn_8008D398((u32)&respC, 0x40);
        return 0;
    }
    MWTRACE(1, (u32)((u8 *)(u32)p_lbl_80095890) + 0x60);
    err_2 = fn_80088B00((struct Sig_fn_80088B00_fn_80088B00_Arg0 *)arg0);
    MWTRACE(1, (u32)((u8 *)(u32)p_lbl_80095890) + 0x80, err_2);
    return err_2;
}
#pragma opt_lifetimes reset

struct fn_8008A3C0_Arg0 {
    u8 pad_0[0x14];
    u8 unk_14;
    u8 pad_15[3];
    u8 unk_18;
    u8 pad_19[3];
    u16 unk_1c;
    u32 unk_20;
};

struct fn_8008A3C0_Buf {
    u32 unk_0;
    u8 unk_4;
    u8 pad_5[3];
    u8 unk_8;
    u8 pad_9[0x37];
};

struct fn_8008A3C0_Msg {
    u8 a[2052];
};

struct fn_8008A3C0_Rodata {
    u8 pad_0[0x1e0];
};
extern struct fn_8008A3C0_Rodata lbl_80095890_ro;

#pragma opt_common_subs off
s32 fn_8008A3C0(struct fn_8008A3C0_Arg0 *arg0) {
    u8 *base;
    s32 v4 = 0;
    s32 code;
    u8 v2;
    u16 v1;
    u32 v0;
    struct fn_8008A3C0_Msg bufD;
    struct fn_8008A3C0_Buf bufB;
    struct fn_8008A3C0_Buf bufA;
    struct fn_8008A3C0_Buf bufC;
    u32 loc_8;

    base = lbl_80095890;
    v0 = arg0->unk_20;
    v1 = arg0->unk_1c;
    v2 = arg0->unk_18;
    MWTRACE(1, (u32)(base + 0x1b0), arg0->unk_14, v0, v1, v2);

    if ((v2 & 0x2) != 0) {        memset(&bufA, 0, 0x40);
        bufA.unk_4 = 0x80;
        bufA.unk_0 = 0x40;
        bufA.unk_8 = 0x12;
        fn_8008D398((u32)&bufA, 0x40);
        return 0;
    }

    loc_8 = v1;
    v4 = fn_8008C730((u32)&bufD, v0, &loc_8, ((((u32)v2) >> 3) & 1) ^ 1, 1);
    fn_80089174((struct struct_fn_80089174_fn_80089174_Arg0 *)arg0, 0);

    if (v4 == 0) {
        memset(&bufB, 0, 0x40);
        bufB.unk_8 = v4;
        bufB.unk_0 = loc_8 + 0x40;
        bufB.unk_4 = 0x80;
        TRKAppendBuffer((Sig_TRKAppendBuffer_TRKBuffer *)arg0, &bufB, 0x40);
        v4 = TRKAppendBuffer((Sig_TRKAppendBuffer_TRKBuffer *)arg0, &bufD, loc_8);
    }

    if (v4 != 0) {
        switch (v4 - 0x700) {
        case 2:
            code = 0x15;
            break;
        case 0:
            code = 0x13;
            break;
        case 4:
            code = 0x21;
            break;
        case 5:
            code = 0x22;
            break;
        case 6:
            code = 0x20;
            break;
        default:
            code = 3;
            break;
        }
        memset(&bufC, 0, 0x40);
        bufC.unk_4 = 0x80;
        bufC.unk_0 = 0x40;
        bufC.unk_8 = code;
        fn_8008D398((u32)&bufC, 0x40);
        return 0;
    }

    MWTRACE(1, (u32)(base + 0x60));
    v4 = fn_80088B00((struct Sig_fn_80088B00_fn_80088B00_Arg0 *)arg0);
    MWTRACE(1, (u32)(base + 0x80), v4);
    return v4;
}
#pragma opt_common_subs reset

