/* Non-matching: best partial attempt (83.88% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
extern u32 lbl_801A65F0, lbl_801A6C44, lbl_801A6C4C, lbl_801A6C74;
extern u8 lbl_8012B658[];
extern u8 lbl_80178C18[144];
extern u32 lbl_801A6590, lbl_801A6C60;
extern f32 lbl_801A6594, lbl_801A6C64;
extern u32 lbl_801A6598, lbl_801A659C, lbl_801A65A0, lbl_801A65A8, lbl_801A65A4, lbl_801A65AC;
extern u32 lbl_801A65F4, lbl_801A65F8, lbl_801A65FC, lbl_801A6600[2];
extern u32 lbl_801A65B0, lbl_801A65B4, lbl_801A65B8, lbl_801A6C48, lbl_801A6C6C;
extern const f32 lbl_801A71C8, lbl_801A71D8, lbl_801A71F0, lbl_801A71F4, lbl_801A71F8, lbl_801A71FC, lbl_801A7204, lbl_801A7208, lbl_801A7210;
extern const f64 lbl_801A71D0;
typedef struct Sig_fn_80035828_GXColor { u8 r,g,b,a; } Sig_fn_80035828_GXColor;
extern void fn_80035828(s32, Sig_fn_80035828_GXColor);
extern void fn_8003462C(u32,u32,u32);
typedef enum Sig_GXSetLineWidth__GXTexOffset { Sig_GXSetLineWidth_GX_TO_ZERO } Sig_GXSetLineWidth_GXTexOffset;
extern void GXSetLineWidth(u8,Sig_GXSetLineWidth_GXTexOffset);
extern void GXLoadPosMtxImm(void *,u32);
extern void fn_8003EC44(void *);
extern void fn_8003F834(void);
/* fzgx-allow: A1 SDK absolute-addressed OS clock globals */
u32 __OSCoreClock : (0x80000000 + 0xFC);
/* fzgx-allow: A1 SDK absolute-addressed GX write-gather FIFO; volatile hardware writes */
volatile f32 __GXWGFifo : 0xCC008000;
#define FIFO __GXWGFifo
static inline void position(f32 x, f32 y, f32 z) { FIFO=x; FIFO=y; FIFO=z; }
#define VERT(x,y) position((x),(y),-1.0f)
#define COLOR(x) { Sig_fn_80035828_GXColor color = *(Sig_fn_80035828_GXColor *)&(x); fn_80035828(4,color); }
#define BEGIN(p,n) fn_8003462C(p,0,n)
#define X(t) (616.0f * ((f32)(u32)(t) / (f32)lbl_801A6C60))
struct Entry { u32 ptr, count, time, end; };
static inline u8 fn_8003FF88_array_read(u8 *array, s32 index) { return array[index]; }
#pragma opt_strength_reduction on
static inline u32 fn_8003FF88_operand(u32 left, u32 right) { left *= right; return left; }
void fn_8003FF88(f32 arg0) {
 u32 v3;
 u32 v0;
 f32 v1;
 u32 v2;
 u8 *p_lbl_8012B658;
 u32 fzgx_frame_pad[50];  /* fzgx: retail frame home */
 f32 extent, y, x;
 u32 i, tick, id, row, delta;
 u8 *record;
 p_lbl_8012B658=(u8 *)&lbl_8012B658;
 v1=arg0;
 if(lbl_801A6C74 != 0) {
 v0=lbl_801A6C44;
 v2=v0<<4;
 v3=*(u32 *)((u8 *)lbl_801A6C4C+v2);
 if((s32)lbl_801A65F0 != 0) {
 lbl_801A6590=((struct Entry *)((u8 *)lbl_801A6C4C+v2))->time/(__OSCoreClock/60)+1;
 }
 lbl_801A6C60=(__OSCoreClock/60)*lbl_801A6590;
 lbl_801A6594=616.0f/(f32)lbl_801A6590;
 extent=X(((struct Entry *)((u8 *)lbl_801A6C4C+v2))->time);
 GXLoadPosMtxImm(lbl_80178C18,0);
 COLOR(lbl_801A6598);
 BEGIN(0x80,4);
 VERT(0.0f,0.0f);
 VERT(0.0f,lbl_801A6C64);
 VERT(616.0f,lbl_801A6C64);
 VERT(616.0f,0.0f);
 COLOR(lbl_801A659C);
 GXSetLineWidth(12,0);
 BEGIN(0xA8,8);
 VERT(*(f32 *)(p_lbl_8012B658+0),*(f32 *)(p_lbl_8012B658+4));
 VERT(*(f32 *)(p_lbl_8012B658+8),*(f32 *)(p_lbl_8012B658+12));
 VERT(*(f32 *)(p_lbl_8012B658+16),*(f32 *)(p_lbl_8012B658+20));
 VERT(*(f32 *)(p_lbl_8012B658+24),*(f32 *)(p_lbl_8012B658+28));
 VERT(*(f32 *)(p_lbl_8012B658+32),*(f32 *)(p_lbl_8012B658+36));
 VERT(*(f32 *)(p_lbl_8012B658+40),*(f32 *)(p_lbl_8012B658+44));
 VERT(*(f32 *)(p_lbl_8012B658+48),*(f32 *)(p_lbl_8012B658+52));
 VERT(*(f32 *)(p_lbl_8012B658+56),*(f32 *)(p_lbl_8012B658+60));
 if(lbl_801A6590>1) {
 BEGIN(0xA8,(u16)((lbl_801A6590-1)*2));
 tick=__OSCoreClock/60;
 for(i=1;i<lbl_801A6590;i++) {
 x=X(fn_8003FF88_operand((i), (tick)));
 VERT(x,*(f32 *)(p_lbl_8012B658+0x44));
 VERT(x,*(f32 *)(p_lbl_8012B658+0x4C));
 }
 }
 COLOR(lbl_801A65A0);
 GXSetLineWidth(32,0); BEGIN(0xA8,2);
 VERT(0.0f,0.0f); VERT(extent,0.0f);
 COLOR(lbl_801A65A8); BEGIN(0xA8,2);
 VERT(0.0f,0.0f);
 VERT(X(((struct Entry *)lbl_801A6C4C)[lbl_801A6C44].end),0.0f);
 if((s32)lbl_801A65F4 != 0) { y=7.0f+lbl_801A6C64; COLOR(lbl_801A65B0); BEGIN(0x80,4);
 VERT(0.0f,y); VERT(0.0f,140.0f+y);
 VERT(extent,140.0f+y); VERT(extent,y);
 }
 if((s32)lbl_801A65F8 != 0) { y=7.0f+(140.0f+(7.0f+lbl_801A6C64)); COLOR(lbl_801A65B4); BEGIN(0x80,4);
 VERT(0.0f,y); VERT(0.0f,50.0f+y);
 VERT(extent,50.0f+y); VERT(extent,y);
 COLOR(lbl_801A65AC); GXSetLineWidth(6,0); BEGIN(0xA8,2);
 VERT(0.0f,25.0f+y); VERT(extent,25.0f+y);
 }
 if((s32)lbl_801A65FC != 0) { y=14.0f+(50.0f+(140.0f+(7.0f+lbl_801A6C64))); COLOR(lbl_801A65B8); BEGIN(0x80,4);
 VERT(0.0f,y); VERT(0.0f,50.0f+y);
 VERT(extent,50.0f+y); VERT(extent,y);
 }
 if((s32)lbl_801A6600[0] != 0) { y=50.0f+(21.0f+(50.0f+(140.0f+(7.0f+lbl_801A6C64)))); COLOR(lbl_801A65B8); BEGIN(0x80,4);
 VERT(0.0f,y); VERT(0.0f,50.0f+y);
 VERT(extent,50.0f+y); VERT(extent,y);
 }
 for(i=0;i<((struct Entry *)lbl_801A6C4C)[lbl_801A6C44].count;i++) {
 record=(u8 *)v3+i*0xB0;
 id=fn_8003FF88_array_read(record, 0);
 if(id==255) { fn_8003EC44(record); } else {
 switch((s32)((struct Entry *)lbl_801A6C48)[id].count) {
 case 1: { COLOR(((struct Entry *)lbl_801A6C48)[id].end);
 GXSetLineWidth(32,0); BEGIN(0xA8,2);
 row=(id+1)*7;
 VERT(X(*(u32 *)(record+4)),(f32)row); VERT(X(*(u32 *)(record+8)),(f32)row);
 delta=*(u32 *)(record+44)-*(u32 *)(record+40);
 if(delta!=0) {
 x=X(delta+*(u32 *)(record+4));
 COLOR(lbl_801A65A8); BEGIN(0xA8,2);
 VERT(X(*(u32 *)(record+4)),(f32)row); VERT(x,(f32)row);
 }
 if(*(u32 *)(record+16)!=0) {
 if((s32)*(u32 *)(record+20)==0) { COLOR(lbl_801A65A4); GXSetLineWidth(32,0); BEGIN(0xA8,2);
 VERT(X(*(u32 *)(record+12)),lbl_801A6C64); VERT(X(*(u32 *)(record+16)),lbl_801A6C64);
 fn_8003EC44(record);
 COLOR(lbl_801A65AC); GXSetLineWidth(6,0); BEGIN(0xA8,4);
 VERT(X(*(u32 *)(record+12)),lbl_801A6C64); VERT(X(*(u32 *)(record+4)),(f32)row);
 VERT(X(*(u32 *)(record+16)),lbl_801A6C64); VERT(X(*(u32 *)(record+8)),(f32)row);
 } else { COLOR(lbl_801A65A4); GXSetLineWidth(32,0); BEGIN(0xA8,2);
 VERT(X(*(u32 *)(record+28)),lbl_801A6C64); VERT(X(*(u32 *)(record+16)),lbl_801A6C64);
 fn_8003EC44(record);
 COLOR(lbl_801A65AC); GXSetLineWidth(6,0); BEGIN(0xA8,4);
 VERT(X(*(u32 *)(record+28)),lbl_801A6C64); VERT(X(*(u32 *)(record+24)),(f32)row);
 VERT(X(*(u32 *)(record+16)),lbl_801A6C64); VERT(X(*(u32 *)(record+8)),(f32)row);
 }
 } break; }
 case 0: { COLOR(((struct Entry *)lbl_801A6C48)[id].end);
 GXSetLineWidth(32,0); BEGIN(0xA8,2);
 row=(id+1)*7;
 VERT(X(*(u32 *)(record+4)),(f32)row); VERT(X(*(u32 *)(record+8)),(f32)row);
 delta=*(u32 *)(record+44)-*(u32 *)(record+40);
 if(delta!=0) {
 x=X(delta+*(u32 *)(record+4));
 COLOR(lbl_801A65A8); BEGIN(0xA8,2);
 VERT(X(*(u32 *)(record+4)),(f32)row); VERT(x,(f32)row);
 } break; }
 case 2: {
 if((s32)*(u32 *)(record+20)==0) { COLOR(lbl_801A65A4); GXSetLineWidth(32,0); BEGIN(0xA8,2);
 VERT(X(*(u32 *)(record+12)),lbl_801A6C64); VERT(X(*(u32 *)(record+16)),lbl_801A6C64);
 fn_8003EC44(record);
 } else { COLOR(lbl_801A65A4); GXSetLineWidth(32,0); BEGIN(0xA8,2);
 VERT(X(*(u32 *)(record+28)),lbl_801A6C64); VERT(X(*(u32 *)(record+16)),lbl_801A6C64);
 fn_8003EC44(record);
 }
 break; }
 }
 }
 }
 if((s32)lbl_801A6C6C!=0) fn_8003F834();
 }
}
#pragma opt_strength_reduction reset

