/* Non-matching: best partial attempt (97.87% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_C742C_Vec;

typedef struct {
    fn_1_C742C_Vec v[3][6];
} fn_1_C742C_TabA;

typedef struct {
    fn_1_C742C_Vec v[3][4];
} fn_1_C742C_TabB;

typedef void (*fn_1_C742C_Call3)(int, int, int);

typedef struct {
    fn_1_C742C_Call3 v[6];
} fn_1_C742C_Fn6;

typedef struct {
    s32 v[6];
} fn_1_C742C_Int6;

extern fn_1_C742C_Fn6 lbl_1_rodata_5A68;
extern u8 lbl_1_rodata_5A80[144];
extern u8 lbl_1_rodata_5B10[216];
extern fn_1_C742C_Int6 lbl_1_rodata_5BE8;
extern s32 camera_get_mode(void);
extern int fn_1_5910(void);
extern u32 fn_1_5348(void);
extern void fn_1_CFA4C(int, int);
extern s32 camera_get_state(void);
extern struct fn_1_CC280_lbl_1_rodata_5C00 lbl_1_rodata_5C00[];
extern f32 fn_1_519FC(f32);
extern void fn_1_52070(int);
extern void fn_1_52088(void);
extern void fn_1_CD51C(int);
extern u32 fn_1_C7AA0(void);
extern u16 fn_1_C7874(void);

static inline fn_1_C742C_Vec (* fn_1_C742C_read_pointer(fn_1_C742C_TabB * owner))[4] { return owner->v; }
void fn_1_C742C(void) {
    struct { u8 value; } mode;
    int idx;
    fn_1_C742C_TabB tabB;
    fn_1_C742C_TabA tabA;
    fn_1_C742C_Fn6 funcs;
    fn_1_C742C_Int6 ints;
    fn_1_C742C_Vec *pa;
    f32 sumx;
    f32 sumy;
    struct { int value; } grp;
    int i;
    fn_1_C742C_Vec *pv;

    funcs = lbl_1_rodata_5A68;
    tabB = *(fn_1_C742C_TabB *)&lbl_1_rodata_5A80;
    tabA = *(fn_1_C742C_TabA *)&lbl_1_rodata_5B10;
    ints = lbl_1_rodata_5BE8;
    (void) ints;  /* fzgx: keeps the web at its definition */

    mode.value = camera_get_mode();
    idx = fn_1_5910();
    if (mode.value == -1 || mode.value < 0) {
        pv = &tabB.v[2][idx];
        if (((fn_1_5348() >> 32) & 0xff) == 3) {
            fn_1_CFA4C((int)pv->x, (int)pv->y);
        }
        return;
    }

    switch ((s8)camera_get_state()) {
    case 1:
        grp.value = 0;
        break;
    case 2:
        grp.value = 1;
        break;
    case 6:
    case 7:
    case 8:
        grp.value = 2;
        break;
    default:
        return;
    }

    for (i = 0; i < 6; i++) {
        pa = &tabA.v[grp.value][i];
        sumx = pa->x + (*((grp.value) + (tabB.v)))[idx].x;
        sumy = pa->y + fn_1_C742C_read_pointer(&tabB)[grp.value][idx].y;
        fn_1_52070((int)fn_1_519FC((f32)ints.v[i]));
        funcs.v[i](mode.value, (int)sumx, (int)sumy);
        fn_1_52088();
    }
    fn_1_CD51C(mode.value);

    switch ((s8)camera_get_state()) {
    case 1:
        fn_1_C7AA0();
        break;
    case 2:
        fn_1_C7874();
        break;
    case 6:
    case 7:
    case 8:
        fn_1_C7AA0();
        fn_1_C7874();
        break;
    default:
        break;
    }
}
