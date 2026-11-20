#include "types.h"
#include "font.h"

typedef unsigned long size_t;

/* The work object of the name entry screen (one per screen, allocated in fn_10_25610). */
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
    u8 name[0xE];
    u8 unk_36;
    u8 unk_37;
    u8 pad_38[0x2];
    u8 unk_3A;
    u8 unk_3B;
    u32 unk_3C;
} Obj_4_bss_5680_Target;
typedef Obj_4_bss_5680_Target Obj_10_bss_55CD8_Target;

/* One character page: cursor, character count, the three letter cases and the page title. */
typedef struct NameEntryAlphabet {
    u16 selected_character;
    u16 reserved;
    const char *capital;
    const char *small;
    const char *signs;
    const char *label;
} NameEntryAlphabet;

typedef struct NameEntryRGBA {
    u8 r, g, b, a;
} NameEntryRGBA;

extern s16 lbl_1_bss_960;
extern u8 lbl_1_bss_9F8[];
extern u8 lbl_1_bss_A48[];
extern s32 lbl_801A66B4;
extern u32 lbl_801A66A0;
extern u32 lbl_801A6410;
extern void *lbl_1_data_418D4[];
extern const FontDrawPacket lbl_1_rodata_26F8;

extern s32 strncmp(const char *, const char *, size_t);
extern char *strncpy(char *, const char *, size_t);
extern char *strcat(char *, const char *);
extern size_t strlen(const char *);
extern int sprintf(char *, const char *, ...);
extern void *memset(void *, int, u32);
extern int __abs(int);
extern void *fn_1_45D0(u32, u32, const char *, u32);
extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern void fn_1_435C(u32);
extern void fn_1_A2D84(u32);
extern void fn_1_46B4(u32, u32, const char *, int);
extern u32 fn_1_4060(void);
extern u32 fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495C8(u8);
extern void fn_1_49514(NameEntryRGBA);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4955C(f32, f32);
extern char *fn_80083DB0(char *, const char *);
extern void *fn_800793D4(void *, s32, u32);
void fn_10_2325C();
/* Character pages of the name entry screen: the page title, then the letters of each case
   (Shift JIS, two bytes per letter). The Japanese pages come first, then the English pages. */
static const char lbl_10_rodata_1548[] = "\x89p\x90\x94";
static const char lbl_10_rodata_1550[] = "\x82`\x82\x61\x82\x62\x82\x63\x82\x64\x82\x65\x82\x66\x82g\x82h\x82i\x82j\x82k\x82l\x82m\x82n\x82o\x82p\x82q\x82r\x82s\x82t\x82u\x82v\x82w\x82x\x82y\x82\x81\x82\x82\x82\x83\x82\x84\x82\x85\x82\x86\x82\x87\x82\x88\x82\x89\x82\x8a\x82\x8b\x82\x8c\x82\x8d\x82\x8e\x82\x8f\x82\x90\x82\x91\x82\x92\x82\x93\x82\x94\x82\x95\x82\x96\x82\x97\x82\x98\x82\x99\x82\x9a\x82O\x82P\x82Q\x82R\x82S\x82T\x82U\x82V\x82W\x82X\x81\xe7\x81\xe8";
static const char lbl_10_rodata_15D4[] = "\x82\x81\x82\x82\x82\x83\x82\x84\x82\x85\x82\x86\x82\x87\x82\x88\x82\x89\x82\x8a\x82\x8b\x82\x8c\x82\x8d\x82\x8e\x82\x8f\x82\x90\x82\x91\x82\x92\x82\x93\x82\x94\x82\x95\x82\x96\x82\x97\x82\x98\x82\x99\x82\x9a\x82`\x82\x61\x82\x62\x82\x63\x82\x64\x82\x65\x82\x66\x82g\x82h\x82i\x82j\x82k\x82l\x82m\x82n\x82o\x82p\x82q\x82r\x82s\x82t\x82u\x82v\x82w\x82x\x82y\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@";
static const char lbl_10_rodata_1658[] = "\x8bL\x8d\x86";
static const char lbl_10_rodata_1660[] = "\x81\x41\x81\x42\x81L\x81M\x81\x45\x81\x43\x81\x44\x81\x46\x81G\x81H\x81I\x81{\x81|\x81^\x81\x81\x81\x83\x81\x84\x81O\x81Q\x81`\x81\x62\x81u\x81v\x81i\x81j\x81o\x81p\x81m\x81n\x81\x8f\x81\x90\x81\x93\x81\x94\x81\x95\x81\x96\x81\x97\x81\xe7\x81\xe8";
static const char lbl_10_rodata_16B0[] = "\x82\xd0\x82\xe7\x82\xaa\x82\xc8";
static const char lbl_10_rodata_16BC[] = "\x82\xa0\x82\xa2\x82\xa4\x82\xa6\x82\xa8\x82\xa9\x82\xab\x82\xad\x82\xaf\x82\xb1\x82\xb3\x82\xb5\x82\xb7\x82\xb9\x82\xbb\x82\xbd\x82\xbf\x82\xc2\x82\xc4\x82\xc6\x82\xc8\x82\xc9\x82\xca\x82\xcb\x82\xcc\x82\xcd\x82\xd0\x82\xd3\x82\xd6\x82\xd9\x82\xdc\x82\xdd\x82\xde\x82\xdf\x82\xe0\x82\xe2\x82\xe4\x82\xe6\x82\xe7\x82\xe8\x82\xe9\x82\xea\x82\xeb\x82\xed\x82\xee\x82\xef\x82\xf0\x82\xf1\x82\xaa\x82\xac\x82\xae\x82\xb0\x82\xb2\x82\xb4\x82\xb6\x82\xb8\x82\xba\x82\xbc\x82\xbe\x82\xc0\x82\xc3\x82\xc5\x82\xc7\x82\xce\x82\xd1\x82\xd4\x82\xd7\x82\xda\x82\xcf\x82\xd2\x82\xd5\x82\xd8\x82\xdb\x82\x9f\x82\xa1\x82\xa3\x82\xa5\x82\xa7\x82\xc1\x82\xe1\x82\xe3\x82\xe5\x82\xec\x81\xe7\x81\xe8";
static const char lbl_10_rodata_1768[] = "\x82\x9f\x82\xa1\x82\xa3\x82\xa5\x82\xa7\x82\xaa\x82\xac\x82\xae\x82\xb0\x82\xb2\x82\xb4\x82\xb6\x82\xb8\x82\xba\x82\xbc\x82\xbe\x82\xc0\x82\xc1\x82\xc5\x82\xc7\x81@\x81@\x81@\x81@\x81@\x82\xce\x82\xd1\x82\xd4\x82\xd7\x82\xda\x81@\x81@\x81@\x81@\x81@\x82\xe1\x82\xe3\x82\xe5\x81@\x81@\x81@\x81@\x81@\x82\xec\x81@\x81@\x81@\x81@\x82\xa9\x82\xab\x82\xad\x82\xaf\x82\xb1\x82\xb3\x82\xb5\x82\xb7\x82\xb9\x82\xbb\x82\xbd\x82\xbf\x82\xc2\x82\xc4\x82\xc6\x82\xcf\x82\xd2\x82\xd5\x82\xd8\x82\xdb\x82\xcd\x82\xd0\x82\xd3\x82\xd6\x82\xd9\x82\xa0\x82\xa2\x82\xa4\x82\xa6\x82\xa8\x82\xc2\x82\xe2\x82\xe4\x82\xe6\x82\xed\x81@\x81@";
static const char lbl_10_rodata_1814[] = "\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x82\xc3\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x82\xcf\x82\xd2\x82\xd5\x82\xd8\x82\xdb\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x82\xc1\x81@\x81@\x82\xcd\x82\xd0\x82\xd3\x82\xd6\x82\xd9\x82\xce\x82\xd1\x82\xd4\x82\xd7\x82\xda\x81@\x81@\x81@\x81@\x81@\x82\xc3\x81@\x81@\x81@\x81@\x81@\x81@";
static const char lbl_10_rodata_18C0[] = "\x83J\x83^\x83J\x83i";
static const char lbl_10_rodata_18CC[] = "\x83\x41\x83\x43\x83\x45\x83G\x83I\x83J\x83L\x83N\x83P\x83R\x83T\x83V\x83X\x83Z\x83\\\x83^\x83`\x83\x63\x83\x65\x83g\x83i\x83j\x83k\x83l\x83m\x83n\x83q\x83t\x82\xd6\x83z\x83}\x83~\x83\x80\x83\x81\x83\x82\x83\x84\x83\x86\x83\x88\x83\x89\x83\x8a\x83\x8b\x83\x8c\x83\x8d\x83\x8f\x83\x90\x83\x91\x83\x92\x83\x93\x83\x94\x83K\x83M\x83O\x83Q\x83S\x83U\x83W\x83Y\x83[\x83]\x83_\x83\x61\x83\x64\x83\x66\x83h\x83o\x83r\x83u\x82\xd7\x83{\x83p\x83s\x83v\x82\xd8\x83|\x83@\x83\x42\x83\x44\x83\x46\x83H\x83\x95\x83\x96\x83\x62\x83\x83\x83\x85\x83\x87\x83\x8e\x81\xe7\x81\xe8";
static const char lbl_10_rodata_1980[] = "\x83@\x83\x42\x83\x44\x83\x46\x83H\x83K\x83M\x83O\x83Q\x83S\x83U\x83W\x83Y\x83[\x83]\x83_\x83\x61\x83\x62\x83\x66\x83h\x81@\x81@\x81@\x81@\x81@\x83o\x83r\x83u\x82\xd7\x83{\x81@\x81@\x81@\x81@\x81@\x83\x83\x83\x85\x83\x87\x81@\x81@\x81@\x81@\x81@\x83\x8e\x81@\x81@\x81@\x81@\x83\x45\x83J\x83L\x83N\x83P\x83R\x83T\x83V\x83X\x83Z\x83\\\x83^\x83`\x83\x63\x83\x65\x83g\x83p\x83s\x83v\x82\xd8\x83|\x83n\x83q\x83t\x82\xd6\x83z\x83\x41\x83\x43\x83\x45\x83G\x83I\x83J\x83P\x83\x63\x83\x84\x83\x86\x83\x88\x83\x8f\x81@\x81@";
static const char lbl_10_rodata_1A34[] = "\x81@\x81@\x83\x94\x81@\x81@\x83\x95\x81@\x81@\x83\x96\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x83\x64\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x83p\x83s\x83v\x82\xd8\x83|\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x83\x44\x83\x95\x81@\x81@\x83\x96\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x81@\x83\x62\x81@\x81@\x83n\x83q\x83t\x82\xd6\x83z\x83o\x83r\x83u\x82\xd7\x83{\x81@\x81@\x83\x94\x81@\x81@\x83K\x83Q\x83\x64\x81@\x81@\x81@\x81@\x81@\x81@";
static const char lbl_10_rodata_1AE8[] = "Capital Letters";
static const char lbl_10_rodata_1AF8[] = "\x82`\x82\x61\x82\x62\x82\x63\x82\x64\x82\x65\x82\x66\x82g\x82h\x82i\x82j\x82k\x82l\x82m\x82n\x82o\x82p\x82q\x82r\x82s\x82t\x82u\x82v\x82w\x82x\x82y\x81\xe7\x81\xe8";
static const char lbl_10_rodata_1B34[] = "Small Letters";
static const char lbl_10_rodata_1B44[] = "\x82\x81\x82\x82\x82\x83\x82\x84\x82\x85\x82\x86\x82\x87\x82\x88\x82\x89\x82\x8a\x82\x8b\x82\x8c\x82\x8d\x82\x8e\x82\x8f\x82\x90\x82\x91\x82\x92\x82\x93\x82\x94\x82\x95\x82\x96\x82\x97\x82\x98\x82\x99\x82\x9a\x81\xe7\x81\xe8";
static const char lbl_10_rodata_1B80[] = "Signs";
static const char lbl_10_rodata_1B88[] = "\x81\x43\x81\x44\x81H\x81I\x81{\x81|\x81^\x81_\x81\x81\x81\x83\x81\x84\x81\x46\x81G\x81L\x81M\x81O\x81Q\x81\x62\x81i\x81j\x81m\x81n\x81o\x81p\x81\x90\x81\x93\x81\x94\x81\x95\x81\x96\x81\x97\x81\xe7\x81\xe8";
static const char lbl_10_rodata_1BCC[] = "Numbers";
static const char lbl_10_rodata_1BD4[] = "\x82O\x82P\x82Q\x82R\x82S\x82T\x82U\x82V\x82W\x82X\x81\xe7\x81\xe8";

