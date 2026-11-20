#include "types.h"


/* --- dol/fn_8006FFDC.c --- */
extern u16 lbl_801A6CC4;

s32 fn_8003401C(u16);                           /* extern */

u16 fn_8006FFDC(void) {
    u16 temp_r31;

    temp_r31 = *(u16 *)((u8 *)(&lbl_801A6CC4) + 0);
    fn_8003401C(*(u16 *)((u8 *)(&lbl_801A6CC4) + 0));
    (*(u16 *)((u8 *)(&lbl_801A6CC4) + 0)) += 1;
    return temp_r31;
}

/* --- dol/fn_8007001C.c --- */
extern u32 GXSetAlphaCompare(u32, u32, u32, u32, u32);
extern u32 fn_80072BD0(u32);
extern u32 fn_80074918(u32, u32, u32);

void fn_8007001C(void) {
    fn_80074918(1, 3, 1);
    GXSetAlphaCompare(7, 0, 0, 7, 0);
    fn_80072BD0(1);
}

/* --- dol/fn_80070068.c --- */
struct fn_80070068_lbl_801A6D30_T {
    u8 pad_0[0x14];
    u32 unk_14;
    u32 unk_18;
};

extern struct fn_80070068_lbl_801A6D30_T *lbl_801A6D30;
extern u32 GXSetCPUFifo(u32);
extern u32 fn_80032360(void);

s32 fn_80070068(void) {
    u32 v0;
    u32 v1;
    u32 t0, t1, t2;
    t0 = fn_80032360();
    v0 = lbl_801A6D30->unk_14;
    v1 = t0;
    if (t0 != v0) {
    v1 = v0;
    t1 = GXSetCPUFifo(v1);
    v1 = t1;
    v1 = 1;
    } else {
    v1 = lbl_801A6D30->unk_18;
    t2 = GXSetCPUFifo(v1);
    v1 = t2;
    v1 = 0;
    }
    return v1;
}

/* --- dol/fn_800700B4.c --- */
extern void GXGetGPStatus(u8 *, u8 *, u8 *, u8 *, u8 *);

void fn_800700B4(void) {
    u8 v3;
    u8 v2;
    u8 v1;
    u8 v0;

    do {
        GXGetGPStatus(&v3, &v3, &v2, &v1, &v0);
    } while (v2 != 1);
}
