#include "types.h"

/* car_colchg.c: the machine color-change test scene (fze.car_colchg.rel, one translation unit) */

/* one pad's button words: held, trigger and repeat */
typedef struct PadInput {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[4];
    u16 unk_8;
    u16 unk_A;
    u8 pad_C[4];
    u16 unk_10;
    u16 unk_12;
} PadInput;

typedef struct SystemCursor {
    u32 unk_0;
    u8 unk_4;
} SystemCursor;

/* one machine of the car table (0x440 bytes) */
typedef struct ColchgCar {
    u8 pad_0[0x324];
    s32 unk_324;
    u8 pad_328[0x90];
    s16 unk_3B8;
    u8 pad_3BA[0x86];
} ColchgCar;

/* one color entry of a machine's color list (lbl_1_data_1FB6C): id -1 ends the list */
typedef struct ColorEntry {
    s16 id;
    s16 unk_2;
    u32 unk_4;
    u32 color;  /* 0xRRGGBBAA */
} ColorEntry;

/* the current selection */
typedef struct ColchgSelect {
    s16 car;
    s16 color_id;
    s16 color;
    s16 channel;
    u8 pad_8[0x4];
    s16 unk_C;
} ColchgSelect;

/* a menu panel (fn_1_8CED0 / fn_1_8D3F8) */
typedef struct ColchgPanel {
    u8 data[0x64];
} ColchgPanel;

/* the panel template of lbl_1_rodata_26F8 */
typedef struct PanelTemplate {
    u32 words[2];
    f32 x;
    f32 y;
    u32 rest[18];
} PanelTemplate;

typedef struct CarEntry {
    s16 id;
    u8 pad_2[0x2];
    u32 unk_4;
    u8 pad_8[0x18];
} CarEntry;

typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct GXColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} GXColor;

typedef struct LightObj {
    u8 data[0x40];
} LightObj;

typedef struct ColchgScene {
    char name[0x20];
    void (*init)(void);
    void (*main)(void);
    void (*disp)(void);
} ColchgScene;

extern PadInput lbl_1_bss_D58;

/* Pad button test: bit n of a pad button word. */
/* REVIEW NOTE (accepted for now): PAD_BIT is a reconstruction. Retail reads a pad bit with lhz + rlwinm and
 * loads the word again in each statement. Only the __rlwinm intrinsic reproduces it. No retail name proves it. */
#define PAD_BIT(word, n) __rlwinm((word), (32 - (n)) & 31, 31, 31)
extern SystemCursor lbl_1_bss_970;
extern u16 lbl_1_bss_96A;
extern u16 lbl_1_bss_968;
extern s16 lbl_1_bss_962;
extern void (*lbl_1_bss_7167C)(void);
extern void (*lbl_1_bss_71680)(void);
extern void (*lbl_1_bss_71684)(void);
extern void (*lbl_1_bss_71688)(void);
extern void (*lbl_1_bss_7168C)(void);
extern u32 lbl_801A6410;
extern u32 lbl_801A66A0;
extern ColorEntry *lbl_1_data_1FB6C[];
extern const PanelTemplate lbl_1_rodata_26F8;

extern void *fn_1_4630(u32, u32, const char *, s32);
extern u32 fn_1_45D0(u32, u32, const char *, s32);
extern void fn_1_46B4(u32, u32, const char *, int);
extern u32 fn_1_7BA08(u32, u32, u32);
extern void fn_1_7BA48(u32);
extern void fn_1_3CF0(u32, u32);
extern void fn_1_5124(u32, u32);
extern u16 fn_1_3F8C(const char *, void (*)(void), u32, s32);
extern u32 fn_1_435C(u32);
extern void fn_1_426C(s16);
extern void fn_1_4A00(s32, u8, void *);
extern int fn_1_4C10(void);
extern void fn_1_407C(void);
extern void fn_1_3CC4(void);
extern void fn_1_41A8(void);
extern void fn_1_6400(void);
extern void fn_1_7FA04(void *);
extern void fn_1_8CED0(void *, u16, u16);
extern void fn_1_8D0A4(void *);
extern void fn_1_8D168(void *);
extern void fn_1_8D3F8(void *, void *, s32 (*)(ColchgCar *), void *);
extern void fn_1_7BAF8(void);
extern void fn_8006CE1C(f32);
extern void fn_80074CF4(f32, f32, f32);
extern void fn_1_A8EB0(int, int);
extern void fn_1_A8DD4(const char *, ...);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4955C(f32, f32);
extern f32 fn_1_4B040(const char *);
extern void fn_1_4B83C(char *, const char *, const char *, const char *);
extern void *fn_1_7F49C(s16, s16, void *);
extern unsigned long strlen(const char *);
extern char *fn_80083DB0(char *, const char *);
extern int sprintf(char *, const char *, ...);
extern void fn_1_870BC(ColchgCar *, s8, ColchgCar *, s32, u8, f32);
extern void lbl_8006D7F4(f32, f32, f32);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_x(s32);
extern void lbl_8006E14C(f32);
extern void fn_80072558(void);
extern void lbl_8006DCA4(void);
extern void lbl_8006E1D8(Vec3 *, f32, f32, f32);
extern void fn_1_7BCCC(Vec3 *);
extern void fn_80035680(LightObj *, f32, f32, f32);
extern void fn_80035690(LightObj *, f32, f32, f32);
extern void fn_80035420(LightObj *, f32, int);
extern void fn_800356AC(LightObj *, GXColor);
extern void GXInitLightDistAttn(LightObj *, f32, f32, int);
extern void fn_1_7BB80(LightObj *, int);
extern void fn_1_7BD6C(int);
extern void fn_1_80058(s8, CarEntry *);
extern void fn_1_80C18(void *, CarEntry *, s8);
extern void fn_1_12B4(void);
extern void fn_1_12FC(void);
extern void fn_1_1300(void);

