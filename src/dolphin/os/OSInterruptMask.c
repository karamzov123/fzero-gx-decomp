typedef int BOOL;
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned long long u64;
typedef signed long long s64;
typedef float f32;

#define OS_INTERRUPTMASK_MEM_0        0x00000001
#define OS_INTERRUPTMASK_MEM_1        0x00000002
#define OS_INTERRUPTMASK_MEM_2        0x00000004
#define OS_INTERRUPTMASK_MEM_3        0x00000008
#define OS_INTERRUPTMASK_MEM_ADDRESS  0x00000010
#define OS_INTERRUPTMASK_MEM          (OS_INTERRUPTMASK_MEM_0 | \
                                       OS_INTERRUPTMASK_MEM_1 | \
                                       OS_INTERRUPTMASK_MEM_2 | \
                                       OS_INTERRUPTMASK_MEM_3 | \
                                       OS_INTERRUPTMASK_MEM_ADDRESS)
#define OS_INTERRUPTMASK_DSP_AI       0x00000020
#define OS_INTERRUPTMASK_DSP_ARAM     0x00000040
#define OS_INTERRUPTMASK_DSP_DSP      0x00000080
#define OS_INTERRUPTMASK_DSP          (OS_INTERRUPTMASK_DSP_AI | \
                                       OS_INTERRUPTMASK_DSP_ARAM | \
                                       OS_INTERRUPTMASK_DSP_DSP)
#define OS_INTERRUPTMASK_AI_AI        0x00000100
#define OS_INTERRUPTMASK_AI           OS_INTERRUPTMASK_AI_AI
#define OS_INTERRUPTMASK_EXI_0_EXI    0x00000200
#define OS_INTERRUPTMASK_EXI_0_TC     0x00000400
#define OS_INTERRUPTMASK_EXI_0_EXT    0x00000800
#define OS_INTERRUPTMASK_EXI_0        (OS_INTERRUPTMASK_EXI_0_EXI | \
                                       OS_INTERRUPTMASK_EXI_0_TC | \
                                       OS_INTERRUPTMASK_EXI_0_EXT)
#define OS_INTERRUPTMASK_EXI_1_EXI    0x00001000
#define OS_INTERRUPTMASK_EXI_1_TC     0x00002000
#define OS_INTERRUPTMASK_EXI_1_EXT    0x00004000
#define OS_INTERRUPTMASK_EXI_1        (OS_INTERRUPTMASK_EXI_1_EXI | \
                                       OS_INTERRUPTMASK_EXI_1_TC | \
                                       OS_INTERRUPTMASK_EXI_1_EXT)
#define OS_INTERRUPTMASK_EXI_2_EXI    0x00008000
#define OS_INTERRUPTMASK_EXI_2_TC     0x00010000
#define OS_INTERRUPTMASK_EXI_2        (OS_INTERRUPTMASK_EXI_2_EXI | \
                                       OS_INTERRUPTMASK_EXI_2_TC)
#define OS_INTERRUPTMASK_EXI          (OS_INTERRUPTMASK_EXI_0 | \
                                       OS_INTERRUPTMASK_EXI_1 | \
                                       OS_INTERRUPTMASK_EXI_2)
#define OS_INTERRUPTMASK_PI_CP        0x00020000
#define OS_INTERRUPTMASK_PI_PE_TOKEN  0x00040000
#define OS_INTERRUPTMASK_PI_PE_FINISH 0x00080000
#define OS_INTERRUPTMASK_PI_PE        (OS_INTERRUPTMASK_PI_PE_TOKEN | \
                                       OS_INTERRUPTMASK_PI_PE_FINISH)
