/* Non-matching: best partial attempt (24.97% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"

extern s16 fn_1_3F0C8(void);
extern u8 lbl_1_bss_6F59C[36];
extern void fn_1_862D4(void *, void *);
extern s32 camera_compare_values(const u8 *, const u8 *);
extern u8 lbl_1_bss_6F2C4;
extern u32 lbl_1_bss_6F2C8[4];
extern u32 fn_1_864E8(void *);
extern u32 fn_1_A3D5C(void *, void *, void *, void *);
extern f32 fn_1_86544(s32);
extern u32 fn_1_3FC48(void);
extern const f32 lbl_1_rodata_1AC, lbl_1_rodata_1E8, lbl_1_rodata_1EC;
extern const f32 lbl_1_rodata_1F0, lbl_1_rodata_194, lbl_1_rodata_1F4;
extern u32 fn_1_A47F4(u32, u32, u32, void *, void *);
extern u32 fn_1_A4268(void *, u32, u32, u32);
extern u32 fn_1_A3654(void *, u32);
extern void fn_1_A358C(void *);
extern void fn_1_A2DF4(s32, void *, s32);
extern u32 fn_1_86514(int);
extern f32 fn_1_8652C(void *);
extern const f32 lbl_1_rodata_1F8;
extern void fn_1_A2D84(u32);
typedef struct { u8 pad[0x68]; f32 unk_68; u8 pad70[0x0C]; u32 unk_7C; u8 pad80[0x98]; u32 unk_118; } CameraTransform;
typedef struct { u8 pad[0x49c]; CameraTransform *unk_49C; } CameraCamera;
extern CameraCamera *fn_1_86254(void *);
typedef CameraTransform CameraTarget;
extern void fn_1_A4BC8(void *, void *, CameraTarget *);
extern void fn_1_3EF14(void *);
extern const f32 lbl_1_rodata_1FC;
extern const f64 lbl_1_rodata_1E0;
extern s32 fn_80067344(u32, u32, u32, u32);
extern void qsort(void *, size_t, size_t, int (*)(const void *, const void *));
extern Obj_1_bss_F68_Target *lbl_1_bss_F68;
extern Obj_1_bss_6F1E4 lbl_1_bss_6F1E4;
extern Obj_1_bss_6F524 lbl_1_bss_6F524;
extern Obj_1_data_35C8 lbl_1_data_35C8;
extern u32 lbl_801A66C8;

void fn_1_739C(void * arg0, u32 arg1, u32 arg2) {
    s16 status = fn_1_3F0C8();
    Obj_1_bss_F68_Target **mgr = &lbl_1_bss_F68;
    Obj_1_bss_6F1E4 *entries = &lbl_1_bss_6F1E4;
    u8 *order = lbl_1_bss_6F59C;
    u8 *rank = (u8 *)&lbl_1_bss_6F1E4;
    u8 max = (u8)arg1;
    u8 limit = (u8)arg2;
    u8 count = (u8)arg2;
    u8 kind = 0, current = 0, idx = 0;
    s16 player = -1;
    s32 mode = 0, cursor = 0, slot = 0, n = 0;
    s32 flag = 0;
    f32 distance;
    u8 a,b,c, va,vb,vc,vd;
    if (status == 0x27) return;
    {
        void *obj = *(void **)mgr;
        if (obj && !(*(u32 *)obj & 1))
            player = ((u8 *)obj)[0x4A];
        if (obj && !(*(u32 *)obj & 1)) {
            s8 type = ((u8 *)obj)[0x48];
            if (type >= 9 && type < 0xB) player = ((s16 *)((u8 *)(*mgr)->unk_50))[3];
            else if (type != 0xB) {
                s16 p = *(s16 *)((u8 *)(*mgr)->unk_54 + (player * 0x1FC) + 2);
                player = p;
            } else player = -1;
        }
    }
    if (player == 0xFF) player = -1;
    {
      void *obj = *(void **)mgr;
      if (!obj) kind=0;
      else if (((u8 *)obj)[0x48] == 0xB) kind=1;
      else if (*(u32 *)obj & 1) kind=1;
      else kind=((u8 *)obj)[0x49];
    }
    if ((u8)limit > max) count=max;
    order[0]=0;
    for (n=0;n<(s8)limit;n++) {
      order[n]=(u8)n;
      {
        f32 p[3];
        fn_1_862D4((void *)((u8 *)arg0), p);
        distance=(p[0]-((f32 *)arg0)[0])*(p[0]-((f32 *)arg0)[0])+
                 (p[1]-((f32 *)arg0)[1])*(p[1]-((f32 *)arg0)[1])+
                 (p[2]-((f32 *)arg0)[2])*(p[2]-((f32 *)arg0)[2]);
        ((f32 *)&lbl_1_bss_6F524)[n]=distance;
      }
    }
    qsort(order, limit, 1, (int (*)(const void *, const void *))camera_compare_values);
    if (count > 4) count=4;
    lbl_1_bss_6F2C4=count;
    if (kind==1) {
      if (count==1) { idx=0; flag=0; }
      else if (count<4) { idx=count-1; flag=1; }
      else {idx=3; flag=1;}
    } else if (kind==2) {
      if (count==2) {idx=0;flag=0;}
      else if (count<4) { if (((u8 *)*(void **)mgr)[0x4A]==1) {idx=1;flag=3;} else {idx=0;flag=0;} }
      else {idx=1;flag=((u8 *)*(void **)mgr)[0x4A]+2;}
    } else {idx=0;flag=0;}
    {
      Obj_1_bss_6F1E4 *e=entries+((u8 *)*(void **)mgr)[0x4A]*0x14;
      for (cursor=0; cursor<(s8)limit; cursor++) {
        u8 car=order[cursor];
        if (car != (u8)player) {
          u32 bits=fn_1_864E8((void *)(s32)player);
          u8 out0=0,out1=0,out2=0;
          u32 model=fn_1_A3D5C((void *)(s32)player,&out0,&out1,&out2);
          u8 target=fn_1_86544(player);
          distance=target;
          if (status==0x28 && !fn_1_3FC48()) {
            if (kind==1) distance*=lbl_1_rodata_1AC;
            else if (kind==2) distance*=lbl_1_rodata_1E8;
            else if (kind==3) distance*=lbl_1_rodata_1EC;
          }
          distance*=lbl_1_rodata_1F0;
          if (distance<lbl_1_rodata_194) distance=lbl_1_rodata_194;
          else if (distance>lbl_1_rodata_1F4) distance=lbl_1_rodata_1F4;
          va=(u8)distance;
          if (car != e->unk_1) {e->unk_1=car;e->unk_0|=3;} else e->unk_0 &= ~2;
          e->unk_C=((f32 *)&lbl_1_bss_6F524)[car];
          e->unk_2=out2; e->unk_4=out0; e->unk_5=out1; e->unk_A=(u8)target;
          if(e->unk_0&2) { int d=(s8)(e->unk_6-va); if(d>4)e->unk_6+=4;else if(d< -4)e->unk_6-=4; }
          else {e->unk_0 &= ~4; e->unk_6=va;}
          fn_1_A47F4(((u8 *)*(void **)mgr)[0x4A],va,((u8 *)*(void **)mgr)[0x4A],&a,&b);
          if(out2) {fn_80067344(1,16,0xb027,0);fn_80067344(1,16,0xb02a,(s8)out0);}
          fn_1_A3654((void *)(s32)player,car); fn_1_A358C((void *)(s32)player);
          (void)bits;(void)model;
        }
      }
    }
    {
      for (cursor=0; cursor<(s8)limit; cursor++) {
        u8 car=order[cursor];
        if (car!=(u8)player) {
          u8 oa=0,ob=0,oc=0;
          s32 pct=(s32)((f32)car*((f32 *)((u8 *)&lbl_1_data_35C8))[idx]);
          u32 attr=fn_1_A3D5C((void *)(s32)car,&oa,&ob,&oc);
          f32 speed=fn_1_86544(car);
          if(status==0x28 && !fn_1_3FC48()) {
            if(kind==1) speed*=lbl_1_rodata_1AC;
            else if(kind==2) speed*=lbl_1_rodata_1E8;
            else if(kind==3) speed*=lbl_1_rodata_1EC;
          }
          speed*=lbl_1_rodata_1F0;
          if(speed<lbl_1_rodata_194) speed=lbl_1_rodata_194;
          else if(speed>lbl_1_rodata_1F4) speed=lbl_1_rodata_1F4;
          vb=(u8)speed;
          fn_1_A47F4(idx,vb,((u8 *)*(void **)mgr)[0x4A],&a,&b);
          fn_1_A3654((void *)(s32)car,idx);
          fn_1_A358C((void *)(s32)car);
          {
            CameraCamera *cam=fn_1_86254((void *)(s32)car);
            CameraTarget *t=cam->unk_49C;
            if(t) {
              fn_1_A4BC8((void *)(s32)car,(void *)(s32)idx,t);
              if(kind<2 && t->unk_7C&0x140 && !(t->unk_7C&1)) {
                f32 x=t->unk_68;
                fn_1_3EF14(&a);
                x*=lbl_1_rodata_1FC;
                va=(u8)x;
                fn_80067344(1,16,0xb02d,va);
                fn_1_A2DF4(0,(void *)0xa540,va);
              } else {
                fn_1_A2DF4(0,(void *)0xa540,0);
              }
              if(oc) fn_1_A2D84(0xa90a700);
            }
          }
          entries[car].unk_C=((f32 *)&lbl_1_bss_6F524)[car];
          lbl_1_bss_6F2C8[idx]=attr;
          (void)pct;
        }
      }
    }
}
