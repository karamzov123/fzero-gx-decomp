#include "types.h"

struct fn_8003458C_gx_T {
    u8 pad_0[0x4F4];
    u32 unk_4F4;
};

extern struct fn_8003458C_gx_T *gx;
extern u32 __GXSetVCD(void);
extern u32 __GXCalculateVLim(void);
extern u32 fn_80033650(void);
extern u32 __GXSetGenMode(void);
extern u32 __GXSetSUTexRegs(void);
extern u32 fn_80036F24(void);

void fn_8003458C(void) {
    if ((gx->unk_4F4 & 0x1) != 0) {
    __GXSetSUTexRegs();
    }
    if ((gx->unk_4F4 & 0x2) != 0) {
    fn_80036F24();
    }
    if ((gx->unk_4F4 & 0x4) != 0) {
    __GXSetGenMode();
    }
    if ((gx->unk_4F4 & 0x8) != 0) {
    __GXSetVCD();
    }
    if ((gx->unk_4F4 & 0x10) != 0) {
    fn_80033650();
    }
    if ((gx->unk_4F4 & 0x18) != 0) {
    __GXCalculateVLim();
    }
    gx->unk_4F4 = 0;
}
