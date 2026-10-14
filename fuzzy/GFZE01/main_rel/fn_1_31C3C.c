/* Non-matching: best partial attempt (91.13% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/game.h"

typedef struct {
    u32 time;
    u32 unk_4;
    u8 pad_8[0x10];
    u16 unk_18;
    u8 unk_1a;
    u8 unk_1b;
    u8 unk_1c;
    u8 unk_1d;
    u8 unk_1e;
    u8 unk_1f;
} Record;

typedef struct {
    Record top10[10];
    Record best_lap;
    u16 max_speed;
    u8 unk_162;
    u8 pad_163;
    u8 unk_164;
    u8 unk_165;
    u8 unk_166;
    u8 unk_167;
    u8 unk_168;
} RecordData;

typedef struct {
    u8 pad_0[0x20d0];
    RecordData *records;
    u8 pad_20d4[0xe34];
    u32 rank;
    u32 unk_2f0c;
    u32 unk_2f10;
} Mgr;

typedef struct {
    u8 pad_0[0x18];
    u16 unk_18[5];
    u8 pad_22[0x2];
    u32 unk_24[5];
    u32 unk_38[5];
    u8 pad_4c[0x30];
    u8 unk_7c;
    u8 unk_7d;
    u8 unk_7e;
    u8 pad_7f;
    u8 unk_80;
    u8 unk_81;
    u8 unk_82;
    u8 pad_83[0xd];
} Obj;

typedef struct {
    u8 pad_0[0x6];
    u8 unk_6;
    u8 pad_7[0xcd];
    Obj obj;
    u8 pad_164[0x12e0];
    u32 unk_1444;
    u32 unk_1448;
    u8 pad_144c[0x10];
    u16 unk_145c;
    u8 unk_145e;
    u8 unk_145f;
    u8 unk_1460;
    u8 unk_1461;
    u8 unk_1462;
    u8 unk_1463;
    u8 pad_1464[0xa4];
} Sub;

typedef struct {
    u16 unk_0;
    u8 pad_2[0xe1];
    u8 unk_e3;
} Thing;

typedef struct {
    u8 pad_0[0x30];
    Sub sub;
    Thing thing;
} Bss3C00;

struct Obj_801A66CC_T {
    u8 pad_0[0x8b4];
    u8 unk_8B4;
    u8 unk_8B5;
    u16 unk_8B6;
};

extern struct Obj_801A66CC_T *lbl_801A66CC;

extern void fn_1_1554D0(void);
extern s32 fn_1_1555B0(s32);
extern void fn_1_155F9C(u32);
extern void fn_1_155FA8(u32);
extern s32 fn_1_F1B84(void);
extern s32 fn_1_F2280(s32);
extern void fn_1_F220C(s32);
extern u32 fn_1_F2338(s32, u32);
extern s32 ghost_test_record_flag0(s32);

void fn_1_31C3C(u32 arg0) {
    struct {
        Mgr *mgr;
    } s;
    Bss3C00 *base;
    u32 time;
    Obj *obj;
    Sub *sub;
    u32 lap_time;
    u32 rank;
    s32 i;
    u32 code;

    base = (Bss3C00 *)&lbl_1_bss_3C00;
    s.mgr = (Mgr *)((u8 *)base + 0x20000);
    obj = &base->sub.obj;
    time = obj->unk_24[arg0];
    lap_time = obj->unk_38[arg0];

    for (rank = 0; rank < 10; rank++) {
        if (time < s.mgr->records->top10[rank].time) {
            break;
        }
    }
    s.mgr->rank = rank;

    for (i = 9; (u32)i > s.mgr->rank; i--) {
        s.mgr->records->top10[i] = s.mgr->records->top10[i - 1];
    }

    if (s.mgr->rank < 10) {
        s.mgr->records->top10[s.mgr->rank].time = time;
        s.mgr->records->top10[s.mgr->rank].unk_4 = lap_time;
        s.mgr->records->top10[s.mgr->rank].unk_18 = obj->unk_18[arg0];
        s.mgr->records->top10[s.mgr->rank].unk_1a = obj->unk_82;
        s.mgr->records->top10[s.mgr->rank].unk_1b = obj->unk_80;
        s.mgr->records->top10[s.mgr->rank].unk_1c = obj->unk_81;
        s.mgr->records->top10[s.mgr->rank].unk_1d = obj->unk_7c;
        s.mgr->records->top10[s.mgr->rank].unk_1e = obj->unk_7d;
        s.mgr->records->top10[s.mgr->rank].unk_1f = obj->unk_7e;
    }

    if (lap_time < s.mgr->records->best_lap.time) {
        s.mgr->unk_2f0c = 1;
        s.mgr->records->best_lap.time = lap_time;
        s.mgr->records->best_lap.unk_4 = lap_time;
        s.mgr->records->best_lap.unk_18 = obj->unk_18[arg0];
        s.mgr->records->best_lap.unk_1a = obj->unk_82;
        s.mgr->records->best_lap.unk_1b = obj->unk_80;
        s.mgr->records->best_lap.unk_1c = obj->unk_81;
        s.mgr->records->best_lap.unk_1d = obj->unk_7c;
        s.mgr->records->best_lap.unk_1e = obj->unk_7d;
        s.mgr->records->best_lap.unk_1f = obj->unk_7e;
    } else {
        s.mgr->unk_2f0c = 0;
    }

    if (s.mgr->records->max_speed < obj->unk_18[arg0]) {
        s.mgr->unk_2f10 = 1;
        s.mgr->records->max_speed = obj->unk_18[arg0];
        s.mgr->records->unk_162 = obj->unk_82;
        s.mgr->records->unk_164 = obj->unk_80;
        s.mgr->records->unk_165 = obj->unk_81;
        s.mgr->records->unk_166 = obj->unk_7c;
        s.mgr->records->unk_167 = obj->unk_7d;
        s.mgr->records->unk_168 = obj->unk_7e;
    } else {
        s.mgr->unk_2f10 = 0;
    }

    sub = &base->sub;
    sub->unk_1448 = lap_time;
    sub->unk_145c = obj->unk_18[arg0];
    sub->unk_145e = obj->unk_82;
    sub->unk_145f = obj->unk_80;
    sub->unk_1460 = obj->unk_81;
    sub->unk_1461 = obj->unk_7c;
    sub->unk_1462 = obj->unk_7d;
    sub->unk_1463 = obj->unk_7e;

    code = lbl_801A66CC->unk_8B5 << 12;
    code |= lbl_801A66CC->unk_8B4 << 20;
    sub->unk_1444 = code | lbl_801A66CC->unk_8B6;

    fn_1_1554D0();
    fn_1_1555B0(lbl_1_bss_8B3A0.unk_90);

    if (s.mgr->rank < 10) {
        fn_1_155F9C(1);
        fn_1_155FA8(s.mgr->rank);
    } else {
        fn_1_155F9C(0);
        fn_1_155FA8(-1);
    }

    switch (fn_1_F1B84()) {
    case 1:
        sub = &base->sub;
        if (fn_1_F2280(sub->unk_6) == 0) {
            base->thing.unk_0 = 25;
            fn_1_F220C(sub->unk_6);
        }
        break;
    }

    sub = &base->sub;
    if ((u8)fn_1_F2338(sub->unk_6, time) != 0) {
        if (ghost_test_record_flag0(sub->unk_6) == 0) {
            base->thing.unk_e3 = sub->unk_6;
            base->thing.unk_0 = 10;
        }
    }
}
