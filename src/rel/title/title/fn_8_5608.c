#include "types.h"
#include "font.h"

struct TitleState {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad3[0x21d];
    f32 unk220;
    u8 pad224[0x19];
    u8 unk23d;
    u8 pad23e[4];
    u8 unk242;
};

struct TitleRodata {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    u8 padC[0x20];
    f32 unk2c;
    f32 unk30;
    f32 unk34;
};

struct FzgxCopy88 { u32 words[22]; };

extern struct TitleState lbl_8_bss_0;
extern struct TitleRodata lbl_8_rodata_0;
extern struct FzgxCopy88 lbl_1_rodata_26F8;
extern u16 lbl_1_bss_96A;
extern u32 lbl_801A66A0;
extern int fn_1_3F038(void);
extern void fn_1_52070(u32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);
extern u32 fn_1_52088(void);
extern u16 fn_1_486C4(u32);
extern u16 fn_1_48690(u32);
extern void fn_8_D034(void);

void fn_8_5608(void) {
    struct TitleState *state = (struct TitleState *)&lbl_8_bss_0;
    struct TitleRodata *rodata = (struct TitleRodata *)&lbl_8_rodata_0;
    struct FzgxCopy88 loc_60;
    struct FzgxCopy88 loc_8;

    if (state->unk23d != 0) {
        fn_1_3F038();
        return;
    }
    if (state->unk242 != 0) {
        if (fn_1_3F038() != 0) {
            if (state->unk0 != 0) {
                state->unk1 = 1;
                state->unk0 = 0;
                return;
            }
            lbl_1_bss_96A = 0x9E;
        }
        return;
    }
    fn_1_52070(0x60);
    loc_60 = lbl_1_rodata_26F8;
    loc_60.words[0] = 0x100;
    *(f32 *)((u8 *)&loc_60 + 4) = rodata->unk2c;
    *(f32 *)((u8 *)&loc_60 + 8) = rodata->unk30;
    *(f32 *)((u8 *)&loc_60 + 12) = rodata->unk34;
    *(u32 *)((u8 *)&loc_60 + 0x30) = 0xD;
    fn_1_51678((FontDrawPacket *)&loc_60, 0x100, 0, 0, 0xFA, 0x22);
    fn_1_4F734((FontDrawPacket *)&loc_60);
    fn_1_52088();
    fn_1_52070(0x220);
    state->unk220 = rodata->unk8;
    fn_1_52088();
    fn_1_52070(0x140);
    if (state->unk2 != 0 && (lbl_801A66A0 & 0x18)) {
        loc_8 = lbl_1_rodata_26F8;
        loc_8.words[0] = 0x102;
        fn_1_51678((FontDrawPacket *)&loc_8, loc_8.words[0], 0,
                   (s16)(((fn_1_486C4(loc_8.words[0]) >> 2) & 0x3FFF) * 3),
                   (s16)fn_1_48690(loc_8.words[0]),
                   (s16)((fn_1_486C4(0x102) >> 2) & 0x3FFF));
        *(f32 *)((u8 *)&loc_8 + 4) = rodata->unk0;
        *(f32 *)((u8 *)&loc_8 + 8) = rodata->unk4;
        *(f32 *)((u8 *)&loc_8 + 12) = rodata->unk8;
        *(u32 *)((u8 *)&loc_8 + 0x30) = 6;
        fn_1_4F734((FontDrawPacket *)&loc_8);
    }
    fn_1_52088();
    fn_8_D034();
}
