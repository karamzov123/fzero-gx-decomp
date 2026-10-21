#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/avline.h"

extern u32 lbl_801A6410;
extern u32 fn_1_45D0(u32, u32, unsigned char *, u32);
extern void fn_1_46B4(u32, u32, void *, u32);
extern u8 lbl_1_data_1D62C[148];
extern void fn_1_9F870(void);
extern void fn_1_58158(void);

/* fzgx:begin fn_1_58114 */
void fn_1_58114(void) {
    lbl_1_bss_6C840 = fn_1_45D0(lbl_801A6410, 0x6590, lbl_1_data_1C68C, 0x39f);
}
/* fzgx:end fn_1_58114 */

/* fzgx:begin fn_1_58158 */
// fn_1_58158: loads global values and calls fn_1_46B4.
void fn_1_58158(void) {
    u32 v1 = lbl_801A6410;
    u32 v2 = lbl_1_bss_6C840;
    fn_1_46B4(v1, v2, &lbl_1_data_1C68C, 0x3a6);
}
/* fzgx:end fn_1_58158 */

/* fzgx:begin fn_1_5819C */
void fn_1_5819C(void) {
    lbl_1_bss_6C844 = 0;
}
/* fzgx:end fn_1_5819C */

/* fzgx:begin fn_1_581AC */
extern u16 lbl_1_bss_6C844;
extern u32 lbl_1_bss_6C840;

typedef struct AvLineEntry {
    u16 unk_00;
    u16 unk_02;
    u8 unk_04[0x100];
} AvLineEntry;

extern void fn_80008BA8(void*, void*, u32);

