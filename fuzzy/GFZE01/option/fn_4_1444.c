/* Non-matching: best partial attempt (98.95% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dolphin/hw_regs.h"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void prime1(void) { volatile f32 s; s=167.0f; s=38.0f; s=0.5f; }
static const u32 table2[1]={0x00D0D000};
__declspec(section ".fzgxpool") static void keep2(void){const u32 *volatile cp; cp=table2;}
__declspec(section ".fzgxpool") static void prime3(void){volatile f32 s; volatile f64 d; d=78.0; d=0.125; s=2.9375f; s=0.0f; d=0.3; d=1.0;}
static const u32 table4[1]={0x00D0D000};
__declspec(section ".fzgxpool") static void keep4(void){const u32 *volatile cp; cp=table4;}
__declspec(section ".fzgxpool") static void prime5(void){volatile f32 s; s=0.6000000238418579f;}
static const u32 table6[1]={0xFF000000};
__declspec(section ".fzgxpool") static void keep6(void){const u32 *volatile cp; cp=table6;}
__declspec(section ".fzgxpool") static void prime7(void){volatile f32 s; s=3.5f; s=5.0f;}
static const u32 table8[1]={0};
__declspec(section ".fzgxpool") static void keep8(void){const u32 *volatile cp; cp=table8;}
__declspec(section ".fzgxpool") static void prime9(void){volatile f32 s; s=320.0f; s=0.15000000596046448f; s=240.0f;}
static const u32 table10[1]={0};
__declspec(section ".fzgxpool") static void keep10(void){const u32 *volatile cp; cp=table10;}
__declspec(section ".fzgxpool") static void prime11(void){volatile f32 s; volatile f64 d; d=96.0; d=48.0; s=0.25f;}
static const u32 table12[1]={0};
__declspec(section ".fzgxpool") static void keep12(void){const u32 *volatile cp; cp=table12;}
__declspec(section ".fzgxpool") static void prime13(void){volatile f32 s; volatile f64 d; d=4503599627370496.0; s=0.004999999888241291f; s=216.0f; d=90.0; d=320.0; d=0.5; s=264.0f;}
static const u32 table14[1]={0};
__declspec(section ".fzgxpool") static void keep14(void){const u32 *volatile cp; cp=table14;}
__declspec(section ".fzgxpool") static void prime15(void){volatile f32 s; volatile f64 d; d=-0.5; s=0.014999999664723873f; s=72.0f; s=0.02500000037252903f; s=0.05000000074505806f; s=48.0f; s=0.800000011920929f; s=110.0f; s=1.0f; s=120.0f;}
static const u32 table16[11]={0x08080000,0x78780000,0x06060000,0x25000000,0x1A1A0000,0x00250000,0xE61A0000,0xDB000000,0xE6E60000,0x00DB0000,0x1AE60000};
__declspec(section ".fzgxpool") static void keep16(void){const u32 *volatile cp; cp=table16;}
__declspec(section ".fzgxpool") static void prime17(void){volatile f32 s; volatile f64 d; d=4503601774854144.0; s=1.3333333730697632f; s=160.0f; s=210.0f; s=480.0f; s=-0.009999999776482582f; s=1.100000023841858f; s=1.399999976158142f; s=20.0f; s=10.0f; s=0.009999999776482582f; s=140.0f; s=0.0010000000474974513f;}
#pragma section code_type ".text"
extern s32 lbl_801A66B4;
extern void fn_1_49410(void);
extern void fn_1_495C8(u8);
extern void fn_1_49738(void (*)(void));
extern void fn_1_5233C(void);
extern void fn_1_49748(f32);
extern void fn_1_4955C(f32,f32);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern f32 fn_1_4B068(s32);
extern f32 fn_1_4B090(s32);
extern u32 fn_800371F8(u32,void *);
extern u32 fn_8003462C(u32,u32,u32);
extern void fn_800746A8(u8,s32);
extern void fn_1_496FC(f32,f32);
extern void fn_1_4A0D8(const char *);
#define FIFO(v) (*(volatile f32 *)(GX_FIFO_BASE + 0x0) = (v))
static inline f32 fn_4_1444_operand(f32 right,f32 left){return left+right;}
#pragma opt_lifetimes off
static inline f32 fn_4_1444_operand_(f32 left,f32 right){return left+right;}
#pragma opt_common_subs on
static inline f32 fn_4_1444_operand__(f32 left,f32 right){return left+right;}
void fn_4_1444(u32 arg0,s32 arg1,u32 *arg2,u32 *arg3,s32 arg4){
s32 tmp_call13; s32 tmp_call52;
f32 span_a; f32 span_b; f32 zbase; f32 ymid; f32 zpad; f32 ymax; f32 ymin; f32 line_h;
u32 id1; f32 ymid_2; u32 id2; u32 id3; u32 id4; s32 tmp_call41;
if(arg1!=0){span_a=160.0f;span_b=210.0f;}else{span_a=480.0f;span_b=210.0f;}
zbase=-0.01f*(f32)(arg0&0xFFFF);
fn_1_49410(); fn_1_495C8(1); fn_1_49738(fn_1_5233C); fn_1_49748(5.0f); fn_1_4955C(0.8f,0.8f);
if(lbl_801A66B4!=5){fn_1_495B0(0x80000000U);fn_1_49590(0.5f);}
ymax=0.5f*(fn_1_4B068(arg4)+20.0f); ymid=fn_1_4B090(arg4)+10.0f;
id1=*arg3; fn_800371F8(1,&id1); fn_8003462C(0x80,7,4);
ymid_2=(span_b-110.0f)-ymid; ymin=span_a-ymax; zpad=0.01f+zbase; ymax=span_a+ymax;
FIFO(ymin); FIFO(ymid_2); tmp_call13=FIFO(zpad); tmp_call13;
FIFO(ymax);FIFO(ymid_2);FIFO(zpad);FIFO(ymax);FIFO(span_b-110.0f);FIFO(zpad);FIFO(ymin);FIFO(span_b-110.0f);FIFO(zpad);
fn_800746A8(0xa,0); id2=*arg2; fn_800371F8(1,&id2);fn_8003462C(0xa8,7,2);
FIFO(ymin);FIFO(ymid_2);FIFO(zpad);FIFO(ymax);FIFO(ymid_2);FIFO(zpad);
fn_8003462C(0xa8,7,2);
FIFO(ymax);FIFO(ymid_2);FIFO(zpad);FIFO(ymax);FIFO(span_b-110.0f);FIFO(zpad);
fn_8003462C(0xa8,7,2);
FIFO(ymax);tmp_call41=FIFO(span_b-110.0f);tmp_call41;FIFO(zpad);FIFO(ymin);FIFO(span_b-110.0f);FIFO(zpad);
fn_8003462C(0xa8,7,2);
FIFO(ymin);FIFO(span_b-110.0f);FIFO(zpad);FIFO(ymin);FIFO(ymid_2);tmp_call52=FIFO(zpad);tmp_call52;
fn_1_496FC(span_a,5.0f+ymid_2);fn_1_4A0D8((const char *)arg4);
id3=*arg3;fn_800371F8(1,&id3);fn_8003462C(0x80,7,4);
FIFO(span_a-140.0f);
tmp_call41=*arg2;
FIFO(span_b-110.0f);FIFO(zbase-0.001f);
FIFO(fn_4_1444_operand__(span_a,140.0f));FIFO(span_b-110.0f);FIFO(zbase-0.001f);
FIFO(fn_4_1444_operand__(span_a,140.0f));FIFO(fn_4_1444_operand_(span_b,110.0f));FIFO(zbase-0.001f);
FIFO(span_a-140.0f);FIFO(fn_4_1444_operand_(span_b,110.0f));FIFO(zbase-0.001f);
id4=tmp_call41;
fn_800371F8(1,&id4);fn_8003462C(0xa8,7,2);
FIFO(span_a-140.0f);FIFO(span_b-110.0f);FIFO(zbase);FIFO(fn_4_1444_operand__(span_a,140.0f));FIFO(span_b-110.0f);FIFO(zbase);
fn_8003462C(0xa8,7,2);
FIFO(fn_4_1444_operand__(span_a,140.0f));FIFO(span_b-110.0f);FIFO(zbase);FIFO(fn_4_1444_operand__(span_a,140.0f));FIFO(fn_4_1444_operand_(span_b,110.0f));FIFO(zbase);
fn_8003462C(0xa8,7,2);
FIFO(fn_4_1444_operand(140.0f,span_a));FIFO(fn_4_1444_operand_(span_b,110.0f));FIFO(zbase);FIFO(span_a-140.0f);FIFO(fn_4_1444_operand_(span_b,110.0f));FIFO(zbase);
fn_8003462C(0xa8,7,2);
FIFO(span_a-140.0f);FIFO(fn_4_1444_operand_(span_b,110.0f));FIFO(zbase);FIFO(span_a-140.0f);FIFO(span_b-110.0f);FIFO(zbase);
}
#pragma opt_common_subs reset
#pragma opt_lifetimes reset
