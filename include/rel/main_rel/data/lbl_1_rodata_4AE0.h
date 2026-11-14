#ifndef MEMCARDKIND_H
#define MEMCARDKIND_H

#include "types.h"

typedef struct {
    char name[32];
    char file[28];
    u32 unk_3C;
    u32 unk_40;
    s32 unk_44;
    s32 unk_48;
} MemcardKind;
extern const MemcardKind lbl_1_rodata_4AE0[6];

#endif
