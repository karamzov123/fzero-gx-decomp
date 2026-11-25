#include <dolphin/os.h>
#include <dolphin/base/PPCArch.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSError.h>
#pragma peephole off


void OSReport(const char *msg, ...);
void DBPrintf(char *format, ...);
OSErrorHandler OSSetErrorHandler(OSError code, OSErrorHandler handler);

/* Assembly in the original: the SDK's OSCache.c writes the cache, locked-cache and DMA
 * primitives as CodeWarrior asm functions (dcbi/dcbf/dcbst/icbi loops, HID0/HID2/DBAT and DMA SPR access,
 * no compiler frame); LCEnable and the L2/DMA-error code are C. */

#define OS_CACHED_REGION_PREFIX 0x8000
#define LC_BASE_PREFIX 0xE000
#define LC_LINES 512
#define CACHE_LINES 1024

asm void DCEnable(void) {
    nofralloc
    sync
    mfspr r3, HID0
    ori r3, r3, 0x4000
    mtspr HID0, r3
    blr
}

asm void DCInvalidateRange(register void *addr, register u32 nBytes) {
    nofralloc
    cmplwi nBytes, 0
    blelr
    clrlwi r5, addr, 27
    add nBytes, nBytes, r5
    addi nBytes, nBytes, 31
    srwi nBytes, nBytes, 5
    mtctr nBytes
@1
    dcbi r0, addr
    addi addr, addr, 32
    bdnz @1
    blr
}

asm void DCFlushRange(register void *addr, register u32 nBytes) {
    nofralloc
    cmplwi nBytes, 0
    blelr
    clrlwi r5, addr, 27
    add nBytes, nBytes, r5
    addi nBytes, nBytes, 31
    srwi nBytes, nBytes, 5
    mtctr nBytes
@1
    dcbf r0, addr
    addi addr, addr, 32
    bdnz @1
    sc
    blr
}

asm void DCStoreRange(register void *addr, register u32 nBytes) {
    nofralloc
    cmplwi nBytes, 0
    blelr
    clrlwi r5, addr, 27
    add nBytes, nBytes, r5
    addi nBytes, nBytes, 31
    srwi nBytes, nBytes, 5
    mtctr nBytes
@1
    dcbst r0, addr
    addi addr, addr, 32
    bdnz @1
    sc
    blr
}

asm void DCFlushRangeNoSync(register void *addr, register u32 nBytes) {
    nofralloc
    cmplwi nBytes, 0
    blelr
    clrlwi r5, addr, 27
    add nBytes, nBytes, r5
    addi nBytes, nBytes, 31
    srwi nBytes, nBytes, 5
    mtctr nBytes
@1
    dcbf r0, addr
    addi addr, addr, 32
    bdnz @1
    blr
}

asm void ICInvalidateRange(register void *addr, register u32 nBytes) {
    nofralloc
    cmplwi nBytes, 0
    blelr
    clrlwi r5, addr, 27
    add nBytes, nBytes, r5
    addi nBytes, nBytes, 31
    srwi nBytes, nBytes, 5
    mtctr nBytes
@1
    icbi r0, addr
    addi addr, addr, 32
    bdnz @1
    sync
    isync
    blr
}

asm void ICFlashInvalidate(void) {
    nofralloc
    mfspr r3, HID0
    ori r3, r3, 0x0800
    mtspr HID0, r3
    blr
}

asm void ICEnable(void) {
    nofralloc
    isync
    mfspr r3, HID0
    ori r3, r3, 0x8000
    mtspr HID0, r3
    blr
}

static asm void __LCEnable(void) {
    nofralloc
    mfmsr r5
    ori r5, r5, 0x1000
    mtmsr r5
    lis r3, OS_CACHED_REGION_PREFIX
    li r4, CACHE_LINES
    mtctr r4
_touchloop:
    dcbt 0, r3
    dcbst 0, r3
    addi r3, r3, 32
    bdnz _touchloop
    mfspr r4, HID2
    oris r4, r4, 0x100F
    mtspr HID2, r4
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    lis r3, LC_BASE_PREFIX
    ori r3, r3, 0x0002
    mtspr DBAT3L, r3
    ori r3, r3, 0x01fe
    mtspr DBAT3U, r3
    isync
    lis r3, LC_BASE_PREFIX
    li r6, LC_LINES
    mtctr r6
    li r6, 0
_lockloop:
    dcbz_l r6, r3
    addi r3, r3, 32
    bdnz _lockloop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    blr
}

void LCEnable(void) {
    BOOL enabled;

    enabled = OSDisableInterrupts();
    __LCEnable();
    OSRestoreInterrupts(enabled);
}

