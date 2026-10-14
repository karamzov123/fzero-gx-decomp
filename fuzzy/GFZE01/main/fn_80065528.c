/* Non-matching: best partial attempt (78.65% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dol/globals.h"

extern u32 fn_8006331C(u32, u32);
extern void fn_80064FDC(u8, u8 *);

#pragma opt_propagation off
void fn_80065528(u32 arg0) {
    u32 v0, v1, v2, v3, v4, v5, v6;
    u32 v9, v10;
    u8 v11;
    u16 v12;
    u8 *v13;
    u8 v14;
    u32 v15;
    s32 v16;
    u32 v17, v18;
    u8 v19;
    u32 v20, v21;
    u8 v22;
    u8 v7;
    u32 v8;
    u32 v23;
    u8 v24;
    u8 v25;
    u32 v26;
    u8 v27;
    u32 v28;
    v0 = *(u32 *)((u8 *)lbl_801A6C80 + 0x444);
    v1 = (v0 & 0xF) << 4;
    v2 = v0 & 0xF;
    v3 = lbl_801A6C80 + v1;
    v4 = (v0 >> 8) & 0xFF;
    v5 = *(u32 *)(v3 + 8);
    if (v5 != 0 && (v4 != *(u8 *)(v3 + 0x490) || arg0 != 0)) {
        v10 = v5 + 0x3c;
        v6 = *(u32 *)(v5 + 0x18);
        v9 = v5 + v6;
        v6 = (s32)*(u16 *)(v5 + 0x3c) >> 8;
        if (v4 > v6 - 1) return;
        v11 = 0;
        while (v11 <= v4 + 1) {
            v10 += 2;
            v11++;
        }
        v12 = *(u16 *)v10;
        if (v12 == 0) return;
        v13 = (u8 *)(v9 + v12);
        *(u8 **)((u8 *)lbl_801A6C80 + v1 + 0x488) = v13;
        *(u8 *)((u8 *)lbl_801A6C80 + v1 + 0x490) = v4;
        v14 = v13[1];
        if (v14 != 0x80) {
            *(u8 *)((u8 *)lbl_801A6C80 + v1 + 0x492) = v14;
        }
        v15 = (u8)v2 << 6;
        v16 = 0;
        while ((v16 & 0xff) < 16) {
            v17 = v15 + ((v16 & 0xff) << 2);
            v6 = 0;
            while ((u8)v6 < 4) {
                v18 = (u8)v6;
                v19 = *(u8 *)(v17 + (lbl_801A6C80 + v18 + 0xd88));
                if (v19 != 255) {
                    v20 = v19 << 5;
                    v21 = lbl_801A6C80 + v20;
                    v22 = 0;
                    if ((*(u8 *)(v21 + 0x589) & 1) == 0) v22 = 1;
                    if (v22 != 0) {
                        u32 a = v20 + 0x589;
                        u32 b = v20 + 0x5a0;
                        u32 c = v20 + 0x5a4;
                        u32 d = v20 + 0x58a;
                        u32 e = v20 + 0x599;
                        u32 f = v20 + 0x59a;
                        u32 g = v20 + 0x59b;
                        u32 h = v20 + 0x59c;
                        u32 i = v20 + 0x59d;
                        v7 = 0;
                        *(u8 *)(v21 + 0x588) = v7;
                        *(u8 *)((u8 *)lbl_801A6C80 + a) = v7;
                        *(u32 *)((u8 *)lbl_801A6C80 + b) = v7;
                        *(u32 *)((u8 *)lbl_801A6C80 + c) = v7;
                        *(u8 *)((u8 *)lbl_801A6C80 + d) = v7;
                        *(u8 *)((u8 *)lbl_801A6C80 + e) = 64;
                        *(u8 *)((u8 *)lbl_801A6C80 + f) = v7;
                        *(u8 *)((u8 *)lbl_801A6C80 + g) = v7;
                        *(u8 *)((u8 *)lbl_801A6C80 + h) = v7;
                        *(u8 *)((u8 *)lbl_801A6C80 + i) = v7;
                        v18 = lbl_801A6C80 + v18;
                        v18 += 0xd88;
                        *(u8 *)(v17 + v18) = 255;
                    }
                }
                v6++;
            }
            v16++;
        }
        fn_80064FDC(v2, v13);
        fn_8006331C(v13[3], v13[4]);
    } else if (v5 != 0) {
        v8 = v2 << 6;
        v7 = 0;
        while (v7 < 16) {
            v23 = v8 + (v7 << 2);
            v24 = 0;
            while (v24 < 4) {
                v6 = lbl_801A6C80 + v24;
                v25 = *(u8 *)(v23 + v6 + 0xd88);
                if (v25 != 255) {
                    v26 = v25 << 5;
                    v6 = lbl_801A6C80 + v26;
                    v27 = 0;
                    if ((*(u8 *)(v6 + 0x589) & 1) == 0) v27 = 1;
                    if (v27 != 0) {
                        *(u8 *)(v6 + 0x58a) = 0;
                        *(u8 *)(lbl_801A6C80 + (v26 + 0x599)) = 64;
                        *(u8 *)(lbl_801A6C80 + (v26 + 0x59a)) = 0;
                        *(u8 *)(lbl_801A6C80 + (v26 + 0x59b)) = 0;
                        *(u8 *)(lbl_801A6C80 + (v26 + 0x59c)) = 0;
                        *(u8 *)(lbl_801A6C80 + (v26 + 0x59d)) = 0;
                    }
                }
                v24++;
            }
            v7++;
        }
    }
}
