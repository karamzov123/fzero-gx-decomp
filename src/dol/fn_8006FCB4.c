#include "types.h"
#include "dolphin/os/OSTime.h"


/* --- dol/fn_8006FCB4.c --- */
extern u16 lbl_801A6CC4;
extern u16 lbl_801A6CC6;
extern u32 VISetBlack(u32);
extern u32 GXDrawDone(void);
extern u32 fn_80034444(u32);
extern u32 fn_8007001C(void);
extern u32 fn_80070100(void);
extern u32 lbl_801A6CCC;
extern u32 lbl_801A6CD0;
extern u32 lbl_801A6CD4;
extern u8 lbl_801A6CB4;
extern void fn_800700F4(void);

void fn_8006FCB4(void) {
    VISetBlack(0);
    fn_80034444((u32)fn_800700F4);
    lbl_801A6CB4 = 0;
    GXDrawDone();
    lbl_801A6CD0 = 1;
    lbl_801A6CCC = -1;
    lbl_801A6CC6 = 0;
    lbl_801A6CC4 = 0;
    fn_80070100();
    fn_8007001C();
    lbl_801A6CD4 = 0;
}

/* --- dol/fn_8006FD1C.c --- */
extern void GXSetDrawDone(void);
extern u32 lbl_801A6CE0;
extern u32 fn_80032368(void);
extern u32 GXGetFifoPtrs(u32, u32 *, u32 *);
extern u32 fn_80032360(void);
extern void fn_80031FF4(void);
extern u32 fn_800700B4(void);
extern u32 fn_80070068(void);
typedef struct Fifo {
    u32 first;
    u8 pad[0x10];
    void *fifo;
} Fifo;

extern Fifo **lbl_801A6D30;
extern void GXSetGPFifo(void *);
extern u32 lbl_801A6CD8;
extern void fn_80072B28(u32);
extern u32 fn_80035110(u32, u32);
extern u32 fn_8001BE6C(void);
extern u32 OSGetTick(void);
extern u32 lbl_801A6CC8;
extern u32 lbl_801A6CB8;
extern u32 lbl_801A6CC0;
extern u16 lbl_801A6CBC;

void fn_8006FD1C(void) {
    u32 value_c;
    u32 value_8;

    lbl_801A6CB4 = 0;
    GXSetDrawDone();

    if ((lbl_801A6CE0 & 0x04) != 0) {
        GXGetFifoPtrs(fn_80032368(), &value_c, &value_8);
        fn_80032360();
        fn_80031FF4();
        fn_800700B4();
        GXSetGPFifo(lbl_801A6D30[fn_80070068() + 5]);
    }

    GXGetFifoPtrs(fn_80032360(), &value_c, &value_8);
    lbl_801A6CD8 = value_8;
    fn_80072B28(1);
    fn_8007001C();
    fn_80035110((u32)lbl_801A6D30[0], 1);
    fn_80070100();
    lbl_801A6CCC = fn_8001BE6C();
    lbl_801A6CC8 = OSGetTick();
    lbl_801A6CC6 = 0;
    lbl_801A6CC4 = 0;
    lbl_801A6CB8 = OSGetTick();
    lbl_801A6CC0 = 0;
    lbl_801A6CBC = 0;
}

/* --- dol/fn_8006FDEC.c --- */
extern char lbl_8015AA10[];
extern u32 lbl_801A6CB0;
extern u32 lbl_801A6CE4;
extern u32 __OSBusClock : 0x800000F8; /* fzgx-allow: A1 fixed cached-RAM bus-clock word; retail carries no reloc */
extern void OSReport(const char *, ...);
extern OSTime OSGetTime(void);

s32 fn_8006FDEC(void) {
    u32 value_c;
    u32 value_8;
    s32 ret;
    OSTime t0;

    ret = 0;
    t0 = OSGetTime();

    while (lbl_801A6CB4 == 0) {
        if (OSGetTime() - t0 > (OSTime)(__OSBusClock >> 2)) {
            OSReport(lbl_8015AA10, lbl_801A6CC6, lbl_801A6CC4, lbl_801A6CBC,
                     (lbl_801A6CC0 << 3) / ((__OSBusClock >> 2) / 125000));
            if (lbl_801A6CB0 != 0) {
                ((void (*)(void))lbl_801A6CB0)();
            }
            ret = 1;
            break;
        }
    }

    GXGetFifoPtrs(fn_80032360(), &value_c, &value_8);

    if (lbl_801A6CD8 > value_8) {
        lbl_801A6CD4 = lbl_801A6CE4 + value_8 - lbl_801A6CD8;
    } else {
        lbl_801A6CD4 = value_8 - lbl_801A6CD8;
    }

    return ret;
}
