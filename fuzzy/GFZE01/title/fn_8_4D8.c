/* Non-matching: best partial attempt (90.36% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 lbl_8_bss_228;
extern u32 lbl_8_bss_22C;
extern const u8 lbl_8_rodata_0[];
extern u8 lbl_8_data_0[];
extern u8 lbl_1_bss_9C8[];
extern u8 lbl_1_bss_9F8[];
extern u8 lbl_1_bss_8B3A0[];
extern void fn_1_49410(void);
extern void fn_1_495C8(u8);
extern void fn_1_495FC(void);
extern void fn_1_4954C(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_49614(void);

struct fn_8_4D8_data {
    u8 pad_0[0x3D8];
    s16 tbl[2][2];
    char msg_1[12];
    char msg_2[20];
    char msg_3[16];
    char msg_4[12];
    char msg_5[12];
};

s32 fn_8_4D8(u32 *arg0) {
    s32 *p228 = (s32 *)&lbl_8_bss_228;
    struct fn_8_4D8_data *d = (struct fn_8_4D8_data *)&lbl_8_data_0;
    const u8 *ro = lbl_8_rodata_0;
    s16 *p = (s16 *)((u8 *)d + 0x3D8);
    s16 *q = p + 1;
    s32 i;
    s16 v;

    if (*p228 != 0) {
        *p228 = *p228 - 1;
    } else {
        i = (s32)lbl_8_bss_22C + 1;
        lbl_8_bss_22C = (u32)i;
        *p228 = p[i * 2];
    }

    v = q[lbl_8_bss_22C * 2];

    if (v == 6) {
        *arg0 = *arg0 & 0x70000000;
        return 2;
    }
    if (v == 0) {
        *arg0 = *arg0 & 0x70000000;
    } else {
        *arg0 = *arg0 | 4;
        fn_1_49410();
        fn_1_495C8(9);
        fn_1_495FC();
        fn_1_4954C(*(const f32 *)(ro + 0x38));
        switch (q[lbl_8_bss_22C * 2]) {
        case 1:
            fn_1_496FC(*(const f32 *)(ro + 0x00), *(const f32 *)(ro + 0x1C));
            fn_1_4A0D8(d->msg_1);
            break;
        case 2:
            fn_1_496FC(*(const f32 *)(ro + 0x00), *(const f32 *)(ro + 0x3C));
            fn_1_4A0D8(d->msg_2);
            break;
        case 3:
            fn_1_496FC(*(const f32 *)(ro + 0x00), *(const f32 *)(ro + 0x40));
            fn_1_4A0D8(d->msg_3);
            break;
        case 4:
            fn_1_496FC(*(const f32 *)(ro + 0x00), *(const f32 *)(ro + 0x1C));
            fn_1_4A0D8(d->msg_1);
            fn_1_496FC(*(const f32 *)(ro + 0x00), *(const f32 *)(ro + 0x40));
            fn_1_4A0D8(d->msg_3);
            fn_1_496FC(*(const f32 *)(ro + 0x00), *(const f32 *)(ro + 0x3C));
            fn_1_4A0D8(d->msg_2);
            break;
        case 5:
            fn_1_496FC(*(const f32 *)(ro + 0x00), *(const f32 *)(ro + 0x44));
            fn_1_4A0D8(d->msg_4);
            fn_1_496FC(*(const f32 *)(ro + 0x00), *(const f32 *)(ro + 0x40));
            fn_1_4A0D8(d->msg_5);
            break;
        }
        fn_1_49614();
    }

    if (*(const s8 *)(lbl_1_bss_9C8 + 0xA) == 0) {
        if ((*(const u16 *)(lbl_1_bss_9F8 + 8) & 8) != 0) {
            *(u8 *)(lbl_1_bss_8B3A0 + 0x9E) = 0;
        }
    }

    return 0;
}
