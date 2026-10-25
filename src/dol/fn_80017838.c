#include "types.h"

typedef struct BootInfo {
    u8 pad[0x38];
    u32 field38;
    u32 field3c;
} BootInfo;

extern u32 lbl_801A6904;
extern char lbl_80123FE4[52];
extern char lbl_801A6484[6];
extern BootInfo *bootInfo_801A68C8;
extern u32 BB2[];
extern void OSPanic(char *, int, char *, ...);
extern void DVDLowRead(u32, u32, u32, void *);
extern void cbForStateReadingFST(void);

void fn_80017838(void) {
    lbl_801A6904 = (u32)fn_80017838;
    if (bootInfo_801A68C8->field3c < BB2[2]) {
        OSPanic(lbl_801A6484, 0x287, lbl_80123FE4);
    }
    DVDLowRead(bootInfo_801A68C8->field38, (BB2[2] + 0x1f) & ~0x1f,
                BB2[1], cbForStateReadingFST);
}
