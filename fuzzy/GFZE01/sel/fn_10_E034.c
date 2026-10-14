/* Non-matching: best partial attempt (90.92% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/sel/sel.h"

typedef struct {
    u8 pad_0[4];
    s16 v4;
    s16 v6;
    s16 v8;
    u8 pad_a[0x9a];
    s16 *items;
} SelArgs;
typedef struct {
    s16 v0;
    u8 pad_2[0x92];
    u32 flags;
} SelState;
typedef struct { s16 h[8]; } Pair8;
typedef struct { u32 value; } SelColor;
extern SelState lbl_1_bss_8B3A0;
extern s16 lbl_1_bss_962;
extern s32 lbl_801A66B4;
extern const f32 lbl_10_rodata_158[19];
extern u32 fn_1_535A0(void *, f32, f32, f32, f32, f32, f32);
extern void fn_1_49514(u32 *);
extern void fn_1_4AE0C(const char *, ...);
extern int sprintf(char *, const char *, ...);
static inline s16 fn_10_E034_array_read(s16 *array, s32 index) { return array[index]; }
#pragma opt_lifetimes off
void fn_10_E034(SelArgs *a) {
    u32 tmp_call6;
    SelState *state = &lbl_1_bss_8B3A0;
    const f32 *pool = lbl_10_rodata_158;
    s16 idx = lbl_1_bss_962 - 0xe;
    SelColor t_case0;
    s16 sel = *(s16 *)((u8 *)a->items + idx * 0x94 + 0x14);
    u32 t_a;
    u32 t_b;
    u32 t_c;
    SelColor t_case1;
    SelColor t_case2;
    Pair8 arr;
    char buf[0x20];
    s16 i;
    f32 one;
    arr = *(Pair8 *)&pool[52];
    if ((lbl_1_bss_8B3A0.flags & 0x200) == 0) {
        return;
    }
    switch (lbl_1_bss_8B3A0.v0) {
    case 0:
        switch (sel) {
            case 0:
                one = pool[17];
                t_case0 = *(SelColor *)&pool[56];
                fn_1_535A0(&t_case0, pool[19], pool[62], one,
                           pool[63], pool[64], one);
                for (i = 0; i < 4; i++) {
                    t_a = *(u32 *)&pool[57];
                    fn_1_49514(&t_a);
                    if (i == a->v8) {
                        t_b = *(u32 *)&pool[58];
                        fn_1_49514(&t_b);
                    }
                    fn_1_4AE0C((const char *)&lbl_10_data_5E2C,
                               *(char **)((u8 *)&lbl_10_data_2CDC +
                                          fn_10_E034_array_read(arr.h, i) * 0x18 + lbl_801A66B4 * 4));
                    t_c = *(u32 *)&pool[59];
                    fn_1_49514(&t_c);
                }
                break;
            case 1:
                one = pool[17];
                t_case1 = *(SelColor *)&pool[60];
                fn_1_535A0(&t_case1, pool[19], pool[62], one,
                           pool[65], pool[66], one);
                sprintf(buf,
                        ((char **)((u8 *)&lbl_10_data_2CDC + 0x168))[lbl_801A66B4],
                        a->v4);
                fn_1_4AE0C((const char *)&lbl_10_data_5E2C, buf);
                break;
            case 2:
                one = pool[17];
                t_case2 = *(SelColor *)&pool[61];
                (void) t_case2;
                tmp_call6 = fn_1_535A0(&t_case2, pool[19], pool[62], one,
                           pool[67], pool[66], one);
                tmp_call6;
                sprintf(buf,
                        ((char **)((u8 *)&lbl_10_data_2CDC + 0x180))[lbl_801A66B4],
                        a->v6);
                fn_1_4AE0C((const char *)&lbl_10_data_5E2C, buf);
                break;
            }
        break;
    }
}
#pragma opt_lifetimes reset
