/* Non-matching: best partial attempt (90.44% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Sig_fn_8006E294_fn_1_9CCE8_Vec3;
struct fn_1_F5D94_lbl_1_rodata_6D88 {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f64 unk_18;
    f32 unk_20;
    f32 unk_24;
    f64 unk_28;
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    f32 unk_54;
    f32 unk_58;
    f32 unk_5C;
};
extern const struct fn_1_F5D94_lbl_1_rodata_6D88 lbl_1_rodata_6D88;
extern u32 lbl_801A63C0;
extern u8 *lbl_801A6D00;
extern u8 *lbl_801A66CC;
extern u8 *lbl_8006DBAC(u8 *);
extern void fn_8006E294(void *);
extern f32 lbl_8006D0B4(f32);
typedef struct {
    Sig_fn_8006E294_fn_1_9CCE8_Vec3 pos;
    Sig_fn_8006E294_fn_1_9CCE8_Vec3 prev;
    Sig_fn_8006E294_fn_1_9CCE8_Vec3 vel;
    f32 alpha;
    f32 size;
    f32 baseSize;
    s32 life;
} Particle;
static inline f32 random_value(const struct fn_1_F5D94_lbl_1_rodata_6D88 *p) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (f32)(s32)((lbl_801A63C0 >> 16) & 0x7FFF) / p->unk_8;
}
#define random_value() random_value(p_lbl_1_rodata_6D88)
#pragma opt_common_subs on
void fn_1_F5D94(void *arg0) {
    f32 fzgx_live;
    const struct fn_1_F5D94_lbl_1_rodata_6D88 *p_lbl_1_rodata_6D88 = &lbl_1_rodata_6D88;
    f32 v2;
    Sig_fn_8006E294_fn_1_9CCE8_Vec3 loc_14;
    f32 v0;
    f32 v1;
    Sig_fn_8006E294_fn_1_9CCE8_Vec3 loc_8;
    f32 v6;
    f32 v9;
    f32 v10;
    f32 v36;
    s32 i;
    Particle *v13;
    s32 v8;
    lbl_8006DBAC(lbl_801A66CC);
    fn_8006E294(&loc_8);
    lbl_8006DBAC(lbl_801A6D00 + 48);
    fn_8006E294(&loc_14);
    v0 = loc_14.x - loc_8.x;
    v1 = loc_14.y - loc_8.y;
    v2 = loc_14.z - loc_8.z;
    *(f32 *)((u8 *)arg0 + 8) = lbl_8006D0B4((f32)(v0*v0) + v1*v1 + v2*v2);
    v2 = *(f32 *)((u8 *)arg0 + 12);
    *(f32 *)((u8 *)arg0 + 12) = v2 + (f32)((*(f32 volatile *)&(p_lbl_1_rodata_6D88->unk_20)) /* Retail reloads this field. */ * (p_lbl_1_rodata_6D88->unk_10 - v2));
    v8 = (s32)(p_lbl_1_rodata_6D88->unk_24 * *(f32 *)((u8 *)arg0 + 12));
    if (*(f32 *)((u8 *)arg0 + 8) > p_lbl_1_rodata_6D88->unk_28) {
        v9 = p_lbl_1_rodata_6D88->unk_34;
        v6 = p_lbl_1_rodata_6D88->unk_30;
        v10 = *(f32 *)((u8 *)arg0 + 8) - v9;
        if (v10 < v6) {} else if (v10 > v9) v6 = v9; else v6 = v10;
        v8 = (s32)((f32)v8 * (p_lbl_1_rodata_6D88->unk_10 / v6));
    }
    v13 = (Particle *)((u8 *)arg0 + 20);
    for (i = 36; i > 0; i--, v13++) {
        if (v8 > i && v13->life == 0) {
            v13->pos.x = p_lbl_1_rodata_6D88->unk_4 * random_value();
            v13->pos.y = p_lbl_1_rodata_6D88->unk_4 * random_value();
            v13->pos.z = p_lbl_1_rodata_6D88->unk_4 * random_value();
            v13->prev = v13->pos;
            v13->vel.x = p_lbl_1_rodata_6D88->unk_0 + (f32)(p_lbl_1_rodata_6D88->unk_38 * (random_value() - p_lbl_1_rodata_6D88->unk_3C));
            v13->vel.y = (*(f32 volatile *)&(p_lbl_1_rodata_6D88->unk_20)) /* Retail reloads this field. */ + (f32)(p_lbl_1_rodata_6D88->unk_40 * random_value());
            v13->vel.z = p_lbl_1_rodata_6D88->unk_0 + (f32)(p_lbl_1_rodata_6D88->unk_38 * (random_value() - p_lbl_1_rodata_6D88->unk_3C));
            v13->alpha = p_lbl_1_rodata_6D88->unk_0;
            v13->size = p_lbl_1_rodata_6D88->unk_C * (p_lbl_1_rodata_6D88->unk_10 + random_value());
            v13->baseSize = p_lbl_1_rodata_6D88->unk_C * (p_lbl_1_rodata_6D88->unk_10 + random_value());
            v13->size = v13->baseSize;
            v13->life = (s32)(p_lbl_1_rodata_6D88->unk_44 + (f32)(p_lbl_1_rodata_6D88->unk_48 * random_value()));
        }
        if (v13->life > 0) {
            v36 = lbl_8006D0B4((f32)(v13->vel.x*v13->vel.x) + v13->vel.y*v13->vel.y + v13->vel.z*v13->vel.z);
            v6 = p_lbl_1_rodata_6D88->unk_10 / (p_lbl_1_rodata_6D88->unk_10 + (f32)(p_lbl_1_rodata_6D88->unk_4C * v36));
            v13->size = v13->baseSize * (p_lbl_1_rodata_6D88->unk_10 - (f32)(v6 * random_value()));
            v13->vel.x += (f32)(p_lbl_1_rodata_6D88->unk_50 * (f32)(v36 * (random_value() - p_lbl_1_rodata_6D88->unk_3C)));
            v13->vel.y += (f32)(p_lbl_1_rodata_6D88->unk_50 * (f32)(v36 * (random_value() - p_lbl_1_rodata_6D88->unk_3C)));
            v13->vel.z += (f32)(p_lbl_1_rodata_6D88->unk_50 * (f32)(v36 * (random_value() - p_lbl_1_rodata_6D88->unk_3C)));
            v13->vel.y += p_lbl_1_rodata_6D88->unk_54;
            v13->vel.x += (f32)(p_lbl_1_rodata_6D88->unk_58 * (p_lbl_1_rodata_6D88->unk_0 - v13->vel.x));
            v13->vel.y += (f32)(p_lbl_1_rodata_6D88->unk_58 * (p_lbl_1_rodata_6D88->unk_40 - v13->vel.y));
            v13->vel.z += (p_lbl_1_rodata_6D88->unk_58 * (p_lbl_1_rodata_6D88->unk_0 - v13->vel.z));
            v13->prev = v13->pos;
            fzgx_live = p_lbl_1_rodata_6D88->unk_5C;
            v13->pos.x += v13->vel.x + (f32)(fzgx_live * (random_value() - p_lbl_1_rodata_6D88->unk_3C));
            fzgx_live = p_lbl_1_rodata_6D88->unk_5C;
            v13->pos.y += v13->vel.y + (f32)(fzgx_live * (random_value() - p_lbl_1_rodata_6D88->unk_3C));
            fzgx_live = p_lbl_1_rodata_6D88->unk_5C;
            v13->pos.z += v13->vel.z + (f32)(fzgx_live * (random_value() - p_lbl_1_rodata_6D88->unk_3C));
            while (v13->pos.x < p_lbl_1_rodata_6D88->unk_0) v13->pos.x += p_lbl_1_rodata_6D88->unk_4;
            while (v13->pos.x > p_lbl_1_rodata_6D88->unk_4) v13->pos.x -= p_lbl_1_rodata_6D88->unk_4;
            while (v13->pos.y < p_lbl_1_rodata_6D88->unk_0) v13->pos.y += p_lbl_1_rodata_6D88->unk_4;
            while (v13->pos.y > p_lbl_1_rodata_6D88->unk_4) v13->pos.y -= p_lbl_1_rodata_6D88->unk_4;
            while (v13->pos.z < p_lbl_1_rodata_6D88->unk_0) v13->pos.z += p_lbl_1_rodata_6D88->unk_4;
            while (v13->pos.z > p_lbl_1_rodata_6D88->unk_4) v13->pos.z -= p_lbl_1_rodata_6D88->unk_4;
            v13->life--;
            if ((f32)v13->life < p_lbl_1_rodata_6D88->unk_14)
                v13->alpha *= (f32)v13->life / (f32)(v13->life + 1);
            else v13->alpha += (f32)(p_lbl_1_rodata_6D88->unk_40 * (p_lbl_1_rodata_6D88->unk_10 - v13->alpha));
            if (v13->life <= 0) {
                v13->alpha = p_lbl_1_rodata_6D88->unk_0;
                v13->life = 0;
            }
        }
    }
}
#pragma opt_common_subs reset

