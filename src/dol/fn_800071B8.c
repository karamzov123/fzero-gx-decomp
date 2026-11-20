#include "types.h"


/* --- dol/fn_800071B8.c --- */
extern u32 OSGetArenaHi(void);
extern void OSSetArenaHi(u32);
extern void *memset(void *, int, u32);
extern void fn_8000740C(u32, u32, u32, u32, u32);

extern u32 lbl_801A6710;
extern u32 lbl_801A6714;
extern u32 lbl_801A6718;
extern u32 lbl_801A671C;
extern u32 lbl_801A6720;
extern u16 lbl_801A6724;
extern u16 lbl_801A6726;
extern u32 lbl_801A6CE0;
extern u32 lbl_801A6CF8;

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

/* --- dol/fn_8000740C.c --- */
extern u32 fn_80007654(u32);
extern void fn_80007664(void *, u32, u32);
extern u32 fn_80007730(u32, u32, u32, u32, u32);
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

void fn_8000740C(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 unk_1;
    u8 loc_20;
    Entry *t0;
    u32 t2;

    t0 = (Entry *)fn_80007730(arg0, arg1, arg2, arg3, arg4);
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
    fn_80007664(t0, arg0, arg1);
}
