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
extern void fn_8001AF64(void);
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
extern int fn_80016DF8(char *buffer);
extern void fn_1_412A0(u32 index);
extern size_t strlen(const char *str);
extern int fn_80083BCC(const char *s1, const char *s2);
extern u8 lbl_1_A9011300;
extern u8 lbl_1_A9011100;
extern u8 lbl_1_A9011000;

/* fzgx:begin fn_1_2FDBC pool noprologue */
#include "types.h"
#include "rel/main_rel/game.h"

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 fzgx_obj_lbl_1_bss_3C08[2];
u8 fzgx_obj_lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u8 fzgx_obj_lbl_1_bss_3C12;
u8 fzgx_obj_lbl_1_bss_3C12__b1;
u8 fzgx_obj_lbl_1_bss_3C12__b2;
u8 fzgx_obj_lbl_1_bss_3C12__b3;
u8 fzgx_obj_lbl_1_bss_3C12__b4;
u8 fzgx_obj_lbl_1_bss_3C12__b5;
u8 fzgx_obj_lbl_1_bss_3C12__b6;
u8 fzgx_obj_lbl_1_bss_3C12__b7;
u8 fzgx_obj_lbl_1_bss_3C12__b8;
u8 fzgx_obj_lbl_1_bss_3C12__b9;
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
u8 fzgx_pad_26B1B;
u8 fzgx_pad_26B1C;
u8 fzgx_obj_lbl_1_bss_26B1D;
u8 fzgx_obj_lbl_1_bss_26B1E;
u8 fzgx_obj_lbl_1_bss_26B1E__b1;
u8 fzgx_obj_lbl_1_bss_26B1E__b2;
u8 fzgx_obj_lbl_1_bss_26B1E__b3;
u8 fzgx_obj_lbl_1_bss_26B1E__b4;
u8 fzgx_obj_lbl_1_bss_26B1E__b5;
u8 fzgx_obj_lbl_1_bss_26B1E__b6;
u8 fzgx_obj_lbl_1_bss_26B1E__b7;
u8 fzgx_obj_lbl_1_bss_26B1E__b8;
u8 fzgx_obj_lbl_1_bss_26B1E__b9;
u8 fzgx_obj_lbl_1_bss_26B1E__b10;
u8 fzgx_obj_lbl_1_bss_26B1E__b11;
u8 fzgx_obj_lbl_1_bss_26B1E__b12;
u8 fzgx_obj_lbl_1_bss_26B1E__b13;
u8 fzgx_obj_lbl_1_bss_26B1E__b14;
u8 fzgx_obj_lbl_1_bss_26B1E__b15;
u8 fzgx_obj_lbl_1_bss_26B1E__b16;
u8 fzgx_obj_lbl_1_bss_26B1E__b17;
u8 fzgx_obj_lbl_1_bss_26B1E__b18;
u8 fzgx_obj_lbl_1_bss_26B1E__b19;
u8 fzgx_obj_lbl_1_bss_26B1E__b20;
u8 fzgx_obj_lbl_1_bss_26B1E__b21;
u8 fzgx_obj_lbl_1_bss_26B1E__b22;
u8 fzgx_obj_lbl_1_bss_26B1E__b23;
u8 fzgx_obj_lbl_1_bss_26B1E__b24;
u8 fzgx_obj_lbl_1_bss_26B1E__b25;
u8 fzgx_obj_lbl_1_bss_26B1E__b26;
u8 fzgx_obj_lbl_1_bss_26B1E__b27;
u8 fzgx_obj_lbl_1_bss_26B1E__b28;
u8 fzgx_obj_lbl_1_bss_26B1E__b29;
u8 fzgx_obj_lbl_1_bss_26B1E__b30;
u8 fzgx_obj_lbl_1_bss_26B1E__b31;
u8 fzgx_obj_lbl_1_bss_26B1E__b32;
u8 fzgx_obj_lbl_1_bss_26B1E__b33;
u8 fzgx_obj_lbl_1_bss_26B1E__b34;
u8 fzgx_obj_lbl_1_bss_26B1E__b35;
u8 fzgx_obj_lbl_1_bss_26B1E__b36;
u8 fzgx_obj_lbl_1_bss_26B1E__b37;
u8 fzgx_obj_lbl_1_bss_26B1E__b38;
u8 fzgx_obj_lbl_1_bss_26B1E__b39;
u8 fzgx_obj_lbl_1_bss_26B1E__b40;
u8 fzgx_obj_lbl_1_bss_26B1E__b41;
u8 fzgx_obj_lbl_1_bss_26B1E__b42;
u8 fzgx_obj_lbl_1_bss_26B1E__b43;
u8 fzgx_obj_lbl_1_bss_26B1E__b44;
u8 fzgx_obj_lbl_1_bss_26B1E__b45;
u32 fzgx_obj_lbl_1_bss_26B4C;
u32 fzgx_obj_lbl_1_bss_26B50;
u32 fzgx_obj_lbl_1_bss_26B54[2];
u8 fzgx_obj_lbl_1_bss_26B5C[30];
u8 fzgx_obj_lbl_1_bss_26B7A;
u8 fzgx_obj_lbl_1_bss_26B7A__b1;
u8 fzgx_obj_lbl_1_bss_26B7A__b2;
u8 fzgx_obj_lbl_1_bss_26B7A__b3;
u8 fzgx_obj_lbl_1_bss_26B7A__b4;
u8 fzgx_obj_lbl_1_bss_26B7A__b5;
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
    s = fzgx_obj_lbl_1_bss_3C12__b1;
    s = fzgx_obj_lbl_1_bss_3C12__b2;
    s = fzgx_obj_lbl_1_bss_3C12__b3;
    s = fzgx_obj_lbl_1_bss_3C12__b4;
    s = fzgx_obj_lbl_1_bss_3C12__b5;
    s = fzgx_obj_lbl_1_bss_3C12__b6;
    s = fzgx_obj_lbl_1_bss_3C12__b7;
    s = fzgx_obj_lbl_1_bss_3C12__b8;
    s = fzgx_obj_lbl_1_bss_3C12__b9;
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
    s = fzgx_pad_26B1B;
    s = fzgx_pad_26B1C;
    s = fzgx_obj_lbl_1_bss_26B1D;
    s = fzgx_obj_lbl_1_bss_26B1E;
    s = fzgx_obj_lbl_1_bss_26B1E__b1;
    s = fzgx_obj_lbl_1_bss_26B1E__b2;
    s = fzgx_obj_lbl_1_bss_26B1E__b3;
    s = fzgx_obj_lbl_1_bss_26B1E__b4;
    s = fzgx_obj_lbl_1_bss_26B1E__b5;
    s = fzgx_obj_lbl_1_bss_26B1E__b6;
    s = fzgx_obj_lbl_1_bss_26B1E__b7;
    s = fzgx_obj_lbl_1_bss_26B1E__b8;
    s = fzgx_obj_lbl_1_bss_26B1E__b9;
    s = fzgx_obj_lbl_1_bss_26B1E__b10;
    s = fzgx_obj_lbl_1_bss_26B1E__b11;
    s = fzgx_obj_lbl_1_bss_26B1E__b12;
    s = fzgx_obj_lbl_1_bss_26B1E__b13;
    s = fzgx_obj_lbl_1_bss_26B1E__b14;
    s = fzgx_obj_lbl_1_bss_26B1E__b15;
    s = fzgx_obj_lbl_1_bss_26B1E__b16;
    s = fzgx_obj_lbl_1_bss_26B1E__b17;
    s = fzgx_obj_lbl_1_bss_26B1E__b18;
    s = fzgx_obj_lbl_1_bss_26B1E__b19;
    s = fzgx_obj_lbl_1_bss_26B1E__b20;
    s = fzgx_obj_lbl_1_bss_26B1E__b21;
    s = fzgx_obj_lbl_1_bss_26B1E__b22;
    s = fzgx_obj_lbl_1_bss_26B1E__b23;
    s = fzgx_obj_lbl_1_bss_26B1E__b24;
    s = fzgx_obj_lbl_1_bss_26B1E__b25;
    s = fzgx_obj_lbl_1_bss_26B1E__b26;
    s = fzgx_obj_lbl_1_bss_26B1E__b27;
    s = fzgx_obj_lbl_1_bss_26B1E__b28;
    s = fzgx_obj_lbl_1_bss_26B1E__b29;
    s = fzgx_obj_lbl_1_bss_26B1E__b30;
    s = fzgx_obj_lbl_1_bss_26B1E__b31;
    s = fzgx_obj_lbl_1_bss_26B1E__b32;
    s = fzgx_obj_lbl_1_bss_26B1E__b33;
    s = fzgx_obj_lbl_1_bss_26B1E__b34;
    s = fzgx_obj_lbl_1_bss_26B1E__b35;
    s = fzgx_obj_lbl_1_bss_26B1E__b36;
    s = fzgx_obj_lbl_1_bss_26B1E__b37;
    s = fzgx_obj_lbl_1_bss_26B1E__b38;
    s = fzgx_obj_lbl_1_bss_26B1E__b39;
    s = fzgx_obj_lbl_1_bss_26B1E__b40;
    s = fzgx_obj_lbl_1_bss_26B1E__b41;
    s = fzgx_obj_lbl_1_bss_26B1E__b42;
    s = fzgx_obj_lbl_1_bss_26B1E__b43;
    s = fzgx_obj_lbl_1_bss_26B1E__b44;
    s = fzgx_obj_lbl_1_bss_26B1E__b45;
    s = fzgx_obj_lbl_1_bss_26B4C;
    s = fzgx_obj_lbl_1_bss_26B50;
    s = fzgx_obj_lbl_1_bss_26B54[0];
    s = fzgx_obj_lbl_1_bss_26B5C[0];
    s = fzgx_obj_lbl_1_bss_26B7A;
    s = fzgx_obj_lbl_1_bss_26B7A__b1;
    s = fzgx_obj_lbl_1_bss_26B7A__b2;
    s = fzgx_obj_lbl_1_bss_26B7A__b3;
    s = fzgx_obj_lbl_1_bss_26B7A__b4;
    s = fzgx_obj_lbl_1_bss_26B7A__b5;
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

