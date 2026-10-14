/* Non-matching: best partial attempt (31.03% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/game.h"


extern u32 fn_1_3F2A0(void);
extern void fn_1_4A00(s32, u8, void *);
extern void fn_1_469BC(void);
extern void fn_1_8DBA4(u8);

typedef struct {
    u8 pad_0[4];
    u8 unk_4;
    u8 pad_5;
    u8 unk_6;
    u8 pad_7;
} fn_1_304A8_Slot;

typedef struct {
    fn_1_304A8_Slot slots[50];
    u8 unk_190;
    u8 unk_191;
    u8 unk_192;
    u8 pad_193;
    u8 unk_194[4];
} fn_1_304A8_SlotTable;

typedef struct {
    u8 pad_0[0x2A];
    s16 unk_2A;
    u8 pad_2C[4];
    u32 unk_30;
    u8 pad_34[0x14B0 - 0x34];
    u32 unk_14B0[0x14];
    void *unk_1500;
    u8 pad_1504[0x163C - 0x1504];
    u8 unk_163C[0x20];
    fn_1_304A8_SlotTable unk_165C;
    u16 unk_17F4;
} fn_1_304A8_State;

void fn_1_304A8(void) {
    fn_1_304A8_State *state;
    u8 *sub;
    int i;
    int j;
    int count;

    state = (fn_1_304A8_State *)&lbl_1_bss_3C00;
    if ((s32)lbl_1_bss_25BA0.unk_0 == 0) {
        sub = (u8 *)&state->unk_30;
        state->unk_17F4 = sub[7];
        if (sub[5] == 0) {
            for (i = 0; i < sub[8]; i++) {
                if (*(u32 *)(sub + 0x1480 + i * 4) != 0) {
                    if (state->unk_30 & 0x400000) {
                        break;
                    }
                    fn_1_3F2A0();
                    count = sub[8];
                    if (state->unk_2A <= 41) {
                        for (j = 0; j < count; j++) {
                            u8 id = sub[j * 0xA0 + 0x157];
                            state->unk_165C.slots[id].unk_4 = sub[j * 0xA0 + 0x154];
                            state->unk_165C.slots[id].unk_6 = state->unk_163C[j];
                            state->unk_165C.unk_194[id] = j;
                        }
                    } else {
                        for (j = 0; j < count; j++) {
                            u8 id = sub[j * 0xA0 + 0xDC];
                            state->unk_165C.slots[id].unk_4 = sub[j * 0xA0 + 0x154];
                            state->unk_165C.slots[id].unk_6 = state->unk_163C[j];
                            state->unk_165C.unk_194[id] = j;
                        }
                    }
                    state->unk_165C.unk_192 = count;
                    state->unk_165C.unk_191 |= 2;
                    state->unk_165C.unk_190 = sub[7];
                    state->unk_30 |= 0x400000;
                    state->unk_17F4 = 14;
                    break;
                }
            }
        }
        fn_1_4A00(0, 30, state->unk_1500);
        lbl_1_bss_6EAB4.unk_0 |= 0x2C;
        lbl_1_bss_25BA0.unk_0 = 1;
        if (sub[5] == 0) {
            lbl_1_data_5B84 = 1;
        }
        fn_1_469BC();
        fn_1_8DBA4(0);
    }
}
