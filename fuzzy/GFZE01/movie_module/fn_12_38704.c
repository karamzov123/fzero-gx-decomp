/* Non-matching: best partial attempt (96.20% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MovieResource {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u32 field_10;
    u32 field_14;
    u8 pad_18[0xC];
    u32 field_24;
} MovieResource;

extern char lbl_12_rodata_2184[152];
extern void MWSFSVM_Error(const char *, ...);

#pragma opt_propagation off
s32 fn_12_38704(MovieResource *res) {
    u32 scale;
    u32 lines;
    u32 offset_0;
    u32 offset_1;
    u32 offset_2;
    u32 offset_3;
    s32 height;
    s32 count;
    s32 mode;
    struct { s32 value; } data;
    s32 blocks;
    s32 shifted;
    s32 width;
    u32 offset_4;
    s32 rows;
    s32 cols;
    s32 row_bytes;
    s32 col_bytes;
    s32 row_blocks;
    s32 col_half;
    s32 block_size;
    s32 chunk;

    count = res->field_14;
    mode = res->field_0;
    data.value = res->field_4;
    if (count <= 0) {
        count = 1;
    }

    if (((2) == (mode))) {
        blocks = data.value / 8 / 2048;
        offset_0 = 0;
        offset_4 = 0;
        offset_1 = 0;
        offset_2 = 0;
        offset_3 = 0;
        lines = count * (blocks << 11);
    } else if (((3) == (mode))) {
        blocks = data.value / 8 / 2048;
        offset_0 = 0;
        offset_1 = 0;
        offset_2 = 0;
        offset_3 = 0;
        shifted = blocks * 2048;
        lines = count * shifted;
        offset_4 = shifted / 2 + 0x800;
    } else {
        blocks = data.value / 8 / 2048;
        offset_0 = 0;
        offset_3 = 0x10000 - 0x3E40;
        offset_1 = 0x5DCC;
        offset_2 = 0x5F0C;
        shifted = blocks * 2048;
        lines = count * shifted;
        offset_4 = shifted / 2 + 0x800;
    }

    scale = res->field_10;
    width = res->field_8;
    height = res->field_c;
    if ((s32)res->field_24 >= 4 || (s32)res->field_24 < 0) {
        MWSFSVM_Error(lbl_12_rodata_2184);
    }

    rows = (width + 15) / 16;
    row_bytes = rows << 4;
    cols = (height + 15) / 16;
    col_bytes = cols << 4;
    row_blocks = ((row_bytes + 31) / 32) << 5;
    col_half = col_bytes / 2;
    block_size = (((row_bytes / 2) + 31) / 32) << 5;
    chunk = (col_bytes * row_blocks) + ((col_half * block_size) << 1) + 32;

    return ((((offset_3))) + ((((((((((chunk << 1)) + ((offset_2))) + (((((((((offset_1)) + ((((lines))) + ((offset_4)))))) + (32))) + 0x840)))))) + (((((scale * chunk))) + (0x4800))))) + (offset_0)));
}
#pragma opt_propagation reset
