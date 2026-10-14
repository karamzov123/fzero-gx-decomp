/* Non-matching: best partial attempt (90.67% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/globals.h"

struct fn_3_680C_lbl_3_data_0 {
    u8 pad_0[0x11D0];
    s16 unk_11D0;
    u8 pad_11D2[2];
    u32 unk_11D4;
};

extern u32 fn_1_12A32C(void *);
extern void fn_1_80058(s8, u8 *);
extern void fn_1_12A2B8(u32);
extern void fn_1_80C18(u8 *, u8 *, s8);
extern s32 fn_8006FDEC(void);
extern s32 fn_1_3F8C(void *, void (*)(void), u32, u32);
extern void fn_3_2B268(void);
extern void fn_1_4A00(s32, u8, void *);
extern s32 fn_1_F9244(u32);
extern void fn_1_F8D5C(u32, void *);
extern void fn_1_7B2E8(s32);
extern void fn_1_47F74(s32);
extern void fn_3_7A08(s16 *, s16 *, int);

u32 fn_3_680C(s32 arg0) {
    u32 v0;
    struct fn_3_680C_lbl_3_data_0 *p_lbl_3_data_0;
    u32 v2;
    u8 *p_lbl_3_bss_0;
    u32 v1;
    u32 v3;
    struct { s32 value; } v4;
    s16 v5;
    s32 i;
    s8 count;
    s16 a, b;
    p_lbl_3_bss_0 = (u8 *)&lbl_3_bss_0;
    v0 = ((u32)p_lbl_3_bss_0 + 0x80000);
    p_lbl_3_data_0 = (struct fn_3_680C_lbl_3_data_0 *)&lbl_3_data_0;
    v1 = ((u32)p_lbl_3_bss_0 + 0x20000);
    v3 = (v0 - 9376);
    v4.value = 0;
    while ((s16)v4.value < 41) {
        fn_1_80058((s8)v4.value, (u8 *)v3);
        *(u16 *)((u8 *)v3 + 0) = v4.value;
        v4.value++;
        v5 = p_lbl_3_data_0->unk_11D0;
        *(u8 *)((u8 *)v3 + 8) = 0;
        *(u8 *)((u8 *)v3 + 8) = (*(u8 *)((u8 *)v3 + 8) | 16);
        *(u32 *)((u8 *)v3 + 4) = (1 << v5);
        v3 += 32;
    }
    p_lbl_3_data_0->unk_11D4 = fn_1_12A32C((u8 *)p_lbl_3_data_0 + 4452);
    fn_1_12A2B8(1);
    fn_1_80C18(*(u8 **)(v1 + 0x854), (u8 *)(v0 - 9376), 41);
    fn_1_12A2B8(0);
    {
    s16 fzgx_loop_i_1563;
for (fzgx_loop_i_1563 = 0; (s16)fzgx_loop_i_1563 < 41; fzgx_loop_i_1563++) {
        *(u32 *)(*(u8 **)(v1 + 0x854) + fzgx_loop_i_1563 * 0x440 + 0x324) = p_lbl_3_data_0->unk_11D4;
    }
    i = fzgx_loop_i_1563;
}
    if (*(s32 *)((u8 *)p_lbl_3_data_0 + 0xB8) == -1) {
        fn_8006FDEC();
        *(s32 *)((u8 *)p_lbl_3_data_0 + 0xB8) = fn_1_3F8C((u8 *)p_lbl_3_data_0 + 0x190C, fn_3_2B268, 0, 8);
    }
    {
        void *t = *(void **)(v1 + 0x850);
        fn_1_4A00(1, 15, t);
    }
    *(u32 *)(v1 + 0x43A8) = 0;
    *(s32 *)(p_lbl_3_bss_0 + 0x120) = -1;
    count = 0;
    for (i = 0; (s16)i < 44; i++) {
        if (fn_1_F9244(i)) {
            fn_1_F8D5C(i, (u8 *)(v0 - 0x1F7C) + (s16)count * 10);
            count++;
        }
    }
    *(s16 *)(v0 - 0x1DC4) = count;
    *(s16 *)(p_lbl_3_bss_0 + 0xE2) = 0;
    *(s16 *)(p_lbl_3_bss_0 + 0xE4) = 0;
    for (v4.value = 0; (s16)v4.value < *(s16 *)(p_lbl_3_bss_0 + 0xE2); v4.value++) {
        fn_3_7A08(&a, &b, 5);
        if (*(s16 *)(p_lbl_3_bss_0 + 0xE2) > b) {
            --*(s16 *)(p_lbl_3_bss_0 + 0xE4);
        }
    }
    if (*(s16 *)(v0 - 0x1DC4) > 0) {
        u8 *entry = (u8 *)(v0 - 0x1F7C) + *(s16 *)(p_lbl_3_bss_0 + 0xE2) * 10;
        if (*(s16 *)(entry + 2) == 1) {
            fn_1_7B2E8(*(s16 *)(entry + 6));
        }
    }
    fn_1_47F74(0xA3);
    *(u32 *)(p_lbl_3_bss_0 + 0xC) = 0;
    return (u32)p_lbl_3_data_0;
}
