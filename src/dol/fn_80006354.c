#include "types.h"

extern u32 DVDReadAsyncPrio(u32, u32, u32, u32, u32, u32);
extern u8 lbl_801A66DB;
extern void fn_80006340(void);
extern void fn_8000659C(void);

u32 fn_80006354(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    lbl_801A66DB = 1;
    DVDReadAsyncPrio(arg0, arg1, arg2, arg3, (u32)fn_80006340, 2);
    while ((s8)lbl_801A66DB != 0) {
        fn_8000659C();
    }
    return *(u32 *)((u8 *)arg0 + 52);
}
