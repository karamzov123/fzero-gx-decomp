/* Non-matching: best partial attempt (90.18% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/globals.h"
typedef struct { u16 buttons; u8 pad[6]; u16 pressed; u8 pad2[6]; u16 repeat; u16 other; } Input;
typedef struct { s16 id; s16 type; u16 price; s16 sound; s16 unk; } Item;
extern Input lbl_1_bss_9F8[];
extern u8 lbl_1_bss_7F0C0[];
extern u32 lbl_801A66A8;
extern void fn_3_7A08(s16 *, s16 *, int);
extern void fn_3_BD00(u32, u32, u32, u32);
extern void fn_1_7B4C0(void);
extern void fn_1_7B2E8(s16);
extern void fn_1_A2D84(u32);
extern s32 fn_1_F9028(s16);
extern void fn_1_F946C(s16);
extern void fn_1_F9888(s16);
typedef struct lbl_3_bss_C_t {
    u32 fzgx_u32_C;
    u8 pad_4[0x8];
} lbl_3_bss_C_t;

typedef struct lbl_3_bss_20_t {
    u8 pad_1[0xc3];
    u8 fzgx_u8_20;
    s16 fzgx_s16_E4;
    u8 pad_C6[0xa];
} lbl_3_bss_20_t;

typedef struct lbl_3_bss_F0_t {
    u8 fzgx_u8_F0;
    u8 pad_1[0x2f];
} lbl_3_bss_F0_t;

typedef struct lbl_3_bss_7EE40_t {
    u8 fzgx_u8_80000;
    u8 pad_0[0x11c0];
    u8 pad_11C1[0x6fff];
} lbl_3_bss_7EE40_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_3_bss_0[2];
u32 lbl_3_bss_8;
lbl_3_bss_C_t lbl_3_bss_C;
u32 fzgx_obj_lbl_3_bss_18[2];
lbl_3_bss_20_t fzgx_obj_lbl_3_bss_20;
lbl_3_bss_F0_t fzgx_obj_lbl_3_bss_F0;
u32 lbl_3_bss_120[8];
u32 fzgx_obj_lbl_3_bss_140[33217];
u16 lbl_3_bss_20844;
u16 lbl_3_bss_0_gap_20846;
u32 fzgx_obj_lbl_3_bss_20848;
u32 lbl_3_bss_2084C;
u32 fzgx_obj_lbl_3_bss_20850;
u32 fzgx_obj_lbl_3_bss_20854[3];
u32 lbl_3_bss_20860[1088];
u32 fzgx_obj_lbl_3_bss_21960[2592];
u32 fzgx_obj_lbl_3_bss_241E0[100];
u32 lbl_3_bss_24370[3];
u32 lbl_3_bss_2437C[11];
u32 lbl_3_bss_243A8[6];
u32 lbl_3_bss_243C0[8304];
u16 lbl_3_bss_2C580;
u16 lbl_3_bss_0_gap_2C582;
u32 fzgx_obj_lbl_3_bss_2C584[98];
u32 lbl_3_bss_2C70C[45];
u32 fzgx_obj_lbl_3_bss_2C7C0[66624];
u32 fzgx_obj_lbl_3_bss_6D8C0[300];
u32 lbl_3_bss_6DD70;
u8 lbl_3_bss_6DD74;
u8 lbl_3_bss_0_gap_6DD75;
u16 lbl_3_bss_0_gap_6DD75_fill_6DD76;
u32 lbl_3_bss_6DD78[42];
u32 fzgx_obj_lbl_3_bss_6DE20[16208];
u32 lbl_3_bss_7DB60[328];
u32 lbl_3_bss_7E080;
u32 fzgx_obj_lbl_3_bss_7E084[110];
u16 fzgx_obj_lbl_3_bss_7E23C;
u16 lbl_3_bss_0_gap_7E23E;
u32 lbl_3_bss_7E240[300];
u32 fzgx_obj_lbl_3_bss_7E6F0[300];
u16 fzgx_obj_lbl_3_bss_7EBA0;
u16 lbl_3_bss_0_gap_7EBA2;
u32 fzgx_obj_lbl_3_bss_7EBA4;
u32 fzgx_obj_lbl_3_bss_7EBA8;
u16 lbl_3_bss_7EBAC;
u16 lbl_3_bss_0_gap_7EBAE;
u32 lbl_3_bss_7EBB0[20];
u16 lbl_3_bss_7EBB0_fill_7EC00;
u16 lbl_3_bss_7EC02;
u32 lbl_3_bss_7EC04;
u32 lbl_3_bss_7EC08[84];
u32 fzgx_obj_lbl_3_bss_7ED58[18];
u32 fzgx_obj_lbl_3_bss_7EDA0[8];
u32 fzgx_obj_lbl_3_bss_7EDC0[3];
u32 lbl_3_bss_7EDCC[3];
u32 fzgx_obj_lbl_3_bss_7EDD8[26];
lbl_3_bss_7EE40_t fzgx_obj_lbl_3_bss_7EE40;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_3_bss_0;
    s = *(u8 *)&lbl_3_bss_8;
    s = *(u8 *)&lbl_3_bss_C;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_18;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_20;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_F0;
    s = *(u8 *)&lbl_3_bss_120;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_140;
    s = *(u8 *)&lbl_3_bss_20844;
    s = *(u8 *)&lbl_3_bss_0_gap_20846;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_20848;
    s = *(u8 *)&lbl_3_bss_2084C;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_20850;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_20854;
    s = *(u8 *)&lbl_3_bss_20860;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_21960;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_241E0;
    s = *(u8 *)&lbl_3_bss_24370;
    s = *(u8 *)&lbl_3_bss_2437C;
    s = *(u8 *)&lbl_3_bss_243A8;
    s = *(u8 *)&lbl_3_bss_243C0;
    s = *(u8 *)&lbl_3_bss_2C580;
    s = *(u8 *)&lbl_3_bss_0_gap_2C582;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_2C584;
    s = *(u8 *)&lbl_3_bss_2C70C;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_2C7C0;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_6D8C0;
    s = *(u8 *)&lbl_3_bss_6DD70;
    s = *(u8 *)&lbl_3_bss_6DD74;
    s = *(u8 *)&lbl_3_bss_0_gap_6DD75;
    s = *(u8 *)&lbl_3_bss_0_gap_6DD75_fill_6DD76;
    s = *(u8 *)&lbl_3_bss_6DD78;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_6DE20;
    s = *(u8 *)&lbl_3_bss_7DB60;
    s = *(u8 *)&lbl_3_bss_7E080;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_7E084;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_7E23C;
    s = *(u8 *)&lbl_3_bss_0_gap_7E23E;
    s = *(u8 *)&lbl_3_bss_7E240;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_7E6F0;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_7EBA0;
    s = *(u8 *)&lbl_3_bss_0_gap_7EBA2;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_7EBA4;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_7EBA8;
    s = *(u8 *)&lbl_3_bss_7EBAC;
    s = *(u8 *)&lbl_3_bss_0_gap_7EBAE;
    s = *(u8 *)&lbl_3_bss_7EBB0;
    s = *(u8 *)&lbl_3_bss_7EBB0_fill_7EC00;
    s = *(u8 *)&lbl_3_bss_7EC02;
    s = *(u8 *)&lbl_3_bss_7EC04;
    s = *(u8 *)&lbl_3_bss_7EC08;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_7ED58;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_7EDA0;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_7EDC0;
    s = *(u8 *)&lbl_3_bss_7EDCC;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_7EDD8;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_7EE40;
}
#pragma section code_type ".text"

s16 fn_3_6AC4(void) {
    
    struct { u8 *value; } upper;
    s32 inputOffset;
    struct { u8 *value; } state;
    s16 direction;
    s32 delta = 0;
    s32 old, next;
    s16 low, high;
    s16 id;
    s16 price;
    upper.value = (u8 *)&fzgx_obj_lbl_3_bss_7EE40.fzgx_u8_80000;
    inputOffset = *(s16 *)(((u8 *)&fzgx_obj_lbl_3_bss_F0.fzgx_u8_F0) + 6);
    if ((((1) & (lbl_1_bss_9F8[inputOffset].repeat >> 3))) ||
        (lbl_1_bss_9F8[inputOffset].other >> 3 & 1)) delta = -1;
    if ((lbl_1_bss_9F8[inputOffset].repeat >> 2 & 1) ||
        (lbl_1_bss_9F8[inputOffset].other >> 2 & 1)) delta++;
    state.value = (u8 *)&fzgx_obj_lbl_3_bss_20.fzgx_u8_20;
    direction = delta;
    old = *(s16 *)(state.value + 0xC2);
    next = old;
    next += direction;
    if (next < 0) next = 0;
    else if (next > *(s16 *)(upper.value - 0x1DC4) - 1) next = *(s16 *)(upper.value - 0x1DC4) - 1;
    *(s16 *)(state.value + 0xC2) = next;
    if (old != (s16)next && *(s16 *)(upper.value - 0x1DC4) > 0) {
        if (((Item *)(upper.value - 0x1F7C))[old].type == 1) fn_1_7B4C0();
        if (((Item *)(upper.value - 0x1F7C))[*(s16 *)(state.value + 0xC2)].type == 1)
            fn_1_7B2E8(((Item *)(upper.value - 0x1F7C))[*(s16 *)(state.value + 0xC2)].sound);
        fn_1_A2D84(0xA9010000);
        lbl_801A66A8 = 0;
        fn_3_7A08(&low, &high, 5);
        if (*(s16 *)(state.value + 0xC2) < low || *(s16 *)(state.value + 0xC2) > high) {
            fn_3_BD00(delta, 0, (s16)(direction * 10), 0x08000001);
            fzgx_obj_lbl_3_bss_20.fzgx_s16_E4 -= delta;
        }
    }
    if ((lbl_1_bss_9F8[inputOffset].pressed >> 8 & 1) && *(s16 *)(upper.value - 0x1DC4) > 0) {
        id = ((Item *)(upper.value - 0x1F7C))[*(s16 *)(state.value + 0xC2)].id;
        price = ((Item *)(upper.value - 0x1F7C))[*(s16 *)(state.value + 0xC2)].price;
        if (fn_1_F9028(id) == 0 && *(u32 *)(lbl_1_bss_7F0C0 + 0x48F8) >= price) {
            *(u32 *)(lbl_1_bss_7F0C0 + 0x48F8) -= price;
            fn_1_F946C(id);
            fn_1_F9888(id);
            lbl_3_bss_8 = 1;
            fn_1_A2D84(0xA9010100);
            lbl_3_bss_C.fzgx_u32_C = 1;
        } else fn_1_A2D84(0xA9011400);
    }
    if (lbl_1_bss_9F8[inputOffset].buttons >> 9 & 1) {
        fn_1_A2D84(0xA9010200);
        return -1;
    }
    return 0;
}
