#include "types.h"
#include "dolphin/hw_regs.h"
#include "dolphin/os/OSTime.h"
#include "dol/gx_tables.h"

/* The progressive scan prompt. */
typedef struct {
    u32 enabled;
    s8 state;
    u8 progressive;
    s16 timer;
} ProgScan;

/* A controller state (0x14 bytes). */
typedef struct {
    u16 button;
    u16 unk_2;
    u8 pad_4[0x4];
    u16 down;
    u16 unk_A;
    u8 pad_C[0x8];
} ProgPad;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
} ProgDisplay;

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} ProgColor;

extern GXRenderModeObj *lbl_801A6CF4;
extern GXRenderModeObj lbl_8012B030;
extern GXRenderModeObj lbl_8012AFB8;
extern GXRenderModeObj lbl_8012B0A8;
extern GXRenderModeObj lbl_8012B06C;
extern GXRenderModeObj lbl_8019E150;
extern ProgDisplay *lbl_801A6D30;
extern u8 lbl_801A66B0[];
extern s32 lbl_801A66B4;
extern ProgPad lbl_1_bss_9F8[4];
extern s16 lbl_1_bss_962;
extern ProgPad lbl_1_bss_D58;

#include "game/pad.h"

extern void OSPanic(const char *file, int line, const char *msg, ...);
extern s32 OSGetResetCode(void);
extern u32 OSGetProgressiveMode(void);
extern void OSSetProgressiveMode(s32 mode);
extern u32 VIGetDTVStatus(void);
extern u32 VIGetTvFormat(void);
extern void VIConfigure(GXRenderModeObj *rmode);
extern void VIWaitForRetrace(void);
extern void VIFlush(void);
extern void GXAdjustForOverscan(GXRenderModeObj *rmIn, GXRenderModeObj *rmOut, u16 hor, u16 ver);
extern void fn_80034ECC(u8 aa, u8 *pattern, u8 vf, u8 *filter);
extern void fn_80035110(void *buf, u8 flag);
extern void fn_80038EEC(f32 x, f32 y, f32 w, f32 h, f32 nearZ, f32 farZ);
extern void fn_8006CE1C(f32 value);
extern void fn_80070620(s32 value);
extern void fn_80074188(u32 x, u32 y, u32 w, u32 h);
extern void fn_8007423C(u32 x, u32 y, u32 w, u32 h);
extern void fn_800743C4(s32 w, u32 h);
extern void fn_1_3308(void);
extern void fn_1_4A00(s32 arg0, s32 arg1, u32 arg2);
extern s32 fn_1_4C10(void);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16 size);
extern void fn_1_49514(ProgColor *color);
extern void fn_1_4954C(f32 value);
extern void fn_1_495B0(u32 flags);
extern void fn_1_495C8(u8 value);
extern void fn_1_4965C(u8 value);
extern void fn_1_496FC(f32 x, f32 y);
extern void fn_1_4A0D8(const char *text);
extern void fn_1_4AF10(const char *text);
extern void fn_1_549F4(void *mtx, void *pos, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
extern void fn_1_54DCC(u8 *buf);
extern void fn_1_A9868(void);
extern void fn_1_A9A28(int x0, int y0, int x1, int y1, ProgColor *color);
extern void fn_1_AA538(void);

extern f32 fn_1_A6FE8(void);
extern void fn_1_A7024(f32 fovy, f32 aspect, f32 near, f32 far);
extern void fn_1_A714C(f32 *fovy, f32 *aspect, f32 *near, f32 *far);

void fn_1_A5F44(void);
s32 fn_1_A6480(void);
void fn_1_A6870(u32 *mode);

u32 lbl_1_bss_6F5F0;
u32 lbl_1_bss_6F5F4;
s32 lbl_1_bss_6F600;
static ProgScan lbl_1_bss_6F5F8;
ProgScan *lbl_1_data_341B8 = &lbl_1_bss_6F5F8;

/* fzgx:begin fn_1_A5D88 */
u16 fn_1_A5D88(void) {
    return lbl_801A6CF4->fbWidth;
}
/* fzgx:end fn_1_A5D88 */

/* fzgx:begin fn_1_A5D9C */
u16 fn_1_A5D9C(void) {
    return lbl_801A6CF4->efbHeight;
}
/* fzgx:end fn_1_A5D9C */

/* fzgx:begin fn_1_A5DB0 */
u16 fn_1_A5DB0(void) {
    return lbl_801A6CF4->xfbHeight;
}
/* fzgx:end fn_1_A5DB0 */

/* fzgx:begin fn_1_A5DC4 */
// Return whether relocation processing is in one of the active states.
s8 fn_1_A5DC4(void) {
    if ((s32)lbl_1_bss_6F5F0 == 1 || (s32)lbl_1_bss_6F5F0 == 2) {
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_A5DC4 */

/* fzgx:begin fn_1_A5DEC */
void fn_1_A5DEC(void) {
    u32 ticks;
    u32 start;

    if (VIGetDTVStatus() != 0) {
        fn_1_3308();
        start = OSGetTick();
        do {
            ticks = (OS_BUS_CLOCK >> 2) / 1000;
        } while (((OSGetTick() / ticks) - (start / ticks)) < 500);
        fn_1_3308();
        if (PAD_BIT(lbl_1_bss_9F8[0].button, 9) || PAD_BIT(lbl_1_bss_9F8[1].button, 9) ||
            PAD_BIT(lbl_1_bss_9F8[2].button, 9) || PAD_BIT(lbl_1_bss_9F8[3].button, 9) ||
            OSGetProgressiveMode() != 0) {
            lbl_1_data_341B8->enabled = 1;
            return;
        }
        lbl_1_data_341B8->enabled = 0;
        return;
    }
    lbl_1_data_341B8->enabled = 0;
}
/* fzgx:end fn_1_A5DEC */

/* fzgx:begin fn_1_A5EFC */
void fn_1_A5EFC(void) {
    lbl_1_bss_6F5F0 = 0;
    if ((s32)lbl_1_data_341B8->enabled != 0) {
        lbl_1_data_341B8->state = 0;
        lbl_1_data_341B8->progressive = 1;
        lbl_1_data_341B8->timer = 600;
    }
}
/* fzgx:end fn_1_A5EFC */

/* fzgx:begin fn_1_A5F44 */
void fn_1_A5F44(void) {
    char *displayIn[6] = {"Would you like to display in", "", "", "", "",
                          "\203v\203\215\203O\203\214\203b\203V\203u\203\202\201[\203h\202\305"};
    char *progQuestion[6] = {"Progressive Scan Mode?", "", "", "", "",
                             "\225\\[\202\320\202\345\202\244]\216\246[\202\266]\202\265\202\334\202\267\202\251\201H"};
    char *yes[6] = {"YES", "", "", "", "", "\202\315\202\242"};
    char *no[6] = {"NO", "", "", "", "", "\202\242\202\242\202\246"};
    char *cursorYes[6] = {"<     >", "", "", "", "", "[\201@\201@]"};
    char *cursorNo[6] = {"<    >", "", "", "", "", "[\201@\201@\201@]"};
    char *setTo[6] = {"Screen display has been set to", "", "", "", "",
                      "\211\346[\202\252]\226\312[\202\337\202\361 ]\225\\[\202\320\202\345\202\244]\216\246[\202\266]\203\202\201[\203h\202\315"};
    char *progMode[6] = {"Progressive Scan Mode.", "", "", "", "",
                         "\203v\203\215\203O\203\214\203b\203V\203u\203\202\201[\203h\202\311"};
    char *interlace[6] = {"Interlace Mode.", "", "", "", "",
                          "\203C\203\223\203^\201[\203\214\201[\203X\203\202\201[\203h\202\311"};
    char *wasSet[6] = {"", "", "", "", "", "\203Z\203b\203g\202\263\202\352\202\334\202\265\202\275\201B"};
    ProgColor color;

    fn_1_49410();
    fn_1_494DC(42);
    fn_1_495B0(0x80000000);
    fn_1_4965C(0);
    color = (ProgColor){0xFF, 0xFF, 0xFF, 0x00};
    fn_1_49514(&color);
    fn_1_4954C(0.1f);
    fn_1_495C8(9);
    switch (lbl_1_data_341B8->state) {
    case 0:
    case 5:
        fn_1_496FC(320.0f, 184.0f);
        fn_1_4AF10(displayIn[lbl_801A66B4]);
        fn_1_496FC(320.0f, 221.0f);
        fn_1_4AF10(progQuestion[lbl_801A66B4]);
        fn_1_496FC(256.0f, 258.0f);
        fn_1_4AF10(yes[lbl_801A66B4]);
        if ((s32)lbl_1_data_341B8->progressive == 1 && lbl_1_data_341B8->state != 5) {
            fn_1_496FC(256.0f, 258.0f);
            fn_1_4A0D8(cursorYes[lbl_801A66B4]);
        }
        fn_1_496FC(384.0f, 258.0f);
        fn_1_4AF10(no[lbl_801A66B4]);
        if ((s32)lbl_1_data_341B8->progressive != 1 && lbl_1_data_341B8->state != 5) {
            fn_1_496FC(384.0f, 258.0f);
            fn_1_4A0D8(cursorNo[lbl_801A66B4]);
        }
        break;
    case 4:
        fn_1_496FC(320.0f, 184.0f);
        fn_1_4AF10(setTo[lbl_801A66B4]);
        fn_1_496FC(320.0f, 221.0f);
        if ((s32)lbl_1_data_341B8->progressive == 1) {
            fn_1_4AF10(progMode[lbl_801A66B4]);
        } else {
            fn_1_4AF10(interlace[lbl_801A66B4]);
        }
        if (lbl_801A66B4 != 5) {
            fn_1_496FC(320.0f, 258.0f);
            fn_1_4AF10(wasSet[lbl_801A66B4]);
        }
        break;
    case 1:
        return;
    }
}
/* fzgx:end fn_1_A5F44 */

/* fzgx:begin fn_1_A6480 */
s32 fn_1_A6480(void) {
    s32 buttonA;
    s32 buttonB;
    s32 start;
    s8 state;

    buttonA = 1;
    if (!PAD_BIT(lbl_1_bss_D58.down, 0) && !PAD_BIT(lbl_1_bss_D58.unk_A, 0)) {
        buttonA = 0;
    }
    buttonB = 1;
    if (!PAD_BIT(lbl_1_bss_D58.down, 1) && !PAD_BIT(lbl_1_bss_D58.unk_A, 1)) {
        buttonB = 0;
    }
    start = PAD_BIT(lbl_1_bss_D58.down, 8);
    state = lbl_1_data_341B8->state;
    switch (state) {
    case 0:
        fn_8006CE1C(0.0f);
        if (((u32)__cntlzw(((-2147483647 - 1) - OSGetResetCode())) >> 5) != 0) {
            lbl_1_data_341B8->state = 2;
        } else {
            if (buttonA != 0) {
                lbl_1_data_341B8->progressive = 1;
            } else if (buttonB != 0) {
                lbl_1_data_341B8->progressive = 0;
            }
            if ((--lbl_1_data_341B8->timer) <= 0 || start != 0) {
                lbl_1_data_341B8->state = 2;
            }
        }
        break;
    case 2:
        if ((s32)lbl_1_data_341B8->progressive == 1) {
            lbl_1_data_341B8->timer = 100;
            OSSetProgressiveMode(1);
        } else {
            lbl_1_data_341B8->timer = 1;
            OSSetProgressiveMode(0);
        }
        lbl_1_data_341B8->state = 3;
        break;
    case 3:
        if (--lbl_1_data_341B8->timer <= 0) {
            lbl_1_data_341B8->state = 4;
            lbl_1_data_341B8->timer = 300;
        } else if (lbl_1_data_341B8->timer == 70) {
            fn_80070620(1);
        }
        break;
    case 4:
        if ((--lbl_1_data_341B8->timer) <= 0 || start != 0) {
            return 1;
        }
        break;
    case 5:
        if (fn_1_4C10() == 0) {
            lbl_1_data_341B8->state = 0;
            lbl_1_data_341B8->progressive = 1;
            lbl_1_data_341B8->timer = 600;
        }
        break;
    }
    return 0;
}
/* fzgx:end fn_1_A6480 */

/* fzgx:begin fn_1_A66FC */
// Records the reset state and performs the appropriate relocation startup or recovery.
s32 fn_1_A66FC(s32 value) {
    s32 result;

    lbl_1_bss_6F5F4 = value;
    if (((u32)__cntlzw(((-2147483647 - 1) - OSGetResetCode())) >> 5) != 0) {
        if (OSGetProgressiveMode() != 0) {
            result = 1;
        } else {
            OSSetProgressiveMode(0);
            lbl_1_data_341B8->enabled = 0;
            result = 1;
        }
        if (lbl_801A66B0[3] != 0) {
            lbl_1_bss_6F5F0 = 1;
            fn_1_A6870(&lbl_1_bss_6F5F0);
        }
    } else if ((s32)lbl_1_data_341B8->enabled != 0) {
        fn_1_A5F44();
        result = fn_1_A6480();
    } else {
        OSSetProgressiveMode(0);
        lbl_1_data_341B8->enabled = 0;
        result = 1;
    }
    return result;
}
/* fzgx:end fn_1_A66FC */

/* fzgx:begin fn_1_A67E8 */
void fn_1_A67E8(void) {
    s32 mode;
    s32 next;

    next = lbl_1_bss_6F5F0 + 1;
    if (next > 3) {
        mode = 0;
    } else {
        mode = 3;
        if (next >= 0) {
            mode = next;
        }
    }
    lbl_1_bss_6F5F0 = mode;
    fn_1_A6870(&lbl_1_bss_6F5F0);
}
/* fzgx:end fn_1_A67E8 */

/* fzgx:begin fn_1_A6840 */
void fn_1_A6840(u32 value) {
    u32 *value_ptr;

    value_ptr = &lbl_1_bss_6F5F0;
    *value_ptr = value & 0xff;
    fn_1_A6870(value_ptr);
}
/* fzgx:end fn_1_A6840 */

/* fzgx:begin fn_1_A6870 */
void fn_1_A6870(u32 *mode) {
    GXRenderModeObj *rmode;
    s32 tv;
    s8 flag;
    struct {
        u8 unk_0[0x6c];
        f32 unk_6c[6];
    } loc_18;
    f32 loc_14;
    f32 loc_10;
    f32 loc_C;
    f32 loc_8;

    switch (VIGetTvFormat()) {
    case 0:
        if (OSGetProgressiveMode() != 0) {
            *lbl_801A6CF4 = lbl_8012B030;
        } else {
            *lbl_801A6CF4 = lbl_8012AFB8;
        }
        break;
    case 1:
        *lbl_801A6CF4 = lbl_8012B0A8;
        break;
    case 2:
        *lbl_801A6CF4 = lbl_8012B06C;
        break;
    default:
        OSPanic("prog.c", 557, "init_system: invalid TV format\n");
        break;
    }

    switch (*mode) {
    case 0:
        GXAdjustForOverscan(lbl_801A6CF4, &lbl_8019E150, 0, 16);
        lbl_801A6CF4 = &lbl_8019E150;
        VIConfigure(&lbl_8019E150);
        VIWaitForRetrace();
        VIWaitForRetrace();
        VIFlush();
        *mode = 0;
        break;
    case 1:
        GXAdjustForOverscan(lbl_801A6CF4, &lbl_8019E150, 0, 16);
        lbl_801A6CF4 = &lbl_8019E150;
        VIConfigure(&lbl_8019E150);
        VIWaitForRetrace();
        VIWaitForRetrace();
        VIFlush();
        *mode = 1;
        break;
    case 2:
        lbl_801A6CF4->xfbHeight = 360;
        lbl_801A6CF4->viHeight = 360;
        lbl_801A6CF4->viXOrigin = 40;
        lbl_801A6CF4->viYOrigin = 60;
        GXAdjustForOverscan(lbl_801A6CF4, &lbl_8019E150, 0, 12);
        lbl_801A6CF4 = &lbl_8019E150;
        VIConfigure(&lbl_8019E150);
        VIWaitForRetrace();
        VIWaitForRetrace();
        VIFlush();
        *mode = 2;
        break;
    case 3:
        GXAdjustForOverscan(lbl_801A6CF4, &lbl_8019E150, 0, 0);
        lbl_801A6CF4 = &lbl_8019E150;
        VIConfigure(&lbl_8019E150);
        VIWaitForRetrace();
        VIWaitForRetrace();
        VIFlush();
        *mode = 3;
        break;
    }

    fn_8007423C(0, 0, lbl_801A6CF4->fbWidth, lbl_801A6CF4->efbHeight);
    fn_800743C4(lbl_801A6CF4->fbWidth, lbl_801A6CF4->xfbHeight);
    fn_80035110((void *)lbl_801A6D30->unk_4, 1);
    fn_80035110((void *)lbl_801A6D30->unk_8, 0);
    fn_80035110((void *)lbl_801A6D30->unk_4, 0);

    fn_1_54DCC(loc_18.unk_0);
    fn_1_549F4(loc_18.unk_0, loc_18.unk_6c, loc_18.unk_6c[2], fn_1_A6FE8(), loc_18.unk_6c[4], loc_18.unk_6c[5]);
    fn_1_A714C(&loc_14, &loc_10, &loc_C, &loc_8);
    fn_1_A7024(loc_14, fn_1_A6FE8(), loc_C, loc_8);

    rmode = lbl_801A6CF4;
    fn_80038EEC(0.0f, 0.0f, rmode->fbWidth, rmode->efbHeight, 0.0f, 1.0f);
    fn_80074188(0, 0, lbl_801A6CF4->fbWidth, lbl_801A6CF4->efbHeight);
    fn_80034ECC(lbl_801A6CF4->aa, lbl_801A6CF4->sample_pattern[0], 1, lbl_801A6CF4->vfilter);

    tv = lbl_1_bss_6F5F0;
    if (tv == 1 || tv == 2) {
        flag = 1;
    } else {
        flag = 0;
    }
    if (flag) {
        lbl_801A66B0[3] = 1;
    } else {
        lbl_801A66B0[3] = 0;
    }
}
/* fzgx:end fn_1_A6870 */

/* fzgx:begin fn_1_A6E68 */
void fn_1_A6E68(void) {
    if (448.0f == lbl_801A6CF4->xfbHeight) {
        fn_1_A9868();
        {
            ProgColor color = {0xFF, 0x00, 0x00, 0xFF};
            fn_1_A9A28(0, 25, 640, 25, &color);
        }
        {
            ProgColor color = {0xFF, 0x00, 0x00, 0xFF};
            fn_1_A9A28(0, 454, 640, 454, &color);
        }
        fn_1_AA538();
    }
}
/* fzgx:end fn_1_A6E68 */

/* fzgx:begin fn_1_A6F10 */
u32 *fn_1_A6F10(void) {
    return &lbl_1_bss_6F5F0;
}
/* fzgx:end fn_1_A6F10 */

/* fzgx:begin fn_1_A6F1C */
u32 fn_1_A6F1C(void) {
    return lbl_1_bss_6F5F0;
}
/* fzgx:end fn_1_A6F1C */

/* fzgx:begin fn_1_A6F2C */
s32 fn_1_A6F2C(void) {
    s32 result = 0;
    s8 state;

    if (lbl_1_bss_962 == 0x99) {
        state = lbl_1_data_341B8->state;
        if (state == 0 || state == 5) {
            result = 1;
        }
    }

    return result;
}
/* fzgx:end fn_1_A6F2C */

/* fzgx:begin fn_1_A6F6C */
s32 fn_1_A6F6C(void) {
    s32 result = 0;

    if (lbl_1_bss_962 == 0x99) {
        if (lbl_1_data_341B8->state == 5) {
            result = 1;
        }
    }

    return result;
}
/* fzgx:end fn_1_A6F6C */

/* fzgx:begin fn_1_A6FA0 */
void fn_1_A6FA0(void) {
    fn_1_4A00(0, 0x3c, lbl_1_bss_6F5F4);
    lbl_1_data_341B8->state = 5;
}
/* fzgx:end fn_1_A6FA0 */
