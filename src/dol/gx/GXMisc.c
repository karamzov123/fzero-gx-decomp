#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
#include "types.h"
#include "sdk_addresses.h"
#include "dolphin/hw_regs.h"
#include <dolphin/os/OSInterrupt.h>
#include <types.h>
#include <dolphin/types.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os.h>
typedef void (*GXDrawSyncCallback)(u16 token);
typedef void (*GXDrawDoneCallback)(void);

extern GXDrawSyncCallback lbl_801A6C10;
extern GXDrawDoneCallback lbl_801A6C14;
extern GXBool lbl_801A6C18;
extern OSThreadQueue lbl_801A6C1C;

void OSSleepThread(OSThreadQueue *queue);
void OSWakeupThread(OSThreadQueue *queue);
void OSInitThreadQueue(OSThreadQueue *queue);
void *__OSSetInterruptHandler(s16 interrupt, void (*handler)(s16, OSContext *));
void GXTokenInterruptHandler(s16 interrupt, OSContext *context);
void GXFinishInterruptHandler(s16 interrupt, OSContext *context);
void GXFlush(void);


void GXSetMisc(u32 arg0, u32 arg1) {
    GXData *p;

    switch ((s32)arg0) {
    case 0:
        break;
    case 1:
        p = gx;
        p->vNum = arg1;
        p->vNumNot = (__cntlzw(p->vNum) >> 5) & 0xFFFF;
        p->bpSentNot = 1;
        if (p->vNum != 0) {
            p->dirtyState |= 8;
        }
        break;
    case 2:
        gx->dlSaveContext = (arg1 != 0);
        break;
    case 3:
        gx->abtWaitPECopy = (arg1 != 0);
        break;
    }
}

extern u32 PPCSync(void);
extern u32 fn_8003458C(void);

void GXFlush(void) {
    if (gx->dirtyState != 0) {
    fn_8003458C();
    }
    *(u32 *)((u8 *)0xCC010000 + -32768) = 0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(u32 *)((u8 *)0xCC010000 + -32768) = 0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(u32 *)((u8 *)0xCC010000 + -32768) = 0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(u32 *)((u8 *)0xCC010000 + -32768) = 0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(u32 *)((u8 *)0xCC010000 + -32768) = 0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(u32 *)((u8 *)0xCC010000 + -32768) = 0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(u32 *)((u8 *)0xCC010000 + -32768) = 0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(u32 *)((u8 *)0xCC010000 + -32768) = 0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    PPCSync();
}

extern u32 PPCMfwpar(void);
extern void PPCMtwpar(u32);

void fn_80033E7C(void) {
    u32 status;

    do {
        status = PPCMfwpar();
    } while ((status & 1u) != 0);

    PPCMtwpar(0x0C008000); // fzgx-allow: A1 fixed PPC hardware address
}

typedef signed long long OSTime;

void fn_80033EB0(void);

GXFifoObj *fn_80032368(void);

OSTime OSGetTime(void);

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
    if (gx->abtWaitPECopy && fn_80032368() != ((void *)0)) {
        __GXAbortWaitPECopyDone();
    }
    __PIRegs[0x18 / 4] = 1;
    __GXAbortWait(200);
    __PIRegs[0x18 / 4] = 0;
    __GXAbortWait(20);
}

#define SET_REG_FIELD(reg, size, shift, val) \
    ((reg) = ((reg) & ~(((1 << (size)) - 1) << (shift))) | ((val) << (shift)))
#define GET_REG_FIELD(reg, size, shift) (((reg) >> (shift)) & ((1 << (size)) - 1))

void fn_8003401C(u16 token) {
    s32 enabled;
    u32 reg;

    enabled = OSDisableInterrupts();
    reg = token | 0x48000000;
    GX_WRITE_RAS_REG(reg);
    SET_REG_FIELD(reg, 16, 0, token);
    SET_REG_FIELD(reg, 8, 24, 0x47);
    GX_WRITE_RAS_REG(reg);
    GXFlush();
    OSRestoreInterrupts(enabled);
    gx->bpSentNot = 0;
}


void GXSetDrawDone(void) {
    u8 padding[8];
    BOOL restore = OSDisableInterrupts();
    do {
        GXWGFifo.u8 = (u8)(0x61);
        GXWGFifo.u32 = (u32)(0x45000002);
        ;
    } while (0);
    GXFlush();
    lbl_801A6C18 = 0;
    OSRestoreInterrupts(restore);
}


static inline void GXWaitDrawDone(void) {
    BOOL enabled = OSDisableInterrupts();

    while (lbl_801A6C18 == 0) {
        OSSleepThread(&lbl_801A6C1C);
    }
    OSRestoreInterrupts(enabled);
}

