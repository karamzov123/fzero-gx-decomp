#include "types.h"


/* --- dol/fn_800775EC.c --- */
struct fn_800775EC_Arg0 {
    u8 pad_0[0xC];
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
};
struct fn_800775EC_lbl_801A3220 {
    u8 pad_0[0x10];
    u8 unk_10;
    u8 unk_11;
    u8 unk_12;
    u8 pad_13[0x35];
    u32 unk_48;
    u32 unk_4C;
};

extern struct fn_800775EC_lbl_801A3220 lbl_801A3220[];

void fn_800775EC(struct fn_800775EC_Arg0 *arg0) {
    u8 v0;
    v0 = lbl_801A3220[0].unk_11;
    if (lbl_801A3220[0].unk_10 == arg0->unk_C && lbl_801A3220[0].unk_11 == arg0->unk_D) {
    v0 = lbl_801A3220[0].unk_12;
    if (v0 == arg0->unk_E) { return; }
    }
    lbl_801A3220[0].unk_48 = 0;
    lbl_801A3220[0].unk_4C = 0;
    lbl_801A3220[0].unk_10 = arg0->unk_C;
    lbl_801A3220[0].unk_11 = arg0->unk_D;
    lbl_801A3220[0].unk_12 = arg0->unk_E;
}

/* --- dol/fn_80077654.c --- */
extern u32 fn_80072C24(u32, u32, u32, u32, u32);
extern u32 fn_80072CC4(u32, u32, u32, u32, u32);
extern u32 fn_80072D64(u32, u32, u32, u32, u32, u32);
extern u32 fn_80072E20(u32, u32, u32, u32, u32, u32);
extern u32 fn_800734A8(u32, u32, u32, u32);
extern u32 fn_800735C8(u32, u32);
extern u32 fn_80073620(u32, u32);
extern u32 fn_80073C6C(u32);

void fn_80077654(u32 arg0) {
    fn_800735C8(arg0, 14);
    fn_80073620(arg0, 30);
    fn_80073C6C(arg0);
    fn_800734A8(arg0, 255, 255, 255);
    fn_80072C24(arg0, 15, 0, 14, 15);
    fn_80072D64(arg0, 0, 0, 0, 1, 0);
    fn_80072CC4(arg0, 7, 0, 6, 7);
    fn_80072E20(arg0, 0, 0, 0, 1, 0);
}

/* --- dol/fn_80077714.c --- */
void fn_80077714(u32 arg0) {
    fn_800735C8(arg0, 15);
    fn_80073620(arg0, 31);
    fn_80073C6C(arg0);
    fn_800734A8(arg0, 255, 255, 255);
    fn_80072C24(arg0, 0, 15, 15, 14);
    fn_80072D64(arg0, 0, 0, 0, 1, 0);
    fn_80072CC4(arg0, 0, 7, 7, 6);
    fn_80072E20(arg0, 0, 0, 0, 1, 0);
}

/* --- dol/fn_800777D4.c --- */
extern f32 lbl_801A74A8;
extern f32 lbl_801A74AC;
extern struct fn_800777D4_lbl_8019F130 lbl_8019F130;
extern u32 fn_80070D94(void);
extern u32 fn_80070E00(void);
extern u32 fn_80072778(void);
extern u32 fn_80074A8C(f32, f32, f32, f32);
extern u32 fn_80074BC4(f32, f32, f32, f32);
extern u32 fn_80075240(void);
extern u32 fn_80077848(void);
extern u32 lbl_801A6D90;
extern u32 lbl_801A6D94;
extern u32 lbl_801A6D98;

struct fn_800777D4_lbl_8019F130 {
    u8 pad_0[0xC];
    f32 unk_C;
};

void fn_800777D4(void) {
    fn_80072778();
    lbl_8019F130.unk_C = lbl_801A74A8;
    fn_80074A8C(lbl_801A74A8, lbl_801A74A8, lbl_801A74A8, lbl_801A74A8);
    fn_80074BC4(lbl_801A74AC, lbl_801A74AC, lbl_801A74AC, lbl_801A74AC);
    lbl_801A6D90 = 0;
    lbl_801A6D98 = 0;
    lbl_801A6D94 = 0;
    fn_80075240();
    fn_80077848();
    fn_80070E00();
    fn_80070D94();
}
