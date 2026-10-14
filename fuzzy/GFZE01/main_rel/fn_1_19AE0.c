/* Non-matching: best partial attempt (59.56% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/stcoli.h"

typedef struct { f32 x, y, z; } V3;

typedef struct {
    u32 count;
    u32 f04[7];
    u32 f20, f24, f28, f2c, f30, f34, f38, f3c;
    u32 f40, f44, f48, f4c;
} Ent;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1c;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
    f32 f30;
    f32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
} CfgEnt;

typedef struct {
    u32 h00[0x34c / 4];
    CfgEnt ents[8];
    u32 count;
} Mgr;

typedef struct {
    u32 pad_0[2];
    void *f08;
    u32 pad_c[0x14];
    f32 f20;
    u8 pad_24[0x14];
    f32 f38;
    f32 f3c;
    f32 f40;
    f32 f44;
} P3;

typedef struct {
    u8 pad_0[0x30];
    V3 v30;
    f32 f3c;
} Hit;

typedef struct {
    u8 pad_0[0x8];
    f32 f8;
    f32 fc;
    u8 pad_10[0x8];
    f32 f18;
    f32 f20;
    u8 pad_24[0x18];
    f32 f38;
    f32 f3c;
    f32 f40;
    f32 f44;
} Pool;

typedef struct { Ent *f0; Ent *f4; } Stk;

extern struct { u32 unk_0; } lbl_801A66CC;
extern void *lbl_801A6D00[];
extern Pool lbl_1_rodata_6C8;
extern s16 fn_1_7B054(void);
extern void fn_1_18784(u32, u32, u32, u32);
extern u32 fn_1_192E8(u32, u32, void *, void *, u32, u32, u32, u32, void *, u32);
extern u32 fn_1_1ACC0(u32, u32, u32, u32);
extern u32 fn_1_17B5C(u32, u32, s32, f32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DF44(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006E1B0(void *, void *);

static f32 abf(f32 v) { return v < 0.0f ? -v : v; }

void fn_1_19AE0(V3 *p0, V3 *p1, u32 p2, P3 *p3, V3 *p4, Stk *p5, u32 p6, s32 p7) {
    Pool *pool = &lbl_1_rodata_6C8;
    Mgr *g;
    CfgEnt *ent;
    CfgEnt *e0;
    CfgEnt *e1;
    CfgEnt *dst;
    Hit *hit;
    V3 A;
    V3 B;
    V3 t1;
    V3 t2;
    V3 t3;
    V3 sA;
    V3 sB;
    V3 sC;
    V3 sD;
    f32 sx;
    f32 f30;
    f32 f31;
    f32 f29;
    f32 f26;
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 c0;
    f32 c1;
    f32 c2;
    f32 c3;
    u32 flg;
    u32 b1;
    u32 b2;
    u32 bits;
    u32 w;
    s32 m22;
    s32 f23;
    s32 f16;
    s32 f17;
    s32 f15;
    s32 f15b;
    s32 i;
    s32 n;
    u32 la;
    u32 lb;
    u32 lc;
    u32 l0;
    u32 l1;
    u32 l2;

    flg = 0xE0000000;
    b1 = 0;
    b2 = 0;
    f30 = pool->f20;
    f29 = 0.0f;
    c0 = 0.0f;
    c1 = 0.0f;
    c2 = 0.0f;
    c3 = 0.0f;
    fn_1_18784(p2, (u32)p3, (u32)p4, p6);
    m22 = 0;
    if (p5 != 0 && fn_1_7B054() != 8) {
        m22 = 1;
    }
    lbl_8006DAEC();
    lbl_8006DF44();
    g = (Mgr *)lbl_801A66CC.unk_0;
    hit = (Hit *)((u8 *)g + 0x7b0 + (g->h00[0x1d0 / 4] << 6));
    f1 = p3->f3c;
    f0 = p3->f40;
    if (f0 <= f1) {
        f0 = f1;
    }
    hit->f3c = f0;
    hit->v30 = *p4;
    lbl_8006DB74((void *)hit);
    lbl_8006E1B0((void *)p0, (void *)&A);
    n = (s32)g->h00[0x5ac / 4];
    if (n > 0) {
        f1 = pool->f20;
        f0 = p4->x;
        f31 = f1 * f0;
        ent = (CfgEnt *)((u8 *)g + 0x34c);
        for (i = 0; i < n; i++) {
            if (ent->f0c != 0) {
                lbl_8006E1B0((void *)((u8 *)ent + 0x38), (void *)&g->h00[0xd4 / 4]);
                g = (Mgr *)lbl_801A66CC.unk_0;
                f0 = f31 - pool->f3c;
                f1 = abf(*(f32 *)&g->h00[0xd4 / 4]);
                if (f1 <= f0) {
                    f1 = abf(*(f32 *)&g->h00[0xd8 / 4]);
                    f0 = p3->f40;
                    if (f1 > f0) {
                        f0 = p3->f3c;
                        if (f1 <= f0) {
                            if (p5 != 0) {
                                w = ((u32 *)g->ents)[144 + i];
                                ((u32 *)p5->f0)[w] &= 0x3FFF0000;
                                if ((ent->f0c & 0x180000) != 0) {
                                    p5->f0->f2c = 1;
                                }
                            }
                            ent->f0c = 0;
                        }
                    }
                }
            }
            ent++;
        }
    }
    lbl_8006E1B0((void *)p0, (void *)&A);
    A.x = A.x / p4->x;
    lbl_8006E1B0((void *)p1, (void *)&B);
    B.x = B.x / p4->x;
    lbl_8006DB30();
    g = (Mgr *)lbl_801A66CC.unk_0;
    e0 = &g->ents[0];
    e1 = &g->ents[1];
    f17 = (p2 >> 29) & 1;
    f15 = f17;
    if (p5 != 0) {
        w = p5->f4->f04[5];
        if (w & 0x00010000) {
            f17 = 0;
        }
        if (w & 0x00020000) {
            f15 = 0;
        }
    }
    if (!(p3->pad_0[0] & 0x200000) && !(p3->pad_0[0] & 0x100000)) {
        f1 = *(f32 *)&g->h00[0x1b4 / 4];
        f2 = pool->f20;
        f0 = f1 / p4->x;
        f3 = B.x;
        f30 = f2 + f0;
        f1 = -f30;
        if (f1 <= f3) {
            if (!(f30 >= f3)) {
                if (f30 < A.x) {
                    flg = 0;
                }
            }
        } else {
            if (f1 > A.x) {
                flg = 0;
            }
        }
        if ((s32)g->h00[0x1b8 / 4] > 1) {
            f1 = pool->f40;
            f0 = A.y;
            if (f0 <= f1) {
                f0 = B.y;
                if (f0 <= f1) {
                    flg = flg;
                } else {
                    flg &= 0xE;
                }
            } else {
                f0 = B.y;
                if (f0 <= f1) {
                    flg = flg;
                } else {
                    flg &= 0xE;
                }
            }
        }
    }
    if (fn_1_7B054() == 3) {
        g = (Mgr *)lbl_801A66CC.unk_0;
        if ((s32)g->h00[0x1c0 / 4] >= 0x7c && (s32)g->h00[0x1c0 / 4] <= 0x8b) {
            f1 = pool->f44;
            f0 = A.y;
            if (f0 <= f1) {
                f0 = B.y;
                if (f0 <= f1) {
                    flg = flg;
                } else {
                    flg &= 0xE;
                }
            } else {
                f0 = B.y;
                if (f0 <= f1) {
                    flg = flg;
                } else {
                    flg &= 0xE;
                }
            }
        }
    }
    f1 = A.x;
    f0 = pool->f8;
    if (f1 > f0) {
        f15 = 0;
    }
    if (A.x == 0.0f) {
        f17 = 0;
    }
    if (!(0.0f > A.y)) {
        flg &= 0xE;
    }
    f23 = 0;
    if (-f30 <= B.x) {
        if (!(f30 >= B.x)) {
            if (f30 < A.x) {
                f23 = 1;
            }
        }
    } else {
        if (-f30 > A.x) {
            f23 = 1;
        }
    }
    if (p5 != 0) {
        s32 cnt = p5->f0->count;
        s32 cur = p5->f4->count;
        u32 cw = p5->f4[cnt].f3c;
        int hit2 = 1;
        i = 0;
        if (cnt > cur && (cw & 0x10000000)) {
            hit2 = 1;
        } else {
            if (g->h00[0x1d8 / 4] == 0) {
                f23 = 0;
                hit2 = 0;
            } else {
                while (i < cnt && (p5->f4[i].f3c & 0x20000000)) {
                    i++;
                }
                if (i >= cnt) {
                    f23 = 0;
                    hit2 = 0;
                }
            }
        }
        if (hit2) {
            if (!(cw & 0x2a0000)) {
                cw |= 0x2a000000;
            }
            bits = cw;
            if ((((p3->pad_0[0] >> 6) & 0x1F) == ((bits & (p3->pad_0[0] >> 6)) & 0x1F))) {
                if (p5->f4[i].f04[6] == (u32)p3) {
                    f23 = 1;
                } else {
                    f23 = fn_1_17B5C(p5->f4[i].f4c, lbl_1_bss_3BE0->unk_8, p7, pool->f38);
                }
            } else {
                f23 = 0;
            }
        }
    }
    f2 = B.y;
    f3 = A.y;
    f0 = pool->f8;
    f1 = f2 - f3;
    f29 = f2 / f1;
    if (f2 <= f0) {
        if (f3 <= f2) {
            c0 = f29;
            *(u32 *)&c0 &= 0x7F800000;
            if ((*(u32 *)&c0 - 0x7F800000) != 0) {
                b2 |= 0x2000;
                if (e1->f0c != 0) {
                    if (f29 < e1->f10) {
                        b1 = 0x2000;
                    }
                } else {
                    b1 = 0x2000;
                }
            }
        }
    } else {
        if (f3 > f2) {
            if (m22 == 0) {
                if (f29 >= pool->fc) {
                    c1 = f29;
                    *(u32 *)&c1 &= 0x7F800000;
                    if ((*(u32 *)&c1 - 0x7F800000) != 0) {
                        b2 |= 0x2000;
                        if (e1->f0c != 0) {
                            if (f29 < e1->f10) {
                                b1 = 0x2000;
                            }
                        } else {
                            b1 = 0x2000;
                        }
                    }
                } else {
                    b1 = 0;
                    c2 = f29;
                }
                f3 = f29;
                if (f3 >= pool->f8) {
                    if (f29 >= pool->f8) {
                        f29 = f29;
                    }
                }
            } else {
                if (f23 == 0) {
                    if (f29 >= pool->fc) {
                        c3 = f29;
                        *(u32 *)&c3 &= 0x7F800000;
                        if ((*(u32 *)&c3 - 0x7F800000) != 0) {
                            b2 |= 0x200;
                            if (e0->f0c != 0) {
                                if (f29 < e0->f10) {
                                    b1 = 0x200;
                                }
                            } else {
                                b1 = 0x200;
                            }
                        }
                    }
                }
            }
        }
    }
    if (f23 != 0 && f16 == 0 && ((b1 & 0x2) == 0)) {
        e1->f0c = e1->f0c;
    }
    if (m22 != 0 && b1 == 0) {
        if (0.0f >= A.y || f23 != 0) {
            s32 r;
            if (p5 == 0) {
                r = 0;
            } else {
                s32 cnt = p5->f0->count;
                s32 cur = p5->f4->count;
                u32 cw = p5->f4[cnt].f3c;
                if (cur <= cnt) {
                    r = 0;
                } else if (cw & 0x40000000) {
                    u32 mask = 0x3e0;
                    u32 k;
                    if ((s32)g->h00[0x1b8 / 4] == cur) {
                        mask |= 0xc00;
                    }
                    k = p3->pad_0[0] & mask;
                    if (k == (k & cw)) {
                        if (p5->f4[cnt].f04[6] == (u32)p3) {
                            r = 1;
                        } else {
                            r = fn_1_17B5C(p5->f4[cnt].f4c, lbl_1_bss_3BE0->unk_8, p7, pool->f38);
                        }
                    } else {
                        r = 0;
                    }
                } else {
                    r = 0;
                }
                if (r == 0) {
                    if (fn_1_7B054() != 0x10) {
                        if (fn_1_7B054() != 0x1c) {
                            r = 1;
                        } else {
                            if (p7 < 0x74) {
                                r = 1;
                            } else if (p7 > 0x90) {
                                r = 1;
                            } else {
                                r = 1;
                            }
                        }
                    } else {
                        r = 1;
                    }
                }
            }
            if (r != 0) {
                if (f16 == 0) {
                    b2 |= 0x200;
                    if (e0->f0c == 0) {
                        b1 = 0x200;
                        f29 = pool->f8;
                    }
                }
            }
        }
    }
    if (b1 != 0) {
        if (b1 & 0x40) {
            dst = e0;
        } else {
            dst = e1;
        }
        psvec_sub_scale_add(&A.x, &B.x, f29, &t1.x, &t2.x);
        if (abf(t2.x) <= f30) {
            goto L_write;
        }
        if (!(b1 & 0x40)) {
            goto L_fail;
        }
        if (!(p2 & 0x40)) {
            goto L_fail;
        }
        if (f23 == 0) {
            goto L_fail;
        }
        if (t2.x > pool->f8) {
            if (p3->pad_0[0] & 0x100000) {
                if (!(p5->f4[p5->f0->count].f3c & 0x20000000)) {
                    goto L_write;
                }
            }
            goto L_fail;
        }
        if (!(t2.x <= pool->f8)) {
            goto L_fail;
        }
        if (p3->pad_0[0] & 0x200000) {
            if (!(p5->f4[p5->f0->count].f3c & 0x40000000)) {
                goto L_write;
            }
        }
    L_fail:
        b1 = 0;
        b2 = 0;
        goto L_after;
    L_write:
        psvec_sub_scale_add(&p0->x, &p1->x, f29, &t1.x, &dst->f14);
        if (b1 & 0x40) {
            f0 = pool->f8;
            dst->f20 = -((f32 *)lbl_801A6D00[0])[1];
            dst->f24 = -((f32 *)lbl_801A6D00[0])[5];
            dst->f28 = -((f32 *)lbl_801A6D00[0])[9];
            f3 = -A.y;
            if (f3 < f0) {
                dst->f2c = f3 * *(f32 *)(0xE0000000 + 0x4);
                dst->f30 = f3 * *(f32 *)(0xE0000000 + 0x14);
                dst->f34 = f3 * *(f32 *)(0xE0000000 + 0x24);
            } else {
                dst->f2c = f0;
                dst->f30 = f0;
                dst->f34 = f0;
            }
        } else {
            f0 = pool->f8;
            dst->f20 = ((f32 *)lbl_801A6D00[0])[1];
            dst->f24 = ((f32 *)lbl_801A6D00[0])[5];
            dst->f28 = ((f32 *)lbl_801A6D00[0])[9];
            f3 = -A.y;
            if (f3 > f0) {
                dst->f2c = f3 * *(f32 *)(0xE0000000 + 0x4);
                dst->f30 = f3 * *(f32 *)(0xE0000000 + 0x14);
                dst->f34 = f3 * *(f32 *)(0xE0000000 + 0x24);
            } else {
                dst->f2c = f0;
                dst->f30 = f0;
                dst->f34 = f0;
            }
        }
        dst->f0c = 0x200;
        dst->f10 = f29;
        g = (Mgr *)lbl_801A66CC.unk_0;
        dst->f00 = g->h00[0x1bc / 4];
        dst->f04 = g->h00[0x1c0 / 4];
        dst->f08 = *(f32 *)&g->h00[0x1c4 / 4];
        if (p5 != 0) {
            dst->f44 = p5->f0[p5->f0->count].f3c;
        } else {
            dst->f44 = 0;
        }
    L_after:
        if (b1 & 0x40) {
            b1 = 0;
            flg = 0;
        }
    }
    if (p3->pad_0[0] & 0x200000) {
        f16 = (p3->pad_0[0] >> 19) & 1;
        if (f16) {
            sA = A;
            sB = B;
            sC = t1;
            sD = t2;
            sx = p4->x;
            lbl_8006DAEC();
            lbl_8006DBAC(p3->f08);
            lbl_8006DAEC();
            lbl_8006DF44();
            p4->x = ((f32 *)p3->f08)[0xc];
            lbl_8006E1B0((void *)p0, (void *)&A);
            A.x = A.x / p4->x;
            lbl_8006E1B0((void *)p1, (void *)&B);
            B.x = B.x / p4->x;
            lbl_8006DB30();
        }
        if (!(-f30 > A.x)) {
            flg &= ~1;
        }
        if (f15) {
            if (fn_1_192E8((u32)p0, (u32)p1, (void *)&A, (void *)&B, (u32)p3, (u32)p4,
                           (u32)p5, (u32)p7, (void *)&flg, (b1 & 2) ? 1 : 0)) {
                b1 |= 0x8000;
            }
        }
        if (f16) {
            lbl_8006DB30();
            A = sA;
            B = sB;
            t1 = sC;
            t2 = sD;
            p4->x = sx;
        }
    }
    if (p3->pad_0[0] & 0x100000) {
        f15b = (p3->pad_0[0] >> 18) & 1;
        if (f15b) {
            sA = A;
            sB = B;
            sC = t1;
            sD = t2;
            sx = p4->x;
            lbl_8006DAEC();
            lbl_8006DBAC(p3->f08);
            lbl_8006DAEC();
            lbl_8006DF44();
            p4->x = ((f32 *)p3->f08)[0xc];
            lbl_8006E1B0((void *)p0, (void *)&A);
            A.x = A.x / p4->x;
            lbl_8006E1B0((void *)p1, (void *)&B);
            B.x = B.x / p4->x;
            lbl_8006DB30();
        }
        if (!(f30 > A.x)) {
            flg &= ~2;
        }
        if (f17) {
            if (fn_1_192E8((u32)p0, (u32)p1, (void *)&A, (void *)&B, (u32)p3, (u32)p4,
                           (u32)p5, (u32)p7, (void *)&flg, (b1 & 2) ? 1 : 0)) {
                b1 |= 0x4000;
            }
        }
        if (f15b) {
            lbl_8006DB30();
            A = sA;
            B = sB;
            t1 = sC;
            t2 = sD;
            p4->x = sx;
        }
    }
    if (p2 & 0x80) {
        if (fn_1_7B054() == 0x26) {
            if (b1 == 0 && !(flg & 2) && A.x > 0.0f) {
                fn_1_1ACC0((u32)p0, (u32)p1, (u32)p3, (u32)p4);
            }
        }
        if (!(flg & 0x80000000) && !(A.x > 0.0f)) {
            fn_1_1ACC0((u32)p0, (u32)p1, (u32)p3, (u32)p4);
        }
    }
    if ((((flg | b1) & 0xE0000000) == 0xE0000000) && ((p2 & 0x104) == 0x104)) {
        g = (Mgr *)lbl_801A66CC.unk_0;
        if ((s32)g->h00[0x1c0 / 4] == 0x6b && fn_1_7B054() == 1) {
            u32 *ob = (u32 *)lbl_1_bss_3BE0->unk_0;
            u32 *tb = *(u32 **)(ob + 0xc / 4);
            u32 *sub = *(u32 **)(tb + 0x508 / 4);
            f0 = pool->f20;
            f2 = p0->x;
            l0 = sub[0x18 / 4];
            l1 = sub[0x1c / 4];
            l2 = sub[0x20 / 4];
            f1 = *(f32 *)&l0;
            f0 = f1 - f0;
            if (f2 >= f0) {
                f3 = p1->x;
                f1 = f3 - f0;
                f0 = f3 - f2;
                f26 = f1 / f0;
                c0 = f26;
                *(u32 *)&c0 &= 0x7F800000;
                if ((*(u32 *)&c0 - 0x7F800000) == 0) {
                    f26 = pool->f8;
                }
                f3 = p1->y;
                f0 = p0->y;
                f1 = *(f32 *)&l1;
                f2 = f0 - f3;
                f2 = f26 * f2;
                f2 = f3 + f2;
                f1 = f2 - f1;
                f1 = abf(f1);
                if (f1 <= p3->f40) {
                    g = (Mgr *)lbl_801A66CC.unk_0;
                    ent = (CfgEnt *)((u8 *)g + 0x34c + g->count * 0x48);
                    ent->f0c = 0;
                    ent->f10 = pool->f18;
                    g->count = g->count + 1;
                    ent->f38 = l0;
                    ent->f3c = l1;
                    ent->f40 = l2;
                    psvec_sub_scale_add(&p0->x, &p1->x, f26, &t3.x, &ent->f14);
                    f1 = p0->x;
                    f0 = f1 - *(f32 *)&l0;
                    f2 = pool->f8;
                    if (f0 > f2) {
                        f1 = -f0;
                        f0 = f1 - pool->f20;
                        ent->f20 = f0;
                        ent->f24 = f2;
                        ent->f28 = f2;
                    } else {
                        ent->f20 = f2;
                        ent->f24 = f2;
                        ent->f28 = f2;
                    }
                    ent->f10 = f26;
                    ent->f0c = 0x400;
                    dst = ent;
                    g = (Mgr *)lbl_801A66CC.unk_0;
                    dst->f00 = g->h00[0x1bc / 4];
                    dst->f04 = g->h00[0x1c0 / 4];
                    dst->f08 = *(f32 *)&g->h00[0x1c4 / 4];
                    if (p5 != 0) {
                        dst->f44 = p5->f0[p5->f0->count].f3c;
                    } else {
                        dst->f44 = 0;
                    }
                }
            }
        }
    }
    g = (Mgr *)lbl_801A66CC.unk_0;
    if (g->h00[0x1d0 / 4] < 3) {
        g->h00[0x1d0 / 4] = g->h00[0x1d0 / 4] + 1;
    }
    if (p5 != 0) {
        Ent *ce = p5->f0 + p5->f0->count;
        la = b1 & 0x40 ? 4 : 0;
        lb = (b1 >> 5) & 7;
        lc = (b2 >> 5) & 7;
        ce->f04[6] = (u32)p3;
        ce->f2c = p4->x;
        ce->f3c = p3->pad_0[0] | la;
        if (flg || lb || lc) {
            ce->f3c |= flg | lb | lc | 0x10000000;
        }
        if (lb < 0) {
            ce->f3c &= ~0x00078000;
            ce->f3c |= 0x8000;
        } else if (lb & 1) {
            ce->f3c &= ~0x00078000;
            ce->f3c |= 0x4000;
        }
        ce->f4c = (u32)p7;
        if (p5->f0->count < 3) {
            p5->f0->count = p5->f0->count + 1;
        }
    }
}
