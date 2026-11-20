#include "types.h"


/* --- dol/fn_80005738.c --- */
extern const f32 lbl_801A6E44;
extern const f32 lbl_801A6E48;
extern u32 lbl_801A7900[2];
extern const f32 lbl_801A6E4C;
extern const f32 lbl_801A6E50;
extern void fn_800721FC(f32, f32, f32, f32);
extern u32 fn_80072BD0(u32);
extern u32 fn_800728A8(u32, u32, u32, u32);
extern u32 GXSetAlphaCompare(u32, u32, u32, u32, u32);
extern u32 fn_80037D40(u32, u32);
extern void fn_80007A44(void);
extern void fn_8006CDFC(void *);
extern const f32 lbl_801A6E54;
extern void fn_8006CE1C(f32);

void fn_80005738(void) {
    u32 value[2];

    value[1] = lbl_801A7900[0];
    fn_800721FC(lbl_801A6E44, lbl_801A6E48, lbl_801A6E4C, lbl_801A6E50);
    fn_80072BD0(1);
    fn_800728A8(1, 4, 5, 0);
    GXSetAlphaCompare(4, 0, 0, 4, 0);
    fn_80037D40(0, 0);
    fn_80007A44();
    value[0] = value[1];
    fn_8006CDFC(&value[0]);
    fn_8006CE1C(lbl_801A6E54);
}

/* --- dol/fn_800057CC.c --- */
extern u32 fn_800702E4(u32);
extern u32 fn_800791A4(void);
extern u32 lbl_801A66CC;

void fn_800057CC(void) {
    u32 t0;
    t0 = fn_800702E4(3);
    lbl_801A66CC = t0;
    fn_800791A4();
}

/* --- dol/fn_800057F8.c --- */
extern void fn_8000EE5C(void *, void *);
extern u8 lbl_801A66B0[4];
extern void *memset(void *, int, u32);
extern void *memcpy(void *, const void *, u32);

void fn_800057F8(void) {
    void *src;
    void *dst;

    fn_8000EE5C(&src, &dst);
    if (src == 0 || dst == 0) {
        memset(lbl_801A66B0, 0, 4);
    } else {
        memcpy(lbl_801A66B0, src, 4);
    }
}

/* --- dol/fn_80005858.c --- */
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

/* --- dol/fn_800058D8.c --- */
extern u32 PADInit(void);
extern u32 PADSetAnalogMode(u32);
extern u32 fn_8006B188(void);
extern u8 lbl_801A66AC;

u8 fn_800058D8(void) {
    u32 v0;
    u32 t0, t1, t2;
    if (lbl_801A66AC == 0) {
    t0 = PADInit();
    v0 = t0;
    v0 = 3;
    t1 = PADSetAnalogMode(v0);
    v0 = t1;
    t2 = fn_8006B188();
    v0 = t2;
    v0 = lbl_801A66AC;
    lbl_801A66AC = (v0 + 1);
    }
    return v0;
}
