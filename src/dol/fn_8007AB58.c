#include "types.h"


/* --- dol/fn_8007AB58.c --- */
extern u32 fn_80079FA8(u32);
extern u32 fn_8007ADF0(u32, u32);

u32 fn_8007AB58(u32 arg0, u32 arg1) {
    u32 v0;
    u32 v2;
    u32 t0;
    u32 v1;
    u32 t1;
    v1 = (arg1 + 0x1f) & ~0x7;
    if (v1 < 0x10000) {
    v1 = 0x10000;
    }
    t0 = fn_80079FA8(v1);
    v2 = t0;
    if (t0 == 0) {
    v2 = 0;
    } else {
    t1 = fn_8007ADF0(v2, v1);
    v2 = t1;
    v2 = *(u32 *)((u8 *)arg0 + 0);
    if (v2 != 0) {
    *(u32 *)((u8 *)t0 + 0) = *(u32 *)((u8 *)v2 + 0);
    v2 = *(u32 *)((u8 *)t0 + 0);
    *(u32 *)((u8 *)v2 + 4) = t0;
    *(u32 *)((u8 *)t0 + 4) = *(u32 *)((u8 *)arg0 + 0);
    v2 = *(u32 *)((u8 *)arg0 + 0);
    *(u32 *)((u8 *)v2 + 0) = t0;
    *(u32 *)((u8 *)arg0 + 0) = t0;
    } else {
    *(u32 *)((u8 *)arg0 + 0) = t0;
    *(u32 *)((u8 *)t0 + 0) = t0;
    *(u32 *)((u8 *)t0 + 4) = t0;
    }
    v2 = t0;
    }
    return v2;
}

/* --- dol/fn_8007AC0C.c --- */
typedef struct Block {
    struct Block *prev;
    struct Block *next;
    unsigned long max_size;
    const unsigned long size;
} Block;

typedef struct SubBlock {
    unsigned long size;
    Block *bp;
    struct SubBlock *prev;
    struct SubBlock *next;
} SubBlock;

#define SubBlock_size(ths) ((ths)->size & 0xFFFFFFF8)
#define SubBlock_block(ths) ((Block *)((unsigned long)((ths)->bp) & ~0x1))
#define Block_size(ths) ((ths)->size & 0xFFFFFFF8)
#define Block_start(ths) (*(SubBlock **)((char *)(ths) + Block_size((ths)) - sizeof(unsigned long)))
#define SubBlock_is_free(ths) (!((ths)->size & 2))

static inline void SubBlock_construct(SubBlock *ths, unsigned long size_, Block *bp_, int prev_alloc, int this_alloc) {
    ths->bp = (Block *)((unsigned long)bp_ | 0x1);
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
    unsigned long npsz = origsize - sz;
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
