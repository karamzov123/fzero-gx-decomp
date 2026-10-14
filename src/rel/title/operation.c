#include "types.h"

/* fzgx:begin fn_8_67F8 */
struct fn_8_67F8_lbl_8_bss_2B8 {
    u32 unk_0;
};
struct fn_8_67F8_lbl_8_bss_2BC {
    u32 unk_0;
};

extern struct fn_8_67F8_lbl_8_bss_2B8 lbl_8_bss_2B8;
extern struct fn_8_67F8_lbl_8_bss_2BC lbl_8_bss_2BC;
extern u32 fn_1_3F8C0(void);
extern u32 fn_1_46B4(u32, u32, u32, u32);
extern u32 fn_80008E84(u32);
extern u32 fn_8_8C80(u32);
extern u32 lbl_801A6410;
extern u32 lbl_8_data_8AD4;
extern void fn_1_14DBCC(void *);
extern void fn_1_48140(int);

void fn_8_67F8(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    u32 v7;
    u32 v8;
    s32 v9;
    u32 t0, t1, t4, t6, t7;
    t0 = fn_1_3F8C0();
    t1 = fn_80008E84(t0);
    fn_1_48140(148);
    v0 = lbl_8_bss_2B8.unk_0;
    v1 = arg1;
    v2 = v0;
    v3 = arg2;
    v4 = arg3;
    if (v0 != 0) {
    fn_1_14DBCC((void *)v2);
    v3 = (u32)&lbl_801A6410;
    v4 = (u32)&lbl_8_bss_2B8;
    v2 = *(u32 *)((u8 *)v3 + 0);
    v3 = (u32)&lbl_8_data_8AD4;
    v1 = *(u32 *)((u8 *)v4 + 0);
    v4 = 1035;
    t4 = fn_1_46B4(v2, v1, (u32)v3, v4);
    v2 = t4;
    lbl_8_bss_2B8.unk_0 = 0;
    }
    v5 = lbl_8_bss_2BC.unk_0;
    v6 = v1;
    v7 = v5;
    v8 = v3;
    v9 = v4;
    if (v5 != 0) {
    fn_1_14DBCC((void *)v7);
    v8 = (u32)&lbl_801A6410;
    v9 = (u32)&lbl_8_bss_2BC;
    v7 = *(u32 *)((u8 *)v8 + 0);
    v8 = (u32)&lbl_8_data_8AD4;
    v6 = *(u32 *)((u8 *)v9 + 0);
    v9 = 1040;
    t6 = fn_1_46B4(v7, v6, (u32)v8, v9);
    v7 = t6;
    lbl_8_bss_2BC.unk_0 = 0;
    }
    t7 = fn_80008E84(t1);
    fn_8_8C80(t7);
}
/* fzgx:end fn_8_67F8 */

/* fzgx:begin fn_8_68D8 */
extern u32 lbl_8_bss_2A8;
extern u32 lbl_8_bss_2C0;

void fn_8_68D8(void) {
    lbl_8_bss_2C0 = 4;
    lbl_8_bss_2A8 = 0;
}
/* fzgx:end fn_8_68D8 */

/* fzgx:begin fn_8_68F4 */
extern struct fn_8_68F4_lbl_8_bss_2C0 lbl_8_bss_2C0;
extern u32 fn_1_411A4(u32);
extern u32 fn_1_4630(u32, u32, u32, u32);
extern u32 fn_1_46B4(u32, u32, u32, u32);
extern u32 fn_8_8C48(void);
extern u32 fn_8_8E00(void);
extern u32 fn_8_988C(void);
extern u32 fn_8_9B04(void);
extern u32 lbl_801A6410;
extern u32 lbl_801A66B4;
extern u32 lbl_8_bss_2B0;
extern u32 lbl_8_data_8AD4;

struct fn_8_68F4_lbl_8_bss_2C0 {
    u32 unk_0;
};

u32 fn_8_68F4(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 t0, t1, t2, t3, t4, t5, t6, t7;
    v0 = lbl_8_bss_2C0.unk_0;
    if ((s32)lbl_8_bss_2C0.unk_0 == 1) {
    v1 = arg2;
    v2 = arg3;
    if (lbl_8_bss_2B0 != 0) {
    v2 = (u32)&lbl_801A6410;
    v1 = (u32)&lbl_8_data_8AD4;
    v0 = *(u32 *)((u8 *)v2 + 0);
    v2 = 1152;
    t0 = fn_1_46B4(v0, lbl_8_bss_2B0, (u32)v1, v2);
    v0 = t0;
    }
    v2 = (u32)&lbl_801A6410;
    v1 = (u32)&lbl_8_data_8AD4;
    v0 = *(u32 *)((u8 *)v2 + 0);
    v2 = 1154;
    t1 = fn_1_4630(v0, (0x90000 - 16384), (u32)v1, v2);
    v0 = t1;
    lbl_8_bss_2B0 = v0;
    if ((s32)lbl_801A66B4 == 5) {
    v0 = 4;
    t2 = fn_1_411A4(v0);
    v0 = t2;
    } else {
    v0 = 5;
    t3 = fn_1_411A4(v0);
    v0 = t3;
    }
    t4 = fn_8_988C();
    v0 = t4;
    t5 = fn_8_9B04();
    v0 = t5;
    t6 = fn_8_8C48();
    v0 = t6;
    v3 = lbl_8_bss_2C0.unk_0;
    v0 = v3;
    lbl_8_bss_2C0.unk_0 = (v0 - 1);
    } else {
    lbl_8_bss_2C0.unk_0 = (v0 - 1);
    if ((s32)v0 <= 0) {
    t7 = fn_8_8E00();
    v0 = t7;
    }
    }
    return v0;
}
/* fzgx:end fn_8_68F4 */

/* fzgx:begin fn_8_69D8 */
extern struct fn_8_69D8_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_412A0(u32);
extern u32 fn_1_46B4(u32, u32, u32, u32);
extern u32 lbl_801A66B4;
extern u32 lbl_8_bss_2B0;
extern u32 lbl_8_data_8AD4;

struct fn_8_69D8_lbl_801A6410 {
    u32 unk_0;
};

void fn_8_69D8(void) {
    if ((s32)lbl_801A66B4 == 5) {
    fn_1_412A0(4);
    } else {
    fn_1_412A0(5);
    }
    if (lbl_8_bss_2B0 != 0) {
    fn_1_46B4(lbl_801A6410.unk_0, lbl_8_bss_2B0, (u32)&lbl_8_data_8AD4, 1199);
    lbl_8_bss_2B0 = 0;
    }
}
/* fzgx:end fn_8_69D8 */

