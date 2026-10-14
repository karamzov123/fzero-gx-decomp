/* Non-matching: best partial attempt (86.79% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef int BOOL;
typedef unsigned long size_t;
typedef struct {
u8 pad_00[0x150];
u8 *unk_150;
} Sub126774;
typedef struct {
u8 pad_00[0x08];
u8 *base;
} Model126774;
typedef struct {
f32 x;
f32 y;
f32 z;
} Vec3;
typedef struct {
u8 flags; /* 0x00 */
u8 pad_01;
u8 count; /* 0x02 */
u8 pad_03;
u16 indices[6]; /* 0x04 */
Vec3 pos; /* 0x10 */
Vec3 prev; /* 0x1c */
Vec3 rest; /* 0x28 */
Vec3 vel; /* 0x34 */
f32 unk_40; /* 0x40 */
} Entry126774;
typedef struct {
u8 *a;
u8 *b;
f32 unk_8;
} Pair126774;
typedef struct {
u8 flags; /* 0x00 */
u8 pad_01[0x07];
u32 idx; /* 0x08 */
void *unk_c; /* 0x0c */
void *unk_10; /* 0x10 */
u32 pad_14;
u32 count; /* 0x18 */
u32 pair_count; /* 0x1c */
u32 pad_20;
Entry126774 *entries; /* 0x24 */
Pair126774 *pairs; /* 0x28 */
} Obj126774;
typedef struct {
u8 pad_0[0x58];
f64 unk_58;
f32 unk_60;
u8 pad_64[0x38];
f32 unk_9C;
f32 unk_A0;
f32 unk_A4;
u8 pad_A8[0xF0];
f64 unk_198;
u8 pad_1A0[0xC8];
f64 unk_268;
u8 pad_270[0x1B8];
f32 unk_428;
} Ro126774;
extern Ro126774 lbl_1_rodata_7AB8;
extern u32 lbl_1_data_3FFBC[];
extern s32 fn_80077B14(void *);
extern u32 fn_1_1286F4(void *);
extern void fn_8006E250(void *, void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DBE4(void);
extern void lbl_8006DC20(void);
extern void lbl_8006E1B0(void *, void *);
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D118(f32 *);
extern f32 fabsf(f32);
#pragma opt_common_subs on
static inline f32 fn_1_126774_array_read(s32 index, f32 *array) { return array[index]; }
#pragma opt_dead_assignments on
void fn_1_11B958(Obj126774 *obj) {
    struct { Entry126774 * value; } fzgx_live_;
    f32 fzgx_live;
Ro126774 *ro;
f32 eps;
f32 t;
f64 w;
f64 h;
f64 f;
f32 d;
f32 m1;
f32 m0;
f32 s;
f32 dz;
f32 dy;
f32 dx;
u8 *model;
u8 *base;
    struct { Pair126774 * value; } p;
    struct { Entry126774 * value; } e;
u32 k;
u32 j;
    struct { u32 value; } i;
f32 tmpA[6];
f32 tmpB[3];
f32 tmpC[6];
f32 dist2;
void * lab_t0;
    void * lab_t0_;
ro = &lbl_1_rodata_7AB8;
if (obj == 0) {
return;
}
if (obj->unk_10 == 0) {
return;
}
fn_80077B14(obj->unk_10);
if ((obj->flags & 2) != 0) {
obj->flags &= ~2;
lab_t0_ = (((Model126774 *)((Sub126774 *)((obj)->unk_c))->unk_150)->base) + lbl_1_data_3FFBC[obj->idx] * 0x18c + 0x88;
lbl_8006DBAC(lab_t0_);
lbl_8006DAEC();
{ u32 __reg_value_i = 0; i.value = __reg_value_i; }
{ Entry126774 * __reg_value_fzgx_live_ = obj->entries; fzgx_live_.value = __reg_value_fzgx_live_; }
{ Entry126774 * __reg_value_e = fzgx_live_.value; e.value = __reg_value_e; }
while (i.value < obj->count) {
lbl_8006DBE4();
lab_t0 = &e.value->rest;
lbl_8006E1B0(lab_t0, &e.value->pos);
i.value++;
e.value++;
}
lbl_8006DC20();
}
{ u32 __reg_value_i = 0; i.value = __reg_value_i; }
{ Entry126774 * __reg_value_fzgx_live_ = obj->entries; fzgx_live_.value = __reg_value_fzgx_live_; }
{ Entry126774 * __reg_value_e = fzgx_live_.value; e.value = __reg_value_e; }
while (i.value < obj->count) {
if ((e.value->flags & 1) == 0) {
fn_1_1286F4(tmpA);
e.value->prev = e.value->pos;
h = (0.5);
f = h * fn_1_126774_array_read(0, tmpA);
fzgx_live = e.value->pos.x;
e.value->pos.x = e.value->vel.x + f + fzgx_live;
f = h * fn_1_126774_array_read(1, tmpA);
e.value->pos.y = e.value->vel.y + f + e.value->pos.y;
f = h * fn_1_126774_array_read(2, tmpA);
e.value->pos.z = e.value->vel.z + f + e.value->pos.z;
e.value->pos.y = e.value->pos.y - (0.0013611111376020642);
e.value->vel.x = e.value->vel.x + fn_1_126774_array_read(0, tmpA);
e.value->vel.y = e.value->vel.y + fn_1_126774_array_read(1, tmpA);
e.value->vel.z = e.value->vel.z + fn_1_126774_array_read(2, tmpA);
e.value->vel.y = e.value->vel.y - (0.00272222236f);
}
i.value++;
e.value++;
}
model = (((Model126774 *)((Sub126774 *)((obj)->unk_c))->unk_150)->base) + lbl_1_data_3FFBC[obj->idx] * 0x18c;
{ u32 __reg_value_i = 0; i.value = __reg_value_i; }
{ Entry126774 * __reg_value_fzgx_live_ = obj->entries; fzgx_live_.value = __reg_value_fzgx_live_; }
{ Entry126774 * __reg_value_e = fzgx_live_.value; e.value = __reg_value_e; }
while (i.value < obj->count) {
lab_t0_ = model + 0x88;
lbl_8006DBAC(lab_t0_);
lbl_8006DAEC();
if ((e.value->flags & 1) != 0) {
lbl_8006DBE4();
lab_t0 = &e.value->rest;
lbl_8006E1B0(lab_t0, &e.value->pos);
}
lbl_8006DC20();
i.value++;
e.value++;
}
for (k = 0; k < 2; k++) {
{ u32 __reg_value_i = 0; i.value = __reg_value_i; }
{ Pair126774 * __reg_value_p = obj->pairs; p.value = __reg_value_p; }
while (i.value < obj->pair_count) {
u8 *a = p.value->a;
u8 *b = p.value->b;
if (a != 0 && b != 0) {
dx = *(f32 *)(a + 0x10) - *(f32 *)(b + 0x10);
dy = *(f32 *)(a + 0x14) - *(f32 *)(b + 0x14);
dz = *(f32 *)(a + 0x18) - *(f32 *)(b + 0x18);
dist2 = ((dy * dy) + (dx * dx)) + dz * dz;
tmpA[3] = dx;
tmpA[4] = dy;
tmpA[5] = dz;
if (dist2 - (9.99999975e-05f) > p.value->unk_8) {
d = lbl_8006D118(&dist2);
s = d * (dist2 - lbl_8006D0B4(p.value->unk_8));
dx = fn_1_126774_array_read(3, tmpA) * s;
dy = fn_1_126774_array_read(4, tmpA) * s;
dz = fn_1_126774_array_read(5, tmpA) * s;
tmpA[3] = dx;
tmpA[4] = dy;
tmpA[5] = dz;
m0 = *(f32 *)(a + 0x40);
m1 = *(f32 *)(b + 0x40);
dx = (1.0f) / (m0 + m1);
dy = m0 * dx;
dz = m1 * dx;
m0 = fn_1_126774_array_read(3, tmpA) * dy;
m1 = fn_1_126774_array_read(4, tmpA) * dy;
t = fn_1_126774_array_read(5, tmpA) * dy;
*(f32 *)(a + 0x10) = *(f32 *)(a + 0x10) - m0;
*(f32 *)(a + 0x14) = *(f32 *)(a + 0x14) - m1;
*(f32 *)(a + 0x18) = *(f32 *)(a + 0x18) - t;
m0 = fn_1_126774_array_read(3, tmpA) * dz;
m1 = fn_1_126774_array_read(4, tmpA) * dz;
t = fn_1_126774_array_read(5, tmpA) * dz;
*(f32 *)(b + 0x10) = *(f32 *)(b + 0x10) + m0;
*(f32 *)(b + 0x14) = *(f32 *)(b + 0x14) + m1;
*(f32 *)(b + 0x18) = *(f32 *)(b + 0x18) + t;
}
}
i.value++;
p.value++;
}
}
model = (((Model126774 *)((Sub126774 *)((obj)->unk_c))->unk_150)->base) + lbl_1_data_3FFBC[obj->idx] * 0x18c;
{ u32 __reg_value_i = 0; i.value = __reg_value_i; }
{ Entry126774 * __reg_value_fzgx_live_ = obj->entries; fzgx_live_.value = __reg_value_fzgx_live_; }
{ Entry126774 * __reg_value_e = fzgx_live_.value; e.value = __reg_value_e; }
while (i.value < obj->count) {
if ((e.value->flags & 1) == 0) {
lab_t0_ = model + 0x88;
lbl_8006DBAC(lab_t0_);
lab_t0 = tmpB;
lbl_8006E1B0(lab_t0, &e.value->rest);
w = (1.0) - fabsf(e.value->unk_40);
fzgx_live = e.value->pos.x;
t = (0.349999994f) * (fn_1_126774_array_read(0, tmpB) - fzgx_live) * w;
fzgx_live = e.value->pos.x;
e.value->pos.x = fzgx_live + t;
t = (0.349999994f) * (fn_1_126774_array_read(1, tmpB) - e.value->pos.y) * w;
e.value->pos.y = e.value->pos.y + t;
t = (0.349999994f) * (fn_1_126774_array_read(2, tmpB) - e.value->pos.z) * w;
e.value->pos.z = e.value->pos.z + t;
}
i.value++;
e.value++;
}
model = (((Model126774 *)((Sub126774 *)((obj)->unk_c))->unk_150)->base) + lbl_1_data_3FFBC[obj->idx] * 0x18c;
eps = (0.00039999999f);
{ u32 __reg_value_i = 0; i.value = __reg_value_i; }
{ Entry126774 * __reg_value_fzgx_live_ = obj->entries; fzgx_live_.value = __reg_value_fzgx_live_; }
{ Entry126774 * __reg_value_e = fzgx_live_.value; e.value = __reg_value_e; }
while (i.value < obj->count) {
lab_t0_ = model + 0x88;
lbl_8006DBAC(lab_t0_);
lab_t0 = tmpC;
lbl_8006E1B0(lab_t0, &e.value->rest);
fzgx_live = e.value->pos.x;
dx = fzgx_live - fn_1_126774_array_read(0, tmpC);
dy = e.value->pos.y;
dy -= fn_1_126774_array_read(1, tmpC);
dz = e.value->pos.z - fn_1_126774_array_read(2, tmpC);
d = ((dy * dy) + (dx * dx)) + dz * dz;
tmpC[3] = dx;
tmpC[4] = dy;
tmpC[5] = dz;
if (d > eps) {
s = lbl_8006D0B4(eps / d);
m0 = fn_1_126774_array_read(3, tmpC) * s;
m1 = fn_1_126774_array_read(4, tmpC) * s;
t = fn_1_126774_array_read(5, tmpC) * s;
e.value->pos.x = fn_1_126774_array_read(0, tmpC) + m0;
e.value->pos.y = fn_1_126774_array_read(1, tmpC) + m1;
e.value->pos.z = fn_1_126774_array_read(2, tmpC) + t;
e.value->prev = e.value->pos;
}
i.value++;
e.value++;
}
{ u32 __reg_value_i = 0; i.value = __reg_value_i; }
{ Entry126774 * __reg_value_fzgx_live_ = obj->entries; fzgx_live_.value = __reg_value_fzgx_live_; }
{ Entry126774 * __reg_value_e = fzgx_live_.value; e.value = __reg_value_e; }
while (i.value < obj->count) {
fzgx_live = e.value->pos.x;
e.value->vel.x = fzgx_live - e.value->prev.x;
e.value->vel.y = e.value->pos.y - e.value->prev.y;
e.value->vel.z = e.value->pos.z - e.value->prev.z;
i.value++;
e.value++;
}
base = (u8 *)fn_80077B14(obj->unk_10);
model = (((Model126774 *)((Sub126774 *)((obj)->unk_c))->unk_150)->base) + lbl_1_data_3FFBC[obj->idx] * 0x18c;
lab_t0_ = model + 0x88;
lbl_8006DBAC(lab_t0_);
{ u32 __reg_value_i = 0; i.value = __reg_value_i; }
{ Entry126774 * __reg_value_fzgx_live_ = obj->entries; fzgx_live_.value = __reg_value_fzgx_live_; }
{ Entry126774 * __reg_value_e = fzgx_live_.value; e.value = __reg_value_e; }
while (i.value < obj->count) {
j = 0;
while (j < e.value->count) {
fn_8006E250(&e.value->pos, base + e.value->indices[j] * 0x40);
j++;
}
i.value++;
e.value++;
}
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs reset
