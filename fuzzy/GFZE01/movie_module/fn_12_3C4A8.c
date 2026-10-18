/* Non-matching: best partial attempt (51.14% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_12_3C4A8_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
};
struct fn_12_3C4A8_Arg1 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u8 pad_14[0x4];
    u32 unk_18;
};

void fn_12_3C4A8(struct fn_12_3C4A8_Arg0 *arg0, struct fn_12_3C4A8_Arg1 *arg1, u32 arg2) {
    u32 v0;
    u32 v1;
    struct { unsigned int v2; unsigned int v26; } fzgx_copy_state;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    u32 v7;
    u32 v8;
    u32 v9;
    u32 v10;
    u32 v11;
    u32 v12;
    u32 v13;
    u32 v14;
    u32 v15;
    u32 v16;
    u32 v17;
    u32 v18;
    u32 v19;
    u32 v20;
    u32 v21;
    u32 v22;
    u32 v23;
    u32 v24;
    u32 v25;
    u32 v28;
    u32 v29;
    u32 v30;
    u32 v31;
    u32 v32;
    u32 v33;
    u32 v34;
    u32 v35;
    u32 v36;
    u32 v37;
    u32 v38;
    u32 v39;
    u32 v40;
    u32 v41;
    u32 v43;
    u32 v44;
    u32 v45;
    u32 v46;
    u32 v47;
    u32 v48;
    u32 v49;
    u32 v50;
    u32 v51;
    u32 v52;
    u32 v53;
    u32 v54;
    u32 v55;
    u32 v56;
    u32 row_end;
    u32 end_y;

    v0 = (arg2 + 1024);
    v1 = (v0 + 1024);
    fzgx_copy_state.v2 = ((arg0->unk_0 - 4) + (arg0->unk_C & ~0x3));
    v3 = (v1 + 1024);
    v4 = (arg0->unk_4 - 4);
    v5 = (arg0->unk_8 - 4);
    v6 = arg1->unk_C;
    if (arg1->unk_C == 0) {
        v6 = 640;
    }
    v7 = (arg0->unk_0 - 4);
    v8 = (arg1->unk_0 - 4);
    arg1->unk_C = v6;
    v9 = arg1->unk_18;
    if (arg1->unk_18 == 0) {
        v9 = 480;
    }
    arg1->unk_18 = v9;
    v10 = arg1->unk_C;
    v11 = arg0->unk_C;
    v12 = v8;
    if (arg0->unk_C > v10) {
        v11 = v10;
    } else {
        v12 = (v12 + ((v10 - arg1->unk_4) & 0x7FFFFFFC));
    }
    v13 = arg1->unk_18;
    v14 = arg1->unk_8;
    v15 = v12;
    if (arg1->unk_8 > v13) {
        v14 = v13;
    } else {
        v15 = (v15 + ((arg1->unk_C * (v13 - (v14 * arg1->unk_10))) & ~0x3));
    }
    v16 = arg1->unk_C;
    v17 = arg1->unk_10;
    v18 = (((((s32)arg0->unk_C / 4) << 1) - ((s32)v11 / 4)) << 2);
    v19 = (((s32)(arg0->unk_10 - ((s32)(((u32)v11 >> 31) + v11) >> 1)) / 4) << 2);
    v20 = (v15 + (((v16 * v17) << 1) & 0xFFFFFFFC));
    v21 = ((((v17 * (v16 << 1)) - v11) << 1) & 0xFFFFFFFC);
    v22 = v15;
    v23 = v20;
    v24 = v5;
    v25 = v4;
    fzgx_copy_state.v26 = fzgx_copy_state.v2;
    end_y = v15 + ((v17 * (((u32)v16 >> 1) * v14)) << 2);
    while (end_y > v22) {
        row_end = v22 + ((v11 << 1) & 0x7FFFFFFC);
        while (row_end > v22) {
            __dcbt((void *)v7, 0x20);
            v28 = *(u32 *)((u8 *)v7 + 4);
            v29 = *(u32 *)((u8 *)v25 + 4);
            v30 = *(u32 *)((u8 *)v24 + 4);
            v31 = *(u32 *)((u8 *)fzgx_copy_state.v26 + 4);
            v32 = (*(u32 *)((u8 *)v3 + (((u32)v30 >> 22) & 0x3FC)) | *(u32 *)((u8 *)v1 + (((u32)v29 >> 22) & 0x3FC)));
            v33 = (v32 | *(u32 *)((u8 *)arg2 + (((u32)v31 >> 22) & 0x3FC)));
            *(u32 *)((u8 *)v22 + 4) = (*(u32 *)((u8 *)v0 + (((u32)v28 >> 14) & 0x3FC)) | (v32 | *(u32 *)((u8 *)arg2 + (((u32)v28 >> 22) & 0x3FC))));
            *(u32 *)((u8 *)v23 + 4) = (*(u32 *)((u8 *)v0 + (((u32)v31 >> 14) & 0x3FC)) | v33);
            v34 = (*(u32 *)((u8 *)v3 + (((u32)v30 >> 14) & 0x3FC)) | *(u32 *)((u8 *)v1 + (((u32)v29 >> 14) & 0x3FC)));
            v35 = (v34 | *(u32 *)((u8 *)arg2 + (((u32)v31 >> 6) & 0x3FC)));
            *(u32 *)((u8 *)v22 + 8) = (*(u32 *)((u8 *)v0 + ((v28 & 0xFF) << 2)) | (v34 | *(u32 *)((u8 *)arg2 + (((u32)v28 >> 6) & 0x3FC))));
            *(u32 *)((u8 *)v23 + 8) = (*(u32 *)((u8 *)v0 + ((v31 & 0xFF) << 2)) | v35);
            v36 = *(u32 *)((u8 *)v7 + 8);
            v37 = *(u32 *)((u8 *)fzgx_copy_state.v26 + 8);
            fzgx_copy_state.v26 = (u32)((u8 *)fzgx_copy_state.v26 + 8);
            v38 = (*(u32 *)((u8 *)v3 + (((u32)v30 >> 6) & 0x3FC)) | *(u32 *)((u8 *)v1 + (((u32)v29 >> 6) & 0x3FC)));
            v39 = (v38 | *(u32 *)((u8 *)arg2 + (((u32)v37 >> 22) & 0x3FC)));
            *(u32 *)((u8 *)v22 + 12) = (*(u32 *)((u8 *)v0 + (((u32)v36 >> 14) & 0x3FC)) | (v38 | *(u32 *)((u8 *)arg2 + (((u32)v36 >> 22) & 0x3FC))));
            *(u32 *)((u8 *)v23 + 12) = (*(u32 *)((u8 *)v0 + (((u32)v37 >> 14) & 0x3FC)) | v39);
            v40 = (*(u32 *)((u8 *)v3 + ((v30 & 0xFF) << 2)) | *(u32 *)((u8 *)v1 + ((v29 & 0xFF) << 2)));
            v41 = (v40 | *(u32 *)((u8 *)arg2 + (((u32)v37 >> 6) & 0x3FC)));
            *(u32 *)((u8 *)v22 + 16) = (*(u32 *)((u8 *)v0 + ((v36 & 0xFF) << 2)) | (v40 | *(u32 *)((u8 *)arg2 + (((u32)v36 >> 6) & 0x3FC))));
            *(u32 *)((u8 *)v23 + 16) = (*(u32 *)((u8 *)v0 + ((v37 & 0xFF) << 2)) | v41);
            __dcbt((void *)fzgx_copy_state.v26, 0x20);
            v43 = *(u32 *)((u8 *)v7 + 12);
            v44 = *(u32 *)((u8 *)v25 + 8);
            v25 = (u32)((u8 *)v25 + 8);
            v45 = *(u32 *)((u8 *)v24 + 8);
            v24 = (u32)((u8 *)v24 + 8);
            v46 = *(u32 *)((u8 *)fzgx_copy_state.v26 + 4);
            v47 = (*(u32 *)((u8 *)v3 + (((u32)v45 >> 22) & 0x3FC)) | *(u32 *)((u8 *)v1 + (((u32)v44 >> 22) & 0x3FC)));
            v48 = (v47 | *(u32 *)((u8 *)arg2 + (((u32)v46 >> 22) & 0x3FC)));
            *(u32 *)((u8 *)v22 + 20) = (*(u32 *)((u8 *)v0 + (((u32)v43 >> 14) & 0x3FC)) | (v47 | *(u32 *)((u8 *)arg2 + (((u32)v43 >> 22) & 0x3FC))));
            *(u32 *)((u8 *)v23 + 20) = (*(u32 *)((u8 *)v0 + (((u32)v46 >> 14) & 0x3FC)) | v48);
            v49 = (*(u32 *)((u8 *)v3 + (((u32)v45 >> 14) & 0x3FC)) | *(u32 *)((u8 *)v1 + (((u32)v44 >> 14) & 0x3FC)));
            v50 = (v49 | *(u32 *)((u8 *)arg2 + (((u32)v46 >> 6) & 0x3FC)));
            *(u32 *)((u8 *)v22 + 24) = (*(u32 *)((u8 *)v0 + ((v43 & 0xFF) << 2)) | (v49 | *(u32 *)((u8 *)arg2 + (((u32)v43 >> 6) & 0x3FC))));
            *(u32 *)((u8 *)v23 + 24) = (*(u32 *)((u8 *)v0 + ((v46 & 0xFF) << 2)) | v50);
            v51 = *(u32 *)((u8 *)v7 + 16);
            v52 = *(u32 *)((u8 *)fzgx_copy_state.v26 + 8);
            fzgx_copy_state.v26 = (u32)((u8 *)fzgx_copy_state.v26 + 8);
            v53 = (*(u32 *)((u8 *)v3 + (((u32)v45 >> 6) & 0x3FC)) | *(u32 *)((u8 *)v1 + (((u32)v44 >> 6) & 0x3FC)));
            v54 = (v53 | *(u32 *)((u8 *)arg2 + (((u32)v52 >> 22) & 0x3FC)));
            *(u32 *)((u8 *)v22 + 28) = (*(u32 *)((u8 *)v0 + (((v51 >> 16) & 0xFF) << 2)) | (v53 | *(u32 *)((u8 *)arg2 + (((u32)v51 >> 22) & 0x3FC))));
            *(u32 *)((u8 *)v23 + 28) = (*(u32 *)((u8 *)v0 + (((u32)v52 >> 14) & 0x3FC)) | v54);
            v55 = (*(u32 *)((u8 *)v3 + ((v45 & 0xFF) << 2)) | *(u32 *)((u8 *)v1 + ((v44 & 0xFF) << 2)));
            v56 = *(u32 *)((u8 *)v0 + ((v52 & 0xFF) << 2));
            *(u32 *)((u8 *)v22 + 32) = (*(u32 *)((u8 *)v0 + ((v51 & 0xFF) << 2)) | (v55 | *(u32 *)((u8 *)arg2 + (((u32)v51 >> 6) & 0x3FC))));
            *(u32 *)((u8 *)v23 + 32) = (*(u32 *)((u8 *)v0 + ((v52 & 0xFF) << 2)) | (v55 | *(u32 *)((u8 *)arg2 + (((u32)v52 >> 6) & 0x3FC))));
            v7 = (u32)((u8 *)v7 + 16);
            v22 = (u32)((u8 *)v22 + 32);
            v23 = (u32)((u8 *)v23 + 32);
        }
        v22 = (v22 + v21);
        v23 = (v23 + v21);
        v7 = (v7 + v18);
        fzgx_copy_state.v26 = (fzgx_copy_state.v26 + v18);
        v25 = (v25 + v19);
        v24 = (v24 + v19);
    }
}
