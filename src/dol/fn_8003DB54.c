#include "types.h"


/* --- dol/fn_8003DB54.c --- */
typedef struct Color {
    u8 r, g, b, a;
} Color;

typedef struct Entry {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    Color unkC;
} Entry;

extern const Color lbl_801A71B8;
extern Entry *lbl_801A6C48;

void fn_8003DB54(u8 arg0, u32 arg1, u32 arg2) {
    Color c = lbl_801A71B8;

    lbl_801A6C48[arg0].unk0 = arg1;
    lbl_801A6C48[arg0].unk4 = arg2;
    lbl_801A6C48[arg0].unk8 = -1;
    lbl_801A6C48[arg0].unkC = c;
}

/* --- dol/fn_8003DBA0.c --- */
typedef struct Entry_u1 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
} Entry_u1;

extern u32 OSDisableInterrupts(void);
extern volatile u32 lbl_801A6C40;  /* shared with the handler; store order is observable */
extern void fn_8003D698(void);
extern volatile u32 lbl_801A6588[2];  /* MMIO-visible slot; store order vs 6C40 matters */
extern void fn_80034378(void (*func)(void));
extern u32 lbl_801A6C44;
extern Entry_u1 *lbl_801A6C4C;
extern void fn_8003D4E0(void);
extern void GXClearGPMetric(void);
extern void PPCMtpmc1(u32 value);
extern void PPCMtpmc2(u32 value);
extern void PPCMtpmc3(u32 value);
extern void PPCMtpmc4(u32 value);
extern void PPCMtmmcr0(u32 value);
extern void PPCMtmmcr1(u32 value);
extern void fn_8003E13C(void);
extern void OSRestoreInterrupts(u32 level);

void fn_8003DBA0(void) {
    u32 level;

    level = OSDisableInterrupts();
    lbl_801A6C40 = 0;
    lbl_801A6588[0] = 0xffff;
    fn_80034378(fn_8003D698);
    lbl_801A6C4C[lbl_801A6C44].unk4 = 0;
    fn_8003D4E0();
    GXClearGPMetric();
    PPCMtpmc1(0);
    PPCMtpmc2(0);
    PPCMtpmc3(0);
    PPCMtpmc4(0);
    PPCMtmmcr0(0x8b);
    PPCMtmmcr1(0x78400000);
    fn_8003E13C();
    OSRestoreInterrupts(level);
}
