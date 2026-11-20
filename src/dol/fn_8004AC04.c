#include "types.h"


/* --- dol/fn_8004AC04.c --- */
typedef struct AdxtVoice {
    u8 pad00[0x10];
    s32 unk10;
    u8 pad14[0x18];
    s32 unk2C;
} AdxtVoice;

void fn_8004AC04(AdxtVoice* p, int a)
{
    if (a >= 0) {
        p->unk2C = a;
        return;
    }
    {
        int q;
        q = p->unk10 % 2048 > 0;
        q = (p->unk10 / 2048) + q;
        p->unk2C = q;
    }
}

/* --- dol/fn_8004AC4C.c --- */
struct fn_8004AC4C_Arg0 {
    u8 pad_0[0x34];
    u32 unk_34;
    u32 unk_38;
};

void fn_8004AC4C(struct fn_8004AC4C_Arg0 *arg0, u32 arg1, u32 arg2) {
    arg0->unk_34 = arg1;
    arg0->unk_38 = arg2;
}

/* --- dol/fn_8004AC58.c --- */
/* --- dol/fn_8004AC58.c --- */
typedef struct Stream {
    s8 used;
    s8 status;
    s8 substatus;
    u8 pad0[5];
    void *handle;
    u8 pad1[0x14];
    u32 flags20;
    u8 pad2[0x1C];
    u8 pad3;
    s8 f41;
    s8 f42;
    s8 f43;
    s8 f44;
    s8 f45;
    u8 pad4[0x16];
} Stream;

extern void fn_800547C8(void *);
extern s32 fn_80059B44(void);
extern s32 fn_80059AB4(void);
extern s32 fn_80058A40(s32 *value);
extern u8 lbl_8017D6FC[];
extern Stream lbl_8017D708[40];
extern void fn_8004A5F4(Stream *);

static inline void endStatus(Stream *arg0) {
    fn_80059B44();
    if (arg0->status == 2 && arg0->substatus == 1) {
        arg0->f44 = 1;
        if (arg0->f43 == 1) {
            arg0->f43 = 0;
        }
    } else {
        arg0->status = 1;
    }
    fn_80059AB4();
}

static inline void stopStream(Stream *arg0) {
    if (arg0->handle != NULL && arg0->f42 == 0) {
        fn_800547C8(arg0->handle);
    }
    fn_80059B44();
    arg0->status = 1;
    arg0->substatus = 0;
    arg0->flags20 = 0;
    fn_80059AB4();
    endStatus(arg0);
}

static inline void execServer(void) {
    s32 index;

    if (fn_80058A40((s32 *)lbl_8017D6FC) != 0) {
        for (index = 0; index < 40; index++) {
            if (lbl_8017D708[index].used == 1) {
                fn_8004A5F4(&lbl_8017D708[index]);
            }
        }
        *(s32 *)lbl_8017D6FC = 0;
    }
}

void fn_8004AC58(Stream *arg0) {
    stopStream(arg0);
    do {
        execServer();
    } while (arg0->status != 1 || arg0->flags20 != 0);
}

/* --- dol/fn_8004AD84.c --- */
/* --- dol/fn_8004AD84.c --- */

typedef struct Fn8004AD84 {
    s8 unk00;
    s8 unk01;
    s8 unk02;
    s8 unk03[0x3e];
    s8 unk41;
    s8 unk42;
    s8 unk43;
    s8 unk44;
} Fn8004AD84;

void fn_8004AD84(Fn8004AD84 *self) {
    fn_80059B44();
    if (self->unk01 == 2 && self->unk02 == 1) {
        self->unk44 = 1;
        if (self->unk43 == 1) {
            self->unk43 = 0;
        }
    } else {
        self->unk01 = 1;
    }
    fn_80059AB4();
}

/* --- dol/fn_8004ADF4.c --- */
extern void fn_80046718(void);
extern void fn_80046738(void);

s32 fn_8004ADF4(u32 arg0) {
    fn_80046738();
    *(u32 *)((u8 *)arg0 + 48) = 0;
    *(u8 *)((u8 *)arg0 + 3) = 0;
    if ((s32)*(u32 *)((u8 *)arg0 + 16) == 0) {
    *(u8 *)((u8 *)arg0 + 1) = 3;
    } else {
    *(u8 *)((u8 *)arg0 + 1) = 2;
    }
    *(u8 *)((u8 *)arg0 + 2) = 0;
    *(u32 *)((u8 *)arg0 + 32) = 0;
    *(u32 *)((u8 *)arg0 + 36) = 0;
    *(u8 *)((u8 *)arg0 + 67) = 1;
    *(u32 *)((u8 *)arg0 + 88) = (0x100000 - 1);
    fn_80046718();
    return 1;
}

/* --- dol/fn_8004AE78.c --- */
struct fn_8004AE78_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

s32 fn_8004AE78(struct fn_8004AE78_Arg0 *arg0) {
    u32 v0;
    v0 = (u32)arg0;
    if (arg0->unk_8 != 0) {
    v0 = *(u32 *)((u8 *)v0 + 84);
    return v0;
    }
    v0 = 0;
    return v0;
}

/* --- dol/fn_8004AE94.c --- */
typedef struct AdxtVoice_u4 {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[0x40];
    s32 unk54;
} AdxtVoice_u4;

// Donor seed for fn_8004AE94 (addr 0x8004AE94)
// Extracted from adxt_8004AC04.c (original name: fn_8004AE94)

int fn_8004AE94(AdxtVoice_u4* p, int n)
{
    p->unk54 = n;
    if (p->unk54 * 2048 > p->unk10) {
        p->unk54 = p->unk10 / 2048 + (p->unk10 % 2048 > 0);
    }
    return p->unk54;
}
