/* Non-matching: best partial attempt (76.07% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    s16 index;
} Sig_fn_3_B30_Fn3B30Data;

typedef struct Sig_fn_1_DCED0_Vec3 {
    u32 x;
    u32 y;
    u32 z;
} Sig_fn_1_DCED0_Vec3;

typedef struct Sig_fn_1_DCED0_BgForObject {
    Sig_fn_1_DCED0_Vec3 value00;
    Sig_fn_1_DCED0_Vec3 value0c;
    u8 unk18[0xc];
    u32 value24;
    u8 unk28[0x8];
    f32 value30;
    f32 value34;
    f32 value38;
    f32 value3c;
    u8 unk40[0x30];
    u8 unk70[1];
} Sig_fn_1_DCED0_BgForObject;

typedef struct {
    u32 unk_0;
    u8 pad_4[0x2];
    s16 idx;
    s16 idx2;
    u8 pad_A[0x1A];
    u32 unk_24;
} Sub0;

typedef struct {
    u32 unk_0;
    u8 pad_4[0x16];
    u8 flag1;
    u8 flag2;
    u8 flag3;
    u8 pad_1D[0xD3];
    Sub0 sub;
    u8 pad_118[0x8];
    s32 unk_120;
    u8 pad_124[0x2072C];
    u8 pad_20850[4];
    u8 pad_20854[0x3B20];
    u8 pad_24374[0x8];
    u8 sel;
    u8 pad_2437D[0x499B7];
    u8 pad_6DD75[0x3];
} Obj0;

typedef struct {
    u8 pad_0[0xB4];
    u32 unk_B4;
    u8 pad_B8[0xA8];
    u8 pad_160[0x146C];
    char *unk_15CC;
} Data0;

typedef struct {
    u8 pad_0[0x4];
    f32 unk_4;
    f32 unk_8;
    u8 pad_C[0x8];
    f32 unk_14;
    u8 pad_18[0x2C];
    f32 unk_44;
    u32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    f32 unk_54;
    u8 pad_58[0x4];
    f32 unk_5C;
    f32 unk_60;
    f32 unk_64;
    f32 unk_68;
    u8 pad_6C[0x4];
    f32 unk_70;
    u8 pad_74[0x8];
    f32 unk_7C;
    u8 pad_80[0x5C];
    f32 unk_DC;
} Rodata0;

extern Obj0 lbl_3_bss_0;
extern Data0 lbl_3_data_0;
extern Rodata0 lbl_3_rodata_0;
extern u8 lbl_1_bss_9F8[];
extern u8 lbl_3_bss_140[];
extern s32 lbl_801A66B4;
extern u16 lbl_1_bss_96A;

extern s32 fn_3_B30(Sig_fn_3_B30_Fn3B30Data *);
extern void fn_3_BFC(char *, void *, const char *, const char *);
extern void fn_3_E64(u8 *);
extern s32 fn_3_9CA8(void);
extern void fn_1_A2D84(u32);
extern void fn_1_1280(u32);
extern void fn_1_FDFF4(void);
extern void fn_1_53BD8(void *, f32, f32, f32, f32, f32);
extern u32 fn_1_4AEC0(u32);
extern void fn_1_4AEB4(f32);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_4A0D8(const char *);
extern int fn_1_4C10(void);
extern void fn_1_DCED0(Sig_fn_1_DCED0_BgForObject *);
extern u32 fn_8008023C(u32, u32, u32);
extern void fn_1_4A00(s32, u8, void *);

void fn_3_A12C(void) {
    u32 loc_8;
    u32 loc_C;
    u32 loc_10;
    char buf3[0x400];
    char buf2[0x400];
    char buf1[0x400];
    s16 *p_idx2;
    s16 idx2;
    Obj0 *b;
    Rodata0 *ro;
    Data0 *dt;
    u8 *fb;
    u32 *hb;
    Sub0 *p;
    s16 idx;
    s32 sel;

    b = &lbl_3_bss_0;
    p = &b->sub;
    idx2 = p->idx2;
    idx = p->idx;
    p_idx2 = &p->idx2;
    ro = &lbl_3_rodata_0;
    dt = &lbl_3_data_0;
    fb = (u8 *)b + 0x70000;
    hb = (u32 *)((u8 *)b + 0x20000);

    if (b->flag1) {
        s32 off = idx * 0x14;
        u16 *p1 = (u16 *)((u8 *)&lbl_1_bss_9F8 + off + 0x10);
        u16 *p2;
        u32 vv;

        if ((*p1 & 1) || (*(u16 *)((u8 *)&lbl_1_bss_9F8 + off + 0x12) & 1)) {
            *(fb - 0x228C) = 0;
            fn_1_A2D84(0xA9011300);
        }
        if ((*p1 & 2) || (*(u16 *)((u8 *)&lbl_1_bss_9F8 + off + 0x12) & 2)) {
            *(fb - 0x228C) = 1;
            fn_1_A2D84(0xA9011300);
        }
        p2 = (u16 *)((u8 *)&lbl_1_bss_9F8 + off + 8);
        if (*p2 & 0x200) {
            *(fb - 0x228C) = 1;
        }
        if ((*p2 & 0x100) || (*p2 & 0x200)) {
            if (*(fb - 0x228C) == 0) {
                b->unk_120 = 93;
                fn_1_1280(1);
                fn_1_FDFF4();
                dt->unk_B4 = 95;
                hb[0x10DD] = (u32)fn_3_B30;
                hb[0x10DE] = (u32)p_idx2;
                p->unk_0 |= 0x20000000;
                fn_1_FDFF4();
                fn_1_A2D84(0xA9011100);
            } else {
                fn_1_A2D84(0xA9011000);
            }
            b->flag1 = 0;
        }
        loc_10 = ro->unk_48;
        fn_1_53BD8(&loc_10, ro->unk_4, ro->unk_8, ro->unk_4C, ro->unk_50, ro->unk_54);
        vv = *(u32 *)((u8 *)dt + 0x160 + (lbl_801A66B4 << 2));
        fn_1_4AEC0(1);
        fn_1_4AEB4(ro->unk_5C);
        fn_1_49410();
        fn_1_4955C(ro->unk_7C, ro->unk_7C);
        fn_1_4954C(ro->unk_70);
        fn_1_495C8(9);
        fn_1_496FC(ro->unk_4, ro->unk_DC);
        fn_1_4966C(ro->unk_60, ro->unk_64);
        if (lbl_801A66B4 != 5) {
            fn_1_495B0(0x80000000);
            fn_1_49590(ro->unk_14);
            fn_1_4966C(ro->unk_60, ro->unk_68);
        }
        fn_3_BFC(buf1, (void *)vv, dt->unk_15CC,
            (const char *)(*(u32 *)((u8 *)dt + 0xE80 + b->sel * 0x18 + (lbl_801A66B4 << 2))));
        fn_3_BFC(buf1, buf1, dt->unk_15CC,
            (const char *)(*(u32 *)((u8 *)dt + 0xE80 + b->sel * 0x18 + (lbl_801A66B4 << 2))));
        fn_3_BFC(buf1, buf1, dt->unk_15CC,
            (const char *)(*(u32 *)((u8 *)dt + 0xE80 + b->sel * 0x18 + (lbl_801A66B4 << 2))));
        fn_1_4A0D8(buf1);
        fn_1_4AEC0(0);
        fn_1_4AEB4(ro->unk_44);
        fn_3_E64(fb - 0x228C);
    } else if (b->flag2) {
        s32 off = idx * 0x14;
        u16 *p1 = (u16 *)((u8 *)&lbl_1_bss_9F8 + off + 0x10);
        u16 *p2;
        u32 vv;

        if ((*p1 & 1) || (*(u16 *)((u8 *)&lbl_1_bss_9F8 + off + 0x12) & 1)) {
            *(fb - 0x228C) = 0;
            fn_1_A2D84(0xA9011300);
        }
        if ((*p1 & 2) || (*(u16 *)((u8 *)&lbl_1_bss_9F8 + off + 0x12) & 2)) {
            *(fb - 0x228C) = 1;
            fn_1_A2D84(0xA9011300);
        }
        p2 = (u16 *)((u8 *)&lbl_1_bss_9F8 + off + 8);
        if (*p2 & 0x200) {
            *(fb - 0x228C) = 1;
        }
        if ((*p2 & 0x100) || (*p2 & 0x200)) {
            if (*(fb - 0x228C) == 0) {
                b->unk_0 = 1;
                b->unk_120 = 93;
                fn_1_1280(1);
                fn_1_FDFF4();
                dt->unk_B4 = 95;
                hb[0x10DD] = (u32)fn_3_B30;
                hb[0x10DE] = (u32)p_idx2;
                p->unk_0 |= 0x20000000;
                fn_1_FDFF4();
                fn_1_A2D84(0xA9011100);
            } else {
                fn_1_A2D84(0xA9011000);
            }
            b->flag2 = 0;
        }
        loc_C = ro->unk_48;
        fn_1_53BD8(&loc_C, ro->unk_4, ro->unk_8, ro->unk_4C, ro->unk_50, ro->unk_54);
        vv = *(u32 *)((u8 *)dt + 0x2E4 + (lbl_801A66B4 << 2));
        fn_1_4AEC0(1);
        fn_1_4AEB4(ro->unk_5C);
        fn_1_49410();
        fn_1_4955C(ro->unk_7C, ro->unk_7C);
        fn_1_4954C(ro->unk_70);
        fn_1_495C8(9);
        fn_1_496FC(ro->unk_4, ro->unk_DC);
        fn_1_4966C(ro->unk_60, ro->unk_64);
        if (lbl_801A66B4 != 5) {
            fn_1_495B0(0x80000000);
            fn_1_49590(ro->unk_14);
            fn_1_4966C(ro->unk_60, ro->unk_68);
        }
        fn_3_BFC(buf2, (void *)vv, dt->unk_15CC,
            (const char *)(*(u32 *)((u8 *)dt + 0xE80 + b->sel * 0x18 + (lbl_801A66B4 << 2))));
        fn_3_BFC(buf2, buf2, dt->unk_15CC,
            (const char *)(*(u32 *)((u8 *)dt + 0xE80 + b->sel * 0x18 + (lbl_801A66B4 << 2))));
        fn_3_BFC(buf2, buf2, dt->unk_15CC,
            (const char *)(*(u32 *)((u8 *)dt + 0xE80 + b->sel * 0x18 + (lbl_801A66B4 << 2))));
        fn_1_4A0D8(buf2);
        fn_1_4AEC0(0);
        fn_1_4AEB4(ro->unk_44);
        fn_3_E64(fb - 0x228C);
    } else if (b->flag3) {
        s32 off = idx * 0x14;
        u16 *p1 = (u16 *)((u8 *)&lbl_1_bss_9F8 + off + 0x10);
        u16 *p2;
        u32 vv;

        if ((*p1 & 1) || (*(u16 *)((u8 *)&lbl_1_bss_9F8 + off + 0x12) & 1)) {
            *(fb - 0x228C) = 0;
            fn_1_A2D84(0xA9011300);
        }
        if ((*p1 & 2) || (*(u16 *)((u8 *)&lbl_1_bss_9F8 + off + 0x12) & 2)) {
            *(fb - 0x228C) = 1;
            fn_1_A2D84(0xA9011300);
        }
        p2 = (u16 *)((u8 *)&lbl_1_bss_9F8 + off + 8);
        if (*p2 & 0x200) {
            *(fb - 0x228C) = 1;
        }
        if ((*p2 & 0x100) || (*p2 & 0x200)) {
            if (*(fb - 0x228C) == 0) {
                b->unk_0 = 1;
                b->unk_120 = 93;
                fn_1_1280(1);
                fn_1_FDFF4();
                dt->unk_B4 = 108;
                hb[0x10DD] = (u32)fn_3_B30;
                hb[0x10DE] = (u32)p_idx2;
                p->unk_0 |= 0x20000000;
                fn_1_A2D84(0xA9011100);
            } else {
                fn_1_A2D84(0xA9011000);
            }
            b->flag3 = 0;
        }
        loc_8 = ro->unk_48;
        fn_1_53BD8(&loc_8, ro->unk_4, ro->unk_8, ro->unk_4C, ro->unk_50, ro->unk_54);
        vv = *(u32 *)((u8 *)dt + 0x35C + (lbl_801A66B4 << 2));
        fn_1_4AEC0(1);
        fn_1_4AEB4(ro->unk_5C);
        fn_1_49410();
        fn_1_4955C(ro->unk_7C, ro->unk_7C);
        fn_1_4954C(ro->unk_70);
        fn_1_495C8(9);
        fn_1_496FC(ro->unk_4, ro->unk_DC);
        fn_1_4966C(ro->unk_60, ro->unk_64);
        if (lbl_801A66B4 != 5) {
            fn_1_495B0(0x80000000);
            fn_1_49590(ro->unk_14);
            fn_1_4966C(ro->unk_60, ro->unk_68);
        }
        fn_3_BFC(buf3, (void *)vv, dt->unk_15CC,
            (const char *)(*(u32 *)((u8 *)dt + 0xE80 + b->sel * 0x18 + (lbl_801A66B4 << 2))));
        fn_3_BFC(buf3, buf3, dt->unk_15CC,
            (const char *)(*(u32 *)((u8 *)dt + 0xE80 + b->sel * 0x18 + (lbl_801A66B4 << 2))));
        fn_3_BFC(buf3, buf3, dt->unk_15CC,
            (const char *)(*(u32 *)((u8 *)dt + 0xE80 + b->sel * 0x18 + (lbl_801A66B4 << 2))));
        fn_1_4A0D8(buf3);
        fn_1_4AEC0(0);
        fn_1_4AEB4(ro->unk_44);
        fn_3_E64(fb - 0x228C);
    } else {
        u32 v;
        int cond;

        if (b->unk_120 == -1) {
            fn_1_4C10();
        }
        v = p->unk_24;
        cond = ((v & 0x80000000) && !(v & 1) && !(p->unk_0 & 2)) || fn_1_4C10();
        if (cond) {
            return;
        }
        if (b->unk_120 != -1) {
            lbl_1_bss_96A = b->unk_120;
            b->unk_120 = -1;
            return;
        }
        fn_1_DCED0((Sig_fn_1_DCED0_BgForObject *)(fb - 0x2288));
        sel = fn_3_9CA8();
        if (sel == 13) {
            if (fn_8008023C((u32)((u8 *)hb + 0x43C0),
                    (u32)((u8 *)lbl_3_bss_140 + idx2 * 0x81C0), 0x81C0) != 0) {
                *(fb - 0x228C) = 1;
                b->flag1 = 1;
            } else {
                b->unk_120 = 95;
                fn_1_1280(1);
            }
        } else if (sel == 12 && fn_8008023C((u32)((u8 *)hb + 0x43C0),
                    (u32)((u8 *)lbl_3_bss_140 + idx2 * 0x81C0), 0x81C0) != 0) {
            *(fb - 0x228C) = 1;
            b->flag3 = 1;
        } else if (sel == 11) {
            if (fn_8008023C((u32)((u8 *)hb + 0x43C0),
                    (u32)((u8 *)lbl_3_bss_140 + idx2 * 0x81C0), 0x81C0) != 0) {
                *(fb - 0x228C) = 1;
                b->flag2 = 1;
            } else {
                b->unk_120 = 95;
                fn_1_1280(1);
            }
        } else if (sel == -1) {
            if (fn_8008023C((u32)((u8 *)hb + 0x43C0),
                    (u32)((u8 *)lbl_3_bss_140 + idx2 * 0x81C0), 0x81C0) != 0) {
                b->unk_0 = 1;
            }
            fn_1_FDFF4();
            b->unk_120 = 93;
            fn_1_1280(1);
            dt->unk_B4 = 95;
            hb[0x10DD] = (u32)fn_3_B30;
            hb[0x10DE] = (u32)p_idx2;
            p->unk_0 |= 0x20000000;
        } else {
            switch (sel) {
            case 7:
                if (fn_8008023C((u32)((u8 *)hb + 0x43C0),
                        (u32)((u8 *)lbl_3_bss_140 + idx2 * 0x81C0), 0x81C0) != 0) {
                    b->unk_0 = 1;
                }
                b->unk_120 = 93;
                fn_1_1280(1);
                fn_1_FDFF4();
                dt->unk_B4 = 108;
                hb[0x10DD] = (u32)fn_3_B30;
                hb[0x10DE] = (u32)p_idx2;
                p->unk_0 |= 0x20000000;
                break;
            case 9:
                b->unk_120 = 107;
                fn_1_FDFF4();
                fn_1_4A00(0, 15, (void *)hb[0x214]);
                hb[0x10EA] = 0;
                break;
            case 8:
                b->unk_120 = 108;
                fn_1_FDFF4();
                fn_1_4A00(0, 15, (void *)hb[0x214]);
                hb[0x10EA] = 0;
                break;
            }
        }
    }
}
