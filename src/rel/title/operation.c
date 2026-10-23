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

/* fzgx:begin fn_8_71A8 pool */
#include "rel/title/operation.h"

typedef struct {
    u8 r, g, b, a;
} Color8_71A8;
extern u8 fn_8_8C48__fzgx_offset_0[];
extern u8 fn_8_8C80__fzgx_offset_0[];
extern u8 fn_8_8E00__fzgx_offset_0[];
extern u8 fn_8_988C__fzgx_offset_0[];
extern u8 fn_8_9B04__fzgx_offset_0[];
extern u8 fn_8_9B40__fzgx_offset_0[];
extern u8 lbl_8_data_7E50__fzgx_offset_0[];
extern u8 lbl_8_data_7E54__fzgx_offset_0[];
extern u8 lbl_8_data_7E60__fzgx_offset_0[];
extern u8 lbl_8_data_7E6C__fzgx_offset_0[];
extern u8 lbl_8_data_7E78__fzgx_offset_0[];
extern u8 lbl_8_data_7E84__fzgx_offset_0[];
extern u8 lbl_8_data_7E8C__fzgx_offset_0[];
extern u8 lbl_8_data_7E94__fzgx_offset_0[];
extern u8 lbl_8_data_7E9C__fzgx_offset_0[];
extern u8 lbl_8_data_7EA4__fzgx_offset_0[];
extern u8 lbl_8_data_7EB0__fzgx_offset_0[];
extern u8 lbl_8_data_7EC0__fzgx_offset_0[];
extern u8 lbl_8_data_7ED0__fzgx_offset_0[];
extern u8 lbl_8_data_7ED8__fzgx_offset_0[];
extern u8 lbl_8_data_7EE0__fzgx_offset_0[];
extern u8 lbl_8_data_7EEC__fzgx_offset_0[];
extern u8 lbl_8_data_7EF8__fzgx_offset_0[];
extern u8 lbl_8_data_7F08__fzgx_offset_0[];
extern u8 lbl_8_data_7F10__fzgx_offset_0[];
extern u8 lbl_8_data_7F1C__fzgx_offset_0[];
extern u8 lbl_8_data_7F28__fzgx_offset_0[];
extern u8 lbl_8_data_7F38__fzgx_offset_0[];
extern u8 lbl_8_data_7F40__fzgx_offset_0[];
extern u8 lbl_8_data_7F4C__fzgx_offset_0[];
extern u8 lbl_8_data_7F58__fzgx_offset_0[];
extern u8 lbl_8_data_7F68__fzgx_offset_0[];
extern u8 lbl_8_data_7F70__fzgx_offset_0[];
extern u8 lbl_8_data_7F7C__fzgx_offset_0[];
extern u8 lbl_8_data_7F84__fzgx_offset_0[];
extern u8 lbl_8_data_7F90__fzgx_offset_0[];
extern u8 lbl_8_data_7FA0__fzgx_offset_0[];
extern u8 lbl_8_data_7FAC__fzgx_offset_0[];
extern u8 lbl_8_data_7FB8__fzgx_offset_0[];
extern u8 lbl_8_data_7FC0__fzgx_offset_0[];
extern u8 lbl_8_data_7FD4__fzgx_offset_0[];
extern u8 lbl_8_data_7FE4__fzgx_offset_0[];
extern u8 lbl_8_data_7FF4__fzgx_offset_0[];
extern u8 lbl_8_data_8000__fzgx_offset_0[];
extern u8 lbl_8_data_800C__fzgx_offset_0[];
extern u8 lbl_8_data_801C__fzgx_offset_0[];
extern u8 lbl_8_data_8024__fzgx_offset_0[];
extern u8 lbl_8_data_8030__fzgx_offset_0[];
extern u8 lbl_8_data_8038__fzgx_offset_0[];
extern u8 lbl_8_data_8040__fzgx_offset_0[];
extern u8 lbl_8_data_8048__fzgx_offset_0[];
extern u8 lbl_8_data_8104__fzgx_offset_0[];
extern u8 lbl_8_data_8110__fzgx_offset_0[];
extern u8 lbl_8_data_8118__fzgx_offset_0[];
extern u8 lbl_8_data_8124__fzgx_offset_0[];
extern u8 lbl_8_data_812C__fzgx_offset_0[];
extern u8 lbl_8_data_8138__fzgx_offset_0[];
extern u8 lbl_8_data_8140__fzgx_offset_0[];
extern u8 lbl_8_data_8148__fzgx_offset_0[];
extern u8 lbl_8_data_816C__fzgx_offset_0[];
extern u8 lbl_8_data_8174__fzgx_offset_0[];
extern u8 lbl_8_data_819C__fzgx_offset_0[];
extern u8 lbl_8_data_81AC__fzgx_offset_0[];
extern u8 lbl_8_data_81B0__fzgx_offset_0[];
extern u8 lbl_8_data_81D4__fzgx_offset_0[];
extern u8 lbl_8_data_81E0__fzgx_offset_0[];
extern u8 lbl_8_data_8208__fzgx_offset_0[];
extern u8 lbl_8_data_8214__fzgx_offset_0[];
extern u8 lbl_8_data_823C__fzgx_offset_0[];
extern u8 lbl_8_data_8248__fzgx_offset_0[];
extern u8 lbl_8_data_8270__fzgx_offset_0[];
extern u8 lbl_8_data_827C__fzgx_offset_0[];
extern u8 lbl_8_data_82A4__fzgx_offset_0[];
extern u8 lbl_8_data_82C0__fzgx_offset_0[];
extern u8 lbl_8_data_82FC__fzgx_offset_0[];
extern u8 lbl_8_data_8328__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_8_data_7E50[271] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E4F4E00, 0x4D415354, 0x45522052, 0x45435600, 0x4D415354, 0x45522053, 0x454E4400, 0x534C4156,
    0x45205345, 0x4E440000, 0x534C4156, 0x45205245, 0x43560000, 0x494E4954, 0x0, 0x54455354,
    0x0, 0x54455354, 0x454E4400, 0x53455455, 0x50000000, 0x53455455, 0x505F444F, 0x4E450000,
    0x53455455, 0x505F434F, 0x554E5445, 0x52000000, 0x53455455, 0x505F434E, 0x545F444F, 0x4E450000,
    0x554E4C49, 0x4E4B0000, 0x434F494E, 0x0, 0x454E5452, 0x595F5741, 0x49540000, 0x4348414C,
    0x4C454E47, 0x45520000, 0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000, 0x454E5452, 0x59000000,
    0x454E5452, 0x595F4F4B, 0x0, 0x53494E47, 0x4C454348, 0x45434B00, 0x53494E47, 0x4C454348,
    0x45434B5F, 0x4F4B0000, 0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F, 0x4B000000, 0x434F5552,
    0x53455F44, 0x41544100, 0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000, 0x4D414348, 0x494E4500,
    0x4D414348, 0x494E455F, 0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46, 0x49475F4F, 0x4B000000,
    0x434F554E, 0x54455241, 0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954, 0x0, 0x4C494E4B,
    0x57414954, 0x4F4B0000, 0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49, 0x56455259, 0x53544152,
    0x54000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x0, 0x4C494E4B, 0x44454C49, 0x56455259,
    0x4F4B0000, 0x4C494E4B, 0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649, 0x45570000, 0x434F5552,
    0x53455649, 0x45575F4F, 0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B, 0x5354414E, 0x44425900,
    0x4C494E4B, 0x4F4B0000, 0x4C494E4B, 0x0, 0x50415553, 0x45000000, 0x4552524F, 0x52000000,
    (u32)lbl_8_data_7E50__fzgx_offset_0, (u32)lbl_8_data_7E54__fzgx_offset_0, (u32)lbl_8_data_7E60__fzgx_offset_0, (u32)lbl_8_data_7E6C__fzgx_offset_0, (u32)lbl_8_data_7E78__fzgx_offset_0, (u32)lbl_8_data_7E84__fzgx_offset_0, (u32)lbl_8_data_7E8C__fzgx_offset_0, (u32)lbl_8_data_7E94__fzgx_offset_0,
    (u32)lbl_8_data_7E9C__fzgx_offset_0, (u32)lbl_8_data_7EA4__fzgx_offset_0, (u32)lbl_8_data_7EB0__fzgx_offset_0, (u32)lbl_8_data_7EC0__fzgx_offset_0, (u32)lbl_8_data_7ED0__fzgx_offset_0, (u32)lbl_8_data_7ED8__fzgx_offset_0, (u32)lbl_8_data_7EE0__fzgx_offset_0, (u32)lbl_8_data_7EEC__fzgx_offset_0,
    (u32)lbl_8_data_7EF8__fzgx_offset_0, (u32)lbl_8_data_7F08__fzgx_offset_0, (u32)lbl_8_data_7F10__fzgx_offset_0, (u32)lbl_8_data_7F1C__fzgx_offset_0, (u32)lbl_8_data_7F28__fzgx_offset_0, (u32)lbl_8_data_7F38__fzgx_offset_0, (u32)lbl_8_data_7F40__fzgx_offset_0, (u32)lbl_8_data_7F4C__fzgx_offset_0,
    (u32)lbl_8_data_7F58__fzgx_offset_0, (u32)lbl_8_data_7F68__fzgx_offset_0, (u32)lbl_8_data_7F70__fzgx_offset_0, (u32)lbl_8_data_7F7C__fzgx_offset_0, (u32)lbl_8_data_7F84__fzgx_offset_0, (u32)lbl_8_data_7F90__fzgx_offset_0, (u32)lbl_8_data_7FA0__fzgx_offset_0, (u32)lbl_8_data_7FAC__fzgx_offset_0,
    (u32)lbl_8_data_7FB8__fzgx_offset_0, (u32)lbl_8_data_7FC0__fzgx_offset_0, (u32)lbl_8_data_7FD4__fzgx_offset_0, (u32)lbl_8_data_7FE4__fzgx_offset_0, (u32)lbl_8_data_7FF4__fzgx_offset_0, (u32)lbl_8_data_8000__fzgx_offset_0, (u32)lbl_8_data_800C__fzgx_offset_0, (u32)lbl_8_data_801C__fzgx_offset_0,
    (u32)lbl_8_data_8024__fzgx_offset_0, (u32)lbl_8_data_8030__fzgx_offset_0, (u32)lbl_8_data_8038__fzgx_offset_0, (u32)lbl_8_data_8040__fzgx_offset_0, (u32)lbl_8_data_8048__fzgx_offset_0, 0x4F564552, 0x54414B45, 0x0,
    0x4A554D50, 0x0, 0x454E454D, 0x59484954, 0x0, 0x57414C4C, 0x48495400, 0x53494445,
    0x42595349, 0x44450000, 0x53544152, 0x54000000, 0x474F414C, 0x0, 0x4C415000, (u32)lbl_8_data_8104__fzgx_offset_0,
    (u32)lbl_8_data_8110__fzgx_offset_0, (u32)lbl_8_data_8118__fzgx_offset_0, (u32)lbl_8_data_8124__fzgx_offset_0, (u32)lbl_8_data_812C__fzgx_offset_0, (u32)lbl_8_data_8138__fzgx_offset_0, (u32)lbl_8_data_8140__fzgx_offset_0, (u32)lbl_8_data_8148__fzgx_offset_0, 0x6D656E75,
    0x0, 0x77617463, 0x68000000, (u32)lbl_8_data_816C__fzgx_offset_0, (u32)fn_8_988C__fzgx_offset_0, (u32)fn_8_9B04__fzgx_offset_0, (u32)fn_8_9B40__fzgx_offset_0, (u32)lbl_8_data_8174__fzgx_offset_0,
    (u32)fn_8_8C48__fzgx_offset_0, (u32)fn_8_8E00__fzgx_offset_0, (u32)fn_8_8C80__fzgx_offset_0, 0x41434345, 0x4C455241, 0x544F520A, 0x0, 0x0,
    0x8341834E, 0x835A838B, 0xA000000, (u32)lbl_8_data_819C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_81B0__fzgx_offset_0, 0x73706565, 0x64207570, 0x2E0A0000, 0x89C191AC, 0x82B582DC, 0x82B78142, 0xA000000,
    (u32)lbl_8_data_81D4__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81E0__fzgx_offset_0, 0x41495220, 0x4252414B,
    0x450A0000, 0x83478341, 0x8375838C, 0x815B834C, 0xA000000, (u32)lbl_8_data_8208__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8214__fzgx_offset_0, 0x736C6F77, 0x20646F77, 0x6E2E0A00, 0x8CB891AC, 0x82B582DC,
    0x82B78142, 0xA000000, (u32)lbl_8_data_823C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8248__fzgx_offset_0,
    0x53544545, 0x52494E47, 0xA000000, 0x83588365, 0x8341838A, 0x8393834F, 0xA000000
};
static u32 fzgx_pool_data_lbl_8_data_7E50_43C[6] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_8_data_8270__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_827C__fzgx_offset_0
};
static u32 fzgx_pool_data_lbl_8_data_82A4[16] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x436F6E74, 0x726F6C20, 0x796F7572, 0x206D6163, 0x68696E65, 0x20776974, 0x680A0000, 0x83588365,
    0x8341838A, 0x8393834F, 0x82C68341, 0x834E835A, 0x838B82C5, 0x837D8356, 0x839382F0, 0xA000000
};
static u32 fzgx_pool_data_lbl_8_data_7E50_494[6] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_8_data_82A4__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_82C0__fzgx_offset_0
};
static u32 fzgx_pool_data_lbl_8_data_82FC[18] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x74686520, 0x73746565, 0x72696E67, 0x20776865, 0x656C2061, 0x6E642074, 0x68652061, 0x6363656C,
    0x65726174, 0x6F722E0A, 0x0, 0x83528393, 0x8367838D, 0x815B838B, 0x82B582C4, 0x82AD82BE,  /* fzgx-allow: A1 retail data bytes */
    0x82B382A2, 0x81420A00  /* fzgx-allow: A1 retail data bytes */
};
static u32 fzgx_pool_data_lbl_8_data_7E50_4F4[6] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_8_data_82FC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8328__fzgx_offset_0
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_8_data_7E50(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_8_data_7E50;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_7E50_43C;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_82A4;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_7E50_494;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_82FC;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_7E50_4F4;
}
#pragma section code_type ".text"


extern u32 lbl_801A66B4;
extern void fn_1_5233C(void);
extern void fn_8_CC4C(u32, u32);
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
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D0D4(Color8_71A8 *, f32);

/* Pool primers: fix the TU literal pool's first-use order (dropped at integration). */
#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_primer1(f64 *d, f32 *f)
{
    d[0] = 15.0;
    f[0] = 320.0f;
    f[1] = 640.0f;
    d[1] = 1.0;
    f[2] = 150.0f;
    f[3] = 0.1f;
    f[4] = 20.0f;
    f[5] = 0.8333333f;
}

__declspec(section ".fzgxpool") void fzgx_pool_primer2(f32 *f, s32 i)
{
    f[0] = (f32)i;
}

__declspec(section ".fzgxpool") void fzgx_pool_primer3(Color8_71A8 *out)
{
    Color8_71A8 c = { 0xFF, 0xFF, 0xFF, 0x00 };
    *out = c;
}

__declspec(section ".fzgxpool") void fzgx_pool_primer4(f32 *f)
{
    f[0] = 0.0f;
    f[1] = 1.0f;
    f[2] = 0.5f;
    f[3] = 0.09f;
    f[4] = 5.0f;
    f[5] = 255.0f;
}

__declspec(section ".fzgxpool") void fzgx_pool_primer5(Color8_71A8 *out)
{
    Color8_71A8 c = { 0xFF, 0xFF, 0xFF, 0x00 };
    *out = c;
}

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_8_bss_3D0;
u32 lbl_8_bss_3D0_fill_3D4[91];
u8 lbl_8_bss_540;
u8 lbl_8_bss_3D0_gap_541;
u16 lbl_8_bss_3D0_gap_541_fill_542;
u32 lbl_8_bss_544[3];
u32 fzgx_obj_lbl_8_bss_550;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_8_bss_3D0;
    s = *(u8 *)&lbl_8_bss_3D0_fill_3D4;
    s = *(u8 *)&lbl_8_bss_540;
    s = *(u8 *)&lbl_8_bss_3D0_gap_541;
    s = *(u8 *)&lbl_8_bss_3D0_gap_541_fill_542;
    s = *(u8 *)&lbl_8_bss_544;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_550;
}
#pragma section code_type ".text"

void fn_8_71A8(void)
{
    s32 x;
    f32 t;
    f32 sq;
    s32 cnt;
    s32 end;
    Color8_71A8 c2;

    
    if ((s32)lbl_8_bss_3CC == (s32)fzgx_obj_lbl_8_bss_3D0 - 1) {
        fn_1_A2D84(0xA9120A00);
    }
    cnt = lbl_8_bss_3CC;
    if (cnt < 15.0) {
        t = 1.0 - (f32)cnt / 15.0;
        x = 320.0f + (f32)(640.0f * t);
    } else {
        end = fzgx_obj_lbl_8_bss_3D0;
        if (cnt > end - 15.0) {
            t = 1.0 - (f32)(end - cnt) / 15.0;
            x = 320.0f - (f32)(640.0f * t);
        } else {
            t = 0.0f;
            x = 320;
        }
    }
    sq = (1.0f - t) * (1.0f - t);
    end = fzgx_obj_lbl_8_bss_3D0;
    if (end > cnt && cnt > end - 180) {
        fn_8_CC4C(0x1B7, 0xB1);
    }
    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_49590(0.5f);
    fn_1_495C8(9);
    fn_1_496FC(x, 150.0f);
    fn_1_4954C(0.09f);
    if ((s32)lbl_801A66B4 == 5) {
        fn_1_4955C(1.0f, 1.0f);
    } else {
        fn_1_4955C(0.8333333f, 0.8333333f);
    }
    fn_1_495A0(sq);
    fn_1_4D0A0();
    fn_1_49738((u32)fn_1_5233C);
    fn_1_49748(5.0f);
    fn_1_4AE0C(*(char **)((u32)((u8 *)fzgx_pool_data_lbl_8_data_7E50_43C) + lbl_801A66B4 * 4));
    fn_1_49738(0);
    fn_1_4AE0C(*(char **)((u32)((u8 *)fzgx_pool_data_lbl_8_data_7E50_494) + lbl_801A66B4 * 4));
    fn_1_4AE0C(*(char **)((u32)((u8 *)fzgx_pool_data_lbl_8_data_7E50_4F4) + lbl_801A66B4 * 4));
    {
        Color8_71A8 c = { 0xFF, 0xFF, 0xFF, 0x00 };
        c.a = 255.0f * sq;
        c2 = c;
        fn_1_4D0D4(&c2, 20.0f);
    }
}
/* fzgx:end fn_8_71A8 */

/* fzgx:begin fn_8_7484 */
#include "rel/title/operation.h"

typedef struct {
    u8 r, g, b, a;
} Color_8_7484;

extern s32 lbl_801A66B4;
extern void fn_8_CC4C(u32, u32);
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
extern void fn_1_4D0D4(Color_8_7484 *, f32);
extern void fn_1_5233C(void);

/* Primes the TU literal pool in retail order (lbl_8_rodata_160). */

extern u8 fn_8_8C48__fzgx_offset_0[];
extern u8 fn_8_8C80__fzgx_offset_0[];
extern u8 fn_8_8E00__fzgx_offset_0[];
extern u8 fn_8_988C__fzgx_offset_0[];
extern u8 fn_8_9B04__fzgx_offset_0[];
extern u8 fn_8_9B40__fzgx_offset_0[];
extern u8 lbl_8_data_7E50__fzgx_offset_0[];
extern u8 lbl_8_data_7E54__fzgx_offset_0[];
extern u8 lbl_8_data_7E60__fzgx_offset_0[];
extern u8 lbl_8_data_7E6C__fzgx_offset_0[];
extern u8 lbl_8_data_7E78__fzgx_offset_0[];
extern u8 lbl_8_data_7E84__fzgx_offset_0[];
extern u8 lbl_8_data_7E8C__fzgx_offset_0[];
extern u8 lbl_8_data_7E94__fzgx_offset_0[];
extern u8 lbl_8_data_7E9C__fzgx_offset_0[];
extern u8 lbl_8_data_7EA4__fzgx_offset_0[];
extern u8 lbl_8_data_7EB0__fzgx_offset_0[];
extern u8 lbl_8_data_7EC0__fzgx_offset_0[];
extern u8 lbl_8_data_7ED0__fzgx_offset_0[];
extern u8 lbl_8_data_7ED8__fzgx_offset_0[];
extern u8 lbl_8_data_7EE0__fzgx_offset_0[];
extern u8 lbl_8_data_7EEC__fzgx_offset_0[];
extern u8 lbl_8_data_7EF8__fzgx_offset_0[];
extern u8 lbl_8_data_7F08__fzgx_offset_0[];
extern u8 lbl_8_data_7F10__fzgx_offset_0[];
extern u8 lbl_8_data_7F1C__fzgx_offset_0[];
extern u8 lbl_8_data_7F28__fzgx_offset_0[];
extern u8 lbl_8_data_7F38__fzgx_offset_0[];
extern u8 lbl_8_data_7F40__fzgx_offset_0[];
extern u8 lbl_8_data_7F4C__fzgx_offset_0[];
extern u8 lbl_8_data_7F58__fzgx_offset_0[];
extern u8 lbl_8_data_7F68__fzgx_offset_0[];
extern u8 lbl_8_data_7F70__fzgx_offset_0[];
extern u8 lbl_8_data_7F7C__fzgx_offset_0[];
extern u8 lbl_8_data_7F84__fzgx_offset_0[];
extern u8 lbl_8_data_7F90__fzgx_offset_0[];
extern u8 lbl_8_data_7FA0__fzgx_offset_0[];
extern u8 lbl_8_data_7FAC__fzgx_offset_0[];
extern u8 lbl_8_data_7FB8__fzgx_offset_0[];
extern u8 lbl_8_data_7FC0__fzgx_offset_0[];
extern u8 lbl_8_data_7FD4__fzgx_offset_0[];
extern u8 lbl_8_data_7FE4__fzgx_offset_0[];
extern u8 lbl_8_data_7FF4__fzgx_offset_0[];
extern u8 lbl_8_data_8000__fzgx_offset_0[];
extern u8 lbl_8_data_800C__fzgx_offset_0[];
extern u8 lbl_8_data_801C__fzgx_offset_0[];
extern u8 lbl_8_data_8024__fzgx_offset_0[];
extern u8 lbl_8_data_8030__fzgx_offset_0[];
extern u8 lbl_8_data_8038__fzgx_offset_0[];
extern u8 lbl_8_data_8040__fzgx_offset_0[];
extern u8 lbl_8_data_8048__fzgx_offset_0[];
extern u8 lbl_8_data_8104__fzgx_offset_0[];
extern u8 lbl_8_data_8110__fzgx_offset_0[];
extern u8 lbl_8_data_8118__fzgx_offset_0[];
extern u8 lbl_8_data_8124__fzgx_offset_0[];
extern u8 lbl_8_data_812C__fzgx_offset_0[];
extern u8 lbl_8_data_8138__fzgx_offset_0[];
extern u8 lbl_8_data_8140__fzgx_offset_0[];
extern u8 lbl_8_data_8148__fzgx_offset_0[];
extern u8 lbl_8_data_816C__fzgx_offset_0[];
extern u8 lbl_8_data_8174__fzgx_offset_0[];
extern u8 lbl_8_data_819C__fzgx_offset_0[];
extern u8 lbl_8_data_81AC__fzgx_offset_0[];
extern u8 lbl_8_data_81B0__fzgx_offset_0[];
extern u8 lbl_8_data_81D4__fzgx_offset_0[];
extern u8 lbl_8_data_81E0__fzgx_offset_0[];
extern u8 lbl_8_data_8208__fzgx_offset_0[];
extern u8 lbl_8_data_8214__fzgx_offset_0[];
extern u8 lbl_8_data_823C__fzgx_offset_0[];
extern u8 lbl_8_data_8248__fzgx_offset_0[];
extern u8 lbl_8_data_8270__fzgx_offset_0[];
extern u8 lbl_8_data_827C__fzgx_offset_0[];
extern u8 lbl_8_data_82A4__fzgx_offset_0[];
extern u8 lbl_8_data_82C0__fzgx_offset_0[];
extern u8 lbl_8_data_82FC__fzgx_offset_0[];
extern u8 lbl_8_data_8328__fzgx_offset_0[];
extern u8 lbl_8_data_835C__fzgx_offset_0[];
extern u8 lbl_8_data_8368__fzgx_offset_0[];
extern u8 lbl_8_data_8394__fzgx_offset_0[];
extern u8 lbl_8_data_83B8__fzgx_offset_0[];
extern u8 lbl_8_data_83FC__fzgx_offset_0[];
static union { u32 w[331]; u8 v[0x52c]; } fzgx_pool_init_test_pad = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E4F4E00, 0x4D415354, 0x45522052, 0x45435600, 0x4D415354, 0x45522053, 0x454E4400, 0x534C4156,
    0x45205345, 0x4E440000, 0x534C4156, 0x45205245, 0x43560000, 0x494E4954, 0x0, 0x54455354,
    0x0, 0x54455354, 0x454E4400, 0x53455455, 0x50000000, 0x53455455, 0x505F444F, 0x4E450000,
    0x53455455, 0x505F434F, 0x554E5445, 0x52000000, 0x53455455, 0x505F434E, 0x545F444F, 0x4E450000,
    0x554E4C49, 0x4E4B0000, 0x434F494E, 0x0, 0x454E5452, 0x595F5741, 0x49540000, 0x4348414C,
    0x4C454E47, 0x45520000, 0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000, 0x454E5452, 0x59000000,
    0x454E5452, 0x595F4F4B, 0x0, 0x53494E47, 0x4C454348, 0x45434B00, 0x53494E47, 0x4C454348,
    0x45434B5F, 0x4F4B0000, 0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F, 0x4B000000, 0x434F5552,
    0x53455F44, 0x41544100, 0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000, 0x4D414348, 0x494E4500,
    0x4D414348, 0x494E455F, 0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46, 0x49475F4F, 0x4B000000,
    0x434F554E, 0x54455241, 0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954, 0x0, 0x4C494E4B,
    0x57414954, 0x4F4B0000, 0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49, 0x56455259, 0x53544152,
    0x54000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x0, 0x4C494E4B, 0x44454C49, 0x56455259,
    0x4F4B0000, 0x4C494E4B, 0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649, 0x45570000, 0x434F5552,
    0x53455649, 0x45575F4F, 0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B, 0x5354414E, 0x44425900,
    0x4C494E4B, 0x4F4B0000, 0x4C494E4B, 0x0, 0x50415553, 0x45000000, 0x4552524F, 0x52000000,
    (u32)lbl_8_data_7E50__fzgx_offset_0, (u32)lbl_8_data_7E54__fzgx_offset_0, (u32)lbl_8_data_7E60__fzgx_offset_0, (u32)lbl_8_data_7E6C__fzgx_offset_0, (u32)lbl_8_data_7E78__fzgx_offset_0, (u32)lbl_8_data_7E84__fzgx_offset_0, (u32)lbl_8_data_7E8C__fzgx_offset_0, (u32)lbl_8_data_7E94__fzgx_offset_0,
    (u32)lbl_8_data_7E9C__fzgx_offset_0, (u32)lbl_8_data_7EA4__fzgx_offset_0, (u32)lbl_8_data_7EB0__fzgx_offset_0, (u32)lbl_8_data_7EC0__fzgx_offset_0, (u32)lbl_8_data_7ED0__fzgx_offset_0, (u32)lbl_8_data_7ED8__fzgx_offset_0, (u32)lbl_8_data_7EE0__fzgx_offset_0, (u32)lbl_8_data_7EEC__fzgx_offset_0,
    (u32)lbl_8_data_7EF8__fzgx_offset_0, (u32)lbl_8_data_7F08__fzgx_offset_0, (u32)lbl_8_data_7F10__fzgx_offset_0, (u32)lbl_8_data_7F1C__fzgx_offset_0, (u32)lbl_8_data_7F28__fzgx_offset_0, (u32)lbl_8_data_7F38__fzgx_offset_0, (u32)lbl_8_data_7F40__fzgx_offset_0, (u32)lbl_8_data_7F4C__fzgx_offset_0,
    (u32)lbl_8_data_7F58__fzgx_offset_0, (u32)lbl_8_data_7F68__fzgx_offset_0, (u32)lbl_8_data_7F70__fzgx_offset_0, (u32)lbl_8_data_7F7C__fzgx_offset_0, (u32)lbl_8_data_7F84__fzgx_offset_0, (u32)lbl_8_data_7F90__fzgx_offset_0, (u32)lbl_8_data_7FA0__fzgx_offset_0, (u32)lbl_8_data_7FAC__fzgx_offset_0,
    (u32)lbl_8_data_7FB8__fzgx_offset_0, (u32)lbl_8_data_7FC0__fzgx_offset_0, (u32)lbl_8_data_7FD4__fzgx_offset_0, (u32)lbl_8_data_7FE4__fzgx_offset_0, (u32)lbl_8_data_7FF4__fzgx_offset_0, (u32)lbl_8_data_8000__fzgx_offset_0, (u32)lbl_8_data_800C__fzgx_offset_0, (u32)lbl_8_data_801C__fzgx_offset_0,
    (u32)lbl_8_data_8024__fzgx_offset_0, (u32)lbl_8_data_8030__fzgx_offset_0, (u32)lbl_8_data_8038__fzgx_offset_0, (u32)lbl_8_data_8040__fzgx_offset_0, (u32)lbl_8_data_8048__fzgx_offset_0, 0x4F564552, 0x54414B45, 0x0,
    0x4A554D50, 0x0, 0x454E454D, 0x59484954, 0x0, 0x57414C4C, 0x48495400, 0x53494445,
    0x42595349, 0x44450000, 0x53544152, 0x54000000, 0x474F414C, 0x0, 0x4C415000, (u32)lbl_8_data_8104__fzgx_offset_0,
    (u32)lbl_8_data_8110__fzgx_offset_0, (u32)lbl_8_data_8118__fzgx_offset_0, (u32)lbl_8_data_8124__fzgx_offset_0, (u32)lbl_8_data_812C__fzgx_offset_0, (u32)lbl_8_data_8138__fzgx_offset_0, (u32)lbl_8_data_8140__fzgx_offset_0, (u32)lbl_8_data_8148__fzgx_offset_0, 0x6D656E75,
    0x0, 0x77617463, 0x68000000, (u32)lbl_8_data_816C__fzgx_offset_0, (u32)fn_8_988C__fzgx_offset_0, (u32)fn_8_9B04__fzgx_offset_0, (u32)fn_8_9B40__fzgx_offset_0, (u32)lbl_8_data_8174__fzgx_offset_0,
    (u32)fn_8_8C48__fzgx_offset_0, (u32)fn_8_8E00__fzgx_offset_0, (u32)fn_8_8C80__fzgx_offset_0, 0x41434345, 0x4C455241, 0x544F520A, 0x0, 0x0,
    0x8341834E, 0x835A838B, 0xA000000, (u32)lbl_8_data_819C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_81B0__fzgx_offset_0, 0x73706565, 0x64207570, 0x2E0A0000, 0x89C191AC, 0x82B582DC, 0x82B78142, 0xA000000,
    (u32)lbl_8_data_81D4__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81E0__fzgx_offset_0, 0x41495220, 0x4252414B,
    0x450A0000, 0x83478341, 0x8375838C, 0x815B834C, 0xA000000, (u32)lbl_8_data_8208__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8214__fzgx_offset_0, 0x736C6F77, 0x20646F77, 0x6E2E0A00, 0x8CB891AC, 0x82B582DC,
    0x82B78142, 0xA000000, (u32)lbl_8_data_823C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8248__fzgx_offset_0,
    0x53544545, 0x52494E47, 0xA000000, 0x83588365, 0x8341838A, 0x8393834F, 0xA000000, (u32)lbl_8_data_8270__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_827C__fzgx_offset_0, 0x436F6E74, 0x726F6C20, 0x796F7572,
    0x206D6163, 0x68696E65, 0x20776974, 0x680A0000, 0x83588365, 0x8341838A, 0x8393834F, 0x82C68341,
    0x834E835A, 0x838B82C5, 0x837D8356, 0x839382F0, 0xA000000, (u32)lbl_8_data_82A4__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_82C0__fzgx_offset_0, 0x74686520, 0x73746565, 0x72696E67, 0x20776865, 0x656C2061,
    0x6E642074, 0x68652061, 0x6363656C, 0x65726174, 0x6F722E0A, 0x0, 0x83528393, 0x8367838D,
    0x815B838B, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420A00, (u32)lbl_8_data_82FC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8328__fzgx_offset_0, 0x44415348, 0x20504C41, 0x54450A00, 0x835F8362, 0x83568385,
    0x8376838C, 0x815B8367, 0xA000000  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[26]; char *v[26]; } fzgx_pool_init_test_a = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_8_data_835C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8368__fzgx_offset_0, 0x53706565, 0x64207769,
    0x6C6C2074, 0x656D706F, 0x72617269, 0x6C792069, 0x6E637265, 0x6173650A, 0x0, 0x92CA89DF,
    0x82B782E9, 0x82C68358, 0x8373815B, 0x836882AA, 0x88EA8E9E, 0x934982C9, 0x83418362, 0x837682B5,
    0x82DC82B7, 0xA000000
}};
static union { u32 w[15]; char *v[15]; } fzgx_pool_init_test_b = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_8_data_8394__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_83B8__fzgx_offset_0, 0x7768656E, 0x20706173,
    0x73696E67, 0x206F7665, 0x72206120, 0x64617368, 0x20706C61, 0x74652E0A, 0x0
}};
static union { u32 w[4]; char *v[4]; } fzgx_pool_init_test_c = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_8_data_83FC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0
}};


#pragma section code_type ".fzgxpool"
static void fzgx_base_order_data(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: the TU references .data before its other sections */
    s = *(u8 *)&fzgx_pool_init_test_pad.v;
    s = *(u8 *)&fzgx_pool_init_test_a.v;
    s = *(u8 *)&fzgx_pool_init_test_b.v;
    s = *(u8 *)&fzgx_pool_init_test_c.v;
}
#pragma section code_type ".text"

#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fn_8_7484_pool_primer(volatile f32 *f, volatile f64 *d, s32 i) {  /* fzgx-allow: S2 pool primer sink */
    *d = 15.0;
    *f = 320.0f;
    *f = 640.0f;
    *d = 1.0;
    *f = 150.0f;
    *f = 0.1f;
    *f = 20.0f;
    *f = 0.8333333f;
    *d = i;
}

__declspec(section ".fzgxpool") void fn_8_7484_pool_primer2(volatile f32 *f, volatile f64 *d, s32 i, Color_8_7484 *c) {  /* fzgx-allow: S2 pool primer sink */
    Color_8_7484 white = { 0xFF, 0xFF, 0xFF, 0x00 };

    *d = i;
    *c = white;
    *f = 0.0f;
    *f = 1.0f;
    *f = 0.5f;
    *f = 0.09f;
    *f = 5.0f;
    *f = 255.0f;
}

__declspec(section ".fzgxpool") void fn_8_7484_pool_primer3(Color_8_7484 *c) {
    Color_8_7484 white2 = { 0xFF, 0xFF, 0xFF, 0x00 };
    Color_8_7484 white3 = { 0xFF, 0xFF, 0xFF, 0x00 };

    c[0] = white2;
    c[1] = white3;
}

