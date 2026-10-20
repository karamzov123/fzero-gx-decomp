#include "types.h"

extern void *memset(void *dest, int value, u32 size);

typedef struct AdxtWork {
    u8 active;
    u8 index;
    u8 pad[2];
    u32 field4;
    u32 field8;
    u32 table2;
    u32 table1;
} AdxtWork;

typedef struct AdxtGlobal {
    u32 ref_count;
    u32 initialized;
    u32 table1;
    u32 table2;
    AdxtWork *slots[16];
} AdxtGlobal;

extern AdxtGlobal lbl_80187370;

#pragma opt_propagation off

AdxtWork *fn_80053A84(AdxtWork *arg0, u32 size) {
    AdxtGlobal *g = &lbl_80187370;
    s32 index;
    AdxtWork *work;

    {
        AdxtWork **p = g->slots;
        for (index = 0; index < 16; p++, index++) {
            if (*p == 0) {
                break;
            }
        }
    }

    if (index == 16) {
        return 0;
    }

    memset(arg0, 0, size);
    {
        u32 offset = (u32)index * sizeof(AdxtWork *);
        AdxtWork **slots = g->slots;
        *(AdxtWork **)((u8 *)slots + offset) = arg0;
        work = *(AdxtWork **)((u8 *)slots + offset);
    }
    work->index = index;
    work->field4 = work->field8 = 0x40;
    work->table1 = g->table1;
    work->table2 = g->table2;
    work->active = 1;
    return work;
}
#pragma opt_propagation reset