#define OS_INTERRUPTMASK_PI_SI        0x00100000
#define OS_INTERRUPTMASK_PI_DI        0x00200000
#define OS_INTERRUPTMASK_PI_RSW       0x00400000
#define OS_INTERRUPTMASK_PI_ERROR     0x00800000
#define OS_INTERRUPTMASK_PI_VI        0x01000000
#define OS_INTERRUPTMASK_PI_DEBUG     0x02000000
#define OS_INTERRUPTMASK_PI_HSP       0x04000000
#define OS_INTERRUPTMASK_PI           (OS_INTERRUPTMASK_PI_CP | \
                                       OS_INTERRUPTMASK_PI_PE | \
                                       OS_INTERRUPTMASK_PI_SI | \
                                       OS_INTERRUPTMASK_PI_DI | \
                                       OS_INTERRUPTMASK_PI_RSW | \
                                       OS_INTERRUPTMASK_PI_ERROR | \
                                       OS_INTERRUPTMASK_PI_VI | \
                                       OS_INTERRUPTMASK_PI_DEBUG | \
                                       OS_INTERRUPTMASK_PI_HSP)

enum {
    __OS_INTERRUPT_MEM_0 = 0,
    __OS_INTERRUPT_MEM_1,
    __OS_INTERRUPT_MEM_2,
    __OS_INTERRUPT_MEM_3,
    __OS_INTERRUPT_MEM_ADDRESS,
    __OS_INTERRUPT_DSP_AI,
    __OS_INTERRUPT_DSP_ARAM,
    __OS_INTERRUPT_DSP_DSP,
    __OS_INTERRUPT_AI_AI,
    __OS_INTERRUPT_EXI_0_EXI,
    __OS_INTERRUPT_EXI_0_TC,
    __OS_INTERRUPT_EXI_0_EXT,
    __OS_INTERRUPT_EXI_1_EXI,
    __OS_INTERRUPT_EXI_1_TC,
    __OS_INTERRUPT_EXI_1_EXT,
    __OS_INTERRUPT_EXI_2_EXI,
    __OS_INTERRUPT_EXI_2_TC,
    __OS_INTERRUPT_PI_CP,
    __OS_INTERRUPT_PI_PE_TOKEN,
    __OS_INTERRUPT_PI_PE_FINISH,
    __OS_INTERRUPT_PI_SI,
    __OS_INTERRUPT_PI_DI,
    __OS_INTERRUPT_PI_RSW,
    __OS_INTERRUPT_PI_ERROR,
    __OS_INTERRUPT_PI_VI,
    __OS_INTERRUPT_PI_DEBUG,
    __OS_INTERRUPT_PI_HSP,
};

typedef void (*__OSInterruptHandler)(int interrupt, void* context);
typedef struct OSContext OSContext;

#define HW_BASE          0xCC004000
#define __MEMRegs        ((volatile u16*)(HW_BASE + 0x000))
#define __DSPRegs        ((volatile u16*)(HW_BASE + 0x1000))
#define __AIRegs         ((volatile u32*)(HW_BASE + 0x2C00))
#define __EXIRegs        ((volatile u32*)(HW_BASE + 0x2800))
#define __PIRegs         ((volatile u32*)(HW_BASE - 0x1000))
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern void OSLoadContext(OSContext* context);
extern void OSDisableScheduler(void);
extern void OSEnableScheduler(void);
extern void __OSReschedule(void);
extern unsigned long long OSGetTime(void);
extern __OSInterruptHandler __OSGetInterruptHandler(short interrupt);

/* r13-anchored small data (base 0x801A63C0 + 0x8000) */
extern u32 InterruptPrioTable[12]; /* .data:0x80123A60 */
extern __OSInterruptHandler* InterruptHandlerTable; /* .sbss:0x801A67A8 */
extern volatile u16 __OSLastInterrupt;              /* .sbss:0x801A67B0 */
extern volatile unsigned long long __OSLastInterruptTime; /* .sbss:0x801A67B8 */
extern volatile u32 __OSLastInterruptSrr0;          /* .sbss:0x801A67AC */

