#include "types.h"

typedef struct ARCHeader {
    u32 magic;
    u32 data_offset;
    u32 unk_8;
    u32 table_offset;
} ARCHeader;

typedef struct ARCEntry {
    u32 isDirAndStringOff;
    u32 parentOrPosition;
    u32 nextEntryOrLength;
} ARCEntry;

typedef struct ARCHandle {
    void *archiveStartAddr;
    void *FSTStart;
    void *fileStart;
    u32 entryNum;
    char *FSTStringStart;
    u32 FSTLength;
    u32 currDir;
} ARCHandle;

typedef struct ARCFileInfo {
    ARCHandle *handle;
    u32 startOffset;
    u32 length;
} ARCFileInfo;

extern char lbl_80132788[34];
extern char lbl_801A6610[6];
extern char lbl_801327AC[70];
extern void OSPanic(const char *file, int line, const char *format, ...);
extern void OSReport(const char *, ...);
extern s32 fn_8007ED90(s32);

s32 fn_8006A554(ARCHandle *arg0, u8 *p);
BOOL fn_8006A8CC(ARCHandle *handle, char *path, u32 maxlen);

u32 fn_8006A3DC(ARCHeader *src, ARCHandle *dst) {
    u8 *data;
    if (src->magic != 0x55AA382D) {
        OSPanic(lbl_801A6610, 0x3b, lbl_80132788);
    }

    dst->archiveStartAddr = src;
    data = (u8 *)src + src->data_offset;
    dst->FSTStart = data;
    dst->fileStart = (u8 *)src + src->table_offset;
    dst->entryNum = ((u32 *)data)[2];
    dst->FSTStringStart = (char *)(data + dst->entryNum * 0xc);
    dst->FSTLength = src->unk_8;
    dst->currDir = 0;
    return 1;
}

s32 fn_8006A480(ARCHandle *arg0, const char *arg1, ARCFileInfo *arg2) {
    ARCEntry *entries;
    s32 idx;
    char buf[0x80];
    entries = (ARCEntry *)arg0->FSTStart;
    idx = fn_8006A554(arg0, (u8 *)arg1);
    if (idx < 0) {
        fn_8006A8CC(arg0, buf, 0x80);
        OSReport(lbl_801327AC, arg1, buf);
        return 0;
    }
    if (idx < 0 || ((entries[idx].isDirAndStringOff & 0xFF000000) == 0 ? 0 : 1)) {
        return 0;
    }
    arg2->handle = arg0;
    arg2->startOffset = entries[idx].parentOrPosition;
    arg2->length = entries[idx].nextEntryOrLength;
    return 1;
}

s32 fn_8006A554(ARCHandle *arg0, u8 *p) {
    ARCEntry *ent;
    s32 idx;
    u8 *end;
    s32 len;
    s32 i;
    s32 flag;
    ARCEntry *entries;
    u32 pad_a, pad_b;

    idx = arg0->currDir;
    entries = (ARCEntry *)arg0->FSTStart;

    for (;;) {
        if (*p == 0) {
            return idx;
        }
        if (*p == '/') {
            idx = 0;
            p++;
            continue;
        }
        if (*p == '.') {
            if (p[1] == '.') {
                if (p[2] == '/') {
                    idx = entries[idx].parentOrPosition;
                    p += 3;
                    continue;
                }
                if (p[2] == 0) {
                    return entries[idx].parentOrPosition;
                }
            } else if (p[1] == '/') {
                p += 2;
                continue;
            } else if (p[1] == 0) {
                return idx;
            }
        }
        end = p;
        while (((0) != (*end)) && *end != '/') {
            end++;
        }
        flag = (*end == 0) ? 0 : 1;
        len = end - p;
        i = idx + 1;
        while (i < (&entries[idx])->nextEntryOrLength) {
            ent = &entries[i];
            (void)ent; /* fzgx: keeps the web at its definition */
            if (((ent->isDirAndStringOff & 0xFF000000) == 0 ? 0 : 1) != 0 || flag != 1) {
                s32 f = ent->isDirAndStringOff;
                u8 *t = p;
                u8 *s = (u8 *)(arg0->FSTStringStart + (f & 0x00FFFFFF));
                s32 m = 1;
                while (*s != 0) {
                    s32 c1 = fn_8007ED90(*s++);
                    s32 c2 = fn_8007ED90(*t++);
                    if (c2 != c1) {
                        m = 0;
                        goto cmp; // fzgx-allow: S1 goto shape is the retail control flow; no equivalent exists in C
                    }
                }
                if (*t == '/' || *t == 0) {
                    m = 1;
                } else {
                    m = 0;
                }
            cmp:
                if (m == 1) {
                    goto found; // fzgx-allow: S1 goto shape is the retail control flow; no equivalent exists in C
                }
            }
            i = ((ent->isDirAndStringOff & 0xFF000000) == 0 ? 0 : 1) ? ent->nextEntryOrLength : i + 1;
        }
        return -1;
    found:
        if (flag == 0) {
            return i;
        }
        idx = i;
        p = (u8 *)(len + (u32)p);
        p = p + 1;
    }
}

