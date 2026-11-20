#include "types.h"


/* --- dol/TRKGetInput.c --- */
/* --- dol/TRKGetInput.c --- */
/* --- dol/TRKGetInput.c --- */
extern s32 fn_800894FC(void);
extern void TRKGetBuffer(void);
extern void fn_80088764(void *, s32);
extern u32 lbl_801A5098[6];
extern void TRKPostEvent(void *);

struct TRKGetInput_Buffer {
    u32 unk_0;
    u32 unk_4;
    s32 unk_8;
};

void TRKGetInput(void) {
    struct TRKGetInput_Buffer buffer;
    s32 result;

    result = fn_800894FC();
    if (result != -1) {
        TRKGetBuffer();
        fn_80088764(&buffer, 2);
        lbl_801A5098[0] = -1;
        buffer.unk_8 = result;
        TRKPostEvent(&buffer);
    }
}

/* --- dol/fn_800894FC.c --- */
extern u8 lbl_800956C0[400];
extern s32 fn_8008D410(void);
extern s32 fn_80089244(u32 *out_a, u32 *out_b);
extern void MWTRACE(u32, ...);
extern s32 fn_80089144(void *value, u32 arg1);
extern s32 fn_8008D3D4(void *dst, u32 size);
extern s32 TRKAppendBuffer_ui8(void *buffer, const void *data, u32 length);
extern void fn_800891B4(void *value);

s32 fn_800894FC(void) {
    u8 *rodata;
    u8 local_50[0x888];
    s32 local_10[0x10];
    u32 local_C;
    s32 diff;
    u32 local_8;
    s32 result;

    rodata = lbl_800956C0;
    if (fn_8008D410() <= 0) {
        return -1;
    }
    result = fn_80089244(&local_C, &local_8);
    MWTRACE(4, (u32)(rodata + 0xd0), result);
    fn_80089144((void *)local_8, 0);
    if (fn_8008D3D4(local_10, 0x40) == 0) {
        TRKAppendBuffer_ui8((void *)local_8, local_10, 0x40);
        result = local_C;
        if ((diff = local_10[0] - 0x40) > 0) {
            MWTRACE(1, (u32)(rodata + 0xf4), diff);
            if (fn_8008D3D4(local_50, local_10[0] - 0x40) == 0) {
                TRKAppendBuffer_ui8((void *)local_8, local_50, local_10[0]);
            } else {
                MWTRACE(8, (u32)(rodata + 0x110));
                fn_800891B4((void *)result);
                result = -1;
            }
        }
    } else {
        MWTRACE(8, (u32)(rodata + 0x144));
        fn_800891B4((void *)result);
        result = -1;
    }
    MWTRACE(1, (u32)(rodata + 0x16c), result);
    return result;
}

/* --- dol/usr_put_initialize.c --- */
// usr_put_initialize: empty in retail (single blr).
void usr_put_initialize(void) {
}

/* --- dol/fn_8008963C.c --- */
extern u32 fn_8008A754(void);
extern void OSReport(const char *);
extern void fn_8008A748(u32);

s32 fn_8008963C(const char *arg0) {
    s32 rc = 0;
    s8 ch;
    s32 r;
    struct {
        u8 a[2];
    } loc_8;

    while (rc == 0 && (ch = *arg0++) != 0) {
        r = fn_8008A754();
        loc_8.a[0] = ch;
        loc_8.a[1] = '\0';
        fn_8008A748(0);
        OSReport((const char *)&loc_8);
        fn_8008A748(r);
        rc = 0;
    }
    return rc;
}

/* --- dol/TRKDispatchMessage.c --- */
typedef struct TRKBuffer TRKBuffer;
struct TRKBuffer {
    u32 mutex;
    u32 isInUse;
    u32 length;
    u32 position;
    u8 data[(0x800 + 0x80)];
};

/* MetroTRK message command IDs (msgcmd.h) */
enum {
    kDSConnect = 0x01,
    kDSDisconnect = 0x02,
    kDSReset = 0x03,
    kDSVersions = 0x04,
    kDSSupportMask = 0x05,
    kDSOverride = 0x07,
    kDSReadMemory = 0x10,
    kDSWriteMemory = 0x11,
    kDSReadRegisters = 0x12,
    kDSWriteRegisters = 0x13,
    kDSSetOption = 0x17,
    kDSContinue = 0x18,
    kDSStep = 0x19,
    kDSStop = 0x1A
};

extern char lbl_80095850[];
extern char lbl_8009586C[];
extern s32 fn_8008A6E4(TRKBuffer *);
extern s32 fn_8008A66C(TRKBuffer *);
extern s32 fn_8008A614(TRKBuffer *);
extern s32 fn_8008A5BC(TRKBuffer *);
extern s32 fn_8008A5B4(TRKBuffer *);
extern s32 fn_8008A5AC(TRKBuffer *);
extern s32 fn_8008A3C0(TRKBuffer *);
extern s32 fn_8008A1CC(TRKBuffer *);
extern s32 fn_80089EEC(TRKBuffer *);
extern s32 fn_80089C5C(TRKBuffer *);
extern s32 fn_80089BAC(TRKBuffer *);
extern s32 fn_8008998C(TRKBuffer *);
extern s32 fn_800898E4(TRKBuffer *);
extern s32 fn_8008983C(TRKBuffer *);

s32 TRKDispatchMessage(TRKBuffer * arg0) {
    s32 result = 0x500;

    fn_80089144(arg0, 0);
    MWTRACE(1, lbl_80095850, arg0->data[4]);
    switch (arg0->data[4]) {
    case kDSConnect:
        result = fn_8008A6E4(arg0);
        break;
    case kDSDisconnect:
        result = fn_8008A66C(arg0);
        break;
    case kDSReset:
        result = fn_8008A614(arg0);
        break;
    case kDSOverride:
        result = fn_8008A5BC(arg0);
        break;
    case kDSVersions:
        result = fn_8008A5B4(arg0);
        break;
    case kDSSupportMask:
        result = fn_8008A5AC(arg0);
        break;
    case kDSReadMemory:
        result = fn_8008A3C0(arg0);
        break;
    case kDSWriteMemory:
        result = fn_8008A1CC(arg0);
        break;
    case kDSReadRegisters:
        result = fn_80089EEC(arg0);
        break;
    case kDSWriteRegisters:
        result = fn_80089C5C(arg0);
        break;
    case kDSContinue:
        result = fn_80089BAC(arg0);
        break;
    case kDSStep:
        result = fn_8008998C(arg0);
        break;
    case kDSStop:
        result = fn_800898E4(arg0);
        break;
    case kDSSetOption:
        result = fn_8008983C(arg0);
        break;
    }
    MWTRACE(1, lbl_8009586C, result);
    return result;
}