/* Japanese pages. */
NameEntryAlphabet lbl_10_data_68E0[4] = {
    { 0, 0x40, lbl_10_rodata_1550, lbl_10_rodata_15D4, NULL, lbl_10_rodata_1548 },
    { 0, 0x26, lbl_10_rodata_1660, NULL, NULL, lbl_10_rodata_1658 },
    { 0, 0x55, lbl_10_rodata_16BC, lbl_10_rodata_1768, lbl_10_rodata_1814, lbl_10_rodata_16B0 },
    { 0, 0x58, lbl_10_rodata_18CC, lbl_10_rodata_1980, lbl_10_rodata_1A34, lbl_10_rodata_18C0 },
};
/* English pages. */
NameEntryAlphabet lbl_10_data_6930[4] = {
    { 0, 0x1C, lbl_10_rodata_1AF8, NULL, NULL, lbl_10_rodata_1AE8 },
    { 0, 0x1C, lbl_10_rodata_1B44, NULL, NULL, lbl_10_rodata_1B34 },
    { 0, 0x20, lbl_10_rodata_1B88, NULL, NULL, lbl_10_rodata_1B80 },
    { 0, 0x0C, lbl_10_rodata_1BD4, NULL, NULL, lbl_10_rodata_1BCC },
};

Obj_4_bss_5680_Target *lbl_10_bss_55CD8 = 0;
u8 lbl_10_bss_55CDC;
u8 lbl_10_bss_55CDD;

/* fzgx:begin fn_10_2325C */
extern void fn_1_495A0(f32);

#pragma pack(1)
struct NameEntryLetter {
u8 unk_0;
u8 unk_1;
char name[2];
u16 unk_4;
u16 unk_6;
u16 unk_8;
u16 unk_A;
u8 unk_C;
NameEntryRGBA color;
};
#pragma pack()
static inline s32 fn_4_ADF4_sign(s32 x) { return x < 0 ? -1 : x > 0; }
void fn_10_2325C(struct NameEntryLetter *arg0)
{
struct NameEntryLetter *p;
u8 name[4];
NameEntryRGBA ph;
FontDrawPacket loc_20;
f32 f;
f32 scale;
u32 t;
u32 n2;
s32 e;
p = arg0;
if (lbl_10_bss_55CDC != 0) {
fn_1_46B4(lbl_801A6410, (u32)p, "name_entry.c", 0xFB);
fn_1_4060();
return;
}
n2 = (p->unk_C + 1) & 0x1F;
t = lbl_10_bss_55CD8->unk_20;
if (__rlwnm(t, n2, 31, 31) != 0) {
if (p->unk_0 != 1 || p->unk_1 != 0x18) {
p->unk_0 = 4;
p->unk_1 = 0x10;
lbl_10_bss_55CD8->unk_20 &= ~(0x80000000U >> p->unk_C);
if (strncmp(p->name, "\x81@", 2) == 0) {
strncpy(p->name, "\x81\xe7", 2);
name[0] = p->name[0];
name[1] = p->name[1];
}
}
}
name[0] = p->name[0];
name[1] = p->name[1];
name[2] = 0;
fn_1_49410();
fn_1_494DC(0x2A);
fn_1_495C8(9);
switch (p->unk_0) {
case 1:
{
u16 c4 = p->unk_4;
s32 t4 = p->unk_8 - c4;
f64 dd = 0.21 * t4;
if ((s32)dd != 0) {
p->unk_4 = (c4 + dd);
} else {
e = fn_4_ADF4_sign(t4);
/* Retail rereads the position after selecting the one-step adjustment. */
p->unk_4 = *(u16 *)&p->unk_4 + e;
}
{
u16 c6 = p->unk_6;
s32 t6 = p->unk_A - c6;
dd = 0.21 * t6;
if ((s32)dd != 0) {
p->unk_6 = (c6 + dd);
} else {
e = fn_4_ADF4_sign(t6);
/* Retail rereads the position after selecting the one-step adjustment. */
p->unk_6 = *(u16 *)&p->unk_6 + e;
}
}
}
fn_1_49514(p->color);
fn_1_496FC(p->unk_4, p->unk_6);
{
f64 scale_d = 1.6666666666666667 * (0.5 + (0x18 - p->unk_1) / 48.0f);
fn_1_4955C(scale_d, scale_d);
}
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
ph = p->color;
{
f32 quarter = 0.25f;
f = p->unk_1 * quarter;
{
ph.r += (255 - ph.r) * f;
ph.g += (255 - ph.g) * f;
ph.b += (255 - ph.b) * f;
}
}
fn_1_49514(ph);
fn_1_496FC(p->unk_4, p->unk_6);
{
f64 scale_d = 1.6666666666666667 * (1.0 + 0.5 * f);
fn_1_4955C(scale_d, scale_d);
}
loc_20 = *(FontDrawPacket *)(&lbl_1_rodata_26F8);
loc_20.image = 0x8F09;
loc_20.x = p->unk_4;
loc_20.y = p->unk_6;
loc_20.z = 0.13f;
loc_20.scale_x = loc_20.scale_y = (1.5 + 2.0 * f);
loc_20.flags = 0xA;
fn_1_4F734((FontDrawPacket *)&loc_20);
if (p->unk_1 == 1) {
p->unk_0 = 3;
if (strncmp(p->name, "\x81\xe7", 2) == 0) {
strncpy(p->name, "\x81@", 2);
name[0] = p->name[0];
name[1] = p->name[1];
}
}
break;
case 3:
fn_1_49514(p->color);
fn_1_496FC(p->unk_4, p->unk_6);
fn_1_4955C(1.6666666f, 1.6666666f);
break;
case 4:
if (p->unk_1 == 0) {
fn_1_46B4(lbl_801A6410, (u32)p, "name_entry.c", 0x169);
fn_1_4060();
return;
}
fn_1_49514(p->color);
fn_1_496FC(p->unk_4, p->unk_6);
{
f64 scale_d = 1.6666666666666667 * (1.0 + 0.5 * (f32)(0x10 - p->unk_1));
fn_1_4955C(scale_d, scale_d);
}
{
f32 alpha = p->unk_1;
alpha *= 0.0625f;
fn_1_495A0(alpha);
}
break;
}
fn_1_4A0D8((const char *)name);
p->unk_1--;
}
/* fzgx:end fn_10_2325C */

/* fzgx:begin fn_10_23990 */
typedef signed char fn_10_23990_s8;
typedef signed short fn_10_23990_s16;
typedef signed long fn_10_23990_s32;

typedef unsigned char fn_10_23990_u8;
typedef unsigned short fn_10_23990_u16;
typedef unsigned long fn_10_23990_u32;

typedef float fn_10_23990_f32;
typedef double fn_10_23990_f64;

typedef unsigned long fn_10_23990_size_t;

/* lbl_4_bss_5680: .bss size 0x4, referenced by 8 functions, shape {'object': 112, 'pointer': 28} */
typedef struct {
fn_10_23990_u32 unk_0; /* 11 loads, 6 stores */
fn_10_23990_u32 unk_4; /* 1 loads, 1 stores */
fn_10_23990_u32 unk_8; /* 4 loads, 1 stores */
fn_10_23990_u8 unk_C; /* 8 loads, 1 stores */
fn_10_23990_u8 unk_D; /* 5 loads, 4 stores */
fn_10_23990_u8 unk_E; /* 10 loads, 3 stores */
fn_10_23990_u8 unk_F; /* 3 loads, 12 stores */
fn_10_23990_u8 unk_10; /* 1 loads, 0 stores */
fn_10_23990_u8 unk_11; /* 2 loads, 1 stores */
fn_10_23990_u16 unk_12; /* 3 loads, 3 stores */
fn_10_23990_u8 unk_14; /* 2 loads, 2 stores */
fn_10_23990_u8 unk_15; /* 2 loads, 2 stores */
fn_10_23990_u8 unk_16; /* 2 loads, 2 stores */
fn_10_23990_u8 unk_17; /* 2 loads, 2 stores */
fn_10_23990_u32 unk_18; /* 1 loads, 1 stores */
fn_10_23990_u32 unk_1C; /* 1 loads, 1 stores */
fn_10_23990_u32 unk_20; /* 3 loads, 2 stores */
fn_10_23990_u8 pad_24[0x4];
fn_10_23990_u8 unk_28; /* 1 loads, 0 stores */
fn_10_23990_u8 pad_29[0xD];
fn_10_23990_u8 unk_36; /* 2 loads, 1 stores */
fn_10_23990_u8 unk_37; /* 0 loads, 1 stores */
fn_10_23990_u8 pad_38[0x2];
fn_10_23990_u8 unk_3A; /* 2 loads, 2 stores */
fn_10_23990_u8 unk_3B; /* 5 loads, 2 stores */
fn_10_23990_u32 unk_3C; /* 4 loads, 2 stores */
} fn_10_23990_Obj_4_bss_5680_Target;



/* lbl_4_data_2F78: .data size 0xA0, referenced by 5 functions, shape {} */

/* lbl_4_bss_5684: .bss size 0x1, referenced by 3 functions, shape {'object': 3} */

struct fn_8_DD64_lbl_801A63D0 {
fn_10_23990_u32 unk_0;
};
struct fn_8_DD64_lbl_8_rodata_408 {
fn_10_23990_u8 pad_0[0x6F0];
fn_10_23990_f64 unk_6F0;
fn_10_23990_f64 unk_6F8;
fn_10_23990_f32 unk_700;
fn_10_23990_f32 unk_704;
fn_10_23990_f32 unk_708;
fn_10_23990_u32 unk_70C;
fn_10_23990_u32 unk_710;
fn_10_23990_u32 unk_714;
fn_10_23990_u32 unk_718;
fn_10_23990_u32 unk_71C;
fn_10_23990_u32 unk_720;
fn_10_23990_f32 unk_724;
fn_10_23990_f32 unk_728;
fn_10_23990_u8 pad_72C[0x4];
fn_10_23990_f64 unk_730;
fn_10_23990_f64 unk_738;
fn_10_23990_f32 unk_740;
fn_10_23990_u8 pad_744[0x4];
fn_10_23990_f64 unk_748;
fn_10_23990_f32 unk_750;
fn_10_23990_f32 unk_754;
};
extern char * fn_80083CF4(char *, const char *, fn_10_23990_size_t);
extern struct fn_8_DD64_lbl_801A63D0 lbl_801A63D0;


typedef NameEntryRGBA Sig_fn_800081C8_Color;
extern fn_10_23990_u32 fn_800081C8(Sig_fn_800081C8_Color, Sig_fn_800081C8_Color, fn_10_23990_f32);


extern fn_10_23990_u8 * fn_80083970(fn_10_23990_u8 *, const fn_10_23990_u8 *);






extern void fn_1_4954C(fn_10_23990_f32);
extern void fn_1_4966C(fn_10_23990_f32, fn_10_23990_f32);
static f32 name_entry_glyph_size(s32 index) {
    switch (index) {
    case 0:
        return 32.0f;
    case 1:
        return 24.0f;
    default:
        return 18.0f;
    }
}

