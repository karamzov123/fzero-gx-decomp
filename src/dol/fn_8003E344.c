#include "types.h"

typedef struct {
    u8 unk00;
    u8 pad01[0x0B];
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u8 pad38[0x78];
} Entry;

typedef struct {
    Entry *entries;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
} Slot;

extern u32 fn_8000A020(void);
extern u32 fn_8000A040(void);
extern u32 fn_8000A050(void);
extern u32 fn_8003D588(void *, u32);
extern char lbl_8012B624[];
extern volatile s32 lbl_801A6584; /* Slot is written then re-read, as in the matched allocator. */
extern volatile u32 lbl_801A6588[2]; /* Pending token is sampled separately for its index and generation. */
extern volatile u32 lbl_801A6C40; /* Allocation count is re-read after clamping or incrementing. */
extern u32 lbl_801A6C44;
extern Slot *lbl_801A6C4C;
extern u32 lbl_801A6C50;
extern volatile u8 lbl_801A6C30; /* Reload the current generation after reading the pending token. */
extern void *memcpy(void *, const void *, u32);
extern void OSReport(const char *, ...);

void fn_8003E344(void) {
    u32 v0;
    u32 v16;
    struct { u32 source; } v18;
    if ((s32)lbl_801A6C40 != 0) {
        if (lbl_801A6588[0] < 65535) {
            v18.source = (u8)lbl_801A6588[0];
            v0 = lbl_801A6588[0];
            if ((s32)((v0 >> 8) & 0xF) != (s32)lbl_801A6C30) {
                if (lbl_801A6584 >= 0) {
                    lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk10 = fn_8000A050();
                    fn_8003D588(&lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584], 1);
                    lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk24 = fn_8000A040();
                    lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk34 = fn_8000A020();
                }
                lbl_801A6584 = -1;
                v0 = lbl_801A6C50 - 1;
                if (lbl_801A6C40 >= v0) {
                    lbl_801A6C40 = v0;
                    v0 = lbl_801A6C40;
                } else {
                    v0 = lbl_801A6C40;
                    lbl_801A6C40 = v0 + 1;
                }
                lbl_801A6584 = v0;
                lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk00 = 255;
                lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk14 = 0;
                fn_8003D588(&lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584], 0);
                lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk0C = fn_8000A050();
                lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk10 = 0;
                lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk20 = fn_8000A040();
                lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk30 = fn_8000A020();
            } else {
                v0 = lbl_801A6C50 - 1;
                if (lbl_801A6C40 >= v0) {
                    lbl_801A6C40 = v0;
                    v16 = lbl_801A6C40;
                } else {
                    v16 = lbl_801A6C40;
                    lbl_801A6C40 = v16 + 1;
                }
                memcpy(&lbl_801A6C4C[lbl_801A6C44].entries[v16],
                       &lbl_801A6C4C[lbl_801A6C44].entries[v18.source], 176);
                lbl_801A6C4C[lbl_801A6C44].entries[v16].unk10 = fn_8000A050();
                lbl_801A6C4C[lbl_801A6C44].entries[v16].unk24 = fn_8000A040();
                lbl_801A6C4C[lbl_801A6C44].entries[v16].unk34 = fn_8000A020();
                fn_8003D588(&lbl_801A6C4C[lbl_801A6C44].entries[v16], 1);
                lbl_801A6C4C[lbl_801A6C44].entries[v16].unk00 = 255;
                lbl_801A6C4C[lbl_801A6C44].entries[v18.source].unk0C = fn_8000A050();
                lbl_801A6C4C[lbl_801A6C44].entries[v18.source].unk20 = fn_8000A040();
                lbl_801A6C4C[lbl_801A6C44].entries[v18.source].unk30 = fn_8000A020();
                fn_8003D588(&lbl_801A6C4C[lbl_801A6C44].entries[v18.source], 0);
                lbl_801A6C4C[lbl_801A6C44].entries[v18.source].unk14 = 1;
                lbl_801A6584 = -1;
            }
        } else {
            if (lbl_801A6584 < 0) {
                OSReport(lbl_8012B624);
            } else {
                if (lbl_801A6584 >= 0) {
                    lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk10 = fn_8000A050();
                    fn_8003D588(&lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584], 1);
                    lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk24 = fn_8000A040();
                    lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk34 = fn_8000A020();
                }
                lbl_801A6584 = -1;
                v0 = lbl_801A6C50 - 1;
                if (lbl_801A6C40 >= v0) {
                    lbl_801A6C40 = v0;
                    v0 = lbl_801A6C40;
                } else {
                    v0 = lbl_801A6C40;
                    lbl_801A6C40 = v0 + 1;
                }
                lbl_801A6584 = v0;
                lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk00 = 255;
                lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk14 = 0;
                fn_8003D588(&lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584], 0);
                lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk0C = fn_8000A050();
                lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk10 = 0;
                lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk20 = fn_8000A040();
                lbl_801A6C4C[lbl_801A6C44].entries[lbl_801A6584].unk30 = fn_8000A020();
            }
        }
    }
}
