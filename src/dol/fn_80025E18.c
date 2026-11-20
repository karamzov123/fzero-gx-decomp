#include "types.h"


/* --- dol/fn_80025E18.c --- */
typedef struct {
    s16 v;
    s16 pad;
} Fn80025E18Pair;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    s32 unkC;
    s32 unk10;
    u32 x;
    u32 y;
    u32 unk1C;
    u32 unk20[6];
    Fn80025E18Pair pairs[10];
} Fn80025E18Entry;

extern Fn80025E18Entry lbl_80176160[64];
extern void fn_80025D5C(Fn80025E18Entry *);
extern u32 lbl_801A6B80;
extern u32 lbl_801A6B84;
extern u32 lbl_801A6B88;

void fn_80025E18(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 64; i++) {
        lbl_80176160[i].unk4 = 0x50000000;
        lbl_80176160[i].unk8 = 0;
        lbl_80176160[i].unkC = -0x3c0;
        lbl_80176160[i].unk10 = -0x3c0;
        lbl_80176160[i].unk1C = 0;
        lbl_80176160[i].x = 0x40;
        lbl_80176160[i].y = 0x7f;
        for (j = 9; j >= 0; j--) {
            lbl_80176160[i].pairs[j].v = 0;
        }
        fn_80025D5C(&lbl_80176160[i]);
    }
    lbl_801A6B80 = 0;
    lbl_801A6B84 = 0;
    lbl_801A6B88 = 1;
}

/* --- dol/fn_80025EE0.c --- */
/* --- dol/fn_80025EE0.c --- */
// fn_80025EE0: empty in retail (single blr).
void fn_80025EE0(void) {
}

/* --- dol/fn_80025EE4.c --- */

void fn_80025EE4(u32 arg0) {
    lbl_801A6B88 = arg0;
}