asm u32 fn_8000D5E4(register u32 mask, register u32 current)
{
    nofralloc
    cntlzw   r0, r3
    cmpwi    r0, 0xc
    bge      L_8000d610
    cmpwi    r0, 8
    beq      L_8000d6f0
    bge      L_8000d720
    cmpwi    r0, 5
    bge      L_8000d69c
    cmpwi    r0, 0
    bge      L_8000d630
    b        L_8000d8b8
L_8000d610:
    cmpwi    r0, 0x11
    bge      L_8000d624
    cmpwi    r0, 0xf
    bge      L_8000d7c4
    b        L_8000d770
L_8000d624:
    cmpwi    r0, 0x1b
    bge      L_8000d8b8
    b        L_8000d804
L_8000d630:
    rlwinm   r0, r4, 0, 0, 0
    cmplwi   r0, 0
    li       r5, 0
    bne      L_8000d644
    ori      r5, r5, 1
L_8000d644:
    rlwinm   r0, r4, 0, 1, 1
    cmplwi   r0, 0
    bne      L_8000d654
    ori      r5, r5, 2
L_8000d654:
    rlwinm   r0, r4, 0, 2, 2
    cmplwi   r0, 0
    bne      L_8000d65c
    ori      r5, r5, 4
L_8000d65c:
    rlwinm   r0, r4, 0, 3, 3
    cmplwi   r0, 0
    bne      L_8000d664
    ori      r5, r5, 8
L_8000d664:
    rlwinm   r0, r4, 0, 4, 4
    cmplwi   r0, 0
    bne      L_8000d66c
    ori      r5, r5, 0x10
L_8000d66c:
    lis      r4, -0x3400
    clrlwi   r0, r5, 0x10
    addi     r4, r4, 0x4000
    sth      r0, 0x1c(r4)
    rlwinm   r3, r3, 0, 5, 31
    b        L_8000d8b8
L_8000d69c:
    lis      r5, -0x3400
    addi     r5, r5, 0x5000
    addi     r5, r5, 0xa
    rlwinm   r0, r4, 0, 5, 5
    lhz      r6, 0(r5)
    cmplwi   r0, 0
    rlwinm   r6, r6, 0, 0x1d, 0x16
    bne      L_8000d6c0
    ori      r6, r6, 0x10
L_8000d6c0:
    rlwinm   r0, r4, 0, 6, 6
    cmplwi   r0, 0
    bne      L_8000d6d0
    ori      r6, r6, 0x40
L_8000d6d0:
    rlwinm   r0, r4, 0, 7, 7
    cmplwi   r0, 0
    bne      L_8000d6e0
    ori      r6, r6, 0x100
L_8000d6e0:
    clrlwi   r0, r6, 0x10
    sth      r0, 0(r5)
    rlwinm   r3, r3, 0, 8, 4
    b        L_8000d8b8
L_8000d6f0:
    rlwinm   r0, r4, 0, 8, 8
    lis      r4, -0x3400
    cmplwi   r0, 0
    lwz      r5, 0x6c00(r4)
    li       r0, -0x2d
    and      r5, r5, r0
    bne      L_8000d710
    ori      r5, r5, 4
L_8000d710:
    lis      r4, -0x3400
    stw      r5, 0x6c00(r4)
    rlwinm   r3, r3, 0, 9, 7
    b        L_8000d8b8
L_8000d720:
    rlwinm   r0, r4, 0, 9, 9
    lis      r5, -0x3400
    cmplwi   r0, 0
    lwz      r5, 0x6800(r5)
    li       r0, -0x2c10
    and      r5, r5, r0
    bne      L_8000d740
    ori      r5, r5, 1
L_8000d740:
    rlwinm   r0, r4, 0, 0xa, 0xa
    cmplwi   r0, 0
    bne      L_8000d750
    ori      r5, r5, 4
L_8000d750:
    rlwinm   r0, r4, 0, 0xb, 0xb
    cmplwi   r0, 0
    bne      L_8000d760
    ori      r5, r5, 0x400
L_8000d760:
    lis      r4, -0x3400
    stw      r5, 0x6800(r4)
    rlwinm   r3, r3, 0, 0xc, 8
    b        L_8000d8b8
L_8000d770:
    lis      r5, -0x3400
    addi     r6, r5, 0x6800
    addi     r6, r6, 0x14
    rlwinm   r0, r4, 0, 0xc, 0xc
    lwz      r7, 0(r6)
    li       r5, -0xc10
    cmplwi   r0, 0
    and      r7, r7, r5
    bne      L_8000d798
    ori      r7, r7, 1
L_8000d798:
    rlwinm   r0, r4, 0, 0xd, 0xd
    cmplwi   r0, 0
    bne      L_8000d7a8
    ori      r7, r7, 4
L_8000d7a8:
    rlwinm   r0, r4, 0, 0xe, 0xe
    cmplwi   r0, 0
    bne      L_8000d7b8
    ori      r7, r7, 0x400
L_8000d7b8:
    stw      r7, 0(r6)
    rlwinm   r3, r3, 0, 0xf, 0xb
    b        L_8000d8b8
L_8000d7c4:
    lis      r5, -0x3400
    addi     r5, r5, 0x6800
    addi     r5, r5, 0x28
    rlwinm   r0, r4, 0, 0xf, 0xf
    lwz      r6, 0(r5)
    cmplwi   r0, 0
    rlwinm   r6, r6, 0, 0, 0x1b
    bne      L_8000d7e8
    ori      r6, r6, 1
L_8000d7e8:
    rlwinm   r0, r4, 0, 0x10, 0x10
    cmplwi   r0, 0
    bne      L_8000d7f8
    ori      r6, r6, 4
L_8000d7f8:
    stw      r6, 0(r5)
    rlwinm   r3, r3, 0, 0x11, 0xe
    b        L_8000d8b8
L_8000d804:
    rlwinm   r0, r4, 0, 0x11, 0x11
    cmplwi   r0, 0
    li       r5, 0xf0
    bne      L_8000d818
    ori      r5, r5, 0x800
L_8000d818:
    rlwinm   r0, r4, 0, 0x14, 0x14
    cmplwi   r0, 0
    bne      L_8000d828
    ori      r5, r5, 8
L_8000d828:
    rlwinm   r0, r4, 0, 0x15, 0x15
    cmplwi   r0, 0
    bne      L_8000d838
    ori      r5, r5, 4
L_8000d838:
    rlwinm   r0, r4, 0, 0x16, 0x16
    cmplwi   r0, 0
    bne      L_8000d848
    ori      r5, r5, 2
L_8000d848:
    rlwinm   r0, r4, 0, 0x17, 0x17
    cmplwi   r0, 0
    bne      L_8000d858
    ori      r5, r5, 1
L_8000d858:
    rlwinm   r0, r4, 0, 0x18, 0x18
    cmplwi   r0, 0
    bne      L_8000d868
    ori      r5, r5, 0x100
L_8000d868:
    rlwinm   r0, r4, 0, 0x19, 0x19
    cmplwi   r0, 0
    bne      L_8000d878
    ori      r5, r5, 0x1000
L_8000d878:
    rlwinm   r0, r4, 0, 0x12, 0x12
    cmplwi   r0, 0
    bne      L_8000d888
    ori      r5, r5, 0x200
L_8000d888:
    rlwinm   r0, r4, 0, 0x13, 0x13
    cmplwi   r0, 0
    bne      L_8000d898
    ori      r5, r5, 0x400
L_8000d898:
    rlwinm   r0, r4, 0, 0x1a, 0x1a
    cmplwi   r0, 0
    bne      L_8000d8a8
    ori      r5, r5, 0x2000
L_8000d8a8:
    lis      r4, -0x3400
    addi     r4, r4, 0x3000
    stw      r5, 4(r4)
    rlwinm   r3, r3, 0, 0x1b, 0x10
L_8000d8b8:
    blr
}


