#include "types.h"


/* --- dol/fn_80008DB4.c --- */
typedef struct Fn80008DB4Value {
    u8 data[0x10];
} Fn80008DB4Value;

extern void lbl_8006DBAC(void *value);
extern void fn_8006E5FC(Fn80008DB4Value *value);
extern void fn_8006EB4C(Fn80008DB4Value *out, Fn80008DB4Value *a, Fn80008DB4Value *b, f32 amount);
extern void PSMTXQuat(void *value, Fn80008DB4Value *transform);

void fn_80008DB4(void *first, f32 amount, void *second, void *out) {
    Fn80008DB4Value a;
    Fn80008DB4Value b;

    lbl_8006DBAC(first);
    fn_8006E5FC(&a);
    lbl_8006DBAC(second);
    fn_8006E5FC(&b);
{
    Fn80008DB4Value result;
    fn_8006EB4C(&result, &a, &b, amount);
    PSMTXQuat(out, &result);
}
}

/* --- dol/fn_80008E30.c --- */
// fn_80008E30: empty in retail (single blr).
void fn_80008E30(void) {
}

/* --- dol/fn_80008E34.c --- */
/* --- dol/fn_80008E34.c --- */
extern u32 fn_80009830(u32, u32, u32, u32);
extern u32 lbl_801A6414;

void fn_80008E34(u32 arg0, u32 arg1) {
    fn_80009830(arg0, arg1, (u32)&lbl_801A6414, 0);
}

/* --- dol/fn_80008E5C.c --- */
extern u32 fn_80009AA8(u32, u32, u32, u32);

void fn_80008E5C(u32 arg0, u32 arg1) {
    fn_80009AA8(arg0, arg1, (u32)&lbl_801A6414, 0);
}

/* --- dol/fn_80008E84.c --- */
extern u32 fn_8000951C(u32);
extern u32 fn_800095A4(void);
extern u32 lbl_801A6410;

u32 fn_80008E84(u32 arg0) {
    u32 v0;
    fn_8000951C(arg0);
    v0 = lbl_801A6410;
    lbl_801A6410 = arg0;
    fn_800095A4();
    return v0;
}

/* --- dol/fn_80008EC8.c --- */
extern u32 lbl_801A6744;
extern u32 lbl_801A6740;
extern u32 lbl_801A673C;
extern u32 lbl_801A6738;
extern void fn_80009468(void *);

typedef struct {
    s32 field_0x0;
    s32 field_0x4;
    s32 field_0x8;
} HeapDesc;

u32 fn_80008EC8(void *arenaStart, void *arenaEnd, s32 maxHeaps) {
    u32 arraySize;
    s32 i;
    HeapDesc *hd;
    u32 zero = 0;
    u32 end;
    u32 ret;

    arraySize = maxHeaps * 12;
    lbl_801A6744 = (u32)arenaStart;
    lbl_801A6740 = maxHeaps;

    for (i = 0; i < (s32)lbl_801A6740; i++) {
        hd = (HeapDesc *)((u8 *)lbl_801A6744 + i * 12);
        hd->field_0x0 = -1;
        hd->field_0x4 = hd->field_0x8 = 0;
    }

    end = lbl_801A6744 + arraySize;
    lbl_801A6738 = (u32)arenaEnd & 0xFFFFFFE0;
    lbl_801A6410 = -1;
    ret = (end + 0x1F) & 0xFFFFFFE0;
    lbl_801A673C = ret;
    fn_80009468((void *)end);
    return ret;
}

/* --- dol/fn_80008F60.c --- */
extern u32 fn_80008FB0(void);
extern u32 lbl_801A6734;

void fn_80008F60(void) {
    lbl_801A6734 = 0;
    fn_80008FB0();
}

/* --- dol/fn_80008F88.c --- */
void fn_80008F88(void) {
    lbl_801A6734 = 1;
    fn_80008FB0();
}
