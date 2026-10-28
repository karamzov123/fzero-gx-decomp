/* Non-matching: best partial attempt (90.91% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_7_520_flag {
    u8 pad_0[3];
    s8 unk_3;
};

extern struct fn_7_520_flag lbl_1_bss_9C;
extern u32 lbl_801A6410;
extern void **lbl_1_bss_6EAD0;
extern const f32 lbl_7_rodata_528;

extern void fn_7_4050(void);
extern u32 fn_7_4094(void *, u32, u32, u32);
extern void fn_1_4CC0(void);
extern void fn_8006CE1C(f32);
extern void fn_1_A0680(void);
extern void fn_1_47F74(s32);
extern void fn_1_411A4(u32);
extern u32 fn_1_4706C(void);
extern u32 fn_1_46A60(void);
extern u32 fn_1_4404(void);
extern u32 fn_800090A4(u32);
extern u32 fn_1_45D0(u32, u32, void *, u32);
extern u32 fn_1_46BA0(u32, u32);
extern void fn_1_47E54(s32);
extern void fn_1_41104(u32);
extern u32 fn_1_46BFC(void);
extern u32 fn_1_46B44(u32, void *);
extern u32 fn_80008E84(u32);
extern int sprintf(char *, const char *, ...);
extern s32 fn_1_465D0(void *, s32);
extern void fn_1_4A00(s32, u8, u32);
extern u32 fn_1_A1588(void *, u32);

u8 lbl_7_data_0[0x2A0] = {1};
static u8 fzgx_pool_data_gap0[0x12E74 - 0x2A0] = {1};
u32 lbl_7_data_12E70__fzgx_offset_4 = 1;
s32 lbl_7_data_12E78 = 1;
static u8 fzgx_pool_data_gap1[0x13A3C - 0x12E7C] = {1};
char lbl_7_data_13A3C[0xD] = {1};
static u8 fzgx_pool_data_gap2[0x13D9C - 0x13A4C] = {1};
char lbl_7_data_13A58__fzgx_offset_344[0x14] = {1};
char lbl_7_data_13A58__fzgx_offset_358[0x18] = {1};
char lbl_7_data_13A58__fzgx_offset_370[0x18] = {1};

u32 lbl_7_bss_0;
s32 lbl_7_bss_4[2];
s32 lbl_7_bss_C;
s8 *lbl_7_bss_10;
u8 *lbl_7_bss_14;
u32 lbl_7_bss_18;
u32 lbl_7_bss_1C__fzgx_offset_0[2];
u32 lbl_7_bss_1C__fzgx_offset_8;
s32 lbl_7_bss_1C__fzgx_offset_C;
u32 lbl_7_bss_1C__fzgx_offset_10;
s32 lbl_7_bss_1C__fzgx_offset_14;
s32 lbl_7_bss_1C__fzgx_offset_18[2];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_7_bss_0;
    s = *(u8 *)&lbl_7_bss_4;
    s = *(u8 *)&lbl_7_bss_C;
    s = *(u8 *)&lbl_7_bss_10;
    s = *(u8 *)&lbl_7_bss_14;
    s = *(u8 *)&lbl_7_bss_18;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_0;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_8;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_C;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_10;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_14;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_18;
}
#pragma section code_type ".text"


typedef struct {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
} Fn72CPad;
typedef struct {
    u8 pad_0[0x64];
    u16 unk_64;
} Fn72CSave;
extern Fn72CPad lbl_1_bss_9F8[];
extern Fn72CSave lbl_1_bss_7F0C0;
extern u32 lbl_1_bss_6EAB4;
extern u8 lbl_1_bss_8B3A0[];
extern s16 lbl_1_bss_968;
extern u16 lbl_1_bss_96A;
extern void fn_7_2538(void);
extern void fn_1_C2454(void);
extern s32 fn_1_C24A4(void);
extern u8 fn_1_B7C00(void);
extern int fn_1_4C10(void);
extern s32 fn_1_F9CA0(u32, u32);
extern s32 fn_1_F9E80(u8, u8);
extern void fn_1_A2D84(u32);

static inline s8 *fn_7_72C_array_read(s8 *array) { return array; }
#pragma opt_propagation off
void fn_7_72C(void) {
    u32 delta;
    s32 v;

    delta = 0;
    fn_7_2538();
    if (lbl_1_bss_9C.unk_3 == 1) {
        fn_1_C2454();
        lbl_1_bss_9C.unk_3 = 2;
    }
    if (lbl_1_bss_9C.unk_3 == 2) {
        if (fn_1_C24A4() == 0 && fn_1_B7C00() == 0) {
            lbl_1_bss_9C.unk_3 = 0;
        } else {
            return;
        }
    }
    if ((*((lbl_7_bss_1C__fzgx_offset_18) + (0))) > 0) {
        lbl_7_bss_1C__fzgx_offset_18[0]--;
    }
    if (lbl_7_bss_1C__fzgx_offset_18[1] > 0) {
        lbl_7_bss_1C__fzgx_offset_18[1]--;
    }
    if ((s32)lbl_7_bss_1C__fzgx_offset_10 != 0) {
        lbl_7_bss_1C__fzgx_offset_C += lbl_7_bss_1C__fzgx_offset_10;
        if (lbl_7_bss_1C__fzgx_offset_C > 200) {
            lbl_7_bss_1C__fzgx_offset_C = 200;
            lbl_7_bss_1C__fzgx_offset_10 = 0;
        } else if (lbl_7_bss_1C__fzgx_offset_C < 0) {
            lbl_7_bss_1C__fzgx_offset_C = 0;
            if (lbl_7_data_12E78 != -1) {
                lbl_7_bss_1C__fzgx_offset_10 = lbl_7_bss_1C__fzgx_offset_10 * -1;
            } else {
                lbl_7_bss_1C__fzgx_offset_10 = 0;
            }
        } else {
            return;
        }
    }
    if (lbl_7_data_12E78 != -1) {
        lbl_7_bss_1C__fzgx_offset_14 = lbl_7_data_12E78;
        lbl_7_data_12E78 = -1;
    }
    if (fn_1_4C10() != 0) {
        return;
    }
    if (lbl_7_bss_4[0] == 1) {
        switch (lbl_7_bss_1C__fzgx_offset_14) {
        case 4:
            lbl_1_bss_968 = 1;
            break;
        case 3:
            lbl_1_bss_96A = 0x88;
            break;
        }
    } else if (lbl_7_bss_4[0] == 0) {
        switch (lbl_7_bss_1C__fzgx_offset_14) {
        case 1:
            if (((lbl_1_bss_9F8[fn_7_72C_array_read(lbl_7_bss_10)[2]].unk_10 >> 1) & 1) || ((lbl_1_bss_9F8[fn_7_72C_array_read(lbl_7_bss_10)[2]].unk_12 >> 1) & 1)) {
                lbl_7_bss_1C__fzgx_offset_18[1] = 15;
                delta = 1;
                lbl_7_bss_1C__fzgx_offset_18[0] = 0;
            } else if ((lbl_1_bss_9F8[fn_7_72C_array_read(lbl_7_bss_10)[2]].unk_10 & 1) || (lbl_1_bss_9F8[fn_7_72C_array_read(lbl_7_bss_10)[2]].unk_12 & 1)) {
                lbl_7_bss_1C__fzgx_offset_18[0] = 15;
                delta = -1;
                lbl_7_bss_1C__fzgx_offset_18[1] = 0;
            }
            v = (*((0) + (lbl_7_bss_10))) + delta;
            if (v < 0 || v > 9) {
                lbl_7_bss_1C__fzgx_offset_18[0] = 0;
                delta = 0;
                lbl_7_bss_1C__fzgx_offset_18[1] = 0;
            }
            if (!(lbl_1_bss_7F0C0.unk_64 & (0x8000 >> ((*((lbl_7_bss_10) + (0))) + delta)))) {
                lbl_7_bss_1C__fzgx_offset_18[0] = 0;
                delta = 0;
                lbl_7_bss_1C__fzgx_offset_18[1] = 0;
            }
            if ((s32)delta != 0) {
                fn_1_A2D84(0xA9010000);
            }
            lbl_7_bss_10[0] += delta;
            if (((lbl_1_bss_9F8[fn_7_72C_array_read(lbl_7_bss_10)[2]].unk_8 >> 8) & 1) && fn_1_F9CA0(0, fn_7_72C_array_read(lbl_7_bss_10)[0]) != 0) {
                if (fn_7_72C_array_read(lbl_7_bss_10)[0] > 0 && fn_1_F9CA0(1, fn_7_72C_array_read(lbl_7_bss_10)[0]) != 0) {
                    lbl_7_data_12E78 = 2;
                    lbl_7_bss_1C__fzgx_offset_10 = -10;
                    for (lbl_7_bss_10[1] = 0; fn_7_72C_array_read(lbl_7_bss_10)[1] < 2 && fn_1_F9E80(fn_7_72C_array_read(lbl_7_bss_10)[1], fn_7_72C_array_read(lbl_7_bss_10)[0]) != 0; lbl_7_bss_10[1]++) {
                    }
                    fn_1_A2D84(0xA9010100);
                } else {
                    lbl_7_bss_10[1] = 0;
                    lbl_7_bss_1C__fzgx_offset_14 = 3;
                    lbl_7_bss_4[0] = 0x20;
                    lbl_7_bss_1C__fzgx_offset_10 = -10;
                    fn_1_4A00(0, 0x1E, lbl_7_bss_1C__fzgx_offset_0[0]);
                    fn_1_A2D84(0xA9010100);
                    lbl_1_bss_6EAB4 |= 0x24;
                }
            } else if ((lbl_1_bss_9F8[fn_7_72C_array_read(lbl_7_bss_10)[2]].unk_8 >> 9) & 1) {
                *(u32 *)(lbl_1_bss_8B3A0 + 0x94) = 0;
                lbl_7_bss_4[0] = 0x20;
                fn_1_4A00(0, 0x1E, lbl_7_bss_1C__fzgx_offset_0[0]);
                lbl_7_data_12E78 = 4;
                fn_1_A2D84(0xA9010200);
                lbl_1_bss_6EAB4 |= 0x24;
            }
            break;
        case 2:
            if ((((lbl_1_bss_9F8[fn_7_72C_array_read(lbl_7_bss_10)[2]].unk_10 >> 1) & 1) || ((lbl_1_bss_9F8[fn_7_72C_array_read(lbl_7_bss_10)[2]].unk_12 >> 1) & 1))
                && lbl_7_bss_10[1] < 2 && fn_1_F9CA0(fn_7_72C_array_read(lbl_7_bss_10)[1] + 1, fn_7_72C_array_read(lbl_7_bss_10)[0]) != 0) {
                lbl_7_bss_10[1]++;
                lbl_7_bss_C = 0;
                fn_1_A2D84(0xA9010000);
            } else if (((lbl_1_bss_9F8[fn_7_72C_array_read(lbl_7_bss_10)[2]].unk_10 & 1) || (lbl_1_bss_9F8[fn_7_72C_array_read(lbl_7_bss_10)[2]].unk_12 & 1))
                && lbl_7_bss_10[1] > 0 && fn_1_F9CA0(fn_7_72C_array_read(lbl_7_bss_10)[1] - 1, fn_7_72C_array_read(lbl_7_bss_10)[0]) != 0) {
                lbl_7_bss_10[1]--;
                lbl_7_bss_C = 0;
                fn_1_A2D84(0xA9010000);
            }
            if ((lbl_1_bss_9F8[(*((2) + (lbl_7_bss_10)))].unk_8 >> 8) & 1) {
                lbl_7_bss_1C__fzgx_offset_14 = 3;
                lbl_7_bss_4[0] = 0x20;
                lbl_7_bss_1C__fzgx_offset_10 = -10;
                fn_1_4A00(0, 0x1E, lbl_7_bss_1C__fzgx_offset_0[0]);
                fn_1_A2D84(0xA9010100);
                lbl_7_bss_C = 0;
                lbl_1_bss_6EAB4 |= 0x24;
            } else if ((lbl_1_bss_9F8[((2)[lbl_7_bss_10])].unk_8 >> 9) & 1) {
                lbl_7_bss_1C__fzgx_offset_10 = -10;
                lbl_7_data_12E78 = 1;
                fn_1_A2D84(0xA9010200);
            }
            break;
        }
    }
}
#pragma opt_propagation reset

