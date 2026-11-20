#include <types.h>
#include <dolphin/dsp.h>
#include "types.h"


/* --- dol/__DSP_insert_task.c --- */
/* --- dol/__DSP_insert_task.c --- */
extern DSPTaskInfo *lbl_801A6BBC;

extern DSPTaskInfo *lbl_801A6BB4;

extern DSPTaskInfo *lbl_801A6BB8;

void __DSP_insert_task(DSPTaskInfo *task) {
    DSPTaskInfo *temp;
    if (lbl_801A6BB8 == 0) {
        lbl_801A6BB8 = lbl_801A6BB4 = lbl_801A6BBC = task;
        task->next = task->prev = 0;
    } else {
        temp = lbl_801A6BB8;
        while (temp) {
            if (task->priority < temp->priority) {
                task->prev = temp->prev;
                temp->prev = task;
                task->next = temp;
                if (task->prev == 0) {
                    lbl_801A6BB8 = task;
                } else {
                    (task->prev)->next = task;
                }
                break;
            }
            temp = temp->next;
        }
        if (temp == 0) {
            lbl_801A6BB4->next = task;
            task->next = 0;
            task->prev = lbl_801A6BB4;
            lbl_801A6BB4 = task;
        }
    }
}

/* --- dol/__DSP_remove_task.c --- */
void __DSP_remove_task(DSPTaskInfo *task) {
    task->flags = 0x00000000;
    task->state = 3;
    if (lbl_801A6BB8 == task) {
        if (task->next) {
            lbl_801A6BB8 = (task->next);
            task->next->prev = 0;
        } else {
            lbl_801A6BB8 = lbl_801A6BB4 = lbl_801A6BBC = 0;
        }
    } else if (lbl_801A6BB4 == task) {
        lbl_801A6BB4 = (task->prev);
        task->prev->next = 0;
        lbl_801A6BBC = lbl_801A6BB8;
    } else {
        lbl_801A6BBC = task->next;
        task->prev->next = task->next;
        task->next->prev = task->prev;
    }
}

/* --- dol/fn_80029824.c --- */
// fn_80029824: empty in retail (single blr).
void fn_80029824(void) {
}

/* --- dol/__CARDSyncCallback.c --- */
extern u32 OSWakeupThread(u32);
extern u32 lbl_80177960[];

void __CARDSyncCallback(u32 arg0) {
    s32 v0;
    v0 = (arg0 * 272);
    OSWakeupThread((u32)((u8 *)((u8 *)&lbl_80177960 + v0) + 140));
}