#pragma opt_propagation off
s32 fn_1_581AC(u16 value, u16 type, void* data) {
    AvLineEntry *entry;
    u8 *p;

    if (lbl_1_bss_6C844 == 0x64) {
        return 0;
    }

    ((AvLineEntry*)lbl_1_bss_6C840)[lbl_1_bss_6C844].unk_00 = value;
    p = (u8*)lbl_1_bss_6C840 + lbl_1_bss_6C844 * 0x104;
    entry = (AvLineEntry*)p;
    entry->unk_02 = type;
    fn_80008BA8(((AvLineEntry*)lbl_1_bss_6C840)[lbl_1_bss_6C844].unk_04, data, 0x100);
    lbl_1_bss_6C844++;
    return 1;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_581AC */

/* fzgx:begin fn_1_58248 */
typedef struct AvLineState {
    u8 unk_0;
    u8 pad_1[3];
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
    s32 unk_14;
} AvLineState;

typedef struct AvLineVtx {
    f32 x, y, z;
    u8 r, g, b, a;
} AvLineVtx;

typedef struct AvLineEntry2 {
    u16 unk_00;
    u16 unk_02;
    AvLineVtx unk_04[16];
} AvLineEntry2;

typedef union AvWGPipe {
    volatile u8 u8;  /* fzgx-allow: S2 AI pipe register, write-only hardware */
    volatile f32 f32;  /* fzgx-allow: S2 AI pipe register, write-only hardware */
} AvWGPipe;

#define AV_WGPIPE ((AvWGPipe *)0xCC008000)  /* fzgx-allow: A1,A2 AI pipe register block */

extern AvLineState lbl_1_data_1C670;
extern u32 lbl_801A6D00;
extern void GXLoadPosMtxImm(u32, u32);
extern void fn_800720B0(u32);
extern void fn_80072EDC(s32, u32);
extern void lbl_8006DCA4(void);
extern void fn_8003462C(u32, u32, u16);
extern void fn_8007245C(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073678(u32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_80074918(u8, s32, u8);
extern void fn_800746A8(u8, s32);

static inline void AvPos(f32 x, f32 y, f32 z) {
    AV_WGPIPE->f32 = x;
    AV_WGPIPE->f32 = y;
    AV_WGPIPE->f32 = z;
}

static inline void AvCol(s8 r, s8 g, s8 b, s8 a) {
    AV_WGPIPE->u8 = r;
    AV_WGPIPE->u8 = g;
    AV_WGPIPE->u8 = b;
    AV_WGPIPE->u8 = a;
}

#define AvDraw(a, b) AvDraw_(b, a)
static inline void AvDraw_(u16 n, AvLineVtx *v) {
    s32 j;

    if (n >= 2) {
        fn_8003462C(0xb0, 0, n);
        for (j = 0; j < n; j++) {
            AvPos(v->x, v->y, v->z);
            AvCol(v->r, v->g, v->b, v->a);
            v++;
        }
    }
}

void fn_1_58248(void) {
    s32 i;
    AvLineEntry2 *entry;

    lbl_1_data_1C670.unk_4 = 1;
    lbl_1_data_1C670.unk_8 = 1;
    lbl_1_data_1C670.unk_C = 1;
    lbl_1_data_1C670.unk_10 = 0;
    lbl_8006DCA4();
    fn_80074918(1, 3, 1);
    fn_800746A8(lbl_1_data_1C670.unk_0, lbl_1_data_1C670.unk_14);
    fn_8007245C(0xa00);
    fn_800728A8(lbl_1_data_1C670.unk_4, lbl_1_data_1C670.unk_8, lbl_1_data_1C670.unk_C, lbl_1_data_1C670.unk_10);
    fn_800720B0(0);
    fn_800747D0(4, 0, 1, 1, 0, 2, 1);
    fn_800734A8(0, 0xff, 0xff, 4);
    fn_80072EDC(0, 4);
    fn_80073C6C(0);
    fn_80073678(1);
    fn_80074660(0);
    fn_80073898(0);
    fn_80074788(1);
    GXLoadPosMtxImm(lbl_801A6D00, 0);

    for (i = 0; i < lbl_1_bss_6C844; i++) {
        entry = &((AvLineEntry2 *)lbl_1_bss_6C840)[i];
        lbl_1_data_1C670.unk_0 = entry->unk_00;
        AvDraw(entry->unk_04, entry->unk_02);
    }
    lbl_1_bss_6C844 = 0;
}
/* fzgx:end fn_1_58248 */

/* fzgx:begin fn_1_584AC */
// fn_1_584AC: linear congruential generator.
u32 fn_1_584AC(void) {
    u32 state = lbl_1_data_1D628;
    u32 next = state * 0x41c64e6du + 0x3039u;
    lbl_1_data_1D628 = next;
    return (next >> 16) & 0x7FFFu;
}
/* fzgx:end fn_1_584AC */

/* fzgx:begin fn_1_58694 noprologue */
#include "types.h"

typedef struct AvlineVec3 {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} AvlineVec3;

typedef struct AvlineEntry {
    s8 unk_00;
    u8 _pad01[0x0b];
    s16 unk_0c;
    u8 _pad0e[0x02];
    s32 unk_10;
    u8 _pad14[0x28];
    AvlineVec3 unk_3c;
    u8 _pad48[0x18];
    AvlineVec3 unk_60;
    u8 _pad6c[0x7c];
} AvlineEntry;

typedef struct AvlineState {
    AvlineEntry *unk_00;
    AvlineEntry *unk_04;
    u8 _pad08[0x0c];
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
} AvlineState;

typedef void (*AvlineHandler)(AvlineEntry *);

extern AvlineState lbl_1_bss_6C848;
extern AvlineHandler lbl_1_data_1D514[];
extern AvlineHandler lbl_1_data_1D2EC[];
extern s16 fn_1_3F0C8(void);
extern void fn_1_3BDC(s32);
extern void fn_1_3C18(s32);

void fn_1_58694(void) {
    AvlineState *state = &lbl_1_bss_6C848;
    s32 count;
    AvlineEntry *entry;

    if (fn_1_3F0C8() != 0x28) {
        entry = state->unk_00;
        state->unk_14 = 0;
        state->unk_18 = 0;
        state->unk_1c = 0;
        state->unk_20 = 0;
        fn_1_3BDC(9);
        for (count = 0xbe; count > 0; count--) {
            if (entry->unk_00 != 0) {
                entry->unk_10 -= 1;
                if (entry->unk_10 == 0 || entry->unk_00 == 3) {
                    lbl_1_data_1D514[entry->unk_0c](entry);
                    entry->unk_00 = 0;
                } else {
                    entry->unk_60 = entry->unk_3c;
                    lbl_1_data_1D2EC[entry->unk_0c](entry);
                }
            }
            entry++;
        }
        entry = state->unk_04;
        for (count = 0xc8; count > 0; count--) {
            if (entry->unk_00 != 0) {
                entry->unk_10 -= 1;
                if (entry->unk_10 == 0 || entry->unk_00 == 3) {
                    lbl_1_data_1D514[entry->unk_0c](entry);
                    entry->unk_00 = 0;
                } else {
                    entry->unk_60 = entry->unk_3c;
                    lbl_1_data_1D2EC[entry->unk_0c](entry);
                }
            }
            entry++;
        }
        fn_1_3C18(9);
    }
}
/* fzgx:end fn_1_58694 */

/* fzgx:begin fn_1_58854 */
typedef struct {
    s8 unk_0;
    u8 pad_1[0xb];
    s16 unk_C;
} AvlineObj;

typedef void (*AvlineCallback)(void *);

void fn_1_58854(void) {
    s32 count;
    AvlineObj *obj;
    s32 index;
    AvlineCallback callback;

    fn_1_9F870();
    fn_1_58158();

    obj = *(AvlineObj **)&lbl_1_bss_6C848;
    count = 0xbe;
    index = 0;
    while (count > 0) {
        if (obj->unk_0 != 0) {
            callback = ((AvlineCallback *)lbl_1_data_1D514)[obj->unk_C];
            callback(obj);
            obj->unk_0 = index;
        }
        count--;
        obj = (AvlineObj *)((u8 *)obj + 0xe8);
    }

    obj = (AvlineObj *)lbl_1_bss_6C84C;
    count = 0xc8;
    index = 0;
    while (count > 0) {
        if (obj->unk_0 != 0) {
            callback = ((AvlineCallback *)lbl_1_data_1D514)[obj->unk_C];
            callback(obj);
            obj->unk_0 = index;
        }
        count--;
        obj = (AvlineObj *)((u8 *)obj + 0xe8);
    }

    fn_1_46B4(lbl_801A6410, *(u32 *)&lbl_1_bss_6C848,
              lbl_1_data_1D62C, 0x156);
    fn_1_46B4(lbl_801A6410, *(u32 *)&lbl_1_bss_6C84C,
              lbl_1_data_1D62C, 0x157);

    *(u32 *)&lbl_1_bss_6C848 = 0;
    lbl_1_bss_6C84C = 0;
}
/* fzgx:end fn_1_58854 */

/* fzgx:begin fn_1_591A0 */
typedef struct {
    s8 unk_0;
    u8 pad_1[0x7];
    u32 unk_8;
    s16 unk_C;
    u8 pad_E[0xDA];
} Fn591A0Obj;

void fn_1_591A0(s32 id) {
    {
        Fn591A0Obj *obj;
        void (**table)(void *);
        s32 count;
        s32 zero;

        obj = *(Fn591A0Obj **)&lbl_1_bss_6C848;
        table = (void (**)(void *))lbl_1_data_1D514;
        zero = 0;
        for (count = 0xbe; count > 0; count--) {
            if (obj->unk_0 && obj->unk_C == id) {
                table[obj->unk_C](obj);
                obj->unk_8 |= (u32)0x8000 << 16;
                obj->unk_0 = zero;
            }
            obj++;
        }
    }
    {
        s32 count;
        Fn591A0Obj *obj;
        void (**table)(void *);
        s32 zero;

        obj = (Fn591A0Obj *)lbl_1_bss_6C84C;
        table = (void (**)(void *))lbl_1_data_1D514;
        zero = 0;
        for (count = 0xc8; count > 0; count--) {
            if (obj->unk_0 && obj->unk_C == id) {
                table[obj->unk_C](obj);
                obj->unk_8 |= (u32)0x8000 << 16;
                obj->unk_0 = zero;
            }
            obj++;
        }
    }
}
/* fzgx:end fn_1_591A0 */

/* fzgx:begin fn_1_60880 */
extern u32 lbl_801A6410;
extern u32 fn_1_45D0(u32, u32, unsigned char *, u32);
extern void fn_1_46B4(u32, u32, void *, u32);
extern u8 lbl_1_data_1D62C[148];
extern void fn_1_9F870(void);
extern void fn_1_58158(void);


#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    s = 0.0f;
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const u32 fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
}
#pragma section code_type ".text"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Avl60880Vec;

typedef struct {
    u8 state;           // 0x00
    u8 pad_1[0x27];
    f32 size;           // 0x28
    u8 pad_2C[0x10];
    Avl60880Vec pos;    // 0x3c
    Avl60880Vec vel;    // 0x48
    s16 rotX;           // 0x54
    s16 rotY;           // 0x56
    s16 rotZ;           // 0x58
    s16 spinX;          // 0x5a
    s16 spinY;          // 0x5c
    s16 spinZ;          // 0x5e
} Avl60880Obj;

extern s32 lbl_1_bss_6C85C;
extern s32 fn_1_66B8(Avl60880Vec *, f32);
extern void lbl_8006D8D8(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_z(s16);
extern void lbl_8006E1C0(Avl60880Vec *, Avl60880Vec *);
extern f32 lbl_8006D0B4(f32);

#pragma opt_dead_assignments off
void fn_1_60880(Avl60880Obj *obj) {
    f32 dragScale;
    f32 fzgx_live;
    Obj_1_data_1CC74_Target *grav = lbl_1_data_1CC74;
    Avl60880Vec up;
    f64 d;
    f64 drag;
    f32 vx;
    f32 vy;
    f32 vz;
    f32 dot;
    struct { f32 value; } scale;
    f32 lenSq;
    struct { f32 value; } k;

    if (++lbl_1_bss_6C85C > 200) {
        obj->state = 3;
    }
    if (fn_1_66B8(&obj->pos, 4.0f) == 0) {
        obj->state = 3;
    }

    obj->vel.x = obj->vel.x + (f64)(0.003 * grav->unk_0);
    obj->vel.y = obj->vel.y + (f64)(0.003 * grav->unk_4);
    obj->vel.z = obj->vel.z + (f64)(0.003 * grav->unk_8);

    lbl_8006D8D8(obj->rotY);
    mathutil_mtxA_rotate_x(obj->rotX);
    mathutil_mtxA_rotate_z(obj->rotZ);

    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
    lbl_8006E1C0(&up, &up);

    vx = obj->vel.x;
    lenSq = vx * vx;
    vy = obj->vel.y;
    lenSq += vy * vy;
    vz = obj->vel.z;
    lenSq += vz * vz;
    d = (f64)(0.141 * lbl_8006D0B4(lenSq)) - 0.7f;
    drag = (d < -0.7f) ? -0.7f : ((d > -0.03f) ? -0.03f : d);

    dot = up.x * obj->vel.x;
    fzgx_live = up.y;
    dot += fzgx_live * obj->vel.y;
    vz = up.z;
    dot += vz * obj->vel.z;
    scale.value = (f32)drag * dot;
    obj->vel.x += (f32)(up.x * scale.value);
    fzgx_live = up.y;
    obj->vel.y += (f32)(fzgx_live * scale.value);
    obj->vel.z += (f32)(up.z * scale.value);

    obj->vel.x *= 0.96f;
    obj->vel.y *= 0.96f;
    obj->vel.z *= 0.96f;

    obj->pos.x += obj->vel.x;
    obj->pos.y += obj->vel.y;
    obj->pos.z += obj->vel.z;

    k.value = 512.0f / (10.0f * obj->size);
    obj->spinX += (s32)(k.value * (obj->vel.x + obj->vel.y));
    obj->spinY += (s32)(k.value * (obj->vel.y + obj->vel.z));
    obj->spinZ += (s32)(k.value * (obj->vel.z + obj->vel.x));

    obj->spinX -= obj->spinX >> 5;
    obj->spinY -= obj->spinY >> 5;
    obj->spinZ -= obj->spinZ >> 5;

    obj->rotX += obj->spinX;
    obj->rotY += obj->spinY;
    obj->rotZ += obj->spinZ;
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_60880 */

/* fzgx:begin fn_1_61370 */
extern u32 lbl_801A6410;
extern u32 fn_1_45D0(u32, u32, unsigned char *, u32);
extern void fn_1_46B4(u32, u32, void *, u32);
extern u8 lbl_1_data_1D62C[148];
extern void fn_1_9F870(void);
extern void fn_1_58158(void);


#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const unsigned long fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const unsigned long fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const unsigned long fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const unsigned long fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const unsigned long fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const unsigned long fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const unsigned long fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const unsigned long fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const unsigned long *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
}
#pragma section code_type ".text"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_61370_Vec;

typedef struct {
    u8 pad_0[0x14];
    s32 count;
    u8 pad_18[0x10];
    f32 scale;
    u8 pad_2C[0xC];
    fn_1_61370_Vec *trail;
    fn_1_61370_Vec pos;
    fn_1_61370_Vec vel;
    s16 ang[3];
    s16 rot[3];
    u8 pad_60[0x4C];
    s16 unk_AC;
} fn_1_61370_Obj;

extern void lbl_8006D8D8(s32);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_z(s32);
extern void lbl_8006E1C0(fn_1_61370_Vec *, fn_1_61370_Vec *);

static inline f32 fn_1_61370_read_pointer(fn_1_61370_Vec * owner) { return owner->z; }
#pragma opt_propagation off
void fn_1_61370(fn_1_61370_Obj *p) {
    s16 * fzgx_live;
    Obj_1_data_1CC74_Target *target = lbl_1_data_1CC74;
    fn_1_61370_Vec up;
    fn_1_61370_Vec *trail;
    f32 s;
    f32 k;
    f32 dot;

    p->vel.x += (f64)(0.003 * target->unk_0);
    p->vel.y += (f64)(0.003 * target->unk_4);
    p->vel.z += (f64)(0.003 * target->unk_8);

    lbl_8006D8D8(p->ang[1]);
    mathutil_mtxA_rotate_x(p->ang[0]);
    mathutil_mtxA_rotate_z(p->ang[2]);

    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
    lbl_8006E1C0(&up, &up);

    /* reflect the velocity off the rotated up axis */
    {
        f32 up_z;
        f32 up_x;
        f32 dot;
        up_x = up.x;
        dot = up_x * p->vel.x;
        dot += up.y * p->vel.y;
        up_z = up.z;
        dot += up_z * p->vel.z;
        s = -0.9f * dot;
        p->vel.x += (f32)(up_x * s);
    }
    p->vel.y += (f32)(up.y * s);
    p->vel.z += (f32)(up.z * s);
    p->vel.x *= 0.95f;
    p->vel.y *= 0.95f;
    p->vel.z *= 0.95f;
    p->pos.x += p->vel.x;
    p->pos.y += p->vel.y;
    p->pos.z += p->vel.z;

    k = 512.0f / p->scale;
    fzgx_live = p->rot;
    fzgx_live[0] += (s32)(k * (p->vel.x + p->vel.y));
    fzgx_live = p->rot;
    fzgx_live[1] += (s32)(k * (p->vel.y + p->vel.z));
    fzgx_live = p->rot;
    fzgx_live[2] += (s32)(k * (p->vel.z + p->vel.x));
    fzgx_live = p->rot;
    fzgx_live[0] -= fzgx_live[0] >> 5;
    fzgx_live = p->rot;
    fzgx_live[1] -= fzgx_live[1] >> 5;
    fzgx_live = p->rot;
    fzgx_live[2] -= fzgx_live[2] >> 5;
    fzgx_live = p->rot;
    p->ang[0] += fzgx_live[0];
    fzgx_live = p->rot;
    p->ang[1] += fzgx_live[1];
    fzgx_live = p->rot;
    p->ang[2] += fzgx_live[2];

    if (p->count > 20) {
        p->count = 0;
    }
    trail = p->trail;
    trail[p->count].x = p->pos.x;
    trail[p->count].y = p->pos.y;
    trail[p->count].z = p->pos.z;
    p->count++;

    if (p->unk_AC < 20) {
        p->unk_AC++;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_61370 */

/* fzgx:begin fn_1_62C84 noprologue */
#include "dolphin/types.h"
#include "rel/main_rel/avline.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const u32 fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
    s = 1.059999942779541f;
    s = 28.0f;
    d = 5.0;
    s = 3.5f;
    s = 180.0f;
}
static const u32 fzgx_pool_table22[2] = {0xFFFFFFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 30.0;
    d = 0.03;
    s = 0.9399999976158142f;
    s = -0.07999999821186066f;
}
#pragma section code_type ".text"
extern u32 lbl_1_bss_6C868;
extern const f32 lbl_1_rodata_2950;
extern s32 fn_1_66B8(void *, f32);
typedef struct {
 u8 unk_0; u8 pad_1[0x27]; f32 unk_28; u8 pad_2C[0x10];
 f32 unk_3C, unk_40, unk_44, unk_48, unk_4C, unk_50;
 s16 unk_54, unk_56, unk_58, unk_5A, unk_5C, unk_5E;
} Particle;
#pragma fp_contract off
void fn_1_62C84(Particle *p) {
 const u8 *pool = (const u8 *)&lbl_1_rodata_2950;
 Obj_1_data_1CC74_Target *accel = lbl_1_data_1CC74;
 f32 factor;
 if ((s32)++lbl_1_bss_6C868 > 50) p->unk_0 = 3;
 if (fn_1_66B8(&p->unk_3C, (1.0f)) == 0) p->unk_0 = 3;
 {
 f64 acceleration_scale = (0.029999999999999999);
 f32 damping = (0.939999998f);
 f32 radius_scale = (10.0f);
 f32 angular_scale = (512.0f);
 p->unk_48 += acceleration_scale * accel->unk_0;
 p->unk_4C += acceleration_scale * accel->unk_4;
 p->unk_50 += acceleration_scale * accel->unk_8;
 p->unk_48 *= damping;
 p->unk_4C *= damping;
 p->unk_50 *= damping;
 p->unk_3C += p->unk_48;
 p->unk_40 += p->unk_4C;
 p->unk_44 += p->unk_50;
 factor = angular_scale / (radius_scale * p->unk_28);
 p->unk_5A += (s32)(factor * (p->unk_48 + p->unk_4C));
 p->unk_5C += (s32)(factor * (p->unk_4C + p->unk_50));
 p->unk_5E += (s32)(factor * (p->unk_50 + p->unk_48));
 p->unk_5A -= p->unk_5A >> 5;
 p->unk_5C -= p->unk_5C >> 5;
 p->unk_5E -= p->unk_5E >> 5;
 p->unk_54 += p->unk_5A;
 p->unk_56 += p->unk_5C;
 p->unk_58 += p->unk_5E;
 }
}
/* fzgx:end fn_1_62C84 */
