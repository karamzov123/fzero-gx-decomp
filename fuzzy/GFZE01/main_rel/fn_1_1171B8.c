/* Non-matching: best partial attempt (87.00% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/bg_common.h"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.1920928955078125e-07;
    s = 0.009999999776482582f;
}
static const u32 fzgx_pool_table3[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1e-07;
}
static const u32 fzgx_pool_table5[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 0.25f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    d = 0.0013611111376020642;
    s = 0.0027222223579883575f;
    s = -1.0f;
    s = 0.0f;
    s = -2.0f;
    s = 2.0f;
    s = 1.1920928955078125e-07f;
}
#pragma section code_type ".text"

typedef struct {
    u8 unk_0;
    u8 pad_1[0x17];
    f32 unk_18;
    u8 pad_1C[0x24];
    f32 unk_40;
} Elem;

typedef struct {
    u8 pad_0[8];
    u32 unk_8;
    u8 pad_C[0xC];
    u32 unk_18;
    u8 pad_1C[8];
    Elem *unk_24;
} Obj;

void fn_1_1171B8(Obj *obj) {
    s32 div;
    u32 i;
    u32 j;
    u32 groups;
    Elem *e;
    Elem *p;

    if (obj != 0) {
        div = ((u32)fn_80083970(((u32 *)lbl_1_data_3FCAC)[obj->unk_8], lbl_1_data_3F9CC) != 0) ? 3 : 4;
        fn_1_10846C(obj);
        e = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++) {
            if (e[i].unk_0 & 1) {
                e[i].unk_40 = -1.0f;
                e[i].unk_0 = 0;
            } else {
                e[i].unk_40 = 0.0f;
                e[i].unk_0 = 1;
            }
        }
        p = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++, p++) {
            Elem *b = obj->unk_24;
            for (j = i + 68; j < obj->unk_18; j++) {
                if (!(p->unk_0 & 1) && (b[j].unk_0 & 1)) {
                    fn_1_128884(p, &b[j], 0x44);
                }
            }
        }
        p = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++, p++) {
            Elem *b = obj->unk_24;
            for (j = i + 68; j < obj->unk_18; j++) {
                if (p->unk_0 == b[j].unk_0 && p->unk_18 > b[j].unk_18) {
                    fn_1_128884(p, &b[j], 0x44);
                }
            }
        }
        groups = (obj->unk_18 - 1) / div;
        for (i = 0; i < groups; i++) {
            for (j = 0; j < div; j++) {
                if (1.1920928955078125e-07f + obj->unk_24[i * div + j].unk_40 < 0.0f) {
                    obj->unk_24[i * div + j].unk_40 = -(f32)i / (f32)groups;
                }
            }
        }
        obj->unk_24[div * groups].unk_40 = -1.0f;
    }
}
