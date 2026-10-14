/* Non-matching: best partial attempt (98.68% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#include "rel/main_rel/enemy_ctrl.h"

extern u32 lbl_1_rodata_26F8;
extern const f32 lbl_1_rodata_6020;
extern const f64 lbl_1_rodata_6018;
extern const f32 lbl_1_rodata_6024;
extern const f32 lbl_1_rodata_5CFC;
extern u16 fn_1_48690(u32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);

#pragma opt_common_subs on
void fn_1_CFB28(f32 value) {
    s32 index;
    f64 cur;
    f64 d;
    FontDrawPacket packet;
    s16 lab_t5;

    switch (lbl_1_data_2A7E0.unk_0) {
    case 0:
        break;
    case 1:
    case 17:
    case 18:
        index = 0;
        break;
    case 2:
    case 3:
        index = 1;
        break;
    case 4:
    case 5:
        index = 2;
        break;
    case 6:
    case 7:
        index = 3;
        break;
    case 8:
    case 9:
        index = 4;
        break;
    case 10:
        index = 5;
        break;
    case 11:
    case 12:
        index = 6;
        break;
    case 13:
        index = 7;
        break;
    case 14:
        index = 8;
        break;
    case 15:
        index = 9;
        break;
    case 16:
        index = 10;
        break;
    case 19:
        index = 11;
        break;
    }

    packet = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    packet.image = (0x10000 - 0x4500);
    lab_t5 = 36;
    fn_1_51678(&packet, packet.image, 0, (s16)(((36) * (index))), (s16)fn_1_48690(packet.image), lab_t5);

    d = (lbl_1_rodata_6020 - lbl_1_data_3D554) * lbl_1_rodata_6018;
    cur = (f32)(lbl_1_data_3D554 + d);
    *(f32 *)(((0x8) + ((u8 *)&packet))) = lbl_1_rodata_6024;
    *(f32 *)((u8 *)&packet + 0xC) = lbl_1_rodata_5CFC;
    *(f32 *)((u8 *)&packet + 0x2C) = value;
    *(u32 *)((u8 *)&packet + 0x30) = 10;
    lbl_1_data_3D554 = cur;
    *(f32 *)((u8 *)&packet + 0x4) = lbl_1_data_3D554;
    fn_1_4F734(&packet);
}
#pragma opt_common_subs reset

