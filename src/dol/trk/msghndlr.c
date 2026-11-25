#include "types.h"

typedef int DSError;

typedef struct TRKBuffer {
    u32 mutex;
    BOOL isInUse;
    u32 length;
    u32 position;
    u8 data[0x880];
} TRKBuffer;

typedef struct TRKReplyBuffer {
    u32 length;
    u8 flag;
    u8 pad_5[3];
    u8 status;
    u8 pad_9[0x37];
} TRKReplyBuffer;

extern s32 fn_8008B484(void);
extern void *memset(void *, int, u32);
extern s32 fn_8008D398(u32, u32);
extern s32 fn_80089144(TRKBuffer *, u32);
extern u32 fn_80089174(TRKBuffer *, u32);
extern s32 fn_80088B00(TRKBuffer *);
extern s32 TRKTargetStopped(void);
extern s32 TRKTargetContinue(void);
extern u32 fn_8008B6BC(void);
extern s32 fn_8008B784(u32, u32);
extern s32 fn_8008B6CC(u32, u32, u32);
extern DSError TRKTargetAccessDefault(u32, u32, TRKBuffer *, size_t *, BOOL);
extern DSError fn_8008BFB4(u32, u32, TRKBuffer *, size_t *, BOOL);
extern u32 fn_8008C124(u32, u32, u32, void *, u32);
extern u32 fn_8008BB7C(u32, u32, u32, void *, u32);
extern DSError TRKAppendBuffer(TRKBuffer *, const void *, size_t);
extern DSError TRKAppendBuffer_ui8(TRKBuffer *, const u8 *, int);
extern DSError TRKReadBuffer(TRKBuffer *, void *, size_t);
extern s32 fn_8008C730(u32, u32, u32 *, u32, s32);
extern void MWTRACE(u32, ...);
extern s32 fn_8008963C(const char *message);
extern void fn_8008D7C0(u32 serialIO);

extern u8 lbl_80095890[];
extern u8 lbl_800958C4[44];
extern u32 lbl_800958F0[];
extern u32 lbl_80095910[];

DSError fn_8008983C(TRKBuffer *message) {
    TRKReplyBuffer reply;
    u8 enable = message->data[0x0C];

    if (message->data[0x08] == 1) {
        fn_8008963C("\nMetroTRK Option : SerialIO - ");
        if (enable) {
            fn_8008963C("Enable\n");
        } else {
            fn_8008963C("Disable\n");
        }
        fn_8008D7C0(enable);
    }
    memset(&reply, 0, sizeof(reply));
    reply.flag = 0x80;
    reply.length = sizeof(reply);
    reply.status = 0;
    fn_8008D398((u32)&reply, sizeof(reply));
    return 0;
}

s32 fn_800898E4(void) {
    TRKReplyBuffer buffer;
    s32 type;

    type = fn_8008B484();
    switch (type) {
    case 0:
        type = 0;
        break;
    case 0x704:
        type = 0x21;
        break;
    case 0x705:
        type = 0x22;
        break;
    case 0x706:
        type = 0x20;
        break;
    default:
        type = 1;
        break;
    }

    memset(&buffer, 0, 0x40);
    buffer.flag = 0x80;
    buffer.length = 0x40;
    buffer.status = type;
    fn_8008D398((u32)&buffer, 0x40);
    return 0;
}

