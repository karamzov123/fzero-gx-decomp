#include "types.h"


/* --- dol/fn_8007B0B4.c --- */
typedef struct FileEntry {
    u8 pad00[4];
    u16 unk04;
    u8 pad06[0x46];
    struct FileEntry *next;
} FileEntry;

extern u8 __files[320];
extern s32 fflush(FileEntry *);

s32 fn_8007B0B4(void) {
    s32 result;
    FileEntry *entry;

    result = 0;
    entry = (FileEntry *)&__files;
    while (entry != 0) {
        if (((entry->unk04 >> 6) & 7) != 0) {
            if (fflush(entry) != 0) {
                result = -1;
            }
        }
        entry = entry->next;
    }
    return result;
}

/* --- dol/__close_all.c --- */
extern u32 __begin_critical_region(u32);
extern void fclose(void *);
extern void fn_8007A150(void *);
extern u32 __end_critical_region(u32);

typedef struct File {
    u8 pad0[4];
    u16 unused0:7;
    u16 mode:3;
    u16 unused1:6;
    u8 pad6[6];
    u8 in_use;
    u8 padD[0x3f];
    struct File *next;
} File;

void __close_all(void) {
    File *file;

    file = (File *)&__files;
    __begin_critical_region(2);
    while (file != 0) {
        if (file->mode != 0) {
            fclose(file);
        }
        {
            File *current;
            current = file;
            file = file->next;
            if (current->in_use != 0) {
                fn_8007A150(current);
            } else {
                current->mode = 3;
                if (file != 0 && file->in_use != 0) {
                    current->next = 0;
                }
            }
        }
    }
    __end_critical_region(2);
}
