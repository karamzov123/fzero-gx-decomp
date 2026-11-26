#include "types.h"
#include "rel/title/globals.h"
#include "rel/title/operation.h"
extern u16 lbl_1_bss_9F8[];
extern u8 lbl_1_rodata_26F8[0x58];
extern u32 lbl_801A6410;
extern s32 lbl_801A66B4;
extern u8 lbl_8_rodata_408[0x8];
extern u32 lbl_8_rodata_C24;
extern u32 lbl_8_rodata_C28;
extern s32 fn_1_14CEB8(u32);

/* fzgx:begin fn_8_D5F4 */
extern u32 fn_1_14BD74(u32);
extern u32 fn_1_15555C(u32);
extern u32 fn_1_48140(u32);

void fn_8_D5F4(void) {
    u32 t2, t3;
    fn_1_48140(149);
    fn_1_48140(152);
    t2 = fn_1_48140(151);
    t3 = fn_1_15555C(t2);
    fn_1_14BD74(t3);
}
/* fzgx:end fn_8_D5F4 */

/* fzgx:begin fn_8_D630 */
typedef signed short fn_8_D630_s16;
typedef signed long fn_8_D630_s32;

typedef unsigned char fn_8_D630_u8;
typedef unsigned short fn_8_D630_u16;
typedef unsigned long fn_8_D630_u32;

typedef float fn_8_D630_f32;
typedef double fn_8_D630_f64;

typedef unsigned long fn_8_D630_size_t;

/* lbl_4_bss_5680: .bss size 0x4, referenced by 8 functions, shape {'object': 112, 'pointer': 28} */
typedef struct {
fn_8_D630_u32 unk_0; /* 11 loads, 6 stores */
fn_8_D630_u32 unk_4; /* 1 loads, 1 stores */
fn_8_D630_u32 unk_8; /* 4 loads, 1 stores */
fn_8_D630_u8 unk_C; /* 8 loads, 1 stores */
fn_8_D630_u8 unk_D; /* 5 loads, 4 stores */
fn_8_D630_u8 unk_E; /* 10 loads, 3 stores */
fn_8_D630_u8 unk_F; /* 3 loads, 12 stores */
fn_8_D630_u8 unk_10; /* 1 loads, 0 stores */
fn_8_D630_u8 unk_11; /* 2 loads, 1 stores */
fn_8_D630_u16 unk_12; /* 3 loads, 3 stores */
fn_8_D630_u8 unk_14; /* 2 loads, 2 stores */
fn_8_D630_u8 unk_15; /* 2 loads, 2 stores */
fn_8_D630_u8 unk_16; /* 2 loads, 2 stores */
fn_8_D630_u8 unk_17; /* 2 loads, 2 stores */
fn_8_D630_u32 unk_18; /* 1 loads, 1 stores */
fn_8_D630_u32 unk_1C; /* 1 loads, 1 stores */
fn_8_D630_u32 unk_20; /* 3 loads, 2 stores */
fn_8_D630_u8 pad_24[0x4];
fn_8_D630_u8 unk_28; /* 1 loads, 0 stores */
fn_8_D630_u8 pad_29[0xD];
fn_8_D630_u8 unk_36; /* 2 loads, 1 stores */
fn_8_D630_u8 unk_37; /* 0 loads, 1 stores */
fn_8_D630_u8 pad_38[0x2];
fn_8_D630_u8 unk_3A; /* 2 loads, 2 stores */
fn_8_D630_u8 unk_3B; /* 5 loads, 2 stores */
fn_8_D630_u32 unk_3C; /* 4 loads, 2 stores */
} fn_8_D630_Obj_4_bss_5680_Target;



/* lbl_4_data_2F78: .data size 0xA0, referenced by 5 functions, shape {} */
extern fn_8_D630_u8 lbl_8_data_A1E8[0xA0];

/* lbl_4_bss_5684: .bss size 0x1, referenced by 3 functions, shape {'object': 3} */
extern fn_8_D630_u8 lbl_8_bss_554;

extern void fn_1_A2D84(fn_8_D630_u32);

typedef struct fn_8_D630_FontDrawPacket fn_8_D630_FontDrawPacket;
typedef struct fn_8_D630_FontVertex {
fn_8_D630_f32 x, y, z;
} fn_8_D630_FontVertex;
struct fn_8_D630_FontDrawPacket {
fn_8_D630_u32 image;
fn_8_D630_f32 x, y, z;
fn_8_D630_f32 scale_x, scale_y;
fn_8_D630_f32 u0, v0, u1, v1;
fn_8_D630_s16 rotation_z, rotation_y;
fn_8_D630_f32 alpha;
fn_8_D630_u32 flags;
fn_8_D630_f32 depth;
fn_8_D630_u8 color[4], color_add[4];
fn_8_D630_u32 format;
fn_8_D630_u16 width, height;
void* pixels;
fn_8_D630_FontDrawPacket* secondary;
void (*vertex_callback)(fn_8_D630_FontDrawPacket* packet, fn_8_D630_FontVertex* vertices);
fn_8_D630_u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(fn_8_D630_FontDrawPacket* packet);
void fn_1_4EDAC(fn_8_D630_FontDrawPacket* packet, fn_8_D630_f32 width, fn_8_D630_f32 height);
void fn_1_51678(fn_8_D630_FontDrawPacket* packet, fn_8_D630_u32 image, fn_8_D630_s16 x, fn_8_D630_s16 y, fn_8_D630_s16 width, fn_8_D630_s16 height);
void fn_1_517EC(fn_8_D630_FontDrawPacket* packet, fn_8_D630_s16 x, fn_8_D630_s16 y, fn_8_D630_s16 width, fn_8_D630_s16 height,
fn_8_D630_s16 texture_width, fn_8_D630_s16 texture_height);
#pragma section code_type ".fzgxpool"
static const fn_8_D630_u32 fzgx_pool_table1[360] = {0x89709094, 0x00000000, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x824F8250, 0x82518252, 0x82538254, 0x82558256, 0x82578258, 0x81E781E8, 0x00000000, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x00000000, 0x8B4C8D86, 0x00000000, 0x81418142, 0x814C814D, 0x81458143, 0x81448146, 0x81478148, 0x8149817B, 0x817C815E, 0x81818183, 0x8184814F, 0x81518160, 0x81628175, 0x81768169, 0x816A816F, 0x8170816D, 0x816E818F, 0x81908193, 0x81948195, 0x81968197, 0x81E781E8, 0x00000000, 0x82D082E7, 0x82AA82C8, 0x00000000, 0x82A082A2, 0x82A482A6, 0x82A882A9, 0x82AB82AD, 0x82AF82B1, 0x82B382B5, 0x82B782B9, 0x82BB82BD, 0x82BF82C2, 0x82C482C6, 0x82C882C9, 0x82CA82CB, 0x82CC82CD, 0x82D082D3, 0x82D682D9, 0x82DC82DD, 0x82DE82DF, 0x82E082E2, 0x82E482E6, 0x82E782E8, 0x82E982EA, 0x82EB82ED, 0x82EE82EF, 0x82F082F1, 0x82AA82AC, 0x82AE82B0, 0x82B282B4, 0x82B682B8, 0x82BA82BC, 0x82BE82C0, 0x82C382C5, 0x82C782CE, 0x82D182D4, 0x82D782DA, 0x82CF82D2, 0x82D582D8, 0x82DB829F, 0x82A182A3, 0x82A582A7, 0x82C182E1, 0x82E382E5, 0x82EC81E7, 0x81E80000, 0x829F82A1, 0x82A382A5, 0x82A782AA, 0x82AC82AE, 0x82B082B2, 0x82B482B6, 0x82B882BA, 0x82BC82BE, 0x82C082C1, 0x82C582C7, 0x81408140, 0x81408140, 0x814082CE, 0x82D182D4, 0x82D782DA, 0x81408140, 0x81408140, 0x814082E1, 0x82E382E5, 0x81408140, 0x81408140, 0x814082EC, 0x81408140, 0x81408140, 0x82A982AB, 0x82AD82AF, 0x82B182B3, 0x82B582B7, 0x82B982BB, 0x82BD82BF, 0x82C282C4, 0x82C682CF, 0x82D282D5, 0x82D882DB, 0x82CD82D0, 0x82D382D6, 0x82D982A0, 0x82A282A4, 0x82A682A8, 0x82C282E2, 0x82E482E6, 0x82ED8140, 0x81400000, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x814082C3, 0x81408140, 0x81408140, 0x81408140, 0x814082CF, 0x82D282D5, 0x82D882DB, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x82C18140, 0x814082CD, 0x82D082D3, 0x82D682D9, 0x82CE82D1, 0x82D482D7, 0x82DA8140, 0x81408140, 0x81408140, 0x82C38140, 0x81408140, 0x81408140, 0x81400000, 0x834A835E, 0x834A8369, 0x00000000, 0x83418343, 0x83458347, 0x8349834A, 0x834C834E, 0x83508352, 0x83548356, 0x8358835A, 0x835C835E, 0x83608363, 0x83658367, 0x8369836A, 0x836B836C, 0x836D836E, 0x83718374, 0x82D6837A, 0x837D837E, 0x83808381, 0x83828384, 0x83868388, 0x8389838A, 0x838B838C, 0x838D838F, 0x83908391, 0x83928393, 0x8394834B, 0x834D834F, 0x83518353, 0x83558357, 0x8359835B, 0x835D835F, 0x83618364, 0x83668368, 0x836F8372, 0x837582D7, 0x837B8370, 0x83738376, 0x82D8837C, 0x83408342, 0x83448346, 0x83488395, 0x83968362, 0x83838385, 0x8387838E, 0x81E781E8, 0x00000000, 0x83408342, 0x83448346, 0x8348834B, 0x834D834F, 0x83518353, 0x83558357, 0x8359835B, 0x835D835F, 0x83618362, 0x83668368, 0x81408140, 0x81408140, 0x8140836F, 0x83728375, 0x82D7837B, 0x81408140, 0x81408140, 0x81408383, 0x83858387, 0x81408140, 0x81408140, 0x8140838E, 0x81408140, 0x81408140, 0x8345834A, 0x834C834E, 0x83508352, 0x83548356, 0x8358835A, 0x835C835E, 0x83608363, 0x83658367, 0x83708373, 0x837682D8, 0x837C836E, 0x83718374, 0x82D6837A, 0x83418343, 0x83458347, 0x8349834A, 0x83508363, 0x83848386, 0x8388838F, 0x81408140, 0x00000000, 0x81408140, 0x83948140, 0x81408395, 0x81408140, 0x83968140, 0x81408140, 0x81408140, 0x81408140, 0x81408364, 0x81408140, 0x81408140, 0x81408140, 0x81408370, 0x83738376, 0x82D8837C, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x83448395, 0x81408140, 0x83968140, 0x81408140, 0x81408140, 0x81408140, 0x81408362, 0x81408140, 0x836E8371, 0x837482D6, 0x837A836F, 0x83728375, 0x82D7837B, 0x81408140, 0x83948140, 0x8140834B, 0x83518364, 0x81408140, 0x81408140, 0x81408140, 0x00000000}; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const fn_8_D630_u32 *volatile cp; cp = fzgx_pool_table1; } /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
volatile fn_8_D630_f32 s; volatile fn_8_D630_f64 d; /* fzgx-allow: S2 pool primer sinks */
s = 225.43910217285156f;
}
static const fn_8_D630_u32 fzgx_pool_table3[65] = {0x74616C20, 0x4C657474, 0x65727300, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x81E781E8, 0x00000000, 0x536D616C, 0x6C204C65, 0x74746572, 0x73000000, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x81E781E8, 0x00000000, 0x5369676E, 0x73000000, 0x81438144, 0x81488149, 0x817B817C, 0x815E815F, 0x81818183, 0x81848146, 0x8147814C, 0x814D814F, 0x81518162, 0x8169816A, 0x816D816E, 0x816F8170, 0x81908193, 0x81948195, 0x81968197, 0x81E781E8, 0x00000000, 0x4E756D62, 0x65727300, 0x824F8250, 0x82518252, 0x82538254, 0x82558256, 0x82578258, 0x81E781E8, 0x00000000}; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const fn_8_D630_u32 *volatile cp; cp = fzgx_pool_table3; } /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
volatile fn_8_D630_f32 s; volatile fn_8_D630_f64 d; /* fzgx-allow: S2 pool primer sinks */
d = 0.21;
d = 1.6666666666666667;
d = 0.5;
s = 48.0f;
s = 0.25f;
d = 1.0;
s = 0.12999999523162842f;
s = 0.0f;
d = 1.5;
d = 2.0;
s = 1.6666666269302368f;
s = 0.0625f;
d = 4503601774854144.0;
d = 4503599627370496.0;
}
#pragma section code_type ".text"
struct fn_8_D630_rodata {
fn_8_D630_u8 pad_0[0x6A8];
fn_8_D630_f64 unk_6A8;
fn_8_D630_f64 unk_6B0;
fn_8_D630_f64 unk_6B8;
fn_8_D630_f32 unk_6C0;
fn_8_D630_f32 unk_6C4;
fn_8_D630_f64 unk_6C8;
fn_8_D630_f32 unk_6D0;
fn_8_D630_u8 pad_6D4[0x4];
fn_8_D630_f64 unk_6D8;
fn_8_D630_f64 unk_6E0;
fn_8_D630_f32 unk_6E8;
fn_8_D630_f32 unk_6EC;
fn_8_D630_f64 unk_6F0;
fn_8_D630_f64 unk_6F8;
};

#pragma pack(1)
struct fn_8_D630_obj {
fn_8_D630_u8 unk_0;
fn_8_D630_u8 unk_1;
fn_8_D630_u8 unk_2;
fn_8_D630_u8 unk_3;
fn_8_D630_u16 unk_4;
fn_8_D630_u16 unk_6;
fn_8_D630_u16 unk_8;
fn_8_D630_u16 unk_A;
fn_8_D630_u8 unk_C;
fn_8_D630_u32 unk_D;
};
#pragma pack()










