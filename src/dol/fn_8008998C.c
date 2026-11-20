#include "types.h"


/* --- dol/fn_8008998C.c --- */
typedef struct Sig_fn_8008998C_TRKBuffer Sig_fn_8008998C_TRKBuffer;
struct Sig_fn_8008998C_TRKBuffer {
    u32 mutex;
    u32 isInUse;
    u32 length;
    u32 position;
    u8 data[(0x800 + 0x80)];
};
struct Sig_fn_80089144_fn_80089144_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u32 unk_C;
};
extern s32 fn_80089144(struct Sig_fn_80089144_fn_80089144_Arg0 *, u32);
extern s32 fn_8008D398(u32, u32);
extern s32 TRKTargetStopped(void);
extern u32 fn_8008B6BC(void);
extern void *memset(void *, int, u32);
extern s32 fn_8008B784(u32, u32);
extern s32 fn_8008B6CC(u32, u32, u32);
s32 fn_8008998C(Sig_fn_8008998C_TRKBuffer *arg0) {
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
    fn_80089144((struct Sig_fn_80089144_fn_80089144_Arg0 *)arg0, 0);
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

/* --- dol/fn_80089BAC.c --- */
/* --- dol/fn_80089BAC.c --- */
struct fn_80089BAC_Buffer {
    u32 unk_0;
    u8 unk_4;
    u8 pad_5[3];
    u8 unk_8;
    u8 pad_9[0x37];
};

extern u8 lbl_800958C4[44];
extern u32 MWTRACE(u32, ...);
extern s32 TRKTargetContinue(void);

s32 fn_80089BAC(void) {
    struct fn_80089BAC_Buffer buffer0;
    struct fn_80089BAC_Buffer buffer1;

    MWTRACE(1, (u32)&lbl_800958C4);
    if (!TRKTargetStopped()) {
        memset(&buffer0, 0, 0x40);
        buffer0.unk_4 = 0x80;
        buffer0.unk_0 = 0x40;
        buffer0.unk_8 = 0x16;
        fn_8008D398((u32)&buffer0, 0x40);
        return 0;
    }

    memset(&buffer1, 0, 0x40);
    buffer1.unk_4 = 0x80;
    buffer1.unk_0 = 0x40;
    buffer1.unk_8 = 0;
    fn_8008D398((u32)&buffer1, 0x40);
    return TRKTargetContinue();
}

/* --- dol/fn_80089C5C.c --- */
struct fn_80089C5C_TRKBuffer {
    u32 mutex;
    BOOL isInUse;
    u32 length;
    u32 position;
    u8 data[(0x800 + 0x80)];
};

struct fn_80089C5C_Buffer {
    u32 unk_0;
    u8 unk_4;
    u8 pad_5[3];
    u8 unk_8;
    u8 pad_9[0x37];
};


struct Sig_fn_80089174_fn_80089174_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u32 unk_C;
};

struct Sig_fn_80088B00_fn_80088B00_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

typedef enum {
    Sig_TRKTargetAccessDefault_DS_NoError = 0x0,
    Sig_TRKTargetAccessDefault_DS_StepError = 0x1,
    Sig_TRKTargetAccessDefault_DS_ParameterError = 0x2,
    Sig_TRKTargetAccessDefault_DS_EventQueueFull = 0x100,
    Sig_TRKTargetAccessDefault_DS_NoMessageBufferAvailable = 0x300,
    Sig_TRKTargetAccessDefault_DS_MessageBufferOverflow = 0x301,
    Sig_TRKTargetAccessDefault_DS_MessageBufferReadError = 0x302,
    Sig_TRKTargetAccessDefault_DS_DispatchError = 0x500,
    Sig_TRKTargetAccessDefault_DS_InvalidMemory = 0x700,
    Sig_TRKTargetAccessDefault_DS_InvalidRegister = 0x701,
    Sig_TRKTargetAccessDefault_DS_CWDSException = 0x702,
    Sig_TRKTargetAccessDefault_DS_UnsupportedError = 0x703,
    Sig_TRKTargetAccessDefault_DS_InvalidProcessID = 0x704,
    Sig_TRKTargetAccessDefault_DS_InvalidThreadID = 0x705,
    Sig_TRKTargetAccessDefault_DS_OSError = 0x706,
    Sig_TRKTargetAccessDefault_DS_Error800 = 0x800,
} Sig_TRKTargetAccessDefault_DSError;

