#include "types.h"

/* The name-entry screen of the option menu: the character pages, the letter tasks, the input and the draw task. */

typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
    f32 x, y, z;
} FontVertex;
/* Packed RGBA transfers coexist with channel-level color operations. */
union fn_4_Color { u32 word; u8 channels[4]; };
struct FontDrawPacket {
    u32 image;
    f32 x, y, z;
    f32 scale_x, scale_y;
    f32 u0, v0, u1, v1;
    s16 rotation_z, rotation_y;
    f32 alpha;
    u32 flags;
    f32 depth;
    union fn_4_Color color, color_add;
    u32 format;
    u16 width, height;
    void *pixels;
    FontDrawPacket *secondary;
    void (*vertex_callback)(FontDrawPacket *packet, FontVertex *vertices);
    u32 unk_54;
};

/* lbl_4_bss_5680: the name-entry work area */
typedef struct {
    u32 unk_0; /* 11 loads, 6 stores */
    u32 unk_4; /* 1 loads, 1 stores */
    u32 unk_8; /* 4 loads, 1 stores */
    u8 unk_C; /* 8 loads, 1 stores */
    u8 unk_D; /* 5 loads, 4 stores */
    u8 unk_E; /* 10 loads, 3 stores */
    u8 unk_F; /* 3 loads, 12 stores */
    u8 unk_10; /* 1 loads, 0 stores */
    u8 unk_11; /* 2 loads, 1 stores */
    u16 unk_12; /* 3 loads, 3 stores */
    u8 unk_14; /* 2 loads, 2 stores */
    u8 unk_15; /* 2 loads, 2 stores */
    u8 unk_16; /* 2 loads, 2 stores */
    u8 unk_17; /* 2 loads, 2 stores */
    u32 unk_18; /* 1 loads, 1 stores */
    u32 unk_1C; /* 1 loads, 1 stores */
    u32 unk_20; /* 3 loads, 2 stores */
    u8 pad_24[0x4];
    u8 name[0xE]; /* the name: two bytes for each character */
    u8 unk_36; /* 2 loads, 1 stores */
    u8 unk_37; /* 0 loads, 1 stores */
    u8 pad_38[0x2];
    u8 unk_3A; /* 2 loads, 2 stores */
    u8 unk_3B; /* 5 loads, 2 stores */
    u32 unk_3C; /* 4 loads, 2 stores */
} Obj_4_bss_5680_Target;

/* One page of the character table: the cursor, the character count, up to three character rows and the page name. */
typedef struct {
    u16 cursor;
    u16 count;
    const char *rows[3];
    const char *label;
} NameEntryPage;

extern s16 lbl_1_bss_960;
extern s32 lbl_801A66B4;
extern u32 lbl_801A66A0;
extern u32 lbl_801A6410;
extern u8 lbl_1_rodata_26F8[];
extern u32 lbl_1_bss_9F8;
extern u8 lbl_1_bss_A48[];
extern u32 lbl_1_data_418D4[];

