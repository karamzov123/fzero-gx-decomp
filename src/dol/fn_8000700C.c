#include "types.h"

extern char lbl_801220C0[];
extern u32 lbl_801A66F8;
extern u32 lbl_801A66FC;
extern char **lbl_801A6700;
extern u32 lbl_801A6704;
extern u8 lbl_8015BD40[256];
extern char lbl_801A63F8[2];
extern s32 DVDConvertPathToEntrynum(const char *);
extern void OSPanic(const char *, int, const char *, ...);
extern char *fn_80083DB0(char *, const char *);
extern size_t strlen(const char *);
extern char *strcat(char *, const char *);
extern void fn_80006BDC(const char *, ...);
extern int fn_80083BCC(const char *, const char *);

s32 fn_8000700C(const char *path) {
    struct { char *value; } str;
    char buf[0x88];
    s32 result;
    s32 i;

    str.value = lbl_801220C0;
    if (lbl_801A66F8 == 0) {
        result = DVDConvertPathToEntrynum(path);
    } else {
        if (lbl_801A6704 == 0) {
            OSPanic(str.value + 0x58, 749, str.value + 0x80);
        }
        if (path[0] == '/') {
            for (i = 1; i < strlen(path) + 1; i++) {
                if (path[i] != '/') {
                    fn_80083DB0(buf, &path[i - 1]);
                    break;
                }
            }
        } else {
            fn_80083DB0(buf, (const char *)lbl_8015BD40);
            if (lbl_8015BD40[0] != '/' || lbl_8015BD40[1] != 0) {
                strcat(buf, lbl_801A63F8);
            }
            strcat(buf, path);
        }
        fn_80006BDC(str.value + 0xa0, path);
        fn_80006BDC(str.value + 0xb0, lbl_8015BD40);
        fn_80006BDC(str.value + 0xc0, buf);
        i = 0;
        result = -1;
        for (; i < (s32)lbl_801A66FC; i++) {
            if (fn_80083BCC(lbl_801A6700[i], buf) == 0) {
                result = i | 0x7FFF0000;
                break;
            }
        }
        fn_80006BDC(str.value + 0xd0, buf, result | 0x7FFF0000);
    }
    return result;
}
