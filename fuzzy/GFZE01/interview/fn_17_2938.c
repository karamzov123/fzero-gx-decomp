/* Non-matching: best partial attempt (64.78% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern void fn_17_2D5C(u32, u32);
extern void fn_1_4A00(u32, u32, void *);
extern void fn_1_154F1C(void);
extern void fn_1_46B4(u32, void *, u32);
extern void fn_1_154FC0(void);
extern void fn_1_154FA8(void);
extern s32 fn_17_72C0(s16);
extern void fn_17_74C0(void *);
extern void camera_disable_flags(void);

extern u8 lbl_17_data_0;
extern u8 lbl_17_bss_0;
extern const f32 lbl_17_rodata_20;
extern u32 lbl_17_rodata_38;

typedef struct { u32 unk_0; } L801A6410;
extern L801A6410 lbl_801A6410;

/* lbl_17_bss_0 + 0x60: the interview sub-object passed to fn_17_74C0. */
typedef struct {
    u8 pad_0[0x8];
    u16 value_08;
    u8 pad_A[0x6];
    u32 value_10;
    u32 value_14;
} InterviewSub;

typedef struct {
    u8 pad_0[0x10];
    u8 *unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u8 pad_24[0x30];
    u32 unk_54;
    u32 unk_58;
    u16 unk_5C;
    u8 pad_5E[0x2];
    InterviewSub sub;
    u8 pad_78[0x80];
    u8 unk_F8;
    u8 pad_F9[0x7];
    u8 unk_100;
    u8 pad_101[0x3];
    u32 unk_104;
    u16 unk_108;
    u8 pad_10A[0x2];
    f32 unk_10C;
    f32 unk_110;
    f32 unk_114;
    u32 unk_118[4];
} InterviewState;

/* Five s16[20][4][4] stat tables strided 0xA0 apart from .data+0x62D38;
   retail addresses row*0x20 + col*0x8 + i*0x2 from one section base. */
typedef s16 StatCell[4][4];

void fn_17_2938(void) {
    s16 *data_base = (s16 *)((u8 *)&lbl_17_data_0 + 0x60000);
    InterviewState *bss = (InterviewState *)&lbl_17_bss_0;
    u8 *ptr;
    InterviewSub *sub;
    f32 zero;
    u32 entry;
    s16 i;
    s16 value;
    const StatCell *tbl;

    fn_17_2D5C(bss->unk_14, bss->unk_18);
    fn_1_4A00(1, 0x1e, (void *)bss->unk_18);
    if (bss->unk_58 & 0x80000000) {
        zero = lbl_17_rodata_20;
        entry = lbl_17_rodata_38;
        bss->unk_5C = 0;
        ptr = bss->unk_10;
        bss->unk_1C = 0;
        bss->unk_20 = -1;
        bss->unk_104 = 0;
        bss->unk_108 = 0;
        bss->unk_10C = zero;
        bss->unk_110 = zero;
        bss->unk_114 = zero;
        for (i = 0; i < 4; i++) {
            bss->unk_118[i] = entry;
            /* Every arm keeps its own table base in a register, as retail
               does, so each arm names its own table pointer. */
            switch (ptr[4]) {
            case 3:
                tbl = (const StatCell *)(data_base + 0x173C);
                value = tbl[bss->unk_100][bss->unk_F8][i];
                break;
            case 5:
                tbl = (const StatCell *)(data_base + 0x16EC);
                value = tbl[bss->unk_100][bss->unk_F8][i];
                break;
            case 29:
                tbl = (const StatCell *)(data_base + 0x178C);
                value = tbl[bss->unk_100][bss->unk_F8][i];
                break;
            case 32:
                tbl = (const StatCell *)(data_base + 0x17DC);
                value = tbl[bss->unk_100][bss->unk_F8][i];
                break;
            default:
                tbl = (const StatCell *)(data_base + 0x169C);
                value = tbl[bss->unk_100][bss->unk_F8][i];
                break;
            }
            if (value > 0) {
                bss->unk_104++;
            }
        }
        fn_1_154F1C();
        sub = &bss->sub;
        if (sub->value_10 != 0) {
            /* data_base + 0x1F28 is lbl_17_data_63E50. */
            fn_1_46B4(lbl_801A6410.unk_0, (void *)(data_base + 0x1F28), 0x539);
        }
        sub->value_08 = ptr[4];
        sub->value_10 = fn_17_72C0(ptr[4]);
        sub->value_14 = sub->value_10;
        if (bss->unk_54 == 0) {
            fn_1_154FC0();
        } else {
            fn_1_154FA8();
        }
        fn_17_74C0(sub);
        camera_disable_flags();
    }
}
