#include "types.h"


/* --- dol/GetFontCode.c --- */
typedef enum {
    OS_FONT_ENCODE_ANSI,
    OS_FONT_ENCODE_SJIS,
    OS_FONT_ENCODE_2,
    OS_FONT_ENCODE_UTF8,
    OS_FONT_ENCODE_UTF16,
    OS_FONT_ENCODE_UTF32,
    OS_FONT_ENCODE_MAX
} OSFontEncode;

u16 OSGetFontEncode(void);

void (*DVDLowClearCallback())(u32);

extern u16 lbl_80122F50[];

extern u16 lbl_801230D0[];

static inline BOOL IsSjisTrailByte(u8 c) { return (0x40 <= c && c <= 0xFC) && (c != 0x7F); }

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

/* --- dol/Decode.c --- */
void (*DVDLowClearCallback())(u32);

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