asm u32 __OSMaskInterrupts(register u32 global)
{
    nofralloc
    mflr     r0
    stw      r0, 4(r1)
    stwu     r1, -0x20(r1)
    stw      r31, 0x1c(r1)
    stw      r30, 0x18(r1)
    stw      r29, 0x14(r1)
    mr       r31, r3
    bl       OSDisableInterrupts
    lis      r4, -0x8000
    lwz      r29, 0xc4(r4)
    mr       r30, r3
    lwz      r5, 0xc8(r4)
    or       r0, r29, r5
    andc     r3, r31, r0
    or       r31, r31, r29
    stw      r31, 0xc4(r4)
    or       r31, r31, r5
    b        L_msk_1
L_msk_0:
    mr       r4, r31
    bl       fn_8000D5E4
L_msk_1:
    b        L_msk_2
L_msk_2:
    b        L_msk_loop
L_msk_loop:
    cmplwi   r3, 0
    bne      L_msk_0
    mr       r3, r30
    bl       OSRestoreInterrupts
    mr       r3, r29
    lwz      r0, 0x24(r1)
    lwz      r31, 0x1c(r1)
    lwz      r30, 0x18(r1)
    lwz      r29, 0x14(r1)
    addi     r1, r1, 0x20
    mtlr     r0
    blr
}


