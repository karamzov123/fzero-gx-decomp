

#pragma use_lmw_stmw on


#pragma section ".sdata2" data_mode=far_abs

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef float f32;
typedef double f64;


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


typedef struct Sig_fn_80042228_AdxSjdHandle Sig_fn_80042228_AdxSjdHandle;
typedef struct Sig_fn_800571EC_LSCObject Sig_fn_800571EC_LSCObject;
struct fn_8004CD70_lbl_80178CBC_0_E192 {
s8 unk_0;
u8 pad_1[0x2];
u8 unk_3;
Sig_fn_80042228_AdxSjdHandle *unk_4;
ADXStream *unk_8;
AXRNAHandle *unk_C;
SJ *unk_10;
u32 unk_14;
SJ *unk_18[2];
u8 *unk_20;
s32 unk_24;
s32 unk_28;
u8 *unk_2C;
s32 unk_30;
s32 unk_34;
s32 unk_38;
s16 unk_3C;
s16 unk_3E;
s16 unk_40;
s16 unk_42[2];
s16 unk_46;
u8 pad_48[0xC];
u32 unk_54;
u32 unk_58;
u32 unk_5C;
u16 unk_60;
u8 pad_62[0x2];
u32 unk_64;
u16 unk_68;
u16 unk_6A;
u8 unk_6C;
u8 unk_6D;
u8 pad_6E[0x4];
u8 unk_72;
u8 pad_73[0x15];
u32 unk_88;
u8 pad_8C[0x8];
Sig_fn_800571EC_LSCObject *unk_94;
u8 unk_98;
u8 pad_99[0x13];
u8 *unk_AC;
u8 pad_B0[0x10];
};
extern ADXTHandle lbl_80178CBC[];
extern const char lbl_8009103C[];
extern void *memset(void *, int, u32);
extern void fn_800474E4(const char *);
extern SJ *fn_80058498(void *, s32, s32);
extern ADXStream *fn_8004B4E0(SJ *, s32);
extern void fn_8004CAC8(ADXTHandle *);
extern Sig_fn_80042228_AdxSjdHandle *fn_80042228(SJ *, s32, SJ **);
extern AXRNAHandle *fn_8004EF28(SJ **, s32, void *);
extern Sig_fn_800571EC_LSCObject *fn_800571EC(SJ *);
extern void fn_8005710C(Sig_fn_800571EC_LSCObject *, ADXStream *);


extern const f32 lbl_80091064[];
ADXTHandle *fn_8004CD70(s32 arg0, void *arg1, s32 arg2) {
struct fn_8004CD70_lbl_80178CBC_0_E192 *v2;
u8 *v0 = (u8 *)(((u32)arg1 + 63) & ~0x3F);
s32 v1 = arg2 - (v0 - (u8 *)arg1);
s32 channels = arg0;
s32 v5;
s32 v17;
union { f64 d; struct { u32 hi, lo; } w; } cv;
if (channels < 0 || arg1 == 0 || arg2 < 0) {
fn_800474E4(lbl_8009103C);
return 0;
}
for (v5 = 0; v5 < 16; v5++) {
if (((struct fn_8004CD70_lbl_80178CBC_0_E192 *)lbl_80178CBC)[v5].unk_0 == 0) break;
}
if (v5 == 16) return 0;
v2 = (struct fn_8004CD70_lbl_80178CBC_0_E192 *)&lbl_80178CBC[v5];
memset(v2, 0, 192);
v2->unk_3 = channels;
v2->unk_20 = v0 + ((channels * 12384) << 1);
v2->unk_24 = ((v1 - ((channels * 12384) << 1) - 292) / 2048) << 11;
v2->unk_28 = 36;
{
u8 *base = v2->unk_20;
s32 extra = v2->unk_28;
s32 size = v2->unk_24;
v2->unk_AC = (u8 *)(size + extra + (u32)base);
}
v2->unk_2C = v0;
v2->unk_30 = 8192;
v2->unk_34 = 8288;
v2->unk_14 = 0;
v2->unk_10 = fn_80058498(v2->unk_20, v2->unk_24, v2->unk_28);
if (v2->unk_10 == 0) { fn_8004CAC8((ADXTHandle *)v2); return 0; }
if ((v2->unk_8 = fn_8004B4E0(v2->unk_10, 0)) == 0) { fn_8004CAC8((ADXTHandle *)v2); return 0; }
for (v17 = 0; v17 < channels; v17++) {
v2->unk_18[v17] = fn_80058498(v2->unk_2C + ((v2->unk_34 * v17) << 1),
v2->unk_30 << 1, (v2->unk_34 - v2->unk_30) << 1);
if (v2->unk_18[v17] == 0) { fn_8004CAC8((ADXTHandle *)v2); return 0; }
}
if ((v2->unk_4 = fn_80042228(v2->unk_10, channels, v2->unk_18)) == 0) { fn_8004CAC8((ADXTHandle *)v2); return 0; }
if ((v2->unk_C = fn_8004EF28(v2->unk_18, channels, v0 + channels * 16576)) == 0) { fn_8004CAC8((ADXTHandle *)v2); return 0; }
if ((v2->unk_94 = fn_800571EC(v2->unk_10)) == 0) { fn_8004CAC8((ADXTHandle *)v2); return 0; }
fn_8005710C(v2->unk_94, v2->unk_8);
v2->unk_38 = 60;
v2->unk_3C = v2->unk_24 / 2048;
v2->unk_3E = (s32)(lbl_80091064[0] * (f32)v2->unk_3C);
v2->unk_40 = 0;
for (v17 = 0; v17 < channels; v17++) v2->unk_42[v17] = -128;
v2->unk_46 = 0;
v2->unk_6C = 1;
v2->unk_54 = 0;
v2->unk_58 = 0;
v2->unk_5C = 0;
v2->unk_60 = 0;
v2->unk_64 = 0;
v2->unk_68 = 0;
v2->unk_6A = 0;
v2->unk_6D = 1;
v2->unk_72 = 0;
v2->unk_88 = 0;
v2->unk_98 = 0;
v2->unk_0 = 1;
return (ADXTHandle *)v2;
}
