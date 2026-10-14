/* Non-matching: best partial attempt (93.80% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

#pragma opt_propagation off

typedef struct Prm {
    f32 fps;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Prm;

typedef struct Obj {
    u32 unk0;
    f32 fps;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u8 pad14[0x24];
    s32 unk38;
    s32 unk3C;
    u8 pad40[0x18];
    s32 unk58;
    u8 pad5C[8];
    s32 err;
    u8 pad68[0x1140];
} Obj;

typedef struct Cfg {
    u32 a;
    s32 b;
} Cfg;

struct Pool {
    char ver[0x90];
    Cfg cfg;
    u8 pad_98[0xB8];
    char s150[8];
    char s158[0x34];
    f32 unk_18C;
    char s190[0x28];
    char s1B8[0x28];
    f64 unk_1E0;
    f32 unk_1E8;
    char s1EC[4];
};

struct Bss {
    s32 count;
    s32 unk4;
    u8 pad8[0xCC];
    Obj obj;
    char *ver;
};

extern struct Pool lbl_12_rodata_2270;
extern struct Bss lbl_12_bss_1B9D8;
extern u32 lbl_12_bss_1CC5C;

extern void MWSFSVM_Error(const char *, ...);
extern void fn_12_34E4C(void);
extern int fn_12_35004(void);
extern void fn_12_3A970(u32);
extern int fn_12_24D68(char *, int);
extern int fn_12_24C48(Cfg *);
extern void fn_12_388C4(void);
extern s32 fn_12_249BC(void *, void *, void *);
extern void fn_12_3A3CC(void *, int, int);
extern void fn_12_38D94(void);
extern void fn_12_35E04(void);
extern void fn_12_3ADC4(void);
extern void fn_12_34DE4(int, void *, void *);
extern void fn_12_3ACD0(void);
extern void fn_12_34D1C(void *, void *);
extern void fn_12_3AC70(void);
extern void fn_12_34D80(void *, void *);
extern void fn_800411F4(void);
extern void fn_80058680(void);
extern void fn_80057D0C(void);
extern void fn_80058754(void);
extern void *memset(void *, int, u32);
extern void fn_8005741C(void);
extern void fn_800566BC(void *, void *);

#define OBJ(bss) ((Obj *)((u8 *)(bss) + 0xd4))

static inline int SetErr(struct Bss *bss, int code) {
    Obj *o = (Obj *)((u8 *)&bss->unk4 + 0xd0);
    o->err = code;
    return code;
}

static inline void InitObj(Obj *obj, Prm *prm, struct Pool *pool) {
    s32 fzgx_value_;
    Obj *o;
    memset(obj, 0, sizeof(Obj));
    o = obj;
    fn_12_3A970(0);
    obj->unk58 = 0;
    if (prm != NULL) {
        o->fps = prm->fps;
        o->unk8 = prm->unk4;
        o->unkC = prm->unk8;
        fzgx_value_ = prm->unkC;
        o->unkC = fzgx_value_;
    } else {
        o->fps = pool->unk_18C;
        o->unk8 = 1;
        o->unkC = 0;
        o->unkC = 1;
    }
    obj->unk38 = 1;
    obj->unk3C = 1;
    lbl_12_bss_1CC5C = 0;
}

#pragma opt_dead_assignments off
static inline s8 Start(Prm *prm, struct Pool *pool, struct Bss *bss) {
    s32 fzgx_value = (s32)(pool->unk_1E0 + (f32)(pool->unk_1E8 * prm->fps));
    Cfg cfg = pool->cfg;
    cfg.b = fzgx_value;
    if (fn_12_24D68(pool->s150, 0x29d8) != 1) {
        MWSFSVM_Error(pool->s158);
        return -1;
    }
    if (fn_12_24C48(&cfg) != 0) {
        return SetErr(bss, -301);
    }
    if (fn_12_249BC(NULL, fn_12_388C4, NULL) != 0) {
        return SetErr(bss, -303);
    }
    return 0;
}
#pragma opt_dead_assignments reset


#pragma opt_lifetimes on
void fn_12_38AF0(Prm *prm) {
    struct Pool *pool = &lbl_12_rodata_2270;
    struct Bss *bss = &lbl_12_bss_1B9D8;

    if (prm == NULL) {
        MWSFSVM_Error(pool->s190);
        return;
    }
    bss->ver = (char *)((u32)pool + 0x0);
    fn_12_34E4C();
    prm->unk8 -= 2;
    if (prm->unk8 < 0) {
        prm->unk8 = 0;
    }
    if (bss->count == 0) {
        fn_800411F4();
        fn_80058680();
        fn_80057D0C();
        fn_80058754();
        if (fn_12_35004() != 0) {
            SetErr(bss, -101);
            MWSFSVM_Error(pool->s1B8);
        }
        InitObj(OBJ(bss), prm, pool);
        if (Start(prm, pool, bss) != 0) {
            MWSFSVM_Error(pool->s1EC);
        }
        bss->unk4 = 1;
        fn_12_3A3CC(NULL, 0x1b, (s32)prm->fps);
        fn_12_3A3CC(NULL, 7, 1);
        fn_8005741C();
        fn_800566BC(fn_12_38D94, NULL);
        fn_12_35E04();
        fn_12_34DE4(2, fn_12_3ADC4, NULL);
        fn_12_34D1C(fn_12_3ACD0, NULL);
        fn_12_34D80(fn_12_3AC70, NULL);
    }
    bss->count++;
}
#pragma opt_lifetimes reset

