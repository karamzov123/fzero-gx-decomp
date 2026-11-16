#ifndef FONTENTRY_H
#define FONTENTRY_H

#include "types.h"

typedef struct {
    u32 unk_0;
    u8 unk_4;
    u8 unk_5;
    u32 unk_8;
    u32 unk_C;
    u8 unk_10;
    u8 unk_11;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    char *unk_24;
    u32 unk_28;
    void *unk_2C;
    void *unk_30;
    f32 unk_34;
} FontEntry;
extern FontEntry lbl_1_data_1AEA8[44];

#endif
