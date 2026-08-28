typedef signed int s32;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef volatile u16 vu16;

extern s32 OSDisableInterrupts(void);
extern s32 OSRestoreInterrupts(s32 level);
extern unsigned char jumptable_801243BC[108];
extern unsigned char lbl_801241C8[500];

#pragma push
#pragma force_active on

extern unsigned char lbl_801A6934[4];
extern unsigned char lbl_801A6938[4];
// provenance: original
// harvested 2026-08-27 from natc1's logged 100% attempt; spliced into the current head
s32 fn_8001A78C(register s32 mode)
{
    s32 prev = *(s32*)lbl_801A6934;
    s32 level = OSDisableInterrupts();
    *(s32*)lbl_801A6934 = mode;
    OSRestoreInterrupts(level);
    return prev;
}

// provenance: original (recovered 100% C body from natc1's logged attempt,
//   submissions/.rejected/natc1/vifuncs-swaps-1/vifuncs.c:28; identical IRQ-save
//   envelope to fn_8001A78C, stores r3 to lbl_801A6938 and returns prior value)
s32 fn_8001A7D0(register s32 ntsc)
{
    s32 prev = *(s32*)lbl_801A6938;
    s32 level = OSDisableInterrupts();
    *(s32*)lbl_801A6938 = ntsc;
    OSRestoreInterrupts(level);
    return prev;
}

asm void* fn_8001A814(register s32 mode)
{
    nofralloc
    cmplwi  r3, 0x1a
    lis     r4, lbl_801241C8@ha
    addi    r5, r4, lbl_801241C8@l /* lbl_801241C8 */
    bgt     _8001a8b0
    lis     r4, jumptable_801243BC@ha
    addi    r4, r4, jumptable_801243BC@l
    slwi    r0, r3, 2
    lwzx    r0, r4, r0
    mtctr   r0
    bctr
    addi    r3, r5, 0x44
    blr
    addi    r3, r5, 0x6a
    blr
    addi    r3, r5, 0x90
    blr
    addi    r3, r5, 0xb6
    blr
    addi    r3, r5, 0x44
    blr
    addi    r3, r5, 0x6a
    blr
    addi    r3, r5, 0xdc
    blr
    addi    r3, r5, 0x102
    blr
_8001a8ac:
    addi    r3, r5, 0x128
    blr
    addi    r3, r5, 0x14e
    blr
    addi    r3, r5, 0x90
    blr
    addi    r3, r5, 0xb6
    blr
    addi    r3, r5, 0x174
    blr
    addi    r3, r5, 0x19a
    blr
_8001a8b0:
    li      r3, 0
    blr
}

#pragma pop
