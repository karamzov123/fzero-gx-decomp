// MetroTRK NUB exception vector table (.init blob 0x800035E4-0x80005518).
// Layout per melee src/MetroTRK/__exception.s: banner + per-vector reserved
// slots whose trk_redirect/trk_tlb_redirect stubs live at slot+0xE4 and jump
// TRKInterruptHandler (0x8008B12C) via SRR0; System Reset slot branches to
// __TRK_reset (gTRKInterruptVectorTableEnd).
typedef unsigned char u8;

extern void gTRKInterruptVectorTableEnd(void);
extern void fn_80004538(void);

#pragma push
#pragma force_active on

// 0x800035E4: gTRKInterruptVectorTable - banner string
// "Metrowerks Target Resident Kernel for PowerPC" + word 0x43000000.
__declspec(section ".init") const u8 gTRKInterruptVectorTable[0x34] = {
0x4D, 0x65, 0x74, 0x72, 0x6F, 0x77, 0x65, 0x72,
0x6B, 0x73, 0x20, 0x54, 0x61, 0x72, 0x67, 0x65,
0x74, 0x20, 0x52, 0x65, 0x73, 0x69, 0x64, 0x65,
0x6E, 0x74, 0x20, 0x4B, 0x65, 0x72, 0x6E, 0x65,
0x6C, 0x20, 0x66, 0x6F, 0x72, 0x20, 0x50, 0x6F,
0x77, 0x65, 0x72, 0x50, 0x43, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
};

__declspec(section ".init") const u8 pad_80003614[0xCC] = { 0 };

asm __declspec(section ".init") void fn_800036E4(void)
{
    nofralloc
    b       gTRKInterruptVectorTableEnd
}

__declspec(section ".init") const u8 pad_800036E8[0xFC] = { 0 };

asm __declspec(section ".init") void fn_800037E4(void)
{
    nofralloc
    mtspr   0x111, r2
    mfspr   r2, 0x1a
    icbi    0, r2
    mfdar   r2
    dcbi    0, r2
    mfspr   r2, 0x111
    mtspr   0x111, r2
    mtspr   0x112, r3
    mtspr   0x113, r4
    mfspr   r2, 0x1a
    mfspr   r4, 0x1b
    mfmsr   r3
    ori     r3, r3, 0x30
    mtspr   0x1b, r3
    lis     r3, -0x7ff8
    ori     r3, r3, 0xb12c
    mtspr   0x1a, r3
    li      r3, 0x200
    rfi
}

__declspec(section ".init") const u8 pad_80003830[0xB4] = { 0 };

asm __declspec(section ".init") void fn_800038E4(void)
{
    nofralloc
    mtspr   0x111, r2
    mtspr   0x112, r3
    mtspr   0x113, r4
    mfspr   r2, 0x1a
    mfspr   r4, 0x1b
    mfmsr   r3
    ori     r3, r3, 0x30
    mtspr   0x1b, r3
    lis     r3, -0x7ff8
    ori     r3, r3, 0xb12c
    mtspr   0x1a, r3
    li      r3, 0x300
    rfi
}

__declspec(section ".init") const u8 pad_80003918[0xCC] = { 0 };

asm __declspec(section ".init") void fn_800039E4(void)
{
    nofralloc
    mtspr   0x111, r2
    mtspr   0x112, r3
    mtspr   0x113, r4
    mfspr   r2, 0x1a
    mfspr   r4, 0x1b
    mfmsr   r3
    ori     r3, r3, 0x30
    mtspr   0x1b, r3
    lis     r3, -0x7ff8
    ori     r3, r3, 0xb12c
    mtspr   0x1a, r3
    li      r3, 0x400
    rfi
}

__declspec(section ".init") const u8 pad_80003A18[0xCC] = { 0 };

asm __declspec(section ".init") void fn_80003AE4(void)
{
    nofralloc
    mtspr   0x111, r2
    mtspr   0x112, r3
    mtspr   0x113, r4
    mfspr   r2, 0x1a
    mfspr   r4, 0x1b
    mfmsr   r3
    ori     r3, r3, 0x30
    mtspr   0x1b, r3
    lis     r3, -0x7ff8
    ori     r3, r3, 0xb12c
    mtspr   0x1a, r3
    li      r3, 0x500
    rfi
}

__declspec(section ".init") const u8 pad_80003B18[0xCC] = { 0 };

