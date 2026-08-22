typedef int BOOL;
#define TRUE 1
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct OSContext OSContext;

extern void OSReport(const char* msg, ...);
extern char lbl_80123E10[];
extern void OSDumpContext(OSContext* context);
extern void PPCHalt(void);

#define OSPhysicalToCached(paddr) ((void*)((u32)(paddr) + 0x80000000))
#define OSCachedToPhysical(caddr) ((void*)((u32)(caddr) - 0x80000000))

struct DBInterface {
    u32 pad;
    u32 exceptionMask;
    void* ExceptionDestination;
};

void __DBExceptionDestination(void);

extern struct DBInterface* __DBInterface;
extern BOOL DBVerbose;

void DBInit(void)
{
    struct DBInterface* dbi;

    dbi = (struct DBInterface*)OSPhysicalToCached(0x40);
    __DBInterface = dbi;
    dbi->ExceptionDestination = OSCachedToPhysical(__DBExceptionDestination);
    DBVerbose = TRUE;
}

#pragma push
#pragma force_active on
static void __DBExceptionDestinationAux(void)
{
    u32* contextAddr;
    OSContext* context;

    contextAddr = (void*)0xC0;
    context = OSPhysicalToCached(*contextAddr);
    OSReport(lbl_80123E10);
    OSDumpContext(context);
    PPCHalt();
}

asm void __DBExceptionDestination(void)
{
    nofralloc
    mfmsr   r3
    ori     r3, r3, 0x30
    mtmsr   r3
    b       __DBExceptionDestinationAux
}

BOOL __DBIsExceptionMarked(u8 exception)
{
    u32 mask = (1 << exception);
    return __DBInterface->exceptionMask & mask;
}

asm void DBPrintf(void)
{
    nofralloc
    stwu    r1, -0x70(r1)
    bne     cr1, lbl_80015AFC
    stfd    f1, 0x28(r1)
    stfd    f2, 0x30(r1)
    stfd    f3, 0x38(r1)
    stfd    f4, 0x40(r1)
    stfd    f5, 0x48(r1)
    stfd    f6, 0x50(r1)
    stfd    f7, 0x58(r1)
    stfd    f8, 0x60(r1)
lbl_80015AFC:
    stw     r3, 0x8(r1)
    stw     r4, 0xc(r1)
    stw     r5, 0x10(r1)
    stw     r6, 0x14(r1)
    stw     r7, 0x18(r1)
    stw     r8, 0x1c(r1)
    stw     r9, 0x20(r1)
    stw     r10, 0x24(r1)
    addi    r1, r1, 0x70
    blr
}
#pragma pop
