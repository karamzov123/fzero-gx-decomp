#include "types.h"
typedef struct MPVMCContext MPVMCContext;
typedef struct SfdAudioOutputCallbacks SfdAudioOutputCallbacks;
typedef struct SfdSeeWork SfdSeeWork;
typedef struct SfdVideoFrameState SfdVideoFrameState;
typedef struct fn_12_26C0C_SfdHandle fn_12_26C0C_SfdHandle;
typedef struct fn_12_27C58_SJ fn_12_27C58_SJ;
typedef struct fn_12_27C58_SJInterface fn_12_27C58_SJInterface;
typedef struct fn_12_27C58_SfdMpvPictureUserData fn_12_27C58_SfdMpvPictureUserData;
typedef struct fn_12_27C58_SfdTransportSetup fn_12_27C58_SfdTransportSetup;
#include "sofdec/sj.h"
#include "rel/movie_module/data/lbl_12_rodata_A18.h"

typedef struct MovieArgs {
    u32 field_0000;
    u32 field_0004;
} MovieArgs;

typedef struct fn_12_270AC_MovieObject {
    u8 pad_0038[0x38];
    int field_0038;
    u8 pad_003c[0x1af4];
    void *field_1b30;
    u8 pad_1b34[0x38c];
    void *field_1ec0;
} fn_12_270AC_MovieObject;

typedef struct SfdCreateConfig {
    union {
        unsigned char padding_extent[68];
        struct {
            unsigned char padding_video_output_format[56];
            int video_output_format;
        } view_video_output_format;
    } fields;
} SfdCreateConfig;

typedef struct fn_12_27C58_SfdTransportState {
    union {
        unsigned char padding_extent[68];
        struct {
            unsigned char padding_context[8];
            void *context;
        } view_context;
        struct {
            unsigned char padding_state[32];
            int state;
        } view_state;
    } fields;
} fn_12_27C58_SfdTransportState;

typedef struct fn_12_27C58_SfdHandle fn_12_27C58_SfdHandle;

struct fn_12_27C58_SfdHandle {
    union {
        unsigned char padding_extent[13720];
        struct {
            SfdCreateConfig create_config;
        } view_create_config;
        struct {
            unsigned char padding_transports[6816];
            fn_12_27C58_SfdTransportState transports[9];
        } view_transports;
    } fields;
};

typedef int (*SfdTransportLifecycleFn)(fn_12_27C58_SfdHandle *handle);

typedef int (*SfdTransportPauseFn)(fn_12_27C58_SfdHandle *handle, int state);

typedef int (*SfdTransportBufferFn)(fn_12_27C58_SfdHandle *handle, void *buffer);

typedef int SfdTransportValue;

typedef int (*SfdTransportTransferFn)(fn_12_27C58_SfdHandle *handle, SfdTransportValue parameter, int value);

typedef struct SfdTransportInterface SfdTransportInterface;

struct SfdTransportInterface {
    SfdTransportLifecycleFn init;
    SfdTransportLifecycleFn finish;
    SfdTransportLifecycleFn exec_server;
    SfdTransportLifecycleFn create;
    SfdTransportLifecycleFn destroy;
    SfdTransportLifecycleFn standby;
    SfdTransportLifecycleFn start;
    SfdTransportLifecycleFn stop;
    SfdTransportPauseFn pause;
    SfdTransportBufferFn get_write;
    SfdTransportTransferFn add_write;
    SfdTransportBufferFn get_read;
    SfdTransportTransferFn add_read;
    SfdTransportTransferFn seek;
};

typedef struct fn_12_298AC_SfdTransportState {
    int prepared;
    int terminated;
    void *context;
    const SfdTransportInterface *interface;
    int parameter_10;
    int parameter_14;
    int parameter_18;
    int buffer_output3;
    int state;
    unsigned char unknown_0024[0x20];
} fn_12_298AC_SfdTransportState;

typedef struct fn_12_298AC_SfdHandle fn_12_298AC_SfdHandle;

struct fn_12_298AC_SfdHandle {
    unsigned char unknown_0000[0x28];
    int ring_alignment;
    unsigned char unknown_002C[0x1AA0 - 0x2C];
    fn_12_298AC_SfdTransportState transports[9];
};

typedef struct MovieBlob {
    s32 field_0000[10];
} MovieBlob;

typedef struct fn_12_267C0_MovieState {
    void *field_0000;
    u8 pad04[0x70];
    s32 field_0074;
    s32 field_0078;
    u8 pad7c[0xc];
    s32 field_0088;
} fn_12_267C0_MovieState;

typedef struct fn_12_267C0_MovieData {
    s32 ready;
    u8 pad04[8];
    MovieBlob blob;
    u8 pad34[0x200];
    s32 field_0234;
} fn_12_267C0_MovieData;

typedef struct fn_12_267C0_MovieObject {
    u8 pad_0000[0xcdc];
    MovieBlob blob;
    u8 pad_0d04[0xe2c];
    fn_12_267C0_MovieState *state;
    u8 pad_1b34[0xdd4];
    fn_12_267C0_MovieData *movie;
} fn_12_267C0_MovieObject;

typedef struct fn_12_27478_SfdTimeCode {
    int fields[6];
    int frame_offset;
} fn_12_27478_SfdTimeCode;

typedef struct fn_12_27478_SfdMpvTimeCodeSnapshot {
    int valid;
    fn_12_27478_SfdTimeCode timecode;
    int value;
    int scale;
} fn_12_27478_SfdMpvTimeCodeSnapshot;

typedef struct fn_12_27478_SfdMpvDecodeTimer {
    unsigned char reserved_000[0x1C];
    fn_12_27478_SfdMpvTimeCodeSnapshot initial;
    unsigned char reserved_044[0x50];
    fn_12_27478_SfdMpvTimeCodeSnapshot current;
    unsigned char reserved_0BC[0x28];
    fn_12_27478_SfdMpvTimeCodeSnapshot output_start;
    unsigned char reserved_10C[0x14];
    int field_120;
} fn_12_27478_SfdMpvDecodeTimer;

typedef struct MPVContext MPVContext;

struct MPVContext {
    union {
        unsigned char padding_extent[4992];
        struct {
            unsigned char padding_state[392];
            s32 state;
        } view_state;
    } fields;
};

typedef struct fn_12_27478_MPVPictureInfo {
    int fields_00[6];
    int picture_type;
    int fields_1C[6];
    int field_38;
} fn_12_27478_MPVPictureInfo;

typedef struct fn_12_27478_SfdMpvPictureUserData {
    void *buffer;
    int size;
} fn_12_27478_SfdMpvPictureUserData;

typedef struct fn_12_27478_SfdMpvFrame {
    int state;
    void *frame_buffer;
    int display_time_value;
    int display_time_scale;
    int field_40;
    int field_44;
    int picture_order;
    int field_4C;
    int field_50;
    fn_12_27478_SfdMpvPictureUserData *picture_user_buffer;
    unsigned int picture_info[20];
} fn_12_27478_SfdMpvFrame;

typedef struct fn_12_27478_SfdMpvFrameWork {
    MPVContext *decoder;
    unsigned char reserved_004[0x70];
    int decode_state;
    unsigned char reserved_078[0xC];
    int field_084;
    int field_088;
    fn_12_27478_MPVPictureInfo picture_info;
    unsigned char reserved_0C4[0x6C];
    fn_12_27478_SfdMpvFrame *pending_frame;
    unsigned char reserved_134[0x790];
    void *picture_buffer;
    int picture_buffer_size;
} fn_12_27478_SfdMpvFrameWork;

typedef struct fn_12_27478_SfdTimerSummary {
    int fields[8];
} fn_12_27478_SfdTimerSummary;

typedef struct fn_12_27478_SfdHandle {
    unsigned char reserved_0000[0x38];
    int video_output_format;
    unsigned char reserved_003C[0x918];
    int runtime_field_08;
    int runtime_field_0C;
    unsigned char reserved_095C[0x3C];
    int error_field_0C;
    int error_field_10;
    unsigned char reserved_09A0[0x10];
    int conditions_primary_4;
    unsigned char reserved_09B4[0x30C];
    fn_12_27478_SfdMpvDecodeTimer timer_state;
    unsigned char reserved_0DE4[0x11C];
    int latest_time_value;
    int latest_time_scale;
    unsigned char reserved_0F08[0xC28];
    fn_12_27478_SfdMpvFrameWork *video_work;
    int video_field_1B34;
    int video_parameter;
    unsigned char reserved_1B3C[0xDDC];
    fn_12_27478_SfdTimerSummary timer_summaries[4];
} fn_12_27478_SfdHandle;

typedef struct fn_12_284F8_SfdPlaybackSettings {
    int unk_0;
    int unk_4;
    int unk_8;
    int unk_C;
    int unk_10;
    int frame_rate_code;
    u8 unk_18[8];
    int unk_20;
} fn_12_284F8_SfdPlaybackSettings;

typedef struct fn_12_284F8_SfdTimeCode {
    int frame_rate_code;
    int drop_frame;
    int hours;
    int minutes;
    int seconds;
    int frames;
    int frame_offset;
} fn_12_284F8_SfdTimeCode;

typedef struct fn_12_284F8_SfdMpvTimeCodeSnapshot {
    int valid;
    fn_12_284F8_SfdTimeCode timecode;
    int value;
    int scale;
} fn_12_284F8_SfdMpvTimeCodeSnapshot;

typedef struct fn_12_284F8_SfdMpvDecodeTimer {
    u8 unk_000[0x1C];
    fn_12_284F8_SfdMpvTimeCodeSnapshot initial;
    fn_12_284F8_SfdMpvTimeCodeSnapshot maximum;
    u8 unk_06C[0x28];
    fn_12_284F8_SfdMpvTimeCodeSnapshot current;
    u8 unk_0BC[0x58];
} fn_12_284F8_SfdMpvDecodeTimer;

typedef struct fn_12_284F8_MPVPictureInfo {
    int width;
    int height;
    int macroblocks_per_row;
    int macroblock_rows;
    int frame_rate_code;
    int temporal_reference;
    int picture_type;
    int drop_frame_flag;
    int time_code_hours;
    int time_code_minutes;
    int time_code_seconds;
    int time_code_pictures;
    int unk_30;
} fn_12_284F8_MPVPictureInfo;

typedef struct Entry {
    int unk_0;
    int unk_4;
    int unk_8;
} Entry;

typedef struct fn_12_284F8_SfdMpvFrameWork {
    void *decoder;
    u8 unk_004[0x84];
    int unk_88;
    fn_12_284F8_MPVPictureInfo picture_info;
    u8 unk_0C0[0x1C];
    int unk_DC;
    int unk_E0;
    int unk_E4;
    int unk_E8;
    int unk_EC;
    int unk_F0;
    Entry unk_F4;
    u8 unk_100[0x7C0];
    void *picture_buffer;
    int picture_buffer_size;
    int unk_8C8;
} fn_12_284F8_SfdMpvFrameWork;

typedef struct SeekBuffer {
    u8 unk_0[0x200];
    int unk_200;
} SeekBuffer;

typedef struct SeekEntry {
    int unk_0;
    int unk_4;
    int unk_8;
    fn_12_284F8_SfdMpvTimeCodeSnapshot unk_C;
    SeekBuffer unk_34;
} SeekEntry;

typedef struct SeekWork {
    u8 unk_0[0xAC4];
    SeekEntry unk_AC4;
} SeekWork;

typedef struct fn_12_284F8_SfdHandle {
    u8 unk_0000[0x90C];
    fn_12_284F8_SfdPlaybackSettings playback_settings;
    u8 unk_0930[0x390];
    fn_12_284F8_SfdMpvDecodeTimer timer_state;
    int unk_DD4;
    u8 unk_0DD8[0xD58];
    fn_12_284F8_SfdMpvFrameWork *video_work;
    int unk_1B34;
    int video_parameter;
    u8 unk_1B3C[0xDCC];
    SeekWork *seek_work;
} fn_12_284F8_SfdHandle;

typedef struct fn_12_28CC4_SfdTransportSetup {
    u8 reserved_00[0xC];
    const void *audio_transport;
} fn_12_28CC4_SfdTransportSetup;

typedef struct fn_12_28CC4_SfdTimeCode {
    s32 frame_rate_code;
    s32 drop_frame;
    s32 hours;
    s32 minutes;
    s32 seconds;
    s32 frames;
    s32 frame_offset;
} fn_12_28CC4_SfdTimeCode;

typedef struct fn_12_28CC4_SfdMpvTimeCodeSnapshot {
    s32 valid;
    fn_12_28CC4_SfdTimeCode timecode;
    s32 value;
    s32 scale;
} fn_12_28CC4_SfdMpvTimeCodeSnapshot;

typedef struct fn_12_28CC4_SfdMpvDecodeTimer {
    u8 reserved_000[0x1C];
    fn_12_28CC4_SfdMpvTimeCodeSnapshot initial;
    fn_12_28CC4_SfdMpvTimeCodeSnapshot maximum;
    fn_12_28CC4_SfdMpvTimeCodeSnapshot reserved_snapshot;
    fn_12_28CC4_SfdMpvTimeCodeSnapshot current;
    fn_12_28CC4_SfdMpvTimeCodeSnapshot previous;
    u8 reserved_0E4[0x20];
    s32 reference_time_origin;
    u8 reserved_108[0x18];
    s32 reference_time_offset;
    u8 reserved_124[0x88];
    s32 total_samples;
} fn_12_28CC4_SfdMpvDecodeTimer;

typedef struct fn_12_28CC4_SfdMpvFrameWork {
    void *decoder;
    u8 reserved_004[0x74];
    s32 decode_mode;
    u8 reserved_07C[0xC];
    s32 concat_count;
    u8 reserved_08C[0x18];
    s32 picture_type;
} fn_12_28CC4_SfdMpvFrameWork;

typedef struct fn_12_28CC4_SfdHandle {
    fn_12_28CC4_SfdTransportSetup *transport_setup;
    u8 reserved_0004[0x968];
    s32 decode_wait;
    u8 reserved_0970[0x350];
    fn_12_28CC4_SfdMpvDecodeTimer timer;
    u8 reserved_0E70[0xCC0];
    fn_12_28CC4_SfdMpvFrameWork *video_work;
    u8 reserved_1B34[0x4];
    s32 video_buffer;
    u8 reserved_1B3C[0xC];
    s32 video_total;
} fn_12_28CC4_SfdHandle;

typedef struct MovieEntry {
    void *data;
    u32 field04;
    u32 field08;
    u32 field0c;
    u32 field10;
    u32 field14;
    u32 field18;
    u32 field1c;
    u32 field20;
    u32 field24;
    u32 field28;
    u32 field2c;
    u8 payload[0x40];
} MovieEntry;

typedef struct fn_12_26C2C_MovieModule {
    u8 pad[0x1b30];
    MovieEntry *entry;
} fn_12_26C2C_MovieModule;

typedef void (*Sig_fn_12_24A88_MovieCallback)(void *, s32);

typedef struct Sig_fn_12_24A88_MovieObject {
    u8 pad_0000[0x48];
    s32 state;
    u8 pad_004c[0x940];
    Sig_fn_12_24A88_MovieCallback callback;
    void *callback_context;
    s32 callback_data;
} Sig_fn_12_24A88_MovieObject;

typedef struct fn_12_29FF8_MovieModule {
    u8 pad_0000[0x2c];
    int field_2c;
    u8 pad_0030[0x48];
    int field_78;
    u8 pad_007c[0x78];
    int field_f4;
    u8 pad_00f8[0x854];
    int field_94c;
    u8 pad_0950[0x10];
    s32 field_960;
    u8 pad_0964[0x98];
    int field_9fc;
    u8 pad_a00[0x3a4];
    int field_da4;
    u8 pad_da8[0x1c];
    int field_dc4;
    u8 pad_dc8[0xd68];
    void *field_1b30;
    int field_1b34;
    int field_1b38;
    int field_1b3c;
    u8 pad_1b40[0x794];
    int field_22d4;
    u8 pad_22d8[0x8];
    int field_22e0;
} fn_12_29FF8_MovieModule;

typedef struct fn_12_26B18_MovieData {
    unsigned char pad_0[0x14];
    int field_14;
    int field_18;
} fn_12_26B18_MovieData;

struct fn_12_269E4_arg0_1138_E116 {
    u8 pad_0[0x28];
    u32 unk_28;
    u8 pad_2C[0x48];
};

struct fn_12_269E4_Arg0 {
    u8 pad_0[0x38];
    u32 unk_38;
    u8 pad_3C[0x10FC];
    struct fn_12_269E4_arg0_1138_E116 unk_1138[1];
    u8 pad_11AC[0x984];
    u32 unk_1B30;
    u8 pad_1B34[0x8];
    u32 unk_1B3C;
};

struct fn_12_269E4_Arg1 {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u8 pad_38[0x8];
    u32 unk_40;
    u8 pad_44[0x18];
    u32 unk_5C;
    u32 unk_60;
    u32 unk_64;
    u32 unk_68;
    u32 unk_6C;
    u32 unk_70;
    u32 unk_74;
};

struct fn_12_269E4_Arg2 {
    u32 unk_0;
};

typedef struct MovieInfo {
    u32 field00;
    u32 field04;
    u32 field08;
    u32 field0c;
    u32 buf0;      /* 0x10 */
    u32 field14;
    u32 field18;
    s32 count;     /* 0x1c */
    u32 buf1;      /* 0x20 */
} MovieInfo;

typedef struct MovieChannel {
    u32 field00;
    u32 buf;
    u32 field08;
    u32 field0c;
    u32 field10;
    u32 field14;
    u32 field18;
    u32 field1c;
    u32 field20;
    u32 *slot;
    u32 queue[20];
} MovieChannel;

typedef struct MovieSetup {
    u32 field000;
    MovieInfo info;        /* 0x004 */
    u32 pair[2];           /* 0x028 */
    u32 bufs[16];          /* 0x030 */
    u32 field070;
    u32 field074;
    u32 field078;
    u32 field07c;
    u32 field080;
    u32 field084;
    u32 field088;
    u32 queue[20];         /* 0x08c */
    s32 field0dc;
    u32 field0e0;
    s32 field0e4;
    u32 field0e8;
    u32 field0ec;
    u32 field0f0;
    s32 field0f4;
    u32 field0f8;
    s32 field0fc;
    u32 field100;
    u32 field104;
    u8 pad108[0x20];
    u32 field128;
    u32 field12c;
    u32 field130;
    u32 pad134;
    MovieChannel ch[16];   /* 0x138 */
    u32 field8b8;
    u32 field8bc;
    u32 field8c0;
    u32 field8c4;
    u32 field8c8;
    u32 slots[16][2];      /* 0x8cc */
} MovieSetup;

typedef void (*MPVErrorCallback)(void *object, int error);

typedef struct fn_12_27C58_SfdMpvFrame {
    union {
        unsigned char padding_extent[120];
        struct {
            int state;
        } view_state;
        struct {
            unsigned char padding_frame_buffer[4];
            void *frame_buffer;
        } view_frame_buffer;
        struct {
            unsigned char padding_display_time_value[8];
            int display_time_value;
        } view_display_time_value;
        struct {
            unsigned char padding_display_time_scale[12];
            int display_time_scale;
        } view_display_time_scale;
        struct {
            unsigned char padding_field_40[16];
            int field_40;
        } view_field_40;
        struct {
            unsigned char padding_field_44[20];
            int field_44;
        } view_field_44;
        struct {
            unsigned char padding_picture_order[24];
            int picture_order;
        } view_picture_order;
        struct {
            unsigned char padding_field_4C[28];
            int field_4C;
        } view_field_4C;
        struct {
            unsigned char padding_field_50[32];
            int field_50;
        } view_field_50;
        struct {
            unsigned char padding_picture_info[40];
            unsigned int picture_info[20];
        } view_picture_info;
    } fields;
} fn_12_27C58_SfdMpvFrame;

typedef struct Sig_fn_12_2AB68_MovieEntry {
    int used;
    u8 pad[0x74];
} Sig_fn_12_2AB68_MovieEntry;

typedef struct Sig_fn_12_2AB68_MovieList {
    u8 pad[0x134];
    int count;
    Sig_fn_12_2AB68_MovieEntry entries[1];
} Sig_fn_12_2AB68_MovieList;

typedef struct Sig_fn_12_2AB68_MovieObject {
    u8 pad[0x1b30];
    Sig_fn_12_2AB68_MovieList *list;
} Sig_fn_12_2AB68_MovieObject;

struct Sig_fn_12_2AAD4_fn_12_2AAD4_Arg0 {
    u32 unk_0;
};

struct fn_12_27224_Arg0 {
    u8 pad_0[0x1B30];
    u32 list_1b30;
};

typedef struct fn_12_28CC4_SJCK {
    unsigned char *data;
    long len;
} fn_12_28CC4_SJCK;

typedef struct fn_12_28CC4_SJ fn_12_28CC4_SJ;

typedef struct fn_12_28CC4_SJInterface {
    void *reserved[6];
    void (*get_chunk)(fn_12_28CC4_SJ *sj, int channel, int max_size, fn_12_28CC4_SJCK *chunk);
    void (*unget_chunk)(fn_12_28CC4_SJ *sj, int channel, fn_12_28CC4_SJCK *chunk);
    void (*put_chunk)(fn_12_28CC4_SJ *sj, int channel, fn_12_28CC4_SJCK *chunk);
} fn_12_28CC4_SJInterface;

struct fn_12_28CC4_SJ {
    const fn_12_28CC4_SJInterface *interface;
};

typedef struct fn_12_27478_MPVFrameBuffers {
    int planes[10];
    int decoded_dct_count;
    int skipped_dct_count;
} fn_12_27478_MPVFrameBuffers;

typedef struct SfdMpvPlaybackSettings {
    union {
        unsigned char padding_extent[64];
        struct {
            int width;
        } view_width;
        struct {
            unsigned char padding_height[4];
            int height;
        } view_height;
    } fields;
} SfdMpvPlaybackSettings;

typedef struct SfdTimerTimeUnit {
    int active;
    int fields_04[7];
    unsigned short field_20;
    unsigned short field_22;
    int value;
    int scale;
} SfdTimerTimeUnit;

typedef struct fn_12_28304_SfdTimeCode {
    int frame_rate_code;
    int drop_frame;
    int hours;
    int minutes;
    int seconds;
    int frames;
    int frame_offset;
} fn_12_28304_SfdTimeCode;

typedef struct fn_12_28304_SfdMpvTimeCodeSnapshot {
    int valid;
    fn_12_28304_SfdTimeCode timecode;
    int value;
    int scale;
} fn_12_28304_SfdMpvTimeCodeSnapshot;

typedef struct fn_12_28304_SfdMpvDecodeTimer {
    unsigned char reserved_000[0x1C];
    fn_12_28304_SfdMpvTimeCodeSnapshot initial;
    fn_12_28304_SfdMpvTimeCodeSnapshot maximum;
} fn_12_28304_SfdMpvDecodeTimer;

typedef struct fn_12_28304_SfdHandle {
    unsigned char reserved_0000[0xCC0];
    fn_12_28304_SfdMpvDecodeTimer timer_state;
    unsigned char reserved_0D2C[0x1BDC];
    void *seek_work;
} fn_12_28304_SfdHandle;

typedef struct fn_12_28304_MPVPictureInfo {
    int width;
    int height;
    int macroblocks_per_row;
    int macroblock_rows;
    int frame_rate_code;
    int temporal_reference;
    int picture_type;
    int drop_frame_flag;
    int time_code_hours;
    int time_code_minutes;
    int time_code_seconds;
    int time_code_pictures;
} fn_12_28304_MPVPictureInfo;

typedef struct fn_12_29524_SJCK {
    unsigned char *data;
    long len;
} fn_12_29524_SJCK;

