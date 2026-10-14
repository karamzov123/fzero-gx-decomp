/* Non-matching: best partial attempt (73.72% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 pad_00[0xC];
    s32 state;
    u8 pad_10[0xC];
    u32 currTransferSize;
    u32 transferredSize;
} DvdCommandBlock;

typedef struct {
    s8 state;
    s8 pad_01;
    s8 subState;
    s8 pad_03;
    u8 pad_04[4];
    u32 buffer;
    s32 status;
    s32 blockSize;
    s32 maxOffset;
    u32 pad_18;
    s32 offset;
    s32 aligned;
    s32 numBlocks;
    DvdCommandBlock block;
    u8 pad_4C[0x18];
} DvdEntry;

typedef struct {
    s32 status;
    s8 flag;
    u8 pad_05[7];
} DvdLibStatus;

extern u8 lbl_801878CC[];
extern u32 lbl_801878B8[3];
extern u32 DVDGetCommandBlockStatus(u32);
extern u32 DVDGetTransferredSize(DvdCommandBlock *);
extern void *memset(void *, int, u32);
extern void DCInvalidateRange(void *, u32);
extern void DCStoreRange(void *, u32);

void fn_8005640C(void) {
    s32 i;
    DvdEntry *e;
    DvdLibStatus *lib = (DvdLibStatus *)&lbl_801878B8;

    for (i = 0; i < 0x28; i++) {
        e = &((DvdEntry *)lbl_801878CC)[i];
        if (e->state != 1 || e->subState != 2) {
            continue;
        }
        e->status = DVDGetCommandBlockStatus((u32)&e->block);
        lbl_801878B8[0] = e->status;
        if (e->status == 0) {
            s32 size = e->numBlocks * e->blockSize;
            s32 total;
            DCInvalidateRange((void *)e->buffer, size);
            e->aligned = size;
            e->offset += e->numBlocks;
            total = e->offset * e->blockSize;
            if (total > e->maxOffset) {
                s32 excess = total - e->maxOffset;
                u8 *start = (u8 *)e->buffer + e->aligned - excess;
                memset(start, 0, excess);
                DCStoreRange(start, excess);
            }
            e->subState = 1;
            lib->flag = 1;
        } else if (e->status > 0) {
            if (e->status == 10) {
                s32 transferred = DVDGetTransferredSize(&e->block);
                DCInvalidateRange((void *)e->buffer, transferred);
                e->aligned = e->blockSize * (transferred / e->blockSize);
                lib->flag = 0;
                e->offset += transferred / e->blockSize;
                e->subState = 0;
            }
        } else if (e->status >= -1) {
            e->subState = 3;
            lib->flag = 3;
        }
    }
}
