/* Non-matching: best partial attempt (79.43% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern void fn_1_12F128(s16);
extern s16 fn_1_12EF24(s16, s16);
extern s32 fn_1_F89E4(u8);
extern void fn_1_A2D84(u32);
extern u32 fn_1_12F358(u32);
extern void fn_1_7B2E8(u32);

struct SelGlobal {
    s16 value;
    u8 pad_2[0x8A];
    s16 unk_8C;
    s16 unk_8E;
    s16 unk_90;
    u8 pad_92[2];
    u32 unk_94;
    u32 unk_98;
    s16 unk_9C;
};

struct SelD58 {
    u8 pad_0[2];
    u16 unk_2;
};

struct SelEntA {
    u8 pad_0[0xA];
    s8 unk_A;
    u8 pad_B[1];
};

struct SelEntB {
    u8 pad_0[0x10];
    u16 unk_10;
    u16 unk_12;
};

struct SelArg {
    u8 pad_0[0x8C];
    s16 unk_8C;
    s16 unk_8E;
    s16 unk_90;
    u8 pad_92[2];
    u32 unk_94;
    u8 pad_98[0x60];
};

extern struct SelGlobal lbl_1_bss_8B3A0;
extern struct SelD58 lbl_1_bss_D58;
extern struct SelEntA lbl_1_bss_9C8[4];
extern struct SelEntB lbl_1_bss_9F8[4];
extern s8 lbl_10_data_2B4[0x1A0];

void fn_10_AE14(struct SelArg *ap) {
    s32 count = 0;
    s32 cur;
    s16 prev;
    s32 idx;
    s16 step;
    s16 n;
    s16 i;
    s16 j;
    s16 acc;
    s32 t;
    s8 cnt;

    for (i = 0; i < 4; i++) {
        if (lbl_1_bss_9C8[i].unk_A == -1) {
            continue;
        }
        if ((lbl_1_bss_8B3A0.unk_98 << (i + 1)) & 0x80000000) {
            continue;
        }
        if ((lbl_1_bss_9F8[i].unk_10 & 0x00000002) ||
            (lbl_1_bss_9F8[i].unk_12 & 0x00000002)) {
            count--;
        }
        if (lbl_1_bss_9F8[i].unk_10 & 0x00000002) {
            count++;
        } else if (lbl_1_bss_9F8[i].unk_12 & 0x00000002) {
            count++;
        }
        if (lbl_1_bss_9F8[i].unk_10 & 0x00000002) {
            fn_1_12F128(i);
        } else if (lbl_1_bss_9F8[i].unk_12 & 0x00000002) {
            fn_1_12F128(i);
        } else if (lbl_1_bss_9F8[i].unk_10 & 0x80000000) {
            fn_1_12F128(i);
        } else if (lbl_1_bss_9F8[i].unk_12 & 0x80000000) {
            fn_1_12F128(i);
        }
    }

    if (lbl_1_bss_8B3A0.value == 1) {
        count = 0;
    }

    cur = count;
    prev = ap->unk_90;

    if (ap->unk_8C == 0) {
        s16 w = count;

        if (prev < 0) {
            idx = 0;
        } else if (prev > 0x6e) {
            idx = 0x6e;
        } else {
            idx = prev;
        }
        if ((ap->unk_94 & 0x00000002) != 0 && w == 0 &&
            lbl_10_data_2B4[idx] == 0) {
            w = 1;
        }
        step = (w < 0) ? -1 : 0;
        n = (w < 0) ? -w : w;
        while (--n > 0) {
            t = idx + step;
            if (t > 0x6e) {
                idx = 0;
            } else if (t < 0) {
                idx = 0x6e;
            } else {
                idx = t;
            }
            if ((ap->unk_94 & 0x00000002) == 0) {
                break;
            }
            while (lbl_10_data_2B4[idx] == 0) {
                t = idx + step;
                if (t > 0x6e) {
                    idx = 0;
                } else if (t < 0) {
                    idx = 0x6e;
                } else {
                    idx = t;
                }
            }
        }
        ap->unk_8E = idx;
        ap->unk_90 = ap->unk_8E;
    } else {
        for (cnt = 0; cnt < 6; cnt++) {
            s32 flag = 0;

            t = ap->unk_8E + cur;
            if (t > 5) {
                t = 0;
            } else if (t < 0) {
                t = 5;
            }
            ap->unk_8E = t;
            ap->unk_90 = fn_1_12EF24(ap->unk_8C, ap->unk_8E);
            if (ap->unk_90 == -1 && cur == 0) {
                cur = 1;
            }
            if (ap->unk_8C == 5) {
                if (ap->unk_8E == 5) {
                    if (fn_1_F89E4(0) == 0) {
                        flag = 1;
                        if (cur == 0) {
                            cur = 1;
                        }
                    }
                } else if (fn_1_F89E4((u8)(ap->unk_8E + 1)) == 0) {
                    flag = 1;
                    if (cur == 0) {
                        cur = 1;
                    }
                }
            }
            if (ap->unk_90 != -1 && lbl_10_data_2B4[ap->unk_90] != 0 &&
                flag == 0) {
                break;
            }
        }
    }

    if (prev != ap->unk_90) {
        fn_1_A2D84(0xA9010000);
    }
    fn_1_12F358(ap->unk_90);

    if (lbl_1_bss_8B3A0.value == 10) {
        acc = 0;
        for (j = 0; j < 4; j++) {
            if (lbl_1_bss_9C8[j].unk_A == -1) {
                continue;
            }
            if ((lbl_1_bss_8B3A0.unk_98 << (j + 1)) & 0x80000000) {
                continue;
            }
            if (lbl_1_bss_9F8[j].unk_12 & 0x00000100) {
                acc--;
            }
            if (lbl_1_bss_9F8[j].unk_12 & 0x00000200) {
                acc++;
            }
            if (lbl_1_bss_9F8[j].unk_12 & 0x00000200) {
                fn_1_12F128(j);
            } else if (lbl_1_bss_9F8[j].unk_12 & 0x00000100) {
                fn_1_12F128(j);
            }
        }
        if (acc != 0) {
            t = lbl_1_bss_8B3A0.unk_9C + acc;
            if (t > 3) {
                t = 0;
            } else if (t < 0) {
                t = 3;
            }
            lbl_1_bss_8B3A0.unk_9C = t;
            fn_1_A2D84(0xA9010000);
        }
        if (lbl_1_bss_8B3A0.unk_9C == 3 &&
            (lbl_1_bss_D58.unk_2 & 0x00000100)) {
            lbl_1_bss_8B3A0.unk_9C = 5;
        }
        if (lbl_1_bss_8B3A0.unk_9C == 5 &&
            !(lbl_1_bss_D58.unk_2 & 0x00000100)) {
            lbl_1_bss_8B3A0.unk_9C = 3;
        }
    }

    if (count != 0 && !(ap->unk_94 & 0x80000000)) {
        fn_1_7B2E8(ap->unk_90);
    }
}
