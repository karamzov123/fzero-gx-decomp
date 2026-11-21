#include "types.h"
#include <dolphin/os.h>
#include <dolphin/os/OSModule.h>
#include "sdk_addresses.h"

void *__OSStringTable : FZGX_ADDR___OSStringTable;
OSModuleQueue __OSModuleInfoList : FZGX_ADDR___OSModuleInfoList;

void OSReport(const char *msg, ...);
void *memset(void *dest, int val, size_t count);
void DCFlushRange(void *addr, u32 nBytes);
void ICInvalidateRange(void *addr, u32 nBytes);

void fn_8000DD60(OSModuleInfo *module) {
    (void)module;
}

void fn_8000DD64(OSModuleInfo *module) {
    (void)module;
}

void fn_8000DD68(u32 arg0) {
    *(u32 *)0x800030D0 = arg0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
}

BOOL Relocate(OSModuleHeader *newModule, OSModuleHeader *module) {
    OSModuleID idNew;
    OSImportInfo *imp;
    OSRel *rel;
    OSSectionInfo *si;
    OSSectionInfo *siFlush;
    u32 *p;
    u32 offset;
    u32 x;
    idNew = newModule ? newModule->info.id : 0;
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
        if (idNew) {
            si = &(
                (OSSectionInfo *)(((OSModuleInfo *)(newModule))->sectionInfoOffset))[rel->section];
            offset = ((si->offset) & ~0x1);
        } else {
            offset = 0;
        }
        switch (rel->type) {
        case 0:
            break;
        case 1:
            x = offset + rel->addend;
            *p = x;
            break;
        case 2:
            x = offset + rel->addend;
            *p = (*p & ~0x03fffffc) | (x & 0x03fffffc);
            break;
        case 3:
            x = offset + rel->addend;
            *(u16 *)p = (u16)(x & 0xffff);
            break;
        case 4:
            x = offset + rel->addend;
            *(u16 *)p = (u16)(x & 0xffff);
            break;
        case 5:
            x = offset + rel->addend;
            *(u16 *)p = (u16)(((x >> 16) & 0xffff));
            break;
        case 6:
            x = offset + rel->addend;
            *(u16 *)p = (u16)(((x >> 16) + ((x & 0x8000) ? 1 : 0)) & 0xffff);
            break;
        case 7:
        case 8:
        case 9:
            x = offset + rel->addend;
            *p = (*p & ~0x0000fffc) | (x & 0x0000fffc);
            break;
        case 10:
            x = offset + rel->addend - (u32)p;
            *p = (*p & ~0x03fffffc) | (x & 0x03fffffc);
            break;
        case 11:
        case 12:
        case 13:
            x = offset + rel->addend - (u32)p;
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
            OSReport("OSLink: unknown relocation type %3d\n", rel->type);
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


BOOL Link(OSModuleInfo *newModule, void *bss, BOOL fixed) {
    u32 i;
    OSSectionInfo *si;
    OSModuleHeader *moduleHeader;
    OSModuleInfo *moduleInfo;
    OSImportInfo *imp;
    moduleHeader = (OSModuleHeader *)newModule;
    moduleHeader->bssSection = 0;
    if (3 < newModule->version ||
        2 <= newModule->version &&
            (moduleHeader->align && (u32)newModule % moduleHeader->align != 0 ||
             moduleHeader->bssAlign && (u32)bss % moduleHeader->bssAlign != 0)) {
        return 0;
    }
    do {
        OSModuleInfo *__prev;
        __prev = (&__OSModuleInfoList)->tail;
        if (__prev == ((void *)0))
            (&__OSModuleInfoList)->head = (newModule);
        else
            __prev->link.next = (newModule);
        (newModule)->link.prev = __prev;
        (newModule)->link.next = ((void *)0);
        (&__OSModuleInfoList)->tail = (newModule);
    } while (0);
    newModule->sectionInfoOffset += (u32)moduleHeader;
    moduleHeader->relOffset += (u32)moduleHeader;
    moduleHeader->impOffset += (u32)moduleHeader;
    if (3 <= newModule->version) {
        moduleHeader->fixSize += (u32)moduleHeader;
    }
    for (i = 1; i < newModule->numSections; i++) {
        si = &((OSSectionInfo *)(((OSModuleInfo *)(newModule))->sectionInfoOffset))[i];
        if (si->offset != 0) {
            si->offset += (u32)moduleHeader;
        } else if (si->size != 0) {
            moduleHeader->bssSection = (u8)i;
            si->offset = (u32)bss;
        }
    }
    for (imp = (OSImportInfo *)moduleHeader->impOffset;
         imp < (OSImportInfo *)(moduleHeader->impOffset + moduleHeader->impSize); imp++) {
        imp->offset += (u32)moduleHeader;
    }
    if (moduleHeader->prologSection != 0) {
        moduleHeader->prolog +=
            ((((OSSectionInfo *)(((OSModuleInfo *)(newModule))
                                     ->sectionInfoOffset))[moduleHeader->prologSection]
                  .offset) &
             ~0x1);
    }
    if (moduleHeader->epilogSection != 0) {
        moduleHeader->epilog +=
            ((((OSSectionInfo *)(((OSModuleInfo *)(newModule))
                                     ->sectionInfoOffset))[moduleHeader->epilogSection]
                  .offset) &
             ~0x1);
    }
    if (moduleHeader->unresolvedSection != 0) {
        moduleHeader->unresolved +=
            ((((OSSectionInfo *)(((OSModuleInfo *)(newModule))
                                     ->sectionInfoOffset))[moduleHeader->unresolvedSection]
                  .offset) &
             ~0x1);
    }
    if (__OSStringTable) {
        newModule->nameOffset += (u32)__OSStringTable;
    }
    Relocate(0, moduleHeader);
    for (moduleInfo = __OSModuleInfoList.head; moduleInfo; moduleInfo = moduleInfo->link.next) {
        Relocate(moduleHeader, (OSModuleHeader *)moduleInfo);
        if (moduleInfo != newModule) {
            Relocate((OSModuleHeader *)moduleInfo, moduleHeader);
        }
    }
    if (fixed) {
        for (imp = (OSImportInfo *)moduleHeader->impOffset;
             imp < (OSImportInfo *)(moduleHeader->impOffset + moduleHeader->impSize); imp++) {
            if (imp->id == 0 || imp->id == newModule->id) {
                moduleHeader->impSize = (u32)((u8 *)imp - (u8 *)moduleHeader->impOffset);
                break;
            }
        }
    }
    memset(bss, 0, moduleHeader->bssSize);
    fn_8000DD60(newModule);
    return 1;
}


BOOL OSLink(OSModuleInfo *newModule, void *bss) {
    return Link(newModule, bss, FALSE);
}

BOOL OSLinkFixed(OSModuleInfo *newModule, void *bss) {
    if (newModule->version > 3 || newModule->version < 3) {
        return FALSE;
    }
    return Link(newModule, bss, TRUE);
}

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

