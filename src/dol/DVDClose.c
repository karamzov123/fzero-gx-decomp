#include "types.h"

extern u32 DVDCancel(void);

s32 DVDClose(void) {
    DVDCancel();
    return 1;
}
