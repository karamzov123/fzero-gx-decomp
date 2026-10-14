/* Non-matching: best partial attempt (74.07% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct D5B8Item { u8 unk_0; u8 pad[5]; };
struct D5DCSub { u16 unk_0; u8 pad_2[10]; u16 unk_C; u16 unk_E; u16 unk_10; u16 unk_12; u16 unk_14; };
struct D5DCItem { u8 pad_0[0x2C]; u16 unk_2C; u8 pad_2E[0xA]; u16 unk_38; u16 unk_3A; u16 unk_3C; u16 unk_3E; u16 unk_40; u8 pad_42[0x2C]; };
struct D888Item { u32 unk_0; u32 unk_4; };
struct StatePlayer {
 s16 unk_0; u8 pad_2[2]; s16 unk_4; s16 unk_6; u8 pad_8[6]; s16 unk_E;
 u8 pad_10[4]; u8 unk_14; u8 pad_15[0xB];
};
struct State_8B3A0 {
 struct StatePlayer players[4]; u8 pad_80[0xC]; s16 unk_8C; u8 pad_8E[2];
 s16 unk_90; u8 pad_92[2]; u32 unk_94; u8 pad_98[7]; u8 unk_9F[4];
 u8 pad_A3[0x89]; s16 unk_12C; s16 unk_12E; s16 unk_130; s16 unk_132;
 s16 unk_134; s16 unk_136; s16 unk_138; s16 unk_13A; s16 unk_13C;
};
struct StackItem { u8 unk_0,unk_1,unk_2,unk_3,unk_4,unk_5; u8 unk_6[5]; u8 unk_B; };
extern struct State_8B3A0 lbl_1_bss_8B3A0;
extern struct D5B8Item lbl_1_rodata_D5B8[];
extern struct D5DCItem lbl_1_rodata_D5DC[];
extern u32 lbl_1_rodata_D870[];
extern struct D888Item lbl_1_rodata_D888[];
extern u16 lbl_1_rodata_D8B8[];
extern u32 lbl_10_data_5E4;
extern u8 fn_1_128DD8(u8);
extern void fn_1_3EF8C(u8);
extern void fn_1_3FCB0(s32);
extern void fn_1_3FCD4(u32);
extern u32 fn_1_3ED8C(u32,u32,u32,u32,u32,u32,u32);
extern void fn_1_52E0(u8);
extern void fn_1_5328(u8);
extern u8 *fn_1_36AD0(void);
extern void fn_80008BA8(void *,void *,u32);
extern u32 fn_1_3EC88(u32,void *);
extern u32 fn_1_3F4B8(u32,u32,u32,u32,u32,u32);
extern void fn_1_3F800(u32);
extern void fn_1_3F810(u8,u32);
extern void fn_1_3F834(u8);
extern void fn_1_3F844(u16);
#pragma opt_loop_invariants off
static inline u32 fn_10_D2C_array_read(u32 *array, s32 index) { return array[index]; }
#pragma opt_propagation off
void fn_10_D2C(void) {
 struct StatePlayer *fzgx_live;
 struct State_8B3A0 *state;
 u8 r31;
 struct { u32 value; } var_r24;
 u8 r23;
 struct { u8 value; } r22;
 struct { u32 value; } r25;
 u8 u;
 s16 i;
 struct StackItem items[4];
 void *lab_t1;
 r31=fn_1_128DD8((u8)lbl_1_bss_8B3A0.unk_90);
 var_r24.value=(u8)lbl_1_bss_8B3A0.unk_90;
 switch ((u16)lbl_1_bss_8B3A0.players[0].unk_0) {
 case 9: case 11: fn_1_3EF8C(6); break;
 case 0:
  fn_1_3EF8C(0);
  if(lbl_1_bss_8B3A0.players[0].unk_6>4) fn_1_3EF8C(6);
  if(lbl_1_bss_8B3A0.players[0].unk_4<2) fn_1_3EF8C(3);
  { s16 val=lbl_1_bss_8B3A0.players[0].unk_6;
   if(val<1) val=1; else if(val>4) val=4;
   lbl_1_bss_8B3A0.players[0].unk_6=val;
   val=lbl_1_bss_8B3A0.players[0].unk_4;
   if(val<1) val=1; else if(val>4) val=4;
   lbl_1_bss_8B3A0.players[0].unk_4=val;
  } break;
 case 1: fn_1_3EF8C(1); var_r24.value=(u8)lbl_1_bss_8B3A0.unk_8C; break;
 case 3:
  if(lbl_1_bss_8B3A0.unk_13A==0) fn_1_3EF8C(3);
  else { fn_1_3EF8C(6); fn_1_3FCB0(0x4000010); }
  fn_1_3FCD4(0x20000); break;
 case 2: case 4: case 5: case 6: case 7: case 8: case 10: default: fn_1_3EF8C(2); break;
 }
 state=&lbl_1_bss_8B3A0;
 r23=(u8)state->players[0].unk_6; r22.value=(u8)state->players[0].unk_4;
 if(state->unk_94&0x40000000) {
  u8 val=lbl_1_rodata_D5B8[r31].unk_0;
  fn_1_3ED8C(0,val,val,var_r24.value,10,r23,0);
 } else {
  r25.value=3;
  if(state->players[0].unk_0==0) {
   r25.value=(u8)state->unk_13C;
   if(state->unk_130==1) r23=4;
   fn_1_52E0(state->unk_134!=0);
   fn_1_5328(state->unk_12E!=0?4:3);
   if(state->unk_132==1) fn_1_3FCB0(0x20000); else fn_1_3FCD4(0x20000);
   if(state->unk_138==1) fn_1_3FCB0(0x8000); else fn_1_3FCD4(0x8000);
  } else if(state->players[0].unk_0==3) {
   r25.value=(u8)state->unk_13A; r23=(u8)(state->unk_12C+state->players[0].unk_4);
   if(state->unk_136==1) fn_1_3FCB0(0x8000); else fn_1_3FCD4(0x8000);
  }
  fn_1_3ED8C(0,r25.value,1,var_r24.value,1,r23,0);
 }
 if(state->unk_94&0x40000000) {
  for(i=0;i<=3;i++) if(lbl_1_bss_8B3A0.players[0].unk_14&(1<<i)) break;
  for(u=0;u<1;u++) {
   s8 b; s16 e=lbl_1_bss_8B3A0.players[u].unk_E; b=(s8)e;
   if(b>40) { u8 *p=fn_1_36AD0()+(u8)u*0x81C0;
    if(*(u32 *)p&0x40000000) b=(s8)(var_r24.value+50);
    else b=(s8)*(u8 *)(p+0x81A0);
   }
   items[u].unk_1=b; fzgx_live=lbl_1_bss_8B3A0.players;
   items[u].unk_2=fzgx_live[u].unk_14;
   items[u].unk_4=*(fn_1_36AD0()+(u8)u*0x81C0+8);
   items[u].unk_3=*(fn_1_36AD0()+(u8)u*0x81C0+7);
   items[u].unk_B=lbl_1_bss_8B3A0.unk_9F[u];
   fn_80008BA8(&items[u].unk_6,&lbl_10_data_5E4,5);
  }
  lab_t1=items; fn_1_3EC88(1,lab_t1);
 } else {
  for(u=0;u<4;u++) {
   s16 *pE=&lbl_1_bss_8B3A0.players[u].unk_E;
   if(*pE>40) { u8 *p; *pE=u+50; p=fn_1_36AD0()+(u8)u*0x81C0;
    if(!(*(u32 *)p&0x40000000)) *pE=*(u8 *)(p+0x81A0);
   }
   items[u].unk_1=(u8)*pE; items[u].unk_2=lbl_1_bss_8B3A0.players[u].unk_14;
   items[u].unk_B=lbl_1_bss_8B3A0.unk_9F[u];
   items[u].unk_4=*(fn_1_36AD0()+(u8)u*0x81C0+8);
   items[u].unk_3=*(fn_1_36AD0()+(u8)u*0x81C0+7);
   items[u].unk_5=0; items[u].unk_0=0;
   fn_80008BA8(&items[u].unk_6,&lbl_10_data_5E4,5);
  }
  fn_1_3EC88(r22.value,(lab_t1=items));
 }
 if(state->unk_94&0x40000000) {
  u8 idx=r31; struct D5DCItem *it=&lbl_1_rodata_D5DC[idx];
  struct D5DCSub *sub=(struct D5DCSub *)((u8 *)it+0x2C);
  fn_1_3F4B8(it->unk_2C,(u16)(it->unk_38+it->unk_40),sub->unk_E,sub->unk_10,sub->unk_12,(u8)it->unk_40);
  fn_1_3F800(fn_10_D2C_array_read(lbl_1_rodata_D870,idx));
  fn_1_3F810((u8)lbl_1_rodata_D888[idx].unk_0,lbl_1_rodata_D888[idx].unk_4);
  fn_1_3F834(r31); fn_1_3F844(lbl_1_rodata_D8B8[idx]);
 }
}
#pragma opt_propagation reset
#pragma opt_loop_invariants reset
