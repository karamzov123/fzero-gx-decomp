/* Non-matching: best partial attempt (74.46% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/globals.h"

extern int fn_1_4C10(void);
extern s16 fn_3_4538(void);
extern void fn_1_1280(u32);
extern void fn_80008BA8(void *, void *);
extern s16 lbl_1_bss_96A;
extern u32 lbl_3_data_B4;

typedef struct {
    s16 index;
} Sig_fn_3_AF8_Fn3AF8Arg;

extern int fn_3_AF8(Sig_fn_3_AF8_Fn3AF8Arg *);

struct fn_3_48E0_base {
    u32 unk_0;
    u8 pad_4[0x11C];
    s32 unk_120;
};

struct fn_3_48E0_sub {
    u32 unk_0;
    u8 pad_4[4];
    s16 unk_8;
    u8 pad_A[0x1A];
    u32 unk_24;
};

struct fn_3_48E0_disp {
    u8 pad_0[0x4374];
    int (*fn)(Sig_fn_3_AF8_Fn3AF8Arg *);
    void *arg;
    u8 pad_8[0x44];
    u32 unk_4C;
};

void fn_3_48E0(void) {
    struct fn_3_48E0_base *ctx = (struct fn_3_48E0_base *)&lbl_3_bss_0;
    struct fn_3_48E0_disp *d = (struct fn_3_48E0_disp *)((u8 *)ctx + 0x20000);
    struct fn_3_48E0_sub *sub = (struct fn_3_48E0_sub *)((u8 *)ctx + 0xf0);
    s32 ok;
    s16 v;

    if (ctx->unk_120 == -1) {
        fn_1_4C10();
    }
    if (((sub->unk_24 & 0x80000000) == 0) && ((sub->unk_24 & 1) != 0) &&
        ((sub->unk_0 & 0x40000000) == 0)) {
        ok = 1;
    } else if (fn_1_4C10() != 0) {
        ok = 1;
    } else {
        ok = 0;
    }
    if (ok == 0) {
        if (ctx->unk_120 != -1) {
            lbl_1_bss_96A = (s16)ctx->unk_120;
            ctx->unk_120 = -1;
        } else {
            v = fn_3_4538();
            if (v == -1) {
                fn_80008BA8((void *)((u8 *)&lbl_3_bss_140 + sub->unk_8 * 0x81C0),
                            (void *)&d->unk_4C);
                ctx->unk_120 = 0x5f;
            } else {
                switch (v) {
                case 12:
                    ctx->unk_0 = 1;
                    ctx->unk_120 = 0x5d;
                    fn_1_1280(1);
                    d->fn = fn_3_AF8;
                    lbl_3_data_B4 = 0x60;
                    d->arg = &sub->unk_8;
                    sub->unk_0 |= 0x10000000;
                    break;
                case 11:
                    ctx->unk_0 = 1;
                    ctx->unk_120 = 0x5d;
                    fn_1_1280(1);
                    d->fn = fn_3_AF8;
                    lbl_3_data_B4 = 0x5f;
                    d->arg = &sub->unk_8;
                    sub->unk_0 |= 0x10000000;
                    break;
                }
            }
        }
    }
}
