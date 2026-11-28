#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/background.h"

extern void GXPeekZ(u32, u32, void *);
extern void GXPokeAlphaRead(u32);
extern void fn_8003432C(u32, u32, u32 *);

extern Obj_1_bss_6EA80_Target *lbl_1_bss_6EA80;
extern u32 lbl_1_bss_6EA84;



__declspec(section ".data") u32 lbl_1_bss_6EA84 __attribute__((aligned(4)));



__declspec(section ".data") Obj_1_bss_6EA80_Target *lbl_1_bss_6EA80 __attribute__((aligned(32)));

/* fzgx:begin fn_1_9E14C */
f32 fn_1_9E14C(s32 count, BackgroundCurveKey *keys, f32 t) {
    return fn_1_9DDA8(count, keys, 0, t);
}
/* fzgx:end fn_1_9E14C */

/* fzgx:begin fn_1_9E170 */
f32 fn_1_9E170(s32 count, const BackgroundCurveKey *keys, s32 *cursor, f32 t) {
    return fn_1_9DFB8(count, keys, cursor, 0, t);
}
/* fzgx:end fn_1_9E170 */

/* fzgx:begin fn_1_9E194 */
f32 fn_1_9E194(s32 count, BackgroundCurveKey *keys, f32 t) {
    return fn_1_9DDA8(count, keys, 1, t);
}
/* fzgx:end fn_1_9E194 */

/* fzgx:begin fn_1_9E1B8 */
void fn_1_9E1B8(void) {
    lbl_1_bss_6EA80 = 0;
    lbl_1_bss_6EA84 = (u32)&lbl_1_bss_6EA80;
}
/* fzgx:end fn_1_9E1B8 */

/* fzgx:begin fn_1_9E1D0 */
typedef struct {
    s16 unk_0;
    s16 unk_2;
    u32 unk_4;
    u8 unk_8;
} Fn_1_9E1D0_Entry;

typedef struct Fn_1_9E1D0_Node {
    struct Fn_1_9E1D0_Node *unk_0;
    s32 unk_4;
    Fn_1_9E1D0_Entry *unk_8;
} Fn_1_9E1D0_Node;

void fn_1_9E1D0(void) {
    s32 count;
    Fn_1_9E1D0_Node *node;
    Fn_1_9E1D0_Entry *entry;
    u32 result;

    node = (Fn_1_9E1D0_Node *)lbl_1_bss_6EA80;
    while (node != 0) {
        entry = node->unk_8;
        count = node->unk_4;
        while (count > 0) {
            if (entry->unk_4 == 0) {
                GXPeekZ((u16)entry->unk_0, (u16)entry->unk_2, &entry->unk_4);
                GXPokeAlphaRead(2);
                fn_8003432C((u16)entry->unk_0, (u16)entry->unk_2, &result);
                entry->unk_8 = (result >> 24);
            }
            count--;
            entry++;
        }
        node = node->unk_0;
    }
    lbl_1_bss_6EA80 = 0;
    lbl_1_bss_6EA84 = (u32)&lbl_1_bss_6EA80;
}
/* fzgx:end fn_1_9E1D0 */

/* fzgx:begin fn_1_9E29C */
typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    s16 x;
    s16 y;
    u32 flags;
    u32 pad;
} ScreenPoint;

extern void GXGetProjectionv(f32 *);
extern void fn_80038F10(f32 *);

