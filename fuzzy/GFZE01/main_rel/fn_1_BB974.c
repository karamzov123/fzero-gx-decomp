/* Non-matching: best partial attempt (91.71% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/memcard.h"

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 pad_2[2];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
} MemcardSlot;

typedef struct {
    u32 unk_0;
    u32 unk_4;
} MemcardPair;

extern MemcardPair lbl_1_bss_7A39C[254];

void fn_1_BB974(void) {
    MemcardSlot *slot;
    MemcardPair *pair;
    MemcardSlot tmp;
    MemcardPair aux;
    s32 j, k;
    s32 num, cnt, cnt4, cnt5;
    s32 i;
    MemcardSlot *p;

    slot = (MemcardSlot *)&lbl_1_bss_77380;
    pair = lbl_1_bss_7A39C;
    for (i = 0; i < 2; i++) {
        num = 0;
        for (j = 0, p = slot; j < 127; j++, p++) {
            if (p->unk_24 != 0) {
                num++;
            }
        }
        for (j = 0; j < num - 1; j++) {
            for (k = j + 1; k < num; k++) {
                if (slot[j].unk_1 != 2 && slot[k].unk_1 == 2) {
                    tmp = slot[j];
                    aux = pair[j];
                    slot[j] = slot[k];
                    pair[j] = pair[k];
                    slot[k] = tmp;
                    pair[k] = aux;
                }
            }
        }
        cnt = 0;
        for (j = 0, p = slot; j < 127; j++, p++) {
            if (p->unk_1 == 2) {
                cnt++;
            }
        }
        for (j = cnt; j < num - 1; j++) {
            for (k = j + 1; k < num; k++) {
                if (slot[j].unk_1 != 4 && slot[k].unk_1 == 4) {
                    tmp = slot[j];
                    aux = pair[j];
                    slot[j] = slot[k];
                    pair[j] = pair[k];
                    slot[k] = tmp;
                    pair[k] = aux;
                }
            }
        }
        cnt = 0;
        for (j = 0, p = slot; j < 127; j++, p++) {
            if (p->unk_1 == 2) {
                cnt++;
            }
        }
        for (j = 0; j < cnt - 1; j++) {
            for (k = j + 1; k < cnt; k++) {
                if (slot[j].unk_28 > slot[k].unk_28) {
                    tmp = slot[j];
                    aux = pair[j];
                    slot[j] = slot[k];
                    pair[j] = pair[k];
                    slot[k] = tmp;
                    pair[k] = aux;
                }
            }
        }
        cnt4 = 0;
        for (j = 0, p = slot; j < 127; j++, p++) {
            if (p->unk_1 == 4) {
                cnt4++;
            }
        }
        for (j = cnt; j < cnt + cnt4 - 1; j++) {
            for (k = j + 1; k < cnt + cnt4; k++) {
                if (slot[j].unk_28 > slot[k].unk_28) {
                    tmp = slot[j];
                    aux = pair[j];
                    slot[j] = slot[k];
                    pair[j] = pair[k];
                    slot[k] = tmp;
                    pair[k] = aux;
                }
            }
        }
        cnt += cnt4;
        cnt5 = 0;
        for (j = 0, p = slot; j < 127; j++, p++) {
            if (p->unk_1 == 5) {
                cnt5++;
            }
        }
        for (j = cnt; j < cnt + cnt5 - 1; j++) {
            for (k = j + 1; k < cnt + cnt5; k++) {
                if (slot[j].unk_28 > slot[k].unk_28) {
                    tmp = slot[j];
                    aux = pair[j];
                    slot[j] = slot[k];
                    pair[j] = pair[k];
                    slot[k] = tmp;
                    pair[k] = aux;
                }
            }
        }
        slot = (MemcardSlot *)((u8 *)slot + 0x1800);
        pair = (MemcardPair *)((u8 *)pair + 0x3F8);
    }
}
