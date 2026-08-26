typedef int BOOL;
typedef signed char s8;
typedef short s16;
typedef long long s64;
typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
#pragma push
#pragma force_active on

extern  int WriteSram(void* buffer, unsigned long offset, unsigned long size);
extern unsigned char Scb[84];
extern s32 EXILock(s32 chan, s32 dev, void* callback);
extern s32 EXISelect(s32 chan, s32 dev, s32 freq);
extern s32 EXIUnlock(s32 chan);
extern s32 EXIImm(s32 chan, void* buffer, u32 size, u32 type, void* callback);
extern s32 EXISync(s32 chan);
extern s32 EXIDeselect(s32 chan);
extern s32 EXIImmEx(s32 chan, void* buffer, u32 size, s32 periodic);

// provenance: dolsdk2001:src/os/OSRtc.c:117
void WriteSramCallback(void)
{
    int sync;
    int unused;

    sync = WriteSram((void*)(Scb + *(u32*)(Scb + 0x40)),
                     *(u32*)(Scb + 0x40),
                     0x40 - *(u32*)(Scb + 0x40));
    *(s32*)(Scb + 0x4C) = sync;
    if (*(s32*)(Scb + 0x4C) != 0) {
        *(u32*)(Scb + 0x40) = 0x40;
    }
}

// provenance: dolsdk2001:src/os/OSRtc.c:107 (cntlzw form for !x)
int WriteSram(void* buffer, unsigned long offset, unsigned long size)
{
    int err;
    unsigned long cmd;

    if (!EXILock(0, 1, WriteSramCallback)) {
        return 0;
    }
    if (!EXISelect(0, 1, 3)) {
        EXIUnlock(0);
        return 0;
    }
    offset <<= 6;
    cmd = ((offset + 0x100) | 0xA0000000);
    err = 0;
    err |= !(EXIImm(0, &cmd, 4, 1, 0) != 0);
    err |= !(EXISync(0) != 0);
    err |= !(EXIImmEx(0, buffer, size, 1) != 0);
    err |= !(EXIDeselect(0) != 0);
    EXIUnlock(0);
    return !err;
}

#pragma pop
