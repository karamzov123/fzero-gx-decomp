/* Non-matching: best partial attempt (49.40% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct { u32 x, y, z; } Triple;
typedef struct { f32 x, y, z; } Vec3;
typedef struct {
    u8 pad0[0x18]; s16 mode;
    u8 pad1[0x1c]; /* through 0x37 */
} Effect;
typedef struct {
    u8 pad0[0x20]; f64 two52;
    f32 one;
    u8 pad2c[0x14]; f64 onehalf;
    u8 pad48[8]; f32 zero, half;
    u8 pad58[4]; f32 scale255;
    u8 pad60[0x40]; f32 two;
    u8 padA4[0xAC]; f32 rootHalf;
    u8 pad154[4]; f64 zero64, max255, point9;
} Pool;
extern Pool lbl_1_rodata_2950;
extern void fn_1_862D4(int, Triple *);
extern u8 fn_1_5910(void);
extern u32 fn_1_6EC0(u8);
extern s16 camera_get_mode(void);
extern int fn_1_9F914(const void *, const void *);
extern void lbl_8006DC6C(void *);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006DCA4(void);
extern void *memset(void *, int, u32);
extern void lbl_8006E0A4(void *);
extern void lbl_8006D7B0(void);
extern f32 lbl_8006D0B4(f32);
extern void fn_8006EDBC(Vec3 *, Vec3 *, s16 *, s16 *);
extern void lbl_8006D7DC(void *);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern void lbl_8006E15C(f32, f32, f32);
extern void fn_8006E294(Vec3 *);
extern void lbl_8006D24C(f32, f32);
extern void lbl_8006DB74(void *);

void fn_1_5CA00(Effect *self) {
    Pool *pool = (Pool *)&lbl_1_rodata_2950;
    Triple triple;
    Vec3 a, b;
    Vec3 trans;
    f32 direction[3];
    struct { u8 pad[0x38]; u8 color[4]; u8 tail[4]; } packet;
    u32 effectId;
    s32 mode;
    s32 i;
    f32 radius, dx, dy, angle, limit;
    f32 factor = *(f32 *)((u8 *)self + 0x28);
    fn_1_862D4(self->mode, &triple);
    effectId = *(u32 *)((u8 *)self + 0x34);
    lbl_8006DC6C((u8 *)self + 0xb8);
    *(f32 *)0xE000000C = *(f32 *)&triple.x;
    *(f32 *)0xE000001C = *(f32 *)&triple.y;
    *(f32 *)0xE000002C = *(f32 *)&triple.z;
    lbl_8006E1B0((u8 *)self + 0x3c, &a);
    lbl_8006E1B0((u8 *)self + 0x94, &b);
    lbl_8006DCA4();
    lbl_8006E1B0(&a, &a);
    lbl_8006E1B0(&b, &b);
    if (fn_1_6EC0(fn_1_5910()) != 0 && camera_get_mode() == self->mode)
        mode = 1;
    else if (fn_1_6EC0(fn_1_5910()) != 0)
        mode = 2;
    else
        mode = 3;
    memset(&packet, 0, 0x40);
    *(f32 *)&packet = pool->rootHalf * factor;
    packet.pad[0x30] |= 2;
    packet.color[0] = (u8)(pool->scale255 * *(f32 *)((u8 *)self + 0x1c));
    packet.color[1] = (u8)(pool->scale255 * *(f32 *)((u8 *)self + 0x20));
    packet.color[2] = (u8)(pool->scale255 * *(f32 *)((u8 *)self + 0x24));
    packet.color[3] = 255;
    if (mode == 1) {
        packet.color[0] = (u8)(pool->onehalf * packet.color[0]);
        packet.color[1] = (u8)(pool->onehalf * packet.color[1]);
        packet.color[2] = (u8)(pool->onehalf * packet.color[2]);
    } else {
        packet.color[0] = (u8)(pool->onehalf * packet.color[0]);
        packet.color[1] = (u8)(pool->onehalf * packet.color[1]);
        packet.color[2] = (u8)(pool->onehalf * packet.color[2]);
    }
    for (i = mode; i != 0; i--) {
        radius = *(f32 *)((u8 *)self + 0xb4);
        switch (i) {
        case 1:
            if (mode == 1)
                a.y += pool->two * radius;
            else { a.x -= pool->two * radius; b.x -= pool->two * radius; }
            break;
        case 2:
            a.y -= pool->two * radius; b.y -= pool->two * radius;
            break;
        case 3:
            a.x += pool->two * radius; b.x += pool->two * radius;
            break;
        case 4:
            a.x -= radius; a.y += radius; b.x -= radius; b.y += radius;
            break;
        }
        dx = a.x - b.x; dy = a.y - b.y;
        direction[0] = dx; direction[1] = dy;
        if (pool->zero == dx && pool->zero == dy) {
            lbl_8006E0A4((u8 *)self + 0x3c);
            lbl_8006D7B0();
        } else {
            trans.x = pool->half * (a.x + b.x);
            trans.y = pool->half * (a.y + b.y);
            trans.z = pool->half * (a.z + b.z);
            angle = (f32)(pool->point9 * lbl_8006D0B4((a.x-b.x)*(a.x-b.x) +
                    (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z)));
            fn_8006EDBC(&a, &b, (s16 *)&direction[2], (s16 *)&direction[1]);
            lbl_8006D7DC(&trans);
            mathutil_mtxA_rotate_y(*(s16 *)&direction[1]);
            mathutil_mtxA_rotate_x(*(s16 *)&direction[2]);
            lbl_8006E15C(pool->one, pool->one, angle / factor);
            mathutil_mtxA_rotate_x(0x4000);
            fn_8006E294((Vec3 *)direction);
            lbl_8006D24C(direction[0], direction[2]);
            mathutil_mtxA_rotate_y(0);
        }
        lbl_8006DB74(&packet);
        limit = *(f32 *)&packet * pool->half;
        if (limit > *(f32 *)((u8 *)&packet + 4))
            *(f32 *)((u8 *)&packet + 4) = limit;
        else
            *(f32 *)((u8 *)&packet + 4) = *(f32 *)((u8 *)&packet + 4);
        fn_1_9F914(&packet, (void *)effectId);
    }
}