s32 fn_8008998C(TRKBuffer *arg0) {
    u8 v0;
    u8 v4;
    u32 v5;
    u32 v1;
    u32 v2;
    struct { u8 a[64]; } loc_108;
    struct { u8 a[64]; } loc_C8;
    struct { u8 a[64]; } loc_88;
    struct { u8 a[64]; } loc_48;
    struct { u8 a[64]; } loc_8;
    fn_80089144(arg0, 0);
    v0 = arg0->data[8];
    v1 = *(u32 *)((u8 *)arg0 + 32);
    v2 = *(u32 *)((u8 *)arg0 + 36);
    switch (v0) {
    case 0:
    case 16:
        v4 = arg0->data[12];
        if (v4 < 1) {
            memset(&loc_108, 0, 64);
            loc_108.a[4] = 128;
            *(u32 *)&loc_108 = 64;
            loc_108.a[8] = 17;
            fn_8008D398((u32)&loc_108, 64);
            return 0;
        }
        break;
    case 1:
    case 17:
        v5 = fn_8008B6BC();
        if (v5 < v1 || v5 > v2) {
            memset(&loc_C8, 0, 64);
            loc_C8.a[4] = 128;
            *(u32 *)&loc_C8 = 64;
            loc_C8.a[8] = 17;
            fn_8008D398((u32)&loc_C8, 64);
            return 0;
        }
        break;
    default:
        memset(&loc_88, 0, 64);
        loc_88.a[4] = 128;
        *(u32 *)&loc_88 = 64;
        loc_88.a[8] = 18;
        fn_8008D398((u32)&loc_88, 64);
        return 0;
    }
    if (!TRKTargetStopped()) {
        memset(&loc_48, 0, 64);
        loc_48.a[4] = 128;
        *(u32 *)&loc_48 = 64;
        loc_48.a[8] = 22;
        fn_8008D398((u32)&loc_48, 64);
        return 0;
    }
    memset(&loc_8, 0, 64);
    loc_8.a[4] = 128;
    *(u32 *)&loc_8 = 64;
    loc_8.a[8] = 0;
    fn_8008D398((u32)&loc_8, 64);
    v5 = 0;
    switch (v0) {
    case 0:
    case 16:
        v5 = fn_8008B784(v4, v0 == 16);
        break;
    case 1:
    case 17:
        v5 = fn_8008B6CC(v1, v2, v0 == 17);
        break;
    }
    return v5;
}

s32 fn_80089BAC(void) {
    TRKReplyBuffer buffer0;
    TRKReplyBuffer buffer1;

    MWTRACE(1, (u32)&lbl_800958C4);
    if (!TRKTargetStopped()) {
        memset(&buffer0, 0, 0x40);
        buffer0.flag = 0x80;
        buffer0.length = 0x40;
        buffer0.status = 0x16;
        fn_8008D398((u32)&buffer0, 0x40);
        return 0;
    }

    memset(&buffer1, 0, 0x40);
    buffer1.flag = 0x80;
    buffer1.length = 0x40;
    buffer1.status = 0;
    fn_8008D398((u32)&buffer1, 0x40);
    return TRKTargetContinue();
}

s32 fn_80089C5C(TRKBuffer *arg0) {
    TRKBuffer *self;
    TRKReplyBuffer buf1;
    TRKReplyBuffer buf0;
    TRKReplyBuffer buf2;
    size_t size;
    s32 result;
    u16 f1C;
    u16 f20;

    self = arg0;
    result = self->data[8];
    f1C = *(u16 *)((u8 *)self + 0x1C);
    f20 = *(u16 *)((u8 *)self + 0x20);

    fn_80089144(self, 0);

    if (f1C > f20) {
        memset(&buf0, 0, 0x40);
        buf0.flag = 0x80;
        buf0.length = 0x40;
        buf0.status = 0x14;
        fn_8008D398((u32)&buf0, 0x40);
        return 0;
    }

    fn_80089144(self, 0x40);

    switch (result) {
    case 0:
        result = TRKTargetAccessDefault(f1C, f20, self, &size, 0);
        break;
    case 1:
        result = fn_8008C124(f1C, f20, (u32)self, &size, 0);
        break;
    case 2:
        result = fn_8008BFB4(f1C, f20, self, &size, 0);
        break;
    case 3:
        result = fn_8008BB7C(f1C, f20, (u32)self, &size, 0);
        break;
    default:
        result = 0x703;
        break;
    }

    fn_80089174(self, 0);

    if (result == 0) {
        memset(&buf1, 0, 0x40);
        buf1.length = 0x40;
        buf1.flag = 0x80;
        buf1.status = result;
        result = TRKAppendBuffer(self, &buf1, 0x40);
    }

    if (result != 0) {
        switch (result) {
        case 0x703:
            result = 0x12;
            break;
        case 0x701:
            result = 0x14;
            break;
        case 0x302:
            result = 2;
            break;
        case 0x702:
            result = 0x15;
            break;
        case 0x704:
            result = 0x21;
            break;
        case 0x705:
            result = 0x22;
            break;
        case 0x706:
            result = 0x20;
            break;
        default:
            result = 3;
            break;
        }

        memset(&buf2, 0, 0x40);
        buf2.flag = 0x80;
        buf2.length = 0x40;
        buf2.status = result;
        fn_8008D398((u32)&buf2, 0x40);
        return 0;
    }

    MWTRACE(1, (u32)&lbl_800958F0);
    result = fn_80088B00(self);
    MWTRACE(1, (u32)&lbl_80095910, result);
    return result;
}

