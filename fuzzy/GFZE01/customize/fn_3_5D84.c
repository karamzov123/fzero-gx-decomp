/* Non-matching: best partial attempt (90.69% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    s32 unk_0;
    u8 pad_4[1];
    u8 unk_5;
    u8 pad_6[0x81BA];
} Obj;

typedef struct {
    s32 unk_0;
    u8 pad_4[0x320];
    s32 value;
    u8 tail[0x118];
} Entry;

typedef struct {
    u8 pad[0x18a4];
    u8 blk_18a4[1];
    u8 pad_18a5[0xB];
    u8 blk_18b0[1];
    u8 pad_18b1[0xF];
    u8 blk_18c0[1];
} Data;

extern Obj lbl_3_bss_140[1];
extern Entry lbl_3_bss_20860[4];
extern u8 lbl_3_bss_21960[10368];
extern u32 lbl_3_bss_20848;
extern u32 lbl_1_bss_6D82C;
extern Data lbl_3_data_0;

extern s32 fn_1_80CC4(s32, s32, s32, void *);
extern void fn_1_12AB38(void *);
extern u32 fn_1_D3884(void *);
extern void fn_1_14DB48(void *, void *, u32);

#pragma opt_lifetimes off
#pragma opt_loop_invariants off
void fn_3_5D84(s32 arg0) {
    s16 i;
    Obj *a;
    Entry *e;
    Data *d;

    i = (s16)arg0;
    d = &lbl_3_data_0;
    a = &lbl_3_bss_140[i];
    e = &lbl_3_bss_20860[i];
    e->value = -1;
    if (__rlwinm(a->unk_0, 0, 0, 0)) {
        if (!__rlwinm(a->unk_0, 0, 1, 1)) {
            e->value = (s16)fn_1_80CC4(a->unk_5, 1, 0, e);
        } else {
            if (lbl_1_bss_6D82C == 0) {
                fn_1_12AB38(d->blk_18a4);
                lbl_1_bss_6D82C = fn_1_D3884(d->blk_18b0);
                fn_1_12AB38(d->blk_18c0);
            }
            fn_1_14DB48(a, (void *)(lbl_3_bss_21960 + i * 0xa20), 1 << lbl_3_bss_20848);
        }
    }
}
#pragma opt_loop_invariants reset

#pragma opt_lifetimes reset