extern void fn_1_46B4(fn_8_D630_u32, fn_8_D630_u32, const char *, int);
extern fn_8_D630_u32 fn_1_4060(void);
extern fn_8_D630_s32 strncmp(const char *, const char *, fn_8_D630_size_t);
extern char * strncpy(char *, const char *, fn_8_D630_size_t);
extern void fn_1_49410(void);
extern void fn_1_494DC(fn_8_D630_s16);
extern void fn_1_495C8(fn_8_D630_u8);
extern void fn_1_49514(fn_8_D630_u32 *);
extern void fn_1_496FC(fn_8_D630_f32, fn_8_D630_f32);
extern void fn_1_4955C(fn_8_D630_f32, fn_8_D630_f32);
extern void fn_1_495A0(fn_8_D630_f32);
extern void fn_1_A2D84(fn_8_D630_u32);
extern int fn_1_4F734(fn_8_D630_FontDrawPacket *);
extern void fn_1_4A0D8(const char *);
#pragma pool_data on
#pragma opt_common_subs off
static inline fn_8_D630_s32 fn_4_ADF4_sign(fn_8_D630_s32 x) { return x < 0 ? -1 : x > 0; }
void fn_8_D630(struct fn_8_D630_obj *arg0)
{
struct fn_8_D630_obj *p;
struct fn_8_D630_rodata *r;
fn_8_D630_u8 *d;
fn_8_D630_u8 name[4];
fn_8_D630_u8 ph[4];
fn_8_D630_u32 col1;
fn_8_D630_u32 col2;
fn_8_D630_u32 col3;
fn_8_D630_u32 col4;
fn_8_D630_FontDrawPacket loc_20;
fn_8_D630_f32 f;
fn_8_D630_f32 scale;
fn_8_D630_u32 t;
fn_8_D630_u32 n2;
fn_8_D630_s32 e;
p = arg0;
r = &(*(struct fn_8_D630_rodata *)&lbl_8_rodata_408);
d = (*(fn_8_D630_u8 (*)[])&lbl_8_data_A1E8);
if ((*(fn_8_D630_u8 *)&lbl_8_bss_554) != 0) {
fn_1_46B4((*(fn_8_D630_u32 *)&lbl_801A6410), (fn_8_D630_u32)p, (const char *)(d + 0xA0), 0xFB);
fn_1_4060();
return;
}
n2 = (p->unk_C + 1) & 0x1F;
t = (*(fn_8_D630_Obj_4_bss_5680_Target * *)&lbl_8_bss_550)->unk_20;
if (__rlwnm(t, n2, 31, 31) != 0) {
if (p->unk_0 != 1 || p->unk_1 != 0x18) {
p->unk_0 = 4;
p->unk_1 = 0x10;
(*(fn_8_D630_Obj_4_bss_5680_Target * *)&lbl_8_bss_550)->unk_20 &= ~(0x80000000U >> p->unk_C);
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
{
fn_8_D630_u16 c4 = p->unk_4;
fn_8_D630_s32 t4 = (fn_8_D630_s32)p->unk_8 - (fn_8_D630_s32)c4;
fn_8_D630_f64 dd = 0.21 * (fn_8_D630_f64)t4;
if ((fn_8_D630_s32)dd != 0) {
p->unk_4 = (fn_8_D630_u16)(fn_8_D630_s32)((fn_8_D630_f64)(fn_8_D630_u32)c4 + dd);
} else {
e = fn_4_ADF4_sign(t4);
/* Retail rereads the position after selecting the one-step adjustment. */
p->unk_4 = *(volatile fn_8_D630_u16 *)&p->unk_4 + e;
}
{
fn_8_D630_u16 c6 = p->unk_6;
fn_8_D630_s32 t6 = (fn_8_D630_s32)p->unk_A - (fn_8_D630_s32)c6;
dd = 0.21 * (fn_8_D630_f64)t6;
if ((fn_8_D630_s32)dd != 0) {
p->unk_6 = (fn_8_D630_u16)(fn_8_D630_s32)((fn_8_D630_f64)(fn_8_D630_u32)c6 + dd);
} else {
e = fn_4_ADF4_sign(t6);
/* Retail rereads the position after selecting the one-step adjustment. */
p->unk_6 = *(volatile fn_8_D630_u16 *)&p->unk_6 + e;
}
}
}
col1 = p->unk_D;
fn_1_49514(&col1);
fn_1_496FC((fn_8_D630_f32)p->unk_4, (fn_8_D630_f32)p->unk_6);
{
fn_8_D630_f64 scale_d = 1.6666666666666667 * (0.5 + (fn_8_D630_f32)(0x18 - p->unk_1) / 48.0f);
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
*(fn_8_D630_u32 *)ph = p->unk_D;
{
fn_8_D630_f32 quarter = 0.25f;
f = (fn_8_D630_f32)p->unk_1 * quarter;
{
ph[0] += (255 - ph[0]) * f;
ph[1] += (255 - ph[1]) * f;
ph[2] += (255 - ph[2]) * f;
}
}
col2 = *(fn_8_D630_u32 *)ph;
fn_1_49514(&col2);
fn_1_496FC((fn_8_D630_f32)p->unk_4, (fn_8_D630_f32)p->unk_6);
{
fn_8_D630_f64 scale_d = 1.6666666666666667 * (1.0 + 0.5 * (fn_8_D630_f64)f);
fn_1_4955C(scale_d, scale_d);
}
loc_20 = *(fn_8_D630_FontDrawPacket *)(&(*(fn_8_D630_u32 *)&lbl_1_rodata_26F8));
loc_20.image = 0x8F09;
loc_20.x = (fn_8_D630_f32)p->unk_4;
loc_20.y = (fn_8_D630_f32)p->unk_6;
loc_20.z = 0.13f;
loc_20.scale_x = loc_20.scale_y = (1.5 + 2.0 * (fn_8_D630_f64)f);
loc_20.flags = 0xA;
fn_1_4F734((fn_8_D630_FontDrawPacket *)&loc_20);
if (p->unk_1 == 1) {
p->unk_0 = 3;
if (strncmp((const char *)p + 2, (const char *)(d + 0xB4), 2) == 0) {
strncpy((char *)p + 2, (const char *)(d + 0xB0), 2);
name[0] = p->unk_2;
name[1] = p->unk_3;
}
}
break;
case 3:
col3 = p->unk_D;
fn_1_49514(&col3);
fn_1_496FC((fn_8_D630_f32)p->unk_4, (fn_8_D630_f32)p->unk_6);
fn_1_4955C(1.6666666f, 1.6666666f);
break;
case 4:
if (p->unk_1 == 0) {
fn_1_46B4((*(fn_8_D630_u32 *)&lbl_801A6410), (fn_8_D630_u32)p, (const char *)(d + 0xA0), 0x169);
fn_1_4060();
return;
}
col4 = p->unk_D;
fn_1_49514(&col4);
fn_1_496FC((fn_8_D630_f32)p->unk_4, (fn_8_D630_f32)p->unk_6);
{
fn_8_D630_f64 scale_d = 1.6666666666666667 * (1.0 + 0.5 * (fn_8_D630_f32)(0x10 - p->unk_1));
fn_1_4955C(scale_d, scale_d);
}
{
fn_8_D630_f32 alpha = (fn_8_D630_f32)p->unk_1;
alpha *= 0.0625f;
fn_1_495A0(alpha);
}
break;
}
fn_1_4A0D8((const char *)name);
p->unk_1--;
}
#pragma opt_common_subs reset
/* fzgx:end fn_8_D630 */

/* fzgx:begin fn_8_DD64 */
typedef signed char fn_8_DD64_s8;
typedef signed short fn_8_DD64_s16;
typedef signed long fn_8_DD64_s32;

typedef unsigned char fn_8_DD64_u8;
typedef unsigned short fn_8_DD64_u16;
typedef unsigned long fn_8_DD64_u32;

typedef float fn_8_DD64_f32;
typedef double fn_8_DD64_f64;

typedef unsigned long fn_8_DD64_size_t;
typedef struct fn_8_DD64_FontDrawPacket fn_8_DD64_FontDrawPacket;
typedef struct fn_8_DD64_FontVertex {
fn_8_DD64_f32 x, y, z;
} fn_8_DD64_FontVertex;
struct fn_8_DD64_FontDrawPacket {
fn_8_DD64_u32 image;
fn_8_DD64_f32 x, y, z;
fn_8_DD64_f32 scale_x, scale_y;
fn_8_DD64_f32 u0, v0, u1, v1;
fn_8_DD64_s16 rotation_z, rotation_y;
fn_8_DD64_f32 alpha;
fn_8_DD64_u32 flags;
fn_8_DD64_f32 depth;
fn_8_DD64_u8 color[4], color_add[4];
fn_8_DD64_u32 format;
fn_8_DD64_u16 width, height;
void* pixels;
fn_8_DD64_FontDrawPacket* secondary;
void (*vertex_callback)(fn_8_DD64_FontDrawPacket* packet, fn_8_DD64_FontVertex* vertices);
fn_8_DD64_u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(fn_8_DD64_FontDrawPacket* packet);
void fn_1_4EDAC(fn_8_DD64_FontDrawPacket* packet, fn_8_DD64_f32 width, fn_8_DD64_f32 height);
void fn_1_51678(fn_8_DD64_FontDrawPacket* packet, fn_8_DD64_u32 image, fn_8_DD64_s16 x, fn_8_DD64_s16 y, fn_8_DD64_s16 width, fn_8_DD64_s16 height);
void fn_1_517EC(fn_8_DD64_FontDrawPacket* packet, fn_8_DD64_s16 x, fn_8_DD64_s16 y, fn_8_DD64_s16 width, fn_8_DD64_s16 height,
fn_8_DD64_s16 texture_width, fn_8_DD64_s16 texture_height);

/* lbl_4_bss_5680: .bss size 0x4, referenced by 8 functions, shape {'object': 112, 'pointer': 28} */
typedef struct {
fn_8_DD64_u32 unk_0; /* 11 loads, 6 stores */
fn_8_DD64_u32 unk_4; /* 1 loads, 1 stores */
fn_8_DD64_u32 unk_8; /* 4 loads, 1 stores */
fn_8_DD64_u8 unk_C; /* 8 loads, 1 stores */
fn_8_DD64_u8 unk_D; /* 5 loads, 4 stores */
fn_8_DD64_u8 unk_E; /* 10 loads, 3 stores */
fn_8_DD64_u8 unk_F; /* 3 loads, 12 stores */
fn_8_DD64_u8 unk_10; /* 1 loads, 0 stores */
fn_8_DD64_u8 unk_11; /* 2 loads, 1 stores */
fn_8_DD64_u16 unk_12; /* 3 loads, 3 stores */
fn_8_DD64_u8 unk_14; /* 2 loads, 2 stores */
fn_8_DD64_u8 unk_15; /* 2 loads, 2 stores */
fn_8_DD64_u8 unk_16; /* 2 loads, 2 stores */
fn_8_DD64_u8 unk_17; /* 2 loads, 2 stores */
fn_8_DD64_u32 unk_18; /* 1 loads, 1 stores */
fn_8_DD64_u32 unk_1C; /* 1 loads, 1 stores */
fn_8_DD64_u32 unk_20; /* 3 loads, 2 stores */
fn_8_DD64_u8 pad_24[0x4];
fn_8_DD64_u8 unk_28; /* 1 loads, 0 stores */
fn_8_DD64_u8 pad_29[0xD];
fn_8_DD64_u8 unk_36; /* 2 loads, 1 stores */
fn_8_DD64_u8 unk_37; /* 0 loads, 1 stores */
fn_8_DD64_u8 pad_38[0x2];
fn_8_DD64_u8 unk_3A; /* 2 loads, 2 stores */
fn_8_DD64_u8 unk_3B; /* 5 loads, 2 stores */
fn_8_DD64_u32 unk_3C; /* 4 loads, 2 stores */
} fn_8_DD64_Obj_4_bss_5680_Target;



/* lbl_4_data_2F78: .data size 0xA0, referenced by 5 functions, shape {} */
extern fn_8_DD64_u8 lbl_8_data_A1E8[0xA0];

/* lbl_4_bss_5684: .bss size 0x1, referenced by 3 functions, shape {'object': 3} */
extern fn_8_DD64_u8 lbl_8_bss_554;

void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(fn_8_DD64_FontDrawPacket* packet);
void fn_1_4EDAC(fn_8_DD64_FontDrawPacket* packet, fn_8_DD64_f32 width, fn_8_DD64_f32 height);
void fn_1_51678(fn_8_DD64_FontDrawPacket* packet, fn_8_DD64_u32 image, fn_8_DD64_s16 x, fn_8_DD64_s16 y, fn_8_DD64_s16 width, fn_8_DD64_s16 height);
void fn_1_517EC(fn_8_DD64_FontDrawPacket* packet, fn_8_DD64_s16 x, fn_8_DD64_s16 y, fn_8_DD64_s16 width, fn_8_DD64_s16 height,
fn_8_DD64_s16 texture_width, fn_8_DD64_s16 texture_height);
struct fn_8_DD64_lbl_801A63D0 {
fn_8_DD64_u32 unk_0;
};
struct fn_8_DD64_lbl_8_rodata_408 {
fn_8_DD64_u8 pad_0[0x6F0];
fn_8_DD64_f64 unk_6F0;
fn_8_DD64_f64 unk_6F8;
fn_8_DD64_f32 unk_700;
fn_8_DD64_f32 unk_704;
fn_8_DD64_f32 unk_708;
fn_8_DD64_u32 unk_70C;
fn_8_DD64_u32 unk_710;
fn_8_DD64_u32 unk_714;
fn_8_DD64_u32 unk_718;
fn_8_DD64_u32 unk_71C;
fn_8_DD64_u32 unk_720;
fn_8_DD64_f32 unk_724;
fn_8_DD64_f32 unk_728;
fn_8_DD64_u8 pad_72C[0x4];
fn_8_DD64_f64 unk_730;
fn_8_DD64_f64 unk_738;
fn_8_DD64_f32 unk_740;
fn_8_DD64_u8 pad_744[0x4];
fn_8_DD64_f64 unk_748;
fn_8_DD64_f32 unk_750;
fn_8_DD64_f32 unk_754;
};
extern char * strncat(char *, const char *, fn_8_DD64_size_t);
extern char * strcat(char *, const char *);
extern char * strncpy(char *, const char *, fn_8_DD64_size_t);
extern int fn_1_4F734(fn_8_DD64_FontDrawPacket *);
extern int sprintf(char *, const char *, ...);
extern fn_8_DD64_size_t strlen(const char *);
extern struct fn_8_DD64_lbl_801A63D0 lbl_801A63D0;


extern fn_8_DD64_u32 fn_1_4060(void);
extern fn_8_DD64_u32 fn_1_49410(void);
typedef struct Sig_fn_800081C8_Color Sig_fn_800081C8_Color;
extern fn_8_DD64_u32 fn_800081C8(Sig_fn_800081C8_Color, Sig_fn_800081C8_Color, fn_8_DD64_f32);
extern fn_8_DD64_u32 fn_800793D4(fn_8_DD64_u8 *, fn_8_DD64_u32, void *);
extern fn_8_DD64_u32 strcpy(fn_8_DD64_u32, fn_8_DD64_u32);


extern fn_8_DD64_u8 * strstr(fn_8_DD64_u8 *, const fn_8_DD64_u8 *);






extern void fn_1_46B4(fn_8_DD64_u32, fn_8_DD64_u32, const char *, int);
extern void fn_1_494DC(fn_8_DD64_s16);
extern void fn_1_49514(Sig_fn_800081C8_Color);
extern void fn_1_4954C(fn_8_DD64_f32);
extern void fn_1_4955C(fn_8_DD64_f32, fn_8_DD64_f32);
extern void fn_1_495C8(fn_8_DD64_u8);
extern void fn_1_4966C(fn_8_DD64_f32, fn_8_DD64_f32);
extern void fn_1_496FC(fn_8_DD64_f32, fn_8_DD64_f32);
extern void fn_1_4A0D8(const char *);
struct Sig_fn_800081C8_Color { fn_8_DD64_u8 r, g, b, a; };
#pragma opt_common_subs off
#pragma opt_lifetimes off
#pragma opt_loop_invariants off
extern int __abs(int);
#pragma force_active on
static const fn_8_DD64_u32 fzgx_pool_table_0[] = {2305855636u,0u,2187362913u,2187493987u,2187625061u,2187756135u,2187887209u,2188018283u,2188149357u,2188280431u,2188411505u,2188542579u,2188673653u,2188804727u,2188935801u,2189525634u,2189656708u,2189787782u,2189918856u,2190049930u,2190181004u,2190312078u,2190443152u,2190574226u,2190705300u,2190836374u,2190967448u,2191098522u,2186248784u,2186379858u,2186510932u,2186642006u,2186773080u,2179432936u,0u,2189525634u,2189656708u,2189787782u,2189918856u,2190049930u,2190181004u,2190312078u,2190443152u,2190574226u,2190705300u,2190836374u,2190967448u,2191098522u,2187362913u,2187493987u,2187625061u,2187756135u,2187887209u,2188018283u,2188149357u,2188280431u,2188411505u,2188542579u,2188673653u,2188804727u,2188935801u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,0u,2337049990u,0u,2168553794u,2169274701u,2168815939u,2168750406u,2168947016u,2169078139u,2172420446u,2172748163u,2172944719u,2169602400u,2170716533u,2172027241u,2171240815u,2171634029u,2171502991u,2173731219u,2173993365u,2174124439u,2179432936u,0u,2194703079u,2192212680u,0u,2191557282u,2191819430u,2192081577u,2192278189u,2192540337u,2192802485u,2193064633u,2193326781u,2193588930u,2193916614u,2194178761u,2194309835u,2194440909u,2194703059u,2195096281u,2195489501u,2195620575u,2195751650u,2196013798u,2196210408u,2196341482u,2196472557u,2196669167u,2196800241u,2192212652u,2192474800u,2192736948u,2192999096u,2193261244u,2193523392u,2193851077u,2194113230u,2194768596u,2195161818u,2194637522u,2195030744u,2195423903u,2191622819u,2191884967u,2193720033u,2195948261u,2196537831u,2179465216u,2191491745u,2191753893u,2192016042u,2192343726u,2192605874u,2192868022u,2193130170u,2193392318u,2193654465u,2193982151u,2168488256u,2168488256u,2168488654u,2194768596u,2195161818u,2168488256u,2168488256u,2168488673u,2195948261u,2168488256u,2168488256u,2168488684u,2168488256u,2168488256u,2192147115u,2192409263u,2192671411u,2192933559u,2193195707u,2193457855u,2193785540u,2194047695u,2194834133u,2195227355u,2194506448u,2194899670u,2195292832u,2191688356u,2191950504u,2193785570u,2196013798u,2196603200u,2168455168u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488643u,2168488256u,2168488256u,2168488256u,2168488655u,2194834133u,2195227355u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2193719616u,2168488653u,2194703059u,2195096281u,2194571985u,2194965207u,2195358016u,2168488256u,2168488256u,2193850688u,2168488256u,2168488256u,2168455168u,2202698590u,2202698601u,0u,2202108739u,2202370887u,2202633034u,2202829646u,2203091794u,2203353942u,2203616090u,2203878238u,2204140387u,2204468071u,2204730218u,2204861292u,2204992366u,2205254516u,2195096442u,2206040958u,2206237569u,2206368644u,2206630792u,2206827402u,2206958476u,2207089551u,2207286161u,2207417235u,2207548235u,2202895183u,2203157331u,2203419479u,2203681627u,2203943775u,2204205924u,2204533608u,2205123442u,2205516503u,2205909872u,2205385590u,2195227516u,2202043202u,2202305350u,2202567573u,2207679330u,2206434181u,2206696334u,2179432936u,0u,2202043202u,2202305350u,2202567499u,2202895183u,2203157331u,2203419479u,2203681627u,2203943775u,2204205922u,2204533608u,2168488256u,2168488256u,2168488815u,2205320053u,2195161979u,2168488256u,2168488256u,2168488835u,2206565255u,2168488256u,2168488256u,2168488846u,2168488256u,2168488256u,2202370890u,2202829646u,2203091794u,2203353942u,2203616090u,2203878238u,2204140387u,2204468071u,2205188979u,2205582040u,2205975406u,2205254516u,2195096442u,2202108739u,2202370887u,2202633034u,2203091811u,2206499718u,2206761871u,2168488256u,0u,2168488256u,2207547712u,2168488853u,2168488256u,2207678784u,2168488256u,2168488256u,2168488256u,2168488804u,2168488256u,2168488256u,2168488256u,2168488816u,2205385590u,2195227516u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2202305429u,2168488256u,2207678784u,2168488256u,2168488256u,2168488256u,2168488802u,2168488256u,2205057905u,2205450966u,2205844335u,2205320053u,2195161979u,2168488256u,2207547712u,2168488779u,2203157348u,2168488256u,2168488256u,2168488256u,0u,1130459241u,1952541728u,1281717364u,1701999360u,2187362913u,2187493987u,2187625061u,2187756135u,2187887209u,2188018283u,2188149357u,2188280431u,2188411505u,2188542579u,2188673653u,2188804727u,2188935801u,2179432936u,0u,1399677292u,1814056037u,1953785202u,1929379840u,2189525634u,2189656708u,2189787782u,2189918856u,2190049930u,2190181004u,2190312078u,2190443152u,2190574226u,2190705300u,2190836374u,2190967448u,2191098522u,2179432936u,0u,1399416686u,1929379840u,2168684868u,2169012553u,2172354940u,2170454367u,2172748163u,2172944710u,2168947020u,2169340239u,2169602402u,2171175274u,2171437422u,2171568496u,2173731219u,2173993365u,2174124439u,2179432936u,0u,1316318562u,1701999360u,2186248784u,2186379858u,2186510932u,2186642006u,2186773080u,2179432936u,0u,1070260551u,2920577761u,1073392298u,2863311531u,1071644672u,0u,1111490560u,1048576000u,1072693248u,0u,1040522936u,0u,1073217536u,0u,1073741824u,0u,1070945621u,1031798784u};
#pragma force_active reset
#pragma push
#pragma section code_type ".fzgxpool"
static fn_8_DD64_f64 fzgx_signed_double(fn_8_DD64_s32 value) { return (fn_8_DD64_f64)value; }
static fn_8_DD64_f64 fzgx_unsigned_double(fn_8_DD64_u32 value) { return (fn_8_DD64_f64)value; }
static fn_8_DD64_f32 fzgx_glyph_size(fn_8_DD64_s32 index) {
switch(index) {
case 0:return 32.0f;
case 1:return 24.0f;
default:return 18.0f;
}
}
#pragma force_active reset
#pragma pop
void fn_8_DD64(fn_8_DD64_u32 arg0) {
fn_8_DD64_u8 *p_lbl_8_data_A1E8;
struct fn_8_DD64_lbl_8_rodata_408 *p_lbl_8_rodata_408;
fn_8_DD64_u8 *p_lbl_1_rodata_26F8;
fn_8_DD64_u32 v0;
fn_8_DD64_s32 v1;
fn_8_DD64_s32 v2;
fn_8_DD64_s32 state_value;
fn_8_DD64_s32 cursor_next;
fn_8_DD64_s32 v3;
fn_8_DD64_u32 v4;
fn_8_DD64_f32 v5;
fn_8_DD64_f64 v6;
fn_8_DD64_f32 v7;
struct OptionNameEntry { fn_8_DD64_u16 cursor, length; char *chars; fn_8_DD64_u8 pad[12]; } *v8;
fn_8_DD64_u32 v9;
fn_8_DD64_s32 v10;
fn_8_DD64_u32 v12;
fn_8_DD64_u32 v13;
fn_8_DD64_u32 v14;
fn_8_DD64_s32 v15;
fn_8_DD64_f32 v16;
fn_8_DD64_u16 v17;
fn_8_DD64_f64 v18;
fn_8_DD64_u32 v19;
fn_8_DD64_u8 * v20;
fn_8_DD64_u32 v21;
fn_8_DD64_u32 v22;
fn_8_DD64_f64 v23;
fn_8_DD64_f32 v24;
fn_8_DD64_f64 v25;
fn_8_DD64_f32 v26;
fn_8_DD64_f32 v27;
struct { fn_8_DD64_u32 a[22]; } loc_18;
Sig_fn_800081C8_Color loc_14;
Sig_fn_800081C8_Color loc_10;
Sig_fn_800081C8_Color loc_C;
fn_8_DD64_u32 loc_8;
fn_8_DD64_u32 lab_t0;
fn_8_DD64_u32 lab_t1;
p_lbl_8_data_A1E8 = (*(fn_8_DD64_u8 (*)[])&lbl_8_data_A1E8);
p_lbl_8_rodata_408 = &(*(struct fn_8_DD64_lbl_8_rodata_408 *)&lbl_8_rodata_408);
fn_800793D4((fn_8_DD64_u8 *)lbl_801A63D0.unk_0, 0, (void *)1024);
v0 = lbl_801A63D0.unk_0;
if ((*(fn_8_DD64_u8 *)&lbl_8_bss_554) != 0) {
v2 = (fn_8_DD64_s32)(arg0);
v1 = (fn_8_DD64_u32)&(*(fn_8_DD64_u32 *)&lbl_801A6410);
v3 = (fn_8_DD64_u32)((fn_8_DD64_u8 *)(fn_8_DD64_u32)p_lbl_8_data_A1E8 + 160);
v1 = *(fn_8_DD64_u32 *)((fn_8_DD64_u8 *)v1);
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
v1 = (*(fn_8_DD64_Obj_4_bss_5680_Target * *)&lbl_8_bss_550)->unk_3C;
v8 = (struct OptionNameEntry *)v1 + *(fn_8_DD64_u8 *)arg0;
v19 = v8->cursor;
v3 = (v19 - 10);
v1 = (v19 + 11);
if (v3 >= 0 && (fn_8_DD64_s32)(v19 + 11) <= (fn_8_DD64_s32)v8->length) {
v2 = (fn_8_DD64_s32)((fn_8_DD64_u32)v8->chars);
v1 = v0;
v9 = (v3 << 1);
v3 = 42;
{ fn_8_DD64_s32 __reg_value_v2 = (v2 + v9); v2 = __reg_value_v2; }
v1 = (fn_8_DD64_u32)strncpy((char *)v1, (const char *)v2, v3);
} else if (v19 < 10) {
v10 = v19 - 10;
v10 = v8->length + v10;
if (v10 < 0) {
v2 = (fn_8_DD64_s32)((fn_8_DD64_u32)v8->chars);
v1 = v0;
{ fn_8_DD64_s32 __reg_value_v2 = (v2 + (v19 << 1)); v2 = __reg_value_v2; }
lab_t0 = v1;
lab_t1 = v2;
v1 = strcpy(lab_t0, lab_t1);
{ fn_8_DD64_s32 __reg_value_v2 = (fn_8_DD64_u32)v8->chars; v2 = __reg_value_v2; }
v1 = v0;
v1 = (fn_8_DD64_u32)strcat((char *)v1, (const char *)v2);
{ fn_8_DD64_s32 __reg_value_v2 = (fn_8_DD64_u32)v8->chars; v2 = __reg_value_v2; }
v1 = v0;
v3 = ((v10 + 10) << 1);
v1 = (fn_8_DD64_u32)strncat((char *)v1, (const char *)v2, v3);
} else {
v2 = (fn_8_DD64_s32)((fn_8_DD64_u32)v8->chars);
v1 = v0;
{ fn_8_DD64_s32 __reg_value_v2 = (v2 + (v10 << 1)); v2 = __reg_value_v2; }
lab_t0 = v1;
lab_t1 = v2;
v1 = strcpy(lab_t0, lab_t1);
v1 = v8->cursor;
v10 = (v1 + 11);
if ((fn_8_DD64_s32)v10 > (fn_8_DD64_s32)v8->length) {
v2 = (fn_8_DD64_s32)((fn_8_DD64_u32)v8->chars);
v1 = v0;
v1 = (fn_8_DD64_u32)strcat((char *)v1, (const char *)v2);
v1 = v0;
{ fn_8_DD64_s32 __reg_value_v2 = (fn_8_DD64_u32)v8->chars; v2 = __reg_value_v2; }
v3 = ((v10 - v8->length) << 1);
v1 = (fn_8_DD64_u32)strncat((char *)v1, (const char *)v2, v3);
} else {
v2 = (fn_8_DD64_s32)((fn_8_DD64_u32)v8->chars);
v1 = v0;
v3 = (v10 << 1);
v1 = (fn_8_DD64_u32)strncat((char *)v1, (const char *)v2, v3);
}
}
} else {
v2 = (fn_8_DD64_s32)((fn_8_DD64_u32)v8->chars);
v1 = v0;
{ fn_8_DD64_s32 __reg_value_v2 = (v2 + (v3 << 1)); v2 = __reg_value_v2; }
lab_t0 = v1;
lab_t1 = v2;
v1 = strcpy(lab_t0, lab_t1);
{ fn_8_DD64_s32 __reg_value_v2 = v8->cursor; v2 = __reg_value_v2; }
v1 = v0;
v3 = v8->length;
v12 = (v2 + 11);
{ fn_8_DD64_s32 __reg_value_v2 = (fn_8_DD64_u32)v8->chars; v2 = __reg_value_v2; }
v3 = ((v12 - v3) << 1);
v1 = (fn_8_DD64_u32)strncat((char *)v1, (const char *)v2, v3);
}
v2 = (fn_8_DD64_s32)(*(fn_8_DD64_u8 *)((fn_8_DD64_u8 *)arg0));
v1 = (fn_8_DD64_u32)(*(fn_8_DD64_Obj_4_bss_5680_Target * *)&lbl_8_bss_550);
if ((fn_8_DD64_u32)v2 == *(fn_8_DD64_u8 *)((fn_8_DD64_u8 *)v1 + 13)) {
fn_8_DD64_u32 b14;
v2 = (fn_8_DD64_s32)((v0 + 6));
v1 = (fn_8_DD64_u32)&lbl_801A63D0;
v3 = 14;
v1 = *(fn_8_DD64_u32 *)((fn_8_DD64_u8 *)v1);
v10 = (v1 + 44);
b14 = (v1 + 88);
v1 = v10;
v1 = (fn_8_DD64_u32)strncpy((char *)v1, (const char *)v2, v3);
v1 = b14;
{ fn_8_DD64_s32 __reg_value_v2 = (v0 + 22); v2 = __reg_value_v2; }
v3 = 14;
v1 = (fn_8_DD64_u32)strncpy((char *)v1, (const char *)v2, v3);
v1 = v0;
v3 = v10;
v4 = b14;
{ fn_8_DD64_s32 __reg_value_v2 = (fn_8_DD64_u32)((fn_8_DD64_u8 *)(fn_8_DD64_u32)p_lbl_8_data_A1E8 + 184); v2 = __reg_value_v2; }
v1 = sprintf((char *)v1, (const char *)(fn_8_DD64_u32)v2, v3, v4);
}
v1 = (fn_8_DD64_u32)(*(fn_8_DD64_Obj_4_bss_5680_Target * *)&lbl_8_bss_550);
v1 = *(fn_8_DD64_u8 *)((fn_8_DD64_u8 *)v1 + 13);
v1 = (*(fn_8_DD64_u8 *)((fn_8_DD64_u8 *)arg0) - v1);
if (v1 < 0) {
v1 += 4;
}
switch (v1) {
case 0:
v15 = 178;
v16 = fzgx_glyph_size(0);
{ Sig_fn_800081C8_Color color0 = {255, 255, 255, 0}; loc_14 = color0; }
break;
case 1:
v15 = 276;
v16 = fzgx_glyph_size(1);
{ Sig_fn_800081C8_Color color1 = {0, 255, 255, 0}; loc_14 = color1; }
break;
case 2:
v15 = 313;
v16 = fzgx_glyph_size(2);
{ Sig_fn_800081C8_Color color2 = {0, 255, 255, 0}; loc_14 = color2; }
break;
case 3:
v15 = 84;
v16 = fzgx_glyph_size(1);
{ Sig_fn_800081C8_Color color3 = {0, 255, 255, 0}; loc_14 = color3; }
}
state_value = *(fn_8_DD64_u16 *)((fn_8_DD64_u8 *)arg0 + 4);
v3 = v15 - state_value;
v6 = 0.2 * fzgx_signed_double(v3);
if ((fn_8_DD64_s32)v6 != 0) {
*(fn_8_DD64_u16 *)((fn_8_DD64_u8 *)arg0 + 4) = (fn_8_DD64_s32)((fn_8_DD64_f64)(fn_8_DD64_u32)state_value + v6);
} else {
if (v3 < 0) {
v1 = -1;
} else {
v1 = v3 > 0;
}
*(fn_8_DD64_u16 *)((fn_8_DD64_u8 *)arg0 + 4) += v1;
}
v7 = *(fn_8_DD64_f32 *)((fn_8_DD64_u8 *)arg0 + 8);
v6 = 0.2;
*(fn_8_DD64_f32 *)((fn_8_DD64_u8 *)arg0 + 8) = v7 + v6 * (v16 - v7);
v1 = *(fn_8_DD64_u8 *)((fn_8_DD64_u8 *)arg0 + 2);
v13 = v8->cursor;
state_value = v1 + 1;
if (state_value == (fn_8_DD64_s32)v13 || --v1 > (fn_8_DD64_s32)v13) {
*(fn_8_DD64_u8 *)((fn_8_DD64_u8 *)arg0 + 1) = 36;
} else if (v1 == (fn_8_DD64_s32)v13 || state_value < (fn_8_DD64_s32)v13) {
*(fn_8_DD64_s8 *)((fn_8_DD64_u8 *)arg0 + 1) = -36;
}
v2 = (fn_8_DD64_s8)*(fn_8_DD64_u8 *)((fn_8_DD64_u8 *)arg0 + 1);
v3 = -v2;
v6 = 0.2 * fzgx_signed_double(v3);
if ((fn_8_DD64_s32)v6 != 0) {
*(fn_8_DD64_u8 *)((fn_8_DD64_u8 *)arg0 + 1) = (fn_8_DD64_s32)((fn_8_DD64_f64)v2 + v6);
} else {
if (v3 < 0) {
v1 = -1;
} else {
v1 = v3 > 0;
}
*(fn_8_DD64_u8 *)((fn_8_DD64_u8 *)arg0 + 1) += v1;
}
v1 = v0;
v2 = (fn_8_DD64_u32)(p_lbl_8_data_A1E8 + 196);
*(fn_8_DD64_u8 *)((fn_8_DD64_u8 *)arg0 + 2) = v8->cursor;
v1 = (fn_8_DD64_u32)strstr((fn_8_DD64_u8 *)v1, (const fn_8_DD64_u8 *)v2);
p_lbl_1_rodata_26F8 = (*(fn_8_DD64_u8 (*)[])&lbl_1_rodata_26F8);
v15 = 0x10000 - 28914;
v20 = (fn_8_DD64_u8 *)v1;
v24 = 10.1f;
v25 = 24.0;
while (v20 != 0) {
v1 = strlen((const char *)v0);
state_value = v20 - (fn_8_DD64_u8 *)v0;
v3 = v1 - 1;
v1 = (fn_8_DD64_u32)state_value >> 31;
v1 = v1 + state_value;
state_value = (fn_8_DD64_u32)v3 >> 2;
v1 >>= 1;
v3 = (fn_8_DD64_u32)&loc_14;
v2 = v1 - state_value;
state_value = (fn_8_DD64_u32)p_lbl_1_rodata_26F8 - 4;
for (v21 = 11; v21 != 0; v21--) {
v1 = *(fn_8_DD64_u32 *)((fn_8_DD64_u8 *)state_value + 4);
v22 = *(fn_8_DD64_u32 *)((fn_8_DD64_u8 *)state_value + 8);
state_value += 8;
*(fn_8_DD64_u32 *)((fn_8_DD64_u8 *)v3 + 4) = v1;
*(fn_8_DD64_u32 *)((fn_8_DD64_u8 *)v3 + 8) = v22;
v3 += 8;
}
loc_18.a[0] = v15;
v3 = *(fn_8_DD64_u8 *)((fn_8_DD64_u8 *)arg0 + 1);
v1 = (fn_8_DD64_s8)v3;
v26 = (fn_8_DD64_f32)(fn_8_DD64_s32)v2 * *(fn_8_DD64_f32 *)((fn_8_DD64_u8 *)arg0 + 8);
v5 = (fn_8_DD64_f32)(v1 + 320);
*(fn_8_DD64_f32 *)((fn_8_DD64_u8 *)&loc_18 + 4) = v5 + v26;
if (__abs((fn_8_DD64_s32)v2) > 0) {
v3 = 1;
if ((fn_8_DD64_s32)v2 < 0) v3 = -1;
state_value = (fn_8_DD64_s32)v2 >> 31;
v1 = state_value ^ (fn_8_DD64_s32)v2;
v1 -= state_value;
v6 = 12.0;
v7 = *(fn_8_DD64_f32 *)((fn_8_DD64_u8 *)&loc_18 + 4);
*(fn_8_DD64_f32 *)((fn_8_DD64_u8 *)&loc_18 + 4) = v7 + v6 * (v3 * v1);
}
*(fn_8_DD64_f32 *)((fn_8_DD64_u8 *)&loc_18 + 8) = (fn_8_DD64_f32)(fn_8_DD64_u32)*(fn_8_DD64_u16 *)((fn_8_DD64_u8 *)arg0 + 4);
*(fn_8_DD64_f32 *)((fn_8_DD64_u8 *)&loc_18 + 12) = v24;
loc_18.a[12] = 10;
v5 = 1.0f;
v27 = *(fn_8_DD64_f32 *)((fn_8_DD64_u8 *)arg0 + 8) / v25;
*(fn_8_DD64_f32 *)((fn_8_DD64_u8 *)&loc_18 + 20) = v27;
*(fn_8_DD64_f32 *)((fn_8_DD64_u8 *)&loc_18 + 16) = v27;
{
Sig_fn_800081C8_Color black = {0, 0, 0, 255};
Sig_fn_800081C8_Color white = {255, 255, 255, 255};
loc_10 = black;
loc_C = white;
v1 = fn_800081C8(loc_10, loc_C, v5);
}
loc_18.a[14] = v1;
fn_1_4F734((fn_8_DD64_FontDrawPacket *)&loc_18);
v20 = strstr(v20 + 2, p_lbl_8_data_A1E8 + 196);
}
v2 = (fn_8_DD64_s8)*(fn_8_DD64_u8 *)((fn_8_DD64_u8 *)arg0 + 1);
v2 += 320;
v5 = (fn_8_DD64_f32)v2;
v6 = (fn_8_DD64_f32)(fn_8_DD64_u32)*(fn_8_DD64_u16 *)((fn_8_DD64_u8 *)arg0 + 4);
fn_1_496FC(v5, v6);
v18 = *(fn_8_DD64_f32 *)((fn_8_DD64_u8 *)arg0 + 8) / 24.0;
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
#pragma opt_common_subs reset
/* fzgx:end fn_8_DD64 */

/* fzgx:begin fn_8_E440 */
typedef signed char fn_8_E440_s8;

typedef signed long fn_8_E440_s32;

typedef unsigned char fn_8_E440_u8;
typedef unsigned short fn_8_E440_u16;
typedef unsigned long fn_8_E440_u32;

typedef double fn_8_E440_f64;

typedef unsigned long fn_8_E440_size_t;

/* lbl_10_bss_55CD8: .bss size 0x4, 5 refs from sel.c */
typedef struct {
fn_8_E440_u32 unk_0; /* 12 loads, 7 stores */
fn_8_E440_u32 unk_4; /* 1 loads, 1 stores */
fn_8_E440_u32 unk_8; /* 5 loads, 1 stores */
fn_8_E440_u8 unk_C; /* 8 loads, 1 stores */
fn_8_E440_u8 unk_D; /* 5 loads, 4 stores */
fn_8_E440_u8 unk_E; /* 10 loads, 4 stores */
fn_8_E440_u8 unk_F; /* 3 loads, 12 stores */
fn_8_E440_u8 unk_10; /* 1 loads, 0 stores */
fn_8_E440_u8 unk_11; /* 2 loads, 1 stores */
fn_8_E440_u16 unk_12; /* 3 loads, 3 stores */
fn_8_E440_u8 unk_14; /* 2 loads, 2 stores */
fn_8_E440_u8 unk_15; /* 2 loads, 2 stores */
fn_8_E440_u8 unk_16; /* 2 loads, 2 stores */
fn_8_E440_u8 unk_17; /* 2 loads, 2 stores */
fn_8_E440_u32 unk_18; /* 1 loads, 1 stores */
fn_8_E440_u32 unk_1C; /* 1 loads, 1 stores */
fn_8_E440_u32 unk_20; /* 3 loads, 2 stores */
fn_8_E440_u8 pad_24[0x4];
fn_8_E440_u8 unk_28; /* 2 loads, 0 stores */
fn_8_E440_u8 pad_29[0xD];
fn_8_E440_u8 unk_36; /* 2 loads, 1 stores */
fn_8_E440_u8 unk_37; /* 0 loads, 1 stores */
fn_8_E440_u8 pad_38[0x2];
fn_8_E440_u8 unk_3A; /* 2 loads, 2 stores */
fn_8_E440_u8 unk_3B; /* 5 loads, 2 stores */
fn_8_E440_u32 unk_3C; /* 4 loads, 2 stores */
} Obj_10_bss_55CD8_Target;





extern fn_8_E440_u8 lbl_8_bss_555;
extern char *strncpy(char *, const char *, fn_8_E440_size_t);
extern fn_8_E440_s32 strncmp(const char *, const char *, fn_8_E440_size_t);

extern const fn_8_E440_f64 lbl_8_rodata_B68;
extern const fn_8_E440_u32 lbl_8_rodata_B60;
extern void *fn_1_45D0(fn_8_E440_u32, fn_8_E440_u32, fn_8_E440_u8 *, fn_8_E440_u32);
extern void fn_1_435C(fn_8_E440_u32);
extern fn_8_E440_s32 fn_1_3F8C(fn_8_E440_u32, fn_8_E440_u32, fn_8_E440_u32, fn_8_E440_u32);
extern void fn_8_D630(void);


extern fn_8_E440_u8 lbl_1_bss_A48[];


extern void fn_1_A2D84(fn_8_E440_u32);
typedef struct { fn_8_E440_u8 r, g, b, a; } MenuColor;
typedef struct {
fn_8_E440_u16 cur;
fn_8_E440_u16 max;
fn_8_E440_u8 *p4;
fn_8_E440_u8 *p8;
fn_8_E440_u8 *pC;
fn_8_E440_u32 pad;
} MenuEntry;
#pragma opt_common_subs off
void fn_8_E440(void) {
fn_8_E440_u8 *p;
void *rp;
fn_8_E440_u8 *q;
fn_8_E440_u32 cnt;
fn_8_E440_s32 flA;
fn_8_E440_s32 flB;
fn_8_E440_s32 flC;
fn_8_E440_u8 buf[2];
fn_8_E440_s32 i;
fn_8_E440_u16 *repeat;
fn_8_E440_u16 *held;
Obj_10_bss_55CD8_Target *state;
fn_8_E440_u8 *t8;
MenuEntry *e;
fn_8_E440_s32 inputIndex;
Obj_10_bss_55CD8_Target *active;
Obj_10_bss_55CD8_Target **inputRef;
fn_8_E440_s32 prev;
fn_8_E440_u8 *alternate;
MenuColor v68;
p = (*(fn_8_E440_u8 (*)[0xA0])&lbl_8_data_A1E8);
flA = 0;
flB = 0;
flC = 0;
if ((*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_0 >> 31) {
if (lbl_8_bss_555 == 0) {
goto end; /* matches retail's single early-exit block */
}
}
state = (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550);
e = (MenuEntry *)state->unk_3C + state->unk_D;
t8 = (*(fn_8_E440_u8 (*)[])&lbl_1_bss_9F8) + 8;
if ((((fn_8_E440_u16 *)t8)[state->unk_C * 10] >> 12) & 1) {
if (e->cur == e->max - 1) {
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_0 |= 0x20000000;
fn_1_A2D84(0xA9010F00);
} else {
MenuEntry *z;
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_F = 0;
z = (MenuEntry *)(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_3C;
for (i = 0; i < (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_3B; i++) {
z->cur = z->max - 1;
z++;
}
fn_1_A2D84(0xA9010F00);
}
} else if (((((fn_8_E440_u16 *)t8)[state->unk_C * 10] >> 8) & 1) && lbl_8_bss_555 == 0) {
fn_8_E440_s32 cur = e->cur;
if (cur == e->max - 1) {
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_0 |= 0x20000000;
fn_1_A2D84(0xA9010F00);
} else {
cnt = (fn_8_E440_u8)(state->unk_E);
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
if (strncmp((char *)q, (char *)(p + 0xb4), 2) == 0) {
strncpy((char *)((fn_8_E440_u8 *)(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550) + (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_E * 2 + 0x28), (char *)(p + 0xb0), 2);
} else {
strncpy((char *)((fn_8_E440_u8 *)(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550) + (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_E * 2 + 0x28), (char *)q, 2);
}
{
Obj_10_bss_55CD8_Target **advanceRef = &(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550);
Obj_10_bss_55CD8_Target *advance = *advanceRef;
if (advance->unk_E < 7) {
advance->unk_E = advance->unk_E + 1;
} else {
MenuEntry *z;
fn_8_E440_s32 j;
z = (MenuEntry *)advance->unk_3C;
for (j = 0; j < (*advanceRef)->unk_3B; j++) {
z->cur = z->max - 1;
z++;
}
}
}
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_F = 0;
}
} else if (((((fn_8_E440_u16 *)t8) [(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 10] >> 9) & 1) && lbl_8_bss_555 == 0) {
fn_8_E440_u32 pos;
state = (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550);
pos = state->unk_E;
flB = pos != 0;
if (pos == 7 && state->unk_36 != 0) {
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_36 = 0;
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_37 = 0;
} else {
if (pos != 0) {
state->unk_E = state->unk_E - 1;
}
for (i = (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_E; i <= 7; i++) {
if (i < 7) {
fn_8_E440_u8 *shift = (fn_8_E440_u8 *)(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550) + i * 2;
shift[0x28] = shift[0x2a];
shift = (fn_8_E440_u8 *)(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550) + i * 2;
shift[0x29] = shift[0x2b];
} else {
*((fn_8_E440_u8 *)(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550) + i * 2 + 0x28) = 0;
*((fn_8_E440_u8 *)(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550) + i * 2 + 0x29) = 0;
}
}
}
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_F = 0;
cnt = (fn_8_E440_u8)((*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_E);
} else {
held = (fn_8_E440_u16 *)((*(fn_8_E440_u8 (*)[])&lbl_1_bss_9F8) + 0x10);
if (((held[(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 10] >> 3) & 1) || (((repeat = (fn_8_E440_u16 *)((*(fn_8_E440_u8 (*)[])&lbl_1_bss_9F8) + 0x12), repeat[(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 10]) >> 3) & 1)) {
if ((*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_D == 0) {
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_D = (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_3B - 1;
} else {
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_D = (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_D - 1;
}
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_F = 0;
} else if (((held[(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 10] >> 2) & 1) || ((repeat[(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 10] >> 2) & 1)) {
if ((*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_D == (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_3B - 1) {
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_D = 0;
} else {
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_D = (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_D + 1;
}
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_F = 0;
} else if ((held[(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 10] & 1) || (repeat[(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 10] & 1) || ((repeat[(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 10] >> 8) & 1)) {
if (e->cur == 0) {
e->cur = e->max - 1;
} else {
e->cur = e->cur - 1;
}
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_F = 0;
} else if (((held[(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 10] >> 1) & 1) || ((repeat[(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 10] >> 1) & 1) || ((repeat[(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 10] >> 9) & 1)) {
if (e->cur == e->max - 1) {
e->cur = 0;
} else {
e->cur = e->cur + 1;
}
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_F = 0;
} else if ((((fn_8_E440_u16 *)t8)[(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 10] >> 11) & 1) {
flC = 1;
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_F = (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_F + 1;
if ((*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_F > 2) {
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_F = 0;
} else if ((*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_F == 1) {
alternate = e->p8;
if (alternate == 0) {
flC = 0;
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_F = 0;
} else if (strncmp((char *)(alternate + e->cur * 2), (char *)(p + 0xb0), 2) == 0) {
flC = 0;
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_F = 0;
}
} else if ((*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_F == 2) {
alternate = e->pC;
if (alternate == 0) {
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_F = 0;
} else if (strncmp((char *)(alternate + e->cur * 2), (char *)(p + 0xb0), 2) == 0) {
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_F = 0;
}
}
}
}
{
Obj_10_bss_55CD8_Target **ref = &(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550);
/* Observe the shared state pointer independently before this update stage. */
Obj_10_bss_55CD8_Target *before = *(Obj_10_bss_55CD8_Target **)ref;
Obj_10_bss_55CD8_Target *after;
fn_8_E440_s32 prev;
prev = *(fn_8_E440_s8 *)&before->unk_10;
before->unk_10 = ((fn_8_E440_s8 *)lbl_1_bss_A48)[before->unk_C << 4] >> 2;
after = *ref;
if (*(fn_8_E440_s8 *)&after->unk_10 == 0) {
fn_8_E440_u8 t = lbl_1_bss_A48[after->unk_C << 4];
if ((fn_8_E440_s8)t > 0) {
after->unk_10 = 1;
} else if ((fn_8_E440_s8)t < 0) {
*(fn_8_E440_s8 *)&after->unk_10 = -1;
} else {
*(fn_8_E440_s8 *)&after->unk_10 = prev < 0 ? -1 : 1;
}
}
}
{
Obj_10_bss_55CD8_Target **smoothRef = &(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550);
/* Observe the shared state pointer again for the animation update. */
Obj_10_bss_55CD8_Target *phase = *(Obj_10_bss_55CD8_Target **)smoothRef;
fn_8_E440_u32 old12;
fn_8_E440_s32 x;
fn_8_E440_f64 d;
Obj_10_bss_55CD8_Target *smooth;
phase->unk_11 = phase->unk_11 - phase->unk_10;
smooth = *smoothRef;
old12 = smooth->unk_12;
x = smooth->unk_E * 56 + 98 - old12;
d = lbl_8_rodata_B68 * (fn_8_E440_f64)x;
if ((fn_8_E440_s32)d != 0) {
smooth->unk_12 = (fn_8_E440_s32)((fn_8_E440_f64)old12 + d);
} else {
fn_8_E440_s32 step;
if (x < 0) {
step = -1;
} else {
step = x > 0;
}
smooth->unk_12 += step;
}
}
if ((*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_14 != 0) {
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_14 = (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_14 - 1;
}
if ((*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_15 != 0) {
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_15 = (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_15 - 1;
}
if ((*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_16 != 0) {
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_16 = (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_16 - 1;
}
if ((*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_17 != 0) {
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_17 = (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_17 - 1;
}
q = (*(fn_8_E440_u8 (*)[])&lbl_1_bss_9F8) + 0x10;
if (((*(fn_8_E440_u16 *)(q + (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 20) >> 3) & 1) || ((*(fn_8_E440_u16 *)((fn_8_E440_u32)((*(fn_8_E440_u8 (*)[])&lbl_1_bss_9F8) + 0x12) + (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 20) >> 3) & 1)) {
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_14 = 8;
}
if (((*(fn_8_E440_u16 *)(q + (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 20) >> 2) & 1) || ((*(fn_8_E440_u16 *)((fn_8_E440_u32)((*(fn_8_E440_u8 (*)[])&lbl_1_bss_9F8) + 0x12) + (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 20) >> 2) & 1)) {
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_15 = 8;
}
if ((*(fn_8_E440_u16 *)(q + (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 20) & 1) || ((repeat = (fn_8_E440_u16 *)((*(fn_8_E440_u8 (*)[])&lbl_1_bss_9F8) + 0x12), repeat[(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 10]) & 1) ||
((repeat[(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 10] >> 8) & 1)) {
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_16 = 8;
}
if (((*(fn_8_E440_u16 *)(q + (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 20) >> 1) & 1) || (((repeat = (fn_8_E440_u16 *)((*(fn_8_E440_u8 (*)[])&lbl_1_bss_9F8) + 0x12), repeat[(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 10]) >> 1) & 1) ||
((repeat[(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 10] >> 9) & 1)) {
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_17 = 8;
}
if (flA != 0) {
v68 = *(const MenuColor *)&lbl_8_rodata_B60;
rp = fn_1_45D0 (*(fn_8_E440_u32 *)&(*(fn_8_E440_u32 *)&lbl_801A6410), 0x12, p + 0xa0, 0xd4);
*(fn_8_E440_u16 *)((fn_8_E440_u8 *)rp + 8) = (fn_8_E440_u16)((fn_8_E440_u32)(cnt & 0xFF) * 56 + 0x7e);
*(fn_8_E440_u16 *)((fn_8_E440_u8 *)rp + 10) = 0x17a;
*(fn_8_E440_u8 *)((fn_8_E440_u8 *)rp + 0) = 1;
*(fn_8_E440_u8 *)((fn_8_E440_u8 *)rp + 1) = 0x18;
*(fn_8_E440_u16 *)((fn_8_E440_u8 *)rp + 4) = 0x140;
*(fn_8_E440_u16 *)((fn_8_E440_u8 *)rp + 6) = 0xb2;
*(fn_8_E440_u8 *)((fn_8_E440_u8 *)rp + 2) = buf[0];
*(fn_8_E440_u8 *)((fn_8_E440_u8 *)rp + 3) = buf[1];
*(MenuColor *)((fn_8_E440_u8 *)rp + 0xd) = v68;
*(fn_8_E440_u8 *)((fn_8_E440_u8 *)rp + 0xc) = cnt;
fn_1_435C((*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_8);
fn_1_3F8C((fn_8_E440_u32)(p + 0xc8), (fn_8_E440_u32)fn_8_D630, (fn_8_E440_u32)rp, 0xb);
}
if (flB != 0) {
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_20 |= ((fn_8_E440_u32)0x80000000 >> cnt);
}
if (flA != 0) {
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_3A = 12;
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
if (((*(fn_8_E440_u16 *)(q + (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 20) >> 3) & 1) || (((repeat = (fn_8_E440_u16 *)((*(fn_8_E440_u8 (*)[])&lbl_1_bss_9F8) + 0x12), repeat[(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 10]) >> 3) & 1) ||
((*(fn_8_E440_u16 *)(q + (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 20) >> 2) & 1) || ((repeat[(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 10] >> 2) & 1)) {
fn_1_A2D84(0xA9010000);
}
if ((*(fn_8_E440_u16 *)(q + (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 20) & 1) || ((repeat = (fn_8_E440_u16 *)((*(fn_8_E440_u8 (*)[])&lbl_1_bss_9F8) + 0x12), repeat[(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 10]) & 1) || ((repeat[(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 10] >> 8) & 1) ||
((*(fn_8_E440_u16 *)(q + (*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 20) >> 1) & 1) || ((repeat[(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 10] >> 1) & 1) || ((repeat[(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_C * 10] >> 9) & 1)) {
fn_1_A2D84(0xA9010000);
}
if (lbl_8_bss_555 != 0) {
fn_1_A2D84(0xA9010200);
(*(Obj_10_bss_55CD8_Target * *)&lbl_8_bss_550)->unk_0 &= ~0x80000000u;
}
lbl_8_bss_555 = 0;
end:
return;
}
#pragma opt_common_subs reset
/* fzgx:end fn_8_E440 */

/* fzgx:begin fn_8_EFA4 noprologue */
#include "types.h"
#include "rel/title/globals.h"
#include "rel/title/name_entry.h"
extern s16 lbl_1_bss_960;
extern void fn_1_4A0D8(const char *);
void fn_1_4AE0C(const char* format, ...);
extern void fn_1_1380F0(void *);
extern void fn_1_133DBC(void *);
extern u32 fn_1_412A0(u32);
extern u32 fn_1_426C(u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_46B4(u32, u32, u32, u32);
extern u32 fn_1_48140(u32);
extern u32 fn_1_A8F78(void);
extern u8 lbl_8_bss_554;
extern u32 strcpy(u32, u32);
extern u8 lbl_8_bss_555;

typedef signed char fn_8_EFA4_s8;
typedef signed short fn_8_EFA4_s16;
typedef signed long fn_8_EFA4_s32;
typedef signed long long fn_8_EFA4_s64;
typedef unsigned char fn_8_EFA4_u8;
typedef unsigned short fn_8_EFA4_u16;
typedef unsigned long fn_8_EFA4_u32;
typedef unsigned long long fn_8_EFA4_u64;
typedef float fn_8_EFA4_f32;
typedef double fn_8_EFA4_f64;
#pragma section code_type ".fzgxpool"
static const fn_8_EFA4_u32 fzgx_pool_table1[360] = {0x89709094, 0x00000000, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x824F8250, 0x82518252, 0x82538254, 0x82558256, 0x82578258, 0x81E781E8, 0x00000000, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x00000000, 0x8B4C8D86, 0x00000000, 0x81418142, 0x814C814D, 0x81458143, 0x81448146, 0x81478148, 0x8149817B, 0x817C815E, 0x81818183, 0x8184814F, 0x81518160, 0x81628175, 0x81768169, 0x816A816F, 0x8170816D, 0x816E818F, 0x81908193, 0x81948195, 0x81968197, 0x81E781E8, 0x00000000, 0x82D082E7, 0x82AA82C8, 0x00000000, 0x82A082A2, 0x82A482A6, 0x82A882A9, 0x82AB82AD, 0x82AF82B1, 0x82B382B5, 0x82B782B9, 0x82BB82BD, 0x82BF82C2, 0x82C482C6, 0x82C882C9, 0x82CA82CB, 0x82CC82CD, 0x82D082D3, 0x82D682D9, 0x82DC82DD, 0x82DE82DF, 0x82E082E2, 0x82E482E6, 0x82E782E8, 0x82E982EA, 0x82EB82ED, 0x82EE82EF, 0x82F082F1, 0x82AA82AC, 0x82AE82B0, 0x82B282B4, 0x82B682B8, 0x82BA82BC, 0x82BE82C0, 0x82C382C5, 0x82C782CE, 0x82D182D4, 0x82D782DA, 0x82CF82D2, 0x82D582D8, 0x82DB829F, 0x82A182A3, 0x82A582A7, 0x82C182E1, 0x82E382E5, 0x82EC81E7, 0x81E80000, 0x829F82A1, 0x82A382A5, 0x82A782AA, 0x82AC82AE, 0x82B082B2, 0x82B482B6, 0x82B882BA, 0x82BC82BE, 0x82C082C1, 0x82C582C7, 0x81408140, 0x81408140, 0x814082CE, 0x82D182D4, 0x82D782DA, 0x81408140, 0x81408140, 0x814082E1, 0x82E382E5, 0x81408140, 0x81408140, 0x814082EC, 0x81408140, 0x81408140, 0x82A982AB, 0x82AD82AF, 0x82B182B3, 0x82B582B7, 0x82B982BB, 0x82BD82BF, 0x82C282C4, 0x82C682CF, 0x82D282D5, 0x82D882DB, 0x82CD82D0, 0x82D382D6, 0x82D982A0, 0x82A282A4, 0x82A682A8, 0x82C282E2, 0x82E482E6, 0x82ED8140, 0x81400000, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x814082C3, 0x81408140, 0x81408140, 0x81408140, 0x814082CF, 0x82D282D5, 0x82D882DB, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x82C18140, 0x814082CD, 0x82D082D3, 0x82D682D9, 0x82CE82D1, 0x82D482D7, 0x82DA8140, 0x81408140, 0x81408140, 0x82C38140, 0x81408140, 0x81408140, 0x81400000, 0x834A835E, 0x834A8369, 0x00000000, 0x83418343, 0x83458347, 0x8349834A, 0x834C834E, 0x83508352, 0x83548356, 0x8358835A, 0x835C835E, 0x83608363, 0x83658367, 0x8369836A, 0x836B836C, 0x836D836E, 0x83718374, 0x82D6837A, 0x837D837E, 0x83808381, 0x83828384, 0x83868388, 0x8389838A, 0x838B838C, 0x838D838F, 0x83908391, 0x83928393, 0x8394834B, 0x834D834F, 0x83518353, 0x83558357, 0x8359835B, 0x835D835F, 0x83618364, 0x83668368, 0x836F8372, 0x837582D7, 0x837B8370, 0x83738376, 0x82D8837C, 0x83408342, 0x83448346, 0x83488395, 0x83968362, 0x83838385, 0x8387838E, 0x81E781E8, 0x00000000, 0x83408342, 0x83448346, 0x8348834B, 0x834D834F, 0x83518353, 0x83558357, 0x8359835B, 0x835D835F, 0x83618362, 0x83668368, 0x81408140, 0x81408140, 0x8140836F, 0x83728375, 0x82D7837B, 0x81408140, 0x81408140, 0x81408383, 0x83858387, 0x81408140, 0x81408140, 0x8140838E, 0x81408140, 0x81408140, 0x8345834A, 0x834C834E, 0x83508352, 0x83548356, 0x8358835A, 0x835C835E, 0x83608363, 0x83658367, 0x83708373, 0x837682D8, 0x837C836E, 0x83718374, 0x82D6837A, 0x83418343, 0x83458347, 0x8349834A, 0x83508363, 0x83848386, 0x8388838F, 0x81408140, 0x00000000, 0x81408140, 0x83948140, 0x81408395, 0x81408140, 0x83968140, 0x81408140, 0x81408140, 0x81408140, 0x81408364, 0x81408140, 0x81408140, 0x81408140, 0x81408370, 0x83738376, 0x82D8837C, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x83448395, 0x81408140, 0x83968140, 0x81408140, 0x81408140, 0x81408140, 0x81408362, 0x81408140, 0x836E8371, 0x837482D6, 0x837A836F, 0x83728375, 0x82D7837B, 0x81408140, 0x83948140, 0x8140834B, 0x83518364, 0x81408140, 0x81408140, 0x81408140, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const fn_8_EFA4_u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile fn_8_EFA4_f32 s; volatile fn_8_EFA4_f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 225.43910217285156f;
}
static const fn_8_EFA4_u32 fzgx_pool_table3[65] = {0x74616C20, 0x4C657474, 0x65727300, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x81E781E8, 0x00000000, 0x536D616C, 0x6C204C65, 0x74746572, 0x73000000, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x81E781E8, 0x00000000, 0x5369676E, 0x73000000, 0x81438144, 0x81488149, 0x817B817C, 0x815E815F, 0x81818183, 0x81848146, 0x8147814C, 0x814D814F, 0x81518162, 0x8169816A, 0x816D816E, 0x816F8170, 0x81908193, 0x81948195, 0x81968197, 0x81E781E8, 0x00000000, 0x4E756D62, 0x65727300, 0x824F8250, 0x82518252, 0x82538254, 0x82558256, 0x82578258, 0x81E781E8, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const fn_8_EFA4_u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile fn_8_EFA4_f32 s; volatile fn_8_EFA4_f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.21;
    d = 1.6666666666666667;
    d = 0.5;
    s = 48.0f;
    s = 0.25f;
    d = 1.0;
    s = 0.12999999523162842f;
}
static const fn_8_EFA4_u32 fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const fn_8_EFA4_u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile fn_8_EFA4_f32 s; volatile fn_8_EFA4_f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.5;
    d = 2.0;
    s = 1.6666666269302368f;
    s = 0.0625f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 32.0f;
    s = 24.0f;
    s = 18.0f;
}
static const fn_8_EFA4_u32 fzgx_pool_table7[6] = {0xFFFFFF00, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x000000FF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const fn_8_EFA4_u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile fn_8_EFA4_f32 s; volatile fn_8_EFA4_f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 12.0f;
    s = 0.0f;
}
static const fn_8_EFA4_u32 fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const fn_8_EFA4_u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile fn_8_EFA4_f32 s; volatile fn_8_EFA4_f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    d = 12.0;
    s = 10.100000381469727f;
}
static const fn_8_EFA4_u32 fzgx_pool_table11[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const fn_8_EFA4_u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile fn_8_EFA4_f32 s; volatile fn_8_EFA4_f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 24.0;
    s = 1.0f;
    s = 10.0f;
}
static const fn_8_EFA4_u32 fzgx_pool_table13[2] = {0x00FFFF00, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const fn_8_EFA4_u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile fn_8_EFA4_f32 s; volatile fn_8_EFA4_f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.649999976158142f;
}
static const fn_8_EFA4_u32 fzgx_pool_table15[1] = {0x33333333};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const fn_8_EFA4_u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
static const fn_8_EFA4_u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const fn_8_EFA4_u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
static const fn_8_EFA4_u32 fzgx_pool_table17[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const fn_8_EFA4_u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
static const fn_8_EFA4_u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const fn_8_EFA4_u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
static const fn_8_EFA4_u32 fzgx_pool_table19[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const fn_8_EFA4_u32 *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
static const fn_8_EFA4_u32 fzgx_pool_table20[1] = {0x00FFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const fn_8_EFA4_u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
static const fn_8_EFA4_u32 fzgx_pool_table21[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const fn_8_EFA4_u32 *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile fn_8_EFA4_f32 s; volatile fn_8_EFA4_f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 6.0;
    d = 20.0;
    s = 167.0f;
    s = 38.0f;
    s = 0.5f;
    s = 68.0f;
    s = 10.199999809265137f;
    s = 320.0f;
    s = 140.0f;
    s = 98.0f;
    s = 0.1899999976158142f;
    s = 178.0f;
    s = 0.18000000715255737f;
    s = 0.17000000178813934f;
    s = 352.0f;
    s = 0.1599999964237213f;
    s = 0.15000000596046448f;
    s = 0.14000000059604645f;
    s = 110.0f;
    s = 250.0f;
    s = 180.0f;
    s = 390.0f;
    s = 378.0f;
}
static const fn_8_EFA4_u32 fzgx_pool_table23[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const fn_8_EFA4_u32 *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile fn_8_EFA4_f32 s; volatile fn_8_EFA4_f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.1;
    d = 0.25;
    s = 346.0f;
    s = 0.11999999731779099f;
    s = 397.0f;
    s = 321.0f;
    d = 2.1666666666666665;
    s = 118.0f;
    s = 0.625f;
    s = 0.30000001192092896f;
}
static const fn_8_EFA4_u32 fzgx_pool_table25[1] = {0x00FFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const fn_8_EFA4_u32 *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef int fn_8_EFA4_BOOL;
typedef unsigned long fn_8_EFA4_size_t;
typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
fn_8_EFA4_f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
fn_8_EFA4_u32 image;
fn_8_EFA4_f32 x, y, z;
fn_8_EFA4_f32 scale_x, scale_y;
fn_8_EFA4_f32 u0, v0, u1, v1;
fn_8_EFA4_s16 rotation_z, rotation_y;
fn_8_EFA4_f32 alpha;
fn_8_EFA4_u32 flags;
fn_8_EFA4_f32 depth;
fn_8_EFA4_u8 color[4], color_add[4];
fn_8_EFA4_u32 format;
fn_8_EFA4_u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
fn_8_EFA4_u32 unk_54;
};
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, fn_8_EFA4_f32 width, fn_8_EFA4_f32 height);
void fn_1_51678(FontDrawPacket* packet, fn_8_EFA4_u32 image, fn_8_EFA4_s16 x, fn_8_EFA4_s16 y, fn_8_EFA4_s16 width, fn_8_EFA4_s16 height);
void fn_1_517EC(FontDrawPacket* packet, fn_8_EFA4_s16 x, fn_8_EFA4_s16 y, fn_8_EFA4_s16 width, fn_8_EFA4_s16 height,
fn_8_EFA4_s16 texture_width, fn_8_EFA4_s16 texture_height);
/* Generated by `fzgx headers --module option`: layouts recovered from every access in the */
/* module's disassembly (matched or not). Field names are offsets until the librarian names them; */
/* offsets and widths are facts, names are not. Regenerate rather than hand-edit padding. */
/* lbl_4_bss_0: .bss size 0x2, referenced by 39 functions, shape {'object': 762} */
extern fn_8_EFA4_u16 lbl_4_bss_0;
/* lbl_4_data_0: .data size 0xC, referenced by 17 functions, shape {'object': 49} */
extern fn_8_EFA4_u8 lbl_4_data_0[0xC];
/* lbl_4_bss_8: .bss size 0x4, referenced by 14 functions, shape {'object': 14} */
extern fn_8_EFA4_u32 lbl_4_bss_8;
/* lbl_4_bss_5680: .bss size 0x4, referenced by 8 functions, shape {'object': 112, 'pointer': 28} */
typedef struct {
fn_8_EFA4_u32 unk_0; /* 11 loads, 6 stores */
fn_8_EFA4_u32 unk_4; /* 1 loads, 1 stores */
fn_8_EFA4_u32 unk_8; /* 4 loads, 1 stores */
fn_8_EFA4_u8 unk_C; /* 8 loads, 1 stores */
fn_8_EFA4_u8 unk_D; /* 5 loads, 4 stores */
fn_8_EFA4_u8 unk_E; /* 10 loads, 3 stores */
fn_8_EFA4_u8 unk_F; /* 3 loads, 12 stores */
fn_8_EFA4_u8 unk_10; /* 1 loads, 0 stores */
fn_8_EFA4_u8 unk_11; /* 2 loads, 1 stores */
fn_8_EFA4_u16 unk_12; /* 3 loads, 3 stores */
fn_8_EFA4_u8 unk_14; /* 2 loads, 2 stores */
fn_8_EFA4_u8 unk_15; /* 2 loads, 2 stores */
fn_8_EFA4_u8 unk_16; /* 2 loads, 2 stores */
fn_8_EFA4_u8 unk_17; /* 2 loads, 2 stores */
fn_8_EFA4_u32 unk_18; /* 1 loads, 1 stores */
fn_8_EFA4_u32 unk_1C; /* 1 loads, 1 stores */
fn_8_EFA4_u32 unk_20; /* 3 loads, 2 stores */
fn_8_EFA4_u8 pad_24[0x4];
fn_8_EFA4_u8 unk_28; /* 1 loads, 0 stores */
fn_8_EFA4_u8 pad_29[0xD];
fn_8_EFA4_u8 unk_36; /* 2 loads, 1 stores */
fn_8_EFA4_u8 unk_37; /* 0 loads, 1 stores */
fn_8_EFA4_u8 pad_38[0x2];
fn_8_EFA4_u8 unk_3A; /* 2 loads, 2 stores */
fn_8_EFA4_u8 unk_3B; /* 5 loads, 2 stores */
fn_8_EFA4_u32 unk_3C; /* 4 loads, 2 stores */
} Obj_4_bss_5680_Target;

/* lbl_4_bss_5630: .bss size 0x48, referenced by 6 functions, shape {'object': 5} */
typedef struct {
fn_8_EFA4_u32 unk_0; /* 0 loads, 3 stores */
fn_8_EFA4_u8 unk_4; /* 0 loads, 1 stores */
fn_8_EFA4_u8 pad_5[0x1D];
fn_8_EFA4_u8 unk_22; /* 1 loads, 0 stores */
fn_8_EFA4_u8 pad_23[0x25];
} Obj_4_bss_5630;
extern Obj_4_bss_5630 lbl_4_bss_5630;
/* lbl_4_bss_2: .bss size 0x1, referenced by 5 functions, shape {'object': 10} */
extern fn_8_EFA4_u8 lbl_4_bss_2;
/* lbl_4_data_2F78: .data size 0xA0, referenced by 5 functions, shape {} */
extern fn_8_EFA4_u8 lbl_4_data_2F78[0xA0];
/* lbl_4_data_2F1C: .data size 0x4, referenced by 4 functions, shape {'object': 4} */
extern fn_8_EFA4_u32 lbl_4_data_2F1C;
/* lbl_4_bss_5684: .bss size 0x1, referenced by 3 functions, shape {'object': 3} */
extern fn_8_EFA4_u8 lbl_4_bss_5684;
/* lbl_4_bss_4: .bss size 0x4, referenced by 2 functions, shape {'object': 2} */
extern fn_8_EFA4_u32 lbl_4_bss_4;
/* lbl_4_bss_10: .bss size 0xB4, referenced by 2 functions, shape {'object': 8} */
typedef struct {
fn_8_EFA4_u16 unk_0; /* 4 loads, 4 stores */
fn_8_EFA4_u8 pad_2[0xB2];
} Obj_4_bss_10;
extern Obj_4_bss_10 lbl_4_bss_10;
/* lbl_4_bss_C4: .bss size 0x5554, referenced by 2 functions, shape {'object': 16} */
typedef struct {
fn_8_EFA4_u8 pad_0[0x2];
fn_8_EFA4_u16 unk_2; /* 1 loads, 1 stores */
fn_8_EFA4_u16 unk_4; /* 1 loads, 1 stores */
fn_8_EFA4_u16 unk_6; /* 1 loads, 1 stores */
fn_8_EFA4_u32 unk_8; /* 1 loads, 1 stores */
fn_8_EFA4_u32 unk_C; /* 1 loads, 1 stores */
fn_8_EFA4_u32 unk_10; /* 1 loads, 1 stores */
fn_8_EFA4_u32 unk_14; /* 1 loads, 1 stores */
fn_8_EFA4_u32 unk_18; /* 1 loads, 1 stores */
fn_8_EFA4_u8 pad_1C[0x5538];
} Obj_4_bss_C4;
extern Obj_4_bss_C4 lbl_4_bss_C4;
/* lbl_4_data_2F00: .data size 0x1C, referenced by 2 functions, shape {'object': 6} */
typedef struct {
fn_8_EFA4_u8 pad_0[0x18];
fn_8_EFA4_u32 unk_18; /* 3 loads, 1 stores */
} Obj_4_data_2F00;
extern Obj_4_data_2F00 lbl_4_data_2F00;
/* lbl_4_bss_5685: .bss size 0x1, referenced by 2 functions, shape {'object': 6} */
extern fn_8_EFA4_u8 lbl_4_bss_5685;
struct fn_4_C768_Copy88 { fn_8_EFA4_u32 a[22]; };
struct fn_4_C768_Ro410 {
fn_8_EFA4_u8 pad_0[0x6B8];
fn_8_EFA4_f64 unk_6B8;
fn_8_EFA4_u8 pad_6C0[0x8];
fn_8_EFA4_f64 unk_6C8;
fn_8_EFA4_f32 unk_6D0;
fn_8_EFA4_u8 pad_6D4[0x1C];
fn_8_EFA4_f64 unk_6F0;
fn_8_EFA4_f64 unk_6F8;
fn_8_EFA4_u8 pad_700[0x28];
fn_8_EFA4_f32 unk_728;
fn_8_EFA4_u8 pad_72C[0xC];
fn_8_EFA4_f64 unk_738;
fn_8_EFA4_u8 pad_740[0x10];
fn_8_EFA4_f32 unk_750;
fn_8_EFA4_u8 pad_754[0x14];
fn_8_EFA4_u32 unk_768;
fn_8_EFA4_u32 unk_76C;
fn_8_EFA4_u32 unk_770;
fn_8_EFA4_u32 unk_774;
fn_8_EFA4_u32 unk_778;
fn_8_EFA4_u8 pad_77C[0x4];
fn_8_EFA4_f64 unk_780;
fn_8_EFA4_f64 unk_788;
fn_8_EFA4_f32 unk_790;
fn_8_EFA4_f32 unk_794;
fn_8_EFA4_f32 unk_798;
fn_8_EFA4_f32 unk_79C;
fn_8_EFA4_f32 unk_7A0;
fn_8_EFA4_f32 unk_7A4;
fn_8_EFA4_f32 unk_7A8;
fn_8_EFA4_f32 unk_7AC;
fn_8_EFA4_f32 unk_7B0;
fn_8_EFA4_f32 unk_7B4;
fn_8_EFA4_f32 unk_7B8;
fn_8_EFA4_f32 unk_7BC;
fn_8_EFA4_f32 unk_7C0;
fn_8_EFA4_f32 unk_7C4;
fn_8_EFA4_f32 unk_7C8;
fn_8_EFA4_f32 unk_7CC;
fn_8_EFA4_f32 unk_7D0;
fn_8_EFA4_f32 unk_7D4;
fn_8_EFA4_f32 unk_7D8;
fn_8_EFA4_f32 unk_7DC;
fn_8_EFA4_f32 unk_7E0;
fn_8_EFA4_u8 pad_7E4[0x4];
fn_8_EFA4_f64 unk_7E8;
fn_8_EFA4_f64 unk_7F0;
fn_8_EFA4_f32 unk_7F8;
fn_8_EFA4_f32 unk_7FC;
fn_8_EFA4_f32 unk_800;
fn_8_EFA4_f32 unk_804;
fn_8_EFA4_f64 unk_808;
fn_8_EFA4_f32 unk_810;
fn_8_EFA4_f32 unk_814;
fn_8_EFA4_f32 unk_818;
};
struct fn_4_C768_lbl_1_data_418D4 {
fn_8_EFA4_u32 unk_0[1];
};
struct fn_4_C768_Clr { fn_8_EFA4_u32 w; };
union NativeColor {fn_8_EFA4_u32 w;fn_8_EFA4_s8 b[4];};

extern fn_8_EFA4_s32 lbl_801A66B4;
extern struct fn_4_C768_lbl_1_data_418D4 lbl_1_data_418D4;
extern fn_8_EFA4_u8 lbl_1_rodata_26F8[];

extern fn_8_EFA4_u32 lbl_801A66A0;
extern fn_8_EFA4_u32 fn_1_49410(void);
extern fn_8_EFA4_u32 fn_1_134AD4(void);
extern int fn_1_4F734(FontDrawPacket *);
extern fn_8_EFA4_u32 fn_1_13ABA8(fn_8_EFA4_u32);
extern fn_8_EFA4_f32 lbl_8006D188(fn_8_EFA4_s16);
extern void * memset(void *, int, fn_8_EFA4_u32);
extern char * strncpy(char *, const char *, fn_8_EFA4_size_t);
extern void fn_1_494DC(fn_8_EFA4_s16);
extern void fn_1_495C8(fn_8_EFA4_u8);
extern void fn_1_496FC(fn_8_EFA4_f32, fn_8_EFA4_f32);
extern void fn_1_4955C(fn_8_EFA4_f32, fn_8_EFA4_f32);
extern void fn_1_49514(fn_8_EFA4_u32 *);
extern void fn_1_49590(fn_8_EFA4_f32);
extern void fn_1_495B0(fn_8_EFA4_u32);
void fn_8_EFA4(void) {
    fn_8_EFA4_f32 *fzgx_value_;
    fn_8_EFA4_f32 fzgx_value;
FontDrawPacket loc_20;
fn_8_EFA4_u8 buf[3];
struct fn_4_C768_Clr clr_18;
union NativeColor clr_14;
struct fn_4_C768_Clr clr_10;
union NativeColor clr_C;
fn_8_EFA4_u32 sp8;
fn_8_EFA4_f32 var_f31;
fn_8_EFA4_f32 temp_f0;
fn_8_EFA4_f32 temp_f0_2;
fn_8_EFA4_f32 temp_f0_3;
fn_8_EFA4_f32 temp_f0_4;
fn_8_EFA4_f32 temp_f0_5;
fn_8_EFA4_u32 var_r28;
fn_8_EFA4_u32 var_r27;
fn_8_EFA4_u32 var_r27_2;
fn_8_EFA4_u32 var_r28_2;
fn_8_EFA4_u8 *var_r4;
fn_8_EFA4_u8 *base;
fn_1_49410();
{
fn_8_EFA4_u8 c = (*(Obj_4_bss_5680_Target * (*)[1])&lbl_8_bss_550)[0]->unk_3A;
fn_8_EFA4_u8 *base = (fn_8_EFA4_u8 *)((*(Obj_4_bss_5680_Target * (*)[1])&lbl_8_bss_550)[0]->unk_3C + (*(Obj_4_bss_5680_Target * (*)[1])&lbl_8_bss_550)[0]->unk_D * 0x14);
if (c != 0) {
if (c > 9) {
var_f31 = (fn_8_EFA4_f32)((0.5) + (fn_8_EFA4_f64)(fn_8_EFA4_f32)(c - 0xA) / (6.0));
} else {
var_f31 = (fn_8_EFA4_f32)((0.5) + (fn_8_EFA4_f64)(fn_8_EFA4_f32)(0xA - c) / (20.0));
}
(*(Obj_4_bss_5680_Target * (*)[1])&lbl_8_bss_550)[0]->unk_3A = (*(fn_8_EFA4_u8 *)&((*(Obj_4_bss_5680_Target * (*)[1])&lbl_8_bss_550)[0]->unk_3A)) - 1;
} else {
var_f31 = (1.0f);
}
fn_1_134AD4();
if ((*(fn_8_EFA4_s16 *)&lbl_1_bss_960) != 3) {
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.image = 0x8F0C;
loc_20.x = (167.0f);
loc_20.y = (38.0f);
loc_20.z = (0.5f);
loc_20.flags = 0xA;
fn_1_4F734(&loc_20);
}
if ((((*(Obj_4_bss_5680_Target * (*)[1])&lbl_8_bss_550)[0]->unk_0) >> 0x1FU) == 0) {
if (lbl_801A66B4 == 5) {
fn_1_1380F0(&(*(fn_8_EFA4_u32 *)&lbl_8_data_A2C8));
} else {
fn_1_1380F0(&(*(fn_8_EFA4_u32 *)&lbl_8_data_A2E0));
}
} else {
fn_1_1380F0((void *)((fn_8_EFA4_u32 *)&lbl_1_data_418D4)[lbl_801A66B4]);
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
loc_20.x = (fn_8_EFA4_f32)var_r28;
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
loc_20.rotation_z = (fn_8_EFA4_s16)(((*(Obj_4_bss_5680_Target * (*)[1])&lbl_8_bss_550)[0]->unk_11 << 8) & 0xFF00);
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
fzgx_value = (110.0f);
loc_20.y = fzgx_value;
{
fn_8_EFA4_u8 v = (*(Obj_4_bss_5680_Target * (*)[1])&lbl_8_bss_550)[0]->unk_14;
fn_8_EFA4_u8 *cb = (fn_8_EFA4_u8 *)&clr_18;
clr_18.w = fzgx_pool_table16[0];
cb[0] = (fn_8_EFA4_u8)((v * 0x10) & 0xF0);
cb[1] = (fn_8_EFA4_u8)((v * 0x10) & 0xF0);
cb[2] = (fn_8_EFA4_u8)((v * 0x10) & 0xF0);
*(fn_8_EFA4_u32 *)loc_20.color_add = clr_18.w;
temp_f0 = (fn_8_EFA4_f32)((1.0) + (fn_8_EFA4_f64)v / (12.0));
loc_20.scale_y = temp_f0;
loc_20.scale_x = temp_f0;
}
fn_1_4F734(&loc_20);
loc_20.y = (250.0f);
loc_20.image = 0x8F02;
{
fn_8_EFA4_u32 v = (*(Obj_4_bss_5680_Target * (*)[1])&lbl_8_bss_550)[0]->unk_15;
clr_14.w = fzgx_pool_table17[0];
clr_14.b[0] = (fn_8_EFA4_u8)((v * 0x10) & 0xF0);
clr_14.b[1] = (fn_8_EFA4_u8)((v * 0x10) & 0xF0);
clr_14.b[2] = (fn_8_EFA4_u8)((v * 0x10) & 0xF0);
*(fn_8_EFA4_u32 *)loc_20.color_add = clr_14.w;
temp_f0_2 = (fn_8_EFA4_f32)((1.0) + (fn_8_EFA4_f64)v / (12.0));
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
fn_8_EFA4_u8 v = (*(Obj_4_bss_5680_Target * (*)[1])&lbl_8_bss_550)[0]->unk_16;
fn_8_EFA4_u8 *cb = (fn_8_EFA4_u8 *)&clr_10;
clr_10.w = fzgx_pool_table18[0];
cb[0] = (fn_8_EFA4_u8)((v * 0x10) & 0xF0);
cb[1] = (fn_8_EFA4_u8)((v * 0x10) & 0xF0);
cb[2] = (fn_8_EFA4_u8)((v * 0x10) & 0xF0);
*(fn_8_EFA4_u32 *)loc_20.color_add = clr_10.w;
temp_f0_3 = (fn_8_EFA4_f32)((1.0) + (fn_8_EFA4_f64)v / (12.0));
loc_20.scale_y = temp_f0_3;
loc_20.scale_x = temp_f0_3;
}
fn_1_4F734(&loc_20);
loc_20.x = (390.0f);
loc_20.flags |= 0x80000;
{
fn_8_EFA4_u32 v = (*(Obj_4_bss_5680_Target * (*)[1])&lbl_8_bss_550)[0]->unk_17;
clr_C.w = fzgx_pool_table19[0];
clr_C.b[0] = (fn_8_EFA4_u8)((v * 0x10) & 0xF0);
clr_C.b[1] = (fn_8_EFA4_u8)((v * 0x10) & 0xF0);
clr_C.b[2] = (fn_8_EFA4_u8)((v * 0x10) & 0xF0);
*(fn_8_EFA4_u32 *)loc_20.color_add = clr_C.w;
temp_f0_4 = (fn_8_EFA4_f32)((1.0) + (fn_8_EFA4_f64)v / (12.0));
loc_20.scale_y = temp_f0_4;
loc_20.scale_x = temp_f0_4;
}
fn_1_4F734(&loc_20);
if ((*(Obj_4_bss_5680_Target * (*)[1])&lbl_8_bss_550)[0]->unk_E != 7 || (*(Obj_4_bss_5680_Target * (*)[1])&lbl_8_bss_550)[0]->unk_36 == 0) {
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.image = 0x8F09;
loc_20.y = (378.0f);
loc_20.z = (0.129999995f);
{
fn_8_EFA4_f64 t = (0.25) * lbl_8006D188((fn_8_EFA4_s16)((lbl_801A66A0 << 8) & 0xFF00));
temp_f0_5 = (fn_8_EFA4_f32)((1.1000000000000001) + t);
}
loc_20.flags = 0xA;
loc_20.scale_y = temp_f0_5;
loc_20.scale_x = temp_f0_5;
var_r27_2 = (*(Obj_4_bss_5680_Target * (*)[1])&lbl_8_bss_550)[0]->unk_E;
var_r28_2 = (var_r27_2 * 0x38) + 0x7C;
while (var_r27_2 < 8) {
loc_20.x = (fn_8_EFA4_f32)var_r28_2;
fn_1_4F734(&loc_20);
var_r28_2 += 0x38;
var_r27_2 += 1;
}
}
if ((((*(Obj_4_bss_5680_Target * (*)[1])&lbl_8_bss_550)[0]->unk_0) >> 0x1FU) == 0) {
*(struct fn_4_C768_Copy88 *)&loc_20 = *(struct fn_4_C768_Copy88 *)lbl_1_rodata_26F8;
loc_20.image = 0x8F00;
loc_20.x = (fn_8_EFA4_f32)((*(Obj_4_bss_5680_Target * (*)[1])&lbl_8_bss_550)[0]->unk_12);
loc_20.y = (346.0f);
loc_20.z = (0.119999997f);
fn_1_4F734(&loc_20);
loc_20.image = 0x8F01;
loc_20.y = (397.0f);
fn_1_4F734(&loc_20);
}
memset(buf, 0, 3);
switch ((*(Obj_4_bss_5680_Target * (*)[1])&lbl_8_bss_550)[0]->unk_F) {
case 0:
default:
var_r4 = (fn_8_EFA4_u8 *)(*(fn_8_EFA4_u32 *)(base + 4) + *(fn_8_EFA4_u16 *)base * 2);
break;
case 1:
var_r4 = (fn_8_EFA4_u8 *)(*(fn_8_EFA4_u32 *)(base + 8) + *(fn_8_EFA4_u16 *)base * 2);
break;
case 2:
var_r4 = (fn_8_EFA4_u8 *)(*(fn_8_EFA4_u32 *)(base + 12) + *(fn_8_EFA4_u16 *)base * 2);
break;
}
strncpy((char *)buf, (const char *)var_r4, 2);
fn_1_49410();
fn_1_494DC(0x2A);
fn_1_495C8(9);
fn_1_496FC((321.0f), (178.0f));
{
fn_8_EFA4_f64 t = (2.1666666666666665) * (fn_8_EFA4_f64)var_f31;
fn_1_4955C((fn_8_EFA4_f32)t, (fn_8_EFA4_f32)t);
}
fn_1_4A0D8((const char *)buf);
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.image = 0x8F03;
loc_20.x = (118.0f);
loc_20.y = (118.0f);
fzgx_value_ = &loc_20.z;
*fzgx_value_ = (0.189999998f);
fn_1_4F734(&loc_20);
fn_1_49410();
fn_1_494DC(0x2A);
fn_1_496FC((140.0f), (118.0f));
sp8 = fzgx_pool_table20[0];
fn_1_49514(&sp8);
if (lbl_801A66B4 == 5) {
fn_1_4955C((0.625f), (0.625f));
} else {
fn_1_4955C((0.5f), (0.5f));
fn_1_49590((0.300000012f));
fn_1_495B0(0x80000000U);
}
fn_1_4A0D8((const char *)(*(fn_8_EFA4_u32 *)(base + 16)));
fn_1_133DBC((void *)1);
}
}
/* fzgx:end fn_8_EFA4 */

/* fzgx:begin fn_8_F9E4 noprologue */
#include "types.h"

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u8 unk_c;
    u8 pad_d[5];
    u16 unk_12;
    u8 pad_14[4];
    u32 unk_18;
    u32 unk_1c;
    u8 pad_20[0x1b];
    u8 unk_3b;
    u32 unk_3c;
} Obj;

typedef struct {
    u8 unk_0;
    u8 pad_1[3];
    u16 unk_4;
    f32 unk_8;
} Node;

extern u32 lbl_801A6410;
extern s16 lbl_1_bss_960;
extern s32 lbl_801A66B4;
const u8 lbl_8_rodata_408[8] = {0x89,0x70,0x90,0x94,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_410[132] = {0x82,0x60,0x82,0x61,0x82,0x62,0x82,0x63,0x82,0x64,0x82,0x65,0x82,0x66,0x82,0x67,0x82,0x68,0x82,0x69,0x82,0x6A,0x82,0x6B,0x82,0x6C,0x82,0x6D,0x82,0x6E,0x82,0x6F,0x82,0x70,0x82,0x71,0x82,0x72,0x82,0x73,0x82,0x74,0x82,0x75,0x82,0x76,0x82,0x77,0x82,0x78,0x82,0x79,0x82,0x81,0x82,0x82,0x82,0x83,0x82,0x84,0x82,0x85,0x82,0x86,0x82,0x87,0x82,0x88,0x82,0x89,0x82,0x8A,0x82,0x8B,0x82,0x8C,0x82,0x8D,0x82,0x8E,0x82,0x8F,0x82,0x90,0x82,0x91,0x82,0x92,0x82,0x93,0x82,0x94,0x82,0x95,0x82,0x96,0x82,0x97,0x82,0x98,0x82,0x99,0x82,0x9A,0x82,0x4F,0x82,0x50,0x82,0x51,0x82,0x52,0x82,0x53,0x82,0x54,0x82,0x55,0x82,0x56,0x82,0x57,0x82,0x58,0x81,0xE7,0x81,0xE8,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_494[132] = {0x82,0x81,0x82,0x82,0x82,0x83,0x82,0x84,0x82,0x85,0x82,0x86,0x82,0x87,0x82,0x88,0x82,0x89,0x82,0x8A,0x82,0x8B,0x82,0x8C,0x82,0x8D,0x82,0x8E,0x82,0x8F,0x82,0x90,0x82,0x91,0x82,0x92,0x82,0x93,0x82,0x94,0x82,0x95,0x82,0x96,0x82,0x97,0x82,0x98,0x82,0x99,0x82,0x9A,0x82,0x60,0x82,0x61,0x82,0x62,0x82,0x63,0x82,0x64,0x82,0x65,0x82,0x66,0x82,0x67,0x82,0x68,0x82,0x69,0x82,0x6A,0x82,0x6B,0x82,0x6C,0x82,0x6D,0x82,0x6E,0x82,0x6F,0x82,0x70,0x82,0x71,0x82,0x72,0x82,0x73,0x82,0x74,0x82,0x75,0x82,0x76,0x82,0x77,0x82,0x78,0x82,0x79,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_518[8] = {0x8B,0x4C,0x8D,0x86,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_520[80] = {0x81,0x41,0x81,0x42,0x81,0x4C,0x81,0x4D,0x81,0x45,0x81,0x43,0x81,0x44,0x81,0x46,0x81,0x47,0x81,0x48,0x81,0x49,0x81,0x7B,0x81,0x7C,0x81,0x5E,0x81,0x81,0x81,0x83,0x81,0x84,0x81,0x4F,0x81,0x51,0x81,0x60,0x81,0x62,0x81,0x75,0x81,0x76,0x81,0x69,0x81,0x6A,0x81,0x6F,0x81,0x70,0x81,0x6D,0x81,0x6E,0x81,0x8F,0x81,0x90,0x81,0x93,0x81,0x94,0x81,0x95,0x81,0x96,0x81,0x97,0x81,0xE7,0x81,0xE8,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_570[12] = {0x82,0xD0,0x82,0xE7,0x82,0xAA,0x82,0xC8,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_57C[172] = {0x82,0xA0,0x82,0xA2,0x82,0xA4,0x82,0xA6,0x82,0xA8,0x82,0xA9,0x82,0xAB,0x82,0xAD,0x82,0xAF,0x82,0xB1,0x82,0xB3,0x82,0xB5,0x82,0xB7,0x82,0xB9,0x82,0xBB,0x82,0xBD,0x82,0xBF,0x82,0xC2,0x82,0xC4,0x82,0xC6,0x82,0xC8,0x82,0xC9,0x82,0xCA,0x82,0xCB,0x82,0xCC,0x82,0xCD,0x82,0xD0,0x82,0xD3,0x82,0xD6,0x82,0xD9,0x82,0xDC,0x82,0xDD,0x82,0xDE,0x82,0xDF,0x82,0xE0,0x82,0xE2,0x82,0xE4,0x82,0xE6,0x82,0xE7,0x82,0xE8,0x82,0xE9,0x82,0xEA,0x82,0xEB,0x82,0xED,0x82,0xEE,0x82,0xEF,0x82,0xF0,0x82,0xF1,0x82,0xAA,0x82,0xAC,0x82,0xAE,0x82,0xB0,0x82,0xB2,0x82,0xB4,0x82,0xB6,0x82,0xB8,0x82,0xBA,0x82,0xBC,0x82,0xBE,0x82,0xC0,0x82,0xC3,0x82,0xC5,0x82,0xC7,0x82,0xCE,0x82,0xD1,0x82,0xD4,0x82,0xD7,0x82,0xDA,0x82,0xCF,0x82,0xD2,0x82,0xD5,0x82,0xD8,0x82,0xDB,0x82,0x9F,0x82,0xA1,0x82,0xA3,0x82,0xA5,0x82,0xA7,0x82,0xC1,0x82,0xE1,0x82,0xE3,0x82,0xE5,0x82,0xEC,0x81,0xE7,0x81,0xE8,0x00,0x00};
const u8 lbl_8_rodata_628[172] = {0x82,0x9F,0x82,0xA1,0x82,0xA3,0x82,0xA5,0x82,0xA7,0x82,0xAA,0x82,0xAC,0x82,0xAE,0x82,0xB0,0x82,0xB2,0x82,0xB4,0x82,0xB6,0x82,0xB8,0x82,0xBA,0x82,0xBC,0x82,0xBE,0x82,0xC0,0x82,0xC1,0x82,0xC5,0x82,0xC7,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x82,0xCE,0x82,0xD1,0x82,0xD4,0x82,0xD7,0x82,0xDA,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x82,0xE1,0x82,0xE3,0x82,0xE5,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x82,0xEC,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x82,0xA9,0x82,0xAB,0x82,0xAD,0x82,0xAF,0x82,0xB1,0x82,0xB3,0x82,0xB5,0x82,0xB7,0x82,0xB9,0x82,0xBB,0x82,0xBD,0x82,0xBF,0x82,0xC2,0x82,0xC4,0x82,0xC6,0x82,0xCF,0x82,0xD2,0x82,0xD5,0x82,0xD8,0x82,0xDB,0x82,0xCD,0x82,0xD0,0x82,0xD3,0x82,0xD6,0x82,0xD9,0x82,0xA0,0x82,0xA2,0x82,0xA4,0x82,0xA6,0x82,0xA8,0x82,0xC2,0x82,0xE2,0x82,0xE4,0x82,0xE6,0x82,0xED,0x81,0x40,0x81,0x40,0x00,0x00};
const u8 lbl_8_rodata_6D4[172] = {0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x82,0xC3,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x82,0xCF,0x82,0xD2,0x82,0xD5,0x82,0xD8,0x82,0xDB,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x82,0xC1,0x81,0x40,0x81,0x40,0x82,0xCD,0x82,0xD0,0x82,0xD3,0x82,0xD6,0x82,0xD9,0x82,0xCE,0x82,0xD1,0x82,0xD4,0x82,0xD7,0x82,0xDA,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x82,0xC3,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x00,0x00};
const u8 lbl_8_rodata_780[12] = {0x83,0x4A,0x83,0x5E,0x83,0x4A,0x83,0x69,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_78C[180] = {0x83,0x41,0x83,0x43,0x83,0x45,0x83,0x47,0x83,0x49,0x83,0x4A,0x83,0x4C,0x83,0x4E,0x83,0x50,0x83,0x52,0x83,0x54,0x83,0x56,0x83,0x58,0x83,0x5A,0x83,0x5C,0x83,0x5E,0x83,0x60,0x83,0x63,0x83,0x65,0x83,0x67,0x83,0x69,0x83,0x6A,0x83,0x6B,0x83,0x6C,0x83,0x6D,0x83,0x6E,0x83,0x71,0x83,0x74,0x82,0xD6,0x83,0x7A,0x83,0x7D,0x83,0x7E,0x83,0x80,0x83,0x81,0x83,0x82,0x83,0x84,0x83,0x86,0x83,0x88,0x83,0x89,0x83,0x8A,0x83,0x8B,0x83,0x8C,0x83,0x8D,0x83,0x8F,0x83,0x90,0x83,0x91,0x83,0x92,0x83,0x93,0x83,0x94,0x83,0x4B,0x83,0x4D,0x83,0x4F,0x83,0x51,0x83,0x53,0x83,0x55,0x83,0x57,0x83,0x59,0x83,0x5B,0x83,0x5D,0x83,0x5F,0x83,0x61,0x83,0x64,0x83,0x66,0x83,0x68,0x83,0x6F,0x83,0x72,0x83,0x75,0x82,0xD7,0x83,0x7B,0x83,0x70,0x83,0x73,0x83,0x76,0x82,0xD8,0x83,0x7C,0x83,0x40,0x83,0x42,0x83,0x44,0x83,0x46,0x83,0x48,0x83,0x95,0x83,0x96,0x83,0x62,0x83,0x83,0x83,0x85,0x83,0x87,0x83,0x8E,0x81,0xE7,0x81,0xE8,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_840[180] = {0x83,0x40,0x83,0x42,0x83,0x44,0x83,0x46,0x83,0x48,0x83,0x4B,0x83,0x4D,0x83,0x4F,0x83,0x51,0x83,0x53,0x83,0x55,0x83,0x57,0x83,0x59,0x83,0x5B,0x83,0x5D,0x83,0x5F,0x83,0x61,0x83,0x62,0x83,0x66,0x83,0x68,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x83,0x6F,0x83,0x72,0x83,0x75,0x82,0xD7,0x83,0x7B,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x83,0x83,0x83,0x85,0x83,0x87,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x83,0x8E,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x83,0x45,0x83,0x4A,0x83,0x4C,0x83,0x4E,0x83,0x50,0x83,0x52,0x83,0x54,0x83,0x56,0x83,0x58,0x83,0x5A,0x83,0x5C,0x83,0x5E,0x83,0x60,0x83,0x63,0x83,0x65,0x83,0x67,0x83,0x70,0x83,0x73,0x83,0x76,0x82,0xD8,0x83,0x7C,0x83,0x6E,0x83,0x71,0x83,0x74,0x82,0xD6,0x83,0x7A,0x83,0x41,0x83,0x43,0x83,0x45,0x83,0x47,0x83,0x49,0x83,0x4A,0x83,0x50,0x83,0x63,0x83,0x84,0x83,0x86,0x83,0x88,0x83,0x8F,0x81,0x40,0x81,0x40,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_8F4[180] = {0x81,0x40,0x81,0x40,0x83,0x94,0x81,0x40,0x81,0x40,0x83,0x95,0x81,0x40,0x81,0x40,0x83,0x96,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x83,0x64,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x83,0x70,0x83,0x73,0x83,0x76,0x82,0xD8,0x83,0x7C,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x83,0x44,0x83,0x95,0x81,0x40,0x81,0x40,0x83,0x96,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x83,0x62,0x81,0x40,0x81,0x40,0x83,0x6E,0x83,0x71,0x83,0x74,0x82,0xD6,0x83,0x7A,0x83,0x6F,0x83,0x72,0x83,0x75,0x82,0xD7,0x83,0x7B,0x81,0x40,0x81,0x40,0x83,0x94,0x81,0x40,0x81,0x40,0x83,0x4B,0x83,0x51,0x83,0x64,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x81,0x40,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_9A8[16] = {0x43,0x61,0x70,0x69,0x74,0x61,0x6C,0x20,0x4C,0x65,0x74,0x74,0x65,0x72,0x73,0x00};
const u8 lbl_8_rodata_9B8[60] = {0x82,0x60,0x82,0x61,0x82,0x62,0x82,0x63,0x82,0x64,0x82,0x65,0x82,0x66,0x82,0x67,0x82,0x68,0x82,0x69,0x82,0x6A,0x82,0x6B,0x82,0x6C,0x82,0x6D,0x82,0x6E,0x82,0x6F,0x82,0x70,0x82,0x71,0x82,0x72,0x82,0x73,0x82,0x74,0x82,0x75,0x82,0x76,0x82,0x77,0x82,0x78,0x82,0x79,0x81,0xE7,0x81,0xE8,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_9F4[14] = {0x53,0x6D,0x61,0x6C,0x6C,0x20,0x4C,0x65,0x74,0x74,0x65,0x72,0x73,0x00};
const u8 lbl_8_rodata_A04[60] = {0x82,0x81,0x82,0x82,0x82,0x83,0x82,0x84,0x82,0x85,0x82,0x86,0x82,0x87,0x82,0x88,0x82,0x89,0x82,0x8A,0x82,0x8B,0x82,0x8C,0x82,0x8D,0x82,0x8E,0x82,0x8F,0x82,0x90,0x82,0x91,0x82,0x92,0x82,0x93,0x82,0x94,0x82,0x95,0x82,0x96,0x82,0x97,0x82,0x98,0x82,0x99,0x82,0x9A,0x81,0xE7,0x81,0xE8,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_A40[6] = {0x53,0x69,0x67,0x6E,0x73,0x00};
const u8 lbl_8_rodata_A48[68] = {0x81,0x43,0x81,0x44,0x81,0x48,0x81,0x49,0x81,0x7B,0x81,0x7C,0x81,0x5E,0x81,0x5F,0x81,0x81,0x81,0x83,0x81,0x84,0x81,0x46,0x81,0x47,0x81,0x4C,0x81,0x4D,0x81,0x4F,0x81,0x51,0x81,0x62,0x81,0x69,0x81,0x6A,0x81,0x6D,0x81,0x6E,0x81,0x6F,0x81,0x70,0x81,0x90,0x81,0x93,0x81,0x94,0x81,0x95,0x81,0x96,0x81,0x97,0x81,0xE7,0x81,0xE8,0x00,0x00,0x00,0x00};
const u8 lbl_8_rodata_A8C[8] = {0x4E,0x75,0x6D,0x62,0x65,0x72,0x73,0x00};
const u8 lbl_8_rodata_A94[100] = {0x82,0x4F,0x82,0x50,0x82,0x51,0x82,0x52,0x82,0x53,0x82,0x54,0x82,0x55,0x82,0x56,0x82,0x57,0x82,0x58,0x81,0xE7,0x81,0xE8,0x00,0x00,0x00,0x00,0x3F,0xCA,0xE1,0x47,0xAE,0x14,0x7A,0xE1,0x3F,0xFA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAB,0x3F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x42,0x40,0x00,0x00,0x3E,0x80,0x00,0x00,0x3F,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x05,0x1E,0xB8,0x00,0x00,0x00,0x00,0x3F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xD5,0x55,0x55,0x3D,0x80,0x00,0x00};
const u8 lbl_8_rodata_AF8[8] = {0x43,0x30,0x00,0x00,0x80,0x00,0x00,0x00};
const u8 lbl_8_rodata_B00[8] = {0x43,0x30,0x00,0x00,0x00,0x00,0x00,0x00};
const f32 lbl_8_rodata_B00__fzgx_offset_8[1] = {32.0f};
const f32 lbl_8_rodata_B00__fzgx_offset_C[1] = {24.0f};
const f32 lbl_8_rodata_B00__fzgx_offset_10[1] = {18.0f};
const u8 lbl_8_rodata_B00__fzgx_offset_14[76] = {0xFF,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0x41,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xC9,0x99,0x99,0x99,0x99,0x99,0x9A,0x40,0x28,0x00,0x00,0x00,0x00,0x00,0x00,0x41,0x21,0x99,0x9A,0x00,0x00,0x00,0x00,0x40,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x80,0x00,0x00,0x41,0x20,0x00,0x00};
extern s32 fn_1_45D0(u32, u32, u32, u32);
extern u32 fn_800793D4(u32, s32, u32);
extern void fn_1_435C(u32);
extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern void fn_1_47F74(s32);
extern void fn_1_411A4(u32);
extern void fn_1_A2D84(u32);
extern u32 fn_8_E440();
extern void fn_8_EFA4(void);
extern u32 fn_8_DD64();

typedef struct { u16 cleared; u16 code; const u8 *text[4]; } NameEntryOption;
NameEntryOption fzgx_obj_lbl_8_data_A1E8[4] __attribute__((aligned(8))) = {
    {0, 64, {lbl_8_rodata_410, lbl_8_rodata_494, 0, lbl_8_rodata_408}},
    {0, 38, {lbl_8_rodata_520, 0, 0, lbl_8_rodata_518}},
    {0, 85, {lbl_8_rodata_57C, lbl_8_rodata_628, lbl_8_rodata_6D4, lbl_8_rodata_570}},
    {0, 88, {lbl_8_rodata_78C, lbl_8_rodata_840, lbl_8_rodata_8F4, lbl_8_rodata_780}},
};
NameEntryOption lbl_8_data_A1E8__fzgx_offset_50[4] = {
    {0, 28, {lbl_8_rodata_9B8, 0, 0, lbl_8_rodata_9A8}},
    {0, 28, {lbl_8_rodata_A04, 0, 0, lbl_8_rodata_9F4}},
    {0, 32, {lbl_8_rodata_A48, 0, 0, lbl_8_rodata_A40}},
    {0, 12, {lbl_8_rodata_A94, 0, 0, lbl_8_rodata_A8C}},
};
u8 fzgx_obj_lbl_8_data_A288[64] = "name_entry.c\000\000\000\000\201@\000\000\201\347\000\000%s\201@\201@\201@%s\000\000\201\350\000"
    "\000name_entry_fixed_letter";
u8 fzgx_obj_lbl_8_data_A2C8[24] = "\226\274\221O\202\360\223\374\202\352\202\304\202\255\202\276\202\263\202\242\201B\000";
u8 fzgx_obj_lbl_8_data_A2E0[56] = "Please enter your name.  \000\000\000\203G\203t\203[\203\215\000\000\000\000\202e\201|\202y\202d"
    "\202q\202n\000\000\000";
u8 lbl_8_data_A2E0__fzgx_offset_38[16] = "name_entry_main";
u8 lbl_8_data_A2E0__fzgx_offset_48[24] = "name_entry_disp_main\000\000\000";
u8 lbl_8_data_A2E0__fzgx_offset_60[16] = "name_entry_line";
Obj *fzgx_obj_lbl_8_bss_550;
u8 fzgx_obj_lbl_8_bss_554;
u8 fzgx_obj_lbl_8_bss_555;
#pragma section code_type ".fzgxpool"
static void name_entry_data_layout(void) {
    const void *volatile sink; /* fzgx-allow: S2 discarded measured section-layout primer */
    sink = &fzgx_obj_lbl_8_data_A1E8;
    sink = &fzgx_obj_lbl_8_data_A288;
    sink = &fzgx_obj_lbl_8_data_A2C8;
    sink = &fzgx_obj_lbl_8_data_A2E0;
}
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void name_entry_rodata_layout(void) {
    const void *volatile sink; /* fzgx-allow: S2 discarded measured section-layout primer */
    sink = &lbl_8_rodata_408;
    sink = &lbl_8_rodata_410;
    sink = &lbl_8_rodata_494;
    sink = &lbl_8_rodata_518;
    sink = &lbl_8_rodata_520;
    sink = &lbl_8_rodata_570;
    sink = &lbl_8_rodata_57C;
    sink = &lbl_8_rodata_628;
    sink = &lbl_8_rodata_6D4;
    sink = &lbl_8_rodata_780;
    sink = &lbl_8_rodata_78C;
    sink = &lbl_8_rodata_840;
    sink = &lbl_8_rodata_8F4;
    sink = &lbl_8_rodata_9A8;
    sink = &lbl_8_rodata_9B8;
    sink = &lbl_8_rodata_9F4;
    sink = &lbl_8_rodata_A04;
    sink = &lbl_8_rodata_A40;
    sink = &lbl_8_rodata_A48;
    sink = &lbl_8_rodata_A8C;
    sink = &lbl_8_rodata_A94;
    sink = &lbl_8_rodata_AF8;
    sink = &lbl_8_rodata_B00;
    sink = &lbl_8_rodata_B00__fzgx_offset_8;
    sink = &lbl_8_rodata_B00__fzgx_offset_C;
    sink = &lbl_8_rodata_B00__fzgx_offset_10;
    sink = &lbl_8_rodata_B00__fzgx_offset_14;
}
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void name_entry_bss_layout(void) {
    const void *volatile sink; /* fzgx-allow: S2 discarded measured section-layout primer */
    sink = &fzgx_obj_lbl_8_bss_550;
    sink = &fzgx_obj_lbl_8_bss_554;
    sink = &fzgx_obj_lbl_8_bss_555;
}
#pragma section code_type ".text"

static inline void clear_name_entry_flag(void) {
    u16 *flag;
    u32 index = 0;
    flag = (u16 *)fzgx_obj_lbl_8_bss_550->unk_3c;
    while (index < fzgx_obj_lbl_8_bss_550->unk_3b) {
        *flag = 0;
        index++;
    }
}
#pragma opt_common_subs off
#pragma opt_loop_invariants off

void fn_8_F9E4(u32 arg0, u32 arg1, u8 arg2) {
    Node *n;
    u32 i;

    fzgx_obj_lbl_8_bss_550 = (Obj *)fn_1_45D0(lbl_801A6410, 0x40, (u32)fzgx_obj_lbl_8_data_A288, 0x4ef);
    fn_800793D4((u32)fzgx_obj_lbl_8_bss_550, 0, 0x40);
    fzgx_obj_lbl_8_bss_550->unk_4 = arg0;
    fzgx_obj_lbl_8_bss_550->unk_8 = arg1;
    fn_1_435C(arg0);
    fzgx_obj_lbl_8_bss_550->unk_18 = fn_1_3F8C((u32)lbl_8_data_A2E0__fzgx_offset_38, (u32)&fn_8_E440, 0, 0xa);
    fn_1_47F74(0x8f);
    if (lbl_1_bss_960 != 1) {
        fn_1_47F74(0x9a);
        fn_1_47F74(0x9e);
        fn_1_411A4(1);
    }
    fn_1_435C(arg1);
    fzgx_obj_lbl_8_bss_550->unk_1c = fn_1_3F8C((u32)lbl_8_data_A2E0__fzgx_offset_48, (u32)&fn_8_EFA4, 0, 0xa);
    if (lbl_801A66B4 == 5) {
        fzgx_obj_lbl_8_bss_550->unk_3c = (u32)fzgx_obj_lbl_8_data_A1E8;
        fzgx_obj_lbl_8_bss_550->unk_3b = 4;
    } else {
        fzgx_obj_lbl_8_bss_550->unk_3c = (u32)lbl_8_data_A1E8__fzgx_offset_50;
        fzgx_obj_lbl_8_bss_550->unk_3b = 4;
    }
    for (i = 0; i < fzgx_obj_lbl_8_bss_550->unk_3b; i++) {
        n = (Node *)fn_1_45D0(lbl_801A6410, 0xc, (u32)fzgx_obj_lbl_8_data_A288, 0x1a5);
        fn_800793D4((u32)n, 0, 0xc);
        n->unk_0 = i;
        switch ((u8)i) {
        case 0:
            n->unk_4 = 0xb2;
            n->unk_8 = lbl_8_rodata_B00__fzgx_offset_8[0];
            break;
        case 1:
            n->unk_4 = 0x114;
            n->unk_8 = lbl_8_rodata_B00__fzgx_offset_C[0];
            break;
        case 2:
            n->unk_4 = 0x139;
            n->unk_8 = lbl_8_rodata_B00__fzgx_offset_10[0];
            break;
        case 3:
            n->unk_4 = 0x54;
            n->unk_8 = lbl_8_rodata_B00__fzgx_offset_C[0];
            break;
        }
        fn_1_3F8C((u32)lbl_8_data_A2E0__fzgx_offset_60, (u32)&fn_8_DD64, (u32)n, 0xb);
    }
    fzgx_obj_lbl_8_bss_550->unk_c = arg2;
    clear_name_entry_flag();
    fzgx_obj_lbl_8_bss_550->unk_12 = 0x62;
    fn_1_A2D84(0xa9100000);
    fzgx_obj_lbl_8_bss_554 = 0;
    fzgx_obj_lbl_8_bss_555 = 0;
}

#pragma opt_loop_invariants reset
#pragma opt_common_subs reset

#pragma opt_common_subs reset
#pragma opt_loop_invariants reset
/* fzgx:end fn_8_F9E4 */

/* fzgx:begin fn_8_FC5C */
#include "rel/title/operation.h"

extern u32 fn_1_435C(u32);
extern s32 fn_1_45D0(u32, u32, u8 *, u32);
extern s32 fn_1_3F8C(u8 *, u32, u32, u32);
extern void fn_1_A2D84(u32);
extern void strcpy(u8 *, u32);
extern void fn_8_D630(void);
struct fn_8_FC5C_lbl_801A6410 {
    u32 unk_0;
};
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    u16 unk_A;
    u8 unk_C;
    u8 pad_D[0x3];
    u32 unk_10;
} Entry_4_D420;
typedef struct { u32 v; } Word;

#pragma opt_loop_invariants off
#pragma opt_lifetimes off
s32 fn_8_FC5C(void) {
    s32 bit;
    u8 *src;
    s32 i;
    struct { u8 value; } k;
    struct { s32 value; } n;
    s32 res;
    u8 *src2;
    u8 *data;
    Entry_4_D420 *t;
    Word c;
    Word c2;

    res = 0;
    data = lbl_8_data_A1E8;
    if ((lbl_8_bss_550->unk_0 >> 30) & 1) {
        c = *(Word *)&lbl_8_rodata_C28;
        fn_1_435C(lbl_8_bss_550->unk_8);
        n.value = 0;
        i = 0;
        while (src = (u8 *)lbl_8_bss_550 + 0x28 + i, src[0] != 0) {
            t = (Entry_4_D420 *)fn_1_45D0((*(struct fn_8_FC5C_lbl_801A6410 *)&lbl_801A6410).unk_0, 0x12, ((0xA0) + data), 0xD4);
            t->unk_8 = (u8)n.value * 0x38 + 0x7E;
            t->unk_A = 0x17A;
            t->unk_0 = 2;
            t->unk_1 = 0;
            t->unk_4 = t->unk_8;
            t->unk_6 = t->unk_A;
            t->unk_2 = src[0];
            t->unk_3 = src[1];
            *(u32 *)((u8 *)t + 0xD) = c.v;
            t->unk_C = n.value;
            fn_1_3F8C(data + 0xC8, (u32)&fn_8_D630, (u32)t, 0xB);
            i += 2;
            n.value += 1;
        }
        c2.v = lbl_8_bss_550->unk_0;
        /* Retail reloads the target pointer after reading its flags. */
        (*(Obj_8_bss_550_Target * *)&lbl_8_bss_550)->unk_0 = c2.v & ~0x40000000;
    }
    if (lbl_8_bss_550->unk_0 >> 31) {
        return 1;
    }
    if (((lbl_8_bss_550->unk_0 >> 29) & 1) || ((lbl_8_bss_550->unk_0 >> 28) & 1)) {
        fn_1_A2D84(0xA9010100);
        lbl_8_bss_550->unk_0 &= ~0x20000000;
        lbl_8_bss_550->unk_0 &= ~0x10000000;
        lbl_8_bss_550->unk_0 |= 0x80000000;
        if (fn_1_14CEB8((u32)lbl_8_bss_550 + 0x28) != 0) {
            bit = 0;
            lbl_8_bss_550->unk_0 |= 0x40000000;
            while (((u8 *)lbl_8_bss_550)[0x28 + bit * 2] != 0) {
                lbl_8_bss_550->unk_20 |= 0x80000000 >> bit;
                bit++;
            }
        }
        if (((u8 *)lbl_8_bss_550)[0x28] == 0) {
            if (lbl_801A66B4 == 5) {
                strcpy((u8 *)lbl_8_bss_550 + 0x28, (u32)(data + 0x114));
            } else {
                strcpy((u8 *)lbl_8_bss_550 + 0x28, (u32)(data + 0x120));
            }
            c2 = *(Word *)&lbl_8_rodata_C24;
            fn_1_435C(lbl_8_bss_550->unk_8);
            n.value = 0;
            while (src2 = (u8 *)lbl_8_bss_550 + 0x28 + n.value * 2, src2[0] != 0) {
                k.value = n.value;
                t = (Entry_4_D420 *)fn_1_45D0((*(struct fn_8_FC5C_lbl_801A6410 *)&lbl_801A6410).unk_0, 0x12, ((0xA0) + data), 0xD4);
                t->unk_8 = k.value * 0x38 + 0x7E;
                t->unk_A = 0x17A;
                t->unk_0 = 2;
                t->unk_1 = 0;
                t->unk_4 = t->unk_8;
                t->unk_6 = t->unk_A;
                t->unk_2 = src2[0];
                t->unk_3 = src2[1];
                *(u32 *)((u8 *)t + 0xD) = c2.v;
                t->unk_C = k.value;
                fn_1_3F8C(data + 0xC8, (u32)&fn_8_D630, (u32)t, 0xB);
                n.value += 1;
            }
            lbl_8_bss_550->unk_E = n.value;
        }
        res = 1;
    }
    return res;
}
#pragma opt_lifetimes reset

#pragma opt_loop_invariants reset
/* fzgx:end fn_8_FC5C */
