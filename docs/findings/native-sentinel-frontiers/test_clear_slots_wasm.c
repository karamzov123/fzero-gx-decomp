/* Compile this fixture to wasm32, where long and pointers are both 32 bits.
 * It exercises the exact archived C, not a 64-bit pointer-stride adaptation. */
#include "fn_8006BC50.native.c"

_Static_assert(sizeof(void *) == 4, "32-bit fixture required");
_Static_assert(sizeof(u32) == 4, "retail scalar width");
_Static_assert(sizeof(StreamSlots) == 0x1F4, "retail slot extent");

static struct {
    u8 before[12];
    StreamSlots slots;
    u8 after[12];
} guarded;

int run_suite(void) {
    u32 pattern, i;
    int passed = 0;
    for (pattern = 0; pattern < 66; ++pattern) {
        for (i = 0; i < 12; ++i) {
            guarded.before[i] = 0xA5;
            guarded.after[i] = 0x5A;
        }
        for (i = 0; i < 0xF4; ++i) guarded.slots.pad[i] = 0xC3;
        for (i = 0; i < 64; ++i) {
            guarded.slots.items[i] = (pattern == i || pattern == 64) ? (void *)(i + 1) : 0;
        }
        if (fn_8006BC50(&guarded.slots) != 0) return -1;
        for (i = 0; i < 64; ++i) if (guarded.slots.items[i] != 0) return -2;
        for (i = 0; i < 0xF4; ++i) if (guarded.slots.pad[i] != 0xC3) return -3;
        for (i = 0; i < 12; ++i) {
            if (guarded.before[i] != 0xA5 || guarded.after[i] != 0x5A) return -4;
        }
        ++passed;
    }
    return passed;
}
