#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_lig.h"

extern void fn_80008BA8(void *arg0, void *arg1, int arg2);
extern u32 lbl_801A66A0;
extern u32 lbl_1_rodata_6358;

/* fzgx:begin fn_1_D5C70 */
#include "sdk_addresses.h"

extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_801A63C0;
extern u32 lbl_801A66C8;
extern void *memset(void *dst, int value, u32 size);
extern f32 lbl_8006D0B4(f32);
extern s32 fn_1_58C4(void);
extern u32 fn_1_584AC(void);
extern s16 fn_1_58E3C(void *source);

typedef struct {
    u32 unk0;
    void *data;
    u32 unk8;
    u32 flags;
    u8 rest[0xac - 0x10];
} Elem;

#define IDX (*(s32 *)(p - 0x1820))
#define FLAG(idx) (((Elem *)(p - 0x1820))[idx].flags)
#define DATA(idx) (((Elem *)(p - 0x1820))[idx].data)
#define SB0 (*(s16 *)(p - 0x1888))
#define SB1 (*(s16 *)(p - 0x1886))

s32 fn_1_D5C70(u32 arg0, u32 *arg1) {
    u8 *p;
    u8 *scan;

    p = (u8 *)lbl_1_data_2A7E0.unk_3C + 0x10000;

    switch (arg0) {
    case 0:
        FLAG(IDX) |= 0x40000000;
        FLAG(IDX) |= 0x10000000;
        DATA(IDX) = arg1;
        IDX = IDX + 1;
        if (IDX >= 32) {
            OSPanic("bg_lig.c", 0x577, "SPOT LIGHT OVER!");
        }
        break;
    case 1:
        FLAG(IDX) |= 0x40000000;
        FLAG(IDX) |= 0x20000000;
        DATA(IDX) = arg1;
        IDX = IDX + 1;
        if (IDX >= 32) {
            OSPanic("bg_lig.c", 0x57e, "SPOT LIGHT OVER!");
        }
        break;
    case 2:
        FLAG(IDX) |= 0x40000000;
        FLAG(IDX) |= 0x10000000;
        FLAG(IDX) |= 0x08000000;
        DATA(IDX) = arg1;
        IDX = IDX + 1;
        if (IDX >= 32) {
            OSPanic("bg_lig.c", 0x586, "SPOT LIGHT OVER!");
        }
        break;
    case 3:
        FLAG(IDX) |= 0x40000000;
        FLAG(IDX) |= 0x20000000;
        FLAG(IDX) |= 0x08000000;
        DATA(IDX) = arg1;
        IDX = IDX + 1;
        if (IDX >= 32) {
            OSPanic("bg_lig.c", 0x58e, "SPOT LIGHT OVER!");
        }
        break;
    case 5:
        *arg1 |= 0x01000000;
        break;
    case 6:
        if (fn_1_58C4() <= 2) {
            *arg1 |= 0x02000000;
            SB0 = 0x1b;
            SB1 = 0x28;
        } else {
            *arg1 &= ~0x02000000;
        }
        break;
    case 7:
    case 8:
    case 9:
        if (fn_1_58C4() <= 2) {
            *arg1 |= 0x02000000;
            SB0 = 0x18;
            SB1 = 0x18;
        } else {
            *arg1 &= ~0x02000000;
        }
        break;
    case 10:
        scan = (u8 *)lbl_1_bss_3BE0->unk_54;
        *(s32 *)(p - 0x29c) = 0;
        while (scan != (u8 *)arg1) {
            scan += 0x40;
            *(s32 *)(p - 0x29c) = *(s32 *)(p - 0x29c) + 1;
        }
        *arg1 |= 0x80000000;
        break;
    default:
        break;
    }
    return 1;
}
/* fzgx:end fn_1_D5C70 */

/* fzgx:begin fn_1_D5FA8 */
typedef union PPCWGPipe {
u8 u8;
u16 u16;
u32 u32;
s8 s8;
s16 s16;
s32 s32;
f32 f32;
f64 f64;
} PPCWGPipe;