/* Carried from main: this function matches only with the optimizer settings below. */
#pragma opt_common_subs off
#pragma opt_lifetimes off
#pragma opt_loop_invariants off
void fn_10_23990(fn_10_23990_u32 arg0) {
fn_10_23990_u8 *p_lbl_1_rodata_26F8;
fn_10_23990_u32 v0;
fn_10_23990_s32 v1;
fn_10_23990_s32 v2;
fn_10_23990_s32 state_value;
fn_10_23990_s32 cursor_next;
fn_10_23990_s32 v3;
fn_10_23990_u32 v4;
fn_10_23990_f32 v5;
fn_10_23990_f64 v6;
fn_10_23990_f32 v7;
struct OptionNameEntry { fn_10_23990_u16 cursor, length; char *chars; fn_10_23990_u8 pad[12]; } *v8;
fn_10_23990_u32 v9;
fn_10_23990_s32 v10;
fn_10_23990_u32 v12;
fn_10_23990_u32 v13;
fn_10_23990_u32 v14;
fn_10_23990_s32 v15;
fn_10_23990_f32 v16;
fn_10_23990_u16 v17;
fn_10_23990_f64 v18;
fn_10_23990_u32 v19;
fn_10_23990_u8 * v20;
fn_10_23990_u32 v21;
fn_10_23990_u32 v22;
fn_10_23990_f64 v23;
fn_10_23990_f32 v24;
fn_10_23990_f64 v25;
fn_10_23990_f32 v26;
fn_10_23990_f32 v27;
struct { fn_10_23990_u32 a[22]; } loc_18;
Sig_fn_800081C8_Color loc_14;
Sig_fn_800081C8_Color loc_10;
Sig_fn_800081C8_Color loc_C;
fn_10_23990_u32 lab_t0;
fn_10_23990_u32 lab_t1;
fn_800793D4((void *)lbl_801A63D0.unk_0, 0, 1024);
v0 = lbl_801A63D0.unk_0;
if ((*(fn_10_23990_u8 *)&lbl_10_bss_55CDC) != 0) {
v2 = (fn_10_23990_s32)(arg0);
v1 = (fn_10_23990_u32)&(*(fn_10_23990_u32 *)&lbl_801A6410);
v3 = (fn_10_23990_u32)"name_entry.c";
v1 = *(fn_10_23990_u32 *)((fn_10_23990_u8 *)v1);
v4 = 465;
fn_1_46B4(v1, v2, (const char *)v3, v4);
v1 = fn_1_4060();
} else {
v1 = fn_1_49410();
v1 = 42;
fn_1_494DC(v1);
v1 = 9;
fn_1_495C8(v1);
fn_1_4966C(12.0f, 0.0f);
v1 = (*(fn_10_23990_Obj_4_bss_5680_Target * *)&lbl_10_bss_55CD8)->unk_3C;
v8 = (struct OptionNameEntry *)v1 + *(fn_10_23990_u8 *)arg0;
v19 = v8->cursor;
v3 = (v19 - 10);
v1 = (v19 + 11);
if (v3 >= 0 && (fn_10_23990_s32)(v19 + 11) <= (fn_10_23990_s32)v8->length) {
v2 = (fn_10_23990_s32)((fn_10_23990_u32)v8->chars);
v1 = v0;
v9 = (v3 << 1);
v3 = 42;
{ fn_10_23990_s32 __reg_value_v2 = (v2 + v9); v2 = __reg_value_v2; }
v1 = (fn_10_23990_u32)strncpy((char *)v1, (const char *)v2, v3);
} else if (v19 < 10) {
v10 = v19 - 10;
v10 = v8->length + v10;
if (v10 < 0) {
v2 = (fn_10_23990_s32)((fn_10_23990_u32)v8->chars);
v1 = v0;
{ fn_10_23990_s32 __reg_value_v2 = (v2 + (v19 << 1)); v2 = __reg_value_v2; }
lab_t0 = v1;
lab_t1 = v2;
v1 = (fn_10_23990_u32)fn_80083DB0((char *)lab_t0, (const char *)lab_t1);
{ fn_10_23990_s32 __reg_value_v2 = (fn_10_23990_u32)v8->chars; v2 = __reg_value_v2; }
v1 = v0;
v1 = (fn_10_23990_u32)strcat((char *)v1, (const char *)v2);
{ fn_10_23990_s32 __reg_value_v2 = (fn_10_23990_u32)v8->chars; v2 = __reg_value_v2; }
v1 = v0;
v3 = ((v10 + 10) << 1);
v1 = (fn_10_23990_u32)fn_80083CF4((char *)v1, (const char *)v2, v3);
} else {
v2 = (fn_10_23990_s32)((fn_10_23990_u32)v8->chars);
v1 = v0;
{ fn_10_23990_s32 __reg_value_v2 = (v2 + (v10 << 1)); v2 = __reg_value_v2; }
lab_t0 = v1;
lab_t1 = v2;
v1 = (fn_10_23990_u32)fn_80083DB0((char *)lab_t0, (const char *)lab_t1);
v1 = v8->cursor;
v10 = (v1 + 11);
if ((fn_10_23990_s32)v10 > (fn_10_23990_s32)v8->length) {
v2 = (fn_10_23990_s32)((fn_10_23990_u32)v8->chars);
v1 = v0;
v1 = (fn_10_23990_u32)strcat((char *)v1, (const char *)v2);
v1 = v0;
{ fn_10_23990_s32 __reg_value_v2 = (fn_10_23990_u32)v8->chars; v2 = __reg_value_v2; }
v3 = ((v10 - v8->length) << 1);
v1 = (fn_10_23990_u32)fn_80083CF4((char *)v1, (const char *)v2, v3);
} else {
v2 = (fn_10_23990_s32)((fn_10_23990_u32)v8->chars);
v1 = v0;
v3 = (v10 << 1);
v1 = (fn_10_23990_u32)fn_80083CF4((char *)v1, (const char *)v2, v3);
}
}
} else {
v2 = (fn_10_23990_s32)((fn_10_23990_u32)v8->chars);
v1 = v0;
{ fn_10_23990_s32 __reg_value_v2 = (v2 + (v3 << 1)); v2 = __reg_value_v2; }
lab_t0 = v1;
lab_t1 = v2;
v1 = (fn_10_23990_u32)fn_80083DB0((char *)lab_t0, (const char *)lab_t1);
{ fn_10_23990_s32 __reg_value_v2 = v8->cursor; v2 = __reg_value_v2; }
v1 = v0;
v3 = v8->length;
v12 = (v2 + 11);
{ fn_10_23990_s32 __reg_value_v2 = (fn_10_23990_u32)v8->chars; v2 = __reg_value_v2; }
v3 = ((v12 - v3) << 1);
v1 = (fn_10_23990_u32)fn_80083CF4((char *)v1, (const char *)v2, v3);
}
v2 = (fn_10_23990_s32)(*(fn_10_23990_u8 *)((fn_10_23990_u8 *)arg0));
v1 = (fn_10_23990_u32)(*(fn_10_23990_Obj_4_bss_5680_Target * *)&lbl_10_bss_55CD8);
if ((fn_10_23990_u32)v2 == *(fn_10_23990_u8 *)((fn_10_23990_u8 *)v1 + 13)) {
fn_10_23990_u32 b14;
v2 = (fn_10_23990_s32)((v0 + 6));
v1 = (fn_10_23990_u32)&lbl_801A63D0;
v3 = 14;
v1 = *(fn_10_23990_u32 *)((fn_10_23990_u8 *)v1);
v10 = (v1 + 44);
b14 = (v1 + 88);
v1 = v10;
v1 = (fn_10_23990_u32)strncpy((char *)v1, (const char *)v2, v3);
v1 = b14;
{ fn_10_23990_s32 __reg_value_v2 = (v0 + 22); v2 = __reg_value_v2; }
v3 = 14;
v1 = (fn_10_23990_u32)strncpy((char *)v1, (const char *)v2, v3);
v1 = v0;
v3 = v10;
v4 = b14;
{ fn_10_23990_s32 __reg_value_v2 = (fn_10_23990_u32)"%s\x81@\x81@\x81@%s"; v2 = __reg_value_v2; }
v1 = sprintf((char *)v1, (const char *)(fn_10_23990_u32)v2, v3, v4);
}
v1 = (fn_10_23990_u32)(*(fn_10_23990_Obj_4_bss_5680_Target * *)&lbl_10_bss_55CD8);
v1 = *(fn_10_23990_u8 *)((fn_10_23990_u8 *)v1 + 13);
v1 = (*(fn_10_23990_u8 *)((fn_10_23990_u8 *)arg0) - v1);
if (v1 < 0) {
v1 += 4;
}
switch (v1) {
case 0:
v15 = 178;
v16 = name_entry_glyph_size(0);
{ Sig_fn_800081C8_Color color0 = {255, 255, 255, 0}; loc_14 = color0; }
break;
case 1:
v15 = 276;
v16 = name_entry_glyph_size(1);
{ Sig_fn_800081C8_Color color1 = {0, 255, 255, 0}; loc_14 = color1; }
break;
case 2:
v15 = 313;
v16 = name_entry_glyph_size(2);
{ Sig_fn_800081C8_Color color2 = {0, 255, 255, 0}; loc_14 = color2; }
break;
case 3:
v15 = 84;
v16 = name_entry_glyph_size(1);
{ Sig_fn_800081C8_Color color3 = {0, 255, 255, 0}; loc_14 = color3; }
}
state_value = *(fn_10_23990_u16 *)((fn_10_23990_u8 *)arg0 + 4);
v3 = v15 - state_value;
v6 = 0.2 * (fn_10_23990_f64)v3;
if ((fn_10_23990_s32)v6 != 0) {
*(fn_10_23990_u16 *)((fn_10_23990_u8 *)arg0 + 4) = (fn_10_23990_s32)((fn_10_23990_f64)(fn_10_23990_u32)state_value + v6);
} else {
if (v3 < 0) {
v1 = -1;
} else {
v1 = v3 > 0;
}
*(fn_10_23990_u16 *)((fn_10_23990_u8 *)arg0 + 4) += v1;
}
v7 = *(fn_10_23990_f32 *)((fn_10_23990_u8 *)arg0 + 8);
v6 = 0.2;
*(fn_10_23990_f32 *)((fn_10_23990_u8 *)arg0 + 8) = v7 + v6 * (v16 - v7);
v1 = *(fn_10_23990_u8 *)((fn_10_23990_u8 *)arg0 + 2);
v13 = v8->cursor;
state_value = v1 + 1;
if (state_value == (fn_10_23990_s32)v13 || --v1 > (fn_10_23990_s32)v13) {
*(fn_10_23990_u8 *)((fn_10_23990_u8 *)arg0 + 1) = 36;
} else if (v1 == (fn_10_23990_s32)v13 || state_value < (fn_10_23990_s32)v13) {
*(fn_10_23990_s8 *)((fn_10_23990_u8 *)arg0 + 1) = -36;
}
v2 = (fn_10_23990_s8)*(fn_10_23990_u8 *)((fn_10_23990_u8 *)arg0 + 1);
v3 = -v2;
v6 = 0.2 * (fn_10_23990_f64)v3;
if ((fn_10_23990_s32)v6 != 0) {
*(fn_10_23990_u8 *)((fn_10_23990_u8 *)arg0 + 1) = (fn_10_23990_s32)((fn_10_23990_f64)v2 + v6);
} else {
if (v3 < 0) {
v1 = -1;
} else {
v1 = v3 > 0;
}
*(fn_10_23990_u8 *)((fn_10_23990_u8 *)arg0 + 1) += v1;
}
v1 = v0;
v2 = (fn_10_23990_u32)"\x81\xe8";
*(fn_10_23990_u8 *)((fn_10_23990_u8 *)arg0 + 2) = v8->cursor;
v1 = (fn_10_23990_u32)fn_80083970((fn_10_23990_u8 *)v1, (const fn_10_23990_u8 *)v2);
p_lbl_1_rodata_26F8 = (*(fn_10_23990_u8 (*)[])&lbl_1_rodata_26F8);
v15 = 0x10000 - 28914;
v20 = (fn_10_23990_u8 *)v1;
v24 = 10.1f;
v25 = 24.0;
while (v20 != 0) {
v1 = strlen((const char *)v0);
state_value = v20 - (fn_10_23990_u8 *)v0;
v3 = v1 - 1;
v1 = (fn_10_23990_u32)state_value >> 31;
v1 = v1 + state_value;
state_value = (fn_10_23990_u32)v3 >> 2;
v1 >>= 1;
v3 = (fn_10_23990_u32)&loc_14;
v2 = v1 - state_value;
state_value = (fn_10_23990_u32)p_lbl_1_rodata_26F8 - 4;
for (v21 = 11; v21 != 0; v21--) {
v1 = *(fn_10_23990_u32 *)((fn_10_23990_u8 *)state_value + 4);
v22 = *(fn_10_23990_u32 *)((fn_10_23990_u8 *)state_value + 8);
state_value += 8;
*(fn_10_23990_u32 *)((fn_10_23990_u8 *)v3 + 4) = v1;
*(fn_10_23990_u32 *)((fn_10_23990_u8 *)v3 + 8) = v22;
v3 += 8;
}
loc_18.a[0] = v15;
v3 = *(fn_10_23990_u8 *)((fn_10_23990_u8 *)arg0 + 1);
v1 = (fn_10_23990_s8)v3;
v26 = (fn_10_23990_f32)(fn_10_23990_s32)v2 * *(fn_10_23990_f32 *)((fn_10_23990_u8 *)arg0 + 8);
v5 = (fn_10_23990_f32)(v1 + 320);
*(fn_10_23990_f32 *)((fn_10_23990_u8 *)&loc_18 + 4) = v5 + v26;
if (__abs((fn_10_23990_s32)v2) > 0) {
v3 = 1;
if ((fn_10_23990_s32)v2 < 0) v3 = -1;
state_value = (fn_10_23990_s32)v2 >> 31;
v1 = state_value ^ (fn_10_23990_s32)v2;
v1 -= state_value;
v6 = 12.0;
v7 = *(fn_10_23990_f32 *)((fn_10_23990_u8 *)&loc_18 + 4);
*(fn_10_23990_f32 *)((fn_10_23990_u8 *)&loc_18 + 4) = v7 + v6 * (v3 * v1);
}
*(fn_10_23990_f32 *)((fn_10_23990_u8 *)&loc_18 + 8) = (fn_10_23990_f32)(fn_10_23990_u32)*(fn_10_23990_u16 *)((fn_10_23990_u8 *)arg0 + 4);
*(fn_10_23990_f32 *)((fn_10_23990_u8 *)&loc_18 + 12) = v24;
loc_18.a[12] = 10;
v5 = 1.0f;
v27 = *(fn_10_23990_f32 *)((fn_10_23990_u8 *)arg0 + 8) / v25;
*(fn_10_23990_f32 *)((fn_10_23990_u8 *)&loc_18 + 20) = v27;
*(fn_10_23990_f32 *)((fn_10_23990_u8 *)&loc_18 + 16) = v27;
{
Sig_fn_800081C8_Color black = {0, 0, 0, 255};
Sig_fn_800081C8_Color white = {255, 255, 255, 255};
loc_10 = black;
loc_C = white;
v1 = fn_800081C8(loc_10, loc_C, v5);
}
loc_18.a[14] = v1;
fn_1_4F734((FontDrawPacket *)&loc_18);
v20 = fn_80083970(v20 + 2, (const fn_10_23990_u8 *)"\x81\xe8");
}
v2 = (fn_10_23990_s8)*(fn_10_23990_u8 *)((fn_10_23990_u8 *)arg0 + 1);
v2 += 320;
v5 = (fn_10_23990_f32)v2;
v6 = (fn_10_23990_f32)(fn_10_23990_u32)*(fn_10_23990_u16 *)((fn_10_23990_u8 *)arg0 + 4);
fn_1_496FC(v5, v6);
v18 = *(fn_10_23990_f32 *)((fn_10_23990_u8 *)arg0 + 8) / 24.0;
fn_1_4955C(v18, v18);
fn_1_49514(loc_14);
fn_1_4954C(10.0f);
fn_1_4A0D8((const char *)v0);
}
}
#pragma opt_loop_invariants reset
#pragma opt_lifetimes reset
#pragma opt_common_subs reset
/* fzgx:end fn_10_23990 */

