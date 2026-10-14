/* Non-matching: best partial attempt (95.20% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u16 v[5];
} Row_1_8DD54;

typedef struct {
    u8 pad[0x3BA];
    s16 unk_3BA;
    u8 pad2[0x440 - 0x3BC];
} Obj_1_8DD54;

struct fn_1_8DD54_lbl_1_bss_6D820 {
    u8 pad_0[0x18];
    u8 *unk_18;
    u8 *unk_1C;
    u8 pad_20[0xA];
    s8 unk_2A;
    u8 pad_2B[9];
    u8 unk_34;
    u8 pad_35[0x160 - 0x35];
    u8 flag[0x100C - 0x160];
    Row_1_8DD54 row[64];
};

typedef struct {
    u32 unk_0;
    u8 pad_4[5];
    u8 unk_9;
    u8 pad_A[0x14C0 - 0x12];
    u64 pad_18;
} Loc_1_8DD54;

extern f32 lbl_1_rodata_3CB0[33];
extern f32 lbl_1_rodata_3E30[6];
extern f32 lbl_1_data_1FFE0;
extern struct fn_1_8DD54_lbl_1_bss_6D820 lbl_1_bss_6D820;
extern void fn_1_3EF14(void *);
extern s32 fn_1_58C4(void);
extern s32 fn_1_7B054(void);
extern s32 fn_1_3F0C8(void);
extern s32 fn_1_3FC18(void);
extern s32 fn_1_84408(Obj_1_8DD54 *);
extern void fn_1_8E084(Obj_1_8DD54 *, void *, u32);

#pragma opt_propagation on
#pragma opt_loop_invariants off
void fn_1_8DD54(void) {
    struct { struct fn_1_8DD54_lbl_1_bss_6D820 *value; } p;
    Loc_1_8DD54 loc;
    u32 total;
    Row_1_8DD54 *rows;
    s16 val_2;
    s16 val;
    s32 i1;
    Obj_1_8DD54 *obj1;
    s32 i2;
    Obj_1_8DD54 *obj2;
    s32 i3;
    Obj_1_8DD54 *obj3;
    s32 i4;
    Obj_1_8DD54 *obj4;
    s32 limit;

    p.value = &lbl_1_bss_6D820;
    fn_1_3EF14(&loc);
    total = 0;
    switch (fn_1_58C4()) {
    case 3:
        limit = 0x258;
        break;
    case 1: {
        s16 v = (s16)fn_1_7B054();
        if (v == 0x28) {
            limit = 0x834;
        } else if (v == 0x19) {
            limit = 0x514;
        } else {
            limit = 0x640;
        }
        break;
    }
    case 2:
        limit = 0x640;
        break;
    default:
        limit = 0x258;
        break;
    }
    if ((loc.unk_0 & 0x4000) != 0 && ((s16)fn_1_3F0C8() == 0x28 || (s32)fn_1_3FC18() > 0)) {
        lbl_1_data_1FFE0 = lbl_1_rodata_3E30[0];
    } else {
        lbl_1_data_1FFE0 = lbl_1_rodata_3CB0[0];
    }
    rows = p.value->row;
    for (i1 = 0; i1 < (s32)loc.unk_9; i1++) {
        if ((s8)i1 < p.value->unk_2A && p.value->unk_1C != 0) {
            obj1 = (Obj_1_8DD54 *)(p.value->unk_1C + (s8)i1 * 0x440);
        } else {
            obj1 = 0;
        }
        obj1->unk_3BA = (s8)fn_1_84408(obj1);
        val = obj1->unk_3BA;
        if (val != 5 && p.value->unk_18[i1 * 0x620 + 0x50D] >= 0xF0) {
            obj1->unk_3BA = 3;
            total += 0x32;
        } else if (val != 5) {
            total += rows[i1].v[val];
        }
    }
    if (total > (u32)limit || p.value->unk_34 != 0) {
        u8 *flags = p.value->flag;
        for (i2 = 0; i2 < (s32)loc.unk_9; i2++) {
            if ((s8)i2 < p.value->unk_2A && p.value->unk_1C != 0) {
                obj2 = (Obj_1_8DD54 *)(p.value->unk_1C + (s8)i2 * 0x440);
            } else {
                obj2 = 0;
            }
            if (flags[i2] != 0) {
                val = obj2->unk_3BA;
                total -= rows[i2].v[val];
                obj2->unk_3BA = 5;
            }
        }
        if (total > (u32)limit) {
            for (i3 = 0; i3 < (s32)loc.unk_9; i3++) {
                if ((s8)i3 < p.value->unk_2A && p.value->unk_1C != 0) {
                    obj3 = (Obj_1_8DD54 *)(p.value->unk_1C + (s8)i3 * 0x440);
                } else {
                    obj3 = 0;
                }
                val_2 = obj3->unk_3BA;
                if (val_2 > 0 && val_2 < 3) {
                    fn_1_8E084(obj3, &total, i3);
                }
            }
            if (total > (u32)limit) {
                for (i4 = 0; i4 < (s32)loc.unk_9; i4++) {
                    if ((s8)i4 < p.value->unk_2A && p.value->unk_1C != 0) {
                        obj4 = (Obj_1_8DD54 *)(p.value->unk_1C + (s8)i4 * 0x440);
                    } else {
                        obj4 = 0;
                    }
                    if (obj4->unk_3BA == 0) {
                        fn_1_8E084(obj4, &total, i4);
                    }
                }
            }
        }
    }
}
#pragma opt_loop_invariants reset

#pragma opt_propagation reset
