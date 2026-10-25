#include "types.h"

struct fn_800164A4_CommandList_8015CD70 {
    u32 unk_0;
    u8 pad_4[0x8];
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
};

extern struct fn_800164A4_CommandList_8015CD70 CommandList[];
extern u32 NextCommandNumber_801A689C;
extern u32 WorkAroundSeekLocation_801A6880;
extern u32 DVDLowSeek(u32, u32, u32, u32);

void SeekTwiceBeforeRead(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, u32 arg7) {
    struct fn_800164A4_CommandList_8015CD70 *cmd;
    u32 v0;

    cmd = CommandList;
    v0 = arg2 & ~0x7FFF;
    if (v0 == 0) {
        v0 = 0;
    } else {
        v0 = v0 + WorkAroundSeekLocation_801A6880;
    }
    cmd->unk_0 = 2;
    cmd->unk_C = v0;
    cmd->unk_10 = arg3;
    cmd->unk_14 = 1;
    cmd->unk_18 = arg0;
    cmd->unk_1C = arg1;
    cmd->unk_20 = arg2;
    cmd->unk_24 = arg3;
    cmd->unk_28 = -1;
    NextCommandNumber_801A689C = 0;
    DVDLowSeek(v0, arg3, arg2, arg3);
}
