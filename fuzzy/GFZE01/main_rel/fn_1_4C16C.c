/* Non-matching: best partial attempt (38.12% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"

extern f32 lbl_1_rodata_FD0[];
extern void fn_1_A8EB0(int, int);
extern void fn_1_A8DD4(const char *, ...);
extern void fn_1_A8E78(int);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4AE0C(const char *, ...);
extern f32 fn_1_519FC(f32);
extern f32 fn_1_51AC0(f32);
extern f32 fn_1_51B84(f32);
extern f32 fn_1_51BFC(f32);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_4E500(void);
extern u32 fn_1_48D80(u32);
extern void fn_1_4E6F4(void);
extern s32 fn_1_4E724(void *);
extern u8 lbl_1_bss_4BB30[];
extern u8 lbl_1_data_1A3B8[];
extern u8 lbl_1_bss_4B9CC[];
extern u8 lbl_1_bss_4BA30[];
extern u32 lbl_1_bss_40BBC[];

typedef struct {
 f32 x,y,z; s16 id, row; u32 a,b; f32 c,d,e,f,g; u32 flags;
 u16 h,i,j; u8 k,l; f32 o,p,q; u8 r,s,t,u; s16 v,w,X,Y; f32 z2; u32 zz,aa;
} Packet;

void fn_1_4C16C(void) {
 u8 *g=lbl_1_bss_4BB30, *d=lbl_1_data_1A3B8;
 u8 *inf=d+0xaf0+(s8)g[0]*0x38;
 Packet *p=(Packet*)lbl_1_bss_4B9CC;
 f32 *ro=lbl_1_rodata_FD0;
 int rows,cols,i;
 if (*(s32*)inf==-1) { rows=16; cols=8; }
 else { rows=(s8)inf[0x10]; cols=(s8)inf[0x11]; }
 fn_1_A8EB0(1,3);
 if (*(s32*)inf==-1)
  fn_1_A8DD4((char*)d+0x2070,*(u32*)(d+0x180c+(s8)g[0]*4),*(u32*)(d+0x18f4+(s8)g[3]*4),(s8)g[3],5);
 else fn_1_A8DD4((char*)d+0x2084,*(u32*)(d+0x180c+(s8)g[0]*4));
 fn_1_A8E78((int)(d+0x208c)); fn_1_A8E78((int)(d+0x2090));
 if (*(s32*)inf==-1) fn_1_A8E78((int)(d+0x20a0));
 fn_1_A8E78((int)(d+0x20b4));
 if (*(s32*)inf==-1) { fn_1_A8E78((int)(d+0x20cc)); fn_1_A8E78((int)(d+0x20e4)); }
 p->id=42; p->row=(s8)g[0]; p->a=*(u32*)(ro+0x118/4); p->b=*(u32*)(ro+0x11c/4);
 p->c=ro[0x120/4]; p->d=1.0f; p->e=1.0f; p->f=1.0f; p->g=1.0f;
 p->flags=0; p->k=0; p->h=0; p->i=2; p->j=2; p->o=0.75f; p->l=g[3];
 p->p=0.0f; p->q=0.0f; p->r=1; p->s=0; p->z2=0.0f; p->zz=0;
 p->t=0;p->u=0;p->v=0;p->w=0;p->X=640;p->Y=480;p->aa=5;
 p->d=ro[0x104/4]*(*(f32*)(inf+0x34)); p->e=p->d;
 p->y=ro[0x16d8/4]-(f32)(*(f32*)(inf+0x34)*(f32)(s32)(inf[4]*rows)*ro[0x169c/4]);
 p->x=p->y; p->z=ro[0x16dc/4];
 if ((s8)g[2]) p->flags=0x80000000;
 p->l=g[3];
 if (*(s32*)inf==-1) {
  int total=rows*cols, n=0, off=0, idx, *tmp=(int*)lbl_1_bss_4BA30;
  u16 *ids=(u16*)(u32)*(u32*)(inf+0x2c);
  tmp[0]=1; *(f32*)((u8*)tmp+4)=ro[0x16ac/4]; *(f32*)((u8*)tmp+8)=0; *(f32*)((u8*)tmp+12)=ro[0x16b0/4]; *(f32*)((u8*)tmp+16)=0;
  while (*ids) {
   int lim=(s8)g[4]*total;
   if (n>=lim && n<lim+total) {
    u8 text[2]; text[0]=(*ids)>>8; text[1]=*ids;
    p->a=*(u32*)(ro+0x16b4/4);
    for(i=0;i<0x56b;i++) if (*ids==*(u16*)(d+i*2)) p->a=*(u32*)(ro+0x16b8/4);
    if (*(s32*)(g+8)==n) p->a=*(u32*)(ro+0x16bc/4);
    if (*(s16*)(*(u32*)(inf+0x30)+off)==-1) {
     fn_1_4A0D8((char*)d+0x1d14);
     p->row=(s8)g[0]; p->d=*(f32*)(inf+0x34); p->e=p->d;
    } else fn_1_4A0D8((char*)text);
    if (n%rows==rows-1) fn_1_4A0D8((char*)d+0x208c);
    p->a=*(u32*)(ro+0x16c0/4);
   }
   off+=2; n++; ids++;
  }
  p->flags &= 0x7fffffff; tmp[0]=0;
  idx=*(s32*)(g+8);
  if (*(s16*)(*(u32*)(inf+0x30)+idx*2)!=-1) {
   u16 val=*(u16*)(*(u32*)(inf+0x2c)+idx*2); u8 text[2]; text[0]=val>>8; text[1]=val;
   p->d=12; p->x=150; p->y=150; p->p=2.0f*(*(f32*)(d+0xaf0+p->row*0x38+0x34)); p->e=p->p;
   fn_1_4A0D8((char*)text);
  }
  p->row=3; p->d=12; p->e=12; p->x=(s8)(inf[5]*2+162); p->y=p->x;
  p->z=(f32)(s32)(inf[5]*2+162);
  fn_1_4AE0C((char*)d+0x20f8,*(u16*)(*(u32*)(inf+0x2c)+(*(s32*)(g+8)*2)));
  if (*(s16*)(*(u32*)(inf+0x30)+(*(s32*)(g+8)*2))==-1) fn_1_4A0D8((char*)d+0x20fc);
  else fn_1_4AE0C((char*)d+0x210c);
  fn_1_4AE0C((char*)d+0x2118,(s8)g[4],(s32)lbl_1_bss_40BBC[(s8)g[0]]/total);
 } else {
  int row=*(s32*)(inf+8), last=rows-1, n=0;
  while(row<*(s32*)(inf+12)+1) {
   if (*(s32*)(g+8)==row) p->a=*(u32*)(ro+0x16c4/4);
   if(row==0) {
    u8 text[88]; int w=*(s32*)(d+0xaf0+p->row*0x38+8), div=(-w)/(s8)*(u8*)(d+0xaf0+p->row*0x38+16);
    p->b=*(u32*)(ro+0x16c8/4);
    text[0]=0;
    if(p->s) p->flags|=0x400;
    if(p->s) p->aa=p->s;
    if(p->s) { fn_1_4E500(); }
    p->d=fn_1_519FC(p->d); p->e=fn_1_51AC0(p->e);
    p->d=fn_1_51B84(p->d); p->e=fn_1_51BFC(p->e);
    if(p->u) fn_1_4F734((FontDrawPacket*)((u8*)&text+4));
    else if(p->t) fn_1_4E724((void*)&text);
    else { fn_1_48D80(0); fn_1_4E6F4(); }
    fn_1_4A0D8((char*)d+0x1cfc);
   } else if(row==10) {
    u8 text[88]; p->a=*(u32*)(ro+0x16cc/4);
    if(p->s) p->flags|=0x400;
    if(p->s) p->aa=p->s;
    p->d=fn_1_519FC(p->d); p->e=fn_1_51AC0(p->e);
    p->d=fn_1_51B84(p->d); p->e=fn_1_51BFC(p->e);
    if(p->u) fn_1_4F734((FontDrawPacket*)((u8*)&text+4));
    else fn_1_4E724((void*)&text);
    fn_1_4A0D8((char*)d+0x1cfc);
   } else { *(u8*)(&n)=row; fn_1_4A0D8((char*)&n); }
   if(n%rows==last) fn_1_4A0D8((char*)d+0x208c);
   p->a=*(u32*)(ro+0x16d0/4); p->b=*(u32*)(ro+0x16d4/4);
   row++; n++;
  }
  p->flags &= 0x7fffffff;
  fn_1_4A0D8((char*)d+0x1cfc);
  p->row=3; p->d=12; p->e=12; p->x=(s8)(inf[5]*2+162); p->y=p->x;
  p->z=(f32)(s32)(inf[5]*2+162);
  fn_1_4AE0C((char*)d+0x2128,*(s32*)(g+8));
 }
}
