#ifndef TITLEENTRY_H
#define TITLEENTRY_H

#include "types.h"

typedef struct {
    s32 image;
    u8 flags;
    u8 pad;
    u16 y;
} TitleEntry;
extern const TitleEntry lbl_8_rodata_48[8];

#endif