void fn_9_298(void);
void fn_9_2E0(void);
void fn_9_1AFC(void);
void fn_9_1C54(void);
void colchg_menu_disp(void);
void colchg_selcar_disp(ColchgCar *cars);
void colchg_selmate_disp(ColchgCar *cars);
void colchg_chgcol_disp(ColchgCar *cars);
void colchg_ezsel_disp(void);
void colchg_save_disp(void);
void fn_9_1AC4(void);
void fn_9_1BCC(void);
s32 fn_9_120C(ColchgCar *car);
s32 fn_9_1310(ColchgCar *car);

s16 lbl_9_data_0 = 5;

u32 lbl_9_bss_0 = 0;
ColchgCar *lbl_9_bss_4 = NULL;
ColchgSelect *lbl_9_bss_8;
u32 lbl_9_bss_C;
u32 lbl_9_bss_10;
ColchgPanel lbl_9_bss_14[2];
s16 lbl_9_bss_DC;
u32 lbl_9_bss_E0[2];

/* fzgx:begin _prolog */
void _prolog(void) {
    s16 i;

    lbl_9_bss_8 = fn_1_4630(lbl_801A6410, 0x10, "car_colchg.c", 0x93);
    lbl_9_bss_4 = fn_1_4630(lbl_801A6410, 0xAE40, "car_colchg.c", 0x94);
    for (i = 0; i < 0x29; i++) {
        lbl_9_bss_4[i].unk_324 = -1;
    }
    lbl_9_bss_0 = fn_1_45D0(lbl_801A6410, fn_1_7BA08(0x20, 0x20, 0x40), "car_colchg.c", 0x96);
    fn_1_7BA48(lbl_9_bss_0);
    lbl_9_bss_C = fn_1_45D0(lbl_801A6410, 0x173C, "car_colchg.c", 0x97);
    fn_1_3CF0(lbl_9_bss_C, 0x80);
    lbl_9_bss_10 = fn_1_45D0(lbl_801A6410, 0x173C, "car_colchg.c", 0x98);
    fn_1_3CF0(lbl_9_bss_10, 0x80);
    fn_1_5124(lbl_9_bss_C, lbl_9_bss_10);
    lbl_1_bss_970.unk_0 = 0;
    lbl_1_bss_970.unk_4 = 0x72;
    lbl_1_bss_96A = 0x72;
    fn_8006CE1C(0.0f);
    fn_80074CF4(0.25f, 0.25f, 0.25f);
    fn_1_435C(lbl_9_bss_10);
    fn_1_3F8C("LightMain", fn_1_7BAF8, lbl_9_bss_0, 2);
    fn_1_3F8C("light_calc", fn_9_1AFC, 0, 3);
    for (i = 0; i < 2; i++) {
        fn_1_8CED0(&lbl_9_bss_14[i], 0x200, 0x200);
        fn_1_8D0A4(&lbl_9_bss_14[i]);
    }
    lbl_1_bss_7167C = fn_9_298;
    lbl_1_bss_71680 = fn_9_2E0;
    lbl_1_bss_71684 = fn_9_1C54;
}
/* fzgx:end _prolog */

