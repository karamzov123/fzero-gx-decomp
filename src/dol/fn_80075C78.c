#include "types.h"


/* --- dol/fn_80075C78.c --- */
struct fn_80075C78_Arg0 {
    u32 unk_0;
    u8 pad_4[0x3C];
    u32 unk_40;
};

struct fn_80075C78_lbl_801A3220 {
    u8 pad_0[0x1C];
    u32 unk_1C;
    u32 unk_20;
};

extern struct fn_80075C78_lbl_801A3220 lbl_801A3220;
extern u32 lbl_801A6D5C;
extern u32 lbl_801A6D60;
extern void fn_800728A8(s32, s32, s32, s32);

void fn_80075C78(struct fn_80075C78_Arg0 *arg0) {
    struct fn_80075C78_lbl_801A3220 *p_lbl_801A3220;
    s32 v0;
    u32 v1;
    s32 v2;
    u32 unk_1;
    u32 unk_2;
    u32 v5;

    v0 = 4;
    v2 = 5;
    if ((s32)lbl_801A6D60 == -1) {
        v1 = arg0->unk_0;
        if ((v1 & 0x20) != 0) {
            v1 = arg0->unk_40;
            v0 = (v1 & 0xF);
        }
    } else {
        v0 = lbl_801A6D60;
    }
    if ((s32)lbl_801A6D5C == -1) {
        unk_1 = arg0->unk_0;
        if ((unk_1 & 0x40) != 0) {
            unk_2 = arg0->unk_40;
            v2 = ((unk_2 >> 4) & 0xF);
        }
    } else {
        v2 = lbl_801A6D5C;
    }
    p_lbl_801A3220 = (struct fn_80075C78_lbl_801A3220 *)&lbl_801A3220;
    if ((s32)p_lbl_801A3220->unk_1C != (s32)v0 ||
        (s32)p_lbl_801A3220->unk_20 != (s32)v2) {
        v5 = 1;
        fn_800728A8(v5, v0, v2, 0);
        p_lbl_801A3220->unk_1C = v0;
        v5 = (u32)&lbl_801A3220;
        *(u32 *)((u8 *)v5 + 32) = v2;
    }
}

