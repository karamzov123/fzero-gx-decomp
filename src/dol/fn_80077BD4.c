#include "types.h"

extern u32 fn_80072404(u32, s32);

static inline u32 fn_80077BD4_entry(u32 entry) {
    u32 node;
    u32 j;
    u32 sum;
    node = entry + *(u32 *)(entry + 32);
    sum = 0;
    j = 0;
    while (j < (u32)(*(u16 *)(entry + 26) + *(u16 *)(entry + 28))) {
        u32 n;
        n = fn_80072404(*(u32 *)(node + 28), 0);
        if ((*(u32 *)(entry + 4) & 0x18) != 0) {
            if (*(u32 *)(node + 40) != 0) {
                sum += n * *(u32 *)(node + 40);
            }
            if (*(u32 *)(node + 44) != 0) {
                sum += n * *(u32 *)(node + 44);
            }
            node += 96;
        } else {
            u32 p;
            u32 k;
            u32 a;
            u32 b;
            if (*(u32 *)(node + 40) != 0) {
                sum += *(u32 *)(node + 40) / n;
            }
            if (*(u32 *)(node + 44) != 0) {
                sum += *(u32 *)(node + 44) / n;
            }
            p = node;
            p += 96;
            for (k = 0; k < 2; k++) {
                if (*(u8 *)(node + 19) & (1 << k)) {
                    p += ((u32 *)(node + 40))[k];
                }
            }
            if (*(u8 *)(node + 19) & 0xC) {
                b = *(u32 *)(p + 12);
                a = *(u32 *)(p + 8);
                p += 32;
                p += a;
                p += b;
            }
            node = p;
        }
        j++;
    }
    return sum;
}

u32 fn_80077BD4(u32 arg0, u32 arg1, u32 arg2) {
    u32 off;
    u32 i;
    u32 total;
    u32 entry;

    total = 0;
    i = 0;
    off = 0;
    while (i < *(u32 *)(arg0 + 0)) {
        entry = *(u32 *)(*(u32 *)(arg0 + 8) + off);
        if (entry != 0) {
            total += fn_80077BD4_entry(entry);
        }
        off += 8;
        i++;
    }
    return total;
}
