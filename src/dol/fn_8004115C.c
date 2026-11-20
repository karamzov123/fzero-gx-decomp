#include "types.h"


/* --- dol/fn_8004115C.c --- */
extern u32 lbl_801A6C6C;

void fn_8004115C(u32 arg0) {
    lbl_801A6C6C = arg0;
}

/* --- dol/ADXT_Finish.c --- */
void fn_80058630(void);

void fn_80058B54(void);

void fn_800592E0(int server_type, int id);

extern void ADXT_DestroyAll(void);

extern void fn_8004EF68(void);

extern void fn_8004F6B0(void);

extern void fn_8004B79C(void);

extern void fn_80057378(void);

extern void fn_80046738(void);

extern void fn_80046718(void);

extern void fn_800424B8(void);

extern void fn_80047578(void);

extern void fn_80057CC4(void);

extern void fn_80058630(void);

extern void fn_8005870C(void);

struct adx_inisBss {
    int adxt_init_cnt;
    unsigned char padding_4[4];
    int adxt_svr_main_id;
    int adxt_svr_fs_id;
};
extern struct adx_inisBss lbl_80178CA8;

void ADXT_Finish(void) {
    struct adx_inisBss *bss = &lbl_80178CA8;

    (bss->adxt_init_cnt)--;
    if ((bss->adxt_init_cnt) == 0) {

        fn_8004EF68();
        fn_8004F6B0();
        fn_8004B79C();
        fn_80057378();
        fn_80046738();
        fn_800592E0(2, 1);
        fn_800592E0(4, (bss->adxt_svr_fs_id));
        fn_800592E0(5, (bss->adxt_svr_main_id));
        fn_80058B54();
        fn_800424B8();
        fn_80047578();
        fn_80057CC4();
        fn_80058630();
        fn_8005870C();
        fn_80046718();
    }
}
