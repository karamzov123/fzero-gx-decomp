/* Non-matching: best partial attempt (34.77% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"

extern u32 lbl_1_rodata_8C78;
extern u32 lbl_1_rodata_8C7C;
extern f32 lbl_1_rodata_26F8[22];
extern u32 lbl_1_rodata_8C80;
extern u32 lbl_1_rodata_8C84;
extern u32 lbl_1_rodata_8C88;
extern u32 lbl_1_rodata_8C8C;
extern u32 lbl_1_rodata_8C90;
extern u32 lbl_1_rodata_8C94;
extern u32 lbl_1_rodata_8C98;
extern u32 lbl_801A66A0;
extern const f64 lbl_1_rodata_8600;
extern const f64 lbl_1_rodata_8CA0;
extern const f64 lbl_1_rodata_8CA8;
extern const f32 lbl_1_rodata_8A54;
extern const f32 lbl_1_rodata_8B3C;
extern const f32 lbl_1_rodata_8C9C;
extern const f32 lbl_1_rodata_85F0;
extern int fn_1_4F734(FontDrawPacket *);
extern u16 fn_1_48690(u32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);

s32 fn_1_13B548(s32 arg0, s32 x, s32 y, u32 mode) {
    FontDrawPacket p;
    u32 loc_C, loc_8;
    u32 rem, t, n;
    s32 a = 0, b = 0, c = 9;
    u32 m = mode & 255;
    s32 ret = 0;
    if (arg0 != 0) {
        p = *(FontDrawPacket *)lbl_1_rodata_26F8;
        p.x = (f32)x; p.y = (f32)y; p.z = lbl_1_rodata_8C9C;
        if (m == 6 || m == 0 || (m >= 5 && m < 6) || (m >= 7 && m < 9)) {
            p.image = 0x10000 - 25079;
            fn_1_4F734(&p);
        } else if (m > 0 && m < 5) {
            p.image = 0x10000 - 25071;
            fn_1_4F734(&p);
        }
        t = lbl_801A66A0;
        rem = t - (((u32)(((u64)0x88898889U * t) >> 32) >> 5) * 60);
        n = (30U << __cntlzw(rem ^ 30U)) >> 31;
        if (n) p.image = lbl_1_rodata_8C80;
        else p.image = lbl_1_rodata_8C84;
        if (m == 0) {
            t = lbl_801A66A0;
            rem = t - (((u32)(((u64)0x88898889U * t) >> 32) >> 7) * 240);
            n = (u32)(((s64)(s32)0x88898889 * (s64)(s32)rem) >> 32);
            n = (n + rem) >> 5;
            n += (s32)n >> 31;
            if (n == 0) { a = rem / 30; if (a > 10) a = 11; }
            if (n == 1) { b = rem / 30; if (b > 10) b = 11; }
            if (n == 2) { c = 9 - rem / 30; if (rem / 30 > 9) c = 0; }
            if (n == 3) { c = rem / 30 + 10; if (rem / 30 > 9) c = 19; }
            p = *(FontDrawPacket *)lbl_1_rodata_26F8;
            p.image = 0x10000 - 25070; p.x = (f32)((f64)15.5 + x); p.y = (f32)(y - 2); p.z = lbl_1_rodata_8A54;
            fn_1_4F734(&p);
            fn_1_51678(&p,p.image,0,(s16)c,(s16)fn_1_48690(p.image),10);
            p.z = lbl_1_rodata_8B3C; p.y += (f32)c; *(u32 *)((u8 *)&p+60)=lbl_1_rodata_8C88; fn_1_4F734(&p);
            p = *(FontDrawPacket *)lbl_1_rodata_26F8;
            p.image=0x10000-25077; p.x=(f32)(x-8); p.y=(f32)y; p.z=lbl_1_rodata_8A54;
            fn_1_4F734(&p); fn_1_51678(&p,p.image,0,0,8,(s16)a); *(u32 *)((u8 *)&p+60)=lbl_1_rodata_8C8C; p.z=lbl_1_rodata_8B3C; fn_1_4F734(&p);
            p = *(FontDrawPacket *)lbl_1_rodata_26F8;
            p.image=0x10000-25077; p.x=(f32)(x+37); p.y=(f32)y; p.z=lbl_1_rodata_8A54; p.flags=0x80000;
            fn_1_4F734(&p); fn_1_51678(&p,p.image,0,0,8,(s16)b); *(u32 *)((u8 *)&p+60)=lbl_1_rodata_8C90; p.z=lbl_1_rodata_8B3C; fn_1_4F734(&p);
        } else if (m == 1 || m == 2) {
            t=lbl_801A66A0; rem=t-(((u32)(((u64)0x88898889U*t)>>32)>>6)*120);
            n=(u32)(((s64)(s32)0x88898889*(s64)(s32)rem)>>32); n=(n+rem)>>5; n+=(s32)n>>31;
            a=0;b=0;if(n==0){a=rem/30;if(a>10)a=11;} if(n==1){b=rem/30;if(b>10)b=11;}
            p=*(FontDrawPacket *)lbl_1_rodata_26F8; p.image=0x10000-25077;p.x=(f32)(x-8);p.y=(f32)y;p.z=lbl_1_rodata_8A54;fn_1_4F734(&p);fn_1_51678(&p,p.image,0,0,8,(s16)a);*(u32 *)((u8 *)&p+60)=lbl_1_rodata_8C94;p.z=lbl_1_rodata_8B3C;fn_1_4F734(&p);
            p=*(FontDrawPacket *)lbl_1_rodata_26F8;p.image=0x10000-25077;p.x=(f32)(x+37);p.y=(f32)y;p.z=lbl_1_rodata_8A54;p.flags=0x80000;fn_1_4F734(&p);fn_1_51678(&p,p.image,0,0,8,(s16)b);*(u32 *)((u8 *)&p+60)=lbl_1_rodata_8C98;p.z=lbl_1_rodata_8B3C;fn_1_4F734(&p);
        } else if (m==3 || m==4) {
            p=*(FontDrawPacket *)lbl_1_rodata_26F8;p.image=0x10000-25072;p.x=(f32)(x+6);p.y=(f32)(y+6);p.z=lbl_1_rodata_8A54;*(u32 *)((u8 *)&p+60)=lbl_1_rodata_8C80;fn_1_4F734(&p);
            p=*(FontDrawPacket *)lbl_1_rodata_26F8;p.image=0x10000-25072;p.x=(f32)(x+24);p.y=(f32)(y+6);p.z=lbl_1_rodata_8A54;p.flags=0x80000;*(u32 *)((u8 *)&p+60)=lbl_1_rodata_8C84;fn_1_4F734(&p);
        } else if (m==6) {
            p=*(FontDrawPacket *)lbl_1_rodata_26F8;p.image=0x10000-25081;p.x=(f32)((f64)16.5+x);p.y=(f32)(y+9);p.z=lbl_1_rodata_8A54;*(u32 *)((u8 *)&p+60)=lbl_1_rodata_8C80;fn_1_4F734(&p);
            p=*(FontDrawPacket *)lbl_1_rodata_26F8;p.image=0x10000-25081;p.x=(f32)(x+27);p.y=(f32)(y+9);p.z=lbl_1_rodata_8A54;p.scale_x*=lbl_1_rodata_85F0;p.scale_y*=lbl_1_rodata_85F0;*(u32 *)((u8 *)&p+60)=lbl_1_rodata_8C80;fn_1_4F734(&p);
        } else if (m==5) {
            p=*(FontDrawPacket *)lbl_1_rodata_26F8;p.image=0x10000-25080;p.x=(f32)(x+3);p.y=(f32)(y+5);p.z=lbl_1_rodata_8A54;*(u32 *)((u8 *)&p+60)=lbl_1_rodata_8C80;fn_1_4F734(&p);
        } else if (m==7 || m==8) {
            p=*(FontDrawPacket *)lbl_1_rodata_26F8;p.image=0x10000-25082;p.x=(f32)(x+14);p.y=(f32)(y+1);p.z=lbl_1_rodata_8A54;*(u32 *)((u8 *)&p+60)=lbl_1_rodata_8C80;fn_1_4F734(&p);
        }
    }
    if (m<=2) ret=43; else if(m==3||m==4) ret=35; else if(m==6) ret=39; else if(m==5||m==7||m==8) ret=24;
    return ret;
}
