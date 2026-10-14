/* Non-matching: best partial attempt (69.60% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"
#include "rel/main_rel/memcard.h"

struct B5_rodata {
    u8 pad_0[0x1E0];
    f32 unk_1E0;
    u8 pad_1E4[0x10];
    u32 unk_1F4, unk_1F8, unk_1FC, unk_200;
    f32 unk_204;
    u8 pad_208[0x24];
    f32 unk_22C, unk_230, unk_234, unk_238, unk_23C, unk_240, unk_244;
    u8 pad_248[4];
    f32 unk_24C, unk_250;
    u8 pad_254[4];
    f32 unk_258, unk_25C, unk_260;
    u8 pad_264[0x2C];
    f32 unk_290;
    u32 unk_294, unk_298, unk_29C, unk_2A0, unk_2A4, unk_2A8, unk_2AC, unk_2B0, unk_2B4;
    f32 unk_2B8;
};
extern struct B5_rodata lbl_1_rodata_4AE0;
extern u32 lbl_1_data_35AC8;
extern u32 lbl_801A66B4;
extern void fn_1_4D4C8(void *, f32, f32);
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

void fn_1_B5A3C(void)
{
    struct B5_rodata *ro = &lbl_1_rodata_4AE0;
    u8 *data = (u8 *)&lbl_1_data_35AC8;
    u32 text_ptr;
    char buffer[0x410];
    u32 color = ro->unk_294;
    u32 font = ro->unk_298;
    u32 text = fn_80007F70(&color, &font, lbl_1_bss_71808, ro->unk_1E0);
    Obj_1_bss_716C8 *obj = &lbl_1_bss_716C8;
    Obj_1_bss_716C8 *entry = obj;
    if (obj->unk_4 != 11) entry = (Obj_1_bss_716C8 *)((u8 *)obj + 0xA0);
    fn_1_49410();
    fn_1_494DC(42);
    fn_1_495C8(9);
    fn_1_4954C(ro->unk_22C);
    color = ro->unk_29C;
    fn_1_49514(&color);
    fn_1_49614();
    fn_1_4955C(ro->unk_230, ro->unk_230);
    fn_1_4966C(ro->unk_234, ro->unk_238);
    if ((s32)lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(ro->unk_23C);
        fn_1_4966C(ro->unk_234, ro->unk_240);
    }
    fn_1_496FC(ro->unk_244, ro->unk_2B8);
    if (*(u8 *)entry->unk_24 == 4) {
        u8 *p = data + 0x5C84 + (lbl_801A66B4 << 2);
        const char *s;
        if (entry->unk_0 == 0) s = (const char *)*(u32 *)(p + 0x378);
        else s = (const char *)*(u32 *)(p + 0x390);
        fn_1_B5258(buffer, (void *)*(u32 *)(p + 0x9D8), (const char *)(data + 0x7320), s);
        if (entry->unk_0 == 0) s = (const char *)*(u32 *)(data + 0x5C84 + (lbl_801A66B4 << 2) + 0x378);
        else s = (const char *)*(u32 *)(data + 0x5C84 + (lbl_801A66B4 << 2) + 0x390);
        fn_1_B5258(buffer, buffer, (const char *)(data + 0x7320), s);
    } else {
        u8 flag = entry->unk_0;
        u8 *p = data + 0x5C84 + (lbl_801A66B4 << 2);
        fn_1_B5258(buffer, (void *)*(u32 *)(p + 0x450), (const char *)(data + 0x7320),
                   (const char *)*(u32 *)(p + (flag == 0 ? 0x378 : 0x390)));
        flag = entry->unk_0;
        p = data + 0x5C84 + (lbl_801A66B4 << 2);
        fn_1_B5258(buffer, buffer, (const char *)(data + 0x7320),
                   (const char *)*(u32 *)(p + (flag == 0 ? 0x378 : 0x390)));
    }
    fn_1_B5258(buffer, buffer, (const char *)(data + 0x7328),
        (const char *)*(u32 *)(data + 0x5C84 + (lbl_801A66B4 << 2) +
        (entry->unk_24->unk_8C * 0x18)));
    fn_1_4A0D8(buffer);
    if (obj->unk_2A) {
        color = ro->unk_1F4;
        font = ro->unk_1F8;
        text_ptr = fn_80007F70(&color, &font, lbl_1_bss_71808, ro->unk_204);
    } else {
        color = ro->unk_1FC;
        font = ro->unk_200;
        text_ptr = fn_80007F70(&color, &font, lbl_1_bss_71808, ro->unk_1E0);
    }
    fn_1_496FC(ro->unk_24C, ro->unk_250);
    fn_1_495C8(10);
    if (entry->unk_1 == 0) {
        fn_1_4D494();
        fn_1_49514(&text_ptr);
        fn_1_4AE0C((const char *)(data + 0x7318),
                   *(u32 *)(data + 0x5C84 + (lbl_801A66B4 << 2) + 0x3A8));
        fn_1_4D4C8(&text, ro->unk_290, ro->unk_204);
    } else {
        color = ro->unk_2A0;
        fn_1_49514(&color);
        font = ro->unk_2A4;
        fn_1_49528(&font);
        fn_1_4AE0C((const char *)(data + 0x7318),
                   *(u32 *)(data + 0x5C84 + (lbl_801A66B4 << 2) + 0x3A8));
    }
    fn_1_496FC(ro->unk_258, ro->unk_250);
    fn_1_495C8(8);
    if (entry->unk_1 == 0) {
        color = ro->unk_2A8;
        fn_1_49514(&color);
        font = ro->unk_2AC;
        fn_1_49528(&font);
        fn_1_4AE0C((const char *)(data + 0x7318),
                   *(u32 *)(data + 0x5C84 + (lbl_801A66B4 << 2) + 0x3C0));
    } else {
        fn_1_4D494();
        fn_1_49514(&text_ptr);
        fn_1_4AE0C((const char *)(data + 0x7318),
                   *(u32 *)(data + 0x5C84 + (lbl_801A66B4 << 2) + 0x3C0));
        fn_1_4D4C8(&text, ro->unk_290, ro->unk_204);
    }
    color = ro->unk_2B0;
    fn_1_49514(&color);
    font = ro->unk_2B4;
    fn_1_49528(&font);
    fn_1_495C8(9);
    fn_1_495FC();
    fn_1_496FC(ro->unk_244, ro->unk_25C);
    fn_1_495A0(ro->unk_260);
    fn_1_4A0D8((const char *)(data + 0x731C));
    fn_1_49410();
}
