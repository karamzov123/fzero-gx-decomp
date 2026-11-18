#include "types.h"

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
