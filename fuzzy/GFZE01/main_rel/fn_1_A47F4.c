/* Non-matching: best partial attempt (96.24% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dolphin/os/OSFastCast.h"
typedef struct { f32 x,y,z; } Vec;
extern u8 lbl_1_bss_6F1E4[85];
extern void fn_1_862D4(u8, Vec *);
extern void fn_1_8658C(u8, Vec *);
extern f32 fn_1_8652C(u8);
extern void fn_1_681C(u32, void *);
extern void fn_1_6898(u32, void *);
extern f32 lbl_8006D0B4(f32);
extern f64 __fabs(f64);
extern s16 camera_get_mode(void);
extern s32 camera_get_state(void);
extern f64 lbl_1_rodata_4598;
extern f32 lbl_1_rodata_4470, lbl_1_rodata_45A0, lbl_1_rodata_45A8;
extern f32 lbl_1_rodata_45AC, lbl_1_rodata_45B0, lbl_1_rodata_45B4;
extern f32 lbl_1_rodata_45C4, lbl_1_rodata_45C8, lbl_1_rodata_45CC;
extern struct { f32 value; } lbl_1_rodata_45A4;
extern struct { f64 value; } lbl_1_rodata_45B8;
extern struct { f32 value; } lbl_1_rodata_45C0;

static inline f32 distance2(Vec *a, Vec *b) {
    f32 x;
    f32 y;
    f32 z;
    x=a->x-b->x;
    y=a->y-b->y;
    z=a->z-b->z;
    x*=x;
    x+=y*y;
    x+=z*z;
    return x;
}
static inline f32 clamp(f32 x) {
    f32 result=lbl_1_rodata_45C4;
    if(x<result) return result;
    result=lbl_1_rodata_45C8;
    if(x>result) return result;
    return x;
}
#pragma opt_common_subs off
#pragma opt_dead_assignments off
static inline f32 fn_1_A47F4_read_pointer(Vec * owner) { return owner->y; }
#pragma opt_loop_invariants on
void fn_1_A47F4(u32 index, u8 speed, u32 object, s8 *whole, s8 *fraction) {
    f32 fzgx_live__;
    f32 fzgx_live_;
    f32 fzgx_live;
    s32 offset;
    u32 nearer;
    f32 source;
    s32 exceeds;
    s32 mode;
    u8 id;
    f32 output;
    f32 base;
    f32 difference;
    f32 factor;
    f32 distA;
    f32 distance;
    f32 distB;
    struct { f32 value; } x;
    f32 y;
    f32 z;
    Vec a;
    Vec b;
    Vec c;
    Vec d;
    u8 byte;
    offset=index*20;
    byte=speed;
    id=lbl_1_bss_6F1E4[offset+1];
    fn_1_862D4(id,&a);
    fn_1_8658C(id,&b);
    source=fn_1_8652C(id);
    fn_1_681C(object,&c);
    fn_1_6898(object,&d);
    fzgx_live_ = c.x;
    fzgx_live__ = c.y;
    x.value=fzgx_live_-d.x; y=fzgx_live__-d.y; z=c.z-d.z;
    x.value*=x.value; x.value+=y*y; x.value+=z*z;
    distance=lbl_8006D0B4(x.value);
    x.value=b.x-d.x; y=b.y-d.y; z=b.z-d.z;
    distA=x.value*x.value; distA+=y*y; distA+=z*z;
    fzgx_live = a.x;
    fzgx_live_ = c.x;
    x.value=fzgx_live-fzgx_live_; y=fn_1_A47F4_read_pointer(&a)-c.y; z=a.z-c.z;
{
    f32 scaled;
    scaled=lbl_1_rodata_4598*distance;
    distB=x.value*x.value; distB+=y*y; distB+=z*z;
    if(distB<=distA) nearer=1; else nearer=0;
    if(scaled>source) exceeds=1; else exceeds=0;
    { f32 multiplier=lbl_1_rodata_45A4.value*__OSu8tof32(&byte);
    base=lbl_1_rodata_45A0+multiplier; }
    difference=scaled-source;
    if(source>=lbl_1_rodata_45A8) source=lbl_1_rodata_45A8;
    if(scaled>=lbl_1_rodata_45AC) scaled=lbl_1_rodata_45AC;
    source=lbl_1_rodata_45B0-source;
    scaled=lbl_1_rodata_45B0-scaled;
    mode=camera_get_mode();
    { s32 state=camera_get_state();
    if(mode==(s32)id && (s8)state!=9) factor=lbl_1_rodata_4470;
    else if(exceeds) factor=lbl_1_rodata_4470;
    else {
        f32 magnitude=(f32)__fabs(difference);
        if(magnitude>lbl_1_rodata_45B4) factor=lbl_1_rodata_45B4/magnitude;
        else factor=lbl_1_rodata_4470;
    }}
    output=base*(scaled/(source*factor));
}
    output=(f32)((output-base)/lbl_1_rodata_45B8.value);
    output=lbl_1_rodata_45C0.value*output;
    output=clamp(output);
    if(nearer | (lbl_1_bss_6F1E4[offset]&1)) *(f32 *)(lbl_1_bss_6F1E4+offset+16)=output;
    else {
        f32 *entry;
        entry=(f32 *)(lbl_1_bss_6F1E4+offset+16);
        output=*entry;
        output-=lbl_1_rodata_4470;
        output=clamp(output);
        *entry=output;
    }
    *whole=(s8)__OSf32tos8(output);
    output=(output-__OSs8tof32(whole))/lbl_1_rodata_45CC;
    *fraction=(s8)__OSf32tos8(output);
    { s32 v, result;
    v=*whole;
    if(v < -3) result=-3;
    else { result=32; if(v<=32) result=v; }
    *whole=result;
    v=*fraction;
    if(v < -64) result=-64;
    else { result=63; if(v<=63) result=v; }
    *fraction=result; }
}
#pragma opt_loop_invariants reset

