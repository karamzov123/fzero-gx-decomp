#include "types.h"

typedef struct {
    u8 pad[0x34];
    u32 length;
    u8 tail[0x10];
} DVDFileInfo;

typedef struct Module {
    u8 pad[0x34];
    void *(*entry)(void);
} Module;

typedef struct GXColor {
    u8 r, g, b, a;
} GXColor;

typedef f32 Mtx44[4][4];

extern u32 lbl_801A66B4;
extern f32 lbl_801A6E40;
extern const f32 lbl_801A6E44;
extern const f32 lbl_801A6E48;
extern const f32 lbl_801A6E4C;
extern const f32 lbl_801A6E50;
extern const f32 lbl_801A6E54;
extern u32 lbl_801A7900[2];
extern u32 lbl_801A66CC;
extern u8 lbl_801A66B0[4];
extern char lbl_801A63C4[8];
extern u8 lbl_801A66AC;
extern char lbl_80095EA0[15];
extern u8 lbl_8015B920[];
extern u32 lbl_801A63D0;
extern GXColor lbl_801A6E58;
extern GXColor lbl_801A7908;
extern void *lbl_801A6D00;
extern f32 lbl_801A6E5C;
extern f32 lbl_801A6E60;
extern f32 lbl_801A6E64;
extern f32 lbl_801A6E68;
extern f32 lbl_801A6E6C;
extern f32 lbl_801A6E70;
extern f64 lbl_801A6E78;
extern f32 lbl_801A6E80;
extern f64 lbl_801A6E88;
extern f32 lbl_801A6E90;
extern f32 lbl_801A6E94;