void fn_8_7484(void) {
    s32 x;
    u32 base;
    f32 t;
    f32 alpha;
    s32 now;

    now = lbl_8_bss_3CC;
    base = (u32)&lbl_8_data_7E50;
    if (now < 15.0) {
        t = 1.0 - (f32)now / 15.0;
        x = (f32)(640.0f * t) + 320.0f;
    } else if (now > (s32)lbl_8_bss_3D0.unk_0 - 15.0) {
        t = 1.0 - (f32)((s32)lbl_8_bss_3D0.unk_0 - now) / 15.0;
        x = 320.0f - (f32)(640.0f * t);
    } else {
        t = 0.0f;
        x = 320;
    }
    alpha = 1.0f - t;
    alpha = alpha * alpha;
    if ((s32)lbl_8_bss_3D0.unk_0 - 60 > now && now > (s32)lbl_8_bss_3D0.unk_0 - 180) {
        fn_8_CC4C(0x12e, 0xad);
    }
    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_49590(0.5f);
    fn_1_495C8(9);
    fn_1_496FC(x, 150.0f);
    fn_1_4954C(0.09f);
    if (lbl_801A66B4 == 5) {
        fn_1_4955C(1.0f, 1.0f);
    } else {
        fn_1_4955C(0.8333333f, 0.8333333f);
    }
    fn_1_495A0(alpha);
    fn_1_4D0A0();
    fn_1_49738((u32)fn_1_5233C);
    fn_1_49748(5.0f);
    fn_1_4AE0C(fzgx_pool_init_test_a.v[lbl_801A66B4]);
    fn_1_49738(0);
    fn_1_4AE0C(fzgx_pool_init_test_b.v[lbl_801A66B4]);
    fn_1_4AE0C(fzgx_pool_init_test_c.v[lbl_801A66B4]);
    {
        Color_8_7484 arg;
        Color_8_7484 color = { 0xFF, 0xFF, 0xFF, 0x00 };

        color.a = 255.0f * alpha;
        arg = color;
        fn_1_4D0D4(&arg, 20.0f);
    }
}
/* fzgx:end fn_8_7484 */

/* fzgx:begin fn_8_7C4C pool */
#include "rel/title/operation.h"

extern u8 fn_8_8C48__fzgx_offset_0[];
extern u8 fn_8_8C80__fzgx_offset_0[];
extern u8 fn_8_8E00__fzgx_offset_0[];
extern u8 fn_8_988C__fzgx_offset_0[];
extern u8 fn_8_9B04__fzgx_offset_0[];
extern u8 fn_8_9B40__fzgx_offset_0[];
extern u8 lbl_8_data_7E50__fzgx_offset_0[];
extern u8 lbl_8_data_7E54__fzgx_offset_0[];
extern u8 lbl_8_data_7E60__fzgx_offset_0[];
extern u8 lbl_8_data_7E6C__fzgx_offset_0[];
extern u8 lbl_8_data_7E78__fzgx_offset_0[];
extern u8 lbl_8_data_7E84__fzgx_offset_0[];
extern u8 lbl_8_data_7E8C__fzgx_offset_0[];
extern u8 lbl_8_data_7E94__fzgx_offset_0[];
extern u8 lbl_8_data_7E9C__fzgx_offset_0[];
extern u8 lbl_8_data_7EA4__fzgx_offset_0[];
extern u8 lbl_8_data_7EB0__fzgx_offset_0[];
extern u8 lbl_8_data_7EC0__fzgx_offset_0[];
extern u8 lbl_8_data_7ED0__fzgx_offset_0[];
extern u8 lbl_8_data_7ED8__fzgx_offset_0[];
extern u8 lbl_8_data_7EE0__fzgx_offset_0[];
extern u8 lbl_8_data_7EEC__fzgx_offset_0[];
extern u8 lbl_8_data_7EF8__fzgx_offset_0[];
extern u8 lbl_8_data_7F08__fzgx_offset_0[];
extern u8 lbl_8_data_7F10__fzgx_offset_0[];
extern u8 lbl_8_data_7F1C__fzgx_offset_0[];
extern u8 lbl_8_data_7F28__fzgx_offset_0[];
extern u8 lbl_8_data_7F38__fzgx_offset_0[];
extern u8 lbl_8_data_7F40__fzgx_offset_0[];
extern u8 lbl_8_data_7F4C__fzgx_offset_0[];
extern u8 lbl_8_data_7F58__fzgx_offset_0[];
extern u8 lbl_8_data_7F68__fzgx_offset_0[];
extern u8 lbl_8_data_7F70__fzgx_offset_0[];
extern u8 lbl_8_data_7F7C__fzgx_offset_0[];
extern u8 lbl_8_data_7F84__fzgx_offset_0[];
extern u8 lbl_8_data_7F90__fzgx_offset_0[];
extern u8 lbl_8_data_7FA0__fzgx_offset_0[];
extern u8 lbl_8_data_7FAC__fzgx_offset_0[];
extern u8 lbl_8_data_7FB8__fzgx_offset_0[];
extern u8 lbl_8_data_7FC0__fzgx_offset_0[];
extern u8 lbl_8_data_7FD4__fzgx_offset_0[];
extern u8 lbl_8_data_7FE4__fzgx_offset_0[];
extern u8 lbl_8_data_7FF4__fzgx_offset_0[];
extern u8 lbl_8_data_8000__fzgx_offset_0[];
extern u8 lbl_8_data_800C__fzgx_offset_0[];
extern u8 lbl_8_data_801C__fzgx_offset_0[];
extern u8 lbl_8_data_8024__fzgx_offset_0[];
extern u8 lbl_8_data_8030__fzgx_offset_0[];
extern u8 lbl_8_data_8038__fzgx_offset_0[];
extern u8 lbl_8_data_8040__fzgx_offset_0[];
extern u8 lbl_8_data_8048__fzgx_offset_0[];
extern u8 lbl_8_data_8104__fzgx_offset_0[];
extern u8 lbl_8_data_8110__fzgx_offset_0[];
extern u8 lbl_8_data_8118__fzgx_offset_0[];
extern u8 lbl_8_data_8124__fzgx_offset_0[];
extern u8 lbl_8_data_812C__fzgx_offset_0[];
extern u8 lbl_8_data_8138__fzgx_offset_0[];
extern u8 lbl_8_data_8140__fzgx_offset_0[];
extern u8 lbl_8_data_8148__fzgx_offset_0[];
extern u8 lbl_8_data_816C__fzgx_offset_0[];
extern u8 lbl_8_data_8174__fzgx_offset_0[];
extern u8 lbl_8_data_819C__fzgx_offset_0[];
extern u8 lbl_8_data_81AC__fzgx_offset_0[];
extern u8 lbl_8_data_81B0__fzgx_offset_0[];
extern u8 lbl_8_data_81D4__fzgx_offset_0[];
extern u8 lbl_8_data_81E0__fzgx_offset_0[];
extern u8 lbl_8_data_8208__fzgx_offset_0[];
extern u8 lbl_8_data_8214__fzgx_offset_0[];
extern u8 lbl_8_data_823C__fzgx_offset_0[];
extern u8 lbl_8_data_8248__fzgx_offset_0[];
extern u8 lbl_8_data_8270__fzgx_offset_0[];
extern u8 lbl_8_data_827C__fzgx_offset_0[];
extern u8 lbl_8_data_82A4__fzgx_offset_0[];
extern u8 lbl_8_data_82C0__fzgx_offset_0[];
extern u8 lbl_8_data_82FC__fzgx_offset_0[];
extern u8 lbl_8_data_8328__fzgx_offset_0[];
extern u8 lbl_8_data_835C__fzgx_offset_0[];
extern u8 lbl_8_data_8368__fzgx_offset_0[];
extern u8 lbl_8_data_8394__fzgx_offset_0[];
extern u8 lbl_8_data_83B8__fzgx_offset_0[];
extern u8 lbl_8_data_83FC__fzgx_offset_0[];
extern u8 lbl_8_data_8438__fzgx_offset_0[];
extern u8 lbl_8_data_8448__fzgx_offset_0[];
extern u8 lbl_8_data_8470__fzgx_offset_0[];
extern u8 lbl_8_data_8490__fzgx_offset_0[];
extern u8 lbl_8_data_84D0__fzgx_offset_0[];
extern u8 lbl_8_data_84DC__fzgx_offset_0[];
extern u8 lbl_8_data_8504__fzgx_offset_0[];
extern u8 lbl_8_data_8528__fzgx_offset_0[];
extern u8 lbl_8_data_856C__fzgx_offset_0[];
extern u8 lbl_8_data_8578__fzgx_offset_0[];
extern u8 lbl_8_data_85A0__fzgx_offset_0[];
extern u8 lbl_8_data_85D8__fzgx_offset_0[];
extern u8 lbl_8_data_8618__fzgx_offset_0[];
extern u8 lbl_8_data_8644__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_8_data_7E50[462] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E4F4E00, 0x4D415354, 0x45522052, 0x45435600, 0x4D415354, 0x45522053, 0x454E4400, 0x534C4156,
    0x45205345, 0x4E440000, 0x534C4156, 0x45205245, 0x43560000, 0x494E4954, 0x0, 0x54455354,
    0x0, 0x54455354, 0x454E4400, 0x53455455, 0x50000000, 0x53455455, 0x505F444F, 0x4E450000,
    0x53455455, 0x505F434F, 0x554E5445, 0x52000000, 0x53455455, 0x505F434E, 0x545F444F, 0x4E450000,
    0x554E4C49, 0x4E4B0000, 0x434F494E, 0x0, 0x454E5452, 0x595F5741, 0x49540000, 0x4348414C,
    0x4C454E47, 0x45520000, 0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000, 0x454E5452, 0x59000000,
    0x454E5452, 0x595F4F4B, 0x0, 0x53494E47, 0x4C454348, 0x45434B00, 0x53494E47, 0x4C454348,
    0x45434B5F, 0x4F4B0000, 0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F, 0x4B000000, 0x434F5552,
    0x53455F44, 0x41544100, 0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000, 0x4D414348, 0x494E4500,
    0x4D414348, 0x494E455F, 0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46, 0x49475F4F, 0x4B000000,
    0x434F554E, 0x54455241, 0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954, 0x0, 0x4C494E4B,
    0x57414954, 0x4F4B0000, 0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49, 0x56455259, 0x53544152,
    0x54000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x0, 0x4C494E4B, 0x44454C49, 0x56455259,
    0x4F4B0000, 0x4C494E4B, 0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649, 0x45570000, 0x434F5552,
    0x53455649, 0x45575F4F, 0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B, 0x5354414E, 0x44425900,
    0x4C494E4B, 0x4F4B0000, 0x4C494E4B, 0x0, 0x50415553, 0x45000000, 0x4552524F, 0x52000000,
    (u32)lbl_8_data_7E50__fzgx_offset_0, (u32)lbl_8_data_7E54__fzgx_offset_0, (u32)lbl_8_data_7E60__fzgx_offset_0, (u32)lbl_8_data_7E6C__fzgx_offset_0, (u32)lbl_8_data_7E78__fzgx_offset_0, (u32)lbl_8_data_7E84__fzgx_offset_0, (u32)lbl_8_data_7E8C__fzgx_offset_0, (u32)lbl_8_data_7E94__fzgx_offset_0,
    (u32)lbl_8_data_7E9C__fzgx_offset_0, (u32)lbl_8_data_7EA4__fzgx_offset_0, (u32)lbl_8_data_7EB0__fzgx_offset_0, (u32)lbl_8_data_7EC0__fzgx_offset_0, (u32)lbl_8_data_7ED0__fzgx_offset_0, (u32)lbl_8_data_7ED8__fzgx_offset_0, (u32)lbl_8_data_7EE0__fzgx_offset_0, (u32)lbl_8_data_7EEC__fzgx_offset_0,
    (u32)lbl_8_data_7EF8__fzgx_offset_0, (u32)lbl_8_data_7F08__fzgx_offset_0, (u32)lbl_8_data_7F10__fzgx_offset_0, (u32)lbl_8_data_7F1C__fzgx_offset_0, (u32)lbl_8_data_7F28__fzgx_offset_0, (u32)lbl_8_data_7F38__fzgx_offset_0, (u32)lbl_8_data_7F40__fzgx_offset_0, (u32)lbl_8_data_7F4C__fzgx_offset_0,
    (u32)lbl_8_data_7F58__fzgx_offset_0, (u32)lbl_8_data_7F68__fzgx_offset_0, (u32)lbl_8_data_7F70__fzgx_offset_0, (u32)lbl_8_data_7F7C__fzgx_offset_0, (u32)lbl_8_data_7F84__fzgx_offset_0, (u32)lbl_8_data_7F90__fzgx_offset_0, (u32)lbl_8_data_7FA0__fzgx_offset_0, (u32)lbl_8_data_7FAC__fzgx_offset_0,
    (u32)lbl_8_data_7FB8__fzgx_offset_0, (u32)lbl_8_data_7FC0__fzgx_offset_0, (u32)lbl_8_data_7FD4__fzgx_offset_0, (u32)lbl_8_data_7FE4__fzgx_offset_0, (u32)lbl_8_data_7FF4__fzgx_offset_0, (u32)lbl_8_data_8000__fzgx_offset_0, (u32)lbl_8_data_800C__fzgx_offset_0, (u32)lbl_8_data_801C__fzgx_offset_0,
    (u32)lbl_8_data_8024__fzgx_offset_0, (u32)lbl_8_data_8030__fzgx_offset_0, (u32)lbl_8_data_8038__fzgx_offset_0, (u32)lbl_8_data_8040__fzgx_offset_0, (u32)lbl_8_data_8048__fzgx_offset_0, 0x4F564552, 0x54414B45, 0x0,
    0x4A554D50, 0x0, 0x454E454D, 0x59484954, 0x0, 0x57414C4C, 0x48495400, 0x53494445,
    0x42595349, 0x44450000, 0x53544152, 0x54000000, 0x474F414C, 0x0, 0x4C415000, (u32)lbl_8_data_8104__fzgx_offset_0,
    (u32)lbl_8_data_8110__fzgx_offset_0, (u32)lbl_8_data_8118__fzgx_offset_0, (u32)lbl_8_data_8124__fzgx_offset_0, (u32)lbl_8_data_812C__fzgx_offset_0, (u32)lbl_8_data_8138__fzgx_offset_0, (u32)lbl_8_data_8140__fzgx_offset_0, (u32)lbl_8_data_8148__fzgx_offset_0, 0x6D656E75,
    0x0, 0x77617463, 0x68000000, (u32)lbl_8_data_816C__fzgx_offset_0, (u32)fn_8_988C__fzgx_offset_0, (u32)fn_8_9B04__fzgx_offset_0, (u32)fn_8_9B40__fzgx_offset_0, (u32)lbl_8_data_8174__fzgx_offset_0,
    (u32)fn_8_8C48__fzgx_offset_0, (u32)fn_8_8E00__fzgx_offset_0, (u32)fn_8_8C80__fzgx_offset_0, 0x41434345, 0x4C455241, 0x544F520A, 0x0, 0x0,
    0x8341834E, 0x835A838B, 0xA000000, (u32)lbl_8_data_819C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_81B0__fzgx_offset_0, 0x73706565, 0x64207570, 0x2E0A0000, 0x89C191AC, 0x82B582DC, 0x82B78142, 0xA000000,
    (u32)lbl_8_data_81D4__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81E0__fzgx_offset_0, 0x41495220, 0x4252414B,
    0x450A0000, 0x83478341, 0x8375838C, 0x815B834C, 0xA000000, (u32)lbl_8_data_8208__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8214__fzgx_offset_0, 0x736C6F77, 0x20646F77, 0x6E2E0A00, 0x8CB891AC, 0x82B582DC,
    0x82B78142, 0xA000000, (u32)lbl_8_data_823C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8248__fzgx_offset_0,
    0x53544545, 0x52494E47, 0xA000000, 0x83588365, 0x8341838A, 0x8393834F, 0xA000000, (u32)lbl_8_data_8270__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_827C__fzgx_offset_0, 0x436F6E74, 0x726F6C20, 0x796F7572,
    0x206D6163, 0x68696E65, 0x20776974, 0x680A0000, 0x83588365, 0x8341838A, 0x8393834F, 0x82C68341,
    0x834E835A, 0x838B82C5, 0x837D8356, 0x839382F0, 0xA000000, (u32)lbl_8_data_82A4__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_82C0__fzgx_offset_0, 0x74686520, 0x73746565, 0x72696E67, 0x20776865, 0x656C2061,
    0x6E642074, 0x68652061, 0x6363656C, 0x65726174, 0x6F722E0A, 0x0, 0x83528393, 0x8367838D,
    0x815B838B, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420A00, (u32)lbl_8_data_82FC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8328__fzgx_offset_0, 0x44415348, 0x20504C41, 0x54450A00, 0x835F8362, 0x83568385,
    0x8376838C, 0x815B8367, 0xA000000, (u32)lbl_8_data_835C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_8_data_8368__fzgx_offset_0, 0x53706565, 0x64207769, 0x6C6C2074, 0x656D706F, 0x72617269, 0x6C792069, 0x6E637265,
    0x6173650A, 0x0, 0x92CA89DF, 0x82B782E9, 0x82C68358, 0x8373815B, 0x836882AA, 0x88EA8E9E,
    0x934982C9, 0x83418362, 0x837682B5, 0x82DC82B7, 0xA000000, (u32)lbl_8_data_8394__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_83B8__fzgx_offset_0, 0x7768656E, 0x20706173, 0x73696E67, 0x206F7665, 0x72206120,
    0x64617368, 0x20706C61, 0x74652E0A, 0x0, (u32)lbl_8_data_83FC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, 0x4E4F524D, 0x414C2054, 0x55524E0A, 0x0, 0x836D815B, 0x837D838B,
    0x835E815B, 0x83930A00, (u32)lbl_8_data_8438__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8448__fzgx_offset_0,
    0x436F726E, 0x6572696E, 0x67207769, 0x74682074, 0x68652073, 0x74656572, 0x696E672E, 0xA000000,
    0x83588365, 0x8341838A, 0x8393834F, 0x82BE82AF, 0x82CC8352, 0x815B8369, 0x838A8393, 0x834F82C5,  /* fzgx-allow: A1 retail data bytes */
    0x82B78142, 0xA000000, (u32)lbl_8_data_8470__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8490__fzgx_offset_0,
    0x534C4944, 0x45205455, 0x524E0A00, 0x83588389, 0x83438368, 0x835E815B, 0x83930A00, (u32)lbl_8_data_84D0__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_84DC__fzgx_offset_0, 0x50756C6C, 0x20746865, 0x20706164,
    0x646C6520, 0x7768696C, 0x6520636F, 0x726E6572, 0x696E672E, 0xA000000, 0x8352815B, 0x8369838A,
    0x8393834F, 0x928682C9, 0x83708368, 0x838B838C, 0x836F815B, 0x82F088F8, 0x82AB82DC, 0x82B78142,
    0xA000000, (u32)lbl_8_data_8504__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8528__fzgx_offset_0, 0x44524946,
    0x54205455, 0x524E0A00, 0x8368838A, 0x83748367, 0x835E815B, 0x83930A00
};
static u32 fzgx_pool_data_lbl_8_data_7E50_738[6] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_8_data_856C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8578__fzgx_offset_0
};
static u32 fzgx_pool_data_lbl_8_data_85A0[24] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4272616B, 0x65206265, 0x666F7265, 0x20796F75, 0x20656E74, 0x65722074, 0x68652063, 0x75727665,
    0x20776974, 0x68207468, 0x65206163, 0x63656C65, 0x7261746F, 0x720A0000, 0x8352815B, 0x8369815B,
    0x82CC8EE8, 0x914F82C5, 0x8341834E, 0x835A838B, 0x82F093A5, 0x82F182BE, 0x82DC82DC, 0xA000000
};
static u32 fzgx_pool_data_lbl_8_data_7E50_7B0[6] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_8_data_85A0__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_85D8__fzgx_offset_0
};
static u32 fzgx_pool_data_lbl_8_data_8618[23] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x73746570, 0x70656420, 0x6F6E2C20, 0x7468656E, 0x20747572, 0x6E207468, 0x65207374, 0x65657269,
    0x6E672077, 0x6865656C, 0x2E0A0000, 0x8375838C, 0x815B834C, 0x82F08C79, 0x82AD93A5, 0x82DD82C8,  /* fzgx-allow: A1 retail data bytes */
    0x82AA82E7, 0x83588365, 0x8341838A, 0x8393834F, 0x82F090D8, 0x82E882DC, 0x82B70A00
};
static u32 fzgx_pool_data_lbl_8_data_7E50_824[6] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_8_data_8618__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8644__fzgx_offset_0
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_8_data_7E50(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_8_data_7E50;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_7E50_738;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_85A0;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_7E50_7B0;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_8618;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_7E50_824;
}
#pragma section code_type ".text"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
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
static const unsigned long fzgx_pool_table2[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 1.0f;
    s = 0.5f;
    s = 0.09000000357627869f;
    s = 5.0f;
    s = 255.0f;
}
static const unsigned long fzgx_pool_table4[5] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
/* pool +0x60 (the Color8 literal) and +0x64 (0.3f) are first used by fn_8_7C4C itself */
#pragma section code_type ".text"

typedef struct {
    u8 r, g, b, a;
} Color8;

extern s32 lbl_801A66B4;
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
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D0D4(Color8 *, f32);
extern void fn_1_5233C(void);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_8_bss_3D0;
u32 lbl_8_bss_3D0_fill_3D4[91];
u8 lbl_8_bss_540;
u8 lbl_8_bss_3D0_gap_541;
u16 lbl_8_bss_3D0_gap_541_fill_542;
u32 lbl_8_bss_544[3];
u32 fzgx_obj_lbl_8_bss_550;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_8_bss_3D0;
    s = *(u8 *)&lbl_8_bss_3D0_fill_3D4;
    s = *(u8 *)&lbl_8_bss_540;
    s = *(u8 *)&lbl_8_bss_3D0_gap_541;
    s = *(u8 *)&lbl_8_bss_3D0_gap_541_fill_542;
    s = *(u8 *)&lbl_8_bss_544;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_550;
}
#pragma section code_type ".text"

void fn_8_7C4C(void)
{
    Color8 arg;
    f32 t;
    s32 x;

    if ((s32)lbl_8_bss_3CC == (s32)fzgx_obj_lbl_8_bss_3D0 - 1) {
        fn_1_A2D84(0xA9120900);
    }
    if ((s32)lbl_8_bss_3CC < 15.0) {
        t = 1.0 - (f32)(s32)lbl_8_bss_3CC / 15.0;
        x = 320.0f + (f32)(640.0f * t);
    } else if ((s32)lbl_8_bss_3CC > (s32)fzgx_obj_lbl_8_bss_3D0 - 15.0) {
        t = 1.0 - (f32)(s32)(fzgx_obj_lbl_8_bss_3D0 - lbl_8_bss_3CC) / 15.0;
        x = 320.0f - (f32)(640.0f * t);
    } else {
        t = 0.0f;
        x = 320;
    }
    fn_1_49410();
    t = (1.0f - t) * (1.0f - t);
    fn_1_495B0(0x80000000);
    fn_1_49590(0.3f);
    fn_1_495C8(9);
    fn_1_496FC(x, 150.0f);
    fn_1_4954C(0.09f);
    if (lbl_801A66B4 == 5) {
        fn_1_4955C(1.0f, 1.0f);
    } else {
        fn_1_4955C(0.8333333f, 0.8333333f);
    }
    fn_1_495A0(t);
    fn_1_4D0A0();
    fn_1_49738((u32)fn_1_5233C);
    fn_1_49748(5.0f);
    fn_1_4AE0C(*(const char **)((((u8 *)fzgx_pool_data_lbl_8_data_7E50_738)) + lbl_801A66B4 * 4));
    fn_1_49738(0);
    fn_1_4AE0C(((const char **)(((u8 *)fzgx_pool_data_lbl_8_data_7E50_7B0)))[lbl_801A66B4]);
    fn_1_4AE0C(((const char **)(((u8 *)fzgx_pool_data_lbl_8_data_7E50_824)))[lbl_801A66B4]);
    {
        /* alpha starts at 0 in the retail literal (0xFFFFFF00) and is filled from the fade */
        Color8 color = { 0xFF, 0xFF, 0xFF, 0x00 };
        color.a = 255.0f * t;
        arg = color;
        fn_1_4D0D4(&arg, 20.0f);
    }
}
/* fzgx:end fn_8_7C4C */

/* fzgx:begin fn_8_7EFC */
#include "rel/title/operation.h"

extern s32 lbl_801A66B4;
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
extern void fn_1_49738(void (*)(void));
extern void fn_1_5233C(void);
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
typedef struct { u8 r, g, b, a; } Color;
extern void fn_1_4D0D4(void *, f32);
typedef struct { u8 pad[0x854]; const char *a[24]; const char *b[27]; const char *c[11]; } TextData;
extern void pool_f32(f32);
extern void pool_f64(f64);

/* Primers: reproduce the TU's shared literal pool layout (lbl_8_rodata_160). */
#pragma push
#pragma force_active on
#pragma section code_type ".fzgxpool"
void shared_pool_primer(s32 n) {
    pool_f64(15.0);
    pool_f32(320.0f);
    pool_f32(640.0f);
    pool_f64(1.0);
    pool_f32(150.0f);
    pool_f32(0.1f);
    pool_f32(20.0f);
    pool_f32(0.8333333f);
    pool_f64(4503601774854144.0);
}
void shared_pool_primer_b(void) {
    { Color white = {255, 255, 255, 0}; fn_1_4D0D4(&white, 20.0f); }
    pool_f32(0.0f);
    pool_f32(1.0f);
    pool_f32(0.5f);
    pool_f32(0.09f);
    pool_f32(5.0f);
    pool_f32(255.0f);
}
void shared_pool_primer_c(void) {
    struct { Color first[6]; f32 scale; } colors = {
        {{255, 255, 255, 0}, {255, 255, 255, 0}, {255, 255, 255, 0},
         {255, 255, 255, 0}, {255, 255, 255, 0}, {255, 255, 255, 0}},
        0.3f
    };
    fn_1_4D0D4(&colors, 20.0f);
}
#pragma pop

#pragma push
#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_8_7EFC(void) {
    s32 x;
    f32 t;
    f32 alpha;
    TextData *data = (TextData *)&lbl_8_data_7E50;
    Color color;
    if ((s32)lbl_8_bss_3CC == (s32)lbl_8_bss_3D0.unk_0 - 1)
        fn_1_A2D84(0xA9120100);
    if ((s32)lbl_8_bss_3CC < 15.0) {
        t = 1.0 - (f32)(s32)lbl_8_bss_3CC / 15.0;
        x = 320.0f + (f32)(640.0f * t);
    } else if ((s32)lbl_8_bss_3CC > (s32)lbl_8_bss_3D0.unk_0 - 15.0) {
        t = 1.0 - (f32)((s32)lbl_8_bss_3D0.unk_0 - (s32)lbl_8_bss_3CC) / 15.0;
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
    fn_1_496FC(x, 150.0f);
    fn_1_4954C(0.09f);
    if (lbl_801A66B4 == 5) fn_1_4955C(1.0f, 1.0f);
    else fn_1_4955C(0.8333333f, 0.8333333f);
    fn_1_495A0(alpha);
    fn_1_4D0A0();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    /* the table address is held in its own value so the lookup stays an indexed load */
    { const char *text = (const char *)data->a; text = ((const char **)text)[lbl_801A66B4]; fn_1_4AE0C(text); }
    fn_1_49738(0);
    { const char *text = (const char *)data->b; text = ((const char **)text)[lbl_801A66B4]; fn_1_4AE0C(text); }
    { const char *text = (const char *)data->c; text = ((const char **)text)[lbl_801A66B4]; fn_1_4AE0C(text); }
    {
        Color white = {255, 255, 255, 0};
        white.a = (s32)(255.0f * alpha);
        color = white;
        fn_1_4D0D4(&color, 20.0f);
    }
}
#pragma pop
/* fzgx:end fn_8_7EFC */

/* fzgx:begin fn_8_8440 */
#include "rel/title/operation.h"

extern s32 lbl_801A66B4;
extern void fn_1_A2D84(u32);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32,f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32,f32);
extern void fn_1_495A0(f32);
extern void fn_1_4D0A0(void);
extern void fn_1_49738(void (*)(void));
extern void fn_1_5233C(void);
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *,...);
typedef struct { u8 r,g,b,a; } Color;
extern void fn_1_4D0D4(void *,f32);
typedef struct { u8 pad[0xa2c]; const char *a[21]; const char *b[11]; const char *c[11]; } TextData;
extern u32 fn_8_CC4C(u32,u32);
extern void pool_f32(f32);
extern void pool_f64(f64);
#pragma push
#pragma force_active on
#pragma section code_type ".fzgxpool"
void shared_pool_primer(s32 n) {
    pool_f64(15.0);
    pool_f32(320.0f);
    pool_f32(640.0f);
    pool_f64(1.0);
    pool_f32(150.0f);
    pool_f32(0.1f);
    pool_f32(20.0f);
    pool_f32(0.8333333f);
    pool_f64(4503601774854144.0);
}
void shared_pool_primer_b(void) {
    { Color white = {255,255,255,0}; fn_1_4D0D4(&white,20.0f); }
    pool_f32(0.0f);
    pool_f32(1.0f);
    pool_f32(0.5f);
    pool_f32(0.09f);
    pool_f32(5.0f);
    pool_f32(255.0f);
}
void shared_pool_primer_c(void) {
    struct { Color first[6]; f32 scale; Color last[2]; } colors = {
        {{255,255,255,0}, {255,255,255,0}, {255,255,255,0},
         {255,255,255,0}, {255,255,255,0}, {255,255,255,0}},
        0.3f, {{255,255,255,0}, {255,255,255,0}}
    };
    fn_1_4D0D4(&colors,20.0f);
}
#pragma pop
#pragma push
#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_8_8440(void) {
    s32 x;
    f32 t;
    f32 alpha;
    TextData *data = (TextData *)&lbl_8_data_7E50;
    Color color;
    if ((s32)lbl_8_bss_3CC == (s32)lbl_8_bss_3D0.unk_0 - 1)
        fn_1_A2D84(0xA9120200);
    if ((s32)lbl_8_bss_3CC < 15.0) {
        t = 1.0 - (f32)(s32)lbl_8_bss_3CC / 15.0;
        x = 320.0f + (f32)(640.0f * t);
    } else if ((s32)lbl_8_bss_3CC > (s32)lbl_8_bss_3D0.unk_0 - 15.0) {
        t = 1.0 - (f32)((s32)lbl_8_bss_3D0.unk_0 - (s32)lbl_8_bss_3CC) / 15.0;
        x = 320.0f - (f32)(640.0f * t);
    } else {
        t = 0.0f;
        x = 320;
    }
    alpha = (1.0f-t)*(1.0f-t);
    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_49590(0.5f);
    fn_1_495C8(9);
    fn_1_496FC(x,150.0f);
    fn_1_4954C(0.09f);
    if (lbl_801A66B4 == 5) fn_1_4955C(1.0f,1.0f);
    else fn_1_4955C(0.8333333f,0.8333333f);
    fn_1_495A0(alpha);
    fn_1_4D0A0();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    { const char *text = (const char *)data->a; text = ((const char **)text)[lbl_801A66B4]; fn_1_4AE0C(text); }
    fn_1_49738(0);
    { const char *text = (const char *)data->b; text = ((const char **)text)[lbl_801A66B4]; fn_1_4AE0C(text); }
    { const char *text = (const char *)data->c; text = ((const char **)text)[lbl_801A66B4]; fn_1_4AE0C(text); }
    {
        Color white = {255,255,255,0};
        white.a = (s32)(255.0f*alpha);
        color = white;
        fn_1_4D0D4(&color,20.0f);
    }
    fn_8_CC4C(505,394);
}
/* fzgx:end fn_8_8440 */

/* fzgx:begin fn_8_86FC */
#include "rel/title/operation.h"