/* fzgx:begin fn_9_298 */
void fn_9_298(void) {
    if (fn_1_4C10() == 0) {
        if (PAD_BIT(lbl_1_bss_D58.unk_8, 12)) {
            lbl_1_bss_96A = 0x75;
        }
    }
}
/* fzgx:end fn_9_298 */

/* fzgx:begin fn_9_2E0 */
void fn_9_2E0(void) {
    fn_1_435C(lbl_9_bss_C);
    fn_1_407C();
    fn_1_3CC4();
    fn_1_435C(lbl_9_bss_10);
    fn_1_407C();
}
/* fzgx:end fn_9_2E0 */

/* fzgx:begin _epilog */
/* Tear down the color-change state and release its two menu entries. */
void _epilog(void) {
    s16 i;

    fn_1_7FA04(lbl_9_bss_4);
    for (i = 0; i < 2; i++) {
        fn_1_8D168(&lbl_9_bss_14[i]);
    }
    fn_1_435C(lbl_9_bss_C);
    fn_1_41A8();
    fn_1_435C(lbl_9_bss_10);
    fn_1_41A8();
    fn_1_46B4(lbl_801A6410, lbl_9_bss_0, "car_colchg.c", 0xDA);
    fn_1_6400();
    fn_1_46B4(lbl_801A6410, (u32)lbl_9_bss_8, "car_colchg.c", 0xDC);
}
/* fzgx:end _epilog */

/* fzgx:begin colchg_menu_init */
void colchg_menu_init(void) {
    // Set up the menu callback and activate the initial collision-color selection.
    fn_1_435C(lbl_9_bss_10);
    lbl_9_bss_DC = fn_1_3F8C("colchg_menu_disp", colchg_menu_disp, 0, 8);
    fn_1_4A00(1, 15, (void *)lbl_9_bss_10);
}
/* fzgx:end colchg_menu_init */

/* fzgx:begin fn_9_454 */
void fn_9_454(void) {
    s32 value;
    s8 delta;

    if (fn_1_4C10() == 0) {
        delta = 0;
        if (PAD_BIT(lbl_1_bss_D58.unk_10, 3) || PAD_BIT(lbl_1_bss_D58.unk_12, 3)) {
            delta = -1;
        }
        if (PAD_BIT(lbl_1_bss_D58.unk_10, 2) || PAD_BIT(lbl_1_bss_D58.unk_12, 2)) {
            delta++;
        }
        value = lbl_1_bss_970.unk_4 + delta;
        value = (lbl_1_bss_970.unk_4 = (value > 0x73) ? 0x73 : ((value < 0x73) ? 0x73 : value));
        if (PAD_BIT(lbl_1_bss_D58.unk_8, 8)) {
            lbl_1_bss_96A = value;
        }
        if (PAD_BIT(lbl_1_bss_D58.unk_8, 9)) {
            lbl_1_bss_96A = 0x75;
        }
    }
}
/* fzgx:end fn_9_454 */

/* fzgx:begin fn_9_534 */
// Initialize the car color-change state and apply the current selection.
void fn_9_534(void) {
    fn_1_435C(lbl_9_bss_10);
    fn_1_426C(lbl_9_bss_DC);
}
/* fzgx:end fn_9_534 */

/* fzgx:begin colchg_selcar_init */
void colchg_selcar_init(void) {
    fn_9_1BCC();
    fn_1_435C(lbl_9_bss_10);
    lbl_9_bss_DC = fn_1_3F8C("colchg_selcar_disp", (void (*)(void))colchg_selcar_disp, (u32)lbl_9_bss_4, 8);
    fn_1_4A00(1, 15, (void *)lbl_9_bss_10);
}
/* fzgx:end colchg_selcar_init */

/* fzgx:begin fn_9_5D8 */
void fn_9_5D8(void) {
    ColorEntry *entries;
    s32 value;
    s8 delta;

    if (fn_1_4C10() == 0) {
        if (PAD_BIT(lbl_1_bss_D58.unk_8, 9)) {
            lbl_1_bss_96A = 0x72;
        }
        delta = 0;
        if (PAD_BIT(lbl_1_bss_D58.unk_10, 0) || PAD_BIT(lbl_1_bss_D58.unk_12, 0)) {
            delta = -1;
        }
        if (PAD_BIT(lbl_1_bss_D58.unk_10, 1) || PAD_BIT(lbl_1_bss_D58.unk_12, 1)) {
            delta++;
        }
        if (delta != 0) {
            value = lbl_9_bss_8->car + delta;
            lbl_9_bss_8->car = value > 40 ? 0 : value < 0 ? 40 : value;
        }
        entries = lbl_1_data_1FB6C[lbl_9_bss_8->car];
        if (PAD_BIT(lbl_1_bss_D58.unk_8, 8) && entries->id != -1) {
            lbl_1_bss_96A = 0x76;
        }
    }
}
/* fzgx:end fn_9_5D8 */

