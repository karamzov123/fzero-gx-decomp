/* Non-matching: best partial attempt (96.00% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct fn_80049728_Vtbl {
    u8 pad_0[0x18];
    void (*unk18)(void *, s32, s32, void *);
    void (*unk1C)(void *, s32, void *);
    void (*unk20)(void *, s32, void *);
    s32 (*unk24)(void *, s32);
} fn_80049728_Vtbl;

typedef struct fn_80049728_Obj {
    fn_80049728_Vtbl *vtbl;
} fn_80049728_Obj;

typedef struct fn_80049728_Buf {
    void *data;
    u32 size;
} fn_80049728_Buf;

struct fn_80049728_Arg0 {
    u8 pad_0[0xC];
    fn_80049728_Obj *unk_C;
    u8 pad_10[0x1C];
    s32 unk_2C;
    u8 pad_30[0x20];
    s32 unk_50;
    u8 pad_54[0x18];
    s32 unk_6C;
};

struct fn_80049728_Tmp {
    u8 b;
    s16 h;
};

extern void * memcpy(void *, u32);

#pragma peephole on
#pragma opt_loop_invariants off
static inline void (* fn_80049728_read_pointer(fn_80049728_Obj * owner))(void *, s32, void *) { return owner->vtbl->unk1C; }
#pragma opt_common_subs off
#pragma opt_lifetimes off
static inline s32 (* fn_80049728_read_pointer_(fn_80049728_Obj * owner))(void *, s32) { return owner->vtbl->unk24; }
#pragma opt_dead_assignments off
#pragma opt_propagation off
s32 fn_80049728(struct fn_80049728_Arg0 *arg0) {
    void * tmp_call7;
    void * fzgx_live;
    fn_80049728_Buf b1;
    fn_80049728_Buf b2;
    fn_80049728_Buf b3;
    struct fn_80049728_Tmp t;
    s32 m;
    s32 n;
    fn_80049728_Obj *v = arg0->unk_C;
    s32 i;
    const void * lab_t1;
    s32 a;

    a = arg0->unk_2C;
    if (arg0->unk_6C <= 0) {
        n = arg0->unk_50;
    } else {
        n = (a + arg0->unk_50 + 0x7FF) / 0x800 * 0x800 - a;
    }
    m = n - 4;
    if (fn_80049728_read_pointer_(v)(v, 0) < n) {
        return 0;
    }
    *(u16 *)&t.h = 0x8001;
    (*(void (* volatile *)(void *, s32, s32, void *))&(v->vtbl->unk18)) /* Retail reloads this field. */(v, 0, 2, &b1);
    if ((s32)b1.size < 2) {
        fn_80049728_read_pointer(v)(v, 0, &b1);
    } else {
        *(s16 *)b1.data = t.h;
        v->vtbl->unk20(v, 1, &b1);
    }
    t.h = (s16)m;
    (*(void (* volatile *)(void *, s32, s32, void *))&(v->vtbl->unk18)) /* Retail reloads this field. */(v, 0, 2, &b2);
    if ((s32)b2.size < 2) {
        fn_80049728_read_pointer(v)(v, 0, &b2);
    } else {
        *(s16 *)b2.data = t.h;
        v->vtbl->unk20(v, 1, &b2);
    }
    t.b = 0;
    for (i = 0; i < m; i++) {
        (*(void (* volatile *)(void *, s32, s32, void *))&(v->vtbl->unk18)) /* Retail reloads this field. */(v, 0, 1, &b3);
        if ((s32)b3.size < 1) {
            fn_80049728_read_pointer(v)(v, 0, &b3);
        } else {
            lab_t1 = &t.b;
            fzgx_live = b3.data;
            tmp_call7 = memcpy(fzgx_live, 1);
            tmp_call7;
            v->vtbl->unk20(v, 1, &b3);
        }
    }
    return n;
}
#pragma opt_propagation reset

#pragma opt_dead_assignments reset

#pragma opt_lifetimes reset

#pragma opt_common_subs reset

#pragma opt_loop_invariants reset
#pragma peephole reset

