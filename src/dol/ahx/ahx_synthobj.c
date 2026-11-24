#include "types.h"

/* One synthesis object: a 1024-float ring per channel, addressed from a shared window and transform table. */
typedef struct AhxSynth {
    u8 active;
    s8 index;
    u8 pad_2[2];
    u32 offset[2];
    f32 *transform;
    f32 *window;
    f32 ring[2][0x400];
} AhxSynth;

typedef struct AhxSynthGlobal {
    s32 ref_count;
    s32 initialized;
    f32 *window;
    f32 *transform;
    AhxSynth *slots[16];
} AhxSynthGlobal;

typedef void (*AhxSynthFn)(f32 *ring, f32 *window, void *out);

extern AhxSynthGlobal lbl_80187370;
extern AhxSynth *lbl_80187380[16];
extern u32 lbl_801873C0[6];
extern u8 lbl_801319E0[];
extern u8 lbl_8012B938[];
extern AhxSynthFn lbl_80130BC0[16];

extern void *memset(void *, int, u32);
extern void fn_80051F38(u32, f32 *, f32 *);
extern int fn_80053A30(void);

void fn_80053A38(AhxSynth *synth) {
    s32 index = synth->index;

    memset(synth, 0, sizeof(AhxSynth));
    lbl_80187380[index] = 0;
}

/* WARNING: compiler-diff device, not original code. Retail keeps the slot address and offset in registers. */
#pragma opt_propagation off

AhxSynth *fn_80053A84(AhxSynth *synth, u32 size) {
    AhxSynthGlobal *g = &lbl_80187370;
    s32 index;
    AhxSynth *work;

    {
        AhxSynth **p = g->slots;
        for (index = 0; index < 16; p++, index++) {
            if (*p == 0) {
                break;
            }
        }
    }

    if (index == 16) {
        return 0;
    }

    memset(synth, 0, size);
    {
        u32 offset = index * sizeof(AhxSynth *);
        AhxSynth **slots = g->slots;
        *(AhxSynth **)((u8 *)slots + offset) = synth;
        work = *(AhxSynth **)((u8 *)slots + offset);
    }
    work->index = index;
    work->offset[0] = work->offset[1] = 0x40;
    work->window = g->window;
    work->transform = g->transform;
    work->active = 1;
    return work;
}
#pragma opt_propagation reset

void fn_80053BB4(void) {
    AhxSynthGlobal *g = &lbl_80187370;

    g->ref_count -= 1;
    if (g->ref_count == 0) {
        memset(lbl_80187380, 0, sizeof(lbl_80187380));
    }
}

void fn_80053BFC(void) {
    AhxSynthGlobal *g = &lbl_80187370;

    if (g->ref_count == 0) {
        memset(g->slots, 0, sizeof(g->slots));
        if (g->initialized == 0) {
            char *src1 = (char *)lbl_801319E0 + 0x800;
            char *dst1;
            long n;
            char *src2;
            char *dst2;

            g->window = (f32 *)(((u32)lbl_801319E0 + 0x1F) & ~0x1F);
            dst1 = (char *)g->window + 0x800;

            for (n = 0x2AB; n > 0; n--) {
                *dst1 = *src1;
                *(dst1 - 1) = *(src1 - 1);
                *(dst1 - 2) = *(src1 - 2);
                src1 -= 3;
                dst1 -= 3;
            }

            for (n = 0; n < 0x200; n++) {
                g->window[n] *= 2147483648.0f;
            }

            src2 = (char *)lbl_8012B938 + 0x2000;
            g->transform = (f32 *)(((u32)lbl_8012B938 + 0x1F) & ~0x1F);
            dst2 = (char *)g->transform + 0x2000;

            for (n = 0xAAB; n > 0; n--) {
                *dst2 = *src2;
                *(dst2 - 1) = *(src2 - 1);
                *(dst2 - 2) = *(src2 - 2);
                src2 -= 3;
                dst2 -= 3;
            }

            g->initialized = 1;
        }
    }
    g->ref_count++;
}

void fn_80053DB4(AhxSynth *synth, u32 input, u32 channel, void *out) {
    u32 *p;
    u8 *buf;
    s32 index;
    f32 *transform;
    f32 *ring;

    p = (u32 *)((u8 *)synth + (channel << 2));
    buf = (u8 *)synth + (channel << 12);
    p[1] = (p[1] - 0x40) & 0x3FF;
    index = p[1];
    transform = synth->transform;
    ring = (f32 *)(buf + 0x14 + (index << 2));
    lbl_801873C0[0] = fn_80053A30();
    if ((input & 0x1F) != 0 || ((u32)transform & 0x1F) != 0) {
        while (1) {
        }
    }
    fn_80051F38(input, transform, ring);
    lbl_801873C0[4] = fn_80053A30();
    index = p[1];
    lbl_801873C0[0] = fn_80053A30();
    lbl_80130BC0[index >> 6]((f32 *)(buf + 0x14) + index, synth->window, out);
    lbl_801873C0[4] = fn_80053A30();
}
