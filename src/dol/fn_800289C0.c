#include "types.h"
#include <types.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"
#include <dolphin/dsp.h>
#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>


/* --- dol/fn_800289C0.c --- */
/* --- dol/fn_800289C0.c --- */
/* --- dol/fn_800289C0.c --- */
struct fn_800289C0_Arg0 {
    u8 pad_0[0x8];
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
};

void fn_800289C0(struct fn_800289C0_Arg0 *arg0) {
    if (arg0->unk_10 == arg0->unk_C) {
        return;
    }
    arg0->unk_10 += arg0->unk_8;
    if (arg0->unk_8 > 0) {
        if (arg0->unk_10 > arg0->unk_C) {
            arg0->unk_10 = arg0->unk_C;
        }
    } else if (arg0->unk_8 < 0) {
        if (arg0->unk_10 < arg0->unk_C) {
            arg0->unk_10 = arg0->unk_C;
        }
    }
}

/* --- dol/fn_80028A1C.c --- */
struct fn_80028A1C_Arg0 {
    u8 pad_0[0x8];
    s32 unk_8;
    s32 unk_c;
    s32 unk_10;
};

void fn_80028A1C(struct fn_80028A1C_Arg0 *arg0) {
    if (arg0->unk_10 == arg0->unk_c) {
        return;
    }
    arg0->unk_10 = arg0->unk_10 + arg0->unk_8;
    if (arg0->unk_8 > 0) {
        if (arg0->unk_10 > arg0->unk_c) {
            arg0->unk_10 = arg0->unk_c;
        }
    } else if (arg0->unk_8 < 0) {
        if (arg0->unk_10 < arg0->unk_c) {
            arg0->unk_10 = arg0->unk_c;
        }
    }
}

/* --- dol/fn_80028A78.c --- */
struct fn_80028A78_Arg0 {
    f32 *unk_0;
    u32 unk_4;
    f32 unk_8;
    u32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
};

extern f32 lbl_801A7040;
extern u32 __cvt_fp2unsigned(f32);

void fn_80028A78(struct fn_80028A78_Arg0 *arg0) {
    f32 difference;
    f32 value;
    u32 index;

    arg0->unk_10 = arg0->unk_10 + arg0->unk_8;
    value = arg0->unk_10;
    if (value >= lbl_801A7040) {
        arg0->unk_10 = value - value;
        index = __cvt_fp2unsigned(value);
        arg0->unk_C = arg0->unk_C + index;
        arg0->unk_C = arg0->unk_C % arg0->unk_4;
        arg0->unk_14 = arg0->unk_18;
        arg0->unk_18 = arg0->unk_0[arg0->unk_C];
    }
    difference = arg0->unk_10 * (arg0->unk_14 - arg0->unk_18);
    arg0->unk_1C = arg0->unk_14 - difference;
}

/* --- dol/fn_80028B2C.c --- */
/* --- dol/fn_80028B2C.c --- */
/* --- dol/fn_80028B2C.c --- */
extern f32 lbl_801A6B98;

void fn_80028B2C(f32 arg0) {
    lbl_801A6B98 = arg0;
}

/* --- dol/fn_80028B34.c --- */
extern f32 lbl_801A6B9C;

void fn_80028B34(f32 arg0) {
    lbl_801A6B9C = arg0;
}

/* --- dol/fn_80028B3C.c --- */
struct fn_80028B3C_Arg0 {
    u8 pad_0[0x8];
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u32 unk_18;
    u8 unk_1C;
    u8 unk_1D;
    u8 unk_1E;
    u8 pad_1F;
    u16 unk_20;
    u16 unk_22;
    f32 unk_24;
    u32 unk_28;
};

extern u8 lbl_80129FD0[];
extern const f32 lbl_801A7048;
extern const f32 lbl_801A7050;
extern const f32 lbl_801A704C;
extern const f32 lbl_801A7054;
extern u32 fn_80025EEC(void);

void fn_80028B3C(struct fn_80028B3C_Arg0 *arg0) {
    u8 *base;
    u32 idx8;
    u32 idxC;
    f32 a;

    base = lbl_80129FD0;
    if (arg0->unk_18 == 0) {
        return;
    }
    a = arg0->unk_8;
    if (a > lbl_801A7048) {
        idx8 = __cvt_fp2unsigned(lbl_801A704C * (a / lbl_801A7050));
    } else if (a < lbl_801A7048) {
        f32 t = lbl_801A704C * (a / lbl_801A7050);
        idx8 = __cvt_fp2unsigned(lbl_801A704C + t);
    } else {
        idx8 = 0;
    }
    a = arg0->unk_C;
    if (a > lbl_801A7048) {
        idxC = __cvt_fp2unsigned(lbl_801A704C * (a / lbl_801A7050));
    } else if (a < lbl_801A7048) {
        f32 t = lbl_801A704C * (a / lbl_801A7050);
        idxC = __cvt_fp2unsigned(lbl_801A704C + t);
    } else {
        idxC = 0;
    }
    arg0->unk_18 = 0;
    if (fn_80025EEC() == 3) {
        arg0->unk_1C = base[idx8 + 720];
    } else {
        arg0->unk_1C = base[idx8];
    }
    arg0->unk_1D = base[idx8 + 360];
    arg0->unk_20 = base[idx8 + 1080];
    arg0->unk_22 = base[idx8 + 1440];
    arg0->unk_1E = base[idxC + 1800];
    arg0->unk_24 = arg0->unk_14 / lbl_801A6B98;
    arg0->unk_28 = (s32)(lbl_801A7054 * (arg0->unk_10 / lbl_801A6B9C));
}

/* --- dol/DSPCheckMailToDSP.c --- */
/* --- dol/DSPCheckMailToDSP.c --- */
/* --- dol/DSPCheckMailToDSP.c --- */
u32 DSPCheckMailToDSP(void) {
    return ((*(u16 *)0xCC005000 >> 15) & 0x1);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
}

/* --- dol/DSPCheckMailFromDSP.c --- */
u32 DSPCheckMailFromDSP(void) {
    return ((*(u16 *)0xCC005004 >> 15) & 0x1);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
}

/* --- dol/DSPReadMailFromDSP.c --- */
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
