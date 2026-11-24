#include "types.h"

typedef struct Block Block;
typedef struct SubBlock SubBlock;
typedef struct FixBlock FixBlock;

struct Block {
    Block *prev;
    Block *next;
    unsigned long max_size;
    unsigned long size;
};

typedef struct FixSubBlock FixSubBlock;

struct FixBlock {
    FixBlock *prev;
    FixBlock *next;
    unsigned long client_size;
    FixSubBlock *free;
    unsigned long allocated;
};

struct FixSubBlock {
    FixBlock *block;
    FixSubBlock *next;
};

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

static inline void SubBlock_construct(SubBlock *ths, unsigned long size_, Block *bp_, int prev_alloc, int this_alloc) {
    ths->block = (Block *)((unsigned long)bp_ | 0x1);
    ths->size = size_;
    if (prev_alloc) ths->size |= 0x4;
    if (this_alloc) {
        ths->size |= 0x2;
        *(unsigned long *)((char *)ths + size_) |= 0x4;
    } else
        *(unsigned long *)((char *)ths + size_ - sizeof(unsigned long)) = size_;
}

static inline SubBlock *SubBlock_split(SubBlock *ths, unsigned long sz) {
    unsigned long origsize = SubBlock_size(ths);
    int isfree = SubBlock_is_free(ths);
    int isprevalloced = ths->size & 4;
    SubBlock *np = (SubBlock *)((char *)ths + sz);
    Block *bp = SubBlock_block(ths);

    SubBlock_construct(ths, sz, bp, isprevalloced, !isfree);
    SubBlock_construct(np, origsize - sz, bp, !isfree, !isfree);
    if (isfree) {
        np->next = ths->next;
        np->next->prev = np;
        np->prev = ths;
        ths->next = np;
    }
    return np;
}

static inline void Block_unlink(Block *ths, SubBlock *sb) {
    unsigned long this_size;
    unsigned long bsize;

    this_size = SubBlock_size(sb);
    sb->size |= 0x2;
    *(unsigned long *)((char *)sb + this_size) |= 0x4;
    bsize = Block_size(ths);
    if (*(SubBlock **)((char *)ths + bsize - sizeof(unsigned long)) == sb) {
        *(SubBlock **)((char *)ths + bsize - sizeof(unsigned long)) = sb->next;
    }
    if (*(SubBlock **)((char *)ths + bsize - sizeof(unsigned long)) == sb) {
        *(SubBlock **)((char *)ths + bsize - sizeof(unsigned long)) = 0;
        ths->max_size = 0;
    } else {
        sb->next->prev = sb->prev;
        sb->prev->next = sb->next;
    }
}

extern void fn_80079EF0(Block *);
extern u32 fn_80079FA8(u32);

Block *fn_8007AB58(MemPoolObj *pool, u32 arg1);
SubBlock *fn_8007AC0C(Block *ths, unsigned long size);
void fn_8007ADF0(u32 arg0, u32 arg1);

extern void __begin_critical_region(s32);
extern void __end_critical_region(s32);
extern void *memset(void *, int, u32);
extern MemPoolObj lbl_801A3380;
extern u8 lbl_801A6DD8;
extern const unsigned long lbl_80094EC0[];

void deallocate_from_fixed_pools(MemPoolObj *pool, void *ptr, unsigned long size);
void *fn_8007A440(MemPoolObj *pool, unsigned long size);
void fn_8007A710(MemPoolObj *pool, void *ptr);
u32 fn_8007A9A4(Block **head, unsigned long size, unsigned long *remaining);
u32 fn_8007AA7C(MemPoolObj *pool, unsigned long size);
void fn_8007A23C(MemPoolObj *pool, void *ptr);
void *fn_8007A294(MemPoolObj *pool, unsigned long size);

static inline MemPoolObj *AllocPool(void) {
    if (lbl_801A6DD8 == 0) {
        memset(&lbl_801A3380, 0, sizeof(MemPoolObj));
        lbl_801A6DD8 = 1;
    }
    return &lbl_801A3380;
}

void fn_8007A150(void *ptr) {
    __begin_critical_region(1);
    fn_8007A23C(AllocPool(), ptr);
    __end_critical_region(1);
}

void *fn_8007A1C0(unsigned long size) {
    void *result;

    __begin_critical_region(1);
    result = fn_8007A294(AllocPool(), size);
    __end_critical_region(1);
    return result;
}