/* GX write-gather FIFO: hardware register, every store must reach it. */
volatile PPCWGPipe GXWGFifo : FZGX_ADDR_GXFIFO;
extern s32 *fn_8000961C(s32);
extern void *OSGetArenaLo(void);
extern u32 OSGetArenaHi(void);
extern void fn_80074918(u8, s32, u8);
extern void fn_80074788(u32);
extern void fn_80074660(u32);
extern void fn_80073678(u32);
extern void fn_80073C6C(s32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072864(u32);
extern void fn_8007245C(u32);
extern u32 fn_800371F8(u32, void *);
extern void fn_8003462C(u32, u32, u32);
extern u32 lbl_801A66C8;
typedef struct HeapBlock {
struct HeapBlock *prev;
struct HeapBlock *next;
u32 size;
} HeapBlock;
typedef struct HeapView { f32 x, y, z; } HeapView;
typedef struct HeapColor { u8 r, g, b, a; } HeapColor;
static inline void VERT(f32 x, f32 y, f32 z) { (GXWGFifo.f32 = (f32)(x)) ; (GXWGFifo.f32 = (f32)(y)) ; (GXWGFifo.f32 = (f32)(z)) ; }
void fn_1_D5FA8(s32 heap, HeapView *pos, f32 width, f32 height) {
HeapBlock *head;
u32 lo;
u32 hi;
HeapBlock *block;
u32 index;
HeapBlock *scan;
u32 count;
f32 start, end;
f32 depth;
head = (HeapBlock *)fn_8000961C(heap);
lo = (u32)OSGetArenaLo();
hi = OSGetArenaHi();
fn_80074918(0, 7, 0);
fn_80074788(1);
fn_80074660(0);
fn_80073678(1);
fn_80073C6C(0);
fn_800747D0(4, 0, 0, 0, 0, 2, 2);
fn_80072AB0(0, 0, 0);
fn_800734A8(0, 255, 255, 4);
fn_80072C24(0, 15, 15, 15, 2);
fn_80072D64(0, 0, 0, 0, 1, 0);
fn_80072CC4(0, 7, 7, 7, 1);
fn_80072E20(0, 0, 0, 0, 1, 0);
fn_800728A8(1, 4, 5, 0);
fn_80072864(2);
fn_8007245C(512);
{
HeapColor color = { 0x00, 0x00, 0x00, 0xFF };
fn_800371F8(1, &color);
}
fn_8003462C(128, 7, 4);
VERT(pos->x, pos->y, pos->z);
VERT(pos->x+width, pos->y, pos->z);
VERT(pos->x+width, pos->y+height, pos->z);
VERT(pos->x, pos->y+height, pos->z);
width -= 1.0f;
height -= 1.0f;
pos->x += 1.0f;
pos->y += 1.0f;
{
HeapColor color = { 0x7F, 0x7F, 0x7F, 0xFF };
fn_800371F8(1, &color);
}
fn_8003462C(128, 7, 4);
VERT(pos->x, pos->y, pos->z-0.001f);
VERT(pos->x+width, pos->y, pos->z-0.001f);
VERT(pos->x+width, pos->y+height, pos->z-0.001f);
VERT(pos->x, pos->y+height, pos->z-0.001f);
{
HeapColor color = { 0x00, 0xFF, 0x00, 0xFF };
fn_800371F8(1, &color);
}
fn_8003462C(128, 7, 4);
depth = 0.002f;
VERT(pos->x+(((u32)(lo) + 0x80000000)) *width/25165824.0f , pos->y, pos->z-depth);
VERT(pos->x+(((u32)(hi) + 0x80000000)) *width/25165824.0f , pos->y, pos->z-depth);
VERT(pos->x+(((u32)(hi) + 0x80000000)) *width/25165824.0f , pos->y+height, pos->z-depth);
VERT(pos->x+(((u32)(lo) + 0x80000000)) *width/25165824.0f , pos->y+height, pos->z-depth);
if (head) {
block = (HeapBlock *)head->size;
while (block) {
HeapColor color = { 0xFF, 0x00, 0x00, 0xFF };
fn_800371F8(1, &color);
fn_8003462C(128, 7, 4);
VERT(pos->x+(((u32)(block) + 0x80000000)) *width/25165824.0f , pos->y, pos->z-depth);
VERT(pos->x+width*((((u32)block+block->size) + 0x80000000)) /25165824.0f , pos->y, pos->z-depth);
VERT(pos->x+width*((((u32)block+block->size) + 0x80000000)) /25165824.0f , pos->y+height, pos->z-depth);
VERT(pos->x+(((u32)(block) + 0x80000000)) *width/25165824.0f , pos->y+height, pos->z-depth);
block = block->next;
}
head = head->next;
count = 0;
scan = head;
while (scan) {
scan = scan->next;
if (scan) {
count++;
}
}
index = 0;
while (head) {
HeapColor color = { 0x00, 0x00, 0xFF, 0xFF };
fn_800371F8(1, &color);
if (head->next) {
if (index == (lbl_801A66C8 >> 7) % count) {
HeapColor blink = { 0xFF, 0xFF, 0x00, 0xFF };
fn_800371F8(1, &blink);
}
index++;
}
fn_8003462C(128, 7, 4);
VERT(pos->x+(((u32)(head) + 0x80000000)) *width/25165824.0f , pos->y, pos->z-depth);
VERT(pos->x+width*((((u32)head+head->size) + 0x80000000)) /25165824.0f , pos->y, pos->z-depth);
VERT(pos->x+width*((((u32)head+head->size) + 0x80000000)) /25165824.0f , pos->y+height, pos->z-depth);
VERT(pos->x+(((u32)(head) + 0x80000000)) *width/25165824.0f , pos->y+height, pos->z-depth);
head = head->next;
}
}
}
/* fzgx:end fn_1_D5FA8 */

/* fzgx:begin fn_1_D6680 */
// fn_1_D6680: returns a constant.
int fn_1_D6680(void) {
    return 0;
}
/* fzgx:end fn_1_D6680 */

/* fzgx:begin fn_1_D6688 */
// fn_1_D6688: returns a constant.
int fn_1_D6688(void) {
    return 1;
}
/* fzgx:end fn_1_D6688 */

/* fzgx:begin fn_1_D6690 */
// fn_1_D6690: returns a constant.
int fn_1_D6690(void) {
    return 0;
}
/* fzgx:end fn_1_D6690 */

/* fzgx:begin fn_1_D6698 */
// fn_1_D6698: returns a constant.
int fn_1_D6698(void) {
    return 0;
}
/* fzgx:end fn_1_D6698 */

/* fzgx:begin fn_1_D66A0 */
// fn_1_D66A0: returns a constant.
int fn_1_D66A0(void) {
    return 0;
}
/* fzgx:end fn_1_D66A0 */

/* fzgx:begin fn_1_D66A8 */
// fn_1_D66A8: returns a constant.
int fn_1_D66A8(void) {
    return 0;
}
/* fzgx:end fn_1_D66A8 */

/* fzgx:begin fn_1_D66B0 */
// fn_1_D66B0: returns a constant.
int fn_1_D66B0(void) {
    return 0;
}
/* fzgx:end fn_1_D66B0 */

/* fzgx:begin fn_1_D66B8 */
// fn_1_D66B8: empty in retail (single blr).
void fn_1_D66B8(void) {
}
/* fzgx:end fn_1_D66B8 */

/* fzgx:begin fn_1_D66BC */
int fn_1_D66BC(void *unused, void *arg)
{
    fn_80008BA8(arg, lbl_1_data_3DC38, 0x10);
    return 1;
}
/* fzgx:end fn_1_D66BC */

/* fzgx:begin fn_1_D66F4 */
// fn_1_D66F4: empty in retail (single blr).
void fn_1_D66F4(void) {
}
/* fzgx:end fn_1_D66F4 */

/* fzgx:begin fn_1_D66F8 */
struct fn_1_D66F8_Arg1 {
    u8 unk_0;
};
struct fn_1_D66F8_Arg2 {
    u8 unk_0;
};
void fn_1_D66F8(u8 arg0, u8 *arg1, s8 *arg2) {
    u32 sp8;

    sp8 = lbl_1_rodata_6358;
    (*arg1) = *((((u8 *)(&sp8) + arg0)));
    (*arg2) = (lbl_801A66A0 / ((arg0 + 1) * 0x1E)) & 3;
}
/* fzgx:end fn_1_D66F8 */

/* fzgx:begin fn_1_D6740 */
// fn_1_D6740: returns a constant.
int fn_1_D6740(void) {
    return 1;
}
/* fzgx:end fn_1_D6740 */

/* fzgx:begin fn_1_D6748 */
typedef struct {
    f32 x, y, z;
} Vec3_D6748;

/* the 0xE8-byte record fn_1_58E3C copies into a free effect slot */
typedef struct {
    u8 pad_0[0xC];
    s16 unk_C;
    u8 pad_E[0xA];
    s16 unk_18;
    u16 unk_1A;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    u8 pad_2C[4];
    f32 unk_30;
    u8 pad_34[8];
    Vec3_D6748 unk_3C;
    Vec3_D6748 unk_48;
    u8 pad_54[0x1C];
    Vec3_D6748 unk_70;
    u8 pad_7C[0xC];
    Vec3_D6748 unk_88;
    Vec3_D6748 unk_94;
    u8 pad_A0[0xC];
    s16 unk_AC;
    u8 pad_AE[4];
    u16 unk_B2;
    u8 pad_B4[0x34];
} Desc_D6748;

extern s32 fn_1_66B8(void *arg0, f32 arg1);
extern s32 fn_1_58C4(void);
extern void fn_1_681C(u8 index, void *out);
extern u32 fn_1_584AC(void);
extern s16 fn_1_58E3C(void *source);
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D668(void *);
extern void *memset(void *dst, int value, u32 size);
extern u32 lbl_801A63C0;

/* one step of the executable's random generator, lbl_801A63C0 */
static inline s32 rand15_D6748(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

static inline f32 dist2_D6748(Vec3_D6748 *a, Vec3_D6748 *b) {
    f32 dx = a->x;
    f32 dy = a->y;
    f32 dz = a->z;

    dx -= b->x;
    dy -= b->y;
    dz -= b->z;
    dx *= dx;
    dx += dy * dy;
    dx += dz * dz;
    return dx;
}

/* distance from p to the nearest viewport camera (fn_1_58C4 viewports, fn_1_681C positions) */
static inline f32 nearest_camera_D6748(Vec3_D6748 *p) {
    Vec3_D6748 cam;
    u32 n;
    u32 i;
    f32 best;

    n = fn_1_58C4();
    fn_1_681C(0, &cam);
    best = lbl_8006D0B4(dist2_D6748(p, &cam));
    for (i = 1; i < n; i++) {
        fn_1_681C(i, &cam);
        best = best < lbl_8006D0B4(dist2_D6748(p, &cam)) ? best : lbl_8006D0B4(dist2_D6748(p, &cam));
    }
    return best;
}

void fn_1_D6748(Vec3_D6748 *a, Vec3_D6748 *b, s16 kind) {
    Desc_D6748 desc;
    f32 s;

    if (fn_1_66B8(a, 4.0f) == 0 && fn_1_66B8(b, 4.0f) == 0) {
        return;
    }
    if (nearest_camera_D6748(a) < 2000.0f || nearest_camera_D6748(b) < 2000.0f) {
        return;
    }
    memset(&desc, 0, 0xE8);
    desc.unk_18 = 0;
    desc.unk_C = 0x13;
    desc.unk_1A = 0xFFFF;
    desc.unk_88 = *a;
    desc.unk_94 = *b;
    desc.unk_3C = *b;
    {
        Vec3_D6748 zero = {0.0f, 0.0f, 0.0f};
        desc.unk_48 = zero;
    }
    /* the casts keep each product unfused: retail has fmul/fadd here, no fmadd */
    desc.unk_28 = 1.0 + (f64)(0.2 * (rand15_D6748() / 32767.0f - 0.5));
    desc.unk_30 = 1.0 + (f64)(0.2 * (rand15_D6748() / 32767.0f - 0.5));
    desc.unk_B2 = kind;
    s = 0.8f + (f32)(0.2f * ((u16)fn_1_584AC() / 32767.0f));
    desc.unk_1C = 255.0f * (0.5f * (1.0f + s)) / 255.0f;
    desc.unk_20 = 224.0f * s / 255.0f;
    desc.unk_24 = 176.0f * s / 255.0f;
    desc.unk_70.x = 0.8f * ((u16)fn_1_584AC() / 32767.0f - 0.5f);
    desc.unk_70.y = 0.8f * ((u16)fn_1_584AC() / 32767.0f - 0.5f);
    desc.unk_70.z = 0.8f * ((u16)fn_1_584AC() / 32767.0f - 0.5f);
    lbl_8006D668(&desc.unk_70);
    desc.unk_AC = 20;
    fn_1_58E3C(&desc);
}
/* fzgx:end fn_1_D6748 */

/* fzgx:begin fn_1_D6C10 */
#pragma section code_type ".fzgxpool"
static const unsigned long fzgx_pool_table1[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const unsigned long *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 4.0f;
    s = 2000.0f;
    d = 1.0;
    d = 0.2;
    s = 32767.0f;
}
static const unsigned long fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const unsigned long *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.800000011920929f;
    s = 0.20000000298023224f;
    s = 255.0f;
    s = 0.5f;
    s = 1.0f;
    s = 224.0f;
    s = 176.0f;
}
static const unsigned long fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const unsigned long *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 4503599627370496.0;
}
static const unsigned long fzgx_pool_table7[6] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const unsigned long *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
}
static const unsigned long fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const unsigned long *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0029999017715454f;
}
static const unsigned long fzgx_pool_table11[1] = {0xD2F1A9FC};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const unsigned long *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5625f;
}
static const unsigned long fzgx_pool_table13[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const unsigned long *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.140625f;
}
static const unsigned long fzgx_pool_table15[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const unsigned long *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 2.5f;
    s = 85.0f;
    s = 21.0f;
    s = 1.284999966621399f;
    s = 89128.9609375f;
    s = 0.07999999821186066f;
}
static const unsigned long fzgx_pool_table17[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const unsigned long *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 182.04444885253906;
    s = 1.9375f;
}
static const unsigned long fzgx_pool_table19[4] = {0x00000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const unsigned long *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
static inline Vec3 D6C10InitialVelocity(void) {
    Vec3 initialVelocity = { 0.0f, 0.0f, 0.0f };
    return initialVelocity;
}
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    Vec3 initialVelocity = D6C10InitialVelocity();
    const void *volatile cp = &initialVelocity; /* fzgx-allow: S2 pool primer sink */
}
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 20.0f;
}
static const unsigned long fzgx_pool_table24[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const unsigned long *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.09;
    d = 30.0;
    s = 10.0f;
    s = 1.5f;
    s = 0.019999999552965164f;
}
static const unsigned long fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const unsigned long *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.1;
    s = 221.0f;
}
static const unsigned long fzgx_pool_table28[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const unsigned long *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile double d;  /* fzgx-allow: S2 pool primer sink */
    d = 0.05;
}
#pragma section code_type ".text"
#pragma pool_data on

