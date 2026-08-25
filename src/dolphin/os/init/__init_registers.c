#pragma push
#pragma force_active on

extern unsigned char _stack_addr[4];
extern unsigned char _SDA2_BASE_[4];
extern unsigned char _SDA_BASE_[4];
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
    lis     r1, _stack_addr@h
    ori     r1, r1, _stack_addr@l
    lis     r2, _SDA2_BASE_@h
    ori     r2, r2, _SDA2_BASE_@l
    lis     r13, _SDA_BASE_@h
    ori     r13, r13, _SDA_BASE_@l
    blr
}

#pragma pop
