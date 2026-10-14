/* Non-matching: best partial attempt (93.09% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#include "rel/customize/editor.h"

extern f32 lbl_8006D188(u32);
extern int fn_1_4F734(FontDrawPacket *);
extern u32 lbl_801A66A0;
extern FontDrawPacket lbl_1_rodata_26F8;
extern void fn_1_49410(void);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);

#pragma opt_loop_invariants off
void fn_3_17854(void) {
    Obj_3_bss_A2410 *p_lbl_3_bss_A2410;
    Obj_3_data_35C0 *p_lbl_3_data_35C0;
    u32 lab_v;
    s32 v0, v1;
    f32 v2, v3, v4, v5, v6, v8, v9, v10, v11, v12;
    f32 v13, v14, v15, v17, v18, v19, v20;
    u32 v7, v16, v21;
    u8 *v24, *v26;
    u32 v25;
    f32 v27, v29;
    u32 v31, v33;
    u16 v32, v35;
    f32 v34, v36, v38;
    s32 v39;
    f32 v40, v41;
    u16 v42, v43, v44;
    u8 v46, v80, v81, v91, v93;
    s32 v47;
    u32 v51;
    f32 v52, v55;
    u8 v53;
    s32 v58, v60, v61;
    f32 v62, v63, v64;
    u8 v65;
    u32 v66;
    f32 v67, v68, v71, v73, v74, v75, v76;
    s32 v77;
    u32 v82, v83;
    f32 v84, v85, v86, v87, v88, v89, v96, v97;
    s32 v92;
    u32 v94;
    FontDrawPacket loc_8;
    f32 t8, t10;
    p_lbl_3_bss_A2410 = &lbl_3_bss_A2410;
    p_lbl_3_data_35C0 = &lbl_3_data_35C0;
    if ((p_lbl_3_bss_A2410->unk_8 & 0x80000000) != 0) {
        v0 = p_lbl_3_bss_A2410->unk_18 + 1;
        p_lbl_3_bss_A2410->unk_18 = v0 < 0 ? 0 : v0 > 10 ? 10 : v0;
    } else {
        v1 = p_lbl_3_bss_A2410->unk_18 - 1;
        p_lbl_3_bss_A2410->unk_18 = v1 < 0 ? 0 : v1 > 10 ? 10 : v1;
    }
    p_lbl_3_bss_A2410 = &lbl_3_bss_A2410;
    v2 = 0.1f + p_lbl_3_bss_A2410->unk_1C;
    v3 = v2 < 0.0f ? 0.0f : v2 > 1.0f ? 1.0f : v2;
    p_lbl_3_bss_A2410->unk_1C = v3;
    loc_8 = lbl_1_rodata_26F8;
    v4 = 456.0f; v5 = 86.0f;
    loc_8.image = 0x8609;
    loc_8.x = v4; loc_8.y = v5; loc_8.z = 75.0f; loc_8.flags = 5;
    fn_1_4F734(&loc_8);
    loc_8 = lbl_1_rodata_26F8;
    p_lbl_3_bss_A2410 = &lbl_3_bss_A2410;
    v6 = 474.0f; v7 = 0x860B; v8 = 141.0f; v9 = 60.0f;
    v10 = (f32)(s32)p_lbl_3_bss_A2410->unk_18;
    loc_8.image = v7;
    loc_8.x = v6; loc_8.y = v8; loc_8.z = v9;
    loc_8.color[0] = 255; loc_8.color[1] = 242; loc_8.color[2] = 0; loc_8.color[3] = 255;
    v11 = v10 / 10.0f;
    v12 = v11 < 0.0f ? 0.0f : v11 > 1.0f ? 1.0f : v11;
    loc_8.alpha = v12; loc_8.flags = 5;
    fn_1_4F734(&loc_8);
    loc_8 = lbl_1_rodata_26F8;
    v13 = 474.0f; v14 = 294.0f; v15 = 60.0f; v16 = 0x860A;
    v17 = (f32)(s32)p_lbl_3_bss_A2410->unk_18; v18 = 1.0f;
    loc_8.image = v16; loc_8.x = v13; loc_8.y = v14; loc_8.z = v15;
    loc_8.color[0] = 255; loc_8.color[1] = 242;
    v19 = v18 - v17 / 10.0f;
    loc_8.color[2] = 0; loc_8.color[3] = 255;
    v20 = v19 < 0.0f ? 0.0f : v19 > v18 ? v18 : v19;
    loc_8.alpha = v20; loc_8.flags = 5;
    fn_1_4F734(&loc_8);
    loc_8 = lbl_1_rodata_26F8;
    v21 = p_lbl_3_bss_A2410->unk_8;
    loc_8.image = 0x8634; loc_8.x = 564.0f; loc_8.y = 91.0f; loc_8.z = 40.0f;
    if ((__rlwnm(v21, 32 - ((32-2)), 31, 31))) {
        if (!((__rlwnm(v21, 32 - ((32-3)), 31, 31)))) {
            v24 = (u8 *)p_lbl_3_data_35C0;
            v25 = lbl_3_bss_A2410.unk_C << 2;
            v26 = v24 + v25;
            v27 = p_lbl_3_bss_A2410->unk_1C;
            v29 = 1.0f - v27;
    lab_v = lbl_3_bss_A2410.unk_0;
            loc_8.color[0] = (s32)((f32)((f32)(u32)lab_v * v29) + (f32)(v27 * (f32)(u32)v24[v25]));
            loc_8.color[1] = (s32)((f32)((f32)(u32)lbl_3_bss_A2410.unk_1 * v29) + (f32)(v27 * (f32)(u32)v26[1]));
            loc_8.color[2] = (s32)((f32)((f32)(u32)lbl_3_bss_A2410.unk_2 * v29) + (f32)(v27 * (f32)(u32)v26[2]));
        } else { goto blend; }
    } else {
blend:
        if (p_lbl_3_bss_A2410->unk_8 & 0xA0000000) {
            v31 = lab_v; v32 = lbl_3_bss_A2410.unk_10; v33 = lbl_3_bss_A2410.unk_1;
            v34 = p_lbl_3_bss_A2410->unk_1C; v35 = lbl_3_bss_A2410.unk_12; v36 = 1.0f - v34;
            v38 = (f32)(u32)lbl_3_bss_A2410.unk_2 * v36;
            v39 = (s32)((f32)((f32)(u32)v31 * v36) + (f32)((f32)(u32)v32 * v34));
            loc_8.color[3] = 255; loc_8.color[0] = v39;
            loc_8.color[1] = (s32)((f32)((f32)(u32)v33 * v36) + (f32)((f32)(u32)v35 * v34));
            loc_8.color[2] = (s32)(v38 + (f32)((f32)(u32)lbl_3_bss_A2410.unk_14 * v34));
        }
    }
    loc_8.flags = 5; fn_1_4F734(&loc_8);
    loc_8.x = 587.0f; loc_8.flags |= 0x80000; fn_1_4F734(&loc_8);
    loc_8 = lbl_1_rodata_26F8;
    v40 = 565.0f; p_lbl_3_bss_A2410 = &lbl_3_bss_A2410; v41 = 152.0f;
    v42 = p_lbl_3_bss_A2410->unk_10; v43 = p_lbl_3_bss_A2410->unk_12; v44 = p_lbl_3_bss_A2410->unk_14;
    loc_8.image = 0x860D; loc_8.x = v40; loc_8.y = v41; loc_8.z = 50.0f;
    loc_8.color[0] = v42; loc_8.color[1] = v43; loc_8.color[2] = v44; loc_8.color[3] = 255;
    loc_8.flags = 5; fn_1_4F734(&loc_8);
    loc_8.x = 585.0f; loc_8.flags |= 0x80000; fn_1_4F734(&loc_8);
    loc_8 = lbl_1_rodata_26F8; loc_8.image = 0x8600;
    p_lbl_3_bss_A2410 = &lbl_3_bss_A2410;
    for (v46 = 0; v46 < 3; v46++) {
        v47 = ((u16 *)&p_lbl_3_bss_A2410->unk_10)[v46] * 124;
        loc_8.z = 50.0f; loc_8.flags = 5;
        loc_8.y = (f32)(s32)(v46 * 40 + 203);
        loc_8.x = (f32)(s32)(v47 / 255 + 479);
        fn_1_4F734(&loc_8);
    }
    if (p_lbl_3_bss_A2410->unk_8 & 0x40000000) {
        loc_8 = lbl_1_rodata_26F8;
        v51 = lbl_801A66A0; v52 = 40.0f; v53 = lbl_3_bss_A2410.unk_C; v55 = 65535.0f;
        v58 = (s32)v53 % 4; v60 = v58 / 2; v61 = v58 * 33;
        loc_8.image = 0x8635; v62 = (f32)(s32)((v53 >> 2) * 24 + 297);
        loc_8.z = v52; loc_8.x = (f32)(s32)(((v60) + ((474) + (v61)))); loc_8.y = v62;
        v63 = 0.5f; v64 = lbl_8006D188((s32)(v55 * (f32)(u32)(v51 % 60) / 120.0f)) * v63;
        loc_8.flags = 5; loc_8.alpha = 1.0f - v64; fn_1_4F734(&loc_8);
    }
    if (p_lbl_3_bss_A2410->unk_8 & 0x80000000) {
        p_lbl_3_bss_A2410 = &lbl_3_bss_A2410; v65 = p_lbl_3_bss_A2410->unk_C;
        if (v65 < 3) {
            loc_8 = lbl_1_rodata_26F8;
            v66 = lbl_801A66A0; v67 = 472.0f; v68 = 40.0f; v71 = 65535.0f;
            v73 = (f32)(s32)(v65 * 40 + 186);
            loc_8.image = 0x8636; loc_8.x = v67; v74 = v71 * (f32)(u32)(v66 % 60);
            loc_8.y = v73; loc_8.z = v68; t10 = lbl_8006D188((s32)(v74 / 120.0f));
            v75 = 0.5f; v76 = t10 * v75; loc_8.flags = 5; loc_8.alpha = 1.0f - v76;
            fn_1_4F734(&loc_8);
            v77 = p_lbl_3_bss_A2410->unk_C * 40; loc_8.x = 544.0f; loc_8.flags |= 0x80000;
            loc_8.y = (f32)(s32)(v77 + 186); fn_1_4F734(&loc_8);
        }
    }
    loc_8 = lbl_1_rodata_26F8; loc_8.image = 0x863A;
    for (v80 = 0; v80 < 4; v80++) {
        for (v81 = 0; v81 < 4; v81++) {
            v82 = v81; v83 = v81 >> 1; v84 = (f32)(s32)(((v82 * 33) + ((v83) + (482))));
            loc_8.x = v84; loc_8.z = 40.0f; loc_8.y = (f32)(s32)(v80 * 24 + 303);
            loc_8.scale_x = 3.0f; loc_8.scale_y = 1.5f; loc_8.flags = 5;
            *(u32 *)loc_8.color = ((u32 *)p_lbl_3_data_35C0)[v82 + v80 * 4];
            fn_1_4F734(&loc_8);
        }
    }
    fn_1_49410(); fn_1_4954C(30.0f); fn_1_496FC(484.0f,174.0f); fn_1_495C8(0);
    v85 = 0.5f; fn_1_4955C(v85,v85); fn_1_495B0(0x80000000);
    fn_1_4AE0C((char *)p_lbl_3_data_35C0 + 64,p_lbl_3_bss_A2410->unk_10);
    fn_1_49410(); fn_1_4954C(30.0f); fn_1_496FC(484.0f,215.0f);
    v86 = 0.5f; fn_1_4955C(v86,v86); fn_1_495C8(0); fn_1_495B0(0x80000000);
    fn_1_4AE0C((char *)p_lbl_3_data_35C0 + 72,p_lbl_3_bss_A2410->unk_12);
    fn_1_49410(); fn_1_4954C(30.0f); fn_1_496FC(484.0f,255.0f); fn_1_495B0(0x80000000); fn_1_495C8(0);
    v87 = 0.5f; fn_1_4955C(v87,v87);
    fn_1_4AE0C((char *)p_lbl_3_data_35C0 + 80,p_lbl_3_bss_A2410->unk_14);
    v88 = 30.0f; v89 = 0.5f; loc_8.image = 0x863A; loc_8.z = v88;
    loc_8.scale_x = v89; loc_8.scale_y = 1.5f; loc_8.flags = 5;
    for (v91 = 0; v91 < 3; v91++) {
        v92 = v91; loc_8.y = (f32)(s32)(v92 * 40 + 191);
        for (v93 = 0; v93 < 31; v93++) {
            v94 = v93; loc_8.x = (f32)(s32)(v93 * 4 + 482);
            switch (v92) {
            case 0: loc_8.color[0] = (v94 & 31) << 3; loc_8.color[1] = p_lbl_3_bss_A2410->unk_12; loc_8.color[2] = p_lbl_3_bss_A2410->unk_14; break;
            case 1: loc_8.color[0] = p_lbl_3_bss_A2410->unk_10; loc_8.color[1] = (v94 & 31) << 3; loc_8.color[2] = p_lbl_3_bss_A2410->unk_14; break;
            case 2: loc_8.color[0] = p_lbl_3_bss_A2410->unk_10; loc_8.color[1] = p_lbl_3_bss_A2410->unk_12; loc_8.color[2] = (v94 & 31) << 3; break;
            }
            fn_1_4F734(&loc_8);
        }
    }
    loc_8 = lbl_1_rodata_26F8; v96 = 594.0f; v97 = 92.0f; loc_8.image = 0x8601;
    loc_8.x = v96; loc_8.y = v97; loc_8.z = 30.0f; loc_8.flags = 5; fn_1_4F734(&loc_8);
}
#pragma opt_loop_invariants reset