asm __declspec(section ".init") void fn_80003BE4(void)
{
    nofralloc
    mtspr   0x111, r2
    mtspr   0x112, r3
    mtspr   0x113, r4
    mfspr   r2, 0x1a
    mfspr   r4, 0x1b
    mfmsr   r3
    ori     r3, r3, 0x30
    mtspr   0x1b, r3
    lis     r3, -0x7ff8
    ori     r3, r3, 0xb12c
    mtspr   0x1a, r3
    li      r3, 0x600
    rfi
}

__declspec(section ".init") const u8 pad_80003C18[0xCC] = { 0 };

asm __declspec(section ".init") void fn_80003CE4(void)
{
    nofralloc
    mtspr   0x111, r2
    mtspr   0x112, r3
    mtspr   0x113, r4
    mfspr   r2, 0x1a
    mfspr   r4, 0x1b
    mfmsr   r3
    ori     r3, r3, 0x30
    mtspr   0x1b, r3
    lis     r3, -0x7ff8
    ori     r3, r3, 0xb12c
    mtspr   0x1a, r3
    li      r3, 0x700
    rfi
}

__declspec(section ".init") const u8 pad_80003D18[0xCC] = { 0 };

asm __declspec(section ".init") void fn_80003DE4(void)
{
    nofralloc
    mtspr   0x111, r2
    mtspr   0x112, r3
    mtspr   0x113, r4
    mfspr   r2, 0x1a
    mfspr   r4, 0x1b
    mfmsr   r3
    ori     r3, r3, 0x30
    mtspr   0x1b, r3
    lis     r3, -0x7ff8
    ori     r3, r3, 0xb12c
    mtspr   0x1a, r3
    li      r3, 0x800
    rfi
}

__declspec(section ".init") const u8 pad_80003E18[0xCC] = { 0 };

asm __declspec(section ".init") void fn_80003EE4(void)
{
    nofralloc
    mtspr   0x111, r2
    mtspr   0x112, r3
    mtspr   0x113, r4
    mfspr   r2, 0x1a
    mfspr   r4, 0x1b
    mfmsr   r3
    ori     r3, r3, 0x30
    mtspr   0x1b, r3
    lis     r3, -0x7ff8
    ori     r3, r3, 0xb12c
    mtspr   0x1a, r3
    li      r3, 0x900
    rfi
}

__declspec(section ".init") const u8 pad_80003F18[0x2CC] = { 0 };

asm __declspec(section ".init") void fn_800041E4(void)
{
    nofralloc
    mtspr   0x111, r2
    mtspr   0x112, r3
    mtspr   0x113, r4
    mfspr   r2, 0x1a
    mfspr   r4, 0x1b
    mfmsr   r3
    ori     r3, r3, 0x30
    mtspr   0x1b, r3
    lis     r3, -0x7ff8
    ori     r3, r3, 0xb12c
    mtspr   0x1a, r3
    li      r3, 0xc00
    rfi
}

__declspec(section ".init") const u8 pad_80004218[0xCC] = { 0 };

asm __declspec(section ".init") void fn_800042E4(void)
{
    nofralloc
    mtspr   0x111, r2
    mtspr   0x112, r3
    mtspr   0x113, r4
    mfspr   r2, 0x1a
    mfspr   r4, 0x1b
    mfmsr   r3
    ori     r3, r3, 0x30
    mtspr   0x1b, r3
    lis     r3, -0x7ff8
    ori     r3, r3, 0xb12c
    mtspr   0x1a, r3
    li      r3, 0xd00
    rfi
}

__declspec(section ".init") const u8 pad_80004318[0xCC] = { 0 };

asm __declspec(section ".init") void fn_800043E4(void)
{
    nofralloc
    mtspr   0x111, r2
    mtspr   0x112, r3
    mtspr   0x113, r4
    mfspr   r2, 0x1a
    mfspr   r4, 0x1b
    mfmsr   r3
    ori     r3, r3, 0x30
    mtspr   0x1b, r3
    lis     r3, -0x7ff8
    ori     r3, r3, 0xb12c
    mtspr   0x1a, r3
    li      r3, 0xe00
    rfi
}

__declspec(section ".init") const u8 pad_80004418[0xCC] = { 0 };

asm __declspec(section ".init") void fn_800044E4(void)
{
    nofralloc
    b       fn_80004538
}

__declspec(section ".init") const u8 pad_800044E8[0x1C] = { 0 };

