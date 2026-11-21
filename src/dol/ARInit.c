#include <types.h>
#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"
#include <dolphin/os/OSCache.h>
#include "types.h"


/* --- dol/ARInit.c --- */
/* --- dol/ARInit.c --- */
typedef void (*ARCallback)(void);

vu16 __DSPRegs[32] : FZGX_ADDR___DSPRegs;

void OSRegisterVersion(const char *id);

__OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt interrupt, __OSInterruptHandler handler);

extern const char *lbl_801A64D8;

extern ARCallback lbl_801A69E0;

extern u32 lbl_801A69F0;

extern u32 lbl_801A69F4;

extern u32 *lbl_801A69F8;

// Hardware or OS state can change asynchronously.
extern volatile BOOL lbl_801A69FC; // fzgx-allow: S2 SDK asynchronous state

void __ARHandler(__OSInterrupt interrupt, OSContext *context);

void __ARChecksize(void);

void __ARHandler(__OSInterrupt interrupt, OSContext *context);

void __ARChecksize(void);

u32 ARInit(u32 *stack_index_addr, u32 num_entries) {
    BOOL old;
    u16 refresh;
    if (lbl_801A69FC == 1) {
        return 0x4000;
    }
    OSRegisterVersion(lbl_801A64D8);
    old = OSDisableInterrupts();
    lbl_801A69E0 = 0;
    __OSSetInterruptHandler(6, __ARHandler);
    __OSUnmaskInterrupts((0x80000000u >> (6)));
    lbl_801A69F0 = 0x4000;
    lbl_801A69F4 = num_entries;
    lbl_801A69F8 = stack_index_addr;
    refresh = (u16)(__DSPRegs[13] & 0x000000ff);
    __DSPRegs[13] = (u16)((__DSPRegs[13] & ~0x000000ff) | (refresh & 0x000000ff));
    __ARChecksize();
    lbl_801A69FC = 1;
    OSRestoreInterrupts(old);
    return lbl_801A69F0;
}

/* --- dol/__ARHandler.c --- */
void __ARHandler(__OSInterrupt interrupt, OSContext *context) {
    OSContext exceptionContext;
    u16 tmp;
    tmp = __DSPRegs[5];
    tmp = (u16)((tmp & ~0x00000088) | 0x20);
    __DSPRegs[5] = tmp;
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(&exceptionContext);
    if (lbl_801A69E0) {
        (*lbl_801A69E0)();
    }
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(context);
}

/* --- dol/__ARChecksize.c --- */
void *memset(void *dest, int value, size_t n);

void __ARClearInterrupt(void);


extern u32 lbl_801A69E4;

extern u32 lbl_801A69E8;

extern u32 lbl_801A69EC;

static inline void __ARClearInterrupt(void) {
    u16 tmp;
    tmp = __DSPRegs[5];
    tmp = (u16)((tmp & ~(0x00000080 | 0x00000008)) | 0x00000020);
    __DSPRegs[5] = tmp;
}

static inline void __ARWaitForDMA(void) {
    while (__DSPRegs[5] & 0x0200) {
    }
}

static inline void __ARWriteDMA(u32 mmem_addr, u32 aram_addr, u32 length) {
    __DSPRegs[16] = (u16)((__DSPRegs[16] & ~0x03ff) | (u16)(mmem_addr >> 16));
    __DSPRegs[16 + 1] = (u16)((__DSPRegs[16 + 1] & ~0xffe0) | (u16)(mmem_addr & 0xffff));
    __DSPRegs[18] = (u16)((__DSPRegs[18] & ~0x03ff) | (u16)(aram_addr >> 16));
    __DSPRegs[18 + 1] = (u16)((__DSPRegs[18 + 1] & ~0xffe0) | (u16)(aram_addr & 0xffff));
    __DSPRegs[20] = (u16)(__DSPRegs[20] & ~0x8000);
    __DSPRegs[20] = (u16)((__DSPRegs[20] & ~0x03ff) | (u16)(length >> 16));
    __DSPRegs[20 + 1] = (u16)((__DSPRegs[20 + 1] & ~0xffe0) | (u16)(length & 0xffff));
    __ARWaitForDMA();
    __ARClearInterrupt();
}

