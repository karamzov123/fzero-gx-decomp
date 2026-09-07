#ifndef FZERO_DOLPHIN_EXI_H
#define FZERO_DOLPHIN_EXI_H

#include <dolphin/assert.h>

/*
 * GFZE01 EXI ABI slice. Like the CARD pilot this is deliberately smaller than
 * a wholesale SDK import: every field below is backed by a retail access in
 * src/dolphin/os/EXIBios.c (offsets cited on each member).
 */
/*
 * `long`, not `int`, for s32. The dolsdk2001/mkdd/melee reference bodies spell
 * every s32 parameter `long` because that is what the shipped SDK headers used.
 * With `typedef int s32` every spliced reference collided with this unit's own
 * forward declarations ("identifier 'EXISync(int)' redeclared ... now declared
 * as 'int (long)'") and five EXI functions could not even be compiled. Both are
 * 32-bit under MWCC PPC, so this is a spelling change, not an ABI change; the
 * unit still compiles to a byte-identical object.
 */
typedef long s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

/*
 * OSContext is a real struct, not `typedef void`: the reference bodies spell
 * the callback parameter `struct OSContext *` (against `void` MWCC rejects the
 * splice), and the interrupt handlers declare one as a LOCAL, so the complete
 * layout is load-bearing for their frame size.
 */
#include <dolphin/os.h>

typedef void (*EXICallback)(s32 chan, OSContext* context);

/* SDK-internal names, kept verbatim so reference bodies splice unmodified. */
#define MAX_CHAN 3
#define MAX_DEV 3

/*
 * exi->state bits, read straight off the retail masks in EXIBios.c:
 *   `& 3` busy test, `| 2` imm start, `| 1` dma start, rlwinm 29/28/27 for
 *   selected/attached/locked. Names match the SDK's so reference bodies splice
 *   unmodified.
 */
#define STATE_DMA 0x01u
#define STATE_IMM 0x02u
#define STATE_BUSY (STATE_DMA | STATE_IMM)
#define STATE_SELECTED 0x04u
#define STATE_ATTACHED 0x08u
#define STATE_LOCKED 0x10u

/* Transfer types, from the `(type << 2) | 1` control word EXIImm writes. */
#define EXI_READ 0
#define EXI_WRITE 1
#define EXI_READ_WRITE 2
#define MAX_TYPE 3

/* EXI clock divider settings, 1 MHz .. 32 MHz. */
#define EXI_FREQ_1M 0
#define EXI_FREQ_2M 1
#define EXI_FREQ_4M 2
#define EXI_FREQ_8M 3
#define EXI_FREQ_16M 4
#define EXI_FREQ_32M 5
#define MAX_FREQ 6

/* An immediate transfer is at most one 32-bit word. */
#define MAX_IMM 4

/* The EXI UART's "initialised" sentinel, from InitializeUART's comparison. */
#define EXI_MAGIC 0xA5FF005Au

/*
 * Device IDs. EXISync special-cases the first two through `subis`; the rest
 * are the switch arms __OSEnableBarnacle compares against, read off its
 * binary-search `lis`/`addi` pairs.
 */
#define EXI_MEMORY_CARD_59 0x00000004u
#define EXI_MEMORY_CARD_123 0x00000008u
#define EXI_MEMORY_CARD_251 0x00000010u
#define EXI_MEMORY_CARD_507 0x00000020u
#define EXI_USB_ADAPTER 0x01010000u
#define EXI_NPDP_GDEV 0x01020000u
#define EXI_MODEM 0x02020000u
#define EXI_MARLIN 0x03010000u
#define EXI_IS_VIEWER 0x05070000u

/*
 * The barnacle UART's transmit command word. WriteUARTN builds
 * `(EXI_TX | 0x2000000) << 6` == 0xA0010000 and QueueLength builds
 * `EXI_TX << 6` == 0x20010000, which pins it.
 */
#define EXI_TX 0x00800400u

/*
 * Function prototypes deliberately stay in the unit source: the retail
 * signatures use `register` parameters and u32/int return spellings that the
 * adapter rewrites per symbol. Declaring them twice only creates conflicts.
 */

typedef char EXI_u32_is_4_bytes[(sizeof(u32) == 4) ? 1 : -1];

#endif