asm u32 __OSUnmaskInterrupts(register u32 global)
{
    nofralloc
    mflr     r0
    stw      r0, 4(r1)
    stwu     r1, -0x20(r1)
    stw      r31, 0x1c(r1)
    stw      r30, 0x18(r1)
    stw      r29, 0x14(r1)
    mr       r31, r3
    bl       OSDisableInterrupts
    lis      r4, -0x8000
    lwz      r29, 0xc4(r4)
    mr       r30, r3
    lwz      r5, 0xc8(r4)
    or       r0, r29, r5
    andc     r3, r31, r0
    or       r31, r31, r29
    stw      r31, 0xc4(r4)
    or       r31, r31, r5
    b        L_umsk_1
L_umsk_0:
    mr       r4, r31
    bl       fn_8000D5E4
L_umsk_1:
    b        L_umsk_1b
L_umsk_1b:
    b        L_umsk_loop
L_umsk_loop:
    cmplwi   r3, 0
    bne      L_umsk_0
    mr       r3, r30
    bl       OSRestoreInterrupts
    mr       r3, r29
    lwz      r0, 0x24(r1)
    lwz      r31, 0x1c(r1)
    lwz      r30, 0x18(r1)
    lwz      r29, 0x14(r1)
    addi     r1, r1, 0x20
    mtlr     r0
    blr
}


