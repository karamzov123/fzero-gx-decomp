#include "types.h"


/* --- dol/fn_8000691C.c --- */
typedef struct {
    u16 unk00;
    u8 unk02[7];
    s8 unk09;
} Rec8;

typedef struct {
    u16 unk00;
    u8 unk02[8];
    s8 unk0A;
} RecC;

extern u8 lbl_801A66D9;
extern u8 lbl_801A66DA;
extern const f64 lbl_801A6EC8;
extern const f64 lbl_801A6EF8;
extern s32 fn_8000F5F0(void);
extern void PADRead(void *);
extern void fn_8006B470(void *);
extern void fn_8006FDEC(void);
extern u32 fn_8006FFCC(u32);
extern void VIWaitForRetrace(void);
extern void fn_8006FEFC(void);
extern void OSResetSystem(int, u32, int);
extern void VISetBlack(u32);

void fn_8000691C(void) {
    RecC sp30[4];
    Rec8 sp8[4];
    RecC *p;
    u32 j;
    u32 i;
    u32 n;
    f64 d;

    PADRead(sp30);
    fn_8006B470(sp8);

    p = sp30;
    for (j = 0; j < 4; j++) {
        if (sp8[j].unk09 != -1) {
            p[j].unk00 = sp8[j].unk00;
            p[j].unk0A = 0;
        }
    }
    for (j = 0; j < 4; j++) {
        if (p[j].unk0A == -3) {
            p[j].unk00 = 0;
        }
    }

    if (lbl_801A66DA == 1 && fn_8000F5F0() == 0) {
        lbl_801A66D9 = 255;
    }
    if (fn_8000F5F0() != 0) {
        lbl_801A66DA = 1;
    }

    d = lbl_801A66D9;
    if (d > lbl_801A6EF8) {
        VIWaitForRetrace();
        VISetBlack(1);
        fn_8006FFCC(0);
        fn_8006FDEC();
        fn_8006FEFC();
        OSResetSystem(0, 0, 0);
    }

    n = 0;
    for (i = 4; i != 0; i--) {
        if ((p->unk00 & 0x1600) == 0x1600) {
            lbl_801A66D9++;
            break;
        }
        p++;
        n++;
    }
    if (n == 4) {
        lbl_801A66D9 = 0;
    }
}

/* --- dol/fn_80006AEC.c --- */
/* --- dol/fn_80006AEC.c --- */
/* --- dol/fn_80006AEC.c --- */
extern u32 lbl_801A66DC;

void fn_80006AEC(u32 arg0) {
    lbl_801A66DC = arg0;
}

/* --- dol/fn_80006AF4.c --- */
extern u8 lbl_801A66D8;

u8 fn_80006AF4(void) {
    return lbl_801A66D8;
}

/* --- dol/fn_80006AFC.c --- */
extern u32 fn_80006B30(u32);
extern u32 fn_80083DB0(u32, u32);
extern u32 lbl_8015BD40[];
extern u32 lbl_801A63F8;

void fn_80006AFC(void) {
    fn_80083DB0((u32)&lbl_8015BD40, (u32)&lbl_801A63F8);
    fn_80006B30(0);
}
