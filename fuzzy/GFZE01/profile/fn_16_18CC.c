/* Non-matching: best partial attempt (97.03% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
typedef struct {
    s32 active;
    s32 entries[5];
} Sig_fn_1_8F494_Fn1_8F494_Object;

struct fn_16_18CC_lbl_16_bss_150 {
    u32 unk_0;
};
struct fn_16_18CC_lbl_16_bss_14C {
    u32 unk_0;
};
struct fn_16_18CC_lbl_16_bss_220_0_E1088 {
    u8 pad_0[0x324];
    u32 unk_324;
    u8 pad_328[0x118];
};
struct fn_16_18CC_lbl_16_bss_220 {
    struct fn_16_18CC_lbl_16_bss_220_0_E1088 unk_0[1];
};
struct fn_16_18CC_lbl_1_bss_8B614 {
    u8 pad_0[0xC];
    s16 unk_C;
    u8 pad_E[0x4A];
    s16 unk_58;
};

extern struct fn_16_18CC_lbl_16_bss_14C lbl_16_bss_14C;
extern struct fn_16_18CC_lbl_16_bss_150 lbl_16_bss_150;
extern struct fn_16_18CC_lbl_16_bss_220 lbl_16_bss_220;
extern struct fn_16_18CC_lbl_1_bss_8B614 lbl_1_bss_8B614;
extern u8 lbl_16_data_0[535296];
extern u32 fn_1_426C(u32);
extern u32 fn_1_435C(u32);
extern void fn_1_48140(int);
extern void fn_1_80F1C(s32, void *);
extern void fn_1_8F494(Sig_fn_1_8F494_Fn1_8F494_Object *);
extern s32 fn_1_12CB04(s16);

void fn_16_18CC(u32 arg0) {
    s16 v1;
    u8 *base;
    s16 v5;
    struct fn_16_18CC_lbl_1_bss_8B614 *p_lbl_1_bss_8B614;
    struct { u8 * value; } v4;
    s32 *v2;
    struct fn_16_18CC_lbl_16_bss_220 *temp_r4;
    struct fn_16_18CC_lbl_16_bss_14C *p_lbl_16_bss_14C;
    Sig_fn_1_8F494_Fn1_8F494_Object * lab_t0;

    base = lbl_16_data_0 + 0x80000;
    if (*(s32 *)(base + 0x2B00) != -1) {
        fn_1_435C(lbl_16_bss_150.unk_0);
        fn_1_426C(*(u32 *)(base + 0x2B00));
        *(u32 *)(base + 0x2B00) = -1;
    }
    p_lbl_1_bss_8B614 = (struct fn_16_18CC_lbl_1_bss_8B614 *)&lbl_1_bss_8B614;
    v1 = p_lbl_1_bss_8B614->unk_C;
    if (p_lbl_1_bss_8B614->unk_58 == 4) {
        fn_1_8F494((Sig_fn_1_8F494_Fn1_8F494_Object *)((u8 *)p_lbl_1_bss_8B614 + 0x74));
        if (*(s32 *)(0x2B04 + base) != -1) {
            fn_1_435C(lbl_16_bss_14C.unk_0);
            fn_1_426C(*(u32 *)(base + 0x2B04));
            *(u32 *)(base + 0x2B04) = -1;
        }
        v4.value = (u8 *)&lbl_1_bss_8B614;
        v2 = (s32 *)(base + 0x2B08);
        p_lbl_16_bss_14C = (struct fn_16_18CC_lbl_16_bss_14C *)&lbl_16_bss_14C;
        (void) p_lbl_16_bss_14C;  /* fzgx: keeps the web at its definition */
        for (v5 = 0; v5 < (s16)fn_1_12CB04(v1); v5++) {
            lab_t0 = (Sig_fn_1_8F494_Fn1_8F494_Object *)(v4.value + 0x55C);
            fn_1_8F494(lab_t0);
            if (*v2 != -1) {
                fn_1_435C(p_lbl_16_bss_14C->unk_0);
                fn_1_426C(*v2);
                *v2 = -1;
            }
            v4.value += 0x4E8;
            v2 += 1;
        }
        p_lbl_1_bss_8B614->unk_58 = 0;
    }
    fn_1_48140(*(s32 *)(base + 0x2B54 + (s32)p_lbl_1_bss_8B614->unk_C * 4));
    temp_r4 = (struct fn_16_18CC_lbl_16_bss_220 *)(&(&lbl_16_bss_220)[p_lbl_1_bss_8B614->unk_C]);
    fn_1_80F1C((s32)((s32)(s16)temp_r4->unk_0[0].unk_324), (void *)(temp_r4));
}
