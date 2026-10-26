/* Non-matching: best partial attempt (43.64% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"

typedef struct { f32 x,y,z; } Vec3;
typedef struct { f32 x,y,z; u8 age; u8 pad[3]; } Entry;
typedef struct { f32 x,y,z; u8 color[4]; f32 u,v; u8 more[8]; } Vertex;
extern u8 fn_1_58C4(void);
extern void fn_1_681C(u8, u32 *);
extern void fn_1_6914(u8, u32 *);
extern void fn_1_6990(u8, u32 *);
extern s32 camera_get_state(void);
extern f32 lbl_8006D668(u32 *);
extern void fn_1_6898(u8, u32 *);
extern void lbl_8006DCA4(void);
extern u32 fn_1_6EC0(u8);
extern s32 fn_1_54E34(void *, f32);
extern void fn_1_A714C(f32 *, f32 *, f32 *, f32 *);
extern f32 fn_1_A71AC(void);
extern void lbl_8006D5F0(void *, f32);
extern u32 lbl_801A63C0;

void fn_1_106084(u8 *base, u32 id, f32 p, f32 q, f32 t) {
    u32 n, div, end, i;
    u8 uid=(u8)id;
    Vec3 a, cross, tmp;
    f32 b[3], c[3];
    f32 motion[3];
    Vec3 *v;
    Entry *e;
    Vertex *w;
    f32 k, dist, x, y, z;
    u32 seed, rnd;
    f32 scalar;
    if (fn_1_58C4()>2) return;
    fn_1_58C4();
    div=0x400/fn_1_58C4();
    if (0x200/fn_1_58C4()>div) div=0x400/fn_1_58C4();
    else div=0x200/fn_1_58C4();
    *(u32 *)(base+0xc000)=div;
    base[0xc006]=(u8)(32*p+96*(1-p));
    base[0xc005]=(u8)(48*p+160*(1-p));
    base[0xc004]=(u8)(32*p+64*(1-p));
    base[0xc007]=(u8)(48*p+192*(1-p));
    base[0xc00a]=(u8)(48*p+192*(1-p));
    base[0xc009]=(u8)(48*p+192*(1-p));
    base[0xc008]=(u8)(48*p+192*(1-p));
    base[0xc00b]=(u8)(48*p+192*(1-p));
    fn_1_681C(uid,(u32 *)&a);
    fn_1_6914(uid,(u32 *)&b);
    fn_1_6990(uid,(u32 *)&c);
    if ((s8)camera_get_state()==9) { c[0]=0.0f; c[1]=1.0f; c[2]=0.0f; }
    psvec_sub(&b,&a,&b);
    lbl_8006D668((u32 *)&b);
    cross.x=b[1]*c[2]-b[2]*c[1];
    cross.y=b[2]*c[0]-b[0]*c[2];
    cross.z=b[0]*c[1]-b[1]*c[0];
    fn_1_6898(uid,(u32 *)&cross);
    k=0.5f+0.25f*q/t;
    psvec_sub(&a,&cross,&motion);
    lbl_8006DCA4();
    n=*(u32 *)(base+0xc000);
    i=id*n;
    end=i+n;
    fn_1_6EC0(uid);
    for (;i<end;i++) {
        e=(Entry *)(base+i*32+0x4000);
        v=(Vec3 *)(base+i*16);
        psvec_add(v,e,e);
        e->z+=v->z;
        if (v->z != 0.0f && fn_1_54E34(e,5.0f) && fn_1_6EC0(uid)) {
            dist=(e->x-a.x)*(e->x-a.x)+(e->y-a.y)*(e->y-a.y)+(e->z-a.z)*(e->z-a.z);
            if (dist>100.0f) goto skip;
        }
        seed=*(u32 *)(base+0xc008);
        rnd=*(u32 *)(base+0xc004);
        if (fn_1_58C4()<=2) {
            f32 f0,f1,f2;
            fn_1_A714C(&f0,&f1,&f2,(f32 *)&tmp);
            scalar=f2-3.0f;
            x=(f32)((u16)(lbl_801A63C0=lbl_801A63C0*0x676a4b6b+0x33cb)>>1);
            k=scalar+(x/32767.0f)*(30.0f-scalar);
            psvec_scale_add(&tmp,&b,k,&tmp);
            rnd=lbl_801A63C0=lbl_801A63C0*0x676a4b6b+0x33cb;
            x=(f32)((u16)(rnd>>1))/32767.0f;
            scalar=(3.0f+k)*(f1)*(2.5f*x-1.25f);
            psvec_scale_add(&tmp,&c,scalar,&tmp);
            scalar=f0*(3.0f+k)*fn_1_A71AC()*(2.5f*((f32)((u16)(lbl_801A63C0=lbl_801A63C0*0x676a4b6b+0x33cb)>>1)/32767.0f)-1.25f);
            psvec_scale_add(&tmp,&cross,scalar,&tmp);
            w=(Vertex *)v;
            w->x=0.0f; w->y=-0.5f; w->z=0.0f;
            w->color[0]=(u8)(45.0f-k);
            w->color[1]=(u8)(0.3f*32767.0f);
            w->color[2]=(u8)(1.0f-0.3f*(f32)((u16)(rnd>>1))/32767.0f);
            ((u8 *)v)[12]=(u8)(45.0f-k);
            psvec_scale_add(&tmp,&cross,scalar,&tmp);
            e->x=tmp.x; e->y=tmp.y; e->z=tmp.z;
            ((u8 *)e)[12]=(u8)(45.0f-k);
            ((u8 *)e)[13]=(u8)(45.0f-k);
            ((u8 *)e)[14]=(u8)(45.0f-k);
            ((u8 *)e)[15]=((u8 *)&tmp)[11];
        } else { v->z-=1.0f; }
skip:
        tmp.x=v->x-0.5f*0.0f;
        tmp.y=v->y-0.5f*0.0f;
        tmp.z=v->z-0.5f*0.0f;
        lbl_8006D5F0(&tmp,k);
        psvec_add(e,(u8 *)&tmp+0x2c,(u8 *)e+16);
    }
}
