/* Non-matching: best partial attempt (95.31% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    f32 unk_8;
    u8 unk_C[0xC];
    f32 unk_18;
    u8 pad_1C[0xC];
    f32 unk_28;
    u8 pad_2C[0xC];
    f32 unk_38;
    u32 unk_3C;
} Arg0;

typedef struct {
    u32 unk_0;
    void (*unk_4)(void *);
    Vec3 p0;
    Vec3 p1;
    Vec3 p2;
    Vec3 p3;
    u8 unk_38;
    union {
        u32 unk_3C;
        struct {
            u8 pad[3];
            u8 v;
        } b;
    } u3C;
    u32 unk_40;
} Event;

typedef struct {
    u8 pad_0[4];
    f32 unk_4;
    u8 pad_8[0x44];
    f32 unk_4C;
    u8 pad_50[0x40];
    f64 unk_90;
    f64 unk_98;
} Pool;

typedef struct {
    u8 pad_0[0xD4];
    f32 x;
    f32 y;
    f32 z;
} SndMgr;

typedef struct {
    u8 pad_0[0x2C];
    f32 unk_2C;
    u8 pad_30[0x30];
    u8 unk_60[4];
} SndState;

extern const Pool lbl_1_rodata_28B0;
extern SndMgr *lbl_801A66CC;
extern SndState *lbl_801A6D00;

extern void *fn_1_548AC(u32 size);
extern s32 fn_1_54E34(void *entry, f32 value);
extern u8 *fn_1_54384(f32 value);
extern void fn_1_5489C(void *data, void *event);
extern void fn_1_571E8(void *self);

extern void lbl_8006DCA4(void);
extern void lbl_8006DFC4(void *p);
extern void lbl_8006DB74(void *p);
extern void lbl_8006D848(f32 value);
extern void lbl_8006E1D8(void *dst, f32 x, f32 y, f32 z);

#pragma opt_common_subs off
#pragma peephole off
static inline f32 fn_1_5745C_read_pointer_read_pointer(SndMgr * owner) { return owner->z; }
static inline f32 fn_1_5745C_read_pointer(SndMgr *owner) { return fn_1_5745C_read_pointer_read_pointer(owner); }
#pragma peephole reset

void fn_1_5745C(Arg0 *arg0, u32 *arg1, f32 arg2) {
    f32 fzgx_live;
    void * tmp_call1;
    u8 *data;
    Event *event;
    const Pool *pool;
    f32 neg;

    pool = (const Pool *)&lbl_1_rodata_28B0;

    if ((((arg0->unk_0 >> 2) & 1) != 0) &&
        ((((arg0->unk_0 & arg0->unk_4) & 1) != 0) ||
         (((arg0->unk_0 & arg0->unk_4) & 2) != 0))) {
        tmp_call1 = fn_1_548AC(0x44);
        event = (Event *)tmp_call1;
        if (event == 0) {
            return;
        }
        lbl_8006DCA4();
        lbl_801A66CC->x = arg0->unk_18;
        lbl_801A66CC->y = arg0->unk_28;
        lbl_801A66CC->z = arg0->unk_38;
        if (fn_1_54E34(&lbl_801A66CC->x, pool->unk_4C) == 0) {
            return;
        }
        lbl_8006DFC4(arg0->unk_C);
        data = fn_1_54384(lbl_801A6D00->unk_2C);
        event->unk_4 = fn_1_571E8;
        psvec_set(&lbl_801A66CC->x, *(volatile f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
        fzgx_live = lbl_801A66CC->z;
        lbl_801A66CC->z = -fzgx_live;
        if (lbl_801A66CC->z > pool->unk_90) {
            lbl_8006DB74(lbl_801A6D00->unk_60);
            fzgx_live = lbl_801A66CC->z;
            lbl_8006D848((fzgx_live - pool->unk_4C) / fn_1_5745C_read_pointer(lbl_801A66CC));
            lbl_8006DFC4(lbl_801A6D00->unk_60);
            event->unk_40 = 3;
        } else {
            event->unk_40 = 7;
        }
        if ((arg0->unk_0 >> 1) & 1) {
            neg = -pool->unk_4C;
            lbl_8006E1D8(&event->p0, neg, neg, (*(f32 volatile *)&(pool->unk_4)));
            lbl_8006E1D8(&event->p1, pool->unk_4C, neg, (*(f32 volatile *)&(pool->unk_4)));
            lbl_8006E1D8(&event->p2, pool->unk_4C, pool->unk_4C, (*(f32 volatile *)&(pool->unk_4)));
            lbl_8006E1D8(&event->p3, neg, pool->unk_4C, (*(f32 volatile *)&(pool->unk_4)));
        } else {
            neg = -pool->unk_4C;
            lbl_8006E1D8(&event->p0, neg, (*(f32 volatile *)&(pool->unk_4)), neg);
            lbl_8006E1D8(&event->p1, pool->unk_4C, (*(f32 volatile *)&(pool->unk_4)), neg);
            lbl_8006E1D8(&event->p2, pool->unk_4C, (*(f32 volatile *)&(pool->unk_4)), pool->unk_4C);
            lbl_8006E1D8(&event->p3, neg, (*(f32 volatile *)&(pool->unk_4)), pool->unk_4C);
        }
        event->unk_38 = arg0->unk_3C;
        event->u3C.unk_3C = *arg1;
        event->u3C.b.v = (u8)(s32)((f32)(u32)event->u3C.b.v * arg0->unk_8);
        fn_1_5489C(data, event);
    }
}
#pragma opt_common_subs reset
