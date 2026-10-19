/* Non-matching: best partial attempt (99.23% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u8 lbl_1_rodata_6E38[440];
extern u32 lbl_1_bss_7F0C0[5336];
extern void fn_80008BA8(void *dst, const void *src, s32 size);
extern void fn_1_F9CD0(s32 arg0, s32 arg1);
extern void ghost_set_record_flag2(s16 value);

typedef struct {
    u32 words[110];
} TableData;

static inline s16 find_record_ordinal(s16 key, s16 ordinal) {
    TableData table;
    u8 record[10];
    s16 match_count;
    s16 index;

    match_count = 0;
    for (index = 0; index < 44; index++) {
        table = *(TableData *)lbl_1_rodata_6E38;
        fn_80008BA8(record, (u8 *)table.words + index * 10, 10);
        if (*(s16 *)(record + 2) == key) {
            if (match_count == ordinal) {
                return index;
            }
            match_count++;
        }
    }
    return -1;
}

void fn_1_F946C(s16 value) {
    TableData table_a;
    TableData table_b;
    u8 record_a[10];
    u8 record_b[10];
    s16 ordinal;
    s16 index;
    s32 offset;

    table_a = *(TableData *)lbl_1_rodata_6E38;
    offset = value * 10;
    fn_80008BA8(record_a, (u8 *)table_a.words + offset, 10);

    table_b = *(TableData *)lbl_1_rodata_6E38;
    fn_80008BA8(record_b, (u8 *)table_b.words + offset, 10);

    ordinal = 0;
    for (;;) {
        index = find_record_ordinal(*(s16 *)(record_b + 2), ordinal);
        if (value == index) {
            break;
        }
        ordinal++;
    }

    switch (*(s16 *)(record_a + 2)) {
    case 0:
        fn_1_F9CD0(0, (u8)ordinal);
        break;
    case 1:
        lbl_1_bss_7F0C0[4672] |= ((1u << 31) >> (u8)ordinal);
        break;
    case 2:
        ghost_set_record_flag2(*(s16 *)(record_a + 8));
        break;
    case 3:
        lbl_1_bss_7F0C0[4677] |= ((1u << 31) >> (31 - ordinal));
        break;
    }
}

