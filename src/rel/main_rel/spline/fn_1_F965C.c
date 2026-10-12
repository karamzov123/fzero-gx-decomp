#include "types.h"

extern const u8 lbl_1_rodata_6E38[440];
extern void fn_80008BA8(u32, u32, u32);

/* fn_1_F965C: for each of 0x2C rows, copy a 55-word rodata block to the stack,
 * convert one selected slice, and compare. Returns the matching row index. */
s32 fn_1_F965C(s16 arg) {
    u32 block[55];
    s32 want = (s16)arg;
    s32 i;
    s32 r26 = 0;
    s32 r27 = 0;
    s32 r28 = 0;
    s16 r25;

    for (i = 0; i < 0x2C; i++) {
        const u32 *src = (const u32 *)lbl_1_rodata_6E38 - 1;
        u32 *dst = block - 1;
        s32 n;
        s16 v;

        for (n = 0x37; n != 0; n--) {
            u32 w = src[1];
            u32 w2 = src[2];
            dst[1] = w;
            src += 2;
            dst += 2;
            (void)w2;
        }

        fn_80008BA8((u32)block + 0x2C, (u32)block + 0x8, 0xA);

        v = *(s16 *)((u8 *)block + 0xA);
        r25 = *(s16 *)((u8 *)block + 0x16);
        if (v != r25) {
            if ((s16)r27 != (s16)r28) {
                r27++;
            }
        }
    }

    return r26;
}
