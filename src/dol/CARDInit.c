#include "types.h"
#include "dol/globals.h"

extern u16 OSGetFontEncode(void);
extern void OSRegisterVersion(u32 version);
extern void DSPInit(void);
extern void OSInitAlarm(void);
extern void OSInitThreadQueue(void *queue);
extern void OSCreateAlarm(void *alarm);
extern void __CARDSetDiskID(u32 id);
extern void OSRegisterResetFunction(void *function);

extern u16 lbl_801A6BC0[4];
extern u32 lbl_801A6508[2];
extern u8 lbl_8012AA50[16];

#pragma opt_dead_assignments off
void CARDInit(void) {
    Obj_80177960 *state = &lbl_80177960;
    s32 i;

    state = &lbl_80177960;
    if (*(u32 *)((u8 *)state + 0x10c) == 0 || *(u32 *)((u8 *)state + 0x21c) == 0) {
        lbl_801A6BC0[0] = OSGetFontEncode();
        OSRegisterVersion(lbl_801A6508[0]);
        DSPInit();
        OSInitAlarm();
        i = 0;
        do {
            *(u32 *)((u8 *)state + 4) = -3;
            OSInitThreadQueue((u8 *)state + 0x8c);
            OSCreateAlarm((u8 *)state + 0xe0);
            i++;
            state = (Obj_80177960 *)((u8 *)state + 0x110);
        } while (i < 2);
        __CARDSetDiskID((u32)0x8000 << 16);
        OSRegisterResetFunction((void *)((u8 *)&lbl_8012AA50));
    }
}
#pragma opt_dead_assignments reset

