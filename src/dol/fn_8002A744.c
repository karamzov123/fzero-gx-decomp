#include "types.h"
#include <dolphin/card/CARDPriv.h>


/* --- dol/fn_8002A744.c --- */
/* --- dol/fn_8002A744.c --- */
extern u16 lbl_801A6BC0;

u16 fn_8002A744(void) {
    return lbl_801A6BC0;
}

/* --- dol/fn_8002A74C.c --- */
u16 fn_8002A74C(u32 arg0) {
    u32 v0;
    u16 v1;
    v0 = (arg0 & 0xFFFF);
    v1 = lbl_801A6BC0;
    switch ((s32)v0) {
case 0: case 1: {

        lbl_801A6BC0 = arg0;
    
} break;
default: {

} break;
}
    return v1;
}

/* --- dol/__CARDSetDiskID.c --- */
struct CARDBiosBss {
    CARDControl blocks[2];
    DVDDiskID diskNone;
};

extern struct CARDBiosBss lbl_80177960;

void __CARDSetDiskID(const DVDDiskID *id) {
    struct CARDBiosBss *storage = &lbl_80177960;

    (storage->blocks)[0].diskID = id ? id : &(storage->diskNone);
    (storage->blocks)[1].diskID = id ? id : &(storage->diskNone);
}
