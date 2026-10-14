/* Non-matching: best partial attempt (82.61% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    s16 id;
    u8 pad[2];
    u32 flags;
} SelSigEntry;

typedef struct {
    s16 key;
    u16 pad;
    u32 mask;
} SelKeyEntry;

typedef struct {
    s16 a;
    s16 b;
} SelPair;

typedef struct {
    s16 unk_0;
    u8 pad_2[2];
    s16 unk_4;
    u8 pad_6[8];
    s16 key;
    u8 pad_10[0x1E];
} SelSlot;

typedef struct {
    SelSlot slot[4];
    u8 pad_80[0x14];
    u32 flags;
    u8 pad_98[6];
    u8 index;
    u8 flag[4];
    u8 pad_A3[0xD];
    SelPair pair[4];
    u8 buf_C0[0x10];
    u8 buf_D0[0x10];
} SelState;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    s16 unk_8;
    s16 unk_A;
    u8 unk_C;
    u8 pad_D[3];
    u32 unk_10;
} Obj_10_bss_0;

extern SelState lbl_1_bss_8B3A0;
extern Obj_10_bss_0 lbl_10_bss_0;
extern s16 lbl_10_data_554;
extern u32 lbl_10_data_55C;
extern s16 lbl_1_bss_966;
extern s16 fn_1_152840(s16, SelSigEntry *, s16, s16);
extern void fn_1_A5330(u8, s16);
extern s32 fn_1_152970(s16 *, s16 *, s16, u32, SelKeyEntry *, s16, s16);
extern u32 fn_10_4AE0(u32, u32);
extern void fn_80008BEC(void *, int, void *);
extern void fn_80008BA8(u32, u32, void *);

void fn_10_4D78(void) {
    Obj_10_bss_0 *cfg = &lbl_10_bss_0;
    SelState *st = &lbl_1_bss_8B3A0;
    u8 sel = st->index;
    s16 i;

    if (st->flags & 0x0C000000) {
        u8 *fl = (u8 *)st;
        s16 *d = (s16 *)&lbl_10_data_554;
        for (i = 0; i < 4; i++) {
            s16 k = st->slot[i].key;
            if (k != -1 && (k > 0x28 || fn_1_152840(k, (SelSigEntry *)((u8 *)cfg + 0x1C), cfg->unk_A, cfg->unk_8) == 0)) {
                st->slot[i].key = d[i];
                fl[0x9F + i] = 0x32;
                fn_1_A5330(0x32, i);
            }
        }
    } else {
        SelState *b = &lbl_1_bss_8B3A0;
        u32 v;
        s16 cnt;

        if (st->slot[0].unk_4 == 0) {
            st->slot[0].key = -1;
            st->slot[1].key = -1;
            st->slot[2].key = -1;
            st->slot[3].key = -1;
            st->slot[sel].key = 6;
        }

        for (i = 0; i < 4; i++) {
            s16 k = b->slot[i].key;
            if (fn_1_152840(k, (SelSigEntry *)((u8 *)cfg + 0x1C), cfg->unk_A, cfg->unk_8) == 0) {
                if (!(lbl_1_bss_966 == 20 || lbl_1_bss_966 == 16) || k < 0x36 || k > 0x39) {
                    b->slot[i].key = -1;
                    ((u8 *)b)[0x9F + i] = 0x32;
                    fn_1_A5330(0x32, i);
                }
            } else {
                fn_1_A5330(((u8 *)b)[0x9F + i], i);
            }
        }

        if (lbl_1_bss_8B3A0.slot[sel].key == -1) {
            if (st->flags & 2) {
                lbl_1_bss_8B3A0.slot[sel].unk_0 = ((s16 *)&lbl_10_data_55C)[sel];
            } else {
                lbl_1_bss_8B3A0.slot[sel].unk_0 = ((s16 *)&lbl_10_data_554)[sel];
            }
            ((u8 *)&lbl_1_bss_8B3A0)[0x9F + sel] = 0x32;
            fn_1_A5330(0x32, sel);
        }

        cnt = 1;
        for (i = 0; i < 4; i++) {
            if (i != sel && b->slot[i].key != -1) {
                if (st->slot[0].unk_4 <= cnt) {
                    b->slot[i].key = -1;
                    ((u8 *)b)[0x9F + i] = 0x32;
                    fn_1_A5330(0x32, i);
                }
                cnt++;
            }
        }

        v = fn_10_4AE0(sel, 0);
        for (i = 0; i < 4; i++) {
            if (i != sel) {
                v = fn_10_4AE0(i, v);
            }
        }

        while ((s16)v < st->slot[0].unk_4) {
            for (i = 0; i < 4; i++) {
                if (b->slot[i].key == -1) {
                    lbl_1_bss_8B3A0.slot[i].key = ((s16 *)&lbl_10_data_554)[i];
                    v++;
                    break;
                }
            }
        }

        if (st->flags & 0x18000) {
            for (i = 0; i < 4; i++) {
                s16 k = b->slot[i].key;
                if (k != -1) {
                    fn_1_152970(&b->pair[i].a, &b->pair[i].b, k, 0xC0000000, (SelKeyEntry *)((u8 *)cfg + 0x1C), cfg->unk_A, cfg->unk_8);
                    fn_80008BEC((void *)&lbl_1_bss_8B3A0.buf_C0, 0, (void *)0x10);
                    fn_80008BA8((u32)&lbl_1_bss_8B3A0.buf_D0, (u32)&lbl_1_bss_8B3A0.pair[0], (void *)0x10);
                }
            }
        }
    }
}
