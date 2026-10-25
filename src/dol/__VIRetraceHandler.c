#include "sdk_addresses.h"

#include "types.h"

// Hardware or OS state can change asynchronously.
typedef volatile u16 vu16;

typedef unsigned int uint;

typedef struct OSContext OSContext;

typedef struct OSContext {
    u32 gpr[32];
    u32 cr;
    u32 lr;
    u32 ctr;
    u32 xer;
    f64 fpr[32];
    u32 field_0x190;
    u32 fpscr;
    u32 srr0;
    u32 srr1;
    u16 mode;
    u16 state;
    u32 gqr[8];
    f64 ps[32];
} OSContext;

typedef s16 __OSInterrupt;

typedef u16 OSThreadState;

typedef s32 OSPriority;

typedef struct OSThread OSThread;

typedef struct OSThreadQueue OSThreadQueue;

typedef struct OSThreadLink OSThreadLink;

typedef struct OSMutex OSMutex;

typedef struct OSMutexQueue OSMutexQueue;

typedef struct OSMutexLink OSMutexLink;

struct OSThreadLink {
    OSThread *next;
    OSThread *prev;
};

struct OSThreadQueue {
    OSThread *head;
    OSThread *tail;
};

struct OSMutexLink {
    OSMutex *next;
    OSMutex *prev;
};

struct OSMutexQueue {
    OSMutex *head;
    OSMutex *tail;
};

struct OSThread {
    OSContext context;
    OSThreadState state;
    u16 attributes;
    s32 suspend_count;
    OSPriority effective_priority;
    OSPriority base_priority;
    void *exit_value;
    OSThreadQueue *queue;
    OSThreadLink link;
    OSThreadQueue join_queue;
    OSMutex *mutex;
    OSMutexQueue owned_mutexes;
    OSThreadLink active_threads_link;
    u8 *stack_base;
    u32 *stack_end;
    u8 *error_code;
    void *data[2];
};

typedef struct OSMutex {
    OSThreadQueue queue;
    OSThread *thread;
    s32 count;
    OSMutexLink link;
} OSMutex;

typedef enum { VI_XFBMODE_SF = 0, VI_XFBMODE_DF } VIXFBMode;

typedef struct {
    u8 equ;
    u16 acv;
    u16 prbOdd;
    u16 prbEven;
    u16 psbOdd;
    u16 psbEven;
    u8 bs1;
    u8 bs2;
    u8 bs3;
    u8 bs4;
    u16 be1;
    u16 be2;
    u16 be3;
    u16 be4;
    u16 nhlines;
    u16 hlw;
    u8 hsy;
    u8 hcs;
    u8 hce;
    u8 hbe640;
    u16 hbs640;
    u8 hbeCCIR656;
    u16 hbsCCIR656;
} VITiming;

typedef struct {
    u16 DispPosX;
    u16 DispPosY;
    u16 DispSizeX;
    u16 DispSizeY;
    u16 AdjustedDispPosX;
    u16 AdjustedDispPosY;
    u16 AdjustedDispSizeY;
    u16 AdjustedPanPosY;
    u16 AdjustedPanSizeY;
    u16 FBSizeX;
    u16 FBSizeY;
    u16 PanPosX;
    u16 PanPosY;
    u16 PanSizeX;
    u16 PanSizeY;
    VIXFBMode FBMode;
    u32 nonInter;
    u32 tv;
    u8 wordPerLine;
    u8 std;
    u8 wpl;
    u32 bufAddr;
    u32 tfbb;
    u32 bfbb;
    u8 xof;
    BOOL black;
    BOOL threeD;
    u32 rbufAddr;
    u32 rtfbb;
    u32 rbfbb;
    VITiming *timing;
} SomeVIStruct;

void __VIRetraceHandler(__OSInterrupt unused, OSContext *context);

extern int __cntlzw(uint);

void OSSetCurrentContext(OSContext *context);

void OSClearContext(OSContext *context);

