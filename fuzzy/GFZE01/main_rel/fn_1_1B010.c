/* Non-matching: best partial attempt (79.48% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/stcoli.h"

typedef struct {
    u32 e[9];
} Nine;

typedef struct {
    u8 pad0[0x8];
    f32 zero;
    u8 padC[0x4];
    f32 limLo;
    f32 limHi;
    u8 pad18[0x8];
    f32 half;
    f32 base;
    u8 pad28[0x24];
    Nine t1;
    Nine t2;
} Pool;

typedef struct {
    u8 pad[0x1D4];
    u32 flags;
} Ctrl;

typedef struct {
    u32 flags;
    u32 *table;
} Obj;

typedef struct {
    u32 f00;
    f32 f04;
} Node;

extern Pool lbl_1_rodata_6C8;
extern Ctrl *lbl_801A66CC;
extern void fn_1_18214(Obj *, f32 *, void *, f32);
extern void fn_8006E250(u8 *, f32 *);

void fn_1_1B010(u32 arg0, u8 *arg1, u32 arg2, Obj *arg3, f32 *arg4, u32 arg5, void *arg6, f32 arg7) {
    f32 vec[3];
    Nine tab2;
    Nine tab1;
    Pool *pool = &lbl_1_rodata_6C8;
    f32 vmax = lbl_1_data_4;
    f32 vmin = pool->zero;
    s32 found = 1;
    u32 *tbl;
    s32 i;
    f32 span;
    Node *n0;
    Node *n1;
    Node *n2;
    f32 a;
    f32 b;

    tab1 = pool->t1;
    tab2 = pool->t2;

    if (arg2 & 0x400) {
        tbl = arg3->table;
        for (i = 0; i < 3; i++) {
            n0 = (Node *)tbl[tab1.e[i * 3 + 0]];
            if (n0 != 0) {
                a = n0->f04;
                if (vmax > a) {
                    vmax = a;
                }
                b = *(f32 *)((u8 *)n0 + tab2.e[i * 3 + 0] * 20 - 16);
                if (vmin < b) {
                    vmin = b;
                }
                found = 0;
            }
            n1 = (Node *)tbl[tab1.e[i * 3 + 1]];
            if (n1 != 0) {
                a = n1->f04;
                if (vmax > a) {
                    vmax = a;
                }
                b = *(f32 *)((u8 *)n1 + tab2.e[i * 3 + 1] * 20 - 16);
                if (vmin < b) {
                    vmin = b;
                }
                found = 0;
            }
            n2 = (Node *)tbl[tab1.e[i * 3 + 2]];
            if (n2 != 0) {
                a = n2->f04;
                if (vmax > a) {
                    vmax = a;
                }
                b = *(f32 *)((u8 *)n2 + tab2.e[i * 3 + 2] * 20 - 16);
                if (vmin < b) {
                    vmin = b;
                }
                found = 0;
            }
        }
        if (found || (vmax < arg7 && arg7 < vmin)) {
            fn_1_18214(arg3, arg4, arg6, arg7);
            {
                f32 s = arg4[0];
                if (s < pool->zero) {
                    s = -s;
                }
                span = pool->base + (f32)(pool->half * s);
            }
            fn_8006E250(arg1, vec);
            if (pool->limLo < vec[1] && vec[1] < pool->limHi) {
                if (-span < vec[0] && vec[0] < span) {
                    lbl_801A66CC->flags |= (arg3->flags & 0x1E0000);
                }
            }
        }
    }
}
