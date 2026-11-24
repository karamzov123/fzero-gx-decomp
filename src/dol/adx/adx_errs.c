#include "types.h"

/* --- dol/fn_80046F88.c --- */
/* --- dol/ADX_DecodeInfoExLoop.c --- */
/* --- dol/ADX_DecodeInfoExLoop.c --- */
typedef union AdxHeaderMagic {
    unsigned short value;
    struct {
        unsigned char high;
        unsigned char low;
    } bytes;
} AdxHeaderMagic;

typedef union AdxHeaderOffset {
    short value;
} AdxHeaderOffset;

typedef struct AdxHeader {
    AdxHeaderMagic magic;
    AdxHeaderOffset copyright_offset;
    unsigned char encoding;
    unsigned char block_size;
    unsigned char bits_per_sample;
    unsigned char channel_count;
    unsigned char sample_rate_0;
    unsigned char sample_rate_1;
    unsigned char sample_rate_2;
    unsigned char sample_rate_3;
    unsigned char total_samples_0;
    unsigned char total_samples_1;
    unsigned char total_samples_2;
    unsigned char total_samples_3;
    unsigned short highpass_frequency;
    unsigned char version;
    unsigned char flags;
    unsigned char reserved[4];
    unsigned short delay[4];
} AdxHeader;

static inline int decode_info_header(AdxHeader *header, int buffer_len, unsigned int *version) {
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

int ADX_DecodeInfoExLoop(signed char *buffer, int buffer_len, int *inserted_samples, short *num_loops,
                short *loop_type, int *start_sample, int *start_offset, int *end_sample,
                int *end_offset);

/* --- dol/fn_80046AC0.c --- */
/* --- dol/fn_80046AC0.c --- */
/* --- dol/fn_80046AC0.c --- */
struct fn_80046AC0_Arg0 {
    u16 unk_0;
    s16 unk_2;
    u8 unk_4[0xE];
    u8 unk_12;
};

s32 fn_80046AC0(struct fn_80046AC0_Arg0 *arg0, s32 arg1, u16 *arg2, u16 *arg3);

/* --- dol/fn_80046B90.c --- */
struct fn_80046B90_Arg2 {
    u8 unk_0;
};
struct fn_80046B90_Arg3 {
    u8 unk_0;
};


s32 fn_80046B90(u32 arg0, u32 arg1, struct fn_80046B90_Arg2 *arg2, struct fn_80046B90_Arg3 *arg3);

/* --- dol/fn_80046BE0.c --- */
struct fn_80046BE0_Arg2 {
    u16 unk_0;
};


s32 fn_80046BE0(u32 arg0, u32 arg1, struct fn_80046BE0_Arg2 *arg2);

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

s32 fn_80046C28(struct fn_80046C28_Data *arg0, u32 arg1, struct fn_80046C28_Arg2 *arg2, struct fn_80046C28_Arg3 *arg3, struct fn_80046C28_Arg4 *arg4, struct fn_80046C28_Arg5 *arg5, struct fn_80046C28_Arg6 *arg6, struct fn_80046C28_Arg7 *arg7, struct fn_80046C28_Arg1 *arg8, struct fn_80046C28_Arg1 *arg9);

/* --- dol/ADX_ScanInfoCode.c --- */
int ADX_ScanInfoCode(signed char *buffer, int buffer_len, short *data_len);

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

void fn_80046D94(s32 arg0, s32 arg1, short *arg2, short *arg3);

/* --- dol/fn_80046F7C.c --- */
extern u32 lbl_8017B028[3];

void fn_80046F7C(u32 value);

/* --- dol/fn_80046F88.c --- */
/* ADXERR_ItoA2, from the CC0 MK Deception decomp (adx_errs.c) */

extern unsigned long strlen(const char *string);
extern char *fn_80083CF4(char *destination, const char *source, unsigned long size);
extern signed char lbl_8017B038[32];

static inline void adxerr_itoa(int value, signed char* string, int length)
{
    int i;
    int n;
    int l;

    for (i = 0; i < 32; i++) {
        string[i] = value % 10;
        value /= 10;
        if (value == 0) {
            string[i] = '\0';
            break;
        }
    }

    l = strlen((const char*)lbl_8017B038);
    n = length - 1;
    if (l < n) {
        n = l;
    }
    for (i = 0; i < n; i++) {
        string[i] = lbl_8017B038[n - 1 - i];
    }
    string[i] = '\0';
}

void fn_80046F88(int value1, int value2, signed char* string, int length)
{
    adxerr_itoa(value1, string, length);
    fn_80083CF4((char*)string, " ", length - strlen((const char*)string) - 1);
    adxerr_itoa(value2, string + strlen((const char*)string),
                4 - strlen((const char*)string));
}

/* --- dol/adx/adx_errs.c --- */
typedef void (*AdxErrCallback)(u32, void *);

struct AdxErrState {
    u32 unk_0;
    u32 unk_4;
    u8 unk_8[32];
    u8 unk_28[256];
};

extern struct AdxErrState lbl_8017B030[];
extern u32 lbl_8017B034[];
extern u32 SVM_CallErr(u32, ...);
extern void strncpy(void *, void *, int);
extern u32 fn_80058EF4(u32, u32);
extern u32 memset(u32, u32, u32);

void fn_80047464(u32 arg0, u32 arg1) {
    struct AdxErrState *p_lbl_8017B030;
    p_lbl_8017B030 = (struct AdxErrState *)&lbl_8017B030;
    strncpy(&p_lbl_8017B030->unk_28, (void *)arg0, 255);
    fn_80083CF4((char *)&p_lbl_8017B030->unk_28, (const char *)arg1, 255);
    if (p_lbl_8017B030->unk_0 != 0) {
        ((AdxErrCallback)p_lbl_8017B030->unk_0)(
            p_lbl_8017B030->unk_4,
            ((u8 *)p_lbl_8017B030 + 40));
    }
    SVM_CallErr((u32)((u8 *)p_lbl_8017B030 + 40));
}

void fn_800474E4(u32 arg0) {
    struct AdxErrState *p_lbl_8017B030;
    p_lbl_8017B030 = (struct AdxErrState *)&lbl_8017B030;
    strncpy(p_lbl_8017B030->unk_28, (void *)arg0, 255);
    if (p_lbl_8017B030->unk_0 != 0) {
        ((AdxErrCallback)p_lbl_8017B030->unk_0)(
            p_lbl_8017B030->unk_4,
            &p_lbl_8017B030->unk_28[0]);
    }
    SVM_CallErr((u32)((u8 *)p_lbl_8017B030 + 40));
}

void fn_80047548(u32 arg0, u32 arg1) {
    ((u32 *)&lbl_8017B030)[0] = arg0;
    lbl_8017B034[0] = arg1;
    fn_80058EF4(arg0, arg1);
}

void fn_80047578(void) {
    struct AdxErrState *p_lbl_8017B030;
    p_lbl_8017B030 = (struct AdxErrState *)&lbl_8017B030;
    memset((u32)((u8 *)p_lbl_8017B030 + 40), 0, 256);
    p_lbl_8017B030->unk_0 = 0;
    p_lbl_8017B030->unk_4 = 0;
}

void fn_800475C0(void) {
    struct AdxErrState *p_lbl_8017B030;
    p_lbl_8017B030 = (struct AdxErrState *)&lbl_8017B030;
    memset((u32)((u8 *)(u32)p_lbl_8017B030 + 40), 0, 256);
    p_lbl_8017B030->unk_0 = 0;
    p_lbl_8017B030->unk_4 = 0;
}
