#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/reset.h"

extern s32 fn_1_B7E48(void);
extern void VIWaitForRetrace(void);
extern void VISetBlack(int arg0);
extern void fn_8006B224(void);
extern void fn_8006FFCC(int arg0);
extern void fn_8006FDEC(void);
extern void fn_8006FEFC(void);
extern void fn_8000EE50(void *arg0, void *arg1);
extern void fn_1_C37A0(void);
extern void fn_1_F7578(void);
extern void fn_1_A0AA4(void);
extern void fn_1_A02F0(void);
extern void OSResetSystem(int reset, u32 reset_code, int force);
extern int OSPanic(void *arg0, int arg1, ...);
extern void *memset(void *dest, int value, unsigned long size);
extern void *memcpy(void *dest, const void *src, unsigned long size);
extern u8 lbl_801A66B0[4];
extern const f64 lbl_1_rodata_6160;
extern const f64 lbl_1_rodata_6158;
extern int fn_8000F5F0(void);
extern int fn_1_A6F2C(void);
extern int fn_80006AF4(void);
extern int fn_1_A6F6C(void);
extern int fn_1_A6FA0(void);
extern void fn_80070F44(void);
extern void fn_1_D3B6C(void);
extern void fn_80071100(void);

/* fzgx:begin fn_1_D3214 */
#define RESET_AREA ((u8 *)((u32)0x8070 << 16))

// Completes an accepted reset request and transfers control to the reset system.
void fn_1_D3214(void) {
    Obj_1_bss_7AD48 *state = &lbl_1_bss_7AD48;
    int result;
    u32 callback;

    if (state->unk_0 != 0 || state->unk_1 != 0) {
        result = fn_1_B7E48();
        if (result == 0 && state->unk_2 == 0) {
            state->unk_2 = 1;
            VIWaitForRetrace();
            VISetBlack(1);
            callback = state->unk_4;
            if (callback != 0) {
                result = ((int (*)(void))callback)();
                if (result == 0) {
                    return;
                }
            }
            fn_1_C37A0();
            fn_1_F7578();
            fn_8006B224();
            fn_1_A0AA4();
            fn_1_A02F0();
            fn_8006FFCC(0);
            fn_8006FDEC();
            fn_8006FEFC();
            fn_8000EE50(RESET_AREA, RESET_AREA + 0x20);
            memset(RESET_AREA, 0, 0x20);
            memcpy(RESET_AREA, lbl_801A66B0, 4);
            state->unk_0 = 0;
            OSResetSystem(0, state->unk_8, 0);
            OSPanic(&lbl_1_data_3DBC0, 0x76, lbl_1_data_3DBC8);
        }
    }
}
/* fzgx:end fn_1_D3214 */

/* fzgx:begin fn_1_D332C */
void fn_1_D332C(u16 *data) {
    u16 *entry;
    Obj_1_bss_7AD48 *state = &lbl_1_bss_7AD48;
    int i;

    if (state->unk_9 == 1 && fn_8000F5F0() == 0) {
        state->unk_A = 0xff;
        state->unk_8 = 2;
    } else {
        state->unk_8 = 1;
    }

    if (fn_8000F5F0() != 0) {
        state->unk_9 = 1;
    }

    if ((f64)state->unk_A > lbl_1_rodata_6158) {
        state->unk_0 = 1;
    }

    entry = data;
    for (i = 0; i < 4; i++) {
        if ((*entry & 0x1600) == 0x1600) {
            state->unk_A++;
            break;
        }
        entry += 6;
    }

    if (i == 4) {
        state->unk_A = 0;
    }

    if (state->unk_0 != 0 &&
        fn_1_A6F2C() != 0 &&
        fn_80006AF4() == 0) {
        state->unk_0 = 0;
        state->unk_9 = 0;
        state->unk_A = 0;
        if (fn_1_A6F6C() == 0) {
            fn_1_A6FA0();
        }
    }
}
/* fzgx:end fn_1_D332C */

/* fzgx:begin fn_1_D3474 */
#define RESET_AREA ((u8 *)((u32)0x8070 << 16))

void fn_1_D3474(void) {
    Obj_1_bss_7AD48 *state = &lbl_1_bss_7AD48;
    int result;
    u32 callback;

    state->unk_0 = 1;
    result = fn_1_B7E48();
    if (result == 0 && state->unk_2 == 0) {
        state->unk_2 = 1;
        VIWaitForRetrace();
        VISetBlack(1);
        callback = state->unk_4;
        if (callback != 0) {
            result = ((int (*)(void))callback)();
            if (result == 0) {
                return;
            }
        }
        fn_1_C37A0();
        fn_1_F7578();
        fn_8006B224();
        fn_1_A0AA4();
        fn_1_A02F0();
        fn_8006FFCC(0);
        fn_8006FDEC();
        fn_8006FEFC();
        fn_8000EE50(RESET_AREA, RESET_AREA + 0x20);
        memset(RESET_AREA, 0, 0x20);
        memcpy(RESET_AREA, lbl_801A66B0, 4);
        state->unk_0 = 0;
        OSResetSystem(0, state->unk_8, 0);
        OSPanic(&lbl_1_data_3DBC0, 0x76, lbl_1_data_3DBC8);
    }
}
/* fzgx:end fn_1_D3474 */

/* fzgx:begin fn_1_D357C */
u8 fn_1_D357C(void) {
    return lbl_1_bss_7AD48.unk_0;
}
/* fzgx:end fn_1_D357C */

/* fzgx:begin fn_1_D358C */
void fn_1_D358C(void) {
    fn_80070F44();
    fn_1_D3B6C();
}
/* fzgx:end fn_1_D358C */

/* fzgx:begin fn_1_D35B0 */
// Wrapper that calls fn_80071100 followed by fn_1_D3B6C.
void fn_1_D35B0(void) {
    fn_80071100();
    fn_1_D3B6C();
}
/* fzgx:end fn_1_D35B0 */
