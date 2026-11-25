#include "types.h"

extern u32 AXRNA_SetAdjsfreqFlg(void);
extern u32 AXRNA_SetStmHdInfo(void);
extern u32 AXRNA_DiscardData(void);
extern u32 AXRNA_SetBitPerSmpl(void);
extern u32 AXRNA_SetOutPan(void);
struct AXRNAHandle;
extern void AXRNA_SetOutVol(struct AXRNAHandle *, s32);
extern u32 AXRNA_SetSfreq(void);
extern u32 AXRNA_SetNumChan(void);
extern u32 AXRNA_ExecServer(void);
extern u32 AXRNA_GetNumRoom(void);
extern u32 AXRNA_GetNumData(void);
extern u32 AXRNA_SetPlaySw();
extern u32 AXRNA_SetTransSw();
extern u32 AXRNA_Destroy(u32);
extern u32 AXRNA_Create(void);
extern u32 AXRNA_EntryErrFunc(void);
extern u32 AXRNA_Finish(void);
extern u32 AXRNA_Init(void);

void fn_8004ED3C(void) {
    AXRNA_SetAdjsfreqFlg();
}

s32 fn_8004ED5C(void) {
    AXRNA_SetStmHdInfo();
    return 0;
}

// fn_8004ED80: empty in retail (single blr).
void fn_8004ED80(void) {
}

void fn_8004ED84(void) {
    AXRNA_DiscardData();
}

void fn_8004EDA4(void) {
    AXRNA_SetBitPerSmpl();
}

void fn_8004EDC4(void) {
    AXRNA_SetOutPan();
}

void fn_8004EDE4(struct AXRNAHandle *handle, s32 value) {
    AXRNA_SetOutVol(handle, value);
}

void fn_8004EE04(void) {
    AXRNA_SetSfreq();
}

void fn_8004EE24(void) {
    AXRNA_SetNumChan();
}

void fn_8004EE44(void) {
    AXRNA_ExecServer();
}

void fn_8004EE64(void) {
    AXRNA_GetNumRoom();
}

void fn_8004EE84(void) {
    AXRNA_GetNumData();
}

void fn_8004EEA4(void) {
    AXRNA_SetPlaySw();
}

void fn_8004EEC4(void) {
    AXRNA_SetTransSw();
}

void fn_8004EEE4(u32 arg0) {
    AXRNA_SetPlaySw(arg0, 0);
    AXRNA_SetTransSw(arg0, 0);
    AXRNA_Destroy(arg0);
}

void fn_8004EF28(void) {
    AXRNA_Create();
}

void fn_8004EF48(void) {
    AXRNA_EntryErrFunc();
}

void fn_8004EF68(void) {
    AXRNA_Finish();
}

void fn_8004EF88(void) {
    AXRNA_Init();
}
