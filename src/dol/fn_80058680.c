#include "types.h"


/* --- dol/fn_80058680.c --- */
struct fn_80058680_lbl_8018B2A0 {
    u32 unk_0;
};

extern struct fn_80058680_lbl_8018B2A0 lbl_8018B2A0[];
extern u32 fn_800576DC(void);
extern u32 fn_80057728(void);
extern const f32 lbl_8009232C[];
extern u32 lbl_8018B2A4[];
extern u32 memset(u32, u32, u32);

void fn_80058680(void) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 t1;
    /* Preserve the retail literal-pool read before initialization. */
    (void)*(volatile u32 *)&lbl_8009232C;
    fn_80057728();
    v1 = 0;
    v2 = 0;
    if ((s32)lbl_8018B2A0[0].unk_0 == 0) {
        v1 = 0;
        v0 = (u32)&lbl_8018B2A4;
        v2 = 16384;
        t1 = memset((u32)v0, v1, v2);
        v0 = t1;
    }
    v3 = lbl_8018B2A0[0].unk_0;
    lbl_8018B2A0[0].unk_0 = (v3 + 1);
    fn_800576DC();
}

/* --- dol/fn_800586E4.c --- */
extern u32 fn_80058A20(u32);
extern u32 lbl_80092340[];

void fn_800586E4(void) {
    fn_80058A20((u32)&lbl_80092340);
}

/* --- dol/fn_8005870C.c --- */
struct fn_8005870C_lbl_8018F2A8 {
    u32 unk_0;
};

extern struct fn_8005870C_lbl_8018F2A8 lbl_8018F2A8[];
extern u32 lbl_8018F2AC[];

void fn_8005870C(void) {
    struct fn_8005870C_lbl_8018F2A8 *p;

    p = (struct fn_8005870C_lbl_8018F2A8 *)&lbl_8018F2A8;
    if (--p->unk_0 == 0) {
        memset((u32)&lbl_8018F2AC, 0, 3072);
    }
}
