#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/spline.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"
#include "rel/main_rel/bg_cas.h"





typedef struct SplineEntry {
    u8 pad0[0x104];
    u32 f104;
    u8 pad1[0xC];
    u32 f114;
    u8 pad2[0xC];
    u32 f124;
    u8 pad3[0xC];
    u32 f134;
    u8 pad4[0xC];
    u32 f144;
    u8 pad5[0xC];
    u32 f154;
    u8 pad6[0xC];
    f32 f164;
} SplineEntry;

typedef struct SplineMain {
    u8 pad0[4];
    u8 unk_4;
    u8 pad5[0x163];
    f32 unk_168;
} SplineMain;

void fn_1_FA89C(SplineMain *arg0);

Obj_1_bss_84428 lbl_1_bss_84428;

Obj_1_data_3EED0 lbl_1_data_3EED0 = {
    0x00U,
    0x01U,
    0x03U,
    0x02U,
    {0x3FU, 0x80U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x04U, 0x05U, 0x01U, 0x00U, 0x00U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x02U, 0x06U, 0x04U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0x04U, 0x06U, 0x07U, 0x05U, 0xBFU, 0x80U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x02U, 0x03U, 0x07U, 0x06U, 0x00U, 0x00U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x01U, 0x05U, 0x07U, 0x03U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U}
};

Obj_1_data_3EF30 lbl_1_data_3EF30 = {
    0x3F800000U,
    0x3F800000U,
    0x3F800000U,
    {0x3FU, 0x80U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U}
};

/* fzgx:begin fn_1_FC414 noprologue */
#include "types.h"
#include "rel/main_rel/bg_cas.h"

extern const f32 lbl_1_rodata_7600;
extern const f32 lbl_1_rodata_7604;

extern void *GXGetTexBufferSize(int, int, int, int, int);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_FC4E0(void *, void *);
extern void fn_1_FC51C(void);

typedef struct {
    u8 pad_0[0x10];
    u32 unk_10;
    f32 unk_14;
    f32 unk_18;
    u8 pad_1c[4];
    u8 unk_20[0x100];
    u8 unk_120[0x20];
    u32 unk_140;
} Fn1FC414Data;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_850C0;
u16 lbl_1_bss_850C0__fzgx_offset_4;
u16 lbl_1_bss_850C6__fzgx_offset_0;
u32 lbl_1_bss_850C6__fzgx_offset_2[2];
u32 lbl_1_bss_850C6__fzgx_offset_A;
f32 fzgx_obj_lbl_1_bss_850D4;
f32 fzgx_obj_lbl_1_bss_850D8;
u32 lbl_1_bss_850D8__fzgx_offset_4;
u8 lbl_1_bss_850E0[0x100];
u8 lbl_1_bss_851E0[0x20];
u32 lbl_1_bss_851E0__fzgx_offset_20;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_850C0;
    s = *(u8 *)&lbl_1_bss_850C0__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_850C6__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_850C6__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_850C6__fzgx_offset_A;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_850D4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_850D8;
    s = *(u8 *)&lbl_1_bss_850D8__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_850E0;
    s = *(u8 *)&lbl_1_bss_851E0;
    s = *(u8 *)&lbl_1_bss_851E0__fzgx_offset_20;
}
#pragma section code_type ".text"

void fn_1_FC414(void *arg0, void *arg1) {
    
    f32 v14 = lbl_1_rodata_7600;
    f32 v18 = lbl_1_rodata_7604;
    void *buffer;

    fzgx_obj_lbl_1_bss_850D4 = v14;
    fzgx_obj_lbl_1_bss_850D8 = v18;
    buffer = GXGetTexBufferSize(0x10, 0x10, 1, 0, 0);
    fn_80008BEC(lbl_1_bss_850E0, 0, (u32)buffer);
    fn_80008BEC(lbl_1_bss_851E0, 0, 0x20);
    lbl_1_bss_851E0__fzgx_offset_20 = (u32)GXGetTexBufferSize(0x80, 0x80, 1, 0, 0);
    fn_1_FC4E0(arg0, arg1);
    lbl_1_bss_850C6__fzgx_offset_A = 0;
    fn_1_FC51C();
}
/* fzgx:end fn_1_FC414 */

/* fzgx:begin fn_1_FC4E0 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

void fn_1_FC4E0(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_80008BEC(arg0, 0, (arg1 & 0xff) * 0x10440);
    }
}
/* fzgx:end fn_1_FC4E0 */

/* fzgx:begin fn_1_FC51C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

extern void fn_1_FC60C(void);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u32, u32, u32, u32, u32, u32);
extern void GXInitTexObjLOD(void *, f32, f32, f32, u32, u32, u32, u32, u32);

#pragma opt_common_subs off
void fn_1_FC51C(void) {
    fn_1_FC60C();

    lbl_1_bss_851E0[0] = 0xff;
    lbl_1_bss_851E0[1] = 0xff;
    lbl_1_bss_851E0[2] = 0;
    lbl_1_bss_851E0[3] = 0;
    lbl_1_bss_851E0[4] = 0;
    lbl_1_bss_851E0[5] = 0;
    lbl_1_bss_851E0[6] = 0;
    lbl_1_bss_851E0[7] = 0;

    fn_80008BA8(lbl_1_bss_851E0 + 8, lbl_1_bss_851E0, 8);
    fn_80008BA8(lbl_1_bss_851E0 + 0x10, lbl_1_bss_851E0, 8);
    fn_80008BA8(lbl_1_bss_851E0 + 0x18, lbl_1_bss_851E0, 8);
    DCFlushRange(lbl_1_bss_851E0, 0x20);

    GXInitTexObj((*(u8 (*)[32])&lbl_1_bss_85204), lbl_1_bss_851E0, 8, 4, 1, 0, 0, 0);
    GXInitTexObjLOD((*(u8 (*)[32])&lbl_1_bss_85204),
                *(const f32 *)&lbl_1_rodata_760C,
                *(const f32 *)&lbl_1_rodata_760C,
                *(const f32 *)&lbl_1_rodata_760C,
                1, 1, 0, 0, 0);
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_FC51C */

/* fzgx:begin fn_1_FC60C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

extern u8 lbl_1_bss_850E0[256];


extern u32 GXGetTexBufferSize(u16, u16, u32, u8, u8);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void DCFlushRange(void *, u32);

void fn_1_FC60C(void) {
    u8 *tex;
    u8 *buf;
    u32 size;
    u32 i;

    size = GXGetTexBufferSize(0x10, 0x10, 1, 0, 0);
    tex = lbl_1_bss_85224;
    buf = lbl_1_bss_850E0;

    for (i = 0; i < 0x100; i++) {
        int idx = ((i & 0x80) >> 2) + ((i >> 4) & 7) + ((i & 0xC) << 4) + ((i & 3) << 3);
        if (i >= 0xA) {
            buf[idx] = (u8)i - 0xA;
        } else {
            buf[idx] = 0;
        }
    }

    GXInitTexObj(tex, buf, 0x10, 0x10, 1, 0, 1, 0);
    GXInitTexObjLOD(tex, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0);
    DCFlushRange(buf, size);
}
/* fzgx:end fn_1_FC60C */

/* fzgx:begin fn_1_FC760 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

extern void fn_80038F10(f32 *);
extern void GXGetScissor(u32 *, u32 *, u32 *, u32 *);
extern void GXGetProjectionv(f32 *);
extern void fn_80015C1C(void *, f32,f32,f32,f32,f32,f32,f32,f32,f32);
extern void PSMTXScale(void *,f32,f32,f32);
extern void lbl_8006DFFC(void *,void *,void *);
extern void C_MTXFrustum(void *,f32,f32,f32,f32,f32,f32);
extern void fn_800737E4(void *,s32);
extern void fn_80038EEC(f32,f32,f32,f32,f32,f32);
extern void fn_80074188(u32,u32,u32,u32);
extern void fn_80074300(u16,u16,u16,u16);
extern void fn_80074438(u32,u32,u32,u32);
extern void fn_800744F8(void *,u32);
extern void fn_8003526C(void *,u8);
extern void fn_80007C2C(void);
extern void lbl_8006DBAC(void *);
extern void DCInvalidateRange(void *,u32);
extern void GXInitTexObj(void *,void *,u16,u16,int,int,int,u8);
extern void GXInitTexObjLOD(void *,int,int,f32,f32,f32,u8,u8,int);
extern void GXInvalidateTexAll(void);
extern void fn_80072270(void *);

typedef struct {
    u8 pad_0[0xC];
    f32 unk_C;
    u32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
} Pool;
extern Pool lbl_1_rodata_7600;

typedef struct {
    u8 pad_0[0x14];
    f32 unk_14;
    f32 unk_18;
    u8 pad_1C[0x124];
    u32 unk_140;
} BssPool;

typedef struct { f32 m[12]; } Mat;
typedef struct { f32 m[16]; } Mat44;
typedef struct { f32 m[6]; } View;
typedef struct { f32 m[7]; } Saved;
typedef struct { u8 pad[0x40]; Mat unk_40; Mat unk_70; Mat unk_A0; u8 unk_D0[0x10]; u8 unk_E0[0x4000]; f32 unk_40E0; f32 unk_40E4; f32 unk_40E8; } Texture;
typedef struct {u8 pad[0x10428]; void (*unk_10428)(void *,Texture *); } Owner;

void fn_1_FC760(void *arg0, Texture *arg1) {
Pool *p_ro = (Pool *)&lbl_1_rodata_7600;
BssPool *p_bss = (BssPool *)&lbl_1_bss_850C0;
f32 v0,v1,v2;
f32 near,far,range;
f32 scale,ratio;
Mat44 loc_B8;
Mat loc_88;
Mat loc_58;
View loc_40;
Saved loc_24;
u32 loc_20,loc_1C,loc_18,loc_14;
u32 loc_10;
fn_80038F10(loc_40.m);
GXGetScissor(&loc_20,&loc_1C,&loc_18,&loc_14);
GXGetProjectionv(loc_24.m);
v0=p_ro->unk_14;
v1=arg1->unk_40E4;
v2=arg1->unk_40E8;
fn_80015C1C(&loc_88,-v2,v2,-v1,v1,p_bss->unk_14,v0,v0,v0,v0);
near=p_bss->unk_14;
far=p_bss->unk_18;
range=far-near;
PSMTXScale(&loc_58,p_ro->unk_C,p_ro->unk_C,p_ro->unk_C);
ratio=far/range;
loc_58.m[2]=ratio;
loc_58.m[3]=(far*near)/range;
scale=p_ro->unk_18;
loc_58.m[6]=ratio*scale;
loc_58.m[7]=loc_58.m[3]*scale;
loc_58.m[10]=p_ro->unk_1C;
lbl_8006DFFC(&loc_88,&arg1->unk_A0,&arg1->unk_40);
lbl_8006DFFC(&loc_58,&arg1->unk_A0,&arg1->unk_70);
C_MTXFrustum(&loc_B8,arg1->unk_40E8,-arg1->unk_40E8,-arg1->unk_40E4,arg1->unk_40E4,p_bss->unk_14,p_bss->unk_18);
fn_800737E4(&loc_B8,0);
fn_80038EEC(p_ro->unk_C,p_ro->unk_C,p_ro->unk_20,p_ro->unk_20,p_ro->unk_C,p_ro->unk_1C);
fn_80074188(0,0,128,128);
fn_80074300(0,0,128,128);
fn_80074438(128,128,17,0);
loc_10=p_ro->unk_10;
fn_800744F8(&loc_10,0xffffff);
fn_8003526C(arg1->unk_E0,1);
fn_80007C2C();
lbl_8006DBAC(&arg1->unk_A0);
((Owner *)arg0)->unk_10428(arg0,arg1);
DCInvalidateRange(arg1->unk_E0,p_bss->unk_140);
fn_8003526C(arg1->unk_E0,1);
GXInitTexObj(arg1,arg1->unk_E0,128,128,1,0,0,0);
GXInitTexObjLOD(arg1,1,1,p_ro->unk_C,p_ro->unk_C,p_ro->unk_C,0,0,0);
GXInvalidateTexAll();
fn_80038EEC(loc_40.m[0],loc_40.m[1],loc_40.m[2],loc_40.m[3],loc_40.m[4],loc_40.m[5]);
fn_80074188(loc_20,loc_1C,loc_18,loc_14);
fn_80072270(&loc_24);
}
/* fzgx:end fn_1_FC760 */

