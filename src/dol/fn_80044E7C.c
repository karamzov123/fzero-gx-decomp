#include "types.h"

struct fn_80044E7C_Arg0 {
    u8 pad_0[0x98];
    s16 unk_98;
};

extern u32 fn_8004251C(u32);
extern u32 fn_800433A4(u32);
extern u32 fn_8004342C(u32);
extern u32 fn_80043FA4(u32);
extern u32 fn_80044EF8(u32);
extern u32 fn_80046020(u32);

void fn_80044E7C(struct fn_80044E7C_Arg0 *arg0) {
    s16 v0;
    v0 = arg0->unk_98;
    if (v0 == 0) {
    fn_80044EF8((u32)arg0);
    } else {
    if (v0 == 10) {
    fn_800433A4((u32)arg0);
    } else {
    if (v0 == 2) {
    fn_80046020((u32)arg0);
    } else {
    if (v0 == 3) {
    fn_8004342C((u32)arg0);
    } else {
    if (v0 == 4) {
    fn_80043FA4((u32)arg0);
    } else {
    if (v0 == 1) {
    fn_8004251C((u32)arg0);
    }
    }
    }
    }
    }
    }
}
