/* Non-matching: best partial attempt (86.73% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
    f32 unk_18;
    f32 unk_1C;
} InterviewPool;

typedef struct {
    u32 unk_00[4];
    void *unk_10;
    u32 unk_14;
    u32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    u8 unk_28;
    f32 unk_2C;
    u8 unk_30;
    u8 unk_31[3];
    u8 unk_34[0x20];
    u32 unk_54;
} InterviewBss;

extern u32 lbl_17_rodata_0[6];
extern u8 lbl_17_data_63E50[0x250];
extern u8 lbl_17_bss_0;
extern u8 lbl_1_bss_525C[0x198];
extern u32 lbl_801A6410[1];
extern u32 lbl_801A66B4[1];
extern s16 lbl_1_bss_964;
extern s16 lbl_1_bss_96A;
extern void (*lbl_1_bss_7167C[1])(void);
extern void (*lbl_1_bss_71680[1])(void);
extern void (*lbl_1_bss_71684[1])(void);

extern void fn_17_23C(void);
extern void fn_17_2B4(void);
extern void fn_17_394(void);
extern s32 fn_1_45D0(u32, u32, void *, u32);
extern u32 fn_1_3CF0(void *, u32);
extern void fn_1_47F74(s32);
extern void fn_80008BEC(void *, int, u32);
extern void * memset(void *, int, u32);
extern void fn_1_4A00(s32, u8, void *);
extern u32 fn_1_B724(void *, void *, u32, f32);

void _prolog(void) {
    u32 *pool = lbl_17_rodata_0;
    InterviewBss *s = (InterviewBss *)&lbl_17_bss_0;
    u8 *p = lbl_1_bss_525C;
    u32 t[6];

    s->unk_10 = p;
    s->unk_14 = fn_1_45D0(lbl_801A6410[0], 0x173c, lbl_17_data_63E50, 0x240);
    s->unk_18 = fn_1_45D0(lbl_801A6410[0], 0x173c, lbl_17_data_63E50, 0x241);
    fn_1_3CF0((void *)s->unk_14, 0x80);
    fn_1_3CF0((void *)s->unk_18, 0x80);
    fn_1_47F74(0x8c);
    fn_1_47F74(0xa1);
    s->unk_1C = 0;
    s->unk_20 = -1;
    s->unk_24 = 0x1e;
    s->unk_28 = 1;
    s->unk_2C = 1.0f;
    s->unk_30 = 0;
    fn_80008BEC(s->unk_34, 0xff, 0x20);
    lbl_1_bss_96A = 0xc5;
    s->unk_54 = lbl_801A66B4[0];
    if (lbl_1_bss_964 == 10) {
        memset(s->unk_10, 0, 0x198);
        p[4] = 6;
        p[5] = 6;
        p[6] = 1;
    }
    fn_1_4A00(1, 0x1e, (void *)s->unk_18);
    lbl_1_bss_71680[0] = fn_17_2B4;
    lbl_1_bss_7167C[0] = fn_17_23C;
    lbl_1_bss_71684[0] = fn_17_394;
    t[0] = pool[3];
    t[1] = pool[4];
    t[2] = pool[5];
    t[3] = pool[0];
    t[4] = pool[1];
    t[5] = pool[2];
    fn_1_B724(&t[3], t, 0, 30.0f);
}
