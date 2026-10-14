/* Non-matching: best partial attempt (39.53% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#include "rel/main_rel/enemy_ctrl.h"

struct Packet88 { u32 w[22]; };
extern u32 fn_1_5910(void);
extern u32 lbl_1_rodata_5FB8[2], lbl_1_rodata_5FC0[2];
extern u32 lbl_1_rodata_5FC8;
extern f32 lbl_1_rodata_26F8[22];
extern const f32 lbl_1_rodata_5D90, lbl_1_rodata_5D04, lbl_1_rodata_5CFC;
extern const f32 lbl_1_rodata_5FD0, lbl_1_rodata_5FCC, lbl_1_rodata_5FD4, lbl_1_rodata_5FD8;
extern const f32 lbl_1_rodata_5FDC, lbl_1_rodata_5C3C, lbl_1_rodata_5C40;
extern const f64 lbl_1_rodata_5C00, lbl_1_rodata_5FE0, lbl_1_rodata_5CE8;
extern const f32 lbl_1_rodata_5C48, lbl_1_rodata_5CCC, lbl_1_rodata_5DC8;
extern const f32 lbl_1_rodata_5E90, lbl_1_rodata_5CF4, lbl_1_rodata_5FE8;
extern const f32 lbl_1_rodata_5CB0, lbl_1_rodata_5FEC, lbl_1_rodata_5CD8, lbl_1_rodata_5F98;
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern void fn_1_49410(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_495C8(u8);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_494DC(s16);
extern void fn_1_495B0(u32);
extern void fn_1_49514(u32 *);
extern void fn_1_49590(f32);
extern void fn_1_4955C(f32, f32);
extern int fn_1_8623C(void);
extern u8 *fn_1_3F0D8(u32, f32 *, u8 *);
extern f32 lbl_8006D188(u32);

static u32 flags(void) { return ((u32 *)((u8 *)&lbl_1_data_3D290 + 0x2B4))[fn_1_5910()]; }
static void init(struct Packet88 *p) { *p = *(struct Packet88 *)(void *)lbl_1_rodata_26F8; }

void fn_1_CEB38(u32 arg0) {
    struct Packet88 p;
    u32 v, raw, ix, sec, rem, i;
    f32 t, q, x, y;
    u8 *s;
    (void)arg0;
    if (flags() & 0x800) {
        raw = lbl_1_bss_84.unk_0 ? lbl_1_bss_84.unk_0->unk_0 : 0;
        ix = lbl_1_bss_84.unk_10;
        t = lbl_1_bss_84.unk_0 ? (f32)raw : 0.0f;
        q = t > 15.0f ? 1.0f : t / 15.0f;
        init(&p); p.w[0] = 0xBA0E;
        x = (32.0f + 112.0f*q) / 144.0f;
        p.w[1] = *(u32 *)&x;
        *(f32 *)&p.w[2] = ((f32 *)lbl_1_rodata_5FB8)[ix] + (320.0f-((f32 *)lbl_1_rodata_5FB8)[ix])*q;
        *(f32 *)&p.w[3] = ((f32 *)lbl_1_rodata_5FC0)[ix] + (240.0f-((f32 *)lbl_1_rodata_5FC0)[ix])*q;
        *(f32 *)&p.w[4] = x; *(f32 *)&p.w[5] = x;
        *(f32 *)&p.w[11] = q < .2f ? 0.0f : q; p.w[12]=10;
        fn_1_4F734((FontDrawPacket *)&p);
    }
    if (flags() & 0x400) {
        init(&p); p.w[0]=0xBA0B;
        *(f32 *)&p.w[1]=320.0f; *(f32 *)&p.w[2]=240.0f;
        if (flags() & 8) *(f32 *)&p.w[2]-=44.0f;
        p.w[12]=10; fn_1_4F734((FontDrawPacket *)&p);
    }
    if (flags() & 0x80) { init(&p); p.w[0]=0xBA15; *(f32 *)&p.w[1]=320.0f; *(f32 *)&p.w[2]=240.0f; p.w[12]=10; fn_1_4F734((FontDrawPacket *)&p); }
    if (flags() & 0x40) { fn_1_49410(); fn_1_496FC(320.0f,240.0f); fn_1_495C8(9); fn_1_4AE0C((char *)&lbl_1_data_3D290+0x320); }
    if (flags() & 0x20) { fn_1_49410(); fn_1_496FC(320.0f,240.0f); fn_1_495C8(9); fn_1_4AE0C((char *)&lbl_1_data_3D290+0x32c); }
    if (flags() & 8) {
        raw=lbl_1_bss_84.unk_0 ? lbl_1_bss_84.unk_0->unk_0 : 0;
        sec=raw/60; rem=raw%60; init(&p); p.w[0]=0xBA09;
        *(f32 *)&p.w[1]=320.0f; *(f32 *)&p.w[2]=240.0f;
        *(f32 *)&p.w[3]=(f32)rem/10.0f+1.0f; *(f32 *)&p.w[4]=1.0f-(f32)rem/30.0f;
        *(f32 *)&p.w[11]=*(f32 *)((u8 *)&p+0xe0)-.01f;
        p.w[12]=10; fn_1_51678((FontDrawPacket *)&p,0,(s16)(sec*60),0,60,52); fn_1_4F734((FontDrawPacket *)&p);
    }
    if (flags() & 0x200) {
        raw=lbl_1_bss_84.unk_0 ? lbl_1_bss_84.unk_0->unk_0 : 0; init(&p);
        if ((f64)raw-4503601774854144.0 > 105.0) {
            p.w[0]=0xBA09; *(f32 *)&p.w[1]=320; *(f32 *)&p.w[2]=240;
            q=((f32)(raw-105))/15.0f;
            *(f32 *)&p.w[11]=1.0f-q; *(f32 *)&p.w[5]=1.0f+9.0f*q; *(f32 *)&p.w[6]=1.0f+9.0f*q;
            p.w[12]=10; fn_1_4F734((FontDrawPacket *)&p);
        } else {
            t=(f32)raw-105.0f; v=(u32)t; sec=v/60;
            ix = (u32)(lbl_1_bss_84.unk_0) - sec*0x444;
            for (i=0; i<16; i++) {
                f32 a = lbl_8006D188(ix-i*0x800);
                f32 d = (f32)i;
                init(&p); p.w[0]=0xBA09;
                *(f32 *)&p.w[1]=320.0f;
                *(f32 *)&p.w[2]=240.0f;
                *(f32 *)&p.w[3]=100.0f+27.5f*d;
                *(f32 *)&p.w[4]=240.0f*d;
                *(f32 *)&p.w[5]=320.0f*d;
                *(f32 *)&p.w[6]=255.0f*(.5f*(1.0f+a));
                *(f32 *)&p.w[7]=255.0f*(.5f*(1.0f+a));
                *(f32 *)&p.w[8]=255.0f*(.5f*(1.0f+a));
                p.w[12]=10; fn_1_4F734((FontDrawPacket *)&p);
            }
        }
    }
    if (flags() & 0x100) {
        raw=lbl_1_bss_84.unk_0 ? lbl_1_bss_84.unk_0->unk_0 : 0; init(&p);
        if ((f64)raw-4503601774854144.0 > 105.0) {
            p.w[0]=0xBA0C; *(f32 *)&p.w[1]=320; *(f32 *)&p.w[2]=240;
            q=((f32)(raw-105))/15.0f; *(f32 *)&p.w[11]=1-q; *(f32 *)&p.w[5]=1+9*q; *(f32 *)&p.w[6]=1+9*q; p.w[12]=10; fn_1_4F734((FontDrawPacket *)&p);
        } else { t=(f32)raw-105; v=(u32)t; q=(f32)(v%60)/10; init(&p); p.w[0]=0xBA0C; *(f32 *)&p.w[1]=320; *(f32 *)&p.w[2]=240; *(f32 *)&p.w[3]=100; *(f32 *)&p.w[7]=1+q*.0625f; *(f32 *)&p.w[8]=1+q*.0625f; *(f32 *)&p.w[11]=1-q; p.w[12]=9; fn_1_4F734((FontDrawPacket *)&p); }
    }
    if (flags() & 2) { init(&p); raw=lbl_1_bss_84.unk_0 ? lbl_1_bss_84.unk_0->unk_0 : 0; p.w[0]=0xBA0C; *(f32 *)&p.w[1]=320; *(f32 *)&p.w[2]=240; *(f32 *)&p.w[3]=15; p.w[12]=10; fn_1_4F734((FontDrawPacket *)&p); }
    if (flags() & 0x40000000) {
        ix=fn_1_8623C(); x=0; y=0; s=fn_1_3F0D8(ix,&x,(u8 *)&y);
        fn_1_49410(); fn_1_494DC(5); fn_1_495B0(0x80000000); fn_1_495C8(2); fn_1_496FC(320,320);
        fn_1_49514(&lbl_1_rodata_5FC8); fn_1_49590(.5f); fn_1_4955C(1.5f,1.5f); fn_1_4AE0C((char *)&lbl_1_data_3D290+0x334);
        fn_1_49410(); fn_1_494DC(5); fn_1_4955C(1.5f,1.5f); fn_1_496FC(320,320); fn_1_4AE0C((char *)&lbl_1_data_3D290+0x340,s[0x1e0],s[0x1e1],*(u16 *)(s+0x1e2));
    }
    if (flags() & 0x20000000) { init(&p); p.w[0]=0xBA01; *(f32 *)&p.w[1]=320; *(f32 *)&p.w[2]=240; p.w[12]=10; fn_1_4F734((FontDrawPacket *)&p); }
}
