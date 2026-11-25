#include "types.h"
#include "dolphin/hw_regs.h"

struct Mtx44Struct {
    f32 unk_0;
    u8 pad_4[0x4];
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x4];
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    u8 pad_20[0x8];
    f32 unk_28;
    f32 unk_2C;
    u8 pad_30[0x10];
};

typedef struct {
    void *image;
    u16 code;
    u16 width;
} FontGlyph;

typedef struct {
    u32 dummy[8];
} GXTexObj;

typedef struct OSFontHeader {
    u16 fontType; u16 firstChar; u16 lastChar; u16 invalChar;
    u16 ascent; u16 descent; u16 width; u16 leading;
    u16 cellWidth; u16 cellHeight; u32 sheetSize;
    u16 sheetFormat; u16 sheetColumn; u16 sheetRow; u16 sheetWidth;
    u16 sheetHeight; u16 widthTable; u32 sheetImage; u32 sheetFullSize;
    u8 c0; u8 c1; u8 c2; u8 c3;
} OSFontHeader;

typedef struct StringGroup {
    u8 **lines;
    s32 numStrings;
} StringGroup;

typedef struct {
    u16 unk00;
    u8 unk02[7];
    s8 unk09;
} Rec8;

typedef struct {
    u16 unk00;
    u8 unk02[8];
    s8 unk0A;
} RecC;

extern u32 lbl_801A6E98;
extern u32 lbl_801A6D00[2];
extern const f32 lbl_801A6E9C;
extern const f32 lbl_801A6EA0;
extern const f32 lbl_801A6EA4;
extern const f32 lbl_801A6EA8;
extern s16 lbl_801A66EC;
extern FontGlyph lbl_8015B940[128];
extern u8 lbl_801A66DB;
extern u32 lbl_801A66F0;
extern StringGroup *lbl_801A66F4;
extern s32 (*lbl_801A66DC)(void);
extern void (*lbl_801A66E0)(void);
extern void (*lbl_801A66E4)(void);
extern void (*lbl_801A66E8)(void);
extern u8 lbl_801A66D8;
extern char lbl_801A63F0[4];
extern char lbl_801A63F4[4];
extern u8 *lbl_80121F1C[];
extern u8 lbl_80121F84[];
extern u8 *lbl_80121FC8[];
extern u8 lbl_80121FDC[];
extern u8 lbl_80121FF4[];
extern u8 lbl_80122014[];
extern u8 *lbl_801A63D8[];
extern u8 *lbl_801A63E0[];
extern u8 lbl_801A63E8[];
extern u8 *lbl_801A63EC[];
extern u8 lbl_801A66D9;
extern u8 lbl_801A66DA;
extern const f64 lbl_801A6EC8;
extern const f64 lbl_801A6EF8;
extern u32 lbl_8015BD40[];
extern u32 lbl_801A63F8;
extern u32 lbl_801A6708[2];

extern u32 GXLoadPosMtxImm(u32, u32);
extern u32 fn_800371F8(u32, void *);
extern void fn_80071ED4(u32, f32, f32);
extern u32 fn_80072CC4(u32, u32, u32, u32, u32);
extern u32 fn_80072D64(u32, u32, u32, u32, u32, u32);
extern u32 fn_80072EDC(u32, u32);
extern u32 fn_800734A8(u32, u32, u32, u32);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
extern void fn_8007245C(u32);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_80073678(u32);
extern void fn_800737E4(struct Mtx44Struct *, s32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, u32, u32, u32, u32, u32);
extern void fn_80074918(u8, s32, u8);
extern void lbl_8006D758(void);
extern void GXInitTexObj(GXTexObj *, void *, u16, u16, s32, s32, s32, u8);
extern void GXInvalidateTexAll(void);
extern void fn_80073778(GXTexObj *, s32);
extern void fn_8003462C(s32, s32, u16);
extern u32 DVDReadAsyncPrio(u32, u32, u32, u32, u32, u32);
extern u32 OSGetArenaHi(void);
extern u32 OSGetFontEncode(void);
extern void *OSAllocFromArenaHi(u32, u32);
extern u32 fn_8000CEBC(OSFontHeader *, void *);
extern void *OSAllocFromArenaLo(u32, u32);
extern void fn_8000D1F0(u8 *, void *, u32, u32, u32 *);
extern void DCStoreRange(void *, u32);
extern void OSSetArenaHi(u32);
extern s32 DVDGetDriveStatus(void);
extern int strcmp(const char *, const char *);
extern void fn_80007B68(void);
extern s32 fn_8006FDEC(void);
extern void fn_8006FEFC(void);
extern void fn_8006FD1C(void);
extern s32 fn_8000F5F0(void);
extern void PADRead(void *);
extern void fn_8006B470(void *);
extern u32 fn_8006FFCC(u32);
extern void VIWaitForRetrace(void);
extern void OSResetSystem(int, u32, int);
extern void VISetBlack(u32);
extern u32 strcpy(u32, u32);
extern void fn_80006B4C(void);

