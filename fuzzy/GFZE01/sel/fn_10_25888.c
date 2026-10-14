/* Non-matching: best partial attempt (93.50% in the project ledger). Scored for the
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
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    u8 unk_F;
    u8 unk_10;
    u8 unk_11;
    u16 unk_12;
    u8 unk_14;
    u8 unk_15;
    u8 unk_16;
    u8 unk_17;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u8 pad_24[0x4];
    u8 unk_28;
    u8 pad_29[0xD];
    u8 unk_36;
    u8 unk_37;
    u8 pad_38[0x2];
    u8 unk_3A;
    u8 unk_3B;
    u32 unk_3C;
} Obj_10_bss_55CD8_Target;
extern Obj_10_bss_55CD8_Target *lbl_10_bss_55CD8;
extern u8 lbl_10_data_68E0[0xA0];
extern u32 lbl_10_rodata_1D64;
extern u32 lbl_10_rodata_1D68;
extern s32 lbl_801A66B4;

struct fn_10_25888_lbl_801A6410 {
    u32 unk_0;
};
extern struct fn_10_25888_lbl_801A6410 lbl_801A6410;

extern void fn_1_435C(u32 value);
extern s32 fn_1_45D0(u32, u32, u8 *, u32);
extern s32 fn_1_3F8C(u8 *, u32, u32, u32);
extern void fn_1_A2D84(u32 value);
extern s32 fn_1_14CEB8(u32);
extern void fn_80083DB0(void *, void *);
extern void fn_10_2325C(void);

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    u16 unk_A;
    s8 unk_C;
    u8 pad_D[0x3];
    u32 unk_10;
} Entry_10_25888;

#pragma peephole off
static inline u8 fn_10_25888_array_read(u8 *array, s32 index) { return array[index]; }
#pragma peephole reset


#pragma opt_loop_invariants off
#pragma opt_dead_assignments on
#pragma opt_propagation off
#pragma opt_lifetimes off
s32 fn_10_25888(void) {
    u16 *fzgx_value__;
    u32 fzgx_value_;
    u32 fzgx_value;
    struct { u32 value; } c;
    u8 *data;
    Entry_10_25888 *t;
    struct { s32 value; } i;
    struct { s32 value; } fzgx_loop_i_4853;
    u8 *src;
    Obj_10_bss_55CD8_Target *p;
    u32 n;
    s32 res;
    u32 lab_t3;
    res = 0;
    data = lbl_10_data_68E0;
    if ((lbl_10_bss_55CD8->unk_0 >> 30) & 1) {
    /* retail parks this pool constant in a frame slot across the fn_1_435C call */
    volatile u32 sp_c = lbl_10_rodata_1D68;
    u8 fzgx_loop_n_4853;
fn_1_435C(lbl_10_bss_55CD8->unk_8);
c.value = sp_c;
fzgx_loop_n_4853 = 0;
fzgx_loop_i_4853.value = 0;
while ((p = *(Obj_10_bss_55CD8_Target * volatile *)&lbl_10_bss_55CD8, src = (u8 *)p + 0x28 + fzgx_loop_i_4853.value, fn_10_25888_array_read(src, 0) != 0)) {
t = (Entry_10_25888 *)fn_1_45D0(lbl_801A6410.unk_0, 0x12, data + 0xA0, 0xD4);
t->unk_8 = ((0x7E) + (fzgx_loop_n_4853 * 0x38));
t->unk_A = 0x17A;
t->unk_0 = 2;
t->unk_1 = 0;
t->unk_4 = t->unk_8;
t->unk_6 = t->unk_A;
t->unk_2 = fn_10_25888_array_read(src, 0);
t->unk_3 = fn_10_25888_array_read(src, 1);
*(u32 *)((u8 *)t + 0xD) = c.value;
t->unk_C = fzgx_loop_n_4853;
lab_t3 = 0xB;
fn_1_3F8C(data + 0xC8, (u32)&fn_10_2325C, (u32)t, lab_t3);
fzgx_loop_i_4853.value += 2;
fzgx_loop_n_4853 += 1;
}
    n = fzgx_loop_n_4853;
    i.value = fzgx_loop_i_4853.value;
lbl_10_bss_55CD8->unk_0 = p->unk_0 & ~0x40000000;
}
if (lbl_10_bss_55CD8->unk_0 >> 31) {
return 1;
}
fzgx_value = lbl_10_bss_55CD8->unk_0;
if (((fzgx_value >> 29) & 1) || ((fzgx_value >> 28) & 1)) {
fn_1_A2D84(0xA9010100);
lbl_10_bss_55CD8->unk_0 &= ~0x20000000;
lbl_10_bss_55CD8->unk_0 &= ~0x10000000;
lbl_10_bss_55CD8->unk_0 |= 0x80000000;
if (fn_1_14CEB8((u32)lbl_10_bss_55CD8 + 0x28) != 0) {
n = 0;
i.value = 0;
lbl_10_bss_55CD8->unk_0 |= 0x40000000;
while (((u8 *)lbl_10_bss_55CD8)[0x28 + i.value] != 0) {
lbl_10_bss_55CD8->unk_20 |= 0x80000000 >> n;
i.value += 2;
n += 1;
}
}
if (((u8 *)lbl_10_bss_55CD8)[0x28] == 0) {
if (lbl_801A66B4 == 5) {
fn_80083DB0((u8 *)lbl_10_bss_55CD8 + 0x28, data + 0x114);
} else {
fn_80083DB0((u8 *)lbl_10_bss_55CD8 + 0x28, data + 0x120);
}
{
/* retail parks this pool constant in a frame slot across the fn_1_435C call */
volatile u32 sp_c2 = lbl_10_rodata_1D64;
u32 c2;
s32 fzgx_loop_i2;
u32 fzgx_loop_n2;
fn_1_435C(lbl_10_bss_55CD8->unk_8);
fzgx_loop_n2 = 0;
c2 = (sp_c2);
fzgx_loop_i2 = fzgx_loop_n2;
while ((src = (u8 *)lbl_10_bss_55CD8 + 0x28 + fzgx_loop_i2), fn_10_25888_array_read(src, 0) != 0) {
t = (Entry_10_25888 *)fn_1_45D0(lbl_801A6410.unk_0, 0x12, data + 0xA0, 0xD4);
t->unk_8 = fzgx_loop_n2 * 0x38 + 0x7E;
fzgx_value__ = &(t->unk_A);
*fzgx_value__ = 0x17A;
fzgx_value_ = 2;
t->unk_0 = fzgx_value_;
t->unk_1 = 0;
t->unk_4 = t->unk_8;
t->unk_6 = t->unk_A;
t->unk_2 = fn_10_25888_array_read(src, 0);
t->unk_3 = fn_10_25888_array_read(src, 1);
*(u32 *)((u8 *)t + 0xD) = c2;
t->unk_C = fzgx_loop_n2;
fzgx_loop_i2 += 2;
fn_1_3F8C(data + 0xC8, (u32)&fn_10_2325C, (u32)t, 0xB);
fzgx_loop_n2 += 1;
}
lbl_10_bss_55CD8->unk_E = fzgx_loop_n2;
}
}
res = 1;
}
return res;
}
#pragma opt_lifetimes reset

#pragma opt_propagation reset

#pragma opt_dead_assignments reset
#pragma opt_loop_invariants reset
