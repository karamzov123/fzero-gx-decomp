/* Non-matching: best partial attempt (93.58% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef s32 (*fn_8000659C_Fn0)(void);
typedef u32 (*fn_8000659C_Fn1)(void);
typedef u32 (*fn_8000659C_Fn2)(void);
typedef u32 (*fn_8000659C_Fn3)(void);
typedef struct { void *image; u16 code; u16 width; } FontGlyph;
typedef struct { u8 **lines; s32 count; } Message;
extern const f32 lbl_801A6EE8;
extern const f64 lbl_801A6EB0, lbl_801A6EB8, lbl_801A6ED0, lbl_801A6ED8, lbl_801A6EE0;
extern int fn_80083BCC(const char *, const char *);
extern s16 lbl_801A66EC;
extern s32 DVDGetDriveStatus(void);
extern s32 fn_8006FDEC(void);
extern FontGlyph lbl_8015B940[];
extern u32 lbl_801A63F0, lbl_801A63F4;
extern u32 lbl_801A66DC, lbl_801A66E0, lbl_801A66E4, lbl_801A66E8;
extern Message *lbl_801A66F4;
extern u8 lbl_801A66D8;
extern void fn_80005EDC(void);
extern void fn_800060D8(u8 *, f32, f32, f32);
extern void fn_80007B68(void);
extern void fn_8006FD1C(void);
extern void fn_8006FEFC(void);

#pragma opt_common_subs off
static inline FontGlyph *find_glyph(s32 code) {
    struct { FontGlyph *value; } glyph;
    struct { s32 value; } i;
    glyph.value = lbl_8015B940;
    {
    s32 fzgx_loop_i_1012;
for (fzgx_loop_i_1012 = 0; fzgx_loop_i_1012 < lbl_801A66EC; fzgx_loop_i_1012++, glyph.value++) {
        if (glyph.value->code == code) return glyph.value;
    }
    i.value = fzgx_loop_i_1012;
}
    return NULL;
}
#pragma opt_common_subs reset


#pragma opt_propagation off
#pragma opt_common_subs off
void fn_8000659C(void) {
    s32 v6;
    s32 v3;
    u8 ** fzgx_live;
    Message *v11;
    s32 v15;
    u8 *v16;
    s32 v17;
    s32 v9;
    s32 v2;
    s32 v5;
    FontGlyph *glyph;
    if (lbl_801A66DC != 0 && ((fn_8000659C_Fn0)lbl_801A66DC)() != 0) return;
    v5 = -1;
    v2 = 0;
    do {
        if ((v3 = DVDGetDriveStatus()) != -1) {
            lbl_801A66D8 = 1;
            ((fn_8000659C_Fn1)lbl_801A66E0)();
            lbl_801A66D8 = 0;
        }
        switch (v3) {
        case 4: v5 = 1; break;
        case 5: v5 = 0; break;
        case 6: v5 = 2; break;
        case 11: v5 = 3; break;
        case -1: v5 = 4; break;
        default: if (v2 != 0) v5 = 5; break;
        case 0: v5 = -1; break;
        }
        if (v5 >= 0) {
            if (v2 == 0) {
                if (lbl_801A66E8 != 0) ((fn_8000659C_Fn2)lbl_801A66E8)();
                v2 = 1;
            }
            fn_80007B68();
            if (v5 >= 0) {
                fn_80005EDC();
                v6 = 0;
                v9 = v6;
                v11 = lbl_801A66F4 + v5;
#pragma fp_contract off
                for (; v6 < v11->count; v9 += 4, v6++) {
                    v15 = 0;
                    fzgx_live = v11->lines;
                    v16 = *(u8 **)((u8 *)fzgx_live + v9);
                    while (*v16 != 0) {
                        if (fn_80083BCC((char *)v16, (char *)&lbl_801A63F0) == 0) break;
                        if (fn_80083BCC((char *)v16, (char *)&lbl_801A63F4) == 0) break;
                        v17 = *v16;
                        if ((v17 >> 7) & 1) {
                            v17 = *(u16 *)v16;
                            v16 += 2;
                        } else v16++;
                        if ((u32)v17 == 32) {
                            v15 = (s32)(v15 + lbl_801A6EB8);
                        } else {
                            glyph = find_glyph(v17);
                            if (glyph != NULL) v15 += glyph->width;
                        }
                    }
                    fn_800060D8(*(u8 **)((u8 *)v11->lines + v9),
                        (f32)(lbl_801A6ED0 - lbl_801A6ED8 * v15),
                        (f32)(lbl_801A6EE0 - lbl_801A6ED8 * (lbl_801A6EB0 * v11->count) + lbl_801A6EB0 * v6),
                        lbl_801A6EE8);
                }
            }
            fn_8006FDEC();
            fn_8006FEFC();
            fn_8006FD1C();
        }
        if (v3 == 0) v17 = 1;
        else if (v2 == 0 && v3 == 1) v17 = 1;
        else v17 = 0;
    } while (v17 == 0);
    if (v2 != 0 && lbl_801A66E4 != 0) ((fn_8000659C_Fn3)lbl_801A66E4)();
}
#pragma opt_common_subs reset

#pragma opt_propagation reset
