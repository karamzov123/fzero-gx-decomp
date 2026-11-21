#include "types.h"


/* --- dol/fn_80045F58.c --- */
/* --- dol/fn_80045F58.c --- */
/* --- dol/fn_80045F58.c --- */
struct fn_80045F58_Arg0 {
    u8 pad_0[0x88];
    u32 unk_88;
    u32 unk_8C;
};

void fn_80045F58(struct fn_80045F58_Arg0 *arg0, u32 arg1, u32 arg2);

/* --- dol/fn_80045F74.c --- */
struct fn_80045F74_Arg0 {
    u8 pad_0[0x18];
    u32 unk_18;
    u8 pad_1C[0x20];
    u32 unk_3C;
    u32 unk_40;
    u8 pad_44[0x44];
    u32 unk_88;
    u32 unk_8C;
};
struct fn_80045F74_Arg1 {
    u32 unk_0;
};
struct fn_80045F74_Arg2 {
    u32 unk_0;
};
struct fn_80045F74_Arg3 {
    u32 unk_0;
};

u32 fn_80045F74(struct fn_80045F74_Arg0 *arg0, struct fn_80045F74_Arg1 *arg1, struct fn_80045F74_Arg2 *arg2, struct fn_80045F74_Arg3 *arg3);

/* --- dol/fn_80045FA4.c --- */
/* --- dol/fn_80045FA4.c --- */
struct fn_80045FA4_lbl_8017A288 {
    u32 unk_0;    u8 pad_4[0x10];
};

extern struct fn_80045FA4_lbl_8017A288 lbl_8017A288[];
extern u32 fn_8004E4AC(void);
extern u32 lbl_8017A29C[];
extern u32 memset(u32, u32, u32);

void fn_80045FA4(void);

/* --- dol/fn_80045FEC.c --- */
extern u32 fn_8008023C(u32, u32, u32);
extern u32 lbl_80090928[];

u32 fn_80045FEC(u32 arg0) {
    u32 t0;
    t0 = fn_8008023C(arg0, (u32)&lbl_80090928, 4);
    return ((u32)__cntlzw(t0) >> 5);
}

/* --- dol/fn_80046020.c --- */
typedef struct AdxXpndParams {
    int channel_count;
    const signed char *input;
    int num_blocks;
    short *output_left;
    short *output_right;
} AdxXpndParams;

typedef struct AdxXpnd {
    int used;
    int index;
    int mode;
    int status;
    int num_decoded_blocks;
    AdxXpndParams params;
    short delay[2][2];
    short coefficients[2];
    short random_state;
    short random_multiplier;
    short random_increment;
    short reserved;
} AdxXpnd;

typedef struct AdxDecodeParams {
    const unsigned short *input;
    int input_blocks;
    int channel_count;
    int block_size;
    int samples_per_block;
    short *pcm_buffer;
    int pcm_size;
    int pcm_distance;
    int write_position;
    int room;
    int loop_samples;
} AdxDecodeParams;

typedef void (*AdxGetWriteInfo)(void *, int *, int *, int *);

typedef void (*AdxAddWriteInfo)(void *, int, int);

typedef struct AdxBasicDecoder {
    short used;
    short header_decoded;
    int status;
    AdxXpnd *expander;
    signed char encoding;
    signed char bits_per_sample;
    signed char channel_count;
    signed char block_length;
    int samples_per_block;
    int sample_rate;
    int total_samples;
    short coefficient;
    short field_1E;
    int loop_insert_samples;
    short loop_count;
    short loop_type;
    int loop_start_sample;
    int loop_start_offset;
    int loop_end_sample;
    int loop_end_offset;
    int max_channels;
    short *pcm_buffer;
    int pcm_size;
    int pcm_distance;
    AdxDecodeParams decode;
    short field_74;
    short field_76;
    AdxGetWriteInfo get_write_info;
    void *get_write_object;
    AdxAddWriteInfo add_write_info;
    void *add_write_object;
    int total_decoded_samples;
    int current_write_position;
    int decoded_samples;
    int decoded_data_length;
    short format_type;
    short field_9A;
    short codec_type;
} AdxBasicDecoder;

