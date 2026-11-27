#include "dol/trk_memory.h"

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
extern void DCFlushRange(void *, u32);
extern void PPCHalt(void);
extern void OSReport(const char *, ...);
extern u32 OSEnableScheduler(u32, u32);
void TRKInterruptHandler(void);

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
/* MetroTRK Os/dolphin/dolphin_trk_glue.c: TRKLoadContext is a CodeWarrior asm function in
 * the original. It reloads the saved register file with lmw, restores CR/LR/CTR/XER and the
 * SPRGs, clears MSR[EE|RI] with mtmsr and branches to TRKInterruptHandler, with no compiler
 * frame. */
asm void TRKLoadContext(register u32 context, register u32 exception) {
    nofralloc
    lwz r0, 0x0(r3)
    lwz r1, 0x4(r3)
    lwz r2, 0x8(r3)
    lhz r5, 0x1a2(r3)
    rlwinm. r6, r5, 0, 30, 30
    beq L_8008D24C
    rlwinm r5, r5, 0, 31, 29
    sth r5, 0x1a2(r3)
    lmw r5, 0x14(r3)
    b L_8008D250
L_8008D24C:
    lmw r13, 0x34(r3)
L_8008D250:
    mr r31, r3
    mr r3, r4
    lwz r4, 0x80(r31)
    mtcrf 255, r4
    lwz r4, 0x84(r31)
    mtlr r4
    lwz r4, 0x88(r31)
    mtctr r4
    lwz r4, 0x8c(r31)
    mtxer r4
    mfmsr r4
    rlwinm r4, r4, 0, 17, 15
    rlwinm r4, r4, 0, 31, 29
    mtmsr r4
    mtsprg 1, r2
    lwz r4, 0xc(r31)
    mtsprg 2, r4
    lwz r4, 0x10(r31)
    mtsprg 3, r4
    lwz r2, 0x198(r31)
    lwz r4, 0x19c(r31)
    lwz r31, 0x7c(r31)
    b TRKInterruptHandler
}

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

s32 TRKInitializeIntDrivenUART(u32 arg0, u32 arg1, u32 arg2, void **arg3) {
    ((DBCommInitFn)gDBCommTable[0].initialize)((u32)arg3, (u32)TRKEXICallBack, arg2, (u32)arg3);
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