/* fzgx:begin fn_1_32600 pool noprologue */
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
u32 fzgx_obj_lbl_1_bss_50EC[5];
u32 fzgx_obj_lbl_1_bss_5100;
u32 fzgx_obj_lbl_1_bss_5104[13];
u32 fzgx_obj_lbl_1_bss_5138[65];
u32 fzgx_obj_lbl_1_bss_523C[8];

#pragma section code_type ".fzgxpool"
static inline void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C30;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_50EC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5100;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5104;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5138;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_523C;
}
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

/* fzgx:begin fn_1_384E8 pool noprologue */
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
static u8 lbl_1_bss_3C00__fzgx_offset_4[0x2C];
static Sub30 lbl_1_bss_3C00__fzgx_offset_30;
static s16 lbl_1_bss_3C00__fzgx_offset_14E8;
static u8 lbl_1_bss_3C00__fzgx_offset_14EA[0x12];
static void *lbl_1_bss_3C00__fzgx_offset_1500;

static void primer(void)
{
    lbl_1_bss_3C00 = 0;
    lbl_1_bss_3C00__fzgx_offset_4[0] = 0;
    lbl_1_bss_3C00__fzgx_offset_30.unk_06 = 0;
    lbl_1_bss_3C00__fzgx_offset_14E8 = 0;
    lbl_1_bss_3C00__fzgx_offset_14EA[0] = 0;
    lbl_1_bss_3C00__fzgx_offset_1500 = 0;
}

