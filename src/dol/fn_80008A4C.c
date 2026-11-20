#include "types.h"


/* --- dol/fn_80008A4C.c --- */
extern u32 fn_800720B0(u32);
extern u32 fn_80072CC4(u32, u32, u32, u32, u32);
extern u32 fn_80072D64(u32, u32, u32, u32, u32, u32);
extern u32 fn_800734A8(u32, u32, u32, u32);
extern void fn_8007245C(u32);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800735C8(s32, s32);
extern void fn_80073620(s32, s32);
extern void fn_80073678(u32);
extern void fn_800736C0(int, void *);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_80074660(u32);
extern void fn_800746A8(u32, u32);
extern void fn_80074788(u32);
extern void fn_80074918(u8, s32, u8);

void fn_80008A4C(u32 arg0, u32 arg1, u32 arg2) {
    u32 loc_8;

    fn_800728A8(0, 1, 0, 0);
    fn_80074918(1, 3, 1);
    fn_800720B0(0);
    fn_800746A8(6, 0);
    fn_80072864(0);
    fn_80073C6C(0);
    fn_800745A4(0, 1, 4, 60, 0, 125);
    fn_800734A8(0, 0, 0, 255);
    loc_8 = *(u32 *)((u8 *)arg0 + 24);
    fn_800736C0(0, (void *)&loc_8);
    fn_800735C8(0, 12);
    fn_80073620(0, 28);
    fn_80072C24(0, 15, 15, 15, 14);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 6);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80073678(1);
    fn_80074660(1);
    fn_80073898(0);
    fn_80074788(0);
    fn_8007245C(512);
}

/* --- dol/fn_80008BA8.c --- */
extern u32 fn_800791E8(u32, u32);
extern u32 fn_800794F0(u32, u32);
extern u32 memcpy(u32, u32, u32);

void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2) {
    u32 v0;
    v0 = (arg1 | arg0);
    if ((v0 & 0x3) != 0) {
    memcpy(arg0, arg1, arg2);
    } else {
    if ((v0 & 0x1F) != 0) {
    fn_800794F0(arg0, arg1);
    } else {
    fn_800791E8(arg0, arg1);
    }
    }
}

/* --- dol/fn_80008BEC.c --- */
extern void fn_800793D4(void *, int, u32);
extern void *memset(void *, int, u32);
void fn_80008BEC(void *dest, int value, u32 size) {
    if (((u32)dest & 0x1F) == 0) {
        fn_800793D4(dest, value, size);
    } else {
        memset(dest, (u8)value, size);
    }
}
