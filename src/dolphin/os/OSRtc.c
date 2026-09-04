#pragma push
#pragma force_active on
#pragma push
#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef int BOOL;
#define NULL ((void*) 0)

extern void OSRestoreInterrupts(register s32 enabled);
extern void DCInvalidateRange(register void* addr, register unsigned long n);
extern s32 EXILock(register s32 chn, register u32 dev, register void* callback);
extern s32 EXISelect(register s32 chn, register u32 dev, register u32 freq);
extern s32 EXIUnlock(register s32 chn);
extern s32 EXIImm(register s32 chn, register void* buf, register s32 len, register u32 type, register void* callback);
extern s32 EXISync(register s32 chn);
extern s32 EXIDma(register s32 chn, register void* buf, register s32 len, register u32 type, register void* callback);
extern s32 __OSUnlockSramCore(register u32 doWrite, register u32 offset);

typedef struct SramControlBlock {
    u8 sram[0x40];
    u32 offset;
    s32 enabled;
    BOOL locked;
    s32 sync;
    void (*callback)(void);
} SramControlBlock;

extern SramControlBlock Scb;

/* harvest: declarations carried over from the recovered
   candidate - the converted body below needs them. */
extern s32 OSDisableInterrupts(void);
extern s32 EXIDeselect(register s32 chn);

#pragma pop

static inline void* LockSram(u32 offset)
{
    SramControlBlock* scb = &Scb;
    s32 enabled = OSDisableInterrupts();
    BOOL* locked = &scb->locked;
    if (*locked) {
        OSRestoreInterrupts(enabled);
        return NULL;
    }
    scb->enabled = enabled;
    *locked = 1;
    return &scb->sram[offset];
}

// provenance: harvest:runs.sqlite - __OSReadROM recovered from cand1.c, compiled by natc1 at 2026-08-26T05:17 and scored 100 against main/dolphin/os/OSRtc; original reference not recorded
// provenance: dolsdk2001:src/os/OSRtc.c:227
int __OSReadROM(register void* buffer, register long length, register long offset)
{
    int err;
    unsigned long cmd;

    DCInvalidateRange(buffer, length);
    if (!EXILock(0, 1, 0)) {
        return 0;
    }
    if (!EXISelect(0, 1, 3)) {
        EXIUnlock(0);
        return 0;
    }
    cmd = offset << 6;
    err = 0;
    err |= !EXIImm(0, &cmd, 4, 1, 0);
    err |= !EXISync(0);
    err |= !EXIDma(0, buffer, length, 0, 0);
    err |= !EXISync(0);
    err |= !EXIDeselect(0);
    EXIUnlock(0);
    return !err;
}

// provenance: dolsdk2001:src/os/OSRtc.c:318
u32 OSGetSoundMode(void)
{
    u8* sram = (u8*)LockSram(0);
    u32 mode;
    u8 _pad[8];

    if (sram[0x13] & 4) {
        mode = 1;
    } else {
        mode = 0;
    }
    __OSUnlockSramCore(0, 0);
    return mode;
}

// provenance: dolsdk2001:src/os/OSRtc.c:347
u32 OSGetProgressiveMode(void)
{
    u8* sram = (u8*)LockSram(0);
    u32 mode = (sram[0x13] >> 7) & 1;
    __OSUnlockSramCore(0, 0);
    return mode;
}

// provenance: dolsdk2001:src/os/OSRtc.c:357
void OSSetProgressiveMode(u32 mode)
{
    u32 target = (mode << 7) & 0x80;
    u8* sram = (u8*)LockSram(0);
    u8 sram13 = sram[0x13];
    u8 _pad[4];

    if (target == (sram13 & 0x80)) {
        __OSUnlockSramCore(0, 0);
    } else {
        sram[0x13] &= 0xFFFFFF7F;
        sram[0x13] |= target;
        __OSUnlockSramCore(1, 0);
    }
}

// provenance: dolsdk2001:src/os/OSRtc.c:376
u16 OSGetWirelessID(s32 channel)
{
    u16* sram = (u16*)LockSram(0x14);
    u16 id = sram[channel + 0xE];
    u8 _pad[4];
    __OSUnlockSramCore(0, 0x14);
    return id;
}

#pragma push
#pragma force_active on

asm void OSSetWirelessID(register s32 channel, register u16 id)
{
    nofralloc
    mflr	r0
    lis     r5, Scb@ha
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    addi	r31, r5, Scb@l
    stw	r30, 0x20(r1)
    addi	r30, r4, 0
    stw	r29, 0x1c(r1)
    addi	r29, r3, 0
    bl      OSDisableInterrupts
    lwz	r0, 0x48(r31)
    addi	r4, r31, 0x48
    cmpwi	r0, 0
    beq     _80010058
    bl      OSRestoreInterrupts
    li	r3, 0
    b       _80010068
_80010058:
    stw	r3, 0x44(r31)
    li	r0, 1
    addi	r3, r31, 0x14
    stw	r0, 0(r4)
_80010068:
    slwi	r0, r29, 1
    add	r4, r3, r0
    lhzu	r3, 0x1c(r4)
    clrlwi	r0, r30, 0x10
    cmplw	r3, r0
    beq     _80010094
    sth	r30, 0(r4)
    li	r3, 1
    li	r4, 0x14
    bl      __OSUnlockSramCore
    b       _800100a0
_80010094:
    li	r3, 0
    li	r4, 0x14
    bl      __OSUnlockSramCore
_800100a0:
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    lwz	r29, 0x1c(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

#pragma pop

#pragma pop
