#include "types.h"
#include "font.h"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 20.0f;
    s = 10.0f;
    s = 0.6000000238418579f;
    s = 456.0f;
    s = 0.125f;
    s = 5.0f;
    s = 1.4444444179534912f;
    s = 1.0f;
    s = 46.0f;
    s = 52.0f;
    s = 0.5f;
    s = 71.0f;
    s = 22.0f;
    s = 98.0f;
    s = 93.38823699951172f;
    s = 0.7686274647712708f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table5[1] = {0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 32.0f;
    s = 28.0f;
    s = 69.0f;
    s = 338.0f;
    s = 504.0f;
    s = 24.0f;
    s = 8.0f;
    s = 0.7777777910232544f;
    s = 79.0f;
    s = 343.0f;
    s = 155.0f;
    s = 365.0f;
}
static const u32 fzgx_pool_table7[1] = {0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 44.0f;
    s = 248.0f;
    s = 6.0f;
}
#pragma section code_type ".text"

#define CLAMP01(v) (((v) < 0.0f) ? 0.0f : (((v) > 1.0f) ? 1.0f : (v)))

struct fn_16_2EEC_lbl_1_bss_8B614 {
    u8 pad_0[0xA];
    s16 unk_A;
    u8 pad_C[0x40];
    u32 unk_4C;
    u8 pad_50[0x2];
    s16 unk_52;
    s16 unk_54;
};
struct fn_16_2EEC_lbl_16_data_82F28 {
    u8 pad_0[0x78];
    const char *unk_78[1];
};

extern struct fn_16_2EEC_lbl_16_data_82F28 lbl_16_data_82F28;
extern struct fn_16_2EEC_lbl_1_bss_8B614 lbl_1_bss_8B614;
extern u32 lbl_16_data_83380[44];
extern const FontDrawPacket lbl_1_rodata_26F8;
extern void fn_1_52250(void);
extern void fn_1_50190(FontDrawPacket *, f32, f32, f32, f32, f32, f32);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495B0(u32);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4962C(void);
extern void fn_1_495A0(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49514(u32 *);
extern void fn_1_4954C(f32);
extern void fn_1_4965C(u8);
extern void fn_1_495C8(u8);
extern void *fn_1_7F49C(s16, s16, void *);

void fn_16_2EEC(s16 index, s16 x, s16 y) {
    FontDrawPacket packet;
    u32 buf[16];
    u32 color;
    f32 alpha;
    f32 ratio;
    f32 t0;
    f32 t1;
    s16 width;

    if (lbl_1_bss_8B614.unk_4C & 0x80000000) {
        /* the divide by 2.0f becomes a multiply by the pooled 0.5 */
        ratio = lbl_1_bss_8B614.unk_52 / (lbl_1_bss_8B614.unk_54 / 2.0f);
        t0 = CLAMP01(ratio);
        ratio = (lbl_1_bss_8B614.unk_52 - lbl_1_bss_8B614.unk_54 / 2.0f) / (lbl_1_bss_8B614.unk_54 / 2.0f);
        t1 = CLAMP01(ratio);
        if (lbl_1_bss_8B614.unk_4C & 0x10000000) {
            alpha = t1;
            width = (s16) (32.0f + (f32) (44.0f * t0));
        } else if (lbl_1_bss_8B614.unk_4C & 0x08000000) {
            width = (s16) (32.0f + (f32) (44.0f * (1.0f - t1)));
            alpha = 1.0f - t0;
        } else {
            alpha = 1.0f;
            width = 0x4C;
        }
    } else {
        width = 0x4C;
        alpha = 1.0f;
    }

    packet = lbl_1_rodata_26F8;
    packet.image = 0x9306;
    packet.x = x;
    packet.y = y;
    packet.z = 1.0f;
    packet.alpha = 0.6f;
    fn_1_50190(&packet, 248.0f, width, 5.0f, 5.0f, 24.0f, 8.0f);

    fn_1_49410();
    fn_1_494DC(5);
    fn_1_495B0(0x80000000);
    fn_1_49738((u32) fn_1_52250);
    fn_1_49748(5.0f);
    fn_1_4955C(0.7777778f, 0.7777778f);
    fn_1_4962C();
    fn_1_495A0(1.0f);
    fn_1_496FC(x + 10, y + 5);
    color = fzgx_pool_table7[0];
    fn_1_49514(&color);
    fn_1_4954C(0.5f);
    fn_1_4AE0C(lbl_16_data_82F28.unk_78[lbl_1_bss_8B614.unk_A]);

    packet = lbl_1_rodata_26F8;
    packet.image = lbl_16_data_83380[index];
    packet.x = x + 0x7C;
    packet.y = y + 0x29;
    if (lbl_1_bss_8B614.unk_A != 5) {
        packet.y += 6.0f;
    }
    packet.alpha = alpha;
    packet.z = 0.5f;
    packet.flags = 10;
    fn_1_4F734(&packet);

    if (lbl_1_bss_8B614.unk_A == 5) {
        fn_1_49410();
        fn_1_495B0(0x80000000);
        fn_1_4965C(2);
        fn_1_4955C(0.5f, 0.5f);
        fn_1_495C8(9);
        fn_1_496FC(x + 0x7C, y + 0x40);
        fn_1_495A0(alpha);
        fn_1_4954C(0.5f);
        fn_1_4AE0C(fn_1_7F49C(index, lbl_1_bss_8B614.unk_A, buf));
    }
}
