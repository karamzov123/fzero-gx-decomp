/* Non-matching: best partial attempt (40.92% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/phys.h"

typedef struct { u32 value; const u8 *string; } SVEntry;
typedef struct { s32 count; u32 unused; SVEntry *entries; } SVTable;
typedef struct {
    u8 pad[0x28]; f32 one; u8 p2c[4]; f32 tenth; f32 half; f32 ten;
    u8 p3c[0x44]; f64 two52;
    u8 p88[0x48]; f32 two; u8 pd4[0x30]; f32 nine;
    u8 p108[4]; u32 q10c,q110,q114,q118,q11c,q120;
    f32 eightTenths, tiny, threeTenths, minute, tenMillion, fiveMillion, hundred;
} Pool;
extern Pool lbl_1_rodata_6780;
extern u32 lbl_1_bss_384B4;
extern u32 lbl_801A63C0;
extern u32 lbl_1_data_3DE3C;
extern SVTable *fn_1_7B064(void);
extern u32 fn_1_E86FC(SVTable *, const char *);
extern u32 fn_1_E1E9C(void *);
struct Arg { u8 pad[0xA]; s16 unk_A; };

void fn_1_E252C(u32 arg0, u32 arg1, struct Arg *p) {
    s16 type=(s16)arg0;
    u32 words[6];
    f32 q;
    u32 x, y, z;
    s32 n;
    f64 d;
    f32 a;
    SVTable *t;
    words[0]=lbl_1_rodata_6780.q10c; words[1]=lbl_1_rodata_6780.q110;
    words[2]=lbl_1_rodata_6780.q114; words[3]=lbl_1_rodata_6780.q118;
    words[4]=lbl_1_rodata_6780.q11c; words[5]=lbl_1_rodata_6780.q120;
    q=*(f32 *)&words[p->unk_A];
    *(f32 *)((u8 *)p+0x84)=q;
    *(u32 *)((u8 *)p+0x140)=1 << p->unk_A;

    if (type == 0) {
        *(u16 *)((u8 *)p+0xc)=0;
        *(f32 *)((u8 *)p+0x1a0)=q;
        *(f32 *)((u8 *)p+0x1a4)=lbl_1_rodata_6780.two*q;
        *(f32 *)((u8 *)p+0x18)=lbl_1_rodata_6780.half;
        *(f32 *)((u8 *)p+0x1c)=lbl_1_rodata_6780.one;
        *(f32 *)((u8 *)p+0x20)=lbl_1_rodata_6780.nine;
        *(f32 *)((u8 *)p+0x24)=lbl_1_rodata_6780.eightTenths;
        *(f32 *)((u8 *)p+0x28)=lbl_1_rodata_6780.tiny;
        *(u32 *)p=0;
        *(u32 *)((u8 *)p+0x13c) |= 0x10000;
        *(u32 *)((u8 *)p+0x13c) |= 0x80000;
        *(u32 *)((u8 *)p+0x13c) |= 0x40;
        *(u32 *)((u8 *)p+0x138) |= 0x200;
        *(u32 *)((u8 *)p+0x138) |= 0x100;
        *(u32 *)((u8 *)p+0xbc)=600;
        *(u32 *)((u8 *)p+0xc0)=-1;
    } else if (type == 1 || type == 5) {
        *(u16 *)((u8 *)p+0xc)=0;
        *(f32 *)((u8 *)p+0x18)=lbl_1_rodata_6780.threeTenths;
        *(f32 *)((u8 *)p+0x1c)=lbl_1_rodata_6780.one;
        *(f32 *)((u8 *)p+0x20)=lbl_1_rodata_6780.half;
        *(f32 *)((u8 *)p+0x24)=lbl_1_rodata_6780.half;
        *(f32 *)((u8 *)p+0x28)=lbl_1_rodata_6780.minute;
        *(u32 *)p=0;
        *(u32 *)((u8 *)p+0x13c) |= 0x400;
        *(u32 *)((u8 *)p+0x13c) |= 8;
        *(u32 *)((u8 *)p+0x13c) |= 0x40;
        *(u32 *)((u8 *)p+0x13c) |= 0x20;
        if(type==1) {
            *(u32 *)((u8 *)p+0x13c) |= 0x1000000;
            *(u32 *)((u8 *)p+0x13c) |= 0x2000000;
            *(u32 *)((u8 *)p+0x13c) |= 0x100;
        } else {
            *(u32 *)((u8 *)p+0x13c) |= 0x2000000;
            *(u32 *)((u8 *)p+0x13c) |= 0x100;
        }
    } else if (type == 2) {
        *(u16 *)((u8 *)p+0xc)=0;
        *(f32 *)((u8 *)p+0x18)=lbl_1_rodata_6780.tenth;
        *(f32 *)((u8 *)p+0x1c)=lbl_1_rodata_6780.tenMillion;
        *(f32 *)((u8 *)p+0x20)=lbl_1_rodata_6780.nine;
        *(f32 *)((u8 *)p+0x24)=lbl_1_rodata_6780.eightTenths;
        *(f32 *)((u8 *)p+0x28)=lbl_1_rodata_6780.tiny;
        fn_1_7B064();
        *(u32 *)p=fn_1_E86FC(fn_1_7B064(), (const char *)&lbl_1_data_3DE3C);
    } else if (type == 3 || type == 4) {
        *(u16 *)((u8 *)p+0xc)=0;
        *(f32 *)((u8 *)p+0x18)=lbl_1_rodata_6780.tenth;
        *(f32 *)((u8 *)p+0x1c)=type==3 ? lbl_1_rodata_6780.tenMillion : lbl_1_rodata_6780.fiveMillion;
        *(f32 *)((u8 *)p+0x20)=lbl_1_rodata_6780.nine;
        *(f32 *)((u8 *)p+0x24)=lbl_1_rodata_6780.eightTenths;
        *(f32 *)((u8 *)p+0x28)=lbl_1_rodata_6780.tiny;
        t=fn_1_7B064();
        x=fn_1_E86FC(t,(const char *)&lbl_1_data_3DE3C);
        *(u32 *)p=x;
        if(!x) {
            y=fn_1_E86FC((SVTable *)lbl_1_bss_384B4,(const char *)&lbl_1_data_3DE3C);
            *(u32 *)p=y;
            if(!y) *(u32 *)p=0;
        }
        psvec_scale((u8 *)p+0xf4,lbl_1_rodata_6780.one,(u8 *)p+0xf4);
        *(u32 *)((u8 *)p+0x13c) |= 0x10000;
        *(u32 *)((u8 *)p+0x13c) |= 0x200;
        *(u32 *)((u8 *)p+0x13c) |= 0x40000;
        *(u32 *)((u8 *)p+0x13c) |= 8;
        *(u32 *)((u8 *)p+0x13c) |= 0x40;
        *(u32 *)((u8 *)p+0x13c) |= 0x20;
        *(u32 *)((u8 *)p+0x13c) |= 0x2000;
        *(u32 *)((u8 *)p+0x138) |= 0x10;
        if(type==3) {
            *(u32 *)((u8 *)p+0x138) |= 0x40;
            *(u32 *)((u8 *)p+0x138) |= 0x80;
        }
        *(u32 *)((u8 *)p+0x138) |= 0x800;
        if(type==3) *(u32 *)((u8 *)p+0x138) |= 0x20;
    } else if (type == 5) {
    } else if (type == 4) {
    } else if (type == 3) {
    } else {
        *(u16 *)((u8 *)p+0xc)=0;
        x=lbl_801A63C0;
        x=x*0x676a4b6b+0x33cb;
        lbl_801A63C0=x;
        z=(x>>16)&0x7fff;
        n=(s32)(0x2aaaab * z);
        n=(z-((n+(n<0))*6));
        *(u32 *)((u8 *)p+0x13c) |= 0x80000;
        *(u32 *)((u8 *)p+0x13c) |= 0x40;
        *(u32 *)((u8 *)p+0x13c) |= 0x20;
        *(u32 *)((u8 *)p+0x13c) |= 0x2000000;
        *(u32 *)((u8 *)p+0x13c) |= 0x4000000;
        *(u32 *)((u8 *)p+0x138) |= 2;
    }
    fn_1_E1E9C(p);
}