void GXDrawDone(void) {
    /* WARNING: compiler-diff device, not original code: reserves the 8 bytes of retail's frame
       that the inlined GXSetDrawDone/GXWaitDrawDone do not account for. */
    u8 padding[8];

    GXSetDrawDone();
    GXWaitDrawDone();
}

// Hardware register block pointer; accesses must not be cached.
extern volatile u16 *__peReg;

void GXPokeAlphaMode(u32 arg0, u32 arg1) {
    __peReg[3] = (u16)((arg0 << 8) | (arg1 & 0xFF));
}

void GXPokeAlphaRead(u32 arg0) {
    u32 v0;
    v0 = (arg0 & 0xFFFFFFFB);
    __peReg[4] = (v0 | 4);
}

// Hardware register pointer; accesses must not be cached.

void GXPokeAlphaUpdate(u8 value) {
    __peReg[1] = (u16)((__peReg[1] & ~0x10) | ((u32)value << 4));
}

typedef enum _GXBlendMode {
    GX_BM_NONE,
    GX_BM_BLEND,
    GX_BM_LOGIC,
    GX_BM_SUBTRACT,
    GX_MAX_BLENDMODE,
} GXBlendMode;

typedef enum _GXBlendFactor {
    GX_BL_ZERO,
    GX_BL_ONE,
    GX_BL_SRC_COLOR,
    GX_BL_DST_COLOR = 2,
    GX_BL_INV_SRC_COLOR,
    GX_BL_INV_DST_COLOR = 3,
    GX_BL_SRC_ALPHA,
    GX_BL_INV_SRC_ALPHA,
    GX_BL_DST_ALPHA,
    GX_BL_INV_DST_ALPHA,
} GXBlendFactor;

typedef enum _GXLogicOp {
    GX_LO_CLEAR,
    GX_LO_AND,
    GX_LO_REV_AND,
    GX_LO_COPY,
    GX_LO_INV_AND,
    GX_LO_NOOP,
    GX_LO_XOR,
    GX_LO_OR,
    GX_LO_NOR,
    GX_LO_EQUIV,
    GX_LO_INV,
    GX_LO_REV_OR,
    GX_LO_INV_COPY,
    GX_LO_INV_OR,
    GX_LO_NAND,
    GX_LO_SET,
} GXLogicOp;

void GXPokeBlendMode(GXBlendMode mode, GXBlendFactor srcFactor, GXBlendFactor destFactor,
                 GXLogicOp op) {
    u32 reg;
    reg = (*(vu16 *)((vu16 *)(__peReg) + (1)));
    (reg) = (reg & ~(((1 << ((31 - 31 + 1))) - 1) << (31 - (31) - ((31 - 31 + 1)) + 1))) |
            ((int)((mode == GX_BM_BLEND) || (mode == GX_BM_SUBTRACT))
             << (31 - (31) - ((31 - 31 + 1)) + 1));
    (reg) = (reg & ~(((1 << ((20 - 20 + 1))) - 1) << (31 - (20) - ((20 - 20 + 1)) + 1))) |
            ((int)((mode == GX_BM_SUBTRACT)) << (31 - (20) - ((20 - 20 + 1)) + 1));
    (reg) = (reg & ~(((1 << ((30 - 30 + 1))) - 1) << (31 - (30) - ((30 - 30 + 1)) + 1))) |
            ((int)((mode == GX_BM_LOGIC)) << (31 - (30) - ((30 - 30 + 1)) + 1));
    (reg) = (reg & ~(((1 << ((19 - 16 + 1))) - 1) << (31 - (16) - ((19 - 16 + 1)) + 1))) |
            ((int)(op) << (31 - (16) - ((19 - 16 + 1)) + 1));
    (reg) = (reg & ~(((1 << ((23 - 21 + 1))) - 1) << (31 - (21) - ((23 - 21 + 1)) + 1))) |
            ((int)(srcFactor) << (31 - (21) - ((23 - 21 + 1)) + 1));
    (reg) = (reg & ~(((1 << ((26 - 24 + 1))) - 1) << (31 - (24) - ((26 - 24 + 1)) + 1))) |
            ((int)(destFactor) << (31 - (24) - ((26 - 24 + 1)) + 1));
    (reg) = (reg & ~(((1 << ((7 - 0 + 1))) - 1) << (31 - (0) - ((7 - 0 + 1)) + 1))) |
            ((int)(0x41) << (31 - (0) - ((7 - 0 + 1)) + 1));
    (*(vu16 *)((vu16 *)(__peReg) + (1)) = reg);
}