/* fzgx:begin fn_10_2406C */
typedef struct { u8 r, g, b, a; } MenuColor;
typedef struct {
u16 cur;
u16 max;
u8 *p4;
u8 *p8;
u8 *pC;
u32 pad;
} MenuEntry;
/* Carried from main: this function matches only with the optimizer settings below. */
#pragma opt_common_subs off
void fn_10_2406C(void) {
void *rp;
u8 *q;
u32 cnt;
s32 flA;
s32 flB;
s32 flC;
u8 buf[2];
s32 i;
u16 *repeat;
u16 *held;
Obj_10_bss_55CD8_Target *state;
u8 *t8;
MenuEntry *e;
s32 inputIndex;
Obj_10_bss_55CD8_Target *active;
Obj_10_bss_55CD8_Target **inputRef;
s32 prev;
u8 *alternate;
flA = 0;
flB = 0;
flC = 0;
if (lbl_10_bss_55CD8->unk_0 >> 31) {
if (lbl_10_bss_55CDD == 0) {
goto end; /* matches retail's single early-exit block */
}
}
state = lbl_10_bss_55CD8;
e = (MenuEntry *)state->unk_3C + state->unk_D;
t8 = lbl_1_bss_9F8 + 8;
if ((((u16 *)t8)[state->unk_C * 10] >> 12) & 1) {
if (e->cur == e->max - 1) {
lbl_10_bss_55CD8->unk_0 |= 0x20000000;
fn_1_A2D84(0xA9010F00);
} else {
MenuEntry *z;
lbl_10_bss_55CD8->unk_F = 0;
z = (MenuEntry *)lbl_10_bss_55CD8->unk_3C;
for (i = 0; i < lbl_10_bss_55CD8->unk_3B; i++) {
z->cur = z->max - 1;
z++;
}
fn_1_A2D84(0xA9010F00);
}
} else if (((((u16 *)t8)[state->unk_C * 10] >> 8) & 1) && lbl_10_bss_55CDD == 0) {
s32 cur = e->cur;
if (cur == e->max - 1) {
lbl_10_bss_55CD8->unk_0 |= 0x20000000;
fn_1_A2D84(0xA9010F00);
} else {
cnt = (u8)(state->unk_E);
flA = 1;
if (cnt == 7 && state->unk_36 != 0) {
flB = 1;
}
{
switch (state->unk_F) {
case 0: q = e->p4 + cur * 2; break;
case 1: q = e->p8 + cur * 2; break;
case 2: q = e->pC + cur * 2; break;
}
}
strncpy((char *)buf, (char *)q, 2);
if (strncmp((char *)q, "\x81\xe7", 2) == 0) {
strncpy((char *)((u8 *)lbl_10_bss_55CD8 + lbl_10_bss_55CD8->unk_E * 2 + 0x28), "\x81@", 2);
} else {
strncpy((char *)((u8 *)lbl_10_bss_55CD8 + lbl_10_bss_55CD8->unk_E * 2 + 0x28), (char *)q, 2);
}
{
Obj_10_bss_55CD8_Target **advanceRef = &lbl_10_bss_55CD8;
Obj_10_bss_55CD8_Target *advance = *advanceRef;
if (advance->unk_E < 7) {
advance->unk_E = advance->unk_E + 1;
} else {
MenuEntry *z;
s32 j;
z = (MenuEntry *)advance->unk_3C;
for (j = 0; j < (*advanceRef)->unk_3B; j++) {
z->cur = z->max - 1;
z++;
}
}
}
lbl_10_bss_55CD8->unk_F = 0;
}
} else if (((((u16 *)t8) [lbl_10_bss_55CD8->unk_C * 10] >> 9) & 1) && lbl_10_bss_55CDD == 0) {
u32 pos;
state = lbl_10_bss_55CD8;
pos = state->unk_E;
flB = pos != 0;
if (pos == 7 && state->unk_36 != 0) {
lbl_10_bss_55CD8->unk_36 = 0;
lbl_10_bss_55CD8->unk_37 = 0;
} else {
if (pos != 0) {
state->unk_E = state->unk_E - 1;
}
for (i = lbl_10_bss_55CD8->unk_E; i <= 7; i++) {
if (i < 7) {
u8 *shift = (u8 *)lbl_10_bss_55CD8 + i * 2;
shift[0x28] = shift[0x2a];
shift = (u8 *)lbl_10_bss_55CD8 + i * 2;
shift[0x29] = shift[0x2b];
} else {
*((u8 *)lbl_10_bss_55CD8 + i * 2 + 0x28) = 0;
*((u8 *)lbl_10_bss_55CD8 + i * 2 + 0x29) = 0;
}
}
}
lbl_10_bss_55CD8->unk_F = 0;
cnt = lbl_10_bss_55CD8->unk_E;
} else {
held = (u16 *)(lbl_1_bss_9F8 + 0x10);
if (((held[lbl_10_bss_55CD8->unk_C * 10] >> 3) & 1) || (((repeat = (u16 *)(lbl_1_bss_9F8 + 0x12), repeat[lbl_10_bss_55CD8->unk_C * 10]) >> 3) & 1)) {
if (lbl_10_bss_55CD8->unk_D == 0) {
lbl_10_bss_55CD8->unk_D = lbl_10_bss_55CD8->unk_3B - 1;
} else {
lbl_10_bss_55CD8->unk_D = lbl_10_bss_55CD8->unk_D - 1;
}
lbl_10_bss_55CD8->unk_F = 0;
} else if (((held[lbl_10_bss_55CD8->unk_C * 10] >> 2) & 1) || ((repeat[lbl_10_bss_55CD8->unk_C * 10] >> 2) & 1)) {
if (lbl_10_bss_55CD8->unk_D == lbl_10_bss_55CD8->unk_3B - 1) {
lbl_10_bss_55CD8->unk_D = 0;
} else {
lbl_10_bss_55CD8->unk_D = lbl_10_bss_55CD8->unk_D + 1;
}
lbl_10_bss_55CD8->unk_F = 0;
} else if ((held[lbl_10_bss_55CD8->unk_C * 10] & 1) || (repeat[lbl_10_bss_55CD8->unk_C * 10] & 1) || ((repeat[lbl_10_bss_55CD8->unk_C * 10] >> 8) & 1)) {
if (e->cur == 0) {
e->cur = e->max - 1;
} else {
e->cur = e->cur - 1;
}
lbl_10_bss_55CD8->unk_F = 0;
} else if (((held[lbl_10_bss_55CD8->unk_C * 10] >> 1) & 1) || ((repeat[lbl_10_bss_55CD8->unk_C * 10] >> 1) & 1) || ((repeat[lbl_10_bss_55CD8->unk_C * 10] >> 9) & 1)) {
if (e->cur == e->max - 1) {
e->cur = 0;
} else {
e->cur = e->cur + 1;
}
lbl_10_bss_55CD8->unk_F = 0;
} else if ((((u16 *)t8)[lbl_10_bss_55CD8->unk_C * 10] >> 11) & 1) {
flC = 1;
lbl_10_bss_55CD8->unk_F = lbl_10_bss_55CD8->unk_F + 1;
if (lbl_10_bss_55CD8->unk_F > 2) {
lbl_10_bss_55CD8->unk_F = 0;
} else if (lbl_10_bss_55CD8->unk_F == 1) {
alternate = e->p8;
if (alternate == 0) {
flC = 0;
lbl_10_bss_55CD8->unk_F = 0;
} else if (strncmp((char *)(alternate + e->cur * 2), "\x81@", 2) == 0) {
flC = 0;
lbl_10_bss_55CD8->unk_F = 0;
}
} else if (lbl_10_bss_55CD8->unk_F == 2) {
alternate = e->pC;
if (alternate == 0) {
lbl_10_bss_55CD8->unk_F = 0;
} else if (strncmp((char *)(alternate + e->cur * 2), "\x81@", 2) == 0) {
lbl_10_bss_55CD8->unk_F = 0;
}
}
}
}
{
Obj_10_bss_55CD8_Target **ref = &lbl_10_bss_55CD8;
/* Observe the shared state pointer independently before this update stage. */
Obj_10_bss_55CD8_Target *before = *(Obj_10_bss_55CD8_Target **)ref;
Obj_10_bss_55CD8_Target *after;
s32 prev;
prev = *(s8 *)&before->unk_10;
before->unk_10 = ((s8 *)lbl_1_bss_A48)[before->unk_C << 4] >> 2;
after = *ref;
if (*(s8 *)&after->unk_10 == 0) {
u8 t = lbl_1_bss_A48[after->unk_C << 4];
if ((s8)t > 0) {
after->unk_10 = 1;
} else if ((s8)t < 0) {
*(s8 *)&after->unk_10 = -1;
} else {
*(s8 *)&after->unk_10 = prev < 0 ? -1 : 1;
}
}
}
{
Obj_10_bss_55CD8_Target **smoothRef = &lbl_10_bss_55CD8;
/* Observe the shared state pointer again for the animation update. */
Obj_10_bss_55CD8_Target *phase = *(Obj_10_bss_55CD8_Target **)smoothRef;
u32 old12;
s32 x;
f64 d;
Obj_10_bss_55CD8_Target *smooth;
phase->unk_11 = phase->unk_11 - phase->unk_10;
smooth = *smoothRef;
old12 = smooth->unk_12;
x = smooth->unk_E * 56 + 98 - old12;
d = 0.3 * x;
if ((s32)d != 0) {
smooth->unk_12 = (old12 + d);
} else {
s32 step;
if (x < 0) {
step = -1;
} else {
step = x > 0;
}
smooth->unk_12 += step;
}
}
if (lbl_10_bss_55CD8->unk_14 != 0) {
lbl_10_bss_55CD8->unk_14 = lbl_10_bss_55CD8->unk_14 - 1;
}
if (lbl_10_bss_55CD8->unk_15 != 0) {
lbl_10_bss_55CD8->unk_15 = lbl_10_bss_55CD8->unk_15 - 1;
}
if (lbl_10_bss_55CD8->unk_16 != 0) {
lbl_10_bss_55CD8->unk_16 = lbl_10_bss_55CD8->unk_16 - 1;
}
if (lbl_10_bss_55CD8->unk_17 != 0) {
lbl_10_bss_55CD8->unk_17 = lbl_10_bss_55CD8->unk_17 - 1;
}
q = lbl_1_bss_9F8 + 0x10;
if (((*(u16 *)(q + lbl_10_bss_55CD8->unk_C * 20) >> 3) & 1) || ((*(u16 *)((lbl_1_bss_9F8 + 0x12) + lbl_10_bss_55CD8->unk_C * 20) >> 3) & 1)) {
lbl_10_bss_55CD8->unk_14 = 8;
}
if (((*(u16 *)(q + lbl_10_bss_55CD8->unk_C * 20) >> 2) & 1) || ((*(u16 *)((lbl_1_bss_9F8 + 0x12) + lbl_10_bss_55CD8->unk_C * 20) >> 2) & 1)) {
lbl_10_bss_55CD8->unk_15 = 8;
}
if ((*(u16 *)(q + lbl_10_bss_55CD8->unk_C * 20) & 1) || ((repeat = (u16 *)(lbl_1_bss_9F8 + 0x12), repeat[lbl_10_bss_55CD8->unk_C * 10]) & 1) ||
((repeat[lbl_10_bss_55CD8->unk_C * 10] >> 8) & 1)) {
lbl_10_bss_55CD8->unk_16 = 8;
}
if (((*(u16 *)(q + lbl_10_bss_55CD8->unk_C * 20) >> 1) & 1) || (((repeat = (u16 *)(lbl_1_bss_9F8 + 0x12), repeat[lbl_10_bss_55CD8->unk_C * 10]) >> 1) & 1) ||
((repeat[lbl_10_bss_55CD8->unk_C * 10] >> 9) & 1)) {
lbl_10_bss_55CD8->unk_17 = 8;
}
if (flA != 0) {
MenuColor v68 = {0x00, 0xFF, 0xFF, 0x00};
rp = fn_1_45D0(lbl_801A6410, 0x12, "name_entry.c", 0xd4);
*(u16 *)((u8 *)rp + 8) = (u16)((u32)(cnt & 0xFF) * 56 + 0x7e);
*(u16 *)((u8 *)rp + 10) = 0x17a;
*(u8 *)((u8 *)rp + 0) = 1;
*(u8 *)((u8 *)rp + 1) = 0x18;
*(u16 *)((u8 *)rp + 4) = 0x140;
*(u16 *)((u8 *)rp + 6) = 0xb2;
*(u8 *)((u8 *)rp + 2) = buf[0];
*(u8 *)((u8 *)rp + 3) = buf[1];
*(MenuColor *)((u8 *)rp + 0xd) = v68;
*(u8 *)((u8 *)rp + 0xc) = cnt;
fn_1_435C(lbl_10_bss_55CD8->unk_8);
fn_1_3F8C((u32)"name_entry_fixed_letter", (u32)fn_10_2325C, (u32)rp, 0xb);
}
if (flB != 0) {
lbl_10_bss_55CD8->unk_20 |= ((u32)0x80000000 >> cnt);
}
if (flA != 0) {
lbl_10_bss_55CD8->unk_3A = 12;
}
if (flA != 0) {
fn_1_A2D84(0xA9010F00);
}
if (flB != 0) {
fn_1_A2D84(0xA9010200);
}
if (flC != 0) {
fn_1_A2D84(0xA9010000);
}
if (((*(u16 *)(q + lbl_10_bss_55CD8->unk_C * 20) >> 3) & 1) || (((repeat = (u16 *)(lbl_1_bss_9F8 + 0x12), repeat[lbl_10_bss_55CD8->unk_C * 10]) >> 3) & 1) ||
((*(u16 *)(q + lbl_10_bss_55CD8->unk_C * 20) >> 2) & 1) || ((repeat[lbl_10_bss_55CD8->unk_C * 10] >> 2) & 1)) {
fn_1_A2D84(0xA9010000);
}
if ((*(u16 *)(q + lbl_10_bss_55CD8->unk_C * 20) & 1) || ((repeat = (u16 *)(lbl_1_bss_9F8 + 0x12), repeat[lbl_10_bss_55CD8->unk_C * 10]) & 1) || ((repeat[lbl_10_bss_55CD8->unk_C * 10] >> 8) & 1) ||
((*(u16 *)(q + lbl_10_bss_55CD8->unk_C * 20) >> 1) & 1) || ((repeat[lbl_10_bss_55CD8->unk_C * 10] >> 1) & 1) || ((repeat[lbl_10_bss_55CD8->unk_C * 10] >> 9) & 1)) {
fn_1_A2D84(0xA9010000);
}

if (lbl_10_bss_55CDD != 0) {
fn_1_A2D84(0xA9010200);
lbl_10_bss_55CD8->unk_0 &= ~0x80000000u;
}
lbl_10_bss_55CDD = 0;
end:
return;
}
#pragma opt_common_subs reset
/* fzgx:end fn_10_2406C */

