/* Non-matching: best partial attempt (98.99% in the project ledger). Scored for the
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

void fn_1_F946C(s16 value) {
    TableData table_a;
    TableData table_b;
    TableData table_c;
    u8 record_a[10];
    u8 record_b[10];
    u8 record_c[10];
    struct { s16 value; } ordinal;
    struct { s16 value; } match_count;
    struct { s16 value; } index;
    struct { s16 value; } key;
    s32 offset;

    table_a = *(TableData *)lbl_1_rodata_6E38;
    offset = value * 10;
    fn_80008BA8(record_a, (u8 *)table_a.words + offset, 10);

    table_b = *(TableData *)lbl_1_rodata_6E38;
    fn_80008BA8(record_b, (u8 *)table_b.words + offset, 10);

    ordinal.value = 0;
    for (;;) {
        match_count.value = 0;
        index.value = 0;
        key.value = *(s16 *)(record_b + 2);
        for (; index.value < 44; index.value++) {
            table_c = *(TableData *)lbl_1_rodata_6E38;
            fn_80008BA8(record_c, (u8 *)table_c.words + index.value * 10, 10);
            if (*(s16 *)(record_c + 2) == key.value) {
                if (match_count.value != ordinal.value) {
                    match_count.value++;
                } else {
                    goto found;
                }
            }
        }
        index.value = -1;
    found:
        if (value == index.value) break;
        ordinal.value++;
    }

    switch (*(s16 *)(record_a + 2)) {
    case 0:
        fn_1_F9CD0(0, (u8)ordinal.value);
        break;
    case 1:
        lbl_1_bss_7F0C0[4672] |= (0x80000000u >> (u8)ordinal.value);
        break;
    case 2:
        ghost_set_record_flag2(*(s16 *)(record_a + 8));
        break;
    case 3:
        lbl_1_bss_7F0C0[4677] |= (0x80000000u >> (31 - ordinal.value));
        break;
    }
}