/* fzgx:begin fn_9_6F0 */
// Apply the current car color-change configuration.
void fn_9_6F0(void) {
    fn_1_435C(lbl_9_bss_10);
    fn_1_426C(lbl_9_bss_DC);
}
/* fzgx:end fn_9_6F0 */

/* fzgx:begin colchg_selmate_init */
void colchg_selmate_init(void) {
    ColorEntry *entries = lbl_1_data_1FB6C[lbl_9_bss_8->car];

    fn_1_435C(lbl_9_bss_10);
    lbl_9_bss_DC = fn_1_3F8C("colchg_selmate_disp", (void (*)(void))colchg_selmate_disp, (u32)lbl_9_bss_4, 8);
    fn_1_4A00(1, 15, (void *)lbl_9_bss_10);
    lbl_9_bss_8->color_id = entries[lbl_9_bss_8->color].id;
    lbl_9_bss_E0[0] = entries[lbl_9_bss_8->color].color;
}
/* fzgx:end colchg_selmate_init */

/* fzgx:begin fn_9_7DC */
void fn_9_7DC(void) {
    ColorEntry *entries;
    s8 change;
    s16 count;
    s32 index;

    entries = lbl_1_data_1FB6C[lbl_9_bss_8->car];
    if (fn_1_4C10() == 0) {
        if (PAD_BIT(lbl_1_bss_D58.unk_8, 8)) {
            lbl_1_bss_96A = 0x77;
        }
        if (PAD_BIT(lbl_1_bss_D58.unk_8, 9)) {
            lbl_1_bss_96A = 0x73;
        }
        change = 0;
        // Direct polling of the button-edge reads and the second button-edge source.
        if (PAD_BIT(lbl_1_bss_D58.unk_10, 0) || PAD_BIT(lbl_1_bss_D58.unk_12, 0)) {
            change = -1;
        }
        // Direct polling of the button-edge reads and the second button-edge source.
        if (PAD_BIT(lbl_1_bss_D58.unk_10, 1) || PAD_BIT(lbl_1_bss_D58.unk_12, 1)) {
            change++;
        }
        if (change != 0) {
            count = 0;
            while (lbl_1_data_1FB6C[lbl_9_bss_8->car][count].id != -1) {
                count++;
            }
            entries[lbl_9_bss_8->color].color = lbl_9_bss_E0[0];
            index = lbl_9_bss_8->color + change;
            if (index > count - 1) {
                index = 0;
            } else if (index < 0) {
                index = count - 1;
            }
            lbl_9_bss_8->color = index;
            if (entries[lbl_9_bss_8->color].id == -1) {
                index = lbl_9_bss_8->color - change;
                if (index > count - 1) {
                    index = 0;
                } else if (index < 0) {
                    index = count - 1;
                }
                lbl_9_bss_8->color = index;
            }
            lbl_9_bss_8->color_id = entries[lbl_9_bss_8->color].id;
            lbl_9_bss_E0[0] = entries[lbl_9_bss_8->color].color;
        }
        if (lbl_801A66A0 & 1) {
            entries[lbl_9_bss_8->color].color = 0;
        } else {
            entries[lbl_9_bss_8->color].color = -1;
        }
    }
}
/* fzgx:end fn_9_7DC */

/* fzgx:begin fn_9_A18 */
void fn_9_A18(void) {
    ColorEntry *entries = lbl_1_data_1FB6C[lbl_9_bss_8->car];

    fn_1_435C(lbl_9_bss_10);
    fn_1_426C(lbl_9_bss_DC);
    entries[lbl_9_bss_8->color].color = lbl_9_bss_E0[0];
}
/* fzgx:end fn_9_A18 */

/* fzgx:begin colchg_chgcol_init */
void colchg_chgcol_init(void) {
    fn_1_435C(lbl_9_bss_10);
    lbl_9_bss_DC = fn_1_3F8C("colchg_chgcol_disp", (void (*)(void))colchg_chgcol_disp, (u32)lbl_9_bss_4, 8);
    fn_1_4A00(1, 15, (void *)lbl_9_bss_10);
}
/* fzgx:end colchg_chgcol_init */

