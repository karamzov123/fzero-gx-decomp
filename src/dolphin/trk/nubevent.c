// MetroTRK nub event-queue functions (0x80088648-0x80088910).
// Semantic reference: melee src/MetroTRK (bytes differ).

#pragma push
#pragma force_active on

extern int TRKGetNextEvent(void*);
extern void TRK_memcpy(void*, const void*, unsigned long);
extern void TRKDestructEvent(void*);
extern void* TRKGetBuffer(int);
extern void TRKDispatchMessage(void*);
extern void TRKTargetInterrupt(void*);
extern void TRKTargetSupportRequest(void);
extern void TRKGetInput(void);
extern int TRKTargetStopped(void);
extern void TRKTargetContinue(void);
extern void TRKReleaseBuffer(void*);
extern void TRKReleaseMutex_stub(unsigned long);
extern void TRKAcquireMutex_stub(unsigned long);
extern unsigned char gTRKInputPendingPtr[9];
extern unsigned char lbl_801A36B8[40];

typedef struct {
    int eventType;
    int eventID;
    int msgBufID;
} TRKEvent;

// TRKNubMainLoop: exact natural-C (100.0%, GC/1.3).
// Retail dispatch (from asm 1.2.5): eventType 0 = Null (break), 1 = Shutdown,
// 2 = GetBuffer+DispatchMessage, 3/4 = TargetInterrupt, 5 =
// TargetSupportRequest. Block order (case 2 before case 1) matches retail
// basic-block placement; case 0 is kept so MWCC emits the retail comparison
// skeleton (cmpwi 0x0; beq end before the >=1 test).
// provenance: sms:src/TRK_MINNOW_DOLPHIN/debugger/embedded/MetroTRK/Portable/mainloop.c:22
void TRKNubMainLoop(void)
{
    TRKEvent event;
    int isShutdownRequested = 0;
    int isNewInput = 0;
    while (isShutdownRequested == 0) {
        if (TRKGetNextEvent(&event) != 0) {
            isNewInput = 0;
            switch (event.eventType) {
            case 0:
                break;
            case 2:
                TRKDispatchMessage(TRKGetBuffer(event.msgBufID));
                break;
            case 1:
                isShutdownRequested = 1;
                break;
            case 3:
            case 4:
                TRKTargetInterrupt(&event);
                break;
            case 5:
                TRKTargetSupportRequest();
                break;
            }
            TRKDestructEvent(&event);
        } else {
            if (isNewInput == 0 ||
                **(unsigned char**)(void*)gTRKInputPendingPtr != 0) {
                isNewInput = 1;
                TRKGetInput();
            } else {
                if (TRKTargetStopped() == 0) {
                    TRKTargetContinue();
                }
                isNewInput = 0;
            }
        }
    }
}

// provenance: original
void TRKDestructEvent(void* msg) {
    TRKReleaseBuffer(*(void**)((char*)msg + 8));
}

// provenance: original
void TRKConstructEvent(void* ev, int type) {
    *(int*)ev = type;
    *(int*)((char*)ev + 4) = 0;
    *(int*)((char*)ev + 8) = -1;
}

asm int TRKPostEvent(void* msg)
{
    nofralloc
    stwu    r1, -0x20(r1)
    mflr    r0
    lis     r4, lbl_801A36B8@ha
    stw     r0, 0x24(r1)
    stw     r31, 0x1c(r1)
    li      r31, 0
    stw     r30, 0x18(r1)
    stw     r29, 0x14(r1)
    mr      r29, r3
    addi    r3, r4, lbl_801A36B8@l
    bl      TRKReleaseMutex_stub
    lis     r3, lbl_801A36B8@ha
    addi    r30, r3, lbl_801A36B8@l
    lwz     r3, 4(r30)
    cmpwi   r3, 2
    bne     lbl_800887C4
    li      r31, 0x100
    b       lbl_80088830
lbl_800887C4:
    lwz     r0, 8(r30)
    mr      r4, r29
    li      r5, 0xC
    add     r0, r0, r3
    srwi    r3, r0, 0x1F
    clrlwi  r0, r0, 0x1F
    xor     r0, r0, r3
    subf    r0, r3, r0
    mulli   r29, r0, 0xC
    add     r3, r30, r29
    addi    r3, r3, 0xC
    bl      TRK_memcpy
    lis     r3, lbl_801A36B8@ha
    addi    r4, r3, lbl_801A36B8@l
    lwz     r0, 0x24(r4)
    add     r3, r4, r29
    stw     r0, 0x10(r3)
    lwz     r3, 0x24(r4)
    addi    r0, r3, 1
    cmplwi  r0, 0x100
    stw     r0, 0x24(r4)
    bge     lbl_80088824
    li      r0, 0x100
    stw     r0, 0x24(r4)
lbl_80088824:
    lwz     r3, 4(r30)
    addi    r0, r3, 1
    stw     r0, 4(r30)
lbl_80088830:
    lis     r3, lbl_801A36B8@ha
    addi    r3, r3, lbl_801A36B8@l
    bl      TRKAcquireMutex_stub
    lwz     r0, 0x24(r1)
    mr      r3, r31
    lwz     r31, 0x1c(r1)
    lwz     r30, 0x18(r1)
    lwz     r29, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x20
    blr
}

asm int TRKGetNextEvent(void* msg)
{
    nofralloc
    stwu    r1, -0x20(r1)
    mflr    r0
    lis     r4, lbl_801A36B8@ha
    stw     r0, 0x24(r1)
    stw     r31, 0x1c(r1)
    stw     r30, 0x18(r1)
    li      r30, 0
    stw     r29, 0x14(r1)
    mr      r29, r3
    addi    r3, r4, lbl_801A36B8@l
    bl      TRKReleaseMutex_stub
    lis     r3, lbl_801A36B8@ha
    addi    r31, r3, lbl_801A36B8@l
    lwz     r0, 4(r31)
    cmpwi   r0, 0
    ble     lbl_800888E4
    lwz     r0, 8(r31)
    mr      r3, r29
    li      r5, 0xC
    mulli   r0, r0, 0xC
    add     r4, r31, r0
    addi    r4, r4, 0xC
    bl      TRK_memcpy
    lwz     r3, 8(r31)
    lwz     r4, 4(r31)
    addi    r0, r3, 1
    addi    r3, r4, -1
    stw     r0, 8(r31)
    cmpwi   r0, 2
    stw     r3, 4(r31)
    bne     lbl_800888E0
    li      r0, 0
    stw     r0, 8(r31)
lbl_800888E0:
    li      r30, 1
lbl_800888E4:
    lis     r3, lbl_801A36B8@ha
    addi    r3, r3, lbl_801A36B8@l
    bl      TRKAcquireMutex_stub
    lwz     r0, 0x24(r1)
    mr      r3, r30
    lwz     r31, 0x1c(r1)
    lwz     r30, 0x18(r1)
    lwz     r29, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x20
    blr
}

#pragma pop
