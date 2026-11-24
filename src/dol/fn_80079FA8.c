#include "types.h"


/* --- dol/fn_80079FA8.c --- */
extern u32 lbl_801A6410;
extern char lbl_80094E48[54];
extern void OSReport(const char *, ...);
extern char lbl_80094E80[57];
extern u32 OSGetArenaLo(void);
extern u32 OSGetArenaHi(void);
extern u32 fn_80008EC8(u32, u32, u32);
extern u32 OSSetArenaLo(u32);
extern u32 fn_80008F60(u32, u32);
extern u32 fn_80008E84(void);
extern u32 fn_80008E34(u32, u32);

void fn_80079FA8(u32 arg0) {
    s32 status;
    u32 v0;
    struct { u32 value; } v1;
    u32 v2;

    status = lbl_801A6410;
    if (status == -1) {
        OSReport(lbl_80094E48);
        OSReport(lbl_80094E80);
        v0 = OSGetArenaLo();
        v1.value = OSGetArenaHi();
        v0 = fn_80008EC8(v0, v1.value, 1);
        OSSetArenaLo(v0);
        v2 = v1.value & ~0x1F;
        v0 = (v0 + 0x1F) & ~0x1F;
        fn_80008F60(v0, v2);
        fn_80008E84();
        OSSetArenaLo(v2);
    }
    fn_80008E34(lbl_801A6410, arg0);
}
