#include "types.h"

extern s32 CurrCommand_801A68DC;
extern u32 lbl_801A6904;
extern void *IDShouldBe_801A68C4;

struct fn_80018028_BB2_8015CE40_T {
    u8 pad_0[0x20];
    u8 data[0x20];
};

extern struct fn_80018028_BB2_8015CE40_T BB2;

struct fn_80018028_executing_801A68C0_T {
    u8 pad_0[0xc];
    u32 state;
    u8 pad_10[0x14];
    void *disk_id;
};

extern struct fn_80018028_executing_801A68C0_T *executing_801A68C0;
extern s32 DVDCompareDiskID(void *, void *);
extern void *memcpy(void *, const void *, u32);
extern void DCInvalidateRange(void *, u32);
extern void fn_8001813C(struct fn_80018028_executing_801A68C0_T *);
extern void cbForStateCheckID1(void);
extern void DVDLowStopMotor(void *);
extern s32 fn_8008023C(const void *, const void *, u32);
extern void fn_80018108(struct fn_80018028_executing_801A68C0_T *);

void stateCheckID(void) {
    struct fn_80018028_BB2_8015CE40_T *bb;

    bb = &BB2;
    switch (CurrCommand_801A68DC) {
    case 3:
        if (DVDCompareDiskID(bb->data, executing_801A68C0->disk_id)) {
            memcpy(IDShouldBe_801A68C4, BB2.data, 0x20);
            executing_801A68C0->state = 1;
            DCInvalidateRange(bb, 0x20);
            lbl_801A6904 = (u32)fn_8001813C;
            fn_8001813C(executing_801A68C0);
        } else {
            DVDLowStopMotor((void *)cbForStateCheckID1);
        }
        break;
    default:
        if (fn_8008023C(BB2.data, IDShouldBe_801A68C4, 0x20)) {
            DVDLowStopMotor((void *)cbForStateCheckID1);
        } else {
            lbl_801A6904 = (u32)fn_80018108;
            fn_80018108(executing_801A68C0);
        }
        break;
    }
}
