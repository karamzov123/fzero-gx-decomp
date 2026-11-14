#include "types.h"

extern u32 autoInvalidation;

u32 fn_8001989C(u32 arg0) {
    u32 v0;
    v0 = autoInvalidation;
    autoInvalidation = arg0;
    return v0;
}
