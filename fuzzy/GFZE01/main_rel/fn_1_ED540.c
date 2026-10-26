/* Non-matching: best partial attempt (72.21% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef float f32;
typedef double f64;

/* Paired-single vector kernels recovered from retail code (2026-09-15).
 *
 * Retail's x/y lanes are handled by psq_l/psq_st with a displacement and the
 * z lane by lfs/stfs. MWCC's __vec2x32float__ type only ever emits the indexed
 * psq_lx/psq_stx forms, so the displacement form can come only from inline
 * assembly inlined into the caller; the compiler then allocates the registers
 * and schedules these instructions together with the surrounding code, which
 * is what the retail streams show. Pointers are untyped so every per-block Vec
 * typedef can be passed without a cast. */
/* ab = a - b */
static inline void psvec_sub(const register void *a, const register void *b, register void *ab) {
register f32 axy, bxy, az, bz;
asm {psq_l axy, 0(a), 0, 0
psq_l bxy, 0(b), 0, 0
lfs az, 8(a)
lfs bz, 8(b)
ps_sub axy, axy, bxy
fsubs az, az, bz
psq_st axy, 0(ab), 0, 0
stfs az, 8(ab)
}
}
/* ab = a + b */
static inline void psvec_add(const register void *a, const register void *b, register void *ab) {
register f32 axy, bxy, az, bz;
asm {psq_l axy, 0(a), 0, 0
psq_l bxy, 0(b), 0, 0
lfs az, 8(a)
lfs bz, 8(b)
ps_add axy, axy, bxy
fadds az, az, bz
psq_st axy, 0(ab), 0, 0
stfs az, 8(ab)
}
}
/* dst = a * s */
static inline void psvec_scale(const register void *a, register f32 s, register void *dst) {
register f32 axy, az;
asm {psq_l axy, 0(a), 0, 0
lfs az, 8(a)
ps_muls0 axy, axy, s
fmuls az, az, s
psq_st axy, 0(dst), 0, 0
stfs az, 8(dst)
}
}
/* dst = acc + v * s (retail loads the accumulator first: fn_1_236CC) */
static inline void psvec_scale_add(const register void *acc, const register void *v, register f32 s, register void *dst) {
register f32 axy, vxy, az, vz;
asm {psq_l axy, 0(acc), 0, 0
psq_l vxy, 0(v), 0, 0
lfs az, 8(acc)
lfs vz, 8(v)
ps_madds0 axy, vxy, s, axy
fmadds az, vz, s, az
psq_st axy, 0(dst), 0, 0
stfs az, 8(dst)
}
}
/* d = a - b; out = b + d * s (the interpolation kernel: fn_1_115BE8, fn_1_108A90) */
static inline void psvec_sub_scale_add(const register void *a, const register void *b, register f32 s, register void *d, register void *out) {
register f32 axy, bxy, az, bz;
asm {psq_l axy, 0(a), 0, 0
psq_l bxy, 0(b), 0, 0
lfs az, 8(a)
lfs bz, 8(b)
ps_sub axy, axy, bxy
fsubs az, az, bz
psq_st axy, 0(d), 0, 0
stfs az, 8(d)
ps_madds0 bxy, axy, s, bxy
fmadds bz, az, s, bz
psq_st bxy, 0(out), 0, 0
stfs bz, 8(out)
}
}
/* dst = (x, y, z). The parameters are declared z, y, x: an inlined asm block's
 * register parameters take f0, f1, f2 in declaration order, and retail merges
 * x from f2 with y from f1 while z sits in f0 (fn_1_2A694). */
