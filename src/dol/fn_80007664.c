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