asm __declspec(section ".init") void fn_80004504(void)
{
    nofralloc
    mtspr   0x111, r2
    mtspr   0x112, r3
    mtspr   0x113, r4
    mfspr   r2, 0x1a
    mfspr   r4, 0x1b
    mfmsr   r3
    ori     r3, r3, 0x30
    mtspr   0x1b, r3
    lis     r3, -0x7ff8
    ori     r3, r3, 0xb12c
    mtspr   0x1a, r3
    li      r3, 0xf20
    rfi
}

asm __declspec(section ".init") void fn_80004538(void)
{
    nofralloc
    mtspr   0x111, r2
    mtspr   0x112, r3
    mtspr   0x113, r4
    mfspr   r2, 0x1a
    mfspr   r4, 0x1b
    mfmsr   r3
    ori     r3, r3, 0x30
    mtspr   0x1b, r3
    lis     r3, -0x7ff8
    ori     r3, r3, 0xb12c
    mtspr   0x1a, r3
    li      r3, 0xf00
    rfi
}

__declspec(section ".init") const u8 pad_8000456C[0x78] = { 0 };

asm __declspec(section ".init") void fn_800045E4(void)
{
    nofralloc
    mtspr   0x111, r2
    mfcr    r2
    mtspr   0x112, r2
    mfmsr   r2
    andis.  r2, r2, 2
    beq     lbl_800045E4
    mfmsr   r2
    xoris   r2, r2, 2
    sync
    mtmsr   r2
    sync
    mtspr   0x111, r2
lbl_800045E4:
    mfspr   r2, 0x112
    mtcrf   0xff, r2
    mfspr   r2, 0x111
    mtspr   0x111, r2
    mtspr   0x112, r3
    mtspr   0x113, r4
    mfspr   r2, 0x1a
    mfspr   r4, 0x1b
    mfmsr   r3
    ori     r3, r3, 0x30
    mtspr   0x1b, r3
    lis     r3, -0x7ff8
    ori     r3, r3, 0xb12c
    mtspr   0x1a, r3
    li      r3, 0x1000
    rfi
}

__declspec(section ".init") const u8 pad_80004654[0x90] = { 0 };

asm __declspec(section ".init") void fn_800046E4(void)
{
    nofralloc
    mtspr   0x111, r2
    mfcr    r2
    mtspr   0x112, r2
    mfmsr   r2
    andis.  r2, r2, 2
    beq     lbl_800046E4
    mfmsr   r2
    xoris   r2, r2, 2
    sync
    mtmsr   r2
    sync
    mtspr   0x111, r2
lbl_800046E4:
    mfspr   r2, 0x112
    mtcrf   0xff, r2
    mfspr   r2, 0x111
    mtspr   0x111, r2
    mtspr   0x112, r3
    mtspr   0x113, r4
    mfspr   r2, 0x1a
    mfspr   r4, 0x1b
    mfmsr   r3
    ori     r3, r3, 0x30
    mtspr   0x1b, r3
    lis     r3, -0x7ff8
    ori     r3, r3, 0xb12c
    mtspr   0x1a, r3
    li      r3, 0x1100
    rfi
}

__declspec(section ".init") const u8 pad_80004754[0x90] = { 0 };

asm __declspec(section ".init") void fn_800047E4(void)
{
    nofralloc
    mtspr   0x111, r2
    mfcr    r2
    mtspr   0x112, r2
    mfmsr   r2
    andis.  r2, r2, 2
    beq     lbl_800047E4
    mfmsr   r2
    xoris   r2, r2, 2
    sync
    mtmsr   r2
    sync
    mtspr   0x111, r2
lbl_800047E4:
    mfspr   r2, 0x112
    mtcrf   0xff, r2
    mfspr   r2, 0x111
    mtspr   0x111, r2
    mtspr   0x112, r3
    mtspr   0x113, r4
    mfspr   r2, 0x1a
    mfspr   r4, 0x1b
    mfmsr   r3
    ori     r3, r3, 0x30
    mtspr   0x1b, r3
    lis     r3, -0x7ff8
    ori     r3, r3, 0xb12c
    mtspr   0x1a, r3
    li      r3, 0x1200
    rfi
}

__declspec(section ".init") const u8 pad_80004854[0x90] = { 0 };

asm __declspec(section ".init") void fn_800048E4(void)
{
    nofralloc
    mtspr   0x111, r2
    mtspr   0x112, r3
    mtspr   0x113, r4
    mfspr   r2, 0x1a
    mfspr   r4, 0x1b
    mfmsr   r3
    ori     r3, r3, 0x30
    mtspr   0x1b, r3
    lis     r3, -0x7ff8
    ori     r3, r3, 0xb12c
    mtspr   0x1a, r3
    li      r3, 0x1300
    rfi
}

