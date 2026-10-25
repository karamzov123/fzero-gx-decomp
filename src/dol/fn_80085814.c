#include "types.h"

extern u32 OSGetConsoleType(void *arg);
extern s32 lbl_801A6DE8;
extern s32 InitializeUART(u32 arg);
extern s32 WriteUARTN(void *arg0, u32 arg1);
extern void fn_8008DC10(void *arg0, void *arg1, u32 *arg2, void *arg3);

s32 fn_80085814(void *arg0, void *arg1, u32 *arg2, void *arg3) {
    u32 flags = OSGetConsoleType(arg0);
    if ((flags & 0x20000000) == 0) {
        s32 result = 0;
        if (lbl_801A6DE8 == 0) {
            result = InitializeUART(0xE100);
            if (result == 0) {
                lbl_801A6DE8 = 1;
            }
        }
        if (result != 0) {
            return 1;
        }
        if (WriteUARTN(arg1, *arg2) != 0) {
            *arg2 = 0;
            return 1;
        }
    }

    fn_8008DC10(arg0, arg1, arg2, arg3);
    return 0;
}
