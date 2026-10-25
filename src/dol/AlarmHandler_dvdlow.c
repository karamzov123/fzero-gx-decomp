#include <types.h>
#include <dolphin/os/OSAlarm.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/types.h>

typedef void (*DVDLowCallback)(u32 intType);

typedef struct DVDCommand {
    s32 cmd;
    void *addr;
    u32 length;
    u32 offset;
    DVDLowCallback callback;
} DVDCommand;

BOOL DVDLowSeek(u32 offset, DVDLowCallback callback);

extern vu32 NextCommandNumber_801A689C;

void Read(void *addr, u32 length, u32 offset, DVDLowCallback callback);

static DVDCommand CommandList_8015CD70[3];

#pragma section code_type ".fzgxpool"
static void layout____bss_0(void) {
// Hardware or OS state can change asynchronously.
    volatile unsigned char sink; // fzgx-allow: S2 SDK asynchronous state
    sink = *(unsigned char *)&CommandList_8015CD70;
}
#pragma section code_type ".text"

static inline BOOL ProcessNextCommand() {
    s32 n = NextCommandNumber_801A689C;
    ((void)0);
    if (CommandList_8015CD70[n].cmd == 1) {
        ++NextCommandNumber_801A689C;
        Read(CommandList_8015CD70[n].addr, CommandList_8015CD70[n].length,
                    CommandList_8015CD70[n].offset, CommandList_8015CD70[n].callback);
        return 1;
    } else if (CommandList_8015CD70[n].cmd == 2) {
        ++NextCommandNumber_801A689C;
        DVDLowSeek(CommandList_8015CD70[n].offset, CommandList_8015CD70[n].callback);
        return 1;
    }
    return 0;
}

void AlarmHandler_dvdlow(OSAlarm *alarm, OSContext *context) {
    BOOL error = ProcessNextCommand();
    ((void)0);
}
