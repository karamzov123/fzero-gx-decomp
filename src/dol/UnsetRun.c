#include "types.h"

extern u32 RunQueueBits;

struct fn_8001036C_Arg0 {
    u8 pad_0[0x2D0];
    u32 unk_2D0;
    u8 pad_2D4[0x8];
    u32 unk_2DC;
    u32 unk_2E0;
    u32 unk_2E4;
};

void UnsetRun(struct fn_8001036C_Arg0 *arg0) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    v0 = arg0->unk_2E0;
    v1 = arg0->unk_2DC;
    v2 = arg0->unk_2E4;
    if (v0 == 0) {
    *(u32 *)((u8 *)v1 + 4) = v2;
    } else {
    *(u32 *)((u8 *)v0 + 740) = v2;
    }
    if (v2 == 0) {
    *(u32 *)((u8 *)v1 + 0) = v0;
    } else {
    *(u32 *)((u8 *)v2 + 736) = v0;
    }
    if (*(u32 *)((u8 *)v1 + 0) == 0) {
    v3 = arg0->unk_2D0;
    RunQueueBits = (RunQueueBits & ~(1 << (31 - v3)));
    }
    arg0->unk_2DC = 0;
}