extern void *fn_1_45D0(u32, u32, const char *, u32);
extern void fn_1_46B4(u32, u32, const char *, int);
extern s32 fn_1_3F8C(const char *, u32, u32, u32);
extern void fn_1_435C(u32);
extern u32 fn_1_426C(u32);
extern u32 fn_1_4060(void);
extern void fn_1_411A4(u32);
extern u32 fn_1_412A0(u32);
extern void fn_1_47F74(s32);
extern u32 fn_1_48140(u32);
extern u32 fn_1_A8F78(void);
extern void fn_1_A2D84(u32);
extern s32 fn_1_14CEB8(u32);
extern u32 fn_1_134AD4(void);
extern void fn_1_133DBC(void *);
extern void fn_1_1380F0(void *);
extern u32 fn_1_13ABA8(u32);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495C8(u8);
extern void fn_1_49514();
extern void fn_1_496FC(f32, f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_4954C(f32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_4A0D8(const char *);
extern f32 lbl_8006D188(s16);
extern u32 fn_800793D4(void *, s32, u32);
extern u32 fn_80083DB0(void *, const void *);
extern u8 *fn_80083970(u8 *, const u8 *);
extern char *fn_80083CF4(char *, const char *, size_t);
extern void *memset(void *, int, u32);
extern char *strncpy(char *, const char *, size_t);
extern char *strcat(char *, const char *);
extern s32 strncmp(const char *, const char *, size_t);
extern int sprintf(char *, const char *, ...);
extern size_t strlen(const char *);
extern int __abs(int);

const char lbl_4_rodata_410[] = "\211p\220\224";
const char lbl_4_rodata_418[] =
    "\202`\202a\202b\202c\202d\202e\202f\202g\202h\202i\202j\202k\202l\202m\202n\202o\202p\202q\202r"
    "\202s\202t\202u\202v\202w\202x\202y\202\201\202\202\202\203\202\204\202\205\202\206\202\207\202"
    "\210\202\211\202\212\202\213\202\214\202\215\202\216\202\217\202\220\202\221\202\222\202\223\202"
    "\224\202\225\202\226\202\227\202\230\202\231\202\232\202O\202P\202Q\202R\202S\202T\202U\202V\202"
    "W\202X\201\347\201\350";
const char lbl_4_rodata_49C[] =
    "\202\201\202\202\202\203\202\204\202\205\202\206\202\207\202\210\202\211\202\212\202\213\202\214"
    "\202\215\202\216\202\217\202\220\202\221\202\222\202\223\202\224\202\225\202\226\202\227\202\230"
    "\202\231\202\232\202`\202a\202b\202c\202d\202e\202f\202g\202h\202i\202j\202k\202l\202m\202n\202o"
    "\202p\202q\202r\202s\202t\202u\202v\202w\202x\202y\201@\201@\201@\201@\201@\201@\201@\201@\201@"
    "\201@\201@\201@";
const char lbl_4_rodata_520[] = "\213L\215\206";
const char lbl_4_rodata_528[] =
    "\201A\201B\201L\201M\201E\201C\201D\201F\201G\201H\201I\201{\201|\201^\201\201\201\203\201\204"
    "\201O\201Q\201`\201b\201u\201v\201i\201j\201o\201p\201m\201n\201\217\201\220\201\223\201\224\201"
    "\225\201\226\201\227\201\347\201\350";
const char lbl_4_rodata_578[] = "\202\320\202\347\202\252\202\310";
const char lbl_4_rodata_584[] =
    "\202\240\202\242\202\244\202\246\202\250\202\251\202\253\202\255\202\257\202\261\202\263\202\265"
    "\202\267\202\271\202\273\202\275\202\277\202\302\202\304\202\306\202\310\202\311\202\312\202\313"
    "\202\314\202\315\202\320\202\323\202\326\202\331\202\334\202\335\202\336\202\337\202\340\202\342"
    "\202\344\202\346\202\347\202\350\202\351\202\352\202\353\202\355\202\356\202\357\202\360\202\361"
    "\202\252\202\254\202\256\202\260\202\262\202\264\202\266\202\270\202\272\202\274\202\276\202\300"
    "\202\303\202\305\202\307\202\316\202\321\202\324\202\327\202\332\202\317\202\322\202\325\202\330"
    "\202\333\202\237\202\241\202\243\202\245\202\247\202\301\202\341\202\343\202\345\202\354\201\347"
    "\201\350";
const char lbl_4_rodata_630[] =
    "\202\237\202\241\202\243\202\245\202\247\202\252\202\254\202\256\202\260\202\262\202\264\202\266"
    "\202\270\202\272\202\274\202\276\202\300\202\301\202\305\202\307\201@\201@\201@\201@\201@\202"
    "\316\202\321\202\324\202\327\202\332\201@\201@\201@\201@\201@\202\341\202\343\202\345\201@\201@"
    "\201@\201@\201@\202\354\201@\201@\201@\201@\202\251\202\253\202\255\202\257\202\261\202\263\202"
    "\265\202\267\202\271\202\273\202\275\202\277\202\302\202\304\202\306\202\317\202\322\202\325\202"
    "\330\202\333\202\315\202\320\202\323\202\326\202\331\202\240\202\242\202\244\202\246\202\250\202"
    "\302\202\342\202\344\202\346\202\355\201@\201@";
const char lbl_4_rodata_6DC[] =
    "\201@\201@\201@\201@\201@\201@\201@\201@\201@\201@\201@\201@\201@\201@\201@\201@\201@\202\303"
    "\201@\201@\201@\201@\201@\201@\201@\202\317\202\322\202\325\202\330\202\333\201@\201@\201@\201@"
    "\201@\201@\201@\201@\201@\201@\201@\201@\201@\201@\201@\201@\201@\201@\201@\201@\201@\201@\201@"
    "\201@\201@\201@\201@\201@\201@\201@\202\301\201@\201@\202\315\202\320\202\323\202\326\202\331"
    "\202\316\202\321\202\324\202\327\202\332\201@\201@\201@\201@\201@\202\303\201@\201@\201@\201@"
    "\201@\201@";
const char lbl_4_rodata_788[] = "\203J\203^\203J\203i";
const char lbl_4_rodata_794[] =
    "\203A\203C\203E\203G\203I\203J\203L\203N\203P\203R\203T\203V\203X\203Z\203\134\203^\203`\203c"
    "\203e\203g\203i\203j\203k\203l\203m\203n\203q\203t\202\326\203z\203}\203~\203\200\203\201\203"
    "\202\203\204\203\206\203\210\203\211\203\212\203\213\203\214\203\215\203\217\203\220\203\221\203"
    "\222\203\223\203\224\203K\203M\203O\203Q\203S\203U\203W\203Y\203[\203]\203_\203a\203d\203f\203h"
    "\203o\203r\203u\202\327\203{\203p\203s\203v\202\330\203|\203@\203B\203D\203F\203H\203\225\203"
    "\226\203b\203\203\203\205\203\207\203\216\201\347\201\350";
const char lbl_4_rodata_848[] =
    "\203@\203B\203D\203F\203H\203K\203M\203O\203Q\203S\203U\203W\203Y\203[\203]\203_\203a\203b\203f"
    "\203h\201@\201@\201@\201@\201@\203o\203r\203u\202\327\203{\201@\201@\201@\201@\201@\203\203\203"
    "\205\203\207\201@\201@\201@\201@\201@\203\216\201@\201@\201@\201@\203E\203J\203L\203N\203P\203R"
    "\203T\203V\203X\203Z\203\134\203^\203`\203c\203e\203g\203p\203s\203v\202\330\203|\203n\203q\203t"
    "\202\326\203z\203A\203C\203E\203G\203I\203J\203P\203c\203\204\203\206\203\210\203\217\201@\201@";
const char lbl_4_rodata_8FC[] =
    "\201@\201@\203\224\201@\201@\203\225\201@\201@\203\226\201@\201@\201@\201@\201@\201@\201@\201@"
    "\203d\201@\201@\201@\201@\201@\201@\201@\203p\203s\203v\202\330\203|\201@\201@\201@\201@\201@"
    "\201@\201@\201@\201@\201@\201@\201@\201@\201@\201@\201@\201@\201@\203D\203\225\201@\201@\203\226"
    "\201@\201@\201@\201@\201@\201@\201@\201@\203b\201@\201@\203n\203q\203t\202\326\203z\203o\203r"
    "\203u\202\327\203{\201@\201@\203\224\201@\201@\203K\203Q\203d\201@\201@\201@\201@\201@\201@";
const char lbl_4_rodata_9B0[] = "Capital Letters";
const char lbl_4_rodata_9C0[] =
    "\202`\202a\202b\202c\202d\202e\202f\202g\202h\202i\202j\202k\202l\202m\202n\202o\202p\202q\202r"
    "\202s\202t\202u\202v\202w\202x\202y\201\347\201\350";
const char lbl_4_rodata_9FC[] = "Small Letters";
const char lbl_4_rodata_A0C[] =
    "\202\201\202\202\202\203\202\204\202\205\202\206\202\207\202\210\202\211\202\212\202\213\202\214"
    "\202\215\202\216\202\217\202\220\202\221\202\222\202\223\202\224\202\225\202\226\202\227\202\230"
    "\202\231\202\232\201\347\201\350";
const char lbl_4_rodata_A48[] = "Signs";
const char lbl_4_rodata_A50[] =
    "\201C\201D\201H\201I\201{\201|\201^\201_\201\201\201\203\201\204\201F\201G\201L\201M\201O\201Q"
    "\201b\201i\201j\201m\201n\201o\201p\201\220\201\223\201\224\201\225\201\226\201\227\201\347\201"
    "\350";
const char lbl_4_rodata_A94[] = "Numbers";
const char lbl_4_rodata_A9C[] = "\202O\202P\202Q\202R\202S\202T\202U\202V\202W\202X\201\347\201\350";

/* The character pages of the Japanese version: letters and digits, symbols, hiragana, katakana. */
NameEntryPage lbl_4_data_2F78[4] = {
    {0, 0x40, {lbl_4_rodata_418, lbl_4_rodata_49C, NULL}, lbl_4_rodata_410},
    {0, 0x26, {lbl_4_rodata_528, NULL, NULL}, lbl_4_rodata_520},
    {0, 0x55, {lbl_4_rodata_584, lbl_4_rodata_630, lbl_4_rodata_6DC}, lbl_4_rodata_578},
    {0, 0x58, {lbl_4_rodata_794, lbl_4_rodata_848, lbl_4_rodata_8FC}, lbl_4_rodata_788},
};

/* The character pages of the other versions: capital letters, small letters, signs, numbers. */
NameEntryPage lbl_4_data_2FC8[4] = {
    {0, 0x1C, {lbl_4_rodata_9C0, NULL, NULL}, lbl_4_rodata_9B0},
    {0, 0x1C, {lbl_4_rodata_A0C, NULL, NULL}, lbl_4_rodata_9FC},
    {0, 0x20, {lbl_4_rodata_A50, NULL, NULL}, lbl_4_rodata_A48},
    {0, 0x0C, {lbl_4_rodata_A9C, NULL, NULL}, lbl_4_rodata_A94},
};

Obj_4_bss_5680_Target *lbl_4_bss_5680 = NULL;
u8 lbl_4_bss_5684;
u8 lbl_4_bss_5685;

/* fzgx:begin fn_4_ADF4 */
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

static inline s32 fn_4_ADF4_sign(s32 x) { return x < 0 ? -1 : x > 0; }
void fn_4_ADF4(struct fn_8_D630_obj *arg0)
{
struct fn_8_D630_obj *p;
u8 name[4];
u8 ph[4];
u32 col1;
u32 col2;
u32 col3;
u32 col4;
FontDrawPacket loc_20;
f32 f;
f32 scale;
u32 t;
u32 n2;
s32 e;
p = arg0;
if (lbl_4_bss_5684 != 0) {
fn_1_46B4(lbl_801A6410, (u32)p, "name_entry.c", 0xFB);
fn_1_4060();
return;
}
n2 = (p->unk_C + 1) & 0x1F;
t = lbl_4_bss_5680->unk_20;
/* WARNING: compiler-diff device, not original code (__rlwnm intrinsic: retail tests the bit with one rlwnm, carried from main) */
if (__rlwnm(t, n2, 31, 31) != 0) {
if (p->unk_0 != 1 || p->unk_1 != 0x18) {
p->unk_0 = 4;
p->unk_1 = 0x10;
lbl_4_bss_5680->unk_20 &= ~(0x80000000U >> p->unk_C);
if (strncmp((const char *)p + 2, "\201@", 2) == 0) {
strncpy((char *)p + 2, "\201\347", 2);
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
{
u16 c4 = p->unk_4;
s32 t4 = p->unk_8 - c4;
f64 dd = 0.21 * t4;
if ((s32)dd != 0) {
p->unk_4 = (c4 + dd);
} else {
e = fn_4_ADF4_sign(t4);
/* Retail rereads the position after selecting the one-step adjustment. */
/* WARNING: compiler-diff device, not original code (volatile read: retail reloads the x position, carried from main) */
p->unk_4 = *(volatile u16 *)&p->unk_4 + e;
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
/* WARNING: compiler-diff device, not original code (volatile read: retail reloads the y position, carried from main) */
p->unk_6 = *(volatile u16 *)&p->unk_6 + e;
}
}
}
col1 = p->unk_D;
fn_1_49514(&col1);
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
*(u32 *)ph = p->unk_D;
{
f32 quarter = 0.25f;
f = p->unk_1 * quarter;
{
ph[0] += (255 - ph[0]) * f;
ph[1] += (255 - ph[1]) * f;
ph[2] += (255 - ph[2]) * f;
}
}
col2 = *(u32 *)ph;
fn_1_49514(&col2);
fn_1_496FC(p->unk_4, p->unk_6);
{
f64 scale_d = 1.6666666666666667 * (1.0 + 0.5 * f);
fn_1_4955C(scale_d, scale_d);
}
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.image = 0x8F09;
loc_20.x = p->unk_4;
loc_20.y = p->unk_6;
loc_20.z = 0.13f;
loc_20.scale_x = loc_20.scale_y = (1.5 + 2.0 * f);
loc_20.flags = 0xA;
fn_1_4F734((FontDrawPacket *)&loc_20);
if (p->unk_1 == 1) {
p->unk_0 = 3;
if (strncmp((const char *)p + 2, "\201\347", 2) == 0) {
strncpy((char *)p + 2, "\201@", 2);
name[0] = p->unk_2;
name[1] = p->unk_3;
}
}
break;
case 3:
col3 = p->unk_D;
fn_1_49514(&col3);
fn_1_496FC(p->unk_4, p->unk_6);
fn_1_4955C(1.6666666f, 1.6666666f);
break;
case 4:
if (p->unk_1 == 0) {
fn_1_46B4(lbl_801A6410, (u32)p, "name_entry.c", 0x169);
fn_1_4060();
return;
}
col4 = p->unk_D;
fn_1_49514(&col4);
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
/* fzgx:end fn_4_ADF4 */

/* fzgx:begin fn_4_B528 */
typedef struct Sig_fn_800081C8_Color { u8 r, g, b, a; } Sig_fn_800081C8_Color;
extern u32 fn_800081C8(Sig_fn_800081C8_Color, Sig_fn_800081C8_Color, f32);
extern u32 lbl_801A63D0;

/* The glyph size of each column of the name line. */
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

/* WARNING: compiler-diff device, not original code (opt_lifetimes and opt_loop_invariants off, carried from main) */
#pragma opt_lifetimes off
#pragma opt_loop_invariants off
void fn_4_B528(u32 arg0) {
u8 *p_lbl_1_rodata_26F8;
u32 v0;
s32 v1;
s32 v2;
s32 state_value;
s32 cursor_next;
s32 v3;
u32 v4;
f32 v5;
f64 v6;
f32 v7;
struct OptionNameEntry { u16 cursor, length; char *chars; u8 pad[12]; } *v8;
u32 v9;
s32 v10;
u32 v12;
u32 v13;
u32 v14;
s32 v15;
f32 v16;
u16 v17;
f64 v18;
u32 v19;
u8 * v20;
u32 v21;
u32 v22;
f64 v23;
f32 v24;
f64 v25;
f32 v26;
f32 v27;
struct { u32 a[22]; } loc_18;
Sig_fn_800081C8_Color loc_14;
Sig_fn_800081C8_Color loc_10;
Sig_fn_800081C8_Color loc_C;
u32 loc_8;

u32 lab_t0;
u32 lab_t1;
fn_800793D4((void *)lbl_801A63D0, 0, 1024);
v0 = lbl_801A63D0;
if (lbl_4_bss_5684 != 0) {
v2 = (arg0);
v1 = (u32)&lbl_801A6410;
v3 = (s32)"name_entry.c";
v1 = *(u32 *)((u8 *)v1);
v4 = 465;
fn_1_46B4(v1, v2, (const char *)v3, v4);
v1 = fn_1_4060();
} else {
fn_1_49410();
v1 = 42;
fn_1_494DC(v1);
v1 = 9;
fn_1_495C8(v1);
fn_1_4966C(12.0f, 0.0f);
v1 = lbl_4_bss_5680->unk_3C;
v8 = (struct OptionNameEntry *)v1 + *(u8 *)arg0;
v19 = v8->cursor;
v3 = (v19 - 10);
v1 = (v19 + 11);
if (v3 >= 0 && (s32)(v19 + 11) <= v8->length) {
v2 = ((u32)v8->chars);
v1 = v0;
v9 = (v3 << 1);
v3 = 42;
{ s32 __reg_value_v2 = (v2 + v9); v2 = __reg_value_v2; }
v1 = (u32)strncpy((char *)v1, (const char *)v2, v3);
} else if (v19 < 10) {
v10 = v19 - 10;
v10 = v8->length + v10;
if (v10 < 0) {
v2 = ((u32)v8->chars);
v1 = v0;
{ s32 __reg_value_v2 = (v2 + (v19 << 1)); v2 = __reg_value_v2; }
lab_t0 = v1;
lab_t1 = v2;
v1 = fn_80083DB0((void *)lab_t0, (const void *)lab_t1);
{ s32 __reg_value_v2 = (u32)v8->chars; v2 = __reg_value_v2; }
v1 = v0;
v1 = (u32)strcat((char *)v1, (const char *)v2);
{ s32 __reg_value_v2 = (u32)v8->chars; v2 = __reg_value_v2; }
v1 = v0;
v3 = ((v10 + 10) << 1);
v1 = (u32)fn_80083CF4((char *)v1, (const char *)v2, v3);
} else {
v2 = ((u32)v8->chars);
v1 = v0;
{ s32 __reg_value_v2 = (v2 + (v10 << 1)); v2 = __reg_value_v2; }
lab_t0 = v1;
lab_t1 = v2;
v1 = fn_80083DB0((void *)lab_t0, (const void *)lab_t1);
v1 = v8->cursor;
v10 = (v1 + 11);
if (v10 > v8->length) {
v2 = ((u32)v8->chars);
v1 = v0;
v1 = (u32)strcat((char *)v1, (const char *)v2);
v1 = v0;
{ s32 __reg_value_v2 = (u32)v8->chars; v2 = __reg_value_v2; }
v3 = ((v10 - v8->length) << 1);
v1 = (u32)fn_80083CF4((char *)v1, (const char *)v2, v3);
} else {
v2 = ((u32)v8->chars);
v1 = v0;
v3 = (v10 << 1);
v1 = (u32)fn_80083CF4((char *)v1, (const char *)v2, v3);
}
}
} else {
v2 = ((u32)v8->chars);
v1 = v0;
{ s32 __reg_value_v2 = (v2 + (v3 << 1)); v2 = __reg_value_v2; }
lab_t0 = v1;
lab_t1 = v2;
v1 = fn_80083DB0((void *)lab_t0, (const void *)lab_t1);
{ s32 __reg_value_v2 = v8->cursor; v2 = __reg_value_v2; }
v1 = v0;
v3 = v8->length;
v12 = (v2 + 11);
{ s32 __reg_value_v2 = (u32)v8->chars; v2 = __reg_value_v2; }
v3 = ((v12 - v3) << 1);
v1 = (u32)fn_80083CF4((char *)v1, (const char *)v2, v3);
}
v2 = (*(u8 *)((u8 *)arg0));
v1 = (u32)lbl_4_bss_5680;
if ((u32)v2 == *(u8 *)((u8 *)v1 + 13)) {
u32 b14;
v2 = ((v0 + 6));
v1 = (u32)&lbl_801A63D0;
v3 = 14;
v1 = *(u32 *)((u8 *)v1);
v10 = (v1 + 44);
b14 = (v1 + 88);
v1 = v10;
v1 = (u32)strncpy((char *)v1, (const char *)v2, v3);
v1 = b14;
{ s32 __reg_value_v2 = (v0 + 22); v2 = __reg_value_v2; }
v3 = 14;
v1 = (u32)strncpy((char *)v1, (const char *)v2, v3);
v1 = v0;
v3 = v10;
v4 = b14;
{ s32 __reg_value_v2 = (s32)"%s\201@\201@\201@%s"; v2 = __reg_value_v2; }
v1 = sprintf((char *)v1, (const char *)v2, v3, v4);
}
v1 = (u32)lbl_4_bss_5680;
v1 = *(u8 *)((u8 *)v1 + 13);
v1 = (*(u8 *)((u8 *)arg0) - v1);
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
state_value = *(u16 *)((u8 *)arg0 + 4);
v3 = v15 - state_value;
v6 = 0.2 * v3;
if ((s32)v6 != 0) {
*(u16 *)((u8 *)arg0 + 4) = (s32)((f64)(u32)state_value + v6);
} else {
if (v3 < 0) {
v1 = -1;
} else {
v1 = v3 > 0;
}
*(u16 *)((u8 *)arg0 + 4) += v1;
}
v7 = *(f32 *)((u8 *)arg0 + 8);
v6 = 0.2;
*(f32 *)((u8 *)arg0 + 8) = v7 + v6 * (v16 - v7);
v1 = *(u8 *)((u8 *)arg0 + 2);
v13 = v8->cursor;
state_value = v1 + 1;
if (state_value == (s32)v13 || --v1 > (s32)v13) {
*(u8 *)((u8 *)arg0 + 1) = 36;
} else if (v1 == (s32)v13 || state_value < (s32)v13) {
*(s8 *)((u8 *)arg0 + 1) = -36;
}
v2 = (s8)*(u8 *)((u8 *)arg0 + 1);
v3 = -v2;
v6 = 0.2 * v3;
if ((s32)v6 != 0) {
*(u8 *)((u8 *)arg0 + 1) = (s32)((f64)v2 + v6);
} else {
if (v3 < 0) {
v1 = -1;
} else {
v1 = v3 > 0;
}
*(u8 *)((u8 *)arg0 + 1) += v1;
}
v1 = v0;
v2 = (s32)"\201\350";
*(u8 *)((u8 *)arg0 + 2) = v8->cursor;
v1 = (u32)fn_80083970((u8 *)v1, (const u8 *)v2);
p_lbl_1_rodata_26F8 = lbl_1_rodata_26F8;
v15 = 0x10000 - 28914;
v20 = (u8 *)v1;
v24 = 10.1f;
v25 = 24.0;
while (v20 != 0) {
v1 = strlen((const char *)v0);
state_value = v20 - (u8 *)v0;
v3 = v1 - 1;
v1 = (u32)state_value >> 31;
v1 = v1 + state_value;
state_value = (u32)v3 >> 2;
v1 >>= 1;
v3 = (u32)&loc_14;
v2 = v1 - state_value;
state_value = (u32)p_lbl_1_rodata_26F8 - 4;
for (v21 = 11; v21 != 0; v21--) {
v1 = *(u32 *)((u8 *)state_value + 4);
v22 = *(u32 *)((u8 *)state_value + 8);
state_value += 8;
*(u32 *)((u8 *)v3 + 4) = v1;
*(u32 *)((u8 *)v3 + 8) = v22;
v3 += 8;
}
loc_18.a[0] = v15;
v3 = *(u8 *)((u8 *)arg0 + 1);
v1 = (s8)v3;
v26 = v2 * *(f32 *)((u8 *)arg0 + 8);
v5 = (v1 + 320);
*(f32 *)((u8 *)&loc_18 + 4) = v5 + v26;
if (__abs(v2) > 0) {
v3 = 1;
if (v2 < 0) v3 = -1;
state_value = v2 >> 31;
v1 = state_value ^ v2;
v1 -= state_value;
v6 = 12.0;
v7 = *(f32 *)((u8 *)&loc_18 + 4);
*(f32 *)((u8 *)&loc_18 + 4) = v7 + v6 * (v3 * v1);
}
*(f32 *)((u8 *)&loc_18 + 8) = (f32)(u32)*(u16 *)((u8 *)arg0 + 4);
*(f32 *)((u8 *)&loc_18 + 12) = v24;
loc_18.a[12] = 10;
v5 = 1.0f;
v27 = *(f32 *)((u8 *)arg0 + 8) / v25;
*(f32 *)((u8 *)&loc_18 + 20) = v27;
*(f32 *)((u8 *)&loc_18 + 16) = v27;
{
Sig_fn_800081C8_Color black = {0, 0, 0, 255};
Sig_fn_800081C8_Color white = {255, 255, 255, 255};
loc_10 = black;
loc_C = white;
v1 = fn_800081C8(loc_10, loc_C, v5);
}
loc_18.a[14] = v1;
fn_1_4F734((FontDrawPacket *)&loc_18);
v20 = fn_80083970(v20 + 2, (const u8 *)"\201\350");
}
v2 = (s8)*(u8 *)((u8 *)arg0 + 1);
v2 += 320;
v5 = v2;
v6 = (f32)(u32)*(u16 *)((u8 *)arg0 + 4);
fn_1_496FC(v5, v6);
v18 = *(f32 *)((u8 *)arg0 + 8) / 24.0;
fn_1_4955C(v18, v18);
{
fn_1_49514(loc_14);
}
fn_1_4954C(10.0f);
fn_1_4A0D8((const char *)v0);
}
}
#pragma opt_loop_invariants reset
#pragma opt_lifetimes reset
/* fzgx:end fn_4_B528 */

/* fzgx:begin fn_4_BC04 */
typedef struct { u8 r, g, b, a; } MenuColor;
typedef struct {
u16 cur;
u16 max;
u8 *p4;
u8 *p8;
u8 *pC;
u32 pad;
} MenuEntry;
void fn_4_BC04(void) {
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
Obj_4_bss_5680_Target *state;
u8 *t8;
MenuEntry *e;
s32 inputIndex;
Obj_4_bss_5680_Target *active;
Obj_4_bss_5680_Target **inputRef;
s32 prev;
u8 *alternate;
flA = 0;
flB = 0;
flC = 0;
if (lbl_4_bss_5680->unk_0 >> 31) {
if (lbl_4_bss_5685 == 0) {
goto end; /* matches retail's single early-exit block */
}
}
state = lbl_4_bss_5680;
e = (MenuEntry *)state->unk_3C + state->unk_D;
t8 = (*(u8 (*)[])&lbl_1_bss_9F8) + 8;
if ((((u16 *)t8)[state->unk_C * 10] >> 12) & 1) {
if (e->cur == e->max - 1) {
lbl_4_bss_5680->unk_0 |= 0x20000000;
fn_1_A2D84(0xA9010F00);
} else {
MenuEntry *z;
lbl_4_bss_5680->unk_F = 0;
z = (MenuEntry *)lbl_4_bss_5680->unk_3C;
for (i = 0; i < lbl_4_bss_5680->unk_3B; i++) {
z->cur = z->max - 1;
z++;
}
fn_1_A2D84(0xA9010F00);
}
} else if (((((u16 *)t8)[state->unk_C * 10] >> 8) & 1) && lbl_4_bss_5685 == 0) {
s32 cur = e->cur;
if (cur == e->max - 1) {
lbl_4_bss_5680->unk_0 |= 0x20000000;
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
if (strncmp((char *)q, "\201\347", 2) == 0) {
strncpy((char *)((u8 *)lbl_4_bss_5680 + lbl_4_bss_5680->unk_E * 2 + 0x28), "\201@", 2);
} else {
strncpy((char *)((u8 *)lbl_4_bss_5680 + lbl_4_bss_5680->unk_E * 2 + 0x28), (char *)q, 2);
}
{
Obj_4_bss_5680_Target **advanceRef = &lbl_4_bss_5680;
Obj_4_bss_5680_Target *advance = *advanceRef;
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
lbl_4_bss_5680->unk_F = 0;
}
} else if (((((u16 *)t8) [lbl_4_bss_5680->unk_C * 10] >> 9) & 1) && lbl_4_bss_5685 == 0) {
u32 pos;
state = lbl_4_bss_5680;
pos = state->unk_E;
flB = pos != 0;
if (pos == 7 && state->unk_36 != 0) {
lbl_4_bss_5680->unk_36 = 0;
lbl_4_bss_5680->unk_37 = 0;
} else {
if (pos != 0) {
state->unk_E = state->unk_E - 1;
}
for (i = lbl_4_bss_5680->unk_E; i <= 7; i++) {
if (i < 7) {
u8 *shift = (u8 *)lbl_4_bss_5680 + i * 2;
shift[0x28] = shift[0x2a];
shift = (u8 *)lbl_4_bss_5680 + i * 2;
shift[0x29] = shift[0x2b];
} else {
*((u8 *)lbl_4_bss_5680 + i * 2 + 0x28) = 0;
*((u8 *)lbl_4_bss_5680 + i * 2 + 0x29) = 0;
}
}
}
lbl_4_bss_5680->unk_F = 0;
cnt = (lbl_4_bss_5680->unk_E);
} else {
held = (u16 *)((*(u8 (*)[])&lbl_1_bss_9F8) + 0x10);
if (((held[lbl_4_bss_5680->unk_C * 10] >> 3) & 1) || (((repeat = (u16 *)((*(u8 (*)[])&lbl_1_bss_9F8) + 0x12), repeat[lbl_4_bss_5680->unk_C * 10]) >> 3) & 1)) {
if (lbl_4_bss_5680->unk_D == 0) {
lbl_4_bss_5680->unk_D = lbl_4_bss_5680->unk_3B - 1;
} else {
lbl_4_bss_5680->unk_D = lbl_4_bss_5680->unk_D - 1;
}
lbl_4_bss_5680->unk_F = 0;
} else if (((held[lbl_4_bss_5680->unk_C * 10] >> 2) & 1) || ((repeat[lbl_4_bss_5680->unk_C * 10] >> 2) & 1)) {
if (lbl_4_bss_5680->unk_D == lbl_4_bss_5680->unk_3B - 1) {
lbl_4_bss_5680->unk_D = 0;
} else {
lbl_4_bss_5680->unk_D = lbl_4_bss_5680->unk_D + 1;
}
lbl_4_bss_5680->unk_F = 0;
} else if ((held[lbl_4_bss_5680->unk_C * 10] & 1) || (repeat[lbl_4_bss_5680->unk_C * 10] & 1) || ((repeat[lbl_4_bss_5680->unk_C * 10] >> 8) & 1)) {
if (e->cur == 0) {
e->cur = e->max - 1;
} else {
e->cur = e->cur - 1;
}
lbl_4_bss_5680->unk_F = 0;
} else if (((held[lbl_4_bss_5680->unk_C * 10] >> 1) & 1) || ((repeat[lbl_4_bss_5680->unk_C * 10] >> 1) & 1) || ((repeat[lbl_4_bss_5680->unk_C * 10] >> 9) & 1)) {
if (e->cur == e->max - 1) {
e->cur = 0;
} else {
e->cur = e->cur + 1;
}
lbl_4_bss_5680->unk_F = 0;
} else if ((((u16 *)t8)[lbl_4_bss_5680->unk_C * 10] >> 11) & 1) {
flC = 1;
lbl_4_bss_5680->unk_F = lbl_4_bss_5680->unk_F + 1;
if (lbl_4_bss_5680->unk_F > 2) {
lbl_4_bss_5680->unk_F = 0;
} else if (lbl_4_bss_5680->unk_F == 1) {
alternate = e->p8;
if (alternate == 0) {
flC = 0;
lbl_4_bss_5680->unk_F = 0;
} else if (strncmp((char *)(alternate + e->cur * 2), "\201@", 2) == 0) {
flC = 0;
lbl_4_bss_5680->unk_F = 0;
}
} else if (lbl_4_bss_5680->unk_F == 2) {
alternate = e->pC;
if (alternate == 0) {
lbl_4_bss_5680->unk_F = 0;
} else if (strncmp((char *)(alternate + e->cur * 2), "\201@", 2) == 0) {
lbl_4_bss_5680->unk_F = 0;
}
}
}
}
{
Obj_4_bss_5680_Target **ref = &lbl_4_bss_5680;
/* Observe the shared state pointer independently before this update stage. */
/* WARNING: compiler-diff device, not original code (no-op pointer cast: retail reloads the target pointer; a plain *ref read differs, carried from main) */
Obj_4_bss_5680_Target *before = *(Obj_4_bss_5680_Target **)ref;
Obj_4_bss_5680_Target *after;
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
Obj_4_bss_5680_Target **smoothRef = &lbl_4_bss_5680;
/* Observe the shared state pointer again for the animation update. */
/* WARNING: compiler-diff device, not original code (no-op pointer cast: retail reloads the target pointer; a plain *ref read differs, carried from main) */
Obj_4_bss_5680_Target *phase = *(Obj_4_bss_5680_Target **)smoothRef;
u32 old12;
s32 x;
f64 d;
Obj_4_bss_5680_Target *smooth;
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
if (lbl_4_bss_5680->unk_14 != 0) {
lbl_4_bss_5680->unk_14 = lbl_4_bss_5680->unk_14 - 1;
}
if (lbl_4_bss_5680->unk_15 != 0) {
lbl_4_bss_5680->unk_15 = lbl_4_bss_5680->unk_15 - 1;
}
if (lbl_4_bss_5680->unk_16 != 0) {
lbl_4_bss_5680->unk_16 = lbl_4_bss_5680->unk_16 - 1;
}
if (lbl_4_bss_5680->unk_17 != 0) {
lbl_4_bss_5680->unk_17 = lbl_4_bss_5680->unk_17 - 1;
}
q = (*(u8 (*)[])&lbl_1_bss_9F8) + 0x10;
if (((*(u16 *)(q + lbl_4_bss_5680->unk_C * 20) >> 3) & 1) || ((*(u16 *)(((*(u8 (*)[])&lbl_1_bss_9F8) + 0x12) + lbl_4_bss_5680->unk_C * 20) >> 3) & 1)) {
lbl_4_bss_5680->unk_14 = 8;
}
if (((*(u16 *)(q + lbl_4_bss_5680->unk_C * 20) >> 2) & 1) || ((*(u16 *)(((*(u8 (*)[])&lbl_1_bss_9F8) + 0x12) + lbl_4_bss_5680->unk_C * 20) >> 2) & 1)) {
lbl_4_bss_5680->unk_15 = 8;
}
if ((*(u16 *)(q + lbl_4_bss_5680->unk_C * 20) & 1) || ((repeat = (u16 *)((*(u8 (*)[])&lbl_1_bss_9F8) + 0x12), repeat[lbl_4_bss_5680->unk_C * 10]) & 1) ||
((repeat[lbl_4_bss_5680->unk_C * 10] >> 8) & 1)) {
lbl_4_bss_5680->unk_16 = 8;
}
if (((*(u16 *)(q + lbl_4_bss_5680->unk_C * 20) >> 1) & 1) || (((repeat = (u16 *)((*(u8 (*)[])&lbl_1_bss_9F8) + 0x12), repeat[lbl_4_bss_5680->unk_C * 10]) >> 1) & 1) ||
((repeat[lbl_4_bss_5680->unk_C * 10] >> 9) & 1)) {
lbl_4_bss_5680->unk_17 = 8;
}
if (flA != 0) {
MenuColor v68 = {0, 255, 255, 0};
rp = fn_1_45D0 (lbl_801A6410, 0x12, "name_entry.c", 0xd4);
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
fn_1_435C(lbl_4_bss_5680->unk_8);
fn_1_3F8C("name_entry_fixed_letter", (u32)fn_4_ADF4, (u32)rp, 0xb);
}
if (flB != 0) {
lbl_4_bss_5680->unk_20 |= ((u32)0x80000000 >> cnt);
}
if (flA != 0) {
lbl_4_bss_5680->unk_3A = 12;
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
if (((*(u16 *)(q + lbl_4_bss_5680->unk_C * 20) >> 3) & 1) || (((repeat = (u16 *)((*(u8 (*)[])&lbl_1_bss_9F8) + 0x12), repeat[lbl_4_bss_5680->unk_C * 10]) >> 3) & 1) ||
((*(u16 *)(q + lbl_4_bss_5680->unk_C * 20) >> 2) & 1) || ((repeat[lbl_4_bss_5680->unk_C * 10] >> 2) & 1)) {
fn_1_A2D84(0xA9010000);
}
if ((*(u16 *)(q + lbl_4_bss_5680->unk_C * 20) & 1) || ((repeat = (u16 *)((*(u8 (*)[])&lbl_1_bss_9F8) + 0x12), repeat[lbl_4_bss_5680->unk_C * 10]) & 1) || ((repeat[lbl_4_bss_5680->unk_C * 10] >> 8) & 1) ||
((*(u16 *)(q + lbl_4_bss_5680->unk_C * 20) >> 1) & 1) || ((repeat[lbl_4_bss_5680->unk_C * 10] >> 1) & 1) || ((repeat[lbl_4_bss_5680->unk_C * 10] >> 9) & 1)) {
fn_1_A2D84(0xA9010000);
}
if (lbl_4_bss_5685 != 0) {
fn_1_A2D84(0xA9010200);
lbl_4_bss_5680->unk_0 &= ~0x80000000u;
}
lbl_4_bss_5685 = 0;
end:
return;
}
/* fzgx:end fn_4_BC04 */

/* fzgx:begin fn_4_C768 */
/* Retail colors are both packed words and individual byte channels. */
union fn_4_C768_Clr { u8 channels[4]; u32 w; };
struct fn_4_C768_NameRow {
    u16 index;
    u16 unk_2;
    const char *columns[3];
    const char *label;
};
/* WARNING: compiler-diff device, not original code (optimization_level 3: main compiled this function with -opt level=3, carried from main) */
#pragma optimization_level 3
void fn_4_C768(void) {
FontDrawPacket loc_20;
u8 buf[3];
f32 var_f31;
f32 temp_f0;
f32 temp_f0_2;
f32 temp_f0_3;
f32 temp_f0_4;
f32 temp_f0_5;
u32 var_r28;
u32 var_r27;
u32 var_r27_2;
u32 var_r28_2;
const char *var_r4;
fn_1_49410();
{
u8 c = lbl_4_bss_5680->unk_3A;
struct fn_4_C768_NameRow *base = (struct fn_4_C768_NameRow *)lbl_4_bss_5680->unk_3C + lbl_4_bss_5680->unk_D;
if (c != 0) {
if (c > 9) {
var_f31 = ((0.5) + (f32)(c - 0xA) / (6.0));
} else {
var_f31 = ((0.5) + (f32)(0xA - c) / (20.0));
}
lbl_4_bss_5680->unk_3A--;
} else {
var_f31 = (1.0f);
}
fn_1_134AD4();
if (lbl_1_bss_960 != 3) {
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.image = 0x8F0C;
loc_20.x = (167.0f);
loc_20.y = (38.0f);
loc_20.z = (0.5f);
loc_20.flags = 0xA;
fn_1_4F734(&loc_20);
}
if (((lbl_4_bss_5680->unk_0) >> 0x1FU) == 0) {
if (lbl_801A66B4 == 5) {
fn_1_1380F0("\226\274\221O\202\360\223\374\202\352\202\304\202\255\202\276\202\263\202\242\201B");
} else {
fn_1_1380F0("Please enter your name.  ");
}
} else {
fn_1_1380F0((void *)lbl_1_data_418D4[lbl_801A66B4]);
}
fn_1_13ABA8(0x18000000U);
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.image = 0x8F0A;
loc_20.x = (0.0f);
loc_20.y = (68.0f);
loc_20.z = (10.1999998f);
fn_1_4F734(&loc_20);
loc_20.x = (320.0f);
loc_20.flags |= 0x80000;
fn_1_4F734(&loc_20);
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.image = 0x8F08;
loc_20.x = (140.0f);
loc_20.y = (98.0f);
loc_20.z = (0.189999998f);
fn_1_4F734(&loc_20);
loc_20.x = (320.0f);
loc_20.flags |= 0x80000;
fn_1_4F734(&loc_20);
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.image = 0x8F05;
loc_20.x = (320.0f);
loc_20.y = (178.0f);
loc_20.z = (0.180000007f);
loc_20.flags = 0xA;
fn_1_4F734(&loc_20);
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.image = 0x8F06;
loc_20.x = (320.0f);
loc_20.y = (178.0f);
loc_20.z = (0.170000002f);
loc_20.flags = 0xA;
fn_1_4F734(&loc_20);
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.image = 0x8F0B;
var_r27 = 0;
var_r28 = 0x62;
loc_20.y = (352.0f);
loc_20.z = (0.159999996f);
do {
loc_20.x = var_r28;
fn_1_4F734(&loc_20);
var_r27 += 1;
var_r28 += 0x38;
} while (var_r27 < 8);
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.image = 0x8F07;
loc_20.x = (320.0f);
loc_20.y = (178.0f);
loc_20.z = (0.150000006f);
loc_20.flags = 0xA;
loc_20.rotation_z = (((u32)lbl_4_bss_5680->unk_11 << 24) >> 16);
if ((1.0) != var_f31) {
loc_20.scale_y = var_f31;
loc_20.scale_x = var_f31;
}
fn_1_4F734(&loc_20);
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.x = (320.0f);
loc_20.z = (0.140000001f);
loc_20.flags = 0xA;
loc_20.image = 0x8F0D;
loc_20.y = (110.0f);
{
u8 v = lbl_4_bss_5680->unk_14;
union fn_4_C768_Clr clr_18 = {{0, 0, 0, 0}};
u8 *cb = clr_18.channels;
cb[0] = ((v * 0x10) & 0xF0);
cb[1] = ((v * 0x10) & 0xF0);
cb[2] = ((v * 0x10) & 0xF0);
loc_20.color_add.word = clr_18.w;
temp_f0 = ((1.0) + v / (12.0));
loc_20.scale_y = temp_f0;
loc_20.scale_x = temp_f0;
}
fn_1_4F734(&loc_20);
loc_20.y = (250.0f);
loc_20.image = 0x8F02;
{
u8 v = lbl_4_bss_5680->unk_15;
union fn_4_C768_Clr clr_14 = {{0, 0, 0, 0}};
u8 *cb = clr_14.channels;
cb[0] = ((v * 0x10) & 0xF0);
cb[1] = ((v * 0x10) & 0xF0);
cb[2] = ((v * 0x10) & 0xF0);
loc_20.color_add.word = clr_14.w;
temp_f0_2 = ((1.0) + v / (12.0));
loc_20.scale_y = temp_f0_2;
loc_20.scale_x = temp_f0_2;
}
fn_1_4F734(&loc_20);
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.y = (180.0f);
loc_20.z = (0.140000001f);
loc_20.x = (250.0f);
loc_20.flags = 0xA;
loc_20.image = 0x8F04;
{
u8 v = lbl_4_bss_5680->unk_16;
union fn_4_C768_Clr clr_10 = {{0, 0, 0, 0}};
u8 *cb = clr_10.channels;
cb[0] = ((v * 0x10) & 0xF0);
cb[1] = ((v * 0x10) & 0xF0);
cb[2] = ((v * 0x10) & 0xF0);
loc_20.color_add.word = clr_10.w;
temp_f0_3 = ((1.0) + v / (12.0));
loc_20.scale_y = temp_f0_3;
loc_20.scale_x = temp_f0_3;
}
fn_1_4F734(&loc_20);
loc_20.x = (390.0f);
loc_20.flags |= 0x80000;
{
u8 v = lbl_4_bss_5680->unk_17;
union fn_4_C768_Clr clr_C = {{0, 0, 0, 0}};
u8 *cb = clr_C.channels;
cb[0] = ((v * 0x10) & 0xF0);
cb[1] = ((v * 0x10) & 0xF0);
cb[2] = ((v * 0x10) & 0xF0);
loc_20.color_add.word = clr_C.w;
temp_f0_4 = ((1.0) + v / (12.0));
loc_20.scale_y = temp_f0_4;
loc_20.scale_x = temp_f0_4;
}
fn_1_4F734(&loc_20);
if (lbl_4_bss_5680->unk_E != 7 || lbl_4_bss_5680->unk_36 == 0) {
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.y = (378.0f);
loc_20.image = 0x8F09;
loc_20.z = (0.129999995f);
temp_f0_5 = (1.1 + 0.25 * lbl_8006D188(((lbl_801A66A0 << 8) & 0xFF00)));
loc_20.flags = 0xA;
loc_20.scale_y = temp_f0_5;
loc_20.scale_x = temp_f0_5;
var_r27_2 = lbl_4_bss_5680->unk_E;
var_r28_2 = (var_r27_2 * 0x38) + 0x7C;
while (var_r27_2 < 8) {
loc_20.x = var_r28_2;
fn_1_4F734(&loc_20);
var_r28_2 += 0x38;
var_r27_2 += 1;
}
}
/* WARNING: compiler-diff device, not original code (pointer view of lbl_4_bss_5680, carried from main) */
if ((((*(Obj_4_bss_5680_Target **)(void *)&lbl_4_bss_5680)->unk_0) >> 0x1FU) == 0) {
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.image = 0x8F00;
loc_20.x = (lbl_4_bss_5680->unk_12);
loc_20.y = (346.0f);
loc_20.z = (0.119999997f);
fn_1_4F734(&loc_20);
loc_20.image = 0x8F01;
loc_20.y = (397.0f);
fn_1_4F734(&loc_20);
}
memset(buf, 0, 3);
switch (lbl_4_bss_5680->unk_F) {
case 0:
default:
var_r4 = base->columns[0] + base->index * 2;
break;
case 1:
var_r4 = base->columns[1] + base->index * 2;
break;
case 2:
var_r4 = base->columns[2] + base->index * 2;
break;
}
strncpy((char *)buf, (const char *)var_r4, 2);
fn_1_49410();
fn_1_494DC(0x2A);
fn_1_495C8(9);
fn_1_496FC((321.0f), (178.0f));
{
f64 t = (2.1666666666666665) * var_f31;
fn_1_4955C(t, t);
}
fn_1_4A0D8((const char *)buf);
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.image = 0x8F03;
loc_20.x = (118.0f);
loc_20.y = (118.0f);
loc_20.z = (0.189999998f);
fn_1_4F734(&loc_20);
fn_1_49410();
fn_1_494DC(0x2A);
fn_1_496FC((140.0f), (118.0f));
{
union fn_4_C768_Clr sp8 = {{0, 255, 255, 0}};
fn_1_49514(&sp8);
}
if (lbl_801A66B4 == 5) {
fn_1_4955C((0.625f), (0.625f));
} else {
fn_1_4955C((0.5f), (0.5f));
fn_1_49590((0.300000012f));
fn_1_495B0(0x80000000U);
}
fn_1_4A0D8(base->label);
fn_1_133DBC((void *)1);
}
}
#pragma optimization_level reset
/* fzgx:end fn_4_C768 */

/* fzgx:begin fn_4_D1A8 */
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

/* Creates the letter object for one character of the name. */
static inline void name_entry_add_letter(u8 index, const u8 *ch, MenuColor color) {
    struct fn_8_D630_obj *e;

    e = fn_1_45D0(lbl_801A6410, 0x12, "name_entry.c", 0xD4);
    e->unk_8 = index * 0x38 + 0x7E;
    e->unk_A = 0x17A;
    e->unk_0 = 2;
    e->unk_1 = 0;
    e->unk_4 = e->unk_8;
    e->unk_6 = e->unk_A;
    e->unk_2 = ch[0];
    e->unk_3 = ch[1];
    *(MenuColor *)&e->unk_D = color;
    e->unk_C = index;
    fn_1_3F8C("name_entry_fixed_letter", (u32)fn_4_ADF4, (u32)e, 0xB);
}

/* Gives an empty name the default name and creates its letter objects. */
static void name_entry_set_default_name(void) {
    u8 *ptr;
    u32 i;

    ptr = lbl_4_bss_5680->name;
    if (*ptr == 0) {
        if (lbl_801A66B4 == 5) {
            fn_80083DB0((char *)ptr, "\203G\203t\203[\203\215");
        } else {
            fn_80083DB0((char *)ptr, "\202e\201|\202y\202d\202q\202n");
        }
        {
            MenuColor color = {0x00, 0xFF, 0xFF, 0x00};

            fn_1_435C(lbl_4_bss_5680->unk_8);
            i = 0;
            while (lbl_4_bss_5680->name[i * 2] != 0) {
                name_entry_add_letter(i, &lbl_4_bss_5680->name[i * 2], color);
                i++;
            }
        }
        lbl_4_bss_5680->unk_E = i;
    }
}

/* WARNING: compiler-diff device, not original code (opt_loop_invariants off, carried from main) */
#pragma opt_loop_invariants off
void fn_4_D1A8(u32 arg0, u32 arg1, u8 arg2) {
Node *n;
u32 i;
struct { u32 value; } j; /* WARNING: compiler-diff device, not original code (one-member carrier, carried from main) */
u16 *clear;
lbl_4_bss_5680 = (Obj_4_bss_5680_Target *)fn_1_45D0(lbl_801A6410, 0x40, "name_entry.c", 0x4ef);
fn_800793D4(lbl_4_bss_5680, 0, 0x40);
lbl_4_bss_5680->unk_4 = arg0;
lbl_4_bss_5680->unk_8 = arg1;
fn_1_435C(arg0);
lbl_4_bss_5680->unk_18 = fn_1_3F8C("name_entry_main", (u32)fn_4_BC04, 0, 0xa);
fn_1_47F74(0x8f);
if (lbl_1_bss_960 != 1) {
fn_1_47F74(0x9a);
fn_1_47F74(0x9e);
fn_1_411A4(1);
}
fn_1_435C(arg1);
lbl_4_bss_5680->unk_1C = fn_1_3F8C("name_entry_disp_main", (u32)fn_4_C768, 0, 0xa);
if (lbl_801A66B4 == 5) {
lbl_4_bss_5680->unk_3C = (u32)lbl_4_data_2F78;
lbl_4_bss_5680->unk_3B = 4;
} else {
lbl_4_bss_5680->unk_3C = (u32)lbl_4_data_2FC8;
lbl_4_bss_5680->unk_3B = 4;
}
i = 0;
while (i < lbl_4_bss_5680->unk_3B) {
n = (Node *)fn_1_45D0(lbl_801A6410, 0xc, "name_entry.c", 0x1a5);
fn_800793D4(n, 0, 0xc);
n->unk_0 = i;
switch ((u8)i) {
case 0:
n->unk_4 = 0xb2;
n->unk_8.f = name_entry_glyph_size(0);
break;
case 1:
n->unk_4 = 0x114;
n->unk_8.f = name_entry_glyph_size(1);
break;
case 2:
n->unk_4 = 0x139;
n->unk_8.f = name_entry_glyph_size(2);
break;
case 3:
n->unk_4 = 0x54;
n->unk_8.f = name_entry_glyph_size(1);
break;
}
fn_1_3F8C("name_entry_line", (u32)fn_4_B528, (u32)n, 0xb);
i++;
}
lbl_4_bss_5680->unk_C = arg2;
j.value = 0;
clear = (u16 *)lbl_4_bss_5680->unk_3C;
while (j.value < lbl_4_bss_5680->unk_3B) {
*clear = 0;
j.value++;
}
lbl_4_bss_5680->unk_12 = 0x62;
fn_1_A2D84(0xa9100000U);
lbl_4_bss_5684 = 0;
lbl_4_bss_5685 = 0;
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_4_D1A8 */

/* fzgx:begin fn_4_D420 */
/* WARNING: compiler-diff device, not original code (opt_loop_invariants off, carried from main) */
#pragma opt_loop_invariants off
s32 fn_4_D420(void) {
    s32 bit;
    s32 res;
    u32 i;

    res = 0;
    if ((lbl_4_bss_5680->unk_0 >> 30) & 1) {
        {
            MenuColor color = {0x00, 0xFF, 0xFF, 0x00};

            fn_1_435C(lbl_4_bss_5680->unk_8);
            i = 0;
            while (lbl_4_bss_5680->name[i * 2] != 0) {
                name_entry_add_letter(i, &lbl_4_bss_5680->name[i * 2], color);
                i++;
            }
        }
        {
            u32 flags = lbl_4_bss_5680->unk_0;
            /* Retail reloads the target pointer after reading its flags. */
            /* WARNING: compiler-diff device, not original code (no-op pointer cast on the store target: retail reloads the pointer, carried from main) */
            (*(Obj_4_bss_5680_Target * *)&lbl_4_bss_5680)->unk_0 = flags & ~0x40000000;
        }
    }
    if (lbl_4_bss_5680->unk_0 >> 31) {
        return 1;
    }
    if (((lbl_4_bss_5680->unk_0 >> 29) & 1) || ((lbl_4_bss_5680->unk_0 >> 28) & 1)) {
        fn_1_A2D84(0xA9010100);
        lbl_4_bss_5680->unk_0 &= ~0x20000000;
        lbl_4_bss_5680->unk_0 &= ~0x10000000;
        lbl_4_bss_5680->unk_0 |= 0x80000000;
        if (fn_1_14CEB8((u32)lbl_4_bss_5680->name) != 0) {
            bit = 0;
            lbl_4_bss_5680->unk_0 |= 0x40000000;
            while (lbl_4_bss_5680->name[bit * 2] != 0) {
                lbl_4_bss_5680->unk_20 |= 0x80000000 >> bit;
                bit++;
            }
        }
        name_entry_set_default_name();
        res = 1;
    }
    return res;
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_4_D420 */

/* fzgx:begin fn_4_D760 */
// Initialize the option name-entry state and dispatch the next menu resources.
void fn_4_D760(void) {
    lbl_4_bss_5684 = 1;
    fn_1_435C(lbl_4_bss_5680->unk_4);
    fn_1_426C(lbl_4_bss_5680->unk_18);
    fn_1_A8F78();
    fn_1_48140(143);

    if (lbl_1_bss_960 != 1) {
        if (lbl_1_bss_960 != 3) {
            fn_1_412A0(1);
            fn_1_48140(154);
        }
        fn_1_48140(158);
    }

    fn_1_435C(lbl_4_bss_5680->unk_8);
    fn_1_426C(lbl_4_bss_5680->unk_1C);
    fn_1_46B4(lbl_801A6410, (u32)lbl_4_bss_5680, "name_entry.c", 1378);
    lbl_4_bss_5680 = 0;
}
/* fzgx:end fn_4_D760 */

/* fzgx:begin fn_4_D848 */
// Copies the name-entry data into the active name-entry buffer.
void fn_4_D848(u32 arg0) {
    fn_80083DB0((void *)arg0, lbl_4_bss_5680->name);
}
/* fzgx:end fn_4_D848 */

/* fzgx:begin fn_4_D878 */
void fn_4_D878(void) {
    lbl_4_bss_5685 = 1;
}
/* fzgx:end fn_4_D878 */