/* fzgx:begin fn_8_6A50 */
struct fn_8_6A50_lbl_8_bss_2A8 {
    u32 unk_0;
    u8 pad_4[0x14];
    u32 unk_18;
    u32 unk_1C;
};

extern struct fn_8_6A50_lbl_8_bss_2A8 lbl_8_bss_2A8;

void fn_8_6A50(void) {
    struct fn_8_6A50_lbl_8_bss_2A8 *p_lbl_8_bss_2A8;
    p_lbl_8_bss_2A8 = (struct fn_8_6A50_lbl_8_bss_2A8 *)&lbl_8_bss_2A8;
    p_lbl_8_bss_2A8->unk_1C = 0;
    p_lbl_8_bss_2A8->unk_18 = 4;
    p_lbl_8_bss_2A8->unk_0 = 0;
}
/* fzgx:end fn_8_6A50 */

/* fzgx:begin fn_8_6A70 */
struct fn_8_6A70_lbl_8_bss_2A8 {
    u8 pad_0[0x18];
    u32 unk_18;
    u8 pad_1C[0x4];
    u32 unk_20;
    u8 pad_24[0xF0];
    u32 unk_114;
    u32 unk_118;
    u32 unk_11C;
    u32 unk_120;
};

struct fn_8_6A70_lbl_801A63C0 {
    u32 unk_0;
};

extern struct fn_8_6A70_lbl_801A63C0 lbl_801A63C0;
extern struct fn_8_6A70_lbl_8_bss_2A8 lbl_8_bss_2A8;
extern u32 lbl_801A66B4;
extern u32 fn_1_3EB78(u32, u32, u32, u32);
extern u32 fn_1_3ED8C(u32, u32, u32, u32, u32, u32, u32);
extern u32 fn_8_BD08(void);
extern void fn_8_663C(void);
extern void fn_8_67F8(u32, u32, u32, u32);
extern void fn_1_3EF08(u8);
extern void fn_1_3EF8C(u8);
extern void fn_1_3EFF0(u32, u8);
extern void fn_1_3F02C(u32);
extern void fn_1_411A4(u32);
extern void fn_80008BEC(void *, int, u32);

void fn_8_6A70(void) {
    struct fn_8_6A70_lbl_8_bss_2A8 *p_lbl_8_bss_2A8;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    s32 v4;
    s32 v5;
    u32 v6;
    u32 v7;

    p_lbl_8_bss_2A8 = (struct fn_8_6A70_lbl_8_bss_2A8 *)&lbl_8_bss_2A8;
    v0 = p_lbl_8_bss_2A8->unk_18;
    if ((s32)v0 == 1) {
        v0 = 0x2AAB0000;
        v1 = lbl_801A63C0.unk_0;
        v2 = (v0 - 21845);
        v0 = (v1 * (0x676A0000 + 19307));
        v3 = (v0 + 13259);
        v0 = ((v3 >> 16) & 0x7FFF);
        lbl_801A63C0.unk_0 = v3;
        v4 = ((s32)v0 >> 8);
        v5 = v4 % 6;
        switch (v5) {
        case 0:
            v6 = 31;
            break;
        case 1:
            v6 = 32;
            break;
        case 2:
            v6 = 33;
            break;
        case 3:
            v6 = 34;
            break;
        case 4:
            v6 = 35;
            break;
        default:
            v6 = 36;
        }
        v0 = 6;
        fn_1_3EF8C(v0);
        v0 = 0;
        fn_1_3ED8C(v0, 3, 1, (v6 & 0xFF), 10, 15, 0);
        v0 = 0;
        fn_1_3EB78(v0, 0, 0, 0);
        v0 = (u32)&fn_8_663C;
        fn_1_3EFF0(v0, 1);
        v0 = (u32)&fn_8_67F8;
        fn_1_3F02C(v0);
        v0 = 0;
        fn_1_3EF08(v0);
        p_lbl_8_bss_2A8->unk_20 = 0;
        if ((s32)lbl_801A66B4 == 5) {
            v0 = 4;
            fn_1_411A4(v0);
        } else {
            v0 = 5;
            fn_1_411A4(v0);
        }
        v7 = p_lbl_8_bss_2A8->unk_18;
        p_lbl_8_bss_2A8->unk_18 = (v7 - 1);
        fn_80008BEC((void *)((u8 *)p_lbl_8_bss_2A8 + 36), 0, 60);
        v0 = (u32)((u8 *)p_lbl_8_bss_2A8 + 96);
        fn_80008BEC((void *)v0, 0, 60);
        v0 = (u32)((u8 *)p_lbl_8_bss_2A8 + 156);
        fn_80008BEC((void *)v0, 0, 60);
        v0 = (u32)((u8 *)p_lbl_8_bss_2A8 + 216);
        fn_80008BEC((void *)v0, 0, 60);
        p_lbl_8_bss_2A8->unk_114 = 0;
        p_lbl_8_bss_2A8->unk_118 = 0;
        p_lbl_8_bss_2A8->unk_11C = 0;
        p_lbl_8_bss_2A8->unk_120 = 0;
    } else {
        p_lbl_8_bss_2A8->unk_18 = (v0 - 1);
        if ((s32)v0 <= 0) {
            fn_8_BD08();
        }
    }
}
/* fzgx:end fn_8_6A70 */

/* fzgx:begin fn_8_6C50 */
extern u32 fn_1_412A0(u32);
extern u32 lbl_801A66B4;

void fn_8_6C50(void) {
    if ((s32)lbl_801A66B4 == 5) {
    fn_1_412A0(4);
    } else {
    fn_1_412A0(5);
    }
}
/* fzgx:end fn_8_6C50 */

/* fzgx:begin fn_8_8C44 */
// fn_8_8C44: empty in retail (single blr).
void fn_8_8C44(void) {
}
/* fzgx:end fn_8_8C44 */

/* fzgx:begin fn_8_8C48 */
struct fn_8_8C48_lbl_8_bss_2A8 {
    u8 pad_0[0x124];
    u32 unk_124;
    u8 pad_128[0x4];
    u32 unk_12C;
    u32 unk_130;
    u32 unk_134;
    u32 unk_138;
};

extern struct fn_8_8C48_lbl_8_bss_2A8 lbl_8_bss_2A8;
extern u32 lbl_1_bss_26C60;
extern void fn_8_5FD4(void);

void fn_8_8C48(void) {
    struct fn_8_8C48_lbl_8_bss_2A8 *p_lbl_8_bss_2A8;
    p_lbl_8_bss_2A8 = (struct fn_8_8C48_lbl_8_bss_2A8 *)&lbl_8_bss_2A8;
    lbl_1_bss_26C60 = (u32)fn_8_5FD4;
    p_lbl_8_bss_2A8->unk_12C = 0;
    p_lbl_8_bss_2A8->unk_124 = 0;
    p_lbl_8_bss_2A8->unk_130 = 0;
    p_lbl_8_bss_2A8->unk_134 = -1;
    p_lbl_8_bss_2A8->unk_138 = 0;
}
/* fzgx:end fn_8_8C48 */

