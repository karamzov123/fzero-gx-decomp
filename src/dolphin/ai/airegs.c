typedef signed int s32;
typedef unsigned int u32;

/* AI control-register (0xCC005036) bit set/clear helpers.
   Carved from coarse/text_8001A8B4.c. */

#pragma push
#pragma force_active on

// AI control-register (0xCC005000, AICR at +0x36) bit set/clear helpers.
// Absolute-address register array forces MWCC to materialize the base via
// lis 0xcc00 / addi 0x5000 (two-step), matching retail (a single D-form load
// folds the address and diverges). Proven form.
typedef unsigned short u16;
volatile u16 __DSPRegs[] : 0xCC005000;

// provenance: dolsdk2001:src/ai/ai.c:71
void AIStartDMA(void)
{
    __DSPRegs[27] = (u16)(__DSPRegs[27] | 0x8000);
}

// provenance: dolsdk2001:src/ai/ai.c:76
void AIStopDMA(void)
{
    __DSPRegs[27] = (u16)(__DSPRegs[27] & ~0x8000);
}

#pragma pop
