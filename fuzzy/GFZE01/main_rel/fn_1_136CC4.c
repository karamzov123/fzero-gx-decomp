/* Non-matching: best partial attempt (54.59% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"

typedef struct Sig_fn_1_5158C_FontDrawPacket Sig_fn_1_5158C_FontDrawPacket;
extern int fn_1_4F734(FontDrawPacket *);
extern u32 lbl_1_rodata_8A48;
extern u32 lbl_1_rodata_26F8[22];
extern const f32 lbl_1_rodata_8A4C;
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_87DC;
extern void fn_1_137288(int, u8 *, u8 *, u8 *, s16);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_1_5158C(Sig_fn_1_5158C_FontDrawPacket *, u32, s16, s16);

void fn_1_136CC4(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    FontDrawPacket packet;
    u32 loc_A[1];
    u8 loc_9;
    u8 loc_8;

    *(u32 *)((u8 *)loc_A + 2) = lbl_1_rodata_8A48;
    fn_1_137288(arg2, (u8 *)loc_A + 2, &loc_9, &loc_8, arg3);
    fn_1_51564(0, 0, 64, 20, 1, 3);

    packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = (u32)0xFFFF9A20;
    packet.x = (f32)(arg0 + 2);
    packet.y = (f32)arg1;
    packet.z = lbl_1_rodata_87DC;
    packet.scale_x *= lbl_1_rodata_8A4C;
    packet.scale_y *= lbl_1_rodata_8A4C;
    packet.flags = 9;
    fn_1_5158C((Sig_fn_1_5158C_FontDrawPacket *)&packet, 0xFFFF9A20, 0, 0);
    fn_1_4F734(&packet);

    packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
    packet.x = (f32)(arg0 + 0x5B);
    packet.y = (f32)arg1;
    packet.z = lbl_1_rodata_87DC;
    packet.scale_x *= lbl_1_rodata_8A4C;
    packet.scale_y *= lbl_1_rodata_8A4C;
    packet.flags = 9;
    fn_1_5158C((Sig_fn_1_5158C_FontDrawPacket *)&packet, 0xFFFF9A20, 0, 1);
    fn_1_4F734(&packet);

    packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
    packet.x = (f32)(arg0 + 0xB3);
    packet.y = (f32)arg1;
    packet.z = lbl_1_rodata_87DC;
    packet.scale_x *= lbl_1_rodata_8A4C;
    packet.scale_y *= lbl_1_rodata_8A4C;
    packet.flags = 9;
    fn_1_5158C((Sig_fn_1_5158C_FontDrawPacket *)&packet, 0xFFFF9A20, 0, 2);
    fn_1_4F734(&packet);

    fn_1_51564(0, 0, 16, 16, 3, 2);

    packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = (u32)0xFFFF9A21;
    packet.x = (f32)(arg0 + 0x4A);
    packet.y = (f32)arg1;
    packet.z = lbl_1_rodata_87DC;
    packet.scale_x *= lbl_1_rodata_8A4C;
    packet.scale_y *= lbl_1_rodata_8A4C;
    packet.flags = 10;
    *(u32 *)((u8 *)&packet + 56) = *(u32 *)((u8 *)loc_A + 2);
    {
        s32 div = loc_8 / 3;
        fn_1_5158C((Sig_fn_1_5158C_FontDrawPacket *)&packet, 0xFFFF9A21, (s16)(loc_8 - div * 3), (s16)div);
    }
    fn_1_4F734(&packet);

    packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = (u32)0xFFFF9A21;
    packet.x = (f32)(arg0 + 0xA2);
    packet.y = (f32)arg1;
    packet.z = lbl_1_rodata_87DC;
    packet.scale_x *= lbl_1_rodata_8A4C;
    packet.scale_y *= lbl_1_rodata_8A4C;
    packet.flags = 10;
    *(u32 *)((u8 *)&packet + 56) = *(u32 *)((u8 *)loc_A + 2);
    {
        s32 div = loc_9 / 3;
        fn_1_5158C((Sig_fn_1_5158C_FontDrawPacket *)&packet, 0xFFFF9A21, (s16)(loc_9 - div * 3), (s16)div);
    }
    fn_1_4F734(&packet);

    packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = (u32)0xFFFF9A21;
    packet.x = (f32)(arg0 + 0xFA);
    packet.y = (f32)arg1;
    packet.z = lbl_1_rodata_87DC;
    packet.scale_x *= lbl_1_rodata_8A4C;
    packet.scale_y *= lbl_1_rodata_8A4C;
    packet.flags = 10;
    *(u32 *)((u8 *)&packet + 56) = *(u32 *)((u8 *)loc_A + 2);
    {
        s32 div = *((u8 *)loc_A + 2) / 3;
        fn_1_5158C((Sig_fn_1_5158C_FontDrawPacket *)&packet, 0xFFFF9A21, (s16)(*((u8 *)loc_A + 2) - div * 3), (s16)div);
    }
    fn_1_4F734(&packet);
}
