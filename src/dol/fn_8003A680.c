#include "types.h"

struct Sig_fn_8003A680_fn_8003A1CC_Huff {
    u8 *bits;
    s8 *huffsize;
    s32 *huffcode;
    u16 count;
    u8 padE[0x2];
    u8 *huffval;
    u8 pad14[0x94];
};
struct Sig_fn_8003A680_fn_8003A1CC_Dec {
    u8 pad0[0x400];
    u8 *ptr;
    u8 pad404[0x14];
    u8 tables;
    u8 pad419[0x7];
    struct Sig_fn_8003A680_fn_8003A1CC_Huff huff[4];
    u8 pad6C0[0xF4];
    u8 *data;
};

s32 fn_8003A680(struct Sig_fn_8003A680_fn_8003A1CC_Dec *arg0, u8 arg1) {
    s32 length;
    s32 k;
    s32 code;

    k = 0;
    length = arg0->huff[arg1].huffsize[0];
    while (arg0->huff[arg1].huffsize[k] != 0) {
        while (arg0->huff[arg1].huffsize[k] == length) {
            k++;
        }
        length++;
    }
    arg0->huff[arg1].huffcode = (s32 *)arg0->data;
    arg0->data += k * 4;
    k = 0;
    code = 0;
    length = arg0->huff[arg1].huffsize[0];
    while (arg0->huff[arg1].huffsize[k] != 0) {
        while (arg0->huff[arg1].huffsize[k] == length) {
            arg0->huff[arg1].huffcode[k++] = code;
            code++;
        }
        code <<= 1;
        length++;
    }
    return 0;
}