void fn_1_384E8(void)
{
    fn_1_12F308();
    if (fn_1_4C10() == 0) {
        fn_1_12F358(lbl_1_bss_3C00__fzgx_offset_30.unk_06);
        if ((s32)lbl_1_bss_26C28 == 2) {
            if (fn_1_467F4() == 0) {
                fn_1_4A00(0, 0x1E, lbl_1_bss_3C00__fzgx_offset_1500);
                lbl_1_bss_26C28 = 1;
            }
        } else if ((s32)lbl_1_bss_26C28 != 0) {
            lbl_1_bss_3C00__fzgx_offset_14E8 = 0x26;
        } else if (fn_1_402D4() != 0) {
            fn_1_A2D84(0xA9010100);
            lbl_1_bss_26C28 = 2;
        }
    }
}
/* fzgx:end fn_1_384E8 */

/* fzgx:begin fn_1_385A4 pool */
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
u8 fzgx_obj_lbl_1_bss_3C12__b1;
u8 fzgx_obj_lbl_1_bss_3C12__b2;
u8 fzgx_obj_lbl_1_bss_3C12__b3;
u8 fzgx_obj_lbl_1_bss_3C12__b4;
u8 fzgx_obj_lbl_1_bss_3C12__b5;
u8 fzgx_obj_lbl_1_bss_3C12__b6;
u8 fzgx_obj_lbl_1_bss_3C12__b7;
u8 fzgx_obj_lbl_1_bss_3C12__b8;
u8 fzgx_obj_lbl_1_bss_3C12__b9;
u8 fzgx_obj_lbl_1_bss_3C1C[14];
u8 fzgx_obj_lbl_1_bss_3C2A;
u8 fzgx_obj_lbl_1_bss_3C2A__b1;
u8 fzgx_obj_lbl_1_bss_3C2A__b2;
u8 fzgx_obj_lbl_1_bss_3C2A__b3;
u8 fzgx_obj_lbl_1_bss_3C2A__b4;
u8 fzgx_obj_lbl_1_bss_3C2A__b5;
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
u8 fzgx_pad_26B1B;
u8 fzgx_pad_26B1C;
u8 fzgx_obj_lbl_1_bss_26B1D;
u8 fzgx_obj_lbl_1_bss_26B1E;
u8 fzgx_obj_lbl_1_bss_26B1E__b1;
u8 fzgx_obj_lbl_1_bss_26B1E__b2;
u8 fzgx_obj_lbl_1_bss_26B1E__b3;
u8 fzgx_obj_lbl_1_bss_26B1E__b4;
u8 fzgx_obj_lbl_1_bss_26B1E__b5;
u8 fzgx_obj_lbl_1_bss_26B1E__b6;
u8 fzgx_obj_lbl_1_bss_26B1E__b7;
u8 fzgx_obj_lbl_1_bss_26B1E__b8;
u8 fzgx_obj_lbl_1_bss_26B1E__b9;
u8 fzgx_obj_lbl_1_bss_26B1E__b10;
u8 fzgx_obj_lbl_1_bss_26B1E__b11;
u8 fzgx_obj_lbl_1_bss_26B1E__b12;
u8 fzgx_obj_lbl_1_bss_26B1E__b13;
u8 fzgx_obj_lbl_1_bss_26B1E__b14;
u8 fzgx_obj_lbl_1_bss_26B1E__b15;
u8 fzgx_obj_lbl_1_bss_26B1E__b16;
u8 fzgx_obj_lbl_1_bss_26B1E__b17;
u8 fzgx_obj_lbl_1_bss_26B1E__b18;
u8 fzgx_obj_lbl_1_bss_26B1E__b19;
u8 fzgx_obj_lbl_1_bss_26B1E__b20;
u8 fzgx_obj_lbl_1_bss_26B1E__b21;
u8 fzgx_obj_lbl_1_bss_26B1E__b22;
u8 fzgx_obj_lbl_1_bss_26B1E__b23;
u8 fzgx_obj_lbl_1_bss_26B1E__b24;
u8 fzgx_obj_lbl_1_bss_26B1E__b25;
u8 fzgx_obj_lbl_1_bss_26B1E__b26;
u8 fzgx_obj_lbl_1_bss_26B1E__b27;
u8 fzgx_obj_lbl_1_bss_26B1E__b28;
u8 fzgx_obj_lbl_1_bss_26B1E__b29;
u8 fzgx_obj_lbl_1_bss_26B1E__b30;
u8 fzgx_obj_lbl_1_bss_26B1E__b31;
u8 fzgx_obj_lbl_1_bss_26B1E__b32;
u8 fzgx_obj_lbl_1_bss_26B1E__b33;
u8 fzgx_obj_lbl_1_bss_26B1E__b34;
u8 fzgx_obj_lbl_1_bss_26B1E__b35;
u8 fzgx_obj_lbl_1_bss_26B1E__b36;
u8 fzgx_obj_lbl_1_bss_26B1E__b37;
u8 fzgx_obj_lbl_1_bss_26B1E__b38;
u8 fzgx_obj_lbl_1_bss_26B1E__b39;
u8 fzgx_obj_lbl_1_bss_26B1E__b40;
u8 fzgx_obj_lbl_1_bss_26B1E__b41;
u8 fzgx_obj_lbl_1_bss_26B1E__b42;
u8 fzgx_obj_lbl_1_bss_26B1E__b43;
u8 fzgx_obj_lbl_1_bss_26B1E__b44;
u8 fzgx_obj_lbl_1_bss_26B1E__b45;
u32 fzgx_obj_lbl_1_bss_26B4C;
u32 fzgx_obj_lbl_1_bss_26B50;
u32 fzgx_obj_lbl_1_bss_26B54[2];
u8 fzgx_obj_lbl_1_bss_26B5C[30];
u8 fzgx_obj_lbl_1_bss_26B7A;
u8 fzgx_obj_lbl_1_bss_26B7A__b1;
u8 fzgx_obj_lbl_1_bss_26B7A__b2;
u8 fzgx_obj_lbl_1_bss_26B7A__b3;
u8 fzgx_obj_lbl_1_bss_26B7A__b4;
u8 fzgx_obj_lbl_1_bss_26B7A__b5;
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
    s = fzgx_obj_lbl_1_bss_3C12__b1;
    s = fzgx_obj_lbl_1_bss_3C12__b2;
    s = fzgx_obj_lbl_1_bss_3C12__b3;
    s = fzgx_obj_lbl_1_bss_3C12__b4;
    s = fzgx_obj_lbl_1_bss_3C12__b5;
    s = fzgx_obj_lbl_1_bss_3C12__b6;
    s = fzgx_obj_lbl_1_bss_3C12__b7;
    s = fzgx_obj_lbl_1_bss_3C12__b8;
    s = fzgx_obj_lbl_1_bss_3C12__b9;
    s = fzgx_obj_lbl_1_bss_3C1C[0];
    s = fzgx_obj_lbl_1_bss_3C2A;
    s = fzgx_obj_lbl_1_bss_3C2A__b1;
    s = fzgx_obj_lbl_1_bss_3C2A__b2;
    s = fzgx_obj_lbl_1_bss_3C2A__b3;
    s = fzgx_obj_lbl_1_bss_3C2A__b4;
    s = fzgx_obj_lbl_1_bss_3C2A__b5;
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
    s = fzgx_pad_26B1B;
    s = fzgx_pad_26B1C;
    s = fzgx_obj_lbl_1_bss_26B1D;
    s = fzgx_obj_lbl_1_bss_26B1E;
    s = fzgx_obj_lbl_1_bss_26B1E__b1;
    s = fzgx_obj_lbl_1_bss_26B1E__b2;
    s = fzgx_obj_lbl_1_bss_26B1E__b3;
    s = fzgx_obj_lbl_1_bss_26B1E__b4;
    s = fzgx_obj_lbl_1_bss_26B1E__b5;
    s = fzgx_obj_lbl_1_bss_26B1E__b6;
    s = fzgx_obj_lbl_1_bss_26B1E__b7;
    s = fzgx_obj_lbl_1_bss_26B1E__b8;
    s = fzgx_obj_lbl_1_bss_26B1E__b9;
    s = fzgx_obj_lbl_1_bss_26B1E__b10;
    s = fzgx_obj_lbl_1_bss_26B1E__b11;
    s = fzgx_obj_lbl_1_bss_26B1E__b12;
    s = fzgx_obj_lbl_1_bss_26B1E__b13;
    s = fzgx_obj_lbl_1_bss_26B1E__b14;
    s = fzgx_obj_lbl_1_bss_26B1E__b15;
    s = fzgx_obj_lbl_1_bss_26B1E__b16;
    s = fzgx_obj_lbl_1_bss_26B1E__b17;
    s = fzgx_obj_lbl_1_bss_26B1E__b18;
    s = fzgx_obj_lbl_1_bss_26B1E__b19;
    s = fzgx_obj_lbl_1_bss_26B1E__b20;
    s = fzgx_obj_lbl_1_bss_26B1E__b21;
    s = fzgx_obj_lbl_1_bss_26B1E__b22;
    s = fzgx_obj_lbl_1_bss_26B1E__b23;
    s = fzgx_obj_lbl_1_bss_26B1E__b24;
    s = fzgx_obj_lbl_1_bss_26B1E__b25;
    s = fzgx_obj_lbl_1_bss_26B1E__b26;
    s = fzgx_obj_lbl_1_bss_26B1E__b27;
    s = fzgx_obj_lbl_1_bss_26B1E__b28;
    s = fzgx_obj_lbl_1_bss_26B1E__b29;
    s = fzgx_obj_lbl_1_bss_26B1E__b30;
    s = fzgx_obj_lbl_1_bss_26B1E__b31;
    s = fzgx_obj_lbl_1_bss_26B1E__b32;
    s = fzgx_obj_lbl_1_bss_26B1E__b33;
    s = fzgx_obj_lbl_1_bss_26B1E__b34;
    s = fzgx_obj_lbl_1_bss_26B1E__b35;
    s = fzgx_obj_lbl_1_bss_26B1E__b36;
    s = fzgx_obj_lbl_1_bss_26B1E__b37;
    s = fzgx_obj_lbl_1_bss_26B1E__b38;
    s = fzgx_obj_lbl_1_bss_26B1E__b39;
    s = fzgx_obj_lbl_1_bss_26B1E__b40;
    s = fzgx_obj_lbl_1_bss_26B1E__b41;
    s = fzgx_obj_lbl_1_bss_26B1E__b42;
    s = fzgx_obj_lbl_1_bss_26B1E__b43;
    s = fzgx_obj_lbl_1_bss_26B1E__b44;
    s = fzgx_obj_lbl_1_bss_26B1E__b45;
    s = fzgx_obj_lbl_1_bss_26B4C;
    s = fzgx_obj_lbl_1_bss_26B50;
    s = fzgx_obj_lbl_1_bss_26B54[0];
    s = fzgx_obj_lbl_1_bss_26B5C[0];
    s = fzgx_obj_lbl_1_bss_26B7A;
    s = fzgx_obj_lbl_1_bss_26B7A__b1;
    s = fzgx_obj_lbl_1_bss_26B7A__b2;
    s = fzgx_obj_lbl_1_bss_26B7A__b3;
    s = fzgx_obj_lbl_1_bss_26B7A__b4;
    s = fzgx_obj_lbl_1_bss_26B7A__b5;
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

