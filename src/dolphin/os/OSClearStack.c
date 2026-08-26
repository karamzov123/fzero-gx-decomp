typedef unsigned int u32;
typedef unsigned char u8;
typedef struct OSThread_ { u8 pad[0x308]; u32 stackEnd; } OSThread;

extern u32 OSGetStackPointer(void);

#pragma push
#pragma force_active on

u32 fn_80011358(char *thread)
{
    return *(u32 *)(thread + 0x2d4);
}

// provenance: mkdd:libs/dolphin/os/OSThread.c:580 (adapted)
void OSClearStack(register u32 clearValue) {
    register u32 pattern;
    register u32* p;
    u32 sp;

    pattern = ((u32)(u8)clearValue << 24) | ((u32)(u8)clearValue << 16) |
              ((u32)(u8)clearValue << 8) | (u32)(u8)clearValue;
    sp = OSGetStackPointer();
    p = (u32*)(*(OSThread**)0x800000E4)->stackEnd + 1;
    for (; p < (u32*)sp; ++p) {
        *p = pattern;
    }
}

#pragma pop
