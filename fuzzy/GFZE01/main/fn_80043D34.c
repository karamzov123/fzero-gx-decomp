/* Non-matching: best partial attempt (79.40% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

#define RD16(p) ((p)[0] | ((p)[1] << 8))
#define RD32(p) ((p)[0] | ((p)[1] << 8) | ((p)[2] << 16) | ((p)[3] << 24))
#define SW16(x) ((((x) & 0xFF) << 8) | (((x) >> 8) & 0xFF))
#define SW32(x) ((((x) >> 8) & 0xFF00) | (((x) >> 24) & 0xFF) | (((x) << 8) & 0xFF0000) | ((x) << 24))

u8 *fn_80043D34(u8 *arg0, s32 *rate, s32 *channels, s32 *bits, s32 *frames) {
    u8 *p;
    u8 *end;
    s32 comm;
    s32 ssnd;
    u8 *data;
    u32 form;
    u32 size;
    u32 aiff;
    s32 id;
    u32 csize;
    u16 e;
    u16 m;

    p = arg0 + 12;
    comm = 0;
    form = RD32(arg0);
    size = RD32(arg0 + 4);
    aiff = RD32(arg0 + 8);
    size = SW32(size);
    ssnd = 0;
    data = 0;
    if (form != 0x4D524F46) {
        return 0;
    }
    if (aiff != 0x46464941) {
        return 0;
    }
    end = p + (size - 4);
    while (p < end) {
        id = RD32(p);
        csize = RD32(p + 4);
        p += 8;
        csize = SW32(csize);
        switch (id) {
        case 0x4D4D4F43:
            if (comm == 0) {
                if ((s32)csize < 18) {
                    return 0;
                }
                comm = 1;
                *channels = RD16(p);
                *channels = SW16(*channels);
                *frames = RD32(p + 2);
                *frames = SW32(*frames);
                *bits = RD16(p + 6);
                *bits = SW16(*bits);
                e = SW16(RD16(p + 8));
                m = SW16(RD16(p + 10));
                p += 18;
                *rate = (s32)m >> (0x400E - e);
                if (ssnd != 0) {
                    return data;
                }
            }
            break;
        case 0x444E5353:
            if (ssnd == 0) {
                u32 off;
                ssnd = 1;
                off = RD32(p);
                p += 4;
                off = SW32(off);
                data = p + off;
                if (comm != 0) {
                    return data;
                }
            }
            break;
        default:
            p += (csize + 1) & ~1;
            break;
        }
    }
    return data;
}
