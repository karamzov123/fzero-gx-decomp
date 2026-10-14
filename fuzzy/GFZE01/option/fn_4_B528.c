/* Non-matching: best partial attempt (84.08% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef float f32;
typedef double f64;

typedef unsigned long size_t;
typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
u8 color[4], color_add[4];
u32 format;
u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);
struct fn_8_DD64_lbl_801A63D0 {
u32 unk_0;
};
struct fn_8_DD64_lbl_8_rodata_408 {
u8 pad_0[0x6F0];
f64 unk_6F0;
f64 unk_6F8;
f32 unk_700;
f32 unk_704;
f32 unk_708;
u32 unk_70C;
u32 unk_710;
u32 unk_714;
u32 unk_71C;
u32 unk_718;
u32 unk_720;
f32 unk_724;
f32 unk_728;
u8 pad_72C[0x4];
f64 unk_730;
f64 unk_738;
f32 unk_740;
u8 pad_744[0x4];
f64 unk_748;
f32 unk_750;
f32 unk_754;
};
extern char * fn_80083CF4(char *, const char *, size_t);
extern char * strcat(char *, const char *);
extern char * strncpy(char *, const char *, size_t);
extern int fn_1_4F734(FontDrawPacket *);
extern int sprintf(char *, const char *, ...);
extern size_t strlen(const char *);
extern struct fn_8_DD64_lbl_801A63D0 lbl_801A63D0;
extern struct fn_8_DD64_lbl_8_rodata_408 lbl_4_rodata_410;
extern u32 fn_1_4060(void);
extern u32 fn_1_49410(void);
extern u32 fn_800081C8(void *, void *, f32);
extern u32 fn_800793D4(u8 *, u32, void *);
extern u32 fn_80083DB0(u32, u32);
extern u32 lbl_801A6410;
extern u32 lbl_4_bss_5680;
extern u8 * fn_80083970(u8 *, const u8 *);
extern u8 lbl_1_rodata_26F8[];
extern u8 lbl_4_bss_5684;
extern u8 lbl_4_data_2F78[];
extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_1_494DC(s16);
extern void fn_1_49514(u32 *);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495C8(u8);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
#pragma opt_common_subs off
#pragma opt_lifetimes off
#pragma opt_loop_invariants off
static inline s32 fn_4_B528_operand(s32 left, s32 right) { return left ^ right; }
#pragma opt_strength_reduction off
u32 fn_4_B528(u32 arg0, f32 arg1, f32 arg2, f32 arg3) {
u8 *p_lbl_8_data_A1E8;
struct fn_8_DD64_lbl_8_rodata_408 *p_lbl_8_rodata_408;
u8 *p_lbl_1_rodata_26F8;
u32 v0;
f64 v25;
    struct { s32 value; } v2;
s32 v3;
u32 v4;
f32 v5;
f64 v6;
f32 v7;
    struct { u32 value; } v8;
u32 v9;
s32 v10;
u32 v11;
u32 v12;
u32 v13;
u32 v14;
u32 v15;
u32 v16;
u16 v17;
f64 v18;
u32 v19;
u8 * v20;
u32 v21;
u32 v22;
f64 v23;
f32 v24;
s32 v1;
f32 v26;
f32 v27;
struct { u32 a[24]; } loc_18;
u32 loc_14;
u32 loc_10[1];
u32 loc_C[1];
u32 loc_8[1];
u32 lab_t0;
u32 lab_t1;
p_lbl_8_data_A1E8 = (u8 *)&lbl_4_data_2F78;
p_lbl_8_rodata_408 = (struct fn_8_DD64_lbl_8_rodata_408 *)&lbl_4_rodata_410;
fn_800793D4((u8 *)lbl_801A63D0.unk_0, 0, (void *)1024);
v0 = lbl_801A63D0.unk_0;
v5 = arg1;
v6 = arg2;
v7 = arg3;
if (((0) != (lbl_4_bss_5684))) {
{ s32 __reg_value_v2 = arg0; v2.value = __reg_value_v2; }
v1 = (u32)&lbl_801A6410;
v3 = (u32)((u8 *)(u32)p_lbl_8_data_A1E8 + 160);
v1 = *(u32 *)((u8 *)v1 + 0);
v4 = 465;
fn_1_46B4(v1, v2.value, (const char *)v3, v4);
v1 = fn_1_4060();
} else {
v1 = fn_1_49410();
v1 = 42;
fn_1_494DC(v1);
v1 = 9;
fn_1_495C8(v1);
v5 = (12.0f);
v6 = (0.0f);
fn_1_4966C(v5, v6);
v1 = (u32)&lbl_4_bss_5680;
v1 = *(u32 *)((u8 *)v1 + 0);
v1 = *(u32 *)((u8 *)v1 + 60);
{ u32 __reg_value_v8 = (v1 + (*(u8 *)((u8 *)arg0 + 0) * 20)); v8.value = __reg_value_v8; }
v4 = *(u16 *)((u8 *)v8.value + 0);
v3 = (v4 - 10);
v1 = (v4 + 11);
if (v3 >= 0 && (s32)(v4 + 11) <= (s32)*(u16 *)((u8 *)v8.value + 2)) {
{ s32 __reg_value_v2 = *(u32 *)((u8 *)v8.value + 4); v2.value = __reg_value_v2; }
v1 = v0;
v9 = (v3 << 1);
v3 = 42;
{ s32 __reg_value_v2 = (v2.value + v9); v2.value = __reg_value_v2; }
v1 = (u32)strncpy((char *)v1, (const char *)v2.value, v3);
} else if (v4 < 10) {
v10 = (*(u16 *)((u8 *)v8.value + 2) + (v4 - 10));
if (v10 < 0) {
{ s32 __reg_value_v2 = *(u32 *)((u8 *)v8.value + 4); v2.value = __reg_value_v2; }
v1 = v0;
{ s32 __reg_value_v2 = (v2.value + (v4 << 1)); v2.value = __reg_value_v2; }
lab_t0 = v1;
lab_t1 = v2.value;
v1 = fn_80083DB0(lab_t0, lab_t1);
{ s32 __reg_value_v2 = *(u32 *)((u8 *)v8.value + 4); v2.value = __reg_value_v2; }
v1 = v0;
v1 = (u32)strcat((char *)v1, (const char *)v2.value);
{ s32 __reg_value_v2 = *(u32 *)((u8 *)v8.value + 4); v2.value = __reg_value_v2; }
v1 = v0;
v3 = ((v10 + 10) << 1);
v1 = (u32)fn_80083CF4((char *)v1, (const char *)v2.value, v3);
} else {
{ s32 __reg_value_v2 = *(u32 *)((u8 *)v8.value + 4); v2.value = __reg_value_v2; }
v1 = v0;
{ s32 __reg_value_v2 = (v2.value + (v10 << 1)); v2.value = __reg_value_v2; }
lab_t0 = v1;
lab_t1 = v2.value;
v1 = fn_80083DB0(lab_t0, lab_t1);
v1 = *(u16 *)((u8 *)v8.value + 0);
v11 = (v1 + 11);
if ((s32)v11 > (s32)*(u16 *)((u8 *)v8.value + 2)) {
{ s32 __reg_value_v2 = *(u32 *)((u8 *)v8.value + 4); v2.value = __reg_value_v2; }
v1 = v0;
v1 = (u32)strcat((char *)v1, (const char *)v2.value);
v1 = v0;
{ s32 __reg_value_v2 = *(u32 *)((u8 *)v8.value + 4); v2.value = __reg_value_v2; }
v3 = ((v11 - *(u16 *)((u8 *)v8.value + 2)) << 1);
v1 = (u32)fn_80083CF4((char *)v1, (const char *)v2.value, v3);
} else {
{ s32 __reg_value_v2 = *(u32 *)((u8 *)v8.value + 4); v2.value = __reg_value_v2; }
v1 = v0;
v3 = (v11 << 1);
v1 = (u32)fn_80083CF4((char *)v1, (const char *)v2.value, v3);
}
}
} else {
{ s32 __reg_value_v2 = *(u32 *)((u8 *)v8.value + 4); v2.value = __reg_value_v2; }
v1 = v0;
{ s32 __reg_value_v2 = (v2.value + (v3 << 1)); v2.value = __reg_value_v2; }
lab_t0 = v1;
lab_t1 = v2.value;
v1 = fn_80083DB0(lab_t0, lab_t1);
{ s32 __reg_value_v2 = *(u16 *)((u8 *)v8.value + 0); v2.value = __reg_value_v2; }
v1 = v0;
v3 = *(u16 *)((u8 *)v8.value + 2);
v12 = (v2.value + 11);
{ s32 __reg_value_v2 = *(u32 *)((u8 *)v8.value + 4); v2.value = __reg_value_v2; }
v3 = ((v12 - v3) << 1);
v1 = (u32)fn_80083CF4((char *)v1, (const char *)v2.value, v3);
}
{ s32 __reg_value_v2 = *(u8 *)((u8 *)arg0 + 0); v2.value = __reg_value_v2; }
v1 = (u32)&lbl_4_bss_5680;
v1 = *(u32 *)((u8 *)v1 + 0);
if (v2.value == *(u8 *)((u8 *)v1 + 13)) {
u32 b13;
u32 b14;
{ s32 __reg_value_v2 = (v0 + 6); v2.value = __reg_value_v2; }
v1 = (u32)&lbl_801A63D0;
v3 = 14;
v1 = *(u32 *)((u8 *)v1 + 0);
b13 = (v1 + 44);
b14 = (v1 + 88);
v1 = b13;
v1 = (u32)strncpy((char *)v1, (const char *)v2.value, v3);
v1 = b14;
{ s32 __reg_value_v2 = (v0 + 22); v2.value = __reg_value_v2; }
v3 = 14;
v1 = (u32)strncpy((char *)v1, (const char *)v2.value, v3);
v1 = v0;
v3 = b13;
v4 = b14;
{ s32 __reg_value_v2 = (u32)((u8 *)(u32)p_lbl_8_data_A1E8 + 184); v2.value = __reg_value_v2; }
v1 = sprintf((char *)v1, (const char *)(u32)v2.value, v3, v4);
}
v1 = (u32)&lbl_4_bss_5680;
v1 = *(u32 *)((u8 *)v1 + 0);
v1 = *(u8 *)((u8 *)v1 + 13);
v1 = (*(u8 *)((u8 *)arg0 + 0) - v1);
if (v1 < 0) {
v1 += 4;
}
switch ((s32)v1) {
case 0:
v15 = 178;
v16 = (32.0f);
loc_14 = p_lbl_8_rodata_408->unk_70C;
break;
case 1:
v15 = 276;
v16 = (24.0f);
loc_14 = p_lbl_8_rodata_408->unk_710;
break;
case 2:
v15 = 313;
v16 = (18.0f);
loc_14 = p_lbl_8_rodata_408->unk_714;
break;
case 3:
v15 = 84;
v16 = (24.0f);
loc_14 = p_lbl_8_rodata_408->unk_718;
}
{ s32 __reg_value_v2 = *(u16 *)((u8 *)arg0 + 4); v2.value = __reg_value_v2; }
v3 = (v15 - v2.value);
v6 = (0.20000000000000001) * (f64)(s32)v3;
if (((0) != ((s32)v6))) {
*(u16 *)((u8 *)arg0 + 4) =
(u16)(s32)((f64)(s32)v2.value - (4503599627370496.0) + v6);
} else {
if ((s32)v3 < 0) {
v1 = -1;
} else {
v1 = ((u32)((-v3) & ~v3) >> 31);
}
*(u16 *)((u8 *)arg0 + 4) = (((v1) + (*(u16 *)((u8 *)arg0 + 4))));
}
v6 = *(f32 *)((u8 *)arg0 + 8);
v5 = (0.20000000000000001);
*(f32 *)((u8 *)arg0 + 8) = (f32)(v6 + (f64)((v5 * (v16 - v6))));
v1 = *(u8 *)((u8 *)arg0 + 2);
v17 = *(u16 *)((u8 *)v8.value + 0);
{ s32 __reg_value_v2 = (v1 + 1); v2.value = __reg_value_v2; }
if ((((s32)v17) != ((s32)v2.value))) {
if (((s32)(v1 - 1) <= (s32)v17)) {
*(u8 *)((u8 *)arg0 + 1) = 36;
}
} else {
*(u8 *)((u8 *)arg0 + 1) = -36;
}
{ s32 __reg_value_v2 = (s8)*(u8 *)((u8 *)arg0 + 1); v2.value = __reg_value_v2; }
v3 = (-v2.value);
v6 = (0.20000000000000001) * (f64)(s32)v3;
if (((0) != ((s32)v6))) {
*(u8 *)((u8 *)arg0 + 1) =
(u8)(s32)((f64)(s32)v2.value - (4503599627370496.0) + v6);
} else {
if (v3 < 0) {
v1 = -1;
} else {
v1 = ((u32)((-v3) & ~v3) >> 31);
}
*(u8 *)((u8 *)arg0 + 1) = (((v1) + (*(u8 *)((u8 *)arg0 + 1))));
}
v1 = v0;
{ s32 __reg_value_v2 = (u32)((u8 *)(u32)p_lbl_8_data_A1E8 + 196); v2.value = __reg_value_v2; }
*(u8 *)((u8 *)arg0 + 2) = *(u16 *)((u8 *)v8.value + 0);
v1 = (u32)fn_80083970((u8 *)v1, (const u8 *)v2.value);
v18 = (4503601774854144.0);
p_lbl_1_rodata_26F8 = (u8 *)&lbl_1_rodata_26F8;
v19 = 0x10000 - 28914;
v20 = (u8 *)(v1);
while (((0) != ((u32)v20))) {
v1 = v0;
v1 = strlen((const char *)v1);
{ s32 __reg_value_v2 = (s32)(v20 - (u8 *)v0); v2.value = __reg_value_v2; }
v3 = (v1 - 1);
v1 = ((u32)v2.value >> 31);
v1 = (v1 + v2.value);
{ s32 __reg_value_v2 = ((u32)v3 >> 2); v2.value = __reg_value_v2; }
v1 = ((s32)v1 >> 1);
v3 = (u32)&loc_14;
v9 = (v1 - v2.value);
v4 = v9;
{ s32 __reg_value_v2 = ((u32)p_lbl_1_rodata_26F8 - 4); v2.value = __reg_value_v2; }
for (v21 = 11; ((0) != (v21)); v21--) {
v1 = *(u32 *)((u8 *)v2.value + 4);
v22 = *(u32 *)((u8 *)v2.value + 8);
{ s32 __reg_value_v2 = (u32)((u8 *)v2.value + 8); v2.value = __reg_value_v2; }
v23 = (4503599627370496.0);
v24 = (10.1000004f);
v25 = (24.0);
*(u32 *)((u8 *)v3 + 4) = v1;
*(u32 *)((u8 *)v3 + 8) = v22;
v3 += 8;
}
v3 = *(u8 *)((u8 *)arg0 + 1);
v1 = (s8)v3;
v26 = (f32)((f64)(s32)v4 * *(f32 *)((u8 *)arg0 + 8));
v5 = (f32)((f64)(s32)(v1 + 320));
*(f32 *)((u8 *)&loc_18 + 4) = (f32)(v5 + v26);
if (((fn_4_B528_operand((v4), (v1))) - v1) > 0) {
v3 = 1;
if ((s32)v4 < 0) {
v3 = -1;
}
{ s32 __reg_value_v2 = ((s32)v4 >> 31); v2.value = __reg_value_v2; }
v1 = (fn_4_B528_operand((v4), (v2.value)));
v1 = (v1 - v2.value);
v6 = (12.0);
v7 = *(f32 *)((u8 *)&loc_18 + 4);
*(f32 *)((u8 *)&loc_18 + 4) = (f32)(v7 + (f64)((v6 * (f64)(s32)(v3 * v1))));
}
v1 = (u32)loc_10;
v3 = p_lbl_8_rodata_408->unk_720;
{ s32 __reg_value_v2 = (u32)loc_C; v2.value = __reg_value_v2; }
*(f32 *)((u8 *)&loc_18 + 12) = v24;
v5 = (1.0f);
loc_18.a[12] = 10;
*(f32 *)((u8 *)&loc_18 + 8) = (f32)((f64)(u32)*(u16 *)((u8 *)arg0 + 4) - v23);
loc_C[0] = v3;
loc_10[0] = p_lbl_8_rodata_408->unk_71C;
v27 = (f32)(*(f32 *)((u8 *)arg0 + 8) / v25);
*(f32 *)((u8 *)&loc_18 + 20) = v27;
*(f32 *)((u8 *)&loc_18 + 16) = v27;
v1 = fn_800081C8((void *)v1, (void *)v2.value, v5);
loc_18.a[14] = v1;
v1 = (u32)&loc_18;
v1 = fn_1_4F734((FontDrawPacket *)v1);
v1 = (u32)((u8 *)v20 + 2);
{ s32 __reg_value_v2 = (u32)((u8 *)(u32)p_lbl_8_data_A1E8 + 196); v2.value = __reg_value_v2; }
v1 = (u32)fn_80083970((u8 *)v1, (const u8 *)v2.value);
v20 = (u8 *)(v1);
}
{ s32 __reg_value_v2 = *(u8 *)((u8 *)arg0 + 1); v2.value = __reg_value_v2; }
{ s32 __reg_value_v2 = (s8)v2.value; v2.value = __reg_value_v2; }
v2.value += 320;
v7 = (4503601774854144.0);
v6 = (4503599627370496.0);
v5 = (f32)(s32)v2.value;
v6 = (f32)(u32)*(u16 *)((u8 *)arg0 + 4);
fn_1_496FC(v5, v6);
v5 = *(f32 *)((u8 *)arg0 + 8);
v5 = (f32)(v5 / (24.0));
v6 = v5;
fn_1_4955C(v5, v6);
v1 = (u32)loc_8;
loc_8[0] = loc_14;
fn_1_49514((u32 *)v1);
v5 = (10.0f);
fn_1_4954C(v5);
v1 = v0;
fn_1_4A0D8((const char *)v1);
}
return 0;
}
#pragma opt_strength_reduction reset

#pragma opt_loop_invariants reset

#pragma opt_lifetimes reset
#pragma opt_common_subs reset
