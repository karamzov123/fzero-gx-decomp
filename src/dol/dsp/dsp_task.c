#include <types.h>
#include <dolphin/dsp.h>
#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

u32 DSPCheckMailToDSP(void);

u32 DSPCheckMailFromDSP(void);

u32 DSPReadMailFromDSP(void);

void DSPSendMailToDSP(u32 mail);

extern DSPTaskInfo *lbl_801A6BBC;

extern DSPTaskInfo *lbl_801A6BB4;

extern DSPTaskInfo *lbl_801A6BB8;

void __DSP_exec_task(DSPTaskInfo *, DSPTaskInfo *);

void __DSP_remove_task(DSPTaskInfo *task);

vu16 __DSPRegs[32] : FZGX_ADDR___DSPRegs;

extern DSPTaskInfo *lbl_801A6BAC;

extern BOOL lbl_801A6BA8;

void __DSP_exec_task(DSPTaskInfo *curr, DSPTaskInfo *next);

void __DSPHandler(__OSInterrupt, OSContext *context) {
    DSPTaskInfo *tmp_task;
    OSContext exceptionContext;
    u16 tmp;
    u32 mail;
    tmp = __DSPRegs[5];
    tmp = (u16)(tmp & ~0x28) | 0x80;
    __DSPRegs[5] = tmp;
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(&exceptionContext);
    while (!DSPCheckMailFromDSP())
        ;
    mail = DSPReadMailFromDSP();
    if ((lbl_801A6BBC->flags & 0x00000002) && (mail == 0xDCD10002)) {
        mail = 0xDCD10003;
    }
    switch (mail) {
    case 0xDCD10000:
        lbl_801A6BBC->state = 1;
        if (lbl_801A6BBC->init_cb) {
            (*(lbl_801A6BBC->init_cb))((void *)(lbl_801A6BBC));
        }
        break;
    case 0xDCD10001:
        lbl_801A6BBC->state = 1;
        if (lbl_801A6BBC->res_cb) {
            (*(lbl_801A6BBC->res_cb))((void *)(lbl_801A6BBC));
        }
        break;
    case 0xDCD10002:
        if (lbl_801A6BA8) {
            if (lbl_801A6BBC == lbl_801A6BAC) {
                DSPSendMailToDSP(0xCDD10003);
                while (DSPCheckMailToDSP()) {
                }
                lbl_801A6BAC = 0;
                lbl_801A6BA8 = 0;
                if (lbl_801A6BBC->res_cb) {
                    (*(lbl_801A6BBC->res_cb))((void *)(lbl_801A6BBC));
                }
                break;
            } else {
                DSPSendMailToDSP(0xCDD10001);
                while (DSPCheckMailToDSP())
                    ;
                __DSP_exec_task(lbl_801A6BBC, lbl_801A6BAC);
                lbl_801A6BBC->state = 2;
                lbl_801A6BBC = lbl_801A6BAC;
                lbl_801A6BAC = 0;
                lbl_801A6BA8 = 0;
                break;
            }
        }
        if (lbl_801A6BBC->next == 0) {
            if (lbl_801A6BBC == lbl_801A6BB8) {
                DSPSendMailToDSP(0xCDD10003);
                while (DSPCheckMailToDSP())
                    ;
                if (lbl_801A6BBC->res_cb) {
                    (*(lbl_801A6BBC->res_cb))((void *)(lbl_801A6BBC));
                }
            } else {
                DSPSendMailToDSP(0xCDD10001);
                while (DSPCheckMailToDSP()) {
                }
                __DSP_exec_task(lbl_801A6BBC, lbl_801A6BB8);
                lbl_801A6BBC->state = 2;
                lbl_801A6BBC = lbl_801A6BB8;
            }
        } else {
            DSPSendMailToDSP(0xCDD10001);
            while (DSPCheckMailToDSP()) {
            }
            __DSP_exec_task(lbl_801A6BBC, lbl_801A6BBC->next);
            lbl_801A6BBC->state = 2;
            lbl_801A6BBC = lbl_801A6BBC->next;
        }
        break;
    case 0xDCD10003:
        if (lbl_801A6BA8) {
            if (lbl_801A6BBC->done_cb) {
                (*(lbl_801A6BBC->done_cb))((void *)(lbl_801A6BBC));
            }
            DSPSendMailToDSP(0xCDD10001);
            while (DSPCheckMailToDSP())
                ;
            __DSP_exec_task(0, lbl_801A6BAC);
            __DSP_remove_task(lbl_801A6BBC);
            lbl_801A6BBC = lbl_801A6BAC;
            lbl_801A6BAC = 0;
            lbl_801A6BA8 = 0;
            break;
        }
        if (lbl_801A6BBC->next == 0) {
            if (lbl_801A6BBC == lbl_801A6BB8) {
                if (lbl_801A6BBC->done_cb) {
                    (*(lbl_801A6BBC->done_cb))((void *)(lbl_801A6BBC));
                }
                DSPSendMailToDSP(0xCDD10002);
                while (DSPCheckMailToDSP())
                    ;
                lbl_801A6BBC->state = 3;
                __DSP_remove_task(lbl_801A6BBC);
            } else {
                if (lbl_801A6BBC->done_cb) {
                    (*(lbl_801A6BBC->done_cb))((void *)(lbl_801A6BBC));
                }
                DSPSendMailToDSP(0xCDD10001);
                while (DSPCheckMailToDSP())
                    ;
                lbl_801A6BBC->state = 3;
                __DSP_exec_task(0, lbl_801A6BB8);
                lbl_801A6BBC = lbl_801A6BB8;
                __DSP_remove_task(lbl_801A6BB4);
            }
        } else {
            if (lbl_801A6BBC->done_cb) {
                (*(lbl_801A6BBC->done_cb))((void *)(lbl_801A6BBC));
            }
            DSPSendMailToDSP(0xCDD10001);
            while (DSPCheckMailToDSP())
                ;
            lbl_801A6BBC->state = 3;
            __DSP_exec_task(0, lbl_801A6BBC->next);
            lbl_801A6BBC = lbl_801A6BBC->next;
            __DSP_remove_task(lbl_801A6BBC->prev);
        }
        break;
    case 0xDCD10004:
        if (lbl_801A6BBC->req_cb) {
            (*(lbl_801A6BBC->req_cb))((void *)(lbl_801A6BBC));
        }
        break;
    default:
        break;
    }
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(context);
}