__declspec(section ".init") const u8 pad_80004918[0xCC] = { 0 };

asm __declspec(section ".init") void fn_800049E4(void)
{
    nofralloc
    mtspr   0x111, r2
    mtspr   0x112, r3
    mtspr   0x113, r4
    mfspr   r2, 0x1a
    mfspr   r4, 0x1b
    mfmsr   r3
    ori     r3, r3, 0x30
    mtspr   0x1b, r3
    lis     r3, -0x7ff8
    ori     r3, r3, 0xb12c
    mtspr   0x1a, r3
    li      r3, 0x1400
    rfi
}

__declspec(section ".init") const u8 pad_80004A18[0x1CC] = { 0 };

asm __declspec(section ".init") void fn_80004BE4(void)
{
    nofralloc
    mtspr   0x111, r2
    mtspr   0x112, r3
    mtspr   0x113, r4
    mfspr   r2, 0x1a
    mfspr   r4, 0x1b
    mfmsr   r3
    ori     r3, r3, 0x30
    mtspr   0x1b, r3
    lis     r3, -0x7ff8
    ori     r3, r3, 0xb12c
    mtspr   0x1a, r3
    li      r3, 0x1600
    rfi
}

__declspec(section ".init") const u8 pad_80004C18[0xCC] = { 0 };

asm __declspec(section ".init") void fn_80004CE4(void)
{
    nofralloc
    mtspr   0x111, r2
    mtspr   0x112, r3
    mtspr   0x113, r4
    mfspr   r2, 0x1a
    mfspr   r4, 0x1b
    mfmsr   r3
    ori     r3, r3, 0x30
    mtspr   0x1b, r3
    lis     r3, -0x7ff8
    ori     r3, r3, 0xb12c
    mtspr   0x1a, r3
    li      r3, 0x1700
    rfi
}

__declspec(section ".init") const u8 pad_80004D18[0x4CC] = { 0 };

asm __declspec(section ".init") void fn_800051E4(void)
{
    nofralloc
    mtspr   0x111, r2
    mtspr   0x112, r3
    mtspr   0x113, r4
    mfspr   r2, 0x1a
    mfspr   r4, 0x1b
    mfmsr   r3
    ori     r3, r3, 0x30
    mtspr   0x1b, r3
    lis     r3, -0x7ff8
    ori     r3, r3, 0xb12c
    mtspr   0x1a, r3
    li      r3, 0x1c00
    rfi
}

__declspec(section ".init") const u8 pad_80005218[0xCC] = { 0 };

asm __declspec(section ".init") void fn_800052E4(void)
{
    nofralloc
    mtspr   0x111, r2
    mtspr   0x112, r3
    mtspr   0x113, r4
    mfspr   r2, 0x1a
    mfspr   r4, 0x1b
    mfmsr   r3
    ori     r3, r3, 0x30
    mtspr   0x1b, r3
    lis     r3, -0x7ff8
    ori     r3, r3, 0xb12c
    mtspr   0x1a, r3
    li      r3, 0x1d00
    rfi
}

__declspec(section ".init") const u8 pad_80005318[0xCC] = { 0 };

asm __declspec(section ".init") void fn_800053E4(void)
{
    nofralloc
    mtspr   0x111, r2
    mtspr   0x112, r3
    mtspr   0x113, r4
    mfspr   r2, 0x1a
    mfspr   r4, 0x1b
    mfmsr   r3
    ori     r3, r3, 0x30
    mtspr   0x1b, r3
    lis     r3, -0x7ff8
    ori     r3, r3, 0xb12c
    mtspr   0x1a, r3
    li      r3, 0x1e00
    rfi
}

__declspec(section ".init") const u8 pad_80005418[0xCC] = { 0 };

asm __declspec(section ".init") void fn_800054E4(void)
{
    nofralloc
    mtspr   0x111, r2
    mtspr   0x112, r3
    mtspr   0x113, r4
    mfspr   r2, 0x1a
    mfspr   r4, 0x1b
    mfmsr   r3
    ori     r3, r3, 0x30
    mtspr   0x1b, r3
    lis     r3, -0x7ff8
    ori     r3, r3, 0xb12c
    mtspr   0x1a, r3
    li      r3, 0x1f00
    rfi
}

#pragma pop
