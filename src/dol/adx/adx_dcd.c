#include "types.h"

/* --- dol/fn_80046768.c --- */
/* --- dol/fn_80046718.c --- */
/* --- dol/fn_80046718.c --- */
extern u32 fn_80059AB4(void);

void fn_80046718(void);

/* --- dol/fn_80046738.c --- */
extern u32 fn_80059B44(void);

void fn_80046738(void);

/* --- dol/fn_80046758.c --- */
extern u32 lbl_8017B020[];

void fn_80046758(void);

/* --- dol/fn_80046768.c --- */
extern char lbl_80090930[];
extern u32 strlen(char *);

u32 fn_80046768(s32 flag, u32 subtrahend, u32 value, u32 divisor) {
    if (flag == 0) {
        return (0x1b + subtrahend + strlen(lbl_80090930) + value + divisor) / divisor * divisor -
               value;
    }
    return (0x33 + subtrahend + strlen(lbl_80090930) + value + divisor) / divisor * divisor - value;
}

/* --- dol/fn_80046804.c --- */
struct fn_80046804_Arg2 {
    u16 unk_0;
};


s32 fn_80046804(u32 arg0, u32 arg1, struct fn_80046804_Arg2 *arg2) {
    u32 v0;
    s16 v1;
    v0 = arg0;
    if ((s32)arg1 < 16) {
    v0 = -1;
    return v0;
    }
    if (*(u16 *)(v0) != 32769) {
    v0 = -2;
    return v0;
    }
    v1 = *(s16 *)(v0 + 2);
    v0 = 0;
    arg2->unk_0 = (v1 + 4);
    return v0;
}

/* --- dol/fn_8004683C.c --- */
typedef union AdxHeaderMagic {
    u16 value;
    struct {
        u8 high;
        u8 low;
    } bytes;
} AdxHeaderMagic;

typedef union AdxHeaderOffset {
    s16 value;
} AdxHeaderOffset;

typedef struct AdxHeader {
    AdxHeaderMagic magic;
    AdxHeaderOffset copyright_offset;
    u8 encoding;
    u8 block_size;
    u8 bits_per_sample;
    u8 channel_count;
    u8 sample_rate_0;
    u8 sample_rate_1;
    u8 sample_rate_2;
    u8 sample_rate_3;
    u8 total_samples_0;
    u8 total_samples_1;
    u8 total_samples_2;
    u8 total_samples_3;
    u16 highpass_frequency;
    u8 version;
    u8 flags;
    u8 reserved[2];
} AdxHeader;

extern void *memcpy(void *destination, const void *source, u32 size);

static inline int decode_info_header(AdxHeader *header, int buffer_len, u32 *version) {
    int result = 0;
    if (buffer_len < 0x14) {
        result = -1;
    } else if (header->magic.value != 0x8000) {
        result = -2;
    } else if (header->copyright_offset.value < 0x10) {
        result = -1;
    } else {
        *version = header->version;
    }
    return result;
}

int fn_8004683C(u8 *buffer, int buffer_len, int *ainf_len, u8 ainf[16],
                s16 *default_out_volume, s16 default_pan[2]) {
    u32 version;
    int result;
    int required_len;
    int ainf_offset;
    u32 tag;
    u8 *base;

    base = buffer;
    *ainf_len = 0;
    result = decode_info_header((AdxHeader *)base, buffer_len, &version);
    if (result != 0) {
        return result;
    }
    required_len = version == 4 ? 0x48 : 0x3C;
    if (buffer_len < required_len) {
        return -1;
    }
    if (*(u16 *)base != 0x8000) {
        return -2;
    }
    if (*(s16 *)(base + 2) < required_len - 4) {
        return -1;
    }
    ainf_offset = version == 4 ? 0x20 : 0x14;
    {
        u8 *q = (u8 *)(ainf_offset + (u32)base);
        tag = (((q)[4]) << 24) | (((q)[5]) << 16) | (((q)[6]) << 8) | ((q)[7]);
    }
    if (tag != 0x41494E46) {
        return -2;
    }
    *ainf_len = *(u32 *)((((8) + (ainf_offset)) + (base)));
    memcpy(ainf, ((base) + ((ainf_offset) + (0xc))), 16);
    *default_out_volume = *(s16 *)(base + (ainf_offset + 0x1c));
    default_pan[0] = *(s16 *)(base + (ainf_offset + 0x20));
    default_pan[1] = *(s16 *)(base + (ainf_offset + 0x22));
    return 0;
}

/* --- dol/ADX_DecodeInfoExLoop.c --- */
/* --- dol/ADX_DecodeInfoExLoop.c --- */
/* --- dol/ADX_DecodeInfoExLoop.c --- */




