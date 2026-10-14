/* Non-matching: best partial attempt (83.63% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/profile/data/lbl_16_data_0.h"

extern const f32 lbl_16_rodata_0[18];
extern ProfileTextData lbl_16_data_0;

extern u32 lbl_16_bss_150;
extern u32 lbl_16_bss_B0B4;
extern u32 lbl_16_bss_21C;

extern void fn_16_6B24(void);
extern u32 fn_1_435C(u32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern s16 fn_1_80CC4(s32, s32, s32, void *);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_12AB38(void *);
extern void fn_1_80270(void *, void *);
extern void fn_800713E0(void *, void *);
extern void fn_1_8019C(void *);
extern void fn_1_47F74(s32);

struct Fn_16_1D18_State {
    u8 pad_0[0xC];
    s16 idx;
    f32 pos0;
    f32 pos1;
    f32 pos2;
    f32 pos3;
    f32 pos4;
    f32 pos5;
    s16 flag_a;
    s16 flag_b;
    u32 unk_2C;
    s16 sel_30;
    u8 pad_32[0x1A];
    u32 flags;
    u16 unk_50;
    u16 unk_52;
    u16 unk_54;
    u8 pad_58[4];
    u32 group;
};

struct Fn_16_1D18_Grp {
    s32 v0;
    u8 pad_4[8];
};

struct Fn_16_1D18_Slot {
    u8 pad_0[0x324];
    s32 value_324;
    u8 pad_328[0x10];
    struct Fn_16_1D18_Grp grp[5];
    u8 pad_374[8];
    s32 table_37C[49];
};

struct Fn_16_1D18_Req {
    u16 idx_a;
    u16 idx_b;
    u32 pad_4;
    u8 flag;
    u8 pad_9[0x17];
};

extern struct Fn_16_1D18_State lbl_1_bss_8B614;
extern struct Fn_16_1D18_Slot lbl_16_bss_220[];

void fn_16_1D18(void) {
    u8 *tables = (u8 *)&lbl_16_data_0 + 0x80000;
    const f32 *pool = lbl_16_rodata_0;
    struct Fn_16_1D18_State *state;
    struct Fn_16_1D18_Slot *slot;
    struct Fn_16_1D18_Req req;
    s16 idx;
    u32 t2;
    u8 *grp_base;

    fn_1_435C(lbl_16_bss_150);
    fn_1_4A00(1, 15, lbl_16_bss_150);
    lbl_16_bss_B0B4 = 0;
    t2 = fn_1_3F8C((u32)(tables + 0x2D84), (u32)fn_16_6B24, 0, 8);

    state = &lbl_1_bss_8B614;
    idx = state->idx;
    slot = &lbl_16_bss_220[idx];
    *(u32 *)(tables + 0x2B00) = t2;
    lbl_16_bss_21C = -1;

    state->pos0 = pool[0];
    state->pos1 = pool[16];
    state->pos2 = pool[17];
    state->pos3 = pool[0];
    state->pos4 = pool[16];
    state->pos5 = pool[0];
    state->flag_a = 0x14A;
    state->flag_b = 0x14A;

    lbl_16_bss_220[idx].value_324 = (s16)fn_1_80CC4((s32)idx, 0, 0, slot);

    fn_80008BEC(&req, 0, 0x20);
    req.idx_b = idx;
    req.pad_4 = 0;
    req.flag = 0xF;
    req.idx_a = idx;
    fn_1_12AB38(tables + 0x2D24);
    fn_1_80270(&req, (void *)slot);
    fn_1_12AB38(tables + 0x2D30);

    grp_base = (u8 *)lbl_16_bss_220 + 0x338;
    fn_800713E0(*(void **)(grp_base + state->idx * 0x440 + lbl_1_bss_8B614.group * 0xC),
                *(void **)((u8 *)&lbl_16_bss_220[state->idx] + 0x37C + lbl_1_bss_8B614.sel_30 * 4));

    fn_1_8019C(*(void **)(grp_base + state->idx * 0x440 + lbl_1_bss_8B614.group * 0xC));

    fn_1_47F74(((s32 *)(tables + 0x2B54))[state->idx]);

    lbl_1_bss_8B614.flags = 0;
    lbl_1_bss_8B614.flags |= 0x80000000;
    lbl_1_bss_8B614.flags |= 0x10000000;
    lbl_1_bss_8B614.unk_50 = 1;
    lbl_1_bss_8B614.unk_52 = 0;
    lbl_1_bss_8B614.unk_54 = 15;
    lbl_1_bss_8B614.unk_2C = 0;
}
