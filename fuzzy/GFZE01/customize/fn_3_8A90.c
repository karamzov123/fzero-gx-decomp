/* Non-matching: best partial attempt (92.75% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u16 f_0;
    u8 pad_2[6];
    u16 f_8;
    u16 f_A;
    u8 pad_C[4];
    u16 f_10;
    u16 f_12;
} Entry;

typedef struct {
    s16 f_0;
    u8 pad_2[4];
    s16 f_6;
    s16 f_8;
    u8 pad_A[0x1A];
    u32 f_24;
} Sel;

typedef struct {
    u32 unk_0;
    u8 pad_4[0x16];
    u8 unk_1A;
    u8 unk_1B;
    u8 unk_1C;
    u8 pad_1D[3];
    u8 pad_20[0x18];
    s16 unk_38;
    u8 pad_3A[0xB6];
    u32 unk_F0;
    u8 pad_F4[2];
    s16 unk_F6;
    s16 unk_F8;
    u8 pad_FA[0x1A];
    u32 unk_114;
    u8 pad_118[8];
    s32 unk_120;
} Obj_3_bss_0;

typedef struct {
    u8 pad_0[4];
    f32 f_4;
    f32 f_8;
    u8 pad_C[8];
    f32 f_14;
    u8 pad_18[0x2C];
    f32 f_44;
    u32 f_48;
    f32 f_4C;
    f32 f_50;
    f32 f_54;
    u8 pad_58[4];
    f32 f_5C;
    f32 f_60;
    f32 f_64;
    f32 f_68;
    u8 pad_6C[4];
    f32 f_70;
    u8 pad_74[8];
    f32 f_7C;
    u8 pad_80[0x5C];
    f32 f_DC;
} Obj_3_rodata_0;

typedef struct {
    u8 pad_0[0xB4];
    u32 unk_B4;
    u8 pad_B8[0xA8];
    void *tab_160[0x32];
    void *tab_228[0x4D];
    void *tab_35C[0x2C9];
    char *tab_E80[77][6];
    u8 pad_15B8[0x14];
    char str_15CC[4];
} Obj_3_data_0;

extern Obj_3_bss_0 lbl_3_bss_0;
extern Obj_3_rodata_0 lbl_3_rodata_0;
extern Obj_3_data_0 lbl_3_data_0;
extern Entry lbl_1_bss_9F8[];
extern u32 lbl_3_bss_7EC04;
extern u16 lbl_1_bss_96A;
extern s32 lbl_801A66B4;
extern u32 lbl_3_bss_140;

extern void fn_1_A2D84(u32);
extern void fn_1_FDFF4(void);
extern void fn_1_1280(u32);
extern void fn_1_53BD8(void *, f32, f32, f32, f32, f32);
extern void fn_1_4AEC0(u32);
extern void fn_1_4AEB4(f32);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_4A0D8(const char *);
extern int fn_1_4C10(void);
extern s16 fn_3_83CC(void);
extern s32 fn_8008023C(u32, u32, u32);
extern void fn_1_FE5C4(s16, void *, void *, u32);
extern void fn_1_4A00(s32, u8, void *);
extern void fn_1_DCED0(void *);
extern void fn_3_B30(void *);
extern void fn_3_BFC(char *, void *, const char *, const char *);
extern void fn_3_E64(u8 *);
extern void fn_3_B984(void *, u8 *);

static inline BOOL sub_check(u8 *b2, void *dst) {
    return fn_8008023C((u32)(b2 + 0x43C0), (u32)dst, 0x81C0) != 0;
}

#pragma opt_propagation off
static inline void * *fn_3_8A90_array_read(void * *array) { return array; }
#pragma opt_lifetimes off
void fn_3_8A90(void) {
    u8 * lab_t1;
    void * lab_t1_;
    char * (* fzgx_live)[6];
    s16 crs;
    Obj_3_rodata_0 *ro;
    u8 *b2;
    u8 *b7;
    Obj_3_data_0 *data;
    Obj_3_bss_0 *bss;
    void *sp8;
    Sel *sp;
    s16 idx;
    s16 a;
    s32 r3v;
    u32 temp;
    char buf1[0x400];
    char buf2[0x400];
    char buf3[0x400];
    u32 u1;
    u32 u2;
    u32 u3;
    void *e2;

    bss = &lbl_3_bss_0;
    sp = (Sel *)&bss->unk_F0;
    lbl_3_bss_7EC04 = 1;
    sp8 = &sp->f_8;
    crs = sp->f_8;
    idx = sp->f_6;
    ro = &lbl_3_rodata_0;
    data = &lbl_3_data_0;
    b7 = (u8 *)bss + 0x70000;
    b2 = (u8 *)bss + 0x20000;

    if (bss->unk_1A) {
        if (lbl_1_bss_9F8[idx].f_10 & 1 || lbl_1_bss_9F8[idx].f_12 & 1) {
            *(u8 *)(b7 - 0x228C) = 0;
            fn_1_A2D84(0xA9011300);
        }
        if (lbl_1_bss_9F8[idx].f_10 & 2 || lbl_1_bss_9F8[idx].f_12 & 2) {
            *(u8 *)(b7 - 0x228C) = 1;
            fn_1_A2D84(0xA9011300);
        }
        if (lbl_1_bss_9F8[idx].f_8 & 0x200) {
            *(u8 *)(b7 - 0x228C) = 1;
        }
        if (lbl_1_bss_9F8[idx].f_8 & 0x100 || lbl_1_bss_9F8[idx].f_8 & 0x200) {
            if (*(u8 *)(b7 - 0x228C) == 0) {
                fn_1_A2D84(0xA9011100);
                fn_1_FDFF4();
                bss->unk_120 = 0x5D;
                fn_1_1280(1);
                temp = bss->unk_F0 | 0x40000000;
                *(void **)(b2 + 0x4374) = (void *)fn_3_B30;
                data->unk_B4 = 0x5F;
                *(void **)(b2 + 0x4378) = sp8;
                bss->unk_F0 = temp;
            } else {
                fn_1_A2D84(0xA9011000);
            }
            bss->unk_1A = 0;
        }
        u1 = ro->f_48;
        fn_1_53BD8(&u1, ro->f_4, ro->f_8, ro->f_4C, ro->f_50, ro->f_54);
        e2 = fn_3_8A90_array_read(data->tab_160)[lbl_801A66B4];
        fn_1_4AEC0(1);
        fn_1_4AEB4(ro->f_5C);
        fn_1_49410();
        fn_1_4955C(ro->f_7C, ro->f_7C);
        fn_1_4954C(ro->f_70);
        fn_1_495C8(9);
        fn_1_496FC(ro->f_4, ro->f_DC);
        fn_1_4966C(ro->f_60, ro->f_64);
        if (lbl_801A66B4 != 5) {
            fn_1_495B0(0x80000000);
            fn_1_49590(ro->f_14);
            fn_1_4966C(ro->f_60, ro->f_68);
        }
        fzgx_live = data->tab_E80;
        fn_3_BFC(buf1, e2, data->str_15CC, fzgx_live[*(u8 *)(b2 + 0x437C)][lbl_801A66B4]);
        fzgx_live = data->tab_E80;
        fn_3_BFC(buf1, buf1, data->str_15CC, fzgx_live[*(u8 *)(b2 + 0x437C)][lbl_801A66B4]);
        fzgx_live = data->tab_E80;
        fn_3_BFC(buf1, buf1, data->str_15CC, fzgx_live[*(u8 *)(b2 + 0x437C)][lbl_801A66B4]);
        fn_1_4A0D8(buf1);
        fn_1_4AEC0(0);
        fn_1_4AEB4(ro->f_44);
        fn_3_E64(b7 - 0x228C);
    } else if (bss->unk_1B) {
        if (lbl_1_bss_9F8[idx].f_10 & 1 || lbl_1_bss_9F8[idx].f_12 & 1) {
            *(u8 *)(b7 - 0x228C) = 0;
            fn_1_A2D84(0xA9011300);
        }
        if (lbl_1_bss_9F8[idx].f_10 & 2 || lbl_1_bss_9F8[idx].f_12 & 2) {
            *(u8 *)(b7 - 0x228C) = 1;
            fn_1_A2D84(0xA9011300);
        }
        if (lbl_1_bss_9F8[idx].f_8 & 0x200) {
            *(u8 *)(b7 - 0x228C) = 1;
        }
        if (lbl_1_bss_9F8[idx].f_8 & 0x100 || lbl_1_bss_9F8[idx].f_8 & 0x200) {
            if (*(u8 *)(b7 - 0x228C) == 0) {
                bss->unk_0 = 1;
                bss->unk_120 = 0x5D;
                fn_1_1280(1);
                temp = bss->unk_F0 | 0x40000000;
                *(void **)(b2 + 0x4374) = (void *)fn_3_B30;
                data->unk_B4 = 0x5F;
                *(void **)(b2 + 0x4378) = sp8;
                bss->unk_F0 = temp;
                fn_1_FDFF4();
                lab_t1 = (u8 *)(b2 + 0x43C0);
                fn_3_B984((void *)((u8 *)&lbl_3_bss_140 + (crs * 0x81C0)), lab_t1);
                fn_1_A2D84(0xA9011100);
            } else {
                fn_1_A2D84(0xA9011000);
            }
            bss->unk_1B = 0;
        }
        u2 = ro->f_48;
        fn_1_53BD8(&u2, ro->f_4, ro->f_8, ro->f_4C, ro->f_50, ro->f_54);
        e2 = fn_3_8A90_array_read(data->tab_228)[lbl_801A66B4];
        fn_1_4AEC0(1);
        fn_1_4AEB4(ro->f_5C);
        fn_1_49410();
        fn_1_4955C(ro->f_7C, ro->f_7C);
        fn_1_4954C(ro->f_70);
        fn_1_495C8(9);
        fn_1_496FC(ro->f_4, ro->f_DC);
        fn_1_4966C(ro->f_60, ro->f_64);
        if (lbl_801A66B4 != 5) {
            fn_1_495B0(0x80000000);
            fn_1_49590(ro->f_14);
            fn_1_4966C(ro->f_60, ro->f_68);
        }
        fzgx_live = data->tab_E80;
        fn_3_BFC(buf2, e2, data->str_15CC, fzgx_live[*(u8 *)(b2 + 0x437C)][lbl_801A66B4]);
        fzgx_live = data->tab_E80;
        fn_3_BFC(buf2, buf2, data->str_15CC, fzgx_live[*(u8 *)(b2 + 0x437C)][lbl_801A66B4]);
        fzgx_live = data->tab_E80;
        fn_3_BFC(buf2, buf2, data->str_15CC, fzgx_live[*(u8 *)(b2 + 0x437C)][lbl_801A66B4]);
        fn_1_4A0D8(buf2);
        fn_1_4AEC0(0);
        fn_1_4AEB4(ro->f_44);
        fn_3_E64(b7 - 0x228C);
    } else if (bss->unk_1C) {
        if (lbl_1_bss_9F8[idx].f_10 & 1 || lbl_1_bss_9F8[idx].f_12 & 1) {
            *(u8 *)(b7 - 0x228C) = 0;
            fn_1_A2D84(0xA9011300);
        }
        if (lbl_1_bss_9F8[idx].f_10 & 2 || lbl_1_bss_9F8[idx].f_12 & 2) {
            *(u8 *)(b7 - 0x228C) = 1;
            fn_1_A2D84(0xA9011300);
        }
        if (lbl_1_bss_9F8[idx].f_8 & 0x200) {
            *(u8 *)(b7 - 0x228C) = 1;
        }
        if (lbl_1_bss_9F8[idx].f_8 & 0x100 || lbl_1_bss_9F8[idx].f_8 & 0x200) {
            if (*(u8 *)(b7 - 0x228C) == 0) {
                bss->unk_0 = 1;
                bss->unk_120 = 0x5D;
                fn_1_1280(1);
                temp = bss->unk_F0 | 0x40000000;
                *(void **)(b2 + 0x4374) = (void *)fn_3_B30;
                data->unk_B4 = 0x6B;
                *(void **)(b2 + 0x4378) = sp8;
                bss->unk_F0 = temp;
                fn_1_FDFF4();
                lab_t1 = (u8 *)(b2 + 0x43C0);
                fn_3_B984((void *)((u8 *)&lbl_3_bss_140 + (crs * 0x81C0)), lab_t1);
                fn_1_A2D84(0xA9011100);
            } else {
                fn_1_A2D84(0xA9011000);
            }
            bss->unk_1C = 0;
        }
        u3 = ro->f_48;
        fn_1_53BD8(&u3, ro->f_4, ro->f_8, ro->f_4C, ro->f_50, ro->f_54);
        e2 = fn_3_8A90_array_read(data->tab_35C)[lbl_801A66B4];
        fn_1_4AEC0(1);
        fn_1_4AEB4(ro->f_5C);
        fn_1_49410();
        fn_1_4955C(ro->f_7C, ro->f_7C);
        fn_1_4954C(ro->f_70);
        fn_1_495C8(9);
        fn_1_496FC(ro->f_4, ro->f_DC);
        fn_1_4966C(ro->f_60, ro->f_64);
        if (lbl_801A66B4 != 5) {
            fn_1_495B0(0x80000000);
            fn_1_49590(ro->f_14);
            fn_1_4966C(ro->f_60, ro->f_68);
        }
        fzgx_live = data->tab_E80;
        fn_3_BFC(buf3, e2, data->str_15CC, fzgx_live[*(u8 *)(b2 + 0x437C)][lbl_801A66B4]);
        fzgx_live = data->tab_E80;
        fn_3_BFC(buf3, buf3, data->str_15CC, fzgx_live[*(u8 *)(b2 + 0x437C)][lbl_801A66B4]);
        fzgx_live = data->tab_E80;
        fn_3_BFC(buf3, buf3, data->str_15CC, fzgx_live[*(u8 *)(b2 + 0x437C)][lbl_801A66B4]);
        fn_1_4A0D8(buf3);
        fn_1_4AEC0(0);
        fn_1_4AEB4(ro->f_44);
        fn_3_E64(b7 - 0x228C);
    } else {
        lbl_3_bss_7EC04 = 0;
        if (bss->unk_120 == -1) {
            fn_1_4C10();
        }
        if ((sp->f_24 & 0x80000000) && !(sp->f_24 & 1) && !(bss->unk_F0 & 2)) {
            r3v = 1;
        } else {
            r3v = fn_1_4C10() != 0;
        }
        if (r3v) {
            return;
        }
        if (bss->unk_120 != -1) {
            lbl_1_bss_96A = bss->unk_120;
            bss->unk_120 = -1;
            return;
        }
        fn_1_DCED0(b7 - 0x2288);
        a = fn_3_83CC();
        if (a == 13) {
            if (sub_check(b2, (u8 *)&lbl_3_bss_140 + (crs * 0x81C0)) == 1) {
                *(u8 *)(b7 - 0x228C) = 1;
                bss->unk_1A = 1;
            } else {
                bss->unk_120 = 0x5F;
                fn_1_1280(1);
            }
            return;
        }
        if (a == 12 && sub_check(b2, (u8 *)&lbl_3_bss_140 + (crs * 0x81C0)) == 1) {
            *(u8 *)(b7 - 0x228C) = 1;
            bss->unk_1C = 1;
            return;
        }
        if (a == 11) {
            if (sub_check(b2, (u8 *)&lbl_3_bss_140 + (crs * 0x81C0)) == 1) {
                *(u8 *)(b7 - 0x228C) = 1;
                bss->unk_1B = 1;
            } else {
                bss->unk_120 = 0x5F;
                fn_1_1280(1);
            }
            return;
        }
        if (bss->unk_38 < 3) {
            if (lbl_1_bss_9F8[sp->f_6].f_0 & 0x400) {
                lab_t1_ = b7 - 0x21E0;
                fn_1_FE5C4(bss->unk_38, lab_t1_, (u8 *)bss + 0x20, 1);
            } else {
                lab_t1_ = b7 - 0x21E0;
                fn_1_FE5C4(bss->unk_38, lab_t1_, (u8 *)bss + 0x20, 0);
            }
        }
        if (a == -1) {
            u8 *dst = (u8 *)&lbl_3_bss_140 + (crs * 0x81C0);
            if (sub_check(b2, dst) == 1) {
                fn_3_B984(dst, (lab_t1 = b2 + 0x43C0));
                bss->unk_0 = 1;
            }
            fn_1_FDFF4();
            bss->unk_120 = 0x5D;
            fn_1_1280(1);
            temp = bss->unk_F0 | 0x40000000;
            *(void **)(b2 + 0x4374) = (void *)fn_3_B30;
            data->unk_B4 = 0x5F;
            *(void **)(b2 + 0x4378) = sp8;
            bss->unk_F0 = temp;
        } else {
            switch (a) {
            case 7:
                if (sub_check(b2, (u8 *)&lbl_3_bss_140 + (crs * 0x81C0)) == 1) {
                    bss->unk_0 = 1;
                }
                bss->unk_120 = 0x5D;
                fn_1_1280(1);
                temp = bss->unk_F0 | 0x40000000;
                *(void **)(b2 + 0x4374) = (void *)fn_3_B30;
                data->unk_B4 = 0x6B;
                *(void **)(b2 + 0x4378) = sp8;
                bss->unk_F0 = temp;
                fn_1_FDFF4();
                break;
            case 9:
                bss->unk_120 = 0x6B;
                fn_1_FDFF4();
                fn_1_4A00(0, 0xF, *(void **)(b2 + 0x850));
                *(u32 *)(b2 + 0x43A8) = 0;
                break;
            case 8:
                bss->unk_120 = 0x6C;
                fn_1_FDFF4();
                fn_1_4A00(0, 0xF, *(void **)(b2 + 0x850));
                *(u32 *)(b2 + 0x43A8) = 0;
                break;
            case 10:
                bss->unk_120 = 0x6A;
                fn_1_FDFF4();
                fn_1_4A00(0, 0xF, *(void **)(b2 + 0x850));
                *(u32 *)(b2 + 0x43A8) = 0;
                break;
            }
        }
    }
}
#pragma opt_lifetimes reset

#pragma opt_propagation reset

