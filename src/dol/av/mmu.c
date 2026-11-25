#include "types.h"

typedef struct PTE {
    u32 valid : 1;
    u32 vsid : 24;
    u32 h : 1;
    u32 api : 6;
    u32 rpn : 20;
    u32 res1 : 3;
    u32 r : 1;
    u32 c : 1;
    u32 w : 1;
    u32 i : 1;
    u32 m : 1;
    u32 g : 1;
    u32 res2 : 1;
    u32 pp : 2;
} PTE;

void fn_80007664(PTE *pte, u32 ea, u32 pa);

extern u32 OSGetArenaHi(void);
extern void OSSetArenaHi(u32);
extern void *memset(void *, int, u32);
extern u32 fn_80007730(u32);
extern u32 fn_800077E0(u32);
extern void OSPanic(u8 *, s32, u8 *, ...);

extern u32 lbl_801A6710;
extern u32 lbl_801A6714;
extern u32 lbl_801A6718;
extern u32 lbl_801A671C;
extern u32 lbl_801A6720;
extern u16 lbl_801A6724;
extern u16 lbl_801A6726;
extern u32 lbl_801A6CE0;
extern u32 lbl_801A6CF8;
extern u32 lbl_801221A0[];
extern u32 lbl_801A6400;

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

void fn_80007700(Entry *pte, u32 ea);
u32 fn_80007654(u32 ea);

void fn_8000740C(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4);

static inline u8 *page_span(void *base) {
    return (u8 *)((u32)base & 0xFFF) + 0xFFF;
}

/* Original VM initialization routine: C arena/page-table setup wrapping SDR1/SR/DBAT asm. */
void fn_800071B8(void) {
    u32 arena;
    u32 i;

    lbl_801A6714 = 1;
    arena = OSGetArenaHi();
    arena -= 0x40000;
    arena &= ~0x3FFFF;
    OSSetArenaHi(arena);
    lbl_801A671C = 0x1000;
    if (lbl_801A6CE0 & 8) {
        arena = lbl_801A6CF8;
        lbl_801A671C *= 4;
        lbl_801A6718 = lbl_801A671C * 0x40;
        arena -= lbl_801A6718;
        arena &= ~(lbl_801A6718 - 1);
        lbl_801A6CF8 = arena;
    } else {
        lbl_801A6718 = lbl_801A671C * 0x40;
    }
    lbl_801A6710 = (arena & 0x0FFFFFFF) | 0xC0000000;  /* fzgx-allow: A1 OS_BASE_UNCACHED virtual address base */
    memset((void *)lbl_801A6710, 0, lbl_801A6718);

    {
        register u32 sdr1;
        register u32 msr;
        register u32 mask = ~0x18;
        sdr1 = (arena & 0x0FFF0000) | ((lbl_801A6718 - 1) >> 16);
        asm {
            mfmsr msr
            and msr, msr, mask
            nor mask, mask, mask
            mtmsr msr
            isync
            sync
            mtsdr1 sdr1
            or msr, msr, mask
            mtmsr msr
            isync
            sync
        }
    }

    for (i = 0; i < 16; i++) {
        register u32 sr = (lbl_801A671C >> 4) * ((i + 8) & 0xF);
        register u32 sr_ea = i << 28;
        asm {
            mtsrin sr, sr_ea
        }
    }

    asm {
        isync
        sync
        tlbsync
        sync
    }

    if (lbl_801A6CE0 & 8) {
        for (i = 0; i < 0x3000; i++) {
            fn_8000740C(0x80000000 + i * 0x1000, i * 0x1000, 0, 0, 0);
        }
        {
            register u32 zero = 0;
            register u32 dbatu;
            register u32 bl = 0x3F;
            asm {
                isync
                sync
                nop
                mfdbatu dbatu, 0
                rlwimi dbatu, bl, 0, 16, 31
                mtdbatu 0, dbatu
                mtdbatu 2, zero
                mtdbatl 2, zero
                nop
                isync
                sync
            }
        }
    }

    lbl_801A6726 = 0;
    lbl_801A6724 = 0xFFFF;
    lbl_801A6720 = 0;
}

