/* Non-matching: best partial attempt (86.59% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct PPEntry {
    s16 id;
    u8 pad_2[2];
    u32 flags;
} PPEntry;

typedef struct PPGroup {
    u32 flags;
    u8 pad_4[2];
    s16 unk_6;
    PPEntry entries[8];
    s16 count_a;
    s16 limit_a;
    s16 count_b;
    s16 limit_b;
} PPGroup;

typedef struct PPBss {
    u8 pad_0[0x110];
    PPGroup group;
} PPBss;

typedef struct PPData {
    u8 pad_0[0x2AB4];
    PPEntry table[8];
    u8 pad_2AF4[0x2F30 - 0x2AF4];
    u32 param;
    u8 pad_2F34[0x10];
    u32 mode;
} PPData;

typedef struct PPSlot {
    u8 id;
    u8 pad_1[3];
    u32 value;
} PPSlot;

typedef struct PPPlayer {
    u32 flags;
    u8 pad_4[0x81A4 - 4];
    PPSlot slots[3];
} PPPlayer;

extern PPData lbl_14_data_0;
extern PPBss lbl_14_bss_0;
extern PPPlayer lbl_14_bss_180;
extern u32 lbl_801A63C0;

extern u32 fn_14_DC2C(void);
extern void fn_14_315C(u32);
extern void *fn_80008BEC(void *, int, unsigned long); /* memset */
extern void *fn_80008BA8(void *, const void *, unsigned long); /* memcpy */
extern void fn_1_128B60(u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *);
extern u8 fn_1_14F270(u8, s32, u32);
extern s16 fn_1_14D5CC(s32, u32, u32);
extern s32 fn_1_128B00(s32);
extern s16 fn_1_14F19C(s16, s32, u32);
extern s16 fn_1_14D670(void);
extern PPPlayer *fn_1_36AD0(void);
extern void fn_1_12B4EC(u8, s16);
extern u32 fn_1_14D6D8(u8);
extern u32 fn_1_151BE8(u8, s16);


void fn_14_2590(void) {
    PPData *data;
    s16 m;
    u32 param;
    u32 *used;
    s16 i;
    PPEntry *entry;
    u8 *picks;
    s16 count_b;
    s16 group;
    s16 sel;
    PPPlayer *player;
    struct { s16 value; } j;
    s16 k;
    PPBss *bss;
    PPSlot *slot;
    u8 extra;
    u8 ids[9];
    u32 masks[3];
    u32 lab_t2;

    data = &lbl_14_data_0;
    bss = &lbl_14_bss_0;
    param = data->param;
{
    s16 count_a;
    count_a = 0;
    count_b = 0;
    fn_80008BEC(masks, 0, sizeof(masks));
    fn_80008BEC(ids, 0, sizeof(ids));
    fn_1_128B60(&ids[0], &ids[1], &ids[2], &ids[3], &ids[4], &ids[5], &ids[6], &ids[7], &ids[8], &extra);
    ids[0] = fn_1_14F270(ids[0], 0, param);
    ids[1] = fn_1_14F270(ids[1], 0, param);
    ids[2] = fn_1_14F270(ids[2], 0, param);
    ids[3] = fn_1_14F270(ids[3], 1, param);
    ids[4] = fn_1_14F270(ids[4], 1, param);
    ids[5] = fn_1_14F270(ids[5], 1, param);
    ids[6] = fn_1_14F270(ids[6], 2, param);
    ids[7] = fn_1_14F270(ids[7], 2, param);
    ids[8] = fn_1_14F270(ids[8], 2, param);

    fn_80008BEC(&bss->group, 0, 0x50);
    fn_80008BA8(bss->group.entries, data->table, sizeof(data->table));
    for (i = 0; i < 8u; i++) {
        if (bss->group.entries[i].flags & 8) {
            count_a++;
        }
        if (bss->group.entries[i].flags & 0x10) {
            count_b++;
        }
    }
    bss->group.flags |= 0x80000000;
    bss->group.unk_6 = 1;
    bss->group.count_a = count_a / 3;
    bss->group.count_b = count_b;
    bss->group.limit_a = count_a / 3 + 1;
}
    bss->group.limit_b = count_b + 1;

    used = masks;
    group = 0;
    picks = ids;
    picks = picks;
    entry = bss->group.entries;
    for (i = 0; i < 8u; i++, entry++) {
        if (entry->flags & 8) {
            do {
                lab_t2 = 0x10000000;
                entry->id = fn_1_14D5CC(group, param, lab_t2);
            } while (entry->id == picks[0] || entry->id == picks[1] || entry->id == picks[2] ||
                     entry->id == (s16)fn_1_14F270(fn_1_128B00(group), group, param) ||
                     (*used & (1 << fn_1_14F19C(entry->id, group, param))));
            *used |= 1 << fn_1_14F19C(entry->id, group, param);
            if (entry->flags & 0x20) {
                picks += 3;
                used++;
                group++;
            }
        }
        if (entry->flags & 0x10) {
            do {
                entry->id = fn_1_14D670();
            } while (entry->id == (s16)fn_1_128B00(3) || entry->id == extra);
        }
    }

    ids[0] = bss->group.entries[1].id;
    ids[1] = bss->group.entries[2].id;
    ids[3] = bss->group.entries[3].id;
    ids[4] = bss->group.entries[4].id;
    ids[6] = bss->group.entries[5].id;
    ids[7] = bss->group.entries[6].id;
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    sel = (lbl_801A63C0 >> 16) & 3;

    player = fn_1_36AD0() + (u8)fn_14_DC2C();
    player->flags |= (0x80000000 | 0x40000000);
    {
    s16 fzgx_loop_j_4253;
for (fzgx_loop_j_4253 = 0; fzgx_loop_j_4253 < 3; fzgx_loop_j_4253++) {
        player->slots[fzgx_loop_j_4253].id = fn_1_14F270(fn_1_128B00(fzgx_loop_j_4253), fzgx_loop_j_4253, param);
    }
    j.value = fzgx_loop_j_4253;
}
    fn_1_12B4EC((u8)fn_14_DC2C(), sel);

    for (j.value = 0; j.value < 3; j.value++) {
        for (k = 0; k < 25; k++) {
            if ((fn_1_14D6D8(fn_1_14F270(k, j.value, param)) & 0x80000000) &&
                !(fn_1_14D6D8(fn_1_14F270(k, j.value, param)) & 0x10000000)) {
                (&lbl_14_bss_180)->slots[j.value].id = fn_1_14F270(k, j.value, param);
                for (m = 0; m < 1; m++) {
                    (&(&lbl_14_bss_180)->slots[j.value].value)[m] = fn_1_151BE8((&lbl_14_bss_180)->slots[j.value].id, (sel % 4) + m);
                }
                break;
            }
        }
    }
    lbl_14_bss_180.flags |= (0x80000000 | 0x40000000);

    switch (sel) {
    case 0:
        data->mode = 0x80000000;
        break;
    case 1:
        data->mode = 0x40000000;
        break;
    case 2:
        data->mode = 0x20000000;
        break;
    case 3:
        data->mode = 0x10000000;
        break;
    default:
        data->mode = 0x80000000;
        break;
    }
    fn_14_315C(0xF);
}