s32 fn_80006334(u8 *arg0);
void fn_8000659C(void);
void fn_80006914(void (*arg0)(void));
void fn_8000691C(void);
void fn_80006AEC(s32 (*arg0)(void));
void fn_80006B30(void (*func)(void));

u8 *lbl_80122030[5] = {
    lbl_80121FDC, lbl_801A63E8, lbl_80121FF4, lbl_80121F84, lbl_80122014,
};

char lbl_80122044[23] = "Reading the Game Disc.";

StringGroup lbl_8012205C[6] = {
    {lbl_80121F1C, 3},
    {lbl_801A63D8, 2},
    {lbl_801A63E0, 2},
    {lbl_80121FC8, 5},
    {lbl_80122030, 5},
    {lbl_801A63EC, 1},
};

#define FIFO_F32(v) (*(volatile f32 *)GX_FIFO_BASE = (v))  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */

static inline FontGlyph *find_glyph(s32 code) {
    FontGlyph *glyph = lbl_8015B940;
    s32 i;

    for (i = 0; i < lbl_801A66EC; i++, glyph++) {
        if (glyph->code == code) {
            return glyph;
        }
    }
    return NULL;
}

void fn_80005EDC(void) {
    u32 color = lbl_801A6E98;
    u32 buf0;
    u32 buf1;
    u32 buf2;
    struct Mtx44Struct mtx;

    fn_8007245C(8704);
    fn_80074788(0);
    fn_80074660(1);
    fn_80073678(1);
    fn_80073C6C(0);
    fn_80072EDC(0, 0);
    fn_800745A4(0, 1, 4, 60, 0, 125);
    fn_800734A8(0, 0, 0, 255);
    fn_80072AB0(0, 0, 0);
    fn_80072C24(0, 15, 2, 8, 4);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 1, 4, 2);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_800747D0(4, 0, 0, 0, 0, 2, 2);
    buf0 = color;
    fn_800371F8(1, &buf0);
    fn_80074918(1, 7, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_80071ED4(0, lbl_801A6E9C, lbl_801A6EA0);
    fn_80072864(2);
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00[0], 0);
    C_MTXOrtho(&mtx, lbl_801A6E9C, lbl_801A6EA4, lbl_801A6E9C, lbl_801A6EA8, lbl_801A6E9C, lbl_801A6EA0);
    fn_800737E4(&mtx, 1);
    ((u8 *)&color)[0] = 255;
    ((u8 *)&color)[1] = 255;
    ((u8 *)&color)[2] = 255;
    ((u8 *)&color)[3] = 255;
    buf1 = color;
    fn_800371F8(1, &buf1);
    ((u8 *)&color)[0] = 0;
    ((u8 *)&color)[1] = 0;
    ((u8 *)&color)[2] = 0;
    ((u8 *)&color)[3] = 0;
    buf2 = color;
    fn_800371F8(2, &buf2);
}

void fn_800060D8(f32 x, f32 y, f32 z, u8 *str) {
    GXTexObj obj;
    FontGlyph *glyph;
    u32 code;
    f32 nz;
    f32 y2;
    f32 x2;

    nz = -z;
    while (*str != 0) {
        if (fn_80006334(str)) {
            code = *(u16 *)str;
            str += 2;
        } else {
            code = *str;
            str += 1;
        }
        if (code == 0x20) {
            x += 8.0;
            continue;
        }
        glyph = find_glyph(code);
        if (glyph == NULL) {
            continue;
        }
        GXInitTexObj(&obj, glyph->image, 24, 24, 0, 0, 0, 0);
        GXInvalidateTexAll();
        fn_80073778(&obj, 0);
        y2 = 24.0 + y;
        x2 = x + glyph->width;
        fn_8003462C(0x80, 7, 4);
        FIFO_F32(x);
        FIFO_F32(y);
        FIFO_F32(nz);
        FIFO_F32(0.0f);
        FIFO_F32(0.0f);
        FIFO_F32(x2);
        FIFO_F32(y);
        FIFO_F32(nz);
        FIFO_F32(glyph->width / 24.0);
        FIFO_F32(0.0f);
        FIFO_F32(x2);
        FIFO_F32(y2);
        FIFO_F32(nz);
        FIFO_F32(glyph->width / 24.0);
        FIFO_F32(1.0f);
        FIFO_F32(x);
        FIFO_F32(y2);
        FIFO_F32(nz);
        FIFO_F32(0.0f);
        FIFO_F32(1.0f);
        x += glyph->width;
    }
}

