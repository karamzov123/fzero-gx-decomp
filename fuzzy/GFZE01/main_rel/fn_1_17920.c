/* Non-matching: best partial attempt (91.58% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/stcoli.h"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    s = 0.0f;
    s = 1.0f;
    s = -5.0f;
    s = 10.0f;
    s = -1.0f;
    s = 2.0f;
}
#pragma section code_type ".text"

extern f32 lbl_1_rodata_6C8[8];
extern void lbl_8006D758(void);
typedef struct Sig_fn_1_1902C_StcoliNode Sig_fn_1_1902C_StcoliNode;
struct Sig_fn_1_1902C_StcoliNode {
    u32 flags;
    u8 pad[8];
    s32 count;
    Sig_fn_1_1902C_StcoliNode *items;
    u8 rest[0x3c];
};
typedef struct Sig_fn_1_1902C_StcoliVec {
    f32 x;
    f32 y;
    f32 z;
} Sig_fn_1_1902C_StcoliVec;
extern void fn_1_1902C(Sig_fn_1_1902C_StcoliNode *, Sig_fn_1_1902C_StcoliVec *, void *, f32);

typedef struct {
    s32 unk_0;
    f32 *unk_4;
    Sig_fn_1_1902C_StcoliNode *unk_8;
} StcoliEntry;

typedef struct {
    u32 unk_0;
    f32 unk_4;
} StcoliRange;

typedef struct {
    u8 pad_0[0x1B0];
    f32 unk_1B0;
    f32 unk_1B4;
    u32 unk_1B8;
    u32 unk_1BC;
    u8 pad_1C0[0x8];
    u32 unk_1C8;
    s32 unk_1CC;
    u32 unk_1D0;
    u32 unk_1D4;
    u8 pad_1D8[0x18];
    StcoliRange unk_1F0;
    u8 pad_1F8[0x40];
    StcoliRange unk_238;
    u8 pad_240[0x40];
    StcoliRange unk_280;
    u8 pad_288[0x40];
    StcoliRange unk_2C8;
    u8 pad_2D0[0x40];
    StcoliRange unk_310;
    u8 pad_318[0x294];
    u32 unk_5AC;
    u8 pad_5B0[0x7C];
    u32 unk_62C;
} StcoliState;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

extern StcoliState *lbl_801A66CC;

static inline f32 fn_1_17920_array_read(f32 *array, s32 index) { return array[index]; }

static inline void fn_1_17920_set_range(StcoliRange *r) { r->unk_0 = 0; r->unk_4 = -1.0f; }

#pragma opt_dead_assignments off
#pragma opt_lifetimes on
u16 fn_1_17920(s32 idx, void *unk1, f32 scale)
{
    f32 *fzgx_value__;
    f32 *fzgx_value;
    f32 *p;
    Sig_fn_1_1902C_StcoliNode *node;
    struct { f32 value; } a;
    f32 b;
    f32 t;
    f32 v;
    s32 c;
    Vec3f dir;
    Sig_fn_1_1902C_StcoliVec * lab_t1;

    {
        StcoliEntry *e = (StcoliEntry *)lbl_1_bss_3BE0->unk_C;
        p = e[idx].unk_4;
        node = e[idx].unk_8;
    }
    a.value = fn_1_17920_array_read(p, 0);
    b = fn_1_17920_array_read(p, 1);
    t = (((b - a.value)) * (scale));
    v = a.value + t;

    lbl_801A66CC->unk_1C8 = 0;
    lbl_801A66CC->unk_1CC = 0;
    lbl_801A66CC->unk_1D0 = 0;
    lbl_801A66CC->unk_1D4 = 0;
    lbl_801A66CC->unk_62C = 0;
    lbl_801A66CC->unk_5AC = 0;
    fn_1_17920_set_range(&lbl_801A66CC->unk_1F0);
    fn_1_17920_set_range(&lbl_801A66CC->unk_238);
    fn_1_17920_set_range(&lbl_801A66CC->unk_280);
    fn_1_17920_set_range(&lbl_801A66CC->unk_2C8);
    fn_1_17920_set_range(&lbl_801A66CC->unk_310);
    lbl_801A66CC->unk_1B0 = 2.0f;
    lbl_801A66CC->unk_1B4 = 0.0f;

    lbl_8006D758();
    fzgx_value = &(dir.x);
    *fzgx_value = 1.0f;
    dir.y = 1.0f;
    fzgx_value__ = &(dir.z);
    *fzgx_value__ = 1.0f;
    lbl_801A66CC->unk_1BC = 1;
    fn_1_1902C(node, (Sig_fn_1_1902C_StcoliVec *)&dir, unk1, v);

    c = lbl_801A66CC->unk_1CC;

    c = c + 1;
    lbl_801A66CC->unk_1CC = c;
    c = lbl_801A66CC->unk_1CC;
    lbl_801A66CC->unk_1B8 = (c > 1) ? c - 1 : c;
}
#pragma opt_lifetimes reset

