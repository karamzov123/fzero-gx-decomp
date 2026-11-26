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
VERT(pos->x+(((lo) + 0x80000000)) *width/25165824.0f , pos->y, pos->z-depth);
VERT(pos->x+(((hi) + 0x80000000)) *width/25165824.0f , pos->y, pos->z-depth);
VERT(pos->x+(((hi) + 0x80000000)) *width/25165824.0f , pos->y+height, pos->z-depth);
VERT(pos->x+(((lo) + 0x80000000)) *width/25165824.0f , pos->y+height, pos->z-depth);
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
