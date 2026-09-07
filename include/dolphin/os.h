#ifndef FZERO_DOLPHIN_OS_H
#define FZERO_DOLPHIN_OS_H

/*
 * The OS pieces an EXI-era unit needs, in one include. Each part lives in its
 * own header so a unit that only wants (say) tick conversion does not pull in
 * the whole context layout.
 */
#include <dolphin/os_context.h>
#include <dolphin/os_interrupt.h>
#include <dolphin/os_time.h>

/*
 * Console type, from EXISync: `OSGetConsoleType() & 0xF0000000` compared
 * against 0x20000000 (`clrrwi r3, r3, 28` then `subis r0, r3, 0x2000`).
 */
#define OS_CONSOLE_MASK 0xF0000000u
#define OS_CONSOLE_RETAIL 0x00000000u
#define OS_CONSOLE_TDEV 0x20000000u
#define OS_CONSOLE_DEVELOPMENT 0x10000000u

/* OS globals: the boot device code, read as a halfword at 0x800030E6. */
#define __OSDeviceCode (*(u16*)0x800030E6)

#endif
