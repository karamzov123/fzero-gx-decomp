#include "types.h"


/* --- dol/fn_8004D18C.c --- */
extern u32 fn_800474E4(u32);
extern u32 ADXT_Stop(u32);
extern u32 lbl_80091068[];
extern void fn_80083DB0(void *, void *);

void fn_8004D18C(u32 arg0, u32 arg1) {
    u32 v0;
    u32 t0, t1;
    v0 = arg0;
    if (arg0 == 0 || arg1 == 0) {
    v0 = (u32)&lbl_80091068;
    t0 = fn_800474E4(v0);
    v0 = t0;
    } else {
    t1 = ADXT_Stop(v0);
    v0 = t1;
    v0 = *(u32 *)(arg0 + 172);
    fn_80083DB0((void *)v0, (void *)arg1);
    v0 = 0x100000;
    *(u32 *)((u8 *)arg0 + 176) = *(u32 *)((u8 *)arg0 + 172);
    v0--;
    *(u32 *)((u8 *)arg0 + 180) = 0;
    *(u32 *)((u8 *)arg0 + 184) = 0;
    *(u32 *)((u8 *)arg0 + 188) = v0;
    *(u8 *)((u8 *)arg0 + 1) = 1;
    *(u8 *)((u8 *)arg0 + 168) = 1;
    *(u8 *)((u8 *)arg0 + 2) = 0;
    *(u8 *)((u8 *)arg0 + 152) = 0;
    }
}
