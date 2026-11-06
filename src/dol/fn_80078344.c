#include "dolphin/types.h"
#include "dolphin/hw_regs.h"

#pragma optimization_level 0
#pragma always_inline on
#pragma opt_propagation off
#pragma opt_address_propagation off
#pragma peephole on
#pragma scheduling off
static inline void writeDisplayList(u32 a, u32 b, u32 unused, u32 command, u32 address) {
    /* Volatile stores send commands to the GX write-gather FIFO. */
    *(volatile u8 *)address = command;
    *(volatile u32 *)address = a;  /* fzgx-allow: S2 volatile view keeps the verified load order */
    *(volatile u32 *)address = b;  /* fzgx-allow: S2 volatile view keeps the verified load order */
}
void fn_80078344(register u32 a, register u32 b, register u32 unused,
                 register u32 command, register u32 address) {
    command = 0x40;
    address = GX_FIFO_BASE & 0xFFFF0000;
    address |= GX_FIFO_BASE & 0xFFFF;
    writeDisplayList(a, b, unused, command, address);
}
