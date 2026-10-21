#include "types.h"
typedef struct Sig_fn_8000CEBC_OSFontHeader {
    u16 fontType; u16 firstChar; u16 lastChar; u16 invalChar;
    u16 ascent; u16 descent; u16 width; u16 leading;
    u16 cellWidth; u16 cellHeight; u32 sheetSize;
    u16 sheetFormat; u16 sheetColumn; u16 sheetRow; u16 sheetWidth;
    u16 sheetHeight; u16 widthTable; u32 sheetImage; u32 sheetFullSize;
    u8 c0; u8 c1; u8 c2; u8 c3;
} Sig_fn_8000CEBC_OSFontHeader;
typedef struct StringGroup { u8 **stringList; s32 numStrings; } StringGroup;
typedef struct Glyph { void *image; u16 code; u16 width; } Glyph;
extern u32 OSGetArenaHi(void);
extern u32 OSGetFontEncode(void);
extern void *fn_8000B360(u32, u32);
extern u32 fn_8000CEBC(Sig_fn_8000CEBC_OSFontHeader *, void *);
extern StringGroup lbl_8012205C[];
extern u32 lbl_801A66F0;
extern StringGroup *lbl_801A66F4;
extern s16 lbl_801A66EC;
extern Glyph lbl_8015B940[128];
extern void *fn_8000B334(u32, u32);
extern void fn_8000D1F0(u8 *, void *, u32, u32, u32 *);
extern void DCStoreRange(void *, u32);
extern void OSSetArenaHi(u32);
extern void fn_8000691C(void);
extern void fn_80006914(u32);
extern void fn_80006AEC(u32);
#pragma opt_propagation off
void fn_800063AC(u32 arg0, u32 arg1, u32 arg2) {
    struct {
    u32 arena;
    s32 stringIndex;
    u8 **strings;
    s32 groupIndex;
    StringGroup *group;
    void *font;
    u8 *start;
    Glyph *glyph;
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
        font = fn_8000B360(0x90EE4, 32);
        temp = fn_8000B360(0x4D000, 32);
    } else {
        font = fn_8000B360(0x10120, 32);
        temp = fn_8000B360(0x3000, 32);
    }
    fn_8000CEBC((Sig_fn_8000CEBC_OSFontHeader *)font, (void *)temp);
    group = (StringGroup *)lbl_801A66F4;
    for (groupIndex = 0; groupIndex < (s32)lbl_801A66F0; groupIndex++, group++) {
        strings = group->stringList;
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
                { Glyph *base = (Glyph *)lbl_8015B940; glyph = base; }
                for (i = 0; i < count; i++, glyph++) {
                    if (glyph->code == code) break;
                }
                if (i < count) continue;
                glyph->code = code;
                glyph->image = fn_8000B334(0x120, 32);
                fn_8000D1F0(start, glyph->image, 0, 6, &width);
                DCStoreRange(glyph->image, 0x120);
                glyph->width = width;
                count++;
            }
            lbl_801A66EC = count;
        }
    }
    OSSetArenaHi(arena);
    fn_80006914((u32)fn_8000691C);
    fn_80006AEC(0);
}
