/* Non-matching: best partial attempt (96.45% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car.h"

extern void fn_1_96664(s32);
extern void fn_1_956EC(s32, u32);
extern void fn_1_96130(char *);
extern int sprintf(char *, const char *, ...);
extern int fn_80083BCC(const char *, const char *);

struct car_sub_data {
    u16 unk_00;
    u16 unk_04;
    s16 unk_08;
    u32 unk_0C;
};

struct car_data {
    u8 unk_000[0x35C];
    void *unk_name[0x1656];
    u32 unk_flag[0x398];
    struct car_sub_data unk_sub[0x42];
    u32 unk_count;
    u8 unk_20[4];
    char unk_fmt0[0xC];
    char unk_fmt1[0xC];
    char unk_fmt2[0xC];
    char unk_fmt3[0xC];
    char unk_fmt4[0xC];
    char unk_fmt5[0xC];
    char unk_fmt6[8];
    char unk_fmt7[8];
    char unk_fmt8[0xC];
};

#pragma opt_propagation off
#pragma opt_strength_reduction off
#pragma opt_dead_assignments off
#pragma opt_lifetimes off
static inline struct car_sub_data *fn_1_8E4A4_array_read(struct car_sub_data *array) { return array; }
#pragma opt_loop_invariants off
void fn_1_8E4A4(s32 id, u32 attr) {
    struct { struct car_data *base; } mgr;
    s32 mask_2;
    struct { void **tbl; } nt;
    struct { u32 *tbl; } ft;
    char buf[0x38];
    u32 count;
    s32 flag;
    s32 mask;
    u32 found;
    void *name;
    u32 i, j;

    mgr.base = (struct car_data *)&lbl_1_data_209C0;
    nt.tbl = mgr.base->unk_name;
    name = nt.tbl[id];

    fn_1_96664(id);
    fn_1_956EC(id, attr);

    if (*(s16 *)&lbl_1_bss_960 == 14 && attr == 0x1000u) {
        sprintf(buf, mgr.base->unk_fmt0, name);
        fn_1_96130(buf);
    } else {
        sprintf(buf, mgr.base->unk_fmt1, name);
        fn_1_96130(buf);

        flag = 0;
        if (id == 0x15) {
            goto lbl_set;
        }
        if (id == 0x29) {
            goto lbl_set;
        }
        if (id == 0x21) {
            goto lbl_set;
        }
        if (id == 0x2a) {
            goto lbl_set;
        }
        if (id == 0x2b) {
            goto lbl_set;
        }
        goto lbl_flag;
    lbl_set:
        flag = 1;
    lbl_flag:
        mask = 0xC000;
        if (flag) {
            mask_2 = 0xE000;
        }

        if (((mask_2) & (attr))) {
            ft.tbl = mgr.base->unk_flag;
            if (ft.tbl[id] & 2) {
                sprintf(buf, mgr.base->unk_fmt2, name);
                fn_1_96130(buf);
            }
        }

        if (attr & 0xC0000000u) {
            ft.tbl = mgr.base->unk_flag;
            if (ft.tbl[id] & 4) {
                sprintf(buf, mgr.base->unk_fmt3, name);
                fn_1_96130(buf);
            }
        }

        if (attr & 0xC0000000u) {
            ft.tbl = mgr.base->unk_flag;
            if (ft.tbl[id] & 8) {
                sprintf(buf, mgr.base->unk_fmt4, name);
                fn_1_96130(buf);
            }
        }

        if (attr & 0xC0000000u) {
            ft.tbl = mgr.base->unk_flag;
            if (ft.tbl[id] & 0x10) {
                sprintf(buf, mgr.base->unk_fmt5, name);
                fn_1_96130(buf);
            }
        }

        if (attr & 0xE0000000u) {
            ft.tbl = mgr.base->unk_flag;
            if (ft.tbl[id] & 0x20) {
                for (i = 0; i < 0x14; i++) {
                    count = mgr.base->unk_count;
{
    struct car_sub_data *sp;
                    sp = mgr.base->unk_sub;
                    for (j = 0; j < count; j++) {
                        if ((u32)id == sp->unk_00 && i == sp->unk_04) {
                            found = fn_1_8E4A4_array_read(mgr.base->unk_sub)[j].unk_08;
                            goto lbl_found;
                        }
                        sp++;
}
                    }
                    found = 0;
                lbl_found:
                    sprintf(buf, mgr.base->unk_fmt6, found);
                    if (fn_80083BCC(buf, mgr.base->unk_fmt7)) {
                        fn_1_96130(buf);
                    }
                }
            }
        }
    }

    sprintf(buf, mgr.base->unk_fmt8, name);
    fn_1_96130(buf);
}
#pragma opt_loop_invariants reset

#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset

#pragma opt_strength_reduction reset

#pragma opt_propagation reset
