/* Non-matching: best partial attempt (97.81% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
typedef struct { f32 x,y,z; } V;
typedef struct { u8 pad[0x1BC]; u32 a,b; f32 c; u8 pad2[0x304-0x1C8]; u32 d,e; f32 f; u32 flags; f32 t; V pos,normal,offset; u8 pad3[0x348-0x33C]; u32 end; } Global;
typedef struct { f32 m[3][4]; } Matrix;
typedef struct { u8 pad[8]; f32 zero; u8 pC[4]; f32 min; u8 p14[12]; f32 half; u8 p24[16]; f32 nhalf; u8 p38[16]; f32 low; } Pool;
extern const Pool lbl_1_rodata_6C8;
extern Global *lbl_801A66CC;
extern Matrix *lbl_801A6D00;
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DF44(void);
extern void lbl_8006E0B4(f32,f32,f32);
extern void lbl_8006E1B0(V *, V *);
extern u16 mathutil_mtxA_rotate_z(u32);
static inline f32 fn_1_1ACC0_read_pointer(const Pool * owner) { return owner->zero; }
#pragma opt_dead_assignments off
u32 fn_1_1ACC0(V *a, V *b, void *c, f32 *d, f32 value) {
    f32 *fzgx_value;
    f32 (* fzgx_live)[4];
 Global *g;
 const Pool *pool;
 s32 positive;
 u32 flags;
    f32 lab_t1;
 f32 delta;
 f32 t;
 f32 h;
 f32 x;
 f32 y;
 f32 z;
 V va;
 V vb;
 V diff;
 V out;
 union { f32 f; u32 u; } bits;
 pool = (const Pool *)&lbl_1_rodata_6C8;
 g = lbl_801A66CC;
 positive = value > fn_1_1ACC0_read_pointer(pool);
 delta = a->y - lbl_801A6D00->m[1][3];
 lbl_8006DAEC();
 if (positive) {
 h = pool->half;
 h = h * *d;
 x = ((Matrix *)0xE0000000)->m[0][0]*h + ((Matrix *)0xE0000000)->m[0][3];
 y = ((Matrix *)0xE0000000)->m[1][0]*h + ((Matrix *)0xE0000000)->m[1][3];
 z = ((Matrix *)0xE0000000)->m[2][0]*h + ((Matrix *)0xE0000000)->m[2][3];
 ((Matrix *)0xE0000000)->m[0][3] = x;
 ((Matrix *)0xE0000000)->m[1][3] = y;
 ((Matrix *)0xE0000000)->m[2][3] = z;
 mathutil_mtxA_rotate_z(-12743);
 } else {
 lab_t1 = *(f32 *)((u8 *)c + 0x40);
 lbl_8006E0B4(pool->nhalf * *d, lab_t1, fn_1_1ACC0_read_pointer(pool));
 mathutil_mtxA_rotate_z(-3276);
 }
 lbl_8006DAEC();
 lbl_8006DF44();
 lbl_8006E1B0(a, &va);
 lbl_8006E1B0(b, &vb);
 lbl_8006DB30();
 if (delta < pool->min) {
 g->pos = *b;
 g->normal.x = lbl_801A6D00->m[0][1];
 g->normal.y = lbl_801A6D00->m[1][1];
 g->normal.z = lbl_801A6D00->m[2][1];
 g->offset.x = fn_1_1ACC0_read_pointer(pool);
 g->offset.y = fn_1_1ACC0_read_pointer(pool);
 g->offset.z = fn_1_1ACC0_read_pointer(pool);
 g->t = fn_1_1ACC0_read_pointer(pool);
 g->flags |= 0x100;
 g->d = lbl_801A66CC->a;
 g->e = lbl_801A66CC->b;
 g->f = lbl_801A66CC->c;
 g->end = 0;
 }
 if (fn_1_1ACC0_read_pointer(pool) >= va.y) {
 t = vb.y / (vb.y - va.y);
 bits.f = t;
 if ((bits.u & 0x7F800000) == 0x7F800000) t = fn_1_1ACC0_read_pointer(pool);
 psvec_sub_scale_add(&va, &vb, t, &diff, &out);
 psvec_sub_scale_add(a, b, t, &diff, &g->pos);
 fzgx_live = lbl_801A6D00->m;
 g->normal.x = fzgx_live[0][1];
 fzgx_value = &(g->normal.y);
 *fzgx_value = lbl_801A6D00->m[1][1];
 g->normal.z = lbl_801A6D00->m[2][1];
 h = -va.y;
 if (h > fn_1_1ACC0_read_pointer(pool)) {
 x = ((Matrix *)0xE0000000)->m[0][1]*h;
 y = ((Matrix *)0xE0000000)->m[1][1]*h;
 z = ((Matrix *)0xE0000000)->m[2][1]*h;
 g->offset.x = x;
 g->offset.y = y;
 g->offset.z = z;
 } else {
 g->offset.x = fn_1_1ACC0_read_pointer(pool);
 g->offset.y = fn_1_1ACC0_read_pointer(pool);
 g->offset.z = fn_1_1ACC0_read_pointer(pool);
 }
 g->t = t;
 if (positive) {
 if (delta < pool->low) flags = 0x200;
 else flags = 0x800;
 } else flags = 0x400;
 g->flags = flags;
 g->d = lbl_801A66CC->a;
 g->e = lbl_801A66CC->b;
 g->f = lbl_801A66CC->c;
 g->end = 0;
 }
 lbl_8006DB30();
    return (u32)pool;
}
#pragma opt_dead_assignments reset

