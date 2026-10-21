#include "types.h"

extern void *memset(void *, int, u32);

typedef struct JpegInfo {
    u16 height;
    u16 width;
    u32 format;
} JpegInfo;

/* Parse a baseline JPEG header (SOI, then markers up to SOF0) and report the
 * image size and chroma subsampling format. */
int fn_8003BE1C(u8 *data, JpegInfo *info) {
    u8 hsamp[4];
    u8 vsamp[4];
    u8 quant[8];
    u8 count;
    u8 i;
    u8 c;
    u8 marker;
    u8 soi0;
    u8 soi1;
    u16 len;
    u32 j;

    memset(info, 0, 8);
    soi0 = *data++;
    soi1 = *data++;
    if (soi0 != 0xFF || soi1 != 0xD8) {
        return 0;
    }
    while (1) {
        if (*data++ != 0xFF) {
            return 0;
        }
        while (*data == 0xFF) {
            data++;
        }
        marker = *data++;
        if (marker == 0xC0) {
            info->width = data[4] | (data[3] << 8);
            info->height = data[6] | (data[5] << 8);
            count = data[7];
            data += 8;
            if (count != 3) {
                return 0;
            }
            for (i = 0; i < count; i++) {
                data++;
                c = *data++;
                data++;
                hsamp[i] = c >> 4;
                vsamp[i] = c & 0xF;
            }
            if (hsamp[0] / hsamp[1] == 2 && hsamp[0] / hsamp[2] == 2) {
                if (vsamp[0] / vsamp[1] == 2 && vsamp[0] / vsamp[2] == 2) {
                    info->format = 4;
                } else if (vsamp[0] == vsamp[1] && vsamp[0] == vsamp[2]) {
                    info->format = 2;
                }
            } else if (hsamp[0] == hsamp[1] && hsamp[0] == hsamp[2]) {
                if (vsamp[0] == vsamp[1] && vsamp[0] == vsamp[2]) {
                    info->format = 1;
                }
            } else {
                return 0;
            }
            break;
        } else if (marker >= 0xC0 && marker <= 0xFE) {
            len = data[1] | (data[0] << 8);
            data += 2;
            for (j = 0; j < (u32)(len - 2); j++) {
                data++;
            }
        } else {
            return 0;
        }
    }
    return 1;
}
