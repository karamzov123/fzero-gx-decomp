/* Non-matching: best partial attempt (91.72% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dolphin/dvd.h"

typedef struct {
    u8 pad[0x34];
    u32 size;
    u8 pad2[4];
} Sig_DVDOpen_DVDFileInfo;

typedef struct {
    s8 f0;
    u8 f1;
    u8 f2;
    u8 pad3[5];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1c;
    s32 f20;
    s32 f24;
    Sig_DVDOpen_DVDFileInfo info;
    u8 pad60[4];
} fn_80056084_Slot;

typedef struct {
    u8 pad[0xC];
    u32 obj;
    u32 cb;
} fn_80056084_Tbl;

typedef u32 (*fn_80056084_Fn)(u32, u32, u32);

extern u32 lbl_801878B8[];
extern u8 lbl_80188870[];
extern char lbl_80091F50[];
extern BOOL DVDOpen(const char *, Sig_DVDOpen_DVDFileInfo *);
extern char *fn_80083DB0(char *, const char *);
extern char *strcat(char *, const char *);
extern size_t strlen(const char *);
extern void *memset(void *, int, u32);

s32 fn_80056084(char *arg0, s32 arg1, s32 arg2) {
    char *p_lbl_80091F50;
    fn_80056084_Slot * slot_2;
    fn_80056084_Tbl *p_lbl_801878B8;
    fn_80056084_Slot *slot;
    u32 i;
    char *p;
    size_t n;
    s32 size;
    struct {
        u32 a[66];
    } buf;

    p_lbl_80091F50 = (char *)&lbl_80091F50;
    p_lbl_801878B8 = (fn_80056084_Tbl *)&lbl_801878B8;
    if (arg0 == 0) {
        if (p_lbl_801878B8->cb != 0) {
            ((fn_80056084_Fn)p_lbl_801878B8->cb)(p_lbl_801878B8->obj, (u32)(p_lbl_80091F50 + 0x110), 0);
        }
        return 0;
    }
    if (arg2 != 0) {
        if (p_lbl_801878B8->cb != 0) {
            ((fn_80056084_Fn)p_lbl_801878B8->cb)(p_lbl_801878B8->obj, (u32)(p_lbl_80091F50 + 0x134), 0);
        }
        return 0;
    }
    slot = 0;
    for (i = 0; i < 40; i++) {
        if (((fn_80056084_Slot *)((u8 *)p_lbl_801878B8 + 0x14 + i * 0x64))->f0 == 0) {
            slot_2 = (fn_80056084_Slot *)((u8 *)p_lbl_801878B8 + 0x14 + i * 0x64);
            break;
        }
    }
    if (slot_2 == 0) {
        if (p_lbl_801878B8->cb != 0) {
            ((fn_80056084_Fn)p_lbl_801878B8->cb)(p_lbl_801878B8->obj, (u32)(p_lbl_80091F50 + 0x158), 0);
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
    if (!DVDOpen((char *)&buf, &slot_2->info)) {
        if (p_lbl_801878B8->cb != 0) {
            ((fn_80056084_Fn)p_lbl_801878B8->cb)(p_lbl_801878B8->obj, (u32)(p_lbl_80091F50 + 0x188), 0);
        }
        memset((void *)slot_2, 0, 0x64);
        return 0;
    }
    slot_2->f10 = 0x800;
    size = (s32)slot_2->info.size;
    if (size & ~0x7fffffff) {
        size = 0x7fffffff;
    }
    slot_2->f14 = size;
    slot_2->f18 = (slot_2->f10 + slot_2->f14 - 1) / slot_2->f10;
    slot_2->f1c = 0;
    slot_2->f8 = 0;
    slot_2->f24 = 0;
    slot_2->f20 = 0;
    slot_2->f2 = 0;
    slot_2->f0 = 1;
}
