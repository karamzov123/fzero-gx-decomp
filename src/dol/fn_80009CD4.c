#include "types.h"

struct fn_80009CD4_Copy8 { u32 a[2]; };
struct fn_80009CD4_lbl_8015BEE0 { u32 unk_0, unk_4, unk_8, unk_C, unk_10; };
extern u32 lbl_8015BEE0[8];
extern u32 lbl_8015BE40[40];
extern u32 lbl_801A6410;
extern u32 lbl_801A6730;
extern u32 lbl_801A6738;
extern u32 lbl_801A673C;
extern u32 lbl_801A6740;
extern u32 lbl_801A6744;

static inline u32 find_block(u32 link, u32 address) {
    while (link) {
        if (link == address) return link;
        link = *(u32 *)(link + 4);
    }
    return 0;
}
static inline void enter(void) {
    if ((s32)lbl_801A6730 != -1) {
        lbl_8015BEE0[0] = lbl_801A6410;
        lbl_8015BEE0[1] = lbl_801A6744;
        lbl_8015BEE0[2] = lbl_801A6740;
        lbl_8015BEE0[3] = lbl_801A673C;
        lbl_8015BEE0[4] = lbl_801A6738;
        lbl_801A6410 = lbl_8015BE40[lbl_801A6730 * 5];
        lbl_801A6744 = lbl_8015BE40[lbl_801A6730 * 5 + 1];
        lbl_801A6740 = lbl_8015BE40[lbl_801A6730 * 5 + 2];
        lbl_801A673C = lbl_8015BE40[lbl_801A6730 * 5 + 3];
        lbl_801A6738 = lbl_8015BE40[lbl_801A6730 * 5 + 4];
    }
}

s32 fn_80009CD4(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 v0;
    u32 v7, v11, v14, v16, v13, v15, v20, v21, v23, v24, v28, v29, v30, v31;
    u32 v19, v17, v9, v18, v25, v26, v12, v8, v27, v22, v10;
    /* Volatile preserves the heap index snapshot before enter() swaps the globals. */
    v0 = *(volatile u32 *)&lbl_801A6410;
    enter();
    v7 = v0 * 12;
    v8 = arg0 - 32;
    v9 = *(u32 *)(v8 + 8);
    v12 = lbl_801A6744 + v7;
    v10 = v8 + v9;
    v11 = find_block(*(u32 *)(v12 + 4), v10);
    if (!v11 && v9 <= arg1 + 64) return 0;
    v13 = *(u32 *)(v8 + 4);
    v14 = *(u32 *)(v12 + 8);
    if (v13 != 0) {
        *(u32 *)v13 = *(u32 *)v8;
    }
    v15 = *(u32 *)v8;
    v16 = v14;
    if (v15 == 0) {
        v16 = *(u32 *)(v8 + 4);
    } else {
        *(u32 *)(v15 + 4) = *(u32 *)(v8 + 4);
    }
    *(u32 *)(v12 + 8) = v16;
    v17 = *(u32 *)(v12 + 4);
    v18 = v17;
    v19 = 0;
    while (v18 != 0) {
        if (v8 <= v18) break;
        v19 = v18;
        v18 = *(u32 *)(v18 + 4);
    }
    v20 = v17;
    *(u32 *)(v8 + 4) = v18;
    *(u32 *)v8 = v19;
    v21 = v18;
    if (v18 != 0) {
        *(u32 *)v21 = v8;
        v24 = *(u32 *)(v8 + 8);
        v22 = v8 + v24;
        if (v22 == v21) {
            *(u32 *)(v8 + 8) = v24 + *(u32 *)(v21 + 8);
            v21 = *(u32 *)(v21 + 4);
            *(u32 *)(v8 + 4) = v21;
            if (v21 != 0) *(u32 *)v21 = v8;
        }
    }
    v17 = v20;
    if (v19 != 0) {
        *(u32 *)(v19 + 4) = v8;
        v24 = *(u32 *)(v19 + 8);
        v22 = v19 + v24;
        if (v22 == v8) {
            *(u32 *)(v19 + 8) = v24 + *(u32 *)(v8 + 8);
            *(u32 *)(v19 + 4) = v21;
            if (v21 != 0) *(u32 *)v21 = v19;
        }
    } else {
        v17 = v8;
    }
    *(u32 *)(v12 + 4) = v17;
    v25 = (arg1 + 63) & ~31;
    v26 = v8 + v25;
    v27 = v9 - v25;
    v28 = *(u32 *)(v8 + 8);
    *(u32 *)(v8 + 8) = v25;
    *(u32 *)(v26 + 8) = v28 - v25;
    *(u32 *)v26 = *(u32 *)v8;
    *(u32 *)(v26 + 4) = *(u32 *)(v8 + 4);
    v29 = *(u32 *)(v26 + 4);
    if (v29 != 0) *(u32 *)v29 = v26;
    v30 = *(u32 *)v26;
    if (v30 != 0) *(u32 *)(v30 + 4) = v26;
    else *(u32 *)(v12 + 4) = v26;
    v31 = *(u32 *)(v12 + 8);
    *(u32 *)(v8 + 4) = v31;
    *(u32 *)v8 = 0;
    if (v31 != 0) *(u32 *)v31 = v8;
    *(u32 *)(v12 + 8) = v8;
    if ((s32)lbl_801A6730 != -1) {
        lbl_8015BE40[lbl_801A6730 * 5] = lbl_801A6410;
        lbl_8015BE40[lbl_801A6730 * 5 + 1] = lbl_801A6744;
        lbl_8015BE40[lbl_801A6730 * 5 + 2] = lbl_801A6740;
        lbl_8015BE40[lbl_801A6730 * 5 + 3] = lbl_801A673C;
        lbl_8015BE40[lbl_801A6730 * 5 + 4] = lbl_801A6738;
        lbl_801A6410 = lbl_8015BEE0[0];
        lbl_801A6744 = lbl_8015BEE0[1];
        lbl_801A6740 = lbl_8015BEE0[2];
        lbl_801A673C = lbl_8015BEE0[3];
        lbl_801A6738 = lbl_8015BEE0[4];
    }
    return -v27;
}