/* fzgx:begin fn_1_39420 pool */
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
u8 fzgx_obj_lbl_1_bss_3C12__b1;
u8 fzgx_obj_lbl_1_bss_3C12__b2;
u8 fzgx_obj_lbl_1_bss_3C12__b3;
u8 fzgx_obj_lbl_1_bss_3C12__b4;
u8 fzgx_obj_lbl_1_bss_3C12__b5;
u8 fzgx_obj_lbl_1_bss_3C12__b6;
u8 fzgx_obj_lbl_1_bss_3C12__b7;
u8 fzgx_obj_lbl_1_bss_3C12__b8;
u8 fzgx_obj_lbl_1_bss_3C12__b9;
u8 fzgx_obj_lbl_1_bss_3C1C[14];
u8 fzgx_obj_lbl_1_bss_3C2A;
u8 fzgx_obj_lbl_1_bss_3C2A__b1;
u8 fzgx_obj_lbl_1_bss_3C2A__b2;
u8 fzgx_obj_lbl_1_bss_3C2A__b3;
u8 fzgx_obj_lbl_1_bss_3C2A__b4;
u8 fzgx_obj_lbl_1_bss_3C2A__b5;
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
u8 fzgx_pad_26B1B;
u8 fzgx_pad_26B1C;
u8 fzgx_obj_lbl_1_bss_26B1D;
u8 fzgx_obj_lbl_1_bss_26B1E;
u8 fzgx_obj_lbl_1_bss_26B1E__b1;
u8 fzgx_obj_lbl_1_bss_26B1E__b2;
u8 fzgx_obj_lbl_1_bss_26B1E__b3;
u8 fzgx_obj_lbl_1_bss_26B1E__b4;
u8 fzgx_obj_lbl_1_bss_26B1E__b5;
u8 fzgx_obj_lbl_1_bss_26B1E__b6;
u8 fzgx_obj_lbl_1_bss_26B1E__b7;
u8 fzgx_obj_lbl_1_bss_26B1E__b8;
u8 fzgx_obj_lbl_1_bss_26B1E__b9;
u8 fzgx_obj_lbl_1_bss_26B1E__b10;
u8 fzgx_obj_lbl_1_bss_26B1E__b11;
u8 fzgx_obj_lbl_1_bss_26B1E__b12;
u8 fzgx_obj_lbl_1_bss_26B1E__b13;
u8 fzgx_obj_lbl_1_bss_26B1E__b14;
u8 fzgx_obj_lbl_1_bss_26B1E__b15;
u8 fzgx_obj_lbl_1_bss_26B1E__b16;
u8 fzgx_obj_lbl_1_bss_26B1E__b17;
u8 fzgx_obj_lbl_1_bss_26B1E__b18;
u8 fzgx_obj_lbl_1_bss_26B1E__b19;
u8 fzgx_obj_lbl_1_bss_26B1E__b20;
u8 fzgx_obj_lbl_1_bss_26B1E__b21;
u8 fzgx_obj_lbl_1_bss_26B1E__b22;
u8 fzgx_obj_lbl_1_bss_26B1E__b23;
u8 fzgx_obj_lbl_1_bss_26B1E__b24;
u8 fzgx_obj_lbl_1_bss_26B1E__b25;
u8 fzgx_obj_lbl_1_bss_26B1E__b26;
u8 fzgx_obj_lbl_1_bss_26B1E__b27;
u8 fzgx_obj_lbl_1_bss_26B1E__b28;
u8 fzgx_obj_lbl_1_bss_26B1E__b29;
u8 fzgx_obj_lbl_1_bss_26B1E__b30;
u8 fzgx_obj_lbl_1_bss_26B1E__b31;
u8 fzgx_obj_lbl_1_bss_26B1E__b32;
u8 fzgx_obj_lbl_1_bss_26B1E__b33;
u8 fzgx_obj_lbl_1_bss_26B1E__b34;
u8 fzgx_obj_lbl_1_bss_26B1E__b35;
u8 fzgx_obj_lbl_1_bss_26B1E__b36;
u8 fzgx_obj_lbl_1_bss_26B1E__b37;
u8 fzgx_obj_lbl_1_bss_26B1E__b38;
u8 fzgx_obj_lbl_1_bss_26B1E__b39;
u8 fzgx_obj_lbl_1_bss_26B1E__b40;
u8 fzgx_obj_lbl_1_bss_26B1E__b41;
u8 fzgx_obj_lbl_1_bss_26B1E__b42;
u8 fzgx_obj_lbl_1_bss_26B1E__b43;
u8 fzgx_obj_lbl_1_bss_26B1E__b44;
u8 fzgx_obj_lbl_1_bss_26B1E__b45;
u32 fzgx_obj_lbl_1_bss_26B4C;
u32 fzgx_obj_lbl_1_bss_26B50;
u32 fzgx_obj_lbl_1_bss_26B54[2];
u8 fzgx_obj_lbl_1_bss_26B5C[30];
u8 fzgx_obj_lbl_1_bss_26B7A;
u8 fzgx_obj_lbl_1_bss_26B7A__b1;
u8 fzgx_obj_lbl_1_bss_26B7A__b2;
u8 fzgx_obj_lbl_1_bss_26B7A__b3;
u8 fzgx_obj_lbl_1_bss_26B7A__b4;
u8 fzgx_obj_lbl_1_bss_26B7A__b5;
u8 fzgx_obj_lbl_1_bss_26B80[150];
s8 lbl_1_bss_26B80__fzgx_offset_96;
u8 lbl_1_bss_26B80__fzgx_offset_97;
u8 lbl_1_bss_26B80__fzgx_offset_97__b1;
u8 lbl_1_bss_26B80__fzgx_offset_97__b2;
u8 lbl_1_bss_26B80__fzgx_offset_97__b3;
u8 lbl_1_bss_26B80__fzgx_offset_97__b4;
u8 lbl_1_bss_26B80__fzgx_offset_97__b5;
u8 lbl_1_bss_26B80__fzgx_offset_97__b6;
u8 lbl_1_bss_26B80__fzgx_offset_97__b7;
u8 lbl_1_bss_26B80__fzgx_offset_97__b8;
u8 lbl_1_bss_26B80__fzgx_offset_97__b9;
u8 lbl_1_bss_26B80__fzgx_offset_97__b10;
u8 lbl_1_bss_26B80__fzgx_offset_97__b11;
u8 lbl_1_bss_26B80__fzgx_offset_97__b12;
u8 lbl_1_bss_26B80__fzgx_offset_97__b13;
u8 lbl_1_bss_26B80__fzgx_offset_97__b14;
u8 lbl_1_bss_26B80__fzgx_offset_97__b15;
u8 lbl_1_bss_26B80__fzgx_offset_97__b16;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_3C00;
    s = fzgx_obj_lbl_1_bss_3C04;
    s = fzgx_obj_lbl_1_bss_3C08[0];
    s = fzgx_obj_lbl_1_bss_3C10;
    s = fzgx_obj_lbl_1_bss_3C11;
    s = fzgx_obj_lbl_1_bss_3C12;
    s = fzgx_obj_lbl_1_bss_3C12__b1;
    s = fzgx_obj_lbl_1_bss_3C12__b2;
    s = fzgx_obj_lbl_1_bss_3C12__b3;
    s = fzgx_obj_lbl_1_bss_3C12__b4;
    s = fzgx_obj_lbl_1_bss_3C12__b5;
    s = fzgx_obj_lbl_1_bss_3C12__b6;
    s = fzgx_obj_lbl_1_bss_3C12__b7;
    s = fzgx_obj_lbl_1_bss_3C12__b8;
    s = fzgx_obj_lbl_1_bss_3C12__b9;
    s = fzgx_obj_lbl_1_bss_3C1C[0];
    s = fzgx_obj_lbl_1_bss_3C2A;
    s = fzgx_obj_lbl_1_bss_3C2A__b1;
    s = fzgx_obj_lbl_1_bss_3C2A__b2;
    s = fzgx_obj_lbl_1_bss_3C2A__b3;
    s = fzgx_obj_lbl_1_bss_3C2A__b4;
    s = fzgx_obj_lbl_1_bss_3C2A__b5;
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
    s = fzgx_pad_26B1B;
    s = fzgx_pad_26B1C;
    s = fzgx_obj_lbl_1_bss_26B1D;
    s = fzgx_obj_lbl_1_bss_26B1E;
    s = fzgx_obj_lbl_1_bss_26B1E__b1;
    s = fzgx_obj_lbl_1_bss_26B1E__b2;
    s = fzgx_obj_lbl_1_bss_26B1E__b3;
    s = fzgx_obj_lbl_1_bss_26B1E__b4;
    s = fzgx_obj_lbl_1_bss_26B1E__b5;
    s = fzgx_obj_lbl_1_bss_26B1E__b6;
    s = fzgx_obj_lbl_1_bss_26B1E__b7;
    s = fzgx_obj_lbl_1_bss_26B1E__b8;
    s = fzgx_obj_lbl_1_bss_26B1E__b9;
    s = fzgx_obj_lbl_1_bss_26B1E__b10;
    s = fzgx_obj_lbl_1_bss_26B1E__b11;
    s = fzgx_obj_lbl_1_bss_26B1E__b12;
    s = fzgx_obj_lbl_1_bss_26B1E__b13;
    s = fzgx_obj_lbl_1_bss_26B1E__b14;
    s = fzgx_obj_lbl_1_bss_26B1E__b15;
    s = fzgx_obj_lbl_1_bss_26B1E__b16;
    s = fzgx_obj_lbl_1_bss_26B1E__b17;
    s = fzgx_obj_lbl_1_bss_26B1E__b18;
    s = fzgx_obj_lbl_1_bss_26B1E__b19;
    s = fzgx_obj_lbl_1_bss_26B1E__b20;
    s = fzgx_obj_lbl_1_bss_26B1E__b21;
    s = fzgx_obj_lbl_1_bss_26B1E__b22;
    s = fzgx_obj_lbl_1_bss_26B1E__b23;
    s = fzgx_obj_lbl_1_bss_26B1E__b24;
    s = fzgx_obj_lbl_1_bss_26B1E__b25;
    s = fzgx_obj_lbl_1_bss_26B1E__b26;
    s = fzgx_obj_lbl_1_bss_26B1E__b27;
    s = fzgx_obj_lbl_1_bss_26B1E__b28;
    s = fzgx_obj_lbl_1_bss_26B1E__b29;
    s = fzgx_obj_lbl_1_bss_26B1E__b30;
    s = fzgx_obj_lbl_1_bss_26B1E__b31;
    s = fzgx_obj_lbl_1_bss_26B1E__b32;
    s = fzgx_obj_lbl_1_bss_26B1E__b33;
    s = fzgx_obj_lbl_1_bss_26B1E__b34;
    s = fzgx_obj_lbl_1_bss_26B1E__b35;
    s = fzgx_obj_lbl_1_bss_26B1E__b36;
    s = fzgx_obj_lbl_1_bss_26B1E__b37;
    s = fzgx_obj_lbl_1_bss_26B1E__b38;
    s = fzgx_obj_lbl_1_bss_26B1E__b39;
    s = fzgx_obj_lbl_1_bss_26B1E__b40;
    s = fzgx_obj_lbl_1_bss_26B1E__b41;
    s = fzgx_obj_lbl_1_bss_26B1E__b42;
    s = fzgx_obj_lbl_1_bss_26B1E__b43;
    s = fzgx_obj_lbl_1_bss_26B1E__b44;
    s = fzgx_obj_lbl_1_bss_26B1E__b45;
    s = fzgx_obj_lbl_1_bss_26B4C;
    s = fzgx_obj_lbl_1_bss_26B50;
    s = fzgx_obj_lbl_1_bss_26B54[0];
    s = fzgx_obj_lbl_1_bss_26B5C[0];
    s = fzgx_obj_lbl_1_bss_26B7A;
    s = fzgx_obj_lbl_1_bss_26B7A__b1;
    s = fzgx_obj_lbl_1_bss_26B7A__b2;
    s = fzgx_obj_lbl_1_bss_26B7A__b3;
    s = fzgx_obj_lbl_1_bss_26B7A__b4;
    s = fzgx_obj_lbl_1_bss_26B7A__b5;
    s = fzgx_obj_lbl_1_bss_26B80[0];
    s = lbl_1_bss_26B80__fzgx_offset_96;
    s = lbl_1_bss_26B80__fzgx_offset_97;
    s = lbl_1_bss_26B80__fzgx_offset_97__b1;
    s = lbl_1_bss_26B80__fzgx_offset_97__b2;
    s = lbl_1_bss_26B80__fzgx_offset_97__b3;
    s = lbl_1_bss_26B80__fzgx_offset_97__b4;
    s = lbl_1_bss_26B80__fzgx_offset_97__b5;
    s = lbl_1_bss_26B80__fzgx_offset_97__b6;
    s = lbl_1_bss_26B80__fzgx_offset_97__b7;
    s = lbl_1_bss_26B80__fzgx_offset_97__b8;
    s = lbl_1_bss_26B80__fzgx_offset_97__b9;
    s = lbl_1_bss_26B80__fzgx_offset_97__b10;
    s = lbl_1_bss_26B80__fzgx_offset_97__b11;
    s = lbl_1_bss_26B80__fzgx_offset_97__b12;
    s = lbl_1_bss_26B80__fzgx_offset_97__b13;
    s = lbl_1_bss_26B80__fzgx_offset_97__b14;
    s = lbl_1_bss_26B80__fzgx_offset_97__b15;
    s = lbl_1_bss_26B80__fzgx_offset_97__b16;
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

