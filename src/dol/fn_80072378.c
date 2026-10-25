#include "types.h"

extern u32 lbl_8019F008[];
extern u32 lbl_8019F024[];
extern u32 memcpy(u32, u32, u32);
extern void GXSetProjectionv(void *);

void fn_80072378(void) {
    memcpy((u32)&lbl_8019F008, (u32)&lbl_8019F024, 28);
    GXSetProjectionv(&lbl_8019F008);
}
