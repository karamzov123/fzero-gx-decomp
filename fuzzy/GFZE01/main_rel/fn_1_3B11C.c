/* Non-matching: best partial attempt (44.75% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/game.h"
typedef struct { u8 pad[0x2c]; u32 flags; u8 pad34[0x14c8]; s16 mode; u8 p14fe[2]; u32 file; u8 p1504[0x2f0]; u16 count; } State;
typedef struct { u32 word; } Word;
typedef struct { u8 pad[0x32c]; u8 value; } Obj;
extern u8 lbl_1_bss_3C00;
extern u32 lbl_1_bss_7F04C;
extern u8 lbl_1_data_5B84, lbl_1_bss_8E51D;
extern u16 lbl_1_bss_960;
extern u8 lbl_1_data_1A2B4[];
extern u16 lbl_1_rodata_DBDC[];
extern u32 lbl_1_rodata_E54[];
extern void *fn_1_435C(void *);
extern void fn_1_8D988(void), fn_1_A0C68(void), fn_1_14A17C(void), fn_1_F7578(void), fn_1_F37F4(void), fn_1_F2EDC(void), fn_1_F7308(void), fn_1_D0790(void), fn_1_3F2A0(void), fn_1_469BC(void);
extern void fn_1_156754(s32), fn_1_5370(s32,s32), fn_1_426C(u32), fn_1_1280(u32), fn_1_49F0(u32 *), fn_1_4A00(s32,u8,void *), fn_1_8DBA4(u8), fn_1_4068C(u32), fn_1_31C3C(u32), fn_1_F9F2C(u8,u8,u8,u8), fn_1_4811C(int), fn_1_48004(s32,s32);
extern u32 fn_1_F2F58(void), fn_1_3FC9C(void), fn_1_485A8(s32), fn_1_8623C(void), fn_1_86900(u32);
extern s16 fn_1_12C930(s16);
extern struct { u32 unk[0x2000]; } *unused;
void fn_1_3B11C(void) {
 u8 *b=&lbl_1_bss_3C00, *s=b+0x30, *manager=b+0x20000, *mgr3=b+0x30000;
 u32 f, x; s32 i,j; u8 n;
 fn_1_435C(*(void **)(manager+0x1f88)); fn_1_8D988(); fn_1_5370(1,*(s16 *)(b+0x14fc)); fn_1_A0C68(); fn_1_14A17C();
 for(i=0;i<4;i++) fn_1_156754(i);
 fn_1_F7578();
 f=*(u32 *)(b+0x30);
 if(f&0x100000){*(u32 *)(b+0x30)=f&~0x100000; *(u8 *)(mgr3+0x45f4)=1;} else *(u8 *)(mgr3+0x45f4)=0;
 f=*(u32 *)(b+0x30);
 if(f&0x800000){
   extern Obj_1_bss_7EFD8 lbl_1_bss_7EFD8;
   if(lbl_1_bss_7EFD8.unk_40){
     if(fn_1_F2F58()) fn_1_F37F4();
     fn_1_426C((u32)lbl_1_bss_7EFD8.unk_40);
     lbl_1_bss_7EFD8.unk_40=0;
   }
   fn_1_F2EDC();
 }
 if(lbl_1_bss_7F04C){fn_1_435C(*(void **)(manager+0x1f88)); fn_1_426C(lbl_1_bss_7F04C); fn_1_F7308(); lbl_1_bss_7F04C=0;}
 *(u32 *)(manager+0x2f14)=0; fn_1_D0790(); fn_1_1280(0); fn_1_49F0(lbl_1_rodata_E54); fn_1_4A00(1,30,*(void **)(b+0x1500));
 f=*(u32 *)(b+0x30); *(u32 *)(b+4)=0; f|=0x1000; *(u32 *)(b+0x30)=f;
 if(f&0x800){
   if(b[0x10]){
     if(!*(u32 *)(manager+0x1fa0)){
       u8 *entry=s, *ids, *slots; u8 num; s32 mode=s[5]; *(u16 *)(b+0x17f4)=s[7]; n=s[8];
       for(i=0;i<n;i++,entry+=0xa0) if(*(u32 *)(entry+0x1480)) {
         if(f&0x400000) break;
         fn_1_3F2A0();
         ids=entry+0x163c; slots=b+0x165c; num=n;
         if(*(s16 *)(b+0x2a)<=41) {
           for(j=0;j<num;j++) { u8 ix=entry[0x157+j*0xa0], val=ids[j]; slots[ix*8+4]=entry[0x154+j*0xa0]; slots[ix*8+6]=val; slots[0x194+ix]=(u8)j; }
         } else {
           for(j=0;j<num;j++) { u8 ix=entry[0xdc+j*0xa0], val=ids[j]; slots[ix*8+4]=entry[0x154+j*0xa0]; slots[ix*8+6]=val; slots[0x194+ix]=(u8)j; }
         }
         f=*(u32 *)(b+0x30); f|=0x400000; *(u32 *)(b+0x30)=f;
         slots[0x192]=n; slots[0x191]|=2; slots[0x190]=s[7]; *(u16 *)(b+0x17f4)=14;
         break;
       }
     }
     fn_1_4A00(0,30,*(void **)(b+0x1500));
     lbl_1_bss_6EAB4.unk_0|=0x2c; *(u32 *)(manager+0x1fa0)=1;
     if(s[5]==0) lbl_1_data_5B84=1;
     fn_1_469BC(); fn_1_8DBA4(0);
   } else {
     b[0x1504]=0xff; lbl_1_bss_8E51D=8; *(u32 *)(s+0xc4)=0;
     fn_1_4068C((u32)(b+0x1508)); b[0x150b]&=0xfe;
   }
 } else if(!(f&0x4000000)) {
   u8 mode=s[5];
   if(mode==0) {
     u8 *cursor=s; u16 *values=lbl_1_rodata_DBDC;
     for(i=0;i<s[9];i++,cursor++,values++) {
       u8 ix=cursor[14];
       *(u32 *)(s+0x1480+ix*4)+=*values;
       if(i==0) ++*(u16 *)(s+0x1478+ix*2);
       s+0; s[ix*0xa0+0xd4+9]=*values;
     }
   }
   if(mode==6){if(s[9]<=4) lbl_1_bss_8E51D=3;}
   else if(mode==2) fn_1_31C3C(0);
   else if(mode==5) lbl_1_bss_8E51D=9;
   else if(mode==1) { u8 result=(u8)fn_1_3FC9C(); fn_1_F9F2C(s[0x156],result,(u8)(s[0xa6]-1),s[0xa7]); }
 }
 if(lbl_1_bss_960!=10 && lbl_1_bss_960!=12 && !fn_1_485A8(151)){ s32 q=(s32)fn_1_8623C(); u32 z=fn_1_86900((s8)q); if(!z) z=(u32)fn_1_86900(0); fn_1_4811C(148); fn_1_48004(151,1); fn_1_48004(153,1); fn_1_48004(*(u32 *)(lbl_1_data_1A2B4+4*(u16)fn_1_12C930((s8)((Obj *)z)->value)),1); }
 fn_1_8DBA4(0); f=*(u32 *)(b+0x30); *(u8 *)(mgr3+0x4600)= f&0x800 ? 0 : 60;
}