/* fzgx:begin fn_8_8C80 */
struct fn_8_8C80_ctx {
    u8 pad_0[0x13c];
    u32 unk_13C[9];
    u32 unk_160[9];
    u32 unk_184[9];
    u32 unk_1A8[9];
    u32 unk_1CC[9][4];
};

struct fn_8_8C80_lbl_801A6410 {
    u32 unk_0;
};

extern struct fn_8_8C80_ctx lbl_8_bss_2A8;
extern struct fn_8_8C80_lbl_801A6410 lbl_801A6410;
extern u8 lbl_8_data_8AD4[];
extern void fn_1_469BC(void);
extern u32 fn_1_46EE8(void);
extern void fn_1_46B4(u32, u32, const char *, int);

void fn_8_8C80(void) {
    u32 base;
    u32 *v0;
    u32 *v1;
    u32 *v2;
    u32 *v3;
    u32 (*v4)[4];
    s32 v5;
    s32 v6;
    u32 v7;

    base = (u32)&lbl_8_bss_2A8;
    fn_1_469BC();
    fn_1_46EE8();
    v0 = (u32 *)(base + 0x13c);
    v1 = (u32 *)(base + 0x160);
    v2 = (u32 *)(base + 0x184);
    v3 = (u32 *)(base + 0x1a8);
    v4 = (u32 (*)[4])(base + 0x1cc);
    for (v5 = 0; v5 < 9; v5++) {
        if (v0[0] != 0) {
            fn_1_46B4(lbl_801A6410.unk_0, v0[0], (const char *)&lbl_8_data_8AD4, 1975);
            v0[0] = 0;
        }
        if (v1[0] != 0) {
            fn_1_46B4(lbl_801A6410.unk_0, v1[0], (const char *)&lbl_8_data_8AD4, 1979);
            v1[0] = 0;
        }
        if (v2[0] != 0) {
            fn_1_46B4(lbl_801A6410.unk_0, v2[0], (const char *)&lbl_8_data_8AD4, 1983);
            v2[0] = 0;
        }
        if (v3[0] != 0) {
            fn_1_46B4(lbl_801A6410.unk_0, v3[0], (const char *)&lbl_8_data_8AD4, 1987);
            v3[0] = 0;
        }
        v7 = 0;
        for (v6 = 0; v6 < 4; v6++) {
            if (v4[0][v6] != 0) {
                fn_1_46B4(lbl_801A6410.unk_0, v4[0][v6], (const char *)&lbl_8_data_8AD4, 1992);
                v4[0][v6] = v7;
            }
        }
        v0++;
        v1++;
        v2++;
        v3++;
        v4++;
    }
}
/* fzgx:end fn_8_8C80 */

/* fzgx:begin fn_8_988C */
extern int sprintf(char *, const char *, ...);

struct fn_8_988C_ctx {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x130];
    u32 unk_13C[9];
    u32 unk_160[9];
    u32 unk_184[9];
    u32 unk_1A8[9];
    u32 unk_1CC[9][4];
    u32 unk_25C[9];
};

struct fn_8_988C_lbl_801A6410 {
    u32 unk_0;
};

extern struct fn_8_988C_ctx lbl_8_bss_2A8;
extern struct fn_8_988C_lbl_801A6410 lbl_801A6410;
extern u8 lbl_8_data_7E50[];
extern u32 lbl_1_bss_970;
extern const f32 lbl_8_rodata_194;

extern s32 fn_1_45730(const char *, void *);
extern u32 fn_1_45B2C(void *);
extern u32 fn_1_4630(u32, u32, const char *, int);
extern void DCFlushRange(void *, u32);
extern void fn_1_458A0(void *, u32, u32, u32);
extern void fn_1_45850(void *);
extern void fn_80008BA8(u32, u32, u32);
extern void fn_1_A8F78(void);
extern void fn_1_4BB0(void);
extern void fn_8006CE1C(f32);

void fn_8_988C(void) {
    u32 data;
    u32 ctx;
    u32 *src;
    u32 *v25C;
    u32 *v13C;
    u32 *v160;
    u32 *v184;
    u32 *v1A8;
    u32 *v1CC;
    u8 res[0x5c];
    u8 buf[0xfc];
    s32 i;
    u32 base;
    s32 j;
    u32 dest;

    data = (u32)lbl_8_data_7E50;
    ctx = (u32)&lbl_8_bss_2A8;
    fn_1_A8F78();
    fn_1_4BB0();
    fn_8006CE1C(lbl_8_rodata_194);
    lbl_1_bss_970 = 1200;
    src = (u32 *)(data + 0xe14);
    v25C = (u32 *)(ctx + 0x25c);
    v13C = (u32 *)(ctx + 0x13c);
    v160 = (u32 *)(ctx + 0x160);
    v184 = (u32 *)(ctx + 0x184);
    v1A8 = (u32 *)(ctx + 0x1a8);
    v1CC = (u32 *)(ctx + 0x1cc);
    for (i = 0; i < 9; i++) {
        sprintf((char *)buf, (const char *)(data + 0xe78), src[0]);
        if (fn_1_45730((const char *)buf, res) != 0) {
            v25C[0] = fn_1_45B2C(res);
            v13C[0] = fn_1_4630(lbl_801A6410.unk_0, v25C[0], (const char *)(data + 0xc84), 2454);
            DCFlushRange((void *)v13C[0], v25C[0] + 32);
            fn_1_458A0(res, v13C[0], (v25C[0] + 31) & ~31, 0);
            fn_1_45850(res);
        }
        sprintf((char *)buf, (const char *)(data + 0xe90), src[0]);
        if (fn_1_45730((const char *)buf, res) != 0) {
            v160[0] = fn_1_4630(lbl_801A6410.unk_0, 0x620, (const char *)(data + 0xc84), 2472);
            v184[0] = fn_1_4630(lbl_801A6410.unk_0, 0x1fc, (const char *)(data + 0xc84), 2473);
            v1A8[0] = fn_1_4630(lbl_801A6410.unk_0, 0x194, (const char *)(data + 0xc84), 2474);
            for (j = 0; j < 4; j++) {
                v1CC[j] = fn_1_4630(lbl_801A6410.unk_0, 0xc0, (const char *)(data + 0xc84), 2476);
            }
            fn_1_458A0(res, *(u32 *)(ctx + 0x8), (fn_1_45B2C(res) + 31) & ~31, 0);
            fn_1_45850(res);
            base = *(u32 *)(ctx + 0x8);
            fn_80008BA8(v160[0], base, 0x5a0);
            fn_80008BA8(v184[0], base + 0x5a0, 0x1fc);
            dest = base + 0x79c;
            for (j = 0; j < 4; j++) {
                fn_80008BA8(v1CC[j], dest, 0xc0);
                dest += 0xc0;
            }
            fn_80008BA8(v1A8[0], dest, 0x194);
        }
        src += 2;
        v25C++;
        v13C++;
        v160++;
        v184++;
        v1A8++;
        v1CC += 4;
    }
}
/* fzgx:end fn_8_988C */