/* Projects camera-space points to clamped screen coordinates. */
#pragma push
void fn_1_9E29C(s32 count, Vec3f *src, ScreenPoint *dst) {
    Vec3f p;
    f32 proj[7];
    f32 vp[6];
    f32 halfW, halfH;
    f32 dxmax, dymax, cx, cy, xmax, ymax;
    f32 nx, ny;
    f32 t;
    s32 i;

    GXGetProjectionv(proj);
    fn_80038F10(vp);
    halfW = 0.5f * vp[2];
    halfH = 0.5f * vp[3];
    cx = vp[0] + halfW;
    cy = vp[1] + halfH;
    xmax = (vp[0] + vp[2]) - 1.0f;
    ymax = (vp[1] + vp[3]) - 1.0f;
    dxmax = xmax - cx;
    dymax = ymax - cy;

    for (i = 0; i < count; i++) {
        p = src[i];
        dst[i].flags = 0x1000000;
        if (p.z < 0.0f) {
            t = 1.0f / p.z;
            ny = proj[4] + t * (p.y * proj[3]);
            nx = proj[2] + t * (p.x * proj[1]);
            nx = 0.5f * (1.0f + nx);
            p.x = vp[0] + vp[2] * (1.0f - nx);
            p.y = vp[1] + vp[3] * (0.5f * (1.0f + ny));
            if (p.x < vp[0]) {
                t = (vp[0] - cx) / (p.x - cx);
                p.x = vp[0];
                p.y = cy + t * (p.y - cy);
            } else if (p.x > xmax) {
                t = dxmax / (p.x - cx);
                p.x = xmax;
                p.y = cy + t * (p.y - cy);
            }
            if (p.y < vp[1]) {
                t = (vp[1] - cy) / (p.y - cy);
                p.y = vp[1];
                p.x = cx + t * (p.x - cx);
            } else if (p.y > ymax) {
                t = dymax / (p.y - cy);
                p.y = ymax;
                p.x = cx + t * (p.x - cx);
            }
            dst[i].x = p.x;
            dst[i].y = p.y;
            dst[i].flags = 0;
        }
    }
}
#pragma pop
/* fzgx:end fn_1_9E29C */

/* fzgx:begin fn_1_9E514 */
extern f32 lbl_1_rodata_42C0[4];
extern void GXGetProjectionv(f32 *);
extern u32 __cvt_fp2unsigned(f32);

typedef struct {
    u8 unk_00[0x14];
    f32 unk_14;
    f32 unk_18;
} Fn_1_9E514_Data;

s32 fn_1_9E514(f32 arg0) {
    Fn_1_9E514_Data data;
    f32 *table = (f32 *)&lbl_1_rodata_42C0;
    f32 prod;
    f32 value;

    GXGetProjectionv((f32 *)&data);
    prod = data.unk_14 * arg0;
    value = data.unk_18 + prod;
    value /= arg0;
    value = (table[1] - value) * table[3];
    if (value < table[2]) {
        return 0;
    }
    return __cvt_fp2unsigned(value);
}
/* fzgx:end fn_1_9E514 */

/* fzgx:begin fn_1_9E598 */
typedef struct Node Node;
struct Node {
    Node *next;
};

// Append a node to the linked-list tail and terminate the new tail.
void fn_1_9E598(Node *node) {
    Node *tail;

    tail = *(Node **)&lbl_1_bss_6EA84;
    tail->next = node;
    node->next = 0;
    lbl_1_bss_6EA84 = (u32)node;
}
/* fzgx:end fn_1_9E598 */

/* fzgx:begin fn_1_9E5B8 */
// Removes a node from the background-node chain and updates its tail link.
void fn_1_9E5B8(Obj_1_bss_6EA80_Target *node) {
    u32 *link;

    link = (u32 *)&lbl_1_bss_6EA80;
    while (*link != 0 && *link != (u32)node) {
        link = (u32 *)*link;
    }
    if (*link == 0) {
        return;
    }
    *link = node->unk_0;
    if (lbl_1_bss_6EA84 == (u32)node) {
        lbl_1_bss_6EA84 = (u32)link;
    }
}
/* fzgx:end fn_1_9E5B8 */

/* fzgx:begin fn_1_9E608 */
#include "dolphin/hw_regs.h"
#include "dolphin/hw_regs.h"

/* begin game/main_rel/background_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_BACKGROUND_TYPES_H
#define GAME_MAIN_REL_BACKGROUND_TYPES_H

// Types (and the externs that name them) of background.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct {
    s32 type;     /* 0: constant, 1: linear, else: hermite */
    f32 time;
    f32 value;
    f32 tanIn;
    f32 tanOut;
} CurveKey;


#endif  // GAME_MAIN_REL_BACKGROUND_TYPES_H

/* end game/main_rel/background_types.h */

typedef struct {
    u8 r, g, b, a;
} BgColor;

typedef struct {
    u8 unk_0[0xC];
    f32 size;
    s16 rotZ;
    u16 flags;
    BgColor color;
} BgSprite;

