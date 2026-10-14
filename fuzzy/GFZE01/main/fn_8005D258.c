/* Non-matching: best partial attempt (95.31% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dol/globals.h"

extern const f32 lbl_801A7240;
extern const f32 lbl_801A7250;
extern const f32 lbl_801A7254;
extern const f32 lbl_801A7258;
extern const f64 lbl_801A7238;
extern const f64 lbl_801A7248;
extern f32 fn_80088578(f32);
typedef struct Entry { u32 a, b, ptr, d; } Entry;
typedef struct Pitch { u8 pad[0x5A54]; s16 value; } Pitch;

#pragma opt_lifetimes off
#pragma opt_dead_assignments off
s32 fn_8005D258(u32 arg0, u32 arg1, u32 arg2, u32 arg3, f32 *arg4, s16 *arg5) {
    u32 v0;
    u32 v1;
    f32 v2;
    s32 v18;
    u32 v4;
    u32 v5;
    u32 v14_2;
    s32 v6;
    f32 v7;
    f32 v8;
    u32 v9;
    f32 v10;
    f32 v11;
    s32 v12;
    f32 v13;
    u32 v14;
    s16 v15;
    u32 v16;
    s16 v17;
    u32 v3;
    v4 = lbl_801A6C80 + (*(u8 *)(lbl_801A6C80 + 0x45B) << 4);
    v0 = *(u32 *)(v4 + 8);
    v1 = arg0;
    if (v0 != 0) {
    v1 = *(u8 *)((u8 *)v1 + 6);
    v3 = arg3 & 0xFF;
    v4 = *(u32 *)((u8 *)v0 + 32);
    v1 = (v1 << 7);
    v1 = (v0 + v1);
    v5 = ((((v4) + (v1)) + (4)));
    v6 = 0;
    while ((u8)v6 < (u8)arg3) {
    v5++;
    v6++;
    }
    v1 = *(u8 *)v5;
    if (v1 != 0) {
    v7 = (f32)(lbl_801A7238 * fn_80088578((f32)v1 / lbl_801A7250));
    } else {
    v7 = lbl_801A7258;
    }
    v1 = *(u8 *)((u8 *)arg1 + 9);
    v8 = v7;
    if (v1 != 0) {
    v8 = v8 + (f32)(lbl_801A7238 * fn_80088578((f32)v1 / lbl_801A7250));
    } else {
    v8 = lbl_801A7258;
    }
    v9 = ((arg2 & 0xFF) << 5);
    v1 = (lbl_801A6C80 + v9);
    v1 = *(u8 *)((u8 *)v1 + 1423);
    v10 = v8;
    if (v1 != 0) {
    v10 = v10 + (f32)(lbl_801A7238 * fn_80088578((f32)v1 / lbl_801A7240));
    } else {
    v10 = lbl_801A7258;
    }
    v1 = (lbl_801A6C80 + v9);
    v1 = *(u8 *)((u8 *)v1 + 1432);
    v11 = v10;
    if (v1 != 0) {
    v11 = v11 + (f32)(lbl_801A7238 * fn_80088578((f32)v1 / lbl_801A7240));
    } else {
    v11 = lbl_801A7258;
    }
    v1 = (lbl_801A6C80 + v9);
    v12 = v9;
    v13 = v11;
    if ((*(u8 *)((u8 *)v1 + 1417) & 0x1) != 0) {
    v1 = (lbl_801A6C80 + (*(u8 *)(lbl_801A6C80 + 0x45B) << 1));
    v12 = *(s16 *)((u8 *)v1 + 23124);
    } else {
    v1 = (lbl_801A6C80 + (*(u8 *)(lbl_801A6C80 + 0x45B) << 4));
    v1 = *(u8 *)((u8 *)v1 + 1169);
    if (v1 != 0) {
    v13 = v13 + (f32)(lbl_801A7238 * fn_80088578((f32)v1 / lbl_801A7240));
    } else {
    v13 = lbl_801A7258;
    }
    v1 = lbl_801A6C80;
    v14 = (*(u8 *)((u8 *)v1 + 1115) << 1);
    v1 = (v1 + v14);
    v12 = *(s16 *)((u8 *)v1 + 23092);
    }
    v1 = lbl_801A6C80;
    v1 = *(u8 *)((u8 *)v1 + 1121);
    if (v1 != 0) {
    v2 = v13 + (f32)(lbl_801A7238 * fn_80088578((f32)v1 / lbl_801A7240));
    } else {
    v2 = lbl_801A7258;
    }
    v1 = lbl_801A6C80;
    v15 = *(s16 *)((u8 *)v1 + 23056);
    *(f32 *)arg4 = v2;
    v12 = v12 + v15;
    *(s16 *)arg5 = v12;
    v12 += (s32)(lbl_801A7254 * v2);
    if ((s16)v12 < -960) {
    v12 = -960;
    }
    v1 = v12;
    } else {
    v1 = -960;
    *(f32 *)arg4 = lbl_801A7258;
    *arg5 = -960;
    }
    return v1;
}
#pragma opt_dead_assignments reset

#pragma opt_lifetimes reset

