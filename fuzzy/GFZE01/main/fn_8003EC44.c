/* Non-matching: best partial attempt (84.60% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
typedef struct Sig_fn_80035828_GXColor { u8 r,g,b,a; } Sig_fn_80035828_GXColor;
struct fn_8003EC44_Arg0 {
 u8 pad_0[0xC]; u32 unk_C; u32 unk_10;
 u8 pad_14[0x9C];
};
extern f32 lbl_801A6C64, lbl_801A6C70;
extern const f32 lbl_801A71C8;
extern const f32 lbl_801A71E4;
extern const f32 lbl_801A71F0;
extern const f32 lbl_801A71F4;
extern const f32 lbl_801A71F8;
extern const f32 lbl_801A71FC;
extern const f32 lbl_801A7200;
extern const f32 lbl_801A7204;
extern const f32 lbl_801A7208;
extern const f64 lbl_801A71D0;
extern u32 lbl_801A65A8;
extern u32 lbl_801A65BC;
extern u32 lbl_801A65C0;
extern u32 lbl_801A65C4;
extern u32 lbl_801A65C8;
extern u32 lbl_801A65CC;
extern u32 lbl_801A65D0;
extern u32 lbl_801A65D4;
extern u32 lbl_801A65D8;
extern u32 lbl_801A65DC;
extern u32 lbl_801A65E0;
extern u32 lbl_801A65E4;
extern u32 lbl_801A65E8;
extern u32 lbl_801A65EC;
extern u32 lbl_801A65F4;
extern u32 lbl_801A65F8;
extern u32 lbl_801A65FC;
extern u32 lbl_801A6C60;
extern u32 lbl_801A6C68;
extern u32 lbl_801A6600[2];
extern void fn_80035828(s32, Sig_fn_80035828_GXColor);
extern void fn_8003462C(u32,u32,u32);
/* fzgx-allow: A1 SDK absolute-addressed OS clock globals */
u32 __OSCoreClock : (0x80000000 + 0xFC);
/* fzgx-allow: A1 SDK write gather FIFO */
volatile f32 __GXWGFifo : 0xCC008000;
#define FIELD(o) (*(u32 *)((u8 *)arg0 + (o)))
static inline f32 fn_8003EC44_operand(f32 right, f32 left) { return left + right; }
#pragma opt_loop_invariants off
void fn_8003EC44(struct fn_8003EC44_Arg0 *arg0) {
 f32 v12;
 u32 v0;
 u32 v1;
 u32 v2;
 u32 v4;
 u32 v16;
 u32 v59;
 u32 v68;
 u32 v70;
 f32 v5;
 f32 v10;
    u8 fzgx_frame_pad[40];  /* fzgx: retail frame home */
 f32 v11;
 f32 v13;
 f32 v14;
 f32 v18;
 f32 v54;
 f32 v57;
 f32 v60;
 f32 v63;
 f32 v67;
 f32 v73;
 f32 v74;
 f32 loc_1C;
 v0=arg0->unk_C; v1=arg0->unk_10; v2=v1-v0;
 v5=616.0f*((f32)v0/(f32)lbl_801A6C60);
 v12=616.0f*((f32)v1/(f32)lbl_801A6C60);
 v4=__OSCoreClock/60;
 v10=(f32)v2/(f32)v4;
 v13=v5;
 loc_1C=lbl_801A6C70-v5;
 *(u32 *)&loc_1C &= 0x7FFFFFFF;
 v11=7.0f+lbl_801A6C64;
 if(loc_1C<1.0f) v13=lbl_801A6C70;
 lbl_801A6C70=v12;
 if((s32)lbl_801A65F4 != 0) {

v16=FIELD(68)-FIELD(64);
 v18=140.0f*((f32)v16/((f32)lbl_801A6C68*v10));
 if(v18>1.0f) { fn_80035828(4, *(Sig_fn_80035828_GXColor *)&lbl_801A65C0);
 fn_8003462C(128,0,4);
__GXWGFifo=v13;
 v14=v11+v18;
 __GXWGFifo=v11; __GXWGFifo=-1.0f;
 __GXWGFifo=v13; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v11;
 v11=v11+v18;
 __GXWGFifo=-1.0f;
 }
v16=FIELD(76)-FIELD(72);
 v18=140.0f*((f32)v16/((f32)lbl_801A6C68*v10));
 if(v18>1.0f) { fn_80035828(4, *(Sig_fn_80035828_GXColor *)&lbl_801A65C4);
 fn_8003462C(128,0,4);
__GXWGFifo=v13;
 v14=v11+v18;
 __GXWGFifo=v11; __GXWGFifo=-1.0f;
 __GXWGFifo=v13; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v11;
 v11=v11+v18;
 __GXWGFifo=-1.0f;
 }
v16=FIELD(84)-FIELD(80);
 v18=140.0f*((f32)v16/((f32)lbl_801A6C68*v10));
 if(v18>1.0f) { fn_80035828(4, *(Sig_fn_80035828_GXColor *)&lbl_801A65C8);
 fn_8003462C(128,0,4);
__GXWGFifo=v13;
 v14=v11+v18;
 __GXWGFifo=v11; __GXWGFifo=-1.0f;
 __GXWGFifo=v13; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v11;
 v11=v11+v18;
 __GXWGFifo=-1.0f;
 }
v16=FIELD(92)-FIELD(88);
 v18=140.0f*((f32)v16/((f32)lbl_801A6C68*v10));
 if(v18>1.0f) { fn_80035828(4, *(Sig_fn_80035828_GXColor *)&lbl_801A65CC);
 fn_8003462C(128,0,4);
__GXWGFifo=v13;
 v14=fn_8003EC44_operand((v18), (v11));
 __GXWGFifo=v11; __GXWGFifo=-1.0f;
 __GXWGFifo=v13; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v11;
 v11=v11+v18;
 __GXWGFifo=-1.0f;
 }
v16=FIELD(100)-FIELD(96);
 v18=140.0f*((f32)v16/((f32)lbl_801A6C68*v10));
 if(v18>1.0f) { fn_80035828(4, *(Sig_fn_80035828_GXColor *)&lbl_801A65D0);
 fn_8003462C(128,0,4);
__GXWGFifo=v13;
 v14=v11+v18;
 __GXWGFifo=v11; __GXWGFifo=-1.0f;
 __GXWGFifo=v13; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v11;
 v11=v11+v18;
 __GXWGFifo=-1.0f;
 }
v16=FIELD(108)-FIELD(104);
 v18=140.0f*((f32)v16/((f32)lbl_801A6C68*v10));
 if(v18>1.0f) { fn_80035828(4, *(Sig_fn_80035828_GXColor *)&lbl_801A65D4);
 fn_8003462C(128,0,4);
__GXWGFifo=v13;
 v14=v11+v18;
 __GXWGFifo=v11; __GXWGFifo=-1.0f;
 __GXWGFifo=v13; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v11;
 v11=v11+v18;
 __GXWGFifo=-1.0f;
 }
v16=FIELD(116)-FIELD(112);
 v18=140.0f*((f32)v16/((f32)lbl_801A6C68*v10));
 if(v18>1.0f) { fn_80035828(4, *(Sig_fn_80035828_GXColor *)&lbl_801A65D8);
 fn_8003462C(128,0,4);
__GXWGFifo=v13;
 v14=v11+v18;
 __GXWGFifo=v11; __GXWGFifo=-1.0f;
 __GXWGFifo=v13; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v11;
 v11=v11+v18;
 __GXWGFifo=-1.0f;
 }
v16=FIELD(124)-FIELD(120);
 v18=140.0f*((f32)v16/((f32)lbl_801A6C68*v10));
 if(v18>1.0f) { fn_80035828(4, *(Sig_fn_80035828_GXColor *)&lbl_801A65DC);
 fn_8003462C(128,0,4);
__GXWGFifo=v13;
 v14=v11+v18;
 __GXWGFifo=v11; __GXWGFifo=-1.0f;
 __GXWGFifo=v13; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v11;
 v11=v11+v18;
 __GXWGFifo=-1.0f;
 }
v16=FIELD(132)-FIELD(128);
 v18=140.0f*((f32)v16/((f32)lbl_801A6C68*v10));
 if(v18>1.0f) { fn_80035828(4, *(Sig_fn_80035828_GXColor *)&lbl_801A65E0);
 fn_8003462C(128,0,4);
__GXWGFifo=v13;
 v14=v11+v18;
 __GXWGFifo=v11; __GXWGFifo=-1.0f;
 __GXWGFifo=v13; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v11;
 v11=v11+v18;
 __GXWGFifo=-1.0f;
 }
FIELD(0x88)>>=1; FIELD(0x8C)>>=1;
v16=FIELD(140)-FIELD(136);
 v18=140.0f*((f32)v16/((f32)lbl_801A6C68*v10));
 if(v18>1.0f) { fn_80035828(4, *(Sig_fn_80035828_GXColor *)&lbl_801A65E4);
 fn_8003462C(128,0,4);
__GXWGFifo=v13;
 v14=v11+v18;
 __GXWGFifo=v11; __GXWGFifo=-1.0f;
 __GXWGFifo=v13; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v11;
 
 __GXWGFifo=-1.0f;
 }
}
 if((s32)lbl_801A65F8 != 0) {
 v54=(f32)(FIELD(0x34)-FIELD(0x30))/(f32)v2;
 v57=50.0f*(v54*0.5f);
 v60=7.0f+(140.0f+(7.0f+lbl_801A6C64));
 v59=FIELD(0x24)-FIELD(0x20);
 if(v57>1.0f) { fn_80035828(4, *(Sig_fn_80035828_GXColor *)&lbl_801A65BC);
 fn_8003462C(128,0,4);
__GXWGFifo=v13;
 v14=v60+v57;
 __GXWGFifo=v60; __GXWGFifo=-1.0f;
 __GXWGFifo=v13; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v60;
 
 __GXWGFifo=-1.0f;
 }
 fn_80035828(4, *(Sig_fn_80035828_GXColor *)&lbl_801A65A8);
 fn_8003462C(128,0,4);

 v63=50.0f+v60;
 __GXWGFifo=v13;
 v14=v63-(50.0f*(f32)v59)/(f32)v2;
 __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v13; __GXWGFifo=v63; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v63; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 }
 v68=FIELD(0xAC)-FIELD(0xA8);
 if((s32)lbl_801A65FC != 0) {
 v67=14.0f+(50.0f+(140.0f+(7.0f+lbl_801A6C64)));
 v70=(FIELD(0x94)-FIELD(0x90))+(FIELD(0x9C)-FIELD(0x98));
 if(v68>=v70) {
 v73=(50.0f*(f32)(v68-v70))/(f32)v68;
 if(v73>1.0f) { fn_80035828(4, *(Sig_fn_80035828_GXColor *)&lbl_801A65E8);
 fn_8003462C(128,0,4);
__GXWGFifo=v13;
 v14=v67+v73;
 __GXWGFifo=v67; __GXWGFifo=-1.0f;
 __GXWGFifo=v13; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v67;
 
 __GXWGFifo=-1.0f;
 }
 }
 }
 if((s32)lbl_801A6600[0] != 0) {
 v73=(50.0f*(f32)(FIELD(0xA4)-FIELD(0xA0)))/(f32)v68;
 v74=50.0f+(((((140.0f+(7.0f+lbl_801A6C64))) + (21.0f)) + (50.0f)));
 if(v73>1.0f) { fn_80035828(4, *(Sig_fn_80035828_GXColor *)&lbl_801A65EC);
 fn_8003462C(128,0,4);
__GXWGFifo=v13;
 v14=v74+v73;
 __GXWGFifo=v74; __GXWGFifo=-1.0f;
 __GXWGFifo=v13; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v14; __GXWGFifo=-1.0f;
 __GXWGFifo=v12; __GXWGFifo=v74;
 
 __GXWGFifo=-1.0f;
 }
 }
}
#pragma opt_loop_invariants reset

