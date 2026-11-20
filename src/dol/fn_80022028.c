#include "types.h"

#pragma pack(1)
struct Entry {
    s32 unk_0;
    s16 unk_4;
};
#pragma pack()

extern struct Entry lbl_80164D20[9];
extern s32 lbl_801A6B38;
extern s32 lbl_801A6B3C;
extern s32 lbl_801A6B40;
extern s32 lbl_801A6B44;
extern s32 lbl_801A6B48;
extern s32 lbl_801A6B4C;
extern s32 lbl_801A6B50;
extern s32 lbl_801A6B54;
extern s32 lbl_801A6B58;
extern void DCFlushRange(void *, u32);

static void update(struct Entry *e, s32 *src) {
    s32 v;
    v = *src / 160;
    if (v != 0) {
        s16 nv;
        if (v > 20) {
            v = 20;
        }
        if (v < -20) {
            v = -20;
        }
        e->unk_0 = *src;
        nv = (-v);
        *src = *src - v * 160;
        e->unk_4 = nv;
    } else {
        *src = 0;
        e->unk_0 = 0;
        e->unk_4 = 0;
    }
}

void fn_80022028(void) {
    struct { struct Entry *value; } p;
    p.value = lbl_80164D20;
    update(p.value + 0, &lbl_801A6B38);
    update(p.value + 1, &lbl_801A6B3C);
    update(p.value + 2, &lbl_801A6B40);
    update(p.value + 3, &lbl_801A6B44);
    update(p.value + 4, &lbl_801A6B48);
    update(p.value + 5, &lbl_801A6B4C);
    update(p.value + 6, &lbl_801A6B50);
    update(p.value + 7, &lbl_801A6B54);
    update(p.value + 8, &lbl_801A6B58);
    DCFlushRange(p.value, 54);
}