extern u32 lbl_801A6D00;
extern s32 fn_1_54E34(void *arg0, f32 arg1);
extern void fn_800724C8(void);
extern void fn_8007245C(u32 value);
extern void lbl_8006DAEC(void);
extern void lbl_8006D758(void);
extern u32 GXLoadPosMtxImm(u32, u32);
extern void lbl_8006DB30(void);
/* The color is passed by value: MWCC copies it to the stack and passes the copy's address. */
extern void fn_800736C0();
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern void lbl_8006E1D8(void *, f32, f32, f32);
extern void mathutil_mtxA_rotate_z(s32);
extern void lbl_8006E0A4(void *);
extern u32 lbl_8006D7B0(void);

/* GX write-gather FIFO: every store is a hardware write, so it must not be merged or dropped. */
#define BG_FIFO (*(volatile f32 *)GX_FIFO_BASE)

void fn_1_9E608(s32 count, BgSprite *list) {
    BgSprite *sprites;
    s32 remaining;
    f32 v[4][3];
    BgColor col;
    s32 i;
    BgSprite *start;
    BgSprite *last;
    BgSprite *s;
    s32 visible;
    s32 n;
    f32 neg;
    f32 size;

    s = list;
    visible = 0;
    for (i = count; i > 0; i--, s++) {
        if (fn_1_54E34(s, s->size) != 0) {
            visible++;
            s->flags &= ~1;
        } else {
            s->flags |= 1;
        }
    }
    if (visible == 0) {
        return;
    }

    fn_800724C8();
    fn_8007245C(0x2200);
    lbl_8006DAEC();
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    lbl_8006DB30();

    sprites = list;
    remaining = count;
    while (remaining > 0) {
        while (remaining > 0) {
            if (!(sprites->flags & 1)) {
                break;
            }
            remaining--;
            sprites++;
        }
        if (remaining == 0) {
            return;
        }
        col = sprites->color;
        fn_800736C0(0, col);
        fn_8003462C(0x90, 0, 8);
        start = sprites;
        remaining--;
        sprites++;
        for (i = 0; i < 8; i++) {
            BG_FIFO = 0.0f;
            BG_FIFO = 0.0f;
            BG_FIFO = 0.0f;
            BG_FIFO = 0.0f;
            BG_FIFO = 0.0f;
        }
        n = 1;
        while (remaining > 0) {
            if (!(sprites->flags & 1)) {
                if (col.r != sprites->color.r || col.g != sprites->color.g ||
                    col.b != sprites->color.b || col.a != sprites->color.a) {
                    remaining++;
                    last = sprites - 1;
                    break;
                }
                n++;
            }
            remaining--;
            sprites++;
        }
        fn_8003462C(0x80, 0, (u16)(n * 4));
        sprites = start;
        while (n > 0) {
            if (!(sprites->flags & 1)) {
                size = sprites->size;
                neg = -size;
                lbl_8006DAEC();
                lbl_8006E0A4(sprites);
                lbl_8006D7B0();
                if (sprites->rotZ != 0) {
                    mathutil_mtxA_rotate_z(sprites->rotZ);
                }
                lbl_8006E1D8(v[0], neg, neg, 0.0f);
                lbl_8006E1D8(v[1], size, neg, 0.0f);
                lbl_8006E1D8(v[2], size, size, 0.0f);
                lbl_8006E1D8(v[3], neg, size, 0.0f);
                lbl_8006DB30();
                n--;
                BG_FIFO = v[0][0];
                BG_FIFO = v[0][1];
                BG_FIFO = v[0][2];
                BG_FIFO = 0.0f;
                BG_FIFO = 0.0f;
                BG_FIFO = v[1][0];
                BG_FIFO = v[1][1];
                BG_FIFO = v[1][2];
                BG_FIFO = 1.0f;
                BG_FIFO = 0.0f;
                BG_FIFO = v[2][0];
                BG_FIFO = v[2][1];
                BG_FIFO = v[2][2];
                BG_FIFO = 1.0f;
                BG_FIFO = 1.0f;
                BG_FIFO = v[3][0];
                BG_FIFO = v[3][1];
                BG_FIFO = v[3][2];
                BG_FIFO = 0.0f;
                BG_FIFO = 1.0f;
            }
            sprites++;
        }
        remaining--;
        sprites = last + 1;
    }
}
/* fzgx:end fn_1_9E608 */