/* fzgx:begin fn_1_3F75C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/game.h"

extern void fn_1_451E4(void);
extern void fn_1_D3214(void);
extern void fn_8001AF64(void);
extern s32 fn_1_467F4(void);
extern s32 fn_1_13018(void);

void fn_1_3F75C(void) {
    while (fn_1_467F4() || fn_1_13018()) {
        fn_1_451E4();
        fn_1_D3214();
        fn_8001AF64();
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

/* fzgx:begin fn_1_411D4 pool noprologue */
#include "types.h"
#include "rel/main_rel/game.h"

typedef struct Fn411D4Cache {
    u8 pad_00[0x10];
    u32 flags[7];
    int cached[7];
    char *generated[7];
} Fn411D4Cache;

extern int sprintf(char *buffer, char *format, ...);
extern int fn_80016DF8(char *buffer);
extern void fn_1_412A0(u32 index);
extern char *fn_1_D3884(char *buffer);
extern int fn_1_D358C(char *buffer, char *value);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_38450;
u32 fzgx_obj_lbl_1_bss_38454;
u32 fzgx_obj_lbl_1_bss_38458;
u32 fzgx_obj_lbl_1_bss_3845C;
u8 fzgx_obj_lbl_1_bss_38460;
u8 lbl_1_bss_38460_fill_38461;
u16 lbl_1_bss_38460_fill_38462;
u32 lbl_1_bss_38460_fill_38464[6];
u8 lbl_1_bss_38460_1C;
u8 lbl_1_bss_38460_fill_3847D;
u16 lbl_1_bss_38460_fill_3847E;
u32 lbl_1_bss_38460_fill_38480[6];
u8 lbl_1_bss_38460_38;
u8 lbl_1_bss_38460_fill_38499;
u16 lbl_1_bss_38460_fill_3849A;
u32 lbl_1_bss_38460_fill_3849C[6];
u32 fzgx_obj_lbl_1_bss_384B4;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_38450;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_38454;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_38458;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3845C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_38460;
    s = *(u8 *)&lbl_1_bss_38460_fill_38461;
    s = *(u8 *)&lbl_1_bss_38460_fill_38462;
    s = *(u8 *)&lbl_1_bss_38460_fill_38464;
    s = *(u8 *)&lbl_1_bss_38460_1C;
    s = *(u8 *)&lbl_1_bss_38460_fill_3847D;
    s = *(u8 *)&lbl_1_bss_38460_fill_3847E;
    s = *(u8 *)&lbl_1_bss_38460_fill_38480;
    s = *(u8 *)&lbl_1_bss_38460_38;
    s = *(u8 *)&lbl_1_bss_38460_fill_38499;
    s = *(u8 *)&lbl_1_bss_38460_fill_3849A;
    s = *(u8 *)&lbl_1_bss_38460_fill_3849C;
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
    key = fn_80016DF8(buffer);
    off.value = index * 4;
    flags = (u32 *)&fzgx_obj_lbl_1_bss_38460;

    if (*(u32 *)((u8 *)flags + off.value) == 0 ||
        *(int *)((u8 *)&lbl_1_bss_38460_1C + off.value) != key) {
        fn_1_412A0(index);
        *(int *)((u8 *)&lbl_1_bss_38460_1C + off.value) = key;
        sprintf(second_buffer, (char *)&lbl_1_data_6700, value);
        *(char **)((u8 *)&lbl_1_bss_38460_38 + off.value) = fn_1_D3884(second_buffer);
        *(u32 *)((u8 *)flags + off.value) =
            fn_1_D358C(buffer, *(char **)((u8 *)&lbl_1_bss_38460_38 + off.value));
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
