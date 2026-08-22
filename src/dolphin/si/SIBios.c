typedef int s32;
typedef unsigned int u32;
typedef void OSContext;

extern void OSRegisterVersion(const char* version);
extern void __OSSetInterruptHandler(s32 interrupt, void (*handler)(s32, OSContext*));
extern void __OSUnmaskInterrupts(u32 mask);
extern void SISetSamplingRate(s32 msec);
extern void SIGetType(s32 chan);
extern void SIInterruptHandler(s32 interrupt, OSContext* context);

extern u32 Packet[32];
extern u32 Si[5];

#pragma push
#pragma force_active on
asm void SIInit(void)
{
    nofralloc
    mflr r0
    lis r4, Packet@ha
    stw r0, 0x4(r1)
    stwu r1, -0x10(r1)
    stw r31, 0xc(r1)
    addi r31, r4, Packet@l
    lwz r3, -0x7F78(r13)
    bl OSRegisterVersion
    li r5, -1
    stw r5, 0x60(r31)
    lis r3, Si@ha
    addi r4, r3, Si@l
    stw r5, 0x40(r31)
    li r0, 0
    li r3, 0
    stw r5, 0x20(r31)
    stw r5, 0x0(r31)
    stw r0, 0x4(r4)
    bl SISetSamplingRate
    lis r3, 0xcc00
_loop:
    addi r4, r3, 0x6400
    lwzu r0, 0x34(r4)
    clrlwi. r0, r0, 31
    bne _loop
    lis r0, 0x8000
    lis r3, SIInterruptHandler@ha
    stw r0, 0x0(r4)
    addi r4, r3, SIInterruptHandler@l
    li r3, 0x14
    bl __OSSetInterruptHandler
    li r3, 0x800
    bl __OSUnmaskInterrupts
    li r3, 0x0
    bl SIGetType
    li r3, 0x1
    bl SIGetType
    li r3, 0x2
    bl SIGetType
    li r3, 0x3
    bl SIGetType
    lwz r0, 0x14(r1)
    lwz r31, 0xc(r1)
    addi r1, r1, 0x10
    mtlr r0
    blr
}
#pragma pop
