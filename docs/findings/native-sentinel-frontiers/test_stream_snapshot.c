/* Host-only semantic fixture. This does not prove PowerPC allocation or ABI.
 * Build with -I include -fsanitize=address,undefined -fno-omit-frame-pointer.
 * Override FRONTIER_SOURCE to exercise an intentional negative control. */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#define TYPES_H
#ifndef FRONTIER_SOURCE
#define FRONTIER_SOURCE "fn_8006B470.native.c"
#endif
typedef int8_t s8;
typedef uint8_t u8;
typedef uint16_t u16;
typedef int32_t s32;
typedef uint32_t u32;
#include FRONTIER_SOURCE

StreamEntry lbl_80199670[4];
static unsigned cleanup_mask;
static unsigned cleanup_count;
void fn_8006BC50(void *data) {
    unsigned i;
    for (i = 0; i < 4; ++i) {
        if (data == lbl_80199670[i].data) {
            assert(!(cleanup_mask & (1u << i)));
            cleanup_mask |= 1u << i;
            ++cleanup_count;
            return;
        }
    }
    assert(!"cleanup did not receive an entry's data subobject");
}

_Static_assert(sizeof(StreamEntry) == 0x1248, "retail entry stride");
_Static_assert(sizeof(StreamSnapshot) == 10, "retail output stride");
_Static_assert(offsetof(StreamEntry, flags) == 4, "flag offset");
_Static_assert(offsetof(StreamEntry, status) == 8, "status offset");
_Static_assert(offsetof(StreamEntry, snapshot) == 0x44, "snapshot offset");
_Static_assert(offsetof(StreamEntry, data) == 0x50, "data offset");

int main(void) {
    unsigned pattern, i, j;
    struct { u8 before[16]; StreamSnapshot records[4]; u8 after[16]; } guarded;
    cleanup_mask = cleanup_count = 0;
    assert(fn_8006B470(0) == -2);
    assert(cleanup_count == 0);
    for (pattern = 0; pattern < 256; ++pattern) {
        unsigned expected_mask = 0;
        unsigned expected_count = 0;
        memset(lbl_80199670, 0, sizeof(lbl_80199670));
        memset(&guarded, 0xA5, sizeof(guarded));
        cleanup_mask = cleanup_count = 0;
        for (i = 0; i < 4; ++i) {
            StreamEntry *entry = &lbl_80199670[i];
            entry->flags.enabled = (pattern >> (2 * i)) & 1;
            entry->flags.retiring = (pattern >> (2 * i + 1)) & 1;
            entry->status = 100 + i;
            for (j = 0; j < 10; ++j) entry->snapshot.bytes[j] = 10 * i + j;
            if (entry->flags.enabled && entry->flags.retiring) {
                expected_mask |= 1u << i;
                ++expected_count;
            }
        }
        assert(fn_8006B470(guarded.records) == 0);
        assert(cleanup_mask == expected_mask);
        assert(cleanup_count == expected_count);
        for (i = 0; i < 4; ++i) {
            unsigned enabled = (pattern >> (2 * i)) & 1;
            unsigned retiring = (pattern >> (2 * i + 1)) & 1;
            StreamEntry *entry = &lbl_80199670[i];
            assert(entry->flags.enabled == (enabled && !retiring));
            assert(entry->flags.retiring == (retiring && !enabled));
            assert(entry->status == ((enabled && retiring) ? -1 : (s32)(100 + i)));
            for (j = 0; j < 10; ++j) {
                u8 expected = enabled && !retiring ? 10 * i + j : (j == 9 ? 0xFF : 0xA5);
                assert(guarded.records[i].bytes[j] == expected);
            }
        }
        for (i = 0; i < 16; ++i) {
            assert(guarded.before[i] == 0xA5);
            assert(guarded.after[i] == 0xA5);
        }
    }
    puts("PASS: null destination + 256 flag combinations; entry/output strides, cleanup, status, snapshots and guards");
    return 0;
}
