/* Non-matching: best partial attempt (11.33% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

extern u8 lbl_1_rodata_8A5C[156];
extern f32 lbl_1_rodata_26F8[22];
extern const f64 lbl_1_rodata_8600;
extern const f64 lbl_1_rodata_8608;
extern const f32 lbl_1_rodata_86C4;
extern const f32 lbl_1_rodata_87DC;
extern const f32 lbl_1_rodata_8B28;
extern const f32 lbl_1_rodata_8B2C;
extern const f32 lbl_1_rodata_8B30;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_8664;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_85F4;
extern const f32 lbl_1_rodata_8808;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8B34;
extern const f32 lbl_1_rodata_8B38;
extern const f32 lbl_1_rodata_8B3C;
extern const f32 lbl_1_rodata_8B40;
extern u32 lbl_1_rodata_8AF8[6];
extern u32 lbl_1_rodata_8B10[6];
extern u32 lbl_801A66A0;
extern u32 lbl_801A66B4;
extern f32 lbl_8006D188(u32);
extern int fn_1_4F734(FontDrawPacket *);
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern void fn_1_1392E0(void *, void *);
extern int fn_1_139A3C(int);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);

typedef struct { u32 w[22]; } Packet;
typedef struct {
 u8 pad0[4]; f32 a; f32 b; f32 c; f32 d; f32 e; f32 f; f32 g; f32 h; f32 i; f32 j; f32 k; f32 l;
} Config;
void fn_1_1375C0(u32 arg0, void *arg1, void *arg2, u32 arg3, void *arg4) {
 u32 copyA[39];
 Packet p;
 Packet q;
 s32 count;
 s32 i;
 s32 x = (s32)arg1;
 s32 y = (s32)arg2;
 s32 mode = (s32)arg4;
 f32 angle;
 f32 scale;
 Config *cfg;
 Packet small;
 Packet text;
 Packet wide;
 Packet arr;
 s32 idx;
 f32 temp;
 f32 rate;
 u32 select;
 s32 row;
 s32 val;
 u32 colors[12];
 f32 x1;
 f32 y1;
 f32 x2;
 f32 y2;
 u32 *src;
 (void)arg3;
 {
  typedef struct { u32 words[39]; } Copy156;
  Copy156 *dst = (void *)copyA;
  Copy156 *src0 = (void *)lbl_1_rodata_8A5C;
  *dst = *src0;
 }
 cfg=(Config *)(copyA + 1) + arg0;
 small = *(Packet *)lbl_1_rodata_26F8;
 {
  struct { u32 header; u32 type; f32 x,y,z; } *v=(void *)&small;
  f64 dx=(f64)y-lbl_1_rodata_8600;
  f64 dy=(f64)x-lbl_1_rodata_8600;
  v->type=*((u32 *)cfg);
  v->x=(f32)dy+cfg->a;
  v->y=(f32)dx+cfg->b;
  v->z=lbl_1_rodata_86C4;
  fn_1_4F734((FontDrawPacket *)((u8 *)&small+4));
 }
 for(i=0;i<22;i++) q.w[i]=((u32 *)lbl_1_rodata_26F8)[i];
 {
  struct {u32 type; f32 x,y,z;} *v=(void *)&p;
  f32 xx=(f32)x-lbl_1_rodata_8600;
  f32 yy=(f32)y-lbl_1_rodata_8600;
  v->type=18;
  v->x=xx+cfg->c;
  v->y=yy+cfg->d;
  v->z=lbl_1_rodata_87DC;
  fn_1_48690((u32)&p);
 }
 idx=fn_1_48690((u32)&p);
 temp=((f32)idx-lbl_1_rodata_8608);
 p.w[4]=p.w[4];
 fn_1_486C4((u32)&p);
 fn_1_1392E0((void *)&copyA[0],(void *)&p);
 if(lbl_1_bss_8B3A0.unk_94 & 2) mode=0;
 if(fn_1_139A3C((s16)mode)) angle=lbl_1_rodata_861C;
 else {
  u32 ticks=lbl_801A66A0;
  u32 sec=ticks/60;
  f32 z=lbl_8006D188((s32)(lbl_1_rodata_8B2C*(f32)(ticks-sec*60)/lbl_1_rodata_8B30));
  angle=lbl_1_rodata_8808+lbl_1_rodata_8664*(lbl_1_rodata_863C+z)*lbl_1_rodata_85F0;
 }
 count=100-lbl_1_bss_8B3A0.unk_9F;
 temp=(f32)count*lbl_1_rodata_8B28/lbl_1_rodata_85F4;
 scale=((f32)y-lbl_1_rodata_8600)*cfg->d;
 x1=(f32)x-lbl_1_rodata_8600;
 y1=(f32)mode-lbl_1_rodata_8600;
 small.w[0]=0;
 small.w[1]=0;
 small.w[2]=0;
 small.w[3]=0;
 fn_1_4F734((FontDrawPacket *)&p);
 if ((f32)mode < (f32)x + cfg->d + lbl_1_rodata_8B28) fn_1_4F734((FontDrawPacket *)&p);
 if ((f32)mode > (f32)x + cfg->d + cfg->l - lbl_1_rodata_8638) fn_1_4F734((FontDrawPacket *)&p);
 fn_1_486C4((u32)&p);
 if(arg0) {
  ((f32 *)&p)[1] = angle;
  ((f32 *)&p)[2] = scale;
  fn_1_4F734((FontDrawPacket *)&p);
  fn_1_49410();
  fn_1_494DC(4);
  fn_1_4966C(lbl_1_rodata_8B40,lbl_1_rodata_861C);
  fn_1_496FC((f32)x-lbl_1_rodata_8600+cfg->k,(f32)y-lbl_1_rodata_8600+cfg->l);
  fn_1_4A0D8((const char *)lbl_1_data_41AF8);
 }
}
