/* Non-matching: best partial attempt (94.88% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/memcard.h"
extern f32 lbl_1_rodata_4AE0[];
extern s32 lbl_801A66B4;
struct ro_pool {
u8 pad_0[0x1E0]; f32 f_1E0; u8 pad_1E4[0x10];
u32 w_1F4,w_1F8,w_1FC,w_200; f32 f_204;
u32 w_208,w_20C,w_210,w_214,w_218,w_21C,w_220,w_224,w_228;
f32 f_22C,f_230,f_234,f_238,f_23C,f_240,f_244,f_248,f_24C,f_250,f_254,f_258,f_25C,f_260;
};
extern u32 fn_80007F70(void *,void *,u32,f32);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495C8(u8);
extern void fn_1_4954C(f32);
extern void fn_1_49514(u32 *);
extern void fn_1_49614(void);
extern void fn_1_4955C(f32,f32);
extern void fn_1_4966C(f32,f32);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_496FC(f32,f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4D494(void);
extern void fn_1_4AE0C(const char *,...);
extern u32 fn_1_4D4C8(void *,f32,f32);
extern void fn_1_49528(u32 *);
extern void fn_1_495FC(void);
extern void fn_1_495A0(f32);
#pragma opt_propagation off
struct rowmap { u8 pad[0x2A0]; u32 title; u8 pad2[0xD4]; u32 first; u8 pad3[0x14]; u32 second; };
static inline struct rowmap *row_pointer(u8 *base, s32 *index) {
u8 *table = base + 0x5C84;
return (struct rowmap *)(table + (*index << 2));
}
#define row_value(base,index,offset) (*(u32 *)((u8 *)row_pointer(base,index) + offset))
struct selection { u8 pad[0x2A]; u8 value; };
static inline int selected(struct selection *state, u32 bit) {
u32 value = state->value;
return ((value << bit) | (value >> (32-bit))) & 1;
}
#pragma opt_propagation reset
#pragma opt_dead_assignments off
#pragma opt_propagation off
#pragma opt_common_subs off
void fn_1_B5310(void) {
struct ro_pool *r=(struct ro_pool *)&lbl_1_rodata_4AE0;
u8 *d=(u8 *)&lbl_1_data_35AC8;
u8 *b=(u8 *)&lbl_1_bss_716C0;
volatile u32 res;
u32 arg_hi,arg_lo;
u32 tmp0,tmp1,tmp2,tmp3,tmp4,tmp5,tmp6,tmp7,tmp8,tmp9,tmp10;
volatile u32 res_sel;
u32 sel_d,sel_c,sel_b,sel_a;
f32 v;
arg_lo=r->w_20C; arg_hi=r->w_208;
res=fn_80007F70(&arg_hi,&arg_lo,*(u32 *)(b+0x148),r->f_1E0);
fn_1_49410(); fn_1_494DC(42); fn_1_495C8(9); fn_1_4954C(r->f_22C);
tmp0=r->w_210; fn_1_49514(&tmp0); fn_1_49614();
v=r->f_230; fn_1_4955C(v,v); fn_1_4966C(r->f_234,r->f_238);
if(lbl_801A66B4!=5) {fn_1_495B0(0x80000000); fn_1_49590(r->f_23C);fn_1_4966C(r->f_234,r->f_240);}
fn_1_496FC(r->f_244,r->f_248);
fn_1_4A0D8((const char *)row_value(d,&lbl_801A66B4,0x2A0));
{
struct selection *flags = (struct selection *)(b + 0x150);
u32 bit = 0;
if(selected(flags,bit)) {
sel_b=r->w_1F8; sel_a=r->w_1F4;
res_sel=fn_80007F70(&sel_a,&sel_b,*(u32 *)(b+0x148),r->f_204);
} else {
sel_d=r->w_200;sel_c=r->w_1FC;
res_sel=fn_80007F70(&sel_c,&sel_d,*(u32 *)(b+0x148),r->f_1E0);
}
}
fn_1_496FC(r->f_24C,r->f_250);fn_1_495C8(10);
if(b[0x1F2]==0) {
fn_1_4D494();tmp1=res_sel;fn_1_49514(&tmp1);
fn_1_4AE0C((const char *)(d+0x7318),row_value(d,&lbl_801A66B4,0x378));
tmp2=res;fn_1_4D4C8(&tmp2,r->f_254,r->f_204);
} else {
tmp3=r->w_214;fn_1_49514(&tmp3);tmp4=r->w_218;fn_1_49528(&tmp4);
fn_1_4AE0C((const char *)(d+0x7318),row_value(d,&lbl_801A66B4,0x378));
}
fn_1_496FC(r->f_258,r->f_250);fn_1_495C8(8);
if(b[0x1F2]==0) {
tmp5=r->w_21C;fn_1_49514(&tmp5);tmp6=r->w_220;fn_1_49528(&tmp6);
fn_1_4AE0C((const char *)(d+0x7318),row_value(d,&lbl_801A66B4,0x390));
} else {
fn_1_4D494();tmp7=res_sel;fn_1_49514(&tmp7);
fn_1_4AE0C((const char *)(d+0x7318),row_value(d,&lbl_801A66B4,0x390));
tmp8=res;fn_1_4D4C8(&tmp8,r->f_254,r->f_204);
}
tmp9=r->w_224;fn_1_49514(&tmp9);tmp10=r->w_228;fn_1_49528(&tmp10);
fn_1_495C8(9);fn_1_495FC();fn_1_496FC(r->f_244,r->f_25C);fn_1_495A0(r->f_260);
fn_1_4A0D8((const char *)(d+0x731C));fn_1_49410();
}
#pragma opt_dead_assignments reset