typedef struct Sig_TRKTargetAccessDefault_TRKBuffer {
    u32 mutex;
    BOOL isInUse;
    u32 length;
    u32 position;
    u8 data[(0x800 + 0x80)];
} Sig_TRKTargetAccessDefault_TRKBuffer;

typedef int Sig_fn_8008BFB4_DSError;

typedef struct Sig_fn_8008BFB4_TRKBuffer {
    u32 mutex;
    BOOL isInUse;
    u32 length;
    u32 position;
    u8 data[(0x800 + 0x80)];
} Sig_fn_8008BFB4_TRKBuffer;

typedef int Sig_TRKAppendBuffer_DSError;

typedef struct Sig_TRKAppendBuffer_TRKBuffer {
    u32 mutex;
    BOOL isInUse;
    u32 length;
    u32 position;
    u8 data[(0x800 + 0x80)];
} Sig_TRKAppendBuffer_TRKBuffer;

extern Sig_TRKTargetAccessDefault_DSError TRKTargetAccessDefault(u32, u32, Sig_TRKTargetAccessDefault_TRKBuffer *, size_t *, BOOL);
extern Sig_fn_8008BFB4_DSError fn_8008BFB4(u32, u32, Sig_fn_8008BFB4_TRKBuffer *, size_t *, BOOL);
extern u32 fn_8008C124(u32, u32, u32, void *, u32);
extern u32 fn_8008BB7C(u32, u32, u32, void *, u32);
extern Sig_TRKAppendBuffer_DSError TRKAppendBuffer(Sig_TRKAppendBuffer_TRKBuffer *, const void *, size_t);
extern u32 fn_80089174(struct Sig_fn_80089174_fn_80089174_Arg0 *, u32);
extern s32 fn_80088B00(struct Sig_fn_80088B00_fn_80088B00_Arg0 *);
extern u32 lbl_800958F0[];
extern u32 lbl_80095910[];

s32 fn_80089C5C(struct fn_80089C5C_TRKBuffer *arg0) {
    struct fn_80089C5C_TRKBuffer *self;
    struct fn_80089C5C_Buffer buf1;
    struct fn_80089C5C_Buffer buf0;
    struct fn_80089C5C_Buffer buf2;
    u32 size;
    s32 result;
    u16 f1C;
    u16 f20;

    self = arg0;
    result = self->data[8];
    f1C = *(u16 *)((u8 *)self + 0x1C);
    f20 = *(u16 *)((u8 *)self + 0x20);

    fn_80089144((struct Sig_fn_80089144_fn_80089144_Arg0 *)self, 0);

    if (f1C > f20) {
        memset(&buf0, 0, 0x40);
        buf0.unk_4 = 0x80;
        buf0.unk_0 = 0x40;
        buf0.unk_8 = 0x14;
        fn_8008D398((u32)&buf0, 0x40);
        return 0;
    }

    fn_80089144((struct Sig_fn_80089144_fn_80089144_Arg0 *)self, 0x40);

    switch (result) {
    case 0:
        result = TRKTargetAccessDefault(f1C, f20, (Sig_TRKTargetAccessDefault_TRKBuffer *)self, &size, 0);
        break;
    case 1:
        result = fn_8008C124(f1C, f20, (u32)self, (void *)&size, 0);
        break;
    case 2:
        result = fn_8008BFB4(f1C, f20, (Sig_fn_8008BFB4_TRKBuffer *)self, &size, 0);
        break;
    case 3:
        result = fn_8008BB7C(f1C, f20, (u32)self, (void *)&size, 0);
        break;
    default:
        result = 0x703;
        break;
    }

    fn_80089174((struct Sig_fn_80089174_fn_80089174_Arg0 *)self, 0);

    if (result == 0) {
        memset(&buf1, 0, 0x40);
        buf1.unk_0 = 0x40;
        buf1.unk_4 = 0x80;
        buf1.unk_8 = result;
        result = TRKAppendBuffer((Sig_TRKAppendBuffer_TRKBuffer *)self, &buf1, 0x40);
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
        buf2.unk_4 = 0x80;
        buf2.unk_0 = 0x40;
        buf2.unk_8 = result;
        fn_8008D398((u32)&buf2, 0x40);
        return 0;
    }

    MWTRACE(1, (u32)&lbl_800958F0);
    result = fn_80088B00((struct Sig_fn_80088B00_fn_80088B00_Arg0 *)self);
    MWTRACE(1, (u32)&lbl_80095910, result);
    return result;
}
