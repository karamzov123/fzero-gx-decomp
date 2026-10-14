/* Non-matching: best partial attempt (98.36% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern const f32 lbl_1_rodata_F6C;
extern const f32 lbl_1_rodata_F68;
extern const f32 lbl_1_rodata_F50;
extern const f32 lbl_1_rodata_F54;

extern f32 lbl_8006D188(s32);
extern void lbl_8006D758(void);
extern void lbl_8006DBAC(void *);
extern void lbl_8006E1B0(void *, void *);
extern void mathutil_mtxA_from_quat(void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DD7C(void);
extern void lbl_8006DFC4(void *);
extern void fn_8006E5FC(void *);
extern void lbl_8006E15C(f32, f32, f32);

typedef struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct Quaternion {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Quaternion;

extern void fn_8006E8DC(Quaternion *);
extern void fn_8006EB4C(Quaternion *, const Quaternion *, const Quaternion *, f32);

typedef f32 Mtx[3][4];

typedef struct Elem {
    u8 pad0[4];
    u16 flags;
    u16 parent_idx;
    u8 pad8[0xC];
    f32 unk14;
    Vec3f unk18;
    f32 unk24;
    u8 pad28[0x60];
    Mtx unk88;
    Vec3f scale;
    Vec3f unkC4;
    u8 padD0[0x94];
    Quaternion quat;
    f32 unk174;
    f32 unk178;
    f32 unk17C;
    f32 unk180;
    f32 unk184;
    f32 unk188;
} Elem;

typedef struct Fn1433E0Arg0 {
    u16 count;
    u16 flags;
    u8 pad4[4];
    Elem *elements;
    Vec3f scale;
    Vec3f trans;
    u8 pad24[4];
    f32 unk28;
    f32 unk2C;
    Vec3f prev_trans;
} Fn1433E0Arg0;

#pragma opt_propagation off
static inline f32 fn_1_433E0_read_pointer(Vec3f * owner) { return owner->z; }
void fn_1_433E0(Fn1433E0Arg0 *arg0) {
    struct {
        u8 *value;
    } mtxA;
    Elem *elem;
    Elem *elements;
    s32 i;
    Elem *parent;
    f32 t;
    f32 zero;
    Vec3f pos;
    Vec3f temp;
    f32 tx;
    f32 ty;
    f32 tz;
    Mtx loc_34;
    Quaternion loc_18;
    Quaternion loc_8;
    f32 lab_t3;
    f32 zero_2;

    if (arg0->unk28 < arg0->unk2C) {
        t = arg0->unk28 / arg0->unk2C;
        if (arg0->flags & 0x0C00) {
            t = lbl_8006D188((s32)(lbl_1_rodata_F68 * (lbl_1_rodata_F6C * t)));
            if (arg0->flags & 0x0800) {
                t = t * t;
            }
        }
        arg0->unk28 += lbl_1_rodata_F50;
    } else {
        t = lbl_1_rodata_F50;
        arg0->unk28 = lbl_1_rodata_F54;
        arg0->unk2C = lbl_1_rodata_F54;
        arg0->flags &= 0xFFFE;
    }

    elements = arg0->elements;
    elem = elements;
    mtxA.value = (u8 *)0xE0000000;
    for (i = 0; i < arg0->count; elem++, i++) {
        parent = NULL;
        if (i == 0) {
            pos.x = arg0->trans.x * arg0->scale.x;
            pos.y = arg0->trans.y * arg0->scale.y;
            pos.z = arg0->trans.z * arg0->scale.z;
            if (!(arg0->flags & 0x0020)) {
                pos.x = arg0->prev_trans.x + (f32)(t * (pos.x - arg0->prev_trans.x));
            }
            if (!(arg0->flags & 0x0040)) {
                pos.y = arg0->prev_trans.y + (f32)(t * (pos.y - arg0->prev_trans.y));
            }
            if (!(arg0->flags & 0x0080)) {
                pos.z = arg0->prev_trans.z + (f32)(t * (pos.z - arg0->prev_trans.z));
            }
        } else {
            if (elem->parent_idx == 0xFFFF) {
                lbl_8006D758();
            } else {
                parent = &elements[elem->parent_idx];
                lbl_8006DBAC(&parent->unk88);
            }
            if (elem->flags & 0x11) {
                pos.x = elem->unk14 * arg0->scale.x;
                pos.y = lbl_1_rodata_F54;
                pos.z = lbl_1_rodata_F54;
                if (arg0->flags & 0x0008) {
                    pos.x = pos.x * elem->unk24;
                }
            } else {
                if (arg0->flags & 0x0008) {
                    temp = elem->unk18;
                } else {
                    temp = elem->unkC4;
                }
                pos = temp;
                if (t < lbl_1_rodata_F50) {
                    if (elem->flags & 0x0040) {
                        tx = elem->unk180 * (elem->unk174 / elem->scale.x);
                        pos.x = tx + (f32)(t * (pos.x - tx));
                        ty = elem->unk184 * (elem->unk178 / elem->scale.y);
                        pos.y = ty + (f32)(t * (pos.y - ty));
                        tz = elem->unk188 * (elem->unk17C / elem->scale.z);
                        pos.z = tz + (f32)(t * (pos.z - tz));
                    }
                }
            }
            lbl_8006E1B0(&pos, &pos);
        }

        elem->scale.x *= arg0->scale.x;
        elem->scale.y *= arg0->scale.y;
        elem->scale.z *= arg0->scale.z;

        if (t < lbl_1_rodata_F50) {
            if ((arg0->flags & 0x0200) && parent != NULL && elem->parent_idx != 0) {
                mathutil_mtxA_from_quat(&elem->quat);
                lbl_8006DB74(&loc_34);
                mathutil_mtxA_from_quat(&parent->quat);
                lbl_8006DD7C();
                lbl_8006DFC4(&loc_34);
                fn_8006E5FC(&loc_8);
                lbl_8006DBAC(&parent->unk88);
                zero = lbl_1_rodata_F54;
                *(f32 *)(0xE0000000 + 0x0C) = zero;
                *(f32 *)(0xE0000000 + 0x1C) = zero;
                *(f32 *)(0xE0000000 + 0x2C) = zero;
                lbl_8006DD7C();
                lbl_8006DFC4(&elem->unk88);
                zero_2 = lbl_1_rodata_F54;
                *(f32 *)(0xE0000000 + 0x0C) = zero_2;
                *(f32 *)(0xE0000000 + 0x1C) = zero_2;
                *(f32 *)(0xE0000000 + 0x2C) = zero_2;
                fn_8006E5FC(&loc_18);
                fn_8006E8DC(&loc_18);
                fn_8006E8DC(&loc_8);
                lab_t3 = t;
                fn_8006EB4C(&loc_18, &loc_8, &loc_18, lab_t3);
                fn_8006E8DC(&loc_18);
                mathutil_mtxA_from_quat(&loc_18);
                lbl_8006DB74(&loc_34);
                lbl_8006DBAC(&parent->unk88);
                zero_2 = lbl_1_rodata_F54;
                *(f32 *)(0xE0000000 + 0x0C) = zero_2;
                *(f32 *)(0xE0000000 + 0x1C) = zero_2;
                *(f32 *)(0xE0000000 + 0x2C) = zero_2;
                lbl_8006DFC4(&loc_34);
            } else {
                lbl_8006DBAC(&elem->unk88);
                fn_8006E5FC(&loc_18);
                lab_t3 = t;
                fn_8006EB4C(&loc_18, &elem->quat, &loc_18, lab_t3);
                mathutil_mtxA_from_quat(&loc_18);
            }
        } else {
            lbl_8006DBAC(&elem->unk88);
        }

        {
            f32 y = pos.y;
            f32 x = pos.x;
            f32 z = fn_1_433E0_read_pointer(&pos);
            *(f32 *)(mtxA.value + 0x0C) = x;
            *(f32 *)(mtxA.value + 0x1C) = y;
            *(f32 *)(mtxA.value + 0x2C) = z;
        }
        lbl_8006E15C(elem->scale.x, elem->scale.y, elem->scale.z);
        lbl_8006DB74(&elem->unk88);
    }
}
#pragma opt_propagation reset