typedef struct fn_12_29524_SfdBufferTransfer {
    fn_12_29524_SJCK chunks[2];
    int reserved[3];
} fn_12_29524_SfdBufferTransfer;

typedef struct fn_12_28CC4_SfdBufferTransfer {
    fn_12_28CC4_SJCK chunks[2];
    s32 reserved[3];
} fn_12_28CC4_SfdBufferTransfer;

typedef struct MPVFrameBuffers {
    int planes[10];
    int decoded_dct_count;
    int skipped_dct_count;
} MPVFrameBuffers;

typedef struct SfdTimerSummary {
    int fields[8];
} SfdTimerSummary;

typedef struct SfdMpvPictureUserData {
    void *buffer;
    int size;
} SfdMpvPictureUserData;

typedef struct SfdMpvFrame {
    int state;
    void *frame_buffer;
    int display_time_value;
    int display_time_scale;
    int field_40;
    int field_44;
    int picture_order;
    int field_4C;
    int field_50;
    SfdMpvPictureUserData *picture_user_buffer;
    unsigned int picture_info[20];
} SfdMpvFrame;

typedef struct MovieData {
    s32 ready;
    u8 pad04[8];
    MovieBlob blob;
    u8 pad34[0x200];
    s32 field_0234;
} MovieData;

