/* Non-matching: best partial attempt (87.07% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/cloth.h"
extern u32 lbl_801A6410;
typedef struct { u8 bytes[0x5C]; } Info;
typedef struct { u8 pad_0[8]; u32 unk_8; u8 pad_C; u8 unk_D; u8 pad_E[0x12]; } TexEntry;
typedef struct { u8 pad_0[0x18]; u16 count; u8 pad_1A[0x26]; TexEntry entry[1]; } TexList;
typedef struct { u8 pad_0[0x30]; TexList *a; u32 unused; TexList *b; } Holder;
typedef struct { u32 unk_0; u32 unk_4; u8 pad_8[0x240]; u32 unk_248; u32 ptr_a[218]; u32 ptr_b[210]; u32 unk_8FC; u32 unk_900; u32 unk_904; u8 unk_908; u8 unk_909; u8 pad_90A[2]; u32 texptrs[210]; } ClothBs;
extern void fn_1_465D0(u8 *, s32);
extern void fn_1_451E4(void);
extern void fn_1_D3214(void);
extern s32 fn_1_467F4(void);
extern s16 fn_1_46C70(u8 *);
extern s32 fn_1_45730(char *, void *);
extern s32 fn_1_45B2C(void *);
extern s32 fn_1_45B68(void *);
extern void fn_1_45850(void *);
extern u32 fn_1_45D0(u32,u32,u8 *,u32);
extern u32 fn_1_4630(u32,u32,u8 *,u32);
extern u32 GXGetTexBufferSize(u16,u16,u32,u32,u32);
extern void GXInitTexObj(void *, void *, u16, u16, s32, s32, u64);
extern int sprintf(char *,const char *,...);
extern void OSReport(u8 *,...);
extern void OSPanic(u8 *,s32,u8 *,...);
#pragma opt_propagation off
#pragma peephole off
#pragma opt_common_subs off
static inline u32 *array_base(u32 *p) { return p; }
#pragma opt_common_subs reset
#pragma scheduling on
static inline u32 fn_1_10688C_call_fn_1_4630(u32 a0, u32 a1, u8 * a2, u32 a3) { return fn_1_4630(a0, a1, a2, a3); }
static inline u16 fn_1_10688C_array_read(u32 *array, s32 index) { return array[index]; }
void fn_1_10688C(void) {
    u32 *fzgx_value__;
    struct { u8 value; } fzgx_value_;
    u8 fzgx_value;
 char name[0x80];
 Info info;
 TexList *lists[2];
 ClothBs *bss;
 Holder *h;
 u8 *data;
 u32 *texbuf;
    u16 lab_t2;
    u32 tmp_call10;
 u32 *a,*b;
    char * lab_t0;
 s16 i,j;
 u32 grp;
 data=lbl_1_data_3F188;
 bss=(ClothBs *)&lbl_1_bss_85280;
 fn_1_465D0(data+0x1F4,3);
 while(fn_1_467F4()!=0) { fn_1_451E4(); fn_1_D3214(); }
 bss->unk_8FC=fn_1_46C70(data+0x1F4);
 bss->unk_900=0;
 a=bss->ptr_a; b=bss->ptr_b;
 for(i=0;i<0xD2;a++,b++,i++) {
 lab_t0 = name;
 sprintf(lab_t0, (const char *)(data+0x204), i+1);
 if(fn_1_45730(name,&info)==0) { OSReport(data+0x220,name); OSPanic(data+0x1C4,0x83A,data+0x22C); }
 *a=fn_1_45B2C(&info);
 *b=fn_1_45B68(&info);
 fn_1_45850(&info);
 if(bss->unk_900<*a) bss->unk_900=*a;
 }
 if(bss->unk_4!=0) OSReport(data+0x23C);
 else bss->unk_4=fn_1_45D0(lbl_801A6410,bss->unk_900,data+0x1C4,0x847);
 {
 u32 size;
 size=GXGetTexBufferSize(0x80,0x80,6,0,0);
 bss->unk_904=size;
 if(*(u32 *)(data+0xFC)!=0 || (texbuf=array_base((u32 *)(data+0xFC)))[1]!=0 || bss->unk_0!=0) OSReport(data+0x260);
 else {
 *(u32 *)(data+0xFC)=fn_1_4630(lbl_801A6410,size,data+0x1C4,0x84F);
 texbuf[1]=fn_1_10688C_call_fn_1_4630(lbl_801A6410, bss->unk_904, data+0x1C4, 0x850);
 fzgx_value__ = &(bss->unk_0);
 tmp_call10 = fn_1_4630(lbl_801A6410,0x4000,data+0x1C4,0x851);
 *fzgx_value__ = tmp_call10;
 }
 }
 h=(Holder *)lbl_1_bss_38460.unk_8->unk_8;
 fzgx_value_.value = 0;
 bss->unk_909 = fzgx_value_.value; bss->unk_909=0; bss->unk_248=1;
 lists[0]=h->a; lists[1]=h->b;
 { TexList **lp=lists;
 for(grp=0;(s32)grp<2;grp++,lp++) {
 TexList *list=*lp;
 TexEntry *entry=list->entry;
 for(j=0;j<(s32)list->count;entry++,j++) {
 if(entry->unk_D==1) {
 u32 index=bss->unk_909;
 u32 *out=array_base(bss->texptrs);
 u32 value=entry->unk_8;
 u32 *buffers=array_base((u32 *)(data+0xFC));
 u32 active=bss->unk_909;
 bss->unk_909=index+1;
 out[(u8)index]=value;
 GXInitTexObj((void *)entry->unk_8, (void *)fn_1_10688C_array_read(buffers, active), 0x80, 0x80, 6, 0, (u64)0);
 }
 }
 }
 }
}
#pragma opt_strength_reduction reset

#pragma peephole reset
