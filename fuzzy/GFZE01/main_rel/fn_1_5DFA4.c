/* Non-matching: best partial attempt (74.67% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dolphin/os.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Sig_fn_1_579A0_ColorVertex;

typedef struct {
    f32 unk00;
    u8 pad04[4];
    u8 unk08[0x34];
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Struct_4C;

typedef struct Arg0Struct {
    u8 pad00[0x8];
    u32 flags;
    u8 pad0C[0x4];
    s32 unk10;
    u8 pad14[0x8];
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    u8 pad28[0xC];
    void *unk34;
    u8 pad38[0x4];
    Vec3f unk3C;
    Vec3f unk48;
    s16 unk54;
    s16 unk56;
    s16 unk58;
    u8 pad5A[0x6];
    Vec3f unk60;
    u8 pad6C[0x48];
    f32 unkB4;
} Arg0Struct;

extern u32 camera_forward_status(void);
extern void lbl_8006D9D8(void *);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_z(s32);
extern void *memset(void *, int, u32);
extern void lbl_8006DB74(void *);
extern int fn_1_9F914(const void *, const void *);
extern void *lbl_801A66CC;
extern void lbl_8006DBAC(void *);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006DCA4(void);
extern void lbl_8006D758(void);
extern f32 lbl_8006D0B4(f32);
extern s32 fn_1_54E34(void *, f32);
extern void fn_1_57714(s32);
extern void fn_1_57720(s32, s32, s32, s32);
extern void fn_1_579A0(void *, void *);

void fn_1_5DFA4(Arg0Struct *arg0) {
    Vec3f sp14;
    Vec3f sp20;
    Sig_fn_1_579A0_ColorVertex vtx[2];
    Struct_4C sp4C;

    if (camera_forward_status() & 0x80000000) {
        return;
    }

    if (arg0->unk34 != NULL) {
        f32 val = 0.1f;
        f32 f27;

        if (arg0->unk48.x * arg0->unk48.x + arg0->unk48.y * arg0->unk48.y + arg0->unk48.z * arg0->unk48.z >= 0.1f) {
            val = 0.3f;
            if (arg0->unk48.x * arg0->unk48.x + arg0->unk48.y * arg0->unk48.y + arg0->unk48.z * arg0->unk48.z <= 0.3f) {
                val = arg0->unk48.x * arg0->unk48.x + arg0->unk48.y * arg0->unk48.y + arg0->unk48.z * arg0->unk48.z;
            }
        }

        lbl_8006D9D8(&arg0->unk3C);
        mathutil_mtxA_rotate_y(arg0->unk56);
        mathutil_mtxA_rotate_x(arg0->unk54);
        mathutil_mtxA_rotate_z(arg0->unk58);

        f27 = 1.0f;
        if (arg0->unk10 < 12) {
            f27 = f27 * (arg0->unk10 * (1.0f / 12.0f));
        }

        memset(&sp4C, 0, sizeof(sp4C));
        lbl_8006DB74(sp4C.unk08);
        sp4C.r = OSFloatToU8(255.0f * f27);
        sp4C.g = OSFloatToU8(51.0f * f27);
        sp4C.b = OSFloatToU8(0.0f);
        sp4C.a = 255;
        sp4C.unk00 = 0.7071067690849304f * (2.0f * val);
        fn_1_9F914(&sp4C, arg0->unk34);
    } else {
        Sig_fn_1_579A0_ColorVertex *vtx1 = &vtx[1];
        f32 diffX, diffY, diffZ;
        f32 dist;
        f32 f1;

        lbl_8006DBAC(lbl_801A66CC);
        lbl_8006E1B0(&arg0->unk60, &sp20);
        lbl_8006DCA4();
        lbl_8006E1B0(&arg0->unk3C, &vtx[0]);

        vtx1->x = 1.5 * sp20.x - 0.5 * vtx[0].x;
        vtx1->y = 1.5 * sp20.y - 0.5 * vtx[0].y;
        vtx1->z = 1.5 * sp20.z - 0.5 * vtx[0].z;
        lbl_8006D758();

        diffX = vtx[0].x - vtx[1].x;
        diffY = vtx[0].y - vtx[1].y;
        diffZ = vtx[0].z - vtx[1].z;
        dist = lbl_8006D0B4(diffX * diffX + diffY * diffY + diffZ * diffZ);

        sp14.x = 0.5f * (vtx[0].x + vtx[1].y);
        sp14.y = 0.5f * (vtx[0].y + vtx[1].y);
        sp14.z = 0.5f * (vtx[0].z + vtx[1].z);

        if (!fn_1_54E34(&sp14, 0.5f * dist)) {
            return;
        }

        vtx[0].r = (s32)(255.0f * arg0->unk1C);
        vtx[0].g = (s32)(255.0f * arg0->unk20);
        vtx[0].b = (s32)(255.0f * arg0->unk24);
        vtx1->r = (s32)(88.0f * arg0->unk1C);
        vtx1->g = (s32)(88.0f * arg0->unk20);
        vtx1->b = (s32)(88.0f * arg0->unk24);
        vtx[0].a = (s32)(255.0f * arg0->unkB4);
        vtx1->a = (s32)(255.0f * arg0->unkB4);

        if (vtx[0].z < -3.0) {
            f1 = 1.5f;
        } else if (vtx[0].z > 0.0) {
            f1 = 4.5f;
        } else {
            f1 = 1.5 + (3.0 + (f64)vtx[0].z);
        }

        if ((arg0->flags >> 12) & 1) {
            f1 *= 2.0f;
        }

        fn_1_57714((s32)(6.0f * f1));
        fn_1_57720(1, 1, 1, 0);
        fn_1_579A0(&vtx[0], vtx1);
    }
}
