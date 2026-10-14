/* Non-matching: best partial attempt (48.97% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 pad[0x328];
    s8 unk_328;
} Fn86900Obj;

typedef struct {
    u8 pad[0xa0];
} Player;

typedef struct {
    u8 pad0[5];
    u8 unk_5;
    u8 pad6;
    u8 unk_7;
    u8 unk_8;
    u8 pad9[0x1480 - 9];
    u32 tbl[20];
} G;

typedef struct {
    u8 pad4[4];
    u8 unk_4;
    u8 pad5;
    u8 unk_6;
    u8 pad7;
} OutEnt;

typedef struct {
    OutEnt e[50];
    u8 unk_190;
    u8 unk_191;
    u8 unk_192;
    u8 pad193;
    u8 idx[50];
} Out;

typedef struct {
    u8 pad0[0x2a];
    s16 unk_2a;
    u8 pad2c[4];
    u32 flags;
    u8 pad34;
    u8 unk_35;
    u8 pad36;
    u8 unk_37;
    u8 unk_38;
    u8 pad39[0xe8 - 0x39];
    u32 (*unk_e8)(void);
    u8 padec[0x14b0 - 0xec];
    u32 tbl[20];
    u32 unk_1500;
    u8 unk_1504;
    u8 pad1505[0x163c - 0x1505];
    u8 arr[0x20];
    OutEnt out[50];
    u8 pad17ec[0x17f4 - 0x17ec];
    u16 unk_17f4;
} Base;

typedef struct {
    u8 pad0[0x1f88];
    u32 unk_1f88;
    u8 pad1f8c[0x1f9c - 0x1f8c];
    s32 unk_1f9c;
    s32 unk_1fa0;
    s32 unk_1fa4;
    u8 pad1fa8[0x1fe6 - 0x1fa8];
    u16 unk_1fe6;
    u8 pad1fe8[2];
    u8 unk_1fea;
    u8 pad1feb;
    s32 unk_1fec;
    u8 pad1ff0[0x226c - 0x1ff0];
    s32 unk_226c;
    s32 unk_2270;
    u8 pad2274[4];
    s32 unk_2278;
    u8 pad227c[0x228c - 0x227c];
    s32 unk_228c;
    u8 pad2290[0x2f14 - 0x2290];
    s32 unk_2f14;
} Hi;

extern Base lbl_1_bss_3C00;
extern u8 lbl_1_data_5730;
extern u32 lbl_1_bss_6EAB4;
extern u8 lbl_1_bss_38200;
extern s16 lbl_1_bss_960;
extern u32 lbl_1_data_1A2B4[];
extern struct {
    u8 pad[0x94];
    u32 unk_94;
} lbl_1_bss_8B3A0;

extern void fn_1_3F2A0(void);
extern void fn_1_4A00(s32, u8, u32);
extern void fn_1_469BC(void);
extern void fn_1_8DBA4(u8);
extern int fn_1_EB248(void);
extern s32 fn_1_154C84(void);
extern u32 fn_1_435C(u32);
extern u32 fn_1_2DE00(u32);
extern u32 fn_1_4DE04(void);
extern s8 fn_1_8623C(void);
extern Fn86900Obj *fn_1_86900(s8);
extern Fn86900Obj *fn_1_868C0(s8);
extern s16 fn_1_12C930(s16);
extern void fn_1_4811C(int);
extern void fn_1_48004(s32, s32);
extern void fn_1_3F8D0(void);
extern void fn_1_30D84(void);
extern void fn_1_3129C(void);
extern void fn_1_30824(void);
extern void *fn_1_3F8C(void *, void *, s32, s32);
extern u32 fn_1_F3BC0(void);
extern void fn_1_154CC4(u32);
extern void fn_1_EB080(int);

#define PB(p, i, o) (*((u8 *)&(p)[i] + (o)))

static inline void sel_cursor(Base *base, Hi *hi)
{
    s32 v = hi->unk_1fec;
    if (v != -2) {
        s32 i;
        base->flags |= 2;
        for (i = 13; i > 0; i--) {
            if (v & (1 << i)) {
                base->unk_1504 = i;
                return;
            }
        }
        {
            u16 w = hi->unk_1fe6;
            for (i = 0; i < 14; i++) {
                if (w & (1 << i)) {
                    base->unk_1504 = i;
                    return;
                }
            }
        }
    }
}

static inline void idle_sound(void)
{
    if (lbl_1_bss_960 != 10 && lbl_1_bss_960 != 12) {
        Fn86900Obj *o = fn_1_86900(fn_1_8623C());
        if (o == 0) {
            o = fn_1_868C0(0);
        }
        fn_1_4811C(lbl_1_data_1A2B4[fn_1_12C930(o->unk_328)]);
        fn_1_4811C(0x97);
        fn_1_4811C(0x99);
        fn_1_48004(0x94, 1);
    }
}

static inline void confirm_start(Base *base, Hi *hi, u8 *d)
{
    G *g = (G *)((u8 *)base + 0x30);
    Player *pl = (Player *)g;
    s32 i, n;
    base->unk_17f4 = g->unk_7;
    if (g->unk_5 == 0) {
        n = g->unk_8;
        for (i = 0; i < n; i++) {
            if (g->tbl[i] != 0) {
                if (!(base->flags & 0x400000)) {
                    u8 cnt;
                    u8 *ob = (u8 *)base->out;
                    u8 j;
                    u8 *ap;
                    Player *pp;
                    fn_1_3F2A0();
                    cnt = g->unk_8;
                    ap = base->arr;
                    pp = pl;
                    if (base->unk_2a <= 41) {
                        for (j = 0; j < cnt; j++) {
                            s32 k = PB(pp, 0, 0x157);
                            ((OutEnt *)((u8 *)base + 0x165c))[k].unk_4 = PB(pp, 0, 0x154);
                            ((OutEnt *)((u8 *)base + 0x165c))[k].unk_6 = *ap;
                            ob[0x194 + k] = j;
                            pp++;
                            ap++;
                        }
                    } else {
                        for (j = 0; j < cnt; j++) {
                            s32 k = PB(pp, 0, 0xdc);
                            ((OutEnt *)((u8 *)base + 0x165c))[k].unk_4 = PB(pp, 0, 0x154);
                            ((OutEnt *)((u8 *)base + 0x165c))[k].unk_6 = *ap;
                            ob[0x194 + k] = j;
                            pp++;
                            ap++;
                        }
                    }
                    ob[0x191] |= 2;
                    ob[0x192] = cnt;
                    ob[0x190] = g->unk_7;
                    base->flags |= 0x400000;
                    base->unk_17f4 = 0xe;
                }
                break;
            }
        }
    }
    fn_1_4A00(0, 0x1e, base->unk_1500);
    hi->unk_1fa0 = 1;
    lbl_1_bss_6EAB4 |= 0x2c;
    if (g->unk_5 == 0) {
        *(d + 0x454) = 1;
    }
    fn_1_469BC();
    fn_1_8DBA4(0);
}

void fn_1_3B7D4(void)
{
    Base *base = (Base *)&lbl_1_bss_3C00;
    u8 *d = (u8 *)&lbl_1_data_5730;
    Hi *hi = (Hi *)((u8 *)base + 0x20000);
    u32 (*fp)(void) = base->unk_e8;
    s32 sel;
    u32 ret;
    u32 tmp;

    hi->unk_1f9c = 0;
    if (fp != 0) {
        ret = fp();
        if (ret & 4) {
            hi->unk_1f9c = 1;
        }
        if ((ret & 2) && hi->unk_1fa0 == 0) {
            confirm_start(base, hi, d);
        }
        if (ret & 1) {
            return;
        }
    }
    if (lbl_1_bss_38200 != 0) {
        lbl_1_bss_38200--;
    }
    if (hi->unk_1fa0 != 0) {
        return;
    }
    if (hi->unk_2f14 == 0) {
        return;
    }
    if (hi->unk_1fa4 != 0) {
        return;
    }
    sel = -2;
    if (hi->unk_1fea == 2) {
        sel = hi->unk_1fec;
    }
    if (fn_1_EB248() != 0 || fn_1_154C84() != 0) {
        base->flags |= 2;
        return;
    }
    base->flags &= ~2;
    if (sel == -2) {
        return;
    }
    fn_1_435C(hi->unk_1f88);
    sel_cursor(base, hi);

    switch (sel) {
    case 2:
        if (hi->unk_1fa0 == 0) {
            fn_1_2DE00(1);
            base->unk_37 = 0xe;
            if (hi->unk_1fa0 == 0) {
                confirm_start(base, hi, d);
            }
        }
        break;
    case 3:
        break;
    case 4:
        if (hi->unk_1fa0 == 0) {
            s32 i;
            Player *pl = (Player *)((u8 *)base + 0x30);
            hi->unk_1fa0 = 1;
            fn_1_4A00(0, 0x1e, base->unk_1500);
            hi->unk_2278 = 0;
            lbl_1_bss_6EAB4 |= 0x2c;
            fn_1_4DE04();
            idle_sound();
            fn_1_3F8D0();
            hi->unk_226c = 1;
            hi->unk_228c = 0x3c;
            tmp = fn_1_435C(base->unk_1500);
            fn_1_3F8C(d + 0xcb0, (void *)fn_1_30D84, 0, 2);
            fn_1_435C(tmp);
            for (i = 0; i < base->unk_38; i++) {
                PB(pl, i, 0x157) = PB(pl, i, 0xdc);
            }
        }
        break;
    case 8:
        if (hi->unk_1fa0 == 0) {
            hi->unk_1fa0 = 1;
            fn_1_4A00(0, 0x1e, base->unk_1500);
            hi->unk_2278 = 0;
            lbl_1_bss_6EAB4 |= 0x2c;
            fn_1_4DE04();
            idle_sound();
            fn_1_3F8D0();
            hi->unk_228c = 0x3c;
            tmp = fn_1_435C(base->unk_1500);
            fn_1_3F8C(d + 0xcc0, (void *)fn_1_3129C, 0, 2);
            fn_1_435C(tmp);
        }
        break;
    case 0x20:
        if (hi->unk_1fa0 == 0) {
            hi->unk_1fa0 = 1;
            fn_1_4A00(0, 0x1e, base->unk_1500);
            hi->unk_2278 = 0;
            lbl_1_bss_6EAB4 |= 0x2c;
            fn_1_4DE04();
            idle_sound();
            fn_1_3F8D0();
            hi->unk_2270 = 1;
            hi->unk_228c = 0x3c;
            tmp = fn_1_435C(base->unk_1500);
            fn_1_3F8C(d + 0xca4, (void *)fn_1_30824, 0, 2);
            fn_1_435C(tmp);
        }
        break;
    case 0x40:
        if (hi->unk_1fa0 == 0) {
            base->unk_17f4 = 1;
            lbl_1_bss_8B3A0.unk_94 |= 0x20;
            fn_1_4A00(0, 0x1e, base->unk_1500);
            hi->unk_1fa0 = 1;
            lbl_1_bss_6EAB4 |= 0x2c;
            if (base->unk_35 == 0) {
                *(d + 0x454) = 0;
            }
            fn_1_8DBA4(0);
        }
        break;
    case 0x80:
        if (hi->unk_1fa0 == 0) {
            hi->unk_1fa0 = 1;
            fn_1_4A00(0, 0x1e, base->unk_1500);
            hi->unk_2278 = 1;
            lbl_1_bss_6EAB4 |= 0x2c;
            fn_1_4DE04();
            idle_sound();
            fn_1_3F8D0();
            hi->unk_228c = 0x3c;
            tmp = fn_1_435C(base->unk_1500);
            fn_1_3F8C(d + 0xcc0, (void *)fn_1_3129C, 1, 2);
            fn_1_435C(tmp);
        }
        break;
    case 0x100:
        fn_1_F3BC0();
        fn_1_154CC4(0);
        sel_cursor(base, hi);
        break;
    case 0x200:
        fn_1_EB080(0xb);
        break;
    case 0x2000:
        if (hi->unk_1fa0 == 0) {
            confirm_start(base, hi, d);
        }
        break;
    }
}
