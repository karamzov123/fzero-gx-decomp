#ifndef BITMAPFILEENTRY_H
#define BITMAPFILEENTRY_H

#include "types.h"

typedef struct {
    u32 unk_0;
    char *path[6];
    char *name;
    void *unk_20;
    u8 unk_24;
} BitmapFileEntry;
extern BitmapFileEntry lbl_1_data_FCD4[188];

#endif
