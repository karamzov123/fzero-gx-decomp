/* Non-matching: best partial attempt (98.84% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/bg_aur.h"
struct fn_1_15176C_Arg1 {
    u8 pad_0[0x10];
    f32 unk_10;
    u8 pad_14[0x20];
    s32 unk_34;
    u8 pad_38[0x4];
    s32 unk_3C;
};
struct Entry15176C {
    u8 pad_0[0x88];
    s32 unk_88;
    u8 pad_8C[4];
    s32 unk_90;
    u8 pad_94[0x18];
};
extern f32 lbl_1_rodata_CF70[54];
extern void OSPanic(const char *, int, const char *, ...);
#pragma opt_propagation off
s32 fn_1_15176C(s32 arg0, struct fn_1_15176C_Arg1 *arg1) {
    struct {
    u32 lab_pad[4]; char text[0x40]; } *table = (void *)lbl_1_data_463C8;
#define strings (table->text)
    struct Entry15176C *entry;
    Obj_1_data_2A7E0_At3C *v2;
    u8 *v15;
    u32 v0;
    f32 v1;
    if (arg1 == 0) return 1;
    v2 = lbl_1_data_2A7E0.unk_3C;
    switch (arg0) {
    case 0:
        entry = (struct Entry15176C *)((u32)v2 + ((0xAC) * (v2->unk_84)));
        entry->unk_90 |= 0x40000000;
        entry = (struct Entry15176C *)((u32)v2 + ((0xAC) * (v2->unk_84)));
        entry->unk_90 |= 0x10000000;
        entry = (struct Entry15176C *)((u32)v2 + ((0xAC) * (v2->unk_84)));
        entry->unk_88 = (u32)arg1;
        v2->unk_84++;
        if ((s32)v2->unk_84 >= 32)
            OSPanic(strings, 1346, strings + 12);
        break;
    case 1:
        entry = (struct Entry15176C *)((u32)v2 + ((0xAC) * (v2->unk_84)));
        entry->unk_90 |= 0x40000000;
        entry = (struct Entry15176C *)((u32)v2 + ((0xAC) * (v2->unk_84)));
        entry->unk_90 |= 0x20000000;
        entry = (struct Entry15176C *)((u32)v2 + ((0xAC) * (v2->unk_84)));
        entry->unk_88 = (u32)arg1;
        v2->unk_84++;
        if ((s32)v2->unk_84 >= 32)
            OSPanic(strings, 1353, strings + 12);
        break;
    case 2:
        entry = (struct Entry15176C *)((u32)v2 + ((0xAC) * (v2->unk_84)));
        entry->unk_90 |= 0x40000000;
        entry = (struct Entry15176C *)((u32)v2 + ((0xAC) * (v2->unk_84)));
        entry->unk_90 |= 0x10000000;
        entry = (struct Entry15176C *)((u32)v2 + ((0xAC) * (v2->unk_84)));
        entry->unk_90 |= 0x08000000;
        entry = (struct Entry15176C *)((u32)v2 + ((0xAC) * (v2->unk_84)));
        entry->unk_88 = (u32)arg1;
        v2->unk_84++;
        if ((s32)v2->unk_84 >= 32)
            OSPanic(strings, 1361, strings + 12);
        break;
    case 3:
        entry = (struct Entry15176C *)((u32)v2 + ((0xAC) * (v2->unk_84)));
        entry->unk_90 |= 0x40000000;
        entry = (struct Entry15176C *)((u32)v2 + ((0xAC) * (v2->unk_84)));
        entry->unk_90 |= 0x20000000;
        entry = (struct Entry15176C *)((u32)v2 + ((0xAC) * (v2->unk_84)));
        entry->unk_90 |= 0x08000000;
        entry = (struct Entry15176C *)((u32)v2 + ((0xAC) * (v2->unk_84)));
        entry->unk_88 = (u32)arg1;
        v2->unk_84++;
        if ((s32)v2->unk_84 >= 32)
            OSPanic(strings, 1369, strings + 12);
        break;
    case 4: case 5: case 6: case 7: case 8:
        v15 = (u8 *)v2 + v2->unk_2724 * 60 + 0x1824;
        arg1->unk_3C = 0;
        *(u32 *)(v15 + 0x34) = (u32)arg1;
        if (arg0 == 4 || arg0 == 5) v15[0x38] = 1;
        else if (arg0 == 6) v15[0x39] = 1;
        else if (arg0 == 7) v15[0x3A] = 1;
        else if (arg0 == 8) v15[0x3B] = 1;
        if ((s32)v2->unk_0 == 0) {
            v1 = lbl_1_rodata_CF70[0];
            *(f32 *)(v15 + 12) = arg1->unk_10;
            v0 = arg1->unk_34;
            if (v0 != 0) {
                v0 = *(u32 *)((u8 *)v0 + 0);
                if (v0 != 0)
                    *(f32 *)(v15 + 40) = *(f32 *)((u8 *)v0 + 4) / v1;
            }
            v0 = arg1->unk_34;
            if (v0 != 0) {
                v0 = *(u32 *)((u8 *)v0 + 4);
                if (v0 != 0)
                    *(f32 *)(v15 + 44) = *(f32 *)((u8 *)v0 + 4) / v1;
            }
            v0 = arg1->unk_34;
            if (v0 != 0) {
                v0 = *(u32 *)((u8 *)v0 + 8);
                if (v0 != 0)
                    *(f32 *)(v15 + 48) = *(f32 *)((u8 *)v0 + 4) / v1;
            }
        }
        v2->unk_2724++;
        if ((s32)v2->unk_2724 >= 64)
            OSPanic(strings + 0, 0x57F, strings + 32);
        break;
    }
    return 1;
}
#pragma opt_propagation reset

