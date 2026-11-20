#include "types.h"


/* --- dol/fn_800791E8.c --- */
extern u32 LCStoreBlocks(void *, void *, u32);
extern u32 fn_8000B8AC(u32);
extern u32 fn_800794F0(void *, void *, u32);
extern u32 lbl_801A6DB0;
extern s32 lbl_801A6DB8;
extern u8 lbl_801A6DB4;
extern void DCFlushRange(void *, u32);
extern void DCFlushRangeNoSync(void *, u32);
extern void LCLoadBlocks(void *, void *, u32);

u32 fn_800791E8(u8 *dst, u8 *src, u32 nBytes) {
    u32 numBlocks;
    u32 i;
    u32 numBytes;
    u32 numBlockLoops;
    u32 j;
    u8 *q;
    u8 *p;
    u32 remBytes;

    if (lbl_801A6DB8 == 0) {
        return fn_800794F0(dst, src, nBytes);
    }
    numBlocks = nBytes >> 10;
    remBytes = nBytes & 0x1F;
    numBlockLoops = numBlocks / lbl_801A6DB4;
    numBytes = ((nBytes - (numBlocks << 10)) - remBytes) >> 5;
    numBlocks = numBlocks % lbl_801A6DB4;
    DCFlushRange(src, nBytes);
    DCFlushRangeNoSync(dst, nBytes);
    for (i = 0; i < numBlockLoops; i++) {
        p = (u8 *)lbl_801A6DB0;
        q = p;
        for (j = 0; j < lbl_801A6DB4; j++) {
            fn_8000B8AC(14);
            LCLoadBlocks(p, src, 0x20);
            p += 0x400;
            src += 0x400;
        }
        for (j = 0; j < lbl_801A6DB4; j++) {
            fn_8000B8AC(14);
            LCStoreBlocks(dst, q, 0x20);
            dst += 0x400;
            q += 0x400;
        }
    }
    p = (u8 *)lbl_801A6DB0;
    q = p;
    for (j = 0; j < numBlocks; j++) {
        fn_8000B8AC(14);
        LCLoadBlocks(p, src, 0x20);
        p += 0x400;
        src += 0x400;
    }
    for (j = 0; j < numBlocks; j++) {
        fn_8000B8AC(14);
        LCStoreBlocks(dst, q, 0x20);
        dst += 0x400;
        q += 0x400;
    }
    if (numBytes != 0) {
        fn_8000B8AC(14);
        LCLoadBlocks(p, src, numBytes);
        src += numBytes << 5;
        fn_8000B8AC(14);
        LCStoreBlocks(dst, q, numBytes);
        dst += numBytes << 5;
    }
    if (remBytes != 0) {
        fn_800794F0(dst, src, remBytes);
    }
    return fn_8000B8AC(0);
}

/* --- dol/fn_800793D4.c --- */
extern void *memset(void *, int, u32);

u32 fn_800793D4(u8 *arg0, u32 arg1, u32 arg2) {
    u32 i;
    u32 blocks;
    u32 tail;
    u32 chunks;
    s32 did;

    did = 0;
    if (lbl_801A6DB8 == 0) {
        return (u32)memset(arg0, arg1 & 0xFF, arg2);
    }
    tail = arg2 & 0x1F;
    blocks = arg2 >> 10;
    chunks = ((arg2 - (arg2 & ~0x3FF)) - tail) >> 5;
    DCFlushRangeNoSync(arg0, arg2);
    if (blocks != 0) {
        memset((void *)lbl_801A6DB0, arg1 & 0xFF, 0x400);
        did = 1;
        for (i = 0; i < blocks; i++) {
            fn_8000B8AC(0xE);
            LCStoreBlocks(arg0, (void *)lbl_801A6DB0, 0x20);
            arg0 += 0x400;
        }
    }
    if (chunks != 0) {
        if (did == 0) {
            memset((void *)lbl_801A6DB0, arg1 & 0xFF, chunks << 5);
        }
        fn_8000B8AC(0xE);
        LCStoreBlocks(arg0, (void *)lbl_801A6DB0, chunks);
        arg0 += chunks << 5;
    }
    if (tail != 0) {
        memset(arg0, arg1 & 0xFF, tail);
    }
    return fn_8000B8AC(0);
}
