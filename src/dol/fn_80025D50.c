#include "types.h"


/* --- dol/fn_80025D50.c --- */
extern u32 lbl_801A64F8;
extern u32 lbl_801A64FC;

void fn_80025D50(u32 arg0, u32 arg1) {
    lbl_801A64F8 = arg0;
    lbl_801A64FC = arg1;
}

/* --- dol/fn_80025D5C.c --- */
typedef struct {
    u8 pad0[0x14];
    u32 x;
    u32 y;
    u32 pad1c;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2c;
    u32 unk30;
    u32 unk34;
    u8 pad1[0x950];
    s16 half[128];
    s16 extra[128];
} Fn80025D5CObject;

typedef struct {
    u8 pad0[0x78c];
    u32 words[128];
    s16 half[128];
    s16 extra[128];
} Fn80025D5CTable;

extern u32 lbl_801A6B88[2];
extern u8 lbl_80128990[3008];

void fn_80025D5C(Fn80025D5CObject *obj) {
    Fn80025D5CTable *table = (Fn80025D5CTable *)lbl_80128990;
    u32 x = obj->x;
    u32 y = obj->y;
    u32 dx = 0x7f - x;
    u32 dy = 0x7f - y;

    if (lbl_801A6B88[0] == 3) {
        obj->unk20 = table->half[x];
        obj->unk24 = table->half[dx];
        obj->unk28 = table->half[dy];
        obj->unk2c = table->half[y];
        obj->unk30 = table->extra[dx];
        obj->unk34 = table->extra[x];
    } else {
        obj->unk20 = table->words[x];
        obj->unk24 = table->words[dx];
        obj->unk28 = table->words[dy];
        obj->unk2c = table->words[y];
    }
}
