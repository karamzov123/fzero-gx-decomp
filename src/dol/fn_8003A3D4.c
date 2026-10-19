#include "types.h"

s32 fn_8003A91C(void *arg0);

#pragma peephole on
#pragma opt_loop_invariants on
s32 fn_8003A3D4(u8 *arg0) {
    u8 count;
    u8 i;
    struct { u8 *value; } p;

    *(u8 **)(arg0 + 0x400) += 2;
    count = *(*(u8 **)(arg0 + 0x400))++;
    if (count != *(u8 *)(arg0 + 0x41C)) {
        return 6;
    }

    p.value = arg0;
    for (i = 0; i < count; i++, p.value += 0x30) {
        s32 hi;
        u16 val;
        s32 lo;
        u16 unk8;
        s16 shift;
        s32 diff;

        (*(u8 **)(arg0 + 0x400)) = (*(u8 **)(arg0 + 0x400)) + 1;
        val = (u8)(*(*(u8 **)(((0x400) + (arg0))))++);
        hi = val >> 4;
        *(u8 *)(p.value + 0x6C4) = hi;
        lo = val & 0xF;
        *(u8 *)(p.value + 0x6C5) = lo;
        if (!(*(u8 *)(((0x418) + (arg0))) & (1 << hi))) {
            return 9;
        }
        if (!(*(u8 *)(((0x418) + (arg0))) & (1 << (lo + 1)))) {
            return 9;
        }

        diff = *(u8 *)(arg0 + 0x41B) - *(u8 *)(((0x6C2) + (p.value)));
        unk8 = (u16)(*(u32 *)(p.value + 0x6C8));
        shift = 16 >> diff;
        *(u32 *)(p.value + 0x6D0) = *(u32 *)(arg0 + 0x7B4);
        *(u32 *)(arg0 + 0x7B4) += ((u16)unk8) * ((u16)shift);
    }

    *(u8 **)(arg0 + 0x400) += 3;
    return fn_8003A91C(arg0);
}
#pragma opt_loop_invariants reset

#pragma peephole reset