/* fzgx:begin fn_9_AF0 */
// Channel editor: pick R/G/B with left/right, change it with up/down, write it back into the entry.
void fn_9_AF0(void) {
    s16 rgb[3];
    s16 *chan;
    ColorEntry *entries;
    u32 color;
    s8 delta;
    s8 step;
    s8 i;
    s32 value;
    u8 shift;

    if (fn_1_4C10() == 0) {
        if (PAD_BIT(lbl_1_bss_D58.unk_8, 9)) {
            lbl_1_bss_96A = 0x76;
        }
        delta = 0;
        step = 0;
        entries = lbl_1_data_1FB6C[lbl_9_bss_8->car];
        if (PAD_BIT(lbl_1_bss_D58.unk_10, 3) || PAD_BIT(lbl_1_bss_D58.unk_12, 3)) {
            delta = -1;
        }
        if (PAD_BIT(lbl_1_bss_D58.unk_10, 2) || PAD_BIT(lbl_1_bss_D58.unk_12, 2)) {
            delta++;
        }
        if (delta != 0) {
            value = lbl_9_bss_8->channel + delta;
            lbl_9_bss_8->channel = value > 2 ? 0 : value < 0 ? 2 : value;
        }
        color = entries[lbl_9_bss_8->color].color;
        /* WARNING: compiler-diff device, not original code (comma expression keeps chan a separate pointer) */
        chan = (0, rgb); // the comma keeps chan its own pointer; `chan = rgb` is folded into rgb

        rgb[0] = color >> 24;
        rgb[1] = (color >> 16) & 0xFF;
        rgb[2] = (color >> 8) & 0xFF;
        if (PAD_BIT(lbl_1_bss_D58.unk_10, 0) || PAD_BIT(lbl_1_bss_D58.unk_12, 0)) {
            step = -1;
        }
        if (PAD_BIT(lbl_1_bss_D58.unk_10, 1) || PAD_BIT(lbl_1_bss_D58.unk_12, 1)) {
            step++;
        }
        if (step != 0) {
            value = rgb[lbl_9_bss_8->channel] + step;
            rgb[lbl_9_bss_8->channel] = value > 255 ? 0 : value < 0 ? 255 : value;
        }
        shift = (3 - lbl_9_bss_8->channel) * 8;
        entries[lbl_9_bss_8->color].color &= ~(0xFF << shift);
        entries[lbl_9_bss_8->color].color |= rgb[lbl_9_bss_8->channel] << shift;
        {
            /* the R/G/B name table (lbl_9_rodata_8) points at the retail strings */
            char *names[3] = {"R", "G", "B"};

            fn_1_A8EB0(2, 0x14);
            for (i = 0; i < 3; i++) {
                fn_1_A8DD4("%s%s:%d\n", i == lbl_9_bss_8->channel ? ">" : " ", names[i], chan[i]);
            }
        }
    }
}
/* fzgx:end fn_9_AF0 */

/* fzgx:begin fn_9_DC0 */
// Refresh the collision-change state from the current global settings.
void fn_9_DC0(void) {
    fn_1_435C(lbl_9_bss_10);
    fn_1_426C(lbl_9_bss_DC);
}
/* fzgx:end fn_9_DC0 */

/* fzgx:begin colchg_ezsel_init */
// Register the easy-selection display callback and retain its menu handle.
void colchg_ezsel_init(void) {
    fn_1_435C(lbl_9_bss_10);
    lbl_9_bss_DC = fn_1_3F8C("colchg_ezsel_disp", colchg_ezsel_disp, 0, 8);
}
/* fzgx:end colchg_ezsel_init */

/* fzgx:begin fn_9_E4C */
void fn_9_E4C(void) {
    s8 change;
    s32 value;

    if (fn_1_4C10() == 0) {
        if (PAD_BIT(lbl_1_bss_D58.unk_8, 9)) {
            lbl_1_bss_96A = 0x72;
        }
        change = 0;
        if (PAD_BIT(lbl_1_bss_D58.unk_10, 0) || PAD_BIT(lbl_1_bss_D58.unk_12, 0)) {
            change = -1;
        }
        if (PAD_BIT(lbl_1_bss_D58.unk_10, 1) || PAD_BIT(lbl_1_bss_D58.unk_12, 1)) {
            change++;
        }
        if (change != 0) {
            value = lbl_9_bss_8->car + change;
            lbl_9_bss_8->car = value > 40 ? 0 : value < 0 ? 40 : value;
        }
        if (PAD_BIT(lbl_1_bss_D58.unk_8, 8)) {
            lbl_1_bss_96A = 0x76;
        }
    }
}
/* fzgx:end fn_9_E4C */

