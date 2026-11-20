#include "types.h"


/* --- dol/InitializeProgramEndTrap.c --- */
extern void ICInvalidateRange(void *, u32);
extern void fn_800035C0(void *, void *, u32);
extern void DCFlushRange(void *, u32);
extern void PPCHalt(void);
extern u8 EndofProgramInstruction[];

void InitializeProgramEndTrap(void) {
    u8 *trap = (u8 *)PPCHalt;

    fn_800035C0(trap + 4, EndofProgramInstruction, 4);
    ICInvalidateRange(trap + 4, 4);
    DCFlushRange(trap + 4, 4);
}

/* --- dol/TRK_board_display.c --- */
extern u32 OSReport(u32, ...);
extern u32 lbl_80095BCC[];

void TRK_board_display(u32 arg0) {
    OSReport((u32)&lbl_80095BCC, arg0);
}

/* --- dol/UnreserveEXI2Port.c --- */
typedef u32 (*UnreserveEXI2Port_Fn0)(void);
struct UnreserveEXI2Port_gDBCommTable {
    u8 pad_0[0x20];
    u32 unk_20;
};

extern struct UnreserveEXI2Port_gDBCommTable gDBCommTable[];

void UnreserveEXI2Port(void) {
    ((UnreserveEXI2Port_Fn0)gDBCommTable[0].unk_20)();
}
