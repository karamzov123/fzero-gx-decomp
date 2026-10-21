#include "types.h"

#pragma use_lmw_stmw on

struct Sig_fn_800501F4_fn_800501F4_Arg0 {
    u8 pad_0[0x8];
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
};

struct fn_800510D8_Entry {
    u32 unk_0;
    s32 unk_4;
    u8 pad_8[0x180 - 0x8];
};

struct fn_800510D8_Arg0 {
    u8 pad_0[0x345];
    u8 unk_345;
    u8 pad_346[2];
    s32 unk_348;
    struct Sig_fn_800501F4_fn_800501F4_Arg0 *unk_34C;
    u32 unk_350;
    s32 unk_354;
    s32 unk_358;
    s32 unk_35C;
    s32 unk_360;
    s32 unk_364;
    s32 unk_368;
    s32 unk_36C;
    s32 unk_370;
    s32 unk_374;
    s32 unk_378;
    s32 unk_37C;
    s32 unk_380;
    s32 unk_384;
    s32 unk_388;
    s32 unk_38C;
    s32 unk_390;
    s32 unk_394;
    s32 unk_398;
    struct fn_800510D8_Entry *unk_39C;
    u8 pad_3A0[0x18];
    s32 unk_3B8[8][32];
};

extern s32 fn_8004FF68(struct Sig_fn_800501F4_fn_800501F4_Arg0 *);
extern s32 fn_800501F4(struct Sig_fn_800501F4_fn_800501F4_Arg0 *, s32);
extern s32 fn_80050670(s32, struct fn_800510D8_Entry **);
extern void fn_80050BD4(struct Sig_fn_800501F4_fn_800501F4_Arg0 *, s32 *, s32 *, s32 *, s32 *);
extern s32 lbl_80130B68[3][4];
extern s32 lbl_80130B48[2][4];

/* the column pointers step through obj itself: unk_3B8[j][i] is read as col->unk_3B8[j][0] */
#define COL_STEP(p, bytes) ((struct fn_800510D8_Arg0 *)((u8 *)(p) + (bytes)))

s32 fn_800510D8(struct fn_800510D8_Arg0 *obj) {
    s32 count;
    s32 total;
    struct { struct Sig_fn_800501F4_fn_800501F4_Arg0 *value; } dec;
#define dec dec.value
    struct {
        struct fn_800510D8_Entry *entries;
        s32 j;
        s32 i;
        struct Sig_fn_800501F4_fn_800501F4_Arg0 *src;
        struct fn_800510D8_Arg0 *row;
        struct fn_800510D8_Arg0 *col;
        struct fn_800510D8_Entry *ent;
        s32 n;
    } loops;
    struct fn_800510D8_Entry *ent2;
    struct fn_800510D8_Arg0 *col2;
    s32 tmp_fn_800501F4;
    struct fn_800510D8_Arg0 *col3;
    s32 v;
#define entries loops.entries
#define j loops.j
#define i loops.i
#define src loops.src
#define row loops.row
#define col loops.col
#define ent loops.ent
#define n loops.n

    if (obj->unk_34C == 0) {
        return 0;
    }
    if (fn_8004FF68(obj->unk_34C) != 1) {
        return 1;
    }
    dec = obj->unk_34C;
    tmp_fn_800501F4 = fn_800501F4(dec, 1);
    obj->unk_354 = tmp_fn_800501F4;
    tmp_fn_800501F4 = fn_800501F4(dec, 2);
    obj->unk_358 = 4 - tmp_fn_800501F4;
    tmp_fn_800501F4 = fn_800501F4(dec, 1);
    obj->unk_35C = tmp_fn_800501F4 == 0;
    tmp_fn_800501F4 = fn_800501F4(dec, 4);
    obj->unk_360 = tmp_fn_800501F4;
    tmp_fn_800501F4 = fn_800501F4(dec, 2);
    obj->unk_364 = tmp_fn_800501F4;
    tmp_fn_800501F4 = fn_800501F4(dec, 1);
    obj->unk_368 = tmp_fn_800501F4;
    tmp_fn_800501F4 = fn_800501F4(dec, 1);
    obj->unk_36C = tmp_fn_800501F4;
    tmp_fn_800501F4 = fn_800501F4(dec, 2);
    obj->unk_370 = tmp_fn_800501F4;
    tmp_fn_800501F4 = fn_800501F4(dec, 2);
    obj->unk_374 = tmp_fn_800501F4;
    tmp_fn_800501F4 = fn_800501F4(dec, 1);
    obj->unk_378 = tmp_fn_800501F4;
    tmp_fn_800501F4 = fn_800501F4(dec, 1);
    obj->unk_37C = tmp_fn_800501F4;
    tmp_fn_800501F4 = fn_800501F4(dec, 2);
    obj->unk_380 = tmp_fn_800501F4;

    if (obj->unk_384 == 0) {
        if (obj->unk_370 == 3) {
            obj->unk_388 = 1;
        } else {
            obj->unk_388 = 2;
        }
    }
    if (obj->unk_358 == 2) {
        obj->unk_394 = fn_80050670(0, &obj->unk_39C);
    } else {
        obj->unk_394 = 32;
    }
    if (obj->unk_370 == 1) {
        obj->unk_398 = lbl_80130B68[obj->unk_358][obj->unk_374];
    } else {
        obj->unk_398 = obj->unk_394;
    }
    if (obj->unk_384 == 0) {
        obj->unk_38C = lbl_80130B48[obj->unk_354][obj->unk_364];
    }

    entries = obj->unk_39C;
    j = 0;
    i = 0;
    src = obj->unk_34C;
    row = obj;
    col = obj;
    ent = entries;
    total = obj->unk_394;
    count = obj->unk_388;
    n = obj->unk_398;
    for (; i < n; i++) {
        row = col;
        for (j = 0; j < count; j++) {
            tmp_fn_800501F4 = fn_800501F4(src, ent->unk_4);
            row->unk_3B8[0][0] = tmp_fn_800501F4;
            row = COL_STEP(row, 0x80);
        }
        col = COL_STEP(col, 4);
        ent++;
    }
    ent2 = entries + n;
    col2 = COL_STEP(obj, n * 4);
    while (n < total) {
        tmp_fn_800501F4 = fn_800501F4(src, ent2->unk_4);
        v = tmp_fn_800501F4;
        col2->unk_3B8[1][0] = v;
        col2->unk_3B8[0][0] = v;
        col2 = COL_STEP(col2, 4);
        ent2++;
        n++;
    }
    col3 = COL_STEP(obj, total * 4);
    while (total < 32) {
        for (n = 0; n < count; n++) {
            col3->unk_3B8[n][0] = 0;
        }
        col3 = COL_STEP(col3, 4);
        total++;
    }
    fn_80050BD4(obj->unk_34C, &obj->unk_384, obj->unk_3B8[0], obj->unk_3B8[2], obj->unk_3B8[4]);
    obj->unk_345 = 1;
    obj->unk_348 = 0;
    return 0;
}
