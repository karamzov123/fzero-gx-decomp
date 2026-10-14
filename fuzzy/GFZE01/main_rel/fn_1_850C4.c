/* Non-matching: best partial attempt (72.90% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/car.h"

typedef struct Sig_fn_1_25004_Fn_1_25004_Obj {
    u32 flags00;
    s16 field04;
    u8 pad06[0x8e];
    f32 field94;
    f32 field98;
    f32 field9c;
    f32 fielda0;
    f32 fielda4;
    f32 fielda8;
    u8 padac[0xd0];
    f32 field17c;
    u8 pad180[0x4];
    f32 field184;
    u8 pad188[0x9c];
    f32 field224;
    u8 pad228[0x24c];
    u8 field474;
    u8 pad475[0x117];
    u32 flags58c;
} Sig_fn_1_25004_Fn_1_25004_Obj;

typedef struct Sig_fn_1_250F8_Fn_1_250F8 {
    u32 flags;
    u8 pad04[0x180];
    f32 field184;
    u8 pad188[0x88];
    u16 field210;
    u8 pad212[0x01];
    u8 field213;
    u8 pad214[0x03];
    u8 field217;
    u8 pad218[0x29A];
    u8 field4b2;
    u8 pad4b3[0xD9];
    u32 field58c;
} Sig_fn_1_250F8_Fn_1_250F8;

typedef struct { f32 x, y, z; } Vec3;

typedef struct Sym390 {
    u8 pad00[0x390];
    u32 flags390;
} Sym390;

typedef struct Elem {
    u32 f00;
    s16 f04;
    u8 pad06[0x76];
    f32 x;
    f32 y;
    f32 z;
    u8 pad88[0x0C];
    u8 pad94[0xEF];
    f32 f184;
    u8 pad188[0x64];
    u8 pad1EC[0x1A0];
    u8 pad38C[0x04];
    u32 f390;
    u8 pad394[0x108];
    void *owner;
    u8 pad4A0[0xEC];
    u32 f58C;
    u8 pad590[0x90];
} Elem;

typedef struct Owner {
    u8 pad00[0x115];
    u8 lim;
    u8 pad116[0x02];
    u32 val118;
} Owner;

typedef struct Obj {
    u32 flags00;
    u8 field04;
    u8 pad05[0x1400];
    u8 mask;
    u8 pad1406[0x02];
    Vec3 slot[5];
} Obj;

typedef struct Mgr {
    u8 pad00[0x18];
    Elem *base;
    u8 pad1C[0x0E];
    s8 count;
    u8 pad2B[0x125];
    void (*fn150)(void *);
    void (*fn154)(void *);
    u32 unk158;
    u32 unk15C;
} Mgr;

extern f32 lbl_1_rodata_3A50[17];
extern u32 fn_1_239C4(Elem *, Elem *);
extern u32 fn_1_24A4C(Elem *);
extern u32 fn_1_266A8(Elem *);
extern u32 fn_1_68B6C(s8, s8);
extern void fn_1_8B9B8(void *);
extern u8 fn_1_3F854(void);
extern u8 * lbl_8006DBAC(u8 *);
extern void * fn_1_868C0(s8);
extern void fn_1_8A1B4(Elem *, void *, void *);

void fn_1_850C4(Obj *obj, f32 a1, f32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
    Mgr *p = (Mgr *)&lbl_1_bss_6D820;
    u32 i, j;
    u32 f = obj->flags00;
    u32 t10 = f & 0x400;
    s32 s10 = (f >> 10) & 1;
    u8 flag = 0;

    if (t10) {
        if (f & 0x4000000) {
            obj = 0;
        } else if (!(f & 0x20000) || t10) {
            obj->flags00 |= 0x200000;
            flag = 1;
        }
    }

    for (i = 0; i < p->count; i++) {
        for (j = i + 1; j < p->count; j++) {
            if (fn_1_239C4(p->base + i, p->base + j)) {
                Sym390 *o1 = (Sym390 *)fn_1_868C0((s8)p->base[i].f04);
                Sym390 *o2 = (Sym390 *)fn_1_868C0((s8)p->base[j].f04);
                if (o1->flags390 & 0x400) {
                    fn_1_25004((Sig_fn_1_25004_Fn_1_25004_Obj *)(p->base + i));
                }
                if (o2->flags390 & 0x400) {
                    fn_1_25004((Sig_fn_1_25004_Fn_1_25004_Obj *)(p->base + j));
                }
                fn_1_68B6C((s8)i, (s8)j);
            }
        }
    }

    for (i = 0; i < p->count; i++) {
        Elem *e = p->base + i;
        if (e->f58C & 0x10000000) {
            lbl_8006DBAC((u8 *)e->f00);
            *(f32 *)(0xE0000000 + 0x0C) = e->x;
            *(f32 *)(0xE0000000 + 0x1C) = e->y;
            *(f32 *)(0xE0000000 + 0x2C) = e->z;
            fn_1_266A8(e);
        }
    }

    for (i = 0; i < p->count; i++) {
        fn_1_24A4C(p->base + i);
    }

    for (i = 0; i < p->count; i++) {
        fn_1_8A1B4(p->base + i, (void *)0, (void *)obj);
    }

    if ((flag & 0xFF) == 0 && p->unk158 == 0) {
        for (i = 0; i < p->count; i++) {
            Elem *e = p->base + i;
            if ((e->f00 & 0xC0000000) == 0 && obj) {
                if (((s32)obj->field04 < (s32)((Owner *)e->owner)->val118)
                    & (p->unk158 == 0) & ((obj->flags00 & 0x2000000) == 0)) {
                    fn_1_250F8((Sig_fn_1_250F8_Fn_1_250F8 *)e);
                }
            }
        }
    } else {
        for (i = 0; i < p->count; i++) {
            p->base[i].f184 = lbl_1_rodata_3A50[0];
        }
    }

    if (obj) {
        p->fn154((void *)obj);
        p->fn154 = fn_1_8B9B8;
        obj->mask = 0;
        {
            u8 lim = p->count;
            for (i = 0; i < p->count; i++) {
                Elem *e = p->base + i;
                s32 sel = -1;
                if (!(e->f00 & 0x20000000)) {
                    if (i < fn_1_3F854()) {
                        sel = i;
                    } else if (((Owner *)e->owner)->lim < lim) {
                        sel = 4;
                        lim = ((Owner *)e->owner)->lim;
                    }
                }
                if (sel != -1) {
                    obj->mask |= 1 << sel;
                    obj->slot[sel].x = e->x;
                    obj->slot[sel].y = e->y;
                    obj->slot[sel].z = e->z;
                }
            }
        }
    }

    if (p->fn150) {
        for (i = 0; i < p->count; i++) {
            p->fn150((void *)(p->base + i));
        }
    }

    p->unk158 = (p->unk15C != 0);
    if (obj && s10 == 0) {
        obj->flags00 &= ~0x600;
    }
}