#pragma opt_lifetimes off
s32 fn_80089EEC(TRKBuffer *arg0) {
    u8 *p_lbl_80095890 = (u8 *)&lbl_80095890;
    s32 v10;
    struct { s32 value; } v12;
    TRKReplyBuffer loc_8C;
    TRKReplyBuffer loc_4C;
    TRKReplyBuffer loc_C;
    u32 loc_8;
    void *lab_t0;
    if (*(u16 *)((u8 *)arg0 + 28) > *(u16 *)((u8 *)arg0 + 32)) {
        memset(&loc_4C, 0, 64);
        loc_4C.flag = 128;
        loc_4C.length = 64;
        loc_4C.status = 20;
        fn_8008D398((u32)&loc_4C, 64);
        return 0;
    }
    loc_8C.flag = 128;
    *(u32 *)&loc_8C = 1128;
    fn_80089174(arg0, 0);
    MWTRACE(4, (p_lbl_80095890 + 152), arg0->length);
    TRKAppendBuffer_ui8(arg0, (const u8 *)&loc_8C, 64);
    MWTRACE(4, (p_lbl_80095890 + 152), arg0->length);
    v10 = TRKTargetAccessDefault(0, 36, arg0, (size_t *)&loc_8, 1);
    MWTRACE(4, (p_lbl_80095890 + 192), v10);
    MWTRACE(4, (p_lbl_80095890 + 152), arg0->length);
    if (!v10) v10 = fn_8008C124(0, 33, (u32)arg0, &loc_8, 1);
    MWTRACE(4, (p_lbl_80095890 + 248), v10);
    MWTRACE(4, (p_lbl_80095890 + 152), arg0->length);
    if (!v10) v10 = fn_8008BFB4(0, 96, arg0, (size_t *)&loc_8, 1);
    MWTRACE(4, (p_lbl_80095890 + 288), v10);
    MWTRACE(4, (p_lbl_80095890 + 152), arg0->length);
    if (!v10) v10 = fn_8008BB7C(0, 31, (u32)arg0, &loc_8, 1);
    MWTRACE(4, (p_lbl_80095890 + 336), v10);
    MWTRACE(4, (p_lbl_80095890 + 152), arg0->length);
    if (v10) {
        switch (v10) {
        case 1795: v10 = 18; break;
        case 1793: v10 = 20; break;
        case 1794: v10 = 21; break;
        case 1796: v10 = 33; break;
        case 1797: v10 = 34; break;
        case 1798: v10 = 32; break;
        default: v10 = 3; break;
        }
        lab_t0 = &loc_C;
        memset(lab_t0, 0, 64);
        loc_C.flag = 128;
        loc_C.length = 64;
        loc_C.status = v10;
        fn_8008D398((u32)&loc_C, 64);
        return 0;
    }
    MWTRACE(1, (p_lbl_80095890 + 96));
    v12.value = fn_80088B00(arg0);
    MWTRACE(1, (p_lbl_80095890 + 128), v12.value);
    return v12.value;
}

