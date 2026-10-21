#include "types.h"

extern void *memset(void *, int, u32);

typedef struct JpegDec {
    u8 pad_0[0x400];
    u8 *ptr;            /* 0x400 */
    u8 *scan;           /* 0x404 */
    u8 pad_408[0x4];
    u16 unk_40C;
    u16 unk_40E;
    u8 pad_410[0x4];
    u32 unk_414;
    u8 unk_418;
    u8 unk_419;
    u8 pad_41A[0x3];
    u8 unk_41D;
    u8 unk_41E;
    u8 format;          /* 0x41F */
    u8 pad_420[0x330];
    u8 *blocks[16];     /* 0x750 */
    u8 pad_790[0x16];
    u16 unk_7A6;
    u8 pad_7A8[0x2];
    u16 unk_7AA;
    u16 unk_7AC;
    u16 restart;        /* 0x7AE */
    u16 restartLeft;    /* 0x7B0 */
    u8 pad_7B2[0x2];
    u8 *heap;           /* 0x7B4 */
    u8 pad_7B8[0x10];
} JpegDec;

typedef struct JpegCtx {
    u8 *data;
    JpegDec *dec;
} JpegCtx;

typedef struct JpegInfo {
    u16 width;
    u16 height;
    u32 format;
} JpegInfo;

extern u8 fn_8003A1CC(JpegDec *);
extern u8 fn_80039C40(JpegDec *);
extern u8 fn_80039E48(JpegDec *);
extern u8 fn_8003A3D4(JpegDec *);

/* Reset the decoder work area and carve the 16 block buffers out of its heap. */
static inline void JpegDecInit(JpegDec *dec) {
    u8 i;
    u8 *buf;

    memset(dec, 0, sizeof(JpegDec));
    dec->heap = (u8 *)dec;
    dec->heap += 0x7E0;
    dec->ptr = dec->scan;
    dec->unk_414 = 0x21;
    dec->unk_7AA = 0;
    dec->unk_7AC = 0;
    dec->unk_7A6 = 0;
    dec->unk_41D = 0;
    dec->unk_40C = 0;
    dec->unk_40E = 0;
    dec->unk_418 = 0;
    dec->unk_419 = 0;
    buf = (u8 *)(((u32)dec->heap + 0x1F) & ~0x1F);
    dec->heap = buf + 0x800;
    for (i = 0; i < 16; i++) {
        dec->blocks[i] = buf + i * 0x80;
    }
}

/* Set up a JPEG decoder over `data` and parse its markers up to the first
 * scan. The error exits share one tail, as in the retail layout. */
int fn_8003C1A4(JpegCtx *ctx, u8 *status, JpegDec *work, u8 *data, JpegInfo *info) {
    struct { u16 value; } len;
    u8 found;
    u8 marker;
    u8 r;

    u32 bad;
    u32 seglen;
    u32 k;
    JpegDec *dec = work;
    struct { u32 value; } j;

    bad = 0;
    switch (info->format) {
    case 1:
        bad = info->width % 8u;
        bad |= info->height % 8u;
        break;
    case 2:
        bad = info->width % 16u;
        bad |= info->height % 8u;
        break;
    case 4:
        bad = info->width % 16u;
        bad |= info->height % 16u;
        break;
    }
    if (bad != 0 || info->width > 0x400 || info->height > 0x400) {
        goto bad_size; /* shared error tail */
    }
    ctx->data = data;
    ctx->dec = dec;
    if (dec == NULL) {
        goto no_buffer; /* shared error tail */
    }
    JpegDecInit(dec);
    dec->ptr = ctx->data;
    found = 0;
    do {
        if (*dec->ptr++ != 0xFF) {
            goto bad_marker; /* shared error tail */
        }
        while (*dec->ptr == 0xFF) {
            dec->ptr++;
        }
        marker = *dec->ptr++;
        if (marker <= 0xD7) {
            if (marker == 0xC4) {
                r = fn_8003A1CC(dec);
                if (r != 0) {
                    goto failed; /* shared error tail */
                }
            } else if (marker == 0xC0) {
                r = fn_80039C40(dec);
                dec->format = info->format;
                if (r != 0) {
                    goto failed; /* shared error tail */
                }
            } else {
                *status = 5;
                return 0;
            }
        } else if (marker >= 0xD8 && marker <= 0xDF) {
            if (marker == 0xDD) {
                dec->unk_41E = 1;
                dec->ptr += 2;
                dec->restart = (dec->ptr[0] << 8) | dec->ptr[1];
                dec->ptr += 2;
                dec->restartLeft = dec->restart;
            } else if (marker == 0xDB) {
                r = fn_80039E48(dec);
                if (r != 0) {
                    goto failed; /* shared error tail */
                }
            } else if (marker == 0xDA) {
                r = fn_8003A3D4(dec);
                if (r != 0) {
                    goto failed; /* shared error tail */
                }
                found = 1;
                dec->scan = dec->ptr;
            } else if (marker != 0xD8) {
                *status = 5;
                return 0;
            }
        } else if (marker < 0xE0) {
        } else if (marker >= 0xE0 && marker <= 0xEF) {
            len.value = (dec->ptr[0] << 8) | dec->ptr[1];
            for (j.value = 0; j.value < len.value; j.value++) {
                dec->ptr++;
            }
        } else if (marker == 0xFE) {
            seglen = (dec->ptr[0] << 8) | dec->ptr[1];
            dec->ptr += 2;
            for (k = 0; k < seglen - 2; k++) {
                dec->ptr++;
            }
        } else {
            *status = 5;
            return 0;
        }
    } while (!found);
    *status = 0;
    return 1;

no_buffer:
    *status = 2;
    goto fail; /* Keep the verified branch to fail. */
bad_marker:
    *status = 1;
    goto fail; /* Keep the verified branch to fail. */
failed:
    *status = r;
    goto fail; /* Keep the verified branch to fail. */
bad_size:
    *status = 13;
fail:
    return 0;
}