/* fzgx:begin fn_10_24BD0 */
typedef struct {
    u32 flags;  /* 11 loads, 6 stores */
    u32 unk_4;  /* 1 loads, 1 stores */
    u32 unk_8;  /* 4 loads, 1 stores */
    u8 unk_C;   /* 8 loads, 1 stores */
    u8 alphabet_index;   /* 5 loads, 4 stores */
    u8 name_length;   /* 10 loads, 3 stores */
    u8 letter_case;   /* 3 loads, 12 stores */
    u8 unk_10;  /* 1 loads, 0 stores */
    u8 rotation;  /* 2 loads, 1 stores */
    u16 selection_x; /* 3 loads, 3 stores */
    u8 tab_pulse;  /* 2 loads, 2 stores */
    u8 up_pulse;  /* 2 loads, 2 stores */
    u8 left_pulse;  /* 2 loads, 2 stores */
    u8 right_pulse;  /* 2 loads, 2 stores */
    u32 unk_18; /* 1 loads, 1 stores */
    u32 unk_1C; /* 1 loads, 1 stores */
    u32 unk_20; /* 3 loads, 2 stores */
    u8 pad_24[0x4];
    u8 unk_28; /* 1 loads, 0 stores */
    u8 pad_29[0xD];
    u8 name_complete; /* 2 loads, 1 stores */
    u8 unk_37; /* 0 loads, 1 stores */
    u8 pad_38[0x2];
    u8 pulse_ticks;  /* 2 loads, 2 stores */
    u8 unk_3B;  /* 5 loads, 2 stores */
    NameEntryAlphabet *alphabets; /* 4 loads, 2 stores */
} NameEntryState;

/* Packet templates are copied in full, including the callback and texture fields. */
struct NameEntryPacketWords {
    u32 words[22];
};
/* Colors use a packed word at the font boundary and signed byte channels internally. */
struct NameEntryColor {
    s8 channels[4];
};










extern u32 fn_1_134AD4(void);
extern void fn_1_133DBC(void *);
extern void fn_1_1380F0(void *);
extern u32 fn_1_13ABA8(u32);
extern f32 lbl_8006D188(s16);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);

static inline f32 name_entry_pulse_scale(u8 c) {
    if (c > 9) {
        return (0.5 + (f32)(c - 10) / 6.0);
    }
    return (0.5 + (f32)(10 - c) / 20.0);
}
void fn_10_24BD0(void) {

    FontDrawPacket packet;
    u8 buf[3];
    f32 pulse_scale;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 cursor_scale;
    u32 char_index;
    u32 empty_index;
    u32 text_index;
    u32 cursor_x;
    u8 *text;
    NameEntryAlphabet *alphabet;
    fn_1_49410();
    {
        u8 c = (*(NameEntryState * *)&lbl_10_bss_55CD8)->pulse_ticks;
        alphabet = &(*(NameEntryState * *)&lbl_10_bss_55CD8)->alphabets[(*(NameEntryState * *)&lbl_10_bss_55CD8)->alphabet_index];
        if (c != 0) {
            pulse_scale = name_entry_pulse_scale(c);
            (*(NameEntryState * *)&lbl_10_bss_55CD8)->pulse_ticks--;
        } else {
            pulse_scale = 1.0f;
        }
        fn_1_134AD4();
        if (lbl_1_bss_960 != 3) {
            packet = *(FontDrawPacket *)(*(u8 (*)[])&lbl_1_rodata_26F8);
            packet.image = 0x8F0C;
            packet.x = (167.0f);
            packet.y = (38.0f);
            packet.z = (0.5f);
            packet.flags = 0xA;
            fn_1_4F734((FontDrawPacket *)&packet);
        }
        if ((((*(NameEntryState * *)&lbl_10_bss_55CD8)->flags) >> 0x1FU) == 0) {
            if (lbl_801A66B4 == 5) {
                fn_1_1380F0("\x96\xbc\x91O\x82\xf0\x93\xfc\x82\xea\x82\xc4\x82\xad\x82\xbe\x82\xb3\x82\xa2\x81\x42");
            } else {
                fn_1_1380F0("Please enter your name.  ");
            }
        } else {
            fn_1_1380F0((*(void * (*)[])&lbl_1_data_418D4)[lbl_801A66B4]);
        }
        fn_1_13ABA8(0x18000000U);
        packet = *(FontDrawPacket *)(*(u8 (*)[])&lbl_1_rodata_26F8);
        packet.image = 0x8F0A;
        packet.x = (0.0f);
        packet.y = (68.0f);
        packet.z = (10.1999998f);
        fn_1_4F734((FontDrawPacket *)&packet);
        packet.x = (320.0f);
        packet.flags |= 0x80000;
        fn_1_4F734((FontDrawPacket *)&packet);
        packet = *(FontDrawPacket *)(*(u8 (*)[])&lbl_1_rodata_26F8);
        packet.image = 0x8F08;
        packet.x = (140.0f);
        packet.y = (98.0f);
        packet.z = (0.189999998f);
        fn_1_4F734((FontDrawPacket *)&packet);
        packet.x = (320.0f);
        packet.flags |= 0x80000;
        fn_1_4F734((FontDrawPacket *)&packet);
        packet = *(FontDrawPacket *)(*(u8 (*)[])&lbl_1_rodata_26F8);
        packet.image = 0x8F05;
        packet.x = (320.0f);
        packet.y = (178.0f);
        packet.z = (0.180000007f);
        packet.flags = 0xA;
        fn_1_4F734((FontDrawPacket *)&packet);
        packet = *(FontDrawPacket *)(*(u8 (*)[])&lbl_1_rodata_26F8);
        packet.image = 0x8F06;
        packet.x = (320.0f);
        packet.y = (178.0f);
        packet.z = (0.170000002f);
        packet.flags = 0xA;
        fn_1_4F734((FontDrawPacket *)&packet);
        packet = *(FontDrawPacket *)(*(u8 (*)[])&lbl_1_rodata_26F8);
        packet.image = 0x8F0B;
        empty_index = 0;
        char_index = 0x62;
        packet.y = (352.0f);
        packet.z = (0.159999996f);
        do {
            packet.x = char_index;
            fn_1_4F734((FontDrawPacket *)&packet);
            empty_index += 1;
            char_index += 0x38;
        } while (empty_index < 8);
        packet = *(FontDrawPacket *)(*(u8 (*)[])&lbl_1_rodata_26F8);
        packet.image = 0x8F07;
        packet.x = (320.0f);
        packet.y = (178.0f);
        packet.z = (0.150000006f);
        packet.flags = 0xA;
        packet.rotation_z = (((*(NameEntryState * *)&lbl_10_bss_55CD8)->rotation << 8) & 0xFF00);
        if ((1.0) != pulse_scale) {
            packet.scale_y = pulse_scale;
            packet.scale_x = pulse_scale;
        }
        fn_1_4F734((FontDrawPacket *)&packet);
        packet = *(FontDrawPacket *)(*(u8 (*)[])&lbl_1_rodata_26F8);
        packet.x = (320.0f);
        packet.z = (0.140000001f);
        packet.flags = 0xA;
        packet.image = 0x8F0D;
        packet.y = (110.0f);
        {
            u32 v = (*(NameEntryState * *)&lbl_10_bss_55CD8)->tab_pulse;
            struct NameEntryColor tab_color = {0, 0, 0, 0};
                        tab_color.channels[0] = ((v * 0x10) & 0xF0);
            tab_color.channels[1] = ((v * 0x10) & 0xF0);
            tab_color.channels[2] = ((v * 0x10) & 0xF0);
            *(u32 *)packet.color_add = *(u32 *)&tab_color;
            temp_f0 = ((1.0) + v / (12.0));
            packet.scale_y = temp_f0;
            packet.scale_x = temp_f0;
        }
        fn_1_4F734((FontDrawPacket *)&packet);
        packet.y = (250.0f);
        packet.image = 0x8F02;
        {
            u32 v = (*(NameEntryState * *)&lbl_10_bss_55CD8)->up_pulse;
            struct NameEntryColor left_color = {0, 0, 0, 0};
                        left_color.channels[0] = ((v * 0x10) & 0xF0);
            left_color.channels[1] = ((v * 0x10) & 0xF0);
            left_color.channels[2] = ((v * 0x10) & 0xF0);
            *(u32 *)packet.color_add = *(u32 *)&left_color;
            temp_f0_2 = ((1.0) + v / (12.0));
            packet.scale_y = temp_f0_2;
            packet.scale_x = temp_f0_2;
        }
        fn_1_4F734((FontDrawPacket *)&packet);
        packet = *(FontDrawPacket *)(*(u8 (*)[])&lbl_1_rodata_26F8);
        packet.y = (180.0f);
        packet.z = (0.140000001f);
        packet.x = (250.0f);
        packet.flags = 0xA;
        packet.image = 0x8F04;
        {
            u32 v = (*(NameEntryState * *)&lbl_10_bss_55CD8)->left_pulse;
            struct NameEntryColor right_color = {0, 0, 0, 0};
                        right_color.channels[0] = ((v * 0x10) & 0xF0);
            right_color.channels[1] = ((v * 0x10) & 0xF0);
            right_color.channels[2] = ((v * 0x10) & 0xF0);
            *(u32 *)packet.color_add = *(u32 *)&right_color;
            temp_f0_3 = ((1.0) + v / (12.0));
            packet.scale_y = temp_f0_3;
            packet.scale_x = temp_f0_3;
        }
        fn_1_4F734((FontDrawPacket *)&packet);
        packet.x = (390.0f);
        packet.flags |= 0x80000;
        {
            u32 v = (*(NameEntryState * *)&lbl_10_bss_55CD8)->right_pulse;
            struct NameEntryColor cursor_color = {0, 0, 0, 0};
                        cursor_color.channels[0] = (u8)((v * 0x10) & 0xF0);
            cursor_color.channels[1] = (u8)((v * 0x10) & 0xF0);
            cursor_color.channels[2] = (u8)((v * 0x10) & 0xF0);
            *(u32 *)packet.color_add = *(u32 *)&cursor_color;
            temp_f0_4 = ((1.0) + v / (12.0));
            packet.scale_y = temp_f0_4;
            packet.scale_x = temp_f0_4;
        }
        fn_1_4F734((FontDrawPacket *)&packet);
        if ((*(NameEntryState * *)&lbl_10_bss_55CD8)->name_length != 7 || (*(NameEntryState * *)&lbl_10_bss_55CD8)->name_complete == 0) {
            packet = *(FontDrawPacket *)(*(u8 (*)[])&lbl_1_rodata_26F8);
            packet.y = (378.0f);
            packet.image = 0x8F09;
            packet.z = (0.129999995f);
            cursor_scale = 1.1 + 0.25 * lbl_8006D188((s16)((lbl_801A66A0 << 8) & 0xFF00));
            packet.flags = 0xA;
            packet.scale_y = cursor_scale;
            packet.scale_x = cursor_scale;
            text_index = (*(NameEntryState * *)&lbl_10_bss_55CD8)->name_length;
            cursor_x = (text_index * 0x38) + 0x7C;
            while (text_index < 8) {
                packet.x = (f32)cursor_x;
                fn_1_4F734((FontDrawPacket *)&packet);
                cursor_x += 0x38;
                text_index += 1;
            }
        }
        if ((((*(NameEntryState * *)&lbl_10_bss_55CD8)->flags) >> 0x1FU) == 0) {
            *(struct NameEntryPacketWords *)&packet =
                *(struct NameEntryPacketWords *)(*(u8 (*)[])&lbl_1_rodata_26F8);
            packet.image = 0x8F00;
            packet.x = ((*(NameEntryState * *)&lbl_10_bss_55CD8)->selection_x);
            packet.y = (346.0f);
            packet.z = (0.119999997f);
            fn_1_4F734((FontDrawPacket *)&packet);
            packet.image = 0x8F01;
            packet.y = (397.0f);
            fn_1_4F734((FontDrawPacket *)&packet);
        }
        memset(buf, 0, 3);
        switch ((*(NameEntryState * *)&lbl_10_bss_55CD8)->letter_case) {
        case 0:
        default:
            text = (u8 *)(alphabet->capital + alphabet->selected_character * 2);
            break;
        case 1:
            text = (u8 *)(alphabet->small + alphabet->selected_character * 2);
            break;
        case 2:
            text = (u8 *)(alphabet->signs + alphabet->selected_character * 2);
            break;
        }
        strncpy((char *)buf, (const char *)text, 2);
        fn_1_49410();
        fn_1_494DC(0x2A);
        fn_1_495C8(9);
        fn_1_496FC((321.0f), (178.0f));
        {
            f64 t = (2.1666666666666665) * pulse_scale;
            fn_1_4955C(t, t);
        }
        fn_1_4A0D8((const char *)buf);
        packet = *(FontDrawPacket *)(*(u8 (*)[])&lbl_1_rodata_26F8);
        packet.image = 0x8F03;
        packet.x = (118.0f);
        packet.y = (118.0f);
        packet.z = (0.189999998f);
        fn_1_4F734((FontDrawPacket *)&packet);
        fn_1_49410();
        fn_1_494DC(0x2A);
        fn_1_496FC((140.0f), (118.0f));
        {
            struct NameEntryRGBA color = {0x00, 0xFF, 0xFF, 0x00};
            fn_1_49514(color);
        }
        if (lbl_801A66B4 == 5) {
            fn_1_4955C((0.625f), (0.625f));
        } else {
            fn_1_4955C((0.5f), (0.5f));
            fn_1_49590((0.300000012f));
            fn_1_495B0(0x80000000U);
        }
        fn_1_4A0D8(alphabet->label);
        fn_1_133DBC((void *)1);
    }
}
/* fzgx:end fn_10_24BD0 */

/* fzgx:begin fn_10_25610 */
/* Creates the letter object for one character of the name. */
static void name_entry_add_letter(u8 index, const u8 *ch, NameEntryRGBA color) {
    struct NameEntryLetter *e;

    e = fn_1_45D0(lbl_801A6410, 0x12, "name_entry.c", 0xD4);
    e->unk_8 = index * 0x38 + 0x7E;
    e->unk_A = 0x17A;
    e->unk_0 = 2;
    e->unk_1 = 0;
    e->unk_4 = e->unk_8;
    e->unk_6 = e->unk_A;
    e->name[0] = ch[0];
    e->name[1] = ch[1];
    e->color = color;
    e->unk_C = index;
    fn_1_3F8C((u32)"name_entry_fixed_letter", (u32)fn_10_2325C, (u32)e, 0xB);
}

/* Gives an empty name the default name and creates its letter objects. */
static void name_entry_set_default_name(void) {
    u8 *ptr;
    u32 i;

    ptr = lbl_10_bss_55CD8->name;
    if (*ptr == 0) {
        if (lbl_801A66B4 == 5) {
            fn_80083DB0((char *)ptr, "\x83G\x83t\x83[\x83\x8d");
        } else {
            fn_80083DB0((char *)ptr, "\x82\x65\x81|\x82y\x82\x64\x82q\x82n");
        }
        {
            NameEntryRGBA color = {0x00, 0xFF, 0xFF, 0x00};

            fn_1_435C(lbl_10_bss_55CD8->unk_8);
            i = 0;
            while (lbl_10_bss_55CD8->name[i * 2] != 0) {
                name_entry_add_letter(i, &lbl_10_bss_55CD8->name[i * 2], color);
                i++;
            }
        }
        lbl_10_bss_55CD8->unk_E = i;
    }
}
extern void *fn_1_45D0(u32, u32, const char *, u32);
extern void fn_1_435C(u32);
extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern void fn_1_47F74(s32);
extern void fn_1_411A4(u32);
extern void fn_10_23990();
extern void fn_10_2406C(void);
extern void fn_10_24BD0(void);

