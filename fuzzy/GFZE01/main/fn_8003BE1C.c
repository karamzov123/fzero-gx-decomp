/* Non-matching: best partial attempt (94.62% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern void * memset(void *, int, u32);

struct JpegInfo {
    u16 width;
    u16 height;
    u32 sampling;
};

#pragma opt_dead_assignments off
#pragma opt_propagation off
int fn_8003BE1C(u8 *p, struct JpegInfo *info) {
    u8 h[4];
    u8 w[4];
    struct { u8 value; } i;
    struct { u8 value; } n;
    struct { u8 value; } m;
    u32 k;
    struct { u16 value; } l;
    u8 m0;
    u8 m1;

    memset(info, 0, 8);
    m0 = (*((p) + (0)));
    m1 = p[1];
    p += 2;
    if (m0 != 0xFF || m1 != 0xD8) {
        return 0;
    }
    for (;;) {
        if (*p++ != 0xFF) {
            return 0;
        }
        while (*p == 0xFF) {
            p++;
        }
        m.value = *p++;
        if (m.value == 0xC0) {
            info->height = ((p[4]) | ((p[3] << 8)));
            info->width = ((p[6]) | ((p[5] << 8)));
            n.value = p[7];
            p += 8;
            if (n.value != 3) {
                return 0;
            }
            for (i.value = 0; i.value < n.value; i.value++) {
                s32 s = (*((p) + (1)));
                h[i.value] = s >> 4;
                w[i.value] = s & 0xF;
                p += 3;
            }
            if (h[0] / h[1] == 2 && h[0] / h[2] == 2) {
                if (w[0] / w[1] == 2 && w[0] / w[2] == 2) {
                    info->sampling = 4;
                } else if (w[0] == w[1] && w[0] == w[2]) {
                    info->sampling = 2;
                }
            } else if (h[0] == h[1] && h[0] == h[2]) {
                if (w[0] == w[1] && w[0] == w[2]) {
                    info->sampling = 1;
                }
            } else {
                return 0;
            }
            goto ok;
        } else if (m.value < 0xC0 || m.value > 0xFE) {
            break;
        } else {
            l.value = (p[0] << 8) | p[1];
            p += 2;
            for (k = 0; k < ((u32)l.value - 2); k++) {
                p++;
            }
        }
    }
    return 0;
ok:
    return 1;
}
#pragma opt_propagation reset

#pragma opt_dead_assignments reset
