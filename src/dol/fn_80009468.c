#include "types.h"


/* --- dol/fn_80009468.c --- */
/* --- dol/fn_80009468.c --- */
extern u32 lbl_8015BE40[40];
extern u32 lbl_801A6730;

void fn_80009468(void) {
    s32 i;

    for (i = 0; i < 40; i += 5) {
        lbl_8015BE40[i] = -1;
        lbl_8015BE40[i + 1] = 0;
        lbl_8015BE40[i + 2] = 0;
        lbl_8015BE40[i + 3] = 0;
        lbl_8015BE40[i + 4] = 0;
    }
    lbl_801A6730 = -1;
}

/* --- dol/fn_8000951C.c --- */
extern u32 lbl_8015BEE0[8];
extern u32 lbl_801A6410;
extern u32 lbl_801A6744;
extern u32 lbl_801A6740;
extern u32 lbl_801A673C;
extern u32 lbl_801A6738;

void fn_8000951C(u32 arg0) {
    if ((s32)lbl_801A6730 != -1) {
        lbl_8015BEE0[0] = lbl_801A6410;
        lbl_8015BEE0[1] = lbl_801A6744;
        lbl_8015BEE0[2] = lbl_801A6740;
        lbl_8015BEE0[3] = lbl_801A673C;
        lbl_8015BEE0[4] = lbl_801A6738;
        lbl_801A6410 = lbl_8015BE40[lbl_801A6730 * 5];
        lbl_801A6744 = lbl_8015BE40[lbl_801A6730 * 5 + 1];
        lbl_801A6740 = lbl_8015BE40[lbl_801A6730 * 5 + 2];
        lbl_801A673C = lbl_8015BE40[lbl_801A6730 * 5 + 3];
        lbl_801A6738 = lbl_8015BE40[lbl_801A6730 * 5 + 4];
    }
}

/* --- dol/fn_800095A4.c --- */
void fn_800095A4(void) {
    if ((s32)lbl_801A6730 != -1) {
        lbl_8015BE40[lbl_801A6730 * 5] = lbl_801A6410;
        lbl_8015BE40[lbl_801A6730 * 5 + 1] = lbl_801A6744;
        lbl_8015BE40[lbl_801A6730 * 5 + 2] = lbl_801A6740;
        lbl_8015BE40[lbl_801A6730 * 5 + 3] = lbl_801A673C;
        lbl_8015BE40[lbl_801A6730 * 5 + 4] = lbl_801A6738;
        lbl_801A6410 = lbl_8015BEE0[0];
        lbl_801A6744 = lbl_8015BEE0[1];
        lbl_801A6740 = lbl_8015BEE0[2];
        lbl_801A673C = lbl_8015BEE0[3];
        lbl_801A6738 = lbl_8015BEE0[4];
    }
}

/* --- dol/fn_8000961C.c --- */
s32 *fn_8000961C(s32 arg0) {
    s32 idx;
    s32 v0, v1, v2, v3, v4;
    s32 *p;

    idx = lbl_801A6730;
    if (idx != -1) {
        v0 = lbl_801A6410;
        v1 = lbl_801A6744;
        v2 = lbl_801A6740;
        v3 = lbl_801A673C;
        v4 = lbl_801A6738;
        lbl_8015BEE0[0] = v0;
        lbl_8015BEE0[1] = v1;
        lbl_8015BEE0[2] = v2;
        lbl_8015BEE0[3] = v3;
        lbl_8015BEE0[4] = v4;
        lbl_801A6410 = lbl_8015BE40[idx * 5];
        lbl_801A6744 = lbl_8015BE40[idx * 5 + 1];
        lbl_801A6740 = lbl_8015BE40[idx * 5 + 2];
        lbl_801A673C = lbl_8015BE40[idx * 5 + 3];
        lbl_801A6738 = lbl_8015BE40[idx * 5 + 4];
    }
    if (arg0 < 0 || arg0 >= (s32)lbl_801A6740) {
        if (idx != -1) {
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
        return 0;
    }
    p = (s32 *)(lbl_801A6744 + arg0 * 12);
    if (*p < 0) {
        if (idx != -1) {
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
        return 0;
    }
    if (idx != -1) {
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
    return p;
}

/* --- dol/fn_80009830.c --- */
/* --- dol/fn_80009830.c --- */

typedef struct Node {
    struct Node *f0;
    struct Node *f4;
    s32 f8;
} Node;

void *fn_80009830(s32 arg0, s32 arg1) {
    struct Node * fzgx_value;
    struct Node * fzgx_live;
    s32 idx;
    Node *cur;
    Node *nxt;
    Node *prev;
    Node *q;
    Node *t;
    s32 key;
    s32 d;

    if ((s32)lbl_801A6730 != -1) {
        idx = lbl_801A6730;
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

    {
    Node *head;
    Node *first;
    arg0 = arg0 * 12;
    head = (Node *)(lbl_801A6744 + arg0);
    key = (arg1 + 0x3F) & 0xFFFFFFE0;
    first = head->f4;
    for (cur = first; cur != NULL; cur = cur->f4) {
        if (key <= cur->f8) {
            break;
        }
    }

    if (cur == NULL) {
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
        return NULL;
    }

    d = cur->f8 - key;

    if ((u32)d < 0x40) {
        t = cur->f4;
        if (t != NULL) {
            t->f0 = cur->f0;
        }
        nxt = cur->f0;
        if (nxt == NULL) {
            first = cur->f4;
        } else {
            nxt->f4 = cur->f4;
        }
        head->f4 = first;
    } else {
        cur->f8 = key;
        q = (Node *)((u8 *)cur + key);
        q->f8 = d;
        q->f0 = cur->f0;
        fzgx_live = cur->f4;
        q->f4 = fzgx_live;
        prev = q->f4;
        if (prev != NULL) {
            prev->f0 = q;
        }
        nxt = q->f0;
        if (nxt != NULL) {
            nxt->f4 = q;
        } else {
            head->f4 = q;
        }
    }

    prev = (Node *)head->f8;
    fzgx_value = prev;
    cur->f4 = fzgx_value;
    cur->f0 = NULL;
    if (prev != NULL) {
        prev->f0 = cur;
    }
    head->f8 = (s32)cur;
}

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

    return (u8 *)cur + 0x20;
}

/* --- dol/fn_80009AA8.c --- */
/* --- dol/fn_80009AA8.c --- */

typedef struct Node_u1 {
    struct Node_u1 *prev;
    struct Node_u1 *next;
    u32 size;
} Node_u1;

typedef struct Pool {
    u32 pad;
    Node_u1 *head;
    Node_u1 *tail;
} Pool;

void fn_80009AA8(s32 arg0, s32 arg1) {
    Node_u1 *cur;
    Node_u1 *prev;
    Node_u1 *head;
    struct { Node_u1 * value; } tail;
    Pool *pool;
    Node_u1 *node;
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

    node = (Node_u1 *)(arg1 - 0x20);
    pool = (Pool *)(lbl_801A6744 + arg0 * 0xC);
    tail.value = (Node_u1 *)(pool->tail);

    if (node->next != 0) {
        node->next->prev = node->prev;
    }
    if (node->prev == 0) {
        tail.value = (Node_u1 *)(node->next);
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
