/* Non-matching: best partial attempt (96.82% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u16 unk_0;
    s16 unk_2;
    u32 unk_4;
    s16 unk_8;
} Rec10;

typedef struct {
    u32 unk_0[110];
} Tab440;

struct fn_1_F9888_bss_7F0C0 {
    u8 pad_0[0x4900];
    u32 unk_4900;
    u8 pad_4904[0xC];
    u32 unk_4910;
};

extern struct fn_1_F9888_bss_7F0C0 lbl_1_bss_7F0C0;
extern u8 lbl_1_rodata_6E38[440];
extern void fn_1_F9E10(u32);
extern void ghost_set_record_flag1(s32);
extern void fn_80008BA8(void *, void *, u32);

void fn_1_F9888(s16 arg0) {
    struct { s16 value; } cnt;
    struct { s16 value; } i;
    Rec10 rec_20;
    Rec10 rec_14;
    Tab440 tab_39C;
    Tab440 tab_1E4;
    Tab440 tab_2C;
    struct { s16 value; } k;
    s16 id;
    struct { s16 value; } key;
    Rec10 rec_8;
    s32 tmp_cse1;

    id = arg0;
    tab_39C = *(Tab440 *)&lbl_1_rodata_6E38;
    tmp_cse1 = arg0 * 10;
    fn_80008BA8(&rec_20, (u8 *)&tab_39C + tmp_cse1, 10);
    tab_1E4 = *(Tab440 *)&lbl_1_rodata_6E38;
    fn_80008BA8(&rec_14, (u8 *)&tab_1E4 + tmp_cse1, 10);

    k.value = 0;
    for (;;) {
        i.value = 0;
        cnt.value = i.value;
        key.value = rec_14.unk_2;
        for (; i.value < 44; i.value++) {
            tab_2C = *(Tab440 *)((u8 *)&lbl_1_rodata_6E38);
            fn_80008BA8(&rec_8, (u8 *)&tab_2C + i.value * 10, 10);
            if (rec_8.unk_2 == key.value) {
                if (cnt.value == k.value)
                    goto L_found; /* found the k-th match; i.value is the index */
                cnt.value++;
            }
        }
        i.value = -1;
    L_found:
        if (id == i.value)
            break;
        k.value++;
    }

    switch (rec_20.unk_2) {
    case 0:
        fn_1_F9E10(k.value & 0xFF);
        break;
    case 1:
        lbl_1_bss_7F0C0.unk_4900 &= ~(0x80000000 >> ((k.value & 0xFF) + 16));
        break;
    case 2:
        ghost_set_record_flag1(rec_20.unk_8);
        break;
    case 3:
        lbl_1_bss_7F0C0.unk_4910 &= ~(0x80000000 >> (31 - ((k.value << 1) + 1)));
        break;
    }
}
