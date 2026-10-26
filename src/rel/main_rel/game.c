#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"

typedef struct Sig_ADXT_Pause_AdxSjdHandle Sig_ADXT_Pause_AdxSjdHandle;

typedef struct Sig_ADXT_Pause_ADXStream Sig_ADXT_Pause_ADXStream;

typedef struct Sig_ADXT_Pause_AXRNAHandle Sig_ADXT_Pause_AXRNAHandle;

typedef struct Sig_ADXT_Pause_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Pause_SJCK;

typedef void (*Sig_ADXT_Pause_SJErrorCallback)(void *object, int error);

typedef struct Sig_ADXT_Pause_SJInterface Sig_ADXT_Pause_SJInterface;

typedef struct Sig_ADXT_Pause_SJ Sig_ADXT_Pause_SJ;

struct Sig_ADXT_Pause_SJ {
    const Sig_ADXT_Pause_SJInterface *interface;
};

struct Sig_ADXT_Pause_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Pause_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Pause_SJ *sj);
    void (*reset)(Sig_ADXT_Pause_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, int max_size, Sig_ADXT_Pause_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, Sig_ADXT_Pause_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, Sig_ADXT_Pause_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Pause_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Pause_SJ *sj, Sig_ADXT_Pause_SJErrorCallback callback, void *object);
};

typedef struct Sig_ADXT_Pause_ADX_AMP Sig_ADXT_Pause_ADX_AMP;

typedef struct Sig_ADXT_Pause_LSCObject Sig_ADXT_Pause_LSCObject;

typedef struct Sig_ADXT_Pause_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Pause_AdxSjdHandle *decoder;
    Sig_ADXT_Pause_ADXStream *stream;
    Sig_ADXT_Pause_AXRNAHandle *rna;
    Sig_ADXT_Pause_SJ *stream_sj;
    Sig_ADXT_Pause_SJ *input_sj;
    Sig_ADXT_Pause_SJ *output_sj[2];
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
    Sig_ADXT_Pause_ADX_AMP *amplifier;
    Sig_ADXT_Pause_SJ *amplifier_input[2];
    Sig_ADXT_Pause_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Pause_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Pause_ADXTHandle;

typedef struct Sig_ADXT_Stop_AdxSjdHandle Sig_ADXT_Stop_AdxSjdHandle;

typedef struct Sig_ADXT_Stop_ADXStream Sig_ADXT_Stop_ADXStream;

typedef struct Sig_ADXT_Stop_AXRNAHandle Sig_ADXT_Stop_AXRNAHandle;

typedef struct Sig_ADXT_Stop_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK;

typedef void (*Sig_ADXT_Stop_SJErrorCallback)(void *object, int error);

typedef struct Sig_ADXT_Stop_SJInterface Sig_ADXT_Stop_SJInterface;

typedef struct Sig_ADXT_Stop_SJ Sig_ADXT_Stop_SJ;

struct Sig_ADXT_Stop_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ *sj);
    void (*reset)(Sig_ADXT_Stop_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};

struct Sig_ADXT_Stop_SJ {
    const Sig_ADXT_Stop_SJInterface *interface;
};

typedef struct Sig_ADXT_Stop_ADX_AMP Sig_ADXT_Stop_ADX_AMP;

typedef struct Sig_ADXT_Stop_LSCObject Sig_ADXT_Stop_LSCObject;

typedef struct Sig_ADXT_Stop_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Stop_AdxSjdHandle *decoder;
    Sig_ADXT_Stop_ADXStream *stream;
    Sig_ADXT_Stop_AXRNAHandle *rna;
    Sig_ADXT_Stop_SJ *stream_sj;
    Sig_ADXT_Stop_SJ *input_sj;
    Sig_ADXT_Stop_SJ *output_sj[2];
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
    Sig_ADXT_Stop_ADX_AMP *amplifier;
    Sig_ADXT_Stop_SJ *amplifier_input[2];
    Sig_ADXT_Stop_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Stop_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Stop_ADXTHandle;

typedef struct {
    u8 unk[0xb];
    u8 value;
} Entry;

typedef struct {
    u8 pad_0[2];
    s16 unk_2;
    u8 pad_4[8];
    u32 unk_C;
    u8 pad_10[0x10];
} Obj_1_bss_25E9C;

typedef struct {
    u8 pad[0x2f8];
    u32 value_2f8;
    u32 value_2fc;
    u32 value_300;
    u32 value_304;
    u32 value_308;
    u32 value_30c;
    u32 value_310;
    u32 value_314;
    u32 value_318;
    u32 value_31c;
} Fn40710Config;
extern void fn_1_15E330(s32 index, u32 value, void *arg);
extern void fn_1_15E5E4(s32 index, void *arg);
extern void fn_1_15E688(s32 index, u32 value, u8 state, void *arg);
extern void fn_1_15E3E0(s32 index, u32 value);
extern void fn_1_15E434(u32 value);
extern void fn_1_15E540(s32 index, void *arg);
extern void fn_1_CB404(u8 value);
extern void fn_1_D07C4(u32 arg0, u32 arg1);
extern u32 lbl_1_bss_25B84;
extern u32 OSGetTick(void);
extern void fn_1_A0978(void);
extern void fn_1_35174(void);
extern s32 fn_1_3EFA8(void);
extern u16 lbl_1_bss_26B7A[3];
extern u16 lbl_1_bss_26300;
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern u32 fn_1_101C0(void);
extern u32 fn_1_A11EC(void);
extern u32 fn_1_435C(u32 value);
extern void ADXT_Pause(Sig_ADXT_Pause_ADXTHandle *, s32);
extern void fn_1_4310(u32 arg0);
extern void fn_1_48004(s32 index, s32 image);
extern void fn_1_8616C(void);
extern void fn_1_A1588(u32 arg0, u32 arg1);
extern void fn_1_D0790(void);
extern void fn_1_817C0(void);
extern u32 lbl_1_bss_381FC;
extern void fn_1_EB080(int mode);
extern s64 OSGetTime(void);
extern void fn_1_4A00(u32 arg0, u32 arg1, u32 arg2);
extern void fn_1_5370(u32 arg0, u32 arg1);
extern void fn_1_15E27C(void);
extern void fn_1_4811C(int arg);
extern void fn_1_A8F78(void);
extern u8 lbl_1_bss_262F4;
extern u32 lbl_1_bss_25E74[7];
extern u8 lbl_1_bss_3C10;
extern void fn_1_36330(void);
extern void fn_1_36B10(void);
extern void fn_1_3C98(void);
extern void fn_1_37AA8(void);
extern void fn_1_37E98(void);
extern f32 lbl_1_bss_26304[4];
extern u8 lbl_1_bss_26B04[20];
extern u8 lbl_1_bss_26314[2032];
extern s16 fn_1_12EF24(s16 row, s16 column);
extern u8 lbl_1_bss_523C[32];
extern Entry *lbl_1_bss_53F8[34];
extern void OSPanic(const void *, u32, const char *, ...);
extern Obj_1_bss_25E9C lbl_1_bss_25E9C[30];
extern void fn_1_12AB38(void *arg0);
extern void fn_1_465D0(char *value, u32 flag);
extern void* fn_1_7F518(s16 car_type, void* car, s32 initialize);
extern int sprintf(char *s, const char *format, ...);
extern void fn_1_451E4(void);
extern void fn_1_D3214(void);
extern void VIWaitForRetrace(void);
extern u32 fn_1_467F4(void);
extern u32 fn_1_13018(void);
extern u32 fn_1_46C60(void);
extern u32 lbl_1_bss_26C2C[2];
extern u32 lbl_1_bss_262F8[2];
extern u16 lbl_1_bss_26C68[35526];
extern u32 lbl_1_bss_3C08[2];
extern u32 fn_800075AC(u32, u32, u32);
extern u32 ghost_test_record_flag0(s32 arg);
extern u32 fn_1_F9D44(u32 arg);
extern u8 fn_1_F8C50(s32 arg0);
extern void fn_1_2DB50(void);
extern void fn_1_3F8C(void *, void *, Obj_1_bss_5138 *, int);
extern void fn_1_2D888(void);
extern void fn_1_2D524(void);
extern u32 fn_1_FA070(void);
extern int fn_1_FA180(int, u8);
extern u32 fn_1_F9FEC(void);
extern void fn_1_A2DC4(u32 arg0);
extern Fn40710Config lbl_1_rodata_BD8;
extern u8 lbl_1_bss_26B54[8];
extern u32 fn_1_40EE4(void);
extern u32 lbl_801A63D0;
extern u32 lbl_1_bss_26C34[9];
extern u8 lbl_1_bss_38218[568];
extern u32 fn_1_4060(void);
extern void ARQPostRequest(u8 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, u32 arg7);
extern u32 lbl_801A63C0;
extern void fn_1_40BE4(void);
extern u32 GXGetTexBufferSize(u32, u32, u32, u32, u32);
extern u32 lbl_1_bss_26B4C;
extern u8 lbl_1_bss_25E90[8];
extern s32 fn_1_48B0(u32 arg0, u32 arg1);
extern void fn_1_40F54(void *arg0);
extern u32 lbl_801A6CE0;
extern u32 lbl_1_bss_38454;
extern u32 fn_80070DE0(u32 arg0);
extern void fn_1_D3884();
extern void fn_1_D358C();
extern void fn_800711A8(Obj_1_bss_38458_Target *target);
extern void fn_80071718(u32 value);
extern void fn_1_41134(void *unused, char *value);
extern void fn_1_411D4(u32, char *);
extern int DVDConvertPathToEntrynum(char *buffer);
extern void fn_1_412A0(u32 index);
extern size_t strlen(const char *str);
extern int fn_80083BCC(const char *s1, const char *s2);
extern u8 lbl_1_A9011300;
extern u8 lbl_1_A9011100;
extern u8 lbl_1_A9011000;

/* fzgx:begin fn_1_2FDBC */
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 fzgx_obj_lbl_1_bss_3C08[2];
u8 fzgx_obj_lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u8 fzgx_obj_lbl_1_bss_3C12;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b5;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b7;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b8;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b9;
u8 fzgx_obj_lbl_1_bss_3C1C[14];
s16 fzgx_obj_lbl_1_bss_3C2A;
u32 lbl_1_bss_3C2A__fzgx_offset_2;
u32 fzgx_obj_lbl_1_bss_3C30[1327];
u32 fzgx_obj_lbl_1_bss_50EC[5];
u32 fzgx_obj_lbl_1_bss_5100;
u32 fzgx_obj_lbl_1_bss_5104[13];
u32 fzgx_obj_lbl_1_bss_5138[65];
u32 fzgx_obj_lbl_1_bss_523C[8];
u32 fzgx_obj_lbl_1_bss_525C[102];
u16 fzgx_obj_lbl_1_bss_53F4;
u32 fzgx_obj_lbl_1_bss_53F8[34];
u32 fzgx_obj_lbl_1_bss_5480[33216];
u16 fzgx_obj_lbl_1_bss_25B80;
u32 fzgx_obj_lbl_1_bss_25B84;
u32 fzgx_obj_lbl_1_bss_25B88[4];
u16 fzgx_obj_lbl_1_bss_25B98;
u32 fzgx_obj_lbl_1_bss_25B9C;
u32 fzgx_obj_lbl_1_bss_25BA0[42];
u32 fzgx_obj_lbl_1_bss_25C48[23];
u32 fzgx_obj_lbl_1_bss_25CA4[11];
u32 fzgx_obj_lbl_1_bss_25CD0[105];
u32 fzgx_obj_lbl_1_bss_25E74[7];
u32 fzgx_obj_lbl_1_bss_25E90[2];
u8 fzgx_obj_lbl_1_bss_25E98;
u32 fzgx_obj_lbl_1_bss_25E9C[240];
u32 fzgx_obj_lbl_1_bss_2625C[8];
u32 fzgx_obj_lbl_1_bss_2627C[30];
u8 fzgx_obj_lbl_1_bss_262F4;
u32 fzgx_obj_lbl_1_bss_262F8[2];
u16 fzgx_obj_lbl_1_bss_26300;
u32 fzgx_obj_lbl_1_bss_26304[4];
u32 fzgx_obj_lbl_1_bss_26314[508];
u32 fzgx_obj_lbl_1_bss_26B04[5];
u8 fzgx_obj_lbl_1_bss_26B18;
u8 fzgx_obj_lbl_1_bss_26B19;
u8 fzgx_obj_lbl_1_bss_26B1A;
u8 fzgx_pool_fzgx_pad_26B1B;
u8 fzgx_pool_fzgx_pad_26B1C;
u8 fzgx_obj_lbl_1_bss_26B1D;
u8 fzgx_obj_lbl_1_bss_26B1E;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b42;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b43;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b44;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b45;
u32 fzgx_obj_lbl_1_bss_26B4C;
u32 fzgx_obj_lbl_1_bss_26B50;
u32 fzgx_obj_lbl_1_bss_26B54[2];
u8 fzgx_obj_lbl_1_bss_26B5C[30];
u8 fzgx_obj_lbl_1_bss_26B7A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
u32 fzgx_obj_lbl_1_bss_26B80[42];

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_3C00;
    s = fzgx_obj_lbl_1_bss_3C04;
    s = fzgx_obj_lbl_1_bss_3C08[0];
    s = fzgx_obj_lbl_1_bss_3C10;
    s = fzgx_obj_lbl_1_bss_3C11;
    s = fzgx_obj_lbl_1_bss_3C12;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b5;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b7;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b8;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b9;
    s = fzgx_obj_lbl_1_bss_3C1C[0];
    s = fzgx_obj_lbl_1_bss_3C2A;
    s = lbl_1_bss_3C2A__fzgx_offset_2;
    s = fzgx_obj_lbl_1_bss_3C30[0];
    s = fzgx_obj_lbl_1_bss_50EC[0];
    s = fzgx_obj_lbl_1_bss_5100;
    s = fzgx_obj_lbl_1_bss_5104[0];
    s = fzgx_obj_lbl_1_bss_5138[0];
    s = fzgx_obj_lbl_1_bss_523C[0];
    s = fzgx_obj_lbl_1_bss_525C[0];
    s = fzgx_obj_lbl_1_bss_53F4;
    s = fzgx_obj_lbl_1_bss_53F8[0];
    s = fzgx_obj_lbl_1_bss_5480[0];
    s = fzgx_obj_lbl_1_bss_25B80;
    s = fzgx_obj_lbl_1_bss_25B84;
    s = fzgx_obj_lbl_1_bss_25B88[0];
    s = fzgx_obj_lbl_1_bss_25B98;
    s = fzgx_obj_lbl_1_bss_25B9C;
    s = fzgx_obj_lbl_1_bss_25BA0[0];
    s = fzgx_obj_lbl_1_bss_25C48[0];
    s = fzgx_obj_lbl_1_bss_25CA4[0];
    s = fzgx_obj_lbl_1_bss_25CD0[0];
    s = fzgx_obj_lbl_1_bss_25E74[0];
    s = fzgx_obj_lbl_1_bss_25E90[0];
    s = fzgx_obj_lbl_1_bss_25E98;
    s = fzgx_obj_lbl_1_bss_25E9C[0];
    s = fzgx_obj_lbl_1_bss_2625C[0];
    s = fzgx_obj_lbl_1_bss_2627C[0];
    s = fzgx_obj_lbl_1_bss_262F4;
    s = fzgx_obj_lbl_1_bss_262F8[0];
    s = fzgx_obj_lbl_1_bss_26300;
    s = fzgx_obj_lbl_1_bss_26304[0];
    s = fzgx_obj_lbl_1_bss_26314[0];
    s = fzgx_obj_lbl_1_bss_26B04[0];
    s = fzgx_obj_lbl_1_bss_26B18;
    s = fzgx_obj_lbl_1_bss_26B19;
    s = fzgx_obj_lbl_1_bss_26B1A;
    s = fzgx_pool_fzgx_pad_26B1B;
    s = fzgx_pool_fzgx_pad_26B1C;
    s = fzgx_obj_lbl_1_bss_26B1D;
    s = fzgx_obj_lbl_1_bss_26B1E;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b42;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b43;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b44;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b45;
    s = fzgx_obj_lbl_1_bss_26B4C;
    s = fzgx_obj_lbl_1_bss_26B50;
    s = fzgx_obj_lbl_1_bss_26B54[0];
    s = fzgx_obj_lbl_1_bss_26B5C[0];
    s = fzgx_obj_lbl_1_bss_26B7A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
    s = fzgx_obj_lbl_1_bss_26B80[0];
}
#pragma section code_type ".text"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 15.0f;
    s = 1.0f;
    s = 10.0f;
    s = 1.25f;
    s = 0.10000000149011612f;
    s = 0.8999999761581421f;
    s = 0.0006000000284984708f;
    s = 0.4000000059604645f;
    s = 0.75f;
    s = 70.0f;
    s = 0.5f;
    s = 36.0f;
    s = 16.0f;
    s = 45.0f;
    s = 0.0007999999797903001f;
    s = 18.0f;
    s = 50.0f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table5[52] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = 80.0f;
    s = 60.0f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table9[2] = {0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 470.0f;
    s = 0.0625f;
    s = 14.0f;
    s = 127.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table11[3] = {0x03E8FED4, 0xFE70FE0C, 0xFE0CFE0C};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 10000.0f;
    s = 15000.0f;
    s = 9999.0f;
}
static const u32 fzgx_pool_table13[2] = {0xFFFFFF00, 0x80808000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 240.0f;
    s = 280.0f;
    s = 200.0f;
    s = 40.0f;
    s = 30.0f;
}
static const u32 fzgx_pool_table15[8] = {0x80808000, 0xFFFFFF00, 0x80808000, 0xFFFFFF00, 0xFFFFFF00, 0x00000000, 0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.05000000074505806f;
    s = 0.15000000596046448f;
    s = 0.07999999821186066f;
    s = 2.0f;
    s = 4.0f;
    s = 255.0f;
    s = 1.100000023841858f;
    s = 38.0f;
    s = 20.0f;
    s = 180.0f;
    s = 3.0f;
    s = 0.00019999999494757503f;
    s = 100.0f;
    s = 75.0f;
    s = 0.00039999998989515007f;
    s = 150.0f;
}
static const u32 fzgx_pool_table17[7] = {0xFFF200FF, 0xFFF200FF, 0x80808080, 0xFFFFFF96, 0xFFF200FF, 0xFFF200FF, 0xFFFFFF96};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.009999999776482582f;
    s = 1000.0f;
    d = 20.0;
}
#pragma section code_type ".text"

struct fn_1_2FDBC_sub {
    u8 pad_0[0xB];
    u8 unk_B;
};
struct fn_1_2FDBC_flags {
    u32 unk_0;
    u8 unk_4;
    u8 unk_5;
};
struct fn_1_2FDBC_lbl_1_bss_3C00 {
    u8 pad_0[0x2A];
    s16 unk_2A;
    u8 pad_2C[0x4];
    u32 unk_30;
    u8 pad_34[0x17C4];
    struct fn_1_2FDBC_sub *unk_17F8;
};
struct fn_1_2FDBC_G {
    u8 pad_0[0x8B4];
    u8 unk_8B4;
    u8 unk_8B5;
    u16 unk_8B6;
};
struct fn_1_2FDBC_T {
    u8 pad_0[0x1E0];
    u8 unk_1E0;
    u8 unk_1E1;
    u16 unk_1E2;
    u32 unk_1E4;
};
struct fn_1_2FDBC_arg {
    u32 unk_0;
    s16 unk_4;
    s16 unk_6;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad_18[0x14];
    f32 unk_2C;
    u8 pad_30[0x1F0];
    f32 unk_220;
    u8 pad_224[0x8];
    f32 unk_22C;
    u8 pad_230[0x244];
    s8 unk_474;
    u8 pad_475[0x27];
    struct fn_1_2FDBC_T *unk_49C;
};
struct fn_1_2FDBC_loc {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    u8 pad_24[0x94];
};
extern s32 fn_1_3EFA8(void);
extern struct fn_1_2FDBC_G *lbl_801A66CC;
extern void fn_1_82EDC(s32, s32, void *);
extern void fn_1_22B10(void *, f32);

#pragma opt_propagation off
static inline void fn_1_2FDBC_set(struct fn_1_2FDBC_flags *f) {
    f->unk_5 = 6;
}
#pragma opt_propagation reset

void fn_1_2FDBC(struct fn_1_2FDBC_arg *arg0) {
    s32 sum;
    s32 flag;
    f32 ms;
    f32 t;
    struct fn_1_2FDBC_loc loc;
    s32 lab_t1;

    flag = 0;
    if (fn_1_3EFA8() != 0) {
        return;
    }
    switch (fzgx_obj_lbl_1_bss_3C2A) {
    case 41:
        break;
    default:
        return;
    }
    if (fzgx_obj_lbl_1_bss_3C30[0] & 0x800) {
        return;
    }
    sum = lbl_801A66CC->unk_8B4;
    sum += lbl_801A66CC->unk_8B5;
    sum += lbl_801A66CC->unk_8B6;
    if (!(arg0->unk_0 & 0x10000)) {
        fn_1_82EDC(arg0->unk_474, (arg0->unk_6), &loc);
        if (((struct fn_1_2FDBC_sub *)fzgx_obj_lbl_1_bss_53F8[0]) != 0) {
            t = ((struct fn_1_2FDBC_sub *)fzgx_obj_lbl_1_bss_53F8[0])->unk_B;
            t *= 0.01f;
            fn_1_22B10(&loc, t);
        } else {
            t = lbl_1_bss_25C48.unk_0;
            t *= 0.01f;
            fn_1_22B10(&loc, t);
        }
        if (loc.unk_4 != arg0->unk_8) {
            flag = 1;
        }
        if (loc.unk_10 != arg0->unk_C) {
            flag = 1;
        }
        if (loc.unk_20 != arg0->unk_14) {
            flag = 1;
        }
        if (loc.unk_1C != arg0->unk_2C) {
            flag = 1;
        }
        if (loc.unk_8 != arg0->unk_220) {
            flag = 1;
        }
        if (loc.unk_C != arg0->unk_22C) {
            flag = 1;
        }
    } else if (sum == 0) {
        lbl_801A66CC->unk_8B4 = arg0->unk_49C->unk_1E0;
        lbl_801A66CC->unk_8B5 = arg0->unk_49C->unk_1E1;
        lbl_801A66CC->unk_8B6 = arg0->unk_49C->unk_1E2;
        if (lbl_801A66CC->unk_8B4 == 0 && lbl_801A66CC->unk_8B5 < 20) {
            flag = 1;
        }
        ms = lbl_801A66CC->unk_8B5 + lbl_801A66CC->unk_8B4 * 60;
        ms *= 60.0f;
        ms += ((((f32)lbl_801A66CC->unk_8B6) * (60.0f))) / 1000.0f;
        if (__fabs(ms - (f32)arg0->unk_49C->unk_1E4) > 20.0) {
            flag = 1;
        }
    }
    if (flag != 0) {
        fn_1_2FDBC_set((struct fn_1_2FDBC_flags *)fzgx_obj_lbl_1_bss_3C30);
    }
}
/* fzgx:end fn_1_2FDBC */

/* fzgx:begin fn_1_3181C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"

typedef struct {
    u8 pad_0[6];
    s16 unk_6;
    u8 pad_8[0x34];
    u8 unk_3C[0x438];
    u8 unk_474;
    s8 unk_475;
    u8 pad_476[0x26];
    u32 unk_49C;
    u8 pad_4A0[0x180];
} GameResult;
typedef struct {
    u32 unk_0;
    u8 pad_4[0x1E];
    u16 unk_22;
    u8 pad_24[0x58];
    u8 unk_7C;
    u8 unk_7D;
    u8 unk_7E;
    u8 pad_7F;
    u8 unk_80;
    u8 unk_81;
    u8 unk_82;
    u8 pad_83;
    u16 unk_84;
    u16 unk_86;
    u16 unk_88;
    u16 unk_8A;
    u16 unk_8C;
    u16 unk_8E;
    u32 unk_90;
    u32 unk_94;
    u16 unk_98;
    u16 unk_9A;
    u16 unk_9C;
    u8 pad_9E[2];
} GamePlayer;
typedef struct {
    u8 pad_0[5];
    u8 unk_5;
    u8 pad_6[2];
    u8 unk_8;
    u8 unk_9;
    u8 pad_A[0x22];
    u32 unk_2C[4];
    u8 pad_3C[0x98];
    GamePlayer players[4];
    u8 pad_354[0x1394 - 0x354];
    u8 unk_1394[4];
    u8 pad_1398[0x14BC - 0x1398];
} GameState;
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 pad_2[9];
    u8 unk_B;
} GameSub;
typedef struct {
    u8 pad_0[5];
    u8 unk_5;
    u8 pad_6[0x819A];
    u8 unk_81A0;
    u8 pad_81A1[3];
    u8 unk_81A4;
    u8 pad_81A5[7];
    u8 unk_81AC;
    u8 pad_81AD[7];
    u8 unk_81B4;
    u8 pad_81B5[0xB];
} GameRacer;
typedef struct {
    u16 unk_0;
    u8 pad_2[2];
    u32 unk_4;
    u8 unk_8;
    u8 pad_9[3];
    u32 unk_C;
    u8 pad_10[0x10];
} GameEntry;
/* .bss: lbl_1_bss_3C00 +[0, 0x22702) */
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 fzgx_obj_lbl_1_bss_3C08[0x2];
u8 fzgx_obj_lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u8 fzgx_obj_lbl_1_bss_3C12;
u8 lbl_1_bss_3C12__fzgx_offset_1;
u8 lbl_1_bss_3C12__fzgx_offset_2[0x8];
u8 fzgx_obj_lbl_1_bss_3C1C[0xE];
u8 fzgx_obj_lbl_1_bss_3C2A;
u8 lbl_1_bss_3C2A__fzgx_offset_1;
u32 lbl_1_bss_3C2A__fzgx_offset_2;
GameState fzgx_obj_lbl_1_bss_3C30;
u16 fzgx_obj_lbl_1_bss_50EC[0xA];
u32 fzgx_obj_lbl_1_bss_5100;
u8 fzgx_obj_lbl_1_bss_5104[0x34];
u8 fzgx_obj_lbl_1_bss_5138[0x104];
u8 fzgx_obj_lbl_1_bss_523C[0x20];
u8 fzgx_obj_lbl_1_bss_525C[0x198];
u16 fzgx_obj_lbl_1_bss_53F4;
u8 fzgx_pool_gap_bss_53F6;
u8 fzgx_pool_gap_bss_53F7;
GameSub *fzgx_obj_lbl_1_bss_53F8[0x22];
GameRacer fzgx_obj_lbl_1_bss_5480[4];
u16 fzgx_obj_lbl_1_bss_25B80;
u8 fzgx_pool_gap_bss_25B82;
u8 fzgx_pool_gap_bss_25B83;
u32 fzgx_obj_lbl_1_bss_25B84;
u32 fzgx_obj_lbl_1_bss_25B88[0x4];
u16 fzgx_obj_lbl_1_bss_25B98;
u8 fzgx_pool_gap_bss_25B9A;
u8 fzgx_pool_gap_bss_25B9B;
u32 fzgx_obj_lbl_1_bss_25B9C;
u32 fzgx_obj_lbl_1_bss_25BA0[0x2A];
s16 fzgx_obj_lbl_1_bss_25C48[0x2E];
u32 fzgx_obj_lbl_1_bss_25CA4[0xB];
u32 fzgx_obj_lbl_1_bss_25CD0[0x69];
u32 fzgx_obj_lbl_1_bss_25E74[0x7];
u8 fzgx_obj_lbl_1_bss_25E90[0x8];
u32 fzgx_obj_lbl_1_bss_25E98;
GameEntry fzgx_obj_lbl_1_bss_25E9C[0x1E];
u8 fzgx_obj_lbl_1_bss_2625C[0x20];
u32 fzgx_obj_lbl_1_bss_2627C[0x1E];
u8 fzgx_obj_lbl_1_bss_262F4;
u8 fzgx_pool_gap_bss_262F5;
u8 fzgx_pool_gap_bss_262F6;
u8 fzgx_pool_gap_bss_262F7;
u32 fzgx_obj_lbl_1_bss_262F8;
u8 lbl_1_bss_262F8__fzgx_offset_4[4];
u16 fzgx_obj_lbl_1_bss_26300;
#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C00;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C04;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C08;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C10;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C11;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C12;
    s = *(u8 *)&lbl_1_bss_3C12__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_3C12__fzgx_offset_2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C1C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C2A;
    s = *(u8 *)&lbl_1_bss_3C2A__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_3C2A__fzgx_offset_2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C30;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_50EC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5100;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5104;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5138;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_523C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_525C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_53F4;
    s = *(u8 *)&fzgx_pool_gap_bss_53F6;
    s = *(u8 *)&fzgx_pool_gap_bss_53F7;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_53F8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5480;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25B80;
    s = *(u8 *)&fzgx_pool_gap_bss_25B82;
    s = *(u8 *)&fzgx_pool_gap_bss_25B83;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25B84;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25B88;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25B98;
    s = *(u8 *)&fzgx_pool_gap_bss_25B9A;
    s = *(u8 *)&fzgx_pool_gap_bss_25B9B;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25B9C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25BA0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25C48;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25CA4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25CD0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E74;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E90;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E98;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E9C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_2625C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_2627C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_262F4;
    s = *(u8 *)&fzgx_pool_gap_bss_262F5;
    s = *(u8 *)&fzgx_pool_gap_bss_262F6;
    s = *(u8 *)&fzgx_pool_gap_bss_262F7;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_262F8;
    s = *(u8 *)&lbl_1_bss_262F8__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26300;
}
#pragma section code_type ".text"

static u8 fzgx_pool_lbl_1_data_6400[0x11] = {  /* fzgx-allow: A1 retail data bytes: lbl_1_data_6400 +0x0 */
    0x63, 0x61, 0x72, 0x5F, 0x73, 0x74, 0x61, 0x74, 0x75, 0x73, 0x5F, 0x63, 0x68, 0x65, 0x63, 0x6B,
    0x00,
};

extern u32 lbl_801A6410;
extern void fn_1_81808(s8 *);
extern void fn_1_80058(u8, GameEntry *);
extern u32 fn_1_8171C(s32);
extern GameRacer *fn_1_36AD0(void);
extern void fn_1_14F38C(GameEntry *, GameRacer *);
extern u32 fn_80008E84(u32);
extern GameResult *fn_1_83070(u32, u32, GameEntry *, u8);
extern void fn_1_2FDBC();
extern u32 fn_1_435C(u32 value);
extern u16 fn_1_3F8C(void *, void *, void *, int);

void fn_1_3181C(void)
{
    s8 slots[4];
    u32 bits[4] = { 0x80000000, 0x40000000, 0x20000000, 0x10000000 };
    GameEntry *e;
    GameResult *res;
    GameSub *sub;
    GameRacer *racer;
    u32 heap;
    s32 i;
    s16 slot;
    GamePlayer *pl;
    s8 t;
    s32 k;

    fn_1_81808(slots);
    for (i = 0; i < fzgx_obj_lbl_1_bss_3C30.unk_9; i++) {
        e = &fzgx_obj_lbl_1_bss_25E9C[i];
        fn_1_80058(fzgx_obj_lbl_1_bss_2625C[i], e);
        e->unk_0 = i;
        e->unk_8 = fzgx_obj_lbl_1_bss_523C[i];
        e->unk_C = fzgx_obj_lbl_1_bss_2627C[i];
        e->unk_4 = fn_1_8171C(1);
        slot = -1;
        for (k = 0; k < 4; k++) {
            if (slots[k] == i) {
                slots[k] = -1;
                slot = k;
            }
        }
        if (i < fzgx_obj_lbl_1_bss_3C30.unk_8) {
            if (fzgx_obj_lbl_1_bss_3C30.unk_8 > 1) {
                e->unk_4 = fn_1_8171C(2);
                switch (e->unk_8) {
                case 1:
                    e->unk_8 = 0x10;
                    break;
                case 2:
                    e->unk_8 = 0x20;
                    break;
                case 4:
                    e->unk_8 = 0x40;
                    break;
                case 8:
                    e->unk_8 = 0x80;
                    break;
                }
            } else {
                e->unk_4 = fn_1_8171C(0);
                e->unk_C |= bits[i];
            }
            if (slot != -1) {
                racer = fn_1_36AD0() + slot;
                fn_1_14F38C(e, racer);
            }
        }
        if (fzgx_obj_lbl_1_bss_3C30.unk_8 == 0) {
            if (i < fzgx_obj_lbl_1_bss_262F4 || i == 0) {
                e->unk_4 = fn_1_8171C(0);
                e->unk_C |= 0x80000000;
                e->unk_8 = 1;
            }
        }
    }
    heap = fn_80008E84(fzgx_obj_lbl_1_bss_262F8);
    res = fn_1_83070(fzgx_obj_lbl_1_bss_25B88[0], fzgx_obj_lbl_1_bss_25CA4[0], fzgx_obj_lbl_1_bss_25E9C,
                     fzgx_obj_lbl_1_bss_3C30.unk_9);
    *(volatile u32 *)&lbl_801A6410;  /* fzgx-allow: S2 retail loads the heap handle here and discards it */
    fn_80008E84(heap);
    for (i = 0; i < fzgx_obj_lbl_1_bss_3C30.unk_9; i++) {
        pl = &fzgx_obj_lbl_1_bss_3C30.players[i];
        pl->unk_0 = (u32)res[i].unk_3C;
        t = res[i].unk_475;
        if (t != -1) {
            lbl_1_bss_262F8__fzgx_offset_4[t] = res[i].unk_474;
        }
        fzgx_obj_lbl_1_bss_3C30.unk_1394[i] = i;
        fzgx_obj_lbl_1_bss_3C30.unk_2C[i] = res[i].unk_49C;
        pl->unk_7C = 0xFF;
        pl->unk_7D = 0xFF;
        pl->unk_7E = 0xFF;
        pl->unk_80 = res[i].unk_6;
        pl->unk_82 = res[i].unk_6;
        pl->unk_81 = fzgx_obj_lbl_1_bss_25C48[i];
        pl->unk_22 = 0;
        pl->unk_84 = 0;
        pl->unk_8A = 0;
        pl->unk_86 = 0;
        pl->unk_88 = 0;
        pl->unk_8C = 0;
        pl->unk_8E = 0;
        pl->unk_98 = 0;
        pl->unk_90 = 0;
        pl->unk_94 = 0;
        pl->unk_9A = 0;
        pl->unk_9C = 0;
        if (fzgx_obj_lbl_1_bss_3C30.unk_5 == 2 && i == 0) {
            fn_1_435C(fzgx_obj_lbl_1_bss_25B88[0]);
            fzgx_obj_lbl_1_bss_26300 = fn_1_3F8C(fzgx_pool_lbl_1_data_6400, fn_1_2FDBC, res, 0x1E);
        }
        sub = fzgx_obj_lbl_1_bss_53F8[i];
        if (sub != NULL) {
            pl->unk_81 = sub->unk_B;
            if (sub->unk_1 >= 0x29) {
                t = res[i].unk_474;
                if (t != -1) {
                    racer = &fzgx_obj_lbl_1_bss_5480[t];
                    pl->unk_80 = racer->unk_81A0;
                    pl->unk_82 = racer->unk_5;
                    pl->unk_7C = racer->unk_81A4;
                    pl->unk_7D = racer->unk_81AC;
                    pl->unk_7E = racer->unk_81B4;
                }
            } else {
                pl->unk_80 = pl->unk_82 = sub->unk_1;
            }
        }
    }
}
/* fzgx:end fn_1_3181C */

/* fzgx:begin fn_1_31C3C noprologue */
#include "types.h"

typedef struct Record {
    u32 time;      /* 0x00 */
    u32 lap;       /* 0x04 */
    u8 pad_8[0x10];
    u16 speed;     /* 0x18 */
    u8 c1A;
    u8 c1B;
    u8 c1C;
    u8 c1D;
    u8 c1E;
    u8 c1F;
} Record;

typedef struct RecordTable {
    Record ranking[10];  /* 0x000 */
    Record bestLap;      /* 0x140 */
    u16 maxSpeed;        /* 0x160 */
    u8 s162;
    u8 pad_163;
    u8 s164;
    u8 s165;
    u8 s166;
    u8 s167;
    u8 s168;
} RecordTable;

typedef struct RaceResult {
    u8 pad_0[0x18];
    u16 speed[6];   /* 0x18 */
    u32 time[5];    /* 0x24 */
    u32 lap[5];     /* 0x38 */
    u8 pad_4C[0x30];
    u8 c7C;
    u8 c7D;
    u8 c7E;
    u8 pad_7F;
    u8 c80;
    u8 c81;
    u8 c82;
} RaceResult;

typedef struct GameState {
    u8 pad_0[6];
    u8 course;          /* 0x06 */
    u8 pad_7[0xCD];
    RaceResult result;  /* 0xD4 */
    u8 pad_158[0x1444 - 0x158];
    Record last;        /* 0x1444 */
    u8 pad_1464[0x14BC - 0x1464];
} GameState;

typedef struct Obj5138 {
    u16 mode;
    u8 pad_2[0xE1];
    u8 course;   /* 0xE3 */
} Obj5138;

typedef struct Obj801A66CC {
    u8 pad_0[0x8B4];
    u8 b8B4;
    u8 b8B5;
    u16 h8B6;
} Obj801A66CC;

typedef struct Obj8B3A0 {
    u8 pad_0[0x90];
    s16 unk_90;
} Obj8B3A0;

/* the TU's .bss, addressed off one section base */
static u32 lbl_1_bss_3C00;
static u32 fzgx_pool_fzgx_bss_gap00[0xB];
static GameState lbl_1_bss_3C30;
static u8 fzgx_pool_fzgx_record_layout_tail[0x4C];
static Obj5138 lbl_1_bss_5138;
static u32 fzgx_pool_fzgx_bss_gap0[(0x220D0 - 0x161C) / 4];
static RecordTable *lbl_1_bss_25CD0;
static u32 fzgx_pool_fzgx_bss_gap1[(0x22F08 - 0x220D4) / 4];
static u32 lbl_1_bss_26B04__fzgx_offset_4;
static u32 lbl_1_bss_26B04__fzgx_offset_8;
static u32 lbl_1_bss_26B04__fzgx_offset_C;

extern Obj801A66CC *lbl_801A66CC;
extern Obj8B3A0 lbl_1_bss_8B3A0;
extern void fn_1_1554D0(void);
extern s32 fn_1_1555B0(s32);
extern void fn_1_155F9C(u32);
extern void fn_1_155FA8(u32);
extern s32 fn_1_F1B84(void);
extern s32 fn_1_F2280(s32);
extern void fn_1_F220C(s32);
extern u32 fn_1_F2338(s32, u32);
extern u32 ghost_test_record_flag0(s32);

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_order(void) {
    volatile u32 s;  /* fzgx-allow: S2 layout primer sink */
    s = lbl_1_bss_3C00;
    s = fzgx_pool_fzgx_bss_gap00[0];
    s = lbl_1_bss_3C30.course;
    s = fzgx_pool_fzgx_record_layout_tail[0];
    s = lbl_1_bss_5138.mode;
    s = fzgx_pool_fzgx_bss_gap0[0];
    s = (u32)lbl_1_bss_25CD0;
    s = fzgx_pool_fzgx_bss_gap1[0];
    s = lbl_1_bss_26B04__fzgx_offset_4;
    s = lbl_1_bss_26B04__fzgx_offset_8;
    s = lbl_1_bss_26B04__fzgx_offset_C;
}
#pragma section code_type ".text"

void fn_1_31C3C(u32 player) {
    RaceResult *res = &lbl_1_bss_3C30.result;
    u32 time = res->time[player];
    u32 lap = res->lap[player];
    u32 i;

    for (i = 0; i < 10; i++) {
        if (time < lbl_1_bss_25CD0->ranking[i].time) {
            break;
        }
    }
    lbl_1_bss_26B04__fzgx_offset_4 = i;

    for (i = 9; i > lbl_1_bss_26B04__fzgx_offset_4; i--) {
        lbl_1_bss_25CD0->ranking[i] = lbl_1_bss_25CD0->ranking[i - 1];
    }

    if (lbl_1_bss_26B04__fzgx_offset_4 < 10) {
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B04__fzgx_offset_4].time = time;
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B04__fzgx_offset_4].lap = lap;
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B04__fzgx_offset_4].speed = res->speed[player];
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B04__fzgx_offset_4].c1A = res->c82;
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B04__fzgx_offset_4].c1B = res->c80;
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B04__fzgx_offset_4].c1C = res->c81;
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B04__fzgx_offset_4].c1D = res->c7C;
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B04__fzgx_offset_4].c1E = res->c7D;
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B04__fzgx_offset_4].c1F = res->c7E;
    }

    if (lap < lbl_1_bss_25CD0->bestLap.time) {
        lbl_1_bss_26B04__fzgx_offset_8 = 1;
        lbl_1_bss_25CD0->bestLap.time = lap;
        lbl_1_bss_25CD0->bestLap.lap = lap;
        lbl_1_bss_25CD0->bestLap.speed = res->speed[player];
        lbl_1_bss_25CD0->bestLap.c1A = res->c82;
        lbl_1_bss_25CD0->bestLap.c1B = res->c80;
        lbl_1_bss_25CD0->bestLap.c1C = res->c81;
        lbl_1_bss_25CD0->bestLap.c1D = res->c7C;
        lbl_1_bss_25CD0->bestLap.c1E = res->c7D;
        lbl_1_bss_25CD0->bestLap.c1F = res->c7E;
    } else {
        lbl_1_bss_26B04__fzgx_offset_8 = 0;
    }

    if (lbl_1_bss_25CD0->maxSpeed < res->speed[player]) {
        lbl_1_bss_26B04__fzgx_offset_C = 1;
        lbl_1_bss_25CD0->maxSpeed = res->speed[player];
        lbl_1_bss_25CD0->s162 = res->c82;
        lbl_1_bss_25CD0->s164 = res->c80;
        lbl_1_bss_25CD0->s165 = res->c81;
        lbl_1_bss_25CD0->s166 = res->c7C;
        lbl_1_bss_25CD0->s167 = res->c7D;
        lbl_1_bss_25CD0->s168 = res->c7E;
    } else {
        lbl_1_bss_26B04__fzgx_offset_C = 0;
    }

    lbl_1_bss_3C30.last.lap = lap;
    lbl_1_bss_3C30.last.speed = res->speed[player];
    lbl_1_bss_3C30.last.c1A = res->c82;
    lbl_1_bss_3C30.last.c1B = res->c80;
    lbl_1_bss_3C30.last.c1C = res->c81;
    lbl_1_bss_3C30.last.c1D = res->c7C;
    lbl_1_bss_3C30.last.c1E = res->c7D;
    lbl_1_bss_3C30.last.c1F = res->c7E;
    lbl_1_bss_3C30.last.time = ((lbl_801A66CC->b8B4 << 20) & 0xFF00000) | (lbl_801A66CC->b8B5 << 12) | lbl_801A66CC->h8B6;

    fn_1_1554D0();
    fn_1_1555B0(lbl_1_bss_8B3A0.unk_90);
    if (lbl_1_bss_26B04__fzgx_offset_4 < 10) {
        fn_1_155F9C(1);
        fn_1_155FA8(lbl_1_bss_26B04__fzgx_offset_4);
    } else {
        fn_1_155F9C(0);
        fn_1_155FA8(-1);
    }

    switch (fn_1_F1B84()) {
    case 1:
        if (fn_1_F2280(lbl_1_bss_3C30.course) == 0) {
            lbl_1_bss_5138.mode = 25;
            fn_1_F220C(lbl_1_bss_3C30.course);
        }
        break;
    }

    if (fn_1_F2338(lbl_1_bss_3C30.course, time) & 0xFF) {
        if ((s32)ghost_test_record_flag0(lbl_1_bss_3C30.course) == 0) {
            lbl_1_bss_5138.course = lbl_1_bss_3C30.course;
            lbl_1_bss_5138.mode = 10;
        }
    }
}
/* fzgx:end fn_1_31C3C */

/* fzgx:begin fn_1_32600 noprologue */
#include "types.h"
#include "rel/main_rel/game.h"

typedef struct {
    s32 unk_0;
    u8 pad_4[0x178];
    f32 unk_17c;
    u8 pad_180[0x94];
    u16 unk_214;
    u8 pad_216[0x25F];
    s8 unk_475;
    u8 pad_476[0x116];
    u32 unk_58c;
} FnObj_1_32600;

extern const f32 lbl_1_rodata_BD8[];
extern void fn_1_15E260(s32 arg0);
extern u16 lbl_1_bss_25B80;
extern u8 lbl_1_bss_26B1D;

#pragma optpointer_analysis off
#pragma opt_strength_reduction off
static inline const f32 fn_1_32600_array_read(const f32 *array, s32 index) { return array[index]; }
#pragma opt_strength_reduction reset

#pragma opt_loop_invariants off
typedef struct lbl_1_bss_3C30_t {
    u32 unk_0;
    u8 pad_4[0x1];
    u8 unk_5;
    u8 pad_6[0x9e];
    u16 unk_A4;
    u8 pad_A6[0x1416];
} lbl_1_bss_3C30_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
lbl_1_bss_3C30_t fzgx_obj_lbl_1_bss_3C30;

#pragma section code_type ".fzgxpool"

#pragma section code_type ".text"

int fn_1_32600(FnObj_1_32600* obj) {
    f32 fzgx_live;
    s32 cond;
    const f32* rodata;
    f32 lim;
    f32 fv;
    u32 count;
    s32 tmp_ra3;
    u32 lab_t0;

    rodata = lbl_1_rodata_BD8;
    if (!(fzgx_obj_lbl_1_bss_3C30.unk_0 & 0x00008000)) {
        if (obj->unk_0 & 0x08000000) {
            return 1;
        }
        if (obj->unk_58c & 0x00000010) {
            return 1;
        }
        tmp_ra3 = obj->unk_0;
        if (tmp_ra3 & 0x00000800) {
            if (obj->unk_475 != -1) {
                lab_t0 = obj->unk_475;
                fn_1_15E260(lab_t0);
            }
            return 1;
        }
        if (obj->unk_0 & 0x00000080) {
            if (obj->unk_475 != -1) {
                lab_t0 = obj->unk_475;
                fn_1_15E260(lab_t0);
            }
            if (fzgx_obj_lbl_1_bss_3C30.unk_5 != 5) {
                if ((obj->unk_0 & 0x00000200) || obj->unk_17c < fn_1_32600_array_read(rodata, 3)) {
                    return 1;
                }
            } else {
                return 1;
            }
        }
    }

    if ((fzgx_obj_lbl_1_bss_3C30.unk_0 & 0x00040000) && fzgx_obj_lbl_1_bss_3C30.unk_A4 == 0) {
        fzgx_live = obj->unk_17c;
        fv = fzgx_live;
        if (lbl_1_bss_25B80 < 0x12c) {
            lim = fn_1_32600_array_read(rodata, 3);
        } else if (lbl_1_bss_25B80 < 0x258) {
            lim = ((4)[rodata]);
        } else {
            lim = fn_1_32600_array_read(rodata, 121);
            fv = fn_1_32600_array_read(rodata, 1);
        }
        cond = (fv < lim);
        cond |= (obj->unk_214 != 0);
        if (obj->unk_0 & 0x00000800) {
            cond = 1;
        }
        lbl_1_bss_26B1D++;
        if (cond) {
            if (lbl_1_bss_26B1D > 0x1e) {
                obj->unk_0 |= 0x10000000;
                return 1;
            }
        }
    }

    if (((0x00080000) & (fzgx_obj_lbl_1_bss_3C30.unk_0))) {
        obj->unk_0 |= 0x10000000;
        return 1;
    }
    if (!(obj->unk_0 & 0x00010200) && lbl_1_bss_25B98 > 0x1a4) {
        return 1;
    }
    return 0;
}
#pragma opt_loop_invariants reset
#pragma opt_pointer_analysis reset
/* fzgx:end fn_1_32600 */

/* fzgx:begin fn_1_327F8 */
struct fn_1_327F8_Arg0 {
    u32 unk_0;
    s16 unk_4;
    u8 pad_6[0x46F];
    s8 unk_475;
    u8 pad_476[0x26];
    u32 unk_49C;
};
struct fn_1_327F8_lbl_1_bss_3C30 {
    u32 unk_0;
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[0x13B4 - 0x6];
    u32 unk_13B4;
    u8 pad_13B8[0x13D4 - 0x13B8];
    u32 unk_13D4;
    u8 pad_13D8[0x13F4 - 0x13D8];
    u8 unk_13F4;
    u8 unk_13F5;
    u8 pad_13F6[0x1468 - 0x13F6];
    u8 unk_1468;
    u8 pad_1469[0x1474 - 0x1469];
    u32 unk_1474;
};
struct fn_1_327F8_lbl_1_bss_25B88 {
    u32 unk_0;
};


void fn_1_327F8(struct fn_1_327F8_Arg0 *arg0, u32 arg1) {
    u8 *v0;
    s32 v1;
    u32 v5;
    u32 v2;
    u32 v3;
    u32 v4;

    v0 = (u8 *)arg0->unk_49C;
    v1 = arg0->unk_475;
    v2 = ((*(u8 *)(v0 + 0x174) << 20) | (*(u8 *)(v0 + 0x175) << 12)) | *(u16 *)(v0 + 0x176);
    v3 = ((*(u8 *)(v0 + 0x1e0) << 20) | (*(u8 *)(v0 + 0x1e1) << 12)) | *(u16 *)(v0 + 0x1e2);
    v5 = *(u32 *)(v0 + 0x118);

    if (arg0->unk_475 != -1) {
        if (v5 == 1 && ((*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_0 & 0x10) == 0) {
            fn_1_15E540(v1, (void *)(*((struct fn_1_327F8_lbl_1_bss_25B88 *)&lbl_1_bss_25B88)).unk_0);
        }
        if (v5 == ((*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_4 - 1) && (*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_5 != 3) {
            u32 a = (*((struct fn_1_327F8_lbl_1_bss_25B88 *)&lbl_1_bss_25B88)).unk_0;
            fn_1_15E5E4(arg0->unk_475, (void *)a);
        }
        fn_1_D07C4((u8)arg0->unk_475,
                   (((*(u8 *)(v0 + 0x1d4) << 20) | (*(u8 *)(v0 + 0x1d5) << 12)) | *(u16 *)(v0 + 0x1d6)));
        fn_1_CB404((u8)arg0->unk_475);
    }
    if ((s32)arg1 != -1) {
        *((u8 *)&(*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)) + 0x1468 + arg1) = (u8)v5;
    }
    if (v5 < 8) {
        *((u32 *)((u8 *)&(*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)) + 0x12c) + arg0->unk_4 * 0x28 + v5) = v2;
    }
    if (arg0->unk_475 != -1) {
        fn_1_15E688(arg0->unk_475, v2, (u8)v5, (void *)(*((struct fn_1_327F8_lbl_1_bss_25B88 *)&lbl_1_bss_25B88)).unk_0);
    }
    if ((*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_1474 <= 0x50000 + 0x6ff4) {
        if ((arg0->unk_0 & 0x08000000) != 0) {
            v3 = 0;
        }
        if (*(u8 *)(v0 + 0x115) == 0) {
            if (v5 > (*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_13F4) {
                *(u32 *)((u8 *)&(*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)) + (((v5 - 1) & 3) << 2) + 0x13b4) = v3;
                (*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_13F4 = (u8)v5;
                fn_1_15E3E0(arg0->unk_475, v3);
            }
        } else {
            if (*(u8 *)(v0 + 0x115) == 1) {
                if (v5 > (*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_13F5) {
                    *(u32 *)((u8 *)&(*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)) + (((v5 - 1) & 3) << 2) + 0x13d4) = v3;
                    (*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_13F5 = (u8)v5;
                    fn_1_15E434((*((struct fn_1_327F8_lbl_1_bss_25B88 *)&lbl_1_bss_25B88)).unk_0);
                }
            }
            if (arg0->unk_475 != -1) {
                fn_1_15E330(arg0->unk_475, v3, (void *)(u32)((*((struct fn_1_327F8_lbl_1_bss_25B88 *)&lbl_1_bss_25B88)).unk_0));
            }
        }
    }
}
/* fzgx:end fn_1_327F8 */

/* fzgx:begin fn_1_331EC noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"
#include "font.h"
#include "font.h"

typedef struct Sig_ADXT_Pause_AdxSjdHandle Sig_ADXT_Pause_AdxSjdHandle;

typedef struct Sig_ADXT_Pause_ADXStream Sig_ADXT_Pause_ADXStream;

typedef struct Sig_ADXT_Pause_AXRNAHandle Sig_ADXT_Pause_AXRNAHandle;

typedef struct Sig_ADXT_Pause_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Pause_SJCK;

typedef void (*Sig_ADXT_Pause_SJErrorCallback)(void *object, int error);

typedef struct Sig_ADXT_Pause_SJInterface Sig_ADXT_Pause_SJInterface;

typedef struct Sig_ADXT_Pause_SJ Sig_ADXT_Pause_SJ;

struct Sig_ADXT_Pause_SJ {
    const Sig_ADXT_Pause_SJInterface *interface;
};

struct Sig_ADXT_Pause_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Pause_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Pause_SJ *sj);
    void (*reset)(Sig_ADXT_Pause_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, int max_size, Sig_ADXT_Pause_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, Sig_ADXT_Pause_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, Sig_ADXT_Pause_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Pause_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Pause_SJ *sj, Sig_ADXT_Pause_SJErrorCallback callback, void *object);
};

typedef struct Sig_ADXT_Pause_ADX_AMP Sig_ADXT_Pause_ADX_AMP;

typedef struct Sig_ADXT_Pause_LSCObject Sig_ADXT_Pause_LSCObject;

typedef struct Sig_ADXT_Pause_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Pause_AdxSjdHandle *decoder;
    Sig_ADXT_Pause_ADXStream *stream;
    Sig_ADXT_Pause_AXRNAHandle *rna;
    Sig_ADXT_Pause_SJ *stream_sj;
    Sig_ADXT_Pause_SJ *input_sj;
    Sig_ADXT_Pause_SJ *output_sj[2];
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
    Sig_ADXT_Pause_ADX_AMP *amplifier;
    Sig_ADXT_Pause_SJ *amplifier_input[2];
    Sig_ADXT_Pause_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Pause_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Pause_ADXTHandle;

typedef struct Sig_ADXT_Stop_AdxSjdHandle Sig_ADXT_Stop_AdxSjdHandle;

typedef struct Sig_ADXT_Stop_ADXStream Sig_ADXT_Stop_ADXStream;

typedef struct Sig_ADXT_Stop_AXRNAHandle Sig_ADXT_Stop_AXRNAHandle;

typedef struct Sig_ADXT_Stop_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK;

typedef void (*Sig_ADXT_Stop_SJErrorCallback)(void *object, int error);

typedef struct Sig_ADXT_Stop_SJInterface Sig_ADXT_Stop_SJInterface;

typedef struct Sig_ADXT_Stop_SJ Sig_ADXT_Stop_SJ;

struct Sig_ADXT_Stop_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ *sj);
    void (*reset)(Sig_ADXT_Stop_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};

struct Sig_ADXT_Stop_SJ {
    const Sig_ADXT_Stop_SJInterface *interface;
};

typedef struct Sig_ADXT_Stop_ADX_AMP Sig_ADXT_Stop_ADX_AMP;

typedef struct Sig_ADXT_Stop_LSCObject Sig_ADXT_Stop_LSCObject;

typedef struct Sig_ADXT_Stop_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Stop_AdxSjdHandle *decoder;
    Sig_ADXT_Stop_ADXStream *stream;
    Sig_ADXT_Stop_AXRNAHandle *rna;
    Sig_ADXT_Stop_SJ *stream_sj;
    Sig_ADXT_Stop_SJ *input_sj;
    Sig_ADXT_Stop_SJ *output_sj[2];
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
    Sig_ADXT_Stop_ADX_AMP *amplifier;
    Sig_ADXT_Stop_SJ *amplifier_input[2];
    Sig_ADXT_Stop_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Stop_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Stop_ADXTHandle;

typedef struct {
    u8 unk[0xb];
    u8 value;
} Entry;

typedef struct {
    u8 pad_0[2];
    s16 unk_2;
    u8 pad_4[8];
    u32 unk_C;
    u8 pad_10[0x10];
} Obj_1_bss_25E9C;

typedef struct {
    u8 pad[0x2f8];
    u32 value_2f8;
    u32 value_2fc;
    u32 value_300;
    u32 value_304;
    u32 value_308;
    u32 value_30c;
    u32 value_310;
    u32 value_314;
    u32 value_318;
    u32 value_31c;
} Fn40710Config;
extern void fn_1_15E330(s32 index, u32 value, void *arg);
extern void fn_1_15E5E4(s32 index, void *arg);
extern void fn_1_15E688(s32 index, u32 value, u8 state, void *arg);
extern void fn_1_15E3E0(s32 index, u32 value);
extern void fn_1_15E434(u32 value);
extern void fn_1_15E540(s32 index, void *arg);
extern void fn_1_CB404(u8 value);
extern void fn_1_D07C4(u32 arg0, u32 arg1);
extern u32 lbl_1_bss_25B84;
extern u32 OSGetTick(void);
extern void fn_1_A0978(void);
extern void fn_1_35174(void);
extern s32 fn_1_3EFA8(void);
extern u16 lbl_1_bss_26B7A[3];
extern u16 lbl_1_bss_26300;
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern u32 fn_1_101C0(void);
extern u32 fn_1_A11EC(void);
extern u32 fn_1_435C(u32 value);
extern void ADXT_Pause(Sig_ADXT_Pause_ADXTHandle *, s32);
extern void fn_1_4310(u32 arg0);
extern void fn_1_48004(s32 index, s32 image);
extern void fn_1_8616C(void);
extern void fn_1_A1588(u32 arg0, u32 arg1);
extern void fn_1_D0790(void);
extern void fn_1_817C0(void);
extern u32 lbl_1_bss_381FC;
extern void fn_1_EB080(int mode);
extern s64 OSGetTime(void);
extern void fn_1_4A00(u32 arg0, u32 arg1, u32 arg2);
extern void fn_1_5370(u32 arg0, u32 arg1);
extern void fn_1_15E27C(void);
extern void fn_1_4811C(int arg);
extern void fn_1_A8F78(void);
extern u8 lbl_1_bss_262F4;
extern u32 lbl_1_bss_25E74[7];
extern u8 lbl_1_bss_3C10;
extern void fn_1_36330(void);
extern void fn_1_36B10(void);
extern void fn_1_3C98(void);
extern void fn_1_37AA8(void);
extern void fn_1_37E98(void);
extern f32 lbl_1_bss_26304[4];
extern u8 lbl_1_bss_26B04[20];
extern u8 lbl_1_bss_26314[2032];
extern s16 fn_1_12EF24(s16 row, s16 column);
extern u8 lbl_1_bss_523C[32];
extern Entry *lbl_1_bss_53F8[34];
extern void OSPanic(const void *, u32, const char *, ...);
extern Obj_1_bss_25E9C lbl_1_bss_25E9C[30];
extern void fn_1_12AB38(void *arg0);
extern void fn_1_465D0(char *value, u32 flag);
extern void* fn_1_7F518(s16 car_type, void* car, s32 initialize);
extern int sprintf(char *s, const char *format, ...);
extern void fn_1_451E4(void);
extern void fn_1_D3214(void);
extern void VIWaitForRetrace(void);
extern u32 fn_1_467F4(void);
extern u32 fn_1_13018(void);
extern u32 fn_1_46C60(void);
extern u32 lbl_1_bss_26C2C[2];
extern u32 lbl_1_bss_262F8[2];
extern u16 lbl_1_bss_26C68[35526];
extern u32 lbl_1_bss_3C08[2];
extern u32 fn_800075AC(u32, u32, u32);
extern u32 ghost_test_record_flag0(s32 arg);
extern u32 fn_1_F9D44(u32 arg);
extern u8 fn_1_F8C50(s32 arg0);
extern void fn_1_2DB50(void);
extern void fn_1_3F8C(void *, void *, Obj_1_bss_5138 *, int);
extern void fn_1_2D888(void);
extern void fn_1_2D524(void);
extern u32 fn_1_FA070(void);
extern int fn_1_FA180(int, u8);
extern u32 fn_1_F9FEC(void);
extern void fn_1_A2DC4(u32 arg0);
extern Fn40710Config lbl_1_rodata_BD8;
extern u8 lbl_1_bss_26B54[8];
extern u32 fn_1_40EE4(void);
extern u32 lbl_801A63D0;
extern u32 lbl_1_bss_26C34[9];
extern u8 lbl_1_bss_38218[568];
extern u32 fn_1_4060(void);
extern void ARQPostRequest(u8 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, u32 arg7);
extern u32 lbl_801A63C0;
extern void fn_1_40BE4(void);
extern u32 GXGetTexBufferSize(u32, u32, u32, u32, u32);
extern u32 lbl_1_bss_26B4C;
extern u8 lbl_1_bss_25E90[8];
extern s32 fn_1_48B0(u32 arg0, u32 arg1);
extern void fn_1_40F54(void *arg0);
extern u32 lbl_801A6CE0;
extern u32 lbl_1_bss_38454;
extern u32 fn_80070DE0(u32 arg0);
extern void fn_1_D3884();
extern void fn_1_D358C();
extern void fn_800711A8(Obj_1_bss_38458_Target *target);
extern void fn_80071718(u32 value);
extern void fn_1_41134(void *unused, char *value);
extern void fn_1_411D4(u32, char *);
extern int DVDConvertPathToEntrynum(char *buffer);
extern void fn_1_412A0(u32 index);
extern size_t strlen(const char *str);
extern int fn_80083BCC(const char *s1, const char *s2);
extern u8 lbl_1_A9011300;
extern u8 lbl_1_A9011100;
extern u8 lbl_1_A9011000;


#ifndef GAME_MAIN_REL_GAME_TYPES_H
#define GAME_MAIN_REL_GAME_TYPES_H

#ifndef GAME_MAIN_REL_ADXT_STOP_TYPES_H
#define GAME_MAIN_REL_ADXT_STOP_TYPES_H

#endif  // GAME_MAIN_REL_ADXT_STOP_TYPES_H

#endif  // GAME_MAIN_REL_GAME_TYPES_H

typedef struct Track {
 u8 pad0[0xfc]; f32 unk_FC, unk_100; u8 pad104[0x14]; s32 unk_118,unk_11C;
} Track;
typedef struct Racer {
 u32 flags; s16 id,slot; u8 pad8[0x174]; f32 speed; u8 pad180[4]; f32 distance;
 u8 pad188[0x6c]; f32 a,b,c,d,e; u8 pad208[0x18]; f32 x; u8 pad224[8]; f32 y;
 u8 pad230[0x244]; s8 controller; u8 pad475[0x27]; Track *track; u8 pad4a0[0x3c]; f32 factor;
 u8 pad4e0[0xac]; u32 flags58c; u8 state;
} Racer;
typedef struct Config { u32 flags; u8 pad4; u8 mode; u8 pad6[0x26]; Track *track; u8 pad30[0x74]; u16 lock; u8 pada6[0x2a]; void (*callback)(struct Config*,Racer*); } Config;
/* The TU's .bss objects, in retail layout order: MWCC addresses them off one
   section base, materialising an object's address for any non-zero field. */
static u8 fzgx_obj_lbl_1_bss_3C00[4];
#define s_bss_0 fzgx_obj_lbl_1_bss_3C00
static u8 fzgx_pool_s_bss_4[0x26];
static s16 lbl_1_bss_3C2A__fzgx_offset_0;
static u8 lbl_1_bss_3C2A__fzgx_offset_2[4];
static Config lbl_1_bss_3C30__fzgx_offset_0;
static u8 fzgx_pool_s_bss_104[0x1624-0x104];
static u8 lbl_1_bss_5138__fzgx_offset_EC;
static u8 fzgx_pool_s_bss_1628[0x17f8-0x1628];
static u8 *lbl_1_bss_53F8__fzgx_offset_0[4];
static u8 fzgx_pool_s_bss_1808[0x22048-0x1808];
static s16 lbl_1_bss_25C48__fzgx_offset_0[4];
static u8 fzgx_pool_s_bss_22050[0x22f20-0x22050];
static u8 lbl_1_bss_26B1E__fzgx_offset_2[4];
static u8 lbl_1_bss_26B1E__fzgx_offset_6[0x1c];
static f32 lbl_1_bss_26B1E__fzgx_offset_22;
static f32 lbl_1_bss_26B1E__fzgx_offset_26;
static s32 lbl_1_bss_26B1E__fzgx_offset_2A;
#pragma section code_type ".fzgxpool"
/* Reads every object once, in layout order, so MWCC emits them in that order. */
void fzgx_bss_primer(volatile u32 *p) {
 *p = s_bss_0[0]; *p = fzgx_pool_s_bss_4[0]; *p = lbl_1_bss_3C2A__fzgx_offset_0; *p = lbl_1_bss_3C2A__fzgx_offset_2[0]; *p = lbl_1_bss_3C30__fzgx_offset_0.flags; *p = fzgx_pool_s_bss_104[0];
 *p = lbl_1_bss_5138__fzgx_offset_EC; *p = fzgx_pool_s_bss_1628[0]; *p = (u32)lbl_1_bss_53F8__fzgx_offset_0[0]; *p = fzgx_pool_s_bss_1808[0];
 *p = lbl_1_bss_25C48__fzgx_offset_0[0]; *p = fzgx_pool_s_bss_22050[0]; *p = lbl_1_bss_26B1E__fzgx_offset_2[0]; *p = lbl_1_bss_26B1E__fzgx_offset_6[0];
 *p = lbl_1_bss_26B1E__fzgx_offset_22; *p = lbl_1_bss_26B1E__fzgx_offset_26; *p = lbl_1_bss_26B1E__fzgx_offset_2A;
}
#pragma section code_type ".text"
const u32 fzgx_pool_table_0[1] = {0xFFFFFF00};
#pragma section code_type ".fzgxpool"
/* Volatile stores retain the shared literal pool's retail order. */
void fzgx_pool_primer_4(volatile f32 *p, volatile f64 *d, u32 x) {
 *p=0.0f; *p=15.0f; *p=1.0f; *p=10.0f; *p=1.25f;
 *p=0.1f; *p=0.9f; *p=0.0006f; *p=0.4f; *p=0.75f; *p=70.0f;
 *p=0.5f; *p=36.0f; *p=16.0f; *p=45.0f; *p=0.0008f; *p=18.0f; *p=50.0f;
 *d=(f64)x;
}
#pragma section code_type ".text"

const u32 fzgx_pool_table_58[52] = {0};
#pragma section code_type ".fzgxpool"
/* Volatile stores retain the shared literal pool's retail order. */
void fzgx_pool_primer_128(volatile f32 *p, volatile f64 *d, s32 x) { *p=0.8f; *p=80.0f; *p=60.0f; *d=(f64)x; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_140[2]={0,0xFFFFFF00};
#pragma section code_type ".fzgxpool"
/* Volatile stores retain the shared literal pool's retail order. */
void fzgx_pool_primer_148(volatile f32 *p) { *p=470.0f; *p=0.0625f; *p=14.0f; *p=127.0f; *p=0.25f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_15C[3]={0x03E8FED4,0xFE70FE0C,0xFE0CFE0C};
#pragma section code_type ".fzgxpool"
/* Volatile stores retain the shared literal pool's retail order. */
void fzgx_pool_primer_168(volatile f32 *p) { *p=10000.0f; *p=15000.0f; *p=9999.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_174[2]={0xFFFFFF00,0x80808000};  /* fzgx-allow: A1 retail pool bytes */
#pragma section code_type ".fzgxpool"
/* Volatile stores retain the shared literal pool's retail order. */
void fzgx_pool_primer_17C(volatile f32 *p) { *p=320.0f; *p=240.0f; *p=280.0f; *p=200.0f; *p=40.0f; *p=30.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_194[5]={0x80808000,0xFFFFFF00,0x80808000,0xFFFFFF00,0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
const u32 fzgx_pool_table_1A8[2]={0,0};
const u32 fzgx_pool_table_1B0[1]={0xFFFFFF00};
#pragma section code_type ".fzgxpool"
/* Volatile stores retain the shared literal pool's retail order. */
void fzgx_pool_primer_1B4(volatile f32 *p) { *p=0.05f; *p=0.15f; *p=0.08f; *p=2.0f; *p=4.0f; *p=255.0f; *p=1.1f; *p=38.0f; *p=20.0f; *p=180.0f; *p=3.0f; *p=0.0002f; *p=100.0f; *p=75.0f; *p=0.0004f; *p=150.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_1F4[7]={0xFFF200FF,0xFFF200FF,0x80808080,0xFFFFFF96,0xFFF200FF,0xFFF200FF,0xFFFFFF96};  /* fzgx-allow: A1 retail pool bytes */
#pragma section code_type ".fzgxpool"
/* Volatile stores retain the shared literal pool's retail order. */
void fzgx_pool_primer_210(volatile f32 *p, volatile f64 *d) { *p=0.01f; *p=1000.0f; *d=20.0; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_220[4]={0x80000000,0x40000000,0x20000000,0x10000000};
#pragma section code_type ".fzgxpool"
/* Volatile stores retain the shared literal pool's retail order. */
void fzgx_pool_primer_230(volatile f32 *p) { *p=620.0f; *p=140.0f; *p=3000.0f; *p=0.00033333333f; *p=0.3f; *p=0.7f; *p=0.2f; *p=0.6f; }
#pragma section code_type ".text"
typedef struct Input { u32 head; f32 f4,f8,fc,f10,f14; u8 pad18[0x1c]; f32 f34; u8 pad38[0xc]; f32 f44; u8 pad48[0x70]; } Input;
extern s32 fn_1_F2F34(void);
extern u8 fn_1_3BB0(u32);
extern u8 lbl_1_data_2B60[4],lbl_1_bss_D70[8];
extern u8 fn_1_84794(s16);
extern u32 *fn_1_82EDC(s16,s16,u32*);
extern void fn_1_22B10(Input*,f32);
extern void fn_1_22E8C(Racer*,Input*);
static inline f32 track_total(Track *t) {
 f32 distance=(f32)t->unk_11C*t->unk_FC;
 return t->unk_100+distance;
}
static inline void apply_handicap(Input *in, Racer *r, f32 diff) {
 if(diff>3000.0f) diff=3000.0f;
 diff*=0.00033333333f;
 in->fc += (f32)(1.1f*diff);
 in->f8 += (f32)(0.3f*diff);
 in->f10 += (f32)(0.3f*(f32)(in->f10*diff));
 in->f44 -= (f32)(0.7f*(f32)(in->f44*diff));
 in->f34 += (f32)(0.2f*(f32)(in->f34*diff));
 r->factor=1.0f-(f32)(0.2f*diff);
}
void fn_1_331EC(Racer *r) {
 Input in;
 s32 freeze=0;
 f32 diff;
 s16 slot,controller;
 s16 i;
 if (!(lbl_1_bss_3C30__fzgx_offset_0.flags & 0x10) && r->track->unk_118 < 1) r->flags &= ~0x40;
 if(lbl_1_bss_3C30__fzgx_offset_0.callback) lbl_1_bss_3C30__fzgx_offset_0.callback(&lbl_1_bss_3C30__fzgx_offset_0,r);
 if (lbl_1_bss_3C30__fzgx_offset_0.lock) r->flags &= ~0x10000000;
 if (lbl_1_bss_3C30__fzgx_offset_0.mode==2) {
  if (!(r->flags & 0x10000) && (r->distance>100.0f || r->distance>lbl_1_bss_26B1E__fzgx_offset_26)) r->flags58c |=0x40;
  lbl_1_bss_26B1E__fzgx_offset_22=r->distance;
 }
 if ((lbl_1_bss_3C30__fzgx_offset_0.flags&0x40000) && !lbl_1_bss_3C30__fzgx_offset_0.lock && !(r->flags&0x200)) {
  if(r->speed<1.0f) r->c=0.0f;
  r->a=0.0f; r->e=0.5f; r->b=0.0f; r->d=0.0f;
  r->flags &= 0xfff7dfff; r->flags &=0xfffdfff7; r->flags |=0x10000000;
 } else if ((lbl_1_bss_3C30__fzgx_offset_0.flags&0x80) && !(r->flags&0x200)) {
  if(r->speed<1.0f) r->c=0.0f;
  r->a=0.0f; r->e=1.0f; r->b=0.0f; r->d=0.0f;
  r->flags &=0xfff7dfff; r->flags &=0xfffdfff7;
 } else if(lbl_1_bss_3C2A__fzgx_offset_0<=40) {
  r->c=0.0f; r->a=0.0f; r->b=0.0f;
  if(lbl_1_bss_3C30__fzgx_offset_0.flags&0x100) {
   freeze=1; if(!(r->flags&0x20000000)) r->d=0.6f;
   r->e=0.0f; r->flags &=0xfff7dfbf; r->flags &=0xfffdfff7;
  }
 } else if(lbl_1_bss_3C30__fzgx_offset_0.flags&0x80000) {
  r->c=0.0f; r->a=0.0f; r->e=0.3f; r->b=0.0f; r->d=0.0f;
  r->flags &=0xfff7dfff; r->flags &=0xfffdfff7;
 }
 if(lbl_1_bss_3C30__fzgx_offset_0.mode==2 && !(r->flags&0x10000) && (r->flags58c&0x40)) lbl_1_bss_3C30__fzgx_offset_0.mode=6;
 if(r->controller!=-1 && lbl_1_bss_26B1E__fzgx_offset_2A && !r->state) {
  if(lbl_1_bss_3C30__fzgx_offset_0.flags&0x800000) {
   if(!fn_1_F2F34()) {
    r->state=fn_1_3BB0(r->controller);
    (&lbl_1_bss_7EFD8.unk_38)[r->id]=r->state;
    (&lbl_1_bss_7EFD8.unk_3C)[r->id]=lbl_1_data_2B60[r->id];
    lbl_1_bss_D70[r->id]=lbl_1_data_2B60[r->id];
   } else {
    r->state=(&lbl_1_bss_7EFD8.unk_38)[r->id];
    lbl_1_bss_D70[r->id]=(&lbl_1_bss_7EFD8.unk_3C)[r->id];
   }
  } else {
   lbl_1_bss_D70[r->id]=lbl_1_data_2B60[r->id];
   r->state=fn_1_3BB0(r->controller);
  }
 } else if(!(lbl_1_bss_3C30__fzgx_offset_0.flags&0x800) && lbl_1_bss_26B1E__fzgx_offset_2A && r->controller!=-1) {
  s8 state=fn_1_3BB0(r->controller);
  if(state && r->state!=state) {lbl_1_bss_5138__fzgx_offset_EC=1; r->state=state;}
 }
 controller=r->controller; slot=r->slot;
 if(controller==-1) {
  for(i=0;i<4;i++) {
   if(r->id==fn_1_84794(i)) {controller=i;break;}
  }
 }
 fn_1_82EDC(controller,slot,(u32*)&in);
 if(freeze && !(r->flags&0x4000000)) { r->x=in.f8; r->y=in.fc; }
 else {
  u8 *p=lbl_1_bss_53F8__fzgx_offset_0[r->id];
  if(p) { f32 v = p[0xb]; v *= 0.01f; fn_1_22B10(&in,v); }
  else { f32 v = lbl_1_bss_25C48__fzgx_offset_0[r->id]; v *= 0.01f; fn_1_22B10(&in,v); }
 }
 if(lbl_1_bss_3C30__fzgx_offset_0.flags&0x20000) {
  Track *rt;
  Track *t=lbl_1_bss_3C30__fzgx_offset_0.track;
  if(!(r->flags&0x4000200)) {
   f32 a,b;
   apply_handicap(&in,r,track_total(t)-track_total(r->track));
  }
 }
 if(!(r->flags&0x4000000) && !freeze) fn_1_22E8C(r,&in);
 if(lbl_1_bss_3C30__fzgx_offset_0.flags&0x8000) r->flags |=1;
 if(lbl_1_bss_26B1E__fzgx_offset_2[r->id] && lbl_1_bss_3C2A__fzgx_offset_0==42) r->flags |=1;
}
/* fzgx:end fn_1_331EC */

/* fzgx:begin fn_1_33890 */
typedef struct {
    u8 pad_0[0x5];
    u8 unk_5;
    u8 pad_6[0x4];
    u8 unk_A;
    u8 pad_B[0x1];
    u8 unk_C;
    u8 unk_D;
} Fn33890Arg;

int fn_1_33890(Fn33890Arg* arg0) {
    u8 count;
    u8 limit;
    u32 flags;

    if ((s32)lbl_1_bss_25BA0.unk_0 != 0) {
        return 0;
    }

    if (((flags = lbl_1_bss_3C30.unk_0) & 0x800) != 0) {
        return 0;
    }

    switch (arg0->unk_5) {
    case 4:
        if (arg0->unk_D == 0 || arg0->unk_A != 1) {
            /* Shared fallback is the irreducible default path. */
            goto fallback;
        }
        return 1;

    case 2:
        if (arg0->unk_C == 0) {
            /* Shared fallback is the irreducible default path. */
            goto fallback;
        }
        return 1;

    case 0:
    case 1:
    case 6:
        count = arg0->unk_C;
        if (count == 0) {
            /* Shared fallback is the irreducible default path. */
            goto fallback;
        }
        limit = arg0->unk_D;
        if (limit <= count) {
            if ((s32)lbl_1_bss_25B84 != 0) {
                lbl_1_bss_3C30.unk_0 |= 0x10000;
            }
            return 1;
        }
        if (lbl_1_bss_3C30.unk_5 == 0 && (limit - count) <= 1) {
            lbl_1_bss_25B98++;
            return 1;
        }
        break;

    default:
        break;
    }

fallback:
    if (lbl_1_bss_3C30.unk_8 != 0) {
        if (lbl_1_bss_3C30.unk_D == 0) {
            return -1;
        }
    } else if (lbl_1_bss_3C30.pad_A[0] == 0) {
        return -1;
    }

    if ((flags & 0x04000000) == 0 && lbl_1_bss_3C30.unk_1474 > 0x57030) {
        lbl_1_bss_3C30.unk_0 |= 0x80000;
        return -1;
    }
    return 0;
}
/* fzgx:end fn_1_33890 */

/* fzgx:begin fn_1_34924 noprologue */
#include "types.h"

typedef struct GameState30 {
    u32 flags;
    u8 pad_4[4];
    u8 unk_8;
    u8 pad_9[0x14B3];
} GameState30;

typedef struct GamePilot {
    u8 pad_0[0x475];
    s8 unk_475;
} GamePilot;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 fzgx_obj_lbl_1_bss_3C08[2];
u8 fzgx_obj_lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u8 fzgx_obj_lbl_1_bss_3C12;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b5;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b7;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b8;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b9;
u32 fzgx_obj_lbl_1_bss_3C1C;
u8 lbl_1_bss_3C1C__fzgx_offset_4[10];
u8 fzgx_obj_lbl_1_bss_3C2A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b5;
GameState30 fzgx_obj_lbl_1_bss_3C30;
u32 fzgx_obj_lbl_1_bss_50EC[5];
u32 fzgx_obj_lbl_1_bss_5100;
s8 fzgx_obj_lbl_1_bss_5104;
u32 lbl_1_bss_5104__fzgx_offset_4[12];
u32 fzgx_obj_lbl_1_bss_5138[65];
u32 fzgx_obj_lbl_1_bss_523C[8];
u32 fzgx_obj_lbl_1_bss_525C[102];
u16 fzgx_obj_lbl_1_bss_53F4;
u32 fzgx_obj_lbl_1_bss_53F8[34];
u32 fzgx_obj_lbl_1_bss_5480[33216];
u16 fzgx_obj_lbl_1_bss_25B80;
u32 fzgx_obj_lbl_1_bss_25B84;
u32 fzgx_obj_lbl_1_bss_25B88[4];
u16 fzgx_obj_lbl_1_bss_25B98;
u32 fzgx_obj_lbl_1_bss_25B9C;
u32 fzgx_obj_lbl_1_bss_25BA0[42];
u32 fzgx_obj_lbl_1_bss_25C48[23];
u32 fzgx_obj_lbl_1_bss_25CA4[11];
u32 fzgx_obj_lbl_1_bss_25CD0[105];
u32 fzgx_obj_lbl_1_bss_25E74[2];
s32 lbl_1_bss_25E74__fzgx_offset_8;
s32 lbl_1_bss_25E74__fzgx_offset_C;
s32 lbl_1_bss_25E74__fzgx_offset_10;
u32 lbl_1_bss_25E74__fzgx_offset_14[2];
u32 fzgx_obj_lbl_1_bss_25E90[2];
u8 fzgx_obj_lbl_1_bss_25E98[4];
u32 fzgx_obj_lbl_1_bss_25E9C[240];
u32 fzgx_obj_lbl_1_bss_2625C[8];
u32 fzgx_obj_lbl_1_bss_2627C[30];
u8 fzgx_obj_lbl_1_bss_262F4;
u32 fzgx_obj_lbl_1_bss_262F8[2];
u16 fzgx_obj_lbl_1_bss_26300;
u32 fzgx_obj_lbl_1_bss_26304[4];
u32 fzgx_obj_lbl_1_bss_26314[508];
u32 fzgx_obj_lbl_1_bss_26B04[5];
u8 fzgx_obj_lbl_1_bss_26B18;
u8 fzgx_obj_lbl_1_bss_26B19;
u8 fzgx_obj_lbl_1_bss_26B1A;
u8 fzgx_pool_fzgx_pad_26B1B;
u8 fzgx_pool_fzgx_pad_26B1C;
u8 fzgx_obj_lbl_1_bss_26B1D;
u8 fzgx_obj_lbl_1_bss_26B1E;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
u32 lbl_1_bss_26B1E__fzgx_offset_2A;
u32 fzgx_obj_lbl_1_bss_26B4C;
u32 fzgx_obj_lbl_1_bss_26B50;
u32 fzgx_obj_lbl_1_bss_26B54[2];
u8 fzgx_obj_lbl_1_bss_26B5C[30];
u8 fzgx_obj_lbl_1_bss_26B7A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
u32 fzgx_obj_lbl_1_bss_26B80[42];
u32 fzgx_obj_lbl_1_bss_26C28;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_3C00;
    s = fzgx_obj_lbl_1_bss_3C04;
    s = fzgx_obj_lbl_1_bss_3C08[0];
    s = fzgx_obj_lbl_1_bss_3C10;
    s = fzgx_obj_lbl_1_bss_3C11;
    s = fzgx_obj_lbl_1_bss_3C12;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b5;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b7;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b8;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b9;
    s = fzgx_obj_lbl_1_bss_3C1C;
    s = lbl_1_bss_3C1C__fzgx_offset_4[0];
    s = fzgx_obj_lbl_1_bss_3C2A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b5;
    s = *(u32 *)&fzgx_obj_lbl_1_bss_3C30;
    s = fzgx_obj_lbl_1_bss_50EC[0];
    s = fzgx_obj_lbl_1_bss_5100;
    s = fzgx_obj_lbl_1_bss_5104;
    s = lbl_1_bss_5104__fzgx_offset_4[0];
    s = fzgx_obj_lbl_1_bss_5138[0];
    s = fzgx_obj_lbl_1_bss_523C[0];
    s = fzgx_obj_lbl_1_bss_525C[0];
    s = fzgx_obj_lbl_1_bss_53F4;
    s = fzgx_obj_lbl_1_bss_53F8[0];
    s = fzgx_obj_lbl_1_bss_5480[0];
    s = fzgx_obj_lbl_1_bss_25B80;
    s = fzgx_obj_lbl_1_bss_25B84;
    s = fzgx_obj_lbl_1_bss_25B88[0];
    s = fzgx_obj_lbl_1_bss_25B98;
    s = fzgx_obj_lbl_1_bss_25B9C;
    s = fzgx_obj_lbl_1_bss_25BA0[0];
    s = fzgx_obj_lbl_1_bss_25C48[0];
    s = fzgx_obj_lbl_1_bss_25CA4[0];
    s = fzgx_obj_lbl_1_bss_25CD0[0];
    s = fzgx_obj_lbl_1_bss_25E74[0];
    s = lbl_1_bss_25E74__fzgx_offset_8;
    s = lbl_1_bss_25E74__fzgx_offset_C;
    s = lbl_1_bss_25E74__fzgx_offset_10;
    s = lbl_1_bss_25E74__fzgx_offset_14[0];
    s = fzgx_obj_lbl_1_bss_25E90[0];
    s = fzgx_obj_lbl_1_bss_25E98[0];
    s = fzgx_obj_lbl_1_bss_25E9C[0];
    s = fzgx_obj_lbl_1_bss_2625C[0];
    s = fzgx_obj_lbl_1_bss_2627C[0];
    s = fzgx_obj_lbl_1_bss_262F4;
    s = fzgx_obj_lbl_1_bss_262F8[0];
    s = fzgx_obj_lbl_1_bss_26300;
    s = fzgx_obj_lbl_1_bss_26304[0];
    s = fzgx_obj_lbl_1_bss_26314[0];
    s = fzgx_obj_lbl_1_bss_26B04[0];
    s = fzgx_obj_lbl_1_bss_26B18;
    s = fzgx_obj_lbl_1_bss_26B19;
    s = fzgx_obj_lbl_1_bss_26B1A;
    s = fzgx_pool_fzgx_pad_26B1B;
    s = fzgx_pool_fzgx_pad_26B1C;
    s = fzgx_obj_lbl_1_bss_26B1D;
    s = fzgx_obj_lbl_1_bss_26B1E;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
    s = lbl_1_bss_26B1E__fzgx_offset_2A;
    s = fzgx_obj_lbl_1_bss_26B4C;
    s = fzgx_obj_lbl_1_bss_26B50;
    s = fzgx_obj_lbl_1_bss_26B54[0];
    s = fzgx_obj_lbl_1_bss_26B5C[0];
    s = fzgx_obj_lbl_1_bss_26B7A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
    s = fzgx_obj_lbl_1_bss_26B80[0];
    s = fzgx_obj_lbl_1_bss_26C28;
}
#pragma section code_type ".text"

extern s32 fn_1_EB200(void);
extern void fn_1_4310(u32);
extern void fn_1_F2EB8(void);
extern void fn_1_A4F18(u8);
extern void fn_1_4060(void);
extern void *fn_1_435C(u32);
extern void fn_1_426C(u32);
extern void fn_1_105724(void);
extern GamePilot *fn_1_86254(s32);
extern void fn_1_15E540(s32, u32);

void fn_1_34924(u16 *timer) {
    s8 i;

    if (fn_1_EB200() != 0) {
        return;
    }
    if (!(fzgx_obj_lbl_1_bss_3C30.flags & 0x800) && fzgx_obj_lbl_1_bss_5104 != -1) {
        return;
    }
    if (--*timer != 0) {
        if (*timer > 60 && *timer < 240) {
            fn_1_4310(0);
            fzgx_obj_lbl_1_bss_3C30.flags |= 0x4000;
            if (fzgx_obj_lbl_1_bss_3C30.flags & 0x800000) {
                if (*timer == 239) {
                    fn_1_F2EB8();
                    lbl_1_bss_26B1E__fzgx_offset_2A = 1;
                }
            } else {
                lbl_1_bss_26B1E__fzgx_offset_2A = 1;
            }
        }
        fn_1_A4F18(*timer / 60);
    } else {
        fn_1_4060();
        lbl_1_bss_25E74__fzgx_offset_8 = -1;
        fn_1_435C(fzgx_obj_lbl_1_bss_25B88[0]);
        if (lbl_1_bss_25E74__fzgx_offset_C != -1) {
            fn_1_426C(lbl_1_bss_25E74__fzgx_offset_C);
            fn_1_105724();
        }
        lbl_1_bss_25E74__fzgx_offset_C = -1;
        fn_1_435C(fzgx_obj_lbl_1_bss_25CA4[0]);
        if (lbl_1_bss_25E74__fzgx_offset_10 != -1) {
            fn_1_426C(lbl_1_bss_25E74__fzgx_offset_10);
        }
        lbl_1_bss_25E74__fzgx_offset_10 = -1;
        if (fzgx_obj_lbl_1_bss_3C30.flags & 0x10) {
            for (i = 0; i < fzgx_obj_lbl_1_bss_3C30.unk_8; i++) {
                s8 v = fn_1_86254(i)->unk_475;
                if (v != -1) {
                    fn_1_15E540(v, fzgx_obj_lbl_1_bss_25B88[0]);
                }
            }
        }
    }
}
/* fzgx:end fn_1_34924 */

/* fzgx:begin fn_1_34AC0 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"
#include "types.h"
#include "rel/main_rel/game.h"

typedef struct Sig_ADXT_Pause_AdxSjdHandle Sig_ADXT_Pause_AdxSjdHandle;

typedef struct Sig_ADXT_Pause_ADXStream Sig_ADXT_Pause_ADXStream;

typedef struct Sig_ADXT_Pause_AXRNAHandle Sig_ADXT_Pause_AXRNAHandle;

typedef struct Sig_ADXT_Pause_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Pause_SJCK;

typedef void (*Sig_ADXT_Pause_SJErrorCallback)(void *object, int error);

typedef struct Sig_ADXT_Pause_SJInterface Sig_ADXT_Pause_SJInterface;

typedef struct Sig_ADXT_Pause_SJ Sig_ADXT_Pause_SJ;

struct Sig_ADXT_Pause_SJ {
    const Sig_ADXT_Pause_SJInterface *interface;
};

struct Sig_ADXT_Pause_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Pause_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Pause_SJ *sj);
    void (*reset)(Sig_ADXT_Pause_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, int max_size, Sig_ADXT_Pause_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, Sig_ADXT_Pause_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, Sig_ADXT_Pause_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Pause_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Pause_SJ *sj, Sig_ADXT_Pause_SJErrorCallback callback, void *object);
};

typedef struct Sig_ADXT_Pause_ADX_AMP Sig_ADXT_Pause_ADX_AMP;

typedef struct Sig_ADXT_Pause_LSCObject Sig_ADXT_Pause_LSCObject;

typedef struct Sig_ADXT_Pause_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Pause_AdxSjdHandle *decoder;
    Sig_ADXT_Pause_ADXStream *stream;
    Sig_ADXT_Pause_AXRNAHandle *rna;
    Sig_ADXT_Pause_SJ *stream_sj;
    Sig_ADXT_Pause_SJ *input_sj;
    Sig_ADXT_Pause_SJ *output_sj[2];
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
    Sig_ADXT_Pause_ADX_AMP *amplifier;
    Sig_ADXT_Pause_SJ *amplifier_input[2];
    Sig_ADXT_Pause_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Pause_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Pause_ADXTHandle;

typedef struct Sig_ADXT_Stop_AdxSjdHandle Sig_ADXT_Stop_AdxSjdHandle;

typedef struct Sig_ADXT_Stop_ADXStream Sig_ADXT_Stop_ADXStream;

typedef struct Sig_ADXT_Stop_AXRNAHandle Sig_ADXT_Stop_AXRNAHandle;

typedef struct Sig_ADXT_Stop_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK;

typedef void (*Sig_ADXT_Stop_SJErrorCallback)(void *object, int error);

typedef struct Sig_ADXT_Stop_SJInterface Sig_ADXT_Stop_SJInterface;

typedef struct Sig_ADXT_Stop_SJ Sig_ADXT_Stop_SJ;

struct Sig_ADXT_Stop_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ *sj);
    void (*reset)(Sig_ADXT_Stop_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};

struct Sig_ADXT_Stop_SJ {
    const Sig_ADXT_Stop_SJInterface *interface;
};

typedef struct Sig_ADXT_Stop_ADX_AMP Sig_ADXT_Stop_ADX_AMP;

typedef struct Sig_ADXT_Stop_LSCObject Sig_ADXT_Stop_LSCObject;

typedef struct Sig_ADXT_Stop_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Stop_AdxSjdHandle *decoder;
    Sig_ADXT_Stop_ADXStream *stream;
    Sig_ADXT_Stop_AXRNAHandle *rna;
    Sig_ADXT_Stop_SJ *stream_sj;
    Sig_ADXT_Stop_SJ *input_sj;
    Sig_ADXT_Stop_SJ *output_sj[2];
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
    Sig_ADXT_Stop_ADX_AMP *amplifier;
    Sig_ADXT_Stop_SJ *amplifier_input[2];
    Sig_ADXT_Stop_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Stop_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Stop_ADXTHandle;

typedef struct {
    u8 unk[0xb];
    u8 value;
} Entry;

typedef struct {
    u8 pad_0[2];
    s16 unk_2;
    u8 pad_4[8];
    u32 unk_C;
    u8 pad_10[0x10];
} Obj_1_bss_25E9C;

typedef struct {
    u8 pad[0x2f8];
    u32 value_2f8;
    u32 value_2fc;
    u32 value_300;
    u32 value_304;
    u32 value_308;
    u32 value_30c;
    u32 value_310;
    u32 value_314;
    u32 value_318;
    u32 value_31c;
} Fn40710Config;
extern void fn_1_15E330(s32 index, u32 value, void *arg);
extern void fn_1_15E5E4(s32 index, void *arg);
extern void fn_1_15E688(s32 index, u32 value, u8 state, void *arg);
extern void fn_1_15E3E0(s32 index, u32 value);
extern void fn_1_15E434(u32 value);
extern void fn_1_15E540(s32 index, void *arg);
extern void fn_1_CB404(u8 value);
extern void fn_1_D07C4(u32 arg0, u32 arg1);
extern u32 lbl_1_bss_25B84;
extern u32 OSGetTick(void);
extern void fn_1_A0978(void);
extern void fn_1_35174(void);
extern s32 fn_1_3EFA8(void);
extern u16 lbl_1_bss_26B7A[3];
extern u16 lbl_1_bss_26300;
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern u32 fn_1_101C0(void);
extern u32 fn_1_A11EC(void);
extern u32 fn_1_435C(u32 value);
extern void ADXT_Pause(Sig_ADXT_Pause_ADXTHandle *, s32);
extern void fn_1_4310(u32 arg0);
extern void fn_1_48004(s32 index, s32 image);
extern void fn_1_8616C(void);
extern void fn_1_A1588(u32 arg0, u32 arg1);
extern void fn_1_D0790(void);
extern void fn_1_817C0(void);
extern u32 lbl_1_bss_381FC;
extern void fn_1_EB080(int mode);
extern s64 OSGetTime(void);
extern void fn_1_4A00(u32 arg0, u32 arg1, u32 arg2);
extern void fn_1_5370(u32 arg0, u32 arg1);
extern void fn_1_15E27C(void);
extern void fn_1_4811C(int arg);
extern void fn_1_A8F78(void);
extern u8 lbl_1_bss_262F4;
extern u32 lbl_1_bss_25E74[7];
extern u8 lbl_1_bss_3C10;
extern void fn_1_36330(void);
extern void fn_1_36B10(void);
extern void fn_1_3C98(void);
extern void fn_1_37AA8(void);
extern void fn_1_37E98(void);
extern f32 lbl_1_bss_26304[4];
extern u8 lbl_1_bss_26B04[20];
extern u8 lbl_1_bss_26314[2032];
extern s16 fn_1_12EF24(s16 row, s16 column);
extern u8 lbl_1_bss_523C[32];
extern Entry *lbl_1_bss_53F8[34];
extern void OSPanic(const void *, u32, const char *, ...);
extern Obj_1_bss_25E9C lbl_1_bss_25E9C[30];
extern void fn_1_12AB38(void *arg0);
extern void fn_1_465D0(char *value, u32 flag);
extern void* fn_1_7F518(s16 car_type, void* car, s32 initialize);
extern int sprintf(char *s, const char *format, ...);
extern void fn_1_451E4(void);
extern void fn_1_D3214(void);
extern void VIWaitForRetrace(void);
extern u32 fn_1_467F4(void);
extern u32 fn_1_13018(void);
extern u32 fn_1_46C60(void);
extern u32 lbl_1_bss_26C2C[2];
extern u32 lbl_1_bss_262F8[2];
extern u16 lbl_1_bss_26C68[35526];
extern u32 lbl_1_bss_3C08[2];
extern u32 fn_800075AC(u32, u32, u32);
extern u32 ghost_test_record_flag0(s32 arg);
extern u32 fn_1_F9D44(u32 arg);
extern u8 fn_1_F8C50(s32 arg0);
extern void fn_1_2DB50(void);
extern void fn_1_3F8C(void *, void *, Obj_1_bss_5138 *, int);
extern void fn_1_2D888(void);
extern void fn_1_2D524(void);
extern u32 fn_1_FA070(void);
extern int fn_1_FA180(int, u8);
extern u32 fn_1_F9FEC(void);
extern void fn_1_A2DC4(u32 arg0);
extern Fn40710Config lbl_1_rodata_BD8;
extern u8 lbl_1_bss_26B54[8];
extern u32 fn_1_40EE4(void);
extern u32 lbl_801A63D0;
extern u32 lbl_1_bss_26C34[9];
extern u8 lbl_1_bss_38218[568];
extern u32 fn_1_4060(void);
extern void ARQPostRequest(u8 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, u32 arg7);
extern u32 lbl_801A63C0;
extern void fn_1_40BE4(void);
extern u32 GXGetTexBufferSize(u32, u32, u32, u32, u32);
extern u32 lbl_1_bss_26B4C;
extern u8 lbl_1_bss_25E90[8];
extern s32 fn_1_48B0(u32 arg0, u32 arg1);
extern void fn_1_40F54(void *arg0);
extern u32 lbl_801A6CE0;
extern u32 lbl_1_bss_38454;
extern u32 fn_80070DE0(u32 arg0);
extern void fn_1_D3884();
extern void fn_1_D358C();
extern void fn_800711A8(Obj_1_bss_38458_Target *target);
extern void fn_80071718(u32 value);
extern void fn_1_41134(void *unused, char *value);
extern void fn_1_411D4(u32, char *);
extern int DVDConvertPathToEntrynum(char *buffer);
extern void fn_1_412A0(u32 index);
extern size_t strlen(const char *str);
extern int fn_80083BCC(const char *s1, const char *s2);
extern u8 lbl_1_A9011300;
extern u8 lbl_1_A9011100;
extern u8 lbl_1_A9011000;


extern s16 fn_1_8D7C8(void);
extern s16 fn_1_12C7B8(s16);
extern u32 fn_1_8D5F0(s16);
extern int fn_1_8D72C(s16);
extern u32 lbl_801A63C0;
extern u8 lbl_1_bss_2627C[120];

static inline s32 fn_1_34AC0_rand(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

void fn_1_34AC0(s8 *arr, s8 start, s8 total, s32 mode) {
    u64 mask = 0;
    s32 flag = 0;
    s16 r;
    s16 k;
    s16 j;
    s16 m;
    s16 i;
    s16 a;
    s16 b;
    s32 t;

    if (total > fn_1_8D7C8()) {
        flag = 1;
    }
    if (start == 0) {
        start = 1;
    }
    for (i = 0; i < start; i++) {
        mask |= 1ULL << fn_1_12C7B8(arr[i]);
    }

    if ((mode == 0 && lbl_1_bss_3C30.unk_5 == 1 && lbl_1_bss_3C30.unk_A6 == 5) ||
        (mode == 1 && lbl_1_bss_8B3A0.unk_0 == 1 && lbl_1_bss_8B3A0.unk_8C == 5)) {
        k = start;
        for (j = 0; j < 41; j++) {
            if ((fn_1_8D5F0(j) & 0x10000000) && k < total) {
                if (flag ? 1 : (mask & (1ULL << j)) == 0) {
                    ((u32 *)lbl_1_bss_2627C)[k] = 0;
                    arr[k] = j;
                    mask |= 1ULL << j;
                    k++;
                }
            }
        }
        for (m = 0; m < 30; m++) {
            a = fn_1_34AC0_rand() % k;
            b = fn_1_34AC0_rand() % k;
            if (a >= start && b >= start && a != b) {
                t = arr[a];
                arr[a] = arr[b];
                arr[b] = t;
            }
        }
        start = k;
    }

    for (k = start; k < total; k++) {
        do {
            r = fn_1_34AC0_rand() % 41;
        } while ((flag ? 0 : (mask & (1ULL << r))) != 0 || fn_1_8D72C(r) == 0);
        ((u32 *)lbl_1_bss_2627C)[k] = 0;
        arr[k] = r;
        mask |= 1ULL << r;
    }
}
/* fzgx:end fn_1_34AC0 */

/* fzgx:begin fn_1_34E08 noprologue */
#include "types.h"

struct fn_1_34E08_lbl_1_bss_8B3A0 {
    u8 pad_0[0xE];
    s16 unk_E;
};

extern int sprintf(char *, const char *, ...);
extern s32 fn_1_465D0(void *, s32);
extern struct fn_1_34E08_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern u8 * fn_1_36AD0(void);
extern u8 lbl_1_bss_26B5C[];
extern u8 lbl_1_data_5730[];
extern void * fn_1_7F518(s16, void *, s32);
extern void fn_1_12AB38(u32);
extern void fn_1_8001C(void);

void fn_1_34E08(void) {
    char loc_28[32];
    u8 *p_lbl_1_data_5730;
    s32 v2;
    u16 v0;
    char loc_8[32];
    u8 *p_lbl_1_bss_26B5C;
    void * lab_t0;

    p_lbl_1_data_5730 = (u8 *)&lbl_1_data_5730;
{
    s16 v1;
    v1 = (lbl_1_bss_8B3A0.unk_E);
    if (v1 > 40) {
        u8 *t0 = fn_1_36AD0();
        v1 = 50;
        if ((((0x40000000) & (*(u32 *)t0))) == 0) {
            v1 = *(u8 *)(t0 + 0x81A0);
        }
    }
    p_lbl_1_bss_26B5C = &lbl_1_bss_26B5C[-1];
    *++p_lbl_1_bss_26B5C = v1;
}
    fn_1_34AC0((u32)p_lbl_1_bss_26B5C, 1, 0x1e, 1);
    fn_1_8001C();
    fn_1_12AB38((u32)(p_lbl_1_data_5730 + 0xce4));
    fn_1_465D0((void *)(p_lbl_1_data_5730 + 0xcf0), 1);
    p_lbl_1_bss_26B5C = &lbl_1_bss_26B5C[0];
    v2 = 0;
    while ((s16)v2 < 30) {
        if ((s16)v2 == 0) {
            sprintf(loc_28, (const char *)(p_lbl_1_data_5730 + 0xd00),
                    fn_1_7F518(*(s8 *)((u8 *)((u8 *)(p_lbl_1_bss_26B5C) + v2 * 0x1)), loc_8, 0));
        } else {
            sprintf(loc_28, (const char *)(p_lbl_1_data_5730 + 0xd0c),
                    fn_1_7F518(*(s8 *)((u8 *)((u8 *)(p_lbl_1_bss_26B5C) + v2 * 0x1)), loc_8, 0));
        }
        lab_t0 = loc_28;
        fn_1_465D0(lab_t0, 1);
        v2++;
    }
    fn_1_12AB38((u32)(p_lbl_1_data_5730 + 0xd18));
}
/* fzgx:end fn_1_34E08 */

/* fzgx:begin fn_1_34F38 noprologue */
#include "rel/main_rel/game.h"

extern f32 lbl_1_rodata_BD8;
extern u8 lbl_1_bss_6F1E4[85];
extern Obj_1_bss_3C30 lbl_1_bss_3C30;
extern u32 fn_8004CD70(int arg0, void* arg1, const char* arg2);
extern void fn_1_A2E24(int arg0, u32 arg1, int arg2);
extern void fn_80067344(int arg0, int arg1, u32 arg2, int arg3);
extern Obj_1_bss_3C30* fn_1_86254(void);
extern void fn_1_A2DF4(int arg0, u32 arg1, int arg2);
extern void fn_1_35124(void);
extern void fn_1_4030(void (*func)(void));
extern const char lbl_1_rodata_4A248[];

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[8];
    u8 pad_10[0x20];
} InitObj;

typedef struct {
    u8 pad_0[8];
    f32 unk_8;
} Obj_1_86254;

#pragma opt_propagation off
#pragma opt_lifetimes off
#pragma opt_common_subs off
void fn_1_34F38(InitObj* obj) {
    u16* table;
    struct { u8* value; } state;
    u8* rodata;
    struct { s8 value; } i;
    int lab_t0;
    int lab_t0_;
    int lab_t2;
    int lab_t0__;
    int lab_t0___;

    rodata = (u8*)&lbl_1_rodata_BD8;
    if (obj != 0) {
        if (obj->unk_0 == 0) {
            obj->unk_0 = fn_8004CD70(2, &obj->pad_10[0],
                (const char *)(0x50000 - 0x5db8));
        }
        if (obj->unk_4 == 0) {
            obj->unk_4 = fn_8004CD70(2, (u8*)obj + 0x4a258,
                (const char *)(0x50000 - 0x5db8));
        }
    }

    fn_1_A2E24(0x10, 0xa0100000, 0x7f);
    fn_1_A2E24(0x10, 0xa0110000, 0);
    fn_80067344(1, 0xf, 0xb0270000, 0x7f);

    state.value = (u8*)&lbl_1_bss_6F1E4;
    table = (u16*)(rodata + 0x254);
    {
    s8 fzgx_loop_i_1335;
for (fzgx_loop_i_1335 = 0; fzgx_loop_i_1335 < 4; fzgx_loop_i_1335++) {
        s32 id = fzgx_loop_i_1335;
        i.value = id;
        if (lbl_1_bss_3C30.unk_8 > i.value) {
            Obj_1_86254* value = (Obj_1_86254*)fn_1_86254();
            if (value->unk_8 <= *(f32*)(rodata + 0x25c)) {
                *(u16*)(((8) + (state.value))) = 4;
            } else if (value->unk_8 <= *(f32*)(rodata + 0x260)) {
                *(u16*)(state.value + 8) = 0;
            } else {
                *(u16*)(state.value + 8) = 5;
            }
        } else {
            *(u16*)(state.value + 8) = *table;
        }
        lab_t0 = (s8)fzgx_loop_i_1335;
        lab_t0_ = lab_t0;
        lab_t0__ = lab_t0_;
        fn_1_A2DF4(lab_t0__, 0xa5000000, *(u16*)(state.value + 8));
        state.value += 0x14;
        table++;
    }
    i.value = fzgx_loop_i_1335;
}

    lab_t0 = 4;
    lab_t0_ = lab_t0;
    lab_t0__ = lab_t0_;
    lab_t0___ = lab_t0__;
    fn_1_A2DF4(lab_t0___, 0xa5000000, 0xa);
    lab_t0 = 5;
    lab_t0_ = lab_t0;
    lab_t2 = 9;
    lab_t0__ = lab_t0_;
    fn_1_A2DF4(lab_t0__, 0xa5000000, lab_t2);
    lab_t0 = 7;
    lab_t0_ = lab_t0;
    lab_t0__ = lab_t0_;
    fn_1_A2DF4(lab_t0__, 0xa5000000, 6);
    lab_t0 = 6;
    lab_t0_ = lab_t0;
    lab_t0__ = lab_t0_;
    fn_1_A2DF4(lab_t0__, 0xa5000000, 7);

    for (i.value = 0; i.value < 0x10; i.value++) {
        lab_t0 = i.value;
        lab_t0_ = lab_t0;
        lab_t0 = i.value;
        lab_t0__ = lab_t0_;
        fn_1_A2DF4(lab_t0__, 0xa6000000, 0);
        lab_t0_ = lab_t0;
        lab_t0__ = lab_t0_;
        fn_1_A2DF4(lab_t0__, 0xa5100000, 0);
    }

    fn_1_4030(fn_1_35124);
}
#pragma opt_common_subs reset

#pragma opt_lifetimes reset

#pragma opt_propagation reset
/* fzgx:end fn_1_34F38 */

/* fzgx:begin fn_1_35124 */
void fn_1_35124(void) {
    OSGetTick();
    fn_1_A0978();
    OSGetTick();
}
/* fzgx:end fn_1_35124 */

/* fzgx:begin fn_1_3514C */
void fn_1_3514C(void* arg0, int arg1) {
    if (arg1 == 1) {
        fn_1_35174();
    }
}
/* fzgx:end fn_1_3514C */

/* fzgx:begin fn_1_35174 */
// fn_1_35174: empty in retail (single blr).
void fn_1_35174(void) {
}
/* fzgx:end fn_1_35174 */

/* fzgx:begin fn_1_35178 */
// Decrement the counter while the associated state is active.
void fn_1_35178(u32* arg0) {
    if (fn_1_3EFA8() == 0) {
        switch (lbl_1_bss_3C2A) {
        case 0x29:
            if ((lbl_1_bss_3C30.unk_0 & 0x00000800) == 0) {
                if (lbl_1_bss_3C30.unk_5 == 2) {
                    u32 value = -(*arg0);

                    if (lbl_1_bss_3C30.unk_14A8 != value) {
                        lbl_1_bss_3C30.unk_14A8 = value;
                    }
                    if (*(s16*)&lbl_1_bss_26B7A[0] == -1 ||
                        *(s16*)&lbl_1_bss_26300 == -1) {
                        lbl_1_bss_3C30.unk_5 = 6;
                    }
                }
                *arg0 -= 1;
            }
            break;
        default:
            break;
        }
    }
}
/* fzgx:end fn_1_35178 */

/* fzgx:begin fn_1_3522C noprologue */
#include "types.h"
#include "types.h"
#include "types.h"

/* begin rel/main_rel/game.h (deltawave784/windows-and-types@cf9407c75) */
#ifndef REL_MAIN_REL_GAME_H
#define REL_MAIN_REL_GAME_H

/* begin rel/main_rel/globals.h (deltawave784/windows-and-types@cf9407c75) */
#ifndef REL_MAIN_REL_GLOBALS_H
#define REL_MAIN_REL_GLOBALS_H


// Generated by `fzgx headers --module main_rel`: layouts recovered from every access in the
// module's disassembly (matched or not). Field names are offsets until the librarian names them;
// offsets and widths are facts, names are not. Regenerate rather than hand-edit padding.

// lbl_1_bss_960: .bss size 0x2, referenced by 110 functions, shape {'object': 231}
extern s16 lbl_1_bss_960;

#endif  // REL_MAIN_REL_GLOBALS_H

// lbl_1_bss_962: .bss size 0x2, 2 refs from game.c
extern s16 lbl_1_bss_962;

#endif  // REL_MAIN_REL_GAME_H

/* end rel/main_rel/game.h */

extern void fn_1_81834(s8, s8, s8);
extern void fn_1_34AC0(s8 *, s8, s8, s32);
extern void fn_1_3181C(void);
extern void fn_1_584D4(void);
extern void *fn_1_435C(u32);
extern s32 fn_1_3F8C(void *, void *, void *, s32);
extern void fn_1_2C768(u32 *);
extern void fn_1_58694(void);
extern void fn_1_58C6C(void);
extern void fn_1_58994(void);
extern void fn_1_58D38(void);
extern void fn_1_128F10(void);
extern void fn_1_128F54(void);
extern void fn_1_12907C(void);
extern void *fn_1_7BA08(u32, u32, u32);
extern u32 fn_1_45D0(u32, void *, void *, s32);
extern void fn_1_7BA48(void);
extern void fn_1_7BAF8(void);
extern void fn_1_545B8(void);
extern void fn_1_7EAE8(void);
extern void camera_set_state_flag(u8);
extern void fn_1_5124(u32, u32);
extern s8 fn_1_5370(s8, s16);
extern void fn_1_9A578(void);
extern void fn_1_981C4(void);
extern void fn_1_98230(void);
extern void fn_1_9835C(void);
extern u32 fn_1_12AF50(u32);
extern u32 fn_1_82724(u32, u32, void *, u32, u32);
extern u32 fn_1_12AF64(void);
extern u32 fn_1_32A40(u32);
extern void fn_1_835E0(void *, u32, void *);
extern u32 fn_1_331EC(u32);
extern void fn_1_8176C(void *);
extern void fn_1_14A00C(void);
extern void fn_1_14A028(void);
extern void fn_1_15C36C(void);
extern u32 fn_1_8DBB0(void);
extern void fn_1_8DD54(void);
extern void fn_1_2F294(void);
extern u32 fn_1_4068C(void *);
extern void fn_1_408E8(void);
extern void fn_1_2D038(void);
extern void fn_80008BA8(void *, void *, u32);
extern u32 fn_80008E84(u32);
extern void fn_80008BEC(void *, int, u32);
extern u32 lbl_801A63C0;
/* read for its side effect only: retail reloads it after each of these calls */
extern volatile u32 lbl_801A6410;
extern const f32 lbl_1_rodata_BDC[];

/* The game-state objects of this TU's .bss, starting at lbl_1_bss_3C00.
 * Retail addresses them off one section base register, so they are
 * defined here in retail order. */
typedef struct {
    u32 flags;
    u8 pad_4;
    u8 mode;
    u8 pad_6[2];
    u8 humans;
    u8 total;
    u8 total2;
    u8 unk_B;
    u8 unk_C;
    u8 humans2;
    u8 order[0x14A8 - 0xE];
    u8 unk_14A8[0x14D0 - 0x14A8];
} GameObj30;

typedef struct {
    u8 pad_0[3];
    u8 flags;
    u8 pad_4[0x30 - 4];
} GameObj1508;

typedef struct {
    u16 unk_0;
    u8 unk_2;
    u8 unk_3;
    u8 pad_4[0xC];
    u16 unk_10;
    u16 unk_12;
    u8 pad_14[8];
    f32 unk_1C;
    u8 unk_20;
    u8 pad_21[0xE0 - 0x21];
    u8 unk_E0;
    u8 unk_E1;
    u8 unk_E2;
    u8 unk_E3;
    u8 unk_E4;
    u8 unk_E5;
    u8 pad_E6[5];
    u8 unk_EB;
    u8 pad_EC[0x104 - 0xEC];
} GameObj1538;

typedef struct {
    u8 b[5];
} GameEntry5;
extern u8 fn_1_382C4__fzgx_offset_0[];
extern u8 fn_1_384E8__fzgx_offset_0[];
extern u8 fn_1_385A4__fzgx_offset_0[];
extern u8 fn_1_3867C__fzgx_offset_0[];
extern u8 fn_1_38BBC__fzgx_offset_0[];
extern u8 fn_1_38CF4__fzgx_offset_0[];
extern u8 fn_1_3908C__fzgx_offset_0[];
extern u8 fn_1_391F0__fzgx_offset_0[];
extern u8 fn_1_39420__fzgx_offset_0[];
extern u8 fn_1_395CC__fzgx_offset_0[];
extern u8 fn_1_39C60__fzgx_offset_0[];
extern u8 fn_1_3A044__fzgx_offset_0[];
extern u8 fn_1_3A2C4__fzgx_offset_0[];
extern u8 fn_1_3A330__fzgx_offset_0[];
extern u8 fn_1_3AEC4__fzgx_offset_0[];
extern u8 fn_1_3B11C__fzgx_offset_0[];
extern u8 fn_1_3B7D4__fzgx_offset_0[];
extern u8 fn_1_3C880__fzgx_offset_0[];
extern u8 fn_1_3CDB0__fzgx_offset_0[];
extern u8 fn_1_3CE94__fzgx_offset_0[];
extern u8 fn_1_3DB9C__fzgx_offset_0[];
extern u8 fn_1_3DDAC__fzgx_offset_0[];
extern u8 fn_1_3DE80__fzgx_offset_0[];
extern u8 fn_1_3E5D0__fzgx_offset_0[];
extern u8 fn_1_3E628__fzgx_offset_0[];
extern u8 fn_1_3E62C__fzgx_offset_0[];
extern u8 fn_1_3E66C__fzgx_offset_0[];
extern u8 fn_1_3E670__fzgx_offset_0[];
extern u8 fn_1_3E6D8__fzgx_offset_0[];
extern u8 fn_1_3EA70__fzgx_offset_0[];
extern u8 lbl_1_data_5730__fzgx_offset_0[];
extern u8 lbl_1_data_573C__fzgx_offset_0[];
extern u8 lbl_1_data_5744__fzgx_offset_0[];
extern u8 lbl_1_data_5750__fzgx_offset_0[];
extern u8 lbl_1_data_5758__fzgx_offset_0[];
extern u8 lbl_1_data_5764__fzgx_offset_0[];
extern u8 lbl_1_data_576C__fzgx_offset_0[];
extern u8 lbl_1_data_5774__fzgx_offset_0[];
extern u8 lbl_1_data_5798__fzgx_offset_0[];
extern u8 lbl_1_data_579C__fzgx_offset_0[];
extern u8 lbl_1_data_57A8__fzgx_offset_0[];
extern u8 lbl_1_data_57B4__fzgx_offset_0[];
extern u8 lbl_1_data_57C0__fzgx_offset_0[];
extern u8 lbl_1_data_57CC__fzgx_offset_0[];
extern u8 lbl_1_data_57D4__fzgx_offset_0[];
extern u8 lbl_1_data_57DC__fzgx_offset_0[];
extern u8 lbl_1_data_57E4__fzgx_offset_0[];
extern u8 lbl_1_data_57EC__fzgx_offset_0[];
extern u8 lbl_1_data_57F8__fzgx_offset_0[];
extern u8 lbl_1_data_5808__fzgx_offset_0[];
extern u8 lbl_1_data_5818__fzgx_offset_0[];
extern u8 lbl_1_data_5820__fzgx_offset_0[];
extern u8 lbl_1_data_5828__fzgx_offset_0[];
extern u8 lbl_1_data_5834__fzgx_offset_0[];
extern u8 lbl_1_data_5840__fzgx_offset_0[];
extern u8 lbl_1_data_5850__fzgx_offset_0[];
extern u8 lbl_1_data_5858__fzgx_offset_0[];
extern u8 lbl_1_data_5864__fzgx_offset_0[];
extern u8 lbl_1_data_5870__fzgx_offset_0[];
extern u8 lbl_1_data_5880__fzgx_offset_0[];
extern u8 lbl_1_data_5888__fzgx_offset_0[];
extern u8 lbl_1_data_5894__fzgx_offset_0[];
extern u8 lbl_1_data_58A0__fzgx_offset_0[];
extern u8 lbl_1_data_58B0__fzgx_offset_0[];
extern u8 lbl_1_data_58B8__fzgx_offset_0[];
extern u8 lbl_1_data_58C4__fzgx_offset_0[];
extern u8 lbl_1_data_58CC__fzgx_offset_0[];
extern u8 lbl_1_data_58D8__fzgx_offset_0[];
extern u8 lbl_1_data_58E8__fzgx_offset_0[];
extern u8 lbl_1_data_58F4__fzgx_offset_0[];
extern u8 lbl_1_data_5900__fzgx_offset_0[];
extern u8 lbl_1_data_5908__fzgx_offset_0[];
extern u8 lbl_1_data_591C__fzgx_offset_0[];
extern u8 lbl_1_data_592C__fzgx_offset_0[];
extern u8 lbl_1_data_593C__fzgx_offset_0[];
extern u8 lbl_1_data_5948__fzgx_offset_0[];
extern u8 lbl_1_data_5954__fzgx_offset_0[];
extern u8 lbl_1_data_5964__fzgx_offset_0[];
extern u8 lbl_1_data_596C__fzgx_offset_0[];
extern u8 lbl_1_data_5978__fzgx_offset_0[];
extern u8 lbl_1_data_5980__fzgx_offset_0[];
extern u8 lbl_1_data_5988__fzgx_offset_0[];
extern u8 lbl_1_data_5990__fzgx_offset_0[];
extern u8 lbl_1_data_5A4C__fzgx_offset_0[];
extern u8 lbl_1_data_5A5C__fzgx_offset_0[];
extern u8 lbl_1_data_5A68__fzgx_offset_0[];
extern u8 lbl_1_data_5A74__fzgx_offset_0[];
extern u8 lbl_1_data_5A80__fzgx_offset_0[];
extern u8 lbl_1_data_5A88__fzgx_offset_0[];
extern u8 lbl_1_data_5A94__fzgx_offset_0[];
extern u8 lbl_1_data_5AA0__fzgx_offset_0[];
extern u8 lbl_1_data_5AAC__fzgx_offset_0[];
extern u8 lbl_1_data_5AB4__fzgx_offset_0[];
extern u8 lbl_1_data_5B94__fzgx_offset_0[];
extern u8 lbl_1_data_5BBC__fzgx_offset_0[];
extern u8 lbl_1_data_5BDC__fzgx_offset_0[];
extern u8 lbl_1_data_5C10__fzgx_offset_0[];
extern u8 lbl_1_data_5C6C__fzgx_offset_0[];
extern u8 lbl_1_data_5CC0__fzgx_offset_0[];
extern u8 lbl_1_data_5D1C__fzgx_offset_0[];
extern u8 lbl_1_data_5D78__fzgx_offset_0[];
extern u8 lbl_1_data_5DC8__fzgx_offset_0[];
extern u8 lbl_1_data_5E1C__fzgx_offset_0[];
extern u8 lbl_1_data_5E3C__fzgx_offset_0[];
extern u8 lbl_1_data_5E48__fzgx_offset_0[];
extern u8 lbl_1_data_5E58__fzgx_offset_0[];
extern u8 lbl_1_data_5E60__fzgx_offset_0[];
extern u8 lbl_1_data_5E70__fzgx_offset_0[];
extern u8 lbl_1_data_5E7C__fzgx_offset_0[];
extern u8 lbl_1_data_5E8C__fzgx_offset_0[];
extern u8 lbl_1_data_5E94__fzgx_offset_0[];
extern u8 lbl_1_data_5EA0__fzgx_offset_0[];
extern u8 lbl_1_data_5EAC__fzgx_offset_0[];
extern u8 lbl_1_data_5EB4__fzgx_offset_0[];
extern u8 lbl_1_data_5EC0__fzgx_offset_0[];
extern u8 lbl_1_data_5EC8__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_1_data_5730[275] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F564552, 0x54414B45, 0x0, 0x4A554D50, 0x0, 0x454E454D, 0x59484954, 0x0,
    0x57414C4C, 0x48495400, 0x53494445, 0x42595349, 0x44450000, 0x53544152, 0x54000000, 0x474F414C,
    0x0, 0x4C415000, (u32)lbl_1_data_5730__fzgx_offset_0, (u32)lbl_1_data_573C__fzgx_offset_0, (u32)lbl_1_data_5744__fzgx_offset_0, (u32)lbl_1_data_5750__fzgx_offset_0, (u32)lbl_1_data_5758__fzgx_offset_0, (u32)lbl_1_data_5764__fzgx_offset_0,
    (u32)lbl_1_data_576C__fzgx_offset_0, (u32)lbl_1_data_5774__fzgx_offset_0, 0x4E4F4E00, 0x4D415354, 0x45522052, 0x45435600, 0x4D415354, 0x45522053,
    0x454E4400, 0x534C4156, 0x45205345, 0x4E440000, 0x534C4156, 0x45205245, 0x43560000, 0x494E4954,
    0x0, 0x54455354, 0x0, 0x54455354, 0x454E4400, 0x53455455, 0x50000000, 0x53455455,
    0x505F444F, 0x4E450000, 0x53455455, 0x505F434F, 0x554E5445, 0x52000000, 0x53455455, 0x505F434E,
    0x545F444F, 0x4E450000, 0x554E4C49, 0x4E4B0000, 0x434F494E, 0x0, 0x454E5452, 0x595F5741,
    0x49540000, 0x4348414C, 0x4C454E47, 0x45520000, 0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000,
    0x454E5452, 0x59000000, 0x454E5452, 0x595F4F4B, 0x0, 0x53494E47, 0x4C454348, 0x45434B00,
    0x53494E47, 0x4C454348, 0x45434B5F, 0x4F4B0000, 0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F,
    0x4B000000, 0x434F5552, 0x53455F44, 0x41544100, 0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000,
    0x4D414348, 0x494E4500, 0x4D414348, 0x494E455F, 0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46,
    0x49475F4F, 0x4B000000, 0x434F554E, 0x54455241, 0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954,
    0x0, 0x4C494E4B, 0x57414954, 0x4F4B0000, 0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49,
    0x56455259, 0x53544152, 0x54000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x0, 0x4C494E4B,
    0x44454C49, 0x56455259, 0x4F4B0000, 0x4C494E4B, 0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649,
    0x45570000, 0x434F5552, 0x53455649, 0x45575F4F, 0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B,
    0x5354414E, 0x44425900, 0x4C494E4B, 0x4F4B0000, 0x4C494E4B, 0x0, 0x50415553, 0x45000000,
    0x4552524F, 0x52000000, (u32)lbl_1_data_5798__fzgx_offset_0, (u32)lbl_1_data_579C__fzgx_offset_0, (u32)lbl_1_data_57A8__fzgx_offset_0, (u32)lbl_1_data_57B4__fzgx_offset_0, (u32)lbl_1_data_57C0__fzgx_offset_0, (u32)lbl_1_data_57CC__fzgx_offset_0,
    (u32)lbl_1_data_57D4__fzgx_offset_0, (u32)lbl_1_data_57DC__fzgx_offset_0, (u32)lbl_1_data_57E4__fzgx_offset_0, (u32)lbl_1_data_57EC__fzgx_offset_0, (u32)lbl_1_data_57F8__fzgx_offset_0, (u32)lbl_1_data_5808__fzgx_offset_0, (u32)lbl_1_data_5818__fzgx_offset_0, (u32)lbl_1_data_5820__fzgx_offset_0,
    (u32)lbl_1_data_5828__fzgx_offset_0, (u32)lbl_1_data_5834__fzgx_offset_0, (u32)lbl_1_data_5840__fzgx_offset_0, (u32)lbl_1_data_5850__fzgx_offset_0, (u32)lbl_1_data_5858__fzgx_offset_0, (u32)lbl_1_data_5864__fzgx_offset_0, (u32)lbl_1_data_5870__fzgx_offset_0, (u32)lbl_1_data_5880__fzgx_offset_0,
    (u32)lbl_1_data_5888__fzgx_offset_0, (u32)lbl_1_data_5894__fzgx_offset_0, (u32)lbl_1_data_58A0__fzgx_offset_0, (u32)lbl_1_data_58B0__fzgx_offset_0, (u32)lbl_1_data_58B8__fzgx_offset_0, (u32)lbl_1_data_58C4__fzgx_offset_0, (u32)lbl_1_data_58CC__fzgx_offset_0, (u32)lbl_1_data_58D8__fzgx_offset_0,
    (u32)lbl_1_data_58E8__fzgx_offset_0, (u32)lbl_1_data_58F4__fzgx_offset_0, (u32)lbl_1_data_5900__fzgx_offset_0, (u32)lbl_1_data_5908__fzgx_offset_0, (u32)lbl_1_data_591C__fzgx_offset_0, (u32)lbl_1_data_592C__fzgx_offset_0, (u32)lbl_1_data_593C__fzgx_offset_0, (u32)lbl_1_data_5948__fzgx_offset_0,
    (u32)lbl_1_data_5954__fzgx_offset_0, (u32)lbl_1_data_5964__fzgx_offset_0, (u32)lbl_1_data_596C__fzgx_offset_0, (u32)lbl_1_data_5978__fzgx_offset_0, (u32)lbl_1_data_5980__fzgx_offset_0, (u32)lbl_1_data_5988__fzgx_offset_0, (u32)lbl_1_data_5990__fzgx_offset_0, 0x636F7572,
    0x73655F69, 0x6E74726F, 0x0, 0x63757374, 0x6F6D697A, 0x65000000, 0x636F7572, 0x73655F76,
    0x69657700, 0x72616365, 0x5F737461, 0x72740000, 0x72616365, 0x0, 0x72616365, 0x5F726573,
    0x756C7400, 0x6661696C, 0x5F726573, 0x756C7400, 0x70696C6F, 0x74706F69, 0x6E740000, 0x6F766572,
    0x0, 0x7469636B, 0x65740000, 0x0, 0x0, 0x0, 0x0, (u32)fn_1_382C4__fzgx_offset_0,
    (u32)fn_1_384E8__fzgx_offset_0, (u32)fn_1_385A4__fzgx_offset_0, (u32)lbl_1_data_5A4C__fzgx_offset_0, (u32)fn_1_3867C__fzgx_offset_0, (u32)fn_1_38BBC__fzgx_offset_0, (u32)fn_1_38CF4__fzgx_offset_0, (u32)lbl_1_data_5A5C__fzgx_offset_0, (u32)fn_1_3908C__fzgx_offset_0,
    (u32)fn_1_391F0__fzgx_offset_0, (u32)fn_1_39420__fzgx_offset_0, (u32)lbl_1_data_5A68__fzgx_offset_0, (u32)fn_1_395CC__fzgx_offset_0, (u32)fn_1_39C60__fzgx_offset_0, (u32)fn_1_3A044__fzgx_offset_0, (u32)lbl_1_data_5A74__fzgx_offset_0, (u32)fn_1_3A2C4__fzgx_offset_0,
    (u32)fn_1_3A330__fzgx_offset_0, (u32)fn_1_3AEC4__fzgx_offset_0, (u32)lbl_1_data_5A80__fzgx_offset_0, (u32)fn_1_3B11C__fzgx_offset_0, (u32)fn_1_3B7D4__fzgx_offset_0, (u32)fn_1_3C880__fzgx_offset_0, (u32)lbl_1_data_5A88__fzgx_offset_0, (u32)fn_1_3CDB0__fzgx_offset_0,
    (u32)fn_1_3CE94__fzgx_offset_0, (u32)fn_1_3DB9C__fzgx_offset_0, (u32)lbl_1_data_5A94__fzgx_offset_0, (u32)fn_1_3E628__fzgx_offset_0, (u32)fn_1_3E62C__fzgx_offset_0, (u32)fn_1_3E66C__fzgx_offset_0, (u32)lbl_1_data_5AA0__fzgx_offset_0, (u32)fn_1_3DDAC__fzgx_offset_0,
    (u32)fn_1_3DE80__fzgx_offset_0, (u32)fn_1_3E5D0__fzgx_offset_0, (u32)lbl_1_data_5AAC__fzgx_offset_0, (u32)fn_1_3E670__fzgx_offset_0, (u32)fn_1_3E6D8__fzgx_offset_0, (u32)fn_1_3EA70__fzgx_offset_0, (u32)lbl_1_data_5AB4__fzgx_offset_0, 0x43A00000,
    0x43200000, 0x43A00000, 0x438C0000
};
static u32 fzgx_pool_data_lbl_1_data_5B7C[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x1000000
};
static u32 fzgx_pool_data_lbl_1_data_5B80[475] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFFFFFF, 0x100FFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x54686973, 0x20726570, 0x6C617920,
    0x616E6420, 0x67686F73, 0x740A2063, 0x616E6E6F, 0x74206265, 0x20736176, 0x65642E00, 0x54686973,
    0x20726570, 0x6C617920, 0x63616E6E, 0x6F742062, 0x65207361, 0x7665642E, 0x0, 0x54686973,
    0x2067686F, 0x73742063, 0x616E6E6F, 0x74206265, 0x20736176, 0x65642E00, (u32)lbl_1_data_5B94__fzgx_offset_0, (u32)lbl_1_data_5BBC__fzgx_offset_0,
    (u32)lbl_1_data_5BDC__fzgx_offset_0, (u32)lbl_1_data_5B94__fzgx_offset_0, (u32)lbl_1_data_5BBC__fzgx_offset_0, (u32)lbl_1_data_5BDC__fzgx_offset_0, 0x4E657720, 0x70617274, 0x73206861, 0x7665206A,
    0x75737420, 0x61727269, 0x76656421, 0xA2F6263, 0x30306666, 0x66662F25, 0x732F6263, 0x66666666,
    0x66662F0A, 0x596F7520, 0x63616E20, 0x70757263, 0x68617365, 0x20746865, 0x6D20696E, 0x20746865,
    0x2073686F, 0x702E0000, (u32)lbl_1_data_5C10__fzgx_offset_0, 0x4D616368, 0x696E650A, 0x2F626330, 0x30666666, 0x662F2573,
    0x2F626366, 0x66666666, 0x662F0A68, 0x61732061, 0x72726976, 0x65642E0A, 0x596F7520, 0x63616E20,
    0x70757263, 0x68617365, 0x20697420, 0x61742074, 0x68652073, 0x686F702E, 0x0, (u32)lbl_1_data_5C6C__fzgx_offset_0,
    0x2F626330, 0x30666666, 0x662F2573, 0x2F626366, 0x66666666, 0x662F0A53, 0x74616666, 0x2047686F,
    0x73747320, 0x68617665, 0x20617272, 0x69766564, 0x2E0A596F, 0x75206361, 0x6E207075, 0x72636861,
    0x73652074, 0x68656D20, 0x61742074, 0x68652073, 0x686F702E, 0x0, (u32)lbl_1_data_5CC0__fzgx_offset_0, 0x2F626330,
    0x30666666, 0x662F2573, 0x2F626366, 0x66666666, 0x662F0A61, 0x72636164, 0x6520636F, 0x75727365,
    0x73206861, 0x76652061, 0x72726976, 0x65642E0A, 0x596F7520, 0x63616E20, 0x70757263, 0x68617365,
    0x20746865, 0x6D206174, 0x20746865, 0x2073686F, 0x702E0000, (u32)lbl_1_data_5D1C__fzgx_offset_0, 0x53746F72, 0x790A2F62,
    0x63303066, 0x6666662F, 0x25732F62, 0x63666666, 0x6666662F, 0xA686173, 0x20617272, 0x69766564,
    0x2E0A596F, 0x75206361, 0x6E207075, 0x72636861, 0x73652069, 0x74206174, 0x20746865, 0x2073686F,
    0x702E0000, (u32)lbl_1_data_5D78__fzgx_offset_0, 0x2F626330, 0x30666666, 0x662F2573, 0x2F626366, 0x66666666, 0x662F0A73,
    0x6F756E64, 0x73206861, 0x76652061, 0x72726976, 0x65642E0A, 0x596F7520, 0x63616E20, 0x70757263,
    0x68617365, 0x20746865, 0x6D206174, 0x20746865, 0x2073686F, 0x702E0000, (u32)lbl_1_data_5DC8__fzgx_offset_0, 0x596F7520,
    0x61637175, 0x69726564, 0x20256420, 0x5469636B, 0x6574732E, 0x0, (u32)lbl_1_data_5E1C__fzgx_offset_0, 0x436F6E74,
    0x696E7565, 0x0, 0x50726F63, 0x65656420, 0x746F204E, 0x65787400, 0x52657472, 0x79000000,
    0x4D697373, 0x696F6E20, 0x44697370, 0x6C617900, 0x53657474, 0x696E6773, 0x0, 0x53656C65,
    0x63742043, 0x6F757273, 0x65000000, 0x5265706C, 0x61790000, 0x53617665, 0x20526570, 0x6C617900,
    0x53617665, 0x2047686F, 0x73740000, 0x53746174, 0x75730000, 0x466F7263, 0x65205769, 0x6E000000,
    0x52657365, 0x74000000, 0x51756974, 0x0, (u32)lbl_1_data_5E3C__fzgx_offset_0, (u32)lbl_1_data_5E48__fzgx_offset_0, (u32)lbl_1_data_5E48__fzgx_offset_0, (u32)lbl_1_data_5E58__fzgx_offset_0,
    (u32)lbl_1_data_5E60__fzgx_offset_0, (u32)lbl_1_data_5E70__fzgx_offset_0, (u32)lbl_1_data_5E7C__fzgx_offset_0, (u32)lbl_1_data_5E8C__fzgx_offset_0, (u32)lbl_1_data_5E94__fzgx_offset_0, (u32)lbl_1_data_5EA0__fzgx_offset_0, (u32)lbl_1_data_5EAC__fzgx_offset_0, (u32)lbl_1_data_5EB4__fzgx_offset_0,
    (u32)lbl_1_data_5EC0__fzgx_offset_0, (u32)lbl_1_data_5EC8__fzgx_offset_0, 0x1000000, 0x436C6561, 0x72205363, 0x656E6172, 0x696F380A, 0x0,
    0x4E6F7420, 0x67657420, 0x5363656E, 0x6172696F, 0x39207965, 0x740A0000, 0x4E6F7420, 0x436C6561,
    0x72656420, 0x63757020, 0x25640A00, 0x67657420, 0x7363656E, 0x6172696F, 0x20390A00, 0x7265706C,
    0x61795F65, 0x7869745F, 0x67617000, 0x2F626337, 0x66666666, 0x662F5072, 0x6F6C6F67, 0x75652F62,
    0x63666666, 0x6666662F, 0x20202020, 0x20426C61, 0x636B2053, 0x6861646F, 0x77277320, 0x44697367,
    0x72616365, 0x0, 0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220312F, 0x62636666,
    0x66666666, 0x2F202020, 0x20204361, 0x70746169, 0x6E204661, 0x6C636F6E, 0x20547261, 0x696E7300,
    0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220322F, 0x62636666, 0x66666666, 0x2F202020,
    0x2020476F, 0x726F683A, 0x20546865, 0x2056656E, 0x67656675, 0x6C205361, 0x6D757261, 0x69000000,
    0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220332F, 0x62636666, 0x66666666, 0x2F202020,
    0x20204869, 0x67682053, 0x74616B65, 0x7320696E, 0x204D7574, 0x65204369, 0x74790000, 0x2F626337,
    0x66666666, 0x662F4368, 0x61707465, 0x7220342F, 0x62636666, 0x66666666, 0x2F202020, 0x20204368,
    0x616C6C65, 0x6E676520, 0x6F662074, 0x68652042, 0x6C6F6F64, 0x79204368, 0x61696E00, 0x2F626337,
    0x66666666, 0x662F4368, 0x61707465, 0x7220352F, 0x62636666, 0x66666666, 0x2F202020, 0x20205361,
    0x7665204A, 0x6F647921, 0x0, 0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220362F,
    0x62636666, 0x66666666, 0x2F202020, 0x2020426C, 0x61636B20, 0x53686164, 0x6F772773, 0x20547261,
    0x70000000, 0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220372F, 0x62636666, 0x66666666,
    0x2F202020, 0x20205468, 0x6520462D, 0x5A45524F, 0x20477261, 0x6E642050, 0x72697800, 0x2F626337,
    0x66666666, 0x662F4368, 0x61707465, 0x7220382F, 0x62636666, 0x66666666, 0x2F202020, 0x20205365,
    0x63726574, 0x73206F66, 0x20746865, 0x20436861, 0x6D70696F, 0x6E204265, 0x6C740000, 0x2F626337,
    0x66666666, 0x662F4368, 0x61707465, 0x7220392F, 0x62636666, 0x66666666, 0x2F202020, 0x20204669,
    0x6E616C65, 0x3A20456E, 0x74657220, 0x74686520, 0x43726561, 0x746F7273, 0x0, 0x4D757465,
    0x20436974, 0x79000000, 0x42696720, 0x426C7565, 0x0, 0x839F0000, 0x746F5F67, 0x616D656F,
    0x7665725F, 0x6576656E, 0x74000000, 0x51756974, 0x74696E67, 0x20526570, 0x6C61792E, 0x204F4B3F,
    0x0, 0x51756974, 0x74696E67, 0x20477261, 0x6E642050, 0x7269782E, 0x0, 0x51756974,
    0x74696E67, 0x2054696D, 0x65204174, 0x7461636B, 0x2E000000, 0x51756974, 0x74696E67, 0x20746869,
    0x73207363, 0x656E6172, 0x696F2E00, 0x51756974, 0x74696E67, 0x20746865, 0x20726163, 0x652E0000,
    0x53746172, 0x74696E67, 0x20726163, 0x65206F76, 0x65722E00, 0x456E7465, 0x72696E67, 0x20536574,
    0x74696E67, 0x73207363, 0x7265656E, 0x2E000000, 0x456E7465, 0x72696E67, 0x2053656C, 0x65637420,
    0x436F7572, 0x73652073, 0x63726565, 0x6E2E0000, 0x53797374, 0x656D2072, 0x65736574, 0x0,
    0x59455300, 0x4E4F0000, 0x462D5A45, 0x524F2047, 0x58000000, 0x5B204D45, 0x4E55205D, 0x0,
    0x49732074, 0x68697320, 0x4F4B3F00
};
static u32 fzgx_pool_data_lbl_1_data_62EC[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x67616D65, 0x2E630000
};
static u32 fzgx_pool_data_lbl_1_data_62F4[72] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x47414D45, 0x3A206D65, 0x6E75206D, 0x61736B20, 0x6973207A, 0x65726F2E, 0xA000000, 0x47616D65,
    0x43616C63, 0x4C696768, 0x74000000, 0x43617243, 0x616C634C, 0x69676874, 0x0, 0x53746167,
    0x6543616C, 0x63000000, 0x4261636B, 0x47726F75, 0x6E644361, 0x6C630000, 0x466F674D, 0x61696E00,
    0x53746167, 0x65446973, 0x70000000, 0x4261636B, 0x47726F75, 0x6E644469, 0x73700000, 0x79616A69,
    0x72757368, 0x695F6469, 0x73700000, 0x50687973, 0x4F626A44, 0x69737000, 0x50687973, 0x4F626A50,
    0x6F737444, 0x69737000, 0x50687973, 0x53686164, 0x6F775072, 0x6552656E, 0x64000000, 0x50687973,
    0x4F626A43, 0x616C6300, 0x456E656D, 0x79546F74, 0x616C436F, 0x6E74726F, 0x6C4D6169, 0x6E000000,
    0x73657474, 0x696E675F, 0x67617000, 0x6E657874, 0x5F737461, 0x67655F67, 0x61700000, 0x47616D65,
    0x52657374, 0x6172745F, 0x67617000, 0x6361725F, 0x73746174, 0x75735F63, 0x6865636B, 0x0
};
static u8 fzgx_pool_data_lbl_1_data_6414[55] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x76, 0x65, 0x68, 0x69, 0x63, 0x6C, 0x65, 0x2F, 0, 0, 0, 0,
    0x63, 0x61, 0x72, 0x63, 0x6D, 0x6E, 0x74, 0x65, 0x78, 0x2E, 0x74, 0x70,
    0x6C, 0, 0, 0, 0x25, 0x73, 0x5F, 0x70, 0x2E, 0x61, 0x72, 0x63,
    0x2E, 0x6C, 0x7A, 0, 0x25, 0x73, 0x5F, 0x65, 0x2E, 0x61, 0x72, 0x63,
    0x2E, 0x6C, 0x7A, 0, 0x2E, 0x2E, 0
};
static u8 fzgx_pool_data_lbl_1_data_5730_D1B = 1; /* fzgx-allow: A1 retail byte */
static u32 fzgx_pool_data_lbl_1_data_5730_D1C[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4275726E, 0x65720000
};
static u32 fzgx_pool_data_lbl_1_data_5730_D24[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4275726E, 0x65724469, 0x73700000
};
static u32 fzgx_pool_data_lbl_1_data_5730_D30[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x47616D65, 0x52657375, 0x6C744374, 0x726C0000
};
static u32 fzgx_pool_data_lbl_1_data_5730_D40[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x47616D65, 0x52657375, 0x6C744469, 0x73700000
};
static u32 fzgx_pool_data_lbl_1_data_5730_D50[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x53657441, 0x6C6C4361, 0x724C4F44, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_5730_D60[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x64756D6D, 0x795F636F, 0x756E745F, 0x75700000
};
static u32 fzgx_pool_data_lbl_1_data_5730_D70[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45666665, 0x63740000
};
static u32 fzgx_pool_data_lbl_1_data_5730_D78[5] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45666665, 0x63744469, 0x73704265, 0x666F7265, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_5730_D8C[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45666665, 0x63744469, 0x73700000
};
static u32 fzgx_pool_data_lbl_1_data_5730_D98[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x45666665, 0x63744469, 0x73704166, 0x74657200
};
static u32 fzgx_pool_data_lbl_1_data_5730_DA8[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x43686563, 0x6B000000
};
static u32 fzgx_pool_data_lbl_1_data_5730_DB0[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x43686563, 0x6B446973, 0x70000000
};
static u32 fzgx_pool_data_lbl_1_data_5730_DBC[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4C696768, 0x744D6169, 0x6E000000
};
static u32 fzgx_pool_data_lbl_1_data_5730_DC8[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x44726177, 0x4F726453, 0x79730000
};
static u32 fzgx_pool_data_lbl_1_data_5730_DD4[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x466F674F, 0x66660000
};
static u32 fzgx_pool_data_lbl_1_data_5730_DDC[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x67616D65, 0x5F6D656E, 0x755F6469, 0x73700000
};
static u32 fzgx_pool_data_lbl_1_data_5730_DEC[5] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x47616D65, 0x4D656E75, 0x57696467, 0x65744469, 0x73700000
};
static u32 fzgx_pool_data_lbl_1_data_5730_E00[46] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x64697370, 0x5F666169, 0x6C5F7265, 0x636F7264, 0x0, 0x46616365, 0x0, 0x46616365,
    0x44697370, 0x0, 0x52756D62, 0x6C654D61, 0x696E0000, 0x736F756E, 0x645F696E, 0x69740000,
    0x67616D65, 0x0, 0x74696D65, 0x5F636F75, 0x6E745F64, 0x65630000, 0x5265706C, 0x6179496E,
    0x666F4465, 0x636F6465, 0x0, 0x5265706C, 0x6179496E, 0x666F456E, 0x636F6465, 0x0,
    0x73746172, 0x745F636F, 0x756E7464, 0x6F776E00, 0x53746172, 0x74657200, 0x53746172, 0x74657244,
    0x69737000, 0x53746F72, 0x7947686F, 0x73745374, 0x61727444, 0x69737000
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_data_5730(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5B7C;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5B80;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_62EC;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_62F4;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_6414;
    s = fzgx_pool_data_lbl_1_data_5730_D1B;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_D1C;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_D24;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_D30;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_D40;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_D50;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_D60;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_D70;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_D78;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_D8C;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_D98;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_DA8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_DB0;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_DBC;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_DC8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_DD4;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_DDC;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_DEC;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_5730_E00;
}
#pragma section code_type ".text"

u8 fzgx_obj_lbl_1_bss_3C00[4];
u8 fzgx_pool_obj_3C04[0x20];
u32 fzgx_pool_obj_3C24[3];
GameObj30 fzgx_pool_obj_3C30;
u32 fzgx_pool_obj_5100[2];
GameObj1508 fzgx_pool_obj_5108;
GameObj1538 fzgx_pool_obj_5138;
u8 fzgx_pool_obj_523C[0x40];
/* objects of other functions, between 0x167C and 0x21F88 */
u8 fzgx_pool_obj_527C[0x4000];
u8 fzgx_pool_obj_927C[0x4000];
u8 fzgx_pool_obj_D27C[0x4000];
u8 fzgx_pool_obj_1127C[0x4000];
u8 fzgx_pool_obj_1527C[0x4000];
u8 fzgx_pool_obj_1927C[0x4000];
u8 fzgx_pool_obj_1D27C[0x4000];
u8 fzgx_pool_obj_2127C[0x4000];
u8 fzgx_pool_obj_2527C[0x90C];
u32 fzgx_pool_obj_25B88[(0x21FF0 - 0x21F88) / 4];
u32 fzgx_pool_obj_25BF0[(0x22048 - 0x21FF0) / 4];
u16 fzgx_pool_obj_25C48[(0x220A4 - 0x22048) / 2];
u32 fzgx_pool_obj_25CA4[(0x220C8 - 0x220A4) / 4];
u32 fzgx_pool_obj_25CC8[(0x2226C - 0x220C8) / 4];
u32 fzgx_pool_obj_25E6C;
u32 fzgx_pool_obj_25E70[2];
u32 fzgx_pool_obj_25E78[(0x22298 - 0x22278) / 4];
u8 fzgx_pool_obj_25E98[4];
u16 fzgx_pool_obj_25E9C[(0x2265C - 0x2229C) / 2];
u8 fzgx_pool_obj_2625C[0x226F8 - 0x2265C];
u32 fzgx_pool_obj_262F8[(0x22F50 - 0x226F8) / 4];
u32 fzgx_pool_obj_26B50[3];
u8 fzgx_pool_obj_26B5C[0x22F7A - 0x22F5C];
u16 fzgx_pool_obj_26B7A;
u8 fzgx_pool_obj_26B7C[4];
GameEntry5 fzgx_pool_obj_26B80[(0x23016 - 0x22F80) / 5];
u8 fzgx_pool_obj_26C16;
u8 fzgx_pool_obj_26C18[4];
u32 fzgx_pool_obj_26C1C;

#pragma section code_type ".fzgxpool"
/* layout primer: first use fixes the .bss order to retail's */
void fzgx_primer_bss(volatile u32 *sink) {
    *sink = (u32)fzgx_obj_lbl_1_bss_3C00;
    *sink = (u32)fzgx_pool_obj_3C04;
    *sink = (u32)fzgx_pool_obj_3C24;
    *sink = (u32)&fzgx_pool_obj_3C30;
    *sink = (u32)fzgx_pool_obj_5100;
    *sink = (u32)&fzgx_pool_obj_5108;
    *sink = (u32)&fzgx_pool_obj_5138;
    *sink = (u32)fzgx_pool_obj_523C;
    *sink = (u32)fzgx_pool_obj_527C;
    *sink = (u32)fzgx_pool_obj_927C;
    *sink = (u32)fzgx_pool_obj_D27C;
    *sink = (u32)fzgx_pool_obj_1127C;
    *sink = (u32)fzgx_pool_obj_1527C;
    *sink = (u32)fzgx_pool_obj_1927C;
    *sink = (u32)fzgx_pool_obj_1D27C;
    *sink = (u32)fzgx_pool_obj_2127C;
    *sink = (u32)fzgx_pool_obj_2527C;
    *sink = (u32)fzgx_pool_obj_25B88;
    *sink = (u32)fzgx_pool_obj_25BF0;
    *sink = (u32)fzgx_pool_obj_25C48;
    *sink = (u32)fzgx_pool_obj_25CA4;
    *sink = (u32)fzgx_pool_obj_25CC8;
    *sink = (u32)&fzgx_pool_obj_25E6C;
    *sink = (u32)fzgx_pool_obj_25E70;
    *sink = (u32)fzgx_pool_obj_25E78;
    *sink = (u32)fzgx_pool_obj_25E98;
    *sink = (u32)fzgx_pool_obj_25E9C;
    *sink = (u32)fzgx_pool_obj_2625C;
    *sink = (u32)fzgx_pool_obj_262F8;
    *sink = (u32)fzgx_pool_obj_26B50;
    *sink = (u32)fzgx_pool_obj_26B5C;
    *sink = (u32)&fzgx_pool_obj_26B7A;
    *sink = (u32)fzgx_pool_obj_26B7C;
    *sink = (u32)fzgx_pool_obj_26B80;
    *sink = (u32)&fzgx_pool_obj_26C16;
    *sink = (u32)fzgx_pool_obj_26C18;
    *sink = (u32)&fzgx_pool_obj_26C1C;
}
#pragma section code_type ".text"

void fn_1_3522C(void) {
    struct { s32 value; } n;
    u8 humans;
    struct { u8 value; } total;
    struct { s32 value; } i;
    s32 random;
    void *created;

    humans = fzgx_obj_lbl_1_bss_3C00[0];
    total.value = fzgx_pool_obj_3C30.total;
    fzgx_pool_obj_3C30.humans = humans;
    if (total.value > 30) {
        fzgx_pool_obj_3C30.total = 30;
    } else if (humans > total.value) {
        fzgx_pool_obj_3C30.total = humans;
    }
    i.value = 0;
    fzgx_pool_obj_3C30.total2 = fzgx_pool_obj_3C30.total;
    fzgx_pool_obj_3C30.unk_B = i.value;
    fzgx_pool_obj_3C30.unk_C = i.value;
    fzgx_pool_obj_3C30.mode = (*((char *)fzgx_pool_data_lbl_1_data_5B7C));
    fzgx_pool_obj_3C30.humans2 = fzgx_pool_obj_3C30.humans;
    for (; i.value < fzgx_pool_obj_3C30.total; i.value++) {
        fzgx_pool_obj_3C30.order[i.value] = i.value;
    }
    if (lbl_1_bss_960 == 12 || lbl_1_bss_962 == 160) {
        for (n.value = 0; n.value < fzgx_obj_lbl_1_bss_3C00[0]; n.value++) {
            fn_1_81834(n.value, fzgx_pool_obj_25E98[n.value], n.value);
        }
        for (i.value = fzgx_obj_lbl_1_bss_3C00[0]; i.value < fzgx_pool_obj_3C30.total; i.value++) {
            fzgx_pool_obj_2625C[i.value] = fzgx_pool_obj_26B80[i.value].b[1];
            fzgx_pool_obj_523C[i.value] = 0x10;
        }
    } else {
        if (fzgx_obj_lbl_1_bss_3C00[0]) {
            for (n.value = 0; n.value < fzgx_obj_lbl_1_bss_3C00[0]; n.value++) {
                fn_1_81834(n.value, fzgx_pool_obj_25E98[n.value], n.value);
            }
        } else {
            fn_1_81834(0, -1, 0);
            if (lbl_1_bss_960 == 2) {
                fzgx_pool_obj_2625C[0] = 6;
            } else if (lbl_1_bss_960 == 10) {
                if (fzgx_pool_data_lbl_1_data_5730_D1B) {
                    fzgx_pool_obj_2625C[0] = 6;
                    fzgx_pool_data_lbl_1_data_5730_D1B = 0;
                } else {
                    lbl_801A63C0 = lbl_801A63C0 * 0x676a4b6b + 0x33cb;
                    random = (lbl_801A63C0 >> 16) & 0x7fff;
                    fzgx_pool_obj_2625C[0] = random % (s32)fzgx_pool_obj_3C30.total;
                }
            } else {
                lbl_801A63C0 = lbl_801A63C0 * 0x676a4b6b + 0x33cb;
                random = (lbl_801A63C0 >> 16) & 0x7fff;
                fzgx_pool_obj_2625C[0] = random % (s32)fzgx_pool_obj_3C30.total;
            }
            fzgx_pool_obj_523C[0] = 0x10;
            fzgx_pool_obj_25C48[0] = 50;
        }
        if (lbl_1_bss_960 == 2 && (u8)(*((char *)fzgx_pool_data_lbl_1_data_5B7C)) == 1) {
            fn_80008BA8(fzgx_pool_obj_2625C, fzgx_pool_obj_26B5C, 30);
        } else {
            fn_1_34AC0((s8 *)fzgx_pool_obj_2625C, (s8)(fzgx_obj_lbl_1_bss_3C00[0] + fzgx_pool_obj_26B7C[0]),
                       (s8)fzgx_pool_obj_3C30.total, 0);
        }
    }
    fn_1_3181C();
    lbl_801A6410;
    if (fzgx_pool_obj_3C30.humans < 2 && lbl_1_bss_960 != 10 && lbl_1_bss_960 != 12) {
        fzgx_pool_obj_25CC8[0] = 1;
    } else {
        fzgx_pool_obj_25CC8[0] = 0;
    }
    fn_1_584D4();
    fn_1_435C(fzgx_pool_obj_25B88[0]);
    fzgx_pool_obj_26B7A = fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_D60), fn_1_2C768, fzgx_pool_obj_3C30.unk_14A8, 13);
    if (!(fzgx_pool_obj_3C30.flags & 0x1000000)) {
        fn_1_435C(fzgx_pool_obj_25B88[0]);
        fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_D70), fn_1_58694, 0, 11);
        fn_1_435C(fzgx_pool_obj_25CA4[0]);
        fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_D78), fn_1_58C6C, 0, 0);
        fn_1_435C(fzgx_pool_obj_25CA4[0]);
        fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_D8C), fn_1_58994, 0, 22);
        fn_1_435C(fzgx_pool_obj_25CA4[0]);
        fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_D98), fn_1_58D38, 0, 27);
    }
    if (lbl_1_bss_960 != 10 && lbl_1_bss_960 != 12) {
        fn_1_128F10();
        fn_1_435C(fzgx_pool_obj_25B88[0]);
        fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_DA8), fn_1_128F54, 0, 12);
        fn_1_435C(fzgx_pool_obj_25CA4[0]);
        fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_DB0), fn_1_12907C, 0, 22);
        lbl_801A6410;
    }
    created = fn_1_7BA08(32, 32, 64);
    fzgx_pool_obj_3C24[0] = fn_1_45D0(lbl_801A6410, created, ((char *)fzgx_pool_data_lbl_1_data_62EC), 0x17af);
    fn_1_7BA48();
    fn_1_435C(fzgx_pool_obj_25CA4[0]);
    fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_DBC), fn_1_7BAF8, (void *)fzgx_pool_obj_3C24[0], 3);
    lbl_801A6410;
    fn_1_435C(fzgx_pool_obj_25CA4[0]);
    fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_DC8), fn_1_545B8, 0, 25);
    fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_DD4), fn_1_7EAE8, 0, 29);
    camera_set_state_flag(1);
    fn_1_5124(fzgx_pool_obj_25B88[0], fzgx_pool_obj_25CA4[0]);
    fn_1_5370(3, 0);
    lbl_801A6410;
    fn_1_9A578();
    if (lbl_1_bss_960 == 10 || (lbl_1_bss_960 == 2 && (u8)(*((char *)fzgx_pool_data_lbl_1_data_5B7C)) == 1)) {
        struct { u32 value; } saved;
        saved.value = fn_80008E84(fzgx_pool_obj_262F8[0]);
        fn_1_981C4();
        lbl_801A6410;
        fn_1_435C(fzgx_pool_obj_25B88[0]);
        fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_D1C), fn_1_98230, 0, 10);
        fn_1_435C(fzgx_pool_obj_25CA4[0]);
        fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_D24), fn_1_9835C, 0, 21);
        fn_1_12AF50(saved.value);
        fn_1_82724(fzgx_pool_obj_25B88[0], fzgx_pool_obj_25CA4[0], fzgx_pool_obj_25E9C, fzgx_pool_obj_3C30.total, 1);
        fn_1_12AF64();
        fn_1_835E0(&fzgx_pool_obj_3C30, fzgx_pool_obj_25B88[0], fn_1_32A40);
        fn_1_8176C(fn_1_331EC);
        fn_80008E84(saved.value);
        fn_1_14A00C();
        fn_1_435C(fzgx_pool_obj_25B88[0]);
        fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_D30), fn_1_14A028, &fzgx_pool_obj_3C30, 25);
        fn_1_435C(fzgx_pool_obj_25CA4[0]);
        fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_D40), fn_1_15C36C, &fzgx_pool_obj_3C30, 28);
        fn_1_435C(fzgx_pool_obj_25CA4[0]);
        fn_1_8DBB0();
        fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_D50), fn_1_8DD54, 0, 1);
    }
    fzgx_pool_obj_26C1C = 1;
    fzgx_pool_obj_26B50[0] = 0;
    fzgx_pool_obj_25E6C = 0;
    fzgx_pool_obj_25E70[0] = 0;
    fzgx_pool_obj_25E78[0] = 0;
    fzgx_pool_obj_25BF0[0] = 0;
    fzgx_pool_obj_26C16 = 0;
    fn_1_435C(fzgx_pool_obj_5100[0]);
    fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_DDC), fn_1_2F294, 0, 30);
    fn_1_4068C(&fzgx_pool_obj_5108);
    fzgx_pool_obj_5108.flags &= ~1;
    fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_DEC), fn_1_408E8, &fzgx_pool_obj_5108, 30);
    fn_80008BEC(&fzgx_pool_obj_5138, 0, 0xec);
    fzgx_pool_obj_5138.unk_10 = 320;
    fzgx_pool_obj_5138.unk_12 = 180;
    fzgx_pool_obj_5138.unk_E1 = 0;
    fzgx_pool_obj_5138.unk_E0 = 0;
    fzgx_pool_obj_5138.unk_0 = 0;
    fzgx_pool_obj_5138.unk_2 = 0;
    fzgx_pool_obj_5138.unk_3 = 0;
    fzgx_pool_obj_5138.unk_1C = lbl_1_rodata_BDC[0];
    fzgx_pool_obj_5138.unk_20 = 0;
    fzgx_pool_obj_5138.unk_E2 = 0;
    fzgx_pool_obj_5138.unk_E3 = 255;
    fzgx_pool_obj_5138.unk_E4 = 0;
    fzgx_pool_obj_5138.unk_E5 = 255;
    fzgx_pool_obj_5138.unk_EB = 255;
    fn_1_3F8C(((char *)fzgx_pool_data_lbl_1_data_5730_E00), fn_1_2D038, 0, 1);
}
/* fzgx:end fn_1_3522C */

/* fzgx:begin fn_1_36A94 */
// Clears one indexed 0x81c0-byte entry in the shared buffer.
void fn_1_36A94(u32 arg0, u32 arg1) {
    u8 *entry = lbl_1_bss_5480;
    u32 stride = 0x81c0;
    u32 offset = (arg0 & 0xFF) * stride;

    fn_80008BA8( (u32)(void *)(entry + offset), (u32)((void *)arg1), stride);
}
/* fzgx:end fn_1_36A94 */

/* fzgx:begin fn_1_36AD0 */
u8* fn_1_36AD0(void) {
    return lbl_1_bss_5480;
}
/* fzgx:end fn_1_36AD0 */

/* fzgx:begin fn_1_36ADC */
void fn_1_36ADC(void) {
    fn_80008BEC(lbl_1_bss_5480, (int)(void *)(0), 0x20700);
}
/* fzgx:end fn_1_36ADC */

/* fzgx:begin fn_1_37E98 noprologue */
#include "types.h"
#include "rel/main_rel/game.h"

typedef u32 (*fn_1_37E98_Fn0)(void);
typedef u32 (*fn_1_37E98_Fn1)(u32);
typedef u32 (*fn_1_37E98_Fn2)(void);
struct GameModeEntry {
    u32 setup;
    u32 update;
    u32 cleanup;
    u32 other;
};
struct fn_1_37E98_lbl_1_data_5730 {
    u8 pad_0[0x38C];
    struct GameModeEntry modes[12];
    u8 pad_44C[12];
    u32 unk_458;
    u32 unk_45C;
    u8 pad_460[0x75C];
    char filename[8];
};
extern u8 fn_1_382C4__fzgx_offset_0[];
extern u8 fn_1_384E8__fzgx_offset_0[];
extern u8 fn_1_385A4__fzgx_offset_0[];
extern u8 fn_1_3867C__fzgx_offset_0[];
extern u8 fn_1_38BBC__fzgx_offset_0[];
extern u8 fn_1_38CF4__fzgx_offset_0[];
extern u8 fn_1_3908C__fzgx_offset_0[];
extern u8 fn_1_391F0__fzgx_offset_0[];
extern u8 fn_1_39420__fzgx_offset_0[];
extern u8 fn_1_395CC__fzgx_offset_0[];
extern u8 fn_1_39C60__fzgx_offset_0[];
extern u8 fn_1_3A044__fzgx_offset_0[];
extern u8 fn_1_3A2C4__fzgx_offset_0[];
extern u8 fn_1_3A330__fzgx_offset_0[];
extern u8 fn_1_3AEC4__fzgx_offset_0[];
extern u8 fn_1_3B11C__fzgx_offset_0[];
extern u8 fn_1_3B7D4__fzgx_offset_0[];
extern u8 fn_1_3C880__fzgx_offset_0[];
extern u8 fn_1_3CDB0__fzgx_offset_0[];
extern u8 fn_1_3CE94__fzgx_offset_0[];
extern u8 fn_1_3DB9C__fzgx_offset_0[];
extern u8 fn_1_3DDAC__fzgx_offset_0[];
extern u8 fn_1_3DE80__fzgx_offset_0[];
extern u8 fn_1_3E5D0__fzgx_offset_0[];
extern u8 fn_1_3E628__fzgx_offset_0[];
extern u8 fn_1_3E62C__fzgx_offset_0[];
extern u8 fn_1_3E66C__fzgx_offset_0[];
extern u8 fn_1_3E670__fzgx_offset_0[];
extern u8 fn_1_3E6D8__fzgx_offset_0[];
extern u8 fn_1_3EA70__fzgx_offset_0[];
extern u8 lbl_1_data_5730__fzgx_offset_0[];
extern u8 lbl_1_data_573C__fzgx_offset_0[];
extern u8 lbl_1_data_5744__fzgx_offset_0[];
extern u8 lbl_1_data_5750__fzgx_offset_0[];
extern u8 lbl_1_data_5758__fzgx_offset_0[];
extern u8 lbl_1_data_5764__fzgx_offset_0[];
extern u8 lbl_1_data_576C__fzgx_offset_0[];
extern u8 lbl_1_data_5774__fzgx_offset_0[];
extern u8 lbl_1_data_5798__fzgx_offset_0[];
extern u8 lbl_1_data_579C__fzgx_offset_0[];
extern u8 lbl_1_data_57A8__fzgx_offset_0[];
extern u8 lbl_1_data_57B4__fzgx_offset_0[];
extern u8 lbl_1_data_57C0__fzgx_offset_0[];
extern u8 lbl_1_data_57CC__fzgx_offset_0[];
extern u8 lbl_1_data_57D4__fzgx_offset_0[];
extern u8 lbl_1_data_57DC__fzgx_offset_0[];
extern u8 lbl_1_data_57E4__fzgx_offset_0[];
extern u8 lbl_1_data_57EC__fzgx_offset_0[];
extern u8 lbl_1_data_57F8__fzgx_offset_0[];
extern u8 lbl_1_data_5808__fzgx_offset_0[];
extern u8 lbl_1_data_5818__fzgx_offset_0[];
extern u8 lbl_1_data_5820__fzgx_offset_0[];
extern u8 lbl_1_data_5828__fzgx_offset_0[];
extern u8 lbl_1_data_5834__fzgx_offset_0[];
extern u8 lbl_1_data_5840__fzgx_offset_0[];
extern u8 lbl_1_data_5850__fzgx_offset_0[];
extern u8 lbl_1_data_5858__fzgx_offset_0[];
extern u8 lbl_1_data_5864__fzgx_offset_0[];
extern u8 lbl_1_data_5870__fzgx_offset_0[];
extern u8 lbl_1_data_5880__fzgx_offset_0[];
extern u8 lbl_1_data_5888__fzgx_offset_0[];
extern u8 lbl_1_data_5894__fzgx_offset_0[];
extern u8 lbl_1_data_58A0__fzgx_offset_0[];
extern u8 lbl_1_data_58B0__fzgx_offset_0[];
extern u8 lbl_1_data_58B8__fzgx_offset_0[];
extern u8 lbl_1_data_58C4__fzgx_offset_0[];
extern u8 lbl_1_data_58CC__fzgx_offset_0[];
extern u8 lbl_1_data_58D8__fzgx_offset_0[];
extern u8 lbl_1_data_58E8__fzgx_offset_0[];
extern u8 lbl_1_data_58F4__fzgx_offset_0[];
extern u8 lbl_1_data_5900__fzgx_offset_0[];
extern u8 lbl_1_data_5908__fzgx_offset_0[];
extern u8 lbl_1_data_591C__fzgx_offset_0[];
extern u8 lbl_1_data_592C__fzgx_offset_0[];
extern u8 lbl_1_data_593C__fzgx_offset_0[];
extern u8 lbl_1_data_5948__fzgx_offset_0[];
extern u8 lbl_1_data_5954__fzgx_offset_0[];
extern u8 lbl_1_data_5964__fzgx_offset_0[];
extern u8 lbl_1_data_596C__fzgx_offset_0[];
extern u8 lbl_1_data_5978__fzgx_offset_0[];
extern u8 lbl_1_data_5980__fzgx_offset_0[];
extern u8 lbl_1_data_5988__fzgx_offset_0[];
extern u8 lbl_1_data_5990__fzgx_offset_0[];
extern u8 lbl_1_data_5A4C__fzgx_offset_0[];
extern u8 lbl_1_data_5A5C__fzgx_offset_0[];
extern u8 lbl_1_data_5A68__fzgx_offset_0[];
extern u8 lbl_1_data_5A74__fzgx_offset_0[];
extern u8 lbl_1_data_5A80__fzgx_offset_0[];
extern u8 lbl_1_data_5A88__fzgx_offset_0[];
extern u8 lbl_1_data_5A94__fzgx_offset_0[];
extern u8 lbl_1_data_5AA0__fzgx_offset_0[];
extern u8 lbl_1_data_5AAC__fzgx_offset_0[];
extern u8 lbl_1_data_5AB4__fzgx_offset_0[];
extern u8 lbl_1_data_5B94__fzgx_offset_0[];
extern u8 lbl_1_data_5BBC__fzgx_offset_0[];
extern u8 lbl_1_data_5BDC__fzgx_offset_0[];
extern u8 lbl_1_data_5C10__fzgx_offset_0[];
extern u8 lbl_1_data_5C6C__fzgx_offset_0[];
extern u8 lbl_1_data_5CC0__fzgx_offset_0[];
extern u8 lbl_1_data_5D1C__fzgx_offset_0[];
extern u8 lbl_1_data_5D78__fzgx_offset_0[];
extern u8 lbl_1_data_5DC8__fzgx_offset_0[];
extern u8 lbl_1_data_5E1C__fzgx_offset_0[];
extern u8 lbl_1_data_5E3C__fzgx_offset_0[];
extern u8 lbl_1_data_5E48__fzgx_offset_0[];
extern u8 lbl_1_data_5E58__fzgx_offset_0[];
extern u8 lbl_1_data_5E60__fzgx_offset_0[];
extern u8 lbl_1_data_5E70__fzgx_offset_0[];
extern u8 lbl_1_data_5E7C__fzgx_offset_0[];
extern u8 lbl_1_data_5E8C__fzgx_offset_0[];
extern u8 lbl_1_data_5E94__fzgx_offset_0[];
extern u8 lbl_1_data_5EA0__fzgx_offset_0[];
extern u8 lbl_1_data_5EAC__fzgx_offset_0[];
extern u8 lbl_1_data_5EB4__fzgx_offset_0[];
extern u8 lbl_1_data_5EC0__fzgx_offset_0[];
extern u8 lbl_1_data_5EC8__fzgx_offset_0[];
static u32 fzgx_pool_native_lbl_1_data_5730_gap_0[227] = { 0x4F564552, 0x54414B45, 0x00000000,
    0x4A554D50, 0x00000000, 0x454E454D, 0x59484954, 0x00000000, 0x57414C4C, 0x48495400, 0x53494445,
    0x42595349, 0x44450000, 0x53544152, 0x54000000, 0x474F414C, 0x00000000, 0x4C415000,
    (u32)lbl_1_data_5730__fzgx_offset_0, (u32)lbl_1_data_573C__fzgx_offset_0,
    (u32)lbl_1_data_5744__fzgx_offset_0, (u32)lbl_1_data_5750__fzgx_offset_0,
    (u32)lbl_1_data_5758__fzgx_offset_0, (u32)lbl_1_data_5764__fzgx_offset_0,
    (u32)lbl_1_data_576C__fzgx_offset_0, (u32)lbl_1_data_5774__fzgx_offset_0, 0x4E4F4E00,
    0x4D415354, 0x45522052, 0x45435600, 0x4D415354, 0x45522053, 0x454E4400, 0x534C4156, 0x45205345,
    0x4E440000, 0x534C4156, 0x45205245, 0x43560000, 0x494E4954, 0x00000000, 0x54455354, 0x00000000,
    0x54455354, 0x454E4400, 0x53455455, 0x50000000, 0x53455455, 0x505F444F, 0x4E450000, 0x53455455,
    0x505F434F, 0x554E5445, 0x52000000, 0x53455455, 0x505F434E, 0x545F444F, 0x4E450000, 0x554E4C49,
    0x4E4B0000, 0x434F494E, 0x00000000, 0x454E5452, 0x595F5741, 0x49540000, 0x4348414C, 0x4C454E47,
    0x45520000, 0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000, 0x454E5452, 0x59000000, 0x454E5452,
    0x595F4F4B, 0x00000000, 0x53494E47, 0x4C454348, 0x45434B00, 0x53494E47, 0x4C454348, 0x45434B5F,
    0x4F4B0000, 0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F, 0x4B000000, 0x434F5552, 0x53455F44,
    0x41544100, 0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000, 0x4D414348, 0x494E4500, 0x4D414348,
    0x494E455F, 0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46, 0x49475F4F, 0x4B000000, 0x434F554E,
    0x54455241, 0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954, 0x00000000, 0x4C494E4B, 0x57414954,
    0x4F4B0000, 0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49, 0x56455259, 0x53544152, 0x54000000,
    0x4C494E4B, 0x44454C49, 0x56455259, 0x00000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x4F4B0000,
    0x4C494E4B, 0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649, 0x45570000, 0x434F5552, 0x53455649,
    0x45575F4F, 0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B, 0x5354414E, 0x44425900, 0x4C494E4B,
    0x4F4B0000, 0x4C494E4B, 0x00000000, 0x50415553, 0x45000000, 0x4552524F, 0x52000000,
    (u32)lbl_1_data_5798__fzgx_offset_0, (u32)lbl_1_data_579C__fzgx_offset_0,
    (u32)lbl_1_data_57A8__fzgx_offset_0, (u32)lbl_1_data_57B4__fzgx_offset_0,
    (u32)lbl_1_data_57C0__fzgx_offset_0, (u32)lbl_1_data_57CC__fzgx_offset_0,
    (u32)lbl_1_data_57D4__fzgx_offset_0, (u32)lbl_1_data_57DC__fzgx_offset_0,
    (u32)lbl_1_data_57E4__fzgx_offset_0, (u32)lbl_1_data_57EC__fzgx_offset_0,
    (u32)lbl_1_data_57F8__fzgx_offset_0, (u32)lbl_1_data_5808__fzgx_offset_0,
    (u32)lbl_1_data_5818__fzgx_offset_0, (u32)lbl_1_data_5820__fzgx_offset_0,
    (u32)lbl_1_data_5828__fzgx_offset_0, (u32)lbl_1_data_5834__fzgx_offset_0,
    (u32)lbl_1_data_5840__fzgx_offset_0, (u32)lbl_1_data_5850__fzgx_offset_0,
    (u32)lbl_1_data_5858__fzgx_offset_0, (u32)lbl_1_data_5864__fzgx_offset_0,
    (u32)lbl_1_data_5870__fzgx_offset_0, (u32)lbl_1_data_5880__fzgx_offset_0,
    (u32)lbl_1_data_5888__fzgx_offset_0, (u32)lbl_1_data_5894__fzgx_offset_0,
    (u32)lbl_1_data_58A0__fzgx_offset_0, (u32)lbl_1_data_58B0__fzgx_offset_0,
    (u32)lbl_1_data_58B8__fzgx_offset_0, (u32)lbl_1_data_58C4__fzgx_offset_0,
    (u32)lbl_1_data_58CC__fzgx_offset_0, (u32)lbl_1_data_58D8__fzgx_offset_0,
    (u32)lbl_1_data_58E8__fzgx_offset_0, (u32)lbl_1_data_58F4__fzgx_offset_0,
    (u32)lbl_1_data_5900__fzgx_offset_0, (u32)lbl_1_data_5908__fzgx_offset_0,
    (u32)lbl_1_data_591C__fzgx_offset_0, (u32)lbl_1_data_592C__fzgx_offset_0,
    (u32)lbl_1_data_593C__fzgx_offset_0, (u32)lbl_1_data_5948__fzgx_offset_0,
    (u32)lbl_1_data_5954__fzgx_offset_0, (u32)lbl_1_data_5964__fzgx_offset_0,
    (u32)lbl_1_data_596C__fzgx_offset_0, (u32)lbl_1_data_5978__fzgx_offset_0,
    (u32)lbl_1_data_5980__fzgx_offset_0, (u32)lbl_1_data_5988__fzgx_offset_0,
    (u32)lbl_1_data_5990__fzgx_offset_0, 0x636F7572, 0x73655F69, 0x6E74726F, 0x00000000, 0x63757374,
    0x6F6D697A, 0x65000000, 0x636F7572, 0x73655F76, 0x69657700, 0x72616365, 0x5F737461, 0x72740000,
    0x72616365, 0x00000000, 0x72616365, 0x5F726573, 0x756C7400, 0x6661696C, 0x5F726573, 0x756C7400,
    0x70696C6F, 0x74706F69, 0x6E740000, 0x6F766572, 0x00000000, 0x7469636B,
    0x65740000 }; /* fzgx-allow: A1 measured pool bytes and bindings */
static union {
    u32 words[48];
    struct GameModeEntry view[12];
} fzgx_pool_native_lbl_1_data_5730_modes = { { 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    (u32)fn_1_382C4__fzgx_offset_0, (u32)fn_1_384E8__fzgx_offset_0, (u32)fn_1_385A4__fzgx_offset_0,
    (u32)lbl_1_data_5A4C__fzgx_offset_0, (u32)fn_1_3867C__fzgx_offset_0,
    (u32)fn_1_38BBC__fzgx_offset_0, (u32)fn_1_38CF4__fzgx_offset_0,
    (u32)lbl_1_data_5A5C__fzgx_offset_0, (u32)fn_1_3908C__fzgx_offset_0,
    (u32)fn_1_391F0__fzgx_offset_0, (u32)fn_1_39420__fzgx_offset_0,
    (u32)lbl_1_data_5A68__fzgx_offset_0, (u32)fn_1_395CC__fzgx_offset_0,
    (u32)fn_1_39C60__fzgx_offset_0, (u32)fn_1_3A044__fzgx_offset_0,
    (u32)lbl_1_data_5A74__fzgx_offset_0, (u32)fn_1_3A2C4__fzgx_offset_0,
    (u32)fn_1_3A330__fzgx_offset_0, (u32)fn_1_3AEC4__fzgx_offset_0,
    (u32)lbl_1_data_5A80__fzgx_offset_0, (u32)fn_1_3B11C__fzgx_offset_0,
    (u32)fn_1_3B7D4__fzgx_offset_0, (u32)fn_1_3C880__fzgx_offset_0,
    (u32)lbl_1_data_5A88__fzgx_offset_0, (u32)fn_1_3CDB0__fzgx_offset_0,
    (u32)fn_1_3CE94__fzgx_offset_0, (u32)fn_1_3DB9C__fzgx_offset_0,
    (u32)lbl_1_data_5A94__fzgx_offset_0, (u32)fn_1_3E628__fzgx_offset_0,
    (u32)fn_1_3E62C__fzgx_offset_0, (u32)fn_1_3E66C__fzgx_offset_0,
    (u32)lbl_1_data_5AA0__fzgx_offset_0, (u32)fn_1_3DDAC__fzgx_offset_0,
    (u32)fn_1_3DE80__fzgx_offset_0, (u32)fn_1_3E5D0__fzgx_offset_0,
    (u32)lbl_1_data_5AAC__fzgx_offset_0, (u32)fn_1_3E670__fzgx_offset_0,
    (u32)fn_1_3E6D8__fzgx_offset_0, (u32)fn_1_3EA70__fzgx_offset_0,
    (u32)lbl_1_data_5AB4__fzgx_offset_0, 0x43A00000, 0x43200000, 0x43A00000,
    0x438C0000 } }; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_1_data_5730_gap_44C[3]
    = { 0x01000000, 0xFFFFFFFF, 0x0100FFFF }; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_1_data_5730_unk_458
    = 0xFFFFFFFF; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_1_data_5730_unk_45C
    = 0xFFFFFFFF; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_1_data_5730_gap_460[471] = { 0xFFFFFFFF, 0x54686973, 0x20726570,
    0x6C617920, 0x616E6420, 0x67686F73, 0x740A2063, 0x616E6E6F, 0x74206265, 0x20736176, 0x65642E00,
    0x54686973, 0x20726570, 0x6C617920, 0x63616E6E, 0x6F742062, 0x65207361, 0x7665642E, 0x00000000,
    0x54686973, 0x2067686F, 0x73742063, 0x616E6E6F, 0x74206265, 0x20736176, 0x65642E00,
    (u32)lbl_1_data_5B94__fzgx_offset_0, (u32)lbl_1_data_5BBC__fzgx_offset_0,
    (u32)lbl_1_data_5BDC__fzgx_offset_0, (u32)lbl_1_data_5B94__fzgx_offset_0,
    (u32)lbl_1_data_5BBC__fzgx_offset_0, (u32)lbl_1_data_5BDC__fzgx_offset_0, 0x4E657720,
    0x70617274, 0x73206861, 0x7665206A, 0x75737420, 0x61727269, 0x76656421, 0x0A2F6263, 0x30306666,
    0x66662F25, 0x732F6263, 0x66666666, 0x66662F0A, 0x596F7520, 0x63616E20, 0x70757263, 0x68617365,
    0x20746865, 0x6D20696E, 0x20746865, 0x2073686F, 0x702E0000, (u32)lbl_1_data_5C10__fzgx_offset_0,
    0x4D616368, 0x696E650A, 0x2F626330, 0x30666666, 0x662F2573, 0x2F626366, 0x66666666, 0x662F0A68,
    0x61732061, 0x72726976, 0x65642E0A, 0x596F7520, 0x63616E20, 0x70757263, 0x68617365, 0x20697420,
    0x61742074, 0x68652073, 0x686F702E, 0x00000000, (u32)lbl_1_data_5C6C__fzgx_offset_0, 0x2F626330,
    0x30666666, 0x662F2573, 0x2F626366, 0x66666666, 0x662F0A53, 0x74616666, 0x2047686F, 0x73747320,
    0x68617665, 0x20617272, 0x69766564, 0x2E0A596F, 0x75206361, 0x6E207075, 0x72636861, 0x73652074,
    0x68656D20, 0x61742074, 0x68652073, 0x686F702E, 0x00000000, (u32)lbl_1_data_5CC0__fzgx_offset_0,
    0x2F626330, 0x30666666, 0x662F2573, 0x2F626366, 0x66666666, 0x662F0A61, 0x72636164, 0x6520636F,
    0x75727365, 0x73206861, 0x76652061, 0x72726976, 0x65642E0A, 0x596F7520, 0x63616E20, 0x70757263,
    0x68617365, 0x20746865, 0x6D206174, 0x20746865, 0x2073686F, 0x702E0000,
    (u32)lbl_1_data_5D1C__fzgx_offset_0, 0x53746F72, 0x790A2F62, 0x63303066, 0x6666662F, 0x25732F62,
    0x63666666, 0x6666662F, 0x0A686173, 0x20617272, 0x69766564, 0x2E0A596F, 0x75206361, 0x6E207075,
    0x72636861, 0x73652069, 0x74206174, 0x20746865, 0x2073686F, 0x702E0000,
    (u32)lbl_1_data_5D78__fzgx_offset_0, 0x2F626330, 0x30666666, 0x662F2573, 0x2F626366, 0x66666666,
    0x662F0A73, 0x6F756E64, 0x73206861, 0x76652061, 0x72726976, 0x65642E0A, 0x596F7520, 0x63616E20,
    0x70757263, 0x68617365, 0x20746865, 0x6D206174, 0x20746865, 0x2073686F, 0x702E0000,
    (u32)lbl_1_data_5DC8__fzgx_offset_0, 0x596F7520, 0x61637175, 0x69726564, 0x20256420, 0x5469636B,
    0x6574732E, 0x00000000, (u32)lbl_1_data_5E1C__fzgx_offset_0, 0x436F6E74, 0x696E7565, 0x00000000,
    0x50726F63, 0x65656420, 0x746F204E, 0x65787400, 0x52657472, 0x79000000, 0x4D697373, 0x696F6E20,
    0x44697370, 0x6C617900, 0x53657474, 0x696E6773, 0x00000000, 0x53656C65, 0x63742043, 0x6F757273,
    0x65000000, 0x5265706C, 0x61790000, 0x53617665, 0x20526570, 0x6C617900, 0x53617665, 0x2047686F,
    0x73740000, 0x53746174, 0x75730000, 0x466F7263, 0x65205769, 0x6E000000, 0x52657365, 0x74000000,
    0x51756974, 0x00000000, (u32)lbl_1_data_5E3C__fzgx_offset_0,
    (u32)lbl_1_data_5E48__fzgx_offset_0, (u32)lbl_1_data_5E48__fzgx_offset_0,
    (u32)lbl_1_data_5E58__fzgx_offset_0, (u32)lbl_1_data_5E60__fzgx_offset_0,
    (u32)lbl_1_data_5E70__fzgx_offset_0, (u32)lbl_1_data_5E7C__fzgx_offset_0,
    (u32)lbl_1_data_5E8C__fzgx_offset_0, (u32)lbl_1_data_5E94__fzgx_offset_0,
    (u32)lbl_1_data_5EA0__fzgx_offset_0, (u32)lbl_1_data_5EAC__fzgx_offset_0,
    (u32)lbl_1_data_5EB4__fzgx_offset_0, (u32)lbl_1_data_5EC0__fzgx_offset_0,
    (u32)lbl_1_data_5EC8__fzgx_offset_0, 0x01000000, 0x436C6561, 0x72205363, 0x656E6172, 0x696F380A,
    0x00000000, 0x4E6F7420, 0x67657420, 0x5363656E, 0x6172696F, 0x39207965, 0x740A0000, 0x4E6F7420,
    0x436C6561, 0x72656420, 0x63757020, 0x25640A00, 0x67657420, 0x7363656E, 0x6172696F, 0x20390A00,
    0x7265706C, 0x61795F65, 0x7869745F, 0x67617000, 0x2F626337, 0x66666666, 0x662F5072, 0x6F6C6F67,
    0x75652F62, 0x63666666, 0x6666662F, 0x20202020, 0x20426C61, 0x636B2053, 0x6861646F, 0x77277320,
    0x44697367, 0x72616365, 0x00000000, 0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220312F,
    0x62636666, 0x66666666, 0x2F202020, 0x20204361, 0x70746169, 0x6E204661, 0x6C636F6E, 0x20547261,
    0x696E7300, 0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220322F, 0x62636666, 0x66666666,
    0x2F202020, 0x2020476F, 0x726F683A, 0x20546865, 0x2056656E, 0x67656675, 0x6C205361, 0x6D757261,
    0x69000000, 0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220332F, 0x62636666, 0x66666666,
    0x2F202020, 0x20204869, 0x67682053, 0x74616B65, 0x7320696E, 0x204D7574, 0x65204369, 0x74790000,
    0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220342F, 0x62636666, 0x66666666, 0x2F202020,
    0x20204368, 0x616C6C65, 0x6E676520, 0x6F662074, 0x68652042, 0x6C6F6F64, 0x79204368, 0x61696E00,
    0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220352F, 0x62636666, 0x66666666, 0x2F202020,
    0x20205361, 0x7665204A, 0x6F647921, 0x00000000, 0x2F626337, 0x66666666, 0x662F4368, 0x61707465,
    0x7220362F, 0x62636666, 0x66666666, 0x2F202020, 0x2020426C, 0x61636B20, 0x53686164, 0x6F772773,
    0x20547261, 0x70000000, 0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220372F, 0x62636666,
    0x66666666, 0x2F202020, 0x20205468, 0x6520462D, 0x5A45524F, 0x20477261, 0x6E642050, 0x72697800,
    0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220382F, 0x62636666, 0x66666666, 0x2F202020,
    0x20205365, 0x63726574, 0x73206F66, 0x20746865, 0x20436861, 0x6D70696F, 0x6E204265, 0x6C740000,
    0x2F626337, 0x66666666, 0x662F4368, 0x61707465, 0x7220392F, 0x62636666, 0x66666666, 0x2F202020,
    0x20204669, 0x6E616C65, 0x3A20456E, 0x74657220, 0x74686520, 0x43726561, 0x746F7273, 0x00000000,
    0x4D757465, 0x20436974, 0x79000000, 0x42696720, 0x426C7565, 0x00000000, 0x839F0000, 0x746F5F67,
    0x616D656F, 0x7665725F, 0x6576656E, 0x74000000, 0x51756974, 0x74696E67, 0x20526570, 0x6C61792E,
    0x204F4B3F, 0x00000000, 0x51756974, 0x74696E67, 0x20477261, 0x6E642050, 0x7269782E, 0x00000000,
    0x51756974, 0x74696E67, 0x2054696D, 0x65204174, 0x7461636B, 0x2E000000, 0x51756974, 0x74696E67,
    0x20746869, 0x73207363, 0x656E6172, 0x696F2E00, 0x51756974, 0x74696E67, 0x20746865, 0x20726163,
    0x652E0000, 0x53746172, 0x74696E67, 0x20726163, 0x65206F76, 0x65722E00, 0x456E7465, 0x72696E67,
    0x20536574, 0x74696E67, 0x73207363, 0x7265656E, 0x2E000000, 0x456E7465, 0x72696E67, 0x2053656C,
    0x65637420, 0x436F7572, 0x73652073, 0x63726565, 0x6E2E0000, 0x53797374, 0x656D2072, 0x65736574,
    0x00000000, 0x59455300, 0x4E4F0000, 0x462D5A45, 0x524F2047, 0x58000000, 0x5B204D45, 0x4E55205D,
    0x00000000, 0x49732074, 0x68697320,
    0x4F4B3F00 }; /* fzgx-allow: A1 measured pool bytes and bindings */
static char fzgx_pool_native_lbl_1_data_5730_filename[8] = { 0x67, 0x61, 0x6D, 0x65, 0x2E, 0x63,
    0x00, 0x00 }; /* fzgx-allow: A1 measured pool bytes and bindings */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_data_base_prime(void) {
    const void* volatile s; /* fzgx-allow: S2 data base primer sink: the retail TU addressed .data
                               off its section base before its literal pool; the section is dropped
                               at integration */
    s = &fzgx_pool_native_lbl_1_data_5730_modes;
    s = &fzgx_pool_native_lbl_1_data_5730_unk_458;
    s = &fzgx_pool_native_lbl_1_data_5730_unk_45C;
    s = &fzgx_pool_native_lbl_1_data_5730_filename;
}
#pragma section code_type ".text"
struct fn_1_37E98_lbl_1_bss_3C00 {
    u8 pad_0[0x10];
    u8 unk_10;
    u8 pad_11;
    u8 unk_12;
    u8 pad_13;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u8 pad_20[4];
    u32 unk_24;
    u8 pad_28[2];
    s16 unk_2A;
    u8 pad_2C[4];
    u32 unk_30;
    u8 pad_34[0x14CC];
    u32 unk_1500;
};
extern u8 lbl_1_bss_5480[0x20700];
extern u16 lbl_1_bss_96A;
extern u32 lbl_1_rodata_E3C;
extern u32 lbl_801A6410;
extern u32 fn_1_435C(u32);
extern u32 fn_1_426C(u32);
extern void fn_1_1547FC(void);
extern u32 fn_1_2DE00(u32);
extern u16 fn_1_4DE04(void);
extern u32 fn_1_A0AA4(void);
extern u32 fn_1_A7024(f32, f32, f32, f32);
extern u16 fn_1_E9CFC(void);
extern u32 fn_80008E84(u32);
extern void camera_set_state_flag(u8);
extern void fn_1_15555C(void);
extern void fn_1_3FCB0(s32);
extern void fn_1_3FCD4(u32);
extern void fn_1_410A0(void);
extern void fn_1_412A0(u32);
extern void fn_1_41A8(void);
extern void fn_1_46B4(u32, u32, const char*, int);
extern void fn_1_48140(int);
extern void fn_1_48164(int);
extern void fn_1_484CC(s32);
extern void fn_1_49F0(u32*);
extern void fn_1_58854(void);
extern void fn_1_6400(void);
extern void fn_1_76BF8(void);
extern void fn_1_79100(void);
extern void fn_1_85878(void);
extern void fn_1_8DAB4(void);
extern void fn_1_982C4(void);
extern void fn_1_C47B4(void);
extern void fn_1_C6F80(u8);
extern void fn_1_D17E8(void);
extern void fn_1_D1F88(void);
extern void fn_1_E35F0(void);
extern void fn_1_F2DDC(void);
extern void fn_1_F2EDC(void);
extern void fn_1_F7308(void);
extern void fn_80008BEC(void*, int, u32);
extern void fn_80009064(u32);
extern void fn_80074D18(u32);
#pragma opt_common_subs off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 lbl_1_bss_3C08[2];
u8 lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u8 fzgx_obj_lbl_1_bss_3C12;
u8 lbl_1_bss_3C12__fzgx_offset_1;
u32 lbl_1_bss_3C12__fzgx_offset_2;
u32 lbl_1_bss_3C12__fzgx_offset_6;
u32 fzgx_obj_lbl_1_bss_3C1C;
u32 lbl_1_bss_3C1C__fzgx_offset_4;
u32 lbl_1_bss_3C1C__fzgx_offset_8;
u16 lbl_1_bss_3C1C__fzgx_offset_C;
s16 fzgx_obj_lbl_1_bss_3C2A;
u32 lbl_1_bss_3C2A__fzgx_offset_2;
u32 fzgx_obj_lbl_1_bss_3C30;
u32 lbl_1_bss_3C30__fzgx_offset_4[1326];
u32 fzgx_obj_lbl_1_bss_50EC[5];
u32 fzgx_obj_lbl_1_bss_5100;
u32 fzgx_obj_lbl_1_bss_5104[13];
u32 fzgx_obj_lbl_1_bss_5138[65];
u32 lbl_1_bss_523C[8];
u32 fzgx_obj_lbl_1_bss_525C[102];
u16 fzgx_obj_lbl_1_bss_53F4;
u16 fzgx_pool_lbl_1_bss_3C00_gap_53F6;
u32 lbl_1_bss_53F8[34];
u32 lbl_1_bss_5480__fzgx_offset_0[31200];
u8 fzgx_pool_fzgx_game_gap_23C00[0x1F88];
u32 fzgx_obj_lbl_1_bss_25B88;
u8 fzgx_pool_fzgx_game_gap_25B8C[0x118];
u32 fzgx_obj_lbl_1_bss_25CA4;
u8 lbl_1_bss_25CA4__fzgx_offset_4[0x24];
u32 lbl_1_bss_25CA4__fzgx_offset_28;
u8 lbl_1_bss_25CD0__fzgx_offset_0[0x1A4];
u32 fzgx_obj_lbl_1_bss_25E74;
u8 lbl_1_bss_25E74__fzgx_offset_4[0x10];
s32 lbl_1_bss_25E74__fzgx_offset_14;
u8 fzgx_pool_fzgx_game_gap_25E8C[0x46C];
u32 fzgx_obj_lbl_1_bss_262F8;
u8 lbl_1_bss_262F8__fzgx_offset_4[0x4];
s16 fzgx_obj_lbl_1_bss_26300;
u16 fzgx_pool_fzgx_game_gap_26302;
u8 fzgx_pool_fzgx_game_gap_26304[0x914];
u32 lbl_1_bss_26B80__fzgx_offset_98;
s32 lbl_1_bss_26B80__fzgx_offset_9C;
u8 fzgx_pool_fzgx_game_gap_26C20[0x20];
u32 lbl_1_bss_26C34__fzgx_offset_C;
u8 lbl_1_bss_26C34__fzgx_offset_10[0x4];
f32 lbl_1_bss_26C34__fzgx_offset_14;
f32 lbl_1_bss_26C34__fzgx_offset_18;
f32 lbl_1_bss_26C34__fzgx_offset_1C;
f32 lbl_1_bss_26C34__fzgx_offset_20;
u8 fzgx_pool_fzgx_game_gap_26C58[0xC];
u32 fzgx_obj_lbl_1_bss_26C64;
u16 fzgx_obj_lbl_1_bss_26C68;
#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    /* fzgx-allow: S2 discarded primer fixes BSS first-access order. */
    volatile u8 s;
    s = *(u8*)&fzgx_obj_lbl_1_bss_3C00;
    s = *(u8*)&fzgx_obj_lbl_1_bss_3C04;
    s = *(u8*)&lbl_1_bss_3C08;
    s = *(u8*)&lbl_1_bss_3C10;
    s = *(u8*)&fzgx_obj_lbl_1_bss_3C11;
    s = *(u8*)&fzgx_obj_lbl_1_bss_3C12;
    s = *(u8*)&lbl_1_bss_3C12__fzgx_offset_1;
    s = *(u8*)&lbl_1_bss_3C12__fzgx_offset_2;
    s = *(u8*)&lbl_1_bss_3C12__fzgx_offset_6;
    s = *(u8*)&fzgx_obj_lbl_1_bss_3C1C;
    s = *(u8*)&lbl_1_bss_3C1C__fzgx_offset_4;
    s = *(u8*)&lbl_1_bss_3C1C__fzgx_offset_8;
    s = *(u8*)&lbl_1_bss_3C1C__fzgx_offset_C;
    s = *(u8*)&fzgx_obj_lbl_1_bss_3C2A;
    s = *(u8*)&lbl_1_bss_3C2A__fzgx_offset_2;
    s = *(u8*)&fzgx_obj_lbl_1_bss_3C30;
    s = *(u8*)&lbl_1_bss_3C30__fzgx_offset_4;
    s = *(u8*)&fzgx_obj_lbl_1_bss_50EC;
    s = *(u8*)&fzgx_obj_lbl_1_bss_5100;
    s = *(u8*)&fzgx_obj_lbl_1_bss_5104;
    s = *(u8*)&fzgx_obj_lbl_1_bss_5138;
    s = *(u8*)&lbl_1_bss_523C;
    s = *(u8*)&fzgx_obj_lbl_1_bss_525C;
    s = *(u8*)&fzgx_obj_lbl_1_bss_53F4;
    s = *(u8*)&fzgx_pool_lbl_1_bss_3C00_gap_53F6;
    s = *(u8*)&lbl_1_bss_53F8;
    s = *(u8*)&lbl_1_bss_5480__fzgx_offset_0;
    s = *(u8*)&fzgx_pool_fzgx_game_gap_23C00;
    s = *(u8*)&fzgx_obj_lbl_1_bss_25B88;
    s = *(u8*)&fzgx_pool_fzgx_game_gap_25B8C;
    s = *(u8*)&fzgx_obj_lbl_1_bss_25CA4;
    s = *(u8*)&lbl_1_bss_25CA4__fzgx_offset_4;
    s = *(u8*)&lbl_1_bss_25CA4__fzgx_offset_28;
    s = *(u8*)&lbl_1_bss_25CD0__fzgx_offset_0;
    s = *(u8*)&fzgx_obj_lbl_1_bss_25E74;
    s = *(u8*)&lbl_1_bss_25E74__fzgx_offset_4;
    s = *(u8*)&lbl_1_bss_25E74__fzgx_offset_14;
    s = *(u8*)&fzgx_pool_fzgx_game_gap_25E8C;
    s = *(u8*)&fzgx_obj_lbl_1_bss_262F8;
    s = *(u8*)&lbl_1_bss_262F8__fzgx_offset_4;
    s = *(u8*)&fzgx_obj_lbl_1_bss_26300;
    s = *(u8*)&fzgx_pool_fzgx_game_gap_26302;
    s = *(u8*)&fzgx_pool_fzgx_game_gap_26304;
    s = *(u8*)&lbl_1_bss_26B80__fzgx_offset_98;
    s = *(u8*)&lbl_1_bss_26B80__fzgx_offset_9C;
    s = *(u8*)&fzgx_pool_fzgx_game_gap_26C20;
    s = *(u8*)&lbl_1_bss_26C34__fzgx_offset_C;
    s = *(u8*)&lbl_1_bss_26C34__fzgx_offset_10;
    s = *(u8*)&lbl_1_bss_26C34__fzgx_offset_14;
    s = *(u8*)&lbl_1_bss_26C34__fzgx_offset_18;
    s = *(u8*)&lbl_1_bss_26C34__fzgx_offset_1C;
    s = *(u8*)&lbl_1_bss_26C34__fzgx_offset_20;
    s = *(u8*)&fzgx_pool_fzgx_game_gap_26C58;
    s = *(u8*)&fzgx_obj_lbl_1_bss_26C64;
    s = *(u8*)&fzgx_obj_lbl_1_bss_26C68;
}
#pragma section code_type ".text"

#pragma opt_dead_assignments off
#pragma opt_loop_invariants off
void fn_1_37E98(void) {

    u32 v1;
    s16 v3;
    u32 v4;
    u32 v5;
    u32 v10;
    u32 loc_8;

    if (fzgx_obj_lbl_1_bss_3C12 != 0) {
        fn_1_435C(fzgx_obj_lbl_1_bss_25B88);
        fn_1_8DAB4();
        v1 = (u32)((u8*)&fzgx_obj_lbl_1_bss_3C30);
        if (*(u8*)(v1 + 5) == 2) {
            fn_1_435C(fzgx_obj_lbl_1_bss_5100);
            fn_1_426C(fzgx_obj_lbl_1_bss_26300);
        }
        v3 = fzgx_obj_lbl_1_bss_3C2A;
        if (v3 != -1) {
            ((fn_1_37E98_Fn0)fzgx_pool_native_lbl_1_data_5730_modes.view[v3 - 36].cleanup)();
        }
        v4 = fzgx_obj_lbl_1_bss_26C64;
        if (v4 != 0)
            ((fn_1_37E98_Fn1)v4)((u32)((u8*)&fzgx_obj_lbl_1_bss_3C30));
        loc_8 = lbl_1_rodata_E3C;
        fn_1_49F0(&loc_8);
        v1 = (u32)((u8*)&fzgx_obj_lbl_1_bss_3C30);
        v5 = *(u32*)(v1 + 192);
        if (v5 != 0)
            ((fn_1_37E98_Fn2)v5)();
        fn_1_E9CFC();
        if (lbl_1_bss_26B80__fzgx_offset_9C != 0) {
            if (fzgx_obj_lbl_1_bss_3C30 & 0x800000)
                fn_1_F2EDC();
            camera_set_state_flag(0);
            fn_1_F7308();
            fn_1_6400();
            fn_1_46B4(lbl_801A6410, lbl_1_bss_3C1C__fzgx_offset_8,
                (const char*)fzgx_pool_native_lbl_1_data_5730_filename, 6148);
            lbl_1_bss_3C1C__fzgx_offset_8 = 0;
            if (lbl_1_bss_25E74__fzgx_offset_14 != 0) {
                fn_1_435C(fzgx_obj_lbl_1_bss_25B88);
                v1 = fzgx_pool_native_lbl_1_data_5730_unk_458;
                if ((s32)v1 != -1) {
                    fn_1_426C(v1);
                    fzgx_pool_native_lbl_1_data_5730_unk_458 = -1;
                }
                fn_1_435C(fzgx_obj_lbl_1_bss_25CA4);
                v1 = fzgx_pool_native_lbl_1_data_5730_unk_45C;
                if ((s32)v1 != -1) {
                    fn_1_426C(v1);
                    fzgx_pool_native_lbl_1_data_5730_unk_45C = -1;
                }
                fn_1_D1F88();
                lbl_1_bss_25E74__fzgx_offset_14 = 0;
            }
            v1 = fn_80008E84(fzgx_obj_lbl_1_bss_262F8);
            fn_1_85878();
            fn_1_982C4();
            fn_80008E84(v1);
            fn_80009064(fzgx_obj_lbl_1_bss_262F8);
            fn_1_46B4(lbl_801A6410, lbl_1_bss_26B80__fzgx_offset_98,
                (const char*)fzgx_pool_native_lbl_1_data_5730_filename, 5986);
            fn_1_58854();
            if (*(s16*)&lbl_1_bss_960 != 10 && *(s16*)&lbl_1_bss_960 != 12
                && !(fzgx_obj_lbl_1_bss_3C30 & 0x400000)) {
                fn_80008BEC(lbl_1_bss_5480, 0, 0x20700);
            }
        }
        fn_1_1547FC();
        fn_1_C47B4();
        fn_1_435C(fzgx_obj_lbl_1_bss_25B88);
        v1 = lbl_1_bss_3C12__fzgx_offset_2;
        if (v1 != 0) {
            fn_1_426C(v1);
            lbl_1_bss_3C12__fzgx_offset_2 = 0;
        }
        fn_1_435C(fzgx_obj_lbl_1_bss_25CA4);
        v1 = lbl_1_bss_3C12__fzgx_offset_6;
        if (v1 != 0) {
            fn_1_426C(v1);
            lbl_1_bss_3C12__fzgx_offset_6 = 0;
        }
        fn_1_C6F80(0);
        v1 = fn_80008E84(lbl_1_bss_25CA4__fzgx_offset_28);
        fn_1_79100();
        fn_80008E84(v1);
        fn_1_412A0(2);
        fn_1_E35F0();
        fn_1_435C(fzgx_obj_lbl_1_bss_25CA4);
        fn_1_41A8();
        fn_1_435C(fzgx_obj_lbl_1_bss_25B88);
        fn_1_41A8();
        fn_1_435C(fzgx_obj_lbl_1_bss_5100);
        fn_1_41A8();
        fn_1_46B4(lbl_801A6410, fzgx_obj_lbl_1_bss_5100,
            (const char*)fzgx_pool_native_lbl_1_data_5730_filename, 7345);
        fn_1_46B4(lbl_801A6410, fzgx_obj_lbl_1_bss_25B88,
            (const char*)fzgx_pool_native_lbl_1_data_5730_filename, 7346);
        fn_1_46B4(lbl_801A6410, fzgx_obj_lbl_1_bss_25CA4,
            (const char*)fzgx_pool_native_lbl_1_data_5730_filename, 7347);
        if (fzgx_obj_lbl_1_bss_3C30 & 0x800000) {
            fn_1_F2DDC();
            fzgx_obj_lbl_1_bss_3C30 &= 0xFF7FFFFF;
        }
        fn_1_A0AA4();
        fn_80074D18(0);
        fn_1_76BF8();
        if (*(s16*)&lbl_1_bss_960 == 12)
            fn_1_48140(150);
        else {
            fn_1_48164(1);
            fn_1_484CC(1);
        }
        fn_1_4DE04();
        fn_1_A7024(lbl_1_bss_26C34__fzgx_offset_14, lbl_1_bss_26C34__fzgx_offset_18, lbl_1_bss_26C34__fzgx_offset_1C,
            lbl_1_bss_26C34__fzgx_offset_20);
        v10 = fzgx_obj_lbl_1_bss_3C1C;
        if (v10 != 0) {
            fn_1_46B4(
                lbl_801A6410, v10, (const char*)fzgx_pool_native_lbl_1_data_5730_filename, 7380);
            fzgx_obj_lbl_1_bss_3C1C = 0;
        }
        fn_1_410A0();
        fn_80009064(lbl_1_bss_25CA4__fzgx_offset_28);
        fn_1_46B4(lbl_801A6410, lbl_1_bss_26C34__fzgx_offset_C,
            (const char*)fzgx_pool_native_lbl_1_data_5730_filename, 7392);
        fn_1_D17E8();
        if (lbl_1_bss_3C10 == 0)
            fn_1_2DE00(0);
        fzgx_obj_lbl_1_bss_26C68 = 0;
        fn_1_3FCB0(0);
        fn_1_3FCD4(0);
        fzgx_obj_lbl_1_bss_25E74 = 0;
        fzgx_obj_lbl_1_bss_26C64 = 0;
        lbl_1_bss_3C10 = 0;
        fzgx_obj_lbl_1_bss_3C12 = 0;
        fn_1_15555C();
        if (fzgx_obj_lbl_1_bss_3C30 & 0x400000)
            lbl_1_bss_96A = 184;
    }
}
#pragma opt_loop_invariants reset

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_37E98 */

/* fzgx:begin fn_1_384E8 noprologue */
#include "rel/main_rel/game.h"

extern void fn_1_12F308(void);
extern int fn_1_4C10(void);
extern u32 fn_1_12F358(u32);
extern int fn_1_467F4(void);
extern void fn_1_4A00(u32, u32, void *);
extern int fn_1_402D4(void);
extern void fn_1_A2D84(u32);

typedef struct {
    u8 pad[6];
    u8 unk_06;
    u8 rest[0x14B1];
} Sub30;

u8 lbl_1_bss_3C00;
static u8 lbl_1_bss_3C04__fzgx_offset_0[4];
static u8 lbl_1_bss_3C08__fzgx_offset_0[8];
static u8 lbl_1_bss_3C10__fzgx_offset_0[1];
static u8 lbl_1_bss_3C11__fzgx_offset_0;
static u8 lbl_1_bss_3C12__fzgx_offset_0;
static u8 lbl_1_bss_3C12__fzgx_offset_1;
static u8 lbl_1_bss_3C12__fzgx_offset_2[8];
static u8 lbl_1_bss_3C1C__fzgx_offset_0[14];
static u8 lbl_1_bss_3C2A__fzgx_offset_0;
static u8 lbl_1_bss_3C2A__fzgx_offset_1;
static u8 lbl_1_bss_3C2A__fzgx_offset_2[4];
static Sub30 lbl_1_bss_3C30__fzgx_offset_0;
static s16 lbl_1_bss_3C30__fzgx_offset_14B8;
static u8 lbl_1_bss_50EC__fzgx_offset_0[0x12];
static void *lbl_1_bss_5100__fzgx_offset_0;

#pragma section code_type ".fzgxpool"
#pragma section code_type ".text"
__declspec(section ".fzgxpool") static void primer(void)
{
    lbl_1_bss_3C00 = 0;
    lbl_1_bss_3C04__fzgx_offset_0[0] = 0;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_1_bss_3C08__fzgx_offset_0;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_1_bss_3C10__fzgx_offset_0;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_1_bss_3C11__fzgx_offset_0;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_1_bss_3C12__fzgx_offset_0;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_1_bss_3C12__fzgx_offset_1;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_1_bss_3C12__fzgx_offset_2;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_1_bss_3C1C__fzgx_offset_0;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_1_bss_3C2A__fzgx_offset_0;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_1_bss_3C2A__fzgx_offset_1;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_1_bss_3C2A__fzgx_offset_2;
    lbl_1_bss_3C30__fzgx_offset_0.unk_06 = 0;
    lbl_1_bss_3C30__fzgx_offset_14B8 = 0;
    lbl_1_bss_50EC__fzgx_offset_0[0] = 0;
    lbl_1_bss_5100__fzgx_offset_0 = 0;
}

void fn_1_384E8(void)
{
    fn_1_12F308();
    if (fn_1_4C10() == 0) {
        fn_1_12F358(lbl_1_bss_3C30__fzgx_offset_0.unk_06);
        if ((s32)lbl_1_bss_26C28 == 2) {
            if (fn_1_467F4() == 0) {
                fn_1_4A00(0, 0x1E, lbl_1_bss_5100__fzgx_offset_0);
                lbl_1_bss_26C28 = 1;
            }
        } else if ((s32)lbl_1_bss_26C28 != 0) {
            lbl_1_bss_3C30__fzgx_offset_14B8 = 0x26;
        } else if (fn_1_402D4() != 0) {
            fn_1_A2D84(0xA9010100);
            lbl_1_bss_26C28 = 2;
        }
    }
}
/* fzgx:end fn_1_384E8 */

/* fzgx:begin fn_1_385A4 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"

typedef struct Sig_ADXT_Pause_AdxSjdHandle Sig_ADXT_Pause_AdxSjdHandle;

typedef struct Sig_ADXT_Pause_ADXStream Sig_ADXT_Pause_ADXStream;

typedef struct Sig_ADXT_Pause_AXRNAHandle Sig_ADXT_Pause_AXRNAHandle;

typedef struct Sig_ADXT_Pause_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Pause_SJCK;

typedef void (*Sig_ADXT_Pause_SJErrorCallback)(void *object, int error);

typedef struct Sig_ADXT_Pause_SJInterface Sig_ADXT_Pause_SJInterface;

typedef struct Sig_ADXT_Pause_SJ Sig_ADXT_Pause_SJ;

struct Sig_ADXT_Pause_SJ {
    const Sig_ADXT_Pause_SJInterface *interface;
};

struct Sig_ADXT_Pause_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Pause_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Pause_SJ *sj);
    void (*reset)(Sig_ADXT_Pause_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, int max_size, Sig_ADXT_Pause_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, Sig_ADXT_Pause_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, Sig_ADXT_Pause_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Pause_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Pause_SJ *sj, Sig_ADXT_Pause_SJErrorCallback callback, void *object);
};

typedef struct Sig_ADXT_Pause_ADX_AMP Sig_ADXT_Pause_ADX_AMP;

typedef struct Sig_ADXT_Pause_LSCObject Sig_ADXT_Pause_LSCObject;

typedef struct Sig_ADXT_Pause_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Pause_AdxSjdHandle *decoder;
    Sig_ADXT_Pause_ADXStream *stream;
    Sig_ADXT_Pause_AXRNAHandle *rna;
    Sig_ADXT_Pause_SJ *stream_sj;
    Sig_ADXT_Pause_SJ *input_sj;
    Sig_ADXT_Pause_SJ *output_sj[2];
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
    Sig_ADXT_Pause_ADX_AMP *amplifier;
    Sig_ADXT_Pause_SJ *amplifier_input[2];
    Sig_ADXT_Pause_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Pause_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Pause_ADXTHandle;

typedef struct Sig_ADXT_Stop_AdxSjdHandle Sig_ADXT_Stop_AdxSjdHandle;

typedef struct Sig_ADXT_Stop_ADXStream Sig_ADXT_Stop_ADXStream;

typedef struct Sig_ADXT_Stop_AXRNAHandle Sig_ADXT_Stop_AXRNAHandle;

typedef struct Sig_ADXT_Stop_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK;

typedef void (*Sig_ADXT_Stop_SJErrorCallback)(void *object, int error);

typedef struct Sig_ADXT_Stop_SJInterface Sig_ADXT_Stop_SJInterface;

typedef struct Sig_ADXT_Stop_SJ Sig_ADXT_Stop_SJ;

struct Sig_ADXT_Stop_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ *sj);
    void (*reset)(Sig_ADXT_Stop_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};

struct Sig_ADXT_Stop_SJ {
    const Sig_ADXT_Stop_SJInterface *interface;
};

typedef struct Sig_ADXT_Stop_ADX_AMP Sig_ADXT_Stop_ADX_AMP;

typedef struct Sig_ADXT_Stop_LSCObject Sig_ADXT_Stop_LSCObject;

typedef struct Sig_ADXT_Stop_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Stop_AdxSjdHandle *decoder;
    Sig_ADXT_Stop_ADXStream *stream;
    Sig_ADXT_Stop_AXRNAHandle *rna;
    Sig_ADXT_Stop_SJ *stream_sj;
    Sig_ADXT_Stop_SJ *input_sj;
    Sig_ADXT_Stop_SJ *output_sj[2];
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
    Sig_ADXT_Stop_ADX_AMP *amplifier;
    Sig_ADXT_Stop_SJ *amplifier_input[2];
    Sig_ADXT_Stop_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Stop_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Stop_ADXTHandle;

typedef struct {
    u8 unk[0xb];
    u8 value;
} Entry;

typedef struct {
    u8 pad_0[2];
    s16 unk_2;
    u8 pad_4[8];
    u32 unk_C;
    u8 pad_10[0x10];
} Obj_1_bss_25E9C;

typedef struct {
    u8 pad[0x2f8];
    u32 value_2f8;
    u32 value_2fc;
    u32 value_300;
    u32 value_304;
    u32 value_308;
    u32 value_30c;
    u32 value_310;
    u32 value_314;
    u32 value_318;
    u32 value_31c;
} Fn40710Config;
extern void fn_1_15E330(s32 index, u32 value, void *arg);
extern void fn_1_15E5E4(s32 index, void *arg);
extern void fn_1_15E688(s32 index, u32 value, u8 state, void *arg);
extern void fn_1_15E3E0(s32 index, u32 value);
extern void fn_1_15E434(u32 value);
extern void fn_1_15E540(s32 index, void *arg);
extern void fn_1_CB404(u8 value);
extern void fn_1_D07C4(u32 arg0, u32 arg1);
extern u32 lbl_1_bss_25B84;
extern u32 OSGetTick(void);
extern void fn_1_A0978(void);
extern void fn_1_35174(void);
extern s32 fn_1_3EFA8(void);
extern u16 lbl_1_bss_26B7A[3];
extern u16 lbl_1_bss_26300;
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern u32 fn_1_101C0(void);
extern u32 fn_1_A11EC(void);
extern u32 fn_1_435C(u32 value);
extern void ADXT_Pause(Sig_ADXT_Pause_ADXTHandle *, s32);
extern void fn_1_4310(u32 arg0);
extern void fn_1_48004(s32 index, s32 image);
extern void fn_1_8616C(void);
extern void fn_1_A1588(u32 arg0, u32 arg1);
extern void fn_1_D0790(void);
extern void fn_1_817C0(void);
extern u32 lbl_1_bss_381FC;
extern void fn_1_EB080(int mode);
extern s64 OSGetTime(void);
extern void fn_1_4A00(u32 arg0, u32 arg1, u32 arg2);
extern void fn_1_5370(u32 arg0, u32 arg1);
extern void fn_1_15E27C(void);
extern void fn_1_4811C(int arg);
extern void fn_1_A8F78(void);
extern u8 lbl_1_bss_262F4;
extern u32 lbl_1_bss_25E74[7];
extern u8 lbl_1_bss_3C10;
extern void fn_1_36330(void);
extern void fn_1_36B10(void);
extern void fn_1_3C98(void);
extern void fn_1_37AA8(void);
extern void fn_1_37E98(void);
extern f32 lbl_1_bss_26304[4];
extern u8 lbl_1_bss_26B04[20];
extern u8 lbl_1_bss_26314[2032];
extern s16 fn_1_12EF24(s16 row, s16 column);
extern u8 lbl_1_bss_523C[32];
extern Entry *lbl_1_bss_53F8[34];
extern void OSPanic(const void *, u32, const char *, ...);
extern Obj_1_bss_25E9C lbl_1_bss_25E9C[30];
extern void fn_1_12AB38(void *arg0);
extern void fn_1_465D0(char *value, u32 flag);
extern void* fn_1_7F518(s16 car_type, void* car, s32 initialize);
extern int sprintf(char *s, const char *format, ...);
extern void fn_1_451E4(void);
extern void fn_1_D3214(void);
extern void VIWaitForRetrace(void);
extern u32 fn_1_467F4(void);
extern u32 fn_1_13018(void);
extern u32 fn_1_46C60(void);
extern u32 lbl_1_bss_26C2C[2];
extern u32 lbl_1_bss_262F8[2];
extern u16 lbl_1_bss_26C68[35526];
extern u32 lbl_1_bss_3C08[2];
extern u32 fn_800075AC(u32, u32, u32);
extern u32 ghost_test_record_flag0(s32 arg);
extern u32 fn_1_F9D44(u32 arg);
extern u8 fn_1_F8C50(s32 arg0);
extern void fn_1_2DB50(void);
extern void fn_1_3F8C(void *, void *, Obj_1_bss_5138 *, int);
extern void fn_1_2D888(void);
extern void fn_1_2D524(void);
extern u32 fn_1_FA070(void);
extern int fn_1_FA180(int, u8);
extern u32 fn_1_F9FEC(void);
extern void fn_1_A2DC4(u32 arg0);
extern Fn40710Config lbl_1_rodata_BD8;
extern u8 lbl_1_bss_26B54[8];
extern u32 fn_1_40EE4(void);
extern u32 lbl_801A63D0;
extern u32 lbl_1_bss_26C34[9];
extern u8 lbl_1_bss_38218[568];
extern u32 fn_1_4060(void);
extern void ARQPostRequest(u8 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, u32 arg7);
extern u32 lbl_801A63C0;
extern void fn_1_40BE4(void);
extern u32 GXGetTexBufferSize(u32, u32, u32, u32, u32);
extern u32 lbl_1_bss_26B4C;
extern u8 lbl_1_bss_25E90[8];
extern s32 fn_1_48B0(u32 arg0, u32 arg1);
extern void fn_1_40F54(void *arg0);
extern u32 lbl_801A6CE0;
extern u32 lbl_1_bss_38454;
extern u32 fn_80070DE0(u32 arg0);
extern void fn_1_D3884();
extern void fn_1_D358C();
extern void fn_800711A8(Obj_1_bss_38458_Target *target);
extern void fn_80071718(u32 value);
extern void fn_1_41134(void *unused, char *value);
extern void fn_1_411D4(u32, char *);
extern int DVDConvertPathToEntrynum(char *buffer);
extern void fn_1_412A0(u32 index);
extern size_t strlen(const char *str);
extern int fn_80083BCC(const char *s1, const char *s2);
extern u8 lbl_1_A9011300;
extern u8 lbl_1_A9011100;
extern u8 lbl_1_A9011000;

typedef struct Sig_fn_1_12F30C_Fn1_12F30CState {
    s32 value;
} Sig_fn_1_12F30C_Fn1_12F30CState;

struct fn_1_385A4_sub {
    u8 pad_6[6];
    u8 unk_6;
    u8 pad_7[1];
    u8 unk_8;
};

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 fzgx_obj_lbl_1_bss_3C08[2];
u8 fzgx_obj_lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u8 fzgx_obj_lbl_1_bss_3C12;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b5;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b7;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b8;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b9;
u8 fzgx_obj_lbl_1_bss_3C1C[14];
u8 fzgx_obj_lbl_1_bss_3C2A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b5;
u32 fzgx_obj_lbl_1_bss_3C30[1327];
u32 fzgx_obj_lbl_1_bss_50EC[5];
u32 fzgx_obj_lbl_1_bss_5100;
u32 fzgx_obj_lbl_1_bss_5104[13];
u32 fzgx_obj_lbl_1_bss_5138[65];
u32 fzgx_obj_lbl_1_bss_523C[8];
u32 fzgx_obj_lbl_1_bss_525C[102];
u16 fzgx_obj_lbl_1_bss_53F4;
u32 fzgx_obj_lbl_1_bss_53F8[34];
u32 fzgx_obj_lbl_1_bss_5480[33216];
u16 fzgx_obj_lbl_1_bss_25B80;
u32 fzgx_obj_lbl_1_bss_25B84;
u32 fzgx_obj_lbl_1_bss_25B88[4];
u16 fzgx_obj_lbl_1_bss_25B98;
u32 fzgx_obj_lbl_1_bss_25B9C;
u32 fzgx_obj_lbl_1_bss_25BA0[42];
u32 fzgx_obj_lbl_1_bss_25C48[23];
u32 fzgx_obj_lbl_1_bss_25CA4[10];
u32 lbl_1_bss_25CA4__fzgx_offset_28;
u32 fzgx_obj_lbl_1_bss_25CD0[105];
u32 fzgx_obj_lbl_1_bss_25E74[7];
u32 fzgx_obj_lbl_1_bss_25E90[2];
u8 fzgx_obj_lbl_1_bss_25E98;
u32 fzgx_obj_lbl_1_bss_25E9C[240];
u32 fzgx_obj_lbl_1_bss_2625C[8];
u32 fzgx_obj_lbl_1_bss_2627C[30];
u8 fzgx_obj_lbl_1_bss_262F4;
u32 fzgx_obj_lbl_1_bss_262F8[2];
u16 fzgx_obj_lbl_1_bss_26300;
u32 fzgx_obj_lbl_1_bss_26304[4];
u32 fzgx_obj_lbl_1_bss_26314[508];
u32 fzgx_obj_lbl_1_bss_26B04[5];
u8 fzgx_obj_lbl_1_bss_26B18;
u8 fzgx_obj_lbl_1_bss_26B19;
u8 fzgx_obj_lbl_1_bss_26B1A;
u8 fzgx_pool_fzgx_pad_26B1B;
u8 fzgx_pool_fzgx_pad_26B1C;
u8 fzgx_obj_lbl_1_bss_26B1D;
u8 fzgx_obj_lbl_1_bss_26B1E;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b42;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b43;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b44;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b45;
u32 fzgx_obj_lbl_1_bss_26B4C;
u32 fzgx_obj_lbl_1_bss_26B50;
u32 fzgx_obj_lbl_1_bss_26B54[2];
u8 fzgx_obj_lbl_1_bss_26B5C[30];
u8 fzgx_obj_lbl_1_bss_26B7A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
u32 fzgx_obj_lbl_1_bss_26B80[42];
u32 fzgx_obj_lbl_1_bss_26C28;
u32 fzgx_obj_lbl_1_bss_26C2C[2];
u32 fzgx_obj_lbl_1_bss_26C34[9];
u8 fzgx_obj_lbl_1_bss_26C58;
u32 fzgx_obj_lbl_1_bss_26C5C;
u32 fzgx_obj_lbl_1_bss_26C60;
u32 fzgx_obj_lbl_1_bss_26C64;
u16 fzgx_obj_lbl_1_bss_26C68;
u8 lbl_1_bss_26C68__fzgx_offset_2;
u8 lbl_1_bss_26C68__fzgx_offset_3;
u32 lbl_1_bss_26C68__fzgx_offset_4[17762];

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_3C00;
    s = fzgx_obj_lbl_1_bss_3C04;
    s = fzgx_obj_lbl_1_bss_3C08[0];
    s = fzgx_obj_lbl_1_bss_3C10;
    s = fzgx_obj_lbl_1_bss_3C11;
    s = fzgx_obj_lbl_1_bss_3C12;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b5;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b7;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b8;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b9;
    s = fzgx_obj_lbl_1_bss_3C1C[0];
    s = fzgx_obj_lbl_1_bss_3C2A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b5;
    s = fzgx_obj_lbl_1_bss_3C30[0];
    s = fzgx_obj_lbl_1_bss_50EC[0];
    s = fzgx_obj_lbl_1_bss_5100;
    s = fzgx_obj_lbl_1_bss_5104[0];
    s = fzgx_obj_lbl_1_bss_5138[0];
    s = fzgx_obj_lbl_1_bss_523C[0];
    s = fzgx_obj_lbl_1_bss_525C[0];
    s = fzgx_obj_lbl_1_bss_53F4;
    s = fzgx_obj_lbl_1_bss_53F8[0];
    s = fzgx_obj_lbl_1_bss_5480[0];
    s = fzgx_obj_lbl_1_bss_25B80;
    s = fzgx_obj_lbl_1_bss_25B84;
    s = fzgx_obj_lbl_1_bss_25B88[0];
    s = fzgx_obj_lbl_1_bss_25B98;
    s = fzgx_obj_lbl_1_bss_25B9C;
    s = fzgx_obj_lbl_1_bss_25BA0[0];
    s = fzgx_obj_lbl_1_bss_25C48[0];
    s = fzgx_obj_lbl_1_bss_25CA4[0];
    s = lbl_1_bss_25CA4__fzgx_offset_28;
    s = fzgx_obj_lbl_1_bss_25CD0[0];
    s = fzgx_obj_lbl_1_bss_25E74[0];
    s = fzgx_obj_lbl_1_bss_25E90[0];
    s = fzgx_obj_lbl_1_bss_25E98;
    s = fzgx_obj_lbl_1_bss_25E9C[0];
    s = fzgx_obj_lbl_1_bss_2625C[0];
    s = fzgx_obj_lbl_1_bss_2627C[0];
    s = fzgx_obj_lbl_1_bss_262F4;
    s = fzgx_obj_lbl_1_bss_262F8[0];
    s = fzgx_obj_lbl_1_bss_26300;
    s = fzgx_obj_lbl_1_bss_26304[0];
    s = fzgx_obj_lbl_1_bss_26314[0];
    s = fzgx_obj_lbl_1_bss_26B04[0];
    s = fzgx_obj_lbl_1_bss_26B18;
    s = fzgx_obj_lbl_1_bss_26B19;
    s = fzgx_obj_lbl_1_bss_26B1A;
    s = fzgx_pool_fzgx_pad_26B1B;
    s = fzgx_pool_fzgx_pad_26B1C;
    s = fzgx_obj_lbl_1_bss_26B1D;
    s = fzgx_obj_lbl_1_bss_26B1E;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b42;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b43;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b44;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b45;
    s = fzgx_obj_lbl_1_bss_26B4C;
    s = fzgx_obj_lbl_1_bss_26B50;
    s = fzgx_obj_lbl_1_bss_26B54[0];
    s = fzgx_obj_lbl_1_bss_26B5C[0];
    s = fzgx_obj_lbl_1_bss_26B7A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
    s = fzgx_obj_lbl_1_bss_26B80[0];
    s = fzgx_obj_lbl_1_bss_26C28;
    s = fzgx_obj_lbl_1_bss_26C2C[0];
    s = fzgx_obj_lbl_1_bss_26C34[0];
    s = fzgx_obj_lbl_1_bss_26C58;
    s = fzgx_obj_lbl_1_bss_26C5C;
    s = fzgx_obj_lbl_1_bss_26C60;
    s = fzgx_obj_lbl_1_bss_26C64;
    s = fzgx_obj_lbl_1_bss_26C68;
    s = lbl_1_bss_26C68__fzgx_offset_2;
    s = lbl_1_bss_26C68__fzgx_offset_3;
    s = lbl_1_bss_26C68__fzgx_offset_4[0];
}
#pragma section code_type ".text"

void fn_1_385A4(void)
{
    u32 saved;
    fn_1_A8F78();
    fn_1_1596DC(2);
    saved = fn_80008E84(lbl_1_bss_25CA4__fzgx_offset_28);
    fn_1_12F30C((void *)fzgx_obj_lbl_1_bss_25CA4[0],
                (Sig_fn_1_12F30C_Fn1_12F30CState *)lbl_1_bss_26C68__fzgx_offset_4);
    fn_1_412A0(1);
    fn_1_48140(0xa1);
    fn_1_48140(fn_1_402A4(((struct fn_1_385A4_sub *)fzgx_obj_lbl_1_bss_3C30)->unk_6));
    if (((struct fn_1_385A4_sub *)fzgx_obj_lbl_1_bss_3C30)->unk_8 == 1) {
        fn_1_48140(0x9b);
    }
    else {
        fn_1_48140(0x9d);
    }
    fn_1_48140(0x9a);
    fn_80008E84(saved);
    fn_1_3F75C();
    if (lbl_1_data_5B7C == 1) {
        lbl_1_bss_26C68__fzgx_offset_2 = 1;
    }
}
/* fzgx:end fn_1_385A4 */

/* fzgx:begin fn_1_38BBC noprologue */
#include "types.h"

typedef struct GameState30 {
    u32 flags;
    u8 pad_4[0x14B4];
} GameState30;

typedef struct GameLinkSlot {
    u8 data[0x1C];
} GameLinkSlot;

typedef struct GameLink {
    u8 pad_0[0x1C];
    GameLinkSlot *slots;
    u8 pad_20[0x11550 - 0x20];
} GameLink;

typedef struct {
    u32 unk_0;
    u8 pad_4[0xE];
} Obj_1_bss_6EAB4;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 fzgx_obj_lbl_1_bss_3C08[2];
u8 fzgx_obj_lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u8 fzgx_obj_lbl_1_bss_3C12;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b5;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b7;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b8;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b9;
u32 fzgx_obj_lbl_1_bss_3C1C;
u8 lbl_1_bss_3C1C__fzgx_offset_4[10];
u8 fzgx_obj_lbl_1_bss_3C2A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b5;
GameState30 fzgx_obj_lbl_1_bss_3C30;
s16 lbl_1_bss_3C30__fzgx_offset_14B8;
s16 lbl_1_bss_3C30__fzgx_offset_14BA;
u32 fzgx_obj_lbl_1_bss_50EC[5];
u32 fzgx_obj_lbl_1_bss_5100;
u32 fzgx_obj_lbl_1_bss_5104[13];
u32 fzgx_obj_lbl_1_bss_5138[65];
u32 fzgx_obj_lbl_1_bss_523C[8];
u32 fzgx_obj_lbl_1_bss_525C[102];
u16 fzgx_obj_lbl_1_bss_53F4;
u32 fzgx_obj_lbl_1_bss_53F8[34];
u32 fzgx_obj_lbl_1_bss_5480[33216];
u16 fzgx_obj_lbl_1_bss_25B80;
u32 fzgx_obj_lbl_1_bss_25B84;
u32 fzgx_obj_lbl_1_bss_25B88[4];
u16 fzgx_obj_lbl_1_bss_25B98;
u32 fzgx_obj_lbl_1_bss_25B9C;
u32 fzgx_obj_lbl_1_bss_25BA0[42];
u32 fzgx_obj_lbl_1_bss_25C48[23];
u32 fzgx_obj_lbl_1_bss_25CA4[11];
u32 fzgx_obj_lbl_1_bss_25CD0[105];
u32 fzgx_obj_lbl_1_bss_25E74[7];
u32 fzgx_obj_lbl_1_bss_25E90[2];
u8 fzgx_obj_lbl_1_bss_25E98[4];
u32 fzgx_obj_lbl_1_bss_25E9C[240];
u32 fzgx_obj_lbl_1_bss_2625C[8];
u32 fzgx_obj_lbl_1_bss_2627C[30];
u8 fzgx_obj_lbl_1_bss_262F4;
u32 fzgx_obj_lbl_1_bss_262F8[2];
u16 fzgx_obj_lbl_1_bss_26300;
u32 fzgx_obj_lbl_1_bss_26304[4];
u32 fzgx_obj_lbl_1_bss_26314[508];
u32 fzgx_obj_lbl_1_bss_26B04[5];
u8 fzgx_obj_lbl_1_bss_26B18;
u8 fzgx_obj_lbl_1_bss_26B19;
u8 fzgx_obj_lbl_1_bss_26B1A;
u8 fzgx_pool_fzgx_pad_26B1B;
u8 fzgx_pool_fzgx_pad_26B1C;
u8 fzgx_obj_lbl_1_bss_26B1D;
u8 fzgx_obj_lbl_1_bss_26B1E;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b42;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b43;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b44;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b45;
u32 fzgx_obj_lbl_1_bss_26B4C;
u32 fzgx_obj_lbl_1_bss_26B50;
u32 fzgx_obj_lbl_1_bss_26B54[2];
u8 fzgx_obj_lbl_1_bss_26B5C[30];
u8 fzgx_obj_lbl_1_bss_26B7A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
u32 fzgx_obj_lbl_1_bss_26B80[42];
s32 fzgx_obj_lbl_1_bss_26C28;
u32 fzgx_obj_lbl_1_bss_26C2C[2];
u32 fzgx_obj_lbl_1_bss_26C34[9];
u8 fzgx_obj_lbl_1_bss_26C58;
u32 fzgx_obj_lbl_1_bss_26C5C;
u32 fzgx_obj_lbl_1_bss_26C60;
u32 fzgx_obj_lbl_1_bss_26C64;
u32 fzgx_obj_lbl_1_bss_26C68[2];
GameLink lbl_1_bss_26C68__fzgx_offset_8;
u32 lbl_1_bss_26C68__fzgx_offset_11558[4];
u32 lbl_1_bss_26C68__fzgx_offset_11568[8];
u32 lbl_1_bss_26C68__fzgx_offset_11588;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_3C00;
    s = fzgx_obj_lbl_1_bss_3C04;
    s = fzgx_obj_lbl_1_bss_3C08[0];
    s = fzgx_obj_lbl_1_bss_3C10;
    s = fzgx_obj_lbl_1_bss_3C11;
    s = fzgx_obj_lbl_1_bss_3C12;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b5;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b7;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b8;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b9;
    s = fzgx_obj_lbl_1_bss_3C1C;
    s = lbl_1_bss_3C1C__fzgx_offset_4[0];
    s = fzgx_obj_lbl_1_bss_3C2A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b5;
    s = *(u32 *)&fzgx_obj_lbl_1_bss_3C30;
    s = lbl_1_bss_3C30__fzgx_offset_14B8;
    s = lbl_1_bss_3C30__fzgx_offset_14BA;
    s = fzgx_obj_lbl_1_bss_50EC[0];
    s = fzgx_obj_lbl_1_bss_5100;
    s = fzgx_obj_lbl_1_bss_5104[0];
    s = fzgx_obj_lbl_1_bss_5138[0];
    s = fzgx_obj_lbl_1_bss_523C[0];
    s = fzgx_obj_lbl_1_bss_525C[0];
    s = fzgx_obj_lbl_1_bss_53F4;
    s = fzgx_obj_lbl_1_bss_53F8[0];
    s = fzgx_obj_lbl_1_bss_5480[0];
    s = fzgx_obj_lbl_1_bss_25B80;
    s = fzgx_obj_lbl_1_bss_25B84;
    s = fzgx_obj_lbl_1_bss_25B88[0];
    s = fzgx_obj_lbl_1_bss_25B98;
    s = fzgx_obj_lbl_1_bss_25B9C;
    s = fzgx_obj_lbl_1_bss_25BA0[0];
    s = fzgx_obj_lbl_1_bss_25C48[0];
    s = fzgx_obj_lbl_1_bss_25CA4[0];
    s = fzgx_obj_lbl_1_bss_25CD0[0];
    s = fzgx_obj_lbl_1_bss_25E74[0];
    s = fzgx_obj_lbl_1_bss_25E90[0];
    s = fzgx_obj_lbl_1_bss_25E98[0];
    s = fzgx_obj_lbl_1_bss_25E9C[0];
    s = fzgx_obj_lbl_1_bss_2625C[0];
    s = fzgx_obj_lbl_1_bss_2627C[0];
    s = fzgx_obj_lbl_1_bss_262F4;
    s = fzgx_obj_lbl_1_bss_262F8[0];
    s = fzgx_obj_lbl_1_bss_26300;
    s = fzgx_obj_lbl_1_bss_26304[0];
    s = fzgx_obj_lbl_1_bss_26314[0];
    s = fzgx_obj_lbl_1_bss_26B04[0];
    s = fzgx_obj_lbl_1_bss_26B18;
    s = fzgx_obj_lbl_1_bss_26B19;
    s = fzgx_obj_lbl_1_bss_26B1A;
    s = fzgx_pool_fzgx_pad_26B1B;
    s = fzgx_pool_fzgx_pad_26B1C;
    s = fzgx_obj_lbl_1_bss_26B1D;
    s = fzgx_obj_lbl_1_bss_26B1E;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b42;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b43;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b44;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b45;
    s = fzgx_obj_lbl_1_bss_26B4C;
    s = fzgx_obj_lbl_1_bss_26B50;
    s = fzgx_obj_lbl_1_bss_26B54[0];
    s = fzgx_obj_lbl_1_bss_26B5C[0];
    s = fzgx_obj_lbl_1_bss_26B7A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
    s = fzgx_obj_lbl_1_bss_26B80[0];
    s = fzgx_obj_lbl_1_bss_26C28;
    s = fzgx_obj_lbl_1_bss_26C2C[0];
    s = fzgx_obj_lbl_1_bss_26C34[0];
    s = fzgx_obj_lbl_1_bss_26C58;
    s = fzgx_obj_lbl_1_bss_26C5C;
    s = fzgx_obj_lbl_1_bss_26C60;
    s = fzgx_obj_lbl_1_bss_26C64;
    s = fzgx_obj_lbl_1_bss_26C68[0];
    s = *(u32 *)&lbl_1_bss_26C68__fzgx_offset_8;
    s = lbl_1_bss_26C68__fzgx_offset_11558[0];
    s = lbl_1_bss_26C68__fzgx_offset_11568[0];
    s = lbl_1_bss_26C68__fzgx_offset_11588;
}
#pragma section code_type ".text"

extern Obj_1_bss_6EAB4 lbl_1_bss_6EAB4;
extern s32 fn_1_4C10(void);
extern void fn_1_12C060(GameLinkSlot *);
extern s16 fn_1_12B3BC(GameLink *, u32, u32, void *, void *, void *, u32);
extern void fn_1_3F75C(void);
extern void fn_1_4A00(s32, u8, void *);
extern void fn_1_47E54(u32);

void fn_1_38BBC(void) {
    s16 i;
    s16 result;

    if (fn_1_4C10() != 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        fn_1_12C060(&lbl_1_bss_26C68__fzgx_offset_8.slots[i]);
    }
    result = fn_1_12B3BC(&lbl_1_bss_26C68__fzgx_offset_8, fzgx_obj_lbl_1_bss_25B88[0], fzgx_obj_lbl_1_bss_25CA4[0],
                         lbl_1_bss_26C68__fzgx_offset_11558, lbl_1_bss_26C68__fzgx_offset_11568,
                         &lbl_1_bss_26C68__fzgx_offset_11588, 0);
    if (fn_1_4C10() == 0) {
        if (fzgx_obj_lbl_1_bss_26C28 == 1) {
            fn_1_3F75C();
            if (fzgx_obj_lbl_1_bss_3C30.flags & 0x201) {
                lbl_1_bss_3C30__fzgx_offset_14B8 = 0x28;
            } else {
                lbl_1_bss_3C30__fzgx_offset_14B8 = 0x27;
            }
        } else if (fzgx_obj_lbl_1_bss_26C28 == -1) {
            fn_1_3F75C();
            lbl_1_bss_3C30__fzgx_offset_14B8 = 0x25;
        }
    }
    if (result == 1 && fzgx_obj_lbl_1_bss_26C28 == 0) {
        fzgx_obj_lbl_1_bss_26C28 = 1;
        fn_1_4A00(0, 30, (void *)fzgx_obj_lbl_1_bss_5100);
        lbl_1_bss_6EAB4.unk_0 |= 0x2C;
        fn_1_47E54(0x94);
    }
}
/* fzgx:end fn_1_38BBC */

/* fzgx:begin fn_1_3908C noprologue */
#include "types.h"

typedef struct Sig_ADXT_Stop_AdxSjdHandle Sig_ADXT_Stop_AdxSjdHandle;
typedef struct Sig_ADXT_Stop_ADXStream Sig_ADXT_Stop_ADXStream;
typedef struct Sig_ADXT_Stop_AXRNAHandle Sig_ADXT_Stop_AXRNAHandle;
typedef struct Sig_ADXT_Stop_SJInterface Sig_ADXT_Stop_SJInterface;
typedef struct Sig_ADXT_Stop_SJ Sig_ADXT_Stop_SJ;
typedef struct Sig_ADXT_Stop_ADX_AMP Sig_ADXT_Stop_ADX_AMP;
typedef struct Sig_ADXT_Stop_LSCObject Sig_ADXT_Stop_LSCObject;
typedef struct Sig_ADXT_Pause_AdxSjdHandle Sig_ADXT_Pause_AdxSjdHandle;
typedef struct Sig_ADXT_Pause_ADXStream Sig_ADXT_Pause_ADXStream;
typedef struct Sig_ADXT_Pause_AXRNAHandle Sig_ADXT_Pause_AXRNAHandle;
typedef struct Sig_ADXT_Pause_SJInterface Sig_ADXT_Pause_SJInterface;
typedef struct Sig_ADXT_Pause_SJ Sig_ADXT_Pause_SJ;
typedef struct Sig_ADXT_Pause_ADX_AMP Sig_ADXT_Pause_ADX_AMP;
typedef struct Sig_ADXT_Pause_LSCObject Sig_ADXT_Pause_LSCObject;
typedef struct Sig_ADXT_Stop_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK;
typedef void (*Sig_ADXT_Stop_SJErrorCallback)(void *object, int error);
struct Sig_ADXT_Stop_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ *sj);
    void (*reset)(Sig_ADXT_Stop_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};
struct Sig_ADXT_Stop_SJ {
    const Sig_ADXT_Stop_SJInterface *interface;
};
typedef struct Sig_ADXT_Stop_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Stop_AdxSjdHandle *decoder;
    Sig_ADXT_Stop_ADXStream *stream;
    Sig_ADXT_Stop_AXRNAHandle *rna;
    Sig_ADXT_Stop_SJ *stream_sj;
    Sig_ADXT_Stop_SJ *input_sj;
    Sig_ADXT_Stop_SJ *output_sj[2];
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
    Sig_ADXT_Stop_ADX_AMP *amplifier;
    Sig_ADXT_Stop_SJ *amplifier_input[2];
    Sig_ADXT_Stop_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Stop_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Stop_ADXTHandle;
typedef struct Sig_ADXT_Pause_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Pause_SJCK;
typedef void (*Sig_ADXT_Pause_SJErrorCallback)(void *object, int error);
struct Sig_ADXT_Pause_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Pause_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Pause_SJ *sj);
    void (*reset)(Sig_ADXT_Pause_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, int max_size, Sig_ADXT_Pause_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, Sig_ADXT_Pause_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, Sig_ADXT_Pause_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Pause_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Pause_SJ *sj, Sig_ADXT_Pause_SJErrorCallback callback, void *object);
};
struct Sig_ADXT_Pause_SJ {
    const Sig_ADXT_Pause_SJInterface *interface;
};
typedef struct Sig_ADXT_Pause_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Pause_AdxSjdHandle *decoder;
    Sig_ADXT_Pause_ADXStream *stream;
    Sig_ADXT_Pause_AXRNAHandle *rna;
    Sig_ADXT_Pause_SJ *stream_sj;
    Sig_ADXT_Pause_SJ *input_sj;
    Sig_ADXT_Pause_SJ *output_sj[2];
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
    Sig_ADXT_Pause_ADX_AMP *amplifier;
    Sig_ADXT_Pause_SJ *amplifier_input[2];
    Sig_ADXT_Pause_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Pause_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Pause_ADXTHandle;

struct fn_1_3908C_lbl_1_bss_25B88 {
    u32 unk_0;
};
struct fn_1_3908C_lbl_1_bss_25CA4 {
    u32 unk_0;
};
struct fn_1_3908C_lbl_1_bss_3C30 {
    u8 pad_0[0x5];
    u8 unk_5;
    u8 unk_6;
    u8 pad_7[0x146D];
    u32 unk_1474;
};
struct fn_1_3908C_lbl_1_bss_6EAD0 {
    u32 unk_0;
};
struct fn_1_3908C_lbl_1_bss_381F5 {
    u8 unk_0;
};

extern s16 lbl_1_bss_960;
extern struct fn_1_3908C_lbl_1_bss_25B88 lbl_1_bss_25B88;
extern struct fn_1_3908C_lbl_1_bss_25CA4 lbl_1_bss_25CA4;
extern struct fn_1_3908C_lbl_1_bss_381F5 lbl_1_bss_381F5;
extern struct fn_1_3908C_lbl_1_bss_3C30 lbl_1_bss_3C30;
extern struct fn_1_3908C_lbl_1_bss_6EAD0 lbl_1_bss_6EAD0;
extern u32 fn_1_101C0(void);
extern u32 fn_1_A11EC(void);
extern u32 lbl_1_bss_26C28;
extern s8 lbl_1_bss_5104;
extern void * fn_1_435C(void *);
extern void ADXT_Pause(Sig_ADXT_Pause_ADXTHandle *, s32);
extern void fn_1_4310(u32);
extern void fn_1_48004(s32, s32);
extern void fn_1_8616C(void);
extern void fn_1_A1588(Sig_ADXT_Stop_ADXTHandle *, u32);
extern void fn_1_D0790(void);

void fn_1_3908C(void) {
    u32 v0;
    u32 v1;
    s32 t7;
    fn_1_435C((void *)lbl_1_bss_25B88.unk_0);
    fn_1_4310(-1);
    fn_1_435C((void *)lbl_1_bss_25CA4.unk_0);
    fn_1_4310(-1);
    fn_1_8616C();
    switch ((s32)lbl_1_bss_3C30.unk_6) {
case 31: case 32: case 33: case 34: case 35: case 36: {

    v0 = 1;
    
} break;
default: {

    v0 = 0;
    
} break;
}
    fn_1_A11EC();
    fn_1_D0790();
    lbl_1_bss_5104 = -1;
    t7 = fn_1_101C0();
    lbl_1_bss_26C28 = t7;    if (t7 < 0) {
    lbl_1_bss_26C28 = 0xf0;
    }
    if (lbl_1_bss_960 == 9 || (v0 & 0xFF) != 0) {
    lbl_1_bss_26C28 = 350;
    fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)*(u32 *)((u8 *)lbl_1_bss_6EAD0.unk_0 + 0), 7);
    } else {
    fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)*(u32 *)((u8 *)lbl_1_bss_6EAD0.unk_0 + 0), 6);
    }
    lbl_1_bss_3C30.unk_1474 = 0;
    v1 = lbl_1_bss_6EAD0.unk_0;
    lbl_1_bss_381F5.unk_0 = 1;
    ADXT_Pause((Sig_ADXT_Pause_ADXTHandle *)*(u32 *)((u8 *)v1 + 0), 1);
    if (lbl_1_bss_3C30.unk_5 == 1) {
    fn_1_48004(187, 1);
    }
}
/* fzgx:end fn_1_3908C */

/* fzgx:begin fn_1_391F0 noprologue */
#include "types.h"
#include "rel/main_rel/game.h"

struct Sig_fn_8004BD5C_fn_8004BD5C_Arg0 { u8 pad_0[0x71]; s8 unk_71; };
typedef struct Sig_ADXT_Pause_ADXTHandle Sig_ADXT_Pause_ADXTHandle;
extern s32 fn_8004BD5C(struct Sig_fn_8004BD5C_fn_8004BD5C_Arg0 *);
extern void ADXT_Pause(Sig_ADXT_Pause_ADXTHandle *, s32);
extern u8 lbl_1_bss_6F31A[138];
extern void *fn_1_435C(void *);
extern void fn_1_4310(u32);
extern void fn_1_4A00(s32, u8, void *);
extern void fn_1_5370(s8, s32);
extern u32 fn_1_101C0(void);
extern void fn_1_3F4FC(void);
extern u32 fn_1_467F4(void);
extern int fn_1_EB200(void);
extern int fn_1_4C10(void);
struct fn_1_391F0_st30 { u8 pad_0[5]; u8 unk_5; u8 unk_6; };
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 fzgx_obj_lbl_1_bss_3C08[2];
u8 fzgx_obj_lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u8 fzgx_obj_lbl_1_bss_3C12;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b5;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b7;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b8;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b9;
u8 fzgx_obj_lbl_1_bss_3C1C[14];
u8 fzgx_obj_lbl_1_bss_3C2A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b5;
u32 fzgx_obj_lbl_1_bss_3C30[1326];
u16 lbl_1_bss_3C30__fzgx_offset_14B8;
u16 lbl_1_bss_3C30__fzgx_offset_14BA;
u32 fzgx_obj_lbl_1_bss_50EC[5];
u32 fzgx_obj_lbl_1_bss_5100;
u32 fzgx_obj_lbl_1_bss_5104[13];
u32 fzgx_obj_lbl_1_bss_5138[65];
u32 fzgx_obj_lbl_1_bss_523C[8];
u32 fzgx_obj_lbl_1_bss_525C[102];
u16 fzgx_obj_lbl_1_bss_53F4;
u32 fzgx_obj_lbl_1_bss_53F8[34];
u32 fzgx_obj_lbl_1_bss_5480[33216];
u16 fzgx_obj_lbl_1_bss_25B80;
u32 fzgx_obj_lbl_1_bss_25B84;
u32 fzgx_obj_lbl_1_bss_25B88[4];
u16 fzgx_obj_lbl_1_bss_25B98;
u32 fzgx_obj_lbl_1_bss_25B9C;
u32 fzgx_obj_lbl_1_bss_25BA0[42];
u32 fzgx_obj_lbl_1_bss_25C48[23];
u32 fzgx_obj_lbl_1_bss_25CA4[10];
u32 lbl_1_bss_25CA4__fzgx_offset_28;
u32 fzgx_obj_lbl_1_bss_25CD0[105];
u32 fzgx_obj_lbl_1_bss_25E74[7];
u32 fzgx_obj_lbl_1_bss_25E90[2];
u8 fzgx_obj_lbl_1_bss_25E98;
u32 fzgx_obj_lbl_1_bss_25E9C[240];
u32 fzgx_obj_lbl_1_bss_2625C[8];
u32 fzgx_obj_lbl_1_bss_2627C[30];
u8 fzgx_obj_lbl_1_bss_262F4;
u32 fzgx_obj_lbl_1_bss_262F8[2];
u16 fzgx_obj_lbl_1_bss_26300;
u32 fzgx_obj_lbl_1_bss_26304[4];
u32 fzgx_obj_lbl_1_bss_26314[508];
u32 fzgx_obj_lbl_1_bss_26B04[5];
u8 fzgx_obj_lbl_1_bss_26B18;
u8 fzgx_obj_lbl_1_bss_26B19;
u8 fzgx_obj_lbl_1_bss_26B1A;
u8 fzgx_pool_fzgx_pad_26B1B;
u8 fzgx_pool_fzgx_pad_26B1C;
u8 fzgx_obj_lbl_1_bss_26B1D;
u8 fzgx_obj_lbl_1_bss_26B1E;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b42;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b43;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b44;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b45;
u32 fzgx_obj_lbl_1_bss_26B4C;
u32 fzgx_obj_lbl_1_bss_26B50;
u32 fzgx_obj_lbl_1_bss_26B54[2];
u8 fzgx_obj_lbl_1_bss_26B5C[30];
u8 fzgx_obj_lbl_1_bss_26B7A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
u32 fzgx_obj_lbl_1_bss_26B80[42];
u32 fzgx_obj_lbl_1_bss_26C28;
u32 fzgx_obj_lbl_1_bss_26C2C[2];
u32 fzgx_obj_lbl_1_bss_26C34[9];
u8 fzgx_obj_lbl_1_bss_26C58;
u32 fzgx_obj_lbl_1_bss_26C5C;
u32 fzgx_obj_lbl_1_bss_26C60;
u32 fzgx_obj_lbl_1_bss_26C64;
u16 fzgx_obj_lbl_1_bss_26C68;
u8 lbl_1_bss_26C68__fzgx_offset_2;
u8 lbl_1_bss_26C68__fzgx_offset_3;
u32 lbl_1_bss_26C68__fzgx_offset_4[17762];

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_3C00;
    s = fzgx_obj_lbl_1_bss_3C04;
    s = fzgx_obj_lbl_1_bss_3C08[0];
    s = fzgx_obj_lbl_1_bss_3C10;
    s = fzgx_obj_lbl_1_bss_3C11;
    s = fzgx_obj_lbl_1_bss_3C12;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b5;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b7;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b8;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b9;
    s = fzgx_obj_lbl_1_bss_3C1C[0];
    s = fzgx_obj_lbl_1_bss_3C2A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b5;
    s = fzgx_obj_lbl_1_bss_3C30[0];
    s = lbl_1_bss_3C30__fzgx_offset_14B8;
    s = lbl_1_bss_3C30__fzgx_offset_14BA;
    s = fzgx_obj_lbl_1_bss_50EC[0];
    s = fzgx_obj_lbl_1_bss_5100;
    s = fzgx_obj_lbl_1_bss_5104[0];
    s = fzgx_obj_lbl_1_bss_5138[0];
    s = fzgx_obj_lbl_1_bss_523C[0];
    s = fzgx_obj_lbl_1_bss_525C[0];
    s = fzgx_obj_lbl_1_bss_53F4;
    s = fzgx_obj_lbl_1_bss_53F8[0];
    s = fzgx_obj_lbl_1_bss_5480[0];
    s = fzgx_obj_lbl_1_bss_25B80;
    s = fzgx_obj_lbl_1_bss_25B84;
    s = fzgx_obj_lbl_1_bss_25B88[0];
    s = fzgx_obj_lbl_1_bss_25B98;
    s = fzgx_obj_lbl_1_bss_25B9C;
    s = fzgx_obj_lbl_1_bss_25BA0[0];
    s = fzgx_obj_lbl_1_bss_25C48[0];
    s = fzgx_obj_lbl_1_bss_25CA4[0];
    s = lbl_1_bss_25CA4__fzgx_offset_28;
    s = fzgx_obj_lbl_1_bss_25CD0[0];
    s = fzgx_obj_lbl_1_bss_25E74[0];
    s = fzgx_obj_lbl_1_bss_25E90[0];
    s = fzgx_obj_lbl_1_bss_25E98;
    s = fzgx_obj_lbl_1_bss_25E9C[0];
    s = fzgx_obj_lbl_1_bss_2625C[0];
    s = fzgx_obj_lbl_1_bss_2627C[0];
    s = fzgx_obj_lbl_1_bss_262F4;
    s = fzgx_obj_lbl_1_bss_262F8[0];
    s = fzgx_obj_lbl_1_bss_26300;
    s = fzgx_obj_lbl_1_bss_26304[0];
    s = fzgx_obj_lbl_1_bss_26314[0];
    s = fzgx_obj_lbl_1_bss_26B04[0];
    s = fzgx_obj_lbl_1_bss_26B18;
    s = fzgx_obj_lbl_1_bss_26B19;
    s = fzgx_obj_lbl_1_bss_26B1A;
    s = fzgx_pool_fzgx_pad_26B1B;
    s = fzgx_pool_fzgx_pad_26B1C;
    s = fzgx_obj_lbl_1_bss_26B1D;
    s = fzgx_obj_lbl_1_bss_26B1E;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b42;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b43;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b44;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b45;
    s = fzgx_obj_lbl_1_bss_26B4C;
    s = fzgx_obj_lbl_1_bss_26B50;
    s = fzgx_obj_lbl_1_bss_26B54[0];
    s = fzgx_obj_lbl_1_bss_26B5C[0];
    s = fzgx_obj_lbl_1_bss_26B7A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
    s = fzgx_obj_lbl_1_bss_26B80[0];
    s = fzgx_obj_lbl_1_bss_26C28;
    s = fzgx_obj_lbl_1_bss_26C2C[0];
    s = fzgx_obj_lbl_1_bss_26C34[0];
    s = fzgx_obj_lbl_1_bss_26C58;
    s = fzgx_obj_lbl_1_bss_26C5C;
    s = fzgx_obj_lbl_1_bss_26C60;
    s = fzgx_obj_lbl_1_bss_26C64;
    s = fzgx_obj_lbl_1_bss_26C68;
    s = lbl_1_bss_26C68__fzgx_offset_2;
    s = lbl_1_bss_26C68__fzgx_offset_3;
    s = lbl_1_bss_26C68__fzgx_offset_4[0];
}
#pragma section code_type ".text"

typedef struct GameElem9F8 { u8 pad_0[8]; u16 unk_8; u8 pad_A[0xA]; } GameElem9F8;

#pragma opt_propagation off
void fn_1_391F0(void) {
 s32 v1;
 u32 v3;
 s32 v4;
 s32 v8;
 s32 v9;
 u16 v10;
 if (lbl_1_bss_6F31A[0] != 0) v1 = 1;
 else v1 = fn_8004BD5C((struct Sig_fn_8004BD5C_fn_8004BD5C_Arg0 *)lbl_1_bss_6EAD0.unk_0->unk_0);
 if (v1 == 0 && (s8)lbl_1_bss_381F5 != 0) return;
 if ((s8)lbl_1_bss_381F5 != 0) {
 switch (((struct fn_1_391F0_st30 *)fzgx_obj_lbl_1_bss_3C30)->unk_6) {
 case 31: case 32: case 33: case 34: case 35: case 36: v3 = 1; break;
 default: v3 = 0; break;
 }
 ADXT_Pause((Sig_ADXT_Pause_ADXTHandle *)lbl_1_bss_6EAD0.unk_0->unk_0, 0);
 fn_1_435C((void *)fzgx_obj_lbl_1_bss_25B88[0]);
 fn_1_4310(0);
 fn_1_435C((void *)fzgx_obj_lbl_1_bss_25CA4[0]);
 fn_1_4310(0);
 fn_1_4310(0x10020000);
 fn_1_435C((void *)fzgx_obj_lbl_1_bss_25B88[0]);
 fn_1_4310(707);
 lbl_1_bss_381F5 = 0;
 fn_1_4A00(1,142,(void *)fzgx_obj_lbl_1_bss_5100);
 fn_1_5370(4,0);
 if ((v3 & 0xff) != 0) v4 = 350;
 else v4 = fn_1_101C0();
 *(s32 *)&fzgx_obj_lbl_1_bss_26C28 = v4;
 if (((struct fn_1_391F0_st30 *)fzgx_obj_lbl_1_bss_3C30)->unk_5 != 1) fn_1_3F4FC();
 }
 --*(s32 *)&fzgx_obj_lbl_1_bss_26C28;
 { u32 v6 = !fn_1_467F4();
 v8 = 0;
 if (v6 && fn_1_EB200() == 0) v8 = 1;
 }
 v9 = 0;
 if (v8 != 0 && fn_1_4C10() == 0) v9 = 1;
 if (v9 != 0) {
 { u16 *flags = &((GameElem9F8 *)&lbl_1_bss_9F8)->unk_8; v10 = *(u16 *)((u8 *)flags + fzgx_obj_lbl_1_bss_25E98 * 20); }
 if (((v10 >> 8)&1) != 0 || ((v10 >> 12)&1) != 0) {
 if (*(s32 *)&fzgx_obj_lbl_1_bss_26C28 > 30) *(s32 *)&fzgx_obj_lbl_1_bss_26C28 = 30;
 }
 }
 if (*(s32 *)&fzgx_obj_lbl_1_bss_26C28 == 30) {
 fn_1_4A00(0,30,(void *)fzgx_obj_lbl_1_bss_5100);
 lbl_1_bss_6EAB4.unk_0 |= 12;
 }
 if (*(s32 *)&fzgx_obj_lbl_1_bss_26C28 == 0) lbl_1_bss_3C30__fzgx_offset_14B8 = 40;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_391F0 */

/* fzgx:begin fn_1_39420 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"

typedef struct Sig_ADXT_Pause_AdxSjdHandle Sig_ADXT_Pause_AdxSjdHandle;

typedef struct Sig_ADXT_Pause_ADXStream Sig_ADXT_Pause_ADXStream;

typedef struct Sig_ADXT_Pause_AXRNAHandle Sig_ADXT_Pause_AXRNAHandle;

typedef struct Sig_ADXT_Pause_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Pause_SJCK;

typedef void (*Sig_ADXT_Pause_SJErrorCallback)(void *object, int error);

typedef struct Sig_ADXT_Pause_SJInterface Sig_ADXT_Pause_SJInterface;

typedef struct Sig_ADXT_Pause_SJ Sig_ADXT_Pause_SJ;

struct Sig_ADXT_Pause_SJ {
    const Sig_ADXT_Pause_SJInterface *interface;
};

struct Sig_ADXT_Pause_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Pause_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Pause_SJ *sj);
    void (*reset)(Sig_ADXT_Pause_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, int max_size, Sig_ADXT_Pause_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, Sig_ADXT_Pause_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, Sig_ADXT_Pause_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Pause_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Pause_SJ *sj, Sig_ADXT_Pause_SJErrorCallback callback, void *object);
};

typedef struct Sig_ADXT_Pause_ADX_AMP Sig_ADXT_Pause_ADX_AMP;

typedef struct Sig_ADXT_Pause_LSCObject Sig_ADXT_Pause_LSCObject;

typedef struct Sig_ADXT_Pause_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Pause_AdxSjdHandle *decoder;
    Sig_ADXT_Pause_ADXStream *stream;
    Sig_ADXT_Pause_AXRNAHandle *rna;
    Sig_ADXT_Pause_SJ *stream_sj;
    Sig_ADXT_Pause_SJ *input_sj;
    Sig_ADXT_Pause_SJ *output_sj[2];
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
    Sig_ADXT_Pause_ADX_AMP *amplifier;
    Sig_ADXT_Pause_SJ *amplifier_input[2];
    Sig_ADXT_Pause_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Pause_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Pause_ADXTHandle;

typedef struct Sig_ADXT_Stop_AdxSjdHandle Sig_ADXT_Stop_AdxSjdHandle;

typedef struct Sig_ADXT_Stop_ADXStream Sig_ADXT_Stop_ADXStream;

typedef struct Sig_ADXT_Stop_AXRNAHandle Sig_ADXT_Stop_AXRNAHandle;

typedef struct Sig_ADXT_Stop_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK;

typedef void (*Sig_ADXT_Stop_SJErrorCallback)(void *object, int error);

typedef struct Sig_ADXT_Stop_SJInterface Sig_ADXT_Stop_SJInterface;

typedef struct Sig_ADXT_Stop_SJ Sig_ADXT_Stop_SJ;

struct Sig_ADXT_Stop_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ *sj);
    void (*reset)(Sig_ADXT_Stop_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};

struct Sig_ADXT_Stop_SJ {
    const Sig_ADXT_Stop_SJInterface *interface;
};

typedef struct Sig_ADXT_Stop_ADX_AMP Sig_ADXT_Stop_ADX_AMP;

typedef struct Sig_ADXT_Stop_LSCObject Sig_ADXT_Stop_LSCObject;

typedef struct Sig_ADXT_Stop_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Stop_AdxSjdHandle *decoder;
    Sig_ADXT_Stop_ADXStream *stream;
    Sig_ADXT_Stop_AXRNAHandle *rna;
    Sig_ADXT_Stop_SJ *stream_sj;
    Sig_ADXT_Stop_SJ *input_sj;
    Sig_ADXT_Stop_SJ *output_sj[2];
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
    Sig_ADXT_Stop_ADX_AMP *amplifier;
    Sig_ADXT_Stop_SJ *amplifier_input[2];
    Sig_ADXT_Stop_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Stop_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Stop_ADXTHandle;

typedef struct {
    u8 unk[0xb];
    u8 value;
} Entry;

typedef struct {
    u8 pad_0[2];
    s16 unk_2;
    u8 pad_4[8];
    u32 unk_C;
    u8 pad_10[0x10];
} Obj_1_bss_25E9C;

typedef struct {
    u8 pad[0x2f8];
    u32 value_2f8;
    u32 value_2fc;
    u32 value_300;
    u32 value_304;
    u32 value_308;
    u32 value_30c;
    u32 value_310;
    u32 value_314;
    u32 value_318;
    u32 value_31c;
} Fn40710Config;
extern void fn_1_15E330(s32 index, u32 value, void *arg);
extern void fn_1_15E5E4(s32 index, void *arg);
extern void fn_1_15E688(s32 index, u32 value, u8 state, void *arg);
extern void fn_1_15E3E0(s32 index, u32 value);
extern void fn_1_15E434(u32 value);
extern void fn_1_15E540(s32 index, void *arg);
extern void fn_1_CB404(u8 value);
extern void fn_1_D07C4(u32 arg0, u32 arg1);
extern u32 lbl_1_bss_25B84;
extern u32 OSGetTick(void);
extern void fn_1_A0978(void);
extern void fn_1_35174(void);
extern s32 fn_1_3EFA8(void);
extern u16 lbl_1_bss_26B7A[3];
extern u16 lbl_1_bss_26300;
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern u32 fn_1_101C0(void);
extern u32 fn_1_A11EC(void);
extern u32 fn_1_435C(u32 value);
extern void ADXT_Pause(Sig_ADXT_Pause_ADXTHandle *, s32);
extern void fn_1_4310(u32 arg0);
extern void fn_1_48004(s32 index, s32 image);
extern void fn_1_8616C(void);
extern void fn_1_A1588(u32 arg0, u32 arg1);
extern void fn_1_D0790(void);
extern void fn_1_817C0(void);
extern u32 lbl_1_bss_381FC;
extern void fn_1_EB080(int mode);
extern s64 OSGetTime(void);
extern void fn_1_4A00(u32 arg0, u32 arg1, u32 arg2);
extern void fn_1_5370(u32 arg0, u32 arg1);
extern void fn_1_15E27C(void);
extern void fn_1_4811C(int arg);
extern void fn_1_A8F78(void);
extern u8 lbl_1_bss_262F4;
extern u32 lbl_1_bss_25E74[7];
extern u8 lbl_1_bss_3C10;
extern void fn_1_36330(void);
extern void fn_1_36B10(void);
extern void fn_1_3C98(void);
extern void fn_1_37AA8(void);
extern void fn_1_37E98(void);
extern f32 lbl_1_bss_26304[4];
extern u8 lbl_1_bss_26B04[20];
extern u8 lbl_1_bss_26314[2032];
extern s16 fn_1_12EF24(s16 row, s16 column);
extern u8 lbl_1_bss_523C[32];
extern Entry *lbl_1_bss_53F8[34];
extern void OSPanic(const void *, u32, const char *, ...);
extern Obj_1_bss_25E9C lbl_1_bss_25E9C[30];
extern void fn_1_12AB38(void *arg0);
extern void fn_1_465D0(char *value, u32 flag);
extern void* fn_1_7F518(s16 car_type, void* car, s32 initialize);
extern int sprintf(char *s, const char *format, ...);
extern void fn_1_451E4(void);
extern void fn_1_D3214(void);
extern void VIWaitForRetrace(void);
extern u32 fn_1_467F4(void);
extern u32 fn_1_13018(void);
extern u32 fn_1_46C60(void);
extern u32 lbl_1_bss_26C2C[2];
extern u32 lbl_1_bss_262F8[2];
extern u16 lbl_1_bss_26C68[35526];
extern u32 lbl_1_bss_3C08[2];
extern u32 fn_800075AC(u32, u32, u32);
extern u32 ghost_test_record_flag0(s32 arg);
extern u32 fn_1_F9D44(u32 arg);
extern u8 fn_1_F8C50(s32 arg0);
extern void fn_1_2DB50(void);
extern void fn_1_3F8C(void *, void *, Obj_1_bss_5138 *, int);
extern void fn_1_2D888(void);
extern void fn_1_2D524(void);
extern u32 fn_1_FA070(void);
extern int fn_1_FA180(int, u8);
extern u32 fn_1_F9FEC(void);
extern void fn_1_A2DC4(u32 arg0);
extern Fn40710Config lbl_1_rodata_BD8;
extern u8 lbl_1_bss_26B54[8];
extern u32 fn_1_40EE4(void);
extern u32 lbl_801A63D0;
extern u32 lbl_1_bss_26C34[9];
extern u8 lbl_1_bss_38218[568];
extern u32 fn_1_4060(void);
extern void ARQPostRequest(u8 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, u32 arg7);
extern u32 lbl_801A63C0;
extern void fn_1_40BE4(void);
extern u32 GXGetTexBufferSize(u32, u32, u32, u32, u32);
extern u32 lbl_1_bss_26B4C;
extern u8 lbl_1_bss_25E90[8];
extern s32 fn_1_48B0(u32 arg0, u32 arg1);
extern void fn_1_40F54(void *arg0);
extern u32 lbl_801A6CE0;
extern u32 lbl_1_bss_38454;
extern u32 fn_80070DE0(u32 arg0);
extern void fn_1_D3884();
extern void fn_1_D358C();
extern void fn_800711A8(Obj_1_bss_38458_Target *target);
extern void fn_80071718(u32 value);
extern void fn_1_41134(void *unused, char *value);
extern void fn_1_411D4(u32, char *);
extern int DVDConvertPathToEntrynum(char *buffer);
extern void fn_1_412A0(u32 index);
extern size_t strlen(const char *str);
extern int fn_80083BCC(const char *s1, const char *s2);
extern u8 lbl_1_A9011300;
extern u8 lbl_1_A9011100;
extern u8 lbl_1_A9011000;

/* sub-object at base+0x30: flag byte at +5, mode byte at +9 */
typedef struct {
    u8 pad_0[5];
    u8 unk_5;
    u8 pad_1[3];
    u8 unk_9;
} St_30;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 fzgx_obj_lbl_1_bss_3C08[2];
u8 fzgx_obj_lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u8 fzgx_obj_lbl_1_bss_3C12;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b5;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b7;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b8;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b9;
u8 fzgx_obj_lbl_1_bss_3C1C[14];
u8 fzgx_obj_lbl_1_bss_3C2A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b5;
u32 fzgx_obj_lbl_1_bss_3C30[1327];
u32 fzgx_obj_lbl_1_bss_50EC[5];
u32 fzgx_obj_lbl_1_bss_5100;
u32 fzgx_obj_lbl_1_bss_5104[13];
u32 fzgx_obj_lbl_1_bss_5138[65];
u32 fzgx_obj_lbl_1_bss_523C[8];
u32 fzgx_obj_lbl_1_bss_525C[102];
u16 fzgx_obj_lbl_1_bss_53F4;
u32 fzgx_obj_lbl_1_bss_53F8[34];
u32 fzgx_obj_lbl_1_bss_5480[33216];
u16 fzgx_obj_lbl_1_bss_25B80;
u32 fzgx_obj_lbl_1_bss_25B84;
u32 fzgx_obj_lbl_1_bss_25B88[4];
u16 fzgx_obj_lbl_1_bss_25B98;
u32 fzgx_obj_lbl_1_bss_25B9C;
u32 fzgx_obj_lbl_1_bss_25BA0[42];
u32 fzgx_obj_lbl_1_bss_25C48[23];
u32 fzgx_obj_lbl_1_bss_25CA4[11];
u32 fzgx_obj_lbl_1_bss_25CD0[105];
u32 fzgx_obj_lbl_1_bss_25E74[7];
u32 fzgx_obj_lbl_1_bss_25E90[2];
u8 fzgx_obj_lbl_1_bss_25E98;
u32 fzgx_obj_lbl_1_bss_25E9C[240];
u32 fzgx_obj_lbl_1_bss_2625C[8];
u32 fzgx_obj_lbl_1_bss_2627C[30];
u8 fzgx_obj_lbl_1_bss_262F4;
u32 fzgx_obj_lbl_1_bss_262F8[2];
u16 fzgx_obj_lbl_1_bss_26300;
u32 fzgx_obj_lbl_1_bss_26304[4];
u32 fzgx_obj_lbl_1_bss_26314[508];
u32 fzgx_obj_lbl_1_bss_26B04[5];
u8 fzgx_obj_lbl_1_bss_26B18;
u8 fzgx_obj_lbl_1_bss_26B19;
u8 fzgx_obj_lbl_1_bss_26B1A;
u8 fzgx_pool_fzgx_pad_26B1B;
u8 fzgx_pool_fzgx_pad_26B1C;
u8 fzgx_obj_lbl_1_bss_26B1D;
u8 fzgx_obj_lbl_1_bss_26B1E;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b42;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b43;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b44;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b45;
u32 fzgx_obj_lbl_1_bss_26B4C;
u32 fzgx_obj_lbl_1_bss_26B50;
u32 fzgx_obj_lbl_1_bss_26B54[2];
u8 fzgx_obj_lbl_1_bss_26B5C[30];
u8 fzgx_obj_lbl_1_bss_26B7A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
u8 fzgx_obj_lbl_1_bss_26B80[150];
s8 lbl_1_bss_26B80__fzgx_offset_96;
u8 lbl_1_bss_26B80__fzgx_offset_97;
u8 fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b1;
u8 fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b2;
u8 fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b3;
u8 fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b4;
u8 fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b5;
u8 fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b6;
u8 fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b7;
u8 fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b8;
u8 fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b9;
u8 fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b10;
u8 fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b11;
u8 fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b12;
u8 fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b13;
u8 fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b14;
u8 fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b15;
u8 fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b16;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_3C00;
    s = fzgx_obj_lbl_1_bss_3C04;
    s = fzgx_obj_lbl_1_bss_3C08[0];
    s = fzgx_obj_lbl_1_bss_3C10;
    s = fzgx_obj_lbl_1_bss_3C11;
    s = fzgx_obj_lbl_1_bss_3C12;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b5;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b7;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b8;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b9;
    s = fzgx_obj_lbl_1_bss_3C1C[0];
    s = fzgx_obj_lbl_1_bss_3C2A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b5;
    s = fzgx_obj_lbl_1_bss_3C30[0];
    s = fzgx_obj_lbl_1_bss_50EC[0];
    s = fzgx_obj_lbl_1_bss_5100;
    s = fzgx_obj_lbl_1_bss_5104[0];
    s = fzgx_obj_lbl_1_bss_5138[0];
    s = fzgx_obj_lbl_1_bss_523C[0];
    s = fzgx_obj_lbl_1_bss_525C[0];
    s = fzgx_obj_lbl_1_bss_53F4;
    s = fzgx_obj_lbl_1_bss_53F8[0];
    s = fzgx_obj_lbl_1_bss_5480[0];
    s = fzgx_obj_lbl_1_bss_25B80;
    s = fzgx_obj_lbl_1_bss_25B84;
    s = fzgx_obj_lbl_1_bss_25B88[0];
    s = fzgx_obj_lbl_1_bss_25B98;
    s = fzgx_obj_lbl_1_bss_25B9C;
    s = fzgx_obj_lbl_1_bss_25BA0[0];
    s = fzgx_obj_lbl_1_bss_25C48[0];
    s = fzgx_obj_lbl_1_bss_25CA4[0];
    s = fzgx_obj_lbl_1_bss_25CD0[0];
    s = fzgx_obj_lbl_1_bss_25E74[0];
    s = fzgx_obj_lbl_1_bss_25E90[0];
    s = fzgx_obj_lbl_1_bss_25E98;
    s = fzgx_obj_lbl_1_bss_25E9C[0];
    s = fzgx_obj_lbl_1_bss_2625C[0];
    s = fzgx_obj_lbl_1_bss_2627C[0];
    s = fzgx_obj_lbl_1_bss_262F4;
    s = fzgx_obj_lbl_1_bss_262F8[0];
    s = fzgx_obj_lbl_1_bss_26300;
    s = fzgx_obj_lbl_1_bss_26304[0];
    s = fzgx_obj_lbl_1_bss_26314[0];
    s = fzgx_obj_lbl_1_bss_26B04[0];
    s = fzgx_obj_lbl_1_bss_26B18;
    s = fzgx_obj_lbl_1_bss_26B19;
    s = fzgx_obj_lbl_1_bss_26B1A;
    s = fzgx_pool_fzgx_pad_26B1B;
    s = fzgx_pool_fzgx_pad_26B1C;
    s = fzgx_obj_lbl_1_bss_26B1D;
    s = fzgx_obj_lbl_1_bss_26B1E;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b42;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b43;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b44;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b45;
    s = fzgx_obj_lbl_1_bss_26B4C;
    s = fzgx_obj_lbl_1_bss_26B50;
    s = fzgx_obj_lbl_1_bss_26B54[0];
    s = fzgx_obj_lbl_1_bss_26B5C[0];
    s = fzgx_obj_lbl_1_bss_26B7A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
    s = fzgx_obj_lbl_1_bss_26B80[0];
    s = lbl_1_bss_26B80__fzgx_offset_96;
    s = lbl_1_bss_26B80__fzgx_offset_97;
    s = fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b1;
    s = fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b2;
    s = fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b3;
    s = fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b4;
    s = fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b5;
    s = fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b6;
    s = fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b7;
    s = fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b8;
    s = fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b9;
    s = fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b10;
    s = fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b11;
    s = fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b12;
    s = fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b13;
    s = fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b14;
    s = fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b15;
    s = fzgx_pool_lbl_1_bss_26B80__fzgx_offset_97__b16;
}
#pragma section code_type ".text"

extern void fn_1_3F75C(void);
extern void fn_1_981C4(void);
extern void fn_1_98230(void *);
extern void fn_1_9835C(void *);
extern u32 fn_1_12AF50(u32);
extern u32 fn_1_82724(void *, void *, void *, u32, u32);
extern u32 fn_1_12AF64(void);
extern void fn_1_32A40(void *);
extern void fn_1_835E0(void *, void *, void *);
extern void fn_1_331EC(void);
extern void fn_1_8176C(void *);
extern void fn_1_14A00C(void);
extern void fn_1_14A028(void *);
extern void fn_1_15C36C(void *);
extern u32 fn_1_8DBB0(void);
extern void fn_1_8DD54(void *);
extern u32 fn_80008E84(u32);
extern volatile u32 lbl_801A6410;  /* fzgx-allow: S2 retail reads the counter without using it */

#pragma opt_propagation off
static inline u32 st_1_39420_flag(St_30 *s) { return s->unk_5; }
static inline u32 fn_1_39420_call_fn_1_82724(u32 a4, u32 a3, void *a2, void *a1, void *a0) { return fn_1_82724(a0, a1, a2, a3, a4); }
void fn_1_39420(void)
{
    u8 *tab = (u8 *)&lbl_1_data_5730;
    St_30 *stm;
    u32 obj;
    void *lab_t0;
    void *lab_t0_2;
    u32 lab_t0_;
    void * lab_t0__;

    fn_1_A8F78();
    fn_1_435C(fzgx_obj_lbl_1_bss_25B88[0]);
    fn_1_4310(0);
    fn_1_5370(0, 0);
    fn_1_3F75C();

    if (st_1_39420_flag((St_30 *)fzgx_obj_lbl_1_bss_3C30) != 1) {
        lab_t0_ = fzgx_obj_lbl_1_bss_262F8[0];
        obj = fn_80008E84(lab_t0_);
        fn_1_981C4();
        (void)lbl_801A6410;
        fn_1_435C(fzgx_obj_lbl_1_bss_25B88[0]);
        lab_t0 = tab + 0xd1c;
        lab_t0__ = lab_t0;
        fn_1_3F8C(lab_t0__, fn_1_98230, 0, 10);
        fn_1_435C(fzgx_obj_lbl_1_bss_25CA4[0]);
        lab_t0_2 = tab + 0xd24;
        lab_t0__ = lab_t0_2;
        fn_1_3F8C(lab_t0__, fn_1_9835C, 0, 21);
        fn_1_12AF50(obj);
        stm = (St_30 *)fzgx_obj_lbl_1_bss_3C30;
        fn_1_39420_call_fn_1_82724(1, stm->unk_9, fzgx_obj_lbl_1_bss_25E9C, (void *)fzgx_obj_lbl_1_bss_25CA4[0], (void *)fzgx_obj_lbl_1_bss_25B88[0]);
        fn_1_12AF64();
        fn_1_835E0(fzgx_obj_lbl_1_bss_3C30, (void *)fzgx_obj_lbl_1_bss_25B88[0], fn_1_32A40);
        fn_1_8176C(fn_1_331EC);
        lab_t0_ = obj;
        obj = fn_80008E84(lab_t0_);
        fn_1_14A00C();
        fn_1_435C(fzgx_obj_lbl_1_bss_25B88[0]);
        lab_t0_2 = tab + 0xd30;
        lab_t0__ = lab_t0_2;
        fn_1_3F8C(lab_t0__, fn_1_14A028, (Obj_1_bss_5138 *)fzgx_obj_lbl_1_bss_3C30, 25);
        fn_1_435C(fzgx_obj_lbl_1_bss_25CA4[0]);
        lab_t0_2 = tab + 0xd40;
        lab_t0__ = lab_t0_2;
        fn_1_3F8C(lab_t0__, fn_1_15C36C, (Obj_1_bss_5138 *)fzgx_obj_lbl_1_bss_3C30, 28);
        fn_1_435C(fzgx_obj_lbl_1_bss_25CA4[0]);
        fn_1_8DBB0();
        lab_t0_2 = tab + 0xd50;
        lab_t0__ = lab_t0_2;
        fn_1_3F8C(lab_t0__, fn_1_8DD54, 0, 1);
        lbl_1_bss_26B80__fzgx_offset_96 = 1;
    }

    fn_1_435C(fzgx_obj_lbl_1_bss_25CA4[0]);
    fn_1_4310(0);
}
#pragma opt_propagation reset
/* fzgx:end fn_1_39420 */

/* fzgx:begin fn_1_3A044 noprologue */
#include "types.h"

typedef struct GameEntryC {
    u8 data[0xA0];
} GameEntryC;

typedef struct GameStateC {
    u32 flags;
    u8 pad_4[5];
    u8 unk_9;
    u8 pad_A[0x9D];
    u8 unk_A7;
    u8 pad_A8[0x2C];
    GameEntryC entries[31];
    u8 pad_1434[0x30];
    u32 unk_1464;
    u8 pad_1468[0x4];
    u8 unk_146C;
    u8 unk_146D;
    s16 unk_146E;
    u8 unk_1470;
    u8 pad_1471[0x47];
} GameStateC;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 fzgx_obj_lbl_1_bss_3C08[2];
u8 fzgx_obj_lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u16 fzgx_obj_lbl_1_bss_3C12;
u32 lbl_1_bss_3C12__fzgx_offset_2;
u32 lbl_1_bss_3C12__fzgx_offset_6;
u32 fzgx_obj_lbl_1_bss_3C1C;
u8 lbl_1_bss_3C1C__fzgx_offset_4[10];
u8 fzgx_obj_lbl_1_bss_3C2A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b5;
GameStateC fzgx_obj_lbl_1_bss_3C30;
s16 lbl_1_bss_3C30__fzgx_offset_14B8;
u32 fzgx_obj_lbl_1_bss_50EC[5];
u32 fzgx_obj_lbl_1_bss_5100;
u32 fzgx_obj_lbl_1_bss_5104[13];
u32 fzgx_obj_lbl_1_bss_5138[65];
u32 fzgx_obj_lbl_1_bss_523C[8];
u32 fzgx_obj_lbl_1_bss_525C[102];
u16 fzgx_obj_lbl_1_bss_53F4;
u32 fzgx_obj_lbl_1_bss_53F8[34];
u32 fzgx_obj_lbl_1_bss_5480[33216];
u16 fzgx_obj_lbl_1_bss_25B80;
u32 fzgx_obj_lbl_1_bss_25B84;
u32 fzgx_obj_lbl_1_bss_25B88[4];
u16 fzgx_obj_lbl_1_bss_25B98;
u32 fzgx_obj_lbl_1_bss_25B9C;
u32 fzgx_obj_lbl_1_bss_25BA0[2];
u8 lbl_1_bss_25BA0__fzgx_offset_8[0x20];
u8 lbl_1_bss_25BA0__fzgx_offset_28[0x20];
u32 lbl_1_bss_25BA0__fzgx_offset_48[24];
u32 fzgx_obj_lbl_1_bss_25C48[23];
u32 fzgx_obj_lbl_1_bss_25CA4;
u32 lbl_1_bss_25CA4__fzgx_offset_4;
u32 lbl_1_bss_25CA4__fzgx_offset_8;
u32 lbl_1_bss_25CA4__fzgx_offset_C;
u32 lbl_1_bss_25CA4__fzgx_offset_10;
u32 lbl_1_bss_25CA4__fzgx_offset_14;
u32 lbl_1_bss_25CA4__fzgx_offset_18;
u32 lbl_1_bss_25CA4__fzgx_offset_1C;
u32 lbl_1_bss_25CA4__fzgx_offset_20;
u32 lbl_1_bss_25CA4__fzgx_offset_24;
u32 lbl_1_bss_25CA4__fzgx_offset_28;
u32 fzgx_obj_lbl_1_bss_25CD0[97];
u32 lbl_1_bss_25CD0__fzgx_offset_184;
u32 lbl_1_bss_25CD0__fzgx_offset_188;
u32 lbl_1_bss_25CD0__fzgx_offset_18C;
u32 lbl_1_bss_25CD0__fzgx_offset_190;
u32 lbl_1_bss_25CD0__fzgx_offset_194;
u32 lbl_1_bss_25CD0__fzgx_offset_198;
s32 lbl_1_bss_25CD0__fzgx_offset_19C;
s32 lbl_1_bss_25CD0__fzgx_offset_1A0;
u32 fzgx_obj_lbl_1_bss_25E74[2];
s32 lbl_1_bss_25E74__fzgx_offset_8;
s32 lbl_1_bss_25E74__fzgx_offset_C;
s32 lbl_1_bss_25E74__fzgx_offset_10;
u32 lbl_1_bss_25E74__fzgx_offset_14;
u32 lbl_1_bss_25E74__fzgx_offset_18;
u32 fzgx_obj_lbl_1_bss_25E90[2];
u8 fzgx_obj_lbl_1_bss_25E98[1];
u32 fzgx_obj_lbl_1_bss_25E9C[240];
u32 fzgx_obj_lbl_1_bss_2625C[8];
u32 fzgx_obj_lbl_1_bss_2627C[30];
u8 fzgx_obj_lbl_1_bss_262F4;
u32 fzgx_obj_lbl_1_bss_262F8[2];
u16 fzgx_obj_lbl_1_bss_26300;
u32 fzgx_obj_lbl_1_bss_26304[4];
u32 fzgx_obj_lbl_1_bss_26314[508];
u32 fzgx_obj_lbl_1_bss_26B04[5];
u8 fzgx_obj_lbl_1_bss_26B18;
u8 fzgx_obj_lbl_1_bss_26B19;
u8 fzgx_obj_lbl_1_bss_26B1A;
u8 fzgx_pool_fzgx_pad_26B1B;
u8 fzgx_pool_fzgx_pad_26B1C;
u8 fzgx_obj_lbl_1_bss_26B1D;
u8 fzgx_obj_lbl_1_bss_26B1E;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b42;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b43;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b44;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b45;
u32 fzgx_obj_lbl_1_bss_26B4C;
u32 fzgx_obj_lbl_1_bss_26B50;
u32 fzgx_obj_lbl_1_bss_26B54[2];
u8 fzgx_obj_lbl_1_bss_26B5C[30];
u8 fzgx_obj_lbl_1_bss_26B7A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
u32 fzgx_obj_lbl_1_bss_26B80[42];
u32 fzgx_obj_lbl_1_bss_26C28;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_3C00;
    s = fzgx_obj_lbl_1_bss_3C04;
    s = fzgx_obj_lbl_1_bss_3C08[0];
    s = fzgx_obj_lbl_1_bss_3C10;
    s = fzgx_obj_lbl_1_bss_3C11;
    s = fzgx_obj_lbl_1_bss_3C12;
    s = lbl_1_bss_3C12__fzgx_offset_2;
    s = lbl_1_bss_3C12__fzgx_offset_6;
    s = fzgx_obj_lbl_1_bss_3C1C;
    s = lbl_1_bss_3C1C__fzgx_offset_4[0];
    s = fzgx_obj_lbl_1_bss_3C2A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b5;
    s = *(u32 *)&fzgx_obj_lbl_1_bss_3C30;
    s = lbl_1_bss_3C30__fzgx_offset_14B8;
    s = fzgx_obj_lbl_1_bss_50EC[0];
    s = fzgx_obj_lbl_1_bss_5100;
    s = fzgx_obj_lbl_1_bss_5104[0];
    s = fzgx_obj_lbl_1_bss_5138[0];
    s = fzgx_obj_lbl_1_bss_523C[0];
    s = fzgx_obj_lbl_1_bss_525C[0];
    s = fzgx_obj_lbl_1_bss_53F4;
    s = fzgx_obj_lbl_1_bss_53F8[0];
    s = fzgx_obj_lbl_1_bss_5480[0];
    s = fzgx_obj_lbl_1_bss_25B80;
    s = fzgx_obj_lbl_1_bss_25B84;
    s = fzgx_obj_lbl_1_bss_25B88[0];
    s = fzgx_obj_lbl_1_bss_25B98;
    s = fzgx_obj_lbl_1_bss_25B9C;
    s = fzgx_obj_lbl_1_bss_25BA0[0];
    s = lbl_1_bss_25BA0__fzgx_offset_8[0];
    s = lbl_1_bss_25BA0__fzgx_offset_28[0];
    s = lbl_1_bss_25BA0__fzgx_offset_48[0];
    s = fzgx_obj_lbl_1_bss_25C48[0];
    s = fzgx_obj_lbl_1_bss_25CA4;
    s = lbl_1_bss_25CA4__fzgx_offset_4;
    s = lbl_1_bss_25CA4__fzgx_offset_8;
    s = lbl_1_bss_25CA4__fzgx_offset_C;
    s = lbl_1_bss_25CA4__fzgx_offset_10;
    s = lbl_1_bss_25CA4__fzgx_offset_14;
    s = lbl_1_bss_25CA4__fzgx_offset_18;
    s = lbl_1_bss_25CA4__fzgx_offset_1C;
    s = lbl_1_bss_25CA4__fzgx_offset_20;
    s = lbl_1_bss_25CA4__fzgx_offset_24;
    s = lbl_1_bss_25CA4__fzgx_offset_28;
    s = fzgx_obj_lbl_1_bss_25CD0[0];
    s = lbl_1_bss_25CD0__fzgx_offset_184;
    s = lbl_1_bss_25CD0__fzgx_offset_188;
    s = lbl_1_bss_25CD0__fzgx_offset_18C;
    s = lbl_1_bss_25CD0__fzgx_offset_190;
    s = lbl_1_bss_25CD0__fzgx_offset_194;
    s = lbl_1_bss_25CD0__fzgx_offset_198;
    s = lbl_1_bss_25CD0__fzgx_offset_19C;
    s = lbl_1_bss_25CD0__fzgx_offset_1A0;
    s = fzgx_obj_lbl_1_bss_25E74[0];
    s = lbl_1_bss_25E74__fzgx_offset_8;
    s = lbl_1_bss_25E74__fzgx_offset_C;
    s = lbl_1_bss_25E74__fzgx_offset_10;
    s = lbl_1_bss_25E74__fzgx_offset_14;
    s = lbl_1_bss_25E74__fzgx_offset_18;
    s = fzgx_obj_lbl_1_bss_25E90[0];
    s = fzgx_obj_lbl_1_bss_25E98[0];
    s = fzgx_obj_lbl_1_bss_25E9C[0];
    s = fzgx_obj_lbl_1_bss_2625C[0];
    s = fzgx_obj_lbl_1_bss_2627C[0];
    s = fzgx_obj_lbl_1_bss_262F4;
    s = fzgx_obj_lbl_1_bss_262F8[0];
    s = fzgx_obj_lbl_1_bss_26300;
    s = fzgx_obj_lbl_1_bss_26304[0];
    s = fzgx_obj_lbl_1_bss_26314[0];
    s = fzgx_obj_lbl_1_bss_26B04[0];
    s = fzgx_obj_lbl_1_bss_26B18;
    s = fzgx_obj_lbl_1_bss_26B19;
    s = fzgx_obj_lbl_1_bss_26B1A;
    s = fzgx_pool_fzgx_pad_26B1B;
    s = fzgx_pool_fzgx_pad_26B1C;
    s = fzgx_obj_lbl_1_bss_26B1D;
    s = fzgx_obj_lbl_1_bss_26B1E;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b42;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b43;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b44;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b45;
    s = fzgx_obj_lbl_1_bss_26B4C;
    s = fzgx_obj_lbl_1_bss_26B50;
    s = fzgx_obj_lbl_1_bss_26B54[0];
    s = fzgx_obj_lbl_1_bss_26B5C[0];
    s = fzgx_obj_lbl_1_bss_26B7A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
    s = fzgx_obj_lbl_1_bss_26B80[0];
    s = fzgx_obj_lbl_1_bss_26C28;
}
#pragma section code_type ".text"

extern u32 fn_1_435C(u32);
extern void fn_1_426C(u32);
extern void fn_1_105724(void);
extern void fn_1_F2EDC(void);
extern void fn_1_A8F78(void);
extern s32 fn_1_1547FC(void *);
extern void fn_1_C47B4(void);
extern void fn_1_C6F80(u8);
extern void fn_1_79100(void);
extern void fn_1_412A0(u32);
extern void fn_1_E35F0(void);
extern u32 fn_80008E84(u32);
typedef struct { s32 unk_0; } Obj_1_bss_381F8;
extern Obj_1_bss_381F8 lbl_1_bss_381F8;

static inline void game_copy_names(void) {
    s32 i;
    for (i = 0; i < fzgx_obj_lbl_1_bss_3C30.unk_9; i++) {
        u8 *d = fzgx_obj_lbl_1_bss_3C30.entries[i].data;
        d[fzgx_obj_lbl_1_bss_3C30.unk_A7 + 0xE] = lbl_1_bss_25BA0__fzgx_offset_8[i];
        d[fzgx_obj_lbl_1_bss_3C30.unk_A7 + 0x13] = lbl_1_bss_25BA0__fzgx_offset_28[i];
    }
}

void fn_1_3A044(void) {
    u32 v;

    if (lbl_1_bss_381F8.unk_0 != -1) {
        fn_1_435C(fzgx_obj_lbl_1_bss_25CA4);
        fn_1_426C(lbl_1_bss_381F8.unk_0);
    }
    fn_1_A8F78();
    if (lbl_1_bss_25CD0__fzgx_offset_19C != 0) {
        lbl_1_bss_25CD0__fzgx_offset_1A0 = 1;
    }
    if (lbl_1_bss_25CD0__fzgx_offset_1A0 != 0) {
        game_copy_names();
        fzgx_obj_lbl_1_bss_3C30.unk_1464 = 0;
        fzgx_obj_lbl_1_bss_3C30.unk_146C = 0;
        fzgx_obj_lbl_1_bss_3C30.unk_146D = 0;
        fzgx_obj_lbl_1_bss_3C30.unk_1470 = 0;
        fzgx_obj_lbl_1_bss_3C30.unk_146E = 0x5DC;
        fn_1_1547FC(&fzgx_obj_lbl_1_bss_3C30);
        fn_1_C47B4();
        fn_1_435C(fzgx_obj_lbl_1_bss_25B88[0]);
        if (lbl_1_bss_3C12__fzgx_offset_2 != 0) {
            fn_1_426C(lbl_1_bss_3C12__fzgx_offset_2);
            lbl_1_bss_3C12__fzgx_offset_2 = 0;
        }
        fn_1_435C(fzgx_obj_lbl_1_bss_25CA4);
        if (lbl_1_bss_3C12__fzgx_offset_6 != 0) {
            fn_1_426C(lbl_1_bss_3C12__fzgx_offset_6);
            lbl_1_bss_3C12__fzgx_offset_6 = 0;
        }
        fn_1_C6F80(0);
        v = fn_80008E84(lbl_1_bss_25CA4__fzgx_offset_28);
        fn_1_79100();
        fn_80008E84(v);
        fn_1_412A0(2);
        fn_1_E35F0();
        fn_1_435C(fzgx_obj_lbl_1_bss_25B88[0]);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_10);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_14);
        fn_1_426C(lbl_1_bss_25CD0__fzgx_offset_194);
        fn_1_435C(fzgx_obj_lbl_1_bss_25CA4);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_4);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_8);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_C);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_18);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_1C);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_20);
        fn_1_426C(lbl_1_bss_25CD0__fzgx_offset_188);
        fn_1_426C(lbl_1_bss_25CD0__fzgx_offset_18C);
        fn_1_426C(lbl_1_bss_25CD0__fzgx_offset_190);
        fn_1_426C(lbl_1_bss_25CD0__fzgx_offset_184);
    }
    if (lbl_1_bss_25CD0__fzgx_offset_19C != 0) {
        fzgx_obj_lbl_1_bss_3C30.unk_A7++;
    }
    if (lbl_1_bss_3C30__fzgx_offset_14B8 != 0x29) {
        fn_1_435C(fzgx_obj_lbl_1_bss_25B88[0]);
        if (lbl_1_bss_25E74__fzgx_offset_8 != -1) {
            fn_1_426C(lbl_1_bss_25E74__fzgx_offset_8);
        }
        if (lbl_1_bss_25E74__fzgx_offset_C != -1) {
            fn_1_426C(lbl_1_bss_25E74__fzgx_offset_C);
            fn_1_105724();
        }
        fn_1_435C(fzgx_obj_lbl_1_bss_25CA4);
        if (lbl_1_bss_25E74__fzgx_offset_10 != -1) {
            fn_1_426C(lbl_1_bss_25E74__fzgx_offset_10);
        }
        lbl_1_bss_25E74__fzgx_offset_8 = -1;
        lbl_1_bss_25E74__fzgx_offset_C = -1;
        lbl_1_bss_25E74__fzgx_offset_10 = -1;
        if (fzgx_obj_lbl_1_bss_3C30.flags & 0x800000) {
            fn_1_F2EDC();
        }
    }
}
/* fzgx:end fn_1_3A044 */

/* fzgx:begin fn_1_3A2C4 */
void fn_1_3A2C4(void) {
    s64 time;
    u32 lo, hi;

    fn_1_817C0();
    lbl_1_bss_381FC = 0;
    fn_1_EB080(1);
    time = OSGetTime();
    lo = (u32)time;
    hi = (u32)(time >> 32);
    lbl_1_bss_3C30.unk_14A4 = lo;
    lbl_1_bss_3C30.unk_14A0 = hi;
    lbl_1_bss_3C30.unk_1494 = lo;
    lbl_1_bss_3C30.unk_1490 = hi;
    lbl_1_bss_3C30.unk_149C = 0;
    lbl_1_bss_3C30.unk_1498 = 0;
    lbl_1_bss_38200 = 0xff;
}
/* fzgx:end fn_1_3A2C4 */

/* fzgx:begin fn_1_3AEC4 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"

typedef struct Sig_ADXT_Pause_AdxSjdHandle Sig_ADXT_Pause_AdxSjdHandle;

typedef struct Sig_ADXT_Pause_ADXStream Sig_ADXT_Pause_ADXStream;

typedef struct Sig_ADXT_Pause_AXRNAHandle Sig_ADXT_Pause_AXRNAHandle;

typedef struct Sig_ADXT_Pause_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Pause_SJCK;

typedef void (*Sig_ADXT_Pause_SJErrorCallback)(void *object, int error);

typedef struct Sig_ADXT_Pause_SJInterface Sig_ADXT_Pause_SJInterface;

typedef struct Sig_ADXT_Pause_SJ Sig_ADXT_Pause_SJ;

struct Sig_ADXT_Pause_SJ {
    const Sig_ADXT_Pause_SJInterface *interface;
};

struct Sig_ADXT_Pause_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Pause_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Pause_SJ *sj);
    void (*reset)(Sig_ADXT_Pause_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, int max_size, Sig_ADXT_Pause_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, Sig_ADXT_Pause_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, Sig_ADXT_Pause_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Pause_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Pause_SJ *sj, Sig_ADXT_Pause_SJErrorCallback callback, void *object);
};

typedef struct Sig_ADXT_Pause_ADX_AMP Sig_ADXT_Pause_ADX_AMP;

typedef struct Sig_ADXT_Pause_LSCObject Sig_ADXT_Pause_LSCObject;

typedef struct Sig_ADXT_Pause_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Pause_AdxSjdHandle *decoder;
    Sig_ADXT_Pause_ADXStream *stream;
    Sig_ADXT_Pause_AXRNAHandle *rna;
    Sig_ADXT_Pause_SJ *stream_sj;
    Sig_ADXT_Pause_SJ *input_sj;
    Sig_ADXT_Pause_SJ *output_sj[2];
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
    Sig_ADXT_Pause_ADX_AMP *amplifier;
    Sig_ADXT_Pause_SJ *amplifier_input[2];
    Sig_ADXT_Pause_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Pause_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Pause_ADXTHandle;

typedef struct Sig_ADXT_Stop_AdxSjdHandle Sig_ADXT_Stop_AdxSjdHandle;

typedef struct Sig_ADXT_Stop_ADXStream Sig_ADXT_Stop_ADXStream;

typedef struct Sig_ADXT_Stop_AXRNAHandle Sig_ADXT_Stop_AXRNAHandle;

typedef struct Sig_ADXT_Stop_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK;

typedef void (*Sig_ADXT_Stop_SJErrorCallback)(void *object, int error);

typedef struct Sig_ADXT_Stop_SJInterface Sig_ADXT_Stop_SJInterface;

typedef struct Sig_ADXT_Stop_SJ Sig_ADXT_Stop_SJ;

struct Sig_ADXT_Stop_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ *sj);
    void (*reset)(Sig_ADXT_Stop_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};

struct Sig_ADXT_Stop_SJ {
    const Sig_ADXT_Stop_SJInterface *interface;
};

typedef struct Sig_ADXT_Stop_ADX_AMP Sig_ADXT_Stop_ADX_AMP;

typedef struct Sig_ADXT_Stop_LSCObject Sig_ADXT_Stop_LSCObject;

typedef struct Sig_ADXT_Stop_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Stop_AdxSjdHandle *decoder;
    Sig_ADXT_Stop_ADXStream *stream;
    Sig_ADXT_Stop_AXRNAHandle *rna;
    Sig_ADXT_Stop_SJ *stream_sj;
    Sig_ADXT_Stop_SJ *input_sj;
    Sig_ADXT_Stop_SJ *output_sj[2];
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
    Sig_ADXT_Stop_ADX_AMP *amplifier;
    Sig_ADXT_Stop_SJ *amplifier_input[2];
    Sig_ADXT_Stop_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Stop_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Stop_ADXTHandle;

typedef struct {
    u8 unk[0xb];
    u8 value;
} Entry;

typedef struct {
    u8 pad_0[2];
    s16 unk_2;
    u8 pad_4[8];
    u32 unk_C;
    u8 pad_10[0x10];
} Obj_1_bss_25E9C;

typedef struct {
    u8 pad[0x2f8];
    u32 value_2f8;
    u32 value_2fc;
    u32 value_300;
    u32 value_304;
    u32 value_308;
    u32 value_30c;
    u32 value_310;
    u32 value_314;
    u32 value_318;
    u32 value_31c;
} Fn40710Config;
extern void fn_1_15E330(s32 index, u32 value, void *arg);
extern void fn_1_15E5E4(s32 index, void *arg);
extern void fn_1_15E688(s32 index, u32 value, u8 state, void *arg);
extern void fn_1_15E3E0(s32 index, u32 value);
extern void fn_1_15E434(u32 value);
extern void fn_1_15E540(s32 index, void *arg);
extern void fn_1_CB404(u8 value);
extern void fn_1_D07C4(u32 arg0, u32 arg1);
extern u32 lbl_1_bss_25B84;
extern u32 OSGetTick(void);
extern void fn_1_A0978(void);
extern void fn_1_35174(void);
extern s32 fn_1_3EFA8(void);
extern u16 lbl_1_bss_26B7A[3];
extern u16 lbl_1_bss_26300;
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern u32 fn_1_101C0(void);
extern u32 fn_1_A11EC(void);
extern u32 fn_1_435C(u32 value);
extern void ADXT_Pause(Sig_ADXT_Pause_ADXTHandle *, s32);
extern void fn_1_4310(u32 arg0);
extern void fn_1_48004(s32 index, s32 image);
extern void fn_1_8616C(void);
extern void fn_1_A1588(u32 arg0, u32 arg1);
extern void fn_1_D0790(void);
extern void fn_1_817C0(void);
extern u32 lbl_1_bss_381FC;
extern void fn_1_EB080(int mode);
extern s64 OSGetTime(void);
extern void fn_1_4A00(u32 arg0, u32 arg1, u32 arg2);
extern void fn_1_5370(u32 arg0, u32 arg1);
extern void fn_1_15E27C(void);
extern void fn_1_4811C(int arg);
extern void fn_1_A8F78(void);
extern u8 lbl_1_bss_262F4;
extern u32 lbl_1_bss_25E74[7];
extern u8 lbl_1_bss_3C10;
extern void fn_1_36330(void);
extern void fn_1_36B10(void);
extern void fn_1_3C98(void);
extern void fn_1_37AA8(void);
extern void fn_1_37E98(void);
extern f32 lbl_1_bss_26304[4];
extern u8 lbl_1_bss_26B04[20];
extern u8 lbl_1_bss_26314[2032];
extern s16 fn_1_12EF24(s16 row, s16 column);
extern u8 lbl_1_bss_523C[32];
extern Entry *lbl_1_bss_53F8[34];
extern void OSPanic(const void *, u32, const char *, ...);
extern Obj_1_bss_25E9C lbl_1_bss_25E9C[30];
extern void fn_1_12AB38(void *arg0);
extern void fn_1_465D0(char *value, u32 flag);
extern void* fn_1_7F518(s16 car_type, void* car, s32 initialize);
extern int sprintf(char *s, const char *format, ...);
extern void fn_1_451E4(void);
extern void fn_1_D3214(void);
extern void VIWaitForRetrace(void);
extern u32 fn_1_467F4(void);
extern u32 fn_1_13018(void);
extern u32 fn_1_46C60(void);
extern u32 lbl_1_bss_26C2C[2];
extern u32 lbl_1_bss_262F8[2];
extern u16 lbl_1_bss_26C68[35526];
extern u32 lbl_1_bss_3C08[2];
extern u32 fn_800075AC(u32, u32, u32);
extern u32 ghost_test_record_flag0(s32 arg);
extern u32 fn_1_F9D44(u32 arg);
extern u8 fn_1_F8C50(s32 arg0);
extern void fn_1_2DB50(void);
extern void fn_1_3F8C(void *, void *, Obj_1_bss_5138 *, int);
extern void fn_1_2D888(void);
extern void fn_1_2D524(void);
extern u32 fn_1_FA070(void);
extern int fn_1_FA180(int, u8);
extern u32 fn_1_F9FEC(void);
extern void fn_1_A2DC4(u32 arg0);
extern Fn40710Config lbl_1_rodata_BD8;
extern u8 lbl_1_bss_26B54[8];
extern u32 fn_1_40EE4(void);
extern u32 lbl_801A63D0;
extern u32 lbl_1_bss_26C34[9];
extern u8 lbl_1_bss_38218[568];
extern u32 fn_1_4060(void);
extern void ARQPostRequest(u8 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, u32 arg7);
extern u32 lbl_801A63C0;
extern void fn_1_40BE4(void);
extern u32 GXGetTexBufferSize(u32, u32, u32, u32, u32);
extern u32 lbl_1_bss_26B4C;
extern u8 lbl_1_bss_25E90[8];
extern s32 fn_1_48B0(u32 arg0, u32 arg1);
extern void fn_1_40F54(void *arg0);
extern u32 lbl_801A6CE0;
extern u32 lbl_1_bss_38454;
extern u32 fn_80070DE0(u32 arg0);
extern void fn_1_D3884();
extern void fn_1_D358C();
extern void fn_800711A8(Obj_1_bss_38458_Target *target);
extern void fn_80071718(u32 value);
extern void fn_1_41134(void *unused, char *value);
extern void fn_1_411D4(u32, char *);
extern int DVDConvertPathToEntrynum(char *buffer);
extern void fn_1_412A0(u32 index);
extern size_t strlen(const char *str);
extern int fn_80083BCC(const char *s1, const char *s2);
extern u8 lbl_1_A9011300;
extern u8 lbl_1_A9011100;
extern u8 lbl_1_A9011000;

typedef struct GameEntryC {
    u8 data[0xA0];
} GameEntryC;

typedef struct GameStateC {
    u32 flags;
    u8 pad_4[5];
    u8 unk_9;
    u8 pad_A[0x9D];
    u8 unk_A7;
    u8 pad_A8[0x2C];
    GameEntryC entries[31];
    u8 pad_1434[0x30];
    u32 unk_1464;
    u8 pad_1468[0x4];
    u8 unk_146C;
    u8 unk_146D;
    s16 unk_146E;
    u8 unk_1470;
    u8 pad_1471[0x47];
} GameStateC;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 fzgx_obj_lbl_1_bss_3C08[2];
u8 fzgx_obj_lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u16 fzgx_obj_lbl_1_bss_3C12;
u32 lbl_1_bss_3C12__fzgx_offset_2;
u32 lbl_1_bss_3C12__fzgx_offset_6;
u32 fzgx_obj_lbl_1_bss_3C1C;
u8 lbl_1_bss_3C1C__fzgx_offset_4[10];
u8 fzgx_obj_lbl_1_bss_3C2A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b5;
GameStateC fzgx_obj_lbl_1_bss_3C30;
s16 lbl_1_bss_3C30__fzgx_offset_14B8;
u32 fzgx_obj_lbl_1_bss_50EC[5];
u32 fzgx_obj_lbl_1_bss_5100;
u32 fzgx_obj_lbl_1_bss_5104[13];
u32 fzgx_obj_lbl_1_bss_5138[65];
u32 fzgx_obj_lbl_1_bss_523C[8];
u32 fzgx_obj_lbl_1_bss_525C[102];
u16 fzgx_obj_lbl_1_bss_53F4;
u32 fzgx_obj_lbl_1_bss_53F8[34];
u32 fzgx_obj_lbl_1_bss_5480[33216];
u16 fzgx_obj_lbl_1_bss_25B80;
u32 fzgx_obj_lbl_1_bss_25B84;
u32 fzgx_obj_lbl_1_bss_25B88[4];
u16 fzgx_obj_lbl_1_bss_25B98;
u32 fzgx_obj_lbl_1_bss_25B9C;
u32 fzgx_obj_lbl_1_bss_25BA0[2];
u8 lbl_1_bss_25BA0__fzgx_offset_8[0x20];
u8 lbl_1_bss_25BA0__fzgx_offset_28[0x20];
u32 lbl_1_bss_25BA0__fzgx_offset_48[24];
u32 fzgx_obj_lbl_1_bss_25C48[23];
u32 fzgx_obj_lbl_1_bss_25CA4;
u32 lbl_1_bss_25CA4__fzgx_offset_4;
u32 lbl_1_bss_25CA4__fzgx_offset_8;
u32 lbl_1_bss_25CA4__fzgx_offset_C;
u32 lbl_1_bss_25CA4__fzgx_offset_10;
u32 lbl_1_bss_25CA4__fzgx_offset_14;
u32 lbl_1_bss_25CA4__fzgx_offset_18;
u32 lbl_1_bss_25CA4__fzgx_offset_1C;
u32 lbl_1_bss_25CA4__fzgx_offset_20;
u32 lbl_1_bss_25CA4__fzgx_offset_24;
u32 lbl_1_bss_25CA4__fzgx_offset_28;
u32 fzgx_obj_lbl_1_bss_25CD0[97];
u32 lbl_1_bss_25CD0__fzgx_offset_184;
u32 lbl_1_bss_25CD0__fzgx_offset_188;
u32 lbl_1_bss_25CD0__fzgx_offset_18C;
u32 lbl_1_bss_25CD0__fzgx_offset_190;
u32 lbl_1_bss_25CD0__fzgx_offset_194;
u32 lbl_1_bss_25CD0__fzgx_offset_198;
s32 lbl_1_bss_25CD0__fzgx_offset_19C;
s32 lbl_1_bss_25CD0__fzgx_offset_1A0;
u32 fzgx_obj_lbl_1_bss_25E74[2];
s32 lbl_1_bss_25E74__fzgx_offset_8;
s32 lbl_1_bss_25E74__fzgx_offset_C;
s32 lbl_1_bss_25E74__fzgx_offset_10;
u32 lbl_1_bss_25E74__fzgx_offset_14;
u32 lbl_1_bss_25E74__fzgx_offset_18;
u32 fzgx_obj_lbl_1_bss_25E90[2];
u8 fzgx_obj_lbl_1_bss_25E98[1];
u32 fzgx_obj_lbl_1_bss_25E9C[240];
u32 fzgx_obj_lbl_1_bss_2625C[8];
u32 fzgx_obj_lbl_1_bss_2627C[30];
u8 fzgx_obj_lbl_1_bss_262F4;
u32 fzgx_obj_lbl_1_bss_262F8[2];
u16 fzgx_obj_lbl_1_bss_26300;
u32 fzgx_obj_lbl_1_bss_26304[4];
u32 fzgx_obj_lbl_1_bss_26314[508];
u32 fzgx_obj_lbl_1_bss_26B04[5];
u8 fzgx_obj_lbl_1_bss_26B18;
u8 fzgx_obj_lbl_1_bss_26B19;
u8 fzgx_obj_lbl_1_bss_26B1A;
u8 fzgx_pool_fzgx_pad_26B1B;
u8 fzgx_pool_fzgx_pad_26B1C;
u8 fzgx_obj_lbl_1_bss_26B1D;
u8 fzgx_obj_lbl_1_bss_26B1E;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b42;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b43;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b44;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b45;
u32 fzgx_obj_lbl_1_bss_26B4C;
u32 fzgx_obj_lbl_1_bss_26B50;
u32 fzgx_obj_lbl_1_bss_26B54[2];
u8 fzgx_obj_lbl_1_bss_26B5C[30];
u8 fzgx_obj_lbl_1_bss_26B7A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
u32 fzgx_obj_lbl_1_bss_26B80[42];
u32 fzgx_obj_lbl_1_bss_26C28;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_3C00;
    s = fzgx_obj_lbl_1_bss_3C04;
    s = fzgx_obj_lbl_1_bss_3C08[0];
    s = fzgx_obj_lbl_1_bss_3C10;
    s = fzgx_obj_lbl_1_bss_3C11;
    s = fzgx_obj_lbl_1_bss_3C12;
    s = lbl_1_bss_3C12__fzgx_offset_2;
    s = lbl_1_bss_3C12__fzgx_offset_6;
    s = fzgx_obj_lbl_1_bss_3C1C;
    s = lbl_1_bss_3C1C__fzgx_offset_4[0];
    s = fzgx_obj_lbl_1_bss_3C2A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b5;
    s = *(u32 *)&fzgx_obj_lbl_1_bss_3C30;
    s = lbl_1_bss_3C30__fzgx_offset_14B8;
    s = fzgx_obj_lbl_1_bss_50EC[0];
    s = fzgx_obj_lbl_1_bss_5100;
    s = fzgx_obj_lbl_1_bss_5104[0];
    s = fzgx_obj_lbl_1_bss_5138[0];
    s = fzgx_obj_lbl_1_bss_523C[0];
    s = fzgx_obj_lbl_1_bss_525C[0];
    s = fzgx_obj_lbl_1_bss_53F4;
    s = fzgx_obj_lbl_1_bss_53F8[0];
    s = fzgx_obj_lbl_1_bss_5480[0];
    s = fzgx_obj_lbl_1_bss_25B80;
    s = fzgx_obj_lbl_1_bss_25B84;
    s = fzgx_obj_lbl_1_bss_25B88[0];
    s = fzgx_obj_lbl_1_bss_25B98;
    s = fzgx_obj_lbl_1_bss_25B9C;
    s = fzgx_obj_lbl_1_bss_25BA0[0];
    s = lbl_1_bss_25BA0__fzgx_offset_8[0];
    s = lbl_1_bss_25BA0__fzgx_offset_28[0];
    s = lbl_1_bss_25BA0__fzgx_offset_48[0];
    s = fzgx_obj_lbl_1_bss_25C48[0];
    s = fzgx_obj_lbl_1_bss_25CA4;
    s = lbl_1_bss_25CA4__fzgx_offset_4;
    s = lbl_1_bss_25CA4__fzgx_offset_8;
    s = lbl_1_bss_25CA4__fzgx_offset_C;
    s = lbl_1_bss_25CA4__fzgx_offset_10;
    s = lbl_1_bss_25CA4__fzgx_offset_14;
    s = lbl_1_bss_25CA4__fzgx_offset_18;
    s = lbl_1_bss_25CA4__fzgx_offset_1C;
    s = lbl_1_bss_25CA4__fzgx_offset_20;
    s = lbl_1_bss_25CA4__fzgx_offset_24;
    s = lbl_1_bss_25CA4__fzgx_offset_28;
    s = fzgx_obj_lbl_1_bss_25CD0[0];
    s = lbl_1_bss_25CD0__fzgx_offset_184;
    s = lbl_1_bss_25CD0__fzgx_offset_188;
    s = lbl_1_bss_25CD0__fzgx_offset_18C;
    s = lbl_1_bss_25CD0__fzgx_offset_190;
    s = lbl_1_bss_25CD0__fzgx_offset_194;
    s = lbl_1_bss_25CD0__fzgx_offset_198;
    s = lbl_1_bss_25CD0__fzgx_offset_19C;
    s = lbl_1_bss_25CD0__fzgx_offset_1A0;
    s = fzgx_obj_lbl_1_bss_25E74[0];
    s = lbl_1_bss_25E74__fzgx_offset_8;
    s = lbl_1_bss_25E74__fzgx_offset_C;
    s = lbl_1_bss_25E74__fzgx_offset_10;
    s = lbl_1_bss_25E74__fzgx_offset_14;
    s = lbl_1_bss_25E74__fzgx_offset_18;
    s = fzgx_obj_lbl_1_bss_25E90[0];
    s = fzgx_obj_lbl_1_bss_25E98[0];
    s = fzgx_obj_lbl_1_bss_25E9C[0];
    s = fzgx_obj_lbl_1_bss_2625C[0];
    s = fzgx_obj_lbl_1_bss_2627C[0];
    s = fzgx_obj_lbl_1_bss_262F4;
    s = fzgx_obj_lbl_1_bss_262F8[0];
    s = fzgx_obj_lbl_1_bss_26300;
    s = fzgx_obj_lbl_1_bss_26304[0];
    s = fzgx_obj_lbl_1_bss_26314[0];
    s = fzgx_obj_lbl_1_bss_26B04[0];
    s = fzgx_obj_lbl_1_bss_26B18;
    s = fzgx_obj_lbl_1_bss_26B19;
    s = fzgx_obj_lbl_1_bss_26B1A;
    s = fzgx_pool_fzgx_pad_26B1B;
    s = fzgx_pool_fzgx_pad_26B1C;
    s = fzgx_obj_lbl_1_bss_26B1D;
    s = fzgx_obj_lbl_1_bss_26B1E;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b42;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b43;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b44;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b45;
    s = fzgx_obj_lbl_1_bss_26B4C;
    s = fzgx_obj_lbl_1_bss_26B50;
    s = fzgx_obj_lbl_1_bss_26B54[0];
    s = fzgx_obj_lbl_1_bss_26B5C[0];
    s = fzgx_obj_lbl_1_bss_26B7A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
    s = fzgx_obj_lbl_1_bss_26B80[0];
    s = fzgx_obj_lbl_1_bss_26C28;
}
#pragma section code_type ".text"

extern u32 fn_1_435C(u32);
extern void fn_1_426C(u32);
extern void fn_1_105724(void);
extern void fn_1_F2EDC(void);
extern void fn_1_A8F78(void);
extern s32 fn_1_1547FC(void *);
extern void fn_1_C47B4(void);
extern void fn_1_C6F80(u8);
extern void fn_1_79100(void);
extern void fn_1_412A0(u32);
extern void fn_1_E35F0(void);
extern u32 fn_80008E84(u32);

static inline void game_copy_names(void) {
    s32 i;
    for (i = 0; i < fzgx_obj_lbl_1_bss_3C30.unk_9; i++) {
        u8 *d = fzgx_obj_lbl_1_bss_3C30.entries[i].data;
        d[fzgx_obj_lbl_1_bss_3C30.unk_A7 + 0xE] = lbl_1_bss_25BA0__fzgx_offset_8[i];
        d[fzgx_obj_lbl_1_bss_3C30.unk_A7 + 0x13] = lbl_1_bss_25BA0__fzgx_offset_28[i];
    }
}

void fn_1_3AEC4(void) {
    u32 v;

    fn_1_435C(fzgx_obj_lbl_1_bss_25B88[0]);
    if (lbl_1_bss_25E74__fzgx_offset_8 != -1) {
        fn_1_426C(lbl_1_bss_25E74__fzgx_offset_8);
    }
    if (lbl_1_bss_25E74__fzgx_offset_C != -1) {
        fn_1_426C(lbl_1_bss_25E74__fzgx_offset_C);
        fn_1_105724();
    }
    fn_1_435C(fzgx_obj_lbl_1_bss_25CA4);
    if (lbl_1_bss_25E74__fzgx_offset_10 != -1) {
        fn_1_426C(lbl_1_bss_25E74__fzgx_offset_10);
    }
    lbl_1_bss_25E74__fzgx_offset_8 = -1;
    lbl_1_bss_25E74__fzgx_offset_C = -1;
    lbl_1_bss_25E74__fzgx_offset_10 = -1;
    if (fzgx_obj_lbl_1_bss_3C30.flags & 0x800000) {
        if (lbl_1_bss_3C30__fzgx_offset_14B8 != 0x2A) {
            fn_1_F2EDC();
        }
    }
    fn_1_A8F78();
    if (lbl_1_bss_25CD0__fzgx_offset_19C != 0) {
        lbl_1_bss_25CD0__fzgx_offset_1A0 = 1;
    }
    if (lbl_1_bss_25CD0__fzgx_offset_1A0 != 0) {
        game_copy_names();
        fzgx_obj_lbl_1_bss_3C30.unk_1464 = 0;
        fzgx_obj_lbl_1_bss_3C30.unk_146C = 0;
        fzgx_obj_lbl_1_bss_3C30.unk_146D = 0;
        fzgx_obj_lbl_1_bss_3C30.unk_1470 = 0;
        fzgx_obj_lbl_1_bss_3C30.unk_146E = 0x5DC;
        fn_1_1547FC(&fzgx_obj_lbl_1_bss_3C30);
        fn_1_C47B4();
        fn_1_435C(fzgx_obj_lbl_1_bss_25B88[0]);
        if (lbl_1_bss_3C12__fzgx_offset_2 != 0) {
            fn_1_426C(lbl_1_bss_3C12__fzgx_offset_2);
            lbl_1_bss_3C12__fzgx_offset_2 = 0;
        }
        fn_1_435C(fzgx_obj_lbl_1_bss_25CA4);
        if (lbl_1_bss_3C12__fzgx_offset_6 != 0) {
            fn_1_426C(lbl_1_bss_3C12__fzgx_offset_6);
            lbl_1_bss_3C12__fzgx_offset_6 = 0;
        }
        fn_1_C6F80(0);
        v = fn_80008E84(lbl_1_bss_25CA4__fzgx_offset_28);
        fn_1_79100();
        fn_80008E84(v);
        fn_1_412A0(2);
        fn_1_E35F0();
        fn_1_435C(fzgx_obj_lbl_1_bss_25B88[0]);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_10);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_14);
        fn_1_426C(lbl_1_bss_25CD0__fzgx_offset_194);
        fn_1_435C(fzgx_obj_lbl_1_bss_25CA4);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_4);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_8);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_C);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_18);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_1C);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_20);
        fn_1_426C(lbl_1_bss_25CD0__fzgx_offset_188);
        fn_1_426C(lbl_1_bss_25CD0__fzgx_offset_18C);
        fn_1_426C(lbl_1_bss_25CD0__fzgx_offset_190);
        fn_1_426C(lbl_1_bss_25CD0__fzgx_offset_184);
    }
    if (lbl_1_bss_25CD0__fzgx_offset_19C != 0) {
        fzgx_obj_lbl_1_bss_3C30.unk_A7++;
    }
}
/* fzgx:end fn_1_3AEC4 */

/* fzgx:begin fn_1_3CDB0 noprologue */
#include "types.h"

typedef struct GameState30 {
    u32 flags;
    u8 pad_4;
    u8 unk_5;
    u8 pad_6[2];
    u8 unk_8;
    u8 pad_9[0x14B3];
} GameState30;

typedef struct Obj_1_bss_7EFD8 {
    u32 unk_0;
} Obj_1_bss_7EFD8;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 fzgx_obj_lbl_1_bss_3C08[2];
u8 fzgx_obj_lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u8 fzgx_obj_lbl_1_bss_3C12;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b5;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b7;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b8;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b9;
u32 fzgx_obj_lbl_1_bss_3C1C;
u8 lbl_1_bss_3C1C__fzgx_offset_4[10];
u8 fzgx_obj_lbl_1_bss_3C2A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b5;
GameState30 fzgx_obj_lbl_1_bss_3C30;
u32 fzgx_obj_lbl_1_bss_50EC[5];
u32 fzgx_obj_lbl_1_bss_5100;
s8 fzgx_obj_lbl_1_bss_5104[0x34];
u32 fzgx_obj_lbl_1_bss_5138[65];
u32 fzgx_obj_lbl_1_bss_523C[8];
u32 fzgx_obj_lbl_1_bss_525C[102];
u16 fzgx_obj_lbl_1_bss_53F4;
u32 fzgx_obj_lbl_1_bss_53F8[34];
u32 fzgx_obj_lbl_1_bss_5480[33216];
u16 fzgx_obj_lbl_1_bss_25B80;
u32 fzgx_obj_lbl_1_bss_25B84;
u32 fzgx_obj_lbl_1_bss_25B88[4];
u16 fzgx_obj_lbl_1_bss_25B98;
u32 fzgx_obj_lbl_1_bss_25B9C;
u32 fzgx_obj_lbl_1_bss_25BA0[42];
u32 fzgx_obj_lbl_1_bss_25C48[23];
u32 fzgx_obj_lbl_1_bss_25CA4[11];
u32 fzgx_obj_lbl_1_bss_25CD0[105];
u32 fzgx_obj_lbl_1_bss_25E74[7];
u32 fzgx_obj_lbl_1_bss_25E90[2];
u8 fzgx_obj_lbl_1_bss_25E98[1];
u32 fzgx_obj_lbl_1_bss_25E9C[240];
u32 fzgx_obj_lbl_1_bss_2625C[8];
u32 fzgx_obj_lbl_1_bss_2627C[30];
u8 fzgx_obj_lbl_1_bss_262F4;
u32 fzgx_obj_lbl_1_bss_262F8[2];
u16 fzgx_obj_lbl_1_bss_26300;
u32 fzgx_obj_lbl_1_bss_26304[4];
u32 fzgx_obj_lbl_1_bss_26314[508];
u32 fzgx_obj_lbl_1_bss_26B04[5];
u8 fzgx_obj_lbl_1_bss_26B18;
u8 fzgx_obj_lbl_1_bss_26B19;
u8 fzgx_obj_lbl_1_bss_26B1A;
u8 fzgx_pool_fzgx_pad_26B1B;
u8 fzgx_pool_fzgx_pad_26B1C;
u8 fzgx_obj_lbl_1_bss_26B1D;
u8 fzgx_obj_lbl_1_bss_26B1E;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b42;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b43;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b44;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b45;
u32 fzgx_obj_lbl_1_bss_26B4C;
u32 fzgx_obj_lbl_1_bss_26B50;
u32 fzgx_obj_lbl_1_bss_26B54[2];
u8 fzgx_obj_lbl_1_bss_26B5C[30];
u8 fzgx_obj_lbl_1_bss_26B7A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
u32 fzgx_obj_lbl_1_bss_26B80[42];
u32 fzgx_obj_lbl_1_bss_26C28;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_3C00;
    s = fzgx_obj_lbl_1_bss_3C04;
    s = fzgx_obj_lbl_1_bss_3C08[0];
    s = fzgx_obj_lbl_1_bss_3C10;
    s = fzgx_obj_lbl_1_bss_3C11;
    s = fzgx_obj_lbl_1_bss_3C12;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b5;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b7;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b8;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b9;
    s = fzgx_obj_lbl_1_bss_3C1C;
    s = lbl_1_bss_3C1C__fzgx_offset_4[0];
    s = fzgx_obj_lbl_1_bss_3C2A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b5;
    s = *(u32 *)&fzgx_obj_lbl_1_bss_3C30;
    s = fzgx_obj_lbl_1_bss_50EC[0];
    s = fzgx_obj_lbl_1_bss_5100;
    s = fzgx_obj_lbl_1_bss_5104[0];
    s = fzgx_obj_lbl_1_bss_5138[0];
    s = fzgx_obj_lbl_1_bss_523C[0];
    s = fzgx_obj_lbl_1_bss_525C[0];
    s = fzgx_obj_lbl_1_bss_53F4;
    s = fzgx_obj_lbl_1_bss_53F8[0];
    s = fzgx_obj_lbl_1_bss_5480[0];
    s = fzgx_obj_lbl_1_bss_25B80;
    s = fzgx_obj_lbl_1_bss_25B84;
    s = fzgx_obj_lbl_1_bss_25B88[0];
    s = fzgx_obj_lbl_1_bss_25B98;
    s = fzgx_obj_lbl_1_bss_25B9C;
    s = fzgx_obj_lbl_1_bss_25BA0[0];
    s = fzgx_obj_lbl_1_bss_25C48[0];
    s = fzgx_obj_lbl_1_bss_25CA4[0];
    s = fzgx_obj_lbl_1_bss_25CD0[0];
    s = fzgx_obj_lbl_1_bss_25E74[0];
    s = fzgx_obj_lbl_1_bss_25E90[0];
    s = fzgx_obj_lbl_1_bss_25E98[0];
    s = fzgx_obj_lbl_1_bss_25E9C[0];
    s = fzgx_obj_lbl_1_bss_2625C[0];
    s = fzgx_obj_lbl_1_bss_2627C[0];
    s = fzgx_obj_lbl_1_bss_262F4;
    s = fzgx_obj_lbl_1_bss_262F8[0];
    s = fzgx_obj_lbl_1_bss_26300;
    s = fzgx_obj_lbl_1_bss_26304[0];
    s = fzgx_obj_lbl_1_bss_26314[0];
    s = fzgx_obj_lbl_1_bss_26B04[0];
    s = fzgx_obj_lbl_1_bss_26B18;
    s = fzgx_obj_lbl_1_bss_26B19;
    s = fzgx_obj_lbl_1_bss_26B1A;
    s = fzgx_pool_fzgx_pad_26B1B;
    s = fzgx_pool_fzgx_pad_26B1C;
    s = fzgx_obj_lbl_1_bss_26B1D;
    s = fzgx_obj_lbl_1_bss_26B1E;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b42;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b43;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b44;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b45;
    s = fzgx_obj_lbl_1_bss_26B4C;
    s = fzgx_obj_lbl_1_bss_26B50;
    s = fzgx_obj_lbl_1_bss_26B54[0];
    s = fzgx_obj_lbl_1_bss_26B5C[0];
    s = fzgx_obj_lbl_1_bss_26B7A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
    s = fzgx_obj_lbl_1_bss_26B80[0];
    s = fzgx_obj_lbl_1_bss_26C28;
}
#pragma section code_type ".text"

extern Obj_1_bss_7EFD8 lbl_1_bss_7EFD8;
extern void fn_1_1280(u32);
extern void fn_1_D0790(void);
extern void *fn_1_435C(u32);
extern s32 fn_1_F2F58(void);
extern void fn_1_F37F4(void);
extern void fn_1_426C(u32);
extern void fn_1_F2EDC(void);

void fn_1_3CDB0(void) {
    fn_1_1280(0);
    if (fzgx_obj_lbl_1_bss_3C30.unk_5 != 5) {
        fn_1_D0790();
    }
    fzgx_obj_lbl_1_bss_3C30.flags |= 0x2000;
    fn_1_435C(fzgx_obj_lbl_1_bss_25B88[0]);
    if (fzgx_obj_lbl_1_bss_3C30.flags & 0x800000) {
        if (lbl_1_bss_7EFD8.unk_0 != 0) {
            if (fn_1_F2F58() != 0) {
                fn_1_F37F4();
            }
            fn_1_426C(lbl_1_bss_7EFD8.unk_0);
            lbl_1_bss_7EFD8.unk_0 = 0;
        }
        fn_1_F2EDC();
    }
    fzgx_obj_lbl_1_bss_5104[0] = -1;
    if (fzgx_obj_lbl_1_bss_3C30.unk_8 != 0) {
        lbl_1_bss_3C1C__fzgx_offset_4[0] = fzgx_obj_lbl_1_bss_25E98[0];
    } else {
        lbl_1_bss_3C1C__fzgx_offset_4[0] = 0;
    }
    fzgx_obj_lbl_1_bss_26C28 = 0;
}
/* fzgx:end fn_1_3CDB0 */

/* fzgx:begin fn_1_3DB9C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"

typedef struct Sig_ADXT_Pause_AdxSjdHandle Sig_ADXT_Pause_AdxSjdHandle;

typedef struct Sig_ADXT_Pause_ADXStream Sig_ADXT_Pause_ADXStream;

typedef struct Sig_ADXT_Pause_AXRNAHandle Sig_ADXT_Pause_AXRNAHandle;

typedef struct Sig_ADXT_Pause_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Pause_SJCK;

typedef void (*Sig_ADXT_Pause_SJErrorCallback)(void *object, int error);

typedef struct Sig_ADXT_Pause_SJInterface Sig_ADXT_Pause_SJInterface;

typedef struct Sig_ADXT_Pause_SJ Sig_ADXT_Pause_SJ;

struct Sig_ADXT_Pause_SJ {
    const Sig_ADXT_Pause_SJInterface *interface;
};

struct Sig_ADXT_Pause_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Pause_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Pause_SJ *sj);
    void (*reset)(Sig_ADXT_Pause_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, int max_size, Sig_ADXT_Pause_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, Sig_ADXT_Pause_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, Sig_ADXT_Pause_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Pause_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Pause_SJ *sj, Sig_ADXT_Pause_SJErrorCallback callback, void *object);
};

typedef struct Sig_ADXT_Pause_ADX_AMP Sig_ADXT_Pause_ADX_AMP;

typedef struct Sig_ADXT_Pause_LSCObject Sig_ADXT_Pause_LSCObject;

typedef struct Sig_ADXT_Pause_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Pause_AdxSjdHandle *decoder;
    Sig_ADXT_Pause_ADXStream *stream;
    Sig_ADXT_Pause_AXRNAHandle *rna;
    Sig_ADXT_Pause_SJ *stream_sj;
    Sig_ADXT_Pause_SJ *input_sj;
    Sig_ADXT_Pause_SJ *output_sj[2];
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
    Sig_ADXT_Pause_ADX_AMP *amplifier;
    Sig_ADXT_Pause_SJ *amplifier_input[2];
    Sig_ADXT_Pause_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Pause_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Pause_ADXTHandle;

typedef struct Sig_ADXT_Stop_AdxSjdHandle Sig_ADXT_Stop_AdxSjdHandle;

typedef struct Sig_ADXT_Stop_ADXStream Sig_ADXT_Stop_ADXStream;

typedef struct Sig_ADXT_Stop_AXRNAHandle Sig_ADXT_Stop_AXRNAHandle;

typedef struct Sig_ADXT_Stop_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK;

typedef void (*Sig_ADXT_Stop_SJErrorCallback)(void *object, int error);

typedef struct Sig_ADXT_Stop_SJInterface Sig_ADXT_Stop_SJInterface;

typedef struct Sig_ADXT_Stop_SJ Sig_ADXT_Stop_SJ;

struct Sig_ADXT_Stop_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ *sj);
    void (*reset)(Sig_ADXT_Stop_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};

struct Sig_ADXT_Stop_SJ {
    const Sig_ADXT_Stop_SJInterface *interface;
};

typedef struct Sig_ADXT_Stop_ADX_AMP Sig_ADXT_Stop_ADX_AMP;

typedef struct Sig_ADXT_Stop_LSCObject Sig_ADXT_Stop_LSCObject;

typedef struct Sig_ADXT_Stop_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Stop_AdxSjdHandle *decoder;
    Sig_ADXT_Stop_ADXStream *stream;
    Sig_ADXT_Stop_AXRNAHandle *rna;
    Sig_ADXT_Stop_SJ *stream_sj;
    Sig_ADXT_Stop_SJ *input_sj;
    Sig_ADXT_Stop_SJ *output_sj[2];
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
    Sig_ADXT_Stop_ADX_AMP *amplifier;
    Sig_ADXT_Stop_SJ *amplifier_input[2];
    Sig_ADXT_Stop_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Stop_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Stop_ADXTHandle;

typedef struct {
    u8 unk[0xb];
    u8 value;
} Entry;

typedef struct {
    u8 pad_0[2];
    s16 unk_2;
    u8 pad_4[8];
    u32 unk_C;
    u8 pad_10[0x10];
} Obj_1_bss_25E9C;

typedef struct {
    u8 pad[0x2f8];
    u32 value_2f8;
    u32 value_2fc;
    u32 value_300;
    u32 value_304;
    u32 value_308;
    u32 value_30c;
    u32 value_310;
    u32 value_314;
    u32 value_318;
    u32 value_31c;
} Fn40710Config;
extern void fn_1_15E330(s32 index, u32 value, void *arg);
extern void fn_1_15E5E4(s32 index, void *arg);
extern void fn_1_15E688(s32 index, u32 value, u8 state, void *arg);
extern void fn_1_15E3E0(s32 index, u32 value);
extern void fn_1_15E434(u32 value);
extern void fn_1_15E540(s32 index, void *arg);
extern void fn_1_CB404(u8 value);
extern void fn_1_D07C4(u32 arg0, u32 arg1);
extern u32 lbl_1_bss_25B84;
extern u32 OSGetTick(void);
extern void fn_1_A0978(void);
extern void fn_1_35174(void);
extern s32 fn_1_3EFA8(void);
extern u16 lbl_1_bss_26B7A[3];
extern u16 lbl_1_bss_26300;
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern u32 fn_1_101C0(void);
extern u32 fn_1_A11EC(void);
extern u32 fn_1_435C(u32 value);
extern void ADXT_Pause(Sig_ADXT_Pause_ADXTHandle *, s32);
extern void fn_1_4310(u32 arg0);
extern void fn_1_48004(s32 index, s32 image);
extern void fn_1_8616C(void);
extern void fn_1_A1588(u32 arg0, u32 arg1);
extern void fn_1_D0790(void);
extern void fn_1_817C0(void);
extern u32 lbl_1_bss_381FC;
extern void fn_1_EB080(int mode);
extern s64 OSGetTime(void);
extern void fn_1_4A00(u32 arg0, u32 arg1, u32 arg2);
extern void fn_1_5370(u32 arg0, u32 arg1);
extern void fn_1_15E27C(void);
extern void fn_1_4811C(int arg);
extern void fn_1_A8F78(void);
extern u8 lbl_1_bss_262F4;
extern u32 lbl_1_bss_25E74[7];
extern u8 lbl_1_bss_3C10;
extern void fn_1_36330(void);
extern void fn_1_36B10(void);
extern void fn_1_3C98(void);
extern void fn_1_37AA8(void);
extern void fn_1_37E98(void);
extern f32 lbl_1_bss_26304[4];
extern u8 lbl_1_bss_26B04[20];
extern u8 lbl_1_bss_26314[2032];
extern s16 fn_1_12EF24(s16 row, s16 column);
extern u8 lbl_1_bss_523C[32];
extern Entry *lbl_1_bss_53F8[34];
extern void OSPanic(const void *, u32, const char *, ...);
extern Obj_1_bss_25E9C lbl_1_bss_25E9C[30];
extern void fn_1_12AB38(void *arg0);
extern void fn_1_465D0(char *value, u32 flag);
extern void* fn_1_7F518(s16 car_type, void* car, s32 initialize);
extern int sprintf(char *s, const char *format, ...);
extern void fn_1_451E4(void);
extern void fn_1_D3214(void);
extern void VIWaitForRetrace(void);
extern u32 fn_1_467F4(void);
extern u32 fn_1_13018(void);
extern u32 fn_1_46C60(void);
extern u32 lbl_1_bss_26C2C[2];
extern u32 lbl_1_bss_262F8[2];
extern u16 lbl_1_bss_26C68[35526];
extern u32 lbl_1_bss_3C08[2];
extern u32 fn_800075AC(u32, u32, u32);
extern u32 ghost_test_record_flag0(s32 arg);
extern u32 fn_1_F9D44(u32 arg);
extern u8 fn_1_F8C50(s32 arg0);
extern void fn_1_2DB50(void);
extern void fn_1_3F8C(void *, void *, Obj_1_bss_5138 *, int);
extern void fn_1_2D888(void);
extern void fn_1_2D524(void);
extern u32 fn_1_FA070(void);
extern int fn_1_FA180(int, u8);
extern u32 fn_1_F9FEC(void);
extern void fn_1_A2DC4(u32 arg0);
extern Fn40710Config lbl_1_rodata_BD8;
extern u8 lbl_1_bss_26B54[8];
extern u32 fn_1_40EE4(void);
extern u32 lbl_801A63D0;
extern u32 lbl_1_bss_26C34[9];
extern u8 lbl_1_bss_38218[568];
extern u32 fn_1_4060(void);
extern void ARQPostRequest(u8 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, u32 arg7);
extern u32 lbl_801A63C0;
extern void fn_1_40BE4(void);
extern u32 GXGetTexBufferSize(u32, u32, u32, u32, u32);
extern u32 lbl_1_bss_26B4C;
extern u8 lbl_1_bss_25E90[8];
extern s32 fn_1_48B0(u32 arg0, u32 arg1);
extern void fn_1_40F54(void *arg0);
extern u32 lbl_801A6CE0;
extern u32 lbl_1_bss_38454;
extern u32 fn_80070DE0(u32 arg0);
extern void fn_1_D3884();
extern void fn_1_D358C();
extern void fn_800711A8(Obj_1_bss_38458_Target *target);
extern void fn_80071718(u32 value);
extern void fn_1_41134(void *unused, char *value);
extern void fn_1_411D4(u32, char *);
extern int DVDConvertPathToEntrynum(char *buffer);
extern void fn_1_412A0(u32 index);
extern size_t strlen(const char *str);
extern int fn_80083BCC(const char *s1, const char *s2);
extern u8 lbl_1_A9011300;
extern u8 lbl_1_A9011100;
extern u8 lbl_1_A9011000;

typedef struct GameEntryC {
    u8 data[0xA0];
} GameEntryC;

typedef struct GameStateC {
    u32 flags;
    u8 pad_4[5];
    u8 unk_9;
    u8 pad_A[0x9D];
    u8 unk_A7;
    u8 pad_A8[0x2C];
    GameEntryC entries[31];
    u8 pad_1434[0x30];
    u32 unk_1464;
    u8 pad_1468[0x4];
    u8 unk_146C;
    u8 unk_146D;
    s16 unk_146E;
    u8 unk_1470;
    u8 pad_1471[0x47];
} GameStateC;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 fzgx_obj_lbl_1_bss_3C08[2];
u8 fzgx_obj_lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u16 fzgx_obj_lbl_1_bss_3C12;
u32 lbl_1_bss_3C12__fzgx_offset_2;
u32 lbl_1_bss_3C12__fzgx_offset_6;
u32 fzgx_obj_lbl_1_bss_3C1C;
u8 lbl_1_bss_3C1C__fzgx_offset_4[10];
u8 fzgx_obj_lbl_1_bss_3C2A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b5;
GameStateC fzgx_obj_lbl_1_bss_3C30;
s16 lbl_1_bss_3C30__fzgx_offset_14B8;
u32 fzgx_obj_lbl_1_bss_50EC[5];
u32 fzgx_obj_lbl_1_bss_5100;
u32 fzgx_obj_lbl_1_bss_5104[13];
u32 fzgx_obj_lbl_1_bss_5138[65];
u32 fzgx_obj_lbl_1_bss_523C[8];
u32 fzgx_obj_lbl_1_bss_525C[102];
u16 fzgx_obj_lbl_1_bss_53F4;
u32 fzgx_obj_lbl_1_bss_53F8[34];
u32 fzgx_obj_lbl_1_bss_5480[33216];
u16 fzgx_obj_lbl_1_bss_25B80;
u32 fzgx_obj_lbl_1_bss_25B84;
u32 fzgx_obj_lbl_1_bss_25B88[4];
u16 fzgx_obj_lbl_1_bss_25B98;
u32 fzgx_obj_lbl_1_bss_25B9C;
u32 fzgx_obj_lbl_1_bss_25BA0[2];
u8 lbl_1_bss_25BA0__fzgx_offset_8[0x20];
u8 lbl_1_bss_25BA0__fzgx_offset_28[0x20];
u32 lbl_1_bss_25BA0__fzgx_offset_48[24];
u32 fzgx_obj_lbl_1_bss_25C48[23];
u32 fzgx_obj_lbl_1_bss_25CA4;
u32 lbl_1_bss_25CA4__fzgx_offset_4;
u32 lbl_1_bss_25CA4__fzgx_offset_8;
u32 lbl_1_bss_25CA4__fzgx_offset_C;
u32 lbl_1_bss_25CA4__fzgx_offset_10;
u32 lbl_1_bss_25CA4__fzgx_offset_14;
u32 lbl_1_bss_25CA4__fzgx_offset_18;
u32 lbl_1_bss_25CA4__fzgx_offset_1C;
u32 lbl_1_bss_25CA4__fzgx_offset_20;
u32 lbl_1_bss_25CA4__fzgx_offset_24;
u32 lbl_1_bss_25CA4__fzgx_offset_28;
u32 fzgx_obj_lbl_1_bss_25CD0[97];
u32 lbl_1_bss_25CD0__fzgx_offset_184;
u32 lbl_1_bss_25CD0__fzgx_offset_188;
u32 lbl_1_bss_25CD0__fzgx_offset_18C;
u32 lbl_1_bss_25CD0__fzgx_offset_190;
u32 lbl_1_bss_25CD0__fzgx_offset_194;
u32 lbl_1_bss_25CD0__fzgx_offset_198;
s32 lbl_1_bss_25CD0__fzgx_offset_19C;
s32 lbl_1_bss_25CD0__fzgx_offset_1A0;
u32 fzgx_obj_lbl_1_bss_25E74[2];
s32 lbl_1_bss_25E74__fzgx_offset_8;
s32 lbl_1_bss_25E74__fzgx_offset_C;
s32 lbl_1_bss_25E74__fzgx_offset_10;
u32 lbl_1_bss_25E74__fzgx_offset_14;
u32 lbl_1_bss_25E74__fzgx_offset_18;
u32 fzgx_obj_lbl_1_bss_25E90[2];
u8 fzgx_obj_lbl_1_bss_25E98[1];
u32 fzgx_obj_lbl_1_bss_25E9C[240];
u32 fzgx_obj_lbl_1_bss_2625C[8];
u32 fzgx_obj_lbl_1_bss_2627C[30];
u8 fzgx_obj_lbl_1_bss_262F4;
u32 fzgx_obj_lbl_1_bss_262F8[2];
u16 fzgx_obj_lbl_1_bss_26300;
u32 fzgx_obj_lbl_1_bss_26304[4];
u32 fzgx_obj_lbl_1_bss_26314[508];
u32 fzgx_obj_lbl_1_bss_26B04[5];
u8 fzgx_obj_lbl_1_bss_26B18;
u8 fzgx_obj_lbl_1_bss_26B19;
u8 fzgx_obj_lbl_1_bss_26B1A;
u8 fzgx_pool_fzgx_pad_26B1B;
u8 fzgx_pool_fzgx_pad_26B1C;
u8 fzgx_obj_lbl_1_bss_26B1D;
u8 fzgx_obj_lbl_1_bss_26B1E;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b42;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b43;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b44;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b45;
u32 fzgx_obj_lbl_1_bss_26B4C;
u32 fzgx_obj_lbl_1_bss_26B50;
u32 fzgx_obj_lbl_1_bss_26B54[2];
u8 fzgx_obj_lbl_1_bss_26B5C[30];
u8 fzgx_obj_lbl_1_bss_26B7A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
u32 fzgx_obj_lbl_1_bss_26B80[42];
u32 fzgx_obj_lbl_1_bss_26C28;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_3C00;
    s = fzgx_obj_lbl_1_bss_3C04;
    s = fzgx_obj_lbl_1_bss_3C08[0];
    s = fzgx_obj_lbl_1_bss_3C10;
    s = fzgx_obj_lbl_1_bss_3C11;
    s = fzgx_obj_lbl_1_bss_3C12;
    s = lbl_1_bss_3C12__fzgx_offset_2;
    s = lbl_1_bss_3C12__fzgx_offset_6;
    s = fzgx_obj_lbl_1_bss_3C1C;
    s = lbl_1_bss_3C1C__fzgx_offset_4[0];
    s = fzgx_obj_lbl_1_bss_3C2A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b5;
    s = *(u32 *)&fzgx_obj_lbl_1_bss_3C30;
    s = lbl_1_bss_3C30__fzgx_offset_14B8;
    s = fzgx_obj_lbl_1_bss_50EC[0];
    s = fzgx_obj_lbl_1_bss_5100;
    s = fzgx_obj_lbl_1_bss_5104[0];
    s = fzgx_obj_lbl_1_bss_5138[0];
    s = fzgx_obj_lbl_1_bss_523C[0];
    s = fzgx_obj_lbl_1_bss_525C[0];
    s = fzgx_obj_lbl_1_bss_53F4;
    s = fzgx_obj_lbl_1_bss_53F8[0];
    s = fzgx_obj_lbl_1_bss_5480[0];
    s = fzgx_obj_lbl_1_bss_25B80;
    s = fzgx_obj_lbl_1_bss_25B84;
    s = fzgx_obj_lbl_1_bss_25B88[0];
    s = fzgx_obj_lbl_1_bss_25B98;
    s = fzgx_obj_lbl_1_bss_25B9C;
    s = fzgx_obj_lbl_1_bss_25BA0[0];
    s = lbl_1_bss_25BA0__fzgx_offset_8[0];
    s = lbl_1_bss_25BA0__fzgx_offset_28[0];
    s = lbl_1_bss_25BA0__fzgx_offset_48[0];
    s = fzgx_obj_lbl_1_bss_25C48[0];
    s = fzgx_obj_lbl_1_bss_25CA4;
    s = lbl_1_bss_25CA4__fzgx_offset_4;
    s = lbl_1_bss_25CA4__fzgx_offset_8;
    s = lbl_1_bss_25CA4__fzgx_offset_C;
    s = lbl_1_bss_25CA4__fzgx_offset_10;
    s = lbl_1_bss_25CA4__fzgx_offset_14;
    s = lbl_1_bss_25CA4__fzgx_offset_18;
    s = lbl_1_bss_25CA4__fzgx_offset_1C;
    s = lbl_1_bss_25CA4__fzgx_offset_20;
    s = lbl_1_bss_25CA4__fzgx_offset_24;
    s = lbl_1_bss_25CA4__fzgx_offset_28;
    s = fzgx_obj_lbl_1_bss_25CD0[0];
    s = lbl_1_bss_25CD0__fzgx_offset_184;
    s = lbl_1_bss_25CD0__fzgx_offset_188;
    s = lbl_1_bss_25CD0__fzgx_offset_18C;
    s = lbl_1_bss_25CD0__fzgx_offset_190;
    s = lbl_1_bss_25CD0__fzgx_offset_194;
    s = lbl_1_bss_25CD0__fzgx_offset_198;
    s = lbl_1_bss_25CD0__fzgx_offset_19C;
    s = lbl_1_bss_25CD0__fzgx_offset_1A0;
    s = fzgx_obj_lbl_1_bss_25E74[0];
    s = lbl_1_bss_25E74__fzgx_offset_8;
    s = lbl_1_bss_25E74__fzgx_offset_C;
    s = lbl_1_bss_25E74__fzgx_offset_10;
    s = lbl_1_bss_25E74__fzgx_offset_14;
    s = lbl_1_bss_25E74__fzgx_offset_18;
    s = fzgx_obj_lbl_1_bss_25E90[0];
    s = fzgx_obj_lbl_1_bss_25E98[0];
    s = fzgx_obj_lbl_1_bss_25E9C[0];
    s = fzgx_obj_lbl_1_bss_2625C[0];
    s = fzgx_obj_lbl_1_bss_2627C[0];
    s = fzgx_obj_lbl_1_bss_262F4;
    s = fzgx_obj_lbl_1_bss_262F8[0];
    s = fzgx_obj_lbl_1_bss_26300;
    s = fzgx_obj_lbl_1_bss_26304[0];
    s = fzgx_obj_lbl_1_bss_26314[0];
    s = fzgx_obj_lbl_1_bss_26B04[0];
    s = fzgx_obj_lbl_1_bss_26B18;
    s = fzgx_obj_lbl_1_bss_26B19;
    s = fzgx_obj_lbl_1_bss_26B1A;
    s = fzgx_pool_fzgx_pad_26B1B;
    s = fzgx_pool_fzgx_pad_26B1C;
    s = fzgx_obj_lbl_1_bss_26B1D;
    s = fzgx_obj_lbl_1_bss_26B1E;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b42;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b43;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b44;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b45;
    s = fzgx_obj_lbl_1_bss_26B4C;
    s = fzgx_obj_lbl_1_bss_26B50;
    s = fzgx_obj_lbl_1_bss_26B54[0];
    s = fzgx_obj_lbl_1_bss_26B5C[0];
    s = fzgx_obj_lbl_1_bss_26B7A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
    s = fzgx_obj_lbl_1_bss_26B80[0];
    s = fzgx_obj_lbl_1_bss_26C28;
}
#pragma section code_type ".text"

extern u32 fn_1_435C(u32);
extern void fn_1_426C(u32);
extern void fn_1_105724(void);
extern void fn_1_F2EDC(void);
extern void fn_1_A8F78(void);
extern s32 fn_1_1547FC(void *);
extern void fn_1_156754(s32);
extern void fn_1_F7578(void);
extern void fn_1_C47B4(void);
extern void fn_1_C6F80(u8);
extern void fn_1_79100(void);
extern void fn_1_412A0(u32);
extern void fn_1_E35F0(void);
extern u32 fn_80008E84(u32);

static inline void game_copy_names(void) {
    s32 i;
    for (i = 0; i < fzgx_obj_lbl_1_bss_3C30.unk_9; i++) {
        u8 *d = fzgx_obj_lbl_1_bss_3C30.entries[i].data;
        d[fzgx_obj_lbl_1_bss_3C30.unk_A7 + 0xE] = lbl_1_bss_25BA0__fzgx_offset_8[i];
        d[fzgx_obj_lbl_1_bss_3C30.unk_A7 + 0x13] = lbl_1_bss_25BA0__fzgx_offset_28[i];
    }
}

void fn_1_3DB9C(void) {
    s32 i;
    u32 v;

    for (i = 0; i < 4; i++) {
        fn_1_156754(i);
    }
    fn_1_F7578();
    fzgx_obj_lbl_1_bss_3C30.flags &= ~0x2000;
    fn_1_A8F78();
    if (lbl_1_bss_25CD0__fzgx_offset_19C != 0) {
        lbl_1_bss_25CD0__fzgx_offset_1A0 = 1;
    }
    if (lbl_1_bss_25CD0__fzgx_offset_1A0 != 0) {
        game_copy_names();
        fzgx_obj_lbl_1_bss_3C30.unk_1464 = 0;
        fzgx_obj_lbl_1_bss_3C30.unk_146C = 0;
        fzgx_obj_lbl_1_bss_3C30.unk_146D = 0;
        fzgx_obj_lbl_1_bss_3C30.unk_1470 = 0;
        fzgx_obj_lbl_1_bss_3C30.unk_146E = 0x5DC;
        fn_1_1547FC(&fzgx_obj_lbl_1_bss_3C30);
        fn_1_C47B4();
        fn_1_435C(fzgx_obj_lbl_1_bss_25B88[0]);
        if (lbl_1_bss_3C12__fzgx_offset_2 != 0) {
            fn_1_426C(lbl_1_bss_3C12__fzgx_offset_2);
            lbl_1_bss_3C12__fzgx_offset_2 = 0;
        }
        fn_1_435C(fzgx_obj_lbl_1_bss_25CA4);
        if (lbl_1_bss_3C12__fzgx_offset_6 != 0) {
            fn_1_426C(lbl_1_bss_3C12__fzgx_offset_6);
            lbl_1_bss_3C12__fzgx_offset_6 = 0;
        }
        fn_1_C6F80(0);
        v = fn_80008E84(lbl_1_bss_25CA4__fzgx_offset_28);
        fn_1_79100();
        fn_80008E84(v);
        fn_1_412A0(2);
        fn_1_E35F0();
        fn_1_435C(fzgx_obj_lbl_1_bss_25B88[0]);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_10);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_14);
        fn_1_426C(lbl_1_bss_25CD0__fzgx_offset_194);
        fn_1_435C(fzgx_obj_lbl_1_bss_25CA4);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_4);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_8);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_C);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_18);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_1C);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_20);
        fn_1_426C(lbl_1_bss_25CD0__fzgx_offset_188);
        fn_1_426C(lbl_1_bss_25CD0__fzgx_offset_18C);
        fn_1_426C(lbl_1_bss_25CD0__fzgx_offset_190);
        fn_1_426C(lbl_1_bss_25CD0__fzgx_offset_184);
    }
    if (lbl_1_bss_25CD0__fzgx_offset_19C != 0) {
        fzgx_obj_lbl_1_bss_3C30.unk_A7++;
    }
}
/* fzgx:end fn_1_3DB9C */

/* fzgx:begin fn_1_3DDAC */
// Initializes global game state and configures startup resources.
void fn_1_3DDAC(void) {
    fn_1_4A00(1, 0x1e, lbl_1_bss_5100);
    fn_1_5370(3, 0);
    fn_1_15E27C();

    lbl_1_bss_26C28 = 0;
    fn_1_D0790();

    lbl_1_bss_3C30.unk_0 |= 0x8;
    lbl_1_bss_6EAB4.unk_0 |= 0x2c;
    fn_1_4811C(0x94);

    fn_1_48004(0x8a, 1);
    fn_1_435C( (u32)((void *)lbl_1_bss_25CA4.unk_0));
    fn_1_4310(0x20000);
    fn_1_435C( (u32)((void *)lbl_1_bss_25B88.unk_0));
    fn_1_4310(0x2c3);

    fn_1_A1588(lbl_1_bss_6EAD0.unk_0->unk_0, 0x1e);
}
/* fzgx:end fn_1_3DDAC */

/* fzgx:begin fn_1_3DE80 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"
#include "font.h"

typedef struct {
    f32 x, y, z;
} GameVec;
typedef u32 (*GameStepFn)(void);
typedef s32 (*GameModeFn)(void);
typedef struct {
    u32 unk_0;
    u8 pad_4[4];
    u8 unk_8;
    u8 unk_9;
    u8 pad_A[0x76];
    u8 unk_80;
    u8 unk_81;
    u8 unk_82;
    u8 unk_83;
    u8 pad_84[0x1C];
} GamePlayer;
typedef struct {
    u32 unk_0;
    u8 pad_4;
    u8 unk_5;
    u8 unk_6;
    u8 unk_7;
    u8 unk_8;
    u8 unk_9;
    u8 unk_A;
    u8 unk_B;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E[4];
    u8 pad_12[0xA4 - 0x12];
    u16 unk_A4;
    u8 unk_A6;
    u8 unk_A7;
    u8 pad_A8[4];
    GameStepFn unk_AC;
    GameStepFn unk_B0;
    GameStepFn unk_B4;
    u8 pad_B8[0x8];
    GameStepFn unk_C0;
    u32 unk_C4;
    GameStepFn unk_C8;
    GameModeFn unk_CC;
    u8 pad_D0[0x4];
    GamePlayer players[4];
    u8 pad_354[0x13F6 - 0x354];
    u8 unk_13F6;
    u8 pad_13F7[0x1474 - 0x13F7];
    u32 unk_1474;
    u16 unk_1478[4];
    u32 unk_1480[4];
    u8 pad_1490[0x14B8 - 0x1490];
} GameState;
typedef struct {
    u8 pad_0[4];
    u8 unk_4;
    u8 pad_5;
    u8 unk_6;
    u8 pad_7;
} GameSlotEntry;
typedef struct {
    GameSlotEntry entries[50];
    u8 unk_190;
    u8 unk_191;
    u8 unk_192;
    u8 pad_193;
    u8 unk_194[4];
} GameSlotTable;
typedef struct {
    u8 pad_0[3];
    u8 unk_3;
    u8 pad_4[0x2C];
} GameObj5108;
typedef struct {
    u8 pad_0[0xD8];
    f32 unk_D8;
    u8 pad_DC[0x475 - 0xDC];
    u8 unk_475;
    u8 pad_476[0x482 - 0x476];
    u8 unk_482;
    u8 pad_483[0x49C - 0x483];
    void *unk_49C;
} GameRacer;
typedef struct {
    u8 pad_0[0x1FC];
} GameRaceRecord;
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 fzgx_obj_lbl_1_bss_3C08;
s32 lbl_1_bss_3C08__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u8 fzgx_obj_lbl_1_bss_3C12;
u8 lbl_1_bss_3C12__fzgx_offset_1;
u8 lbl_1_bss_3C12__fzgx_offset_2[0x8];
u8 fzgx_obj_lbl_1_bss_3C1C[0xE];
s16 fzgx_obj_lbl_1_bss_3C2A;
u32 lbl_1_bss_3C2A__fzgx_offset_2;
GameState fzgx_obj_lbl_1_bss_3C30;
s16 lbl_1_bss_3C30__fzgx_offset_14B8[2];
u16 fzgx_obj_lbl_1_bss_50EC[0x8];
s16 lbl_1_bss_50EC__fzgx_offset_10;
u16 lbl_1_bss_50EC__fzgx_offset_12;
u32 fzgx_obj_lbl_1_bss_5100;
u8 fzgx_obj_lbl_1_bss_5104[0x4];
GameObj5108 lbl_1_bss_5104__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_5138[0x104];
u8 fzgx_obj_lbl_1_bss_523C[0x20];
GameSlotTable fzgx_obj_lbl_1_bss_525C;
u16 fzgx_obj_lbl_1_bss_53F4;
u8 fzgx_pool_gap_bss_53F6;
u8 fzgx_pool_gap_bss_53F7;
u32 fzgx_obj_lbl_1_bss_53F8[0x22];
u8 fzgx_obj_lbl_1_bss_5480[0x20700];
u16 fzgx_obj_lbl_1_bss_25B80;
u8 fzgx_pool_gap_bss_25B82;
u8 fzgx_pool_gap_bss_25B83;
u32 fzgx_obj_lbl_1_bss_25B84;
u32 fzgx_obj_lbl_1_bss_25B88[0x4];
u16 fzgx_obj_lbl_1_bss_25B98;
u8 fzgx_pool_gap_bss_25B9A;
u8 fzgx_pool_gap_bss_25B9B;
u32 fzgx_obj_lbl_1_bss_25B9C;
s32 fzgx_obj_lbl_1_bss_25BA0[0x2A];
u16 fzgx_obj_lbl_1_bss_25C48[0x2E];
u32 fzgx_obj_lbl_1_bss_25CA4[0xB];
u32 fzgx_obj_lbl_1_bss_25CD0[0x69];
u32 fzgx_obj_lbl_1_bss_25E74;
s32 lbl_1_bss_25E74__fzgx_offset_4[0x4];
s32 lbl_1_bss_25E74__fzgx_offset_14;
s32 lbl_1_bss_25E74__fzgx_offset_18;
u32 fzgx_obj_lbl_1_bss_25E90;
u32 lbl_1_bss_25E90__fzgx_offset_4;
u32 fzgx_obj_lbl_1_bss_25E98;
u16 fzgx_obj_lbl_1_bss_25E9C[0x1E0];
u8 fzgx_obj_lbl_1_bss_2625C[0x20];
u8 fzgx_obj_lbl_1_bss_2627C[0x78];
u8 fzgx_obj_lbl_1_bss_262F4;
u8 fzgx_pool_gap_bss_262F5;
u8 fzgx_pool_gap_bss_262F6;
u8 fzgx_pool_gap_bss_262F7;
u32 fzgx_obj_lbl_1_bss_262F8[0x2];
u16 fzgx_obj_lbl_1_bss_26300;
u8 fzgx_pool_gap_bss_26302;
u8 fzgx_pool_gap_bss_26303;
f32 fzgx_obj_lbl_1_bss_26304[0x4];
GameRaceRecord fzgx_obj_lbl_1_bss_26314[0x4];
u8 fzgx_obj_lbl_1_bss_26B04[0x10];
u32 lbl_1_bss_26B04__fzgx_offset_10;
u8 fzgx_obj_lbl_1_bss_26B18;
u8 fzgx_obj_lbl_1_bss_26B19;
u8 fzgx_obj_lbl_1_bss_26B1A;
u8 fzgx_pool_gap_bss_26B1B;
u8 fzgx_pool_gap_bss_26B1C;
u8 fzgx_obj_lbl_1_bss_26B1D;
u8 fzgx_obj_lbl_1_bss_26B1E;
u8 lbl_1_bss_26B1E__fzgx_offset_1;
u8 lbl_1_bss_26B1E__fzgx_offset_2[0x2C];
u32 fzgx_obj_lbl_1_bss_26B4C;
u32 fzgx_obj_lbl_1_bss_26B50;
u8 fzgx_obj_lbl_1_bss_26B54[0x8];
u8 fzgx_obj_lbl_1_bss_26B5C[0x1E];
u8 fzgx_obj_lbl_1_bss_26B7A;
u8 lbl_1_bss_26B7A__fzgx_offset_1;
u32 lbl_1_bss_26B7A__fzgx_offset_2;
u8 fzgx_obj_lbl_1_bss_26B80[0xA0];
u32 lbl_1_bss_26B80__fzgx_offset_A0;
u8 lbl_1_bss_26B80__fzgx_offset_A4[0x4];
u32 fzgx_obj_lbl_1_bss_26C28;
u32 fzgx_obj_lbl_1_bss_26C2C[0x2];
u32 fzgx_obj_lbl_1_bss_26C34[0x9];
u8 fzgx_obj_lbl_1_bss_26C58;
u8 fzgx_pool_gap_bss_26C59;
u8 fzgx_pool_gap_bss_26C5A;
u8 fzgx_pool_gap_bss_26C5B;
u32 fzgx_obj_lbl_1_bss_26C5C;
u32 fzgx_obj_lbl_1_bss_26C60;
u32 fzgx_obj_lbl_1_bss_26C64;
u16 fzgx_obj_lbl_1_bss_26C68[0x8AC6];
u8 fzgx_obj_lbl_1_bss_381F4;
u8 fzgx_obj_lbl_1_bss_381F5;
u8 fzgx_pool_gap_bss_381F6;
u8 fzgx_pool_gap_bss_381F7;
u32 fzgx_obj_lbl_1_bss_381F8;
u32 fzgx_obj_lbl_1_bss_381FC;
u8 fzgx_obj_lbl_1_bss_38200;
#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C00;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C04;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C08;
    s = *(u8 *)&lbl_1_bss_3C08__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C10;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C11;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C12;
    s = *(u8 *)&lbl_1_bss_3C12__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_3C12__fzgx_offset_2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C1C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C2A;
    s = *(u8 *)&lbl_1_bss_3C2A__fzgx_offset_2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C30;
    s = *(u8 *)&lbl_1_bss_3C30__fzgx_offset_14B8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_50EC;
    s = *(u8 *)&lbl_1_bss_50EC__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_50EC__fzgx_offset_12;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5100;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5104;
    s = *(u8 *)&lbl_1_bss_5104__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5138;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_523C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_525C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_53F4;
    s = *(u8 *)&fzgx_pool_gap_bss_53F6;
    s = *(u8 *)&fzgx_pool_gap_bss_53F7;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_53F8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5480;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25B80;
    s = *(u8 *)&fzgx_pool_gap_bss_25B82;
    s = *(u8 *)&fzgx_pool_gap_bss_25B83;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25B84;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25B88;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25B98;
    s = *(u8 *)&fzgx_pool_gap_bss_25B9A;
    s = *(u8 *)&fzgx_pool_gap_bss_25B9B;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25B9C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25BA0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25C48;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25CA4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25CD0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E74;
    s = *(u8 *)&lbl_1_bss_25E74__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_25E74__fzgx_offset_14;
    s = *(u8 *)&lbl_1_bss_25E74__fzgx_offset_18;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E90;
    s = *(u8 *)&lbl_1_bss_25E90__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E98;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_25E9C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_2625C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_2627C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_262F4;
    s = *(u8 *)&fzgx_pool_gap_bss_262F5;
    s = *(u8 *)&fzgx_pool_gap_bss_262F6;
    s = *(u8 *)&fzgx_pool_gap_bss_262F7;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_262F8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26300;
    s = *(u8 *)&fzgx_pool_gap_bss_26302;
    s = *(u8 *)&fzgx_pool_gap_bss_26303;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26304;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26314;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26B04;
    s = *(u8 *)&lbl_1_bss_26B04__fzgx_offset_10;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26B18;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26B19;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26B1A;
    s = *(u8 *)&fzgx_pool_gap_bss_26B1B;
    s = *(u8 *)&fzgx_pool_gap_bss_26B1C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26B1D;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26B1E;
    s = *(u8 *)&lbl_1_bss_26B1E__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_26B1E__fzgx_offset_2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26B4C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26B50;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26B54;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26B5C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26B7A;
    s = *(u8 *)&lbl_1_bss_26B7A__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_26B7A__fzgx_offset_2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26B80;
    s = *(u8 *)&lbl_1_bss_26B80__fzgx_offset_A0;
    s = *(u8 *)&lbl_1_bss_26B80__fzgx_offset_A4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26C28;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26C2C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26C34;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26C58;
    s = *(u8 *)&fzgx_pool_gap_bss_26C59;
    s = *(u8 *)&fzgx_pool_gap_bss_26C5A;
    s = *(u8 *)&fzgx_pool_gap_bss_26C5B;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26C5C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26C60;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26C64;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_26C68;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_381F4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_381F5;
    s = *(u8 *)&fzgx_pool_gap_bss_381F6;
    s = *(u8 *)&fzgx_pool_gap_bss_381F7;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_381F8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_381FC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_38200;
}
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 15.0f;
    s = 1.0f;
    s = 10.0f;
    s = 1.25f;
    s = 0.10000000149011612f;
    s = 0.8999999761581421f;
    s = 0.0006000000284984708f;
    s = 0.4000000059604645f;
    s = 0.75f;
    s = 70.0f;
    s = 0.5f;
    s = 36.0f;
    s = 16.0f;
    s = 45.0f;
    s = 0.0007999999797903001f;
    s = 18.0f;
    s = 50.0f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table5[52] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = 80.0f;
    s = 60.0f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table9[2] = {0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 470.0f;
    s = 0.0625f;
    s = 14.0f;
    s = 127.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table11[3] = {0x03E8FED4, 0xFE70FE0C, 0xFE0CFE0C};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 10000.0f;
    s = 15000.0f;
    s = 9999.0f;
}
static const u32 fzgx_pool_table13[2] = {0xFFFFFF00, 0x80808000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 240.0f;
    s = 280.0f;
    s = 200.0f;
    s = 40.0f;
    s = 30.0f;
}
static const u32 fzgx_pool_table15[8] = {0x80808000, 0xFFFFFF00, 0x80808000, 0xFFFFFF00, 0xFFFFFF00, 0x00000000, 0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.05000000074505806f;
    s = 0.15000000596046448f;
    s = 0.07999999821186066f;
    s = 2.0f;
    s = 4.0f;
    s = 255.0f;
    s = 1.100000023841858f;
    s = 38.0f;
    s = 20.0f;
    s = 180.0f;
    s = 3.0f;
    s = 0.00019999999494757503f;
    s = 100.0f;
    s = 75.0f;
    s = 0.00039999998989515007f;
    s = 150.0f;
}
static const u32 fzgx_pool_table17[7] = {0xFFF200FF, 0xFFF200FF, 0x80808080, 0xFFFFFF96, 0xFFF200FF, 0xFFF200FF, 0xFFFFFF96};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.009999999776482582f;
    s = 1000.0f;
    s = 2.8125f;
}
static const u32 fzgx_pool_table19[5] = {0x00000000, 0x80000000, 0x40000000, 0x20000000, 0x10000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const u32 *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 620.0f;
    s = 140.0f;
    s = 3000.0f;
    s = 0.00033333332976326346f;
    s = 0.30000001192092896f;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.6000000238418579f;
    s = 450.0f;
}
static const u32 fzgx_pool_table21[2] = {0x00000001, 0x00020003};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const u32 *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1100.0f;
    s = 1900.0f;
}
static const u32 fzgx_pool_table23[7] = {0x00000000, 0x40000000, 0x40000000, 0x40000000, 0x20000000, 0x20000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const u32 *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_color0[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_color0; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_color1[1] = {0x50000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const u32 *volatile cp; cp = fzgx_pool_color1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime26(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 600.0f;
    s = -60.0f;
    s = -1.0f;
    s = 35.0f;
    s = -11.0f;
    s = 3.5f;
    s = -10.0f;
    s = 640.0f;
    s = 480.0f;
    s = 6.5f;
}
#pragma section code_type ".text"
extern void fn_1_98590(void);
extern void fn_1_59290(void);
extern void fn_1_3FC68(s32);
extern void fn_1_DCF54(GameVec *, GameVec *, GameVec *);
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern s32 fn_1_402D4(void);
extern void fn_1_3F2A0(void);
extern void fn_1_4A00(s32, s32, u32);
extern void fn_1_469BC(void);
extern void fn_1_8DBA4(s32);
extern u32 lbl_1_rodata_26F8;

#define FN_1_3DE80_CLAMP(x) ((x) < 0.0f ? 0.0f : ((x) > 1.0f ? 1.0f : (x)))

void fn_1_3DE80(void)
{
    FontDrawPacket packet;
    GameVec eye;
    GameVec at;
    GameVec up;
    f32 t;
    s32 idx;
    GamePlayer *p;
    s32 k;
    u8 *pp;
    u8 *src;
    s32 i;
    GameState *gs;
    GameSlotEntry *e;
    s32 n;

    fn_1_98590();
    fn_1_59290();
    fn_1_3FC68(0);
    t = (f32)(s32)fzgx_obj_lbl_1_bss_26C28 / 600.0f;
    if (t > 1.0f) {
        t = 1.0f;
    }
    {
        f32 dx, dy, dz, ay, az;
        dx = -60.0f * t;
        dy = -1.0f * t;
        dz = -11.0f * t;
        ay = 3.5f * t;
        az = -10.0f * t;
        eye.x = 30.0f + dx;
        eye.y = 3.0f + dy;
        eye.z = 35.0f + dz;
        at.x = 16.0f;
        at.y = 0.5f + ay;
        at.z = 3.0f + az;
    }
    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
    fn_1_DCF54(&eye, &at, &up);
    if ((s32)++fzgx_obj_lbl_1_bss_26C28 > 1200) {
        fzgx_obj_lbl_1_bss_26C28 = 1200;
    }

    packet = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    packet.image = 0x12;
    packet.x = 320.0f;
    packet.y = 240.0f;
    packet.scale_x = packet.scale_x * (640.0f / (f32)fn_1_48690(0x12));
    packet.scale_y = packet.scale_y * (480.0f / (f32)fn_1_486C4(packet.image));
    *(u32 *)packet.color = fzgx_pool_color0[0];
    packet.flags = 10;
    packet.alpha = FN_1_3DE80_CLAMP(0.25f * (f32)((s32)fzgx_obj_lbl_1_bss_26C28 - 240) / 60.0f);
    packet.z = 60.0f;
    fn_1_4F734(&packet);

    packet = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    packet.image = 0x8A01;
    packet.x = 320.0f;
    packet.y = 240.0f;
    packet.scale_x *= 6.5f;
    packet.scale_y *= 3.0f;
    *(u32 *)packet.color = fzgx_pool_color1[0];
    packet.flags = 10;
    packet.alpha = FN_1_3DE80_CLAMP(0.25f * (f32)((s32)fzgx_obj_lbl_1_bss_26C28 - 240) / 60.0f);
    packet.z = 50.0f;
    fn_1_4F734(&packet);

    packet = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    packet.image = 0x8A00;
    packet.x = 320.0f;
    packet.y = 240.0f;
    packet.flags = 10;
    packet.alpha = FN_1_3DE80_CLAMP(0.5f * (f32)((s32)fzgx_obj_lbl_1_bss_26C28 - 60) / 60.0f);
    packet.z = 40.0f;
    fn_1_4F734(&packet);

    if (fzgx_obj_lbl_1_bss_25BA0[0] == 0 && (s32)fzgx_obj_lbl_1_bss_26C28 > 60 && fn_1_402D4() != 0 &&
        fzgx_obj_lbl_1_bss_25BA0[0] == 0) {
        gs = &fzgx_obj_lbl_1_bss_3C30;
        fzgx_obj_lbl_1_bss_53F4 = gs->unk_7;
        if (gs->unk_5 == 0) {
            for (i = 0; i < gs->unk_8; i++) {
                if (gs->unk_1480[i] != 0) {
                    if (!(fzgx_obj_lbl_1_bss_3C30.unk_0 & 0x00400000)) {
                        fn_1_3F2A0();
                        n = gs->unk_8;
                        src = fzgx_obj_lbl_1_bss_523C;
                        pp = (u8 *)gs;
                        for (k = 0; k < n; k++, pp += sizeof(GamePlayer), src++) {
                            p = ((GameState *)pp)->players;
                            if (fzgx_obj_lbl_1_bss_3C2A <= 0x29) {
                                idx = p->unk_83;
                            } else {
                                idx = p->unk_8;
                            }
                            (e = &fzgx_obj_lbl_1_bss_525C.entries[idx])->unk_4 = p->unk_80;
                            e->unk_6 = *src;
                            fzgx_obj_lbl_1_bss_525C.unk_194[idx] = k;
                        }
                        fzgx_obj_lbl_1_bss_525C.unk_192 = n;
                        fzgx_obj_lbl_1_bss_525C.unk_191 |= 2;
                        fzgx_obj_lbl_1_bss_525C.unk_190 = gs->unk_7;
                        fzgx_obj_lbl_1_bss_3C30.unk_0 |= 0x00400000;
                        fzgx_obj_lbl_1_bss_53F4 = 0xE;
                    }
                    break;
                }
            }
        }
        fn_1_4A00(0, 0x1E, fzgx_obj_lbl_1_bss_5100);
        lbl_1_bss_6EAB4.unk_0 |= 0x2C;
        fzgx_obj_lbl_1_bss_25BA0[0] = 1;
        if (gs->unk_5 == 0) {
            lbl_1_data_5B84 = 1;
        }
        fn_1_469BC();
        fn_1_8DBA4(0);
    }
}
/* fzgx:end fn_1_3DE80 */

/* fzgx:begin fn_1_3E5D0 */
// Resets both state objects and advances the game initialization sequence.
void fn_1_3E5D0(void) {
    fn_1_435C( (u32)((void *)lbl_1_bss_25B88.unk_0));
    fn_1_4310(0);
    fn_1_435C( (u32)((void *)lbl_1_bss_25CA4.unk_0));
    fn_1_4310(0);
    fn_1_4811C(0x8a);
    fn_1_A8F78();
}
/* fzgx:end fn_1_3E5D0 */

/* fzgx:begin fn_1_3E628 */
// fn_1_3E628: empty in retail (single blr).
void fn_1_3E628(void) {
}
/* fzgx:end fn_1_3E628 */

/* fzgx:begin fn_1_3E62C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"

typedef struct Sig_ADXT_Pause_AdxSjdHandle Sig_ADXT_Pause_AdxSjdHandle;

typedef struct Sig_ADXT_Pause_ADXStream Sig_ADXT_Pause_ADXStream;

typedef struct Sig_ADXT_Pause_AXRNAHandle Sig_ADXT_Pause_AXRNAHandle;

typedef struct Sig_ADXT_Pause_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Pause_SJCK;

typedef void (*Sig_ADXT_Pause_SJErrorCallback)(void *object, int error);

typedef struct Sig_ADXT_Pause_SJInterface Sig_ADXT_Pause_SJInterface;

typedef struct Sig_ADXT_Pause_SJ Sig_ADXT_Pause_SJ;

struct Sig_ADXT_Pause_SJ {
    const Sig_ADXT_Pause_SJInterface *interface;
};

struct Sig_ADXT_Pause_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Pause_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Pause_SJ *sj);
    void (*reset)(Sig_ADXT_Pause_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, int max_size, Sig_ADXT_Pause_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, Sig_ADXT_Pause_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, Sig_ADXT_Pause_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Pause_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Pause_SJ *sj, Sig_ADXT_Pause_SJErrorCallback callback, void *object);
};

typedef struct Sig_ADXT_Pause_ADX_AMP Sig_ADXT_Pause_ADX_AMP;

typedef struct Sig_ADXT_Pause_LSCObject Sig_ADXT_Pause_LSCObject;

typedef struct Sig_ADXT_Pause_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Pause_AdxSjdHandle *decoder;
    Sig_ADXT_Pause_ADXStream *stream;
    Sig_ADXT_Pause_AXRNAHandle *rna;
    Sig_ADXT_Pause_SJ *stream_sj;
    Sig_ADXT_Pause_SJ *input_sj;
    Sig_ADXT_Pause_SJ *output_sj[2];
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
    Sig_ADXT_Pause_ADX_AMP *amplifier;
    Sig_ADXT_Pause_SJ *amplifier_input[2];
    Sig_ADXT_Pause_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Pause_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Pause_ADXTHandle;

typedef struct Sig_ADXT_Stop_AdxSjdHandle Sig_ADXT_Stop_AdxSjdHandle;

typedef struct Sig_ADXT_Stop_ADXStream Sig_ADXT_Stop_ADXStream;

typedef struct Sig_ADXT_Stop_AXRNAHandle Sig_ADXT_Stop_AXRNAHandle;

typedef struct Sig_ADXT_Stop_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK;

typedef void (*Sig_ADXT_Stop_SJErrorCallback)(void *object, int error);

typedef struct Sig_ADXT_Stop_SJInterface Sig_ADXT_Stop_SJInterface;

typedef struct Sig_ADXT_Stop_SJ Sig_ADXT_Stop_SJ;

struct Sig_ADXT_Stop_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ *sj);
    void (*reset)(Sig_ADXT_Stop_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};

struct Sig_ADXT_Stop_SJ {
    const Sig_ADXT_Stop_SJInterface *interface;
};

typedef struct Sig_ADXT_Stop_ADX_AMP Sig_ADXT_Stop_ADX_AMP;

typedef struct Sig_ADXT_Stop_LSCObject Sig_ADXT_Stop_LSCObject;

typedef struct Sig_ADXT_Stop_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Stop_AdxSjdHandle *decoder;
    Sig_ADXT_Stop_ADXStream *stream;
    Sig_ADXT_Stop_AXRNAHandle *rna;
    Sig_ADXT_Stop_SJ *stream_sj;
    Sig_ADXT_Stop_SJ *input_sj;
    Sig_ADXT_Stop_SJ *output_sj[2];
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
    Sig_ADXT_Stop_ADX_AMP *amplifier;
    Sig_ADXT_Stop_SJ *amplifier_input[2];
    Sig_ADXT_Stop_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Stop_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Stop_ADXTHandle;

typedef struct {
    u8 unk[0xb];
    u8 value;
} Entry;

typedef struct {
    u8 pad_0[2];
    s16 unk_2;
    u8 pad_4[8];
    u32 unk_C;
    u8 pad_10[0x10];
} Obj_1_bss_25E9C;

typedef struct {
    u8 pad[0x2f8];
    u32 value_2f8;
    u32 value_2fc;
    u32 value_300;
    u32 value_304;
    u32 value_308;
    u32 value_30c;
    u32 value_310;
    u32 value_314;
    u32 value_318;
    u32 value_31c;
} Fn40710Config;
extern void fn_1_15E330(s32 index, u32 value, void *arg);
extern void fn_1_15E5E4(s32 index, void *arg);
extern void fn_1_15E688(s32 index, u32 value, u8 state, void *arg);
extern void fn_1_15E3E0(s32 index, u32 value);
extern void fn_1_15E434(u32 value);
extern void fn_1_15E540(s32 index, void *arg);
extern void fn_1_CB404(u8 value);
extern void fn_1_D07C4(u32 arg0, u32 arg1);
extern u32 lbl_1_bss_25B84;
extern u32 OSGetTick(void);
extern void fn_1_A0978(void);
extern void fn_1_35174(void);
extern s32 fn_1_3EFA8(void);
extern u16 lbl_1_bss_26B7A[3];
extern u16 lbl_1_bss_26300;
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern u32 fn_1_101C0(void);
extern u32 fn_1_A11EC(void);
extern u32 fn_1_435C(u32 value);
extern void ADXT_Pause(Sig_ADXT_Pause_ADXTHandle *, s32);
extern void fn_1_4310(u32 arg0);
extern void fn_1_48004(s32 index, s32 image);
extern void fn_1_8616C(void);
extern void fn_1_A1588(u32 arg0, u32 arg1);
extern void fn_1_D0790(void);
extern void fn_1_817C0(void);
extern u32 lbl_1_bss_381FC;
extern void fn_1_EB080(int mode);
extern s64 OSGetTime(void);
extern void fn_1_4A00(u32 arg0, u32 arg1, u32 arg2);
extern void fn_1_5370(u32 arg0, u32 arg1);
extern void fn_1_15E27C(void);
extern void fn_1_4811C(int arg);
extern void fn_1_A8F78(void);
extern u8 lbl_1_bss_262F4;
extern u32 lbl_1_bss_25E74[7];
extern u8 lbl_1_bss_3C10;
extern void fn_1_36330(void);
extern void fn_1_36B10(void);
extern void fn_1_3C98(void);
extern void fn_1_37AA8(void);
extern void fn_1_37E98(void);
extern f32 lbl_1_bss_26304[4];
extern u8 lbl_1_bss_26B04[20];
extern u8 lbl_1_bss_26314[2032];
extern s16 fn_1_12EF24(s16 row, s16 column);
extern u8 lbl_1_bss_523C[32];
extern Entry *lbl_1_bss_53F8[34];
extern void OSPanic(const void *, u32, const char *, ...);
extern Obj_1_bss_25E9C lbl_1_bss_25E9C[30];
extern void fn_1_12AB38(void *arg0);
extern void fn_1_465D0(char *value, u32 flag);
extern void* fn_1_7F518(s16 car_type, void* car, s32 initialize);
extern int sprintf(char *s, const char *format, ...);
extern void fn_1_451E4(void);
extern void fn_1_D3214(void);
extern void VIWaitForRetrace(void);
extern u32 fn_1_467F4(void);
extern u32 fn_1_13018(void);
extern u32 fn_1_46C60(void);
extern u32 lbl_1_bss_26C2C[2];
extern u32 lbl_1_bss_262F8[2];
extern u16 lbl_1_bss_26C68[35526];
extern u32 lbl_1_bss_3C08[2];
extern u32 fn_800075AC(u32, u32, u32);
extern u32 ghost_test_record_flag0(s32 arg);
extern u32 fn_1_F9D44(u32 arg);
extern u8 fn_1_F8C50(s32 arg0);
extern void fn_1_2DB50(void);
extern void fn_1_3F8C(void *, void *, Obj_1_bss_5138 *, int);
extern void fn_1_2D888(void);
extern void fn_1_2D524(void);
extern u32 fn_1_FA070(void);
extern int fn_1_FA180(int, u8);
extern u32 fn_1_F9FEC(void);
extern void fn_1_A2DC4(u32 arg0);
extern Fn40710Config lbl_1_rodata_BD8;
extern u8 lbl_1_bss_26B54[8];
extern u32 fn_1_40EE4(void);
extern u32 lbl_801A63D0;
extern u32 lbl_1_bss_26C34[9];
extern u8 lbl_1_bss_38218[568];
extern u32 fn_1_4060(void);
extern void ARQPostRequest(u8 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, u32 arg7);
extern u32 lbl_801A63C0;
extern void fn_1_40BE4(void);
extern u32 GXGetTexBufferSize(u32, u32, u32, u32, u32);
extern u32 lbl_1_bss_26B4C;
extern u8 lbl_1_bss_25E90[8];
extern s32 fn_1_48B0(u32 arg0, u32 arg1);
extern void fn_1_40F54(void *arg0);
extern u32 lbl_801A6CE0;
extern u32 lbl_1_bss_38454;
extern u32 fn_80070DE0(u32 arg0);
extern void fn_1_D3884();
extern void fn_1_D358C();
extern void fn_800711A8(Obj_1_bss_38458_Target *target);
extern void fn_80071718(u32 value);
extern void fn_1_41134(void *unused, char *value);
extern void fn_1_411D4(u32, char *);
extern int DVDConvertPathToEntrynum(char *buffer);
extern void fn_1_412A0(u32 index);
extern size_t strlen(const char *str);
extern int fn_80083BCC(const char *s1, const char *s2);
extern u8 lbl_1_A9011300;
extern u8 lbl_1_A9011100;
extern u8 lbl_1_A9011000;

void fn_1_3E62C(void) {
    if ((s32)lbl_1_bss_25BA0.unk_0 == 0) {
        lbl_1_bss_53F4 = 0xD;
        lbl_1_bss_6EAB4.unk_0 |= 0x2C;
        lbl_1_bss_25BA0.unk_0 = 1;
    }
}
/* fzgx:end fn_1_3E62C */

/* fzgx:begin fn_1_3E66C */
// fn_1_3E66C: empty in retail (single blr).
void fn_1_3E66C(void) {
}
/* fzgx:end fn_1_3E66C */

/* fzgx:begin fn_1_3E670 */
void fn_1_3E670(void) {
    fn_1_4A00(1, 0x1e, lbl_1_bss_5100);
    lbl_1_bss_26C28 = 0;
    fn_1_D0790();
    lbl_1_bss_3C30.unk_0 |= 8;
    lbl_1_bss_6EAB4.unk_0 |= 0x2c;
}
/* fzgx:end fn_1_3E670 */

/* fzgx:begin fn_1_3EA70 */
void fn_1_3EA70(void) {
    fn_1_A8F78();
}
/* fzgx:end fn_1_3EA70 */

/* fzgx:begin fn_1_3EA90 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"

typedef struct Sig_ADXT_Pause_AdxSjdHandle Sig_ADXT_Pause_AdxSjdHandle;

typedef struct Sig_ADXT_Pause_ADXStream Sig_ADXT_Pause_ADXStream;

typedef struct Sig_ADXT_Pause_AXRNAHandle Sig_ADXT_Pause_AXRNAHandle;

typedef struct Sig_ADXT_Pause_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Pause_SJCK;

typedef void (*Sig_ADXT_Pause_SJErrorCallback)(void *object, int error);

typedef struct Sig_ADXT_Pause_SJInterface Sig_ADXT_Pause_SJInterface;

typedef struct Sig_ADXT_Pause_SJ Sig_ADXT_Pause_SJ;

struct Sig_ADXT_Pause_SJ {
    const Sig_ADXT_Pause_SJInterface *interface;
};

struct Sig_ADXT_Pause_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Pause_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Pause_SJ *sj);
    void (*reset)(Sig_ADXT_Pause_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, int max_size, Sig_ADXT_Pause_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, Sig_ADXT_Pause_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, Sig_ADXT_Pause_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Pause_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Pause_SJ *sj, Sig_ADXT_Pause_SJErrorCallback callback, void *object);
};

typedef struct Sig_ADXT_Pause_ADX_AMP Sig_ADXT_Pause_ADX_AMP;

typedef struct Sig_ADXT_Pause_LSCObject Sig_ADXT_Pause_LSCObject;

typedef struct Sig_ADXT_Pause_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Pause_AdxSjdHandle *decoder;
    Sig_ADXT_Pause_ADXStream *stream;
    Sig_ADXT_Pause_AXRNAHandle *rna;
    Sig_ADXT_Pause_SJ *stream_sj;
    Sig_ADXT_Pause_SJ *input_sj;
    Sig_ADXT_Pause_SJ *output_sj[2];
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
    Sig_ADXT_Pause_ADX_AMP *amplifier;
    Sig_ADXT_Pause_SJ *amplifier_input[2];
    Sig_ADXT_Pause_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Pause_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Pause_ADXTHandle;

typedef struct Sig_ADXT_Stop_AdxSjdHandle Sig_ADXT_Stop_AdxSjdHandle;

typedef struct Sig_ADXT_Stop_ADXStream Sig_ADXT_Stop_ADXStream;

typedef struct Sig_ADXT_Stop_AXRNAHandle Sig_ADXT_Stop_AXRNAHandle;

typedef struct Sig_ADXT_Stop_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK;

typedef void (*Sig_ADXT_Stop_SJErrorCallback)(void *object, int error);

typedef struct Sig_ADXT_Stop_SJInterface Sig_ADXT_Stop_SJInterface;

typedef struct Sig_ADXT_Stop_SJ Sig_ADXT_Stop_SJ;

struct Sig_ADXT_Stop_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ *sj);
    void (*reset)(Sig_ADXT_Stop_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};

struct Sig_ADXT_Stop_SJ {
    const Sig_ADXT_Stop_SJInterface *interface;
};

typedef struct Sig_ADXT_Stop_ADX_AMP Sig_ADXT_Stop_ADX_AMP;

typedef struct Sig_ADXT_Stop_LSCObject Sig_ADXT_Stop_LSCObject;

typedef struct Sig_ADXT_Stop_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Stop_AdxSjdHandle *decoder;
    Sig_ADXT_Stop_ADXStream *stream;
    Sig_ADXT_Stop_AXRNAHandle *rna;
    Sig_ADXT_Stop_SJ *stream_sj;
    Sig_ADXT_Stop_SJ *input_sj;
    Sig_ADXT_Stop_SJ *output_sj[2];
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
    Sig_ADXT_Stop_ADX_AMP *amplifier;
    Sig_ADXT_Stop_SJ *amplifier_input[2];
    Sig_ADXT_Stop_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Stop_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Stop_ADXTHandle;

typedef struct {
    u8 unk[0xb];
    u8 value;
} Entry;

typedef struct {
    u8 pad_0[2];
    s16 unk_2;
    u8 pad_4[8];
    u32 unk_C;
    u8 pad_10[0x10];
} Obj_1_bss_25E9C;

typedef struct {
    u8 pad[0x2f8];
    u32 value_2f8;
    u32 value_2fc;
    u32 value_300;
    u32 value_304;
    u32 value_308;
    u32 value_30c;
    u32 value_310;
    u32 value_314;
    u32 value_318;
    u32 value_31c;
} Fn40710Config;
extern void fn_1_15E330(s32 index, u32 value, void *arg);
extern void fn_1_15E5E4(s32 index, void *arg);
extern void fn_1_15E688(s32 index, u32 value, u8 state, void *arg);
extern void fn_1_15E3E0(s32 index, u32 value);
extern void fn_1_15E434(u32 value);
extern void fn_1_15E540(s32 index, void *arg);
extern void fn_1_CB404(u8 value);
extern void fn_1_D07C4(u32 arg0, u32 arg1);
extern u32 lbl_1_bss_25B84;
extern u32 OSGetTick(void);
extern void fn_1_A0978(void);
extern void fn_1_35174(void);
extern s32 fn_1_3EFA8(void);
extern u16 lbl_1_bss_26B7A[3];
extern u16 lbl_1_bss_26300;
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern u32 fn_1_101C0(void);
extern u32 fn_1_A11EC(void);
extern u32 fn_1_435C(u32 value);
extern void ADXT_Pause(Sig_ADXT_Pause_ADXTHandle *, s32);
extern void fn_1_4310(u32 arg0);
extern void fn_1_48004(s32 index, s32 image);
extern void fn_1_8616C(void);
extern void fn_1_A1588(u32 arg0, u32 arg1);
extern void fn_1_D0790(void);
extern void fn_1_817C0(void);
extern u32 lbl_1_bss_381FC;
extern void fn_1_EB080(int mode);
extern s64 OSGetTime(void);
extern void fn_1_4A00(u32 arg0, u32 arg1, u32 arg2);
extern void fn_1_5370(u32 arg0, u32 arg1);
extern void fn_1_15E27C(void);
extern void fn_1_4811C(int arg);
extern void fn_1_A8F78(void);
extern u8 lbl_1_bss_262F4;
extern u32 lbl_1_bss_25E74[7];
extern u8 lbl_1_bss_3C10;
extern void fn_1_36330(void);
extern void fn_1_36B10(void);
extern void fn_1_3C98(void);
extern void fn_1_37AA8(void);
extern void fn_1_37E98(void);
extern f32 lbl_1_bss_26304[4];
extern u8 lbl_1_bss_26B04[20];
extern u8 lbl_1_bss_26314[2032];
extern s16 fn_1_12EF24(s16 row, s16 column);
extern u8 lbl_1_bss_523C[32];
extern Entry *lbl_1_bss_53F8[34];
extern void OSPanic(const void *, u32, const char *, ...);
extern Obj_1_bss_25E9C lbl_1_bss_25E9C[30];
extern void fn_1_12AB38(void *arg0);
extern void fn_1_465D0(char *value, u32 flag);
extern void* fn_1_7F518(s16 car_type, void* car, s32 initialize);
extern int sprintf(char *s, const char *format, ...);
extern void fn_1_451E4(void);
extern void fn_1_D3214(void);
extern void VIWaitForRetrace(void);
extern u32 fn_1_467F4(void);
extern u32 fn_1_13018(void);
extern u32 fn_1_46C60(void);
extern u32 lbl_1_bss_26C2C[2];
extern u32 lbl_1_bss_262F8[2];
extern u16 lbl_1_bss_26C68[35526];
extern u32 lbl_1_bss_3C08[2];
extern u32 fn_800075AC(u32, u32, u32);
extern u32 ghost_test_record_flag0(s32 arg);
extern u32 fn_1_F9D44(u32 arg);
extern u8 fn_1_F8C50(s32 arg0);
extern void fn_1_2DB50(void);
extern void fn_1_3F8C(void *, void *, Obj_1_bss_5138 *, int);
extern void fn_1_2D888(void);
extern void fn_1_2D524(void);
extern u32 fn_1_FA070(void);
extern int fn_1_FA180(int, u8);
extern u32 fn_1_F9FEC(void);
extern void fn_1_A2DC4(u32 arg0);
extern Fn40710Config lbl_1_rodata_BD8;
extern u8 lbl_1_bss_26B54[8];
extern u32 fn_1_40EE4(void);
extern u32 lbl_801A63D0;
extern u32 lbl_1_bss_26C34[9];
extern u8 lbl_1_bss_38218[568];
extern u32 fn_1_4060(void);
extern void ARQPostRequest(u8 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, u32 arg7);
extern u32 lbl_801A63C0;
extern void fn_1_40BE4(void);
extern u32 GXGetTexBufferSize(u32, u32, u32, u32, u32);
extern u32 lbl_1_bss_26B4C;
extern u8 lbl_1_bss_25E90[8];
extern s32 fn_1_48B0(u32 arg0, u32 arg1);
extern void fn_1_40F54(void *arg0);
extern u32 lbl_801A6CE0;
extern u32 lbl_1_bss_38454;
extern u32 fn_80070DE0(u32 arg0);
extern void fn_1_D3884();
extern void fn_1_D358C();
extern void fn_800711A8(Obj_1_bss_38458_Target *target);
extern void fn_80071718(u32 value);
extern void fn_1_41134(void *unused, char *value);
extern void fn_1_411D4(u32, char *);
extern int DVDConvertPathToEntrynum(char *buffer);
extern void fn_1_412A0(u32 index);
extern size_t strlen(const char *str);
extern int fn_80083BCC(const char *s1, const char *s2);
extern u8 lbl_1_A9011300;
extern u8 lbl_1_A9011100;
extern u8 lbl_1_A9011000;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_1_bss_3C00[4];
u32 fzgx_obj_lbl_1_bss_3C04;
u32 fzgx_obj_lbl_1_bss_3C08[2];
u8 fzgx_obj_lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u8 fzgx_obj_lbl_1_bss_3C12;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b5;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b7;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b8;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b9;
u32 fzgx_obj_lbl_1_bss_3C1C;
u8 lbl_1_bss_3C1C__fzgx_offset_4[10];
u8 fzgx_obj_lbl_1_bss_3C2A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b5;
u32 fzgx_obj_lbl_1_bss_3C30[1327];
u32 fzgx_obj_lbl_1_bss_50EC[5];
u32 fzgx_obj_lbl_1_bss_5100;
u32 fzgx_obj_lbl_1_bss_5104[13];
u32 fzgx_obj_lbl_1_bss_5138[65];
u8 fzgx_obj_lbl_1_bss_523C[0x20];
u32 fzgx_obj_lbl_1_bss_525C[102];
u16 fzgx_obj_lbl_1_bss_53F4;
u32 fzgx_obj_lbl_1_bss_53F8[34];
u32 fzgx_obj_lbl_1_bss_5480[33216];
u16 fzgx_obj_lbl_1_bss_25B80;
u32 fzgx_obj_lbl_1_bss_25B84;
u32 fzgx_obj_lbl_1_bss_25B88[4];
u16 fzgx_obj_lbl_1_bss_25B98;
u32 fzgx_obj_lbl_1_bss_25B9C;
u32 fzgx_obj_lbl_1_bss_25BA0[42];
u16 fzgx_obj_lbl_1_bss_25C48[0x2E];
u32 fzgx_obj_lbl_1_bss_25CA4[11];
u32 fzgx_obj_lbl_1_bss_25CD0[105];
u32 fzgx_obj_lbl_1_bss_25E74[7];
u32 fzgx_obj_lbl_1_bss_25E90[2];
u8 fzgx_obj_lbl_1_bss_25E98[1];
u32 fzgx_obj_lbl_1_bss_25E9C[240];
u8 fzgx_obj_lbl_1_bss_2625C[0x20];
u32 fzgx_obj_lbl_1_bss_2627C[30];
u8 fzgx_obj_lbl_1_bss_262F4;
u32 fzgx_obj_lbl_1_bss_262F8[2];
u16 fzgx_obj_lbl_1_bss_26300;
u32 fzgx_obj_lbl_1_bss_26304[4];
u32 fzgx_obj_lbl_1_bss_26314[508];
u32 fzgx_obj_lbl_1_bss_26B04[5];
u8 fzgx_obj_lbl_1_bss_26B18;
u8 fzgx_obj_lbl_1_bss_26B19;
u8 fzgx_obj_lbl_1_bss_26B1A;
u8 fzgx_pool_fzgx_pad_26B1B;
u8 fzgx_pool_fzgx_pad_26B1C;
u8 fzgx_obj_lbl_1_bss_26B1D;
u8 fzgx_obj_lbl_1_bss_26B1E;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b42;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b43;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b44;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b45;
u32 fzgx_obj_lbl_1_bss_26B4C;
u32 fzgx_obj_lbl_1_bss_26B50;
u32 fzgx_obj_lbl_1_bss_26B54[2];
u8 fzgx_obj_lbl_1_bss_26B5C[30];
u8 fzgx_obj_lbl_1_bss_26B7A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
u8 lbl_1_bss_26B7A__fzgx_offset_2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
u32 fzgx_obj_lbl_1_bss_26B80[42];
u32 fzgx_obj_lbl_1_bss_26C28;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_3C00[0];
    s = fzgx_obj_lbl_1_bss_3C04;
    s = fzgx_obj_lbl_1_bss_3C08[0];
    s = fzgx_obj_lbl_1_bss_3C10;
    s = fzgx_obj_lbl_1_bss_3C11;
    s = fzgx_obj_lbl_1_bss_3C12;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b5;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b7;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b8;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b9;
    s = fzgx_obj_lbl_1_bss_3C1C;
    s = lbl_1_bss_3C1C__fzgx_offset_4[0];
    s = fzgx_obj_lbl_1_bss_3C2A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b5;
    s = fzgx_obj_lbl_1_bss_3C30[0];
    s = fzgx_obj_lbl_1_bss_50EC[0];
    s = fzgx_obj_lbl_1_bss_5100;
    s = fzgx_obj_lbl_1_bss_5104[0];
    s = fzgx_obj_lbl_1_bss_5138[0];
    s = fzgx_obj_lbl_1_bss_523C[0];
    s = fzgx_obj_lbl_1_bss_525C[0];
    s = fzgx_obj_lbl_1_bss_53F4;
    s = fzgx_obj_lbl_1_bss_53F8[0];
    s = fzgx_obj_lbl_1_bss_5480[0];
    s = fzgx_obj_lbl_1_bss_25B80;
    s = fzgx_obj_lbl_1_bss_25B84;
    s = fzgx_obj_lbl_1_bss_25B88[0];
    s = fzgx_obj_lbl_1_bss_25B98;
    s = fzgx_obj_lbl_1_bss_25B9C;
    s = fzgx_obj_lbl_1_bss_25BA0[0];
    s = fzgx_obj_lbl_1_bss_25C48[0];
    s = fzgx_obj_lbl_1_bss_25CA4[0];
    s = fzgx_obj_lbl_1_bss_25CD0[0];
    s = fzgx_obj_lbl_1_bss_25E74[0];
    s = fzgx_obj_lbl_1_bss_25E90[0];
    s = fzgx_obj_lbl_1_bss_25E98[0];
    s = fzgx_obj_lbl_1_bss_25E9C[0];
    s = fzgx_obj_lbl_1_bss_2625C[0];
    s = fzgx_obj_lbl_1_bss_2627C[0];
    s = fzgx_obj_lbl_1_bss_262F4;
    s = fzgx_obj_lbl_1_bss_262F8[0];
    s = fzgx_obj_lbl_1_bss_26300;
    s = fzgx_obj_lbl_1_bss_26304[0];
    s = fzgx_obj_lbl_1_bss_26314[0];
    s = fzgx_obj_lbl_1_bss_26B04[0];
    s = fzgx_obj_lbl_1_bss_26B18;
    s = fzgx_obj_lbl_1_bss_26B19;
    s = fzgx_obj_lbl_1_bss_26B1A;
    s = fzgx_pool_fzgx_pad_26B1B;
    s = fzgx_pool_fzgx_pad_26B1C;
    s = fzgx_obj_lbl_1_bss_26B1D;
    s = fzgx_obj_lbl_1_bss_26B1E;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b42;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b43;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b44;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b45;
    s = fzgx_obj_lbl_1_bss_26B4C;
    s = fzgx_obj_lbl_1_bss_26B50;
    s = fzgx_obj_lbl_1_bss_26B54[0];
    s = fzgx_obj_lbl_1_bss_26B5C[0];
    s = fzgx_obj_lbl_1_bss_26B7A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
    s = lbl_1_bss_26B7A__fzgx_offset_2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
    s = fzgx_obj_lbl_1_bss_26B80[0];
    s = fzgx_obj_lbl_1_bss_26C28;
}
#pragma section code_type ".text"

void fn_1_3EA90(u8 count, u8 *name_src, u8 *code_src, u32 *value_src) {
    u8 slot = fzgx_obj_lbl_1_bss_3C00[0];
    s32 i;

    for (i = 0; i < count; i++) {
        fzgx_obj_lbl_1_bss_2625C[slot + i] = name_src[i];
        if (code_src == NULL || code_src[i] == 0xFF) {
            fzgx_obj_lbl_1_bss_523C[slot + i] = 0x10;
        } else {
            fzgx_obj_lbl_1_bss_523C[slot + i] = code_src[i];
        }
        if (value_src == NULL) {
            fzgx_obj_lbl_1_bss_2627C[slot + i] = 0;
        } else {
            fzgx_obj_lbl_1_bss_2627C[slot + i] = value_src[i];
        }
        fzgx_obj_lbl_1_bss_25C48[slot + i] = 50;
    }
    lbl_1_bss_26B7A__fzgx_offset_2 = count;
}
/* fzgx:end fn_1_3EA90 */

/* fzgx:begin fn_1_3EB78 noprologue */
#include "types.h"

typedef struct GameState30 {
    u32 flags;
    u8 pad_4[4];
    u8 unk_8;
    u8 pad_9[0x14B3];
} GameState30;

typedef struct GameEntrant {
    u8 unk_0;
    u8 name;
    u8 letter;
    u8 pad_3[9];
} GameEntrant;

typedef struct GamePlayer {
    u32 unk_0;
    GameEntrant entrant;
    u8 pad_10[0x81B0];
} GamePlayer;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_1_bss_3C00[4];
u32 fzgx_obj_lbl_1_bss_3C04;
u32 fzgx_obj_lbl_1_bss_3C08[2];
u8 fzgx_obj_lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u8 fzgx_obj_lbl_1_bss_3C12;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b5;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b7;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b8;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b9;
u32 fzgx_obj_lbl_1_bss_3C1C;
u8 lbl_1_bss_3C1C__fzgx_offset_4[10];
u8 fzgx_obj_lbl_1_bss_3C2A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b5;
GameState30 fzgx_obj_lbl_1_bss_3C30;
u32 fzgx_obj_lbl_1_bss_50EC[5];
u32 fzgx_obj_lbl_1_bss_5100;
u32 fzgx_obj_lbl_1_bss_5104[13];
u32 fzgx_obj_lbl_1_bss_5138[65];
u8 fzgx_obj_lbl_1_bss_523C[0x20];
u32 fzgx_obj_lbl_1_bss_525C[102];
u16 fzgx_obj_lbl_1_bss_53F4;
void *fzgx_obj_lbl_1_bss_53F8[34];
u32 fzgx_obj_lbl_1_bss_5480[33216];
u16 fzgx_obj_lbl_1_bss_25B80;
u32 fzgx_obj_lbl_1_bss_25B84;
u32 fzgx_obj_lbl_1_bss_25B88[4];
u16 fzgx_obj_lbl_1_bss_25B98;
u32 fzgx_obj_lbl_1_bss_25B9C;
u32 fzgx_obj_lbl_1_bss_25BA0[42];
u16 fzgx_obj_lbl_1_bss_25C48[0x2E];
u32 fzgx_obj_lbl_1_bss_25CA4[11];
u32 fzgx_obj_lbl_1_bss_25CD0[105];
u32 fzgx_obj_lbl_1_bss_25E74[7];
u32 fzgx_obj_lbl_1_bss_25E90[2];
u8 fzgx_obj_lbl_1_bss_25E98[4];
u32 fzgx_obj_lbl_1_bss_25E9C[240];
u8 fzgx_obj_lbl_1_bss_2625C[0x20];
u32 fzgx_obj_lbl_1_bss_2627C[30];
u8 fzgx_obj_lbl_1_bss_262F4;
u32 fzgx_obj_lbl_1_bss_262F8[2];
u16 fzgx_obj_lbl_1_bss_26300;
u32 fzgx_obj_lbl_1_bss_26304[4];
u32 fzgx_obj_lbl_1_bss_26314[508];
u32 fzgx_obj_lbl_1_bss_26B04[5];
u8 fzgx_obj_lbl_1_bss_26B18;
u8 fzgx_obj_lbl_1_bss_26B19;
u8 fzgx_obj_lbl_1_bss_26B1A;
u8 fzgx_pool_fzgx_pad_26B1B;
u8 fzgx_pool_fzgx_pad_26B1C;
u8 fzgx_obj_lbl_1_bss_26B1D;
u8 fzgx_obj_lbl_1_bss_26B1E;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b42;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b43;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b44;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b45;
u32 fzgx_obj_lbl_1_bss_26B4C;
u32 fzgx_obj_lbl_1_bss_26B50;
u32 fzgx_obj_lbl_1_bss_26B54[2];
u8 fzgx_obj_lbl_1_bss_26B5C[30];
u8 fzgx_obj_lbl_1_bss_26B7A;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b2;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
u8 fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
u32 fzgx_obj_lbl_1_bss_26B80[42];
u32 fzgx_obj_lbl_1_bss_26C28;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_3C00[0];
    s = fzgx_obj_lbl_1_bss_3C04;
    s = fzgx_obj_lbl_1_bss_3C08[0];
    s = fzgx_obj_lbl_1_bss_3C10;
    s = fzgx_obj_lbl_1_bss_3C11;
    s = fzgx_obj_lbl_1_bss_3C12;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b5;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b7;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b8;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C12__b9;
    s = fzgx_obj_lbl_1_bss_3C1C;
    s = lbl_1_bss_3C1C__fzgx_offset_4[0];
    s = fzgx_obj_lbl_1_bss_3C2A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_3C2A__b5;
    s = fzgx_obj_lbl_1_bss_3C30.flags;
    s = fzgx_obj_lbl_1_bss_50EC[0];
    s = fzgx_obj_lbl_1_bss_5100;
    s = fzgx_obj_lbl_1_bss_5104[0];
    s = fzgx_obj_lbl_1_bss_5138[0];
    s = fzgx_obj_lbl_1_bss_523C[0];
    s = fzgx_obj_lbl_1_bss_525C[0];
    s = fzgx_obj_lbl_1_bss_53F4;
    s = *(u32 *)fzgx_obj_lbl_1_bss_53F8;
    s = fzgx_obj_lbl_1_bss_5480[0];
    s = fzgx_obj_lbl_1_bss_25B80;
    s = fzgx_obj_lbl_1_bss_25B84;
    s = fzgx_obj_lbl_1_bss_25B88[0];
    s = fzgx_obj_lbl_1_bss_25B98;
    s = fzgx_obj_lbl_1_bss_25B9C;
    s = fzgx_obj_lbl_1_bss_25BA0[0];
    s = fzgx_obj_lbl_1_bss_25C48[0];
    s = fzgx_obj_lbl_1_bss_25CA4[0];
    s = fzgx_obj_lbl_1_bss_25CD0[0];
    s = fzgx_obj_lbl_1_bss_25E74[0];
    s = fzgx_obj_lbl_1_bss_25E90[0];
    s = fzgx_obj_lbl_1_bss_25E98[0];
    s = fzgx_obj_lbl_1_bss_25E9C[0];
    s = fzgx_obj_lbl_1_bss_2625C[0];
    s = fzgx_obj_lbl_1_bss_2627C[0];
    s = fzgx_obj_lbl_1_bss_262F4;
    s = fzgx_obj_lbl_1_bss_262F8[0];
    s = fzgx_obj_lbl_1_bss_26300;
    s = fzgx_obj_lbl_1_bss_26304[0];
    s = fzgx_obj_lbl_1_bss_26314[0];
    s = fzgx_obj_lbl_1_bss_26B04[0];
    s = fzgx_obj_lbl_1_bss_26B18;
    s = fzgx_obj_lbl_1_bss_26B19;
    s = fzgx_obj_lbl_1_bss_26B1A;
    s = fzgx_pool_fzgx_pad_26B1B;
    s = fzgx_pool_fzgx_pad_26B1C;
    s = fzgx_obj_lbl_1_bss_26B1D;
    s = fzgx_obj_lbl_1_bss_26B1E;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b5;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b6;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b7;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b8;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b9;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b10;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b11;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b12;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b13;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b14;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b15;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b16;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b17;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b18;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b19;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b20;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b21;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b22;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b23;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b24;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b25;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b26;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b27;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b28;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b29;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b30;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b31;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b32;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b33;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b34;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b35;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b36;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b37;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b38;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b39;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b40;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b41;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b42;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b43;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b44;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B1E__b45;
    s = fzgx_obj_lbl_1_bss_26B4C;
    s = fzgx_obj_lbl_1_bss_26B50;
    s = fzgx_obj_lbl_1_bss_26B54[0];
    s = fzgx_obj_lbl_1_bss_26B5C[0];
    s = fzgx_obj_lbl_1_bss_26B7A;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b1;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b2;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b3;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b4;
    s = fzgx_pool_fzgx_obj_lbl_1_bss_26B7A__b5;
    s = fzgx_obj_lbl_1_bss_26B80[0];
    s = fzgx_obj_lbl_1_bss_26C28;
}
#pragma section code_type ".text"

extern u8 lbl_1_bss_8B3A0[];

void fn_1_3EB78(u8 count, u8 *names, u8 *codes, u32 *values) {
    s32 i;
    s32 n;

    n = 0;
    for (i = 0; n < count && i < 4; i++) {
        if (names[i] == 0xFF) {
            continue;
        }
        fzgx_obj_lbl_1_bss_2625C[n] = names[i];
        if (codes == NULL || codes[i] == 0xFF) {
            fzgx_obj_lbl_1_bss_523C[n] = 1;
        } else {
            fzgx_obj_lbl_1_bss_523C[n] = codes[i];
        }
        if (values == NULL) {
            fzgx_obj_lbl_1_bss_2627C[n] = 0;
        } else {
            fzgx_obj_lbl_1_bss_2627C[n] = values[i];
        }
        fzgx_obj_lbl_1_bss_25E98[n] = i;
        fzgx_obj_lbl_1_bss_25C48[n] = lbl_1_bss_8B3A0[0x9F + i];
        n++;
    }
    fzgx_obj_lbl_1_bss_3C00[0] = n;
    fzgx_obj_lbl_1_bss_3C30.unk_8 = n;
}
/* fzgx:end fn_1_3EB78 */

/* fzgx:begin fn_1_3EF08 */
void fn_1_3EF08(u8 value) {
    lbl_1_bss_262F4 = value;
}
/* fzgx:end fn_1_3EF08 */

/* fzgx:begin fn_1_3EF14 */
static inline s16 current_mode(void) {
    return *(s16 *)&lbl_1_bss_960;
}

// Selects the appropriate buffer initialization based on the current mode.
void fn_1_3EF14(void *arg1) {
    if (lbl_1_bss_3C12.unk_0 != 0 ||
        (u16)(current_mode() - 13) <= 1 ||
        current_mode() == 10 ||
        current_mode() == 16) {
        fn_80008BA8( (u32)(void *)(arg1), (u32)(void *)(&lbl_1_bss_3C30), 0x14b8);
    } else {
        fn_80008BEC(arg1, (int)(void *)(0), 0x14b8);
    }
}
/* fzgx:end fn_1_3EF14 */

/* fzgx:begin fn_1_3EF8C */
// Stores the value unless initialization has already occurred.
void fn_1_3EF8C(u8 value) {
    if (lbl_1_bss_3C12.unk_0 == 0) {
        lbl_1_data_5B7C = value;
    }
}
/* fzgx:end fn_1_3EF8C */

/* fzgx:begin fn_1_3EFA8 */
typedef struct MainRelState {
    u8 pad_0000[0x12];
    u8 unk_12;
    u8 pad_0013[0x1D];
    s32 unk_30;
    u8 pad_0034[0x14C4];
    s32 unk_14F8;
} MainRelState;

// Reports whether the relevant state is active and enabled.
s32 fn_1_3EFA8(void) {
    s32 result = 0;
    MainRelState *state = (MainRelState *)&lbl_1_bss_3C00;

    if (state->unk_14F8 != 0 ||
        (state->unk_30 & 2) != 0 ||
        (s32)lbl_1_bss_26B50 != 0) {
        if (state->unk_12 != 0) {
            result = 1;
        }
    }
    return result;
}
/* fzgx:end fn_1_3EFA8 */

/* fzgx:begin fn_1_3EFF0 */
void fn_1_3EFF0(u32 arg1, u8 arg2) {
    lbl_1_bss_25E74[0] = arg1;
    lbl_1_bss_3C10 = arg2;
    lbl_1_bss_3C11 = 1;
    lbl_1_bss_26C58 = 0;
    lbl_1_bss_26C64 = 0;
}
/* fzgx:end fn_1_3EFF0 */

/* fzgx:begin fn_1_3F02C */
void fn_1_3F02C(u32 arg1) {
    lbl_1_bss_26C64 = arg1;
}
/* fzgx:end fn_1_3F02C */

/* fzgx:begin fn_1_3F038 */
// Initializes the game state and reports whether startup has completed.
int fn_1_3F038(void) {
    if (lbl_1_bss_26C58 != 0) {
        return 1;
    }

    if (lbl_1_bss_3C11 != 0) {
        fn_1_36330();
        lbl_1_bss_3C11 = 0;
    }

    fn_1_36B10();
    fn_1_3C98();
    if ((lbl_1_bss_3C30.unk_0 & 4) == 0) {
        fn_1_37AA8();
    }

    if (lbl_1_bss_26C58 != 0) {
        fn_1_37E98();
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_3F038 */

/* fzgx:begin fn_1_3F0C8 */
s16 fn_1_3F0C8(void) {
    return lbl_1_bss_3C2A;
}
/* fzgx:end fn_1_3F0C8 */

/* fzgx:begin fn_1_3F0D8 */
u8 *fn_1_3F0D8(u32 index, f32 *value, u8 *flag) {
    u8 idx = (u8)index;
    *value = lbl_1_bss_26304[idx];
    *flag = lbl_1_bss_26B04[idx];
    return &lbl_1_bss_26314[idx * 0x1fc];
}
/* fzgx:end fn_1_3F0D8 */

/* fzgx:begin fn_1_3F114 */
// Returns the current global status byte when the subsystem is enabled.
u8 fn_1_3F114(void) {
    if (lbl_1_bss_3C12.unk_0 != 0) {
        return lbl_1_bss_3C30.unk_4;
    }
    return 0;
}
/* fzgx:end fn_1_3F114 */

/* fzgx:begin fn_1_3F13C */
u8 fn_1_3F13C(void) {
    if (lbl_1_bss_3C12.unk_0 != 0) {
        return lbl_1_bss_3C30.unk_5;
    }
    return 0xff;
}
/* fzgx:end fn_1_3F13C */

/* fzgx:begin fn_1_3F164 */
typedef struct {
    u8 unk_00[0x12];
    u8 unk_12;
    u8 unk_13[0x1d];
    s32 unk_30;
    u8 unk_34[0x14c4];
    s32 unk_14f8;
} MainState;

// Reports whether the active state permits the current mode.
s32 fn_1_3F164(void) {
    s32 result = 0;
    MainState *state = (MainState *)&lbl_1_bss_3C00;

    if (state->unk_14f8 != 0 ||
        (state->unk_30 & 2) != 0 ||
        (s32)lbl_1_bss_26B50 != 0) {
        if (state->unk_12 != 0) {
            result = 1;
        }
    }
    return result;
}
/* fzgx:end fn_1_3F164 */

/* fzgx:begin fn_1_3F1AC */
u32 fn_1_3F1AC(u32 arg0) {
    u32 v0;
    v0 = arg0;
    if ((*(u8 *)&lbl_1_bss_3C12) == 0) {
    v0 = 0;
    return v0;
    }
    return (((*(u32 (*)[])&lbl_1_bss_3C30)[0] >> 1) & 0x1);
}
/* fzgx:end fn_1_3F1AC */

/* fzgx:begin fn_1_3F1D4 */
// Return the stored status byte when the game state is initialized.
s32 fn_1_3F1D4(void) {
    if (lbl_1_bss_3C30.unk_5 == 1) {
        return lbl_1_bss_3C30.unk_13F6;
    }
    return -1;
}
/* fzgx:end fn_1_3F1D4 */

/* fzgx:begin fn_1_3F1F8 */
u8 fn_1_3F1F8(void) {
    if (lbl_1_bss_3C30.unk_A6 != 0xff) {
        return fn_1_12EF24(lbl_1_bss_3C30.unk_A6, lbl_1_bss_3C30.unk_A7);
    }
    return lbl_1_bss_3C30.unk_6;
}
/* fzgx:end fn_1_3F1F8 */

/* fzgx:begin fn_1_3F23C */
// Reads the byte selected by the low eight bits of the index.
u8 fn_1_3F23C(u32 index) {
    u8 *table = &lbl_1_bss_2625C.unk_0;

    return table[index & 0xff];
}
/* fzgx:end fn_1_3F23C */

/* fzgx:begin fn_1_3F250 */
u8 fn_1_3F250(u32 index) {
    return lbl_1_bss_523C[index & 0xff];
}
/* fzgx:end fn_1_3F250 */

/* fzgx:begin fn_1_3F264 */
// Return the stored entry byte, or the indexed fallback when no entry exists.
u8 fn_1_3F264(u32 index) {
    u32 masked = index & 0xff;
    Entry *entry = lbl_1_bss_53F8[masked];

    if (entry != 0) {
        return entry->value;
    }

    return (u8)(&lbl_1_bss_25C48.unk_0)[masked];
}
/* fzgx:end fn_1_3F264 */

/* fzgx:begin fn_1_3F2A0 noprologue */
#include "types.h"

typedef struct {
    u32 unk_0;
    u16 unk_4;
    u8 pad_6[2];
    u8 unk_8;
    u8 pad_9[0x7A];
    u8 unk_83;
    u8 pad_84[0x1A];
    u16 unk_9E;
} fn_1_3F2A0_rec;

typedef struct {
    u8 pad_0[5];
    u8 unk_5;
    u8 pad_6[2];
    u8 unk_8;
    u8 unk_9;
    u8 pad_A[4];
    u8 ids[0x99];
    u8 unk_A7;
    u8 pad_A8[0x2C];
    fn_1_3F2A0_rec rec[30];
    u8 ord[0x20];
    u8 pad_13B4[0xC4];
    u16 pair[4];
    u32 score[0xC];
} fn_1_3F2A0_obj;

extern fn_1_3F2A0_obj lbl_1_bss_3C30;

void fn_1_3F2A0(void)
{
    s32 lim = !lbl_1_bss_3C30.unk_5 ? (s32)lbl_1_bss_3C30.unk_8 : (s32)lbl_1_bss_3C30.unk_9;
    u8 mode;
    s32 kid;
    s32 j;
    s32 i = 0;
    s32 k;
    s32 id;
    s32 cnt;
    s32 score;
    s32 other;
    fn_1_3F2A0_rec *p;

    for (j = 0; j < lim; i++, j++) {
        if (!lbl_1_bss_3C30.unk_5) {
            while (lbl_1_bss_3C30.ids[i] >= lim) {
                i++;
            }
        }
        id = lbl_1_bss_3C30.ids[i];
        cnt = 0;
        p = &lbl_1_bss_3C30.rec[id];
        if (!lbl_1_bss_3C30.unk_5) {
            score = lbl_1_bss_3C30.score[id];
            p->unk_4 = score;
            p->unk_9E = lbl_1_bss_3C30.pair[id];
        } else {
            score = p->unk_4;
        }
        mode = lbl_1_bss_3C30.unk_5;
        for (k = 0; k < lbl_1_bss_3C30.unk_9; k++) {
            if (i == k) {
                continue;
            }
            kid = lbl_1_bss_3C30.ids[k];
            if (!mode) {
                if (kid >= lim) {
                    continue;
                }
                other = lbl_1_bss_3C30.score[kid];
            } else {
                other = lbl_1_bss_3C30.rec[kid].unk_4;
            }
            if (score < other) {
                cnt++;
            } else if (score == other && i > k) {
                cnt++;
            }
        }
        lbl_1_bss_3C30.ord[cnt] = id;
        p->unk_8 = cnt;
        if (!lbl_1_bss_3C30.unk_A7 && lbl_1_bss_3C30.unk_5) {
            p->unk_83 = cnt;
        }
    }
}
/* fzgx:end fn_1_3F2A0 */

/* fzgx:begin fn_1_3F440 */
// Reports an out-of-range index and returns the corresponding limit when valid.
s32 fn_1_3F440(u8 index) {
    u8 *limits;

    if (index > 0x1d) {
        OSPanic(&lbl_1_data_62EC, 0x2654, (const char *)lbl_1_data_65E8);
    }

    limits = (u8 *)&lbl_1_bss_3C30.unk_0;
    if (lbl_1_bss_3C30.unk_8 > limits[index + 14]) {
        return limits[index + 14];
    }

    return -1;
}
/* fzgx:end fn_1_3F440 */

/* fzgx:begin fn_1_3F4B8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"

extern u32 lbl_1_bss_26C5C;

typedef struct lbl_1_bss_3C30_t {
    u8 pad_0[0x13f8];
    u16 unk_13F8;
    u16 unk_13FA;
    u16 unk_13FC;
    u16 unk_13FE;
    u16 unk_1400;
    u8 unk_1402;
    u8 pad_1403[0xb9];
} lbl_1_bss_3C30_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
lbl_1_bss_3C30_t fzgx_obj_lbl_1_bss_3C30;
u32 fzgx_obj_lbl_1_bss_50EC[5];
u32 fzgx_obj_lbl_1_bss_5100;
u32 fzgx_obj_lbl_1_bss_5104[13];
u32 fzgx_obj_lbl_1_bss_5138[65];
u32 lbl_1_bss_523C[8];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C30;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_50EC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5100;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5104;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5138;
    s = *(u8 *)&lbl_1_bss_523C;
}
#pragma section code_type ".text"

void fn_1_3F4B8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5)
{
    fzgx_obj_lbl_1_bss_3C30.unk_13F8 = arg0 * 60;
    fzgx_obj_lbl_1_bss_3C30.unk_1402 = arg5;
    fzgx_obj_lbl_1_bss_3C30.unk_13FA = arg1 * 60;
    fzgx_obj_lbl_1_bss_3C30.unk_13FC = arg2 * 60;
    fzgx_obj_lbl_1_bss_3C30.unk_13FE = arg3 * 60;
    fzgx_obj_lbl_1_bss_3C30.unk_1400 = arg4 * 60;
    lbl_1_bss_26C5C = 1;
}
/* fzgx:end fn_1_3F4B8 */

/* fzgx:begin fn_1_3F4FC */
void fn_1_3F4FC(void) {
    u8 *dp;
    s16 i;
    s32 mode;
    u32 flags;
    char buffer[0x20];
    char temp[0x20];

    dp = (u8 *)&lbl_1_data_5730;
    fn_1_12AB38(dp + 0xce4);
    fn_1_465D0( (char *)(void *)(dp + 0xcf0), 1);

    i = 0;
    while (i < lbl_1_bss_3C30.unk_9) {
        flags = lbl_1_bss_25E9C[i].unk_C;
        mode = 0;
        if (flags & 0x100000) {
            mode = 1;
        }

        if (flags & 0xf0000000) {
            sprintf(buffer, (const char *)(dp + 0xd00), (s32)fn_1_7F518(lbl_1_bss_25E9C[i].unk_2, temp, mode));
        } else {
            sprintf(buffer, (const char *)(dp + 0xd0c), (s32)fn_1_7F518(lbl_1_bss_25E9C[i].unk_2, temp, mode));
        }

        fn_1_465D0( (char *)(void *)(buffer), 1);
        i++;
    }

    fn_1_12AB38(dp + 0xd18);
}
/* fzgx:end fn_1_3F4FC */

/* fzgx:begin fn_1_3F5F8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"

extern s32 fn_1_465D0(s32, s32);
extern s32 fn_1_12D254(s32, s32);
extern void *fn_1_7F518(s16, void *, s32);
extern u32 fn_1_7F58C(s16, void *, u8, s32);
extern void fn_80006E10(void *);
extern u32 lbl_1_rodata_E88[11];

#pragma opt_propagation off
#pragma peephole on
static inline s32 *fn_1_3F5F8_array_read(s32 *array) { return array; }
void fn_1_3F5F8(void) {
    Obj_1_bss_3C30 *mgr = &lbl_1_bss_3C30;
    s16 n;
    struct { s32 value; } t;
    s8 eq;
    s8 i;
    s16 j;
    s32 val;
    s16 mode;
    s32 c;
    s32 tbl[5];
    u32 buf1[16];
    s32 buf2[17];
    s32 lab_t0;
    s32 k;

    t.value = 4;
    eq = (mgr->unk_8 == 1);
    if (eq) {
        t.value = 0;
    }
    n = (s16)t.value;
    tbl[0] = lbl_1_rodata_E88[0];
    tbl[1] = lbl_1_rodata_E88[1];
    tbl[2] = lbl_1_rodata_E88[2];
    tbl[3] = lbl_1_rodata_E88[3];
    tbl[4] = lbl_1_rodata_E88[4];
    val = fn_1_3F5F8_array_read(tbl)[mgr->unk_8];
    mode = *(s16 *)&lbl_1_bss_960;
    if (mode == 10 || mode == 12) {
        return;
    }
    {
        for (i = 0, k = 0; i < mgr->unk_8; k++, i++) {
            c = ((s8 *)&lbl_1_bss_2625C)[k];
            if (c <= 40) {
                fn_1_465D0(fn_1_12D254(c, val), 1);
                fn_80006E10(lbl_1_data_6414);
                fn_80006E10(fn_1_7F518(c, buf2, 0));
                for (j = n; j <= n + 3; j++) {
                    lab_t0 = fn_1_7F58C(c, buf1, (u8)j, 0);
                    fn_1_465D0(lab_t0, 1);
                }
                fn_80006E10(&lbl_1_data_6600);
            }
        }
    }
}
#pragma peephole reset
#pragma opt_propagation reset
/* fzgx:end fn_1_3F5F8 */

/* fzgx:begin fn_1_3F75C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"

extern void fn_1_451E4(void);
extern void fn_1_D3214(void);
extern void VIWaitForRetrace(void);
extern s32 fn_1_467F4(void);
extern s32 fn_1_13018(void);

void fn_1_3F75C(void) {
    while (fn_1_467F4() || fn_1_13018()) {
        fn_1_451E4();
        fn_1_D3214();
        VIWaitForRetrace();
    }
}
/* fzgx:end fn_1_3F75C */

/* fzgx:begin fn_1_3F7A0 */
void fn_1_3F7A0(u32* self) {
    self[0] = fn_1_46C60();
}
/* fzgx:end fn_1_3F7A0 */

/* fzgx:begin fn_1_3F7D0 */
u32 fn_1_3F7D0(void) {
    return lbl_1_bss_26C28;
}
/* fzgx:end fn_1_3F7D0 */

/* fzgx:begin fn_1_3F7E0 */
// Selects the mode-specific byte from the shared game state.
u8 fn_1_3F7E0(void) {
    if (lbl_1_bss_3C30.unk_0 & 0x00008000) {
        return lbl_1_bss_3C30.unk_9;
    }
    return lbl_1_bss_3C30.pad_A[0];
}
/* fzgx:end fn_1_3F7E0 */

/* fzgx:begin fn_1_3F800 */
// Stores the value in the shared game state.
void fn_1_3F800(u32 value) {
    lbl_1_bss_3C30.unk_1464 = value;
}
/* fzgx:end fn_1_3F800 */

/* fzgx:begin fn_1_3F810 */
// Stores a value and its scaled companion in the shared game state.
void fn_1_3F810(u8 value, u32 input) {
    lbl_1_bss_3C30.unk_146C = value;
    lbl_1_bss_3C30.unk_146D = (u8)((input / 5) >> 1);
}
/* fzgx:end fn_1_3F810 */

/* fzgx:begin fn_1_3F834 */
// Stores the byte value in the shared game state.
void fn_1_3F834(u8 value) {
    lbl_1_bss_3C30.unk_1470 = value;
}
/* fzgx:end fn_1_3F834 */

/* fzgx:begin fn_1_3F844 */
// Store the current 16-bit value in the shared game state.
void fn_1_3F844(u16 value) {
    lbl_1_bss_3C30.unk_146E = value;
}
/* fzgx:end fn_1_3F844 */

/* fzgx:begin fn_1_3F854 */
// Return the current game-state byte.
u8 fn_1_3F854(void) {
    return lbl_1_bss_3C30.unk_8;
}
/* fzgx:end fn_1_3F854 */

/* fzgx:begin fn_1_3F864 */
// Reports whether the game is in the guarded state or mode 0x000c.
u8 fn_1_3F864(void) {
    if ((lbl_1_bss_3C30.unk_0 & 0x00100000) != 0 ||
        *(s16 *)&lbl_1_bss_960 == 0x000c) {
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_3F864 */

/* fzgx:begin fn_1_3F894 */
// Enables the associated game state and records the current mode.
void fn_1_3F894(void) {
    lbl_1_bss_53F4 = lbl_1_bss_3C30.unk_7;
    lbl_1_bss_25BA0.unk_0 = 1;
    lbl_1_bss_26C2C[0] = 1;
}
/* fzgx:end fn_1_3F894 */

/* fzgx:begin fn_1_3F8C0 */
u32 fn_1_3F8C0(void) {
    return lbl_1_bss_262F8[0];
}
/* fzgx:end fn_1_3F8C0 */

/* fzgx:begin fn_1_3F8D0 */
void fn_1_3F8D0(void) {
    u16 *values = (u16 *)&lbl_1_bss_38204;

    values[0] = 0;
    values[1] = 0;
    values[2] = 0;
    values[3] = 0;
}
/* fzgx:end fn_1_3F8D0 */

/* fzgx:begin fn_1_3F8EC noprologue */
#include "types.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"
#include "rel/main_rel/game.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 15.0f;
    s = 1.0f;
    s = 10.0f;
    s = 1.25f;
    s = 0.10000000149011612f;
    s = 0.8999999761581421f;
    s = 0.0006000000284984708f;
    s = 0.4000000059604645f;
    s = 0.75f;
    s = 70.0f;
    s = 0.5f;
    s = 36.0f;
    s = 16.0f;
    s = 45.0f;
    s = 0.0007999999797903001f;
    s = 18.0f;
    s = 50.0f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table5[52] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = 80.0f;
    s = 60.0f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table9[2] = {0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 470.0f;
    s = 0.0625f;
    s = 14.0f;
    s = 127.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table11[3] = {0x03E8FED4, 0xFE70FE0C, 0xFE0CFE0C};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 10000.0f;
    s = 15000.0f;
    s = 9999.0f;
}
static const u32 fzgx_pool_table13[2] = {0xFFFFFF00, 0x80808000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 240.0f;
    s = 280.0f;
    s = 200.0f;
    s = 40.0f;
    s = 30.0f;
}
static const u32 fzgx_pool_table15[8] = {0x80808000, 0xFFFFFF00, 0x80808000, 0xFFFFFF00, 0xFFFFFF00, 0x00000000, 0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.05000000074505806f;
    s = 0.15000000596046448f;
    s = 0.07999999821186066f;
    s = 2.0f;
    s = 4.0f;
    s = 255.0f;
    s = 1.100000023841858f;
    s = 38.0f;
    s = 20.0f;
    s = 180.0f;
    s = 3.0f;
    s = 0.00019999999494757503f;
    s = 100.0f;
    s = 75.0f;
    s = 0.00039999998989515007f;
    s = 150.0f;
}
static const u32 fzgx_pool_table17[7] = {0xFFF200FF, 0xFFF200FF, 0x80808080, 0xFFFFFF96, 0xFFF200FF, 0xFFF200FF, 0xFFFFFF96};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.009999999776482582f;
    s = 1000.0f;
    d = 20.0;
}
static const u32 fzgx_pool_table19[4] = {0x80000000, 0x40000000, 0x20000000, 0x10000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const u32 *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 620.0f;
    s = 140.0f;
    s = 3000.0f;
    s = 0.00033333332976326346f;
    s = 0.30000001192092896f;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.6000000238418579f;
    s = 450.0f;
}
static const u32 fzgx_pool_table21[2] = {0x00000001, 0x00020003};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const u32 *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1100.0f;
    s = 1900.0f;
}
static const u32 fzgx_pool_table23[9] = {0x00000000, 0x40000000, 0x40000000, 0x40000000, 0x20000000, 0x20000000, 0x00000000, 0x00000000, 0x50000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const u32 *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 600.0f;
    s = -60.0f;
    s = -1.0f;
    s = 35.0f;
    s = -11.0f;
    s = 3.5f;
    s = -10.0f;
    s = 640.0f;
    s = 480.0f;
    s = 6.5f;
}
static const u32 fzgx_pool_table25[6] = {0x40000000, 0x40000000, 0x40000000, 0x20000000, 0x20000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const u32 *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime26(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 1000000.0f;
    s = -0.10000000149011612f;
    s = -2.0f;
}
static const u32 fzgx_pool_table27[1] = {0x00B500B6};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep27(void) { const u32 *volatile cp; cp = fzgx_pool_table27; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct {
    f32 x, y, z;
} Vec3;

typedef struct {
    u32 unk_0;
    u8 pad_4[0x78];
    Vec3 unk_7c;
    u8 pad_88[0x64];
    s32 unk_ec;
    u8 pad_f0[0x124];
    u16 unk_214;
} ObjA;

typedef struct {
    u8 pad_0[0x50];
    Vec3 unk_50;
} ObjB;

typedef struct {
    u8 pad_0[0x4];
    f32 unk_4;
    u8 pad_8[0x48];
    f64 unk_50;
    u8 pad_58[0xE0];
    f64 unk_138;
    u8 pad_140[0x10];
    f32 unk_150;
    u8 pad_154[0x80];
    f32 unk_1d4;
    u8 pad_1D8[0xB8];
    f32 unk_290;
    u8 pad_294[0x34];
    f64 unk_2c8;
    f32 unk_2d0;
    f32 unk_2d4;
    f32 unk_2d8;
} PoolObj;

extern const f32 lbl_1_rodata_BD8;
extern u32 lbl_801A66A0;
extern u32 lbl_801A6D00;
extern u32 lbl_1_bss_38460[21];

extern s32 camera_get_flags(void);
extern u32 camera_get_status(void);
extern u32 fn_1_5910(void);
extern u32 camera_get_entry_field_0x2(u32);
extern void *fn_1_86254(s32);
extern void *fn_1_8627C(s32);
extern u32 lbl_8006DBAC(void *);
extern f32 lbl_8006D6FC(void *, void *);
extern u32 lbl_8006DCA4(void);
extern u32 lbl_8006E1B0(void *, void *);
extern void fn_8006EF10(void *, s16 *, s16 *);
extern u32 lbl_8006D7F4(f32, f32, f32);
extern u32 lbl_8006DB74(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 lbl_8006D24C(f32, f32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void fn_8006E294(void *);
extern void fn_80072558(void);
extern void fn_1_55FF0(f32);
extern void fn_1_56018(s32);
extern void fn_1_560F0(s32, u32);
extern void fn_1_556B8(void *);

#pragma opt_dead_assignments off
#pragma opt_common_subs off
#pragma opt_propagation off
void fn_1_3F8EC(f32 arg0) {
    f32 fzgx_live;
    f32 *fzgx_value;
    s32 e;
    ObjA *a;
    u32 id;
    ObjB *b;
    PoolObj *p = (PoolObj *)&lbl_1_rodata_BD8;
    s32 cnt;
    u16 tmp;
    s32 d;
    s16 xa;
    s16 ya;
    Vec3 vec;
    f32 q2;
    f32 q1;

    if (camera_get_flags() == 0 && (s16)camera_get_status() == 1 && lbl_1_bss_3C2A < 42) {
        id = fn_1_5910();
        e = camera_get_entry_field_0x2((u8)id);
        if ((s16)e != -1) {
            a = (ObjA *)fn_1_86254((s16)e);
            if (a != 0 && (a->unk_0 & 0x800) == 0) {
                b = (ObjB *)fn_1_8627C((s16)e);
                if (b != 0) {
                    lbl_8006DBAC(&a->unk_ec);
                    fzgx_value = &vec.x;
                    {
                        f32 sc = (-1.0f);
                        /* Read the transformed matrix's Z column from Gekko locked cache. */
                        f32 q0 = *(f32 *)(LC_BASE + 0x8);
                        q1 = *(f32 *)(LC_BASE + 0x18);
                        q2 = *(f32 *)(LC_BASE + 0x28);
                        *fzgx_value = q0 * sc;
                        vec.y = q1 * sc;
                        vec.z = q2 * sc;
                    }
                    if (a->unk_214 == 0 &&
                        lbl_8006D6FC(&vec, &b->unk_50) < 0.5) {
                        if (((u16 *)&lbl_1_bss_38204)[id] < 110) {
                            ((u16 *)&lbl_1_bss_38204)[id] += 1;
                        }
                    } else if (((u16 *)&lbl_1_bss_38204)[id] != 0) {
                        ((u16 *)&lbl_1_bss_38204)[id] -= 1;
                    }
                    tmp = ((u16 *)&lbl_1_bss_38204)[id];
                    d = tmp - 60;
                    if (d < 0) {
                        cnt = 0;
                    } else {
                        cnt = 20;
                        if (d <= 20) {
                            cnt = d;
                        }
                    }
                    if (cnt != 0) {
                        psvec_scale(&b->unk_50, (1000000.0f), &vec.x);
                        psvec_add(&a->unk_7c, &vec.x, &vec.x);
                        lbl_8006DCA4();
                        lbl_8006E1B0(&vec, &vec);
                        fn_8006EF10(&vec, &xa, &ya);
                        lbl_8006D7F4((0.0f), (f32)(lbl_801A66A0 % 15) / (14.0f), (0.0f));
                        lbl_8006DB74(lbl_801A6D00 + 0x60);
                        lbl_8006D7F4((0.0f), (-0.100000001f), (-2.0f));
                        mathutil_mtxA_rotate_y(ya);
                        mathutil_mtxA_rotate_x(xa);
                        fn_8006E294(&vec);
                        fzgx_live = vec.x;
                        mathutil_mtxA_rotate_z((s16)-lbl_8006D24C(fzgx_live, vec.y));
                        fn_80072558();
                        if (cnt < 20) {
                            fn_1_55FF0((f32)cnt / (20.0f));
                        }
                        fn_1_56018(1);
                        fn_1_560F0(0, lbl_801A6D00 + 0x60);
                        fn_1_556B8(*(void **)((u8 *)(*(u32 **)((u8 *)(*(u32 *)((u8 *)lbl_1_bss_38460 + 8)) + 8)) + 0x108));
                        fn_1_56018(0);
                    }
                }
            }
        }
    }
}
#pragma opt_propagation reset

#pragma opt_common_subs reset

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_3F8EC */

/* fzgx:begin fn_1_3FBF4 */
void fn_1_3FBF4(u32 arg0) {
    u32 v0;
    v0 = ((*(u32 *)&lbl_1_bss_3C30) & 0xFFFFFFFD);
    if ((s32)arg0 != 0) {
    v0 = ((*(u32 *)&lbl_1_bss_3C30) | 2);
    }
    (*(u32 *)&lbl_1_bss_3C30) = v0;
}
/* fzgx:end fn_1_3FBF4 */

/* fzgx:begin fn_1_3FC18 */
u16 fn_1_3FC18(void) {
    return lbl_1_bss_26C68[0];
}
/* fzgx:end fn_1_3FC18 */

/* fzgx:begin fn_1_3FC28 */
u32 fn_1_3FC28(void) {
    return lbl_1_bss_3C30.unk_0 & 0x00800000;
}
/* fzgx:end fn_1_3FC28 */

/* fzgx:begin fn_1_3FC38 */
u8 fn_1_3FC38(void) {
    return lbl_1_bss_3C12.unk_0;
}
/* fzgx:end fn_1_3FC38 */

/* fzgx:begin fn_1_3FC48 */
u32 fn_1_3FC48(void) {
    return lbl_1_bss_3C30.unk_0 & 0x100;
}
/* fzgx:end fn_1_3FC48 */

/* fzgx:begin fn_1_3FC58 */
u32 fn_1_3FC58(void) {
    return lbl_1_bss_3C30.unk_0 & 0x01000000;
}
/* fzgx:end fn_1_3FC58 */

/* fzgx:begin fn_1_3FC68 */
// Toggles the 0x02000000 status flag according to the requested state.
void fn_1_3FC68(s32 enabled) {
    lbl_1_bss_3C30.unk_0 = enabled != 0
        ? lbl_1_bss_3C30.unk_0 & ~0x02000000
        : lbl_1_bss_3C30.unk_0 | 0x02000000;
}
/* fzgx:end fn_1_3FC68 */

/* fzgx:begin fn_1_3FC8C */
// Return the global state flag stored in bit 6 of the control word.
u32 fn_1_3FC8C(void) {
    return lbl_1_bss_3C30.unk_0 & 0x02000000;
}
/* fzgx:end fn_1_3FC8C */

/* fzgx:begin fn_1_3FC9C */
 // Return the low byte of the signed global status field.
u32 fn_1_3FC9C(void) {
    return (u32)lbl_1_bss_8B3A0.unk_8 & 0xff;
}
/* fzgx:end fn_1_3FC9C */

/* fzgx:begin fn_1_3FCB0 */
static inline u32 fn_1_3FCB0_operand(u32 left, u32 right) { left &= right; return left; }
#pragma opt_propagation off
void fn_1_3FCB0(s32 value) {
    s32 mask = -value;
    mask |= value;
    mask >>= 31;
    lbl_1_bss_3C08[0] = fn_1_3FCB0_operand(((lbl_1_bss_3C08[0] | (u32)value)), ((u32)mask));
}
#pragma opt_propagation reset
/* fzgx:end fn_1_3FCB0 */

/* fzgx:begin fn_1_3FCF8 */
struct fn_1_3FCF8_lbl_1_bss_3C30 {
    u8 pad_0[0x1478];
    u16 unk_1478;
    u16 unk_147A;
    u16 unk_147C;
    u16 unk_147E;
    u32 unk_1480;
    u32 unk_1484;
    u32 unk_1488;
    u32 unk_148C;
};

u32 fn_1_3FCF8(void) {
    u32 v0;
    u32 v1;
    u32 t0;
    (*(struct fn_1_3FCF8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30).unk_1480 = 0;
    (*(struct fn_1_3FCF8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30).unk_1478 = 0;
    (*(struct fn_1_3FCF8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30).unk_1484 = 0;
    (*(struct fn_1_3FCF8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30).unk_147A = 0;
    (*(struct fn_1_3FCF8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30).unk_1488 = 0;
    (*(struct fn_1_3FCF8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30).unk_147C = 0;
    (*(struct fn_1_3FCF8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30).unk_148C = 0;
    (*(struct fn_1_3FCF8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30).unk_147E = 0;
    v1 = (u32)&(*(struct fn_1_3FCF8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30);
    for (v0 = 5; v0 != 0; v0--) {
    *(u8 *)((u8 *)v1 + 343) = 0;
    *(u8 *)((u8 *)v1 + 220) = 0;
    *(u16 *)((u8 *)v1 + 216) = 0;
    *(u8 *)((u8 *)v1 + 503) = 0;
    *(u8 *)((u8 *)v1 + 380) = 0;
    *(u16 *)((u8 *)v1 + 376) = 0;
    *(u8 *)((u8 *)v1 + 663) = 0;
    *(u8 *)((u8 *)v1 + 540) = 0;
    *(u16 *)((u8 *)v1 + 536) = 0;
    *(u8 *)((u8 *)v1 + 823) = 0;
    *(u8 *)((u8 *)v1 + 700) = 0;
    *(u16 *)((u8 *)v1 + 696) = 0;
    *(u8 *)((u8 *)v1 + 983) = 0;
    *(u8 *)((u8 *)v1 + 860) = 0;
    *(u16 *)((u8 *)v1 + 856) = 0;
    *(u8 *)((u8 *)v1 + 1143) = 0;
    *(u8 *)((u8 *)v1 + 1020) = 0;
    *(u16 *)((u8 *)v1 + 1016) = 0;
    v1 = (u32)((u8 *)v1 + 960);
    }
    v1 = 0x80000000;
    t0 = fn_800075AC(v1, 8192, 1);
    v1 = t0;
    return v1;
}
/* fzgx:end fn_1_3FCF8 */

/* fzgx:begin fn_1_3FDA8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"

extern void *fn_1_435C(void *value);
extern s32 ghost_test_record_flag0(u8 value);
extern s32 fn_1_F9D44(u32 value);
extern u8 fn_1_F8C50(u8 value);
extern void fn_1_2DB50(void);
extern void fn_1_3F8C(void *arg0, void (*arg1)(void), Obj_1_bss_5138 *arg2, u32 arg3);
extern void fn_1_2D888(void);
extern void fn_1_2D524(void);

extern void *fn_1_435C(void *value);

void fn_1_3FDA8(void *arg0, void *arg1) {
    s32 condition;
    void *value;

    if (lbl_1_bss_5138.unk_0 != 0) {
        lbl_1_bss_5138.unk_E1 = 0;
    } else {
        if (lbl_1_bss_5138.unk_E3 == 0xff) {
            condition = 0;
        } else if (ghost_test_record_flag0(lbl_1_bss_3C30.unk_6) != 0) {
            condition = 0;
        } else {
            condition = 1;
        }
        if (condition != 0) {
            lbl_1_bss_5138.unk_E1 = 1;
        } else {
            if (lbl_1_bss_5138.unk_E5 == 0xff) {
                condition = 0;
            } else if (fn_1_F9D44(lbl_1_bss_5138.unk_E5 & 0xf) != 0) {
                condition = 0;
            } else {
                condition = 1;
            }
            if (condition != 0) {
                lbl_1_bss_5138.unk_E1 = 2;
            } else {
                if (lbl_1_bss_5138.unk_EB == 0xff) {
                    condition = 0;
                } else if (fn_1_F8C50(lbl_1_bss_5138.unk_EB) != 0) {
                    condition = 0;
                } else {
                    condition = 1;
                }
                if (condition != 0) {
                    lbl_1_bss_5138.unk_E1 = 3;
                } else if (lbl_1_bss_5138.unk_3 + lbl_1_bss_5138.unk_2 + lbl_1_bss_5138.unk_E4 != 0) {
                    lbl_1_bss_5138.unk_E1 = 4;
                } else {
                    // Skip setup when no state transition is selected.
                    goto done;
                }
            }
        }
    }

    value = fn_1_435C(arg0);
    fn_1_3F8C(lbl_1_data_6608, fn_1_2DB50, &lbl_1_bss_5138, 30);
    fn_1_435C(arg1);
    fn_1_3F8C(lbl_1_data_6618, fn_1_2D888, &lbl_1_bss_5138, 30);
    fn_1_435C(value);
    lbl_1_bss_5138.unk_E2 = 1;
    fn_1_2D524();

done:
    return;
}
/* fzgx:end fn_1_3FDA8 */

/* fzgx:begin fn_1_3FF90 */
void fn_1_3FF90(void) {
    u32 bss_25b88;
    u32 bss_25ca4;
    int flag;

    bss_25ca4 = lbl_1_bss_25CA4.unk_0;
    bss_25b88 = lbl_1_bss_25B88.unk_0;
    if (lbl_1_bss_5138.unk_0 != 0) {
        lbl_1_bss_5138.unk_E1 = 0;
    } else {
        if (lbl_1_bss_5138.unk_E3 == 0xff) {
            flag = 0;
        } else if ((int)ghost_test_record_flag0(lbl_1_bss_3C30.unk_6) != 0) {
            flag = 0;
        } else {
            flag = 1;
        }
        if (flag != 0) {
            lbl_1_bss_5138.unk_E1 = 1;
        } else {
            if (lbl_1_bss_5138.unk_E5 == 0xff) {
                flag = 0;
            } else if ((int)fn_1_F9D44(lbl_1_bss_5138.unk_E5 & 0xf) != 0) {
                flag = 0;
            } else {
                flag = 1;
            }
            if (flag != 0) {
                lbl_1_bss_5138.unk_E1 = 2;
            } else {
                if (lbl_1_bss_5138.unk_EB == 0xff) {
                    flag = 0;
                } else if (fn_1_F8C50(lbl_1_bss_5138.unk_EB)) {
                    flag = 0;
                } else {
                    flag = 1;
                }
                if (flag != 0) {
                    lbl_1_bss_5138.unk_E1 = 3;
                } else if ((lbl_1_bss_5138.unk_3 + lbl_1_bss_5138.unk_2 +
                            lbl_1_bss_5138.unk_E4) == 0) {
                    return;
                } else {
                    lbl_1_bss_5138.unk_E1 = 4;
                }
            }
        }
    }

    bss_25b88 = fn_1_435C(bss_25b88);
    fn_1_3F8C(lbl_1_data_6608, fn_1_2DB50, &lbl_1_bss_5138, 30);
    fn_1_435C(bss_25ca4);
    fn_1_3F8C(lbl_1_data_6618, fn_1_2D888, &lbl_1_bss_5138, 30);
    bss_25b88 = fn_1_435C(bss_25b88);
    lbl_1_bss_5138.unk_E2 = 1;
    fn_1_2D524();
}
/* fzgx:end fn_1_3FF90 */

/* fzgx:begin fn_1_4017C */
int fn_1_4017C(void) {
    int i;
    int result1;
    int result2;
    int result3;

    if ((int)fn_1_FA070() != 0) {
        return 1;
    }
    for (i = 0; i < 3; i++) {
        result1 = fn_1_FA180(1, i);
        result2 = fn_1_FA180(2, i);
        result3 = fn_1_FA180(3, i);
        if (result1 == 0 && result2 == 0 && result3 == 0) {
            return 0;
        }
    }
    return 1;
}
/* fzgx:end fn_1_4017C */

/* fzgx:begin fn_1_40224 */
int fn_1_40224(void) {
    int result;

    if ((int)fn_1_F9FEC() != 0) {
        return 1;
    }
    if (fn_1_FA180(2, 0) == 0) {
        return 0;
    }
    if (fn_1_FA180(2, 1) == 0) {
        return 0;
    }
    result = fn_1_FA180(2, 2);
    return result != 0;
}
/* fzgx:end fn_1_40224 */

/* fzgx:begin fn_1_402D4 */
typedef struct {
    u8 pad_0[8];
    u16 unk_8;
    u8 pad_A[0xA];
} Elem_1_bss_9F8;

int fn_1_402D4(void) {
    s32 i;

    if (lbl_1_bss_3C30.unk_8 != 0) {
        for (i = 0; i < lbl_1_bss_3C30.unk_8; i++) {
            if ((((Elem_1_bss_9F8 *)&lbl_1_bss_9F8)[(&lbl_1_bss_25E98)[i]].unk_8 >> 8) & 1) {
                return 1;
            }
        }
    } else if ((lbl_1_bss_9F8.unk_8 >> 12) & 1) {
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_402D4 */

/* fzgx:begin fn_1_40354 */
typedef struct {
    u8 pad_0[8];
    u16 unk_8;
    u8 pad_A[0xa];
} Entry_1_bss_9F8;

int fn_1_40354(void) {
    int i;

    if (lbl_1_bss_3C30.unk_8 != 0) {
        for (i = 0; i < lbl_1_bss_3C30.unk_8; i++) {
            if ((((Entry_1_bss_9F8 *)&lbl_1_bss_9F8)[((u8 *)&lbl_1_bss_25E98)[i]].unk_8 >> 12) & 1) {
                return 1;
            }
        }
    } else if ((lbl_1_bss_9F8.unk_8 >> 12) & 1) {
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_40354 */

/* fzgx:begin fn_1_403D4 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"
#include "font.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"
#include "font.h"
#include "types.h"

/* begin game/main_rel/game_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_GAME_TYPES_H
#define GAME_MAIN_REL_GAME_TYPES_H

// Types (and the externs that name them) of game.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct Sig_ADXT_Pause_AdxSjdHandle Sig_ADXT_Pause_AdxSjdHandle;
typedef struct Sig_ADXT_Pause_ADXStream Sig_ADXT_Pause_ADXStream;
typedef struct Sig_ADXT_Pause_AXRNAHandle Sig_ADXT_Pause_AXRNAHandle;

typedef struct Sig_ADXT_Pause_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Pause_SJCK;

typedef void (*Sig_ADXT_Pause_SJErrorCallback)(void *object, int error);
typedef struct Sig_ADXT_Pause_SJInterface Sig_ADXT_Pause_SJInterface;
typedef struct Sig_ADXT_Pause_SJ Sig_ADXT_Pause_SJ;

struct Sig_ADXT_Pause_SJ {
    const Sig_ADXT_Pause_SJInterface *interface;
};

struct Sig_ADXT_Pause_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Pause_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Pause_SJ *sj);
    void (*reset)(Sig_ADXT_Pause_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, int max_size, Sig_ADXT_Pause_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, Sig_ADXT_Pause_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, Sig_ADXT_Pause_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Pause_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Pause_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Pause_SJ *sj, Sig_ADXT_Pause_SJErrorCallback callback, void *object);
};

typedef struct Sig_ADXT_Pause_ADX_AMP Sig_ADXT_Pause_ADX_AMP;
typedef struct Sig_ADXT_Pause_LSCObject Sig_ADXT_Pause_LSCObject;

typedef struct Sig_ADXT_Pause_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Pause_AdxSjdHandle *decoder;
    Sig_ADXT_Pause_ADXStream *stream;
    Sig_ADXT_Pause_AXRNAHandle *rna;
    Sig_ADXT_Pause_SJ *stream_sj;
    Sig_ADXT_Pause_SJ *input_sj;
    Sig_ADXT_Pause_SJ *output_sj[2];
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
    Sig_ADXT_Pause_ADX_AMP *amplifier;
    Sig_ADXT_Pause_SJ *amplifier_input[2];
    Sig_ADXT_Pause_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Pause_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Pause_ADXTHandle;

/* begin game/main_rel/adxt_stop_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_ADXT_STOP_TYPES_H
#define GAME_MAIN_REL_ADXT_STOP_TYPES_H

// The ADXT handle layout recovered from ADXT_Stop's accesses (signature types), shared by game.c and
// live_camera.c, which carried identical copies. Hand-owned (librarian).


typedef struct Sig_ADXT_Stop_AdxSjdHandle Sig_ADXT_Stop_AdxSjdHandle;
typedef struct Sig_ADXT_Stop_ADXStream Sig_ADXT_Stop_ADXStream;
typedef struct Sig_ADXT_Stop_AXRNAHandle Sig_ADXT_Stop_AXRNAHandle;

typedef struct Sig_ADXT_Stop_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK;

typedef void (*Sig_ADXT_Stop_SJErrorCallback)(void *object, int error);
typedef struct Sig_ADXT_Stop_SJInterface Sig_ADXT_Stop_SJInterface;
typedef struct Sig_ADXT_Stop_SJ Sig_ADXT_Stop_SJ;

struct Sig_ADXT_Stop_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ *sj);
    void (*reset)(Sig_ADXT_Stop_SJ *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, Sig_ADXT_Stop_SJCK *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};

struct Sig_ADXT_Stop_SJ {
    const Sig_ADXT_Stop_SJInterface *interface;
};

typedef struct Sig_ADXT_Stop_ADX_AMP Sig_ADXT_Stop_ADX_AMP;
typedef struct Sig_ADXT_Stop_LSCObject Sig_ADXT_Stop_LSCObject;

typedef struct Sig_ADXT_Stop_ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Stop_AdxSjdHandle *decoder;
    Sig_ADXT_Stop_ADXStream *stream;
    Sig_ADXT_Stop_AXRNAHandle *rna;
    Sig_ADXT_Stop_SJ *stream_sj;
    Sig_ADXT_Stop_SJ *input_sj;
    Sig_ADXT_Stop_SJ *output_sj[2];
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
    Sig_ADXT_Stop_ADX_AMP *amplifier;
    Sig_ADXT_Stop_SJ *amplifier_input[2];
    Sig_ADXT_Stop_SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    Sig_ADXT_Stop_LSCObject *linked_stream_controller;
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
} Sig_ADXT_Stop_ADXTHandle;

#endif  // GAME_MAIN_REL_ADXT_STOP_TYPES_H

/* end game/main_rel/adxt_stop_types.h */

typedef struct {
    u8 unk[0xb];
    u8 value;
} Entry;

typedef struct {
    u8 pad_0[2];
    s16 unk_2;
    u8 pad_4[8];
    u32 unk_C;
    u8 pad_10[0x10];
} Obj_1_bss_25E9C;

typedef struct {
    u8 pad[0x2f8];
    u32 value_2f8;
    u32 value_2fc;
    u32 value_300;
    u32 value_304;
    u32 value_308;
    u32 value_30c;
    u32 value_310;
    u32 value_314;
    u32 value_318;
    u32 value_31c;
} Fn40710Config;

struct fn_1_408E8_lbl_1_rodata_BD8 {
    u8 pad_0[0x4];
    f32 unk_4;
    u8 pad_8[0x4];
    f32 unk_C;
    u8 pad_10[0x2C];
    f32 unk_3C;
    u8 pad_40[0x4];
    f32 unk_44;
    u8 pad_48[0x174];
    f32 unk_1BC;
    u8 pad_1C0[0xC];
    f32 unk_1CC;
    u8 pad_1D0[0xC];
    f32 unk_1DC;
    u8 pad_1E0[0x15C];
    u32 unk_33C;
    f32 unk_340;
};

typedef struct Fn408E8Obj {
    u8 type;         /* 0x00 */
    u8 pad_1[2];
    u8 flags;        /* 0x03 */
    u32 unk_4;
    f32 fade;        /* 0x08 */
    f32 z;           /* 0x0C */
    f32 x;           /* 0x10 */
    f32 y;           /* 0x14 */
    f32 width;       /* 0x18 */
    f32 height;      /* 0x1C */
    void *data;      /* 0x20 */
} Fn408E8Obj;

extern void ADXT_Pause(Sig_ADXT_Pause_ADXTHandle *, s32);
extern Fn40710Config lbl_1_rodata_BD8;
extern void fn_1_403D4(Fn408E8Obj *obj);
extern Entry *lbl_1_bss_53F8[34];
extern Obj_1_bss_25E9C lbl_1_bss_25E9C[30];

#endif  // GAME_MAIN_REL_GAME_TYPES_H

/* end game/main_rel/game_types.h */

extern void fn_1_451E4(void);
extern void fn_1_D3214(void);
extern void VIWaitForRetrace(void);
extern s32 fn_1_467F4(void);
extern s32 fn_1_13018(void);
extern u32 lbl_801A6CE0;
extern u32 lbl_1_bss_38454;
extern u32 fn_80070DE0(u32 arg0);
extern void fn_1_40F54(void *arg0);
extern void fn_1_D3884();
extern void fn_1_D358C();
extern int sprintf(char *s, const char *format, ...);
extern int DVDConvertPathToEntrynum(char *buffer);
extern void fn_1_412A0(u32 index);
extern s8 lbl_1_bss_26B5C[30];
extern u8* fn_1_36AD0(void);
extern u32 fn_1_34AC0(void *, u32, u32, u32);
extern void fn_1_8001C(void);
extern void fn_1_12AB38(void *arg0);
extern void fn_1_465D0(char *value, u32 flag);
extern void* fn_1_7F518(s16 car_type, void* car, s32 initialize);
extern u32 fn_1_435C(u32 value);
extern void fn_1_4310(u32 arg0);
extern void fn_1_8616C(void);
extern u32 fn_1_A11EC(void);
extern void fn_1_D0790(void);
extern u32 fn_1_101C0(void);
extern void fn_1_A1588(u32 arg0, u32 arg1);
extern void fn_1_48004(s32 index, s32 image);
extern u32 ghost_test_record_flag0(s32 arg);
extern u32 fn_1_F9D44(u32 arg);
extern u8 fn_1_F8C50(s32 arg0);
extern void fn_1_2DB50(void);
extern void fn_1_3F8C(void *, void *, Obj_1_bss_5138 *, int);
extern void fn_1_2D888(void);
extern void fn_1_2D524(void);
extern FontDrawPacket lbl_1_rodata_26F8;
extern void fn_1_50A90(FontDrawPacket *packet, s32 w, s32 h, s32 clipW, s32 clipH);
extern void fn_1_49514(u32 *value);
extern void fn_1_49614(void);
extern u32 lbl_801A63C0;
extern void fn_1_40BE4(void);
extern void fn_1_41134(void *unused, char *value);
extern void fn_1_12F308(void);
extern int fn_1_4C10(void);
extern u32 fn_1_12F358(u32);
extern void fn_1_4A00(s32 fadeIn, u8 steps, u32 arg);
extern int fn_1_402D4(void);
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_15E330(s32 index, u32 value, void *arg);
extern void fn_1_15E5E4(s32 index, void *arg);
extern void fn_1_15E688(s32 index, u32 value, u8 state, void *arg);
extern void fn_1_15E3E0(s32 index, u32 value);
extern void fn_1_15E434(u32 value);
extern void fn_1_15E540(s32 index, void *arg);
extern void fn_1_CB404(u8 value);
extern void fn_1_D07C4(u32 arg0, u32 arg1);
extern u32 lbl_1_bss_25B84;
extern u32 OSGetTick(void);
extern void fn_1_A0978(void);
extern void fn_1_35174(void);
extern s32 fn_1_3EFA8(void);
extern u16 lbl_1_bss_26B7A[3];
extern u16 lbl_1_bss_26300;
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_1_817C0(void);
extern u32 lbl_1_bss_381FC;
extern void fn_1_EB080(int mode);
extern s64 OSGetTime(void);
extern void fn_1_5370(u32 arg0, u32 arg1);
extern void fn_1_15E27C(void);
extern void fn_1_4811C(int arg);
extern void fn_1_A8F78(void);
extern u8 lbl_1_bss_262F4;
extern u32 lbl_1_bss_25E74[7];
extern u8 lbl_1_bss_3C10;
extern void fn_1_36330(void);
extern void fn_1_36B10(void);
extern void fn_1_3C98(void);
extern void fn_1_37AA8(void);
extern void fn_1_37E98(void);
extern f32 lbl_1_bss_26304[4];
extern u8 lbl_1_bss_26B04[20];
extern u8 lbl_1_bss_26314[2032];
extern s16 fn_1_12EF24(s16 row, s16 column);
extern u8 lbl_1_bss_523C[32];
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 fn_1_46C60(void);
extern u32 lbl_1_bss_26C2C[2];
extern u32 lbl_1_bss_262F8[2];
extern u16 lbl_1_bss_26C68[35526];
extern u32 lbl_1_bss_3C08[2];
extern u32 fn_800075AC(u32, u32, u32);
extern u32 fn_1_FA070(void);
extern u32 fn_1_FA180(u8 a, u8 b);
extern u32 fn_1_F9FEC(void);
extern void fn_1_A2DC4(u32 arg0);
extern u8 lbl_1_bss_26B54[8];
extern u32 fn_1_40EE4(void);
extern u32 lbl_801A63D0;
extern u32 lbl_1_bss_26C34[9];
extern u8 lbl_1_bss_38218[568];
extern u32 fn_1_4060(void);
extern void ARQPostRequest(u8 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, u32 arg7);
extern u32 GXGetTexBufferSize(u32, u32, u32, u32, u32);
extern u32 lbl_1_bss_26B4C;
extern u8 lbl_1_bss_25E90[8];
extern s32 fn_1_48B0(u32 arg0, u32 arg1);
extern void fn_800711A8(Obj_1_bss_38458_Target *target);
extern void fn_80071718(u32 value);
extern void fn_1_411D4(u32 index, char *value);
extern size_t strlen(const char *str);
extern int fn_80083BCC(const char *s1, const char *s2);
extern u8 lbl_1_A9011300;
extern u8 lbl_1_A9011100;
extern u8 lbl_1_A9011000;
extern u16 lbl_1_bss_25B80;
extern u8 lbl_1_bss_26B1D;
extern void fn_1_15E260(s32 index);

#pragma section code_type ".fzgxpool"
static const unsigned long fzgx_pool_table1[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const unsigned long *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 15.0f;
    s = 1.0f;
    s = 10.0f;
    s = 1.25f;
    s = 0.10000000149011612f;
    s = 0.8999999761581421f;
    s = 0.0006000000284984708f;
    s = 0.4000000059604645f;
    s = 0.75f;
    s = 70.0f;
    s = 0.5f;
    s = 36.0f;
    s = 16.0f;
    s = 45.0f;
    s = 0.0007999999797903001f;
    s = 18.0f;
    s = 50.0f;
}
static const unsigned long fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const unsigned long *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const unsigned long fzgx_pool_table5[52] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const unsigned long *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = 80.0f;
    s = 60.0f;
}
static const unsigned long fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const unsigned long *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const unsigned long fzgx_pool_table9[2] = {0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const unsigned long *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 470.0f;
    s = 0.0625f;
    s = 14.0f;
    s = 127.0f;
    s = 0.25f;
}
static const unsigned long fzgx_pool_table11[3] = {0x03E8FED4, 0xFE70FE0C, 0xFE0CFE0C};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const unsigned long *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 10000.0f;
    s = 15000.0f;
    s = 9999.0f;
}
static const unsigned long fzgx_pool_table13[2] = {0xFFFFFF00, 0x80808000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const unsigned long *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 240.0f;
    s = 280.0f;
    s = 200.0f;
    s = 40.0f;
    s = 30.0f;
}
static const unsigned long fzgx_pool_table15[8] = {0x80808000, 0xFFFFFF00, 0x80808000, 0xFFFFFF00, 0xFFFFFF00, 0x00000000, 0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const unsigned long *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.05000000074505806f;
    s = 0.15000000596046448f;
    s = 0.07999999821186066f;
    s = 2.0f;
    s = 4.0f;
    s = 255.0f;
    s = 1.100000023841858f;
    s = 38.0f;
    s = 20.0f;
    s = 180.0f;
    s = 3.0f;
    s = 0.00019999999494757503f;
    s = 100.0f;
    s = 75.0f;
    s = 0.00039999998989515007f;
    s = 150.0f;
}
static const unsigned long fzgx_pool_table17[7] = {0xFFF200FF, 0xFFF200FF, 0x80808080, 0xFFFFFF96, 0xFFF200FF, 0xFFF200FF, 0xFFFFFF96};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const unsigned long *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.009999999776482582f;
    s = 1000.0f;
    d = 20.0;
}
static const unsigned long fzgx_pool_table19[4] = {0x80000000, 0x40000000, 0x20000000, 0x10000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const unsigned long *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 620.0f;
    s = 140.0f;
    s = 3000.0f;
    s = 0.00033333332976326346f;
}
static const f32 fzgx_pool_fn_1_403D4_pool_scale[1] = {0.3f};
__declspec(section ".fzgxpool") static void fzgx_pool_prime20b(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.6000000238418579f;
    s = 450.0f;
}
static const unsigned long fzgx_pool_table21[2] = {0x00000001, 0x00020003};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const unsigned long *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1100.0f;
    s = 1900.0f;
}
static const unsigned long fzgx_pool_table23[9] = {0x00000000, 0x40000000, 0x40000000, 0x40000000, 0x20000000, 0x20000000, 0x00000000, 0x00000000, 0x50000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const unsigned long *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 600.0f;
    s = -60.0f;
    s = -1.0f;
    s = 35.0f;
    s = -11.0f;
    s = 3.5f;
    s = -10.0f;
    s = 640.0f;
    s = 480.0f;
    s = 6.5f;
}
static const unsigned long fzgx_pool_table25[6] = {0x40000000, 0x40000000, 0x40000000, 0x20000000, 0x20000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const unsigned long *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime26(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 1000000.0f;
    s = -0.10000000149011612f;
    s = -2.0f;
}
static const unsigned long fzgx_pool_table27[17] = {0x00B500B6, 0x00AD00B3, 0x00B800B2, 0x00B100AE, 0x00B400B9, 0x00B000AF, 0x00B7FFFF, 0xFFF200FF, 0xFFF200FF, 0xFFFFFF96, 0xFFFFFF96, 0xFFFFFF96, 0xFFFFFF96, 0xFFFFFF96, 0xFFFFFF96, 0xFFFFFF96, 0xFFFFFF96};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep27(void) { const unsigned long *volatile cp; cp = fzgx_pool_table27; }  /* fzgx-allow: S2 pool primer sink */
static const unsigned long fzgx_pool_table28[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const unsigned long *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
static const unsigned long fzgx_pool_table29[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep29(void) { const unsigned long *volatile cp; cp = fzgx_pool_table29; }  /* fzgx-allow: S2 pool primer sink */
static const unsigned long fzgx_pool_table30[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const unsigned long *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0010000000474974513f;
    s = 360.0f;
    s = 90.0f;
}
#pragma section code_type ".text"

typedef struct {
    u8 r, g, b, a;
} Fn403D4Color;

/* Fn408E8Obj followed by the two button colours this box draws. */
typedef struct {
    Fn408E8Obj base;         /* 0x00 */
    u32 unk_24;
    Fn403D4Color colors[2];  /* 0x28 */
} Fn403D4Obj;

#define COLORS(o) (((Fn403D4Obj *)(o))->colors)

extern char *fn_1_15BA78(char *);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u8);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_494DC(s16);
extern void fn_1_4955C(f32, f32);
extern f32 fn_1_4B068(char *);
extern f32 fn_1_4B090(char *);
extern void fn_1_49514(u32 *);
extern void fn_1_495A0(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);

void fn_1_403D4(Fn408E8Obj *obj) {
    f32 textH;
    f32 fade;
    f32 lineH;
    f32 h;
    u32 header;
    s32 i;
    char *text;

    fade = obj->fade;
    text = fn_1_15BA78((char *)obj->unk_4);
    fn_1_49410();
    fn_1_495FC();
    fn_1_4954C(obj->z - 0.001f);
    fn_1_495C8(1);
    fn_1_49590(0.4f);
    fn_1_495B0(0x80000000);
    fn_1_494DC(0x2a);
    fn_1_4955C(0.75f, 0.75f * obj->fade);

    obj->width = (f32)(s32)(150.0f + fn_1_4B068(text));
    if (obj->width < 360.0f) {
        obj->width = 360.0f;
    }
    h = fn_1_4B090(text);
    lineH = 30.0f + h;
    textH = h * fzgx_pool_fn_1_403D4_pool_scale[0];
    *(volatile f32 *)&obj->height = 90.0f + lineH; /* fzgx-allow: S2 preserve the height publication before reading the shared colour */

    header = ((volatile u32 *)fzgx_pool_table28)[0]; /* fzgx-allow: S2 retain retail shared-pool read ordering */
    fn_1_49514(&header);
    fn_1_495A0(obj->fade);
    fn_1_496FC(obj->x, textH + ((obj->y - lineH) + (f32)((1.0f - fade) * lineH)));
    fn_1_4A0D8(text);
    fn_1_496FC(obj->x, textH + ((obj->y - 10.0f) + (f32)(10.0f * (1.0f - fade))));

    for (i = 0; i < 2; i++) {
        const char *labels[2];
        u32 color;
        f32 alpha;

        labels[0] = (char *)((volatile u32 *)fzgx_pool_table29)[0]; /* fzgx-allow: S2 reload shared label words each iteration */
        labels[1] = (char *)((volatile u32 *)fzgx_pool_table30)[0]; /* fzgx-allow: S2 reload shared label words each iteration */
        color = *(u32 *)&COLORS(obj)[i];
        fn_1_49514(&color);
        alpha = fade * ((f32)COLORS(obj)[i].a / 255.0f);
        if (alpha < 0.0f) {
            alpha = 0.0f;
        }
        fn_1_495A0(alpha);
        fn_1_496FC((obj->x - 90.0f) + (f32)(i * 180), textH + (obj->y + 20.0f * fade));
        fn_1_4A0D8(fn_1_15BA78((char *)labels[i]));
    }
}
/* fzgx:end fn_1_403D4 */

/* fzgx:begin fn_1_40710 */
typedef struct {
    u8 state;
    u8 enabled;
    u8 applied;
    u8 flags;
    u8 pad[0x24];
    u32 value_28;
    u32 value_2c;
} Fn40710Object;



void fn_1_40710(Fn40710Object *obj) {
    Fn40710Object *self = obj;
    Fn40710Config *config = &lbl_1_rodata_BD8;
    int state = self->state;
    u8 *values;
    u32 limits[8];
    u32 flags;

    switch (state) {
    case 2:
        self->enabled &= 1;
        if (self->enabled != 0) {
            self->value_2c = config->value_2f8;
            values = (u8 *)&self->value_28;
        } else {
            self->value_28 = config->value_2fc;
            values = (u8 *)&self->value_2c;
        }
        limits[0] = config->value_300;
        if (values[0] < ((u8 *)&limits[0])[0] - 0x14) {
            values[0] += 0x14;
        } else {
            limits[1] = config->value_304;
            values[0] = ((u8 *)&limits[1])[0];
        }
        limits[2] = config->value_308;
        if (values[1] < ((u8 *)&limits[2])[1] - 0x14) {
            values[1] += 0x14;
        } else {
            limits[3] = config->value_30c;
            values[1] = ((u8 *)&limits[3])[1];
        }
        limits[4] = config->value_310;
        if (values[2] < ((u8 *)&limits[4])[2] - 0x14) {
            values[2] += 0x14;
        } else {
            limits[5] = config->value_314;
            values[2] = ((u8 *)&limits[5])[2];
        }
        limits[6] = config->value_318;
        if (values[3] > ((u8 *)&limits[6])[3] + 0x14) {
            values[3] -= 0x14;
        } else {
            limits[7] = config->value_31c;
            values[3] = ((u8 *)&limits[7])[3];
        }
        // The case-2 path joins the shared state update below.
        goto update_state;
    case 0:
        // The case-0 path joins the shared state update below.
        goto update_state;
    case 1:
        // The case-1 path joins the shared state update below.
        goto update_state;
    default:
        break;
    }
    return;

update_state:
    if (self->enabled != self->applied) {
        /* fzgx-allow: A1 absolute game data address */
        fn_1_A2DC4((u32)0xA9011300);
        self->applied = self->enabled;
    }
    if ((self->flags & 2) != 0) {
        /* fzgx-allow: A1 absolute game data address */
        fn_1_A2DC4((u32)0xA9011100);
        flags = __rlwinm(self->flags, 0, 24, 29);
        self->flags = flags;
    } else if ((self->flags & 4) != 0) {
        /* fzgx-allow: A1 absolute game data address */
        fn_1_A2DC4((u32)0xA9011000);
        self->flags = self->flags & -6;
    }
}
/* fzgx:end fn_1_40710 */

/* fzgx:begin fn_1_408E8 noprologue */
#include "types.h"

struct fn_1_408E8_Copy88 { u32 a[22]; };
struct fn_1_408E8_lbl_1_rodata_BD8 {
    u8 pad_0[0x4];
    f32 unk_4;
    u8 pad_8[0x4];
    f32 unk_C;
    u8 pad_10[0x2C];
    f32 unk_3C;
    u8 pad_40[4];
    f32 unk_44;
    u8 pad_48[0x174];
    f32 unk_1BC;
    u8 pad_1C0[0xC];
    f32 unk_1CC;
    u8 pad_1D0[0xC];
    f32 unk_1DC;
    u8 pad_1E0[0x15C];
    u32 unk_33C;
    f32 unk_340;
};
extern struct fn_1_408E8_lbl_1_rodata_BD8 lbl_1_rodata_BD8;
extern struct fn_1_408E8_Copy88 lbl_1_rodata_26F8;
extern u32 fn_1_403D4(void *);
extern u32 fn_1_50A90(void *, s32, s32, s32, s32);
extern void fn_1_49514(u32 *);
extern void fn_1_49614(void);

static inline f32 fn_1_408E8_read_pointer(struct fn_1_408E8_lbl_1_rodata_BD8 * owner) { return owner->unk_1BC; }
static inline f32 fn_1_408E8_read_one(struct fn_1_408E8_lbl_1_rodata_BD8 * owner) { return owner->unk_C; }
#pragma opt_common_subs off
#pragma opt_propagation off
void fn_1_408E8(void *arg0, u32 arg1, u32 arg2, s32 arg3, s32 arg4, f32 arg5) {
    f32 fzgx_live;
    struct fn_1_408E8_lbl_1_rodata_BD8 *p_lbl_1_rodata_BD8;
    f32 v0;
    f32 v1;
    f32 v2;
    f32 v3;
    f32 v4;
    u8 v5;
    f32 v0_2;
    s32 v6;
    s32 v7;
    f32 v8;
    u32 prefix;
    struct fn_1_408E8_Copy88 packet;
    s32 v7_2;
    s32 width;
    s32 height;
    s32 lab_t3;
    p_lbl_1_rodata_BD8 = (struct fn_1_408E8_lbl_1_rodata_BD8 *)&lbl_1_rodata_BD8;
    if ((*(u8 *)((u8 *)arg0 + 3) & 1) != 0) {
        v0 = *(f32 *)((u8 *)arg0 + 8);
        if (v0 < p_lbl_1_rodata_BD8->unk_340)
            *(f32 *)((u8 *)arg0 + 8) = v0 + fn_1_408E8_read_pointer(p_lbl_1_rodata_BD8);
        else
            *(f32 *)((u8 *)arg0 + 8) = p_lbl_1_rodata_BD8->unk_C;
    } else {
        v0_2 = *(f32 *)((u8 *)arg0 + 8);
        v1 = fn_1_408E8_read_pointer(p_lbl_1_rodata_BD8);
        if (v0_2 > v1)
            *(f32 *)((u8 *)arg0 + 8) = v0_2 - v1;
        else {
            *(f32 *)((u8 *)arg0 + 8) = p_lbl_1_rodata_BD8->unk_4;
            return;
        }
    }
    v2 = p_lbl_1_rodata_BD8->unk_1CC;
    fzgx_live = *(f32 *)((u8 *)arg0 + 8);
    v3 = fn_1_408E8_read_one(p_lbl_1_rodata_BD8);
    v4 = v2 * fzgx_live;
    if (v4 > v3) v4 = v3;
    v5 = *(u8 *)arg0;
    v6 = arg3;
    v7 = arg4;
    switch (v5) {
    case 1:
        if (*(u32 *)((u8 *)arg0 + 32) != 0) break;
    case 0:
        v6 = (s32)(*(f32 *)((u8 *)arg0 + 24) * v4);
        v7_2 = (s32)(*(f32 *)((u8 *)arg0 + 28) * v4);
        break;
    case 2:
        fn_1_403D4(arg0);
        v6 = (s32)*(f32 *)((u8 *)arg0 + 24);
        v7_2 = (s32)(*(f32 *)((u8 *)arg0 + 28) * v4);
        break;
    default: return;
    }
    packet = lbl_1_rodata_26F8;
    *(f32 *)&packet.a[1] = *(f32 *)((u8 *)arg0 + 16);
    *(f32 *)&packet.a[2] = *(f32 *)((u8 *)arg0 + 20);
    *(f32 *)&packet.a[3] = *(f32 *)((u8 *)arg0 + 12);
    packet.a[12] = 10;
    packet.a[0] = 2;
    v8 = *(f32 *)((u8 *)arg0 + 8);
    *(f32 *)&packet.a[11] = v8;
    width = (s32)(p_lbl_1_rodata_BD8->unk_1DC * (f32)(p_lbl_1_rodata_BD8->unk_44 * v8));
    height = (s32)(p_lbl_1_rodata_BD8->unk_1DC * (f32)(p_lbl_1_rodata_BD8->unk_3C * v8));
    if (width > 18 || v6 > 18) width = 18;
    if (height > 45 || v7_2 > 45) height = 45;
    lab_t3 = v6;
    fn_1_50A90(&packet, width, height, lab_t3, v7_2);
    prefix = p_lbl_1_rodata_BD8->unk_33C;
    fn_1_49514(&prefix);
    fn_1_49614();
}
#pragma opt_propagation reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_408E8 */

/* fzgx:begin fn_1_40B14 */
u8 *fn_1_40B14(void) {
    return lbl_1_bss_26B54;
}
/* fzgx:end fn_1_40B14 */

/* fzgx:begin fn_1_40B20 */
s32 fn_1_40B20(void) {
    s32 i;
    u8 *q;
    s32 n;
    u8 a7;
    u8 min;
    u8 v;

    if (lbl_1_bss_3C30.unk_5 == 5) {
        return *(s8 *)((u8 *)&lbl_1_bss_9C + 6);
    }
    if (lbl_1_bss_3C30.unk_5 != 1) {
        return -1;
    }
    a7 = lbl_1_bss_3C30.unk_A7;
    if (a7 == 0) {
        return -1;
    }
    n = lbl_1_bss_3C30.unk_9;
    q = (u8 *)&lbl_1_bss_3C30 + a7;
    min = lbl_1_bss_3C30.unk_8;
    for (i = 0; i < n; i++) {
        v = *(u8 *)((u8 *)&lbl_1_bss_3C30 + i + 0x1394);
        if ((s32)v >= (s32)min) {
            if (q[v * 160 + 226] != 254) {
                return v;
            }
        }
    }
    return -1;
}
/* fzgx:end fn_1_40B20 */

/* fzgx:begin fn_1_40BB4 */
u8 fn_1_40BB4(void) {
    return (s8)lbl_1_bss_5104.unk_0 != -1;
}
/* fzgx:end fn_1_40BB4 */

/* fzgx:begin fn_1_40BD4 */
void fn_1_40BD4(void) {
    lbl_1_bss_3820C = 0;
}
/* fzgx:end fn_1_40BD4 */

/* fzgx:begin fn_1_40BE4 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"

extern const struct fn_1_40BE4_lbl_1_rodata_BD8_pool {
    u8 pad_0[0x30];
    f32 unk_30;
    u8 pad_34[0xF8];
    f32 unk_12C;
    u8 pad_130[0x214];
    u32 unk_344;
    u32 unk_348;
    u32 unk_34C;
    u32 unk_350;
    f32 unk_354;
} lbl_1_rodata_BD8;

extern void *fn_1_86254(s32);
extern void *fn_1_868C0(s32);
extern f32 fn_1_84038(void *, s16, u8, f32);
extern u32 fn_1_76504(u32, void *, void *);
extern void fn_1_7269C(u32, u32, u32);
extern u32 lbl_801A63D0[];
extern void fn_1_40D44(void);
extern u32 fn_1_4030(u32);

typedef struct {
    u32 x;
    u32 y;
    u32 z;
    u32 w;
} Vec4u;






void fn_1_40BE4(void) {
    struct fn_1_40BE4_lbl_1_rodata_BD8_pool *pool_lbl_1_rodata_BD8 = (struct fn_1_40BE4_lbl_1_rodata_BD8_pool *)&lbl_1_rodata_BD8;
    u8 ok = 1;
    Vec4u v;
    u32 n;
    u32 name;
    u8 sel;

    if (*(s16 *)&lbl_1_bss_960 == 2) {
        f32 r;

        if (*(s16 *)((u8 *)fn_1_86254(0) + 6) > 0x29) {
            r = fn_1_84038(fn_1_868C0(0), 0, 1, pool_lbl_1_rodata_BD8->unk_30);
        } else {
            r = fn_1_84038(fn_1_868C0(0), 0, 0, pool_lbl_1_rodata_BD8->unk_30);
        }

        if (r < pool_lbl_1_rodata_BD8->unk_12C || r > pool_lbl_1_rodata_BD8->unk_354) {
            ok = 0;
        }
    }

    if (lbl_1_bss_38210 == 0) {
        return;
    }

    v.x = pool_lbl_1_rodata_BD8->unk_344;
    v.y = pool_lbl_1_rodata_BD8->unk_348;
    v.z = pool_lbl_1_rodata_BD8->unk_34C;
    v.w = pool_lbl_1_rodata_BD8->unk_350;

    sel = (u8)fn_1_76504(0x25, &v, 0);

    if (lbl_1_bss_3C1C.unk_0 + 0x10000 == 0xFFFF) {
        name = lbl_801A63D0[0];
    } else {
        name = lbl_1_bss_3C1C.unk_0;
    }
    fn_1_7269C(sel, 0, name);

    n = lbl_1_bss_38210 - 1;
    lbl_1_bss_38210 = n;
    if ((n < lbl_1_bss_38214 && ok) || n == 0) {
        fn_1_4030((u32)fn_1_40D44);
    }
}
/* fzgx:end fn_1_40BE4 */

/* fzgx:begin fn_1_40D44 */
void fn_1_40D44(void) {
    u32 result;
    u32 state;
    u32 arg;

    result = fn_1_40EE4();
    state = lbl_1_bss_3C1C.unk_0;
    if ((state + 0x10000) == 0xffff) {
        lbl_1_bss_3C1C.unk_0 = 0;
        arg = lbl_801A63D0;
    } else {
        arg = state;
    }

    ARQPostRequest(lbl_1_bss_38218, 0, 0, 1, arg, result,
                lbl_1_bss_26C34[0], 0);

    lbl_1_bss_3820C = lbl_1_bss_3820C + 1;
    if (lbl_1_bss_3820C > 6 || result >= 0x00f95fff) {
        lbl_1_bss_3820C = 6;
    }

    fn_1_4060();
}
/* fzgx:end fn_1_40D44 */

/* fzgx:begin fn_1_40E08 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"

extern void fn_1_3F8C(void *arg0, void (*arg1)(void), Obj_1_bss_5138 *arg2, u32 arg3);
extern u32 lbl_801A63C0;
extern void fn_1_40BE4(void);

// Initializes the random-selection bounds and schedules the next callback.
void fn_1_40E08(u32 arg0) {
    u32 value;
    u32 half;
    u32 max;
    u32 remainder;

    if (*(s16 *)&lbl_1_bss_960 == 0x10) {
        lbl_1_bss_3C1C.unk_0 = -1;
    }

    lbl_1_bss_38210 = arg0;
    if (arg0 < 5) {
        lbl_1_bss_38210 = 5;
    }

    value = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    lbl_801A63C0 = value;

    half = lbl_1_bss_38210 >> 1;
    max = lbl_1_bss_38210 - 5;
    remainder = ((value >> 16) & 0x7FFF) % half;
    lbl_1_bss_38214 = half + remainder;
    if (lbl_1_bss_38214 > max) {
        lbl_1_bss_38214 = max;
    }

    fn_1_3F8C(lbl_1_data_662C, fn_1_40BE4, 0, 1);
}
/* fzgx:end fn_1_40E08 */

/* fzgx:begin fn_1_40ED4 */
u8 fn_1_40ED4(void) {
    return lbl_1_bss_3820C;
}
/* fzgx:end fn_1_40ED4 */

/* fzgx:begin fn_1_40EE4 */
u32 fn_1_40EE4(void) {
    u32 t0;
    return (((lbl_1_bss_3820C * (((GXGetTexBufferSize(320, 224, 1, 0, 0)) + 31) & ~0x1F)) + 0xF20000) + 16384);
}
/* fzgx:end fn_1_40EE4 */

/* fzgx:begin fn_1_40F34 */
u32 fn_1_40F34(void) {
    return lbl_1_bss_26B4C;
}
/* fzgx:end fn_1_40F34 */

/* fzgx:begin fn_1_40F44 */
u8 fn_1_40F44(void) {
    return lbl_1_bss_25E90[0];
}
/* fzgx:end fn_1_40F44 */

/* fzgx:begin fn_1_40F54 */
// Initializes the related game state with the standard allocation size.
void fn_1_40F54(void *arg0) {
    fn_1_48B0( (u32)(void *)(arg0), 0x20);
}
/* fzgx:end fn_1_40F54 */

/* fzgx:begin fn_1_40F78 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"

extern u32 lbl_801A6CE0;
extern u32 lbl_1_bss_38454;
extern u32 fn_80070DE0(void (*)(void));
extern void fn_1_40F54(void *arg0);
extern void *fn_1_D3884(u8 *arg0);
extern void *fn_1_D358C(u8 *arg0, void *arg1);

extern u32 lbl_801A6CE0;
extern u32 lbl_1_bss_38454;
extern u32 fn_80070DE0(void (*)(void));
extern void fn_1_40F54(void *arg0);
extern void *fn_1_D3884(u8 *arg0);
extern void *fn_1_D358C(u8 *arg0, void *arg1);

// Initializes the shared resource handles when the subsystem is enabled.
void fn_1_40F78(void) {
    u32 resource_handle;
    void *decoded_data;

    if ((lbl_801A6CE0 & 1) == 0) {
        lbl_1_bss_38450 = 0;
        lbl_1_bss_38454 = 0;
        return;
    }

    resource_handle = fn_80070DE0((void (*)(void))fn_1_40F54);
    decoded_data = fn_1_D3884((u8 *)lbl_1_data_66C0);
    lbl_1_bss_38450 = (u32)decoded_data;
    lbl_1_bss_38454 = (u32)fn_1_D358C((u8 *)lbl_1_data_66D0, decoded_data);
    fn_80070DE0((void (*)(void))resource_handle);
}
/* fzgx:end fn_1_40F78 */

/* fzgx:begin fn_1_4100C */
// Initializes both shared data blocks with their default state.
void fn_1_4100C(void) {
    fn_1_465D0((char *)lbl_1_data_66E0, 1);
    fn_1_465D0((char *)lbl_1_data_66F0, 1);
}
/* fzgx:end fn_1_4100C */

/* fzgx:begin fn_1_41048 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"

extern void *fn_1_D3884(u8 *arg0);
extern void *fn_1_D358C(u8 *arg0, void *arg1);

extern void *fn_1_D3884(u8 *arg0);
extern void *fn_1_D358C(u8 *arg0, void *arg1);

void fn_1_41048(void) {
    void *value;

    if (lbl_1_bss_38458 == 0) {
        value = fn_1_D3884(lbl_1_data_66E0);
        lbl_1_bss_3845C = (u32)value;
        lbl_1_bss_38458 = (Obj_1_bss_38458_Target *)fn_1_D358C(lbl_1_data_66F0, value);
    }
}
/* fzgx:end fn_1_41048 */

/* fzgx:begin fn_1_410A0 */
void fn_1_410A0(void) {
    if (lbl_1_bss_38458 != 0) {
        fn_800711A8(lbl_1_bss_38458);
        lbl_1_bss_38458 = 0;
    }

    if (lbl_1_bss_3845C != 0) {
        fn_80071718(lbl_1_bss_3845C);
        lbl_1_bss_3845C = 0;
    }
}
/* fzgx:end fn_1_410A0 */

/* fzgx:begin fn_1_41104 */
// Forwards the selected message entry to the formatter.
void fn_1_41104(u32 message_index) {
    char *message = *(char **)(lbl_1_data_66A0 + message_index * sizeof(char *));
    fn_1_41134((void *)message_index, message);
}
/* fzgx:end fn_1_41104 */

/* fzgx:begin fn_1_41134 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"

extern void fn_1_465D0(char *value, u32 flag);
extern void sprintf(char *buffer, u32 *format, ...);

extern void fn_1_41134(void *unused, char *value);

// Format the value with each registered template and publish both results.
void fn_1_41134(void *unused, char *value) {
    char buffer[128];

    sprintf(buffer, &lbl_1_data_6700, value);
    fn_1_465D0(buffer, 1);
    sprintf(buffer, &lbl_1_data_6708, value);
    fn_1_465D0(buffer, 1);
}
/* fzgx:end fn_1_41134 */

/* fzgx:begin fn_1_411A4 */
// Forwards the indexed message entry to the follow-up handler.
void fn_1_411A4(u32 index) {
    fn_1_411D4(index, ((char **)lbl_1_data_66A0)[index]);
}
/* fzgx:end fn_1_411A4 */

/* fzgx:begin fn_1_411D4 noprologue */
#include "types.h"
#include "rel/main_rel/game.h"

typedef struct Fn411D4Cache {
    u8 pad_00[0x10];
    u32 flags[7];
    int cached[7];
    char *generated[7];
} Fn411D4Cache;

extern int sprintf(char *buffer, char *format, ...);
extern int DVDConvertPathToEntrynum(char *buffer);
extern void fn_1_412A0(u32 index);
extern char *fn_1_D3884(char *buffer);
extern int fn_1_D358C(char *buffer, char *value);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_38450;
u32 fzgx_obj_lbl_1_bss_38454;
u32 fzgx_obj_lbl_1_bss_38458;
u32 fzgx_obj_lbl_1_bss_3845C;
u8 fzgx_obj_lbl_1_bss_38460;
u8 lbl_1_bss_38460__fzgx_offset_1;
u16 lbl_1_bss_38460__fzgx_offset_2;
u32 lbl_1_bss_38460__fzgx_offset_4[6];
u8 lbl_1_bss_38460__fzgx_offset_1C;
u8 lbl_1_bss_38460__fzgx_offset_1D;
u16 lbl_1_bss_38460__fzgx_offset_1E;
u32 lbl_1_bss_38460__fzgx_offset_20[6];
u8 lbl_1_bss_38460__fzgx_offset_38;
u8 lbl_1_bss_38460__fzgx_offset_39;
u16 lbl_1_bss_38460__fzgx_offset_3A;
u32 lbl_1_bss_38460__fzgx_offset_3C[6];
u32 fzgx_obj_lbl_1_bss_384B4;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_38450;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_38454;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_38458;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3845C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_38460;
    s = *(u8 *)&lbl_1_bss_38460__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_38460__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_38460__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_38460__fzgx_offset_1C;
    s = *(u8 *)&lbl_1_bss_38460__fzgx_offset_1D;
    s = *(u8 *)&lbl_1_bss_38460__fzgx_offset_1E;
    s = *(u8 *)&lbl_1_bss_38460__fzgx_offset_20;
    s = *(u8 *)&lbl_1_bss_38460__fzgx_offset_38;
    s = *(u8 *)&lbl_1_bss_38460__fzgx_offset_39;
    s = *(u8 *)&lbl_1_bss_38460__fzgx_offset_3A;
    s = *(u8 *)&lbl_1_bss_38460__fzgx_offset_3C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384B4;
}
#pragma section code_type ".text"

void fn_1_411D4(u32 index, char *value) {
    char second_buffer[128];
    char buffer[128];
    int key;
    u32 *flags;
    struct { u32 value; } off;

    
    sprintf(buffer, (char *)&lbl_1_data_6708, value);
    key = DVDConvertPathToEntrynum(buffer);
    off.value = index * 4;
    flags = (u32 *)&fzgx_obj_lbl_1_bss_38460;

    if (*(u32 *)((u8 *)flags + off.value) == 0 ||
        *(int *)((u8 *)&lbl_1_bss_38460__fzgx_offset_1C + off.value) != key) {
        fn_1_412A0(index);
        *(int *)((u8 *)&lbl_1_bss_38460__fzgx_offset_1C + off.value) = key;
        sprintf(second_buffer, (char *)&lbl_1_data_6700, value);
        *(char **)((u8 *)&lbl_1_bss_38460__fzgx_offset_38 + off.value) = fn_1_D3884(second_buffer);
        *(u32 *)((u8 *)flags + off.value) =
            fn_1_D358C(buffer, *(char **)((u8 *)&lbl_1_bss_38460__fzgx_offset_38 + off.value));
    }
}
/* fzgx:end fn_1_411D4 */

/* fzgx:begin fn_1_412A0 */
typedef struct BssState {
    u8 pad_10[0x10];
    u32 second[7];
    s32 third[7];
    u32 first[7];
} BssState;


/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_38450;
u32 fzgx_obj_lbl_1_bss_38454;
u32 fzgx_obj_lbl_1_bss_38458;
u32 fzgx_obj_lbl_1_bss_3845C;
u32 fzgx_obj_lbl_1_bss_38460[7];
s32 lbl_1_bss_38460__fzgx_offset_1C[7];
u32 lbl_1_bss_38460__fzgx_offset_38[7];
u32 fzgx_obj_lbl_1_bss_384B4;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_38450;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_38454;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_38458;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3845C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_38460;
    s = *(u8 *)&lbl_1_bss_38460__fzgx_offset_1C;
    s = *(u8 *)&lbl_1_bss_38460__fzgx_offset_38;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_384B4;
}
#pragma section code_type ".text"

void fn_1_412A0(u32 index) {
    

    if (lbl_1_bss_38460__fzgx_offset_38[index] != 0) {
        fn_80071718( (u32)((void *)lbl_1_bss_38460__fzgx_offset_38[index]));
    }

    if (fzgx_obj_lbl_1_bss_38460[index] != 0) {
        fn_800711A8( (Obj_1_bss_38458_Target *)((void *)fzgx_obj_lbl_1_bss_38460[index]));
    }

    lbl_1_bss_38460__fzgx_offset_38[index] = 0;
    fzgx_obj_lbl_1_bss_38460[index] = 0;
    lbl_1_bss_38460__fzgx_offset_1C[index] = -1;
}
/* fzgx:end fn_1_412A0 */

/* fzgx:begin fn_1_41328 */
typedef struct RelocData {
    u32 count;
    u32 values[1];
} RelocData;

void fn_1_41328(RelocData *data) {
    u32 *values = data->values;
    u32 count = data->count;
    u32 i = 0;

    if (count & ((u32)1 << 31)) {
        return;
    }

    for (i = 0; i <= count; i++) {
        values[i] += (u32)data;
    }

    data->count |= ((u32)1 << 31);
}
/* fzgx:end fn_1_41328 */

/* fzgx:begin fn_1_41418 */
typedef struct Fn41418Data {
    u32 count;
    char *strings;
} Fn41418Data;

static inline u32 add_lengths(u32 length, u32 address) {
    return length + address;
}

char *fn_1_41418(Fn41418Data *data, u32 index) {
    u32 count = data->count & 0x7fffffff;
    u32 str = (u32)data->strings;

    if (index >= count) {
        return 0;
    }

    while (index != 0) {
        str = add_lengths((u32)strlen((char *)str), str);
        index -= 1;
        str += 1;
    }

    return (char *)str;
}
/* fzgx:end fn_1_41418 */

/* fzgx:begin fn_1_41488 */
typedef struct Fn41488Data {
    u32 count;
    char *strings;
} Fn41488Data;

static inline u32 add_lengths(u32 length, u32 address) {
    return length + address;
}

int fn_1_41488(Fn41488Data *data, const char *value) {
    u32 count = data->count & 0x7fffffff;
    u32 str = (u32)data->strings;
    u32 index = 0;

    while (index < count) {
        if (fn_80083BCC(value, (const char *)str) == 0) {
            return index;
        }
        str = add_lengths((u32)strlen((const char *)str), str);
        index += 1;
        str += 1;
    }

    return -1;
}
/* fzgx:end fn_1_41488 */

/* fzgx:begin fn_1_41CB8 */
typedef struct Fn41CB8Node {
    u8 pad0[0x30];
    struct Fn41CB8Node *next;
} Fn41CB8Node;

typedef struct Fn41CB8Entry {
    u8 pad0[4];
    Fn41CB8Node *next;
    u8 pad8[2];
    u16 count;
} Fn41CB8Entry;

typedef struct Fn41CB8Data {
    u8 pad0[1];
    u8 count;
    u16 flags;
    u8 pad4[4];
    void *resource;
    u8 padC[6];
    u16 index;
    u8 pad14[18];
    u8 limit;
    u8 pad27[1];
    Fn41CB8Entry *table_a;
    void *items_a;
    void *items_b;
    Fn41CB8Entry *table_b;
    u8 pad38[20];
    u8 base_index;
} Fn41CB8Data;

extern void fn_1_42E74(void *resource);
extern void *fn_1_42044(Fn41CB8Data *data, int index);
extern void *fn_1_42254(Fn41CB8Data *data, int index);
extern void fn_1_42458(void *entry, void *resource);
extern u8 lbl_1_data_6710[16];

static inline void fn_1_41CB8_walk(Fn41CB8Entry *entry, int n) {
    Fn41CB8Node *node;
    int j;
    node = entry->next;
    j = 0;
    while (j < n) {
        node = node->next;
        j++;
    }
}

#pragma opt_lifetimes on
static inline void * fn_1_41CB8_read_pointer(Fn41CB8Data * owner) { return owner->items_b; }
void fn_1_41CB8(Fn41CB8Data *data) {
    Fn41CB8Entry *entry;
    u32 offset;
    int i;
    void *a;
    void *b;
    void *c;
    void *resource;

    fn_1_42E74(data->resource);

    if (data->index < data->limit) {
        entry = (Fn41CB8Entry *)((u8 *)data->table_a + data->index * 12);
        (void) entry;  /* fzgx: keeps the web at its definition */
    } else if (data->table_b != 0) {
        entry = (Fn41CB8Entry *)((u8 *)data->table_b
            + (data->index - data->base_index) * 12);
    }

    if ((data->flags & 1) == 0) {
        fn_1_41CB8_walk(entry, entry->count);
    }

    i = 0;
    offset = 0;
    while (i < data->count) {
        a = fn_1_42044(data, i);
        b = (u8 *)data->items_a + offset;
        c = (u8 *)fn_1_41CB8_read_pointer(data) + offset;
        if (a != 0) {
            resource = fn_1_42254(data, i);
        } else {
            a = lbl_1_data_6710;
            resource = lbl_1_data_6710;
        }
        if (((0) == ((*(u16 *)b & 4)))) {
            fn_1_42458(b, resource);
        }
        fn_1_42458(c, a);
        offset += 16;
        i++;
    }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_41CB8 */
