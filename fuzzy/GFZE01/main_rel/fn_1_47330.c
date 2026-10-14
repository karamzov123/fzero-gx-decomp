/* Non-matching: best partial attempt (62.04% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/load.h"

extern u32 lbl_1_rodata_F88[18];
extern void fn_80074918(u8, s32, u8);
extern void fn_80074788(u32);
extern void fn_80074660(u32);
extern void fn_80073678(u32);
extern void fn_80073C6C(s32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072864(u32);
extern void fn_8007245C(u32);
extern void fn_800371F8(s32, void *);
extern void fn_8003462C(u32, u32, u32);
extern u32 lbl_1_bss_384C0;

typedef struct Vec3 { f32 x,y,z; } Vec3;
typedef struct Entry { u32 type, unk4, offset, size; } Entry;

static void vertex(f32 x, f32 y, f32 z) {
    volatile f32 *fifo = (volatile f32 *)0xCC008000;
    *fifo=x; *fifo=y; *fifo=z;
}

void fn_1_47330(Vec3 *pos, f32 w, f32 h) {
    u8 color[4];
    Entry *entries;
    s32 i;
    f32 one = 1.0f;
    f32 dy = h - one;
    f32 dx = w - one;

    fn_80074918(0,7,0);
    fn_80074788(1);
    fn_80074660(0);
    fn_80073678(1);
    fn_80073C6C(0);
    fn_800747D0(4,0,0,0,0,2,2);
    fn_80072AB0(0,0,0);
    fn_800734A8(0,255,255,4);
    fn_80072C24(0,15,15,15,2);
    fn_80072D64(0,0,0,0,1,0);
    fn_80072CC4(0,7,7,7,1);
    fn_80072E20(0,0,0,0,1,0);
    fn_800728A8(1,4,5,0);
    fn_80072864(2);
    fn_8007245C(512);

    *(u32 *)color=lbl_1_rodata_F88[0];
    fn_800371F8(1,color);
    fn_8003462C(128,7,4);
    vertex(pos->x,pos->y,pos->z);
    vertex(pos->x+w,pos->y,pos->z);
    vertex(pos->x+w,pos->y+h,pos->z);
    vertex(pos->x,pos->y+h,pos->z);
    pos->x += one;
    pos->y += one;
    *(u32 *)color=lbl_1_rodata_F88[1];
    fn_800371F8(1,color);

    fn_8003462C(128,7,4);
    vertex(pos->x,pos->y,pos->z-0.001f);
    vertex(pos->x+w-one,pos->y,pos->z-0.001f);
    vertex(pos->x+w-one,pos->y+h-one,pos->z-0.001f);
    vertex(pos->x,pos->y+h-one,pos->z-0.001f);
    *(u32 *)color=lbl_1_rodata_F88[2];
    fn_800371F8(1,color);

    entries=(Entry *)((u8 *)&lbl_1_bss_384C0+0x18);
    for(i=0;i<0x400;i++) {
        Entry *e=&entries[i];
        u32 mode=0;
        if (e->type==0x40000000) { *(u32 *)color=lbl_1_rodata_F88[3]; fn_800371F8(1,color); mode=1; }
        else if(e->type==0x50000000) { *(u32 *)color=lbl_1_rodata_F88[4]; fn_800371F8(1,color); mode=1; }
        else if(e->type==0x20000000) { *(u32 *)color=lbl_1_rodata_F88[5]; fn_800371F8(1,color); mode=1; }
        else if(e->type==0x30000000) { *(u32 *)color=lbl_1_rodata_F88[6]; fn_800371F8(1,color); mode=1; }
        else if(e->type==0x80000000) { *(u32 *)color=lbl_1_rodata_F88[7]; fn_800371F8(1,color); mode=1; }
        else if(e->type==0x04000000) { *(u32 *)color=lbl_1_rodata_F88[8]; fn_800371F8(1,color); mode=1; }
        else if(e->type==0x14000000) { *(u32 *)color=lbl_1_rodata_F88[9]; fn_800371F8(1,color); mode=1; }
        else if(e->type==0x48000000) { *(u32 *)color=lbl_1_rodata_F88[10]; fn_800371F8(1,color); mode=1; }
        else if(e->type==0x58000000) { *(u32 *)color=lbl_1_rodata_F88[11]; fn_800371F8(1,color); mode=1; }
        if(mode) {
            f32 x = pos->x + ((f32)e->offset * w) / 16777216.0f;
            f32 z = pos->z - 0.002f;
            f32 x2 = pos->x + ((f64)(e->offset+e->size)-4503599627370496.0) * w / 16777216.0f;
            fn_8003462C(128,7,4);
            vertex(x,pos->y,z);
            vertex(x2,pos->y,z);
            vertex(x2,pos->y+h-1.0f,z);
            vertex(x,pos->y+h-1.0f,z);
        }
    }
}
