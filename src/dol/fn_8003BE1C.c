#include "types.h"
#include "gqr.h"


/* --- dol/fn_8003BE1C.c --- */
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
            for (j = 0; j < (len - 2); j++) {
                data++;
            }
        } else {
            return 0;
        }
    }
    return 1;
}

/* --- dol/fn_8003C1A4.c --- */
/* --- dol/fn_8003C1A4.c --- */

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

typedef struct JpegInfo_u1 {
    u16 width;
    u16 height;
    u32 format;
} JpegInfo_u1;

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
int fn_8003C1A4(JpegCtx *ctx, u8 *status, JpegDec *work, u8 *data, JpegInfo_u1 *info) {
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

/* --- dol/fn_8003C6D0.c --- */
typedef struct ImgComponent {
    u32 width;          /* 0x00 */
    u32 height;         /* 0x04 */
    u8 *base;           /* 0x08 */
    u8 *dest;           /* 0x0C */
    u32 unk_10;         /* 0x10 */
    u32 unk_14;         /* 0x14 */
    u8 pad_18[0x11];
    u8 hshift;          /* 0x29 */
    u8 vshift;          /* 0x2A */
    u8 pad_2B[0x5];
} ImgComponent;

typedef struct ImgDecoder {
    u8 pad_0[0x400];
    u32 unk_400;
    u32 unk_404;
    u16 unk_408;
    u16 unk_40A;
    u16 unk_40C;
    u16 unk_40E;
    u8 pad_410[0x4];
    u32 unk_414;
    u8 pad_418[0x2];
    u8 unk_41A;
    u8 unk_41B;
    u8 unk_41C;
    u8 unk_41D;
    u8 pad_41E[0x6C8 - 0x41E];
    ImgComponent comp[3];
    u8 pad_758[0x7A0 - 0x758];
    u16 unk_7A0;
    u8 pad_7A2[0x4];
    u16 unk_7A6;
    u16 unk_7A8;
    u16 unk_7AA;
    u16 unk_7AC;
    u8 pad_7AE[0xA];
    u32 gqr2;
    u32 gqr5;
    u32 gqr6;
    u32 gqr7;
} ImgDecoder;

typedef struct ImgHandle {
    u8 pad_0[0x4];
    ImgDecoder *dec;
} ImgHandle;

typedef struct ProfRec {
    u32 t0_start;
    u32 t0_end;
    u32 t2_start;
    u32 t2_end;
    u32 t1_start;
    u32 t1_end;
    u32 t3_start;
    u32 t3_end;
    u32 t0_total;
    u32 t2_total;
    u32 t1_total;
    u32 t3_total;
    u32 t0_max;
    u32 count;
} ProfRec;

extern ProfRec lbl_801789C0[];
extern void PPCMtmmcr0(u32 value);
extern void PPCMtmmcr1(u32 value);
extern u32 fn_8000A020(void);
extern u32 fn_8000A030(void);
extern u32 fn_8000A040(void);
extern u32 fn_8000A050(void);
extern void DCStoreRange(void *, u32);
extern void fn_8003AB08(ImgDecoder *dec);
extern void fn_8003BB30(u8 *out, u8 *y, u8 *u, u8 *v, u32 width);
extern void fn_8003B9AC(u8 *out, u8 *y, u8 *u, u8 *v, u32 width);

void fn_8003C6D0(ImgHandle *handle, u8 *dst, u32 width, u32 height) {
    u32 stride;
    u8 vsub;
    u8 hsub;
    u32 h;
    s32 hraw;
    s32 vraw;
    u32 i;
    u32 ystride;
    u32 cstride;
    u32 w;
    u8 *out;
    u8 *y;
    u8 *u;
    u8 *v;
    ImgDecoder *dec;

    out = dst - 2;
    dec = handle->dec;
    dec->unk_400 = dec->unk_404;
    dec->unk_414 = 0x21;
    dec->unk_7AA = 0;
    dec->unk_7AC = 0;
    dec->unk_7A6 = 0;
    dec->unk_41D = 0;
    dec->unk_40C = 0;
    dec->unk_40E = 0;
    w = (dec->unk_408 > width) ? width : dec->unk_408;
    h = dec->unk_40A;
    if (h > height) {
        h = height;
    }
    hraw = dec->unk_41A - dec->comp[0].hshift;
    vraw = dec->unk_41B - dec->comp[0].vshift;
    ystride = dec->comp[0].width;
    cstride = dec->comp[1].width;
    {
        u32 j;
        for (j = 0; j < dec->unk_41C; j++) {
            dec->comp[j].dest = dec->comp[j].base;
        }
    }
    dec->unk_7AC = 0;
    PPCMtmmcr1(0);
    PPCMtmmcr0(0);
    lbl_801789C0[5].t0_start = fn_8000A050();
    lbl_801789C0[5].t1_start = fn_8000A040();
    lbl_801789C0[5].t2_start = fn_8000A030();
    lbl_801789C0[5].t3_start = fn_8000A020();
    PPCMtmmcr0(0x8B);
    PPCMtmmcr1(0x78400000);
    dec->gqr2 = gqr_get2();
    gqr_set2_decode();
    dec->gqr5 = gqr_get5();
    gqr_set5_decode();
    dec->gqr6 = gqr_get6();
    gqr_set6_decode();
    dec->gqr7 = gqr_get7();
    gqr_set7_decode();
    stride = width * 2;
    vsub = vraw;
    hsub = hraw;
    while (dec->unk_7AC < h) {
        dec->unk_7AA = 0;
        fn_8003AB08(dec);
        dec->unk_7AC += dec->unk_7A8;
        y = dec->comp[0].dest - 2;
        u = dec->comp[1].dest - 2;
        v = dec->comp[2].dest - 2;
        if (hsub == 0) {
            for (i = 0; i < dec->unk_7A8; i++) {
                fn_8003BB30(out, y, u, v, w);
                out += stride;
                y += ystride;
                u += cstride;
                v += cstride;
            }
        } else if (vsub == 0) {
            for (i = 0; i < dec->unk_7A8; i++) {
                fn_8003B9AC(out, y, u, v, w);
                out += stride;
                y += ystride;
                u += cstride;
                v += cstride;
            }
        } else {
            for (i = 0; i < dec->unk_7A8; i += 2) {
                fn_8003B9AC(out, y, u, v, w);
                out += stride;
                y += ystride;
                fn_8003B9AC(out, y, u, v, w);
                out += stride;
                y += ystride;
                u += cstride;
                v += cstride;
            }
        }
    }
    PPCMtmmcr1(0);
    PPCMtmmcr0(0);
    lbl_801789C0[5].count++;
    lbl_801789C0[5].t0_end = fn_8000A050();
    lbl_801789C0[5].t1_end = fn_8000A040();
    lbl_801789C0[5].t2_end = fn_8000A030();
    lbl_801789C0[5].t3_end = fn_8000A020();
    {
        u32 d = lbl_801789C0[5].t0_end - lbl_801789C0[5].t0_start;
        u32 max = lbl_801789C0[5].t0_max;
        if (d > max) {
            max = d;
        }
        lbl_801789C0[5].t0_max = max;
    }
    lbl_801789C0[5].t0_total += lbl_801789C0[5].t0_end - lbl_801789C0[5].t0_start;
    lbl_801789C0[5].t1_total += lbl_801789C0[5].t1_end - lbl_801789C0[5].t1_start;
    lbl_801789C0[5].t2_total += lbl_801789C0[5].t2_end - lbl_801789C0[5].t2_start;
    lbl_801789C0[5].t3_total += lbl_801789C0[5].t3_end - lbl_801789C0[5].t3_start;
    PPCMtmmcr0(0x8B);
    PPCMtmmcr1(0x78400000);
    PPCMtmmcr1(0);
    PPCMtmmcr0(0);
    lbl_801789C0[9].t0_start = fn_8000A050();
    lbl_801789C0[9].t1_start = fn_8000A040();
    lbl_801789C0[9].t2_start = fn_8000A030();
    lbl_801789C0[9].t3_start = fn_8000A020();
    PPCMtmmcr0(0x8B);
    PPCMtmmcr1(0x78400000);
    DCStoreRange(dst, width * height * 2);
    PPCMtmmcr1(0);
    PPCMtmmcr0(0);
    lbl_801789C0[9].count++;
    lbl_801789C0[9].t0_end = fn_8000A050();
    lbl_801789C0[9].t1_end = fn_8000A040();
    lbl_801789C0[9].t2_end = fn_8000A030();
    lbl_801789C0[9].t3_end = fn_8000A020();
    {
        u32 d = lbl_801789C0[9].t0_end - lbl_801789C0[9].t0_start;
        u32 max = lbl_801789C0[9].t0_max;
        if (d > max) {
            max = d;
        }
        lbl_801789C0[9].t0_max = max;
    }
    lbl_801789C0[9].t0_total += lbl_801789C0[9].t0_end - lbl_801789C0[9].t0_start;
    lbl_801789C0[9].t1_total += lbl_801789C0[9].t1_end - lbl_801789C0[9].t1_start;
    lbl_801789C0[9].t2_total += lbl_801789C0[9].t2_end - lbl_801789C0[9].t2_start;
    lbl_801789C0[9].t3_total += lbl_801789C0[9].t3_end - lbl_801789C0[9].t3_start;
    PPCMtmmcr0(0x8B);
    PPCMtmmcr1(0x78400000);
    gqr_put2(dec->gqr2);
    gqr_put5(dec->gqr5);
    gqr_put6(dec->gqr6);
    gqr_put7(dec->gqr7);
}
