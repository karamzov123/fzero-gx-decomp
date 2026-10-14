/* Non-matching: best partial attempt (5.49% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/accessory.h"

typedef struct { f32 x,y,z; } Vec3;
typedef struct {
    u8 flags;
    u8 pad1[1];
    u8 count;
    u8 pad3[13];
    Vec3 pos;
    Vec3 old;
    Vec3 vel;
    Vec3 delta;
    u8 pad40[4];
} Node;
typedef struct {
    u8 pad0[8];
    u32 type;
    u32 unused;
    void *owner;
    u32 count;
    u32 unused20;
    Node *nodes;
} Obj;
typedef struct { u8 pad[0x150]; void *scene; } Manager;
typedef struct {
    u8 pad0[0x50]; f64 two52, dt, step; u8 pad64[4]; f32 zero;
    u8 pad6c[0x11c]; f64 eightTenths, twoTenths; u8 pad198[8];
    f32 a1a0; u8 pad1a4[0xc0]; f32 a264; u8 pad268[0x1c]; f32 a284;
    u8 pad288[0x20]; f32 a2a8; u8 pad2ac[0x4c]; f32 a2f8; u8 pad2fc[0xa0];
    f32 a39c,a3a0,a3a4,a3a8,a3ac,a3b0,a3b4,a3b8,a3bc,a3c0;
    u32 a3c4,a3c8,a3cc;
} Pool;
extern Pool lbl_1_rodata_7AB8;
extern s32 lbl_8006D0B4(f32);
extern f32 lbl_8006D0E8(f32);
extern f32 lbl_8006D668(Vec3 *);
extern void *fn_80077B14(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006D758(void);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E0B4(f32,f32,f32);
extern void lbl_8006DFC4(void *);
extern void lbl_8006DB74(void *);
extern void fn_8006E978(void *, Vec3 *, Vec3 *);
extern void mathutil_mtxA_from_quat(void *);
extern void fn_8006E250(void *, void *);
extern void fn_1_108BD0(void *, u32, f32, f32, f32, f32);

void fn_1_11677C(Obj *o)
{
    Node *n;
    u32 i;
    Vec3 center, avg, d;
    f32 quat[4];
    f32 mat[12];
    void *model;
    if (lbl_1_bss_962 == 0xb8 || o == 0 || o->owner == 0) return;
    fn_80077B14(o->owner);
    n=o->nodes;
    for(i=0;i<o->count;i++,n++) if(!(n->flags&1)) {
        n->old.x=n->pos.x+n->delta.x;
        n->old.y=n->pos.y+n->delta.y;
        n->old.z=n->pos.z+n->delta.z;
    }
}
