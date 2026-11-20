#include "types.h"


/* --- dol/fn_800421CC.c --- */
extern u32 fn_80045D3C(u32);
extern u32 memset(u32, u32, u32);
extern void fn_80046718(void);
extern void fn_80046738(void);

void fn_800421CC(u32 arg0) {
    u32 v0;
    u32 t0, t2;
    v0 = arg0;
    if (arg0 != 0) {
    v0 = *(u32 *)((u8 *)arg0 + 4);
    if (v0 != 0) {
    *(u32 *)((u8 *)arg0 + 4) = 0;
    t0 = fn_80045D3C(v0);
    v0 = t0;
    }
    fn_80046738();
    v0 = arg0;
    t2 = memset(v0, 0, 156);
    v0 = t2;
    fn_80046718();
    }
}

/* --- dol/fn_80042228.c --- */
typedef struct AdxXpndParams {
    union {
        unsigned char padding_extent[20];
        struct {
            int channel_count;
        } view_channel_count;
        struct {
            unsigned char padding_input[4];
            const signed char *input;
        } view_input;
    } fields;
} AdxXpndParams;

typedef struct AdxXpnd {
    union {
        unsigned char padding_extent[60];
        struct {
            int used;
        } view_used;
        struct {
            unsigned char padding_status[12];
            int status;
        } view_status;
    } fields;
} AdxXpnd;

typedef struct AdxDecodeParams {
    union {
        unsigned char padding_extent[44];
        struct {
            const unsigned short *input;
        } view_input;
        struct {
            unsigned char padding_channel_count[8];
            int channel_count;
        } view_channel_count;
    } fields;
} AdxDecodeParams;

typedef void (*AdxGetWriteInfo)(void *, int *, int *, int *);

typedef void (*AdxAddWriteInfo)(void *, int, int);

typedef struct AdxBasicDecoder {
    union {
        unsigned char padding_extent[160];
        struct {
            short used;
        } view_used;
        struct {
            unsigned char padding_status[4];
            int status;
        } view_status;
        struct {
            unsigned char padding_channel_count[14];
            signed char channel_count;
        } view_channel_count;
        struct {
            unsigned char padding_decoded_samples[144];
            int decoded_samples;
        } view_decoded_samples;
        struct {
            unsigned char padding_decoded_data_length[148];
            int decoded_data_length;
        } view_decoded_data_length;
    } fields;
} AdxBasicDecoder;

typedef struct SJCK {
    unsigned char *data;
    int len;
} SJCK;

typedef struct SJ SJ;

typedef struct SJInterface SJInterface;

typedef void (*SJErrorCallback)(void *object, int error);

