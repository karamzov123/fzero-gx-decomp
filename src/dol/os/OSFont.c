#include <dolphin/os.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

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

volatile int __OSTVMode : FZGX_ADDR___OSTVMode; /* fzgx-allow: S2 SDK asynchronous state */
vu16 __VIRegs[59] : FZGX_ADDR___VIRegs;

extern u16 lbl_801A6438;
extern OSFontHeader *lbl_801A6798;
extern u8 *lbl_801A679C;
extern u8 *lbl_801A67A0;
extern int lbl_801A67A4;
extern u16 lbl_80122F50[];
extern u16 lbl_801230D0[];
extern s32 __OSReadROM(void *dst, s32 length, u32 offset);
extern void *OSAllocFromArenaLo(u32 size, u32 align);
extern void DCStoreRange(void *addr, u32 nBytes);

u16 OSGetFontEncode(void);

static inline BOOL IsSjisTrailByte(u8 c) {
    return (0x40 <= c && c <= 0xFC) && (c != 0x7F);
}



int GetFontCode(u16 code) {
    u16 encode = OSGetFontEncode();
    if (encode == OS_FONT_ENCODE_SJIS) {
        if (code >= 0x20 && code <= 0xDF) {
            return lbl_80122F50[code - 0x20];
        }
        if (code > 0x889E && code <= 0x9872) {
            int i = ((code >> 8) - 0x88) * 188;
            int j = (code & 0xFF);
            if (!IsSjisTrailByte(j)) {
                return 0;
            }
            j -= 0x40;
            if (j >= 0x40) {
                j--;
            }
            return (i + j + 0x2BE);
        }
        if (code >= 0x8140 && code < 0x879E) {
            int i = ((code >> 8) - 0x81) * 188;
            int j = (code & 0xFF);
            if (!IsSjisTrailByte(j)) {
                return 0;
            }
            j -= 0x40;
            if (j >= 0x40) {
                j--;
            }
            return lbl_801230D0[i + j];
        }
    } else if (code > 0x20 && code <= 0xFF) {
        return code - 0x20;
    }
    return 0;
}

void Decode(unsigned char *s, unsigned char *d) {
    int i;
    int j;
    int k;
    int p;
    int q;
    int r7;
    int r25;
    int cnt;
    int os;
    unsigned int flag;
    unsigned int code;
    os = *(int *)(s + 0x4);
    r7 = *(int *)(s + 0x8);
    r25 = *(int *)(s + 0xC);
    q = 0;
    flag = 0;
    p = 16;
    do {
        if (flag == 0) {
            code = *(u32 *)(s + p);
            p += sizeof(u32);
            flag = sizeof(u32) * 8;
        }
        if (code & 0x80000000) {
            d[q++] = s[r25++];
        } else {
            j = s[r7] << 8 | s[r7 + 1];
            r7 += sizeof(u16);
            k = q - (j & 0x0FFF);
            cnt = j >> 12;
            if (cnt == 0) {
                cnt = s[r25++] + 0x12;
            } else {
                cnt += 2;
            }
            for (i = 0; i < cnt; i++, q++, k++) {
                d[q] = d[k - 1];
            }
        }
        code <<= 1;
        flag--;
    } while (q < os);
}

u16 OSGetFontEncode(void) {
    if (lbl_801A6438 <= 1) {
        return lbl_801A6438;
    }
    switch (__OSTVMode) {
    case 0:
        lbl_801A6438 = (__VIRegs[55] & 2) ? 1u : 0u;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    default:
        lbl_801A6438 = 0u;
    }
    return lbl_801A6438;
}

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

static inline BOOL IsSjisLeadByte(u8 c) {
    return (0x81 <= c && c <= 0x9F) || (0xE0 <= c && c <= 0xFC);
}

static inline u16 OSGetFontEncode_inline(void) {
    if (lbl_801A6438 <= 1) {
        return lbl_801A6438;
    }
    switch (__OSTVMode) {
    case 0:
        lbl_801A6438 = (__VIRegs[55] & 2) ? 1u : 0u;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    default:
        lbl_801A6438 = 0u;
    }
    return lbl_801A6438;
}

char *fn_8000D1F0(char *string, void *image, s32 pos, s32 stride, s32 *width) {
    u16 code;
    u8 *src;
    u8 *dst;
    int fontCode;
    int sheet;
    int numChars;
    int row;
    int column;
    int x;
    int y;
    int offsetSrc;
    int offsetDst;
    u8 *colorIndex;
    u8 *imageSrc;

    code = *(u8 *)string;
    if (code == '\0') {
        return string;
    }

    string++;
    if (OSGetFontEncode_inline() == 1) {
        if (IsSjisLeadByte(code) && *string != 0) {
            code = (code << 8) | *(u8 *)string++;
        }
    }
    colorIndex = &lbl_801A6798->c0;

    fontCode = GetFontCode(code);

    sheet = fontCode / lbl_801A67A4;
    numChars = fontCode - (sheet * lbl_801A67A4);
    row = numChars / lbl_801A6798->sheetColumn;
    column = (numChars - (row * lbl_801A6798->sheetColumn));
    row *= lbl_801A6798->cellHeight;
    column *= lbl_801A6798->cellWidth;
    imageSrc = (u8 *)lbl_801A6798 + lbl_801A6798->sheetImage;
    imageSrc += (sheet * lbl_801A6798->sheetSize) / 2;

    for (y = 0; y < lbl_801A6798->cellHeight; y++) {
        for (x = 0; x < lbl_801A6798->cellWidth; x++) {
            src = imageSrc + (((lbl_801A6798->sheetWidth / 8) * 32) / 2) * ((row + y) / 8);
            src += ((column + x) / 8) * 16;
            src += ((row + y) % 8) * 2;
            src += ((column + x) % 8) / 4;

            offsetSrc = (column + x) % 4;

            dst = (u8 *)image + ((y / 8) * (((stride * 4) / 8) * 32));
            dst += (((pos + x) / 8) * 32);
            dst += ((y % 8) * 4);
            dst += ((pos + x) % 8) / 2;

            offsetDst = (pos + x) % 2;

            *dst |= colorIndex[*src >> (6 - (offsetSrc * 2)) & 3] & ((offsetDst != 0) ? 0x0F : 0xF0);
        }
    }
    if (width != NULL) {
        *width = lbl_801A67A0[fontCode];
    }

    return string;
}