/* fzgx:begin fn_9_F38 */
// Initialize the color-change subsystem and apply its current configuration.
void fn_9_F38(void) {
    fn_1_435C(lbl_9_bss_10);
    fn_1_426C(lbl_9_bss_DC);
}
/* fzgx:end fn_9_F38 */

/* fzgx:begin colchg_save_init */
// Register the save-screen callback and reset the color-change save state.
void colchg_save_init(void) {
    fn_1_435C(lbl_9_bss_10);
    lbl_9_bss_DC = fn_1_3F8C("colchg_save_disp", colchg_save_disp, 0, 8);
    lbl_1_bss_968 = 10;
}
/* fzgx:end colchg_save_init */

/* fzgx:begin fn_9_FD0 */
void fn_9_FD0(void) {
    if (fn_1_4C10() == 0) {
        if (PAD_BIT(lbl_1_bss_D58.unk_8, 9)) {
            lbl_1_bss_968 = 10;
        }
    }
}
/* fzgx:end fn_9_FD0 */

/* fzgx:begin fn_9_1018 */
// Initializes the color-change subsystem from its configured state.
void fn_9_1018(void) {
    fn_1_435C(lbl_9_bss_10);
    fn_1_426C(lbl_9_bss_DC);
}
/* fzgx:end fn_9_1018 */

/* fzgx:begin fn_9_1054 */
// Sets up the color-change display callback and selects the default palette.
void fn_9_1054(void) {
    fn_9_1BCC();
    fn_1_435C(lbl_9_bss_10);
    lbl_9_bss_DC = fn_1_3F8C("colchg_load_disp", fn_9_1AC4, 0, 8);
    fn_1_4A00(1, 15, (void *)lbl_9_bss_10);
}
/* fzgx:end fn_9_1054 */

/* fzgx:begin fn_9_10BC */
void fn_9_10BC(void) {
    if (fn_1_4C10() == 0) {
        lbl_1_bss_96A = 0x73;
        if (PAD_BIT(lbl_1_bss_D58.unk_8, 9)) {
            lbl_1_bss_96A = 0x72;
        }
        if (PAD_BIT(lbl_1_bss_D58.unk_8, 8)) {
            lbl_1_bss_96A = 0x76;
        }
    }
}
/* fzgx:end fn_9_10BC */

/* fzgx:begin fn_9_1124 */
void fn_9_1124(void) {
    // Apply the active color-change state before refreshing the selection display.
    fn_1_435C(lbl_9_bss_10);
    fn_1_426C(lbl_9_bss_DC);
}
/* fzgx:end fn_9_1124 */

/* fzgx:begin colchg_menu_disp */
void colchg_menu_disp(void) {
    s8 i;

    fn_1_496FC(160.0f, 50.0f);
    fn_1_4AE0C("[ \x83\x81\x83j\x83\x85\x81[ ]\n\n");  /* "[ menu ]" */
    for (i = 0x72; i < 0x79; i++) {
        switch (i) {
        case 0x73:
            fn_1_4AE0C("%s\x83}\x83V\x83\x93\x83Z\x83\x8C\x83N\x83g\n",  /* "%s machine select" */
                       lbl_1_bss_970.unk_4 == i ? "*" : " ");
            break;
        }
    }
}
/* fzgx:end colchg_menu_disp */

/* fzgx:begin fn_9_120C */
s32 fn_9_120C(ColchgCar *car) {
    s16 color = lbl_9_bss_8->unk_C;

    lbl_8006D7F4(0.0f, 0.0f, -10.0f);
    mathutil_mtxA_rotate_y(-0x8000);
    mathutil_mtxA_rotate_x(0x10000 - 0x2000);
    mathutil_mtxA_rotate_y((s32)((f32)(lbl_801A66A0 % 360) * 182.04444885253906f));
    lbl_8006E14C(2.0f);
    fn_80072558();
    fn_1_870BC(car, (s8)color, car, 0, (u8)car->unk_3B8, 1.0f);
    return 0;
}
/* fzgx:end fn_9_120C */

/* fzgx:begin fn_9_1310 */
s32 fn_9_1310(ColchgCar *car) {
    s16 color = lbl_9_bss_8->unk_C;

    lbl_8006D7F4(0.0f, 0.0f, -10.0f);
    mathutil_mtxA_rotate_y(-0x8000);
    mathutil_mtxA_rotate_x(0x2000);
    mathutil_mtxA_rotate_y((s32)(182.04444885253906f * (f32)(lbl_801A66A0 % 360)));
    lbl_8006E14C(2.0f);
    fn_80072558();
    fn_1_870BC(car, (s8)color, car, 0, (u8)car->unk_3B8, 1.0f);
    return 0;
}
/* fzgx:end fn_9_1310 */

