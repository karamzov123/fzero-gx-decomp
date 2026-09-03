// dolphin/os/OSPSInit.c -- carved from coarse/text_8000AB54.c (0x8000AB54-0x8000ABE8).
// provenance: original
// provenance: original
// Melee identity: extern/dolphin/src/dolphin/os/OS.c (__OSPSInit/__OSGetDIConfig).
// Funcs: __OSPSInit, __OSGetDIConfig, OSRegisterVersion.
// All nofralloc asm transcription; hex SPR numerics proven (OSSync.c).

typedef unsigned int u32;

extern u32 PPCMfhid2(void);
extern void PPCMthid2(register u32 v);
extern void ICFlashInvalidate(void);
extern void OSReport(register const char* msg, ...);
extern const char lbl_801A6424[4];

#pragma push
#pragma force_active on

asm void __OSPSInit(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -8(r1)
    bl      PPCMfhid2
    oris	r3, r3, 0xa000
    bl      PPCMthid2
    bl      ICFlashInvalidate
    sync
    li	r3, 0
    mtspr	0x390, r3
    mtspr	0x391, r3
    mtspr	0x392, r3
    mtspr	0x393, r3
    mtspr	0x394, r3
    mtspr	0x395, r3
    mtspr	0x396, r3
    mtspr	0x397, r3
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr
}

// provenance: original
// provenance: original
volatile u32 __DIRegs[64] : 0xCC006000;
u32 __OSGetDIConfig(void)
{
    return __DIRegs[9] & 0xFF;
}

// provenance: original
void OSRegisterVersion(const char* version)
{
    OSReport(lbl_801A6424, version);
}
#pragma pop
