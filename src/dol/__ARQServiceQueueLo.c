#include <types.h>
#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"
#include <dolphin/os/OSCache.h>
#include "types.h"


/* --- dol/ARInit.c --- */
/* --- dol/ARInit.c --- */
typedef void (*ARCallback)(void);

vu16 __DSPRegs[32] : FZGX_ADDR___DSPRegs;

void OSRegisterVersion(const char *id);

__OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt interrupt, __OSInterruptHandler handler);

extern const char *lbl_801A64D8;

extern ARCallback lbl_801A69E0;

extern u32 lbl_801A69F0;

extern u32 lbl_801A69F4;

extern u32 *lbl_801A69F8;

// Hardware or OS state can change asynchronously.
extern volatile BOOL lbl_801A69FC; // fzgx-allow: S2 SDK asynchronous state

void __ARHandler(__OSInterrupt interrupt, OSContext *context);

void __ARChecksize(void);

void __ARHandler(__OSInterrupt interrupt, OSContext *context);

void __ARChecksize(void);

u32 ARInit(u32 *stack_index_addr, u32 num_entries);

/* --- dol/__ARHandler.c --- */
void __ARHandler(__OSInterrupt interrupt, OSContext *context);

/* --- dol/__ARChecksize.c --- */
void *memset(void *dest, int value, size_t n);

void __ARClearInterrupt(void);


extern u32 lbl_801A69E4;

extern u32 lbl_801A69E8;

extern u32 lbl_801A69EC;

static inline void __ARClearInterrupt(void) {
    u16 tmp;
    tmp = __DSPRegs[5];
    tmp = (u16)((tmp & ~(0x00000080 | 0x00000008)) | 0x00000020);
    __DSPRegs[5] = tmp;
}

static inline void __ARWaitForDMA(void) {
    while (__DSPRegs[5] & 0x0200) {
    }
}

static inline void __ARWriteDMA(u32 mmem_addr, u32 aram_addr, u32 length) {
    __DSPRegs[16] = (u16)((__DSPRegs[16] & ~0x03ff) | (u16)(mmem_addr >> 16));
    __DSPRegs[16 + 1] = (u16)((__DSPRegs[16 + 1] & ~0xffe0) | (u16)(mmem_addr & 0xffff));
    __DSPRegs[18] = (u16)((__DSPRegs[18] & ~0x03ff) | (u16)(aram_addr >> 16));
    __DSPRegs[18 + 1] = (u16)((__DSPRegs[18 + 1] & ~0xffe0) | (u16)(aram_addr & 0xffff));
    __DSPRegs[20] = (u16)(__DSPRegs[20] & ~0x8000);
    __DSPRegs[20] = (u16)((__DSPRegs[20] & ~0x03ff) | (u16)(length >> 16));
    __DSPRegs[20 + 1] = (u16)((__DSPRegs[20 + 1] & ~0xffe0) | (u16)(length & 0xffff));
    __ARWaitForDMA();
    __ARClearInterrupt();
}

static inline void __ARReadDMA(u32 mmem_addr, u32 aram_addr, u32 length) {
    __DSPRegs[16] = (u16)((__DSPRegs[16] & ~0x03ff) | (u16)(mmem_addr >> 16));
    __DSPRegs[16 + 1] = (u16)((__DSPRegs[16 + 1] & ~0xffe0) | (u16)(mmem_addr & 0xffff));
    __DSPRegs[18] = (u16)((__DSPRegs[18] & ~0x03ff) | (u16)(aram_addr >> 16));
    __DSPRegs[18 + 1] = (u16)((__DSPRegs[18 + 1] & ~0xffe0) | (u16)(aram_addr & 0xffff));
    __DSPRegs[20] = (u16)(__DSPRegs[20] | 0x8000);
    __DSPRegs[20] = (u16)((__DSPRegs[20] & ~0x03ff) | (u16)(length >> 16));
    __DSPRegs[20 + 1] = (u16)((__DSPRegs[20 + 1] & ~0xffe0) | (u16)(length & 0xffff));
    __ARWaitForDMA();
    __ARClearInterrupt();
}

