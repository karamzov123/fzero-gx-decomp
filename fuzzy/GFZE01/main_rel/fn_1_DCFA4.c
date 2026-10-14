/* Non-matching: best partial attempt (74.12% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"

extern f32 fabsf(f32);

typedef struct Sig_fn_8006EE70_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Sig_fn_8006EE70_Vec3;

typedef struct DCFA4_Pool {
    u8 pad_0[0x18];
    f64 unk_18;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    u32 unk_2C;
} DCFA4_Pool;

typedef struct DCFA4_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} DCFA4_Vec3;

typedef struct DCFA4_Pair {
    f32 x;
    f32 y;
    f32 z;
} DCFA4_Pair;

typedef struct DCFA4_Mtx {
    f32 a[12];
} DCFA4_Mtx;

typedef struct DCFA4_Rot {
    s16 a[4];
} DCFA4_Rot;

typedef struct DCFA4_U32 {
    u32 a[3];
} DCFA4_U32;

typedef struct DCFA4_Obj {
    u8 pad_0[0x44];
    u8 unk_44[0xC];
    f32 unk_50;
    DCFA4_Vec3 unk_54;
    u8 pad_60[0x34];
    DCFA4_Mtx unk_94;
    u8 unk_c4[0x74];
    u32 unk_138;
    u32 unk_13C;
    u32 unk_140;
    u32 unk_144;
} DCFA4_Obj;

typedef struct DCFA4_Node {
    u8 pad_0[0x94];
    u8 unk_94[0xE8];
    f32 unk_17C;
} DCFA4_Node;

typedef struct DCFA4_L3 {
    u8 pad_0[0x38];
    void *v;
} DCFA4_L3;
typedef struct DCFA4_L2 {
    u32 pad_0[2];
    DCFA4_L3 *v;
} DCFA4_L2;
typedef struct DCFA4_L1 {
    DCFA4_L2 *v;
} DCFA4_L1;

extern DCFA4_Pool lbl_1_rodata_6780;
extern DCFA4_L1 lbl_1_bss_38454;

extern void fn_1_57714(u8);
extern u32 fn_1_57810(u32, u32, void *);
extern u32 fn_1_DDF80(u32, u32, u8 *, void *, f32, f32);
extern void fn_1_56298(f32, f32, f32, f32);
extern void fn_1_556B8(void *);
extern void fn_80008BA8(u8 *, u32, u32);
extern void lbl_8006D758(void);
extern u32 lbl_8006E1B0(void *, void *);
extern u32 lbl_8006DCA4(void);
extern void fn_80072558(void);
extern u32 lbl_8006D784(u32);
extern u32 lbl_8006DBAC(u32);
extern u32 lbl_8006DFE8(u32);
extern void lbl_8006DAEC(void);
extern f32 lbl_8006D0B4(f32);
extern void fn_8006EE70(const Sig_fn_8006EE70_Vec3 *, s16 *);
extern u32 mathutil_mtxA_rotate_z(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_x(u32);
extern void lbl_8006E15C(f32, f32, f32);
extern void lbl_8006DB30(void);

void fn_1_DCFA4(DCFA4_Obj *arg0) {
    DCFA4_Mtx loc_C8;
    DCFA4_Mtx loc_98;
    DCFA4_U32 loc_8C;
    DCFA4_U32 loc_80;
    DCFA4_Pair loc_74;
    DCFA4_Vec3 loc_68;
    DCFA4_Pair loc_5C;
    DCFA4_Vec3 loc_50;
    DCFA4_Vec3 loc_44;
    DCFA4_Vec3 loc_38;
    DCFA4_Vec3 loc_2C;
    DCFA4_Rot loc_24;
    DCFA4_Rot loc_1C;
    DCFA4_Rot loc_14;
    DCFA4_Rot loc_C;
    u32 loc_8;
    u32 z;
    f32 v5;
    f32 v8;
    f32 v9;
    f32 v10;
    f32 v15;
    f32 scale;
    DCFA4_Node *v19;

    z = 0;
    if (arg0->unk_144 == 0) {
        return;
    }
    if ((((arg0->unk_13C & 0x20000000) ^ z) | ((arg0->unk_138 & z) ^ z)) != 0) {
        fn_80008BA8((u8 *)&loc_74, arg0->unk_144 + 0x54, 0xC);
    } else if ((((arg0->unk_13C & 0x80000000) ^ z) | ((arg0->unk_138 & z) ^ z)) != 0) {
        fn_80008BA8((u8 *)&loc_74, arg0->unk_144 + 0x7C, 0xC);
    } else {
        return;
    }

    fn_1_57714(0x14);
    lbl_8006D758();
    lbl_8006E1B0(&arg0->unk_54, &loc_80);
    lbl_8006E1B0(&loc_74, &loc_8C);
    lbl_8006DCA4();
    fn_80072558();
    loc_8 = lbl_1_rodata_6780.unk_2C;
    fn_1_57810(2, (u32)&loc_80, &loc_8);

    psvec_sub(&loc_74, &arg0->unk_54, &loc_68);
    lbl_8006D784((u32)&loc_C8);
    lbl_8006DBAC((u32)&arg0->unk_c4);
    loc_C8.a[3] = *(f32 *)(0xE0000000 + 0x0C);
    loc_C8.a[7] = *(f32 *)(0xE0000000 + 0x1C);
    loc_C8.a[11] = *(f32 *)(0xE0000000 + 0x2C);
    lbl_8006DFE8((u32)&loc_C8);
    v5 = arg0->unk_50;
    fn_1_DDF80((u32)&arg0->unk_44[0], (u32)&loc_68, (u8 *)&loc_44, (void *)&loc_50, v5, v5);
    lbl_8006DAEC();

    v10 = lbl_1_rodata_6780.unk_28;
    v9 = lbl_1_rodata_6780.unk_20;
    fn_1_56298(v10, v9, v9, v10);
    scale = lbl_8006D0B4((f32)(loc_44.x * loc_44.x) + loc_44.y * loc_44.y + loc_44.z * loc_44.z);
    if (fabsf(scale) >= (f32)lbl_1_rodata_6780.unk_18) {
        fn_8006EE70((const Sig_fn_8006EE70_Vec3 *)&loc_44, (s16 *)&loc_24);
        mathutil_mtxA_rotate_z(loc_24.a[2]);
        mathutil_mtxA_rotate_y(loc_24.a[1]);
        mathutil_mtxA_rotate_x(loc_24.a[0]);
        v8 = lbl_1_rodata_6780.unk_24;
        v9 = lbl_1_rodata_6780.unk_20;
        v15 = v8 * scale;
        if (!(v15 < v9)) {
            if (v15 > v8) {
                v9 = v8;
            } else {
                v9 = v15;
            }
        }
        v10 = lbl_1_rodata_6780.unk_28;
        lbl_8006E15C(v10, v10, v9);
        fn_80072558();
        fn_1_556B8(lbl_1_bss_38454.v->v->v);
    }
    lbl_8006DB30();
    v9 = lbl_1_rodata_6780.unk_20;
    v10 = lbl_1_rodata_6780.unk_28;
    fn_1_56298(v9, v10, v9, v10);
    scale = lbl_8006D0B4((f32)(loc_50.x * loc_50.x) + loc_50.y * loc_50.y + loc_50.z * loc_50.z);
    if (fabsf(scale) >= (f32)lbl_1_rodata_6780.unk_18) {
        fn_8006EE70((const Sig_fn_8006EE70_Vec3 *)&loc_50, (s16 *)&loc_1C);
        mathutil_mtxA_rotate_z(loc_1C.a[2]);
        mathutil_mtxA_rotate_y(loc_1C.a[1]);
        mathutil_mtxA_rotate_x(loc_1C.a[0]);
        v8 = lbl_1_rodata_6780.unk_24;
        v9 = lbl_1_rodata_6780.unk_20;
        v15 = v8 * scale;
        if (!(v15 < v9)) {
            if (v15 > v8) {
                v9 = v8;
            } else {
                v9 = v15;
            }
        }
        v10 = lbl_1_rodata_6780.unk_28;
        lbl_8006E15C(v10, v10, v9);
        fn_80072558();
        fn_1_556B8(lbl_1_bss_38454.v->v->v);
    }

    v9 = lbl_1_rodata_6780.unk_20;
    fn_1_56298(v9, v9, v9, v9);

    if ((((arg0->unk_13C & 0x80000000) ^ z) | ((arg0->unk_138 & z) ^ z)) != 0) {
        psvec_sub(&loc_74, &arg0->unk_54, &loc_5C);
        v19 = (DCFA4_Node *)arg0->unk_144;
        lbl_8006D784((u32)&loc_98);
        lbl_8006DBAC((u32)(v19 + 0x14C));
        loc_98.a[3] = *(f32 *)(0xE0000000 + 0x0C);
        loc_98.a[7] = *(f32 *)(0xE0000000 + 0x1C);
        loc_98.a[11] = *(f32 *)(0xE0000000 + 0x2C);
        lbl_8006DFE8((u32)&loc_98);
        v5 = v19->unk_17C;
        fn_1_DDF80((u32)&v19->unk_94[0], (u32)&loc_5C, (u8 *)&loc_2C, (void *)&loc_38, v5, v5);
        lbl_8006DAEC();

        v10 = lbl_1_rodata_6780.unk_28;
        v9 = lbl_1_rodata_6780.unk_20;
        fn_1_56298(v10, v9, v9, v10);
        scale = lbl_8006D0B4((f32)(loc_2C.x * loc_2C.x) + loc_2C.y * loc_2C.y + loc_2C.z * loc_2C.z);
        if (fabsf(scale) >= (f32)lbl_1_rodata_6780.unk_18) {
            fn_8006EE70((const Sig_fn_8006EE70_Vec3 *)&loc_2C, (s16 *)&loc_14);
            mathutil_mtxA_rotate_z(loc_14.a[2]);
            mathutil_mtxA_rotate_y(loc_14.a[1]);
            mathutil_mtxA_rotate_x(loc_14.a[0]);
            v8 = lbl_1_rodata_6780.unk_24;
            v9 = lbl_1_rodata_6780.unk_20;
            v15 = v8 * scale;
            if (!(v15 < v9)) {
                if (v15 > v8) {
                    v9 = v8;
                } else {
                    v9 = v15;
                }
            }
            v10 = lbl_1_rodata_6780.unk_28;
            lbl_8006E15C(v10, v10, v9);
            fn_80072558();
            fn_1_556B8(lbl_1_bss_38454.v->v->v);
        }
        lbl_8006DB30();
        v9 = lbl_1_rodata_6780.unk_20;
        v10 = lbl_1_rodata_6780.unk_28;
        fn_1_56298(v9, v10, v9, v10);
        scale = lbl_8006D0B4((f32)(loc_38.x * loc_38.x) + loc_38.y * loc_38.y + loc_38.z * loc_38.z);
        if (fabsf(scale) >= (f32)lbl_1_rodata_6780.unk_18) {
            fn_8006EE70((const Sig_fn_8006EE70_Vec3 *)&loc_38, (s16 *)&loc_C);
            mathutil_mtxA_rotate_z(loc_C.a[2]);
            mathutil_mtxA_rotate_y(loc_C.a[1]);
            mathutil_mtxA_rotate_x(loc_C.a[0]);
            v8 = lbl_1_rodata_6780.unk_24;
            v9 = lbl_1_rodata_6780.unk_20;
            v15 = v8 * scale;
            if (!(v15 < v9)) {
                if (v15 > v8) {
                    v9 = v8;
                } else {
                    v9 = v15;
                }
            }
            v10 = lbl_1_rodata_6780.unk_28;
            lbl_8006E15C(v10, v10, v9);
            fn_80072558();
            fn_1_556B8(lbl_1_bss_38454.v->v->v);
        }
    }
    v9 = lbl_1_rodata_6780.unk_20;
    fn_1_56298(v9, v9, v9, v9);
}
