#include "types.h"

typedef struct Fn8006B188Flags {
    u8 flag7 : 1;
    u8 flag6 : 1;
    u8 rest : 6;
} Fn8006B188Flags;

typedef struct Fn8006B188Entry {
    u32 unk_0;
    Fn8006B188Flags flags;
    u8 _pad_5[3];
    u32 value;
    u8 _pad_c[8];
    s8 state;
    u8 _pad_15[0x38];
    s8 field_4d;
    u8 _pad_4e[0x11fa];
} Fn8006B188Entry;

extern s32 lbl_801A6C88;
extern u8 lbl_80199670[18720];
extern void fn_8006AA20(u32, u32);
extern void fn_8006B92C(void *);
extern void fn_8006B048(Fn8006B188Entry *, s32);
extern s32 fn_80013428(s32, void *);
extern void fn_800137C4(s32, void *);
extern s32 fn_8006AF94(void);
extern u32 PADSetSamplingCallback(u32);

#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
void fn_8006B188(void) {
    s32 off;
    void *handler;
    u8 *base;
    Fn8006B188Entry *entry;
    s32 i;

    if (lbl_801A6C88 == 0) {
        base = lbl_80199670;
        i = 0;
        off = 0;
        do {
            entry = (Fn8006B188Entry *)((u32)base + i * 0x1248);
            fn_8006B92C((u8 *)entry + 0x50);
            fn_8006B048(entry, i);
            fn_80013428(i, (void *)fn_8006AA20);
            fn_800137C4(i, (u8 *)entry + 0xc);
            i++;
            off += 0x1248;
        } while (i < 4);
        PADSetSamplingCallback((u32)(void *)fn_8006AF94);
        lbl_801A6C88 = 1;
    }
}
#pragma opt_loop_invariants reset

#pragma opt_strength_reduction reset
