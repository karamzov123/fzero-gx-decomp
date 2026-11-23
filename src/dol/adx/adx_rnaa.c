#include "types.h"

extern u32 fn_8005A668(void);
extern u32 fn_8005A680(void);
extern u32 fn_8005A678(void);
extern u32 fn_8005A688(void);
extern u32 AXRNA_SetOutPan(void);
struct AXRNAHandle;
extern void fn_8005A74C(struct AXRNAHandle *, s32);
extern u32 fn_8005A7F8(void);
extern u32 fn_8005A94C(void);
extern u32 AXRNA_ExecServer(void);
extern u32 fn_8005B010(void);
extern u32 fn_8005B068(void);
extern u32 fn_8005B0C4();
extern u32 fn_8005B264();
extern u32 fn_8005B464(u32);
extern u32 fn_8005B534(void);
extern u32 fn_8005BE48(void);
extern u32 AXRNA_Finish(void);
extern u32 fn_8005BDD4(void);

void fn_8004ED3C(void) {
    fn_8005A668();
}

s32 fn_8004ED5C(void) {
    fn_8005A680();
    return 0;
}

// fn_8004ED80: empty in retail (single blr).
void fn_8004ED80(void) {
}

void fn_8004ED84(void) {
    fn_8005A678();
}

void fn_8004EDA4(void) {
    fn_8005A688();
}

void fn_8004EDC4(void) {
    AXRNA_SetOutPan();
}

void fn_8004EDE4(struct AXRNAHandle *handle, s32 value) {
    fn_8005A74C(handle, value);
}

void fn_8004EE04(void) {
    fn_8005A7F8();
}

void fn_8004EE24(void) {
    fn_8005A94C();
}

void fn_8004EE44(void) {
    AXRNA_ExecServer();
}

void fn_8004EE64(void) {
    fn_8005B010();
}

void fn_8004EE84(void) {
    fn_8005B068();
}

void fn_8004EEA4(void) {
    fn_8005B0C4();
}

void fn_8004EEC4(void) {
    fn_8005B264();
}

void fn_8004EEE4(u32 arg0) {
    fn_8005B0C4(arg0, 0);
    fn_8005B264(arg0, 0);
    fn_8005B464(arg0);
}

void fn_8004EF28(void) {
    fn_8005B534();
}

void fn_8004EF48(void) {
    fn_8005BE48();
}

void fn_8004EF68(void) {
    AXRNA_Finish();
}

void fn_8004EF88(void) {
    fn_8005BDD4();
}
