#include "types.h"
#include "sdk_addresses.h"


/* --- dol/fn_80028DD0.c --- */
extern u32 lbl_801A6BA0;

u32 fn_80028DD0(void);

/* --- dol/DSPAddTask.c --- */
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

void *DSPAddTask(Fn80028DD8Data *data);

/* --- dol/fn_80028E48.c --- */
/* --- dol/fn_80028E48.c --- */

typedef struct {
    u8 pad0[8];
    u32 field8;
} Fn80028E48Data;

Fn80028E48Data *fn_80028E48(Fn80028E48Data *data);

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

Fn80028E88Data *fn_80028E88(Fn80028E88Data *data);

/* --- dol/fn_80028F50.c --- */
void fn_80028F50(u32 arg, ...) {
}
