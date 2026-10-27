/* Non-matching: best partial attempt (87.63% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/sel/sel.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} SelVec3;

typedef struct {
    u8 pad_0[0x12];
    s8 unk_12;
    u8 pad_13[1];
} SelObj14;

typedef struct {
    u8 pad_0[0xE];
    s16 val;
    u8 pad_10[0x10];
} SelSpawnEnt;

typedef struct {
    u8 pad_0[4];
    u32 val;
} SelRow;

extern const f64 lbl_10_rodata_158[24];
extern SelSpawnEnt lbl_1_bss_8B3A0[];
extern f32 lbl_8006D188(u32);
extern s16 fn_10_0(s16 *, s16 *, int, int);
extern void fn_1_13198C(s16, SelVec3, SelVec3, void *, void *, s32);

s32 fn_10_1A760(Obj_10_bss_1C *p) {
    const f64 *pool = lbl_10_rodata_158;
    SelVec3 b;
    SelVec3 a;
    s16 j;
    s16 i;
    SelRow *row;
    u32 v;

    b.x = pool[0xb90 / 8] * -lbl_8006D188(0xeee);
    b.y = ((const f32 *)pool)[0xb98 / 4];
    b.z = pool[0xb90 / 8] * -lbl_8006D188(0x4eee);
    a.x = ((const f32 *)pool)[0xb9c / 4];
    a.y = b.y;
    a.z = ((const f32 *)pool)[0x4c / 4];

    if (((SelObj14 *)(void *)&lbl_10_bss_5560C)[p->unk_0].unk_12 == 4) {
        fn_10_0(&j, &i, lbl_1_bss_8B3A0[p->unk_0].val, 0);
        row = (SelRow *)((u8 *)&lbl_10_bss_1C + i * 0x98 + j * 8);
        v = row->val;
        fn_1_13198C(p->unk_0, b, a, lbl_10_bss_51B7C, lbl_10_bss_52EFC, (s32)(v >> 31));
    }
    return 0;
}
