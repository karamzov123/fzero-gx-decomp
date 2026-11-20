#include "types.h"
#include "dolphin/card.h"
#include "dolphin/card/CARDPriv.h"
typedef struct {
    u8 pad[0x84];
    u32 value;
} Sig_fn_8002C4BC_Fn8002C4BCObject;

typedef struct Sig___CARDPutControlBlock_CARDControlBlock {
    s32 attached;
    s32 callback;
} Sig___CARDPutControlBlock_CARDControlBlock;

extern s32 __CARDGetControlBlock(s32, CARDControl * *);
extern u32 fn_8002C4BC(Sig_fn_8002C4BC_Fn8002C4BCObject *);
extern s32 __CARDAccess(CARDControl *, CARDDir *);
extern s32 __CARDIsPublic(CARDDir *);
extern u32 memcpy(u32, u32, u32);
extern u32 __CARDPutControlBlock(Sig___CARDPutControlBlock_CARDControlBlock *, u32);


s32 fn_80030380(s32 arg0, s32 arg1, u32 arg2) {
    CARDControl *sp14;
    s32 temp_r3;
    s32 var_r31;
    CARDDir *temp_r30;

    if ((arg1 < 0) || (arg1 >= 0x7F)) {
        return -0x80;
    }
    temp_r3 = __CARDGetControlBlock(arg0, (CARDControl * *)(&sp14));
    if (temp_r3 < 0) {
        return temp_r3;
    }
    temp_r30 = (CARDDir *)fn_8002C4BC((Sig_fn_8002C4BC_Fn8002C4BCObject *)((Sig_fn_8002C4BC_Fn8002C4BCObject *) sp14));
    temp_r30 += arg1;
    var_r31 = __CARDAccess((CARDControl *)(sp14), (CARDDir *)(temp_r30));
    if (var_r31 == -0xA) {
        var_r31 = __CARDIsPublic((CARDDir *)(temp_r30));
    }
    if (var_r31 >= 0) {
        memcpy(arg2, (u32)(temp_r30), (0x40U));
    }
    return __CARDPutControlBlock((Sig___CARDPutControlBlock_CARDControlBlock *)((Sig___CARDPutControlBlock_CARDControlBlock *) sp14), var_r31);
}
