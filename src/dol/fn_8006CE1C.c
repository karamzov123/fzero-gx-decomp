#include "types.h"


/* --- dol/fn_8006CE1C.c --- */
extern const f32 lbl_801A73B0;
extern u32 lbl_801A6CA8;

void fn_8006CE1C(f32 arg0) {
    f32 value = lbl_801A73B0;
    ((u8 *)&lbl_801A6CA8)[3] = (value * arg0);
}

/* --- dol/fn_8006CE44.c --- */
extern f32 lbl_801A6CA0;
extern f32 lbl_801A6CA4;
extern f32 lbl_801A73A8;
extern f32 lbl_801A73B4;

extern void fn_80074918(u8, s32, u8);
extern void fn_80074788(u32);
extern void fn_80074660(u32);
extern void fn_80073678(u32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_800747D0(u32, u32, u32, u32, u32, u32, u32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_800734A8(u32, u32, u32, u32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(u32, u32, u32, u32, u32, u32);
extern void fn_80072CC4(u32, u32, u32, u32, u32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072864(u32);
extern void fn_8007245C(u32);
extern u32 fn_800371F8(u32, void *);
extern void fn_8003462C(u32, u32, u32);

void fn_8006CE44(void) {
    u32 flags;
    f32 x;
    f32 y;

    if (((u8 *)&lbl_801A6CA8)[3] == 0) {
        return;
    }
    fn_80074918(0, 7, 0);
    fn_80074788(1);
    fn_80074660(0);
    fn_80073678(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_800747D0(4, 0, 0, 0, 0, 2, 2);
    fn_80072AB0(0, 0, 0);
    fn_800734A8(0, 255, 255, 4);
    fn_80072C24(0, 15, 15, 15, 2);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 1);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_80072864(2);
    fn_8007245C(512);
    flags = lbl_801A6CA8;
    fn_800371F8(1, &flags);
    fn_8003462C(128, 7, 4);

    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A73A8;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A73A8;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A73B4;  /* fzgx-allow: A2 */
    x = lbl_801A6CA4;
    *(f32 *)((u8 *)0xCC010000 + -32768) = x;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A73A8;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A73B4;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = x;  /* fzgx-allow: A2 */
    y = lbl_801A6CA0;
    *(f32 *)((u8 *)0xCC010000 + -32768) = y;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A73B4;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A73A8;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = y;  /* fzgx-allow: A2 */
    *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_801A73B4;  /* fzgx-allow: A2 */
}
