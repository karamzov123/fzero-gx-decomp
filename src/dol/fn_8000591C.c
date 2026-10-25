#include "types.h"

typedef struct DVDFileInfo {
    u8 pad[0x34];
    u32 length;
    u8 tail[0x10];
} DVDFileInfo;

typedef struct Module {
    u8 pad[0x34];
    void *(*entry)(void);
} Module;

extern void *OSGetArenaHi(void);
extern u32 OSGetTick(void);
extern char lbl_80095EA0[15];
extern s32 DVDOpen(char *, DVDFileInfo *);
extern void *OSAllocFromArenaHi(u32, u32);
extern s32 fn_80006354(DVDFileInfo *, void *, u32, u32);
extern s32 DVDClose(DVDFileInfo *);
extern void OSLink(void *, u32);
extern s32 OSUnlink(void *);
extern u32 fn_800793D4(void *, u32, u32);
extern void OSSetArenaHi(void *);

void fn_8000591C(void) {
    u32 total;
    DVDFileInfo file_info;
    void *module;
    u32 module_size;
    void *arena_hi;
    u32 size;
    void *(*entry)(void);

    arena_hi = OSGetArenaHi();
    module_size = ((OSGetTick() & 0x1Fu) + 1) << 5;
    DVDOpen(lbl_80095EA0, &file_info);
    size = (file_info.length + 0x1F) & ~0x1Fu;
    total = size + module_size;
    module = OSAllocFromArenaHi(total, 0x20);
    fn_80006354(&file_info, module, size, 0);
    DVDClose(&file_info);
    OSLink(module, 0);
    entry = ((Module *)module)->entry();
    OSUnlink(module);
    fn_800793D4(module, total & 0xFF, 0);
    OSSetArenaHi(arena_hi);
    entry();
}
