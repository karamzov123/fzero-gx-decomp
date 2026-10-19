#include "sdk_addresses.h"

#include "types.h"

typedef struct GXFifoObj {
    unsigned char data[0x80];
} GXFifoObj;

typedef struct GXTexObj {
    unsigned char data[0x20];
} GXTexObj;

typedef struct GXTexRegion GXTexRegion;

typedef struct GXTlutRegion GXTlutRegion;

typedef signed long long OSTime;

typedef enum GXPerf0 {
    GX_PERF0_VERTICES,
    GX_PERF0_CLIP_VTX,
    GX_PERF0_CLIP_CLKS,
    GX_PERF0_XF_WAIT_IN,
    GX_PERF0_XF_WAIT_OUT,
    GX_PERF0_XF_XFRM_CLKS,
    GX_PERF0_XF_LIT_CLKS,
    GX_PERF0_XF_BOT_CLKS,
    GX_PERF0_XF_REGLD_CLKS,
    GX_PERF0_XF_REGRD_CLKS,
    GX_PERF0_CLIP_RATIO,
    GX_PERF0_TRIANGLES,
    GX_PERF0_TRIANGLES_CULLED,
    GX_PERF0_TRIANGLES_PASSED,
    GX_PERF0_TRIANGLES_SCISSORED,
    GX_PERF0_TRIANGLES_0TEX,
    GX_PERF0_TRIANGLES_1TEX,
    GX_PERF0_TRIANGLES_2TEX,
    GX_PERF0_TRIANGLES_3TEX,
    GX_PERF0_TRIANGLES_4TEX,
    GX_PERF0_TRIANGLES_5TEX,
    GX_PERF0_TRIANGLES_6TEX,
    GX_PERF0_TRIANGLES_7TEX,
    GX_PERF0_TRIANGLES_8TEX,
    GX_PERF0_TRIANGLES_0CLR,
    GX_PERF0_TRIANGLES_1CLR,
    GX_PERF0_TRIANGLES_2CLR,
    GX_PERF0_QUAD_0CVG,
    GX_PERF0_QUAD_NON0CVG,
    GX_PERF0_QUAD_1CVG,
    GX_PERF0_QUAD_2CVG,
    GX_PERF0_QUAD_3CVG,
    GX_PERF0_QUAD_4CVG,
    GX_PERF0_AVG_QUAD_CNT,
    GX_PERF0_CLOCKS,
    GX_PERF0_NONE
} GXPerf0;

typedef enum GXPerf1 {
    GX_PERF1_TEXELS,
    GX_PERF1_TX_IDLE,
    GX_PERF1_TX_REGS,
    GX_PERF1_TX_MEMSTALL,
    GX_PERF1_TC_CHECK1_2,
    GX_PERF1_TC_CHECK3_4,
    GX_PERF1_TC_CHECK5_6,
    GX_PERF1_TC_CHECK7_8,
    GX_PERF1_TC_MISS,
    GX_PERF1_VC_ELEMQ_FULL,
    GX_PERF1_VC_MISSQ_FULL,
    GX_PERF1_VC_MEMREQ_FULL,
    GX_PERF1_VC_STATUS7,
    GX_PERF1_VC_MISSREP_FULL,
    GX_PERF1_VC_STREAMBUF_LOW,
    GX_PERF1_VC_ALL_STALLS,
    GX_PERF1_VERTICES,
    GX_PERF1_FIFO_REQ,
    GX_PERF1_CALL_REQ,
    GX_PERF1_VC_MISS_REQ,
    GX_PERF1_CP_ALL_REQ,
    GX_PERF1_CLOCKS,
    GX_PERF1_NONE
} GXPerf1;

struct GXTexRegion {
    u32 data[4];
};

struct GXTlutRegion {
    u32 data[4];
};

typedef struct GXData {
    union {
        unsigned char padding_extent[1456];
        struct {
            unsigned char padding_abtWaitPECopy[1266];
            u8 abtWaitPECopy;
        } view_abtWaitPECopy;
    } fields;
} GXData;

void fn_80033EB0(void);

GXFifoObj *fn_80032368(void);

OSTime OSGetTime(void);

extern GXData *const gx;

extern void *__memReg;

static inline u32 __GXReadMEMCounterU32(u32 low, u32 high) {
// Hardware or OS state can change asynchronously.
    u32 high0 = (*(volatile u16 *)((volatile u16 *)__memReg + (high)));
    u32 high1;
    u32 lowValue;
    do {
        high1 = high0;
// Hardware or OS state can change asynchronously.
        lowValue = (*(volatile u16 *)((volatile u16 *)__memReg + (low)));
// Hardware or OS state can change asynchronously.
        high0 = (*(volatile u16 *)((volatile u16 *)__memReg + (high)));
    } while (high0 != high1);
    return (high0 << 16) | lowValue;
}

// Hardware or OS state can change asynchronously.
volatile u32 __PIRegs[] : FZGX_ADDR___PIRegs;

static inline void __GXAbortWait(u32 clocks) {
    OSTime time0;
    OSTime time1;
    time0 = OSGetTime();
    do {
        time1 = OSGetTime();
    } while (time1 - time0 <= (clocks / 4));
}

static inline void __GXAbortWaitPECopyDone(void) {
    u32 peCnt0;
    u32 peCnt1;
    peCnt0 = __GXReadMEMCounterU32(0x28, 0x27);
    do {
        peCnt1 = peCnt0;
        __GXAbortWait(32);
        peCnt0 = __GXReadMEMCounterU32(0x28, 0x27);
    } while (peCnt0 != peCnt1);
}

void fn_80033EB0(void) {
    if (gx->fields.view_abtWaitPECopy.abtWaitPECopy && fn_80032368() != ((void *)0)) {
        __GXAbortWaitPECopyDone();
    }
    __PIRegs[0x18 / 4] = 1;
    __GXAbortWait(200);
    __PIRegs[0x18 / 4] = 0;
    __GXAbortWait(20);
}