void OSWakeupThread(OSThreadQueue *queue);

vu16 __VIRegs[59] : FZGX_ADDR___VIRegs;

// Hardware or OS state can change asynchronously.
extern volatile u32 lbl_801A6924;

// Hardware or OS state can change asynchronously.
extern volatile u32 lbl_801A6928;

extern OSThreadQueue lbl_801A692C;

extern void (*lbl_801A6934)(u32);

extern void (*lbl_801A6938)(u32);

// Hardware or OS state can change asynchronously.
extern volatile u32 lbl_801A6950;

// Hardware or OS state can change asynchronously.
extern volatile u64 lbl_801A6958;

extern VITiming *lbl_801A6960;

extern u32 CurrTvMode_801A6964;

extern u32 lbl_801A6968;

extern u32 lbl_801A696C;

extern VITiming timing[10];

u32 getCurrentFieldEvenOdd(void);

void (*__VIDisableRawPositionInterrupt())(s16, s16);

struct viBss {
    unsigned char padding_0[120];
// Hardware or OS state can change asynchronously.
    u16 shdwRegs[59];
    unsigned char padding_238[2];
    SomeVIStruct HorVer;
};
extern struct viBss lbl_8015CF68;

static inline s32 cntlzd(u64 bit) {
    u32 hi;
    u32 lo;
    s32 value;
    hi = bit >> 32;
    lo = bit & 0xFFFFFFFF;
    value = __cntlzw(hi);
    if (value < 32) {
        return value;
    }
    return __cntlzw(lo) + 32;
}

static inline int VISetRegs(struct viBss *bss) {
    s32 regIndex;
    if (lbl_801A6950 != 1 || getCurrentFieldEvenOdd() != 0) {
        while (lbl_801A6958 != 0) {
            regIndex = cntlzd(lbl_801A6958);
            __VIRegs[regIndex] = (bss->shdwRegs)[regIndex];
            lbl_801A6958 &= ~((u64)1 << (63 - regIndex));
        }
        lbl_801A6950 = 0;
        lbl_801A6960 = (bss->HorVer).timing;
        CurrTvMode_801A6964 = (bss->HorVer).tv;
        lbl_801A696C = lbl_801A6968;
        return 1;
    }
    return 0;
}

#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
void __VIRetraceHandler(__OSInterrupt unused, OSContext *context) {
    OSContext exceptionContext;
    struct viBss *bss;
    u16 reg;
    u32 inter;
    bss = &lbl_8015CF68;
    inter = 0;
    reg = __VIRegs[0x18];
    if (reg & 0x8000) {
        __VIRegs[0x18] = reg & ~0x8000;
        inter |= 1;
    }
    reg = __VIRegs[0x1A];
    if (reg & 0x8000) {
        __VIRegs[0x1A] = reg & ~0x8000;
        inter |= 2;
    }
    reg = __VIRegs[0x1C];
    if (reg & 0x8000) {
        __VIRegs[0x1C] = reg & ~0x8000;
        inter |= 4;
    }
    reg = __VIRegs[0x1E];
    if (reg & 0x8000) {
        __VIRegs[0x1E] = reg & ~0x8000;
        inter |= 8;
    }
    if ((inter & 4) || (inter & 8)) {
        OSSetCurrentContext(context);
        return;
    }
    if (inter == 0) {
        (void)0;
    }
    lbl_801A6924 += 1;
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(&exceptionContext);
    if (lbl_801A6934) {
        lbl_801A6934(lbl_801A6924);
    }
    if (lbl_801A6928 != 0) {
        if (VISetRegs(bss) != 0) {
            lbl_801A6928 = 0;
            SIRefreshSamplingRate();
        }
    }
    if (lbl_801A6938) {
        OSClearContext(&exceptionContext);
        lbl_801A6938(lbl_801A6924);
    }
    OSWakeupThread(&lbl_801A692C);
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(context);
}
#pragma opt_strength_reduction reset

#pragma opt_loop_invariants reset

