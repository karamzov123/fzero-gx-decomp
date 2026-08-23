#pragma push
#pragma force_active on

asm void TRK_main(register void* a, register void* b, register void* c, register void* d);
asm void InitMetroTRKCommTable(register void* a, register void* b, register void* c, register void* d);

asm void fn_8008CB20(void)
{
    nofralloc
    twi     31, r0, 0
    blr	
}

asm void fn_8008CB28(void)
{
    nofralloc
    twi     31, r0, 0
    blr	
}

asm void fn_8008CB30(void)
{
    nofralloc
    twi     31, r0, 0
    blr	
}

asm void fn_8008CB38(void)
{
    nofralloc
    twi     31, r0, 0
    blr	
}

asm void TRKSaveExtended1Block(void)
{
    nofralloc
    lis	r2, -0x7fe6
    ori	r2, r2, 0x5160
    mfsr    r16, 0
    mfsr    r17, 1
    mfsr    r18, 2
    mfsr    r19, 3
    mfsr    r20, 4
    mfsr    r21, 5
    mfsr    r22, 6
    mfsr    r23, 7
    mfsr    r24, 8
    mfsr    r25, 9
    mfsr    r26, 10
    mfsr    r27, 11
    mfsr    r28, 12
    mfsr    r29, 13
    mfsr    r30, 14
    mfsr    r31, 15
    stmw	r16, 0x1a8(r2)
    mftb	r10, 0x10c
    mftbu	r11
    mfspr	r12, 0x3f0
    mfspr	r13, 0x3f1
    mfspr	r14, 0x1b
    mfpvr	r15
    mfspr   r16, 528
    mfspr   r17, 529
    mfspr   r18, 530
    mfspr   r19, 531
    mfspr   r20, 532
    mfspr   r21, 533
    mfspr   r22, 534
    mfspr   r23, 535
    mfspr   r24, 536
    mfspr   r25, 537
    mfspr   r26, 538
    mfspr   r27, 539
    mfspr   r28, 540
    mfspr   r29, 541
    mfspr   r30, 542
    mfspr   r31, 543
    stmw	r10, 0x1e8(r2)
    mfspr	r22, 0x19
    mfdar	r23
    mfspr   r24, 18
    mfspr	r25, 0x110
    mfspr	r26, 0x111
    mfspr	r27, 0x112
    mfspr	r28, 0x113
    li	r29, 0
    mfspr	r30, 0x3f2
    mfspr	r31, 0x11a
    stmw	r22, 0x25c(r2)
    mfspr	r20, 0x390
    mfspr	r21, 0x391
    mfspr	r22, 0x392
    mfspr	r23, 0x393
    mfspr	r24, 0x394
    mfspr	r25, 0x395
    mfspr	r26, 0x396
    mfspr	r27, 0x397
    mfspr	r28, 0x398
    mfspr	r29, 0x399
    mfspr	r30, 0x39a
    mfspr	r31, 0x39b
    stmw	r20, 0x2fc(r2)
    b       _8008cc90
    mfspr	r16, 0x3a0
    mfspr	r17, 0x3a7
    mfspr	r18, 0x3a8
    mfspr	r19, 0x3a9
    mfspr	r20, 0x3aa
    mfspr	r21, 0x3ab
    mfspr	r22, 0x3ac
    mfspr	r23, 0x3ad
    mfspr	r24, 0x3ae
    mfspr	r25, 0x3af
    mfspr	r26, 0x3b0
    mfspr	r27, 0x3b7
    mfspr	r28, 0x3bf
    mfspr	r29, 0x3f6
    mfspr	r30, 0x3f7
    mfspr	r31, 0x3ff
    stmw	r16, 0x2b8(r2)
_8008cc90:
    mfspr	r19, 0x3f5
    mfspr	r20, 0x3b9
    mfspr	r21, 0x3ba
    mfspr	r22, 0x3bd
    mfspr	r23, 0x3be
    mfspr	r24, 0x3bb
    mfspr	r25, 0x3b8
    mfspr	r26, 0x3bc
    mfspr	r27, 0x3fc
    mfspr	r28, 0x3fd
    mfspr	r29, 0x3fe
    mfspr   r30, 1019
    mfspr	r31, 0x3f9
    stmw	r19, 0x284(r2)
    blr	
    mfspr	r25, 0x3d0
    mfspr	r26, 0x3d1
    mfspr	r27, 0x3d2
    mfspr	r28, 0x3d3
    mfspr   r29, 980
    mfspr   r30, 981
    mfspr	r31, 0x3d6
    stmw	r25, 0x240(r2)
    mfspr	r31, 0x16
    stw	r31, 0x278(r2)
    blr	
}

