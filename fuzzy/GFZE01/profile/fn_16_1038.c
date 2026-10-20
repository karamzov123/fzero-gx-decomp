/* Non-matching: best partial attempt (89.05% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/profile/data/lbl_16_data_0.h"
#include "rel/profile/data/lbl_16_bss_B0B8.h"

struct fn_16_1038_ent {
    u32 unk_554;
    s16 unk_558;
    u8 pad_55A[0x4E2];
};

struct fn_16_1038_b154 {
    u8 pad_0[0xA8];
    f32 unk_A8;
    u8 pad_AC[0x1C];
};

struct fn_16_1038_bss0 {
    u32 unk_0;
    u32 tab[41];
    u8 pad_A8[0xA8];
    u32 unk_150;
    struct fn_16_1038_b154 b154;
    u32 unk_21C;
};

struct fn_16_1038_g {
    u8 pad_0[0xA];
    s16 unk_A;
    s16 unk_C;
    u16 unk_E;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    u16 unk_28;
    u16 unk_2A;
    u8 pad_2C[0x4];
    s16 unk_30;
    u8 pad_32[0x2];
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    u32 unk_4C;
    u16 unk_50;
    u16 unk_52;
    u16 unk_54;
    u8 pad_56[0x2];
    u16 unk_58;
    s16 unk_5A;
    u32 unk_5C;
    u8 pad_60[0x4];
    u32 unk_64;
    u32 unk_68;
    u32 unk_6C;
    s16 unk_70;
    u8 pad_72[0x4E2];
    struct fn_16_1038_ent ent[2];
};

struct fn_16_1038_s {
    s16 f0;
    s16 f2;
    u32 f4;
    u8 f8;
    u8 pad_9[0x17];
};

extern const f32 lbl_16_rodata_0[18];
extern struct fn_16_1038_bss0 lbl_16_bss_0;
extern struct fn_16_1038_g lbl_1_bss_8B614;
extern s16 lbl_1_bss_966;
extern u16 lbl_16_bss_860B8[4];
extern u32 lbl_16_bss_B0B4;
extern u8 lbl_16_bss_220[44608];

void fn_1_49410(ProfileTextData *);
void fn_1_495B0(u32);
void fn_1_4965C(u8);
void fn_1_4955C(f32, f32);
void fn_1_49590(f32);
void fn_1_4D784(s32, s32, s32, s32, char *, u8 *, ...);
char *fn_80083DB0(char *, const char *);
s16 fn_1_4B16C(u8 *, s32, struct fn_16_1038_g *, s32);
s32 fn_1_12CB04(s16);
void fn_1_46838(s16);
s32 fn_1_12C930(s16);
u8 *fn_1_12D254(s16, u32);
s32 fn_1_465D0(u8 *, s32);
s32 fn_1_12CCB0(s16, s16);
s16 fn_1_46B44(u32, u32);
u32 fn_1_435C(u32);
void fn_1_4A00(s32, s32, u32);
s32 fn_1_3F8C(u32, u32, u32, u32);
s16 fn_1_80CC4(s16, s32, s32, u8 *);
void fn_80008BEC(void *, int, u32);
void fn_1_12AB38(void *);
void fn_1_80270(struct fn_16_1038_s *, u8 *);
void fn_800713E0(u32, u32);
void fn_1_8019C(u32);
void fn_1_47F74(s32);
void fn_1_A1964(u32);
void fn_16_6508(void);

static inline u32 *fn_16_1038_array_read(u32 *array) { return array; }
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_16_1038(void) {
    const u8 *pPool;
    struct fn_16_1038_bss0 *pBss;
    char *pData;
    struct fn_16_1038_s v0;
    struct fn_16_1038_ent *pEnt;
    u8 *pRec;
    u8 *pTab;
    s16 n;
    s16 c;
    struct { s16 value; } i;
    s16 v;
    char str[0x808];
    void * lab_t0;

    pBss = &lbl_16_bss_0;
    pPool = (const u8 *)lbl_16_rodata_0;
    pData = (char *)&lbl_16_data_0 + 0x80000;
    fn_1_49410(&lbl_16_data_0);
    fn_1_495B0(0x8000U << 16);
    fn_1_4965C(2);
    fn_1_4955C(*(const f32 *)(pPool + 0x4C), *(const f32 *)(pPool + 0x4C));
    switch (lbl_1_bss_8B614.unk_A) {
    case 0:
        fn_1_49590(*(const f32 *)(pPool + 0x18));
        break;
    case 5:
        break;
    }
    if (lbl_1_bss_8B614.unk_A == 5) {
        fn_1_4D784(0, 0, 1, 0xE4, str, (u8 *)fn_16_1038_array_read(pBss->tab)[lbl_1_bss_8B614.unk_C] + (lbl_1_bss_8B614.unk_A << 11));
    } else {
        fn_1_4D784(1, 0, 1, 0xE4, str, (u8 *)fn_16_1038_array_read(pBss->tab)[lbl_1_bss_8B614.unk_C] + (lbl_1_bss_8B614.unk_A << 11));
    }
    fn_80083DB0((char *)&lbl_16_bss_B0B8.biographies[lbl_1_bss_8B614.unk_C][lbl_1_bss_8B614.unk_A], str);
    lbl_1_bss_8B614.unk_E = 0;
    lbl_16_bss_860B8[0] = fn_1_4B16C((u8 *)&lbl_16_bss_B0B8.biographies[lbl_1_bss_8B614.unk_C][lbl_1_bss_8B614.unk_A], lbl_1_bss_8B614.unk_C * 0x3000, &lbl_1_bss_8B614, 0);
    c = lbl_1_bss_8B614.unk_C;
    n = (s16)fn_1_12CB04(c);
    if (lbl_1_bss_8B614.unk_70 != -1) {
        fn_1_46838(lbl_1_bss_8B614.unk_70);
    }
    for (i.value = 0; i.value < 2; i.value++) {
        if (lbl_1_bss_8B614.ent[i.value].unk_558 != -1) {
            fn_1_46838(lbl_1_bss_8B614.ent[i.value].unk_558);
        }
    }
    if (lbl_1_bss_8B614.unk_5A != -1) {
        fn_1_46838(lbl_1_bss_8B614.unk_5A);
    }
    lbl_1_bss_8B614.unk_58 = 0;
    lbl_1_bss_8B614.unk_6C = (u32)fn_1_12D254(fn_1_12C930(c), lbl_1_bss_8B614.unk_5C);
    lbl_1_bss_8B614.unk_70 = fn_1_465D0((u8 *)lbl_1_bss_8B614.unk_6C, 1);
    pEnt = lbl_1_bss_8B614.ent;
    for (i.value = 0; i.value < n; i.value++) {
        pEnt->unk_554 = (u32)fn_1_12D254(fn_1_12CCB0(c, i.value), lbl_1_bss_8B614.unk_5C);
        pEnt->unk_558 = fn_1_465D0((u8 *)pEnt->unk_554, 1);
        pEnt++;
    }
    lbl_1_bss_8B614.unk_58 = 1;
    lbl_1_bss_8B614.unk_5A = fn_1_46B44(lbl_1_bss_8B614.unk_64, lbl_1_bss_8B614.unk_68);
    fn_1_435C(pBss->unk_150);
    fn_1_4A00(1, 15, pBss->unk_150);
    lbl_16_bss_B0B4 = 0;
    *(u32 *)(pData + 0x2B00) = fn_1_3F8C((u32)(pData + 0x2D70), (u32)fn_16_6508, 0, 8);
    pBss->unk_21C = -1;
    pRec = lbl_16_bss_220 + lbl_1_bss_8B614.unk_C * 0x440;
    v = fn_1_80CC4(lbl_1_bss_8B614.unk_C, 0, 0, pRec);
    *(u32 *)(lbl_16_bss_220 + lbl_1_bss_8B614.unk_C * 0x440 + 0x324) = v;
    fn_80008BEC(&v0, 0, 0x20);
    v0.f2 = lbl_1_bss_8B614.unk_C;
    v0.f4 = 0;
    v0.f8 = 0xF;
    v0.f0 = lbl_1_bss_8B614.unk_C;
    lab_t0 = pData + 0x2D24;
    fn_1_12AB38(lab_t0);
    fn_1_80270(&v0, pRec);
    lab_t0 = pData + 0x2D30;
    fn_1_12AB38(lab_t0);
    pTab = lbl_16_bss_220 + 0x338;
    fn_800713E0(*(u32 *)(pTab + lbl_1_bss_8B614.unk_C * 0x440 + lbl_1_bss_8B614.unk_5C * 0xC),
                *(u32 *)(lbl_16_bss_220 + lbl_1_bss_8B614.unk_C * 0x440 + lbl_1_bss_8B614.unk_30 * 4 + 0x37C));
    fn_1_8019C(*(u32 *)(pTab + lbl_1_bss_8B614.unk_C * 0x440 + lbl_1_bss_8B614.unk_5C * 0xC));
    fn_1_47F74(*(s32 *)(pData + 0x2B54 + lbl_1_bss_8B614.unk_C * 4));
    lbl_1_bss_8B614.unk_4C = 0;
    lbl_1_bss_8B614.unk_4C |= 0x80000000;
    lbl_1_bss_8B614.unk_10 = *(const f32 *)(pPool + 0x18);
    lbl_1_bss_8B614.unk_14 = *(const f32 *)(pPool + 0x30);
    lbl_1_bss_8B614.unk_18 = *(const f32 *)(pPool + 0x34);
    lbl_1_bss_8B614.unk_1C = *(const f32 *)(pPool + 0x18);
    lbl_1_bss_8B614.unk_20 = *(const f32 *)(pPool + 0x0);
    lbl_1_bss_8B614.unk_24 = *(const f32 *)(pPool + 0x0);
    lbl_1_bss_8B614.unk_28 = 0x14A;
    lbl_1_bss_8B614.unk_2A = 0x14A;
    lbl_1_bss_8B614.unk_34 = *(const f32 *)(pPool + 0x0);
    lbl_1_bss_8B614.unk_38 = *(const f32 *)(pPool + 0x18);
    lbl_1_bss_8B614.unk_3C = *(const f32 *)(pPool + 0x38);
    lbl_1_bss_8B614.unk_40 = *(const f32 *)(pPool + 0x0);
    lbl_1_bss_8B614.unk_44 = *(const f32 *)(pPool + 0x18);
    lbl_1_bss_8B614.unk_48 = *(const f32 *)(pPool + 0x0);
    pBss->b154.unk_A8 = *(const f32 *)(pPool + 0x3C);
    lbl_1_bss_8B614.unk_4C |= 0x1000;
    lbl_1_bss_8B614.unk_50 = 1;
    lbl_1_bss_8B614.unk_52 = 0;
    lbl_1_bss_8B614.unk_54 = 0xF;
    if (lbl_1_bss_966 != 0xC1) {
        fn_1_A1964((u32)(u8)lbl_1_bss_8B614.unk_C);
    }
}
#pragma opt_dead_assignments reset

#pragma opt_propagation reset
