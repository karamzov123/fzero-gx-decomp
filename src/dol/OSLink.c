#include "types.h"
#include <dolphin/os.h>
#include <dolphin/os/OSModule.h>
#include "sdk_addresses.h"
#include <dolphin/types.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSError.h>
#include <dolphin/os/OSInterrupt.h>


/* --- dol/OSLink.c --- */
extern u32 Link(u32, u32, u32);

void OSLink(u32 arg0, u32 arg1) {
    Link(arg0, arg1, 0);
}

/* --- dol/OSLinkFixed.c --- */
struct OSLinkFixed_Arg0 {
    u8 pad_0[0x1C];
    u32 unk_1C;
};


u32 OSLinkFixed(struct OSLinkFixed_Arg0 *arg0, u32 arg1) {
    u32 v0;
    u32 t0;
    v0 = (u32)arg0;
    if (arg0->unk_1C > 3 || arg0->unk_1C < 3) {
    v0 = 0;
    } else {
    t0 = Link(v0, arg1, 1);
    v0 = t0;
    }
    return v0;
}

/* --- dol/Undo.c --- */
void OSReport(const char *msg, ...);

BOOL Undo(OSModuleHeader *newModule, OSModuleHeader *module) {
    OSModuleID idNew;
    OSImportInfo *imp;
    OSRel *rel;
    OSSectionInfo *si;
    OSSectionInfo *siFlush;
    u32 *p;
    u32 offset;
    u32 x;
    idNew = newModule->info.id;
    for (imp = (OSImportInfo *)module->impOffset;
         imp < (OSImportInfo *)(module->impOffset + module->impSize); imp++) {
        if (imp->id == idNew) {
            goto Found; // fzgx-allow: S1 SDK error cleanup path
        }
    }
    return 0;
Found:
    siFlush = 0;
    for (rel = (OSRel *)imp->offset; rel->type != 203; rel++) {
        (u8 *)p += rel->offset;
        si = &((OSSectionInfo *)(((OSModuleInfo *)(newModule))->sectionInfoOffset))[rel->section];
        offset = ((si->offset) & ~0x1);
        x = 0;
        switch (rel->type) {
        case 0:
            break;
        case 1:
            *p = x;
            break;
        case 2:
            *p = (*p & ~0x03fffffc) | (x & 0x03fffffc);
            break;
        case 3:
            *(u16 *)p = (u16)(x & 0xffff);
            break;
        case 4:
            *(u16 *)p = (u16)(x & 0xffff);
            break;
        case 5:
            *(u16 *)p = (u16)(((x >> 16) & 0xffff));
            break;
        case 6:
            *(u16 *)p = (u16)(((x >> 16) + ((x & 0x8000) ? 1 : 0)) & 0xffff);
            break;
        case 7:
        case 8:
        case 9:
            *p = (*p & ~0x0000fffc) | (x & 0x0000fffc);
            break;
        case 10:
            if (module->unresolvedSection != 0) {
                x = (u32)module->unresolved - (u32)p;
            }
            *p = (*p & ~0x03fffffc) | (x & 0x03fffffc);
            break;
        case 11:
        case 12:
        case 13:
            *p = (*p & ~0x0000fffc) | (x & 0x0000fffc);
            break;
        case 201:
            break;
        case 202:
            si = &((OSSectionInfo *)(((OSModuleInfo *)(module))->sectionInfoOffset))[rel->section];
            p = (u32 *)((si->offset) & ~0x1);
            if (siFlush) {
                offset = ((siFlush->offset) & ~0x1);
                DCFlushRange((void *)offset, siFlush->size);
                ICInvalidateRange((void *)offset, siFlush->size);
            }
            siFlush = (si->offset & 0x1) ? si : 0;
            break;
        default:
            OSReport("OSUnlink: unknown relocation type %3d\n", rel->type);
            break;
        }
    }
    if (siFlush) {
        offset = ((siFlush->offset) & ~0x1);
        DCFlushRange((void *)offset, siFlush->size);
        ICInvalidateRange((void *)offset, siFlush->size);
    }
    return 1;
}

/* --- dol/OSUnlink.c --- */
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
