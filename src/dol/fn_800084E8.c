#include "types.h"
#include "sdk_addresses.h"

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

// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

typedef struct fn_800084E8_Vec {
    f32 x;
    f32 y;
    f32 z;
} fn_800084E8_Vec;

typedef struct fn_800084E8_Rect {
    f32 z;
    f32 left;
    f32 top;
    f32 right;
    f32 bottom;
    u8 pad_14[0x8];
    s32 show_corners;
    fn_800084E8_Vec corners[4];
} fn_800084E8_Rect;

extern void fn_800087F4(void *arg0, fn_800084E8_Rect *rect);
extern void lbl_8006DAEC(void);
extern void lbl_8006D758(void);
extern void fn_80072558(void);
extern void lbl_8006DB30(void);
extern void GXGetProjectionv(f32 *viewport);
extern void fn_8003462C(u32 type, u32 fmt, u32 count);
extern void fn_80008A4C(fn_800084E8_Rect *rect);

static inline void GXPosition3f32(f32 x, f32 y, f32 z) {
    GXFIFO.f32 = x;
    GXFIFO.f32 = y;
    GXFIFO.f32 = z;
}

static inline void GXTexCoord2f32(f32 s, f32 t) {
    GXFIFO.f32 = s;
    GXFIFO.f32 = t;
}

void fn_800084E8(void *arg0, fn_800084E8_Rect *rect) {
    f32 viewport[6];
    f32 sx;
    f32 sy;
    f32 z;
    f32 left;
    f32 top;
    f32 right;
    f32 bottom;

    fn_800087F4(arg0, rect);
    lbl_8006DAEC();
    lbl_8006D758();
    fn_80072558();
    lbl_8006DB30();
    GXGetProjectionv(viewport);
    sx = -1.0f / viewport[1];
    sy = 1.0f / viewport[3];
    left = sx * (rect->left * rect->z);
    right = sx * (rect->right * rect->z);
    top = sy * (rect->top * rect->z);
    bottom = sy * (rect->bottom * rect->z);

    fn_8003462C(0x80, 0, 4);
    GXPosition3f32(left, top, rect->z);
    GXTexCoord2f32(0.0f, 0.0f);
    GXPosition3f32(right, top, rect->z);
    GXTexCoord2f32(1.0f, 0.0f);
    GXPosition3f32(right, bottom, rect->z);
    GXTexCoord2f32(1.0f, 1.0f);
    GXPosition3f32(left, bottom, rect->z);
    GXTexCoord2f32(0.0f, 1.0f);

    fn_80008A4C(rect);
    z = rect->z;
    fn_8003462C(0xB0, 0, 5);
    GXPosition3f32(left, top, z);
    GXPosition3f32(right, top, z);
    GXPosition3f32(right, bottom, z);
    GXPosition3f32(left, bottom, z);
    GXPosition3f32(left, top, z);

    if (rect->show_corners != 0) {
        fn_8003462C(0xB0, 0, 5);
        GXPosition3f32(rect->corners[0].x, rect->corners[0].y, rect->corners[0].z);
        GXPosition3f32(rect->corners[1].x, rect->corners[1].y, rect->corners[1].z);
        GXPosition3f32(rect->corners[2].x, rect->corners[2].y, rect->corners[2].z);
        GXPosition3f32(rect->corners[3].x, rect->corners[3].y, rect->corners[3].z);
        GXPosition3f32(rect->corners[0].x, rect->corners[0].y, rect->corners[0].z);

        fn_8003462C(0xA8, 0, 8);
        GXPosition3f32(rect->corners[0].x, rect->corners[0].y, rect->corners[0].z);
        GXPosition3f32(left, top, z);
        GXPosition3f32(rect->corners[1].x, rect->corners[1].y, rect->corners[1].z);
        GXPosition3f32(right, top, z);
        GXPosition3f32(rect->corners[2].x, rect->corners[2].y, rect->corners[2].z);
        GXPosition3f32(right, bottom, z);
        GXPosition3f32(rect->corners[3].x, rect->corners[3].y, rect->corners[3].z);
        GXPosition3f32(left, bottom, z);
    }
}
