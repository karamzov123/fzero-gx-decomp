#include "types.h"


/* --- dol/fn_800475C0.c --- */
/* --- dol/fn_800475C0.c --- */
struct fn_800475C0_lbl_8017B030 {
    u32 unk_0;
    u32 unk_4;
};

extern struct fn_800475C0_lbl_8017B030 lbl_8017B030[];
extern u32 memset(u32, u32, u32);

void fn_800475C0(void);

/* --- dol/fn_80047608.c --- */
struct fn_80047608_lbl_8017B158 {
    u32 unk_0;
};
extern struct fn_80047608_lbl_8017B158 lbl_8017B158[];
extern u32 fn_80046738(void);
extern void fn_80046718(void);
extern u32 ADXSTM_ExecServer(void);
extern u32 cvFsExecServer(void);
extern u32 ADXF_ExecServer(void);


void fn_80047608(void);

/* --- dol/ADXT_InsertHdrSfa.c --- */
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

typedef struct AdxSjdHandle AdxSjdHandle;

typedef struct ADXStream ADXStream;

typedef struct AXRNAHandle AXRNAHandle;

typedef struct LSCObject LSCObject;

typedef struct ADX_AMP ADX_AMP;

typedef struct ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    AdxSjdHandle *decoder;
    ADXStream *stream;
    AXRNAHandle *rna;
    SJ *stream_sj;
    SJ *input_sj;
    SJ *output_sj[2];
    u8 *input_buffer;
    s32 input_buffer_size;
    s32 input_extra_size;
    u8 *output_buffer;
    s32 output_buffer_size;
    s32 output_buffer_distance;
    s32 server_frequency;
    s16 stream_buffer_sectors;
    s16 minimum_buffer_sectors;
    s16 output_volume;
    s16 output_pan[2];
    s16 field_46;
    s32 maximum_decode_samples;
    s32 loop_count;
    s32 link_data_length;
    s32 field_54;
    s32 field_58;
    s32 field_5C;
    s16 error_code;
    u8 reserved_62[2];
    s32 field_64;
    s16 field_68;
    s16 field_6A;
    s8 stream_loop_enabled;
    s8 auto_receiver;
    u8 reserved_6E[2];
    s8 suppress_playback;
    s8 decoder_ready;
    s8 paused;
    u8 reserved_73;
    ADX_AMP *amplifier;
    SJ *amplifier_input[2];
    SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    LSCObject *linked_stream_controller;
    s8 link_enabled;
    u8 reserved_99[3];
    u32 playback_time;
    s32 playback_start_vsync;
    s32 linked_decoded_samples;
    s8 pending_stream_start;
    u8 reserved_A9[3];
    u8 *work_end;
    const char *pending_filename;
    void *pending_directory;
    s32 pending_file_offset;
    s32 pending_file_sectors;
} ADXTHandle;

typedef struct AdxSjeHandle AdxSjeHandle;

SJ *fn_80058498(void *buffer, int buffer_size, int extra_size);

SJ *fn_80057B9C(void *buffer, int buffer_size);

void *memcpy(void *destination, const void *source, unsigned long size);

extern void fn_800482FC(void);

extern void fn_800482B8(void);

extern AdxSjeHandle *fn_80047C94(int count, SJ **inputs, SJ *output);

extern void fn_80047C08(AdxSjeHandle *encoder);

extern void fn_80047ADC(AdxSjeHandle *encoder, int channels, int sample_rate, int sample_count);

extern void ADXSJE_Start(AdxSjeHandle *encoder);

extern void fn_80047AF8(AdxSjeHandle *encoder);

extern void ADXSJE_ExecServer(void);

extern unsigned char lbl_8017B160[0x40];

extern unsigned char lbl_8017B1A0[0x400];

void ADXT_InsertHdrSfa(ADXTHandle *decoder, int channels, int sample_rate, int sample_count) {
    SJ *inputs[2];
    SJCK header;
    SJCK destination;
    SJ *header_stream;
    SJ *destination_stream;
    AdxSjeHandle *encoder;
    fn_800482FC();
    header_stream = fn_80058498(lbl_8017B1A0, sizeof(lbl_8017B1A0), 0);
    inputs[0] = fn_80057B9C(lbl_8017B160, 0x20);
    inputs[1] = fn_80057B9C(lbl_8017B160 + 0x20, 0x20);
    destination_stream = decoder->input_sj;
    encoder = fn_80047C94(2, inputs, header_stream);
    fn_80047ADC(encoder, channels, sample_rate, sample_count);
    ADXSJE_Start(encoder);
    ADXSJE_ExecServer();
    header_stream->interface->get_chunk(header_stream, 1, sizeof(lbl_8017B1A0), &header);
    if (header.len == 0) {
        for (;;) {
        }
    }
    destination_stream->interface->get_chunk(destination_stream, 0, header.len, &destination);
    if (destination.len < header.len) {
        for (;;) {
        }
    }
    memcpy(destination.data, header.data, header.len);
    header_stream->interface->put_chunk(header_stream, 0, &header);
    destination_stream->interface->put_chunk(destination_stream, 1, &destination);
    fn_80047AF8(encoder);
    fn_80047C08(encoder);
    header_stream->interface->destroy(header_stream);
    inputs[1]->interface->destroy(inputs[1]);
    inputs[0]->interface->destroy(inputs[0]);
    fn_800482B8();
}
