#include "sdk_addresses.h"
#include "dolphin/types.h"
#include "dolphin/gx.h"

typedef union {
    u8 u8;
    u32 u32;
} Func8008D6BCFifo;
/* Write-gather FIFO accesses must remain ordered hardware writes. */
extern volatile Func8008D6BCFifo __WGFifo[];

#pragma optimization_level 0
#pragma opt_propagation off
#pragma peephole on
u32 func_8008D6BC(register u32 value, register u8 command, register u32 fifo) {
    /* FIFO writes are volatile hardware accesses. */
    fifo = FZGX_ADDR___CPRegs;
    command = 0x61;
    fifo |= 0x8000;
    ((volatile Func8008D6BCFifo *)fifo)->u8 = command;  /* fzgx-allow: S2 volatile view keeps the verified load order */
    ((volatile Func8008D6BCFifo *)fifo)->u32 = value;  /* fzgx-allow: S2 volatile view keeps the verified load order */
    return value;
}
