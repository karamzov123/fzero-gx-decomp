#include "types.h"

extern struct fn_8001813C_IDShouldBe_801A68C4_T *IDShouldBe_801A68C4;
extern u32 DVDLowAudioBufferConfig(u32, u32, u32);
extern void cbForStateCheckID2a(void);

struct fn_8001813C_IDShouldBe_801A68C4_T {
    u8 pad_0[0x8];
    u8 unk_8;
};

void fn_8001813C(void) {
    DVDLowAudioBufferConfig(IDShouldBe_801A68C4->unk_8, 10, (u32)cbForStateCheckID2a);
}