extern u32 OSGetResetCode(void);
extern int __cntlzw(unsigned int value);
extern u32 DVDInit(void);
extern u32 OSGetProgressiveMode(void);
extern u32 OSInit(void);
extern u32 VIInit(void);
extern void mathutil_init(void);
extern u32 fn_800063AC(void);
extern u32 fn_80006B30(u32);
extern u32 fn_800071B8(void);
extern u32 fn_8006CCC8(void);
extern f32 fn_8006CD40(f32);
extern u32 fn_80070158(u32);
extern u32 fn_80070538(void);
extern u32 fn_80070620(u32);
extern u32 fn_80070774(u32, u32, u32);
extern u32 fn_80070AC0(u32, u32);
extern s32 fn_80006354(DVDFileInfo *, void *, u32, u32);
extern void fn_80006AFC(void);
extern void fn_8006FCB4(void);
extern void fn_8006FF8C(s32);
extern void fn_8007075C(u32);
extern void fn_800721FC(f32, f32, f32, f32);
extern u32 fn_80072BD0(u32);
extern u32 fn_800728A8(s32, s32, s32, s32);
extern u32 GXSetAlphaCompare(u32, u32, u32, u32, u32);
extern u32 fn_80037D40(u32, u32);
extern void fn_80007A44(void);
extern void fn_8006CDFC(void *);
extern void fn_8006CE1C(f32);
extern u32 fn_800702E4(u32);
extern u32 fn_800791A4(void);
extern void OSGetSavedRegion(void *, void *);
extern void *memset(void *, int, u32);
extern void *memcpy(void *, const void *, u32);
extern s32 DVDOpen(char *, DVDFileInfo *);
extern void *OSAllocFromArenaHi(u32, u32);
extern void fn_8000DD68(void *);
extern s32 DVDClose(DVDFileInfo *);
extern u32 PADInit(void);
extern u32 PADSetAnalogMode(u32);
extern u32 fn_8006B188(void);
extern void *OSGetArenaLo(void);
extern void *OSGetArenaHi(void);
extern void OSSetArenaLo(u32);
extern void OSSetArenaHi(void *);
extern u32 OSGetTick(void);
extern void OSLink(void *, u32);
extern s32 OSUnlink(void *);
extern u32 fn_800793D4(void *, u32, u32);
extern s32 fn_80005E0C(void);
extern void fn_8006FD1C(void);
extern s32 fn_8006FDEC(void);
extern void fn_8006FEFC(void);
extern u32 GXInvalidateTexAll(u32);
extern u32 GXInitTexObj(u32, u32, u32, u32, u32, u32, u32, u32);
extern void fn_800723F8(void);
extern void fn_8007245C(u32);
extern void fn_80074788(u32);
extern void fn_80074660(u32);
extern void fn_80073678(u32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_80072EDC(s32, s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_800371F8(s32, GXColor);
extern void fn_80074918(u8, s32, u8);
extern void fn_800377F8(s32, f32, f32, f32, f32, GXColor);
extern void fn_80072864(u32);
extern void lbl_8006D758(void);
extern void GXLoadPosMtxImm(void *, u32);
extern void C_MTXOrtho(Mtx44, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(Mtx44, s32);
extern void fn_80073778(void *, s32);
extern void fn_8003462C(u32, u32, u32);

void fn_80005660(void);
void fn_80005738(void);
void fn_800057CC(void);
void fn_800057F8(void);
void fn_80005858(void);
u8 fn_800058D8(void);
void fn_8000591C(void);
void fn_80005A08(void);
void fn_80005AD0(u32 arg0);
void fn_80005B10(void *arg0);

void main(int argc, char **argv) {
    u32 reset_code;
    u32 reset_match;
    u32 *base;
    u32 value;

    reset_code = OSGetResetCode();
    reset_match = (u32)__cntlzw(((u32)1 << 31) - reset_code) >> 5;
    if (reset_match) {
        fn_800057F8();
    }

    value = 0x4C000064;
    base = (u32 *)((u32)0x40000000 << 1);
    base[0x200 / 4] = value;
    base[0x300 / 4] = value;
    base[0x400 / 4] = value;
    base[0x600 / 4] = value;
    base[0x700 / 4] = value;
    base[0xC00 / 4] = value;
    base[0xD00 / 4] = value;
    base[0x1000 / 4] = value;
    base[0x1100 / 4] = value;
    base[0x1200 / 4] = value;
    base[0x1300 / 4] = value;
    lbl_801A66B4 = 0;
    fn_80005660();
    fn_8000591C();
}

void fn_80005660(void) {
    u32 reset_code;
    u32 reset_match;
    u32 v1;
    u32 t12, t13;

    OSInit();
    DVDInit();
    fn_80006AFC();
    fn_80006B30((u32)fn_80006354);
    VIInit();
    mathutil_init();
    fn_80070158(1);
    fn_8007075C(1);
    fn_8006FF8C(1);
    fn_80070538();
    fn_800071B8();
    reset_code = OSGetResetCode();
    reset_match = (u32)__cntlzw(((u32)1 << 31) - reset_code) >> 5;
    if (reset_match && OSGetProgressiveMode() != 0) {
        v1 = 1;
        t12 = fn_80070620(v1);
        v1 = t12;
    } else {
        v1 = 0;
        t13 = fn_80070620(v1);
        v1 = t13;
    }
    fn_80070774(1, 0xC0000, 1);
    fn_8006FCB4();
    fn_8006CCC8();
    fn_8006CD40(lbl_801A6E40);
    fn_80070AC0(32, 1);
    fn_80005738();
    fn_800057CC();
    fn_800058D8();
    fn_800063AC();
    fn_80005A08();
    fn_80005858();
}

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

void fn_800057CC(void) {
    u32 t0;
    t0 = fn_800702E4(3);
    lbl_801A66CC = t0;
    fn_800791A4();
}

void fn_800057F8(void) {
    void *src;
    void *dst;

    OSGetSavedRegion(&src, &dst);
    if (src == 0 || dst == 0) {
        memset(lbl_801A66B0, 0, 4);
    } else {
        memcpy(lbl_801A66B0, src, 4);
    }
}

void fn_80005858(void) {
    struct {
        u8 pad[0x34];
        u32 size;
    } info;
    void *buffer;
    u32 size;

    if (DVDOpen(lbl_801A63C4, (DVDFileInfo *)&info)) {
        size = (info.size + 0x1f) & ~0x1f;
        buffer = OSAllocFromArenaHi(size, 0x20);
        if (fn_80006354((DVDFileInfo *)&info, buffer, size, 0)) {
            fn_8000DD68(buffer);
        }
        DVDClose((DVDFileInfo *)&info);
    }
}

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

void fn_80005A08(void) {
    s32 var_r31;
    s32 var_r30_2;
    s32 var_r30;
    void *temp_r29;
    void *temp_r28;

    temp_r29 = OSGetArenaLo();
    temp_r28 = OSGetArenaHi();
    fn_80005AD0((u32)(lbl_8015B920));
    var_r30 = 0;
    do {
        fn_80005E0C();
        var_r30 += 1;
    } while (var_r30 < 0x14);
    var_r30_2 = 0;
    do {
        fn_8006FD1C();
        fn_80005B10(lbl_8015B920);
        fn_80005E0C();
        fn_80005E0C();
        fn_8006FDEC();
        fn_8006FEFC();
        var_r30_2 += 1;
    } while (var_r30_2 < 5);
    var_r31 = 0;
    do {
        fn_80005E0C();
        var_r31 += 1;
    } while (var_r31 < 0x14);
    OSSetArenaLo((u32)(temp_r29));
    OSSetArenaHi(temp_r28);
}

void fn_80005AD0(u32 arg0) {
    u32 t0;
    t0 = GXInitTexObj(arg0, lbl_801A63D0, 640, 480, 14, 0, 0, 0);
    GXInvalidateTexAll(t0);
}

void fn_80005B10(void *arg0) {
    Mtx44 mtx;
    GXColor color = lbl_801A6E58;
    f32 cx = 320.0f;
    f32 cy = 240.0f;
    f64 l, t, r, b;

    fn_800723F8();
    fn_8007245C(0x2200);
    fn_800723F8();
    fn_80074788(0);
    fn_80074660(1);
    fn_80073678(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_80072EDC(0, 0);
    fn_800745A4(0, 1, 4, 60, 0, 125);
    fn_800734A8(0, 0, 0, 255);
    fn_80072AB0(0, 0, 0);
    fn_80072C24(0, 15, 2, 8, 4);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 1, 4, 2);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_800747D0(4, 0, 0, 0, 0, 2, 2);
    fn_800371F8(1, color);
    fn_80074918(1, 1, 1);
    fn_800728A8(1, 4, 5, 0);
    fn_800377F8(0, 0.0f, 100.0f, 0.0f, 100.0f, lbl_801A7908);
    fn_80072864(2);
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    C_MTXOrtho(mtx, lbl_801A6E5C, lbl_801A6E64, lbl_801A6E5C, lbl_801A6E68, lbl_801A6E5C, lbl_801A6E6C);
    fn_800737E4(mtx, 1);
    color.r = 255;
    color.g = 255;
    color.b = 255;
    color.a = 255;
    fn_800371F8(1, color);
    color.r = 0;
    color.g = 0;
    color.b = 0;
    color.a = 0;
    fn_800371F8(2, color);
    fn_80073778(arg0, 0);
    fn_8003462C(128, 7, 4);

    l = cx - 320.0;
    r = 320.0 + cx;
    t = cy - 240.0;
    b = 240.0 + cy;

    *(f32 *)((u8 *)0xCC010000 + -32768) = l;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = t;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A6E90;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A6E5C;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A6E5C;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = r;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = t;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A6E90;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A6E94;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A6E5C;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = r;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = b;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A6E90;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A6E94;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A6E94;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = l;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = b;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A6E90;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A6E5C;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A6E94;  /* fzgx-allow: A2 */
}