void fn_8007A23C(MemPoolObj *pool, void *ptr) {
    unsigned long size;

    if (ptr != 0) {
        size = *(unsigned long *)((u8 *)ptr - 4);
        if ((size & 1) == 0) {
            size = ((Block *)size)->max_size;
        } else {
            size = (*(unsigned long *)((u8 *)ptr - 8) & ~7) - 8;
        }
        if (size <= 68) {
            deallocate_from_fixed_pools(pool, ptr, size);
        } else {
            fn_8007A710(pool, ptr);
        }
    }
}

void *fn_8007A294(MemPoolObj *pool, unsigned long size) {
    if (size == 0) {
        return 0;
    }
    if (size > (unsigned long)-49) {
        return 0;
    }
    if (size <= 68) {
        return fn_8007A440(pool, size);
    }
    return (void *)fn_8007AA7C(pool, size);
}

void deallocate_from_fixed_pools(MemPoolObj *pool, void *ptr, unsigned long size) {
    unsigned long index = 0;
    FixSubBlock *subblock;
    FixBlock *block;
    FixStart *start;
    while (size > lbl_80094EC0[index]) {
        index++;
    }
    start = &pool->fixed[index];
    subblock = (FixSubBlock *)((unsigned char *)ptr - 4);
    block = subblock->block;
    if (block->free == ((void *)0) && start->head != block) {
        if (start->tail == block) {
            start->head = start->head->prev;
            start->tail = start->tail->prev;
        } else {
            block->prev->next = block->next;
            block->next->prev = block->prev;
            block->next = start->head;
            block->prev = block->next->prev;
            block->prev->next = block;
            block->next->prev = block;
            start->head = block;
        }
    }
    subblock->next = block->free;
    block->free = subblock;
    if (--block->allocated == 0) {
        if (start->head == block) {
            start->head = block->next;
        }
        if (start->tail == block) {
            start->tail = block->prev;
        }
        block->prev->next = block->next;
        block->next->prev = block->prev;
        if (start->head == block) {
            start->head = ((void *)0);
        }
        if (start->tail == block) {
            start->tail = ((void *)0);
        }
        fn_8007A710(pool, block);
    }
}

static inline void FixBlock_construct(FixBlock *ths, FixBlock *prev, FixBlock *next, unsigned long index, unsigned long size) {
    unsigned long csize = lbl_80094EC0[index];
    unsigned long stride = csize + 4;
    unsigned long n;
    unsigned long i;
    char *p;
    n = (size - 20) / stride;
    p = (char *)ths + 20;
    ths->prev = prev;
    ths->next = next;
    prev->next = ths;
    next->prev = ths;
    ths->client_size = csize;
    for (i = 0; i < n - 1; i++) {
        char *q = p + stride;
        ((FixSubBlock *)p)->block = ths;
        ((FixSubBlock *)p)->next = (FixSubBlock *)q;
        p = q;
    }
    ((FixSubBlock *)p)->block = ths;
    ((FixSubBlock *)p)->next = 0;
    ths->free = (FixSubBlock *)(ths + 1);
    ths->allocated = 0;
}

static inline FixBlock * fn_8007A440_read_pointer(FixStart * owner) { return owner->tail->next; }
static inline FixBlock * fn_8007A440_read_pointer_(FixStart * owner) { return owner->head; }

void *fn_8007A440(MemPoolObj *pool, unsigned long size) {
    FixBlock * *fzgx_value;
    FixBlock * fzgx_live;
    unsigned long i = 0;
    FixStart *fs;
    FixBlock *b;
    FixSubBlock *p;
    while (size > lbl_80094EC0[i]) {
        i++;
    }
    fs = &pool->fixed[i];
    if (fs->head == 0 || fs->head->free == 0) {
        unsigned long n = 4076 / (lbl_80094EC0[i] + 4);
        unsigned long n_used, avail;
        unsigned long bsize;
        if (n > 256) n = 256;
        n_used = n;
        while (n >= 10) {
            b = (FixBlock *)fn_8007A9A4(&pool->start, n * (lbl_80094EC0[i] + 4) + 20, &avail);
            if (b != 0) break;
            if (avail > 20)
                n = (avail - 20) / (lbl_80094EC0[i] + 4);
            else
                n = 0;
        }
        if (b == 0 && n < n_used) {
            b = (FixBlock *)fn_8007AA7C(pool, n_used * (lbl_80094EC0[i] + 4) + 20);
            if (b == 0) return 0;
        }
        bsize = *(unsigned long *)((unsigned char *)b - 4);
        if ((bsize & 1) == 0)
            bsize = ((Block *)bsize)->max_size;
        else
            bsize = (*(unsigned long *)((unsigned char *)b - 8) & ~7) - 8;
        if (fs->head == 0) {
            fs->head = b;
            fzgx_value = &(fs->tail);
            *fzgx_value = b;
        }
        fzgx_live = fn_8007A440_read_pointer_(fs);
        FixBlock_construct(b, fs->tail, fzgx_live, i, bsize);
        fs->head = b;
    }
    fzgx_live = fs->head;
    b = fzgx_live;
    p = b->free;
    b->free = p->next;
    fzgx_live = fs->head;
    fzgx_live->allocated++;
    if (fs->head->free == 0) {
        fzgx_live = fs->head;
        fs->head = fzgx_live->next;
        fs->tail = fn_8007A440_read_pointer(fs);
    }
    return (unsigned char *)p + 4;
}

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