static inline void __ARReadDMA(u32 mmem_addr, u32 aram_addr, u32 length) {
    __DSPRegs[16] = (u16)((__DSPRegs[16] & ~0x03ff) | (u16)(mmem_addr >> 16));
    __DSPRegs[16 + 1] = (u16)((__DSPRegs[16 + 1] & ~0xffe0) | (u16)(mmem_addr & 0xffff));
    __DSPRegs[18] = (u16)((__DSPRegs[18] & ~0x03ff) | (u16)(aram_addr >> 16));
    __DSPRegs[18 + 1] = (u16)((__DSPRegs[18 + 1] & ~0xffe0) | (u16)(aram_addr & 0xffff));
    __DSPRegs[20] = (u16)(__DSPRegs[20] | 0x8000);
    __DSPRegs[20] = (u16)((__DSPRegs[20] & ~0x03ff) | (u16)(length >> 16));
    __DSPRegs[20 + 1] = (u16)((__DSPRegs[20 + 1] & ~0xffe0) | (u16)(length & 0xffff));
    __ARWaitForDMA();
    __ARClearInterrupt();
}

void __ARChecksize(void) {
    u8 test_data_pad[0x20 + 31];
    u8 dummy_data_pad[0x20 + 31];
    u8 buffer_pad[0x20 + 31];
    u8 save_pad_1[0x20 + 31];
    u8 save_pad_2[0x20 + 31];
    u8 save_pad_3[0x20 + 31];
    u8 save_pad_4[0x20 + 31];
    u8 save_pad_5[0x20 + 31];
    u32 *test_data;
    u32 *dummy_data;
    u32 *buffer;
    u32 *save1;
    u32 *save2;
    u32 *save3;
    u32 *save4;
    u32 *save5;
    u16 ARAM_mode = 0;
    u32 ARAM_size = 0;
    u32 i;
    while (!(__DSPRegs[11] & 1))
        ;
    ARAM_mode = 3;
    ARAM_size = lbl_801A69E8 = 0x1000000;
    __DSPRegs[9] = (u16)((__DSPRegs[9] & ~(0x00000007 | 0x00000038)) | 0x20 | 2 | 1);
    test_data = (u32 *)((((u32)((u32)(test_data_pad)) + 32 - 1) & ~(32 - 1)));
    dummy_data = (u32 *)((((u32)((u32)(dummy_data_pad)) + 32 - 1) & ~(32 - 1)));
    buffer = (u32 *)((((u32)((u32)(buffer_pad)) + 32 - 1) & ~(32 - 1)));
    save1 = (u32 *)((((u32)((u32)(save_pad_1)) + 32 - 1) & ~(32 - 1)));
    save2 = (u32 *)((((u32)((u32)(save_pad_2)) + 32 - 1) & ~(32 - 1)));
    save3 = (u32 *)((((u32)((u32)(save_pad_3)) + 32 - 1) & ~(32 - 1)));
    save4 = (u32 *)((((u32)((u32)(save_pad_4)) + 32 - 1) & ~(32 - 1)));
    save5 = (u32 *)((((u32)((u32)(save_pad_5)) + 32 - 1) & ~(32 - 1)));
    for (i = 0; i < 8; i++) {
        *(test_data + i) = 0xdeadbeef;
        *(dummy_data + i) = 0xbad0bad0;
    }
    DCFlushRange((void *)test_data, 0x20);
    DCFlushRange((void *)dummy_data, 0x20);
    lbl_801A69EC = 0;
    DCInvalidateRange((void *)save1, 0x20);
    __ARReadDMA((u32)save1, ARAM_size + 0, 0x20);
    fn_80009FF4();
    __ARWriteDMA((u32)test_data, ARAM_size + 0x0000000, 0x20);
    memset((void *)buffer, 0, 0x20);
    DCFlushRange((void *)buffer, 0x20);
    __ARReadDMA((u32)buffer, ARAM_size + 0x0000000, 0x20);
    fn_80009FF4();
    if (buffer[0] == test_data[0]) {
        DCInvalidateRange((void *)save2, 0x20);
        __ARReadDMA((u32)save2, ARAM_size + 0x0200000, 0x20);
        fn_80009FF4();
        DCInvalidateRange((void *)save3, 0x20);
        __ARReadDMA((u32)save3, ARAM_size + 0x1000000, 0x20);
        fn_80009FF4();
        DCInvalidateRange((void *)save4, 0x20);
        __ARReadDMA((u32)save4, ARAM_size + 0x0000200, 0x20);
        fn_80009FF4();
        DCInvalidateRange((void *)save5, 0x20);
        __ARReadDMA((u32)save5, ARAM_size + 0x0400000, 0x20);
        fn_80009FF4();
        __ARWriteDMA((u32)dummy_data, ARAM_size + 0x0200000, 0x20);
        __ARWriteDMA((u32)test_data, ARAM_size + 0x0000000, 0x20);
        memset((void *)buffer, 0, 0x20);
        DCFlushRange((void *)buffer, 0x20);
        __ARReadDMA((u32)buffer, ARAM_size + 0x0200000, 0x20);
        fn_80009FF4();
        if (buffer[0] == test_data[0]) {
            __ARWriteDMA((u32)save1, ARAM_size + 0x0000000, 0x20);
            ARAM_mode |= 0 << 1;
            ARAM_size += 0x0200000;
            lbl_801A69EC = 0x0200000;
        } else {
            __ARWriteDMA((u32)dummy_data, ARAM_size + 0x1000000, 0x20);
            __ARWriteDMA((u32)test_data, ARAM_size + 0x0000000, 0x20);
            memset((void *)buffer, 0, 0x20);
            DCFlushRange((void *)buffer, 0x20);
            __ARReadDMA((u32)buffer, ARAM_size + 0x1000000, 0x20);
            fn_80009FF4();
            if (buffer[0] == test_data[0]) {
                __ARWriteDMA((u32)save1, ARAM_size + 0x0000000, 0x20);
                __ARWriteDMA((u32)save2, ARAM_size + 0x0200000, 0x20);
                ARAM_mode |= 4 << 1;
                ARAM_size += 0x0400000;
                lbl_801A69EC = 0x0400000;
            } else {
                __ARWriteDMA((u32)dummy_data, ARAM_size + 0x0000200, 0x20);
                __ARWriteDMA((u32)test_data, ARAM_size + 0x0000000, 0x20);
                memset((void *)buffer, 0, 0x20);
                DCFlushRange((void *)buffer, 0x20);
                __ARReadDMA((u32)buffer, ARAM_size + 0x0000200, 0x20);
                fn_80009FF4();
                if (buffer[0] == test_data[0]) {
                    __ARWriteDMA((u32)save1, ARAM_size + 0x0000000, 0x20);
                    __ARWriteDMA((u32)save2, ARAM_size + 0x0200000, 0x20);
                    __ARWriteDMA((u32)save3, ARAM_size + 0x1000000, 0x20);
                    ARAM_mode |= 8 << 1;
                    ARAM_size += 0x0800000;
                    lbl_801A69EC = 0x0800000;
                } else {
                    __ARWriteDMA((u32)dummy_data, ARAM_size + 0x0400000, 0x20);
                    __ARWriteDMA((u32)test_data, ARAM_size + 0x0000000, 0x20);
                    memset((void *)buffer, 0, 0x20);
                    DCFlushRange((void *)buffer, 0x20);
                    __ARReadDMA((u32)buffer, ARAM_size + 0x0400000, 0x20);
                    fn_80009FF4();
                    if (buffer[0] == test_data[0]) {
                        __ARWriteDMA((u32)save1, ARAM_size + 0x0000000, 0x20);
                        __ARWriteDMA((u32)save2, ARAM_size + 0x0200000, 0x20);
                        __ARWriteDMA((u32)save3, ARAM_size + 0x1000000, 0x20);
                        __ARWriteDMA((u32)save4, ARAM_size + 0x0000200, 0x20);
                        ARAM_mode |= 12 << 1;
                        ARAM_size += 0x1000000;
                        lbl_801A69EC = 0x1000000;
                    } else {
                        __ARWriteDMA((u32)save1, ARAM_size + 0x0000000, 0x20);
                        __ARWriteDMA((u32)save2, ARAM_size + 0x0200000, 0x20);
                        __ARWriteDMA((u32)save3, ARAM_size + 0x1000000, 0x20);
                        __ARWriteDMA((u32)save4, ARAM_size + 0x0000200, 0x20);
                        __ARWriteDMA((u32)save5, ARAM_size + 0x0400000, 0x20);
                        ARAM_mode |= 16 << 1;
                        ARAM_size += 0x2000000;
                        lbl_801A69EC = 0x2000000;
                    }
                }
            }
        }
        __DSPRegs[9] = (u16)((__DSPRegs[9] & ~(0x07 | 0x38)) | ARAM_mode);
    }
    *(u32 *)((void *)((u32)(0x00D0) + (0xC000 << 16))) = ARAM_size;
    lbl_801A69E4 = ARAM_size;
}
