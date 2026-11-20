#include "types.h"

extern u32 lbl_80187330[16];
extern void *memset(void *, int, unsigned int);
extern void *fn_80053A84(void *, unsigned int);

typedef struct Fn800517C0Object {
    u32 field_0;
    u8 pad_4[0x340];
    u8 field_344;
    u8 field_345;
    u8 field_346;
    u8 pad_347[9];
    u32 field_350;
} Fn800517C0Object;

Fn800517C0Object *fn_800517C0(Fn800517C0Object *obj, unsigned int size) {
    Fn800517C0Object *entry;
    int i;
    void *resource;

    for (i = 0; i < 16; i++) {
        if (lbl_80187330[i] == 0) {
            break;
        }
    }
    if (i == 16) {
        return 0;
    }

    memset(obj, 0, size);
    lbl_80187330[i] = (u32)obj;
    entry = (Fn800517C0Object *)lbl_80187330[i];
    entry->field_346 = i;
    resource = fn_80053A84((u8 *)entry + 0xbb8, 0x2014);
    entry->field_350 = (u32)resource;
    if (resource == 0) {
        return 0;
    }

    entry->field_0 = ((u32)entry + 0x23) & ~31;
    if (entry->field_0 & 0x1f) {
        for (;;) {
        }
    }
    entry->field_344 = 1;
    return entry;
}
