#include "types.h"

#pragma use_lmw_stmw on

struct fn_80048340_block {
    /* volatile: destination pointer must be re-read on each stream copy */
    void *volatile ptr; /* volatile: staged destination pointer survives the callbacks */
    u32 size;
};

struct fn_80048340_stream {
    u32 vtable;
};

struct fn_80048340_data {
    u8 pad_00[0x48];
    s32 unk_48;
    s32 unk_4c;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
    s32 unk_7c;
    u8 pad_80[0x248];
    s16 unk_2c8;
    s16 unk_2ca;
    s16 unk_2cc;
    s16 unk_2ce;
    s16 unk_2d0;
    u8 pad_2d2[0x4];
    s8 unk_2d6;
    u8 unk_2d7[0x10];
    s16 unk_2e8;
    s16 unk_2ea;
    s16 unk_2ec;
};

typedef u32 (*fn_80048340_FnA)(struct fn_80048340_stream *, u32, u32,
                               struct fn_80048340_block *);
typedef u32 (*fn_80048340_FnB)(struct fn_80048340_stream *, u32,
                               struct fn_80048340_block *);
typedef u32 (*fn_80048340_FnC)(struct fn_80048340_stream *, u32,
                               struct fn_80048340_block *);

extern u32 lbl_8012B8FC[];
extern size_t strlen(const char *);
extern void *memcpy(void *, const void *, u16);

static inline s32 fn_80048340_put8(struct fn_80048340_stream *arg1,
                                   const u8 *p) {
    struct fn_80048340_block blk;

    (*(fn_80048340_FnA *)(arg1->vtable + 24))(arg1, 0, 1, &blk);
    if ((s32)blk.size < 1) {
        (*(fn_80048340_FnB *)(arg1->vtable + 28))(arg1, 0, &blk);
        return 0;
    }
    memcpy((void *)blk.ptr, (const void *)p, 1);
    (*(fn_80048340_FnC *)(arg1->vtable + 32))(arg1, 1, &blk);
    return 1;
}

static inline s32 fn_80048340_put16(struct fn_80048340_stream *arg1,
                                    const volatile void *p) { /* volatile: staged source slot */
    struct fn_80048340_block blk;
    s16 *dst;

    (*(fn_80048340_FnA *)(arg1->vtable + 24))(arg1, 0, 2, &blk);
    if ((s32)blk.size < 2) {
        (*(fn_80048340_FnB *)(arg1->vtable + 28))(arg1, 0, &blk);
        return 0;
    }
    dst = (s16 *)blk.ptr;
    *dst = *(const volatile s16 *)p; /* volatile: source read after the callback */
    (*(fn_80048340_FnC *)(arg1->vtable + 32))(arg1, 1, &blk);
    return 1;
}

static inline s32 fn_80048340_put16n(struct fn_80048340_stream *arg1,
                                     const u16 *p) {
    struct fn_80048340_block blk;
    s16 *dst;

    (*(fn_80048340_FnA *)(arg1->vtable + 24))(arg1, 0, 2, &blk);
    if ((s32)blk.size < 2) {
        (*(fn_80048340_FnB *)(arg1->vtable + 28))(arg1, 0, &blk);
        return 0;
    }
    dst = (s16 *)blk.ptr;
    *dst = *(const s16 *)p;
    (*(fn_80048340_FnC *)(arg1->vtable + 32))(arg1, 1, &blk);
    return 1;
}

static inline s32 fn_80048340_put32(struct fn_80048340_stream *arg1,
                                    const volatile s32 *p) { /* volatile: staged source slot */
    struct fn_80048340_block blk;
    s32 *dst;

    (*(fn_80048340_FnA *)(arg1->vtable + 24))(arg1, 0, 4, &blk);
    if ((s32)blk.size < 4) {
        (*(fn_80048340_FnB *)(arg1->vtable + 28))(arg1, 0, &blk);
        return 0;
    }
    dst = (s32 *)blk.ptr;
    *dst = *p;
    (*(fn_80048340_FnC *)(arg1->vtable + 32))(arg1, 1, &blk);
    return 1;
}

static inline s32 fn_80048340_putBytes(struct fn_80048340_stream *arg1,
                                       const void *src, u32 n) {
    struct fn_80048340_block blk;

    (*(fn_80048340_FnA *)(arg1->vtable + 24))(arg1, 0, n, &blk);
    if ((s32)blk.size < (s32)n) {
        (*(fn_80048340_FnB *)(28 + arg1->vtable))(arg1, 0, &blk);
        return 0;
    }
    memcpy((void *)blk.ptr, src, n & 0xffff);
    (*(fn_80048340_FnC *)(arg1->vtable + 32))(arg1, 1, &blk);
    return n;
}

