#pragma push
#pragma force_active on

typedef signed int s32;
typedef unsigned int u32;

#define NULL ((void*) 0)

typedef void (*AXCallback)(void*);
typedef struct AXVPB_ {
    unsigned char pad[0xC];
    unsigned int flags;
    AXCallback callback;
} AXVPB;


extern void OSRegisterVersion(const char* version);
extern void __AXInitVoiceStacks(void);
extern void __AXAllocQuit(void);
extern void __AXPushFreeStack(register void* p);
extern void* __AXPopCallbackStack(void);
extern void __AXRemoveFromStack(register void* p);
extern void fn_80022EA4(void);
extern void fn_80022420(void);
extern void AXInitAux(void);
extern void AXInitCommandList(void);
extern void fn_80021910(void);
extern void fn_80021C7C(void);
extern void fn_800230A0(void);
extern void fn_8002244C(void);
extern void AXClearAuxBufferPtrs(void);
extern void fn_80021FBC(void);
extern void* __AXStackHead[32];
extern void* __AXStackTail[32];

extern char* lbl_801A64E8;
extern unsigned char lbl_801A6A28[8];
extern unsigned char lbl_801A6A30[8];
extern unsigned char lbl_801A6A38[8];
extern unsigned char lbl_801A6A40[8];
extern unsigned char lbl_801A6A48[8];
extern unsigned char lbl_801A6A50[8];
extern unsigned char lbl_801A6A58[8];
extern unsigned char lbl_801A6A60[8];
extern unsigned char lbl_801A6A68[8];
extern unsigned char lbl_801A6A70[8];
extern unsigned char lbl_801A6A78[8];
extern unsigned char lbl_801A6A80[8];
extern unsigned char lbl_801A6A88[8];
extern unsigned char lbl_801A6A90[8];
extern unsigned char lbl_801A6A98[8];
extern unsigned char lbl_801A6AA0[8];
extern unsigned char lbl_801A6AA8[8];
extern unsigned char lbl_801A6AB0[8];
extern void* lbl_801A6AB8;
// provenance: original
// provenance: original


void fn_80020724(void) {
    lbl_801A6AB0[0] = 0;
    lbl_801A6AB0[0] = 0;
    lbl_801A6AA8[0] = 0;
    lbl_801A6AA0[0] = 0;
    lbl_801A6A98[0] = 0;
    lbl_801A6A90[0] = 0;
    lbl_801A6A88[0] = 0;
    lbl_801A6A80[0] = 0;
    lbl_801A6A78[0] = 0;
    lbl_801A6A70[0] = 0;
    lbl_801A6A68[0] = 0;
    lbl_801A6A60[0] = 0;
    lbl_801A6A58[0] = 0;
    lbl_801A6A50[0] = 0;
    lbl_801A6A48[0] = 0;
    lbl_801A6A40[0] = 0;
    lbl_801A6A38[0] = 0;
    lbl_801A6A30[0] = 0;
    lbl_801A6A28[0] = 0;
}


void AXInit(void)
{
    OSRegisterVersion(lbl_801A64E8);
    __AXInitVoiceStacks();
    fn_80022EA4();
    fn_80022420();
    AXInitAux();
    AXInitCommandList();
    fn_80021C7C();
}

// provenance: original
void AXQuit(void) {
    __AXAllocQuit();
    fn_800230A0();
    fn_8002244C();
    AXClearAuxBufferPtrs();
    fn_80021910();
    fn_80021FBC();
}

// provenance: dolsdk2001:src/ax/AXAlloc.c:11
void* __AXGetStackHead(s32 priority)
{
    return *(void**)((char*)__AXStackHead + priority * 4);
}

// provenance: dolsdk2001:src/ax/AXAlloc.c:16 (adapted)
void __AXServiceCallbackStack(void)
{
    AXVPB* p;
    for (p = __AXPopCallbackStack(); p; p = __AXPopCallbackStack()) {
        if (p->flags != 0) {
            if (p->callback != NULL) {
                p->callback(p);
            }
            __AXRemoveFromStack(p);
            __AXPushFreeStack(p);
        }
    }
}

// provenance: dolsdk2001:src/ax/AXAlloc.c:31 (chained-assign shape)
void __AXInitVoiceStacks(void) {
    u32 i;

    lbl_801A6AB8 = 0;
    for (i = 0; i < 32; i++) {
        __AXStackHead[i] = __AXStackTail[i] = 0;
    }
}

// provenance: dolsdk2001:src/ax/AXAlloc.c:47
void __AXAllocQuit(void) {
    __AXInitVoiceStacks();
}

#pragma pop
