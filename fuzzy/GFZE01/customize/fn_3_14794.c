/* Non-matching: best partial attempt (70.83% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/customize/emblem.h"

struct fn_3_14794_Arg3 {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
};
extern void *memset(void *, int, u32);

static inline u32 packColor(struct fn_3_14794_Arg3 *arg3) {
    if (arg3->unk_3 >= 224) {
        return ((arg3->unk_1 << 2) & 0x3E0) |
               ((arg3->unk_0 << 7) & 0x7C00) |
               ((u32)arg3->unk_2 >> 3) | 32768;
    } else {
        return (arg3->unk_1 & 0xF0) |
               ((arg3->unk_0 << 4) & 0xF00) |
               ((u32)arg3->unk_2 >> 4) |
               ((arg3->unk_3 << 7) & 0x7000);
    }
}

void fn_3_14794(u32 arg0, u32 arg1, u32 arg2, struct fn_3_14794_Arg3 *arg3) {
    s16 v1;
    s16 v2;
    s16 v4;
    s16 v8;
    u32 v9;
    s16 v11;
    s16 v12;
    s16 v13;
    s16 v15;
    s16 v17;
    u32 color;

    switch ((s32)lbl_3_bss_A23E0) {
    case 4:
        v1 = (s16)arg1;
        v2 = (s16)arg2;
        v4 = (s16)((u32)lbl_3_bss_A23D8 >> 2);
        color = ((arg3->unk_1 << 3) & 0x7E0);
        color |= ((arg3->unk_0 << 8) & 0xF800);
        color |= ((u32)arg3->unk_2 >> 3);
        v8 = (s16)((s16)(v1 / 4) + (s16)(v2 / 4) * v4);
        v11 = (s16)((v8 << 5) + (((s16)(v1 % 4) + ((s16)(v2 % 4) << 2)) << 1));
        v9 = color & 255;
        memset((void *)(arg0 + v11), (color >> 8) & 255, 1);
        memset((u8 *)(v11 + arg0) + 1, v9, 1);
        break;
    case 5:
        v12 = (s16)arg1;
        v13 = (s16)arg2;
        v15 = (s16)(v13 >> 2);
        v17 = (s16)(((s16)((s16)(v12 >> 2) + v15 * (s16)(lbl_3_bss_A23D8 >> 2)) << 5) +
                      (((v12 & 3) + ((v13 & 3) << 2)) << 1));
        ((u8 *)arg0)[v17] = packColor(arg3) >> 8;
        ((u8 *)arg0)[v17 + 1] = packColor(arg3);
        break;
    }
}
