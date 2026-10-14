/* Non-matching: best partial attempt (87.08% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MovieModule MovieModule;
typedef struct MovieObj MovieObj;
typedef struct MovieObjVtbl MovieObjVtbl;
typedef struct MovieEntry MovieEntry;

struct MovieObjVtbl {
    void *pad[9];
    s32 (*func_24)(MovieObj *obj, s32 arg);
};

struct MovieObj {
    MovieObjVtbl *vtbl;
};

struct MovieEntry {
    s32 field_0;
    MovieObj *obj;
    s32 field_8;
    s32 field_c;
    u8 pad_14[0x64];
};

struct MovieModule {
    u8 pad_0[0x48];
    s32 field_48;
    s32 field_4c;
    s32 field_50;
    u8 pad_54[0x964 - 0x54];
    s32 field_964;
    s32 field_968;
    u8 pad_96c[0x9b4 - 0x96c];
    s32 field_9b4;
    s32 field_9b8;
    u8 pad_9bc[0x9f0 - 0x9bc];
    s32 field_9f0;
    s32 field_9f4;
    u8 pad_9f8[0xf00 - 0x9f8];
    s32 field_f00;
    s32 field_f04;
    u8 pad_f08[0x1150 - 0xf08];
    MovieEntry entries[1];
    u8 pad_11c4[0x1b38 - 0x11c4];
    s32 field_1b38;
    u8 pad_1b3c[0x1b7c - 0x1b3c];
    s32 field_1b7c;
};

extern void fn_12_24970(s32 *arg0);
extern void fn_12_24950(s32 *arg0);
extern s32 fn_12_2E714(MovieModule *module, s32 *arg1, s32 *arg2);
extern s32 fn_12_332DC(int state, int time, int arg2, int arg3);
extern s32 fn_12_2F1D0(MovieModule *module, u32 arg);
extern s32 fn_12_2D73C(MovieModule *module, int arg);
extern s32 fn_12_2EAC4(MovieModule *module);
extern s32 fn_12_2E7C8(MovieModule *module, s32 *arg1, s32 *arg2);
extern s32 fn_12_2E42C(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 fn_12_2F210(MovieModule *module, u32 arg1, u32 arg2, u32 arg3, u32 arg4);
extern s32 fn_12_2BE3C(MovieModule *module);
extern s32 fn_12_2ADDC(MovieModule *arg0, u32 arg1);
extern s32 fn_12_21D30(MovieModule *module, u32 idx);
extern s32 UTY_MulDiv(s32 a, s32 b, s32 c);

#pragma opt_dead_assignments off
static inline MovieObjVtbl * fn_12_2C0F8_read_pointer(MovieEntry * owner) { return owner->obj->vtbl; }
s32 fn_12_2C0F8(MovieModule *arg0) {
    MovieObjVtbl * fzgx_live;
    s32 f9f4 = arg0->field_9f4;
    MovieModule *m = arg0;
    s32 f9f0 = arg0->field_9f0;
    s32 e2;
    s32 v7;
    s32 v6;
    s32 res;
    s32 i;
    MovieEntry *ent;
    s32 a;
    s32 f04;
    s32 delta;
    s32 v_20;
    s32 v_1c;
    s32 v_18;
    MovieEntry * ent_2;
    s32 v_14;
    s32 v_10;
    s32 v_c;
    s32 v_8;

    {
        s32 e;
        if (f9f0 == -4) {
            e = 0;
        } else {
            fn_12_2E714(m, &v_18, &v_1c);
            if (v_18 < 0) {
                e = 0;
            } else if (fn_12_332DC(v_18, v_1c, f9f0, f9f4) != 0) {
                e = 0;
            } else {
                e = 1;
            }
        }
        if (e != 0) {
            goto reset;
        }
    }

    if (!(m->field_9b8 == 0 && m->field_9b4 == 0)) {
        e2 = 0;
        v6 = fn_12_2F1D0(m, 6);
        v7 = fn_12_2F1D0(m, 7);
        switch (fn_12_2D73C(m, 25)) {
        case 0:
            break;
            e2 = v7 & v6;
        case 1:
            e2 = v7;
            break;
        case 2:
            e2 = v6;
            break;
        case 3:
            e2 = v7 | v6;
            break;
        default:
            break;
        }
    } else {
        e2 = 1;
    }
    if (e2 != 0) {
        goto reset;
    }

    {
        s32 e;
        if (!(m->field_48 == 4 && m->field_50 != 1 && m->field_964 == 1)) {
            e = 0;
        } else {
            if (fn_12_2EAC4(m) != 0) {
                e = 1;
            } else {
                e = 0;
            }
        }
        if (e != 0) {
            goto reset;
        }
    }

    {
        s32 e;
        if (m->field_48 == 4 && m->field_50 != 1 && m->field_964 == 1) {
            if (fn_12_2E7C8(m, &v_10, &v_14) == 0) {
                e = 0;
            } else if (v_10 < 0) {
                e = 0;
            } else if (fn_12_2E42C(fn_12_2D73C(m, 54), 1000, v_10, v_14) != 0) {
                e = 1;
            } else {
                e = 0;
            }
        } else {
            e = 0;
        }
        if (e != 0) {
            goto reset;
        }
    }

reset:
    {
        s32 t3 = 0;
        if (m->field_48 == 4 && fn_12_2F210(m, 7, 7, 0, 0) != 0) {
            t3 = 1;
        } else {
            t3 = 0;
            m->field_48 = 1;
            m->field_4c = 1;
        }
        if (t3 == 0) {
            m->field_4c = 6;
            t3 = 0;
        }
        if (t3 != 0) {
            return m->field_48;
        }
    }

    fn_12_24970(&v_20);
    res = 0;
    if (m->field_964 == 0) {
        if (fn_12_2BE3C(m) == 0) {
            goto end;
        }
        m->field_964 = 1;
        m->field_968 = m->field_968 + 1;
        res = fn_12_2ADDC(m, 1);
    } else {
        s32 e;
        if (fn_12_2D73C(m, 5) != 0 && fn_12_2F1D0(m, 6) != 0) {
            e = 1;
        } else if (fn_12_2D73C(m, 6) != 0 && fn_12_2F1D0(m, 7) != 0) {
            e = 1;
        } else {
            for (i = 0; i < 8; i++) {
                if (fn_12_21D30(m, i) != 0) {
                    e = 1;
                    goto flag_join;
                }
            }
            e = 0;
flag_join:
            ;
        }
        if (e != 0) {
            e = 1;
            goto clear964;
        }

        if (fn_12_2D73C(m, 5) == 1) {
            ent = &m->entries[m->field_1b38];
            fzgx_live = fn_12_2C0F8_read_pointer(ent);
            a = fzgx_live->func_24(ent->obj, 1);
            if (a >= (ent->field_c * 80) / 100) {
                e = 1;
            } else if (a >= fn_12_2D73C(m, 0x46)) {
                e = 1;
            } else {
                e = 0;
            }
        }
        if (e != 0) {
            e = 1;
            goto clear964;
        }

        if (fn_12_2D73C(m, 6) == 1) {
            ent_2 = &m->entries[m->field_1b7c];
            a = ent_2->obj->vtbl->func_24(ent_2->obj, 1);
            if (a >= (ent_2->field_c * 80) / 100) {
                e = 1;
                goto clear964;
            }
        }

        fn_12_2E714(m, &v_8, &v_c);
        delta = m->field_f00;
        f04 = m->field_f04;
        delta = delta - UTY_MulDiv(fn_12_2D73C(m, 0x45), f04, 1000000);
        if (fn_12_2E42C(v_8, v_c, delta, f04) != 0) {
            e = 1;
        } else {
            e = 0;
        }

clear964:
        if (e != 0) {
            m->field_964 = 0;
            res = fn_12_2ADDC(m, 0);
        }
    }

end:
    fn_12_24950(&v_20);
    if (res != 0) {
        return m->field_48;
    }
    {
        s32 s = m->field_4c;
        s32 r48 = m->field_48;
        if (s == 5) {
            return r48;
        } else if (s >= 5) {
            if (s >= 7) {
                return r48;
            }
            return 6;
        }
        return r48;
    }
}
#pragma opt_dead_assignments reset

