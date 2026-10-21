#include "types.h"
struct fn_16_20F4_9F8 {
    u16 unk_0;
    u8 pad_2[0x6];
    u16 unk_8;
    u16 unk_A;
    u8 pad_C[0x6];
    u16 unk_12;
};
struct fn_16_20F4_8B614 {
    u8 pad_0[0x8];
    s16 unk_8;
    u8 pad_A[0xE];
    f32 unk_18;
    u8 pad_1C[0xC];
    s16 unk_28;
    s16 unk_2A;
    u32 unk_2C;
    s16 unk_30;
};
struct fn_16_20F4_A48 {
    s8 unk_0;
    s8 unk_1;
    u8 pad_2[0xE];
};
struct fn_16_20F4_BF0 {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0x10];
};
extern struct fn_16_20F4_8B614 lbl_1_bss_8B614;
extern struct fn_16_20F4_9F8 lbl_1_bss_9F8[];
extern struct fn_16_20F4_A48 lbl_1_bss_A48[];
extern struct fn_16_20F4_BF0 lbl_1_bss_BF0[];
extern const f32 lbl_16_rodata_0[22];
extern void fn_1_A2D84(u32);
#pragma opt_propagation off
#pragma opt_common_subs on
static inline const f32 *fn_16_20F4_array_read(const f32 *array) { return array; }
s32 fn_16_20F4(void) {
    struct { volatile u16 *value; } p; /* Controller flags are read on each test. */
    volatile u16 *q;
    s32 idx = lbl_1_bss_8B614.unk_8;
    s16 flag = 0;
    s32 a;
    s32 b;
    s32 t;
    f32 v;
    const f32 *pool = lbl_16_rodata_0;
    u32 c;
    a = lbl_1_bss_8B614.unk_2A + lbl_1_bss_A48[idx].unk_0 / 20;
    a = (a > 0x168) ? 0 : (a < 0 ? 0x168 : a);
    lbl_1_bss_8B614.unk_2A = a;
    b = lbl_1_bss_8B614.unk_28 + lbl_1_bss_A48[idx].unk_1 / 20;
    b = (b > 0x168) ? 0 : (b < 0 ? 0x168 : b);
    lbl_1_bss_8B614.unk_28 = b;
    v = lbl_1_bss_8B614.unk_18 + (f32)(lbl_1_bss_BF0[idx].unk_C * fn_16_20F4_array_read(pool)[6]);
    v = (v < fn_16_20F4_array_read(pool)[20]) ? fn_16_20F4_array_read(pool)[20]
      : (v > fn_16_20F4_array_read(pool)[21] ? fn_16_20F4_array_read(pool)[21] : v);
    lbl_1_bss_8B614.unk_18 = v;
    {
    s32 offset = idx * 20;
    p.value = (u16 *)((u8 *)lbl_1_bss_9F8 + offset);
    p.value += 4;
    if ((*p.value >> 4) & 1) {
        fn_1_A2D84(0xA9010000);
        lbl_1_bss_8B614.unk_2C = lbl_1_bss_8B614.unk_2C != 1;
    }
    q = (u16 *)((u32)lbl_1_bss_9F8 + offset + 18);
    }
    if ((*q >> 8) & 1) {
        flag = 1;
    }
    if ((*q >> 9) & 1) {
        flag--;
    }
    if (flag != 0) {
        t = lbl_1_bss_8B614.unk_30 + flag;
        t = (t > 3) ? 0 : (t < 0 ? 3 : t);
        lbl_1_bss_8B614.unk_30 = t;
        fn_1_A2D84(0xA9010000);
    }
    if ((*p.value >> 9) & 1) {
        fn_1_A2D84(0xA9010000 + 0x200);
        return -1;
    }
    return 0;
}
#pragma opt_propagation reset

