#include <types.h>
#include <dolphin/os/OSInterrupt.h>
#include "types.h"


/* --- dol/ARQPostRequest.c --- */
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

extern ARQRequest *lbl_801A6A00;

extern ARQRequest *lbl_801A6A04;

extern ARQRequest *lbl_801A6A08;

extern ARQRequest *lbl_801A6A0C;

extern ARQRequest *lbl_801A6A10;

extern ARQRequest *lbl_801A6A14;

extern ARQCallback lbl_801A6A18;

void __ARQPopTaskQueueHi(void);

void __ARQServiceQueueLo(void);

void fn_80020460(void);

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

void ARQPostRequest(ARQRequest *request, u32 owner, u32 type, u32 priority, u32 source, u32 dest,
                 u32 length, ARQCallback callback);

/* --- dol/fn_800206FC.c --- */
/* --- dol/fn_800206FC.c --- */
extern u32 lbl_801A6A20;

u32 fn_800206FC(u32 arg0) {
    u32 v0;
    if ((arg0 & 0x1F) != 0) {
    v0 = (arg0 + (32 - (arg0 & 0x1F)));
    lbl_801A6A20 = v0;
    return arg0;
    }
    lbl_801A6A20 = arg0;
}

/* --- dol/fn_8002071C.c --- */
/* --- dol/fn_8002071C.c --- */

u32 fn_8002071C(void) {
    return lbl_801A6A20;
}

/* --- dol/fn_80020724.c --- */
extern u8 lbl_801A6AB0[8];
extern u8 lbl_801A6AA8[8];
extern u8 lbl_801A6AA0[8];
extern u8 lbl_801A6A98[8];
extern u8 lbl_801A6A90[8];
extern u8 lbl_801A6A88[8];
extern u8 lbl_801A6A80[8];
extern u8 lbl_801A6A78[8];
extern u8 lbl_801A6A70[8];
extern u8 lbl_801A6A68[8];
extern u8 lbl_801A6A60[8];
extern u8 lbl_801A6A58[8];
extern u8 lbl_801A6A50[8];
extern u8 lbl_801A6A48[8];
extern u8 lbl_801A6A40[8];
extern u8 lbl_801A6A38[8];
extern u8 lbl_801A6A30[8];
extern u8 lbl_801A6A28[8];

void fn_80020724(void) {
    lbl_801A6AB0[0] = 0;
    lbl_801A6AB0[0] = 0;
    lbl_801A6AA8[0] = 0;
    lbl_801A6AA0[0] = 0;
    lbl_801A6A98[0] = 0;
    lbl_801A6A90[0] = 0;
    lbl_801A6A88[0] = 0;
    lbl_801A6A80[0] = 0;
    lbl_801A6A78[0] = 0;
    lbl_801A6A70[0] = 0;
    lbl_801A6A68[0] = 0;
    lbl_801A6A60[0] = 0;
    lbl_801A6A58[0] = 0;
    lbl_801A6A50[0] = 0;
    lbl_801A6A48[0] = 0;
    lbl_801A6A40[0] = 0;
    lbl_801A6A38[0] = 0;
    lbl_801A6A30[0] = 0;
    lbl_801A6A28[0] = 0;
}

/* --- dol/fn_80020778.c --- */
extern u32 OSRegisterVersion(u32);
extern u32 fn_80020874(u32);
extern u32 fn_80020D58(u32);
extern u32 fn_800218EC(u32);
extern u32 fn_80021C7C(u32);
extern u32 fn_80022420(u32);
extern u32 fn_80022EA4(u32);
extern u32 lbl_801A64E8;

u32 fn_80020778(void) {
    u32 t0, t1, t2, t3, t4, t5;
    t0 = OSRegisterVersion(lbl_801A64E8);
    t1 = fn_80020874(t0);
    t2 = fn_80022EA4(t1);
    t3 = fn_80022420(t2);
    t4 = fn_80020D58(t3);
    t5 = fn_800218EC(t4);
    return fn_80021C7C(t5);
}

/* --- dol/fn_800207B4.c --- */
extern void fn_80020928(void);
extern void fn_800230A0(void);
extern void fn_8002244C(void);
extern void fn_80020E3C(void);
extern void fn_80021910(void);
extern void fn_80021FBC(void);

void fn_800207B4(void) {
    fn_80020928();
    fn_800230A0();
    fn_8002244C();
    fn_80020E3C();
    fn_80021910();
    fn_80021FBC();
}

/* --- dol/fn_800207E8.c --- */
extern u32 lbl_8015D100[32];

u32 fn_800207E8(u32 index) {
    return lbl_8015D100[index];
}

/* --- dol/fn_80020800.c --- */
typedef struct Node Node;
struct Node {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    void (*callback)(Node *);
};

extern Node *fn_80020A0C(void);
extern void fn_80020A28(Node *);
extern void fn_800209DC(Node *);

void fn_80020800(void) {
    Node *node;

    node = fn_80020A0C();
    while (node != 0) {
        if (node->unk_0c != 0) {
            if (node->callback != 0) {
                node->callback(node);
            }
            fn_80020A28(node);
            fn_800209DC(node);
        }
        node = fn_80020A0C();
    }
}
