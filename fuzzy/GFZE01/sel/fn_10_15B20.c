/* Non-matching: best partial attempt (76.35% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"

typedef struct Sig_fn_1_5158C_FontDrawPacket Sig_fn_1_5158C_FontDrawPacket;
extern int fn_10_160BC(s16);
extern void fn_10_14C84(u32, u32, u32, u32, f32);
extern void fn_10_18A50(void *, u32);
extern void fn_10_175F0(void *, u32);
extern int fn_1_F89E4(int);
extern void fn_1_12EF80(u32, void *, void *);
extern void fn_1_140EE8(u8, int, int);
extern u32 fn_1_B7C00(void);
extern void fn_1_14108C(s16, s32, s32);
extern void fn_1_141614(s16);
extern u32 fn_1_141C10(u32);
extern void fn_1_1418EC(u32, u32);
extern void fn_1_141754(s32, s32);
extern s16 fn_1_12EF24(s16, s16);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_1_5158C(Sig_fn_1_5158C_FontDrawPacket *, u32, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);
extern f32 lbl_8006D188(u32);
extern u32 fn_1_141A80(u32);
extern void fn_10_18A50(void *, u32);
extern void fn_10_175F0(void *, u32);
extern u8 lbl_1_rodata_26F8[];
struct Pool { u8 pad0[0x44]; f32 f44; u8 p48[0x20]; f32 f68; u8 p6c[0xc]; f32 f78; f32 f7c; u8 p80[8]; f64 f88; f64 f90; u8 p98[0x9c]; f32 f134; u8 p138[0x154]; f32 f28c; u8 p290[0x34]; f32 f2c4; u8 p2c8[0x40]; f32 f308; u8 p30c[0x234]; f32 f540; u8 p544[0x120]; u32 f664; f64 f668; f64 f670; };
extern struct Pool lbl_10_rodata_158;
extern u8 lbl_10_bss_51750;
extern u8 lbl_1_bss_8B3A0[];
extern u8 lbl_1_data_2B0D4[];
extern u8 lbl_1_data_2B144[];
extern u32 lbl_801A66A0;

struct BssMenu {
    u8 pad[0x8c];
    s16 unk_8c;
    u8 pad2[2];
    s16 unk_90;
};
struct Copy88 { u32 a[22]; };
struct SelData { u8 a[0x100]; };
struct MenuState { u32 a[0x114/4+1]; };

void fn_10_15B20(void *arg0, u32 arg1) {
    struct BssMenu *g = (struct BssMenu *)&lbl_1_bss_8B3A0;
    struct SelData *d0 = (struct SelData *)&lbl_1_data_2B0D4;
    struct SelData *d1 = (struct SelData *)&lbl_1_data_2B144;
    struct Copy88 packet;
    FontDrawPacket *p = (FontDrawPacket *)&packet;
    u16 color[5];
    s16 selected = 0;
    s32 reverse = 0;
    s32 selectedMenu;
    s32 i;
    s32 drawIndex;
    s32 forceAlpha;
    s32 font;
    f32 fade;
    f32 x;
    u32 state;
    u32 *time;
    struct MenuState *menu;
    if (g->unk_8c == 5 && fn_1_F89E4(0) != 0) reverse = 1;
    reverse = (u32)(reverse | -reverse) >> 31;
    selectedMenu = (u8)(reverse + 5);
    if (g->unk_8c == 0) {
        color[0] = 1;
        selected = 0;
    } else {
        fn_1_12EF80(*(s16 *)((u8 *)arg0 + 0x90), &color[0], &selected);
    }
    fn_1_140EE8((u8)*(s16 *)((u8 *)arg0 + 0x90), 0, 0);
    if ((u8)fn_1_B7C00() == 0) {
            fn_1_14108C(color[0], 0x44, 0x78);
            fn_1_141614(*(s16 *)((u8 *)arg0 + 0x90));
            fn_1_141C10((u8)*(s16 *)((u8 *)arg0 + 0x90));
            font = reverse ? 0x24 : 0x4d;
            if (reverse) fn_1_1418EC(font, 0x15c);
            else fn_1_141754(font, 0x15c);
            x = lbl_10_rodata_158.f308;
            for (i = 0; i < selectedMenu; i++) {
                forceAlpha = 0;
                if (i == selected) {
                    u8 a = lbl_10_bss_51750;
                    if (a != 0) {
                        if (a > 15) fade = (f32)(20 - a) / 5.0f;
                        else fade = (f32)a / 15.0f;
                        forceAlpha = 1;
                        *(u32 *)&color[1] = lbl_10_rodata_158.f664;
                        color[1] = (s32)(255.0f * fade);
                        color[2] = (s32)(255.0f * fade);
                        color[3] = (s32)(255.0f * fade);
                    }
                }
                drawIndex = fn_1_12EF24(selected, (s16)i);
                if (g->unk_8c == 0) drawIndex = g->unk_90;
                state = d0->a[(s16)drawIndex];
                color[0] = d1->a[state];
                *p = *(FontDrawPacket *)lbl_1_rodata_26F8;
                if (fn_10_160BC(color[0])) {
                    p->image = 0xa100;
                    fn_1_51564(0, 0, 0x48, 0x48, 7, 2);
                    fn_1_5158C((Sig_fn_1_5158C_FontDrawPacket *)p, (u32)p->image,
                               (s16)((color[0] - 1) % 7), (s16)((color[0] - 1) / 7));
                } else {
                    p->image = 0xffffa110;
                }
                p->y = 366.0f;
                p->z = 60.0f;
                p->x = (f32)(font + 77);
                p->flags = 10;
                if (forceAlpha) *(u32 *)((u8 *)p + 60) = *(u32 *)&color[1];
                fn_1_4F734(p);
                *p = *(FontDrawPacket *)lbl_1_rodata_26F8;
                p->image = 0xffffa110;
                p->y = 366.0f;
                p->x = (f32)(font + 77);
                p->z = 50.0f;
                p->flags = 10;
                if (forceAlpha) *(u32 *)((u8 *)p + 60) = *(u32 *)&color[1];
                fn_1_4F734(p);
                *p = *(FontDrawPacket *)lbl_1_rodata_26F8;
                p->image = 0xffffa12f;
                p->y = 366.0f;
                p->x = (f32)(font + 77);
                p->z = 40.0f;
                p->flags = 10;
                if (forceAlpha) *(u32 *)((u8 *)p + 60) = *(u32 *)&color[1];
                fn_1_4F734(p);
            }
            selected = selected;
            if (selected != -1) {
                menu = (struct MenuState *)((u8 *)arg0 + ((u8 *)arg0)[0x9e] * 4);
                drawIndex = font + selected * 82 + 77;
                if (menu->a[0x100/4] == 6 && menu->a[0x110/4] != 0) {
                    fade = 1.0f;
                } else {
                    time = &lbl_801A66A0;
                    state = *time;
                    fade = (f32)(state - ((state / 60) * 60));
                    fade = (65536.0f * fade) / 60.0f;
                    fade = lbl_8006D188((u32)fade);
                    fn_10_14C84(drawIndex, 366, 8, 9, 0.75f + 0.25f * fade);
                }
            }
            if (selected != -1) fn_1_141A80(*(s16 *)((u8 *)arg0 + 0x90));
    }
    fn_10_18A50(arg0, 0xe8);
    if (arg1 != 0) fn_10_175F0(arg0, 0);
}
