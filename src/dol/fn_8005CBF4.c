#include "types.h"
#pragma use_lmw_stmw on
#include "dol/globals.h"
typedef struct Sig_fn_80028424_Fn80028424Node Sig_fn_80028424_Fn80028424Node;
typedef struct Sig_fn_80023168_Fn80023168State {
    u8 pad_000[0x1c]; u32 flags; u32 state; u8 pad_024[0x122]; u16 value;
} Sig_fn_80023168_Fn80023168State;
struct Sig_fn_80026D70_fn_80026D70_Arg0 { u8 pad_0[0x18]; u32 unk_18; };
struct Sig_fn_80028424_Fn80028424Node {
    Sig_fn_80028424_Fn80028424Node *next; Sig_fn_80028424_Fn80028424Node *prev; void *data;
};
typedef struct Fn8005CBF4Entry {
    u8 state;
    u8 unk_1;
    u8 pad_2[6];
    u8 flags;
    u8 unk_9;
    u8 unk_a;
    u8 pad_b[0xd];
    u32 unk_18;
    u32 pad_1c[4];
    u32 object;
    u8 node[0xe8];
} Fn8005CBF4Entry;
typedef struct Fn8005CBF4Data {
    u8 pad_0[0x444];
    u32 unk_444;
    u8 pad_448[0xfc0];
    Fn8005CBF4Entry entries[64];
} Fn8005CBF4Data;
#define DATA ((Fn8005CBF4Data *)lbl_801A6C80)
extern u32 fn_80026D70(struct Sig_fn_80026D70_fn_80026D70_Arg0 *);
extern u32 fn_80063F38(u32, u32);
extern u32 fn_8006953C(u32);
extern void fn_80020ABC(u32);
extern void fn_80023168(Sig_fn_80023168_Fn80023168State *, u16);
extern void fn_80028424(Sig_fn_80028424_Fn80028424Node *);
extern void fn_80060BDC(u32);
extern void fn_8006413C(void *);

