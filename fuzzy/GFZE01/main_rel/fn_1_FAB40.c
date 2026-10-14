/* Non-matching: best partial attempt (58.61% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/spline.h"

typedef struct {
    f32 x, y, z;
} Vec3;
typedef struct {
    f32 value0, value4, value8;
} Sig_fn_8006F900_Fn8006F900Data;

extern f32 lbl_1_rodata_7480[];
extern Obj_1_data_3EED0 lbl_1_data_3EED0;
extern Obj_1_data_3EF30 lbl_1_data_3EF30;
extern u32 lbl_801A6D00;
extern s32 fn_1_5910(void);
extern s16 fn_1_3F0C8(void);
extern s32 fn_1_58C4(void);
extern s32 fn_1_5948(s32);
extern void fn_1_681C(u32, Vec3 *);
extern s32 fn_1_54E34(void *, f32);
extern void fn_1_76BD0(u8, u8);
extern void *fn_1_72714(u8, u32);
extern void fn_1_627C(s32);
extern f32 fn_1_A71AC(void);
extern void fn_1_55FF0(f32);
extern void fn_1_556B8(void *);
extern void lbl_8006DCA4(void);
extern void lbl_8006E0A4(void *);
extern void mathutil_mtxA_rotate_z(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_x(s32);
extern void lbl_8006E14C(f32);
extern void lbl_8006E13C(void *);
extern void fn_80072558(void);
extern void fn_800724C8(void);
extern void fn_80073778(void *, s32);
extern void fn_80072864(u32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80072EDC(s32, s32);
extern void fn_80073C6C(s32);
extern void fn_80073678(u32);
extern void fn_80074660(u32);
extern void fn_80073898(u32);
extern void fn_80074788(u32);
extern void fn_8007245C(u32);
extern void fn_80074918(u8, s32, u8);
extern void fn_800728A8(s32, s32, s32, s32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void fn_8006F900(Vec3 *, Sig_fn_8006F900_Fn8006F900Data *, f32);
extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DB30(void);
extern void lbl_8006DFD8(void);
extern u32 GXLoadTexMtxImm(u32, u32, u32);
extern void fn_8003462C(u32, u32, u32);
extern void lbl_8006DC20(void);

void fn_1_FAB40(void) {
    Obj_1_data_2A7E0_At3C *obj = lbl_1_data_2A7E0.unk_3C;
    u8 *list = (u8 *)obj + 4;
    s32 selected;
    s32 count, i, j, k;
    Vec3 pos;
    u32 mask;
    f32 scale = lbl_1_rodata_7480[13];
    Sig_fn_8006F900_Fn8006F900Data transformed;
    f32 matrix[12];
    f32 vertices[12];
    Obj_1_data_3EED0 *indices;
    Obj_1_data_3EF30 *points;

    fn_1_5910();
    if (*list == 0)
        return;
    if (fn_1_3F0C8() == 45)
        return;
    selected = 1;

    count = fn_1_58C4();
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        lbl_8006DCA4();
        fn_1_681C(i & 0xff, &pos);
        for (j = 0; j < *list; j++) {
            u8 *record = *(u8 **)(list + 4 + j * 4);
            u32 flags = *(u32 *)(record + 4);
            if (((flags + 0x10000) == 0xffff || (flags & lbl_1_data_2A7E0.unk_50)) &&
                (*(u32 *)record & lbl_1_data_2A7E0.unk_4C)) {
                Vec3 *origin = (Vec3 *)(record + 0xc);
                f32 dx = pos.x - origin->x;
                f32 dy = pos.y - origin->y;
                f32 dz = pos.z - origin->z;
                f32 dist = dx * dx + dy * dy + dz * dz;
                if (dist < lbl_1_rodata_7480[10] &&
                    fn_1_54E34(origin, lbl_1_rodata_7480[11]))
                    selected = 0;
            }
        }
    }
    mask = obj->unk_16C;
    fn_1_76BD0(mask & 0xff, selected);

    count = fn_1_58C4();
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        for (j = 0; j < *list; j++) {
            u8 *record = *(u8 **)(list + 4 + j * 4);
            u32 flags = *(u32 *)(record + 4);
            if ((flags + 0x10000 == 0xffff || (flags & lbl_1_data_2A7E0.unk_50)) &&
                (*(u32 *)record & lbl_1_data_2A7E0.unk_4C)) {
                lbl_8006DCA4();
                lbl_8006E0A4(record + 0xc);
                mathutil_mtxA_rotate_z(*(s16 *)(record + 0x1c));
                mathutil_mtxA_rotate_y(*(s16 *)(record + 0x1a));
                mathutil_mtxA_rotate_x(*(s16 *)(record + 0x18));
                mathutil_mtxA_rotate_z(0x1c71);
                mathutil_mtxA_rotate_y(0);
                mathutil_mtxA_rotate_x(0x2000);
                lbl_8006E14C(lbl_1_rodata_7480[12]);
                lbl_8006E13C(record + 0x20);
                fn_80072558();
                fn_800724C8();
                fn_80073778(fn_1_72714(((u8 *)obj)[0x168], 0), 0);
                fn_80072864(2);
                fn_800745A4(0, 0, 0, 30, 0, 125);
                fn_800734A8(0, 0, 0, 255);
                fn_80072EDC(0, 3);
                fn_80073C6C(0);
                fn_80073678(1);
                fn_80074660(1);
                fn_80073898(0);
                fn_80074788(0);
                fn_8007245C(512);
                fn_80074918(1, 3, 0);
                fn_800728A8(1, 4, 0, 0);
                lbl_8006DAEC();

                for (k = 0; k < 6; k++) {
                    u8 *idx = (u8 *)indices + k * 16;
                    Vec3 *a = (Vec3 *)((u8 *)points + idx[0] * 12);
                    Vec3 *b = (Vec3 *)((u8 *)points + idx[2] * 12);
                    Vec3 *c = (Vec3 *)((u8 *)points + idx[1] * 12);
                    Vec3 *d = (Vec3 *)((u8 *)points + idx[3] * 12);
                    vertices[0] = (a->x + b->x) * scale;
                    vertices[1] = (a->y + b->y) * scale;
                    vertices[2] = (a->z + b->z) * scale;
                    vertices[3] = (c->x + d->x) * scale;
                    vertices[4] = (c->y + d->y) * scale;
                    vertices[5] = (c->z + d->z) * scale;
                    vertices[6] = (b->x + c->x) * scale;
                    vertices[7] = (b->y + c->y) * scale;
                    vertices[8] = (b->z + c->z) * scale;
                    vertices[9] = (d->x + a->x) * scale;
                    vertices[10] = (d->y + a->y) * scale;
                    vertices[11] = (d->z + a->z) * scale;
                    vertices[12] = (a->x + c->x) * scale;
                    vertices[13] = (a->y + c->y) * scale;
                    vertices[14] = (a->z + c->z) * scale;
                    vertices[15] = (b->x + d->x) * scale;
                    vertices[16] = (b->y + d->y) * scale;
                    vertices[17] = (b->z + d->z) * scale;
                    fn_8006F900((Vec3 *)vertices, &transformed, fn_1_A71AC());
                    lbl_8006DAEC();
                    lbl_8006D7F4(-transformed.value0 * 50.0f,
                                  -transformed.value4 * 10.0f, 0.0f);
                    lbl_8006DB74(matrix);
                    lbl_8006DB30();
                    lbl_8006DFD8();
                    lbl_8006DFD8();
                    GXLoadTexMtxImm(lbl_801A6D00, 30, 0);
                    fn_8003462C(128, 0, 4);
                    *(volatile f32 *)0xCC008000 = vertices[0];
                    *(volatile f32 *)0xCC008000 = vertices[1];
                    *(volatile f32 *)0xCC008000 = vertices[2];
                    *(volatile f32 *)0xCC008000 = vertices[3];
                    *(volatile f32 *)0xCC008000 = vertices[4];
                    *(volatile f32 *)0xCC008000 = vertices[5];
                    *(volatile f32 *)0xCC008000 = vertices[6];
                    *(volatile f32 *)0xCC008000 = vertices[7];
                    *(volatile f32 *)0xCC008000 = vertices[8];
                    *(volatile f32 *)0xCC008000 = vertices[9];
                    *(volatile f32 *)0xCC008000 = vertices[10];
                    *(volatile f32 *)0xCC008000 = vertices[11];
                }
            }
        }
        fn_1_627C(i);
    }
    lbl_8006DC20();
}
