#include <dolphin/os/OSInterrupt.h>
#include "types.h"

extern void OSRegisterVersion(const char *id);
extern void fn_8001E7E4(void (*)(void));
extern const char *lbl_801A64E0;
extern s32 lbl_801A6A24;
struct ARQRequest;
extern struct ARQRequest *lbl_801A6A04;
extern struct ARQRequest *lbl_801A6A0C;

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

// fn_80020460: empty in retail (single blr).
void fn_80020460(void) {
}

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

void ARQInit(void) {
    if (lbl_801A6A24 != 1) {
        OSRegisterVersion(lbl_801A64E0);
        lbl_801A6A08 = 0;
        lbl_801A6A00 = 0;
        lbl_801A6A20 = 4096;
        fn_8001E7E4(__ARQInterruptServiceRoutine);
        lbl_801A6A10 = 0;
        lbl_801A6A14 = 0;
        lbl_801A6A18 = 0;
        lbl_801A6A1C = 0;
        lbl_801A6A24 = 1;
    }
}
void ARQPostRequest(ARQRequest *request, u32 owner, u32 type, u32 priority, u32 source, u32 dest,
                 u32 length, ARQCallback callback) {
    BOOL enabled;
    request->next = 0;
    request->owner = owner;
    request->type = type;
    request->source = source;
    request->dest = dest;
    request->length = length;
    if (callback) {
        request->callback = callback;
    } else {
        request->callback = (ARQCallback)&fn_80020460;
    }
    enabled = OSDisableInterrupts();
    switch (priority) {
    case 0:
        if (lbl_801A6A08) {
            lbl_801A6A0C->next = request;
        } else {
            lbl_801A6A08 = request;
        }
        lbl_801A6A0C = request;
        break;
    case 1:
        if (lbl_801A6A00) {
            lbl_801A6A04->next = request;
        } else {
            lbl_801A6A00 = request;
        }
        lbl_801A6A04 = request;
        break;
    }
    if ((lbl_801A6A10 == 0) && (lbl_801A6A14 == 0)) {
        __ARQPopTaskQueueHi();
        if (lbl_801A6A10 == 0) {
            __ARQServiceQueueLo();
        }
    }
    OSRestoreInterrupts(enabled);
}