asm void LCDisable(void) {
    nofralloc
    lis r3, LC_BASE_PREFIX
    li r4, LC_LINES
    mtctr r4
@1
    dcbi r0, r3
    addi r3, r3, 32
    bdnz @1
    mfspr r4, HID2
    rlwinm r4, r4, 0, 4, 2
    mtspr HID2, r4
    blr
}

asm void LCLoadBlocks(register void *destTag, register void *srcAddr, register u32 numBlocks) {
    nofralloc
    rlwinm r6, numBlocks, 30, 27, 31
    rlwinm srcAddr, srcAddr, 0, 4, 31
    or r6, r6, srcAddr
    mtspr DMA_U, r6
    rlwinm r6, numBlocks, 2, 28, 29
    or r6, r6, destTag
    ori r6, r6, 0x12
    mtspr DMA_L, r6
    blr
}

asm void LCStoreBlocks(register void *destAddr, register void *srcTag, register u32 numBlocks) {
    nofralloc
    rlwinm r6, numBlocks, 30, 27, 31
    rlwinm destAddr, destAddr, 0, 4, 31
    or r6, r6, destAddr
    mtspr DMA_U, r6
    rlwinm r6, numBlocks, 2, 28, 29
    or r6, r6, srcTag
    ori r6, r6, 0x2
    mtspr DMA_L, r6
    blr
}

asm void fn_8000B8AC(register u32 len) {
    nofralloc
@1
    mfspr r4, HID2
    rlwinm r4, r4, 8, 28, 31
    cmpw r4, len
    bgt @1
    blr
}

static inline void L2Disable(void) {
    __sync();
    PPCMtl2cr(PPCMfl2cr() & ~0x80000000);
    __sync();
}

void L2GlobalInvalidate(void) {
    L2Disable();
    PPCMtl2cr(PPCMfl2cr() | 0x00200000);
    while (PPCMfl2cr() & 0x00000001u)
        ;
    PPCMtl2cr(PPCMfl2cr() & ~0x00200000);
    while (PPCMfl2cr() & 0x00000001u) {
        DBPrintf(">>> L2 INVALIDATE : SHOULD NEVER HAPPEN\n");
    }
}

void DMAErrorHandler(OSError error, OSContext *context, ...) {
    u32 hid2 = PPCMfhid2();
    OSReport("Machine check received\n");
    OSReport("HID2 = 0x%x   SRR1 = 0x%x\n", hid2, context->srr1);
    if (!(hid2 & ((1 << (31 - 8)) | (1 << (31 - 9)) | (1 << (31 - 10)) | (1 << (31 - 11)))) ||
        !(context->srr1 & 0x00200000)) {
        OSReport("Machine check was not DMA/locked cache related\n");
        OSDumpContext(context);
        PPCHalt();
    }
    OSReport("DMAErrorHandler(): An error occurred while processing DMA.\n");
    OSReport("The following errors have been detected and cleared :\n");
    if (hid2 & (1 << (31 - 8))) {
        OSReport("\t- Requested a locked cache tag that was already in the cache\n");
    }
    if (hid2 & (1 << (31 - 9))) {
        OSReport("\t- DMA attempted to access normal cache\n");
    }
    if (hid2 & (1 << (31 - 10))) {
        OSReport("\t- DMA missed in data cache\n");
    }
    if (hid2 & (1 << (31 - 11))) {
        OSReport("\t- DMA queue overflowed\n");
    }
    PPCMthid2(hid2);
}

static inline void L2Init(void) {
    u32 oldMSR;
    oldMSR = PPCMfmsr();
    __sync();
    PPCMtmsr((1 << (31 - 26)) | (1 << (31 - 27)));
    __sync();
    L2Disable();
    L2GlobalInvalidate();
    PPCMtmsr(oldMSR);
}

static inline void L2Enable(void) {
    PPCMtl2cr((PPCMfl2cr() | (1 << (31 - 0))) & ~(1 << (31 - 10)));
}

void __OSCacheInit() {
    if (!(PPCMfhid0() & (1 << (31 - 16)))) {
        ICEnable();
        DBPrintf("L1 i-caches initialized\n");
    }
    if (!(PPCMfhid0() & (1 << (31 - 17)))) {
        DCEnable();
        DBPrintf("L1 d-caches initialized\n");
    }
    if (!(PPCMfl2cr() & (1 << (31 - 0)))) {
        L2Init();
        L2Enable();
        DBPrintf("L2 cache initialized\n");
    }
    OSSetErrorHandler(1, DMAErrorHandler);
    DBPrintf("Locked cache machine check handler installed\n");
}
