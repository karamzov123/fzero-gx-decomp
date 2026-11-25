#include "types.h"
#include <dolphin/base/PPCArch.h>

/* MetroTRK Processor/ppc/Generic/mpc_7xx_603e.c. Saving and restoring the extended register
 * block (HID, BAT, SPRG, time base, cache/thermal, paired-single GQR registers) is
 * CodeWarrior asm in the original: mfspr/mtspr of supervisor registers with no compiler
 * frame. SPRs that PPCArch.h does not name are written by number. */

extern u8 gTRKCPUState[];
extern u8 gTRKRestoreFlags[];

asm void TRKSaveExtended1Block(void) {
    nofralloc
    lis r2, gTRKCPUState@h
    ori r2, r2, gTRKCPUState@l
    mfsr r16, 0
    mfsr r17, 1
    mfsr r18, 2
    mfsr r19, 3
    mfsr r20, 4
    mfsr r21, 5
    mfsr r22, 6
    mfsr r23, 7
    mfsr r24, 8
    mfsr r25, 9
    mfsr r26, 10
    mfsr r27, 11
    mfsr r28, 12
    mfsr r29, 13
    mfsr r30, 14
    mfsr r31, 15
    stmw r16, 0x1a8(r2)
    mftb r10, 268
    mftb r11, 269
    mfspr r12, HID0
    mfspr r13, 1009
    mfsrr1 r14
    mfspr r15, 287
    mfibatu r16, 0
    mfibatl r17, 0
    mfibatu r18, 1
    mfibatl r19, 1
    mfibatu r20, 2
    mfibatl r21, 2
    mfibatu r22, 3
    mfibatl r23, 3
    mfdbatu r24, 0
    mfdbatl r25, 0
    mfdbatu r26, 1
    mfdbatl r27, 1
    mfdbatu r28, 2
    mfdbatl r29, 2
    mfdbatu r30, 3
    mfdbatl r31, 3
    stmw r10, 0x1e8(r2)
    mfsdr1 r22
    mfdar r23
    mfdsisr r24
    mfsprg r25, 0
    mfsprg r26, 1
    mfsprg r27, 2
    mfsprg r28, 3
    li r29, 0x0
    mfspr r30, 1010
    mfear r31
    stmw r22, 0x25c(r2)
    mfspr r20, GQR0
    mfspr r21, GQR1
    mfspr r22, GQR2
    mfspr r23, GQR3
    mfspr r24, GQR4
    mfspr r25, GQR5
    mfspr r26, GQR6
    mfspr r27, GQR7
    mfspr r28, HID2
    mfspr r29, WPAR
    mfspr r30, DMA_U
    mfspr r31, DMA_L
    stmw r20, 0x2fc(r2)
    b L_8008CC90
    mfspr r16, 928
    mfspr r17, 935
    mfspr r18, 936
    mfspr r19, 937
    mfspr r20, 938
    mfspr r21, 939
    mfspr r22, 940
    mfspr r23, 941
    mfspr r24, 942
    mfspr r25, 943
    mfspr r26, 944
    mfspr r27, 951
    mfspr r28, 959
    mfspr r29, 1014
    mfspr r30, 1015
    mfspr r31, 1023
    stmw r16, 0x2b8(r2)
L_8008CC90:
    mfspr r19, 1013
    mfspr r20, PMC1
    mfspr r21, PMC2
    mfspr r22, PMC3
    mfspr r23, PMC4
    mfspr r24, 955
    mfspr r25, MMCR0
    mfspr r26, MMCR1
    mfspr r27, 1020
    mfspr r28, 1021
    mfspr r29, 1022
    mfspr r30, 1019
    mfspr r31, L2CR
    stmw r19, 0x284(r2)
    blr
    mfspr r25, 976
    mfspr r26, 977
    mfspr r27, 978
    mfspr r28, 979
    mfspr r29, 980
    mfspr r30, 981
    mfspr r31, 982
    stmw r25, 0x240(r2)
    mfdec r31
    stw r31, 0x278(r2)
    blr
}

asm void TRKRestoreExtended1Block(void) {
    nofralloc
    lis r2, gTRKCPUState@h
    ori r2, r2, gTRKCPUState@l
    lis r5, gTRKRestoreFlags@h
    ori r5, r5, gTRKRestoreFlags@l
    lbz r3, 0x0(r5)
    lbz r6, 0x1(r5)
    li r0, 0x0
    stb r0, 0x0(r5)
    stb r0, 0x1(r5)
    cmpwi r3, 0x0
    beq L_8008CD34
    lwz r24, 0x1e8(r2)
    lwz r25, 0x1ec(r2)
    mttbl r24
    mttbu r25
L_8008CD34:
    lmw r20, 0x2fc(r2)
    mtspr GQR0, r20
    mtspr GQR1, r21
    mtspr GQR2, r22
    mtspr GQR3, r23
    mtspr GQR4, r24
    mtspr GQR5, r25
    mtspr GQR6, r26
    mtspr GQR7, r27
    mtspr HID2, r28
    mtspr DMA_U, r30
    mtspr DMA_L, r31
    b L_8008CD80
    lmw r26, 0x2e0(r2)
    mtspr 944, r26
    mtspr 951, r27
    mtspr 1014, r29
    mtspr 1015, r30
    mtspr 1023, r31
L_8008CD80:
    lmw r19, 0x284(r2)
    mtspr 1013, r19
    mtspr PMC1, r20
    mtspr PMC2, r21
    mtspr PMC3, r22
    mtspr PMC4, r23
    mtspr 955, r24
    mtspr MMCR0, r25
    mtspr MMCR1, r26
    mtspr 1020, r27
    mtspr 1021, r28
    mtspr 1022, r29
    mtspr 1019, r30
    mtspr L2CR, r31
    b L_8008CDEC
    cmpwi r6, 0x0
    beq L_8008CDCC
    lwz r26, 0x278(r2)
    mtdec r26
L_8008CDCC:
    lmw r25, 0x240(r2)
    mtspr 976, r25
    mtspr 977, r26
    mtspr 978, r27
    mtspr 979, r28
    mtspr 980, r29
    mtspr 981, r30
    mtspr 982, r31
L_8008CDEC:
    lmw r16, 0x1a8(r2)
    mtsr 0, r16
    mtsr 1, r17
    mtsr 2, r18
    mtsr 3, r19
    mtsr 4, r20
    mtsr 5, r21
    mtsr 6, r22
    mtsr 7, r23
    mtsr 8, r24
    mtsr 9, r25
    mtsr 10, r26
    mtsr 11, r27
    mtsr 12, r28
    mtsr 13, r29
    mtsr 14, r30
    mtsr 15, r31
    lmw r12, 0x1f0(r2)
    mtspr HID0, r12
    mtspr 1009, r13
    mtsrr1 r14
    mtspr 287, r15
    mtibatu 0, r16
    mtibatl 0, r17
    mtibatu 1, r18
    mtibatl 1, r19
    mtibatu 2, r20
    mtibatl 2, r21
    mtibatu 3, r22
    mtibatl 3, r23
    mtdbatu 0, r24
    mtdbatl 0, r25
    mtdbatu 1, r26
    mtdbatl 1, r27
    mtdbatu 2, r28
    mtdbatl 2, r29
    mtdbatu 3, r30
    mtdbatl 3, r31
    lmw r22, 0x25c(r2)
    mtsdr1 r22
    mtdar r23
    mtdsisr r24
    mtsprg 0, r25
    mtsprg 1, r26
    mtsprg 2, r27
    mtsprg 3, r28
    mtspr 1010, r30
    mtear r31
    blr
}

