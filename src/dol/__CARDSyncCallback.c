#include <types.h>
#include <dolphin/dsp.h>
#include "types.h"


/* --- dol/__DSP_insert_task.c --- */
/* --- dol/__DSP_insert_task.c --- */
extern DSPTaskInfo *lbl_801A6BBC;

extern DSPTaskInfo *lbl_801A6BB4;

extern DSPTaskInfo *lbl_801A6BB8;

void __DSP_insert_task(DSPTaskInfo *task);

/* --- dol/__DSP_remove_task.c --- */
void __DSP_remove_task(DSPTaskInfo *task);

/* --- dol/fn_80029824.c --- */
// fn_80029824: empty in retail (single blr).
void fn_80029824(void);

/* --- dol/__CARDSyncCallback.c --- */
extern u32 OSWakeupThread(u32);
extern u32 lbl_80177960[];

void __CARDSyncCallback(u32 arg0) {
    s32 v0;
    v0 = (arg0 * 272);
    OSWakeupThread((u32)((u8 *)((u8 *)&lbl_80177960 + v0) + 140));
}
