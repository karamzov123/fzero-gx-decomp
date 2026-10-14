/* Non-matching: best partial attempt (61.00% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#include "rel/main_rel/memcard.h"

struct Copy88 { u32 a[22]; };
struct Rodata {
    u8 pad0[0x1c8]; f32 zero; u8 pad1d0[4]; f64 conv; u8 pad1d8[8]; f32 one;
    u8 pad1e4[0x20]; f32 ten; u8 pad208[0x28];
    f32 a230,a234,a238,a23c,a240,a244;
    u8 pad248[0xb4]; f32 a2fc;
    f64 a300,a308,a310,a318,a320,a328,a330,a338;
    f32 a340,a344,a348; u8 pad34c[4]; f64 a350,a358;
    f32 a360,a364,a368,a36c,a370,a374; f64 a378;
    f32 a380,a384,a388,a38c;
};
struct Bss { u8 pad[0x5c54]; u8 flags; u8 pad2[3]; s32 count; };
extern struct Rodata lbl_1_rodata_4AE0;
extern u32 lbl_801A66B4, lbl_801A66C8;
extern struct Copy88 lbl_1_rodata_26F8;
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495C8(u8);
extern void fn_1_4954C(f32);
extern void fn_1_49614(void);
extern void fn_1_4955C(f32,f32);
extern void fn_1_4966C(f32,f32);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_A2DC4(u32);
typedef struct { f32 value0; u8 pad4[8]; f32 valueC; } Dest;
typedef struct { u8 pad0[0x54]; f32 value; } Source;
extern void fn_1_B5F00(Source *,Dest *);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_496FC(f32,f32);
extern void fn_1_49514(u32 *);
extern void fn_1_4AE0C(const char *,...);
extern void fn_1_495A0(f32);
extern void fn_1_50164(void *,f32,f32,f32,f32);
extern int fn_1_4F734(FontDrawPacket *);
extern void _savegpr_27(void);
extern void _restgpr_27(void);

#define DRAWBASE() do { fn_1_49410(); fn_1_49614(); fn_1_494DC(5); fn_1_495B0(0x80000000); fn_1_49738((u32)fn_1_B5F00); fn_1_49748(p->a240); fn_1_49590(p->a23c); fn_1_495C8(9); } while(0)
#define CLAMP(v) do { if ((v)<0.0f) (v)=0.0f; else if ((v)>1.0f) (v)=1.0f; } while(0)
#define COPY_PACKET() do { packet=lbl_1_rodata_26F8; } while(0)
#define PACKET(x,y,z,w,mode) do { packet.a[0]=mode; ((f32*)packet.a)[1]=(x); ((f32*)packet.a)[2]=(y); ((f32*)packet.a)[3]=(z); ((f32*)packet.a)[4]=(w); packet.a[12]=10; } while(0)
void fn_1_B5F20(void) {
    struct Bss *b=(struct Bss *)&lbl_1_bss_716C0;
    struct Rodata *p=&lbl_1_rodata_4AE0;
    u8 *d=(u8 *)&lbl_1_data_35AC8;
    u8 *s=(u8*)b+8;
    u8 *m=s+0xa0;
    struct Copy88 packet;
    f32 x,a,c,z,q;
    f32 f31v,f30v,f29v;
    s32 kind;
    if(s[0x2a]&2) m=s;
    if(m[2]==4) kind=68;
    else if(m[2]==6) kind=69;
    else if(m[4]==6) kind=66;
    else if(m[4]==15 || m[4]==36 || m[4]==37) kind=67;
    else if(m[4]==25) kind=68;
    else kind=67;
    fn_1_49410(); fn_1_494DC(42); fn_1_495C8(9); fn_1_4954C(p->a2fc);
    fn_1_49614(); x=p->a230; fn_1_4955C(x,x); fn_1_4966C(p->a234,p->a238);
    if((s32)lbl_801A66B4!=5){ fn_1_495B0(0x80000000); fn_1_49590(p->a23c); fn_1_4966C(p->a234,p->a240); }
    x=*(f32*)(m+0x38);
    if(m[2]==0 || m[2]==1){ x=(f32)(p->a300*x); if(x<p->a308)x=(f32)p->a308; else if(x>p->a310){} else x=(f32)x; }
    if(m[2]==4){ x=(f32)(p->a318*x); if(x<p->a308)x=(f32)p->a308; else if(x>p->a310){} else x=(f32)x; }
    a=(f32)(x/p->a320); if(a<p->a308){} else if(a>p->a310){} else a=(f32)a;
    c=(f32)(((f64)x-p->a320)/p->a328); if(c<p->a308){} else if(c>p->a310){} else c=(f32)c;
    z=(f32)(((f64)x-p->a330)/p->a338); if(z<p->a308){} else if(z>p->a310){} else z=(f32)z;
    if(a<0.5f)b->flags=0;
    if(a>=1.0f && !(b->flags&1)){fn_1_A2DC4(0xa9010300);b->flags|=1;}
    if(c>=1.0f && !(b->flags&2)){fn_1_A2DC4(0xa9010300);b->flags|=2;}
    if(z>=1.0f && !(b->flags&4)){fn_1_A2DC4(0xa9010300);b->flags|=4;}
    if(z<1.0f && ((lbl_801A66C8&63)<48)){
        fn_1_49410(); fn_1_49614(); fn_1_494DC(5); fn_1_495B0(0x80000000);
        fn_1_49738((u32)fn_1_B5F00); fn_1_49748(4.0f); fn_1_49590(0.5f); fn_1_495C8(9);
        fn_1_496FC(320.0f,225.0f); fn_1_4954C(0.09f); fn_1_49514((u32*)&p->a350);
        fn_1_4AE0C((char*)d+0x5c84+(u32)kind*0x18+(u32)lbl_801A66B4*4);
        b->count=0;
    } else {
        b->count++;
        if(b->count==10) fn_1_A2DC4(0xa9010b00);
        q=(f32)b->count/10.0f; CLAMP(q);
        DRAWBASE(); fn_1_496FC(320.0f,225.0f); fn_1_495A0(q*q); fn_1_4954C(0.09f);
        fn_1_49514((u32*)&p->a358); fn_1_4955C(1.0f,q); fn_1_4AE0C((char*)d+0x7330); fn_1_4955C(1.0f,1.0f);
    }
    DRAWBASE(); fn_1_4955C(0.7f,0.7f); fn_1_4954C(0.09f); fn_1_49514((u32*)&p->a340);
    fn_1_496FC(275.0f,310.0f); fn_1_4AE0C((char*)d+0x7340);
    COPY_PACKET();
    PACKET(p->a244,p->a360,p->a344,p->a238,11);
    fn_1_50164(&packet,258.0f,17.0f,310.0f,8.0f);
    COPY_PACKET();
    PACKET(125.0f,p->a360,p->a344,p->a238,16);
    ((f32*)packet.a)[5]=15.625f; ((f32*)packet.a)[6]=0.5625f; packet.a[12]=9;
    fn_1_4F734((FontDrawPacket*)&packet);
    DRAWBASE(); fn_1_496FC(275.0f,310.0f); fn_1_4954C(0.09f); fn_1_49514((u32*)&p->a344);
    fn_1_496FC(275.0f,310.0f); fn_1_4AE0C((char*)d+0x7348);
    DRAWBASE(); fn_1_496FC(275.0f,340.0f); fn_1_4954C(0.09f); fn_1_49514((u32*)&p->a348);
    fn_1_496FC(275.0f,370.0f); fn_1_4AE0C((char*)d+0x7358);
    DRAWBASE(); fn_1_496FC(275.0f,370.0f); fn_1_4954C(0.09f); fn_1_49514((u32*)&p->a350);
    fn_1_496FC(275.0f,380.0f); fn_1_495A0(0.01f); fn_1_4AE0C((char*)d+0x731c);

    DRAWBASE(); fn_1_4955C(0.75f,0.75f); fn_1_4954C(0.09f);
    fn_1_49514((u32*)&p->a348);
    fn_1_496FC(275.0f,370.0f); fn_1_4AE0C((char*)d+0x7360);
    COPY_PACKET();
    PACKET(p->a244,p->a380,p->a344,p->a238,11);
    fn_1_50164(&packet,258.0f,17.0f,310.0f,8.0f);
    COPY_PACKET();
    PACKET(p->a244,p->a380,p->a344,p->a238,16);
    ((f32*)packet.a)[5]=15.625f; ((f32*)packet.a)[6]=0.5625f; packet.a[12]=9;
    fn_1_4F734((FontDrawPacket*)&packet);
    DRAWBASE(); fn_1_4955C(0.75f,0.75f); fn_1_4954C(0.09f);
    fn_1_49514((u32*)&p->a348);
    fn_1_496FC(275.0f,370.0f); fn_1_4AE0C((char*)d+0x7360);
    fn_1_4955C(p->a388,1.0f);
    fn_1_496FC(320.0f,p->a38c);
    fn_1_495A0(0.01f); fn_1_4AE0C((char*)d+0x731c);
}
