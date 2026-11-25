#include "types.h"

typedef u32 (*fn_80070E1C_Fn0)(u32, u32);
typedef s32 (*fn_80070E1C_Fn1)(u32, u32);
typedef u32 (*fn_80070E1C_Fn2)(u32);
typedef u32 (*fn_80070E1C_Fn3)(u32);
typedef u32 (*fn_80070E1C_Fn4)(u32, u32, u32, u32);
typedef u32 (*fn_80070E1C_Fn5)(u32);
typedef u32 (*fn_80070E1C_Fn6)(u32);

extern u32 fn_80078F0C(u32, u32, u32, u32);
extern u32 lbl_801A6D0C;
extern u32 lbl_801A6D10;
extern u32 lbl_801A6D14;
extern u32 lbl_801A6D18;
extern u32 lbl_801A6D1C;
extern u32 lbl_801A6D20;
extern u32 lbl_801A6D24;
extern void OSReport(const char *, ...);
extern void fn_8007174C(u32, u32);

u32 fn_80070E1C(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 alloc;
    u32 size;
    u32 t0;

    
    t0 = ((fn_80070E1C_Fn0)lbl_801A6D24)(arg0, arg1);
    if (((fn_80070E1C_Fn1)lbl_801A6D20)(arg0, t0) == 0) {
        return 0;
    }
    size = ((fn_80070E1C_Fn2)lbl_801A6D1C)(t0);
    alloc = ((fn_80070E1C_Fn3)lbl_801A6D0C)((size + 31) & ~0x1F);
    if (alloc == 0) {
        fn_8007174C((u32)"alloc: <%s> not enough memory.", arg0);
    }
    ((fn_80070E1C_Fn4)lbl_801A6D18)(t0, alloc, size, 0);
    ((fn_80070E1C_Fn5)lbl_801A6D14)(t0);
    ((fn_80070E1C_Fn6)lbl_801A6D10)(t0);
    if (*(u32 *)alloc != 0x47434D46) {
        OSReport(("invalid model format<%s>\n"), arg0);
        return 0;
    }
    fn_80078F0C(alloc, arg1, 0, (u32)("Single Load Model"));
    return alloc;
}
