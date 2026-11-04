#ifndef DATA_LBL_80132300_H
#define DATA_LBL_80132300_H

#include "types.h"

typedef struct {
    u32 at_0;
    u32 at_4;
    u32 at_8;
    void (*at_C)(void);
    void (*at_10)(void);
    void (*at_14)(void);
    void (*at_18)(void);
    void (*at_1C)(void);
    void (*at_20)(void);
    void (*at_24)(void);
    void (*at_28)(void);
    void (*at_2C)(void);
} Data_lbl_80132300;
extern Data_lbl_80132300 lbl_80132300;

#endif