/* fzgx:begin colchg_selcar_disp */
void colchg_selcar_disp(ColchgCar *cars) {
    char format[32];
    char longest[32];
    char text[32];
    char name[32];
    PanelTemplate panel;
    s16 car_id = lbl_9_bss_8->car;
    s16 i;
    s32 max_length;
    ColorEntry *entries = lbl_1_data_1FB6C[car_id];

    fn_1_496FC(160.0f, 50.0f);
    fn_1_4AE0C("[ \x83}\x83V\x83\x93\x83Z\x83\x8C\x83N\x83g ]\n\n");  /* "[ machine select ]" */
    max_length = 0;
    fn_1_7F49C(lbl_9_bss_8->car, lbl_9_data_0, name);
    for (i = 0; i < 41; i++) {
        s32 length = strlen(name);
        if (length > max_length) {
            max_length = length;
            fn_80083DB0(longest, name);
        }
    }
    fn_1_4B83C(format, "%%-%ds", longest, name);
    sprintf(text, format, name);
    fn_1_4955C(250.0f / fn_1_4B040(text), 1.0f);
    fn_1_4AE0C(text);
    fn_1_4955C(1.0f, 1.0f);
    fn_1_4955C(1.0f, 1.0f);
    fn_1_4AE0C("(%2d)\n", lbl_9_bss_8->car);
    if (PAD_BIT(lbl_1_bss_D58.unk_0, 8) && entries->id == -1) {
        /* "this machine cannot change color" */
        fn_1_4AE0C("\x82\xB1\x82\xCC\x82\xAD\x82\xE9\x82\xDC\x82\xCD\x83J\x83\x89\x81[\x83`\x83" "F\x83\x93\x83W\x82\xC5\x82\xAB\x82\xDC\x82\xB9\x82\xF1\n");
    }
    for (i = 0; i < 2; i++) {
        panel = lbl_1_rodata_26F8;
        panel.y = 255.0f;
        panel.x = 0.5f * (480.0f * (i % 2));
        switch (i) {
        case 0:
            fn_1_8D3F8(&lbl_9_bss_14[i], &panel, fn_9_120C, &cars[car_id]);
            break;
        case 1:
            fn_1_8D3F8(&lbl_9_bss_14[i], &panel, fn_9_1310, &cars[car_id]);
            break;
        }
    }
}
/* fzgx:end colchg_selcar_disp */

/* fzgx:begin colchg_selmate_disp */
void colchg_selmate_disp(ColchgCar *cars) {
    PanelTemplate panel;
    /* WARNING: compiler-diff device, not original code (one-field carrier for the loop counter) */
    struct { s16 value; } i;
    ColorEntry *entry;
    s16 car_id;

    car_id = lbl_9_bss_8->car;
    fn_1_496FC(160.0f, 50.0f);
    entry = lbl_1_data_1FB6C[lbl_9_bss_8->car];
    i.value = 0;
    while (entry->id != -1) {
        entry++;
        i.value++;
    }
    /* "[ material select ]" */
    fn_1_4AE0C("[ \x83}\x83" "e\x83\x8A\x83" "A\x83\x8B\x83Z\x83\x8C\x83N\x83g ]\n\n%2d(ID%d/%d))\n",
               lbl_9_bss_8->color_id, lbl_9_bss_8->color, i.value - 1);
    for (i.value = 0; i.value < 2; i.value++) {
        panel = lbl_1_rodata_26F8;
        panel.y = 255.0f;
        panel.x = 480.0f * (i.value % 2) * 0.5f;
        switch (i.value) {
        case 0:
            fn_1_8D3F8(&lbl_9_bss_14[i.value], &panel, fn_9_120C, &cars[car_id]);
            break;
        case 1:
            fn_1_8D3F8(&lbl_9_bss_14[i.value], &panel, fn_9_1310, &cars[car_id]);
            break;
        }
    }
}
/* fzgx:end colchg_selmate_disp */

