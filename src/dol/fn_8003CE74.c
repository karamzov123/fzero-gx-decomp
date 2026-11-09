#include "types.h"
#include "gqr.h"

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
extern void fn_8003BD78(u8 *out, u8 *y, u8 *u, u8 *v, u8 *alpha);
extern void fn_8003BCE4(u8 *out, u8 *y, u8 *u, u8 *v, u8 *alpha);
extern u32 GXGetTexBufferSize(u16 width, u16 height, u32 format, u8 mipmap, u8 max_lod);

void fn_8003CE74(ImgHandle *handle, u8 *dst, u8 alpha) {
    ImgDecoder *dec;
    u8 *out;
    u8 *y;
    u8 *u;
    u8 *v;
    u8 *yy;
    u8 *uu;
    u8 *vv;
    u32 row;
    u32 tile;
    u32 k;
    u32 tiles;
    u32 ystride;
    u32 cstride;
    u32 ystride3;
    u32 cstride3;
    u8 hsub;
    u8 vsub;

    out = dst;
    dec = handle->dec;
    dec->unk_400 = dec->unk_404;
    dec->unk_414 = 0x21;
    dec->unk_7AA = 0;
    dec->unk_7AC = 0;
    dec->unk_7A6 = 0;
    dec->unk_41D = 0;
    dec->unk_40C = 0;
    dec->unk_40E = 0;
    hsub = dec->unk_41A - dec->comp[0].hshift;
    vsub = dec->unk_41B - dec->comp[0].vshift;
    ystride = dec->comp[0].width;
    cstride = dec->comp[1].width;
    for (k = 0; k < dec->unk_41C; k++) {
        dec->comp[k].dest = dec->comp[k].base;
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
    ystride3 = ystride * 3;
    cstride3 = cstride * 3;
    tiles = ystride >> 2;
    while (dec->unk_7AC < dec->unk_40A) {
        dec->unk_7AA = 0;
        fn_8003AB08(dec);
        dec->unk_7AC += dec->unk_7A8;
        y = dec->comp[0].dest;
        u = dec->comp[1].dest;
        v = dec->comp[2].dest;
        if (hsub == 0) {
            for (row = 0; row < (dec->unk_7A8 >> 2); row++) {
                for (tile = 0; tile < tiles; tile++) {
                    yy = y;
                    uu = u;
                    vv = v;
                    for (k = 0; k < 4; k++) {
                        fn_8003BD78(out, yy, uu, vv, &alpha);
                        yy += ystride;
                        uu += cstride;
                        vv += cstride;
                        out += 8;
                    }
                    out += 0x20;
                    y += 4;
                    u += 4;
                    v += 4;
                }
                y += ystride3;
                u += cstride3;
                v += cstride3;
            }
        } else if (vsub == 0) {
            for (row = 0; row < (dec->unk_7A8 >> 2); row++) {
                for (tile = 0; tile < tiles; tile++) {
                    yy = y;
                    uu = u;
                    vv = v;
                    for (k = 0; k < 4; k++) {
                        fn_8003BCE4(out, yy, uu, vv, &alpha);
                        yy += ystride;
                        uu += cstride;
                        vv += cstride;
                        out += 8;
                    }
                    out += 0x20;
                    y += 4;
                    u += 2;
                    v += 2;
                }
                y += ystride3;
                u += cstride3;
                v += cstride3;
            }
        } else {
            for (row = 0; row < (dec->unk_7A8 >> 2); row++) {
                for (tile = 0; tile < tiles; tile++) {
                    yy = y;
                    uu = u;
                    vv = v;
                    for (k = 0; k < 2; k++) {
                        fn_8003BCE4(out, yy, uu, vv, &alpha);
                        yy += ystride;
                        out += 8;
                        fn_8003BCE4(out, yy, uu, vv, &alpha);
                        yy += ystride;
                        uu += cstride;
                        vv += cstride;
                        out += 8;
                    }
                    out += 0x20;
                    y += 4;
                    u += 2;
                    v += 2;
                }
                y += ystride3;
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
    lbl_801789C0[2].t0_start = fn_8000A050();
    lbl_801789C0[2].t1_start = fn_8000A040();
    lbl_801789C0[2].t2_start = fn_8000A030();
    lbl_801789C0[2].t3_start = fn_8000A020();
    PPCMtmmcr0(0x8B);
    PPCMtmmcr1(0x78400000);
    DCStoreRange(dst, GXGetTexBufferSize(dec->unk_408, dec->unk_40A, 6, 0, 0));
    PPCMtmmcr1(0);
    PPCMtmmcr0(0);
    lbl_801789C0[2].count++;
    lbl_801789C0[2].t0_end = fn_8000A050();
    lbl_801789C0[2].t1_end = fn_8000A040();
    lbl_801789C0[2].t2_end = fn_8000A030();
    lbl_801789C0[2].t3_end = fn_8000A020();
    {
        u32 d = lbl_801789C0[2].t0_end - lbl_801789C0[2].t0_start;
        u32 max = lbl_801789C0[2].t0_max;
        if (d > max) {
            max = d;
        }
        lbl_801789C0[2].t0_max = max;
    }
    lbl_801789C0[2].t0_total += lbl_801789C0[2].t0_end - lbl_801789C0[2].t0_start;
    lbl_801789C0[2].t1_total += lbl_801789C0[2].t1_end - lbl_801789C0[2].t1_start;
    lbl_801789C0[2].t2_total += lbl_801789C0[2].t2_end - lbl_801789C0[2].t2_start;
    lbl_801789C0[2].t3_total += lbl_801789C0[2].t3_end - lbl_801789C0[2].t3_start;
    PPCMtmmcr0(0x8B);
    PPCMtmmcr1(0x78400000);
    gqr_put2(dec->gqr2);
    gqr_put5(dec->gqr5);
    gqr_put6(dec->gqr6);
    gqr_put7(dec->gqr7);
}