typedef union Word8 {
u32 w;
f32 f;
} Word8;
typedef struct Node {
u8 unk_0;
u8 pad_1[3];
u16 unk_4;
Word8 unk_8;
s8 unk_c;
u8 pad_d[0x5];
u16 unk_12;
u8 pad_14[0x4];
u32 unk_18;
u32 unk_1c;
u8 pad_20[0x1b];
u8 unk_3b;
u32 unk_3c;
} Node;
typedef struct {
u8 pad_0[0x700];
f32 unk_700;
f32 unk_704;
f32 unk_708;
} RData;
/* Carried from main: this function matches only with the optimizer settings below. */
#pragma opt_loop_invariants off
void fn_10_25610(u32 arg0, u32 arg1, u8 arg2) {
Node *n;
u32 i;
struct { u32 value; } j;
u16 *clear;
lbl_10_bss_55CD8 = (Obj_4_bss_5680_Target *)fn_1_45D0(lbl_801A6410, 0x40, "name_entry.c", 0x4ef);
fn_800793D4(lbl_10_bss_55CD8, 0, 0x40);
lbl_10_bss_55CD8->unk_4 = arg0;
lbl_10_bss_55CD8->unk_8 = arg1;
fn_1_435C(arg0);
lbl_10_bss_55CD8->unk_18 = fn_1_3F8C((u32)"name_entry_main", (u32)&fn_10_2406C, 0, 0xa);
fn_1_47F74(0x8f);
if (lbl_1_bss_960 != 1) {
fn_1_47F74(0x9a);
fn_1_47F74(0x9e);
fn_1_411A4(1);
}
fn_1_435C(arg1);
lbl_10_bss_55CD8->unk_1C = fn_1_3F8C((u32)"name_entry_disp_main", (u32)&fn_10_24BD0, 0, 0xa);
if (lbl_801A66B4 == 5) {
lbl_10_bss_55CD8->unk_3C = (u32)lbl_10_data_68E0;
lbl_10_bss_55CD8->unk_3B = 4;
} else {
lbl_10_bss_55CD8->unk_3C = (u32)lbl_10_data_6930;
lbl_10_bss_55CD8->unk_3B = 4;
}
i = 0;
while (i < lbl_10_bss_55CD8->unk_3B) {
n = (Node *)fn_1_45D0(lbl_801A6410, 0xc, "name_entry.c", 0x1a5);
fn_800793D4(n, 0, 0xc);
n->unk_0 = i;
switch ((u8)i) {
case 0:
n->unk_4 = 0xb2;
n->unk_8.f = (32.0f);
break;
case 1:
n->unk_4 = 0x114;
n->unk_8.f = (24.0f);
break;
case 2:
n->unk_4 = 0x139;
n->unk_8.f = (18.0f);
break;
case 3:
n->unk_4 = 0x54;
n->unk_8.f = (24.0f);
break;
}
fn_1_3F8C((u32)"name_entry_line", (u32)&fn_10_23990, (u32)n, 0xb);
i++;
}
lbl_10_bss_55CD8->unk_C = arg2;
j.value = 0;
clear = (u16 *)lbl_10_bss_55CD8->unk_3C;
while (j.value < lbl_10_bss_55CD8->unk_3B) {
*clear = 0;
j.value++;
}
lbl_10_bss_55CD8->unk_12 = 0x62;
fn_1_A2D84(0xa9100000U);
lbl_10_bss_55CDC = 0;
lbl_10_bss_55CDD = 0;
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_10_25610 */

/* fzgx:begin fn_10_25888 */
typedef signed char fn_10_25888_s8;
typedef signed short fn_10_25888_s16;
typedef signed long fn_10_25888_s32;
typedef signed long long fn_10_25888_s64;
typedef unsigned char fn_10_25888_u8;
typedef unsigned short fn_10_25888_u16;
typedef unsigned long fn_10_25888_u32;
typedef unsigned long long fn_10_25888_u64;
typedef float fn_10_25888_f32;
typedef double fn_10_25888_f64;
typedef int fn_10_25888_BOOL;
typedef unsigned long fn_10_25888_size_t;

typedef struct {
    fn_10_25888_u32 unk_0;
    fn_10_25888_u32 unk_4;
    fn_10_25888_u32 unk_8;
    fn_10_25888_u8 unk_C;
    fn_10_25888_u8 unk_D;
    fn_10_25888_u8 unk_E;
    fn_10_25888_u8 unk_F;
    fn_10_25888_u8 unk_10;
    fn_10_25888_u8 unk_11;
    fn_10_25888_u16 unk_12;
    fn_10_25888_u8 unk_14;
    fn_10_25888_u8 unk_15;
    fn_10_25888_u8 unk_16;
    fn_10_25888_u8 unk_17;
    fn_10_25888_u32 unk_18;
    fn_10_25888_u32 unk_1C;
    fn_10_25888_u32 unk_20;
    fn_10_25888_u8 pad_24[0x4];
    fn_10_25888_u8 unk_28;
    fn_10_25888_u8 pad_29[0xD];
    fn_10_25888_u8 unk_36;
    fn_10_25888_u8 unk_37;
    fn_10_25888_u8 pad_38[0x2];
    fn_10_25888_u8 unk_3A;
    fn_10_25888_u8 unk_3B;
    fn_10_25888_u32 unk_3C;
} fn_10_25888_Obj_10_bss_55CD8_Target;












extern fn_10_25888_s32 fn_1_14CEB8(fn_10_25888_u32);
typedef struct {
    fn_10_25888_u8 unk_0;
    fn_10_25888_u8 unk_1;
    fn_10_25888_u8 unk_2;
    fn_10_25888_u8 unk_3;
    fn_10_25888_u16 unk_4;
    fn_10_25888_u16 unk_6;
    fn_10_25888_u16 unk_8;
    fn_10_25888_u16 unk_A;
    fn_10_25888_u8 unk_C;
    fn_10_25888_u8 pad_D[0x3];
    fn_10_25888_u32 unk_10;
} Entry_4_D420;
typedef struct { fn_10_25888_u32 v; } Word;

/* Carried from main: this function matches only with the optimizer settings below. */
#pragma opt_loop_invariants off
fn_10_25888_s32 fn_10_25888(void) {
    fn_10_25888_s32 bit;
    fn_10_25888_s32 res;
    u32 i;

    res = 0;
        if ((lbl_10_bss_55CD8->unk_0 >> 30) & 1) {
        {
            NameEntryRGBA color = {0x00, 0xFF, 0xFF, 0x00};

            fn_1_435C(lbl_10_bss_55CD8->unk_8);
            i = 0;
            while (lbl_10_bss_55CD8->name[i * 2] != 0) {
                name_entry_add_letter(i, &lbl_10_bss_55CD8->name[i * 2], color);
                i++;
            }
        }
        {
            u32 flags = lbl_10_bss_55CD8->unk_0;
            /* Retail reloads the target pointer after reading its flags. */
            (*(Obj_4_bss_5680_Target * *)&lbl_10_bss_55CD8)->unk_0 = flags & ~0x40000000;
        }
    }
    if (lbl_10_bss_55CD8->unk_0 >> 31) {
        return 1;
    }
    if (((lbl_10_bss_55CD8->unk_0 >> 29) & 1) || ((lbl_10_bss_55CD8->unk_0 >> 28) & 1)) {
        fn_1_A2D84(0xA9010100);
        lbl_10_bss_55CD8->unk_0 &= ~0x20000000;
        lbl_10_bss_55CD8->unk_0 &= ~0x10000000;
        lbl_10_bss_55CD8->unk_0 |= 0x80000000;
        if (fn_1_14CEB8((fn_10_25888_u32)lbl_10_bss_55CD8 + 0x28) != 0) {
            bit = 0;
            lbl_10_bss_55CD8->unk_0 |= 0x40000000;
            while (((fn_10_25888_u8 *)lbl_10_bss_55CD8)[0x28 + bit * 2] != 0) {
                lbl_10_bss_55CD8->unk_20 |= 0x80000000 >> bit;
                bit++;
            }
        }
        name_entry_set_default_name();
        res = 1;
    }
    return res;
}

#pragma opt_loop_invariants reset
/* fzgx:end fn_10_25888 */

/* fzgx:begin fn_10_25BC8 */
extern void fn_1_426C(u32 value);
extern void fn_1_A8F78(void);
extern void fn_1_48140(int value);
extern void fn_1_412A0(int value);
void fn_10_25BC8(void) {
    lbl_10_bss_55CDC = 1;
    fn_1_435C(lbl_10_bss_55CD8->unk_4);
    fn_1_426C(lbl_10_bss_55CD8->unk_18);
    fn_1_A8F78();
    fn_1_48140(0x8f);

    if (lbl_1_bss_960 != 1) {
        if (lbl_1_bss_960 != 3) {
            fn_1_412A0(1);
            fn_1_48140(0x9a);
        }
        fn_1_48140(0x9e);
    }

    fn_1_435C(lbl_10_bss_55CD8->unk_8);
    fn_1_426C(lbl_10_bss_55CD8->unk_1C);
    fn_1_46B4(lbl_801A6410, (u32)lbl_10_bss_55CD8, "name_entry.c", 0x562);
    lbl_10_bss_55CD8 = 0;
}
/* fzgx:end fn_10_25BC8 */

/* fzgx:begin fn_10_25CB0 */
/* Carried from main: this function matches only with the optimizer settings below. */
#pragma opt_loop_invariants off
void fn_10_25CB0(u32 arg0) {
    name_entry_set_default_name();
    lbl_10_bss_55CD8->unk_0 |= 0x10000000;
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_10_25CB0 */

/* fzgx:begin fn_10_25E1C noprologue */
#include "types.h"
#include "rel/sel/globals.h"
#include "rel/sel/name_entry.h"


extern u8 lbl_10_bss_55CDC;
extern s16 lbl_1_bss_960;
extern u32 lbl_801A6410;
extern void fn_1_435C(u32 value);
extern void fn_1_426C(u32 value);
extern void fn_1_A8F78(void);
extern void fn_1_48140(int value);
extern void fn_1_412A0(int value);
extern u8 fn_1_B7C00(void);
extern u8 fn_10_26434(void);
extern void fn_10_26554(void);
extern void fn_1_14BD94(void *);
extern void fn_10_26424(void);
extern u16 lbl_1_bss_9F8[5];
extern u8 lbl_1_bss_8B3A0[0x9f];
extern void fn_1_A2D84(void *);
extern void fn_1_14BCBC(void *, u8);
extern u8 lbl_1_bss_8E51D;
extern u8 lbl_1_data_2B0D4[];
extern u8 lbl_1_data_2B144[];
extern s16 fn_1_12EF24(s16, s16);
extern s32 fn_1_F89E4(u8);
extern void fn_1_14A1AC(u8);
extern void fn_1_14BC40(void);
extern void fn_1_1554D0(void);
extern void fn_1_1555B0(u8);
extern void fn_1_47F74(s32);
extern void fn_1_15555C(void);
extern void fn_1_14BD74(void);
extern s32 lbl_801A66B4;
extern u8 lbl_10_data_68E0[];
extern u32 lbl_10_rodata_1D64;
extern char * fn_80083DB0(char *, const char *);
extern u32 fn_10_2325C(void);
extern s32 fn_1_3F8C(void *, u32, void *, u32);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u8);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4D494(void);
extern void fn_1_4AE0C(const char *, ...);
extern void fzgx_pool_use(void *);

#include "types.h"

typedef struct {
    u8 pad[0x8c];
    s16 value;
} fn_10_25E1C_NameEntryState;

typedef struct {
    s16 v[14];
} fn_10_25E1C_SndTable;

extern fn_10_25E1C_SndTable lbl_10_rodata_1D70;
extern u8 lbl_10_bss_55CE0;
extern u8 lbl_10_bss_55CE1;

void fn_10_25E1C(void) {
    fn_10_25E1C_NameEntryState *state = &(*(fn_10_25E1C_NameEntryState *)&lbl_1_bss_8B3A0);
    s32 i;
    s16 result;

    for (i = 0; i < 6; i++) {
        result = fn_1_12EF24(state->value, i);
        if (state->value == 5) {
            if (i == 5) {
                if (fn_1_F89E4(0) == 0) {
                    goto set_neg; // shared tail: retail merges both -1 arms
                }
            }
            if (i != 5) {
                if (fn_1_F89E4((i + 1)) == 0) {
                    goto set_neg; // shared tail: retail merges both -1 arms
                }
            }
            goto after_neg; // skip the merged -1 arm
        set_neg:
            result = -1;
        after_neg: ;
        }
        if (result != -1) {
            break;
        }
    }

    if (result != -1) {
        lbl_10_bss_55CE0 = result;
    } else {
        lbl_10_bss_55CE0 = fn_1_12EF24(state->value, 0);
    }

    fn_1_14A1AC(lbl_1_bss_8E51D);
    fn_1_14BC40();
    fn_1_1554D0();
    fn_1_1555B0(lbl_10_bss_55CE0);
    fn_1_47F74(0x91);
    fn_1_47F74(0x97);
    fn_1_47F74(0x99);

    for (i = 0; i < 6; i++) {
        result = fn_1_12EF24(state->value, i);
        if (result != -1) {
            u8 key = lbl_1_data_2B0D4[result];
            fn_10_25E1C_SndTable table = lbl_10_rodata_1D70;
            s16 index = lbl_1_data_2B144[key] - 1;

            if ((((u32)index > 13) ? 0 : (index >= 0)) && table.v[index] != -1) {
                fn_1_47F74(table.v[index]);
            }
        }
    }
    lbl_10_bss_55CE1 = 0;
}
/* fzgx:end fn_10_25E1C */

/* fzgx:begin fn_10_26000 noprologue */
#include "types.h"
#include "rel/sel/globals.h"
#include "rel/sel/name_entry.h"


extern u8 lbl_10_bss_55CDC;
extern s16 lbl_1_bss_960;
extern u32 lbl_801A6410;
extern void fn_1_435C(u32 value);
extern void fn_1_426C(u32 value);
extern void fn_1_A8F78(void);
extern void fn_1_48140(int value);
extern void fn_1_412A0(int value);
extern u8 fn_1_B7C00(void);
extern u8 fn_10_26434(void);
extern void fn_10_26554(void);
extern void fn_1_14BD94(void *);
extern void fn_10_26424(void);
extern u16 lbl_1_bss_9F8[5];
extern u8 lbl_1_bss_8B3A0[0x9f];
extern void fn_1_A2D84(void *);
extern void fn_1_14BCBC(void *, u8);
extern u8 lbl_1_bss_8E51D;
extern u8 lbl_1_data_2B0D4[];
extern u8 lbl_1_data_2B144[];
extern s16 fn_1_12EF24(s16, s16);
extern s32 fn_1_F89E4(u8);
extern void fn_1_14A1AC(u8);
extern void fn_1_14BC40(void);
extern void fn_1_1554D0(void);
extern void fn_1_1555B0(u8);
extern void fn_1_47F74(s32);
extern void fn_1_15555C(void);
extern void fn_1_14BD74(void);
extern s32 lbl_801A66B4;
extern u8 lbl_10_data_68E0[];
extern u32 lbl_10_rodata_1D64;
extern char * fn_80083DB0(char *, const char *);
extern u32 fn_10_2325C(void);
extern s32 fn_1_3F8C(void *, u32, void *, u32);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u8);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4D494(void);
extern void fn_1_4AE0C(const char *, ...);
extern void fzgx_pool_use(void *);

u8 fn_10_26000(void) {
    u8 result;
    u16 flags;

    if (fn_1_B7C00()) {
        return 0;
    }

    if (lbl_10_bss_55CE1 != 0) {
        result = fn_10_26434();
        if (result == 1) {
            fn_10_26554();
            fn_1_14BD94(&lbl_10_bss_55CE0);
        }
        if (result != 0) {
            lbl_10_bss_55CE1 = 0;
        }
        return result;
    }

    flags = lbl_1_bss_9F8[4];
    if (((flags >> 11) & 1) != 0) {
        // fzgx-allow: A1 target hardware address
        fn_1_A2D84((void *)0xA9011100); // fzgx-allow: A2 target hardware address
        fn_10_26424();
        lbl_10_bss_55CE1 = 1;
    }
    fn_1_14BCBC(&lbl_10_bss_55CE0, lbl_1_bss_8B3A0[0x9e]);
    return 0;
}
/* fzgx:end fn_10_26000 */

/* fzgx:begin fn_10_260D4 noprologue */
#include "types.h"
#include "rel/sel/globals.h"
#include "rel/sel/name_entry.h"


extern u8 lbl_10_bss_55CDC;
extern s16 lbl_1_bss_960;
extern u32 lbl_801A6410;
extern void fn_1_435C(u32 value);
extern void fn_1_426C(u32 value);
extern void fn_1_A8F78(void);
extern void fn_1_48140(int value);
extern void fn_1_412A0(int value);
extern u8 fn_1_B7C00(void);
extern u8 fn_10_26434(void);
extern void fn_10_26554(void);
extern void fn_1_14BD94(void *);
extern void fn_10_26424(void);
extern u16 lbl_1_bss_9F8[5];
extern u8 lbl_1_bss_8B3A0[0x9f];
extern void fn_1_A2D84(void *);
extern void fn_1_14BCBC(void *, u8);
extern u8 lbl_1_bss_8E51D;
extern u8 lbl_1_data_2B0D4[];
extern u8 lbl_1_data_2B144[];
extern s16 fn_1_12EF24(s16, s16);
extern s32 fn_1_F89E4(u8);
extern void fn_1_14A1AC(u8);
extern void fn_1_14BC40(void);
extern void fn_1_1554D0(void);
extern void fn_1_1555B0(u8);
extern void fn_1_47F74(s32);
extern void fn_1_15555C(void);
extern void fn_1_14BD74(void);
extern s32 lbl_801A66B4;
extern u8 lbl_10_data_68E0[];
extern u32 lbl_10_rodata_1D64;
extern char * fn_80083DB0(char *, const char *);
extern u32 fn_10_2325C(void);
extern s32 fn_1_3F8C(void *, u32, void *, u32);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u8);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4D494(void);
extern void fn_1_4AE0C(const char *, ...);
extern void fzgx_pool_use(void *);

#include "types.h"

typedef struct {
    u8 pad[0x8c];
    s16 value;
} fn_10_260D4_NameEntryState;

typedef struct {
    s16 v[14];
} fn_10_260D4_SndTable;

extern fn_10_260D4_SndTable lbl_10_rodata_1D8C;

extern void fn_1_48140(int);

void fn_10_260D4(void) {
    fn_10_260D4_NameEntryState *state = &(*(fn_10_260D4_NameEntryState *)&lbl_1_bss_8B3A0);
    s32 i;

    for (i = 5; i >= 0; i--) {
        s16 result = fn_1_12EF24(state->value, i);
        if (result != -1) {
            u8 key = lbl_1_data_2B0D4[result];
            fn_10_260D4_SndTable table = lbl_10_rodata_1D8C;
            s16 index = lbl_1_data_2B144[key] - 1;

            if ((((u32)index > 13) ? 0 : (index >= 0)) && table.v[index] != -1) {
                fn_1_48140(table.v[index]);
            }
        }
    }
    fn_1_48140(0x99);
    fn_1_48140(0x97);
    fn_1_48140(0x91);
    fn_1_15555C();
    fn_1_14BD74();
}
/* fzgx:end fn_10_260D4 */

/* fzgx:begin fn_10_261E4 noprologue */
#include "types.h"
#include "rel/sel/globals.h"
#include "rel/sel/name_entry.h"