/* fzgx:begin fn_1_9EA94 */
typedef struct {
    u8 pad_0[0xC];
    f32 unk_C;
    s16 unk_10;
    u16 unk_12;
    u32 unk_14;
} Obj_1_9EA94_Target;

extern f32 lbl_1_rodata_42D0;
extern f32 lbl_1_rodata_42D4;
extern s32 fn_1_54E34(void *, f32);
extern void fn_800724C8(void);
extern void fn_8007245C(u32);
extern void lbl_8006DAEC(void);
extern void lbl_8006D758(void);
extern u32 GXLoadPosMtxImm(u32, u32);
extern u32 lbl_801A6D00;
extern void lbl_8006DB30(void);
extern void fn_800736C0();
extern void fn_8003462C(u32, u32, u32);
extern void lbl_8006E0A4(void *);
extern void mathutil_mtxA_rotate_z(s32);
extern void lbl_8006E1D8(void *, f32, f32, f32);

#pragma opt_propagation off
void fn_1_9EA94(Obj_1_9EA94_Target *arg0) {
    u32 v0;
    f32 v3;
    f32 v2;
    void * lab_t0_2;
    f32 loc_30[3];
    f32 loc_24[3];
    f32 loc_18[3];
    f32 loc_C[3];
    u32 loc_8;
    void * lab_t0;

    if (fn_1_54E34(arg0, arg0->unk_C) == 0) {
        arg0->unk_12 |= 1;
        return;
    }
    arg0->unk_12 &= 0xFFFE;
    fn_800724C8();
    fn_8007245C(0x2200);
    lbl_8006DAEC();
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    lbl_8006DB30();
    loc_8 = arg0->unk_14;
    fn_800736C0(0, &loc_8);
    fn_8003462C(0x90, 0, 8);
    v0 = 0x80;
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    fn_8003462C(v0, 0, 4);
    v2 = arg0->unk_C;
    v3 = -v2;
    lbl_8006DAEC();
    lbl_8006E0A4(arg0);
    if (arg0->unk_10 != 0) {
        mathutil_mtxA_rotate_z(arg0->unk_10);
    }
    lbl_8006E1D8((lab_t0 = loc_C), v3, v3, lbl_1_rodata_42D0);
    lab_t0 = loc_18;
    lbl_8006E1D8(lab_t0, v2, v3, lbl_1_rodata_42D0);
    lab_t0_2 = loc_24;
    lbl_8006E1D8(lab_t0_2, v2, v2, lbl_1_rodata_42D0);
    lab_t0_2 = loc_30;
    lbl_8006E1D8(lab_t0_2, v3, v2, lbl_1_rodata_42D0);
    lbl_8006DB30();
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = loc_C[0];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = loc_C[1];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = loc_C[2];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = loc_18[0];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = loc_18[1];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = loc_18[2];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D4;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = loc_24[0];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = loc_24[1];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = loc_24[2];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D4;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D4;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = loc_30[0];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = loc_30[1];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = loc_30[2];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D4;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
}
#pragma opt_propagation reset
/* fzgx:end fn_1_9EA94 */

/* fzgx:begin fn_1_9EDE8 */
typedef volatile const f32 OrderedFifoConst; /* Reload before each ordered FIFO write. */
#include "dolphin/hw_regs.h"
#include "types.h"
#include "dolphin/types.h"

extern f32 lbl_1_rodata_42D0;
extern f32 lbl_1_rodata_42D4;
extern u32 lbl_801A6D00;
extern s32 fn_1_54E34(void *, f32);
extern void fn_800724C8(void);
extern void fn_8007245C(u32);
extern void lbl_8006DAEC(void);
extern void lbl_8006D758(void);
extern u32 GXLoadPosMtxImm(u32, u32);
extern void lbl_8006DB30(void);
extern void fn_800736C0();
extern void fn_8003462C(u32, u32, u32);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E1D8(void *, f32, f32, f32);

extern vu32 __DIRegs[];

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

#include "rel/main_rel/background.h"

/* fzgx-allow: A1 GX FIFO write port; retail materialises it as lis 0xcc01/stfs -0x8000 */
#define FIFO(v) (*(volatile f32 *)(GX_FIFO_BASE + 0x0) = (v)) /* Hardware access must remain ordered. */

