#include <dolphin/base/PPCArch.h>

/* Dolphin SDK base/PPCArch.c. The register accessors are CodeWarrior asm functions in the
 * original (privileged mfspr/mtspr/mtmsr and sc, no compiler frame); the FPSCR accessors and
 * PPCDisableSpeculation are C. */

asm u32 PPCMfmsr(void) {
    nofralloc
    mfmsr r3
    blr
}

asm void PPCMtmsr(register u32 newMSR) {
    nofralloc
    mtmsr newMSR
    blr
}

asm u32 PPCMfhid0(void) {
    nofralloc
    mfspr r3, HID0
    blr
}

asm void PPCMthid0(register u32 newHID0) {
    nofralloc
    mtspr HID0, newHID0
    blr
}

asm u32 PPCMfl2cr(void) {
    nofralloc
    mfspr r3, L2CR
    blr
}

asm void PPCMtl2cr(register u32 newL2cr) {
    nofralloc
    mtspr L2CR, newL2cr
    blr
}

asm void PPCMtdec(register u32 newDec) {
    nofralloc
    mtdec newDec
    blr
}

asm void PPCSync(void) {
    nofralloc
    sc
    blr
}

asm void PPCHalt(void) {
    nofralloc
    sync
loop:
    nop
    li r3, 0
    nop
    b loop
}

asm void PPCMtmmcr0(register u32 newMmcr0) {
    nofralloc
    mtspr MMCR0, newMmcr0
    blr
}

asm void PPCMtmmcr1(register u32 newMmcr1) {
    nofralloc
    mtspr MMCR1, newMmcr1
    blr
}

asm u32 PPCMfpmc1(void) {
    nofralloc
    mfspr r3, PMC1
    blr
}

asm void PPCMtpmc1(register u32 newPmc1) {
    nofralloc
    mtspr PMC1, newPmc1
    blr
}

asm u32 PPCMfpmc2(void) {
    nofralloc
    mfspr r3, PMC2
    blr
}

asm void PPCMtpmc2(register u32 newPmc2) {
    nofralloc
    mtspr PMC2, newPmc2
    blr
}

asm u32 PPCMfpmc3(void) {
    nofralloc
    mfspr r3, PMC3
    blr
}

asm void PPCMtpmc3(register u32 newPmc3) {
    nofralloc
    mtspr PMC3, newPmc3
    blr
}

asm u32 PPCMfpmc4(void) {
    nofralloc
    mfspr r3, PMC4
    blr
}

asm void PPCMtpmc4(register u32 newPmc4) {
    nofralloc
    mtspr PMC4, newPmc4
    blr
}

union FpscrUnion {
    f64 f;
    struct {
        u32 fpscr_pad;
        u32 fpscr;
    } u;
};

u32 PPCMffpscr(void) {
    union FpscrUnion m;

    asm {
        mffs f31
        stfd f31, m.f
    }
    return m.u.fpscr;
}

void PPCMtfpscr(register u32 newFPSCR) {
    union FpscrUnion m;

    asm {
        li r4, 0
        stw r4, m.u.fpscr_pad
        stw newFPSCR, m.u.fpscr
        lfd f31, m.f
        mtfsf 255, f31
    }
}

asm u32 PPCMfhid2(void) {
    nofralloc
    mfspr r3, HID2
    blr
}

asm void PPCMthid2(register u32 newHID2) {
    nofralloc
    mtspr HID2, newHID2
    blr
}

asm u32 PPCMfwpar(void) {
    nofralloc
    sync
    mfspr r3, WPAR
    blr
}

asm void PPCMtwpar(register u32 newWPAR) {
    nofralloc
    mtspr WPAR, newWPAR
    blr
}

void PPCDisableSpeculation(void) {
    PPCMthid0(PPCMfhid0() | HID0_SPD);
}

asm void PPCSetFpNonIEEEMode(void) {
    nofralloc
    mtfsb1 29
    blr
}
