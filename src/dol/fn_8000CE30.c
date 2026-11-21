#include "types.h"
#include "sdk_addresses.h"


/* --- dol/fn_8000CE30.c --- */
extern s32 __OSReadROM(void *dst, s32 length, u32 offset);

void fn_8000CE30(void *dst, s32 length, u32 offset) {
    s32 chunk;

    while (length > 0) {
        if (length <= 0x100) {
            chunk = length;
        } else {
            chunk = 0x100;
        }
        length -= chunk;
        while (!__OSReadROM(dst, chunk, offset)) {
        }
        offset += chunk;
        dst = (u8 *)dst + chunk;
    }
}

/* --- dol/fn_8000CEBC.c --- */
typedef enum {
    OS_FONT_ENCODE_ANSI,
    OS_FONT_ENCODE_SJIS,
    OS_FONT_ENCODE_2,
    OS_FONT_ENCODE_UTF8,
    OS_FONT_ENCODE_UTF16,
    OS_FONT_ENCODE_UTF32,
    OS_FONT_ENCODE_MAX
} OSFontEncode;

typedef struct OSFontHeader {
    u16 fontType;
    u16 firstChar;
    u16 lastChar;
    u16 invalChar;
    u16 ascent;
    u16 descent;
    u16 width;
    u16 leading;
    u16 cellWidth;
    u16 cellHeight;
    u32 sheetSize;
    u16 sheetFormat;
    u16 sheetColumn;
    u16 sheetRow;
    u16 sheetWidth;
    u16 sheetHeight;
    u16 widthTable;
    u32 sheetImage;
    u32 sheetFullSize;
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} OSFontHeader;

u16 OSGetFontEncode(void);

void (*DVDLowClearCallback())(u32);

extern OSFontHeader *lbl_801A6798;

extern u8 *lbl_801A679C;

extern u8 *lbl_801A67A0;

extern int lbl_801A67A4;

extern u16 lbl_801A6438;

// OS state and hardware register block; link-defined absolute symbols.
extern volatile int __OSTVMode : FZGX_ADDR___OSTVMode;

extern volatile u16 __VIRegs[] : FZGX_ADDR___VIRegs;  /* fzgx-allow: S2 hardware register block */

int GetFontCode(u16 code);

void Decode(unsigned char *s, unsigned char *d);

static inline u32 GetFontSize(u8 *buf) {
    if (buf[0] == 'Y' && buf[1] == 'a' && buf[2] == 'y') {
        return *(u32 *)(buf + 0x4);
    }
    return 0;
}


static inline u32 ReadFont(void *img) {
    if (OSGetFontEncode() == OS_FONT_ENCODE_SJIS) {
        fn_8000CE30(img, 0x4D000, 0x1AFF00);
    } else {
        fn_8000CE30(img, 0x03000, 0x1FCF00);
    }
    return GetFontSize(img);
}

u32 fn_8000CEBC(OSFontHeader *fontData, void *temp) {
    u16 enc;
    u32 size;
    lbl_801A679C = ((void *)0);
    size = ReadFont(temp);
    if (size) {
        Decode(temp, (void *)fontData);
        lbl_801A6798 = fontData;
        lbl_801A67A0 = (u8 *)lbl_801A6798 + lbl_801A6798->widthTable;
        lbl_801A67A4 = lbl_801A6798->sheetColumn * lbl_801A6798->sheetRow;
        if ((enc = lbl_801A6438) <= 1) {
            enc = lbl_801A6438;
        } else {
            switch (__OSTVMode) {
            case 0:
                lbl_801A6438 = (__VIRegs[55] & 2) ? 1u : 0u;
                break;
            default:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                lbl_801A6438 = 0u;
                break;
            }
            enc = lbl_801A6438;
        }
        if (enc == OS_FONT_ENCODE_SJIS) {
            int fontCode;
            u8 *imageSrc;
            int sheet;
            int numChars;
            int row;
            int column;
            int x;
            int y;
            u8 *src;
            u16 imageT[4] = {0x2ABE, 0x003D, 0x003D, 0x003D};
            fontCode = GetFontCode(0x54);
            sheet = fontCode / lbl_801A67A4;
            numChars = fontCode - (sheet * lbl_801A67A4);
            row = numChars / lbl_801A6798->sheetColumn;
            column = numChars - (row * lbl_801A6798->sheetColumn);
            row *= lbl_801A6798->cellHeight;
            column *= lbl_801A6798->cellWidth;
            imageSrc = (u8 *)lbl_801A6798 + lbl_801A6798->sheetImage;
            imageSrc += ((sheet * lbl_801A6798->sheetSize) >> 1);
            for (y = 4; y < 8; y++) {
                x = 0;
                src = imageSrc
                    + ((((lbl_801A6798->sheetWidth / 8) << 5) / 2) * ((row + y) / 8));
                src += ((column + x) / 8) * 0x10;
                src += ((row + y) % 8) * 2;
                src += ((column + x) % 8) / 4;
                *(u16 *)src = imageT[y - 4];
            }
        }
    }
    return size;
}