typedef struct SfdBufferTransfer {
    fn_12_28CC4_SJCK chunks[2];
    s32 reserved[3];
} SfdBufferTransfer;
extern s32 fn_12_C218(void *arg0, MovieArgs *args, s32 *result);
extern int fn_12_24A88(int arg0, u32 arg1);
extern u32 fn_12_2D73C(u8 *base, int index);
extern void fn_12_24970();
extern void fn_12_2AB00(void *);
extern void fn_12_24950();
extern void *memcpy(void *dst, const void *src, u32 size);
extern void fn_12_33428(u32 *dst, u32 value, u32 count);
extern s32 fn_12_26D68(Sig_fn_12_24A88_MovieObject *movie, MovieSetup *setup);
extern void *fn_12_CF2C(void);
extern void fn_12_26D24(Sig_fn_12_24A88_MovieObject *movie, s32 code);
extern int fn_12_A6E8(MPVContext *handle, MPVErrorCallback callback, int object);
extern s32 fn_12_CBC8(u32 arg0);
extern void fn_12_CAE4(void *, int, int);
fn_12_27C58_SfdMpvFrame *fn_12_2AB68(fn_12_27C58_SfdHandle *handle);
extern u32 fn_12_2AAD4(struct Sig_fn_12_2AAD4_fn_12_2AAD4_Arg0 *);
extern s32 fn_12_27224(struct fn_12_27224_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_12_2E374(u32 arg0, u32 arg1, u32 arg2);
extern s64 fn_12_335B8(void);
extern u32 fn_80057D88(u32 arg0, u32 arg1, u32 arg2);
extern int fn_12_A858(MPVContext *decoder, SJ *stream, fn_12_27478_MPVFrameBuffers *buffers);
extern void SFTMR_AddTsum(SfdTimerSummary *summary, long long elapsed);
extern void fn_12_21E20(fn_12_28CC4_SfdHandle *handle, s32 buffer, s32 size);
extern void fn_12_2AB54(int* value);
extern void fn_12_2AC80(fn_12_27478_SfdHandle *handle, int state);
extern void fn_12_2AB2C(int *value);
extern void fn_12_2AB40(int *arg0);
extern void fn_12_CCB0(const MovieData *movie, u32 *first, u32 *second);
extern void fn_12_2BA6C(fn_12_27478_SfdHandle *handle, int count, int picture_type);
extern int fn_12_332DC(int a, int b, int c, int d);
extern s32 fn_12_A374(s32 arg0, s32 length, s32 count);
extern void fn_12_2EDAC(void *, int);
extern int fn_12_2ED74(void *, int);
extern int fn_12_A9C4(void *movie, void *out_a, void *out_b);
extern void fn_12_2814C(s32 value, s32 index, s32 drop, s32 offset, s32 *out);
extern void fn_12_CA84(void *decoder, int size, void *buffer);
extern void fn_12_CA60(void *decoder, int *a, int *b);
extern int fn_12_C2C8(void *decoder, SJ *stream);
extern s32 fn_12_AB60(u32 arg0, u32 arg1);
extern u8 *fn_12_A0D8(u8 *data, s32 size, u32 mask);
extern int fn_12_2CDD0(fn_12_284F8_SfdHandle *handle, int parameter, const unsigned char *delimiter, Entry *entry);
extern const int lbl_12_rodata_E10[];
extern unsigned int UTY_MulDiv(int multiplicand, int multiplier, int divisor);
extern s32 memcmp(u32 arg0, u32 arg1, u32 arg2);
extern void fn_12_2D7DC(u8 *base, int index, int value);
extern void fn_12_28304(fn_12_28304_SfdHandle *handle, fn_12_28304_MPVPictureInfo *picture, int pts, int group_changed);
extern int fn_12_AB00(void *obj, int *value);
extern int fn_12_AA38(void *movie, void *out_a, void *out_b, void *out_c);
extern int fn_12_21F38(fn_12_284F8_SfdHandle *handle, int index);
extern void *fn_12_57F0(void *dst, const void *src, u32 size);
extern int fn_12_27C58(fn_12_27C58_SfdHandle *handle, SfdMpvPlaybackSettings *settings);
extern int fn_12_21E40(void *module, int index, int *movie_id);
extern s32 fn_12_21F28(fn_12_28CC4_SfdHandle *handle, s32 buffer);
extern u32 fn_12_23250(u32 arg0);
extern int fn_12_22FBC(fn_12_28CC4_SfdHandle *handle, s32 *samples, s32 *sample_rate);
extern void fn_12_23120(void *arg0, int arg1);
extern void fn_12_2EE48(fn_12_28CC4_SfdMpvTimeCodeSnapshot *snapshot, s32 value);
extern u32 fn_12_A2C4(const u8 *data);
extern s32 fn_12_231A0(u32 arg0);
extern int fn_12_21D30(fn_12_28CC4_SfdHandle *handle, s32 buffer);
extern void fn_12_2AC98(fn_12_28CC4_SfdHandle *handle);
extern int fn_12_22390(u8 *module, int index, u32 *out);
extern int fn_12_284F8(fn_12_284F8_SfdHandle *handle, SJCK *chunk, SJ *stream, int flag);
extern int fn_12_27884(fn_12_28CC4_SfdHandle *handle, fn_12_28CC4_SJCK *chunk);
extern void fn_12_A7B0(void *movie, SJ *sj);
extern void fn_12_2B9F8(fn_12_28CC4_SfdHandle *handle, s32 count, s32 picture_type);
extern int fn_12_27478(fn_12_27478_SfdHandle *handle, SJ *stream);
extern void fn_12_22008(fn_12_28CC4_SfdHandle *handle, s32 buffer, s32 size);
extern int fn_12_23F00(fn_12_29FF8_MovieModule *module);
extern s32 fn_12_24990();
extern int fn_12_298AC(fn_12_298AC_SfdHandle *handle, int *active_size, int *delimiter_type);
extern int fn_12_28CC4(fn_12_28CC4_SfdHandle *handle, s32 active_size, s32 delimiter_type, int *processed);
extern int fn_12_21D50(fn_12_29FF8_MovieModule *module, int value);
extern int fn_12_2AC8C(fn_12_29FF8_MovieModule *module);
extern int fn_12_2ABF0(void *);
extern int fn_12_21E94(fn_12_29FF8_MovieModule *module, int value);
extern int fn_12_2F1B4(fn_12_29FF8_MovieModule *module, int value);
extern void fn_12_21D60(fn_12_29FF8_MovieModule *module, int value, int flag);
extern void fn_12_21D40(void *base, int index, int value);
extern fn_12_26B18_MovieData *fn_12_2A9DC(void *, int *);
extern void fn_12_269E4(struct fn_12_269E4_Arg0 *arg0, struct fn_12_269E4_Arg1 *arg1, struct fn_12_269E4_Arg2 *arg2);
extern u32 lbl_12_bss_96A0[28];
void SFTIM_InitTtu(SfdTimerTimeUnit *unit, int scale);
extern const s32 lbl_12_rodata_C10[9];
extern s32 fn_12_334FC(s32 a, s32 b, s32 c);
extern u32 lbl_12_rodata_C54[9];
extern u32 lbl_12_rodata_C34[8];
extern int fn_12_29524(fn_12_29524_SfdBufferTransfer *transfer, int current_type, const unsigned char *delimiter);
extern char *fn_12_A1C4(char *text, s32 length, u32 mask);
int fn_12_21C00(fn_12_298AC_SfdHandle *handle, int buffer_index);
extern void fn_12_21F48(u8 *module, int index, void *movie, void *stream);
void fn_12_21FA4(fn_12_298AC_SfdHandle *handle, int buffer_index, unsigned char **position, unsigned char **end_position);
extern int fn_12_29FF8();
extern void fn_12_D038(void);
extern u8 lbl_12_bss_9710[73760];
extern s32 fn_12_D0B8(s32 id, void *buf);
extern void *memset(void *dst, int c, u32 n);
extern u32 fn_12_2A85C(u32);

/* fzgx:begin fn_12_267C0 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_267C0.c --- */
typedef struct MovieBlob {
    s32 field_0000[10];
} MovieBlob;

typedef struct MovieData {
    s32 ready;
    u8 pad04[8];
    MovieBlob blob;
    u8 pad34[0x200];
    s32 field_0234;
} MovieData;

typedef struct MovieState {
    void *field_0000;
    u8 pad04[0x70];
    s32 field_0074;
    s32 field_0078;
    u8 pad7c[0xc];
    s32 field_0088;
} MovieState;

typedef struct MovieObject {
    u8 pad_0000[0xcdc];
    MovieBlob blob;
    u8 pad_0d04[0xe2c];
    MovieState *state;
    u8 pad_1b34[0xdd4];
    MovieData *movie;
} MovieObject;

typedef struct MovieArgs {
    u32 field_0000;
    u32 field_0004;
} MovieArgs;

extern s32 fn_12_C218(void *base, MovieArgs *args, s32 *out);
extern s32 fn_12_24A88(MovieObject *self, u32 code);
extern s32 fn_12_2D73C(MovieObject *self, int value);

#pragma opt_propagation off
int fn_12_267C0(MovieObject *self) {
    MovieData * fzgx_live;
    u32 fzgx_value;
    MovieData *movie;
    MovieState *state;
    MovieData *data;
    void *ctx;
    MovieArgs args;
    s32 out;
    s32 result;
    s32 success;

    success = 0;
    fzgx_live = self->movie;
    movie = fzgx_live;
    state = self->state;
    if (movie == 0) {
        data = 0;
    } else if (state->field_0088 > 0) {
        data = 0;
    } else {
        data = (MovieData *)((u8 *)movie + 0xac4);
    }
    if (data == 0) {
        result = 0;
    } else if (data->ready == 0) {
        result = 0;
    } else {
        ctx = state->field_0000;
        self->blob = data->blob;
        fzgx_value = (u32)((u8 *)data + 0x34);
        args.field_0000 = fzgx_value;
        args.field_0004 = (u32)data->field_0234;
        if (fn_12_C218(ctx, &args, &out) != 0) {
            result = fn_12_24A88(self, 0xff000f1b);
        } else {
            success = 1;
            result = 0;
        }
    }
    if (result != 0) {
        return result;
    }
    state->field_0074 = 2;
    if (success == 0 || fn_12_2D73C(self, 0x30) == 0) {
        state->field_0078 = 0xc0;
    } else {
        state->field_0078 = 0xc8;
    }
    return 0;
}
/* fzgx:end fn_12_267C0 */

/* fzgx:begin fn_12_2692C noprologue */
#pragma opt_propagation reset

/* --- rel/movie_module/fn_12_2692C.c --- */
/* --- rel/movie_module/fn_12_2692C.c --- */
extern void fn_12_24970(void *);
extern void fn_12_2AB00(void *);
extern void fn_12_24950(void *);

int fn_12_2692C(void *arg0, void *arg1) {
    u8 local[8];
    int index;
    void *context;
    void *entry;
    int result;

    fn_12_24970(local);
    index = *(int *)((u8 *)arg0 + 0x1b3c);
    context = *(void **)((u8 *)arg0 + 0x1b30);
    entry = (u8 *)arg0 + index * 0x74;
    entry = *(void **)((u8 *)entry + 0x1160);
    if (*(int *)entry != 1) {
        result = fn_12_24A88(arg0, 0xff000f0e);
    } else if ((u8 *)entry + 4 != (u8 *)arg1) {
        result = fn_12_24A88(arg0, 0xff000f0f);
    } else {
        *(int *)entry = 0;
        fn_12_2AB00(*(void **)((u8 *)context + 0x70));
        result = 0;
    }
    fn_12_24950(local);
    return result;
}
/* fzgx:end fn_12_2692C */

/* fzgx:begin fn_12_269E4 noprologue */
/* --- rel/movie_module/fn_12_269E4.c --- */
struct fn_12_269E4_arg0_1138_E116 {
    u8 pad_0[0x28];
    u32 unk_28;
    u8 pad_2C[0x48];
};
struct fn_12_269E4_Arg0 {
    u8 pad_0[0x38];
    u32 unk_38;
    u8 pad_3C[0x10FC];
    struct fn_12_269E4_arg0_1138_E116 unk_1138[1];
    u8 pad_11AC[0x984];
    u32 unk_1B30;
    u8 pad_1B34[0x8];
    u32 unk_1B3C;
};
struct fn_12_269E4_Arg1 {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u8 pad_38[0x8];
    u32 unk_40;
    u8 pad_44[0x18];
    u32 unk_5C;
    u32 unk_60;
    u32 unk_64;
    u32 unk_68;
    u32 unk_6C;
    u32 unk_70;
    u32 unk_74;
};
struct fn_12_269E4_Arg2 {
    u32 unk_0;
};


void fn_12_269E4(struct fn_12_269E4_Arg0 *arg0, struct fn_12_269E4_Arg1 *arg1, struct fn_12_269E4_Arg2 *arg2) {
    u32 v1;
    u32 v0;
    u32 v2;
    v0 = arg0->unk_1138[arg0->unk_1B3C].unk_28;
    v1 = arg0->unk_1B30;
    arg2->unk_0 = (v0 + 4);
    *(u32 *)((u8 *)v0 + 0) = 1;
    *(u32 *)((u8 *)v1 + 112) = (u32)arg1;
    *(u32 *)((u8 *)arg2->unk_0 + 0) = arg1->unk_28;
    *(u32 *)((u8 *)arg2->unk_0 + 4) = arg1->unk_2C;
    *(u32 *)((u8 *)arg2->unk_0 + 8) = arg1->unk_30;
    *(u32 *)((u8 *)arg2->unk_0 + 12) = arg1->unk_34;
    *(u32 *)((u8 *)arg2->unk_0 + 16) = arg1->unk_40;
    *(u32 *)((u8 *)arg2->unk_0 + 20) = arg1->unk_8;
    *(u32 *)((u8 *)arg2->unk_0 + 24) = arg1->unk_C;
    *(u32 *)((u8 *)arg2->unk_0 + 28) = arg0->unk_38;
    *(u32 *)((u8 *)arg2->unk_0 + 32) = arg1->unk_4;
    *(u32 *)((u8 *)arg2->unk_0 + 36) = arg1->unk_10;
    *(u32 *)((u8 *)arg2->unk_0 + 40) = arg1->unk_14;
    *(u32 *)((u8 *)arg2->unk_0 + 44) = arg1->unk_18;
    *(u32 *)((u8 *)arg2->unk_0 + 48) = arg1->unk_1C;
    *(u32 *)((u8 *)arg2->unk_0 + 52) = arg1->unk_20;
    *(u32 *)((u8 *)arg2->unk_0 + 56) = arg1->unk_24;
    *(u32 *)((u8 *)arg2->unk_0 + 60) = arg1->unk_5C;
    *(u32 *)((u8 *)arg2->unk_0 + 64) = arg1->unk_60;
    *(u32 *)((u8 *)arg2->unk_0 + 68) = arg1->unk_64;
    *(u32 *)((u8 *)arg2->unk_0 + 72) = arg1->unk_68;
    *(u32 *)((u8 *)arg2->unk_0 + 76) = arg1->unk_6C;
    *(u32 *)((u8 *)arg2->unk_0 + 80) = arg1->unk_70;
    v2 = arg2->unk_0;
    *(u32 *)((u8 *)v2 + 84) = arg1->unk_74;
}
/* fzgx:end fn_12_269E4 */

/* fzgx:begin fn_12_26B18 */
/* --- rel/movie_module/fn_12_26B18.c --- */
typedef struct fn_12_26B18_MovieObject {
    unsigned char pad_0[0xef8];
    int field_ef8;
    int field_efc;
} fn_12_26B18_MovieObject;



int fn_12_26B18(fn_12_26B18_MovieObject *movie, fn_12_26B18_MovieData **out) {
    int local;
    fn_12_26B18_MovieData *data;

    if (fn_12_2ABF0(movie) == -1) {
        *out = 0;
        return 0;
    }

    data = fn_12_2A9DC(movie, &local);
    if (data == 0) {
        *out = 0;
        return 0;
    }

    fn_12_269E4( (struct fn_12_269E4_Arg0 *)(void *)(movie), (struct fn_12_269E4_Arg1 *)(fn_12_26B18_MovieData *)(data), (struct fn_12_269E4_Arg2 *)(fn_12_26B18_MovieData **)(out));
    movie->field_ef8 = (*out)->field_14;
    movie->field_efc = (*out)->field_18;
    return 0;
}
/* fzgx:end fn_12_26B18 */

/* fzgx:begin fn_12_26BB4 */
/* --- rel/movie_module/fn_12_26BB4.c --- */

void fn_12_26BB4(int arg0) {
    fn_12_24A88(arg0, 0xff000f0d);
}
/* fzgx:end fn_12_26BB4 */

/* fzgx:begin fn_12_26BDC */
/* --- rel/movie_module/fn_12_26BDC.c --- */
/* --- rel/movie_module/fn_12_26BDC.c --- */

void fn_12_26BDC(void *arg) {
    fn_12_24A88( (int)(void *)(arg), 0xff000f0d);
}
/* fzgx:end fn_12_26BDC */

/* fzgx:begin fn_12_26C04 */
/* --- rel/movie_module/fn_12_26C04.c --- */
// fn_12_26C04: returns a constant.
int fn_12_26C04(void) {
    return 0;
}
/* fzgx:end fn_12_26C04 */

/* fzgx:begin fn_12_26C0C */
typedef struct fn_12_26C0C_SfdHandle fn_12_26C0C_SfdHandle;

typedef struct fn_12_26C0C_SfdTransportState {
    union {
        unsigned char padding_extent[68];
        struct {
            unsigned char padding_context[8];
            void *context;
        } fn_12_26C0C_view_context;
    } fn_12_26C0C_fields;
} fn_12_26C0C_SfdTransportState;

struct fn_12_26C0C_SfdHandle {
    union {
        unsigned char padding_extent[13720];
        struct {
            unsigned char padding_transports[6816];
            fn_12_26C0C_SfdTransportState transports[9];
        } fn_12_26C0C_view_transports;
    } fn_12_26C0C_fields;
};

static inline int sfmpv_StopSub(fn_12_26C0C_SfdHandle *handle) {
    int result;
    result = 0;
    if (handle->fn_12_26C0C_fields.fn_12_26C0C_view_transports.transports[2].fn_12_26C0C_fields.fn_12_26C0C_view_context.context == 0) {
        result = 0;
    }
    return result;
}

int fn_12_26C0C(fn_12_26C0C_SfdHandle *handle) { return sfmpv_StopSub(handle); }
/* fzgx:end fn_12_26C0C */

/* fzgx:begin fn_12_26C1C */
/* --- rel/movie_module/fn_12_26C1C.c --- */
// fn_12_26C1C: returns a constant.
int fn_12_26C1C(void) {
    return 0;
}
/* fzgx:end fn_12_26C1C */

/* fzgx:begin fn_12_26C24 */
/* --- rel/movie_module/fn_12_26C24.c --- */
// fn_12_26C24: returns a constant.
int fn_12_26C24(void) {
    return 0;
}
/* fzgx:end fn_12_26C24 */

/* fzgx:begin fn_12_26C2C */
/* --- rel/movie_module/fn_12_26C2C.c --- */

struct Copy8 {
    u32 a[2];
};

struct Copy28 {
    u32 a[7];
};




int fn_12_26C2C(fn_12_26C2C_MovieModule *module) {
    u32 *globals;
    MovieEntry *entry;
    void *movie;
    u32 value1;
    u32 value0;

    globals = lbl_12_bss_96A0;
    entry = module->entry;
    movie = entry->data;
    if (movie == 0) {
        return 0;
    }

    *(struct Copy8 *)&globals[19] = *(struct Copy8 *)&entry->field04;
    *(struct Copy28 *)&globals[21] = *(struct Copy28 *)&entry->field0c;
    memcpy(&globals[17], &entry->field28, 8);
    memcpy(&globals[1], entry->payload, 0x40);

    if (fn_12_CBC8( (u32)(void *)(movie)) != 0) {
        return fn_12_24A88( (int)(fn_12_26C2C_MovieModule *)(module), 0xff000f0c);
    } else {
        entry->data = 0;
        return 0;
    }
}
/* fzgx:end fn_12_26C2C */

/* fzgx:begin fn_12_26D24 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_26D24.c --- */
typedef void (*Sig_fn_12_24A88_MovieCallback)(void *, s32);

typedef struct Sig_fn_12_24A88_MovieObject {
    u8 pad_0000[0x48];
    s32 state;
    u8 pad_004c[0x940];
    Sig_fn_12_24A88_MovieCallback callback;
    void *callback_context;
    s32 callback_data;
} Sig_fn_12_24A88_MovieObject;

extern s32 fn_12_24A88(Sig_fn_12_24A88_MovieObject *movie, s32 code);

void fn_12_26D24(Sig_fn_12_24A88_MovieObject *movie, s32 code) {
    switch (code) {
    case -3:
    case -2:
    case 0:
        break;
    default:
        fn_12_24A88(movie, code);
        break;
    }
}
/* fzgx:end fn_12_26D24 */

/* fzgx:begin fn_12_26D68 noprologue */
/* --- rel/movie_module/fn_12_26D68.c --- */
extern void *memcpy(void *, const void *, u32);
extern void fn_12_33428(u32 *, u32, u32);

/* 36-byte movie description */
typedef struct MovieInfo {
    u32 field00;
    u32 field04;
    u32 field08;
    u32 field0c;
    u32 buf0;      /* 0x10 */
    u32 field14;
    u32 field18;
    s32 count;     /* 0x1c */
    u32 buf1;      /* 0x20 */
} MovieInfo;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base
 * (dtk's lbl_12_bss_96A0 covers the first four objects) */
u32 lbl_12_bss_96A0;
u32 lbl_12_bss_96A0__fzgx_offset_4[16];   /* 0x96A4 */
u32 lbl_12_bss_96A0__fzgx_offset_44[2];    /* 0x96E4 */
MovieInfo lbl_12_bss_96A0__fzgx_offset_4C; /* 0x96EC */
u8 lbl_12_bss_9710[73760];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_12_bss_96A0;
    s = *(u8 *)&lbl_12_bss_96A0__fzgx_offset_4;
    s = *(u8 *)&lbl_12_bss_96A0__fzgx_offset_44;
    s = *(u8 *)&lbl_12_bss_96A0__fzgx_offset_4C;
    s = *(u8 *)&lbl_12_bss_9710;
}
#pragma section code_type ".text"

typedef struct MovieChannel {
    u32 field00;
    u32 buf;
    u32 field08;
    u32 field0c;
    u32 field10;
    u32 field14;
    u32 field18;
    u32 field1c;
    u32 field20;
    u32 *slot;
    u32 queue[20];
} MovieChannel;

typedef struct MovieSetup {
    u32 field000;
    MovieInfo info;        /* 0x004 */
    u32 pair[2];           /* 0x028 */
    u32 bufs[16];          /* 0x030 */
    u32 field070;
    u32 field074;
    u32 field078;
    u32 field07c;
    u32 field080;
    u32 field084;
    u32 field088;
    u32 queue[20];         /* 0x08c */
    s32 field0dc;
    u32 field0e0;
    s32 field0e4;
    u32 field0e8;
    u32 field0ec;
    u32 field0f0;
    s32 field0f4;
    u32 field0f8;
    s32 field0fc;
    u32 field100;
    u32 field104;
    u8 pad108[0x20];
    u32 field128;
    u32 field12c;
    u32 field130;
    u32 pad134;
    MovieChannel ch[16];   /* 0x138 */
    u32 field8b8;
    u32 field8bc;
    u32 field8c0;
    u32 field8c4;
    u32 field8c8;
    u32 slots[16][2];      /* 0x8cc */
} MovieSetup;

s32 fn_12_26D68(Sig_fn_12_24A88_MovieObject *movie, MovieSetup *setup) {
    s32 i;
    MovieChannel *ch;
    u32 *bp;
    u32 j;
    u32 k;
    s32 err;

    /* the pending description: count in range, and when either direct buffer is
     * missing, the pair and every per-stream buffer must be set.  The loop counter
     * is shared with the channel loop below (retail reuses one variable). */
    if (lbl_12_bss_96A0__fzgx_offset_4C.count <= 0 || lbl_12_bss_96A0__fzgx_offset_4C.count > 16) {
        err = -1;
        goto done; /* fzgx-allow: S1 retail joins the four failures on one error value */
    }
    if (lbl_12_bss_96A0__fzgx_offset_4C.buf0 == 0 || lbl_12_bss_96A0__fzgx_offset_4C.buf1 == 0) {
        for (i = 0; i < 2; i++) {
            if (lbl_12_bss_96A0__fzgx_offset_44[i] == 0) {
                err = -1;
                goto done; /* fzgx-allow: S1 */
            }
        }
        for (i = 0; i < lbl_12_bss_96A0__fzgx_offset_4C.count; i++) {
            if (lbl_12_bss_96A0__fzgx_offset_4[i] == 0) {
                err = -1;
                goto done; /* fzgx-allow: S1 */
            }
        }
    }
    err = 0;
done:
    if (err != 0) {
        return fn_12_24A88(movie, 0xff000f15);
    }

    setup->info = lbl_12_bss_96A0__fzgx_offset_4C;
    memcpy(setup->pair, lbl_12_bss_96A0__fzgx_offset_44, 8);
    memcpy(setup->bufs, lbl_12_bss_96A0__fzgx_offset_4, 0x40);
    setup->field000 = 0;
    setup->field070 = 0;
    setup->field074 = 5;
    setup->field078 = 0xc0;
    setup->field100 = 0;
    setup->field104 = 1;
    setup->field07c = 0;
    setup->field080 = 0;
    setup->field128 = 0;
    setup->field12c = 0;
    setup->field130 = 0;
    for (i = 0, bp = (u32 *)setup, ch = setup->ch; i < 16; i++, bp++, ch++) {
        ch->field00 = 0;
        ch->buf = bp[12];
        ch->field08 = 0;
        ch->field0c = 1;
        ch->field10 = 0;
        ch->field14 = 0;
        ch->field18 = 0;
        ch->field1c = 0;
        ch->field20 = 0;
        fn_12_33428(ch->queue, -1, 0x14);
    }
    setup->field084 = 0;
    setup->field088 = 0;
    fn_12_33428(setup->queue, -1, 0x14);
    setup->field0dc = -1;
    setup->field0e0 = 0;
    setup->field0e4 = 0x7fffffff;
    setup->field0e8 = 0;
    setup->field0ec = 0;
    setup->field0f0 = 0;
    setup->field0f4 = -1;
    setup->field0f8 = 0;
    setup->field0fc = -1;
    setup->field8b8 = 0;
    setup->field8bc = 0;
    setup->field8c0 = 0;
    setup->field8c4 = 0;
    setup->field8c8 = 0;
    for (j = 0; j < 16; j++) {
        setup->slots[j][0] = 0;
        setup->slots[j][1] = 0;
    }
    for (k = 0; k < 16; k++) {
        setup->ch[k].slot = setup->slots[k];
    }
    return 0;
}
/* fzgx:end fn_12_26D68 */

/* fzgx:begin fn_12_270AC noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_270AC.c --- */
typedef struct MovieObject {
    u8 pad_0038[0x38];
    int field_0038;
    u8 pad_003c[0x1af4];
    void *field_1b30;
    u8 pad_1b34[0x38c];
    void *field_1ec0;
} MovieObject;

extern int fn_12_2D73C(MovieObject *, int);
extern int fn_12_26D68(MovieObject *, void *);
extern void *fn_12_CF2C(void);
extern int fn_12_24A88(MovieObject *, int);
extern void fn_12_26D24(void);
extern int fn_12_A6E8(void *, void (*)(void), MovieObject *);
extern void fn_12_CBC8(void *);
extern void fn_12_CAE4(void *, int, int);

int fn_12_270AC(MovieObject *movie) {
    void *movie_data;
    void *movie_slot;
    int result;

    if (fn_12_2D73C(movie, 5) == 0) {
        return 0;
    }

    movie_data = &movie->field_1ec0;
    movie->field_1b30 = movie_data;
    result = fn_12_26D68(movie, movie_data);
    if (result != 0) {
        return result;
    }

    movie_slot = fn_12_CF2C();
    if (movie_slot == 0) {
        return fn_12_24A88(movie, (int)0xff000f0a);
    }

    if (fn_12_A6E8(movie_slot, fn_12_26D24, movie) != 0) {
        fn_12_CBC8(movie_slot);
        return fn_12_24A88(movie, (int)0xff000f0b);
    }

    fn_12_CAE4(movie_slot, 1, fn_12_2D73C(movie, 0));
    fn_12_CAE4(movie_slot, 2, fn_12_2D73C(movie, 1));
    fn_12_CAE4(movie_slot, 3, 0);
    fn_12_CAE4(movie_slot, 4, 0);
    fn_12_CAE4(movie_slot, 5, 0);
    fn_12_CAE4(movie_slot, 6, movie->field_0038);
    fn_12_CAE4(movie_slot, 7, 0x7fffffff);
    fn_12_CAE4(movie_slot, 8, 0);
    fn_12_CAE4(movie_slot, 9, 0);
    *(void **)movie_data = movie_slot;
    return 0;
}
/* fzgx:end fn_12_270AC */

/* fzgx:begin fn_12_27224 noprologue */
/* --- rel/movie_module/fn_12_27224.c --- */
typedef struct Sig_fn_12_2AB68_MovieEntry {
    int used;
    u8 pad[0x74];
} Sig_fn_12_2AB68_MovieEntry;

typedef struct Sig_fn_12_2AB68_MovieList {
    u8 pad[0x134];
    int count;
    Sig_fn_12_2AB68_MovieEntry entries[1];
} Sig_fn_12_2AB68_MovieList;

typedef struct Sig_fn_12_2AB68_MovieObject {
    u8 pad[0x1b30];
    Sig_fn_12_2AB68_MovieList *list;
} Sig_fn_12_2AB68_MovieObject;

struct Sig_fn_12_2AAD4_fn_12_2AAD4_Arg0 {
    u32 unk_0;
};

struct fn_12_27224_Arg0 {
    u8 pad_0[0x1B30];
    u32 list_1b30;
};

struct fn_12_27224_Copy16 { u32 a[4]; };
struct fn_12_27224_Copy80 { u32 a[20]; };

extern Sig_fn_12_2AB68_MovieEntry * fn_12_2AB68(Sig_fn_12_2AB68_MovieObject *);
extern u32 fn_12_2AAD4(struct Sig_fn_12_2AAD4_fn_12_2AAD4_Arg0 *);

#pragma opt_common_subs off
static inline u32 fn_12_27224_operand(u32 right, u32 left) { return left * right; }
s32 fn_12_27224(struct fn_12_27224_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 list_bits;
    u32 entry_130;
    u32 self_bits;
    void *copy_dst;
    u32 row_half;
    s32 w_in;
    s32 h_in;
    s32 w_tiles;
    s32 w_align16;
    s32 h_align32;
    s32 h_tiles;
    s32 h_align16;
    s32 offset_cur;
    s32 offset_half;
    u32 table;
    u32 row_cur;
    Sig_fn_12_2AB68_MovieEntry * t0;

    list_bits = arg0->list_1b30;
    entry_130 = *(u32 *)((u8 *)list_bits + 304);
    self_bits = (u32)arg0;

    if (0 != entry_130) {
        *(u32 *)((u8 *)arg3 + 0) = entry_130;
    } else {
        t0 = (Sig_fn_12_2AB68_MovieEntry *)(fn_12_2AB68((Sig_fn_12_2AB68_MovieObject *)self_bits));
        self_bits = (u32)(t0);
        *(u32 *)((u8 *)arg3 + 0) = (u32)(self_bits);

        if (*(u32 *)((u8 *)arg3 + 0) == 0) {
            *(u32 *)((u8 *)(u32)arg0 + 2416) = 1;
            return -1;
        }
    }

    copy_dst = (void *)(((u8 *)*(u32 *)((u8 *)arg3 + 0) + 40));
    *(struct fn_12_27224_Copy80 *)copy_dst = *(struct fn_12_27224_Copy80 *)arg1;

    if (*(s32 *)((u8 *)(u32)arg0 + 56) == 3) {
        if ((s32)*(u32 *)((u8 *)arg1 + 24) == 1 || (s32)*(u32 *)((u8 *)arg1 + 24) == 2) {
            if (*(u32 *)((u8 *)list_bits + 304) == 0) {
                fn_12_2AAD4((struct Sig_fn_12_2AAD4_fn_12_2AAD4_Arg0 *)*(u32 *)((u8 *)list_bits + 296));
                *(u32 *)((u8 *)list_bits + 296) = *(u32 *)((u8 *)list_bits + 300);
                *(u32 *)((u8 *)list_bits + 300) = *(u32 *)((u8 *)arg3 + 0);
            }
        }

        w_in = (s32)*(u32 *)((u8 *)arg1 + 0);
        h_in = (s32)*(u32 *)((u8 *)arg1 + 4);
        w_tiles = (w_in + 15) / 16;
        w_align16 = w_tiles << 4;
{
        u32 w_align32;
        self_bits = ((w_align16 + 31) / 32) << 5;
        w_align32 = self_bits;
        *(s16 *)((u8 *)arg2 + 14) = w_align32;
        h_align32 = (((((w_tiles >> 27) & 0x1) + w_align16) >> 1) + 31) / 32 << 5;
        h_tiles = (h_in + 15) / 16;
        *(s16 *)((u8 *)arg2 + 12) = h_align32;
        h_align16 = h_tiles << 4;
        offset_cur = (h_align16 * w_align32);
        *(u32 *)(((8) + ((u8 *)arg2))) = *(u32 *)((u8 *)*(u32 *)((u8 *)list_bits + 296) + 4);
        *(u32 *)((u8 *)arg2 + 0) = (*(u32 *)(((8) + ((u8 *)arg2))) + offset_cur);
        offset_half = fn_12_27224_operand(h_align32, ((((h_tiles >> 27) & 0x1) + h_align16) >> 1));
        *(u32 *)((u8 *)arg2 + 4) = (*(u32 *)((u8 *)arg2 + 0) + offset_half);
        *(s16 *)((u8 *)arg2 + 30) = w_align32;
        *(s16 *)((u8 *)arg2 + 28) = h_align32;
        *(u32 *)((u8 *)arg2 + 24) = *(u32 *)((u8 *)*(u32 *)((u8 *)list_bits + 300) + 4);
        *(u32 *)((u8 *)arg2 + 16) = (*(u32 *)((u8 *)arg2 + 24) + offset_cur);
        *(u32 *)((u8 *)arg2 + 20) = (*(u32 *)((u8 *)arg2 + 16) + offset_half);
}
    } else {
        if ((s32)*(u32 *)((u8 *)arg1 + 24) == 1 || (s32)*(u32 *)((u8 *)arg1 + 24) == 2) {
            *(u32 *)((u8 *)list_bits + 256) = (*(u32 *)((u8 *)list_bits + 256) ^ 1);
            *(u32 *)((u8 *)list_bits + 260) = (*(u32 *)((u8 *)list_bits + 260) ^ 1);
        }

        table = (264 + list_bits);
        row_cur = (table + (*(u32 *)((u8 *)list_bits + 256) << 4));
        *(struct fn_12_27224_Copy16 *)arg2 = *(struct fn_12_27224_Copy16 *)row_cur;
        row_half = (table + (*(u32 *)((u8 *)list_bits + 260) << 4));
        *(struct fn_12_27224_Copy16 *)((u8 *)arg2 + 16) = *(struct fn_12_27224_Copy16 *)row_half;
    }

    *(u32 *)((u8 *)arg2 + 32) = *(u32 *)((u8 *)*(u32 *)((u8 *)arg3 + 0) + 4);
    *(u32 *)((u8 *)arg2 + 36) = (*(u32 *)((u8 *)arg3 + 0) + 40);
    *(u32 *)((u8 *)arg2 + 40) = 0;
    *(u32 *)((u8 *)arg2 + 44) = 0;
    *(u32 *)((u8 *)(u32)arg0 + 2416) = 0;
    return 0;
}

#pragma opt_common_subs reset
/* fzgx:end fn_12_27224 */

/* fzgx:begin fn_12_27478 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_27478.c --- */
/* sfmpv_DecodeFrm (sfd_mpv.c, CRI Sofdec), GX layout */

typedef struct SJ SJ;
typedef struct MPVContext MPVContext;

typedef struct SfdTimeCode {
    int fields[6];
    int frame_offset;
} SfdTimeCode;

typedef struct SfdMpvTimeCodeSnapshot {
    int valid;
    SfdTimeCode timecode;
    int value;
    int scale;
} SfdMpvTimeCodeSnapshot;

typedef struct SfdMpvDecodeTimer {
    unsigned char reserved_000[0x1C];
    SfdMpvTimeCodeSnapshot initial;
    unsigned char reserved_044[0x50];
    SfdMpvTimeCodeSnapshot current;
    unsigned char reserved_0BC[0x28];
    SfdMpvTimeCodeSnapshot output_start;
    unsigned char reserved_10C[0x14];
    int field_120;
} SfdMpvDecodeTimer;

typedef struct SfdMpvPictureUserData {
    void *buffer;
    int size;
} SfdMpvPictureUserData;

typedef struct SfdMpvFrame {
    int state;
    void *frame_buffer;
    int display_time_value;
    int display_time_scale;
    int field_40;
    int field_44;
    int picture_order;
    int field_4C;
    int field_50;
    SfdMpvPictureUserData *picture_user_buffer;
    unsigned int picture_info[20];
} SfdMpvFrame;

typedef struct MPVPictureInfo {
    int fields_00[6];
    int picture_type;
    int fields_1C[6];
    int field_38;
} MPVPictureInfo;

typedef struct MPVFrameBuffers {
    int planes[10];
    int decoded_dct_count;
    int skipped_dct_count;
} MPVFrameBuffers;

typedef struct SfdMpvFrameWork {
    MPVContext *decoder;
    unsigned char reserved_004[0x70];
    int decode_state;
    unsigned char reserved_078[0xC];
    int field_084;
    int field_088;
    MPVPictureInfo picture_info;
    unsigned char reserved_0C4[0x6C];
    SfdMpvFrame *pending_frame;
    unsigned char reserved_134[0x790];
    void *picture_buffer;
    int picture_buffer_size;
} SfdMpvFrameWork;

typedef struct SfdTimerSummary {
    int fields[8];
} SfdTimerSummary;

typedef struct SfdHandle {
    unsigned char reserved_0000[0x38];
    int video_output_format;
    unsigned char reserved_003C[0x918];
    int runtime_field_08;
    int runtime_field_0C;
    unsigned char reserved_095C[0x3C];
    int error_field_0C;
    int error_field_10;
    unsigned char reserved_09A0[0x10];
    int conditions_primary_4;
    unsigned char reserved_09B4[0x30C];
    SfdMpvDecodeTimer timer_state;
    unsigned char reserved_0DE4[0x11C];
    int latest_time_value;
    int latest_time_scale;
    unsigned char reserved_0F08[0xC28];
    SfdMpvFrameWork *video_work;
    int video_field_1B34;
    int video_parameter;
    unsigned char reserved_1B3C[0xDDC];
    SfdTimerSummary timer_summaries[4];
} SfdHandle;

extern int fn_12_27224(SfdHandle *handle, MPVPictureInfo *picture, MPVFrameBuffers *buffers,
                       SfdMpvFrame **frame);
extern void *memcpy(void *, const void *, unsigned long);
extern void fn_12_2E374(SfdTimeCode *timecode, int *value, int *scale);
extern unsigned long long fn_12_335B8(void);
extern int fn_80057D88(SJ *stream, int channel, int type);
extern int fn_12_A858(MPVContext *decoder, SJ *stream, MPVFrameBuffers *buffers);
extern void SFTMR_AddTsum(SfdTimerSummary *summary, unsigned long long time);
extern int fn_12_24A88(SfdHandle *handle, int error);
extern void fn_12_21E20(SfdHandle *handle, int parameter, int consumed);
extern void fn_12_2AB54(SfdMpvFrame *frame);
extern void fn_12_2AC80(SfdHandle *handle, int state);
extern void fn_12_2AB2C(SfdMpvFrame *frame);
extern void fn_12_2AB40(SfdMpvFrame *frame);
extern void fn_12_CCB0(MPVContext *decoder, int *decoded, int *skipped);
extern void fn_12_2BA6C(SfdHandle *handle, int count, int picture_type);

static inline void sfmpv_SetVofst(SfdHandle *handle) {
    SfdMpvDecodeTimer *timer = &handle->timer_state;
    SfdMpvTimeCodeSnapshot *initial = &timer->initial;
    SfdMpvTimeCodeSnapshot *output_start = &timer->output_start;
    int mode;
    SfdMpvTimeCodeSnapshot *current = &timer->current;

    if (output_start->valid == 0) {
        SfdTimeCode timecode = current->timecode;
        SfdMpvFrameWork *work = handle->video_work;
        int value;
        int scale;

        mode = 0;
        switch (work->decode_state) {
        case 2:
            mode = 1;
            break;
        case 3:
            mode = 1;
            break;
        case 4:
            mode = 0;
            break;
        case 5:
            break;
        default:
            break;
        }
        if (mode == 0 && handle->conditions_primary_4 != 0) {
            timecode.frame_offset = 0;
        }
        fn_12_2E374(&timecode, &value, &scale);
        output_start->timecode = timecode;
        output_start->value = value - initial->value;
        output_start->scale = scale;
        output_start->valid = 1;
    }
}

static inline int sfmpv_ChkDecRet(SfdHandle *handle, int result, int consumed, int error_code) {
    int error;
    switch (result) {
    case 0:
        error = 0;
        break;
    case -2:
        if (consumed > 0) {
            error = 0;
        } else {
            error = fn_12_24A88(handle, -2);
        }
        break;
    case -3:
        if (consumed > 0) {
            error = 0;
        } else {
            error = fn_12_24A88(handle, -3);
        }
        break;
    case -1:
    default:
        error = fn_12_24A88(handle, error_code);
        break;
    }
    return error;
}

static inline void sfmpv_SetFrmTime(SfdHandle *handle, SfdMpvFrame *frame) {
    SfdMpvDecodeTimer *timer = &handle->timer_state;
    frame->display_time_scale = timer->current.scale;
    frame->display_time_value = timer->field_120 + (timer->current.value - timer->output_start.value);
    frame->field_4C = timer->current.value;
    frame->field_50 = timer->current.value + timer->field_120;
    if (handle->latest_time_value < frame->display_time_value) {
        handle->latest_time_value = frame->display_time_value;
        handle->latest_time_scale = frame->display_time_scale;
    }
}

int fn_12_27478(SfdHandle *handle, SJ *stream) {
    int result;
    int flow_before;
    int consumed;
    SfdMpvFrameWork *work;
    MPVContext *decoder;
    MPVPictureInfo *picture;
    MPVFrameBuffers buffers;
    SfdMpvFrame *frame;
    unsigned long long start;
    int error;

    work = handle->video_work;
    picture = &work->picture_info;
    decoder = work->decoder;
    if (fn_12_27224(handle, picture, &buffers, &frame) != 0) {
        return 0;
    }
    if (work->picture_buffer_size > 0) {
        memcpy(frame->picture_user_buffer->buffer, work->picture_buffer, work->picture_buffer_size);
        frame->picture_user_buffer->size = work->picture_buffer_size;
    }
    sfmpv_SetVofst(handle);

    start = fn_12_335B8();
    flow_before = fn_80057D88(stream, 0, 1);
    result = fn_12_A858(decoder, stream, &buffers);
    consumed = fn_80057D88(stream, 0, 1) - flow_before;
    SFTMR_AddTsum(&handle->timer_summaries[picture->picture_type], fn_12_335B8() - start);
    handle->error_field_0C += buffers.decoded_dct_count;
    handle->error_field_10 += buffers.skipped_dct_count;
    error = sfmpv_ChkDecRet(handle, result, consumed, 0xFF000F06);
    fn_12_21E20(handle, handle->video_parameter, consumed);
    if (error != 0) {
        fn_12_2AB54(frame);
        return error;
    }
    if (consumed > 0) {
        fn_12_2AC80(handle, 0);
        sfmpv_SetFrmTime(handle, frame);
        frame->picture_order = work->field_088;
        frame->field_40 = buffers.decoded_dct_count;
        frame->field_44 = buffers.skipped_dct_count;
        if (picture->field_38 != 3 && work->pending_frame == 0) {
            work->pending_frame = frame;
        } else {
            work->pending_frame = 0;
        }
        if (work->pending_frame == 0) {
            if (handle->video_output_format == 3 &&
                (picture->picture_type == 1 || picture->picture_type == 2)) {
                fn_12_2AB2C(frame);
            } else {
                fn_12_2AB40(frame);
            }
            fn_12_CCB0(decoder, &handle->runtime_field_08, &handle->runtime_field_0C);
            fn_12_2BA6C(handle, 1, picture->picture_type);
            work->field_084 = 0;
        }
    } else if (work->pending_frame == 0) {
        fn_12_2AB54(frame);
    }
    return 0;
}
/* fzgx:end fn_12_27478 */

/* fzgx:begin fn_12_27884 noprologue */
typedef char SfdHandleCheck[(int)&((SfdHandle *)0)->timer_summaries == 0x2918 ? 1 : -1];
typedef char SfdWorkCheck[(int)&((SfdMpvFrameWork *)0)->picture_buffer == 0x8C4 ? 1 : -1];

/* --- rel/movie_module/fn_12_27884.c --- */
typedef struct MovieTimeCode {
    int valid;
    u8 pad_04[0x1C];
    int value;
    int scale;
} MovieTimeCode;
typedef struct MovieDecodeTimer {
    u8 pad_00[0x94];
    MovieTimeCode current;
    u8 pad_bc[0x28];
    MovieTimeCode output_start;
} MovieDecodeTimer;
struct fn_12_27884_Arg0 {
    u8 pad_0[0xCC0];
    MovieDecodeTimer timer;
    u8 pad_dcc[0x1B30 - 0xDCC];
    u32 unk_1B30;
};
typedef struct fn_12_27884_Arg0 MovieModule;
#define I(p, o) (*(int *)((u8 *)(p) + (o)))
#define U(p, o) (*(u32 *)((u8 *)(p) + (o)))
extern int fn_12_332DC(int, int, int, int);
extern u32 fn_12_2D73C(u8 *, int);
extern int fn_12_A374(int, int, int);
extern void fn_12_2EDAC(void *, int);
extern int fn_12_2ED74(void *, int);
extern int fn_12_2DAB4(MovieModule *);
extern int fn_12_2E714(MovieModule *, int *, int *);
extern int fn_12_A9C4(void *, int *, int *);
typedef int (*MovieCallback)(MovieModule *, int, int, int);

static inline int ready(MovieModule *movie) {
    MovieDecodeTimer *timer = &movie->timer;
    MovieTimeCode *current = &timer->current;
    MovieTimeCode *output_start = &timer->output_start;
    if (I(movie, 0x2910) < 0) return 0;
    if (output_start->valid != 0) return 0;
    if (fn_12_332DC(I(movie, 0x2910), I(movie, 0x2914), current->value, current->scale) != 0) return 0;
    return 1;
}
#pragma peephole off
static inline int missing(MovieModule *movie, int mode) {
    int value;
    switch (mode) {
    case 1: value = I(movie, 0x9a8); break;
    case 2: value = I(movie, 0x9ac); break;
    case 3: value = I(movie, 0x9b0); break;
    default: return 1;
    }
    if (value == 0) return 1;
    return 0;
}
#pragma peephole reset

static inline int check_input(MovieModule *movie, int *input, int mode) {
    int result;
    if (mode != 3) return 0;
    if ((int)fn_12_2D73C((u8 *)movie, 7) != 0) return 0;
    result = fn_12_A374(input[0], input[1], I(movie, 0x914) * I(movie, 0x918));
    if (0 != result) I(movie, 0x95c)++;
    return result;
}
static inline int check_state(MovieModule *movie, int mode) {
    void *work = (void *)movie->unk_1B30;
    int state = I(work, 0x74);
    int result = 0;
    switch (state) {
    case 2:
        if (mode == 2 || mode == 3) result = 1;
        break;
    case 3:
        if (mode == 3) result = 1;
        break;
    case 4:
        result = 0;
        break;
    case 5:
    default:
        break;
    }
    return result;
}
static inline int check_time(MovieModule *movie, int mode) {
    void *data = (void *)movie->unk_1B30;
    int time;
    int duration;
    u8 *p = (u8 *)movie + 0xcc0;
    MovieCallback callback;
    struct { int value; } state;
    int value;
    if (I(p, 0xe4) == 0) time = 0;
    else time = I(p, 0x120) + (I(p, 0xb4) - I(p, 0x104));
    callback = *(MovieCallback *)(p + 0x18);
    duration = I(p, 0xb8);
    if (callback != 0) return callback(movie, mode, time, duration);
    if (mode == 1) fn_12_2EDAC(p, time);
    if (mode == 1 || mode == 2) time = fn_12_2ED74(p, time);
    if (fn_12_2DAB4(movie) <= 1000 && I(data, 0x84) >= I(movie, 0xa38)) return 0;
    fn_12_2E714(movie, &state.value, &value);
    if (state.value < 0) return 0;
    time -= duration * I(movie, 0xa48) / I(movie, 0xa4c);
    if (fn_12_332DC(state.value, value, time, duration) != 0) return 0;
    I(data, 0x84)++;
    return 1;
}
static inline void update_pic_stat(MovieModule *movie, void *v0, int skip) {
    void *work = (void *)movie->unk_1B30;
    void *decoder = *(void **)work;
    int state = I(work, 0x74);
    if (I(work, 0xe0) != 0) {
        int a;
        int b;
        fn_12_A9C4(decoder, &a, &b);
        if (a == 0 && b == 1) state = 2;
        if (a == 1) state = 5;
    }
    if (skip == 1) {
        if (I(v0, 0xa4) == 1 || I(v0, 0xa4) == 2) state = 2;
    } else {
        if (state == 2) state = 3;
        else if (state == 3) state = 5;
    }
    I(work, 0x74) = state;
}

#pragma opt_propagation off
int fn_12_27884(MovieModule *arg0, int *arg1) {
    void *v0;
    int v4;
    int v3;
    v0 = (void *)arg0->unk_1B30;
    if ((int)fn_12_2D73C((u8 *)arg0, 47) == 1) return 1;
    if ((int)fn_12_2D73C((u8 *)arg0, 39) == 1) return 0;
    if (U(v0, 0x130) != 0) return 0;
    v3 = I(v0, 0xa4);
    if (ready(arg0)) v4 = 1;
    else if (missing(arg0, v3)) v4 = 1;
    else if (check_input(arg0, arg1, v3)) v4 = 1;
    else if (check_state(arg0, v3)) v4 = 1;
    else if (check_time(arg0, v3)) v4 = 1;
    else v4 = 0;
    update_pic_stat(arg0, v0, v4);
    return v4;
}
#pragma opt_propagation reset
/* fzgx:end fn_12_27884 */

/* fzgx:begin fn_12_27C58 noprologue */
#include "types.h"
typedef struct MPVMCContext MPVMCContext;
typedef struct SfdAudioOutputCallbacks SfdAudioOutputCallbacks;
typedef struct SfdSeeWork SfdSeeWork;
typedef struct SfdVideoFrameState SfdVideoFrameState;
typedef struct fn_12_26C0C_SfdHandle fn_12_26C0C_SfdHandle;
typedef struct fn_12_27C58_SJ fn_12_27C58_SJ;
typedef struct fn_12_27C58_SJInterface fn_12_27C58_SJInterface;
typedef struct fn_12_27C58_SfdMpvPictureUserData fn_12_27C58_SfdMpvPictureUserData;
typedef struct fn_12_27C58_SfdTransportSetup fn_12_27C58_SfdTransportSetup;
#include "sofdec/sj.h"
#include "rel/movie_module/data/lbl_12_rodata_A18.h"

typedef struct MovieArgs {
    u32 field_0000;
    u32 field_0004;
} MovieArgs;

typedef struct fn_12_270AC_MovieObject {
    u8 pad_0038[0x38];
    int field_0038;
    u8 pad_003c[0x1af4];
    void *field_1b30;
    u8 pad_1b34[0x38c];
    void *field_1ec0;
} fn_12_270AC_MovieObject;

typedef struct SfdCreateConfig {
    union {
        unsigned char padding_extent[68];
        struct {
            unsigned char padding_video_output_format[56];
            int video_output_format;
        } view_video_output_format;
    } fields;
} SfdCreateConfig;

typedef struct fn_12_27C58_SfdTransportState {
    union {
        unsigned char padding_extent[68];
        struct {
            unsigned char padding_context[8];
            void *context;
        } view_context;
        struct {
            unsigned char padding_state[32];
            int state;
        } view_state;
    } fields;
} fn_12_27C58_SfdTransportState;

typedef struct fn_12_27C58_SfdHandle fn_12_27C58_SfdHandle;

struct fn_12_27C58_SfdHandle {
    union {
        unsigned char padding_extent[13720];
        struct {
            SfdCreateConfig create_config;
        } view_create_config;
        struct {
            unsigned char padding_transports[6816];
            fn_12_27C58_SfdTransportState transports[9];
        } view_transports;
    } fields;
};

typedef int (*SfdTransportLifecycleFn)(fn_12_27C58_SfdHandle *handle);

typedef int (*SfdTransportPauseFn)(fn_12_27C58_SfdHandle *handle, int state);

typedef int (*SfdTransportBufferFn)(fn_12_27C58_SfdHandle *handle, void *buffer);

typedef int SfdTransportValue;

typedef int (*SfdTransportTransferFn)(fn_12_27C58_SfdHandle *handle, SfdTransportValue parameter, int value);

typedef struct SfdTransportInterface SfdTransportInterface;

struct SfdTransportInterface {
    SfdTransportLifecycleFn init;
    SfdTransportLifecycleFn finish;
    SfdTransportLifecycleFn exec_server;
    SfdTransportLifecycleFn create;
    SfdTransportLifecycleFn destroy;
    SfdTransportLifecycleFn standby;
    SfdTransportLifecycleFn start;
    SfdTransportLifecycleFn stop;
    SfdTransportPauseFn pause;
    SfdTransportBufferFn get_write;
    SfdTransportTransferFn add_write;
    SfdTransportBufferFn get_read;
    SfdTransportTransferFn add_read;
    SfdTransportTransferFn seek;
};

typedef struct fn_12_298AC_SfdTransportState {
    int prepared;
    int terminated;
    void *context;
    const SfdTransportInterface *interface;
    int parameter_10;
    int parameter_14;
    int parameter_18;
    int buffer_output3;
    int state;
    unsigned char unknown_0024[0x20];
} fn_12_298AC_SfdTransportState;

typedef struct fn_12_298AC_SfdHandle fn_12_298AC_SfdHandle;

struct fn_12_298AC_SfdHandle {
    unsigned char unknown_0000[0x28];
    int ring_alignment;
    unsigned char unknown_002C[0x1AA0 - 0x2C];
    fn_12_298AC_SfdTransportState transports[9];
};

typedef struct MovieBlob {
    s32 field_0000[10];
} MovieBlob;

typedef struct fn_12_267C0_MovieState {
    void *field_0000;
    u8 pad04[0x70];
    s32 field_0074;
    s32 field_0078;
    u8 pad7c[0xc];
    s32 field_0088;
} fn_12_267C0_MovieState;

typedef struct fn_12_267C0_MovieData {
    s32 ready;
    u8 pad04[8];
    MovieBlob blob;
    u8 pad34[0x200];
    s32 field_0234;
} fn_12_267C0_MovieData;

typedef struct fn_12_267C0_MovieObject {
    u8 pad_0000[0xcdc];
    MovieBlob blob;
    u8 pad_0d04[0xe2c];
    fn_12_267C0_MovieState *state;
    u8 pad_1b34[0xdd4];
    fn_12_267C0_MovieData *movie;
} fn_12_267C0_MovieObject;

typedef struct fn_12_27478_SfdTimeCode {
    int fields[6];
    int frame_offset;
} fn_12_27478_SfdTimeCode;

typedef struct fn_12_27478_SfdMpvTimeCodeSnapshot {
    int valid;
    fn_12_27478_SfdTimeCode timecode;
    int value;
    int scale;
} fn_12_27478_SfdMpvTimeCodeSnapshot;

typedef struct fn_12_27478_SfdMpvDecodeTimer {
    unsigned char reserved_000[0x1C];
    fn_12_27478_SfdMpvTimeCodeSnapshot initial;
    unsigned char reserved_044[0x50];
    fn_12_27478_SfdMpvTimeCodeSnapshot current;
    unsigned char reserved_0BC[0x28];
    fn_12_27478_SfdMpvTimeCodeSnapshot output_start;
    unsigned char reserved_10C[0x14];
    int field_120;
} fn_12_27478_SfdMpvDecodeTimer;

typedef struct MPVContext MPVContext;

struct MPVContext {
    union {
        unsigned char padding_extent[4992];
        struct {
            unsigned char padding_state[392];
            s32 state;
        } view_state;
    } fields;
};

typedef struct fn_12_27478_MPVPictureInfo {
    int fields_00[6];
    int picture_type;
    int fields_1C[6];
    int field_38;
} fn_12_27478_MPVPictureInfo;

typedef struct fn_12_27478_SfdMpvPictureUserData {
    void *buffer;
    int size;
} fn_12_27478_SfdMpvPictureUserData;

typedef struct fn_12_27478_SfdMpvFrame {
    int state;
    void *frame_buffer;
    int display_time_value;
    int display_time_scale;
    int field_40;
    int field_44;
    int picture_order;
    int field_4C;
    int field_50;
    fn_12_27478_SfdMpvPictureUserData *picture_user_buffer;
    unsigned int picture_info[20];
} fn_12_27478_SfdMpvFrame;

typedef struct fn_12_27478_SfdMpvFrameWork {
    MPVContext *decoder;
    unsigned char reserved_004[0x70];
    int decode_state;
    unsigned char reserved_078[0xC];
    int field_084;
    int field_088;
    fn_12_27478_MPVPictureInfo picture_info;
    unsigned char reserved_0C4[0x6C];
    fn_12_27478_SfdMpvFrame *pending_frame;
    unsigned char reserved_134[0x790];
    void *picture_buffer;
    int picture_buffer_size;
} fn_12_27478_SfdMpvFrameWork;

typedef struct fn_12_27478_SfdTimerSummary {
    int fields[8];
} fn_12_27478_SfdTimerSummary;

typedef struct fn_12_27478_SfdHandle {
    unsigned char reserved_0000[0x38];
    int video_output_format;
    unsigned char reserved_003C[0x918];
    int runtime_field_08;
    int runtime_field_0C;
    unsigned char reserved_095C[0x3C];
    int error_field_0C;
    int error_field_10;
    unsigned char reserved_09A0[0x10];
    int conditions_primary_4;
    unsigned char reserved_09B4[0x30C];
    fn_12_27478_SfdMpvDecodeTimer timer_state;
    unsigned char reserved_0DE4[0x11C];
    int latest_time_value;
    int latest_time_scale;
    unsigned char reserved_0F08[0xC28];
    fn_12_27478_SfdMpvFrameWork *video_work;
    int video_field_1B34;
    int video_parameter;
    unsigned char reserved_1B3C[0xDDC];
    fn_12_27478_SfdTimerSummary timer_summaries[4];
} fn_12_27478_SfdHandle;

typedef struct fn_12_284F8_SfdPlaybackSettings {
    int unk_0;
    int unk_4;
    int unk_8;
    int unk_C;
    int unk_10;
    int frame_rate_code;
    u8 unk_18[8];
    int unk_20;
} fn_12_284F8_SfdPlaybackSettings;

typedef struct fn_12_284F8_SfdTimeCode {
    int frame_rate_code;
    int drop_frame;
    int hours;
    int minutes;
    int seconds;
    int frames;
    int frame_offset;
} fn_12_284F8_SfdTimeCode;

typedef struct fn_12_284F8_SfdMpvTimeCodeSnapshot {
    int valid;
    fn_12_284F8_SfdTimeCode timecode;
    int value;
    int scale;
} fn_12_284F8_SfdMpvTimeCodeSnapshot;

typedef struct fn_12_284F8_SfdMpvDecodeTimer {
    u8 unk_000[0x1C];
    fn_12_284F8_SfdMpvTimeCodeSnapshot initial;
    fn_12_284F8_SfdMpvTimeCodeSnapshot maximum;
    u8 unk_06C[0x28];
    fn_12_284F8_SfdMpvTimeCodeSnapshot current;
    u8 unk_0BC[0x58];
} fn_12_284F8_SfdMpvDecodeTimer;

typedef struct fn_12_284F8_MPVPictureInfo {
    int width;
    int height;
    int macroblocks_per_row;
    int macroblock_rows;
    int frame_rate_code;
    int temporal_reference;
    int picture_type;
    int drop_frame_flag;
    int time_code_hours;
    int time_code_minutes;
    int time_code_seconds;
    int time_code_pictures;
    int unk_30;
} fn_12_284F8_MPVPictureInfo;

typedef struct Entry {
    int unk_0;
    int unk_4;
    int unk_8;
} Entry;

typedef struct fn_12_284F8_SfdMpvFrameWork {
    void *decoder;
    u8 unk_004[0x84];
    int unk_88;
    fn_12_284F8_MPVPictureInfo picture_info;
    u8 unk_0C0[0x1C];
    int unk_DC;
    int unk_E0;
    int unk_E4;
    int unk_E8;
    int unk_EC;
    int unk_F0;
    Entry unk_F4;
    u8 unk_100[0x7C0];
    void *picture_buffer;
    int picture_buffer_size;
    int unk_8C8;
} fn_12_284F8_SfdMpvFrameWork;

typedef struct SeekBuffer {
    u8 unk_0[0x200];
    int unk_200;
} SeekBuffer;

typedef struct SeekEntry {
    int unk_0;
    int unk_4;
    int unk_8;
    fn_12_284F8_SfdMpvTimeCodeSnapshot unk_C;
    SeekBuffer unk_34;
} SeekEntry;

typedef struct SeekWork {
    u8 unk_0[0xAC4];
    SeekEntry unk_AC4;
} SeekWork;

typedef struct fn_12_284F8_SfdHandle {
    u8 unk_0000[0x90C];
    fn_12_284F8_SfdPlaybackSettings playback_settings;
    u8 unk_0930[0x390];
    fn_12_284F8_SfdMpvDecodeTimer timer_state;
    int unk_DD4;
    u8 unk_0DD8[0xD58];
    fn_12_284F8_SfdMpvFrameWork *video_work;
    int unk_1B34;
    int video_parameter;
    u8 unk_1B3C[0xDCC];
    SeekWork *seek_work;
} fn_12_284F8_SfdHandle;

typedef struct fn_12_28CC4_SfdTransportSetup {
    u8 reserved_00[0xC];
    const void *audio_transport;
} fn_12_28CC4_SfdTransportSetup;

typedef struct fn_12_28CC4_SfdTimeCode {
    s32 frame_rate_code;
    s32 drop_frame;
    s32 hours;
    s32 minutes;
    s32 seconds;
    s32 frames;
    s32 frame_offset;
} fn_12_28CC4_SfdTimeCode;

typedef struct fn_12_28CC4_SfdMpvTimeCodeSnapshot {
    s32 valid;
    fn_12_28CC4_SfdTimeCode timecode;
    s32 value;
    s32 scale;
} fn_12_28CC4_SfdMpvTimeCodeSnapshot;

typedef struct fn_12_28CC4_SfdMpvDecodeTimer {
    u8 reserved_000[0x1C];
    fn_12_28CC4_SfdMpvTimeCodeSnapshot initial;
    fn_12_28CC4_SfdMpvTimeCodeSnapshot maximum;
    fn_12_28CC4_SfdMpvTimeCodeSnapshot reserved_snapshot;
    fn_12_28CC4_SfdMpvTimeCodeSnapshot current;
    fn_12_28CC4_SfdMpvTimeCodeSnapshot previous;
    u8 reserved_0E4[0x20];
    s32 reference_time_origin;
    u8 reserved_108[0x18];
    s32 reference_time_offset;
    u8 reserved_124[0x88];
    s32 total_samples;
} fn_12_28CC4_SfdMpvDecodeTimer;

typedef struct fn_12_28CC4_SfdMpvFrameWork {
    void *decoder;
    u8 reserved_004[0x74];
    s32 decode_mode;
    u8 reserved_07C[0xC];
    s32 concat_count;
    u8 reserved_08C[0x18];
    s32 picture_type;
} fn_12_28CC4_SfdMpvFrameWork;

typedef struct fn_12_28CC4_SfdHandle {
    fn_12_28CC4_SfdTransportSetup *transport_setup;
    u8 reserved_0004[0x968];
    s32 decode_wait;
    u8 reserved_0970[0x350];
    fn_12_28CC4_SfdMpvDecodeTimer timer;
    u8 reserved_0E70[0xCC0];
    fn_12_28CC4_SfdMpvFrameWork *video_work;
    u8 reserved_1B34[0x4];
    s32 video_buffer;
    u8 reserved_1B3C[0xC];
    s32 video_total;
} fn_12_28CC4_SfdHandle;

typedef struct MovieEntry {
    void *data;
    u32 field04;
    u32 field08;
    u32 field0c;
    u32 field10;
    u32 field14;
    u32 field18;
    u32 field1c;
    u32 field20;
    u32 field24;
    u32 field28;
    u32 field2c;
    u8 payload[0x40];
} MovieEntry;

typedef struct fn_12_26C2C_MovieModule {
    u8 pad[0x1b30];
    MovieEntry *entry;
} fn_12_26C2C_MovieModule;

typedef void (*Sig_fn_12_24A88_MovieCallback)(void *, s32);

typedef struct Sig_fn_12_24A88_MovieObject {
    u8 pad_0000[0x48];
    s32 state;
    u8 pad_004c[0x940];
    Sig_fn_12_24A88_MovieCallback callback;
    void *callback_context;
    s32 callback_data;
} Sig_fn_12_24A88_MovieObject;

typedef struct fn_12_29FF8_MovieModule {
    u8 pad_0000[0x2c];
    int field_2c;
    u8 pad_0030[0x48];
    int field_78;
    u8 pad_007c[0x78];
    int field_f4;
    u8 pad_00f8[0x854];
    int field_94c;
    u8 pad_0950[0x10];
    s32 field_960;
    u8 pad_0964[0x98];
    int field_9fc;
    u8 pad_a00[0x3a4];
    int field_da4;
    u8 pad_da8[0x1c];
    int field_dc4;
    u8 pad_dc8[0xd68];
    void *field_1b30;
    int field_1b34;
    int field_1b38;
    int field_1b3c;
    u8 pad_1b40[0x794];
    int field_22d4;
    u8 pad_22d8[0x8];
    int field_22e0;
} fn_12_29FF8_MovieModule;

typedef struct fn_12_26B18_MovieData {
    unsigned char pad_0[0x14];
    int field_14;
    int field_18;
} fn_12_26B18_MovieData;

struct fn_12_269E4_arg0_1138_E116 {
    u8 pad_0[0x28];
    u32 unk_28;
    u8 pad_2C[0x48];
};

struct fn_12_269E4_Arg0 {
    u8 pad_0[0x38];
    u32 unk_38;
    u8 pad_3C[0x10FC];
    struct fn_12_269E4_arg0_1138_E116 unk_1138[1];
    u8 pad_11AC[0x984];
    u32 unk_1B30;
    u8 pad_1B34[0x8];
    u32 unk_1B3C;
};

struct fn_12_269E4_Arg1 {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u8 pad_38[0x8];
    u32 unk_40;
    u8 pad_44[0x18];
    u32 unk_5C;
    u32 unk_60;
    u32 unk_64;
    u32 unk_68;
    u32 unk_6C;
    u32 unk_70;
    u32 unk_74;
};

struct fn_12_269E4_Arg2 {
    u32 unk_0;
};

typedef struct MovieInfo {
    u32 field00;
    u32 field04;
    u32 field08;
    u32 field0c;
    u32 buf0;      /* 0x10 */
    u32 field14;
    u32 field18;
    s32 count;     /* 0x1c */
    u32 buf1;      /* 0x20 */
} MovieInfo;

typedef struct MovieChannel {
    u32 field00;
    u32 buf;
    u32 field08;
    u32 field0c;
    u32 field10;
    u32 field14;
    u32 field18;
    u32 field1c;
    u32 field20;
    u32 *slot;
    u32 queue[20];
} MovieChannel;

typedef struct MovieSetup {
    u32 field000;
    MovieInfo info;        /* 0x004 */
    u32 pair[2];           /* 0x028 */
    u32 bufs[16];          /* 0x030 */
    u32 field070;
    u32 field074;
    u32 field078;
    u32 field07c;
    u32 field080;
    u32 field084;
    u32 field088;
    u32 queue[20];         /* 0x08c */
    s32 field0dc;
    u32 field0e0;
    s32 field0e4;
    u32 field0e8;
    u32 field0ec;
    u32 field0f0;
    s32 field0f4;
    u32 field0f8;
    s32 field0fc;
    u32 field100;
    u32 field104;
    u8 pad108[0x20];
    u32 field128;
    u32 field12c;
    u32 field130;
    u32 pad134;
    MovieChannel ch[16];   /* 0x138 */
    u32 field8b8;
    u32 field8bc;
    u32 field8c0;
    u32 field8c4;
    u32 field8c8;
    u32 slots[16][2];      /* 0x8cc */
} MovieSetup;

typedef void (*MPVErrorCallback)(void *object, int error);

typedef struct fn_12_27C58_SfdMpvFrame {
    union {
        unsigned char padding_extent[120];
        struct {
            int state;
        } view_state;
        struct {
            unsigned char padding_frame_buffer[4];
            void *frame_buffer;
        } view_frame_buffer;
        struct {
            unsigned char padding_display_time_value[8];
            int display_time_value;
        } view_display_time_value;
        struct {
            unsigned char padding_display_time_scale[12];
            int display_time_scale;
        } view_display_time_scale;
        struct {
            unsigned char padding_field_40[16];
            int field_40;
        } view_field_40;
        struct {
            unsigned char padding_field_44[20];
            int field_44;
        } view_field_44;
        struct {
            unsigned char padding_picture_order[24];
            int picture_order;
        } view_picture_order;
        struct {
            unsigned char padding_field_4C[28];
            int field_4C;
        } view_field_4C;
        struct {
            unsigned char padding_field_50[32];
            int field_50;
        } view_field_50;
        struct {
            unsigned char padding_picture_info[40];
            unsigned int picture_info[20];
        } view_picture_info;
    } fields;
} fn_12_27C58_SfdMpvFrame;

typedef struct Sig_fn_12_2AB68_MovieEntry {
    int used;
    u8 pad[0x74];
} Sig_fn_12_2AB68_MovieEntry;

typedef struct Sig_fn_12_2AB68_MovieList {
    u8 pad[0x134];
    int count;
    Sig_fn_12_2AB68_MovieEntry entries[1];
} Sig_fn_12_2AB68_MovieList;

typedef struct Sig_fn_12_2AB68_MovieObject {
    u8 pad[0x1b30];
    Sig_fn_12_2AB68_MovieList *list;
} Sig_fn_12_2AB68_MovieObject;

struct Sig_fn_12_2AAD4_fn_12_2AAD4_Arg0 {
    u32 unk_0;
};

struct fn_12_27224_Arg0 {
    u8 pad_0[0x1B30];
    u32 list_1b30;
};

typedef struct fn_12_28CC4_SJCK {
    unsigned char *data;
    long len;
} fn_12_28CC4_SJCK;

typedef struct fn_12_28CC4_SJ fn_12_28CC4_SJ;

typedef struct fn_12_28CC4_SJInterface {
    void *reserved[6];
    void (*get_chunk)(fn_12_28CC4_SJ *sj, int channel, int max_size, fn_12_28CC4_SJCK *chunk);
    void (*unget_chunk)(fn_12_28CC4_SJ *sj, int channel, fn_12_28CC4_SJCK *chunk);
    void (*put_chunk)(fn_12_28CC4_SJ *sj, int channel, fn_12_28CC4_SJCK *chunk);
} fn_12_28CC4_SJInterface;

struct fn_12_28CC4_SJ {
    const fn_12_28CC4_SJInterface *interface;
};

typedef struct fn_12_27478_MPVFrameBuffers {
    int planes[10];
    int decoded_dct_count;
    int skipped_dct_count;
} fn_12_27478_MPVFrameBuffers;

typedef struct SfdMpvPlaybackSettings {
    union {
        unsigned char padding_extent[64];
        struct {
            int width;
        } view_width;
        struct {
            unsigned char padding_height[4];
            int height;
        } view_height;
    } fields;
} SfdMpvPlaybackSettings;

typedef struct SfdTimerTimeUnit {
    int active;
    int fields_04[7];
    unsigned short field_20;
    unsigned short field_22;
    int value;
    int scale;
} SfdTimerTimeUnit;

typedef struct fn_12_28304_SfdTimeCode {
    int frame_rate_code;
    int drop_frame;
    int hours;
    int minutes;
    int seconds;
    int frames;
    int frame_offset;
} fn_12_28304_SfdTimeCode;

typedef struct fn_12_28304_SfdMpvTimeCodeSnapshot {
    int valid;
    fn_12_28304_SfdTimeCode timecode;
    int value;
    int scale;
} fn_12_28304_SfdMpvTimeCodeSnapshot;

typedef struct fn_12_28304_SfdMpvDecodeTimer {
    unsigned char reserved_000[0x1C];
    fn_12_28304_SfdMpvTimeCodeSnapshot initial;
    fn_12_28304_SfdMpvTimeCodeSnapshot maximum;
} fn_12_28304_SfdMpvDecodeTimer;

typedef struct fn_12_28304_SfdHandle {
    unsigned char reserved_0000[0xCC0];
    fn_12_28304_SfdMpvDecodeTimer timer_state;
    unsigned char reserved_0D2C[0x1BDC];
    void *seek_work;
} fn_12_28304_SfdHandle;

typedef struct fn_12_28304_MPVPictureInfo {
    int width;
    int height;
    int macroblocks_per_row;
    int macroblock_rows;
    int frame_rate_code;
    int temporal_reference;
    int picture_type;
    int drop_frame_flag;
    int time_code_hours;
    int time_code_minutes;
    int time_code_seconds;
    int time_code_pictures;
} fn_12_28304_MPVPictureInfo;

typedef struct fn_12_29524_SJCK {
    unsigned char *data;
    long len;
} fn_12_29524_SJCK;

typedef struct fn_12_29524_SfdBufferTransfer {
    fn_12_29524_SJCK chunks[2];
    int reserved[3];
} fn_12_29524_SfdBufferTransfer;

typedef struct fn_12_28CC4_SfdBufferTransfer {
    fn_12_28CC4_SJCK chunks[2];
    s32 reserved[3];
} fn_12_28CC4_SfdBufferTransfer;
extern s32 fn_12_C218(void *arg0, MovieArgs *args, s32 *result);
extern int fn_12_24A88(int arg0, u32 arg1);
extern u32 fn_12_2D73C(u8 *base, int index);
extern void fn_12_24970();
extern void fn_12_2AB00(void *);
extern void fn_12_24950();
extern int fn_12_2ABF0(void *);
extern fn_12_26B18_MovieData *fn_12_2A9DC(void *, int *);
extern void fn_12_269E4(struct fn_12_269E4_Arg0 *arg0, struct fn_12_269E4_Arg1 *arg1, struct fn_12_269E4_Arg2 *arg2);
extern u32 lbl_12_bss_96A0[28];
extern void *memcpy(void *dst, const void *src, u32 size);
extern s32 fn_12_CBC8(u32 arg0);
extern void fn_12_33428(u32 *dst, u32 value, u32 count);
extern s32 fn_12_26D68(Sig_fn_12_24A88_MovieObject *movie, MovieSetup *setup);
extern void *fn_12_CF2C(void);
extern void fn_12_26D24(Sig_fn_12_24A88_MovieObject *movie, s32 code);
extern int fn_12_A6E8(MPVContext *handle, MPVErrorCallback callback, int object);
extern void fn_12_CAE4(void *, int, int);
fn_12_27C58_SfdMpvFrame *fn_12_2AB68(fn_12_27C58_SfdHandle *handle);
extern u32 fn_12_2AAD4(struct Sig_fn_12_2AAD4_fn_12_2AAD4_Arg0 *);
extern s32 fn_12_27224(struct fn_12_27224_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_12_2E374(u32 arg0, u32 arg1, u32 arg2);
extern s64 fn_12_335B8(void);
extern u32 fn_80057D88(u32 arg0, u32 arg1, u32 arg2);
extern int fn_12_A858(MPVContext *decoder, SJ *stream, fn_12_27478_MPVFrameBuffers *buffers);
extern void SFTMR_AddTsum(fn_12_27478_SfdTimerSummary *summary, unsigned long long time);
extern void fn_12_21E20(fn_12_28CC4_SfdHandle *handle, s32 buffer, s32 size);
extern void fn_12_2AB54(int* value);
extern void fn_12_2AC80(fn_12_27478_SfdHandle *handle, int state);
extern void fn_12_2AB2C(int *value);
extern void fn_12_2AB40(int *arg0);
extern void fn_12_CCB0(MPVContext *decoder, int *decoded, int *skipped);
extern void fn_12_2BA6C(fn_12_27478_SfdHandle *handle, int count, int picture_type);
extern int fn_12_332DC(int a, int b, int c, int d);
extern s32 fn_12_A374(s32 arg0, s32 length, s32 count);
extern void fn_12_2EDAC(void *, int);
extern int fn_12_2ED74(void *, int);
extern int fn_12_A9C4(void *movie, void *out_a, void *out_b);
extern int fn_12_27C58(fn_12_27C58_SfdHandle *, SfdMpvPlaybackSettings *);
void SFTIM_InitTtu(SfdTimerTimeUnit *unit, int scale);
extern const int lbl_12_rodata_E10[];
extern const s32 lbl_12_rodata_C10[9];
extern s32 fn_12_334FC(s32 a, s32 b, s32 c);
extern u32 lbl_12_rodata_C54[9];
extern u32 lbl_12_rodata_C34[8];
extern void fn_12_2814C(s32 value, s32 index, s32 drop, s32 offset, s32 *out);
extern void fn_12_CA84(void *decoder, int size, void *buffer);
extern void fn_12_CA60(void *decoder, int *a, int *b);
extern int fn_12_C2C8(void *decoder, SJ *stream);
extern s32 fn_12_AB60(u32 arg0, u32 arg1);
extern u8 *fn_12_A0D8(u8 *data, s32 size, u32 mask);
extern int fn_12_2CDD0(fn_12_284F8_SfdHandle *handle, int parameter, const unsigned char *delimiter, Entry *entry);
extern unsigned int UTY_MulDiv(int multiplicand, int multiplier, int divisor);
extern s32 memcmp(u32 arg0, u32 arg1, u32 arg2);
extern void fn_12_2D7DC(u8 *base, int index, int value);
extern void fn_12_28304(fn_12_28304_SfdHandle *handle, fn_12_28304_MPVPictureInfo *picture, int pts, int group_changed);
extern int fn_12_AB00(void *obj, int *value);
extern int fn_12_AA38(void *movie, void *out_a, void *out_b, void *out_c);
extern int fn_12_21F38(fn_12_284F8_SfdHandle *handle, int index);
extern void *fn_12_57F0(void *dst, const void *src, u32 size);
extern int fn_12_21E40(void *module, int index, int *movie_id);
extern s32 fn_12_21F28(fn_12_28CC4_SfdHandle *handle, s32 buffer);
extern u32 fn_12_23250(u32 arg0);
extern int fn_12_22FBC(fn_12_28CC4_SfdHandle *handle, s32 *samples, s32 *sample_rate);
extern void fn_12_23120(void *arg0, int arg1);
extern void fn_12_2EE48(fn_12_28CC4_SfdMpvTimeCodeSnapshot *snapshot, s32 value);
extern u32 fn_12_A2C4(const u8 *data);
extern s32 fn_12_231A0(u32 arg0);
extern int fn_12_21D30(fn_12_28CC4_SfdHandle *handle, s32 buffer);
extern void fn_12_2AC98(fn_12_28CC4_SfdHandle *handle);
extern int fn_12_22390(u8 *module, int index, u32 *out);
extern int fn_12_284F8(fn_12_284F8_SfdHandle *handle, SJCK *chunk, SJ *stream, int flag);
extern int fn_12_27884(fn_12_28CC4_SfdHandle *handle, fn_12_28CC4_SJCK *chunk);
extern void fn_12_A7B0(void *movie, SJ *sj);
extern void fn_12_2B9F8(fn_12_28CC4_SfdHandle *handle, s32 count, s32 picture_type);
extern int fn_12_27478(fn_12_27478_SfdHandle *handle, SJ *stream);
extern void fn_12_22008(fn_12_28CC4_SfdHandle *handle, s32 buffer, s32 size);
extern int fn_12_29524(fn_12_29524_SfdBufferTransfer *, int, const unsigned char *);
extern char *fn_12_A1C4(char *text, s32 length, u32 mask);
int fn_12_21C00(fn_12_298AC_SfdHandle *handle, int buffer_index);
extern void fn_12_21F48(u8 *module, int index, void *movie, void *stream);
void fn_12_21FA4(fn_12_298AC_SfdHandle *handle, int buffer_index, unsigned char **position, unsigned char **end_position);
extern int fn_12_23F00(fn_12_29FF8_MovieModule *module);
extern s32 fn_12_24990();
extern int fn_12_298AC(fn_12_298AC_SfdHandle *handle, int *active_size, int *delimiter_type);
extern int fn_12_28CC4(fn_12_28CC4_SfdHandle *handle, s32 active_size, s32 delimiter_type, int *processed);
extern int fn_12_21D50(fn_12_29FF8_MovieModule *module, int value);
extern int fn_12_2AC8C(fn_12_29FF8_MovieModule *module);
extern int fn_12_21E94(fn_12_29FF8_MovieModule *module, int value);
extern int fn_12_2F1B4(fn_12_29FF8_MovieModule *module, int value);
extern void fn_12_21D60(fn_12_29FF8_MovieModule *module, int value, int flag);
extern void fn_12_21D40(void *base, int index, int value);
extern int fn_12_29FF8();
extern void fn_12_D038(void);
extern u8 lbl_12_bss_9710[73760];
extern s32 fn_12_D0B8(s32 id, void *buf);
extern void *memset(void *dst, int c, u32 n);
extern u32 fn_12_2A85C(u32);

/* --- rel/movie_module/fn_12_27C58.c --- */
typedef struct fn_12_27C58_SJCK {
    unsigned char *data;
    long len;
} fn_12_27C58_SJCK;

typedef struct fn_12_27C58_SJ fn_12_27C58_SJ;

typedef struct fn_12_27C58_SJInterface fn_12_27C58_SJInterface;

typedef void (*SJErrorCallback)(void *object, int error);

struct fn_12_27C58_SJInterface {
    void *reserved[3];
    void (*destroy)(fn_12_27C58_SJ *sj);
    const void *(*get_uuid)(fn_12_27C58_SJ *sj);
    void (*reset)(fn_12_27C58_SJ *sj);
    void (*get_chunk)(fn_12_27C58_SJ *sj, long channel, long max_size, fn_12_27C58_SJCK *chunk);
    void (*unget_chunk)(fn_12_27C58_SJ *sj, int channel, fn_12_27C58_SJCK *chunk);
    void (*put_chunk)(fn_12_27C58_SJ *sj, int channel, fn_12_27C58_SJCK *chunk);
    int (*get_num_data)(fn_12_27C58_SJ *sj, int channel);
    int (*is_get_chunk)(fn_12_27C58_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(fn_12_27C58_SJ *sj, SJErrorCallback callback, void *object);
};

struct fn_12_27C58_SJ {
    const fn_12_27C58_SJInterface *interface;
};

typedef struct DctFsriBlock {
    s16 samples[64];
} DctFsriBlock;

typedef struct DctFsriParams {
    union {
        unsigned char padding_extent[84];
        struct {
            unsigned char padding_field_4C[76];
            u8 field_4C[8];
        } view_field_4C;
    } fields;
} DctFsriParams;

typedef struct MPVErrorInfo {
    MPVErrorCallback callback;
    void *callback_object;
    int first_error;
    int field_0C;
    int field_10;
} MPVErrorInfo;

typedef struct MPVMCContext MPVMCContext;

typedef void (*MPVMCFunction)(MPVMCContext *context);

struct MPVMCContext {
    MPVMCFunction functions08[4];
    u8 field_10[8];
    u8 *destination;
    u32 field_1c;
    s32 reference_stride;
    const u8 *reference0;
    const u8 *reference1;
    u8 field_2c[8];
    MPVMCFunction functions16[4];
};

typedef struct MPVPlaneSet {
    union {
        unsigned char padding_extent[16];
        struct {
            u8 *planes[3];
        } view_planes;
        struct {
            unsigned char padding_chroma_stride[12];
            s16 chroma_stride;
        } view_chroma_stride;
        struct {
            unsigned char padding_luma_stride[14];
            s16 luma_stride;
        } view_luma_stride;
    } fields;
} MPVPlaneSet;

typedef struct MPVOutputBlock {
    u8 *destination;
    s32 stride;
} MPVOutputBlock;

typedef struct MPVOutputBlocks {
    s32 count;
    MPVOutputBlock blocks[6];
} MPVOutputBlocks;

typedef struct MPVMacroblockSources {
    void *field_00;
    s16 *residual;
    u8 *prediction0;
    u8 *prediction1;
} MPVMacroblockSources;

typedef struct MPVYccPlane {
    union {
        unsigned char padding_extent[16];
        struct {
            unsigned char padding_chroma_stride[12];
            s16 chroma_stride;
        } view_chroma_stride;
        struct {
            unsigned char padding_luma_stride[14];
            s16 luma_stride;
        } view_luma_stride;
    } fields;
} MPVYccPlane;

typedef struct MPVMotionInfo {
    s32 full_pel;
    s32 r_size;
    s32 shift;
    s32 limit;
    s32 previous_horizontal;
    s32 previous_vertical;
    s32 horizontal;
    s32 vertical;
    u8 field_20[4];
} MPVMotionInfo;

typedef struct MPVPictureAttributes {
    union {
        unsigned char padding_extent[128];
        struct {
            int width;
        } view_width;
        struct {
            unsigned char padding_height[4];
            int height;
        } view_height;
        struct {
            unsigned char padding_field_40[64];
            int field_40;
        } view_field_40;
        struct {
            unsigned char padding_field_44[68];
            int field_44;
        } view_field_44;
        struct {
            unsigned char padding_field_50[80];
            s16 field_50;
        } view_field_50;
    } fields;
} MPVPictureAttributes;

typedef MPVPictureAttributes fn_12_27C58_MPVPictureInfo;

typedef struct fn_12_27C58_MPVFrameBuffers {
    union {
        unsigned char padding_extent[48];
        struct {
            unsigned char padding_picture_info[36];
            fn_12_27C58_MPVPictureInfo *picture_info;
        } view_picture_info;
    } fields;
} fn_12_27C58_MPVFrameBuffers;

typedef struct MPVBitReader {
    u32 bits;
    u32 next_bits;
    s32 bit_offset;
    const u32 *words;
} MPVBitReader;

typedef struct MPVConditionState {
    int conditions[16];
    MPVPictureAttributes picture;
} MPVConditionState;

typedef struct MPVTransformWorkspace {
    DctFsriBlock blocks[6];
    float coefficients[6][64];
} MPVTransformWorkspace;

typedef struct MPVCodingBlock {
    s32 run;
    s32 level;
    s32 sign;
    u32 code_length;
    s32 first_scan;
    s32 current_scan;
    u8 field_18[4];
    void *coefficients;
    const u8 *quant_matrix;
    s32 quantizer_scale;
    s32 *dc_predictor;
    const u8 *dc_size_lut;
} MPVCodingBlock;

typedef struct MPVCodingWorkspace {
    MPVCodingBlock block;
    s32 non_intra_mode;
} MPVCodingWorkspace;

typedef struct MPVUserStream {
    fn_12_27C58_SJ *stream;
    void (*callback)(void *argument, int index);
    void *callback_argument;
} MPVUserStream;

typedef struct MPVPictureUserBuffer {
    void *buffer;
    s32 capacity;
    s32 size;
} MPVPictureUserBuffer;


typedef void *SfdCallbackObject;

typedef int SfdConditionValue;

typedef int (*SfdUserIsSkipFn)(fn_12_27C58_SfdHandle *handle, int picture_type, int value, int scale);

typedef int (*SfdTimeSourceFn)(fn_12_27C58_SfdHandle *handle, int *value, int *scale);

typedef struct fn_12_27C58_SfdPlaybackSettings {
    int values_00[5];
    int frame_rate_code;
    int values_18[10];
} fn_12_27C58_SfdPlaybackSettings;

typedef struct SfdPlaybackRuntime {
    int decoded_pictures;
    int skipped_pictures;
    int field_08;
    int field_0C;
    int field_10;
    int field_14;
    int frame_outstanding;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    long long time_values[12];
    int tail_values[4];
} SfdPlaybackRuntime;


typedef struct SfdTimerSkipState {
    SfdUserIsSkipFn callback;
    int fields_04[7];
    unsigned short field_20;
    unsigned short field_22;
} SfdTimerSkipState;

typedef struct SfdTimerStreamTimeUnit {
    int active;
    int field_04;
    int file_size;
    int total_time_value;
    int total_time_scale;
    int byte_rate;
    int seek_position;
    int field_1C;
    unsigned short field_20;
    unsigned short field_22;
    int value;
    int scale;
} SfdTimerStreamTimeUnit;

typedef struct SfdTimerSampleHistory {
    int fields_00[3];
    int samples[32];
} SfdTimerSampleHistory;

typedef struct SfdTimerSampleWindow {
    int enabled;
    int fields_04[3];
    int samples[32];
} SfdTimerSampleWindow;

typedef struct SfdPtsManager {
    void *field_00;
    int field_04;
    int field_08;
} SfdPtsManager;

typedef struct SfdTimerTestTime {
    long long value;
    long long scale;
} SfdTimerTestTime;

typedef struct SfdTimerTestWork {
    int test_enabled;
    int paused;
    int reset_history;
    int adjust_enabled;
    int average_count;
    int average_index;
    int errors[60];
    SfdTimerTestTime input_time;
    SfdTimerTestTime sample_time;
    SfdTimerTestTime output_time;
    SfdTimerTestTime tolerance;
    SfdTimerTestTime excess_error;
    SfdTimerTestTime adjustment_start;
    SfdTimerTestTime adjustment_offset;
    long long previous_sample;
    long long adjusted_time;
    long long maximum_time;
    int adjustment_count;
    int positive_adjustments;
    int negative_adjustments;
    int history_resets;
    int excess_resets;
    int average;
    int adjusted_average;
    int front_max;
    int front_min;
    int rear_max;
    int rear_min;
    int field_0x1BC;
} SfdTimerTestWork;

typedef int (*SfdExternalClockFn)(SfdCallbackObject object, int *value, int *scale);

typedef struct SfdTimerState {
    SfdTimeSourceFn time_sources[6];
    SfdTimerSkipState skip_state;
    SfdTimerTimeUnit field_003C;
    SfdTimerTimeUnit field_0068;
    SfdTimerStreamTimeUnit stream_time;
    SfdTimerTimeUnit field_00C0;
    SfdTimerTimeUnit video_start_time;
    SfdTimerTimeUnit elapsed_time;
    int start_time_value;
    int start_time_scale;
    int field_014C;
    long long field_0150;
    long long audio_start_pts;
    SfdTimerSampleHistory sample_history;
    SfdTimerSampleWindow sample_window;
    int video_end_time_value;
    int video_end_time_scale;
    int field_0284;
    int field_0288;
    int current_time_value;
    int current_time_scale;
    int interval_time_last;
    int interval_time_estimate;
    int interval_time_max;
    int interval_time_min;
    int field_02A4;
    int video_clock_sample;
    int speed;
    int field_02B0;
    int field_02B4;
    int field_02B8;
    int frame_time_repeat_count;
    float previous_frame_time;
    int previous_frame_ready;
    float last_frame_time;
// Hardware or OS state can change asynchronously.
    volatile int field_02CC;
    int previous_clock_sample;
    SfdExternalClockFn external_clock_callback;
    int previous_external_sample;
    int current_clock_sample;
    int clock_sample_scale;
    int external_clock_wrap;
    SfdCallbackObject external_clock_object;
    int field_02EC;
    SfdTimerTestWork test_work;
    unsigned char unknown_04B0[0x100];
    SfdPtsManager video_pts;
    unsigned char unknown_05BC[0x24];
} SfdTimerState;

typedef struct SfdSeeWork SfdSeeWork;

typedef struct SfdSeekRequest {
    int field_00;
    int position;
    int field_08;
} SfdSeekRequest;

typedef struct SfdSeekState {
    SfdSeeWork *work;
    SfdSeekRequest request;
} SfdSeekState;

typedef void (*SfdErrorCallback)(SfdCallbackObject object, int error);

typedef struct SfdErrorInfo {
    SfdErrorCallback callback;
    SfdCallbackObject callback_object;
    int first_error;
    int field_0C;
    int field_10;
} SfdErrorInfo;

typedef struct SfdHeaderAudioInfo {
    int codec;
    int layer;
    int channel_count;
    int sample_rate;
} SfdHeaderAudioInfo;

typedef struct SfdHeaderVideoInfo {
    union {
        unsigned char padding_extent[52];
        struct {
            unsigned char padding_width[8];
            int width;
        } view_width;
        struct {
            unsigned char padding_height[12];
            int height;
        } view_height;
    } fields;
} SfdHeaderVideoInfo;

typedef struct SfdHeaderState {
    int processed;
    int mux_version_major;
    int mux_version_minor;
    int byte_rate;
    int header_size;
    int pack_type;
    int packet_size_length;
    int pack_size;
    int element_count;
    int audio_element_count;
    int video_element_count;
    int private_element_count;
    int maximum_audio_length;
    int maximum_video_length;
    int maximum_frame_count;
    int private_stream_1;
    int private_stream_2;
    int audio_stream;
    int video_stream;
    SfdHeaderAudioInfo audio;
    SfdHeaderVideoInfo video;
    int raw_header_size;
    unsigned char raw_header[0x800];
} SfdHeaderState;

typedef struct fn_12_27C58_SfdTimerSummary {
    long long total;
    long long minimum;
    long long maximum;
    int count;
    int field_1C;
} fn_12_27C58_SfdTimerSummary;

typedef struct fn_12_27C58_SfdTransportSetup fn_12_27C58_SfdTransportSetup;

typedef struct SfdVideoFrameState SfdVideoFrameState;

typedef void (*SfdBufferHandleCallback)(fn_12_27C58_SfdHandle *handle, int stream_index);

typedef void (*SfdBufferObjectCallback)(SfdCallbackObject object, int stream_index);

typedef struct SfdBufferChannel {
    fn_12_27C58_SJ *stream_joint;
    SfdBufferHandleCallback handle_callback;
    SfdBufferObjectCallback object_callback;
    SfdCallbackObject object;
} SfdBufferChannel;

typedef struct SfdPtsEntry {
    long long pts;
    unsigned char *data;
    int size;
} SfdPtsEntry;

typedef struct SfdPtsQueue {
    SfdPtsEntry *entries;
    int capacity;
    int count;
    int write_index;
    int read_index;
} SfdPtsQueue;

typedef struct SfdBufferSupply {
    int kind;
    fn_12_27C58_SJ *stream_joint;
    unsigned char *buffer;
    int buffer_size;
    int extra_size;
    int field_14;
} SfdBufferSupply;

typedef struct SfdBufferRingWork {
    SfdBufferSupply supply;
    unsigned char *delimiter_position;
    unsigned char *delimiter_end;
    int write_total;
    int read_total;
    SfdPtsQueue pts_queue;
} SfdBufferRingWork;

typedef struct SfdBufferVideoWork {
    unsigned char *buffer;
    int buffer_size;
    int reserved_08;
    int reserved_0C;
    SfdVideoFrameState *video_frames;
} SfdBufferVideoWork;

typedef struct SfdBufferAudioWork {
    unsigned char *buffer;
    int buffer_size;
    int reserved[7];
    int reserved_tail[3];
} SfdBufferAudioWork;

typedef union SfdBufferWork {
    SfdBufferRingWork ring;
    SfdBufferVideoWork video;
    SfdBufferAudioWork audio;
    SfdBufferChannel user_channels[3];
} SfdBufferWork;


typedef struct SfdBufferState {
    int storage_mode;
    int active;
    int prepared;
    int terminated;
    SfdBufferWork work;
    int input_transport;
    int output_transport;
    int reserved_54[8];
} SfdBufferState;

typedef struct SfdVideoFrameInfo {
    union {
        unsigned char padding_extent[128];
        struct {
            unsigned char padding_display_time_scale[24];
            int display_time_value, display_time_scale;
        } view_display_time_scale;
        struct {
            unsigned char padding_frame_buffer[32];
            void *frame_buffer;
        } view_frame_buffer;
    } fields;
} SfdVideoFrameInfo;

struct SfdVideoFrameState {
    union {
        unsigned char padding_extent[136];
        struct {
            int state;
        } view_state;
    } fields;
};

typedef struct SfdBufferCreateConfig {
    const fn_12_27C58_SfdTransportSetup *transport_setup;
    unsigned char *memory;
    int buffer_sizes[7];
    int field_24;
    int ring_alignment;
} SfdBufferCreateConfig;



typedef struct SfdUserOutputWork {
    union {
        unsigned char padding_extent[52];
        struct {
            int state;
        } view_state;
    } fields;
} SfdUserOutputWork;

struct fn_12_27C58_SfdTransportSetup {
    const SfdTransportInterface *entries[9];
};

typedef struct SfdAudioOutputCallbacks SfdAudioOutputCallbacks;

typedef int (*SfdAudioSetPanFn)(fn_12_27C58_SfdHandle *, int, int, SfdAudioOutputCallbacks *);

typedef int (*SfdAudioGetPanFn)(fn_12_27C58_SfdHandle *, int, SfdAudioOutputCallbacks *);

typedef int (*SfdAudioSetVolumeFn)(fn_12_27C58_SfdHandle *, int, SfdAudioOutputCallbacks *);

typedef int (*SfdAudioGetVolumeFn)(fn_12_27C58_SfdHandle *, SfdAudioOutputCallbacks *);

typedef void (*SfdAudioSetSpeedFn)(fn_12_27C58_SfdHandle *, int);

struct SfdAudioOutputCallbacks {
    void *output_context;
    SfdAudioSetPanFn set_pan;
    SfdAudioGetPanFn get_pan;
    SfdAudioSetVolumeFn set_volume;
    SfdAudioGetVolumeFn get_volume;
    SfdAudioSetSpeedFn set_speed;
    int reserved_18;
};


typedef struct fn_12_27C58_SfdMpvPictureUserData fn_12_27C58_SfdMpvPictureUserData;

typedef struct SfdMpvParameters {
    union {
        unsigned char padding_extent[36];
        struct {
            unsigned char padding_width[8];
            s32 width;
        } view_width;
        struct {
            unsigned char padding_height[12];
            s32 height;
        } view_height;
        struct {
            unsigned char padding_reference_buffer[16];
            s32 reference_buffer;
        } view_reference_buffer;
        struct {
            unsigned char padding_frame_count[28];
            s32 frame_count;
        } view_frame_count;
        struct {
            unsigned char padding_frame_buffer[32];
            s32 frame_buffer;
        } view_frame_buffer;
    } fields;
} SfdMpvParameters;


typedef struct fn_12_27C58_SfdMpvFrameWork {
    union {
        unsigned char padding_extent[3968];
        struct {
            unsigned char padding_setup_values[4];
            SfdMpvParameters setup_values;
        } view_setup_values;
        struct {
            unsigned char padding_saved_pair[40];
            void *saved_pair[2];
        } view_saved_pair;
        struct {
            unsigned char padding_address_table[48];
            void *address_table[16];
        } view_address_table;
        struct {
            unsigned char padding_picture_info[140];
            fn_12_27C58_MPVPictureInfo picture_info;
        } view_picture_info;
        struct {
            unsigned char padding_planes[264];
            MPVPlaneSet planes[2];
        } view_planes;
        struct {
            unsigned char padding_reference_frames[296];
            fn_12_27C58_SfdMpvFrame *reference_frames[2];
        } view_reference_frames;
        struct {
            unsigned char padding_frame_count[308];
            int frame_count;
        } view_frame_count;
        struct {
            unsigned char padding_frames[312];
            fn_12_27C58_SfdMpvFrame frames[16];
        } view_frames;
    } fields;
} fn_12_27C58_SfdMpvFrameWork;

struct fn_12_27C58_SfdMpvPictureUserData {
    void *buffer;
    int size;
};







static inline void sfmpv_InitFrame(fn_12_27C58_SfdMpvFrame *frame, void **frame_buffer) {
    frame->fields.view_state.state = 0;

    frame->fields.view_frame_buffer.frame_buffer = *frame_buffer;
    frame->fields.view_display_time_value.display_time_value = 0;
    frame->fields.view_display_time_scale.display_time_scale = 1;
    frame->fields.view_field_40.field_40 = 0;
    frame->fields.view_field_44.field_44 = 0;
    frame->fields.view_picture_order.picture_order = 0;
    frame->fields.view_field_4C.field_4C = 0;
    frame->fields.view_field_50.field_50 = 0;
    fn_12_33428( (u32 *)(unsigned int *)(frame->fields.view_picture_info.picture_info), -1, 20);
}

static inline void sfmpv_InitSavedFrames(fn_12_27C58_SfdMpvFrameWork *work, fn_12_27C58_SfdMpvFrame *frame) {
    int i;
    for (i = 0; i < 2; i++, frame++) {
        sfmpv_InitFrame(frame, &work->fields.view_saved_pair.saved_pair[i]);
    }
}

static inline void sfmpv_InitDecodedFrames(fn_12_27C58_SfdMpvFrameWork *work, fn_12_27C58_SfdMpvFrame *frame, int count) {
    int i;
    for (i = 0; i < count; i++, frame++) {
        sfmpv_InitFrame(frame, &work->fields.view_address_table.address_table[i]);
    }
}

static inline int sfmpv_CalcFrameSize(int width, int height) {
    int aligned_width = ((width + 15) / 16) * 16;
    int aligned_height = ((height + 15) / 16) * 16;
    int luma_size = aligned_height * (((aligned_width + 31) / 32) * 32);
    int chroma_size = (aligned_height / 2) * ((((aligned_width / 2) + 31) / 32) * 32);
    return luma_size + chroma_size * 2 + 0x20;
}

static inline void sfmpv_SetPlane(void **buffer, int luma_stride, int chroma_stride, int luma_size, int chroma_size, MPVPlaneSet *plane) { plane->fields.view_luma_stride.luma_stride = luma_stride;
    plane->fields.view_chroma_stride.chroma_stride = chroma_stride;
    plane->fields.view_planes.planes[2] = *buffer;
    plane->fields.view_planes.planes[0] = plane->fields.view_planes.planes[2] + luma_size;
    plane->fields.view_planes.planes[1] = plane->fields.view_planes.planes[0] + chroma_size;
}

int fn_12_27C58(fn_12_27C58_SfdHandle *handle, SfdMpvPlaybackSettings *settings) {
    fn_12_27C58_SfdMpvFrameWork *work =
        handle->fields.view_transports.transports[2].fields.view_context.context;
    unsigned char *frame_buffer;
    int frame_size;
    int configured_width = work->fields.view_setup_values.setup_values.fields.view_width.width;
    int configured_height = work->fields.view_setup_values.setup_values.fields.view_height.height;
    int width;
    int height;
    int aligned_width;
    int aligned_height;
    int luma_stride;
    int chroma_stride;
    int luma_size;
    int chroma_size;
    int configured_size;
    int requested_count =
        work->fields.view_setup_values.setup_values.fields.view_frame_count.frame_count;
    int frame_count;
    int decoded_count;
    int i;
    unsigned char *reference_buffer;
    fn_12_27C58_SfdMpvFrame *frames = work->fields.view_frames.frames;
    width = settings->fields.view_width.width;
    height = settings->fields.view_height.height;
    aligned_width = ((width + 15) / 16) * 16;
    aligned_height = ((height + 15) / 16) * 16;
    luma_stride = ((aligned_width + 31) / 32) * 32;
    chroma_size = (aligned_height / 2) * (chroma_stride = (((aligned_width / 2) + 31) / 32) * 32);
    luma_size = aligned_height * luma_stride;
    frame_size = luma_size + chroma_size * 2 + 0x20;
    configured_size = sfmpv_CalcFrameSize(configured_width, configured_height);
    if (frame_size * 2 > configured_size * 2) {
        return fn_12_24A88( (int)(fn_12_27C58_SfdHandle *)(handle), 0xFF000F17);
    }
    frame_buffer =
        (unsigned char *)
            work->fields.view_setup_values.setup_values.fields.view_frame_buffer.frame_buffer;
    if (frame_buffer == 0) {
        frame_count = requested_count;
    } else {
        int available_size = requested_count * configured_size;
        int used_size = frame_size;
        for (frame_count = 1; frame_count <= 16; frame_count++) {
            if (used_size > available_size) {
                frame_count--;
                break;
            }
            used_size += frame_size;
        }
        if (frame_count < requested_count) {
            return fn_12_24A88( (int)(fn_12_27C58_SfdHandle *)(handle), 0xFF000F17);
        }
        reference_buffer = (unsigned char *)work->fields.view_setup_values.setup_values.fields
                               .view_reference_buffer.reference_buffer;
        work->fields.view_saved_pair.saved_pair[0] = reference_buffer;
        work->fields.view_saved_pair.saved_pair[1] = reference_buffer + frame_size;
        for (i = 0; i < frame_count; i++) {
            work->fields.view_address_table.address_table[i] = frame_buffer + i * frame_size;
        }
    }
    sfmpv_SetPlane(&work->fields.view_saved_pair.saved_pair[0], luma_stride, chroma_stride,
                   luma_size, chroma_size, &work->fields.view_planes.planes[0]);
    sfmpv_SetPlane(&work->fields.view_saved_pair.saved_pair[1], luma_stride, chroma_stride,
                   luma_size, chroma_size, &work->fields.view_planes.planes[1]);
    if (handle->fields.view_create_config.create_config.fields.view_video_output_format
            .video_output_format == 3) {
        decoded_count = frame_count < 14 ? frame_count : 14;
        work->fields.view_frame_count.frame_count = decoded_count + 2;
        sfmpv_InitSavedFrames(work, frames);
        sfmpv_InitDecodedFrames(work, frames + 2, decoded_count);
        work->fields.view_reference_frames.reference_frames[0] = fn_12_2AB68(handle);
        work->fields.view_reference_frames.reference_frames[1] = fn_12_2AB68(handle);
    } else {
        decoded_count = frame_count < 16 ? frame_count : 16;
        work->fields.view_frame_count.frame_count = decoded_count;
        sfmpv_InitDecodedFrames(work, frames, decoded_count);
    }
    return 0;
}
/* fzgx:end fn_12_27C58 */

/* fzgx:begin fn_12_2814C noprologue */
/* --- rel/movie_module/fn_12_2814C.c --- */

void fn_12_2814C(s32 value, s32 index, s32 drop, s32 offset, s32 *out) {
    s32 rate;
    s32 scale;
    s32 frames;
    s32 fraction;
    s32 seconds;
    s32 rem;
    s32 minutes;
    s32 hours;
    s32 blocks;
    rate = ((s32 *)lbl_12_rodata_C10)[index];
    scale = ((s32 *)(((const s32 *)&lbl_12_rodata_E10)))[index];
    frames = fn_12_334FC(value, scale, 22500000) - offset;
    frames = frames > 0 ? frames : 0;
    if (drop && (scale == 29970 || scale == 59940)) {
        s32 *table = scale == 29970 ? (s32 *)lbl_12_rodata_C34 : (s32 *)lbl_12_rodata_C54;
        hours = frames / table[0];
        rem = frames % table[0];
        blocks = rem / table[1];
        rem %= table[1];
        if (rem < table[2]) {
            minutes = 0;
            seconds = rem / table[5];
            fraction = rem % table[5];
        } else {
            rem -= table[2];
            minutes = rem / table[3] + 1;
            rem %= table[3];
            if (rem < table[4]) {
                seconds = 0;
                fraction = rem + table[7];
            } else {
                rem -= table[4];
                seconds = rem / table[5] + 1;
                fraction = rem % table[5];
            }
        }
        minutes += table[6] * blocks;
    } else {
        seconds = frames / rate;
        fraction = frames % rate;
        minutes = seconds / 60;
        seconds %= 60;
        hours = minutes / 60;
        minutes %= 60;
    }
    out[2] = hours;
    out[3] = minutes;
    out[4] = seconds;
    out[5] = fraction;
}
/* fzgx:end fn_12_2814C */

/* fzgx:begin fn_12_28304 noprologue */
#include "types.h"

/* sfmpv_DoReformTc (sfd_mpv.c, CRI Sofdec), GX version */

typedef struct SfdTimeCode {
    int frame_rate_code;
    int drop_frame;
    int hours;
    int minutes;
    int seconds;
    int frames;
    int frame_offset;
} SfdTimeCode;

typedef struct SfdMpvTimeCodeSnapshot {
    int valid;
    SfdTimeCode timecode;
    int value;
    int scale;
} SfdMpvTimeCodeSnapshot;

typedef struct SfdMpvDecodeTimer {
    unsigned char reserved_000[0x1C];
    SfdMpvTimeCodeSnapshot initial;
    SfdMpvTimeCodeSnapshot maximum;
} SfdMpvDecodeTimer;

typedef struct MPVPictureInfo {
    int width;
    int height;
    int macroblocks_per_row;
    int macroblock_rows;
    int frame_rate_code;
    int temporal_reference;
    int picture_type;
    int drop_frame_flag;
    int time_code_hours;
    int time_code_minutes;
    int time_code_seconds;
    int time_code_pictures;
} MPVPictureInfo;

typedef struct SfdHandle {
    unsigned char reserved_0000[0xCC0];
    SfdMpvDecodeTimer timer_state;
    unsigned char reserved_0D2C[0x1BDC];
    void *seek_work;
} SfdHandle;

extern const int lbl_12_rodata_C10[]; /* sfmpv_fps_round */
extern void fn_12_2814C(int pts, int frame_rate, int drop_frame, int temporal_reference,
                        SfdTimeCode *timecode);

static inline void sfmpv_SetPicTc(MPVPictureInfo *picture, SfdTimeCode *timecode) {
    picture->time_code_hours = timecode->hours;
    picture->time_code_minutes = timecode->minutes;
    picture->time_code_seconds = timecode->seconds;
    picture->time_code_pictures = timecode->frames;
}

void fn_12_28304(SfdHandle *handle, MPVPictureInfo *picture, int pts, int group_changed) {
    int frame_rate;
    int fps_round;
    SfdTimeCode timecode;
    int minutes;
    int frame;
    struct { int value; } seconds;
    SfdTimeCode *source;
    int drop_frame;
    int temporal_reference;
    SfdMpvDecodeTimer *timer;
    int hours;
    int lab_t2;
    timer = &handle->timer_state;
    source = &timer->maximum.timecode;
    frame_rate = picture->frame_rate_code;
    drop_frame = picture->drop_frame_flag;
    temporal_reference = picture->temporal_reference;

    if (group_changed != 0 && pts >= 0) {
        lab_t2 = drop_frame;
        fn_12_2814C(pts, frame_rate, lab_t2, temporal_reference, &timecode);
        sfmpv_SetPicTc(picture, &timecode);
    } else if (timer->maximum.valid == 0) {
        if (handle->seek_work == 0) {
            picture->drop_frame_flag = 0;
            picture->time_code_hours = 0;
            picture->time_code_minutes = 0;
            picture->time_code_seconds = 0;
            picture->time_code_pictures = 0;
        } else {
            return;
        }
    } else if (group_changed != 0) {
        fps_round = lbl_12_rodata_C10[frame_rate];
        lab_t2 = source->frames + source->frame_offset + 1;
        frame = lab_t2;
        hours = source->hours;
        minutes = source->minutes;
        seconds.value = source->seconds;
        seconds.value += frame / fps_round;
        frame %= fps_round;
        minutes += seconds.value / 60;
        seconds.value %= 60;
        hours += minutes / 60;
        minutes %= 60;
        if (drop_frame != 0 && seconds.value == 0 && minutes % 10 != 0 && (frame == 0 || frame == 1)) {
            frame = 2;
        }
        timecode.hours = hours;
        timecode.minutes = minutes;
        timecode.seconds = seconds.value;
        timecode.frames = frame;
        sfmpv_SetPicTc(picture, &timecode);
    } else {
        sfmpv_SetPicTc(picture, source);
    }
}
/* fzgx:end fn_12_28304 */

/* fzgx:begin fn_12_284F8 noprologue */
#include "types.h"
#include "sofdec/sj.h"

typedef struct SfdTimeCode {
    int frame_rate_code;
    int drop_frame;
    int hours;
    int minutes;
    int seconds;
    int frames;
    int frame_offset;
} SfdTimeCode;

typedef struct SfdMpvTimeCodeSnapshot {
    int valid;
    SfdTimeCode timecode;
    int value;
    int scale;
} SfdMpvTimeCodeSnapshot;

typedef struct MPVPictureInfo {
    int width;
    int height;
    int macroblocks_per_row;
    int macroblock_rows;
    int frame_rate_code;
    int temporal_reference;
    int picture_type;
    int drop_frame_flag;
    int time_code_hours;
    int time_code_minutes;
    int time_code_seconds;
    int time_code_pictures;
    int unk_30;
} MPVPictureInfo;

/* the 12-byte entry fn_12_2CDD0 fills */
typedef struct Entry {
    int unk_0;
    int unk_4;
    int unk_8;
} Entry;

typedef struct SfdMpvFrameWork {
    void *decoder;
    u8 unk_004[0x84];
    int unk_88;
    MPVPictureInfo picture_info;
    u8 unk_0C0[0x1C];
    int unk_DC;
    int unk_E0;
    int unk_E4;
    int unk_E8;
    int unk_EC;
    int unk_F0;
    Entry unk_F4;
    u8 unk_100[0x7C0];
    void *picture_buffer;
    int picture_buffer_size;
    int unk_8C8;
} SfdMpvFrameWork;

typedef struct SfdPlaybackSettings {
    int unk_0;
    int unk_4;
    int unk_8;
    int unk_C;
    int unk_10;
    int frame_rate_code;
    u8 unk_18[8];
    int unk_20;
} SfdPlaybackSettings;

typedef struct SeekBuffer {
    u8 unk_0[0x200];
    int unk_200;
} SeekBuffer;

typedef struct SeekEntry {
    int unk_0;
    int unk_4;
    int unk_8;
    SfdMpvTimeCodeSnapshot unk_C;
    SeekBuffer unk_34;
} SeekEntry;

typedef struct SeekWork {
    u8 unk_0[0xAC4];
    SeekEntry unk_AC4;
} SeekWork;

typedef struct SfdMpvDecodeTimer {
    u8 unk_000[0x1C];
    SfdMpvTimeCodeSnapshot initial;
    SfdMpvTimeCodeSnapshot maximum;
    u8 unk_06C[0x28];
    SfdMpvTimeCodeSnapshot current;
    u8 unk_0BC[0x58];
} SfdMpvDecodeTimer;

typedef struct SfdHandle {
    u8 unk_0000[0x90C];
    SfdPlaybackSettings playback_settings;
    u8 unk_0930[0x390];
    SfdMpvDecodeTimer timer_state;
    int unk_DD4;
    u8 unk_0DD8[0xD58];
    SfdMpvFrameWork *video_work;
    int unk_1B34;
    int video_parameter;
    u8 unk_1B3C[0xDCC];
    SeekWork *seek_work;
} SfdHandle;

extern void fn_12_CA84(void *decoder, int size, void *buffer);
extern void fn_12_CA60(void *decoder, int *a, int *b);
extern int fn_12_C2C8(void *decoder, SJ *stream);
extern int fn_80057D88(SJ *stream, int channel, int type);
extern int fn_12_24A88(SfdHandle *handle, int error);
extern void fn_12_21E20(SfdHandle *handle, int parameter, int consumed);
extern int fn_12_AB60(void *decoder, MPVPictureInfo *picture);
extern const unsigned char *fn_12_A0D8(const unsigned char *data, int length, int mask);
extern int fn_12_2CDD0(SfdHandle *handle, int parameter, const unsigned char *delimiter, Entry *entry);
extern const int lbl_12_rodata_E10[];
extern unsigned int UTY_MulDiv(int multiplicand, int multiplier, int divisor);
extern int memcmp(const void *a, const void *b, int size);
extern int fn_12_2D73C(SfdHandle *handle, int index);
extern void fn_12_2D7DC(SfdHandle *handle, int index, int value);
extern void fn_12_2E374(SfdTimeCode *timecode, int *value, int *scale);
extern void fn_12_28304(SfdHandle *handle, MPVPictureInfo *picture, int pts, int group_changed);
extern int fn_12_AB00(void *decoder, int *value);
extern int fn_12_AA38(void *decoder, int *a, int *b, int *c);
extern int fn_12_21F38(SfdHandle *handle, int index);
extern void *fn_12_57F0(void *dst, const void *src, u32 size);
extern int fn_12_27C58(SfdHandle *handle, SfdPlaybackSettings *settings);

/* retail saves r21-r31 with stmw/lmw, as movie_module code does throughout */
#pragma use_lmw_stmw on

static inline int check_result(SfdHandle *handle, int result, int consumed, int error_code) {
    int error;
    switch (result) {
    case 0:
        error = 0;
        break;
    case -2:
        if (consumed > 0) {
            error = 0;
        } else {
            error = fn_12_24A88(handle, -2);
        }
        break;
    case -3:
        if (consumed > 0) {
            error = 0;
        } else {
            error = fn_12_24A88(handle, -3);
        }
        break;
    case -1:
    default:
        error = fn_12_24A88(handle, error_code);
        break;
    }
    return error;
}

static inline void get_timecode(MPVPictureInfo *picture, SfdTimeCode *timecode) {
    timecode->frame_rate_code = picture->frame_rate_code;
    timecode->drop_frame = picture->drop_frame_flag;
    timecode->hours = picture->time_code_hours;
    timecode->minutes = picture->time_code_minutes;
    timecode->seconds = picture->time_code_seconds;
    timecode->frames = picture->time_code_pictures;
    timecode->frame_offset = picture->temporal_reference;
}

static inline void calc_pts(SfdHandle *handle, MPVPictureInfo *picture, SfdMpvFrameWork *work, Entry *entry,
                            int changed, int *pts) {
    int count;
    int rate;
    int span;

    rate = lbl_12_rodata_E10[picture->frame_rate_code];
    count = picture->temporal_reference;
    if (handle->unk_DD4 < 0) {
        *pts = entry->unk_0 - UTY_MulDiv(count, 22500000, rate);
        handle->unk_DD4 = *pts > 0 ? *pts : 0;
    }
    span = entry->unk_0 - handle->unk_DD4;
    *pts = span > 0 ? span : 0;
    if (memcmp(&work->unk_F4, entry, 4) != 0) {
        work->unk_F4 = *entry;
        work->unk_EC = 0;
        work->unk_E8 = count;
        if (picture->picture_type == 3) {
            work->unk_F0 = 1;
        } else {
            work->unk_F0 = 0;
        }
    } else {
        if (changed != 0) {
            work->unk_EC += work->unk_F0 + 1;
            work->unk_F0 = 0;
            work->unk_E8 = 0;
        }
        span = count - work->unk_E8;
        work->unk_F0 = work->unk_F0 > span ? work->unk_F0 : span;
        *pts += UTY_MulDiv(work->unk_EC + span, 22500000, rate);
        *pts = *pts > 0 ? *pts : 0;
    }
}

static inline int get_pts(SfdHandle *handle, MPVPictureInfo *picture, SJCK *chunk, SfdMpvFrameWork *frame) {
    int pts;
    int changed;
    int parameter;
    const unsigned char *delimiter;
    Entry entry;
    SfdMpvFrameWork *work;

    changed = frame->unk_E0;
    work = handle->video_work;
    pts = -1;
    parameter = handle->video_parameter;
    delimiter = fn_12_A0D8(chunk->data, chunk->len, 4);
    if (delimiter != 0) {
        fn_12_2CDD0(handle, parameter, delimiter, &entry);
        if (entry.unk_0 >= 0) {
            calc_pts(handle, picture, work, &entry, changed, &pts);
        }
    }
    return pts;
}

static inline int is_past_maximum(SfdHandle *handle, MPVPictureInfo *picture) {
    SfdTimeCode timecode;
    int value;
    int maximum;
    int scale;
    int count;

    if (handle->timer_state.maximum.valid == 0) {
        return 0;
    }
    get_timecode(picture, &timecode);
    fn_12_2E374(&timecode, &value, &scale);
    fn_12_2E374(&handle->timer_state.maximum.timecode, &maximum, &scale);
    count = scale * fn_12_2D73C(handle, 0x35);
    if (value <= maximum) {
        return 1;
    }
    if (value >= maximum + count) {
        return 1;
    }
    return 0;
}

static inline SeekEntry *get_seek_entry(SfdHandle *handle) {
    SeekWork *seek = handle->seek_work;
    SfdMpvFrameWork *work = handle->video_work;
    if (seek == 0) {
        return 0;
    }
    if (work->unk_88 > 0) {
        return 0;
    }
    return &seek->unk_AC4;
}

static inline void save_seek_entry(SfdHandle *handle, SJCK *chunk, int code) {
    SeekEntry *entry = get_seek_entry(handle);
    SeekBuffer *buffer;
    if (entry != 0 && entry->unk_0 == 0) {
        buffer = &entry->unk_34;
        buffer->unk_200 = chunk->len < 0x200 ? chunk->len : 0x200;
        fn_12_57F0(buffer->unk_0, chunk->data, buffer->unk_200);
        if (code == 0x3FFFF) {
            entry->unk_4 = 0;
            entry->unk_8 = 0;
        } else {
            entry->unk_4 = code * 50;
            entry->unk_8 = 1;
        }
        entry->unk_C = handle->timer_state.initial;
        entry->unk_0 = 1;
    }
}

static inline void set_settings(SfdPlaybackSettings *settings, MPVPictureInfo *picture, int bit_rate,
                                int value) {
    settings->unk_0 = picture->width;
    settings->unk_4 = picture->height;
    settings->unk_8 = picture->macroblocks_per_row;
    settings->unk_C = picture->macroblock_rows;
    settings->frame_rate_code = picture->frame_rate_code;
    settings->unk_10 = bit_rate;
    settings->unk_20 = value;
}

static inline void start_timecode(SfdHandle *handle, MPVPictureInfo *picture, int pts, int changed) {
    int ready = fn_12_2D73C(handle, 0x34);
    if (ready == 0 && (pts >= 0 || (changed != 0 && is_past_maximum(handle, picture)))) {
        fn_12_2D7DC(handle, 0x34, 1);
        ready = 1;
    }
    if (ready == 1) {
        fn_12_28304(handle, picture, pts, changed);
    }
}

static inline int set_sequence(SfdHandle *handle, void *decoder, MPVPictureInfo *picture, SJCK *chunk) {
    SfdPlaybackSettings *settings;
    SfdMpvFrameWork *work;
    int bit_rate;
    int value_a;
    int value_b;
    int value_c;
    int limit;

    settings = &handle->playback_settings;
    work = handle->video_work;
    if (settings->unk_10 != 0) {
        return 0;
    }
    if (fn_12_AB00(decoder, &bit_rate) != 0) {
        return fn_12_24A88(handle, 0xFF000F16);
    }
    fn_12_AA38(decoder, &value_a, &value_b, &value_c);
    if (fn_12_2D73C(handle, 0x3C) == 0) {
        work->unk_E4 = 0;
    } else {
        limit = fn_12_21F38(handle, 1);
        if (value_c == -1) {
            value_c = value_a;
        }
        work->unk_E4 = value_c < limit ? value_c : limit;
    }
    save_seek_entry(handle, chunk, bit_rate);
    set_settings(settings, picture, bit_rate, value_a);
    return fn_12_27C58(handle, settings);
}

static inline void update_current(SfdHandle *handle, MPVPictureInfo *picture) {
    SfdMpvDecodeTimer *timer;
    SfdMpvTimeCodeSnapshot *maximum;
    SfdMpvTimeCodeSnapshot *current;
    SfdTimeCode timecode;
    int value;
    int scale;

    timer = &handle->timer_state;
    maximum = &timer->maximum;
    current = &timer->current;
    get_timecode(picture, &timecode);
    fn_12_2E374(&timecode, &value, &scale);
    current->timecode = timecode;
    current->value = value - timer->initial.value;
    current->scale = scale;
    current->valid = 1;
    if (maximum->value <= current->value) {
        *maximum = *current;
    }
}

int fn_12_284F8(SfdHandle *handle, SJCK *chunk, SJ *stream, int flag) {
    SfdMpvFrameWork *work;
    void *decoder;
    MPVPictureInfo *picture;
    SfdTimeCode start;
    int before;
    int consumed;
    int error;
    int pts;
    int start_scale;
    int start_value;

    work = handle->video_work;
    decoder = work->decoder;
    picture = &work->picture_info;
    fn_12_CA84(decoder, work->picture_buffer_size, work->picture_buffer);
    before = fn_80057D88(stream, 0, 1);
    error = fn_12_C2C8(decoder, stream);
    consumed = fn_80057D88(stream, 0, 1) - before;
    error = check_result(handle, error, consumed, 0xFF000F04);
    fn_12_21E20(handle, handle->video_parameter, consumed);
    if (error != 0) {
        return error;
    }
    fn_12_CA60(decoder, 0, &work->unk_8C8);
    if (fn_12_AB60(decoder, picture) != 0) {
        return fn_12_24A88(handle, 0xFF000F05);
    }
    if (work->unk_DC != picture->unk_30) {
        work->unk_DC = picture->unk_30;
        work->unk_E0 = 1;
    } else {
        work->unk_E0 = 0;
    }
    pts = get_pts(handle, picture, chunk, work);
    if (flag == 0) {
        return 0;
    }
    start_timecode(handle, picture, pts, work->unk_E0);
    if (handle->timer_state.initial.valid == 0) {
        get_timecode(picture, &start);
        start.frame_offset = 0;
        fn_12_2E374(&start, &start_value, &start_scale);
        handle->timer_state.initial.timecode = start;
        handle->timer_state.initial.value = start_value;
        handle->timer_state.initial.scale = start_scale;
        handle->timer_state.initial.valid = 1;
    }
    update_current(handle, picture);

    return set_sequence(handle, decoder, picture, chunk);
}
/* fzgx:end fn_12_284F8 */

/* fzgx:begin fn_12_28CC4 noprologue */
#include "types.h"

typedef struct SJCK {
    unsigned char *data;
    long len;
} SJCK;

typedef struct SJ SJ;

typedef struct SJInterface {
    void *reserved[6];
    void (*get_chunk)(SJ *sj, int channel, int max_size, SJCK *chunk);
    void (*unget_chunk)(SJ *sj, int channel, SJCK *chunk);
    void (*put_chunk)(SJ *sj, int channel, SJCK *chunk);
} SJInterface;

struct SJ {
    const SJInterface *interface;
};
#include "rel/movie_module/data/lbl_12_rodata_A18.h"

/* sfmpv_DecodeOneUnit (CRI Sofdec, sfd_mpv.c), GX version. */

typedef struct SfdTimeCode {
    s32 frame_rate_code;
    s32 drop_frame;
    s32 hours;
    s32 minutes;
    s32 seconds;
    s32 frames;
    s32 frame_offset;
} SfdTimeCode;

typedef struct SfdMpvTimeCodeSnapshot {
    s32 valid;
    SfdTimeCode timecode;
    s32 value;
    s32 scale;
} SfdMpvTimeCodeSnapshot;

typedef struct SfdMpvDecodeTimer {
    u8 reserved_000[0x1C];
    SfdMpvTimeCodeSnapshot initial;
    SfdMpvTimeCodeSnapshot maximum;
    SfdMpvTimeCodeSnapshot reserved_snapshot;
    SfdMpvTimeCodeSnapshot current;
    SfdMpvTimeCodeSnapshot previous;
    u8 reserved_0E4[0x20];
    s32 reference_time_origin;
    u8 reserved_108[0x18];
    s32 reference_time_offset;
    u8 reserved_124[0x88];
    s32 total_samples;
} SfdMpvDecodeTimer;

typedef struct SfdMpvFrameWork {
    void *decoder;
    u8 reserved_004[0x74];
    s32 decode_mode;
    u8 reserved_07C[0xC];
    s32 concat_count;
    u8 reserved_08C[0x18];
    s32 picture_type;
} SfdMpvFrameWork;

typedef struct SfdTransportSetup {
    u8 reserved_00[0xC];
    const void *audio_transport;
} SfdTransportSetup;

typedef struct SfdHandle {
    SfdTransportSetup *transport_setup;
    u8 reserved_0004[0x968];
    s32 decode_wait;
    u8 reserved_0970[0x350];
    SfdMpvDecodeTimer timer;
    u8 reserved_0E70[0xCC0];
    SfdMpvFrameWork *video_work;
    u8 reserved_1B34[0x4];
    s32 video_buffer;
    u8 reserved_1B3C[0xC];
    s32 video_total;
} SfdHandle;

typedef struct SfdBufferTransfer {
    SJCK chunks[2];
    s32 reserved[3];
} SfdBufferTransfer;

extern int fn_12_21E40(SfdHandle *handle, s32 buffer, SJ **stream);
extern void fn_12_2AC80(SfdHandle *handle, s32 status);
extern s32 fn_12_21F28(SfdHandle *handle, s32 buffer);
extern int fn_12_23250(SfdHandle *handle);
extern int fn_12_2D73C(SfdHandle *handle, s32 condition);
extern void fn_12_2E374(SfdTimeCode *timecode, s32 *value, s32 *scale);
extern int fn_12_22FBC(SfdHandle *handle, s32 *samples, s32 *sample_rate);
extern s32 UTY_MulDiv(s32 value, s32 multiplier, s32 divisor);
extern void fn_12_23120(SfdHandle *handle, s32 concat_time);
extern void fn_12_2EE48(SfdMpvTimeCodeSnapshot *snapshot, s32 value);
extern int fn_12_A2C4(const u8 *data);
extern void fn_12_21E20(SfdHandle *handle, s32 buffer, s32 size);
extern int fn_12_231A0(SfdHandle *handle);
extern int fn_12_21D30(SfdHandle *handle, s32 buffer);
extern void fn_12_2AC98(SfdHandle *handle);
extern int fn_12_22390(SfdHandle *handle, s32 buffer, SfdBufferTransfer *transfer);
extern int fn_12_284F8(SfdHandle *handle, SJCK *header, SJ *stream, int decode);
extern int fn_12_27884(SfdHandle *handle, SJCK *chunk);
extern s32 fn_80057D88(SJ *stream, s32 channel, s32 direction);
extern int fn_12_A7B0(void *decoder, SJ *stream);
extern int fn_12_24A88(SfdHandle *handle, s32 error);
extern void fn_12_2B9F8(SfdHandle *handle, s32 count, s32 picture_type);
extern int fn_12_27478(SfdHandle *handle, SJ *stream);
extern const u8 *fn_12_A0D8(const u8 *data, s32 size, u32 mask);
extern void fn_12_22008(SfdHandle *handle, s32 buffer, s32 size);
extern void *memcpy(void *dst, const void *src, u32 size);

static inline void sfmpv_SkipEndcode(SfdHandle *handle, SJ *stream) {
    for (;;) {
        SJCK chunk;

        stream->interface->get_chunk(stream, 1, 4, &chunk);
        if (chunk.len == 4 && fn_12_A2C4(chunk.data) == 0x80) {
            stream->interface->put_chunk(stream, 0, &chunk);
            fn_12_21E20(handle, handle->video_buffer, 4);
        } else {
            stream->interface->unget_chunk(stream, 1, &chunk);
            break;
        }
    }
}

static inline s32 sfmpv_GetAudioConcatTime(SfdHandle *handle) {
    SfdMpvDecodeTimer *timer = &handle->timer;
    s32 samples;
    s32 sample_rate;
    s32 concat_time;

    if (handle->transport_setup->audio_transport != &lbl_12_rodata_A18) {
        samples = 0;
        sample_rate = 44100;
    } else if (fn_12_22FBC(handle, &samples, &sample_rate) == 0) {
        return -1;
    }
    {
        s32 scale = timer->initial.scale;

        timer->total_samples += samples;
        concat_time = UTY_MulDiv(timer->total_samples, scale, sample_rate) - timer->reference_time_offset;
    }
    if (concat_time < 0) {
        concat_time = 0;
    }
    return concat_time;
}

static inline s32 sfmpv_CalcConcatTime(SfdMpvTimeCodeSnapshot *maximum,
                                       SfdMpvTimeCodeSnapshot *initial) {
    SfdTimeCode timecode;
    s32 value;
    s32 scale;

    if (maximum->valid == 0) {
        return 0;
    }
    timecode = maximum->timecode;
    timecode.frame_offset++;
    fn_12_2E374(&timecode, &value, &scale);
    return value - initial->value;
}

static inline int sfmpv_UpdateConcatTime(SfdHandle *handle) {
    SfdMpvFrameWork *work = handle->video_work;
    SfdMpvDecodeTimer *timer = &handle->timer;
    s32 concat_time;

    if (fn_12_2D73C(handle, 6) == 0) {
        concat_time = sfmpv_CalcConcatTime(&timer->maximum, &timer->initial);
    } else {
        concat_time = sfmpv_GetAudioConcatTime(handle);
        if (concat_time < 0) {
            return -1;
        }
    }
    if (concat_time > 0) {
        fn_12_23120(handle, concat_time);
        work->concat_count++;
    }
    fn_12_2EE48(&timer->initial, 0x7FFFFFFF);
    fn_12_2EE48(&timer->maximum, -1);
    work->decode_mode = 0xC0;
    return 0;
}

static inline int sfmpv_Concat(SfdHandle *handle, SJ *stream) {
    if (sfmpv_UpdateConcatTime(handle) == -1) {
        return -1;
    }
    sfmpv_SkipEndcode(handle, stream);
    return 0;
}

static inline int sfmpv_SkipFrm(SfdHandle *handle, SJ *stream) {
    SfdMpvFrameWork *work = handle->video_work;
    SfdMpvDecodeTimer *timer = &handle->timer;
    void *decoder = work->decoder;
    s32 flow_before;
    s32 consumed;
    int result;
    SfdMpvTimeCodeSnapshot *current = &timer->current;
    SfdMpvTimeCodeSnapshot *previous = &timer->previous;

    if (current->value < timer->reference_time_origin) {
        *previous = *current;
    }
    flow_before = fn_80057D88(stream, 0, 1);
    result = fn_12_A7B0(decoder, stream);
    consumed = fn_80057D88(stream, 0, 1) - flow_before;
    switch (result) {
    case 0:
        result = 0;
        break;
        case -2:
        if (consumed > 0) {
            result = 0;
        } else {
            result = fn_12_24A88(handle, -2);
        }
        break;
    case -3:
        if (consumed > 0) {
            result = 0;
        } else {
            result = fn_12_24A88(handle, -3);
        }
        break;
    default:
        result = fn_12_24A88(handle, 0xFF000F07);
        break;
    }
    fn_12_21E20(handle, handle->video_buffer, consumed);
    if (result != 0) {
        return result;
    }
    fn_12_2B9F8(handle, 1, work->picture_type);
    return 0;
}

static inline int sfmpv_IsTermDec(SfdHandle *handle, s32 active_size, s32 delimiter_type) {
    if (delimiter_type == 0x80) {
        return 1;
    }
    if (active_size <= 4 && fn_12_21D30(handle, handle->video_buffer) == 1) {
        return 1;
    }
    return 0;
}

static inline const u8 *sfmpv_SearchTransferDelimiter(SfdBufferTransfer *transfer,
                                                      int delimiter_mask, int *code) {
    u8 boundary[8];
    const u8 *delimiter;
    long tail;
    long head;
    int i;
    int found_code;
    delimiter = fn_12_A0D8(transfer->chunks[0].data, transfer->chunks[0].len, delimiter_mask);
    if (delimiter != 0) {
        *code = fn_12_A2C4(delimiter);
        return delimiter;
    }
    if (transfer->chunks[1].len == 0) {
        return 0;
    }
    tail = transfer->chunks[0].len < 3 ? transfer->chunks[0].len : 3;
    head = transfer->chunks[1].len < 3 ? transfer->chunks[1].len : 3;
    memcpy(boundary, transfer->chunks[0].data + transfer->chunks[0].len - tail, tail);
    memcpy(boundary + tail, transfer->chunks[1].data, head);
    for (i = 0; i < tail + head - 3; i++) {
        found_code = fn_12_A2C4(boundary + i);
        if ((found_code & delimiter_mask) != 0) {
            *code = found_code;
            return transfer->chunks[0].data + transfer->chunks[0].len - tail + i;
        }
    }
    delimiter = fn_12_A0D8(transfer->chunks[1].data, transfer->chunks[1].len, delimiter_mask);
    if (delimiter != 0) {
        *code = fn_12_A2C4(delimiter);
        return delimiter;
    }
    return 0;
}

static inline int sfmpv_DelimiterOffset(const SfdBufferTransfer *transfer, const u8 *delimiter) {
    if (transfer->chunks[0].data <= delimiter &&
        delimiter < transfer->chunks[0].data + transfer->chunks[0].len) {
        return delimiter - transfer->chunks[0].data;
    }
    if (transfer->chunks[1].data <= delimiter &&
        delimiter < transfer->chunks[1].data + transfer->chunks[1].len) {
        return transfer->chunks[0].len + (delimiter - transfer->chunks[1].data);
    }
    return 0;
}

static inline void sfmpv_GoDdelim(SfdHandle *handle, int delimiter_mask) {
    SfdBufferTransfer transfer;
    const u8 *delimiter;
    int ignored_code;
    s32 consumed;

    if (fn_12_22390(handle, handle->video_buffer, &transfer) != 0 || transfer.chunks[0].len == 0) {
        return;
    }
    delimiter = sfmpv_SearchTransferDelimiter(&transfer, delimiter_mask, &ignored_code);
    if (delimiter == 0) {
        int size = transfer.chunks[0].len + transfer.chunks[1].len;
        size -= 3;
        consumed = size > 0 ? size : 0;
    } else {
        consumed = sfmpv_DelimiterOffset(&transfer, delimiter);
    }
    fn_12_22008(handle, handle->video_buffer, consumed);
}

#pragma use_lmw_stmw on
int fn_12_28CC4(SfdHandle *handle, s32 active_size, s32 delimiter_type, int *processed) {
    SfdMpvFrameWork *work;
    SfdMpvDecodeTimer *timer = &handle->timer;
    SJ *stream;
    SJCK chunk;
    int result;
    s32 buffer;

    *processed = 0;
    work = handle->video_work;
    buffer = handle->video_buffer;
    handle->decode_wait = 0;
    if (work->decode_mode != 0xCC) {
        delimiter_type &= 0xCC;
    }
    result = fn_12_21E40(handle, buffer, &stream);
    if (result != 0) {
        return 0;
    }
    if ((delimiter_type & 0xC8) != 0) {
        fn_12_2AC80(handle, 1);
    }
    if (delimiter_type == 0x80) {
        SfdMpvTimeCodeSnapshot *snapshot = &timer->reserved_snapshot;

        buffer = handle->video_buffer;
        if (handle->video_total < 0) {
            handle->video_total = fn_12_21F28(handle, buffer) + 4;
        }
        if (snapshot->value < 0) {
            *snapshot = timer->maximum;
        }
    }
    if (delimiter_type == 0x80 && fn_12_23250(handle) != 0) {
        if (sfmpv_Concat(handle, stream) == 0) {
            *processed = 1;
        }
    } else if (delimiter_type == 0x80 && fn_12_231A0(handle) != 0) {
        sfmpv_SkipEndcode(handle, stream);
        *processed = 1;
    } else if (sfmpv_IsTermDec(handle, active_size, delimiter_type)) {
        fn_12_2AC98(handle);
    } else if (active_size <= 4) {
        handle->decode_wait = 1;
    } else if ((delimiter_type & 0x4C) != 0) {
        SfdBufferTransfer transfer;

        if (fn_12_22390(handle, handle->video_buffer, &transfer) != 0) {
            chunk.data = NULL;
            chunk.len = 0;
        } else {
            chunk = transfer.chunks[0];
        }
        result = fn_12_284F8(handle, &chunk, stream, (delimiter_type & work->decode_mode) != 0);
        if (result != 0) {
            return result;
        }
        if ((delimiter_type & work->decode_mode) != 0) {
            work->decode_mode = 0xCC;
        }
        *processed = 1;
    } else if ((delimiter_type & 2) != 0) {
        if (timer->reference_time_offset < 0) {
            return 0;
        }
        if (fn_12_27884(handle, &chunk) != 0) {
            result = sfmpv_SkipFrm(handle, stream);
            if (result == 0) {
                *processed = 1;
            }
        } else {
            result = fn_12_27478(handle, stream);
        }
    } else if (delimiter_type != 0x80) {
        sfmpv_GoDdelim(handle, 0xCC);
        *processed = 1;
    }
    return result;
}
/* fzgx:end fn_12_28CC4 */

/* fzgx:begin fn_12_29524 */
#pragma use_lmw_stmw on

/* --- rel/movie_module/fn_12_29524.c --- */






static inline const unsigned char *fn_12_29524_sfmpv_SearchTransferDelimiter(fn_12_29524_SfdBufferTransfer *transfer, int delimiter_mask, int *code) { unsigned char boundary[8];
    const unsigned char *delimiter;
    long tail;
    long head;
    int i;
    int found_code;
    delimiter = ((const unsigned char *)fn_12_A0D8( (u8 *)(const unsigned char *)(transfer->chunks[0].data), transfer->chunks[0].len, delimiter_mask));
    if (delimiter != 0) {
        *code = ((int)fn_12_A2C4( (const u8 *)(const unsigned char *)(delimiter)));
        return delimiter;
    }
    if (transfer->chunks[1].len == 0) {
        return 0;
    }
    tail = transfer->chunks[0].len < 3 ? transfer->chunks[0].len : 3;
    head = transfer->chunks[1].len < 3 ? transfer->chunks[1].len : 3;
    memcpy(boundary, transfer->chunks[0].data + transfer->chunks[0].len - tail, tail);
    memcpy(boundary + tail, transfer->chunks[1].data, head);
    for (i = 0; i < tail + head - 3; i++) {
        found_code = ((int)fn_12_A2C4( (const u8 *)(const unsigned char *)(boundary + i)));
        if ((found_code & delimiter_mask) != 0) {
            *code = found_code;
            return transfer->chunks[0].data + transfer->chunks[0].len - tail + i;
        }
    }
    delimiter = ((const unsigned char *)fn_12_A0D8( (u8 *)(const unsigned char *)(transfer->chunks[1].data), transfer->chunks[1].len, delimiter_mask));
    if (delimiter != 0) {
        *code = ((int)fn_12_A2C4( (const u8 *)(const unsigned char *)(delimiter)));
        return delimiter;
    }
    return 0;
}

int fn_12_29524(fn_12_29524_SfdBufferTransfer *transfer, int current_type, const unsigned char *delimiter) {
    unsigned char delimiter_bytes[4];
    int type;
    int ignored_code;
    if (delimiter == 0) {
        return 1;
    }
    if (delimiter == transfer->chunks[0].data) {
        return 1;
    }
    if ((unsigned long)delimiter >= (unsigned long)transfer->chunks[0].data &&
        (unsigned long)delimiter <
            (unsigned long)transfer->chunks[0].data + transfer->chunks[0].len) {
        int overflow = (unsigned long)delimiter + 4 -
                       ((unsigned long)transfer->chunks[0].data + transfer->chunks[0].len);
        if (overflow > 0) {
            if (overflow > transfer->chunks[1].len) {
                return 1;
            }
            memcpy(delimiter_bytes, delimiter, 4 - overflow);
            memcpy(delimiter_bytes + 4 - overflow, transfer->chunks[1].data, overflow);
        } else {
            memcpy(delimiter_bytes, delimiter, 4);
        }
    } else if ((unsigned long)delimiter >= (unsigned long)transfer->chunks[1].data &&
               (unsigned long)delimiter <
                   (unsigned long)transfer->chunks[1].data + transfer->chunks[1].len) {
        int overflow = (unsigned long)delimiter + 4 -
                       ((unsigned long)transfer->chunks[1].data + transfer->chunks[1].len);
        if (overflow > 0) {
            return 1;
        }
        memcpy(delimiter_bytes, delimiter, 4);
    } else {
        return 1;
    }
    type = ((int)fn_12_A2C4( (const u8 *)(const unsigned char *)(delimiter_bytes)));
    switch (type) {
    case 8:
        if ((current_type & 0x40) != 0) {
            const unsigned char *next = fn_12_29524_sfmpv_SearchTransferDelimiter(transfer, 8, &ignored_code);
            if (next == 0 || next == delimiter) {
                return 1;
            }
        }
        break;
    case 4:
        if ((current_type & 0x48) != 0) {
            const unsigned char *next = fn_12_29524_sfmpv_SearchTransferDelimiter(transfer, 4, &ignored_code);
            if (next == 0 || next == delimiter) {
                return 1;
            }
        }
        break;
    case 0x40:
    case 0x80:
        break;
    default:
        return 1;
    }
    return 0;
}
/* fzgx:end fn_12_29524 */

/* fzgx:begin fn_12_298AC */
/* --- rel/movie_module/fn_12_298AC.c --- */
/* sfmpv_GetActiveSize, from the CC0 MK Deception decomp (sfd_mpv.c). GX's version has no
   has_data output. */

typedef struct SfdTransportInterface SfdTransportInterface;
/* GX's player handle predates MK Deception's layout; only the fields used here are placed. */



static inline int fn_12_298AC_sfmpv_DelimiterOffset(const fn_12_29524_SfdBufferTransfer *transfer, const unsigned char *delimiter) { if (transfer->chunks[0].data <= delimiter && delimiter < transfer->chunks[0].data + transfer->chunks[0].len) { return delimiter - transfer->chunks[0].data;
    }
    if (transfer->chunks[1].data <= delimiter &&
        delimiter < transfer->chunks[1].data + transfer->chunks[1].len) {
        return transfer->chunks[0].len + (delimiter - transfer->chunks[1].data);
    }
    return 0;
}

static inline const unsigned char *sfmpv_BsearchTransferDelimiter(const fn_12_29524_SfdBufferTransfer *transfer, int delimiter_mask, int *code) { const unsigned char *delimiter;
    if (transfer->chunks[1].len != 0) {
        unsigned char boundary[8];
        long tail;
        long head;
        int i;
        delimiter = ((void *)fn_12_A1C4( (char *)(const unsigned char *)(transfer->chunks[1].data + transfer->chunks[1].len),
                               transfer->chunks[1].len, delimiter_mask));
        if (delimiter != 0) {
            *code = ((int)fn_12_A2C4( (const u8 *)(const unsigned char *)(delimiter)));
            return delimiter;
        }
        tail = transfer->chunks[0].len < 3 ? transfer->chunks[0].len : 3;
        head = transfer->chunks[1].len < 3 ? transfer->chunks[1].len : 3;
        memcpy(boundary, transfer->chunks[0].data + transfer->chunks[0].len - tail, tail);
        memcpy(boundary + tail, transfer->chunks[1].data, head);
        for (i = 0; i < tail + head - 3; i++) {
            int found_code = ((int)fn_12_A2C4( (const u8 *)(const unsigned char *)(boundary + i)));
            if ((found_code & delimiter_mask) != 0) {
                *code = found_code;
                return transfer->chunks[0].data + transfer->chunks[0].len - tail + i;
            }
        }
    }
    delimiter = ((void *)fn_12_A1C4( (char *)(const unsigned char *)(transfer->chunks[0].data + transfer->chunks[0].len),
                           transfer->chunks[0].len, delimiter_mask));
    if (delimiter != 0) {
        *code = ((int)fn_12_A2C4( (const u8 *)(const unsigned char *)(delimiter)));
        return delimiter;
    }
    return 0;
}

static inline int sfmpv_ChkRingSpace(fn_12_298AC_SfdHandle *handle) {
    int buffer_index = handle->transports[2].parameter_10;
    if (fn_12_21F38( (fn_12_284F8_SfdHandle *)(fn_12_298AC_SfdHandle *)(handle), buffer_index) - fn_12_21C00(handle, buffer_index) <
        handle->ring_alignment) {
        return fn_12_24A88( (int)(fn_12_298AC_SfdHandle *)(handle), 0xFF000F1C);
    }
    return 0;
}

int fn_12_298AC(fn_12_298AC_SfdHandle *handle, int *active_size, int *delimiter_type) {
    int buffer_index = handle->transports[2].parameter_10;
    fn_12_29524_SfdBufferTransfer transfer;
    const unsigned char *delimiter;
    unsigned char *cached_delimiter;
    unsigned char *cached_end;
    unsigned char *transfer_end;
    int type;
    int result;
    int ignored_code;
    *active_size = 0;
    *delimiter_type = 0;
    result = fn_12_22390( (u8 *)(fn_12_298AC_SfdHandle *)(handle), buffer_index, (u32 *)(fn_12_29524_SfdBufferTransfer *)(&transfer));
    if (result != 0) {
        return result;
    }
    if (transfer.chunks[0].len == 0) {
        return 0;
    }
    type = 0;
    delimiter = fn_12_29524_sfmpv_SearchTransferDelimiter(&transfer, 0xCE, &type);
    if (delimiter != transfer.chunks[0].data) {
        if (delimiter != 0) {
            *active_size = fn_12_298AC_sfmpv_DelimiterOffset(&transfer, delimiter);
        } else {
            int size = transfer.chunks[0].len + transfer.chunks[1].len - 3;
            *active_size = size < 0 ? 0 : size;
        }
        return 0;
    }
    *delimiter_type = type;
    *active_size = 4;
    if ((type & 0x80) != 0) {
        return 0;
    }
    fn_12_21FA4(handle, buffer_index, &cached_delimiter, &cached_end);
    if (fn_12_29524(&transfer, type, cached_delimiter) != 0) {
        cached_delimiter = 0;
        if (transfer.chunks[1].len == 0) {
            transfer_end = transfer.chunks[0].data + transfer.chunks[0].len;
        } else {
            transfer_end = transfer.chunks[1].data + transfer.chunks[1].len;
        }
        if (cached_end != transfer_end) {
            cached_end = transfer_end;
            cached_delimiter =
                (unsigned char *)sfmpv_BsearchTransferDelimiter(&transfer, 0xCC, &ignored_code);
            fn_12_21F48( (u8 *)(fn_12_298AC_SfdHandle *)(handle), buffer_index, (void *)(unsigned char *)(cached_delimiter), (void *)(unsigned char *)(cached_end));
        }
    }
    if (cached_delimiter == 0) {
        return sfmpv_ChkRingSpace(handle);
    }
    switch (((int)fn_12_A2C4( (const u8 *)(const unsigned char *)(cached_delimiter)))) {
    case 8:
        if ((type & 0x40) != 0) {
            const unsigned char *next = fn_12_29524_sfmpv_SearchTransferDelimiter(&transfer, 8, &ignored_code);
            if (next == 0 || next == cached_delimiter) {
                return sfmpv_ChkRingSpace(handle);
            }
        }
        break;
    case 4:
        if ((type & 0x48) != 0) {
            const unsigned char *next = fn_12_29524_sfmpv_SearchTransferDelimiter(&transfer, 4, &ignored_code);
            if (next == 0 || next == cached_delimiter) {
                return sfmpv_ChkRingSpace(handle);
            }
        }
        break;
    case 0x40:
    case 0x80:
    default:
        break;
    }
    *active_size = fn_12_298AC_sfmpv_DelimiterOffset(&transfer, cached_delimiter);
    return 0;
}
/* fzgx:end fn_12_298AC */

/* fzgx:begin fn_12_29FF8 noprologue */
#include "types.h"

typedef struct MovieModule {
    u8 pad_0000[0x2c];
    int field_2c;
    u8 pad_0030[0x48];
    int field_78;
    u8 pad_007c[0x78];
    int field_f4;
    u8 pad_00f8[0x854];
    int field_94c;
    u8 pad_0950[0x10];
    s32 field_960;
    u8 pad_0964[0x98];
    int field_9fc;
    u8 pad_a00[0x3a4];
    int field_da4;
    u8 pad_da8[0x1c];
    int field_dc4;
    u8 pad_dc8[0xd68];
    void *field_1b30;
    int field_1b34;
    int field_1b38;
    int field_1b3c;
    u8 pad_1b40[0x794];
    int field_22d4;
    u8 pad_22d8[0x8];
    int field_22e0;
} MovieModule;

typedef struct MovieState {
    void *field_0;
    u8 pad_4[0xe0];
    int field_e4;
} MovieState;

extern int fn_12_2D73C(MovieModule *module, int value);
extern int fn_12_21D30(MovieModule *module, int value);
extern int fn_12_23F00(MovieModule *module);
extern int fn_12_24990(MovieModule *module);
extern void fn_12_24A88(void *obj, int code);
extern int fn_12_CAE4(int value, int arg, int flag);
extern int fn_12_298AC(MovieModule *module, int *a, int *b);
extern int fn_12_28CC4(MovieModule *module, int a, int b, int *c);
extern int fn_12_21D50(MovieModule *module, int value);
extern int fn_12_2AC8C(MovieModule *module);
extern int fn_12_2ABF0(MovieModule *module);
extern int fn_12_AB00(void *obj, int *value);
extern int fn_12_21E94(MovieModule *module, int value);
extern int fn_12_2F1B4(MovieModule *module, int value);
extern int fn_12_21F38(MovieModule *module, int value);
extern void fn_12_21D60(MovieModule *module, int value, int flag);
extern void fn_12_21D40(MovieModule *module, int value, int flag);
extern void fn_12_2D7DC(MovieModule *module, int value, int flag);

#pragma opt_lifetimes off
int fn_12_29FF8(MovieModule *module) {
    int *fzgx_value;
    int local_14;
    int local_10;
    int local_c;
    int local_8;
    int result;
    int value;
    int other;
    int not;
    int flag;
    MovieState *state;
    void *state0;

    if (fn_12_2D73C(module, 5) == 0) {
        return 0;
    }
    if (fn_12_21D30(module, module->field_1b3c) == 1) {
        return 0;
    }
    if (fn_12_2D73C(module, 0x1c) != 0 && fn_12_23F00(module) != -1) {
        do {
            int v;
            if (module == 0) {
                v = 0;
            } else {
                if (fn_12_24990(module) != 0) {
                    fn_12_24A88(0, (0xff00 << 16) | 0x181);
                    break;
                }
                v = *(int *)module->field_1b30;
            }
            if (fn_12_CAE4(v, 5, 0) != 0) {
                fn_12_24A88(module, (0xff00 << 16) | 0xf12);
            }
        } while (0);
    }
    for (;;) {
        result = fn_12_298AC(module, &local_c, &local_14);
        if (result == 0) {
            result = fn_12_28CC4(module, local_c, local_14, &local_10);
            if (result == 0 && local_10 != 0) {
                continue;
            }
        }
        break;
    }
    value = module->field_1b3c;
    other = module->field_1b38;
    if (fn_12_21D50(module, value) != 1 && fn_12_21D50(module, other) == 1) {
        if (fn_12_2AC8C(module) != 0) {
            flag = 1;
        } else {
            other = module->field_9fc;
{
    int limit;
            limit = module->field_2c;
            if (other == -1) {
                other = limit;
            }
            if (limit < other) {
                other = limit;
}
            }
            if (fn_12_2ABF0(module) >= other) {
                state = module->field_1b30;
                state0 = state->field_0;
                if (fn_12_21D30(module, module->field_1b38) == 1) {
                    flag = 1;
                } else if (module->field_78 != 0 && module->field_f4 == 0) {
                    flag = 1;
                } else if (fn_12_AB00(state0, &local_8), (unsigned)(local_8 - 0x30000) == 0xffff) {
                    flag = 1;
                } else if (fn_12_21E94(module, 1) >= state->field_e4) {
                    flag = 1;
                } else {
                    not = fn_12_2F1B4(module, 1) == 0;
                    other = fn_12_21F38(module, not);
                    if (fn_12_21E94(module, not) >= other) {
                        flag = 1;
                    } else {
                        flag = 0;
                    }
                }
                if (flag != 0) {
                    flag = 1;
                    goto done; /* retail shares the single flag = 0 fallthrough for both failing paths */
                }
            }
            flag = 0;
        }
done:
        if (flag != 0) {
            fn_12_21D60(module, value, 1);
            if (module->field_dc4 != 0x7fffffff) {
                fzgx_value = &(module->field_da4);
                *fzgx_value = 1;
            }
        }
    }
    other = fn_12_2ABF0(module);
    if (other == -1 || (fn_12_2AC8C(module) != 0 && other == 1 && module->field_960 != 0)) {
        fn_12_21D40(module, module->field_1b3c, 1);
        if (module->field_94c == 0) {
            fn_12_2D7DC(module, 5, 0);
        }
    }
    return result;
}
/* fzgx:end fn_12_29FF8 */

/* fzgx:begin fn_12_2A308 */
/* --- rel/movie_module/fn_12_2A308.c --- */
/* --- rel/movie_module/fn_12_2A308.c --- */

void fn_12_2A308(void) {
    fn_12_29FF8();
}
/* fzgx:end fn_12_2A308 */

/* fzgx:begin fn_12_2A328 */
/* --- rel/movie_module/fn_12_2A328.c --- */

int fn_12_2A328(void) {
    fn_12_D038();
    return 0;
}
/* fzgx:end fn_12_2A328 */

/* fzgx:begin fn_12_2A34C */
/* --- rel/movie_module/fn_12_2A34C.c --- */

s32 fn_12_2A34C(void) {
    u32 *state;
    s32 a;
    s32 b;
    s32 err;

    state = lbl_12_bss_96A0;
    a = 0x50;
    b = 0x204;

    if (a != 0x50) {
        err = fn_12_24A88( (int)(void *)(0), 0xff000f1a);
    } else if (b > 0x204) {
        err = fn_12_24A88( (int)(void *)(0), 0xff000f1a);
    } else {
        err = 0;
    }

    if (err != 0) {
        for (;;) {
        }
    }

    err = fn_12_D0B8(8, lbl_12_bss_9710);
    if (err != 0) {
        fn_12_24A88( (int)(void *)(0), err == 0xff03ff05 ? 0xff000f13 : 0xff000f01);
    } else {
        memset((u8 *)state + 0x4c, 0, 0x24);
        memset((u8 *)state + 0x44, 0, 8);
        memset((u8 *)state + 4, 0, 0x40);
        state[0] = 0;
        return 0;
    }
}
/* fzgx:end fn_12_2A34C */

/* fzgx:begin fn_12_2A434 */
/* --- rel/movie_module/fn_12_2A434.c --- */

typedef struct MovieQueueEntry {
    void *data;
    int unk;
} MovieQueueEntry;

typedef struct MovieQueue {
    void *source;
    int count;
    int stride;
    void *base;
    int unk10;
    MovieQueueEntry entries[16];
} MovieQueue;

typedef struct fn_12_2A434_MovieState {
    u8 pad[0x8b8];
    MovieQueue queue;
} fn_12_2A434_MovieState;

typedef struct fn_12_2A434_MovieModule {
    u8 pad[0x1b30];
    fn_12_2A434_MovieState *state;
} fn_12_2A434_MovieModule;

int fn_12_2A434(fn_12_2A434_MovieModule *module, void *source, int count, int stride) {
    fn_12_2A434_MovieState *state;
    MovieQueue *queue;
    int i;

    if (fn_12_24990(module, source)) {
        return fn_12_24A88( (int)(void *)(0), 0xff000185);
    }

    state = module->state;
    queue = &state->queue;
    queue->source = source;
    queue->count = count < 0x10 ? count : 0x10;
    queue->stride = stride;
    queue->base = source;
    queue->unk10 = 0;
    for (i = 0; i < queue->count; i++) {
        queue->entries[i].data = (u8 *)source + stride * (i + 1);
        queue->entries[i].unk = 0;
    }
    return 0;
}
/* fzgx:end fn_12_2A434 */

/* fzgx:begin fn_12_2A508 */
u32 fn_12_2A508(u32 arg0) {
    u32 v0;
    u32 t0, t1, t2;
    t0 = ((u32)fn_12_24990(arg0));
    v0 = t0;
    if ((s32)t0 != 0) {
    v0 = 0;
    t1 = ((u32)fn_12_24A88(v0, (0xFF000000 + 387)));
    v0 = t1;
    v0 = 0;
    } else {
    v0 = arg0;
    t2 = fn_12_2A85C(v0);
    v0 = t2;
    }
    return v0;
}
/* fzgx:end fn_12_2A508 */

/* fzgx:begin fn_12_2A55C */
int fn_12_2A55C(void *arg0, int *arg1) {
    *arg1 = 0;
    if (fn_12_24990(arg0, arg1)) {
        return fn_12_24A88(0, 0xff000182);
    }
    *arg1 = fn_12_2ABF0(arg0);
    return 0;
}
/* fzgx:end fn_12_2A55C */

/* fzgx:begin fn_12_2A5C8 noprologue */
#include "types.h"


/* --- rel/movie_module/fn_12_2A5C8.c --- */
extern int fn_12_24990(void *arg0, int arg1);
extern int fn_12_24A88(int arg0, u32 arg1);
extern int fn_12_CAE4(int arg0, int arg1, int arg2);

typedef struct MovieModule {
    unsigned char _pad[0x1b30];
    void *field_1b30;
} MovieModule;

int fn_12_2A5C8(MovieModule *arg0, int arg1, int arg2) {
    int result;

    if (arg0 == 0) {
        result = 0;
    } else if (fn_12_24990(arg0, arg1)) {
        return fn_12_24A88(0, 0xff000181);
    } else {
        result = *(int *)arg0->field_1b30;
    }

    if (arg1 == 5) {
        arg2 = 0;
    }
    if (fn_12_CAE4(result, arg1, arg2)) {
        return fn_12_24A88((int)arg0, 0xff000f12);
    }
    return 0;
}
/* fzgx:end fn_12_2A5C8 */

/* fzgx:begin fn_12_2A674 noprologue */
/* --- rel/movie_module/fn_12_2A674.c --- */
typedef struct MovieSize {
    s32 value0;
    s32 value1;
    s32 value2;
    s16 value3;
    s16 value4;
} MovieSize;

void fn_12_2A674(int arg0, int arg1, int arg2, MovieSize *out) {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;

    a = (arg1 + 15) / 16;
    b = a << 4;
    c = (b + 31) / 32;
    d = b / 2;
    e = (d + 31) / 32;
    out->value4 = c << 5;
    out->value3 = e << 5;
    f = (arg2 + 15) / 16;
    g = f << 4;
    h = g / 2;
    out->value2 = arg0;
    out->value0 = out->value2 + g * (c << 5);
    out->value1 = out->value0 + h * (e << 5);
}
/* fzgx:end fn_12_2A674 */
