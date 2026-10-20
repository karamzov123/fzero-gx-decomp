#include "types.h"

extern struct SIIsChanBusy_Packet_8015CA10 Packet;
extern u32 Si[];

struct SIIsChanBusy_Packet_8015CA10_0_E32 {
    u32 unk_0;
    u8 pad_4[0x1C];
};
struct SIIsChanBusy_Packet_8015CA10 {
    struct SIIsChanBusy_Packet_8015CA10_0_E32 unk_0[1];
};

s32 SIIsChanBusy(u32 arg0) {
    s32 v0;
    v0 = 1;
    if ((s32)Packet.unk_0[arg0].unk_0 == -1) {
    if ((s32)Si[0] != (s32)arg0) {
    v0 = 0;
    }
    }
    return v0;
}
