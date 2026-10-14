/* Non-matching: best partial attempt (92.19% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_1_3CDB0_lbl_1_bss_3C00 {
    u8 pad_0[0x20];
    u8 unk_20;
    u8 pad_21[0xF];
    u32 unk_30;
    u8 pad_34[0x14D0];
    s8 unk_1504;
};
typedef struct {
    u32 unk_0;
    u8 pad_4[1];
    u8 unk_5;
    u8 pad_6[2];
    u8 unk_8;
} StateFlags;
struct fn_1_3CDB0_lbl_1_bss_7EFD8 {
    u32 unk_0;
};

extern struct fn_1_3CDB0_lbl_1_bss_3C00 lbl_1_bss_3C00[];
extern struct fn_1_3CDB0_lbl_1_bss_7EFD8 lbl_1_bss_7EFD8;
extern u32 fn_1_426C(u32);
extern s32 fn_1_F2F58(void);
extern void * fn_1_435C(void *);
extern void fn_1_1280(u32);
extern void fn_1_D0790(void);
extern void fn_1_F2EDC(void);
extern void fn_1_F37F4(void);

static u8 sub_get5(StateFlags *f) {
    return f->unk_5;
}

static u8 sub_get8(StateFlags *f) {
    return f->unk_8;
}

void fn_1_3CDB0(void) {
    struct fn_1_3CDB0_lbl_1_bss_3C00 *p_lbl_1_bss_3C00;
    u32 v0;
    StateFlags * v1;
    u32 v2;
    u8 v3;
    u32 v4;
    struct { u32 value; } t3;
    StateFlags * v5;
    s32 tmp_ra1;
    p_lbl_1_bss_3C00 = (struct fn_1_3CDB0_lbl_1_bss_3C00 *)&lbl_1_bss_3C00;
    v0 = ((u32)p_lbl_1_bss_3C00 + 0x20000);
    fn_1_1280(0);
    v1 = (StateFlags *)&p_lbl_1_bss_3C00->unk_30;
    if (sub_get5(v1) != 5) {
        fn_1_D0790();
    }
    v2 = *(u32 *)((u8 *)v0 + 8072);
    p_lbl_1_bss_3C00->unk_30 = (p_lbl_1_bss_3C00->unk_30 | 8192);
    fn_1_435C((void *)v2);
    tmp_ra1 = p_lbl_1_bss_3C00->unk_30;
    if ((tmp_ra1 & 0x800000) != 0) {
        if (((0) != (lbl_1_bss_7EFD8.unk_0))) {
            t3.value = fn_1_F2F58();
            if ((s32)t3.value != 0) {
                fn_1_F37F4();
            }
            fn_1_426C(lbl_1_bss_7EFD8.unk_0);
            lbl_1_bss_7EFD8.unk_0 = 0;
        }
        fn_1_F2EDC();
    }
    v5 = (StateFlags *)((u8 *)(u32)p_lbl_1_bss_3C00 + 48);
    (void) v5;  /* fzgx: keeps the web at its definition */
    v3 = sub_get8(v5);
    p_lbl_1_bss_3C00->unk_1504 = -1;
    v4 = v3 != 0 ? *(u8 *)((u8 *)v0 + 8856) : 0;
    *(u32 *)((u8 *)v0 + 12328) = 0;
    p_lbl_1_bss_3C00->unk_20 = v4;
}
