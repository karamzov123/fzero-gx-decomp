/* Non-matching: best partial attempt (69.96% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#pragma opt_unroll_loops off
#include "rel/main_rel/game.h"
typedef struct {
 u8 pad0[0x2A]; s16 unk_2A; u8 pad2C[4]; u32 unk_30;
 u8 pad34[0x14CC]; void *unk_1500;
 u8 pad1504[0x138]; u8 src[0x20]; u8 tab[0x198]; u16 unk_17F4;
} Obj_3C00;
typedef struct { u8 pad[4]; u8 unk_4; u8 unk_5; u8 unk_6; u8 unk_7; } Entry;
extern void fn_1_3F2A0(void);
extern void fn_1_469BC(void);
extern void fn_1_4A00(s32,u8,void *);
extern void fn_1_8DBA4(u8);
void fn_1_3E6D8(void) {
 Obj_3C00 *p = (Obj_3C00 *)&lbl_1_bss_3C00;
 u8 *q;
 Entry *entry;
 s32 count;
 s32 i,j,k,idx;
 u8 *src;
 u8 *rec;
 u8 *tab;
 if ((s32)lbl_1_bss_25BA0.unk_0 != 0) return;
 if (((lbl_1_bss_D58.unk_8 >> 8) & 1) == 0) return;
 if ((s32)lbl_1_bss_25BA0.unk_0 != 0) return;
 q = (u8 *)p + 0x30;
 p->unk_17F4 = q[7];
 if (q[5] == 0) {
  for (i=0;i<q[8];i++) {
   if (*(u32 *)(q+0x1480+i*4) == 0) continue;
   if (p->unk_30 & 0x400000) break;
   fn_1_3F2A0();
   count=q[8];
   src = (u8 *)p+0x163C;
   tab = (u8 *)p+0x165C;
   k=0;
 rec=(u8 *)q;
   if(p->unk_2A<=0x29) {
    for(j=0;j<count;j++) {
     idx=rec[0x157];
     entry=(Entry *)((u8 *)p+0x165C)+idx;
     entry->unk_4=rec[0x154];
     entry->unk_6=*src++;
     tab[idx+0x194]=k++;
     rec+=0xA0;
    }
   } else {
    for(j=0;j<count;j++) {
     idx=rec[0xDC];
     entry=(Entry *)((u8 *)p+0x165C)+idx;
     entry->unk_4=rec[0x154];
     entry->unk_6=*src++;
     tab[idx+0x194]=k++;
     rec+=0xA0;
    }
   }
   tab[0x191]|=2;
   tab[0x192]=count;
   tab[0x190]=q[7];
   p->unk_30|=0x400000;
   p->unk_17F4=14;
   break;
  }
 }
 fn_1_4A00(0,30,p->unk_1500);
 lbl_1_bss_6EAB4.unk_0 |=0x2C;
 lbl_1_bss_25BA0.unk_0=1;
 if(q[5]==0) lbl_1_data_5B84=1;
 fn_1_469BC();
 fn_1_8DBA4(0);
}