u32 fn_8007A9A4(Block **head, unsigned long size, unsigned long *remaining) {
    Block *node;
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
        if (size <= node->max_size) {
            result = (u32)fn_8007AC0C(node, size);
            if (result != 0) {
                *head = node;
                /* both exits leave through the single return below */
                goto found;
            }
        }
        if (node->max_size > 8 && *remaining < node->max_size - 8) {
            *remaining = node->max_size - 8;
        }
        node = node->next;
    } while (node != *head);
    return 0;
found:
    return result + 8;
}

u32 fn_8007AA7C(MemPoolObj *pool, unsigned long arg1) {
    Block *block;
    u32 size;
    u32 result;

    size = (arg1 + 15) & ~7;
    if (size < 80) {
        size = 80;
    }
    if (pool->start != 0) {
        block = pool->start;
    } else {
        block = fn_8007AB58(pool, size);
    }
    if (block == 0) {
        return 0;
    }
    do {
        if (size <= block->max_size) {
            result = (u32)fn_8007AC0C(block, size);
            if (result != 0) {
                pool->start = block;
                /* both search paths leave through the single return below */
                goto found;
            }
        }
        block = block->next;
    } while (block != pool->start);
    block = fn_8007AB58(pool, size);
    if (block == 0) {
        return 0;
    }
    result = (u32)fn_8007AC0C(block, size);
found:
    return result + 8;
}

Block *fn_8007AB58(MemPoolObj *pool, u32 arg1) {
    u32 arg0 = (u32)pool;
    u32 v2;
    u32 t0;
    u32 v1;
    v1 = (arg1 + 0x1f) & ~0x7;
    if (v1 < 0x10000) {
        v1 = 0x10000;
    }
    t0 = fn_80079FA8(v1);
    v2 = t0;
    if (t0 == 0) {
        v2 = 0;
    } else {
        fn_8007ADF0(v2, v1);
        v2 = *(u32 *)(arg0);
        if (v2 != 0) {
            *(u32 *)((u8 *)t0 + 0) = *(u32 *)((u8 *)v2 + 0);
            v2 = *(u32 *)(t0);
            *(u32 *)((u8 *)v2 + 4) = t0;
            *(u32 *)((u8 *)t0 + 4) = *(u32 *)((u8 *)arg0 + 0);
            v2 = *(u32 *)(arg0);
            *(u32 *)((u8 *)v2 + 0) = t0;
            *(u32 *)((u8 *)arg0 + 0) = t0;
        } else {
            *(u32 *)((u8 *)arg0 + 0) = t0;
            *(u32 *)((u8 *)t0 + 0) = t0;
            *(u32 *)((u8 *)t0 + 4) = t0;
        }
        v2 = t0;
    }
    return (Block *)v2;
}

SubBlock *fn_8007AC0C(Block *ths, unsigned long size) {
    SubBlock *st;
    SubBlock *sb;
    unsigned long sb_size;
    unsigned long max_found;

    st = Block_start(ths);
    if (st == 0) {
        ths->max_size = 0;
        return 0;
    }
    sb = st;
    sb_size = SubBlock_size(sb);
    max_found = sb_size;
    while (sb_size < size) {
        sb = sb->next;
        sb_size = SubBlock_size(sb);
        if (max_found < sb_size) {
            max_found = sb_size;
        }
        if (sb == st) {
            ths->max_size = max_found;
            return 0;
        }
    }
    if (sb_size - size >= 80) {
        SubBlock_split(sb, size);
    }
    Block_start(ths) = sb->next;
    Block_unlink(ths, sb);
    return sb;
}

