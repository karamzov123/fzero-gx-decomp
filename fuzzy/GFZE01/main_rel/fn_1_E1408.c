/* Non-matching: best partial attempt (62.26% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"

typedef struct {
    u8 pad0[0x18];
    f32 field18;
    f32 field1C;
    f32 field20;
    u8 pad24[0x20];
    f32 field44;
    u8 pad48[0x08];
    f32 field50;
    f32 field54[3];
    f32 field60[2];
    f32 field68;
    u8 pad6C[0x18];
    f32 field84;
    u8 pad88[0xAC];
    f32 field134;
    u64 field138;
    u32 field140;
    u32 field144;
    u8 pad148[0xFC];
    f32 field244;
} E1408Object;

struct fn_1_E1408_lbl_1_rodata_6780 {
    f32 negone;
    u8 pad4[0x1C];
    f32 zero;
    u8 pad24[0x58];
    f32 epsilon;
    u8 pad80[0x4C];
    f32 nearone;
};
extern struct fn_1_E1408_lbl_1_rodata_6780 lbl_1_rodata_6780;
extern f32 lbl_8006D0B4(f32);
extern void *lbl_8006D5A4(void *, void *, void *, f32);
extern void *lbl_8006D5F0(void *, f32);
extern void fn_1_DF6AC(void *, void *, void *, void *, void *, f32, f32, f32, f32, f32, f32);

void fn_1_E1408(E1408Object *a, E1408Object *b) {
    f32 t;
    f32 dz;
    f32 radius;
    f32 aa;
    f32 bb;
    f32 cc;
    f32 disc;
    f32 impulse;
    f32 tmp;
    s32 hit;
    s32 modeA;
    s32 modeB;
    f32 vecA[3];
    f32 vecB[3];
    f32 vecC[3];

    if ((a->field138 & 0x40) || (b->field138 & 0x40)) return;
    if ((a->field140 & b->field140) == 0) return;

    psvec_sub(&a->field60[0], &b->field60[0], &vecA[0]);
    psvec_sub(&a->field54[0], &b->field54[0], &vecB[0]);
    dz = a->field68 - b->field68;
    vecC[0] = vecB[0] - vecA[0];
    vecC[1] = vecB[1] - vecA[1];
    tmp = a->field68 - b->field68;
    dz = a->field68 - b->field68;
    radius = lbl_1_rodata_6780.nearone * a->field84 * a->field244 +
             lbl_1_rodata_6780.nearone * b->field84 * b->field244;

    aa = vecC[0] * vecC[0] + vecC[1] * vecC[1] + dz * dz;
    cc = vecA[0] * vecA[0] + vecA[1] * vecA[1] + tmp * tmp;
    bb = vecA[0] * vecC[0] + vecA[1] * vecC[1] + tmp * dz;
    cc -= radius * radius;

    hit = 0;
    t = 0.0f;
    if (aa >= lbl_1_rodata_6780.epsilon) {
        disc = bb * bb - aa * cc;
        if (disc >= lbl_1_rodata_6780.zero) {
            if (cc <= lbl_1_rodata_6780.zero) {
                hit = 1;
            } else if (cc + aa + bb + bb > lbl_1_rodata_6780.zero &&
                       bb < lbl_1_rodata_6780.zero &&
                       -bb <= aa) {
                t = -(bb + lbl_8006D0B4(disc)) / aa;
                hit = 1;
            }
        }
    }
    if (!hit) return;

    lbl_8006D5A4(&a->field60[0], &a->field54[0], &a->field54[0], t);
    lbl_8006D5A4(&b->field60[0], &b->field54[0], &b->field54[0], t);
    psvec_sub(&b->field54[0], &a->field54[0], &vecA[0]);
    vecA[2] = b->field68 - a->field68;

    modeA = ((a->field138 & 0x80000) && (b->field138 & 0x80000)) ||
            ((b->field138 & 0x40000) && !(a->field138 & 0x40000));
    modeB = ((b->field138 & 0x80000) && !(a->field138 & 0x80000)) ||
            ((b->field138 & 0x40000) && !(a->field138 & 0x40000));

    if (modeA) {
        impulse = 1.5f * radius;
        lbl_8006D5F0(vecA, impulse);
        psvec_add(&b->field54[0], &vecB[0], &a->field54[0]);
    } else if (modeB) {
        impulse = 1.5f * radius;
        lbl_8006D5F0(vecA, -impulse);
        psvec_add(&a->field54[0], &vecB[0], &b->field54[0]);
    } else {
        impulse = 0.01f * radius;
        lbl_8006D5F0(vecA, -impulse);
        psvec_add(&a->field54[0], &vecB[0], &a->field54[0]);
        psvec_scale(&vecB[0], lbl_1_rodata_6780.negone, &vecB[0]);
        psvec_add(&b->field54[0], &vecB[0], &b->field54[0]);
    }
    fn_1_DF6AC(&vecA[0], &a->field44, &b->field44, &a->field44, &b->field44,
               0.5f * (a->field18 + b->field18), a->field50, b->field50,
               a->field1C, b->field1C, 0.0f);
    a->field138 |= 0x20000000;
    b->field138 |= 0x20000000;
    a->field144 = (u32)b;
    b->field144 = (u32)a;
}
