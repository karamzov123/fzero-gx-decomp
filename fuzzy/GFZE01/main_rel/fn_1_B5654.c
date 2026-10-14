/* Non-matching: best partial attempt (88.84% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/memcard.h"
struct fn_1_B5654_lbl_1_rodata_4AE0 {
    u8 pad_0[0x1E0];
    f32 unk_1E0;
    u8 pad_1E4[0x10];
    u32 unk_1F4, unk_1F8, unk_1FC, unk_200;
    f32 unk_204;
    u8 pad_208[0x24];
    f32 unk_22C, unk_230, unk_234, unk_238, unk_23C, unk_240, unk_244;
    u8 pad_248[4];
    f32 unk_24C;
    u8 pad_250[8];
    f32 unk_258, unk_25C, unk_260;
    u32 unk_264, unk_268, unk_26C, unk_270, unk_274, unk_278, unk_27C, unk_280, unk_284;
    f32 unk_288, unk_28C, unk_290;
};
extern struct fn_1_B5654_lbl_1_rodata_4AE0 lbl_1_rodata_4AE0;
extern s32 lbl_801A66B4;
struct TextTable { u8 pad[0x348]; void *source[12]; const char *suffix0[6]; const char *suffix1[6]; const char *label0[6]; const char *label1[6]; };
extern u32 fn_1_4D4C8(void *, f32, f32);
extern u32 fn_80007F70(void *, void *, u32, f32);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_49514(u32 *);
extern void fn_1_49528(u32 *);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495A0(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_495FC(void);
extern void fn_1_49614(void);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D494(void);
extern void fn_1_B5258(char *, void *, const char *, const char *);

#pragma opt_common_subs off
static inline const char *text_lookup(struct TextTable *table, s32 index, s32 offset) { return *(const char **)((u8 *)table + (index << 2) + offset); }
#pragma peephole on
void fn_1_B5654(void) {
    Obj_1_bss_716C8 *selected;
    u8 *p_lbl_1_data_35AC8;
    struct fn_1_B5654_lbl_1_rodata_4AE0 *p_lbl_1_rodata_4AE0;
    f32 v0;
    struct TextTable *v1;
    const char *v2;
    const char *v3;
    struct {
        u32 loc_8, loc_C, loc_10, loc_14, loc_18, loc_1C, loc_20, loc_24, loc_28, loc_2C, loc_30, loc_34, loc_38, loc_3C, loc_40, loc_44, loc_48, loc_4C, loc_50;
        char loc_54[0x400];
    } frame;
    const char *lab_t2;
    p_lbl_1_data_35AC8 = (u8 *)&lbl_1_data_35AC8;
    p_lbl_1_rodata_4AE0 = &lbl_1_rodata_4AE0;
    v0 = (*(f32 volatile *)&p_lbl_1_rodata_4AE0->unk_1E0);
    frame.loc_48 = p_lbl_1_rodata_4AE0->unk_268;
    frame.loc_4C = p_lbl_1_rodata_4AE0->unk_264;
    frame.loc_50 = fn_80007F70(&frame.loc_4C, &frame.loc_48, lbl_1_bss_71808, v0);
    selected = (Obj_1_bss_716C8 *)((u8 *)&lbl_1_bss_716C8 + 0xA0);
    if (lbl_1_bss_716C8.unk_4 == 5) selected = &lbl_1_bss_716C8;
    fn_1_49410();
    fn_1_494DC(42);
    fn_1_495C8(9);
    fn_1_4954C(p_lbl_1_rodata_4AE0->unk_22C);
    frame.loc_44 = p_lbl_1_rodata_4AE0->unk_26C;
    fn_1_49514(&frame.loc_44);
    fn_1_49614();
    v0 = p_lbl_1_rodata_4AE0->unk_230;
    fn_1_4955C(v0, v0);
    fn_1_4966C(p_lbl_1_rodata_4AE0->unk_234, p_lbl_1_rodata_4AE0->unk_238);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(p_lbl_1_rodata_4AE0->unk_23C);
        fn_1_4966C(p_lbl_1_rodata_4AE0->unk_234, p_lbl_1_rodata_4AE0->unk_240);
    }
    fn_1_496FC(p_lbl_1_rodata_4AE0->unk_244, p_lbl_1_rodata_4AE0->unk_288);
    v1 = (struct TextTable *)(p_lbl_1_data_35AC8 + 0x5c84 + (lbl_801A66B4 << 2));
    lab_t2 = (const char *)(p_lbl_1_data_35AC8 + 0x7320);
    fn_1_B5258(frame.loc_54, v1->source[0], lab_t2, selected->unk_0 == 0 ? v1->suffix0[0] : v1->suffix1[0]);
    fn_1_B5258(frame.loc_54, frame.loc_54, (const char *)(p_lbl_1_data_35AC8 + 0x7320), selected->unk_0 == 0 ? text_lookup((struct TextTable *)(p_lbl_1_data_35AC8 + 0x5c84), lbl_801A66B4, 0x378) : text_lookup((struct TextTable *)(p_lbl_1_data_35AC8 + 0x5c84), lbl_801A66B4, 0x390));
    fn_1_4A0D8(frame.loc_54);
    if ((s32)selected->unk_2A != 0) {
        frame.loc_C = p_lbl_1_rodata_4AE0->unk_1F8;
        frame.loc_8 = p_lbl_1_rodata_4AE0->unk_1F4;
        v0 = p_lbl_1_rodata_4AE0->unk_204;
        frame.loc_18 = fn_80007F70(&frame.loc_8, &frame.loc_C, lbl_1_bss_71808, v0);
    } else {
        frame.loc_14 = p_lbl_1_rodata_4AE0->unk_200;
        frame.loc_10 = p_lbl_1_rodata_4AE0->unk_1FC;
        v0 = p_lbl_1_rodata_4AE0->unk_1E0;
        frame.loc_18 = fn_80007F70(&frame.loc_10, &frame.loc_14, lbl_1_bss_71808, v0);
    }
    fn_1_496FC(p_lbl_1_rodata_4AE0->unk_24C, p_lbl_1_rodata_4AE0->unk_28C);
    fn_1_495C8(10);
    if (selected->unk_24->unk_1 == 0) {
        fn_1_4D494();
        frame.loc_40 = frame.loc_18;
        fn_1_49514(&frame.loc_40);
        fn_1_4AE0C((const char *)(p_lbl_1_data_35AC8 + 0x7318), text_lookup((struct TextTable *)(p_lbl_1_data_35AC8 + 0x5c84), lbl_801A66B4, 0x3a8));
        frame.loc_3C = frame.loc_50;
        fn_1_4D4C8(&frame.loc_3C, p_lbl_1_rodata_4AE0->unk_290, p_lbl_1_rodata_4AE0->unk_204);
    } else {
        frame.loc_38 = p_lbl_1_rodata_4AE0->unk_270;
        fn_1_49514(&frame.loc_38);
        frame.loc_34 = p_lbl_1_rodata_4AE0->unk_274;
        fn_1_49528(&frame.loc_34);
        fn_1_4AE0C((const char *)(p_lbl_1_data_35AC8 + 0x7318), text_lookup((struct TextTable *)(p_lbl_1_data_35AC8 + 0x5c84), lbl_801A66B4, 0x3a8));
    }
    fn_1_496FC(p_lbl_1_rodata_4AE0->unk_258, p_lbl_1_rodata_4AE0->unk_28C);
    fn_1_495C8(8);
    if (selected->unk_24->unk_1 == 0) {
        frame.loc_30 = p_lbl_1_rodata_4AE0->unk_278;
        fn_1_49514(&frame.loc_30);
        frame.loc_2C = p_lbl_1_rodata_4AE0->unk_27C;
        fn_1_49528(&frame.loc_2C);
        fn_1_4AE0C((const char *)(p_lbl_1_data_35AC8 + 0x7318), text_lookup((struct TextTable *)(p_lbl_1_data_35AC8 + 0x5c84), lbl_801A66B4, 0x3c0));
    } else {
        fn_1_4D494();
        frame.loc_28 = frame.loc_18;
        fn_1_49514(&frame.loc_28);
        fn_1_4AE0C((const char *)(p_lbl_1_data_35AC8 + 0x7318), text_lookup((struct TextTable *)(p_lbl_1_data_35AC8 + 0x5c84), lbl_801A66B4, 0x3c0));
        frame.loc_24 = frame.loc_50;
        fn_1_4D4C8(&frame.loc_24, p_lbl_1_rodata_4AE0->unk_290, p_lbl_1_rodata_4AE0->unk_204);
    }
    frame.loc_20 = p_lbl_1_rodata_4AE0->unk_280;
    fn_1_49514(&frame.loc_20);
    frame.loc_1C = p_lbl_1_rodata_4AE0->unk_284;
    fn_1_49528(&frame.loc_1C);
    fn_1_495C8(9);
    fn_1_495FC();
    fn_1_496FC(p_lbl_1_rodata_4AE0->unk_244, p_lbl_1_rodata_4AE0->unk_25C);
    fn_1_495A0(p_lbl_1_rodata_4AE0->unk_260);
    fn_1_4A0D8((const char *)(p_lbl_1_data_35AC8 + 0x731c));
    fn_1_49410();
}
#pragma peephole reset