extern s32 lbl_801A66B4;
extern void fn_1_A2D84(u32);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32,f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32,f32);
extern void fn_1_495A0(f32);
extern void fn_1_4D0A0(void);
extern void fn_1_5233C(void);
extern void fn_1_49738(void (*)(void));
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *,...);
typedef struct { u8 r,g,b,a; } Color;
extern u8 fn_8_8C48__fzgx_offset_0[];
extern u8 fn_8_8C80__fzgx_offset_0[];
extern u8 fn_8_8E00__fzgx_offset_0[];
extern u8 fn_8_988C__fzgx_offset_0[];
extern u8 fn_8_9B04__fzgx_offset_0[];
extern u8 fn_8_9B40__fzgx_offset_0[];
extern u8 lbl_8_data_7E50__fzgx_offset_0[];
extern u8 lbl_8_data_7E54__fzgx_offset_0[];
extern u8 lbl_8_data_7E60__fzgx_offset_0[];
extern u8 lbl_8_data_7E6C__fzgx_offset_0[];
extern u8 lbl_8_data_7E78__fzgx_offset_0[];
extern u8 lbl_8_data_7E84__fzgx_offset_0[];
extern u8 lbl_8_data_7E8C__fzgx_offset_0[];
extern u8 lbl_8_data_7E94__fzgx_offset_0[];
extern u8 lbl_8_data_7E9C__fzgx_offset_0[];
extern u8 lbl_8_data_7EA4__fzgx_offset_0[];
extern u8 lbl_8_data_7EB0__fzgx_offset_0[];
extern u8 lbl_8_data_7EC0__fzgx_offset_0[];
extern u8 lbl_8_data_7ED0__fzgx_offset_0[];
extern u8 lbl_8_data_7ED8__fzgx_offset_0[];
extern u8 lbl_8_data_7EE0__fzgx_offset_0[];
extern u8 lbl_8_data_7EEC__fzgx_offset_0[];
extern u8 lbl_8_data_7EF8__fzgx_offset_0[];
extern u8 lbl_8_data_7F08__fzgx_offset_0[];
extern u8 lbl_8_data_7F10__fzgx_offset_0[];
extern u8 lbl_8_data_7F1C__fzgx_offset_0[];
extern u8 lbl_8_data_7F28__fzgx_offset_0[];
extern u8 lbl_8_data_7F38__fzgx_offset_0[];
extern u8 lbl_8_data_7F40__fzgx_offset_0[];
extern u8 lbl_8_data_7F4C__fzgx_offset_0[];
extern u8 lbl_8_data_7F58__fzgx_offset_0[];
extern u8 lbl_8_data_7F68__fzgx_offset_0[];
extern u8 lbl_8_data_7F70__fzgx_offset_0[];
extern u8 lbl_8_data_7F7C__fzgx_offset_0[];
extern u8 lbl_8_data_7F84__fzgx_offset_0[];
extern u8 lbl_8_data_7F90__fzgx_offset_0[];
extern u8 lbl_8_data_7FA0__fzgx_offset_0[];
extern u8 lbl_8_data_7FAC__fzgx_offset_0[];
extern u8 lbl_8_data_7FB8__fzgx_offset_0[];
extern u8 lbl_8_data_7FC0__fzgx_offset_0[];
extern u8 lbl_8_data_7FD4__fzgx_offset_0[];
extern u8 lbl_8_data_7FE4__fzgx_offset_0[];
extern u8 lbl_8_data_7FF4__fzgx_offset_0[];
extern u8 lbl_8_data_8000__fzgx_offset_0[];
extern u8 lbl_8_data_800C__fzgx_offset_0[];
extern u8 lbl_8_data_801C__fzgx_offset_0[];
extern u8 lbl_8_data_8024__fzgx_offset_0[];
extern u8 lbl_8_data_8030__fzgx_offset_0[];
extern u8 lbl_8_data_8038__fzgx_offset_0[];
extern u8 lbl_8_data_8040__fzgx_offset_0[];
extern u8 lbl_8_data_8048__fzgx_offset_0[];
extern u8 lbl_8_data_8104__fzgx_offset_0[];
extern u8 lbl_8_data_8110__fzgx_offset_0[];
extern u8 lbl_8_data_8118__fzgx_offset_0[];
extern u8 lbl_8_data_8124__fzgx_offset_0[];
extern u8 lbl_8_data_812C__fzgx_offset_0[];
extern u8 lbl_8_data_8138__fzgx_offset_0[];
extern u8 lbl_8_data_8140__fzgx_offset_0[];
extern u8 lbl_8_data_8148__fzgx_offset_0[];
extern u8 lbl_8_data_816C__fzgx_offset_0[];
extern u8 lbl_8_data_8174__fzgx_offset_0[];
extern u8 lbl_8_data_819C__fzgx_offset_0[];
extern u8 lbl_8_data_81AC__fzgx_offset_0[];
extern u8 lbl_8_data_81B0__fzgx_offset_0[];
extern u8 lbl_8_data_81D4__fzgx_offset_0[];
extern u8 lbl_8_data_81E0__fzgx_offset_0[];
extern u8 lbl_8_data_8208__fzgx_offset_0[];
extern u8 lbl_8_data_8214__fzgx_offset_0[];
extern u8 lbl_8_data_823C__fzgx_offset_0[];
extern u8 lbl_8_data_8248__fzgx_offset_0[];
extern u8 lbl_8_data_8270__fzgx_offset_0[];
extern u8 lbl_8_data_827C__fzgx_offset_0[];
extern u8 lbl_8_data_82A4__fzgx_offset_0[];
extern u8 lbl_8_data_82C0__fzgx_offset_0[];
extern u8 lbl_8_data_82FC__fzgx_offset_0[];
extern u8 lbl_8_data_8328__fzgx_offset_0[];
extern u8 lbl_8_data_835C__fzgx_offset_0[];
extern u8 lbl_8_data_8368__fzgx_offset_0[];
extern u8 lbl_8_data_8394__fzgx_offset_0[];
extern u8 lbl_8_data_83B8__fzgx_offset_0[];
extern u8 lbl_8_data_83FC__fzgx_offset_0[];
extern u8 lbl_8_data_8438__fzgx_offset_0[];
extern u8 lbl_8_data_8448__fzgx_offset_0[];
extern u8 lbl_8_data_8470__fzgx_offset_0[];
extern u8 lbl_8_data_8490__fzgx_offset_0[];
extern u8 lbl_8_data_84D0__fzgx_offset_0[];
extern u8 lbl_8_data_84DC__fzgx_offset_0[];
extern u8 lbl_8_data_8504__fzgx_offset_0[];
extern u8 lbl_8_data_8528__fzgx_offset_0[];
extern u8 lbl_8_data_856C__fzgx_offset_0[];
extern u8 lbl_8_data_8578__fzgx_offset_0[];
extern u8 lbl_8_data_85A0__fzgx_offset_0[];
extern u8 lbl_8_data_85D8__fzgx_offset_0[];
extern u8 lbl_8_data_8618__fzgx_offset_0[];
extern u8 lbl_8_data_8644__fzgx_offset_0[];
extern u8 lbl_8_data_868C__fzgx_offset_0[];
extern u8 lbl_8_data_8698__fzgx_offset_0[];
extern u8 lbl_8_data_86BC__fzgx_offset_0[];
extern u8 lbl_8_data_86E8__fzgx_offset_0[];
extern u8 lbl_8_data_871C__fzgx_offset_0[];
extern u8 lbl_8_data_874C__fzgx_offset_0[];
extern u8 lbl_8_data_8788__fzgx_offset_0[];
extern u8 lbl_8_data_87B4__fzgx_offset_0[];
extern u8 lbl_8_data_87F4__fzgx_offset_0[];
extern u8 lbl_8_data_881C__fzgx_offset_0[];
extern u8 lbl_8_data_8858__fzgx_offset_0[];
extern u8 lbl_8_data_8868__fzgx_offset_0[];
extern u8 lbl_8_data_8894__fzgx_offset_0[];
extern u8 lbl_8_data_88AC__fzgx_offset_0[];
extern u8 lbl_8_data_88E8__fzgx_offset_0[];
extern u8 lbl_8_data_8914__fzgx_offset_0[];
extern u8 lbl_8_data_891C__fzgx_offset_0[];
extern u8 lbl_8_data_893C__fzgx_offset_0[];
extern u8 lbl_8_data_8958__fzgx_offset_0[];
extern u8 lbl_8_data_898C__fzgx_offset_0[];
extern u8 lbl_8_data_89B0__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_8_data_7E50[693] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E4F4E00, 0x4D415354, 0x45522052, 0x45435600, 0x4D415354, 0x45522053, 0x454E4400, 0x534C4156,
    0x45205345, 0x4E440000, 0x534C4156, 0x45205245, 0x43560000, 0x494E4954, 0x0, 0x54455354,
    0x0, 0x54455354, 0x454E4400, 0x53455455, 0x50000000, 0x53455455, 0x505F444F, 0x4E450000,
    0x53455455, 0x505F434F, 0x554E5445, 0x52000000, 0x53455455, 0x505F434E, 0x545F444F, 0x4E450000,
    0x554E4C49, 0x4E4B0000, 0x434F494E, 0x0, 0x454E5452, 0x595F5741, 0x49540000, 0x4348414C,
    0x4C454E47, 0x45520000, 0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000, 0x454E5452, 0x59000000,
    0x454E5452, 0x595F4F4B, 0x0, 0x53494E47, 0x4C454348, 0x45434B00, 0x53494E47, 0x4C454348,
    0x45434B5F, 0x4F4B0000, 0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F, 0x4B000000, 0x434F5552,
    0x53455F44, 0x41544100, 0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000, 0x4D414348, 0x494E4500,
    0x4D414348, 0x494E455F, 0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46, 0x49475F4F, 0x4B000000,
    0x434F554E, 0x54455241, 0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954, 0x0, 0x4C494E4B,
    0x57414954, 0x4F4B0000, 0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49, 0x56455259, 0x53544152,
    0x54000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x0, 0x4C494E4B, 0x44454C49, 0x56455259,
    0x4F4B0000, 0x4C494E4B, 0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649, 0x45570000, 0x434F5552,
    0x53455649, 0x45575F4F, 0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B, 0x5354414E, 0x44425900,
    0x4C494E4B, 0x4F4B0000, 0x4C494E4B, 0x0, 0x50415553, 0x45000000, 0x4552524F, 0x52000000,
    (u32)lbl_8_data_7E50__fzgx_offset_0, (u32)lbl_8_data_7E54__fzgx_offset_0, (u32)lbl_8_data_7E60__fzgx_offset_0, (u32)lbl_8_data_7E6C__fzgx_offset_0, (u32)lbl_8_data_7E78__fzgx_offset_0, (u32)lbl_8_data_7E84__fzgx_offset_0, (u32)lbl_8_data_7E8C__fzgx_offset_0, (u32)lbl_8_data_7E94__fzgx_offset_0,
    (u32)lbl_8_data_7E9C__fzgx_offset_0, (u32)lbl_8_data_7EA4__fzgx_offset_0, (u32)lbl_8_data_7EB0__fzgx_offset_0, (u32)lbl_8_data_7EC0__fzgx_offset_0, (u32)lbl_8_data_7ED0__fzgx_offset_0, (u32)lbl_8_data_7ED8__fzgx_offset_0, (u32)lbl_8_data_7EE0__fzgx_offset_0, (u32)lbl_8_data_7EEC__fzgx_offset_0,
    (u32)lbl_8_data_7EF8__fzgx_offset_0, (u32)lbl_8_data_7F08__fzgx_offset_0, (u32)lbl_8_data_7F10__fzgx_offset_0, (u32)lbl_8_data_7F1C__fzgx_offset_0, (u32)lbl_8_data_7F28__fzgx_offset_0, (u32)lbl_8_data_7F38__fzgx_offset_0, (u32)lbl_8_data_7F40__fzgx_offset_0, (u32)lbl_8_data_7F4C__fzgx_offset_0,
    (u32)lbl_8_data_7F58__fzgx_offset_0, (u32)lbl_8_data_7F68__fzgx_offset_0, (u32)lbl_8_data_7F70__fzgx_offset_0, (u32)lbl_8_data_7F7C__fzgx_offset_0, (u32)lbl_8_data_7F84__fzgx_offset_0, (u32)lbl_8_data_7F90__fzgx_offset_0, (u32)lbl_8_data_7FA0__fzgx_offset_0, (u32)lbl_8_data_7FAC__fzgx_offset_0,
    (u32)lbl_8_data_7FB8__fzgx_offset_0, (u32)lbl_8_data_7FC0__fzgx_offset_0, (u32)lbl_8_data_7FD4__fzgx_offset_0, (u32)lbl_8_data_7FE4__fzgx_offset_0, (u32)lbl_8_data_7FF4__fzgx_offset_0, (u32)lbl_8_data_8000__fzgx_offset_0, (u32)lbl_8_data_800C__fzgx_offset_0, (u32)lbl_8_data_801C__fzgx_offset_0,
    (u32)lbl_8_data_8024__fzgx_offset_0, (u32)lbl_8_data_8030__fzgx_offset_0, (u32)lbl_8_data_8038__fzgx_offset_0, (u32)lbl_8_data_8040__fzgx_offset_0, (u32)lbl_8_data_8048__fzgx_offset_0, 0x4F564552, 0x54414B45, 0x0,
    0x4A554D50, 0x0, 0x454E454D, 0x59484954, 0x0, 0x57414C4C, 0x48495400, 0x53494445,
    0x42595349, 0x44450000, 0x53544152, 0x54000000, 0x474F414C, 0x0, 0x4C415000, (u32)lbl_8_data_8104__fzgx_offset_0,
    (u32)lbl_8_data_8110__fzgx_offset_0, (u32)lbl_8_data_8118__fzgx_offset_0, (u32)lbl_8_data_8124__fzgx_offset_0, (u32)lbl_8_data_812C__fzgx_offset_0, (u32)lbl_8_data_8138__fzgx_offset_0, (u32)lbl_8_data_8140__fzgx_offset_0, (u32)lbl_8_data_8148__fzgx_offset_0, 0x6D656E75,
    0x0, 0x77617463, 0x68000000, (u32)lbl_8_data_816C__fzgx_offset_0, (u32)fn_8_988C__fzgx_offset_0, (u32)fn_8_9B04__fzgx_offset_0, (u32)fn_8_9B40__fzgx_offset_0, (u32)lbl_8_data_8174__fzgx_offset_0,
    (u32)fn_8_8C48__fzgx_offset_0, (u32)fn_8_8E00__fzgx_offset_0, (u32)fn_8_8C80__fzgx_offset_0, 0x41434345, 0x4C455241, 0x544F520A, 0x0, 0x0,
    0x8341834E, 0x835A838B, 0xA000000, (u32)lbl_8_data_819C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_81B0__fzgx_offset_0, 0x73706565, 0x64207570, 0x2E0A0000, 0x89C191AC, 0x82B582DC, 0x82B78142, 0xA000000,
    (u32)lbl_8_data_81D4__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81E0__fzgx_offset_0, 0x41495220, 0x4252414B,
    0x450A0000, 0x83478341, 0x8375838C, 0x815B834C, 0xA000000, (u32)lbl_8_data_8208__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8214__fzgx_offset_0, 0x736C6F77, 0x20646F77, 0x6E2E0A00, 0x8CB891AC, 0x82B582DC,
    0x82B78142, 0xA000000, (u32)lbl_8_data_823C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8248__fzgx_offset_0,
    0x53544545, 0x52494E47, 0xA000000, 0x83588365, 0x8341838A, 0x8393834F, 0xA000000, (u32)lbl_8_data_8270__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_827C__fzgx_offset_0, 0x436F6E74, 0x726F6C20, 0x796F7572,
    0x206D6163, 0x68696E65, 0x20776974, 0x680A0000, 0x83588365, 0x8341838A, 0x8393834F, 0x82C68341,
    0x834E835A, 0x838B82C5, 0x837D8356, 0x839382F0, 0xA000000, (u32)lbl_8_data_82A4__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_82C0__fzgx_offset_0, 0x74686520, 0x73746565, 0x72696E67, 0x20776865, 0x656C2061,
    0x6E642074, 0x68652061, 0x6363656C, 0x65726174, 0x6F722E0A, 0x0, 0x83528393, 0x8367838D,
    0x815B838B, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420A00, (u32)lbl_8_data_82FC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8328__fzgx_offset_0, 0x44415348, 0x20504C41, 0x54450A00, 0x835F8362, 0x83568385,
    0x8376838C, 0x815B8367, 0xA000000, (u32)lbl_8_data_835C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_8_data_8368__fzgx_offset_0, 0x53706565, 0x64207769, 0x6C6C2074, 0x656D706F, 0x72617269, 0x6C792069, 0x6E637265,
    0x6173650A, 0x0, 0x92CA89DF, 0x82B782E9, 0x82C68358, 0x8373815B, 0x836882AA, 0x88EA8E9E,
    0x934982C9, 0x83418362, 0x837682B5, 0x82DC82B7, 0xA000000, (u32)lbl_8_data_8394__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_83B8__fzgx_offset_0, 0x7768656E, 0x20706173, 0x73696E67, 0x206F7665, 0x72206120,
    0x64617368, 0x20706C61, 0x74652E0A, 0x0, (u32)lbl_8_data_83FC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, 0x4E4F524D, 0x414C2054, 0x55524E0A, 0x0, 0x836D815B, 0x837D838B,
    0x835E815B, 0x83930A00, (u32)lbl_8_data_8438__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8448__fzgx_offset_0,
    0x436F726E, 0x6572696E, 0x67207769, 0x74682074, 0x68652073, 0x74656572, 0x696E672E, 0xA000000,
    0x83588365, 0x8341838A, 0x8393834F, 0x82BE82AF, 0x82CC8352, 0x815B8369, 0x838A8393, 0x834F82C5,  /* fzgx-allow: A1 retail data bytes */
    0x82B78142, 0xA000000, (u32)lbl_8_data_8470__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8490__fzgx_offset_0,
    0x534C4944, 0x45205455, 0x524E0A00, 0x83588389, 0x83438368, 0x835E815B, 0x83930A00, (u32)lbl_8_data_84D0__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_84DC__fzgx_offset_0, 0x50756C6C, 0x20746865, 0x20706164,
    0x646C6520, 0x7768696C, 0x6520636F, 0x726E6572, 0x696E672E, 0xA000000, 0x8352815B, 0x8369838A,
    0x8393834F, 0x928682C9, 0x83708368, 0x838B838C, 0x836F815B, 0x82F088F8, 0x82AB82DC, 0x82B78142,
    0xA000000, (u32)lbl_8_data_8504__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8528__fzgx_offset_0, 0x44524946,
    0x54205455, 0x524E0A00, 0x8368838A, 0x83748367, 0x835E815B, 0x83930A00, (u32)lbl_8_data_856C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8578__fzgx_offset_0, 0x4272616B, 0x65206265, 0x666F7265, 0x20796F75,
    0x20656E74, 0x65722074, 0x68652063, 0x75727665, 0x20776974, 0x68207468, 0x65206163, 0x63656C65,
    0x7261746F, 0x720A0000, 0x8352815B, 0x8369815B, 0x82CC8EE8, 0x914F82C5, 0x8341834E, 0x835A838B,
    0x82F093A5, 0x82F182BE, 0x82DC82DC, 0xA000000, (u32)lbl_8_data_85A0__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_85D8__fzgx_offset_0, 0x73746570, 0x70656420, 0x6F6E2C20, 0x7468656E, 0x20747572, 0x6E207468,
    0x65207374, 0x65657269, 0x6E672077, 0x6865656C, 0x2E0A0000, 0x8375838C, 0x815B834C, 0x82F08C79,  /* fzgx-allow: A1 retail data bytes */
    0x82AD93A5, 0x82DD82C8, 0x82AA82E7, 0x83588365, 0x8341838A, 0x8393834F, 0x82F090D8, 0x82E882DC,
    0x82B70A00, (u32)lbl_8_data_8618__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8644__fzgx_offset_0, 0x424F4F53,
    0x5445520A, 0x0, 0x8375815B, 0x83588367, 0xA000000, (u32)lbl_8_data_868C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8698__fzgx_offset_0, 0x54686520, 0x73706565, 0x64206F66, 0x20746865, 0x206D6163,
    0x68696E65, 0x2077696C, 0x6C20696E, 0x7374616E, 0x746C790A, 0x0, 0x328EFC96, 0xDA82A982,
    0xE78E6797, 0x7089C294, 0x5C82C582, 0xB781420A, 0x0, (u32)lbl_8_data_86BC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_86E8__fzgx_offset_0, 0x696E6372, 0x65617365, 0x20627920, 0x70726573, 0x73696E67,
    0x20746865, 0x20626F6F, 0x73742062, 0x7574746F, 0x6E206F6E, 0x63652E0A, 0x0, 0x8F758AD4,
    0x934982C9, 0x83588373, 0x815B8368, 0x82AA8341, 0x83628376, 0x82B582DC, 0x82B78142, 0xA000000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_8_data_871C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_874C__fzgx_offset_0, 0x55736520, 0x74686520,
    0x626F6F73, 0x74657220, 0x6173206D, 0x616E7920, 0x74696D65, 0x73206173, 0x20796F75, 0x2077616E,
    0x743B0A00, 0x8375815B, 0x8358835E, 0x815B82C9, 0x89F19094, 0x90A78CC0, 0x82CD82A0, 0x82E882DC,  /* fzgx-allow: A1 retail data bytes */
    0x82B982F1, 0x82AA8141, 0xA000000, (u32)lbl_8_data_8788__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_87B4__fzgx_offset_0, 0x686F7765, 0x7665722C, 0x20757361, 0x67652064, 0x65706C65, 0x74657320, 0x74686520,
    0x656E6572, 0x67792E0A, 0x0, 0x8E679770, 0x82B782E9, 0x82C68347, 0x836C838B, 0x834D815B,
    0x82F08FC1, 0x94EF82B5, 0x82DC82B7, 0x81420A00, (u32)lbl_8_data_87F4__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_881C__fzgx_offset_0, 0x454E4552, 0x4759204D, 0x45544552, 0xA000000, 0x83478369, 0x8357815B,
    0x8381815B, 0x835E815B, 0xA000000, (u32)lbl_8_data_8858__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_8868__fzgx_offset_0, 0x4E6F2065, 0x6E657267, 0x792C206E, 0x6F20626F, 0x6F73742E, 0xA000000, 0x8347836C,
    0x838B834D, 0x815B82AA, 0x3082C982, 0xC882E982, 0xC6837581, 0x5B835883, 0x5E815B82, 0xCD0A0000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_8_data_8894__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_88AC__fzgx_offset_0, 0x8E679770, 0x82C582AB,
    0x82DC82B9, 0x82F18142, 0xA000000, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0,
    (u32)lbl_8_data_88E8__fzgx_offset_0, 0x5049540A, 0x0, 0x83738362, 0x83670A00
};
static u32 fzgx_pool_data_lbl_8_data_7E50_AD4[6] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_8_data_8914__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_891C__fzgx_offset_0
};
static u32 fzgx_pool_data_lbl_8_data_893C[14] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x456E6572, 0x67792063, 0x616E2062, 0x65207265, 0x706C656E, 0x69736865, 0x640A0000, 0x83738362,
    0x83678347, 0x838A8341, 0x82F09196, 0x8D7382B7, 0x82E982C6, 0xA000000
};
static u32 fzgx_pool_data_lbl_8_data_7E50_B24[6] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_8_data_893C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8958__fzgx_offset_0
};
static u32 fzgx_pool_data_lbl_8_data_898C[16] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x62792074, 0x72617665, 0x6C696E67, 0x20746872, 0x6F756768, 0x20746865, 0x20706974, 0x20617265,
    0x612E0A00, 0x8347836C, 0x838B834D, 0x815B82AA, 0x89F1959C, 0x82B582DC, 0x82B78142, 0xA000000  /* fzgx-allow: A1 retail data bytes */
};
static u32 fzgx_pool_data_lbl_8_data_7E50_B7C[6] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_8_data_898C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_89B0__fzgx_offset_0
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_8_data_7E50(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_8_data_7E50;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_7E50_AD4;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_893C;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_7E50_B24;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_898C;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_7E50_B7C;
}
#pragma section code_type ".text"

extern void fn_1_4D0D4(Color *,f32);
extern u32 fn_8_CC4C(u32,u32);
extern void primer_d(f64);
extern void primer_f(f32);
extern void primer_c(Color);
#pragma section code_type ".fzgxpool"
void shared_pool_primer(void) {
 primer_d(15.0); primer_f(320.0f); primer_f(640.0f); primer_d(1.0);
 primer_f(150.0f); primer_f(0.1f); primer_f(20.0f); primer_f(0.8333333f);
 primer_d(4503601774854144.0);
}
void shared_pool_primer2(void) {
 { Color c = {255,255,255,0}; primer_c(c); }
 primer_f(0.0f);
 primer_f(1.0f); primer_f(0.5f); primer_f(0.09f); primer_f(5.0f); primer_f(255.0f);
}
void shared_pool_primer3(void) {
 { Color c = {255,255,255,0}; primer_c(c); }
 { Color c = {255,255,255,0}; primer_c(c); }
 { Color c = {255,255,255,0}; primer_c(c); }
 { Color c = {255,255,255,0}; primer_c(c); }
 { Color c = {255,255,255,0}; primer_c(c); }
 { Color c = {255,255,255,0}; primer_c(c); }
 primer_f(0.3f);
}
void shared_pool_primer4(void) {
 { Color c = {255,255,255,0}; primer_c(c); }
 { Color c = {255,255,255,0}; primer_c(c); }
 { Color c = {255,255,255,0}; primer_c(c); }
}
#pragma section code_type ".text"
typedef struct {
 u8 pad[0xAD4];
 const char *a[20];
 const char *b[22];
 const char *c[1];
} TextData;
void fn_8_86FC(void) {
    s32 x;
    f32 t, alpha;
    
    if ((s32)lbl_8_bss_3CC == (s32)lbl_8_bss_3D0.unk_0-1)
        fn_1_A2D84(0xA9120300);
    if ((s32)lbl_8_bss_3CC < 15.0) {
        t = 1.0 - (f32)(s32)lbl_8_bss_3CC / 15.0;
        x = 320.0f + (f32)(640.0f*t);
    } else if ((s32)lbl_8_bss_3CC > (s32)lbl_8_bss_3D0.unk_0 - 15.0) {
        t = 1.0 - (f32)((s32)lbl_8_bss_3D0.unk_0-(s32)lbl_8_bss_3CC) / 15.0;
        x = 320.0f - (f32)(640.0f*t);
    } else {
        t = 0.0f;
        x = 320;
    }
    alpha = (1.0f-t)*(1.0f-t);
    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_49590(0.5f);
    fn_1_495C8(9);
    fn_1_496FC(x,150.0f);
    fn_1_4954C(0.09f);
    if (lbl_801A66B4 == 5) fn_1_4955C(1.0f,1.0f);
    else fn_1_4955C(0.8333333f,0.8333333f);
    fn_1_495A0(alpha);
    fn_1_4D0A0();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    { const char **table = ((const char * *)(((u8 *)fzgx_pool_data_lbl_8_data_7E50_AD4))); fn_1_4AE0C(table[lbl_801A66B4]); }
    fn_1_49738(0);
    { const char **table = ((const char * *)(((u8 *)fzgx_pool_data_lbl_8_data_7E50_B24))); fn_1_4AE0C(table[lbl_801A66B4]); }
    { const char **table = ((const char * *)(((u8 *)fzgx_pool_data_lbl_8_data_7E50_B7C))); fn_1_4AE0C(table[lbl_801A66B4]); }
    { Color copy; Color c = {255,255,255,0};
    c.a = 255.0f*alpha;
    copy = c; fn_1_4D0D4(&copy,20.0f); }
    fn_8_CC4C(505,394);
}
/* fzgx:end fn_8_86FC */

/* fzgx:begin fn_8_89B8 */
#include "rel/title/operation.h"

extern s32 lbl_801A66B4;
extern void fn_8_CC4C(u32, u32);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_4D0A0(void);
extern void fn_1_5233C(void);
extern void fn_1_49738(void (*)(void));
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
typedef struct { u8 r, g, b, a; } Color;
extern void fn_1_4D0D4(Color *, f32);
typedef struct {
    u8 pad[0xBA8];
    const char *a[24];
    const char *b[25];
    const char *c[1];
} TextData;

/* Literal-pool primer: reproduces the TU's shared literal pool layout. */
extern void primer_d(f64);
extern void primer_f(f32);
extern void primer_c(Color);
#pragma push
#pragma force_active on
#pragma section code_type ".fzgxpool"
void shared_pool_primer(void) {
    primer_d(15.0); primer_f(320.0f); primer_f(640.0f); primer_d(1.0);
    primer_f(150.0f); primer_f(0.1f); primer_f(20.0f); primer_f(0.8333333f);
    primer_d(4503601774854144.0);
}
void shared_pool_primer2(void) {
    { Color c = {255, 255, 255, 0}; primer_c(c); }
    primer_f(0.0f);
    primer_f(1.0f); primer_f(0.5f); primer_f(0.09f); primer_f(5.0f); primer_f(255.0f);
}
void shared_pool_primer3(void) {
    { Color c = {255, 255, 255, 0}; primer_c(c); }
    { Color c = {255, 255, 255, 0}; primer_c(c); }
    { Color c = {255, 255, 255, 0}; primer_c(c); }
    { Color c = {255, 255, 255, 0}; primer_c(c); }
    { Color c = {255, 255, 255, 0}; primer_c(c); }
    { Color c = {255, 255, 255, 0}; primer_c(c); }
    primer_f(0.3f);
}
void shared_pool_primer4(void) {
    { Color c = {255, 255, 255, 0}; primer_c(c); }
    { Color c = {255, 255, 255, 0}; primer_c(c); }
    { Color c = {255, 255, 255, 0}; primer_c(c); }
    { Color c = {255, 255, 255, 0}; primer_c(c); }
}
#pragma pop

#pragma push
#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_8_89B8(void) {
    s32 x;
    f32 t;
    f32 alpha;
    TextData *data = (TextData *)&lbl_8_data_7E50;
    Color color;

    if ((s32)lbl_8_bss_3CC < 15.0) {
        t = 1.0 - (f32)(s32)lbl_8_bss_3CC / 15.0;
        x = 320.0f + (f32)(640.0f * t);
    } else if ((s32)lbl_8_bss_3CC > (s32)lbl_8_bss_3D0.unk_0 - 15.0) {
        t = 1.0 - (f32)((s32)lbl_8_bss_3D0.unk_0 - (s32)lbl_8_bss_3CC) / 15.0;
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
    fn_1_496FC(x, 150.0f);
    fn_1_4954C(0.09f);
    if (lbl_801A66B4 == 5) fn_1_4955C(1.0f, 1.0f);
    else fn_1_4955C(0.8333333f, 0.8333333f);
    fn_1_495A0(alpha);
    fn_1_4D0A0();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    { const char *text = (const char *)data->a; text = ((const char **)text)[lbl_801A66B4]; fn_1_4AE0C(text); }
    fn_1_49738(0);
    { const char *text = (const char *)data->b; text = ((const char **)text)[lbl_801A66B4]; fn_1_4AE0C(text); }
    { const char *text = (const char *)data->c; text = ((const char **)text)[lbl_801A66B4]; fn_1_4AE0C(text); }
    {
        Color white = {255, 255, 255, 0};
        white.a = (s32)(255.0f * alpha);
        color = white;
        fn_1_4D0D4(&color, 20.0f);
    }
    fn_8_CC4C(0x1b7, 0xb1);
}
#pragma pop
/* fzgx:end fn_8_89B8 */

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

/* fzgx:begin fn_8_9B44 */
#include "rel/title/operation.h"

typedef struct {
    u8 r, g, b, a;
} fn_8_9B44_Color;

typedef struct {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad_18[0x24];
} fn_8_9B44_Sub;

/* The TU's own .bss objects, addressed off one section base (lbl_8_bss_2A8). */
s16 fzgx_obj_lbl_8_bss_2A8;
s32 fzgx_obj_lbl_8_bss_2AC;
s32 fzgx_obj_lbl_8_bss_2B0;
s32 fzgx_obj_lbl_8_bss_2B4;
s32 fzgx_obj_lbl_8_bss_2B8;
s32 fzgx_obj_lbl_8_bss_2BC;
u8 fzgx_obj_lbl_8_bss_2C0[0xC];
fn_8_9B44_Sub lbl_8_bss_2C0__fzgx_offset_C;
fn_8_9B44_Sub lbl_8_bss_2C0__fzgx_offset_48;
fn_8_9B44_Sub lbl_8_bss_2C0__fzgx_offset_84;
fn_8_9B44_Sub lbl_8_bss_2C0__fzgx_offset_C0;
s32 lbl_8_bss_2C0__fzgx_offset_FC[4];
s32 fzgx_obj_lbl_8_bss_3CC;
s32 fzgx_obj_lbl_8_bss_3D0;

extern s32 lbl_801A66B4;
extern void fn_1_5233C(void);
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
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D0D4(void *, f32);
extern f32 fn_1_9E14C(u32, void *, f32);

#pragma section RX ".fzgxpool" ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_primer_fn_8_9B44(void) {
    volatile u32 sink; /* primer: fixes the .bss first-access order */
    sink = fzgx_obj_lbl_8_bss_2A8;
    sink = fzgx_obj_lbl_8_bss_2AC;
    sink = fzgx_obj_lbl_8_bss_2B0;
    sink = fzgx_obj_lbl_8_bss_2B4;
    sink = fzgx_obj_lbl_8_bss_2B8;
    sink = fzgx_obj_lbl_8_bss_2BC;
    sink = fzgx_obj_lbl_8_bss_2C0[0];
    sink = lbl_8_bss_2C0__fzgx_offset_C.unk_4;
    sink = lbl_8_bss_2C0__fzgx_offset_48.unk_4;
    sink = lbl_8_bss_2C0__fzgx_offset_84.unk_4;
    sink = lbl_8_bss_2C0__fzgx_offset_C0.unk_4;
    sink = lbl_8_bss_2C0__fzgx_offset_FC[0];
    sink = fzgx_obj_lbl_8_bss_3CC;
    sink = fzgx_obj_lbl_8_bss_3D0;
}

/* The retail TU's literal pool (lbl_8_rodata_160) in retail order, up to this function's
 * own literals. Dropped at integration. */
#pragma section code_type ".fzgxpool"
static void fzgx_pool_layout_00(void) {
    volatile f64 d;  /* fzgx-allow: S2 layout primer sink: MWCC pools literals in first-use order */
    volatile f32 s;  /* fzgx-allow: S2 layout primer sink */
    volatile s32 n;  /* fzgx-allow: S2 layout primer source */
    d = 15.0;
    s = 320.0f;
    s = 640.0f;
    d = 1.0;
    s = 150.0f;
    s = 0.1f;
    s = 20.0f;
    s = 0.8333333f;
    s = (f32)n;
}
static const u32 fzgx_pool_30[1] = {0xFFFFFF00};
static void fzgx_pool_layout_34(void) {
    volatile f32 s;  /* fzgx-allow: S2 layout primer sink */
    s = 0.0f;
    s = 1.0f;
    s = 0.5f;
    s = 0.09f;
    s = 5.0f;
    s = 255.0f;
}
static const u32 fzgx_pool_4C[6] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00};
static const f32 fzgx_pool_64[1] = {0.3f};
static const u32 fzgx_pool_68[5] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00};
static const f32 fzgx_pool_7C[12] = {
    0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.01f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.01f,
};
static void fzgx_pool_layout_AC(void) {
    volatile f32 s;  /* fzgx-allow: S2 layout primer sink */
    s = 60.0f;
}
static const f32 fzgx_pool_B0[23] = {
    0.7f, 0.01f, 240.0f, 45.0f, 0.001f, 100.0f, -200.0f, 120.0f, 200.0f, -120.0f, -0.01f,
    10.0f, -10240.0f, 1.8f, -1.8f, -20.0f, -4096.0f, -2048.0f, 1.1f, -0.51f, 4096.0f, -1.1f, 0.8f,
};
#pragma section code_type ".text"

/* Inlined helper: MWCC keeps an inline parameter a real variable (it is not propagated into
 * its single use), so the ratio is evaluated before the 2.0f / 1.0f constants. */
static inline f32 fn_8_9B44_fade(f32 q) {
    return 2.0f * (1.0f - q);
}

