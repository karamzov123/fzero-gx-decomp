#ifndef FZERO_DOLPHIN_OS_TIME_H
#define FZERO_DOLPHIN_OS_TIME_H

/*
 * OS tick conversions. Retail loads the bus clock from 0x800000F8 absolutely,
 * with no relocation, so it is a dereferenced literal rather than an extern
 * (same shape CARDStat.c and CARDRename.c already open-code; this is the
 * shared spelling of it).
 *
 * OSTime is SIGNED: retail divides through `__div2i`, not `__div2u`.
 */
typedef long long OSTime;
typedef unsigned long OSTick;

#define __OSBusClock (*(u32*)0x800000F8)
#define OS_TIMER_CLOCK (__OSBusClock >> 2)

#define OSTicksToSeconds(t) ((u32)((OSTime)(t) / (OSTime)OS_TIMER_CLOCK))
#define OSTicksToMilliseconds(t) ((OSTime)(t) / (OSTime)(OS_TIMER_CLOCK / 1000))

#endif