static inline void psvec_set(register void *dst, register f32 z, register f32 y, register f32 x) {
asm {ps_merge00 x, x, y
psq_st x, 0(dst), 0, 0
stfs z, 8(dst)
}
}
typedef struct Vec3 {
f32 x;
f32 y;
f32 z;
} Vec3;
typedef struct Sig_fn_1_87448_Fn1_87448_Slot {
void **unk_00;
void *unk_04;
u32 pad_08;
} Sig_fn_1_87448_Fn1_87448_Slot;
typedef struct Fn_1_ED540_Obj22 {
u8 pad_00[0x328];
s8 field_328;
u8 pad_329[0xB];
Sig_fn_1_87448_Fn1_87448_Slot unk_334[3];
u8 pad_358[0x38];
u32 unk_390;
u8 pad_394[0xC];
void *unk_3A0;
u8 pad_3A4[0x16];
s16 field_3BA;
} Fn_1_ED540_Obj22;
struct fn_1_ED540_lbl_1_bss_7B180 {
u8 pad_0[0x8];
u32 unk_8;
u8 pad_C[0x14];
u32 unk_20;
u8 pad_24[0x15DC];
f32 *unk_1600[1];
u8 pad_1604[0xC4];
s32 unk_16C8;
u8 pad_16CC[8];
s32 unk_16D4;
u8 pad_16D8[0x76];
u8 unk_174E;
u8 pad_174F[9];
Vec3 unk_1758[1];
u8 pad_1764[0x30];
Fn_1_ED540_Obj22 *unk_1794[1];
u8 pad_1798[0x10];
void *unk_17A8[1];
u8 pad_17AC[0x10];
s32 unk_17BC;
u8 pad_17C0[8];
s32 unk_17C8;
u8 pad_17CC[0x34];
u16 unk_1800[1];
u8 pad_1802[0x22];
u32 unk_1824[1];
u8 pad_1828[0xB0];
u8 unk_18D8[1][0x30];
u8 pad_1908[0xC0];
u8 unk_19C8[1][0x620];
u8 pad_1FE8[0x18C0];
s32 unk_38A8;
u8 pad_38AC[0x18];
u8 unk_38C4[1][0x30];
u8 pad_38F4[0xC0];
Vec3 unk_39B4[1];
u8 pad_39C0[0x30];
s32 unk_39F0[1];
u8 pad_39F4[0x13C];
s32 unk_3B30;
};
extern u8 lbl_1_data_3E358[];
extern s16 lbl_1_bss_960;
extern u32 lbl_801A66A0;
extern const f32 lbl_1_rodata_6B60;

extern const f32 lbl_1_rodata_6BBC;
extern const f32 lbl_1_rodata_6BD0;
extern const f32 lbl_1_rodata_6C18;

