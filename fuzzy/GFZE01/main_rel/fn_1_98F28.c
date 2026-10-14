/* Non-matching: best partial attempt (27.05% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/burner.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;
typedef struct {
    u8 r, g, b, a;
} Col4;
typedef struct {
    Vec3 pos;
    f32 size;
    s16 unk_10;
    u16 unk_12;
    Col4 color;
} Particle;

struct fn_1_98F28_Arg0 {
    u8 pad_0[0x8];
    u8 *unk_8;
};

#define FP(o, off) (*(f32 *)((u8 *)(o) + (off)))
#define MTXMEM ((f32 *)0xE0000000)

extern u32 lbl_1_bss_6EA0C;
extern u8 *lbl_801A6D00;

extern f32 fn_1_9A0A8(void *);
extern f32 fn_1_A71AC(void);
extern f32 fn_800728A8(s32, s32, s32, s32);
extern f32 lbl_8006D534(void *, void *);
extern f64 __fabs(f64);
extern s16 camera_get_mode(void);
extern s32 fn_1_54E34(void *, f32);
extern u16 fn_1_584AC(void);
extern u32 fn_1_6EC0(u8);
extern void fn_1_9E608(s32, void *);
extern u32 fn_800720B0(u32);
extern u32 lbl_8006D9D8(void *);
extern u32 lbl_8006DCA4(void);
extern u8 fn_1_58C4(void);
extern u8 fn_1_5910(void);
extern void *memset(void *, int, unsigned long);
extern void fn_1_6A0C(u8, void *);
extern void fn_1_9EA94(Particle *);
extern void fn_80072864(u32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_800735C8(s32, s32);
extern void fn_80073620(s32, s32);
extern void fn_80073678(u32);
extern void fn_80073778(void *, s32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_80074918(u8, s32, u8);
extern void lbl_8006D758(void);
extern void lbl_8006D7B0(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DF44(void);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E14C(f32);
extern void lbl_8006E15C(f32, f32, f32);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006E1C0(void *, void *);

void fn_1_98F28(struct fn_1_98F28_Arg0 *arg0) {
    u8 *obj = arg0->unk_8;
    u8 *tgt = *(u8 **)(obj + 0x48);
    Vec3 dir = *(Vec3 *)(obj + 0x468);
    f32 scale;
    f32 mul;
    f32 sp;
    s32 cnt;
    f32 side;
    f32 a71;
    Vec3 vA;
    Vec3 vB;
    Vec3 pos;
    u8 *emit;
    f32 f15;

    scale = fn_1_9A0A8(tgt);
    if (1.0f == scale) {
        f32 t = FP(obj, 0x4a4);
        if (t > 0.0f) {
            scale = t;
        }
    }
    sp = FP(obj, 0x74);
    mul = FP(obj, 0x24);
    if (sp > 1.0) {
        mul *= 1.0f + (sp - 1.0f) / 40.0f;
    }
    cnt = *(s32 *)(obj + 0x4a8);
    if (cnt != 0) {
        mul *= 1.0f + (f32)(cnt * cnt) / 900.0f / 5.0f;
    }
    side = 1.0f - 0.05f * (f32)(s32)(*(u32 *)(obj + 0x44) & 1);
    a71 = fn_1_A71AC();
    vA = *(Vec3 *)(obj + 0x4c);
    lbl_8006DCA4();
    lbl_8006E1C0(&vA, &vB);
    fn_80074788(0);
    fn_80072864(0);
    fn_800745A4(0, 1, 4, 60, 0, 125);
    fn_800734A8(0, 0, 0, 255);
    fn_80072AB0(0, 0, 0);
    fn_800735C8(0, 12);
    fn_80073620(0, 28);
    fn_80073C6C(0);
    fn_80072C24(0, 15, 14, 12, 15);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 6, 4, 7);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80073678(1);
    fn_80074660(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_80074918(1, 3, 0);
    fn_800720B0(0);
    fn_800728A8(1, 4, 1, 0);
    if (fn_1_6EC0(fn_1_5910())) {
        if (*(s16 *)(tgt + 4) == camera_get_mode()) {
            fn_80074918(1, 7, 0);
        }
    }

    emit = *(u8 **)(*(u8 **)&lbl_1_bss_38458->unk_8 + 0x88);
    if (FP(obj, 0x74) > 1.0f) {
        f32 sz;
        lbl_8006DCA4();
        lbl_8006DFC4(obj + 0x474);
        lbl_8006E0A4(obj + 0xc);
        sz = mul * ((0.8f + 1.6000001f / FP(obj, 0x74)) * side);
        if (*(s16 *)(tgt + 6) == 4) {
            sz *= 0.6f;
        }
        if (fn_1_54E34(emit + 8, sz)) {
            Particle p;
            f32 t;
            fn_80073778(*(void **)(emit + 0x24), 0);
            p.unk_12 = 0;
            p.pos = *(Vec3 *)(emit + 8);
            p.size = 0.70710677f * sz;
            p.unk_10 = *(s16 *)(obj + 0x70);
            t = FP(obj, 0x74) - 1.0f;
            if (t > 1.0f) {
                t = 1.0f;
            }
            p.color.r = (u8)(scale * (dir.x * t));
            p.color.g = (u8)(scale * (dir.y * t));
            p.color.b = (u8)(scale * (dir.z * t));
            p.color.a = 255;
            fn_1_9EA94(&p);
        }
    }

    if ((1.0f + vB.z) * FP(obj, 0x74) > 0.0f) {
        f32 sz;
        emit = *(u8 **)(*(u8 **)&lbl_1_bss_38458->unk_8 + 0x70);
        lbl_8006D9D8(obj + 0x58);
        lbl_8006D7B0();
        sz = (1.7f * side) * mul;
        if (*(s16 *)(tgt + 6) == 4) {
            sz *= 0.6f;
        }
        if (fn_1_54E34(emit + 8, sz)) {
            Particle p;
            f32 t;
            f32 k;
            psvec_set(&pos, MTXMEM[11], MTXMEM[7], MTXMEM[3]);
            if (pos.z < -1.8f) {
                lbl_8006DB74(lbl_801A6D00 + 0x60);
                lbl_8006D758();
                lbl_8006E14C((1.7f + pos.z) / pos.z);
                lbl_8006DFC4(lbl_801A6D00 + 0x60);
            }
            fn_80073778(*(void **)(emit + 0x24), 0);
            p.unk_12 = 0;
            p.pos = *(Vec3 *)(emit + 8);
            p.size = 0.70710677f * sz;
            p.unk_10 = 0;
            t = FP(obj, 0x74);
            if (t > 1.0f) {
                t = 1.0f;
            }
            k = 0.5f * (1.0f + vB.z);
            t = t * k;
            p.color.r = (u8)(scale * (dir.x * t));
            p.color.g = (u8)(scale * (dir.y * t));
            p.color.b = (u8)(scale * (dir.z * t));
            p.color.a = 255;
            fn_1_9EA94(&p);
        }
    }

    if (vB.z > 0.0f) {
        sp = FP(obj, 0x74);
        if (sp > 1.2f) {
            f32 ex = sp - 1.2f;
            f32 sz;
            emit = *(u8 **)(*(u8 **)&lbl_1_bss_38458->unk_8 + 0xb8);
            lbl_8006D9D8(obj + 0x58);
            lbl_8006D7B0();
            psvec_set(&pos, MTXMEM[11], MTXMEM[7], MTXMEM[3]);
            if (MTXMEM[11] < 0.0f) {
                sz = a71 * ((0.24f + 0.64f * vB.z) * (-0.2f * MTXMEM[11]));
                if (fn_1_54E34(emit + 8, sz)) {
                    Particle p;
                    f32 k;
                    f32 q;
                    if (pos.z < -2.1f) {
                        lbl_8006DB74(lbl_801A6D00 + 0x60);
                        lbl_8006D758();
                        lbl_8006E14C((2.0f + pos.z) / pos.z);
                        lbl_8006DFC4(lbl_801A6D00 + 0x60);
                    }
                    fn_80073778(*(void **)(emit + 0x24), 0);
                    p.unk_12 = 0;
                    p.pos = *(Vec3 *)(emit + 8);
                    p.size = 0.70710677f * sz;
                    k = (2.0f * ex) / (-0.2f * pos.z);
                    if (k > 0.5f) {
                        k = 0.5f;
                    }
                    k = k * vB.z;
                    q = 0.5f + 0.5f * (f32)(s32)(*(u32 *)(obj + 0x44) & 1);
                    k = k * q;
                    p.color.r = (u8)(scale * (dir.x * k));
                    p.color.g = (u8)(scale * (dir.y * k));
                    p.color.b = (u8)(scale * (dir.z * k));
                    p.color.a = 255;
                    lbl_8006E15C(1.0f, 0.6f, 1.0f);
                    psvec_set(&pos, MTXMEM[11], MTXMEM[7], MTXMEM[3]);
                    p.unk_10 = (s16)((32768.0f * pos.x + 24576.0f * pos.y) / pos.z);
                    fn_1_9EA94(&p);
                    p.size = p.size * 0.75f;
                    p.unk_10 = (s16)((53248.0f * pos.x + 40960.0f * pos.y) / pos.z) + 0x6000;
                    fn_1_9EA94(&p);
                }
            }
        }
    }

    {
        Particle buf[21];
        f32 fa;
        f32 g;
        f32 fabsv;
        f32 ff;

        memset(buf, 0, 0x1e1);
        lbl_8006DCA4();
        lbl_8006E1B0(obj + 0x58, &pos);
        fabsv = lbl_8006D534(&pos, &vB);
        ff = (f32)(1.0 - __fabs(fabsv));
        fa = -(((0.11313709f * (10.0f + 80.0f * ff)) * mul) / (pos.z * a71));
        if (fa > 0.05f) {
            Col4 col;
            Particle *pp;
            s32 n;
            f32 r2;
            s16 ang;
            u8 *trail;
            u8 *em2;
            f32 sz;
            f32 pd;
            f32 pe;
            f32 pf;
            f32 sp2;

            if (fa > 0.15f) {
                g = 1.0f;
            } else {
                g = 9.999999f * (fa - 0.05f);
            }
            f15 = FP(obj, 0x74);
            pd = dir.y;
            pe = dir.z;
            sz = (0.11313709f * (1.0f + 0.9f * f15)) * mul;
            em2 = *(u8 **)(*(u8 **)&lbl_1_bss_38458->unk_8 + 0x168);
            col.r = (u8)(scale * (dir.x * g));
            col.g = (u8)(scale * (dir.y * g));
            col.b = (u8)(scale * (dir.z * g));
            col.a = 255;
            ang = *(s16 *)(obj + 0x70);
            pp = buf;
            n = 0;
            pos = *(Vec3 *)(obj + 0x58);
            fn_1_6A0C(fn_1_5910(), lbl_801A6D00);
            MTXMEM[3] = FP(obj, 0x58);
            MTXMEM[7] = FP(obj, 0x5c);
            MTXMEM[11] = FP(obj, 0x60);
            lbl_8006DF44();
            sp2 = 0;
            pf = 0;
            {
                s32 j = 0;
                while (f15 > 0.0f) {
                    lbl_8006E1B0(&pos, obj + 0x78 + lbl_1_bss_6EA08 * 0xfc + j);
                    pp->pos = pos;
                    pp->pos.x += 0.2f * ((f32)fn_1_584AC() / 32767.0f - 0.5f);
                    pp->pos.y += 0.2f * ((f32)fn_1_584AC() / 32767.0f - 0.5f);
                    pp->pos.z += 0.2f * ((f32)fn_1_584AC() / 32767.0f - 0.5f);
                    pp->size = 0.70710677f * sz;
                    pp->unk_10 = ang;
                    if (f15 < 4.0f) {
                        f32 w = f15 * 0.25f;
                        pp->color.r = (u8)(scale * (g * (dir.x * w)));
                        pp->color.g = (u8)(scale * (g * (pd * w)));
                        pp->color.b = (u8)(scale * (g * (pe * w)));
                        pp->color.a = 255;
                    } else {
                        pp->color = col;
                    }
                    f15 -= 0.5f;
                    pp++;
                    pos.x += 0.4f * (vA.x * sz);
                    pos.y += 0.4f * (vA.y * sz);
                    pos.z += 0.4f * (vA.z * sz);
                    j += 12;
                    n++;
                    sz *= 0.95f;
                    ang += 0x2345;
                }
            }
            fn_80073778(*(void **)(em2 + 0x24), 0);
            lbl_8006DCA4();
            if (n > 0) {
                fn_1_9E608(n, buf);
            }
        }
    }

    if (fn_1_58C4() < 2) {
        if (*(s16 *)(tgt + 4) == camera_get_mode()) {
            if (fn_1_6EC0(fn_1_5910())) {
                if (lbl_1_bss_6EA0C == 0 && lbl_1_bss_6EA08 >= 3) {
                    lbl_1_bss_6EA0C = 1;
                }
                if (lbl_1_bss_6EA0C != 0) {
                    s32 i;
                    u8 *row = obj;
                    for (i = 0; i < 4; i++) {
                        Particle buf2[21];
                        Col4 col;
                        Particle *pp;
                        u8 *em2;
                        s32 n;
                        s32 off;
                        s32 k;
                        s16 ang;
                        f32 sz;
                        f32 g;
                        f32 f15b;
                        f32 pd;
                        f32 pe;
                        f32 px;

                        memset(buf2, 0, 0x1e1);
                        lbl_8006DCA4();
                        lbl_8006E1B0(obj + 0x58, &pos);
                        f15b = FP(obj, 0x74);
                        g = 1.0f;
                        em2 = *(u8 **)(*(u8 **)&lbl_1_bss_38458->unk_8 + 0x168);
                        sz = (0.11313709f * (1.0f + 0.9f * f15b)) * mul;
                        if (i < lbl_1_bss_6EA08) {
                            k = i + 4 - lbl_1_bss_6EA08;
                        } else {
                            k = i - lbl_1_bss_6EA08;
                        }
                        g = g * (0.25f * (f32)k);
                        px = dir.x;
                        pd = dir.y;
                        pe = dir.z;
                        col.r = (u8)(scale * (px * g));
                        col.g = (u8)(scale * (pd * g));
                        col.b = (u8)(scale * (pe * g));
                        col.a = 255;
                        ang = *(s16 *)(obj + 0x70);
                        pp = buf2;
                        n = 0;
                        pos = *(Vec3 *)(obj + 0x58);
                        fn_1_6A0C(fn_1_5910(), lbl_801A6D00);
                        MTXMEM[3] = FP(obj, 0x58);
                        MTXMEM[7] = FP(obj, 0x5c);
                        MTXMEM[11] = FP(obj, 0x60);
                        off = 0;
                        while (f15b > 0.0f) {
                            Vec3 *cur = (Vec3 *)(row + 0x78 + off);
                            Vec3 *prev = (Vec3 *)(obj + 0x78 + lbl_1_bss_6EA08 * 0xfc + off);
                            f32 dx = cur->x - prev->x;
                            f32 dy = cur->y - prev->y;
                            f32 dz = cur->z - prev->z;
                            f32 d2 = dx * dx + dy * dy + dz * dz;
                            if (d2 >= 0.05) {
                                f32 q;
                                lbl_8006E1B0(cur, pp);
                                pp->pos.x += 0.15f * ((f32)fn_1_584AC() / 32767.0f - 0.5f);
                                pp->pos.y += 0.15f * ((f32)fn_1_584AC() / 32767.0f - 0.5f);
                                pp->pos.z += 0.15f * ((f32)fn_1_584AC() / 32767.0f - 0.5f);
                                q = 2.0f * d2;
                                if (q < 0.1f) {
                                    q = 0.1f;
                                } else if (q > 1.0f) {
                                    q = 1.0f;
                                }
                                pp->size = (0.70710677f * sz) * q;
                                pp->unk_10 = ang;
                                if (f15b < 4.0f) {
                                    f32 w = f15b * 0.25f;
                                    pp->color.r = (u8)(scale * (g * (px * w)));
                                    pp->color.g = (u8)(scale * (g * (pd * w)));
                                    pp->color.b = (u8)(scale * (g * (pe * w)));
                                    pp->color.a = 255;
                                } else {
                                    pp->color = col;
                                }
                                ang += 0x2345;
                                n++;
                                pp++;
                                pos.x += 0.4f * (vA.x * sz);
                                pos.y += 0.4f * (vA.y * sz);
                                pos.z += 0.4f * (vA.z * sz);
                                sz *= 0.95f;
                            }
                            f15b -= 0.5f;
                            off += 12;
                        }
                        fn_80073778(*(void **)(em2 + 0x24), 0);
                        lbl_8006DCA4();
                        if (n > 0) {
                            fn_1_9E608(n, buf2);
                        }
                        row += 0xfc;
                    }
                }
            }
        }
    }
}
