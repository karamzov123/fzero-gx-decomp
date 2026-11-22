#include "types.h"

typedef u32 (*DBCommInitFn)(u32, u32, u32, u32);
typedef u32 (*DBCommVoidFn)(void);
typedef u32 (*DBCommIOFn)(u32, u32);

typedef struct DBCommTable {
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
} DBCommTable;

extern DBCommTable gDBCommTable[];
extern u8 EndofProgramInstruction[];
extern u8 TRK_Use_BBA[];
extern u32 lbl_80095BCC[];

extern void ICInvalidateRange(void *, u32);
extern void fn_800035C0(void *, void *, u32);
extern void DCFlushRange(void *, u32);
extern void PPCHalt(void);
extern void OSReport(const char *, ...);
extern u32 OSEnableScheduler(u32, u32);
extern u32 TRKLoadContext(u32, u32);

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

void TRKEXICallBack(u32 arg0, u32 arg1);

// TRKUARTInterruptHandler: empty in retail (single blr).
void TRKUARTInterruptHandler(void) {
}

void InitializeProgramEndTrap(void) {
    u8 *trap = (u8 *)PPCHalt;

    fn_800035C0(trap + 4, EndofProgramInstruction, 4);
    ICInvalidateRange(trap + 4, 4);
    DCFlushRange(trap + 4, 4);
}

void TRK_board_display(u32 arg0) {
    OSReport((const char *)&lbl_80095BCC, arg0);
}

void UnreserveEXI2Port(void) {
    ((DBCommVoidFn)gDBCommTable[0].pre_continue)();
}

void ReserveEXI2Port(void) {
    ((DBCommVoidFn)gDBCommTable[0].post_stop)();
}

s32 fn_8008D398(u32 arg0, u32 arg1) {
    u32 t0;
    t0 = ((DBCommIOFn)gDBCommTable[0].write)(arg0, arg1);
    return ((s32)((-t0) | t0) >> 31);
}

s32 fn_8008D3D4(u32 arg0, u32 arg1) {
    u32 t0;
    t0 = ((DBCommIOFn)gDBCommTable[0].read)(arg0, arg1);
    return ((s32)((-t0) | t0) >> 31);
}

void fn_8008D410(void) {
    ((DBCommVoidFn)gDBCommTable[0].peek)();
}

void fn_8008D440(void) {
    if (TRK_Use_BBA[0] == 0 && gDBCommTable[0].initialize_interrupts != 0) {
        ((DBCommVoidFn)gDBCommTable[0].initialize_interrupts)();
    }
}

s32 TRKInitializeIntDrivenUART(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    ((DBCommInitFn)gDBCommTable[0].initialize)(arg3, (u32)TRKEXICallBack, arg2, arg3);
    ((DBCommVoidFn)gDBCommTable[0].open)();
    return 0;
}

s32 InitMetroTRKCommTable(s32 transport) {
    s32 result = 1;
    u8 *str = (u8 *)EndofProgramInstruction;

    OSReport((const char *)(str + 8), transport);
    TRK_Use_BBA[0] = 0;
    if (transport == 2) {
        OSReport((const char *)(str + 0x20));
        TRK_Use_BBA[0] = 1;
        gDBCommTable[0].initialize = (u32)udp_cc_initialize;
        gDBCommTable[0].open = (u32)udp_cc_open;
        gDBCommTable[0].close = (u32)udp_cc_close;
        gDBCommTable[0].read = (u32)udp_cc_read;
        gDBCommTable[0].write = (u32)udp_cc_write;
        gDBCommTable[0].shutdown = (u32)udp_cc_shutdown;
        gDBCommTable[0].peek = (u32)udp_cc_peek;
        gDBCommTable[0].pre_continue = (u32)udp_cc_pre_continue;
        gDBCommTable[0].post_stop = (u32)udp_cc_post_stop;
        gDBCommTable[0].initialize_interrupts = 0;
        /* BBA setup succeeds directly; stub status only applies to the other transports. */
        return 0;
    } else if (transport == 1) {
        OSReport((const char *)(str + 0x38));
        result = Hu_IsStub();
        gDBCommTable[0].initialize = (u32)gdev_cc_initialize;
        gDBCommTable[0].open = (u32)gdev_cc_open;
        gDBCommTable[0].close = (u32)gdev_cc_close;
        gDBCommTable[0].read = (u32)gdev_cc_read;
        gDBCommTable[0].write = (u32)gdev_cc_write;
        gDBCommTable[0].shutdown = (u32)gdev_cc_shutdown;
        gDBCommTable[0].peek = (u32)gdev_cc_peek;
        gDBCommTable[0].pre_continue = (u32)gdev_cc_pre_continue;
        gDBCommTable[0].post_stop = (u32)gdev_cc_post_stop;
        gDBCommTable[0].initialize_interrupts = (u32)gdev_cc_initinterrupts;
    } else if (transport == 0) {
        OSReport((const char *)(str + 0x5c));
        result = AMC_IsStub();
        gDBCommTable[0].initialize = (u32)ddh_cc_initialize;
        gDBCommTable[0].open = (u32)ddh_cc_open;
        gDBCommTable[0].close = (u32)ddh_cc_close;
        gDBCommTable[0].read = (u32)ddh_cc_read;
        gDBCommTable[0].write = (u32)ddh_cc_write;
        gDBCommTable[0].shutdown = (u32)ddh_cc_shutdown;
        gDBCommTable[0].peek = (u32)ddh_cc_peek;
        gDBCommTable[0].pre_continue = (u32)ddh_cc_pre_continue;
        gDBCommTable[0].post_stop = (u32)ddh_cc_post_stop;
        gDBCommTable[0].initialize_interrupts = (u32)ddh_cc_initinterrupts;
    } else {
        OSReport((const char *)(str + 0x80), transport);
        OSReport((const char *)(str + 0xac));
        OSReport((const char *)(str + 0xdc));
    }
    return result;
}

void TRKEXICallBack(u32 arg0, u32 arg1) {
    OSEnableScheduler(arg0, arg1);
    TRKLoadContext(arg1, 1280);
}