extern u8 lbl_10_bss_55CDC;
extern s16 lbl_1_bss_960;
extern u32 lbl_801A6410;
extern void fn_1_435C(u32 value);
extern void fn_1_426C(u32 value);
extern void fn_1_A8F78(void);
extern void fn_1_48140(int value);
extern void fn_1_412A0(int value);
extern u8 fn_1_B7C00(void);
extern u8 fn_10_26434(void);
extern void fn_10_26554(void);
extern void fn_1_14BD94(void *);
extern void fn_10_26424(void);
extern u16 lbl_1_bss_9F8[5];
extern u8 lbl_1_bss_8B3A0[0x9f];
extern void fn_1_A2D84(void *);
extern void fn_1_14BCBC(void *, u8);
extern u8 lbl_1_bss_8E51D;
extern u8 lbl_1_data_2B0D4[];
extern u8 lbl_1_data_2B144[];
extern s16 fn_1_12EF24(s16, s16);
extern s32 fn_1_F89E4(u8);
extern void fn_1_14A1AC(u8);
extern void fn_1_14BC40(void);
extern void fn_1_1554D0(void);
extern void fn_1_1555B0(u8);
extern void fn_1_47F74(s32);
extern void fn_1_15555C(void);
extern void fn_1_14BD74(void);
extern s32 lbl_801A66B4;
extern u8 lbl_10_data_68E0[];
extern u32 lbl_10_rodata_1D64;
extern char * fn_80083DB0(char *, const char *);
extern u32 fn_10_2325C(void);
extern s32 fn_1_3F8C(void *, u32, void *, u32);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u8);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4D494(void);
extern void fn_1_4AE0C(const char *, ...);
extern void fzgx_pool_use(void *);

#include "dolphin/hw_regs.h"

extern u8 lbl_10_bss_55CDC;
extern s16 lbl_1_bss_960;
extern u32 lbl_801A6410;
extern void fn_1_435C(u32 value);
extern void fn_1_426C(u32 value);
extern void fn_1_A8F78(void);
extern void fn_1_48140(int value);
extern void fn_1_412A0(int value);
extern u8 fn_1_B7C00(void);
extern u8 fn_10_26434(void);
extern void fn_10_26554(void);
extern void fn_1_14BD94(void *);
extern void fn_10_26424(void);
extern u16 lbl_1_bss_9F8[5];
extern u8 lbl_1_bss_8B3A0[0x9f];
extern void fn_1_A2D84(void *);
extern void fn_1_14BCBC(void *, u8);
extern u8 lbl_1_bss_8E51D;
extern u8 lbl_1_data_2B0D4[];
extern u8 lbl_1_data_2B144[];
extern s16 fn_1_12EF24(s16, s16);
extern s32 fn_1_F89E4(u8);
extern void fn_1_14A1AC(u8);
extern void fn_1_14BC40(void);
extern void fn_1_1554D0(void);
extern void fn_1_1555B0(u8);
extern void fn_1_47F74(s32);
extern void fn_1_15555C(void);
extern void fn_1_14BD74(void);

extern u8 lbl_10_bss_55CDC;
extern s16 lbl_1_bss_960;
extern u32 lbl_801A6410;
extern void fn_1_435C(u32 value);
extern void fn_1_426C(u32 value);
extern void fn_1_A8F78(void);
extern void fn_1_48140(int value);
extern void fn_1_412A0(int value);
extern u8 fn_1_B7C00(void);
extern u8 fn_10_26434(void);
extern void fn_10_26554(void);
extern void fn_1_14BD94(void *);
extern void fn_10_26424(void);
extern u16 lbl_1_bss_9F8[5];
extern u8 lbl_1_bss_8B3A0[0x9f];
extern void fn_1_A2D84(void *);
extern void fn_1_14BCBC(void *, u8);
extern u8 lbl_1_bss_8E51D;
extern u8 lbl_1_data_2B0D4[];
extern u8 lbl_1_data_2B144[];
extern s16 fn_1_12EF24(s16, s16);
extern s32 fn_1_F89E4(u8);
extern void fn_1_14A1AC(u8);
extern void fn_1_14BC40(void);
extern void fn_1_1554D0(void);
extern void fn_1_1555B0(u8);
extern void fn_1_47F74(s32);
extern void fn_1_15555C(void);
extern void fn_1_14BD74(void);

typedef struct { u8 r, g, b, a; } Sig_fn_800081C8_Color;
typedef Sig_fn_800081C8_Color Color;

extern Color fn_800081C8(Color, Color, f32);
extern void fn_1_49514(Color);
extern u32 fn_1_4D4C8(Color, f32, f32);
extern void fn_1_49528(Color);

/*
 * Layout stand-in for the TU's .data block at lbl_10_data_6A48: the erase-dialog
 * strings and the per-language pointer tables (question, YES, NO). The pointer
 * tables are relocations in retail; here they are zero words so the private
 * section's bytes can be proven equal and bound to the retail objects at submit.
 */
#pragma explicit_zero_data on
static char fzgx_pool_sQuestionEn[32] = "OK to erase this course record?";
static char fzgx_pool_sQuestionGe[36] = "GER OK to erase this course record?";
static char fzgx_pool_sQuestionFr[36] = "FRE OK to erase this course record?";
static char fzgx_pool_sQuestionSp[36] = "SPA OK to erase this course record?";
static char fzgx_pool_sQuestionIt[36] = "ITA OK to erase this course record?";
static char fzgx_pool_sQuestionJp[52] =
    "\x82\xb1\x82\xcc\x83R\x81[\x83X\x82\xcc\x83\x8c\x83R\x81[\x83h\x82\xf0\x0a"
    "\x83N\x83\x8a\x83\x41\x82\xb5\x82\xc4\x82\xe0\x82\xe6\x82\xeb\x82\xb5\x82\xa2\x82\xc5\x82\xb7\x82\xa9?";
static char *fzgx_pool_sEraseQuestion[6] = {0};
static char fzgx_pool_sYesEn[4] = "YES";
static char fzgx_pool_sYesGe[8] = "GER YES";
static char fzgx_pool_sYesFr[8] = "FRE YES";
static char fzgx_pool_sYesSp[8] = "SPA YES";
static char fzgx_pool_sYesIt[8] = "ITA YES";
static char fzgx_pool_sYesJp[8] = "\x82\xcd\x82\xa2";
static char *fzgx_pool_sEraseYes[6] = {0};
static char fzgx_pool_sNoEn[4] = "NO";
static char fzgx_pool_sNoGe[8] = "GER NO";
static char fzgx_pool_sNoFr[8] = "FRE NO";
static char fzgx_pool_sNoSp[8] = "SPA NO";
static char fzgx_pool_sNoIt[8] = "ITA NO";
static char fzgx_pool_sNoJp[8] = "\x82\xa2\x82\xa2\x82\xa6";
static char *fzgx_pool_sEraseNo[6] = {0};
#pragma explicit_zero_data reset

/* Literal-pool primer: reproduces the order of the TU's shared .rodata pool. */
#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_fn_10_261E4(s32 x) {
    s16 t0[14] = {0xB5, 0xB6, 0xAD, 0xB3, 0xB8, 0xB2, 0xB1, 0xAE, 0xB4, 0xB9, 0xB0, 0xAF, 0xB7, -1};
    s16 t1[14] = {0xB5, 0xB6, 0xAD, 0xB3, 0xB8, 0xB2, 0xB1, 0xAE, 0xB4, 0xB9, 0xB0, 0xAF, 0xB7, -1};
    fzgx_pool_use(t0);
    fzgx_pool_use(t1);
    fzgx_pool_use(fzgx_pool_sEraseQuestion);
    fn_1_4955C(320.0f, 240.0f);
    fn_1_4955C(0.1f, 400.0f);
    fn_1_4955C(200.0f, 13.0f);
    fn_1_4955C(26.0f, 1.5f);
    fn_1_4955C(0.75f, 0.09f);
    fn_1_4955C(0.5f, -1.0f);
    fn_1_4955C(8.0f, 0.0f);
    fn_1_4954C(x);
}

void fn_10_261E4(s32 arg0, u8 arg1) {
    Color col = fn_800081C8((Color){0xA0, 0x50, 0x50, 0x00}, (Color){0xA0, 0xA0, 0xA0, 0x00}, 1.0f);

    fn_1_49410();
    fn_1_4955C(0.75f, 0.75f);
    fn_1_4954C(0.09f);
    fn_1_495C8(9);
    fn_1_495B0(0x80000000);
    fn_1_49590(0.5f);
    fn_1_496FC(288.0f, arg0);
    fn_1_495C8(10);
    if (!arg1) {
        fn_1_4D494();
        fn_1_49514((Color){0xFF, 0xFF, 0xFF, 0x00});
        fn_1_4AE0C("%s", fzgx_pool_sEraseYes[(*(u32 *)&lbl_801A66B4)]);
        fn_1_4D4C8(col, 0.09f, 10.0f);
    } else {
        fn_1_49514((Color){0x70, 0x70, 0x70, 0x00});
        fn_1_49528((Color){0x00, 0x00, 0x00, 0x00});
        fn_1_4AE0C("%s", fzgx_pool_sEraseYes[(*(u32 *)&lbl_801A66B4)]);
    }
    fn_1_496FC(352.0f, arg0);
    fn_1_495C8(8);
    if (!arg1) {
        fn_1_49514((Color){0x70, 0x70, 0x70, 0x00});
        fn_1_49528((Color){0x00, 0x00, 0x00, 0x00});
        fn_1_4AE0C("%s", fzgx_pool_sEraseNo[(*(u32 *)&lbl_801A66B4)]);
    } else {
        fn_1_4D494();
        fn_1_49514((Color){0xFF, 0xFF, 0xFF, 0x00});
        fn_1_4AE0C("%s", fzgx_pool_sEraseNo[(*(u32 *)&lbl_801A66B4)]);
        fn_1_4D4C8(col, 0.09f, 10.0f);
    }
}
/* fzgx:end fn_10_261E4 */

/* fzgx:begin fn_10_26424 noprologue */
#include "types.h"
#include "rel/sel/globals.h"
#include "rel/sel/name_entry.h"


extern u8 lbl_10_bss_55CDC;
extern s16 lbl_1_bss_960;
extern u32 lbl_801A6410;
extern void fn_1_435C(u32 value);
extern void fn_1_426C(u32 value);
extern void fn_1_A8F78(void);
extern void fn_1_48140(int value);
extern void fn_1_412A0(int value);
extern u8 fn_1_B7C00(void);
extern u8 fn_10_26434(void);
extern void fn_10_26554(void);
extern void fn_1_14BD94(void *);
extern void fn_10_26424(void);
extern u16 lbl_1_bss_9F8[5];
extern u8 lbl_1_bss_8B3A0[0x9f];
extern void fn_1_A2D84(void *);
extern void fn_1_14BCBC(void *, u8);
extern u8 lbl_1_bss_8E51D;
extern u8 lbl_1_data_2B0D4[];
extern u8 lbl_1_data_2B144[];
extern s16 fn_1_12EF24(s16, s16);
extern s32 fn_1_F89E4(u8);
extern void fn_1_14A1AC(u8);
extern void fn_1_14BC40(void);
extern void fn_1_1554D0(void);
extern void fn_1_1555B0(u8);
extern void fn_1_47F74(s32);
extern void fn_1_15555C(void);
extern void fn_1_14BD74(void);
extern s32 lbl_801A66B4;
extern u8 lbl_10_data_68E0[];
extern u32 lbl_10_rodata_1D64;
extern char * fn_80083DB0(char *, const char *);
extern u32 fn_10_2325C(void);
extern s32 fn_1_3F8C(void *, u32, void *, u32);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u8);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4D494(void);
extern void fn_1_4AE0C(const char *, ...);
extern void fzgx_pool_use(void *);

void fn_10_26424(void) {
    lbl_10_bss_55CE2 = 1;
}
/* fzgx:end fn_10_26424 */

/* fzgx:begin fn_10_26434 noprologue */
#include "types.h"

extern u16 lbl_1_bss_9F8[5];

typedef struct SelState {
    u8 pad0[8];
    u16 flags8;
    u8 padA[6];
    u16 flags10;
    u16 flags12;
} SelState;


extern u8 lbl_10_bss_55CE2;
extern void fn_1_A2D84(int arg);

int fn_10_26434(void) {
    if (((*(SelState *)&lbl_1_bss_9F8).flags10 & 1) ||
        ((*(SelState *)&lbl_1_bss_9F8).flags12 & 1)) {
        if (lbl_10_bss_55CE2 == 1) {
            lbl_10_bss_55CE2 = 0;
            fn_1_A2D84(0xA9011300);
        }
    }

    if (((((*(SelState *)&lbl_1_bss_9F8).flags10 >> 1) & 1)) ||
        ((((*(SelState *)&lbl_1_bss_9F8).flags12 >> 1) & 1))) {
        if (lbl_10_bss_55CE2 == 0) {
            lbl_10_bss_55CE2 = 1;
            fn_1_A2D84(0xA9011300);
        }
    }

    if ((((*(SelState *)&lbl_1_bss_9F8).flags8 >> 8) & 1)) {
        fn_1_A2D84(0xA9011100);
        if (lbl_10_bss_55CE2 == 0) {
            return 1;
        }
        if (lbl_10_bss_55CE2 == 1) {
            return 2;
        }
    }

    if ((((*(SelState *)&lbl_1_bss_9F8).flags8 >> 9) & 1)) {
        fn_1_A2D84(0xA9011000);
        return 2;
    }

    return 0;
}
/* fzgx:end fn_10_26434 */
