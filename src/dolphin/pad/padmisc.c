typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;

extern s32 OSDisableInterrupts(void);
extern s32 OSRestoreInterrupts(s32 level);

/* PAD/DSP-adjacent small helpers at the tail of coarse/text_8001A8B4.c.
   AIInitDMA programs AI DMA registers 0xCC005030/32/36. */

#pragma push
#pragma force_active on

extern unsigned char lbl_801A69A4[4];

// provenance: dolsdk2001:src/ai/AI.c (adapted; retail saves mflr/frame and reloads old after IRQ restore)
s32 AIRegisterDMACallback(register s32 value) {
    s32 old;
    s32 enabled;
    old = *(u32*)lbl_801A69A4;
    enabled = OSDisableInterrupts();
    *(u32*)lbl_801A69A4 = value;
    OSRestoreInterrupts(enabled);
    return old;
}

volatile u16 __DSPRegs[64] : 0xCC005000;

// provenance: dolsdk2001:src/ai/ai.c
void AIInitDMA(u32 start_addr, u32 length)
{
    s32 old = OSDisableInterrupts();
    __DSPRegs[24] = (__DSPRegs[24] & ~0x3FF) | (start_addr >> 16);
    __DSPRegs[25] = (__DSPRegs[25] & ~0xFFE0) | (start_addr & 0xFFFF);
    __DSPRegs[27] = (__DSPRegs[27] & ~0x7FFF) | ((length >> 5) & 0xFFFF);
    OSRestoreInterrupts(old);
}

#pragma pop
