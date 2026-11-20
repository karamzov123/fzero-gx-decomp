#include "types.h"


/* --- dol/fn_8006A554.c --- */
struct fn_8006A554_Entry {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};
struct fn_8006A554_Arg0 {
    u32 unk_0;
    struct fn_8006A554_Entry *entries;
    u32 unk_8;
    u32 unk_C;
    u8 *names;
    u32 unk_14;
    s32 idx;
};
struct fn_8006A554_Out {
    void *unk_0;
    u32 unk_4;
    u32 unk_8;
};

extern s32 fn_8007ED90(s32);

s32 fn_8006A554(struct fn_8006A554_Arg0 *arg0, u8 *p, struct fn_8006A554_Out *arg2, u32 arg3, u32 arg4) {
    struct fn_8006A554_Entry *ent;
    s32 idx;
    u8 *end;
    s32 len;
    s32 i;
    s32 flag;
    struct fn_8006A554_Entry *entries;

    idx = arg0->idx;
    entries = arg0->entries;

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
                    idx = entries[idx].unk_4;
                    p += 3;
                    continue;
                }
                if (p[2] == 0) {
                    return entries[idx].unk_4;
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
        while (i < (&entries[idx])->unk_8) {
            ent = &entries[i];
            (void) ent;  /* fzgx: keeps the web at its definition */
            if (((ent->unk_0 & 0xFF000000) == 0 ? 0 : 1) != 0 || flag != 1) {
                s32 f = ent->unk_0;
                u8 *t = p;
                u8 *s = (u8 *)((u32)arg0->names + (f & 0x00FFFFFF));
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
            i = ((ent->unk_0 & 0xFF000000) == 0 ? 0 : 1) ? ent->unk_8 : i + 1;
        }
        return -1;
    found:
        if (flag == 0) {
            return i;
        }
        idx = i;
        p = (u8 *)((u32)len + (u32)p);
        p = p + 1;
    }
}

/* --- dol/fn_8006A768.c --- */
/* --- dol/fn_8006A768.c --- */
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

/* --- dol/fn_8006A8CC.c --- */
#define entryIsDir(i) (((FSTEntries[i].isDirAndStringOff & 0xff000000) == 0) ? FALSE : TRUE)
#define stringOff(i) (FSTEntries[i].isDirAndStringOff & ~0xff000000)
#define parentDir(i) (FSTEntries[i].parentOrPosition)
#define nextDir(i) (FSTEntries[i].nextEntryOrLength)

extern u32 fn_8006A768(ARCHandle *handle, u32 entry, char *path, u32 maxlen); /* entryToPath */

static inline BOOL ARCConvertEntrynumToPath(ARCHandle *handle, s32 entrynum, char *path, u32 maxlen) {
    u32 loc;
    ARCEntry *FSTEntries;

    FSTEntries = (ARCEntry *)handle->FSTStart;
    loc = fn_8006A768(handle, (u32)entrynum, path, maxlen);

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
    return ARCConvertEntrynumToPath(handle, (s32)handle->currDir, path, maxlen);
}
