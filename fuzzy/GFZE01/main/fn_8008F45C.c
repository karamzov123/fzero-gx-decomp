/* Non-matching: best partial attempt (84.47% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dolphin/types.h"
#include "dolphin/os/OSInterrupt.h"
#include "sdk_addresses.h"
vu32 __EXIRegs[64] : FZGX_ADDR___EXIRegs;
extern u8 lbl_801A6688;
extern BOOL fn_8008FC3C(void *, s32, u32);
extern BOOL fn_8008F9D8(u32, void *, u32);
static BOOL read_status(u32 *status, BOOL check_read) {
    u32 command;
    BOOL failed;
    volatile u32 *control;
    volatile u32 *busy;
    __EXIRegs[10] = (__EXIRegs[10] & 0x405) | 0xc0;
    control = &__EXIRegs[10];
    command = 0x40000000;
    failed = !fn_8008FC3C(&command, 2, 1);
    do { busy = &__EXIRegs[13]; } while (*busy & 1);
    if (check_read) failed |= !fn_8008FC3C(status, 4, 0);
    else fn_8008FC3C(status, 4, 0);
    while (*busy & 1) {}
    *control &= 0x405;
    return failed;
}
static BOOL transfer_command(u32 command, s32 count) {
    u32 data = command;
    BOOL failed;
    __EXIRegs[10] = (__EXIRegs[10] & 0x405) | 0xc0;
    failed = !fn_8008FC3C(&data, count, 1);
    while (__EXIRegs[13] & 1) {}
    __EXIRegs[10] &= 0x405;
    return failed;
}
s32 fn_8008F45C(void *buffer, u32 length) {
    u32 status;
    BOOL interrupts;
    u32 address;
    interrupts = OSDisableInterrupts();
    do { read_status(&status, FALSE); } while (status & 2);
    lbl_801A6688++;
    if (lbl_801A6688 & 1) address = 0x1000;
    else address = 0;
    address |= 0x1c000;
    while (!fn_8008F9D8(address, buffer, (length + 3) & ~3u)) {}
    do { read_status(&status, FALSE); } while (status & 2);
    address = ((((u32)lbl_801A6688 << 16) | 0x1f000000 | length) & 0x1fffffff) | (0xc000u << 16);
    while (transfer_command(address, 4)) {}
    while (read_status(&status, TRUE) || (status & 2)) {}
    OSRestoreInterrupts(interrupts);
    return 0;
}
