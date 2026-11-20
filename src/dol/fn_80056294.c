#include "types.h"
#include "dolphin/dvd.h"


/* --- dol/fn_80056294.c --- */
typedef struct {
    u8 pad[0x34];
    u32 size;
    u8 pad2[4];
} Sig_DVDOpen_DVDFileInfo;

typedef void (*fn_80056294_Fn)(u32, u32, u32);

extern u32 lbl_801878C4[];
extern u32 lbl_801878C8[];
extern u8 lbl_80188870[];
extern char lbl_80091F50[];
extern BOOL DVDOpen(const char *, Sig_DVDOpen_DVDFileInfo *);
extern BOOL DVDClose(Sig_DVDOpen_DVDFileInfo *);
extern char *fn_80083DB0(char *, const char *);
extern char *strcat(char *, const char *);
extern size_t strlen(const char *);

u32 fn_80056294(char *arg0, u32 arg1, u32 arg2) {
    struct { u32 a[65]; } buf;
    Sig_DVDOpen_DVDFileInfo info;
    u8 *base;
    char *p;
    u32 n;
    u32 i;
    u32 size;

    base = (u8 *)lbl_80091F50;
    if (arg0 == 0) {
        if (lbl_801878C8[0] != 0) {
            ((fn_80056294_Fn)lbl_801878C8[0])(lbl_801878C4[0], (u32)(base + 0x1ac), 0);
        }
        return 0;
    }
    fn_80083DB0((char *)&buf, (const char *)lbl_80188870);
    strcat((char *)&buf, arg0);
    n = strlen((char *)&buf);
    p = (char *)&buf;
    for (i = 0; i < n; i++) {
        if (p[i] == '\\') {
            p[i] = '/';
        }
    }
    if (!DVDOpen((char *)&buf, &info)) {
        if (lbl_801878C8[0] != 0) {
            ((fn_80056294_Fn)lbl_801878C8[0])(lbl_801878C4[0], (u32)(base + 0x1d8), 0);
        }
        return 0;
    }
    size = info.size;
    if (size & ~0x7fffffff) {
        size = 0x7fffffff;
    }
    if (!DVDClose(&info)) {
        if (lbl_801878C8[0] != 0) {
            ((fn_80056294_Fn)lbl_801878C8[0])(lbl_801878C4[0], (u32)(base + 0x208), 0);
        }
        return 0;
    }
    return size;
}

/* --- dol/fn_800563F8.c --- */
void fn_800563F8(u32 arg0, u32 arg1) {
    lbl_801878C8[0] = arg0;
    lbl_801878C4[0] = arg1;
}
