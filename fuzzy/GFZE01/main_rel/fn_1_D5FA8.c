/* Non-matching: best partial attempt (49.03% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct Sig_fn_800371F8_GXColor { u8 r, g, b, a; } Sig_fn_800371F8_GXColor;
struct fn_1_D5FA8_lbl_1_rodata_6328 {
    u32 c0, c1, c2, c3, c4, c5;
    u32 c6, c7, c8, c9, c10, c11;
    f32 one, scale;
    f32 step;
    f32 integer_bias;
    f64 uint_bias;
};
typedef struct Vec3 { f32 x, y, z; } Vec3;
typedef struct Node { struct Node *next; struct Node *next2; struct Node *children; } Node;

extern s32 * fn_8000961C(s32);
extern u32 OSGetArenaHi(void);
extern void * OSGetArenaLo(void);
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
extern void fn_800371F8(s32, Sig_fn_800371F8_GXColor);
extern void fn_8003462C(u32, u32, u32);
extern u32 lbl_801A66C8;
extern struct fn_1_D5FA8_lbl_1_rodata_6328 lbl_1_rodata_6328;

void fn_1_D5FA8(s32 arg0, Vec3 *v, f32 dx, f32 dy) {
    struct fn_1_D5FA8_lbl_1_rodata_6328 *p = (struct fn_1_D5FA8_lbl_1_rodata_6328 *)&lbl_1_rodata_6328;
    s32 *found;
    u32 lo;
    u32 hi;
    Sig_fn_800371F8_GXColor color;
    Node *node;
    Node *list;
    u32 count, i, q;
    f32 xstep, ystep;
    volatile f32 *fifo = (volatile f32 *)0xCC008000;
    found = fn_8000961C(arg0);
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
    color.r = p->c0 >> 24; color.g = p->c0 >> 16; color.b = p->c0 >> 8; color.a = p->c0;
    fn_800371F8(1, color);
    fn_8003462C(128, 7, 4);
    *fifo = v->x; *fifo = v->y; *fifo = v->z;
    *fifo = v->x + dx; *fifo = v->y; *fifo = v->z;
    *fifo = v->x + dx; *fifo = v->y + dy; *fifo = v->z;
    *fifo = v->x; *fifo = v->y + dy; *fifo = v->z;
    v->x += p->one;
    v->y += p->one;
    color.r = p->c1 >> 24; color.g = p->c1 >> 16; color.b = p->c1 >> 8; color.a = p->c1;
    fn_800371F8(1, color);
    fn_8003462C(128, 7, 4);
    *fifo = v->x; *fifo = v->y; *fifo = v->z - p->scale;
    *fifo = v->x + dx; *fifo = v->y; *fifo = v->z - p->scale;
    *fifo = v->x + dx; *fifo = v->y + dy; *fifo = v->z - p->scale;
    *fifo = v->x; *fifo = v->y + dy; *fifo = v->z - p->scale;
    color.r = p->c2 >> 24; color.g = p->c2 >> 16; color.b = p->c2 >> 8; color.a = p->c2;
    fn_800371F8(1, color);
    fn_8003462C(128, 7, 4);
    xstep = ((f32)lo * dx) / p->integer_bias;
    ystep = ((f32)hi * dx) / p->integer_bias;
    *fifo = v->x + xstep; *fifo = v->y; *fifo = v->z - p->step;
    *fifo = v->x + ystep; *fifo = v->y; *fifo = v->z - p->step;
    *fifo = v->x + ystep; *fifo = v->y + dy; *fifo = v->z - p->step;
    *fifo = v->x + xstep; *fifo = v->y + dy; *fifo = v->z - p->step;
    if (found != 0) {
        for (node = (Node *)found[2]; node != 0; node = node->next2) {
            color.r = p->c3 >> 24; color.g = p->c3 >> 16; color.b = p->c3 >> 8; color.a = p->c3;
            fn_800371F8(1, color);
            fn_8003462C(128, 7, 4);
            q = (u32)node;
            *fifo = v->x + ((f32)q * dx) / p->integer_bias;
            *fifo = v->y;
            *fifo = v->z - p->step;
            *fifo = v->x + ((f32)(q + (u32)node->children) * dx) / p->integer_bias;
            *fifo = v->y;
            *fifo = v->z - p->step;
            *fifo = v->x + ((f32)(q + (u32)node->children) * dx) / p->integer_bias;
            *fifo = v->y + dy;
            *fifo = v->z - p->step;
            *fifo = v->x + ((f32)q * dx) / p->integer_bias;
            *fifo = v->y + dy;
            *fifo = v->z - p->step;
        }
        list = (Node *)found[1];
        count = 0;
        for (node = list; node != 0; node = node->next2) count++;
        for (node = list, i = 0; node != 0; node = node->next2, i++) {
            color.r = p->c4 >> 24; color.g = p->c4 >> 16; color.b = p->c4 >> 8; color.a = p->c4;
            fn_800371F8(1, color);
            if (node->next2 != 0 && ((lbl_801A66C8 >> 7) % count) == i) {
                color.r = p->c5 >> 24; color.g = p->c5 >> 16; color.b = p->c5 >> 8; color.a = p->c5;
                fn_800371F8(1, color);
            }
            fn_8003462C(128, 7, 4);
            q = (u32)node;
            *fifo = v->x + ((f32)q * dx) / p->step;
            *fifo = v->y;
            *fifo = v->z - p->integer_bias;
            *fifo = v->x + ((f32)(q + (u32)node->children) * dx) / p->step;
            *fifo = v->y;
            *fifo = v->z - p->integer_bias;
            *fifo = v->x + ((f32)(q + (u32)node->children) * dx) / p->step;
            *fifo = v->y + dy;
            *fifo = v->z - p->integer_bias;
            *fifo = v->x + ((f32)q * dx) / p->step;
            *fifo = v->y + dy;
            *fifo = v->z - p->integer_bias;
        }
    }
}