extern f32 lbl_8006D0B4(f32);
extern s16 fn_1_58E3C(void *);
extern s32 fn_1_58C4(void);
extern u32 fn_1_584AC(void);
extern s32 fn_1_66B8(void *, f32);

extern void * memset(void *, int, u32);
extern void fn_1_681C(u8 index, void *out);

typedef struct {
    u8 pad_0[0xC];
    u16 unk_C;
    u8 pad_E[2];
    s32 unk_10;
    u8 pad_14[4];
    u16 unk_18;
    u16 unk_1A;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    u8 pad_30[4];
    u32 unk_34;
    u8 pad_38[4];
    Vec3 unk_3C;
    Vec3 unk_48;
    u8 pad_54[0x34];
    f32 unk_88;
    f32 unk_8C;
    u8 pad_90[0x1C];
    s16 unk_AC;
    u8 pad_AE[4];
    u16 unk_B2;
    u8 pad_B4[0x34];
} ParticleD6C10;

static inline f32 D6C10Distance(Vec3 *a, f32 *b) {
    f32 dx = a->x;
    f32 dy = a->y;
    f32 dz = a->z;
    dx -= b[0];
    dy -= b[1];
    dz -= b[2];
    dx *= dx;
    dx += dy * dy;
    dx += dz * dz;
    return lbl_8006D0B4(dx);
}

