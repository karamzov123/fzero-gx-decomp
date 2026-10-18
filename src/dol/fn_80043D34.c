
#include "types.h"

unsigned char *fn_80043D34(unsigned char *header, int *rate, int *channels, int *bits,
                           int *samples);

unsigned char *fn_80043D34(unsigned char *header, int *rate, int *channels, int *bits,
                           int *samples) {
    unsigned char *p;
    unsigned char *end;
    unsigned char *data;
    signed long id;
    int size;
    signed long form;
    int have_comm;
    int have_ssnd;
    unsigned short exp;
    unsigned short mant;
    unsigned long offset;
    p = header + 12;
    have_comm = 0;
    have_ssnd = 0;
    data = ((void *)0);
    id = ((unsigned int)(header)[0] | ((unsigned int)(header)[1] << 8) |
          ((unsigned int)(header)[2] << 16) | ((unsigned int)(header)[3] << 24));
    size = ((unsigned int)(header + 4)[0] | ((unsigned int)(header + 4)[1] << 8) |
            ((unsigned int)(header + 4)[2] << 16) | ((unsigned int)(header + 4)[3] << 24));
    size = ((((size) >> 24) & 0xFF) | (((size) >> 8) & 0xFF00) | (((size) << 8) & 0xFF0000) |
            ((size) << 24));
    form = ((unsigned int)(header + 8)[0] | ((unsigned int)(header + 8)[1] << 8) |
            ((unsigned int)(header + 8)[2] << 16) | ((unsigned int)(header + 8)[3] << 24));
    if (id != 0x4D524F46)
        return ((void *)0);
    if (form != 0x46464941)
        return ((void *)0);
    end = p + size - 4;
    while (p < end) {
        id = ((unsigned int)(p)[0] | ((unsigned int)(p)[1] << 8) | ((unsigned int)(p)[2] << 16) |
              ((unsigned int)(p)[3] << 24));
        size = ((unsigned int)(p + 4)[0] | ((unsigned int)(p + 4)[1] << 8) |
                ((unsigned int)(p + 4)[2] << 16) | ((unsigned int)(p + 4)[3] << 24));
        size = ((((size) >> 24) & 0xFF) | (((size) >> 8) & 0xFF00) | (((size) << 8) & 0xFF0000) |
                ((size) << 24));
        p += 8;
        switch (id) {
        case 0x4D4D4F43:
            if (have_comm != 0)
                break;
            if (size < 18)
                return ((void *)0);
            have_comm = 1;
            *channels = (p[0] & 0xFF) | ((p[1] & 0xFFFF) << 8);
            *channels = ((((*channels) >> 8) & 0xFF) | (((*channels) & 0xFF) << 8));
            *samples = ((unsigned int)(p + 2)[0] | ((unsigned int)(p + 2)[1] << 8) |
                        ((unsigned int)(p + 2)[2] << 16) | ((unsigned int)(p + 2)[3] << 24));
            *samples = ((((*samples) >> 24) & 0xFF) | (((*samples) >> 8) & 0xFF00) |
                        (((*samples) << 8) & 0xFF0000) | ((*samples) << 24));
            *bits = (p[6] & 0xFF) | ((p[7] & 0xFFFF) << 8);
            *bits = ((((*bits) >> 8) & 0xFF) | (((*bits) & 0xFF) << 8));
            exp = (((((unsigned short)(p[8] | (p[9] << 8))) >> 8) & 0xFF) |
                   ((((unsigned short)(p[8] | (p[9] << 8))) & 0xFF) << 8));
            mant = (((((unsigned short)(p[10] | (p[11] << 8))) >> 8) & 0xFF) |
                    ((((unsigned short)(p[10] | (p[11] << 8))) & 0xFF) << 8));
            p += 0x12;
            *rate = (signed long)mant >> (0x400E - exp);
            if (have_ssnd != 0)
                return data;
            break;
        case 0x444E5353:
            if (have_ssnd != 0)
                break;
            have_ssnd = 1;
            offset = ((unsigned int)(p)[0] | ((unsigned int)(p)[1] << 8) |
                      ((unsigned int)(p)[2] << 16) | ((unsigned int)(p)[3] << 24));
            offset = ((((offset) >> 24) & 0xFF) | (((offset) >> 8) & 0xFF00) |
                      (((offset) << 8) & 0xFF0000) | ((offset) << 24));
            p += 4;
            data = p + offset;
            if (have_comm != 0)
                return data;
            break;
        default:
            p += (size + 1) & ~1;
            break;
        }
    }
    return data;
}
