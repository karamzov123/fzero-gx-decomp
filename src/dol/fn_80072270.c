#include "types.h"


/* --- dol/fn_80072270.c --- */
/* --- dol/fn_80072270.c --- */
struct fn_80072270_Arg0 {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_c;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
};

extern const f32 lbl_801A745C;
extern const f32 lbl_801A7460;
extern u32 lbl_8019E250[];
extern u32 lbl_8019F008[];
extern void GXSetProjectionv();

void fn_80072270(struct fn_80072270_Arg0 *arg0, u32 arg1, f32 arg2, f32 arg3) {
    f32 zero = lbl_801A745C;
    if (zero == arg0->unk_0) {
        ((f32 *)lbl_8019E250)[1] = __fabs(arg0->unk_18 / (arg0->unk_14 - lbl_801A7460));
    } else {
        ((f32 *)lbl_8019E250)[1] = __fabs((lbl_801A7460 + arg0->unk_18) / arg0->unk_14);
    }

    ((f32 *)lbl_8019E250)[2] = arg0->unk_18 / arg0->unk_14;
    ((f32 *)lbl_8019F008)[0] = arg0->unk_0;
    ((f32 *)lbl_8019F008)[1] = arg0->unk_4;
    ((f32 *)lbl_8019F008)[2] = arg0->unk_8;
    ((f32 *)lbl_8019F008)[3] = arg0->unk_c;
    ((f32 *)lbl_8019F008)[4] = arg0->unk_10;
    ((f32 *)lbl_8019F008)[5] = arg0->unk_14;
    ((f32 *)lbl_8019F008)[6] = arg0->unk_18;
    GXSetProjectionv(lbl_8019F008);
}

/* --- dol/fn_80072344.c --- */
extern u32 lbl_8019F024[];
extern u32 memcpy(u32, u32, u32);

void fn_80072344(void) {
    memcpy((u32)&lbl_8019F024, (u32)&lbl_8019F008, 28);
}

/* --- dol/fn_80072378.c --- */

void fn_80072378(void) {
    memcpy((u32)&lbl_8019F008, (u32)&lbl_8019F024, 28);
    GXSetProjectionv(&lbl_8019F008);
}

/* --- dol/fn_800723B8.c --- */
extern u32 fn_8003887C(void);

void fn_800723B8(void) {
    fn_8003887C();
}

/* --- dol/fn_800723D8.c --- */
extern u32 fn_80038944(void);

void fn_800723D8(void) {
    fn_80038944();
}

/* --- dol/fn_800723F8.c --- */
extern u32 lbl_801A6D28;

void fn_800723F8(void) {
    lbl_801A6D28 = 0;
}

/* --- dol/fn_80072404.c --- */
/* --- dol/fn_80072404.c --- */
extern u32 lbl_8015ACBC[21];
extern u32 lbl_8015AC68[21];

u32 fn_80072404(u32 mask, s32 select) {
    u32 *a = lbl_8015ACBC;
    u32 *b = lbl_8015AC68;
    u32 total = 0;
    int i;

    for (i = 0; i < 17; i++) {
        if (mask & 1) {
            if (select != 0) {
                total += *a;
            } else {
                total += *b;
            }
        }
        mask >>= 1;
        a = a + 1;
        b++;
    }
    return total;
}

/* --- dol/fn_8007245C.c --- */
extern void GXClearVtxDesc(u32 value);
extern void GXSetVtxDesc(u32 index, u32 value);

void fn_8007245C(u32 value) {
    u32 index;

    if (value != lbl_801A6D28) {
        GXClearVtxDesc(value);
        lbl_801A6D28 = value;
        index = 0;
        while (index < 0x1a) {
            if (value & 1) {
                GXSetVtxDesc(index, 1);
            }
            index++;
            value >>= 1;
        }
    }
}

/* --- dol/fn_800724C8.c --- */
// fn_800724C8: empty in retail (single blr).
void fn_800724C8(void) {
}