static inline f32 D6C10NearestImpl(f32 best, Vec3 *a, f32 *b) {
    if (best < D6C10Distance(a, b)) return best;
    return D6C10Distance(a, b);
}
#define D6C10Nearest(best, a, b) D6C10NearestImpl(best, a, b)

void fn_1_D6C10(Vec3 *arg0, f32 arg1) {
    u32 v0;
    f32 v1;
    u32 v2;
    u32 v3;
    struct { f32 value; } v4;
    u32 v5;
    f64 v8;
    f32 v23;
    f32 v24;
    f32 v25;
    f32 v26;
    f32 v27;
    f32 v28;
    u32 v30;
    u32 v31;
    f32 v32;
    f32 v34;
    f32 v33;
    f32 v35;
    f32 v36;
    f32 v37;
    u32 v38;
    f32 coefficient;
    ParticleD6C10 loc_14;
    f32 loc_8[3];
    /* frame */
    u32 t0;
    s32 t1;
    f32 t3;
    f32 t5;
    f32 t6;
    void * t7;
    u32 t8;
    u32 t9;
    u32 t10;
    u32 t11;
    u32 t12;
    u32 t13;
    u32 t14;
    u32 t15;
    u32 t16;
    u32 t17;
    s16 t18;
    f32 fzgx_pool_f32_0 = 0.0199999996f;
    f32 fzgx_pool_f32_1 = 10.0f;
    /* Spawn one particle near the closest viewer. */
    v0 = lbl_801A66A0;
    v1 = arg1;
    v8 = arg1;
    if (v0 % 20 == 0) {
    v1 = (((20.0f) * arg1));
    t0 = fn_1_66B8(arg0, v1);
    v3 = t0;
    if ((s32)v3 != 0) {
    t1 = fn_1_58C4();
    v3 = t1;
    v2 = v3;
    v3 = 0;
    fn_1_681C(v3, loc_8);
    v4.value = D6C10Distance(arg0, loc_8);
    v5 = 1;
    while (v5 < v2) {
    v3 = (v5 & 0xFF);
    fn_1_681C(v3, loc_8);
    v4.value = D6C10Nearest(v4.value, arg0, loc_8);
    v5++;
    }
    if (v4.value > (800.0f)) return;
    {
    f64 v1;
    memset(&loc_14, 0, sizeof(loc_14));
    {
    struct { f64 value; } product;
    v1 = (0.089999999999999997);
    loc_14.unk_18 = 0;
    v1 = v1 * v8;
    product.value = v1;
    loc_14.unk_C = 13;
    v2 = 1;
    loc_14.unk_1A = (0x10000 - 1);
    coefficient = product.value;
    }
    v5 = 0x43300000;
    loc_14.unk_34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 360);
    while ((u8)v2 != 0) {
    loc_14.unk_3C = *arg0;
    t8 = fn_1_584AC();
    v3 = t8;
    v1 = (f32)((v3 & 0xFFFF));
    v1 = ((f32)v1 / (32767.0f));
    v1 = (f64)((v1) - ((0.5)));
    v1 = (f64)((f64)(fzgx_pool_f32_1) * (f64)(v1));
    loc_14.unk_3C.x = ((loc_14.unk_3C.x) + v1);
    t9 = fn_1_584AC();
    v3 = t9;
    v1 = (f32)((v3 & 0xFFFF));
    v1 = ((f32)v1 / (32767.0f));
    v1 = (f64)((v1) - ((0.5)));
    v1 = (f64)((f64)(fzgx_pool_f32_1) * (f64)(v1));
    loc_14.unk_3C.y = ((loc_14.unk_3C.y) + v1);
    t10 = fn_1_584AC();
    v3 = t10;
    v1 = (f32)(v3 & 0xFFFF);
    {
    loc_14.unk_48 = D6C10InitialVelocity();
    }
    v1 = ((f32)v1 / (32767.0f));
    v1 = (f64)((v1) - ((0.5)));
    v1 = (f64)((f64)(fzgx_pool_f32_1) * (f64)(v1));
    loc_14.unk_3C.z = ((loc_14.unk_3C.z) + v1);
    t11 = fn_1_584AC();
    v3 = t11;
    v32 = (v3 & 0xFFFF) / (32767.0f);
    v32 = (0.5f) * v32;
    v32 = (1.5f) + v32;
    v32 = (60.0f) * v32;
    loc_14.unk_10 = v32;
    t12 = fn_1_584AC();
    v3 = t12;
    v1 = (f32)((v3 & 0xFFFF));
    v1 = ((f32)v1 / (32767.0f));
    v1 = (f64)((v1) - ((0.5)));
    v1 = (f64)((f64)(fzgx_pool_f32_0) * (f64)(v1));
    loc_14.unk_48.x = ((loc_14.unk_48.x) + v1);
    t13 = fn_1_584AC();
    v3 = t13;
    v1 = (f32)((v3 & 0xFFFF));
    v1 = ((f32)v1 / (32767.0f));
    v1 = (f64)((v1) - ((0.5)));
    v1 = (f64)((f64)(fzgx_pool_f32_0) * (f64)(v1));
    loc_14.unk_48.z = ((loc_14.unk_48.z) + v1);
    t14 = fn_1_584AC();
    {
    v1 = (t14 & 0xFFFF) / 32767.0f;
    loc_14.unk_B2 = 14;
    loc_14.unk_3C.x -= loc_14.unk_48.x;
    loc_14.unk_48.y += (0.10000000000000001) + (coefficient * (f32)v1);
    loc_14.unk_28 = v8;
    loc_14.unk_2C = ((30.0) * v8);
    }
    loc_14.unk_3C.y -= loc_14.unk_48.y;
    loc_14.unk_3C.z -= loc_14.unk_48.z;
    t15 = fn_1_584AC();
    v3 = t15;
    v36 = (v3 & 0xFFFF) / (32767.0f);
    v36 = (0.200000003f) * v36;
    v36 = (0.800000012f) + v36;
    loc_14.unk_1C = ((221.0f) * ((0.5f) * ((1.0f) + v36))) / (255.0f);
    loc_14.unk_20 = ((221.0f) * v36) / (255.0f);
    loc_14.unk_24 = ((255.0f) * v36) / (255.0f);
    t16 = fn_1_584AC();
    v3 = t16;
    loc_14.unk_8C = (0.200000003f);
    v1 = (((0.02)) * (((v3 & 0xFFFF) / (32767.0f))));
    loc_14.unk_88 = (((0.050000000000000003)) + v1);
    t17 = fn_1_584AC();
    v3 = t17;
    v38 = (v3 & 0xFFFF);
    v1 = (((v38 / (32767.0f))) - ((0.5)));
    loc_14.unk_AC = (((182.04444885253906)) * v1);
    t18 = fn_1_58E3C(&loc_14);
    v3 = t18;
    v2--;
    }
    }
    }
    }
}
/* fzgx:end fn_1_D6C10 */
