#include "types.h"


/* --- dol/GXLoadTexObj.c --- */
struct fn_80036388_gx_T {
    u8 pad_0[0x410];
    u32 (*unk_410)(u32, u32);
};

extern struct fn_80036388_gx_T *gx;
extern void fn_800361F0(u32, u32, u32);

void GXLoadTexObj(u32 arg0, u32 arg1) {
    u32 value;

    value = gx->unk_410(arg0, arg1);
    fn_800361F0(arg0, value, arg1);
}

/* --- dol/GXInitTexCacheRegion.c --- */
typedef struct GXTexRegion {
    u32 tmem_even;
    u32 tmem_odd;
    u8 pad_08[4];
    u8 enable;
    u8 is_32bit;
} GXTexRegion;

void GXInitTexCacheRegion(GXTexRegion *region, u8 enable, u32 tmem_even, s32 size_even,
                          u32 tmem_odd, s32 size_odd) {
    s32 even;
    s32 odd;

    switch (size_even) {
    case 0:
        even = 3;
        break;
    case 1:
        even = 4;
        break;
    case 2:
        even = 5;
        break;
    default:
        break;
        even = 5;
    }

    region->tmem_even = 0;
    region->tmem_even = (region->tmem_even & ~0x7FFFu) | (tmem_even >> 5);
    region->tmem_even = (region->tmem_even & ~0x38000u) | (even << 15);
    region->tmem_even = (region->tmem_even & ~0x1C0000u) | (even << 18);
    region->tmem_even &= ~0x200000u;

    switch (size_odd) {
    case 0:
        even = 3;
        break;
    case 1:
        even = 4;
        break;
    case 2:
        even = 5;
        break;
    case 3:
        even = 0;
        break;
    default:
        break;
        even = 0;
    }

    region->tmem_odd = 0;
    region->tmem_odd = (region->tmem_odd & ~0x7FFFu) | (tmem_odd >> 5);
    region->tmem_odd = (region->tmem_odd & ~0x38000u) | (even << 15);
    region->tmem_odd = (region->tmem_odd & ~0x1C0000u) | (even << 18);

    region->enable = enable;
    region->is_32bit = 1;
}

/* --- dol/GXInitTlutRegion.c --- */
struct GXInitTlutRegion_Arg0 {
    u32 unk_0;
};

void GXInitTlutRegion(struct GXInitTlutRegion_Arg0 *arg0, u32 arg1, u32 arg2) {
    arg0->unk_0 = 0;
    arg0->unk_0 = ((arg0->unk_0 & ~0x3FF) | ((u32)(arg1 - 0x80000) >> 9));
    arg0->unk_0 = ((arg0->unk_0 & 0xFFE003FF) | (arg2 << 10));
    arg0->unk_0 = ((arg0->unk_0 & 0xFFFFFF) | 0x65000000);
}

/* --- dol/GXInvalidateTexAll.c --- */
extern u32 __GXFlushTextureState(void);

void GXInvalidateTexAll(void) {
    u32 v0;
    __GXFlushTextureState();
    *(u8 *)((u8 *)0xCC010000 + -32768) = 97;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    v0 = (0x66000000 + 4096);
    *(u32 *)((u8 *)0xCC010000 + -32768) = v0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(u8 *)((u8 *)0xCC010000 + -32768) = 97;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(u32 *)((u8 *)0xCC010000 + -32768) = (0x66000000 + 4352);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    __GXFlushTextureState();
}