void fn_1_9EDE8(BackgroundQuad *arg0) {
    Vec3 pos;
    u32 z;
    Vec3 vtx[4];
    f32 radius;
    struct { f32 value; } neg;

    pos.x = arg0->mtx[0][3];
    pos.y = arg0->mtx[1][3];
    pos.z = arg0->mtx[2][3];
    if (arg0->flags & 2) {
        radius = arg0->height;
    } else {
        radius = arg0->width;
    }
    if (!(arg0->flags & 4) && fn_1_54E34(&pos, radius) == 0) {
        arg0->flags |= 1;
        return;
    }
    arg0->flags &= ~1;
    fn_800724C8();
    fn_8007245C(0x2200);
    lbl_8006DAEC();
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    lbl_8006DB30();
    z = arg0->color.word;
    fn_800736C0(0, &z);
    fn_8003462C(0x90, 0, 8);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    fn_8003462C(0x80, 0, 4);
    radius = *(f32 *)arg0;
    neg.value = -radius;
    lbl_8006DAEC();
    lbl_8006DFC4((void *)((u8 *)arg0 + 8));
    lbl_8006E1D8((void *)&vtx[0], neg.value, neg.value, *(OrderedFifoConst *)&lbl_1_rodata_42D0);
    lbl_8006E1D8((void *)&vtx[1], radius, neg.value, *(OrderedFifoConst *)&lbl_1_rodata_42D0);
    lbl_8006E1D8((void *)&vtx[2], radius, radius, *(OrderedFifoConst *)&lbl_1_rodata_42D0);
    lbl_8006E1D8((void *)&vtx[3], neg.value, radius, *(OrderedFifoConst *)&lbl_1_rodata_42D0);
    lbl_8006DB30();
    FIFO(vtx[0].x);
    FIFO(vtx[0].y);
    FIFO(vtx[0].z);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(vtx[1].x);
    FIFO(vtx[1].y);
    FIFO(vtx[1].z);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D4);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(vtx[2].x);
    FIFO(vtx[2].y);
    FIFO(vtx[2].z);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D4);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D4);
    FIFO(vtx[3].x);
    FIFO(vtx[3].y);
    FIFO(vtx[3].z);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D0);
    FIFO(*(OrderedFifoConst *)&lbl_1_rodata_42D4);
}
/* fzgx:end fn_1_9EDE8 */

/* fzgx:begin fn_1_9F164 */
typedef struct { f32 x, y, z, w; } Vec4;

struct fn_1_9F164_Arg0 {
    f32 unk_0;
    f32 unk_4;
    Vec4 unk_8[3];
    u32 unk_38;
    u32 unk_3C;
};

#define XF_PUT(v) (*(volatile f32 *)0xCC008000 = (f32)(v)) /* fzgx-allow: A1,A2 unnamed OS/hardware memory */

