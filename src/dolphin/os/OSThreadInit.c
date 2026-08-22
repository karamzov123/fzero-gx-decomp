typedef void OSThreadQueue;

typedef unsigned int u32;

extern void OSInitThreadQueue(OSThreadQueue *queue);
extern void OSClearContext(register void* context);
extern void OSSetCurrentContext(register void* context);
extern void OSClearStack(register u32 clearValue);
extern void fn_80011360(register int);

typedef unsigned int u32;

asm void __OSThreadInit(void)
{
    nofralloc
    mflr    r0
    lis     r3, 0x8016
    stw     r0, 4(r1)
    li      r0, 2
    li      r4, 0x10
    stwu    r1, -0x18(r1)
    stw     r31, 0x14(r1)
    stw     r30, 0x10(r1)
    stw     r29, 0xc(r1)
    li      r29, 0
    stw     r28, 8(r1)
    addi    r28, r3, -0x3fe8
    addi    r31, r28, 0x418
    sth     r0, 0x6e0(r28)
    li      r0, 1
    addi    r3, r31, 0x2e8
    sth     r0, 0x6e2(r28)
    li      r0, -1
    stw     r4, 0x6ec(r28)
    stw     r4, 0x6e8(r28)
    stw     r29, 0x6e4(r28)
    stw     r0, 0x6f0(r28)
    stw     r29, 0x708(r28)
    bl      OSInitThreadQueue
    stw     r29, 0x710(r28)
    lis     r30, 0x8000
    addi    r3, r31, 0
    stw     r29, 0x70c(r28)
    stw     r31, 0xd8(r30)
    bl      OSClearContext
    mr      r3, r31
    bl      OSSetCurrentContext
    lis     r3, 0x801b
    addi    r0, r3, 0x7930
    lis     r3, 0x801a
    stw     r0, 0x71c(r28)
    addi    r0, r3, 0x792c
    stw     r0, 0x720(r28)
    lis     r3, 0xdeae
    addi    r0, r3, -0x4542
    lwz     r3, 0x720(r28)
    mr      r4, r31
    stw     r0, 0(r3)
    lwz     r12, -0x7f80(r13)
    lwz     r3, 0xe4(r30)
    mtlr    r12
    blrl
    stw     r31, 0xe4(r30)
    li      r3, 0
    bl      OSClearStack
    stw     r29, -0x7bc8(r13)
    li      r30, 0
    slwi    r0, r30, 3
    stw     r29, -0x7bc4(r13)
    add     r29, r28, r0
_80010220:
    mr      r3, r29
    bl      OSInitThreadQueue
    addi    r30, r30, 1
    cmpwi   r30, 0x1f
    addi    r29, r29, 8
    ble     _80010220
    lis     r30, 0x8000
    addi    r3, r30, 0xdc
    bl      OSInitThreadQueue
    addi    r4, r30, 0xdc
    lwzu    r3, 4(r4)
    cmplwi  r3, 0
    bne     _8001025c
    stw     r31, 0xdc(r30)
    b       _80010260
_8001025c:
    stw     r31, 0x2fc(r3)
_80010260:
    stw     r3, 0x300(r31)
    li      r30, 0
    addi    r3, r28, 0x730
    stw     r30, 0x2fc(r31)
    stw     r31, 0(r4)
    bl      OSClearContext
    stw     r30, -0x7bc0(r13)
    lwz     r0, 0x1c(r1)
    lwz     r31, 0x14(r1)
    lwz     r30, 0x10(r1)
    lwz     r29, 0xc(r1)
    lwz     r28, 8(r1)
    addi    r1, r1, 0x18
    mtlr    r0
    blr
}