void fn_8_9B44(void) {
    f32 first;
    s32 x;
    f32 t;
    f32 alpha;
    f32 f;
    f64 blend;

    if (fzgx_obj_lbl_8_bss_3CC == fzgx_obj_lbl_8_bss_3D0 - 1) {
        fn_1_A2D84(0xA9100100);
    }
    if (fzgx_obj_lbl_8_bss_3CC < 15.0) {
        t = 1.0 - (f32)fzgx_obj_lbl_8_bss_3CC / 15.0;
        x = 320.0f + (f32)(640.0f * t);
    } else if (fzgx_obj_lbl_8_bss_3CC > fzgx_obj_lbl_8_bss_3D0 - 15.0) {
        t = 1.0 - (f32)(fzgx_obj_lbl_8_bss_3D0 - fzgx_obj_lbl_8_bss_3CC) / 15.0;
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
    fn_1_496FC(x, 345.0f);
    fn_1_4954C(0.09f);
    fn_1_4955C(0.8333333f, 0.8333333f);
    fn_1_495A0(alpha);
    fn_1_4D0A0();
    fn_1_49738((u32)fn_1_5233C);
    fn_1_49748(5.0f);
    fn_1_4AE0C(((char **)lbl_8_data_96AC)[lbl_801A66B4]);
    fn_1_49738(0);
    {
        fn_8_9B44_Color arg;
        fn_8_9B44_Color color = {255, 255, 255, 0};
        color.a = 255.0f * alpha;
        arg = color;
        fn_1_4D0D4(&arg, 20.0f);
    }

    if (fzgx_obj_lbl_8_bss_3CC < fzgx_obj_lbl_8_bss_3D0 - 180) {
        /* alpha is reused as the curve scale from here on */
        alpha = (f32)fzgx_obj_lbl_8_bss_3CC / (f32)(fzgx_obj_lbl_8_bss_3D0 - 180);
        alpha = 2.0f * (1.0f - alpha);
        if (alpha > 1.0f) {
            alpha = 1.0f;
        }
        first = fn_1_9E14C(lbl_8_data_95B8.unk_0, (void *)lbl_8_data_95B8.unk_4, 0.0f);
        fn_1_9E14C(lbl_8_data_95B8.unk_8, (void *)lbl_8_data_95B8.unk_C, 0.0f);
        fn_1_9E14C(lbl_8_data_95B8.unk_10, (void *)lbl_8_data_95B8.unk_14, 0.0f);
        lbl_8_bss_2C0__fzgx_offset_C.unk_C = fn_1_9E14C(lbl_8_data_95B8.unk_0, (void *)lbl_8_data_95B8.unk_4, alpha);
        lbl_8_bss_2C0__fzgx_offset_C.unk_10 = fn_1_9E14C(lbl_8_data_95B8.unk_8, (void *)lbl_8_data_95B8.unk_C, alpha);
        lbl_8_bss_2C0__fzgx_offset_C.unk_14 = fn_1_9E14C(lbl_8_data_95B8.unk_10, (void *)lbl_8_data_95B8.unk_14, alpha);
        lbl_8_bss_2C0__fzgx_offset_C.unk_4 = fn_1_9E14C(lbl_8_data_95B8.unk_18, (void *)lbl_8_data_95B8.unk_1C, alpha);
        /* the product is held, so it stays fmul + fadd */
        blend = 0.85 * (lbl_8_bss_2C0__fzgx_offset_C.unk_C - first);
        lbl_8_bss_2C0__fzgx_offset_C.unk_C = first + blend;
    }

    lbl_8_bss_2C0__fzgx_offset_C0.unk_C = -160.0f;
    lbl_8_bss_2C0__fzgx_offset_C0.unk_10 = 90.0f;
    if (fzgx_obj_lbl_8_bss_3CC > fzgx_obj_lbl_8_bss_3D0 - 60) {
        f = (f32)(fzgx_obj_lbl_8_bss_3D0 - fzgx_obj_lbl_8_bss_3CC) / 60.0f;
        lbl_8_bss_2C0__fzgx_offset_C0.unk_4 = f;
        lbl_8_bss_2C0__fzgx_offset_C0.unk_4 = f * f;
    } else if (fzgx_obj_lbl_8_bss_3CC < 60) {
        f = (f32)fzgx_obj_lbl_8_bss_3CC / 60.0f;
        lbl_8_bss_2C0__fzgx_offset_C0.unk_4 = f;
        lbl_8_bss_2C0__fzgx_offset_C0.unk_4 = f * f;
    } else {
        lbl_8_bss_2C0__fzgx_offset_C0.unk_4 = 1.0f;
    }
    lbl_8_bss_2C0__fzgx_offset_FC[0] = 0;
    if (fzgx_obj_lbl_8_bss_3CC < fzgx_obj_lbl_8_bss_3D0 - 90 && fzgx_obj_lbl_8_bss_3CC > fzgx_obj_lbl_8_bss_3D0 - 180 &&
        fzgx_obj_lbl_8_bss_3CC % 30 > 10) {
        lbl_8_bss_2C0__fzgx_offset_FC[0] = 1;
    }
}
/* fzgx:end fn_8_9B44 */

/* fzgx:begin fn_8_9FB4 pool */
#include "rel/title/operation.h"

typedef struct {
    u8 r, g, b, a;
} Color_8_9FB4;

typedef struct {
    s32 type;
    f32 time;
    f32 value;
    f32 tanIn;
    f32 tanOut;
} CurveKey_8_9FB4;

typedef struct {
    u32 count;
    CurveKey_8_9FB4 *keys;
} Curve_8_9FB4;

typedef struct {
    s16 unk_0;
    u8 pad_2[0x2];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad_18[0x24];
} Sprite_8_9FB4;

typedef struct {
    u8 pad_0[0x24];
    Sprite_8_9FB4 sprite[4];
    u32 unk_114;
    u32 unk_118;
    u32 unk_11C;
    u32 unk_120;
    s32 unk_124;
    s32 unk_128;
} State_8_9FB4;

extern s32 lbl_801A66B4;
extern s32 lbl_801A66A0;
extern void fn_1_5233C(void);
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
extern void fn_1_4D0D4(Color_8_9FB4 *, f32);
extern f32 fn_1_9E14C(u32, CurveKey_8_9FB4 *, f32);

/* Pool primers: fix the TU literal pool's first-use order (dropped at integration). */

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u16 fzgx_obj_lbl_8_bss_2A8;
u16 lbl_8_bss_2A8_gap_2AA;
u32 fzgx_obj_lbl_8_bss_2AC;
u32 fzgx_obj_lbl_8_bss_2B0;
u32 lbl_8_bss_2B4;
u32 lbl_8_bss_2B8;
u32 lbl_8_bss_2BC;
u32 fzgx_obj_lbl_8_bss_2C0[3];
Sprite_8_9FB4 lbl_8_bss_2C0_C[2];
Sprite_8_9FB4 sprite_8_344;
Sprite_8_9FB4 sprite_8_380;
u32 lbl_8_bss_2C0_fill_3BC[4];
s32 fzgx_obj_lbl_8_bss_3CC;
s32 fzgx_obj_lbl_8_bss_3D0;
u32 lbl_8_bss_3D0_fill_3D4[91];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_8_bss_2A8;
    s = *(u8 *)&lbl_8_bss_2A8_gap_2AA;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_2AC;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_2B0;
    s = *(u8 *)&lbl_8_bss_2B4;
    s = *(u8 *)&lbl_8_bss_2B8;
    s = *(u8 *)&lbl_8_bss_2BC;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_2C0;
    s = *(u8 *)&lbl_8_bss_2C0_C;
    s = *(u8 *)&sprite_8_344;
    s = *(u8 *)&sprite_8_380;
    s = *(u8 *)&lbl_8_bss_2C0_fill_3BC;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_3CC;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_3D0;
    s = *(u8 *)&lbl_8_bss_3D0_fill_3D4;
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
    s = 0.1f;
    s = 20.0f;
    s = 0.8333333f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table2[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    s = 0.0f;
    s = 1.0f;
    s = 0.5f;
    s = 0.09f;
    s = 5.0f;
    s = 255.0f;
}
static const u32 fzgx_pool_table4[49] = {  /* fzgx-allow: A1 retail pool bytes */
    0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0x3E99999A, 0xFFFFFF00,
    0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0, 0, 0x3F800000, 0,
    0, 0x3C23D70A, 0, 0, 0x3F800000, 0, 0, 0x3C23D70A,
    0x42700000, 0x3F333333, 0x3C23D70A, 0x43700000, 0x42340000, 0x3A83126F, 0x42C80000, 0xC3480000,
    0x42F00000, 0x43480000, 0xC2F00000, 0xBC23D70A, 0x41200000, 0xC6200000, 0x3FE66666, 0xBFE66666,
    0xC1A00000, 0xC5800000, 0xC5000000, 0x3F8CCCCD, 0xBF028F5C, 0x45800000, 0xBF8CCCCD, 0x3F4CCCCD,
    0xFFFFFF00
};
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 345.0f;
    s = 2.0f;
    d = 0.85;
    s = -160.0f;
    s = 90.0f;
}
#pragma section code_type ".text"

void fn_8_9FB4(void) {
    Curve_8_9FB4 *curves;
    s32 x;
    s32 end;
    s32 cnt;
    f32 t;
    f32 sq;
    f32 base;
    f64 d;

    
    cnt = fzgx_obj_lbl_8_bss_3CC;
    if (cnt < 15.0) {
        t = 1.0 - (f32)cnt / 15.0;
        x = 320.0f + (f32)(640.0f * t);
    } else {
        end = fzgx_obj_lbl_8_bss_3D0;
        if (cnt > end - 15.0) {
            t = 1.0 - (f32)(end - cnt) / 15.0;
            x = 320.0f - (f32)(640.0f * t);
        } else {
            t = 0.0f;
            x = 320;
        }
    }
    sq = (1.0f - t) * (1.0f - t);
    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_49590(0.5f);
    fn_1_495C8(9);
    fn_1_496FC(x, 345.0f);
    fn_1_4954C(0.09f);
    fn_1_4955C(0.8333333f, 0.8333333f);
    fn_1_495A0(sq);
    fn_1_4D0A0();
    fn_1_49738((u32)fn_1_5233C);
    fn_1_49748(5.0f);
    fn_1_4AE0C(((char **)lbl_8_data_9778)[lbl_801A66B4]);
    fn_1_49738(0);
    {
        Color_8_9FB4 arg;
        Color_8_9FB4 color = { 0xFF, 0xFF, 0xFF, 0x00 };

        color.a = 255.0f * sq;
        arg = color;
        fn_1_4D0D4(&arg, 20.0f);
    }

    {
    s32 duration;
    if (fzgx_obj_lbl_8_bss_3CC > fzgx_obj_lbl_8_bss_3D0 - 30) {
        lbl_8_bss_2C0_C[0].unk_C = 112.0f - 272.0f * (f32)(fzgx_obj_lbl_8_bss_3D0 - fzgx_obj_lbl_8_bss_3CC) / 30.0f;
        lbl_8_bss_2C0_C[0].unk_10 = 90.0f;
    } else {
        lbl_8_bss_2C0_C[0].unk_C = -160.0f;
        lbl_8_bss_2C0_C[0].unk_10 = 90.0f;
    }
    lbl_8_bss_2C0_C[0].unk_0 = 0;
    sprite_8_344.unk_0 = lbl_801A66A0 << 9;
    duration = fzgx_obj_lbl_8_bss_3D0 - 90;
    if (fzgx_obj_lbl_8_bss_3CC < duration) {
        t = (f32)fzgx_obj_lbl_8_bss_3CC / (f32)duration;
        t = 2.0f * (1.0f - t);
        if (t > 1.0f) {
            t = 1.0f;
        }
        base = fn_1_9E14C(lbl_8_data_9270.unk_0, (CurveKey_8_9FB4 *)lbl_8_data_9270.unk_4, 0.0f);
        fn_1_9E14C(lbl_8_data_9270.unk_8, (CurveKey_8_9FB4 *)lbl_8_data_9270.unk_C, 0.0f);
        fn_1_9E14C(lbl_8_data_9270.unk_10, (CurveKey_8_9FB4 *)lbl_8_data_9270.unk_14, 0.0f);
        sprite_8_344.unk_C = fn_1_9E14C(lbl_8_data_9270.unk_0, (CurveKey_8_9FB4 *)lbl_8_data_9270.unk_4, t);
        sprite_8_344.unk_10 = fn_1_9E14C(lbl_8_data_9270.unk_8, (CurveKey_8_9FB4 *)lbl_8_data_9270.unk_C, t);
        sprite_8_344.unk_14 = fn_1_9E14C(lbl_8_data_9270.unk_10, (CurveKey_8_9FB4 *)lbl_8_data_9270.unk_14, t);
        sprite_8_344.unk_10 -= 70.0f;
        sprite_8_344.unk_4 = fn_1_9E14C(lbl_8_data_9270.unk_18, (CurveKey_8_9FB4 *)lbl_8_data_9270.unk_1C, t);
        d = 0.85 * (sprite_8_344.unk_C - base);
        sprite_8_344.unk_C = base + d;
    }
    }
}
/* fzgx:end fn_8_9FB4 */

