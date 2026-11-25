#include "types.h"

extern int fn_12_23F34(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_12_20B90(void);
extern int memcmp(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_12_rodata_A50[20];

typedef struct Movie {
    u8 pad_0000[0x38];
    void *field_0038;
    void (*field_003c)(void);
    int field_0040;
} Movie;

typedef struct MovieData {
    u8 pad_0000[0xcfc];
    void *field_0cfc;
} MovieData;

typedef struct MovieModule {
    u8 pad_0000[0x1b74];
    Movie *field_1b74;
    u8 pad_1b78[0xd90];
    MovieData *field_2908;
} MovieModule;

void fn_12_20A7C(MovieModule *arg0, u8 *arg1, s32 arg2, s32 *arg3) {
    Movie *movie;
    s32 i;
    u8 *buf;
    s32 count;
    Movie *m;
    MovieData *data;
    void *entry;
    s32 result;

    *arg3 = 0;
    movie = arg0->field_1b74;
    if (fn_12_23F34((u32)arg0, (u32)arg1, (u32)arg2, (u32)arg3) >= 0x6c) {
        movie->field_003c = fn_12_20B90;
        return;
    } else {
        buf = arg1;
        i = 0;
        while (i < arg2 - 0x12) {
            if (memcmp((u32)buf, (u32)lbl_12_rodata_A50, 0x12) != 0) {
                movie->field_003c = fn_12_20B90;
                break;
            }
            buf += 0x12;
            i += 0x12;
        }
        *arg3 = i;
    }

    data = arg0->field_2908;
    m = arg0->field_1b74;
    if (data == 0) {
        entry = 0;
    } else if (m->field_0040 > 0) {
        entry = 0;
    } else {
        entry = (u8 *)data + 0xcfc;
    }
    if (entry == 0) {
        result = -1;
    } else {
        count = *(s32 *)((u8 *)entry + 0xc);
        result = 0;
    }
    if (result == 0) {
        movie->field_0038 = (u8 *)movie->field_0038
            + (i / (count * 0x12)) * 0x20;
    }
}
