/* Non-matching: best partial attempt (68.97% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"
#include "psvec.h"
#include "rel/main_rel/bg_common.h"

typedef struct { f32 x,y,z; } Vec3;
typedef struct { u8 pad[0x14]; f32 a; f32 b; } Node;
typedef struct {
    u8 pad0[0x8]; u32 flags;
    u8 padc[4]; Vec3 pos;
    s16 rz, ry, rx;
    u8 pad1[2]; f32 size;
    u8 pad2[4]; f32 size2;
    u8 pad3[0x20]; f32 amount;
    u8 pad4[4]; u32 count;
    u8 pad5[8]; void *items;
    u8 pad6[0x30]; /* fields through 0x70 */
} Obj;
extern const f32 lbl_1_rodata_78D0[];
extern s32 fn_1_54E34(void *, f32);
extern void fn_1_56000(u8,u8,u8);
extern void fn_1_56298(f32,f32,f32,f32);
extern void fn_1_5621C(f32,f32,f32,f32);
extern void fn_1_557C4(void *);
extern s32 fn_1_9E514(f32);
extern u32 fn_1_9E29C(u32,u32,u32);
extern void fn_1_9E598(void *);
extern void lbl_8006D9D8(void *);
extern void mathutil_mtxA_rotate_z(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern void *lbl_8006E1F0(void *, f32, f32, f32);
extern void lbl_8006DAEC(void);
extern void lbl_8006E0B4(f32,f32,f32);
extern void lbl_8006D7B0(void);
extern void lbl_8006E14C(f32);
extern void lbl_8006DB30(void);
extern void OSPanic(const char *,int,const char *,...);
extern void fn_80038BFC(f32 *);
extern void lbl_8006DB74(void *);
extern void lbl_8006D758(void);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DFC4(void *);
void fn_1_103264(Obj *o) {
    Obj *unused;
    Node *n;
    Vec3 dir, p;
    f32 scale, depth, angle, step, size, t, q;
    s32 i, rot, frame;
    s32 *items;
    u32 flags;
    flags=o->flags;
    n=(Node *)lbl_1_bss_38458->unk_8;
    n=(Node *)((u8 *)n+0xa0);
    if (flags & 0x40000000) {
        Node *base=(Node *)*(u32 *)((u8 *)o+0);
        size=*(f32 *)((u8 *)base+0x20);
        scale=1.0f/size;
        depth=1.0f/ n->a;
        lbl_8006D9D8((u8 *)base+0xc);
        mathutil_mtxA_rotate_z(*(s16 *)((u8 *)base+0x1c));
        mathutil_mtxA_rotate_y(*(s16 *)((u8 *)base+0x1a));
        mathutil_mtxA_rotate_x(*(s16 *)((u8 *)base+0x18));
        size=*(f32 *)((u8 *)base+0x28);
        rot=*(s16 *)((u8 *)base+0x18);
    } else {
        scale=1.0f/o->size;
        depth=1.0f/n->a;
        size=o->size2;
        lbl_8006D9D8((u8 *)o+0xc);
        mathutil_mtxA_rotate_z(*(s16 *)((u8 *)o+0x28));
        mathutil_mtxA_rotate_y(*(s16 *)((u8 *)o+0x26));
        mathutil_mtxA_rotate_x(*(s16 *)((u8 *)o+0x24));
        rot=*(s16 *)((u8 *)o+0x24);
    }
    dir.x=0.5f*size; dir.y=0; dir.z=0;
    if (!fn_1_54E34(&dir,dir.x+5.0f*size)) {
        o->amount += 0.2f*(-1.0f-o->amount);
        return;
    }
    lbl_8006E1F0(&p,1.0f,0.0f,0.0f);
    psvec_set(&dir, *(f32 *)0xE000002c, *(f32 *)0xE000001c, *(f32 *)0xE000000c);
    if (dir.z < 0.0f) i=(s32)((32768.0f*dir.x+16384.0f*dir.y)/dir.z); else i=0;
    fn_1_56000(1,3,0);
    fn_1_56298(0,0,0,0);
    if (!(flags&0x10)) {
        angle=p.z<0.0f ? 1.0f+p.z : 1.0f;
        fn_1_5621C(p.x*angle,p.y*angle,p.z*angle,angle);
        step=0;
        t=2.0f;
        q=0.25f;
        for (angle=0; angle<size; angle += q*(o->pos.x*(1.0f+2.0f*angle))) {
            f32 radius=0.0f;
            if (fn_1_54E34((u8 *)n+8,o->size2*(1.0f+2.0f*angle))) {
                s32 a=(s16)(i+(s32)(98304.0f*angle));
                if (1.0f-angle < 1.0f) fn_1_5621C(p.x*(1.0f-angle)*step,p.y*(1.0f-angle)*step,p.z*(1.0f-angle)*step,(1.0f-angle)*step);
                lbl_8006DAEC(); lbl_8006E0B4(angle,0,0); lbl_8006D7B0();
                mathutil_mtxA_rotate_z(a);
                lbl_8006E14C(o->size2*depth);
                fn_1_557C4(n); lbl_8006DB30();
                if (++i>100) OSPanic((char *)lbl_1_data_3F34C,0x1f9,(char *)lbl_1_data_3F358);
            }
            angle += radius;
        }
    }
    step=3.0f*o->size2;
    if (fn_1_54E34((u8 *)n+8,step)) {
        fn_1_5621C(p.x*(0.5f+p.z)*(1.0f+0.4f*(1.0f+p.z)),p.y*(0.5f+p.z)*(1.0f+0.4f*(1.0f+p.z)),p.z*(0.5f+p.z)*(1.0f+0.4f*(1.0f+p.z)),0.5f+p.z);
        lbl_8006DAEC(); lbl_8006D7B0(); mathutil_mtxA_rotate_z((s16)(i<<1));
        lbl_8006E14C(step*depth); fn_1_557C4(n); lbl_8006DB30();
    }
    fn_1_5621C(1,1,1,1); fn_1_56298(0,0,0,0); fn_1_56000(1,3,1);
}
