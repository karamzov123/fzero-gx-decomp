#include "types.h"

extern u32 OSDisableInterrupts(void);
extern u32 lbl_801A697C;
extern u32 SIGetType(u32 channel);
extern u32 lbl_801A64C0;
extern u32 lbl_801A64BC;
extern void SISetCommand(u32 channel, u32 command);
extern void SITransferCommands(void);
extern void OSRestoreInterrupts(u32 state);

void PADControlMotor(u32 channel, u32 command) {
    u32 state;
    u32 saved_command = command;
    u32 saved_channel = channel;
    u64 pad;

    state = OSDisableInterrupts();

    if (lbl_801A697C & ((0x8000u << 16) >> saved_channel)) {
        if ((SIGetType(saved_channel) & (0x2000u << 16)) == 0) {
            if (lbl_801A64C0 < 2 && saved_command == 2) {
                saved_command = 0;
            }
            SISetCommand(saved_channel, lbl_801A64BC | 0x400000 | (saved_command & 3));
            SITransferCommands();
        }
    }

    OSRestoreInterrupts(state);
}