void fn_80046020(AdxBasicDecoder *decoder);

int fn_8004E270(AdxXpnd *decoder);

void fn_80046020(AdxBasicDecoder *decoder) {
    AdxDecodeParams *params = &decoder->decode;
    const unsigned short *input = params->input;
    if (decoder->status == 1 && fn_8004E270(decoder->expander) == 0) {
        short *pcm;
        short *left;
        short *right;
        int i;
        int count;
        decoder->get_write_info(decoder->get_write_object, &params->write_position, &params->room,
                                &params->loop_samples);
        count = params->pcm_size - params->write_position;
        if (count > params->room)
            count = params->room;
        if (count > params->input_blocks)
            count = params->input_blocks;
        pcm = params->pcm_buffer;
        left = &pcm[params->write_position];
        if (decoder->channel_count == 2) {
            right = &pcm[params->pcm_distance + params->write_position];
            for (i = 0; i < count; i++) {
                left[i] = input[i * 2];
                right[i] = input[i * 2 + 1];
            }
        } else {
            for (i = 0; i < count; i++)
                left[i] = input[i];
        }
        decoder->decoded_samples = count;
        decoder->decoded_data_length = decoder->channel_count * (count << 1);
        decoder->status = 2;
    }
    if (decoder->status == 2) {
        decoder->add_write_info(decoder->add_write_object, decoder->decoded_data_length,
                                decoder->decoded_samples);
        decoder->status = 3;
    }
}

/* --- dol/fn_800462F8.c --- */
struct fn_800462F8_Arg0 {
    u8 pad_0[0x2];
    u16 unk_2;
    u8 pad_4[0x8];
    u8 unk_c;
    s8 unk_d;
    s8 unk_e;
    s8 unk_f;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u16 unk_1c;
    u8 pad_1e[0x2];
    u32 unk_20;
    u16 unk_24;
    u16 unk_26;
    u32 unk_28;
    u32 unk_2c;
    u32 unk_30;
    u32 unk_34;
    u8 pad_38[0x4];
    u32 unk_3c;
    u32 unk_40;
    u32 unk_44;
    u8 pad_48[0x8];
    s32 unk_50;
    s32 unk_54;
    u32 unk_58;
    u32 unk_5c;
    u32 unk_60;
    u32 unk_64;
    u8 pad_68[0x20];
    u32 unk_88;
    u32 unk_8c;
    u8 pad_90[0x8];
    u16 unk_98;
    u16 unk_9a;
};

extern s32 fn_800463E4(u32, u32, s16 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u32 *);

s32 fn_800462F8(struct fn_800462F8_Arg0 *arg0, u32 arg1, u32 arg2) {
    s16 local;
    s32 result;

    arg0->unk_2 = 1;
    result = fn_800463E4(arg1, arg2, &local,
                         &arg0->unk_c, (u8 *)&arg0->unk_d, (u8 *)&arg0->unk_f,
                         (u8 *)&arg0->unk_e, (u8 *)&arg0->unk_14, (u8 *)&arg0->unk_18,
                         (u8 *)&arg0->unk_10, (u32 *)&arg0->unk_9a);
    if (result < 0) {
        return 0;
    }
    arg0->unk_1c = 0;
    arg0->unk_26 = 0;
    arg0->unk_24 = 0;
    arg0->unk_34 = 0;
    arg0->unk_30 = 0;
    arg0->unk_2c = 0;
    arg0->unk_28 = 0;
    arg0->unk_20 = 0;
    arg0->unk_50 = arg0->unk_e;
    arg0->unk_54 = arg0->unk_f;
    arg0->unk_58 = arg0->unk_10;
    arg0->unk_5c = arg0->unk_3c;
    arg0->unk_60 = arg0->unk_40;
    arg0->unk_64 = arg0->unk_44;
    arg0->unk_8c = 0;
    arg0->unk_88 = 0;
    arg0->unk_98 = 2;
    return local;
}