/* fzgx:begin fn_1_FCA10 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"

/* begin game/main_rel/bg_cas_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_BG_CAS_TYPES_H
#define GAME_MAIN_REL_BG_CAS_TYPES_H

// Types (and the externs that name them) of bg_cas.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct {
    f32 x, y, z;
} fn_1_FF6B8_CasVec;

typedef struct {
    s32 life;        /* 0x00 */
    fn_1_FF6B8_CasVec pos;      /* 0x04 */
    fn_1_FF6B8_CasVec prev;     /* 0x10 */
    fn_1_FF6B8_CasVec vel;      /* 0x1C */
    s16 rot;         /* 0x28 */
    s16 rotVel;      /* 0x2A */
    f32 scale;       /* 0x2C */
    f32 size;        /* 0x30 */
} CasParticle;

typedef struct {
    u8 pad_0[0x4];
    s32 active;      /* 0x04 */
    fn_1_FF6B8_CasVec pos;      /* 0x08 */
    u8 pad_14[0xC];
    fn_1_FF6B8_CasVec vel;      /* 0x20 */
    u8 pad_2C[0xC];
    f32 size;        /* 0x38 */
    CasParticle particles[20]; /* 0x3C */
} CasEmitter;

extern void fn_1_FF6B8(CasEmitter *em);

#endif  // GAME_MAIN_REL_BG_CAS_TYPES_H

/* end game/main_rel/bg_cas_types.h */

struct fn_1_FD3A8_lbl_1_rodata_7600 {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0x4];
    f32 unk_14;
    u8 pad_18[0x4];
    f32 unk_1C;
    u8 pad_20[0x28];
    u32 unk_48;
    f32 unk_4C;
};

struct fn_1_FD3A8_lbl_801A6D00 {
    u32 unk_0;
};

typedef struct Sig_GXInitTexObj__GXTexObj {
    u32 dummy[8];
} Sig_GXInitTexObj_GXTexObj;

typedef enum Sig_GXInitTexObj__GXTexFmt {
    Sig_GXInitTexObj_GX_TF_I4 = 0x0,
    Sig_GXInitTexObj_GX_TF_I8 = 0x1,
    Sig_GXInitTexObj_GX_TF_IA4 = 0x2,
    Sig_GXInitTexObj_GX_TF_IA8 = 0x3,
    Sig_GXInitTexObj_GX_TF_RGB565 = 0x4,
    Sig_GXInitTexObj_GX_TF_RGB5A3 = 0x5,
    Sig_GXInitTexObj_GX_TF_RGBA8 = 0x6,
    Sig_GXInitTexObj_GX_TF_CMPR = 0xE,
    Sig_GXInitTexObj_GX_CTF_R4 = 0x0 | 0x20,
    Sig_GXInitTexObj_GX_CTF_RA4 = 0x2 | 0x20,
    Sig_GXInitTexObj_GX_CTF_RA8 = 0x3 | 0x20,
    Sig_GXInitTexObj_GX_CTF_YUVA8 = 0x6 | 0x20,
    Sig_GXInitTexObj_GX_CTF_A8 = 0x7 | 0x20,
    Sig_GXInitTexObj_GX_CTF_R8 = 0x8 | 0x20,
    Sig_GXInitTexObj_GX_CTF_G8 = 0x9 | 0x20,
    Sig_GXInitTexObj_GX_CTF_B8 = 0xA | 0x20,
    Sig_GXInitTexObj_GX_CTF_RG8 = 0xB | 0x20,
    Sig_GXInitTexObj_GX_CTF_GB8 = 0xC | 0x20,
    Sig_GXInitTexObj_GX_TF_Z8 = 0x1 | 0x10,
    Sig_GXInitTexObj_GX_TF_Z16 = 0x3 | 0x10,
    Sig_GXInitTexObj_GX_TF_Z24X8 = 0x6 | 0x10,
    Sig_GXInitTexObj_GX_CTF_Z4 = 0x0 | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z8M = 0x9 | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z8L = 0xA | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z16L = 0xC | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_TF_A8 = Sig_GXInitTexObj_GX_CTF_A8,
} Sig_GXInitTexObj_GXTexFmt;

typedef enum Sig_GXInitTexObj__GXTexWrapMode {
    Sig_GXInitTexObj_GX_CLAMP,
    Sig_GXInitTexObj_GX_REPEAT,
    Sig_GXInitTexObj_GX_MIRROR,
    Sig_GXInitTexObj_GX_MAX_TEXWRAPMODE,
} Sig_GXInitTexObj_GXTexWrapMode;

typedef struct Sig_GXInitTexObjLOD__GXTexObj {
    u32 texture_filter;
    u32 texture_lod;
    u32 texture_size;
    u32 texture_address;
    u32 user_data;
    u32 texture_format;
    u32 tlut_name;
    u16 texture_time_count;
    u8 texture_tile_type;
    u8 texture_flags;
} Sig_GXInitTexObjLOD_GXTexObj;

typedef enum Sig_GXInitTexObjLOD__GXTexFilter {
    Sig_GXInitTexObjLOD_GX_NEAR,
    Sig_GXInitTexObjLOD_GX_LINEAR,
    Sig_GXInitTexObjLOD_GX_NEAR_MIP_NEAR,
    Sig_GXInitTexObjLOD_GX_LIN_MIP_NEAR,
    Sig_GXInitTexObjLOD_GX_NEAR_MIP_LIN,
    Sig_GXInitTexObjLOD_GX_LIN_MIP_LIN,
} Sig_GXInitTexObjLOD_GXTexFilter;

typedef u8 Sig_GXInitTexObjLOD_GXBool;

typedef enum Sig_GXInitTexObjLOD__GXAnisotropy {
    Sig_GXInitTexObjLOD_GX_ANISO_1,
    Sig_GXInitTexObjLOD_GX_ANISO_2,
    Sig_GXInitTexObjLOD_GX_ANISO_4,
    Sig_GXInitTexObjLOD_GX_MAX_ANISOTROPY,
} Sig_GXInitTexObjLOD_GXAnisotropy;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} FD844_Vec;

typedef struct {
    f32 x, y, z;
} CasVec;

typedef struct {
    CasVec v;
    u8 pad_C[0x34];
} CasMtx;

typedef struct {
    u32 unk_0;
    u32 unk_4;
} CasObj;

typedef struct {
    f32 x, y, z;
} CasSparkVec;