/* fzgx:begin fn_8_9B04 */
extern struct fn_8_9B04_lbl_8_bss_2A8 lbl_8_bss_2A8;
extern u32 fn_80008BA8(u32, u32, u32);
extern u32 fn_8_5C54(u32);

struct fn_8_9B04_lbl_8_bss_2A8 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x130];
    u32 unk_13C;
    u8 pad_140[0x11C];
    u32 unk_25C;
};

void fn_8_9B04(void) {
    fn_80008BA8(lbl_8_bss_2A8.unk_8, lbl_8_bss_2A8.unk_13C, lbl_8_bss_2A8.unk_25C);
    fn_8_5C54(1);
}
/* fzgx:end fn_8_9B04 */

/* fzgx:begin fn_8_9B40 */
// fn_8_9B40: empty in retail (single blr).
void fn_8_9B40(void) {
}
/* fzgx:end fn_8_9B40 */

/* fzgx:begin fn_8_A954 */
#include "rel/title/operation.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 15.0;
    s = 320.0f;
    s = 640.0f;
    d = 1.0;
    s = 150.0f;
    s = 0.10000000149011612f;
    s = 20.0f;
    s = 0.8333333134651184f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table2[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 1.0f;
    s = 0.5f;
    s = 0.09000000357627869f;
    s = 5.0f;
    s = 255.0f;
}
static const u32 fzgx_pool_table4[6] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table6[17] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3C23D70A, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3C23D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.699999988079071f;
    s = 0.009999999776482582f;
    s = 240.0f;
    s = 45.0f;
    s = 0.0010000000474974513f;
    s = 100.0f;
    s = -200.0f;
    s = 120.0f;
    s = 200.0f;
    s = -120.0f;
    s = -0.009999999776482582f;
    s = 10.0f;
    s = -10240.0f;
    s = 1.7999999523162842f;
    s = -1.7999999523162842f;
    s = -20.0f;
    s = -4096.0f;
    s = -2048.0f;
    s = 1.100000023841858f;
    s = -0.5099999904632568f;
    s = 4096.0f;
    s = -1.100000023841858f;
    s = 0.800000011920929f;
}
static const u32 fzgx_pool_table8[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 345.0f;
    s = 2.0f;
    d = 0.85;
    s = -160.0f;
    s = 90.0f;
}
static const u32 fzgx_pool_table10[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 112.0f;
    s = 272.0f;
    s = 30.0f;
    s = 70.0f;
}
static const u32 fzgx_pool_table12[2] = {0xFFFFFF00, 0xFF4040FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.1111111640930176f;
    s = 160.0f;
}
static const u32 fzgx_pool_table14[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_4D0A0(void);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D0D4(u32 *, f32);
extern u32 fn_1_5233C(void);
extern u32 lbl_801A66B4;
extern u32 lbl_801A66A0;
struct TitleAnimationState {
    u8 pad0[0x24]; s16 unk_24;
    u8 pad26[0x76]; s16 unk_9C;
    u8 pad9E[0x7E]; s32 unk_11C; s32 unk_120;
    s32 unk_124; s32 unk_128;
};
#pragma fp_contract off
void fn_8_A954(void) {
    struct TitleAnimationState *s = (struct TitleAnimationState *)&lbl_8_bss_2A8;
    s32 position;
    f32 t;
    f32 opacity;
    if ((f64)s->unk_124 < (15.0)) {
        t = (f32)((1.0) - (f32)s->unk_124 / (15.0));
        position = (s32)((320.0f) + (640.0f) * t);
    } else if ((f64)s->unk_124 > (f64)s->unk_128 - (15.0)) {
        t = (f32)((1.0) - (f32)(s->unk_128 - s->unk_124) / (15.0));
        position = (s32)((320.0f) - (640.0f) * t);
    } else {
        t = (0.0f);
        position = 320;
    }
    t = (1.0f) - t;
    opacity = t * t;
    fn_1_49410();
    fn_1_495B0(0x8000u << 16);
    fn_1_49590((0.5f));
    fn_1_495C8(9);
    fn_1_496FC((f32)position, (345.0f));
    fn_1_4954C((0.0900000036f));
    fn_1_4955C((0.833333313f), (0.833333313f));
    fn_1_495A0(opacity);
    fn_1_4D0A0();
    fn_1_49738((u32)fn_1_5233C);
    fn_1_49748((5.0f));
    fn_1_4AE0C(((const char **)lbl_8_data_990C)[lbl_801A66B4]);
    fn_1_49738(0);
    {
        u32 copy;
        u32 color = fzgx_pool_table14[0];
        ((u8 *)&color)[3] = (u8)(s32)((255.0f) * opacity);
        copy = color;
        fn_1_4D0D4(&copy, (20.0f));
    }
    if (s->unk_124 == s->unk_128 / 2 + 60) {
        s->unk_120 = 120;
        s->unk_11C = 1;
    }
    s->unk_24 = 0;
    s->unk_9C = (s16)(lbl_801A66A0 << 9);
}
#pragma fp_contract reset
/* fzgx:end fn_8_A954 */

/* fzgx:begin fn_8_ADF4 */
struct fn_8_ADF4_sub {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    u8 pad_14[0x28];
};

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
s16 fzgx_obj_lbl_8_bss_2A8;
u32 fzgx_obj_lbl_8_bss_2AC;
u32 fzgx_obj_lbl_8_bss_2B0;
u32 fzgx_obj_lbl_8_bss_2B4;
u32 fzgx_obj_lbl_8_bss_2B8;
u32 fzgx_obj_lbl_8_bss_2BC;
u32 fzgx_obj_lbl_8_bss_2C0[3];
struct fn_8_ADF4_sub lbl_8_bss_2C0__fzgx_offset_C;
struct fn_8_ADF4_sub lbl_8_bss_2C0__fzgx_offset_48;
struct fn_8_ADF4_sub lbl_8_bss_2C0__fzgx_offset_84;
struct fn_8_ADF4_sub lbl_8_bss_2C0__fzgx_offset_C0;
u32 lbl_8_bss_2C0__fzgx_offset_FC[4];
s32 fzgx_obj_lbl_8_bss_3CC;
s32 fzgx_obj_lbl_8_bss_3D0;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_8_bss_2A8;
    s = fzgx_obj_lbl_8_bss_2AC;
    s = fzgx_obj_lbl_8_bss_2B0;
    s = fzgx_obj_lbl_8_bss_2B4;
    s = fzgx_obj_lbl_8_bss_2B8;
    s = fzgx_obj_lbl_8_bss_2BC;
    s = fzgx_obj_lbl_8_bss_2C0[0];
    s = lbl_8_bss_2C0__fzgx_offset_C.unk_4;
    s = lbl_8_bss_2C0__fzgx_offset_48.unk_4;
    s = lbl_8_bss_2C0__fzgx_offset_84.unk_4;
    s = lbl_8_bss_2C0__fzgx_offset_C0.unk_4;
    s = lbl_8_bss_2C0__fzgx_offset_FC[0];
    s = fzgx_obj_lbl_8_bss_3CC;
    s = fzgx_obj_lbl_8_bss_3D0;
}
#pragma section code_type ".text"
extern u8 lbl_8_data_9AB8[0x18];
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 15.0;
    s = 320.0f;
    s = 640.0f;
    d = 1.0;
    s = 150.0f;
    s = 0.10000000149011612f;
    s = 20.0f;
    s = 0.8333333134651184f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table2[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 1.0f;
    s = 0.5f;
    s = 0.09000000357627869f;
    s = 5.0f;
    s = 255.0f;
}
static const u32 fzgx_pool_table4[6] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table6[17] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3C23D70A, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3C23D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.699999988079071f;
    s = 0.009999999776482582f;
    s = 240.0f;
    s = 45.0f;
    s = 0.0010000000474974513f;
    s = 100.0f;
    s = -200.0f;
    s = 120.0f;
    s = 200.0f;
    s = -120.0f;
    s = -0.009999999776482582f;
    s = 10.0f;
    s = -10240.0f;
    s = 1.7999999523162842f;
    s = -1.7999999523162842f;
    s = -20.0f;
    s = -4096.0f;
    s = -2048.0f;
    s = 1.100000023841858f;
    s = -0.5099999904632568f;
    s = 4096.0f;
    s = -1.100000023841858f;
    s = 0.800000011920929f;
}
static const u32 fzgx_pool_table8[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 345.0f;
    s = 2.0f;
    d = 0.85;
    s = -160.0f;
    s = 90.0f;
}
static const u32 fzgx_pool_table10[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 112.0f;
    s = 272.0f;
    s = 30.0f;
    s = 70.0f;
}
static const u32 fzgx_pool_table12[2] = {0xFFFFFF00, 0xFF4040FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.1111111640930176f;
    s = 160.0f;
}
static const u32 fzgx_pool_table14[2] = {0xFFFFFF00, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table15[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -100.0f;
}
static const u32 fzgx_pool_table17[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"



typedef struct {
    u8 r, g, b, a;
} fn_8_ADF4_Color;

extern u32 lbl_801A66B4;
extern void fn_8_C9A8(s32, s32, f32);
extern void fn_1_A2D84(u32);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_4D0A0(void);
extern void fn_1_49738(void *);
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D0D4(fn_8_ADF4_Color *, f32);
extern void fn_1_5233C(void);

#pragma opt_propagation off

void fn_8_ADF4(u32 lab_unused0) {
    s32 cb;
    f32 t;
    f32 alpha;
    f32 inv;
    fn_8_ADF4_Color color2;
    s32 ca;
    s32 x;

    if (fzgx_obj_lbl_8_bss_3CC == fzgx_obj_lbl_8_bss_3D0 - 1) {
        fn_1_A2D84(0xA9121600);
    }

    if ((f64)fzgx_obj_lbl_8_bss_3CC < 15.0) {
        t = (f32)(1.0 - (f32)fzgx_obj_lbl_8_bss_3CC / 15.0);
        x = 320.0f + (f32)(640.0f * t);
    } else if ((f64)fzgx_obj_lbl_8_bss_3CC > (f64)fzgx_obj_lbl_8_bss_3D0 - 15.0) {
        t = (f32)(1.0 - (f32)(fzgx_obj_lbl_8_bss_3D0 - fzgx_obj_lbl_8_bss_3CC) / 15.0);
        x = 320.0f - (f32)(640.0f * t);
    } else {
        t = 0.0f;
        x = 320;
    }
    alpha = (1.0f - t) * (1.0f - t);

    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_49590(0.5f);
    fn_1_495C8(9);
    fn_1_496FC((f32)x, 345.0f);
    fn_1_4954C(0.09f);
    fn_1_4955C(0.8333333134651184f, 0.8333333134651184f);
    fn_1_495A0(alpha);
    fn_1_4D0A0();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    fn_1_4AE0C(((const char **)lbl_8_data_9AB8)[lbl_801A66B4]);
    fn_1_49738(0);
    {
        fn_8_ADF4_Color color = *(const fn_8_ADF4_Color *)fzgx_pool_table15;
        color.a = 255.0f * alpha;
        color2 = color;
        fn_1_4D0D4(&color2, 20.0f);
    }


    lbl_8_bss_2C0__fzgx_offset_C0.unk_4 = 0.0f;
    lbl_8_bss_2C0__fzgx_offset_84.unk_4 = 0.0f;
    lbl_8_bss_2C0__fzgx_offset_48.unk_4 = 0.0f;
    lbl_8_bss_2C0__fzgx_offset_C.unk_4 = 1.0f;
    lbl_8_bss_2C0__fzgx_offset_C.unk_C = 0.0f;
    lbl_8_bss_2C0__fzgx_offset_C.unk_10 = 90.0f;

    if (fzgx_obj_lbl_8_bss_3CC > fzgx_obj_lbl_8_bss_3D0 - 30) {
        alpha = (f32)(fzgx_obj_lbl_8_bss_3D0 - fzgx_obj_lbl_8_bss_3CC) / 30.0f;
        inv = 1.0f - alpha;
        alpha = alpha * alpha;
        alpha = alpha * alpha;
        ca = (s32)(100.0f * inv);
        fn_8_C9A8(ca, ca, alpha);
        cb = (s32)(-100.0f * inv);
        fn_8_C9A8(ca, cb, alpha);
        fn_8_C9A8(cb, ca, alpha);
        fn_8_C9A8(cb, cb, alpha);
    } else {
        fn_8_C9A8(0, 0, 1.0f);
    }
}
/* fzgx:end fn_8_ADF4 */

/* fzgx:begin fn_8_B138 */
struct fn_8_B138_layer {
    u8 pad_0[4];
    f32 unk_4;
    u8 pad_8[4];
    f32 unk_c;
    f32 unk_10;
    u8 pad_14[0x28];
};

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
s16 fzgx_obj_lbl_8_bss_2A8;
u32 fzgx_obj_lbl_8_bss_2AC;
u32 fzgx_obj_lbl_8_bss_2B0;
u32 fzgx_obj_lbl_8_bss_2B4;
u32 fzgx_obj_lbl_8_bss_2B8;
u32 fzgx_obj_lbl_8_bss_2BC;
u32 fzgx_obj_lbl_8_bss_2C0[3];
struct fn_8_B138_layer lbl_8_bss_2C0__fzgx_offset_C[4];
u32 lbl_8_bss_2C0__fzgx_offset_FC[4];
s32 fzgx_obj_lbl_8_bss_3CC;
s32 fzgx_obj_lbl_8_bss_3D0;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_8_bss_2A8;
    s = fzgx_obj_lbl_8_bss_2AC;
    s = fzgx_obj_lbl_8_bss_2B0;
    s = fzgx_obj_lbl_8_bss_2B4;
    s = fzgx_obj_lbl_8_bss_2B8;
    s = fzgx_obj_lbl_8_bss_2BC;
    s = fzgx_obj_lbl_8_bss_2C0[0];
    s = lbl_8_bss_2C0__fzgx_offset_C[0].unk_4;
    s = lbl_8_bss_2C0__fzgx_offset_FC[0];
    s = fzgx_obj_lbl_8_bss_3CC;
    s = fzgx_obj_lbl_8_bss_3D0;
}
#pragma section code_type ".text"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 15.0;
    s = 320.0f;
    s = 640.0f;
    d = 1.0;
    s = 150.0f;
    s = 0.10000000149011612f;
    s = 20.0f;
    s = 0.8333333134651184f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table2[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 1.0f;
    s = 0.5f;
    s = 0.09000000357627869f;
    s = 5.0f;
    s = 255.0f;
}
static const u32 fzgx_pool_table4[6] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table6[17] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3C23D70A, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3C23D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.699999988079071f;
    s = 0.009999999776482582f;
    s = 240.0f;
    s = 45.0f;
    s = 0.0010000000474974513f;
    s = 100.0f;
    s = -200.0f;
    s = 120.0f;
    s = 200.0f;
    s = -120.0f;
    s = -0.009999999776482582f;
    s = 10.0f;
    s = -10240.0f;
    s = 1.7999999523162842f;
    s = -1.7999999523162842f;
    s = -20.0f;
    s = -4096.0f;
    s = -2048.0f;
    s = 1.100000023841858f;
    s = -0.5099999904632568f;
    s = 4096.0f;
    s = -1.100000023841858f;
    s = 0.800000011920929f;
}
static const u32 fzgx_pool_table8[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 345.0f;
    s = 2.0f;
    d = 0.85;
    s = -160.0f;
    s = 90.0f;
}
static const u32 fzgx_pool_table10[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 112.0f;
    s = 272.0f;
    s = 30.0f;
    s = 70.0f;
}
static const u32 fzgx_pool_table12[2] = {0xFFFFFF00, 0xFF4040FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.1111111640930176f;
    s = 160.0f;
}
static const u32 fzgx_pool_table14[3] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -100.0f;
}
static const u32 fzgx_pool_table16[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

extern u8 lbl_8_rodata_160[];
extern u32 lbl_801A66B4;
extern u8 lbl_8_data_9B8C[0x18];

extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_4D0A0(void);
extern void fn_1_49738(void (*)(void));
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D0D4(u32 *, f32);
extern void fn_1_5233C(void);
extern void fn_8_C9A8(s32, s32, f32);



static inline void fn_8_B138_set_layer(struct fn_8_B138_layer *layer, f32 a, f32 b, f32 c) {
    layer->unk_4 = a;
    layer->unk_c = b;
    layer->unk_10 = c;
}

#pragma opt_propagation off
void fn_8_B138(void) {
    u8 *pool;
    s32 current;
    s32 limit;
    s32 target;
    f32 blend;
    f32 alpha;
    u32 copy;
    u32 color;

    pool = (u8 *)&lbl_8_rodata_160;
    current = fzgx_obj_lbl_8_bss_3CC;
    if ((f64)current < (15.0)) {
        blend = (f32)((1.0) - ((f32)current / (15.0)));
        target = (s32)((f32)((640.0f) * blend) + (320.0f));
    } else {
        limit = fzgx_obj_lbl_8_bss_3D0;
        if ((f64)current > ((f64)limit - (15.0))) {
            blend = (f32)((1.0) - ((f32)(limit - current) / (15.0)));
            target = (s32)((320.0f) - (f32)(((blend) * ((640.0f)))));
        } else {
            blend = (0.0f);
            target = 0x140;
        }
    }

    alpha = (1.0f) - blend;
    {
        f32 d = alpha;
        alpha = d * d;
    }
    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_49590((0.5f));
    fn_1_495C8(9);
    fn_1_496FC((f32)target, (345.0f));
    fn_1_4954C((0.0900000036f));
    fn_1_4955C((0.833333313f), (0.833333313f));
    fn_1_495A0(alpha);
    fn_1_4D0A0();
    fn_1_49738(fn_1_5233C);
    fn_1_49748((5.0f));
    fn_1_4AE0C(*(const char **)(lbl_8_data_9B8C + (lbl_801A66B4 << 2)));
    fn_1_49738(0);
    color = ((0)[fzgx_pool_table16]);
    ((u8 *)&color)[3] = (u8)((255.0f) * alpha);
    copy = color;
    fn_1_4D0D4(&copy, (20.0f));
    fn_8_B138_set_layer(&lbl_8_bss_2C0__fzgx_offset_C[0], (1.0f), (0.0f), (90.0f));
    fn_8_C9A8(0, 0, (1.0f));
}

#pragma opt_propagation reset
/* fzgx:end fn_8_B138 */

/* fzgx:begin fn_8_BAEC noprologue */
#include "types.h"

struct fn_8_BAEC_lbl_8_bss_2A8 {
    u8 pad_0[0x9C];
    s16 unk_9C;
    u8 pad_9E[0x86];
    s32 unk_124;
    s32 unk_128;
};

extern const f64 lbl_8_rodata_188;
extern f32 lbl_8_rodata_198;
extern u32 lbl_801A66A0;
extern struct fn_8_BAEC_lbl_8_bss_2A8 lbl_8_bss_2A8;
extern u32 fn_1_5370(s8, u32);
extern void fn_80008BEC(void *, int, u32);
extern void fn_8006CE1C(f32);

void fn_8_BAEC(void) {
    struct fn_8_BAEC_lbl_8_bss_2A8 *base;
    f32 v;
    u32 t;

    base = (struct fn_8_BAEC_lbl_8_bss_2A8 *)&lbl_8_bss_2A8;
    if (base->unk_124 == base->unk_128 / 2) {
        fn_80008BEC((u8 *)base + 0x24, 0, 60);
        fn_80008BEC((u8 *)base + 0x60, 0, 60);
        fn_80008BEC((u8 *)base + 0x9C, 0, 60);
        fn_80008BEC((u8 *)base + 0xD8, 0, 60);
        fn_1_5370(1, 0);
    }

    base->unk_9C = lbl_801A66A0 * 512;
    fn_8006CE1C(lbl_8_rodata_198 - (f32)__fabs((f64)(f32)(base->unk_128 / 2 - base->unk_124)) / (f32)(base->unk_128 / 2));
}
/* fzgx:end fn_8_BAEC */

/* fzgx:begin fn_8_BC04 noprologue */
#include "types.h"

struct fn_8_BC04_lbl_8_bss_2A8 {
    u8 pad_0[0x124];
    s32 unk_124;
    s32 unk_128;
};

extern f32 lbl_8_rodata_198[89];
extern struct fn_8_BC04_lbl_8_bss_2A8 lbl_8_bss_2A8;
extern u32 fn_1_5370(s8, u32);
extern void fn_80008BEC(void *, int, u32);
extern void fn_8006CE1C(f32);

void fn_8_BC04(void) {
    struct fn_8_BC04_lbl_8_bss_2A8 *p;

    p = &lbl_8_bss_2A8;
    if (p->unk_124 == p->unk_128 / 2) {
        fn_80008BEC((u8 *)p + 36, 0, 60);
        fn_80008BEC((u8 *)p + 96, 0, 60);
        fn_80008BEC((u8 *)p + 156, 0, 60);
        fn_80008BEC((u8 *)p + 216, 0, 60);
        fn_1_5370(1, 0);
    }
    fn_8006CE1C(lbl_8_rodata_198[0] - (f32)__fabs((f32)(p->unk_124 - p->unk_128 / 2)) / (f32)(p->unk_128 / 2));
}
/* fzgx:end fn_8_BC04 */

/* fzgx:begin fn_8_C7B0 */
extern f32 lbl_8_rodata_2FC[27];
extern u32 fn_800371F8(u32, void *);
extern void fn_8003462C(u32, u32, u32);
extern void fn_8007245C(u32);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(u32, u32, u32, u32, u32);
extern void fn_80072D64(u32, u32, u32, u32, u32, u32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073678(u32);
extern void fn_80073C6C(s32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, u32, u32, u32, u32, u32);
extern void fn_80074918(u8, s32, u8);

void fn_8_C7B0(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    u32 loc_8;

    fn_80074918(1, 7, 1);
    fn_80074788(1);
    fn_80074660(0);
    fn_80073678(1);
    fn_80073C6C(0);
    fn_800747D0(4, 0, 0, 0, 0, 2, 2);
    fn_80072AB0(0, 0, 0);
    fn_800734A8(0, 255, 255, 4);
    fn_80072C24(0, 15, 15, 15, 2);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 1);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_80072864(2);
    fn_8007245C(512);
    loc_8 = *(u32 *)((u8 *)arg0 + 0);
    fn_800371F8(1, (void *)&loc_8);
    fn_8003462C(128, 7, 4);
    *(f32 *)((u8 *)0xCC008000) = arg3;  /* fzgx-allow: A1,A2 GX FIFO write port */
    *(f32 *)((u8 *)0xCC008000) = arg1;  /* fzgx-allow: A1,A2 GX FIFO write port */
    *(f32 *)((u8 *)0xCC008000) = lbl_8_rodata_2FC[0];  /* fzgx-allow: A1,A2 GX FIFO write port */
    *(f32 *)((u8 *)0xCC008000) = arg4;  /* fzgx-allow: A1,A2 GX FIFO write port */
    *(f32 *)((u8 *)0xCC008000) = arg1;  /* fzgx-allow: A1,A2 GX FIFO write port */
    *(f32 *)((u8 *)0xCC008000) = lbl_8_rodata_2FC[0];  /* fzgx-allow: A1,A2 GX FIFO write port */
    *(f32 *)((u8 *)0xCC008000) = arg4;  /* fzgx-allow: A1,A2 GX FIFO write port */
    *(f32 *)((u8 *)0xCC008000) = arg2;  /* fzgx-allow: A1,A2 GX FIFO write port */
    *(f32 *)((u8 *)0xCC008000) = lbl_8_rodata_2FC[0];  /* fzgx-allow: A1,A2 GX FIFO write port */
    *(f32 *)((u8 *)0xCC008000) = arg3;  /* fzgx-allow: A1,A2 GX FIFO write port */
    *(f32 *)((u8 *)0xCC008000) = arg2;  /* fzgx-allow: A1,A2 GX FIFO write port */
    *(f32 *)((u8 *)0xCC008000) = lbl_8_rodata_2FC[0];  /* fzgx-allow: A1,A2 GX FIFO write port */
    fn_80074918(1, 3, 1);
}
/* fzgx:end fn_8_C7B0 */

/* fzgx:begin fn_8_C9A8 */
#include "rel/title/operation.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 15.0;
    s = 320.0f;
    s = 640.0f;
    d = 1.0;
    s = 150.0f;
    s = 0.10000000149011612f;
    s = 20.0f;
    s = 0.8333333134651184f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table2[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 1.0f;
    s = 0.5f;
    s = 0.09000000357627869f;
    s = 5.0f;
    s = 255.0f;
}
static const u32 fzgx_pool_table4[6] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table6[17] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3C23D70A, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3C23D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.699999988079071f;
    s = 0.009999999776482582f;
    s = 240.0f;
    s = 45.0f;
    s = 0.0010000000474974513f;
    s = 100.0f;
    s = -200.0f;
    s = 120.0f;
    s = 200.0f;
    s = -120.0f;
    s = -0.009999999776482582f;
    s = 10.0f;
    s = -10240.0f;
    s = 1.7999999523162842f;
    s = -1.7999999523162842f;
    s = -20.0f;
    s = -4096.0f;
    s = -2048.0f;
    s = 1.100000023841858f;
    s = -0.5099999904632568f;
    s = 4096.0f;
    s = -1.100000023841858f;
    s = 0.800000011920929f;
}
static const u32 fzgx_pool_table8[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 345.0f;
    s = 2.0f;
    d = 0.85;
    s = -160.0f;
    s = 90.0f;
}
static const u32 fzgx_pool_table10[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 112.0f;
    s = 272.0f;
    s = 30.0f;
    s = 70.0f;
}
static const u32 fzgx_pool_table12[2] = {0xFFFFFF00, 0xFF4040FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.1111111640930176f;
    s = 160.0f;
}
static const u32 fzgx_pool_table14[3] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -100.0f;
}
static const u32 fzgx_pool_table16[2] = {0xFFFFFF00, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 541.0f;
    s = 0.10999999940395355f;
    s = 0.47999998927116394f;
    s = 0.4399999976158142f;
    s = 591.0f;
    s = 289.0f;
}
static const u32 fzgx_pool_table18[2] = {0xFFFFFFFF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 6.5f;
    s = 81.25f;
    s = 26.0f;
    s = 620.0f;
}
static const u32 fzgx_pool_table20[1] = {0x00000080};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 448.0f;
    s = -1.0f;
    s = 481.0f;
    s = 641.0f;
    s = 1.4999999621068127e-05f;
    s = 5.999999848427251e-05f;
    s = 4.999999873689376e-05f;
}
static const u32 fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 90.0;
    d = 60.0;
    d = 30.0;
    s = 0.008999999612569809f;
    s = -177.0f;
    s = 108.0f;
    s = -0.008999999612569809f;
    s = -71.0f;
}
static const u32 fzgx_pool_table24[1] = {0xFFC80000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.0f;
    s = 0.029999999329447746f;
}
#pragma section code_type ".text"

extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_4954C(f32);
extern void fn_1_495A0(f32);
extern void fn_1_4965C(u8);
extern void fn_1_5233C(void);
extern void fn_1_49738(void (*)(void));
extern void fn_1_49748(f32);
extern void fn_1_49514(u32 *);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);

struct TitlePool { f32 values[123]; };

#pragma opt_strength_reduction off
void fn_8_C9A8(s32 x, s32 y, f32 alpha) {
    u32 copy;
    u32 color;
    u8 *data = (u8 *)&lbl_8_data_7E50;
    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_49590((0.5f));
    fn_1_495C8(8);
    fn_1_4954C((0.0900000036f));
    fn_1_495A0(alpha);
    fn_1_4965C(4);
    fn_1_49738(fn_1_5233C);
    fn_1_49748((3.0f));
    color = fzgx_pool_table24[0];
    ((u8 *)&color)[3] = (s32)((255.0f) * alpha);
    copy = color;
    fn_1_49514(&copy);
    fn_1_4955C((2.0f), (2.0f));
    fn_1_496FC((f32)(x + 100), (f32)(y + 240));
    fn_1_4AE0C((char *)data + 0x224c);
    fn_1_4955C((2.0f), (2.0f));
    fn_1_496FC((f32)(x + 189), (f32)(y + 240));
    fn_1_4AE0C((char *)data + 0x2254);
    fn_1_4955C((1.0f), (2.0f));
    fn_1_496FC((f32)(x + 221), (f32)(y + 240));
    fn_1_4AE0C((char *)data + 0x2258);
    fn_1_4955C((2.0f), (2.0f));
    fn_1_496FC((f32)(x + 269), (f32)(y + 240));
    fn_1_4AE0C((char *)data + 0x225c);
    fn_1_4955C((1.0f), (2.0f));
    fn_1_496FC((f32)(x + 520), (f32)(y + 240));
    fn_1_4AE0C((char *)data + 0x2268);
}
#pragma opt_strength_reduction reset
/* fzgx:end fn_8_C9A8 */

