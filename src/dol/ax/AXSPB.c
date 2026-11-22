#include "types.h"
#pragma pack(1)
struct Entry { s32 unk_0; s16 unk_4; };
#pragma pack()
extern struct Entry lbl_80164D20[9];
extern s32 lbl_801A6B38, lbl_801A6B3C, lbl_801A6B40, lbl_801A6B44, lbl_801A6B48, lbl_801A6B4C, lbl_801A6B50, lbl_801A6B54, lbl_801A6B58;



/* --- dol/fn_80021FBC.c --- */
extern u32 AIStopDMA(void);
extern u32 OSDisableInterrupts(void);
extern u32 OSRestoreInterrupts(u32);
extern u32 OSSleepThread(u32);
extern u32 fn_80028E48(u32);
extern u32 lbl_80160C80[];
extern u32 lbl_801A6B20;
extern u32 lbl_801A6B30;

void fn_80021FBC(void) {
    u32 v0;
    u32 t0;
    t0 = OSDisableInterrupts();
    lbl_801A6B20 = 0;
    v0 = t0;
    fn_80028E48((u32)&lbl_80160C80);
    OSSleepThread((u32)&lbl_801A6B30);
    AIStopDMA();
    OSRestoreInterrupts(v0);
}

/* --- dol/fn_80022014.c --- */
/* --- dol/fn_80022014.c --- */

void fn_80022014(u32 arg0) {
    lbl_801A6B20 = arg0;
}

/* --- dol/fn_8002201C.c --- */

u32 fn_8002201C(void) {
    return (u32)&lbl_80164D20;
}



extern void DCFlushRange(void *, u32);

static inline void update(struct Entry *e, s32 *src) {
    s32 v;
    v = *src / 160;
    if (v != 0) {
        s16 nv;
        if (v > 20) {
            v = 20;
        }
        if (v < -20) {
            v = -20;
        }
        e->unk_0 = *src;
        nv = (-v);
        *src = *src - v * 160;
        e->unk_4 = nv;
    } else {
        *src = 0;
        e->unk_0 = 0;
        e->unk_4 = 0;
    }
}

void fn_80022028(void) {
    struct { struct Entry *value; } p;
    p.value = lbl_80164D20;
    update(p.value + 0, &lbl_801A6B38);
    update(p.value + 1, &lbl_801A6B3C);
    update(p.value + 2, &lbl_801A6B40);
    update(p.value + 3, &lbl_801A6B44);
    update(p.value + 4, &lbl_801A6B48);
    update(p.value + 5, &lbl_801A6B4C);
    update(p.value + 6, &lbl_801A6B50);
    update(p.value + 7, &lbl_801A6B54);
    update(p.value + 8, &lbl_801A6B58);
    DCFlushRange(p.value, 54);
}



/* --- dol/fn_80022420.c --- */
/* --- dol/fn_80022420.c --- */

void fn_80022420(void) {
    lbl_801A6B58 = 0;
    lbl_801A6B54 = 0;
    lbl_801A6B50 = 0;
    lbl_801A6B4C = 0;
    lbl_801A6B48 = 0;
    lbl_801A6B44 = 0;
    lbl_801A6B40 = 0;
    lbl_801A6B3C = 0;
    lbl_801A6B38 = 0;
}

/* --- dol/fn_8002244C.c --- */
// fn_8002244C: empty in retail (single blr).
void fn_8002244C(void) {
}

/* --- dol/fn_80022450.c --- */
struct fn_80022450_Arg0 {
    u8 pad_0[0x52];
    s16 unk_52;
    s16 unk_54;
    s16 unk_56;
    s16 unk_58;
    s16 unk_5A;
    s16 unk_5C;
    s16 unk_5E;
    s16 unk_60;
    s16 unk_62;
};

void fn_80022450(struct fn_80022450_Arg0 *arg0) {
    lbl_801A6B38 = (lbl_801A6B38 + arg0->unk_52);
    lbl_801A6B44 = (lbl_801A6B44 + arg0->unk_54);
    lbl_801A6B50 = (lbl_801A6B50 + arg0->unk_56);
    lbl_801A6B3C = (lbl_801A6B3C + arg0->unk_58);
    lbl_801A6B48 = (lbl_801A6B48 + arg0->unk_5A);
    lbl_801A6B54 = (lbl_801A6B54 + arg0->unk_5C);
    lbl_801A6B40 = (lbl_801A6B40 + arg0->unk_5E);
    lbl_801A6B4C = (lbl_801A6B4C + arg0->unk_60);
    lbl_801A6B58 = (lbl_801A6B58 + arg0->unk_62);
}
