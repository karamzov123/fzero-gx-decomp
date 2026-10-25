#include "types.h"

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
