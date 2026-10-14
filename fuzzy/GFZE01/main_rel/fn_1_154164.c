/* Non-matching: best partial attempt (89.81% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    u32 w0, w1, w2, w3, w4, w5;
    s16 ax, ay, az;
    u16 pad;
    u32 m0, m1, m2, m3, m4, m5, m6, m7;
} Node;

typedef struct {
    u8 pad_0[0x1108];
    u32 count;
    u32 num;
    Node *first;
    u32 pad_1114[16];
    u32 flags[16];
} BgAurObj;

extern u32 fn_1_9BBE4(void *, u32, u32, void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DFC4(Vec3 *);
extern void lbl_8006E0C8(Vec3 *);
extern void lbl_8006E0A4(Vec3 *);
extern void lbl_8006D7DC(Vec3 *);
extern void lbl_8006E13C(void *);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_z(s16);

void fn_1_154164(BgAurObj *self, Vec3 *offset, Vec3 *dir, s32 all) {
    Vec3 *v0;
    Vec3 *v;
    u32 scratch[12];
    Node *d;
    s32 i;
    Node *cur;
    u32 *row;
    u32 *tbl = &self->count;
    Node nodes[17];

    if (self->first != 0) {
        v0 = (Vec3 *)&nodes[0].w3;
        nodes[0] = *self->first;
        psvec_add(v0, offset, v0);
        ((0)[nodes]).w0 &= 0x7FFFFFFF;
        lbl_8006D7DC(v0);
        lbl_8006DFC4(dir);
        lbl_8006E13C(&nodes[0].m0);
        lbl_8006DB74(scratch);
        fn_1_9BBE4(&nodes[0], 0, 0, scratch);

        for (i = 0; i < (s32)((0)[tbl]); i++) {
            row = tbl + i;
            cur = &nodes[i];
            if (all != 0 || (s32)((0x13)[row]) == 0) {
                cur[1] = *(Node *)((3)[row]);
                d = &nodes[i + 1];
                ((1)[cur]).w0 &= 0x7FFFFFFF;
                v = (Vec3 *)&d->w3;
                psvec_add(v, offset, v);
                lbl_8006D7DC(v0);
                lbl_8006DFC4(dir);
                lbl_8006E0C8(v0);
                lbl_8006E0A4(v);
                mathutil_mtxA_rotate_z(((1)[cur]).az);
                mathutil_mtxA_rotate_y(((1)[cur]).ay);
                mathutil_mtxA_rotate_x(((1)[cur]).ax);
                lbl_8006E13C(&d->m0);
                lbl_8006DB74(scratch);
                fn_1_9BBE4(d, 0, 0, scratch);
            }
        }
    }
}