#pragma opt_propagation off
s32 fn_80006334(u8 *arg0) {
    return ((*arg0 >> 7) & 0x1);
}

void fn_80006340(u32 arg0) {
    if ((s32)arg0 == -1) { return; }
    lbl_801A66DB = 0;
}

u32 fn_80006354(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    lbl_801A66DB = 1;
    DVDReadAsyncPrio(arg0, arg1, arg2, arg3, (u32)fn_80006340, 2);
    while ((s8)lbl_801A66DB != 0) {
        fn_8000659C();
    }
    return *(u32 *)(arg0 + 52);
}

void fn_800063AC(u32 arg0, u32 arg1, u32 arg2) {
    struct {
        u32 arena;
        s32 stringIndex;
        u8 **strings;
        s32 groupIndex;
        StringGroup *group;
        void *font;
        u8 *start;
        FontGlyph *glyph;
        s32 count;
        u8 *text;
    } locals;
#define arena locals.arena
#define stringIndex locals.stringIndex
#define strings locals.strings
#define groupIndex locals.groupIndex
#define group locals.group
#define font locals.font
#define start locals.start
#define glyph locals.glyph
#define count locals.count
#define text locals.text
    u32 width;
    s32 i;
    u32 code;
    void *temp;
    arena = 0;
    stringIndex = 0;
    strings = 0;
    groupIndex = 0;
    group = 0;
    font = 0;
    start = 0;
    glyph = 0;
    count = 0;
    text = 0;
    if ((OSGetFontEncode() & 0xFFFF) == 1) {
        StringGroup *table = lbl_8012205C;
        lbl_801A66F0 = 6;
        lbl_801A66F4 = table;
    } else {
        StringGroup *table = lbl_8012205C;
        lbl_801A66F0 = 6;
        lbl_801A66F4 = table;
    }
    arena = OSGetArenaHi();
    if ((OSGetFontEncode() & 0xFFFF) == 1) {
        font = OSAllocFromArenaHi(0x90EE4, 32);
        temp = OSAllocFromArenaHi(0x4D000, 32);
    } else {
        font = OSAllocFromArenaHi(0x10120, 32);
        temp = OSAllocFromArenaHi(0x3000, 32);
    }
    fn_8000CEBC((OSFontHeader *)font, temp);
    group = lbl_801A66F4;
    for (groupIndex = 0; groupIndex < (s32)lbl_801A66F0; groupIndex++, group++) {
        strings = group->lines;
        for (stringIndex = 0; stringIndex < group->numStrings; stringIndex++, strings++) {
            text = *strings;
            count = lbl_801A66EC;
            while ((code = *text) != 0) {
                start = text;
                if (code & 0x80) {
                    code = *(u16 *)text;
                    text += 2;
                } else {
                    text++;
                }
                if (code == 32) continue;
                { FontGlyph *base = lbl_8015B940; glyph = base; }
                for (i = 0; i < count; i++, glyph++) {
                    if (glyph->code == code) break;
                }
                if (i < count) continue;
                glyph->code = code;
                glyph->image = OSAllocFromArenaLo(0x120, 32);
                fn_8000D1F0(start, glyph->image, 0, 6, &width);
                DCStoreRange(glyph->image, 0x120);
                glyph->width = width;
                count++;
            }
            lbl_801A66EC = count;
        }
    }
    OSSetArenaHi(arena);
    fn_80006914(fn_8000691C);
    fn_80006AEC(0);
#undef arena
#undef stringIndex
#undef strings
#undef groupIndex
#undef group
#undef font
#undef start
#undef glyph
#undef count
#undef text
}
#pragma opt_propagation reset

#pragma fp_contract off
static inline u32 is_wide(u8 *str) {
    return (*str >> 7) & 1;
}

static inline s32 get_text_width(u8 *str) {
    s32 width = 0;
    u32 code;
    FontGlyph *glyph;

    while (*str != 0) {
        if (strcmp((char *)str, lbl_801A63F0) == 0) {
            break;
        }
        if (strcmp((char *)str, lbl_801A63F4) == 0) {
            break;
        }
        if (is_wide(str)) {
            code = *(u16 *)str;
            str += 2;
        } else {
            code = *str;
            str += 1;
        }
        if (code == 0x20) {
            width += 8.0;
            continue;
        }
        glyph = find_glyph(code);
        if (glyph != NULL) {
            width += glyph->width;
        }
    }
    return width;
}

