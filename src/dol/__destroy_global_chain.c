#include "types.h"

typedef void (*__destroy_global_chain_Fn0)(u32, s32);

extern u32 __global_destructor_chain;

void __destroy_global_chain(void) {
    u32 node;

    while (__global_destructor_chain != 0) {
        node = __global_destructor_chain;
        __global_destructor_chain = *(u32 *)((u8 *)node + 0);
        ((__destroy_global_chain_Fn0)*(u32 *)((u8 *)node + 4))(
            *(u32 *)((u8 *)node + 8), -1);
    }
}


/* The runtime's .dtors entry: __fini (via _dtors) calls the chain at exit. */
__declspec(section ".dtors") static void *const __destroy_global_chain_reference = __destroy_global_chain;
