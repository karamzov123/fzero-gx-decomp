/* Non-matching: best partial attempt (76.89% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"

typedef struct { f32 x, y, z; } Vec3;
typedef struct {
    u8 pad_0[0x7c];
    Vec3 previous;
    Vec3 position;
    u8 pad_94[0x58];
    Vec3 velocity;
    u8 pad_ec[0x28];
    f32 unk_114;
    u8 pad_118[0x60];
    f32 unk_178;
    u8 pad_17c[0x38];
    f32 unk_1b4;
    u8 pad_1b8[0x20];
    u32 flags_218;
    u8 pad_21c[0x8];
    f32 unk_224;
    u8 pad_228[0x284];
    f32 unk_4ac;
    u8 pad_4b0[0x123];
    u8 unk_5d3;
    u8 pad_5d4[6];
    u16 unk_5da;
} Obj;
typedef struct {
    u8 pad_0[0xc]; f32 zero;
    u8 pad_10[4]; f32 one;
    u8 pad_18[8]; f64 two52;
    u8 pad_28[0xc]; f32 four; f32 point6;
    u8 pad_3c[0x24]; f32 quarter;
    u8 pad_64[0x14]; f32 two;
    u8 pad_7c[0x4c]; f32 hundredth;
    u8 pad_cc[0x48]; f32 epsilon;
    u8 pad_118[0x50]; f32 ten;
    u8 pad_16c[0xc]; f32 twenty; f32 scale;
    u8 pad_180[0x28]; f64 mph;
    u8 pad_1b0[0x98]; f32 negone;
    u8 pad_24c[0x48]; f32 sixhundred; f32 six;
} Pool;
extern Pool lbl_1_rodata_840;
extern s32 fn_1_8C66C(s32);
extern int fn_1_163BC(void *, void *, u32, s32);
extern void fn_1_A33F0(s32, f32);
extern void fn_1_694A4(s32, void *, void *, f32);
extern void lbl_8006DAEC(void);
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D6FC(void *, void *);
extern void lbl_8006D5F0(void *, f32);
extern void lbl_8006DBAC(void *);
extern void fn_8006E2B0(void *);
extern void lbl_8006E1C0(void *);
extern void lbl_8006DB30(void);

void fn_1_28184(Obj *o)
{
    Vec3 saved;
    Vec3 v8, v14, v20, v2c, v38;
    f32 dist, dot, t, damp, amount, speed;
    Pool *pool = &lbl_1_rodata_840;
    saved = o->previous;
    lbl_8006DAEC();
    if (fn_1_163BC(&saved, &o->position, 0x4000, fn_1_8C66C(*(s16 *)((u8 *)o + 4)))) {
        psvec_sub(&o->previous, &o->position, &v14);
        psvec_sub(&saved, &o->position, &v8);
        dist = lbl_8006D0B4((f32)(v14.x*v14.x + v14.y*v14.y + v14.z*v14.z));
        dot = v14.x*v8.x + v14.y*v8.y + v14.z*v8.z;
        t = dot / (dist*dist);
        psvec_scale(&v14, t, &v20);
        psvec_add(&v20, &o->position, &v38);
        if (*(f32 *)((u8 *)o + 0x17c) > pool->sixhundred)
            t = pool->one;
        else
            t = pool->negone;
        psvec_sub(&v38, &saved, &v8);
        dist = lbl_8006D0B4((f32)(v8.x*v8.x + v8.y*v8.y + v8.z*v8.z));
        damp = lbl_8006D6FC((void *)((u8 *)o + 0x1bc), &v8);
        speed = dist*damp;
        psvec_scale((void *)((u8 *)o + 0x1bc), speed, &v20);
        v20.z = *(f32 *)((u8 *)o + 0x1c4)*speed;
        psvec_add(&v20, &saved, &v38);
        v38.z += *(f32 *)((u8 *)o + 0x84);
        psvec_sub(&v38, &saved, &v8);
        dist = lbl_8006D0B4((f32)(v8.x*v8.x + v8.y*v8.y + v8.z*v8.z));
        amount = lbl_8006D0B4(pool->one - (dist*pool->quarter)*(dist*pool->quarter));
        amount = t*amount;
        speed = lbl_8006D0B4(pool->one - amount*amount);
        if (speed > pool->epsilon)
            lbl_8006D5F0(&v8, speed);
        else
            v8.x = v8.y = v8.z = pool->zero;
        if (amount > pool->epsilon)
            lbl_8006D5F0(&v14, amount);
        else
            v14.x = v14.y = v14.z = pool->zero;
        psvec_add(&v14, &v8, &v14);
        lbl_8006D5F0(&v14, pool->four);
        psvec_add(&v14, &v20, &o->previous);
        psvec_sub(&o->previous, &saved, &v2c);
        lbl_8006DBAC((u8 *)o + 0xec);
        fn_8006E2B0(&v2c);
        dist = lbl_8006D0B4((f32)(v2c.x*v2c.x + v2c.y*v2c.y + v2c.z*v2c.z));
        speed = dist/pool->twenty;
        if (speed < pool->hundredth)
            speed = pool->hundredth;
        else if (speed > pool->point6)
            speed = pool->point6;
        fn_1_A33F0(*(s16 *)((u8 *)o + 4), speed);
        lbl_8006D5F0(&v2c, (f32)(pool->mph * *(f32 *)((u8 *)o + 8)));
        o->unk_1b4 += pool->six*v2c.x;
        *(f32 *)((u8 *)o + 0xc8) += pool->two*v2c.z;
        lbl_8006E1C0(&v2c);
        psvec_add(&v2c, (u8 *)o + 0x94, (u8 *)o + 0x94);
        o->flags_218 |= 0x40000000;
        if (*(u16 *)((u8 *)o + 0x214) == 0 && *(u8 *)((u8 *)o + 0x593) == 0) {
            f32 f = pool->twenty * *(f32 *)((u8 *)o + 0x30);
            if ((o->flags_218 & 0x200) == 0 && f > pool->twenty)
                f = pool->twenty;
            if (f > pool->scale * o->unk_5da)
                f = pool->scale * o->unk_5da;
            o->unk_4ac = f;
            o->unk_178 -= f;
            if (o->unk_178 < pool->zero) {
                if ((o->flags_218 & 0x10080) == 0)
                    *(u8 *)((u8 *)o + 0x593) = 60;
                o->flags_218 |= 0x80;
                o->unk_178 = pool->zero;
                o->unk_224 = pool->zero;
            }
        }
        fn_1_694A4(*(s16 *)((u8 *)o + 4), &v38, &v2c, speed/pool->ten);
    }
    lbl_8006DB30();
}
