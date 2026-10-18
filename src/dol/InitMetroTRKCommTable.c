#include "types.h"

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
extern u8 EndofProgramInstruction_80095BC8[];
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

#pragma opt_dead_assignments off
s32 InitMetroTRKCommTable(s32 transport) {
    s32 result = 1;
    u8 *str = (u8 *)EndofProgramInstruction_80095BC8;

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
#pragma opt_dead_assignments reset