extern f32 lbl_1_rodata_42D0;
extern f32 lbl_1_rodata_42D4;
extern s32 fn_1_54E34(void *, f32);
extern void fn_800736C0();
extern void fn_8003462C(u32, u32, u32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E1D8(void *, f32, f32, f32);
extern void lbl_8006DB30(void);

#pragma opt_propagation off
void fn_1_9F164(struct fn_1_9F164_Arg0 *arg0, f32 arg1) {
    u32 v0;
    f32 v1;
    f32 v5;
    f32 v4;
    f32 loc_3C[3];
    f32 loc_30[3];
    f32 loc_24[3];
    f32 loc_18[3];
    f32 loc_C[3];
    u32 loc_8;
    void * lab_t0;
    loc_C[0] = arg0->unk_8[0].w;
    loc_C[1] = arg0->unk_8[1].w;
    loc_C[2] = arg0->unk_8[2].w;
    v0 = arg0->unk_38;
    if ((v0 & 0x2) != 0) {
        v1 = arg0->unk_4;
    } else {
        v1 = arg0->unk_0;
    }
    if ((v0 & 0x4) == 0 && fn_1_54E34(loc_C, v1) == 0) {
        arg0->unk_38 |= 1;
    } else {
        arg0->unk_38 &= ~1;
        loc_8 = arg0->unk_3C;
        fn_800736C0(0, &loc_8);
        fn_8003462C(0x90, 0, 8);
        XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0);
        fn_8003462C(0x80, 0, 4);
        v4 = arg0->unk_0;
        v5 = -v4;
        lbl_8006DAEC();
        lbl_8006DFC4(&arg0->unk_8[0]);
        lbl_8006E1D8((lab_t0 = loc_18), v5, v5, lbl_1_rodata_42D0);
        lab_t0 = loc_24;
        lbl_8006E1D8(lab_t0, v4, v5, lbl_1_rodata_42D0);
        lab_t0 = loc_30;
        lbl_8006E1D8(lab_t0, v4, v4, lbl_1_rodata_42D0);
        lab_t0 = loc_3C;
        lbl_8006E1D8(lab_t0, v5, v4, lbl_1_rodata_42D0);
        lbl_8006DB30();
        XF_PUT(loc_18[0]);
        XF_PUT(loc_18[1]);
        XF_PUT(loc_18[2]);
        XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(loc_24[0]);
        XF_PUT(loc_24[1]);
        XF_PUT(loc_24[2]);
        XF_PUT(lbl_1_rodata_42D4);
        XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(loc_30[0]);
        XF_PUT(loc_30[1]);
        XF_PUT(loc_30[2]);
        XF_PUT(lbl_1_rodata_42D4);
        XF_PUT(lbl_1_rodata_42D4);
        XF_PUT(loc_3C[0]);
        XF_PUT(loc_3C[1]);
        XF_PUT(loc_3C[2]);
        XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(lbl_1_rodata_42D4);
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_9F164 */

/* fzgx:begin fn_1_9F4B4 */
struct fn_1_9F4B4_Arg0 {
    u8 pad_0[0xC];
    f32 unk_C;
    s16 unk_10;
    u16 unk_12;
    u32 unk_14;
};
struct fn_1_9F4B4_lbl_1_rodata_42D0 {
    f32 unk_0;
};

extern f32 lbl_1_rodata_42D0;
extern f32 lbl_1_rodata_42D4;
extern s32 fn_1_54E34(void *, f32);
extern void mathutil_mtxA_rotate_z(s32);
extern void fn_8003462C(u32, u32, u32);
extern void fn_800736C0();
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E1D8(void *, f32, f32, f32);

#pragma opt_propagation off
void fn_1_9F4B4(struct fn_1_9F4B4_Arg0 *arg0) {
    f32 loc_30[3];
    f32 loc_24[3];
    f32 loc_18[3];
    f32 loc_C[3];
    u32 loc_8;
    struct { f32 value; } f31;
    struct { f32 value; } f30;
    void *lab_t0;
    void *lab_t0_;
    void *lab_t0__;

    if (fn_1_54E34(arg0, arg0->unk_C) == 0) {
        arg0->unk_12 |= 1;
    } else {
        arg0->unk_12 &= 0xFFFE;
        loc_8 = arg0->unk_14;
        fn_800736C0(0, &loc_8);
        fn_8003462C(0x90, 0, 8);
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = ((*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        fn_8003462C(0x80, 0, 4);
        {
            f31.value = (-arg0->unk_C);
            f30.value = arg0->unk_C;
            lbl_8006DAEC();
            lbl_8006E0A4(arg0);
            if (arg0->unk_10 != 0) {
                mathutil_mtxA_rotate_z(arg0->unk_10);
            }
            lbl_8006E1D8((void *)loc_C, f31.value, f31.value, (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0);
            lab_t0_ = (void *)loc_18;
            lbl_8006E1D8(lab_t0_, f30.value, f31.value, (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0);
            lab_t0 = (void *)loc_24;
            lbl_8006E1D8(lab_t0, f30.value, f30.value, (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0);
            lab_t0__ = (void *)&loc_30;
            lbl_8006E1D8(lab_t0__, f31.value, f30.value, (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0);
        }
        lbl_8006DB30();
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = loc_C[0];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = loc_C[1];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = loc_C[2];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = loc_18[0];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = loc_18[1];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = loc_18[2];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = ((*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D4).unk_0);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = loc_24[0];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = loc_24[1];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = loc_24[2];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = ((*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D4).unk_0);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = ((*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D4).unk_0);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = loc_30[0];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = loc_30[1];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = loc_30[2];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = (*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D0).unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = ((*(struct fn_1_9F4B4_lbl_1_rodata_42D0 *)&lbl_1_rodata_42D4).unk_0);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    }
}

#pragma opt_propagation reset
/* fzgx:end fn_1_9F4B4 */
