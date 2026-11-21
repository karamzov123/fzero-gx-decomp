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

void fn_80058680(void);

/* --- dol/fn_800586E4.c --- */
extern u32 fn_80058A20(u32);
extern u32 lbl_80092340[];

void fn_800586E4(void);

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
