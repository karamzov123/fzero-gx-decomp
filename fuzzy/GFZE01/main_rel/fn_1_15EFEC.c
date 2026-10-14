/* Non-matching: best partial attempt (60.78% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"

struct Pool {
    u8 pad0[8]; f64 bias; u8 pad10[4]; f32 x; u8 pad18[4]; f32 one, small;
    u8 pad24[12]; f32 white; u8 pad34[8]; f32 half; u8 pad40[24];
    f32 tiny, three; u8 pad60[0x84]; f32 onehalf; u8 padE8[4]; f32 nine;
    u8 padF0[12]; f32 center, eighth; u8 pad104[4]; f64 two52;
    u8 pad110[0x60]; f32 fifteen, threehundred; u8 pad178[0x18]; f32 hundredth;
};
extern struct Pool lbl_1_rodata_DD58;
extern f32 lbl_1_rodata_26F8[22];
extern u8 lbl_1_data_3D544[];
extern u8 lbl_1_bss_8FDA8[];
extern u8 lbl_1_data_4C9A0[];
extern void fn_1_49410(void); extern void fn_1_495FC(void); extern void fn_1_495C8(u8);
extern u8 fn_1_3F864(void); extern void fn_1_A2D84(u32);
extern f32 fn_1_519FC(f32); extern f32 fn_1_51AC0(f32);
extern u32 fn_1_15C4EC(void *);
extern u8 fn_1_58C4(void);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_15E7F4(void *, u32);
extern void fn_1_494DC(s16); extern void fn_1_495B0(u32);
extern void fn_1_4955C(f32, f32); extern void fn_1_495A0(f32);
extern void fn_1_496FC(f32, f32); extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_15EC40(void *); extern void fn_1_49728(u8);
extern f32 lbl_8006D188(s32); extern f32 lbl_8006D0B4(f32);

void fn_1_15EFEC(s32 index) {
    u8 *obj = lbl_1_bss_8FDA8 + index * 0x34;
    u32 flags;
    FontDrawPacket p;
    f32 a, b, c;
    u32 color;
    u8 n;
    fn_1_49410();
    fn_1_495FC();
    fn_1_495C8(9);
    flags = *(u32 *)(lbl_1_data_3D544 + index * 4);
    if (flags & 4) {
        n = obj[10];
        if (n) {
            if (n == 255) {
                if (fn_1_3F864()) {
                    fn_1_A2D84(0xa9061a00);
                    fn_1_A2D84(0xa9092800);
                }
                obj[10] = 120;
                n = 120;
            }
            p = *(FontDrawPacket *)lbl_1_rodata_26F8;
            p.x = fn_1_519FC(lbl_1_rodata_DD58.x);
            p.y = fn_1_51AC0(lbl_1_rodata_DD58.center);
            p.z = lbl_1_rodata_DD58.hundredth;
            p.image = 0x10000 - 0x6bcf;
            p.flags = 0x40000a;
            p.vertex_callback = (void (*)(FontDrawPacket *, FontVertex *))fn_1_15C4EC;
            *(f32 *)((u8 *)&p + 84) = (f32)index;
            a = fn_1_58C4() == 1 ? lbl_1_rodata_DD58.one : lbl_1_rodata_DD58.small;
            p.scale_x *= a;
            b = fn_1_58C4() == 1 ? lbl_1_rodata_DD58.one : lbl_1_rodata_DD58.small;
            p.scale_y *= b;
            if (n > 90) {
                c = lbl_8006D188((120 - n) * 1092);
                p.scale_y *= lbl_8006D0B4(lbl_1_rodata_DD58.one - c * c);
                p.color_add[0] = p.color_add[1] = p.color_add[2] = (s32)(lbl_1_rodata_DD58.white * c);
            } else if (n < 8) {
                a = n * lbl_1_rodata_DD58.eighth;
                p.alpha = a;
                p.scale_y *= a;
                p.scale_x *= lbl_1_rodata_DD58.three - lbl_1_rodata_DD58.onehalf * a;
            }
            fn_1_4F734(&p);
            if (obj[2]) fn_1_15E7F4(obj, index);
            else goto second;
        } else goto second;
    } else goto third;
second:
    if (obj[1]) {
        n = obj[1];
        if (n == 255) {
            if (fn_1_3F864()) fn_1_A2D84(0xa9061600);
            obj[1] = 120;
            n = 120;
        }
        p = *(FontDrawPacket *)lbl_1_rodata_26F8;
        p.x = fn_1_519FC(lbl_1_rodata_DD58.x);
        p.y = fn_1_51AC0(lbl_1_rodata_DD58.center);
        p.z = lbl_1_rodata_DD58.tiny;
        p.image = 0x10000 - 0x6bf5;
        p.flags = 0x40000a;
        p.vertex_callback = (void (*)(FontDrawPacket *, FontVertex *))fn_1_15C4EC;
        *(f32 *)((u8 *)&p + 84) = (f32)index;
        a = fn_1_58C4() == 1 ? lbl_1_rodata_DD58.one : lbl_1_rodata_DD58.small;
        p.scale_x *= lbl_1_rodata_DD58.nine * a;
        b = fn_1_58C4() == 1 ? lbl_1_rodata_DD58.one : lbl_1_rodata_DD58.small;
        p.scale_y *= lbl_1_rodata_DD58.nine * b;
        if (fn_1_58C4() > 1) { p.scale_x *= lbl_1_rodata_DD58.small; p.scale_y *= lbl_1_rodata_DD58.small; }
        if (n > 90) p.color_add[0] = p.color_add[1] = p.color_add[2] = (s32)(lbl_1_rodata_DD58.white * lbl_8006D188((120-n)*1092));
        else if (n < 8) { a=n*lbl_1_rodata_DD58.eighth; p.alpha=a; p.scale_y*=a; p.scale_x*=lbl_1_rodata_DD58.three-lbl_1_rodata_DD58.onehalf*a; }
        fn_1_4F734(&p);
    }
third:
    n = obj[3];
    if (n && (flags & 0x1000000)) {
        if(n>75) { b=(90-n)/lbl_1_rodata_DD58.fifteen; a=lbl_1_rodata_DD58.half*b; }
        else if(n<15) { b=n/lbl_1_rodata_DD58.fifteen; a=lbl_1_rodata_DD58.half*b; }
        else { a=lbl_1_rodata_DD58.half; b=lbl_1_rodata_DD58.one; }
        fn_1_494DC(10); fn_1_495B0(0x80000000);
        c=fn_1_58C4()==1 ? lbl_1_rodata_DD58.one : lbl_1_rodata_DD58.small;
        (void)fn_1_58C4();
        fn_1_4955C(b*lbl_1_rodata_DD58.small,c);
        fn_1_495A0(a);
        fn_1_496FC(fn_1_519FC(lbl_1_rodata_DD58.x),fn_1_51AC0(lbl_1_rodata_DD58.threehundred));
        color=*(u32 *)(obj+4);
        fn_1_4AE0C((char *)lbl_1_data_4C9A0,(color>>20)&255,(color>>12)&255,color&4095);
    }
    if(obj[9] && (flags&0x400000)) fn_1_15EC40(obj);
    else if(!obj[9]) obj[0]&=~0x18;
    a=obj[3]/lbl_1_rodata_DD58.fifteen;
    if(a>lbl_1_rodata_DD58.one) a=lbl_1_rodata_DD58.one;
    obj[0x30]=(f32)obj[8]-a;
    fn_1_49728(0);
}
