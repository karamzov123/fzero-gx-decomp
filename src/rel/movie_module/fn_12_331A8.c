#include "types.h"

typedef struct SFHHandle {
    int state;
    const unsigned char *header;
    int header_size;
    int version;
} SFHHandle;

typedef struct SFHObjectInfo {
    int capacity;
    int active_count;
    SFHHandle *objects;
} SFHObjectInfo;

extern const char lbl_12_rodata_10A8[49];

u32 lbl_12_bss_1B758;
SFHObjectInfo lbl_12_bss_1B75C;
u32 lbl_12_bss_1B75C__fzgx_offset_C;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s; // fzgx-allow: S2 BSS primer ordering
    s = *(u8 *)&lbl_12_bss_1B758;
    s = *(u8 *)&lbl_12_bss_1B75C;
    s = *(u8 *)&lbl_12_bss_1B75C__fzgx_offset_C;
}
#pragma section code_type ".text"

static inline void sfh_ClearHn(SFHHandle *objects, int capacity) {
    int i;
    for (i = 0; i < capacity; i++) {
        objects[i].state = 0;
        objects[i].header = 0;
        objects[i].header_size = 0;
        objects[i].version = 0;
    }
}

void fn_12_331A8(int capacity, SFHHandle *objects) {
    if ((s32)lbl_12_bss_1B758 > 0) {
        return;
    }
    lbl_12_bss_1B758++;
    lbl_12_bss_1B75C__fzgx_offset_C = (u32)lbl_12_rodata_10A8;
    sfh_ClearHn(objects, capacity);
    lbl_12_bss_1B75C.capacity = capacity;
    lbl_12_bss_1B75C.active_count = 0;
    lbl_12_bss_1B75C.objects = objects;
}
