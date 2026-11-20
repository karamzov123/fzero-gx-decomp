#include "types.h"


/* --- dol/fn_80071484.c --- */
extern u32 lbl_8015ABD8[];
extern u32 lbl_801A6D0C;
extern u32 lbl_801A6D10;
extern u32 lbl_801A6D14;
extern u32 lbl_801A6D18;
extern u32 lbl_801A6D1C;
extern u32 lbl_801A6D20;
extern u32 lbl_801A6D24;
extern void fn_8007174C(u32, u32);

void *fn_80071484(u32 arg0) {
    s32 temp_r31;
    void *temp_r30;
    void *temp_r29;
    s32 temp_r28;

    temp_r28 = ((s32 (*)())((*(u32 *)((u8 *)(&lbl_801A6D24) + 0))))();
    if (((s32 (*)(u32, s32))((*(u32 *)((u8 *)(&lbl_801A6D20) + 0))))(arg0, temp_r28) == 0) {
        return NULL;
    }
    temp_r31 = ((s32 (*)(s32))((*(u32 *)((u8 *)(&lbl_801A6D1C) + 0))))(temp_r28);
    temp_r30 = ((void *(*)(s32))((*(u32 *)((u8 *)(&lbl_801A6D0C) + 0))))(((temp_r31 + 0x1F) & 0xFFFFFFE0) + 0x20);
    if (temp_r30 == NULL) {
        fn_8007174C((u32)lbl_8015ABD8, arg0);
    }
    temp_r29 = (void *)(((u32)temp_r30 + 0x3F) & 0xFFFFFFE0);
    ((s32 (*)(s32, void *, s32, s32))((*(u32 *)((u8 *)(&lbl_801A6D18) + 0))))(temp_r28, temp_r29, temp_r31, 0);
    ((s32 (*)(s32))((*(u32 *)((u8 *)(&lbl_801A6D14) + 0))))(temp_r28);
    ((s32 (*)(s32))((*(u32 *)((u8 *)(&lbl_801A6D10) + 0))))(temp_r28);
    *(u32 *)temp_r30 = *(u32 *)temp_r29;
    *(u32 *)((u8 *)temp_r30 + 4) = (u32)temp_r29 + 4;
    *(u32 *)((u8 *)temp_r30 + 8) = (u32)temp_r29;
    *(u32 *)((u8 *)temp_r30 + 12) = 0;
    return temp_r30;
}

/* --- dol/fn_800715A0.c --- */
typedef u32 (*fn_800715A0_Fn0)(u32, u32);

extern u32 ARGetDMAStatus(void);
extern u32 ARStartDMA(u32, u32, u32, u32);
extern u32 lbl_8015ABC0[];
extern void DCInvalidateRange(void *, u32);

void *fn_800715A0(u32 arg0, u32 arg1) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 t0, t3, t5;
    v0 = (arg1 + 31);
    v1 = (v0 & ~0x1F);
    t0 = ((fn_800715A0_Fn0)lbl_801A6D0C)((v1 + 32), arg1);
    v2 = t0;
    if (t0 == 0) {
        v2 = (u32)&lbl_8015ABD8;
        v3 = (u32)&lbl_8015ABC0;
        fn_8007174C((u32)v2, (u32)v3);
    }
    v4 = ((t0 + 63) & ~0x1F);
    DCInvalidateRange((void *)v4, v1);
    do {
        t3 = ARGetDMAStatus();
    } while (t3 != 0);
    ARStartDMA(1, v4, arg0, arg1);
    do {
        t5 = ARGetDMAStatus();
    } while (t5 != 0);
    *(u32 *)((u8 *)t0 + 0) = *(u32 *)((u8 *)v4 + 0);
    *(u32 *)((u8 *)t0 + 4) = (v4 + 4);
    *(u32 *)((u8 *)t0 + 8) = v4;
    *(u32 *)((u8 *)t0 + 12) = 0;
    return (void *)t0;
}

/* --- dol/fn_80071678.c --- */
typedef u32 (*fn_80071678_Fn0)(u32, u32);
extern u32 lbl_8015ABCC[];


void *fn_80071678(s32 *arg0, void *arg1) {
    s32 var_r4;
    void *var_r31;

    var_r31 = (void *)(arg1);
    var_r4 = 0;
    if (var_r31 == NULL) {
        var_r31 = (void *)(((void *(*)(s32))((*(u32 *)((u8 *)(&lbl_801A6D0C) + 0))))(0x20));
        if (var_r31 == NULL) {
            fn_8007174C((u32)(lbl_8015ABD8), (u32)(lbl_8015ABCC));
        }
        var_r4 = 1;
    }
    (*(s32 *)((u8 *)(var_r31) + 0)) = (s32) (*(s32 *)((u8 *)(arg0) + 0));
    (*(void **)((u8 *)(var_r31) + 4)) = (void *)((void *) ((u8 *)(arg0) + 4));
    (*(s32 **)((u8 *)(var_r31) + 8)) = (s32 *)(arg0);
    if (var_r4 == 0) {
        (*(s32 *)((u8 *)(var_r31) + 12)) = 1;
    } else {
        (*(s32 *)((u8 *)(var_r31) + 12)) = 0;
    }
    return var_r31;
}

/* --- dol/fn_80071718.c --- */
typedef u32 (*fn_80071718_Fn0)(u32);
struct fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

extern u32 lbl_801A6D08;

void fn_80071718(struct fn_80071718_Arg0 *arg0) {
    if ((arg0->unk_C & 0x1) == 0) {
        ((fn_80071718_Fn0)lbl_801A6D08)((u32)arg0);
    }
}

/* --- dol/fn_8007174C.c --- */
extern u32 OSPanic(u32, ...);
extern u32 sprintf(void *, ...);
extern u32 lbl_8015ABFC[];

void fn_8007174C(u32 arg0, u32 arg1) {
    struct { u32 a[258]; } loc_8;
    /* frame */
    sprintf(&loc_8, arg0, arg1);
    OSPanic((u32)&lbl_8015ABFC, 498, &loc_8);
}

/* --- dol/fn_80071794.c --- */
void fn_80071794(u32 lab_unused0) {
    ((void (*)(void))lbl_801A6D0C)();
}

/* --- dol/fn_800717BC.c --- */
u32 fn_800717BC(u32 arg0, u32 arg1) {
    s32 i;
    s32 c0;
    s32 c1;
    s32 v;
    s32 n;
    c1 = 0;
    c0 = 0;
    for (i = 0; i < 10; i++) {
    if ((arg0 & (1u << i)) != 0) {
    c0++;
    }
    if ((arg1 & (1u << i)) != 0) {
    c1++;
    }
    }
    v = (s32)arg0;
    if (c0 > 1 || c1 > 1) {
    return -1;
    }
    if (v > (s32)arg1) {
    v = (s32)arg1;
    }
    n = 0;
    while (v > 4) {
    v = (v >> 1);
    n++;
    }
    return n;
}
