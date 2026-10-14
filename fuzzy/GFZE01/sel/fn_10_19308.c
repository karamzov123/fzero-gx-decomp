/* Non-matching: best partial attempt (86.66% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/sel/sel.h"

typedef struct {
    u8 pad_0[0xE];
    s16 unk_0E;
    u8 pad_10[0x10];
} Bss8B3A0_Player;

typedef struct {
    Bss8B3A0_Player players[4];
    u8 pad_80[0x14];
    u32 unk_94;
    u8 pad_98[0x6];
    s8 unk_9E;
    u8 pad_9F[0x41];
    u32 unk_E0[4];
    u32 unk_F0[4];
    u8 pad_100[0x10];
    s32 unk_110[4];
} Struct_8B3A0;

typedef struct {
    u32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    u8 pad_18[0x18];
    u32 unk_30;
    u8 pad_34[0x1C];
    void (*unk_50)(void);
    f32 unk_54;
} DrawPacket;

extern Struct_8B3A0 lbl_1_bss_8B3A0;
extern DrawPacket lbl_1_rodata_26F8;
extern u32 lbl_801A66A0;
extern u8 lbl_1_bss_8CA28;

extern s16 fn_1_12C7B8(s16);
extern s16 fn_10_0(s16 *, s16 *, s16, int);
extern void fn_1_51914(DrawPacket *);
extern s8 fn_1_A5DC4(void);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_1_5158C(DrawPacket *, u32, s16, s16);
extern void fn_1_51990(DrawPacket *);
extern void fn_1_4F734(DrawPacket *);
extern void fn_10_12E34(void);
extern void fn_1_8CED0(Obj_10_bss_5197C *, u16, u16);
extern void fn_1_8D1C8(Obj_10_bss_5197C *, void *, void *);
extern u32 fn_10_19924(void *);
extern s32 fn_1_4FC50(DrawPacket *, u32, u16, u16, u32);

void fn_10_19308(f32 arg0) {
    s16 var_8;
    s16 var_a;
    s16 var_c;
    DrawPacket packet3;
    DrawPacket packet;
    DrawPacket packet2;

    if (lbl_1_bss_8B3A0.unk_94 & 0x100) {
        s16 v1 = (s8)lbl_1_bss_8B3A0.unk_9E;
        s16 *ptr = &lbl_1_bss_8B3A0.players[v1].unk_0E;
        s16 val = fn_1_12C7B8(*ptr);
        s32 quotient;
        s32 remainder;
        s32 offset;
        int cond;

        fn_10_0(&var_a, &var_c, *ptr, 0);

        if (((Obj_10_bss_1C *)((u8 *)&lbl_10_bss_1C + var_c * 0x98 + var_a * 8))->unk_4 & 0x80000000) {
            return;
        }

        packet = lbl_1_rodata_26F8;

        quotient = val / 6;
        remainder = val % 6;

        packet.unk_00 = 0x9C04;
        packet.unk_10 *= (38.0f / 255.0f);
        packet.unk_14 *= (36.0f / 255.0f);
        packet.unk_04 = (2.0f / 255.0f) + (f32)remainder / 6.0f;
        packet.unk_08 = (2.0f / 255.0f) + (f32)quotient / 7.0f;

        fn_1_51914(&packet);

        packet2 = lbl_1_rodata_26F8;
        packet2.unk_00 = 0xA000;

        offset = (!fn_1_A5DC4()) ? 0x58 : 0x48;

        packet2.unk_04 = 640.0f - (f32)offset;
        packet2.unk_08 = 366.0f;
        packet2.unk_0C = 85.0f;
        packet2.unk_30 = 0x0400000A;

        fn_1_51564(0, 0, 0x78, 0x78, 6, 7);
        fn_1_5158C(&packet2, packet2.unk_00, (s16)remainder, (s16)quotient);

        packet2.unk_50 = fn_10_12E34;

        cond = 0;
        if (lbl_801A66A0 - lbl_1_bss_8B3A0.unk_E0[v1] > 30) {
            cond = 1;
        } else if (lbl_1_bss_8B3A0.unk_F0[v1] != 0 && lbl_1_bss_8B3A0.unk_110[v1] != 0) {
            cond = 1;
        }

        packet2.unk_54 = (f32)(cond != 0);

        fn_1_51990(&packet2);
        fn_1_4F734(&packet2);
    } else {
        s32 offset;
        s8 val;
        Obj_10_bss_5197C *obj;

        var_8 = (s8)lbl_1_bss_8B3A0.unk_9E;
        packet3 = lbl_1_rodata_26F8;

        offset = (!fn_1_A5DC4()) ? 0x58 : 0x48;

        val = (s8)((Obj_10_bss_5560C *)((u8 *)&lbl_10_bss_5560C + var_8 * 0x14))->unk_12;
        obj = &lbl_10_bss_5197C;

        packet3.unk_04 = 640.0f - (f32)offset;
        packet3.unk_08 = 366.0f;
        packet3.unk_0C = 85.0f;
        packet3.unk_30 = 0x0400000A;
        packet3.unk_50 = fn_10_12E34;
        packet3.unk_54 = (f32)(val == 4);

        if (val == 4) {
            fn_1_8CED0(obj, 0x70, 0x70);
            obj->unk_44 = 30.0f;
            fn_1_8D1C8(obj, (void *)fn_10_19924, &var_8);
        }

        if (lbl_1_bss_8CA28 != 0) {
            packet3.unk_10 *= 2.0f;
            packet3.unk_14 *= 2.0f;
        }

        fn_1_4FC50(&packet3, obj->unk_34, obj->unk_30, obj->unk_32, obj->unk_60);
    }
}
