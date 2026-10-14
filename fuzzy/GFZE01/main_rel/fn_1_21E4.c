/* Non-matching: best partial attempt (65.91% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u8 lbl_1_rodata_70[];
extern u8 lbl_1_bss_978[];
extern u8 lbl_1_data_2A40[];

extern s32 fn_1_3EFA8(void);
extern u8 fn_1_3BB0(u32);
extern u32 fn_1_1DF0(void *, void *, u32);
extern u32 fn_1_1FE8(void *, void *, u32, u32);
extern void fn_80008BEC(void *, int, u32);
extern f64 __fabs(f64);

void fn_1_21E4(u8 *arg0) {
    u8 *p_rodata = lbl_1_rodata_70;
    u8 *p_bss = lbl_1_bss_978;
    u8 *p_data = lbl_1_data_2A40;
    u8 *p29;
    u8 *p27;
    u8 *p30;
    u8 *p28;
    u8 *p17;
    u8 *p24;
    u8 *p18;
    u8 *p25;
    u8 *p19;
    u8 *p26;
    u8 *p21;
    u8 *p23;
    u32 i;

    if (fn_1_3EFA8() != 0) {
        return;
    }

    p29 = arg0;
    p27 = p_bss + 0x50;
    p30 = p_bss + 0x80;
    p28 = p_bss + 0x110;
    p17 = p_data + 0x138;
    p24 = p_data + 0x110;
    p18 = p_data + 0x118;
    p25 = p_data + 0x80;
    p19 = p_data + 0x100;
    p26 = p_data + 0xc0;
    p21 = p_data + 0x108;
    p23 = p_bss + 0x128;

    for (i = 0; i < 4; i++) {
        if ((s8)p27[10] == -1) {
            fn_80008BEC(p28, 0, 6);
            fn_80008BEC(p29, 0, 8);
        } else {
            s32 v = p27[6] - 16;
            if (v < 0) {
                v = 0;
            } else if (v > 184) {
                v = 184;
            }
            p29[4] = (s32)((f32)v * 0.54347825050354f);

            v = p27[7] - 16;
            if (v < 0) {
                v = 0;
            } else if (v > 184) {
                v = 184;
            }
            p29[5] = (s32)((f32)v * 0.54347825050354f);

            if (p17[0] == 2 || p17[0] == 3) {
                s8 val = (s8)p27[2];
                if (val == 0) {
                    p29[0] = 0;
                    p29[1] = 0;
                    p29[2] = 0;
                    p29[3] = 0;
                } else {
                    s32 r3_val;
                    s32 r4_val;
                    s32 is_neg;

                    if (val < 0) {
                        r3_val = (s32)val;
                        if (r3_val < -p24[1]) {
                            r3_val = -p24[1];
                        }
                        if (r3_val > 0) {
                            r3_val = 0;
                        }
                        if (r3_val >= -p18[1]) {
                            p29[0] = 0;
                            p29[1] = 0;
                            p29[2] = 0;
                            p29[3] = 0;
                            goto skip_to_mode;
                        }
                        r3_val = -r3_val - p18[1];
                        r4_val = p24[1] - p18[1];
                        is_neg = 1;
                    } else {
                        r3_val = (s32)val;
                        if (r3_val < 0) {
                            r3_val = 0;
                        }
                        if (r3_val > p24[0]) {
                            r3_val = p24[0];
                        }
                        if (r3_val <= p18[0]) {
                            p29[0] = 0;
                            p29[1] = 0;
                            p29[2] = 0;
                            p29[3] = 0;
                            goto skip_to_mode;
                        }
                        r3_val = r3_val - p18[0];
                        r4_val = p24[0] - p18[0];
                        is_neg = 0;
                    }

                    {
                        s32 res = (s32)((f32)r3_val * 100.0f / (f32)(u32)r4_val);
                        if (is_neg) {
                            res = -res;
                        }
                        p29[0] = (s8)res;
                        p29[1] = 0;
                        p29[2] = 0;
                        p29[3] = 0;
                    }
                }
            } else {
                s32 j;
                p29[0] = p27[2];
                p29[1] = p27[3];
                p29[2] = p27[4];
                p29[3] = p27[5];

                for (j = 0; j < 8; j++) {
                    s32 next = (j == 7) ? 0 : (j + 1);
                    f32 x0 = (f32)(s8)p25[j * 2 + 0];
                    f32 y0 = (f32)(s8)p25[j * 2 + 1];
                    f32 x1 = (f32)(s8)p25[next * 2 + 0];
                    f32 y1 = (f32)(s8)p25[next * 2 + 1];
                    f32 det = x0 * y1 - x1 * y0;
                    if (__fabs(det) >= 1.1920928955078125e-07) {
                        f32 inv_det = 1.0f / det;
                        f32 tx = (f32)(s8)p29[0];
                        f32 ty = (f32)(s8)p29[1];
                        f32 u = inv_det * (tx * y1 - ty * x1);
                        f32 v = inv_det * (-y0 * ty + x0 * tx);
                        if (u >= 0.0f && v >= 0.0f) {
                            f32 t0_x = (f32)(s8)p_rodata[j * 2 + 0];
                            f32 t1_x = (f32)(s8)p_rodata[next * 2 + 0];
                            s32 ix = (s32)(u * t0_x + v * t1_x);
                            s32 abs_ix = (ix < 0) ? -ix : ix;
                            s32 scale_x = ((abs_ix - p19[0]) * 100) / (100 - p19[0]);
                            f32 t0_y;
                            f32 t1_y;
                            s32 iy;
                            s32 abs_iy;
                            s32 scale_y;

                            if (scale_x < 0) scale_x = 0;
                            else if (scale_x > 100) scale_x = 100;
                            if (ix < 0) scale_x = -scale_x;
                            p29[0] = scale_x;

                            t0_y = (f32)(s8)p_rodata[j * 2 + 1];
                            t1_y = (f32)(s8)p_rodata[next * 2 + 1];
                            iy = (s32)(u * t0_y + v * t1_y);
                            abs_iy = (iy < 0) ? -iy : iy;
                            scale_y = ((abs_iy - p19[1]) * 100) / (100 - p19[1]);
                            if (scale_y < 0) scale_y = 0;
                            else if (scale_y > 100) scale_y = 100;
                            if (iy < 0) scale_y = -scale_y;
                            p29[1] = scale_y;
                            break;
                        }
                    }
                }

                for (j = 0; j < 8; j++) {
                    s32 next = (j == 7) ? 0 : (j + 1);
                    f32 x0 = (f32)(s8)p26[j * 2 + 0];
                    f32 y0 = (f32)(s8)p26[j * 2 + 1];
                    f32 x1 = (f32)(s8)p26[next * 2 + 0];
                    f32 y1 = (f32)(s8)p26[next * 2 + 1];
                    f32 det = x0 * y1 - x1 * y0;
                    if (__fabs(det) >= 1.1920928955078125e-07) {
                        f32 inv_det = 1.0f / det;
                        f32 tx = (f32)(s8)p29[2];
                        f32 ty = (f32)(s8)p29[3];
                        f32 u = inv_det * (tx * y1 - ty * x1);
                        f32 v = inv_det * (-y0 * ty + x0 * tx);
                        if (u >= 0.0f && v >= 0.0f) {
                            f32 t0_x = (f32)(s8)p_rodata[j * 2 + 0];
                            f32 t1_x = (f32)(s8)p_rodata[next * 2 + 0];
                            s32 ix = (s32)(u * t0_x + v * t1_x);
                            s32 abs_ix = (ix < 0) ? -ix : ix;
                            s32 scale_x = ((abs_ix - p21[0]) * 100) / (100 - p21[0]);
                            f32 t0_y;
                            f32 t1_y;
                            s32 iy;
                            s32 abs_iy;
                            s32 scale_y;

                            if (scale_x < 0) scale_x = 0;
                            else if (scale_x > 100) scale_x = 100;
                            if (ix < 0) scale_x = -scale_x;
                            p29[2] = scale_x;

                            t0_y = (f32)(s8)p_rodata[j * 2 + 1];
                            t1_y = (f32)(s8)p_rodata[next * 2 + 1];
                            iy = (s32)(u * t0_y + v * t1_y);
                            abs_iy = (iy < 0) ? -iy : iy;
                            scale_y = ((abs_iy - p21[1]) * 100) / (100 - p21[1]);
                            if (scale_y < 0) scale_y = 0;
                            else if (scale_y > 100) scale_y = 100;
                            if (iy < 0) scale_y = -scale_y;
                            p29[3] = scale_y;
                            break;
                        }
                    }
                }
            }

skip_to_mode:
            p29[6] = p27[8];
            p29[7] = p27[9];
            {
                u8 mode = fn_1_3BB0(i);
                u8 *r20;
                u32 m10;
                u32 m14;
                u32 m18;
                u16 w6;
                s32 count;
                u16 w2;
                s32 flag;

                switch (mode) {
                    case 2:
                        r20 = p23 + 0x1C;
                        break;
                    case 3:
                        r20 = p23 + 0x38;
                        break;
                    case 4:
                        r20 = p_rodata + 0x10;
                        break;
                    default:
                        r20 = p23;
                        break;
                }

                p28[4] = fn_1_1DF0(p30, p29, *(u32 *)(r20 + 8));
                p28[5] = fn_1_1DF0(p30, p29, *(u32 *)(r20 + 12));
                p28[1] = fn_1_1FE8(p30, p29, *(u16 *)(r20 + 0), p28[1]);
                p28[3] = fn_1_1FE8(p30, p29, *(u16 *)(r20 + 2), p28[3]);
                p28[2] = fn_1_1FE8(p30, p29, *(u16 *)(r20 + 4), p28[2]);
                p28[0] = 0;

                m10 = *(u32 *)(r20 + 0x10);
                if ((s32)m10 >= 0) {
                    if ((*(u16 *)(p30 + 0) & m10 & 0x0F7F) != 0) {
                        p28[0] |= 0x80;
                    } else if ((m10 & 0x00FFF000) != 0 && (*(u16 *)(p30 + 2) & ((m10 & 0x00FFF000) >> 12)) != 0) {
                        p28[0] |= 0x80;
                    }
                }

                m14 = *(u32 *)(r20 + 0x14);
                if ((s32)m14 >= 0) {
                    if ((*(u16 *)(p30 + 0) & m14 & 0x0F7F) != 0) {
                        p28[0] |= 0x20;
                    } else if ((m14 & 0x00FFF000) != 0 && (*(u16 *)(p30 + 2) & ((m14 & 0x00FFF000) >> 12)) != 0) {
                        p28[0] |= 0x20;
                    }
                }

                m18 = *(u32 *)(r20 + 0x18);
                if ((s32)m18 >= 0) {
                    if ((*(u16 *)(p30 + 0) & m18 & 0x0F7F) != 0) {
                        p28[0] |= 0x40;
                    } else if ((m18 & 0x00FFF000) != 0 && (*(u16 *)(p30 + 2) & ((m18 & 0x00FFF000) >> 12)) != 0) {
                        p28[0] |= 0x40;
                    }
                }

                w6 = *(u16 *)(r20 + 6);
                count = 0;
                if ((s16)w6 >= 0) {
                    u32 bits = w6;
                    while (bits != 0) {
                        int lz = __cntlzw(bits);
                        int bit_idx = 31 - lz;
                        u8 *entry = p_rodata + 0x5C + bit_idx * 3;
                        u16 val = (entry[0] == 0) ? *(u16 *)(p30 + 2) : *(u16 *)(p30 + 0);
                        if ((val & (1 << entry[1])) != 0) {
                            count--;
                        }
                        if ((val & (1 << entry[2])) != 0) {
                            count++;
                        }
                        bits &= ~(0x80000000 >> lz);
                    }
                    if (count < 0) {
                        count = -1;
                    } else if (count > 0) {
                        count = 1;
                    }
                }
                if (count > 0) {
                    p28[0] |= 0x01;
                }
                if (count < 0) {
                    p28[0] |= 0x02;
                }

                w2 = *(u16 *)(r20 + 2);
                flag = 0;
                if ((s16)w2 >= 0) {
                    u32 bits4 = w2 & 0x0F;
                    if (bits4 != 0) {
                        u16 p30_0 = *(u16 *)(p30 + 0);
                        while (bits4 != 0) {
                            int lz = __cntlzw(bits4);
                            int bit_idx = 31 - lz;
                            u8 *entry = p_rodata + 0x54 + bit_idx * 2;
                            if (((p30_0 >> entry[0]) & 1) && ((p30_0 >> entry[1]) & 1)) {
                                flag = 1;
                                break;
                            }
                            bits4 &= ~(0x80000000 >> lz);
                        }
                    }
                    if (!flag) {
                        u32 mid = w2 & 0x03F0;
                        if (mid != 0 && (mid & 0x00F0) == 0) {
                            if (mid & 0x0100) {
                                if ((double)p29[5] > 0.1 && (double)p29[4] > 0.1) {
                                    flag = 1;
                                }
                            } else if (mid & 0x0200) {
                                if ((double)p29[6] > 0.1 && (double)p29[7] > 0.1) {
                                    flag = 1;
                                }
                            }
                        }
                    }
                }
                if (flag) {
                    p28[0] |= 0x10;
                }
            }
        }

        p24 += 2;
        p18 += 2;
        p25 += 16;
        p19 += 2;
        p26 += 16;
        p21 += 2;
        p23 += 0x54;
        p27 += 12;
        p30 += 20;
        p28 += 6;
        p29 += 8;
        p17 += 1;
    }
}
