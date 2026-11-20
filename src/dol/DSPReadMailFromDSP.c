#include <types.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"
#include <dolphin/dsp.h>
#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>


/* --- dol/DSPReadMailFromDSP.c --- */
vu16 __DSPRegs[32] : FZGX_ADDR___DSPRegs;

u32 DSPReadMailFromDSP() {
    u16 reg1;
    u16 reg2;
    reg1 = __DSPRegs[2];
    reg2 = __DSPRegs[3];
    return reg1 << 16 | reg2;
}

/* --- dol/DSPSendMailToDSP.c --- */
void DSPSendMailToDSP(u32 mail) {
    __DSPRegs[0] = mail >> 16;
    __DSPRegs[1] = mail;
}

/* --- dol/DSPInit.c --- */
struct dspMessages {
    char padding_0[72];
    char message_48[30];
    char padding_66[2];
    char message_68[12];
    char message_74[9];
};

typedef enum {
    OS_INTR_MEM_0,
    OS_INTR_MEM_1,
    OS_INTR_MEM_2,
    OS_INTR_MEM_3,
    OS_INTR_MEM_ADDRESS,
    OS_INTR_DSP_AI,
    OS_INTR_DSP_ARAM,
    OS_INTR_DSP_DSP,
    OS_INTR_AI_AI,
    OS_INTR_EXI_0_EXI,
    OS_INTR_EXI_0_TC,
    OS_INTR_EXI_0_EXT,
    OS_INTR_EXI_1_EXI,
    OS_INTR_EXI_1_TC,
    OS_INTR_EXI_1_EXT,
    OS_INTR_EXI_2_EXI,
    OS_INTR_EXI_2_TC,
    OS_INTR_PI_CP,
    OS_INTR_PI_PE_TOKEN,
    OS_INTR_PI_PE_FINISH,
    OS_INTR_PI_SI,
    OS_INTR_PI_DI,
    OS_INTR_PI_RSW,
    OS_INTR_PI_ERROR,
    OS_INTR_PI_VI,
    OS_INTR_PI_DEBUG,
    OS_INTR_PI_HSP,
    OS_INTR_PI_ACR,
    OS_INTR_28,
    OS_INTR_29,
    OS_INTR_30,
    OS_INTR_31,
    OS_INTR_MAX
} OSInterruptType;

extern struct dspMessages lbl_8012A848;

__OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt interrupt, __OSInterruptHandler handler);

void OSRegisterVersion(const char *version);

// Hardware or OS state can change asynchronously.
volatile u16
    __DSPRegs[32] : FZGX_ADDR___DSPRegs; // fzgx-allow: S2 SDK asynchronous state

extern DSPTaskInfo *lbl_801A6BB0;

extern DSPTaskInfo *lbl_801A6BB4;

extern DSPTaskInfo *lbl_801A6BB8;

extern DSPTaskInfo *lbl_801A6BBC;

void fn_80028F50(const char *fmt, ...);

extern const char *lbl_801A6500;

extern BOOL lbl_801A6BA0;

extern void __DSPHandler(__OSInterrupt, OSContext *);

void DSPInit(void) {
    struct dspMessages *messages = &lbl_8012A848;

    BOOL old;
    u16 tmp;
    fn_80028F50(messages->message_48, messages->message_68, messages->message_74);
    if (lbl_801A6BA0 == 1)
        return;
    OSRegisterVersion(lbl_801A6500);
    old = OSDisableInterrupts();
    __OSSetInterruptHandler(7, __DSPHandler);
    __OSUnmaskInterrupts((0x80000000u >> (OS_INTR_DSP_DSP)));
    tmp = __DSPRegs[5];
    tmp = (tmp & ~0xA8) | 0x800;
    __DSPRegs[5] = tmp;
    tmp = __DSPRegs[5];
    __DSPRegs[5] = tmp = tmp & ~0xAC;
    lbl_801A6BB8 = lbl_801A6BB4 = lbl_801A6BBC = lbl_801A6BB0 = ((void *)0);
    lbl_801A6BA0 = 1;
    OSRestoreInterrupts(old);
}
