/* Non-matching: best partial attempt (42.33% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/camera.h"
#include "rel/main_rel/phys.h"
typedef struct Sig_fn_1_24F10_Fn_1_24F10 {
    int flags; unsigned char pad04[0x2c]; f32 field30; unsigned char pad34[0x150];
    f32 field184; unsigned char pad188[0x8c]; u16 field214; unsigned char pad216[0x0e];
    f32 field224; unsigned char pad228[0x284]; f32 field4ac; unsigned char pad4b0[0xe3];
    u8 field593; unsigned char pad594[0x46]; u16 field5da;
} Sig_fn_1_24F10_Fn_1_24F10;
extern Sig_fn_1_24F10_Fn_1_24F10 *fn_1_86254(int);
extern u32 lbl_1_data_3DC98;
extern f32 lbl_1_rodata_6780[];
extern size_t strlen(const char *);
extern s32 fn_8006FC5C(void *, void *, size_t);
extern f32 fn_80073778(void *, s32);
extern u32 lbl_8006D7DC(u32);
extern u32 lbl_8006DB74(u32);
extern u32 lbl_8006DFE8(u32);
extern void fn_80072558(void);
extern int sprintf(char *, const char *, ...);
extern void fn_80074918(u8,s32,u8);
extern void mathutil_mtxA_rotate_x(u32);
extern void mathutil_mtxA_rotate_y(u32);
extern void mathutil_mtxA_rotate_z(u32);
extern void fn_80008BA8(u32,u32,u32);
extern void fn_8006E978(f32 *, void *, void *);
extern void mathutil_mtxA_from_quat(void *);
extern void fn_8006F6A8(void *);
extern u32 lbl_8006E0A4(u32);
extern void lbl_8006E15C(f32,f32,f32);
extern void fn_800728A8(s32,s32,s32,s32);
extern void fn_80072864(u32);
extern u32 fn_80037E30(u32);
extern s32 fn_1_54E34(void *,f32);
extern void fn_1_556B8(void *);
extern s32 fn_1_54F5C(void *,f32,f32);
extern void fn_1_5621C(f32,f32,f32,f32);
extern void fn_1_681C(u32,u32 *);
void fn_1_E8938(u32 arg0,u32 arg1) {
    u8 *data=(u8 *)&lbl_1_data_3DC98;
    u8 *regions=(u8 *)&lbl_1_bss_7AE88;
    f32 *pool=lbl_1_rodata_6780;
    u8 **root=(u8 **)&lbl_1_bss_3BE0;
    Sig_fn_1_24F10_Fn_1_24F10 *mgr=fn_1_86254(*((u8 *)&lbl_1_bss_8B3A0+0x9e));
    s32 i=0, off=0;
    s32 j,k;
    u8 name[128];
    u8 *obj;
    u8 *node;
    u8 *entry;
    f32 a,b,c;
    for (;;) {
        u8 *r=*(u8 **)root;
        if (i >= *(s32 *)(r+0x48)) break;
        if (fn_8006FC5C(*(u32 **)(*(u32 **)(*(u32 **)(*(u32 *)(*(u32 *)(r+0x54)+off+8)+8)+4)),data+0x674,strlen((char *)(data+0x674)))) {
            obj=*(u8 **)(*(u32 *)(*(u32 *)(r+0x54)+off)+0x54);
            obj += (s16)i*0x40;
            break;
        }
        off+=0x40; i++;
    }
    if (i >= *(s32 *)(*(u8 **)root+0x48)) obj=0;
    node=*(u8 **)(obj+8);
    node=*(u8 **)(node+8);
    node=*(u8 **)(node+8);
    fn_80073778(*(void **)(node+0x24),0);
    fn_80073778(*(void **)(node+0x24),1);
    { u32 v[3]; v[0]=*(u32 *)(pool+0x384/4); v[1]=*(u32 *)(pool+0x388/4); v[2]=*(u32 *)(pool+0x38c/4); lbl_8006D7DC((u32)v); }
    lbl_8006DB74((u32)((u8 *)__builtin_alloca(0xc0)+0xd0));
    lbl_8006DFE8((u32)((u8 *)__builtin_alloca(0xc0)+0xd0));
    fn_80072558();
    fn_1_5621C(pool[0x20/4],pool[0x20/4],pool[0x20/4],pool[0x20/4]);
    for (j=2;j<=0x22;j++) {
        if (j >= *(s32 *)(mgr+0x49c+0x90) - 2 && j <= *(s32 *)(mgr+0x49c+0x90)+3) {
            sprintf((char *)name,(char *)(data+0x680),j);
            if(j==11) sprintf((char *)name,(char *)(data+0x68c));
            for(k=0,off=0;;k++,off+=0x40) {
                u8 *r=*(u8 **)root;
                if(k>=*(s32 *)(r+0x48)) { entry=0; break; }
                if(fn_8006FC5C(*(u32 **)(*(u32 **)(*(u32 *)(*(u32 *)(r+0x54)+off+8)+8)+4),name,strlen((char *)name))) {
                    entry=*(u8 **)(*(u32 *)(r+0x54)+((s16)k*0x40)); break;
                }
            }
            node=*(u8 **)(entry+8);
            node=*(u8 **)(node+8);
            node=*(u8 **)(node+8);
            if(fn_1_54E34(node+8,*(f32 *)(node+0x14))) fn_1_556B8(node);
        }
    }
    for(j=1;j<=5;j++) {
        sprintf((char *)name,(char *)(data+0x698),j);
        for(k=0,off=0;;k++,off+=0x40) {
            u8 *r=*(u8 **)root;
            if(k>=*(s32 *)(r+0x48)) { entry=0; break; }
            if(fn_8006FC5C(*(u32 **)(*(u32 **)(*(u32 *)(*(u32 *)(r+0x54)+off+8)+8)+4),name,strlen((char *)name))) {
                entry=*(u8 **)(*(u32 *)(r+0x54)+((s16)k*0x40)); break;
            }
        }
        node=*(u8 **)(entry+8); node=*(u8 **)(node+8); node=*(u8 **)(node+8);
        if(fn_1_54E34(node+8,*(f32 *)(node+0x14))) fn_1_556B8(node);
    }
    fn_1_5621C(pool[0x28/4],pool[0x28/4],pool[0x28/4],pool[0x28/4]);
    fn_80074918(1,1,0);
    for(i=0;i<6;i++) {
      s32 count=*(s16 *)(regions+i*8+4);
      for(j=0,off=0;j<count;j++,off+=0x1a8) {
        switch(i) {
        case 0: obj=*(u8 **)regions+off; break;
        case 1: obj=*(u8 **)(regions+8)+off; break;
        case 2: obj=*(u8 **)(regions+16)+off; break;
        case 3: obj=*(u8 **)(regions+24)+off; break;
        case 4: obj=*(u8 **)(regions+32)+off; break;
        case 5: obj=*(u8 **)(regions+40)+off; break;
        default: obj=0;
        }
        lbl_8006DFE8((u32)(obj+0xc4));
        a=*(f32 *)(obj+0xf4); b=*(f32 *)(obj+0xf8); c=*(f32 *)(obj+0xfc);
        if(a>b) b=a;
        if(b>c) { if(a>*(f32 *)(obj+0xf8)) c=a; else c=*(f32 *)(obj+0xf8); }
        else b=c;
        node=*(u8 **)obj;
        if(fn_1_54F5C(node+8,*(f32 *)(node+0x14),b)) k=1; else k=0;
        {
          s32 d=*(s32 *)(*(u8 **)(mgr+0x49c+0x90))-*(s32 *)(obj+0x100);
          if(d<0)d=-d;
          d=(s16)d;
          if(d<2) j=1;
          else if(d<4) k=1;
          else continue;
        }
        if (!((*(u32 *)(obj+0x138)&0x20) || (*(u32 *)(obj+0x13c)&0)) || (!k && !j)) continue;
        j=j?0x10: (k?6:5);
        {
          f32 q[3],pos[3],quat[3];
          u32 x[3]; x[0]=*(u32 *)(pool+0x390/4); x[1]=*(u32 *)(pool+0x394/4); x[2]=*(u32 *)(pool+0x398/4);
          fn_1_681C(mgr->field4ac,(u32 *)q);
          psvec_sub(obj+0x54,(u8 *)x,(u8 *)x);
          q[2]=*(f32 *)(obj+0x5c)-q[2]; q[1]=pool[0x20/4];
          mathutil_mtxA_rotate_x(0x4000);
          if((q[0]*q[0]+q[1]*q[1]+q[2]*q[2]) <= (pool[0xd0/4]+a)*(pool[0xd0/4]+a)) {
            u8 *cam=(u8 *)game_camera_get();
            if(*(s16 *)(cam+0xa4)==0) continue;
            fn_80008BA8((u32)quat,(u32)((u8 *)mgr+0x1bc),12);
            fn_8006E978((f32 *)pos,q,quat); mathutil_mtxA_from_quat(pos); fn_8006F6A8((void *)quat);
            psvec_scale(quat,pool[0x39c/4]*a,quat);
          } else {
            q[0]=pool[0x20/4]; q[1]=pool[0x28/4]; q[2]=pool[0x20/4];
            fn_8006E978((f32 *)pos,q,quat); mathutil_mtxA_from_quat(pos); fn_8006F6A8((void *)quat);
            psvec_scale(quat,pool[0x3a0/4]*a,quat);
          }
          lbl_8006D7DC((u32)(obj+0x54)); lbl_8006E0A4((u32)quat);
          mathutil_mtxA_rotate_z(*(s16 *)(quat+4)); mathutil_mtxA_rotate_y(*(s16 *)(quat+2)); mathutil_mtxA_rotate_x(*(s16 *)quat);
          lbl_8006E15C(a,a,pool[0xd0/4]*a);
        }
        lbl_8006DB74((u32)((u8 *)__builtin_alloca(0xc0)+0xd0));
        lbl_8006DFE8((u32)((u8 *)__builtin_alloca(0xc0)+0xd0));
        fn_80072558();
        if(*(s16 *)(obj+8)==4) { u8 *p=*(u8 **)(regions+16); if((*(f32 *)(obj+0xf4)* *(f32 *)(obj+0x84)+*(f32 *)(p+0x5ec)* *(f32 *)(p+0x57c))*( *(f32 *)(obj+0xf4)* *(f32 *)(obj+0x84)+*(f32 *)(p+0x5ec)* *(f32 *)(p+0x57c)) <= (pool[0x20/4]*pool[0x20/4]+(*(f32 *)(obj+0x5c)-*(f32 *)(p+0x554))*(*(f32 *)(obj+0x5c)-*(f32 *)(p+0x554)))) continue; }
        fn_80074918(1,1,0); fn_800728A8(2,1,0,10); fn_80072864(1); fn_80037E30((u8)j); fn_800728A8(2,1,0,10); fn_80072864(2); fn_80037E30((u8)j);
      }
    }
    fn_80072864(2); fn_800728A8(0,1,0,10); fn_80074918(1,1,1);
}
