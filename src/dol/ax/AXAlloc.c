#include "types.h"

typedef struct AXVPBNode AXVPBNode;
struct AXVPBNode {
    AXVPBNode *next;
    AXVPBNode *prev;
    u32 unk_8;
    u32 index;
    u32 unk_10;
    u32 unk_14;
    u8 pad_18[0x8];
    u32 unk_20;
    u8 pad_24[0x122];
    u16 unk_146;
};

struct AXAllocBlock {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3C;
};

struct AXAllocStack {
    AXVPBNode *head[32];
    AXVPBNode *tail[32];
};

extern AXVPBNode *lbl_8015D100[32];
extern AXVPBNode *lbl_8015D180[32];
extern u32 lbl_801A6AB8;
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);
extern void fn_80022E68(AXVPBNode *);

void fn_80020874(void) {
    struct AXAllocBlock *tail = (struct AXAllocBlock *)lbl_8015D180;
    struct AXAllocBlock *head = (struct AXAllocBlock *)lbl_8015D100;
    u32 i;

    lbl_801A6AB8 = 0;
    for (i = 0; i < 2; i++) {
        tail[i].unk_0 = 0;
        head[i].unk_0 = 0;
        tail[i].unk_4 = 0;
        head[i].unk_4 = 0;
        tail[i].unk_8 = 0;
        head[i].unk_8 = 0;
        tail[i].unk_C = 0;
        head[i].unk_C = 0;
        tail[i].unk_10 = 0;
        head[i].unk_10 = 0;
        tail[i].unk_14 = 0;
        head[i].unk_14 = 0;
        tail[i].unk_18 = 0;
        head[i].unk_18 = 0;
        tail[i].unk_1C = 0;
        head[i].unk_1C = 0;
        tail[i].unk_20 = 0;
        head[i].unk_20 = 0;
        tail[i].unk_24 = 0;
        head[i].unk_24 = 0;
        tail[i].unk_28 = 0;
        head[i].unk_28 = 0;
        tail[i].unk_2C = 0;
        head[i].unk_2C = 0;
        tail[i].unk_30 = 0;
        head[i].unk_30 = 0;
        tail[i].unk_34 = 0;
        head[i].unk_34 = 0;
        tail[i].unk_38 = 0;
        head[i].unk_38 = 0;
        tail[i].unk_3C = 0;
        head[i].unk_3C = 0;
    }
}

void fn_80020928(void) {
    struct AXAllocBlock *tail = (struct AXAllocBlock *)lbl_8015D180;
    struct AXAllocBlock *head = (struct AXAllocBlock *)lbl_8015D100;
    u32 i;

    lbl_801A6AB8 = 0;
    for (i = 0; i < 2; i++) {
        tail[i].unk_0 = 0;
        head[i].unk_0 = 0;
        tail[i].unk_4 = 0;
        head[i].unk_4 = 0;
        tail[i].unk_8 = 0;
        head[i].unk_8 = 0;
        tail[i].unk_C = 0;
        head[i].unk_C = 0;
        tail[i].unk_10 = 0;
        head[i].unk_10 = 0;
        tail[i].unk_14 = 0;
        head[i].unk_14 = 0;
        tail[i].unk_18 = 0;
        head[i].unk_18 = 0;
        tail[i].unk_1C = 0;
        head[i].unk_1C = 0;
        tail[i].unk_20 = 0;
        head[i].unk_20 = 0;
        tail[i].unk_24 = 0;
        head[i].unk_24 = 0;
        tail[i].unk_28 = 0;
        head[i].unk_28 = 0;
        tail[i].unk_2C = 0;
        head[i].unk_2C = 0;
        tail[i].unk_30 = 0;
        head[i].unk_30 = 0;
        tail[i].unk_34 = 0;
        head[i].unk_34 = 0;
        tail[i].unk_38 = 0;
        head[i].unk_38 = 0;
        tail[i].unk_3C = 0;
        head[i].unk_3C = 0;
    }
}

void fn_800209DC(AXVPBNode *arg0) {
    arg0->next = lbl_8015D100[0];
    lbl_8015D100[0] = arg0;
    arg0->index = 0;
}

void fn_800209FC(AXVPBNode *arg0) {
    arg0->unk_8 = lbl_801A6AB8;
    lbl_801A6AB8 = (u32)arg0;
}

u32 fn_80020A0C(u32 arg0) {
    u32 ptr;

    ptr = lbl_801A6AB8;
    if (ptr == 0) {
        return ptr;
    }
    lbl_801A6AB8 = *(u32 *)(ptr + 8);
    return ptr;
}

