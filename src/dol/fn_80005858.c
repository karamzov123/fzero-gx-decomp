#include "types.h"

typedef struct {
    u8 pad[0x34];
    u32 size;
} DVDFileInfo;

extern char lbl_801A63C4[8];
extern s32 DVDOpen(char *, DVDFileInfo *);
extern void *OSAllocFromArenaHi(u32, u32);
extern s32 fn_80006354(DVDFileInfo *, void *, u32, u32);
extern void fn_8000DD68(void *);
extern void DVDClose(DVDFileInfo *);

void fn_80005858(void) {
    DVDFileInfo info;
    void *buffer;
    u32 size;

    if (DVDOpen(lbl_801A63C4, &info)) {
        size = (info.size + 0x1f) & ~0x1f;
        buffer = OSAllocFromArenaHi(size, 0x20);
        if (fn_80006354(&info, buffer, size, 0)) {
            fn_8000DD68(buffer);
        }
        DVDClose(&info);
    }
}
