#include "types.h"

extern u32 fn_800077E0(u32);

typedef struct Entry {
    u32 a : 1;
    u32 b : 24;
    u32 c : 1;
    u32 d : 6;
    u8 pad[3];
    u8 e : 1;
    u8 f : 1;
    u8 g : 1;
    u8 h : 3;
    u8 i : 2;
} Entry;

extern void fn_80007700(Entry *, u32);

static inline u8 *page_span(void *base) {
    return (u8 *)((u32)base & 0xFFF) + 0xFFF;
}

#pragma opt_propagation off
void fn_800075AC(u32 arg0, u32 arg1, u32 arg2) {
    u8 flags;
    u32 addr;
    u32 i;
    u32 n;
    Entry *entry;
    void *base;
    u8 *offset;

    base = (void *)(arg0 & ~0xFFF);
    offset = (u8 *)page_span(base);
    arg1 += (u32)offset;
    flags = arg2 ? 3 : 0;
    n = arg1 >> 12;
    addr = (u32)base;
    for (i = 0; i < n; i++) {
        entry = (Entry *)fn_800077E0(addr);
        if (entry != 0) {
            entry->i = flags;
            fn_80007700(entry, addr);
        }
        addr += 0x1000;
    }
}