void fn_8000740C(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    u32 v0;
    u32 v1;
    u32 v2;
    Entry *t0;
    u32 t2;

    t0 = (Entry *)fn_80007730(arg0);
    v1 = (u32)t0;
    if (t0 == 0) {
        v1 = (u32)&lbl_801A6400;
        v2 = (u32)&lbl_801221A0;
        v0 = 461;
        OSPanic((u8 *)v1, v0, (u8 *)v2);
    }
    t2 = fn_80007654(arg0);
    t0->b = t2;
    t0->d = arg0 >> 22;
    t0->f = arg2;
    t0->g = arg3;
    t0->i = arg4;
    fn_80007664((PTE *)t0, arg0, arg1);
}

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
    n = (((0xFFF) + ((arg2) + ((arg1 & 0xFFF))))) >> 12;
    while (i < n) {
        t0 = (Entry *)fn_80007730(p0);
        if (t0 == 0) {
            OSPanic((u8 *)&lbl_801A6400, 461, (u8 *)&lbl_801221A0);
        }
        t0->b = fn_80007654(p0);
        t0->d = (u32)(p0) >> 22;
        t0->f = v3;
        t0->g = v4;
        t0->i = v5;
        fn_80007664((PTE *)t0, p0, p1);
        p0 += 0x1000;
        p1 += 0x1000;
        i++;
    }
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
    offset = page_span(base);
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

/* The segment-register read, TLB/cache invalidation and SDR1 hash-table lookup are
 * CodeWarrior asm functions in the original (mfsrin, tlbie/tlbsync, mfsdr1; no compiler frame). */
asm u32 fn_80007654(register u32 ea) {
    nofralloc
    clrrwi r3, r3, 28
    mfsrin r3, r3
    clrlwi r3, r3, 8
    blr
}

/* Original VM PTE update routine: C bitfield updates wrapping TLB/cache invalidation asm. */
void fn_80007664(register PTE *pte, register u32 ea, u32 pa) {
    pte->res1 = 0;
    pte->res2 = 0;
    pte->rpn = (pa >> 12) & 0xFFFF;
    pte->r = 0;
    pte->c = 0;
    pte->m = 0;
    pte->g = 0;
    asm {
        sync
        tlbie ea
        sync
        tlbsync
        sync
    }
    pte->valid = 1;
    asm {
        dcbf 0, pte
        sync
        tlbie ea
        sync
        tlbsync
        sync
    }
}

asm void fn_80007700(register Entry *pte, register u32 ea) {
    nofralloc
    sync
    tlbie r4
    sync
    tlbsync
    sync
    dcbf r0, r3
    sync
    tlbie r4
    sync
    tlbsync
    sync
    blr
}

extern u32 fn_800079C4(u32);
extern u32 fn_80007A00(u32);
extern u8 *fn_800079A0(u32);

u32 fn_80007730(u32 arg0) {
    u32 values[2];
    u32 i;
    u8 *p;
    u32 j;
    u8 *entry;

    values[0] = fn_800079C4(arg0);
    values[1] = fn_80007A00(arg0);
    for (i = 0; i < 2; i++) {
        entry = fn_800079A0(values[i]);
        p = entry;
        for (j = 0; j < 8; j++) {
            if (((p[0] >> 7) & 1) == 0) {
                entry[j * 8 + 3] = (entry[j * 8 + 3] & ~0x40) | ((i << 6) & 0x40);
                return (u32)(entry + j * 8);
            }
            p += 8;
        }
    }
    return 0;
}


u32 fn_800077E0(u32 key) {
    u32 tab[2];
    u32 h;
    u32 hi;
    u32 i;
    u8 *base;
    u8 *p;
    u32 j;

    h = fn_80007654(key);
    hi = (key >> 22) & 0x3F;
    tab[0] = fn_800079C4(key);
    tab[1] = fn_80007A00(key);
    for (i = 0; i < 2; i++) {
        base = fn_800079A0(tab[i]);
        p = base;
        for (j = 0; j < 8; j++) {
            if (((p[0] >> 7) & 1) && i == ((p[3] >> 6) & 1) && hi == (p[3] & 0x3F) && h == ((*(u32 *)p >> 7) & 0xFFFFFF)) {
                return (u32)(base + j * 8);
            }
            p += 8;
        }
    }
    return 0;
}

asm u8 *fn_800079A0(register u32 hash) {
    nofralloc
    mfsdr1 r4
    slwi r0, r4, 16
    clrrwi r4, r4, 16
    ori r0, r0, 0xffff
    and r0, r0, r3
    oris r0, r0, 0x8000
    or r4, r4, r0
    mr r3, r4
    blr
}

u32 fn_800079C4(u32 arg0) {
    u32 t0;
    t0 = fn_80007654(arg0);
    return ((((arg0 >> 12) & 0xFFFF) ^ (t0 & 0x7FFFF)) << 6);
}


u32 fn_80007A00(u32 value) {
    s32 result;

    result = fn_80007654(value);
    result = ((((value >> 12) & 0xffff) ^ (result & 0x7ffff)) << 6);
    return (result ^ 0x01ff0000) ^ 0xffc0;
}

