#include "types.h"
#include "rel/profile/data/lbl_16_data_0.h"
struct State {
u8 pad0[12]; s16 index; u8 padE[2];
f32 a,b,c,d,e,f; s16 g,h; u32 i; s16 selection; u8 pad32[0x1A]; u32 flags; s16 j,k,l; u8 pad56[6]; s32 slot;
};
struct Entry {
u8 pad0[0x324]; s32 handle; u8 pad328[0x10]; void *objects[5][3]; u8 pad374[8]; u32 items[49];
};
struct Params { s16 a,b; u32 c; u8 d; u8 pad[23]; };
extern struct State lbl_1_bss_8B614;
extern u8 lbl_16_bss_220[44608];
extern u32 lbl_16_bss_150, lbl_16_bss_B0B4, lbl_16_bss_21C;
extern const f32 lbl_16_rodata_0[18];
extern void fn_16_6B24(void);
extern u32 fn_1_435C(u32);
extern void fn_1_4A00(s32,u8,u32);
extern s32 fn_1_3F8C(void *,void (*)(void),u32,u32);
extern s32 fn_1_80CC4(s32,s32,s32,void *);
extern void fn_80008BEC(void *,int,u32);
extern void fn_1_12AB38(void *);
extern void fn_1_80270(void *,void *);
extern void fn_800713E0(void *,u32);
extern void fn_1_8019C(void *);
extern void fn_1_47F74(s32);
#pragma opt_common_subs off
#pragma opt_propagation off
void fn_16_1D18(void) {
struct State *state;
u8 *data;
struct Entry *entry;
s16 index;
s32 offset;
struct Params params;
const f32 *pool = lbl_16_rodata_0;
data = (u8 *)&lbl_16_data_0 + 0x80000;
fn_1_435C(lbl_16_bss_150);
fn_1_4A00(1,15,lbl_16_bss_150);
lbl_16_bss_B0B4=0;
*(s32 *)(data+0x2B00)=fn_1_3F8C(data+0x2D84,fn_16_6B24,0,8);
state=(struct State *)&lbl_1_bss_8B614;
index=state->index;
lbl_16_bss_21C=-1;
state->a=pool[0];
state->b=pool[16];
state->c=pool[17];
state->d=pool[0];
state->e=pool[16];
state->f=pool[0];
state->g=330;
state->h=330;
offset=index*0x440;
entry=(struct Entry *)(lbl_16_bss_220+offset);
((struct Entry *)(lbl_16_bss_220+offset))->handle=(s16)fn_1_80CC4(index,0,0,entry);
fn_80008BEC(&params,0,32);
params.b=index;
params.c=0;
params.d=15;
params.a=index;
fn_1_12AB38(data+0x2D24);
fn_1_80270(&params,entry);
fn_1_12AB38(data+0x2D30);
{
struct State *second = (struct State *)&lbl_1_bss_8B614;
s32 off = state->index*0x440;
u8 *objects = lbl_16_bss_220+0x338;
fn_800713E0(*(void **)(objects+off+second->slot*12),((struct Entry *)(lbl_16_bss_220+off))->items[second->selection]);
fn_1_8019C(*(void **)(objects+state->index*0x440+second->slot*12));
}
{
s32 *handles = (s32 *)(data+0x2B54);
fn_1_47F74(handles[state->index]);
}
lbl_1_bss_8B614.flags=0;
lbl_1_bss_8B614.flags|=0x80000000;
lbl_1_bss_8B614.flags|=0x10000000;
lbl_1_bss_8B614.j=1;
lbl_1_bss_8B614.k=0;
lbl_1_bss_8B614.l=15;
lbl_1_bss_8B614.i=0;
}
