/* Non-matching: best partial attempt (87.27% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef s32 u32;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef int BOOL;
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
struct fn_8_D630_rodata {
u8 pad_0[0x6A8];
f64 unk_6A8;
f64 unk_6B0;
f64 unk_6B8;
f32 unk_6C0;
f32 unk_6C4;
f64 unk_6C8;
f32 unk_6D0;
u8 pad_6D4[0x4];
f64 unk_6D8;
f64 unk_6E0;
f32 unk_6E8;
f32 unk_6EC;
f64 unk_6F0;
f64 unk_6F8;
};
struct fn_8_D630_550 {
u32 unk_0;
};
#pragma pack(1)
struct fn_8_D630_obj {
u8 unk_0;
u8 unk_1;
u8 unk_2;
u8 unk_3;
u16 unk_4;
u16 unk_6;
u16 unk_8;
u16 unk_A;
u8 unk_C;
u32 unk_D;
};
#pragma pack()
extern struct fn_8_D630_550 lbl_10_bss_55CD8;
extern struct fn_8_D630_rodata lbl_10_rodata_1548;
extern u8 lbl_10_data_68E0[];
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_801A6410;
extern u8 lbl_10_bss_55CDC;
extern void fn_1_46B4(u32, u32, const char *, int);
extern u32 fn_1_4060(void);
extern s32 strncmp(const char *, const char *, size_t);
extern char * strncpy(char *, const char *, size_t);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495C8(u8);
extern void fn_1_49514(u32 *);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_A2D84(u32);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_4A0D8(const char *);
#pragma opt_common_subs off
static inline f64 fn_10_2325C_read_pointer(struct fn_8_D630_rodata * owner) { return owner->unk_6C8; }
#pragma opt_loop_invariants off
void fn_10_2325C(u32 arg0)
{
s32 e;
u32 n2;
u32 t;
f32 f;
struct FzgxCopy_88 {
u32 words[22];
} loc_20;
u8 name[4];
u8 ph[4];
u32 col1;
u32 col2;
u32 col3;
u32 col4;
u8 *d;
struct fn_8_D630_rodata *r;
struct fn_8_D630_obj *p;
p = (struct fn_8_D630_obj *)arg0;
r = &lbl_10_rodata_1548;
d = lbl_10_data_68E0;
if (lbl_10_bss_55CDC != 0) {
fn_1_46B4(lbl_801A6410, (u32)p, (const char *)(d + 0xA0), 0xFB);
fn_1_4060();
return;
}
n2 = (p->unk_C + 1) & 0x1F;
t = lbl_10_bss_55CD8.unk_0;
if (((__rlwnm(*(u32 *)(t + 32), 32 - (n2), 31, 31))) != 0) {
if (p->unk_0 != 1 || p->unk_1 != 0x18) {
p->unk_0 = 4;
p->unk_1 = 0x10;
t = lbl_10_bss_55CD8.unk_0;
*(u32 *)(t + 32) &= ~(0x80000000U >> p->unk_C);
if (strncmp((const char *)p + 2, (const char *)(d + 0xB0), 2) == 0) {
strncpy((char *)p + 2, (const char *)(d + 0xB4), 2);
name[0] = p->unk_2;
name[1] = p->unk_3;
}
}
}
name[0] = p->unk_2;
name[1] = p->unk_3;
name[2] = 0;
fn_1_49410();
fn_1_494DC(0x2A);
fn_1_495C8(9);
switch (p->unk_0) {
case 1:
onetwo:
{
u16 c4 = p->unk_4;
u16 c6 = p->unk_6;
s32 t4 = (s32)p->unk_8 - (s32)c4;
f64 dd = r->unk_6A8 * (f64)t4;
if ((s32)dd != 0) {
p->unk_4 = (u16)(s32)((f64)(u32)c4 + dd);
} else {
e = (t4 < 0 ? -1 : (t4 > 0 ? 1 : 0));
p->unk_4 = c4 + e;
}
{
s32 t6 = (s32)p->unk_A - (s32)c6;
dd = r->unk_6A8 * (f64)t6;
if ((s32)dd != 0) {
p->unk_6 = (u16)(s32)((f64)(u32)c6 + dd);
} else {
e = (t6 < 0 ? -1 : (t6 > 0 ? 1 : 0));
p->unk_6 = c6 + e;
}
}
}
col1 = p->unk_D;
fn_1_49514(&col1);
fn_1_496FC((f32)p->unk_4, (f32)p->unk_6);
f = (f32)(r->unk_6C8 * (r->unk_6B8 + (f64)(u32)(0x18 - p->unk_1) / r->unk_6C0));
fn_1_4955C(f, f);
if (p->unk_1 == 1) {
p->unk_0 = 2;
p->unk_4 = p->unk_8;
p->unk_6 = p->unk_A;
}
break;
case 2:
if (p->unk_1 == 0) {
p->unk_1 = 4;
fn_1_A2D84(0xA9010100);
}
*(u32 *)ph = p->unk_D;
f = (f32)p->unk_1;
f = ((r->unk_6C4) * (f));
ph[0] = (u8)((s32)((f32)ph[0] + (f32)((f32)(0xFF - ph[0]) * f)));
ph[1] = (u8)((s32)((f32)ph[1] + (f32)((f32)(0xFF - ph[1]) * f)));
ph[2] = (u8)((s32)((f32)ph[2] + (f32)((f32)(0xFF - ph[2]) * f)));
col2 = *(u32 *)ph;
fn_1_49514(&col2);
fn_1_496FC((f32)p->unk_4, (f32)p->unk_6);
f = (f32)(r->unk_6C8 * (r->unk_6C8 + (f32)(r->unk_6B8 * (f64)f)));
fn_1_4955C(f, f);
loc_20 = *(struct FzgxCopy_88 *)(&lbl_1_rodata_26F8 - 4);
loc_20.words[0] = 0x8F09;
f = (f32)(r->unk_6D8 + (f32)(r->unk_6F8 * (f64)f));
*(f32 *)(&loc_20.words[1]) = (f32)p->unk_4;
*(f32 *)(&loc_20.words[2]) = (f32)p->unk_6;
*(f32 *)(&loc_20.words[3]) = r->unk_6D0;
*(f32 *)(&loc_20.words[4]) = f;
*(f32 *)(&loc_20.words[5]) = f;
loc_20.words[0xC] = 0xA;
fn_1_4F734((FontDrawPacket *)&loc_20);
if (p->unk_1 == 1) {
p->unk_0 = 3;
if (strncmp((const char *)p + 2, (const char *)(d + 0xB4), 2) == 0) {
strncpy((char *)p + 2, (const char *)(d + 0xB0), 2);
name[0] = p->unk_2;
name[1] = p->unk_3;
}
}
goto onetwo;
case 3:
col3 = p->unk_D;
fn_1_49514(&col3);
fn_1_496FC((f32)p->unk_4, (f32)p->unk_6);
fn_1_4955C(r->unk_6E8, r->unk_6E8);
break;
case 4:
if (p->unk_1 == 0) {
fn_1_46B4(lbl_801A6410, (u32)p, (const char *)(d + 0xA0), 0x169);
fn_1_4060();
return;
}
col4 = p->unk_D;
fn_1_49514(&col4);
fn_1_496FC((f32)p->unk_4, (f32)p->unk_6);
f = (f32)(fn_10_2325C_read_pointer(r) * (r->unk_6C8 + (f32)(r->unk_6B8 * (f64)(u32)(0x10 - p->unk_1))));
fn_1_4955C(f, f);
fn_1_495A0((f32)p->unk_1 * r->unk_6EC);
break;
}
fn_1_4A0D8((const char *)name);
p->unk_1--;
}
#pragma opt_loop_invariants reset

#pragma opt_common_subs reset