static inline void show_message(s32 msg) {
    StringGroup *group;
    s32 i;

    fn_80007B68();
    if (msg >= 0) {
        fn_80005EDC();
        group = &lbl_801A66F4[msg];
        for (i = 0; i < group->numStrings; i++) {
            fn_800060D8(320.0 - 0.5 * get_text_width(group->lines[i]),
                        240.0 - 0.5 * (24.0 * group->numStrings) + 24.0 * i,
                        10.0f, group->lines[i]);
        }
    }
    fn_8006FDEC();
    fn_8006FEFC();
    fn_8006FD1C();
}

static inline BOOL is_done(s32 status, s32 shown) {
    if (status == 0) {
        return TRUE;
    }
    if (!shown && status == 1) {
        return TRUE;
    }
    return FALSE;
}

void fn_8000659C(void) {
    s32 status;
    s32 shown;
    s32 msg;

    if (lbl_801A66DC != NULL && lbl_801A66DC() != 0) {
        return;
    }
    msg = -1;
    shown = 0;
    do {
        status = DVDGetDriveStatus();
        if (status != -1) {
            lbl_801A66D8 = 1;
            lbl_801A66E0();
            lbl_801A66D8 = 0;
        }
        switch (status) {
        case 4:
            msg = 1;
            break;
        case 5:
            msg = 0;
            break;
        case 6:
            msg = 2;
            break;
        case 11:
            msg = 3;
            break;
        case -1:
            msg = 4;
            break;
        default:
            if (shown) {
                msg = 5;
            }
            break;
        case 0:
            msg = -1;
            break;
        }
        if (msg >= 0) {
            if (!shown) {
                if (lbl_801A66E8 != NULL) {
                    lbl_801A66E8();
                }
                shown = 1;
            }
            show_message(msg);
        }
    } while (!is_done(status, shown));
    if (shown && lbl_801A66E4 != NULL) {
        lbl_801A66E4();
    }
}
#pragma fp_contract reset

void (*fn_800068F4(void (*value)(void)))(void) {
    void (*old_value)(void) = lbl_801A66E8;
    lbl_801A66E8 = value;
    return old_value;
}

void (*fn_80006904(void (*arg0)(void)))(void) {
    void (*v0)(void) = lbl_801A66E4;
    lbl_801A66E4 = arg0;
    return v0;
}

void fn_80006914(void (*arg0)(void)) {
    lbl_801A66E0 = arg0;
}

void fn_8000691C(void) {
    RecC sp30[4];
    Rec8 sp8[4];
    RecC *p;
    u32 j;
    u32 i;
    u32 n;
    f64 d;

    PADRead(sp30);
    fn_8006B470(sp8);

    p = sp30;
    for (j = 0; j < 4; j++) {
        if (sp8[j].unk09 != -1) {
            p[j].unk00 = sp8[j].unk00;
            p[j].unk0A = 0;
        }
    }
    for (j = 0; j < 4; j++) {
        if (p[j].unk0A == -3) {
            p[j].unk00 = 0;
        }
    }

    if (lbl_801A66DA == 1 && fn_8000F5F0() == 0) {
        lbl_801A66D9 = 255;
    }
    if (fn_8000F5F0() != 0) {
        lbl_801A66DA = 1;
    }

    d = lbl_801A66D9;
    if (d > lbl_801A6EF8) {
        VIWaitForRetrace();
        VISetBlack(1);
        fn_8006FFCC(0);
        fn_8006FDEC();
        fn_8006FEFC();
        OSResetSystem(0, 0, 0);
    }

    n = 0;
    for (i = 4; i != 0; i--) {
        if ((p->unk00 & 0x1600) == 0x1600) {
            lbl_801A66D9++;
            break;
        }
        p++;
        n++;
    }
    if (n == 4) {
        lbl_801A66D9 = 0;
    }
}

void fn_80006AEC(s32 (*arg0)(void)) {
    lbl_801A66DC = arg0;
}

u8 fn_80006AF4(void) {
    return lbl_801A66D8;
}

void fn_80006AFC(void) {
    strcpy((u32)&lbl_8015BD40, (u32)&lbl_801A63F8);
    fn_80006B30(0);
}

void fn_80006B30(void (*func)(void)) {
    lbl_801A6708[0] = (u32)(func != 0 ? func : fn_80006B4C);
}
