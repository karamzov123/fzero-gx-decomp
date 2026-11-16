#include "types.h"

struct fn_16_6B24_lbl_16_rodata_58 {
    u8 pad_0[0x10];
    f32 unk_10;
    u8 pad_14[0x18];
    f32 unk_2C;
    u8 pad_30[0x3C];
    f32 unk_6C;
    u8 pad_70[0xD0];
    f32 unk_140;
    u8 pad_144[0x5C];
    f32 unk_1A0;
    f32 unk_1A4;
    u8 pad_1A8[0x34];
    f32 unk_1DC;
    f32 unk_1E0;
};

struct fn_16_6B24_lbl_1_bss_8B614 {
    u8 pad_0[0xA];
    s16 unk_A;
    s16 unk_C;
    u8 pad_E[0x1E];
    s32 unk_2C;
};

struct fn_16_6B24_lbl_16_data_82F28 {
    u8 pad_0[0xC0];
    u32 unk_C0[1];
    u8 pad_C4[0x14];
    u32 unk_D8[1];
    u8 pad_DC[0x14];
    u32 unk_F0[1];
};

struct fn_16_6B24_loc {
    u8 pad_0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad_18[0x18];
    s32 unk_30;
    u8 pad_34[0x24];
};

extern struct fn_16_6B24_lbl_16_data_82F28 lbl_16_data_82F28;
extern struct fn_16_6B24_lbl_16_rodata_58 lbl_16_rodata_58;
extern struct fn_16_6B24_lbl_1_bss_8B614 lbl_1_bss_8B614;
extern struct fn_16_6B24_loc lbl_1_rodata_26F8;
extern f32 lbl_16_bss_154[50];
extern char lbl_16_data_83500[33];

extern s32 fn_1_A5DC4(void);
extern u32 fn_16_2560(u32);
extern u32 fn_16_2EEC(u32, u32, u32);
extern u32 fn_16_3BCC(u32, u32, u32);
extern void fn_16_69B8(void);
extern u32 fn_1_49410(void);
extern void fn_1_133DBC(void *);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_4965C(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_8D3F8(void *, void *, void *, void *);

static inline u32 fn_16_6B24_array_read(u32 *array, s32 index) { return array[index]; }
void fn_16_6B24(void) {
    struct fn_16_6B24_lbl_16_rodata_58 *p_lbl_16_rodata_58;
    struct fn_16_6B24_lbl_1_bss_8B614 *p_lbl_1_bss_8B614;
    struct fn_16_6B24_loc loc_8;
    f32 v0;
    f32 v1;

    p_lbl_16_rodata_58 = (struct fn_16_6B24_lbl_16_rodata_58 *)&lbl_16_rodata_58;
    loc_8 = lbl_1_rodata_26F8;
    loc_8.unk_4 = p_lbl_16_rodata_58->unk_140;
    loc_8.unk_8 = p_lbl_16_rodata_58->unk_1A0;
    loc_8.unk_C = p_lbl_16_rodata_58->unk_1A4;
    if ((s8)fn_1_A5DC4() != 0) {
    loc_8.unk_10 = loc_8.unk_10 * p_lbl_16_rodata_58->unk_1DC;
    loc_8.unk_14 = loc_8.unk_14 * p_lbl_16_rodata_58->unk_1DC;
    }
    loc_8.unk_30 = 10;
    fn_1_8D3F8(lbl_16_bss_154, &loc_8, (void *)fn_16_69B8, &lbl_1_bss_8B614);
    fn_1_133DBC(0);
    p_lbl_1_bss_8B614 = (struct fn_16_6B24_lbl_1_bss_8B614 *)&lbl_1_bss_8B614;
    if (p_lbl_1_bss_8B614->unk_2C == 0) {
    fn_16_2560(p_lbl_1_bss_8B614->unk_C);
    if ((s8)fn_1_A5DC4() != 0) {
    fn_16_2EEC(p_lbl_1_bss_8B614->unk_C, -70, 102);
    } else {
    fn_16_2EEC(p_lbl_1_bss_8B614->unk_C, 24, 102);
    }
    fn_16_3BCC(p_lbl_1_bss_8B614->unk_C, 616, 439);
    }
    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_4965C(2);
    v1 = p_lbl_16_rodata_58->unk_2C;
    fn_1_4955C(v1, v1);
    fn_1_495C8(16);
    if ((s8)fn_1_A5DC4() != 0) {
    fn_1_496FC(p_lbl_16_rodata_58->unk_1E0, p_lbl_16_rodata_58->unk_10);
    } else {
    fn_1_496FC(p_lbl_16_rodata_58->unk_6C, p_lbl_16_rodata_58->unk_10);
    }
    fn_1_4AE0C(lbl_16_data_83500,
    fn_16_6B24_array_read(lbl_16_data_82F28.unk_C0, lbl_1_bss_8B614.unk_A),
    fn_16_6B24_array_read(lbl_16_data_82F28.unk_D8, lbl_1_bss_8B614.unk_A),
    fn_16_6B24_array_read(lbl_16_data_82F28.unk_F0, lbl_1_bss_8B614.unk_A));
}


