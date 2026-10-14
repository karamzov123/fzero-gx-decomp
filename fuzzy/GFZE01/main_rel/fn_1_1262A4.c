/* Non-matching: best partial attempt (51.00% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_1_1262A4_Copy64 { u32 a[17]; };
struct fn_1_1262A4_lbl_1_rodata_7AB8 {
    u8 pad_0[0x64];
    f32 unk_64;
    f32 unk_68;
    u8 pad_6C[0xF0];
    f32 unk_15C;
};
typedef struct {
    u8 active;
    u8 pad_1[0x0F];
    f32 value;
    f32 value2;
    f32 value3;
    u8 pad_1C[0x24];
    f32 result;
} fn_1_1262A4_Entry;
typedef struct {
    u8 pad_0[0x18];
    u32 count;
    u32 count2;
    u8 pad_20[4];
    fn_1_1262A4_Entry *entries;
    void *map;
} fn_1_1262A4_Data;

extern struct fn_1_1262A4_lbl_1_rodata_7AB8 lbl_1_rodata_7AB8;
extern u32 fn_1_10846C(u32);
extern void fn_1_128884(void *, void *, int);
extern u32 fn_1_4630(u32, u32, u32, u32);
extern f32 fn_1_1289BC(const fn_1_1262A4_Entry *, const fn_1_1262A4_Entry *);
extern u32 lbl_801A6410;
extern u8 lbl_1_data_40530[];

void fn_1_1262A4(fn_1_1262A4_Data *data) {
    struct fn_1_1262A4_lbl_1_rodata_7AB8 *pool;
    fn_1_1262A4_Entry *entry;
    fn_1_1262A4_Entry *other;
    fn_1_1262A4_Entry *chosen;
    fn_1_1262A4_Entry scratch[8];
    u32 i;
    u32 j;
    u32 k;
    u32 chosen_index;
    u32 group;
    u32 group_count;
    u32 left_count;
    u32 right_count;
    u32 out;
    f32 group_value;
    f32 zero;
    f32 on_value;
    f32 off_value;
    pool = &lbl_1_rodata_7AB8;
    if (data != 0) {
        fn_1_10846C((u32)data);
        entry = data->entries;
        on_value = pool->unk_64;
        off_value = pool->unk_68;
        i = 0;
        while (i < data->count) {
            if ((entry->active & 1) != 0) {
                entry->result = on_value;
                entry->active = 0;
            } else {
                entry->result = off_value;
                entry->active = 1;
            }
            i++;
            entry++;
        }
        i = 0;
        j = 0;
        entry = data->entries;
        while (i < data->count) {
            u32 next;
            next = i + 1;
            other = (fn_1_1262A4_Entry *)((u8 *)data->entries + j + 0x44);
            while (next < data->count) {
                if (entry->value > other->value) {
                    fn_1_128884(entry, other, 0x44);
                }
                next++;
                other++;
            }
            i++;
            j += 0x44;
            entry++;
        }
        chosen = data->entries;
        chosen_index = data->count;
        zero = pool->unk_15C;
        for (i = 0; i < data->count; i++) {
            if (data->entries[i].value > zero && (data->entries[i].active & 1)) {
                chosen = &data->entries[i];
                break;
            }
        }
        chosen_index = (u32)((u8 *)chosen - (u8 *)data->entries) / 0x44;
        while (chosen_index < data->count - 1) {
            fn_1_128884(chosen, chosen + 1, 0x44);
            chosen_index++;
            chosen++;
        }
        entry = data->entries;
        group_count = data->count >> 3;
        group = 0;
        while (group < group_count) {
            for (i = 0; i < 8; i++) {
                for (j = i + 1; j < 8; j++) {
                    if (entry[i].value2 < entry[j].value2) {
                        fn_1_128884(&entry[i], &entry[j], 0x44);
                    }
                }
            }
            scratch[0] = entry[0];
            left_count = 1;
            right_count = 7;
            for (i = 1; i < 8; i++) {
                if (entry[i].value3 > pool->unk_68) {
                    scratch[left_count++] = entry[i];
                } else {
                    scratch[right_count--] = entry[i];
                }
            }
            group_value = (f32)group;
            group_value = -group_value;
            for (i = 0; i < 8; i++) {
                entry[i] = scratch[i];
            }
            for (i = 0; i < 8; i++) {
                entry[i].result = group_value / (f32)(group_count - 1);
            }
            group++;
            entry += 8;
        }
        data->count2 = 0x40;
        data->map = (void *)fn_1_4630(lbl_801A6410, data->count2 * 0xC,
                                      (u32)lbl_1_data_40530, 0x2DF1);
        out = 0;
        entry = data->entries;
        group = 0;
        while (group < group_count - 1) {
            i = 0;
            while (i < 7) {
                ((u32 *)data->map)[out * 3] = (u32)&entry[i];
                ((u32 *)data->map)[out * 3 + 1] = (u32)&entry[i + 1];
                ((f32 *)((u8 *)data->map + out * 0xC))[2] =
                    fn_1_1289BC(&entry[i], &entry[i + 1]);
                i++;
                out++;
            }
            ((u32 *)data->map)[out * 3] = (u32)(entry + 7);
            ((u32 *)data->map)[out * 3 + 1] = (u32)entry;
            ((f32 *)((u8 *)data->map + out * 0xC))[2] =
                fn_1_1289BC(entry, (fn_1_1262A4_Entry *)((u8 *)entry + 0x1DC));
            entry += 8;
            group++;
            out++;
        }
        group = 0;
        entry = data->entries;
        while (group < group_count - 1) {
            other = entry;
            for (i = 0; i < 8; i++) {
                ((u32 *)data->map)[out * 3] = (u32)other;
                ((u32 *)data->map)[out * 3 + 1] = (u32)((u8 *)other + 0x220);
                ((f32 *)((u8 *)data->map + out * 0xC))[2] =
                    fn_1_1289BC(other, (fn_1_1262A4_Entry *)((u8 *)other + 0x220));
                other++;
                out++;
            }
            entry = (fn_1_1262A4_Entry *)((u8 *)entry + 0x220);
            group++;
        }
    }
}