void __DSP_exec_task(DSPTaskInfo *task, DSPTaskInfo *next) {
    if (task != 0) {
        DSPSendMailToDSP((u32)task->dram_mmem_addr);
        while (DSPCheckMailToDSP() != 0) {
        }
        DSPSendMailToDSP(task->dram_length);
        while (DSPCheckMailToDSP() != 0) {
        }
        DSPSendMailToDSP(task->dram_addr);
        while (DSPCheckMailToDSP() != 0) {
        }
    } else {
        DSPSendMailToDSP(0);
        while (DSPCheckMailToDSP() != 0) {
        }
        DSPSendMailToDSP(0);
        while (DSPCheckMailToDSP() != 0) {
        }
        DSPSendMailToDSP(0);
        while (DSPCheckMailToDSP() != 0) {
        }
    }

    DSPSendMailToDSP((u32)next->iram_mmem_addr);
    while (DSPCheckMailToDSP() != 0) {
    }
    DSPSendMailToDSP(next->iram_length);
    while (DSPCheckMailToDSP() != 0) {
    }
    DSPSendMailToDSP(next->iram_addr);
    while (DSPCheckMailToDSP() != 0) {
    }

    if (next->state == 0) {
        DSPSendMailToDSP(next->dsp_init_vector);
        while (DSPCheckMailToDSP() != 0) {
        }
        DSPSendMailToDSP(0);
        while (DSPCheckMailToDSP() != 0) {
        }
        DSPSendMailToDSP(0);
        while (DSPCheckMailToDSP() != 0) {
        }
        DSPSendMailToDSP(0);
        while (DSPCheckMailToDSP() != 0) {
        }
    } else {
        DSPSendMailToDSP(next->dsp_resume_vector);
        while (DSPCheckMailToDSP() != 0) {
        }
        DSPSendMailToDSP((u32)next->dram_mmem_addr);
        while (DSPCheckMailToDSP() != 0) {
        }
        DSPSendMailToDSP(next->dram_length);
        while (DSPCheckMailToDSP() != 0) {
        }
        DSPSendMailToDSP(next->dram_addr);
        while (DSPCheckMailToDSP() != 0) {
        }
    }
}

