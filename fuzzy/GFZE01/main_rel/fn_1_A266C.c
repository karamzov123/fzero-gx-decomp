/* Non-matching: best partial attempt (81.31% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sound.h"

extern void fn_1_A2E24(u32, u32, s32);
extern void fn_1_A2DF4(s32, void *, s32);
extern void fn_1_A4DF4(void);
extern s32 fn_800672E4(u32, s32);
extern u32 fn_8004BF0C(u32, u32);
extern void ADXT_Stop(u32);

typedef struct {
    u8 pad_00[0x1C];
    u32 flags;
    u8 pad_20[4];
    f32 inc0;
    f32 inc1;
    u8 pad_2C[2];
    u8 flag_2E;
    u8 pad_2F[9];
    u32 *handles;
    u8 pad_3C[0x74C - 0x3C];
    struct {
        u8 b0;
        u8 b1;
        s8 v;
        u8 b3[0x11];
    } ch[4];
    u8 pad_79C[0x10];
    u8 flag_7AC;
    u8 pad_7AD[3];
    u8 base_7B0[4];
    u8 pad_7B4[0xCE];
    u8 flag_882;
    u8 pad_883;
    s16 lim0;
    s16 lim1;
    f32 f888;
    f32 f88C;
} SndState;

static inline u8 *fn_1_A266C_array_read(u8 *array) { return array; }
#pragma opt_propagation off
static inline f32 fn_1_A266C_read_pointer(SndState * owner) { return owner->f88C; }
#pragma opt_lifetimes off
static inline f32 fn_1_A266C_read_pointer_(SndState * owner) { return owner->inc1; }
static inline u32 *fn_1_A266C_array_read_(u32 *array) { return array; }
void fn_1_A266C(void) {
    f32 fzgx_value_;
    f32 fzgx_value;
    SndState *s = (SndState *)&lbl_1_bss_6EA98;
    u32 lab_t1;

    if (s->handles != 0) {
        if ((s->flags & 0x80000000) != 0 && s->handles[0] != 0 && s->flag_882 == 0) {
            s32 v;
            s->f888 = s->f888 + s->inc0;
            v = (s32)s->f888;
            if (s->lim0 > v) {
                fn_8004BF0C(fn_1_A266C_array_read_(s->handles)[0], v);
            } else {
                fn_8004BF0C(fn_1_A266C_array_read_(s->handles)[0], (u32)s->lim0);
                s->flags &= 0x7FFFFFFF;
            }
        }
        if ((s->flags & 0x40000000) != 0 && s->handles[1] != 0 && s->flag_882 == 0) {
            s32 v;
            v = (s32)s->f888;
            fzgx_value = fn_1_A266C_read_pointer(s) + (fn_1_A266C_read_pointer_(s));
            fzgx_value_ = fzgx_value;
            s->f88C = fzgx_value_;
            if (s->lim1 > v) {
                fn_8004BF0C(fn_1_A266C_array_read_(s->handles)[1], v);
            } else {
                fn_8004BF0C(fn_1_A266C_array_read_(s->handles)[1], (u32)s->lim1);
                s->flags &= 0x1FFFFFFF;
            }
        }
        if ((s->flags & 0x20000000) != 0 && s->handles[0] != 0 && s->flag_882 == 0) {
            s32 v;
            s->f888 = s->f888 - s->inc0;
            v = (s32)s->f888;
            if (v > -400) {
                fn_8004BF0C(fn_1_A266C_array_read_(s->handles)[0], v);
            } else {
                ADXT_Stop(fn_1_A266C_array_read_(s->handles)[0]);
                s->flags &= 0x0FFFFFFF;
            }
        }
        if ((s->flags & 0x10000000) != 0 && s->handles[1] != 0 && s->flag_882 == 0) {
            s32 v;
            s->f88C = fn_1_A266C_read_pointer(s) - s->inc1;
            v = (s32)fn_1_A266C_read_pointer(s);
            if (v > -400) {
                fn_8004BF0C(fn_1_A266C_array_read_(s->handles)[1], v);
            } else {
                ADXT_Stop(fn_1_A266C_array_read_(s->handles)[1]);
                s->flags &= 0x07FFFFFF;
            }
        }
        if ((s->flags & 0x04000000) != 0) {
            s32 i;
            u8 n = 0;
            u8 m = 0;

            if ((s->flags & 0x01000000) != 0) {
                s32 d;
                for (i = 1; i < 4; i++) {
                    d = fn_800672E4(i, 0xA0100000) - (*((s->base_7B0) + (i)));
                    if (d < 0) {
                        d = 0;
                    }
                    fn_1_A2E24(i, 0xA0100000, d);
                }
                n = 1;
                m = 1;
                for (i = 1; i < 4; i++) {
                    if (fn_800672E4(i, 0xA0100000) == 0) {
                        n++;
                    }
                }
                s->flag_7AC = 0;
            } else {
                s32 d;
                for (i = 0; i < 4; i++) {
                    d = fn_800672E4(i, 0xA0100000) - fn_1_A266C_array_read(s->base_7B0)[i];
                    if (d < 0) {
                        d = 0;
                    }
                    lab_t1 = 0xA0100000;
                    fn_1_A2E24(i, lab_t1, d);
                }
                for (i = 0; i < 4; i++) {
                    if (fn_800672E4(i, 0xA0100000) == 0) {
                        n++;
                    }
                }
            }
            if (s->flag_2E != 0) {
                s8 v;
                for (i = 0; i < 4; i++) {
                    v = s->ch[i].v - 2;
                    if (v < 0) {
                        v = 0;
                        fn_1_A2DF4(i, (void *)0xA6000000, 0);
                        m++;
                    }
                    fn_1_A2DF4(i, (void *)0xA5100000, v);
                    s->ch[i].v = v;
                }
                if (m >= 4) {
                    fn_1_A2E24(0x10, 0xA0000400, 0);
                }
            } else {
                m = 4;
            }
            if (n >= 4 && m >= 4) {
                fn_1_A2E24(0x10, 0xA0000300, 0);
                fn_1_A2E24(0x10, 0xA0000100, 0);
                fn_1_A2E24(0x10, 0xA0100000, 0x7F);
                s->flags &= 0xF8FFFFFF;
                fn_1_A4DF4();
            }
        }
    }
}
#pragma opt_lifetimes reset

#pragma opt_propagation reset

