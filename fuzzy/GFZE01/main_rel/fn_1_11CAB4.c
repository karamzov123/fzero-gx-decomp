/* Non-matching: best partial attempt (84.57% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern f32 lbl_1_rodata_7AB8[];
extern void fn_1_10846C(void *);
extern f32 lbl_8006D0B4(f32);

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_11CAB4_Vec;

typedef struct {
    u8 active;
    u8 pad_1[0x0f];
    fn_1_11CAB4_Vec pos;
    u8 pad_2[0x24];
    f32 result;
} fn_1_11CAB4_Entry;

typedef struct {
    u8 pad_0[0x18];
    u32 count;
    u8 pad_1c[0x08];
    fn_1_11CAB4_Entry *entries;
} fn_1_11CAB4_Data;

static inline f32 fn_1_11CAB4_length(f32 x, f32 y, f32 z) {
    return lbl_8006D0B4((f32)(x * x) + y * y + z * z);
}

static inline volatile f32 fn_1_11CAB4_array_read(volatile f32 *array, s32 index) { return array[index]; }
#pragma opt_propagation off
void fn_1_11CAB4(fn_1_11CAB4_Data *data) {
    f32 fzgx_live;
    f32 s1;
    fn_1_11CAB4_Vec center;
    /* retail keeps the difference in the frame and reloads it after the call */
    volatile f32 d[3];
    f32 *constants;
    u32 i;
    u32 i_2;
    s32 n;
    fn_1_11CAB4_Entry *entry;
    f32 value_off;
    f32 value_on;
    f32 max_dist;

    constants = lbl_1_rodata_7AB8;
    if (data != 0) {
        fn_1_10846C(data);

        i = 0;
        entry = data->entries;
        value_on = constants[25];
        value_off = constants[26];
        while (i < data->count) {
            if ((entry->active & 1) != 0) {
                entry->result = value_on;
                entry->active = 0;
            } else {
                entry->result = value_off;
                entry->active = 1;
            }
            i++;
            entry++;
        }

        center = *(fn_1_11CAB4_Vec *)&constants[267];
        i = 0;
        n = data->count;
        entry = data->entries;
        while (n > 0) {
            if ((entry->active & 1) != 0) {
                f32 a0;
                f32 a1;

                a0 = center.x;
                a1 = center.y;
                fzgx_live = entry->pos.x;
                center.x = a0 + fzgx_live;
                center.y = a1 + entry->pos.y;
                center.z = (center.z) + entry->pos.z;
                i++;
            }
            entry++;
            n--;
        }

        center.x = center.x / (f32)i;
        center.y = center.y / (f32)i;
        center.z = center.z / (f32)i;

        i = 0;
        max_dist = constants[26];
        entry = data->entries;
        while (i < data->count) {
            if ((entry->active & 1) == 0) {
                f32 s0;

                f32 s2;

                fzgx_live = entry->pos.x;
                s0 = fzgx_live - center.x;
                s1 = entry->pos.y - center.y;
                s2 = entry->pos.z - center.z;
                d[0] = s0;
                d[1] = s1;
                d[2] = s2;
                if (fn_1_11CAB4_length(s0, s1, s2) > max_dist) {
                    max_dist = fn_1_11CAB4_length(fn_1_11CAB4_array_read(d, 0), fn_1_11CAB4_array_read(d, 1), fn_1_11CAB4_array_read(d, 2));
                }
            }
            i++;
            entry++;
        }

        entry = data->entries;
        i_2 = 0;
        while (i_2 < data->count) {
            if ((entry->active & 1) == 0) {
                f32 s0;

                f32 s2;

                fzgx_live = entry->pos.x;
                s0 = fzgx_live - center.x;
                s1 = entry->pos.y - center.y;
                s2 = entry->pos.z - center.z;
                d[0] = s0;
                d[1] = s1;
                d[2] = s2;
                entry->result = -fn_1_11CAB4_length(s0, s1, s2) / max_dist;
            }
            i_2++;
            entry++;
        }
    }
}
#pragma opt_propagation reset

