#include "types.h"


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
