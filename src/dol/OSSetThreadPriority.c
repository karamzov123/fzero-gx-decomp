#include "types.h"
#include "dolphin/os/OSThread.h"
struct Sig___OSGetEffectivePriority___OSGetEffectivePriority_Arg0 {
    u8 pad_0[0x2D4];
    u32 unk_2D4;
    u8 pad_2D8[0x1C];
    u32 unk_2F4;
};

typedef void *(*Sig_fn_80010828_OSThreadStartFunction)(void *);

extern u32 RunQueueHint;
extern void * OSDisableInterrupts(void);
extern u32 __OSGetEffectivePriority(struct Sig___OSGetEffectivePriority___OSGetEffectivePriority_Arg0 *);
extern OSThread * SetEffectivePriority(OSThread *, OSPriority);
extern u32 SelectThread(u32);
extern BOOL OSRestoreInterrupts(void *);


s32 OSSetThreadPriority(struct Sig___OSGetEffectivePriority___OSGetEffectivePriority_Arg0 *arg0, s32 arg1) {
    s32 temp_r3;
    struct Sig___OSGetEffectivePriority___OSGetEffectivePriority_Arg0 *var_r31;
    void *temp_r30;

    if ((arg1 < 0) || (arg1 > 0x1F)) {
        return 0;
    }
    temp_r30 = (void *)(OSDisableInterrupts());
    if ((s32) arg0->unk_2D4 != arg1) {
        arg0->unk_2D4 = arg1;
        var_r31 = (struct Sig___OSGetEffectivePriority___OSGetEffectivePriority_Arg0 *)(arg0);
loop_5:
        if ((s32) (*(s32 *)((u8 *)(var_r31) + 716)) <= 0) {
            temp_r3 = __OSGetEffectivePriority((struct Sig___OSGetEffectivePriority___OSGetEffectivePriority_Arg0 *)(var_r31));
            if ((s32) (*(s32 *)((u8 *)(var_r31) + 720)) != temp_r3) {
                var_r31 = (struct Sig___OSGetEffectivePriority___OSGetEffectivePriority_Arg0 *)(SetEffectivePriority((OSThread *)((OSThread *) var_r31), (s32)(temp_r3)));
                if (var_r31 != NULL) {
                    goto loop_5; /* Preserves the retail branch. */
                }
            }
        }
        if ((s32) (*(u32 *)((u8 *)(&RunQueueHint) + 0)) != 0) {
            SelectThread((u32)(0U));
        }
    }
    OSRestoreInterrupts((void *)(temp_r30));
    return 1;
}
