/* Non-matching: best partial attempt (97.56% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/font.h"

typedef struct FontElement {
    s32 unk_0;
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[0x2];
    u32 unk_8;
    s32 unk_C;
    s8 unk_10;
    s8 unk_11;
    u8 pad_12[0x2];
    f32 unk_14;
    f32 unk_18;
    u8 pad_1C[0x10];
    u16 *unk_2C;
    s16 *unk_30;
    f32 unk_34;
} FontElement;

typedef struct AppState {
    u8 unk_0;
    u8 unk_1;
    s8 unk_2;
    u8 unk_3;
    u8 unk_4;
    u8 pad_5[0x3];
    s32 unk_8;
} AppState;

extern u16 lbl_1_bss_D58[12];
extern u16 lbl_1_bss_96A;
extern void fn_1_48C28(int);
extern u32 fn_1_48A0C(s32, s8, void *, u32);
extern void fn_1_48140(u16);
extern void fn_1_47F74(u16);
extern u32 fn_1_4C16C(void);

#pragma opt_dead_assignments off
void fn_1_4BD4C(u32 unused0, u32 unused1, u32 unused2) {
    u8 *fzgx_value;
    u16 *p_d58;
    s32 page_size;
    FontElement *elem;
    s32 cols;
    s32 rows;
    FontElement *elem2;
    u16 *p25;
    s32 i;
    s8 idx;
    s32 offset;
    u8 prev_unk_0;
    u8 prev_unk_4;
    s32 prev_unk_8;
    s32 count;
    s8 max_page;
    AppState *sp30;

    sp30 = (AppState *)&lbl_1_bss_4BB30;
    if (((FontElement *)&lbl_1_data_1AEA8)[(s8)sp30->unk_0].unk_0 == -1) {
        cols = 16;
        rows = 8;
    } else {
        cols = ((FontElement *)&lbl_1_data_1AEA8)[(s8)sp30->unk_0].unk_10;
        rows = ((FontElement *)&lbl_1_data_1AEA8)[(s8)sp30->unk_0].unk_11;
    }

    prev_unk_0 = (s8)(*(u8 volatile *)&(sp30->unk_0)) /* Retail reloads this field. */;
    p_d58 = lbl_1_bss_D58;

    if (((p_d58[8] >> 1) & 1) != 0) {
        if ((s8)++sp30->unk_0 > 43) {
            sp30->unk_0 = 0;
        }
    }
    if ((p_d58[8] & 1) != 0) {
        if ((s8)--sp30->unk_0 < 0) {
            sp30->unk_0 = 43;
        }
    }

    elem = &((FontElement *)&lbl_1_data_1AEA8)[(s8)sp30->unk_0];
    if (prev_unk_0 != (s8)sp30->unk_0) {
        sp30->unk_4 = 0;
        if (elem->unk_0 == -1) {
            fn_1_48C28((s8)sp30->unk_1);
            idx = sp30->unk_0;
            elem2 = &((FontElement *)&lbl_1_data_1AEA8)[idx];
            if (elem2->unk_0 == -1) {
                i = 0;
#pragma opt_propagation off
                offset = i;
#pragma opt_propagation reset
                p25 = elem2->unk_2C;
                for (; *p25 != 0; offset += 2, i++, p25++) {
                    if (*(s16 *)((u8 *)elem2->unk_30 + offset) == -1) {
                        fn_1_48A0C(i, idx, elem2, 0);
                    }
                }
            }
        } else {
            fn_1_48140(((u32)((FontElement *)&lbl_1_data_1AEA8)[(s8)sp30->unk_1].unk_0 >> 8) & 0xFFFF);
            fn_1_47F74(((u32)elem->unk_0 >> 8) & 0xFFFF);
        }
        sp30->unk_1 = sp30->unk_0;
    }

    if (elem->unk_0 == -1) {
        page_size = cols * rows;
        prev_unk_4 = sp30->unk_4;
        max_page = ((s32 *)&lbl_1_bss_40BBC)[(s8)sp30->unk_0] / page_size;
        if (((p_d58[8] >> 2) & 1) != 0) {
            if ((s8)++(*(u8 volatile *)&(sp30->unk_4)) /* Retail reloads this field. */ > max_page) {
                sp30->unk_4 = 0;
            }
        }
        if (((p_d58[8] >> 3) & 1) != 0) {
            if ((s8)--sp30->unk_4 < 0) {
                fzgx_value = &(sp30->unk_4);
                *fzgx_value = max_page;
            }
        }
        if (prev_unk_4 != (s8)sp30->unk_4) {
            if ((s8)sp30->unk_4 != sp30->unk_8 / page_size) {
                sp30->unk_8 = (s8)sp30->unk_4 * page_size;
            }
        }
    }

    prev_unk_8 = sp30->unk_8;
    if (elem->unk_0 == -1) {
        count = ((s32 *)&lbl_1_bss_40BBC)[(s8)sp30->unk_0];
    } else {
        count = elem->unk_C + 1;
    }

    if (((lbl_1_bss_D58[9] >> 5) & 1) != 0) {
        if (++sp30->unk_8 > count - 1) {
            sp30->unk_8 = 0;
        }
    }
    if (((lbl_1_bss_D58[9] >> 4) & 1) != 0) {
        if (--sp30->unk_8 < 0) {
            sp30->unk_8 = count - 1;
        }
    }
    if (((lbl_1_bss_D58[9] >> 6) & 1) != 0) {
        sp30->unk_8 += cols;
        if (sp30->unk_8 > count - 1) {
            sp30->unk_8 %= cols;
        }
    }
    if (((lbl_1_bss_D58[9] >> 7) & 1) != 0) {
        sp30->unk_8 -= cols;
        if (sp30->unk_8 < 0) {
            sp30->unk_8 = (sp30->unk_8 % cols) + ((count - 1) / cols + 1) * cols;
        }
        if (sp30->unk_8 > count - 1) {
            sp30->unk_8 -= cols;
        }
    }

    if (prev_unk_8 != sp30->unk_8) {
        s32 page = sp30->unk_8 / (((rows) * (cols)));
        if (((page) != ((s8)sp30->unk_4))) {
            sp30->unk_4 = page;
        }
    }

    if (elem->unk_0 == -1) {
        if (((lbl_1_bss_D58[4] >> 10) & 1) != 0) {
            sp30->unk_2 ^= 1;
        }
        if (((lbl_1_bss_D58[4] >> 11) & 1) != 0) {
            if ((s8)++sp30->unk_3 == 6) {
                sp30->unk_3 = 0;
            }
        }
    }

    if (((lbl_1_bss_D58[4] >> 12) & 1) != 0) {
        lbl_1_bss_96A = 52;
    }

    fn_1_4C16C();
}
#pragma opt_dead_assignments reset

