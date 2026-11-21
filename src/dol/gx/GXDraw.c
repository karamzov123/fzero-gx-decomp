#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>

typedef enum _GXPrimitive {
    GX_QUADS = 0x80,
    GX_TRIANGLES = 0x90,
    GX_TRIANGLESTRIP = 0x98,
    GX_TRIANGLEFAN = 0xA0,
    GX_LINES = 0xA8,
    GX_LINESTRIP = 0xB0,
    GX_POINTS = 0xB8,
} GXPrimitive;

extern f32 fn_80088624(f32);
extern f32 fn_80088600(f32);
extern void GXSetVtxDesc(GXAttr attr, GXAttrType type);
extern void GXGetVtxDesc(GXAttr attr, GXAttrType *type);
extern void GXSetVtxDescv(GXVtxDescList *list);
extern void fn_80032EB8(GXVtxDescList *attrPtr);
extern void GXClearVtxDesc(void);
extern void GXSetVtxAttrFmt(GXVtxFmt fmt, GXAttr attr, GXCompCnt cnt, GXCompType type, u8 frac);
extern void GXSetVtxAttrFmtv(GXVtxFmt fmt, GXVtxAttrFmtList *list);
extern void GXGetVtxAttrFmtv(GXVtxFmt param_0, GXVtxAttrFmtList *param_1);
extern void fn_8003462C(GXPrimitive type, GXVtxFmt fmt, u16 vert_num);

static GXVtxDescList lbl_80178118[27];
static GXVtxAttrFmtList lbl_80178118__fzgx_offset_D8[27];

static inline void GXPosition3f32(f32 x, f32 y, f32 z) {
    GXWGFifo.f32 = x;
    GXWGFifo.f32 = y;
    GXWGFifo.f32 = z;
}

static inline void GXNormal3f32(f32 x, f32 y, f32 z) {
    GXWGFifo.f32 = x;
    GXWGFifo.f32 = y;
    GXWGFifo.f32 = z;
}

static inline void GXEnd(void) {}

static inline void GetVertState(void) {
    fn_80032EB8(lbl_80178118);
    GXGetVtxAttrFmtv(GX_VTXFMT3, lbl_80178118__fzgx_offset_D8);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_NRM, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
}

static inline void RestoreVertState(void) {
    GXSetVtxDescv(lbl_80178118);
    GXSetVtxAttrFmtv(GX_VTXFMT3, lbl_80178118__fzgx_offset_D8);
}

void fn_80037E30(u8 numEdges) {
    f32 temp_f29;
    f32 temp_f30;
    f32 temp_f31;
    s32 i;
    f32 sp1A0[100];
    f32 sp10[100];
    temp_f31 = 1.0f;
    temp_f30 = -temp_f31;
    GetVertState();
    for (i = 0; i <= numEdges; i++) {
        temp_f29 = (i * 2.0f * 3.1415927410125732f) / numEdges;
        sp1A0[i] = fn_80088624(temp_f29);
        sp10[i] = fn_80088600(temp_f29);
    }
    fn_8003462C(GX_TRIANGLESTRIP, GX_VTXFMT3, (numEdges + 1) * 2);
    for (i = 0; i <= numEdges; i++) {
        GXPosition3f32(sp1A0[i], sp10[i], temp_f30);
        GXNormal3f32(sp1A0[i], sp10[i], 0.0f);
        GXPosition3f32(sp1A0[i], sp10[i], temp_f31);
        GXNormal3f32(sp1A0[i], sp10[i], 0.0f);
    }
    GXEnd();
    fn_8003462C(GX_TRIANGLEFAN, GX_VTXFMT3, numEdges + 2);
    GXPosition3f32(0.0f, 0.0f, temp_f31);
    GXNormal3f32(0.0f, 0.0f, 1.0f);
    for (i = 0; i <= numEdges; i++) {
        GXPosition3f32(sp1A0[i], -sp10[i], temp_f31);
        GXNormal3f32(0.0f, 0.0f, 1.0f);
    }
    GXEnd();
    fn_8003462C(GX_TRIANGLEFAN, GX_VTXFMT3, numEdges + 2);
    GXPosition3f32(0.0f, 0.0f, temp_f30);
    GXNormal3f32(0.0f, 0.0f, -1.0f);
    for (i = 0; i <= numEdges; i++) {
        GXPosition3f32(sp1A0[i], sp10[i], temp_f30);
        GXNormal3f32(0.0f, 0.0f, -1.0f);
    }
    GXEnd();
    RestoreVertState();
}

#define PI 3.14159265358979323846F

void fn_800384FC(u8 numMajor, u8 numMinor) {
    GXAttrType ttype;
    f32 radius = 1.0F;
    f32 majorStep = PI / numMajor;
    f32 minorStep = 2.0F * PI / numMinor;
    s32 i;
    s32 j;
    f32 a;
    f32 b;
    f32 r0;
    f32 r1;
    f32 z0;
    f32 z1;
    f32 c;
    f32 x;
    f32 y;

    GXGetVtxDesc(GX_VA_TEX0, &ttype);
    fn_80032EB8(lbl_80178118);
    GXGetVtxAttrFmtv(GX_VTXFMT3, lbl_80178118__fzgx_offset_D8);

    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_NRM, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
    if (ttype != GX_NONE) {
        GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
        GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
    }

    for (i = 0; i < numMajor; i++) {
        a = i * majorStep;
        b = a + majorStep;

        r0 = radius * fn_80088600(a);
        r1 = radius * fn_80088600(b);
        z0 = radius * fn_80088624(a);
        z1 = radius * fn_80088624(b);

        fn_8003462C(GX_TRIANGLESTRIP, GX_VTXFMT3, ((numMinor + 1) * 2));
        for (j = 0; j <= numMinor; j++) {
            c = j * minorStep;
            x = fn_80088624(c);
            y = fn_80088600(c);

            GXWGFifo.f32 = x * r1;
            GXWGFifo.f32 = y * r1;
            GXWGFifo.f32 = z1;
            GXWGFifo.f32 = (x * r1) / radius;
            GXWGFifo.f32 = (y * r1) / radius;
            GXWGFifo.f32 = z1 / radius;
            if (ttype != GX_NONE) {
                GXWGFifo.f32 = (f32)j / (f32)numMinor;
                GXWGFifo.f32 = (f32)(i + 1) / (f32)numMajor;
            }

            GXWGFifo.f32 = x * r0;
            GXWGFifo.f32 = y * r0;
            GXWGFifo.f32 = z0;
            GXWGFifo.f32 = (x * r0) / radius;
            GXWGFifo.f32 = (y * r0) / radius;
            GXWGFifo.f32 = z0 / radius;
            if (ttype != GX_NONE) {
                GXWGFifo.f32 = (f32)j / (f32)numMinor;
                GXWGFifo.f32 = (f32)i / (f32)numMajor;
            }
        }
    }

    GXSetVtxDescv(lbl_80178118);
    GXSetVtxAttrFmtv(GX_VTXFMT3, lbl_80178118__fzgx_offset_D8);
}
