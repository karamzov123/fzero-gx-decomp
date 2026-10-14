/* Non-matching: best partial attempt (29.68% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/camera.h"

extern u8 lbl_1_data_32A8[12];
extern u32 lbl_801A6D00;
extern u32 lbl_801A66CC;
extern const f32 lbl_1_rodata_188;
extern const f32 lbl_1_rodata_18C;
extern const f32 lbl_1_rodata_190;
extern const f32 lbl_1_rodata_194;
extern const f32 lbl_1_rodata_198;
extern const f32 lbl_1_rodata_19C;
extern const f32 lbl_1_rodata_1A0;
extern const f32 lbl_1_rodata_1A4;
extern const f32 lbl_1_rodata_1A8;
extern const f32 lbl_1_rodata_1AC;
extern const f64 lbl_1_rodata_1B0;
extern const f32 lbl_1_rodata_1B8;
extern const f64 lbl_1_rodata_1C0;
extern const f32 lbl_1_rodata_1C8;
extern const f64 lbl_1_rodata_1D0;
extern const f32 lbl_1_rodata_1D8;
extern const f64 lbl_1_rodata_1E0;
extern CameraState *camera_get_state_object(void);
extern u32 camera_update_state(CameraState *);
extern f32 fn_1_A6FE8(void);
typedef struct { s16 x,y,z; } Sig_fn_1_549F4_Angles;
typedef struct { f32 x,y,z; } Sig_fn_1_549F4_Vec3;
extern void fn_1_549F4(Sig_fn_1_549F4_Vec3 *, Sig_fn_1_549F4_Angles *, f32, f32, f32, f32);
extern u32 fn_1_A7024(f32,f32,f32,f32);
extern u16 fn_1_A5D88(void);
extern u16 fn_1_A5DB0(void);
extern s32 fn_1_A5DC4(void);
extern void fn_1_54E00(void *);
extern void fn_1_727C(void);
extern u32 lbl_8006DD14(u32, void *);
extern void fn_8006F4E0(void *);
extern void OSReport(const char *, ...);
extern void OSPanic(const char *, int, const char *, ...);
extern u32 fn_80038EEC(f32,f32,f32,f32,f32,f32);
extern u32 __cvt_fp2unsigned(f32);
extern u32 fn_80074188(u32,u32,u32,u32);
extern u32 fn_80007CDC(f32 *);
extern u32 fn_80007D58(f32 *);
extern void *lbl_8006D784(void *);

typedef struct {
    Obj_1_bss_F68_Target *obj;
    Obj_1_bss_F68_Target *model;
    Obj_1_bss_F68_Target *camera;
} StateRefs;

void fn_1_5948(u32 arg0) {
    StateRefs *refs = (StateRefs *)&lbl_1_bss_F68;
    #define obj (refs->obj)
    u8 *data = lbl_1_data_32A8;
    CameraState *camera;
    Sig_fn_1_549F4_Angles angles;
    f32 x, y;
    f32 red, green, blue, alpha, er, eg, eb, ea;
    u32 r, g, b, a;
    Obj_1_bss_F68_Target *work;
    f32 *position;
    f32 *rotation;
    f32 *scale;
    f32 *other;
    f32 size, speed, factor;
    u32 i;

    if ((s8)obj->unk_48 == 11)
        goto done;
    obj->unk_4A = (u8)arg0;
    if (obj->unk_0 & 0x80000000) {
        lbl_8006DD14(lbl_801A6D00 + 0x30, (void *)lbl_801A66CC);
        camera = camera_get_state_object();
        camera_update_state(camera);
        fn_8006F4E0(&angles);
        x = fn_1_A6FE8();
        fn_1_549F4((Sig_fn_1_549F4_Vec3 *)((u8 *)camera + 4), &angles,
                   *(f32 *)((u8 *)camera + 0x1c), x, lbl_1_rodata_188, lbl_1_rodata_188);
        y = fn_1_A6FE8();
        fn_1_A7024(*(f32 *)((u8 *)camera + 0x1c), y, lbl_1_rodata_18C, lbl_1_rodata_190);
        goto done;
    }

    x = (f32)(u32)fn_1_A5D88();
    x -= (f32)lbl_1_rodata_1E0;
    y = (f32)(u32)fn_1_A5DB0();
    y -= (f32)lbl_1_rodata_1E0;

    switch ((s32)arg0) {
    case 0:
        switch ((s8)obj->unk_48) {
        case 1: red=lbl_1_rodata_188; green=lbl_1_rodata_194; blue=lbl_1_rodata_198; alpha=lbl_1_rodata_188; er=lbl_1_rodata_188; break;
        case 2: red=lbl_1_rodata_188; green=lbl_1_rodata_198; blue=lbl_1_rodata_194; alpha=lbl_1_rodata_188; er=lbl_1_rodata_188; break;
        case 3: red=0.0f; green=1.0f; blue=0.5f; alpha=0.0f; er=0.0f; break;
        case 4: red=0.5f; green=0.5f; blue=0.5f; alpha=0.0f; er=0.5f; break;
        case 5: case 6: case 7: case 8: red=0.0f; green=0.5f; blue=0.5f; alpha=0.0f; er=0.0f; break;
        case 10: red=0.0f; green=1.0f; blue=1.0f; alpha=0.0f; er=0.2f; break;
        default:
            if ((s8)obj->unk_48 > 10) {
                OSReport((const char *)(data+0x1a4), arg0);
                OSPanic((const char *)(data+0x70), 0x252, (const char *)(data+0x1b8));
            }
            red=0.0f; green=0.0f; blue=0.0f; alpha=1.0f; er=0.0f; break;
        }
        ea=1.0f;
        break;
    case 1:
        switch ((s8)obj->unk_48) {
        case 1: red=0.5f; green=1.0f; blue=0.5f; alpha=0.0f; ea=1.0f; break;
        case 2: red=0.0f; green=0.5f; blue=1.0f; alpha=0.5f; ea=1.0f; break;
        case 3: red=0.5f; green=0.5f; blue=0.5f; alpha=0.0f; ea=1.0f; break;
        case 4: red=0.0f; green=1.0f; blue=0.5f; alpha=0.0f; ea=1.0f; break;
        case 5: case 6: case 7: case 8: red=0.0f; green=0.5f; blue=0.5f; alpha=0.5f; ea=1.0f; break;
        case 10: red=0.0f; green=0.219999999f; blue=0.219999999f; alpha=0.0f; ea=0.2f; break;
        default:
            if ((s8)obj->unk_48 > 10) {
                OSReport((const char *)(data+0x1a4), arg0);
                OSPanic((const char *)(data+0x70), 0x28e, (const char *)(data+0x1b8));
            }
            red=green=blue=alpha=0.0f; ea=1.0f; break;
        }
        er=0.0f;
        break;
    case 2:
        if ((s8)obj->unk_48 == 3 || (s8)obj->unk_48 == 4) {
            red=green=blue=alpha=0.5f;
        } else if ((s8)obj->unk_48 == 5) {
            red=0.5f; green=1.0f; blue=0.5f; alpha=0.0f;
        } else if ((s8)obj->unk_48 >= 6 && (s8)obj->unk_48 <= 8) {
            red=green=blue=0.5f; alpha=0.0f;
        } else {
            OSReport((const char *)(data+0x1a4), arg0);
            OSPanic((const char *)(data+0x70), 0x2b1, (const char *)(data+0x1dc));
            red=green=blue=0.0f; alpha=0.0f;
        }
        er=0.0f; ea=1.0f;
        break;
    case 3:
        if ((s8)obj->unk_48 == 6 || (s8)obj->unk_48 == 8) {
            red=green=blue=alpha=0.5f;
        } else {
            OSReport((const char *)(data+0x1a4), arg0);
            OSPanic((const char *)(data+0x70), 0x2c6, (const char *)(data+0x200));
            red=green=blue=0.0f; alpha=0.0f;
        }
        er=0.0f; ea=1.0f;
        break;
    default: red=green=blue=alpha=er=ea=0.0f; break;
    }

    if ((s8)obj->unk_48 == 0 || (s8)obj->unk_48 == 9) {
        work = (Obj_1_bss_F68_Target *)((u8 *)obj + (arg0 << 3));
        work->unk_58 = 1.0f;
        work->unk_5C = 1.0f;
        fn_80038EEC(x,y,0.0f,0.0f,0.0f,0.0f);
        r=__cvt_fp2unsigned(y); g=__cvt_fp2unsigned(x);
        fn_80074188(0,0,r,g);
    } else {
        work = (Obj_1_bss_F68_Target *)((u8 *)obj + (arg0 << 3));
        work->unk_58=blue; work->unk_5C=alpha;
        fn_80038EEC(red*x, green*y, blue*x, er*y, ea, alpha);
        a=__cvt_fp2unsigned(er*y); b=__cvt_fp2unsigned(blue*x);
        g=__cvt_fp2unsigned(green*y); r=__cvt_fp2unsigned(red*x);
        fn_80074188(r,g,b,a);
    }

    if ((arg0 == 0 && (obj->unk_48 == 9 || obj->unk_48 == 10)) ||
        (arg0 == 3 && obj->unk_48 == 6)) {
        work=refs->camera;
        size=work->unk_58; speed=work->unk_5C;
        rotation=(f32 *)((u8 *)work+0xfc); other=(f32 *)((u8 *)work+0x12c);
        position=(f32 *)((u8 *)work+0x1c); scale=(f32 *)((u8 *)work+0x15c);
    } else if (arg0 == 1 && obj->unk_48 == 10) {
        work=refs->model;
        size=*(f32 *)((u8 *)work+8); speed=*(f32 *)((u8 *)work+0xc);
        rotation=(f32 *)((u8 *)work+0xac); other=(f32 *)((u8 *)work+0xdc);
        position=(f32 *)((u8 *)work+0x10); scale=(f32 *)((u8 *)work+0x15c);
    } else {
        work=(Obj_1_bss_F68_Target *)((u8 *)refs->model + arg0*0x1fc);
        size=*(f32 *)((u8 *)work+8); speed=*(f32 *)((u8 *)work+0xc);
        rotation=(f32 *)((u8 *)work+0xac); other=(f32 *)((u8 *)work+0xdc);
        position=(f32 *)((u8 *)work+0x10); scale=(f32 *)((u8 *)work+0x15c);
    }
    if (fn_80007CDC(position) || fn_80007D58(other) ||
        (((*(u32 *)&size & 0x7f800000) == 0x7f800000)) ||
        (((*(u32 *)&speed & 0x7f800000) == 0x7f800000))) {
        OSReport((const char *)(data+0x224));
        OSReport((const char *)(data+0x240), (s8)obj->unk_48);
        OSReport((const char *)(data+0x250), arg0);
        OSReport((const char *)(data+0x260), position[0]);
        OSReport((const char *)(data+0x270), position[1]);
        OSReport((const char *)(data+0x280), position[2]);
        OSReport((const char *)(data+0x290), size);
        OSReport((const char *)(data+0x2a0), speed);
        position[0]=position[1]=position[2]=0.0f;
        lbl_8006D784(other);
        size=55.0f;
        speed=fn_1_A6FE8();
    }
    lbl_8006DD14((u32)rotation, (void *)lbl_801A66CC);
    lbl_8006DD14((u32)other, (void *)(lbl_801A6D00+0x30));
    fn_1_54E00(scale);
    factor=0.1f;
    if (size < 5.0f) factor*=100.0f;
    else if (size < 15.0f) factor*=50.0f;
    else if (size < 30.0f) factor*=10.0f;
    else factor=0.1f;
    if (fn_1_A5DC4()) {
        if (*((u8 *)refs + 0xd) == 1) size*=0.8660254f;
        else if (*((u8 *)refs + 0xd) == 2) size*=0.75f;
    }
    fn_1_A7024(size,speed,factor,90000.0f);
    fn_1_727C();
done:
    return;
}