/* fzgx:begin colchg_chgcol_disp */
void colchg_chgcol_disp(ColchgCar *cars) {
    PanelTemplate panel;
    s16 car_id = lbl_9_bss_8->car;
    s16 i;

    fn_1_496FC(160.0f, 50.0f);
    fn_1_4AE0C("[ \x83J\x83\x89\x81[\x83`\x83" "F\x83\x93\x83W ]\n");  /* "[ color change ]" */
    for (i = 0; i < 2; i++) {
        panel = lbl_1_rodata_26F8;
        panel.y = 255.0f;
        panel.x = 480.0f * (i % 2) * 0.5f;
        switch (i) {
        case 0:
            fn_1_8D3F8(&lbl_9_bss_14[i], &panel, fn_9_120C, &cars[car_id]);
            break;
        case 1:
            fn_1_8D3F8(&lbl_9_bss_14[i], &panel, fn_9_1310, &cars[car_id]);
            break;
        }
    }
}
/* fzgx:end colchg_chgcol_disp */

/* fzgx:begin colchg_ezsel_disp */
void colchg_ezsel_disp(void) {
    char name[0x20];

    fn_1_A8EB0(0x14, 0x14);
    fn_1_A8DD4("%2d/%2d [%-16s]", lbl_9_bss_8->car, 0x29, fn_1_7F49C(lbl_9_bss_8->car, 0, name));
}
/* fzgx:end colchg_ezsel_disp */

/* fzgx:begin colchg_save_disp */
void colchg_save_disp(void) {
    fn_1_A8EB0(0x14, 0x14);
    fn_1_A8DD4("Save?\n");
}
/* fzgx:end colchg_save_disp */

/* fzgx:begin fn_9_1AC4 */
void fn_9_1AC4(void) {
    fn_1_A8EB0(0x14, 0xA);
    fn_1_A8DD4("Select Load Data\n");
}
/* fzgx:end fn_9_1AC4 */

/* fzgx:begin fn_9_1AFC */
void fn_9_1AFC(void) {
    static const GXColor color = {0xFF, 0xFF, 0xFF, 0xFF};
    LightObj light;
    Vec3 dir;

    lbl_8006DCA4();
    lbl_8006E1D8(&dir, 200.0f, 200.0f, 200.0f);
    fn_1_7BCCC(&dir);
    fn_80035680(&light, dir.x, dir.y, dir.z);
    fn_80035690(&light, dir.x, dir.y, dir.z);
    fn_80035420(&light, 0.0f, 0);
    fn_800356AC(&light, color);
    GXInitLightDistAttn(&light, 0.0f, 0.0f, 0);
    fn_1_7BB80(&light, 1);
    fn_1_7BD6C(1);
    fn_80074CF4(0.6f, 0.6f, 0.6f);
}
/* fzgx:end fn_9_1AFC */

/* fzgx:begin fn_9_1BCC */
void fn_9_1BCC(void) {
    CarEntry entries[0x29];
    s8 i;

    for (i = 0; i < 0x29; i++) {
        fn_1_80058(i, &entries[i]);
        entries[i].unk_4 = 1;
        entries[i].id = i;
    }
    fn_1_80C18(lbl_9_bss_4, entries, 0x29);
}
/* fzgx:end fn_9_1BCC */

/* fzgx:begin fn_9_1C54 */
ColchgScene lbl_9_data_1B8[9] = {
    {"SMD_CARCOLCHG_TOP", fn_1_12B4, fn_1_12FC, fn_1_1300},
    {"SMD_CARCOLCHG_MENU", colchg_menu_init, fn_9_454, fn_9_534},
    {"SMD_CARCOLCHG_SELCAR", colchg_selcar_init, fn_9_5D8, fn_9_6F0},
    {"SMD_CARCOLCHG_LOAD", fn_9_1054, fn_9_10BC, fn_9_1124},
    {"SMD_CARCOLCHG_SAVE", colchg_save_init, fn_9_FD0, fn_9_1018},
    {"SMD_CARCOLCHG_SELTEX", colchg_selmate_init, fn_9_7DC, fn_9_A18},
    {"SMD_CARCOLCHG_CHGCOL", colchg_chgcol_init, fn_9_AF0, fn_9_DC0},
    {"SMD_CARCOLCHG_EZSEL", colchg_ezsel_init, fn_9_E4C, fn_9_F38},
    {"SMD_CARCOLCHG_BOTTOM", fn_1_12B4, fn_1_12FC, fn_1_1300},
};

// Select the color-change entry for the current car and invoke its handler.
void fn_9_1C54(void) {
    ColchgScene *scene = lbl_9_data_1B8;

    scene += lbl_1_bss_962 - 0x71;
    lbl_1_bss_71688 = scene->main;
    lbl_1_bss_7168C = scene->disp;
    scene->init();
}
/* fzgx:end fn_9_1C54 */