#pragma opt_propagation off
void fn_8007ADF0(u32 arg0, u32 arg1) {
    u32 total;
    u32 next;
    u32 size;
    u32 previous;
    u32 size_2;
    u32 current;
    u32 off;
    u32 end;
    u32 block;
    block = arg0 + 0x10;
    *(u32 *)(arg0 + 0xc) = arg1 | 3;
    *(u32 *)(arg0 + arg1 - 8) = *(u32 *)(arg0 + 0xc);
    *(u32 *)(arg0 + 0x14) = arg0 | 1;
    *(u32 *)(arg0 + 0x10) = arg1 - 0x18;
    end = ((arg1) + block);
    *(u32 *)(end - 0x1c) = arg1 - 0x18;
    *(u32 *)(arg0 + 8) = arg1 - 0x18;
    *(u32 *)(arg0 + (*(u32 *)(arg0 + 0xc) & ~7) - 4) = 0;
    size = *(u32 *)(0x10 + arg0) & ~7;
    *(u32 *)(arg0 + 0x10) &= ~2;
    {
        u32 end_2;
        end_2 = block + size;
        *(u32 *)end_2 &= ~4;
        *(u32 *)(end_2 - 4) = size;
    }
    off = (*(u32 *)(arg0 + 0xc) & ~7) - 4;
    if (*(u32 *)(arg0 + off) != 0) {
        *(u32 *)(block + 8) = *(u32 *)(*(u32 *)(arg0 + off) + 8);
        *(u32 *)(*(u32 *)(block + 8) + 0xc) = block;
        *(u32 *)(block + 0xc) = *(u32 *)(arg0 + off);
        *(u32 *)(*(u32 *)(arg0 + off) + 8) = block;
        *(u32 *)(arg0 + off) = block;
        current = *(u32 *)(arg0 + off);
        if (!(*(u32 *)current & 4)) {
            size_2 = *(u32 *)(current - 4);
            if (size_2 & 2) {
                previous = current;
            } else {
                previous = current - size_2;
                *(u32 *)previous &= 7;
                *(u32 *)previous |= (size_2 + (*(u32 *)current & ~7)) & ~7;
                if (!(*(u32 *)previous & 2)) {
                    total = size_2 + (*(u32 *)current & ~7);
                    *(u32 *)(previous + total - 4) = total;
                }
                {
                    u32 head = *(u32 *)(arg0 + off);
                    if (head == current) {
                        *(u32 *)(arg0 + off) = *(u32 *)(*(u32 *)(arg0 + off) + 0xc);
                    }
                }
                *(u32 *)(*(u32 *)(current + 0xc) + 8) = *(u32 *)(current + 8);
                *(u32 *)(*(u32 *)(*(u32 *)(current + 0xc) + 8) + 0xc) = *(u32 *)(current + 0xc);
            }
        } else {
            previous = current;
        }
        *(u32 *)(arg0 + off) = previous;
        current = *(u32 *)(arg0 + off);
        size_2 = *(u32 *)current & ~7;
        size = current + size_2;
        next = size;
        if (!(*(u32 *)next & 2)) {
            total = size_2 + (*(u32 *)next & ~7);
            *(u32 *)current &= 7;
            *(u32 *)current |= total & ~7;
            if (!(*(u32 *)current & 2)) {
                *(u32 *)(current + total - 4) = total;
            }
            if (!(*(u32 *)current & 2)) {
                *(u32 *)(current + total) &= ~4;
            } else {
                *(u32 *)(current + total) |= 4;
            }
            {
                u32 head = *(u32 *)(arg0 + off);
                if (head == next) {
                    *(u32 *)(arg0 + off) = *(u32 *)(*(u32 *)(arg0 + off) + 0xc);
                }
            }
            {
                u32 head = *(u32 *)(arg0 + off);
                if (head == next) {
                    *(u32 *)(arg0 + off) = 0;
                }
            }
            *(u32 *)(*(u32 *)(next + 0xc) + 8) = *(u32 *)(next + 8);
            *(u32 *)(*(u32 *)(next + 8) + 0xc) = *(u32 *)(next + 0xc);
        }
    } else {
        *(u32 *)(arg0 + off) = block;
        *(u32 *)(block + 8) = block;
        *(u32 *)(block + 0xc) = block;
    }
    {
        u32 head = *(u32 *)(arg0 + off);
        u32 maximum = *(u32 *)(arg0 + 8);
        u32 available = *(u32 *)head & ~7;
        if (maximum < available) {
            *(u32 *)(arg0 + 8) = available;
        }
    }
}
#pragma opt_propagation reset