typedef struct {
    CasSparkVec pos;
    CasSparkVec base;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    s32 unk_30;
} CasSpark;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    f32 unk_C;
    u32 unk_10;
    CasSpark sparks[20];
} CasSparkSet;
extern const f32 lbl_1_rodata_7600;
extern const f32 lbl_1_rodata_7604;
extern u32 GXGetTexBufferSize(u16, u16, u32, u8, u8);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_1_FC4E0(void *arg0, int arg1);
extern void fn_1_FC51C(void);
extern struct fn_1_FD3A8_lbl_801A6D00 lbl_801A6D00;
extern void GXInitTexObj(void *, void *, u32, u32, u32, u32, u32, u32);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void GXLoadTexMtxImm(void *, u32, u32);
extern u32 fn_800371F8(u32, void *);
extern u32 lbl_8006DCA4(void);
extern void fn_1_57720(u32 value_1, u32 value_2, u32 value_3, u32 value_4);
extern void fn_80015C1C(f32 *out, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern void fn_800720B0(int);
extern void fn_8007245C(u32 value);
extern void fn_800724C8(void);
extern void fn_80072558(void);
extern void fn_80072864(u32 arg0);
extern void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80072AB0(s32 arg0, s32 arg1, s32 arg2);
extern void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072D64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_80072E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80073678(u32 arg0);
extern void fn_80073778(void *obj, s32 index);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_800745A4(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5);
extern void fn_80074660(u32 arg0);
extern void fn_80074788(u32 arg0);
extern void fn_800747D0(u32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DD7C(void);
extern void lbl_8006DFC4(void *);
extern void fn_1_FC760(void *, void *);
extern void fn_8006F1F0(FD844_Vec *, FD844_Vec *, FD844_Vec *);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern u32 fn_1_584AC(void);
extern void *memset(void *, int, u32);
extern s32 fn_1_58C4(void);
extern CasVec lbl_1_rodata_77F8;
extern CasVec lbl_1_rodata_7804;
extern CasMtx *fn_80077B14(CasObj *);
extern void fn_1_1024F8(void);
extern void fn_1_102750(void);
extern void fn_1_102C08(void);
extern void fn_800736C0(u32, void *);
extern void fn_800735C8(s32 index, s32 value);
extern void fn_80073620(s32 index, s32 value);
extern void lbl_8006D758(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006E14C(f32);
extern void *fn_1_563B8(void *);
extern void fn_1_566EC(int arg0, int arg1);
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C();
extern void fn_1_7F230();
extern void fn_1_7F1E8();
extern void *fn_1_14DD68(void *);
extern void *fn_1_14DDF4(void *);
extern void lbl_8006E0A4(void *);
extern int fn_1_FCF50(void);
extern void fn_1_FCA10(void);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_FD3A8();
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(CasEmitter *em);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void lbl_8006E13C(void *);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_FFC60(CasSparkSet *state);
extern void fn_1_FEC7C(void *object);
extern f32 lbl_1_rodata_7590[2];
extern const f32 lbl_1_rodata_7598;
extern u8 lbl_1_bss_850E0[256];
extern const f32 lbl_1_rodata_76A8;
extern u32 fn_1_904(void);
extern u32 fn_1_914(void);
extern void fn_1_681C(u32 index, u32 *output);
extern u32 fn_1_1FB80(void *, u32);
extern void fn_1_FC60C(void);
extern void DCFlushRange(void *, u32);
extern void fn_1_FB9DC(int index);
extern void fn_1_FBC5C(u8 idx);

typedef f32 Mtx34[3][4];

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_FCA10_CasVec;

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} CasColor;



#define CAS_VIEW(field) (*(f32 *)(*(u32 *)(lbl_1_data_3EFA8 + 0x40F0) + (field)))

/* Literal pool of the retail TU (lbl_1_rodata_7600): MWCC pools literals in
 * first-use order across the TU, so the earlier functions' literals come first. */
#pragma section code_type ".fzgxpool"
static void fzgx_pool_layout(void) {
    volatile f32 s; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    volatile u32 w; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    s = 2.0f;
    s = 8.0f;
}

/* MWCC emits a function's aggregate initializers before its scalar literals,
 * so each retail function with both gets its own primer. */
static void fzgx_pool_layout_1(void) {
    volatile f32 s; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    volatile u32 w; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    {
        CasColor c = {0xFF, 0xFF, 0xFF, 0xFF};
        w = *(u32 *)&c;
    }
    s = 0.0f;
}

static void fzgx_pool_layout_2(void) {
    volatile f32 s; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    volatile u32 w; /* fzgx-allow: S2 pool primer sink: fixes the TU literal order */
    {
        CasColor z = {0, 0, 0, 0};
        w = *(u32 *)&z;
    }
    s = 0.5f;
    s = 16.0f;
    s = 1.0f;
    s = 128.0f;
}
#pragma section code_type ".text"

void fn_1_FCA10(void) {
    CasColor color = {0xFF, 0xFF, 0xFF, 0xFF};
    u16 j;
    s32 i;
    u32 obj;

    fn_800736C0(0, &color);

    for (i = 0; (u16)i < 4; i++) {
        j = i;
        fn_800735C8(j, 12);
        fn_80073620(j, 28);
    }

    fn_80073778(lbl_1_bss_85224, 0);
    fn_80073778((void *)lbl_1_data_3EFA8, 1);
    fn_80073778((void *)(lbl_1_data_3EFA8 + 0x20), 2);
    fn_80073778(lbl_1_bss_85204, 3);

    GXLoadTexMtxImm((void *)(lbl_1_data_3EFA8 + 0x70), 30, 0);
    GXLoadTexMtxImm((void *)(lbl_1_data_3EFA8 + 0x40), 33, 0);

    lbl_8006DAEC();
    {
        fn_1_FCA10_CasVec trans = {0.0f, 0.0f, 0.0f};
        lbl_8006DBAC((void *)(lbl_1_data_3EFA8 + 0xA0));
        lbl_8006E14C(-1.0f);

        /* Translation column of the locked-cache current matrix. */
        *(f32 *)(0xE0000000 + 0x0C) = trans.x;
        *(f32 *)(0xE0000000 + 0x1C) = trans.y;
        *(f32 *)(0xE0000000 + 0x2C) = trans.z;
    }

    GXLoadTexMtxImm((*((Mtx34 * *)&lbl_801A6D00)), 0x24, 0);
    lbl_8006D758();

    (*(*((Mtx34 * *)&lbl_801A6D00)))[0][0] = 0.0f;
    obj = *(u32 *)(lbl_1_data_3EFA8 + 0x40F0);
    if (*(f32 *)(obj + 0x10) < 0.5f || *(f32 *)(obj + 0x10) >= 1.0f) {
        *(f32 *)(obj + 0x10) = 0.5f;
    }
    obj = *(u32 *)(lbl_1_data_3EFA8 + 0x40F0);
    if (*(f32 *)(obj + 0x14) <= 0.0f || *(f32 *)(obj + 0x14) > 0.5f) {
        *(f32 *)(obj + 0x14) = 0.5f;
    }

    (*(*((Mtx34 * *)&lbl_801A6D00)))[0][2] = CAS_VIEW(0x10);
    (*(*((Mtx34 * *)&lbl_801A6D00)))[0][3] = CAS_VIEW(0x14);
    (*(*((Mtx34 * *)&lbl_801A6D00)))[1][1] = 0.0f;
    (*(*((Mtx34 * *)&lbl_801A6D00)))[2][2] = 0.0f;
    (*(*((Mtx34 * *)&lbl_801A6D00)))[2][3] = 1.0f;

    GXLoadTexMtxImm((*((Mtx34 * *)&lbl_801A6D00)), 0x46, 0);
    lbl_8006DB30();

    fn_80074660(4);
    fn_800745A4(0, 0, 0, 30, 0, 125);
    fn_800745A4(1, 0, 0, 33, 0, 125);
    fn_800745A4(2, 0, 0, 33, 0, 125);
    fn_80073678(4);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_80072AB0(0, 0, 0);
    fn_800734A8(0, 0, 0, 0xFF);
    fn_80072C24(0, 0xF, 0xF, 0xF, 0xF);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 4);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80073C6C(1);
    fn_80072AB0(1, 0, 0);
    fn_800734A8(1, 1, 1, 0xFF);
    fn_80072C24(1, 0xF, 0xF, 0xF, 0xF);
    fn_80072D64(1, 0, 0, 0, 1, 0);
    fn_80072CC4(1, 4, 0, 6, 7);
    fn_80072E20(1, 14, 0, 0, 0, 0);
    fn_80073C6C(2);
    fn_80072AB0(2, 0, 0);
    fn_800734A8(2, 2, 2, 4);
    fn_80072C24(2, 0xF, 0xF, 0xF, 8);
    fn_80072D64(2, 0, 0, 0, 1, 0);
    fn_80072CC4(2, 7, 0, 4, 7);
    fn_80072E20(2, 0, 0, 1, 1, 0);
    fn_80073C6C(3);
    fn_80072AB0(3, 0, 0);
    fn_800745A4(3, 0, 1, 36, 1, 70);
    fn_800734A8(3, 3, 3, 4);
    fn_80072C24(3, 0xF, 0xF, 0xF, 0);
    fn_80072D64(3, 0, 0, 0, 1, 0);
    fn_80072CC4(3, 7, 4, 0, 7);
    fn_80072E20(3, 0, 0, 0, 1, 0);
}
/* fzgx:end fn_1_FCA10 */

/* fzgx:begin fn_1_FCF50 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

int fn_1_FCF50(void) {
    fn_1_FCA10();
    return 1;
}
/* fzgx:end fn_1_FCF50 */

/* fzgx:begin fn_1_FCF74 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

void fn_1_FCF74(void) {
    fn_80008BEC(&lbl_1_data_3EFB0, 0, 4);
}
/* fzgx:end fn_1_FCF74 */

/* fzgx:begin fn_1_FCFA4 noprologue */
#include "types.h"
#include "rel/main_rel/bg_cas.h"
extern Obj_1_bss_850C6 lbl_1_bss_850C0__fzgx_offset_6;

typedef struct {
    u8 r, g, b, a;
} Sig_fn_800371F8_GXColor;

typedef s32 (*Fn)(void *);
typedef void (*DrawFn)(void *, void *);

typedef struct {
    u8 pad_0[0x320];
    s16 unk_320;
} Ctx;

typedef struct {
    u8 pad_0[0x40F0];
    u32 unk_40F0;
    u8 pad_4100[0x4100 - 0x40F4];
} Part;

typedef struct {
    u8 pad_0[0x420];
    Fn unk_420;
    Fn unk_424;
    u8 pad_428[4];
    DrawFn unk_42C;
} Sub;

typedef struct {
    s32 unk_0;
    u8 unk_4;
    u8 pad_5[7];
    u32 unk_C;
    u8 pad_10[0x10];
    Part part[1];
    u8 pad_4120[0x10000 - 0x4120];
    Sub sub;
} Manager;

extern s16 camera_get_output(void);
extern s32 camera_get_state(void);
extern u32 camera_get_status(void);
extern u32 lbl_1_rodata_7608;
extern u8 fn_1_3F854(void);
extern void fn_8007245C(u32);
extern void fn_800724C8(void);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_800371F8(s32, Sig_fn_800371F8_GXColor *);
extern void fn_80074918(u8, s32, u8);
extern void fn_800720B0(u32);
extern void fn_80072864(u32);

void fn_1_FCFA4(void *arg0) {
    s32 tmp_call4;
    u32 nxt;
    Fn f0;
    Fn f1;
    u8 cur;
    u32 status;
    u8 state;
    u8 lim;
    Ctx *p;
    Manager *m = arg0;
    u8 ok;
    Sig_fn_800371F8_GXColor c;
    u32 v;
    s32 i;

    if (m == 0) {
        return;
    }
    f0 = m->sub.unk_420;
    if (f0 != 0 && f0(((u8 *)m + 0x10000)) != 0) {
        return;
    }
    if (lbl_1_bss_850C0__fzgx_offset_6.unk_0 != 0) {
        return;
    }
    if ((m->unk_C & 0x40000000) != 0) {
        p = (Ctx *)m->unk_0;
        status = camera_get_status();
        state = camera_get_state();
        lim = (u8)fn_1_3F854();
        if (p == 0) {
            ok = 0;
        } else {
            cur = ((u8 *)&lbl_1_data_3EFB0)[p->unk_320];
            if ((s16)status == 2 && state == 6) {
                tmp_call4 = camera_get_output();
                if (!(tmp_call4 == p->unk_320)) {
                    ok = 0;
                } else {
                    goto allowed; /* fzgx-allow: S1 shared success block matches retail control flow */
                }
            } else if ((s16)status == 2) {
                goto allowed; /* fzgx-allow: S1 shared success block matches retail control flow */
            } else {
                /* fzgx-allow: S2 retail reloads the counter independently of the saved value */
                nxt = (u8)(((volatile u8 *)&lbl_1_data_3EFB0)[p->unk_320] + 1);
                ((u8 *)&lbl_1_data_3EFB0)[p->unk_320] = nxt;
                if (nxt >= lim) {
                    ((u8 *)&lbl_1_data_3EFB0)[p->unk_320] = 0;
                }
                if (!(cur == p->unk_320)) {
                    ok = 0;
                } else {
                    goto allowed; /* fzgx-allow: S1 shared success block matches retail control flow */
                }
            }
        }
    } else {
        if (!((m->unk_C & 0x80000000) == 0)) {
            ok = 0;
        } else {
allowed:
            ok = 1;
        }
    }
    if (ok == 0) {
        return;
    }
    f1 = m->sub.unk_424;
    if (f1 != 0 && f1(m) == 0) {
        return;
    }
    fn_800724C8();
    fn_8007245C(0x2200);
    v = lbl_1_rodata_7608;
    fn_80074788(1);
    fn_800747D0(4, 0, 0, 0, 0, 2, 2);
    c = *(Sig_fn_800371F8_GXColor *)&v;
    fn_800371F8(0, &c);
    fn_80074918(1, 7, 0);
    fn_800720B0(0);
    fn_80072864(2);
    for (i = 0; (s16)i < m->unk_4; i++) {
        if (m->part[i].unk_40F0 != 0) {
            lbl_1_data_3EFA8 = (u32)&m->part[i];
            m->sub.unk_42C(m, &m->part[i]);
        }
    }
}
/* fzgx:end fn_1_FCFA4 */

/* fzgx:begin fn_1_FD1D4 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);

typedef struct {
    void *value;
} fn_1_FD1D4_Fn1FD27CArg0;

typedef struct {
    u8 pad[0x40f0];
    void *value;
} fn_1_FD1D4_Fn1FD27CArg1;

void fn_1_FD1D4(fn_1_FD1D4_Fn1FD27CArg0 *arg0, fn_1_FD1D4_Fn1FD27CArg1 *arg1) {
    fn_1_FD1D4_Fn1FD27CArg1 *persistent;
    void *value;
    void *result;
    s16 mode;
    u8 local[0x30];

    persistent = arg1;
    value = arg0->value;
    lbl_8006DB74(local);
    if (persistent->value != 0 && (*(u32 *)((u8 *)persistent->value + 4) & ~0x7fffffffU) != 0) {
        result = fn_1_563B8(fn_1_FCF50);
        mode = *(s16 *)persistent->value;
        if (mode == 0) {
            fn_1_7EB8C(value, lbl_1_rodata_761C[0]);
        } else {
            fn_1_7F230(value, mode, lbl_1_rodata_761C[0]);
        }
        lbl_8006DBAC(local);
        fn_1_563B8(result);
    }
}
/* fzgx:end fn_1_FD1D4 */

/* fzgx:begin fn_1_FD27C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

typedef struct {
    void *value;
} fn_1_FD27C_Fn1FD27CArg0;

typedef struct {
    u8 pad[0x40f0];
    void *value;
} fn_1_FD27C_Fn1FD27CArg1;

void fn_1_FD27C(fn_1_FD27C_Fn1FD27CArg0 *arg0, fn_1_FD27C_Fn1FD27CArg1 *arg1) {
    fn_1_FD27C_Fn1FD27CArg1 *persistent;
    void *value;
    void *result;
    s16 mode;
    u8 local[0x30];

    persistent = arg1;
    value = arg0->value;
    lbl_8006DB74(local);
    if (persistent->value != 0 && (*(u32 *)((u8 *)persistent->value + 4) & ~0x7fffffffU) != 0) {
        result = fn_1_563B8(fn_1_FCF50);
        mode = *(s16 *)persistent->value;
        if (mode == 0) {
            fn_1_7EB8C(value, lbl_1_rodata_761C[0]);
        } else {
            fn_1_7F20C(value, mode, lbl_1_rodata_761C[0]);
        }
        lbl_8006DBAC(local);
        fn_1_563B8(result);
    }
}
/* fzgx:end fn_1_FD27C */

/* fzgx:begin fn_1_FD324 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

typedef struct {
	u8 pad390[0x390];
	u32 a;
	u8 pad3a0[0xC];
	u32 b;
	u32 c;
} Obj_fd324;

int fn_1_FD324(void *arg0) {
	Obj_fd324 *p;

	if (arg0 == 0) {
		return 0;
	}
	p = *(Obj_fd324 **)arg0;
	if (p == 0) {
		return 0;
	}
	if ((__rlwnm(p->a, 6, 31, 31) != 0 && p->b == 0)) {
		return 0;
	}
	if (p->c == 0) {
		return 0;
	}
	return 1;
}
/* fzgx:end fn_1_FD324 */

/* fzgx:begin fn_1_FD388 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

void fn_1_FD388(void) {
    fn_1_FD3A8();
}
/* fzgx:end fn_1_FD388 */

/* fzgx:begin fn_1_FD3A8 noprologue */
#include "types.h"
#include "rel/main_rel/bg_cas.h"

typedef enum { TF5 = 5 } Sig_GXInitTexObj_GXTexFmt;
typedef enum { WRAP0 = 0 } Sig_GXInitTexObj_GXTexWrapMode;
typedef enum { FILTER1 = 1 } Sig_GXInitTexObjLOD_GXTexFilter;
typedef enum { ANISO0 = 0 } Sig_GXInitTexObjLOD_GXAnisotropy;
typedef u8 Sig_GXInitTexObjLOD_GXBool;
typedef struct { u32 dummy[8]; } Sig_GXInitTexObj_GXTexObj;
typedef struct { u32 texture_filter, texture_lod, texture_size, texture_address, user_data, texture_format, tlut_name; u16 texture_time_count; u8 texture_tile_type, texture_flags; } Sig_GXInitTexObjLOD_GXTexObj;
extern void GXInitTexObj(Sig_GXInitTexObj_GXTexObj *, void *, u16, u16, Sig_GXInitTexObj_GXTexFmt, Sig_GXInitTexObj_GXTexWrapMode, Sig_GXInitTexObj_GXTexWrapMode, u8);
extern void GXInitTexObjLOD(Sig_GXInitTexObjLOD_GXTexObj *, Sig_GXInitTexObjLOD_GXTexFilter, Sig_GXInitTexObjLOD_GXTexFilter, f32, f32, f32, Sig_GXInitTexObjLOD_GXBool, Sig_GXInitTexObjLOD_GXBool, Sig_GXInitTexObjLOD_GXAnisotropy);
extern u32 GXLoadTexMtxImm(u32,u32,u32);
struct fn_1_FD3A8_lbl_1_rodata_7600 {
 u8 pad_0[0xC]; f32 unk_C; u8 pad_10[4]; f32 unk_14; u8 pad_18[4]; f32 unk_1C; u8 pad_20[0x28]; u32 unk_48; f32 unk_4C;
};
struct fn_1_FD3A8_lbl_801A6D00 { u32 unk_0; };
extern struct fn_1_FD3A8_lbl_1_rodata_7600 lbl_1_rodata_7600;
extern struct fn_1_FD3A8_lbl_801A6D00 lbl_801A6D00;
extern u32 fn_800371F8(u32,void *);
extern u32 lbl_8006DCA4(void);
extern void fn_1_57720(u32,u32,u32,u32);
extern void fn_80015C1C(void *,f32,f32,f32,f32,f32,f32,f32,f32,f32);
extern void fn_8003462C(u32,u32,u32);
extern void fn_800720B0(u32);
extern void fn_8007245C(u32);
extern void fn_800724C8(void);
extern void fn_80072558(void);
extern void fn_80072864(u32);
extern void fn_800728A8(s32,s32,s32,s32);
extern void fn_80072AB0(s32,s32,s32);
extern void fn_80072C24(s32,s32,s32,s32,s32);
extern void fn_80072CC4(s32,s32,s32,s32,s32);
extern void fn_80072D64(s32,s32,s32,s32,u8,s32);
extern void fn_80072E20(s32,s32,s32,s32,u8,s32);
extern void fn_800734A8(u32,s32,s32,s32);
extern void fn_80073678(u32);
extern void fn_80073778(void *,s32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32,s32,s32,u32,u32,u32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32,u32,s32,s32,u32,s32,s32);
extern void fn_80074918(u8,s32,u8);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DD7C(void);
extern void lbl_8006DFC4(void *);
#pragma opt_lifetimes off
void fn_1_FD3A8(void *arg0, f32 arg1) {
    f32 r2;
    f32 r1;
 struct fn_1_FD3A8_lbl_1_rodata_7600 *p_pool;
 f32 v9;
 f32 v0;
 f32 v1;
 f32 v4;
 f32 v3;
 f32 v5;
 f32 v6;
 struct {u32 a[12];} loc_78,loc_48,loc_18;
 u32 loc_10[2]; void *lab_t1;
 v0=*(f32 *)((u8 *)arg0+64);
 p_pool=(struct fn_1_FD3A8_lbl_1_rodata_7600 *)&lbl_1_rodata_7600;
 v1=*(f32 *)((u8 *)arg0+68);
 v3=v0*arg1; v4=(-v0)*arg1; v5=(-v1)*arg1; v6=v1*arg1;
 fn_80072558();
 lbl_8006DB74((void *)(lbl_801A6D00.unk_0+96));
 lbl_8006DD7C(); lbl_8006DB74(&loc_78); lbl_8006DCA4(); lbl_8006DFC4(&loc_78);
 fn_80072558(); fn_1_57720(1,1,1,0);
 {f32 d=lbl_1_bss_850D8-lbl_1_bss_850D4; f32 m=p_pool->unk_C*d; v9=lbl_1_bss_850D4+m;}
 lbl_8006DBAC(&loc_78);
 {
 f32 r0;
 f32 t;


 t=-v9;
 r0=*(f32 *)((u8 *)0xE0000000+8); // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 r1=*(f32 *)((u8 *)0xE0000000+0x18); // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 r2=*(f32 *)((u8 *)0xE0000000+0x28); // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 r0=((((r0)) * ((t))))+*(f32 *)((u8 *)0xE0000000+0xc); // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 r1=r1*t+*(f32 *)((u8 *)0xE0000000+0x1c); // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 r2=((((r2)) * ((t))))+*(f32 *)((u8 *)0xE0000000+0x2c); // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 *(f32 *)((u8 *)0xE0000000+0xc)=r0; // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 *(f32 *)((u8 *)0xE0000000+0x1c)=r1; // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 *(f32 *)((u8 *)0xE0000000+0x2c)=r2; // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 }
 lbl_8006DB74(&loc_48); lbl_8006DCA4(); lbl_8006DFC4(&loc_48); fn_80072558();
 {f32 h=p_pool->unk_14; fn_80015C1C(&loc_18,v5,v6,v4,v3,lbl_1_bss_850D4,h,h,h,h);}
 lbl_8006DBAC(&loc_18); lbl_8006DFC4((void *)(lbl_801A6D00.unk_0+96));
 {
 f32 r0;
 f32 t;


 t=p_pool->unk_4C-v9;
 r0=*(f32 *)((u8 *)0xE0000000+8); // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 r1=*(f32 *)((u8 *)0xE0000000+0x18); // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 r2=*(f32 *)((u8 *)0xE0000000+0x28); // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 r0=((((r0)) * ((t))))+*(f32 *)((u8 *)0xE0000000+0xc); // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 r1=r1*t+*(f32 *)((u8 *)0xE0000000+0x1c); // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 r2=((((r2)) * ((t))))+*(f32 *)(((0x2c) + ((u8 *)0xE0000000))); // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 *(f32 *)((u8 *)0xE0000000+0xc)=r0; // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 *(f32 *)((u8 *)0xE0000000+0x1c)=r1; // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 *(f32 *)((u8 *)0xE0000000+0x2c)=r2; // fzgx-allow: A2 literal is a data constant in this table, not a pointer cast
 }
 GXInitTexObj((Sig_GXInitTexObj_GXTexObj *)(lbl_1_data_3EFA8+0x20),(u8 *)arg0+0x60,64,64,5,0,0,0);
 {f32 z=p_pool->unk_C; GXInitTexObjLOD((Sig_GXInitTexObjLOD_GXTexObj *)(lbl_1_data_3EFA8+0x20),1,1,z,z,z,0,0,0);}
 fn_800724C8(); fn_8007245C(0x2200); loc_10[0]=p_pool->unk_48;
 fn_80074788(1); fn_800747D0(4,0,0,0,0,2,2); loc_10[1]=loc_10[0]; lab_t1=&loc_10[1]; fn_800371F8(1,lab_t1);
 fn_80074918(1,7,0); fn_800728A8(1,4,5,0); fn_800720B0(0); fn_80072864(2);
 fn_80073778((void *)(lbl_1_data_3EFA8+0x20),0);
 GXLoadTexMtxImm(lbl_801A6D00.unk_0,30,0);
 fn_80074660(1); fn_800745A4(0,0,0,30,0,125); fn_80073678(1); fn_80073898(0); fn_80073C6C(0);
 fn_80072AB0(0,0,0); fn_800734A8(0,0,0,4); fn_80072C24(0,2,8,3,15);
 fn_80072D64(0,0,0,0,1,0); fn_80072CC4(0,7,4,1,7); fn_80072E20(0,0,0,0,1,0);
 {f32 d=lbl_1_bss_850D8-lbl_1_bss_850D4; f32 m=v9*d; f32 n=lbl_1_bss_850D4+m; v9=n/lbl_1_bss_850D4;}
 fn_8003462C(128,0,4);
 {f32 a=v9*v4; f32 c=v9*v6; f32 d=v9*v3; f32 b=v9*v5;
#define FIFO(x) *(volatile f32 *)((u8 *)0xCC010000-32768) = (x) // fzgx-allow: A2,S2 literal is a data constant in this table, not a pointer cast
 FIFO(a); FIFO(b); FIFO(p_pool->unk_C); FIFO(p_pool->unk_C); FIFO(p_pool->unk_C);
 FIFO(a); FIFO(c); FIFO(p_pool->unk_C); FIFO(p_pool->unk_C); FIFO(p_pool->unk_1C);
 FIFO(d); FIFO(c); FIFO(p_pool->unk_C); FIFO(p_pool->unk_1C); FIFO(p_pool->unk_1C);
 FIFO(d); FIFO(b); FIFO(p_pool->unk_C); FIFO(p_pool->unk_1C); FIFO(p_pool->unk_C);
#undef FIFO
 }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_FD3A8 */

/* fzgx:begin fn_1_FD844 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"

/* begin game/main_rel/bg_cas_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_BG_CAS_TYPES_H
#define GAME_MAIN_REL_BG_CAS_TYPES_H

// Types (and the externs that name them) of bg_cas.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct {
    f32 x, y, z;
} fn_1_FF6B8_CasVec;

typedef struct {
    s32 life;        /* 0x00 */
    fn_1_FF6B8_CasVec pos;      /* 0x04 */
    fn_1_FF6B8_CasVec prev;     /* 0x10 */
    fn_1_FF6B8_CasVec vel;      /* 0x1C */
    s16 rot;         /* 0x28 */
    s16 rotVel;      /* 0x2A */
    f32 scale;       /* 0x2C */
    f32 size;        /* 0x30 */
} CasParticle;

typedef struct {
    u8 pad_0[0x4];
    s32 active;      /* 0x04 */
    fn_1_FF6B8_CasVec pos;      /* 0x08 */
    u8 pad_14[0xC];
    fn_1_FF6B8_CasVec vel;      /* 0x20 */
    u8 pad_2C[0xC];
    f32 size;        /* 0x38 */
    CasParticle particles[20]; /* 0x3C */
} CasEmitter;

extern void fn_1_FF6B8(CasEmitter *em);

#endif  // GAME_MAIN_REL_BG_CAS_TYPES_H

/* end game/main_rel/bg_cas_types.h */

struct fn_1_FD3A8_lbl_1_rodata_7600 {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0x4];
    f32 unk_14;
    u8 pad_18[0x4];
    f32 unk_1C;
    u8 pad_20[0x28];
    u32 unk_48;
    f32 unk_4C;
};

struct fn_1_FD3A8_lbl_801A6D00 {
    u32 unk_0;
};

typedef struct Sig_GXInitTexObj__GXTexObj {
    u32 dummy[8];
} Sig_GXInitTexObj_GXTexObj;

typedef enum Sig_GXInitTexObj__GXTexFmt {
    Sig_GXInitTexObj_GX_TF_I4 = 0x0,
    Sig_GXInitTexObj_GX_TF_I8 = 0x1,
    Sig_GXInitTexObj_GX_TF_IA4 = 0x2,
    Sig_GXInitTexObj_GX_TF_IA8 = 0x3,
    Sig_GXInitTexObj_GX_TF_RGB565 = 0x4,
    Sig_GXInitTexObj_GX_TF_RGB5A3 = 0x5,
    Sig_GXInitTexObj_GX_TF_RGBA8 = 0x6,
    Sig_GXInitTexObj_GX_TF_CMPR = 0xE,
    Sig_GXInitTexObj_GX_CTF_R4 = 0x0 | 0x20,
    Sig_GXInitTexObj_GX_CTF_RA4 = 0x2 | 0x20,
    Sig_GXInitTexObj_GX_CTF_RA8 = 0x3 | 0x20,
    Sig_GXInitTexObj_GX_CTF_YUVA8 = 0x6 | 0x20,
    Sig_GXInitTexObj_GX_CTF_A8 = 0x7 | 0x20,
    Sig_GXInitTexObj_GX_CTF_R8 = 0x8 | 0x20,
    Sig_GXInitTexObj_GX_CTF_G8 = 0x9 | 0x20,
    Sig_GXInitTexObj_GX_CTF_B8 = 0xA | 0x20,
    Sig_GXInitTexObj_GX_CTF_RG8 = 0xB | 0x20,
    Sig_GXInitTexObj_GX_CTF_GB8 = 0xC | 0x20,
    Sig_GXInitTexObj_GX_TF_Z8 = 0x1 | 0x10,
    Sig_GXInitTexObj_GX_TF_Z16 = 0x3 | 0x10,
    Sig_GXInitTexObj_GX_TF_Z24X8 = 0x6 | 0x10,
    Sig_GXInitTexObj_GX_CTF_Z4 = 0x0 | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z8M = 0x9 | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z8L = 0xA | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z16L = 0xC | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_TF_A8 = Sig_GXInitTexObj_GX_CTF_A8,
} Sig_GXInitTexObj_GXTexFmt;

typedef enum Sig_GXInitTexObj__GXTexWrapMode {
    Sig_GXInitTexObj_GX_CLAMP,
    Sig_GXInitTexObj_GX_REPEAT,
    Sig_GXInitTexObj_GX_MIRROR,
    Sig_GXInitTexObj_GX_MAX_TEXWRAPMODE,
} Sig_GXInitTexObj_GXTexWrapMode;

typedef struct Sig_GXInitTexObjLOD__GXTexObj {
    u32 texture_filter;
    u32 texture_lod;
    u32 texture_size;
    u32 texture_address;
    u32 user_data;
    u32 texture_format;
    u32 tlut_name;
    u16 texture_time_count;
    u8 texture_tile_type;
    u8 texture_flags;
} Sig_GXInitTexObjLOD_GXTexObj;

typedef enum Sig_GXInitTexObjLOD__GXTexFilter {
    Sig_GXInitTexObjLOD_GX_NEAR,
    Sig_GXInitTexObjLOD_GX_LINEAR,
    Sig_GXInitTexObjLOD_GX_NEAR_MIP_NEAR,
    Sig_GXInitTexObjLOD_GX_LIN_MIP_NEAR,
    Sig_GXInitTexObjLOD_GX_NEAR_MIP_LIN,
    Sig_GXInitTexObjLOD_GX_LIN_MIP_LIN,
} Sig_GXInitTexObjLOD_GXTexFilter;

typedef u8 Sig_GXInitTexObjLOD_GXBool;

typedef enum Sig_GXInitTexObjLOD__GXAnisotropy {
    Sig_GXInitTexObjLOD_GX_ANISO_1,
    Sig_GXInitTexObjLOD_GX_ANISO_2,
    Sig_GXInitTexObjLOD_GX_ANISO_4,
    Sig_GXInitTexObjLOD_GX_MAX_ANISOTROPY,
} Sig_GXInitTexObjLOD_GXAnisotropy;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} FD844_Vec;

