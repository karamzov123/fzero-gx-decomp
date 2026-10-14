/* Non-matching: best partial attempt (96.18% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/live_camera.h"

typedef struct Sig_fn_1_45B2C_Fn145B2CData {
    s32 kind;
    u8 pad[0x54];
    void *value;
} Sig_fn_1_45B2C_Fn145B2CData;
extern void *fn_1_45B2C(Sig_fn_1_45B2C_Fn145B2CData *);
extern void fn_1_1383C(void);
extern u32 fn_1_45964(Sig_fn_1_45B2C_Fn145B2CData *, void *, u32, u32, void (*)(void));
extern void fn_1_3308(void);
extern void fn_1_D3214(void);
extern void DCInvalidateRange(void *, u32);
extern void fn_8000659C(void);
extern void fn_8001AF64(void);

typedef struct StreamState {
    u8 pad[0x2328];
    volatile u32 index;
    volatile u32 offset;
    u8 pad2[0x88];
    volatile u8 buffer;
    u8 pad3[3];
    volatile s32 done;
} StreamState;

#pragma opt_propagation off
u8 fn_1_1361C(Sig_fn_1_45B2C_Fn145B2CData *arg0, u8 **arg1) {
    StreamState *state = (StreamState *)lbl_1_bss_1800;
    s32 size;
    u8 result;
    u32 lab_t3;
    u32 lab_t2;
    if (state->offset == 0) {
        size = lbl_1_data_5184;
        state->buffer = 0;
        if (state->offset + lbl_1_data_5184 > (u32)fn_1_45B2C(arg0)) {
            size = ((u32)fn_1_45B2C(arg0) - state->offset + 31) & ~31;
        }
        if (size > 0) {
            DCInvalidateRange(arg1[state->buffer], lbl_1_data_5184);
            state->done = 0;
            lab_t3 = state->offset;
            lab_t2 = size;
            fn_1_45964(arg0, arg1[state->buffer], lab_t2, lab_t3, fn_1_1383C);
        }
        state->offset += lbl_1_data_5184;
        state->buffer = 1 - state->buffer;
    }
    if (state->index == 0) {
        size = lbl_1_data_5184;
        if (state->offset + lbl_1_data_5184 > (u32)fn_1_45B2C(arg0)) {
            size = ((u32)fn_1_45B2C(arg0) - state->offset + 31) & ~31;
        }
        while (state->done == 0) {
            fn_8000659C();
            fn_1_3308();
            fn_1_D3214();
            fn_8001AF64();
        }
        if (size > 0) {
            DCInvalidateRange(arg1[state->buffer], lbl_1_data_5184);
            state->done = 0;
            lab_t3 = state->offset;
            lab_t2 = size;
            fn_1_45964(arg0, arg1[state->buffer], lab_t2, lab_t3, fn_1_1383C);
        }
        state->offset += lbl_1_data_5184;
        state->buffer = 1 - state->buffer;
    }
    result = arg1[state->buffer][state->index];
    state->index++;
    if (state->index >= lbl_1_data_5184) {
        state->index = 0;
    }
    return result;
}
#pragma opt_propagation reset

