/* Non-matching: best partial attempt (68.42% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_4_EF8_vec {
    s8 x;
    s8 y;
};

struct fn_4_EF8_lbl_4_bss_0 {
    u8 pad_0[0x14];
    u8 cnt_x;
    u8 cnt_y;
    u8 pad_16[0x8];
    u8 flag;
    u8 pad_1F[0x1];
    struct fn_4_EF8_vec tab[16];
    struct fn_4_EF8_vec tab2[16];
};

struct fn_4_EF8_lbl_1_bss_9F8 {
    u16 f0;
    u8 pad_2[0xE];
    u16 f10;
    u8 pad_12[0x2];
};

struct fn_4_EF8_lbl_1_bss_9C8 {
    u8 pad_0[0x2];
    s8 px;
    s8 py;
    u8 pad_4[0x8];
};

extern struct fn_4_EF8_lbl_4_bss_0 lbl_4_bss_0;
extern struct fn_4_EF8_lbl_1_bss_9F8 lbl_1_bss_9F8[];
extern struct fn_4_EF8_lbl_1_bss_9C8 lbl_1_bss_9C8[];
extern f64 lbl_4_rodata_100[];
extern s32 lbl_8006D24C(f64, f64);
extern void fn_1_A2D84(u32);
extern u32 fn_1_17C8(void *, void *, void *, void *);

void fn_4_EF8(u32 arg0) {
    struct fn_4_EF8_lbl_4_bss_0 *p_lbl_4_bss_0;
    u8 *cnt_y;
    u16 before;
    u32 f10;
    u32 f0;
    s32 t;
    u32 tv;
    s8 px;
    s8 py;
    s32 idx;
    f32 din;
    f32 d1;
    f32 d2;

    p_lbl_4_bss_0 = (struct fn_4_EF8_lbl_4_bss_0 *)&lbl_4_bss_0;
    if (p_lbl_4_bss_0->flag != 0) {
        p_lbl_4_bss_0->flag = p_lbl_4_bss_0->flag - 1;
    }
    cnt_y = &p_lbl_4_bss_0->cnt_y;
    before = *(u16 *)&p_lbl_4_bss_0->cnt_x;
    f10 = lbl_1_bss_9F8[arg0].f10;
    if (f10 & 0x4000) {
        if (p_lbl_4_bss_0->cnt_x < 50) {
            p_lbl_4_bss_0->cnt_x = p_lbl_4_bss_0->cnt_x + 1;
        }
    }
    f0 = lbl_1_bss_9F8[arg0].f0;
    if (f0 & 0x8000) {
        if (p_lbl_4_bss_0->cnt_x != 0) {
            p_lbl_4_bss_0->cnt_x = p_lbl_4_bss_0->cnt_x - 1;
        }
    }
    if (f0 & 0x1000) {
        if (*cnt_y < 50) {
            *cnt_y = *cnt_y + 1;
        }
    }
    if (f0 & 0x2000) {
        if (*cnt_y != 0) {
            *cnt_y = *cnt_y - 1;
        }
    }
    if ((u8)before != p_lbl_4_bss_0->cnt_x || (u8)(before >> 8) != *cnt_y) {
        fn_1_A2D84(0xA9010300);
    }
    px = lbl_1_bss_9C8[arg0].px;
    py = lbl_1_bss_9C8[arg0].py;
    t = lbl_8006D24C((f64)py, (f64)px);
    tv = (u32)t & 0xFFFF;
    if ((t & 0x3FFF) >= 0x1000 && (t & 0x3FFF) <= 0x3000) {
        idx = (py > 0) ? ((px > 0) ? 1 : 3) : ((px >= 0) ? 7 : 5);
        d1 = (f32)(p_lbl_4_bss_0->tab[idx].x * p_lbl_4_bss_0->tab[idx].x)
           + p_lbl_4_bss_0->tab[idx].y * p_lbl_4_bss_0->tab[idx].y;
        din = (f32)(px * px) + py * py;
        d2 = (f32)(p_lbl_4_bss_0->tab[idx + 8].x * p_lbl_4_bss_0->tab[idx + 8].x)
           + p_lbl_4_bss_0->tab[idx + 8].y * p_lbl_4_bss_0->tab[idx + 8].y;
        if (d1 < din) {
            if (p_lbl_4_bss_0->flag == 0) {
                fn_1_A2D84(0xA9010300);
                p_lbl_4_bss_0->flag = 3;
            }
            p_lbl_4_bss_0->tab[idx].x = px;
            p_lbl_4_bss_0->tab[idx].y = py;
        }
        if (d2 < din) {
            p_lbl_4_bss_0->tab[idx + 8].x = px;
            p_lbl_4_bss_0->tab[idx + 8].y = py;
            p_lbl_4_bss_0->tab2[idx].x = px;
            p_lbl_4_bss_0->tab2[idx].y = py;
            fn_1_17C8(&p_lbl_4_bss_0->tab2[idx], &p_lbl_4_bss_0->tab2[idx].y,
                      &p_lbl_4_bss_0->tab[0], &p_lbl_4_bss_0->cnt_x);
        }
    } else {
        if (p_lbl_4_bss_0->tab[0].x < px && (tv <= 0xF000 || tv < 0x1000)) {
            p_lbl_4_bss_0->tab[0].x = px;
            p_lbl_4_bss_0->tab[0].y = py;
        }
        if (p_lbl_4_bss_0->tab[2].y < py && tv > 0x3000 && tv < 0x5000) {
            p_lbl_4_bss_0->tab[2].x = px;
            p_lbl_4_bss_0->tab[2].y = py;
        }
        if (p_lbl_4_bss_0->tab[4].x > px && tv > 0x7000 && tv < 0x9000) {
            p_lbl_4_bss_0->tab[4].x = px;
            p_lbl_4_bss_0->tab[4].y = py;
        }
        if (p_lbl_4_bss_0->tab[6].y > py && tv > 0xB000 && tv < 0xD000) {
            p_lbl_4_bss_0->tab[6].x = px;
            p_lbl_4_bss_0->tab[6].y = py;
        }
        if (p_lbl_4_bss_0->tab[8].x < px) {
            p_lbl_4_bss_0->tab[8].x = px;
            p_lbl_4_bss_0->tab[8].y = py;
            p_lbl_4_bss_0->tab2[0].x = px;
            p_lbl_4_bss_0->tab2[0].y = py;
            fn_1_17C8(&p_lbl_4_bss_0->tab2[0], &p_lbl_4_bss_0->tab2[0].y,
                      &p_lbl_4_bss_0->tab[0], &p_lbl_4_bss_0->cnt_x);
        }
        if (p_lbl_4_bss_0->tab[10].y < py) {
            p_lbl_4_bss_0->tab[10].x = px;
            p_lbl_4_bss_0->tab[10].y = py;
            p_lbl_4_bss_0->tab2[2].x = px;
            p_lbl_4_bss_0->tab2[2].y = py;
            fn_1_17C8(&p_lbl_4_bss_0->tab2[2], &p_lbl_4_bss_0->tab2[2].y,
                      &p_lbl_4_bss_0->tab[0], &p_lbl_4_bss_0->cnt_x);
        }
        if (p_lbl_4_bss_0->tab[12].x > px) {
            p_lbl_4_bss_0->tab[12].x = px;
            p_lbl_4_bss_0->tab[12].y = py;
            p_lbl_4_bss_0->tab2[4].x = px;
            p_lbl_4_bss_0->tab2[4].y = py;
            fn_1_17C8(&p_lbl_4_bss_0->tab2[4], &p_lbl_4_bss_0->tab2[4].y,
                      &p_lbl_4_bss_0->tab[0], &p_lbl_4_bss_0->cnt_x);
        }
        if (p_lbl_4_bss_0->tab[14].y > py) {
            p_lbl_4_bss_0->tab[14].x = px;
            p_lbl_4_bss_0->tab[14].y = py;
            p_lbl_4_bss_0->tab2[6].x = px;
            p_lbl_4_bss_0->tab2[6].y = py;
            fn_1_17C8(&p_lbl_4_bss_0->tab2[6], &p_lbl_4_bss_0->tab2[6].y,
                      &p_lbl_4_bss_0->tab[0], &p_lbl_4_bss_0->cnt_x);
        }
    }
}
