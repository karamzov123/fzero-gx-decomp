/* Non-matching: best partial attempt (97.02% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_15_2458_Entry {
    u8 pad_0[6];
    u8 unk_6;
    u8 pad_7;
};

struct fn_15_2458_bss {
    u8 pad_0[0x14];
    u32 unk_14;
    u8 pad_18[0x14];
    struct fn_15_2458_Entry *unk_2C;
    u8 pad_30[0x44];
    u32 unk_74;
    u32 unk_78;
    u8 pad_7C[0x20];
    u32 unk_9C[8];
};

struct fn_15_2458_data {
    u8 pad_0[0x20];
    s32 unk_20[1];
    u8 pad_24[0x80];
    u32 unk_A4;
    u8 pad_A8[0x110];
    u32 unk_1B8;
    u32 unk_1BC;
    u32 unk_1C0;
    u8 pad_1C4[0xC];
    u32 unk_1D0;
};

struct fn_15_2458_Car {
    u8 pad_0[0x18];
    u32 unk_18;
    u8 pad_1C[0x12C];
    u32 unk_148;
    u8 pad_14C[0x378];
    u8 unk_4C4;
};

typedef void (*fn_15_2458_CB)(void);

extern struct fn_15_2458_bss lbl_15_bss_0;
extern struct fn_15_2458_data lbl_15_data_0;
extern u32 lbl_801A6410;
extern u32 fn_1_4630(u32, u32, u32, u32);
extern void fn_1_8F198(struct fn_15_2458_Car *, s16, u32, u32);
extern void fn_1_8F45C(struct fn_15_2458_Car *, s16, u32, u32);
extern void fn_1_934CC(struct fn_15_2458_Car *, void *, u32);
extern u32 fn_1_435C(u32);
extern void fn_1_3F8C(void *, fn_15_2458_CB, void *, u32);
extern void fn_1_8F62C(void);
extern void fn_15_27D4(void);
extern void fn_1_92530(void);

#pragma opt_propagation off
static inline void fn_15_2458_call_fn_1_934CC(u32 a2, void * a1, struct fn_15_2458_Car * a0) { fn_1_934CC(a0, a1, a2); }
static inline u32 fn_15_2458_array_read(u32 *array, s32 index) { return array[index]; }
#pragma opt_dead_assignments off
void fn_15_2458(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    struct fn_15_2458_bss *p_bss;
    struct fn_15_2458_data *p_data;
    u32 v_clz;
    u32 *tab2;
    u32 res;
    u32 off;
    u32 *tab;
    s16 v_idx;
    struct fn_15_2458_Car *car;
    fn_15_2458_CB lab_t1;

    p_data = &lbl_15_data_0;
    p_bss = &lbl_15_bss_0;
    v_idx = (s16)arg2;
    v_clz = (0x1F - __cntlzw(p_bss->unk_2C[v_idx].unk_6)) & 3;
    switch ((s32)v_clz) {
    case 0:
        arg4 = 0x80000000;
        break;
    case 1:
        arg4 = 0x40000000;
        break;
    case 2:
        arg4 = 0x20000000;
        break;
    case 3:
        arg4 = 0x10000000;
        break;
    default:
        arg4 = 0x80000000;
        break;
    }
    res = fn_1_4630(lbl_801A6410, 0x4E0, (u32)&p_data->unk_A4, 0x719);
    off = (u32)((s16)arg1) << 2;
    tab = (u32 *)((u8 *)p_bss + 0x9C);
    *(u32 *)((u8 *)tab + off) = res;
    car = (struct fn_15_2458_Car *)(*(u32 *)((u8 *)tab + off));
    if (arg3 == 0x30000000) {
        if ((p_bss->unk_14 & 0x80) != 0) {
            fn_1_8F45C(car, (s16)arg0, arg3, arg4);
        } else {
            fn_1_8F198(car, (s16)arg0, arg3, arg4);
        }
    } else {
        fn_1_8F198(car, (s16)arg0, arg3, arg4);
    }
    tab2 = (u32 *)((u8 *)p_data + 0x20);
    fn_15_2458_call_fn_1_934CC(fn_15_2458_array_read(tab2, v_idx), &car->unk_148, car);
    car->unk_18 |= 0xC0000000;
    car->unk_4C4 = (u8)arg2;
    fn_1_435C(p_bss->unk_74);
    fn_1_3F8C(&p_data->unk_1B8, fn_1_8F62C, car, 0xA);
    lab_t1 = fn_15_27D4;
    fn_1_3F8C(&p_data->unk_1C0, lab_t1, car, 0xB);
    fn_1_435C(p_bss->unk_78);
    fn_1_3F8C(&p_data->unk_1D0, fn_1_92530, car, 0xA);
}
#pragma opt_dead_assignments reset

#pragma opt_propagation reset
