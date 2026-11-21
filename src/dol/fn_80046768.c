#include "types.h"


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
