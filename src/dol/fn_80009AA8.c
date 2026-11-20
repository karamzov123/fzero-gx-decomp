#include "types.h"


/* --- dol/fn_80009AA8.c --- */
extern u32 lbl_801A6730;
extern u32 lbl_8015BE40[40];
extern u32 lbl_8015BEE0[8];
extern u32 lbl_801A6410;
extern u32 lbl_801A6744;
extern u32 lbl_801A6740;
extern u32 lbl_801A673C;
extern u32 lbl_801A6738;

typedef struct Node {
    struct Node *prev;
    struct Node *next;
    u32 size;
} Node;

typedef struct Pool {
    u32 pad;
    Node *head;
    Node *tail;
} Pool;

void fn_80009AA8(s32 arg0, s32 arg1) {
    Node *cur;
    Node *prev;
    Node *head;
    struct { Node * value; } tail;
    Pool *pool;
    Node *node;
    u32 idx;
    u32 off;

    if ((s32)lbl_801A6730 != -1) {
        idx = lbl_801A6730;
        off = idx * 0x14;
        lbl_8015BEE0[0] = lbl_801A6410;
        lbl_8015BEE0[1] = lbl_801A6744;
        lbl_8015BEE0[2] = lbl_801A6740;
        lbl_8015BEE0[3] = lbl_801A673C;
        lbl_8015BEE0[4] = lbl_801A6738;
        lbl_801A6410 = lbl_8015BE40[idx * 5];
        lbl_801A6744 = lbl_8015BE40[idx * 5 + 1];
        lbl_801A6740 = lbl_8015BE40[idx * 5 + 2];
        lbl_801A673C = lbl_8015BE40[idx * 5 + 3];
        lbl_801A6738 = lbl_8015BE40[idx * 5 + 4];
    }

    node = (Node *)(arg1 - 0x20);
    pool = (Pool *)(lbl_801A6744 + arg0 * 0xC);
    tail.value = (Node *)(pool->tail);

    if (node->next != 0) {
        node->next->prev = node->prev;
    }
    if (node->prev == 0) {
        tail.value = (Node *)(node->next);
    } else {
        node->prev->next = node->next;
    }
    pool->tail = tail.value;

    prev = 0;
    head = pool->head;
    cur = head;
    while (cur != 0) {
        if (node <= cur) {
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    node->next = cur;
    node->prev = prev;
    if (cur != 0) {
        cur->prev = node;
        if ((u8 *)node + node->size == (u8 *)cur) {
            node->size = node->size + cur->size;
            cur = cur->next;
            node->next = cur;
            if (cur != 0) {
                cur->prev = node;
            }
        }
    }
    if (prev != 0) {
        prev->next = node;
        if ((u8 *)prev + prev->size == (u8 *)node) {
            prev->size = prev->size + node->size;
            prev->next = cur;
            if (cur) {
                cur->prev = prev;
            }
        }
    } else {
        head = node;
    }
    pool->head = head;

    if ((s32)lbl_801A6730 != -1) {
        idx = lbl_801A6730;
        lbl_8015BE40[idx * 5] = lbl_801A6410;
        lbl_8015BE40[idx * 5 + 1] = lbl_801A6744;
        lbl_8015BE40[idx * 5 + 2] = lbl_801A6740;
        lbl_8015BE40[idx * 5 + 3] = lbl_801A673C;
        lbl_8015BE40[idx * 5 + 4] = lbl_801A6738;
        lbl_801A6410 = lbl_8015BEE0[0];
        lbl_801A6744 = lbl_8015BEE0[1];
        lbl_801A6740 = lbl_8015BEE0[2];
        lbl_801A673C = lbl_8015BEE0[3];
        lbl_801A6738 = lbl_8015BEE0[4];
    }
}

/* --- dol/fn_80009CAC.c --- */
extern u32 fn_80009CD4(u32, u32, u32, u32);
extern u32 lbl_801A6414;

void fn_80009CAC(u32 arg0, u32 arg1) {
    fn_80009CD4(arg0, arg1, (u32)&lbl_801A6414, 0);
}
