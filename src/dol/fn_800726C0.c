#include "types.h"


/* --- dol/fn_800726C0.c --- */
struct fn_800726C0_Entry {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    u8 unk_c;
};

struct fn_800726C0_Table {
    u8 pad_0[0x1a0];
};

extern struct fn_800726C0_Table lbl_8019E308[];
extern void GXSetVtxAttrFmt(u32, s32, s32, s32, u8);

void fn_800726C0(u32 arg0, struct fn_800726C0_Entry *arg1) {
    struct fn_800726C0_Entry *entry;
    s32 value0;
    s32 value1;
    s32 value2;
    u8 value3;

    entry = (struct fn_800726C0_Entry *)&lbl_8019E308[arg0];
    while (arg1->unk_0 < 0x1a) {
        value0 = arg1->unk_0;
        value3 = arg1->unk_c;
        value2 = arg1->unk_8;
        value1 = arg1->unk_4;
        if (entry->unk_0 != value0 ||
            entry->unk_4 != value1 ||
            entry->unk_8 != value2 ||
            entry->unk_c != value3) {
            entry->unk_0 = value0;
            entry->unk_4 = value1;
            entry->unk_8 = value2;
            entry->unk_c = value3;
            GXSetVtxAttrFmt(arg0, value0, value1, value2, value3);
        }
        arg1++;
    }
}

/* --- dol/fn_80072778.c --- */
extern u32 fn_80072A50(u32, u32, u32, u32, u32);
extern u32 lbl_801A6D38;
extern u32 memset(u32, u32, u32);

s32 fn_80072778(void) {
    memset(lbl_801A6D38, 255, 3232);
    fn_80072A50(0, 0, 1, 2, 3);
    fn_80072A50(1, 0, 1, 2, 0);
    fn_80072A50(2, 0, 1, 2, 1);
    fn_80072A50(3, 0, 1, 2, 2);
    return 1;
}

/* --- dol/fn_80072808.c --- */
void fn_80072808(void) {
    memset(lbl_801A6D38, 255, 3232);
    fn_80072A50(0, 0, 1, 2, 3);
    fn_80072A50(1, 0, 1, 2, 0);
}
