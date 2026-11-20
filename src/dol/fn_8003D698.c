#include "types.h"

extern u32 fn_8000A020(void);
extern u32 fn_8000A040(void);
extern u32 fn_8000A050(void);
extern u32 fn_8003D588(void *, u32);
extern void fn_8003E284(void);
extern void fn_8003E13C(void);

extern u8 lbl_801A6C30;
extern s32 lbl_801A6C40;
extern void (*lbl_801A6C3C)(u32);
extern volatile u32 lbl_801A6588;  /* re-read on every access in retail */
extern s32 lbl_801A6584;
extern u32 lbl_801A6C44;

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
    u8 pad28[0x08];
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

extern Slot *lbl_801A6C4C;

void fn_8003D698(u32 arg0) {
    s32 idx;
    s32 cur;

    if (((arg0 & 0xFFFF) < 0xe000) ||
        (((s32)((arg0 & 0xFFFF) >> 8) & 0xf) != lbl_801A6C30) || lbl_801A6C40 == 0) {
        if (lbl_801A6C3C != 0) {
            lbl_801A6C3C(arg0);
        }
        return;
    }
    if ((arg0 & 0xFFFF) >= 0xf000) {
        if (lbl_801A6588 == 0xffff) {
            fn_8003E284();
            fn_8003E13C();
            return;
        }
        idx = (u8)(arg0 & 0xFFFF);
        if ((u8)lbl_801A6588 != idx) {
            idx = (u8)lbl_801A6588;
        }
        lbl_801A6C4C[lbl_801A6C44].entries[idx].unk10 = fn_8000A050();
        lbl_801A6C4C[lbl_801A6C44].entries[idx].unk24 = fn_8000A040();
        lbl_801A6C4C[lbl_801A6C44].entries[idx].unk34 = fn_8000A020();
        fn_8003D588(&lbl_801A6C4C[lbl_801A6C44].entries[idx], 1);
        if (lbl_801A6584 >= 0) {
            fn_8003E284();
        }
        lbl_801A6588 = 0xffff;
        fn_8003E13C();
    } else {
        if (lbl_801A6588 < 0xffff) {
            cur = (u8)lbl_801A6588;
            lbl_801A6C4C[lbl_801A6C44].entries[cur].unk10 = fn_8000A050();
            lbl_801A6C4C[lbl_801A6C44].entries[cur].unk24 = fn_8000A040();
            lbl_801A6C4C[lbl_801A6C44].entries[cur].unk34 = fn_8000A020();
            fn_8003D588(&lbl_801A6C4C[lbl_801A6C44].entries[cur], 1);
        } else {
            fn_8003E284();
        }
        cur = (u8)(arg0 & 0xFFFF);
        lbl_801A6C4C[lbl_801A6C44].entries[cur].unk20 = fn_8000A040();
        lbl_801A6C4C[lbl_801A6C44].entries[cur].unk30 = fn_8000A020();
        lbl_801A6C4C[lbl_801A6C44].entries[cur].unk0C =
            lbl_801A6C4C[lbl_801A6C44].entries[cur].unk1C = fn_8000A050();
        fn_8003D588(&lbl_801A6C4C[lbl_801A6C44].entries[cur], 0);
        lbl_801A6588 = (u16)arg0;
    }
}