#define entryIsDir(i) (((FSTEntries[i].isDirAndStringOff & 0xff000000) == 0) ? FALSE : TRUE)
#define stringOff(i) (FSTEntries[i].isDirAndStringOff & ~0xff000000)
#define parentDir(i) (FSTEntries[i].parentOrPosition)
#define nextDir(i) (FSTEntries[i].nextEntryOrLength)

static inline u32 myStrncpy(char *dest, char *src, u32 maxlen) {
    u32 i = maxlen;

    while ((i > 0) && (*src != 0)) {
        *dest++ = *src++;
        i--;
    }
    return (maxlen - i);
}

u32 fn_8006A768(ARCHandle *handle, u32 entry, char *path, u32 maxlen) {
    char *name;
    u32 loc;
    ARCEntry *FSTEntries;

    FSTEntries = (ARCEntry *)handle->FSTStart;

    if (entry == 0) {
        return 0;
    }

    name = handle->FSTStringStart + stringOff(entry);
    loc = fn_8006A768(handle, parentDir(entry), path, maxlen);

    if (loc == maxlen) {
        return loc;
    }

    *(path + loc++) = '/';
    loc += myStrncpy(path + loc, name, maxlen - loc);
    return loc;
}

static inline BOOL ARCConvertEntrynumToPath(ARCHandle *handle, s32 entrynum, char *path, u32 maxlen) {
    u32 loc;
    ARCEntry *FSTEntries;

    FSTEntries = (ARCEntry *)handle->FSTStart;
    loc = fn_8006A768(handle, entrynum, path, maxlen);

    if (loc == maxlen) {
        path[maxlen - 1] = '\0';
        return FALSE;
    }

    if (entryIsDir(entrynum)) {
        if (loc == maxlen - 1) {
            path[loc] = '\0';
            return FALSE;
        }
        path[loc++] = '/';
    }

    path[loc] = '\0';
    return TRUE;
}

BOOL fn_8006A8CC(ARCHandle *handle, char *path, u32 maxlen) {
    return ARCConvertEntrynumToPath(handle, handle->currDir, path, maxlen);
}

void *fn_8006A998(ARCFileInfo *arg0) {
    return (u8 *)arg0->handle->archiveStartAddr + arg0->startOffset;
}

u32 fn_8006A9AC(ARCFileInfo *data) {
    return data->length;
}

s32 fn_8006A9B4(ARCHandle *data, const char *dirName) {
    s32 idx = fn_8006A554(data, (u8 *)dirName);
    ARCEntry *tbl = (ARCEntry *)data->FSTStart;

    if (idx < 0 || ((tbl[idx].isDirAndStringOff & 0xFF000000) == 0 ? 0 : 1) == 0) {
        return 0;
    }
    data->currDir = idx;
    return 1;
}
