/* Non-matching: best partial attempt (97.97% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/car.h"

typedef struct {
    u8 pad_0[4];
    s32 field_4[5];
} Fn1_8F198Object;

extern u32 lbl_1_rodata_3E48[10];
extern u32 lbl_1_rodata_3E70[63];
extern char *fn_80083DB0(char *, const char *);
extern char *strcat(char *, const char *);
extern int sprintf(char *, const char *, ...);
extern s32 fn_1_12A32C(const char *);
extern void fn_1_12A2B8(s32);
extern void fn_1_12A2D0(s32);
extern void fn_1_12AB38(const char *);
extern void *fn_1_12A290(s32);
extern s32 fn_1_12A6D8(const char *);
extern u32 fn_1_12AAC8(const char *);
extern u32 fn_80009FB4(void *);
extern void fn_80008BA8(void *, void *, u32);
extern void DCFlushRange(void *, u32);
extern void fn_80009CAC(void *, u32);
extern void fn_1_8E7D0(u32, u32, u32, u32);

#define BIT(x,n) __rlwnm((x), ((n) & 31), 31, 31)

void fn_1_8F198(Fn1_8F198Object *obj, s32 idx, u32 flags, u32 mode) {
    char path[0x40];
    u8 *data = (u8 *)&lbl_1_data_209C0;
    s32 i;
    s32 j;
    void *cur;
    void *start;
    u32 size;
    const char *name = (const char *)((const char **)(data + 0x35C))[idx];
    u32 total;
    u32 remaining;

    if (flags == 0) flags = 0x80000000;
    if (mode == 0) mode = 0x80000000;
    obj->field_4[0] = -1;
    obj->field_4[1] = -1;
    obj->field_4[2] = -1;
    obj->field_4[3] = -1;
    obj->field_4[4] = -1;
    for (i = 0; i < 5; i++) {
        if (BIT(flags, i + 1) == 0) continue;
        if (idx == 44) continue;
        if (i == 4) continue;
        fn_80083DB0(path, (const char *)(data + 0x6EBC));
        strcat(path, name);
        strcat(path, (const char *)(data + 0x6EC8));
        switch (i) {
        case 1: strcat(path, (const char *)(data + 0x63AC)); break;
        case 2: strcat(path, (const char *)(data + 0x6394)); break;
        case 3: strcat(path, (const char *)(data + 0x639C)); break;
        case 4: strcat(path, (const char *)(data + 0x63A4)); break;
        }
        strcat(path, (const char *)(data + 0x6ED0));
        obj->field_4[i] = fn_1_12A32C(path);
        if (obj->field_4[i] == -1) continue;
        if (mode == 0x80000000 || mode == 0x40000000 || mode == 0x20000000 || mode == 0x10000000) {
            fn_1_12A2B8(1);
            fn_1_12A2D0(obj->field_4[i]);
            fn_1_12AB38((const char *)(data + 0x6ED8));
            remaining = fn_80009FB4(fn_1_12A290(obj->field_4[i]));
            total = remaining;
            sprintf(path, (const char *)(data + 0x6EE0), name, lbl_1_rodata_3E48[i], lbl_1_rodata_3E70[0]);
            start = (void *)fn_1_12A6D8(path);
            for (j = 0; j < 4; j++) {
                sprintf(path, (const char *)(data + 0x6EE0), name, lbl_1_rodata_3E48[i], lbl_1_rodata_3E70[j]);
                cur = (void *)fn_1_12A6D8(path);
                size = fn_1_12AAC8(path);
                if (BIT(mode, j + 1) == 0) {
                    remaining -= size;
                } else {
                    if (start != cur) {
                        fn_80008BA8(start, cur, size);
                        DCFlushRange(start, size);
                    }
                    start = (void *)((u8 *)start + size);
                }
            }
            if (total != remaining) fn_80009CAC(fn_1_12A290(obj->field_4[i]), remaining);
            fn_1_12AB38((const char *)(data + 0x6EEC));
            fn_1_12A2B8(0);
        }
    }
    fn_1_8E7D0((u32)obj, (u32)idx, flags, mode);
}
