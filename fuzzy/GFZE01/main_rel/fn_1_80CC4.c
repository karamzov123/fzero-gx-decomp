/* Non-matching: best partial attempt (94.80% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/car.h"

extern s32 fn_1_8171C(s32);
extern u32 fn_1_12A32C(void *);
extern void fn_1_12AB38(void *);
extern u32 fn_1_12AC00(void *);
extern void fn_1_12A2B8(u32);
extern void fn_1_80294(void *, u32, u32);
extern void fn_80008BEC(void *, int, u32);
extern void fn_80008BA8(void *, const void *, u32);
extern char *fn_80083DB0(char *, const char *);
extern int sprintf(char *, const char *, ...);

typedef struct {
    u16 unk_0;
    s16 unk_2;
    s32 unk_4;
    u8 unk_8;
    u8 pad_9[23];
} CarRequest;

typedef struct {
    u8 pad_0[0x324];
    const char *names[7];
} CarData;

typedef struct {
    const char *names[7];
} CarNames;

s32 fn_1_80CC4(s32 car, s32 mode, s32 variant, u32 out)
{
    char path[32];
    char name[32];
    CarRequest request;
    CarRequest special;
    CarRequest normal;
    CarData *data = (CarData *)&lbl_1_data_1F1D8;
    const char **tbl;
    s16 result;

    if (!out) {
        return -1;
    }
    if (mode) {
        fn_80008BEC(&special, 0, 32);
        special.unk_4 = fn_1_8171C(1);
        special.unk_8 = 16;
        fn_80008BA8(&request, &special, 32);
        request.unk_2 = car;
        fn_80083DB0(name, *(const char **)((u8 *)data + 0x324 + 4 * (s32)car));
        if (variant == 1) {
            switch ((s16)car) {
            case 6:
                fn_80083DB0(name, (char *)data + 0x13e4);
                break;
            case 0:
                fn_80083DB0(name, (char *)data + 0x13ec);
                break;
            case 1:
                fn_80083DB0(name, (char *)data + 0x13f4);
                break;
            }
        }
        sprintf(path, (char *)data + 0x141c, name);
    } else {
        fn_80008BEC(&normal, 0, 32);
        normal.unk_4 = fn_1_8171C(0);
        normal.unk_8 = 1;
        fn_80008BA8(&request, &normal, 32);
        request.unk_2 = car;
        fn_80083DB0(name, ((CarNames *)((u8 *)data + 0x324))->names[(s16)car]);
        if (variant == 1) {
            switch ((s16)car) {
            case 6:
                fn_80083DB0(name, (char *)data + 0x13e4);
                break;
            case 0:
                fn_80083DB0(name, (char *)data + 0x13ec);
                break;
            case 1:
                fn_80083DB0(name, (char *)data + 0x13f4);
                break;
            }
        }
        sprintf(path, (char *)data + 0x1430, name);
    }
    result = fn_1_12A32C(path);
    if (lbl_1_bss_6D82C.unk_0 == 0) {
        fn_1_12AB38((u8 *)data + 0xe0c);
        lbl_1_bss_6D82C.unk_0 = fn_1_12AC00((u8 *)data + 0x140c);
        fn_1_12AB38((u8 *)data + 0xe20);
    }
    fn_1_12A2B8(1);
    fn_1_12AB38((u8 *)data + 0xe0c);
    fn_1_80294(&request, out, 0);
    fn_1_12AB38((u8 *)data + 0xe20);
    fn_1_12A2B8(0);
    return result;
}