/* fzgx:begin fn_8_CC2C */
struct OperationValue {
    f32 value;
    u8 unk04[0x08];
    f32 delta;
};

struct OperationState {
    u8 unk00[0x54];
    f32 delta;
};

void fn_8_CC2C(struct OperationState *state, struct OperationValue *value) {
    f32 current;
    f32 delta;

    current = value->value;
    value->value = current + (delta = state->delta);
    value->delta = value->delta + delta;
}
/* fzgx:end fn_8_CC2C */

/* fzgx:begin fn_8_CF58 */
// fn_8_CF58: returns a constant.
int fn_8_CF58(void) {
    return 0;
}
/* fzgx:end fn_8_CF58 */

/* fzgx:begin fn_8_CF60 */
// fn_8_CF60: returns a constant.
int fn_8_CF60(void) {
    return 0;
}
/* fzgx:end fn_8_CF60 */

/* fzgx:begin fn_8_CF68 */
// fn_8_CF68: returns a constant.
int fn_8_CF68(void) {
    return 2;
}
/* fzgx:end fn_8_CF68 */

/* fzgx:begin fn_8_CF70 */
extern u32 fn_1_D0790(void);

s32 fn_8_CF70(void) {
    fn_1_D0790();
    return 0;
}
/* fzgx:end fn_8_CF70 */