void __ARChecksize(void);

/* --- dol/__ARQServiceQueueLo.c --- */
typedef void (*ARQCallback)(u32 pointerToARQRequest);

typedef struct ARQRequest {
    struct ARQRequest *next;
    u32 owner;
    u32 type;
    u32 priority;
    u32 source;
    u32 dest;
    u32 length;
    ARQCallback callback;
} ARQRequest;

void ARStartDMA(u32 type, u32 mainmem_addr, u32 aram_addr, u32 length);

extern ARQRequest *lbl_801A6A08;

extern ARQRequest *lbl_801A6A14;

extern ARQCallback lbl_801A6A1C;

extern u32 lbl_801A6A20;

void __ARQServiceQueueLo(void) {
    if ((lbl_801A6A14 == 0) && (lbl_801A6A08)) {
        lbl_801A6A14 = lbl_801A6A08;
        lbl_801A6A08 = lbl_801A6A08->next;
    }
    if (lbl_801A6A14) {
        if (lbl_801A6A14->length <= lbl_801A6A20) {
            if (lbl_801A6A14->type == 0x00)
                ARStartDMA(lbl_801A6A14->type, lbl_801A6A14->source, lbl_801A6A14->dest,
                           lbl_801A6A14->length);
            else
                ARStartDMA(lbl_801A6A14->type, lbl_801A6A14->dest, lbl_801A6A14->source,
                           lbl_801A6A14->length);
            lbl_801A6A1C = lbl_801A6A14->callback;
        } else {
            if (lbl_801A6A14->type == 0x00)
                ARStartDMA(lbl_801A6A14->type, lbl_801A6A14->source, lbl_801A6A14->dest,
                           lbl_801A6A20);
            else
                ARStartDMA(lbl_801A6A14->type, lbl_801A6A14->dest, lbl_801A6A14->source,
                           lbl_801A6A20);
        }
        lbl_801A6A14->length -= lbl_801A6A20;
        lbl_801A6A14->source += lbl_801A6A20;
        lbl_801A6A14->dest += lbl_801A6A20;
    }
}

/* --- dol/fn_80020460.c --- */
// fn_80020460: empty in retail (single blr).
void fn_80020460(void) {
}

/* --- dol/__ARQInterruptServiceRoutine.c --- */
void ARStartDMA(u32 type, u32 mainmem_addr, u32 aram_addr, u32 length);

extern ARQRequest *lbl_801A6A00;

extern ARQRequest *lbl_801A6A10;


extern ARQCallback lbl_801A6A18;


void __ARQPopTaskQueueHi(void);

void __ARQServiceQueueLo(void);

static inline void __ARQPopTaskQueueHi(void) {
    if (lbl_801A6A00) {
        if (lbl_801A6A00->type == 0x00) {
            ARStartDMA(lbl_801A6A00->type, lbl_801A6A00->source, lbl_801A6A00->dest,
                       lbl_801A6A00->length);
        } else {
            ARStartDMA(lbl_801A6A00->type, lbl_801A6A00->dest, lbl_801A6A00->source,
                       lbl_801A6A00->length);
        }
        lbl_801A6A18 = lbl_801A6A00->callback;
        lbl_801A6A10 = lbl_801A6A00;
        lbl_801A6A00 = lbl_801A6A00->next;
    }
}

void __ARQInterruptServiceRoutine(void) {
    if (lbl_801A6A18) {
        (*lbl_801A6A18)((u32)lbl_801A6A10);
        lbl_801A6A10 = 0;
        lbl_801A6A18 = 0;
    } else if (lbl_801A6A1C) {
        (*lbl_801A6A1C)((u32)lbl_801A6A14);
        lbl_801A6A14 = 0;
        lbl_801A6A1C = 0;
    }
    __ARQPopTaskQueueHi();
    if (lbl_801A6A10 == 0)
        __ARQServiceQueueLo();
}
