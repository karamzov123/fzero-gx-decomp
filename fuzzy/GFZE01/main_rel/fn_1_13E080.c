/* Non-matching: best partial attempt (34.66% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/sel_static_disp.h"
#include "font.h"

extern u32 fn_1_12EF80(u32, void *, void *);
typedef struct {
    u8 field_0; u8 field_1; u16 field_2; u8 field_4; u8 pad_5[3];
    u8 field_8; u8 field_9; u16 field_a; u8 field_c[3]; u8 field_f;
    u8 field_10; u8 field_11; u8 field_12; u8 pad_13; u16 field_14;
    u8 pad_16[2]; u16 field_18;
} Sig_fn_1_128E8C_FnData;
extern void fn_1_128E8C(u32, Sig_fn_1_128E8C_FnData *);
extern f32 lbl_1_rodata_26F8[22];
extern const f64 lbl_1_rodata_8600, lbl_1_rodata_8608;
extern const f32 lbl_1_rodata_85E8, lbl_1_rodata_85F4, lbl_1_rodata_85FC;
extern const f32 lbl_1_rodata_86C4, lbl_1_rodata_8B34, lbl_1_rodata_8E00, lbl_1_rodata_8E04;
extern const f32 lbl_1_rodata_861C, lbl_1_rodata_863C, lbl_1_rodata_85F0, lbl_1_rodata_8E08, lbl_1_rodata_8E0C;
extern const f32 lbl_1_rodata_8E10, lbl_1_rodata_8E14, lbl_1_rodata_8E18, lbl_1_rodata_8E1C, lbl_1_rodata_8E20;
extern const f32 lbl_1_rodata_8E24, lbl_1_rodata_8E28, lbl_1_rodata_8E2C, lbl_1_rodata_8E30, lbl_1_rodata_8E34;
extern const f32 lbl_1_rodata_8664, lbl_1_rodata_87DC;
extern u32 lbl_1_rodata_8DF8, lbl_1_rodata_8DFC;
extern u32 fn_1_486C4(u32);
extern u32 fn_1_48690(u32);
extern void fn_1_50164(f32, f32, f32, f32, void *);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(s16);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49738(void *);
extern void fn_1_52250(void);
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_135D7C(s16, s16, s16, s16, u8, s16, s16, f32, f32, f32);
extern void fn_1_1358BC(s16, s16, s16, s16, u8, u8, u8, u8, f32, f32, f32);

typedef struct { u32 w[22]; } Tmpl;
typedef struct {
    u32 id;
    f32 x,y,z;
    u8 pad10[8];
    f32 a,b,c,d,e,f;
    u8 pad30[8];
    u32 count;
    u8 pad3c[4];
    u32 color;
} Pkt;

void fn_1_13E080(s32 x, s32 y, s32 a, s32 b) {
    s16 code = lbl_1_bss_8B3A0.unk_90;
    struct { s16 col, row; Sig_fn_1_128E8C_FnData sig; } work;
    struct { Tmpl payload; u32 tail; } t;
    Pkt *p;
    s32 sum;
    f32 xf, yf, tmp;
    fn_1_12EF80(code, &work.row, &work.col);
    fn_1_128E8C((u8)(work.col + (work.row - 6) * 6), &work.sig);
    if (work.sig.field_18 == 0 || (work.sig.field_0 == 8 && work.sig.field_1 == 0x2c && work.sig.field_2 == 0x11f)) {
        t.payload = *(Tmpl *)lbl_1_rodata_26F8;
        xf = (f32)x;
        sum = y + b;
        yf = (f32)sum;
        fn_1_50164(xf, yf, 50.0f, 50.0f, (void *)&t.payload);
        fn_1_49410();
        fn_1_494DC(5);
        fn_1_495B0(0x80000000);
        fn_1_49738((void *)fn_1_52250);
        fn_1_49748(lbl_1_rodata_8B34);
        fn_1_495C8(9);
        xf = (f32)(y + (fn_1_486C4(a) >> 16 & 0x7fff));
        yf = (f32)(x + (fn_1_48690(a) >> 16 & 0x7fff));
        fn_1_496FC(xf, yf);
        fn_1_4AE0C((const char *)&lbl_1_data_41E1C);
        return;
    }
    t.payload = *(Tmpl *)lbl_1_rodata_26F8;
    p = (Pkt *)&t.payload;
    p->id = 0x9e05; p->x = (f32)x; p->y = (f32)(y+b); p->z=lbl_1_rodata_8E00;
    fn_1_4F734((FontDrawPacket *)p);
    t.payload = *(Tmpl *)lbl_1_rodata_26F8;
    p=(Pkt *)&t.payload; p->id=0x9e05; p->x=(f32)(x+0xa9); p->y=(f32)(y+0x25); p->z=lbl_1_rodata_8E00; p->count=5;
    fn_1_4F734((FontDrawPacket *)p);
    t.payload = *(Tmpl *)lbl_1_rodata_26F8;
    p=(Pkt *)&t.payload; p->id=0x9e04; p->x=(f32)(x+0xad); p->y=(f32)(y+0x24); p->z=lbl_1_rodata_8E04; p->count=6;
    fn_1_4F734((FontDrawPacket *)p);
    t.payload = *(Tmpl *)lbl_1_rodata_26F8;
    p=(Pkt *)&t.payload; p->id=0x9e25; p->x=(f32)(x+0x3e); p->y=(f32)(y+0x3b); p->z=lbl_1_rodata_8E04; p->a=lbl_1_rodata_861C; p->b=lbl_1_rodata_863C;
    p->c=lbl_1_rodata_85F0; p->d=lbl_1_rodata_8E08; p->e=lbl_1_rodata_8E0C; p->f=lbl_1_rodata_863C; p->count=5;
    fn_1_4F734((FontDrawPacket *)p);
    fn_1_49410(); fn_1_495B0(0x80000000); fn_1_495C8(0); fn_1_494DC(0x24);
    fn_1_4954C(lbl_1_rodata_8E04); fn_1_4955C(lbl_1_rodata_8E10,lbl_1_rodata_8E10);
    fn_1_496FC((f32)(x+0x4a),(f32)(y+0x46));
    fn_1_4AE0C((const char *)lbl_1_data_41E24, work.sig.field_c[0],work.sig.field_c[1],work.sig.field_14);
    if (work.sig.field_10 < 0x29) {
        t.payload=*(Tmpl *)lbl_1_rodata_26F8;
        p=(Pkt *)&t.payload; p->id=0x9e2d; p->x=(f32)(x+0x1d); p->y=(f32)(y+0x3c); p->z=lbl_1_rodata_8E04;
        p->a=lbl_1_rodata_8E18; p->b=lbl_1_rodata_8E14; p->c=lbl_1_rodata_8E20; p->d=lbl_1_rodata_8E14; p->e=lbl_1_rodata_8E1C; p->f=lbl_1_rodata_8E20;p->count=10;
        fn_1_4F734((FontDrawPacket *)p);
        fn_1_135D7C((s16)(x+0x84),(s16)(y+0x2d),0,0,work.sig.field_10,10,0,lbl_1_rodata_8664,lbl_1_rodata_8664,lbl_1_rodata_87DC);
    } else {
        t.payload=*(Tmpl *)lbl_1_rodata_26F8;
        p=(Pkt *)&t.payload; p->id=0x9e2d; p->x=(f32)(x+0x1d);p->y=(f32)(y+0x3c);p->z=lbl_1_rodata_8E04;
        p->a=lbl_1_rodata_8E24;p->b=lbl_1_rodata_863C;p->c=lbl_1_rodata_8E28;p->d=lbl_1_rodata_863C;p->e=lbl_1_rodata_8E1C;p->f=lbl_1_rodata_8E20;p->count=10;
        fn_1_4F734((FontDrawPacket *)p);
        fn_1_1358BC(x+0x84,y+0x2e,0,0,work.sig.field_4,work.sig.pad_5[0],work.sig.pad_5[1],work.sig.pad_5[2],lbl_1_rodata_8E2C,lbl_1_rodata_8E2C,lbl_1_rodata_87DC);
    }
    t.payload=*(Tmpl *)lbl_1_rodata_26F8;
    p=(Pkt *)&t.payload; p->id=0x9e2d; p->x=(f32)(x+0xe2);p->y=(f32)(y+0x3c);p->z=lbl_1_rodata_8E04;
    p->a=lbl_1_rodata_8E18;p->b=lbl_1_rodata_8E14;p->c=lbl_1_rodata_8E20;p->d=lbl_1_rodata_8E14;p->e=lbl_1_rodata_8E1C;p->f=lbl_1_rodata_8E20;p->count=10;
    fn_1_4F734((FontDrawPacket *)p);
}
