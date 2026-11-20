#include "types.h"


/* --- dol/fn_800475C0.c --- */
struct fn_800475C0_lbl_8017B030 {
    u32 unk_0;
    u32 unk_4;
};

extern struct fn_800475C0_lbl_8017B030 lbl_8017B030[];
extern u32 memset(u32, u32, u32);

void fn_800475C0(void) {
    struct fn_800475C0_lbl_8017B030 *p_lbl_8017B030;
    p_lbl_8017B030 = (struct fn_800475C0_lbl_8017B030 *)&lbl_8017B030;
    memset((u32)((u8 *)(u32)p_lbl_8017B030 + 40), 0, 256);
    p_lbl_8017B030->unk_0 = 0;
    p_lbl_8017B030->unk_4 = 0;
}

/* --- dol/fn_80047608.c --- */
struct fn_80047608_lbl_8017B158 {
    u32 unk_0;
};
extern struct fn_80047608_lbl_8017B158 lbl_8017B158[];
extern u32 fn_80046738(void);
extern void fn_80046718(void);
extern u32 ADXSTM_ExecServer(void);
extern u32 cvFsExecServer(void);
extern u32 ADXF_ExecServer(void);


void fn_80047608(void) {
    fn_80046738();
    if ((s32) lbl_8017B158->unk_0 != 0) {
        fn_80046718();
        return;
    }
    lbl_8017B158->unk_0 = 1;
    fn_80046718();
    ADXSTM_ExecServer();
    lbl_8017B158->unk_0 = 2;
    cvFsExecServer();
    lbl_8017B158->unk_0 = 5;
    ADXSTM_ExecServer();
    lbl_8017B158->unk_0 = 6;
    ADXF_ExecServer();
    lbl_8017B158->unk_0 = 0;
}
