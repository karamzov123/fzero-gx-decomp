/* Non-matching: best partial attempt (97.16% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#define FontDrawPacket FontDrawPacket_H
#include "font.h"
#undef FontDrawPacket

typedef struct FontDrawPacket FontDrawPacket;
struct FontDrawPacket {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_c;
    f32 unk_10;
    u8 pad_14[0x18];
    f32 unk_2c;
    u8 pad_30[0x28];
};


struct fn_16_2560_lbl_1_bss_8B614 {
    u8 pad_0[0xa];
    s16 unk_a;
};

extern struct fn_16_2560_lbl_1_bss_8B614 lbl_1_bss_8B614;
extern char lbl_16_data_82DB0[4];
extern const FontDrawPacket lbl_1_rodata_26F8;
extern const char *lbl_1_data_212A8[];
extern const char *lbl_1_data_21078[];

extern s32 fn_1_A5DC4(void);
extern u16 fn_1_486C4(u32);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495B0(u32);
extern void fn_1_52250(void);
extern void fn_1_49738(void (*)(void));
extern void fn_1_49748(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4962C(void);
extern void fn_1_495A0(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49644(void);
extern s16 fn_1_12C930(s32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4965C(u8);
extern void fn_1_4954C(f32);
extern void fn_1_49514(void *);
extern void fn_1_495C8(u8);
extern void fn_1_495FC(void);
extern f32 fn_1_4B068(const char *);
extern void fn_1_4A0D8(const char *);

void fn_16_2560(s32 arg0) {
    s32 id = arg0;
    struct fn_16_2560_lbl_1_bss_8B614 *bss;
    const char *data = lbl_16_data_82DB0;
    s32 var_r26 = 0;
    s32 var_r27 = 0;
    s16 var_r30;
    FontDrawPacket packet;

    if ((s8)fn_1_A5DC4() != 0) {
        var_r26 = 94;
        var_r27 = 110;
    }

    var_r30 = var_r27;

    packet = lbl_1_rodata_26F8;
    packet.unk_0 = 0x9305;
    packet.unk_4 = -var_r30;
    packet.unk_8 = 20.0f;
    packet.unk_c = 10.0f;
    packet.unk_2c = 0.6f;
    fn_1_51678((struct FontDrawPacket_H *)&packet, packet.unk_0, 0, 0, 8, fn_1_486C4(packet.unk_0));

    packet.unk_10 *= (456.0f + (f32)(var_r30 * 2)) * 0.125f;
    fn_1_4F734((struct FontDrawPacket_H *)&packet);

    packet = lbl_1_rodata_26F8;
    packet.unk_0 = 0x9305;
    packet.unk_4 = (f32)(var_r30 + 456);
    packet.unk_8 = 20.0f;
    packet.unk_c = 10.0f;
    packet.unk_2c = 0.6f;
    fn_1_51678((struct FontDrawPacket_H *)&packet, packet.unk_0, 8, 0, 24, fn_1_486C4(packet.unk_0));
    fn_1_4F734((struct FontDrawPacket_H *)&packet);

    packet = lbl_1_rodata_26F8;
    packet.unk_0 = 0x9305;
    packet.unk_4 = (f32)(var_r30 + 480);
    packet.unk_8 = 20.0f;
    packet.unk_c = 10.0f;
    packet.unk_2c = 0.6f;
    fn_1_51678((struct FontDrawPacket_H *)&packet, packet.unk_0, 32, 0, 8, fn_1_486C4(packet.unk_0));
    packet.unk_10 *= 20.0f;
    fn_1_4F734((struct FontDrawPacket_H *)&packet);

    fn_1_49410();
    fn_1_494DC(5);
    fn_1_495B0(0x80000000);
    fn_1_49738(fn_1_52250);
    fn_1_49748(5.0f);
    fn_1_4955C(1.4444444f, 1.4444444f);
    fn_1_4962C();
    fn_1_495A0(1.0f);

    var_r26 = (s16)var_r26;
    var_r27 = 24 - var_r26;
    fn_1_496FC((f32)var_r27, 46.0f);

    bss = &lbl_1_bss_8B614;
    if (bss->unk_a != 5) {
        fn_1_496FC((f32)var_r27, 52.0f);
    }

    if ((s16)id == 9) {
        fn_1_49644();
    }
    fn_1_4AE0C(lbl_1_data_212A8[fn_1_12C930(id)]);

    if (bss->unk_a == 5) {
        fn_1_49410();
        fn_1_495B0(0x80000000);
        fn_1_4965C(2);
        fn_1_4955C(0.5f, 0.5f);
        fn_1_495A0(1.0f);
        fn_1_496FC((f32)var_r27, 71.0f);
        fn_1_4AE0C(lbl_1_data_21078[fn_1_12C930(id)]);
    }

    fn_1_49410();
    fn_1_494DC(5);
    fn_1_495B0(0x80000000);
    fn_1_49738(fn_1_52250);
    fn_1_49748(5.0f);
    fn_1_4955C(1.0f, 1.0f);
    fn_1_4962C();
    fn_1_495A0(1.0f);
    fn_1_4954C(5.0f);
    fn_1_496FC((f32)(var_r26 + 616), 22.0f);

    {
        struct { u32 val; } col = { 0xffff0000 };
        fn_1_49514(&col.val);
    }
    fn_1_495C8(2);

    fn_1_4AE0C(data + 0x674, *(const char **)(data + 0x178 + bss->unk_a * 4), ((s16)id == 30) ? 0 : (((s16)id > 30) ? (s16)id : (s16)id + 1));

    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_4965C(2);
    fn_1_4955C(0.5f, 0.5f);
    fn_1_495FC();
    fn_1_495A0(1.0f);
    fn_1_4954C(5.0f);
    var_r26 += 624;
    fn_1_496FC((f32)var_r26, 98.0f);
    fn_1_495C8(2);

    switch (bss->unk_a) {
    case 5:
        fn_1_4AE0C(lbl_1_data_21078[fn_1_12C930(id)]);
        fn_1_496FC((f32)var_r26 - fn_1_4B068(lbl_1_data_21078[fn_1_12C930(id)]), 93.388237f);
        break;
    case 0:
    default:
        fn_1_4AE0C(lbl_1_data_212A8[fn_1_12C930(id)]);
        fn_1_496FC((f32)var_r26 - fn_1_4B068(lbl_1_data_212A8[fn_1_12C930(id)]), 93.388237f);
        break;
    }

    fn_1_4955C(0.76862746f, 0.76862746f);
    fn_1_4A0D8(data + 0x67c);
}
