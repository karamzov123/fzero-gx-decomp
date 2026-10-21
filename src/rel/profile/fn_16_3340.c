#include "types.h"
#include "font.h"
#include "rel/profile/data/lbl_16_data_82F28.h"
#include "rel/profile/data/lbl_16_bss_B0B8.h"

struct ProfileMenuState {
    u8 pad0[0xA];
    s16 language;
    u8 padC[2];
    s16 scroll;
    u8 pad10[0x3C];
    u32 flags;
    u8 pad50[2];
    s16 timer;
    s16 duration;
};
extern struct ProfileMenuState lbl_1_bss_8B614;
struct fn_16_2528_lbl_16_bss_860C0 {
    s16 unk_0;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
};
extern struct fn_16_2528_lbl_16_bss_860C0 lbl_16_bss_860C0;
extern s16 lbl_16_bss_860B8[4];
extern const FontDrawPacket lbl_1_rodata_26F8;
extern const u32 lbl_16_rodata_AC[];
extern s32 fn_1_A5DC4(void);
extern u16 fn_1_A5DB0(void);
extern void fn_1_50190(void *, f32, f32, f32, f32, f32, f32);
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
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4965C(u8);
extern void fn_1_49590(f32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_4A0D8(const char *);
extern f32 lbl_8006D188(s32);
extern u16 fn_1_486C4(u32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_52250(void);
extern void fn_16_2528(void);

#pragma push
#pragma force_active on
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table_0[1] = { 0xFFFF0000 };
static void fzgx_pool_primer_a(void) {
    volatile f32 f; /* Preserve the native shared literal pool's first-use order. */
    volatile f64 d; /* Preserve the shared integer-to-float conversion constant's pool slot. */
    f = 20.0f;
    f = 10.0f;
    f = 0.6f;
    f = 456.0f;
    f = 0.125f;
    f = 5.0f;
    f = 1.4444444179534912f;
    f = 1.0f;
    f = 46.0f;
    f = 52.0f;
    f = 0.5f;
    f = 71.0f;
    f = 22.0f;
    f = 98.0f;
    f = 93.38823699951172f;
    f = 0.7686274647712708f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table_50[1] = { 0xFFFF0000 };
static void fzgx_pool_primer_b(void) {
    volatile f32 f; /* Preserve the native shared literal pool's first-use order. */
    f = 0.0f;
    f = 32.0f;
    f = 28.0f;
    f = 69.0f;
    f = 338.0f;
    f = 504.0f;
    f = 24.0f;
    f = 8.0f;
    f = 0.7777777910232544f;
    f = 79.0f;
    f = 343.0f;
    f = 155.0f;
    f = 365.0f;
}
static const u32 fzgx_pool_table_88[1] = { 0xFFFF0000 };
static void fzgx_pool_primer_c(void) {
    volatile f32 f; /* Keep the native shared literal pool in retail order. */
    f = 44.0f;
    f = 248.0f;
    f = 6.0f;
}
static const u32 fzgx_pool_table_98[1] = { 0xFFFF0000 };
#pragma pop

#define clamp01(v) ((v) < 0.0f ? 0.0f : ((v) > 1.0f ? 1.0f : (v)))
#define PF(p,o) (*(f32 *)((u8 *)&(p) + (o)))
#define PI(p,o) (*(u32 *)((u8 *)&(p) + (o)))

void fn_16_3340(s16 arg0) {
    FontDrawPacket packet;
    u32 color;
    f32 alpha;
    f32 offset;
    f32 progress;
    s16 shift;
    s32 height;
    struct ProfileMenuState *state;
    s32 textX;
    f32 half;
    f32 t;
    f32 scale;
    f32 pulse;
    state = (struct ProfileMenuState *)&lbl_1_bss_8B614;
    offset = (f32)(state->scroll * -22);
    shift = 0;
    if ((s8)fn_1_A5DC4()) {
        shift = 94;
    }
    t = (f32)fn_1_A5DB0() / 480.0f;
    lbl_16_bss_860C0.unk_4 = 520;
    lbl_16_bss_860C0.unk_2 = (s16)(s32)(142.0f * t);
    lbl_16_bss_860C0.unk_0 = 0;
    lbl_16_bss_860C0.unk_6 = 206;
    if ((lbl_1_bss_8B614.flags & 0x80000000) && (lbl_1_bss_8B614.flags & 0x02000000)) {
        progress = clamp01((f32)lbl_1_bss_8B614.timer / (f32)lbl_1_bss_8B614.duration);
        if (lbl_1_bss_8B614.duration > 0) {
            offset = (f32)((state->scroll - 1) * -22) - (f32)(22.0f * progress);
        } else {
            offset = (f32)(22.0f * progress) + (f32)((state->scroll + 1) * -22);
        }
    } else {
        progress = 1.0f;
    }
    if (lbl_1_bss_8B614.flags & 0x80000000) {
        if (lbl_1_bss_8B614.flags & 0x10000000) {
            t = clamp01((f32)lbl_1_bss_8B614.timer / ((f32)lbl_1_bss_8B614.duration / 2.0f));
            half = (f32)lbl_1_bss_8B614.duration / 2.0f;
            height = (s32)(32.0f + (f32)(236.0f * t));
            alpha = clamp01(((f32)lbl_1_bss_8B614.timer - half) / half);
        } else if (lbl_1_bss_8B614.flags & 0x08000000) {
            half = (f32)lbl_1_bss_8B614.duration / 2.0f;
            t = clamp01(((f32)lbl_1_bss_8B614.timer - half) / half);
            height = (s32)(32.0f + (f32)(236.0f * (1.0f - t)));
            alpha = 1.0f - clamp01((f32)lbl_1_bss_8B614.timer / half);
        } else {
            alpha = 1.0f;
            height = 268;
        }
    } else {
        height = 268;
        alpha = 1.0f;
    }
    packet = lbl_1_rodata_26F8;
    PI(packet,0) = 0x9306;
    PF(packet,4) = (f32)(24 - shift);
    PF(packet,8) = 102.0f;
    PF(packet,12) = 1.0f;
    PF(packet,44) = 0.6f;
    fn_1_50190(&packet, 248.0f, (f32)(s16)height, 5.0f, 5.0f, 24.0f, 8.0f);
    fn_1_49410();
    fn_1_494DC(5);
    fn_1_495B0(0x80000000);
    fn_1_49738((u32)fn_1_52250);
    fn_1_49748(5.0f);
    fn_1_4955C(0.7777778f, 0.7777778f);
    fn_1_4962C();
    fn_1_495A0(1.0f);
    textX = 34 - shift;
    fn_1_496FC((f32)textX, 107.0f);
    color = fzgx_pool_table_98[0];
    fn_1_49514(&color);
    fn_1_4954C(0.5f);
    fn_1_4AE0C((const char *)((&lbl_16_data_82F28.at_60)[lbl_1_bss_8B614.language]));
    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_4965C(2);
    fn_1_4955C(0.625f, 0.625f);
    switch (lbl_1_bss_8B614.language) {
    case 0:
        fn_1_49590(0.5f);
        break;
    case 5:
    default:
        break;
    }
    fn_1_496FC((f32)textX, 141.0f + offset);
    fn_1_495A0(alpha);
    fn_1_4954C(0.5f);
    fn_1_49738((u32)fn_16_2528);
    fn_1_4966C(0.0f, 7.0f);
    fn_1_4A0D8(lbl_16_bss_B0B8.biographies[arg0][lbl_1_bss_8B614.language]);
    if (state->scroll != 0) {
        pulse = lbl_8006D188((s32)(182.04445f * (f32)(180.0f * progress)));
        if (lbl_1_bss_8B614.duration > 0) {
            pulse = 0.0f;
        }
        packet = lbl_1_rodata_26F8;
        PI(packet,0) = 0x9300;
        PF(packet,4) = (f32)(144 - shift);
        PF(packet,8) = 134.0f;
        PF(packet,12) = 0.1f;
        PF(packet,44) = clamp01(alpha - (f32)(0.5f * pulse));
        PI(packet,48) = 10;
        PF(packet,16) *= 0.7529412f + (f32)(0.3f * pulse);
        PF(packet,20) *= 0.7529412f + (f32)(0.3f * pulse);
        fn_1_51678(&packet, PI(packet,0), 0, 0, 20, (s16)fn_1_486C4(PI(packet,0)));
        fn_1_4F734(&packet);
    }
    if ((s16)lbl_16_bss_860B8[0] - 10 - state->scroll > 0) {
        pulse = lbl_8006D188((s32)(182.04445f * (f32)(180.0f * progress)));
        if (lbl_1_bss_8B614.duration < 0) {
            pulse = 0.0f;
        }
        packet = lbl_1_rodata_26F8;
        PI(packet,0) = 0x9300;
        PF(packet,4) = (f32)(144 - shift);
        PF(packet,8) = 360.0f;
        PF(packet,12) = 0.1f;
        PF(packet,44) = clamp01(alpha - (f32)(0.5f * pulse));
        PI(packet,48) = 10;
        PF(packet,16) *= 0.7529412f + (f32)(0.3f * pulse);
        PF(packet,20) *= 0.7529412f + (f32)(0.3f * pulse);
        fn_1_51678(&packet, PI(packet,0), 20, 0, 20, (s16)fn_1_486C4(PI(packet,0)));
        fn_1_4F734(&packet);
    }
}