// The PE register is memory-mapped hardware and must not be cached.

void GXPokeColorUpdate(u8 value) {
    u16 current = __peReg[1];
    __peReg[1] = (u16)((current & ~(1 << 3)) | ((value & 0xFF) << 3));
}

void GXPokeDstAlpha(GXBool enable, u8 alpha) {
    u32 val = 0;
    (val) = (val & ~(((1 << (8)) - 1) << (31 - (0x18) - (8) + 1))) |
            ((int)(alpha) << (31 - (0x18) - (8) + 1));
    (val) = (val & ~(((1 << (1)) - 1) << (31 - (0x17) - (1) + 1))) |
            ((int)(enable) << (31 - (0x17) - (1) + 1));
    __peReg[2] = val;
}

// The PE register is memory-mapped hardware and must not be cached.

void GXPokeDither(u8 value) {
    u16 current = __peReg[1];
    __peReg[1] = (u16)((current & ~(1 << 2)) | ((value & 0xFF) << 2));
}

// The PE register is memory-mapped hardware and must not be cached.

void GXPokeZMode(u32 arg0, u32 arg1, u32 arg2) {
    u32 value;
    value = arg0 & 0xFF;
    value = (value & ~(7u << 1)) | (arg1 << 1);
    value = (value & ~(1u << 4)) | ((arg2 & 0xFF) << 4);
    *__peReg = (u16)value;
}

struct fn_8003432C_Arg2 {
    u32 unk_0;
};

u32 fn_8003432C(u32 arg0, u32 arg1, struct fn_8003432C_Arg2 *arg2) {
    u32 v0;
    v0 = ((((((arg0 & 0xFFFF) << 2) | 0xC8000000) & 0xFFC00FFF) | ((arg1 & 0xFFFF) << 12)) & 0xFF3FFFFF);
    arg2->unk_0 = *(u32 *)((u8 *)v0 + 0);
    return v0;
}

struct GXPeekZ_Arg2 {
    u32 unk_0;
};

u32 GXPeekZ(u32 arg0, u32 arg1, struct GXPeekZ_Arg2 *arg2) {
    u32 v0;
    v0 = (((((((arg0 & 0xFFFF) << 2) | 0xC8000000) & 0xFFC00FFF) | ((arg1 & 0xFFFF) << 12)) & 0xFF3FFFFF) | 0x400000);
    arg2->unk_0 = *(u32 *)((u8 *)v0 + 0);
    return v0;
}


GXDrawSyncCallback fn_80034378(GXDrawSyncCallback callback) {
    GXDrawSyncCallback old = lbl_801A6C10;
    BOOL enabled = OSDisableInterrupts();

    lbl_801A6C10 = callback;
    OSRestoreInterrupts(enabled);
    return old;
}

// The PE register is memory-mapped hardware and must not be cached.

void GXTokenInterruptHandler(s16 interrupt, OSContext *context) {
    u16 current;
    OSContext exceptionContext;

    current = __peReg[7];
    if (lbl_801A6C10 != 0) {
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        lbl_801A6C10(current);
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
    __peReg[5] = (u16)((__peReg[5] & ~4u) | 4);
}


GXDrawDoneCallback fn_80034444(GXDrawDoneCallback callback) {
    GXDrawDoneCallback old = lbl_801A6C14;
    BOOL enabled = OSDisableInterrupts();

    lbl_801A6C14 = callback;
    OSRestoreInterrupts(enabled);
    return old;
}

// The PE register is memory-mapped hardware and must not be cached.

void GXFinishInterruptHandler(s16 interrupt, OSContext *context) {
    u16 current;
    OSContext exceptionContext;

    current = __peReg[5];
    __peReg[5] = (u16)((current & ~8u) | 8);
    lbl_801A6C18 = 1;

    if (lbl_801A6C14 != 0) {
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        lbl_801A6C14();
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }

    OSWakeupThread(&lbl_801A6C1C);
}

// PE register block is memory-mapped hardware and must be accessed volatile.

void __GXPEInit(void) {
    u32 current;

    __OSSetInterruptHandler(0x12, GXTokenInterruptHandler);
    __OSSetInterruptHandler(0x13, GXFinishInterruptHandler);
    OSInitThreadQueue(&lbl_801A6C1C);
    __OSUnmaskInterrupts(0x2000);
    __OSUnmaskInterrupts(0x1000);

    current = __peReg[5];
    current = (current & ~0x4u) | 0x4u;
    current = (current & ~0x8u) | 0x8u;
    current = (current & ~0x1u) | 0x1u;
    current = (current & ~0x2u) | 0x2u;
    __peReg[5] = current;
}
