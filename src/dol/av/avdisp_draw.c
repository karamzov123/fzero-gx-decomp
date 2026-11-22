#include "types.h"

typedef struct {
    u8 pad_00[0x1a];
    u16 count_a;
    u16 count_b;
} AvDispObj;

typedef struct {
    u8 pad_00[0xc];
    u32 offset;
    u8 pad_10[0xa];
    u16 count_a;
    u16 count_b;
    u8 pad_20[0x4];
} AvDispData;

extern void GXInvalidateVtxCache(void);
extern u8 *fn_80078360(u8 *, u8 *, AvDispData *, u8 *, AvDispObj *);

void *fn_800786B0(AvDispObj *arg0, AvDispData *arg1, u8 *arg2) {
    u8 *entry;
    u8 *result;
    s32 i;

    result = (u8 *)arg1 + arg1->offset;
    entry = (u8 *)arg1 + 0x20;
    GXInvalidateVtxCache();
    i = 0;
    while (i < arg0->count_a) {
        result = fn_80078360(entry, arg2, arg1, result, arg0);
        entry += 0x60;
        i++;
    }
    i = 0;
    while (i < arg0->count_b) {
        result = fn_80078360(entry, arg2, arg1, result, arg0);
        entry += 0x60;
        i++;
    }
}

void fn_80078768(AvDispObj *arg0, AvDispData *arg1, u8 *arg2, s32 arg3) {
    u8 *entry;
    u8 *result;
    s32 i;

    result = (u8 *)arg1 + arg1->offset;
    entry = (u8 *)arg1 + 0x20;
    GXInvalidateVtxCache();
    if (arg3 != 0) {
        for (i = 0; i < arg0->count_a; i++) {
            result = fn_80078360(entry, arg2, arg1, result, arg0);
            entry += 0x60;
        }
        return;
    }
    for (i = 0; i < arg0->count_a; i++)
        entry += 0x60;
    for (i = 0; i < arg0->count_b; i++) {
        result = fn_80078360(entry, arg2, arg1, result, arg0);
        entry += 0x60;
    }
}