s32 fn_8008A1CC(TRKBuffer *arg0) {
    u8 *p_lbl_80095890 = lbl_80095890;
    s32 err_2;
    s32 err;
    u8 v2;
    u16 v1;
    u32 v0;
    u32 out;
    u32 buf[512];
    TRKReplyBuffer respB;
    TRKReplyBuffer respA;
    TRKReplyBuffer respC;

    v0 = *(u32 *)((u8 *)arg0 + 32);
    v1 = *(u16 *)((u8 *)arg0 + 28);
    v2 = arg0->data[8];
    MWTRACE(1, p_lbl_80095890 + 384, arg0->data[4], v0, v1, v2);
    if (v2 & 2) {
        memset(&respA, 0, 0x40);
        respA.flag = 0x80;
        respA.length = 0x40;
        respA.status = 0x12;
        fn_8008D398((u32)&respA, 0x40);
        return 0;
    }
    out = v1;
    fn_80089144(arg0, 0x40);
    TRKReadBuffer(arg0, &buf, out);
    err = fn_8008C730((u32)&buf, v0, &out, (((u32)v2 >> 3) & 1) ^ 1, 0);
    fn_80089174(arg0, 0);
    if (err == 0) {
        memset(&respB, 0, 0x40);
        respB.length = 0x40;
        respB.flag = 0x80;
        respB.status = err;
        err = TRKAppendBuffer(arg0, &respB, 0x40);
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
        respC.status = err;
        fn_8008D398((u32)&respC, 0x40);
        return 0;
    }
    MWTRACE(1, ((u32)p_lbl_80095890) + 0x60);
    err_2 = fn_80088B00(arg0);
    MWTRACE(1, ((u32)p_lbl_80095890) + 0x80, err_2);
    return err_2;
}
#pragma opt_lifetimes reset

struct fn_8008A3C0_Msg {
    u8 a[2052];
};

s32 fn_8008A3C0(TRKBuffer *arg0) {
    u8 *base;
    s32 v4 = 0;
    s32 code;
    u8 v2;
    u16 v1;
    u32 v0;
    struct fn_8008A3C0_Msg bufD;
    TRKReplyBuffer bufB;
    TRKReplyBuffer bufA;
    TRKReplyBuffer bufC;
    u32 loc_8;

    base = lbl_80095890;
    v0 = *(u32 *)((u8 *)arg0 + 0x20);
    v1 = *(u16 *)((u8 *)arg0 + 0x1C);
    v2 = arg0->data[8];
    MWTRACE(1, base + 0x1b0, arg0->data[4], v0, v1, v2);

    if ((v2 & 0x2) != 0) {
        memset(&bufA, 0, 0x40);
        bufA.flag = 0x80;
        bufA.length = 0x40;
        bufA.status = 0x12;
        fn_8008D398((u32)&bufA, 0x40);
        return 0;
    }

    loc_8 = v1;
    v4 = fn_8008C730((u32)&bufD, v0, &loc_8, ((((u32)v2) >> 3) & 1) ^ 1, 1);
    fn_80089174(arg0, 0);

    if (v4 == 0) {
        memset(&bufB, 0, 0x40);
        bufB.status = v4;
        bufB.length = loc_8 + 0x40;
        bufB.flag = 0x80;
        TRKAppendBuffer(arg0, &bufB, 0x40);
        v4 = TRKAppendBuffer(arg0, &bufD, loc_8);
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
        bufC.flag = 0x80;
        bufC.length = 0x40;
        bufC.status = code;
        fn_8008D398((u32)&bufC, 0x40);
        return 0;
    }

    MWTRACE(1, base + 0x60);
    v4 = fn_80088B00(arg0);
    MWTRACE(1, base + 0x80, v4);
    return v4;
}
