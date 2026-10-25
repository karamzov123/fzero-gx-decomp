/* Non-matching: best partial attempt (66.78% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/face.h"

typedef struct { f32 x,y,z; } Vec3;
typedef struct { f32 a[6]; } SixFloats;
typedef struct { u32 a[7]; } SevenWords;
typedef struct { u32 a[29]; } FrameCC;
typedef struct { u32 a[16]; } Frame8C;
typedef struct { u32 a[12]; } Frame5C;

struct Sig_fn_800737E4_fn_800737E4_Arg0 {
    f32 unk_0; u8 pad_4[4]; f32 unk_8; f32 unk_C; u8 pad_10[4];
    f32 unk_14; f32 unk_18; f32 unk_1C; u8 pad_20[8]; f32 unk_28; f32 unk_2C;
};
typedef struct { void *unk_0; void *unk_4; } Entry;
typedef struct { s32 count; u8 pad_4[4]; Entry *entries; } Entries;

extern f32 fn_1_867F8(int);
extern s16 fn_1_3F0C8(void);
extern u8 fn_1_58C4(void);
extern void fn_1_D2F50(void);
extern void fn_1_D2F84(void);
extern void fn_1_550A8(void);
extern void fn_1_550E0(void);
extern void fn_1_56298(f32,f32,f32,f32);
extern void *fn_1_86254(int);
extern void fn_1_556B8(void *);
extern void fn_80038F10(f32 *);
extern void GXGetScissor(u32 *,u32 *,u32 *,u32 *);
extern void GXGetProjectionv(f32 *);
extern void C_MTXPerspective(f32 *,f32,f32,f32,f32);
extern void fn_800737E4(struct Sig_fn_800737E4_fn_800737E4_Arg0 *,s32,f32);
extern void fn_80074918(u8,s32,u8);
extern void fn_80038EEC(f32,f32,f32,f32,f32,f32);
extern void fn_8006F120(Vec3 *,Vec3 *);
extern void fn_80074CF4(f32,f32,f32);
extern void lbl_8006D758(void);
extern void fn_80074300(u16,u16,u16,u16);
extern void fn_80074438(u32,u32,u32,u32);
extern u32 fn_800744F8(void *,u32);
extern void fn_8003526C(void *,u8);
extern void fn_80007C2C(void);
extern void fn_80077A18(void);
extern void *fn_80071268(Entries *,const u8 *);
extern void lbl_8006DFE8(void *);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_z(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void fn_80072558(void);
extern void GXInvalidateTexAll(void);
extern void fn_80072270(SevenWords *,u32,f32,f32);
extern u32 lbl_8006DB74(void *);
extern u32 lbl_8006DD14(void *,void *);
extern f64 fn_80074188(u32,u32,u32,u32);
extern u32 lbl_801A66A0;
extern u32 lbl_1_data_3D924;
extern u8 lbl_1_data_3DB00[0x2C];
extern f32 lbl_1_rodata_60A0[46];
extern Obj_1_bss_7ACD8_Target *lbl_1_bss_7ACD8;
extern u32 lbl_801A6D00;

void fn_1_D27B8(void)
{
    FrameCC cc;
    SixFloats matrix;
    Frame8C vp;
    Frame5C tmp;
    SixFloats cam;
    SevenWords projection;
    Vec3 vec;
    u32 loc18;
    u32 loc14;
    u32 loc10;
    u32 locC;
    u32 word;
    u32 i;
    Obj_1_bss_7ACD8_Target *obj;
    Obj_1_bss_7ACD8_Target *items;
    void *entry;
    void *ship;
    f32 value;
    f32 tmpf;
    f32 angle;
    f32 rate;
    f32 delta;
    u32 idx;
    s32 limit;

    obj = lbl_1_bss_7ACD8;
    if (fn_1_58C4() > 1 || (s32)lbl_1_data_3D924 == -1)
        return;
    fn_1_D2F50();
    lbl_8006DD14((void *)(*(u32 *)&lbl_801A6D00 + 0x30), &cc);
    fn_80038F10(cam.a);
    GXGetScissor(&loc18, &loc14, &loc10, &locC);
    GXGetProjectionv((f32 *)projection.a);
    fn_1_550A8();
    fn_80074918(1,7,0);
    C_MTXPerspective((f32 *)vp.a,5.0f,1.0f,0.1f,90000.0f);
    fn_800737E4((void *)vp.a,0,0.0f);
    fn_80038EEC(512.0f,352.0f,128.0f,128.0f,0.0f,1.0f);
    fn_80074188(512,352,128,128);
    items = obj;
    for (i=0; i<*(u8 *)((u8 *)obj+0xd); i++, items=(void *)((u8 *)items+0x64)) {
        if (items->unk_10 >= 6)
            continue;
        if (fn_1_3F0C8()==42) {
            items->unk_3C=0;
            items->unk_38=0;
        }
        vec.x=lbl_1_rodata_60A0[0x80/4];
        vec.y=lbl_1_rodata_60A0[0x84/4];
        vec.z=lbl_1_rodata_60A0[0x88/4];
        fn_8006F120((Vec3 *)((u8 *)items+0x20),&vec);
        lbl_8006DB74((void *)(*(u32 *)&lbl_801A6D00+0x30));
        if (items->unk_38 && fn_1_3F0C8()==41) {
            if (items->unk_38 % 3 == 0)
                fn_1_56298(0.5f,0.5f,0.5f,0.5f);
            else
                fn_1_56298(0.1f,0.1f,0.1f,0.5f);
        } else
            fn_1_56298(0.0f,0.0f,0.0f,0.0f);
        value=fn_1_867F8(items->unk_4);
        if (value < 25.0f && fn_1_3F0C8()==41) {
            limit=value < 15.0f ? 15 : 30;
            tmpf=(f32)(lbl_801A66A0 % limit)/(f32)limit;
            if (tmpf < 0.1f) angle=0.1f;
            else if (tmpf > 1.0f) angle=1.0f;
            else angle=tmpf;
            fn_80074CF4(1.0f,angle,angle);
        } else
            fn_80074CF4(1.0f,1.0f,1.0f);
        entry=*(void **)((u8 *)obj->unk_4 + items->unk_4*4);
        lbl_8006D758();
        fn_80074300(512,352,128,128);
        fn_80074438(64,64,5,1);
        word=*(u32 *)((u8 *)lbl_1_rodata_60A0+0x7c);
        fn_800744F8(&word,0xffffff);
        fn_8003526C((void *)items->unk_60,1);
        fn_80007C2C();
        if (entry != 0) {
            fn_80077A18();
            lbl_8006DB74(&tmp);
            entry=fn_80071268(entry,(u8 *)lbl_1_data_3DB00);
            if (entry != 0) {
                lbl_8006DFE8(&tmp);
                mathutil_mtxA_rotate_x(-16384);
                mathutil_mtxA_rotate_z(-16384);
                fn_1_3F0C8();
                fn_80072558();
                fn_1_556B8(entry);
            }
            fn_8003526C((void *)items->unk_60,1);
        }
        GXInvalidateTexAll();
        fn_1_56298(0.0f,0.0f,0.0f,0.0f);
    }
    fn_80074918(1,3,1);
    fn_1_550E0();
    lbl_8006DD14(&cc,(void *)(*(u32 *)&lbl_801A6D00+0x30));
    fn_80038EEC(cam.a[0],cam.a[1],cam.a[2],cam.a[3],cam.a[4],cam.a[5]);
    fn_80074188(vec.x,word,idx,limit);
    fn_80072270(&projection,0,0.0f,0.0f);
    fn_1_D2F84();
}
