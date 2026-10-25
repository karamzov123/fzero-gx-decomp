/* Non-matching: best partial attempt (92.48% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
typedef struct { f32 x,y,z; } Vec;
typedef struct { f32 width,height; f32 matrix[12]; u32 flags; u8 r,g,b,a; } Draw;
typedef struct { s32 type,active; Vec pos; u8 pad14[12]; Vec vel; s16 rx,ry; f32 unk30,alpha,size; u8 rest[0x44c-0x3c]; } Emitter;
typedef struct { u8 pad[0x424]; u32 model; void *tex1,*tex2; u32 unk430; Emitter emit[100]; } State;
extern void lbl_8006DCA4(void);
extern f32 lbl_8006D0B4(f32);
extern s32 fn_1_54E34(Vec *,f32);
extern void lbl_8006E1B0(Vec *,Vec *);
extern void fn_8006EDBC(Vec *,Vec *,s16 *,s16 *);
extern void lbl_8006D7DC(Vec *);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_x(s32);
extern void lbl_8006E15C(f32,f32,f32);
extern void fn_8006E294(Vec *);
extern s32 lbl_8006D24C(f32,f32);
extern void *memset(void *,int,u32);
extern void lbl_8006DB74(void *);
extern u32 fn_1_584AC(void);
extern void fn_1_1011CC(int,int);
extern void fn_800728A8(s32,s32,s32,s32);
extern void lbl_8006D758(void);
extern void fn_80073778(void *,s32);
extern void fn_1_9EDE8(Draw *);
extern void lbl_8006D9D8(void *);
extern void lbl_8006E14C(f32);
extern void fn_1_55FC4(f32);
extern void fn_80072558(void);
extern void fn_1_55FF0(f32);
extern u32 fn_1_55210(u32);
extern void fn_1_FFA0C(Emitter *);
void fn_1_FF038(State *state) {
    s32 i;
    f32 size,length,dist;
    f32 dx,dy,dz;
    f32 sx,sy,sz,squared,t;
    f32 alpha;
    Vec sum,delta;
    f32 random,bright;
    Draw draw;
    Vec temp,start,end,center;
    s16 rx,ry;
    Emitter *e=state->emit;
    for(i=0;i<100;i++,e++) {
        if(e->active<=0) continue;
        lbl_8006DCA4();
        size=22.0f*e->size;
        if(e->type) { t=15.0f*e->size; dist=t*0.25f; }
        else { t=30.0f*e->size; dist=t*0.25f; }
        temp.x=e->pos.x-(f32)(e->vel.x*dist);
        temp.y=e->pos.y-(f32)(e->vel.y*dist);
        temp.z=e->pos.z-(f32)(e->vel.z*dist);
        start=temp;
        end=e->pos;
        sum.x=start.x+end.x;
        sum.y=start.y+end.y;
        sum.z=start.z+end.z;
        delta.x=start.x-end.x;
        delta.y=start.y-end.y;
        delta.z=start.z-end.z;
        squared=(f32)(delta.x*delta.x)+delta.y*delta.y+delta.z*delta.z;
        center.x=0.5f*sum.x;
        center.y=0.5f*sum.y;
        center.z=0.5f*sum.z;
        length=0.9*lbl_8006D0B4(squared);
        if(!fn_1_54E34(&center,length)) continue;
        lbl_8006E1B0(&center,&center);
        lbl_8006E1B0(&start,&start);
        lbl_8006E1B0(&end,&end);
        fn_8006EDBC(&start,&end,&rx,&ry);
        lbl_8006D7DC(&center);
        mathutil_mtxA_rotate_y(ry);
        mathutil_mtxA_rotate_x(rx);
        lbl_8006E15C(1.0f,1.0f,length/size);
        mathutil_mtxA_rotate_x(0x4000);
        fn_8006E294(&temp);
        mathutil_mtxA_rotate_y(lbl_8006D24C(temp.x,temp.z));
        memset(&draw,0,0x40);
        lbl_8006DB74(draw.matrix);
        random=(f32)(fn_1_584AC()&0xffff)/32767.0f;
        alpha=e->alpha;
        bright=0.4f*random;
        bright=0.6f+bright;
        draw.a=255;
        draw.flags|=4;
        draw.r=(s32)((255.0f*(0.5f*(1.0f+bright)))*alpha);
        draw.g=(s32)((255.0f*(0.8f*bright))*alpha);
        draw.b=(s32)((255.0f*(0.3f*bright))*alpha);
        fn_1_1011CC(0,1);
        fn_800728A8(1,4,1,0);
        if(e->type) {
            draw.width=1.3f*(0.70710677f*size);
            draw.height=size;
            lbl_8006D758();
            fn_80073778(*(void **)((u8 *)state->tex1+0x24),0);
            fn_1_9EDE8(&draw);
        } else {
            draw.width=0.6f*(0.70710677f*size);
            draw.height=size;
            lbl_8006D758();
            fn_80073778(*(void **)((u8 *)state->tex2+0x24),0);
            fn_1_9EDE8(&draw);
        }
        lbl_8006DCA4();
        if(e->type) {
            lbl_8006D9D8(&e->pos);
            lbl_8006E14C(e->size);
            fn_1_55FC4(e->size);
            mathutil_mtxA_rotate_y(e->ry);
            mathutil_mtxA_rotate_x(e->rx);
            fn_80072558();
            fn_1_55FF0(e->alpha);
            fn_1_55210(state->model);
            fn_1_FFA0C(e);
        }
    }
}
