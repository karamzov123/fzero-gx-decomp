#include "types.h"


/* --- rel/movie_module/fn_12_34DE4.c --- */
/* --- rel/movie_module/fn_12_34DE4.c --- */
extern void fn_8005912C(u32, void *, void *, void *);
extern u32 lbl_12_bss_1B9A8[2];

void fn_12_34DE4(void *arg0, void *arg1, void *arg2) {
    fn_8005912C(2, arg0, arg1, arg2);
    lbl_12_bss_1B9A8[0] = (u32)arg0;
}

/* --- rel/movie_module/fn_12_34E2C.c --- */
extern void fn_80058B54(void);

void fn_12_34E2C(void) {
    fn_80058B54();
}

/* --- rel/movie_module/fn_12_34E4C.c --- */
extern struct fn_12_34E4C_lbl_12_bss_1B8A0 lbl_12_bss_1B8A0;
extern u32 fn_80058BFC(void);

struct fn_12_34E4C_lbl_12_bss_1B8A0 {
    u8 pad_0[0x100];
    u32 unk_100;
    u32 unk_104;
    u32 unk_108;
    u32 unk_10C;
};

void fn_12_34E4C(void) {
    struct fn_12_34E4C_lbl_12_bss_1B8A0 *p_lbl_12_bss_1B8A0;
    p_lbl_12_bss_1B8A0 = (struct fn_12_34E4C_lbl_12_bss_1B8A0 *)&lbl_12_bss_1B8A0;
    fn_80058BFC();
    p_lbl_12_bss_1B8A0->unk_10C = 0;
    p_lbl_12_bss_1B8A0->unk_108 = 0;
    p_lbl_12_bss_1B8A0->unk_104 = 0;
    p_lbl_12_bss_1B8A0->unk_100 = 0;
}

/* --- rel/movie_module/fn_12_34E90.c --- */
extern void fn_8004AEE4(void);

void fn_12_34E90(void);

/* --- rel/movie_module/fn_12_34EB0.c --- */
extern void fn_8004AD84(void);
extern void fn_8004B0EC(void *);

void fn_12_34EB0(void *arg);

/* --- rel/movie_module/fn_12_34EE4.c --- */
extern void fn_8004ADF4(void);

void fn_12_34EE4(void);

/* --- rel/movie_module/fn_12_34F04.c --- */
extern u32 fn_8004AC04(u32, u32);
extern u32 fn_8004B180(u32, u32, u32, u32, u32);

void fn_12_34F04(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4);
