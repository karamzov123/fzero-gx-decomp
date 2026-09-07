#ifndef FZERO_DOLPHIN_OS_CONTEXT_H
#define FZERO_DOLPHIN_OS_CONTEXT_H

/*
 * OSContext. Same layout src/dolphin/os/OSContext.c already proves against
 * retail; kept as a header because an interrupt handler needs the COMPLETE
 * type to declare its exception context as a local (the frame size is the
 * check). OSContext.c still carries its own copy: it declares its own u32/s32
 * typedefs, so including this there would collide, and that unit is exact.
 */
typedef struct OSContext {
    /* 0x000 */ u32 gpr[32];
    /* 0x080 */ u32 cr;
    /* 0x084 */ u32 lr;
    /* 0x088 */ u32 ctr;
    /* 0x08C */ u32 xer;
    /* 0x090 */ double fpr[32];
    /* 0x190 */ u32 fpscr_pad[2];
    /* 0x198 */ u32 srr0;
    /* 0x19C */ u32 srr1;
    /* 0x1A0 */ u16 mode;
    /* 0x1A2 */ u16 state;
    /* 0x1A4 */ u32 gqr[8];
    /* 0x1C4 */ double psf[32];
} OSContext;

typedef char OS_context_is_0x2C8_bytes[(sizeof(OSContext) == 0x2C8) ? 1 : -1];

#endif