/* --- dol/fn_80075D48.c --- */
struct fn_80075D48_Arg0 {
    u32 unk_0;
};
extern void fn_80073C6C(s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_80073620(s32, s32);

s32 fn_80072CC4(s32, s32, s32, s32, s32); /* extern */
s32 fn_80072D64(s32, s32, s32, s32, s32, s32); /* extern */
s32 fn_800734A8(s32, s32, s32, s32);        /* extern */

void fn_80075D48(void *arg0, void *arg1) {
    s16 temp_r0;
    s16 temp_r0_2;

    fn_80073C6C(*(s32 *)((u8 *)(arg0) + 0));
    fn_80072AB0(*(s32 *)((u8 *)(arg0) + 0), 0, 0);
    fn_800734A8(*(s32 *)((u8 *)(arg0) + 0), *(s32 *)((u8 *)(arg0) + 4), *(s32 *)((u8 *)(arg0) + 12), 4);
    temp_r0 = *(s16 *)((u8 *)(arg1) + 16);
    switch (temp_r0) {                              /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        fn_80072C24(*(s32 *)((u8 *)(arg0) + 0), 0xF, 8, 0xC, *(s32 *)((u8 *)(arg1) + 8));
        fn_80072D64(*(s32 *)((u8 *)(arg0) + 0), 0, 0, 0, 1, 0);
        break;
    case 2:                                         /* switch 1 */
        fn_80072C24(*(s32 *)((u8 *)(arg0) + 0), 0xF, 8, 0xC, *(s32 *)((u8 *)(arg1) + 8));
        fn_80072D64(*(s32 *)((u8 *)(arg0) + 0), 1, 0, 0, 1, 0);
        break;
    case 0:                                         /* switch 1 */
        fn_80072C24(*(s32 *)((u8 *)(arg0) + 0), 0xF, 8, *(s32 *)((u8 *)(arg1) + 8), 0xF);
        fn_80072D64(*(s32 *)((u8 *)(arg0) + 0), 0, 0, 0, 1, 0);
        break;
    case 4:                                         /* switch 1 */
        fn_80072C24(*(s32 *)((u8 *)(arg0) + 0), 0xF, 8, 0xA, 0xF);
        fn_80072D64(*(s32 *)((u8 *)(arg0) + 0), 0, 0, 0, 1, 3);
        fn_80072CC4(*(s32 *)((u8 *)(arg0) + 0), 7, 7, 7, *(s32 *)((u8 *)(arg1) + 12));
        fn_80072E20(*(s32 *)((u8 *)(arg0) + 0), 0, 0, 0, 1U, 0);
        (*(s32 *)((u8 *)(arg0) + 0)) = (s32) ((*(s32 *)((u8 *)(arg0) + 0)) + 1);
        fn_80073C6C(*(s32 *)((u8 *)(arg0) + 0));
        fn_80072AB0(*(s32 *)((u8 *)(arg0) + 0), 0, 0);
        fn_800734A8(*(s32 *)((u8 *)(arg0) + 0), *(s32 *)((u8 *)(arg0) + 4), *(s32 *)((u8 *)(arg0) + 12), 0xFF);
        fn_80072C24(*(s32 *)((u8 *)(arg0) + 0), *(s32 *)((u8 *)(arg1) + 8), 6, 9, 0xF);
        fn_80072D64(*(s32 *)((u8 *)(arg0) + 0), 0, 0, 0, 1, 0);
        break;
    case 3:                                         /* switch 1 */
        fn_80072C24(*(s32 *)((u8 *)(arg0) + 0), 0xF, 0xF, 0xF, *(s32 *)((u8 *)(arg1) + 8));
        fn_80072D64(*(s32 *)((u8 *)(arg0) + 0), 0, 0, 0, 1, 0);
        break;
    }
    temp_r0_2 = *(s16 *)((u8 *)(arg1) + 18);
    switch (temp_r0_2) {                            /* switch 2; irregular */
    case 1:                                         /* switch 2 */
        fn_80072CC4(*(s32 *)((u8 *)(arg0) + 0), 4, 7, 7, *(s32 *)((u8 *)(arg1) + 12));
        fn_80072E20(*(s32 *)((u8 *)(arg0) + 0), 0, 0, 0, 1U, 0);
        break;
    case 2:                                         /* switch 2 */
        fn_80072CC4(*(s32 *)((u8 *)(arg0) + 0), 4, 7, 7, *(s32 *)((u8 *)(arg1) + 12));
        fn_80072E20(*(s32 *)((u8 *)(arg0) + 0), 1, 0, 0, 1U, 0);
        break;
    case 0:                                         /* switch 2 */
        fn_80072CC4(*(s32 *)((u8 *)(arg0) + 0), 7, 4, *(s32 *)((u8 *)(arg1) + 12), 7);
        fn_80072E20(*(s32 *)((u8 *)(arg0) + 0), 0, 0, 0, 1U, 0);
        break;
    case 4:                                         /* switch 2 */
        fn_80072CC4(*(s32 *)((u8 *)(arg0) + 0), 7, 7, 7, 4);
        fn_80072E20(*(s32 *)((u8 *)(arg0) + 0), 0, 0, 0, 1U, 0);
        break;
    case 5:                                         /* switch 2 */
        fn_80073620(*(s32 *)((u8 *)(arg0) + 0), 0);
        fn_80072CC4(*(s32 *)((u8 *)(arg0) + 0), 7, 7, 7, 6);
        fn_80072E20(*(s32 *)((u8 *)(arg0) + 0), 0, 0, 0, 1U, 0);
        break;
    case 3:                                         /* switch 2 */
        fn_80072CC4(*(s32 *)((u8 *)(arg0) + 0), 7, 7, 7, *(s32 *)((u8 *)(arg1) + 12));
        fn_80072E20(*(s32 *)((u8 *)(arg0) + 0), 0, 0, 0, 1U, 0);
        break;
    }
    (*(s32 *)((u8 *)(arg0) + 0)) = (s32) ((*(s32 *)((u8 *)(arg0) + 0)) + 1);
    (*(s32 *)((u8 *)(arg0) + 4)) = (s32) ((*(s32 *)((u8 *)(arg0) + 4)) + 1);
}
