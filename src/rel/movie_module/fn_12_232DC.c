#include "types.h"

extern u8 *fn_12_A0D8(u8 *data, int size, int mode);
extern u8 lbl_12_rodata_AB8[36];
extern u8 lbl_12_rodata_BD8[56];

typedef struct MovieInfo {
    u8 unk_000[8];
    u8 *field_008;
    u8 unk_00c[8];
    u32 field_014;
    u32 field_018;
    s32 field_01c;
    u32 field_020;
    u32 field_024;
} MovieInfo;

int fn_12_232DC(u8 *data, int size, MovieInfo *info) {
    u8 *entry;
    u8 b4;
    u8 b7;
    u8 b5;
    u8 b6;
    u8 b8;
    u8 b9;
    u8 b10;
    u8 b11;
    u8 raw[12];

    while (size > 0) {
        entry = fn_12_A0D8(data, size, 0x40);
        if (entry == NULL) {
            return 0;
        }
        b7 = entry[7];
{
    int offset;
        offset = entry - data;
        data = (u8 *)(offset + (u32)data);
        b4 = entry[4];
        b6 = entry[6];
        offset++;
        b5 = entry[5];
        b8 = entry[8];
        data++;
        b9 = entry[9];
        size -= offset;
}
        b10 = entry[10];
        b11 = entry[11];
        if (((0) == ((b7 >> 4)))) {
            continue;
        }
        b7 &= 0xf;
        if (b7 < 1 || b7 > 8) {
            continue;
        }
        if (((b10 >> 5) & 1) == 0) {
            continue;
        }
        info->field_014 = (b4 << 4) | (b5 >> 4);
        info->field_018 = ((b5 & 0xf) << 8) | b6;
        if (info->field_01c == 0) {
            info->field_01c = (((u32)b10 >> 6) | ((b8 << 10) | (b9 << 2))) * 50;
        }
        info->field_020 = *(u32 *)(lbl_12_rodata_AB8 + b7 * 4);
        info->field_024 = (((u32)b10 & 0x1f) << 5 | (b11 >> 3)) << 11;
        info->field_008 = lbl_12_rodata_BD8;
        break;
    }
    return 1;
}