u32 fn_80020A28(AXVPBNode *arg0) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;

    v0 = arg0->index;
    v1 = *(u32 *)(((u8 *)&lbl_8015D100 + (v0 << 2)));
    v2 = *(u32 *)(((u8 *)&lbl_8015D180 + (v0 << 2)));
    if (v1 == v2) {
        *(u32 *)((u8 *)((u8 *)&lbl_8015D180 + (v0 << 2)) + 0) = 0;
        *(u32 *)((u8 *)((u8 *)&lbl_8015D100 + (v0 << 2)) + 0) = 0;
        return (u32)arg0;
    }
    if ((u32)arg0 == v1) {
        v3 = *(u32 *)(arg0);
        *(u32 *)((u8 *)((u8 *)&lbl_8015D100 + (v0 << 2)) + 0) = v3;
        v3 = *(u32 *)(((u8 *)&lbl_8015D100 + (v0 << 2)));
        *(u32 *)((u8 *)v3 + 4) = 0;
        return v3;
    }
    if ((u32)arg0 == v2) {
        v3 = *(u32 *)((u8 *)arg0 + 4);
        *(u32 *)((u8 *)((u8 *)&lbl_8015D180 + (v0 << 2)) + 0) = v3;
        v3 = *(u32 *)(((u8 *)&lbl_8015D180 + (v0 << 2)));
        *(u32 *)((u8 *)v3 + 0) = 0;
        return v3;
    }
    v4 = *(u32 *)((u8 *)arg0 + 4);
    arg0 = (AXVPBNode *)*(u32 *)(arg0);
    *(u32 *)((u8 *)v4 + 0) = (u32)arg0;
    *(u32 *)((u8 *)arg0 + 4) = v4;
    return (u32)arg0;
}

void fn_80020ABC(AXVPBNode *arg0) {
    BOOL v0;
    AXVPBNode *v1;
    v0 = OSDisableInterrupts();
    fn_80020A28(arg0);
    if (arg0->unk_146 == 1) {
        arg0->unk_20 = 1;
    }
    fn_80022E68(arg0);
    v1 = lbl_8015D100[0];
    arg0->next = v1;
    lbl_8015D100[0] = arg0;
    arg0->index = 0;
    OSRestoreInterrupts(v0);
}

static inline AXVPBNode **fn_80020B3C_array_read(AXVPBNode **array) { return array; }
#pragma opt_common_subs off
u32 fn_80020B3C(u32 arg0, u32 arg1, u32 arg2) {
    AXVPBNode *node;
    struct AXAllocStack *p;
    AXVPBNode *a;
    AXVPBNode *r;
    AXVPBNode **hp;
    AXVPBNode **tp;
    AXVPBNode *b;
    AXVPBNode **slot;
    u32 idx;
    u32 i;
    BOOL irq;

    idx = arg0;
    p = (struct AXAllocStack *)lbl_8015D100;
    irq = OSDisableInterrupts();
    r = fn_80020B3C_array_read(p->head)[0];
    if (r != 0) {
        p->head[0] = r->next;
    }
    node = r;
    if (node == 0) {
        hp = &p->head[1];
        tp = &p->tail[1];
        for (i = 1; i < idx; i++) {
            a = *hp;
            r = 0;
            if (a != 0) {
                b = *tp;
                if (a == b) {
                    r = a;
                    *tp = 0;
                    *hp = 0;
                } else if (b != 0) {
                    r = b;
                    *tp = b->prev;
                    (*tp)->next = 0;
                }
            }
            node = r;
            if (r != 0) {
                if (r->unk_146 == 1) {
                    r->unk_20 = 1;
                }
                if (r->unk_10 != 0) {
                    ((void (*)(AXVPBNode *))r->unk_10)(node);
                }
                break;
            }
            hp++;
            tp++;
        }
    }
    if (node != 0) {
        slot = &p->head[idx];
        (void) slot;  /* fzgx: keeps the web at its definition */
        node->next = *slot;
        node->prev = 0;
        if (node->next != 0) {
            (*slot)->prev = node;
            *slot = node;
        } else {
            p->tail[idx] = node;
            *slot = node;
        }
        node->index = idx;
        node->unk_10 = arg1;
        node->unk_14 = arg2;
        fn_80022E68(node);
    }
    OSRestoreInterrupts(irq);
    return (u32)node;
}
#pragma opt_common_subs reset

void fn_80020CB0(AXVPBNode *arg0, u32 arg1) {
    BOOL v0;
    AXVPBNode **slot;

    v0 = OSDisableInterrupts();
    fn_80020A28(arg0);
    slot = &lbl_8015D100[arg1];
    arg0->next = *slot;
    arg0->prev = 0;
    if (arg0->next != 0) {
        (*slot)->prev = arg0;
        *slot = arg0;
    } else {
        lbl_8015D180[arg1] = arg0;
        *slot = arg0;
    }
    arg0->index = arg1;
    OSRestoreInterrupts(v0);
}
