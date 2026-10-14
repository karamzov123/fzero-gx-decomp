/* Non-matching: best partial attempt (42.97% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/effect_car.h"

typedef struct { f32 x,y,z; } Vec3;
typedef struct {
    u32 flags;
    u8 pad_4[0x10];
    f32 a[3];
    f32 b[3];
    u8 pad_2C[0xC];
    f32 n[3];
    u8 pad_44[0x18];
} Bone;
typedef struct {
    u8 pad0[0x38];
    void *rig;
    u8 pad3c[0x439];
    s8 flag475;
} Car;
typedef struct {
    u8 pad0[0x8];
    f32 pos[3];
    f32 direction[3];
    u8 pad2c[0x30];
    f32 v[3];
    u8 pad50[0x2c];
    u32 count;
    u8 rest[0x78];
} Particle;
typedef struct {
 f32 z0; f32 z4; u8 p8[0x14]; f32 half; u8 p20[4]; f32 scale; u8 p28[0x18];
 f64 bias; u8 p48[0x2c]; f32 x; f32 y; u8 p7c[0x14]; f32 noise; f32 one; u8 p98[0x20];
 f32 rate; f32 four; u8 pc0[0x10]; f64 halfd; f32 min; u8 pdc[0xc]; f32 coeff; f32 five; f32 two; f32 rate2; f32 rate3;
} Params;
extern Params lbl_1_rodata_2D70;
extern u32 lbl_801A66A0;
extern f32 lbl_1_bss_6F3A4[];
extern f32 lbl_8006D0B4(f32);
extern u32 fn_1_584AC(void);
extern u32 fn_1_58C4(void);
extern s16 fn_1_58F50(const void *);
extern void lbl_8006DD14(void *, void *);
extern void *memset(void *, int, u32);

void fn_1_6AF70(Car *car, Vec3 *dir, s32 unused) {
    u8 state[0xE8];
    f32 total = 0.0f;
    u8 *rig = (u8 *)car->rig;
    Bone *bone = (Bone *)(rig + 0x244);
    s32 i;
    lbl_8006DD14((u8 *)car + 0xb8, state - 0x30);
    if (fn_1_58C4() < 2 || *(s8 *)(rig + 0x475) == -1 ||
        lbl_801A66A0 % 5 != 0) {
      for (i = 4; i > 0; --i, ++bone) {
        f32 dx,dy,dz,dot, depth, fac, len;
        f32 p[3];
        s32 flip = 0;
        if ((bone->flags & 2) || !(bone->flags & 4)) continue;
        dx=bone->b[0]-bone->a[0]; dy=bone->b[1]-bone->a[1]; dz=bone->b[2]-bone->a[2];
        dot=dx*dir->x+dy*dir->y+dz*dir->z;
        if (dot <= 0.0f) {
          if (i != 4 && i != 2) { flip=1; dot *= -1.0f; }
        }
        depth=dot-1.0f;
        if (depth < 0.0f) continue;
        if (depth > 1.0f) depth=1.0f;
        total += depth;
        if (*(u16 *)(state+0x1a)==0) {
          memset(state,0,0xe8);
          *(s16 *)(state+0x18)=car->pad0[0]; /* replaced below */
          *(u16 *)(state+0x0c)=2; *(u16 *)(state+0x1a)=3;
          *(u32 *)(state+0x34)=((u32 *)lbl_1_bss_38458->unk_8)[0x3a];
        }
        p[0]=0.93f*dx; p[1]=0.93f*dy; p[2]=0.93f*dz;
        fac=p[0]*bone->n[0]+p[1]*bone->n[1]+p[2]*bone->n[2];
        p[0]-=fac*bone->n[0]; p[1]-=fac*bone->n[1]; p[2]-=fac*bone->n[2];
        p[0]+=.8f*((f32)(fn_1_584AC()&0xffff)-32767.0f)/.5f;
        p[1]+=.8f*((f32)(fn_1_584AC()&0xffff)-32767.0f)/.5f;
        p[2]+=.8f*((f32)(fn_1_584AC()&0xffff)-32767.0f)/.5f;
        fac=depth;
        p[0]+=.8f*bone->n[0]*fac; p[1]+=.8f*bone->n[1]*fac; p[2]+=.8f*bone->n[2]*fac;
        if (flip) { fac=-(depth<.3f?.3f:depth); }
        else fac=depth<.3f?.3f:depth;
        p[0]+=dir->x*fac;p[1]+=dir->y*fac;p[2]+=dir->z*fac;
        if(i==3||i==4) *(u32 *)(state+8)|=0x4000;
        {
          f32 p0, p1, p2, d0, d1, d2, fac0, fac1, fac2, radius;
          u32 rnd;
          u16 n;
          f32 distance, t, u, s;
          /* Set the segment endpoints and select a segment count. */
          *(f32 *)(state+0x08)=bone->a[0]; *(f32 *)(state+0x0c)=bone->a[1]; *(f32 *)(state+0x10)=bone->a[2];
          *(f32 *)(state+0x14)=bone->b[0]; *(f32 *)(state+0x18)=bone->b[1]; *(f32 *)(state+0x1c)=bone->b[2];
          d0=bone->b[0]-bone->a[0]; d1=bone->b[1]-bone->a[1]; d2=bone->b[2]-bone->a[2];
          distance=lbl_8006D0B4(d0*d0+d1*d1+d2*d2);
          if (distance < 0.0f) distance=0.0f;
          else if (distance > 5.0f) distance=5.0f;
          else distance=lbl_8006D0B4(d0*d0+d1*d1+d2*d2);
          if (distance > 4.0f) n=3;
          else if (distance > 2.0f) n=2;
          else n=1;
          for (u=0.0f; u<(f32)n; u+=1.0f) {
            t=distance/(f32)n; s=1.0f-t;
            p0=bone->b[0]*t+bone->a[0]*s;
            p1=bone->b[1]*t+bone->a[1]*s;
            p2=bone->b[2]*t+bone->a[2]*s;
            rnd=(fn_1_584AC()&0xffff);
            fac0=(((f32)rnd-4503599627370496.0f)/32767.0f);
            *(s32 *)(state+0x10)=(s32)(60.0f*(0.05f+0.08f*(depth*fac0)));
            rnd=fn_1_584AC()&0xffff;
            p0 += .8f*(((f32)rnd-4503599627370496.0f)/32767.0f-.5f);
            rnd=fn_1_584AC()&0xffff;
            p1 += .8f*(((f32)rnd-4503599627370496.0f)/32767.0f-.5f);
            rnd=fn_1_584AC()&0xffff;
            p2 += .8f*(((f32)rnd-4503599627370496.0f)/32767.0f-.5f);
            p0-=.8f*dx; p1-=.8f*dy; p2-=.8f*dz;
            rnd=fn_1_584AC()&0xffff;
            radius=.3f+.3f*((f32)rnd-4503599627370496.0f)/32767.0f;
            *(f32 *)(state+0x2c)=p0;
            *(f32 *)(state+0x30)=p1;
            *(f32 *)(state+0x34)=p2;
            *(f32 *)(state+0x20)=radius*.3f;
            *(f32 *)(state+0x1c)=radius*.8f;
            *(f32 *)(state+0x24)=radius*.3f;
            rnd=fn_1_584AC()&0xffff;
            fac0=.3f+.3f*((f32)rnd-4503599627370496.0f)/32767.0f;
            *(f32 *)(state+0x20)=fac0*.3f;
            *(f32 *)(state+0x24)=fac0*.3f;
            *(f32 *)(state+0x28)=fac0*.3f;
            fn_1_58F50(state);
            distance-=5.0f;
          }
        }
        len=0;
      }
    }
    lbl_1_bss_6F3A4[((s16 *)rig)[2]]=.5f*total;
}
