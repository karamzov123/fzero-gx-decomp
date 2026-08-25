typedef signed int s32;
typedef unsigned int u32;
typedef int BOOL;

extern s32 OSDisableInterrupts(void);
extern s32 OSRestoreInterrupts(s32 level);
extern void OSSleepThread(void*);

/* VI wait-for-retrace helper: sleeps on the retrace queue until the retrace
   count changes. Carved from coarse/text_8001A8B4.c.
   Adapted from Melee Dolphin SDK dolphin/vi/vi.c VIWaitForRetrace. */

#pragma push
#pragma force_active on

extern unsigned char lbl_801A6924[4];
extern unsigned char lbl_801A692C[8];

void VIWaitForRetrace(void)
{
    BOOL enabled;
    u32 count;

    enabled = OSDisableInterrupts();
    count = *(volatile u32 *)lbl_801A6924;
    do {
        OSSleepThread(lbl_801A692C);
    } while (count == *(volatile u32 *)lbl_801A6924);
    OSRestoreInterrupts(enabled);
}

#pragma pop
