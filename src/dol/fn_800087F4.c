#include "types.h"


/* --- dol/fn_800087F4.c --- */
extern void fn_80073778(void *, s32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80074918(u8, s32, u8);
extern u32 fn_800720B0(u32);
extern void fn_80072864(u32);
extern void fn_80073C6C(void *);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern u32 fn_800734A8(void *, u32, u32, u32);
extern void fn_80073620(void *, s32);
extern void fn_80072C24(void *, s32, s32, s32, s32);
extern u32 fn_80072D64(void *, u32, u32, u32, u32, u32);
extern u32 fn_80072CC4(void *, u32, u32, u32, u32);
extern void fn_80072E20(void *, s32, s32, s32, u8, s32);
extern void fn_80073678(u32);
extern void fn_80074660(u32);
extern void fn_80073898(u32);
extern void fn_80074788(u32);
extern void fn_800736C0(u32, void *);
extern u32 fn_800735C8(void *, u32);
extern void fn_8007245C(u32);

struct FzgxCopy_4 { u32 words[1]; };
void fn_800087F4(void *arg0, void *arg1) {
    struct FzgxCopy_4 loc_C;
    u32 sp8;
    s32 temp_r0;

    fn_80073778(arg0, (0));
    fn_800728A8((0), (1), (0), (0));
    fn_80074918((1U), (3), (1U));
    fn_800720B0((0U));
    fn_80072864((0U));
    temp_r0 = *(s32 *)((u8 *)(arg1) + 20);
    switch (temp_r0) {                              /* irregular */
    case 0:
        fn_80073C6C(NULL);
        fn_800745A4((0U), (1), (4), (0x3CU), (0U), (0x7DU));
        fn_800734A8(NULL, (0U), (0U), (0xFFU));
        fn_80073620(NULL, (0));
        fn_80072C24(NULL, (0xF), (8), (0xC), (0xF));
        fn_80072D64(NULL, (0U), (0U), (0U), (1U), (0U));
        fn_80072CC4(NULL, (7U), (7U), (7U), (6U));
        fn_80072E20(NULL, (0), (0), (0), (1U), (0));
        fn_80073678((1U));
        fn_80074660((1U));
        fn_80073898((0U));
        fn_80074788((0U));
        break;
    case 1:
        fn_80073C6C(NULL);
        fn_800745A4((0U), (1), (4), (0x3CU), (0U), (0x7DU));
        fn_800734A8(NULL, (0U), (0U), (0xFFU));
        (*(u8 *)(&loc_C)) = 0xFF;
        (*((u8 *)(&loc_C) + 1)) = 0;
        (*((u8 *)(&loc_C) + 2)) = 0;
        sp8 = loc_C.words[0];
        fn_800736C0((0U), &sp8);
        fn_800735C8(NULL, (0xCU));
        fn_80073620(NULL, (0));
        fn_80072C24(NULL, (0xE), (0xF), (9), (0xF));
        fn_80072D64(NULL, (0U), (0U), (0U), (1U), (0U));
        fn_80072CC4(NULL, (7U), (7U), (7U), (6U));
        fn_80072E20(NULL, (0), (0), (0), (1U), (0));
        fn_80073678((1U));
        fn_80074660((1U));
        fn_80073898((0U));
        fn_80074788((0U));
        break;
    }
    fn_8007245C((0x2200U));
}

/* --- dol/fn_80008A4C.c --- */
/* --- dol/fn_80008A4C.c --- */
extern void fn_800746A8(u32, u32);

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
    loc_8 = *(u32 *)(arg0 + 24);
    fn_800736C0(0, &loc_8);
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
