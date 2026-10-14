/* Non-matching: best partial attempt (97.18% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"

extern u32 lbl_801A63C0;
extern u32 OSGetTick(void);

static inline s32 random_value(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

void fn_1_F85A0(Obj_1_bss_7F0C0 *arg0, u8 *arg1) {
    u32 v30;
    u32 v3;
    u8 loc_8[32];
    u32 v19;
    u32 t0;
    u8 v20;
    u8 unk_1;
    u32 v0;
    u8 *v44;
    u8 *v45;
    u8 *v42;
    u8 v18;
    t0 = OSGetTick();
    v0 = (t0 >> 14) + (t0 << 18);
    lbl_801A63C0 = v0 ^ 0xCAE87FB5;
    {
    u32 fzgx_loop_v3_551;
for (fzgx_loop_v3_551 = 0; fzgx_loop_v3_551 < 32; fzgx_loop_v3_551++) {
        loc_8[fzgx_loop_v3_551] = fzgx_loop_v3_551;
    }
    v3 = fzgx_loop_v3_551;
}
    v19 = lbl_801A63C0;
    {
    u32 fzgx_loop_v3_639;
for (fzgx_loop_v3_639 = 100; fzgx_loop_v3_639 != 0; fzgx_loop_v3_639--) {
        t0 = v19 * 0x676A4B6B + 0x33CB;
        v19 = t0;
        v18 = (s32)((v19 >> 16) & 0x7FFF) % 32;
        (void) v18;  /* fzgx: keeps the web at its definition */
        v19 = v19 * 0x676A4B6B + 0x33CB;
        v20 = (s32)((v19 >> 16) & 0x7FFF) % 32;
        unk_1 = (u8)(loc_8[v18]);
        loc_8[v18] = loc_8[v20];
        loc_8[v20] = unk_1;
    }
    v3 = fzgx_loop_v3_639;
}
    lbl_801A63C0 = v19;
    v30 = 4;
    for (v3 = 0; v3 < 32; v3++) {
        v30 += ((v0 & (1 << loc_8[v3])) >> loc_8[v3]) << v3;
    }
    *(u32 *)((u8 *)arg0 + 96) = v30;
    lbl_801A63C0 = v30 ^ 0xCAE87FB5;
    v42 = (u8 *)arg0 + 96;
    v44 = (u8 *)arg0;
    v45 = arg1;
    {
    u32 fzgx_loop_v3_1248;
for (fzgx_loop_v3_1248 = 0; fzgx_loop_v3_1248 < 21344; fzgx_loop_v3_1248++) {
        if (v44 < v42 || v42 + 4 <= v44) {
            *v45 = *v44 ^ (random_value() % 255 + 1);
        } else {
            *v45 = *v44;
        }
        v44++;
        v45++;
    }
    v3 = fzgx_loop_v3_1248;
}
}
