/* Non-matching: best partial attempt (98.18% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/editor.h"

typedef struct {
    u32 unk_0;
    u8 pad_4[0x18];
    u8 unk_1C;
} Obj_18614;

typedef void (*Fn_18614)(Obj_18614 *);

extern u16 lbl_1_bss_9F8[];
extern struct Obj *fn_3_14074(void);
extern u8 fn_3_19C94(void);
extern void fn_3_19CB8(void);
extern void fn_3_19CCC(void);
extern void fn_3_1560C(void);
extern void fn_3_15620(void);
extern void fn_1_A2D84(u32);

void fn_3_18614(void) {
    Obj_18614 *obj = (Obj_18614 *)fn_3_14074();
    int v = fn_3_19C94();
    u32 flags;
    int c;
    u8 k;
    u16 *pad;
    int offset;

    obj->unk_1C = v;
    if (lbl_3_bss_A2438.unk_4 & 0x20000000u) {
        return;
    }
    if (v < 18) {
        if (v >= 11) {
            ((Fn_18614 *)&lbl_3_data_3738)[v](obj);
            return;
        }
    }

    {
        int port = lbl_3_bss_A2438.unk_0;
        flags = *(u16 *)((u8 *)((u16)((u16 *)((u8 *)lbl_1_bss_9F8 + 8))) + port * 20);
    }
    if ((flags >> 8) & 1) {
        fn_1_A2D84(0xA9150400u);
        c = lbl_3_bss_A2438.unk_F;
        k = *(u16 *)((u8 *)&lbl_3_data_3618 + c * 0x10);
        lbl_3_bss_A2438.unk_E = k;
        if (k == 6) {
            ((Fn_18614 *)&lbl_3_data_3738)[c](obj);
            return;
        }
        if ((u8)(k - 11) <= 1 || (u8)(k - 14) <= 3 || k == 13) {
            return;
        }
        if (k == 0 || k == 1) {
            fn_3_19CB8();
            fn_3_15620();
        } else {
            fn_3_19CB8();
            fn_3_1560C();
        }
    } else if ((flags >> 9) & 1) {
        fn_1_A2D84(0xA9150500u);
        fn_3_19CCC();
        lbl_3_bss_A2438.unk_8 |= 0x40000000u;
        obj->unk_0 |= 0x10000000u;
        lbl_3_bss_A2438.unk_10 = 0;
        lbl_3_bss_A2438.unk_E = 0x11;
        return;
    }

    offset = lbl_3_bss_A2438.unk_0 * 20;
    pad = (u16 *)((u8 *)lbl_1_bss_9F8 + 0x10);
    if ((*(u16 *)((u8 *)pad + offset) & 1) || (*(u16 *)((u8 *)lbl_1_bss_9F8 + offset + 0x12) & 1)) {
        c = lbl_3_bss_A2438.unk_F;
        if (c % 3 != 0) {
            lbl_3_bss_A2438.unk_F = c - 1;
            fn_1_A2D84(0xA9150600u);
        }
    }
    offset = lbl_3_bss_A2438.unk_0 * 20;
    if (((*(u16 *)((u8 *)pad + offset) >> 1) & 1) || ((*(u16 *)((u8 *)lbl_1_bss_9F8 + offset + 0x12) >> 1) & 1)) {
        c = lbl_3_bss_A2438.unk_F;
        if (c % 3 < 2) {
            fn_1_A2D84(0xA9150600u);
            lbl_3_bss_A2438.unk_F++;
        }
    }
    offset = lbl_3_bss_A2438.unk_0 * 20;
    if (((*(u16 *)((u8 *)pad + offset) >> 3) & 1) || ((*(u16 *)((u8 *)lbl_1_bss_9F8 + offset + 0x12) >> 3) & 1)) {
        c = lbl_3_bss_A2438.unk_F;
        if (c - 3 >= 0) {
            fn_1_A2D84(0xA9150600u);
            lbl_3_bss_A2438.unk_F -= 3;
        }
    }
    offset = lbl_3_bss_A2438.unk_0 * 20;
    if (((*(u16 *)((u8 *)pad + offset) >> 2) & 1) || ((*(u16 *)((u8 *)lbl_1_bss_9F8 + offset + 0x12) >> 2) & 1)) {
        c = lbl_3_bss_A2438.unk_F;
        if (c + 3 < 18) {
            fn_1_A2D84(0xA9150600u);
            lbl_3_bss_A2438.unk_F += 3;
        }
    }
}
