/* Non-matching: best partial attempt (83.61% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct Block {
    void *prev;
    void *next;
    u32 size;
};

struct FreeList {
    u32 unk0;
    void *next;
    void *prev;
};

struct Save {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    u32 e;
};

extern u32 lbl_801A6730;
extern u32 lbl_8015BE40[40];
extern struct Save lbl_8015BEE0;
extern u32 lbl_801A6410;
extern u32 lbl_801A6744;
extern u32 lbl_801A6740;
extern u32 lbl_801A673C;
extern u32 lbl_801A6738;

s32 fn_80009CD4(void *arg0, u32 arg1, void *arg2, u32 arg3) {
    u32 v0 = lbl_801A6410;
    struct FreeList *list;
    struct Block *block;
    struct Block *node;
    void *head;
    struct Block *next;
    struct Block *prev;
    u32 size;
    u32 tail;
    u32 split;

    if ((s32)lbl_801A6730 != -1) {
        lbl_8015BEE0.a = lbl_801A6410;
        lbl_8015BEE0.b = lbl_801A6744;
        lbl_8015BEE0.c = lbl_801A6740;
        lbl_8015BEE0.d = lbl_801A673C;
        lbl_8015BEE0.e = lbl_801A6738;
        lbl_801A6410 = lbl_8015BE40[lbl_801A6730 * 5];
        lbl_801A6744 = lbl_8015BE40[lbl_801A6730 * 5 + 1];
        lbl_801A6740 = lbl_8015BE40[lbl_801A6730 * 5 + 2];
        lbl_801A673C = lbl_8015BE40[lbl_801A6730 * 5 + 3];
        lbl_801A6738 = lbl_8015BE40[lbl_801A6730 * 5 + 4];
    }

    list = (struct FreeList *)(lbl_801A6744 + v0 * 12);
    block = (struct Block *)((u8 *)arg0 - 0x20);
    size = block->size;
    tail = (u32)block + size;
    node = (struct Block *)list->next;

    while (node != 0) {
        if ((u32)node == tail) {
            break;
        }
        node = (struct Block *)node->next;
    }

    if (node == 0 && size <= arg1 + 0x40) {
        return 0;
    }

    if (block->next != 0) {
        ((struct Block *)block->next)->prev = block->prev;
    }
    if (block->prev != 0) {
        ((struct Block *)block->prev)->next = block->next;
    } else {
        list->prev = block->next;
    }

    prev = 0;
    head = list->next;
    next = (struct Block *)head;
    while (next != 0 && (u32)block > (u32)next) {
        prev = next;
        next = (struct Block *)next->next;
    }

    block->next = next;
    block->prev = prev;

    if (next != 0) {
        next->prev = block;
        if ((u32)block + block->size == (u32)next) {
            block->size += next->size;
            next = (struct Block *)next->next;
            block->next = next;
            if (next != 0) {
                next->prev = block;
            }
        }
    }

    if (prev != 0) {
        prev->next = block;
        if ((u32)prev + prev->size == (u32)block) {
            prev->size += block->size;
            prev->next = next;
            if (next != 0) {
                next->prev = prev;
            }
        }
    } else {
        head = block;
    }

    list->next = head;

    split = (arg1 + 0x3F) & ~0x1F;
    next = (struct Block *)((u8 *)block + split);
    next->size = block->size - split;
    block->size = split;
    next->prev = block->prev;
    next->next = block->next;

    if (next->next != 0) {
        ((struct Block *)next->next)->prev = next;
    } else {
        list->next = next;
    }
    if (next->prev != 0) {
        ((struct Block *)next->prev)->next = next;
    }

    block->next = list->prev;
    block->prev = 0;
    if (block->next != 0) {
        ((struct Block *)block->next)->prev = block;
    }
    list->prev = block;

    if ((s32)lbl_801A6730 != -1) {
        lbl_8015BE40[lbl_801A6730 * 5] = lbl_801A6410;
        lbl_8015BE40[lbl_801A6730 * 5 + 1] = lbl_801A6744;
        lbl_8015BE40[lbl_801A6730 * 5 + 2] = lbl_801A6740;
        lbl_8015BE40[lbl_801A6730 * 5 + 3] = lbl_801A673C;
        lbl_8015BE40[lbl_801A6730 * 5 + 4] = lbl_801A6738;
        lbl_801A6410 = lbl_8015BEE0.a;
        lbl_801A6744 = lbl_8015BEE0.b;
        lbl_801A6740 = lbl_8015BEE0.c;
        lbl_801A673C = lbl_8015BEE0.d;
        lbl_801A6738 = lbl_8015BEE0.e;
    }

    return -(s32)(size - split);
}
