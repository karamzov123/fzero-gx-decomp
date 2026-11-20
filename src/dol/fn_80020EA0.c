#include "types.h"


/* --- dol/fn_80020EA0.c --- */
struct fn_80020EA0_Arg0 {
    u32 unk_0;
};

extern u32 lbl_8015D200[];
extern u32 lbl_801A6AE4;

void fn_80020EA0(struct fn_80020EA0_Arg0 *arg0) {
    arg0->unk_0 = (u32)((u8 *)&lbl_8015D200 + (lbl_801A6AE4 * 1920));
}

/* --- dol/fn_80020EBC.c --- */
struct fn_80020EBC_Arg0 {
    u32 unk_0;
};


void fn_80020EBC(struct fn_80020EBC_Arg0 *arg0) {
    arg0->unk_0 = (u32)((u8 *)((u8 *)&lbl_8015D200 + (lbl_801A6AE4 * 1920)) + 640);
}

/* --- dol/fn_80020EDC.c --- */
struct fn_80020EDC_Arg0 {
    u32 unk_0;
};


void fn_80020EDC(struct fn_80020EDC_Arg0 *arg0) {
    arg0->unk_0 = (u32)((u8 *)((u8 *)&lbl_8015D200 + (lbl_801A6AE4 * 1920)) + 1280);
}

/* --- dol/fn_80020EFC.c --- */
struct fn_80020EFC_Arg0 {
    u32 unk_0;
};

extern u32 lbl_8015E880[];

void fn_80020EFC(struct fn_80020EFC_Arg0 *arg0) {
    arg0->unk_0 = (u32)((u8 *)((u8 *)&lbl_8015E880 + (lbl_801A6AE4 * 1920)) + 1280);
}

/* --- dol/fn_80020F1C.c --- */
struct fn_80020F1C_Arg0 {
    u32 unk_0;
};

extern u32 lbl_801A6AC4;
extern u32 lbl_801A6AE0;

u32 fn_80020F1C(struct fn_80020F1C_Arg0 *arg0) {
    if (lbl_801A6AC4 != 0) {
    arg0->unk_0 = (u32)((u8 *)&lbl_8015E880 + (lbl_801A6AE0 * 1920));
    return (u32)arg0;
    }
    arg0->unk_0 = 0;
}

/* --- dol/fn_80020F50.c --- */
struct fn_80020F50_Arg0 {
    u32 unk_0;
};


void fn_80020F50(struct fn_80020F50_Arg0 *arg0) {
    arg0->unk_0 = (u32)((u8 *)&lbl_8015E880 + (lbl_801A6AE4 * 1920));
}

/* --- dol/fn_80020F6C.c --- */
struct fn_80020F6C_Arg0 {
    u32 unk_0;
};

extern u32 lbl_801A6AE8;

void fn_80020F6C(struct fn_80020F6C_Arg0 *arg0) {
    arg0->unk_0 = (u32)((u8 *)&lbl_8015E880 + (lbl_801A6AE8 * 1920));
}

/* --- dol/fn_80020F88.c --- */
struct fn_80020F88_Arg0 {
    u32 unk_0;
};

extern u32 lbl_801A6AEC;

void fn_80020F88(struct fn_80020F88_Arg0 *arg0) {
    arg0->unk_0 = (u32)((u8 *)&lbl_8015E880 + (lbl_801A6AEC * 1920));
}
