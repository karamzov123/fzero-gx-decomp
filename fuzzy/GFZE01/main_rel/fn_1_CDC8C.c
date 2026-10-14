/* Non-matching: best partial attempt (96.68% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"

struct fn_1_CDC8C_Copy88 { u32 a[22]; };
struct fn_1_CDC8C_lbl_1_bss_84 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
};
struct fn_1_CDC8C_lbl_1_data_3D544 {
    u32 unk_0[1];
};
extern f32 lbl_1_rodata_5C7C;
extern f32 lbl_1_rodata_5C80;
extern f32 lbl_1_rodata_5CCC;
extern f32 lbl_1_rodata_5CFC;
extern f32 lbl_1_rodata_5D04;
extern f32 lbl_1_rodata_5D18;
extern f32 lbl_1_rodata_5D90;
extern f32 lbl_1_rodata_5DC8;
extern f32 lbl_1_rodata_5DBC;
extern f32 lbl_1_rodata_5DCC;
extern f32 lbl_1_rodata_5E24;
extern f32 lbl_1_rodata_5E90;
extern f32 lbl_1_rodata_5E94;
extern f32 lbl_1_rodata_5F2C;
extern f32 lbl_1_rodata_5F30;
extern f32 lbl_1_rodata_5F34;
extern f32 lbl_1_rodata_5F38;
extern f32 lbl_1_rodata_5F3C;
extern f32 lbl_1_rodata_5F40;
extern f32 lbl_1_rodata_5F44;
extern f32 lbl_1_rodata_5F48;
extern f32 lbl_1_rodata_5F4C;
extern f32 lbl_1_rodata_5F50;
extern f32 lbl_1_rodata_5F54;
extern f32 lbl_1_rodata_5F58;
extern f32 lbl_1_rodata_5F5C;
extern f32 lbl_1_rodata_5F60;
extern f32 lbl_1_rodata_5F64;
extern f32 lbl_1_rodata_5F68;
extern f32 lbl_1_rodata_5F6C;
extern f32 lbl_1_rodata_5F70;
extern f32 lbl_1_rodata_5F74;
extern f32 lbl_1_rodata_5F78;
extern f32 lbl_1_rodata_5F7C;
extern f32 lbl_1_rodata_5F80;
extern f32 lbl_1_rodata_5F84;
extern f32 lbl_1_rodata_5F88;
extern f32 lbl_1_rodata_5F8C;
extern f32 lbl_1_rodata_5F90;
extern f32 lbl_1_rodata_5F94;
extern f32 lbl_1_rodata_5F98;
extern f32 lbl_1_rodata_5F9C;
extern f32 lbl_1_rodata_5FA0;
extern f32 lbl_1_rodata_5FA4;
extern f32 lbl_1_rodata_5FA8;
extern f32 lbl_1_rodata_5FAC;
extern f32 lbl_1_rodata_5FB0;
extern f32 lbl_1_rodata_5FB4;
extern f64 lbl_1_rodata_5C00;
extern f64 lbl_1_rodata_5CE8;
extern u32 lbl_1_rodata_5F20;
extern u32 lbl_1_rodata_5F24;
extern u32 lbl_1_rodata_5F28;
extern u32 lbl_1_rodata_26F8;
extern struct fn_1_CDC8C_lbl_1_bss_84 lbl_1_bss_84;
extern struct fn_1_CDC8C_lbl_1_data_3D544 lbl_1_data_3D544;
extern void fn_1_CF5B0(u32);
extern u32 fn_1_5910(void);
extern u32 fn_1_58C4(void);
extern void fn_1_52070(u32);
extern int fn_1_4F734(FontDrawPacket *);
extern s32 fn_1_E5430(s32);
extern s32 fn_1_E5568(s32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern void fn_1_52088(void);

static struct fn_1_CDC8C_Copy88 lbl_1_rodata_26F8_copy(void) {
    return *(const struct fn_1_CDC8C_Copy88 *)((u8 *)&lbl_1_rodata_26F8);
}

#pragma opt_propagation off
void fn_1_CDC8C(void) {
    u32 * fzgx_live;
    struct fn_1_CDC8C_Copy88 loc_B8;
    FontDrawPacket loc_60;
    FontDrawPacket loc_8;
    f32 temp_f26;
    f32 temp_f26_2;
    f32 temp_f26_3;
    struct { f32 value; } temp_f27;
    struct { f32 value; } temp_f27_2;
    f64 temp_f28;
    f32 temp_f29;
    f32 temp_f29_2;
    f32 temp_f30;
    f32 var_f26;
    f32 var_f26_2;
    f32 var_f26_3;
    f32 var_f29;
    struct { f32 value; } var_f30;
    struct { f32 value; } var_f31;
    f32 temp_f1;
    s32 var_r26;
    s32 var_r26_2;
    s32 var_r27;
    s32 var_r27_2;
    s32 var_r28;
    s32 var_r28_2;
    s32 temp_r0;
    s32 temp_r25;
    s32 temp_r25_2;
    struct { s8 value; } temp_r28_5;
    s32 temp_r3;
    struct { s8 value; } var_r6;
    u32 v;
    u32 lab_t1;
    v = 0;
    if (lbl_1_bss_84.unk_0 != 0) {
        v = *(u32 *)((u8 *)lbl_1_bss_84.unk_0 + 0);
    }
    fn_1_CF5B0(v);

    if (((*(u32 *)&((&lbl_1_data_3D544)[fn_1_5910()])) >> 0xEU) & 1) {
        if (fn_1_58C4() == 1) {
            fn_1_52070((u32)(0xA0U));
        }
        loc_B8 = lbl_1_rodata_26F8_copy();
        loc_B8.a[0] = 0xBA0D;
        *(f32 *)((u8 *)(&loc_B8) + 4) = lbl_1_rodata_5F2C;
        *(f32 *)((u8 *)(&loc_B8) + 8) = lbl_1_rodata_5D18;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_B8));
        temp_r28_5.value = (s8)fn_1_E5430(1);
        temp_r3 = fn_1_E5568(1);
        temp_r0 = (s8)(temp_r28_5.value - temp_r3);
        var_f26 = lbl_1_rodata_5CFC;
        var_r6.value = temp_r0;
        if (lbl_1_bss_84.unk_0 != 0) {
            s32 n = *(s32 *)((u8 *)lbl_1_bss_84.unk_0 + 0);
            if (n > 0) {
                var_r6.value = temp_r0;
                var_r6.value -= 1;
                if (n <= 0xF) {
                    var_f26 = (f32)n / lbl_1_rodata_5D04;
                }
            }
        }
        loc_B8 = lbl_1_rodata_26F8_copy();
        loc_B8.a[0] = 0xBA1D;
        temp_r25 = var_r6.value / 10;
        lab_t1 = (u32)(0xBA1DU);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_B8), lab_t1, (s16)((s16) ((s8) temp_r25 * 0x12)), (s16)(0), (s16)(0x12), (s16)(0x18));
        *(f32 *)((u8 *)(&loc_B8) + 4) = lbl_1_rodata_5F30;
        *(f32 *)((u8 *)(&loc_B8) + 8) = lbl_1_rodata_5F34;
        fzgx_live = loc_B8.a;
        fzgx_live[0xC] = 9;
        if ((s8) temp_r25 != (s8) (temp_r0 / 10)) {
            *(f32 *)((u8 *)(&loc_B8) + 20) = var_f26;
            *(f32 *)((u8 *)(&loc_B8) + 44) = var_f26;
        }
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_B8));
        loc_B8 = lbl_1_rodata_26F8_copy();
        loc_B8.a[0] = 0xBA1D;
        temp_r25_2 = var_r6.value % 10;
        lab_t1 = (u32)(0xBA1DU);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_B8), lab_t1, (s16)((s16) ((s8) temp_r25_2 * 0x12)), (s16)(0), (s16)(0x12), (s16)(0x18));
        *(f32 *)((u8 *)(&loc_B8) + 4) = lbl_1_rodata_5F38;
        *(f32 *)((u8 *)(&loc_B8) + 8) = lbl_1_rodata_5F34;
        loc_B8.a[0xC] = 9;
        if ((s8) temp_r25_2 != (s8) ((temp_r28_5.value - temp_r3) % 10)) {
            *(f32 *)((u8 *)(&loc_B8) + 20) = var_f26;
            *(f32 *)((u8 *)(&loc_B8) + 44) = var_f26;
        }
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_B8));
        loc_B8 = lbl_1_rodata_26F8_copy();
        loc_B8.a[0] = 0xBA1D;
        lab_t1 = (u32)(0xBA1DU);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_B8), lab_t1, (s16)((s16) ((s8) (temp_r28_5.value / 10) * 0x12)), (s16)(0), (s16)(0x12), (s16)(0x18));
        *(f32 *)((u8 *)(&loc_B8) + 4) = lbl_1_rodata_5F3C;
        *(f32 *)((u8 *)(&loc_B8) + 8) = lbl_1_rodata_5F34;
        loc_B8.a[0xC] = 9;
        loc_B8.a[0xE] = lbl_1_rodata_5F20;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_B8));
        loc_B8 = lbl_1_rodata_26F8_copy();
        loc_B8.a[0] = 0xBA1D;
        lab_t1 = (u32)(0xBA1DU);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_B8), lab_t1, (s16)((s16) ((s8) (temp_r28_5.value % 10) * 0x12)), (s16)(0), (s16)(0x12), (s16)(0x18));
        *(f32 *)((u8 *)(&loc_B8) + 4) = lbl_1_rodata_5F40;
        *(f32 *)((u8 *)(&loc_B8) + 8) = lbl_1_rodata_5F34;
        loc_B8.a[0xC] = 9;
        loc_B8.a[0xE] = lbl_1_rodata_5F24;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_B8));
        loc_B8 = lbl_1_rodata_26F8_copy();
        loc_B8.a[0] = 0xBA1E;
        *(f32 *)((u8 *)(&loc_B8) + 4) = lbl_1_rodata_5F44;
        *(f32 *)((u8 *)(&loc_B8) + 8) = lbl_1_rodata_5F48;
        loc_B8.a[0xE] = lbl_1_rodata_5F28;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_B8));
        fn_1_52088();
    }

    if (((*(u32 *)&((&lbl_1_data_3D544)[fn_1_5910()])) >> 0xDU) & 1) {
        var_r28 = 0;
        var_r27 = 0x320;
        if (fn_1_58C4() == 1) {
            fn_1_52070((u32)(0U));
        }
        if (lbl_1_bss_84.unk_4 != 0) {
            var_r28 = (s32) (*(f32 *)((u8 *)lbl_1_bss_84.unk_4 + 0));
        }
        if (lbl_1_bss_84.unk_10 != 0) {
            var_r27 = lbl_1_bss_84.unk_10;
        }
        loc_60 = *(const FontDrawPacket *)((u8 *)&lbl_1_rodata_26F8);
        loc_60.x = lbl_1_rodata_5CCC;
        loc_60.image = 0xBA10;
        loc_60.y = lbl_1_rodata_5F4C;
        loc_60.z = loc_60.z - lbl_1_rodata_5DC8;
        fn_1_4F734((FontDrawPacket *)(&loc_60));
        loc_60 = *(const FontDrawPacket *)((u8 *)&lbl_1_rodata_26F8);
        loc_60.x = lbl_1_rodata_5D18;
        loc_60.image = 0xBA14;
        loc_60.y = lbl_1_rodata_5DBC;
        loc_60.z = loc_60.z - lbl_1_rodata_5F50;
        fn_1_4F734((FontDrawPacket *)(&loc_60));
        loc_60 = *(const FontDrawPacket *)((u8 *)&lbl_1_rodata_26F8);
        loc_60.x = lbl_1_rodata_5F54;
        loc_60.image = 0xBA0F;
        loc_60.y = lbl_1_rodata_5F58;
        loc_60.z = loc_60.z - lbl_1_rodata_5F5C;
        fn_1_4F734((FontDrawPacket *)(&loc_60));
        loc_60 = *(const FontDrawPacket *)((u8 *)&lbl_1_rodata_26F8);
        loc_60.image = 0xBA20;
        loc_60.x = lbl_1_rodata_5F54;
        loc_60.y = lbl_1_rodata_5F58;
        loc_60.z = loc_60.z - lbl_1_rodata_5F60;
        loc_60.scale_y = lbl_1_rodata_5F64;
        fn_1_4F734((FontDrawPacket *)(&loc_60));
        var_f26_2 = lbl_1_rodata_5F68 - ((lbl_1_rodata_5F6C * (f32) (var_r28 - var_r27)) / lbl_1_rodata_5F70);
        if (var_f26_2 < lbl_1_rodata_5F74) {
            var_f26_2 = lbl_1_rodata_5F74;
        } else if (var_f26_2 > lbl_1_rodata_5F68) {
            var_f26_2 = lbl_1_rodata_5F68;
        }
        loc_60 = *(const FontDrawPacket *)((u8 *)&lbl_1_rodata_26F8);
        loc_60.image = 0xBA02;
        loc_60.x = lbl_1_rodata_5F78;
        loc_60.y = var_f26_2 - lbl_1_rodata_5E94;
        fn_1_4F734((FontDrawPacket *)(&loc_60));
        loc_60 = *(const FontDrawPacket *)((u8 *)&lbl_1_rodata_26F8);
        loc_60.image = 0xBA02;
        loc_60.x = lbl_1_rodata_5F7C;
        loc_60.y = var_f26_2 - lbl_1_rodata_5E94;
        loc_60.rotation_z = -0x8000;
        loc_60.flags = 0xF;
        fn_1_4F734((FontDrawPacket *)(&loc_60));
        loc_60 = *(const FontDrawPacket *)((u8 *)&lbl_1_rodata_26F8);
        loc_60.image = 0xBA1B;
        loc_60.x = lbl_1_rodata_5CCC;
        loc_60.y = var_f26_2;
        loc_60.z = loc_60.z - lbl_1_rodata_5F80;
        fn_1_4F734((FontDrawPacket *)(&loc_60));
        loc_60 = *(const FontDrawPacket *)((u8 *)&lbl_1_rodata_26F8);
        loc_60.image = 0xBA07;
        loc_60.x = lbl_1_rodata_5F84;
        loc_60.y = var_f26_2 - lbl_1_rodata_5DCC;
        fn_1_4F734((FontDrawPacket *)(&loc_60));
        temp_f26 = var_f26_2 - lbl_1_rodata_5C7C;
        temp_f29 = lbl_1_rodata_5F88;
        temp_f28 = lbl_1_rodata_5F8C;
        var_r26 = 0;
        while ((var_r26 < 5) && (var_r28 > 0)) {
block_27:
            loc_60 = *(const FontDrawPacket *)((u8 *)&lbl_1_rodata_26F8);
            lab_t1 = (u32)(0xBA04U);
            loc_60.image = 0xBA04;
            fn_1_51678((FontDrawPacket *)(&loc_60), lab_t1, (s16)((s16) ((s8) (var_r28 % 10) * 0x14)), (s16)(0), (s16)(0x14), (s16)(0x14));
            loc_60.y = temp_f26;
            temp_f27.value = temp_f28;
            temp_f27.value *= (f32) var_r26;
            loc_60.x = temp_f29 - temp_f27.value;
            fn_1_4F734((FontDrawPacket *)(&loc_60));
            var_r26 += 1;
            var_r28 = (s32) (var_r28 / 10);
        }
        if ((var_r26 == 0) && (var_r28 <= 0)) {
            goto block_27; /* Preserves the retail branch. */
        }
        temp_f30 = lbl_1_rodata_5F90;
        temp_f29_2 = lbl_1_rodata_5C80;
        temp_f27.value = lbl_1_rodata_5F94;
        var_r28_2 = 0;
        temp_f26_2 = lbl_1_rodata_5F98;
        while ((var_r28_2 < 3) && (var_r27 > 0)) {
            loc_60 = *(const FontDrawPacket *)((u8 *)&lbl_1_rodata_26F8);
            loc_60.image = 0xBA05;
            lab_t1 = (u32)(0xBA05U);
            fn_1_51678((FontDrawPacket *)(&loc_60), lab_t1, (s16)((s16) ((s8) (var_r27 % 10) * 0xC)), (s16)(0), (s16)(0xC), (s16)(0xC));
            loc_60.y = temp_f27.value;
            loc_60.scale_y = temp_f26_2;
            temp_f1 = temp_f29_2 * (f32) var_r28_2;
            loc_60.x = temp_f30 - temp_f1;
            fn_1_4F734((FontDrawPacket *)(&loc_60));
            var_r28_2 += 1;
            var_r27 /= 0xA;
        }
        loc_60 = *(const FontDrawPacket *)((u8 *)&lbl_1_rodata_26F8);
        loc_60.image = 0xBA00;
        loc_60.x = lbl_1_rodata_5F9C;
        loc_60.y = lbl_1_rodata_5FA0;
        fn_1_4F734((FontDrawPacket *)(&loc_60));
        fn_1_52088();
    }

    if (((*(u32 *)&((&lbl_1_data_3D544)[fn_1_5910()])) >> 0xCU) & 1) {
        var_f26_3 = lbl_1_rodata_5D90;
        if (fn_1_58C4() == 1) {
            fn_1_52070((u32)(0xA0U));
        }
        if ((lbl_1_bss_84.unk_C != 0) && (lbl_1_bss_84.unk_8 != 0)) {
            temp_f1 = *(f32 *)((u8 *)lbl_1_bss_84.unk_8 + 252);
            temp_f26_3 = (f32) (*(u8 *)((u8 *)lbl_1_bss_84.unk_C + 4));
            temp_f26_3 = temp_f1 * temp_f26_3;
            var_f26_3 = temp_f26_3 - (*(f32 *)((u8 *)lbl_1_bss_84.unk_8 + 248));
        }
        var_f31.value = lbl_1_rodata_5FA4;
        var_f30.value = lbl_1_rodata_5D18;
        var_f29 = lbl_1_rodata_5CFC;
        if (var_f26_3 < lbl_1_rodata_5E24) {
            var_f31.value = lbl_1_rodata_5FA8;
            var_f30.value = lbl_1_rodata_5FAC;
            var_f29 = lbl_1_rodata_5F98;
        }
        var_r27_2 = (s32) var_f26_3;
        loc_8 = *(const FontDrawPacket *)((u8 *)&lbl_1_rodata_26F8);
        loc_8.image = 0xBA13;
        loc_8.x = var_f31.value;
        loc_8.y = var_f30.value;
        loc_8.scale_x = loc_8.scale_x * var_f29;
        loc_8.scale_y = loc_8.scale_y * var_f29;
        fn_1_4F734((FontDrawPacket *)(&loc_8));
        loc_8 = *(const FontDrawPacket *)((u8 *)&lbl_1_rodata_26F8);
        loc_8.image = 0xBA08;
        loc_8.scale_x = loc_8.scale_x * var_f29;
        temp_f26_3 = lbl_1_rodata_5E90;
        temp_f26_3 = temp_f26_3 * var_f29;
        temp_f27_2.value = lbl_1_rodata_5FB0 * var_f29;
        loc_8.y = var_f30.value + temp_f26_3;
        loc_8.x = var_f31.value + temp_f27_2.value;
        loc_8.scale_y = loc_8.scale_y * var_f29;
        fn_1_4F734((FontDrawPacket *)(&loc_8));
{
    s32 fzgx_loop_var_r26_2_13635;
        temp_f26_3 = lbl_1_rodata_5FB4;
        temp_f27_2.value = lbl_1_rodata_5F78;
        fzgx_loop_var_r26_2_13635 = 0;
        while ((fzgx_loop_var_r26_2_13635 < 3) && (var_r27_2 > 0)) {
block_46:
            loc_8 = *(const FontDrawPacket *)((u8 *)&lbl_1_rodata_26F8);
            loc_8.image = 0xBA04;
            lab_t1 = (u32)(0xBA04U);
            fn_1_51678((FontDrawPacket *)(&loc_8), lab_t1, (s16)((s16) ((s8) (var_r27_2 % 10) * 0x14)), (s16)(0), (s16)(0x14), (s16)(0x14));
            loc_8.y = var_f30.value;
            loc_8.scale_x = loc_8.scale_x * var_f29;
            loc_8.scale_y = loc_8.scale_y * var_f29;
            temp_f1 = temp_f27_2.value * (f32) fzgx_loop_var_r26_2_13635;
            temp_f1 = temp_f26_3 - temp_f1;
            temp_f1 = temp_f1 * var_f29;
            loc_8.x = var_f31.value + temp_f1;
            fn_1_4F734((FontDrawPacket *)(&loc_8));
            fzgx_loop_var_r26_2_13635 += 1;
            var_r27_2 = (s32) (var_r27_2 / 10);
        }
    var_r26_2 = fzgx_loop_var_r26_2_13635;
}
        if ((var_r26_2 == 0) && (var_r27_2 <= 0)) {
            goto block_46; /* Preserves the retail branch. */
        }
        fn_1_52088();
    }
}
#pragma opt_propagation reset

