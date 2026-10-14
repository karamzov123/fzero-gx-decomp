/* Non-matching: best partial attempt (69.66% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#include "rel/main_rel/ranking.h"

struct fn_1_157950_Copy88 { u32 a[22]; };
struct fn_1_157950_Entry {
    s16 unk_0;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
    u32 unk_8;
    s16 unk_C;
    s16 unk_E;
    u32 unk_10;
    u32 unk_14;
    const char *unk_18;
};
struct fn_1_157950_PacketFields {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x1C];
    f32 unk_2C;
    s32 unk_30;
};

extern f32 lbl_1_rodata_D920[14];
extern f32 lbl_1_rodata_26F8[22];
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_495C8(u8);
extern void fn_1_49590(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49514(u32 *);
extern void fn_1_494DC(s16);
extern void fn_1_4965C(u8);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_496FC(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_4CF3C(const char *, f32, ...);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_5233C(void);

void fn_1_157950(void) {
    struct fn_1_157950_Entry *entry = (struct fn_1_157950_Entry *)lbl_1_bss_8F568.unk_C;
    f32 time = 0.0f;
    f32 end = lbl_1_bss_8F568.unk_4 - lbl_1_rodata_D920[1] / lbl_1_bss_8F568.unk_8;
    f32 fraction;
    f32 blend;
    while (entry->unk_0 != -2) {
        time += (f32)entry->unk_0 / lbl_1_bss_8F568.unk_8;
        if (time < end && time > lbl_1_bss_8F568.unk_4) {
            f32 amount = lbl_1_bss_8F568.unk_8 * (time - end);
            fn_1_49410();
            fraction = 1.0f;
            if (amount < (f32)entry->unk_E) {
                fraction = amount / (f32)entry->unk_E;
            } else if (amount > lbl_1_rodata_D920[1] - (f32)entry->unk_E) {
                fraction = (lbl_1_rodata_D920[1] - amount) / (f32)entry->unk_E;
            }
            if (*(s32 *)((u8 *)&lbl_1_bss_8F568 + 0x18) < 30) {
                fraction = (f32)*(s32 *)((u8 *)&lbl_1_bss_8F568 + 0x18) / lbl_1_rodata_D920[3];
            }
            switch (entry->unk_10) {
            case 0:
                fn_1_495B0(0xC0000000);
                fn_1_49738((u32)fn_1_5233C);
                fn_1_49748(lbl_1_rodata_D920[4]);
                fn_1_495C8((u8)entry->unk_8);
                fn_1_49590(lbl_1_rodata_D920[5]);
                fn_1_4955C((f32)entry->unk_C / lbl_1_rodata_D920[6],
                           (f32)entry->unk_E / lbl_1_rodata_D920[6]);
                {
                    u32 val = entry->unk_14;
                    fn_1_49514(&val);
                }
                break;
            case 1:
                fn_1_494DC(5);
                fn_1_495B0(0xC0000000);
                fn_1_495C8((u8)entry->unk_8);
                fn_1_49590(lbl_1_rodata_D920[5]);
                fn_1_4955C((f32)entry->unk_C / lbl_1_rodata_D920[6],
                           (f32)entry->unk_E / lbl_1_rodata_D920[6]);
                {
                    u32 val = entry->unk_14;
                    fn_1_49514(&val);
                }
                break;
            case 2:
                fn_1_495B0(0xC0000000);
                fn_1_49738((u32)fn_1_5233C);
                fn_1_49748(lbl_1_rodata_D920[8]);
                fn_1_495C8((u8)entry->unk_8);
                fn_1_49590(lbl_1_rodata_D920[5]);
                fn_1_4955C((f32)entry->unk_C / lbl_1_rodata_D920[6],
                           (f32)entry->unk_E / lbl_1_rodata_D920[6]);
                {
                    u32 val = entry->unk_14;
                    fn_1_49514(&val);
                }
                break;
            case 6:
                fn_1_495B0(0xC0000000);
                fn_1_4965C(2);
                fn_1_49738((u32)fn_1_5233C);
                fn_1_49748(lbl_1_rodata_D920[2]);
                fn_1_495C8((u8)entry->unk_8);
                fn_1_49590(lbl_1_rodata_D920[5]);
                fn_1_4955C((f32)entry->unk_C / lbl_1_rodata_D920[6],
                           (f32)entry->unk_E / lbl_1_rodata_D920[6]);
                {
                    u32 val = entry->unk_14;
                    fn_1_49514(&val);
                }
                break;
            case 3:
            case 4: {
                struct fn_1_157950_Copy88 copy = *(struct fn_1_157950_Copy88 *)lbl_1_rodata_26F8;
                struct fn_1_157950_PacketFields *packet = (struct fn_1_157950_PacketFields *)&copy;
                packet->unk_0 = 0x100;
                packet->unk_4 = (f32)entry->unk_4;
                packet->unk_8 = amount;
                packet->unk_C = 0.1f;
                packet->unk_30 = 5;
                packet->unk_2C = fraction;
                fn_1_51678((FontDrawPacket *)&copy, 0x100, 0, (entry->unk_10 == 3) ? 0 : 0x12,
                           (entry->unk_10 == 3) ? 0x78 : 0xF8, 0x10);
                fn_1_4F734((FontDrawPacket *)&copy);
                break;
            }
            case 5: {
                struct fn_1_157950_Copy88 copy = *(struct fn_1_157950_Copy88 *)lbl_1_rodata_26F8;
                struct fn_1_157950_PacketFields *packet = (struct fn_1_157950_PacketFields *)&copy;
                packet->unk_0 = (u32)(0x10000 - 0x7900);
                packet->unk_4 = (f32)entry->unk_4;
                packet->unk_8 = amount;
                packet->unk_C = 0.1f;
                packet->unk_30 = 5;
                packet->unk_2C = fraction;
                fn_1_4F734((FontDrawPacket *)&copy);
                break;
            }
            default:
                break;
            }
            fn_1_496FC((f32)entry->unk_4, amount);
            fn_1_495A0(fraction);
            if (entry->unk_10 == 6) {
                fn_1_4AE0C(entry->unk_18);
            } else {
                fn_1_4CF3C(entry->unk_18, lbl_1_rodata_D920[10] - (f32)entry->unk_4);
            }
        }
        entry = (struct fn_1_157950_Entry *)((u8 *)entry + 0x1C);
    }
    if ((f32)entry->unk_2 < lbl_1_bss_8F568.unk_4) {
        *(s32 *)((u8 *)&lbl_1_bss_8F568 + 0x14) = 1;
    }
}
