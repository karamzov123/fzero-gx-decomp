#include "types.h"

extern u8 Debug_BBA;

__declspec(section ".init") void __set_debug_bba(void) {
    Debug_BBA = 1;
}
