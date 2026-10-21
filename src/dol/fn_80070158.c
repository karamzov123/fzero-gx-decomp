#include "types.h"
#include "dol/globals.h"
extern u32 LCEnable(void);
extern u32 lbl_801A6CE0;
extern u32 lbl_801A6CF0;
extern u32 fn_80070CF8(u32);
extern u32 lbl_801A6CEC;
extern u8 lbl_8019E140[16];
extern u32 lbl_801A6D00[2];
extern u32 lbl_801A6D30[2];

void fn_80070158(s32 useLC) {
    struct { u32 value; } offset;
    struct { u32 value; } first;
    u32 base;
    u32 second;
    s32 i;
    if (useLC) {
        LCEnable();
        lbl_801A6CF0 = 0xE0000000;
        lbl_801A6CE0 |= 2;
    } else {
        lbl_801A6CF0 = fn_80070CF8(0x4000);
    }
    base = lbl_801A6CF0;
    first.value = base + 0x1C0;
    offset.value = 0;
    lbl_801A6CEC = offset.value;
    lbl_801A6D00[0] = base + lbl_801A6CEC;
    lbl_801A6CEC += 0x1C0;
    first.value = base + lbl_801A6CEC;
    lbl_801A6CEC += 0x1C;
    lbl_801A6CEC = (((lbl_801A6CEC - 1) >> 5) + 1) << 5;
    second = base + lbl_801A6CEC;
    lbl_801A6CEC += 0xCA0;
    lbl_801A6D30[0] = first.value;
    lbl_801A6D38 = second;
    lbl_801A6CEC = (lbl_801A6CEC + 0x3FF) & ~0x3FF;
    for (i = 0; i < 16; i++) {
        u8 value;
        if (i < 14) {
            if (offset.value <= lbl_801A6CEC) value = 0xFF;
            else value = 0;
        } else value = 1;
        lbl_8019E140[i] = value;
        offset.value += 0x400;
    }
}
