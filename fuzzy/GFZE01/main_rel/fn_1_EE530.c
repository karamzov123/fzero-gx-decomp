/* Non-matching: best partial attempt (43.46% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
typedef struct { u8 pad[0x328]; s8 field_328; u8 pad2[7]; void *field_330; u8 pad3[0x86]; s16 field_3BA; } Object;
typedef struct { u8 pad[0x330]; u32 unk_330; struct { void **unk_00; void *unk_04; u32 pad; } unk_334[1]; } Obj;
typedef struct { u8 pad[2]; s8 unk_02; } Arg1;
struct Bss { u8 pad0[8]; u32 unk_8; u8 padC[0x14]; u32 unk_20; u8 pad24[0x172a]; u8 count; };
extern struct Bss lbl_1_bss_7B180;
extern const f64 lbl_1_rodata_6B68;
extern const f32 lbl_1_rodata_6B60, lbl_1_rodata_6BD0, lbl_1_rodata_6C18;
extern const f32 lbl_1_rodata_6CFC, lbl_1_rodata_6D00, lbl_1_rodata_6CF4;
extern const f32 lbl_1_rodata_6CEC, lbl_1_rodata_6CF0, lbl_1_rodata_6CF8, lbl_1_rodata_6BBC;
extern u8 lbl_1_data_3E62C[0x80], lbl_1_data_3E73C[0x158];
extern void lbl_8006DD14(void *, void *);
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D668(void *);
extern void lbl_8006DCA4(void);
extern void lbl_8006E0A4(void *);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E14C(f32);
extern void fn_1_56298(f32,f32,f32,f32);
extern void fn_1_5621C(f32,f32,f32,f32);
extern u8 fn_1_5910(void);
extern void fn_1_681C(u32, void *);
extern void fn_1_56000(u8,u8,u8);
extern void fn_1_55FF0(f32);
extern void fn_80072558(void);
extern void fn_1_14E5E4(void *, s32, f32);
extern void fn_1_556B8(void *);
extern void lbl_8006DAEC(void);
extern void fn_1_87610(Object *, void *);
extern void fn_1_875B4(Obj *, Arg1 *, void *, f32);
extern void fn_1_875EC(Obj *, Arg1 *, void *, f32);
extern void fn_80074A60(u32,u32);
extern void fn_80074A6C(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DC20(void);
extern void OSPanic(const char *, int, const char *, ...);
void fn_1_EE530(void) {
    struct Bss *b = &lbl_1_bss_7B180;
    s32 i;
    s32 idx;
    s32 best = -32767;
    u32 *p50 = (u32 *)((u8 *)b + 0x38c4);
    u32 *p30 = (u32 *)((u8 *)b + 0x39b4);
    s32 *p3 = (s32 *)((u8 *)b + 0x39f0);
    u16 *p18 = (u16 *)((u8 *)b + 0x1800);
    void **p16 = (void **)((u8 *)b + 0x1600);
    u32 *p1824 = (u32 *)((u8 *)b + 0x1824);
    void **p17a8 = (void **)((u8 *)b + 0x17a8);
    Object **p1794 = (Object **)((u8 *)b + 0x1794);
    u8 n;
    if (b->unk_8 == 0) return;
    n = b->count;
    idx = n <= 1 ? 0 : n <= 3 ? 1 : 2;
    for (i=0; i<n; i++) {
        f32 a[3], c[3];
        u32 d[12];
        u32 loc50[28];
        f32 dist, val, t;
        s32 who;
        lbl_8006DD14(p50, loc50);
        c[0] = *(f32 *)((u8 *)p30 + 0);
        c[1] = *(f32 *)((u8 *)p30 + 4);
        c[2] = *(f32 *)((u8 *)p30 + 8);
        if (best < *p3) best = *p3;
        if (*p18 > 1) {
            f32 q = *(f32 *)((u8 *)*p16 + (*p1824 * 4 - 4));
            if (q <= (f32)*p18) { } else {
                fn_1_56298(lbl_1_rodata_6B60,lbl_1_rodata_6B60,lbl_1_rodata_6B60,lbl_1_rodata_6B60);
                fn_1_5621C(lbl_1_rodata_6BD0,lbl_1_rodata_6BD0,lbl_1_rodata_6BD0,lbl_1_rodata_6BD0);
                fn_1_681C(fn_1_5910(), a);
                psvec_sub(&c[0], &a[0], &a[0]);
                a[2] = c[2]-a[2];
                dist = lbl_8006D0B4((a[0]*a[0] + a[1]*a[1]) + a[2]*a[2]);
                lbl_8006D668(a);
                psvec_scale(&a[0], lbl_1_rodata_6CFC, &a[0]);
                a[2] *= lbl_1_rodata_6CFC;
                psvec_add(&c[0], &a[0], &a[0]);
                c[2] += a[2];
                fn_1_56000(1,3,1); lbl_8006DCA4(); lbl_8006E0A4(a); lbl_8006DFC4(p50);
                lbl_8006E14C((lbl_1_rodata_6CFC+dist)/dist); fn_80072558(); fn_1_55FF0(lbl_1_rodata_6D00);
                if (b->unk_20 && (u32)i == (u32)(b->count-1))
                    fn_1_5621C(lbl_1_rodata_6C18,lbl_1_rodata_6C18,lbl_1_rodata_6BD0,lbl_1_rodata_6BD0);
                else fn_1_5621C(lbl_1_rodata_6BD0,lbl_1_rodata_6BD0,lbl_1_rodata_6C18,lbl_1_rodata_6BD0);
                if (*p17a8) fn_1_14E5E4(*p17a8, (*p1794)->field_3BA, lbl_1_rodata_6D00);
                else if (*p1794) {
                    fn_1_556B8((*p1794)->field_330);
                    lbl_8006DAEC(); fn_1_87610(*p1794, *p1794);
                    fn_1_875B4((Obj *)*p1794,(Arg1 *)*p1794,(void *)(s8)(*p1794)->field_3BA,lbl_1_rodata_6D00); lbl_8006DC20();
                }
                fn_1_5621C(0,0,0,0); fn_1_56000(1,3,1);
                fn_1_681C(fn_1_5910(), a);
                val = (a[0]-c[0])*(a[0]-c[0]) + (a[1]-c[1])*(a[1]-c[1]) + (a[2]-c[2])*(a[2]-c[2]);
                t=val-lbl_1_rodata_6CF4;
                if (t<0) t=0; else if(t>lbl_1_rodata_6CF0)t=lbl_1_rodata_6CF0;
                dist=lbl_1_rodata_6CEC*(t/lbl_1_rodata_6CF8);
                if(dist<0) dist=0;
                else {
                    t=val-lbl_1_rodata_6CF4; if(t<0)t=0; else if(t>lbl_1_rodata_6CF0)t=lbl_1_rodata_6CF0;
                    t=lbl_1_rodata_6CEC*(t/lbl_1_rodata_6CF8);
                    if(t>lbl_1_rodata_6BBC) dist=lbl_1_rodata_6BBC;
                    else { t=val-lbl_1_rodata_6CF4;if(t<0)t=0;else if(t>lbl_1_rodata_6CF0)t=lbl_1_rodata_6CF0;dist=lbl_1_rodata_6CEC*(t/lbl_1_rodata_6CF8); }
                }
                lbl_8006DCA4(); lbl_8006E0A4(c); lbl_8006DFC4(p50); fn_80072558(); fn_80074A60(4,1);
                if (b->unk_20 && (u32)i==(u32)(b->count-1)) fn_1_5621C(lbl_1_rodata_6C18,lbl_1_rodata_6C18,lbl_1_rodata_6BD0,lbl_1_rodata_6BD0);
                else fn_1_5621C(lbl_1_rodata_6BD0,lbl_1_rodata_6BD0,lbl_1_rodata_6C18,lbl_1_rodata_6BD0);
                if (*p1794) {
                    who=(s8)(*p1794)->field_3BA; lbl_8006DB74(d);
                    if (((u32 *)*p1794)[0x390/4]&0x4000000) {
                        void *v=((void **)*p1794)[0x3a0/4];
                        if(v) fn_1_14E5E4(v,who,dist);
                        else {
                            if ((s8)(*(u8 *)((u8 *)*p1794+0x328))>=41) OSPanic((char *)lbl_1_data_3E62C,3173,(char *)lbl_1_data_3E73C);
                            fn_1_556B8(((void **)*p1794)[(0x334+who*12)/4]); lbl_8006DAEC();
                            fn_1_87610(*p1794,*p1794); fn_1_875EC((Obj *)*p1794,(Arg1 *)*p1794,(void *)(s8)who,dist); lbl_8006DC20();
                        }
                    }
                }
                fn_80074A6C(); fn_1_5621C(1,1,1,1); fn_1_56000(1,3,1);
            }
        }
        p50+=12; p30+=3; p3++; p18++; p16++; p1824++; p17a8++; p1794++;
    }
}
