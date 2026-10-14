/* Non-matching: best partial attempt (33.01% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"

typedef struct { f32 x, y, z; } Vec3;
typedef struct {
    u8 pad0[0x138];
    u32 flags0;
    u32 flags1;
    u8 pad140[4];
    void *hit;
    u32 hitmask;
    u8 pad14c[0x24];
    f32 velocity;
    u8 pad174[0x30];
} State;
typedef struct {
    u32 flags;
    s16 index;
    u8 pad6[0x4e];
    Vec3 pos;
    Vec3 velocity;
    Vec3 point;
    u8 pad90[0x10c];
    Vec3 normal;
    u8 pad1c8[0x2d4];
} Body;
extern f32 lbl_1_rodata_6780[];
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D534(void *, void *);
extern void *lbl_8006D5A4(void *, void *, void *, f32);
extern void lbl_8006D5F0(void *, f32);
extern void lbl_8006D668(void *);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_1_DF6AC(void *, void *, void *, void *, void *, f32, f32, f32, f32, f32);
extern void fn_1_A2D84(u32);
extern u32 fn_1_A3BD8(u32, u32);
extern int fn_1_24F10(void *, f32);
extern void lbl_8006DBAC(void *);
extern void fn_8006E250(void *);

s32 fn_1_DFBBC(Body *a, State *s, f32 scale) {
    Vec3 delta1, delta2, normal, axis, cross, saved[4];
    f32 speed = *(f32 *)((u8 *)a + 8);
    f32 radius, aa, bb, cc, disc, t, root;
    f32 tmp[3];
    u32 f0=s->flags0, f1=s->flags1;
    volatile u8 work[0x170];
    work[0] = 0;

    if ((f0 & 0x10) || (f1 & 0x10)) return 0;
    if (!(f0 & 0x400) && !(f1 & 0x400)) {
        s32 q = *(s32 *)(*(u32 *)((u8 *)a+0x49c)+0x90);
        s32 n = *(s32 *)((u8 *)s+0x100);
        if (q > n+1 || q < n-1) return 0;
    }
    radius = 0.99f * *(f32 *)((u8 *)s+0x84) * *(f32 *)((u8 *)s+0xf4);
    radius += (a->flags & 8) ? 2.0f : 1.0f;
    delta1.x=*(f32 *)((u8 *)s+0x60)-*(f32 *)((u8 *)a+0x88);
    delta1.y=*(f32 *)((u8 *)s+0x68)-*(f32 *)((u8 *)a+0x90);
    delta1.z=*(f32 *)((u8 *)s+0x64)-*(f32 *)((u8 *)a+0x8c);
    delta2.x=*(f32 *)((u8 *)s+0x54)-*(f32 *)((u8 *)a+0x7c);
    delta2.y=*(f32 *)((u8 *)s+0x5c)-*(f32 *)((u8 *)a+0x84);
    delta2.z=*(f32 *)((u8 *)s+0x58)-*(f32 *)((u8 *)a+0x80);
    normal.x=delta2.x-delta1.x; normal.y=delta2.y-delta1.y; normal.z=delta2.z-delta1.z;
    aa=normal.x*normal.x+normal.y*normal.y+normal.z*normal.z;
    if (aa < 1.1920929e-7f) return 0;
    cc=delta1.x*delta1.x+delta1.y*delta1.y+delta1.z*delta1.z-radius*radius;
    bb=delta1.x*normal.x+delta1.y*normal.y+delta1.z*normal.z;
    disc=bb*bb-aa*cc;
    if (disc < 0.0f) return 0;
    if (cc <= 0.0f) t=0.0f;
    else {
        if (cc+2.0f*bb+aa > 0.0f && (bb >= 0.0f || -bb >= aa)) return 0;
        t=-(bb+lbl_8006D0B4(disc))/aa;
    }
    if (t < 0.0f) t=0.0f;
    else if (t > 1.0f) t=1.0f;
    lbl_8006D5A4((u8 *)s+0x60,(u8 *)s+0x54,&delta1,t);
    lbl_8006D5A4((u8 *)a+0x88,(u8 *)a+0x7c,&delta2,t);
    axis.x=delta2.x-delta1.x; axis.y=delta2.y-delta1.y; axis.z=delta2.z-delta1.z;
    lbl_8006D534(&axis,(u8 *)a+0x1bc);
    root=lbl_8006D0B4(1.0f-root*root);
    fn_80008BA8(&normal,(u8 *)a+0x1bc,12);
    lbl_8006D5F0(&normal,radius*root);
    fn_80008BA8(&saved[0],&axis,12);
    cross.x=saved[0].x; cross.y=saved[0].y; cross.z=saved[0].z;
    if (s->flags0 & 0x40000) {
        if (s->flags1 & 0x80000) {
            lbl_8006D5F0(&normal,1.5f*radius);
            psvec_add((u8 *)s+0x84,&tmp,(u8 *)a+0x7c);
        } else {
            lbl_8006D5F0(&normal,-0.01f*radius);
            psvec_add((u8 *)s+0x84,&tmp,(u8 *)s+0x84);
            psvec_scale(&tmp[0],-1.0f,&tmp[0]);
            psvec_add((u8 *)a+0x7c,&tmp,(u8 *)a+0x7c);
        }
        fn_80008BA8(&normal,&normal,12);
    } else if (s->flags1 & 0x80000) {
        lbl_8006D5F0(&normal,-1.5f*radius);
        psvec_add((u8 *)a+0x7c,&tmp,(u8 *)s+0x84);
    } else {
        lbl_8006D5F0(&normal,-0.01f*radius);
        psvec_add((u8 *)s+0x84,&tmp,(u8 *)s+0x84);
        psvec_scale(&tmp[0],-1.0f,&tmp[0]);
        psvec_add((u8 *)a+0x7c,&tmp,(u8 *)a+0x7c);
    }
    s->flags1 |= 0x80000000;
    s->hit=a;
    s->hitmask |= 1u << a->index;
    if (s->flags1 & 0x400) {
        if (!(a->flags & 0x200)) { s->flags1 |= 3; s->flags0 |= 8; }
        return 1;
    }
    if (s->flags0 & 0x100) *(u32 *)((u8 *)s+0xc0)=*(u32 *)0x801a66a0;
    else { s->flags1 &= ~1u; s->flags0 &= ~2u; }
    if (*(s16 *)((u8 *)s+10)==0) fn_1_A2D84(0xa9093200);
    else if (*(s16 *)((u8 *)s+10)==1) fn_1_A3BD8(!!(a->flags&0x200),0xa9090400);
    else if (*(s16 *)((u8 *)s+10)==2) fn_1_A3BD8(!!(a->flags&0x200),0xa9093100);
    if (s->flags1 & 0x800000) return 0;
    fn_1_DF6AC((s->flags0&0x40)?(void *)((u8 *)s+0x44):(void *)((u8 *)s+0xd4),(u8 *)s+0x44,(u8 *)a+0x94,(u8 *)s+0x44,&axis,*(f32 *)((u8 *)s+0x50),*(f32 *)((u8 *)a+0x17c)/216.0f,*(f32 *)((u8 *)s+0x1c),speed,1.0f);
    if (s->flags1 & 0x200) {
        if (s->flags0&0x80) fn_1_24F10((void *)a,5.0f*lbl_8006D0B4(1.0f/speed));
        psvec_scale((u8 *)a+0x94,speed,(u8 *)a+0x94);
        s->flags0|=0x400;
        fn_80008BA8((u8 *)s+0x170,(u8 *)a+0x94,12);
    } else *(f32 *)((u8 *)s+0x74)=scale;
    return 1;
}