// Hardware or OS state can change asynchronously.
typedef volatile u32 vu32;

typedef s64 OSTime;

typedef void (*DSPCallback)(void *task);

typedef struct STRUCT_DSP_TASK_u1 {
    vu32 state;
    vu32 priority;
    vu32 flags;
    u16 *iram_mmem_addr;
    u32 iram_length;
    u32 iram_addr;
    u16 *dram_mmem_addr;
    u32 dram_length;
    u32 dram_addr;
    u16 dsp_init_vector;
    u16 dsp_resume_vector;
    DSPCallback init_cb;
    DSPCallback res_cb;
    DSPCallback done_cb;
    DSPCallback req_cb;
    struct STRUCT_DSP_TASK_u1 *next;
    struct STRUCT_DSP_TASK_u1 *prev;
    OSTime t_context;
    OSTime t_task;
} DSPTaskInfo_u1;

u32 DSPCheckMailToDSP(void);

u32 DSPCheckMailFromDSP(void);

u32 DSPReadMailFromDSP(void);

void DSPSendMailToDSP(u32 mail);

void fn_80028F50(const char *fmt, ...);

void __DSP_boot_task(DSPTaskInfo_u1 *task) {
// Hardware or OS state can change asynchronously.
    volatile u32 mail;
    while (!DSPCheckMailFromDSP())
        ;
    mail = DSPReadMailFromDSP();
    DSPSendMailToDSP(0x80F30000 | 0xA001); // fzgx-allow: A1 DSP mailbox command, not an address
    while (DSPCheckMailToDSP()) {
    }
    DSPSendMailToDSP((u32)(task->iram_mmem_addr));
    while (DSPCheckMailToDSP()) {
    }
    DSPSendMailToDSP(0x80F30000 | 0xC002); // fzgx-allow: A1 DSP mailbox command, not an address
    while (DSPCheckMailToDSP()) {
    }
    DSPSendMailToDSP((u32)(task->iram_addr & 0xffff));
    while (DSPCheckMailToDSP()) {
    }
    DSPSendMailToDSP(0x80F30000 | 0xA002); // fzgx-allow: A1 DSP mailbox command, not an address
    while (DSPCheckMailToDSP()) {
    }
    DSPSendMailToDSP(task->iram_length);
    while (DSPCheckMailToDSP()) {
    }
    DSPSendMailToDSP(0x80F30000 | 0xB002); // fzgx-allow: A1 DSP mailbox command, not an address
    while (DSPCheckMailToDSP()) {
    }
    DSPSendMailToDSP(0x00000000);
    while (DSPCheckMailToDSP()) {
    }
    DSPSendMailToDSP(0x80F30000 | 0xD001); // fzgx-allow: A1 DSP mailbox command, not an address
    while (DSPCheckMailToDSP()) {
    }
    DSPSendMailToDSP((u32)(0xffff & task->dsp_init_vector));
    while (DSPCheckMailToDSP()) {
    }
    fn_80028F50("DSP is booting task: 0x%08X\n", task);
    fn_80028F50("__DSP_boot_task()  : IRAM MMEM ADDR: 0x%08X\n", (u32)(task->iram_mmem_addr));
    fn_80028F50("__DSP_boot_task()  : IRAM DSP ADDR : 0x%08X\n", (u32)(task->iram_addr));
    fn_80028F50("__DSP_boot_task()  : IRAM LENGTH   : 0x%08X\n", (u32)(task->iram_length));
    fn_80028F50("__DSP_boot_task()  : DRAM MMEM ADDR: 0x%08X\n", (u32)(task->dram_length));
    fn_80028F50("__DSP_boot_task()  : Start Vector  : 0x%08X\n", (u32)(task->dsp_init_vector));
}

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

// fn_80029824: empty in retail (single blr).
void fn_80029824(void) {
}
