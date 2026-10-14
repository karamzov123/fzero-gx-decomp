/* Non-matching: best partial attempt (91.90% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/enemy_ctrl.h"

struct CB028History {
    u8 pad_0[3];
    u8 unk_3;
    u8 pad_4[4];
    u8 unk_8;
    u8 pad_9[7];
    u32 unk_10[8];
};
struct CB028Packet {
    f32 x;
    f32 y;
    f32 scale;
    f32 a;
    f32 b;
    s32 image;
    s32 index;
    u32 unk_1C;
    union { u32 word; u8 bytes[4]; } color;
};
struct CB028Word { u32 unk_0; };
struct CB028Float { f32 unk_0; };
extern f32 lbl_1_rodata_5CD8;
extern f32 lbl_1_rodata_5D04;
extern f32 lbl_1_rodata_5DD4;
extern f32 lbl_1_rodata_5E10;
extern struct CB028Float lbl_1_rodata_5CFC;
#define lbl_1_rodata_5CFC (lbl_1_rodata_5CFC.unk_0)
extern f64 lbl_1_rodata_5C00;
extern f64 lbl_1_rodata_5CE8;
extern struct CB028Word lbl_1_rodata_5DF4;
extern struct CB028Word lbl_1_rodata_5DF8;
extern struct CB028Float lbl_1_rodata_5E08;
extern struct CB028Float lbl_1_rodata_5E0C;
extern u32 lbl_1_rodata_5DF0;
extern u32 lbl_1_rodata_5DFC;
extern u32 lbl_1_rodata_5E00;
extern u32 lbl_1_rodata_5E04;
extern u32 fn_1_5910(void);
extern void *fn_1_15F618(s32);
extern u32 fn_1_CB6D8(void *);

#pragma opt_propagation on
static inline u8 * fn_1_CB028_read_pointer(struct CB028Packet * owner) { return owner->color.bytes; }
static inline u32 * fn_1_CB028_read_pointer_(struct CB028History * owner) { return owner->unk_10; }
static inline u8 * fn_1_CB028_read_pointer__(struct CB028Packet * owner) { return owner->color.bytes; }
void fn_1_CB028(s32 arg0, s32 arg1) {
    struct CB028History *t2;
    Obj_1_bss_7ACA0 *state;
    s32 v16;
    s32 v5;
    u32 v13;
    struct { f32 value; } step;
    s32 v4;
    s32 v17;
    f32 v6;
    f32 v7;
    f32 scale;
    volatile u32 loc_8;
    struct CB028Packet loc_C;
    v7 = lbl_1_rodata_5CFC;
    loc_8 = lbl_1_rodata_5DF0;
    if (( (&lbl_1_data_3D544.unk_0)[fn_1_5910()] >> 24) & 1) {
        t2 = fn_1_15F618(fn_1_5910());
        state = (Obj_1_bss_7ACA0 *)((u8 *)&lbl_1_bss_7ACA0 + fn_1_5910() * 12);
        {
        f32 divisor = lbl_1_rodata_5D04;
        f32 one = lbl_1_rodata_5CFC;
        f32 conv = (f32)(u32)t2->unk_3;
        v6 = one - conv / divisor;
        }
        v4 = t2->unk_8;
        if (v4 >= 1) {
            if (v4 > 4) {
                v5 = v4 - 4;
                if (state->unk_8 != 0) {
                    v5--;
                    v7 = (f32)(u32)state->unk_8 / lbl_1_rodata_5D04;
                    v6 = lbl_1_rodata_5CFC;
                }
                v4 = 4;
            } else {
                v5 = 0;
            }
            loc_C.x = (f32)arg0;
            loc_C.scale = *(f32 *)((u8 *)&lbl_1_rodata_5E08 + 0);
            loc_C.y = (f32)arg1;
            loc_C.a = *(f32 *)((u8 *)&lbl_1_rodata_5E0C + 0);
            loc_C.b = *(f32 *)((u8 *)&lbl_1_rodata_5CFC + 0);
            loc_C.index = -1;
            loc_C.unk_1C = lbl_1_rodata_5DF4.unk_0;
            loc_C.color.word = lbl_1_rodata_5DF8.unk_0;
            if (state->unk_8 != 0) state->unk_8--;
            v17 = v4 + v5;
            v17--;
            v13 = ((v17 % 8)[fn_1_CB028_read_pointer_(t2)]);
            if (v13 == state->unk_4) {
                if (state->unk_9 != v17) {
                    state->unk_A = state->unk_9;
                    state->unk_B = 60;
                    state->unk_9 = v17;
                }
                loc_8 = lbl_1_rodata_5DFC;
            }
            loc_C.index = v5;
{
    struct { f32 value; } fzgx_loop_step_3463;
            v16 = 0;
            fzgx_loop_step_3463.value = lbl_1_rodata_5DD4 * v7;
            scale = lbl_1_rodata_5E0C.unk_0;
            while (v16 < (v4 - 1)) {
                v17 = v16 + v5;
                loc_C.image = ((v17 % 8)[fn_1_CB028_read_pointer_(t2)]);
                if (v16 == 0) loc_C.a = v7;
                else loc_C.a = lbl_1_rodata_5CFC;
                loc_C.a = loc_C.a * scale;
                if (state->unk_9 == v17) {
                    loc_C.color.word = lbl_1_rodata_5E00;
                } else if (state->unk_A == v17 && state->unk_B != 0) {
                    f32 v0 = (f32)(u32)state->unk_B;
                    v0 = lbl_1_rodata_5CFC - v0 / lbl_1_rodata_5E10;
                    v0 = v0 * lbl_1_rodata_5CD8;
                    fn_1_CB028_read_pointer(&loc_C)[0] = 255;
                    fn_1_CB028_read_pointer__(&loc_C)[1] = 255;
                    fn_1_CB028_read_pointer__(&loc_C)[2] = (s32)v0;
                } else {
                    loc_C.color.word = lbl_1_rodata_5E04;
                }
                fn_1_CB6D8(&loc_C);
                if (v16 == 0) loc_C.y = loc_C.y + fzgx_loop_step_3463.value;
                else loc_C.y = loc_C.y + lbl_1_rodata_5DD4;
                v16++;
                loc_C.index++;
            }
    step.value = fzgx_loop_step_3463.value;
}
            if (state->unk_B != 0) state->unk_B--;
            loc_C.image = v13;
            loc_C.color.word = loc_8;
            loc_C.b = v6;
            fn_1_CB6D8(&loc_C);
        }
    }
}
#pragma opt_propagation reset
