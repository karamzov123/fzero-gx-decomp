/* Non-matching: best partial attempt (90.81% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u32 w[61];
    f32 f07;
    f32 f08;
    f32 f09;
    f32 f10;
    f32 f11;
    f32 f12;
    f32 f13;
} fn_1_A5F44_Pool;

typedef struct {
    u32 unk_0;
    s8 unk_4;
    s8 unk_5;
    s16 unk_6;
} fn_1_A5F44_State;

extern fn_1_A5F44_Pool lbl_1_rodata_48C8;
extern fn_1_A5F44_State *lbl_1_data_341B8;
extern s32 lbl_801A66B4;
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495B0(u32);
extern void fn_1_4965C(u8);
extern void fn_1_49514(u32 *);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AF10(const char *);
extern void fn_1_4A0D8(const char *);

#pragma opt_propagation off
#pragma opt_common_subs off
void fn_1_A5F44(void)
{
    fn_1_A5F44_Pool *p = &lbl_1_rodata_48C8;
    u32 v;
    u32 b[6];
    u32 a[9][6];

    a[8][0] = p->w[0];
    a[8][1] = p->w[1];
    a[8][2] = p->w[2];
    a[8][3] = p->w[3];
    a[8][4] = p->w[4];
    a[8][5] = p->w[5];
    a[7][0] = p->w[6];
    a[7][1] = p->w[7];
    a[7][2] = p->w[8];
    a[7][3] = p->w[9];
    a[7][4] = p->w[10];
    a[7][5] = p->w[11];
    a[6][0] = p->w[12];
    a[6][1] = p->w[13];
    a[6][2] = p->w[14];
    a[6][3] = p->w[15];
    a[6][4] = p->w[16];
    a[6][5] = p->w[17];
    a[5][0] = p->w[18];
    a[5][1] = p->w[19];
    a[5][2] = p->w[20];
    a[5][3] = p->w[21];
    a[5][4] = p->w[22];
    ((5)[a])[5] = p->w[23];
    a[4][0] = p->w[24];
    a[4][1] = p->w[25];
    a[4][2] = p->w[26];
    a[4][3] = p->w[27];
    a[4][4] = p->w[28];
    a[4][5] = p->w[29];
    a[3][0] = p->w[30];
    a[3][1] = p->w[31];
    a[3][2] = p->w[32];
    a[3][3] = p->w[33];
    a[3][4] = p->w[34];
    a[3][5] = p->w[35];
    a[2][0] = p->w[36];
    a[2][1] = p->w[37];
    a[2][2] = p->w[38];
    a[2][3] = p->w[39];
    a[2][4] = p->w[40];
    a[2][5] = p->w[41];
    a[1][0] = p->w[42];
    a[1][1] = p->w[43];
    a[1][2] = p->w[44];
    a[1][3] = p->w[45];
    a[1][4] = p->w[46];
    a[1][5] = p->w[47];
    a[0][0] = p->w[48];
    a[0][1] = p->w[49];
    a[0][2] = p->w[50];
    a[0][3] = p->w[51];
    a[0][4] = p->w[52];
    a[0][5] = p->w[53];
    b[0] = p->w[54];
    b[1] = p->w[55];
    b[2] = p->w[56];
    b[3] = p->w[57];
    b[4] = p->w[58];
    b[5] = p->w[59];
    fn_1_49410();
    fn_1_494DC(42);
    fn_1_495B0(0x80000000);
    fn_1_4965C(0);
    v = p->w[60];
    fn_1_49514(&v);
    fn_1_4954C(p->f07);
    fn_1_495C8(9);
    switch (lbl_1_data_341B8->unk_4) {
    case 0:
    case 5:
        fn_1_496FC(p->f08, p->f09);
        fn_1_4AF10((const char *)a[8][lbl_801A66B4]);
        fn_1_496FC(p->f08, p->f10);
        fn_1_4AF10((const char *)a[7][lbl_801A66B4]);
        fn_1_496FC(p->f11, p->f12);
        fn_1_4AF10((const char *)a[6][lbl_801A66B4]);
        if (lbl_1_data_341B8->unk_5 == 1 && lbl_1_data_341B8->unk_4 != 5) {
            fn_1_496FC(p->f11, p->f12);
            fn_1_4A0D8((const char *)a[4][lbl_801A66B4]);
        }
        fn_1_496FC(p->f13, p->f12);
        fn_1_4AF10((const char *)a[5][lbl_801A66B4]);
        if (lbl_1_data_341B8->unk_5 != 1 && lbl_1_data_341B8->unk_4 != 5) {
            fn_1_496FC(p->f13, p->f12);
            fn_1_4A0D8((const char *)a[3][lbl_801A66B4]);
        }
        break;
    case 4:
        fn_1_496FC(p->f08, p->f09);
        fn_1_4AF10((const char *)a[2][lbl_801A66B4]);
        fn_1_496FC(p->f08, p->f10);
        if (lbl_1_data_341B8->unk_5 == 1) {
            fn_1_4AF10((const char *)a[1][lbl_801A66B4]);
        } else {
            fn_1_4AF10((const char *)a[0][lbl_801A66B4]);
        }
        if (lbl_801A66B4 != 5) {
            fn_1_496FC(p->f08, p->f12);
            fn_1_4AF10((const char *)b[lbl_801A66B4]);
        }
        break;
    case 1:
        break;
    }
}
