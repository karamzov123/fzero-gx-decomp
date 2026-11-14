#include "types.h"

typedef struct Block Block;
typedef struct FixBlock FixBlock;
typedef struct FixSubBlock FixSubBlock;
struct Block {
    Block *prev;
    Block *next;
    unsigned long max_size;
    unsigned long size;
};
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
extern const unsigned long lbl_80094EC0[];
extern void *fn_8007A9A4(MemPoolObj *, unsigned long, unsigned long *);
extern void *fn_8007AA7C(MemPoolObj *, unsigned long);

static void FixBlock_construct(FixBlock *ths, FixBlock *prev, FixBlock *next, unsigned long index, unsigned long size) {
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
            b = fn_8007A9A4(pool, n * (lbl_80094EC0[i] + 4) + 20, &avail);
            if (b != 0) break;
            if (avail > 20)
                n = (avail - 20) / (lbl_80094EC0[i] + 4);
            else
                n = 0;
        }
        if (b == 0 && n < n_used) {
            b = fn_8007AA7C(pool, n_used * (lbl_80094EC0[i] + 4) + 20);
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

