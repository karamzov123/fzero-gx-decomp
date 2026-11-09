#include "types.h"
#include "ppc_ops.h"
#include "ppc_lc.h"

typedef struct MovieSlot {
    u8 pad_0[0x188];
    s32 active;
    u8 pad_18C[0x1300 - 0x18C];
    u32 unk_1300;
} MovieSlot;

extern u32 lbl_12_bss_528C[25];
extern u32 fn_12_CCC4(u32 arg0);
extern u32 fn_12_2017C(void);

static inline MovieSlot *movie_find_slot(void) {
    MovieSlot *slot;
    s32 n;

    slot = (MovieSlot *)lbl_12_bss_528C[22];
    for (n = lbl_12_bss_528C[21]; n > 0; n--) {
        if (slot->active == 1) {
            return slot;
        }
        slot = (MovieSlot *)((u8 *)slot + 0x2000);
    }
    return NULL;
}

static inline void movie_lc_clear(void *slot) {
    void *p;
    s32 off;
    u32 i;
    p = slot;

    if ((lbl_12_bss_528C[18] & 0x10000000) != 0) {
        off = 0;
        for (i = 32; i != 0; i--) {
            ppc_dcbi(p, off);
            ppc_dcbz_l(p, off);
            off += 32;
            ppc_dcbi(p, off);
            ppc_dcbz_l(p, off);
            off += 32;
            ppc_dcbi(p, off);
            ppc_dcbz_l(p, off);
            off += 32;
            ppc_dcbi(p, off);
            ppc_dcbz_l(p, off);
            off += 32;
            ppc_dcbi(p, off);
            ppc_dcbz_l(p, off);
            off += 32;
            ppc_dcbi(p, off);
            ppc_dcbz_l(p, off);
            off += 32;
            ppc_dcbi(p, off);
            ppc_dcbz_l(p, off);
            off += 32;
            ppc_dcbi(p, off);
            ppc_dcbz_l(p, off);
            off += 32;
        }
    }
}

void *fn_12_CF2C(void) {
    MovieSlot *slot;

    slot = movie_find_slot();
    if (!slot) {
        return NULL;
    }
    movie_lc_clear(slot);
    slot = (MovieSlot *)fn_12_CCC4((u32)slot);
    slot->unk_1300 = fn_12_2017C();
    return slot;
}