struct SJInterface {
    void *reserved[3];
    void (*destroy)(SJ *sj);
    const void *(*get_uuid)(SJ *sj);
    void (*reset)(SJ *sj);
    void (*get_chunk)(SJ *sj, int channel, int max_size, SJCK *chunk);
    void (*unget_chunk)(SJ *sj, int channel, SJCK *chunk);
    void (*put_chunk)(SJ *sj, int channel, SJCK *chunk);
    int (*get_num_data)(SJ *sj, int channel);
    int (*is_get_chunk)(SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(SJ *sj, SJErrorCallback callback, void *object);
};

struct SJ {
    const SJInterface *interface;
};

enum {
    ADXSJD_MAX_HANDLES = 16,
    ADXSJD_MAX_CHANNELS = 2,
    ADXSJD_MAX_HEADER_SIZE = 0xC800,
    ADXSJD_MAX_OUTPUT_CHUNK = 0x4000
};

typedef struct AhxDecoder AhxDecoder;

typedef struct AdxBasicDecoderExt {
    AdxBasicDecoder base;
    s16 default_key[3];
    s16 snapshot_key[3];
    s16 delay_left[2];
    s16 delay_right[2];
    AhxDecoder *ahx_decoder;
    s32 ahx_max_decoded_samples;
    s32 ahx_max_decoded_blocks;
    s32 ainf_length;
    u8 ainf[16];
    s16 default_out_volume;
    s16 default_pan[2];
    u8 reserved_DA[2];
    void *pl2_context;
    u8 reserved_E0[8];
    s32 last_notified_data_length;
    s32 field_EC;
    void (*notify)(void *, s32, s32);
    void *notify_object;
} AdxBasicDecoderExt;

typedef void (*AdxSjdTrapCallback)(void *object);

typedef void (*AdxSjdOutputCallback)(void *object, s32 channel, u8 *data, s32 length);

typedef struct AdxSjdHandle {
    union {
        unsigned char padding_extent[156];
        struct {
            s8 used;
        } view_used;
        struct {
            unsigned char padding_status[1];
            s8 status;
        } view_status;
        struct {
            unsigned char padding_channel_count[2];
            s8 channel_count;
        } view_channel_count;
        struct {
            unsigned char padding_wait_for_input[3];
            s8 wait_for_input;
        } view_wait_for_input;
        struct {
            unsigned char padding_decoder[4];
            AdxBasicDecoderExt *decoder;
        } view_decoder;
        struct {
            unsigned char padding_input[8];
            SJ *input;
        } view_input;
        struct {
            unsigned char padding_output[12];
            SJ *output[ADXSJD_MAX_CHANNELS];
        } view_output;
        struct {
            unsigned char padding_decoded_samples[44];
            s32 decoded_samples;
        } view_decoded_samples;
        struct {
            unsigned char padding_decoded_data_length[48];
            s32 decoded_data_length;
        } view_decoded_data_length;
        struct {
            unsigned char padding_decode_position[52];
            s32 decode_position;
        } view_decode_position;
        struct {
            unsigned char padding_max_decode_samples[56];
            s32 max_decode_samples;
        } view_max_decode_samples;
        struct {
            unsigned char padding_trap_num_samples[60];
            s32 trap_num_samples;
        } view_trap_num_samples;
        struct {
            unsigned char padding_trap_count[64];
            s32 trap_count;
        } view_trap_count;
        struct {
            unsigned char padding_trap_data_length[68];
            s32 trap_data_length;
        } view_trap_data_length;
        struct {
            unsigned char padding_trap_callback[80];
            AdxSjdTrapCallback trap_callback;
        } view_trap_callback;
        struct {
            unsigned char padding_trap_object[84];
            void *trap_object;
        } view_trap_object;
        struct {
            unsigned char padding_output_callback[80];
            AdxSjdOutputCallback output_callback;
        } view_output_callback;
        struct {
            unsigned char padding_output_object[84];
            void *output_object;
        } view_output_object;
        struct {
            unsigned char padding_header_length[152];
            s32 header_length;
        } view_header_length;
        struct {
            unsigned char padding_pending_leading_samples[72];
            s32 pending_leading_samples;
        } view_pending_leading_samples;
        struct {
            unsigned char padding_pending_trailing_samples[76];
            s32 pending_trailing_samples;
        } view_pending_trailing_samples;
    } fields;
} AdxSjdHandle;

AdxSjdHandle *fn_80042228(SJ *input, s32 channel_count, SJ **output);

extern AdxBasicDecoderExt *ADXB_Create(s32 max_channels, s16 *pcm_buffer, s32 pcm_size,
                                       s32 pcm_distance);

extern void fn_800455AC(AdxBasicDecoderExt *decoder, AdxGetWriteInfo function, void *object);

extern u8 *fn_80057DB0(SJ *sj);

extern s32 fn_80057DA8(SJ *sj);

extern s32 fn_80057DA0(SJ *sj);

extern AdxSjdHandle lbl_801798C0[ADXSJD_MAX_HANDLES];

void adxsjd_get_wr(void *object, int *write_position, int *writable_samples, int *limit_samples);

AdxSjdHandle *fn_80042228(SJ *input, s32 channel_count, SJ **output) {
    u8 *pcm_buffer;
    s32 pcm_size;
    s32 index;
    SJ *first_output;
    s32 pcm_extra;
    AdxSjdHandle *handle;
    first_output = output[0];
    for (index = 0; index < ADXSJD_MAX_HANDLES; index++) {
        if (lbl_801798C0[index].fields.view_used.used == 0) {
            break;
        }
    }
    if (index == ADXSJD_MAX_HANDLES) {
        return 0;
    }
    handle = &lbl_801798C0[index];
    pcm_buffer = fn_80057DB0(first_output);
    pcm_size = fn_80057DA8(first_output) / 2;
    pcm_extra = fn_80057DA0(first_output) / 2;
    handle->fields.view_decoder.decoder =
        ADXB_Create(channel_count, (s16 *)pcm_buffer, pcm_size, pcm_size + pcm_extra);
    if (handle->fields.view_decoder.decoder == 0) {
        return 0;
    }
    fn_800455AC(handle->fields.view_decoder.decoder, adxsjd_get_wr, handle);
    handle->fields.view_input.input = input;
    handle->fields.view_channel_count.channel_count = channel_count;
    for (index = 0; index < channel_count; index++) {
        handle->fields.view_output.output[index] = output[index];
    }
    handle->fields.view_status.status = 0;
    handle->fields.view_header_length.header_length = 0;
    handle->fields.view_decoded_samples.decoded_samples = 0;
    handle->fields.view_decoded_data_length.decoded_data_length = 0;
    handle->fields.view_decode_position.decode_position = 0;
    handle->fields.view_max_decode_samples.max_decode_samples = 0x7FFFFFFF;
    handle->fields.view_trap_num_samples.trap_num_samples = -1;
    handle->fields.view_trap_count.trap_count = 0;
    handle->fields.view_trap_data_length.trap_data_length = 0;
    handle->fields.view_wait_for_input.wait_for_input = 0;
    handle->fields.view_pending_leading_samples.pending_leading_samples = 0;
    handle->fields.view_pending_trailing_samples.pending_trailing_samples = 0;
    handle->fields.view_trap_callback.trap_callback = 0;
    handle->fields.view_trap_object.trap_object = 0;
    /* output callback already clear */
    /* output object already clear */
    handle->fields.view_used.used = 1;
    return handle;
}
