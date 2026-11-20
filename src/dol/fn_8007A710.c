#include "types.h"


/* --- dol/fn_8007A710.c --- */
typedef struct Block Block;

typedef struct SubBlock SubBlock;

struct Block {
    Block *prev;
    Block *next;
    unsigned long max_size;
    unsigned long size;
};

typedef struct FixBlock FixBlock;

typedef struct FixStart {
    FixBlock *tail;
    FixBlock *head;
} FixStart;

typedef struct MemPoolObj {
    Block *start;
    FixStart fixed[6];
} MemPoolObj;

struct SubBlock {
    unsigned long size;
    Block *block;
    SubBlock *prev;
    SubBlock *next;
};

#define Block_size(bp) ((bp)->size & ~7)
#define Block_start(bp) (*(SubBlock **)((char *)(bp) + Block_size(bp) - sizeof(unsigned long)))
#define SubBlock_size(sb) ((sb)->size & ~7)
#define SubBlock_block(sb) ((Block *)((unsigned long)(sb)->block & ~1))
#define SubBlock_is_free(sb) (!((sb)->size & 2))
#define SubBlock_is_prev_allocated(sb) ((sb)->size & 4)

#define SubBlock_set_size(sb, sz)                                                     \
    (sb)->size &= 7;                                                                  \
    (sb)->size |= (sz) & ~7;                                                          \
    if (SubBlock_is_free(sb)) {                                                       \
        *(unsigned long *)((char *)(sb) + (sz) - sizeof(unsigned long)) = (sz);      \
    }

static inline void SubBlock_set_free(SubBlock *sb) {
    unsigned long this_size = SubBlock_size(sb);

    sb->size &= ~2;
    *(unsigned long *)((char *)sb + this_size) &= ~4;
    *(unsigned long *)((char *)sb + this_size - sizeof(unsigned long)) = this_size;
}

static inline SubBlock *SubBlock_merge_prev(SubBlock *sb, SubBlock **start) {
    unsigned long prev_size;
    SubBlock *prev;

    if (!SubBlock_is_prev_allocated(sb)) {
        prev_size = *(unsigned long *)((char *)sb - sizeof(unsigned long));
        if (prev_size & 2) {
            return sb;
        }
        prev = (SubBlock *)((char *)sb - prev_size);
        SubBlock_set_size(prev, prev_size + SubBlock_size(sb));
        if (*start == sb) {
            *start = (*start)->next;
        }
        sb->next->prev = sb->prev;
        sb->next->prev->next = sb->next;
        return prev;
    }
    return sb;
}

static inline void SubBlock_merge_next(SubBlock *sb, SubBlock **start) {
    SubBlock *next;
    unsigned long this_size;

    next = (SubBlock *)((char *)sb + SubBlock_size(sb));
    if (SubBlock_is_free(next)) {
        this_size = SubBlock_size(sb) + SubBlock_size(next);
        SubBlock_set_size(sb, this_size);
        if (SubBlock_is_free(sb)) {
            *(unsigned long *)((char *)sb + this_size) &= ~4;
        } else {
            *(unsigned long *)((char *)sb + this_size) |= 4;
        }
        if (*start == next) {
            *start = (*start)->next;
        }
        if (*start == next) {
            *start = NULL;
        }
        next->next->prev = next->prev;
        next->prev->next = next->next;
    }
}

static inline void Block_link(Block *bp, SubBlock *sb) {
    SubBlock **start;

    SubBlock_set_free(sb);
    start = &Block_start(bp);
    if (*start != NULL) {
        sb->prev = (*start)->prev;
        sb->prev->next = sb;
        sb->next = *start;
        (*start)->prev = sb;
        *start = sb;
        *start = SubBlock_merge_prev(*start, start);
        SubBlock_merge_next(*start, start);
    } else {
        *start = sb;
        sb->prev = sb;
        sb->next = sb;
    }
    if (bp->max_size < SubBlock_size(*start)) {
        bp->max_size = SubBlock_size(*start);
    }
}

static inline int Block_empty(Block *bp) {
    SubBlock *sb = (SubBlock *)((char *)bp + sizeof(Block));

    return SubBlock_is_free(sb) && SubBlock_size(sb) == Block_size(bp) - 0x18;
}

extern void fn_80079EF0(Block *);

void fn_8007A710(MemPoolObj *pool, void *ptr) {
    SubBlock *sb = (SubBlock *)((char *)ptr - 8);
    Block *bp = SubBlock_block(sb);
    Block *next;

    Block_link(bp, sb);
    if (Block_empty(bp)) {
        next = bp->next;
        if (next == bp) {
            next = NULL;
        }
        if (pool->start == bp) {
            pool->start = next;
        }
        if (next != NULL) {
            next->prev = bp->prev;
            next->prev->next = next;
        }
        bp->next = NULL;
        bp->prev = NULL;
        fn_80079EF0(bp);
    }
}

/* --- dol/fn_8007A9A4.c --- */
typedef struct Node {
    u32 pad0;
    struct Node *next;
    u32 size;
} Node;

extern u32 fn_8007AC0C(Node *, u32);

u32 fn_8007A9A4(Node **head, u32 size, u32 *remaining) {
    Node *node;
    u32 result;

    size = (size + 15) & ~7;
    if (size < 0x50) {
        size = 0x50;
    }
    *remaining = 0;
    node = *head;
    if (node == 0) {
        return 0;
    }
    do {
        if (size <= node->size) {
            result = fn_8007AC0C(node, size);
            if (result != 0) {
                *head = node;
                /* both exits leave through the single return below */
                goto found;
            }
        }
        if (node->size > 8 && *remaining < node->size - 8) {
            *remaining = node->size - 8;
        }
        node = node->next;
    } while (node != *head);
    return 0;
found:
    return result + 8;
}
