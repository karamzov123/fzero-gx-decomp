#ifndef DOLPHIN_OS_OSPAIREDINIT_H
#define DOLPHIN_OS_OSPAIREDINIT_H

/* Original SDK __OSPSInit kernel: mtspr GQR0-GQR7 cannot be expressed as C
 * stores. Keep the caller's C prologue and calls; this resets all quantizers.
 * Evidence: retail 0x8000AB74..0x8000AB98, docs/ASM_POLICY.md section 1. */
#define OS_CLEAR_GQRS() \
    asm { \
        li r3, 0; \
        mtspr 912, r3; \
        mtspr 913, r3; \
        mtspr 914, r3; \
        mtspr 915, r3; \
        mtspr 916, r3; \
        mtspr 917, r3; \
        mtspr 918, r3; \
        mtspr 919, r3; \
    }

#endif
