#include "types.h"
#include "sdk_addresses.h"


/* --- dol/DSPAddTask.c --- */
extern u32 OSDisableInterrupts(void);
extern void __DSP_insert_task(void *);
extern void OSRestoreInterrupts(u32);
extern u32 lbl_801A6BB8;
extern void __DSP_boot_task(void *);

typedef struct {
    u32 field0;
    u8 pad04[4];
    u32 field8;
} Fn80028DD8Data;

void *DSPAddTask(Fn80028DD8Data *data) {
    u32 interrupts;
    interrupts = OSDisableInterrupts();
    __DSP_insert_task(data);
    data->field0 = 0;
    data->field8 = 1;
    OSRestoreInterrupts(interrupts);
    if (data == (Fn80028DD8Data *)lbl_801A6BB8) {
        __DSP_boot_task(data);
    }
    return data;
}

/* --- dol/fn_80028E48.c --- */
/* --- dol/fn_80028E48.c --- */

typedef struct {
    u8 pad0[8];
    u32 field8;
} Fn80028E48Data;

Fn80028E48Data *fn_80028E48(Fn80028E48Data *data) {
    u32 level;

    level = OSDisableInterrupts();
    data->field8 |= 2;
    OSRestoreInterrupts(level);
    return data;
}

/* --- dol/fn_80028E88.c --- */
/* Hardware state can change asynchronously. */
volatile u16 __DSPRegs[32] : FZGX_ADDR___DSPRegs;

typedef struct Fn80028E88Data {
    u32 field0;
    u32 field4;
} Fn80028E88Data;

extern Fn80028E88Data *lbl_801A6BBC;
extern Fn80028E88Data *lbl_801A6BAC;
extern u32 lbl_801A6BA8;

Fn80028E88Data *fn_80028E88(Fn80028E88Data *data) {
    u32 level;

    level = OSDisableInterrupts();
    if (lbl_801A6BBC == data) {
        lbl_801A6BAC = data;
        lbl_801A6BA8 = 1;
        OSRestoreInterrupts(level);
        return data;
    }
    if (data->field4 < lbl_801A6BBC->field4) {
        lbl_801A6BAC = data;
        lbl_801A6BA8 = 1;
        if (lbl_801A6BBC->field0 == 1) {
            u32 inner;

            inner = OSDisableInterrupts();
            __DSPRegs[5] = (__DSPRegs[5] & ~0xA8) | 2;
            OSRestoreInterrupts(inner);
        }
        OSRestoreInterrupts(level);
        return data;
    }
    OSRestoreInterrupts(level);
    return 0;
}

/* --- dol/fn_80028F50.c --- */
void fn_80028F50(u32 arg, ...) {
}
