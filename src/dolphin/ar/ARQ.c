// provenance: original
typedef signed int s32;
typedef unsigned int u32;
typedef int BOOL;

typedef void (*ARQCallback)(void);
typedef struct ARQRequest ARQRequest;
typedef struct ARQReq {
    struct ARQReq* next;   /* 0x00 */
    u32 owner;             /* 0x04 */
    u32 type;              /* 0x08 */
    u32 unk0C;             /* 0x0c */
    u32 source;            /* 0x10 */
    u32 dest;              /* 0x14 */
    u32 length;            /* 0x18 */
    void (*callback)(u32); /* 0x1c */
} ARQReq;


extern void OSRegisterVersion(const char* version);
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern void ARStartDMA(register u32 dir, register u32 memaddr, register u32 aramaddr, register u32 length);
extern ARQCallback ARRegisterDMACallback(register ARQCallback callback);

#pragma push
#pragma force_active on

extern char* lbl_801A64E0;
extern ARQReq* lbl_801A6A00;
extern ARQReq* lbl_801A6A04;
extern ARQReq* lbl_801A6A08;
extern ARQReq* lbl_801A6A0C;
extern ARQReq* lbl_801A6A10;
extern ARQReq* lbl_801A6A14;
extern void (*lbl_801A6A18)(u32);
extern void (*lbl_801A6A1C)(u32);
extern u32 lbl_801A6A20;
extern s32 lbl_801A6A24;
// provenance: original
void __ARQServiceQueueLo(void) {
    if (lbl_801A6A14 == 0 && lbl_801A6A08 != 0) {
        lbl_801A6A14 = lbl_801A6A08;
        lbl_801A6A08 = lbl_801A6A08->next;
    }
    if (lbl_801A6A14 != 0) {
        if (lbl_801A6A14->length <= lbl_801A6A20) {
            if (lbl_801A6A14->type == 0) {
                ARStartDMA(lbl_801A6A14->type, lbl_801A6A14->source, lbl_801A6A14->dest, lbl_801A6A14->length);
            } else {
                ARStartDMA(lbl_801A6A14->type, lbl_801A6A14->dest, lbl_801A6A14->source, lbl_801A6A14->length);
            }
            lbl_801A6A1C = lbl_801A6A14->callback;
        } else if (lbl_801A6A14->type == 0) {
            ARStartDMA(lbl_801A6A14->type, lbl_801A6A14->source, lbl_801A6A14->dest, lbl_801A6A20);
        } else {
            ARStartDMA(lbl_801A6A14->type, lbl_801A6A14->dest, lbl_801A6A14->source, lbl_801A6A20);
        }
        lbl_801A6A14->length -= lbl_801A6A20;
        lbl_801A6A14->source += lbl_801A6A20;
        lbl_801A6A14->dest += lbl_801A6A20;
    }
}

// provenance: original
void __ARQCallbackHack(u32 result) {
}

// provenance: dolsdk2001:src/ar/arq.c:60 (adapted; pop-task-queue-hi inlined per retail)
void __ARQInterruptServiceRoutine(void) {
    if (lbl_801A6A18) {
        lbl_801A6A18((u32)lbl_801A6A10);
        lbl_801A6A10 = 0;
        lbl_801A6A18 = 0;
    } else if (lbl_801A6A1C) {
        lbl_801A6A1C((u32)lbl_801A6A14);
        lbl_801A6A14 = 0;
        lbl_801A6A1C = 0;
    }
    if (lbl_801A6A00) {
        if (lbl_801A6A00->type == 0) {
            ARStartDMA(lbl_801A6A00->type, lbl_801A6A00->source, lbl_801A6A00->dest, lbl_801A6A00->length);
        } else {
            ARStartDMA(lbl_801A6A00->type, lbl_801A6A00->dest, lbl_801A6A00->source, lbl_801A6A00->length);
        }
        lbl_801A6A18 = lbl_801A6A00->callback;
        lbl_801A6A10 = lbl_801A6A00;
        lbl_801A6A00 = lbl_801A6A00->next;
    }
    if (lbl_801A6A10 == 0) {
        __ARQServiceQueueLo();
    }
}

// provenance: dolsdk2001:src/ar/arq.c:91 (adapted: OSRegisterVersion kept, GFZE01 globals)
void ARQInit(void) {
    if (lbl_801A6A24 != 1) {
        OSRegisterVersion(lbl_801A64E0);
        lbl_801A6A08 = 0;
        lbl_801A6A00 = 0;
        lbl_801A6A20 = 0x1000;
        ARRegisterDMACallback(__ARQInterruptServiceRoutine);
        lbl_801A6A10 = 0;
        lbl_801A6A14 = 0;
        lbl_801A6A18 = 0;
        lbl_801A6A1C = 0;
        lbl_801A6A24 = 1;
    }
}

// provenance: dolsdk2001:src/ar/arq.c:108 (adapted; asserts absent in retail)
void ARQPostRequest(register ARQReq* request, register u32 owner, register u32 type, register u32 priority,
                    register u32 source, register u32 dest, register u32 length, register void (*callback)(u32)) {
    int level;
    request->next = 0;
    request->owner = owner;
    request->type = type;
    request->source = source;
    request->dest = dest;
    request->length = length;
    if (callback) {
        request->callback = callback;
    } else {
        request->callback = __ARQCallbackHack;
    }
    level = OSDisableInterrupts();
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
    if (lbl_801A6A10 == 0 && lbl_801A6A14 == 0) {
        if (lbl_801A6A00) {
            if (lbl_801A6A00->type == 0) {
                ARStartDMA(lbl_801A6A00->type, lbl_801A6A00->source, lbl_801A6A00->dest, lbl_801A6A00->length);
            } else {
                ARStartDMA(lbl_801A6A00->type, lbl_801A6A00->dest, lbl_801A6A00->source, lbl_801A6A00->length);
            }
            lbl_801A6A18 = lbl_801A6A00->callback;
            lbl_801A6A10 = lbl_801A6A00;
            lbl_801A6A00 = lbl_801A6A00->next;
        }
        if (lbl_801A6A10 == 0) {
            __ARQServiceQueueLo();
        }
    }
    OSRestoreInterrupts(level);
}

// provenance: dolsdk2001:src/ar/arq.c:222 (register-temp form; exact standalone)
void ARQSetChunkSize(register u32 size) {
    register u32 m = size & 0x1F;
    if (m != 0) {
        lbl_801A6A20 = size + (0x20 - m);
    } else {
        lbl_801A6A20 = size;
    }
}

// provenance: original
u32 ARQGetChunkSize(void) {
    return lbl_801A6A20;
}

#pragma pop
