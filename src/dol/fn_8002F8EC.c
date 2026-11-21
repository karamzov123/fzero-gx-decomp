#include "types.h"
#include "dol/globals.h"


/* --- dol/fn_8002F8EC.c --- */
extern s32 __CARDSync(u32);
extern s32 CARDWriteAsync(void *, void *, void *, s32, void *);
extern void __CARDSyncCallback(void);

s32 fn_8002F8EC(u32 arg0, u32 arg1, u32 arg2, s32 arg3) {
    s32 result;

    result = CARDWriteAsync((void *)arg0, (void *)arg1, (void *)arg2, arg3,
                           __CARDSyncCallback);
    if (result < 0) {
        return result;
    }
    return __CARDSync(*(u32 *)arg0);
}
