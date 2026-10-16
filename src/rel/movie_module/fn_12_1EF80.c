#include "types.h"

typedef struct {
    u32 pad_00[6];
    u8 *out;    /* 0x18 */
    u8 *row_a;  /* 0x20 */
    u8 *row_b;  /* 0x24 */
    u8 *row_c;  /* 0x28 */
} Fn12_1EF80_Obj;

/* fn_12_1EF80: byte-wise 3x3 neighbourhood sums over three source rows,
 * packed four bytes per 32-bit word with rlwinm/rlwimi, 16 columns at a time. */
void fn_12_1EF80(Fn12_1EF80_Obj *obj) {
    u8 *ra = obj->row_a;
    u8 *rb = obj->row_b;
    u8 *rc = obj->row_c;
    u32 *out = (u32 *)obj->out;
    s32 n;

    for (n = 0x10; n != 0; n--) {
        u32 w0;
        u32 w1;

        w0 = ((u32)ra[0] + (u32)ra[1] + (u32)ra[2] + 2) & 0xFF;
        w0 |= ((u32)ra[3] + (u32)ra[4] + (u32)ra[5] + 2) << 8;
        w0 |= ((u32)ra[6] + (u32)ra[7] + (u32)ra[8] + 2) << 16;
        w0 |= ((u32)ra[9] + (u32)ra[10] + (u32)ra[11] + 2) << 24;

        w1 = ((u32)ra[12] + (u32)ra[13] + (u32)ra[14] + 2) & 0xFF;
        w1 |= ((u32)rb[0] + (u32)rb[1] + (u32)rb[2] + 2) << 8;
        w1 |= ((u32)rb[3] + (u32)rb[4] + (u32)rb[5] + 2) << 16;
        w1 |= ((u32)rb[6] + (u32)rb[7] + (u32)rb[8] + 2) << 24;

        out[0] = w0;
        out[1] = w1;

        out += 2;
        ra += 0x10;
        rb += 0x10;
        rc += 0x10;
    }
}
