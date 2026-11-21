#include <dolphin/os.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"
#include "types.h"


/* --- dol/OSGetResetButtonState.c --- */
extern u32 __OSBusClock : FZGX_ADDR___OSBusClock;

vu32 __PIRegs[12] : FZGX_ADDR___PIRegs;

extern OSTime __OSStartTime;

u8 GameChoice : FZGX_ADDR_GameChoice;

extern BOOL lbl_801A67DC;

extern BOOL lbl_801A67E0;

extern OSTime lbl_801A67E8;

extern OSTime lbl_801A67F0;

BOOL OSGetResetButtonState(void);

/* --- dol/fn_8000F5F0.c --- */
u32 fn_8000F5F0(void);

/* --- dol/WriteSramCallback.c --- */
struct WriteSramCallback_Scb_8015BFC0 {
    u8 pad_0[0x40];
    u32 unk_40;
    u8 pad_44[0x8];
    u32 unk_4C;
};

extern struct WriteSramCallback_Scb_8015BFC0 Scb_8015BFC0;
extern u32 WriteSram(u32, u32, u32);

void WriteSramCallback(void) {
    struct WriteSramCallback_Scb_8015BFC0 *p_Scb_8015BFC0;
    u32 v0;
    u32 v1;
    u32 t0;
    p_Scb_8015BFC0 = (struct WriteSramCallback_Scb_8015BFC0 *)&Scb_8015BFC0;
    v0 = (u32)((u8 *)(u32)p_Scb_8015BFC0 + 64);
    v1 = p_Scb_8015BFC0->unk_40;
    p_Scb_8015BFC0->unk_4C = (WriteSram((u32)((u8 *)(u32)p_Scb_8015BFC0 + v1), v1, (64 - v1)));
    if ((s32)p_Scb_8015BFC0->unk_4C != 0) {
    *(u32 *)((u8 *)v0 + 0) = 64;
    }
}