extern const f32 lbl_1_rodata_6C90;
extern const u32 lbl_1_rodata_6CBC[3];
extern const u32 lbl_1_rodata_6CC8;
extern const u32 lbl_1_rodata_6CCC;
extern const u32 lbl_1_rodata_6CD0;
extern const u32 lbl_1_rodata_6CD4;
extern const u32 lbl_1_rodata_6CD8;
extern const u32 lbl_1_rodata_6CDC;
extern const u32 lbl_1_rodata_6CE0;
extern const u32 lbl_1_rodata_6CE4;
extern const u32 lbl_1_rodata_6CE8;
extern const f32 lbl_1_rodata_6CEC;
extern const f32 lbl_1_rodata_6CF0;
extern const f32 lbl_1_rodata_6CF4;
extern const f32 lbl_1_rodata_6CF8;
extern const f32 lbl_1_rodata_6CFC;
extern const f32 lbl_1_rodata_6D00;
extern const f64 lbl_1_rodata_6D08;
extern const f32 lbl_1_rodata_6D10;
extern const f32 lbl_1_rodata_6D14;
extern const f32 lbl_1_rodata_6D18;
extern const f32 lbl_1_rodata_6D1C;
extern const f32 lbl_1_rodata_6D20;
extern const f32 lbl_1_rodata_6D24;
extern int fn_1_4C10(void);
extern void fn_1_984F0(void *);
extern void fn_80008BEC(void *, int, u32);
extern void lbl_8006DD14(void *, void *);
extern void lbl_8006D758(void);
extern void lbl_8006DB74(void *);
extern void fn_1_F143C(void *, s32, const void *, const void *, void *);
extern void fn_1_F23E8(void);
extern void fn_1_98634(f32);
extern void fn_1_983CC(void *, void *);
extern void fn_1_56298(f32, f32, f32, f32);
extern void fn_1_5621C(f32, f32, f32, f32);
extern u8 fn_1_5910(void);
extern void fn_1_681C(u32, void *);
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D668(void *);
extern void fn_1_56000(u8, u8, u8);
extern void lbl_8006DCA4(void);
extern void lbl_8006E0A4(void *);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E14C(f32);
extern void fn_80072558(void);
extern void fn_1_55FF0(f32);
extern void fn_1_14E5E4(void *, s32, f32);
extern void fn_1_556B8(void *);
extern void lbl_8006DAEC(void);
extern void fn_1_87610(void *, void *);
extern void fn_1_875B4(void *, void *, void *, f32);
extern void fn_1_875EC(void *, void *, void *, f32);
extern void lbl_8006DC20(void);
extern void fn_80074A60(u32, u32);
extern void fn_80074A6C(void);
extern void OSPanic(const char *, int, const char *, ...);
extern s32 fn_1_3F164(void);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495C8(u8);
extern void fn_1_494DC(s16);
extern void fn_1_495B0(u32);
extern void fn_1_49514(void *);
extern u8 fn_1_58C4(void);
extern void fn_1_4955C(f32, f32);
extern f32 fn_1_51AC0(f32);
extern f32 fn_1_519FC(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_495A0(f32);
#pragma opt_common_subs off
#pragma opt_loop_invariants off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_7B180[2];
u32 fzgx_obj_lbl_1_bss_7B188;
u32 lbl_1_bss_7B188_fill_7B18C;
u32 lbl_1_bss_7B190[2];
u32 lbl_1_bss_7B198;
u32 lbl_1_bss_7B19C_fill_7B19C;
u32 lbl_1_bss_7B19C_4;
u32 fzgx_obj_lbl_1_bss_7B1A4[2];
u32 fzgx_obj_lbl_1_bss_7B1AC[1270];
u32 lbl_1_bss_7C584_fill_7C584[127];
f32 *lbl_1_bss_7C584_1FC[1];
u32 lbl_1_bss_7C584_fill_7C784[49];
s32 lbl_1_bss_7C848;
u32 lbl_1_bss_7C848_fill_7C84C;
u32 lbl_1_bss_7C850_fill_7C850;
s32 lbl_1_bss_7C850_4;
u32 lbl_1_bss_7C850_fill_7C858;
u32 fzgx_obj_lbl_1_bss_7C85C[28];
u8 lbl_1_bss_7C85C_fill_7C8CC;
u8 lbl_1_bss_7C8CD;
u8 lbl_1_bss_7C8CE;
u8 lbl_1_bss_7C8CE_fill_7C8CF;
u32 lbl_1_bss_7C8CE_fill_7C8D0[2];
Vec3 lbl_1_bss_7C8CE_A[1];
u32 lbl_1_bss_7C8CE_fill_7C8E4[12];
Fn_1_ED540_Obj22 *lbl_1_bss_7C914[1];
u32 lbl_1_bss_7C914_fill_7C918[4];
void *lbl_1_bss_7C914_14[1];
u32 lbl_1_bss_7C914_fill_7C92C[4];
s32 lbl_1_bss_7C914_28;
u32 lbl_1_bss_7C914_fill_7C940[2];
s32 lbl_1_bss_7C948;
u32 lbl_1_bss_7C94C_fill_7C94C[13];
u16 lbl_1_bss_7C94C_34[1];
u16 lbl_1_bss_7C94C_fill_7C982;
u32 lbl_1_bss_7C94C_fill_7C984[8];
u32 lbl_1_bss_7C94C_58[1];
u32 lbl_1_bss_7C94C_fill_7C9A8[44];
u8 lbl_1_bss_7CA58[1][0x30];
u32 lbl_1_bss_7CA58_fill_7CA88[48];
u8 lbl_1_bss_7CA58_F0[1][0x620];
u32 lbl_1_bss_7CA58_fill_7D168[1568];
u32 fzgx_obj_lbl_1_bss_7E9E8[6];
u32 lbl_1_bss_7EA00_fill_7EA00[10];
u32 lbl_1_bss_7EA00_28;
u32 lbl_1_bss_7EA00_fill_7EA2C[3];
u32 lbl_1_bss_7EA38_fill_7EA38[3];
u8 lbl_1_bss_7EA38_C[1][0x30];
u32 lbl_1_bss_7EA38_fill_7EA74[48];
Vec3 lbl_1_bss_7EA38_FC[1];
u32 lbl_1_bss_7EA38_fill_7EB40[12];
s32 lbl_1_bss_7EA38_138[1];
u32 lbl_1_bss_7EA38_fill_7EB74[79];
s32 lbl_1_bss_7EA38_278;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B180;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B188;
    s = *(u8 *)&lbl_1_bss_7B188_fill_7B18C;
    s = *(u8 *)&lbl_1_bss_7B190;
    s = *(u8 *)&lbl_1_bss_7B198;
    s = *(u8 *)&lbl_1_bss_7B19C_fill_7B19C;
    s = *(u8 *)&lbl_1_bss_7B19C_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1A4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1AC;
    s = *(u8 *)&lbl_1_bss_7C584_fill_7C584;
    s = *(u8 *)&lbl_1_bss_7C584_1FC;
    s = *(u8 *)&lbl_1_bss_7C584_fill_7C784;
    s = *(u8 *)&lbl_1_bss_7C848;
    s = *(u8 *)&lbl_1_bss_7C848_fill_7C84C;
    s = *(u8 *)&lbl_1_bss_7C850_fill_7C850;
    s = *(u8 *)&lbl_1_bss_7C850_4;
    s = *(u8 *)&lbl_1_bss_7C850_fill_7C858;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7C85C;
    s = *(u8 *)&lbl_1_bss_7C85C_fill_7C8CC;
    s = *(u8 *)&lbl_1_bss_7C8CD;
    s = *(u8 *)&lbl_1_bss_7C8CE;
    s = *(u8 *)&lbl_1_bss_7C8CE_fill_7C8CF;
    s = *(u8 *)&lbl_1_bss_7C8CE_fill_7C8D0;
    s = *(u8 *)&lbl_1_bss_7C8CE_A;
    s = *(u8 *)&lbl_1_bss_7C8CE_fill_7C8E4;
    s = *(u8 *)&lbl_1_bss_7C914;
    s = *(u8 *)&lbl_1_bss_7C914_fill_7C918;
    s = *(u8 *)&lbl_1_bss_7C914_14;
    s = *(u8 *)&lbl_1_bss_7C914_fill_7C92C;
    s = *(u8 *)&lbl_1_bss_7C914_28;
    s = *(u8 *)&lbl_1_bss_7C914_fill_7C940;
    s = *(u8 *)&lbl_1_bss_7C948;
    s = *(u8 *)&lbl_1_bss_7C94C_fill_7C94C;
    s = *(u8 *)&lbl_1_bss_7C94C_34;
    s = *(u8 *)&lbl_1_bss_7C94C_fill_7C982;
    s = *(u8 *)&lbl_1_bss_7C94C_fill_7C984;
    s = *(u8 *)&lbl_1_bss_7C94C_58;
    s = *(u8 *)&lbl_1_bss_7C94C_fill_7C9A8;
    s = *(u8 *)&lbl_1_bss_7CA58;
    s = *(u8 *)&lbl_1_bss_7CA58_fill_7CA88;
    s = *(u8 *)&lbl_1_bss_7CA58_F0;
    s = *(u8 *)&lbl_1_bss_7CA58_fill_7D168;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7E9E8;
    s = *(u8 *)&lbl_1_bss_7EA00_fill_7EA00;
    s = *(u8 *)&lbl_1_bss_7EA00_28;
    s = *(u8 *)&lbl_1_bss_7EA00_fill_7EA2C;
    s = *(u8 *)&lbl_1_bss_7EA38_fill_7EA38;
    s = *(u8 *)&lbl_1_bss_7EA38_C;
    s = *(u8 *)&lbl_1_bss_7EA38_fill_7EA74;
    s = *(u8 *)&lbl_1_bss_7EA38_FC;
    s = *(u8 *)&lbl_1_bss_7EA38_fill_7EB40;
    s = *(u8 *)&lbl_1_bss_7EA38_138;
    s = *(u8 *)&lbl_1_bss_7EA38_fill_7EB74;
    s = *(u8 *)&lbl_1_bss_7EA38_278;
}
#pragma section code_type ".text"

