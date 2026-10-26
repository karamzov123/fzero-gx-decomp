#include "sdk_addresses.h"

#include "types.h"

typedef enum _GXPrimitive {
    GX_QUADS = 0x80,
    GX_TRIANGLES = 0x90,
    GX_TRIANGLESTRIP = 0x98,
    GX_TRIANGLEFAN = 0xA0,
    GX_LINES = 0xA8,
    GX_LINESTRIP = 0xB0,
    GX_POINTS = 0xB8,
} GXPrimitive;

typedef enum _GXVtxFmt {
    GX_VTXFMT0,
    GX_VTXFMT1,
    GX_VTXFMT2,
    GX_VTXFMT3,
    GX_VTXFMT4,
    GX_VTXFMT5,
    GX_VTXFMT6,
    GX_VTXFMT7,
    GX_MAX_VTXFMT,
} GXVtxFmt;

typedef enum _GXAttr {
    GX_VA_PNMTXIDX,
    GX_VA_TEX0MTXIDX,
    GX_VA_TEX1MTXIDX,
    GX_VA_TEX2MTXIDX,
    GX_VA_TEX3MTXIDX,
    GX_VA_TEX4MTXIDX,
    GX_VA_TEX5MTXIDX,
    GX_VA_TEX6MTXIDX,
    GX_VA_TEX7MTXIDX,
    GX_VA_POS,
    GX_VA_NRM,
    GX_VA_CLR0,
    GX_VA_CLR1,
    GX_VA_TEX0,
    GX_VA_TEX1,
    GX_VA_TEX2,
    GX_VA_TEX3,
    GX_VA_TEX4,
    GX_VA_TEX5,
    GX_VA_TEX6,
    GX_VA_TEX7,
    GX_POS_MTX_ARRAY,
    GX_NRM_MTX_ARRAY,
    GX_TEX_MTX_ARRAY,
    GX_LIGHT_ARRAY,
    GX_VA_NBT,
    GX_VA_MAX_ATTR,
    GX_VA_NULL = 255,
} GXAttr;

typedef enum _GXCompCnt {
    GX_POS_XY = 0,
    GX_POS_XYZ = 1,
    GX_NRM_XYZ = 0,
    GX_NRM_NBT = 1,
    GX_NRM_NBT3 = 2,
    GX_CLR_RGB = 0,
    GX_CLR_RGBA = 1,
    GX_TEX_S = 0,
    GX_TEX_ST = 1,
    GX_COMPCNT_NULL = 0,
} GXCompCnt;

typedef enum _GXCompType {
    GX_U8 = 0,
    GX_S8 = 1,
    GX_U16 = 2,
    GX_S16 = 3,
    GX_F32 = 4,
    GX_RGB565 = 0,
    GX_RGB8 = 1,
    GX_RGBX8 = 2,
    GX_RGBA4 = 3,
    GX_RGBA6 = 4,
    GX_RGBA8 = 5,
    GX_COMP_NULL = 0,
} GXCompType;

typedef enum _GXAttrType {
    GX_NONE,
    GX_DIRECT,
    GX_INDEX8,
    GX_INDEX16,
} GXAttrType;

typedef struct _GXVtxDescList {
    GXAttr attr;
    GXAttrType type;
} GXVtxDescList;

typedef struct _GXVtxAttrFmtList {
    GXAttr attr;
    GXCompCnt cnt;
    GXCompType type;
    u8 frac;
} GXVtxAttrFmtList;

typedef union {
    u8 u8;
    u16 u16;
    u32 u32;
    u64 u64;
    s8 s8;
    s16 s16;
    s32 s32;
    s64 s64;
    f32 f32;
    f64 f64;
} PPCWGPipe;

void fn_80037E30(u8 numEdges);

void GXSetVtxDesc(GXAttr attr, GXAttrType type);

void GXSetVtxDescv(GXVtxDescList *list);

void GXClearVtxDesc(void);

void GXSetVtxAttrFmt(GXVtxFmt fmt, GXAttr attr, GXCompCnt cnt, GXCompType type, u8 frac);

void GXSetVtxAttrFmtv(GXVtxFmt fmt, GXVtxAttrFmtList *list);

void GXGetVtxAttrFmtv(GXVtxFmt param_0, GXVtxAttrFmtList *param_1);

void fn_80032EB8(GXVtxDescList *attrPtr);

void fn_8003462C(GXPrimitive type, GXVtxFmt fmt, u16 vert_num);

// Hardware or OS state can change asynchronously.
volatile PPCWGPipe GXFIFO : FZGX_ADDR_GXFIFO;

static GXVtxDescList lbl_80178118[27];
static GXVtxAttrFmtList vat[27];
#pragma section code_type ".fzgxpool"
static void layout____bss_0(void) {
// Hardware or OS state can change asynchronously.
    volatile unsigned char sink; // fzgx-allow: S2 discarded layout primer
    sink = *(unsigned char *)&lbl_80178118;
    sink = *(unsigned char *)&vat;
}
#pragma section code_type ".text"

static inline void GXPosition3f32(f32 x, f32 y, f32 z) {
    GXFIFO.f32 = x;
    GXFIFO.f32 = y;
    GXFIFO.f32 = z;
}

static inline void GXNormal3f32(f32 x, f32 y, f32 z) {
    GXFIFO.f32 = x;
    GXFIFO.f32 = y;
    GXFIFO.f32 = z;
}

static inline void GXEnd() {}

float fn_80088624(float);

float fn_80088600(float);

static inline void GetVertState(void) {
    fn_80032EB8(lbl_80178118);
    GXGetVtxAttrFmtv(GX_VTXFMT3, vat);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_NRM, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
}

static inline void RestoreVertState(void) {
    GXSetVtxDescv(lbl_80178118);
    GXSetVtxAttrFmtv(GX_VTXFMT3, vat);
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
