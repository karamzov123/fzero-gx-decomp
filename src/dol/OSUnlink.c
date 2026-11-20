#include <dolphin/os.h>
#include <dolphin/os/OSModule.h>
#include "sdk_addresses.h"
#include "types.h"
#include <dolphin/types.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSError.h>
#include <dolphin/os/OSInterrupt.h>


/* --- dol/OSUnlink.c --- */
/* --- dol/OSUnlink.c --- */
void fn_8000DD64(OSModuleInfo *module);

OSModuleQueue __OSModuleInfoList : FZGX_ADDR___OSModuleInfoList;

const void *__OSStringTable : FZGX_ADDR___OSStringTable;

BOOL Undo(OSModuleHeader *newModule, OSModuleHeader *module);

BOOL OSUnlink(OSModuleInfo *oldModule) {
    OSModuleHeader *moduleHeader;
    OSModuleInfo *moduleInfo;
    u32 i;
    OSSectionInfo *si;
    OSImportInfo *imp;
    moduleHeader = (OSModuleHeader *)oldModule;
    do {
        OSModuleInfo *__next;
        OSModuleInfo *__prev;
        __next = (oldModule)->link.next;
        __prev = (oldModule)->link.prev;
        if (__next == ((void *)0))
            (&__OSModuleInfoList)->tail = __prev;
        else
            __next->link.prev = __prev;
        if (__prev == ((void *)0))
            (&__OSModuleInfoList)->head = __next;
        else
            __prev->link.next = __next;
    } while (0);
    for (moduleInfo = __OSModuleInfoList.head; moduleInfo; moduleInfo = moduleInfo->link.next) {
        Undo(moduleHeader, (OSModuleHeader *)moduleInfo);
    }
    fn_8000DD64(oldModule);
    if (__OSStringTable) {
        oldModule->nameOffset -= (u32)__OSStringTable;
    }
    if (moduleHeader->prologSection != 0) {
        moduleHeader->prolog -=
            ((((OSSectionInfo *)(((OSModuleInfo *)(oldModule))
                                     ->sectionInfoOffset))[moduleHeader->prologSection]
                  .offset) &
             ~0x1);
    }
    if (moduleHeader->epilogSection != 0) {
        moduleHeader->epilog -=
            ((((OSSectionInfo *)(((OSModuleInfo *)(oldModule))
                                     ->sectionInfoOffset))[moduleHeader->epilogSection]
                  .offset) &
             ~0x1);
    }
    if (moduleHeader->unresolvedSection != 0) {
        moduleHeader->unresolved -=
            ((((OSSectionInfo *)(((OSModuleInfo *)(oldModule))
                                     ->sectionInfoOffset))[moduleHeader->unresolvedSection]
                  .offset) &
             ~0x1);
    }
    for (imp = (OSImportInfo *)moduleHeader->impOffset;
         imp < (OSImportInfo *)(moduleHeader->impOffset + moduleHeader->impSize); imp++) {
        imp->offset -= (u32)moduleHeader;
    }
    for (i = 1; i < oldModule->numSections; i++) {
        si = &((OSSectionInfo *)(((OSModuleInfo *)(oldModule))->sectionInfoOffset))[i];
        if (i == moduleHeader->bssSection) {
            moduleHeader->bssSection = 0;
            si->offset = 0;
        } else if (si->offset != 0) {
            si->offset -= (u32)moduleHeader;
        }
    }
    moduleHeader->relOffset -= (u32)moduleHeader;
    moduleHeader->impOffset -= (u32)moduleHeader;
    oldModule->sectionInfoOffset -= (u32)moduleHeader;
    return 1;
}

/* --- dol/__OSModuleInit.c --- */
void __OSModuleInit(void) {
    __OSModuleInfoList.head = __OSModuleInfoList.tail = 0;
    __OSStringTable = 0;
}

/* --- dol/fn_8000E794.c --- */
/* --- dol/fn_8000E794.c --- */
u32 fn_8000E794(void) {
    return *(u32 *)0x80000028;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
}

/* --- dol/fn_8000E7A0.c --- */
u32 fn_8000E7A0(void) {
    return *(u32 *)0x800000F0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
}

/* --- dol/OnReset.c --- */
/* --- dol/OnReset.c --- */
vu16 __MEMRegs[64] : FZGX_ADDR___MEMRegs;

BOOL OnReset(BOOL final) {
    if (final != 0) {
        __MEMRegs[8] = 0xFF;
        __OSMaskInterrupts(0xf0000000);
    }
    return 1;
}

/* --- dol/MEMIntrruptHandler.c --- */
extern OSErrorHandler __OSErrorTable[(16 + 1)];


void MEMIntrruptHandler(__OSInterrupt interrupt, OSContext *context) {
    u32 addr;
    u32 cause;
    cause = __MEMRegs[0xf];
    addr = (((u32)__MEMRegs[0x12] & 0x3ff) << 16) | __MEMRegs[0x11];
    __MEMRegs[0x10] = 0;
    if (__OSErrorTable[15]) {
        __OSErrorTable[15](15, context, cause, addr);
        return;
    }
    __OSUnhandledException(15, context, cause, addr);
}
