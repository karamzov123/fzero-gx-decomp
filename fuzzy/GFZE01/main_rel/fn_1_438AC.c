/* Non-matching: best partial attempt (75.07% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"

typedef struct Fn1438ACEntry {
    u8 pad0[0xB8];
    f32 scale[3];
    u8 padC4[0x0C];
    u8 padD0[0xA4];
} Fn1438ACEntry;

typedef struct Fn1438ACObject {
    u16 count;
    u16 flags;
    u8 pad4[4];
    Fn1438ACEntry *entries;
    u8 padC[0x0C];
    f32 value18;
    f32 value1C;
    f32 value20;
    u8 pad24[0x28];
    f32 value4C;
    u8 pad50[0x14];
    f32 value64;
} Fn1438ACObject;

typedef struct Fn1438ACItem {
    u16 unk0;
    u16 unk2;
    u16 flags;
    u16 unk6;
    u32 unk8[2];
    f32 unk10;
    u8 pad14[0xBC];
    u8 *orientation;
} Fn1438ACItem;

extern const f32 lbl_1_rodata_F50;
extern const f32 lbl_1_rodata_F54;
extern const f32 lbl_1_rodata_F68;
extern const f64 lbl_1_rodata_F60;
extern s32 fn_1_442D8(void *, void *, u32, u32, f32);
extern u32 fn_1_44A74(void *, void *);
extern u32 fn_8006E250(void *, void *);
extern u32 lbl_8006D7B0(void);
extern void lbl_8006E1B0(void *, void *);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_z(s32);
extern void lbl_8006D758(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DFC4(void *);

static inline f32 *fn_1_438AC_array_read(f32 *array) { return array; }
#pragma opt_common_subs off
static inline u8 fn_1_438AC_array_read_(s32 index, u8 *array) { return array[index]; }
#pragma opt_propagation off
static inline Fn1438ACEntry * fn_1_438AC_read_pointer(Fn1438ACObject * owner) { return owner->entries; }
#pragma opt_loop_invariants on
#pragma opt_lifetimes off
void fn_1_438AC(Fn1438ACObject *arg0, Fn1438ACItem *arg1, u32 arg2) {
    f32 v0;
    u32 v1;
    u16 v2;
    u8 v9;
    Fn1438ACEntry *v5;
    u8 v8;
    Fn1438ACEntry *v3;
    u8 v10;
    f64 v11;
    f32 v12;
    u32 v13;
    u16 v14;
    f32 loc_14[6];
    f32 loc_8[3];
    Fn1438ACEntry * v5_2;
    u32 t13;
    u32 t21;
    void * lab_t0;

    if (arg2 != 0) {
        v0 = arg0->value64;
        v1 = 3;
    } else {
        v1 = 0;
        v0 = arg0->value4C;
    }
    v2 = arg1->unk6;
    if (v2 == 65535) {
        lbl_8006D758();
        loc_14[3] = lbl_1_rodata_F50;
        loc_14[4] = lbl_1_rodata_F50;
        loc_14[5] = lbl_1_rodata_F50;
    } else if ((arg1->flags & 4) != 0) {
        lbl_8006D7B0();
        loc_14[3] = lbl_1_rodata_F50;
        loc_14[4] = lbl_1_rodata_F50;
        loc_14[5] = lbl_1_rodata_F50;
    } else {
        v3 = (Fn1438ACEntry *)((u8 *)fn_1_438AC_read_pointer(arg0) + v2 * 0x18C);
        lbl_8006DBAC((u8 *)v3 + 0x88);
        *(u32 *)((u8 *)&loc_14[0] + 12) = *(u32 *)((u8 *)v3 + 0xB8);
        *(u32 *)((u8 *)&loc_14[0] + 16) = *(u32 *)((u8 *)v3 + 0xBC);
        *(u32 *)((u8 *)&loc_14[0] + 20) = *(u32 *)((u8 *)v3 + 0xC0);
    }
    v5 = (Fn1438ACEntry *)arg1;
    if ((arg0->flags & 2) != 0) {
        u8 *p = (u8 *)arg1 + 0xD0;
        if ((*p & 0x40) == 0) {
            v5_2 = (Fn1438ACEntry *)((u8 *)fn_1_438AC_read_pointer(arg0) + (*(u16 *)(p + 4) * 0x18C));
        }
    }
    if ((arg1->flags & 1) != 0) {
        lbl_8006E1B0((u8 *)arg1 + 8, loc_8);
        fn_1_442D8(loc_8, v5_2, (v1 + 12) & 0xFFFF, arg2, v0);
        if ((arg0->flags & 2) != 0) {
            u8 *p = (u8 *)arg1 + 0xD0;
            if ((*p & 1) != 0) loc_8[0] = -((0)[loc_8]);
            if ((*p & 2) != 0) loc_8[1] = -((1)[loc_8]);
            if ((*p & 4) != 0) loc_8[2] = -((2)[loc_8]);
        }
    } else {
        *(u32 *)&loc_8[0] = *(u32 *)((u8 *)arg1 + 8);
        *(u32 *)&loc_8[1] = *(u32 *)((u8 *)arg1 + 12);
        *(u32 *)&loc_8[2] = *(u32 *)((u8 *)arg1 + 16);
        fn_1_442D8(loc_8, v5_2, (v1 + 12) & 0xFFFF, arg2, v0);
        if ((arg0->flags & 2) != 0) {
            u8 *p = (u8 *)arg1 + 0xD0;
            if ((*p & 1) != 0) loc_8[0] = -((0)[loc_8]);
            if ((*p & 2) != 0) loc_8[1] = -((1)[loc_8]);
            if ((*p & 4) != 0) loc_8[2] = -((2)[loc_8]);
        }
        lbl_8006E1B0(loc_8, loc_8);
    }
    *(f32 *)0xE000000C = ((0)[loc_8]);
    *(f32 *)0xE000001C = ((1)[loc_8]);
    *(f32 *)0xE000002C = ((2)[loc_8]);
    psvec_set((u8 *)arg1 + 0xC4, *(f32 *)0xE000002C, *(f32 *)0xE000001C, *(f32 *)0xE000000C);
    loc_14[0] = lbl_1_rodata_F54;
    loc_14[1] = lbl_1_rodata_F54;
    loc_14[2] = lbl_1_rodata_F54;
    lbl_8006DFC4((u8 *)arg1 + 0x28);
    if ((arg0->flags & 2) != 0) {
        u8 *p = (u8 *)arg1 + 0xD0;
        v8 = fn_1_438AC_array_read_(3, p);
        mathutil_mtxA_rotate_z((s32)(f32)(lbl_1_rodata_F68 * (f32)(s32)((s8)v8 * 45)));
        v9 = fn_1_438AC_array_read_(2, p);
        mathutil_mtxA_rotate_y((s32)(f32)(lbl_1_rodata_F68 * (f32)(s32)((s8)v9 * 45)));
        v10 = fn_1_438AC_array_read_(1, p);
        mathutil_mtxA_rotate_x((s32)(f32)(lbl_1_rodata_F68 * (f32)(s32)((s8)v10 * 45)));
    }
    if ((arg1->flags & 1) != 0) {
        lbl_8006DB74((u8 *)arg1 + 0x88);
        fn_1_44A74(arg0, arg1);
    }
    t13 = fn_1_442D8(loc_14, v5_2, (v1 + 6) & 0xFFFF, arg2, v0);
    if ((s32)t13 != 0) {
        if ((arg0->flags & 2) != 0) {
            u8 *p = (u8 *)arg1 + 0xD0;
            if ((*p & 8) != 0) loc_14[0] = -((0)[loc_14]);
            if ((*p & 0x10) != 0) loc_14[1] = -((1)[loc_14]);
            if ((*p & 0x20) != 0) loc_14[2] = -((2)[loc_14]);
        }
        mathutil_mtxA_rotate_z((s32)(f32)(lbl_1_rodata_F68 * ((2)[loc_14])));
        mathutil_mtxA_rotate_y((s32)(f32)(lbl_1_rodata_F68 * ((1)[loc_14])));
        mathutil_mtxA_rotate_x((s32)(f32)(lbl_1_rodata_F68 * ((0)[loc_14])));
    } else if ((arg1->flags & 4) == 0) {
        lbl_8006DFC4((u8 *)arg1 + 0x58);
    }
    *(f32 *)((u8 *)arg1 + 0xB8) = lbl_1_rodata_F50;
    *(f32 *)((u8 *)arg1 + 0xBC) = lbl_1_rodata_F50;
    *(f32 *)((u8 *)arg1 + 0xC0) = lbl_1_rodata_F50;
    lab_t0 = (u8 *)arg1 + 0xB8;
    fn_1_442D8(lab_t0, v5_2, v1 & 0xFFFF, arg2, v0);
    *(f32 *)((u8 *)arg1 + 0xB8) *= ((3)[loc_14]);
    v11 = *(f32 *)((u8 *)arg1 + 0xBC);
    *(f32 *)((u8 *)arg1 + 0xBC) = v11 * ((4)[loc_14]);
    v12 = *(f32 *)((u8 *)arg1 + 0xC0);
    *(f32 *)((u8 *)arg1 + 0xC0) = v12 * ((5)[loc_14]);
    lbl_8006DB74((u8 *)arg1 + 0x88);
    if ((arg1->flags & 1) == 0) {
        v14 = arg1->unk6;
        if (v14 != 65535) {
            v13 = v14 * 0x18C;
            v13 += 0x88;
            v13 += (u32)fn_1_438AC_read_pointer(arg0);
            lbl_8006DBAC((void *)v13);
            v13 = (u32)((u8 *)arg1 + 0xC4);
            t21 = fn_8006E250((void *)v13, (void *)v13);
            v13 = t21;
        }
    }
}
#pragma opt_lifetimes reset

#pragma opt_loop_invariants reset

#pragma opt_propagation reset

#pragma opt_common_subs reset