/* fzgx:begin fn_8_A3A4 */
extern u8 fn_8_6C90__fzgx_offset_0[];
extern u8 fn_8_6F1C__fzgx_offset_0[];
extern u8 fn_8_71A8__fzgx_offset_0[];
extern u8 fn_8_7484__fzgx_offset_0[];
extern u8 fn_8_7734__fzgx_offset_0[];
extern u8 fn_8_79C0__fzgx_offset_0[];
extern u8 fn_8_7C4C__fzgx_offset_0[];
extern u8 fn_8_7EFC__fzgx_offset_0[];
extern u8 fn_8_81AC__fzgx_offset_0[];
extern u8 fn_8_8440__fzgx_offset_0[];
extern u8 fn_8_86FC__fzgx_offset_0[];
extern u8 fn_8_89B8__fzgx_offset_0[];
extern u8 fn_8_8C44__fzgx_offset_0[];
extern u8 fn_8_8C48__fzgx_offset_0[];
extern u8 fn_8_8C80__fzgx_offset_0[];
extern u8 fn_8_8E00__fzgx_offset_0[];
extern u8 fn_8_988C__fzgx_offset_0[];
extern u8 fn_8_9B04__fzgx_offset_0[];
extern u8 fn_8_9B40__fzgx_offset_0[];
extern u8 fn_8_9B44__fzgx_offset_0[];
extern u8 fn_8_9FB4__fzgx_offset_0[];
extern u8 fn_8_A3A4__fzgx_offset_0[];
extern u8 fn_8_A954__fzgx_offset_0[];
extern u8 fn_8_ABBC__fzgx_offset_0[];
extern u8 fn_8_ADF4__fzgx_offset_0[];
extern u8 fn_8_B138__fzgx_offset_0[];
extern u8 fn_8_B380__fzgx_offset_0[];
extern u8 fn_8_B840__fzgx_offset_0[];
extern u8 fn_8_BAEC__fzgx_offset_0[];
extern u8 fn_8_BC04__fzgx_offset_0[];
extern u8 lbl_8_data_7E50__fzgx_offset_0[];
extern u8 lbl_8_data_7E54__fzgx_offset_0[];
extern u8 lbl_8_data_7E60__fzgx_offset_0[];
extern u8 lbl_8_data_7E6C__fzgx_offset_0[];
extern u8 lbl_8_data_7E78__fzgx_offset_0[];
extern u8 lbl_8_data_7E84__fzgx_offset_0[];
extern u8 lbl_8_data_7E8C__fzgx_offset_0[];
extern u8 lbl_8_data_7E94__fzgx_offset_0[];
extern u8 lbl_8_data_7E9C__fzgx_offset_0[];
extern u8 lbl_8_data_7EA4__fzgx_offset_0[];
extern u8 lbl_8_data_7EB0__fzgx_offset_0[];
extern u8 lbl_8_data_7EC0__fzgx_offset_0[];
extern u8 lbl_8_data_7ED0__fzgx_offset_0[];
extern u8 lbl_8_data_7ED8__fzgx_offset_0[];
extern u8 lbl_8_data_7EE0__fzgx_offset_0[];
extern u8 lbl_8_data_7EEC__fzgx_offset_0[];
extern u8 lbl_8_data_7EF8__fzgx_offset_0[];
extern u8 lbl_8_data_7F08__fzgx_offset_0[];
extern u8 lbl_8_data_7F10__fzgx_offset_0[];
extern u8 lbl_8_data_7F1C__fzgx_offset_0[];
extern u8 lbl_8_data_7F28__fzgx_offset_0[];
extern u8 lbl_8_data_7F38__fzgx_offset_0[];
extern u8 lbl_8_data_7F40__fzgx_offset_0[];
extern u8 lbl_8_data_7F4C__fzgx_offset_0[];
extern u8 lbl_8_data_7F58__fzgx_offset_0[];
extern u8 lbl_8_data_7F68__fzgx_offset_0[];
extern u8 lbl_8_data_7F70__fzgx_offset_0[];
extern u8 lbl_8_data_7F7C__fzgx_offset_0[];
extern u8 lbl_8_data_7F84__fzgx_offset_0[];
extern u8 lbl_8_data_7F90__fzgx_offset_0[];
extern u8 lbl_8_data_7FA0__fzgx_offset_0[];
extern u8 lbl_8_data_7FAC__fzgx_offset_0[];
extern u8 lbl_8_data_7FB8__fzgx_offset_0[];
extern u8 lbl_8_data_7FC0__fzgx_offset_0[];
extern u8 lbl_8_data_7FD4__fzgx_offset_0[];
extern u8 lbl_8_data_7FE4__fzgx_offset_0[];
extern u8 lbl_8_data_7FF4__fzgx_offset_0[];
extern u8 lbl_8_data_8000__fzgx_offset_0[];
extern u8 lbl_8_data_800C__fzgx_offset_0[];
extern u8 lbl_8_data_801C__fzgx_offset_0[];
extern u8 lbl_8_data_8024__fzgx_offset_0[];
extern u8 lbl_8_data_8030__fzgx_offset_0[];
extern u8 lbl_8_data_8038__fzgx_offset_0[];
extern u8 lbl_8_data_8040__fzgx_offset_0[];
extern u8 lbl_8_data_8048__fzgx_offset_0[];
extern u8 lbl_8_data_8104__fzgx_offset_0[];
extern u8 lbl_8_data_8110__fzgx_offset_0[];
extern u8 lbl_8_data_8118__fzgx_offset_0[];
extern u8 lbl_8_data_8124__fzgx_offset_0[];
extern u8 lbl_8_data_812C__fzgx_offset_0[];
extern u8 lbl_8_data_8138__fzgx_offset_0[];
extern u8 lbl_8_data_8140__fzgx_offset_0[];
extern u8 lbl_8_data_8148__fzgx_offset_0[];
extern u8 lbl_8_data_816C__fzgx_offset_0[];
extern u8 lbl_8_data_8174__fzgx_offset_0[];
extern u8 lbl_8_data_819C__fzgx_offset_0[];
extern u8 lbl_8_data_81AC__fzgx_offset_0[];
extern u8 lbl_8_data_81B0__fzgx_offset_0[];
extern u8 lbl_8_data_81D4__fzgx_offset_0[];
extern u8 lbl_8_data_81E0__fzgx_offset_0[];
extern u8 lbl_8_data_8208__fzgx_offset_0[];
extern u8 lbl_8_data_8214__fzgx_offset_0[];
extern u8 lbl_8_data_823C__fzgx_offset_0[];
extern u8 lbl_8_data_8248__fzgx_offset_0[];
extern u8 lbl_8_data_8270__fzgx_offset_0[];
extern u8 lbl_8_data_827C__fzgx_offset_0[];
extern u8 lbl_8_data_82A4__fzgx_offset_0[];
extern u8 lbl_8_data_82C0__fzgx_offset_0[];
extern u8 lbl_8_data_82FC__fzgx_offset_0[];
extern u8 lbl_8_data_8328__fzgx_offset_0[];
extern u8 lbl_8_data_835C__fzgx_offset_0[];
extern u8 lbl_8_data_8368__fzgx_offset_0[];
extern u8 lbl_8_data_8394__fzgx_offset_0[];
extern u8 lbl_8_data_83B8__fzgx_offset_0[];
extern u8 lbl_8_data_83FC__fzgx_offset_0[];
extern u8 lbl_8_data_8438__fzgx_offset_0[];
extern u8 lbl_8_data_8448__fzgx_offset_0[];
extern u8 lbl_8_data_8470__fzgx_offset_0[];
extern u8 lbl_8_data_8490__fzgx_offset_0[];
extern u8 lbl_8_data_84D0__fzgx_offset_0[];
extern u8 lbl_8_data_84DC__fzgx_offset_0[];
extern u8 lbl_8_data_8504__fzgx_offset_0[];
extern u8 lbl_8_data_8528__fzgx_offset_0[];
extern u8 lbl_8_data_856C__fzgx_offset_0[];
extern u8 lbl_8_data_8578__fzgx_offset_0[];
extern u8 lbl_8_data_85A0__fzgx_offset_0[];
extern u8 lbl_8_data_85D8__fzgx_offset_0[];
extern u8 lbl_8_data_8618__fzgx_offset_0[];
extern u8 lbl_8_data_8644__fzgx_offset_0[];
extern u8 lbl_8_data_868C__fzgx_offset_0[];
extern u8 lbl_8_data_8698__fzgx_offset_0[];
extern u8 lbl_8_data_86BC__fzgx_offset_0[];
extern u8 lbl_8_data_86E8__fzgx_offset_0[];
extern u8 lbl_8_data_871C__fzgx_offset_0[];
extern u8 lbl_8_data_874C__fzgx_offset_0[];
extern u8 lbl_8_data_8788__fzgx_offset_0[];
extern u8 lbl_8_data_87B4__fzgx_offset_0[];
extern u8 lbl_8_data_87F4__fzgx_offset_0[];
extern u8 lbl_8_data_881C__fzgx_offset_0[];
extern u8 lbl_8_data_8858__fzgx_offset_0[];
extern u8 lbl_8_data_8868__fzgx_offset_0[];
extern u8 lbl_8_data_8894__fzgx_offset_0[];
extern u8 lbl_8_data_88AC__fzgx_offset_0[];
extern u8 lbl_8_data_88E8__fzgx_offset_0[];
extern u8 lbl_8_data_8914__fzgx_offset_0[];
extern u8 lbl_8_data_891C__fzgx_offset_0[];
extern u8 lbl_8_data_893C__fzgx_offset_0[];
extern u8 lbl_8_data_8958__fzgx_offset_0[];
extern u8 lbl_8_data_898C__fzgx_offset_0[];
extern u8 lbl_8_data_89B0__fzgx_offset_0[];
extern u8 lbl_8_data_89E4__fzgx_offset_0[];
extern u8 lbl_8_data_89EC__fzgx_offset_0[];
extern u8 lbl_8_data_8A10__fzgx_offset_0[];
extern u8 lbl_8_data_8A38__fzgx_offset_0[];
extern u8 lbl_8_data_8A70__fzgx_offset_0[];
extern u8 lbl_8_data_8A98__fzgx_offset_0[];
extern u8 lbl_8_data_8BF8__fzgx_offset_0[];
extern u8 lbl_8_data_8C04__fzgx_offset_0[];
extern u8 lbl_8_data_8C10__fzgx_offset_0[];
extern u8 lbl_8_data_8C1C__fzgx_offset_0[];
extern u8 lbl_8_data_8C28__fzgx_offset_0[];
extern u8 lbl_8_data_8C34__fzgx_offset_0[];
extern u8 lbl_8_data_8C40__fzgx_offset_0[];
extern u8 lbl_8_data_8C48__fzgx_offset_0[];
extern u8 lbl_8_data_8C5C__fzgx_offset_0[];
extern u8 lbl_8_data_8CF8__fzgx_offset_0[];
extern u8 lbl_8_data_8E4C__fzgx_offset_0[];
extern u8 lbl_8_data_8F8C__fzgx_offset_0[];
extern u8 lbl_8_data_8FB4__fzgx_offset_0[];
extern u8 lbl_8_data_8FF0__fzgx_offset_0[];
extern u8 lbl_8_data_9054__fzgx_offset_0[];
extern u8 lbl_8_data_911C__fzgx_offset_0[];
extern u8 lbl_8_data_91D0__fzgx_offset_0[];
extern u8 lbl_8_data_91F8__fzgx_offset_0[];
extern u8 lbl_8_data_9234__fzgx_offset_0[];
extern u8 lbl_8_data_9298__fzgx_offset_0[];
extern u8 lbl_8_data_93C4__fzgx_offset_0[];
extern u8 lbl_8_data_9518__fzgx_offset_0[];
extern u8 lbl_8_data_9540__fzgx_offset_0[];
extern u8 lbl_8_data_957C__fzgx_offset_0[];
extern u8 lbl_8_data_9668__fzgx_offset_0[];
extern u8 lbl_8_data_9690__fzgx_offset_0[];
extern u8 lbl_8_data_96C4__fzgx_offset_0[];
extern u8 lbl_8_data_970C__fzgx_offset_0[];
extern u8 lbl_8_data_9790__fzgx_offset_0[];
extern u8 lbl_8_data_97DC__fzgx_offset_0[];
extern u8 lbl_8_data_9844__fzgx_offset_0[];
extern u8 lbl_8_data_989C__fzgx_offset_0[];
extern u8 lbl_8_data_9924__fzgx_offset_0[];
extern u8 lbl_8_data_9970__fzgx_offset_0[];
extern u8 lbl_8_data_99D4__fzgx_offset_0[];
extern u8 lbl_8_data_9A30__fzgx_offset_0[];
extern u8 lbl_8_data_9AD0__fzgx_offset_0[];
extern u8 lbl_8_data_9B24__fzgx_offset_0[];
extern u8 lbl_8_data_9BA4__fzgx_offset_0[];
extern u8 lbl_8_data_9C04__fzgx_offset_0[];
extern u8 lbl_8_data_9CB8__fzgx_offset_0[];
extern u8 lbl_8_data_9D44__fzgx_offset_0[];
extern u8 lbl_8_data_9E1C__fzgx_offset_0[];
extern u8 lbl_8_data_9F44__fzgx_offset_0[];
static u32 fzgx_pool_native_lbl_8_data_7E50_gap_0[1655] = {0x4E4F4E00, 0x4D415354, 0x45522052, 0x45435600, 0x4D415354, 0x45522053, 0x454E4400, 0x534C4156, 0x45205345, 0x4E440000, 0x534C4156, 0x45205245, 0x43560000, 0x494E4954, 0x00000000, 0x54455354, 0x00000000, 0x54455354, 0x454E4400, 0x53455455, 0x50000000, 0x53455455, 0x505F444F, 0x4E450000, 0x53455455, 0x505F434F, 0x554E5445, 0x52000000, 0x53455455, 0x505F434E, 0x545F444F, 0x4E450000, 0x554E4C49, 0x4E4B0000, 0x434F494E, 0x00000000, 0x454E5452, 0x595F5741, 0x49540000, 0x4348414C, 0x4C454E47, 0x45520000, 0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000, 0x454E5452, 0x59000000, 0x454E5452, 0x595F4F4B, 0x00000000, 0x53494E47, 0x4C454348, 0x45434B00, 0x53494E47, 0x4C454348, 0x45434B5F, 0x4F4B0000, 0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F, 0x4B000000, 0x434F5552, 0x53455F44, 0x41544100, 0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000, 0x4D414348, 0x494E4500, 0x4D414348, 0x494E455F, 0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46, 0x49475F4F, 0x4B000000, 0x434F554E, 0x54455241, 0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954, 0x00000000, 0x4C494E4B, 0x57414954, 0x4F4B0000, 0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49, 0x56455259, 0x53544152, 0x54000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x00000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x4F4B0000, 0x4C494E4B, 0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649, 0x45570000, 0x434F5552, 0x53455649, 0x45575F4F, 0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B, 0x5354414E, 0x44425900, 0x4C494E4B, 0x4F4B0000, 0x4C494E4B, 0x00000000, 0x50415553, 0x45000000, 0x4552524F, 0x52000000, (u32)lbl_8_data_7E50__fzgx_offset_0, (u32)lbl_8_data_7E54__fzgx_offset_0, (u32)lbl_8_data_7E60__fzgx_offset_0, (u32)lbl_8_data_7E6C__fzgx_offset_0, (u32)lbl_8_data_7E78__fzgx_offset_0, (u32)lbl_8_data_7E84__fzgx_offset_0, (u32)lbl_8_data_7E8C__fzgx_offset_0, (u32)lbl_8_data_7E94__fzgx_offset_0, (u32)lbl_8_data_7E9C__fzgx_offset_0, (u32)lbl_8_data_7EA4__fzgx_offset_0, (u32)lbl_8_data_7EB0__fzgx_offset_0, (u32)lbl_8_data_7EC0__fzgx_offset_0, (u32)lbl_8_data_7ED0__fzgx_offset_0, (u32)lbl_8_data_7ED8__fzgx_offset_0, (u32)lbl_8_data_7EE0__fzgx_offset_0, (u32)lbl_8_data_7EEC__fzgx_offset_0, (u32)lbl_8_data_7EF8__fzgx_offset_0, (u32)lbl_8_data_7F08__fzgx_offset_0, (u32)lbl_8_data_7F10__fzgx_offset_0, (u32)lbl_8_data_7F1C__fzgx_offset_0, (u32)lbl_8_data_7F28__fzgx_offset_0, (u32)lbl_8_data_7F38__fzgx_offset_0, (u32)lbl_8_data_7F40__fzgx_offset_0, (u32)lbl_8_data_7F4C__fzgx_offset_0, (u32)lbl_8_data_7F58__fzgx_offset_0, (u32)lbl_8_data_7F68__fzgx_offset_0, (u32)lbl_8_data_7F70__fzgx_offset_0, (u32)lbl_8_data_7F7C__fzgx_offset_0, (u32)lbl_8_data_7F84__fzgx_offset_0, (u32)lbl_8_data_7F90__fzgx_offset_0, (u32)lbl_8_data_7FA0__fzgx_offset_0, (u32)lbl_8_data_7FAC__fzgx_offset_0, (u32)lbl_8_data_7FB8__fzgx_offset_0, (u32)lbl_8_data_7FC0__fzgx_offset_0, (u32)lbl_8_data_7FD4__fzgx_offset_0, (u32)lbl_8_data_7FE4__fzgx_offset_0, (u32)lbl_8_data_7FF4__fzgx_offset_0, (u32)lbl_8_data_8000__fzgx_offset_0, (u32)lbl_8_data_800C__fzgx_offset_0, (u32)lbl_8_data_801C__fzgx_offset_0, (u32)lbl_8_data_8024__fzgx_offset_0, (u32)lbl_8_data_8030__fzgx_offset_0, (u32)lbl_8_data_8038__fzgx_offset_0, (u32)lbl_8_data_8040__fzgx_offset_0, (u32)lbl_8_data_8048__fzgx_offset_0, 0x4F564552, 0x54414B45, 0x00000000, 0x4A554D50, 0x00000000, 0x454E454D, 0x59484954, 0x00000000, 0x57414C4C, 0x48495400, 0x53494445, 0x42595349, 0x44450000, 0x53544152, 0x54000000, 0x474F414C, 0x00000000, 0x4C415000, (u32)lbl_8_data_8104__fzgx_offset_0, (u32)lbl_8_data_8110__fzgx_offset_0, (u32)lbl_8_data_8118__fzgx_offset_0, (u32)lbl_8_data_8124__fzgx_offset_0, (u32)lbl_8_data_812C__fzgx_offset_0, (u32)lbl_8_data_8138__fzgx_offset_0, (u32)lbl_8_data_8140__fzgx_offset_0, (u32)lbl_8_data_8148__fzgx_offset_0, 0x6D656E75, 0x00000000, 0x77617463, 0x68000000, (u32)lbl_8_data_816C__fzgx_offset_0, (u32)fn_8_988C__fzgx_offset_0, (u32)fn_8_9B04__fzgx_offset_0, (u32)fn_8_9B40__fzgx_offset_0, (u32)lbl_8_data_8174__fzgx_offset_0, (u32)fn_8_8C48__fzgx_offset_0, (u32)fn_8_8E00__fzgx_offset_0, (u32)fn_8_8C80__fzgx_offset_0, 0x41434345, 0x4C455241, 0x544F520A, 0x00000000, 0x00000000, 0x8341834E, 0x835A838B, 0x0A000000, (u32)lbl_8_data_819C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81B0__fzgx_offset_0, 0x73706565, 0x64207570, 0x2E0A0000, 0x89C191AC, 0x82B582DC, 0x82B78142, 0x0A000000, (u32)lbl_8_data_81D4__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81E0__fzgx_offset_0, 0x41495220, 0x4252414B, 0x450A0000, 0x83478341, 0x8375838C, 0x815B834C, 0x0A000000, (u32)lbl_8_data_8208__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8214__fzgx_offset_0, 0x736C6F77, 0x20646F77, 0x6E2E0A00, 0x8CB891AC, 0x82B582DC, 0x82B78142, 0x0A000000, (u32)lbl_8_data_823C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8248__fzgx_offset_0, 0x53544545, 0x52494E47, 0x0A000000, 0x83588365, 0x8341838A, 0x8393834F, 0x0A000000, (u32)lbl_8_data_8270__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_827C__fzgx_offset_0, 0x436F6E74, 0x726F6C20, 0x796F7572, 0x206D6163, 0x68696E65, 0x20776974, 0x680A0000, 0x83588365, 0x8341838A, 0x8393834F, 0x82C68341, 0x834E835A, 0x838B82C5, 0x837D8356, 0x839382F0, 0x0A000000, (u32)lbl_8_data_82A4__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_82C0__fzgx_offset_0, 0x74686520, 0x73746565, 0x72696E67, 0x20776865, 0x656C2061, 0x6E642074, 0x68652061, 0x6363656C, 0x65726174, 0x6F722E0A, 0x00000000, 0x83528393, 0x8367838D, 0x815B838B, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420A00, (u32)lbl_8_data_82FC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8328__fzgx_offset_0, 0x44415348, 0x20504C41, 0x54450A00, 0x835F8362, 0x83568385, 0x8376838C, 0x815B8367, 0x0A000000, (u32)lbl_8_data_835C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8368__fzgx_offset_0, 0x53706565, 0x64207769, 0x6C6C2074, 0x656D706F, 0x72617269, 0x6C792069, 0x6E637265, 0x6173650A, 0x00000000, 0x92CA89DF, 0x82B782E9, 0x82C68358, 0x8373815B, 0x836882AA, 0x88EA8E9E, 0x934982C9, 0x83418362, 0x837682B5, 0x82DC82B7, 0x0A000000, (u32)lbl_8_data_8394__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_83B8__fzgx_offset_0, 0x7768656E, 0x20706173, 0x73696E67, 0x206F7665, 0x72206120, 0x64617368, 0x20706C61, 0x74652E0A, 0x00000000, (u32)lbl_8_data_83FC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, 0x4E4F524D, 0x414C2054, 0x55524E0A, 0x00000000, 0x836D815B, 0x837D838B, 0x835E815B, 0x83930A00, (u32)lbl_8_data_8438__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8448__fzgx_offset_0, 0x436F726E, 0x6572696E, 0x67207769, 0x74682074, 0x68652073, 0x74656572, 0x696E672E, 0x0A000000, 0x83588365, 0x8341838A, 0x8393834F, 0x82BE82AF, 0x82CC8352, 0x815B8369, 0x838A8393, 0x834F82C5, 0x82B78142, 0x0A000000, (u32)lbl_8_data_8470__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8490__fzgx_offset_0, 0x534C4944, 0x45205455, 0x524E0A00, 0x83588389, 0x83438368, 0x835E815B, 0x83930A00, (u32)lbl_8_data_84D0__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_84DC__fzgx_offset_0, 0x50756C6C, 0x20746865, 0x20706164, 0x646C6520, 0x7768696C, 0x6520636F, 0x726E6572, 0x696E672E, 0x0A000000, 0x8352815B, 0x8369838A, 0x8393834F, 0x928682C9, 0x83708368, 0x838B838C, 0x836F815B, 0x82F088F8, 0x82AB82DC, 0x82B78142, 0x0A000000, (u32)lbl_8_data_8504__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8528__fzgx_offset_0, 0x44524946, 0x54205455, 0x524E0A00, 0x8368838A, 0x83748367, 0x835E815B, 0x83930A00, (u32)lbl_8_data_856C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8578__fzgx_offset_0, 0x4272616B, 0x65206265, 0x666F7265, 0x20796F75, 0x20656E74, 0x65722074, 0x68652063, 0x75727665, 0x20776974, 0x68207468, 0x65206163, 0x63656C65, 0x7261746F, 0x720A0000, 0x8352815B, 0x8369815B, 0x82CC8EE8, 0x914F82C5, 0x8341834E, 0x835A838B, 0x82F093A5, 0x82F182BE, 0x82DC82DC, 0x0A000000, (u32)lbl_8_data_85A0__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_85D8__fzgx_offset_0, 0x73746570, 0x70656420, 0x6F6E2C20, 0x7468656E, 0x20747572, 0x6E207468, 0x65207374, 0x65657269, 0x6E672077, 0x6865656C, 0x2E0A0000, 0x8375838C, 0x815B834C, 0x82F08C79, 0x82AD93A5, 0x82DD82C8, 0x82AA82E7, 0x83588365, 0x8341838A, 0x8393834F, 0x82F090D8, 0x82E882DC, 0x82B70A00, (u32)lbl_8_data_8618__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8644__fzgx_offset_0, 0x424F4F53, 0x5445520A, 0x00000000, 0x8375815B, 0x83588367, 0x0A000000, (u32)lbl_8_data_868C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8698__fzgx_offset_0, 0x54686520, 0x73706565, 0x64206F66, 0x20746865, 0x206D6163, 0x68696E65, 0x2077696C, 0x6C20696E, 0x7374616E, 0x746C790A, 0x00000000, 0x328EFC96, 0xDA82A982, 0xE78E6797, 0x7089C294, 0x5C82C582, 0xB781420A, 0x00000000, (u32)lbl_8_data_86BC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_86E8__fzgx_offset_0, 0x696E6372, 0x65617365, 0x20627920, 0x70726573, 0x73696E67, 0x20746865, 0x20626F6F, 0x73742062, 0x7574746F, 0x6E206F6E, 0x63652E0A, 0x00000000, 0x8F758AD4, 0x934982C9, 0x83588373, 0x815B8368, 0x82AA8341, 0x83628376, 0x82B582DC, 0x82B78142, 0x0A000000, (u32)lbl_8_data_871C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_874C__fzgx_offset_0, 0x55736520, 0x74686520, 0x626F6F73, 0x74657220, 0x6173206D, 0x616E7920, 0x74696D65, 0x73206173, 0x20796F75, 0x2077616E, 0x743B0A00, 0x8375815B, 0x8358835E, 0x815B82C9, 0x89F19094, 0x90A78CC0, 0x82CD82A0, 0x82E882DC, 0x82B982F1, 0x82AA8141, 0x0A000000, (u32)lbl_8_data_8788__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_87B4__fzgx_offset_0, 0x686F7765, 0x7665722C, 0x20757361, 0x67652064, 0x65706C65, 0x74657320, 0x74686520, 0x656E6572, 0x67792E0A, 0x00000000, 0x8E679770, 0x82B782E9, 0x82C68347, 0x836C838B, 0x834D815B, 0x82F08FC1, 0x94EF82B5, 0x82DC82B7, 0x81420A00, (u32)lbl_8_data_87F4__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_881C__fzgx_offset_0, 0x454E4552, 0x4759204D, 0x45544552, 0x0A000000, 0x83478369, 0x8357815B, 0x8381815B, 0x835E815B, 0x0A000000, (u32)lbl_8_data_8858__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8868__fzgx_offset_0, 0x4E6F2065, 0x6E657267, 0x792C206E, 0x6F20626F, 0x6F73742E, 0x0A000000, 0x8347836C, 0x838B834D, 0x815B82AA, 0x3082C982, 0xC882E982, 0xC6837581, 0x5B835883, 0x5E815B82, 0xCD0A0000, (u32)lbl_8_data_8894__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_88AC__fzgx_offset_0, 0x8E679770, 0x82C582AB, 0x82DC82B9, 0x82F18142, 0x0A000000, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_88E8__fzgx_offset_0, 0x5049540A, 0x00000000, 0x83738362, 0x83670A00, (u32)lbl_8_data_8914__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_891C__fzgx_offset_0, 0x456E6572, 0x67792063, 0x616E2062, 0x65207265, 0x706C656E, 0x69736865, 0x640A0000, 0x83738362, 0x83678347, 0x838A8341, 0x82F09196, 0x8D7382B7, 0x82E982C6, 0x0A000000, (u32)lbl_8_data_893C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8958__fzgx_offset_0, 0x62792074, 0x72617665, 0x6C696E67, 0x20746872, 0x6F756768, 0x20746865, 0x20706974, 0x20617265, 0x612E0A00, 0x8347836C, 0x838B834D, 0x815B82AA, 0x89F1959C, 0x82B582DC, 0x82B78142, 0x0A000000, (u32)lbl_8_data_898C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_89B0__fzgx_offset_0, 0x4A554D50, 0x0A000000, 0x83578383, 0x83938376, 0x0A000000, (u32)lbl_8_data_89E4__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_89EC__fzgx_offset_0, 0x50756C6C, 0x206F7220, 0x70726573, 0x73207468, 0x65207374, 0x65657269, 0x6E672077, 0x6865656C, 0x20746F0A, 0x00000000, 0x83588365, 0x8341838A, 0x8393834F, 0x82CC8FE3, 0x89BA82C5, 0x94F28B97, 0x97A382E2, 0x0A000000, (u32)lbl_8_data_8A10__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8A38__fzgx_offset_0, 0x61646A75, 0x73742079, 0x6F757220, 0x6C656170, 0x20616E64, 0x206C616E, 0x64696E67, 0x20706F69, 0x6E742E0A, 0x00000000, 0x9285926E, 0x926E935F, 0x82F08352, 0x83938367, 0x838D815B, 0x838B82C5, 0x82AB82DC, 0x82B78142, 0x00000000, (u32)lbl_8_data_8A70__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_8A98__fzgx_offset_0, 0x6F706572, 0x6174696F, 0x6E2E6300, 0x76656869, 0x636C655F, 0x70617274, 0x732F0000, 0x2E2E0000, (u32)fn_8_6C90__fzgx_offset_0, (u32)fn_8_6F1C__fzgx_offset_0, (u32)fn_8_71A8__fzgx_offset_0, (u32)fn_8_7484__fzgx_offset_0, (u32)fn_8_7734__fzgx_offset_0, (u32)fn_8_79C0__fzgx_offset_0, (u32)fn_8_7C4C__fzgx_offset_0, (u32)fn_8_7EFC__fzgx_offset_0, (u32)fn_8_81AC__fzgx_offset_0, (u32)fn_8_8440__fzgx_offset_0, (u32)fn_8_86FC__fzgx_offset_0, (u32)fn_8_89B8__fzgx_offset_0, (u32)fn_8_8C44__fzgx_offset_0, 0x00000064, 0x00000078, 0x00000000, 0x00000000, 0x000000F0, 0x00000078, 0x00000000, 0x00000000, 0x000001D6, 0x000000B4, 0x00000000, 0x00000000, 0x000002DA, 0x0000012C, 0x00000001, 0x000000B4, 0x00000424, 0x0000012C, 0x00000001, 0x00000096, 0x0000058C, 0x0000012C, 0x00000001, 0x00000096, 0x000006F4, 0x0000012C, 0x00000001, 0x00000096, 0x00000898, 0x0000012C, 0x00000001, 0x000000B4, 0x000009C4, 0x00000096, 0x00000000, 0x00000000, 0x00000AAA, 0x000000F0, 0x00000001, 0x00000096, 0x00000B72, 0x000000F0, 0x00000001, 0x00000078, 0x00000C94, 0x000000F0, 0x00000001, 0x00000096, 0x00000D98, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x72756E5F, 0x73746F70, 0x00000000, 0x6C656674, 0x5F726967, 0x68740000, 0x64617368, 0x5F706C61, 0x74650000, 0x6E6F726D, 0x616C5F74, 0x75726E00, 0x736C6964, 0x655F7475, 0x726E0000, 0x64726966, 0x745F7475, 0x726E0000, 0x626F6F73, 0x74000000, 0x626F6F73, 0x745F656E, 0x65726779, 0x5F706974, 0x00000000, 0x6A756D70, 0x00000000, (u32)lbl_8_data_8BF8__fzgx_offset_0, 0x00000001, (u32)lbl_8_data_8C04__fzgx_offset_0, 0x00000186, (u32)lbl_8_data_8C10__fzgx_offset_0, 0x000002D0, (u32)lbl_8_data_8C1C__fzgx_offset_0, 0x0000041A, (u32)lbl_8_data_8C28__fzgx_offset_0, 0x00000582, (u32)lbl_8_data_8C34__fzgx_offset_0, 0x000006EA, (u32)lbl_8_data_8C40__fzgx_offset_0, 0x00000852, (u32)lbl_8_data_8C48__fzgx_offset_0, 0x00000A8C, (u32)lbl_8_data_8C5C__fzgx_offset_0, 0x00000C6C, 0x91808DEC, 0x90E096BE, 0x82F082CD, 0x82B682DF, 0x82DC82B7, 0x2889BC29, 0x00000000, 0x6F706572, 0x6174696F, 0x6E2F6F70, 0x5F726570, 0x5F25732E, 0x62696E00, 0x6F706572, 0x6174696F, 0x6E2F6F70, 0x5F667A63, 0x5F25732E, 0x62696E00, 0x00000002, 0x00000000, 0xC3310001, 0x00000000, 0x00000000, 0x00000002, 0x3E4CCCCD, 0xC3384C3C, 0xC2DF49F5, 0xC2DF49F5, 0x00000002, 0x3E888894, 0xC3422432, 0xC334D3C3, 0xC334D3C3, 0x00000002, 0x3EAAAA9F, 0xC34F0C4D, 0xC333E14D, 0xC333E14D, 0x00000002, 0x3EC44439, 0xC3554339, 0xC1F785A1, 0xC1F785A1, 0x00000002, 0x3ED55561, 0xC352BE9E, 0x4374BD7B, 0x4374BD7B, 0x00000002, 0x3EDDDDD3, 0xC34CEB1A, 0x44051B0D, 0x44051B0D, 0x00000002, 0x3EE66666, 0xC340FF47, 0x447DFB25, 0x447DFB25, 0x00000002, 0x3EEEEEFA, 0xC32B0DE2, 0x44C64FF1, 0x44C64FF1, 0x00000002, 0x3F000000, 0xC2D404D1, 0x44F82800, 0x44F82800, 0x00000002, 0x3F04444A, 0xC293E0B9, 0x44E13F8C, 0x44E13F8C, 0x00000002, 0x3F0CCCCD, 0xC1AB3B95, 0x44AD92D7, 0x44AD92D7, 0x00000002, 0x3F155550, 0x419E547E, 0x448A7A41, 0x448A7A41, 0x00000002, 0x3F1DDDE3, 0x4254149B, 0x44609AE5, 0x44609AE5, 0x00000002, 0x3F2EEEE9, 0x42CB9059, 0x4411FFD1, 0x4411FFD1, 0x00000002, 0x3F44444A, 0x4309FEE7, 0x4397BAD2, 0x4397BAD2, 0x00000002, 0x3F800000, 0x43200001, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x430A0000, 0x00000000, 0x00000000, 0x00000002, 0x3E3BBBA5, 0x42FA8AC1, 0xC358AE88, 0xC358AE88, 0x00000002, 0x3EB33333, 0x422B9999, 0xC45618EB, 0xC45618EB, 0x00000002, 0x3ECCCCCD, 0xC0D9A25B, 0xC48D8BB9, 0xC48D8BB9, 0x00000002, 0x3ED55561, 0xC1D364DA, 0xC497A3C4, 0xC497A3C4, 0x00000002, 0x3EDDDDD3, 0xC23CF40B, 0xC49C1166, 0xC49C1166, 0x00000002, 0x3EE66666, 0xC28815B1, 0xC48C32AD, 0xC48C32AD, 0x00000002, 0x3EEEEEFA, 0xC2A93FB7, 0xC42CC9D5, 0xC42CC9D5, 0x00000002, 0x3EF7776C, 0xC2B62961, 0xC2AFE1AB, 0xC2AFE1AB, 0x00000002, 0x3F04444A, 0xC29B69DD, 0x4428EC3B, 0x4428EC3B, 0x00000002, 0x3F088883, 0xC28210C4, 0x4446A0B3, 0x4446A0B3, 0x00000002, 0x3F111117, 0xC21523F3, 0x444E14EE, 0x444E14EE, 0x00000002, 0x3F19999A, 0xC12DEF9D, 0x443B1D1F, 0x443B1D1F, 0x00000002, 0x3F2AAAB0, 0x420086A2, 0x44069524, 0x44069524, 0x00000002, 0x3F400000, 0x42852D03, 0x4395617F, 0x4395617F, 0x00000002, 0x3F800000, 0x42B40000, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0x3F1489D2, 0x3F4B8876, 0x3F800000, 0x3F800000, 0x00000002, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x3F000000, 0x00000000, 0x00000000, 0x00000002, 0x3F000000, 0x3F000000, 0x00000000, 0x00000000, 0x00000002, 0x3F800000, 0x3F000000, 0x00000000, 0x00000000, 0x00000011, (u32)lbl_8_data_8CF8__fzgx_offset_0, 0x00000010, (u32)lbl_8_data_8E4C__fzgx_offset_0, 0x00000002, (u32)lbl_8_data_8F8C__fzgx_offset_0, 0x00000003, (u32)lbl_8_data_8FB4__fzgx_offset_0, 0x00000003, (u32)lbl_8_data_8FF0__fzgx_offset_0, 0x00000002, 0x00000000, 0xC3217ED1, 0x00000000, 0x00000000, 0x00000002, 0x3E4CCCCD, 0xC31B9B4C, 0x42A4DBAD, 0x42A4DBAD, 0x00000002, 0x3E888894, 0xC31390E0, 0x432D7FB5, 0x432D7FB5, 0x00000002, 0x3EA2222D, 0xC307B4AC, 0x439F1510, 0x439F1510, 0x00000002, 0x3EC44439, 0xC2D2F218, 0x4414AB3C, 0x4414AB3C, 0x00000002, 0x3EF7776C, 0xC1D543EC, 0x44706B8A, 0x44706B8A, 0x00000002, 0x3F04444A, 0x40C46408, 0x446BDB20, 0x446BDB20, 0x00000002, 0x3F155550, 0x42705F0D, 0x442C36F6, 0x442C36F6, 0x00000002, 0x3F37777D, 0x42FCA869, 0x43A57D79, 0x43A57D79, 0x00000002, 0x3F800000, 0x43202EB2, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x42B42FD8, 0x00000000, 0x00000000, 0x00000002, 0x3E5DDDF4, 0x42925369, 0xC34D21D5, 0xC34D21D5, 0x00000002, 0x3E911106, 0x4260C236, 0xC394E1A0, 0xC394E1A0, 0x00000002, 0x3ECCCCCD, 0x41BF0DB1, 0xC3283823, 0xC3283823, 0x00000002, 0x3EF7776C, 0x41B451A4, 0x4319CCB0, 0x4319CCB0, 0x00000002, 0x3F0CCCCD, 0x421BE2C8, 0x438CDA1A, 0x438CDA1A, 0x00000002, 0x3F19999A, 0x425295C8, 0x43808191, 0x43808191, 0x00000002, 0x3F333333, 0x429365D2, 0x432231F9, 0x432231F9, 0x00000002, 0x3F800000, 0x42B6D13E, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0x3F263B15, 0x3F5BC6DA, 0x3F800000, 0x3F800000, 0x00000002, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x3F000000, 0x00000000, 0x00000000, 0x00000002, 0x3F000000, 0x3F000000, 0x00000000, 0x00000000, 0x00000002, 0x3F800000, 0x3F000000, 0x00000000, 0x00000000, 0x0000000A, (u32)lbl_8_data_9054__fzgx_offset_0, 0x00000009, (u32)lbl_8_data_911C__fzgx_offset_0, 0x00000002, (u32)lbl_8_data_91D0__fzgx_offset_0, 0x00000003, (u32)lbl_8_data_91F8__fzgx_offset_0, 0x00000003, (u32)lbl_8_data_9234__fzgx_offset_0, 0x00000002, 0x00000000, 0xC28E0000, 0x00000000, 0x00000000, 0x00000002, 0x3E5DDDF4, 0xC2B19D58, 0xC3882D9D, 0xC3882D9D, 0x00000002, 0x3E911106, 0xC2E2CCCD, 0xC3EB5763, 0xC3EB5763, 0x00000002, 0x3EA2222D, 0xC302C5CE, 0xC40DD103, 0xC40DD103, 0x00000002, 0x3EB33333, 0xC316E3AD, 0xC41B09B6, 0xC41B09B6, 0x00000002, 0x3EC44439, 0xC32ADE56, 0xC3FF7027, 0xC3FF7027, 0x00000002, 0x3ED55561, 0xC335DF67, 0xC23DDF81, 0xC23DDF81, 0x00000002, 0x3EE66666, 0xC329F335, 0x44631D07, 0x44631D07, 0x00000002, 0x3EEEEEFA, 0xC31595FD, 0x44BD975E, 0x44BD975E, 0x00000002, 0x3F000000, 0xC2AA0EC0, 0x44F9E25F, 0x44F9E25F, 0x00000002, 0x3F04444A, 0xC25306B7, 0x44DF9788, 0x44DF9788, 0x00000002, 0x3F111117, 0x4191C7E9, 0x448F59C7, 0x448F59C7, 0x00000002, 0x3F22221D, 0x429E76A5, 0x44363635, 0x44363635, 0x00000002, 0x3F44444A, 0x430DF8D3, 0x438344A9, 0x438344A9, 0x00000002, 0x3F800000, 0x43200001, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x42B40000, 0x00000000, 0x00000000, 0x00000002, 0x3E5DDDF4, 0x4299AD22, 0xC34B5279, 0xC34B5279, 0x00000002, 0x3EA2222D, 0x422DCFE5, 0xC3FB039C, 0xC3FB039C, 0x00000002, 0x3EC44439, 0xC0195FFA, 0xC469E361, 0xC469E361, 0x00000002, 0x3ED55561, 0xC21A8213, 0xC498316B, 0xC498316B, 0x00000002, 0x3EDDDDD3, 0xC26F646C, 0xC4A02A33, 0xC4A02A33, 0x00000002, 0x3EE66666, 0xC2A2ACE0, 0xC4944660, 0xC4944660, 0x00000002, 0x3EEEEEFA, 0xC2C6C6AD, 0xC4494850, 0xC4494850, 0x00000002, 0x3EF7776C, 0xC2D859C2, 0xC33999BC, 0xC33999BC, 0x00000002, 0x3F000000, 0xC2D32642, 0x43C90A00, 0x43C90A00, 0x00000002, 0x3F04444A, 0xC2BD8BA0, 0x443D8222, 0x443D8222, 0x00000002, 0x3F088883, 0xC2A09D25, 0x44630D5D, 0x44630D5D, 0x00000002, 0x3F0CCCCD, 0xC280FF84, 0x446D701C, 0x446D701C, 0x00000002, 0x3F155550, 0xC205736C, 0x445EF709, 0x445EF709, 0x00000002, 0x3F266666, 0x4192FE76, 0x44231349, 0x44231349, 0x00000002, 0x3F37777D, 0x425780D8, 0x43D1DAB4, 0x43D1DAB4, 0x00000002, 0x3F800000, 0x42B40000, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0x3F000000, 0x3F37AEFF, 0x3FAB1E3A, 0x3FAB1E3A, 0x00000002, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x3F000000, 0x00000000, 0x00000000, 0x00000002, 0x3F000000, 0x3F000000, 0x00000000, 0x00000000, 0x00000002, 0x3F800000, 0x3F000000, 0x00000000, 0x00000000, 0x0000000F, (u32)lbl_8_data_9298__fzgx_offset_0, 0x00000011, (u32)lbl_8_data_93C4__fzgx_offset_0, 0x00000002, (u32)lbl_8_data_9518__fzgx_offset_0, 0x00000003, (u32)lbl_8_data_9540__fzgx_offset_0, 0x00000003, (u32)lbl_8_data_957C__fzgx_offset_0, (u32)fn_8_9B44__fzgx_offset_0, (u32)fn_8_9FB4__fzgx_offset_0, (u32)fn_8_A3A4__fzgx_offset_0, (u32)fn_8_A954__fzgx_offset_0, (u32)fn_8_ABBC__fzgx_offset_0, (u32)fn_8_BAEC__fzgx_offset_0, (u32)fn_8_ADF4__fzgx_offset_0, (u32)fn_8_B138__fzgx_offset_0, (u32)fn_8_BC04__fzgx_offset_0, (u32)fn_8_B380__fzgx_offset_0, (u32)fn_8_B840__fzgx_offset_0, 0x000001E0, 0x000001E0, 0x000001E0, 0x000001E0, 0x000001E0, 0x0000001E, 0x0000012C, 0x0000012C, 0x0000001E, 0x000001E0, 0x000001E0, 0x000001E0, 0x000001E0, 0x000001E0, 0x000001E0, 0x000001E0, 0x0000001E, 0x0000012C, 0x0000012C, 0x0000001E, 0x000001E0, 0x000001E0, 0x0000000B, 0x4120746F, 0x74616C20, 0x6F662034, 0x30202B20, 0x616C7068, 0x61206361, 0x72642076, 0x61726961, 0x74696F6E, 0x732E0000, 0x834A815B, 0x836882CD, 0x91539594, 0x82C53431, 0x8EED97DE, 0x2B83BF81, 0x420A0000, (u32)lbl_8_data_9668__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_9690__fzgx_offset_0, 0x596F7520, 0x77696C6C, 0x20676574, 0x20616E20, 0x6F726967, 0x696E616C, 0x206D6163, 0x68696E65, 0x0A617320, 0x796F7520, 0x63726561, 0x74652074, 0x68652046, 0x2D5A4552, 0x4F204C49, 0x43454E53, 0x45204341, 0x52442E00, 0x2F626366, 0x66383034, 0x302F462D, 0x5A45524F, 0x20838983, 0x43835A83, 0x93835883, 0x4A815B83, 0x682F6263, 0x66666666, 0x66662F82, 0xF08DEC90, 0xAC82B782, 0xE982C60A, 0x2F626366, 0x66666630, 0x302F8349, 0x838A8357, 0x8369838B, 0x837D8356, 0x83932F62, 0x63666666, 0x6666662F, 0x82AA82E0, 0x82E782A6, 0x82DC82B7, 0x81420A00, (u32)lbl_8_data_96C4__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_970C__fzgx_offset_0, 0x596F7520, 0x77696C6C, 0x20656172, 0x6E207468, 0x65205069, 0x6C6F7420, 0x506F696E, 0x74732062, 0x7920706C, 0x6179696E, 0x670A7769, 0x74682079, 0x6F757220, 0x462D5A45, 0x524F204C, 0x4943454E, 0x53452043, 0x4152442E, 0x00000000, 0x834A815B, 0x836882F0, 0x8E6782C1, 0x82C48376, 0x838C8343, 0x82B782E9, 0x82C60A2F, 0x62636666, 0x38303430, 0x2F837083, 0x43838D83, 0x62836783, 0x7C834383, 0x9383672F, 0x62636666, 0x66666666, 0x2F82AA93, 0xFC82E882, 0xDC82B781, 0x42000000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static const char *fzgx_pool_native_lbl_8_data_7E50_description[6] = {(const char *)(u32)lbl_8_data_9790__fzgx_offset_0, (const char *)(u32)lbl_8_data_81AC__fzgx_offset_0, (const char *)(u32)lbl_8_data_81AC__fzgx_offset_0, (const char *)(u32)lbl_8_data_81AC__fzgx_offset_0, (const char *)(u32)lbl_8_data_81AC__fzgx_offset_0, (const char *)(u32)lbl_8_data_97DC__fzgx_offset_0}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_8_data_7E50_gap_19F4[508] = {0x436F6C6C, 0x65637420, 0x616E6420, 0x65786368, 0x616E6765, 0x20746865, 0x2050696C, 0x6F742050, 0x6F696E74, 0x730A666F, 0x72207061, 0x72747320, 0x6974656D, 0x7320746F, 0x20627569, 0x6C640A79, 0x6F757220, 0x6F776E20, 0x63757374, 0x6F6D206D, 0x61636869, 0x6E652E00, 0x82B182CC, 0x837C8343, 0x83938367, 0x82F08F57, 0x82DF82E9, 0x82C62F62, 0x63666638, 0x3034302F, 0x8370815B, 0x836382CC, 0x8CF08AB7, 0x2F626366, 0x66666666, 0x662F82AA, 0x82C582AB, 0x82DC82B7, 0x81420A8E, 0xA995AA82, 0xBE82AF82, 0xCC837D83, 0x56839382, 0xC9834A83, 0x58835E83, 0x7D834383, 0x5982B582, 0xC482AD82, 0xBE82B382, 0xA2814200, (u32)lbl_8_data_9844__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_989C__fzgx_offset_0, 0x596F7520, 0x63616E20, 0x73617665, 0x206F7468, 0x65722069, 0x6E666F72, 0x6D617469, 0x6F6E206C, 0x696B650A, 0x70696C6F, 0x74207261, 0x6E6B2065, 0x61726E69, 0x6E677320, 0x616E6420, 0x72616369, 0x6E672064, 0x6174612E, 0x00000000, 0x82B182CC, 0x91BC82C9, 0x82E08370, 0x8343838D, 0x83628367, 0x83898393, 0x834E82CC, 0x8A6C93BE, 0x82E20A83, 0x76838C83, 0x43836681, 0x5B835E82, 0xF0835A81, 0x5B837582, 0xB782E982, 0xB182C682, 0xAA82C582, 0xAB82DC82, 0xB7814200, (u32)lbl_8_data_9924__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_9970__fzgx_offset_0, 0x596F7520, 0x77696C6C, 0x20676574, 0x20796F75, 0x72207061, 0x7373776F, 0x72640A62, 0x7920706C, 0x6179696E, 0x67207468, 0x65205469, 0x6D652041, 0x74746163, 0x6B204D6F, 0x64650A77, 0x69746820, 0x796F7572, 0x20462D5A, 0x45524F20, 0x4C494345, 0x4E534520, 0x43415244, 0x2E000000, 0x462D5A45, 0x524F8389, 0x8343835A, 0x83938358, 0x834A815B, 0x836882F0, 0x8E679770, 0x82B582C4, 0x0A2F6263, 0x66663830, 0x34302F83, 0x5E834383, 0x80834183, 0x5E836283, 0x4E838281, 0x5B83682F, 0x62636666, 0x66666666, 0x2F82F083, 0x76838C83, 0x4382B782, 0xE982C60A, 0x2F626366, 0x66666630, 0x302F8370, 0x8358838F, 0x815B8368, 0x2F626366, 0x66666666, 0x662F82AA, 0x955C8EA6, 0x82B382EA, 0x82DC82B7, 0x81420000, (u32)lbl_8_data_99D4__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_9A30__fzgx_offset_0, 0x456E7465, 0x7220796F, 0x75722070, 0x61737377, 0x6F726420, 0x61742074, 0x68650A46, 0x2D5A4552, 0x4F206F66, 0x66696369, 0x616C2077, 0x65627369, 0x74652074, 0x6F206A6F, 0x696E0A74, 0x68652049, 0x6E746572, 0x6E657420, 0x52616E6B, 0x696E6721, 0x00000000, 0x462D5A45, 0x524F8CF6, 0x8EAE8379, 0x815B8357, 0x82C58370, 0x8358838F, 0x815B8368, 0x82F093FC, 0x97CD82B7, 0x82EA82CE, 0x81410A2F, 0x62636666, 0x38303430, 0x2F834383, 0x93835E81, 0x5B836C83, 0x62836783, 0x89839383, 0x4C839383, 0x4F2F6263, 0x66666666, 0x66662F82, 0xC98E5189, 0xC182C582, 0xAB82DC82, 0xB7814200, (u32)lbl_8_data_9AD0__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_9B24__fzgx_offset_0, 0x596F7520, 0x63616E20, 0x65786368, 0x616E6765, 0x20796F75, 0x7220462D, 0x5A45524F, 0x20475820, 0x64617461, 0x0A776974, 0x6820462D, 0x5A45524F, 0x20415820, 0x62792075, 0x73696E67, 0x0A746865, 0x204E494E, 0x54454E44, 0x4F204741, 0x4D454355, 0x4245204D, 0x656D6F72, 0x79204361, 0x72642E00, 0x2F626366, 0x66383034, 0x302F836A, 0x83938365, 0x83938368, 0x815B8351, 0x815B8380, 0x834C8385, 0x815B8375, 0x9770835C, 0x83748367, 0x0A462D5A, 0x45524F20, 0x47582F62, 0x63666666, 0x6666662F, 0x82CC8366, 0x815B835E, 0x82CC93FC, 0x82C182BD, 0x83818382, 0x838A815B, 0x834A815B, 0x836882F0, 0x0A8E6797, 0x7082B782, 0xE982C681, 0x412F6263, 0x66666666, 0x30302F46, 0x2D5A4552, 0x4F204158, 0x2F626366, 0x66666666, 0x662F82C6, 0x0A984193, 0xAE82C582, 0xAB82DC82, 0xB7814200, (u32)lbl_8_data_9BA4__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_9C04__fzgx_offset_0, 0x596F7520, 0x63616E20, 0x6C6F6164, 0x20796F75, 0x7220462D, 0x5A45524F, 0x20475820, 0x6D616368, 0x696E6520, 0x64617461, 0x0A66726F, 0x6D20796F, 0x7572204D, 0x656D6F72, 0x79204361, 0x72642061, 0x6E642079, 0x6F752063, 0x616E0A61, 0x6C736F20, 0x646F776E, 0x6C6F6164, 0x20746865, 0x20462D5A, 0x45524F20, 0x4158206D, 0x61636869, 0x6E652064, 0x6174610A, 0x746F2079, 0x6F757220, 0x4D656D6F, 0x72792043, 0x6172642E, 0x00000000, 0x83818382, 0x838A815B, 0x834A815B, 0x836882F0, 0x917D93FC, 0x82B782E9, 0x82C68141, 0x2F626366, 0x66383034, 0x302F836A, 0x83938365, 0x83938368, 0x815B0A83, 0x51815B83, 0x80834C83, 0x85815B83, 0x75977083, 0x5C837483, 0x67462D5A, 0x45524F20, 0x47582F62, 0x63666666, 0x6666662F, 0x82CC0A83, 0x7D835683, 0x93836681, 0x5B835E82, 0xCC838D81, 0x5B836882, 0xE22F6263, 0x66666666, 0x30302F46, 0x2D5A4552, 0x4F204158, 0x2F626366, 0x66666666, 0x662F82CC, 0x0A835883, 0x79835683, 0x83838B83, 0x66815B83, 0x5E82F083, 0x5F834583, 0x93838D81, 0x5B836882, 0xC582AB82, 0xDC82B781, 0x42000000, (u32)lbl_8_data_9CB8__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_9D44__fzgx_offset_0, 0x506C6561, 0x7365206D, 0x616B6520, 0x73757265, 0x20746865, 0x72652069, 0x73206E6F, 0x20666F72, 0x6569676E, 0x206F626A, 0x65637420, 0x696E2074, 0x68650A73, 0x6C6F742C, 0x20626566, 0x6F726520, 0x796F7520, 0x696E7365, 0x72742074, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642E20, 0x4D656D6F, 0x72790A43, 0x61726473, 0x20776974, 0x686F7574, 0x20462D5A, 0x45524F20, 0x47582067, 0x616D6520, 0x64617461, 0x2063616E, 0x206E6F74, 0x2062650A, 0x75736564, 0x2E20446F, 0x206E6F74, 0x20746F75, 0x63682074, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642064, 0x7572696E, 0x67207468, 0x65206761, 0x6D650A70, 0x6C61792E, 0x20497420, 0x63616E20, 0x64616D61, 0x67652074, 0x68652066, 0x696C652E, 0x20497420, 0x69732072, 0x65636F6D, 0x6D656E64, 0x65642074, 0x6F0A7361, 0x7665206F, 0x6E6C7920, 0x74686520, 0x462D5A45, 0x524F2047, 0x58206461, 0x74612069, 0x6E207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x642E0000, 0x2F626338, 0x30383038, 0x302F8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82F08DB7, 0x82B58D9E, 0x82DE914F, 0x82C98358, 0x838D8362, 0x836782C9, 0x88D98FED, 0x82AA82C8, 0x82A282B1, 0x82C682F0, 0x0A8A6D94, 0x4682B582, 0xC489BA82, 0xB382A281, 0x422F6263, 0x35303530, 0x61302F46, 0x2D5A4552, 0x4F204758, 0x2F626338, 0x30383038, 0x302F88C8, 0x8A4F82CC, 0x8366815B, 0x835E82F0, 0x0A93FC82, 0xEA82C882, 0xA282C58E, 0x67977082, 0xB782E982, 0xB182C682, 0xF090848F, 0xA782B582, 0xDC82B781, 0x420A8376, 0x838C8343, 0x928682CC, 0x834A815B, 0x836882CC, 0x94B282AB, 0x8DB782B5, 0x82CD8141, 0x90E291CE, 0x82C982A8, 0x82E282DF, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_8_data_9E1C__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_81AC__fzgx_offset_0, (u32)lbl_8_data_9F44__fzgx_offset_0}; /* fzgx-allow: A1 measured pool bytes and bindings */
static char fzgx_pool_native_lbl_8_data_7E50_points0[8] = {0x31, 0x30, 0x30, 0x30, 0x50, 0x54, 0x53, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static char fzgx_pool_native_lbl_8_data_7E50_points1[8] = {0x32, 0x30, 0x30, 0x30, 0x50, 0x54, 0x53, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static char fzgx_pool_native_lbl_8_data_7E50_points2[8] = {0x34, 0x30, 0x30, 0x30, 0x50, 0x54, 0x53, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static char fzgx_pool_native_lbl_8_data_7E50_points3[8] = {0x38, 0x30, 0x30, 0x30, 0x50, 0x54, 0x53, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_data_base_prime(void) {
    const void *volatile s;  /* fzgx-allow: S2 data base primer sink: the retail TU addressed .data off its section base before its literal pool; the section is dropped at integration */
    s = fzgx_pool_native_lbl_8_data_7E50_description;
    s = fzgx_pool_native_lbl_8_data_7E50_points0;
    s = fzgx_pool_native_lbl_8_data_7E50_points1;
    s = fzgx_pool_native_lbl_8_data_7E50_points2;
    s = fzgx_pool_native_lbl_8_data_7E50_points3;
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
static const u32 fzgx_pool_table12[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table13[1] = {0xFF4040FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.1111111640930176f;
    s = 160.0f;
}
static const u32 fzgx_pool_table15[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

struct fn_8_A3A4_bss {
    u8 pad_0[0x24];
    u16 unk_24;
    u8 pad_26[0x76];
    s16 unk_9C;
    u8 pad_9E[0x86];
    s32 unk_124;
    s32 unk_128;
};

struct fn_8_A3A4_rodata {
    f64 unk_0;
    f32 unk_8;
    f32 unk_C;
    f64 unk_10;
    f32 unk_18;
    u8 pad_1C[0x4];
    f32 unk_20;
    f32 unk_24;
    f64 unk_28;
    u8 pad_30[0x4];
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    u8 pad_4C[0x60];
    f32 unk_AC;
    u8 pad_B0[0x60];
    f32 unk_110;
    u8 pad_114[0x28];
    u32 unk_13C;
    u32 unk_140;
    f32 unk_144;
    f32 unk_148;
};

struct fn_8_A3A4_data {
    u8 pad_0[0x19DC];
    const char *description[6];
    u8 pad_19F4[0x7F0];
    char points0[8];
    char points1[8];
    char points2[8];
    char points3[8];
};

extern struct fn_8_A3A4_bss lbl_8_bss_2A8;
extern struct fn_8_A3A4_data lbl_8_data_7E50;
extern u32 lbl_801A66A0;
extern u32 lbl_801A66B4;
extern u32 fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern u32 fn_1_4D0A0(void);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D0D4(u32 *, f32);
extern void fn_1_494DC(s16);
extern void fn_1_49514(u32 *);
extern f32 lbl_8006D0B4(f32);
extern s32 fn_1_5233C;
extern s32 fn_8_CC2C;

#pragma opt_propagation off

void fn_8_A3A4(void) {
    s32 pos;
    u32 arg;
    u32 tmp;
    u32 v140;
    struct fn_8_A3A4_bss *bss = &lbl_8_bss_2A8;
    f32 t;
    f32 u;
    f32 lab_t0;

    
    if ((f64)bss->unk_124 < (15.0)) {
        t = (1.0) - (f32)bss->unk_124 / (15.0);
        pos = (s32)((320.0f) + (f32)((640.0f) * t));
    } else if ((f64)bss->unk_124 > (f64)bss->unk_128 - (15.0)) {
        t = (1.0) - (f32)(bss->unk_128 - bss->unk_124) / (15.0);
        pos = (s32)((320.0f) - (f32)((640.0f) * t));
    } else {
        t = (0.0f);
        pos = 0x140;
    }

    u = (1.0f) - t;
    t = u * u;

    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_49590((0.5f));
    fn_1_495C8(9);
    fn_1_496FC((f32)pos, (345.0f));
    fn_1_4954C((0.0900000036f));
    fn_1_4955C((0.833333313f), (0.833333313f));
    fn_1_495A0(t);
    fn_1_4D0A0();
    fn_1_49738((u32)&fn_1_5233C);
    fn_1_49748((5.0f));
    fn_1_4AE0C(fzgx_pool_native_lbl_8_data_7E50_description[lbl_801A66B4]);
    fn_1_49738(0);

    tmp = fzgx_pool_table12[0];
    ((u8 *)&tmp)[3] = (u8)((255.0f) * t);
    arg = tmp;
    fn_1_4D0D4(&arg, (20.0f));

    fn_1_49410();
    fn_1_494DC(5);
    fn_1_495B0(0x80000000);
    fn_1_49738((u32)&fn_8_CC2C);
    fn_1_49748((5.0f));
    fn_1_49590((0.5f));
    fn_1_495C8(9);
    fn_1_496FC((f32)pos, (345.0f));
    fn_1_4954C((0.0900000036f));
    fn_1_4955C((1.0f), (1.11111116f));
    v140 = fzgx_pool_table13[0];
    fn_1_49514(&v140);

    if (bss->unk_124 <= bss->unk_128 && bss->unk_124 > bss->unk_128 * 2 / 3) {
        t = (f32)(bss->unk_124 - bss->unk_128 * 2 / 3) / (f32)(bss->unk_128 / 3);
        fn_1_495A0(lbl_8006D0B4(t));
        fn_1_496FC((160.0f),
                   (150.0f) - (60.0f) * ((1.0f) - t) * ((1.0f) - t));
        fn_1_4AE0C(fzgx_pool_native_lbl_8_data_7E50_points0);
    }

    if (bss->unk_124 <= bss->unk_128 * 5 / 6 && bss->unk_124 > bss->unk_128 * 3 / 6) {
        t = (f32)(bss->unk_124 - bss->unk_128 * 3 / 6) / (f32)(bss->unk_128 / 3);
        lab_t0 = lbl_8006D0B4(t);
        fn_1_495A0(lab_t0);
        fn_1_496FC((160.0f),
                   (150.0f) - (60.0f) * ((1.0f) - t) * ((1.0f) - t));
        fn_1_4AE0C(fzgx_pool_native_lbl_8_data_7E50_points1);
    }

    if (bss->unk_124 <= bss->unk_128 * 2 / 3 && bss->unk_124 > bss->unk_128 / 3) {
        t = (f32)(bss->unk_124 - bss->unk_128 / 3) / (f32)(bss->unk_128 / 3);
        fn_1_495A0(lbl_8006D0B4(t));
        fn_1_496FC((160.0f),
                   (150.0f) - (60.0f) * ((1.0f) - t) * ((1.0f) - t));
        fn_1_4AE0C(fzgx_pool_native_lbl_8_data_7E50_points2);
    }

    if (bss->unk_124 <= bss->unk_128 * 3 / 6 && bss->unk_124 > bss->unk_128 / 6) {
        t = (f32)(bss->unk_124 - bss->unk_128 / 6) / (f32)(bss->unk_128 / 3);
        fn_1_495A0(lbl_8006D0B4(t));
        fn_1_496FC((160.0f),
                   (150.0f) - (60.0f) * ((1.0f) - t) * ((1.0f) - t));
        fn_1_4AE0C(fzgx_pool_native_lbl_8_data_7E50_points3);
    }

    bss->unk_24 = 0;
    bss->unk_9C = lbl_801A66A0 << 9;
}
#pragma opt_propagation reset
/* fzgx:end fn_8_A3A4 */

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

/* fzgx:begin fn_8_ABBC */
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

struct fn_8_ABBC_bss {
    u8 pad_0[0x24];
    s16 unk_24;
    u8 pad_26[0x76];
    s16 unk_9C;
    u8 pad_9E[0x86];
    s32 unk_124;
    s32 unk_128;
};

typedef struct {
    u8 r, g, b, a;
} fn_8_ABBC_Color;

extern struct fn_8_ABBC_bss lbl_8_bss_2A8;
extern char *lbl_8_data_99BC[6];
extern u32 lbl_801A66B4;
extern u32 lbl_801A66A0;
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
extern void fn_1_4D0D4(fn_8_ABBC_Color *, f32);
extern void fn_1_5233C(void);

void fn_8_ABBC(void) {
    struct fn_8_ABBC_bss *p;
    s32 x;
    f32 t;
    f32 alpha;

    p = (struct fn_8_ABBC_bss *)&lbl_8_bss_2A8;
    if (p->unk_124 < 15.0) {
        t = 1.0 - (f32)p->unk_124 / 15.0;
        x = 320.0f + (f32)(640.0f * t);
    } else if (p->unk_124 > p->unk_128 - 15.0) {
        t = 1.0 - (f32)(p->unk_128 - p->unk_124) / 15.0;
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
    fn_1_496FC(x, 345.0f);
    fn_1_4954C(0.09f);
    fn_1_4955C(0.8333333f, 0.8333333f);
    fn_1_495A0(alpha);
    fn_1_4D0A0();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    fn_1_4AE0C(lbl_8_data_99BC[lbl_801A66B4]);
    fn_1_49738(0);
    {
        fn_8_ABBC_Color color2;
        fn_8_ABBC_Color color = { 255, 255, 255, 0 };
        color.a = 255.0f * alpha;
        color2 = color;
        fn_1_4D0D4(&color2, 20.0f);
    }
    p->unk_24 = 0;
    p->unk_9C = lbl_801A66A0 << 9;
}
/* fzgx:end fn_8_ABBC */

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

/* fzgx:begin fn_8_B840 */
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
#pragma section code_type ".text"

extern u32 lbl_801A66B4;
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_53B14(void *, f32, f32, f32, f32, f32);
extern void fn_1_5233C(void);

typedef struct { u8 r, g, b, a; } TitleColor;

void fn_8_B840(void) {
    f32 t;
    f32 opacity;
    s32 frame = (s32)lbl_8_bss_3CC;
    s32 x;
    if ((f64)frame < 15.0) {
        t = 1.0 - (f32)frame / 15.0;
        x = 320.0f + (f32)(640.0f * t);
    } else if ((f64)frame > (f64)(s32)lbl_8_bss_3D0.unk_0 - 15.0) {
        t = 1.0 - (f32)((s32)lbl_8_bss_3D0.unk_0 - frame) / 15.0;
        x = 320.0f - (f32)(640.0f * t);
    } else {
        t = 0.0f;
        x = 320;
    }
    t = 1.0f - t;
    opacity = t * t;
    fn_1_49410();
    fn_1_495B0(1U << 31);
    fn_1_49590(0.5f);
    fn_1_495C8(9);
    fn_1_496FC((f32)x, 345.0f);
    fn_1_4954C(0.09f);
    fn_1_4955C(0.8333333134651184f, 0.8333333134651184f);
    fn_1_495A0(opacity);
    fn_1_49738((u32)fn_1_5233C);
    fn_1_49748(5.0f);
    fn_1_4AE0C(((const char **)lbl_8_data_9E04)[lbl_801A66B4]);
    fn_1_49738(0);
    {
        TitleColor color = {255, 255, 255, 255};
        color.a = (u8)(255.0f * opacity);
        fn_1_53B14(&color, (f32)x, 345.0f, 541.0f, 100.0f, 0.11f);
    }
    fn_1_49410();
    if ((s32)lbl_801A66B4 == 5) {
        fn_1_4955C(0.48f, 0.48f);
    } else {
        fn_1_4955C(0.44f, 0.44f);
    }
    fn_1_495C8(18);
    fn_1_495B0(1U << 31);
    fn_1_49590(0.5f);
    fn_1_496FC(591.0f, 289.0f);
    fn_1_4AE0C(((const char **)lbl_8_data_A01C)[lbl_801A66B4]);
}
/* fzgx:end fn_8_B840 */

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

/* fzgx:begin fn_8_BD08 */
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
static const u32 fzgx_pool_table18[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table19[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const u32 *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 6.5f;
    s = 81.25f;
    s = 26.0f;
    s = 620.0f;
}
static const u32 fzgx_pool_table21[1] = {0x00000080};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const u32 *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct {
    s32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad_18[0x14];
    f32 unk_2C;
    s32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u8 pad_3C[0x1C];
} BD08Packet;

struct fn_8_BD08_bss {
    s32 unk_0;
    u8 pad_4[0x18];
    s32 unk_1C;
    s32 unk_20;
    s16 unk_24;
    u8 pad_26[0x3A];
    s16 unk_60;
    u8 pad_62[0x3A];
    s16 unk_9C;
    u8 pad_9E[0x86];
    s32 unk_124;
    s32 unk_128;
    u8 pad_12C[8];
    s32 unk_134;
};

struct fn_8_BD08_data {
    u8 pad_0[0x1790];
    void (*funcs[11])(void);
    s32 lens[11];
    s32 durs[11];
    s32 count;
    u8 pad_1818[0x2204 - 0x1818];
    char str0[0x14];
    char str1[0x14];
    char str2[0x14];
};

extern f32 lbl_8_rodata_160[];
extern struct fn_8_BD08_data lbl_8_data_7E50;
extern struct fn_8_BD08_bss lbl_8_bss_2A8;
extern BD08Packet lbl_1_rodata_26F8;
extern s16 lbl_1_bss_96A;
extern void **lbl_1_bss_6EAD0[];
extern s32 lbl_801A66A0;

extern void fn_8_CC2C(void);
extern void fn_1_3EF14(void *);
extern int fn_1_4F734(BD08Packet *);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495B0(u32);
extern void fn_1_49738(void *);
extern void fn_1_49748(f32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4CF3C(const char *, f32, ...);
extern int fn_1_3F038(void);
extern u32 fn_1_A1588(void *, u32);
extern void fn_8006CE1C(f32);
extern void fn_1_3F894(void);


#pragma opt_propagation off
void fn_8_BD08(void) {
    u8 buf[0x14B8];
    BD08Packet pkt;
    struct fn_8_BD08_data *data = (struct fn_8_BD08_data *)&lbl_8_data_7E50;
    struct fn_8_BD08_bss *bss = (struct fn_8_BD08_bss *)&lbl_8_bss_2A8;
    s32 *durs;
    s32 *lens;
    s32 frame;
    s32 count;
    s32 i;
    s32 sum;
    s32 idx;
    void (**funcs)(void);

    fn_1_3EF14(buf);
    pkt = lbl_1_rodata_26F8;
    pkt.unk_0 = 0x12;
    pkt.unk_38 = fzgx_pool_table19[0];
    pkt.unk_2C = 0.5f;
    pkt.unk_30 = 6;
    pkt.unk_4 = 320.0f;
    pkt.unk_8 = 0.0f;
    pkt.unk_14 = 6.5f;
    pkt.unk_10 = 81.25f;
    fn_1_4F734(&pkt);
    fn_1_49410();
    fn_1_494DC(5);
    fn_1_495B0(0x80000000);
    fn_1_49738(fn_8_CC2C);
    fn_1_49748(5.0f);
    fn_1_49590(0.5f);
    fn_1_495C8(1);
    fn_1_496FC(320.0f, 26.0f);
    fn_1_4954C(0.09f);
    fn_1_4955C(1.1111112f, 1.1111112f);
    if (bss->unk_20 < 0x96F) {
        fn_1_4CF3C(data->str0, 620.0f);
    } else if (bss->unk_20 < 0xBE5) {
        fn_1_4CF3C(data->str1, 620.0f);
    } else if (bss->unk_20 < 0xFB4) {
        fn_1_4CF3C(data->str2, 620.0f);
    }
    if (fn_1_3F038() != 0) {
        lbl_1_bss_96A = 0xA3;
        return;
    }
    if (bss->unk_20 > 3 && bss->unk_0 == 0) {
        fn_1_A1588(lbl_1_bss_6EAD0[0][0], 0x34);
        bss->unk_0 = 1;
    }
    count = data->count;
    durs = data->durs;
    lens = data->lens;
    frame = bss->unk_20;
    sum = 0;
    for (i = 0; i < count; i++) {
        if (sum == frame) {
            bss->unk_134 = i;
            bss->unk_124 = bss->unk_128 = *durs;
        }
        sum += *lens;
        durs++;
        lens++;
    }
    if (bss->unk_124 <= 0) {
        bss->unk_124 = 0;
        bss->unk_128 = 0;
        bss->unk_134 = -1;
    }
    bss->unk_9C = bss->unk_24 = bss->unk_60 = lbl_801A66A0 << 9;
    if (bss->unk_124 > 0) {
        bss->unk_124--;
        idx = bss->unk_134;
        if (idx >= 0 && idx < count) {
            {
                s32 off4 = idx * 4;
                funcs = (void (**)(void))(0x1790 + (u8 *)data);
                (*(void (**)(void))((u8 *)funcs + off4))();
            }
        }
    }
    if (bss->unk_20 == 0xFB4) {
        bss->unk_20 = 59940;
    }
    if (bss->unk_20 >= 59940) {
        if (bss->unk_1C != 0) {
            fn_8006CE1C(1.0f);
        } else {
            fn_8006CE1C((f32)(bss->unk_20 - 59940) / 60.0f);
        }
    }
    if (bss->unk_20 > 60000) {
        fn_8006CE1C(1.0f);
        fn_1_3F894();
    }
    bss->unk_20++;
}
/* fzgx:end fn_8_BD08 */

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

/* fzgx:begin fn_8_CC4C */
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
    s = 40.0f;
    s = -0.029999999329447746f;
    s = 5.500000042957254e-05f;
    s = 32768.0f;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"
struct fn_8_CC4C_lbl_801A66B4 { u32 unk_0; };
struct fn_8_CC4C_lbl_8_rodata_160 {
u8 pad_0[0x20]; f32 unk_20; u8 pad_24[4]; f64 unk_28;
u8 pad_30[4]; f32 unk_34; f32 unk_38; u8 pad_3C[0x7C];
f32 unk_B8; f32 unk_BC; f32 unk_C0; f32 unk_C4;
u8 pad_C8[0xE8]; f32 unk_1B0; u8 pad_1B4[0x38];
f32 unk_1EC; f32 unk_1F0; f32 unk_1F4; f32 unk_1F8; f32 unk_1FC; f64 unk_200;
};
struct fn_8_CC4C_lbl_1_bss_38460 { u8 pad_0[0x10]; u32 unk_10; u32 unk_14; };
struct fn_8_CC4C_lbl_801A66C8 { u32 unk_0; };
extern f32 fn_1_A6FE8(void);
extern f32 lbl_8006D188(u32);
extern f32 lbl_8006D21C(u32);
extern struct fn_8_CC4C_lbl_1_bss_38460 lbl_1_bss_38460;
extern struct fn_8_CC4C_lbl_801A66B4 lbl_801A66B4;
extern struct fn_8_CC4C_lbl_801A66C8 lbl_801A66C8;
extern struct fn_8_CC4C_lbl_8_rodata_160 lbl_8_rodata_160;
extern u32 fn_1_A7024(f32,f32,f32,f32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void fn_1_556B8(void *);
extern void fn_1_55FF0(f32);
extern void fn_1_56000(u8,u8,u8);
extern void fn_1_5621C(f32,f32,f32,f32);
extern void fn_1_A71CC(void);
extern void fn_1_A722C(void);
extern void fn_80072558(void);
extern void lbl_8006D758(void);
extern void lbl_8006E0B4(f32,f32,f32);
extern void lbl_8006E14C(f32);
#pragma opt_common_subs on
#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_8_CC4C(u32 x, u32 y) {
struct { u32 value; } model;
#define v2 model.value
u32 arg1 = y;
u32 arg0 = x;
struct fn_8_CC4C_lbl_8_rodata_160 *p_lbl_8_rodata_160;
u32 v0;
f32 v1;
f32 v3;
f32 v13;
f32 v12;
f32 v11;
f32 v4;
f32 v9;
f32 v5;
u32 v6;
f32 v14;
union { f64 d; struct { u32 hi, lo; } w; } cv0, cv1, cv2;
v0 = lbl_801A66B4.unk_0;
if ((s32)v0 != 5 || lbl_1_bss_38460.unk_10 != 0) {
if ((s32)v0 == 5 || lbl_1_bss_38460.unk_14 != 0) {
if ((s32)v0 == 5) {
v2 = *(u32 *)((u8 *)*(u32 *)((u8 *)lbl_1_bss_38460.unk_10 + 8) + 8);
} else {
v2 = *(u32 *)((u8 *)*(u32 *)((u8 *)lbl_1_bss_38460.unk_14 + 8) + 8);
}
fn_1_56000(1,7,1);
v1 = lbl_8006D21C(4096);
v3 = 240.0f;
v1 = v3 / v1;
v4 = 0.03f / v1;
fn_1_A71CC();
fn_1_A7024(45.0f,fn_1_A6FE8(),0.001f,100.0f);
v1 = (f32)((lbl_801A66C8.unk_0) % 40);
v9 = v1 / 40.0f;
lbl_8006D758();
v1 = (f32)(s32)(arg0 - 320);
v11 = v1 * v4;
v1 = v11;
v12 = (f32)(s32)(arg1 - 240) * v4;
lbl_8006E0B4(v1,v12,-0.03f);
v1 = 40.0f;
v1 = v1 * v9;
v13 = (f32)(v1 - 20.0f) * v4;
v1 = v13;
lbl_8006E0B4(v1,v13,0.0f);
mathutil_mtxA_rotate_z(-8192);
v1 = 0.000055f;
lbl_8006E14C(v1);
fn_80072558();
v4 = 32768.0f * v9;
v14 = v4;
v1 = lbl_8006D188((s32)v4);
fn_1_55FF0(v1);
v1 = 0.0f;
fn_1_5621C(v1,v1,v1,1.0f);
fn_1_556B8((void *)v2);
v1 = 1.0f;
fn_1_5621C(v1,v1,v1,v1);
lbl_8006D758();
v1 = v11;
lbl_8006E0B4(v1,v12,-0.03f);
v1 = v13;
lbl_8006E0B4(v1,v13,0.0f);
mathutil_mtxA_rotate_z(-8192);
v1 = 0.00005f;
lbl_8006E14C(v1);
fn_80072558();
v1 = lbl_8006D188((s32)v14);
fn_1_55FF0(v1);
v1 = 1.0f;
fn_1_5621C(v1,v1,0.0f,v1);
fn_1_556B8((void *)v2);
v1 = 1.0f;
fn_1_5621C(v1,v1,v1,v1);
fn_1_A722C();
v1 = 1.0f;
fn_1_55FF0(v1);
fn_1_56000(1,3,1);
}
}
}
/* fzgx:end fn_8_CC4C */

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

/* fzgx:begin fn_8_D630 */
typedef signed short s16;
typedef signed long s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef float f32;
typedef double f64;

typedef unsigned long size_t;

/* lbl_4_bss_5680: .bss size 0x4, referenced by 8 functions, shape {'object': 112, 'pointer': 28} */
typedef struct {
u32 unk_0; /* 11 loads, 6 stores */
u32 unk_4; /* 1 loads, 1 stores */
u32 unk_8; /* 4 loads, 1 stores */
u8 unk_C; /* 8 loads, 1 stores */
u8 unk_D; /* 5 loads, 4 stores */
u8 unk_E; /* 10 loads, 3 stores */
u8 unk_F; /* 3 loads, 12 stores */
u8 unk_10; /* 1 loads, 0 stores */
u8 unk_11; /* 2 loads, 1 stores */
u16 unk_12; /* 3 loads, 3 stores */
u8 unk_14; /* 2 loads, 2 stores */
u8 unk_15; /* 2 loads, 2 stores */
u8 unk_16; /* 2 loads, 2 stores */
u8 unk_17; /* 2 loads, 2 stores */
u32 unk_18; /* 1 loads, 1 stores */
u32 unk_1C; /* 1 loads, 1 stores */
u32 unk_20; /* 3 loads, 2 stores */
u8 pad_24[0x4];
u8 unk_28; /* 1 loads, 0 stores */
u8 pad_29[0xD];
u8 unk_36; /* 2 loads, 1 stores */
u8 unk_37; /* 0 loads, 1 stores */
u8 pad_38[0x2];
u8 unk_3A; /* 2 loads, 2 stores */
u8 unk_3B; /* 5 loads, 2 stores */
u32 unk_3C; /* 4 loads, 2 stores */
} Obj_4_bss_5680_Target;
extern Obj_4_bss_5680_Target *lbl_8_bss_550;

/* lbl_4_data_2F78: .data size 0xA0, referenced by 5 functions, shape {} */
extern u8 lbl_8_data_A1E8[0xA0];

/* lbl_4_bss_5684: .bss size 0x1, referenced by 3 functions, shape {'object': 3} */
extern u8 lbl_8_bss_554;

extern void fn_1_A2D84(u32);

typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
u8 color[4], color_add[4];
u32 format;
u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[360] = {0x89709094, 0x00000000, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x824F8250, 0x82518252, 0x82538254, 0x82558256, 0x82578258, 0x81E781E8, 0x00000000, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x00000000, 0x8B4C8D86, 0x00000000, 0x81418142, 0x814C814D, 0x81458143, 0x81448146, 0x81478148, 0x8149817B, 0x817C815E, 0x81818183, 0x8184814F, 0x81518160, 0x81628175, 0x81768169, 0x816A816F, 0x8170816D, 0x816E818F, 0x81908193, 0x81948195, 0x81968197, 0x81E781E8, 0x00000000, 0x82D082E7, 0x82AA82C8, 0x00000000, 0x82A082A2, 0x82A482A6, 0x82A882A9, 0x82AB82AD, 0x82AF82B1, 0x82B382B5, 0x82B782B9, 0x82BB82BD, 0x82BF82C2, 0x82C482C6, 0x82C882C9, 0x82CA82CB, 0x82CC82CD, 0x82D082D3, 0x82D682D9, 0x82DC82DD, 0x82DE82DF, 0x82E082E2, 0x82E482E6, 0x82E782E8, 0x82E982EA, 0x82EB82ED, 0x82EE82EF, 0x82F082F1, 0x82AA82AC, 0x82AE82B0, 0x82B282B4, 0x82B682B8, 0x82BA82BC, 0x82BE82C0, 0x82C382C5, 0x82C782CE, 0x82D182D4, 0x82D782DA, 0x82CF82D2, 0x82D582D8, 0x82DB829F, 0x82A182A3, 0x82A582A7, 0x82C182E1, 0x82E382E5, 0x82EC81E7, 0x81E80000, 0x829F82A1, 0x82A382A5, 0x82A782AA, 0x82AC82AE, 0x82B082B2, 0x82B482B6, 0x82B882BA, 0x82BC82BE, 0x82C082C1, 0x82C582C7, 0x81408140, 0x81408140, 0x814082CE, 0x82D182D4, 0x82D782DA, 0x81408140, 0x81408140, 0x814082E1, 0x82E382E5, 0x81408140, 0x81408140, 0x814082EC, 0x81408140, 0x81408140, 0x82A982AB, 0x82AD82AF, 0x82B182B3, 0x82B582B7, 0x82B982BB, 0x82BD82BF, 0x82C282C4, 0x82C682CF, 0x82D282D5, 0x82D882DB, 0x82CD82D0, 0x82D382D6, 0x82D982A0, 0x82A282A4, 0x82A682A8, 0x82C282E2, 0x82E482E6, 0x82ED8140, 0x81400000, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x814082C3, 0x81408140, 0x81408140, 0x81408140, 0x814082CF, 0x82D282D5, 0x82D882DB, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x82C18140, 0x814082CD, 0x82D082D3, 0x82D682D9, 0x82CE82D1, 0x82D482D7, 0x82DA8140, 0x81408140, 0x81408140, 0x82C38140, 0x81408140, 0x81408140, 0x81400000, 0x834A835E, 0x834A8369, 0x00000000, 0x83418343, 0x83458347, 0x8349834A, 0x834C834E, 0x83508352, 0x83548356, 0x8358835A, 0x835C835E, 0x83608363, 0x83658367, 0x8369836A, 0x836B836C, 0x836D836E, 0x83718374, 0x82D6837A, 0x837D837E, 0x83808381, 0x83828384, 0x83868388, 0x8389838A, 0x838B838C, 0x838D838F, 0x83908391, 0x83928393, 0x8394834B, 0x834D834F, 0x83518353, 0x83558357, 0x8359835B, 0x835D835F, 0x83618364, 0x83668368, 0x836F8372, 0x837582D7, 0x837B8370, 0x83738376, 0x82D8837C, 0x83408342, 0x83448346, 0x83488395, 0x83968362, 0x83838385, 0x8387838E, 0x81E781E8, 0x00000000, 0x83408342, 0x83448346, 0x8348834B, 0x834D834F, 0x83518353, 0x83558357, 0x8359835B, 0x835D835F, 0x83618362, 0x83668368, 0x81408140, 0x81408140, 0x8140836F, 0x83728375, 0x82D7837B, 0x81408140, 0x81408140, 0x81408383, 0x83858387, 0x81408140, 0x81408140, 0x8140838E, 0x81408140, 0x81408140, 0x8345834A, 0x834C834E, 0x83508352, 0x83548356, 0x8358835A, 0x835C835E, 0x83608363, 0x83658367, 0x83708373, 0x837682D8, 0x837C836E, 0x83718374, 0x82D6837A, 0x83418343, 0x83458347, 0x8349834A, 0x83508363, 0x83848386, 0x8388838F, 0x81408140, 0x00000000, 0x81408140, 0x83948140, 0x81408395, 0x81408140, 0x83968140, 0x81408140, 0x81408140, 0x81408140, 0x81408364, 0x81408140, 0x81408140, 0x81408140, 0x81408370, 0x83738376, 0x82D8837C, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x83448395, 0x81408140, 0x83968140, 0x81408140, 0x81408140, 0x81408140, 0x81408362, 0x81408140, 0x836E8371, 0x837482D6, 0x837A836F, 0x83728375, 0x82D7837B, 0x81408140, 0x83948140, 0x8140834B, 0x83518364, 0x81408140, 0x81408140, 0x81408140, 0x00000000}; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; } /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
volatile f32 s; volatile f64 d; /* fzgx-allow: S2 pool primer sinks */
s = 225.43910217285156f;
}
static const u32 fzgx_pool_table3[65] = {0x74616C20, 0x4C657474, 0x65727300, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x81E781E8, 0x00000000, 0x536D616C, 0x6C204C65, 0x74746572, 0x73000000, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x81E781E8, 0x00000000, 0x5369676E, 0x73000000, 0x81438144, 0x81488149, 0x817B817C, 0x815E815F, 0x81818183, 0x81848146, 0x8147814C, 0x814D814F, 0x81518162, 0x8169816A, 0x816D816E, 0x816F8170, 0x81908193, 0x81948195, 0x81968197, 0x81E781E8, 0x00000000, 0x4E756D62, 0x65727300, 0x824F8250, 0x82518252, 0x82538254, 0x82558256, 0x82578258, 0x81E781E8, 0x00000000}; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; } /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
volatile f32 s; volatile f64 d; /* fzgx-allow: S2 pool primer sinks */
d = 0.21;
d = 1.6666666666666667;
d = 0.5;
s = 48.0f;
s = 0.25f;
d = 1.0;
s = 0.12999999523162842f;
s = 0.0f;
d = 1.5;
d = 2.0;
s = 1.6666666269302368f;
s = 0.0625f;
d = 4503601774854144.0;
d = 4503599627370496.0;
}
#pragma section code_type ".text"
struct fn_8_D630_rodata {
u8 pad_0[0x6A8];
f64 unk_6A8;
f64 unk_6B0;
f64 unk_6B8;
f32 unk_6C0;
f32 unk_6C4;
f64 unk_6C8;
f32 unk_6D0;
u8 pad_6D4[0x4];
f64 unk_6D8;
f64 unk_6E0;
f32 unk_6E8;
f32 unk_6EC;
f64 unk_6F0;
f64 unk_6F8;
};

#pragma pack(1)
struct fn_8_D630_obj {
u8 unk_0;
u8 unk_1;
u8 unk_2;
u8 unk_3;
u16 unk_4;
u16 unk_6;
u16 unk_8;
u16 unk_A;
u8 unk_C;
u32 unk_D;
};
#pragma pack()
extern struct fn_8_D630_rodata lbl_8_rodata_408;
extern u8 lbl_8_data_A1E8[];
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_801A6410;
extern u8 lbl_8_bss_554;
extern void fn_1_46B4(u32, u32, const char *, int);
extern u32 fn_1_4060(void);
extern s32 strncmp(const char *, const char *, size_t);
extern char * strncpy(char *, const char *, size_t);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495C8(u8);
extern void fn_1_49514(u32 *);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_A2D84(u32);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_4A0D8(const char *);
#pragma pool_data on
#pragma fp_contract off
#pragma opt_common_subs off
static inline f64 fn_10_2325C_read_pointer(struct fn_8_D630_rodata * owner) { return owner->unk_6B0; }
static inline s32 fn_4_ADF4_sign(s32 x) { return x < 0 ? -1 : x > 0; }
static inline u8 fn_4_ADF4_blend(u8 c, f32 f) {
f32 delta = (f32)(255 - c) * f;
return (s32)((f32)c + delta);
}
void fn_8_D630(struct fn_8_D630_obj *arg0)
{
struct fn_8_D630_obj *p;
struct fn_8_D630_rodata *r;
u8 *d;
u8 name[4];
u8 ph[4];
u32 col1;
u32 col2;
u32 col3;
u32 col4;
FontDrawPacket loc_20;
f32 f;
f32 scale;
u32 t;
u32 n2;
s32 e;
p = arg0;
r = &lbl_8_rodata_408;
d = lbl_8_data_A1E8;
if (lbl_8_bss_554 != 0) {
fn_1_46B4(lbl_801A6410, (u32)p, (const char *)(d + 0xA0), 0xFB);
fn_1_4060();
return;
}
n2 = (p->unk_C + 1) & 0x1F;
t = lbl_8_bss_550->unk_20;
if (__rlwnm(t, n2, 31, 31) != 0) {
if (p->unk_0 != 1 || p->unk_1 != 0x18) {
p->unk_0 = 4;
p->unk_1 = 0x10;
lbl_8_bss_550->unk_20 &= ~(0x80000000U >> p->unk_C);
if (strncmp((const char *)p + 2, (const char *)(d + 0xB0), 2) == 0) {
strncpy((char *)p + 2, (const char *)(d + 0xB4), 2);
name[0] = p->unk_2;
name[1] = p->unk_3;
}
}
}
name[0] = p->unk_2;
name[1] = p->unk_3;
name[2] = 0;
fn_1_49410();
fn_1_494DC(0x2A);
fn_1_495C8(9);
switch (p->unk_0) {
case 1:
{
u16 c4 = p->unk_4;
s32 t4 = (s32)p->unk_8 - (s32)c4;
f64 dd = 0.21 * (f64)t4;
if ((s32)dd != 0) {
p->unk_4 = (u16)(s32)((f64)(u32)c4 + dd);
} else {
e = fn_4_ADF4_sign(t4);
/* Retail rereads the position after selecting the one-step adjustment. */
p->unk_4 = *(volatile u16 *)&p->unk_4 + e;
}
{
u16 c6 = p->unk_6;
s32 t6 = (s32)p->unk_A - (s32)c6;
dd = 0.21 * (f64)t6;
if ((s32)dd != 0) {
p->unk_6 = (u16)(s32)((f64)(u32)c6 + dd);
} else {
e = fn_4_ADF4_sign(t6);
/* Retail rereads the position after selecting the one-step adjustment. */
p->unk_6 = *(volatile u16 *)&p->unk_6 + e;
}
}
}
col1 = p->unk_D;
fn_1_49514(&col1);
fn_1_496FC((f32)p->unk_4, (f32)p->unk_6);
{
f64 scale_d = 1.6666666666666667 * (0.5 + (f32)(0x18 - p->unk_1) / 48.0f);
fn_1_4955C(scale_d, scale_d);
}
if (p->unk_1 == 1) {
p->unk_0 = 2;
p->unk_4 = p->unk_8;
p->unk_6 = p->unk_A;
}
break;
case 2:
if (p->unk_1 == 0) {
p->unk_1 = 4;
fn_1_A2D84(0xA9010100);
}
*(u32 *)ph = p->unk_D;
{
f32 quarter = 0.25f;
f = (f32)p->unk_1 * quarter;
{
ph[0] += (255 - ph[0]) * f;
ph[1] += (255 - ph[1]) * f;
ph[2] += (255 - ph[2]) * f;
}
}
col2 = *(u32 *)ph;
fn_1_49514(&col2);
fn_1_496FC((f32)p->unk_4, (f32)p->unk_6);
{
f64 scale_d = 1.6666666666666667 * (1.0 + 0.5 * (f64)f);
fn_1_4955C(scale_d, scale_d);
}
loc_20 = *(FontDrawPacket *)(&lbl_1_rodata_26F8);
loc_20.image = 0x8F09;
loc_20.x = (f32)p->unk_4;
loc_20.y = (f32)p->unk_6;
loc_20.z = 0.13f;
loc_20.scale_x = loc_20.scale_y = (1.5 + 2.0 * (f64)f);
loc_20.flags = 0xA;
fn_1_4F734((FontDrawPacket *)&loc_20);
if (p->unk_1 == 1) {
p->unk_0 = 3;
if (strncmp((const char *)p + 2, (const char *)(d + 0xB4), 2) == 0) {
strncpy((char *)p + 2, (const char *)(d + 0xB0), 2);
name[0] = p->unk_2;
name[1] = p->unk_3;
}
}
break;
case 3:
col3 = p->unk_D;
fn_1_49514(&col3);
fn_1_496FC((f32)p->unk_4, (f32)p->unk_6);
fn_1_4955C(1.6666666f, 1.6666666f);
break;
case 4:
if (p->unk_1 == 0) {
fn_1_46B4(lbl_801A6410, (u32)p, (const char *)(d + 0xA0), 0x169);
fn_1_4060();
return;
}
col4 = p->unk_D;
fn_1_49514(&col4);
fn_1_496FC((f32)p->unk_4, (f32)p->unk_6);
{
f64 scale_d = 1.6666666666666667 * (1.0 + 0.5 * (f32)(0x10 - p->unk_1));
fn_1_4955C(scale_d, scale_d);
}
{
f32 alpha = (f32)p->unk_1;
alpha *= 0.0625f;
fn_1_495A0(alpha);
}
break;
}
fn_1_4A0D8((const char *)name);
p->unk_1--;
}
#pragma opt_common_subs reset
/* fzgx:end fn_8_D630 */

/* fzgx:begin fn_8_DD64 */
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef float f32;
typedef double f64;

typedef unsigned long size_t;
typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
u8 color[4], color_add[4];
u32 format;
u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);

/* lbl_4_bss_5680: .bss size 0x4, referenced by 8 functions, shape {'object': 112, 'pointer': 28} */
typedef struct {
u32 unk_0; /* 11 loads, 6 stores */
u32 unk_4; /* 1 loads, 1 stores */
u32 unk_8; /* 4 loads, 1 stores */
u8 unk_C; /* 8 loads, 1 stores */
u8 unk_D; /* 5 loads, 4 stores */
u8 unk_E; /* 10 loads, 3 stores */
u8 unk_F; /* 3 loads, 12 stores */
u8 unk_10; /* 1 loads, 0 stores */
u8 unk_11; /* 2 loads, 1 stores */
u16 unk_12; /* 3 loads, 3 stores */
u8 unk_14; /* 2 loads, 2 stores */
u8 unk_15; /* 2 loads, 2 stores */
u8 unk_16; /* 2 loads, 2 stores */
u8 unk_17; /* 2 loads, 2 stores */
u32 unk_18; /* 1 loads, 1 stores */
u32 unk_1C; /* 1 loads, 1 stores */
u32 unk_20; /* 3 loads, 2 stores */
u8 pad_24[0x4];
u8 unk_28; /* 1 loads, 0 stores */
u8 pad_29[0xD];
u8 unk_36; /* 2 loads, 1 stores */
u8 unk_37; /* 0 loads, 1 stores */
u8 pad_38[0x2];
u8 unk_3A; /* 2 loads, 2 stores */
u8 unk_3B; /* 5 loads, 2 stores */
u32 unk_3C; /* 4 loads, 2 stores */
} Obj_4_bss_5680_Target;
extern Obj_4_bss_5680_Target *lbl_8_bss_550;

/* lbl_4_data_2F78: .data size 0xA0, referenced by 5 functions, shape {} */
extern u8 lbl_8_data_A1E8[0xA0];

/* lbl_4_bss_5684: .bss size 0x1, referenced by 3 functions, shape {'object': 3} */
extern u8 lbl_8_bss_554;

void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);
struct fn_8_DD64_lbl_801A63D0 {
u32 unk_0;
};
struct fn_8_DD64_lbl_8_rodata_408 {
u8 pad_0[0x6F0];
f64 unk_6F0;
f64 unk_6F8;
f32 unk_700;
f32 unk_704;
f32 unk_708;
u32 unk_70C;
u32 unk_710;
u32 unk_714;
u32 unk_718;
u32 unk_71C;
u32 unk_720;
f32 unk_724;
f32 unk_728;
u8 pad_72C[0x4];
f64 unk_730;
f64 unk_738;
f32 unk_740;
u8 pad_744[0x4];
f64 unk_748;
f32 unk_750;
f32 unk_754;
};
extern char * fn_80083CF4(char *, const char *, size_t);
extern char * strcat(char *, const char *);
extern char * strncpy(char *, const char *, size_t);
extern int fn_1_4F734(FontDrawPacket *);
extern int sprintf(char *, const char *, ...);
extern size_t strlen(const char *);
extern struct fn_8_DD64_lbl_801A63D0 lbl_801A63D0;
extern struct fn_8_DD64_lbl_8_rodata_408 lbl_8_rodata_408;
extern u32 fn_1_4060(void);
extern u32 fn_1_49410(void);
typedef struct Sig_fn_800081C8_Color Sig_fn_800081C8_Color;
extern u32 fn_800081C8(Sig_fn_800081C8_Color, Sig_fn_800081C8_Color, f32);
extern u32 fn_800793D4(u8 *, u32, void *);
extern u32 fn_80083DB0(u32, u32);
extern u32 lbl_801A6410;
extern u8 * fn_80083970(u8 *, const u8 *);
extern u8 lbl_1_rodata_26F8[];
extern u8 lbl_8_bss_554;
extern u8 lbl_8_data_A1E8[];
extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_1_494DC(s16);
extern void fn_1_49514(Sig_fn_800081C8_Color);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495C8(u8);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
struct Sig_fn_800081C8_Color { u8 r, g, b, a; };
#pragma fp_contract off
#pragma opt_common_subs off
#pragma opt_lifetimes off
#pragma opt_loop_invariants off
extern int __abs(int);
#pragma force_active on
static const u32 fzgx_pool_table_0[] = {2305855636u,0u,2187362913u,2187493987u,2187625061u,2187756135u,2187887209u,2188018283u,2188149357u,2188280431u,2188411505u,2188542579u,2188673653u,2188804727u,2188935801u,2189525634u,2189656708u,2189787782u,2189918856u,2190049930u,2190181004u,2190312078u,2190443152u,2190574226u,2190705300u,2190836374u,2190967448u,2191098522u,2186248784u,2186379858u,2186510932u,2186642006u,2186773080u,2179432936u,0u,2189525634u,2189656708u,2189787782u,2189918856u,2190049930u,2190181004u,2190312078u,2190443152u,2190574226u,2190705300u,2190836374u,2190967448u,2191098522u,2187362913u,2187493987u,2187625061u,2187756135u,2187887209u,2188018283u,2188149357u,2188280431u,2188411505u,2188542579u,2188673653u,2188804727u,2188935801u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,0u,2337049990u,0u,2168553794u,2169274701u,2168815939u,2168750406u,2168947016u,2169078139u,2172420446u,2172748163u,2172944719u,2169602400u,2170716533u,2172027241u,2171240815u,2171634029u,2171502991u,2173731219u,2173993365u,2174124439u,2179432936u,0u,2194703079u,2192212680u,0u,2191557282u,2191819430u,2192081577u,2192278189u,2192540337u,2192802485u,2193064633u,2193326781u,2193588930u,2193916614u,2194178761u,2194309835u,2194440909u,2194703059u,2195096281u,2195489501u,2195620575u,2195751650u,2196013798u,2196210408u,2196341482u,2196472557u,2196669167u,2196800241u,2192212652u,2192474800u,2192736948u,2192999096u,2193261244u,2193523392u,2193851077u,2194113230u,2194768596u,2195161818u,2194637522u,2195030744u,2195423903u,2191622819u,2191884967u,2193720033u,2195948261u,2196537831u,2179465216u,2191491745u,2191753893u,2192016042u,2192343726u,2192605874u,2192868022u,2193130170u,2193392318u,2193654465u,2193982151u,2168488256u,2168488256u,2168488654u,2194768596u,2195161818u,2168488256u,2168488256u,2168488673u,2195948261u,2168488256u,2168488256u,2168488684u,2168488256u,2168488256u,2192147115u,2192409263u,2192671411u,2192933559u,2193195707u,2193457855u,2193785540u,2194047695u,2194834133u,2195227355u,2194506448u,2194899670u,2195292832u,2191688356u,2191950504u,2193785570u,2196013798u,2196603200u,2168455168u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488643u,2168488256u,2168488256u,2168488256u,2168488655u,2194834133u,2195227355u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2193719616u,2168488653u,2194703059u,2195096281u,2194571985u,2194965207u,2195358016u,2168488256u,2168488256u,2193850688u,2168488256u,2168488256u,2168455168u,2202698590u,2202698601u,0u,2202108739u,2202370887u,2202633034u,2202829646u,2203091794u,2203353942u,2203616090u,2203878238u,2204140387u,2204468071u,2204730218u,2204861292u,2204992366u,2205254516u,2195096442u,2206040958u,2206237569u,2206368644u,2206630792u,2206827402u,2206958476u,2207089551u,2207286161u,2207417235u,2207548235u,2202895183u,2203157331u,2203419479u,2203681627u,2203943775u,2204205924u,2204533608u,2205123442u,2205516503u,2205909872u,2205385590u,2195227516u,2202043202u,2202305350u,2202567573u,2207679330u,2206434181u,2206696334u,2179432936u,0u,2202043202u,2202305350u,2202567499u,2202895183u,2203157331u,2203419479u,2203681627u,2203943775u,2204205922u,2204533608u,2168488256u,2168488256u,2168488815u,2205320053u,2195161979u,2168488256u,2168488256u,2168488835u,2206565255u,2168488256u,2168488256u,2168488846u,2168488256u,2168488256u,2202370890u,2202829646u,2203091794u,2203353942u,2203616090u,2203878238u,2204140387u,2204468071u,2205188979u,2205582040u,2205975406u,2205254516u,2195096442u,2202108739u,2202370887u,2202633034u,2203091811u,2206499718u,2206761871u,2168488256u,0u,2168488256u,2207547712u,2168488853u,2168488256u,2207678784u,2168488256u,2168488256u,2168488256u,2168488804u,2168488256u,2168488256u,2168488256u,2168488816u,2205385590u,2195227516u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2202305429u,2168488256u,2207678784u,2168488256u,2168488256u,2168488256u,2168488802u,2168488256u,2205057905u,2205450966u,2205844335u,2205320053u,2195161979u,2168488256u,2207547712u,2168488779u,2203157348u,2168488256u,2168488256u,2168488256u,0u,1130459241u,1952541728u,1281717364u,1701999360u,2187362913u,2187493987u,2187625061u,2187756135u,2187887209u,2188018283u,2188149357u,2188280431u,2188411505u,2188542579u,2188673653u,2188804727u,2188935801u,2179432936u,0u,1399677292u,1814056037u,1953785202u,1929379840u,2189525634u,2189656708u,2189787782u,2189918856u,2190049930u,2190181004u,2190312078u,2190443152u,2190574226u,2190705300u,2190836374u,2190967448u,2191098522u,2179432936u,0u,1399416686u,1929379840u,2168684868u,2169012553u,2172354940u,2170454367u,2172748163u,2172944710u,2168947020u,2169340239u,2169602402u,2171175274u,2171437422u,2171568496u,2173731219u,2173993365u,2174124439u,2179432936u,0u,1316318562u,1701999360u,2186248784u,2186379858u,2186510932u,2186642006u,2186773080u,2179432936u,0u,1070260551u,2920577761u,1073392298u,2863311531u,1071644672u,0u,1111490560u,1048576000u,1072693248u,0u,1040522936u,0u,1073217536u,0u,1073741824u,0u,1070945621u,1031798784u};
#pragma force_active reset
#pragma push
#pragma section code_type ".fzgxpool"
static f64 fzgx_signed_double(s32 value) { return (f64)value; }
static f64 fzgx_unsigned_double(u32 value) { return (f64)value; }
static f32 fzgx_glyph_size(s32 index) {
switch(index) {
case 0:return 32.0f;
case 1:return 24.0f;
default:return 18.0f;
}
}
#pragma force_active reset
#pragma pop
void fn_8_DD64(u32 arg0) {
u8 *p_lbl_8_data_A1E8;
struct fn_8_DD64_lbl_8_rodata_408 *p_lbl_8_rodata_408;
u8 *p_lbl_1_rodata_26F8;
u32 v0;
s32 v1;
s32 v2;
s32 state_value;
s32 cursor_next;
s32 v3;
u32 v4;
f32 v5;
f64 v6;
f32 v7;
struct OptionNameEntry { u16 cursor, length; char *chars; u8 pad[12]; } *v8;
u32 v9;
s32 v10;
u32 v12;
u32 v13;
u32 v14;
s32 v15;
f32 v16;
u16 v17;
f64 v18;
u32 v19;
u8 * v20;
u32 v21;
u32 v22;
f64 v23;
f32 v24;
f64 v25;
f32 v26;
f32 v27;
struct { u32 a[22]; } loc_18;
Sig_fn_800081C8_Color loc_14;
Sig_fn_800081C8_Color loc_10;
Sig_fn_800081C8_Color loc_C;
u32 loc_8;
u32 lab_t0;
u32 lab_t1;
p_lbl_8_data_A1E8 = lbl_8_data_A1E8;
p_lbl_8_rodata_408 = &lbl_8_rodata_408;
fn_800793D4((u8 *)lbl_801A63D0.unk_0, 0, (void *)1024);
v0 = lbl_801A63D0.unk_0;
if (lbl_8_bss_554 != 0) {
{ s32 __reg_value_v2 = arg0; v2 = __reg_value_v2; }
v1 = (u32)&lbl_801A6410;
v3 = (u32)((u8 *)(u32)p_lbl_8_data_A1E8 + 160);
v1 = *(u32 *)((u8 *)v1 + 0);
v4 = 465;
fn_1_46B4(v1, v2, (const char *)v3, v4);
v1 = fn_1_4060();
} else {
v1 = fn_1_49410();
v1 = 42;
fn_1_494DC(v1);
v1 = 9;
fn_1_495C8(v1);
fn_1_4966C(12.0f, 0.0f);
v1 = lbl_8_bss_550->unk_3C;
v8 = (struct OptionNameEntry *)v1 + *(u8 *)arg0;
v19 = v8->cursor;
v3 = (v19 - 10);
v1 = (v19 + 11);
if (v3 >= 0 && (s32)(v19 + 11) <= (s32)v8->length) {
{ s32 __reg_value_v2 = (u32)v8->chars; v2 = __reg_value_v2; }
v1 = v0;
v9 = (v3 << 1);
v3 = 42;
{ s32 __reg_value_v2 = (v2 + v9); v2 = __reg_value_v2; }
v1 = (u32)strncpy((char *)v1, (const char *)v2, v3);
} else if (v19 < 10) {
v10 = v19 - 10;
v10 = v8->length + v10;
if (v10 < 0) {
{ s32 __reg_value_v2 = (u32)v8->chars; v2 = __reg_value_v2; }
v1 = v0;
{ s32 __reg_value_v2 = (v2 + (v19 << 1)); v2 = __reg_value_v2; }
lab_t0 = v1;
lab_t1 = v2;
v1 = fn_80083DB0(lab_t0, lab_t1);
{ s32 __reg_value_v2 = (u32)v8->chars; v2 = __reg_value_v2; }
v1 = v0;
v1 = (u32)strcat((char *)v1, (const char *)v2);
{ s32 __reg_value_v2 = (u32)v8->chars; v2 = __reg_value_v2; }
v1 = v0;
v3 = ((v10 + 10) << 1);
v1 = (u32)fn_80083CF4((char *)v1, (const char *)v2, v3);
} else {
{ s32 __reg_value_v2 = (u32)v8->chars; v2 = __reg_value_v2; }
v1 = v0;
{ s32 __reg_value_v2 = (v2 + (v10 << 1)); v2 = __reg_value_v2; }
lab_t0 = v1;
lab_t1 = v2;
v1 = fn_80083DB0(lab_t0, lab_t1);
v1 = v8->cursor;
v10 = (v1 + 11);
if ((s32)v10 > (s32)v8->length) {
{ s32 __reg_value_v2 = (u32)v8->chars; v2 = __reg_value_v2; }
v1 = v0;
v1 = (u32)strcat((char *)v1, (const char *)v2);
v1 = v0;
{ s32 __reg_value_v2 = (u32)v8->chars; v2 = __reg_value_v2; }
v3 = ((v10 - v8->length) << 1);
v1 = (u32)fn_80083CF4((char *)v1, (const char *)v2, v3);
} else {
{ s32 __reg_value_v2 = (u32)v8->chars; v2 = __reg_value_v2; }
v1 = v0;
v3 = (v10 << 1);
v1 = (u32)fn_80083CF4((char *)v1, (const char *)v2, v3);
}
}
} else {
{ s32 __reg_value_v2 = (u32)v8->chars; v2 = __reg_value_v2; }
v1 = v0;
{ s32 __reg_value_v2 = (v2 + (v3 << 1)); v2 = __reg_value_v2; }
lab_t0 = v1;
lab_t1 = v2;
v1 = fn_80083DB0(lab_t0, lab_t1);
{ s32 __reg_value_v2 = v8->cursor; v2 = __reg_value_v2; }
v1 = v0;
v3 = v8->length;
v12 = (v2 + 11);
{ s32 __reg_value_v2 = (u32)v8->chars; v2 = __reg_value_v2; }
v3 = ((v12 - v3) << 1);
v1 = (u32)fn_80083CF4((char *)v1, (const char *)v2, v3);
}
{ s32 __reg_value_v2 = *(u8 *)((u8 *)arg0 + 0); v2 = __reg_value_v2; }
v1 = (u32)lbl_8_bss_550;
if ((u32)v2 == *(u8 *)((u8 *)v1 + 13)) {
u32 b14;
{ s32 __reg_value_v2 = (v0 + 6); v2 = __reg_value_v2; }
v1 = (u32)&lbl_801A63D0;
v3 = 14;
v1 = *(u32 *)((u8 *)v1 + 0);
v10 = (v1 + 44);
b14 = (v1 + 88);
v1 = v10;
v1 = (u32)strncpy((char *)v1, (const char *)v2, v3);
v1 = b14;
{ s32 __reg_value_v2 = (v0 + 22); v2 = __reg_value_v2; }
v3 = 14;
v1 = (u32)strncpy((char *)v1, (const char *)v2, v3);
v1 = v0;
v3 = v10;
v4 = b14;
{ s32 __reg_value_v2 = (u32)((u8 *)(u32)p_lbl_8_data_A1E8 + 184); v2 = __reg_value_v2; }
v1 = sprintf((char *)v1, (const char *)(u32)v2, v3, v4);
}
v1 = (u32)lbl_8_bss_550;
v1 = *(u8 *)((u8 *)v1 + 13);
v1 = (*(u8 *)((u8 *)arg0 + 0) - v1);
if (v1 < 0) {
v1 += 4;
}
switch (v1) {
case 0:
v15 = 178;
v16 = fzgx_glyph_size(0);
{ Sig_fn_800081C8_Color color0 = {255, 255, 255, 0}; loc_14 = color0; }
break;
case 1:
v15 = 276;
v16 = fzgx_glyph_size(1);
{ Sig_fn_800081C8_Color color1 = {0, 255, 255, 0}; loc_14 = color1; }
break;
case 2:
v15 = 313;
v16 = fzgx_glyph_size(2);
{ Sig_fn_800081C8_Color color2 = {0, 255, 255, 0}; loc_14 = color2; }
break;
case 3:
v15 = 84;
v16 = fzgx_glyph_size(1);
{ Sig_fn_800081C8_Color color3 = {0, 255, 255, 0}; loc_14 = color3; }
}
state_value = *(u16 *)((u8 *)arg0 + 4);
v3 = v15 - state_value;
v6 = 0.2 * fzgx_signed_double(v3);
if ((s32)v6 != 0) {
*(u16 *)((u8 *)arg0 + 4) = (s32)((f64)(u32)state_value + v6);
} else {
if (v3 < 0) {
v1 = -1;
} else {
v1 = v3 > 0;
}
*(u16 *)((u8 *)arg0 + 4) += v1;
}
v7 = *(f32 *)((u8 *)arg0 + 8);
v6 = 0.2;
*(f32 *)((u8 *)arg0 + 8) = v7 + v6 * (v16 - v7);
v1 = *(u8 *)((u8 *)arg0 + 2);
v13 = v8->cursor;
state_value = v1 + 1;
if (state_value == (s32)v13 || --v1 > (s32)v13) {
*(u8 *)((u8 *)arg0 + 1) = 36;
} else if (v1 == (s32)v13 || state_value < (s32)v13) {
*(s8 *)((u8 *)arg0 + 1) = -36;
}
v2 = (s8)*(u8 *)((u8 *)arg0 + 1);
v3 = -v2;
v6 = 0.2 * fzgx_signed_double(v3);
if ((s32)v6 != 0) {
*(u8 *)((u8 *)arg0 + 1) = (s32)((f64)v2 + v6);
} else {
if (v3 < 0) {
v1 = -1;
} else {
v1 = v3 > 0;
}
*(u8 *)((u8 *)arg0 + 1) += v1;
}
v1 = v0;
v2 = (u32)(p_lbl_8_data_A1E8 + 196);
*(u8 *)((u8 *)arg0 + 2) = v8->cursor;
v1 = (u32)fn_80083970((u8 *)v1, (const u8 *)v2);
p_lbl_1_rodata_26F8 = lbl_1_rodata_26F8;
v15 = 0x10000 - 28914;
v20 = (u8 *)v1;
v24 = 10.1f;
v25 = 24.0;
while (v20 != 0) {
v1 = strlen((const char *)v0);
state_value = v20 - (u8 *)v0;
v3 = v1 - 1;
v1 = (u32)state_value >> 31;
v1 = v1 + state_value;
state_value = (u32)v3 >> 2;
v1 >>= 1;
v3 = (u32)&loc_14;
v2 = v1 - state_value;
state_value = (u32)p_lbl_1_rodata_26F8 - 4;
for (v21 = 11; v21 != 0; v21--) {
v1 = *(u32 *)((u8 *)state_value + 4);
v22 = *(u32 *)((u8 *)state_value + 8);
state_value += 8;
*(u32 *)((u8 *)v3 + 4) = v1;
*(u32 *)((u8 *)v3 + 8) = v22;
v3 += 8;
}
loc_18.a[0] = v15;
v3 = *(u8 *)((u8 *)arg0 + 1);
v1 = (s8)v3;
v26 = (f32)(s32)v2 * *(f32 *)((u8 *)arg0 + 8);
v5 = (f32)(v1 + 320);
*(f32 *)((u8 *)&loc_18 + 4) = v5 + v26;
if (__abs((s32)v2) > 0) {
v3 = 1;
if ((s32)v2 < 0) v3 = -1;
state_value = (s32)v2 >> 31;
v1 = state_value ^ (s32)v2;
v1 -= state_value;
v6 = 12.0;
v7 = *(f32 *)((u8 *)&loc_18 + 4);
*(f32 *)((u8 *)&loc_18 + 4) = v7 + v6 * (v3 * v1);
}
*(f32 *)((u8 *)&loc_18 + 8) = (f32)(u32)*(u16 *)((u8 *)arg0 + 4);
*(f32 *)((u8 *)&loc_18 + 12) = v24;
loc_18.a[12] = 10;
v5 = 1.0f;
v27 = *(f32 *)((u8 *)arg0 + 8) / v25;
*(f32 *)((u8 *)&loc_18 + 20) = v27;
*(f32 *)((u8 *)&loc_18 + 16) = v27;
{
Sig_fn_800081C8_Color black = {0, 0, 0, 255};
Sig_fn_800081C8_Color white = {255, 255, 255, 255};
loc_10 = black;
loc_C = white;
v1 = fn_800081C8(loc_10, loc_C, v5);
}
loc_18.a[14] = v1;
fn_1_4F734((FontDrawPacket *)&loc_18);
v20 = fn_80083970(v20 + 2, p_lbl_8_data_A1E8 + 196);
}
v2 = (s8)*(u8 *)((u8 *)arg0 + 1);
v2 += 320;
v5 = (f32)v2;
v6 = (f32)(u32)*(u16 *)((u8 *)arg0 + 4);
fn_1_496FC(v5, v6);
v18 = *(f32 *)((u8 *)arg0 + 8) / 24.0;
fn_1_4955C(v18, v18);
{
fn_1_49514(loc_14);
}
fn_1_4954C(10.0f);
fn_1_4A0D8((const char *)v0);
}
}
#pragma opt_loop_invariants reset
#pragma opt_lifetimes reset
#pragma opt_common_subs reset
/* fzgx:end fn_8_DD64 */

/* fzgx:begin fn_8_E440 */
typedef signed char s8;

typedef signed long s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef double f64;

typedef unsigned long size_t;

/* lbl_10_bss_55CD8: .bss size 0x4, 5 refs from sel.c */
typedef struct {
u32 unk_0; /* 12 loads, 7 stores */
u32 unk_4; /* 1 loads, 1 stores */
u32 unk_8; /* 5 loads, 1 stores */
u8 unk_C; /* 8 loads, 1 stores */
u8 unk_D; /* 5 loads, 4 stores */
u8 unk_E; /* 10 loads, 4 stores */
u8 unk_F; /* 3 loads, 12 stores */
u8 unk_10; /* 1 loads, 0 stores */
u8 unk_11; /* 2 loads, 1 stores */
u16 unk_12; /* 3 loads, 3 stores */
u8 unk_14; /* 2 loads, 2 stores */
u8 unk_15; /* 2 loads, 2 stores */
u8 unk_16; /* 2 loads, 2 stores */
u8 unk_17; /* 2 loads, 2 stores */
u32 unk_18; /* 1 loads, 1 stores */
u32 unk_1C; /* 1 loads, 1 stores */
u32 unk_20; /* 3 loads, 2 stores */
u8 pad_24[0x4];
u8 unk_28; /* 2 loads, 0 stores */
u8 pad_29[0xD];
u8 unk_36; /* 2 loads, 1 stores */
u8 unk_37; /* 0 loads, 1 stores */
u8 pad_38[0x2];
u8 unk_3A; /* 2 loads, 2 stores */
u8 unk_3B; /* 5 loads, 2 stores */
u32 unk_3C; /* 4 loads, 2 stores */
} Obj_10_bss_55CD8_Target;
extern Obj_10_bss_55CD8_Target *lbl_8_bss_550;
/* lbl_10_data_68E0: .data size 0xA0, 5 refs from sel.c (own data block) */
extern u8 lbl_8_data_A1E8[0xA0];

extern u8 lbl_8_bss_555;
extern char *strncpy(char *, const char *, size_t);
extern s32 strncmp(const char *, const char *, size_t);

extern const f64 lbl_8_rodata_B68;
extern const u32 lbl_8_rodata_B60;
extern void *fn_1_45D0(u32, u32, u8 *, u32);
extern void fn_1_435C(u32);
extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern void fn_8_D630(void);
extern u8 lbl_1_bss_9F8[];
extern u8 lbl_1_bss_A48[];
extern u32 lbl_801A6410;
extern void fn_1_A2D84(u32);
typedef struct { u8 r, g, b, a; } MenuColor;
typedef struct {
u16 cur;
u16 max;
u8 *p4;
u8 *p8;
u8 *pC;
u32 pad;
} MenuEntry;
#pragma opt_common_subs off
void fn_8_E440(void) {
u8 *p;
void *rp;
u8 *q;
u32 cnt;
s32 flA;
s32 flB;
s32 flC;
u8 buf[2];
s32 i;
u16 *repeat;
u16 *held;
Obj_10_bss_55CD8_Target *state;
u8 *t8;
MenuEntry *e;
s32 inputIndex;
Obj_10_bss_55CD8_Target *active;
Obj_10_bss_55CD8_Target **inputRef;
s32 prev;
u8 *alternate;
MenuColor v68;
p = lbl_8_data_A1E8;
flA = 0;
flB = 0;
flC = 0;
if (lbl_8_bss_550->unk_0 >> 31) {
if (lbl_8_bss_555 == 0) {
goto end; /* matches retail's single early-exit block */
}
}
state = lbl_8_bss_550;
e = (MenuEntry *)state->unk_3C + state->unk_D;
t8 = lbl_1_bss_9F8 + 8;
if ((((u16 *)t8)[state->unk_C * 10] >> 12) & 1) {
if (e->cur == e->max - 1) {
lbl_8_bss_550->unk_0 |= 0x20000000;
fn_1_A2D84(0xA9010F00);
} else {
MenuEntry *z;
lbl_8_bss_550->unk_F = 0;
z = (MenuEntry *)lbl_8_bss_550->unk_3C;
for (i = 0; i < lbl_8_bss_550->unk_3B; i++) {
z->cur = z->max - 1;
z++;
}
fn_1_A2D84(0xA9010F00);
}
} else if (((((u16 *)t8)[state->unk_C * 10] >> 8) & 1) && lbl_8_bss_555 == 0) {
s32 cur = e->cur;
if (cur == e->max - 1) {
lbl_8_bss_550->unk_0 |= 0x20000000;
fn_1_A2D84(0xA9010F00);
} else {
cnt = (u8)(state->unk_E);
flA = 1;
if (cnt == 7 && state->unk_36 != 0) {
flB = 1;
}
{
switch (state->unk_F) {
case 0: q = e->p4 + cur * 2; break;
case 1: q = e->p8 + cur * 2; break;
case 2: q = e->pC + cur * 2; break;
}
}
strncpy((char *)buf, (char *)q, 2);
if (strncmp((char *)q, (char *)(p + 0xb4), 2) == 0) {
strncpy((char *)((u8 *)lbl_8_bss_550 + lbl_8_bss_550->unk_E * 2 + 0x28), (char *)(p + 0xb0), 2);
} else {
strncpy((char *)((u8 *)lbl_8_bss_550 + lbl_8_bss_550->unk_E * 2 + 0x28), (char *)q, 2);
}
{
Obj_10_bss_55CD8_Target **advanceRef = &lbl_8_bss_550;
Obj_10_bss_55CD8_Target *advance = *advanceRef;
if (advance->unk_E < 7) {
advance->unk_E = advance->unk_E + 1;
} else {
MenuEntry *z;
s32 j;
z = (MenuEntry *)advance->unk_3C;
for (j = 0; j < (*advanceRef)->unk_3B; j++) {
z->cur = z->max - 1;
z++;
}
}
}
lbl_8_bss_550->unk_F = 0;
}
} else if (((((u16 *)t8) [lbl_8_bss_550->unk_C * 10] >> 9) & 1) && lbl_8_bss_555 == 0) {
u32 pos;
state = lbl_8_bss_550;
pos = state->unk_E;
flB = pos != 0;
if (pos == 7 && state->unk_36 != 0) {
lbl_8_bss_550->unk_36 = 0;
lbl_8_bss_550->unk_37 = 0;
} else {
if (pos != 0) {
state->unk_E = state->unk_E - 1;
}
for (i = lbl_8_bss_550->unk_E; i <= 7; i++) {
if (i < 7) {
u8 *shift = (u8 *)lbl_8_bss_550 + i * 2;
shift[0x28] = shift[0x2a];
shift = (u8 *)lbl_8_bss_550 + i * 2;
shift[0x29] = shift[0x2b];
} else {
*((u8 *)lbl_8_bss_550 + i * 2 + 0x28) = 0;
*((u8 *)lbl_8_bss_550 + i * 2 + 0x29) = 0;
}
}
}
lbl_8_bss_550->unk_F = 0;
cnt = (u8)(lbl_8_bss_550->unk_E);
} else {
held = (u16 *)(lbl_1_bss_9F8 + 0x10);
if (((held[lbl_8_bss_550->unk_C * 10] >> 3) & 1) || (((repeat = (u16 *)(lbl_1_bss_9F8 + 0x12), repeat[lbl_8_bss_550->unk_C * 10]) >> 3) & 1)) {
if (lbl_8_bss_550->unk_D == 0) {
lbl_8_bss_550->unk_D = lbl_8_bss_550->unk_3B - 1;
} else {
lbl_8_bss_550->unk_D = lbl_8_bss_550->unk_D - 1;
}
lbl_8_bss_550->unk_F = 0;
} else if (((held[lbl_8_bss_550->unk_C * 10] >> 2) & 1) || ((repeat[lbl_8_bss_550->unk_C * 10] >> 2) & 1)) {
if (lbl_8_bss_550->unk_D == lbl_8_bss_550->unk_3B - 1) {
lbl_8_bss_550->unk_D = 0;
} else {
lbl_8_bss_550->unk_D = lbl_8_bss_550->unk_D + 1;
}
lbl_8_bss_550->unk_F = 0;
} else if ((held[lbl_8_bss_550->unk_C * 10] & 1) || (repeat[lbl_8_bss_550->unk_C * 10] & 1) || ((repeat[lbl_8_bss_550->unk_C * 10] >> 8) & 1)) {
if (e->cur == 0) {
e->cur = e->max - 1;
} else {
e->cur = e->cur - 1;
}
lbl_8_bss_550->unk_F = 0;
} else if (((held[lbl_8_bss_550->unk_C * 10] >> 1) & 1) || ((repeat[lbl_8_bss_550->unk_C * 10] >> 1) & 1) || ((repeat[lbl_8_bss_550->unk_C * 10] >> 9) & 1)) {
if (e->cur == e->max - 1) {
e->cur = 0;
} else {
e->cur = e->cur + 1;
}
lbl_8_bss_550->unk_F = 0;
} else if ((((u16 *)t8)[lbl_8_bss_550->unk_C * 10] >> 11) & 1) {
flC = 1;
lbl_8_bss_550->unk_F = lbl_8_bss_550->unk_F + 1;
if (lbl_8_bss_550->unk_F > 2) {
lbl_8_bss_550->unk_F = 0;
} else if (lbl_8_bss_550->unk_F == 1) {
alternate = e->p8;
if (alternate == 0) {
flC = 0;
lbl_8_bss_550->unk_F = 0;
} else if (strncmp((char *)(alternate + e->cur * 2), (char *)(p + 0xb0), 2) == 0) {
flC = 0;
lbl_8_bss_550->unk_F = 0;
}
} else if (lbl_8_bss_550->unk_F == 2) {
alternate = e->pC;
if (alternate == 0) {
lbl_8_bss_550->unk_F = 0;
} else if (strncmp((char *)(alternate + e->cur * 2), (char *)(p + 0xb0), 2) == 0) {
lbl_8_bss_550->unk_F = 0;
}
}
}
}
{
register Obj_10_bss_55CD8_Target **ref = &lbl_8_bss_550;
/* Observe the shared state pointer independently before this update stage. */
Obj_10_bss_55CD8_Target *before = *(Obj_10_bss_55CD8_Target *volatile *)ref;
Obj_10_bss_55CD8_Target *after;
s32 prev;
prev = *(s8 *)&before->unk_10;
before->unk_10 = ((s8 *)lbl_1_bss_A48)[before->unk_C << 4] >> 2;
after = *ref;
if (*(s8 *)&after->unk_10 == 0) {
u8 t = lbl_1_bss_A48[after->unk_C << 4];
if ((s8)t > 0) {
after->unk_10 = 1;
} else if ((s8)t < 0) {
*(s8 *)&after->unk_10 = -1;
} else {
*(s8 *)&after->unk_10 = prev < 0 ? -1 : 1;
}
}
}
{
register Obj_10_bss_55CD8_Target **smoothRef = &lbl_8_bss_550;
/* Observe the shared state pointer again for the animation update. */
Obj_10_bss_55CD8_Target *phase = *(Obj_10_bss_55CD8_Target *volatile *)smoothRef;
u32 old12;
s32 x;
f64 d;
Obj_10_bss_55CD8_Target *smooth;
phase->unk_11 = phase->unk_11 - phase->unk_10;
smooth = *smoothRef;
old12 = smooth->unk_12;
x = smooth->unk_E * 56 + 98 - old12;
d = lbl_8_rodata_B68 * (f64)x;
if ((s32)d != 0) {
smooth->unk_12 = (s32)((f64)old12 + d);
} else {
s32 step;
if (x < 0) {
step = -1;
} else {
step = x > 0;
}
smooth->unk_12 += step;
}
}
if (lbl_8_bss_550->unk_14 != 0) {
lbl_8_bss_550->unk_14 = lbl_8_bss_550->unk_14 - 1;
}
if (lbl_8_bss_550->unk_15 != 0) {
lbl_8_bss_550->unk_15 = lbl_8_bss_550->unk_15 - 1;
}
if (lbl_8_bss_550->unk_16 != 0) {
lbl_8_bss_550->unk_16 = lbl_8_bss_550->unk_16 - 1;
}
if (lbl_8_bss_550->unk_17 != 0) {
lbl_8_bss_550->unk_17 = lbl_8_bss_550->unk_17 - 1;
}
q = lbl_1_bss_9F8 + 0x10;
if (((*(u16 *)(q + lbl_8_bss_550->unk_C * 20) >> 3) & 1) || ((*(u16 *)((u32)(lbl_1_bss_9F8 + 0x12) + lbl_8_bss_550->unk_C * 20) >> 3) & 1)) {
lbl_8_bss_550->unk_14 = 8;
}
if (((*(u16 *)(q + lbl_8_bss_550->unk_C * 20) >> 2) & 1) || ((*(u16 *)((u32)(lbl_1_bss_9F8 + 0x12) + lbl_8_bss_550->unk_C * 20) >> 2) & 1)) {
lbl_8_bss_550->unk_15 = 8;
}
if ((*(u16 *)(q + lbl_8_bss_550->unk_C * 20) & 1) || ((repeat = (u16 *)(lbl_1_bss_9F8 + 0x12), repeat[lbl_8_bss_550->unk_C * 10]) & 1) ||
((repeat[lbl_8_bss_550->unk_C * 10] >> 8) & 1)) {
lbl_8_bss_550->unk_16 = 8;
}
if (((*(u16 *)(q + lbl_8_bss_550->unk_C * 20) >> 1) & 1) || (((repeat = (u16 *)(lbl_1_bss_9F8 + 0x12), repeat[lbl_8_bss_550->unk_C * 10]) >> 1) & 1) ||
((repeat[lbl_8_bss_550->unk_C * 10] >> 9) & 1)) {
lbl_8_bss_550->unk_17 = 8;
}
if (flA != 0) {
v68 = *(const MenuColor *)&lbl_8_rodata_B60;
rp = fn_1_45D0 (*(u32 *)&lbl_801A6410, 0x12, p + 0xa0, 0xd4);
*(u16 *)((u8 *)rp + 8) = (u16)((u32)(cnt & 0xFF) * 56 + 0x7e);
*(u16 *)((u8 *)rp + 10) = 0x17a;
*(u8 *)((u8 *)rp + 0) = 1;
*(u8 *)((u8 *)rp + 1) = 0x18;
*(u16 *)((u8 *)rp + 4) = 0x140;
*(u16 *)((u8 *)rp + 6) = 0xb2;
*(u8 *)((u8 *)rp + 2) = buf[0];
*(u8 *)((u8 *)rp + 3) = buf[1];
*(MenuColor *)((u8 *)rp + 0xd) = v68;
*(u8 *)((u8 *)rp + 0xc) = cnt;
fn_1_435C(lbl_8_bss_550->unk_8);
fn_1_3F8C((u32)(p + 0xc8), (u32)fn_8_D630, (u32)rp, 0xb);
}
if (flB != 0) {
lbl_8_bss_550->unk_20 |= ((u32)0x80000000 >> cnt);
}
if (flA != 0) {
lbl_8_bss_550->unk_3A = 12;
}
if (flA != 0) {
fn_1_A2D84(0xA9010F00);
}
if (flB != 0) {
fn_1_A2D84(0xA9010200);
}
if (flC != 0) {
fn_1_A2D84(0xA9010000);
}
if (((*(u16 *)(q + lbl_8_bss_550->unk_C * 20) >> 3) & 1) || (((repeat = (u16 *)(lbl_1_bss_9F8 + 0x12), repeat[lbl_8_bss_550->unk_C * 10]) >> 3) & 1) ||
((*(u16 *)(q + lbl_8_bss_550->unk_C * 20) >> 2) & 1) || ((repeat[lbl_8_bss_550->unk_C * 10] >> 2) & 1)) {
fn_1_A2D84(0xA9010000);
}
if ((*(u16 *)(q + lbl_8_bss_550->unk_C * 20) & 1) || ((repeat = (u16 *)(lbl_1_bss_9F8 + 0x12), repeat[lbl_8_bss_550->unk_C * 10]) & 1) || ((repeat[lbl_8_bss_550->unk_C * 10] >> 8) & 1) ||
((*(u16 *)(q + lbl_8_bss_550->unk_C * 20) >> 1) & 1) || ((repeat[lbl_8_bss_550->unk_C * 10] >> 1) & 1) || ((repeat[lbl_8_bss_550->unk_C * 10] >> 9) & 1)) {
fn_1_A2D84(0xA9010000);
}
if (lbl_8_bss_555 != 0) {
fn_1_A2D84(0xA9010200);
lbl_8_bss_550->unk_0 &= ~0x80000000u;
}
lbl_8_bss_555 = 0;
end:
return;
}
#pragma opt_common_subs reset
/* fzgx:end fn_8_E440 */

/* fzgx:begin fn_8_F9E4 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u8 unk_c;
    u8 pad_d[5];
    u16 unk_12;
    u8 pad_14[4];
    u32 unk_18;
    u32 unk_1c;
    u8 pad_20[0x1b];
    u8 unk_3b;
    u32 unk_3c;
} Obj;

typedef struct {
    u8 unk_0;
    u8 pad_1[3];
    u16 unk_4;
    f32 unk_8;
} Node;

extern u32 lbl_801A6410;
extern s16 lbl_1_bss_960;
extern s32 lbl_801A66B4;
const u8 lbl_8_rodata_408[8] = {0x89,0x70,0x90,0x94,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_410[132] = {0x82,0x60,0x82,0x61,0x82,0x62,0x82,0x63,0x82,0x64,0x82,0x65,0x82,0x66,0x82,0x67,0x82,0x68,0x82,0x69,0x82,0x6A,0x82,0x6B,0x82,0x6C,0x82,0x6D,0x82,0x6E,0x82,0x6F,0x82,0x70,0x82,0x71,0x82,0x72,0x82,0x73,0x82,0x74,0x82,0x75,0x82,0x76,0x82,0x77,0x82,0x78,0x82,0x79,0x82,0x81,0x82,0x82,0x82,0x83,0x82,0x84,0x82,0x85,0x82,0x86,0x82,0x87,0x82,0x88,0x82,0x89,0x82,0x8A,0x82,0x8B,0x82,0x8C,0x82,0x8D,0x82,0x8E,0x82,0x8F,0x82,0x90,0x82,0x91,0x82,0x92,0x82,0x93,0x82,0x94,0x82,0x95,0x82,0x96,0x82,0x97,0x82,0x98,0x82,0x99,0x82,0x9A,0x82,0x4F,0x82,0x50,0x82,0x51,0x82,0x52,0x82,0x53,0x82,0x54,0x82,0x55,0x82,0x56,0x82,0x57,0x82,0x58,0x81,0xE7,0x81,0xE8,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_494[132] = {0x82,0x81,0x82,0x82,0x82,0x83,0x82,0x84,0x82,0x85,0x82,0x86,0x82,0x87,0x82,0x88,0x82,0x89,0x82,0x8A,0x82,0x8B,0x82,0x8C,0x82,0x8D,0x82,0x8E,0x82,0x8F,0x82,0x90,0x82,0x91,0x82,0x92,0x82,0x93,0x82,0x94,0x82,0x95,0x82,0x96,0x82,0x97,0x82,0x98,0x82,0x99,0x82,0x9A,0x82,0x60,0x82,0x61,0x82,0x62,0x82,0x63,0x82,0x64,0x82,0x65,0x82,0x66,0x82,0x67,0x82,0x68,0x82,0x69,0x82,0x6A,0x82,0x6B,0x82,0x6C,0x82,0x6D,0x82,0x6E,0x82,0x6F,0x82,0x70,0x82,0x71,0x82,0x72,0x82,0x73,0x82,0x74,0x82,0x75,0x82,0x76,0x82,0x77,0x82,0x78,0x82,0x79,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_518[8] = {0x8B,0x4C,0x8D,0x86,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_520[80] = {0x81,0x41,0x81,0x42,0x81,0x4C,0x81,0x4D,0x81,0x45,0x81,0x43,0x81,0x44,0x81,0x46,0x81,0x47,0x81,0x48,0x81,0x49,0x81,0x7B,0x81,0x7C,0x81,0x5E,0x81,0x81,0x81,0x83,0x81,0x84,0x81,0x4F,0x81,0x51,0x81,0x60,0x81,0x62,0x81,0x75,0x81,0x76,0x81,0x69,0x81,0x6A,0x81,0x6F,0x81,0x70,0x81,0x6D,0x81,0x6E,0x81,0x8F,0x81,0x90,0x81,0x93,0x81,0x94,0x81,0x95,0x81,0x96,0x81,0x97,0x81,0xE7,0x81,0xE8,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_570[12] = {0x82,0xD0,0x82,0xE7,0x82,0xAA,0x82,0xC8,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_57C[172] = {0x82,0xA0,0x82,0xA2,0x82,0xA4,0x82,0xA6,0x82,0xA8,0x82,0xA9,0x82,0xAB,0x82,0xAD,0x82,0xAF,0x82,0xB1,0x82,0xB3,0x82,0xB5,0x82,0xB7,0x82,0xB9,0x82,0xBB,0x82,0xBD,0x82,0xBF,0x82,0xC2,0x82,0xC4,0x82,0xC6,0x82,0xC8,0x82,0xC9,0x82,0xCA,0x82,0xCB,0x82,0xCC,0x82,0xCD,0x82,0xD0,0x82,0xD3,0x82,0xD6,0x82,0xD9,0x82,0xDC,0x82,0xDD,0x82,0xDE,0x82,0xDF,0x82,0xE0,0x82,0xE2,0x82,0xE4,0x82,0xE6,0x82,0xE7,0x82,0xE8,0x82,0xE9,0x82,0xEA,0x82,0xEB,0x82,0xED,0x82,0xEE,0x82,0xEF,0x82,0xF0,0x82,0xF1,0x82,0xAA,0x82,0xAC,0x82,0xAE,0x82,0xB0,0x82,0xB2,0x82,0xB4,0x82,0xB6,0x82,0xB8,0x82,0xBA,0x82,0xBC,0x82,0xBE,0x82,0xC0,0x82,0xC3,0x82,0xC5,0x82,0xC7,0x82,0xCE,0x82,0xD1,0x82,0xD4,0x82,0xD7,0x82,0xDA,0x82,0xCF,0x82,0xD2,0x82,0xD5,0x82,0xD8,0x82,0xDB,0x82,0x9F,0x82,0xA1,0x82,0xA3,0x82,0xA5,0x82,0xA7,0x82,0xC1,0x82,0xE1,0x82,0xE3,0x82,0xE5,0x82,0xEC,0x81,0xE7,0x81,0xE8,0x00,0x00};
const u8 lbl_8_rodata_628[172] = {0x82,0x9F,0x82,0xA1,0x82,0xA3,0x82,0xA5,0x82,0xA7,0x82,0xAA,0x82,0xAC,0x82,0xAE,0x82,0xB0,0x82,0xB2,0x82,0xB4,0x82,0xB6,0x82,0xB8,0x82,0xBA,0x82,0xBC,0x82,0xBE,0x82,0xC0,0x82,0xC1,0x82,0xC5,0x82,0xC7,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x82,0xCE,0x82,0xD1,0x82,0xD4,0x82,0xD7,0x82,0xDA,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x82,0xE1,0x82,0xE3,0x82,0xE5,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x82,0xEC,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x82,0xA9,0x82,0xAB,0x82,0xAD,0x82,0xAF,0x82,0xB1,0x82,0xB3,0x82,0xB5,0x82,0xB7,0x82,0xB9,0x82,0xBB,0x82,0xBD,0x82,0xBF,0x82,0xC2,0x82,0xC4,0x82,0xC6,0x82,0xCF,0x82,0xD2,0x82,0xD5,0x82,0xD8,0x82,0xDB,0x82,0xCD,0x82,0xD0,0x82,0xD3,0x82,0xD6,0x82,0xD9,0x82,0xA0,0x82,0xA2,0x82,0xA4,0x82,0xA6,0x82,0xA8,0x82,0xC2,0x82,0xE2,0x82,0xE4,0x82,0xE6,0x82,0xED,0x81,0x40,0x81,0x40,0x00,0x00};
const u8 lbl_8_rodata_6D4[172] = {0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x82,0xC3,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x82,0xCF,0x82,0xD2,0x82,0xD5,0x82,0xD8,0x82,0xDB,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x82,0xC1,0x81,0x40,0x81,0x40,0x82,0xCD,0x82,0xD0,0x82,0xD3,0x82,0xD6,0x82,0xD9,0x82,0xCE,0x82,0xD1,0x82,0xD4,0x82,0xD7,0x82,0xDA,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x82,0xC3,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x00,0x00};
const u8 lbl_8_rodata_780[12] = {0x83,0x4A,0x83,0x5E,0x83,0x4A,0x83,0x69,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_78C[180] = {0x83,0x41,0x83,0x43,0x83,0x45,0x83,0x47,0x83,0x49,0x83,0x4A,0x83,0x4C,0x83,0x4E,0x83,0x50,0x83,0x52,0x83,0x54,0x83,0x56,0x83,0x58,0x83,0x5A,0x83,0x5C,0x83,0x5E,0x83,0x60,0x83,0x63,0x83,0x65,0x83,0x67,0x83,0x69,0x83,0x6A,0x83,0x6B,0x83,0x6C,0x83,0x6D,0x83,0x6E,0x83,0x71,0x83,0x74,0x82,0xD6,0x83,0x7A,0x83,0x7D,0x83,0x7E,0x83,0x80,0x83,0x81,0x83,0x82,0x83,0x84,0x83,0x86,0x83,0x88,0x83,0x89,0x83,0x8A,0x83,0x8B,0x83,0x8C,0x83,0x8D,0x83,0x8F,0x83,0x90,0x83,0x91,0x83,0x92,0x83,0x93,0x83,0x94,0x83,0x4B,0x83,0x4D,0x83,0x4F,0x83,0x51,0x83,0x53,0x83,0x55,0x83,0x57,0x83,0x59,0x83,0x5B,0x83,0x5D,0x83,0x5F,0x83,0x61,0x83,0x64,0x83,0x66,0x83,0x68,0x83,0x6F,0x83,0x72,0x83,0x75,0x82,0xD7,0x83,0x7B,0x83,0x70,0x83,0x73,0x83,0x76,0x82,0xD8,0x83,0x7C,0x83,0x40,0x83,0x42,0x83,0x44,0x83,0x46,0x83,0x48,0x83,0x95,0x83,0x96,0x83,0x62,0x83,0x83,0x83,0x85,0x83,0x87,0x83,0x8E,0x81,0xE7,0x81,0xE8,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_840[180] = {0x83,0x40,0x83,0x42,0x83,0x44,0x83,0x46,0x83,0x48,0x83,0x4B,0x83,0x4D,0x83,0x4F,0x83,0x51,0x83,0x53,0x83,0x55,0x83,0x57,0x83,0x59,0x83,0x5B,0x83,0x5D,0x83,0x5F,0x83,0x61,0x83,0x62,0x83,0x66,0x83,0x68,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x83,0x6F,0x83,0x72,0x83,0x75,0x82,0xD7,0x83,0x7B,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x83,0x83,0x83,0x85,0x83,0x87,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x83,0x8E,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x83,0x45,0x83,0x4A,0x83,0x4C,0x83,0x4E,0x83,0x50,0x83,0x52,0x83,0x54,0x83,0x56,0x83,0x58,0x83,0x5A,0x83,0x5C,0x83,0x5E,0x83,0x60,0x83,0x63,0x83,0x65,0x83,0x67,0x83,0x70,0x83,0x73,0x83,0x76,0x82,0xD8,0x83,0x7C,0x83,0x6E,0x83,0x71,0x83,0x74,0x82,0xD6,0x83,0x7A,0x83,0x41,0x83,0x43,0x83,0x45,0x83,0x47,0x83,0x49,0x83,0x4A,0x83,0x50,0x83,0x63,0x83,0x84,0x83,0x86,0x83,0x88,0x83,0x8F,0x81,0x40,0x81,0x40,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_8F4[180] = {0x81,0x40,0x81,0x40,0x83,0x94,0x81,0x40,0x81,0x40,0x83,0x95,0x81,0x40,0x81,0x40,0x83,0x96,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x83,0x64,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x83,0x70,0x83,0x73,0x83,0x76,0x82,0xD8,0x83,0x7C,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x83,0x44,0x83,0x95,0x81,0x40,0x81,0x40,0x83,0x96,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x83,0x62,0x81,0x40,0x81,0x40,0x83,0x6E,0x83,0x71,0x83,0x74,0x82,0xD6,0x83,0x7A,0x83,0x6F,0x83,0x72,0x83,0x75,0x82,0xD7,0x83,0x7B,0x81,0x40,0x81,0x40,0x83,0x94,0x81,0x40,0x81,0x40,0x83,0x4B,0x83,0x51,0x83,0x64,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_9A8[16] = {0x43,0x61,0x70,0x69,0x74,0x61,0x6C,0x20,0x4C,0x65,0x74,0x74,0x65,0x72,0x73,0x00};
const u8 lbl_8_rodata_9B8[60] = {0x82,0x60,0x82,0x61,0x82,0x62,0x82,0x63,0x82,0x64,0x82,0x65,0x82,0x66,0x82,0x67,0x82,0x68,0x82,0x69,0x82,0x6A,0x82,0x6B,0x82,0x6C,0x82,0x6D,0x82,0x6E,0x82,0x6F,0x82,0x70,0x82,0x71,0x82,0x72,0x82,0x73,0x82,0x74,0x82,0x75,0x82,0x76,0x82,0x77,0x82,0x78,0x82,0x79,0x81,0xE7,0x81,0xE8,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_9F4[14] = {0x53,0x6D,0x61,0x6C,0x6C,0x20,0x4C,0x65,0x74,0x74,0x65,0x72,0x73,0x00};
const u8 lbl_8_rodata_A04[60] = {0x82,0x81,0x82,0x82,0x82,0x83,0x82,0x84,0x82,0x85,0x82,0x86,0x82,0x87,0x82,0x88,0x82,0x89,0x82,0x8A,0x82,0x8B,0x82,0x8C,0x82,0x8D,0x82,0x8E,0x82,0x8F,0x82,0x90,0x82,0x91,0x82,0x92,0x82,0x93,0x82,0x94,0x82,0x95,0x82,0x96,0x82,0x97,0x82,0x98,0x82,0x99,0x82,0x9A,0x81,0xE7,0x81,0xE8,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_A40[6] = {0x53,0x69,0x67,0x6E,0x73,0x00};
const u8 lbl_8_rodata_A48[68] = {0x81,0x43,0x81,0x44,0x81,0x48,0x81,0x49,0x81,0x7B,0x81,0x7C,0x81,0x5E,0x81,0x5F,0x81,0x81,0x81,0x83,0x81,0x84,0x81,0x46,0x81,0x47,0x81,0x4C,0x81,0x4D,0x81,0x4F,0x81,0x51,0x81,0x62,0x81,0x69,0x81,0x6A,0x81,0x6D,0x81,0x6E,0x81,0x6F,0x81,0x70,0x81,0x90,0x81,0x93,0x81,0x94,0x81,0x95,0x81,0x96,0x81,0x97,0x81,0xE7,0x81,0xE8,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_A8C[8] = {0x4E,0x75,0x6D,0x62,0x65,0x72,0x73,0x00};
const u8 lbl_8_rodata_A94[100] = {0x82,0x4F,0x82,0x50,0x82,0x51,0x82,0x52,0x82,0x53,0x82,0x54,0x82,0x55,0x82,0x56,0x82,0x57,0x82,0x58,0x81,0xE7,0x81,0xE8,0x00,0x00,0x00,0x00,0x3F,0xCA,0xE1,0x47,0xAE,0x14,0x7A,0xE1,0x3F,0xFA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAB,0x3F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x42,0x40,0x00,0x00,0x3E,0x80,0x00,0x00,0x3F,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x05,0x1E,0xB8,0x00,0x00,0x00,0x00,0x3F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xD5,0x55,0x55,0x3D,0x80,0x00,0x00};
const u8 lbl_8_rodata_AF8[8] = {0x43,0x30,0x00,0x00,0x80,0x00,0x00,0x00};
const u8 lbl_8_rodata_B00[8] = {0x43,0x30,0x00,0x00,0x00,0x00,0x00,0x00};
const f32 lbl_8_rodata_B00__fzgx_offset_8[1] = {32.0f};
const f32 lbl_8_rodata_B00__fzgx_offset_C[1] = {24.0f};
const f32 lbl_8_rodata_B00__fzgx_offset_10[1] = {18.0f};
const u8 lbl_8_rodata_B00__fzgx_offset_14[76] = {0xFF,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0x41,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xC9,0x99,0x99,0x99,0x99,0x99,0x9A,0x40,0x28,0x00,0x00,0x00,0x00,0x00,0x00,0x41,0x21,0x99,0x9A,0x00,0x00,0x00,0x00,0x40,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x80,0x00,0x00,0x41,0x20,0x00,0x00};
extern s32 fn_1_45D0(u32, u32, u32, u32);
extern u32 fn_800793D4(u32, s32, u32);
extern void fn_1_435C(u32);
extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern void fn_1_47F74(s32);
extern void fn_1_411A4(u32);
extern void fn_1_A2D84(u32);
extern u32 fn_8_E440();
extern void fn_8_EFA4(void);
extern u32 fn_8_DD64();

typedef struct { u16 cleared; u16 code; const u8 *text[4]; } NameEntryOption;
NameEntryOption fzgx_obj_lbl_8_data_A1E8[4] __attribute__((aligned(8))) = {
    {0, 64, {lbl_8_rodata_410, lbl_8_rodata_494, 0, lbl_8_rodata_408}},
    {0, 38, {lbl_8_rodata_520, 0, 0, lbl_8_rodata_518}},
    {0, 85, {lbl_8_rodata_57C, lbl_8_rodata_628, lbl_8_rodata_6D4, lbl_8_rodata_570}},
    {0, 88, {lbl_8_rodata_78C, lbl_8_rodata_840, lbl_8_rodata_8F4, lbl_8_rodata_780}},
};
NameEntryOption lbl_8_data_A1E8__fzgx_offset_50[4] = {
    {0, 28, {lbl_8_rodata_9B8, 0, 0, lbl_8_rodata_9A8}},
    {0, 28, {lbl_8_rodata_A04, 0, 0, lbl_8_rodata_9F4}},
    {0, 32, {lbl_8_rodata_A48, 0, 0, lbl_8_rodata_A40}},
    {0, 12, {lbl_8_rodata_A94, 0, 0, lbl_8_rodata_A8C}},
};
u8 fzgx_obj_lbl_8_data_A288[64] = "name_entry.c\000\000\000\000\201@\000\000\201\347\000\000%s\201@\201@\201@%s\000\000\201\350\000"
    "\000name_entry_fixed_letter";
u8 fzgx_obj_lbl_8_data_A2C8[24] = "\226\274\221O\202\360\223\374\202\352\202\304\202\255\202\276\202\263\202\242\201B\000";
u8 fzgx_obj_lbl_8_data_A2E0[56] = "Please enter your name.  \000\000\000\203G\203t\203[\203\215\000\000\000\000\202e\201|\202y\202d"
    "\202q\202n\000\000\000";
u8 lbl_8_data_A2E0__fzgx_offset_38[16] = "name_entry_main";
u8 lbl_8_data_A2E0__fzgx_offset_48[24] = "name_entry_disp_main\000\000\000";
u8 lbl_8_data_A2E0__fzgx_offset_60[16] = "name_entry_line";
Obj *fzgx_obj_lbl_8_bss_550;
u8 fzgx_obj_lbl_8_bss_554;
u8 fzgx_obj_lbl_8_bss_555;
#pragma section code_type ".fzgxpool"
static void name_entry_data_layout(void) {
    const void *volatile sink; /* fzgx-allow: S2 discarded measured section-layout primer */
    sink = &fzgx_obj_lbl_8_data_A1E8;
    sink = &fzgx_obj_lbl_8_data_A288;
    sink = &fzgx_obj_lbl_8_data_A2C8;
    sink = &fzgx_obj_lbl_8_data_A2E0;
}
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void name_entry_rodata_layout(void) {
    const void *volatile sink; /* fzgx-allow: S2 discarded measured section-layout primer */
    sink = &lbl_8_rodata_408;
    sink = &lbl_8_rodata_410;
    sink = &lbl_8_rodata_494;
    sink = &lbl_8_rodata_518;
    sink = &lbl_8_rodata_520;
    sink = &lbl_8_rodata_570;
    sink = &lbl_8_rodata_57C;
    sink = &lbl_8_rodata_628;
    sink = &lbl_8_rodata_6D4;
    sink = &lbl_8_rodata_780;
    sink = &lbl_8_rodata_78C;
    sink = &lbl_8_rodata_840;
    sink = &lbl_8_rodata_8F4;
    sink = &lbl_8_rodata_9A8;
    sink = &lbl_8_rodata_9B8;
    sink = &lbl_8_rodata_9F4;
    sink = &lbl_8_rodata_A04;
    sink = &lbl_8_rodata_A40;
    sink = &lbl_8_rodata_A48;
    sink = &lbl_8_rodata_A8C;
    sink = &lbl_8_rodata_A94;
    sink = &lbl_8_rodata_AF8;
    sink = &lbl_8_rodata_B00;
    sink = &lbl_8_rodata_B00__fzgx_offset_8;
    sink = &lbl_8_rodata_B00__fzgx_offset_C;
    sink = &lbl_8_rodata_B00__fzgx_offset_10;
    sink = &lbl_8_rodata_B00__fzgx_offset_14;
}
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void name_entry_bss_layout(void) {
    const void *volatile sink; /* fzgx-allow: S2 discarded measured section-layout primer */
    sink = &fzgx_obj_lbl_8_bss_550;
    sink = &fzgx_obj_lbl_8_bss_554;
    sink = &fzgx_obj_lbl_8_bss_555;
}
#pragma section code_type ".text"

static inline void clear_name_entry_flag(void) {
    u16 *flag;
    u32 index = 0;
    flag = (u16 *)fzgx_obj_lbl_8_bss_550->unk_3c;
    while (index < fzgx_obj_lbl_8_bss_550->unk_3b) {
        *flag = 0;
        index++;
    }
}
#pragma opt_common_subs off
#pragma opt_loop_invariants off
#pragma opt_propagation off
#pragma opt_pointer_analysis off
#pragma opt_strength_reduction off

void fn_8_F9E4(u32 arg0, u32 arg1, u8 arg2) {
    Node *n;
    u32 i;

    fzgx_obj_lbl_8_bss_550 = (Obj *)fn_1_45D0(lbl_801A6410, 0x40, (u32)fzgx_obj_lbl_8_data_A288, 0x4ef);
    fn_800793D4((u32)fzgx_obj_lbl_8_bss_550, 0, 0x40);
    fzgx_obj_lbl_8_bss_550->unk_4 = arg0;
    fzgx_obj_lbl_8_bss_550->unk_8 = arg1;
    fn_1_435C(arg0);
    fzgx_obj_lbl_8_bss_550->unk_18 = fn_1_3F8C((u32)lbl_8_data_A2E0__fzgx_offset_38, (u32)&fn_8_E440, 0, 0xa);
    fn_1_47F74(0x8f);
    if (lbl_1_bss_960 != 1) {
        fn_1_47F74(0x9a);
        fn_1_47F74(0x9e);
        fn_1_411A4(1);
    }
    fn_1_435C(arg1);
    fzgx_obj_lbl_8_bss_550->unk_1c = fn_1_3F8C((u32)lbl_8_data_A2E0__fzgx_offset_48, (u32)&fn_8_EFA4, 0, 0xa);
    if (lbl_801A66B4 == 5) {
        fzgx_obj_lbl_8_bss_550->unk_3c = (u32)fzgx_obj_lbl_8_data_A1E8;
        fzgx_obj_lbl_8_bss_550->unk_3b = 4;
    } else {
        fzgx_obj_lbl_8_bss_550->unk_3c = (u32)lbl_8_data_A1E8__fzgx_offset_50;
        fzgx_obj_lbl_8_bss_550->unk_3b = 4;
    }
    for (i = 0; i < fzgx_obj_lbl_8_bss_550->unk_3b; i++) {
        n = (Node *)fn_1_45D0(lbl_801A6410, 0xc, (u32)fzgx_obj_lbl_8_data_A288, 0x1a5);
        fn_800793D4((u32)n, 0, 0xc);
        n->unk_0 = (u8)i;
        switch ((u8)i) {
        case 0:
            n->unk_4 = 0xb2;
            n->unk_8 = lbl_8_rodata_B00__fzgx_offset_8[0];
            break;
        case 1:
            n->unk_4 = 0x114;
            n->unk_8 = lbl_8_rodata_B00__fzgx_offset_C[0];
            break;
        case 2:
            n->unk_4 = 0x139;
            n->unk_8 = lbl_8_rodata_B00__fzgx_offset_10[0];
            break;
        case 3:
            n->unk_4 = 0x54;
            n->unk_8 = lbl_8_rodata_B00__fzgx_offset_C[0];
            break;
        }
        fn_1_3F8C((u32)lbl_8_data_A2E0__fzgx_offset_60, (u32)&fn_8_DD64, (u32)n, 0xb);
    }
    fzgx_obj_lbl_8_bss_550->unk_c = arg2;
    clear_name_entry_flag();
    fzgx_obj_lbl_8_bss_550->unk_12 = 0x62;
    fn_1_A2D84(0xa9100000);
    fzgx_obj_lbl_8_bss_554 = 0;
    fzgx_obj_lbl_8_bss_555 = 0;
}

#pragma opt_strength_reduction reset
#pragma opt_pointer_analysis reset
#pragma opt_propagation reset
#pragma opt_loop_invariants reset
#pragma opt_common_subs reset

#pragma opt_common_subs reset
#pragma opt_loop_invariants reset
#pragma opt_propagation reset
#pragma opt_pointer_analysis reset
#pragma opt_strength_reduction reset
/* fzgx:end fn_8_F9E4 */

/* fzgx:begin fn_8_FC5C */
#include "rel/title/operation.h"

extern u32 lbl_8_rodata_C24;
extern u32 lbl_8_rodata_C28;
extern s32 lbl_801A66B4;
extern struct fn_8_FC5C_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_435C(u32);
extern s32 fn_1_45D0(u32, u32, u8 *, u32);
extern s32 fn_1_3F8C(u8 *, u32, u32, u32);
extern void fn_1_A2D84(u32);
extern s32 fn_1_14CEB8(u32);
extern void fn_80083DB0(u8 *, u32);
extern void fn_8_D630(void);
struct fn_8_FC5C_lbl_801A6410 {
    u32 unk_0;
};
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    u16 unk_A;
    u8 unk_C;
    u8 pad_D[0x3];
    u32 unk_10;
} Entry_4_D420;
typedef struct { u32 v; } Word;

#pragma opt_loop_invariants off
#pragma opt_lifetimes off
s32 fn_8_FC5C(void) {
    s32 bit;
    u8 *src;
    s32 i;
    Obj_8_bss_550_Target *maskstate;
    struct { u8 value; } k;
    struct { s32 value; } n;
    s32 res;
    u8 *src2;
    u8 *data;
    Entry_4_D420 *t;
    Word c;
    Word c2;

    res = 0;
    data = lbl_8_data_A1E8;
    if ((lbl_8_bss_550->unk_0 >> 30) & 1) {
        c = *(Word *)&lbl_8_rodata_C28;
        fn_1_435C(lbl_8_bss_550->unk_8);
        n.value = 0;
        i = 0;
        while (src = (u8 *)lbl_8_bss_550 + 0x28 + i, src[0] != 0) {
            t = (Entry_4_D420 *)fn_1_45D0(lbl_801A6410.unk_0, 0x12, ((0xA0) + (data)), 0xD4);
            t->unk_8 = (u8)n.value * 0x38 + 0x7E;
            t->unk_A = 0x17A;
            t->unk_0 = 2;
            t->unk_1 = 0;
            t->unk_4 = t->unk_8;
            t->unk_6 = t->unk_A;
            t->unk_2 = src[0];
            t->unk_3 = src[1];
            *(u32 *)((u8 *)t + 0xD) = c.v;
            t->unk_C = n.value;
            fn_1_3F8C(data + 0xC8, (u32)&fn_8_D630, (u32)t, 0xB);
            i += 2;
            n.value += 1;
        }
        c2.v = lbl_8_bss_550->unk_0;
        /* Retail reloads the target pointer after reading its flags. */
        (*(Obj_8_bss_550_Target * volatile *)&lbl_8_bss_550)->unk_0 = c2.v & ~0x40000000;
    }
    if (lbl_8_bss_550->unk_0 >> 31) {
        return 1;
    }
    if (((lbl_8_bss_550->unk_0 >> 29) & 1) || ((lbl_8_bss_550->unk_0 >> 28) & 1)) {
        fn_1_A2D84(0xA9010100);
        lbl_8_bss_550->unk_0 &= ~0x20000000;
        lbl_8_bss_550->unk_0 &= ~0x10000000;
        lbl_8_bss_550->unk_0 |= 0x80000000;
        if (fn_1_14CEB8((u32)lbl_8_bss_550 + 0x28) != 0) {
            bit = 0;
            lbl_8_bss_550->unk_0 |= 0x40000000;
            while (((u8 *)lbl_8_bss_550)[0x28 + bit * 2] != 0) {
                lbl_8_bss_550->unk_20 |= 0x80000000 >> bit;
                bit++;
            }
        }
        if (((u8 *)lbl_8_bss_550)[0x28] == 0) {
            if (lbl_801A66B4 == 5) {
                fn_80083DB0((u8 *)lbl_8_bss_550 + 0x28, (u32)(data + 0x114));
            } else {
                fn_80083DB0((u8 *)lbl_8_bss_550 + 0x28, (u32)(data + 0x120));
            }
            c2 = *(Word *)&lbl_8_rodata_C24;
            fn_1_435C(lbl_8_bss_550->unk_8);
            n.value = 0;
            while (src2 = (u8 *)lbl_8_bss_550 + 0x28 + n.value * 2, src2[0] != 0) {
                k.value = n.value;
                t = (Entry_4_D420 *)fn_1_45D0(lbl_801A6410.unk_0, 0x12, ((0xA0) + (data)), 0xD4);
                t->unk_8 = k.value * 0x38 + 0x7E;
                t->unk_A = 0x17A;
                t->unk_0 = 2;
                t->unk_1 = 0;
                t->unk_4 = t->unk_8;
                t->unk_6 = t->unk_A;
                t->unk_2 = src2[0];
                t->unk_3 = src2[1];
                *(u32 *)((u8 *)t + 0xD) = c2.v;
                t->unk_C = k.value;
                fn_1_3F8C(data + 0xC8, (u32)&fn_8_D630, (u32)t, 0xB);
                n.value += 1;
            }
            lbl_8_bss_550->unk_E = n.value;
        }
        res = 1;
    }
    return res;
}
#pragma opt_lifetimes reset

#pragma opt_loop_invariants reset
/* fzgx:end fn_8_FC5C */
