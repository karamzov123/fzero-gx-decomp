/* Non-matching: best partial attempt (86.04% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct Sig_fn_8003A1CC_Fn8003A1CC_HuffTab {
    u8 *bits;
    u8 pad_4[0x8];
    u16 numVals;
    u8 pad_E[0x2];
    u8 *vals;
    u8 pad_14[0x94];
} Sig_fn_8003A1CC_Fn8003A1CC_HuffTab;
typedef struct Sig_fn_8003A1CC_Fn8003A1CC_Info {
    u8 pad_0[0x400];
    u8 *c;
    u8 pad_404[0x14];
    u8 validHuffmanTabs;
    u8 pad_419[0x7];
    Sig_fn_8003A1CC_Fn8003A1CC_HuffTab huffmanTabs[4];
} Sig_fn_8003A1CC_Fn8003A1CC_Info;
typedef struct Sig_fn_80039C40_Comp {
    u8 id;
    u8 h;
    u8 v;
    u8 tq;
    u8 pad4[4];
    s32 w8;
    s32 hC;
    u8 pad10[0x20];
} Sig_fn_80039C40_Comp;
typedef struct Sig_fn_80039C40_Dec {
    u8 pad_0[0x400];
    u8 *ptr;
    u8 pad_404[4];
    u16 width;
    u16 height;
    u8 pad_40c[0xe];
    u8 maxH;
    u8 maxV;
    u8 numComp;
    u8 pad_41d[0x2a3];
    Sig_fn_80039C40_Comp comps[4];
    u8 pad_780[0x28];
    u16 unk_7a8;
} Sig_fn_80039C40_Dec;

struct fn_8003C1A4_Arg4 {
    u16 w;
    u16 h;
    u32 unk_4;
};

typedef struct fn_8003C1A4_Dec {
    u8 pad_0[0x400];
    u8 *ptr;
    u8 *reset;
    u8 pad_408[4];
    u16 f40c;
    u16 f40e;
    u8 pad_410[4];
    u32 f414;
    u8 f418;
    u8 f419;
    u8 pad_41a[3];
    u8 f41d;
    u8 f41e;
    u8 f41f;
    u8 pad_420[0x330];
    u8 *tab[16];
    u8 pad_790[0x16];
    u16 f7a6;
    u8 pad_7a8[2];
    u16 f7aa;
    u16 f7ac;
    u16 f7ae;
    u16 f7b0;
    u8 pad_7b2[2];
    u8 *mem;
} fn_8003C1A4_Dec;

typedef struct fn_8003C1A4_Out {
    void *f0;
    void *f4;
} fn_8003C1A4_Out;

extern s32 fn_80039C40(Sig_fn_80039C40_Dec *);
extern u32 fn_80039E48(u32);
extern u32 fn_8003A3D4(u32);
extern u32 fn_8003A1CC(Sig_fn_8003A1CC_Fn8003A1CC_Info *);
extern void * memset(void *, int, u32);

s32 fn_8003C1A4(fn_8003C1A4_Out *arg0, u8 *arg1, fn_8003C1A4_Dec *arg2, void *arg3, struct fn_8003C1A4_Arg4 *arg4, u32 arg5) {
    u8 *err = arg1;
    fn_8003C1A4_Dec *dec = arg2;
    struct fn_8003C1A4_Arg4 *hdr = arg4;
    u32 v4;
    u8 *base;
    u8 t;
    u32 i;
    u8 c;
    u16 n16;
    u32 len;
    u32 r;

    v4 = 0;
    switch ((s32)hdr->unk_4) {
    case 1:
        v4 = (hdr->w & 7) | (hdr->h & 7);
        break;
    case 2:
        v4 = (hdr->w & 0xF) | (hdr->h & 7);
        break;
    case 4:
        v4 = (hdr->w & 0xF) | (hdr->h & 0xF);
        break;
    }
    if (v4 == 0 && hdr->w <= 0x400 && hdr->h <= 0x400) {
        arg0->f0 = arg3;
        arg0->f4 = dec;
        if (dec != NULL) {
            memset(dec, 0, 0x7c8);
            dec->mem = (u8 *)dec;
            dec->mem += 0x7e0;
            dec->ptr = dec->reset;
            dec->f414 = 0x21;
            dec->f7aa = 0;
            dec->f7ac = 0;
            dec->f7a6 = 0;
            dec->f41d = 0;
            dec->f40c = 0;
            dec->f40e = 0;
            dec->f418 = 0;
            dec->f419 = 0;
            base = (u8 *)((((u32)dec->mem + 0x1f) & ~0x1f));
            dec->mem = base + 0x800;
            for (t = 0; t < 16; t++) {
                dec->tab[t] = base + t * 0x80;
            }
            dec->ptr = arg0->f0;
            {
            s32 flag = 0;
            for (;;) {
                if (*dec->ptr++ != 0xff) {
                    *err = 1;
                    return 0;
                }
                while (*dec->ptr == 0xff) {
                    dec->ptr++;
                }
                c = *dec->ptr++;
                if (c <= 0xd7) {
                    if (c == 0xc4) {
                        r = fn_8003A1CC((Sig_fn_8003A1CC_Fn8003A1CC_Info *)dec);
                        if (r & 0xff) {
                            *err = r;
                            return 0;
                        }
                    } else if (c == 0xc0) {
                        r = fn_80039C40((Sig_fn_80039C40_Dec *)dec);
                        dec->f41f = hdr->unk_4;
                        if (r & 0xff) {
                            *err = r;
                            return 0;
                        }
                    } else {
                        *err = 5;
                        return 0;
                    }
                } else if (c >= 0xd8 && c <= 0xdf) {
                    if (c == 0xdd) {
                        dec->f41e = 1;
                        dec->ptr += 2;
                        dec->f7ae = (dec->ptr[0] << 8) | dec->ptr[1];
                        dec->ptr += 2;
                        dec->f7b0 = dec->f7ae;
                    } else if (c == 0xdb) {
                        r = fn_80039E48((u32)dec);
                        if (r & 0xff) {
                            *err = r;
                            return 0;
                        }
                    } else if (c == 0xda) {
                        r = fn_8003A3D4((u32)dec);
                        if (r & 0xff) {
                            *err = r;
                            return 0;
                        }
                        dec->reset = dec->ptr;
                        flag = 1;
                    } else if (c != 0xd8) {
                        *err = 5;
                        return 0;
                    }
                } else if (c >= 0xe0) {
                    if (c <= 0xef) {
                        n16 = (dec->ptr[0] << 8) | dec->ptr[1];
                        if ((s32)n16 > 0) {
                            for (i = 0; i < (u32)n16; i++) {
                                dec->ptr++;
                            }
                        }
                    } else if (c == 0xfe) {
                        len = (dec->ptr[0] << 8) | dec->ptr[1];
                        dec->ptr += 2;
                        if ((s32)(len - 2) > 0) {
                            for (i = 0; i < len - 2; i++) {
                                dec->ptr++;
                            }
                        }
                    } else {
                        *err = 5;
                        return 0;
                    }
                }
                if (flag == 0) {
                    continue;
                }
                *err = 0;
                return 1;
            }
            }
        }
        *err = 2;
        return 0;
    }
    *err = 13;
    return 0;
}
