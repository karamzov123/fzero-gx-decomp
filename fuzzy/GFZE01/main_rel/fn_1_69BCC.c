/* Non-matching: best partial attempt (19.06% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/effect_car.h"

typedef struct { f32 x,y,z; } Vec;
typedef struct { u8 pad[0xB4]; u16 flags; } ObjFlags;
extern f32 lbl_1_rodata_2D70[];
extern void *fn_1_868C0(s8);
extern u32 fn_1_864E8(int);
extern u32 fn_1_58C4(void);
extern void fn_1_681C(u32, Vec *);
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D668(void *);
extern void *fn_1_E54A8(s16,s16);
extern s16 fn_1_E5430(s16);
extern u32 fn_1_584AC(void);
extern void fn_1_862D4(int, void *);
extern void fn_1_8636C(int, void *);
extern s16 fn_1_58F50(const void *);
extern void *fn_1_86254(int);
extern s16 camera_get_entry_field_0xa4(u32);
extern u32 fn_1_6E140(void *, void *, f32);
extern u32 fn_1_A2FC8(int, f32);
extern u32 lbl_8006DBAC(void *);
extern void *lbl_8006E1F0(void *, f32, f32, f32);
extern u32 fn_1_6CF3C(void *, void *, f32, f32);
extern u8 *memset(u8 *, int, u32);

typedef struct { u8 pad[0x18]; s16 id; u8 pad2[0x1e]; u32 *cfg; f32 pos[3]; } Obj;

void fn_1_69BCC(Obj *o) {
    u32 *cfg = o->cfg;
    Vec p, q;
    f32 dist, radius;
    u32 i, j;
    u8 n;
    u8 data0[0xE8], data1[0xE8];
    u8 data2[0xE8], data3[0xE8];
    u8 buffer[0xE8];
    Vec v;
    f32 t;
    if (cfg == 0) return;
    if (((*(u32 *)((u8 *)fn_1_868C0((s8)o->id) + 0x390) & 0x1000000) != 0)) return;
    p.x=o->pos[0]; p.y=o->pos[1]; p.z=o->pos[2];
    o->pos[0]=*(f32 *)((u8 *)cfg+0x18);
    o->pos[1]=*(f32 *)((u8 *)cfg+0x1c);
    o->pos[2]=*(f32 *)((u8 *)cfg+0x20);
    n=fn_1_58C4();
    fn_1_681C(0,&q);
    dist=lbl_8006D0B4((o->pos[0]-q.x)*(o->pos[0]-q.x)+(o->pos[1]-q.y)*(o->pos[1]-q.y)+(o->pos[2]-q.z)*(o->pos[2]-q.z));
    for(i=1;i<n;i++) {
      fn_1_681C(i,&q);
      t=lbl_8006D0B4((o->pos[0]-q.x)*(o->pos[0]-q.x)+(o->pos[1]-q.y)*(o->pos[1]-q.y)+(o->pos[2]-q.z)*(o->pos[2]-q.z));
      if(dist>=t) dist=lbl_8006D0B4((o->pos[0]-q.x)*(o->pos[0]-q.x)+(o->pos[1]-q.y)*(o->pos[1]-q.y)+(o->pos[2]-q.z)*(o->pos[2]-q.z));
    }
    if(dist>lbl_1_rodata_2D70[0xb8/4]) return;
    if(fn_1_864E8(o->id)&0x1000000) return;
    p.x=*(f32 *)((u8 *)cfg+0x24); p.y=*(f32 *)((u8 *)cfg+0x28); p.z=*(f32 *)((u8 *)cfg+0x2c);
    radius=lbl_8006D668(&p)*lbl_1_rodata_2D70[0xbc/4];
    q.x=o->pos[0]-p.x; q.y=o->pos[1]-p.y; q.z=o->pos[2]-p.z;
    dist=lbl_8006D0B4(q.x*q.x+q.y*q.y+q.z*q.z);
    if (((u16 *)o)[0x59]&1) {
      i=*(u32 *)((u8 *)o+0x14);
      if(i) { *(u32 *)((u8 *)o+0x14)=i-1; if(radius>=lbl_1_rodata_2D70[0xc0/4]) goto clearflag; }
      else if(radius<lbl_1_rodata_2D70[0x7c/4] || dist<lbl_1_rodata_2D70[0x94/4]) goto clearflag;
    } else {
      i=*(u32 *)((u8 *)o+0x14); if(i) *(u32 *)((u8 *)o+0x14)=i-1;
      if(radius>0 && dist>0 && (fn_1_864E8(o->id)&0x800000)) {
        i=*(u32 *)((u8 *)o+0x14);
        ((u16 *)o)[0x59]|=i?1:3; *(u32 *)((u8 *)o+0x14)=30;
      } else if(dist>0) {
        for(i=0;i<6;i++) for(j=0;j<(u16)fn_1_E5430(i);j++) {
          u32 *x=fn_1_E54A8(i,j);
          if (((x[0x138/4]&0x400) || x[0x13c/4]) ) {
            ((u16 *)o)[0x59]|=*(u32 *)((u8 *)o+0x14)?1:3;
            *(u32 *)((u8 *)o+0x14)=30;
            x[0x13c/4]&=~0u; x[0x138/4]&=~0x400;
          }
        }
      }
    }
    goto done;
clearflag:
    ((u16 *)o)[0x59]&=~3;
done:
    if (((u16 *)o)[0x59]&1) {
      memset(buffer,0,0xe8);
      *(u16 *)(buffer+12)=5; *(u16 *)(buffer+24)=o->id; *(u16 *)(buffer+26)=1;
      *(u32 *)(buffer+8)|=0x8000;
    }
}
