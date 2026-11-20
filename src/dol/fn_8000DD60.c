#include "types.h"
#include <dolphin/os.h>
#include <dolphin/os/OSModule.h>


/* --- dol/fn_8000DD60.c --- */
/* --- dol/fn_8000DD60.c --- */
// fn_8000DD60: empty in retail (single blr).
void fn_8000DD60(void) {
}

/* --- dol/fn_8000DD64.c --- */
// fn_8000DD64: empty in retail (single blr).
void fn_8000DD64(void) {
}

/* --- dol/fn_8000DD68.c --- */
void fn_8000DD68(u32 arg0) {
    *(u32 *)0x800030D0 = arg0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
}

/* --- dol/Relocate.c --- */
void OSReport(const char *msg, ...);

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
