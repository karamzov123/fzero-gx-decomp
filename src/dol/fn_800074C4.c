#include "types.h"
#pragma opt_propagation off

/* --- dol/fn_800074C4.c --- */
extern u32 fn_80007654(u32);
extern void fn_80007664(void *, u32, u32);
extern u32 fn_80007730(u32);
extern u32 lbl_801221A0[];
extern u32 lbl_801A6400;
extern void OSPanic(u8 *, s32, u8 *, ...);

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

void fn_800074C4(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5) {
    u32 v5;
    u32 v4;
    u32 v3;
    Entry *t0;
    u32 p0;
    u32 p1;
    u32 i;
    u32 n;

    v3 = arg3 & 0xFF;
    v4 = arg4 & 0xFF;
    v5 = arg5 & 0xFF;
    p0 = arg0;
    p1 = arg1;
    i = 0;
    n = (((0xFFF) + ((arg2) + (((s32)arg1 & 0xFFF))))) >> 12;
    while (i < n) {
        t0 = (Entry *)fn_80007730(p0);
        if (t0 == 0) {
            OSPanic((u8 *)&lbl_801A6400, 461, (u8 *)&lbl_801221A0);
        }
        t0->b = fn_80007654(p0);
        t0->d = (u32)((u8 *)p0) >> 22;
        t0->f = v3;
        t0->g = v4;
        t0->i = v5;
        fn_80007664(t0, p0, p1);
        p0 += 0x1000;
        p1 += 0x1000;
        i++;
    }
}

/* --- dol/fn_800075AC.c --- */
extern u32 fn_800077E0(u32);


extern void fn_80007700(Entry *, u32);

static inline u8 *page_span(void *base) {
    return (u8 *)((u32)base & 0xFFF) + 0xFFF;
}

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
