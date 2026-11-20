#include "types.h"
struct fn_80076CD4_Arg0 {
    u8 pad_0[0x12];
    u8 unk_12;
};
extern u32 lbl_801A3220[];
extern u32 lbl_801A6D44;
extern void fn_80073778(void *, s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_80075D48(void *, void *);
extern void fn_80073C6C(void *);
extern void fn_800729B0(s32, s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern u32 fn_800734A8(void *, u32, u32, u32);
extern void fn_80072C24(void *, s32, s32, s32, s32);
extern u32 fn_80072D64(void *, u32, u32, u32, u32, u32);
extern u32 fn_80072CC4(void *, u32, u32, u32, u32);
extern void fn_80072E20(void *, s32, s32, s32, u8, s32);
extern void fn_8007264C(u32, u32, u32, u32, u32);
extern u32 fn_800764A0(void *, void *, u32);
extern u32 fn_80076238(void *, void *, u32, u32);
extern u32 fn_8007698C(void *, void *);


s32 fn_80076CD4(void *arg0, void *arg1, s32 arg2, void *arg3, s32 arg_sp0) {
    s32 var_r5;
    void *temp_r3;
    u32 temp_r30;
    s32 temp_r3_2;
    s32 var_r29;
    u32 *var_r28;
    void *temp_r27;
    u16 *var_r26;
    s32 temp_r25;
    s32 temp_r25_2;
    s32 temp_r25_3;
    u32 *var_r24;
    s32 var_r23;
    s32 var_r22;
    s32 temp_r0;

    var_r23 = *((u8 *)(arg0) + 18);
    var_r26 = (u16 *)((u8 *)(arg0) + 0x16);
    var_r28 = (u32 *)((u8 *)(lbl_801A3220) + 0x24);
    var_r24 = (u32 *)((u8 *)(lbl_801A3220) + 0x34);
    var_r22 = 0;
    var_r29 = 4;
    while (var_r23 > 0) {
        temp_r27 = (void *)(arg2 + ((*var_r26) << 5));
        temp_r25 = *(s32 *)((u8 *)(temp_r27));
        temp_r30 = temp_r25 & 0x50A003;
        (*var_r28) = temp_r30;
        if (((*(u16 *)(var_r24)) != (*var_r26)) || ((*(s32 *)((u8 *)(temp_r27))) & 0x10000)) {
            temp_r3 = (*(void **)((u8 *)(temp_r27) + 8));
            if (temp_r3 != NULL) {
                fn_80073778(temp_r3, (*(s32 *)((u8 *)(arg1) + 12)));
                (*(u16 *)(var_r24)) = (*var_r26);
                goto block_5; /* Preserves the retail branch. */
            }
        } else {
block_5:
            (*(s16 *)((u8 *)(arg3) + 16)) = ((*(u32 *)((u8 *)(temp_r27) + 16)) & 0xF);
            (*(s16 *)((u8 *)(arg3) + 18)) = (((*(u32 *)((u8 *)(temp_r27) + 16)) >> 4U) & 0xF);
            if (temp_r30 == 0) {
                if ((*(s32 *)((u8 *)(temp_r27))) & 0x20000) {
                    temp_r0 = ((*(u32 *)((u8 *)(temp_r27) + 16)) >> 8U) & 3;
                    if (temp_r0 != 0) {
                        fn_800745A4((*(u32 *)((u8 *)(arg1) + 4)), (1), var_r29, ((temp_r0 * 3) + 0x30), (0U), (0x7DU));
                    } else {
                        fn_800745A4((*(u32 *)((u8 *)(arg1) + 4)), (1), var_r29, (0x24U), (0U), (0x7DU));
                    }
                } else {
                    fn_800745A4((*(u32 *)((u8 *)(arg1) + 4)), (1), var_r29, (0x3CU), (0U), (0x7DU));
                }
                fn_80075D48(arg1, arg3);
            } else if (temp_r25 & 0x2000) {
                temp_r25_2 = *(s32 *)((u8 *)(temp_r27));
                fn_80073C6C((*(void **)((u8 *)(arg1))));
                temp_r3_2 = temp_r25_2 & 0xC0000;
                switch (temp_r3_2) {                /* irregular */
                case 0x40000:
                    fn_800729B0((2), (0), (1), (2), (1));
                    fn_80072AB0((s32)(((*(void **)((u8 *)(arg1))))), (0), (2));
                    break;
                case 0x80000:
                    fn_800729B0((2), (0), (1), (2), (2));
                    fn_80072AB0((s32)(((*(void **)((u8 *)(arg1))))), (0), (2));
                    break;
                case 0xC0000:
                    fn_800729B0((2), (0), (1), (2), (3));
                    fn_80072AB0((s32)(((*(void **)((u8 *)(arg1))))), (0), (2));
                    break;
                default:
                    fn_80072AB0((s32)(((*(void **)((u8 *)(arg1))))), (0), (1));
                    break;
                }
                if (temp_r25_2 & 0x20000) {
                    fn_800745A4((*(u32 *)((u8 *)(arg1) + 4)), (1), var_r29, (0x24U), (0U), (0x7DU));
                } else {
                    fn_800745A4((*(u32 *)((u8 *)(arg1) + 4)), (1), var_r29, (0x3CU), (0U), (0x7DU));
                }
                fn_800734A8((*(void **)((u8 *)(arg1))), (*(u32 *)((u8 *)(arg1) + 4)), ((*(s32 *)((u8 *)(arg1) + 12))), (4U));
                fn_80072C24((*(void **)((u8 *)(arg1))), (0xF), (0xF), (0xF), (*(s32 *)((u8 *)(arg3) + 8)));
                fn_80072D64((*(void **)((u8 *)(arg1))), (0U), (0U), (0U), (1U), (0U));
                fn_80072CC4((*(void **)((u8 *)(arg1))), (7U), (4U), (*(u32 *)((u8 *)(arg3) + 12)), (7U));
                fn_80072E20((*(void **)((u8 *)(arg1))), (0), (0), (0), (1U), (0));
                (*(void **)((u8 *)(arg1))) = (((u8 *)((*(void **)((u8 *)(arg1)))) + 1));
                (*(u32 *)((u8 *)(arg1) + 4)) = ((*(u32 *)((u8 *)(arg1) + 4)) + 1);
            } else if (temp_r25 & 2) {
                temp_r25_3 = (*(u32 *)((u8 *)(arg1) + 4)) + 0xC;
                fn_8007264C((0U), (0x19U), (1U), (4U), (0U));
                fn_80073C6C((*(void **)((u8 *)(arg1))));
                fn_800745A4((*(u32 *)((u8 *)(arg1) + 4)), (1), var_r29, (0x3CU), (0U), (0x7DU));
                fn_800734A8((*(void **)((u8 *)(arg1))), (*(u32 *)((u8 *)(arg1) + 4)), ((*(s32 *)((u8 *)(arg1) + 12))), (4U));
                fn_80072AB0((s32)(((*(void **)((u8 *)(arg1))))), (0), (0));
                fn_80072C24((*(void **)((u8 *)(arg1))), (8), (0xF), (0xF), (*(s32 *)((u8 *)(arg3) + 8)));
                fn_80072D64((*(void **)((u8 *)(arg1))), (0U), (0U), (0U), (0U), (0U));
                fn_80072CC4((*(void **)((u8 *)(arg1))), (7U), (7U), (7U), (*(u32 *)((u8 *)(arg3) + 12)));
                fn_80072E20((*(void **)((u8 *)(arg1))), (0), (0), (0), (1U), (0));
                (*(void **)((u8 *)(arg1))) = (((u8 *)((*(void **)((u8 *)(arg1)))) + 1));
                (*(u32 *)((u8 *)(arg1) + 4)) = ((*(u32 *)((u8 *)(arg1) + 4)) + 1);
                fn_80073C6C((*(void **)((u8 *)(arg1))));
                fn_800745A4((*(u32 *)((u8 *)(arg1) + 4)), (2), temp_r25_3, (0x3CU), (0U), (0x7DU));
                fn_800734A8((*(void **)((u8 *)(arg1))), (*(u32 *)((u8 *)(arg1) + 4)), ((*(s32 *)((u8 *)(arg1) + 12))), (0xFFU));
                fn_80072AB0((s32)(((*(void **)((u8 *)(arg1))))), (0), (0));
                fn_80072C24((*(void **)((u8 *)(arg1))), (8), (0xF), (0xF), (0));
                fn_80072D64((*(void **)((u8 *)(arg1))), (1U), (0U), (0U), (1U), (0U));
                fn_80072CC4((*(void **)((u8 *)(arg1))), (7U), (7U), (7U), (0U));
                fn_80072E20((*(void **)((u8 *)(arg1))), (0), (0), (0), (1U), (0));
                (*(void **)((u8 *)(arg1))) = (((u8 *)((*(void **)((u8 *)(arg1)))) + 1));
                (*(u32 *)((u8 *)(arg1) + 4)) = ((*(u32 *)((u8 *)(arg1) + 4)) + 1);
            } else if (temp_r25 & 1) {
                if (temp_r25 & 0x100000) {
                    var_r5 = *((u8 *)(temp_r27) + 12);
                } else {
                    var_r5 = 0x80;
                }
                if ((s32) (lbl_801A6D44) != 0) {
                    fn_800764A0(arg1, arg3, var_r5);
                } else {
                    fn_80076238(arg1, arg3, var_r5, (temp_r25 & 0x400000));
                }
            } else {
                fn_8007698C(arg1, arg3);
            }
            var_r26 = (u16 *)((u8 *)(var_r26) + 2);
            (*(s32 *)((u8 *)(arg3) + 8)) = 0;
            var_r28 = (u32 *)((u8 *)(var_r28) + 4);
            var_r24 = (u32 *)((u8 *)(var_r24) + 2);
            var_r22 += 1;
            (*(u32 *)((u8 *)(arg3) + 12)) = 0U;
            var_r29 += 1;
            (*(s32 *)((u8 *)(arg1) + 12)) = ((*(s32 *)((u8 *)(arg1) + 12)) + 1);
        }
        var_r23 -= 1;
            }
    (*var_r28) = -1U;
    return var_r22;
}
