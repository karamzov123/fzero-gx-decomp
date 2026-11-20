#include "types.h"


/* --- dol/fn_80058498.c --- */
struct SjRing {
    u32 unk0;
    s32 used;
    u32 unk8;
    u32 unkC;
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
    u32 unk38;
    u32 unk3C;
};

extern u32 fn_80057728(void);
extern u32 fn_800576DC(void);
extern u32 fn_800586E4(void);
extern u32 lbl_8018B2A4[];
extern u8 lbl_80132300[];
extern u8 lbl_80092330[];

struct SjRing *fn_80058498(void *a0, u32 a1, u32 a2) {
    s32 i;
    struct SjRing *entry;

    fn_80057728();

    for (i = 0; i < 0x100; i++) {
        if (((struct SjRing *)lbl_8018B2A4)[i].used == 0) {
            break;
        }
    }

    if (i == 0x100) {
        entry = 0;
    } else {
        entry = &((struct SjRing *)lbl_8018B2A4)[i];
        entry->used = 1;
        entry->unk0 = (u32)lbl_80132300;
        entry->unk1C = (u32)a0;
        entry->unk20 = a1;
        entry->unk24 = a2;
        entry->unk8 = (u32)lbl_80092330;
        entry->unk38 = (u32)fn_800586E4;
        entry->unk3C = (u32)entry;

        fn_80057728();
        entry->unkC = 0;
        entry->unk10 = entry->unk20;
        entry->unk14 = 0;
        entry->unk18 = 0;
        entry->unk28 = 0;
        entry->unk2C = 0;
        entry->unk30 = 0;
        entry->unk34 = 0;
        fn_800576DC();
    }

    fn_800576DC();
    return entry;
}

/* --- dol/fn_80058630.c --- */
struct Counter {
    u32 value;
};

extern u32 memset(u32, u32, u32);
extern u32 lbl_8018B2A0[];
extern u32 lbl_8018B2A4[4097];

void fn_80058630(void) {
    struct Counter *counter;
    fn_80057728();
    counter = (struct Counter *)&lbl_8018B2A0;
    if (--counter->value == 0) {
        memset((u32)&lbl_8018B2A4, 0, 0x4000);
    }
    fn_800576DC();
}
