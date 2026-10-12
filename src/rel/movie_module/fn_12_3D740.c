#include "types.h"

extern f32 lbl_12_bss_1E088[213];
extern u8 lbl_12_data_EA0[36];
extern f64 lbl_12_rodata_2E80[3];
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

void fn_12_3D740(void *output)
{
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
    fn_12_3E688(state->tableY, state->tableU, state->tableV, bytes + 0x1000);
    fn_12_3E500(lbl_12_data_EA0, state->coefficients);

    offset = 0;
    tableY = state->tableY;
    tableU = state->tableU;
    tableV = state->tableV;
    coefficients = state->coefficients;
    for (; offset != 0x1000; offset += 0x10) {
        *(f32 *)((u8 *)state->output0 + offset + 4) = (f32)*tableY * coefficients[0];
        *(f32 *)((u8 *)state->output0 + offset + 8) = (f32)*tableY * coefficients[3];
        *(f32 *)((u8 *)state->output0 + offset + 12) = (f32)*tableY * coefficients[6];
        tableY++;
        *(f32 *)((u8 *)state->output0 + offset) = lbl_12_rodata_2E78;
        *(f32 *)((u8 *)state->output1 + offset + 4) = ((f32)*tableU - lbl_12_rodata_2E7C) * coefficients[1];
        *(f32 *)((u8 *)state->output1 + offset + 8) = ((f32)*tableU - lbl_12_rodata_2E7C) * coefficients[4];
        *(f32 *)((u8 *)state->output1 + offset + 12) = ((f32)*tableU - lbl_12_rodata_2E7C) * coefficients[7];
        tableU++;
        *(f32 *)((u8 *)state->output2 + offset + 4) = ((f32)*tableV - lbl_12_rodata_2E7C) * coefficients[2];
        *(f32 *)((u8 *)state->output2 + offset + 8) = ((f32)*tableV - lbl_12_rodata_2E7C) * coefficients[5];
        *(f32 *)((u8 *)state->output2 + offset + 12) = ((f32)*tableV - lbl_12_rodata_2E7C) * coefficients[8];
        tableV++;
    }
}