s32 fn_80048340(struct fn_80048340_data *arg0, struct fn_80048340_stream *arg1) {
    s32 len;
    s32 size;
    s32 count;
    s32 i;
    s32 pad;
    /* WARNING: compiler-diff device, not original code: the remaining volatile
     * block pointer, writer reads and word staging retain retail's stack
     * allocation and access ordering. Ordinary halfword staging matches without
     * qualified writes; those qualifiers and address casts are not needed. */
    u8 b;
    u16 v1;
    u16 v;
    volatile s32 d; /* volatile: staged slot survives the stream callbacks */
    u16 vi;

    len = strlen((const char *)*(u32 *)&lbl_8012B8FC[0]);
{
    struct fn_80048340_block blk;
    (*(fn_80048340_FnA *)(arg1->vtable + 24))(arg1, 0, 0x7fffffff, &blk);
    size = blk.size;
    (*(fn_80048340_FnB *)(((28) + (arg1->vtable))))(arg1, 0, &blk);
}
    if (size < arg0->unk_48 + 4) {
        return 0;
    }
    v1 = 0x8000;
    if (fn_80048340_put16(arg1, &v1) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    vi = arg0->unk_48;
    if (fn_80048340_put16(arg1, &vi) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    b = arg0->unk_4c;
    if (fn_80048340_put8(arg1, &b) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    b = arg0->unk_50;
    if (fn_80048340_put8(arg1, &b) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    b = arg0->unk_54;
    if (fn_80048340_put8(arg1, &b) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    b = arg0->unk_58;
    if (fn_80048340_put8(arg1, &b) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    d = arg0->unk_5c;
    if (fn_80048340_put32(arg1, &d) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    d = arg0->unk_60;
    if (fn_80048340_put32(arg1, &d) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    v = arg0->unk_64;
    if (fn_80048340_put16(arg1, &v) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    b = 4;
    if (fn_80048340_put8(arg1, &b) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    if (arg0->unk_2d0 == 0) {
        b = 0;
    } else {
        b = 8;
    }
    if (fn_80048340_put8(arg1, &b) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    d = 0;
    if (fn_80048340_put32(arg1, &d) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    v = arg0->unk_2c8;
    if (fn_80048340_put16(arg1, &v) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    v = arg0->unk_2cc;
    if (fn_80048340_put16(arg1, &v) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    v = arg0->unk_2ca;
    if (fn_80048340_put16(arg1, &v) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    v = arg0->unk_2ce;
    if (fn_80048340_put16(arg1, &v) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    count = 0x1c;
    if (arg0->unk_6c > 0) {
        v = arg0->unk_68;
        if (fn_80048340_put16(arg1, &v) != 1) {
            goto fail; /* error: single shared failure exit */
        }
        v = arg0->unk_6c;
        if (fn_80048340_put16(arg1, &v) != 1) {
            goto fail; /* error: single shared failure exit */
        }
        i = 0;
        count = 0x20;
        while (i < arg0->unk_6c) {
            v = i;
            if (fn_80048340_put16n(arg1, &v) != 1) {
                goto fail; /* error: single shared failure exit */
            }
            v = 1;
            if (fn_80048340_put16(arg1, &v) != 1) {
                goto fail; /* error: single shared failure exit */
            }
            d = arg0->unk_70;
            if (fn_80048340_put32(arg1, &d) != 1) {
                goto fail; /* error: single shared failure exit */
            }
            d = arg0->unk_74;
            if (fn_80048340_put32(arg1, &d) != 1) {
                goto fail; /* error: single shared failure exit */
            }
            d = arg0->unk_78;
            if (fn_80048340_put32(arg1, &d) != 1) {
                goto fail; /* error: single shared failure exit */
            }
            d = arg0->unk_7c;
            if (fn_80048340_put32(arg1, &d) != 1) {
                goto fail; /* error: single shared failure exit */
            }
            count += 0x14;
            i++;
        }
    }
    if (arg0->unk_2d6 == 1) {
        if (arg0->unk_6c == 0) {
            d = 0;
            if (fn_80048340_put32(arg1, &d) != 1) {
                goto fail; /* error: single shared failure exit */
            }
            count += 4;
        }
        d = 0x41494E46;
        if (fn_80048340_put32(arg1, &d) != 1) {
            goto fail; /* error: single shared failure exit */
        }
        d = 0x18;
        if (fn_80048340_put32(arg1, &d) != 1) {
            goto fail; /* error: single shared failure exit */
        }
        if (fn_80048340_putBytes(arg1, arg0->unk_2d7, sizeof(arg0->unk_2d7)) !=
            sizeof(arg0->unk_2d7)) {
            goto fail; /* error: single shared failure exit */
        }
        v = arg0->unk_2e8;
        if (fn_80048340_put16(arg1, &v) != 1) {
            goto fail; /* error: single shared failure exit */
        }
        v = 0;
        if (fn_80048340_put16(arg1, &v) != 1) {
            goto fail; /* error: single shared failure exit */
        }
        v = arg0->unk_2ea;
        if (fn_80048340_put16(arg1, &v) != 1) {
            goto fail; /* error: single shared failure exit */
        }
        v = arg0->unk_2ec;
        if (fn_80048340_put16(arg1, &v) != 1) {
            goto fail; /* error: single shared failure exit */
        }
        count += 0x20;
    }
    b = 0;
    pad = arg0->unk_48 - len;
    while (count < pad) {
        if (fn_80048340_put8(arg1, &b) != 1) {
            goto fail; /* error: single shared failure exit */
        }
        count++;
    }
    if (fn_80048340_putBytes(arg1, (const void *)*(u32 *)&lbl_8012B8FC[0],
                             len) != len) {
        goto fail; /* error: single shared failure exit */
    }
    count += len;
    return count + 4;
fail:
    /* every field write funnels into this single shared failure exit */
    return 0;
}
