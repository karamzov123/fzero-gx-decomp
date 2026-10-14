/* Non-matching: best partial attempt (97.17% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    f32 unk_0;
    u8 pad_4[0x154];
    f32 unk_158;
    u8 pad_15C[0x4];
    f64 unk_160;
    f32 unk_168;
    f32 unk_16C;
} Ro_14_rodata_0;

typedef struct {
    u8 pad_0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    u8 pad_1C[0x8];
} Bss_14_bss_92C4;

typedef struct {
    u8 pad_0[0x88];
    u32 unk_88;
    u8 pad_8C[0x1C];
    f32 unk_A8;
    f32 unk_AC;
    f32 unk_B0;
} Bss_14_bss_8350_Target;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    union {
        u32 u[3];
        f32 f[3];
    } v;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
} Data_1_data_1E5C0;

extern u32 lbl_14_bss_110[20];
extern u32 lbl_14_bss_8350;
extern u8 lbl_14_bss_8354[0xEA0];
extern Ro_14_rodata_0 lbl_14_rodata_0;
extern Bss_14_bss_92C4 lbl_14_bss_92C4;
extern Data_1_data_1E5C0 lbl_1_data_1E5C0;

extern s16 fn_1_12C710(s32);
extern s32 fn_1_12CB04(s16);
extern f32 lbl_8006D188(u32);
extern void fn_8006F038(void *, void *, s16);
extern void lbl_8006DCDC(void);
extern u32 lbl_8006DCA4(void);
extern void fn_1_F7870(void *);
extern void fn_1_9250C(void *);

s32 fn_14_4460(void) {
    Bss_14_bss_8350_Target *target;
    Data_1_data_1E5C0 local;
    Ro_14_rodata_0 *ro;
    f32 neg1;
    f32 neg2;
    f32 a;
    f32 b;
    f32 zero;
    s32 result;
    u32 flags;
    s16 i;
    s16 count;
    s16 sel;
    s16 id;
    s32 off;

    sel = ((s16 *)&lbl_14_bss_110)[2];
    result = (u32)&lbl_14_bss_8354;
    count = 0;
    ro = &lbl_14_rodata_0;

    for (i = 0; (u32)i < 8; i++) {
        flags = ((u32 *)&lbl_14_bss_110[i * 2])[3];
        if (flags & 0x10) {
            if ((flags & 0x40) || (i == sel)) {
                result = lbl_14_bss_8350 + count * 0x4E0;
                break;
            }
            count++;
        }
    }

    target = (Bss_14_bss_8350_Target *)result;
    id = fn_1_12C710(target->unk_88);

    neg1 = -lbl_8006D188(0xEEE);
    lbl_14_bss_92C4.unk_4 = (f32)(ro->unk_160 * neg1);
    lbl_14_bss_92C4.unk_8 = ro->unk_168;
    neg2 = -lbl_8006D188(0x4EEE);
    lbl_14_bss_92C4.unk_C = (f32)(ro->unk_160 * neg2);
    lbl_14_bss_92C4.unk_10 = ro->unk_0;
    if (id == 10) {
        lbl_14_bss_92C4.unk_10 = ro->unk_16C;
    }
    lbl_14_bss_92C4.unk_14 = ro->unk_168;
    lbl_14_bss_92C4.unk_18 = ro->unk_0;
    fn_8006F038(&lbl_14_bss_92C4.unk_4, &lbl_14_bss_92C4.unk_10, 0);
    lbl_8006DCDC();

    a = lbl_1_data_1E5C0.v.f[0] * ro->unk_158;
    b = lbl_1_data_1E5C0.v.f[1] * ro->unk_158;
    local = lbl_1_data_1E5C0;
    local.v.f[0] = a - b;
    local.v.f[1] = a + b;
    local.v.f[2] = lbl_1_data_1E5C0.v.f[2];
    fn_1_F7870(&local);
    lbl_8006DCA4();

    target->unk_A8 = ro->unk_0;
    target->unk_AC = ro->unk_0;
    target->unk_B0 = ro->unk_0;
    fn_1_9250C(target);

    zero = ro->unk_0;
    off = 0;
    i = 0;
    while (i < (s16)fn_1_12CB04(id)) {
        target = (Bss_14_bss_8350_Target *)((u8 *)target + off + 0x4E0);
        target->unk_A8 = zero;
        target->unk_AC = zero;
        target->unk_B0 = zero;
        fn_1_9250C(target);
        off += 0x4E0;
        i++;
    }

    return 0;
}
