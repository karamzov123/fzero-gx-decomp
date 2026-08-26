#pragma push
#pragma force_active on

typedef int BOOL;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef u64 OSTime;
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);

asm u64 OSGetTime(void)
{
    nofralloc
retry:
    mftb    r3, 269
    mftb    r4, 268
    mftb    r5, 269
    cmpw    r3, r5
    bne     retry
    blr
}

asm u32 OSGetTick(void)
{
    nofralloc
    mftb    r3, 268
    blr
}

// provenance: mkdd:libs/dolphin/os/OSTime.c:40
OSTime __OSGetSystemTime(void) {
  BOOL enabled;
  volatile OSTime* timeAdjustAddr = (volatile OSTime*)0x800030D8;
  OSTime result;
  enabled = OSDisableInterrupts();
  result = *timeAdjustAddr + OSGetTime();
  OSRestoreInterrupts(enabled);
  return result;
}

#pragma force_active off
#pragma pop
