#ifndef DATA_LBL_1_RODATA_D5DC_H
#define DATA_LBL_1_RODATA_D5DC_H

#include "types.h"

typedef struct {
    u8 pad_0[44];
    struct {
        u16 unk_0;
        u8 pad_2[10];
        u16 unk_C;
        u16 unk_E;
        u16 unk_10;
        u16 unk_12;
        u16 unk_14;
    } window;
    u8 pad_42[44];
} Data_lbl_1_rodata_D5DC;
extern const Data_lbl_1_rodata_D5DC lbl_1_rodata_D5DC[6];

#endif