asm void fn_8000D9CC(register s32 exception, register OSContext* context)
{
    nofralloc
    mflr     r0
    stw      r0, 4(r1)
    stwu     r1, -0x28(r1)
    stw      r31, 0x24(r1)
    stw      r30, 0x20(r1)
    stw      r29, 0x1c(r1)
    mr       r30, r4
    lis      r3, -0x3400
    lwz      r31, 0x3000(r3)
    rlwinm   r31, r31, 0, 0x10, 0xe
    cmplwi   r31, 0
    beq      L_d9cc_10
    addi     r3, r3, 0x3000
    lwz      r0, 4(r3)
    and      r0, r31, r0
    cmplwi   r0, 0
    bne      L_d9cc_18
L_d9cc_10:
    mr       r3, r30
    bl       OSLoadContext
L_d9cc_18:
    rlwinm   r0, r31, 0, 0x18, 0x18
    cmplwi   r0, 0
    li       r0, 0
    beq      L_9_da84
    lis      r3, -0x3400
    addi     r3, r3, 0x4000
    lhz      r4, 0x1e(r3)
    clrlwi   r3, r4, 0x1f
    cmplwi   r3, 0
    beq      L_9_da44
    oris     r0, r0, 0x8000
L_9_da44:
    rlwinm   r3, r4, 0, 0x1e, 0x1e
    cmplwi   r3, 0
    beq      L_9_da54
    oris     r0, r0, 0x4000
L_9_da54:
    rlwinm   r3, r4, 0, 0x1d, 0x1d
    cmplwi   r3, 0
    beq      L_9_da64
    oris     r0, r0, 0x2000
L_9_da64:
    rlwinm   r3, r4, 0, 0x1c, 0x1c
    cmplwi   r3, 0
    beq      L_9_da74
    oris     r0, r0, 0x1000
L_9_da74:
    rlwinm   r3, r4, 0, 0x1b, 0x1b
    cmplwi   r3, 0
    beq      L_9_da84
    oris     r0, r0, 0x800
L_9_da84:
    rlwinm   r3, r31, 0, 0x19, 0x19
    cmplwi   r3, 0
    beq      L_9_dacc
    lis      r3, -0x3400
    addi     r3, r3, 0x5000
    lhz      r4, 0xa(r3)
    rlwinm   r3, r4, 0, 0x1c, 0x1c
    cmplwi   r3, 0
    beq      L_9_daac
    oris     r0, r0, 0x400
L_9_daac:
    rlwinm   r3, r4, 0, 0x1a, 0x1a
    cmplwi   r3, 0
    beq      L_9_dabc
    oris     r0, r0, 0x200
L_9_dabc:
    rlwinm   r3, r4, 0, 0x18, 0x18
    cmplwi   r3, 0
    beq      L_9_dacc
    oris     r0, r0, 0x100
L_9_dacc:
    rlwinm   r3, r31, 0, 0x1a, 0x1a
    cmplwi   r3, 0
    beq      L_9_daf0
    lis      r3, -0x3400
    lwz      r3, 0x6c00(r3)
    rlwinm   r3, r3, 0, 0x1c, 0x1c
    cmplwi   r3, 0
    beq      L_9_daf0
    oris     r0, r0, 0x80
L_9_daf0:
    rlwinm   r3, r31, 0, 0x1b, 0x1b
    cmplwi   r3, 0
    beq      L_9_db9c
    lis      r3, -0x3400
    lwz      r4, 0x6800(r3)
    rlwinm   r3, r4, 0, 0x1e, 0x1e
    cmplwi   r3, 0
    beq      L_9_db14
    oris     r0, r0, 0x40
L_9_db14:
    rlwinm   r3, r4, 0, 0x1c, 0x1c
    cmplwi   r3, 0
    beq      L_9_db24
    oris     r0, r0, 0x20
L_9_db24:
    rlwinm   r3, r4, 0, 0x14, 0x14
    cmplwi   r3, 0
    beq      L_9_db34
    oris     r0, r0, 0x10
L_9_db34:
    lis      r3, -0x3400
    addi     r3, r3, 0x6800
    lwz      r4, 0x14(r3)
    rlwinm   r3, r4, 0, 0x1e, 0x1e
    cmplwi   r3, 0
    beq      L_9_db50
    oris     r0, r0, 8
L_9_db50:
    rlwinm   r3, r4, 0, 0x1c, 0x1c
    cmplwi   r3, 0
    beq      L_9_db60
    oris     r0, r0, 4
L_9_db60:
    rlwinm   r3, r4, 0, 0x14, 0x14
    cmplwi   r3, 0
    beq      L_9_db70
    oris     r0, r0, 2
L_9_db70:
    lis      r3, -0x3400
    addi     r3, r3, 0x6800
    lwz      r4, 0x28(r3)
    rlwinm   r3, r4, 0, 0x1e, 0x1e
    cmplwi   r3, 0
    beq      L_9_db8c
    oris     r0, r0, 1
L_9_db8c:
    rlwinm   r3, r4, 0, 0x1c, 0x1c
    cmplwi   r3, 0
    beq      L_9_db9c
    ori      r0, r0, 0x8000
L_9_db9c:
    rlwinm   r3, r31, 0, 0x12, 0x12
    cmplwi   r3, 0
    beq      L_9_dbac
    ori      r0, r0, 0x20
L_9_dbac:
    rlwinm   r3, r31, 0, 0x13, 0x13
    cmplwi   r3, 0
    beq      L_9_dbbc
    ori      r0, r0, 0x40
L_9_dbbc:
    rlwinm   r3, r31, 0, 0x15, 0x15
    cmplwi   r3, 0
    beq      L_9_dbcc
    ori      r0, r0, 0x1000
L_9_dbcc:
    rlwinm   r3, r31, 0, 0x16, 0x16
    cmplwi   r3, 0
    beq      L_9_dbdc
    ori      r0, r0, 0x2000
L_9_dbdc:
    rlwinm   r3, r31, 0, 0x17, 0x17
    cmplwi   r3, 0
    beq      L_9_dbec
    ori      r0, r0, 0x80
L_9_dbec:
    rlwinm   r3, r31, 0, 0x1c, 0x1c
    cmplwi   r3, 0
    beq      L_9_dbfc
    ori      r0, r0, 0x800
L_9_dbfc:
    rlwinm   r3, r31, 0, 0x1d, 0x1d
    cmplwi   r3, 0
    beq      L_9_dc0c
    ori      r0, r0, 0x400
L_9_dc0c:
    rlwinm   r3, r31, 0, 0x1e, 0x1e
    cmplwi   r3, 0
    beq      L_9_dc1c
    ori      r0, r0, 0x200
L_9_dc1c:
    rlwinm   r3, r31, 0, 0x14, 0x14
    cmplwi   r3, 0
    beq      L_9_dc2c
    ori      r0, r0, 0x4000
L_9_dc2c:
    rlwinm   r3, r31, 0, 0x1f, 0x1f
    cmplwi   r3, 0
    beq      L_9_dc3c
    ori      r0, r0, 0x100
L_9_dc3c:
L_pi_34b:
    lis      r3, -0x8000
    lwz      r4, 0xc4(r3)
    lwz      r3, 0xc8(r3)
    or       r3, r4, r3
    andc     r4, r0, r3
    cmplwi   r4, 0
    beq      L_exit9
    lis      r3, -0x7fee
    addi     r0, r3, 0x3a60
    mr       r3, r0
    b       L_9_dc64
    b       L_9_dc68
L_9_dc64:
    b       L_9_dc6c
L_9_dc68:
    b       L_9_dc6c
    b       L_9_dc6c
L_9_dc6c:
    lwz      r0, 0(r3)
    and      r0, r4, r0
    cmplwi   r0, 0
    beq      L_advance9
    cntlzw   r0, r0
    extsh    r29, r0
    b        L_found9
L_advance9:
    addi     r3, r3, 4
    b        L_9_dc6c

L_found9:
    lwz      r3, -0x7c18(r13)
    slwi     r0, r29, 2
    lwzx     r31, r3, r0
    cmplwi   r31, 0
    beq      L_exit9
    cmpwi    r29, 4
    ble      L_nostamp9
    sth      r29, -0x7c10(r13)
    bl       OSGetTime
    stw      r4, -0x7c04(r13)
    stw      r3, -0x7c08(r13)
    lwz      r0, 0x198(r30)
    stw      r0, -0x7c14(r13)
L_nostamp9:
    bl       OSDisableScheduler
    mr       r3, r29
    mr       r4, r30
    mr       r12, r31
    mtlr     r12
    blrl
    bl       OSEnableScheduler
    bl       __OSReschedule
L_exit9:
    mr       r3, r30
    bl       OSLoadContext
    lwz      r0, 0x2c(r1)
    lwz      r31, 0x24(r1)
    lwz      r30, 0x20(r1)
    lwz      r29, 0x1c(r1)
    addi     r1, r1, 0x28
    mtlr     r0
    blr
}

