/* Non-matching: best partial attempt (89.19% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#include "rel/main_rel/globals.h"

enum Sig_parse_format_justification_options { Sig_parse_format_left_justification, Sig_parse_format_right_justification, Sig_parse_format_zero_fill };
enum Sig_parse_format_sign_options { Sig_parse_format_only_minus, Sig_parse_format_sign_always, Sig_parse_format_space_holder };
enum Sig_parse_format_argument_options {
    Sig_parse_format_normal_argument,
    Sig_parse_format_char_argument,
    Sig_parse_format_short_argument,
    Sig_parse_format_long_argument,
    Sig_parse_format_long_long_argument,
    Sig_parse_format_long_double_argument,
    Sig_parse_format_wchar_argument
};
typedef struct {
    unsigned char Sig_parse_format_justification_options;
    unsigned char Sig_parse_format_sign_options;
    unsigned char precision_specified;
    unsigned char alternate_form;
    unsigned char Sig_parse_format_argument_options;
    unsigned char conversion_char;
    int field_width;
    int precision;
} Sig_parse_format_print_format;
typedef struct Sig_parse_format_MkVaListState {
    signed char gpr;
    signed char fpr;
    unsigned short reserved;
    char *input_arg_area;
    char *reg_save_area;
} Sig_parse_format___va_list[1];
typedef Sig_parse_format___va_list Sig_parse_format_va_list;

struct fn_10_1BFC4_pool {
    u8 pad_0[0x48];
    f32 unk_48;
    u8 pad_4C[0x24];
    f32 unk_70;
    u8 pad_74[0x14];
    f64 unk_88;
    u8 pad_90[0x100];
    f32 unk_190;
    u8 pad_194[0x108];
    f32 unk_29C;
    u8 pad_2A0[0x8];
    f32 unk_2A8;
    u8 pad_2AC[0x58];
    f32 unk_304;
    u8 pad_308[0x500];
    f32 unk_808;
    u8 pad_80C[0x7E8];
    u32 unk_FF4;
    f32 unk_FF8;
    f32 unk_FFC;
    f32 unk_1000;
    f32 unk_1004;
};

extern int fn_1_4F734(FontDrawPacket *);
extern s32 fn_8008077C(u32, u32, Sig_parse_format_va_list *);
extern u32 fn_1_49410(void);
extern void fn_1_49514(u32 *);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(void *);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4CE48(Obj_1_bss_4B9CC *, f32);
extern void fn_1_50164(f32, f32, f32, f32, void *);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern char lbl_1_rodata_26F8;
extern struct fn_10_1BFC4_pool lbl_10_rodata_158;

struct fn_10_1BFC4_arg2 {
    f32 unk_0;
    u8 fzgx_pad_before_unk_4[0x44];
    u32 unk_4;
    u32 unk_8;
};

#pragma opt_lifetimes off
void fn_10_1BFC4(u32 arg0, u32 arg1, struct fn_10_1BFC4_arg2 *arg2, ...) {
    Obj_1_bss_4B9CC loc_D0;
    FontDrawPacket loc_78;
    u32 loc_6C[3];
    u32 loc_68;
    s32 r30;
    f32 f;

    r30 = (s32)arg2->unk_0;
    loc_68 = lbl_10_rodata_158.unk_FF4;
    loc_6C[0] = 0x3000000;
    loc_6C[1] = 0;
    loc_6C[2] = 0;
    fn_8008077C((u32)&loc_D0, arg2->unk_8, (Sig_parse_format_va_list *)&loc_68);

    fn_1_49410();
    fn_1_496FC((f32)(s32)(arg0 + 14), (f32)(s32)(arg1 - 4));
    fn_1_495B0(0x80000000);
    fn_1_4955C((0.416666657f), (0.416666657f));
    fn_1_49514(&loc_68);
    fn_1_49590((0.5f));
    fn_1_4954C((10.0f));
    fn_1_4A0D8((const char *)arg2->unk_4);

    loc_78 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    f = (f32)(s32)arg0;
    loc_78.image = 0x10000 - 25046;
    loc_78.x = f;
    loc_78.y = (f32)(s32)arg1;
    loc_78.z = (20.0f);
    fn_1_50164((216.0f), (27.0f),
               (8.0f), (8.0f),
               (void *)&loc_78);

    loc_78 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_78.image = 0x10000 - 25045;
    fn_1_51678(&loc_78, loc_78.image, 8, 0, 4, 4);

    loc_78.x = (f32)(s32)(arg0 + 208);
    loc_78.y = (f32)(s32)arg1;
    loc_78.z = (19.0f);
    loc_78.scale_x = loc_78.scale_x * ((f32)r30 * (0.25f));
    loc_78.flags = 7;
    fn_1_4F734(&loc_78);

    fn_1_49410();
    fn_1_495C8((void *)10);
    fn_1_496FC((f32)(s32)(arg0 + 207), (f32)(s32)(arg1 + 14));
    fn_1_495B0(0x80000000);
    fn_1_4955C((0.583333313f), (0.583333313f));
    fn_1_49590((0.5f));
    fn_1_4954C((10.0f));
    fn_1_4CE48(&loc_D0, (176.0f));
}
#pragma opt_lifetimes reset

