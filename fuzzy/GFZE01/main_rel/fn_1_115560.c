/* Non-matching: best partial attempt (59.89% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/accessory.h"

typedef struct { u8 pad[16]; f32 pos[3]; f32 old[3]; f32 local[3]; f32 vel[3]; u8 tail[4]; } Particle;
typedef struct { u8 pad[8]; u32 index; void *obj; void *handle; u32 pad14; u32 count; u8 pad1c[8]; Particle *parts; } Emitter;
typedef struct { f32 x,y,z; } Vec3;
typedef struct { f32 q[4]; } Quat;
typedef struct { u8 pad[0x50]; f64 bias; u8 pad58[0x130]; f64 half; f64 four5; f64 half2; u8 pad1a0[0x1c4]; u32 x,y,z; f64 dt,dt2; } Pool;
extern Pool lbl_1_rodata_7AB8;
extern s32 fn_80077B14(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006E1B0(void *, void *);
extern f32 lbl_8006D668(Vec3 *);
extern void fn_8006E978(Quat *, Vec3 *, Vec3 *);
extern void mathutil_mtxA_from_quat(Quat *);
extern void lbl_8006DB74(void *);
extern void lbl_8006D758(void);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E0B4(f32,f32,f32);
extern void lbl_8006E0A4(void *);
extern void fn_8006E250(void *, void *);
extern void fn_1_1286F4(Vec3 *);
void fn_1_115560(Emitter *e)
{
    Particle *p, *ref = 0;
    s32 i, j, n;
    s32 count = 0;
    Vec3 sum;
    Vec3 avg;
    Vec3 delta;
    Vec3 accum;
    Vec3 out;
    Quat q;
    f32 mat[16];
    Vec3 random;
    void *base;
    if (e == 0 || e->handle == 0)
        return;
    base = (void *)fn_80077B14(e->handle);
    p=e->parts;
    for (i=0;i<e->count;i++,p++) {
        if (!(p->pad[0]&1)) {
            p->old[0]=p->pos[0]; p->old[1]=p->pos[1]; p->old[2]=p->pos[2];
            p->pos[0]+=p->vel[0]; p->pos[1]+=p->vel[1]; p->pos[2]+=p->vel[2];
            p->pos[1]-=(f32)lbl_1_rodata_7AB8.dt;
            p->vel[1]-=(f32)lbl_1_rodata_7AB8.dt2;
        }
    }
    n=((u32 *)&lbl_1_data_3FFBC)[e->index];
    p=e->parts;
    for(i=0;i<e->count;i++,p++) if(p->pad[0]&1) {
        lbl_8006DBAC((u8 *)base+n*0x18c+0x88);
        lbl_8006E1B0((u8 *)p+0x28,(u8 *)p+0x10);
        ref=p;
    }
    sum.x=lbl_1_rodata_7AB8.x; sum.y=lbl_1_rodata_7AB8.y; sum.z=lbl_1_rodata_7AB8.z;
    accum=sum;
    lbl_8006DBAC((u8 *)base+n*0x18c+0x88);
    p=e->parts;
    for(i=0;i<e->count;i++,p++) if(!(p->pad[0]&1)) {
        sum.x+=p->pos[0]; sum.y+=p->pos[1]; sum.z+=p->pos[2]; count++;
        lbl_8006E1B0(p->local,p->pos);
        accum.x+=p->local[0]; accum.y+=p->local[1]; accum.z+=p->local[2];
    }
    avg.x=sum.x/(f32)count; avg.y=sum.y/(f32)count; avg.z=sum.z/(f32)count;
    accum.x=accum.x/(f32)count; accum.y=accum.y/(f32)count; accum.z=accum.z/(f32)count;
    delta.x=avg.x-ref->pos[0]; delta.y=avg.y-ref->pos[1]; delta.z=avg.z-ref->pos[2];
    out.x=accum.x-ref->pos[0]; out.y=accum.y-ref->pos[1]; out.z=accum.z-ref->pos[2];
    (void)lbl_8006D668(&delta); (void)lbl_8006D668(&out);
    fn_8006E978(&q,&out,&delta);
    mathutil_mtxA_from_quat(&q);
    lbl_8006DB74(mat);
    lbl_8006DBAC((u8 *)base+n*0x18c+0x88);
    p=e->parts;
    for(i=0;i<e->count;i++,p++) if(!(p->pad[0]&1)) lbl_8006E1B0(p->local,p->pos);
    lbl_8006D758();
    lbl_8006E0A4(ref->pos);
    lbl_8006DFC4(mat);
    lbl_8006E0B4(-ref->pos[0],-ref->pos[1],-ref->pos[2]);
    p=e->parts;
    for(i=0;i<e->count;i++,p++) if(!(p->pad[0]&1)) lbl_8006E1B0((void *)p->pos,(void *)p->pos);
    p=e->parts;
    for(i=0;i<e->count;i++,p++) {
        fn_1_1286F4(&random);
        p->vel[0]=p->vel[0]*0.8f+0.2f*(p->pos[0]-p->old[0])+0.5f*random.x;
        p->vel[1]=p->vel[1]*0.8f+0.2f*(p->pos[1]-p->old[1])+0.5f*random.y;
        p->vel[2]=p->vel[2]*0.8f+0.2f*(p->pos[2]-p->old[2])+0.5f*random.z;
    }
    lbl_8006DBAC((u8 *)base+n*0x18c+0x88);
    p=e->parts;
    for(i=0;i<e->count;i++,p++) for(j=0;j<p->pad[2];j++) fn_8006E250(p->pos,base);
}
