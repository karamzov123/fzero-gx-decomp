#pragma push
#pragma force_active on

extern asm void OSGetArenaHi(void);
extern asm void OSSetArenaHi(void);
extern asm void OSGetArenaLo(void);
extern asm void OSSetArenaLo(void);
extern void __OSAllocFromHeap(void);
extern void __OSFreeToHeap(void);
extern void OSGetDefaultHeap(void);
extern void ModelDVD_OpenFile(void);
extern void fn_80071CE0(void);
extern void ModelDVD_ReadAsync(void);
extern void ModelDVD_CancelSync(void);
extern void fn_80071D2C(void);
extern void __OSAllocFromHeap(void);
extern void __OSFreeToHeap(void);
extern void OSGetDefaultHeap(void);
extern void ModelDVD_OpenFile(void);
extern void fn_80071CE0(void);
extern void ModelDVD_ReadAsync(void);
extern void ModelDVD_CancelSync(void);
extern void fn_80071D2C(void);

extern unsigned char lbl_801A6620[1];
extern unsigned char lbl_801A6D08[4];
extern unsigned char lbl_801A6D0C[4];

/* harvest: declarations carried over from the recovered
   candidate — the converted body below needs them. */
typedef struct { unsigned long a,b,c,d,e,f; } Hooks; extern unsigned long lbl_801A6D24,lbl_801A6D20,lbl_801A6D1C,lbl_801A6D18,lbl_801A6D14,lbl_801A6D10;
asm void OSAllocFromArena(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    addi	r3, r3, 0x1f
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    rlwinm	r30, r3, 0, 0, 0x1a
    lbz	r0, lbl_801A6620
    cmplwi	r0, 0
    beq	_80070d34
    bl      OSGetArenaHi
    subf	r31, r30, r3
    mr	r3, r31
    bl      OSSetArenaHi
    b	_80070d44
_80070d34:
    bl      OSGetArenaLo
    mr	r31, r3
    add	r3, r31, r30
    bl      OSSetArenaLo
_80070d44:
    lwz	r0, 0x14(r1)
    mr	r3, r31
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

// provenance: harvest:runs.sqlite — fn_80070D60 recovered from d60-struct1.c, compiled by hard2 at 2026-08-25T22:24 and scored 100 against main/dolphin/mtx/fn_80070CF8; original reference not recorded
void fn_80070D60(Hooks *h){lbl_801A6D24=h->a;lbl_801A6D20=h->b;lbl_801A6D1C=h->c;lbl_801A6D18=h->d;lbl_801A6D14=h->e;lbl_801A6D10=h->f;}

asm void fn_80070D94(void)
{
    nofralloc
    lis     r8, OSGetDefaultHeap@ha
    lis     r7, ModelDVD_OpenFile@ha
    lis     r6, fn_80071CE0@ha
    lis     r5, ModelDVD_ReadAsync@ha
    lis     r4, ModelDVD_CancelSync@ha
    lis     r3, fn_80071D2C@ha
    addi	r8, r8, OSGetDefaultHeap@l
    addi	r7, r7, ModelDVD_OpenFile@l
    addi	r6, r6, fn_80071CE0@l
    addi	r5, r5, ModelDVD_ReadAsync@l
    addi	r4, r4, ModelDVD_CancelSync@l
    addi	r0, r3, fn_80071D2C@l
    stw	r8, lbl_801A6D24
    stw	r7, lbl_801A6D20
    stw	r6, lbl_801A6D1C
    stw	r5, lbl_801A6D18
    stw	r4, lbl_801A6D14
    stw	r0, lbl_801A6D10
    blr	
}

asm void fn_80070DE0(void)
{
    nofralloc
    lwz	r0, lbl_801A6D0C
    stw	r3, lbl_801A6D0C
    mr	r3, r0
    blr	
}

asm void fn_80070DF0(void)
{
    nofralloc
    lwz	r0, lbl_801A6D08
    stw	r3, lbl_801A6D08
    mr	r3, r0
    blr	
}

asm void fn_80070E00(void)
{
    nofralloc
    lis     r4, __OSAllocFromHeap@ha
    lis     r3, __OSFreeToHeap@ha
    addi	r4, r4, __OSAllocFromHeap@l
    addi	r0, r3, __OSFreeToHeap@l
    stw	r4, lbl_801A6D0C
    stw	r0, lbl_801A6D08
    blr	
}

#pragma pop
