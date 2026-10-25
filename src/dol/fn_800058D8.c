#include "types.h"

extern u32 PADInit(void);
extern u32 PADSetAnalogMode(u32);
extern u32 fn_8006B188(void);
extern u8 lbl_801A66AC;

u8 fn_800058D8(void) {
    u32 v0;
    u32 t0, t1, t2;
    if (lbl_801A66AC == 0) {
    t0 = PADInit();
    v0 = t0;
    v0 = 3;
    t1 = PADSetAnalogMode(v0);
    v0 = t1;
    t2 = fn_8006B188();
    v0 = t2;
    v0 = lbl_801A66AC;
    lbl_801A66AC = (v0 + 1);
    }
    return v0;
}