int ADX_DecodeInfoExLoop(signed char *buffer, int buffer_len, int *inserted_samples, short *num_loops,
                short *loop_type, int *start_sample, int *start_offset, int *end_sample,
                int *end_offset) {
    u32 version;
    int result;
    int required_len;
    int loop_offset;
    *num_loops = 0;
    result = decode_info_header((AdxHeader *)buffer, buffer_len, &version);
    if (result != 0) {
        return result;
    }
    required_len = version == 4 ? 0x3C : 0x30;
    if (buffer_len < required_len) {
        return -1;
    }
    if (*(const unsigned short *)buffer != 0x8000) {
        return -2;
    }
    if (*(const short *)(buffer + 2) < required_len - 4) {
        return -1;
    }
    loop_offset = 0x14;
    if (version == 4) {
        loop_offset = 0x20;
    }
    *inserted_samples = *(const short *)(buffer + loop_offset);
    loop_offset += 2;
    *num_loops = *(const short *)(buffer + loop_offset);
    loop_offset += 2;
    if (*num_loops != 1) {
        return -2;
    }
    loop_offset += 2;
    *loop_type = *(const short *)(buffer + loop_offset);
    loop_offset += 2;
    *start_sample = *(const int *)(buffer + loop_offset);
    loop_offset += 4;
    *start_offset = *(const int *)(buffer + loop_offset);
    loop_offset += 4;
    *end_sample = *(const int *)(buffer + loop_offset);
    loop_offset += 4;
    *end_offset = *(const int *)(buffer + loop_offset);
    return 0;
}

/* --- dol/fn_80046AC0.c --- */
/* --- dol/fn_80046AC0.c --- */
/* --- dol/fn_80046AC0.c --- */
struct fn_80046AC0_Arg0 {
    u16 unk_0;
    s16 unk_2;
    u8 unk_4[0xE];
    u8 unk_12;
};

s32 fn_80046AC0(struct fn_80046AC0_Arg0 *arg0, s32 arg1, u16 *arg2, u16 *arg3) {
    u8 v1;
    s32 v0;

    if (arg1 < 20) {
        v0 = -1;
    } else {
        if (arg0->unk_0 != 32768) {
            v0 = -2;
        } else {
            if (arg0->unk_2 < 16) {
                v0 = -1;
            } else {
                v1 = arg0->unk_12;
                v0 = 0;
            }
        }
    }
    if (v0 != 0) {
        return -1;
    }
    if (v1 >= 4) {
        if (arg1 < 32) {
            return -1;
        }
        if (arg0->unk_0 != 32768) {
            return -2;
        }
        if (arg0->unk_2 < 28) {
            return -1;
        }
        arg2[0] = *(u16 *)((u8 *)arg0 + 0x18);
        arg3[0] = *(u16 *)((u8 *)arg0 + 0x1A);
        arg2[1] = *(u16 *)((u8 *)arg0 + 0x1C);
        arg3[1] = *(u16 *)((u8 *)arg0 + 0x1E);
    } else {
        arg3[1] = 0;
        arg2[1] = 0;
        arg3[0] = 0;
        arg2[0] = 0;
    }
    return 0;
}

/* --- dol/fn_80046B90.c --- */
struct fn_80046B90_Arg2 {
    u8 unk_0;
};
struct fn_80046B90_Arg3 {
    u8 unk_0;
};


s32 fn_80046B90(u32 arg0, u32 arg1, struct fn_80046B90_Arg2 *arg2, struct fn_80046B90_Arg3 *arg3) {
    u32 v0;
    u8 v1;
    v0 = arg0;
    if ((s32)arg1 < 20) {
    v0 = -1;
    return v0;
    }
    if (*(u16 *)((u8 *)v0 + 0) != 32768) {
    v0 = -2;
    return v0;
    }
    if (*(s16 *)((u8 *)v0 + 2) < 16) {
    v0 = -1;
    return v0;
    }
    arg2->unk_0 = *(u8 *)((u8 *)v0 + 18);
    v1 = *(u8 *)((u8 *)v0 + 19);
    v0 = 0;
    arg3->unk_0 = v1;
    return v0;
}

/* --- dol/fn_80046BE0.c --- */
struct fn_80046BE0_Arg2 {
    u16 unk_0;
};


s32 fn_80046BE0(u32 arg0, u32 arg1, struct fn_80046BE0_Arg2 *arg2) {
    u32 v0;
    u16 v1;
    v0 = arg0;
    if ((s32)arg1 < 18) {
    v0 = -1;
    return v0;
    }
    if (*(u16 *)((u8 *)v0 + 0) != 32768) {
    v0 = -2;
    return v0;
    }
    if (*(s16 *)((u8 *)v0 + 2) < 14) {
    v0 = -1;
    return v0;
    }
    v1 = *(u16 *)((u8 *)v0 + 16);
    v0 = 0;
    arg2->unk_0 = v1;
    return v0;
}

