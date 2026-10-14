/* Non-matching: best partial attempt (90.39% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/car.h"

extern int sprintf(char *, const char *, ...);
extern s32 fn_1_465D0(void *, s32);
extern void fn_1_12AB38(u32);
extern int fn_80083BCC(const char *, const char *);

struct fn_1_956EC_entry {
    u16 car;
    u16 index;
    u32 value;
    u32 unk_8;
};

struct fn_1_956EC_data {
    u32 pad_0[0xD7];
    u32 names[0x1656];
    u32 flags[0x398];
    struct fn_1_956EC_entry entries[0x42];
    u32 count;
    u8 pad_1[0xBC];
    char str_a[0x2F8];
    char str_71e4[8];
    char str_71ec[8];
    char str_71f4[0x10];
    char str_7204[0x10];
    char str_7214[0xC];
    char str_7220[0xC];
    char str_722c[0xC];
    char str_7238[0x40];
};

void fn_1_956EC(s32 car, u32 flags) {
    char buffer[64];
    struct fn_1_956EC_entry *e;
    struct fn_1_956EC_data *data = (struct fn_1_956EC_data *)&lbl_1_data_209C0;
    u32 name = data->names[car];
    u32 high;
    u32 value;
    u32 extra;
    struct { u32 value; } i;

    fn_1_12AB38((u32)&data->str_71e4);
    sprintf(buffer, data->str_71ec, name);
    fn_1_465D0(buffer, 1);
    if (flags & ((car == 0x15 || car == 0x29 || car == 0x21 || car == 0x2a || car == 0x2b) ? 0xe0000000u : 0xc0000000u)
        && (data->flags[car] & 0x40000000u)) {
        sprintf(buffer, data->str_71f4, name);
        fn_1_465D0(buffer, 1);
        sprintf(buffer, data->str_7204, name);
        fn_1_465D0(buffer, 1);
    }
    high = flags & 0xc0000000u;
    if (high && (data->flags[car] & 0x20000000u)) {
        sprintf(buffer, data->str_7214, name);
        fn_1_465D0(buffer, 1);
    }
    if (high && (data->flags[car] & 0x10000000u)) {
        sprintf(buffer, data->str_7220, name);
        fn_1_465D0(buffer, 1);
    }
    if (high && (data->flags[car] & 0x08000000u)) {
        sprintf(buffer, data->str_722c, name);
        fn_1_465D0(buffer, 1);
    }
    if ((flags & 0xe0000000u) && (data->flags[car] & 0x04000000u)) {
        for (extra = 0; extra < 20; extra++) {
            e = data->entries;
            value = 0;
            for (i.value = 0; i.value < data->count; i.value++) {
                if ((u32)car == e->car && extra == e->index) {
                    value = data->entries[i.value].value;
                    break;
                }
                e++;
            }
            sprintf(buffer, data->str_71ec, value);
            if (fn_80083BCC(buffer, data->str_7238))
                fn_1_465D0(buffer, 1);
        }
    }
    fn_1_12AB38((u32)&data->str_a);
}