static inline f32 fn_1_ED540_value_region(void) {
if (lbl_1_bss_7EA00_28 < 15) {
return (f32)lbl_1_bss_7EA00_28 / lbl_1_rodata_6CF4;
}

return lbl_1_rodata_6BD0;

}
void fn_1_ED540(void) {
u8 *p_lbl_1_data_3E358;
void * lab_t0;
void * lab_t0_;
u8 (*p_29)[0x30];
Vec3 *p_28;
s32 *p_27;
u16 *p_26;
f32 **p_25;
u32 *p_24;
void **p_23;
Fn_1_ED540_Obj22 **p_22;
Vec3 *p_21;
u8 (*p_20)[0x620];
s32 var_r19;
Vec3 *p_18;
u8 (*p_17)[0x30];
s32 i;
s32 max_val;
s32 var_r14;
void *first_p_17;
u32 color9;
u32 color8;
u32 color7;
u32 color6;
u32 color5;
u32 color4;
u32 color3;
u32 color2;
u32 color1;
Vec3 vec_2c;
Vec3 vec_38;
Vec3 vec_44;
u8 obj_50[0x30];
u8 obj_80[0x30];
f32 f30;
f32 f31;
f32 f1;
f32 distSq;
f32 dx, dy, dz;
char sign;
s32 time_val;

p_lbl_1_data_3E358 = (u8 *)&lbl_1_data_3E358;
if (fzgx_obj_lbl_1_bss_7B188 == 0) {
return;
}
if (fn_1_4C10() != 0) {
p_20 = (u8 (*)[0x620])lbl_1_bss_7CA58_F0;
for (i = 0; i < (s32)lbl_1_bss_7C8CE; i++) {
fn_1_984F0(p_20);
p_20++;
}
return;
}
if (lbl_1_bss_7C8CE <= 1) {
var_r14 = 0;
} else if (lbl_1_bss_7C8CE <= 3) {
var_r14 = 1;
} else {
var_r14 = 2;
}
p_17 = (u8 (*)[0x30])lbl_1_bss_7CA58;
p_18 = (Vec3 *)lbl_1_bss_7C8CE_A;
p_20 = (u8 (*)[0x620])lbl_1_bss_7CA58_F0;
var_r19 = var_r14 * 0xC;
first_p_17 = p_17;
p_21 = p_18;
max_val = 0x80000001;
p_29 = (u8 (*)[0x30])lbl_1_bss_7EA38_C;
p_28 = (Vec3 *)lbl_1_bss_7EA38_FC;
p_27 = (s32 *)lbl_1_bss_7EA38_138;
p_26 = (u16 *)lbl_1_bss_7C94C_34;
p_25 = (f32 **)lbl_1_bss_7C584_1FC;
p_24 = (u32 *)lbl_1_bss_7C94C_58;
p_23 = (void **)lbl_1_bss_7C914_14;
p_22 = (Fn_1_ED540_Obj22 **)lbl_1_bss_7C914;
i = 0;
p_20 = (u8 (*)[0x620])((u8 *)p_20 + 0x620);
for (; i < (s32)lbl_1_bss_7C8CE; i++) {
fn_80008BEC(p_17, 0, 0x30);
lbl_8006DD14(p_29, obj_80);
vec_44 = *p_28;
if (max_val < *p_27) {
max_val = *p_27;
}
if (lbl_1_bss_7C848 >= 0) {
if (i == 0 && lbl_1_bss_7C94C_34[0] <= 1) {
*(u32 *)&vec_2c.x = lbl_1_rodata_6CBC[0];
*(u32 *)&vec_2c.y = lbl_1_rodata_6CBC[1];
*(u32 *)&vec_2c.z = lbl_1_rodata_6CBC[2];
lbl_8006D758();
lab_t0_ = obj_50;
lbl_8006DB74(lab_t0_);
fn_1_F143C(p_20, 0, &vec_2c, &vec_2c, obj_50);
fn_1_F23E8();
fn_1_98634(lbl_1_rodata_6C90);
fn_1_983CC(p_20, lbl_1_bss_7C914[0]);
fn_1_98634(lbl_1_rodata_6B60);
} else {
fn_1_984F0(p_20);
}
}
if (*p_26 > 1) {
f32 f2 = (*p_25)[*p_24 - 1];
if (f2 > (f32)*p_26) {
if (f2 <= (f32)(s32)(*p_26 + 1)) {
if (lbl_1_bss_7C850_4 == 0) {
lbl_1_bss_7C850_4 = 1;
}
}
fn_1_56298(lbl_1_rodata_6B60, lbl_1_rodata_6B60, lbl_1_rodata_6B60, lbl_1_rodata_6B60);
fn_1_5621C(lbl_1_rodata_6BD0, lbl_1_rodata_6BD0, lbl_1_rodata_6BD0, lbl_1_rodata_6BD0);
fn_1_681C(fn_1_5910(), &vec_38);
dx = vec_38.x - vec_44.x;
dy = vec_38.y - vec_44.y;
dz = vec_38.z - vec_44.z;
distSq = (f32)(dx * dx) + dy * dy + dz * dz;
if (((((((((distSq) - lbl_1_rodata_6CF4) < (lbl_1_rodata_6B60)) ? (lbl_1_rodata_6B60) : ((((distSq) - lbl_1_rodata_6CF4) > (lbl_1_rodata_6CF0)) ? (lbl_1_rodata_6CF0) : ((distSq) - lbl_1_rodata_6CF4))) / lbl_1_rodata_6CF8 * lbl_1_rodata_6CEC)) < (lbl_1_rodata_6B60)) ? (lbl_1_rodata_6B60) : ((((((((distSq) - lbl_1_rodata_6CF4) < (lbl_1_rodata_6B60)) ? (lbl_1_rodata_6B60) : ((((distSq) - lbl_1_rodata_6CF4) > (lbl_1_rodata_6CF0)) ? (lbl_1_rodata_6CF0) : ((distSq) - lbl_1_rodata_6CF4))) / lbl_1_rodata_6CF8 * lbl_1_rodata_6CEC)) > (lbl_1_rodata_6BBC)) ? (lbl_1_rodata_6BBC) : ((((((distSq) - lbl_1_rodata_6CF4) < (lbl_1_rodata_6B60)) ? (lbl_1_rodata_6B60) : ((((distSq) - lbl_1_rodata_6CF4) > (lbl_1_rodata_6CF0)) ? (lbl_1_rodata_6CF0) : ((distSq) - lbl_1_rodata_6CF4))) / lbl_1_rodata_6CF8 * lbl_1_rodata_6CEC)))) >= lbl_1_rodata_6CFC) {
fn_1_681C(fn_1_5910(), &vec_38);
psvec_sub(&vec_44, &vec_38, &vec_38);
f30 = lbl_8006D0B4((f32)(vec_38.x * vec_38.x) + vec_38.y * vec_38.y + vec_38.z * vec_38.z);
lbl_8006D668(&vec_38);
psvec_scale(&vec_38, lbl_1_rodata_6CFC, &vec_38);
psvec_add(&vec_44, &vec_38, &vec_38);
fn_1_56000(1, 3, 1);
lbl_8006DCA4();
lbl_8006E0A4(&vec_38);
lab_t0 = obj_80;
lbl_8006DFC4(lab_t0);
lbl_8006E14C((lbl_1_rodata_6CFC + f30) / f30);
fn_80072558();
fn_1_55FF0(lbl_1_rodata_6D00);
if (lbl_1_bss_7B19C_4 != 0 && i == (s32)lbl_1_bss_7C8CE - 1) {
fn_1_5621C(lbl_1_rodata_6C18, lbl_1_rodata_6C18, lbl_1_rodata_6BD0, lbl_1_rodata_6BD0);
} else {
fn_1_5621C(lbl_1_rodata_6BD0, lbl_1_rodata_6BD0, lbl_1_rodata_6C18, lbl_1_rodata_6BD0);
}
if (*p_23 != ((void *)0) ) {
fn_1_14E5E4(*p_23, (*p_22)->field_3BA, lbl_1_rodata_6D00);
} else if (*p_22 != ((void *)0) ) {
fn_1_556B8((*p_22)->unk_334[var_r14].unk_00[0]);
lbl_8006DAEC();
fn_1_87610(*p_22, *p_22);
fn_1_875B4(*p_22, *p_22, (void *)(s8)(*p_22)->field_3BA, lbl_1_rodata_6D00);
lbl_8006DC20();
}
fn_1_5621C(lbl_1_rodata_6BD0, lbl_1_rodata_6BD0, lbl_1_rodata_6BD0, lbl_1_rodata_6BD0);
fn_1_56000(1, 3, 1);
fn_1_681C(fn_1_5910(), &vec_38);
dx = vec_38.x - vec_44.x;
dy = vec_38.y - vec_44.y;
dz = vec_38.z - vec_44.z;
distSq = (f32)(dx * dx) + dy * dy + dz * dz;
f30 = ((((((((distSq) - lbl_1_rodata_6CF4) < (lbl_1_rodata_6B60)) ? (lbl_1_rodata_6B60) : ((((distSq) - lbl_1_rodata_6CF4) > (lbl_1_rodata_6CF0)) ? (lbl_1_rodata_6CF0) : ((distSq) - lbl_1_rodata_6CF4))) / lbl_1_rodata_6CF8 * lbl_1_rodata_6CEC)) < (lbl_1_rodata_6B60)) ? (lbl_1_rodata_6B60) : ((((((((distSq) - lbl_1_rodata_6CF4) < (lbl_1_rodata_6B60)) ? (lbl_1_rodata_6B60) : ((((distSq) - lbl_1_rodata_6CF4) > (lbl_1_rodata_6CF0)) ? (lbl_1_rodata_6CF0) : ((distSq) - lbl_1_rodata_6CF4))) / lbl_1_rodata_6CF8 * lbl_1_rodata_6CEC)) > (lbl_1_rodata_6BBC)) ? (lbl_1_rodata_6BBC) : ((((((distSq) - lbl_1_rodata_6CF4) < (lbl_1_rodata_6B60)) ? (lbl_1_rodata_6B60) : ((((distSq) - lbl_1_rodata_6CF4) > (lbl_1_rodata_6CF0)) ? (lbl_1_rodata_6CF0) : ((distSq) - lbl_1_rodata_6CF4))) / lbl_1_rodata_6CF8 * lbl_1_rodata_6CEC)))) ;
lbl_8006DCA4();
lbl_8006E0A4(&vec_44);
lab_t0 = obj_80;
lbl_8006DFC4(lab_t0);
lab_t0_ = p_17;
lbl_8006DB74(lab_t0_);
fn_80072558();
if (i > 0) {
if (__fabs(p_21->x - p_18->x) < lbl_1_rodata_6D08 &&
__fabs(p_21->y - p_18->y) < lbl_1_rodata_6D08 &&
__fabs(p_21->z - p_18->z) < lbl_1_rodata_6D08) {
if ((lbl_801A66A0 / 60) % 5 == i) {
fn_80008BEC(first_p_17, 0, 0x30);
} else {
fn_80008BEC(p_17, 0, 0x30);
}
}
}
if (*p_26 < 60) {
f30 *= (f32)*p_26 / lbl_1_rodata_6D10;
}
fn_1_55FF0(f30);
fn_80074A60(4, 1);
if (lbl_1_bss_7B19C_4 != 0 && i == (s32)lbl_1_bss_7C8CE - 1) {
fn_1_5621C(lbl_1_rodata_6C18, lbl_1_rodata_6C18, lbl_1_rodata_6BD0, lbl_1_rodata_6BD0);
} else {
fn_1_5621C(lbl_1_rodata_6BD0, lbl_1_rodata_6BD0, lbl_1_rodata_6C18, lbl_1_rodata_6BD0);
}
if (*p_22 != ((void *)0) ) {
lab_t0_ = obj_80;
lbl_8006DB74(lab_t0_);
if ((*p_22)->unk_390 & 0x04000000) {
if ((*p_22)->unk_3A0 == ((void *)0) ) {
return;
}
fn_1_14E5E4((*p_22)->unk_3A0, (s16)var_r14, f30);
} else {
if ((*p_22)->field_328 >= 0x29) {
OSPanic((const char *)p_lbl_1_data_3E358 + 0x2D4, 0xB1D, (const char *)p_lbl_1_data_3E358 + 0x3E4);
}
fn_1_556B8((*p_22)->unk_334[var_r14].unk_00[0]);
lbl_8006DAEC();
fn_1_87610(*p_22, *p_22);
fn_1_875EC(*p_22, *p_22, (void *)(s8)(*p_22)->field_3BA, f30);
lbl_8006DC20();
}
}
fn_80074A6C();
fn_1_5621C(lbl_1_rodata_6BD0, lbl_1_rodata_6BD0, lbl_1_rodata_6BD0, lbl_1_rodata_6BD0);
fn_1_56000(1, 3, 1);
}
}
}
p_17++;
p_29++;
p_28++;
p_27++;
p_26++;
p_25++;
p_24++;
p_23++;
p_22++;
p_21++;
}
if (lbl_1_bss_7C948 != 0 && (lbl_1_bss_960 == 2 || lbl_1_bss_960 == 9)) {
if (lbl_1_bss_7C850_4 != 0) {
lbl_1_bss_7C914_28 = lbl_1_bss_7C850_4 + max_val;
if (fn_1_3F164() == 0) {
lbl_1_bss_7C850_4 += 16;
}
} else {
lbl_1_bss_7C914_28 = max_val;
}
if (lbl_1_bss_7C8CE != 0) {
fn_1_49410();
fn_1_495FC();
fn_1_495C8(2);
fn_1_494DC(10);
fn_1_495B0(0x80000000);
if (lbl_1_bss_7C850_4 != 0) {
if (lbl_1_bss_7C914_28 > 0) {
color1 = lbl_1_rodata_6CC8;
fn_1_49514(&color1);
} else if (lbl_1_bss_7C914_28 == 0) {
color2 = lbl_1_rodata_6CCC;
fn_1_49514(&color2);
} else {
color3 = lbl_1_rodata_6CD0;
fn_1_49514(&color3);
}
} else {
if (lbl_1_bss_7C914_28 > 0) {
color4 = lbl_1_rodata_6CD4;
fn_1_49514(&color4);
} else if (lbl_1_bss_7C914_28 == 0) {
color5 = lbl_1_rodata_6CD8;
fn_1_49514(&color5);
} else {
color6 = lbl_1_rodata_6CDC;
fn_1_49514(&color6);
}
}
f30 = (fn_1_58C4() == 1) ? lbl_1_rodata_6BD0 : lbl_1_rodata_6D14;
f1 = (fn_1_58C4() == 1) ? lbl_1_rodata_6BD0 : lbl_1_rodata_6D14;
fn_1_4955C(lbl_1_rodata_6BBC * f1, lbl_1_rodata_6BBC * f30);
f30 = fn_1_51AC0(lbl_1_rodata_6D1C);
fn_1_496FC(fn_1_519FC(lbl_1_rodata_6D18), f30);
if (lbl_1_bss_7C914_28 > 0) {
sign = ':';
} else if (lbl_1_bss_7C914_28 == 0) {
sign = ' ';
} else {
sign = ';';
}
time_val = lbl_1_bss_7C914_28;
fn_1_4AE0C((const char *)p_lbl_1_data_3E358 + 0x3F8, sign,
(((time_val) < 0) ? -(time_val) : (time_val)) / 60000,
((((time_val) < 0) ? -(time_val) : (time_val)) % 60000) / 1000,
(((time_val) < 0) ? -(time_val) : (time_val)) % 1000);
}
}
if (lbl_1_bss_7C8CE != 0 && lbl_1_bss_7EA00_28 != 0) {
if (lbl_1_bss_7EA00_28 % 20 > 7) {
fn_1_49410();
fn_1_495FC();
fn_1_495C8(9);
if (lbl_1_bss_7EA00_28 > 165) {
f31 = (f32)(180 - lbl_1_bss_7EA00_28) / lbl_1_rodata_6CF4;
} else f31 = fn_1_ED540_value_region();
fn_1_494DC(10);
fn_1_495B0(0x80000000);
if (lbl_1_bss_7EA38_278 > 0) {
color7 = lbl_1_rodata_6CE0;
fn_1_49514(&color7);
} else if (lbl_1_bss_7EA38_278 == 0) {
color8 = lbl_1_rodata_6CE4;
fn_1_49514(&color8);
} else {
color9 = lbl_1_rodata_6CE8;
fn_1_49514(&color9);
}
f30 = (fn_1_58C4() == 1) ? lbl_1_rodata_6BD0 : lbl_1_rodata_6D14;
f1 = (fn_1_58C4() == 1) ? lbl_1_rodata_6BD0 : lbl_1_rodata_6D14;
fn_1_4955C(f31 * f1, f30);
fn_1_495A0(lbl_1_rodata_6BBC * f31);
f30 = fn_1_51AC0(lbl_1_rodata_6D24);
fn_1_496FC(fn_1_519FC(lbl_1_rodata_6D20), f30);
if (lbl_1_bss_7EA38_278 > 0) {
sign = ':';
} else if (lbl_1_bss_7EA38_278 == 0) {
sign = ' ';
} else {
sign = ';';
}
time_val = lbl_1_bss_7EA38_278;
fn_1_4AE0C((const char *)p_lbl_1_data_3E358 + 0x3F8, sign,
(((time_val) < 0) ? -(time_val) : (time_val)) / 60000,
((((time_val) < 0) ? -(time_val) : (time_val)) % 60000) / 1000,
(((time_val) < 0) ? -(time_val) : (time_val)) % 1000);
}
if (fn_1_3F164() == 0) {
lbl_1_bss_7EA00_28--;
}
}
}
#pragma opt_loop_invariants reset
#pragma opt_common_subs reset
