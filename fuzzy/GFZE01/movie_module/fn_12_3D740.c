/* Non-matching: best partial attempt (93.69% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern f32 lbl_12_bss_1E088[213];
extern u8 lbl_12_data_EA0[36];
extern const f32 lbl_12_rodata_2E78;
extern const f32 lbl_12_rodata_2E7C;

extern void fn_12_3E688(u8 *tableY, u8 *tableU, u8 *tableV, void *output);
extern void fn_12_3E500(u8 *data, f32 *coefficients);

typedef struct MovieState {
    u8 pad0[0x24];
    f32 coefficients[9];
    void *output2;
    void *output1;
    void *output0;
    u8 tableV[0x100];
    u8 tableU[0x100];
    u8 tableY[0x100];
} MovieState;

#pragma opt_dead_assignments off
#pragma opt_lifetimes off
static inline u8 * fn_12_3D740_read_pointer(MovieState * owner) { return owner->tableU; }
u16 fn_12_3D740(void *output)
{
    u8 * fzgx_live_;
    u8 * fzgx_live;
    MovieState *state;
    u8 *bytes;
    u8 *tableY;
    u32 offset;
    u8 *tableU;
    u8 *tableV;
    f32 *coefficients;

    state = (MovieState *)lbl_12_bss_1E088;
    bytes = (u8 *)output;
    state->output0 = bytes;
    state->output1 = bytes + 0x1000;
    state->output2 = bytes + 0x2000;
    fzgx_live_ = state->tableY;
    fzgx_live = fzgx_live_;
    fn_12_3E688(fzgx_live, fn_12_3D740_read_pointer(state), state->tableV, bytes + 0x1000);
    fn_12_3E500(lbl_12_data_EA0, state->coefficients);

    offset = 0;
    fzgx_live_ = state->tableY;
    fzgx_live = fzgx_live_;
    tableY = fzgx_live;
    tableU = state->tableU;
    tableV = state->tableV;
#pragma opt_propagation off
    coefficients = state->coefficients;
#pragma opt_propagation on
    for (; offset != 0x1000; offset += 0x10) {
        *(f32 *)((u8 *)state->output0 + offset + 4) = coefficients[0] * (f32)*tableY;
        *(f32 *)(((8) + ((u8 *)state->output0 + offset))) = coefficients[3] * (f32)*tableY;
        *(f32 *)((u8 *)state->output0 + offset + 12) = coefficients[6] * (f32)*tableY;
        tableY++;
        *(f32 *)((u8 *)state->output0 + offset) = lbl_12_rodata_2E78;
        *(f32 *)((u8 *)state->output1 + offset + 4) = coefficients[1] * ((f32)*tableU - lbl_12_rodata_2E7C);
        *(f32 *)((u8 *)state->output1 + offset + 8) = coefficients[4] * ((f32)*tableU - lbl_12_rodata_2E7C);
        *(f32 *)((u8 *)state->output1 + offset + 12) = coefficients[7] * ((f32)*tableU - lbl_12_rodata_2E7C);
        tableU++;
        *(f32 *)((u8 *)state->output2 + offset + 4) = coefficients[2] * ((f32)*tableV - lbl_12_rodata_2E7C);
        *(f32 *)((u8 *)state->output2 + offset + 8) = coefficients[5] * ((f32)*tableV - lbl_12_rodata_2E7C);
        *(f32 *)((u8 *)state->output2 + offset + 12) = (*((coefficients) + (8))) * ((f32)*tableV - lbl_12_rodata_2E7C);
        tableV++;
    }
    return (u32)coefficients;
}
#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset

