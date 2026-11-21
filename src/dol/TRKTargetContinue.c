#include "types.h"


/* --- dol/InitMetroTRKCommTable.c --- */
struct InitMetroTRKCommTable_gDBCommTable {
    u32 initialize;
    u32 initialize_interrupts;
    u32 shutdown;
    u32 peek;
    u32 read;
    u32 write;
    u32 open;
    u32 close;
    u32 pre_continue;
    u32 post_stop;
};

extern struct InitMetroTRKCommTable_gDBCommTable gDBCommTable[];
extern u8 EndofProgramInstruction[];
extern u8 TRK_Use_BBA[];
extern void OSReport(const char *, ...);
extern int Hu_IsStub(void);
extern int AMC_IsStub(void);
extern int udp_cc_initialize(void);
extern int udp_cc_open(void);
extern int udp_cc_close(void);
extern int udp_cc_read(void);
extern int udp_cc_write(void);
extern int udp_cc_shutdown(void);
extern int udp_cc_peek(void);
extern int udp_cc_pre_continue(void);
extern int udp_cc_post_stop(void);
extern s32 gdev_cc_initialize(u32, u32);
extern s32 gdev_cc_open(u32);
extern int gdev_cc_close(void);
extern u32 gdev_cc_read();
extern u32 gdev_cc_write(void *, s32);
extern int gdev_cc_shutdown(void);
extern s32 gdev_cc_peek(void);
extern s32 gdev_cc_pre_continue(void);
extern s32 gdev_cc_post_stop(void);
extern s32 gdev_cc_initinterrupts(void);
extern s32 ddh_cc_initialize(u32, u32);
extern s32 ddh_cc_open(u32);
extern int ddh_cc_close(void);
extern s32 ddh_cc_read(u32, s32);
extern s32 ddh_cc_write(u8 *, s32);
extern int ddh_cc_shutdown(void);
extern s32 ddh_cc_peek(void);
extern s32 ddh_cc_pre_continue(void);
extern s32 ddh_cc_post_stop(void);
extern s32 ddh_cc_initinterrupts(void);

s32 InitMetroTRKCommTable(s32 transport);

/* --- dol/TRKEXICallBack.c --- */
extern u32 OSEnableScheduler(u32, u32);
extern u32 TRKLoadContext(u32, u32);

void TRKEXICallBack(u32 arg0, u32 arg1);

/* --- dol/TRKTargetContinue.c --- */
extern u32 ReserveEXI2Port(void);
extern u32 TRKSwapAndGo(void);
extern u32 TRKTargetSetStopped(u32);
extern u32 UnreserveEXI2Port(void);

s32 TRKTargetContinue(void) {
    TRKTargetSetStopped(0);
    UnreserveEXI2Port();
    TRKSwapAndGo();
    ReserveEXI2Port();
    return 0;
}
