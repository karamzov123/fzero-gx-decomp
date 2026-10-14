/* Non-matching: best partial attempt (27.50% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/face.h"
#include "font.h"

typedef struct { u32 words[22]; } Sig_fn_1_51914_fn_1_51914_state;
struct fn_1_C8294_Copy88 { u32 a[22]; };
struct fn_1_C8294_Record { s16 x; s16 y; f32 width; s16 a; s16 b; };
extern Obj_1_bss_7ACD8_Target *fn_1_D2D24(s32);
extern Obj_1_bss_7ACD8_Target *fn_1_D2D58(void *);
extern u8 fn_1_58C4(void);
extern u32 lbl_1_rodata_26F8[22];
extern void fn_1_51914(const Sig_fn_1_51914_fn_1_51914_state *);
extern const f64 lbl_1_rodata_5CE8;
extern const f32 lbl_1_rodata_5C48;
extern const f64 lbl_1_rodata_5C98;
extern u32 fn_1_584AC(void);
extern const f32 lbl_1_rodata_5CA0;
extern const f64 lbl_1_rodata_5CA8;
extern const f64 lbl_1_rodata_5C00;
extern const f32 lbl_1_rodata_5CB0;
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern int fn_1_4F734(FontDrawPacket *);
extern u32 fn_1_D2D38(void);
extern const f32 lbl_1_rodata_5CC8, lbl_1_rodata_5CCC;
extern u32 lbl_1_rodata_5C90;
extern const f64 lbl_1_rodata_5CC0, lbl_1_rodata_5CB8;
extern const f32 lbl_1_rodata_5CD0, lbl_1_rodata_5CD4, lbl_1_rodata_5CD8, lbl_1_rodata_5CDC;
extern void fn_1_51990(void *);
extern s32 fn_1_4FC50(void *, u32, u16, u16, u32);
extern u32 fn_1_53830(u32, u32, void *, void *, f32);
extern u32 fn_1_C7CBC(u32, u32, u32, u32, f32, f32);
extern s32 fn_1_40B20(void);
extern const f32 lbl_1_rodata_5CE0, lbl_1_rodata_5CE4;
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern u32 lbl_1_rodata_5C94;
extern void fn_1_49514(u32 *);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern f32 lbl_8006D188(u32);
extern u32 lbl_1_data_3D570;

s16 fn_1_C8294(struct fn_1_C8294_Record *records, u8 count, s32 mode, f32 arg3) {
    s16 result = -1;
    u32 image = mode ? 0x9437 : 0x9728;
    u32 color = mode ? 0x944c : 0x972f;
    u32 shadow = mode ? 0x9454 : 0x9734;
    u32 image2 = mode ? 0x9453 : 0x9714;
    u32 limit = mode ? 11 : 20;
    struct fn_1_C8294_Copy88 init;
    FontDrawPacket p;
    s32 i;
    s32 j = 2, k = 3, m = 4, n = 5, q = 6, z = 7;
    f32 scale;
    u32 alternate = mode ? 0x9418 : 0x9714;
    if (fn_1_58C4() > 1) return -1;
    if (fn_1_D2D24(0) == 0) return -1;
    init = *(struct fn_1_C8294_Copy88 *)lbl_1_rodata_26F8;
    init.a[0] = image;
    fn_1_51914((const Sig_fn_1_51914_fn_1_51914_state *)&init);
    if (count > 6) count = 6;
    for (i = 0; i < count; i++) {
        Obj_1_bss_7ACD8_Target *obj = fn_1_D2D58((void *)i);
        s32 a = 0, b = 0;
        s32 x, y;
        struct fn_1_C8294_Record *rec = &records[i];
        u32 active = 0;
        if (!obj) goto next;
        if (obj->unk_3C == 0 && obj->unk_38 != 0) {
            scale = (f32)(((f64)obj->unk_38 - lbl_1_rodata_5CE8) / lbl_1_rodata_5C48) * (f32)lbl_1_rodata_5C98;
            a = (s32)(scale * ((f32)(((f64)fn_1_584AC() - lbl_1_rodata_5CE8) / lbl_1_rodata_5CA0) - (f32)lbl_1_rodata_5CA8));
            b = (s32)(scale * ((f32)(((f64)fn_1_584AC() - lbl_1_rodata_5CE8) / lbl_1_rodata_5CA0) - (f32)lbl_1_rodata_5CA8));
        }
        x = (s16)(rec->x + (s16)a);
        y = (s16)(rec->y + (s16)b);
        p = *(FontDrawPacket *)lbl_1_rodata_26F8;
        p.image = color; p.x = (f32)x; p.y = (f32)y;
        *(f32 *)((u8 *)&p + 0x10) = (f32)z;
        fn_1_48690(shadow);
        *(f32 *)((u8 *)&p + 0x14) = rec->width * (f32)((((f64)fn_1_48690(shadow) - lbl_1_rodata_5CE8) / lbl_1_rodata_5CA0) - lbl_1_rodata_5CA8);
        fn_1_486C4(shadow);
        *(f32 *)((u8 *)&p + 0x18) = rec->width * (f32)((((f64)fn_1_486C4(shadow) - lbl_1_rodata_5CE8) / lbl_1_rodata_5CA0) - lbl_1_rodata_5CA8);
        *(u32 *)((u8 *)&p + 0x34) = 10;
        fn_1_4F734(&p);
        active = fn_1_D2D38() ? (obj->unk_18 == 0) : (obj->unk_18 != -1);
        if (active) {
            p = *(FontDrawPacket *)lbl_1_rodata_26F8;
            p.image = shadow; p.x=(f32)x; p.y=(f32)y; *(f32 *)((u8 *)&p+0x10)=(f32)q;
            fn_1_48690(shadow);
            *(f32 *)((u8 *)&p+0x14) = rec->width * (f32)((((f64)fn_1_48690(shadow)-lbl_1_rodata_5CE8)/lbl_1_rodata_5CA0)-lbl_1_rodata_5CA8);
            fn_1_486C4(shadow);
            *(f32 *)((u8 *)&p+0x18) = rec->width * (f32)((((f64)fn_1_486C4(shadow)-lbl_1_rodata_5CE8)/lbl_1_rodata_5CA0)-lbl_1_rodata_5CA8);
            *(u32 *)((u8 *)&p+0x34)=10; fn_1_4F734(&p);
        }
        if (obj->unk_60) {
            p = *(FontDrawPacket *)lbl_1_rodata_26F8;
            p.image = 0x9650; p.x=(f32)x; p.y=(f32)y; *(f32 *)((u8 *)&p+0x10)=(f32)m;
            *(f32 *)((u8 *)&p+0x14)=*(f32 *)((u8 *)&p+0x14)*rec->width*lbl_1_rodata_5CD0;
            *(f32 *)((u8 *)&p+0x18)=*(f32 *)((u8 *)&p+0x18)*rec->width*lbl_1_rodata_5CD0;
            *(u32 *)((u8 *)&p+0x34)=10; fn_1_51990(&p);
            fn_1_4FC50(&p,5,0x40,0x40,obj->unk_60);
        }
        p = *(FontDrawPacket *)lbl_1_rodata_26F8;
        p.image = image2; p.x=(f32)x; p.y=(f32)y; *(f32 *)((u8 *)&p+0x10)=(f32)n;
        fn_1_48690(shadow);
        *(f32 *)((u8 *)&p+0x14)=rec->width*(f32)((((f64)fn_1_48690(shadow)-lbl_1_rodata_5CE8)/lbl_1_rodata_5CA0)-lbl_1_rodata_5CA8);
        fn_1_486C4(shadow);
        *(f32 *)((u8 *)&p+0x18)=rec->width*(f32)((((f64)fn_1_486C4(shadow)-lbl_1_rodata_5CE8)/lbl_1_rodata_5CA0)-lbl_1_rodata_5CA8);
        *(u32 *)((u8 *)&p+0x34)=10; fn_1_4F734(&p);
        if (active) {
            fn_1_53830(0x3c,0x32,(void *)0,(void *)0,rec->width);
            fn_1_C7CBC((u32)records,(u32)count,0,(u32)mode,scale,scale);
        }
        fn_1_4F734(&p);
        if (obj->unk_4 == (u32)fn_1_40B20()) {
            p = *(FontDrawPacket *)lbl_1_rodata_26F8;
            p.image=0x96407; p.x=(f32)y; p.y=lbl_1_rodata_5CE0+(f32)i;
            *(f32 *)((u8 *)&p+0x10)=(f32)j; *(u32 *)((u8 *)&p+0x34)=10; fn_1_4F734(&p);
        }
        fn_1_49410(); fn_1_494DC((s16)limit);
        fn_1_496FC((f32)(rec->a+a),(f32)(rec->b+b));
        fn_1_4954C((f32)j);
        *(u32 *)&p=lbl_1_rodata_5C94; fn_1_49514((u32 *)&p);
        if (!mode) fn_1_4955C(lbl_1_rodata_5CE4,lbl_1_rodata_5CE4);
        fn_1_4AE0C((const char *)&lbl_1_data_3D570,i+1);
        if (active) result=(s16)i;
next:
        j+=10; k+=10; m+=10; n+=10; q+=10; z+=10;
    }
    return result;
}
