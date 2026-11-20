#include "types.h"


/* --- dol/qsort.c --- */
extern void qsort(void *base, unsigned long count, unsigned long size,
                        int (*compare)(const void *, const void *));

void qsort(void *base, size_t count, size_t size,
                 int (*compare)(const void *, const void *)) {
    size_t root;
    size_t remaining;
    size_t child;
    unsigned char *bytes = base;
    unsigned char *root_ptr;
    unsigned char *end_ptr;
    unsigned char *parent_ptr;
    unsigned char *child_ptr;
    if (count < 2)
        return;
    remaining = count;
    root = count / 2 + 1;
    root_ptr = bytes + size * (root - 1);
    end_ptr = bytes + size * (count - 1);
    for (;;) {
        if (root > 1) {
            --root;
            root_ptr -= size;
        } else {
            signed char *destination = (signed char *)(end_ptr - 1);
            signed char *source = (signed char *)(root_ptr - 1);
            size_t index;
            int temporary;
            for (index = size + 1; --index != 0;) {
                temporary = source[1];
                source[1] = destination[1];
                destination[1] = temporary;
                ++source;
                ++destination;
            }
            --remaining;
            if (remaining == 1)
                return;
            end_ptr -= size;
        }
        child = root;
        child_ptr = bytes + size * (root - 1);
        while (child * 2 <= remaining) {
            child *= 2;
            parent_ptr = child_ptr;
            child_ptr = bytes + size * (child - 1);
            if (child < remaining) {
                unsigned char *next = child_ptr + size;
                if (compare(child_ptr, next) < 0) {
                    child_ptr = next;
                    ++child;
                }
            }
            if (compare(parent_ptr, child_ptr) < 0) {
                signed char *destination = (signed char *)(child_ptr - 1);
                signed char *source = (signed char *)(parent_ptr - 1);
                size_t index;
                int temporary;
                for (index = size + 1; --index != 0;) {
                    temporary = source[1];
                    source[1] = destination[1];
                    destination[1] = temporary;
                    ++source;
                    ++destination;
                }
            } else {
                break;
            }
        }
    }
}

/* --- dol/fn_80082908.c --- */
/* --- dol/fn_80082908.c --- */
extern u32 lbl_801A6638;

u32 fn_80082908(void) {
    u32 v0;
    v0 = ((lbl_801A6638 * (0x41C60000 + 20077)) + 12345);
    lbl_801A6638 = v0;
    return ((v0 >> 16) & 0x7FFF);
}

/* --- dol/fn_80082928.c --- */
typedef struct {
    char *ptr;
    s32 count;
} FormatContext;

typedef u32 VaList[3];

typedef struct {
    FormatContext ctx;
    VaList ap;
    u32 pad[2];
} LocalBlock;

extern void fn_800829EC(void);
extern s32 fn_80082A7C(void (*callback)(void), FormatContext *ctx, const char *fmt, void *ap);

s32 fn_80082928(char *dst, const char *fmt, ...) {
    LocalBlock block;

    block.ap[0] = 0x02000000;
    block.ap[1] = (u32)((u8 *)&block.ctx + 0x30);
    block.ap[2] = (u32)((u8 *)&block.ctx - 0x60);
    block.ctx.ptr = dst;
    if (dst == 0 || *dst == 0) {
        return -1;
    }
    block.ctx.count = 0;
    return fn_80082A7C(fn_800829EC, &block.ctx, fmt, block.ap);
}
