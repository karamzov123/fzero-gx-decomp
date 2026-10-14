/* Non-matching: best partial attempt (45.93% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/accessory.h"

struct fn_1_11BFCC_Copy68 { u32 a[17]; };
extern f32 lbl_1_rodata_7B1C;
extern f32 lbl_1_rodata_7B20;
extern f64 lbl_1_rodata_7B08;
extern u32 fn_1_10846C(u32);
extern void fn_1_128884(void *, void *, int);
extern u32 fn_1_4630(u32, u32, u32);
extern f32 fn_1_1289BC(const void *, const void *);

void fn_1_11BFCC(u32 arg0, f32 arg1, u32 arg2) {
    u32 i, j, k;
    u8 *base;
    struct fn_1_11BFCC_Copy68 loc_8;
    u32 x;
    u32 y;
    u32 *table;
    u32 idx;
    u32 row;
    u32 col;
    u32 n;
    u32 cnt;
    u32 *p;
    u32 *q;
    f32 f;
    u8 *left;
    u8 *right;
    u8 *src;
    u8 *dst;
    u32 heads[8][17];
    u32 tails[8][17];
    if (arg0 != 0) {
        fn_1_10846C(arg0);
        base = *(u8 **)((u8 *)arg0 + 36);
        n = *(u32 *)((u8 *)arg0 + 24);
        for (i = 0; i < n; i++) {
            if ((base[i * 68] & 1) != 0) {
                *(f32 *)(base + i * 68 + 64) = lbl_1_rodata_7B1C;
                base[i * 68] = 0;
            } else {
                *(f32 *)(base + i * 68 + 64) = lbl_1_rodata_7B20;
                base[i * 68] = 1;
            }
        }
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (*(f32 *)(base + i * 68 + 16) > *(f32 *)(base + j * 68 + 16))
                    fn_1_128884(base + i * 68, base + j * 68, 68);
            }
        }
        n = *(u32 *)((u8 *)arg0 + 24);
        base = *(u8 **)((u8 *)arg0 + 36);
        for (i = 0; i < n / 8; i++) {
            for (j = 0; j < 8; j++) {
                for (k = j + 1; k < 8; k++) {
                    if (*(f32 *)(base + i * 544 + j * 68 + 20) < *(f32 *)(base + i * 544 + k * 68 + 20))
                        fn_1_128884(base + i * 544 + j * 68, base + i * 544 + k * 68, 68);
                }
            }
            loc_8 = *(struct fn_1_11BFCC_Copy68 *)(base + i * 544);
            for (j = 0; j < 8; j++) {
                if (*(f32 *)(base + i * 544 + (j + 1) * 68 + 24) > 0.0f) {
                    *(struct fn_1_11BFCC_Copy68 *)&heads[j][0] =
                        *(struct fn_1_11BFCC_Copy68 *)(base + i * 544 + (j + 1) * 68);
                } else {
                    *(struct fn_1_11BFCC_Copy68 *)&tails[j][0] =
                        *(struct fn_1_11BFCC_Copy68 *)(base + i * 544 + (j + 1) * 68);
                }
            }
            for (j = 0; j < 8; j++) {
                *(struct fn_1_11BFCC_Copy68 *)(base + i * 544 + j * 68) =
                    *(struct fn_1_11BFCC_Copy68 *)&loc_8;
            }
        }
    }
}
