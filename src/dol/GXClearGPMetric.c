#include "types.h"

struct fn_80039AFC___cpReg_T {
    u8 pad_0[0x4];
    u16 unk_4;
};

extern struct fn_80039AFC___cpReg_T *__cpReg;

void GXClearGPMetric(void) {
    __cpReg->unk_4 = 4;
}
