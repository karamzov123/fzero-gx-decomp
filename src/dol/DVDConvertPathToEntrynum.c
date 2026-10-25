
#include "types.h"

typedef unsigned int uint;

typedef struct FSTEntry FSTEntry;

struct FSTEntry {
    uint isDirAndStringOff;
    uint parentOrPosition;
    uint nextEntryOrLength;
};

s32 DVDConvertPathToEntrynum(const char *pathPtr);

void OSPanic(const char *file, int line, const char *message, ...);

int fn_8007ED90(int c);

extern FSTEntry *FstStart;

extern char *FstStringStart;

extern u32 lbl_801A68B0;

extern u32 __DVDLongFileNameFlag;

static inline BOOL isSame(const char *path, const char *string) {
    while (*string != '\0') {
        if (fn_8007ED90(*path++) != fn_8007ED90(*string++)) {
            return (0);
        }
    }
    if ((*path == '/') || (*path == '\0')) {
        return (1);
    }
    return (0);
}

s32 DVDConvertPathToEntrynum(const char *pathPtr) {
    const char *ptr;
    char *stringPtr;
    BOOL isDir;
    u32 length;
    u32 dirLookAt;
    u32 i;
    const char *origPathPtr = pathPtr;
    const char *extentionStart;
    BOOL illegal;
    BOOL extention;
    dirLookAt = lbl_801A68B0;
    while (1) {
        if (*pathPtr == '\0') {
            return (s32)dirLookAt;
        } else if (*pathPtr == '/') {
            dirLookAt = 0;
            pathPtr++;
            continue;
        } else if (*pathPtr == '.') {
            if (*(pathPtr + 1) == '.') {
                if (*(pathPtr + 2) == '/') {
                    dirLookAt = (FstStart[dirLookAt].parentOrPosition);
                    pathPtr += 3;
                    continue;
                } else if (*(pathPtr + 2) == '\0') {
                    return (s32)(FstStart[dirLookAt].parentOrPosition);
                }
            } else if (*(pathPtr + 1) == '/') {
                pathPtr += 2;
                continue;
            } else if (*(pathPtr + 1) == '\0') {
                return (s32)dirLookAt;
            }
        }
        if (!__DVDLongFileNameFlag) {
            extention = (0);
            illegal = (0);
            for (ptr = pathPtr; (*ptr != '\0') && (*ptr != '/'); ptr++) {
                if (*ptr == '.') {
                    if ((ptr - pathPtr > 8) || (extention == (1))) {
                        illegal = (1);
                        break;
                    }
                    extention = (1);
                    extentionStart = ptr + 1;
                } else if (*ptr == ' ') {
                    illegal = (1);
                }
            }
            if ((extention == (1)) && (ptr - extentionStart > 3)) {
                illegal = (1);
            }
            if (illegal) {
                OSPanic("dvdfs.c", 379,
                        "DVDConvertEntrynumToPath(possibly DVDOpen or DVDChangeDir or DVDOpenDir): "
                        "specified directory or file (%s) doesn't match standard 8.3 format. This "
                        "is a temporary restriction and will be removed soon\n",
                        origPathPtr);
            }
        } else {
            for (ptr = pathPtr; (*ptr != '\0') && (*ptr != '/'); ptr++)
                ;
        }
        isDir = (*ptr == '\0') ? (0) : (1);
        length = (u32)(ptr - pathPtr);
        ptr = pathPtr;
        for (i = dirLookAt + 1; i < (FstStart[dirLookAt].nextEntryOrLength);
             i = (((FstStart[i].isDirAndStringOff & 0xff000000) == 0) ? (0) : (1))
                     ? (FstStart[i].nextEntryOrLength)
                     : (i + 1)) {
            if (((((FstStart[i].isDirAndStringOff & 0xff000000) == 0) ? (0) : (1)) == (0)) &&
                (isDir == (1))) {
                continue;
            }
            stringPtr = FstStringStart + (FstStart[i].isDirAndStringOff & ~0xff000000);
            if (isSame(ptr, stringPtr) == (1)) {
                goto next_hier; // Preserve the verified SDK control flow.
            }
        }
        return -1;
    next_hier:
        if (!isDir) {
            return (s32)i;
        }
        dirLookAt = i;
        pathPtr += length + 1;
    }
}
