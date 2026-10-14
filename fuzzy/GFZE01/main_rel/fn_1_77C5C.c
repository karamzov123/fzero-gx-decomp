/* Non-matching: best partial attempt (72.62% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    s16 x;
    s16 y;
    u32 u;
    u32 pad;
} Ent;

typedef struct Node {
    struct Node *next;
    s32 count;
    Ent *data;
} Node;

struct Bss6C8D8 {
    u8 pad_0[0x8DC];
    s32 inited;
    Node node;
    Ent entries[66];
    u32 tbl[66];
};

typedef union {
    u8 u8;
    u16 u16;
    u32 u32;
    f32 f32;
} WGPipe;

volatile WGPipe GXWGFifo : 0xCC008000;

extern struct Bss6C8D8 lbl_1_bss_6C8D8;
extern char lbl_1_data_1DAC0[0x44];
extern char lbl_1_data_1DB9C[0x24];

extern u16 fn_1_A5DB0(void);
extern void fn_1_9E598(Node *);
extern u8 fn_1_7879C(u32);
extern void OSPanic(const char *, int, const char *, ...);
extern void fn_8007245C(u32);
extern void fn_8003462C(u32, u32, u32);
extern void fn_800724C8(void);

static inline int in01(f32 v) {
    if (v > 1.0f) return 0;
    if (v < 0.0f) return 0;
    return 1;
}

#pragma opt_loop_invariants off
void fn_1_77C5C(f32 *m, s16 *p, s16 *q) {
    int i, j, k;
    f32 uv[4];
    f32 vv[4];
    struct Bss6C8D8 *b = &lbl_1_bss_6C8D8;
    Node *n;

    if (b->inited == 0) {
        f32 c639, a0, c10, a3, c640, a1, c5, a10, c480;
        n = &b->node;
        n->data = b->entries;
        n->count = 66;
        c639 = 639.0f;
        a0 = m[0];
        c10 = 10.0f;
        a3 = m[3];
        c640 = 640.0f;
        a1 = m[1];
        c5 = 5.0f;
        a10 = m[10];
        c480 = 480.0f;
        for (i = 0; i <= 5; i++) {
            for (j = 0; j <= 10; j++) {
                n->data[i * 11 + j].x = (s16)(c639 * (a0 * (f32)(10 - j) / c10 + a3 * (f32)j / c10) / c640);
                n->data[i * 11 + j].y = (s16)((a1 * (f32)(5 - i) / c5 + a10 * (f32)i / c5) * (f32)((s32)fn_1_A5DB0() - 1) / c480);
                n->data[i * 11 + j].u = 0;
            }
        }
        b->inited = 1;
    }
    fn_1_9E598(&b->node);

    uv[0] = uv[3] = (f32)(p[0] - q[0]) / (f32)q[2];
    uv[1] = uv[2] = (f32)(p[0] + p[2] - q[0]) / (f32)q[2];
    {
        s32 a = (s32)((f32)(p[1] * fn_1_A5DB0()) / 480.0f);
        vv[0] = vv[1] = (f32)(a - q[1]) / (f32)q[3];
    }
    {
        s32 a = (s32)((f32)(p[3] * fn_1_A5DB0()) / 480.0f);
        s32 c = (s32)((f32)(p[1] * fn_1_A5DB0()) / 480.0f);
        vv[2] = vv[3] = (f32)(c + a - q[1]) / (f32)q[3];
    }

    for (k = 0; k < 4; k++) {
        if (!(in01(uv[k]) && in01(vv[k]))) {
            OSPanic(lbl_1_data_1DAC0, 0xc24, lbl_1_data_1DB9C);
        }
    }

    {
        Ent *d = b->node.data;
        for (i = 0; i <= 5; i++) {
            for (j = 0; j <= 10; j++) {
                int idx = i * 11 + j;
                if (i != 5) {
                    b->tbl[idx] = (u32)((f32)b->tbl[idx] + (f32)(0.2f * (f32)(s32)(d[idx].u - b->tbl[idx])));
                } else {
                    b->tbl[idx] = 0;
                }
            }
        }
    }

    fn_8007245C(0x2a00);
    {
        f32 a0 = m[0];
        f32 a1 = m[1];
        f32 a3 = m[3];
        f32 a10 = m[10];
        for (i = 0; i < 5; i++) {
            int k0 = i * 11;
            int k1 = (i + 1) * 11;
            for (j = 0; j < 10; j++) {
                f32 x0 = (f32)p[4] + a0 * (f32)(10 - j) / 10.0f + a3 * (f32)j / 10.0f;
                f32 x1 = (f32)p[4] + a0 * (f32)(10 - (j + 1)) / 10.0f + a3 * (f32)(j + 1) / 10.0f;
                f32 y0 = (f32)p[5] + a1 * (f32)(5 - i) / 5.0f + a10 * (f32)i / 5.0f;
                f32 y1 = (f32)p[5] + a1 * (f32)(5 - (i + 1)) / 5.0f + a10 * (f32)(i + 1) / 5.0f;
                f32 u0 = uv[0] * (f32)(10 - j) / 10.0f + uv[1] * (f32)j / 10.0f;
                f32 u1 = uv[0] * (f32)(10 - (j + 1)) / 10.0f + uv[1] * (f32)(j + 1) / 10.0f;
                f32 v0 = vv[0] * (f32)(5 - i) / 5.0f + vv[3] * (f32)i / 5.0f;
                f32 v1 = vv[0] * (f32)(5 - (i + 1)) / 5.0f + vv[3] * (f32)(i + 1) / 5.0f;
                u8 c0 = fn_1_7879C(b->tbl[k0 + j]);
                u8 c1 = fn_1_7879C(b->tbl[k0 + j + 1]);
                u8 c2 = fn_1_7879C(b->tbl[k1 + j + 1]);
                u8 c3 = fn_1_7879C(b->tbl[k1 + j]);

                fn_8003462C(0x80, 0, 4);
                GXWGFifo.f32 = x0;
                GXWGFifo.f32 = y0;
                GXWGFifo.f32 = 0.0f;
                GXWGFifo.u8 = 0;
                GXWGFifo.u8 = 0;
                GXWGFifo.u8 = 0;
                GXWGFifo.u8 = c0;
                GXWGFifo.f32 = u0;
                GXWGFifo.f32 = v0;

                GXWGFifo.f32 = x1;
                GXWGFifo.f32 = y0;
                GXWGFifo.f32 = 0.0f;
                GXWGFifo.u8 = 0;
                GXWGFifo.u8 = 0;
                GXWGFifo.u8 = 0;
                GXWGFifo.u8 = c1;
                GXWGFifo.f32 = u1;
                GXWGFifo.f32 = v0;

                GXWGFifo.f32 = x1;
                GXWGFifo.f32 = y1;
                GXWGFifo.f32 = 0.0f;
                GXWGFifo.u8 = 0;
                GXWGFifo.u8 = 0;
                GXWGFifo.u8 = 0;
                GXWGFifo.u8 = c2;
                GXWGFifo.f32 = u1;
                GXWGFifo.f32 = v1;

                GXWGFifo.f32 = x0;
                GXWGFifo.f32 = y1;
                GXWGFifo.f32 = 0.0f;
                GXWGFifo.u8 = 0;
                GXWGFifo.u8 = 0;
                GXWGFifo.u8 = 0;
                GXWGFifo.u8 = c3;
                GXWGFifo.f32 = u0;
                GXWGFifo.f32 = v1;
            }
        }
    }
    fn_800724C8();

    for (i = 0; i <= 5; i++) {
        for (j = 0; j <= 10; j++) {
            b->node.data[i * 11 + j].u = 0;
        }
    }
}
