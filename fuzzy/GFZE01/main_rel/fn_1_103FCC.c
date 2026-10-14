/* Non-matching: best partial attempt (49.38% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"

typedef struct { u32 next; } Node;
struct Pool { u8 pad0[8]; f64 d; f32 one,half,zero; u8 pad[4]; f32 fifth; u8 pad2[12]; f32 two; u8 pad3[16]; f32 neg; u8 pad4[0x48]; f32 four; u8 pad5[8]; f32 eightTenths, sevenTenths; f32 huge, big, eight, fourk; };
extern struct Pool lbl_1_rodata_78D0;
extern f32 lbl_8006D0B4(f32);
extern s32 fn_1_9E514(f32);
extern u32 fn_1_9E29C(u32,u32,u32);
extern u32 fn_1_5910(void);
extern void fn_1_A714C(f32*,f32*,f32*,f32*);
extern void fn_1_56298(f32,f32,f32,f32);
extern void fn_1_9E598(Node*);
extern void fn_1_56000(u8,u8,u8);
extern void fn_1_5621C(f32,f32,f32,f32);
extern void fn_1_556B8(void*);
extern void lbl_8006DCA4(void);
extern u32 lbl_8006E0A4(u32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_x(u32);
extern void lbl_8006E13C(void*);
extern void fn_80038BFC(f32*);
extern u32 lbl_8006D7B0(void);
extern u32 lbl_8006DB74(u32);
extern void lbl_8006D758(void);
extern void lbl_8006E14C(f32);
extern u32 lbl_8006DFC4(u32);
extern u32 lbl_8006DAEC(void);
extern void fn_80072B7C(u32);
extern void fn_80072558(void);
extern void lbl_8006DB30(void);

void fn_1_103FCC(void *arg0) {
    u32 *obj, id, i, j, *p, *node, *param, *s;
    f32 a[4], b[7], temp, z, *cache, ratio, w, x, y, avg, len, power, alpha, ang, q;
    s32 count, n, rot;
    u8 *base, *records, *colors, *verts, *shape;
    f32 *v, *vtx, *add, *angles;
    obj = *(u32 **)((u8*)arg0+8);
    id = fn_1_5910();
    fn_1_A714C(a,a+1,a+2,a+3);
    p = (u32*)obj[0];
    node = (u32*)p[2];
    node = (u32*)node[2];
    param = (u32*)node[2];
    lbl_8006DCA4();
    lbl_8006E0A4((u32)(p+3));
    mathutil_mtxA_rotate_z(*(s16*)((u8*)p+0x1c));
    mathutil_mtxA_rotate_y(*(s16*)((u8*)p+0x1a));
    mathutil_mtxA_rotate_x(*(s16*)((u8*)p+0x18));
    lbl_8006E13C((u8*)p+0x20);
    lbl_8006E0A4((u32)(param+2));
    z=lbl_1_rodata_78D0.zero;
    fn_1_56298(z,z,z,z);
    fn_80038BFC(b);
    cache=(f32*)0xE0000000;
    psvec_set(&a[1],cache[0xb],cache[7],cache[3]);
    if (cache[0xb] < -a[2]) {
        ratio=lbl_1_rodata_78D0.one/cache[0xb];
        w=cache[0xb]+*(f32*)((u8*)param+0x14);
        x=b[2]+ratio*(a[2]*b[3]);
        y=b[5]+ratio*(a[1]*b[3]);
        count=fn_1_9E514(w);
        base=(u8*)obj+(id*0xfc+0x8e4);
        records=*(u8**)(base+8);
        colors=(u8*)obj+id*4;
        verts=(u8*)obj+id*0x50+0x3c4;
        n=(s32)*(f32*)(colors+0x514);
        for (i=0;i<(u32)n;i++) {
            v=(f32*)(verts+i*4);
            if (*(u32*)(records+i*12+4)>(u32)count)
                *v += lbl_1_rodata_78D0.half * (*(f32*)(colors+0x504)-*v);
            else
                *v += lbl_1_rodata_78D0.half * (lbl_1_rodata_78D0.neg-*v);
        }
        shape=(u8*)obj+id*0xf0;
        vtx=(f32*)(shape+0x524); add=(f32*)(shape+4);
        for (i=0;i<(u32)n;i++) {
            vtx[i*12+0]=a[1]; vtx[i*12+1]=a[2]; vtx[i*12+2]=a[3];
            vtx[i*12+0]+=add[i*12+0]; vtx[i*12+1]+=add[i*12+1];
            vtx[i*12+3]=a[1]; vtx[i*12+4]=a[2]; vtx[i*12+5]=a[3];
            vtx[i*12+3]+=add[i*12+3]; vtx[i*12+4]+=add[i*12+4];
            vtx[i*12+6]=a[1]; vtx[i*12+7]=a[2]; vtx[i*12+8]=a[3];
            vtx[i*12+6]+=add[i*12+6]; vtx[i*12+7]+=add[i*12+7];
            vtx[i*12+9]=a[1]; vtx[i*12+10]=a[2]; vtx[i*12+11]=a[3];
            vtx[i*12+9]+=add[i*12+9]; vtx[i*12+10]+=add[i*12+10]; vtx[i*12+11]+=add[i*12+11];
        }
        fn_1_9E29C(n,0,(u32)records);
        fn_1_9E598((Node*)base);
        lbl_8006D7B0();
        lbl_8006DB74((u32)b);
        lbl_8006D758();
        lbl_8006E14C(-(lbl_1_rodata_78D0.one+a[2])/a[3]);
        lbl_8006DFC4((u32)b);
        psvec_set(&a[1],cache[0xb],cache[7],cache[3]);
        lbl_8006DAEC();
        avg=lbl_1_rodata_78D0.zero;
        angles=(f32*)(colors+0x3c4);
        for(i=0;i<(u32)n;i++) if(angles[i]>=lbl_1_rodata_78D0.zero) avg+=angles[i];
        avg=avg*(lbl_1_rodata_78D0.two/(*(f32*)(colors+0x514)))-lbl_1_rodata_78D0.eightTenths;
        len=lbl_8006D0B4(a[1]*a[1]+a[2]*a[2]+a[3]*a[3]);
        power=avg*(-a[3]/len);
        if(power>lbl_1_rodata_78D0.one) power=lbl_1_rodata_78D0.one;
        else if(power<lbl_1_rodata_78D0.zero) power=lbl_1_rodata_78D0.zero;
        fn_1_56000(1,3,0);
        alpha=lbl_1_rodata_78D0.one-lbl_1_rodata_78D0.sevenTenths*power;
        s=(u32*)((u8*)obj+0xcd4);
        rot=(s32)(24576.0f+8192.0f*(lbl_1_rodata_78D0.sevenTenths*y+x));
        lbl_8006DAEC();
        n=(s32)*(f32*)(colors+0x514);
        for(i=n;i>0;i--) {
            ang=angles[n-i];
            if(ang != lbl_1_rodata_78D0.zero) {
                lbl_8006DAEC();
                lbl_8006E0A4((u32)(shape+4+(n-i)*12));
                mathutil_mtxA_rotate_z((s32)(rot+(s32)((i<<16)/(*(f32*)(colors+0x514)))));
                q=alpha*(ang*(8.0f/(*(f32*)(colors+0x514))));
                fn_1_5621C(q,q,q,lbl_1_rodata_78D0.one);
                lbl_8006E14C((-(a[3])*(lbl_1_rodata_78D0.one+ang)*lbl_1_rodata_78D0.fifth*(f32)n)/( *(f32*)(s[0]+20) * (-(lbl_1_rodata_78D0.one+a[2])/a[3])));
                fn_80072B7C(0); fn_80072558(); fn_1_556B8((void*)s[0]); fn_80072B7C(1); lbl_8006DB30();
            }
        }
        lbl_8006DB30();
        fn_1_5621C(1,1,1,1); fn_1_56000(1,3,1);
        fn_1_56000(1,3,0);
        mathutil_mtxA_rotate_z((s16)(24576.0f+4096.0f*(y+lbl_1_rodata_78D0.half*x)));
        q=power;
        if(q>1) q=1;
        fn_1_5621C(q,q,q,1);
        lbl_8006E14C((-(a[3])*4.0f*(f32)*(u32*)((u8*)obj+0xcd4) / (*(f32*)(s[0]+20) * (-(lbl_1_rodata_78D0.one+a[2])/a[3]))));
        fn_80072B7C(0); fn_80072558(); fn_1_556B8((void*)s[0]); fn_80072B7C(1);
        fn_1_5621C(1,1,1,1); fn_1_56000(1,3,1);
        lbl_8006DB30();
    }
}
