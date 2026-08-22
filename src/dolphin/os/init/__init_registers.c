#pragma push
#pragma force_active on

asm __declspec(section ".init") void __init_registers(void)
{
    nofralloc
    li      r0, 0
    li      r3, 0
    li      r4, 0
    li      r5, 0
    li      r6, 0
    li      r7, 0
    li      r8, 0
    li      r9, 0
    li      r10, 0
    li      r11, 0
    li      r12, 0
    li      r14, 0
    li      r15, 0
    li      r16, 0
    li      r17, 0
    li      r18, 0
    li      r19, 0
    li      r20, 0
    li      r21, 0
    li      r22, 0
    li      r23, 0
    li      r24, 0
    li      r25, 0
    li      r26, 0
    li      r27, 0
    li      r28, 0
    li      r29, 0
    li      r30, 0
    li      r31, 0
    lis     r1, 0x801B
    ori     r1, r1, 0x7930
    lis     r2, 0x801A
    ori     r2, r2, 0xEE40
    lis     r13, 0x801A
    ori     r13, r13, 0xE3C0
    blr
}

#pragma pop
