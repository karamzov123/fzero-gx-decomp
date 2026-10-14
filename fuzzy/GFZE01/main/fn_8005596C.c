/* Non-matching: best partial attempt (84.05% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct Sig_fn_800175C0_DVDCommandBlock Sig_fn_800175C0_DVDCommandBlock;
typedef struct Sig_fn_800175C0_DVDFileInfo Sig_fn_800175C0_DVDFileInfo;
typedef struct Sig_DVDGetTransferredSize_DVDCommandBlock {
    u8 pad_00[0xC];
    s32 state;
    u8 pad_10[0xC];
    u32 currTransferSize;
    u32 transferredSize;
} Sig_DVDGetTransferredSize_DVDCommandBlock;
typedef struct Sig_fn_800174D0_Fn800174D0Object {
    u8 pad30[0x30];
    u32 field30;
    u32 field34;
    void *field38;
} Sig_fn_800174D0_Fn800174D0Object;
typedef struct Sig_fn_800175C0_DVDDiskID {
    char gameName[4];
    char company[2];
    u8 diskNumber;
    u8 gameVersion;
    u8 streaming;
    u8 streamBufSize;
    u8 padding[22];
} Sig_fn_800175C0_DVDDiskID;
typedef void (*Sig_fn_800175C0_DVDCBCallback)(s32 result, Sig_fn_800175C0_DVDCommandBlock *block);
struct Sig_fn_800175C0_DVDCommandBlock {
    Sig_fn_800175C0_DVDCommandBlock *next;
    Sig_fn_800175C0_DVDCommandBlock *prev;
    u32 command;
    s32 state;
    u32 offset;
    u32 length;
    void *addr;
    u32 currTransferSize;
    u32 transferredSize;
    Sig_fn_800175C0_DVDDiskID *id;
    Sig_fn_800175C0_DVDCBCallback callback;
    void *userData;
};
typedef void (*Sig_fn_800175C0_DVDCallback)(s32 result, Sig_fn_800175C0_DVDFileInfo *fileInfo);
struct Sig_fn_800175C0_DVDFileInfo {
    Sig_fn_800175C0_DVDCommandBlock cBlock;
    u32 startAddr;
    u32 length;
    Sig_fn_800175C0_DVDCallback callback;
};

struct fn_8005596C_block {
    s8 f00;
    s8 f01;
    s8 state;
    s8 f03;
    u32 f04;
    void *addr;
    s32 f0C;
    s32 f10;
    s32 f14;
    u32 f18;
    s32 f1C;
    u32 f20;
    s32 f24;
    u8 pad28[0x3C];
};

struct fn_8005596C_ctx {
    u32 unk_0;
    s8 state;
    u8 pad05[7];
    u32 unk_C;
    u32 unk_10;
    struct fn_8005596C_block blocks[40];
};

typedef u32 (*fn_8005596C_Fn0)(u32, u32, u32);

extern int fn_800174D0(Sig_fn_800174D0_Fn800174D0Object *, int, int, int, void (*)(void), void *);
extern s32 fn_800175C0(Sig_fn_800175C0_DVDFileInfo *, void *, s32, s32, s32);
extern struct fn_8005596C_ctx lbl_801878B8;
extern u32 DVDGetCommandBlockStatus(u32);
extern u32 DVDGetTransferredSize(Sig_DVDGetTransferredSize_DVDCommandBlock *);
extern char lbl_80091F50[];
extern u32 lbl_801322C8[2];
extern void * memset(void *, int, u32);
extern void DCInvalidateRange(void *, u32);
extern void DCStoreRange(void *, u32);
extern void fn_800555C0(void);

u32 fn_8005596C(struct fn_8005596C_block *arg0, s32 arg1, u32 arg2) {
    struct fn_8005596C_ctx *pCB;
    struct fn_8005596C_block *blk;
    u8 *pFlag;
    char *msg;
    s32 i;
    s32 c1;
    s32 c2;
    s32 found;
    s32 sz;
    s32 tsize;
    s32 rem;
    s32 done;
    s32 diff;
    u32 size;
    s32 result;
    pCB = (struct fn_8005596C_ctx *)&lbl_801878B8;
    msg = lbl_80091F50;
    if (arg0 == 0) {
        if (pCB->unk_10 != 0) {
            ((fn_8005596C_Fn0)pCB->unk_10)(pCB->unk_C, (u32)(msg + 0x2C), 0);
        }
        return 0;
    }
    if (arg1 < 0) {
        if (pCB->unk_10 != 0) {
            ((fn_8005596C_Fn0)pCB->unk_10)(pCB->unk_C, (u32)(msg + 0xCC), (u32)arg0);
        }
        return 0;
    }
    if (arg2 == 0) {
        if (pCB->unk_10 != 0) {
            ((fn_8005596C_Fn0)pCB->unk_10)(pCB->unk_C, (u32)(msg + 0xEC), (u32)arg0);
        }
        return 0;
    }
    c1 = (arg0->state == 1 || arg0->state == 0);
    if (c1 == 0) {
        return 0;
    }
    c2 = (arg0->f0C == 0 || arg0->f0C == 10);
    if (c2 == 0) {
        return 0;
    }
    blk = pCB->blocks;
    for (i = 0; i < 40; i++) {
        if (blk[i].f00 == 1 && blk[i].state == 2) {
            found = 1;
            goto L_found;
        }
    }
    found = 0;
L_found:
    if (found != 0) {
        return 0;
    }
    if (arg1 == 0) {
        arg0->state = 1;
        ((u8 *)pCB)[4] = 1;
        return 0;
    }
    arg0->f20 = 0;
    arg0->addr = (void *)arg2;
    arg0->f24 = arg1;
    pFlag = (u8 *)pCB;
    for (i = 0; i < 40; i++) {
        if (blk->f00 == 1 && blk->state == 2) {
            blk->f0C = DVDGetCommandBlockStatus((u32)&blk->pad28);
            pCB->unk_0 = blk->f0C;
            if (blk->f0C == 0) {
                sz = blk->f24 * blk->f10;
                DCInvalidateRange(blk->addr, sz);
                blk->f20 = sz;
                blk->f1C = blk->f1C + blk->f24;
                if (blk->f1C * blk->f10 > blk->f14) {
                    rem = blk->f1C * blk->f10 - blk->f14;
                    memset((void *)((u8 *)blk->addr + blk->f20 - rem), 0, rem);
                    DCStoreRange((void *)((u8 *)blk->addr + blk->f20 - rem), rem);
                }
                blk->state = 1;
                pFlag[4] = 1;
            } else if (blk->f0C == 10) {
                tsize = DVDGetTransferredSize((Sig_DVDGetTransferredSize_DVDCommandBlock *)&blk->pad28);
                DCInvalidateRange(blk->addr, tsize);
                pFlag[4] = 0;
                blk->f20 = blk->f10 * (tsize / blk->f10);
                blk->f1C = blk->f1C + tsize / blk->f10;
                blk->state = 0;
            } else if (blk->f0C == -1) {
                blk->state = 3;
                pFlag[4] = 3;
            }
        }
        blk = &blk[1];
    }
    done = arg0->f1C * arg0->f10;
    if (done + arg0->f24 * arg0->f10 > arg0->f14) {
        diff = arg0->f14 - done;
        if (diff < 0) {
            arg0->state = 1;
            pFlag[4] = 1;
            return arg1;
        }
    }
    size = (u32)(diff + 0x1F) & 0xFFFFFFE0;
    DCInvalidateRange((void *)arg2, size);
    if (lbl_801322C8[0] == 0) {
        result = fn_800174D0((Sig_fn_800174D0_Fn800174D0Object *)&arg0->pad28, (int)arg2, (int)size, done, fn_800555C0, (void *)2);
    } else {
        result = fn_800175C0((Sig_fn_800175C0_DVDFileInfo *)&arg0->pad28, (void *)arg2, (s32)size, done, 2);
    }
    if (result == 0) {
        return 0;
    }
    arg0->state = 2;
    pFlag[4] = 2;
    return arg0->f24;
}
