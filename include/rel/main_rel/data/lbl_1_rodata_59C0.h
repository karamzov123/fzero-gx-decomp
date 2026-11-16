#ifndef DATA_LBL_1_RODATA_59C0_H
#define DATA_LBL_1_RODATA_59C0_H

#include "types.h"

typedef struct {
    struct {
        s16 x;
        s16 y;
        f32 scale;
        s16 ofs_x;
        s16 ofs_y;
    } entries[6];
} Data_lbl_1_rodata_59C0;
extern const Data_lbl_1_rodata_59C0 lbl_1_rodata_59C0;

#endif
