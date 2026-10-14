/* Non-matching: best partial attempt (83.82% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/ghost.h"
typedef struct { u16 x,y,z; } Sig_fn_1_983CC_Fn1983CCVec3;
typedef struct {
    u8 lab_pad[8];
 u8 unk_00[3]; s8 unk_03; u8 unk_04[0x3c]; s8 unk_40; u8 unk_41[3];
 Sig_fn_1_983CC_Fn1983CCVec3 unk_44,unk_50;
 f32 unk_5C,unk_60,unk_64,unk_68,unk_6C,unk_70,unk_74;
} Sig_fn_1_983CC_Fn1983CCEntry;
struct fn_1_F23E8_lbl_1_bss_7B180 {
 u8 pad_0[0x1600]; s32 unk_1600;
 u8 pad_1604[0x10]; u32 unk_1614;
 u8 pad_1618[0x10]; u32 unk_1628;
 u8 pad_162C[0x10]; u32 unk_163C;
 u8 pad_1640[0x88]; u32 unk_16C8;
 u8 pad_16CC[0x20]; u32 unk_16EC;
 u8 pad_16F0[0x10]; u32 unk_1700;
 u8 pad_1704[0x10]; u32 unk_1714;
 u8 pad_1718[0x10]; u32 unk_1728;
 u8 pad_172C[0x68]; u32 unk_1794;
 u8 pad_1798[0x8c]; u32 unk_1824;
 u8 pad_1828[0x23b0]; u32 unk_3BD8;
};
extern const f32 lbl_1_rodata_6B60;
extern const f32 lbl_1_rodata_6BBC, lbl_1_rodata_6BD0, lbl_1_rodata_6C90;
extern const f32 lbl_1_rodata_6D3C, lbl_1_rodata_6D40, lbl_1_rodata_6D54;
extern f32 lbl_1_rodata_6D58[2];
extern f32 fn_1_F4E3C(s32,f32*,f32*,f32*,f32);
extern void fn_1_F5458(void*,u32,f32,f32*,void*);
extern void fn_1_56298(f32,f32,f32,f32);
extern void fn_1_5621C(f32,f32,f32,f32);
extern void fn_80074A60(u32,u32);
extern void mathutil_mtxA_from_quat(void*);
extern void lbl_8006DB74(void*);
extern void lbl_8006D7DC(void*);
extern void lbl_8006DCA4(void);
extern void lbl_8006E0A4(void*);
extern void lbl_8006E0B4(f32,f32,f32);
extern void lbl_8006DFC4(void*);
extern void fn_80072558(void);
extern void fn_1_55FF0(f32);
extern void fn_1_556B8(void*);
extern void fn_80074A6C(void);
extern void lbl_8006D758(void);
extern void fn_1_98634(f32);
extern void fn_1_983CC(void*,Sig_fn_1_983CC_Fn1983CCEntry*);
#pragma opt_propagation off
static inline f32 fn_1_F23E8_call_fn_1_F4E3C(f64 a4, f32* a3, f32* a2, f32* a1, u32 a0) { return fn_1_F4E3C(a0, a1, a2, a3, a4); }
static inline f32 *fn_1_F23E8_array_read(f32 *array) { return array; }
#pragma opt_dead_assignments off
static inline void fn_1_F23E8_call_lbl_8006D7DC(void* a0) { lbl_8006D7DC(a0); }
void fn_1_F23E8(f32 arg0) {
 struct fn_1_F23E8_lbl_1_bss_7B180 *p_lbl_1_bss_7B180;
 u32 v0;
 f32 v1;
 f32 v2;
 u32 v10;
 void *v4;
 void * v7_2;
 f32 v5;
 void *v6;
 void *v7;
 void *v8;
 f32 v3;
 void *v11;
 void *v12;
 u32 v13;
 struct { u32 a[12]; } loc_24;
 u32 v0_2;
 struct { u32 a[4]; } loc_14;
 struct LocalVec { f32 x,y,z; } loc_8;
    f32 lab_t4;
 p_lbl_1_bss_7B180 = (struct fn_1_F23E8_lbl_1_bss_7B180 *)&lbl_1_bss_7B180;
 if ((s16)lbl_1_bss_960 == 9 && (s32)p_lbl_1_bss_7B180->unk_16C8 != -1) {
 fn_1_F5458(&loc_14,p_lbl_1_bss_7B180->unk_1824,(*(const f32 volatile *)&lbl_1_rodata_6B60) /* Retail reloads this object. */,(f32*)p_lbl_1_bss_7B180->unk_1600,(void*)p_lbl_1_bss_7B180->unk_1728);
 lab_t4 = (*(const f32 volatile *)&lbl_1_rodata_6B60) /* Retail reloads this object. */;
 loc_8.x = fn_1_F4E3C(p_lbl_1_bss_7B180->unk_1824, (f32*)p_lbl_1_bss_7B180->unk_1600, (f32*)p_lbl_1_bss_7B180->unk_1614, (f32*)p_lbl_1_bss_7B180->unk_16EC, lab_t4);
 lab_t4 = (*(const f32 volatile *)&lbl_1_rodata_6B60) /* Retail reloads this object. */;
 loc_8.y = fn_1_F23E8_call_fn_1_F4E3C(lab_t4, (f32*)p_lbl_1_bss_7B180->unk_1700, (f32*)p_lbl_1_bss_7B180->unk_1628, (f32*)p_lbl_1_bss_7B180->unk_1600, p_lbl_1_bss_7B180->unk_1824);
 lab_t4 = (f32)(*(const f32 volatile *)&lbl_1_rodata_6B60) /* Retail reloads this object. */;
 loc_8.z = fn_1_F4E3C(p_lbl_1_bss_7B180->unk_1824, (f32*)p_lbl_1_bss_7B180->unk_1600, (f32*)p_lbl_1_bss_7B180->unk_163C, (f32*)p_lbl_1_bss_7B180->unk_1714, lab_t4);
 v0 = p_lbl_1_bss_7B180->unk_3BD8;
 if ((s32)v0 > 180 && (s32)v0 < 300) {
 v2 = (f32)((s32)v0 - 180) / lbl_1_rodata_6D54;
 v3 = v2*v2;
 v2 *= fn_1_F23E8_array_read(lbl_1_rodata_6D58)[0];
 } else if ((s32)v0 >= 300) {
 v2 = fn_1_F23E8_array_read(lbl_1_rodata_6D58)[0]; v3 = lbl_1_rodata_6BD0;
 } else {
 v2 = (*(const f32 volatile *)&lbl_1_rodata_6B60) /* Retail reloads this object. */; v3 = v2;
 }
 v1=(*(const f32 volatile *)&lbl_1_rodata_6B60) /* Retail reloads this object. */; fn_1_56298(v1,v1,v1,v1);
 v1=lbl_1_rodata_6BD0; fn_1_5621C(v1,v1,v1,v1);
 fn_80074A60(4,1);
 mathutil_mtxA_from_quat(&loc_14);
 lbl_8006DB74(&loc_24);
 v4=(u8*)p_lbl_1_bss_7B180+0x19c8;
 *(u32*)((u8*)v4+0x6a0)=*(u32*)&loc_8.y;
 v0_2=*(u32*)&loc_8.x;
 v5=*(f32*)((u8*)v4+0x6a0);
 *(u32*)((u8*)v4+0x69c)=v0_2;
 *(u32*)((u8*)v4+0x6a4)=*(u32*)&loc_8.z;
 *(f32*)((u8*)v4+0x6a0)=v5+v2;
 v6=(u8*)v4+0x69c;
 fn_1_F23E8_call_lbl_8006D7DC(v6);
 v7=(u8*)p_lbl_1_bss_7B180+0x19c8;
 v7_2=(u8*)v7_2+0x76c;
 lbl_8006DB74(v7_2);
 v8=(u8*)p_lbl_1_bss_7B180+0x19c8;
 v1=lbl_1_rodata_6D3C*v3;
 *(f32*)((u8*)v8+0x844)=v1;
 *(f32*)((u8*)v8+0x820)=lbl_1_rodata_6D40*v3;
 lbl_8006DCA4();
 lbl_8006E0A4(&loc_8);
 v1=(*(const f32 volatile *)&lbl_1_rodata_6B60) /* Retail reloads this object. */; lbl_8006E0B4(v1,v2,v1);
 lbl_8006DFC4(&loc_24);
 fn_80072558();
 fn_1_55FF0(lbl_1_rodata_6BBC*v3);
 v0_2=p_lbl_1_bss_7B180->unk_1794;
 v0_2=*(u32*)((u8*)v0_2+0x334);
 v0_2=*(u32*)v0_2;
 fn_1_556B8((void*)v0_2);
 fn_1_55FF0(lbl_1_rodata_6BD0);
 fn_80074A6C();
 if ((s32)p_lbl_1_bss_7B180->unk_3BD8==0) {
 *(s16*)((u8*)v8+0x624)=-2;
 v10=p_lbl_1_bss_7B180->unk_1794;
 if(v10) *(s16*)((u8*)v8+0x626)=*(s8*)((u8*)v10+0x328);
 v11=(u8*)p_lbl_1_bss_7B180+0x19c8;
 v11=(u8*)v11+0x620;
 *(u32*)v11=0x400;
 *(struct LocalVec*)v6=loc_8;
 lbl_8006D758();
 lbl_8006DB74((u8*)p_lbl_1_bss_7B180+0x19c8+0x70c);
 v12=(u8*)p_lbl_1_bss_7B180+0x19c8;
 *(u8*)((u8*)v12+0xa95)=0;
 *(f32*)((u8*)v8+0x844)=lbl_1_rodata_6D3C;
 *(f32*)((u8*)v8+0x820)=lbl_1_rodata_6D40;
 lbl_8006D7DC(&loc_8);
 lbl_8006DB74(v7_2);
 fn_1_98634(lbl_1_rodata_6C90);
 fn_1_983CC(v11,(Sig_fn_1_983CC_Fn1983CCEntry*)p_lbl_1_bss_7B180->unk_1794);
 fn_1_98634((*(const f32 volatile *)&lbl_1_rodata_6B60) /* Retail reloads this object. */);
 }
 v13=p_lbl_1_bss_7B180->unk_3BD8;
 p_lbl_1_bss_7B180->unk_3BD8=v13+1;
 }
}
#pragma opt_dead_assignments reset

