#include "types.h"

extern s32 __CARDSync(u32);
extern s32 CARDDeleteAsync(u32, void *, void *);
extern void __CARDSyncCallback(void);

s32 fn_8002FC14(u32 arg0, void *arg1) {
    s32 result;

    result = CARDDeleteAsync(arg0, arg1, __CARDSyncCallback);
    if (result < 0) {
        return result;
    } else {
        result = __CARDSync(arg0);
    }
    return result;
}
