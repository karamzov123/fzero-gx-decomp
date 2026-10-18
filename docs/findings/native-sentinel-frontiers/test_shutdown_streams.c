/* Host semantic fixture for the four-entry shutdown pass. */
#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#define TYPES_H
typedef uint8_t u8;
typedef uint32_t u32;
typedef int32_t s32;
#include "fn_8006B224.native.c"

s32 lbl_801A6C88;
u8 lbl_80199670[18720];
static unsigned step;
static unsigned cycles;
static s32 expected_flag;

s32 fn_8006B3F0(struct Fn8006B3F0Data *entry) {
    unsigned index = step / 2;
    assert(step % 2 == 0);
    assert(index < 4);
    assert((u8 *)entry == lbl_80199670 + index * 0x1248);
    assert(lbl_801A6C88 == expected_flag);
    ++step;
    return -1; /* The pass intentionally ignores each release result. */
}

void fn_800139E8(u32 index, u32 command, s32 argument) {
    assert(step % 2 == 1);
    assert(index == step / 2);
    assert(command == 0x400 && argument == 0);
    assert(lbl_801A6C88 == expected_flag);
    ++step;
    ++cycles;
}

int main(void) {
    static const s32 flags[] = { 0, 1, -1, 2 };
    unsigned i;
    for (i = 0; i < sizeof(flags) / sizeof(flags[0]); ++i) {
        expected_flag = flags[i];
        lbl_801A6C88 = flags[i];
        step = cycles = 0;
        fn_8006B224();
        assert(lbl_801A6C88 == 0);
        assert(step == (flags[i] ? 8u : 0u));
        assert(cycles == (flags[i] ? 4u : 0u));
        fn_8006B224();
        assert(step == (flags[i] ? 8u : 0u));
        assert(cycles == (flags[i] ? 4u : 0u));
    }
    puts("PASS: four shutdown flag states, ordered entry release/channel callbacks, exact strides, and repeat-call idempotence");
    return 0;
}