void fn_8005CBF4(u32 arg0) {
    u32 v0;
    u32 v1;
    u8 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    s32 v7;
    u32 v8;
    u32 v9;
    u32 v10;
    u32 v11;
    u8 v12;
    u32 v13;
    s32 v14;
    u32 v15;
    u32 v16;
    u32 v17;
    u32 v18;
    u8 v19;
    u32 v20;
    s32 v21;
    u32 v22;
    u32 v23;
    u32 v24;
    u32 v25;
    u8 v26;
    u32 v27;
    s32 v28;
    u32 v29;
    u32 v30;
    u32 v31;
    u32 v32;
    u8 v33;
    u32 v34;
    s32 v35;
    u32 v36;
    u32 v37;
    u32 v38;
    u32 v39;
    u8 v40;
    u32 v41;
    s32 v42;
    u32 v43;
    u32 v44;
    u32 v45;
    u32 v46;
    u32 v47;
    u32 v2;
    v1 = *(u32 *)((u8 *)lbl_801A6C80 + 0x444);
    v2 = v1 & 0x1F;
    v3 = 0;
    while (v3 < 64) {
        if (arg0 + 0x60000000 == 256) {
            v7 = (u32)v3 * 280;
            v8 = (u32)lbl_801A6C80 + v7;
            if ((*(u8 *)((u8 *)v8 + 5136) & 0x80) == 0 && *(u8 *)((u8 *)v8 + 5128) != 255) {
                fn_80023168((Sig_fn_80023168_Fn80023168State *)*(u32 *)((u8 *)v8 + 5172), 0);
                fn_80026D70((struct Sig_fn_80026D70_fn_80026D70_Arg0 *)DATA->entries[(u32)v3].object);
                fn_80020ABC(DATA->entries[(u32)v3].object);
                v9 = v7 + 5172;
                DATA->entries[(u32)v3].object = 0;
                if (DATA->entries[(u32)v3].state == 3) {
                    fn_80060BDC((u32)v3);
                } else {
                    fn_80028424((Sig_fn_80028424_Fn80028424Node *)DATA->entries[(u32)v3].node);
                }
                v4 = 255;
                DATA->entries[(u32)v3].state = v4;
                v5 = 0;
                v10 = v7 + 5129;
                DATA->entries[(u32)v3].unk_18 = v5;
                DATA->entries[(u32)v3].unk_1 = v5;
                v11 = (u32)lbl_801A6C80 + v7;
                if (*(u8 *)((u8 *)v11 + 5137) == (u32)v3) {
                    *(u8 *)((u8 *)v11 + 5137) = v4;
                } else if (*(u8 *)((u8 *)v11 + 5138) == (u32)v3) {
                    *(u8 *)((u8 *)v11 + 5138) = v4;
                }
            }
        }
        else if (arg0 + 0x60000000 == 512) {
            v14 = (u32)v3 * 280;
            v15 = (u32)lbl_801A6C80 + v14;
            if (*(u8 *)((u8 *)v15 + 5128) == 1 && *(u8 *)((u8 *)v15 + 5128) != 255) {
                fn_80023168((Sig_fn_80023168_Fn80023168State *)*(u32 *)((u8 *)v15 + 5172), 0);
                fn_80026D70((struct Sig_fn_80026D70_fn_80026D70_Arg0 *)DATA->entries[(u32)v3].object);
                fn_80020ABC(DATA->entries[(u32)v3].object);
                v16 = v14 + 5172;
                DATA->entries[(u32)v3].object = 0;
                if (DATA->entries[(u32)v3].state == 3) {
                    fn_80060BDC((u32)v3);
                } else {
                    fn_80028424((Sig_fn_80028424_Fn80028424Node *)DATA->entries[(u32)v3].node);
                }
                v4 = 255;
                DATA->entries[(u32)v3].state = v4;
                v5 = 0;
                v17 = v14 + 5129;
                DATA->entries[(u32)v3].unk_18 = v5;
                DATA->entries[(u32)v3].unk_1 = v5;
                v18 = (u32)lbl_801A6C80 + v14;
                if (*(u8 *)((u8 *)v18 + 5137) == (u32)v3) {
                    *(u8 *)((u8 *)v18 + 5137) = v4;
                } else if (*(u8 *)((u8 *)v18 + 5138) == (u32)v3) {
                    *(u8 *)((u8 *)v18 + 5138) = v4;
                }
            }
        }
        else if (arg0 + 0x60000000 == 768) {
            v21 = (u32)v3 * 280;
            v22 = (u32)lbl_801A6C80 + v21;
            v19 = DATA->entries[(u32)v3].state;
            if (v19 == 2 && (DATA->entries[(u32)v3].flags & 0x80) == 0 && v19 != 255) {
                fn_80023168((Sig_fn_80023168_Fn80023168State *)DATA->entries[(u32)v3].object, 0);
                fn_80026D70((struct Sig_fn_80026D70_fn_80026D70_Arg0 *)DATA->entries[(u32)v3].object);
                fn_80020ABC(DATA->entries[(u32)v3].object);
                v23 = v21 + 5172;
                DATA->entries[(u32)v3].object = 0;
                if (DATA->entries[(u32)v3].state == 3) {
                    fn_80060BDC((u32)v3);
                } else {
                    fn_80028424((Sig_fn_80028424_Fn80028424Node *)DATA->entries[(u32)v3].node);
                }
                v4 = 255;
                DATA->entries[(u32)v3].state = v4;
                v5 = 0;
                v24 = v21 + 5129;
                DATA->entries[(u32)v3].unk_18 = v5;
                DATA->entries[(u32)v3].unk_1 = v5;
                v25 = (u32)lbl_801A6C80 + v21;
                if (*(u8 *)((u8 *)v25 + 5137) == (u32)v3) {
                    *(u8 *)((u8 *)v25 + 5137) = v4;
                } else if (*(u8 *)((u8 *)v25 + 5138) == (u32)v3) {
                    *(u8 *)((u8 *)v25 + 5138) = v4;
                }
            }
        }
        else if (arg0 + 0x60000000 == 4352) {
            v28 = (u32)v3 * 280;
            v29 = (u32)lbl_801A6C80 + v28;
            if ((*(u32 *)((u8 *)v29 + 5152) & 0xF) == v2 && (*(u8 *)((u8 *)v29 + 5136) & 0x80) == 0 && *(u8 *)((u8 *)v29 + 5128) != 255) {
                fn_80023168((Sig_fn_80023168_Fn80023168State *)*(u32 *)((u8 *)v29 + 5172), 0);
                fn_80026D70((struct Sig_fn_80026D70_fn_80026D70_Arg0 *)DATA->entries[(u32)v3].object);
                fn_80020ABC(DATA->entries[(u32)v3].object);
                v30 = v28 + 5172;
                DATA->entries[(u32)v3].object = 0;
                if (DATA->entries[(u32)v3].state == 3) {
                    fn_80060BDC((u32)v3);
                } else {
                    fn_80028424((Sig_fn_80028424_Fn80028424Node *)DATA->entries[(u32)v3].node);
                }
                v4 = 255;
                DATA->entries[(u32)v3].state = v4;
                v5 = 0;
                v31 = v28 + 5129;
                DATA->entries[(u32)v3].unk_18 = v5;
                DATA->entries[(u32)v3].unk_1 = v5;
                v32 = (u32)lbl_801A6C80 + v28;
                if (*(u8 *)((u8 *)v32 + 5137) == (u32)v3) {
                    *(u8 *)((u8 *)v32 + 5137) = v4;
                } else if (*(u8 *)((u8 *)v32 + 5138) == (u32)v3) {
                    *(u8 *)((u8 *)v32 + 5138) = v4;
                }
            }
        }
        else if (arg0 + 0x60000000 == 4608) {
            v35 = (u32)v3 * 280;
            v36 = (u32)lbl_801A6C80 + v35;
            v33 = DATA->entries[(u32)v3].state;
            if (v33 == 1 && (DATA->entries[(u32)v3].unk_18 & 0xF) == v2 && v33 != 255) {
                fn_80023168((Sig_fn_80023168_Fn80023168State *)DATA->entries[(u32)v3].object, 0);
                fn_80026D70((struct Sig_fn_80026D70_fn_80026D70_Arg0 *)DATA->entries[(u32)v3].object);
                fn_80020ABC(DATA->entries[(u32)v3].object);
                v37 = v35 + 5172;
                DATA->entries[(u32)v3].object = 0;
                if (DATA->entries[(u32)v3].state == 3) {
                    fn_80060BDC((u32)v3);
                } else {
                    fn_80028424((Sig_fn_80028424_Fn80028424Node *)DATA->entries[(u32)v3].node);
                }
                v4 = 255;
                DATA->entries[(u32)v3].state = v4;
                v5 = 0;
                v38 = v35 + 5129;
                DATA->entries[(u32)v3].unk_18 = v5;
                DATA->entries[(u32)v3].unk_1 = v5;
                v39 = (u32)lbl_801A6C80 + v35;
                if (*(u8 *)((u8 *)v39 + 5137) == (u32)v3) {
                    *(u8 *)((u8 *)v39 + 5137) = v4;
                } else if (*(u8 *)((u8 *)v39 + 5138) == (u32)v3) {
                    *(u8 *)((u8 *)v39 + 5138) = v4;
                }
            }
        }
        else if (arg0 + 0x60000000 == 4864) {
            v42 = (u32)v3 * 280;
            v43 = (u32)lbl_801A6C80 + v42;
            v40 = DATA->entries[(u32)v3].state;
            if (v40 == 2 && (DATA->entries[(u32)v3].unk_18 & 0xF) == v2 && (DATA->entries[(u32)v3].flags & 0x80) == 0 && v40 != 255) {
                fn_80023168((Sig_fn_80023168_Fn80023168State *)DATA->entries[(u32)v3].object, 0);
                fn_80026D70((struct Sig_fn_80026D70_fn_80026D70_Arg0 *)DATA->entries[(u32)v3].object);
                fn_80020ABC(DATA->entries[(u32)v3].object);
                v44 = v42 + 5172;
                DATA->entries[(u32)v3].object = 0;
                if (DATA->entries[(u32)v3].state == 3) {
                    fn_80060BDC((u32)v3);
                } else {
                    fn_80028424((Sig_fn_80028424_Fn80028424Node *)DATA->entries[(u32)v3].node);
                }
                v4 = 255;
                DATA->entries[(u32)v3].state = v4;
                v5 = 0;
                v45 = v42 + 5129;
                DATA->entries[(u32)v3].unk_18 = v5;
                DATA->entries[(u32)v3].unk_1 = v5;
                v46 = (u32)lbl_801A6C80 + v42;
                if (*(u8 *)((u8 *)v46 + 5137) == (u32)v3) {
                    *(u8 *)((u8 *)v46 + 5137) = v4;
                } else if (*(u8 *)((u8 *)v46 + 5138) == (u32)v3) {
                    *(u8 *)((u8 *)v46 + 5138) = v4;
                }
            }
        }
        v3++;
    }
    if (arg0 + 0x60000000 == 256) {
        fn_8006413C((void *)1);
    } else if (arg0 + 0x60000000 == 4352) {
        fn_80063F38(17, v2);
    }
    v47 = *(u32 *)((u8 *)lbl_801A6C80 + 0x444);
    if ((v47 & 0x40) == 0) {
        fn_8006953C(v47);
    }
}
