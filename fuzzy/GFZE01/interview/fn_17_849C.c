/* Non-matching: best partial attempt (96.19% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/interview/interview.h"

extern f32 lbl_17_rodata_0[];
extern u32 lbl_1_rodata_26F8[];
extern u32 lbl_17_bss_20;
extern f32 lbl_17_bss_354[];
extern int fn_1_4F734(void *);

typedef struct {
    u32 word04;
    f32 float08;
    f32 float0c;
    f32 float10;
    f32 float14[7];
    f32 float30;
    u32 word34;
    u32 word38[9];
} InterviewParams;

static inline f32 *fn_17_849C_array_read_(f32 *array) { return array; }
#pragma opt_lifetimes off
#pragma opt_propagation off
void fn_17_849C(f32 scale) {
    f32 * fzgx_live_;
    f32 * fzgx_live;
    f32* rodata = lbl_17_rodata_0;
    f32 cur = fn_17_849C_array_read_(lbl_17_bss_354)[0];
    InterviewParams params;
    f32 * fzgx_live_2;
    f64 grow;
    f64 span;
    f32 w;
    f32 res;
    f32 wrap_2;

    grow = *(f32 *)&rodata[20] * (f64)(fn_17_849C_array_read_(rodata)[39] - cur);
    (void) grow;
    lbl_17_bss_354[0] = (f32)((f64)cur + grow);
    params = *(InterviewParams *)lbl_1_rodata_26F8;
    params.float08 = fn_17_849C_array_read_(rodata)[40];
    params.float0c = fn_17_849C_array_read_(rodata)[70];
    params.float10 = fn_17_849C_array_read_(rodata)[167];
    params.word04 = 0x8C04;
    params.word34 = 10;
    params.float30 = scale;
    fn_1_4F734(&params.word04);

    params.float10 = fn_17_849C_array_read_(rodata)[48];
    params.word04 = 0x8C06;
    if ((s32)lbl_17_bss_20 > (s32)(lbl_17_data_63058.unk_30 + 0x14)) {
        span = fn_17_849C_array_read_(rodata)[39] * fn_17_849C_array_read_(lbl_17_bss_354)[0];
        fzgx_live_ = params.float14;
        fzgx_live_[0] = span;
        fzgx_live_ = params.float14;
        fzgx_live_[1] = span;
        if (params.float14[1] > fn_17_849C_array_read_(rodata)[39]) {
            w = fn_17_849C_array_read_(rodata)[39] - ((f32)span - ((39)[rodata]));
            if (w < fn_17_849C_array_read_(rodata)[8]) {
                res = fn_17_849C_array_read_(rodata)[8];
            } else {
                if (w > fn_17_849C_array_read_(rodata)[39]) {
                    res = fn_17_849C_array_read_(rodata)[39];
                } else {
                    res = w;
                }
            }
            fzgx_live_ = params.float14;
            fzgx_live_[1] = res;
        }
    } else {
        fzgx_live_ = params.float14;
        fzgx_live_[0] = fn_17_849C_array_read_(rodata)[8];
        fzgx_live_ = params.float14;
        fzgx_live_[1] = fn_17_849C_array_read_(rodata)[8];
    }
    fzgx_live_ = params.float14;
    fzgx_live = fzgx_live_;
    params.float30 = fn_17_849C_array_read_(fzgx_live)[1] * fn_17_849C_array_read_(rodata)[15];
    fn_1_4F734(&params.word04);

    params.float10 = fn_17_849C_array_read_(rodata)[7];
    params.word04 = 0x8C06;
    params.word38[1] = ((u32 *)rodata)[0xA6];
    if ((s32)lbl_17_bss_20 > (s32)(lbl_17_data_63058.unk_30 + 0x14)) {
        span = fn_17_849C_array_read_(rodata)[108] * fn_17_849C_array_read_(lbl_17_bss_354)[0];
        fzgx_live_ = params.float14;
        fzgx_live_[0] = span;
        fzgx_live_ = params.float14;
        fzgx_live_[1] = span;
        if (params.float14[1] > fn_17_849C_array_read_(rodata)[108]) {
            wrap_2 = fn_17_849C_array_read_(rodata)[108] - ((f32)span - fn_17_849C_array_read_(rodata)[108]);
            if (wrap_2 < fn_17_849C_array_read_(rodata)[8]) {
                res = fn_17_849C_array_read_(rodata)[8];
            } else {
                if (wrap_2 > fn_17_849C_array_read_(rodata)[108]) {
                    res = fn_17_849C_array_read_(rodata)[108];
                } else {
                    res = wrap_2;
                }
            }
            fzgx_live_ = params.float14;
            fzgx_live_[1] = res;
        }
    } else {
        fzgx_live_ = params.float14;
        fzgx_live_[0] = fn_17_849C_array_read_(rodata)[8];
        fzgx_live_ = params.float14;
        fzgx_live_[1] = fn_17_849C_array_read_(rodata)[8];
    }
    fzgx_live_ = params.float14;
    fzgx_live_2 = fzgx_live_;
    params.float30 = fn_17_849C_array_read_(fzgx_live_2)[1] / fn_17_849C_array_read_(rodata)[108];
    fn_1_4F734(&params.word04);
}
#pragma opt_propagation reset

#pragma opt_lifetimes reset