/* --- dol/fn_80046C28.c --- */
struct fn_80046C28_Arg1 {
    u32 unk_0;
};
struct fn_80046C28_Arg2 {
    u16 unk_0;
};
struct fn_80046C28_Arg3 {
    u8 unk_0;
};
struct fn_80046C28_Arg4 {
    s8 unk_0;
};
struct fn_80046C28_Arg5 {
    s8 unk_0;
};
struct fn_80046C28_Arg6 {
    u8 unk_0;
};
struct fn_80046C28_Arg7 {
    u32 unk_0;
};
struct fn_80046C28_Data {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 b8;
    u8 b9;
    u8 b10;
    u8 b11;
    u8 b12;
    u8 b13;
    u8 b14;
    u8 b15;
};

s32 fn_80046C28(struct fn_80046C28_Data *arg0, u32 arg1, struct fn_80046C28_Arg2 *arg2, struct fn_80046C28_Arg3 *arg3, struct fn_80046C28_Arg4 *arg4, struct fn_80046C28_Arg5 *arg5, struct fn_80046C28_Arg6 *arg6, struct fn_80046C28_Arg7 *arg7, struct fn_80046C28_Arg1 *arg8, struct fn_80046C28_Arg1 *arg9) {
    if ((s32)arg1 < 16) {
        return -1;
    }
    if ((u16)((arg0->b0 << 8) | arg0->b1) != 32768) {
        return -2;
    }
    arg2->unk_0 = ((arg0->b2 << 8) | arg0->b3) + 4;
    arg3->unk_0 = arg0->b4;
    arg5->unk_0 = arg0->b5;
    arg4->unk_0 = arg0->b6;
    arg6->unk_0 = arg0->b7;
    arg7->unk_0 = (arg0->b8 << 24) | (arg0->b9 << 16) | (arg0->b10 << 8) | arg0->b11;
    arg8->unk_0 = (arg0->b12 << 24) | (arg0->b13 << 16) | (arg0->b14 << 8) | arg0->b15;
    if (arg4->unk_0 == 0) {
        arg9->unk_0 = 0;
    } else {
        arg9->unk_0 = ((arg5->unk_0 - 2) << 3) / arg4->unk_0;
    }
    return 0;
}

/* --- dol/ADX_ScanInfoCode.c --- */
int ADX_ScanInfoCode(signed char *buffer, int buffer_len, short *data_len) {
    short code;
    int offset;
    int minimum;
    minimum = 0x7FFFFFFF;
    code = (short)0x8000;
    for (offset = 0; offset < buffer_len - 1; offset += 2) {
        if (*(short *)&buffer[offset] == code) {
            minimum = offset < minimum ? offset : minimum;
            break;
        }
    }
    if (minimum != 0x7FFFFFFF) {
        *data_len = (short)minimum;
        return 0;
    } else {
        *data_len = 0;
        return -1;
    }
}

/* --- dol/fn_80046D94.c --- */
/* ADX_GetCoefficient (adx_dcd.c, CRI ADX): IIR prediction coefficients for a cutoff. */

extern const f32 lbl_80090938;
extern const f64 lbl_80090940;
extern const f64 lbl_80090948;
extern const f64 lbl_80090950;
extern const f32 lbl_80090958;
extern const f32 lbl_8009095C;
extern const f32 lbl_80090960;
extern const f32 lbl_80090964;
extern f64 __frsqrte(f64);
extern f64 fn_80087E80(f32);

static f64 fn_80046D94_refine(f64 x) {
    f64 r;
    r = __frsqrte(x);
    r = lbl_80090948 * r * (lbl_80090950 - x * (r * r));
    r = lbl_80090948 * r * (lbl_80090950 - x * (r * r));
    r = lbl_80090948 * r * (lbl_80090950 - x * (r * r));
    return x * r;
}

void fn_80046D94(s32 arg0, s32 arg1, short *arg2, short *arg3) {
    volatile f32 sa; /* retail rounds each square root through a float stack slot */
    volatile f32 sb; /* retail rounds each square root through a float stack slot */
    volatile f32 vr; /* retail rounds each square root through a float stack slot */
    f32 v;
    f32 ang;
    f32 d;
    f32 e;
    f32 t;
    ang = (f32)fn_80087E80(lbl_80090938 * (f32)arg0 / (f32)arg1);
    sa = (f32)fn_80046D94_refine(lbl_80090940);
    d = sa - ang;
    sb = (f32)fn_80046D94_refine(lbl_80090940);
    e = sb - lbl_80090958;
    v = (d + e) * (d - e);
    if (v > lbl_8009095C) {
        vr = (f32)fn_80046D94_refine(v);
        v = vr;
    }
    t = (d - v) / e;
    *arg2 = lbl_80090960 * (lbl_80090964 * t);
    *arg3 = lbl_80090960 * (-t * t);
}

/* --- dol/fn_80046F7C.c --- */
extern u32 lbl_8017B028[3];

void fn_80046F7C(u32 value) {
    lbl_8017B028[0] = value;
}