/* fzgx:begin fn_8_CF94 */
extern u32 fn_1_5370(u32, u32);
extern void fn_8_CF58(void);
extern void fn_8_CF60(void);
extern void fn_8_CF68(void);
extern void fn_8_CF70(void);

struct fn_8_CF94_Arg0 {
    u32 unk_0;
    u8 pad_4[0xA4];
    u32 unk_A8;
    u32 unk_AC;
    u8 pad_B0[0x14];
    u32 unk_C4;
    u8 pad_C8[0x4];
    u32 unk_CC;
};

void fn_8_CF94(struct fn_8_CF94_Arg0 *arg0) {
    arg0->unk_A8 = (u32)fn_8_CF58;
    arg0->unk_C4 = (u32)fn_8_CF68;
    arg0->unk_CC = (u32)fn_8_CF60;
    arg0->unk_AC = (u32)fn_8_CF70;
    arg0->unk_0 = (arg0->unk_0 | 513);
    arg0->unk_0 = ((arg0->unk_0 | 0x200000) | 256);
    arg0->unk_0 = (arg0->unk_0 | 32768);
    arg0->unk_0 = (arg0->unk_0 | 0x1000000);
    fn_1_5370(1, 0);
}
/* fzgx:end fn_8_CF94 */

/* fzgx:begin fn_8_D020 */
// fn_8_D020: empty in retail (single blr).
void fn_8_D020(void) {
}
/* fzgx:end fn_8_D020 */

/* fzgx:begin fn_8_D024 */
extern u32 lbl_8_bss_544;

void fn_8_D024(void) {
    lbl_8_bss_544 = 4;
}
/* fzgx:end fn_8_D024 */

/* fzgx:begin fn_8_D5F4 */
extern u32 fn_1_14BD74(u32);
extern u32 fn_1_15555C(u32);
extern u32 fn_1_48140(u32);

void fn_8_D5F4(void) {
    u32 t2, t3;
    fn_1_48140(149);
    fn_1_48140(152);
    t2 = fn_1_48140(151);
    t3 = fn_1_15555C(t2);
    fn_1_14BD74(t3);
}
/* fzgx:end fn_8_D5F4 */
