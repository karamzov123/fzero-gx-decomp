#include "types.h"
#pragma use_lmw_stmw on
struct Sig_fn_80088B00_fn_80088B00_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};
struct Sig_fn_80089144_fn_80089144_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u32 unk_C;
};
extern s32 fn_80088B00(struct Sig_fn_80088B00_fn_80088B00_Arg0 *);
extern s32 fn_80089144(struct Sig_fn_80089144_fn_80089144_Arg0 *, u32);
extern u32 TRKGetBuffer(s32);
extern u32 fn_800891B4(u32);
extern u32 fn_8008A764(u32, u32);
extern s32 fn_800894FC(void);
static const char fzgx_pool_strings_lbl_80095A78_0[24] = "Calling MessageSend\n";
static const char fzgx_pool_strings_lbl_80095A78_18[40] = "msg_command : 0x%02x hdr->cmdID 0x%02x\n";
static const char fzgx_pool_strings_lbl_80095A78_40[20] = "msg_error : 0x%02x\n";
static const char fzgx_pool_strings_lbl_80095A78_54[84] = "RequestSend : Bad ack or non ack received msg_command : 0x%02x msg_error 0x%02x\n";

extern void MWTRACE(u32, ...);
extern void fn_8008944C(u32);

#pragma opt_loop_invariants off
s32 fn_8008AB20(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    
    s32 v2;
    u32 v5;
    u32 v3;
    s32 v1;
    u16 v6;
    u32 v9;
    s32 v10;
    s32 v4;

    v1 = arg3 + 1;
    
    v2 = 0;
    v4 = 1;
    *(s32 *)arg1 = -1;
    while (v1 != 0 && *(s32 *)arg1 == -1 && v2 == 0) {
        MWTRACE(1, (u32)(((u8 *)fzgx_pool_strings_lbl_80095A78_0)));
        v2 = fn_80088B00((struct Sig_fn_80088B00_fn_80088B00_Arg0 *)arg0);
        if (v2 == 0) {
            if ((s32)arg4 != 0) v3 = 0;
receive:
            do {
                *(s32 *)arg1 = fn_800894FC();
                v10 = *(s32 *)arg1;
                if (v10 != -1) break;
                if ((s32)arg4 == 0) continue;
                v3++;
                if (v3 >= 0x4C4B3EC) break;
            } while (1);
            if (v10 != -1) {
                v4 = 0;
                v5 = TRKGetBuffer(v10);
                fn_80089144((struct Sig_fn_80089144_fn_80089144_Arg0 *)v5, 0);
                fn_8008A764(v5 + 16, *(u32 *)(v5 + 8));
                v6 = *(u8 *)(v5 + 20);
                MWTRACE(1, (u32)(((u8 *)fzgx_pool_strings_lbl_80095A78_18)), v6, v6);
                if (v6 < 128) {
                    fn_8008944C(*(u32 *)arg1);
                    *(s32 *)arg1 = -1;
                    goto receive; /* Keep the verified branch to receive. */
                }
            }
            if (*(s32 *)arg1 != -1) {
                if (*(u32 *)(v5 + 8) < 64) v4 = 1;
                if (v2 == 0 && v4 == 0) {
                    v9 = *(u8 *)(v5 + 24);
                    MWTRACE(1, (u32)(((u8 *)fzgx_pool_strings_lbl_80095A78_40)), v9);
                }
                if (v2 == 0 && v4 == 0 && ((s32)v6 != 128 || (s32)v9 != 0)) {
                    MWTRACE(8, (u32)(((u8 *)fzgx_pool_strings_lbl_80095A78_54)), v6, v9);
                    v4 = 1;
                }
                if (v2 != 0 || v4 != 0) {
                    fn_800891B4(*(u32 *)arg1);
                    *(s32 *)arg1 = -1;
                }
            }
        }
        v1--;
    }
    if (*(s32 *)arg1 == -1) v2 = 2048;
    return v2;
}
#pragma opt_loop_invariants reset