typedef struct {
    f32 x, y, z;
} CasVec;

typedef struct {
    CasVec v;
    u8 pad_C[0x34];
} CasMtx;

typedef struct {
    u32 unk_0;
    u32 unk_4;
} CasObj;

typedef struct {
    f32 x, y, z;
} CasSparkVec;

typedef struct {
    CasSparkVec pos;
    CasSparkVec base;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    s32 unk_30;
} CasSpark;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    f32 unk_C;
    u32 unk_10;
    CasSpark sparks[20];
} CasSparkSet;
extern const f32 lbl_1_rodata_7600;
extern const f32 lbl_1_rodata_7604;
extern u32 GXGetTexBufferSize(u16, u16, u32, u8, u8);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_1_FC4E0(void *arg0, int arg1);
extern void fn_1_FC51C(void);
extern struct fn_1_FD3A8_lbl_801A6D00 lbl_801A6D00;
extern void GXInitTexObj(void *, void *, u32, u32, u32, u32, u32, u32);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void GXLoadTexMtxImm(void *, u32, u32);
extern u32 fn_800371F8(u32, void *);
extern u32 lbl_8006DCA4(void);
extern void fn_1_57720(u32 value_1, u32 value_2, u32 value_3, u32 value_4);
extern void fn_80015C1C(f32 *out, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern void fn_800720B0(int);
extern void fn_8007245C(u32 value);
extern void fn_800724C8(void);
extern void fn_80072558(void);
extern void fn_80072864(u32 arg0);
extern void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80072AB0(s32 arg0, s32 arg1, s32 arg2);
extern void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072D64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_80072E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80073678(u32 arg0);
extern void fn_80073778(void *obj, s32 index);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_800745A4(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5);
extern void fn_80074660(u32 arg0);
extern void fn_80074788(u32 arg0);
extern void fn_800747D0(u32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DD7C(void);
extern void lbl_8006DFC4(void *);
extern void fn_1_FC760(void *, void *);
extern void fn_8006F1F0(FD844_Vec *, FD844_Vec *, FD844_Vec *);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern u32 fn_1_584AC(void);
extern void *memset(void *, int, u32);
extern s32 fn_1_58C4(void);
extern CasVec lbl_1_rodata_77F8;
extern CasVec lbl_1_rodata_7804;
extern CasMtx *fn_80077B14(CasObj *);
extern void fn_1_1024F8(void);
extern void fn_1_102750(void);
extern void fn_1_102C08(void);
extern void fn_800736C0(u32, void *);
extern void fn_800735C8(s32 index, s32 value);
extern void fn_80073620(s32 index, s32 value);
extern void lbl_8006D758(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006E14C(f32);
extern void *fn_1_563B8(void *);
extern void fn_1_566EC(int arg0, int arg1);
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C();
extern void fn_1_7F230();
extern void fn_1_7F1E8();
extern void *fn_1_14DD68(void *);
extern void *fn_1_14DDF4(void *);
extern void lbl_8006E0A4(void *);
extern int fn_1_FCF50(void);
extern void fn_1_FCA10(void);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_FD3A8();
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(CasEmitter *em);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void lbl_8006E13C(void *);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_FFC60(CasSparkSet *state);
extern void fn_1_FEC7C(void *object);
extern f32 lbl_1_rodata_7590[2];
extern const f32 lbl_1_rodata_7598;
extern u8 lbl_1_bss_850E0[256];
extern const f32 lbl_1_rodata_76A8;
extern u32 fn_1_904(void);
extern u32 fn_1_914(void);
extern void fn_1_681C(u32 index, u32 *output);
extern u32 fn_1_1FB80(void *, u32);
extern void fn_1_FC60C(void);
extern void DCFlushRange(void *, u32);
extern void fn_1_FB9DC(int index);
extern void fn_1_FBC5C(u8 idx);

typedef struct {
    u32 unk_0;
    u8 pad_4[8];
} FD844_Elem12;

/* the loaded cas object referenced by the context */
typedef struct {
    u8 pad_0[0x338];
    FD844_Elem12 elems[7];  /* 0x338 */
    u8 pad_38C[4];
    u32 unk_390;
    u8 pad_394[0xC];
    u32 unk_3A0;            /* table base, 0x360-byte entries */
    u8 pad_3A4[0x16];
    s16 unk_3BA;
} FD844_Obj;

/* texture descriptor at +0x20 of every 0x2060-byte source entry */
typedef struct {
    s16 unk_0;
    u8 pad_2[2];
    u32 flags;              /* 0x4 */
    s16 rot_x;              /* 0x8 */
    s16 rot_y;              /* 0xA */
    u8 pad_C[0x1C];
    FD844_Vec eye;          /* 0x28 */
    FD844_Vec target;       /* 0x34 */
    f32 unk_40;
    f32 unk_44;
    u8 pad_48[0x18];
    u8 image[0x1FE0];       /* 0x60 */
} FD844_Tex;

typedef struct {
    u8 pad_0[0x20];
    FD844_Tex tex;          /* 0x20 */
} FD844_Src;                /* 0x2060 bytes */

typedef struct {
    u8 pad_0[0x40];
    u8 texobj[0x20];        /* 0x40 */
    u8 pad_60[0x60];
    u8 mtx[0x30];           /* 0xC0 */
    u8 pad_F0[0x4104 - 0xF0];
    f32 unk_4104;
    f32 unk_4108;
    FD844_Obj *obj;         /* 0x410C */
    FD844_Tex *tex;         /* 0x4110 */
    void *sel;              /* 0x4114 */
} FD844_Slot;

typedef struct {
    FD844_Obj *obj;         /* 0x0 */
    u8 count;               /* 0x4 */
    u8 pad_5[0x10428 - 0x5];
    u32 unk_10428;
} FD844_Ctx;

/* slot i of the context: 0x4100 bytes apart, the trailing fields overlap the next slot */
#define FD844_SLOT(ctx, i) ((FD844_Slot *)((u8 *)(ctx) + (i) * 0x4100))


/* Literal pool of the retail TU (lbl_1_rodata_7600): MWCC pools literals in
 * first-use order across the TU, so the earlier functions' literals come first. */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    s = 2.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table2[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    s = 0.0f;
}
static const u32 fzgx_pool_table4[11] = {0x00000000, 0x3F000000, 0x41800000, 0x3F800000, 0x43000000,
                                         0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0xBF800000,
                                         0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

int fn_1_FD844(FD844_Src *src, FD844_Ctx *ctx) {
    u8 i;
    u32 table;
    u8 j;
    FD844_Obj *obj;
    u32 off;
    u8 *texobj;
    FD844_Vec target;
    FD844_Vec eye;

    obj = ctx->obj;
    if (src == NULL) {
        return 0;
    }
    if (ctx == NULL) {
        return 0;
    }
    if (obj == NULL) {
        return 0;
    }
    if (obj->unk_390 & 0x4000000) {
        for (j = 0; j < 3; j++) {
            table = obj->unk_3A0;
            if (table == 0) {
                return 0;
            }
            off = obj->unk_3BA << 2;
            off += j * 0x360;
            if (*(u32 *)(table + off + 0x344) == 0) {
                return 0;
            }
        }
    } else {
        if (obj->elems[obj->unk_3BA].unk_0 == 0) {
            return 0;
        }
    }

    for (i = 0; i < ctx->count; i++) {
        if (!(src[i].tex.flags & 0x80000000)) {
            *(u32 *)((u32)ctx + i * 0x4100 + 0x4110) = 0;
        } else {
            FD844_Vec up;
            FD844_SLOT(ctx, i)->obj = ctx->obj;
            {
                FD844_Vec up_init = {0.0f, 1.0f, 0.0f};
                up = up_init;
            }
            eye = src[i].tex.eye;
            target = src[i].tex.target;
            lbl_1_bss_850D4 = 2.0f;
            lbl_1_bss_850D8 = 8.0f;
            FD844_SLOT(ctx, i)->tex = &src[i].tex;
            FD844_SLOT(ctx, i)->sel = (void *)((u32)src + (src[i].tex.unk_0 << 3) + 0x81A4);
            FD844_SLOT(ctx, i)->unk_4104 = FD844_SLOT(ctx, i)->tex->unk_40;
            FD844_SLOT(ctx, i)->unk_4108 = FD844_SLOT(ctx, i)->tex->unk_44;
            fn_8006F1F0(&eye, &up, &target);
            mathutil_mtxA_rotate_x(FD844_SLOT(ctx, i)->tex->rot_x);
            mathutil_mtxA_rotate_y(FD844_SLOT(ctx, i)->tex->rot_y);
            lbl_8006DB74(FD844_SLOT(ctx, i)->mtx);
            texobj = FD844_SLOT(ctx, i)->texobj;
            GXInitTexObj(texobj, FD844_SLOT(ctx, i)->tex->image, 0x40, 0x40, 5, 0, 0, 0);
            GXInitTexObjLOD(texobj, 1, 1, 0.0f, 0.0f, 0.0f, 0, 0, 0);
        }
    }

    for (i = 0; i < ctx->count; i++) {
        FD844_Tex *tex;
        if (ctx->unk_10428 == 0) {
            break;
        }
        tex = FD844_SLOT(ctx, i)->tex;
        if (tex != NULL && (tex->flags & 0x80000000)) {
            if (0.0f == tex->unk_40 || 0.0f == tex->unk_44) {
                tex->flags &= 0x7FFFFFFF;
            } else {
                fn_1_FC760(ctx, &FD844_SLOT(ctx, i)->pad_0[0x20]);
            }
        }
    }
    return 1;
}
/* fzgx:end fn_1_FD844 */

/* fzgx:begin fn_1_FDB40 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

typedef struct {
    u32 b0 : 5;
    u32 b5 : 1;
    u32 rest : 26;
} FDB40Bits;


s32 fn_1_FDB40(void **arg0) {
    u8 *p;
    u8 *q;
    if (arg0 == 0) {
        return 0;
    }
    p = *arg0;
    if (p == 0) {
        return 0;
    }
    if (*(s16 *)(p + 800) >= 4) {
        return 0;
    }
    if (*(u32 *)(p + 932) == 0) {
        return 0;
    }
    if (*(s16 *)(p + 954) == 5) {
        return 0;
    }
    if (__rlwnm(*(u32 *)(p + 912), 6, 31, 31) && *(u32 *)(p + 928) == 0) {
        return 0;
    }
    if ((*(u32 *)(p + 912) & 0x200000) != 0) {
        return 0;
    }
    q = *(u8 **)(p + 812);
    if (q != 0 && (*(u32 *)(q + 1420) & 0x10) != 0) {
        return 0;
    }
    return 1;
}
/* fzgx:end fn_1_FDB40 */

/* fzgx:begin fn_1_FDC00 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

typedef struct Sig_fn_1_14E09C_Fn14E09CValue { void *value; } Sig_fn_1_14E09C_Fn14E09CValue;
typedef struct Sig_fn_1_14E09C_Fn14E09CRef { u8 pad8[8]; Sig_fn_1_14E09C_Fn14E09CValue *value; } Sig_fn_1_14E09C_Fn14E09CRef;
typedef struct Sig_fn_1_14E09C_Fn14E09CObj { u8 pad344[0x344]; Sig_fn_1_14E09C_Fn14E09CRef *ref; } Sig_fn_1_14E09C_Fn14E09CObj;
struct Sig_fn_1_87238_ModelItem { u32 flags; char pad[0x1c]; };
struct Sig_fn_1_87238_Model { char pad[0x18]; u16 count; char pad2[0x26]; struct Sig_fn_1_87238_ModelItem items[1]; };
struct Sig_fn_1_87238_CarSlot { struct Sig_fn_1_87238_Model **model_ptr; char pad[8]; };
struct Sig_fn_1_87238_fn_1_87238_Car { char pad[0x328]; s8 field_0x328; char pad1[0xb]; struct Sig_fn_1_87238_CarSlot slots[1]; char pad2[0x50]; u32 flags; };
struct fn_1_FDC00_Arg1 { u8 pad_0[0x40F0]; s16 *unk_40F0; };
struct fn_1_FDC00_lbl_1_rodata_7650 { u32 unk_0; u32 unk_4; u32 unk_8; };
extern u32 lbl_1_rodata_7650[3];
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_14DE80(void *, void *, void *, s8, f32);
extern void fn_1_14E054(Sig_fn_1_14E09C_Fn14E09CObj *, void *, s8, f32);
extern void fn_1_14E198(void *, void *, s8, f32);
extern void fn_1_55210(void *);
extern void fn_1_87238(struct Sig_fn_1_87238_fn_1_87238_Car *, s8, f32);
void fn_1_FDC00(void *arg0, struct fn_1_FDC00_Arg1 *arg1, f32 arg2) {
    u8 *v0;
    s8 v3;
    s16 v4;
    struct fn_1_FDC00_lbl_1_rodata_7650 loc_10;
    u32 loc_C;
    u32 loc_8;
    if (arg0 != 0) {
        v0 = *(u8 **)arg0;
        v3 = (s8)*(s16 *)(v0 + 954);
        if ((*(u32 *)(v0 + 912) & 0x4000000) != 0) {
            loc_C = 0;
            loc_8 = 0;
            loc_10 = *(struct fn_1_FDC00_lbl_1_rodata_7650 *)lbl_1_rodata_7650;
            v4 = *arg1->unk_40F0;
            v0 = *(u8 **)(v0 + 928);
            switch (v4) {
            case 0:
                fn_1_14DE80(v0, &loc_C, &loc_8, v3, lbl_1_rodata_761C[0]);
                break;
            case 1:
                fn_1_14E054((Sig_fn_1_14E09C_Fn14E09CObj *)v0, &loc_10, v3, lbl_1_rodata_761C[0]);
                break;
            case 2:
                fn_1_14E198(v0, &loc_10, v3, lbl_1_rodata_761C[0]);
                break;
            }
        } else {
            v4 = *arg1->unk_40F0;
            if (v4 == 0) {
                fn_1_87238((struct Sig_fn_1_87238_fn_1_87238_Car *)v0, v3, lbl_1_rodata_761C[0]);
            } else if (*(s8 *)(v0 + 808) == 4) {
                v0 += v3 * 12;
                v0 = *(u8 **)(v0 + 820);
                fn_1_55210(((void **)v0)[v4]);
            } else if (*(s8 *)(v0 + 808) == 40) {
                if (v3 == 0) {
                    v0 += v3 * 12;
                    v0 = *(u8 **)(v0 + 820);
                    v0 += v4 * 4;
                    fn_1_55210(*(void **)(v0 + 8));
                } else {
                    v0 += v3 * 12;
                    v0 = *(u8 **)(v0 + 820);
                    fn_1_55210(((void **)v0)[v4]);
                }
            }
        }
    }
}
/* fzgx:end fn_1_FDC00 */

/* fzgx:begin fn_1_FDD7C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

extern f32 lbl_1_rodata_7614[2];

extern f32 fn_1_843BC(void *);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern void fn_1_566EC(s32, s32);
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void fn_1_7F1E8(void *, s32, f32);
extern void lbl_8006DFE8(void *);
extern void lbl_8006DCA4(void);

typedef struct {
    u8 pad_0[0x32C];
    u8 *unk_32C;
    u8 pad_330[0x60];
    u32 unk_390;
    u8 pad_394[0x26];
    s16 unk_3BA;
} BgCasRacer;

typedef struct {
    u8 pad_0[0x40E0];
    f32 unk_40E0;
    u8 pad_40E4[0xC];
    s16 *unk_40F0;
} BgCasScene;

void fn_1_FDD7C(BgCasRacer **arg0, BgCasScene *scene) {
    s16 index;
    BgCasRacer *racer;
    f32 value;
    void *saved;
    s16 state;
    s32 mode;

    racer = *arg0;
    state = racer->unk_3BA;
    if (state == 3) {
        racer->unk_3BA = 2;
    }
    if (scene->unk_40F0 == NULL) {
        return;
    }
    index = *scene->unk_40F0;
    if (racer->unk_32C == NULL) {
        value = lbl_1_rodata_7614[0];
    } else {
        value = scene->unk_40E0 = fn_1_843BC(racer);
        if (value <= 0.7f) {
            return;
        }
    }
    saved = fn_1_563B8(fn_1_FCF50);
    mode = index;
    fn_1_566EC(1, 0xFF);
    if (racer->unk_32C != NULL) {
        lbl_8006DFE8(racer->unk_32C + 0x14C);
    } else {
        lbl_8006DCA4();
    }
    if (index == 0) {
        fn_1_7EB8C(racer, value);
    } else if (racer->unk_390 & 0x04000000) {
        fn_1_7F20C(racer, mode, value);
    } else {
        fn_1_7F1E8(racer, mode, value);
    }
    fn_1_566EC(0, 0);
    fn_1_563B8(saved);
    racer->unk_3BA = state;
}
/* fzgx:end fn_1_FDD7C */

/* fzgx:begin fn_1_FDEC8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

extern f32 lbl_1_rodata_7614[2];
extern f32 lbl_1_rodata_761C[13];
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern void fn_1_566EC(s32, s32);
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void fn_1_7F1E8(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_80072558(void);

typedef struct {
    u8 pad_0[0x32C];
    u8 *unk_32C;
    u8 pad_330[0x60];
    u32 unk_390;
    u8 pad_394[0x26];
    s16 unk_3BA;
} fn_1_FDEC8_Racer;

typedef struct {
    u8 pad_0[0x40F0];
    s16 *unk_40F0;
} fn_1_FDEC8_Scene;

void fn_1_FDEC8(fn_1_FDEC8_Racer **arg0, fn_1_FDEC8_Scene *scene) {
    s16 index;
    u8 mtx[0x30];
    s32 mode;
    fn_1_FDEC8_Racer *racer;
    void *saved;
    s16 state;
    f32 value;

    lbl_8006DB74(mtx);
    racer = *arg0;
    state = racer->unk_3BA;
    if (state == 3) {
        racer->unk_3BA = 2;
    }
    if (scene->unk_40F0 != NULL) {
        index = *scene->unk_40F0;
        if (racer->unk_32C == NULL) {
            value = lbl_1_rodata_7614[0];
        } else {
            value = lbl_1_rodata_761C[0];
        }
        saved = fn_1_563B8(fn_1_FCF50);
        mode = index;
        fn_1_566EC(1, 0xFF);
        if (index == 0) {
            fn_1_7EB8C(racer, value);
        } else if (racer->unk_390 & 0x04000000) {
            fn_1_7F20C(racer, mode, value);
        } else {
            fn_1_7F1E8(racer, mode, value);
        }
        fn_1_566EC(0, 0);
        fn_1_563B8(saved);
        racer->unk_3BA = state;
    }
    lbl_8006DBAC(mtx);
    fn_80072558();
}
/* fzgx:end fn_1_FDEC8 */

/* fzgx:begin fn_1_FDFF4 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

#include "rel/main_rel/bg_cas.h"
extern Obj_1_bss_850C6 lbl_1_bss_850C0__fzgx_offset_6;

// Mark the background-collision object as active.
void fn_1_FDFF4(void) {
    lbl_1_bss_850C0__fzgx_offset_6.unk_0 = 1;
}
/* fzgx:end fn_1_FDFF4 */

/* fzgx:begin fn_1_FE004 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

#include "rel/main_rel/bg_cas.h"
extern Obj_1_bss_850C6 lbl_1_bss_850C0__fzgx_offset_6;

void fn_1_FE004(void) {
    lbl_1_bss_850C0__fzgx_offset_6.unk_0 = 0;
}
/* fzgx:end fn_1_FE004 */

/* fzgx:begin fn_1_FE014 noprologue */
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;


typedef unsigned long u32;


typedef float f32;


typedef struct {
u8 pad_0[0x4];
u8 unk_4;
u8 unk_5;
} Obj_1_bss_850C0;
extern Obj_1_bss_850C0 lbl_1_bss_850C0;


extern void fn_80072558(void);


extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);


extern void *fn_1_563B8(void *);
extern void fn_1_566EC(int arg0, int arg1);
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C();
extern void fn_1_7F230();
extern void fn_1_7F1E8();
extern void *fn_1_14DD68(void *);
extern void *fn_1_14DDF4(void *);
extern void lbl_8006E0A4(void *);
extern int fn_1_FCF50(void);


typedef struct {
s16 unk_0;
u8 pad_2[0x360 - 2];
} CasTableEntry;
typedef struct {
u8 unk_0;
u8 pad_1[7];
} CasSelEntry;
typedef struct {
u8 pad_0[0x32C];
u32 unk_32C;
u8 pad_330[0x60];
u32 unk_390;
u8 pad_394[0xC];
CasTableEntry *unk_3A0;
u32 unk_3A4;
u8 pad_3A8[0x12];
s16 unk_3BA;
} CasObject;
typedef struct {
CasObject *value;
} CasObjectRef;
typedef struct {
u8 pad_0[0x40F0];
s16 *view;
} CasContext;
typedef struct {
u8 pad_0[0x4];
u8 unk_4;
u8 unk_5;
u8 pad_6[2];
CasSelEntry *unk_8;
u8 *unk_C;
} CasBase;
static inline void cas_draw_inner(CasObjectRef *ref, CasContext *ctx) {
u8 inner[0x30];
CasObject *obj;
void *prev;
s16 mode;
s16 saved;
f32 alpha;
lbl_8006DB74(inner);
obj = ref->value; saved = obj->unk_3BA; if (saved == 3) { obj->unk_3BA = 2; } if (ctx->view != ((void *)0)) { mode = *ctx->view; alpha = (obj->unk_32C == 0) ? 0.5f : 1.0f; prev = fn_1_563B8(fn_1_FCF50); fn_1_566EC(1, 0xff); if (mode == 0) { fn_1_7EB8C(obj, alpha); } else if (obj->unk_390 & 0x4000000) { fn_1_7F20C(obj, mode, alpha); } else { fn_1_7F1E8(obj, mode, alpha); } fn_1_566EC(0, 0); fn_1_563B8(prev); obj->unk_3BA = saved; } ;
lbl_8006DBAC(inner);
}
static inline void cas_draw_nested(CasObjectRef *ref, CasContext *ctx) {
u8 outer[0x30];
lbl_8006DB74(outer);
fn_80072558();
cas_draw_inner(ref, ctx);
fn_80072558();
lbl_8006DBAC(outer);
}
static inline void cas_draw_multi(CasObjectRef *ref, CasContext *ctx) {
CasObject *obj;
void *prev;
s16 mode;
s16 saved;
f32 alpha;
obj = ref->value; saved = obj->unk_3BA; if (saved == 3) { obj->unk_3BA = 2; } if (ctx->view != ((void *)0)) { mode = *ctx->view; alpha = (obj->unk_32C == 0) ? 0.5f : 1.0f; prev = fn_1_563B8(fn_1_FCF50); fn_1_566EC(1, 0xff); if (mode == 0) { fn_1_7EB8C(obj, alpha); } else if (obj->unk_390 & 0x4000000) { fn_1_7F230(obj, mode, alpha); } else { fn_1_7F1E8(obj, mode, alpha); } fn_1_566EC(0, 0); fn_1_563B8(prev); obj->unk_3BA = saved; } ;
}
static inline void cas_draw_single(CasObjectRef *ref, CasContext *ctx, CasBase *base) {
u8 buf[0x30];
void *res;
s16 kind;
res = ((void *)0) ;
lbl_8006DB74(buf);
kind = *ctx->view;
if (kind != 0) {
if (kind == 1) {
res = fn_1_14DD68(base->unk_C + base->unk_8->unk_0 * 0xa20);
} else if (kind == 2) {
res = fn_1_14DDF4(base->unk_C + base->unk_8->unk_0 * 0xa20);
}
lbl_8006E0A4(res);
}
fn_80072558();
cas_draw_multi(ref, ctx);
lbl_8006DBAC(buf);
}
void fn_1_FE014(CasObjectRef *ref, CasContext *ctx) {
CasBase *base = (CasBase *)&lbl_1_bss_850C0;
CasObject *obj;
CasTableEntry *tbl;
CasSelEntry *sel;
s16 idx;
s32 b;
s32 a;
obj = ref->value;
if (obj == ((void *)0) || obj->unk_3A4 == 0 || (tbl = obj->unk_3A0) == ((void *)0) || base->unk_C == ((void *)0) ||
(sel = base->unk_8) == ((void *)0) ) {
return;
}
a = tbl[0].unk_0;
b = sel[0].unk_0;
if (a == b && tbl[1].unk_0 == sel[1].unk_0 && tbl[2].unk_0 == sel[2].unk_0 && base->unk_4 == 0) {
if (base->unk_5 == *ctx->view) {
cas_draw_nested(ref, ctx);
}
} else if (base->unk_4 != 0) {
idx = *ctx->view;
if (tbl[idx].unk_0 == sel[idx].unk_0) {
cas_draw_single(ref, ctx, base);
}
} else {
idx = *ctx->view;
if (base->unk_5 == idx && tbl[idx].unk_0 == sel[idx].unk_0) {
if (a != b) {
cas_draw_single(ref, ctx, base);
} else {
cas_draw_nested(ref, ctx);
}
}
}
}
/* fzgx:end fn_1_FE014 */

/* fzgx:begin fn_1_FE5C4 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_FCA10(void);
extern int fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern f32 lbl_1_rodata_761C[13];
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_FD3A8(void);
extern void *memset(void *, int, u32);
extern void fn_1_FE7D8(u8 *, s32);
extern void fn_1_FF420(u8 *);
extern void fn_80074788(int);
extern void fn_80072864(int);
extern void fn_800745A4(int, int, int, int, int, int);
extern void fn_800734A8(int, int, int, int);
extern void fn_80072AB0(int, int, int);
extern void fn_800735C8(int, int);
extern void fn_80073620(int, int);
extern void fn_80073C6C(int);
extern void fn_80072C24(int, int, int, int, int);
extern void fn_80072D64(int, int, int, int, int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);
extern void fn_80073678(int);
extern void fn_80074660(int);
extern void fn_80074918(int, int, int);
extern void fn_800720B0(int);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern void fn_1_10069C(Obj_1_data_2A7E0_At3C *);
extern void fn_1_FF038(Obj_1_data_2A7E0_At3C *);
extern const f64 lbl_1_rodata_760C;
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_1_bss_851E0[36];
extern void fn_1_7F230(void *, s32, f32);
extern void fn_1_FFC60(Obj_1_data_2A7E0_At3C *arg0);
extern void fn_1_FEC7C(void *object);
extern const f32 lbl_1_rodata_76A8;

#include "rel/main_rel/bg_cas.h"

void fn_1_FE5C4(u8 arg0, u32 arg1, u32 arg2, u8 arg3) {
    lbl_1_bss_850C0.unk_4 = arg3;
    lbl_1_bss_850C0.unk_5 = arg0;
    *(u32 *)((u8 *)&lbl_1_bss_850C0 + 0x8) = arg2;
    *(u32 *)((u8 *)&lbl_1_bss_850C0 + 0xc) = arg1;
}
/* fzgx:end fn_1_FE5C4 */
