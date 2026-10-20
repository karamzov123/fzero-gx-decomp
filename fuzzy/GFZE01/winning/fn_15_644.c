/* Non-matching: best partial attempt (99.20% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_15_644_Entry {
    u8 pad_0[4];
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[2];
};

struct fn_15_644_World {
    struct fn_15_644_Entry unk_0[9];
    u8 pad_48[0x14A];
    u8 unk_192;
    u8 pad_193;
    u8 unk_194[16];
};

struct fn_15_644_lbl_15_bss_0 {
    u8 pad_0[0x10];
    u32 unk_10;
    u32 unk_14;
    u8 pad_18[8];
    u8 unk_20;
    u8 pad_21[0xB];
    struct fn_15_644_World *unk_2C;
    s32 unk_30;
    u8 pad_34[4];
    s16 unk_38;
};

struct fn_15_644_lbl_1_bss_9F8 {
    u8 pad_0[0x10];
    u16 unk_10;
    u16 unk_12;
};

struct fn_15_644_lbl_1_bss_D58 {
    u8 pad_0[8];
    u16 unk_8;
};

struct fn_15_644_lbl_1_bss_525C {
    u8 pad_0[0x191];
    u8 unk_191;
};

extern struct fn_15_644_lbl_15_bss_0 lbl_15_bss_0;
extern struct fn_15_644_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern struct fn_15_644_lbl_1_bss_D58 lbl_1_bss_D58;
extern struct fn_15_644_lbl_1_bss_525C lbl_1_bss_525C;
extern u32 lbl_1_data_20B14[];
extern u8 lbl_15_data_0[];
extern u16 lbl_1_bss_968;
extern u16 lbl_1_bss_96A;
extern s16 lbl_1_bss_962;

extern void fn_1_A8EB0(int, int);
extern void fn_1_A8F40(u8);
extern void fn_1_A8E78(int);
extern void fn_1_A8DD4(const char *, ...);
extern s16 fn_1_12C930(s16);
extern s16 fn_1_12C710(s32);
extern void *fn_1_7F49C(s16, s16, void *);
extern u8 fn_1_B7C00(void);
extern void fn_1_4A00(s32, u8, void *);

#pragma opt_loop_invariants off
#pragma opt_dead_assignments off
static inline struct fn_15_644_Entry * fn_15_644_read_pointer(struct fn_15_644_lbl_15_bss_0 * owner) { return owner->unk_2C->unk_0; }
void fn_15_644(void) {
    s32 fzgx_condition_2371;
    u8 *str = lbl_15_data_0;
    struct fn_15_644_lbl_15_bss_0 *work = &lbl_15_bss_0;
    struct fn_15_644_World *world;
    struct fn_15_644_Entry *entry;
    struct fn_15_644_lbl_1_bss_D58 *ctrl;
    u16 name[18];
    s16 dir;
    s16 i;
    s16 id;
    struct { s16 value; } j;
    u32 color;
    u32 *colors;
    struct { u32 value; } flags;
    u8 lab_t0;

    if (!(work->unk_14 & 0x20000000)) {
        return;
    }
    world = work->unk_2C;
    if (((lbl_1_bss_9F8.unk_10 >> 3) & 1) || ((lbl_1_bss_9F8.unk_12 >> 3) & 1)) {
        dir = -1;
    } else if (((lbl_1_bss_9F8.unk_10 >> 2) & 1) || ((lbl_1_bss_9F8.unk_12 >> 2) & 1)) {
        dir = 1;
    } else {
        dir = 0;
    }
    work->unk_30 = (work->unk_30 + dir + 9) % 9;

    if (((lbl_1_bss_9F8.unk_10) & 1) || (lbl_1_bss_9F8.unk_12 & 1)) {
        dir = -1;
    } else if (((lbl_1_bss_9F8.unk_10 >> 1) & 1) || ((lbl_1_bss_9F8.unk_12 >> 1) & 1)) {
        dir = 1;
    } else {
        dir = 0;
    }

    if (dir != 0) {
        if ((fzgx_condition_2371 = work->unk_30) >= 0 && fzgx_condition_2371 < 4) {
            world->unk_0[work->unk_30].unk_4 = (world->unk_0[work->unk_30].unk_4 + dir + 41) % 41;
            world->unk_0[work->unk_30].unk_5 = world->unk_0[work->unk_30].unk_4;
        } else {
            switch (work->unk_30 - 4) {
            case 0:
                work->unk_14 ^= 0x80000000;
                break;
            case 1:
                break;
            case 2:
                work->unk_2C->unk_192 += dir;
                if (work->unk_2C->unk_192 == 0) {
                    work->unk_2C->unk_192 = 4;
                }
                if (work->unk_2C->unk_192 > 4) {
                    work->unk_2C->unk_192 = 1;
                }
                break;
            }
        }
    }

    entry = fn_15_644_read_pointer(work);
    fn_1_A8EB0(10, 19);
    fn_1_A8F40(255);
    fn_1_A8E78((int)(str + 0xB0));
    colors = lbl_1_data_20B14;
    for (i = 0; i < 4; i++) {
        if (i == work->unk_30) {
            lab_t0 = 51;
            fn_1_A8F40(lab_t0);
        } else {
            fn_1_A8F40(255);
        }
        id = entry->unk_4;
        fn_1_A8DD4((const char *)(str + 0xD0), i, id);
        color = colors[fn_1_12C930(id)];
        fn_1_7F49C(fn_1_12C710(id), 0, name);
        fn_1_A8DD4((const char *)(str + 0xE4), color, name);
        entry++;
    }
    for (; i < 9; i++) {
        if (i == work->unk_30) {
            fn_1_A8F40(51);
        } else {
            fn_1_A8F40(255);
        }
        switch (i - 4) {
        case 0:
            if (work->unk_14 & 0x80000000) {
                fn_1_A8E78((int)(str + 0xF0));
            } else {
                fn_1_A8E78((int)(str + 0xFC));
            }
            break;
        case 1:
            fn_1_A8E78((int)(str + 0x108));
            break;
        case 2:
            fn_1_A8DD4((const char *)(str + 0x120), work->unk_2C->unk_192);
            break;
        case 3:
            fn_1_A8E78((int)(str + 0x134));
            break;
        case 4:
            fn_1_A8E78((int)(str + 0x144));
            break;
        }
    }
    fn_1_A8F40(255);

    ctrl = &lbl_1_bss_D58;
    if (((ctrl->unk_8 >> 8) & 1) && !fn_1_B7C00()) {
        flags.value = work->unk_14 & 0xFFFFFF01;
        lbl_1_bss_525C.unk_191 = 0;
        work->unk_14 = flags.value;
        switch (work->unk_30 - 4) {
        case 1:
            work->unk_14 = flags.value | 9;
            lbl_1_bss_525C.unk_191 |= 1;
            lbl_1_bss_96A = 0xB8;
            work->unk_20 = 1;
            break;
        case 2:
            work->unk_14 = flags.value | 0x81;
            lbl_1_bss_525C.unk_191 |= 2;
            work->unk_38 = work->unk_2C->unk_192;
            lbl_1_bss_96A = 0xB8;
            work->unk_20 = 1;
            for (j.value = 0; j.value < work->unk_38; j.value++) {
                work->unk_2C->unk_194[j.value] = j.value;
            }
            break;
        case 3:
            work->unk_14 = flags.value | 5;
            lbl_1_bss_96A = 0xB8;
            work->unk_20 = 1;
            break;
        case 4:
            work->unk_14 = flags.value | 3;
            lbl_1_bss_525C.unk_191 |= 1;
            lbl_1_bss_96A = 0xB8;
            work->unk_20 = 0;
            break;
        default:
            work->unk_14 &= ~1;
            work->unk_20 = 1;
            break;
        }
        if ((work->unk_14 & 0x78) == 0) {
            fn_1_4A00(1, 30, (void *)work->unk_10);
        } else {
            fn_1_4A00(0, 0, (void *)work->unk_10);
        }
        lbl_1_bss_96A = 0xB8;
    }
    if (((ctrl->unk_8 >> 12) & 1) && !fn_1_B7C00() && work->unk_20 &&
        (work->unk_14 & 0x20000000) && lbl_1_bss_962 == 183) {
        lbl_1_bss_968 = 10;
    }
}
#pragma opt_dead_assignments reset

#pragma opt_loop_invariants reset
