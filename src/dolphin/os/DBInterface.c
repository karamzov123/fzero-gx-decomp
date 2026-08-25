typedef int BOOL;
#define TRUE 1
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct OSContext OSContext;

extern void OSReport(const char* msg, ...);
extern char db_exception_destination_str[];
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
    OSReport(db_exception_destination_str);
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

// provenance: dolsdk2001:src/db/db.c:66 — retail body is the MWCC empty-variadic spill prologue
void DBPrintf(char* msg, ...)
{
}
#pragma pop