asm void TRKRestoreExtended1Block(void)
{
    nofralloc
    lis	r2, -0x7fe6
    ori	r2, r2, 0x5160
    lis	r5, -0x7feb
    ori	r5, r5, 0xb868
    lbz	r3, 0(r5)
    lbz	r6, 1(r5)
    li	r0, 0
    stb	r0, 0(r5)
    stb	r0, 1(r5)
    cmpwi	r3, 0
    beq     _8008cd34
    lwz	r24, 0x1e8(r2)
    lwz	r25, 0x1ec(r2)
    mttbl	r24
    mttbu	r25
_8008cd34:
    lmw	r20, 0x2fc(r2)
    mtspr	0x390, r20
    mtspr	0x391, r21
    mtspr	0x392, r22
    mtspr	0x393, r23
    mtspr	0x394, r24
    mtspr	0x395, r25
    mtspr	0x396, r26
    mtspr	0x397, r27
    mtspr	0x398, r28
    mtspr	0x39a, r30
    mtspr	0x39b, r31
    b       _8008cd80
    lmw	r26, 0x2e0(r2)
    mtspr	0x3b0, r26
    mtspr	0x3b7, r27
    mtspr	0x3f6, r29
    mtspr	0x3f7, r30
    mtspr	0x3ff, r31
_8008cd80:
    lmw	r19, 0x284(r2)
    mtspr	0x3f5, r19
    mtspr	0x3b9, r20
    mtspr	0x3ba, r21
    mtspr	0x3bd, r22
    mtspr	0x3be, r23
    mtspr	0x3bb, r24
    mtspr	0x3b8, r25
    mtspr	0x3bc, r26
    mtspr	0x3fc, r27
    mtspr	0x3fd, r28
    mtspr	0x3fe, r29
    mtspr   1019, r30
    mtspr	0x3f9, r31
    b       _8008cdec
    cmpwi	r6, 0
    beq     _8008cdcc
    lwz	r26, 0x278(r2)
    mtspr	0x16, r26
_8008cdcc:
    lmw	r25, 0x240(r2)
    mtspr	0x3d0, r25
    mtspr	0x3d1, r26
    mtspr	0x3d2, r27
    mtspr	0x3d3, r28
    mtspr   980, r29
    mtspr   981, r30
    mtspr	0x3d6, r31
_8008cdec:
    lmw	r16, 0x1a8(r2)
    mtsr    0, r16
    mtsr    1, r17
    mtsr    2, r18
    mtsr    3, r19
    mtsr    4, r20
    mtsr    5, r21
    mtsr    6, r22
    mtsr    7, r23
    mtsr    8, r24
    mtsr    9, r25
    mtsr    10, r26
    mtsr    11, r27
    mtsr    12, r28
    mtsr    13, r29
    mtsr    14, r30
    mtsr    15, r31
    lmw	r12, 0x1f0(r2)
    mtspr	0x3f0, r12
    mtspr	0x3f1, r13
    mtspr	0x1b, r14
    mtspr	0x11f, r15
    mtspr   528, r16
    mtspr   529, r17
    mtspr   530, r18
    mtspr   531, r19
    mtspr   532, r20
    mtspr   533, r21
    mtspr   534, r22
    mtspr   535, r23
    mtspr   536, r24
    mtspr   537, r25
    mtspr   538, r26
    mtspr   539, r27
    mtspr   540, r28
    mtspr   541, r29
    mtspr   542, r30
    mtspr   543, r31
    lmw	r22, 0x25c(r2)
    mtspr	0x19, r22
    mtdar	r23
    mtspr   18, r24
    mtspr	0x110, r25
    mtspr	0x111, r26
    mtspr	0x112, r27
    mtspr	0x113, r28
    mtspr	0x3f2, r30
    mtspr	0x11a, r31
    blr	
}

asm void InitMetroTRK(void)
{
    nofralloc
    addi	r1, r1, -4
    stw	r3, 0(r1)
    lis	r3, -0x7fe6
    ori	r3, r3, 0x5160
    stmw	r0, 0(r3)
    lwz	r4, 0(r1)
    addi	r1, r1, 4
    stw	r1, 4(r3)
    stw	r4, 0xc(r3)
    mflr	r4
    stw	r4, 0x84(r3)
    stw	r4, 0x80(r3)
    mfcr	r4
    stw	r4, 0x88(r3)
    mfmsr	r4
    ori	r3, r4, 0x8000
    xori	r3, r3, 0x8000
    mtmsr	r3
    mtspr	0x1b, r4
    bl      TRKSaveExtended1Block
    lis	r3, -0x7fe6
    ori	r3, r3, 0x5160
    lmw	r0, 0(r3)
    li	r0, 0
    mtspr	0x3f2, r0
    mtspr	0x3f5, r0
    lis	r1, -0x7fe5
    ori	r1, r1, 0x9930
    mr	r3, r5
    bl      InitMetroTRKCommTable
    cmpwi	r3, 1
    bne     _8008cf40
    lwz	r4, 0x84(r3)
    mtlr	r4
    lmw	r0, 0(r3)
    blr	
_8008cf40:
    b       TRK_main
    blr	
}

asm void InitMetroTRK_BBA(void)
{
    nofralloc
    addi	r1, r1, -4
    stw	r3, 0(r1)
    lis	r3, -0x7fe6
    ori	r3, r3, 0x5160
    stmw	r0, 0(r3)
    lwz	r4, 0(r1)
    addi	r1, r1, 4
    stw	r1, 4(r3)
    stw	r4, 0xc(r3)
    mflr	r4
    stw	r4, 0x84(r3)
    stw	r4, 0x80(r3)
    mfcr	r4
    stw	r4, 0x88(r3)
    mfmsr	r4
    ori	r3, r4, 0x8000
    mtmsr	r3
    mtspr	0x1b, r4
    bl      TRKSaveExtended1Block
    lis	r3, -0x7fe6
    ori	r3, r3, 0x5160
    lmw	r0, 0(r3)
    li	r0, 0
    mtspr	0x3f2, r0
    mtspr	0x3f5, r0
    lis	r1, -0x7fe5
    ori	r1, r1, 0x9930
    li	r3, 2
    bl      InitMetroTRKCommTable
    cmpwi	r3, 1
    bne     _8008cfd4
    lwz	r4, 0x84(r3)
    mtlr	r4
    lmw	r0, 0(r3)
    blr	
_8008cfd4:
    b       TRK_main
    blr	
}

#pragma pop
