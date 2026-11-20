#include "types.h"

extern char lbl_80090C60[40];
extern void fn_800474E4(char *);

s32 fn_8004C658(char *arg0) {
    if (!arg0) {
        fn_800474E4(lbl_80090C60);
        return -1;
    }
    return arg0[1];
}
