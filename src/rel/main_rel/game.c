#include "types.h"
#include "dolphin/types.h"
#include "font.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"
#include "game/pad.h"

/* Accepted shortcut (for now): the prototypes of functions of other translation units in this file follow the
 * retail call sites of game.c. Some differ from the definition that main has in the other file:
 * s32 result where the other file returns u32 (fn_1_467F4, fn_1_13018, ghost_test_record_flag0, fn_1_F9D44,
 * fn_1_F22D4), u8 fn_1_F45B4, s8 parameter of fn_1_86900 (each call sign-extends the argument), int parameter of
 * fn_1_8627C, GXColor * parameter of fn_1_49F0 and fn_1_49514, char * result of fn_1_7F58C, typed parameters of
 * fn_1_3F8C, fn_1_45D0, fn_1_12F28C, fn_1_12F30C, fn_800713E0 and fn_8004CD70. */
typedef struct GameCar GameCar;
typedef struct RaceBuf RaceBuf;
typedef struct BurnerSlot BurnerSlot;
typedef struct Racer Racer;

typedef struct GXColor {
    u8 r, g, b, a;
} GXColor;

/* Layouts of objects other TUs own (copied from the generated module headers) */
typedef struct {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u8 pad_10[0x18];
} Obj_1_data_27DE0;
typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
} Obj_1_bss_38458_Target;
typedef struct {
    void *unk_0;
    void *unk_4;
} Obj_1_bss_6EAD0_At0;
typedef struct {
    Obj_1_bss_6EAD0_At0 *unk_0;
    u8 pad_4[0x704];
} Obj_1_bss_6EAD0;

/* _prologue */
typedef struct Sig_ADXT_Pause_AdxSjdHandle Sig_ADXT_Pause_AdxSjdHandle;

/* _prologue */
typedef struct Sig_ADXT_Pause_ADXStream Sig_ADXT_Pause_ADXStream;

/* _prologue */
typedef struct Sig_ADXT_Pause_AXRNAHandle Sig_ADXT_Pause_AXRNAHandle;

/* _prologue */
typedef struct Sig_ADXT_Pause_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Pause_SJCK;

/* _prologue */
typedef void (*Sig_ADXT_Pause_SJErrorCallback)(void *object, int error);

/* _prologue */
typedef struct Sig_ADXT_Pause_SJInterface Sig_ADXT_Pause_SJInterface;

/* _prologue */
typedef struct Sig_ADXT_Pause_SJ Sig_ADXT_Pause_SJ;

/* _prologue */
struct Sig_ADXT_Pause_SJ {
    const Sig_ADXT_Pause_SJInterface *interface;
};

/* _prologue */
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

/* _prologue */
typedef struct Sig_ADXT_Pause_ADX_AMP Sig_ADXT_Pause_ADX_AMP;

/* _prologue */
typedef struct Sig_ADXT_Pause_LSCObject Sig_ADXT_Pause_LSCObject;

/* _prologue */
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

/* _prologue */
typedef struct Sig_ADXT_Stop_AdxSjdHandle Sig_ADXT_Stop_AdxSjdHandle;

/* _prologue */
typedef struct Sig_ADXT_Stop_ADXStream Sig_ADXT_Stop_ADXStream;

/* _prologue */
typedef struct Sig_ADXT_Stop_AXRNAHandle Sig_ADXT_Stop_AXRNAHandle;

/* _prologue */
typedef struct Sig_ADXT_Stop_SJCK {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK;

/* _prologue */
typedef void (*Sig_ADXT_Stop_SJErrorCallback)(void *object, int error);

/* _prologue */
typedef struct Sig_ADXT_Stop_SJInterface Sig_ADXT_Stop_SJInterface;

/* _prologue */
typedef struct Sig_ADXT_Stop_SJ Sig_ADXT_Stop_SJ;

/* _prologue */
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

/* _prologue */
struct Sig_ADXT_Stop_SJ {
    const Sig_ADXT_Stop_SJInterface *interface;
};

/* _prologue */
typedef struct Sig_ADXT_Stop_ADX_AMP Sig_ADXT_Stop_ADX_AMP;

/* _prologue */
typedef struct Sig_ADXT_Stop_LSCObject Sig_ADXT_Stop_LSCObject;

/* _prologue */
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

/* _prologue */
/* GameEntrant: see GameEntrant */

/* _prologue */
/* GameEntry: see GameEntry */

/* _prologue */
typedef struct {
    u8 pad[0x2f8];
    GXColor value_2f8;
    GXColor value_2fc;
    u32 value_300;
    u32 value_304;
    u32 value_308;
    u32 value_30c;
    u32 value_310;
    u32 value_314;
    u32 value_318;
    u32 value_31c;
} Fn40710Config;

/* _prologue */
typedef struct Node {
    u32 unk_0;
    u8 pad_4[0x8];
    s32 count;
    struct Node *children;
    u8 pad_14[0x50 - 0x14];
} Node;

/* _prologue */
typedef struct StcoliNode StcoliNode;

/* _prologue */
struct StcoliNode {
    u32 flags;
    u8 pad[8];
    s32 count;
    StcoliNode *items;
    u8 rest[0x3c];
};

/* _prologue */
typedef struct StcoliVec {
    u32 x;
    u32 y;
    u32 z;
} StcoliVec;

/* _prologue */
typedef struct {
    unsigned char pad0[0x0c];
    int count;
    void *entries;
} Fn118F28Object;

/* _prologue */
typedef struct Fn_1_20258Constants {
    unsigned char pad08[8];
    f32 value08;
    f32 value0c;
    unsigned char pad10[0xb0];
    f64 valuec0;
    f32 valuec8;
    unsigned char padcc[4];
    f64 valued0;
} Fn_1_20258Constants;

/* _prologue */
typedef struct {
    u32 f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24;
    u32 f28, f2c, f30, f34, f38, f3c, f40, f44;
} Cfg;

/* _prologue */
typedef struct {
    u8 pad_0[0x4];
    Cfg *cfg;
    u8 pad_8[0xc];
    f32 fx;
    f32 fy;
    f32 fz;
    f32 rxv;
    f32 ryv;
    f32 rzv;
    f32 sxv;
    f32 syv;
    f32 szv;
} Entity;

/* _prologue */
typedef struct {
    u32 count;
    u32 entries[1];
} Stack;

/* _prologue */
struct fn_1_2B478_lbl_801A6D00 {
    u32 unk_0;
};

/* _prologue */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

/* _prologue */
typedef struct {
    f32 m[10];
    f64 d;
} Mtx;

/* _prologue */
struct Pool {
    u8 pad_0[0xc];
    f32 one;
    u8 pad_10[0xc];
    f32 two;
    u8 pad_20[0x14];
    f32 half;
};

/* _prologue */
struct fn_1_207DC_pool {
    u8 pad_0[8];
    f32 zero;
    f32 one;
    u8 pad_10[0xB0];
    f64 eps;
    f32 pi;
    u8 pad_CC[4];
    f64 two;
};

/* _prologue */
struct fn_1_21950_lbl_1_rodata_6C8 {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
    f32 unk_20;
    u8 pad_24[0x10];
    f32 unk_34;
};

/* _prologue */
typedef struct {
    u8 pad_0[0x30];
    Vec3 pos;
    f32 ax;
    f32 ay;
    Vec3 v0;
    Vec3 e;
    Vec3 m;
    f32 d0;
    f32 d1;
    Vec3 o;
    u32 f7c;
    u8 pad_80[0x7c];
    u32 fffc;
} Rec;

/* _prologue */
typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
} fn_1_18784_Cfg;

/* _prologue */
typedef struct {
    u32 f00;
    fn_1_18784_Cfg *cfg;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    f32 f18;
} Src;

/* _prologue */
typedef struct {
    u32 f00;
    fn_1_18784_Cfg *cfg;
    u32 f08;
    s32 f0c;
    Src *f10;
    u32 f14;
    f32 f18;
    f32 f1c;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
} Motion;

/* _prologue */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_21CFC_Vec;

/* _prologue */
struct fn_1_2D524_Copy200 { char *a[10][5]; };

/* _prologue */
struct fn_1_2D524_Copy8 { char *a[2]; };

/* _prologue */
struct fn_1_2D524_lbl_1_rodata_BD8 {
    u8 pad_0[0x24];
    f32 unk_24;
    u8 pad_28[0x30];
    struct fn_1_2D524_Copy200 unk_58;
    struct fn_1_2D524_Copy8 unk_120;
    f32 unk_128;
    f32 unk_12C;
    f32 unk_130;
};

/* fn_1_2C908 */
struct fn_1_2C908_lbl_1_bss_3C00 {
    u8 pad_0[0x30];
    u32 unk_30;
    u8 pad_34[0x14B4];
    u16 unk_14E8;
    u8 pad_14EA[0x2];
    u16 unk_14EC;
    u8 pad_14EE[0x6];
    u8 unk_14F4;
    u8 pad_14F5[0x3];
    u32 unk_14F8;
    u16 unk_14FC;
};

/* fn_1_2C97C */
typedef struct PadButtons {
    u16 unk_0;
    u8 pad_2[0x6];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
} PadButtons;
extern PadButtons lbl_1_bss_9F8[4];

/* fn_1_2C97C */
/* Obj3C30: see the unit type after Config */

/* fn_1_2C97C */
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 pad_4[0x2C];
} Obj5108;

/* fn_1_2C97C */
/* Racer: see Racer */

/* fn_1_2CBAC */
typedef struct {
    u16 unk_0;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4[4];
    u16 unk_8[4];
    u16 unk_10;
    u16 unk_12;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    char unk_20[0xC0];
    u8 unk_E0;
    u8 unk_E1;
    u8 unk_E2;
    u8 unk_E3;
    u8 unk_E4;
    u8 unk_E5;
    u8 unk_E6[5];
    u8 unk_EB;
} Obj5138;

/* fn_1_2D038 */
struct fn_1_2D038_hdr { u32 unk_0; u8 pad_4[1]; u8 unk_5; u8 pad_6[2]; };

/* fn_1_2D038 */
struct fn_1_2D038_lbl_1_bss_3C00 {
u8 pad_0[0x2A]; s16 unk_2A; u8 pad_2C[4]; struct fn_1_2D038_hdr unk_30; u8 pad_38[0x15EC];
u8 unk_1624; u8 pad_1625[3]; u32 unk_1628; u32 unk_162C; u32 unk_1630; u8 unk_1634; u8 pad_1635[3]; u32 unk_1638;
};

/* fn_1_2D038 */
struct fn_1_2D038_lbl_1_rodata_BD8 { u8 pad_0[4]; f32 unk_4,unk_8,unk_C,unk_10,unk_14,unk_18,unk_1C,unk_20,unk_24,unk_28,unk_2C,unk_30,unk_34,unk_38,unk_3C,unk_40,unk_44,unk_48; u8 pad_4C[4]; f64 unk_50; };

/* fn_1_2D038 */
struct fn_1_2D038_obj_3C30 { struct fn_1_2D038_hdr hdr; u8 pad_8[0x14BC - 8]; };

/* fn_1_2D038 */
struct fn_1_2D038_obj_5138 { u8 pad_0[0xEC]; u8 unk_EC; u8 pad_ED[3]; u32 unk_F0; u32 unk_F4; u32 unk_F8; u8 unk_FC; u8 pad_FD[3]; u32 unk_100; };

/* fn_1_2D038 */
struct FzgxCopy_88 { u32 words[22]; };

/* fn_1_2D524 */
struct fn_1_2D524_Arg0 {
    u16 unk_0;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4[4];
    u16 unk_8[6];
    f32 unk_14;
    f32 unk_18;
    u8 pad_1C[4];
    char unk_20[0xC1];
    u8 unk_E1;
    u8 unk_E2;
    u8 unk_E3;
    u8 unk_E4;
    u8 unk_E5;
    u8 unk_E6[5];
    u8 unk_EB;
};

/* fn_1_2D524 */
struct fn_1_2D524_lbl_1_data_5730 {
    u8 pad_0[0x538];
    char *unk_538;
    u8 pad_53C[0x50];
    char *unk_58C;
    u8 pad_590[0x58];
    char *unk_5E8;
    u8 pad_5EC[0x58];
    char *unk_644;
    u8 pad_648[0x4C];
    char *unk_694;
    u8 pad_698[0x50];
    char *unk_6E8;
    u8 pad_6EC[0x1C];
    char *unk_708;
};

/* fn_1_2D524 */
struct fn_1_2D524_lbl_1_bss_3C30 {
    u8 pad_0[0x6];
    u8 unk_6;
};

/* fn_1_2D888 */
typedef struct Node_fn_1_2D888 {
    u32 unk_0;
    u8 pad_4[0x8];
    s32 count;
    struct Node_fn_1_2D888 *children;
    u8 pad_14[0x50 - 0x14];
} Node_fn_1_2D888;

/* fn_1_2D888 */
typedef struct StcoliNode_fn_1_2D888 StcoliNode_fn_1_2D888;

/* fn_1_2D888 */
struct StcoliNode_fn_1_2D888 {
    u32 flags;
    u8 pad[8];
    s32 count;
    StcoliNode_fn_1_2D888 *items;
    u8 rest[0x3c];
};

/* fn_1_2D888 */
typedef struct StcoliVec_fn_1_2D888 {
    u32 x;
    u32 y;
    u32 z;
} StcoliVec_fn_1_2D888;

/* fn_1_2D888 */
typedef struct {
    unsigned char pad0[0x0c];
    int count;
    void *entries;
} Fn118F28Object_fn_1_2D888;

/* fn_1_2D888 */
typedef struct Fn_1_20258Constants_fn_1_2D888 {
    unsigned char pad08[8];
    f32 value08;
    f32 value0c;
    unsigned char pad10[0xb0];
    f64 valuec0;
    f32 valuec8;
    unsigned char padcc[4];
    f64 valued0;
} Fn_1_20258Constants_fn_1_2D888;

/* fn_1_2D888 */
typedef struct {
    u32 f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24;
    u32 f28, f2c, f30, f34, f38, f3c, f40, f44;
} Cfg_fn_1_2D888;

/* fn_1_2D888 */
typedef struct {
    u8 pad_0[0x4];
    Cfg_fn_1_2D888 *cfg;
    u8 pad_8[0xc];
    f32 fx;
    f32 fy;
    f32 fz;
    f32 rxv;
    f32 ryv;
    f32 rzv;
    f32 sxv;
    f32 syv;
    f32 szv;
} Entity_fn_1_2D888;

/* fn_1_2D888 */
typedef struct {
    u32 count;
    u32 entries[1];
} Stack_fn_1_2D888;

/* fn_1_2D888 */
struct fn_1_2B478_lbl_801A6D00_fn_1_2D888 {
    u32 unk_0;
};

/* fn_1_2D888 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3_fn_1_2D888;

/* fn_1_2D888 */
typedef struct {
    f32 m[10];
    f64 d;
} Mtx_fn_1_2D888;

/* fn_1_2D888 */
struct Pool_fn_1_2D888 {
    u8 pad_0[0xc];
    f32 one;
    u8 pad_10[0xc];
    f32 two;
    u8 pad_20[0x14];
    f32 half;
};

/* fn_1_2D888 */
struct fn_1_207DC_pool_fn_1_2D888 {
    u8 pad_0[8];
    f32 zero;
    f32 one;
    u8 pad_10[0xB0];
    f64 eps;
    f32 pi;
    u8 pad_CC[4];
    f64 two;
};

/* fn_1_2D888 */
struct fn_1_21950_lbl_1_rodata_6C8_fn_1_2D888 {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
    f32 unk_20;
    u8 pad_24[0x10];
    f32 unk_34;
};

/* fn_1_2D888 */
typedef struct {
    u8 pad_0[0x30];
    Vec3_fn_1_2D888 pos;
    f32 ax;
    f32 ay;
    Vec3_fn_1_2D888 v0;
    Vec3_fn_1_2D888 e;
    Vec3_fn_1_2D888 m;
    f32 d0;
    f32 d1;
    Vec3_fn_1_2D888 o;
    u32 f7c;
    u8 pad_80[0x7c];
    u32 fffc;
} Rec_fn_1_2D888;

/* fn_1_2D888 */
typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
} fn_1_18784_Cfg_fn_1_2D888;

/* fn_1_2D888 */
typedef struct {
    u32 f00;
    fn_1_18784_Cfg_fn_1_2D888 *cfg;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    f32 f18;
} Src_fn_1_2D888;

/* fn_1_2D888 */
typedef struct {
    u32 f00;
    fn_1_18784_Cfg_fn_1_2D888 *cfg;
    u32 f08;
    s32 f0c;
    Src_fn_1_2D888 *f10;
    u32 f14;
    f32 f18;
    f32 f1c;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
} Motion_fn_1_2D888;

/* fn_1_2D888 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_21CFC_Vec_fn_1_2D888;

/* fn_1_2D888 */
struct fn_1_2D524_Copy200_fn_1_2D888 { char *a[10][5]; };

/* fn_1_2D888 */
struct fn_1_2D524_Copy8_fn_1_2D888 { char *a[2]; };

/* fn_1_2D888 */
struct fn_1_2D524_lbl_1_rodata_BD8_fn_1_2D888 {
    u8 pad_0[0x24];
    f32 unk_24;
    u8 pad_28[0x30];
    struct fn_1_2D524_Copy200_fn_1_2D888 unk_58;
    struct fn_1_2D524_Copy8_fn_1_2D888 unk_120;
    f32 unk_128;
    f32 unk_12C;
    f32 unk_130;
};

/* fn_1_2D888 */
typedef struct {
    u8 pad_0[0x10];
    u16 x;      /* 0x10 */
    u16 y;      /* 0x12 */
    f32 w;      /* 0x14 */
    f32 h;      /* 0x18 */
    f32 t;      /* 0x1C */
    u8 unk_20[0xC2];
    u8 active;  /* 0xE2 */
} fn_1_2D888_Box;

/* fn_1_2D888 */
typedef struct {
    s32 mode;       /* 0x00 */
    f32 x;          /* 0x04 */
    f32 y;          /* 0x08 */
    f32 z;          /* 0x0C */
    u8 pad_10[0x1C];
    f32 alpha;      /* 0x2C */
    s32 count;      /* 0x30 */
    u8 pad_34[0x24];
} fn_1_2D888_Text;

/* fn_1_2DE00 */
typedef u32 (*GameStepFn)(struct Obj3C30 *gs);

/* fn_1_2DE00 */
typedef int (*GameModeFn)(struct Obj3C30 *gs);

/* fn_1_2DE00 */
typedef struct GamePlayer {
    u32 unk_0;
    u16 unk_4;
    u16 unk_6;
    u8 unk_8;
    u8 unk_9[5];
    u8 unk_E[5];
    u8 unk_13[5];
    u16 unk_18[5];
    u16 unk_22;
    u32 unk_24[5];
    u32 unk_38[5];
    u16 unk_4C[5];
    u8 pad_56[0x2];
    u32 unk_58;
    u8 pad_5C[0x1C];
    u32 unk_78;
    u8 unk_7C;
    u8 unk_7D;
    u8 unk_7E;
    u8 pad_7F[0x1];
    u8 unk_80;
    u8 unk_81;
    u8 unk_82;
    u8 unk_83;
    u16 unk_84;
    s16 unk_86;
    u16 unk_88;
    u16 unk_8A;
    s16 unk_8C;
    s16 unk_8E;
    u32 unk_90;
    u32 unk_94;
    s16 unk_98;
    u16 unk_9A;
    s16 unk_9C;
    u16 unk_9E;
} GamePlayer;

/* fn_1_2DE00 */
/* Obj3C30: see Obj3C30 */

/* fn_1_2DE00 */
typedef struct GameSlotEntry {
    void *unk_0;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 pad_7[0x1];
} GameSlotEntry;

/* fn_1_2DE00 */
typedef struct GameSlotTable {
    GameSlotEntry entries[30];
    GamePlayer player;
    u8 unk_190;
    u8 unk_191;
    u8 unk_192;
    u8 pad_193[0x1];
    u8 unk_194[4];
} GameSlotTable;

/* fn_1_2DE00 */
typedef struct {
    u8 pad_0[3];
    u8 unk_3;
    u8 pad_4[0x2C];
} GameObj5108;

/* fn_1_2DE00 */
/* Racer: see Racer */

/* fn_1_2DE00 */
typedef struct GameRaceRecord {
    u8 pad_0[0xFC];
    f32 unk_FC;
    f32 unk_100;
    u8 pad_104[0x11];
    u8 unk_115;
    u8 pad_116[0x2];
    s32 unk_118;
    s32 unk_11C;
    u8 pad_120[0x48];
    u8 unk_168;
    u8 unk_169;
    u16 unk_16A;
    u8 pad_16C[0x68];
    u8 unk_1D4;
    u8 unk_1D5;
    u16 unk_1D6;
    u8 pad_1D8[0x8];
    u8 unk_1E0;
    u8 unk_1E1;
    u16 unk_1E2;
    u8 pad_1E4[0x18];
} GameRaceRecord;

/* fn_1_2DE00 */
/* GameCar: see the unit type at the end */

/* fn_1_2DE00 */
typedef struct {
    u8 pad_0[0x81C0];
} GameRaceBuf;

/* fn_1_2DF98 */
typedef struct Node_fn_1_2DF98 {
    u32 unk_0;
    u8 pad_4[0x8];
    s32 count;
    struct Node_fn_1_2DF98 *children;
    u8 pad_14[0x50 - 0x14];
} Node_fn_1_2DF98;

/* fn_1_2DF98 */
typedef struct StcoliNode_fn_1_2DF98 StcoliNode_fn_1_2DF98;

/* fn_1_2DF98 */
struct StcoliNode_fn_1_2DF98 {
    u32 flags;
    u8 pad[8];
    s32 count;
    StcoliNode_fn_1_2DF98 *items;
    u8 rest[0x3c];
};

/* fn_1_2DF98 */
typedef struct StcoliVec_fn_1_2DF98 {
    u32 x;
    u32 y;
    u32 z;
} StcoliVec_fn_1_2DF98;

/* fn_1_2DF98 */
typedef struct {
    unsigned char pad0[0x0c];
    int count;
    void *entries;
} Fn118F28Object_fn_1_2DF98;

/* fn_1_2DF98 */
typedef struct Fn_1_20258Constants_fn_1_2DF98 {
    unsigned char pad08[8];
    f32 value08;
    f32 value0c;
    unsigned char pad10[0xb0];
    f64 valuec0;
    f32 valuec8;
    unsigned char padcc[4];
    f64 valued0;
} Fn_1_20258Constants_fn_1_2DF98;

/* fn_1_2DF98 */
typedef struct {
    u32 f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24;
    u32 f28, f2c, f30, f34, f38, f3c, f40, f44;
} Cfg_fn_1_2DF98;

/* fn_1_2DF98 */
typedef struct {
    u8 pad_0[0x4];
    Cfg_fn_1_2DF98 *cfg;
    u8 pad_8[0xc];
    f32 fx;
    f32 fy;
    f32 fz;
    f32 rxv;
    f32 ryv;
    f32 rzv;
    f32 sxv;
    f32 syv;
    f32 szv;
} Entity_fn_1_2DF98;

/* fn_1_2DF98 */
typedef struct {
    u32 count;
    u32 entries[1];
} Stack_fn_1_2DF98;

/* fn_1_2DF98 */
struct fn_1_2B478_lbl_801A6D00_fn_1_2DF98 {
    u32 unk_0;
};

/* fn_1_2DF98 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3_fn_1_2DF98;

/* fn_1_2DF98 */
typedef struct {
    f32 m[10];
    f64 d;
} Mtx_fn_1_2DF98;

/* fn_1_2DF98 */
struct Pool_fn_1_2DF98 {
    u8 pad_0[0xc];
    f32 one;
    u8 pad_10[0xc];
    f32 two;
    u8 pad_20[0x14];
    f32 half;
};

/* fn_1_2DF98 */
struct fn_1_207DC_pool_fn_1_2DF98 {
    u8 pad_0[8];
    f32 zero;
    f32 one;
    u8 pad_10[0xB0];
    f64 eps;
    f32 pi;
    u8 pad_CC[4];
    f64 two;
};

/* fn_1_2DF98 */
struct fn_1_21950_lbl_1_rodata_6C8_fn_1_2DF98 {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
    f32 unk_20;
    u8 pad_24[0x10];
    f32 unk_34;
};

/* fn_1_2DF98 */
typedef struct {
    u8 pad_0[0x30];
    Vec3_fn_1_2DF98 pos;
    f32 ax;
    f32 ay;
    Vec3_fn_1_2DF98 v0;
    Vec3_fn_1_2DF98 e;
    Vec3_fn_1_2DF98 m;
    f32 d0;
    f32 d1;
    Vec3_fn_1_2DF98 o;
    u32 f7c;
    u8 pad_80[0x7c];
    u32 fffc;
} Rec_fn_1_2DF98;

/* fn_1_2DF98 */
typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
} fn_1_18784_Cfg_fn_1_2DF98;

/* fn_1_2DF98 */
typedef struct {
    u32 f00;
    fn_1_18784_Cfg_fn_1_2DF98 *cfg;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    f32 f18;
} Src_fn_1_2DF98;

/* fn_1_2DF98 */
typedef struct {
    u32 f00;
    fn_1_18784_Cfg_fn_1_2DF98 *cfg;
    u32 f08;
    s32 f0c;
    Src_fn_1_2DF98 *f10;
    u32 f14;
    f32 f18;
    f32 f1c;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
} Motion_fn_1_2DF98;

/* fn_1_2DF98 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_21CFC_Vec_fn_1_2DF98;

/* fn_1_2DF98 */
struct fn_1_2D524_Copy200_fn_1_2DF98 { char *a[10][5]; };

/* fn_1_2DF98 */
struct fn_1_2D524_Copy8_fn_1_2DF98 { char *a[2]; };

/* fn_1_2DF98 */
struct fn_1_2D524_lbl_1_rodata_BD8_fn_1_2DF98 {
    u8 pad_0[0x24];
    f32 unk_24;
    u8 pad_28[0x30];
    struct fn_1_2D524_Copy200_fn_1_2DF98 unk_58;
    struct fn_1_2D524_Copy8_fn_1_2DF98 unk_120;
    f32 unk_128;
    f32 unk_12C;
    f32 unk_130;
};

/* fn_1_2DF98 */
/* Obj3C30: see Obj3C30 */

/* fn_1_2E1B8 */
typedef struct Node_fn_1_2E1B8 {
    u32 unk_0;
    u8 pad_4[0x8];
    s32 count;
    struct Node_fn_1_2E1B8 *children;
    u8 pad_14[0x50 - 0x14];
} Node_fn_1_2E1B8;

/* fn_1_2E1B8 */
typedef struct StcoliNode_fn_1_2E1B8 StcoliNode_fn_1_2E1B8;

/* fn_1_2E1B8 */
struct StcoliNode_fn_1_2E1B8 {
    u32 flags;
    u8 pad[8];
    s32 count;
    StcoliNode_fn_1_2E1B8 *items;
    u8 rest[0x3c];
};

/* fn_1_2E1B8 */
typedef struct StcoliVec_fn_1_2E1B8 {
    u32 x;
    u32 y;
    u32 z;
} StcoliVec_fn_1_2E1B8;

/* fn_1_2E1B8 */
typedef struct {
    unsigned char pad0[0x0c];
    int count;
    void *entries;
} Fn118F28Object_fn_1_2E1B8;

/* fn_1_2E1B8 */
typedef struct Fn_1_20258Constants_fn_1_2E1B8 {
    unsigned char pad08[8];
    f32 value08;
    f32 value0c;
    unsigned char pad10[0xb0];
    f64 valuec0;
    f32 valuec8;
    unsigned char padcc[4];
    f64 valued0;
} Fn_1_20258Constants_fn_1_2E1B8;

/* fn_1_2E1B8 */
typedef struct {
    u32 f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24;
    u32 f28, f2c, f30, f34, f38, f3c, f40, f44;
} Cfg_fn_1_2E1B8;

/* fn_1_2E1B8 */
typedef struct {
    u8 pad_0[0x4];
    Cfg_fn_1_2E1B8 *cfg;
    u8 pad_8[0xc];
    f32 fx;
    f32 fy;
    f32 fz;
    f32 rxv;
    f32 ryv;
    f32 rzv;
    f32 sxv;
    f32 syv;
    f32 szv;
} Entity_fn_1_2E1B8;

/* fn_1_2E1B8 */
typedef struct {
    u32 count;
    u32 entries[1];
} Stack_fn_1_2E1B8;

/* fn_1_2E1B8 */
struct fn_1_2B478_lbl_801A6D00_fn_1_2E1B8 {
    u32 unk_0;
};

/* fn_1_2E1B8 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3_fn_1_2E1B8;

/* fn_1_2E1B8 */
typedef struct {
    f32 m[10];
    f64 d;
} Mtx_fn_1_2E1B8;

/* fn_1_2E1B8 */
struct Pool_fn_1_2E1B8 {
    u8 pad_0[0xc];
    f32 one;
    u8 pad_10[0xc];
    f32 two;
    u8 pad_20[0x14];
    f32 half;
};

/* fn_1_2E1B8 */
struct fn_1_207DC_pool_fn_1_2E1B8 {
    u8 pad_0[8];
    f32 zero;
    f32 one;
    u8 pad_10[0xB0];
    f64 eps;
    f32 pi;
    u8 pad_CC[4];
    f64 two;
};

/* fn_1_2E1B8 */
struct fn_1_21950_lbl_1_rodata_6C8_fn_1_2E1B8 {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
    f32 unk_20;
    u8 pad_24[0x10];
    f32 unk_34;
};

/* fn_1_2E1B8 */
typedef struct {
    u8 pad_0[0x30];
    Vec3_fn_1_2E1B8 pos;
    f32 ax;
    f32 ay;
    Vec3_fn_1_2E1B8 v0;
    Vec3_fn_1_2E1B8 e;
    Vec3_fn_1_2E1B8 m;
    f32 d0;
    f32 d1;
    Vec3_fn_1_2E1B8 o;
    u32 f7c;
    u8 pad_80[0x7c];
    u32 fffc;
} Rec_fn_1_2E1B8;

/* fn_1_2E1B8 */
typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
} fn_1_18784_Cfg_fn_1_2E1B8;

/* fn_1_2E1B8 */
typedef struct {
    u32 f00;
    fn_1_18784_Cfg_fn_1_2E1B8 *cfg;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    f32 f18;
} Src_fn_1_2E1B8;

/* fn_1_2E1B8 */
typedef struct {
    u32 f00;
    fn_1_18784_Cfg_fn_1_2E1B8 *cfg;
    u32 f08;
    s32 f0c;
    Src_fn_1_2E1B8 *f10;
    u32 f14;
    f32 f18;
    f32 f1c;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
} Motion_fn_1_2E1B8;

/* fn_1_2E1B8 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_21CFC_Vec_fn_1_2E1B8;

/* fn_1_2E1B8 */
struct fn_1_2D524_Copy200_fn_1_2E1B8 { char *a[10][5]; };

/* fn_1_2E1B8 */
struct fn_1_2D524_Copy8_fn_1_2E1B8 { char *a[2]; };

/* fn_1_2E1B8 */
struct fn_1_2D524_lbl_1_rodata_BD8_fn_1_2E1B8 {
    u8 pad_0[0x24];
    f32 unk_24;
    u8 pad_28[0x30];
    struct fn_1_2D524_Copy200_fn_1_2E1B8 unk_58;
    struct fn_1_2D524_Copy8_fn_1_2E1B8 unk_120;
    f32 unk_128;
    f32 unk_12C;
    f32 unk_130;
};

/* fn_1_2E1B8 */
struct CallbackObject {
    u8 pad_0[0xC0];
    u32 (*unk_C0)(void *);
};

/* fn_1_2E1B8 */
struct CallbackState {
    u8 pad_0[0xC];
    s32 unk_C;
    u8 pad_10[0x20];
    struct CallbackObject unk_30;
    u8 pad_F4[0x13F4];
    u16 unk_14E8;
};

/* fn_1_2E3B4 */
typedef struct {
    u8 pad_0[0xE];
    u8 unk_E[1];
    u8 pad_F[4];
    u8 unk_13[1];
    u8 pad_14[0x10];
    u32 unk_24[1];
    u8 pad_28[0x5C];
    u16 unk_84;
    s16 unk_86;
    u16 unk_88;
    u16 unk_8A;
    s16 unk_8C;
    s16 unk_8E;
    u32 unk_90;
    u32 unk_94;
    s16 unk_98;
    u16 unk_9A;
    s16 unk_9C;
} Arg0;

/* fn_1_2E3B4 */
/* Racer: see Racer */

/* fn_1_2E928 */
typedef struct {
    u8 pad_0[0x4];
    u16 unk_4;
    u8 pad_6[0x3];
    u8 unk_9[5];
    u8 unk_E[5];
    u8 unk_13[5];
    s16 unk_18[6];
    u32 unk_24[5];
    u32 unk_38[5];
    u16 unk_4C[22];
    u32 unk_78;
    u8 pad_7C[0x24];
} StEntry;

/* fn_1_2E928 */
typedef struct {
    u8 pad_0[0x5];
    u8 unk_5;
    u8 pad_6[0x3];
    u8 unk_9;
    u8 pad_A[0x4];
    u8 unk_E[0x99];
    u8 unk_A7;
    u8 pad_A8[0x2C];
    StEntry entries[1];
} StState;

/* fn_1_2E928 */
/* GameRaceRecord: see GameRaceRecord */

/* fn_1_2E928 */
/* Racer: see Racer */

/* fn_1_2F294 */
typedef struct {
    u8 pad_0[3];
    u8 unk_3;
    u8 pad_4[4];
    f32 unk_8;
} fn_1_2F294_Widget;

/* fn_1_2FAA0 */
typedef struct Sig_ADXT_Pause_SJCK_np_fn_1_2FAA0 {
    unsigned char *data;
    int len;
} Sig_ADXT_Pause_SJCK_np_fn_1_2FAA0;

/* fn_1_2FAA0 */
typedef struct Sig_ADXT_Pause_SJInterface_np_fn_1_2FAA0 Sig_ADXT_Pause_SJInterface_np_fn_1_2FAA0;

/* fn_1_2FAA0 */
typedef struct Sig_ADXT_Pause_SJ_np_fn_1_2FAA0 Sig_ADXT_Pause_SJ_np_fn_1_2FAA0;

/* fn_1_2FAA0 */
struct Sig_ADXT_Pause_SJ_np_fn_1_2FAA0 {
    const Sig_ADXT_Pause_SJInterface_np_fn_1_2FAA0 *interface;
};

/* fn_1_2FAA0 */
struct Sig_ADXT_Pause_SJInterface_np_fn_1_2FAA0 {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Pause_SJ_np_fn_1_2FAA0 *sj);
    const void *(*get_uuid)(Sig_ADXT_Pause_SJ_np_fn_1_2FAA0 *sj);
    void (*reset)(Sig_ADXT_Pause_SJ_np_fn_1_2FAA0 *sj);
    void (*get_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_2FAA0 *sj, int channel, int max_size, Sig_ADXT_Pause_SJCK_np_fn_1_2FAA0 *chunk);
    void (*unget_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_2FAA0 *sj, int channel, Sig_ADXT_Pause_SJCK_np_fn_1_2FAA0 *chunk);
    void (*put_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_2FAA0 *sj, int channel, Sig_ADXT_Pause_SJCK_np_fn_1_2FAA0 *chunk);
    int (*get_num_data)(Sig_ADXT_Pause_SJ_np_fn_1_2FAA0 *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_2FAA0 *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Pause_SJ_np_fn_1_2FAA0 *sj, Sig_ADXT_Pause_SJErrorCallback callback, void *object);
};

/* fn_1_2FAA0 */
typedef struct Sig_ADXT_Pause_ADXTHandle_np_fn_1_2FAA0 {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Pause_AdxSjdHandle *decoder;
    Sig_ADXT_Pause_ADXStream *stream;
    Sig_ADXT_Pause_AXRNAHandle *rna;
    Sig_ADXT_Pause_SJ_np_fn_1_2FAA0 *stream_sj;
    Sig_ADXT_Pause_SJ_np_fn_1_2FAA0 *input_sj;
    Sig_ADXT_Pause_SJ_np_fn_1_2FAA0 *output_sj[2];
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
    Sig_ADXT_Pause_SJ_np_fn_1_2FAA0 *amplifier_input[2];
    Sig_ADXT_Pause_SJ_np_fn_1_2FAA0 *amplifier_output[2];
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
} Sig_ADXT_Pause_ADXTHandle_np_fn_1_2FAA0;

/* fn_1_2FAA0 */
typedef struct Sig_ADXT_Stop_SJCK_np_fn_1_2FAA0 {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK_np_fn_1_2FAA0;

/* fn_1_2FAA0 */
typedef struct Sig_ADXT_Stop_SJInterface_np_fn_1_2FAA0 Sig_ADXT_Stop_SJInterface_np_fn_1_2FAA0;

/* fn_1_2FAA0 */
typedef struct Sig_ADXT_Stop_SJ_np_fn_1_2FAA0 Sig_ADXT_Stop_SJ_np_fn_1_2FAA0;

/* fn_1_2FAA0 */
struct Sig_ADXT_Stop_SJInterface_np_fn_1_2FAA0 {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ_np_fn_1_2FAA0 *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ_np_fn_1_2FAA0 *sj);
    void (*reset)(Sig_ADXT_Stop_SJ_np_fn_1_2FAA0 *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_2FAA0 *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK_np_fn_1_2FAA0 *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_2FAA0 *sj, int channel, Sig_ADXT_Stop_SJCK_np_fn_1_2FAA0 *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_2FAA0 *sj, int channel, Sig_ADXT_Stop_SJCK_np_fn_1_2FAA0 *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ_np_fn_1_2FAA0 *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_2FAA0 *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ_np_fn_1_2FAA0 *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};

/* fn_1_2FAA0 */
struct Sig_ADXT_Stop_SJ_np_fn_1_2FAA0 {
    const Sig_ADXT_Stop_SJInterface_np_fn_1_2FAA0 *interface;
};

/* fn_1_2FAA0 */
typedef struct Sig_ADXT_Stop_ADXTHandle_np_fn_1_2FAA0 {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Stop_AdxSjdHandle *decoder;
    Sig_ADXT_Stop_ADXStream *stream;
    Sig_ADXT_Stop_AXRNAHandle *rna;
    Sig_ADXT_Stop_SJ_np_fn_1_2FAA0 *stream_sj;
    Sig_ADXT_Stop_SJ_np_fn_1_2FAA0 *input_sj;
    Sig_ADXT_Stop_SJ_np_fn_1_2FAA0 *output_sj[2];
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
    Sig_ADXT_Stop_SJ_np_fn_1_2FAA0 *amplifier_input[2];
    Sig_ADXT_Stop_SJ_np_fn_1_2FAA0 *amplifier_output[2];
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
} Sig_ADXT_Stop_ADXTHandle_np_fn_1_2FAA0;

/* fn_1_2FAA0 */
typedef struct {
    u8 unk[0xb];
    u8 value;
} Entry_np_fn_1_2FAA0;

/* fn_1_2FAA0 */
/* GameEntry: see GameEntry */

/* fn_1_2FAA0 */
typedef struct {
    u8 pad[0x2f8];
    GXColor value_2f8;
    GXColor value_2fc;
    u32 value_300;
    u32 value_304;
    u32 value_308;
    u32 value_30c;
    u32 value_310;
    u32 value_314;
    u32 value_318;
    u32 value_31c;
} Fn40710Config_np_fn_1_2FAA0;

/* fn_1_2FDBC */
struct fn_1_2FDBC_sub {
    u8 pad_0[0xB];
    u8 unk_B;
};

/* fn_1_2FDBC */
struct fn_1_2FDBC_flags {
    u32 unk_0;
    u8 unk_4;
    u8 unk_5;
};

/* fn_1_2FDBC */
struct fn_1_2FDBC_lbl_1_bss_3C00 {
    u8 pad_0[0x2A];
    s16 unk_2A;
    u8 pad_2C[0x4];
    u32 unk_30;
    u8 pad_34[0x17C4];
    struct fn_1_2FDBC_sub *unk_17F8;
};

/* fn_1_2FDBC */
struct fn_1_2FDBC_G {
    u8 pad_0[0x8B4];
    u8 unk_8B4;
    u8 unk_8B5;
    u16 unk_8B6;
};

/* fn_1_2FDBC */
struct fn_1_2FDBC_T {
    u8 pad_0[0x1E0];
    u8 unk_1E0;
    u8 unk_1E1;
    u16 unk_1E2;
    u32 unk_1E4;
};

/* fn_1_2FDBC */
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

/* fn_1_2FDBC */
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

/* fn_1_30054 */
typedef struct {
    u32 unk_0;  // 4 loads, 1 stores
    u32 unk_4;  // 4 loads, 1 stores
    u32 unk_8;  // 2 loads, 1 stores
    u32 unk_C;  // 2 loads, 1 stores
    u32 unk_10;  // 2 loads, 1 stores
    u32 unk_14;  // 2 loads, 1 stores
    u32 unk_18;  // 3 loads, 1 stores
    u32 unk_1C;  // 3 loads, 1 stores
    u32 unk_20;  // 3 loads, 1 stores
    u32 unk_24;  // 3 loads, 1 stores
    u32 unk_28;  // 3 loads, 1 stores
    u32 unk_2C;  // 3 loads, 1 stores
    u8 pad_30[0x18];
    u32 unk_48;  // 3 loads, 3 stores
    u32 unk_4C;  // 3 loads, 3 stores
    u32 unk_50;  // 3 loads, 3 stores
    u32 unk_54;  // 3 loads, 3 stores
    u32 unk_58;  // 3 loads, 3 stores
    u32 unk_5C;  // 3 loads, 3 stores
    u8 pad_60[0x4];
    u16 unk_64;  // 2 loads, 2 stores
    u16 unk_66;  // 2 loads, 2 stores
    u16 unk_68;  // 2 loads, 2 stores
    u16 unk_6A;  // 3 loads, 3 stores
    u8 pad_6C[0x8C];
    u32 unk_F8;  // 4 loads, 2 stores
    u32 unk_FC;  // 2 loads, 0 stores
    u32 unk_100;  // 12 loads, 12 stores
    u32 unk_104;  // 5 loads, 2 stores
    u32 unk_108;  // 2 loads, 0 stores
    u32 unk_10C;  // 2 loads, 0 stores
    u32 unk_110;  // 12 loads, 9 stores
    u32 unk_114;  // 6 loads, 3 stores
    u8 pad_118[0x120];
    u32 unk_238;  // 2 loads, 0 stores
    u32 unk_23C;  // 2 loads, 0 stores
    u32 unk_240;  // 2 loads, 0 stores
    u32 unk_244;  // 2 loads, 0 stores
    u32 unk_248;  // 2 loads, 0 stores
    u32 unk_24C;  // 2 loads, 0 stores
    u32 unk_250;  // 2 loads, 0 stores
    u32 unk_254;  // 2 loads, 0 stores
    u16 unk_258;  // 2 loads, 0 stores
    u8 pad_25A[0x5106];
} Obj_1_bss_7F0C0;

/* fn_1_30054 */
typedef struct {
    u8 pad_0[0xA];
    s16 unk_A;  // 1 loads, 0 stores
    u8 pad_C[0x64];
} Obj_1_data_2B0D4;

/* fn_1_30054 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
} BurnerWork;

/* fn_1_30054 */
typedef struct {
    u32 flags;
    u8 pad_4[2];
    u8 id;
    u8 pad_7[0x14B5];
} BurnerSub;

/* fn_1_30054 */
/* BurnerSlot: see BurnerSlot */

/* fn_1_3181C */
/* Racer: see Racer */

/* fn_1_3181C */
/* GameEntrant: see GameEntrant */

/* fn_1_3181C */
typedef struct GameEntry {
    u16 unk_0;
    s16 unk_2;
    u32 unk_4;
    u8 unk_8;
    u8 pad_9[0x3];
    u32 unk_C;
    u8 pad_10[0x10];
} GameEntry;

/* fn_1_31C3C */
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

/* fn_1_31C3C */
struct BurnerSlot {
    Record ranking[10];
    Record bestLap;
    u16 maxSpeed;
    u8 s162;
    u8 unk_163;
    u8 s164;
    u8 s165;
    u8 s166;
    u8 s167;
    u8 s168;
    u8 pad_169[0x17];
};
/* BurnerSlot: see BurnerSlot */

/* fn_1_31C3C */
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

/* fn_1_31C3C */
typedef struct Obj801A66CC {
    u8 pad_0[0x8B4];
    u8 b8B4;
    u8 b8B5;
    u16 h8B6;
} Obj801A66CC;

/* fn_1_31C3C */
typedef struct Obj8B3A0 {
    u8 pad_0[0x90];
    s16 unk_90;
} Obj8B3A0;

/* fn_1_320A4 */
typedef struct {
    u8 pad_0[8];
    u16 unk_8;
    u8 pad_A[0xA];
} GameEntry9F8;

/* fn_1_320A4 */
typedef struct {
    void (*init)(void);
    void (*update)(void);
    void (*exit)(void);
    char *name;
} GameModeEntry;

/* fn_1_32200 */
typedef struct Sig_ADXT_Pause_SJCK_np_fn_1_32200 {
    unsigned char *data;
    int len;
} Sig_ADXT_Pause_SJCK_np_fn_1_32200;

/* fn_1_32200 */
typedef struct Sig_ADXT_Pause_SJInterface_np_fn_1_32200 Sig_ADXT_Pause_SJInterface_np_fn_1_32200;

/* fn_1_32200 */
typedef struct Sig_ADXT_Pause_SJ_np_fn_1_32200 Sig_ADXT_Pause_SJ_np_fn_1_32200;

/* fn_1_32200 */
struct Sig_ADXT_Pause_SJ_np_fn_1_32200 {
    const Sig_ADXT_Pause_SJInterface_np_fn_1_32200 *interface;
};

/* fn_1_32200 */
struct Sig_ADXT_Pause_SJInterface_np_fn_1_32200 {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Pause_SJ_np_fn_1_32200 *sj);
    const void *(*get_uuid)(Sig_ADXT_Pause_SJ_np_fn_1_32200 *sj);
    void (*reset)(Sig_ADXT_Pause_SJ_np_fn_1_32200 *sj);
    void (*get_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_32200 *sj, int channel, int max_size, Sig_ADXT_Pause_SJCK_np_fn_1_32200 *chunk);
    void (*unget_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_32200 *sj, int channel, Sig_ADXT_Pause_SJCK_np_fn_1_32200 *chunk);
    void (*put_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_32200 *sj, int channel, Sig_ADXT_Pause_SJCK_np_fn_1_32200 *chunk);
    int (*get_num_data)(Sig_ADXT_Pause_SJ_np_fn_1_32200 *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_32200 *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Pause_SJ_np_fn_1_32200 *sj, Sig_ADXT_Pause_SJErrorCallback callback, void *object);
};

/* fn_1_32200 */
typedef struct Sig_ADXT_Pause_ADXTHandle_np_fn_1_32200 {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Pause_AdxSjdHandle *decoder;
    Sig_ADXT_Pause_ADXStream *stream;
    Sig_ADXT_Pause_AXRNAHandle *rna;
    Sig_ADXT_Pause_SJ_np_fn_1_32200 *stream_sj;
    Sig_ADXT_Pause_SJ_np_fn_1_32200 *input_sj;
    Sig_ADXT_Pause_SJ_np_fn_1_32200 *output_sj[2];
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
    Sig_ADXT_Pause_SJ_np_fn_1_32200 *amplifier_input[2];
    Sig_ADXT_Pause_SJ_np_fn_1_32200 *amplifier_output[2];
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
} Sig_ADXT_Pause_ADXTHandle_np_fn_1_32200;

/* fn_1_32200 */
typedef struct Sig_ADXT_Stop_SJCK_np_fn_1_32200 {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK_np_fn_1_32200;

/* fn_1_32200 */
typedef struct Sig_ADXT_Stop_SJInterface_np_fn_1_32200 Sig_ADXT_Stop_SJInterface_np_fn_1_32200;

/* fn_1_32200 */
typedef struct Sig_ADXT_Stop_SJ_np_fn_1_32200 Sig_ADXT_Stop_SJ_np_fn_1_32200;

/* fn_1_32200 */
struct Sig_ADXT_Stop_SJInterface_np_fn_1_32200 {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ_np_fn_1_32200 *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ_np_fn_1_32200 *sj);
    void (*reset)(Sig_ADXT_Stop_SJ_np_fn_1_32200 *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_32200 *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK_np_fn_1_32200 *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_32200 *sj, int channel, Sig_ADXT_Stop_SJCK_np_fn_1_32200 *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_32200 *sj, int channel, Sig_ADXT_Stop_SJCK_np_fn_1_32200 *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ_np_fn_1_32200 *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_32200 *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ_np_fn_1_32200 *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};

/* fn_1_32200 */
struct Sig_ADXT_Stop_SJ_np_fn_1_32200 {
    const Sig_ADXT_Stop_SJInterface_np_fn_1_32200 *interface;
};

/* fn_1_32200 */
typedef struct Sig_ADXT_Stop_ADXTHandle_np_fn_1_32200 {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Stop_AdxSjdHandle *decoder;
    Sig_ADXT_Stop_ADXStream *stream;
    Sig_ADXT_Stop_AXRNAHandle *rna;
    Sig_ADXT_Stop_SJ_np_fn_1_32200 *stream_sj;
    Sig_ADXT_Stop_SJ_np_fn_1_32200 *input_sj;
    Sig_ADXT_Stop_SJ_np_fn_1_32200 *output_sj[2];
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
    Sig_ADXT_Stop_SJ_np_fn_1_32200 *amplifier_input[2];
    Sig_ADXT_Stop_SJ_np_fn_1_32200 *amplifier_output[2];
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
} Sig_ADXT_Stop_ADXTHandle_np_fn_1_32200;

/* fn_1_32200 */
typedef struct {
    u8 unk[0xb];
    u8 value;
} Entry_np_fn_1_32200;

/* fn_1_32200 */
/* GameEntry: see GameEntry */

/* fn_1_32200 */
typedef struct {
    u8 pad[0x2f8];
    GXColor value_2f8;
    GXColor value_2fc;
    u32 value_300;
    u32 value_304;
    u32 value_308;
    u32 value_30c;
    u32 value_310;
    u32 value_314;
    u32 value_318;
    u32 value_31c;
} Fn40710Config_np_fn_1_32200;

/* fn_1_32200 */
/* Obj3C30: see Obj3C30 */

/* fn_1_32600 */
/* Racer: see Racer */

/* fn_1_32600 */
/* Obj3C30: see Obj3C30 */

/* fn_1_327F8 */
/* Racer: see Racer */

/* fn_1_327F8 */
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

/* fn_1_327F8 */
struct fn_1_327F8_lbl_1_bss_25B88 {
    u32 unk_0;
};

/* fn_1_32A40 */
/* GameRaceRecord: see GameRaceRecord */

/* fn_1_32A40 */
typedef struct {
    u8 pad_0[0x2A];
    s16 unk_2A;
    u8 pad_2C[0x4];
} GameHead;

/* fn_1_32A40 */
/* GameRaceRecord: see GameRaceRecord */

/* fn_1_32A40 */
typedef struct {
    u8 pad_0[0x4];
    f32 zero;
    u8 pad_8[0x4];
    f32 one;
    u8 pad_10[0x1E4 - 0x10];
    f32 hundred;
} GameRodata;

/* fn_1_32A40 */
typedef struct {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 flags;
    u8 unk_19;
} RacerStatus;

/* fn_1_331EC */
typedef struct Sig_ADXT_Pause_SJCK_np_fn_1_331EC {
    unsigned char *data;
    int len;
} Sig_ADXT_Pause_SJCK_np_fn_1_331EC;

/* fn_1_331EC */
typedef struct Sig_ADXT_Pause_SJInterface_np_fn_1_331EC Sig_ADXT_Pause_SJInterface_np_fn_1_331EC;

/* fn_1_331EC */
typedef struct Sig_ADXT_Pause_SJ_np_fn_1_331EC Sig_ADXT_Pause_SJ_np_fn_1_331EC;

/* fn_1_331EC */
struct Sig_ADXT_Pause_SJ_np_fn_1_331EC {
    const Sig_ADXT_Pause_SJInterface_np_fn_1_331EC *interface;
};

/* fn_1_331EC */
struct Sig_ADXT_Pause_SJInterface_np_fn_1_331EC {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Pause_SJ_np_fn_1_331EC *sj);
    const void *(*get_uuid)(Sig_ADXT_Pause_SJ_np_fn_1_331EC *sj);
    void (*reset)(Sig_ADXT_Pause_SJ_np_fn_1_331EC *sj);
    void (*get_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_331EC *sj, int channel, int max_size, Sig_ADXT_Pause_SJCK_np_fn_1_331EC *chunk);
    void (*unget_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_331EC *sj, int channel, Sig_ADXT_Pause_SJCK_np_fn_1_331EC *chunk);
    void (*put_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_331EC *sj, int channel, Sig_ADXT_Pause_SJCK_np_fn_1_331EC *chunk);
    int (*get_num_data)(Sig_ADXT_Pause_SJ_np_fn_1_331EC *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_331EC *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Pause_SJ_np_fn_1_331EC *sj, Sig_ADXT_Pause_SJErrorCallback callback, void *object);
};

/* fn_1_331EC */
typedef struct Sig_ADXT_Pause_ADXTHandle_np_fn_1_331EC {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Pause_AdxSjdHandle *decoder;
    Sig_ADXT_Pause_ADXStream *stream;
    Sig_ADXT_Pause_AXRNAHandle *rna;
    Sig_ADXT_Pause_SJ_np_fn_1_331EC *stream_sj;
    Sig_ADXT_Pause_SJ_np_fn_1_331EC *input_sj;
    Sig_ADXT_Pause_SJ_np_fn_1_331EC *output_sj[2];
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
    Sig_ADXT_Pause_SJ_np_fn_1_331EC *amplifier_input[2];
    Sig_ADXT_Pause_SJ_np_fn_1_331EC *amplifier_output[2];
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
} Sig_ADXT_Pause_ADXTHandle_np_fn_1_331EC;

/* fn_1_331EC */
typedef struct Sig_ADXT_Stop_SJCK_np_fn_1_331EC {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK_np_fn_1_331EC;

/* fn_1_331EC */
typedef struct Sig_ADXT_Stop_SJInterface_np_fn_1_331EC Sig_ADXT_Stop_SJInterface_np_fn_1_331EC;

/* fn_1_331EC */
typedef struct Sig_ADXT_Stop_SJ_np_fn_1_331EC Sig_ADXT_Stop_SJ_np_fn_1_331EC;

/* fn_1_331EC */
struct Sig_ADXT_Stop_SJInterface_np_fn_1_331EC {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ_np_fn_1_331EC *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ_np_fn_1_331EC *sj);
    void (*reset)(Sig_ADXT_Stop_SJ_np_fn_1_331EC *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_331EC *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK_np_fn_1_331EC *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_331EC *sj, int channel, Sig_ADXT_Stop_SJCK_np_fn_1_331EC *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_331EC *sj, int channel, Sig_ADXT_Stop_SJCK_np_fn_1_331EC *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ_np_fn_1_331EC *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_331EC *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ_np_fn_1_331EC *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};

/* fn_1_331EC */
struct Sig_ADXT_Stop_SJ_np_fn_1_331EC {
    const Sig_ADXT_Stop_SJInterface_np_fn_1_331EC *interface;
};

/* fn_1_331EC */
typedef struct Sig_ADXT_Stop_ADXTHandle_np_fn_1_331EC {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Stop_AdxSjdHandle *decoder;
    Sig_ADXT_Stop_ADXStream *stream;
    Sig_ADXT_Stop_AXRNAHandle *rna;
    Sig_ADXT_Stop_SJ_np_fn_1_331EC *stream_sj;
    Sig_ADXT_Stop_SJ_np_fn_1_331EC *input_sj;
    Sig_ADXT_Stop_SJ_np_fn_1_331EC *output_sj[2];
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
    Sig_ADXT_Stop_SJ_np_fn_1_331EC *amplifier_input[2];
    Sig_ADXT_Stop_SJ_np_fn_1_331EC *amplifier_output[2];
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
} Sig_ADXT_Stop_ADXTHandle_np_fn_1_331EC;

/* fn_1_331EC */
typedef struct {
    u8 unk[0xb];
    u8 value;
} Entry_np_fn_1_331EC;

/* fn_1_331EC */
/* GameEntry: see GameEntry */

/* fn_1_331EC */
typedef struct {
    u8 pad[0x2f8];
    GXColor value_2f8;
    GXColor value_2fc;
    u32 value_300;
    u32 value_304;
    u32 value_308;
    u32 value_30c;
    u32 value_310;
    u32 value_314;
    u32 value_318;
    u32 value_31c;
} Fn40710Config_np_fn_1_331EC;

/* fn_1_331EC */
/* GameRaceRecord: see GameRaceRecord */

/* fn_1_331EC */
typedef struct Config { u32 flags; u8 pad4; u8 mode; u8 pad6[0x26]; GameRaceRecord *track; u8 pad30[0x74]; u16 lock; u8 pada6[0x2a]; void (*callback)(struct Config*,Racer*); } Config;

typedef struct Obj3C30 {
    u32 unk_0;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 unk_7;
    u8 unk_8;
    u8 unk_9;
    u8 unk_A;
    u8 unk_B;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E[30];
    void *unk_2C[30];
    u16 unk_A4;
    u8 unk_A6;
    u8 unk_A7;
    GameStepFn unk_A8;
    GameStepFn unk_AC;
    GameStepFn unk_B0;
    GameStepFn unk_B4;
    GameStepFn unk_B8;
    GameStepFn unk_BC;
    u32 (*unk_C0)();
    s32 (*unk_C4)(void);
    GameStepFn unk_C8;
    GameModeFn unk_CC;
    void (*unk_D0)(struct Obj3C30 *, Racer *);
    GamePlayer unk_D4[30];
    u8 unk_1394[32];
    u32 unk_13B4[8];
    u32 unk_13D4[8];
    u8 unk_13F4;
    u8 unk_13F5;
    u8 unk_13F6;
    u8 pad_13F7[0x1];
    u16 unk_13F8[5];
    u8 unk_1402;
    u8 unk_1403;
    u8 unk_1404;
    u8 unk_1405;
    u8 pad_1406[0x3E];
    Record unk_1444;
    u32 unk_1464;
    u8 unk_1468[4];
    u8 unk_146C;
    u8 unk_146D;
    u16 unk_146E;
    u8 unk_1470;
    u8 unk_1471;
    u8 unk_1472;
    u8 unk_1473;
    u32 unk_1474;
    u16 unk_1478[4];
    u32 unk_1480[4];
    s64 unk_1490;
    s64 unk_1498;
    s64 unk_14A0;
    u32 unk_14A8;
    u8 pad_14AC[0xC];
} Obj3C30;

/* fn_1_331EC */
typedef struct Input { u32 head; f32 f4,f8,fc,f10,f14; u8 pad18[0x1c]; f32 f34; u8 pad38[0xc]; f32 f44; u8 pad48[0x70]; } Input;

/* fn_1_33890 */
typedef struct {
    u8 pad_0[0x5];
    u8 unk_5;
    u8 pad_6[0x4];
    u8 unk_A;
    u8 pad_B[0x1];
    u8 unk_C;
    u8 unk_D;
} Fn33890Arg;

/* fn_1_34924 */
/* Obj3C30: see Obj3C30 */

/* fn_1_34924 */
struct Racer {
    u32 unk_0;
    s16 unk_4;
    s16 unk_6;
    f32 unk_8;
    u8 pad_C[0x30];
    u8 unk_3C[0x68];
    f32 unk_A4;
    u8 pad_A8[0x14];
    f32 unk_BC;
    u8 pad_C0[0x18];
    f32 unk_D8;
    u8 pad_DC[0xA0];
    f32 unk_17C;
    u8 pad_180[0x4];
    f32 unk_184;
    u8 pad_188[0x3];
    u8 unk_18B;
    u8 pad_18C[0x68];
    f32 unk_1F4;
    f32 unk_1F8;
    f32 unk_1FC;
    f32 unk_200;
    f32 unk_204;
    u8 pad_208[0x8];
    u16 unk_210;
    u8 pad_212[0x1];
    u8 unk_213;
    u16 unk_214;
    u8 pad_216[0x1];
    u8 unk_217;
    u32 unk_218;
    u8 pad_21C[0x4];
    f32 unk_220;
    f32 unk_224;
    u8 pad_228[0x4];
    f32 unk_22C;
    u8 pad_230[0x244];
    s8 unk_474;
    s8 unk_475;
    u8 pad_476[0xC];
    u8 unk_482;
    u8 pad_483[0x19];
    GameRaceRecord *unk_49C;
    u8 pad_4A0[0x22];
    u8 unk_4C2;
    u8 pad_4C3[0x19];
    f32 unk_4DC;
    u8 pad_4E0[0x2D];
    u8 unk_50D;
    u8 pad_50E[0x72];
    f32 unk_580;
    u8 pad_584[0x8];
    u32 unk_58C;
    u8 unk_590;
    u8 pad_591[0x48];
    u8 unk_5D9;
    u8 pad_5DA[0x46];
};
/* conflict 0x475: s8 unk_475 (Racer) vs u8 unk_475 (Racer) */
/* conflict 0x49C: GameRaceRecord* unk_49C (Racer) vs void* unk_49C (Racer) */
/* Racer: see Racer */

/* fn_1_34AC0 */
typedef struct Sig_ADXT_Pause_SJCK_np_fn_1_34AC0 {
    unsigned char *data;
    int len;
} Sig_ADXT_Pause_SJCK_np_fn_1_34AC0;

/* fn_1_34AC0 */
typedef struct Sig_ADXT_Pause_SJInterface_np_fn_1_34AC0 Sig_ADXT_Pause_SJInterface_np_fn_1_34AC0;

/* fn_1_34AC0 */
typedef struct Sig_ADXT_Pause_SJ_np_fn_1_34AC0 Sig_ADXT_Pause_SJ_np_fn_1_34AC0;

/* fn_1_34AC0 */
struct Sig_ADXT_Pause_SJ_np_fn_1_34AC0 {
    const Sig_ADXT_Pause_SJInterface_np_fn_1_34AC0 *interface;
};

/* fn_1_34AC0 */
struct Sig_ADXT_Pause_SJInterface_np_fn_1_34AC0 {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Pause_SJ_np_fn_1_34AC0 *sj);
    const void *(*get_uuid)(Sig_ADXT_Pause_SJ_np_fn_1_34AC0 *sj);
    void (*reset)(Sig_ADXT_Pause_SJ_np_fn_1_34AC0 *sj);
    void (*get_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_34AC0 *sj, int channel, int max_size, Sig_ADXT_Pause_SJCK_np_fn_1_34AC0 *chunk);
    void (*unget_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_34AC0 *sj, int channel, Sig_ADXT_Pause_SJCK_np_fn_1_34AC0 *chunk);
    void (*put_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_34AC0 *sj, int channel, Sig_ADXT_Pause_SJCK_np_fn_1_34AC0 *chunk);
    int (*get_num_data)(Sig_ADXT_Pause_SJ_np_fn_1_34AC0 *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_34AC0 *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Pause_SJ_np_fn_1_34AC0 *sj, Sig_ADXT_Pause_SJErrorCallback callback, void *object);
};

/* fn_1_34AC0 */
typedef struct Sig_ADXT_Pause_ADXTHandle_np_fn_1_34AC0 {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Pause_AdxSjdHandle *decoder;
    Sig_ADXT_Pause_ADXStream *stream;
    Sig_ADXT_Pause_AXRNAHandle *rna;
    Sig_ADXT_Pause_SJ_np_fn_1_34AC0 *stream_sj;
    Sig_ADXT_Pause_SJ_np_fn_1_34AC0 *input_sj;
    Sig_ADXT_Pause_SJ_np_fn_1_34AC0 *output_sj[2];
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
    Sig_ADXT_Pause_SJ_np_fn_1_34AC0 *amplifier_input[2];
    Sig_ADXT_Pause_SJ_np_fn_1_34AC0 *amplifier_output[2];
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
} Sig_ADXT_Pause_ADXTHandle_np_fn_1_34AC0;

/* fn_1_34AC0 */
typedef struct Sig_ADXT_Stop_SJCK_np_fn_1_34AC0 {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK_np_fn_1_34AC0;

/* fn_1_34AC0 */
typedef struct Sig_ADXT_Stop_SJInterface_np_fn_1_34AC0 Sig_ADXT_Stop_SJInterface_np_fn_1_34AC0;

/* fn_1_34AC0 */
typedef struct Sig_ADXT_Stop_SJ_np_fn_1_34AC0 Sig_ADXT_Stop_SJ_np_fn_1_34AC0;

/* fn_1_34AC0 */
struct Sig_ADXT_Stop_SJInterface_np_fn_1_34AC0 {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ_np_fn_1_34AC0 *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ_np_fn_1_34AC0 *sj);
    void (*reset)(Sig_ADXT_Stop_SJ_np_fn_1_34AC0 *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_34AC0 *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK_np_fn_1_34AC0 *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_34AC0 *sj, int channel, Sig_ADXT_Stop_SJCK_np_fn_1_34AC0 *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_34AC0 *sj, int channel, Sig_ADXT_Stop_SJCK_np_fn_1_34AC0 *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ_np_fn_1_34AC0 *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_34AC0 *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ_np_fn_1_34AC0 *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};

/* fn_1_34AC0 */
struct Sig_ADXT_Stop_SJ_np_fn_1_34AC0 {
    const Sig_ADXT_Stop_SJInterface_np_fn_1_34AC0 *interface;
};

/* fn_1_34AC0 */
typedef struct Sig_ADXT_Stop_ADXTHandle_np_fn_1_34AC0 {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Stop_AdxSjdHandle *decoder;
    Sig_ADXT_Stop_ADXStream *stream;
    Sig_ADXT_Stop_AXRNAHandle *rna;
    Sig_ADXT_Stop_SJ_np_fn_1_34AC0 *stream_sj;
    Sig_ADXT_Stop_SJ_np_fn_1_34AC0 *input_sj;
    Sig_ADXT_Stop_SJ_np_fn_1_34AC0 *output_sj[2];
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
    Sig_ADXT_Stop_SJ_np_fn_1_34AC0 *amplifier_input[2];
    Sig_ADXT_Stop_SJ_np_fn_1_34AC0 *amplifier_output[2];
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
} Sig_ADXT_Stop_ADXTHandle_np_fn_1_34AC0;

/* fn_1_34AC0 */
typedef struct {
    u8 unk[0xb];
    u8 value;
} Entry_np_fn_1_34AC0;

/* fn_1_34AC0 */
/* GameEntry: see GameEntry */

/* fn_1_34AC0 */
typedef struct {
    u8 pad[0x2f8];
    GXColor value_2f8;
    GXColor value_2fc;
    u32 value_300;
    u32 value_304;
    u32 value_308;
    u32 value_30c;
    u32 value_310;
    u32 value_314;
    u32 value_318;
    u32 value_31c;
} Fn40710Config_np_fn_1_34AC0;

/* fn_1_34E08 */
struct fn_1_34E08_lbl_1_bss_8B3A0 {
    u8 pad_0[0xE];
    s16 unk_E;
};

/* fn_1_34F38 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[8];
    u8 unk_10[0x4A248];
    u8 unk_4A258[0x4A248];
} InitObj;

/* fn_1_34F38 */
typedef struct {
    u8 pad_0[8];
    f32 unk_8;
} Obj_1_86254;

/* fn_1_3522C */
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

/* fn_1_3522C */
typedef struct {
    u8 pad_0[3];
    u8 flags;
    u8 pad_4[0x30 - 4];
} GameObj1508;

/* fn_1_3522C */
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

/* fn_1_3522C */
typedef struct {
    u8 b[5];
} GameEntry5;

/* fn_1_359B8 */
typedef struct GameEntrant {
    u8 unk_0;
    u8 name;
    u8 letter;
    u8 pad_3[0x8];
    u8 unk_B;
} GameEntrant;

/* fn_1_36330 */
typedef s32 (*RaceRuleFn)(void);

/* fn_1_36330 */
typedef struct {
    u8 pad_0[0x8B4];
    u8 unk_8B4;
    u8 unk_8B5;
    u16 unk_8B6;
} Obj_801A66CC;

/* fn_1_37E98 */
typedef u32 (*fn_1_37E98_Fn0)(void);

/* fn_1_37E98 */
typedef u32 (*fn_1_37E98_Fn1)(u32);

/* fn_1_37E98 */
typedef u32 (*fn_1_37E98_Fn2)(void);

/* fn_1_37E98 */
struct GameModeEntry {
    u32 setup;
    u32 update;
    u32 cleanup;
    u32 other;
};

/* fn_1_37E98 */
struct fn_1_37E98_lbl_1_data_5730 {
    u8 pad_0[0x38C];
    struct GameModeEntry modes[12];
    u8 pad_44C[12];
    u32 unk_458;
    u32 unk_45C;
    u8 pad_460[0x75C];
    char filename[8];
};

/* fn_1_37E98 */
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

/* fn_1_384E8 */
typedef struct {
    u8 pad[6];
    u8 unk_06;
    u8 rest[0x14B1];
} Sub30;

/* fn_1_385A4 */
typedef struct Sig_ADXT_Pause_SJCK_np_fn_1_385A4 {
    unsigned char *data;
    int len;
} Sig_ADXT_Pause_SJCK_np_fn_1_385A4;

/* fn_1_385A4 */
typedef struct Sig_ADXT_Pause_SJInterface_np_fn_1_385A4 Sig_ADXT_Pause_SJInterface_np_fn_1_385A4;

/* fn_1_385A4 */
typedef struct Sig_ADXT_Pause_SJ_np_fn_1_385A4 Sig_ADXT_Pause_SJ_np_fn_1_385A4;

/* fn_1_385A4 */
struct Sig_ADXT_Pause_SJ_np_fn_1_385A4 {
    const Sig_ADXT_Pause_SJInterface_np_fn_1_385A4 *interface;
};

/* fn_1_385A4 */
struct Sig_ADXT_Pause_SJInterface_np_fn_1_385A4 {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Pause_SJ_np_fn_1_385A4 *sj);
    const void *(*get_uuid)(Sig_ADXT_Pause_SJ_np_fn_1_385A4 *sj);
    void (*reset)(Sig_ADXT_Pause_SJ_np_fn_1_385A4 *sj);
    void (*get_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_385A4 *sj, int channel, int max_size, Sig_ADXT_Pause_SJCK_np_fn_1_385A4 *chunk);
    void (*unget_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_385A4 *sj, int channel, Sig_ADXT_Pause_SJCK_np_fn_1_385A4 *chunk);
    void (*put_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_385A4 *sj, int channel, Sig_ADXT_Pause_SJCK_np_fn_1_385A4 *chunk);
    int (*get_num_data)(Sig_ADXT_Pause_SJ_np_fn_1_385A4 *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_385A4 *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Pause_SJ_np_fn_1_385A4 *sj, Sig_ADXT_Pause_SJErrorCallback callback, void *object);
};

/* fn_1_385A4 */
typedef struct Sig_ADXT_Pause_ADXTHandle_np_fn_1_385A4 {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Pause_AdxSjdHandle *decoder;
    Sig_ADXT_Pause_ADXStream *stream;
    Sig_ADXT_Pause_AXRNAHandle *rna;
    Sig_ADXT_Pause_SJ_np_fn_1_385A4 *stream_sj;
    Sig_ADXT_Pause_SJ_np_fn_1_385A4 *input_sj;
    Sig_ADXT_Pause_SJ_np_fn_1_385A4 *output_sj[2];
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
    Sig_ADXT_Pause_SJ_np_fn_1_385A4 *amplifier_input[2];
    Sig_ADXT_Pause_SJ_np_fn_1_385A4 *amplifier_output[2];
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
} Sig_ADXT_Pause_ADXTHandle_np_fn_1_385A4;

/* fn_1_385A4 */
typedef struct Sig_ADXT_Stop_SJCK_np_fn_1_385A4 {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK_np_fn_1_385A4;

/* fn_1_385A4 */
typedef struct Sig_ADXT_Stop_SJInterface_np_fn_1_385A4 Sig_ADXT_Stop_SJInterface_np_fn_1_385A4;

/* fn_1_385A4 */
typedef struct Sig_ADXT_Stop_SJ_np_fn_1_385A4 Sig_ADXT_Stop_SJ_np_fn_1_385A4;

/* fn_1_385A4 */
struct Sig_ADXT_Stop_SJInterface_np_fn_1_385A4 {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ_np_fn_1_385A4 *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ_np_fn_1_385A4 *sj);
    void (*reset)(Sig_ADXT_Stop_SJ_np_fn_1_385A4 *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_385A4 *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK_np_fn_1_385A4 *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_385A4 *sj, int channel, Sig_ADXT_Stop_SJCK_np_fn_1_385A4 *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_385A4 *sj, int channel, Sig_ADXT_Stop_SJCK_np_fn_1_385A4 *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ_np_fn_1_385A4 *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_385A4 *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ_np_fn_1_385A4 *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};

/* fn_1_385A4 */
struct Sig_ADXT_Stop_SJ_np_fn_1_385A4 {
    const Sig_ADXT_Stop_SJInterface_np_fn_1_385A4 *interface;
};

/* fn_1_385A4 */
typedef struct Sig_ADXT_Stop_ADXTHandle_np_fn_1_385A4 {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Stop_AdxSjdHandle *decoder;
    Sig_ADXT_Stop_ADXStream *stream;
    Sig_ADXT_Stop_AXRNAHandle *rna;
    Sig_ADXT_Stop_SJ_np_fn_1_385A4 *stream_sj;
    Sig_ADXT_Stop_SJ_np_fn_1_385A4 *input_sj;
    Sig_ADXT_Stop_SJ_np_fn_1_385A4 *output_sj[2];
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
    Sig_ADXT_Stop_SJ_np_fn_1_385A4 *amplifier_input[2];
    Sig_ADXT_Stop_SJ_np_fn_1_385A4 *amplifier_output[2];
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
} Sig_ADXT_Stop_ADXTHandle_np_fn_1_385A4;

/* fn_1_385A4 */
typedef struct {
    u8 unk[0xb];
    u8 value;
} Entry_np_fn_1_385A4;

/* fn_1_385A4 */
/* GameEntry: see GameEntry */

/* fn_1_385A4 */
typedef struct {
    u8 pad[0x2f8];
    GXColor value_2f8;
    GXColor value_2fc;
    u32 value_300;
    u32 value_304;
    u32 value_308;
    u32 value_30c;
    u32 value_310;
    u32 value_314;
    u32 value_318;
    u32 value_31c;
} Fn40710Config_np_fn_1_385A4;

/* fn_1_385A4 */
typedef struct Sig_fn_1_12F30C_Fn1_12F30CState {
    s32 value;
} Sig_fn_1_12F30C_Fn1_12F30CState;

/* fn_1_385A4 */
struct fn_1_385A4_sub {
    u8 pad_6[6];
    u8 unk_6;
    u8 pad_7[1];
    u8 unk_8;
};

/* fn_1_3867C */
typedef struct GameLinkSlot {
    u8 data[0x1C];
} GameLinkSlot;

/* fn_1_3867C */
typedef struct GameCarData {
    u8 data[0xA20];
} GameCarData;

/* fn_1_3867C */
typedef struct GameLink {
    u32 unk_0;
    u8 *unk_4;
    u8 *unk_8;
    GameCar *unk_C;
    GameCarData *unk_10;
    s16 unk_14;
    s16 unk_16;
    u32 unk_18;
    GameLinkSlot *unk_1C;
    u8 *unk_20;
    u8 *unk_24;
    s32 unk_28;
    s32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u8 pad_38[0x28];
    u32 unk_60;
    u8 pad_64[0x4];
} GameLink;

/* fn_1_3867C */
typedef struct GameRecord {
    u8 pad_0[0x2];
    s16 unk_2;
    u8 pad_4[0x4];
    u8 unk_8;
    u8 pad_9[0x17];
} GameRecord;

/* fn_1_3867C */
typedef struct {
    u32 unk_0;
    u32 unk_4;
} Obj_1_bss_8B5F4;

/* fn_1_3867C */
typedef enum { GAME_SHIFT_SINGLE = 0, GAME_SHIFT_MULTI = 4 } GameShift;

/* fn_1_38BBC */
typedef struct {
    u32 unk_0;
    u8 pad_4[0xE];
} Obj_1_bss_6EAB4;

/* fn_1_38CF4 */
typedef struct {
    u8 pad_0[0x8];
    void *obj;
} fn_1_38CF4_Part;

/* fn_1_38CF4 */
/* GameCar: see GameCar */

/* fn_1_38CF4 */
typedef struct {
    u8 pad_0[0x3B8];
    s16 unk_3B8;
    u8 pad_3BA[0x440 - 0x3BA];
} fn_1_38CF4_Slot;

/* fn_1_3908C */
struct fn_1_3908C_lbl_1_bss_25B88 {
    u32 unk_0;
};

/* fn_1_3908C */
struct fn_1_3908C_lbl_1_bss_25CA4 {
    u32 unk_0;
};

/* fn_1_3908C */
struct fn_1_3908C_lbl_1_bss_3C30 {
    u8 pad_0[0x5];
    u8 unk_5;
    u8 unk_6;
    u8 pad_7[0x146D];
    u32 unk_1474;
};

/* fn_1_3908C */
struct fn_1_3908C_lbl_1_bss_6EAD0 {
    u32 unk_0;
};

/* fn_1_3908C */
struct fn_1_3908C_lbl_1_bss_381F5 {
    u8 unk_0;
};

/* fn_1_391F0 */
struct Sig_fn_8004BD5C_fn_8004BD5C_Arg0 { u8 pad_0[0x71]; s8 unk_71; };

/* fn_1_391F0 */
struct fn_1_391F0_st30 { u8 pad_0[5]; u8 unk_5; u8 unk_6; };

/* fn_1_391F0 */
typedef struct GameElem9F8 { u8 pad_0[8]; u16 unk_8; u8 pad_A[0xA]; } GameElem9F8;

/* fn_1_39420 */
typedef struct Sig_ADXT_Pause_SJCK_np_fn_1_39420 {
    unsigned char *data;
    int len;
} Sig_ADXT_Pause_SJCK_np_fn_1_39420;

/* fn_1_39420 */
typedef struct Sig_ADXT_Pause_SJInterface_np_fn_1_39420 Sig_ADXT_Pause_SJInterface_np_fn_1_39420;

/* fn_1_39420 */
typedef struct Sig_ADXT_Pause_SJ_np_fn_1_39420 Sig_ADXT_Pause_SJ_np_fn_1_39420;

/* fn_1_39420 */
struct Sig_ADXT_Pause_SJ_np_fn_1_39420 {
    const Sig_ADXT_Pause_SJInterface_np_fn_1_39420 *interface;
};

/* fn_1_39420 */
struct Sig_ADXT_Pause_SJInterface_np_fn_1_39420 {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Pause_SJ_np_fn_1_39420 *sj);
    const void *(*get_uuid)(Sig_ADXT_Pause_SJ_np_fn_1_39420 *sj);
    void (*reset)(Sig_ADXT_Pause_SJ_np_fn_1_39420 *sj);
    void (*get_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_39420 *sj, int channel, int max_size, Sig_ADXT_Pause_SJCK_np_fn_1_39420 *chunk);
    void (*unget_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_39420 *sj, int channel, Sig_ADXT_Pause_SJCK_np_fn_1_39420 *chunk);
    void (*put_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_39420 *sj, int channel, Sig_ADXT_Pause_SJCK_np_fn_1_39420 *chunk);
    int (*get_num_data)(Sig_ADXT_Pause_SJ_np_fn_1_39420 *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_39420 *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Pause_SJ_np_fn_1_39420 *sj, Sig_ADXT_Pause_SJErrorCallback callback, void *object);
};

/* fn_1_39420 */
typedef struct Sig_ADXT_Pause_ADXTHandle_np_fn_1_39420 {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Pause_AdxSjdHandle *decoder;
    Sig_ADXT_Pause_ADXStream *stream;
    Sig_ADXT_Pause_AXRNAHandle *rna;
    Sig_ADXT_Pause_SJ_np_fn_1_39420 *stream_sj;
    Sig_ADXT_Pause_SJ_np_fn_1_39420 *input_sj;
    Sig_ADXT_Pause_SJ_np_fn_1_39420 *output_sj[2];
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
    Sig_ADXT_Pause_SJ_np_fn_1_39420 *amplifier_input[2];
    Sig_ADXT_Pause_SJ_np_fn_1_39420 *amplifier_output[2];
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
} Sig_ADXT_Pause_ADXTHandle_np_fn_1_39420;

/* fn_1_39420 */
typedef struct Sig_ADXT_Stop_SJCK_np_fn_1_39420 {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK_np_fn_1_39420;

/* fn_1_39420 */
typedef struct Sig_ADXT_Stop_SJInterface_np_fn_1_39420 Sig_ADXT_Stop_SJInterface_np_fn_1_39420;

/* fn_1_39420 */
typedef struct Sig_ADXT_Stop_SJ_np_fn_1_39420 Sig_ADXT_Stop_SJ_np_fn_1_39420;

/* fn_1_39420 */
struct Sig_ADXT_Stop_SJInterface_np_fn_1_39420 {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ_np_fn_1_39420 *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ_np_fn_1_39420 *sj);
    void (*reset)(Sig_ADXT_Stop_SJ_np_fn_1_39420 *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_39420 *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK_np_fn_1_39420 *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_39420 *sj, int channel, Sig_ADXT_Stop_SJCK_np_fn_1_39420 *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_39420 *sj, int channel, Sig_ADXT_Stop_SJCK_np_fn_1_39420 *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ_np_fn_1_39420 *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_39420 *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ_np_fn_1_39420 *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};

/* fn_1_39420 */
struct Sig_ADXT_Stop_SJ_np_fn_1_39420 {
    const Sig_ADXT_Stop_SJInterface_np_fn_1_39420 *interface;
};

/* fn_1_39420 */
typedef struct Sig_ADXT_Stop_ADXTHandle_np_fn_1_39420 {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Stop_AdxSjdHandle *decoder;
    Sig_ADXT_Stop_ADXStream *stream;
    Sig_ADXT_Stop_AXRNAHandle *rna;
    Sig_ADXT_Stop_SJ_np_fn_1_39420 *stream_sj;
    Sig_ADXT_Stop_SJ_np_fn_1_39420 *input_sj;
    Sig_ADXT_Stop_SJ_np_fn_1_39420 *output_sj[2];
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
    Sig_ADXT_Stop_SJ_np_fn_1_39420 *amplifier_input[2];
    Sig_ADXT_Stop_SJ_np_fn_1_39420 *amplifier_output[2];
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
} Sig_ADXT_Stop_ADXTHandle_np_fn_1_39420;

/* fn_1_39420 */
typedef struct {
    u8 unk[0xb];
    u8 value;
} Entry_np_fn_1_39420;

/* fn_1_39420 */
/* GameEntry: see GameEntry */

/* fn_1_39420 */
typedef struct {
    u8 pad[0x2f8];
    GXColor value_2f8;
    GXColor value_2fc;
    u32 value_300;
    u32 value_304;
    u32 value_308;
    u32 value_30c;
    u32 value_310;
    u32 value_314;
    u32 value_318;
    u32 value_31c;
} Fn40710Config_np_fn_1_39420;

/* fn_1_39420 */
typedef struct {
    u8 pad_0[5];
    u8 unk_5;
    u8 pad_1[3];
    u8 unk_9;
} St_30;

/* fn_1_3A044 */
typedef struct GameEntryC {
    u8 data[0xA0];
} GameEntryC;

/* fn_1_3A044 */
/* Obj3C30: see Obj3C30 */

/* fn_1_3AEC4 */
typedef struct Sig_ADXT_Pause_SJCK_np_fn_1_3AEC4 {
    unsigned char *data;
    int len;
} Sig_ADXT_Pause_SJCK_np_fn_1_3AEC4;

/* fn_1_3AEC4 */
typedef struct Sig_ADXT_Pause_SJInterface_np_fn_1_3AEC4 Sig_ADXT_Pause_SJInterface_np_fn_1_3AEC4;

/* fn_1_3AEC4 */
typedef struct Sig_ADXT_Pause_SJ_np_fn_1_3AEC4 Sig_ADXT_Pause_SJ_np_fn_1_3AEC4;

/* fn_1_3AEC4 */
struct Sig_ADXT_Pause_SJ_np_fn_1_3AEC4 {
    const Sig_ADXT_Pause_SJInterface_np_fn_1_3AEC4 *interface;
};

/* fn_1_3AEC4 */
struct Sig_ADXT_Pause_SJInterface_np_fn_1_3AEC4 {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Pause_SJ_np_fn_1_3AEC4 *sj);
    const void *(*get_uuid)(Sig_ADXT_Pause_SJ_np_fn_1_3AEC4 *sj);
    void (*reset)(Sig_ADXT_Pause_SJ_np_fn_1_3AEC4 *sj);
    void (*get_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_3AEC4 *sj, int channel, int max_size, Sig_ADXT_Pause_SJCK_np_fn_1_3AEC4 *chunk);
    void (*unget_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_3AEC4 *sj, int channel, Sig_ADXT_Pause_SJCK_np_fn_1_3AEC4 *chunk);
    void (*put_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_3AEC4 *sj, int channel, Sig_ADXT_Pause_SJCK_np_fn_1_3AEC4 *chunk);
    int (*get_num_data)(Sig_ADXT_Pause_SJ_np_fn_1_3AEC4 *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_3AEC4 *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Pause_SJ_np_fn_1_3AEC4 *sj, Sig_ADXT_Pause_SJErrorCallback callback, void *object);
};

/* fn_1_3AEC4 */
typedef struct Sig_ADXT_Pause_ADXTHandle_np_fn_1_3AEC4 {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Pause_AdxSjdHandle *decoder;
    Sig_ADXT_Pause_ADXStream *stream;
    Sig_ADXT_Pause_AXRNAHandle *rna;
    Sig_ADXT_Pause_SJ_np_fn_1_3AEC4 *stream_sj;
    Sig_ADXT_Pause_SJ_np_fn_1_3AEC4 *input_sj;
    Sig_ADXT_Pause_SJ_np_fn_1_3AEC4 *output_sj[2];
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
    Sig_ADXT_Pause_SJ_np_fn_1_3AEC4 *amplifier_input[2];
    Sig_ADXT_Pause_SJ_np_fn_1_3AEC4 *amplifier_output[2];
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
} Sig_ADXT_Pause_ADXTHandle_np_fn_1_3AEC4;

/* fn_1_3AEC4 */
typedef struct Sig_ADXT_Stop_SJCK_np_fn_1_3AEC4 {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK_np_fn_1_3AEC4;

/* fn_1_3AEC4 */
typedef struct Sig_ADXT_Stop_SJInterface_np_fn_1_3AEC4 Sig_ADXT_Stop_SJInterface_np_fn_1_3AEC4;

/* fn_1_3AEC4 */
typedef struct Sig_ADXT_Stop_SJ_np_fn_1_3AEC4 Sig_ADXT_Stop_SJ_np_fn_1_3AEC4;

/* fn_1_3AEC4 */
struct Sig_ADXT_Stop_SJInterface_np_fn_1_3AEC4 {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ_np_fn_1_3AEC4 *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ_np_fn_1_3AEC4 *sj);
    void (*reset)(Sig_ADXT_Stop_SJ_np_fn_1_3AEC4 *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_3AEC4 *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK_np_fn_1_3AEC4 *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_3AEC4 *sj, int channel, Sig_ADXT_Stop_SJCK_np_fn_1_3AEC4 *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_3AEC4 *sj, int channel, Sig_ADXT_Stop_SJCK_np_fn_1_3AEC4 *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ_np_fn_1_3AEC4 *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_3AEC4 *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ_np_fn_1_3AEC4 *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};

/* fn_1_3AEC4 */
struct Sig_ADXT_Stop_SJ_np_fn_1_3AEC4 {
    const Sig_ADXT_Stop_SJInterface_np_fn_1_3AEC4 *interface;
};

/* fn_1_3AEC4 */
typedef struct Sig_ADXT_Stop_ADXTHandle_np_fn_1_3AEC4 {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Stop_AdxSjdHandle *decoder;
    Sig_ADXT_Stop_ADXStream *stream;
    Sig_ADXT_Stop_AXRNAHandle *rna;
    Sig_ADXT_Stop_SJ_np_fn_1_3AEC4 *stream_sj;
    Sig_ADXT_Stop_SJ_np_fn_1_3AEC4 *input_sj;
    Sig_ADXT_Stop_SJ_np_fn_1_3AEC4 *output_sj[2];
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
    Sig_ADXT_Stop_SJ_np_fn_1_3AEC4 *amplifier_input[2];
    Sig_ADXT_Stop_SJ_np_fn_1_3AEC4 *amplifier_output[2];
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
} Sig_ADXT_Stop_ADXTHandle_np_fn_1_3AEC4;

/* fn_1_3AEC4 */
typedef struct {
    u8 unk[0xb];
    u8 value;
} Entry_np_fn_1_3AEC4;

/* fn_1_3AEC4 */
/* GameEntry: see GameEntry */

/* fn_1_3AEC4 */
typedef struct {
    u8 pad[0x2f8];
    GXColor value_2f8;
    GXColor value_2fc;
    u32 value_300;
    u32 value_304;
    u32 value_308;
    u32 value_30c;
    u32 value_310;
    u32 value_314;
    u32 value_318;
    u32 value_31c;
} Fn40710Config_np_fn_1_3AEC4;

/* fn_1_3CDB0 */
typedef struct Obj_1_bss_7EFD8_fn_1_3CDB0 {
    u32 unk_0;
} Obj_1_bss_7EFD8_fn_1_3CDB0;

/* fn_1_3DB9C */
typedef struct Sig_ADXT_Pause_SJCK_np_fn_1_3DB9C {
    unsigned char *data;
    int len;
} Sig_ADXT_Pause_SJCK_np_fn_1_3DB9C;

/* fn_1_3DB9C */
typedef struct Sig_ADXT_Pause_SJInterface_np_fn_1_3DB9C Sig_ADXT_Pause_SJInterface_np_fn_1_3DB9C;

/* fn_1_3DB9C */
typedef struct Sig_ADXT_Pause_SJ_np_fn_1_3DB9C Sig_ADXT_Pause_SJ_np_fn_1_3DB9C;

/* fn_1_3DB9C */
struct Sig_ADXT_Pause_SJ_np_fn_1_3DB9C {
    const Sig_ADXT_Pause_SJInterface_np_fn_1_3DB9C *interface;
};

/* fn_1_3DB9C */
struct Sig_ADXT_Pause_SJInterface_np_fn_1_3DB9C {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Pause_SJ_np_fn_1_3DB9C *sj);
    const void *(*get_uuid)(Sig_ADXT_Pause_SJ_np_fn_1_3DB9C *sj);
    void (*reset)(Sig_ADXT_Pause_SJ_np_fn_1_3DB9C *sj);
    void (*get_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_3DB9C *sj, int channel, int max_size, Sig_ADXT_Pause_SJCK_np_fn_1_3DB9C *chunk);
    void (*unget_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_3DB9C *sj, int channel, Sig_ADXT_Pause_SJCK_np_fn_1_3DB9C *chunk);
    void (*put_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_3DB9C *sj, int channel, Sig_ADXT_Pause_SJCK_np_fn_1_3DB9C *chunk);
    int (*get_num_data)(Sig_ADXT_Pause_SJ_np_fn_1_3DB9C *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_3DB9C *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Pause_SJ_np_fn_1_3DB9C *sj, Sig_ADXT_Pause_SJErrorCallback callback, void *object);
};

/* fn_1_3DB9C */
typedef struct Sig_ADXT_Pause_ADXTHandle_np_fn_1_3DB9C {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Pause_AdxSjdHandle *decoder;
    Sig_ADXT_Pause_ADXStream *stream;
    Sig_ADXT_Pause_AXRNAHandle *rna;
    Sig_ADXT_Pause_SJ_np_fn_1_3DB9C *stream_sj;
    Sig_ADXT_Pause_SJ_np_fn_1_3DB9C *input_sj;
    Sig_ADXT_Pause_SJ_np_fn_1_3DB9C *output_sj[2];
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
    Sig_ADXT_Pause_SJ_np_fn_1_3DB9C *amplifier_input[2];
    Sig_ADXT_Pause_SJ_np_fn_1_3DB9C *amplifier_output[2];
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
} Sig_ADXT_Pause_ADXTHandle_np_fn_1_3DB9C;

/* fn_1_3DB9C */
typedef struct Sig_ADXT_Stop_SJCK_np_fn_1_3DB9C {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK_np_fn_1_3DB9C;

/* fn_1_3DB9C */
typedef struct Sig_ADXT_Stop_SJInterface_np_fn_1_3DB9C Sig_ADXT_Stop_SJInterface_np_fn_1_3DB9C;

/* fn_1_3DB9C */
typedef struct Sig_ADXT_Stop_SJ_np_fn_1_3DB9C Sig_ADXT_Stop_SJ_np_fn_1_3DB9C;

/* fn_1_3DB9C */
struct Sig_ADXT_Stop_SJInterface_np_fn_1_3DB9C {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ_np_fn_1_3DB9C *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ_np_fn_1_3DB9C *sj);
    void (*reset)(Sig_ADXT_Stop_SJ_np_fn_1_3DB9C *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_3DB9C *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK_np_fn_1_3DB9C *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_3DB9C *sj, int channel, Sig_ADXT_Stop_SJCK_np_fn_1_3DB9C *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_3DB9C *sj, int channel, Sig_ADXT_Stop_SJCK_np_fn_1_3DB9C *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ_np_fn_1_3DB9C *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_3DB9C *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ_np_fn_1_3DB9C *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};

/* fn_1_3DB9C */
struct Sig_ADXT_Stop_SJ_np_fn_1_3DB9C {
    const Sig_ADXT_Stop_SJInterface_np_fn_1_3DB9C *interface;
};

/* fn_1_3DB9C */
typedef struct Sig_ADXT_Stop_ADXTHandle_np_fn_1_3DB9C {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Stop_AdxSjdHandle *decoder;
    Sig_ADXT_Stop_ADXStream *stream;
    Sig_ADXT_Stop_AXRNAHandle *rna;
    Sig_ADXT_Stop_SJ_np_fn_1_3DB9C *stream_sj;
    Sig_ADXT_Stop_SJ_np_fn_1_3DB9C *input_sj;
    Sig_ADXT_Stop_SJ_np_fn_1_3DB9C *output_sj[2];
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
    Sig_ADXT_Stop_SJ_np_fn_1_3DB9C *amplifier_input[2];
    Sig_ADXT_Stop_SJ_np_fn_1_3DB9C *amplifier_output[2];
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
} Sig_ADXT_Stop_ADXTHandle_np_fn_1_3DB9C;

/* fn_1_3DB9C */
typedef struct {
    u8 unk[0xb];
    u8 value;
} Entry_np_fn_1_3DB9C;

/* fn_1_3DB9C */
/* GameEntry: see GameEntry */

/* fn_1_3DB9C */
typedef struct {
    u8 pad[0x2f8];
    GXColor value_2f8;
    GXColor value_2fc;
    u32 value_300;
    u32 value_304;
    u32 value_308;
    u32 value_30c;
    u32 value_310;
    u32 value_314;
    u32 value_318;
    u32 value_31c;
} Fn40710Config_np_fn_1_3DB9C;

/* fn_1_3DE80 */
typedef struct {
    f32 x, y, z;
} GameVec;

/* fn_1_3E62C */
typedef struct Sig_ADXT_Pause_SJCK_np_fn_1_3E62C {
    unsigned char *data;
    int len;
} Sig_ADXT_Pause_SJCK_np_fn_1_3E62C;

/* fn_1_3E62C */
typedef struct Sig_ADXT_Pause_SJInterface_np_fn_1_3E62C Sig_ADXT_Pause_SJInterface_np_fn_1_3E62C;

/* fn_1_3E62C */
typedef struct Sig_ADXT_Pause_SJ_np_fn_1_3E62C Sig_ADXT_Pause_SJ_np_fn_1_3E62C;

/* fn_1_3E62C */
struct Sig_ADXT_Pause_SJ_np_fn_1_3E62C {
    const Sig_ADXT_Pause_SJInterface_np_fn_1_3E62C *interface;
};

/* fn_1_3E62C */
struct Sig_ADXT_Pause_SJInterface_np_fn_1_3E62C {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Pause_SJ_np_fn_1_3E62C *sj);
    const void *(*get_uuid)(Sig_ADXT_Pause_SJ_np_fn_1_3E62C *sj);
    void (*reset)(Sig_ADXT_Pause_SJ_np_fn_1_3E62C *sj);
    void (*get_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_3E62C *sj, int channel, int max_size, Sig_ADXT_Pause_SJCK_np_fn_1_3E62C *chunk);
    void (*unget_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_3E62C *sj, int channel, Sig_ADXT_Pause_SJCK_np_fn_1_3E62C *chunk);
    void (*put_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_3E62C *sj, int channel, Sig_ADXT_Pause_SJCK_np_fn_1_3E62C *chunk);
    int (*get_num_data)(Sig_ADXT_Pause_SJ_np_fn_1_3E62C *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_3E62C *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Pause_SJ_np_fn_1_3E62C *sj, Sig_ADXT_Pause_SJErrorCallback callback, void *object);
};

/* fn_1_3E62C */
typedef struct Sig_ADXT_Pause_ADXTHandle_np_fn_1_3E62C {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Pause_AdxSjdHandle *decoder;
    Sig_ADXT_Pause_ADXStream *stream;
    Sig_ADXT_Pause_AXRNAHandle *rna;
    Sig_ADXT_Pause_SJ_np_fn_1_3E62C *stream_sj;
    Sig_ADXT_Pause_SJ_np_fn_1_3E62C *input_sj;
    Sig_ADXT_Pause_SJ_np_fn_1_3E62C *output_sj[2];
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
    Sig_ADXT_Pause_SJ_np_fn_1_3E62C *amplifier_input[2];
    Sig_ADXT_Pause_SJ_np_fn_1_3E62C *amplifier_output[2];
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
} Sig_ADXT_Pause_ADXTHandle_np_fn_1_3E62C;

/* fn_1_3E62C */
typedef struct Sig_ADXT_Stop_SJCK_np_fn_1_3E62C {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK_np_fn_1_3E62C;

/* fn_1_3E62C */
typedef struct Sig_ADXT_Stop_SJInterface_np_fn_1_3E62C Sig_ADXT_Stop_SJInterface_np_fn_1_3E62C;

/* fn_1_3E62C */
typedef struct Sig_ADXT_Stop_SJ_np_fn_1_3E62C Sig_ADXT_Stop_SJ_np_fn_1_3E62C;

/* fn_1_3E62C */
struct Sig_ADXT_Stop_SJInterface_np_fn_1_3E62C {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ_np_fn_1_3E62C *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ_np_fn_1_3E62C *sj);
    void (*reset)(Sig_ADXT_Stop_SJ_np_fn_1_3E62C *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_3E62C *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK_np_fn_1_3E62C *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_3E62C *sj, int channel, Sig_ADXT_Stop_SJCK_np_fn_1_3E62C *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_3E62C *sj, int channel, Sig_ADXT_Stop_SJCK_np_fn_1_3E62C *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ_np_fn_1_3E62C *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_3E62C *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ_np_fn_1_3E62C *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};

/* fn_1_3E62C */
struct Sig_ADXT_Stop_SJ_np_fn_1_3E62C {
    const Sig_ADXT_Stop_SJInterface_np_fn_1_3E62C *interface;
};

/* fn_1_3E62C */
typedef struct Sig_ADXT_Stop_ADXTHandle_np_fn_1_3E62C {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Stop_AdxSjdHandle *decoder;
    Sig_ADXT_Stop_ADXStream *stream;
    Sig_ADXT_Stop_AXRNAHandle *rna;
    Sig_ADXT_Stop_SJ_np_fn_1_3E62C *stream_sj;
    Sig_ADXT_Stop_SJ_np_fn_1_3E62C *input_sj;
    Sig_ADXT_Stop_SJ_np_fn_1_3E62C *output_sj[2];
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
    Sig_ADXT_Stop_SJ_np_fn_1_3E62C *amplifier_input[2];
    Sig_ADXT_Stop_SJ_np_fn_1_3E62C *amplifier_output[2];
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
} Sig_ADXT_Stop_ADXTHandle_np_fn_1_3E62C;

/* fn_1_3E62C */
typedef struct {
    u8 unk[0xb];
    u8 value;
} Entry_np_fn_1_3E62C;

/* fn_1_3E62C */
/* GameEntry: see GameEntry */

/* fn_1_3E62C */
typedef struct {
    u8 pad[0x2f8];
    GXColor value_2f8;
    GXColor value_2fc;
    u32 value_300;
    u32 value_304;
    u32 value_308;
    u32 value_30c;
    u32 value_310;
    u32 value_314;
    u32 value_318;
    u32 value_31c;
} Fn40710Config_np_fn_1_3E62C;

/* fn_1_3EA90 */
typedef struct Sig_ADXT_Pause_SJCK_np_fn_1_3EA90 {
    unsigned char *data;
    int len;
} Sig_ADXT_Pause_SJCK_np_fn_1_3EA90;

/* fn_1_3EA90 */
typedef struct Sig_ADXT_Pause_SJInterface_np_fn_1_3EA90 Sig_ADXT_Pause_SJInterface_np_fn_1_3EA90;

/* fn_1_3EA90 */
typedef struct Sig_ADXT_Pause_SJ_np_fn_1_3EA90 Sig_ADXT_Pause_SJ_np_fn_1_3EA90;

/* fn_1_3EA90 */
struct Sig_ADXT_Pause_SJ_np_fn_1_3EA90 {
    const Sig_ADXT_Pause_SJInterface_np_fn_1_3EA90 *interface;
};

/* fn_1_3EA90 */
struct Sig_ADXT_Pause_SJInterface_np_fn_1_3EA90 {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Pause_SJ_np_fn_1_3EA90 *sj);
    const void *(*get_uuid)(Sig_ADXT_Pause_SJ_np_fn_1_3EA90 *sj);
    void (*reset)(Sig_ADXT_Pause_SJ_np_fn_1_3EA90 *sj);
    void (*get_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_3EA90 *sj, int channel, int max_size, Sig_ADXT_Pause_SJCK_np_fn_1_3EA90 *chunk);
    void (*unget_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_3EA90 *sj, int channel, Sig_ADXT_Pause_SJCK_np_fn_1_3EA90 *chunk);
    void (*put_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_3EA90 *sj, int channel, Sig_ADXT_Pause_SJCK_np_fn_1_3EA90 *chunk);
    int (*get_num_data)(Sig_ADXT_Pause_SJ_np_fn_1_3EA90 *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_3EA90 *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Pause_SJ_np_fn_1_3EA90 *sj, Sig_ADXT_Pause_SJErrorCallback callback, void *object);
};

/* fn_1_3EA90 */
typedef struct Sig_ADXT_Pause_ADXTHandle_np_fn_1_3EA90 {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Pause_AdxSjdHandle *decoder;
    Sig_ADXT_Pause_ADXStream *stream;
    Sig_ADXT_Pause_AXRNAHandle *rna;
    Sig_ADXT_Pause_SJ_np_fn_1_3EA90 *stream_sj;
    Sig_ADXT_Pause_SJ_np_fn_1_3EA90 *input_sj;
    Sig_ADXT_Pause_SJ_np_fn_1_3EA90 *output_sj[2];
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
    Sig_ADXT_Pause_SJ_np_fn_1_3EA90 *amplifier_input[2];
    Sig_ADXT_Pause_SJ_np_fn_1_3EA90 *amplifier_output[2];
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
} Sig_ADXT_Pause_ADXTHandle_np_fn_1_3EA90;

/* fn_1_3EA90 */
typedef struct Sig_ADXT_Stop_SJCK_np_fn_1_3EA90 {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK_np_fn_1_3EA90;

/* fn_1_3EA90 */
typedef struct Sig_ADXT_Stop_SJInterface_np_fn_1_3EA90 Sig_ADXT_Stop_SJInterface_np_fn_1_3EA90;

/* fn_1_3EA90 */
typedef struct Sig_ADXT_Stop_SJ_np_fn_1_3EA90 Sig_ADXT_Stop_SJ_np_fn_1_3EA90;

/* fn_1_3EA90 */
struct Sig_ADXT_Stop_SJInterface_np_fn_1_3EA90 {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ_np_fn_1_3EA90 *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ_np_fn_1_3EA90 *sj);
    void (*reset)(Sig_ADXT_Stop_SJ_np_fn_1_3EA90 *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_3EA90 *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK_np_fn_1_3EA90 *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_3EA90 *sj, int channel, Sig_ADXT_Stop_SJCK_np_fn_1_3EA90 *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_3EA90 *sj, int channel, Sig_ADXT_Stop_SJCK_np_fn_1_3EA90 *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ_np_fn_1_3EA90 *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_3EA90 *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ_np_fn_1_3EA90 *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};

/* fn_1_3EA90 */
struct Sig_ADXT_Stop_SJ_np_fn_1_3EA90 {
    const Sig_ADXT_Stop_SJInterface_np_fn_1_3EA90 *interface;
};

/* fn_1_3EA90 */
typedef struct Sig_ADXT_Stop_ADXTHandle_np_fn_1_3EA90 {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Stop_AdxSjdHandle *decoder;
    Sig_ADXT_Stop_ADXStream *stream;
    Sig_ADXT_Stop_AXRNAHandle *rna;
    Sig_ADXT_Stop_SJ_np_fn_1_3EA90 *stream_sj;
    Sig_ADXT_Stop_SJ_np_fn_1_3EA90 *input_sj;
    Sig_ADXT_Stop_SJ_np_fn_1_3EA90 *output_sj[2];
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
    Sig_ADXT_Stop_SJ_np_fn_1_3EA90 *amplifier_input[2];
    Sig_ADXT_Stop_SJ_np_fn_1_3EA90 *amplifier_output[2];
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
} Sig_ADXT_Stop_ADXTHandle_np_fn_1_3EA90;

/* fn_1_3EA90 */
typedef struct {
    u8 unk[0xb];
    u8 value;
} Entry_np_fn_1_3EA90;

/* fn_1_3EA90 */
/* GameEntry: see GameEntry */

/* fn_1_3EA90 */
typedef struct {
    u8 pad[0x2f8];
    GXColor value_2f8;
    GXColor value_2fc;
    u32 value_300;
    u32 value_304;
    u32 value_308;
    u32 value_30c;
    u32 value_310;
    u32 value_314;
    u32 value_318;
    u32 value_31c;
} Fn40710Config_np_fn_1_3EA90;

/* fn_1_3F2A0 */
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

/* fn_1_3F2A0 */
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

/* fn_1_3F8EC */
typedef struct {
    u32 unk_0;
    u8 pad_4[0x78];
    Vec3 unk_7c;
    u8 pad_88[0x64];
    s32 unk_ec;
    u8 pad_f0[0x124];
    u16 unk_214;
} ObjA;

/* fn_1_3F8EC */
typedef struct {
    u8 pad_0[0x50];
    Vec3 unk_50;
} ObjB;

/* fn_1_3F8EC */
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

/* fn_1_3FCF8 */
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

/* fn_1_402D4 */
typedef struct {
    u8 pad_0[8];
    u16 unk_8;
    u8 pad_A[0xA];
} Elem_1_bss_9F8;

/* fn_1_40354 */
typedef struct {
    u8 pad_0[8];
    u16 unk_8;
    u8 pad_A[0xa];
} Entry_1_bss_9F8;

/* fn_1_403D4 */
typedef struct Sig_ADXT_Pause_SJCK_np_fn_1_403D4 {
    unsigned char *data;
    int len;
} Sig_ADXT_Pause_SJCK_np_fn_1_403D4;

/* fn_1_403D4 */
typedef struct Sig_ADXT_Pause_SJInterface_np_fn_1_403D4 Sig_ADXT_Pause_SJInterface_np_fn_1_403D4;

/* fn_1_403D4 */
typedef struct Sig_ADXT_Pause_SJ_np_fn_1_403D4 Sig_ADXT_Pause_SJ_np_fn_1_403D4;

/* fn_1_403D4 */
struct Sig_ADXT_Pause_SJ_np_fn_1_403D4 {
    const Sig_ADXT_Pause_SJInterface_np_fn_1_403D4 *interface;
};

/* fn_1_403D4 */
struct Sig_ADXT_Pause_SJInterface_np_fn_1_403D4 {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Pause_SJ_np_fn_1_403D4 *sj);
    const void *(*get_uuid)(Sig_ADXT_Pause_SJ_np_fn_1_403D4 *sj);
    void (*reset)(Sig_ADXT_Pause_SJ_np_fn_1_403D4 *sj);
    void (*get_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_403D4 *sj, int channel, int max_size, Sig_ADXT_Pause_SJCK_np_fn_1_403D4 *chunk);
    void (*unget_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_403D4 *sj, int channel, Sig_ADXT_Pause_SJCK_np_fn_1_403D4 *chunk);
    void (*put_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_403D4 *sj, int channel, Sig_ADXT_Pause_SJCK_np_fn_1_403D4 *chunk);
    int (*get_num_data)(Sig_ADXT_Pause_SJ_np_fn_1_403D4 *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Pause_SJ_np_fn_1_403D4 *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Pause_SJ_np_fn_1_403D4 *sj, Sig_ADXT_Pause_SJErrorCallback callback, void *object);
};

/* fn_1_403D4 */
typedef struct Sig_ADXT_Pause_ADXTHandle_np_fn_1_403D4 {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Pause_AdxSjdHandle *decoder;
    Sig_ADXT_Pause_ADXStream *stream;
    Sig_ADXT_Pause_AXRNAHandle *rna;
    Sig_ADXT_Pause_SJ_np_fn_1_403D4 *stream_sj;
    Sig_ADXT_Pause_SJ_np_fn_1_403D4 *input_sj;
    Sig_ADXT_Pause_SJ_np_fn_1_403D4 *output_sj[2];
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
    Sig_ADXT_Pause_SJ_np_fn_1_403D4 *amplifier_input[2];
    Sig_ADXT_Pause_SJ_np_fn_1_403D4 *amplifier_output[2];
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
} Sig_ADXT_Pause_ADXTHandle_np_fn_1_403D4;

/* fn_1_403D4 */
typedef struct Sig_ADXT_Stop_SJCK_np_fn_1_403D4 {
    unsigned char *data;
    int len;
} Sig_ADXT_Stop_SJCK_np_fn_1_403D4;

/* fn_1_403D4 */
typedef struct Sig_ADXT_Stop_SJInterface_np_fn_1_403D4 Sig_ADXT_Stop_SJInterface_np_fn_1_403D4;

/* fn_1_403D4 */
typedef struct Sig_ADXT_Stop_SJ_np_fn_1_403D4 Sig_ADXT_Stop_SJ_np_fn_1_403D4;

/* fn_1_403D4 */
struct Sig_ADXT_Stop_SJInterface_np_fn_1_403D4 {
    void *reserved[3];
    void (*destroy)(Sig_ADXT_Stop_SJ_np_fn_1_403D4 *sj);
    const void *(*get_uuid)(Sig_ADXT_Stop_SJ_np_fn_1_403D4 *sj);
    void (*reset)(Sig_ADXT_Stop_SJ_np_fn_1_403D4 *sj);
    void (*get_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_403D4 *sj, int channel, int max_size, Sig_ADXT_Stop_SJCK_np_fn_1_403D4 *chunk);
    void (*unget_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_403D4 *sj, int channel, Sig_ADXT_Stop_SJCK_np_fn_1_403D4 *chunk);
    void (*put_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_403D4 *sj, int channel, Sig_ADXT_Stop_SJCK_np_fn_1_403D4 *chunk);
    int (*get_num_data)(Sig_ADXT_Stop_SJ_np_fn_1_403D4 *sj, int channel);
    int (*is_get_chunk)(Sig_ADXT_Stop_SJ_np_fn_1_403D4 *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_ADXT_Stop_SJ_np_fn_1_403D4 *sj, Sig_ADXT_Stop_SJErrorCallback callback, void *object);
};

/* fn_1_403D4 */
struct Sig_ADXT_Stop_SJ_np_fn_1_403D4 {
    const Sig_ADXT_Stop_SJInterface_np_fn_1_403D4 *interface;
};

/* fn_1_403D4 */
typedef struct Sig_ADXT_Stop_ADXTHandle_np_fn_1_403D4 {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    Sig_ADXT_Stop_AdxSjdHandle *decoder;
    Sig_ADXT_Stop_ADXStream *stream;
    Sig_ADXT_Stop_AXRNAHandle *rna;
    Sig_ADXT_Stop_SJ_np_fn_1_403D4 *stream_sj;
    Sig_ADXT_Stop_SJ_np_fn_1_403D4 *input_sj;
    Sig_ADXT_Stop_SJ_np_fn_1_403D4 *output_sj[2];
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
    Sig_ADXT_Stop_SJ_np_fn_1_403D4 *amplifier_input[2];
    Sig_ADXT_Stop_SJ_np_fn_1_403D4 *amplifier_output[2];
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
} Sig_ADXT_Stop_ADXTHandle_np_fn_1_403D4;

/* fn_1_403D4 */
typedef struct {
    u8 unk[0xb];
    u8 value;
} Entry_np_fn_1_403D4;

/* fn_1_403D4 */
/* GameEntry: see GameEntry */

/* fn_1_403D4 */
typedef struct {
    u8 pad[0x2f8];
    GXColor value_2f8;
    GXColor value_2fc;
    u32 value_300;
    u32 value_304;
    u32 value_308;
    u32 value_30c;
    u32 value_310;
    u32 value_314;
    u32 value_318;
    u32 value_31c;
} Fn40710Config_np_fn_1_403D4;

/* fn_1_403D4 */
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

/* fn_1_403D4 */
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

/* fn_1_403D4 */
typedef struct {
    u8 r, g, b, a;
} Fn403D4Color;

/* fn_1_403D4 */
typedef struct {
    Fn408E8Obj base;         /* 0x00 */
    u32 unk_24;
    Fn403D4Color colors[2];  /* 0x28 */
} Fn403D4Obj;

/* fn_1_4068C */
typedef struct fn_1_4068C_Color {
    u8 r, g, b, a;
} fn_1_4068C_Color;

/* fn_1_4068C */
typedef struct fn_1_4068C_Obj {
    u8 pad_0[0x3];
    u8 flags;
    u8 pad_4[0x8];
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    u8 pad_20[0x8];
    fn_1_4068C_Color unk_28;
    fn_1_4068C_Color unk_2C;
} fn_1_4068C_Obj;

/* fn_1_40710 */
typedef struct {
    u8 state;
    u8 enabled;
    u8 applied;
    u8 flags;
    char *text;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    u32 unk_20;
    u8 pad_24[4];
    GXColor unk_28;
    GXColor unk_2C;
} Fn40710Object;

/* fn_1_408E8 */
struct fn_1_408E8_Copy88 { u32 a[22]; };

/* fn_1_40BE4 */
typedef struct {
    u32 x;
    u32 y;
    u32 z;
    u32 w;
} Vec4u;

/* fn_1_411D4 */
typedef struct Fn411D4Cache {
    u8 pad_00[0x10];
    u32 flags[7];
    int cached[7];
    char *generated[7];
} Fn411D4Cache;

/* fn_1_412A0 */
typedef struct BssState {
    u8 pad_10[0x10];
    u32 second[7];
    s32 third[7];
    u32 first[7];
} BssState;

/* fn_1_41328 */
typedef struct RelocData {
    u32 count;
    u32 values[1];
} RelocData;

/* fn_1_41418 */
typedef struct Fn41418Data {
    u32 count;
    char *strings;
} Fn41418Data;

/* fn_1_41488 */
typedef struct Fn41488Data {
    u32 count;
    char *strings;
} Fn41488Data;

extern void ADXT_Pause(Sig_ADXT_Pause_ADXTHandle *, s32);
extern void ADXT_Stop(void *);
extern void ARQPostRequest(u8 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, u32 arg7);
extern void DCInvalidateRange(void *addr, u32 nBytes);
extern int DVDConvertPathToEntrynum(char *buffer);
extern u32 GXGetTexBufferSize(u32, u32, u32, u32, u32);
extern u32 OSGetTick(void);
extern s64 OSGetTime(void);
extern void OSPanic(const void *, u32, const char *, ...);
extern void OSReport(const char *format, ...);
extern void VIWaitForRetrace(void);
extern f64 __fabs(f64);
extern s16 camera_get_entry_field_0x2(u32 index);
extern s32 camera_get_flags(void);
extern u32 camera_get_status(void);
extern void camera_set_state_flag(u8);
extern void camera_update(void);
extern u32 fn_1_101C0(void);
extern void fn_1_104710(void);
extern void fn_1_1049E0(void);
extern void fn_1_1050D0(void);
extern void fn_1_105724(void);
extern void fn_1_106EB0(void *);
extern void fn_1_1280(s32);
extern void fn_1_128F10(void);
extern void fn_1_128F54(void);
extern void fn_1_12907C(void);
extern void fn_1_12AB38(void *arg0);
extern u32 fn_1_12AF50(u32);
extern u32 fn_1_12AF64(void);
extern void fn_1_12B120(GameLink *, u32, u32, s32 *, s32 *, s32 *);
extern s16 fn_1_12B3BC(GameLink *, u32, u32, void *, void *, void *, u32);
extern void fn_1_12B3F8(void *, u32, u32, void *, void *, void *);
extern void fn_1_12B5B4(s16, s16);
extern void fn_1_12C060(GameLinkSlot *);
extern void fn_1_12C0EC(GameLinkSlot *);
extern s16 fn_1_12C7B8(s16);
extern s16 fn_1_12C930(s16);
extern char *fn_1_12D254(s32, s32);
extern s16 fn_1_12EF24(s16 row, s16 column);
extern u32 fn_1_12EF80(u8, s16 *, s16 *);
extern void fn_1_12F10C(void *);
extern void *fn_1_12F118(void);
extern void fn_1_12F194(void);
extern void fn_1_12F28C(u32 heap, s32 *task, s32 priority, u8 *arg3);
extern void fn_1_12F30C(u32 heap, s32 *task);
extern void fn_1_12F308(void);
extern u32 fn_1_12F358(u32);
extern s32 fn_1_13018(void);
extern void fn_1_14A00C(void);
extern void fn_1_14A028(void);
extern void fn_1_14A17C(void);
extern char *fn_1_14EA74(s16 arg0, char *arg1, s16 arg2);
extern u8 * fn_1_14F04(void);
extern void fn_1_14F38C(GameEntry *, RaceBuf *);
extern void fn_1_14F6F8(u8 arg0, u8 arg1, u8 arg2, void *arg3);
extern void fn_1_154708(u32);
extern void fn_1_1547FC(void);
extern s32 fn_1_154C84(void);
extern void fn_1_154CC4(s32);
extern void fn_1_1554D0(void);
extern void fn_1_15555C(void);
extern s32 fn_1_1555B0(s32);
extern int fn_1_15578();
extern void fn_1_155F9C(u32);
extern void fn_1_155FA8(u32);
extern void fn_1_1566F8(s32, RacerStatus *);
extern void fn_1_156754(s32);
extern void fn_1_1567A8(s32);
extern void fn_1_159478(s32, s32, s32);
extern void fn_1_1596DC(int);
extern char *fn_1_15BA78(char *name);
extern void fn_1_15C36C(void);
extern void fn_1_15E260(s32 arg0);
extern void fn_1_15E27C(void);
extern void fn_1_15E330(s32 index, u32 value, void *arg);
extern void fn_1_15E3E0(s32 index, u32 value);
extern void fn_1_15E434(u32 value);
extern void fn_1_15E44C(void);
extern void fn_1_15E540(s32 index, u32 heap);
extern void fn_1_15E5E4(s32 index, void *arg);
extern void fn_1_15E688(s32 index, u32 value, u8 state, u32 heap);
extern void fn_1_15E764(s32, u32);
extern int fn_1_163BC(void *arg0, void *arg1, int mask, int value);
extern int fn_1_16BA0(void *, void *, void *, int *, int);
extern f32 fn_1_16E68(void *, void *, int);
extern void fn_1_17D5C(Node *node, u32 *acc);
extern int fn_1_180F4(int first, int second, int count, int ascending);
extern void fn_1_18214();
extern void fn_1_18784();
extern void fn_1_18F28(Fn118F28Object *obj, int *args, int arg2, float value);
extern void fn_1_1902C(StcoliNode *root, StcoliVec *vec, void *arg3, f32 value);
extern u32 fn_1_1FB80(void *arg0, s32 arg1);
extern u32 fn_1_203E4(void *, u32, void *, f32, f32, f32);
extern int fn_1_210A8(void *, f32 *, int, int, int);
extern void fn_1_21950(u32 arg0, f32 arg1, f32 arg2);
extern void fn_1_22B10(void *, f32);
extern void fn_1_22E8C(Racer*,Input*);
extern void fn_1_22F90(void *self, int value);
extern u32 fn_1_2B684(u32);
extern void fn_1_3308(void);
extern u8 fn_1_3BB0(u32);
extern void fn_1_3C98(void);
extern void fn_1_3CC4(void);
extern void fn_1_3CF0(u32 heap, u32 count);
extern s32 fn_1_3F8C(char *name, void *func, void *arg, s32 priority);
extern void fn_1_4010(u32 task, void *func);
extern void fn_1_4030(void (*func)(void));
extern u32 fn_1_4060(void);
extern void fn_1_407C(void);
extern void fn_1_41A8(void);
extern void fn_1_426C(u32);
extern void fn_1_4270C(void *arg0, u32 arg1, u32 arg2);
extern void fn_1_4310(u32 arg0);
extern void fn_1_4324(u32);
extern u32 fn_1_4338(void);
extern u32 fn_1_434C(void);
extern u32 fn_1_435C(u32 value);
extern void fn_1_43E8(u32);
extern void fn_1_43F4(void);
extern u32 fn_1_44A4(void);
extern u32 fn_1_451C(void);
extern void fn_1_451E4(void);
extern u32 fn_1_45D0(u32 heap, u32 size, char *file, s32 line);
extern u32 fn_1_4630(u32 heap, u32 size, const char *file, s32 line);
extern void fn_1_465D0(char *value, u32 flag);
extern s32 fn_1_467F4(void);
extern void fn_1_469BC(void);
extern void fn_1_46A60(void);
extern u32 fn_1_46A8C(u32);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern u32 fn_1_46B44(void *, void *);
extern u32 fn_1_46C60(void);
extern void fn_1_46EA8(u32);
extern void fn_1_46EE8(void);
extern void fn_1_4706C(void);
extern void fn_1_479F0(s16 index);
extern void fn_1_47E54(s32);
extern void fn_1_47F74(s32);
extern void fn_1_48004(s32 index, s32 image);
extern void fn_1_4811C(int arg);
extern void fn_1_48140(int);
extern void fn_1_48164(int);
extern void fn_1_484CC(s32);
extern s32 fn_1_485A8(s32);
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern s32 fn_1_48B0(u32 arg0, u32 arg1);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_49514(GXColor *color);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49590(f32 value);
extern void fn_1_495A0(f32);
extern void fn_1_495B0(u32 value);
extern void fn_1_495C8(u8 value);
extern void fn_1_495FC(void);
extern void fn_1_49614(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49F0(GXColor *color);
extern void fn_1_4A00(s32 enabled, u8 mode, u32 value);
extern void fn_1_4A0D8(const char *);
extern u32 fn_1_4AEC0(u32 value);
extern u32 fn_1_4AEE8(u32);
extern void fn_1_4AF10(void *);
extern f32 fn_1_4B068(char *);
extern f32 fn_1_4B090(char *);
extern int fn_1_4C10(void);
extern void fn_1_4CC0(void);
extern void fn_1_4DE04(void);
extern void fn_1_4E724(void *);
extern void fn_1_50A90(void *, u32, u32, u32, u32);
extern void fn_1_5124(u32, u32);
extern void fn_1_5370(u32 arg0, u32 arg1);
extern void fn_1_545B8(void);
extern void fn_1_556B8(void *);
extern void fn_1_55A84(void (*callback)(void), void *arg0, s32 arg1, s32 arg2);
extern void fn_1_55FF0(f32);
extern void fn_1_56018(s32);
extern void fn_1_560F0(s32, u32);
extern void fn_1_56B8(void);
extern u32 fn_1_584AC(void);
extern void fn_1_584D4(void);
extern void fn_1_58694(void);
extern void fn_1_58854(void);
extern void fn_1_58994(void);
extern u32 fn_1_58C4(void);
extern void fn_1_58C6C(void);
extern void fn_1_58D38(void);
extern u32 fn_1_5910(void);
extern void fn_1_59290(void);
extern void fn_1_5948(u32);
extern void fn_1_627C(u32);
extern void fn_1_6400(void);
extern void fn_1_6BC0(void);
extern void fn_1_7269C(u32, u32, void *);
extern u32 fn_1_76504(u32, void *, void *);
extern void fn_1_76BF8(void);
extern void fn_1_789AC(void);
extern void fn_1_789E8(void);
extern void fn_1_78EBC(void);
extern void fn_1_79100(void);
extern u32 fn_1_7ACDC(u8);
extern s16 fn_1_7B054();
extern u8 fn_1_7B074(void);
extern void fn_1_7B084(u32, int);
extern u32 fn_1_7BA08(u16 maxLights, u16 maxSpecs, u16 maxSets);
extern void fn_1_7BA48(void);
extern void fn_1_7BAF8(void);
extern void fn_1_7E9C4(void);
extern void fn_1_7EAE8(void);
extern void *fn_1_7F49C(s16 arg0, s16 arg1, void *arg2);
extern void* fn_1_7F518(s16 car_type, void* car, s32 initialize);
extern char *fn_1_7F58C(s16, void *, u8, s32);
extern void fn_1_8001C(void);
extern void fn_1_80058(u8, GameEntry *);
extern void fn_1_8019C(void *);
extern void fn_1_81164(GameCar *, s16, s16);
extern void fn_1_81408(GameCar *, u8, u8);
extern u32 fn_1_8171C(s32);
extern void fn_1_8176C(void *);
extern void fn_1_81778(void);
extern void fn_1_817C0(void);
extern void fn_1_81808(s8 *);
extern void fn_1_81834(s8, s8, s8);
extern u32 fn_1_82724(u32, u32, void *, u32, u32);
extern void *fn_1_82EDC(s16, s16, void *);
extern Racer *fn_1_83070(u32, u32, GameEntry *, u8);
extern void fn_1_835E0(void *, u32, void *);
extern f32 fn_1_84038(void *, s16, u8, f32);
extern u8 fn_1_84794(s16);
extern void fn_1_85878(void);
extern void fn_1_8589C(Obj3C30 *);
extern void fn_1_8616C(void);
extern void fn_1_86194(f32);
extern void fn_1_861B4(void);
extern s32 fn_1_8623C(void);
extern Racer *fn_1_86254(s32);
extern u32 fn_1_8627C(int index);
extern void fn_1_862D4(u32 arg0, void *arg1);
extern s8 fn_1_86624(void);
extern u8 fn_1_86810(s32);
extern GameCar *fn_1_868C0(s8 index);
extern GameCar *fn_1_86900(s8);
extern void fn_1_87074(void);
extern void fn_1_8A190(void *arg0, void *arg1);
extern u32 fn_1_8C66C(u32 index);
extern u32 fn_1_8C884(s32);
extern u32 fn_1_8D5F0(s16);
extern int fn_1_8D72C(s16);
extern s16 fn_1_8D7C8(void);
extern void fn_1_8D894(Racer *);
extern void fn_1_8D988(void);
extern void fn_1_8DAB4(void);
extern s32 fn_1_8DB94(void);
extern void fn_1_8DBA4(s32);
extern u32 fn_1_8DBB0(void);
extern void fn_1_8DD54(void);
extern void fn_1_981C4(void);
extern void fn_1_98230(void);
extern void fn_1_982C4(void);
extern void fn_1_9835C(void);
extern void fn_1_98590(void);
extern Obj_1_data_27DE0 *fn_1_986A4(Obj_1_data_27DE0 *obj);
extern void fn_1_98804(Obj_1_data_27DE0 *obj);
extern void fn_1_9A578(void);
extern void fn_1_9A5CC(void);
extern void fn_1_9A770(void);
extern void fn_1_9A7BC(void);
extern void fn_1_9A958(int, int);
extern void fn_1_9AF80(u32 arg0, u32 arg1, u32 arg2);
extern void fn_1_9CC6C(void *arg0, s32 arg1);
extern u32 fn_1_9D260(void);
extern void fn_1_9D360(void);
extern void fn_1_9D77C(u32, u32);
extern void fn_1_9E14C();
extern void fn_1_9E170(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_1_A0680(void);
extern void fn_1_A0978(void);
extern u32 fn_1_A0AA4(void);
extern void fn_1_A0C68(void);
extern void fn_1_A0D20(void);
extern u32 fn_1_A11EC(void);
extern void fn_1_A1588(void *h, u8 track);
extern void fn_1_A1DCC(u8);
extern void fn_1_A2210(u8);
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_A2DC4(u32 arg0);
extern void fn_1_A2DF4(int arg0, u32 arg1, int arg2);
extern void fn_1_A2E24(int arg0, u32 arg1, int arg2);
extern void fn_1_A4F18(u8);
extern s8 fn_1_A5DC4(void);
extern u32 fn_1_A7024(f32, f32, f32, f32);
extern void fn_1_A714C(f32 *a, f32 *b, f32 *c, f32 *d);
extern void fn_1_A75DC(GameCar *, s32);
extern void fn_1_A8F78(void);
extern void fn_1_A96DC(void);
extern void fn_1_A96EC(void);
extern int fn_1_B7E98(int);
extern u32 fn_1_C3A0C(void);
extern void fn_1_C42F4(void);
extern void fn_1_C47B4(void);
extern void fn_1_C6F80(u8);
extern void fn_1_C6F8C(void);
extern void fn_1_C7224(void);
extern void fn_1_CB404(u8 value);
extern void fn_1_D0728(void);
extern void fn_1_D0790(void);
extern void fn_1_D07AC(u32, u32);
extern void fn_1_D07C4(u32 arg0, u32 arg1);
extern void fn_1_D1780(void);
extern void fn_1_D17E8(void);
extern void fn_1_D1848(void);
extern void fn_1_D19B8(void *);
extern void fn_1_D1C94(void);
extern void fn_1_D1F88(void);
extern void fn_1_D2404(void);
extern void fn_1_D27B8(void);
extern u32 fn_1_D2FB0(void);
extern void fn_1_D3214(void);
extern void fn_1_D3474(void);
extern void fn_1_D358C();
extern void fn_1_D3884();
extern void fn_1_DCF54(GameVec *, GameVec *, GameVec *);
extern u32 fn_1_E3324(void);
extern void fn_1_E35F0(void);
extern void fn_1_E3778(void);
extern void fn_1_E38D4(void);
extern void fn_1_E39F0(void);
extern void fn_1_E49D4(void);
extern void fn_1_E95B4(void);
extern void fn_1_E9770(u32 a, u32 b, u8 race_type, u8 course);
extern u16 fn_1_E9CFC(void);
extern void fn_1_EA314(s32);
extern void fn_1_EB074(s32);
extern void fn_1_EB080(int mode);
extern s32 fn_1_EB200(void);
extern s32 fn_1_EB248(void);
extern s32 fn_1_F1B84(void);
extern void fn_1_F2008(s32 arg);
extern void fn_1_F220C(s32);
extern s32 fn_1_F2280(s32);
extern s32 fn_1_F22D4(void);
extern u32 fn_1_F2338(s32, u32);
extern void fn_1_F23D8(void);
extern void fn_1_F23E8(void);
extern void fn_1_F2780(u8 humans, u8 *ports);
extern void fn_1_F2DDC(void);
extern void fn_1_F2E50(s32);
extern void fn_1_F2EB8(void);
extern void fn_1_F2EDC(void);
extern void fn_1_F2EFC(void);
extern s32 fn_1_F2F34(void);
extern s32 fn_1_F2F58(void);
extern void fn_1_F2F84(void);
extern void fn_1_F326C(void);
extern void fn_1_F37F4(void);
extern void fn_1_F38C0(void);
extern void fn_1_F3AB0(void);
extern void fn_1_F3BC0(void);
extern u32 fn_1_F4594(void);
extern u32 fn_1_F45A4(void);
extern u8 fn_1_F45B4(void);
extern void fn_1_F70D0(void);
extern void fn_1_F7128(void);
extern void fn_1_F7308(void);
extern void fn_1_F7338(s32, s32, s32);
extern void fn_1_F7578(void);
extern void fn_1_F78AC(void *);
extern void fn_1_F78D8(void *);
extern s32 fn_1_F7EDC(s16);
extern void fn_1_F7F48(s16 value);
extern int fn_1_F8334(s16);
extern void fn_1_F83F0(s16 arg0);
extern int fn_1_F8A38(u8);
extern void fn_1_F8A58(u32 value);
extern void fn_1_F8C00(s32 value);
extern u8 fn_1_F8C50(s32 arg0);
extern u32 fn_1_F8D10(void);
extern void fn_1_F8D38(u32 value);
extern s32 fn_1_F9D44(u32 arg);
extern void fn_1_F9D68(u32 arg);
extern void fn_1_F9DE8(u32 param);
extern void fn_1_F9F2C(u8, u8, u8, u8);
extern void fn_1_F9FB4(void);
extern u32 fn_1_F9FEC(void);
extern void fn_1_FA038(void);
extern u32 fn_1_FA070(void);
extern void fn_1_FA154(u8, u8);
extern int fn_1_FA180(u8, u8);
extern void fn_1_FA67C(s32);
extern void fn_1_FCF74(void);
extern void fn_80006E10(const char *path);
extern u32 fn_800075AC(u32, u32, u32);
extern void fn_80007AB4(u32 *arg0);
extern void fn_80008BA8(void *dst, void *src, u32 size);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern u32 fn_80008E84(u32);
extern u32 fn_80008F88(u32 start, u32 end);
extern void fn_80009064(u32);
extern u32 fn_800090A4(u32 heap);
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern s32 fn_8004BD5C(struct Sig_fn_8004BD5C_fn_8004BD5C_Arg0 *);
extern u32 fn_8004CD70(int arg0, void* arg1, u32 size);
extern void fn_80067344(int arg0, int arg1, u32 arg2, int arg3);
extern void fn_8006CE1C(f32);
extern void fn_8006E250(void *arg0, void *arg1);
extern void fn_8006E294(void *);
extern void fn_8006E7E4(void *, void *, s32);
extern void fn_8006E978(f32 *arg0, Vec3 *arg1, Vec3 *arg2);
extern void fn_8006EF10(void *, s16 *, s16 *);
extern s32 fn_8006FC1C(const char *, const char *);
extern s32 fn_8006FC5C(const char *, const char *, s32);
extern void fn_8006FDEC(void);
extern u32 fn_80070DE0(u32 arg0);
extern void fn_800711A8(Obj_1_bss_38458_Target *target);
extern void fn_800713E0(void *, void *);
extern void fn_80071718(u32 value);
extern void fn_80072558(void);
extern void fn_80074D18(u32);
extern void fn_800794F0(Obj_1_data_27DE0 *arg0, Obj_1_data_27DE0 *arg1, s32 arg2);
extern int strcmp(const char *s1, const char *s2);
extern s32 ghost_test_record_flag0(s32 arg);
extern u8 lbl_1_A9011000;
extern u8 lbl_1_A9011100;
extern u8 lbl_1_A9011300;
extern u8 lbl_1_bss_17AC;
extern u32 lbl_1_bss_38460[21];
extern Obj_1_bss_6EAB4 lbl_1_bss_6EAB4;
extern Obj_1_bss_6EAD0 lbl_1_bss_6EAD0;
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 pad_3;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 pad_7;
    u16 unk_8;
    u8 unk_A;
    u8 pad_B;
    f32 unk_C;
    f32 unk_10;
} SoundSlot;
extern SoundSlot lbl_1_bss_6F1E4[4];
extern u32 lbl_1_bss_6F23C;
extern u8 lbl_1_bss_6F316;
extern u8 lbl_1_bss_6F317;
extern u8 lbl_1_bss_6F31A;
extern u8 *lbl_1_bss_718C0;
extern u8 lbl_1_bss_718E0[];
extern Obj_1_bss_7F0C0 lbl_1_bss_7F0C0;
typedef struct {
    u8 pad_0[0x19];
    u8 unk_19;
} Obj_1_bss_8B3A0_AtA4;
typedef struct {
    u8 pad_0[0x2];
    s16 unk_2;
    u8 pad_4[0x4];
    u8 unk_8;
    u8 pad_9[0x17];
} Obj_1_bss_8B3A0_ElemC;
typedef struct {
    s16 unk_0;
    s16 unk_2;
} Obj_1_bss_8B3A0_ElemB0;
typedef struct {
    s16 unk_0;
    s16 unk_2;
} Obj_1_bss_8B3A0_ElemC0;
typedef struct {
    s16 unk_0;
    s16 unk_2;
} Obj_1_bss_8B3A0_ElemD0;
typedef struct {
    s16 unk_0;
    u8 pad_2[0x2];
    s16 unk_4;
    u8 pad_6[0x2];
    s16 unk_8;
    u8 pad_A[0x2];
    Obj_1_bss_8B3A0_ElemC unk_C[4];
    s16 unk_8C;
    u8 pad_8E[0x2];
    s16 unk_90;
    s16 unk_92;
    u32 unk_94;
    u8 pad_98[0x6];
    u8 unk_9E;
    u8 unk_9F[4];
    u8 pad_A3[0x1];
    Obj_1_bss_8B3A0_AtA4 *unk_A4;
    u8 pad_A8[0x8];
    Obj_1_bss_8B3A0_ElemB0 unk_B0[4];
    Obj_1_bss_8B3A0_ElemC0 unk_C0[4];
    Obj_1_bss_8B3A0_ElemD0 unk_D0[4];
    u32 unk_E0[4];
    u32 unk_F0[4];
    u32 unk_100[4];
    u32 unk_110[4];
    u32 unk_120;
    u32 unk_124;
    u8 unk_128;
    u8 unk_129;
    u8 pad_12A[0x2];
    s16 unk_12C;
    s16 unk_12E;
    s16 unk_130;
    s16 unk_132;
    s16 unk_134;
    s16 unk_136;
    s16 unk_138;
    s16 unk_13A;
    s16 unk_13C;
    u8 pad_13E[0x2];
    u32 unk_140;
    u8 pad_144[0x2];
    s16 unk_146;
    s16 unk_148;
    u8 pad_14A[0x2];
} Obj_1_bss_8B3A0;
extern Obj_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern u8 lbl_1_bss_8B5F0;
extern u8 lbl_1_bss_8B5F1;
extern BurnerWork lbl_1_bss_8B5F4;
extern u8 lbl_1_bss_8E51D;
extern s16 lbl_1_bss_960;
extern s16 lbl_1_bss_962;
extern s16 lbl_1_bss_968;
extern u16 lbl_1_bss_96A;
extern char lbl_1_bss_9C;
extern u8 lbl_1_data_1A2B4[];
extern u8 lbl_1_data_1EA28[12];
extern void *lbl_1_data_2A8D8[21];
extern void *lbl_1_data_2A92C[21];
extern u8 lbl_1_data_2B0D4[0x70];
extern u8 lbl_1_data_2B60[4],lbl_1_bss_D70[8];
extern char *lbl_1_data_2BD54[][6];
extern const u32 lbl_1_rodata_0[];
extern const FontDrawPacket lbl_1_rodata_26F8;
extern const u32 lbl_1_rodata_28[];
extern const u8 lbl_1_rodata_DB38[32];
extern const u16 lbl_1_rodata_DB58[];
extern const u16 lbl_1_rodata_DB94[];
extern const u16 lbl_1_rodata_DB9C[];
extern const u16 lbl_1_rodata_DBDC[];
extern const u16 lbl_1_rodata_DBE4[4][5][6];
extern const u16 lbl_1_rodata_DCD4[];
extern const u16 lbl_1_rodata_DCDC[4][5][2];
extern const u16 lbl_1_rodata_DD2C[4];
extern const u16 lbl_1_rodata_DD34[6][3];
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D188(s16 angle);
extern u32 lbl_8006D24C(f32, f32);
extern void lbl_8006D668(void *arg0);
extern f32 lbl_8006D6FC(void *, void *);
extern void lbl_8006D7B0(s32);
extern void lbl_8006D7DC(void *);
extern u32 lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006D848(f32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *arg0);
extern void lbl_8006DBE4();
extern u32 lbl_8006DCA4(void);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E0B4(f32, f32, f32);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006E1D8(void *arg0, f32 arg1, f32 arg2, f32 arg3);
extern void lbl_8006E1F0(void *, f32, f32, f32);
extern u32 lbl_801A63C0;
extern void *lbl_801A63D0;
/* The current heap handle of the DOL's allocator (a locked copy of the SDK's OSAlloc.c: fn_80008EC8 = OSInitAlloc sets it
   to -1, fn_80008E84 = OSSetCurrentHeap). The SDK declares its __OSCurrHeap with the same qualifier. Every real use is
   the load `lis; addi; lwz 0(rX)`. */
/* fzgx-allow: S2 the SDK's OSAlloc.c declares the current heap handle volatile */
extern volatile u32 lbl_801A6410;
/* WARNING: compiler-diff device, not original code (the dead reads are carried from main, this spelling is a
   reconstruction that retail does not prove). game.c is the only TU with reads of the heap handle whose value is
   discarded (21 sites, each after a loading step). They are what is left of a debug call that took the handle; its body
   is not in the retail build. The bare statement `lbl_801A6410;` compiles to the same code. */
static inline void game_heap_report(u32 heap) { }
extern u32 lbl_801A66A0;
extern u32 lbl_801A66B4;
extern u32 lbl_801A66C8[2];
extern Obj_801A66CC *lbl_801A66CC;
extern u32 lbl_801A6CE0;
extern u8 *lbl_801A6D00;
extern void mathutil_mtxA_from_quat(void *);
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void *memset(void *, int, unsigned int);
struct fn_1_40BE4_lbl_1_rodata_BD8_pool { u8 pad_0[0x30]; f32 unk_30; u8 pad_34[0xF8]; f32 unk_12C; u8 pad_130[0x214]; u32 unk_344; u32 unk_348; u32 unk_34C; u32 unk_350; f32 unk_354; };
extern int sprintf(char *s, const char *format, ...);
extern size_t strlen(const char *str);

void fn_1_2C768(u32 *arg0);
void fn_1_2C7C4(u8 *value, const u8 *target, int step);
u32 fn_1_2C908(void);
s32 fn_1_2C97C(void);
void fn_1_2CBAC(void);
void fn_1_2D038(void);
void fn_1_2D524(Obj5138 *arg0);
void fn_1_2D888(Obj5138 *box);
void fn_1_2DB50(Obj5138 *obj);
void fn_1_2DE00(s32 arg0);
s32 fn_1_2DF98(void);
void fn_1_2E1B8(void);
void fn_1_2E268(void);
void fn_1_2E3B4(GamePlayer *arg0, Racer *arg1);
void fn_1_2E928(Racer *racer);
s32 fn_1_2EBB8(u32 flags, u8 kind);
s32 fn_1_2EE3C(void);
void fn_1_2F294(void);
void fn_1_2FAA0(void);
void fn_1_2FDBC(struct fn_1_2FDBC_arg *arg0);
void fn_1_30054(void);
void fn_1_304A8(void);
void fn_1_30824(void);
void fn_1_30D84(void);
void fn_1_3129C(s32 arg);
void fn_1_3181C(void);
void fn_1_31C3C(u32 player);
void fn_1_320A4(void);
void fn_1_32200(Racer *racer, s32 port);
int fn_1_32600(Racer* obj);
void fn_1_327F8(Racer *arg0, u32 arg1);
void fn_1_32A40(Racer *racer);
void fn_1_331EC(Racer *r);
int fn_1_33890(Obj3C30 *arg0);
void fn_1_33A20(void);
void fn_1_34924(u16 *timer);
void fn_1_34AC0(s8 *arr, s8 start, s8 total, s32 mode);
void fn_1_34E08(void);
void fn_1_34F38(InitObj* obj);
void fn_1_35124(void);
void fn_1_3514C(void* arg0, int arg1);
void fn_1_35174(void);
void fn_1_35178(u32* arg0);
void fn_1_3522C(void);
void fn_1_359B8(void);
void fn_1_35BC4(void);
void fn_1_36330(void);
void fn_1_36A94(u32 arg0, void *arg1);
RaceBuf *fn_1_36AD0(void);
void fn_1_36ADC(void);
void fn_1_36B10(void);
void fn_1_37AA8(void);
void fn_1_37E98(void);
void fn_1_382C4(void);
void fn_1_384E8(void);
void fn_1_385A4(void);
void fn_1_3867C(void);
void fn_1_38BBC(void);
void fn_1_38CF4(void);
void fn_1_3908C(void);
void fn_1_391F0(void);
void fn_1_39420(void);
void fn_1_395CC(void);
void fn_1_39C60(void);
void fn_1_3A044(void);
void fn_1_3A2C4(void);
void fn_1_3A330(void);
void fn_1_3AEC4(void);
void fn_1_3B11C(void);
void fn_1_3B7D4(void);
void fn_1_3C880(void);
void fn_1_3CDB0(void);
void fn_1_3CE94(void);
void fn_1_3DB9C(void);
void fn_1_3DDAC(void);
void fn_1_3DE80(void);
void fn_1_3E5D0(void);
void fn_1_3E628(void);
void fn_1_3E62C(void);
void fn_1_3E66C(void);
void fn_1_3E670(void);
void fn_1_3E6D8(void);
void fn_1_3EA70(void);
void fn_1_3EA90(u8 count, u8 *name_src, u8 *code_src, u32 *value_src);
void fn_1_3EB78(u8 count, u8 *names, u8 *codes, u32 *values);
void fn_1_3EC88(u8 count, GameEntrant *src);
void fn_1_3ED8C(Obj3C30 *setup, u8 unk_4, u8 unk_1404, u8 course, u8 unk_7, u8 racers, u32 flags);
void fn_1_3EF08(u8 value);
void fn_1_3EF14(void *arg1);
void fn_1_3EF8C(u8 value);
s32 fn_1_3EFA8(void);
void fn_1_3EFF0(void (*arg1)(struct Obj3C30 *), u8 arg2);
void fn_1_3F02C(void (*arg1)(Obj3C30 *gs));
int fn_1_3F038(void);
s16 fn_1_3F0C8(void);
GameRaceRecord *fn_1_3F0D8(u32 index, f32 *value, u8 *flag);
u8 fn_1_3F114(void);
u8 fn_1_3F13C(void);
s32 fn_1_3F164(void);
u32 fn_1_3F1AC(u32 arg0);
s32 fn_1_3F1D4(void);
u8 fn_1_3F1F8(void);
u8 fn_1_3F23C(u32 index);
u8 fn_1_3F250(u32 index);
u8 fn_1_3F264(u32 index);
void fn_1_3F2A0(void);
s32 fn_1_3F440(u8 index);
void fn_1_3F4B8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5);
void fn_1_3F4FC(void);
void fn_1_3F5F8(void);
void fn_1_3F75C(void);
void fn_1_3F7A0(u32* self);
u32 fn_1_3F7D0(void);
u8 fn_1_3F7E0(void);
void fn_1_3F800(u32 value);
void fn_1_3F810(u8 value, u32 input);
void fn_1_3F834(u8 value);
void fn_1_3F844(u16 value);
u8 fn_1_3F854(void);
u8 fn_1_3F864(void);
void fn_1_3F894(void);
u32 fn_1_3F8C0(void);
void fn_1_3F8D0(void);
void fn_1_3F8EC(f32 arg0);
void fn_1_3FBF4(u32 arg0);
u16 fn_1_3FC18(void);
u32 fn_1_3FC28(void);
u8 fn_1_3FC38(void);
u32 fn_1_3FC48(void);
u32 fn_1_3FC58(void);
void fn_1_3FC68(s32 enabled);
u32 fn_1_3FC8C(void);
u8 fn_1_3FC9C(void);
void fn_1_3FCB0(s32 value);
void fn_1_3FCD4(u32 mask);
u32 fn_1_3FCF8(void);
void fn_1_3FDA8(u32 arg0, u32 arg1);
void fn_1_3FF90(void);
int fn_1_4017C(void);
int fn_1_40224(void);
s32 fn_1_402A4(u32 index);
int fn_1_402D4(void);
int fn_1_40354(void);
void fn_1_403D4(Fn40710Object *obj);
void fn_1_4068C(Fn40710Object *obj);
void fn_1_40710(Fn40710Object *obj);
void fn_1_408E8(Fn40710Object *obj);
u8 *fn_1_40B14(void);
s32 fn_1_40B20(void);
u8 fn_1_40BB4(void);
void fn_1_40BD4(void);
void fn_1_40BE4(void);
void fn_1_40D44(void);
void fn_1_40E08(u32 arg0);
u8 fn_1_40ED4(void);
u32 fn_1_40EE4(void);
u32 fn_1_40F34(void);
u8 fn_1_40F44(void);
void fn_1_40F54(void *arg0);
void fn_1_40F78(void);
void fn_1_4100C(void);
void fn_1_41048(void);
void fn_1_410A0(void);
void fn_1_41104(u32 message_index);
void fn_1_41134(void *unused, char *value);
void fn_1_411A4(u32 index);
void fn_1_411D4(u32 index, char *value);
void fn_1_412A0(u32 index);
void fn_1_41328(RelocData *data);
char *fn_1_41418(Fn41418Data *data, u32 index);
int fn_1_41488(Fn41488Data *data, const char *value);

struct RaceBuf {
    u32 unk_0;
    GameEntrant unk_4;
    u8 pad_10[0x8190];
    u8 unk_81A0;
    u8 pad_81A1[0x3];
    u8 unk_81A4;
    u8 pad_81A5[0x7];
    u8 unk_81AC;
    u8 pad_81AD[0x7];
    u8 unk_81B4;
    u8 pad_81B5[0xB];
};

struct GameCar {
    u8 pad_0[0x324];
    s32 unk_324;
    s8 unk_328;
    u8 pad_329[0x7];
    fn_1_38CF4_Part unk_330[6]; /* 0xC each, the object pointer is the last word (0x338 + k * 0xC) */
    u8 pad_378[4];
    void *unk_37C[4];
    u8 pad_38C[4];
    u32 unk_390;
    u8 pad_394[0xC];
    void *unk_3A0;
    u8 pad_3A4[0x14];
    s16 unk_3B8;
    u8 pad_3BA[0x86];
};

/* Objects of other translation units that this file reads. */
// lbl_1_bss_7EFD8: .bss size 0x44, referenced by 22 functions, shape {'object': 121}
// object reached through lbl_1_bss_7EFD8.unk_40
typedef struct {
    u8 unk_0;  // 1 loads, 0 stores
    u8 pad_1[0x97];
    u32 unk_98;  // 1 loads, 1 stores
    u32 unk_9C;  // 1 loads, 1 stores
    u16 unk_A0;  // 5 loads, 4 stores
    u16 unk_A2;  // 1 loads, 0 stores
} Obj_1_bss_7EFD8_At40;
typedef struct {
    u32 unk_0;  // 11 loads, 8 stores
    u32 unk_4;  // 1 loads, 2 stores
    u32 unk_8;  // 2 loads, 1 stores
    u32 unk_C;  // 3 loads, 1 stores
    u32 unk_10;  // 0 loads, 2 stores
    u32 unk_14;  // 2 loads, 2 stores
    u8 unk_18;  // 1 loads, 1 stores
    u8 unk_19;  // 0 loads, 4 stores
    u8 unk_1A;  // 1 loads, 3 stores
    u8 unk_1B;  // 1 loads, 3 stores
    u8 unk_1C;  // 0 loads, 2 stores
    u8 unk_1D;  // 0 loads, 1 stores
    u8 unk_1E;  // 0 loads, 1 stores
    u8 unk_1F;  // 0 loads, 1 stores
    u8 unk_20;  // 0 loads, 3 stores
    u8 unk_21;  // 0 loads, 2 stores
    u8 unk_22;  // 0 loads, 2 stores
    u8 unk_23;  // 0 loads, 2 stores
    u8 unk_24;  // 1 loads, 1 stores
    u8 unk_25;  // 0 loads, 1 stores
    u8 unk_26;  // 0 loads, 1 stores
    u8 unk_27;  // 0 loads, 1 stores
    u32 unk_28;  // 1 loads, 0 stores
    u8 pad_2C[0xC];
    u8 unk_38;  // 1 loads, 0 stores
    u8 pad_39[0x3];
    u8 unk_3C;  // 1 loads, 0 stores
    u8 pad_3D[0x3];
    Obj_1_bss_7EFD8_At40 *unk_40;  // 50 loads, 0 stores
} Obj_1_bss_7EFD8;
// lbl_1_bss_D58: .bss size 0x18, 2 refs from game.c
typedef struct {
    u16 unk_0;  // 4 loads, 0 stores
    u16 unk_2;  // 1 loads, 0 stores
    u8 pad_4[0x4];
    u16 unk_8;  // 24 loads, 0 stores
    u16 unk_A;  // 3 loads, 0 stores
    u8 pad_C[0x4];
    u16 unk_10;  // 18 loads, 0 stores
    u16 unk_12;  // 4 loads, 0 stores
    u8 pad_14[0x4];
} Obj_1_bss_D58;
// lbl_1_data_3D544: .data size 0x10, referenced by 26 functions, shape {'object': 9}
typedef struct {
    u32 unk_0;  // 4 loads, 2 stores
    u8 pad_4[0x4];
    u8 unk_8;  // 1 loads, 0 stores
    u8 pad_9[0x7];
} Obj_1_data_3D544;
extern Obj_1_bss_7EFD8 lbl_1_bss_7EFD8;
extern u32 lbl_1_bss_7F04C;
extern Obj_1_bss_D58 lbl_1_bss_D58;
extern u8 lbl_1_data_2B144[0x18];
extern u32 lbl_1_data_3D544[4];

/* WARNING: compiler-diff device, not original code (carried from main). port is scaled in place, so MWCC indexes
   from the field's address (addi; lhzx) as retail does. With a plain lbl_1_bss_9F8[lbl_1_bss_3C20].field read
   fn_1_2C97C is 124 words off and fn_1_2EE3C 212 words off. */
static inline u16 pad_word(u16 *field, s32 port) {
    port *= sizeof(PadButtons) / sizeof(u16);
    field += port;
    return *field;
}
#define PAD(field) pad_word(&lbl_1_bss_9F8[0].field, lbl_1_bss_3C20)

extern u8 lbl_1_data_644B;

/* TU A .rodata starts with this constant (BD8). fn_1_2C97C and fn_1_3A330 copy it. */
static const GXColor lbl_1_rodata_BD8 = {0xFF, 0xFF, 0xFF, 0x00};

/* TU A .data (5730..6640): file-scope objects in retail order. String literals of the functions follow them. */
char *lbl_1_data_5778[8] = {
    "OVERTAKE", "JUMP", "ENEMYHIT", "WALLHIT", "SIDEBYSIDE", "START", "GOAL", "LAP",
};
char *lbl_1_data_5998[45] = {
    "NON", "MASTER RECV", "MASTER SEND", "SLAVE SEND", "SLAVE RECV",
    "INIT", "TEST", "TESTEND", "SETUP", "SETUP_DONE",
    "SETUP_COUNTER", "SETUP_CNT_DONE", "UNLINK", "COIN", "ENTRY_WAIT",
    "CHALLENGER", "CHALLENGER_OK", "ENTRY", "ENTRY_OK", "SINGLECHECK",
    "SINGLECHECK_OK", "COURSE", "COURSE_OK", "COURSE_DATA", "COURSE_DATA_OK",
    "MACHINE", "MACHINE_OK", "CONFIG", "CONFIG_OK", "COUNTERADJUST",
    "LINKWAIT", "LINKWAITOK", "LINKSEL", "LINKDELIVERYSTART", "LINKDELIVERY",
    "LINKDELIVERYOK", "LINKSELOK", "COURSEVIEW", "COURSEVIEW_OK", "LINKREQ",
    "LINKSTANDBY", "LINKOK", "LINK", "PAUSE", "ERROR",
};
typedef struct GameMode {
    void (*init)(void);
    void (*update)(void);
    void (*exit)(void);
    char *name;
} GameMode;

GameMode lbl_1_data_5ABC[11] = {
    {NULL, NULL, NULL, NULL},
    {fn_1_382C4, fn_1_384E8, fn_1_385A4, "course_intro"},
    {fn_1_3867C, fn_1_38BBC, fn_1_38CF4, "customize"},
    {fn_1_3908C, fn_1_391F0, fn_1_39420, "course_view"},
    {fn_1_395CC, fn_1_39C60, fn_1_3A044, "race_start"},
    {fn_1_3A2C4, fn_1_3A330, fn_1_3AEC4, "race"},
    {fn_1_3B11C, fn_1_3B7D4, fn_1_3C880, "race_result"},
    {fn_1_3CDB0, fn_1_3CE94, fn_1_3DB9C, "fail_result"},
    {fn_1_3E628, fn_1_3E62C, fn_1_3E66C, "pilotpoint"},
    {fn_1_3DDAC, fn_1_3DE80, fn_1_3E5D0, "over"},
    {fn_1_3E670, fn_1_3E6D8, fn_1_3EA70, "ticket"},
};
f32 lbl_1_data_5B6C = 320.0f;
f32 lbl_1_data_5B70 = 160.0f;
f32 lbl_1_data_5B74 = 320.0f;
f32 lbl_1_data_5B78 = 280.0f;
u8 lbl_1_data_5B7C = 1;
s32 lbl_1_data_5B80 = -1;
u8 lbl_1_data_5B84 = 1;
s16 lbl_1_data_5B86 = -1;
s32 lbl_1_data_5B88 = -1;
s32 lbl_1_data_5B8C[2] = {-1, -1};
char *lbl_1_data_5BF8[6] = {
    "This replay and ghost\n cannot be saved.",
    "This replay cannot be saved.",
    "This ghost cannot be saved.",
    "This replay and ghost\n cannot be saved.",
    "This replay cannot be saved.",
    "This ghost cannot be saved.",
};
char *lbl_1_data_5C68 = "New parts have just arrived!\n/bc00ffff/%s/bcffffff/\nYou can purchase them in the shop.";
char *lbl_1_data_5CBC = "Machine\n/bc00ffff/%s/bcffffff/\nhas arrived.\nYou can purchase it at the shop.";
char *lbl_1_data_5D18 = "/bc00ffff/%s/bcffffff/\nStaff Ghosts have arrived.\nYou can purchase them at the shop.";
char *lbl_1_data_5D74 = "/bc00ffff/%s/bcffffff/\narcade courses have arrived.\nYou can purchase them at the shop.";
char *lbl_1_data_5DC4 = "Story\n/bc00ffff/%s/bcffffff/\nhas arrived.\nYou can purchase it at the shop.";
char *lbl_1_data_5E18 = "/bc00ffff/%s/bcffffff/\nsounds have arrived.\nYou can purchase them at the shop.";
char *lbl_1_data_5E38 = "You acquired %d Tickets.";
char *lbl_1_data_5ED0[14] = {
    "Continue",
    "Proceed to Next",
    "Proceed to Next",
    "Retry",
    "Mission Display",
    "Settings",
    "Select Course",
    "Replay",
    "Save Replay",
    "Save Ghost",
    "Status",
    "Force Win",
    "Reset",
    "Quit",
};
/* Unknown retail object: .data 5F08 = 01 00 00 00. No retail code reads it (fn_1_2EBB8 only forms the end address of
   lbl_1_data_5ED0, which equals 5F08). Type assumed u8. */
u8 lbl_1_data_5F08 = 1;

/* TU A .bss (3C00..38450): the unit owns these objects (address order) */
u8 lbl_1_bss_3C00 = 0;
u32 lbl_1_bss_3C04 = 0;
u32 lbl_1_bss_3C08 = 0;
s32 lbl_1_bss_3C0C = 0;
u8 lbl_1_bss_3C10 = 0;
u8 lbl_1_bss_3C11 = 0;
u8 lbl_1_bss_3C12 = 0;
u32 lbl_1_bss_3C14 = 0;
u32 lbl_1_bss_3C18 = 0;
void *lbl_1_bss_3C1C = 0;
u8 lbl_1_bss_3C20 = 0;
u32 lbl_1_bss_3C24 = 0;
/* Unknown retail object: .bss 3C28, 2 bytes. No function of this file reads it. Type assumed u16. */
u16 lbl_1_bss_3C28 = 0;
s16 lbl_1_bss_3C2A;
Obj3C30 lbl_1_bss_3C30;
s16 lbl_1_bss_50E8;
u16 lbl_1_bss_50EC[4];
u8 lbl_1_bss_50F4;
s32 lbl_1_bss_50F8;
s16 lbl_1_bss_50FC;
extern u32 lbl_1_bss_5100;
extern s8 lbl_1_bss_5104;
Fn40710Object lbl_1_bss_5108;
Obj5138 lbl_1_bss_5138;
u8 lbl_1_bss_5224;
u32 lbl_1_bss_5228;
u32 lbl_1_bss_522C;
char *lbl_1_bss_5230;
u8 lbl_1_bss_5234;
u32 lbl_1_bss_5238;
u8 lbl_1_bss_523C[0x20];
GameSlotTable lbl_1_bss_525C;
s16 lbl_1_bss_53F4;
GameEntrant *lbl_1_bss_53F8[0x22];
RaceBuf lbl_1_bss_5480[4];
extern u16 lbl_1_bss_25B80;
s32 lbl_1_bss_25B84;
u32 lbl_1_bss_25B88;
u16 *lbl_1_bss_25B8C;
s32 lbl_1_bss_25B90;
u32 lbl_1_bss_25B94;
extern u16 lbl_1_bss_25B98;
s32 lbl_1_bss_25B9C;
extern s32 lbl_1_bss_25BA0;
extern s32 lbl_1_bss_25BA4;
u8 lbl_1_bss_25BA8[30];
u8 lbl_1_bss_25BC8[30];
u16 lbl_1_bss_25BE6;
u16 lbl_1_bss_25BE8;
u8 lbl_1_bss_25BEA;
s32 lbl_1_bss_25BEC;
s32 lbl_1_bss_25BF0;
s32 lbl_1_bss_25BF4;
f32 lbl_1_bss_25BF8;
f32 lbl_1_bss_25BFC;
GXColor lbl_1_bss_25C00[0xA];
GXColor lbl_1_bss_25C28[2];
f32 lbl_1_bss_25C30;
f32 lbl_1_bss_25C34;
s32 lbl_1_bss_25C38;
char *lbl_1_bss_25C3C;
Fn40710Object *lbl_1_bss_25C40;
s32 lbl_1_bss_25C44;
s16 lbl_1_bss_25C48[30];
u32 lbl_1_bss_25C84[8];
u32 lbl_1_bss_25CA4;
s32 lbl_1_bss_25CA8;
s32 lbl_1_bss_25CAC;
s32 lbl_1_bss_25CB0;
s32 lbl_1_bss_25CB4;
s32 lbl_1_bss_25CB8;
s32 lbl_1_bss_25CBC;
s32 lbl_1_bss_25CC0;
s32 lbl_1_bss_25CC4;
s32 lbl_1_bss_25CC8;
u32 lbl_1_bss_25CCC;
BurnerSlot *lbl_1_bss_25CD0;
BurnerSlot lbl_1_bss_25CD4;
s32 lbl_1_bss_25E54;
s32 lbl_1_bss_25E58;
s32 lbl_1_bss_25E5C;
s32 lbl_1_bss_25E60;
s32 lbl_1_bss_25E64;
u32 lbl_1_bss_25E68;
s32 lbl_1_bss_25E6C;
s32 lbl_1_bss_25E70;
void (*lbl_1_bss_25E74)(struct Obj3C30 *);
extern s32 lbl_1_bss_25E78;
extern s32 lbl_1_bss_25E7C;
extern s32 lbl_1_bss_25E80;
extern s32 lbl_1_bss_25E84;
extern s32 lbl_1_bss_25E88;
extern s32 lbl_1_bss_25E8C;
extern u8 lbl_1_bss_25E90;
extern s32 lbl_1_bss_25E94;
u8 lbl_1_bss_25E98[4];
GameEntry lbl_1_bss_25E9C[30];
s8 lbl_1_bss_2625C[0x20];
u32 lbl_1_bss_2627C[30];
u8 lbl_1_bss_262F4;
u32 lbl_1_bss_262F8;
u8 lbl_1_bss_262FC[4];
s16 lbl_1_bss_26300;
f32 lbl_1_bss_26304[4];
GameRaceRecord lbl_1_bss_26314[4];
u8 lbl_1_bss_26B04[4];
u32 lbl_1_bss_26B08;
u32 lbl_1_bss_26B0C;
u32 lbl_1_bss_26B10;
s32 lbl_1_bss_26B14;
u8 lbl_1_bss_26B18;
u8 lbl_1_bss_26B19;
u8 lbl_1_bss_26B1A;
u8 lbl_1_bss_26B1B;
u8 lbl_1_bss_26B1C;
u8 lbl_1_bss_26B1D;
u8 lbl_1_bss_26B1E;
u8 lbl_1_bss_26B20[30];
f32 lbl_1_bss_26B40;
f32 lbl_1_bss_26B44;
s32 lbl_1_bss_26B48;
extern u32 lbl_1_bss_26B4C;
s32 lbl_1_bss_26B50;
u8 lbl_1_bss_26B54[4];
u32 lbl_1_bss_26B58;
s8 lbl_1_bss_26B5C[0x1E];
s16 lbl_1_bss_26B7A;
extern u8 lbl_1_bss_26B7C;
u8 lbl_1_bss_26B80[30][5];
extern s8 lbl_1_bss_26C16;
extern u32 lbl_1_bss_26C18;
s32 lbl_1_bss_26C1C;
u32 lbl_1_bss_26C20;
u8 lbl_1_bss_26C24;
extern s32 lbl_1_bss_26C28;
s32 lbl_1_bss_26C2C;
u32 lbl_1_bss_26C30;
u32 lbl_1_bss_26C34;
u32 lbl_1_bss_26C38;
u32 lbl_1_bss_26C3C;
u32 lbl_1_bss_26C40;
u32 lbl_1_bss_26C44;
f32 lbl_1_bss_26C48;
f32 lbl_1_bss_26C4C;
f32 lbl_1_bss_26C50;
f32 lbl_1_bss_26C54;
u8 lbl_1_bss_26C58;
s32 lbl_1_bss_26C5C;
void (*lbl_1_bss_26C60)(void);
void (*lbl_1_bss_26C64)(Obj3C30 *gs);
u16 lbl_1_bss_26C68;
extern u8 lbl_1_bss_26C6A;
s32 lbl_1_bss_26C6C;
GameLink lbl_1_bss_26C70;
GameLinkSlot lbl_1_bss_26CD8[4];
u8 lbl_1_bss_26D48[0x1380];
u8 lbl_1_bss_280C8[0x2718];
GameCar lbl_1_bss_2A7E0[41];
GameCarData lbl_1_bss_35620[4];
u8 lbl_1_bss_37EA0[0x190];
u8 lbl_1_bss_38030[0x190];
s32 lbl_1_bss_381C0[4];
s32 lbl_1_bss_381D0[8];
s32 lbl_1_bss_381F0;
u8 lbl_1_bss_381F4;
u8 lbl_1_bss_381F5;
u32 lbl_1_bss_381F8;
u32 lbl_1_bss_381FC;
u8 lbl_1_bss_38200;
u16 lbl_1_bss_38204[4];
u8 lbl_1_bss_3820C;
u32 lbl_1_bss_38210;
u32 lbl_1_bss_38214;
u8 lbl_1_bss_38218[0x238];

/* fzgx:begin fn_1_2C768 */
/* WARNING: compiler-diff device, not original code (NEW, not on main, owner accepted 2026-11-23).
 * A function that no retail code calls. It holds four debug strings and it must be the first function of the file.
 * Retail evidence: (1) .data 0x5F0C..0x5F5B holds these four strings before the first string of fn_1_2C97C, and no
 * retail code reads them. (2) MWCC numbers the pool base registers of a function by the order in which the file first
 * used each pool with base addressing (three or more objects of the section in one function). Retail's order is
 * .data, .bss, .rodata, so a function before fn_1_2C908 used the .data pool. Without it fn_1_2D524 is 16 words off
 * and every function with two pool bases has them in the wrong registers.
 * The retail linker removed that function, so its body is not known. An `if (0)` print, an empty inline stub with
 * fixed arguments and a bare string statement emit no string. Only a real call keeps the strings. */
static inline void game_debug_printf(char *format, ...) {
}

static void game_debug_scenario(s32 cup) {
    game_debug_printf("Clear Scenario8\n");
    game_debug_printf("Not get Scenario9 yet\n");
    game_debug_printf("Not Cleared cup %d\n", cup);
    game_debug_printf("get scenario 9\n");
}

void fn_1_2C768(u32 *arg0) {
    if (lbl_1_bss_3C2A != 0x29 || (lbl_1_bss_3C30.unk_0 & 0x800)) {
        return;
    }
    if (lbl_1_bss_3C30.unk_5 == 2 && *arg0 != lbl_1_bss_3C30.unk_1474) {
        lbl_1_bss_3C30.unk_5 = 6;
    }
    *arg0 += 1;
}
/* fzgx:end fn_1_2C768 */

/* fzgx:begin fn_1_2C7C4 */
void fn_1_2C7C4(u8 *value, const u8 *target, int step) {
    if (value[0] != target[0]) {
        if (value[0] > target[0]) {
            if (value[0] > target[0] + step) {
                value[0] -= step;
            } else {
                value[0] = target[0];
            }
        } else {
            if (value[0] < target[0] - step) {
                value[0] += step;
            } else {
                value[0] = target[0];
            }
        }
    }
    if (value[1] != target[1]) {
        if (value[1] > target[1]) {
            if (value[1] > target[1] + step) {
                value[1] -= step;
            } else {
                value[1] = target[1];
            }
        } else {
            if (value[1] < target[1] - step) {
                value[1] += step;
            } else {
                value[1] = target[1];
            }
        }
    }
    if (value[2] != target[2]) {
        if (value[2] > target[2]) {
            if (value[2] > target[2] + step) {
                value[2] -= step;
            } else {
                value[2] = target[2];
            }
        } else {
            if (value[2] < target[2] - step) {
                value[2] += step;
            } else {
                value[2] = target[2];
            }
        }
    }
    if (value[3] != target[3]) {
        if (value[3] > target[3]) {
            if (value[3] > target[3] + step) {
                value[3] -= step;
            } else {
                value[3] = target[3];
            }
        } else {
            if (value[3] < target[3] - step) {
                value[3] += step;
            } else {
                value[3] = target[3];
            }
        }
    }
}
/* fzgx:end fn_1_2C7C4 */

/* fzgx:begin fn_1_2C908 */
u32 fn_1_2C908(void) {
    u32 result = fn_1_4C10();
    if ((s32)result == 0) {
        lbl_1_bss_50E8 = 42;
        lbl_1_bss_3C30.unk_0 |= 0x1000;
        lbl_1_bss_50EC[0] = 0;
        lbl_1_bss_50F4 |= 1;
        lbl_1_bss_50F8 = 0;
        lbl_1_bss_50FC = 0;
        fn_1_EB080(4);
        result = fn_1_4060();
    }
    return result;
}
/* fzgx:end fn_1_2C908 */

/* fzgx:begin fn_1_2C97C */
u32 lbl_1_bss_5100 = 0;
s8 lbl_1_bss_5104 = 0;

s32 fn_1_2C97C(void) {
    s32 cancel;
    s32 confirm;
    u16 pressed;
    s16 i;

    if (fn_1_4C10() != 0) {
        return 4;
    }
    if (lbl_1_bss_5108.flags & 1) {
        if ((PAD(unk_10) & 1) || (PAD(unk_12) & 1)) {
            lbl_1_bss_5108.enabled = 0;
        } else if (((PAD(unk_10) >> 1) & 1) || ((PAD(unk_12) >> 1) & 1)) {
            lbl_1_bss_5108.enabled = 1;
        } else {
            pressed = PAD(unk_8);
            cancel = 0;
            confirm = 0;
            if (((pressed >> 9) & 1) || ((pressed >> 12) & 1)) {
                cancel = 1;
            } else if ((pressed >> 8) & 1) {
                if (lbl_1_bss_5108.enabled == 0) {
                    confirm = 1;
                } else {
                    cancel = 1;
                }
            }
            if (cancel || confirm) {
                if (cancel) {
                    lbl_1_bss_5108.flags |= 4;
                } else if (confirm) {
                    lbl_1_bss_5108.flags |= 2;
                    if (lbl_1_bss_3C2A == 0x29) {
                        fn_1_435C(lbl_1_bss_5100);
                        fn_1_3F8C("replay_exit_gap", fn_1_2C908, 0, 0xD);
                        {
                            GXColor color = lbl_1_rodata_BD8;

                            fn_1_49F0(&color);
                        }
                        if (lbl_1_bss_3C10 != 0) {
                            fn_1_4A00(0, 0x78, lbl_1_bss_5100);
                        } else {
                            fn_1_4A00(0, 0x1E, lbl_1_bss_5100);
                        }
                        if (lbl_1_bss_3C30.unk_5 == 1) {
                            fn_1_86254(0)->unk_475 = 0;
                            for (i = 1; i < fn_1_86624(); i++) {
                                fn_1_86254(i)->unk_475 = -1;
                            }
                        }
                    }
                }
                lbl_1_bss_3C30.unk_C4 = NULL;
                lbl_1_bss_5104 = -1;
            }
            fn_1_40710(&lbl_1_bss_5108);
        }
        return 4;
    }
    return 0;
}
/* fzgx:end fn_1_2C97C */

/* fzgx:begin fn_1_2CBAC */
/* fn_1_2CBAC: block-private types (p0b) */
/* Obj3C30: see Obj3C30 */

static inline int fn_1_2CBAC_active(void) {
    if (lbl_1_bss_3C30.unk_5 != 1) {
        return 0;
    }
    if (lbl_1_bss_3C30.unk_A7 < 4) {
        return 0;
    }
    return 1;
}

static inline void fn_1_2CBAC_clear(u8 cup, u8 diff, u8 course) {
    fn_1_FA154(cup, diff);
    if (fn_1_4017C()) {
        fn_1_FA038();
    }
    if (cup == 2 && fn_1_40224()) {
        fn_1_F9FB4();
    }
    if (cup == 3) {
        fn_1_FA67C(course);
    }
    if (diff + 1 == 5 && !fn_1_F8A38(0)) {
        lbl_1_bss_5138.unk_E6[lbl_1_bss_5138.unk_E4++] = 0;
    }
}

static inline void fn_1_2CBAC_bonus(Obj5138 *p, s16 rank, s16 cup, s16 diff) {
    s32 i;
    s32 j;
    s32 level;
    s32 count;
    s32 found;
    const u16 *entry;
    u16 id;

    level = 1;
    if (rank == 0) {
        if (cup == 0) {
            level = 2;
        } else if (cup == 1) {
            level = 4;
        } else {
            for (i = 0; i < 3; i++) {
                int a = fn_1_FA180(2, i);
                int b = fn_1_FA180(3, i);
                if (diff != i && !a && !b) {
                    break;
                }
            }
            if (i == 3) {
                level = 5;
            } else {
                level = 4;
            }
        }
    } else if (cup > 0) {
        level = 2;
    }
    found = 0;
    for (count = level; count > 0; count--) {
        if (level == 2 && rank == 0 && count == level) {
            entry = lbl_1_rodata_DD34[2];
        } else {
            entry = lbl_1_rodata_DD34[count - 1];
        }
        for (j = 0; j < 3; j++) {
            id = entry[j];
            if (!fn_1_F8334(id)) {
                found = 1;
                lbl_1_bss_5138.unk_8[p->unk_2++] = id;
                if (count != 5) {
                    break;
                }
            }
        }
        if (found) {
            break;
        }
    }
}

static inline s32 fn_1_2CBAC_pick(Obj5138 *p) {
    s32 i;
    s32 found;

    found = 0;
    for (i = 0; i < 3; i++) {
        s16 v = lbl_1_rodata_DD2C[i];
        if (!fn_1_F8334(v)) {
            found = 1;
            lbl_1_bss_5138.unk_8[p->unk_2++] = v;
        }
    }
    return found;
}

static inline void fn_1_2CBAC_unlock(void) {
    s32 i;

    for (i = 1; i < 6; i++) {
        fn_1_12EF24(6, i);
        if (!fn_1_F8A38(i)) {
            lbl_1_bss_5138.unk_E6[lbl_1_bss_5138.unk_E4] = i;
            lbl_1_bss_5138.unk_E4++;
        }
    }
    lbl_1_bss_5138.unk_EB = 1;
}

/* WARNING: compiler-diff device, not original code (carried from main): opt_dead_assignments off keeps the two
   dead stores marked below until register allocation (174 words without it). */
#pragma opt_dead_assignments off

void fn_1_2CBAC(void) {
    Obj5138 *p;
    s32 i;
    s32 count;
    s32 found;
    s32 rank;
    s32 cup;
    s32 diff;
    s32 n;
    s32 id;
    s32 all;
    Obj3C30 *g;
    const u16 (*row)[2];

    g = &lbl_1_bss_3C30;
    if (!fn_1_2CBAC_active()) {
        return;
    }
    found = 0;
    cup = fn_1_3FC9C();
    diff = lbl_1_bss_3C30.unk_A6 - 1;
    fn_1_3F2A0();
    rank = g->unk_D4[0].unk_8;
    if (rank == 0) {
        fn_1_2CBAC_clear(cup, diff, g->unk_D4[0].unk_82);
        n = 2;
    } else {
        n = 1;
    }
    row = lbl_1_rodata_DCDC[cup];
    p = &lbl_1_bss_5138;
    for (count = n; count > 0; count--) {
        id = row[diff][count - 1];
        /* WARNING: compiler-diff device, not original code: dead store. i is overwritten before any read. It keeps an unused n * 2
         * alive until register allocation (opt_dead_assignments off), whose deletion of it
         * makes MWCC reschedule the loop setup into retail's order (n * 2 before diff * 4). */
        i = (s16)((u32)n * 2);
        if (id == 0xFFFE) {
            found = fn_1_2CBAC_pick(p);
            if (found) {
                break;
            }
        } else if (id != 0xFFFF) {
            if (!fn_1_F7EDC(id)) {
                u8 k = p->unk_3++;
                found = 1;
                lbl_1_bss_5138.unk_4[k] = id;
                break;
            }
        }
    }
    /* WARNING: compiler-diff device, not original code: dead store. i = 0 is never read; it survives until register allocation and
     * its deletion there leaves retail's second compare of found in place. */
    if (found) {
        i = 0;
    }
    if (!found) {
        fn_1_2CBAC_bonus(p, rank, cup, diff);
    }
    if (rank == 0) {
        i = 0;
    } else if (rank == 1) {
        i = 1;
    } else if (rank == 2) {
        i = 2;
    } else if (rank < 9) {
        i = 3;
    } else if (rank < 19) {
        i = 4;
    } else {
        i = 5;
    }
    lbl_1_bss_5138.unk_0 = lbl_1_rodata_DBE4[cup][diff][i];
    if (cup == 3) {
        all = 1;
        for (i = 0; i < 4; i++) {
            if (!fn_1_FA180(3, i)) {
                all = 0;
            }
        }
        if (all) {
            fn_1_2CBAC_unlock();
        }
    }
}

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_2CBAC */

/* fzgx:begin fn_1_2D038 */
static void game_message_box_reset(void) {
    fn_80008BEC(&lbl_1_bss_5138, 0, 0xec);
    lbl_1_bss_5138.unk_10 = 320;
    lbl_1_bss_5138.unk_12 = 180;
    lbl_1_bss_5138.unk_E1 = 0;
    lbl_1_bss_5138.unk_E0 = 0;
    lbl_1_bss_5138.unk_0 = 0;
    lbl_1_bss_5138.unk_2 = 0;
    lbl_1_bss_5138.unk_3 = 0;
    lbl_1_bss_5138.unk_1C = 0.0f;
    lbl_1_bss_5138.unk_20[0] = 0;
    lbl_1_bss_5138.unk_E2 = 0;
    lbl_1_bss_5138.unk_E3 = 0xff;
    lbl_1_bss_5138.unk_E4 = 0;
    lbl_1_bss_5138.unk_E5 = 0xff;
    lbl_1_bss_5138.unk_EB = 0xff;
}

void fn_1_2D038(void) {
    FontDrawPacket packet;
    s32 count;
    f32 alpha;
    f32 grow;
    f32 open;
    f32 height;
    f32 width;
    f32 x;
    f32 fade;
    s32 message;

    count = 0;
    message = -1;
    if (!(lbl_1_bss_3C30.unk_0 & 0x800000) || (fn_1_F45B4() != 0 && lbl_1_bss_5224 == 0)) {
        lbl_1_bss_5228 = 0;
    } else {
        if (lbl_1_bss_522C == 0) {
            count = 1;
            lbl_1_bss_5228 = 1;
        } else if ((s32)lbl_1_bss_5228 == 0 && lbl_1_bss_522C >= 180) {
            lbl_1_bss_5228 = 1;
            lbl_1_bss_522C = 0;
            lbl_1_bss_5230 = 0;
        }
        if (lbl_1_bss_522C == 0 && (s32)lbl_1_bss_5228 != 0) {
            message = 1;
        }
    }
    if (lbl_1_bss_5234 != 0 || (lbl_1_bss_3C30.unk_5 == 2 && fn_1_F22D4() != 0)) {
        if (lbl_1_bss_522C == 0) {
            count += 1;
            lbl_1_bss_5238 = 1;
        } else if ((s32)lbl_1_bss_5238 == 0 && lbl_1_bss_522C >= 180) {
            lbl_1_bss_5238 = 1;
            lbl_1_bss_522C = 0;
            lbl_1_bss_5230 = 0;
        }
        if (count == 2) {
            message = 0;
            lbl_1_bss_5230 = 0;
        } else if (lbl_1_bss_522C == 0 && (s32)lbl_1_bss_5238 != 0 && message == -1) {
            message = 2;
        }
    } else {
        lbl_1_bss_5238 = 0;
    }
    if ((s32)lbl_1_bss_5228 == 0 && (s32)lbl_1_bss_5238 == 0) {
        lbl_1_bss_522C = 0;
        lbl_1_bss_5230 = 0;
        return;
    }
    if (fn_1_EB248() != 0 || fn_1_154C84() != 0) {
        if (lbl_1_bss_522C == 0) {
            return;
        }
        if (lbl_1_bss_522C > 15) {
            lbl_1_bss_522C = 15;
        } else {
            lbl_1_bss_522C--;
        }
    } else if (lbl_1_bss_3C2A >= 0x2A) {
        if (lbl_1_bss_8E51D == 10) {
            if (lbl_1_bss_522C == 0) {
                message += 3;
            }
            lbl_1_bss_522C += lbl_1_bss_522C < 60;
        } else {
            lbl_1_bss_522C = 0;
            return;
        }
    } else {
        lbl_1_bss_522C = 0;
        lbl_1_bss_5230 = 0;
        return;
    }
    if (lbl_1_bss_522C < 15) {
        alpha = lbl_1_bss_522C / 15.0f;
    } else if (lbl_1_bss_522C > 165) {
        alpha = 1.0f - (lbl_1_bss_522C - 165) / 15.0f;
    } else {
        alpha = 1.0f;
    }
    grow = 10.0f * alpha;
    if (grow > 1.0f) {
        grow = 1.0f;
    }
    open = 1.25f * (alpha - 0.1f);
    if (open < 0.0f) {
        open = 0.0f;
    }
    fade = 10.0f * (alpha - 0.9f);
    if (fade < 0.0f) {
        fade = 0.0f;
    }
    fn_1_49410();
    fn_1_495FC();
    fn_1_4954C(0.0006f);
    fn_1_49590(0.4f);
    fn_1_4955C(0.75f, 0.75f);
    fn_1_495C8(1);
    fn_1_495A0(fade);
    fn_1_495B0(0x80000000);
    if (lbl_1_bss_5230 == 0) {
        lbl_1_bss_5230 = fn_1_15BA78(lbl_1_data_5BF8[message]);
    }
    width = fn_1_4B068(lbl_1_bss_5230);
    height = fn_1_4B090(lbl_1_bss_5230);
    x = 70.0f + width / 2.0f;
    fn_1_496FC(x, 36.0f);
    fn_1_4A0D8(lbl_1_bss_5230);
    packet = lbl_1_rodata_26F8;
    packet.x = x;
    packet.y = 16.0f + 0.5f * (45.0f + height);
    packet.z = 0.0008f;
    packet.flags = 0xA;
    packet.alpha = alpha;
    packet.image = 2;
    fn_1_50A90(&packet, (s32)(18.0f * grow), (s32)(45.0f * grow), (s32)((50.0f + width) * open),
               (s32)((45.0f + height) * open));
}
/* fzgx:end fn_1_2D038 */

/* fzgx:begin fn_1_2D524 */
void fn_1_2D524(Obj5138 *arg0) {
    u8 v0;
    u16 v8;
    u32 t0;
    char *s;
    u32 t32;
    char buf30[0x40];
    char buf10[0x20];

    v0 = arg0->unk_E1;
    if (v0 == 0) {
        t0 = fn_1_F8D10();
        sprintf(arg0->unk_20, fn_1_15BA78(lbl_1_data_5E38), arg0->unk_0);
        fn_1_F8D38(t0 + arg0->unk_0);
        arg0->unk_0 = 0;
    } else if (v0 == 1) {
        s = lbl_1_data_2BD54[arg0->unk_E3][lbl_801A66B4];
        sprintf(arg0->unk_20, fn_1_15BA78(lbl_1_data_5D18), s);
        fn_1_F2008(lbl_1_bss_3C30.unk_6);
    } else if (v0 == 2) {
        char *tbl[10][5] = {
            {"/bc7fffff/Prologue/bcffffff/     Black Shadow's Disgrace", "/bc7fffff/Prologue/bcffffff/     Black Shadow's Disgrace", "/bc7fffff/Prologue/bcffffff/     Black Shadow's Disgrace", "/bc7fffff/Prologue/bcffffff/     Black Shadow's Disgrace", "/bc7fffff/Prologue/bcffffff/     Black Shadow's Disgrace"},
            {"/bc7fffff/Chapter 1/bcffffff/     Captain Falcon Trains", "/bc7fffff/Chapter 1/bcffffff/     Captain Falcon Trains", "/bc7fffff/Chapter 1/bcffffff/     Captain Falcon Trains", "/bc7fffff/Chapter 1/bcffffff/     Captain Falcon Trains", "/bc7fffff/Chapter 1/bcffffff/     Captain Falcon Trains"},
            {"/bc7fffff/Chapter 2/bcffffff/     Goroh: The Vengeful Samurai", "/bc7fffff/Chapter 2/bcffffff/     Goroh: The Vengeful Samurai", "/bc7fffff/Chapter 2/bcffffff/     Goroh: The Vengeful Samurai", "/bc7fffff/Chapter 2/bcffffff/     Goroh: The Vengeful Samurai", "/bc7fffff/Chapter 2/bcffffff/     Goroh: The Vengeful Samurai"},
            {"/bc7fffff/Chapter 3/bcffffff/     High Stakes in Mute City", "/bc7fffff/Chapter 3/bcffffff/     High Stakes in Mute City", "/bc7fffff/Chapter 3/bcffffff/     High Stakes in Mute City", "/bc7fffff/Chapter 3/bcffffff/     High Stakes in Mute City", "/bc7fffff/Chapter 3/bcffffff/     High Stakes in Mute City"},
            {"/bc7fffff/Chapter 4/bcffffff/     Challenge of the Bloody Chain", "/bc7fffff/Chapter 4/bcffffff/     Challenge of the Bloody Chain", "/bc7fffff/Chapter 4/bcffffff/     Challenge of the Bloody Chain", "/bc7fffff/Chapter 4/bcffffff/     Challenge of the Bloody Chain", "/bc7fffff/Chapter 4/bcffffff/     Challenge of the Bloody Chain"},
            {"/bc7fffff/Chapter 5/bcffffff/     Save Jody!", "/bc7fffff/Chapter 5/bcffffff/     Save Jody!", "/bc7fffff/Chapter 5/bcffffff/     Save Jody!", "/bc7fffff/Chapter 5/bcffffff/     Save Jody!", "/bc7fffff/Chapter 5/bcffffff/     Save Jody!"},
            {"/bc7fffff/Chapter 6/bcffffff/     Black Shadow's Trap", "/bc7fffff/Chapter 6/bcffffff/     Black Shadow's Trap", "/bc7fffff/Chapter 6/bcffffff/     Black Shadow's Trap", "/bc7fffff/Chapter 6/bcffffff/     Black Shadow's Trap", "/bc7fffff/Chapter 6/bcffffff/     Black Shadow's Trap"},
            {"/bc7fffff/Chapter 7/bcffffff/     The F-ZERO Grand Prix", "/bc7fffff/Chapter 7/bcffffff/     The F-ZERO Grand Prix", "/bc7fffff/Chapter 7/bcffffff/     The F-ZERO Grand Prix", "/bc7fffff/Chapter 7/bcffffff/     The F-ZERO Grand Prix", "/bc7fffff/Chapter 7/bcffffff/     The F-ZERO Grand Prix"},
            {"/bc7fffff/Chapter 8/bcffffff/     Secrets of the Champion Belt", "/bc7fffff/Chapter 8/bcffffff/     Secrets of the Champion Belt", "/bc7fffff/Chapter 8/bcffffff/     Secrets of the Champion Belt", "/bc7fffff/Chapter 8/bcffffff/     Secrets of the Champion Belt", "/bc7fffff/Chapter 8/bcffffff/     Secrets of the Champion Belt"},
            {"/bc7fffff/Chapter 9/bcffffff/     Finale: Enter the Creators", "/bc7fffff/Chapter 9/bcffffff/     Finale: Enter the Creators", "/bc7fffff/Chapter 9/bcffffff/     Finale: Enter the Creators", "/bc7fffff/Chapter 9/bcffffff/     Finale: Enter the Creators", "/bc7fffff/Chapter 9/bcffffff/     Finale: Enter the Creators"},
        };

        sprintf(arg0->unk_20, fn_1_15BA78(lbl_1_data_5DC4), tbl[arg0->unk_E5 & 0xF][lbl_801A66B4]);
        fn_1_F9D68(arg0->unk_E5 & 0xF);
        fn_1_F9DE8(arg0->unk_E5 & 0xF);
    } else if (v0 == 3) {
        char *t2[2] = {"Mute City", "Big Blue"};

        s = fn_1_15BA78(t2[arg0->unk_EB]);
        sprintf(arg0->unk_20, fn_1_15BA78(lbl_1_data_5E18), s);
        fn_1_F8C00(arg0->unk_EB);
    } else {
        v8 = v0 - 4;
        if (v8 < arg0->unk_3) {
            fn_1_7F49C(arg0->unk_4[v8], lbl_801A66B4, buf10);
            sprintf(arg0->unk_20, fn_1_15BA78(lbl_1_data_5CBC), buf10);
            fn_1_F7F48(arg0->unk_4[v8]);
        } else if (v8 < arg0->unk_3 + arg0->unk_2) {
            v8 -= arg0->unk_3;
            fn_1_14EA74(arg0->unk_8[v8], buf30, lbl_801A66B4);
            sprintf(arg0->unk_20, fn_1_15BA78(lbl_1_data_5C68), buf30);
            fn_1_F83F0(arg0->unk_8[v8]);
        } else {
            v8 -= arg0->unk_3 + arg0->unk_2;
            s = lbl_1_data_2BD54[fn_1_12EF24(6, arg0->unk_E6[v8])][lbl_801A66B4];
            sprintf(arg0->unk_20, fn_1_15BA78(lbl_1_data_5D74), s);
            fn_1_F8A58(arg0->unk_E6[v8]);
        }
    }
    fn_1_49410();
    fn_1_4955C(0.8f, 0.8f);
    fn_1_49590(0.4f);
    fn_1_495B0(0x80000000);
    fn_1_495C8(1);
    t32 = fn_1_4AEC0(1);
    arg0->unk_14 = 80.0f + fn_1_4B068(arg0->unk_20);
    arg0->unk_18 = 60.0f + fn_1_4B090(arg0->unk_20);
    fn_1_4AEC0(t32);
    fn_1_A2DC4(0xA9011700);
}
/* fzgx:end fn_1_2D524 */

/* fzgx:begin fn_1_2D888 */
void fn_1_2D888(Obj5138 *box) {
    f32 fade;
    f32 scale;
    f32 alpha;
    u32 saved;
    u32 w;
    u32 h;
    FontDrawPacket text;

    if (box->unk_E2 == 0) {
        fn_1_4060();
        return;
    }

    fade = 10.0f * box->unk_1C;
    if (fade > 1.0f) {
        fade = 1.0f;
    }
    scale = 1.25f * (box->unk_1C - 0.1f);
    if (scale < 0.0f) {
        scale = 0.0f;
    }
    alpha = 10.0f * (box->unk_1C - 0.9f);
    if (alpha < 0.0f) {
        alpha = 0.0f;
    }

    fn_1_49410();
    fn_1_495FC();
    fn_1_4954C(0.0006f);
    fn_1_495C8(1);
    fn_1_495B0(0x80000000);
    fn_1_49590(0.4f);
    fn_1_495A0(alpha);
    fn_1_4955C(0.8f, 0.8f);
    fn_1_496FC(box->unk_10, box->unk_12);
    saved = fn_1_4AEE8(0);
    fn_1_4AF10(box->unk_20);
    fn_1_4AEE8(saved);
    fn_1_496FC(box->unk_10, box->unk_12 + box->unk_18 - 45.0f);
    fn_1_4955C(1.0f, 1.0f);
    fn_1_4A0D8("\x83\x9F");

    w = box->unk_14 * scale;
    h = box->unk_18 * scale;
    text = lbl_1_rodata_26F8;
    text.x = box->unk_10;
    text.y = (box->unk_12 - 10) + (f32)(0.5f * box->unk_18);
    text.z = 0.0008f;
    text.flags = 10;
    text.alpha = box->unk_1C;
    text.image = 2;
    fn_1_50A90(&text, 18.0f * fade, 45.0f * fade, w, h);
}
/* fzgx:end fn_1_2D888 */

/* fzgx:begin fn_1_2DB50 */
static inline void fn_1_2DB50_transition(Obj5138 *obj, s32 zero, u8 *threshold) {
    s32 condition;
    *threshold = obj->unk_2 + obj->unk_3 + obj->unk_E4 + 4;
    obj->unk_E0 = zero;
    obj->unk_E1++;
    if (obj->unk_E1 == 1) {
        if (obj->unk_E3 == 0xff) {
            condition = zero;
        } else if (ghost_test_record_flag0(lbl_1_bss_3C30.unk_6) != 0) {
            condition = 0;
        } else {
            condition = 1;
        }
        if (condition == 0) {
            obj->unk_E1 = 2;
        }
    }
}

void fn_1_2DB50(Obj5138 *obj) {
    s32 condition;
    u8 threshold;
    f32 v;
    f32 t;

    if (obj->unk_E0 == 0x78) {
        fn_1_A2DC4(0xA9011100);
    }
    if (++obj->unk_E0 > 0x78) {
        t = (obj->unk_E0 - 0x78);
        if (t > 15.0f) {
            fn_1_2DB50_transition(obj, 0, &threshold);
            if (obj->unk_E1 == 2) {
                if (obj->unk_E5 == 0xff) {
                    condition = 0;
                } else if (fn_1_F9D44(obj->unk_E5 & 0xf) != 0) {
                    condition = 0;
                } else {
                    condition = 1;
                }
                if (condition == 0) {
                    obj->unk_E1 = 3;
                }
            }
            if (obj->unk_E1 == 3) {
                if (obj->unk_EB == 0xff) {
                    condition = 0;
                } else if (fn_1_F8C50(obj->unk_EB) != 0) {
                    condition = 0;
                } else {
                    condition = 1;
                }
                if (condition == 0) {
                    obj->unk_E1 = 4;
                }
            }
            if (obj->unk_E1 >= threshold) {
                game_message_box_reset();
                fn_1_4060();
                return;
            }
            t = 15.0f;
            fn_1_2D524(obj);
        }
        obj->unk_1C = 1.0f - t / 15.0f;
    } else {
        v = obj->unk_E0 / 15.0f;
        obj->unk_1C = v;
        if (v > 1.0f) {
            obj->unk_1C = 1.0f;
            if (obj->unk_E0 == 0x78) {
                obj->unk_E0 = 0x77;
            }
        }
    }
}
/* fzgx:end fn_1_2DB50 */

/* fzgx:begin fn_1_2DE00 */
static void game_slot_table_fill(void)
{
    s32 k;
    GamePlayer *p;
    s32 idx;

    if (lbl_1_bss_3C30.unk_0 & 0x00400000) {
        return;
    }
    fn_1_3F2A0();
    for (k = 0; k < lbl_1_bss_3C30.unk_8; k++) {
        p = &lbl_1_bss_3C30.unk_D4[k];
        if (lbl_1_bss_3C2A <= 0x29) {
            idx = p->unk_83;
        } else {
            idx = p->unk_8;
        }
        lbl_1_bss_525C.entries[idx].unk_4 = p->unk_80;
        lbl_1_bss_525C.entries[idx].unk_6 = lbl_1_bss_523C[k];
        lbl_1_bss_525C.unk_194[idx] = k;
    }
    lbl_1_bss_525C.unk_192 = lbl_1_bss_3C30.unk_8;
    lbl_1_bss_525C.unk_191 |= 2;
    lbl_1_bss_525C.unk_190 = lbl_1_bss_3C30.unk_7;
    lbl_1_bss_3C30.unk_0 |= 0x00400000;
    lbl_1_bss_53F4 = 0xE;
}

/* WARNING: compiler-diff device, not original code (carried from main): opt_loop_invariants off. Without it the
   hoisted load of the entry count comes after the store of unk_192 instead of before it (7 words: zero in r0 / address
   in r4, retail r4 / r3 with the count in r0). */
#pragma opt_loop_invariants off

void fn_1_2DE00(s32 arg0)
{
    s32 i;
    GameRaceBuf *buf;
    s32 j;
    GameSlotEntry *e;
    GamePlayer *p;

    if (lbl_1_bss_3C30.unk_0 & 0x00400000) {
        return;
    }
    fn_1_3F2A0();
    buf = (GameRaceBuf *)lbl_1_bss_5480;
    lbl_1_bss_525C.unk_192 = 0;
    for (i = 0, j = 0; j < 30 && i < lbl_1_bss_3C30.unk_9; i++, j++) {
        p = &lbl_1_bss_3C30.unk_D4[i];
        e = &lbl_1_bss_525C.entries[p->unk_8];
        e->unk_4 = p->unk_80;
        e->unk_5 = p->unk_82;
        e->unk_6 = lbl_1_bss_523C[i];
        if (lbl_1_bss_53F8[i] != 0) {
            e->unk_0 = &buf[i];
        } else {
            e->unk_0 = NULL;
        }
    }
    p = &lbl_1_bss_3C30.unk_D4[fn_1_8623C()];
    p->unk_6 = 0;
    p->unk_6 += p->unk_13[0];
    p->unk_6 += p->unk_13[1];
    p->unk_6 += p->unk_13[2];
    p->unk_6 += p->unk_13[3];
    p->unk_6 += p->unk_13[4];
    fn_80008BA8(&lbl_1_bss_525C.player, p, sizeof(GamePlayer));
    lbl_1_bss_525C.unk_191 = 0;
    if (arg0 != 0) {
        lbl_1_bss_525C.unk_190 = lbl_1_bss_3C30.unk_7;
        lbl_1_bss_3C30.unk_0 |= 0x00400000;
    }
}

#pragma opt_loop_invariants reset
/* fzgx:end fn_1_2DE00 */

/* fzgx:begin fn_1_2DF98 */
u16 lbl_1_bss_25B80 = 0;

s32 fn_1_2DF98(void)
{
    u32 ready;
    void *saved;
    u16 *state;
    s32 count;
    s32 ch;

    lbl_1_bss_5104 = -1;
    if ((lbl_1_bss_3C30.unk_0 & 0x800800) == 0x800800) {
        lbl_1_bss_3C30.unk_C4 = 0;
        lbl_1_bss_5108.flags &= 0xFE;
    }

    if ((lbl_1_bss_6F316) != 0 && lbl_1_bss_25B84 != 0) {
        if (lbl_1_data_5B7C == 5) {
            fn_1_A1588((void *)lbl_1_bss_6EAD0.unk_0->unk_0, 0x18);
        } else {
            fn_1_A1588((void *)lbl_1_bss_6EAD0.unk_0->unk_0, 0x10);
        }
        ADXT_Stop((void *)lbl_1_bss_6EAD0.unk_0->unk_4);
        lbl_1_bss_6F316 = 0;
        if (lbl_1_data_5B7C == 1) {
            saved = (void *)fn_1_435C( (u32)(lbl_1_bss_25B88));
            fn_1_40E08(0x12C);
            fn_1_435C( (u32)(saved));
        }
    }

    ch = lbl_1_bss_3C30.unk_8;
    if (ch < 1) ch = 1;
    state = lbl_1_bss_25B8C;
    if (state == 0) return 1;
    ready = lbl_1_bss_3C30.unk_5;
    if (ready == 0) ch -= 1;
    count = lbl_1_bss_25B90;
    if (count >= ch) {
        if (*state == 0x10) {
            if (lbl_1_bss_25B84 != 0) {
                if (lbl_1_data_5B7C == 5) {
                    GXColor color = {0x00, 0x00, 0x00, 0x00};

                    fn_1_49F0(&color);
                } else {
                    GXColor color = {0xFF, 0xFF, 0xFF, 0x00};

                    fn_1_49F0(&color);
                }
            }
            fn_1_4A00(0, 0xF, lbl_1_bss_5100);
        } else if (*state == 0) {
            if (ready == 0) return count > ch;
            return 1;
        }
        lbl_1_bss_25B94 = *lbl_1_bss_25B8C;
    }
    return 0;
}
/* fzgx:end fn_1_2DF98 */

/* fzgx:begin fn_1_2E1B8 */
u16 lbl_1_bss_25B98 = 0;

void fn_1_2E1B8(void) {

    if (fn_1_4C10() == 0) {
        s32 active = lbl_1_bss_3C0C;
        lbl_1_bss_50E8 = 45;
        if (active) {
            Obj3C30 *object = &lbl_1_bss_3C30;
            u32 result;
            lbl_1_bss_25B9C = 0;
            if (object->unk_C0 != 0) {
                result = object->unk_C0(object);
                if (result & 4) (lbl_1_bss_25B9C) = 1;
                if (result & 2) fn_1_304A8();
                if (result & 1) return;
            }
            lbl_1_bss_3C0C = 0;
        }
        fn_1_4060();
    }
}
/* fzgx:end fn_1_2E1B8 */

/* fzgx:begin fn_1_2E268 */
void fn_1_2E268(void) {
    Obj3C30 *state = &lbl_1_bss_3C30;
    s32 i;
    s32 j;
    GamePlayer *player;

    for (i = 0; i < lbl_1_bss_3C30.unk_9; i++) {
        player = &lbl_1_bss_3C30.unk_D4[i];
        player->unk_4 = 0;
        player->unk_78 = 0;
        player->unk_6 = 0;
        if (lbl_1_bss_3C30.unk_5 == 0) {
            player->unk_4 = lbl_1_bss_3C30.unk_1480[i];
            player->unk_9E = lbl_1_bss_3C30.unk_1478[i];
            player->unk_83 = player->unk_8;
        } else {
            for (j = 0; j < lbl_1_bss_3C30.unk_A7; j++) {
                player->unk_4 += player->unk_9[j];
                player->unk_6 += player->unk_13[j];
                player->unk_78 += player->unk_4C[j];
            }
        }
        player->unk_E[lbl_1_bss_3C30.unk_A7] = 0xFF;
    }
    if (state->unk_A7 != 0) {
        fn_1_3F2A0();
    } else {
        for (i = 0; i < state->unk_9; i++) {
            u8 id = ((GameRaceRecord *)state->unk_2C[i])->unk_115;

            lbl_1_bss_3C30.unk_1394[id] = i;
            state->unk_D4[i].unk_8 = id;
        }
    }
}
/* fzgx:end fn_1_2E268 */

/* fzgx:begin fn_1_2E3B4 */
static void game_draw_sprite_strip(void)
{
    u32 i;
    u32 n;
    u32 value;
    f32 s;
    FontDrawPacket packet;

    packet = lbl_1_rodata_26F8;
    if (fn_1_485A8(0x94) != 0) {
        packet.image = 0x942A;
    } else if (fn_1_485A8(0x97) != 0) {
        packet.image = 0x9722;
    } else {
        return;
    }
    packet.y = 470.0f;
    value = (lbl_801A66A0 % 60) * 0x444;
    packet.flags = 13;
    packet.scale_x = 0.0625f;
    for (n = 0, i = 0; n < 16; n++, i += 0x800) {
        s = 1.0f + lbl_8006D188(value - i);
        {
            f32 dx = 10.0f * n;
            packet.x = 14.0f + dx;
        }
        packet.u0 = packet.scale_x * n;
        packet.u1 = packet.scale_x * (n + 1);
        packet.color_add[0] = 127.0f * (0.5f * s);
        packet.color_add[2] = 127.0f * (0.25f * s);
        fn_1_4F734(&packet);
    }
}

static inline s32 packed_time_difference(u32 t1, u32 t2) {
    u32 max;
    s32 ms;
    s32 min_part;
    s32 sec;

    if (t1 > t2) {
        max = t1;
        t1 = t2;
    } else {
        max = t2;
    }

    ms = (max & 0xFFF) - (t1 & 0xFFF);
    min_part = ((max >> 20) & 0xFF) - ((t1 >> 20) & 0xFF);
    sec = ((max >> 12) & 0xFF) - ((t1 >> 12) & 0xFF);

    if (ms < 0) {
        sec--;
        ms += 1000;
    }
    if (sec < 0) {
        min_part--;
        sec += 60;
    }

    return (min_part * 60 + sec) * 1000 + ms;
}

/* WARNING: compiler-diff device, not original code (carried from main): opt_dead_assignments off. Without it the
   second inlined packed_time_difference swaps registers (best natural body v/2E3B4_best_natural.c: 4 words). */
#pragma opt_dead_assignments off

void fn_1_2E3B4(GamePlayer *arg0, Racer *arg1) {
    f32 distance;
    s32 val_e;
    f32 rate;
    s32 flag;

    val_e = arg0->unk_E[lbl_1_bss_3C30.unk_A7];
    flag = arg1->unk_0 & 0x10000;
    rate = 1.0f + (f32)(0.25f * lbl_1_bss_3C30.unk_1470);
    arg0->unk_88 = 0;

    if (val_e == 0xFE || val_e == 0xFF) {
        if (lbl_1_bss_3C30.unk_5 == 2) {
            arg0->unk_88 = 100;
            arg0->unk_84 = 0;
        } else {
            arg0->unk_84 = 100;
        }
    } else {
        switch (lbl_1_bss_3C30.unk_5) {
        case 0:
            if (lbl_1_bss_3C30.unk_9 <= 4) {
                s32 unk_8 = lbl_1_bss_3C30.unk_8;
                s32 offset = 4 - unk_8;

                if (val_e == 0 && unk_8 == 2) {
                    arg0->unk_84 = 500;
                } else {
                    arg0->unk_84 = lbl_1_rodata_DB94[offset + val_e];
                }
                break;
            }
            /* fallthrough */
        case 1:
        case 6:
            arg0->unk_84 = lbl_1_rodata_DB58[val_e] * rate;
            break;
        case 2:
            if (lbl_1_bss_3C30.unk_1464 >= arg0->unk_24[lbl_1_bss_3C30.unk_A7]) {
                u32 diff = (u32)packed_time_difference(lbl_1_bss_3C30.unk_1464, arg0->unk_24[lbl_1_bss_3C30.unk_A7]) >> 1;
                diff += 1000;
                if (diff > 30000) {
                    diff = 30000;
                }
                arg0->unk_88 = diff;
            } else {
                s32 val = 850 - packed_time_difference(lbl_1_bss_3C30.unk_1464, arg0->unk_24[lbl_1_bss_3C30.unk_A7]) / 50;
                if (val < 100) {
                    val = 100;
                }
                arg0->unk_88 = val;
            }
            arg0->unk_84 = 0;
            break;
        default:
            arg0->unk_84 = 100;
            break;
        }
    }

    arg0->unk_86 = lbl_1_rodata_DB9C[arg0->unk_13[lbl_1_bss_3C30.unk_A7]];

    if (flag != 0) {
        if (arg1->unk_217 >= lbl_1_bss_3C30.unk_146C) {
            arg0->unk_8E = arg1->unk_217 - lbl_1_bss_3C30.unk_146C;
            arg0->unk_8E *= lbl_1_bss_3C30.unk_146D * 10;
            arg0->unk_8E += 500;
        } else {
            arg0->unk_8E = 0;
        }

        if (arg1->unk_D8 >= lbl_1_bss_3C30.unk_146E) {
            distance = arg1->unk_D8;
            arg0->unk_98 = (distance - lbl_1_bss_3C30.unk_146E);
            if (arg0->unk_98 > 1000) {
                arg0->unk_98 = 1000;
            }
            arg0->unk_98 *= 2;
            arg0->unk_98 += 200;
        } else {
            arg0->unk_98 = 0;
        }
        if (lbl_1_bss_3C30.unk_5 != 2) {
            arg0->unk_98 = 0;
        }

        arg0->unk_90 = 0;
        if (arg0->unk_E[lbl_1_bss_3C30.unk_A7] == 0) {
            arg0->unk_90 = (s32)(10000.0f * rate);
        }

        arg0->unk_9C = 0;
        if ((arg1->unk_58C & 1) == 0) {
            arg0->unk_9C += 1000;
        }
        if ((arg1->unk_0 & 0x80) != 0) {
            arg0->unk_9C += 500;
        }
        if (arg1->unk_6 >= 41) {
            arg0->unk_9C += 1000;
        }
        if ((arg0->unk_24[lbl_1_bss_3C30.unk_A7] & 0xFFF) == 0) {
            arg0->unk_9C += 5000;
        }
        if ((arg0->unk_24[lbl_1_bss_3C30.unk_A7] & 0xFFF) == 777) {
            arg0->unk_9C += 7777;
        }

        if (lbl_1_bss_3C30.unk_5 == 2 && arg0->unk_24[lbl_1_bss_3C30.unk_A7] <= lbl_1_bss_3C30.unk_1464) {
            arg0->unk_94 = (s32)(15000.0f * rate);
        }

        if (arg1->unk_4C2 >= 6) {
            arg0->unk_8C = -1000;
        } else {
            const s16 table[6] = { 1000, -300, -400, -500, -500, -500 };
            arg0->unk_8C = table[arg1->unk_4C2];
        }
        if (arg0->unk_8C > arg1->unk_213 * 5) {
            arg0->unk_8C -= arg1->unk_213 * 5;
        } else {
            arg0->unk_8C = 0;
        }
    } else {
        arg0->unk_8E = 0;
        arg0->unk_98 = 0;
        arg0->unk_90 = 0;
        arg0->unk_9C = 0;
        arg0->unk_8C = 0;
        arg0->unk_94 = 0;
    }
    arg0->unk_9A = 0;
    arg0->unk_8A = 0;
}

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_2E3B4 */

/* fzgx:begin fn_1_2E928 */
void fn_1_2E928(Racer *racer) {
    Obj3C30 *st = &lbl_1_bss_3C30;
    GameRaceRecord *info = racer->unk_49C;
    GamePlayer *e = &st->unk_D4[racer->unk_4];
    s32 i;
    s32 mult;

    u8 k = st->unk_A7;

    if (e->unk_E[k] != 0xFE && e->unk_E[k] != 0xFF) {
        return;
    }
    e->unk_24[k] = (info->unk_1E0 << 20) | (info->unk_1E1 << 12) | info->unk_1E2;
    e->unk_38[st->unk_A7] = (info->unk_1D4 << 20) | (info->unk_1D5 << 12) | info->unk_1D6;
    if (racer->unk_D8 > 9999.0f) {
        e->unk_18[st->unk_A7] = 9999;
    } else {
        e->unk_18[st->unk_A7] = racer->unk_D8;
    }
    if (racer->unk_482 > 30) {
        e->unk_13[st->unk_A7] = 30;
    } else {
        e->unk_13[st->unk_A7] = racer->unk_482;
    }
    if (!(racer->unk_0 & 0x10000)) {
        e->unk_E[st->unk_A7] = 0xFE;
        if (lbl_1_bss_3C30.unk_5 != 0) {
            e->unk_9[st->unk_A7] = 0;
            e->unk_4C[st->unk_A7] = 0;
        }
    } else {
        s16 id = racer->unk_4;

        for (i = 0; i < lbl_1_bss_3C30.unk_9; i++) {
            if (id == lbl_1_bss_3C30.unk_E[i]) {
                break;
            }
        }
        e->unk_E[st->unk_A7] = i;
        e->unk_4C[st->unk_A7] = 0;
        if (lbl_1_bss_3C30.unk_5 != 0) {
            if (i < 30) {
                e->unk_9[st->unk_A7] = lbl_1_rodata_DB38[i];
            } else {
                e->unk_9[st->unk_A7] = 0;
            }
        }
        e->unk_4 += e->unk_9[st->unk_A7];
        mult = 4 - e->unk_E[st->unk_A7];
        if (mult < 1) {
            mult = 1;
        } else if (mult == 4) {
            mult++;
        }
        e->unk_4C[st->unk_A7] = mult * (racer->unk_210 + e->unk_9[st->unk_A7] * 2);
        e->unk_78 += e->unk_4C[st->unk_A7];
    }
    fn_1_2E3B4(e, racer);
}
/* fzgx:end fn_1_2E928 */

/* fzgx:begin fn_1_2EBB8 */
/* fn_1_2EBB8: block-private types (p0b) */
/* Obj3C30: see Obj3C30 */
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 pad_2[2];
    char *unk_4;
    u8 pad_8[0x28];
} Obj5108_2EBB8;

s32 lbl_1_bss_25BA0 = 0;
s32 lbl_1_bss_25BA4 = 0;

static void game_start_gameover_event(void) {
    u32 old;

    lbl_1_bss_25BA4 = 1;
    old = fn_1_435C(lbl_1_bss_5100);
    fn_1_3F8C("to_gameover_event", fn_1_2E1B8, 0, 13);
    fn_1_4A00(0, 30, lbl_1_bss_5100);
    lbl_1_bss_6EAB4.unk_0 |= 0x2C;
    fn_1_435C(old);
}

static void game_copy_names(void) {
    s32 i;
    GamePlayer *p;

    for (i = 0; i < lbl_1_bss_3C30.unk_9; i++) {
        p = &lbl_1_bss_3C30.unk_D4[i];
        p->unk_E[lbl_1_bss_3C30.unk_A7] = lbl_1_bss_25BA8[i];
        p->unk_13[lbl_1_bss_3C30.unk_A7] = lbl_1_bss_25BC8[i];
    }
}

static inline void fill_colors(GXColor *dst, s32 n, GXColor c) {
    s32 i;

    for (i = 0; i < n; i++, dst++) {
        *dst = c;
    }
}

s32 fn_1_2EBB8(u32 flags, u8 kind) {
    s32 i;
    s32 count;
    f32 width;
    f32 w;

    if (lbl_1_bss_5104 != -1) {
        return 0;
    }
    if (kind == 0 && (lbl_1_bss_3C30.unk_0 & 0x800)) {
        fn_1_4068C(&lbl_1_bss_5108);
        lbl_1_bss_5108.text = fn_1_15BA78("Quitting Replay. OK?");
        lbl_1_bss_5108.state = 2;
        lbl_1_bss_5108.enabled = 1;
        lbl_1_bss_3C30.unk_C4 = fn_1_2C97C;
    }
    if (lbl_1_bss_3C30.unk_13F6 == 0 && lbl_1_bss_3C30.unk_5 == 1) {
        flags &= ~0x28;
    }
    if (lbl_1_bss_3C30.unk_0 & 0x04000000) {
        flags &= ~0x180;
    }
    lbl_1_bss_25BE6 = flags;
    lbl_1_bss_25BE8 = 0;
    lbl_1_bss_25BEA = kind;
    lbl_1_bss_25BEC = -2;
    lbl_1_bss_25BF0 = 0;
    lbl_1_bss_25BF4 = 0;
    lbl_1_bss_25BF8 = 0.0f;
    lbl_1_bss_25BFC = 0.0f;
    lbl_1_data_5B6C = 320.0f;
    lbl_1_data_5B70 = 240.0f;
    lbl_1_data_5B74 = 320.0f;
    lbl_1_data_5B78 = 280.0f;
    {
        GXColor white = {0xFF, 0xFF, 0xFF, 0x00};
        fill_colors(lbl_1_bss_25C00, 10, white);
    }
    {
        GXColor gray = {0x80, 0x80, 0x80, 0x00};
        lbl_1_bss_25C28[0] = lbl_1_bss_25C28[1] = gray;
    }
    fn_1_49410();
    fn_1_495FC();
    fn_1_495C8(1);
    fn_1_49590(0.4f);
    fn_1_495B0(0x80000000);
    fn_1_494DC(0x2A);
    fn_1_4955C(0.75f, 0.75f);
    count = 0;
    width = 0.0f;
    for (i = 14; i > 0; i--) {
        if (flags & (1 << (i - 1))) {
            lbl_1_bss_5104 = i - 1;
            count++;
            w = fn_1_4B068(fn_1_15BA78(lbl_1_data_5ED0[i - 1]));
            if (width < w) {
                width = w;
            }
        }
    }
    if (width < 200.0f) {
        width = 200.0f;
    }
    lbl_1_bss_25C30 = 40.0f + width;
    lbl_1_bss_25C34 = 30.0f + (count * 24);
    lbl_1_data_5B70 -= (count * 10);
    return lbl_1_bss_25C34;
}
/* fzgx:end fn_1_2EBB8 */

/* fzgx:begin fn_1_2EE3C */
/* fn_1_2EE3C: block-private types (p0b) */
/* PadButtons: see PadButtons */
/* Obj3C30: see Obj3C30 */

/* asks to confirm the chosen item with message */

static inline s32 confirm(char *message) {
    lbl_1_bss_25BF4 = 1;
    lbl_1_bss_25BEC = -2;
    lbl_1_bss_25C38 = 1;
    lbl_1_bss_25C3C = message;
    return 0;
}

s32 fn_1_2EE3C(void) {
    s32 decided;
    s32 i;
    s32 item;
    u16 held;

    decided = 0;
    lbl_1_bss_25BE8 &= ~0x300;
    if (lbl_1_bss_25BE6 & 0x300) {
        if (fn_1_B7E98(0) == 0 && fn_1_B7E98(1) == 0) {
            lbl_1_bss_25BE8 |= 0x300;
        } else {
            if (fn_1_F45B4() == 0 || lbl_1_bss_5224 != 0) {
                lbl_1_bss_25BE8 |= 0x100;
            }
            if (fn_1_F22D4() != 0 || lbl_1_bss_5234 != 0) {
                lbl_1_bss_25BE8 |= 0x200;
                lbl_1_bss_5234 = 1;
            }
        }
    }
    if (lbl_1_bss_25BE6 & 0x80) {
        if (fn_1_F45B4() == 0 || lbl_1_bss_5224 != 0) {
            lbl_1_bss_25BE8 |= 0x80;
        }
    }

    if (((PAD(unk_10) >> 3) & 1) || ((PAD(unk_12) >> 3) & 1)) {
        for (i = 13; i != 0; i--) {
            item = (lbl_1_bss_5104 + i) % 14;
            if (lbl_1_bss_25BE6 & (1 << item)) {
                lbl_1_bss_5104 = item;
                break;
            }
        }
        fn_1_A2DC4(0xA9011300);
    } else if (((PAD(unk_10) >> 2) & 1) || ((PAD(unk_12) >> 2) & 1)) {
        for (i = 1; i < 14; i++) {
            item = (lbl_1_bss_5104 + i) % 14;
            if (lbl_1_bss_25BE6 & (1 << item)) {
                lbl_1_bss_5104 = item;
                break;
            }
        }
        fn_1_A2DC4(0xA9011300);
    }

    if (((PAD(unk_8) >> 8) & 1) && !(lbl_1_bss_25BE8 & (1 << lbl_1_bss_5104))) {
        lbl_1_bss_25BEC = 1 << lbl_1_bss_5104;
        decided = 1;
        if (lbl_1_bss_25BEC == 1) {
            fn_1_A2DC4(0xA9011000);
        } else {
            fn_1_A2DC4(0xA9011100);
        }
        switch (lbl_1_bss_25BEC) {
        case 0x2000:
            lbl_1_bss_25BF4 = 1;
            decided = 0;
            lbl_1_bss_25C38 = 1;
            lbl_1_bss_25BEC = -2;
            switch (lbl_1_bss_3C30.unk_5) {
            case 1:
                lbl_1_bss_25C3C = "Quitting Grand Prix.";
                break;
            case 2:
                lbl_1_bss_25C3C = "Quitting Time Attack.";
                break;
            case 5:
                lbl_1_bss_25C3C = "Quitting this scenario.";
                break;
            default:
                lbl_1_bss_25C3C = "Quitting the race.";
                break;
            }
            break;
        case 0x8:
            if (lbl_1_bss_3C2A < 0x2A) {
                decided = confirm("Starting race over.");
            }
            break;
        case 0x20:
            if (lbl_1_bss_3C2A < 0x2A) {
                decided = confirm("Entering Settings screen.");
            }
            break;
        case 0x40:
            decided = confirm("Entering Select Course screen.");
            break;
        case 0x1000:
            decided = confirm("System reset");
            break;
        }
    } else {
        /* WARNING: compiler-diff device, not original code (carried from main): `*(u8 *)&lbl_1_bss_3C20` on a u8.
           Retail loads the port again here; with PAD(unk_8) MWCC reuses the load above (49 words off). */
        held = pad_word(&lbl_1_bss_9F8[0].unk_8, *(u8 *)&lbl_1_bss_3C20);
        if ((((held >> 9) & 1) || ((held >> 12) & 1)) && (lbl_1_bss_25BE6 & 1)) {
            lbl_1_bss_25BEC = 1;
            decided = 1;
            fn_1_A2DC4(0xA9011000);
        }
    }

    if (lbl_1_bss_25BF4 != 0) {
        GXColor gray = {0x80, 0x80, 0x80, 0x00};
        lbl_1_bss_25C28[0] = lbl_1_bss_25C28[1] = gray;
    }
    return decided;
}
/* fzgx:end fn_1_2EE3C */

/* fzgx:begin fn_1_2F294 */
/* the closed menu's colours: every item white, both answers grey. It counts with the caller's index, which
 * retail reuses for the item loop (li r25,0; mr r27,r25 there) */

static inline void fn_1_2F294_init_colors(s32 *i) {
    GXColor white = {0xFF, 0xFF, 0xFF, 0x00};
    GXColor *p;

    for (*i = 0, p = lbl_1_bss_25C00; *i < 10; (*i)++, p++) {
        *p = white;
    }
    {
        GXColor grey = {0x80, 0x80, 0x80, 0x00};
        lbl_1_bss_25C28[0] = lbl_1_bss_25C28[1] = grey;
    }
}

void fn_1_2F294(void) {
    s32 keep;
    s32 i;
    s32 n;
    f32 t;
    f32 fade;
    f32 alpha;
    f32 width;
    f32 height;
    f32 shift;
    s32 w;

    if (lbl_1_bss_25C40 != NULL) {
        keep = (lbl_1_bss_25C40->flags & 1) != 0;
        fn_1_408E8(lbl_1_bss_25C40);
        if (keep == 0 && lbl_1_bss_25C40->unk_8 == 0.0f) {
            lbl_1_bss_25C40 = NULL;
        }
    }

    if (lbl_1_bss_25BF8 == 0.0f) {
        fn_1_2F294_init_colors(&i);
        return;
    }

    if (lbl_1_bss_5104 == -1 || lbl_1_bss_25C44 == 0) {
        lbl_1_bss_25BF8 -= 0.05f;
        if (lbl_1_bss_25BF8 < 0.0f) {
            lbl_1_bss_25BF8 = 0.0f;
            return;
        }
    } else {
        lbl_1_bss_25BF8 += 0.15f;
        if (lbl_1_bss_25BF8 > 1.0f) {
            lbl_1_bss_25BF8 = 1.0f;
        }
    }
    if (lbl_1_bss_25BF4 != 0) {
        lbl_1_bss_25BFC += 0.08f;
        if (lbl_1_bss_25BFC > 1.0f) {
            lbl_1_bss_25BFC = 1.0f;
        }
    } else {
        lbl_1_bss_25BFC -= 0.08f;
        if (lbl_1_bss_25BFC < 0.0f) {
            lbl_1_bss_25BFC = 0.0f;
        }
    }

    fn_1_49410();
    fn_1_495FC();
    fn_1_4954C(0.0006f);
    fn_1_495C8(1);
    fn_1_49590(0.4f);
    t = 2.0f * (lbl_1_bss_25BF8 - 0.5f);
    if (t < 0.0f) {
        t = 0.0f;
    }
    fade = t * (1.0f - lbl_1_bss_25BFC);
    fn_1_495B0(0x80000000);
    fn_1_494DC(0x2A);
    fn_1_4955C(0.75f, 0.75f * fade);
    alpha = 4.0f * (fade - 0.75f);
    width = 0.0f;
    n = 0;
    for (i = 0; i < 14; i++) {
        if (lbl_1_bss_25BE6 & (1 << i)) {
            GXColor color = lbl_1_bss_25C00[n];
            f32 a;
            char *name;
            f32 name_width;

            fn_1_49514(&color);
            a = alpha;
            if (a < 0.0f) {
                a = 0.0f;
            }
            a *= lbl_1_bss_25C00[n].a / 255.0f;
            fn_1_495A0(a);
            fn_1_496FC(lbl_1_data_5B6C, 10.0f + (lbl_1_data_5B70 + (n * 24)));
            name = fn_1_15BA78(lbl_1_data_5ED0[i]);
            fn_1_4A0D8(name);
            name_width = fn_1_4B068(name);
            if (width < name_width) {
                width = name_width;
            }
            n++;
        }
    }
    height = (n * 12 + 40);
    {
        GXColor white = {0xFF, 0xFF, 0xFF, 0x00};
        fn_1_49514(&white);
    }
    fade = 1.1f * (lbl_1_bss_25BF8 * (1.0f - lbl_1_bss_25BFC));
    if (fade > 1.0f) {
        fade = 1.0f;
    }
    fn_1_495A0(fade * fade);
    fn_1_494DC(5);
    fn_1_496FC(lbl_1_data_5B6C, (lbl_1_data_5B70 - 38.0f) + (1.0f - fade) * height);
    fn_1_4955C(1.0f, 1.0f);
    fn_1_4A0D8("F-ZERO GX");
    fn_1_496FC(lbl_1_data_5B6C, (lbl_1_data_5B70 - 20.0f) + (1.0f - fade) * height);
    fn_1_4A0D8("[ MENU ]");

    {
        FontDrawPacket packet = lbl_1_rodata_26F8;

        packet.x = lbl_1_data_5B6C;
        packet.y = (lbl_1_data_5B70 + height) - 50.0f;
        packet.z = 0.0008f;
        packet.flags = 10;
        packet.image = 2;
        packet.alpha = lbl_1_bss_25BF8 * (1.0f - lbl_1_bss_25BFC);
        if (width < 180.0f) {
            width = 180.0f;
        }
        width += 30.0f;
        w = 3.0f * (45.0f * lbl_1_bss_25BF8);
        if (w > 45) {
            w = 45;
        }
        fade = 1.1f * lbl_1_bss_25BF8 * (1.0f - lbl_1_bss_25BFC);
        if (fade > 1.0f) {
            fade = 1.0f;
        }
        fn_1_50A90(&packet, 18, w, (s32)width, (s32)(fade * (80.0f + (n * 24))));

        if (lbl_1_bss_25BFC > 0.0f) {
            fn_1_494DC(0x2A);
            fn_1_4955C(0.75f, 0.75f * lbl_1_bss_25BFC);
            fn_1_495C8(1);
            fade = 2.0f * (lbl_1_bss_25BFC * lbl_1_bss_25BF8 - 0.5f);
            if (fade < 0.0f) {
                fade = 0.0f;
            }
            fn_1_4954C(0.0002f);
            {
                GXColor white = {0xFF, 0xFF, 0xFF, 0x00};
                fn_1_49514(&white);
            }
            fn_1_495A0(fade);
            shift = 1.0f - fade;
            fn_1_496FC(lbl_1_data_5B74, (30.0f + lbl_1_data_5B78) + 50.0f * shift);
            fn_1_4A0D8(fn_1_15BA78(lbl_1_bss_25C3C));
            fn_1_496FC(lbl_1_data_5B74, (60.0f + lbl_1_data_5B78) + 20.0f * shift);
            fn_1_4A0D8(fn_1_15BA78("Is this OK?"));
            for (i = 0; i < 2; i++) {
                char *answers[2] = {"YES", "NO"};
                GXColor color = lbl_1_bss_25C28[i];

                fn_1_49514(&color);
                alpha = 2.0f * (fade * (lbl_1_bss_25C28[i].a / 255.0f) - 0.5f);
                if (alpha < 0.0f) {
                    alpha = 0.0f;
                }
                fn_1_495A0(alpha);
                fn_1_496FC((lbl_1_data_5B74 - 100.0f) + (i * 200),
                           (70.0f + lbl_1_data_5B78) + 30.0f * fade);
                fn_1_4A0D8(fn_1_15BA78(answers[i]));
            }
            packet.x = lbl_1_data_5B74;
            packet.y = 75.0f + lbl_1_data_5B78;
            packet.z = 0.0004f;
            packet.alpha = lbl_1_bss_25BFC * lbl_1_bss_25BF8;
            width = (s32)(45.0f * lbl_1_bss_25BFC * lbl_1_bss_25BF8);
            height = (s32)(150.0f * lbl_1_bss_25BFC * lbl_1_bss_25BF8);
            fn_1_50A90(&packet, 18, (s32)width, 400, (s32)height);
        }
    }
    {
        GXColor white = {0xFF, 0xFF, 0xFF, 0x00};
        fn_1_49514(&white);
    }
    fn_1_49614();
}
/* fzgx:end fn_1_2F294 */

/* fzgx:begin fn_1_2FAA0 */
/* fn_1_2FAA0: block-private types (p0b) */
/* PadButtons: see PadButtons */

/* .bss 0x9F8: the buttons of one pad port */

static inline s32 fn_1_2FAA0_color_eq(GXColor a, GXColor b) {
    if (a.r != b.r) {
        return 0;
    }
    if (a.g != b.g) {
        return 0;
    }
    if (a.b != b.b) {
        return 0;
    }
    return 1;
}

static inline void fn_1_2FAA0_color_fade(GXColor *color, GXColor target) {
    fn_1_2C7C4((u8 *)color, (u8 *)&target, 20);
}

static inline s32 fn_1_2FAA0_input(void) {
    s32 decided;

    decided = 0;
    if ((pad_word(&lbl_1_bss_9F8[0].unk_10, lbl_1_bss_3C20) & 1) ||
        (pad_word(&lbl_1_bss_9F8[0].unk_12, lbl_1_bss_3C20) & 1)) {
        if (lbl_1_bss_25C38 == 1) {
            fn_1_A2DC4(0xA9011300);
        }
        lbl_1_bss_25C38 = 0;
    } else if (((pad_word(&lbl_1_bss_9F8[0].unk_10, lbl_1_bss_3C20) >> 1) & 1) ||
               ((pad_word(&lbl_1_bss_9F8[0].unk_12, lbl_1_bss_3C20) >> 1) & 1)) {
        if (lbl_1_bss_25C38 == 0) {
            fn_1_A2DC4(0xA9011300);
        }
        lbl_1_bss_25C38 = 1;
    }
    if ((pad_word(&lbl_1_bss_9F8[0].unk_8, lbl_1_bss_3C20) >> 8) & 1) {
        if (lbl_1_bss_25C38 == 0) {
            decided = 1;
            lbl_1_bss_25BEC = 1 << lbl_1_bss_5104;
            fn_1_A2DC4(0xA9011100);
        } else {
            lbl_1_bss_25BF4 = 0;
            fn_1_A2DC4(0xA9011000);
        }
    } else if (((pad_word(&lbl_1_bss_9F8[0].unk_8, lbl_1_bss_3C20) >> 9) & 1) ||
               ((pad_word(&lbl_1_bss_9F8[0].unk_8, lbl_1_bss_3C20) >> 12) & 1)) {
        lbl_1_bss_25BF4 = 0;
        fn_1_A2DC4(0xA9011000);
    }
    return decided;
}

void fn_1_2FAA0(void) {
    GXColor *color;
    s32 i;
    s32 ret;

    ret = 0;
    lbl_1_bss_25BEC = -2;
    lbl_1_bss_25C44 = 1;
    if (lbl_1_bss_25BE6 == 0) {
        OSPanic("game.c", 2983, "GAME: menu mask is zero.\n");
    }
    if (lbl_1_bss_25BA0 == 0) {
        if (lbl_1_bss_25BF4 != 0) {
            ret = fn_1_2FAA0_input();
        } else {
            ret = fn_1_2EE3C();
        }
    }

    for (i = 0, color = lbl_1_bss_25C00; i < 14; i++) {
        if (lbl_1_bss_25BE6 & (1 << i)) {
            if (lbl_1_bss_5104 == i) {
                *color = (GXColor){0xFF, 0xF2, 0x00, 0xFF};
            } else if (fn_1_2FAA0_color_eq(*color, (GXColor){0xFF, 0xF2, 0x00, 0xFF})) {
                color->b = 10;
            } else if (lbl_1_bss_25BE8 & (1 << i)) {
                fn_1_2FAA0_color_fade(color, (GXColor){0x80, 0x80, 0x80, 0x80});
            } else {
                fn_1_2FAA0_color_fade(color, (GXColor){0xFF, 0xFF, 0xFF, 0x96});
            }
            color++;
        }
    }

    if (lbl_1_bss_25BF4 != 0) {
        if (lbl_1_bss_25C38 != 0) {
            lbl_1_bss_25C28[1] = (GXColor){0xFF, 0xF2, 0x00, 0xFF};
            color = &lbl_1_bss_25C28[0];
        } else {
            lbl_1_bss_25C28[0] = (GXColor){0xFF, 0xF2, 0x00, 0xFF};
            color = &lbl_1_bss_25C28[1];
        }
        fn_1_2FAA0_color_fade(color, (GXColor){0xFF, 0xFF, 0xFF, 0x96});
    }

    if (lbl_1_bss_25BF8 == 0.0f) {
        lbl_1_bss_25BF8 = 0.01f;
    }
    if (ret != 0) {
        lbl_1_bss_5104 = -1;
    }
}
/* fzgx:end fn_1_2FAA0 */

/* fzgx:begin fn_1_2FDBC */
static inline void fn_1_2FDBC_set(Obj3C30 *f) {
    f->unk_5 = 6;
}

void fn_1_2FDBC(struct fn_1_2FDBC_arg *arg0) {
    s32 sum;
    s32 flag;
    f32 ms;
    f32 t;
    struct fn_1_2FDBC_loc loc;

    flag = 0;
    if (fn_1_3EFA8() != 0) {
        return;
    }
    switch (lbl_1_bss_3C2A) {
    case 41:
        break;
    default:
        return;
    }
    if (lbl_1_bss_3C30.unk_0 & 0x800) {
        return;
    }
    sum = lbl_801A66CC->unk_8B4;
    sum += lbl_801A66CC->unk_8B5;
    sum += lbl_801A66CC->unk_8B6;
    if (!(arg0->unk_0 & 0x10000)) {
        fn_1_82EDC(arg0->unk_474, arg0->unk_6, &loc);
        if (((struct fn_1_2FDBC_sub *)lbl_1_bss_53F8[0]) != 0) {
            t = ((struct fn_1_2FDBC_sub *)lbl_1_bss_53F8[0])->unk_B;
            t *= 0.01f;
            fn_1_22B10(&loc, t);
        } else {
            t = lbl_1_bss_25C48[0];
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
        ms += (((lbl_801A66CC->unk_8B6) * (60.0f))) / 1000.0f;
        if (__fabs(ms - arg0->unk_49C->unk_1E4) > 20.0) {
            flag = 1;
        }
    }
    if (flag != 0) {
        fn_1_2FDBC_set(&lbl_1_bss_3C30);
    }
}

/* Static helper: inlined five times in fn_1_36330. Its out-of-line copy registers the .bss table
   lbl_1_bss_25C84 here, between 25C48 (fn_1_2FDBC) and 25CA4 (fn_1_30054), as retail has it. */
static void game_save_heap_free(u32 heap)
{
    lbl_1_bss_25C84[heap] = fn_800090A4(heap);
}
/* fzgx:end fn_1_2FDBC */

/* fzgx:begin fn_1_30054 */
static inline void *fn_1_30054_name(u8 id)
{
    BOOL special = FALSE;
    if (id == 5 || id == 0x15) {
        special = TRUE;
    }
    if (special) {
        return lbl_1_data_1EA28;
    }
    return lbl_1_data_2A8D8[lbl_1_data_2B0D4[id]];
}

static inline u32 fn_1_30054_rand(void)
{
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7fff;
}

/* WARNING: compiler-diff device, not original code (carried from main): the no-op view `((BurnerWork *)&lbl_1_bss_8B5F4)`.
   Without it MWCC keeps &lbl_1_bss_8B5F4 in r27 across the call (4 words off); retail builds the address again. */
static inline void fn_1_30054_prepare(void)
{
    fn_1_46A8C(((BurnerWork *)&lbl_1_bss_8B5F4)->unk_4);
}

void fn_1_30054(void)
{
    s16 a;
    s16 b;
    u32 t;
    void *name;

    fn_1_435C(lbl_1_bss_25CA4);
    name = fn_1_30054_name(lbl_1_bss_3C30.unk_6);
    lbl_1_bss_25CA8 = fn_1_3F8C("GameCalcLight", fn_1_F78AC, name, 5);
    name = fn_1_30054_name(lbl_1_bss_3C30.unk_6);
    lbl_1_bss_25CAC = fn_1_3F8C("GameCalcLight", fn_1_F78AC, name, 0x18);
    lbl_1_bss_25CB0 = fn_1_3F8C("CarCalcLight", fn_1_F78D8,
                               lbl_1_data_2A92C[lbl_1_data_2B0D4[lbl_1_bss_3C30.unk_6]], 0x10);
    fn_1_435C(lbl_1_bss_25B88);
    lbl_1_bss_25CB4 = fn_1_3F8C("StageCalc", fn_1_789E8, NULL, 0x15);
    lbl_1_bss_25CB8 = fn_1_3F8C("BackGroundCalc", fn_1_9A5CC, NULL, 0x17);
    fn_1_435C(lbl_1_bss_25CA4);
    lbl_1_bss_25CBC = fn_1_3F8C("FogMain", fn_1_7E9C4, NULL, 4);
    lbl_1_bss_25CC0 = fn_1_3F8C("StageDisp", fn_1_78EBC, NULL, 7);
    lbl_1_bss_25CC4 = fn_1_3F8C("BackGroundDisp", fn_1_9A7BC, NULL, 0xa);

    if (lbl_1_bss_960 != 10 && lbl_1_bss_960 != 12) {
        fn_1_30054_prepare();
        lbl_1_bss_8B5F4.unk_10 = lbl_1_bss_8B5F4.unk_4;
        fn_1_3F75C();
        if (lbl_1_bss_25CC8 != 0 && lbl_1_data_5B7C != 2) {
            fn_1_D19B8(lbl_1_bss_523C);
        }
        fn_1_46B44(fn_1_3F7A0, &lbl_1_bss_8B5F4.unk_14);
    }

    fn_1_411A4(2);
    game_heap_report(lbl_801A6410);
    t = fn_80008E84(lbl_1_bss_25CCC);
    fn_1_7ACDC(lbl_1_bss_3C30.unk_6);
    game_heap_report(lbl_801A6410);
    fn_80008E84(t);

    fn_1_12EF80(lbl_1_bss_3C30.unk_6, &a, &b);
    if (a != -1) {
        lbl_1_bss_25CD0 = (BurnerSlot *)((u8 *)&lbl_1_bss_7F0C0 + a * 0x900 + b * 0x180 + 0xf8);
    } else {
        lbl_1_bss_25CD0 = &lbl_1_bss_25CD4;
        lbl_1_bss_25CD0->unk_163 = 0;
    }

    fn_1_3F8D0();
    fn_1_435C(lbl_1_bss_25CA4);
    lbl_1_bss_25E54 = fn_1_3F8C("yajirushi_disp", fn_1_3F8EC, NULL, 0x1c);
    fn_1_E3324();
    fn_1_435C(lbl_1_bss_25CA4);
    lbl_1_bss_25E58 = fn_1_3F8C("PhysObjDisp", fn_1_E38D4, NULL, 9);
    lbl_1_bss_25E5C = fn_1_3F8C("PhysObjPostDisp", fn_1_E39F0, NULL, 0xb);
    lbl_1_bss_25E60 = fn_1_3F8C("PhysShadowPreRend", fn_1_E95B4, NULL, 0);
    fn_1_435C(lbl_1_bss_25B88);
    lbl_1_bss_25E64 = fn_1_3F8C("PhysObjCalc", fn_1_E49D4, NULL, 8);
    game_heap_report(lbl_801A6410);
    fn_1_154708(lbl_1_bss_25CA4);
    game_heap_report(lbl_801A6410);
    fn_1_86254(0);
    fn_1_C3A0C();
    fn_1_435C(lbl_1_bss_25B88);
    fn_1_43E8(0x101);
    lbl_1_bss_3C14 = fn_1_3F8C("EnemyTotalControlMain", fn_1_C42F4, fn_1_86254(0), 2);
    fn_1_43F4();

    game_heap_report(lbl_801A6410);
    lbl_1_bss_25E68 = fn_1_30054_rand();
    lbl_1_bss_25E6C = 0;
    lbl_1_bss_25E70 = 0;
    lbl_1_bss_3C30.unk_0 &= ~0x4000;
    if (lbl_1_bss_25E74 != NULL) {
        lbl_1_bss_25E74(&lbl_1_bss_3C30);
    }
}
/* fzgx:end fn_1_30054 */

/* fzgx:begin fn_1_304A8 */
/* fn_1_304A8: block-private types (p0b) */
/* GamePlayer: see GamePlayer */
/* Obj3C30: see Obj3C30 */
/* GameSlotEntry: see GameSlotEntry */
/* GameSlotTable: see GameSlotTable */

void fn_1_304A8(void)
{
    s32 i;

    if (lbl_1_bss_25BA0 == 0) {
        lbl_1_bss_53F4 = lbl_1_bss_3C30.unk_7;
        if (lbl_1_bss_3C30.unk_5 == 0) {
            for (i = 0; i < lbl_1_bss_3C30.unk_8; i++) {
                if (lbl_1_bss_3C30.unk_1480[i] != 0) {
                    game_slot_table_fill();
                    break;
                }
            }
        }
        fn_1_4A00(0, 0x1E, lbl_1_bss_5100);
        lbl_1_bss_6EAB4.unk_0 |= 0x2C;
        lbl_1_bss_25BA0 = 1;
        if (lbl_1_bss_3C30.unk_5 == 0) {
            lbl_1_data_5B84 = 1;
        }
        fn_1_469BC();
        fn_1_8DBA4(0);
    }
}
/* fzgx:end fn_1_304A8 */

/* fzgx:begin fn_1_30824 */
/* fn_1_30824: block-private types (p0b) */
/* GamePlayer: see GamePlayer */
/* Obj3C30: see Obj3C30 */
/* GameSlotEntry: see GameSlotEntry */
/* GameSlotTable: see GameSlotTable */

s32 lbl_1_bss_25E78 = 0;
s32 lbl_1_bss_25E7C = 0;
s32 lbl_1_bss_25E80 = 0;
s32 lbl_1_bss_25E84 = 0;
s32 lbl_1_bss_25E88 = 0;
s32 lbl_1_bss_25E8C = 0;
u8 lbl_1_bss_25E90 = 0;
s32 lbl_1_bss_25E94 = 0;

/* The replay work release that fn_1_30824, fn_1_30D84 and fn_1_3129C share (retail holds one inlined copy in each). */
static inline void game_replay_release(void)
{
    u32 heap;

    heap = fn_1_434C();
    if ((lbl_1_bss_3C30.unk_0 & 0x00800000) && lbl_1_bss_7EFD8.unk_0 != 0) {
        if (fn_1_F2F58() != 0) {
            fn_1_F37F4();
        }
        fn_1_435C(lbl_1_bss_25B88);
        fn_1_426C(lbl_1_bss_7EFD8.unk_0);
        lbl_1_bss_7EFD8.unk_0 = 0;
    }
    if (lbl_1_bss_7F04C != 0) {
        fn_1_435C(lbl_1_bss_25B88);
        fn_1_426C(lbl_1_bss_7F04C);
        fn_1_F7308();
        lbl_1_bss_7F04C = 0;
    }
    if (lbl_1_bss_3C30.unk_0 & 0x00800000) {
        if (lbl_1_bss_25E78 != 0) {
            fn_1_F2E50(1);
        } else {
            fn_1_F2E50(0);
        }
    }
    fn_1_435C(heap);
}

void fn_1_30824(void)
{
    GameStepFn func;
    u32 flags;

    if (--lbl_1_bss_25E8C == 0) {
        lbl_1_bss_50E8 = 0x26;
        game_replay_release();
        fn_1_5370(0, 0);
        fn_1_E3778();
        fn_1_EA314(0);
        if (lbl_1_bss_25E88 != 0) {
            fn_1_435C(lbl_1_bss_25B88);
            if (lbl_1_data_5B88 != -1) {
                fn_1_426C(lbl_1_data_5B88);
                lbl_1_data_5B88 = -1;
            }
            fn_1_435C(lbl_1_bss_25CA4);
            if (lbl_1_data_5B8C[0] != -1) {
                fn_1_426C(lbl_1_data_5B8C[0]);
                lbl_1_data_5B8C[0] = -1;
            }
            fn_1_D1F88();
            lbl_1_bss_25E88 = 0;
        }
        lbl_1_bss_3C30.unk_1474 = 0;
        if (lbl_1_bss_3C0C != 0) {
            func = lbl_1_bss_3C30.unk_C0;
            lbl_1_bss_25B9C = 0;
            if (func != NULL) {
                flags = func(&lbl_1_bss_3C30);
                if (flags & 4) {
                    lbl_1_bss_25B9C = 1;
                }
                if (flags & 2) {
                    fn_1_304A8();
                }
                if (flags & 1) {
                    /* Retail skips the 3C08 clear by branching straight to the shared tail. */
                    goto keep;
                }
            }
            lbl_1_bss_3C0C = 0;
        }
    keep:
        if (lbl_1_bss_3C30.unk_5 == 1) {
            lbl_1_bss_3C30.unk_13F6--;
        }
        fn_1_4060();
        fn_1_A1588(lbl_1_bss_6EAD0.unk_0->unk_0, 0x2D);
        lbl_1_bss_25E90 = 0;
    } else {
        lbl_1_bss_25E90 = 1;
    }
}
/* fzgx:end fn_1_30824 */

/* fzgx:begin fn_1_30D84 */
/* fn_1_30D84: block-private types (p0b) */
/* GamePlayer: see GamePlayer */
/* Obj3C30: see Obj3C30 */
/* GameSlotEntry: see GameSlotEntry */
/* GameSlotTable: see GameSlotTable */

static void game_goto_setting(void)
{
    s32 heap;
    GameCar *car;

    if (lbl_1_bss_25BA0 != 0) {
        return;
    }
    lbl_1_bss_25BA0 = 1;
    fn_1_4A00(0, 0x1E, lbl_1_bss_5100);
    lbl_1_bss_25E78 = 0;
    lbl_1_bss_6EAB4.unk_0 |= 0x2C;
    fn_1_4DE04();
    if (lbl_1_bss_960 != 10 && lbl_1_bss_960 != 12) {
        car = fn_1_86900(fn_1_8623C());
        if (car == NULL) {
            car = fn_1_868C0(0);
        }
        fn_1_4811C(((u32 *)lbl_1_data_1A2B4)[fn_1_12C930(car->unk_328)]);
        fn_1_4811C(0x97);
        fn_1_4811C(0x99);
        fn_1_48004(0x94, 1);
    }
    fn_1_3F8D0();
    lbl_1_bss_25E70 = 1;
    lbl_1_bss_25E8C = 0x3C;
    heap = fn_1_435C(lbl_1_bss_5100);
    fn_1_3F8C("setting_gap", fn_1_30824, 0, 2);
    fn_1_435C(heap);
}

void fn_1_30D84(void)
{
    GameStepFn func;
    u32 flags;

    if (--lbl_1_bss_25E8C == 0) {
        lbl_1_bss_50E8 = 0x25;
        game_replay_release();
        fn_1_5370(0, 0);
        fn_1_E3778();
        fn_1_EA314(0);
        if (lbl_1_bss_25E88 != 0) {
            fn_1_435C(lbl_1_bss_25B88);
            if (lbl_1_data_5B88 != -1) {
                fn_1_426C(lbl_1_data_5B88);
                lbl_1_data_5B88 = -1;
            }
            fn_1_435C(lbl_1_bss_25CA4);
            if (lbl_1_data_5B8C[0] != -1) {
                fn_1_426C(lbl_1_data_5B8C[0]);
                lbl_1_data_5B8C[0] = -1;
            }
            fn_1_D1F88();
            lbl_1_bss_25E88 = 0;
        }
        lbl_1_bss_3C30.unk_1474 = 0;
        if (lbl_1_bss_3C0C != 0) {
            func = lbl_1_bss_3C30.unk_C0;
            lbl_1_bss_25B9C = 0;
            if (func != NULL) {
                flags = func(&lbl_1_bss_3C30);
                if (flags & 4) {
                    lbl_1_bss_25B9C = 1;
                }
                if (flags & 2) {
                    fn_1_304A8();
                }
                if (flags & 1) {
                    /* Retail skips the 3C08 clear by branching straight to the shared tail. */
                    goto keep;
                }
            }
            lbl_1_bss_3C0C = 0;
        }
    keep:
        fn_1_4060();
    }
}
/* fzgx:end fn_1_30D84 */

/* fzgx:begin fn_1_3129C */
/* fn_1_3129C: block-private types (p0b) */
/* GamePlayer: see GamePlayer */
/* Obj3C30: see Obj3C30 */
/* GameSlotEntry: see GameSlotEntry */
/* GameSlotTable: see GameSlotTable */

static inline void fn_1_3B7D4_copy(Obj3C30 *gs)
{
    s32 i;
    GamePlayer *q;

    for (i = 0; i < gs->unk_9; i++) {
        q = &gs->unk_D4[i];
        q->unk_83 = q->unk_8;
    }
}

static void game_goto_next_stage(void)
{
    s32 heap;
    GameCar *car;

    if (lbl_1_bss_25BA0 != 0) {
        return;
    }
    lbl_1_bss_25BA0 = 1;
    fn_1_4A00(0, 0x1E, lbl_1_bss_5100);
    lbl_1_bss_25E78 = 0;
    lbl_1_bss_6EAB4.unk_0 |= 0x2C;
    fn_1_4DE04();
    if (lbl_1_bss_960 != 10 && lbl_1_bss_960 != 12) {
        car = fn_1_86900(fn_1_8623C());
        if (car == NULL) {
            car = fn_1_868C0(0);
        }
        fn_1_4811C(((u32 *)lbl_1_data_1A2B4)[fn_1_12C930(car->unk_328)]);
        fn_1_4811C(0x97);
        fn_1_4811C(0x99);
        fn_1_48004(0x94, 1);
    }
    fn_1_3F8D0();
    lbl_1_bss_25E6C = 1;
    lbl_1_bss_25E8C = 0x3C;
    heap = fn_1_435C(lbl_1_bss_5100);
    fn_1_3F8C("next_stage_gap", fn_1_30D84, 0, 2);
    fn_1_435C(heap);
    fn_1_3B7D4_copy(&lbl_1_bss_3C30);
}

void fn_1_3129C(s32 arg)
{
    u32 old;
    s32 mode;
    GameStepFn func;
    u32 flags;

    if (--lbl_1_bss_25E8C == 0) {
        old = lbl_1_bss_3C30.unk_0 & 0x200;
        lbl_1_bss_3C30.unk_0 |= 0x200;
        mode = (lbl_1_bss_3C30.unk_0 & 0x201) != 0;
        lbl_1_bss_3C30.unk_0 &= ~0x200;
        lbl_1_bss_3C30.unk_0 |= old;
        lbl_1_bss_50E8 = 0x27 + mode;
        game_replay_release();
        fn_1_5370(0, 0);
        fn_1_E3778();
        fn_1_EA314(arg);
        if (lbl_1_bss_25E88 != 0) {
            fn_1_435C(lbl_1_bss_25B88);
            if (lbl_1_data_5B88 != -1) {
                fn_1_426C(lbl_1_data_5B88);
                lbl_1_data_5B88 = -1;
            }
            fn_1_435C(lbl_1_bss_25CA4);
            if (lbl_1_data_5B8C[0] != -1) {
                fn_1_426C(lbl_1_data_5B8C[0]);
                lbl_1_data_5B8C[0] = -1;
            }
            fn_1_D1F88();
            lbl_1_bss_25E88 = 0;
        }
        lbl_1_bss_3C30.unk_1474 = 0;
        if (lbl_1_bss_3C0C != 0) {
            func = lbl_1_bss_3C30.unk_C0;
            lbl_1_bss_25B9C = 0;
            if (func != NULL) {
                flags = func(&lbl_1_bss_3C30);
                if (flags & 4) {
                    lbl_1_bss_25B9C = 1;
                }
                if (flags & 2) {
                    fn_1_304A8();
                }
                if (flags & 1) {
                    /* Retail skips the 3C08 clear by branching straight to the shared tail. */
                    goto keep;
                }
            }
            lbl_1_bss_3C0C = 0;
        }
    keep:
        if (arg == 0 && lbl_1_bss_3C30.unk_5 == 1) {
            lbl_1_bss_3C30.unk_13F6--;
        }
        fn_1_4060();
        lbl_1_bss_25E90 = 0;
    } else {
        lbl_1_bss_25E90 = 1;
    }
}
/* fzgx:end fn_1_3129C */

/* fzgx:begin fn_1_3181C */
/* fn_1_3181C: block-private types (p0b) */
/* GamePlayer: see GamePlayer */
/* Obj3C30: see Obj3C30 */
/* RaceBuf: see RaceBuf */

static void game_restart(s32 mode)
{
    s32 heap;
    GameCar *car;

    if (lbl_1_bss_25BA0 != 0) {
        return;
    }
    lbl_1_bss_25BA0 = 1;
    fn_1_4A00(0, 0x1E, lbl_1_bss_5100);
    lbl_1_bss_25E78 = mode;
    lbl_1_bss_6EAB4.unk_0 |= 0x2C;
    fn_1_4DE04();
    if (lbl_1_bss_960 != 10 && lbl_1_bss_960 != 12) {
        car = fn_1_86900(fn_1_8623C());
        if (car == NULL) {
            car = fn_1_868C0(0);
        }
        fn_1_4811C(((u32 *)lbl_1_data_1A2B4)[fn_1_12C930(car->unk_328)]);
        fn_1_4811C(0x97);
        fn_1_4811C(0x99);
        fn_1_48004(0x94, 1);
    }
    fn_1_3F8D0();
    lbl_1_bss_25E8C = 0x3C;
    heap = fn_1_435C(lbl_1_bss_5100);
    fn_1_3F8C("GameRestart_gap", fn_1_3129C, (void *)mode, 2);
    fn_1_435C(heap);
}

static void game_set_pause_port(void)
{
    if (lbl_1_bss_3C30.unk_8 != 0) {
        lbl_1_bss_3C20 = lbl_1_bss_25E98[0];
    } else {
        lbl_1_bss_3C20 = 0;
    }
}

void fn_1_3181C(void)
{
    s8 slots[4];
    u32 bits[4] = { 0x80000000, 0x40000000, 0x20000000, 0x10000000 };
    GameEntry *e;
    Racer *res;
    GameEntrant *sub;
    RaceBuf *racer;
    u32 heap;
    s32 i;
    s16 slot;
    GamePlayer *pl;
    s8 t;
    s32 k;

    fn_1_81808(slots);
    for (i = 0; i < lbl_1_bss_3C30.unk_9; i++) {
        e = &lbl_1_bss_25E9C[i];
        fn_1_80058(lbl_1_bss_2625C[i], e);
        e->unk_0 = i;
        e->unk_8 = lbl_1_bss_523C[i];
        e->unk_C = lbl_1_bss_2627C[i];
        e->unk_4 = fn_1_8171C(1);
        slot = -1;
        for (k = 0; k < 4; k++) {
            if (slots[k] == i) {
                slots[k] = -1;
                slot = k;
            }
        }
        if (i < lbl_1_bss_3C30.unk_8) {
            if (lbl_1_bss_3C30.unk_8 > 1) {
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
        if (lbl_1_bss_3C30.unk_8 == 0) {
            if (i < lbl_1_bss_262F4 || i == 0) {
                e->unk_4 = fn_1_8171C(0);
                e->unk_C |= 0x80000000;
                e->unk_8 = 1;
            }
        }
    }
    heap = fn_80008E84(lbl_1_bss_262F8);
    res = fn_1_83070(lbl_1_bss_25B88, lbl_1_bss_25CA4, lbl_1_bss_25E9C,
                     lbl_1_bss_3C30.unk_9);
    game_heap_report(lbl_801A6410);
    fn_80008E84(heap);
    for (i = 0; i < lbl_1_bss_3C30.unk_9; i++) {
        pl = &lbl_1_bss_3C30.unk_D4[i];
        pl->unk_0 = (u32)res[i].unk_3C;
        t = res[i].unk_475;
        if (t != -1) {
            lbl_1_bss_262FC[t] = res[i].unk_474;
        }
        lbl_1_bss_3C30.unk_1394[i] = i;
        lbl_1_bss_3C30.unk_2C[i] = res[i].unk_49C;
        pl->unk_7C = 0xFF;
        pl->unk_7D = 0xFF;
        pl->unk_7E = 0xFF;
        pl->unk_80 = res[i].unk_6;
        pl->unk_82 = res[i].unk_6;
        pl->unk_81 = lbl_1_bss_25C48[i];
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
        if (lbl_1_bss_3C30.unk_5 == 2 && i == 0) {
            fn_1_435C(lbl_1_bss_25B88);
            lbl_1_bss_26300 = fn_1_3F8C("car_status_check", fn_1_2FDBC, res, 0x1E);
        }
        sub = lbl_1_bss_53F8[i];
        if (sub != NULL) {
            pl->unk_81 = sub->unk_B;
            if (sub->name >= 0x29) {
                t = res[i].unk_474;
                if (t != -1) {
                    racer = &lbl_1_bss_5480[t];
                    pl->unk_80 = racer->unk_81A0;
                    pl->unk_82 = racer->unk_4.name;
                    pl->unk_7C = racer->unk_81A4;
                    pl->unk_7D = racer->unk_81AC;
                    pl->unk_7E = racer->unk_81B4;
                }
            } else {
                pl->unk_80 = pl->unk_82 = sub->name;
            }
        }
    }
}
/* fzgx:end fn_1_3181C */

/* fzgx:begin fn_1_31C3C */
/* fn_1_31C3C: block-private types (p0b) */
/* Obj3C30: see Obj3C30 */
typedef struct Obj5138_31C3C {
    u16 mode;
    u8 pad_2[0xE1];
    u8 course;   /* 0xE3 */
} Obj5138_31C3C;

static void game_keep_goal_record(Racer *racer)
{
    s8 slot = racer->unk_475;

    if (slot != -1 && lbl_1_bss_26304[slot] < 1.0f) {
        fn_80008BA8(&lbl_1_bss_26314[slot], racer->unk_49C, sizeof(GameRaceRecord));
        lbl_1_bss_26304[racer->unk_475] = racer->unk_D8;
        if (racer->unk_482 > 30) {
            lbl_1_bss_26B04[racer->unk_475] = 30;
        } else {
            lbl_1_bss_26B04[racer->unk_475] = racer->unk_482;
        }
    }
}

/* the TU's .bss, addressed off one section base */

void fn_1_31C3C(u32 player) {
    GamePlayer *res = &lbl_1_bss_3C30.unk_D4[0];
    u32 time = res->unk_24[player];
    u32 lap = res->unk_38[player];
    u32 i;

    for (i = 0; i < 10; i++) {
        if (time < lbl_1_bss_25CD0->ranking[i].time) {
            break;
        }
    }
    lbl_1_bss_26B08 = i;

    for (i = 9; i > lbl_1_bss_26B08; i--) {
        lbl_1_bss_25CD0->ranking[i] = lbl_1_bss_25CD0->ranking[i - 1];
    }

    if (lbl_1_bss_26B08 < 10) {
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B08].time = time;
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B08].lap = lap;
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B08].speed = res->unk_18[player];
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B08].c1A = res->unk_82;
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B08].c1B = res->unk_80;
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B08].c1C = res->unk_81;
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B08].c1D = res->unk_7C;
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B08].c1E = res->unk_7D;
        lbl_1_bss_25CD0->ranking[lbl_1_bss_26B08].c1F = res->unk_7E;
    }

    if (lap < lbl_1_bss_25CD0->bestLap.time) {
        lbl_1_bss_26B0C = 1;
        lbl_1_bss_25CD0->bestLap.time = lap;
        lbl_1_bss_25CD0->bestLap.lap = lap;
        lbl_1_bss_25CD0->bestLap.speed = res->unk_18[player];
        lbl_1_bss_25CD0->bestLap.c1A = res->unk_82;
        lbl_1_bss_25CD0->bestLap.c1B = res->unk_80;
        lbl_1_bss_25CD0->bestLap.c1C = res->unk_81;
        lbl_1_bss_25CD0->bestLap.c1D = res->unk_7C;
        lbl_1_bss_25CD0->bestLap.c1E = res->unk_7D;
        lbl_1_bss_25CD0->bestLap.c1F = res->unk_7E;
    } else {
        lbl_1_bss_26B0C = 0;
    }

    if (lbl_1_bss_25CD0->maxSpeed < res->unk_18[player]) {
        lbl_1_bss_26B10 = 1;
        lbl_1_bss_25CD0->maxSpeed = res->unk_18[player];
        lbl_1_bss_25CD0->s162 = res->unk_82;
        lbl_1_bss_25CD0->s164 = res->unk_80;
        lbl_1_bss_25CD0->s165 = res->unk_81;
        lbl_1_bss_25CD0->s166 = res->unk_7C;
        lbl_1_bss_25CD0->s167 = res->unk_7D;
        lbl_1_bss_25CD0->s168 = res->unk_7E;
    } else {
        lbl_1_bss_26B10 = 0;
    }

    lbl_1_bss_3C30.unk_1444.lap = lap;
    lbl_1_bss_3C30.unk_1444.speed = res->unk_18[player];
    lbl_1_bss_3C30.unk_1444.c1A = res->unk_82;
    lbl_1_bss_3C30.unk_1444.c1B = res->unk_80;
    lbl_1_bss_3C30.unk_1444.c1C = res->unk_81;
    lbl_1_bss_3C30.unk_1444.c1D = res->unk_7C;
    lbl_1_bss_3C30.unk_1444.c1E = res->unk_7D;
    lbl_1_bss_3C30.unk_1444.c1F = res->unk_7E;
    lbl_1_bss_3C30.unk_1444.time = ((lbl_801A66CC->unk_8B4 << 20) & 0xFF00000) | (lbl_801A66CC->unk_8B5 << 12) | lbl_801A66CC->unk_8B6;

    fn_1_1554D0();
    fn_1_1555B0(lbl_1_bss_8B3A0.unk_90);
    if (lbl_1_bss_26B08 < 10) {
        fn_1_155F9C(1);
        fn_1_155FA8(lbl_1_bss_26B08);
    } else {
        fn_1_155F9C(0);
        fn_1_155FA8(-1);
    }

    switch (fn_1_F1B84()) {
    case 1:
        if (fn_1_F2280(lbl_1_bss_3C30.unk_6) == 0) {
            lbl_1_bss_5138.unk_0 = 25;
            fn_1_F220C(lbl_1_bss_3C30.unk_6);
        }
        break;
    }

    if (fn_1_F2338(lbl_1_bss_3C30.unk_6, time) & 0xFF) {
        if (ghost_test_record_flag0(lbl_1_bss_3C30.unk_6) == 0) {
            lbl_1_bss_5138.unk_E3 = lbl_1_bss_3C30.unk_6;
            lbl_1_bss_5138.unk_0 = 10;
        }
    }
}
/* fzgx:end fn_1_31C3C */

/* fzgx:begin fn_1_320A4 */
/* fn_1_320A4: block-private types (p0b) */
/* GamePlayer: see GamePlayer */
/* Obj3C30: see Obj3C30 */
/* GameSlotEntry: see GameSlotEntry */
/* GameSlotTable: see GameSlotTable */

static inline s32 fn_1_320A4_grand(u8 mode)
{
    if (mode != 1) {
        return 0;
    }
    if (lbl_1_bss_3C30.unk_A7 < 4) {
        return 0;
    }
    return 1;
}

void fn_1_320A4(void)
{
    u32 flags;
    u8 mode;
    s32 r;

    flags = 0x2028;
    if (lbl_1_bss_3C30.unk_0 & 0x800000) {
        flags |= 0x180;
    }
    mode = lbl_1_bss_3C30.unk_5;
    if (mode == 1) {
        if (fn_1_320A4_grand(mode)) {
            flags |= 2;
            flags &= ~0x2000;
        } else {
            flags |= 4;
        }
        flags &= ~0x28;
    } else {
        flags |= 0x40;
        if (mode == 2) {
            flags |= 0x200;
        }
    }
    if (mode == 5) {
        flags &= ~0x180;
    }
    lbl_1_bss_5104 = -1;
    r = fn_1_2EBB8(flags, 2);
    lbl_1_data_5B70 = 0x1C2 - r;
    {
        f32 h = lbl_1_bss_25C30 / 2.0f;
        lbl_1_data_5B6C = 620.0f - h;
    }
    lbl_1_data_5B78 = 140.0f;
    game_set_pause_port();
    lbl_1_bss_26B14 = 1;
}
/* fzgx:end fn_1_320A4 */

/* fzgx:begin fn_1_32200 */
/* fn_1_32200: block-private types (p0b) */
/* Racer: see Racer */

/* one step of a player's countdown while out: cut to `start` once it is above `limit`, then count down */

static inline void fn_1_32200_countdown(Racer *racer, u16 limit, u16 start) {
    s8 player = racer->unk_475;
    u16 *timer;

    if (lbl_1_bss_50EC[player] > limit) {
        lbl_1_bss_50EC[player] = start;
        timer = &lbl_1_bss_50EC[racer->unk_475];
        lbl_1_bss_25B90++;
        if (lbl_1_bss_25B98 == 0) {
            if (lbl_1_bss_25B8C == NULL) {
                lbl_1_bss_25B8C = timer;
                lbl_1_bss_25B84 = 0;
            } else if (*lbl_1_bss_25B8C == 0 || lbl_1_bss_25B84 == 0) {
                lbl_1_bss_25B8C = timer;
                lbl_1_bss_25B84 = 0;
            }
        }
    } else {
        lbl_1_bss_50EC[player] -= lbl_1_bss_50EC[player] != 0;
    }
}

void fn_1_32200(Racer *racer, s32 port) {
    u8 mask;
    u8 cause;

    if (racer->unk_475 != -1) {
        mask = 1 << racer->unk_475;
        cause = 0xFF;
        if (racer->unk_0 & 0x10000000) {
            lbl_1_bss_26B18 |= mask;
            cause = 2;
        } else if (racer->unk_0 & 0x80) {
            lbl_1_bss_26B19 |= mask;
            cause = 0;
        } else if (racer->unk_0 & 0x800) {
            lbl_1_bss_26B1A |= mask;
            cause = 1;
        }
        switch (cause) {
        case 0:
            fn_1_32200_countdown(racer, 300, 300);
            break;
        case 1:
            fn_1_32200_countdown(racer, 300, 300);
            break;
        case 2:
            fn_1_32200_countdown(racer, 300, 300);
            break;
        default:
            fn_1_32200_countdown(racer, 60, 0);
            break;
        }
        if (lbl_1_data_5B7C != 5) {
            lbl_1_data_3D544[racer->unk_475] = 0;
        }
    }
    if (port != -1) {
        lbl_1_bss_26B1B |= 1 << port;
        if (racer->unk_58C & 0x10) {
            if (++racer->unk_5D9 > 60) {
                racer->unk_5D9 = 60;
                lbl_1_bss_26B1C |= 1 << port;
            }
        }
    }
    if (racer->unk_4 < lbl_1_bss_3C30.unk_8) {
        racer->unk_0 |= 0x08000000;
    }
    fn_1_2E928(racer);
}
/* fzgx:end fn_1_32200 */

/* fzgx:begin fn_1_32600 */
int fn_1_32600(Racer* obj) {
    s32 cond;
    f32 lim;
    f32 fv;
    s32 tmp_ra3;
    u32 lab_t0;

    if (!(lbl_1_bss_3C30.unk_0 & 0x00008000)) {
        if (obj->unk_0 & 0x08000000) {
            return 1;
        }
        if (obj->unk_58C & 0x00000010) {
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
            if (lbl_1_bss_3C30.unk_5 != 5) {
                if ((obj->unk_0 & 0x00000200) || obj->unk_17C < 1.0f) {
                    return 1;
                }
            } else {
                return 1;
            }
        }
    }

    if ((lbl_1_bss_3C30.unk_0 & 0x00040000) && lbl_1_bss_3C30.unk_A4 == 0) {
        fv = obj->unk_17C;
        if (lbl_1_bss_25B80 < 0x12c) {
            lim = 1.0f;
        } else if (lbl_1_bss_25B80 < 0x258) {
            lim = 10.0f;
        } else {
            lim = 100.0f;
            fv = 0.0f;
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

    if (((0x00080000) & lbl_1_bss_3C30.unk_0)) {
        obj->unk_0 |= 0x10000000;
        return 1;
    }
    if (!(obj->unk_0 & 0x00010200) && lbl_1_bss_25B98 > 0x1a4) {
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_32600 */

/* fzgx:begin fn_1_327F8 */
void fn_1_327F8(Racer *arg0, u32 arg1) {
    u8 *v0;
    s32 v1;
    u32 v5;
    u32 v2;
    u32 v3;

    v0 = (u8 *)arg0->unk_49C;
    v1 = arg0->unk_475;
    v2 = ((*(v0 + 0x174) << 20) | (*(v0 + 0x175) << 12)) | *(u16 *)(v0 + 0x176);
    v3 = ((*(v0 + 0x1e0) << 20) | (*(v0 + 0x1e1) << 12)) | *(u16 *)(v0 + 0x1e2);
    v5 = *(u32 *)(v0 + 0x118);

    if (arg0->unk_475 != -1) {
        if (v5 == 1 && ((*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_0 & 0x10) == 0) {
            fn_1_15E540(v1, lbl_1_bss_25B88);
        }
        if (v5 == ((*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_4 - 1) && (*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_5 != 3) {
            u32 a = (*((struct fn_1_327F8_lbl_1_bss_25B88 *)&lbl_1_bss_25B88)).unk_0;
            fn_1_15E5E4(arg0->unk_475, (void *)a);
        }
        fn_1_D07C4((u8)arg0->unk_475,
                   (((*(v0 + 0x1d4) << 20) | (*(v0 + 0x1d5) << 12)) | *(u16 *)(v0 + 0x1d6)));
        fn_1_CB404(arg0->unk_475);
    }
    if ((s32)arg1 != -1) {
        *((u8 *)&(*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)) + 0x1468 + arg1) = (u8)v5;
    }
    if (v5 < 8) {
        *((u32 *)((u8 *)&(*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)) + 0x12c) + arg0->unk_4 * 0x28 + v5) = v2;
    }
    if (arg0->unk_475 != -1) {
        fn_1_15E688(arg0->unk_475, v2, v5, lbl_1_bss_25B88);
    }
    if ((*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_1474 <= 0x50000 + 0x6ff4) {
        if ((arg0->unk_0 & 0x08000000) != 0) {
            v3 = 0;
        }
        if (*(v0 + 0x115) == 0) {
            if (v5 > (*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_13F4) {
                *(u32 *)((u8 *)&(*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)) + (((v5 - 1) & 3) << 2) + 0x13b4) = v3;
                (*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_13F4 = v5;
                fn_1_15E3E0(arg0->unk_475, v3);
            }
        } else {
            if (*(v0 + 0x115) == 1) {
                if (v5 > (*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_13F5) {
                    *(u32 *)((u8 *)&(*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)) + (((v5 - 1) & 3) << 2) + 0x13d4) = v3;
                    (*((struct fn_1_327F8_lbl_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_13F5 = v5;
                    fn_1_15E434((*((struct fn_1_327F8_lbl_1_bss_25B88 *)&lbl_1_bss_25B88)).unk_0);
                }
            }
            if (arg0->unk_475 != -1) {
                fn_1_15E330(arg0->unk_475, v3, (void *)((*((struct fn_1_327F8_lbl_1_bss_25B88 *)&lbl_1_bss_25B88)).unk_0));
            }
        }
    }
}
/* fzgx:end fn_1_327F8 */

/* fzgx:begin fn_1_32A40 */
/* fn_1_32A40: block-private types (p0b) */
/* Racer: see Racer */
typedef struct {
    u32 flags;
    u8 unk_4;
    u8 mode;
    u8 pad_6[2];
    u8 unk_8;
    u8 pad_9[3];
    u8 unk_C;
    u8 unk_D;
    u8 pad_E[0xA4 - 0xE];
    u16 unk_A4;
    u8 pad_A6[0x13F6 - 0xA6];
    u8 unk_13F6;
    u8 pad_13F7[3];
    u16 unk_13FA[4];
    u8 unk_1402;
    u8 unk_1403;
    u8 unk_1404;
    u8 pad_1405[0x1468 - 0x1405];
    u8 unk_1468[0xB];
    u8 unk_1473;
    u8 pad_1474[0x14BC - 0x1474];
} GameSub_32A40;

static void game_goal_slot(Racer *racer)
{
    s8 slot = racer->unk_475;

    if (slot != -1) {
        u8 mask = 1 << slot;
        if (!(lbl_1_bss_26B1E & mask)) {
            lbl_1_bss_26B1E |= mask;
            game_keep_goal_record(racer);
            if (lbl_1_bss_3C30.unk_5 == 5) {
                lbl_1_bss_50EC[racer->unk_475] = 180;
            } else {
                lbl_1_bss_50EC[racer->unk_475] = 480;
            }
            if (!(racer->unk_0 & 0x4000000)) {
                fn_1_8D894(racer);
            }
            {
                u16 *timer = &lbl_1_bss_50EC[racer->unk_475];
                lbl_1_bss_25B90++;
                if (lbl_1_bss_25B98 == 0) {
                    lbl_1_bss_25B8C = timer;
                    lbl_1_bss_25B84 = 1;
                }
            }
            if (lbl_1_bss_50FC == -1) {
                lbl_1_bss_50FC = racer->unk_475;
            }
            lbl_1_data_3D544[racer->unk_475] = 0;
        } else {
            lbl_1_bss_50EC[slot] -= lbl_1_bss_50EC[slot] != 0;
        }
    }
}

static void game_goal_flag(Racer *racer)
{
    if (!(lbl_1_bss_3C30.unk_0 & 0x800)) {
        lbl_1_bss_26B20[racer->unk_4] = 1;
    }
}

void fn_1_32A40(Racer *racer) {
    s8 idx;
    s32 a;
    s32 b;
    s32 c;
    RacerStatus status;

    idx = racer->unk_474;
    if (idx != -1 && !(lbl_1_bss_3C30.unk_0 & 0x800)) {
        status.flags = 0;
        status.unk_19 = racer->unk_6 % 5;
        status.unk_14 = 0.0f;
        a = (racer->unk_0 & 0x400) &&
            !(lbl_1_bss_26B1C & (1 << idx));
        b = 0;
        if (a) {
            if ((__rlwnm(lbl_1_bss_718E0[2], (32 - racer->unk_474) & 31, 31, 31))) {
                b = 1;
            }
        }
        c = 0;
        if (b && lbl_1_bss_3C2A != 42) {
            c = 1;
        }
        if (c) {
            if (racer->unk_0 & 0x8000) {
                status.flags |= 1;
            } else {
                status.flags &= ~1;
            }
            status.unk_0 = racer->unk_8;
            status.unk_C = racer->unk_17C;
            status.unk_4 = racer->unk_580;
            status.unk_8 = racer->unk_A4;
            status.unk_10 = racer->unk_224;
            if (racer->unk_0 & 0x400040) {
                status.flags |= 8;
            }
            if (racer->unk_0 & 0x10) {
                status.flags |= 4;
                status.unk_14 = racer->unk_BC;
            }
            if (racer->unk_0 & 0x2800000) {
                status.flags |= 0x10;
            }
            if ((racer->unk_218 >> 29) & 1) {
                status.flags |= 0x20;
            }
            if (racer->unk_0 & 0x80) {
                if (racer->unk_0 & 0x40000000) {
                    status.flags |= 0x40;
                }
                if (!(racer->unk_58C & 0x10) && racer->unk_50D == 0xEF) {
                    status.flags |= 2;
                }
                status.flags |= 0x80;
            }
        } else {
            status.unk_0 = 0.0f;
        }
        fn_1_1566F8(racer->unk_474, &status);
        fn_1_1567A8(racer->unk_474);
        if (lbl_1_bss_3C30.unk_5 == 2 && !(racer->unk_0 & 0x10000)) {
            if (!(lbl_1_bss_26B40 < racer->unk_184) &&
                100.0f == racer->unk_184 && racer->unk_18B != 0 &&
                !(racer->unk_218 & 0x8000000)) {
                racer->unk_58C |= 0x40;
            }
        }
    }

    if (!(lbl_1_bss_3C30.unk_0 & 0x200000)) {
        s32 player = racer->unk_474;

        if (racer->unk_0 & 0x10000) {
            game_goal_slot(racer);
            if (player != -1) {
                u8 mask = 1 << player;
                if (!(lbl_1_bss_50F4 & mask)) {
                    fn_1_F7338(player, 5, 0);
                }
                lbl_1_bss_50F4 |= mask;
                lbl_1_bss_3C30.unk_1468[player] = lbl_1_bss_3C30.unk_4;
                fn_1_156754(player);
            }
            game_goal_flag(racer);
            racer->unk_0 |= 1;
            fn_1_2E928(racer);
        } else if (fn_1_32600(racer)) {
            fn_1_32200(racer, player);
        } else {
            GameRaceRecord *info = racer->unk_49C;
            if (!(racer->unk_0 & 0x8000200) && (lbl_1_bss_3C30.unk_0 & 0x40000)) {
                u32 n = fn_1_8C884(racer->unk_4);
                u32 q;
                u32 rem;
                Obj3C30 *sub = &lbl_1_bss_3C30;
                if (sub->unk_1403 < n) {
                    s32 v;
                    q = n >> 2;
                    rem = n & 3;
                    if (q >= sub->unk_1404) {
                        q = sub->unk_1404 - 1;
                    }
                    v = lbl_1_bss_3C30.unk_13F8[rem + 1] - lbl_1_bss_3C30.unk_1402 * q * 60;
                    if (v < 0) {
                        v = 0;
                    }
                    if (v != 0) {
                        sub->unk_1403 = n;
                        lbl_1_bss_3C30.unk_A4 += v;
                        if (racer->unk_475 != -1) {
                            fn_1_15E764(racer->unk_475, lbl_1_bss_25B88);
                        }
                    }
                }
            }
            if (racer->unk_0 & 0x40000) {
                fn_1_327F8(racer, player);
            }
            if (racer->unk_475 != -1) {
                fn_1_D07AC((u8)racer->unk_475,
                           info->unk_16A | ((info->unk_168 << 20) | (info->unk_169 << 12)));
            }
        }

        if (lbl_1_bss_3C30.unk_5 == 2 && !(racer->unk_0 & 0x10000)) {
            if (racer->unk_58C & 0x40) {
                lbl_1_bss_3C30.unk_5 = 6;
            }
            lbl_1_bss_26B44 = racer->unk_184;
        }
        if (racer->unk_474 != -1 && lbl_1_bss_3C30.unk_5 == 1) {
            u8 k = racer->unk_482 / 5;
            if (!(lbl_1_bss_3C30.unk_0 & 0x800) && lbl_1_bss_3C30.unk_1473 == 0) {
                u8 d = k - lbl_1_bss_3C30.unk_1473;
                lbl_1_bss_3C30.unk_1473 = k;
                lbl_1_bss_3C30.unk_13F6 += d;
                if (d) {
                    fn_1_A2D84(0xA9092800);
                }
            }
        }
        if (!(lbl_1_bss_3C30.unk_0 & 0x20)) {
            u8 joined;
            u8 left;
            Obj3C30 *sub;
            s32 i;
            sub = &lbl_1_bss_3C30;
            joined = lbl_1_bss_50F4;
            sub->unk_C = 0;
            left = lbl_1_bss_26B1B;
            sub->unk_D = sub->unk_8;
            for (i = 0; i < 4; i++) {
                u32 mask = 1 << i;
                if (joined & mask) {
                    sub->unk_C++;
                }
                if (left & mask) {
                    sub->unk_D--;
                }
            }
        }
    }
}
/* fzgx:end fn_1_32A40 */

/* fzgx:begin fn_1_331EC */
/* fn_1_331EC: block-private types (p0b) */
/* Racer: see Racer */

#define GAME_MAIN_REL_GAME_TYPES_H

#define GAME_MAIN_REL_ADXT_STOP_TYPES_H

static inline f32 track_total(GameRaceRecord *t) {
 f32 distance=t->unk_11C*t->unk_FC;
 return t->unk_100+distance;
}

static void apply_handicap(Input *in, Racer *r, f32 diff) {
 if(diff>3000.0f) diff=3000.0f;
 diff*=0.00033333333f;
 in->fc += (f32)(1.1f*diff);
 in->f8 += (f32)(0.3f*diff);
 in->f10 += (f32)(0.3f*(in->f10*diff));
 in->f44 -= (f32)(0.7f*(in->f44*diff));
 in->f34 += (f32)(0.2f*(in->f34*diff));
 r->unk_4DC=1.0f-(f32)(0.2f*diff);
}

void fn_1_331EC(Racer *r) {
 Input in;
 s32 freeze=0;
 f32 diff;
 s16 slot,controller;
 s16 i;
 if (!(lbl_1_bss_3C30.unk_0 & 0x10) && r->unk_49C->unk_118 < 1) r->unk_0 &= ~0x40;
 if(lbl_1_bss_3C30.unk_D0) lbl_1_bss_3C30.unk_D0(&lbl_1_bss_3C30,r);
 if (lbl_1_bss_3C30.unk_A4) r->unk_0 &= ~0x10000000;
 if (lbl_1_bss_3C30.unk_5==2) {
  if (!(r->unk_0 & 0x10000) && (r->unk_184>100.0f || r->unk_184>lbl_1_bss_26B44)) r->unk_58C |=0x40;
  lbl_1_bss_26B40=r->unk_184;
 }
 if ((lbl_1_bss_3C30.unk_0&0x40000) && !lbl_1_bss_3C30.unk_A4 && !(r->unk_0&0x200)) {
  if(r->unk_17C<1.0f) r->unk_1FC=0.0f;
  r->unk_1F4=0.0f; r->unk_204=0.5f; r->unk_1F8=0.0f; r->unk_200=0.0f;
  r->unk_0 &= 0xfff7dfff; r->unk_0 &=0xfffdfff7; r->unk_0 |=0x10000000;
 } else if ((lbl_1_bss_3C30.unk_0&0x80) && !(r->unk_0&0x200)) {
  if(r->unk_17C<1.0f) r->unk_1FC=0.0f;
  r->unk_1F4=0.0f; r->unk_204=1.0f; r->unk_1F8=0.0f; r->unk_200=0.0f;
  r->unk_0 &=0xfff7dfff; r->unk_0 &=0xfffdfff7;
 } else if(lbl_1_bss_3C2A<=40) {
  r->unk_1FC=0.0f; r->unk_1F4=0.0f; r->unk_1F8=0.0f;
  if(lbl_1_bss_3C30.unk_0&0x100) {
   freeze=1; if(!(r->unk_0&0x20000000)) r->unk_200=0.6f;
   r->unk_204=0.0f; r->unk_0 &=0xfff7dfbf; r->unk_0 &=0xfffdfff7;
  }
 } else if(lbl_1_bss_3C30.unk_0&0x80000) {
  r->unk_1FC=0.0f; r->unk_1F4=0.0f; r->unk_204=0.3f; r->unk_1F8=0.0f; r->unk_200=0.0f;
  r->unk_0 &=0xfff7dfff; r->unk_0 &=0xfffdfff7;
 }
 if(lbl_1_bss_3C30.unk_5==2 && !(r->unk_0&0x10000) && (r->unk_58C&0x40)) lbl_1_bss_3C30.unk_5=6;
 if(r->unk_474!=-1 && lbl_1_bss_26B48 && !r->unk_590) {
  if(lbl_1_bss_3C30.unk_0&0x800000) {
   if(!fn_1_F2F34()) {
    r->unk_590=fn_1_3BB0(r->unk_474);
    (&lbl_1_bss_7EFD8.unk_38)[r->unk_4]=r->unk_590;
    (&lbl_1_bss_7EFD8.unk_3C)[r->unk_4]=lbl_1_data_2B60[r->unk_4];
    lbl_1_bss_D70[r->unk_4]=lbl_1_data_2B60[r->unk_4];
   } else {
    r->unk_590=(&lbl_1_bss_7EFD8.unk_38)[r->unk_4];
    lbl_1_bss_D70[r->unk_4]=(&lbl_1_bss_7EFD8.unk_3C)[r->unk_4];
   }
  } else {
   lbl_1_bss_D70[r->unk_4]=lbl_1_data_2B60[r->unk_4];
   r->unk_590=fn_1_3BB0(r->unk_474);
  }
 } else if(!(lbl_1_bss_3C30.unk_0&0x800) && lbl_1_bss_26B48 && r->unk_474!=-1) {
  s8 state=fn_1_3BB0(r->unk_474);
  if(state && r->unk_590!=state) {lbl_1_bss_5224=1; r->unk_590=state;}
 }
 controller=r->unk_474; slot=r->unk_6;
 if(controller==-1) {
  for(i=0;i<4;i++) {
   if(r->unk_4==fn_1_84794(i)) {controller=i;break;}
  }
 }
 fn_1_82EDC(controller,slot,&in);
 if(freeze && !(r->unk_0&0x4000000)) { r->unk_220=in.f8; r->unk_22C=in.fc; }
 else {
  GameEntrant *p=lbl_1_bss_53F8[r->unk_4];
  if(p) { f32 v = p->unk_B; v *= 0.01f; fn_1_22B10(&in,v); }
  else { f32 v = lbl_1_bss_25C48[r->unk_4]; v *= 0.01f; fn_1_22B10(&in,v); }
 }
 if(lbl_1_bss_3C30.unk_0&0x20000) {
  GameRaceRecord *t=lbl_1_bss_3C30.unk_2C[0];
  if(!(r->unk_0&0x4000200)) {
   f32 a,b;
   apply_handicap(&in,r,track_total(t)-track_total(r->unk_49C));
  }
 }
 if(!(r->unk_0&0x4000000) && !freeze) fn_1_22E8C(r,&in);
 if(lbl_1_bss_3C30.unk_0&0x8000) r->unk_0 |=1;
 if(lbl_1_bss_26B20[r->unk_4] && lbl_1_bss_3C2A==42) r->unk_0 |=1;
}
/* fzgx:end fn_1_331EC */

/* fzgx:begin fn_1_33890 */
int fn_1_33890(Obj3C30 *arg0) {
    u8 count;
    u8 limit;
    u32 flags;

    if (lbl_1_bss_25BA0 != 0) {
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
            if (lbl_1_bss_25B84 != 0) {
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
    } else if (lbl_1_bss_3C30.unk_A == 0) {
        return -1;
    }

    if ((flags & 0x04000000) == 0 && lbl_1_bss_3C30.unk_1474 > 0x57030) {
        lbl_1_bss_3C30.unk_0 |= 0x80000;
        return -1;
    }
    return 0;
}
/* fzgx:end fn_1_33890 */

/* fzgx:begin fn_1_33A20 */
/* fn_1_33A20: block-private types (p0b) */
/* GamePlayer: see GamePlayer */
/* Obj3C30: see Obj3C30 */
/* GameSlotEntry: see GameSlotEntry */
/* GameSlotTable: see GameSlotTable */

u32 lbl_1_bss_26B4C = 0;

void fn_1_33A20(void)
{
    Obj3C30 *gs;
    s32 code;
    s32 j;

    if (lbl_1_bss_25BF8 > 0.0f) {
        for (j = 0; j < 4; j++) {
            fn_1_156754(j);
        }
    }
    fn_1_2FAA0();
    if (lbl_1_bss_25BEA != 0) {
        return;
    }
    if (!(lbl_1_bss_3C30.unk_0 & 0x800)) {
        lbl_1_bss_26B50 = 1;
    }
    code = -2;
    if (lbl_1_bss_25BEA == 0) {
        code = lbl_1_bss_25BEC;
    }
    if (code == -2) {
        return;
    }
    lbl_1_bss_3C30.unk_0 &= ~2;
    switch (code) {
    case 2:
        if (lbl_1_bss_25BA0 != 0) {
            return;
        }
        fn_1_2DE00(1);
        lbl_1_bss_3C30.unk_7 = 0xE;
        fn_1_304A8();
        return;
    case 0x10:
        lbl_1_bss_26B54[0] = 1;
        if (lbl_1_bss_25BEC == -2) {
            return;
        }
        lbl_1_bss_3C30.unk_0 |= 2;
        for (j = 13; j > 0; j--) {
            if (lbl_1_bss_25BEC & (1 << j)) {
                lbl_1_bss_5104 = j;
                return;
            }
        }
        for (j = 0; j < 14; j++) {
            if (lbl_1_bss_25BE6 & (1 << j)) {
                lbl_1_bss_5104 = j;
                return;
            }
        }
        return;
    case 4:
        game_goto_next_stage();
        return;
    case 8:
        game_restart(0);
        return;
    case 0x80:
        game_restart(1);
        return;
    case 0x20:
        game_goto_setting();
        return;
    case 0x40:
        if (lbl_1_bss_25BA0 != 0) {
            return;
        }
        lbl_1_bss_53F4 = 1;
        lbl_1_bss_8B3A0.unk_94 |= 0x20;
        fn_1_4A00(0, 0x1E, lbl_1_bss_5100);
        lbl_1_bss_6EAB4.unk_0 |= 0x2C;
        lbl_1_bss_25BA0 = 1;
        if (lbl_1_bss_3C30.unk_5 == 0) {
            lbl_1_data_5B84 = 0;
        }
        fn_1_8DBA4(0);
        return;
    case 0x400:
        lbl_1_bss_26B58 = 1;
        return;
    case 0x800:
        {
            u8 i;

            gs = &lbl_1_bss_3C30;
            for (i = 0; i < gs->unk_8; i++) {
                game_keep_goal_record(fn_1_86254(i));
            }
        }
        lbl_1_bss_50E8 = 0x2A;
        lbl_1_bss_50EC[0] = 0;
        lbl_1_bss_26B1E |= 1;
        lbl_1_bss_50F4 |= 1;
        lbl_1_bss_50F8 = 0;
        lbl_1_bss_3C30.unk_0 |= 0x1000;
        lbl_1_bss_50FC = 0;
        fn_1_EB080(4);
        return;
    case 0x1000:
        fn_1_D3474();
        return;
    case 0x2000:
        fn_1_304A8();
        return;
    case 0x100:
        fn_1_F3BC0();
        fn_1_154CC4(0);
        if (lbl_1_bss_25BEC == -2) {
            return;
        }
        lbl_1_bss_3C30.unk_0 |= 2;
        for (j = 13; j > 0; j--) {
            if (lbl_1_bss_25BEC & (1 << j)) {
                lbl_1_bss_5104 = j;
                return;
            }
        }
        for (j = 0; j < 14; j++) {
            if (lbl_1_bss_25BE6 & (1 << j)) {
                lbl_1_bss_5104 = j;
                return;
            }
        }
        return;
    case 0x200:
        fn_1_EB080(0xB);
        if (lbl_1_bss_25BEC == -2) {
            return;
        }
        lbl_1_bss_3C30.unk_0 |= 2;
        for (j = 13; j > 0; j--) {
            if (lbl_1_bss_25BEC & (1 << j)) {
                lbl_1_bss_5104 = j;
                return;
            }
        }
        for (j = 0; j < 14; j++) {
            if (lbl_1_bss_25BE6 & (1 << j)) {
                lbl_1_bss_5104 = j;
                return;
            }
        }
        return;
    case 1:
    case 3:
        break;
    }
    if ((lbl_1_bss_3C30.unk_0 & 0x00800000) && !(lbl_1_bss_3C30.unk_0 & 0x800)) {
        fn_1_F2EFC();
    }
    lbl_1_bss_50F8 = 0;
    fn_1_A0D20();
}
/* fzgx:end fn_1_33A20 */

/* fzgx:begin fn_1_34924 */
void fn_1_34924(u16 *timer) {
    s8 i;

    if (fn_1_EB200() != 0) {
        return;
    }
    if (!(lbl_1_bss_3C30.unk_0 & 0x800) && lbl_1_bss_5104 != -1) {
        return;
    }
    if (--*timer != 0) {
        if (*timer > 60 && *timer < 240) {
            fn_1_4310(0);
            lbl_1_bss_3C30.unk_0 |= 0x4000;
            if (lbl_1_bss_3C30.unk_0 & 0x800000) {
                if (*timer == 239) {
                    fn_1_F2EB8();
                    lbl_1_bss_26B48 = 1;
                }
            } else {
                lbl_1_bss_26B48 = 1;
            }
        }
        fn_1_A4F18(*timer / 60);
    } else {
        fn_1_4060();
        lbl_1_bss_25E7C = -1;
        fn_1_435C(lbl_1_bss_25B88);
        if (lbl_1_bss_25E80 != -1) {
            fn_1_426C(lbl_1_bss_25E80);
            fn_1_105724();
        }
        lbl_1_bss_25E80 = -1;
        fn_1_435C(lbl_1_bss_25CA4);
        if (lbl_1_bss_25E84 != -1) {
            fn_1_426C(lbl_1_bss_25E84);
        }
        lbl_1_bss_25E84 = -1;
        if (lbl_1_bss_3C30.unk_0 & 0x10) {
            for (i = 0; i < lbl_1_bss_3C30.unk_8; i++) {
                s8 v = fn_1_86254(i)->unk_475;
                if (v != -1) {
                    fn_1_15E540(v, lbl_1_bss_25B88);
                }
            }
        }
    }
}
/* fzgx:end fn_1_34924 */

/* fzgx:begin fn_1_34AC0 */
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

/* fzgx:begin fn_1_34E08 */
void fn_1_34E08(void) {
    char path[32];
    s16 i;
    char name[32];
    s16 count;

    count = lbl_1_bss_8B3A0.unk_C[0].unk_2;
    if (count > 40) {
        RaceBuf *race = fn_1_36AD0();
        count = 50;
        if (!(race->unk_0 & 0x40000000)) {
            count = race->unk_81A0;
        }
    }
    lbl_1_bss_26B5C[0] = count;
    fn_1_34AC0(lbl_1_bss_26B5C, 1, 30, 1);
    fn_1_8001C();
    fn_1_12AB38("vehicle/");
    fn_1_465D0("carcmntex.tpl", 1);
    for (i = 0; i < 30; i++) {
        if (i == 0) {
            sprintf(path, "%s_p.arc.lz", fn_1_7F518(lbl_1_bss_26B5C[i], name, 0));
        } else {
            sprintf(path, "%s_e.arc.lz", fn_1_7F518(lbl_1_bss_26B5C[i], name, 0));
        }
        fn_1_465D0(path, 1);
    }
    fn_1_12AB38("..");
}
/* fzgx:end fn_1_34E08 */

/* fzgx:begin fn_1_34F38 */
/* Inlined in retail fn_1_36B10 (the only copy). Its place: .rodata E28 450.0f sits between the literals of fn_1_331EC
   and the table of fn_1_34F38. */
static void game_replay_menu_place(void)
{
    lbl_1_data_5B70 = 450.0f - lbl_1_bss_25C34;
    {
        f32 h;
        h = lbl_1_bss_25C30 / 2.0f;
        lbl_1_data_5B6C = 620.0f - h;
    }
}

static const u16 lbl_1_rodata_E2C[4] = { 0, 1, 2, 3 };

static inline void sound_slot_pick(s32 i)
{
    if (lbl_1_bss_3C30.unk_8 > i) {
        Racer *racer = fn_1_86254(i);

        if (racer->unk_8 <= 1100.0f) {
            lbl_1_bss_6F1E4[i].unk_8 = 4;
        } else if (racer->unk_8 <= 1900.0f) {
            lbl_1_bss_6F1E4[i].unk_8 = 0;
        } else {
            lbl_1_bss_6F1E4[i].unk_8 = 5;
        }
    } else {
        lbl_1_bss_6F1E4[i].unk_8 = lbl_1_rodata_E2C[i];
    }
}

void fn_1_34F38(InitObj *obj)
{
    s8 i;

    if (obj != NULL) {
        if (obj->unk_0 == 0) {
            obj->unk_0 = fn_8004CD70(2, obj->unk_10, sizeof(obj->unk_10));
        }
        if (obj->unk_4 == 0) {
            obj->unk_4 = fn_8004CD70(2, obj->unk_4A258, sizeof(obj->unk_4A258));
        }
    }
    fn_1_A2E24(0x10, 0xA0100000, 0x7F);
    fn_1_A2E24(0x10, 0xA0110000, 0);
    fn_80067344(1, 0xF, 0xB0270000, 0x7F);
    for (i = 0; i < 4; i++) {
        sound_slot_pick(i);
        fn_1_A2DF4(i, 0xA5000000, lbl_1_bss_6F1E4[i].unk_8);
    }
    fn_1_A2DF4(4, 0xA5000000, 10);
    fn_1_A2DF4(5, 0xA5000000, 9);
    fn_1_A2DF4(7, 0xA5000000, 6);
    fn_1_A2DF4(6, 0xA5000000, 7);
    for (i = 0; i < 16; i++) {
        fn_1_A2DF4(i, 0xA6000000, 0);
        fn_1_A2DF4(i, 0xA5100000, 0);
    }
    fn_1_4030(fn_1_35124);
}
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
                    if (lbl_1_bss_26B7A == -1 ||
                        lbl_1_bss_26300 == -1) {
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

/* fzgx:begin fn_1_3522C */
u8 lbl_1_data_644B = 1;
u8 lbl_1_bss_26B7C = 0;

/* Static helper: inlined copies in fn_1_3522C and fn_1_39420. Its strings (.data 644C..6480) sit before the
   strings of fn_1_3522C. */
static void game_start_burner(void)
{
    u32 saved;

    saved = fn_80008E84(lbl_1_bss_262F8);
    fn_1_981C4();
    game_heap_report(lbl_801A6410);
    fn_1_435C(lbl_1_bss_25B88);
    fn_1_3F8C("Burner", fn_1_98230, 0, 10);
    fn_1_435C(lbl_1_bss_25CA4);
    fn_1_3F8C("BurnerDisp", fn_1_9835C, 0, 21);
    fn_1_12AF50(saved);
    fn_1_82724(lbl_1_bss_25B88, lbl_1_bss_25CA4, lbl_1_bss_25E9C, lbl_1_bss_3C30.unk_9, 1);
    fn_1_12AF64();
    fn_1_835E0(&lbl_1_bss_3C30, lbl_1_bss_25B88, fn_1_32A40);
    fn_1_8176C(fn_1_331EC);
    fn_80008E84(saved);
    fn_1_14A00C();
    fn_1_435C(lbl_1_bss_25B88);
    fn_1_3F8C("GameResultCtrl", fn_1_14A028, &lbl_1_bss_3C30, 25);
    fn_1_435C(lbl_1_bss_25CA4);
    fn_1_3F8C("GameResultDisp", fn_1_15C36C, &lbl_1_bss_3C30, 28);
    fn_1_435C(lbl_1_bss_25CA4);
    fn_1_8DBB0();
    fn_1_3F8C("SetAllCarLOD", fn_1_8DD54, 0, 1);
}

static void game_set_rival_machines(void) {
    s32 i;

    for (i = lbl_1_bss_3C00; i < lbl_1_bss_3C30.unk_9; i++) {
        lbl_1_bss_2625C[i] = lbl_1_bss_26B80[i][1];
        lbl_1_bss_523C[i] = 0x10;
    }
}

s8 lbl_1_bss_26C16 = 0;
u32 lbl_1_bss_26C18 = 0;

static inline void game_reset_order(void) {
    s32 i;

    lbl_1_bss_3C30.unk_A = lbl_1_bss_3C30.unk_9;
    lbl_1_bss_3C30.unk_C = lbl_1_bss_3C30.unk_B = i = 0;
    lbl_1_bss_3C30.unk_5 = lbl_1_data_5B7C;
    lbl_1_bss_3C30.unk_D = lbl_1_bss_3C30.unk_8;
    for (; i < lbl_1_bss_3C30.unk_9; i++) {
        lbl_1_bss_3C30.unk_E[i] = i;
    }
}

void fn_1_3522C(void) {
    u8 *port;
    s32 i;
    s32 random;
    u32 created;

    lbl_1_bss_3C30.unk_8 = lbl_1_bss_3C00;
    if (lbl_1_bss_3C30.unk_9 > 30) {
        lbl_1_bss_3C30.unk_9 = 30;
    } else if (lbl_1_bss_3C00 > lbl_1_bss_3C30.unk_9) {
        lbl_1_bss_3C30.unk_9 = lbl_1_bss_3C00;
    }
    game_reset_order();
    if (lbl_1_bss_960 == 12 || lbl_1_bss_962 == 160) {
        for (i = 0, port = lbl_1_bss_25E98; i < lbl_1_bss_3C00; port++, i++) {
            fn_1_81834(i, *port, i);
        }
        game_set_rival_machines();
    } else {
        if (lbl_1_bss_3C00) {
            for (i = 0, port = lbl_1_bss_25E98; i < lbl_1_bss_3C00; port++, i++) {
                fn_1_81834(i, *port, i);
            }
        } else {
            fn_1_81834(0, -1, 0);
            if (lbl_1_bss_960 == 2) {
                lbl_1_bss_2625C[0] = 6;
            } else if (lbl_1_bss_960 == 10) {
                if (lbl_1_data_644B) {
                    lbl_1_bss_2625C[0] = 6;
                    lbl_1_data_644B = 0;
                } else {
                    lbl_801A63C0 = lbl_801A63C0 * 0x676a4b6b + 0x33cb;
                    random = (lbl_801A63C0 >> 16) & 0x7fff;
                    lbl_1_bss_2625C[0] = random % lbl_1_bss_3C30.unk_9;
                }
            } else {
                lbl_801A63C0 = lbl_801A63C0 * 0x676a4b6b + 0x33cb;
                random = (lbl_801A63C0 >> 16) & 0x7fff;
                lbl_1_bss_2625C[0] = random % lbl_1_bss_3C30.unk_9;
            }
            lbl_1_bss_523C[0] = 0x10;
            lbl_1_bss_25C48[0] = 50;
        }
        if (lbl_1_bss_960 == 2 && lbl_1_data_5B7C == 1) {
            fn_80008BA8(lbl_1_bss_2625C, lbl_1_bss_26B5C, 30);
        } else {
            fn_1_34AC0(lbl_1_bss_2625C, lbl_1_bss_3C00 + lbl_1_bss_26B7C, lbl_1_bss_3C30.unk_9, 0);
        }
    }
    fn_1_3181C();
    game_heap_report(lbl_801A6410);
    if (lbl_1_bss_3C30.unk_8 < 2 && lbl_1_bss_960 != 10 && lbl_1_bss_960 != 12) {
        lbl_1_bss_25CC8 = 1;
    } else {
        lbl_1_bss_25CC8 = 0;
    }
    fn_1_584D4();
    fn_1_435C(lbl_1_bss_25B88);
    lbl_1_bss_26B7A = fn_1_3F8C("dummy_count_up", fn_1_2C768, &lbl_1_bss_3C30.unk_14A8, 13);
    if (!(lbl_1_bss_3C30.unk_0 & 0x1000000)) {
        fn_1_435C(lbl_1_bss_25B88);
        fn_1_3F8C("Effect", fn_1_58694, 0, 11);
        fn_1_435C(lbl_1_bss_25CA4);
        fn_1_3F8C("EffectDispBefore", fn_1_58C6C, 0, 0);
        fn_1_435C(lbl_1_bss_25CA4);
        fn_1_3F8C("EffectDisp", fn_1_58994, 0, 22);
        fn_1_435C(lbl_1_bss_25CA4);
        fn_1_3F8C("EffectDispAfter", fn_1_58D38, 0, 27);
    }
    if (lbl_1_bss_960 != 10 && lbl_1_bss_960 != 12) {
        fn_1_128F10();
        fn_1_435C(lbl_1_bss_25B88);
        fn_1_3F8C("Check", fn_1_128F54, 0, 12);
        fn_1_435C(lbl_1_bss_25CA4);
        fn_1_3F8C("CheckDisp", fn_1_12907C, 0, 22);
        game_heap_report(lbl_801A6410);
    }
    created = fn_1_7BA08(32, 32, 64);
    lbl_1_bss_3C24 = fn_1_45D0(lbl_801A6410, created, "game.c", 0x17af);
    fn_1_7BA48();
    fn_1_435C(lbl_1_bss_25CA4);
    fn_1_3F8C("LightMain", fn_1_7BAF8, (void *)lbl_1_bss_3C24, 3);
    game_heap_report(lbl_801A6410);
    fn_1_435C(lbl_1_bss_25CA4);
    fn_1_3F8C("DrawOrdSys", fn_1_545B8, 0, 25);
    fn_1_3F8C("FogOff", fn_1_7EAE8, 0, 29);
    camera_set_state_flag(1);
    fn_1_5124(lbl_1_bss_25B88, lbl_1_bss_25CA4);
    fn_1_5370(3, 0);
    game_heap_report(lbl_801A6410);
    fn_1_9A578();
    if (lbl_1_bss_960 == 10 || (lbl_1_bss_960 == 2 && lbl_1_data_5B7C == 1)) {
        game_start_burner();
    }
    lbl_1_bss_26C1C = 1;
    lbl_1_bss_26B50 = 0;
    lbl_1_bss_25E6C = 0;
    lbl_1_bss_25E70 = 0;
    lbl_1_bss_25E78 = 0;
    lbl_1_bss_25BF0 = 0;
    lbl_1_bss_26C16 = 0;
    fn_1_435C(lbl_1_bss_5100);
    fn_1_3F8C("game_menu_disp", fn_1_2F294, 0, 30);
    fn_1_4068C(&lbl_1_bss_5108);
    lbl_1_bss_5108.flags &= ~1;
    fn_1_3F8C("GameMenuWidgetDisp", fn_1_408E8, &lbl_1_bss_5108, 30);
    game_message_box_reset();
    fn_1_3F8C("disp_fail_record", fn_1_2D038, 0, 1);
}
/* fzgx:end fn_1_3522C */

/* fzgx:begin fn_1_359B8 */
/* fn_1_359B8: block-private types (p0b) */
/* Obj3C30: see Obj3C30 */
/* RaceBuf: see RaceBuf */

void fn_1_359B8(void) {
    s32 i;

    lbl_1_bss_17AC = 1;
    fn_1_789AC();
    fn_1_56B8();
    fn_1_9A578();
    fn_1_59290();
    fn_1_87074();
    fn_1_98590();
    lbl_1_bss_26B48 = 0;
    lbl_1_bss_26B1E = 0;
    lbl_1_bss_50F4 = 0;
    lbl_1_bss_26B19 = 0;
    lbl_1_bss_26B1A = 0;
    lbl_1_bss_26B1B = 0;
    lbl_1_bss_26B18 = 0;
    for (i = 0; i < 4; i++) {
        lbl_1_bss_50EC[i] = 0xFFFF;
        lbl_1_bss_26304[i] = 0.0f;
        lbl_1_bss_3C30.unk_1468[i] = 0;
    }
    for (i = 0; i < 3; i++) {
        lbl_1_bss_3C30.unk_13B4[i] = 0;
        lbl_1_bss_3C30.unk_13D4[i] = 0;
    }
    lbl_1_bss_3C30.unk_13F4 = 0;
    lbl_1_bss_3C30.unk_13F5 = 0;
    lbl_1_bss_3C30.unk_1405 = 0;
    lbl_1_bss_3C30.unk_0 &= 0xFFF7BF59;
    fn_1_15E27C();
    lbl_1_bss_8E51D = 0;
    if (!(lbl_1_bss_3C30.unk_0 & 0x800)) {
        fn_1_2E268();
    }
    for (i = 0; i < lbl_1_bss_3C30.unk_9; i++) {
        lbl_1_bss_3C30.unk_E[fn_1_86810(i)] = i;
    }
    if (!(lbl_1_bss_3C30.unk_0 & 0x800)) {
        for (i = 0; i < lbl_1_bss_3C30.unk_9; i++) {
            lbl_1_bss_26B20[i] = 0;
        }
    }
}
/* fzgx:end fn_1_359B8 */

/* fzgx:begin fn_1_35BC4 */
/* fn_1_35BC4: block-private types (p0b) */
/* GamePlayer: see GamePlayer */
/* Obj3C30: see Obj3C30 */
/* GameSlotEntry: see GameSlotEntry */
/* GameSlotTable: see GameSlotTable */

void fn_1_35BC4(void)
{
    u32 result;
    Obj3C30 *st;

    fn_1_3F75C();
    if (lbl_1_bss_960 != 10 && lbl_1_bss_960 != 12) {
        fn_1_46A8C(lbl_1_bss_8B5F4.unk_14);
    }
    lbl_801A63C0 = lbl_1_bss_25E68 ^ 0xCAE87FB5;
    if (lbl_1_bss_25CC8 != 0) {
        lbl_1_bss_25E88 = 1;
        fn_1_D1848();
        if (lbl_1_data_5B88 == -1) {
            fn_1_435C(lbl_1_bss_25B88);
            lbl_1_data_5B88 = fn_1_3F8C("Face", fn_1_D2404, 0, 0xC);
        }
        if (lbl_1_data_5B8C[0] == -1) {
            fn_1_435C(lbl_1_bss_25CA4);
            lbl_1_data_5B8C[0] = fn_1_3F8C("FaceDisp", fn_1_D27B8, 0, 0);
        }
        fn_1_D2FB0();
    }
    lbl_1_bss_7F04C = 0;
    if (lbl_1_bss_3C30.unk_0 & 0x00800000) {
        if (lbl_1_bss_960 != 10 && lbl_1_bss_960 != 12 && fn_1_F2F34() == 0) {
            fn_1_435C(lbl_1_bss_25B88);
            fn_1_F70D0();
            lbl_1_bss_7F04C = fn_1_3F8C("RumbleMain", fn_1_F7128, 0, 0x1F);
        }
    } else if (lbl_1_bss_960 != 10 && lbl_1_bss_960 != 12) {
        fn_1_435C(lbl_1_bss_25B88);
        fn_1_F70D0();
        lbl_1_bss_7F04C = fn_1_3F8C("RumbleMain", fn_1_F7128, 0, 0x1F);
    }
    lbl_1_bss_3C30.unk_0 &= ~0x800;
    if (lbl_1_bss_3C30.unk_0 & 0x00800000) {
        if (fn_1_F2F34() != 0) {
            lbl_1_bss_3C30.unk_0 |= 0x800;
            if (lbl_1_bss_960 == 12) {
                lbl_1_bss_50FC = 0;
            }
            fn_1_5370(1, lbl_1_bss_50FC);
        } else {
            lbl_1_bss_3C30.unk_0 &= ~0x1800;
            lbl_1_bss_5234 = 0;
        }
    } else {
        lbl_1_bss_3C30.unk_0 &= ~0x1800;
    }
    fn_1_435C(lbl_1_bss_25B88);
    fn_1_861B4();
    fn_1_8DAB4();
    st = &lbl_1_bss_3C30;
    if (st->unk_A7 != 0) {
        fn_1_8589C(st);
    } else {
        fn_1_8589C(NULL);
    }
    if (!(lbl_1_bss_3C30.unk_0 & 0x100)) {
        fn_1_8616C();
    } else {
        fn_1_86194(1000.0f);
    }
    lbl_1_bss_25B9C = 0;
    if (lbl_1_bss_3C30.unk_C8 != NULL) {
        result = lbl_1_bss_3C30.unk_C8(&lbl_1_bss_3C30);
        if (result & 4) {
            lbl_1_bss_25B9C = 1;
        }
        if (result & 2) {
            fn_1_304A8();
        }
        if (result & 1) {
            return;
        }
    }
    if (!(lbl_1_bss_3C30.unk_0 & 0x100)) {
        fn_1_81778();
    }
    fn_1_359B8();
    if (lbl_1_bss_25CC8 != 0) {
        fn_1_D1C94();
        game_heap_report(lbl_801A6410);
    }
    lbl_1_bss_26C20 = 0;
    lbl_1_bss_5224 = 0;
    lbl_1_bss_26C24 = 0;
    lbl_1_bss_26B1D = 0;
    lbl_1_bss_25E7C = -1;
    lbl_1_bss_25E80 = -1;
    lbl_1_bss_25E84 = -1;
    lbl_1_bss_50F8 = 0;
    lbl_1_bss_25BA0 = 0;
    lbl_1_bss_5104 = -1;
    lbl_1_bss_25E78 = 0;
    lbl_1_bss_25B90 = 0;
    lbl_1_bss_25B8C = 0;
    lbl_1_bss_25B84 = 0;
    lbl_1_bss_50FC = -1;
    lbl_1_bss_25B94 = 0xFFFF;
    lbl_1_bss_25E94 = 0;
    lbl_1_bss_25BF8 = 0.0f;
    lbl_1_bss_25B80 = 0;
    lbl_1_bss_25B98 = 0;
    lbl_1_bss_26B40 = 100.0f;
    lbl_1_bss_26B44 = 100.0f;
    lbl_801A66CC->unk_8B4 = 0;
    lbl_801A66CC->unk_8B5 = 0;
    lbl_801A66CC->unk_8B6 = 0;
    lbl_1_bss_26B1C = 0;
    fn_1_1280(1);
    lbl_1_bss_3C30.unk_0 &= 0xFFF7BF59;
    lbl_1_bss_3C30.unk_A = lbl_1_bss_3C30.unk_9;
    lbl_1_bss_3C30.unk_B = 0;
    lbl_1_bss_3C30.unk_C = 0;
    lbl_1_bss_3C30.unk_D = lbl_1_bss_3C30.unk_8;
    lbl_1_bss_3C30.unk_A4 = lbl_1_bss_3C30.unk_13F8[0];
    lbl_1_bss_3C30.unk_1403 = 0;
    lbl_1_bss_3C30.unk_1473 = 0;
    lbl_1_bss_3C30.unk_1474 = 0;
    lbl_1_bss_3C30.unk_1490 = OSGetTime();
    lbl_1_bss_3C30.unk_14A8 = 0;
    if (lbl_1_bss_3C30.unk_5 != 1) {
        st->unk_A7 = 0;
    }
    if (!(lbl_1_bss_3C30.unk_0 & 1)) {
        fn_1_435C(lbl_1_bss_25B88);
        if (!(lbl_1_bss_3C30.unk_0 & 0x100)) {
            fn_1_4310(0x2C0);
        } else {
            fn_1_4310(0);
        }
    }
    fn_1_C6F80(1);
    fn_1_4A00(1, 0x1E, lbl_1_bss_5100);
}
/* fzgx:end fn_1_35BC4 */

/* fzgx:begin fn_1_36330 */
/* fn_1_36330: block-private types (p0b) */
/* Obj3C30: see Obj3C30 */

s32 lbl_1_bss_26C28 = 0;

void fn_1_36330(void) {
    u32 heap;
    s16 mode;

    lbl_1_bss_3C12 = 1;
    fn_1_4CC0();
    fn_1_3F75C();
    mode = lbl_1_bss_960;
    if (mode != 10 && mode != 12 && (mode != 2 || lbl_1_data_5B7C != 1)) {
        fn_1_46EE8();
    }
    lbl_1_bss_26C2C = 0;
    if (lbl_1_bss_3C10 == 0) {
        lbl_1_bss_26C30 = fn_1_451C();
        lbl_1_bss_962 = 0x24;
    } else {
        lbl_1_bss_26C30 = lbl_801A6410;
    }
    heap = lbl_1_bss_26C30;
    game_save_heap_free(heap);
    fn_1_A8F78();
    lbl_1_bss_25B88 = fn_1_45D0(lbl_801A6410, 0x215C, "game.c", 0x1991);
    lbl_1_bss_25CA4 = fn_1_45D0(lbl_801A6410, 0x161C, "game.c", 0x1992);
    lbl_1_bss_5100 = fn_1_45D0(lbl_801A6410, 0x80C, "game.c", 0x1993);
    fn_1_3CF0(lbl_1_bss_5100, 20);
    fn_1_3CF0(lbl_1_bss_25B88, 200);
    fn_1_4310(0x2C0);
    fn_1_3CF0(lbl_1_bss_25CA4, 120);
    game_heap_report(lbl_801A6410);
    fn_1_41048();
    game_heap_report(lbl_801A6410);
    if (lbl_1_data_5B7C == 1) {
        lbl_1_bss_26C34 = (GXGetTexBufferSize(320, 224, 1, 0, 0) + 0x1F) & ~0x1F;
        lbl_1_bss_3C1C = (void *)fn_1_45D0(lbl_801A6410, lbl_1_bss_26C34, "game.c", 0x19A4);
        DCInvalidateRange(lbl_1_bss_3C1C, lbl_1_bss_26C34);
    }
    heap = fn_1_44A4();
    game_save_heap_free(heap);
    fn_1_435C(lbl_1_bss_25B88);
    fn_1_A0680();
    lbl_1_bss_26C38 = fn_1_3F8C("sound_init", fn_1_34F38, lbl_1_bss_6EAD0.unk_0, 5);
    fn_1_4010(lbl_1_bss_26C38, fn_1_3514C);
    fn_1_44A4();
    if (lbl_1_data_5B7C == 5) {
        lbl_1_bss_26C3C = lbl_1_rodata_0[(s8)lbl_1_bss_9C] + 0x630000;
    } else if (lbl_1_data_5B7C == 0) {
        lbl_1_bss_26C3C = 0xA00000;
    } else {
        lbl_1_bss_26C3C = 0x630000;
    }
    lbl_1_bss_26C40 = fn_1_4630(lbl_801A6410, lbl_1_bss_26C3C, "game.c", 0x19C4);
    heap = lbl_1_bss_25CCC =
        fn_80008F88(lbl_1_bss_26C40, lbl_1_bss_26C40 + lbl_1_bss_26C3C);
    game_heap_report(lbl_801A6410);
    game_save_heap_free(heap);
    if (lbl_1_bss_962 == 0xA0 || lbl_1_bss_962 == 0xA2) {
        lbl_1_bss_26C44 = 0x480CC0;
    } else if (lbl_1_bss_962 == 0xA3) {
        lbl_1_bss_26C44 = 0x300880;
    } else if (lbl_1_data_5B7C == 0) {
        lbl_1_bss_26C44 = 0x231100;
    } else if (lbl_1_data_5B7C == 2) {
        lbl_1_bss_26C44 = 0x190440;
    } else if (lbl_1_data_5B7C == 5) {
        lbl_1_bss_26C44 = lbl_1_rodata_28[(s8)lbl_1_bss_9C] + 0x601100;
    } else {
        lbl_1_bss_26C44 = 0x601100;
    }
    lbl_1_bss_26C18 = fn_1_45D0(lbl_801A6410, lbl_1_bss_26C44, "game.c", 0x19E2);
    heap = lbl_1_bss_262F8 =
        fn_80008F88(lbl_1_bss_26C18, lbl_1_bss_26C18 + lbl_1_bss_26C44);
    game_heap_report(lbl_801A6410);
    game_save_heap_free(heap);
    fn_1_A714C(&lbl_1_bss_26C48, &lbl_1_bss_26C4C, &lbl_1_bss_26C50,
               &lbl_1_bss_26C54);
    fn_1_D1780();
    game_heap_report(lbl_801A6410);
    heap = fn_1_D2FB0();
    game_save_heap_free(heap);
    fn_1_D2FB0();
    mode = lbl_1_bss_960;
    if (mode == 12) {
        fn_1_47F74(150);
    } else {
        fn_1_479F0(mode);
    }
    game_heap_report(lbl_801A6410);
    lbl_1_bss_26B7A = -1;
    lbl_1_bss_26300 = -1;
    lbl_1_bss_50F8 = 0;
    lbl_1_bss_26C1C = 0;
    lbl_1_bss_5104 = -1;
    lbl_1_bss_53F4 = -1;
    fn_1_D0728();
    lbl_1_bss_25BA4 = 0;
    lbl_1_bss_25E94 = 0;
    lbl_1_bss_26B48 = 0;
    lbl_1_bss_25BF8 = 0.0f;
    lbl_1_bss_25BFC = 0.0f;
    lbl_1_bss_25B80 = 0;
    lbl_1_bss_25B98 = 0;
    lbl_1_bss_3C0C = 0;
    lbl_1_bss_25C40 = 0;
    lbl_1_bss_5234 = 0;
    lbl_1_bss_26C24 = 0;
    lbl_1_bss_26B1D = 0;
    lbl_801A66CC->unk_8B4 = 0;
    lbl_801A66CC->unk_8B5 = 0;
    lbl_801A66CC->unk_8B6 = 0;
    lbl_1_bss_25E90 = 0;
    lbl_1_bss_3C30.unk_A8 = NULL;
    lbl_1_bss_3C30.unk_C8 = NULL;
    lbl_1_bss_3C30.unk_AC = NULL;
    lbl_1_bss_3C30.unk_B0 = NULL;
    lbl_1_bss_3C30.unk_B4 = NULL;
    lbl_1_bss_3C30.unk_B8 = NULL;
    lbl_1_bss_3C30.unk_BC = NULL;
    lbl_1_bss_3C30.unk_C0 = NULL;
    lbl_1_bss_3C30.unk_C4 = NULL;
    lbl_1_bss_3C30.unk_CC = fn_1_33890;
    lbl_1_bss_3C30.unk_A7 = 0;
    lbl_1_bss_3C30.unk_13F6 = lbl_1_rodata_DCD4[fn_1_3FC9C()];
    lbl_1_bss_3C2A = -1;
    lbl_1_bss_26C58 = 0;
    switch (lbl_1_data_5B7C) {
    case 3:
        lbl_1_bss_3C30.unk_0 |= 0x04008050;
        break;
    case 4:
        lbl_1_bss_3C30.unk_0 |= 0x40;
        break;
    case 1:
    case 2:
        lbl_1_bss_3C30.unk_0 |= 0x00800000;
        break;
    }
    if (lbl_1_bss_26C5C != 0) {
        lbl_1_bss_3C30.unk_0 |= 0x40000;
    } else {
        lbl_1_bss_3C30.unk_A4 = 0;
        lbl_1_bss_3C30.unk_13F8[1] = 0;
        lbl_1_bss_3C30.unk_13F8[2] = 0;
        lbl_1_bss_3C30.unk_13F8[3] = 0;
        lbl_1_bss_3C30.unk_13F8[4] = 0;
        lbl_1_bss_3C30.unk_1402 = 0;
    }
    if (lbl_1_bss_3C30.unk_5 != 0 || lbl_1_data_5B84 != 0) {
        fn_1_3FCF8();
    }
    lbl_1_data_5B84 = 1;
    lbl_1_bss_3C30.unk_0 |= lbl_1_bss_3C08;
    if (lbl_1_bss_962 == 0xA2) {
        lbl_1_bss_3C30.unk_0 |= 0x01000000;
    }
    if ((lbl_1_bss_3C30.unk_0 & 0x00800000) && lbl_1_bss_3C00 != 0 &&
        lbl_1_data_5B7C != 5) {
        fn_1_F2780(lbl_1_bss_3C00, lbl_1_bss_25E98);
        if (lbl_1_bss_960 == 12 || lbl_1_bss_962 == 0xA0) {
            fn_1_F2E50(1);
            lbl_1_bss_26C60();
        } else {
            fn_1_F2E50(0);
        }
    }
    game_heap_report(lbl_801A6410);
    fn_80006E10("game");
    fn_80006E10("..");
    if (lbl_1_bss_3C10 == 0) {
        lbl_1_bss_3C30.unk_0 |= 0x100000;
    }
    lbl_1_bss_3C30.unk_0 &= lbl_1_data_5B80;
    fn_1_3522C();
    /* first phase request: 0x28 race start or 0x27 course view, else 0x25 course intro */
    if (lbl_1_bss_3C30.unk_8 == 0 || lbl_1_data_5B7C != 1) {
        fn_1_30054();
        if (lbl_1_bss_3C30.unk_0 & 0x201) {
            lbl_1_bss_50E8 = 0x28;
        } else {
            lbl_1_bss_50E8 = 0x27;
        }
    } else {
        lbl_1_bss_50E8 = 0x25;
        lbl_1_bss_25E70 = 1;
    }
    fn_1_E9770(lbl_1_bss_25B88, lbl_1_bss_25CA4, lbl_1_data_5B7C,
               lbl_1_bss_3C30.unk_6);
    if (lbl_1_data_5B7C == 5) {
        fn_1_3F8C0();
    } else {
        game_heap_report(lbl_801A6410);
    }
    fn_1_40BD4();
    fn_1_435C(lbl_1_bss_5100);
    fn_1_3F8C("time_count_dec", fn_1_35178, &lbl_1_bss_26C20, 2);
}
/* fzgx:end fn_1_36330 */

/* fzgx:begin fn_1_36A94 */
// Clears one indexed 0x81c0-byte entry in the shared buffer.

void fn_1_36A94(u32 arg0, void *arg1) {
    fn_80008BA8(&lbl_1_bss_5480[arg0 & 0xFF], arg1, sizeof(RaceBuf));
}
/* fzgx:end fn_1_36A94 */

/* fzgx:begin fn_1_36AD0 */
RaceBuf *fn_1_36AD0(void) {
    return lbl_1_bss_5480;
}
/* fzgx:end fn_1_36AD0 */

/* fzgx:begin fn_1_36ADC */
void fn_1_36ADC(void) {
    fn_80008BEC(lbl_1_bss_5480, (0), 0x20700);
}
/* fzgx:end fn_1_36ADC */

/* fzgx:begin fn_1_36B10 */
/* fn_1_36B10: block-private types (p0b) */
/* GamePlayer: see GamePlayer */
/* Obj3C30: see Obj3C30 */
/* GameSlotEntry: see GameSlotEntry */
/* GameSlotTable: see GameSlotTable */

static inline s32 fn_1_36B10_ready(void)
{
    if (lbl_1_bss_3C2A >= 0x2A) {
        return 0;
    }
    if (lbl_1_bss_3C2A < 0x28) {
        return 0;
    }
    if (lbl_1_bss_25BA0 != 0 || lbl_1_bss_25E94 != 0) {
        return 0;
    }
    if (lbl_1_bss_25BF8 > 0.0f) {
        return 0;
    }
    if (fn_1_EB248() != 0 || fn_1_154C84() != 0) {
        return 0;
    }
    if (lbl_1_bss_3C30.unk_0 & 0x08000000) {
        return 0;
    }
    if ((lbl_1_bss_3C30.unk_0 & 0x800) && lbl_1_bss_3C2A <= 0x28) {
        return 0;
    }
    if (fn_1_40354() == 0) {
        if (lbl_1_bss_3C30.unk_0 & 0x400) {
            if (fn_1_402D4() == 0) {
                return 0;
            }
        } else {
            return 0;
        }
    }
    return 1;
}

static inline void fn_1_36B10_pick(void)
{
    s32 i;
    if (lbl_1_bss_3C30.unk_8 != 0) {
        for (i = 0; i < lbl_1_bss_3C30.unk_8; i++) {
            if (PAD_BIT(lbl_1_bss_9F8[lbl_1_bss_25E98[i]].unk_8, 12)) {
                lbl_1_bss_3C20 = lbl_1_bss_25E98[i];
                break;
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            if (PAD_BIT(lbl_1_bss_9F8[i].unk_8, 12)) {
                lbl_1_bss_3C20 = i;
                break;
            }
        }
    }
}

static inline u32 fn_1_36B10_flags(void)
{
    u32 f;
    f = 0x2029;
    switch (lbl_1_bss_3C30.unk_5) {
    case 1:
        if (lbl_1_bss_3C30.unk_0 & 0x1000) {
            if (lbl_1_bss_3C30.unk_A7 < 4) {
                f |= 4;
            } else {
                f |= 2;
                f &= ~0x2000;
            }
            f &= ~0x28;
        }
        break;
    case 2:
        if (lbl_1_bss_3C30.unk_5 == 2) {
            f |= 0x200;
        }
    default:
        f |= 0x40;
        break;
    }
    if (lbl_1_bss_3C30.unk_0 & 0x00800000) {
        f |= 0x180;
    }
    return f;
}

void fn_1_36B10(void)
{
    u32 result;
    u32 flags;

    lbl_1_bss_26B50 = 0;
    lbl_1_bss_25C44 = 0;
    lbl_1_bss_25B9C = 0;
    if (lbl_1_bss_3C30.unk_A8 != NULL) {
        result = lbl_1_bss_3C30.unk_A8(&lbl_1_bss_3C30);
        if (result & 4) {
            lbl_1_bss_25B9C = 1;
        }
        if (result & 2) {
            fn_1_304A8();
        }
        if (result & 1) {
            return;
        }
    }
    if (lbl_1_bss_5104 != -1) {
        lbl_1_bss_25B9C = 0;
        if (lbl_1_bss_3C30.unk_C4 != NULL) {
            result = lbl_1_bss_3C30.unk_C4();
            if (result & 4) {
                lbl_1_bss_25B9C = 1;
            }
            if (result & 2) {
                fn_1_304A8();
            }
            if (result & 1) {
                return;
            }
        }
        if (fn_1_EB248() == 0 && fn_1_154C84() == 0) {
            if (lbl_1_bss_25BF0 != 0) {
                if (lbl_1_bss_3C30.unk_0 & 0x00800000) {
                    fn_1_F2EFC();
                }
                lbl_1_bss_25BF0 = 0;
                lbl_1_bss_26B50 = 1;
            } else if (lbl_1_bss_25B9C == 0) {
                fn_1_33A20();
            } else if (lbl_1_bss_3C30.unk_0 & 2) {
                lbl_1_bss_26B50 = 1;
            }
        } else if (lbl_1_bss_3C30.unk_0 & 0x800) {
            if (lbl_1_bss_25BF0 == 0) {
                if (lbl_1_bss_3C30.unk_0 & 0x00800000) {
                    fn_1_F2EDC();
                }
                lbl_1_bss_25BF0 = 1;
            }
            lbl_1_bss_26B50 = 1;
        }
    } else {
        if (fn_1_36B10_ready()) {
            flags = 0x2029;
            if (lbl_1_bss_3C30.unk_0 & 0x800) {
                flags = fn_1_36B10_flags();
                game_replay_menu_place();
            }
            if (lbl_1_bss_3C30.unk_5 == 5) {
                flags &= ~0x180;
                flags |= 0x10;
            } else if (lbl_1_bss_3C30.unk_5 != 1) {
                flags |= 0x40;
            }
            if (fn_1_2EBB8(flags, 0) != 0) {
                if (!(lbl_1_bss_3C30.unk_0 & 0x800)) {
                    lbl_1_bss_50F8 = 1;
                    fn_1_36B10_pick();
                    if (lbl_1_bss_3C30.unk_0 & 0x00800000) {
                        fn_1_F2EDC();
                    }
                    lbl_1_bss_26B50 = 1;
                    lbl_1_bss_3C30.unk_0 |= 2;
                    fn_1_A0C68();
                }
                if (lbl_1_bss_3C30.unk_0 & 0x00100000) {
                    fn_1_A2DC4(0xA9011200);
                }
            }
        }
    }
    if ((lbl_1_bss_53F4 != -1 && fn_1_4C10() == 0) || lbl_1_bss_26C2C != 0) {
        if (lbl_1_bss_3C0C != 0) {
            lbl_1_bss_25B9C = 0;
        if (lbl_1_bss_3C30.unk_C0 != NULL) {
            result = lbl_1_bss_3C30.unk_C0();
            if (result & 4) {
                lbl_1_bss_25B9C = 1;
            }
            if (result & 2) {
                fn_1_304A8();
            }
            if (result & 1) {
                return;
            }
        }
            lbl_1_bss_3C0C = 0;
        }
        fn_1_1280(0);
        lbl_1_bss_26C58 = 1;
        if (lbl_1_bss_3C10 == 0) {
            lbl_1_bss_968 = lbl_1_bss_53F4;
        }
    }
    if (lbl_1_bss_26B50 != 0 || lbl_1_bss_25E8C != 0) {
        return;
    }
    if (lbl_1_bss_3C30.unk_0 & 4) {
        return;
    }
    /* WARNING: compiler-diff device, not original code (carried from main): __cntlzw(0) keeps retail's dead
       pad test (lhz; rlwinm. with no branch). The body must be something the optimizer keeps and the code
       generator deletes: an empty body, `;`, an empty inline call or a dead local store drop the whole test. */
    if (PAD_BIT(lbl_1_bss_D58.unk_0, 10)) {
        __cntlzw(0);
    }
    if (lbl_1_bss_50E8 != -1) {
        if (lbl_1_bss_50E8 == 0x24) {
            if (lbl_1_bss_3C30.unk_0 & 0x201) {
                lbl_1_bss_50E8 = 0x28;
            } else {
                lbl_1_bss_50E8 = 0x27;
            }
        }
        if (lbl_1_bss_3C2A != -1) {
            lbl_1_data_5ABC[lbl_1_bss_3C2A - 0x24].exit();
        }
        lbl_1_data_5B86 = lbl_1_bss_3C2A;
        lbl_1_bss_3C2A = lbl_1_bss_50E8;
        lbl_1_data_5ABC[lbl_1_bss_3C2A - 0x24].init();
        lbl_1_bss_50E8 = -1;
        lbl_1_bss_26B4C = 0;
    }
    lbl_1_data_5ABC[lbl_1_bss_3C2A - 0x24].update();
    lbl_1_bss_26B4C++;
}
/* fzgx:end fn_1_36B10 */

/* fzgx:begin fn_1_37AA8 */
/* fn_1_37AA8: block-private types (p0b) */
/* GamePlayer: see GamePlayer */
/* Obj3C30: see Obj3C30 */
/* GameSlotEntry: see GameSlotEntry */
/* GameSlotTable: see GameSlotTable */
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 pad_2;
    u8 unk_3;
    u32 unk_4;
    u8 pad_8[0x28];
} GameObj5108_37AA8;

void fn_1_37AA8(void)
{
    s32 paused;
    u32 n;
    u32 i;
    u32 value;
    s64 now;

    paused = fn_1_3EFA8();
    fn_1_435C(lbl_1_bss_5100);
    fn_1_407C();
    now = OSGetTime();
    if (paused == 0) {
        fn_1_435C(lbl_1_bss_25B88);
        fn_1_407C();
        if ((lbl_1_bss_3C30.unk_0 & 0x800000) && lbl_1_bss_7EFD8.unk_C != 0) {
            value = fn_1_4338();
            fn_1_4324(1);
            fn_1_A96EC();
            while (lbl_1_bss_7EFD8.unk_C != 0) {
                fn_1_3308();
                fn_1_435C(lbl_1_bss_25B88);
                fn_1_407C();
                lbl_1_bss_7EFD8.unk_C--;
            }
            fn_1_A96DC();
            fn_1_4324(value);
        }
        if (lbl_1_bss_3C2A >= 0x29 && lbl_1_bss_3C30.unk_1474 < 0x57E40) {
            lbl_1_bss_3C30.unk_1474++;
        }
    } else {
        fn_1_F7578();
        lbl_1_bss_3C30.unk_1498 += now - lbl_1_bss_3C30.unk_14A0;
    }
    lbl_1_bss_3C30.unk_14A0 = now;
    fn_1_3CC4();
    fn_1_435C(lbl_1_bss_25CA4);
    if (fn_1_8DB94() != 0) {
        fn_1_106EB0(fn_1_86254(0));
    }
    if (camera_get_flags() != 0) {
        camera_update();
    }
    n = fn_1_58C4();
    for (i = 0; i < n; i++) {
        fn_1_5948(i);
        fn_1_9A770();
        if (lbl_1_bss_3C10 == 0) {
            fn_1_C7224();
        }
        fn_1_407C();
        fn_1_627C(i);
    }
    if ((lbl_1_bss_3C30.unk_0 & 0x800000) && lbl_1_bss_3C2A < 0x2A &&
        (lbl_1_bss_3C30.unk_0 & 0x800) && lbl_1_bss_960 != 0xC && lbl_1_bss_960 != 0xA) {
        game_draw_sprite_strip();
    }
    fn_1_C6F8C();
}
/* fzgx:end fn_1_37AA8 */

/* fzgx:begin fn_1_37E98 */
void fn_1_37E98(void) {
    u32 saved;

    if (lbl_1_bss_3C12 != 0) {
        fn_1_435C(lbl_1_bss_25B88);
        fn_1_8DAB4();
        if (lbl_1_bss_3C30.unk_5 == 2) {
            fn_1_435C(lbl_1_bss_5100);
            fn_1_426C(lbl_1_bss_26300);
        }
        if (lbl_1_bss_3C2A != -1) {
            lbl_1_data_5ABC[lbl_1_bss_3C2A - 0x24].exit();
        }
        if (lbl_1_bss_26C64 != NULL) {
            lbl_1_bss_26C64(&lbl_1_bss_3C30);
        }
        {
            GXColor color = {0, 0, 0, 0};

            fn_1_49F0(&color);
        }
        if (lbl_1_bss_3C30.unk_C0 != NULL) {
            lbl_1_bss_3C30.unk_C0();
        }
        fn_1_E9CFC();
        if (lbl_1_bss_26C1C != 0) {
            if (lbl_1_bss_3C30.unk_0 & 0x800000) {
                fn_1_F2EDC();
            }
            camera_set_state_flag(0);
            fn_1_F7308();
            fn_1_6400();
            fn_1_46B4(lbl_801A6410, lbl_1_bss_3C24, "game.c", 6148);
            lbl_1_bss_3C24 = 0;
            if (lbl_1_bss_25E88 != 0) {
                fn_1_435C(lbl_1_bss_25B88);
                if (lbl_1_data_5B88 != -1) {
                    fn_1_426C(lbl_1_data_5B88);
                    lbl_1_data_5B88 = -1;
                }
                fn_1_435C(lbl_1_bss_25CA4);
                if (lbl_1_data_5B8C[0] != -1) {
                    fn_1_426C(lbl_1_data_5B8C[0]);
                    lbl_1_data_5B8C[0] = -1;
                }
                fn_1_D1F88();
                lbl_1_bss_25E88 = 0;
            }
            saved = fn_80008E84(lbl_1_bss_262F8);
            fn_1_85878();
            fn_1_982C4();
            fn_80008E84(saved);
            fn_80009064(lbl_1_bss_262F8);
            fn_1_46B4(lbl_801A6410, lbl_1_bss_26C18, "game.c", 5986);
            fn_1_58854();
            if (lbl_1_bss_960 != 10 && lbl_1_bss_960 != 12 && !(lbl_1_bss_3C30.unk_0 & 0x400000)) {
                fn_80008BEC(lbl_1_bss_5480, 0, 0x20700);
            }
        }
        fn_1_1547FC();
        fn_1_C47B4();
        fn_1_435C(lbl_1_bss_25B88);
        if (lbl_1_bss_3C14 != 0) {
            fn_1_426C(lbl_1_bss_3C14);
            lbl_1_bss_3C14 = 0;
        }
        fn_1_435C(lbl_1_bss_25CA4);
        if (lbl_1_bss_3C18 != 0) {
            fn_1_426C(lbl_1_bss_3C18);
            lbl_1_bss_3C18 = 0;
        }
        fn_1_C6F80(0);
        saved = fn_80008E84(lbl_1_bss_25CCC);
        fn_1_79100();
        fn_80008E84(saved);
        fn_1_412A0(2);
        fn_1_E35F0();
        fn_1_435C(lbl_1_bss_25CA4);
        fn_1_41A8();
        fn_1_435C(lbl_1_bss_25B88);
        fn_1_41A8();
        fn_1_435C(lbl_1_bss_5100);
        fn_1_41A8();
        fn_1_46B4(lbl_801A6410, lbl_1_bss_5100, "game.c", 7345);
        fn_1_46B4(lbl_801A6410, lbl_1_bss_25B88, "game.c", 7346);
        fn_1_46B4(lbl_801A6410, lbl_1_bss_25CA4, "game.c", 7347);
        if (lbl_1_bss_3C30.unk_0 & 0x800000) {
            fn_1_F2DDC();
            lbl_1_bss_3C30.unk_0 &= ~0x800000;
        }
        fn_1_A0AA4();
        fn_80074D18(0);
        fn_1_76BF8();
        if (lbl_1_bss_960 == 12) {
            fn_1_48140(150);
        } else {
            fn_1_48164(1);
            fn_1_484CC(1);
        }
        fn_1_4DE04();
        fn_1_A7024(lbl_1_bss_26C48, lbl_1_bss_26C4C, lbl_1_bss_26C50, lbl_1_bss_26C54);
        if (lbl_1_bss_3C1C != 0) {
            fn_1_46B4(lbl_801A6410, (u32)lbl_1_bss_3C1C, "game.c", 7380);
            lbl_1_bss_3C1C = 0;
        }
        fn_1_410A0();
        fn_80009064(lbl_1_bss_25CCC);
        fn_1_46B4(lbl_801A6410, lbl_1_bss_26C40, "game.c", 7392);
        fn_1_D17E8();
        if (lbl_1_bss_3C10 == 0) {
            fn_1_2DE00(0);
        }
        lbl_1_bss_26C68 = 0;
        fn_1_3FCB0(0);
        fn_1_3FCD4(0);
        lbl_1_bss_25E74 = 0;
        lbl_1_bss_26C64 = NULL;
        lbl_1_bss_3C10 = 0;
        lbl_1_bss_3C12 = 0;
        fn_1_15555C();
        if (lbl_1_bss_3C30.unk_0 & 0x400000) {
            lbl_1_bss_96A = 184;
        }
    }
}
/* fzgx:end fn_1_37E98 */

/* fzgx:begin fn_1_382C4 */
/* fn_1_382C4: block-private types (p0b) */
/* Obj3C30: see Obj3C30 */
/* RaceBuf: see RaceBuf */
/* Racer: see Racer */

u8 lbl_1_bss_26C6A = 0;

void fn_1_382C4(void) {
    s16 i;
    u32 saved;

    fn_1_A8F78();
    lbl_1_bss_3C30.unk_6 = fn_1_3F1F8();
    fn_8006CE1C(0.0f);
    fn_1_4A00(1, 0x1E, lbl_1_bss_5100);
    fn_1_59290();
    fn_1_87074();
    fn_1_98590();
    lbl_1_bss_26C28 = 0;
    fn_1_435C(lbl_1_bss_25B88);
    fn_1_4310(0xBFFFFFFE);
    fn_1_435C(lbl_1_bss_25CA4);
    fn_1_4310(0xBFFFFFF6);
    fn_1_D0790();
    lbl_1_bss_5104 = -1;
    lbl_1_bss_3C30.unk_0 &= ~0x17800;
    lbl_1_bss_25E78 = 0;
    lbl_1_bss_50F8 = 0;
    lbl_1_bss_3C30.unk_0 &= 0xFFF7BF59;
    if (lbl_1_bss_3C30.unk_5 == 1) {
        fn_1_86254(0)->unk_475 = 0;
        for (i = 1; i < fn_1_86624(); i++) {
            fn_1_86254(i)->unk_475 = -1;
        }
    }
    fn_1_5370(3, 0);
    fn_1_3F75C();
    fn_1_4706C();
    fn_1_46A60();
    fn_1_47E54(0x9A);
    fn_1_47E54(0x9B);
    fn_1_47E54(0xA1);
    fn_1_41104(1);
    fn_1_3F75C();
    saved = fn_80008E84(lbl_1_bss_25CCC);
    fn_1_47F74(0x9A);
    if (lbl_1_bss_3C30.unk_8 == 1) {
        fn_1_47F74(0x9B);
    } else {
        fn_1_47F74(0x9D);
    }
    fn_1_47F74(0xA1);
    fn_1_47F74(fn_1_402A4(lbl_1_bss_3C30.unk_6));
    fn_1_411A4(1);
    fn_1_12F28C(lbl_1_bss_25CA4, &lbl_1_bss_26C6C, 7, &lbl_1_bss_3C30.unk_6);
    fn_80008E84(saved);
    fn_1_159478(2, 0, 1);
    fn_1_4310(-0x89);
    fn_1_3F5F8();
    fn_1_A1588(lbl_1_bss_6EAD0.unk_0->unk_0, 0x2D);
    fn_1_A0C68();
    lbl_1_bss_8B5F0 = 0;
    lbl_1_bss_8B5F1 = 0;
}
/* fzgx:end fn_1_382C4 */

/* fzgx:begin fn_1_384E8 */
void fn_1_384E8(void)
{
    fn_1_12F308();
    if (fn_1_4C10() == 0) {
        fn_1_12F358(lbl_1_bss_3C30.unk_6);
        if (lbl_1_bss_26C28 == 2) {
            if (fn_1_467F4() == 0) {
                fn_1_4A00(0, 0x1E, lbl_1_bss_5100);
                lbl_1_bss_26C28 = 1;
            }
        } else if (lbl_1_bss_26C28 != 0) {
            lbl_1_bss_50E8 = 0x26;
        } else if (fn_1_402D4() != 0) {
            fn_1_A2D84(0xA9010100);
            lbl_1_bss_26C28 = 2;
        }
    }
}
/* fzgx:end fn_1_384E8 */

/* fzgx:begin fn_1_385A4 */
void fn_1_385A4(void)
{
    u32 saved;

    fn_1_A8F78();
    fn_1_1596DC(2);
    saved = fn_80008E84(lbl_1_bss_25CCC);
    fn_1_12F30C(lbl_1_bss_25CA4, &lbl_1_bss_26C6C);
    fn_1_412A0(1);
    fn_1_48140(0xa1);
    fn_1_48140(fn_1_402A4(lbl_1_bss_3C30.unk_6));
    if (lbl_1_bss_3C30.unk_8 == 1) {
        fn_1_48140(0x9b);
    } else {
        fn_1_48140(0x9d);
    }
    fn_1_48140(0x9a);
    fn_80008E84(saved);
    fn_1_3F75C();
    if (lbl_1_data_5B7C == 1) {
        lbl_1_bss_26C6A = 1;
    }
}
/* fzgx:end fn_1_385A4 */

/* fzgx:begin fn_1_3867C */
/* fn_1_3867C: block-private types (p0b) */
/* Obj3C30: see Obj3C30 */
/* GameCar: see GameCar */
typedef struct GameEntry_3867C {
    u8 pad_0[0x14];
    u8 unk_14;
    u8 pad_15[0xB];
} GameEntry_3867C;
/* Racer: see Racer */

void fn_1_3867C(void) {
    GameRecord records[4];
    s8 single;
    u32 saved;
    u32 mode;
    s16 players;
    s16 shift;
    GameCar *car;
    s16 i;
    s16 j;

    single = lbl_1_bss_3C30.unk_8 == 1;
    fn_1_5370(3, 0);
    fn_1_3F75C();
    fn_1_48164(1);
    fn_1_A8F78();
    fn_1_4A00(1, 30, lbl_1_bss_5100);
    {
        u32 modes[5] = { 0x40000000, 0x40000000, 0x40000000, 0x20000000, 0x20000000 };
        mode = modes[lbl_1_bss_3C30.unk_8];
    }
    players = !single;
    shift = single ? GAME_SHIFT_SINGLE : GAME_SHIFT_MULTI;
    lbl_1_bss_26C70.unk_1C = lbl_1_bss_26CD8;
    lbl_1_bss_26C70.unk_4 = lbl_1_bss_26D48;
    lbl_1_bss_26C70.unk_8 = lbl_1_bss_280C8;
    fn_80008BEC(lbl_1_bss_2A7E0, 0, sizeof(lbl_1_bss_2A7E0));
    fn_80008BEC(lbl_1_bss_35620, 0, sizeof(lbl_1_bss_35620));
    for (i = 0; i < 41; i++) {
        lbl_1_bss_2A7E0[i].unk_324 = -1;
        lbl_1_bss_2A7E0[i].unk_328 = -1;
    }
    lbl_1_bss_26C70.unk_C = lbl_1_bss_2A7E0;
    lbl_1_bss_26C70.unk_14 = players;
    lbl_1_bss_26C70.unk_16 = shift;
    lbl_1_bss_26C70.unk_18 = mode;
    lbl_1_bss_26C70.unk_20 = lbl_1_bss_37EA0;
    lbl_1_bss_26C70.unk_24 = lbl_1_bss_38030;
    lbl_1_bss_26C70.unk_28 = 30;
    lbl_1_bss_26C70.unk_2C = 30;
    lbl_1_bss_26C70.unk_10 = lbl_1_bss_35620;
    lbl_1_bss_26C70.unk_30 = 0xF0000000;
    lbl_1_bss_26C70.unk_34 = 1;
    lbl_1_bss_26C70.unk_60 = 1;
    fn_1_12F10C(lbl_1_bss_5480);
    fn_1_12F194();
    fn_80008BA8(records, lbl_1_bss_718C0 + 0xE, sizeof(records));
    for (i = 0; i < 4; i++) {
        car = fn_1_86900(i);
        fn_1_12C0EC(&lbl_1_bss_26C70.unk_1C[i]);
        if (car != NULL) {
            if (car->unk_328 == records[i].unk_2 && lbl_1_bss_960 != 9) {
                lbl_1_bss_8B3A0.unk_C[i].unk_8 = records[i].unk_8;
            } else {
                lbl_1_bss_8B3A0.unk_C[i].unk_8 = 1 << (car->unk_3B8 % 4);
            }
            if (!(car->unk_390 & 0x04000000)) {
                if (car->unk_324 != -1) {
                    fn_1_81164(car, car->unk_3B8, lbl_1_bss_26C70.unk_16);
                }
                fn_80008BA8(&lbl_1_bss_2A7E0[car->unk_328], car, sizeof(GameCar));
            } else {
                for (j = 0; j < 8; j++) {
                    u8 bits = lbl_1_bss_8B3A0.unk_C[i].unk_8;
                    if (bits & (1 << j)) {
                        break;
                    }
                }
                fn_1_12B5B4(i, j);
                fn_80008BA8(&lbl_1_bss_35620[i], car->unk_3A0, sizeof(GameCarData));
            }
        }
    }
    saved = fn_80008E84(lbl_1_bss_25CCC);
    fn_1_12B120(&lbl_1_bss_26C70, lbl_1_bss_25B88, lbl_1_bss_25CA4,
                lbl_1_bss_381C0, lbl_1_bss_381D0,
                &lbl_1_bss_381F0);
    fn_1_47F74(0x9A);
    if (single) {
        fn_1_47F74(0x9B);
    } else {
        fn_1_47F74(0x9D);
    }
    fn_1_411A4(1);
    fn_80008E84(saved);
    fn_1_159478(2, 0, 1);
    fn_1_3F75C();
    if (lbl_1_bss_26C6A != 0) {
        fn_1_46B44(fn_1_3F7A0, &lbl_1_bss_8B5F4.unk_0);
        fn_1_46EA8(1);
        fn_1_7B084(lbl_1_bss_3C30.unk_6, 1);
        fn_1_9A958(lbl_1_bss_3C30.unk_6, 1);
        fn_1_46B44(fn_1_3F7A0, &lbl_1_bss_8B5F4.unk_4);
        fn_1_46EA8(0);
        lbl_1_bss_26C6A = 0;
    }
    fn_1_59290();
    fn_1_87074();
    fn_1_98590();
    lbl_1_bss_26C28 = 0;
    fn_1_435C(lbl_1_bss_25B88);
    fn_1_4310(0xBFFFFFFE);
    fn_1_435C(lbl_1_bss_25CA4);
    fn_1_4310(0xBFFFFFF6);
    fn_1_D0790();
    lbl_1_bss_5104 = -1;
    lbl_1_bss_3C30.unk_0 &= ~0x17800;
    lbl_1_bss_25E78 = 0;
    lbl_1_bss_50F8 = 0;
    lbl_1_bss_3C30.unk_0 &= 0xFFF7BF59;
    if (lbl_1_bss_3C30.unk_5 == 1) {
        fn_1_86254(0)->unk_475 = 0;
        for (i = 1; i < fn_1_86624(); i++) {
            fn_1_86254(i)->unk_475 = -1;
        }
    }
    if (lbl_1_bss_3C30.unk_0 & 0x100000) {
        lbl_1_bss_3C30.unk_0 &= ~0x100000;
        lbl_1_bss_381F4 = 1;
    } else {
        lbl_1_bss_381F4 = 0;
    }
}
/* fzgx:end fn_1_3867C */

/* fzgx:begin fn_1_38BBC */
/* fn_1_38BBC: block-private types (p0b) */
/* Obj3C30: see Obj3C30 */
/* GameLink: see GameLink */

void fn_1_38BBC(void) {
    s16 i;
    s16 result;

    if (fn_1_4C10() != 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        fn_1_12C060(&lbl_1_bss_26C70.unk_1C[i]);
    }
    result = fn_1_12B3BC(&lbl_1_bss_26C70, lbl_1_bss_25B88, lbl_1_bss_25CA4,
                         lbl_1_bss_381C0, lbl_1_bss_381D0,
                         &lbl_1_bss_381F0, 0);
    if (fn_1_4C10() == 0) {
        if (lbl_1_bss_26C28 == 1) {
            fn_1_3F75C();
            if (lbl_1_bss_3C30.unk_0 & 0x201) {
                lbl_1_bss_50E8 = 0x28;
            } else {
                lbl_1_bss_50E8 = 0x27;
            }
        } else if (lbl_1_bss_26C28 == -1) {
            fn_1_3F75C();
            lbl_1_bss_50E8 = 0x25;
        }
    }
    if (result == 1 && lbl_1_bss_26C28 == 0) {
        lbl_1_bss_26C28 = 1;
        fn_1_4A00(0, 30, lbl_1_bss_5100);
        lbl_1_bss_6EAB4.unk_0 |= 0x2C;
        fn_1_47E54(0x94);
    }
}
/* fzgx:end fn_1_38BBC */

/* fzgx:begin fn_1_38CF4 */
/* fn_1_38CF4: block-private types (p0b) */
/* Obj3C30: see Obj3C30 */

void fn_1_38CF4(void) {
    s16 i;
    s16 k;
    s8 single;
    GameCar *drv;
    void *obj;
    u32 save;
    s32 old;
    u32 word;
    u32 any;
    u32 save2;
    GameCar *car;

    single = (lbl_1_bss_3C30.unk_8 == 1);
    for (i = 0; i < lbl_1_bss_3C30.unk_8; i++) {
        if (lbl_1_bss_53F8[i] == NULL) {
            lbl_1_bss_25C48[i] = lbl_1_bss_8B3A0.unk_9F[i];
        } else {
            lbl_1_bss_53F8[i]->unk_B = lbl_1_bss_8B3A0.unk_9F[i];
        }
    }
    if (lbl_1_bss_3C30.unk_5 == 2) {
        if (lbl_1_bss_53F8[0] == NULL) {
            lbl_1_bss_3C30.unk_D4[0].unk_81 = lbl_1_bss_25C48[0];
        } else {
            lbl_1_bss_3C30.unk_D4[0].unk_81 = lbl_1_bss_53F8[0]->unk_B;
        }
    }

    for (i = 0; i < 4; i++) {
        drv = fn_1_86900(i);
        if (drv != NULL && !(drv->unk_390 & 0x04000000)) {
            lbl_1_bss_2A7E0[drv->unk_328].unk_3B8 = drv->unk_3B8;
            for (k = 0; k < 6; k++) {
                obj = drv->unk_330[k].obj;
                if (obj != NULL) {
                    fn_800713E0(obj, drv->unk_37C[drv->unk_3B8 % 4]);
                    fn_1_8019C(obj);
                }
            }
        }
    }

    save = fn_80008E84(lbl_1_bss_25CCC);
    fn_1_12B3F8(&lbl_1_bss_26C70, lbl_1_bss_25B88, lbl_1_bss_25CA4,
                lbl_1_bss_381C0, lbl_1_bss_381D0, &lbl_1_bss_381F0);
    fn_80008E84(save);

    for (i = 0; i < 4; i++) {
        car = fn_1_86900(i);
        if (car != NULL) {
            if (lbl_1_bss_8B3A0.unk_C[i].unk_8 != (u8)(1 << car->unk_3B8)) {
                if (car->unk_390 & 0x04000000) {
                    for (k = 0; k < 8; k++) {
                        if ((1 << k) == lbl_1_bss_8B3A0.unk_C[i].unk_8) {
                            break;
                        }
                    }
                    car->unk_3B8 = k;
                } else {
                    fn_1_81408(car, 1 << car->unk_3B8, lbl_1_bss_8B3A0.unk_C[i].unk_8 << (single ? 0 : 4));
                }
            }
            for (k = 0; k < 32; k++) {
                if ((1 << k) == lbl_1_bss_8B3A0.unk_C[i].unk_8) {
                    break;
                }
            }
            fn_1_A75DC(car, k);
            lbl_1_bss_523C[i] = 1 << car->unk_3B8;
        }
    }

    fn_1_1596DC(2);
    fn_1_48140(0xA1);
    save2 = fn_80008E84(lbl_1_bss_25CCC);
    fn_1_412A0(1);
    if (single) {
        fn_1_48140(0x9B);
    } else {
        fn_1_48140(0x9D);
    }
    fn_1_48140(0x9A);
    fn_80008E84(save2);
    fn_1_A8F78();
    if (lbl_1_bss_25E70 != 0) {
        fn_1_30054();
    }
    if (lbl_1_data_5B86 >= 40) {
        /* set bit 9 temporarily, sample bits 0/9, then restore it */
        old = lbl_1_bss_3C30.unk_0;
        word = old | 0x200;
        lbl_1_bss_3C30.unk_0 = word;
        any = word & 0x201;
        lbl_1_bss_3C30.unk_0 = word & ~0x200;
        lbl_1_bss_3C30.unk_0 = (word & ~0x200) | (old & 0x200);
        lbl_1_bss_50E8 = (any != 0) + 39;
    }
    fn_1_5370(0, 0);
    fn_1_FCF74();
    if (lbl_1_bss_381F4 != 0) {
        lbl_1_bss_3C30.unk_0 |= 0x100000;
    }
}
/* fzgx:end fn_1_38CF4 */

/* fzgx:begin fn_1_3908C */
void fn_1_3908C(void) {
    u32 v0;
    Obj_1_bss_6EAD0_At0 *v1;
    s32 t7;
    fn_1_435C(lbl_1_bss_25B88);
    fn_1_4310(-1);
    fn_1_435C(lbl_1_bss_25CA4);
    fn_1_4310(-1);
    fn_1_8616C();
    switch (lbl_1_bss_3C30.unk_6) {
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
    fn_1_A1588(lbl_1_bss_6EAD0.unk_0->unk_0, 7);
    } else {
    fn_1_A1588(lbl_1_bss_6EAD0.unk_0->unk_0, 6);
    }
    lbl_1_bss_3C30.unk_1474 = 0;
    v1 = lbl_1_bss_6EAD0.unk_0;
    lbl_1_bss_381F5 = 1;
    ADXT_Pause(v1->unk_0, 1);
    if (lbl_1_bss_3C30.unk_5 == 1) {
    fn_1_48004(187, 1);
    }
}
/* fzgx:end fn_1_3908C */

/* fzgx:begin fn_1_391F0 */
void fn_1_391F0(void)
{
    s32 done;
    u8 long_wait;
    s32 skip;
    u32 idle;
    s32 pressed;
    u16 buttons;

    if (lbl_1_bss_6F31A != 0) {
        done = 1;
    } else {
        done = fn_8004BD5C(lbl_1_bss_6EAD0.unk_0->unk_0);
    }
    if (done == 0 && (s8)lbl_1_bss_381F5 != 0) {
        return;
    }
    if ((s8)lbl_1_bss_381F5 != 0) {
        switch (lbl_1_bss_3C30.unk_6) {
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
            long_wait = 1;
            break;
        default:
            long_wait = 0;
            break;
        }
        ADXT_Pause(lbl_1_bss_6EAD0.unk_0->unk_0, 0);
        fn_1_435C(lbl_1_bss_25B88);
        fn_1_4310(0);
        fn_1_435C(lbl_1_bss_25CA4);
        fn_1_4310(0);
        fn_1_4310(0x10020000);
        fn_1_435C(lbl_1_bss_25B88);
        fn_1_4310(707);
        lbl_1_bss_381F5 = 0;
        fn_1_4A00(1, 142, lbl_1_bss_5100);
        fn_1_5370(4, 0);
        if (long_wait) {
            lbl_1_bss_26C28 = 350;
        } else {
            lbl_1_bss_26C28 = fn_1_101C0();
        }
        if (lbl_1_bss_3C30.unk_5 != 1) {
            fn_1_3F4FC();
        }
    }
    lbl_1_bss_26C28--;
    idle = !fn_1_467F4();
    skip = 0;
    if (idle && fn_1_EB200() == 0) {
        skip = 1;
    }
    pressed = 0;
    if (skip && fn_1_4C10() == 0) {
        pressed = 1;
    }
    if (pressed) {
        buttons = pad_word(&lbl_1_bss_9F8[0].unk_8, lbl_1_bss_25E98[0]);
        if (((buttons >> 8) & 1) || ((buttons >> 12) & 1)) {
            if (lbl_1_bss_26C28 > 30) {
                lbl_1_bss_26C28 = 30;
            }
        }
    }
    if (lbl_1_bss_26C28 == 30) {
        fn_1_4A00(0, 30, lbl_1_bss_5100);
        lbl_1_bss_6EAB4.unk_0 |= 12;
    }
    if (lbl_1_bss_26C28 == 0) {
        lbl_1_bss_50E8 = 40;
    }
}
/* fzgx:end fn_1_391F0 */

/* fzgx:begin fn_1_39420 */
void fn_1_39420(void)
{
    fn_1_A8F78();
    fn_1_435C(lbl_1_bss_25B88);
    fn_1_4310(0);
    fn_1_5370(0, 0);
    fn_1_3F75C();
    if (lbl_1_bss_3C30.unk_5 != 1) {
        game_start_burner();
        lbl_1_bss_26C16 = 1;
    }
    fn_1_435C(lbl_1_bss_25CA4);
    fn_1_4310(0);
}
/* fzgx:end fn_1_39420 */

/* fzgx:begin fn_1_395CC */
/* fn_1_395CC: block-private types (p0b) */
/* GamePlayer: see GamePlayer */
/* Obj3C30: see Obj3C30 */
/* GameSlotEntry: see GameSlotEntry */
/* GameSlotTable: see GameSlotTable */

/* fzgx-allow: S2 retail reads this word before fn_1_435C and discards it */

void fn_1_395CC(void)
{
    GameStepFn func;
    u32 j;
    u32 flags;

    fn_1_435C(lbl_1_bss_25B88);
    fn_1_4310(0);
    fn_1_435C(lbl_1_bss_25CA4);
    fn_1_4310(0);
    fn_1_A0D20();
    lbl_1_bss_17AC = 1;
    fn_1_35BC4();
    if (lbl_1_bss_3C30.unk_0 & 0x800) {
        fn_1_D0790();
    } else {
        fn_1_D0728();
        if (lbl_1_bss_3C30.unk_5 == 3) {
            for (j = 0; j < fn_1_58C4(); j++) {
                lbl_1_data_3D544[j] &= ~0x04000000;
            }
        }
        if (lbl_1_bss_3C30.unk_9 == 1) {
            for (j = 0; j < fn_1_58C4(); j++) {
                lbl_1_data_3D544[j] &= ~0x20000000;
            }
        }
    }
    if (lbl_1_bss_3C0C == 0) {
        func = lbl_1_bss_3C30.unk_AC;
        lbl_1_bss_25B9C = 0;
        if (func != NULL) {
            flags = func(&lbl_1_bss_3C30);
            if (flags & 4) {
                lbl_1_bss_25B9C = 1;
            }
            if (flags & 2) {
                fn_1_304A8();
            }
            if (flags & 1) {
                return;
            }
        }
        lbl_1_bss_3C0C = 1;
    }
    lbl_1_bss_26C28 = 0x3C;
    fn_1_435C(lbl_1_bss_25B88);
    if (lbl_1_bss_3C30.unk_0 & 0x00800000) {
        if (fn_1_F2F34() != 0) {
            lbl_1_bss_7EFD8.unk_0 = fn_1_3F8C("ReplayInfoDecode", fn_1_F3AB0, &lbl_1_bss_7EFD8, 0);
            fn_1_F38C0();
        } else if (fn_1_F2F58() != 0) {
            lbl_1_bss_7EFD8.unk_0 = fn_1_3F8C("ReplayInfoEncode", fn_1_F326C, &lbl_1_bss_7EFD8, 0);
            fn_1_F2F84();
        } else {
            lbl_1_bss_7EFD8.unk_0 = 0;
        }
        lbl_1_bss_7EFD8.unk_4 = 0;
    }
    if (lbl_1_bss_960 != 10 && lbl_1_bss_960 != 12) {
        fn_1_4811C(0xBB);
        fn_1_48004(0x94, 1);
    }
    fn_1_EA314(1);
    if (!(lbl_1_bss_3C30.unk_0 & 1)) {
        lbl_1_bss_26C68 = 0x1A4;
        fn_1_46EA8(1);
        fn_1_104710();
        fn_1_46EA8(0);
        game_heap_report(lbl_801A6410);
        fn_1_435C(lbl_1_bss_25B88);
        fn_1_43E8(1);
        fn_1_435C(lbl_1_bss_25B88);
        lbl_1_bss_25E7C = fn_1_3F8C("start_countdown", fn_1_34924, &lbl_1_bss_26C68, 0xD);
        lbl_1_bss_25E80 = fn_1_3F8C("Starter", fn_1_1049E0, &lbl_1_bss_26C68, 0xD);
        fn_1_435C(lbl_1_bss_25CA4);
        lbl_1_bss_25E84 = fn_1_3F8C("StarterDisp", fn_1_1050D0, NULL, 0x1A);
        fn_1_43F4();
    } else {
        lbl_1_bss_26C68 = 0;
        lbl_1_bss_25E7C = -1;
        lbl_1_bss_25E80 = -1;
        lbl_1_bss_25E84 = -1;
        fn_1_435C(lbl_1_bss_25B88);
        fn_1_4310(0);
    }
    fn_1_15E27C();
    fn_1_A11EC();
    fn_1_A1DCC(lbl_1_bss_3C30.unk_6);
    fn_1_3F5F8();
    lbl_1_bss_381F8 = -1;
    fn_1_435C(lbl_1_bss_25CA4);
    lbl_1_bss_381F8 = fn_1_3F8C("StoryGhostStartDisp", fn_1_F23E8, NULL, 0x1A);
    fn_1_F23D8();
}
/* fzgx:end fn_1_395CC */

/* fzgx:begin fn_1_39C60 */
/* fn_1_39C60: block-private types (p0b) */
/* GamePlayer: see GamePlayer */
/* Obj3C30: see Obj3C30 */
/* GameSlotEntry: see GameSlotEntry */
/* GameSlotTable: see GameSlotTable */

void fn_1_39C60(void)
{
    GameStepFn func;
    u32 flags;

    if (fn_1_EB200() == 0) {
        func = lbl_1_bss_3C30.unk_B0;
        lbl_1_bss_25B9C = 0;
        if (func != NULL) {
            flags = func(&lbl_1_bss_3C30);
            if (flags & 4) {
                lbl_1_bss_25B9C = 1;
            }
            if (flags & 2) {
                fn_1_304A8();
            }
            if (flags & 1) {
                return;
            }
        }
        fn_1_A2210(lbl_1_bss_3C30.unk_6);
        if (lbl_1_bss_26C68 < 0x3C || (lbl_1_bss_3C30.unk_0 & 1)) {
            lbl_1_bss_50E8 = 0x29;
        }
    }
}
/* fzgx:end fn_1_39C60 */

/* fzgx:begin fn_1_3A044 */
void fn_1_3A044(void) {
    u32 v;

    if ((s32)lbl_1_bss_381F8 != -1) {
        fn_1_435C(lbl_1_bss_25CA4);
        fn_1_426C(lbl_1_bss_381F8);
    }
    fn_1_A8F78();
    if (lbl_1_bss_25E6C != 0) {
        lbl_1_bss_25E70 = 1;
    }
    if (lbl_1_bss_25E70 != 0) {
        game_copy_names();
        lbl_1_bss_3C30.unk_1464 = 0;
        lbl_1_bss_3C30.unk_146C = 0;
        lbl_1_bss_3C30.unk_146D = 0;
        lbl_1_bss_3C30.unk_1470 = 0;
        lbl_1_bss_3C30.unk_146E = 0x5DC;
        fn_1_1547FC();
        fn_1_C47B4();
        fn_1_435C(lbl_1_bss_25B88);
        if (lbl_1_bss_3C14 != 0) {
            fn_1_426C(lbl_1_bss_3C14);
            lbl_1_bss_3C14 = 0;
        }
        fn_1_435C(lbl_1_bss_25CA4);
        if (lbl_1_bss_3C18 != 0) {
            fn_1_426C(lbl_1_bss_3C18);
            lbl_1_bss_3C18 = 0;
        }
        fn_1_C6F80(0);
        v = fn_80008E84(lbl_1_bss_25CCC);
        fn_1_79100();
        fn_80008E84(v);
        fn_1_412A0(2);
        fn_1_E35F0();
        fn_1_435C(lbl_1_bss_25B88);
        fn_1_426C(lbl_1_bss_25CB4);
        fn_1_426C(lbl_1_bss_25CB8);
        fn_1_426C(lbl_1_bss_25E64);
        fn_1_435C(lbl_1_bss_25CA4);
        fn_1_426C(lbl_1_bss_25CA8);
        fn_1_426C(lbl_1_bss_25CAC);
        fn_1_426C(lbl_1_bss_25CB0);
        fn_1_426C(lbl_1_bss_25CBC);
        fn_1_426C(lbl_1_bss_25CC0);
        fn_1_426C(lbl_1_bss_25CC4);
        fn_1_426C(lbl_1_bss_25E58);
        fn_1_426C(lbl_1_bss_25E5C);
        fn_1_426C(lbl_1_bss_25E60);
        fn_1_426C(lbl_1_bss_25E54);
    }
    if (lbl_1_bss_25E6C != 0) {
        lbl_1_bss_3C30.unk_A7++;
    }
    if (lbl_1_bss_50E8 != 0x29) {
        fn_1_435C(lbl_1_bss_25B88);
        if (lbl_1_bss_25E7C != -1) {
            fn_1_426C(lbl_1_bss_25E7C);
        }
        if (lbl_1_bss_25E80 != -1) {
            fn_1_426C(lbl_1_bss_25E80);
            fn_1_105724();
        }
        fn_1_435C(lbl_1_bss_25CA4);
        if (lbl_1_bss_25E84 != -1) {
            fn_1_426C(lbl_1_bss_25E84);
        }
        lbl_1_bss_25E7C = -1;
        lbl_1_bss_25E80 = -1;
        lbl_1_bss_25E84 = -1;
        if (lbl_1_bss_3C30.unk_0 & 0x800000) {
            fn_1_F2EDC();
        }
    }
}
/* fzgx:end fn_1_3A044 */

/* fzgx:begin fn_1_3A2C4 */
void fn_1_3A2C4(void) {

    fn_1_817C0();
    lbl_1_bss_381FC = 0;
    fn_1_EB080(1);
    lbl_1_bss_3C30.unk_1490 = lbl_1_bss_3C30.unk_14A0 = OSGetTime();
    lbl_1_bss_3C30.unk_1498 = 0;
    lbl_1_bss_38200 = 0xff;
}
/* fzgx:end fn_1_3A2C4 */

/* fzgx:begin fn_1_3A330 */
/* fn_1_3A330: block-private types (p0b) */
/* GamePlayer: see GamePlayer */
/* Obj3C30: see Obj3C30 */
/* GameSlotEntry: see GameSlotEntry */
/* GameSlotTable: see GameSlotTable */

static inline void game_update_countdown(void)
{
    s32 flag;

    if (lbl_1_bss_3C30.unk_0 & 0x40000) {
        flag = 1;
        if (lbl_1_bss_3C30.unk_D == 0) {
            flag = 0;
        } else if (lbl_1_bss_3C30.unk_D <= lbl_1_bss_3C30.unk_C) {
            flag = 0;
            if (lbl_1_bss_3C30.unk_A4 == 0) {
                lbl_1_bss_3C30.unk_A4 = 1;
            }
        }
        if (flag && lbl_1_bss_3C30.unk_A4 != 0) {
            lbl_1_bss_3C30.unk_A4--;
            if (lbl_1_bss_3C30.unk_A4 % 60 == 0 && (u16)(lbl_1_bss_3C30.unk_A4 / 60) < 10) {
                fn_1_A2D84(0xA9092700);
            }
        } else if (flag && lbl_1_bss_3C30.unk_A4 == 0) {
            lbl_1_bss_25B80++;
        }
    }
}

static inline void game_reset_goal_slots(void)
{
    s16 r;

    fn_1_86254(0)->unk_475 = 0;
    for (r = 1; r < fn_1_86624(); r++) {
        *(s8 *)&fn_1_86254(r)->unk_475 = -1;
    }
}

static inline void game_keep_goal_records(void)
{
    s32 j;

    for (j = 0; (u8)j < lbl_1_bss_3C30.unk_8; j++) {
        game_keep_goal_record(fn_1_86254((u8)j));
    }
}

void fn_1_3A330(void)
{
    u32 limit;
    GXColor color;
    u32 result;

    if (lbl_1_bss_3C30.unk_8 == 0) {
        fn_1_6BC0();
    }
    game_update_countdown();
    if ((lbl_1_bss_3C30.unk_0 & 0x800) && fn_1_4C10() == 0) {
        fn_1_F45A4();
        limit = fn_1_F45A4();
        if ((fn_1_F4594() >= limit || lbl_1_bss_7EFD8.unk_1B != 0) && lbl_1_bss_3C2A == 0x29) {
            fn_1_435C(lbl_1_bss_5100);
            fn_1_3F8C("replay_exit_gap", fn_1_2C908, 0, 0xD);
            color = lbl_1_rodata_BD8;
            fn_1_49F0(&color);
            if (lbl_1_bss_3C10 != 0) {
                fn_1_4A00(0, 0x78, lbl_1_bss_5100);
            } else {
                fn_1_4A00(0, 0x1E, lbl_1_bss_5100);
            }
            if (lbl_1_bss_3C30.unk_5 == 1) {
                game_reset_goal_slots();
            }
        }
    }
    lbl_1_bss_25B9C = 0;
    if (lbl_1_bss_3C30.unk_B4 != NULL) {
        result = lbl_1_bss_3C30.unk_B4(&lbl_1_bss_3C30);
        if (result & 4) {
            lbl_1_bss_25B9C = 1;
        }
        if (result & 2) {
            fn_1_304A8();
        }
        if (result & 1) {
            return;
        }
    }
    fn_1_15E44C();
    if (lbl_1_bss_3C30.unk_CC == NULL) {
        return;
    }
    switch (lbl_1_bss_3C30.unk_CC(&lbl_1_bss_3C30)) {
    case 1:
        fn_1_EB080(4);
        fn_1_EB074(0);
        if (fn_1_2DF98() != 0) {
            game_keep_goal_records();
            lbl_1_bss_50E8 = 0x2A;
            lbl_1_bss_25E94 = 0;
        } else {
            lbl_1_bss_25E94 = 1;
        }
        lbl_1_bss_26C24 = 1;
        break;
    case -1:
        fn_1_EB080(4);
        fn_1_EB074(1);
        game_keep_goal_records();
        if (lbl_1_bss_3C30.unk_5 == 5) {
            ADXT_Stop(lbl_1_bss_6EAD0.unk_0->unk_4);
            lbl_1_bss_6F317 = 0;
        } else if (lbl_1_bss_6F317 != 0) {
            fn_1_A1588(lbl_1_bss_6EAD0.unk_0->unk_0, 0x27);
            ADXT_Stop(lbl_1_bss_6EAD0.unk_0->unk_4);
            lbl_1_bss_6F317 = 0;
            lbl_1_bss_6F23C |= 1;
        }
        if (lbl_1_bss_3C30.unk_8 > 1) {
            lbl_1_bss_50E8 = 0x2B;
        } else {
            lbl_1_bss_50E8 = 0x2B;
        }
        break;
    case -2:
        lbl_1_bss_3C30.unk_7 = 10;
        fn_1_304A8();
        break;
    }
}
/* fzgx:end fn_1_3A330 */

/* fzgx:begin fn_1_3AEC4 */
/* Release of the stage data under its heap. Retail has it inlined in fn_1_3AEC4, fn_1_3C880 and fn_1_3DB9C. */
static inline void game_stage_release(void)
{
    u32 saved;

    saved = fn_80008E84(lbl_1_bss_25CCC);
    fn_1_79100();
    fn_80008E84(saved);
}

void fn_1_3AEC4(void) {

    fn_1_435C(lbl_1_bss_25B88);
    if (lbl_1_bss_25E7C != -1) {
        fn_1_426C(lbl_1_bss_25E7C);
    }
    if (lbl_1_bss_25E80 != -1) {
        fn_1_426C(lbl_1_bss_25E80);
        fn_1_105724();
    }
    fn_1_435C(lbl_1_bss_25CA4);
    if (lbl_1_bss_25E84 != -1) {
        fn_1_426C(lbl_1_bss_25E84);
    }
    lbl_1_bss_25E7C = -1;
    lbl_1_bss_25E80 = -1;
    lbl_1_bss_25E84 = -1;
    if (lbl_1_bss_3C30.unk_0 & 0x800000) {
        if (lbl_1_bss_50E8 != 0x2A) {
            fn_1_F2EDC();
        }
    }
    fn_1_A8F78();
    if (lbl_1_bss_25E6C != 0) {
        lbl_1_bss_25E70 = 1;
    }
    if (lbl_1_bss_25E70 != 0) {
        game_copy_names();
        lbl_1_bss_3C30.unk_1464 = 0;
        lbl_1_bss_3C30.unk_146C = 0;
        lbl_1_bss_3C30.unk_146D = 0;
        lbl_1_bss_3C30.unk_1470 = 0;
        lbl_1_bss_3C30.unk_146E = 0x5DC;
        fn_1_1547FC();
        fn_1_C47B4();
        fn_1_435C(lbl_1_bss_25B88);
        if (lbl_1_bss_3C14 != 0) {
            fn_1_426C(lbl_1_bss_3C14);
            lbl_1_bss_3C14 = 0;
        }
        fn_1_435C(lbl_1_bss_25CA4);
        if (lbl_1_bss_3C18 != 0) {
            fn_1_426C(lbl_1_bss_3C18);
            lbl_1_bss_3C18 = 0;
        }
        fn_1_C6F80(0);
        game_stage_release();
        fn_1_412A0(2);
        fn_1_E35F0();
        fn_1_435C(lbl_1_bss_25B88);
        fn_1_426C(lbl_1_bss_25CB4);
        fn_1_426C(lbl_1_bss_25CB8);
        fn_1_426C(lbl_1_bss_25E64);
        fn_1_435C(lbl_1_bss_25CA4);
        fn_1_426C(lbl_1_bss_25CA8);
        fn_1_426C(lbl_1_bss_25CAC);
        fn_1_426C(lbl_1_bss_25CB0);
        fn_1_426C(lbl_1_bss_25CBC);
        fn_1_426C(lbl_1_bss_25CC0);
        fn_1_426C(lbl_1_bss_25CC4);
        fn_1_426C(lbl_1_bss_25E58);
        fn_1_426C(lbl_1_bss_25E5C);
        fn_1_426C(lbl_1_bss_25E60);
        fn_1_426C(lbl_1_bss_25E54);
    }
    if (lbl_1_bss_25E6C != 0) {
        lbl_1_bss_3C30.unk_A7++;
    }
}
/* fzgx:end fn_1_3AEC4 */

/* fzgx:begin fn_1_3B11C */
/* fn_1_3B11C: block-private types (p0b) */
/* GamePlayer: see GamePlayer */
/* Obj3C30: see Obj3C30 */
/* GameSlotEntry: see GameSlotEntry */
/* GameSlotTable: see GameSlotTable */

static inline void game_award_points(void)
{
    s32 k;
    s32 slot;
    GamePlayer *p;

    for (k = 0; k < lbl_1_bss_3C30.unk_9; k++) {
        slot = lbl_1_bss_3C30.unk_E[k];
        p = &lbl_1_bss_3C30.unk_D4[slot];
        lbl_1_bss_3C30.unk_1480[slot] += lbl_1_rodata_DBDC[k];
        if (k == 0) {
            lbl_1_bss_3C30.unk_1478[slot]++;
        }
        p->unk_9[0] = lbl_1_rodata_DBDC[k];
    }
}

void fn_1_3B11C(void)
{
    s32 cup;
    GameCar *car;
    s16 v;
    s32 j;

    fn_1_435C(lbl_1_bss_25B88);
    fn_1_8D988();
    fn_1_5370(1, lbl_1_bss_50FC);
    fn_1_A0C68();
    fn_1_14A17C();
    for (j = 0; j < 4; j++) {
        fn_1_156754(j);
    }
    fn_1_F7578();
    if (lbl_1_bss_3C30.unk_0 & 0x00100000) {
        lbl_1_bss_3C30.unk_0 &= ~0x00100000;
        lbl_1_bss_381F4 = 1;
    } else {
        lbl_1_bss_381F4 = 0;
    }
    if (lbl_1_bss_3C30.unk_0 & 0x00800000) {
        if (lbl_1_bss_7EFD8.unk_0 != 0) {
            if (fn_1_F2F58() != 0) {
                fn_1_F37F4();
            }
            fn_1_426C(lbl_1_bss_7EFD8.unk_0);
            lbl_1_bss_7EFD8.unk_0 = 0;
        }
        fn_1_F2EDC();
    }
    if (lbl_1_bss_7F04C != 0) {
        fn_1_435C(lbl_1_bss_25B88);
        fn_1_426C(lbl_1_bss_7F04C);
        fn_1_F7308();
        lbl_1_bss_7F04C = 0;
    }
    lbl_1_bss_26B14 = 0;
    fn_1_D0790();
    fn_1_1280(0);
    {
        GXColor color = {0x00, 0x00, 0x00, 0x00};

        fn_1_49F0(&color);
    }
    fn_1_4A00(1, 0x1E, lbl_1_bss_5100);
    lbl_1_bss_3C04 = 0;
    lbl_1_bss_3C30.unk_0 |= 0x1000;
    if (lbl_1_bss_3C30.unk_0 & 0x800) {
        if (lbl_1_bss_3C10 != 0) {
            fn_1_304A8();
        } else {
            lbl_1_bss_8E51D = 8;
            lbl_1_bss_5104 = -1;
            lbl_1_bss_3C30.unk_C4 = 0;
            fn_1_4068C(&lbl_1_bss_5108);
            lbl_1_bss_5108.flags &= ~1;
        }
    } else if (!(lbl_1_bss_3C30.unk_0 & 0x04000000)) {
        switch (lbl_1_bss_3C30.unk_5) {
        case 0:
            game_award_points();
        case 6:
            if (lbl_1_bss_3C30.unk_9 <= 4) {
                lbl_1_bss_8E51D = 3;
            }
            break;
        case 2:
            fn_1_31C3C(0);
            break;
        case 5:
            lbl_1_bss_8E51D = 9;
            break;
        case 1:
            cup = fn_1_3FC9C();
            fn_1_F9F2C(lbl_1_bss_3C30.unk_D4[0].unk_82, cup, lbl_1_bss_3C30.unk_A6 - 1, lbl_1_bss_3C30.unk_A7);
            break;
        }
    }
    if (lbl_1_bss_960 != 10 && lbl_1_bss_960 != 12 && fn_1_485A8(0x97) == 0) {
        car = fn_1_86900(fn_1_8623C());
        if (car == NULL) {
            car = fn_1_868C0(0);
        }
        v = fn_1_12C930(car->unk_328);
        fn_1_4811C(0x94);
        fn_1_48004(0x97, 1);
        fn_1_48004(0x99, 1);
        fn_1_48004(((u32 *)lbl_1_data_1A2B4)[v], 1);
    }
    fn_1_8DBA4(0);
    lbl_1_bss_38200 = (lbl_1_bss_3C30.unk_0 & 0x800) ? 0 : 0x3C;
}
/* fzgx:end fn_1_3B11C */

/* fzgx:begin fn_1_3B7D4 */
/* fn_1_3B7D4: block-private types (p0b) */
/* GamePlayer: see GamePlayer */
/* GameSlotEntry: see GameSlotEntry */
/* GameSlotTable: see GameSlotTable */

static inline void fn_1_3B7D4_slot(void)
{
    s32 i;
    s32 mask;

    mask = lbl_1_bss_25BEC;
    if (mask == -2) {
        return;
    }
    lbl_1_bss_3C30.unk_0 |= 2;
    for (i = 13; i > 0; i--) {
        if (mask & (1 << i)) {
            lbl_1_bss_5104 = i;
            return;
        }
    }
    for (i = 0; i < 14; i++) {
        if (lbl_1_bss_25BE6 & (1 << i)) {
            lbl_1_bss_5104 = i;
            return;
        }
    }
}

void fn_1_3B7D4(void)
{
    u32 result;
    s32 code;

    lbl_1_bss_25B9C = 0;
    if (lbl_1_bss_3C30.unk_B8 != NULL) {
        result = lbl_1_bss_3C30.unk_B8(&lbl_1_bss_3C30);
        if (result & 4) {
            lbl_1_bss_25B9C = 1;
        }
        if (result & 2) {
            fn_1_304A8();
        }
        if (result & 1) {
            return;
        }
    }
    if (lbl_1_bss_38200 != 0) {
        lbl_1_bss_38200--;
    }
    if (lbl_1_bss_25BA0 != 0) {
        return;
    }
    if (lbl_1_bss_26B14 == 0) {
        return;
    }
    if (lbl_1_bss_25BA4 != 0) {
        return;
    }
    code = lbl_1_bss_25BEA == 2 ? lbl_1_bss_25BEC : -2;
    if (fn_1_EB248() != 0 || fn_1_154C84() != 0) {
        lbl_1_bss_3C30.unk_0 |= 2;
        return;
    }
    lbl_1_bss_3C30.unk_0 &= ~2;
    if (code == -2) {
        return;
    }
    fn_1_435C(lbl_1_bss_25B88);
    fn_1_3B7D4_slot();
    switch (code) {
    case 0x2:
        if (lbl_1_bss_25BA0 != 0) {
            break;
        }
        fn_1_2DE00(1);
        lbl_1_bss_3C30.unk_7 = 0xE;
        fn_1_304A8();
        break;
    case 0x4:
        game_goto_next_stage();
        break;
    case 0x8:
        game_restart(0);
        break;
    case 0x20:
        game_goto_setting();
        break;
    case 0x40:
        if (lbl_1_bss_25BA0 != 0) {
            break;
        }
        lbl_1_bss_53F4 = 1;
        lbl_1_bss_8B3A0.unk_94 |= 0x20;
        fn_1_4A00(0, 0x1E, lbl_1_bss_5100);
        lbl_1_bss_6EAB4.unk_0 |= 0x2C;
        lbl_1_bss_25BA0 = 1;
        if (lbl_1_bss_3C30.unk_5 == 0) {
            lbl_1_data_5B84 = 0;
        }
        fn_1_8DBA4(0);
        break;
    case 0x80:
        game_restart(1);
        break;
    case 0x100:
        fn_1_F3BC0();
        fn_1_154CC4(0);
        fn_1_3B7D4_slot();
        break;
    case 0x2000:
        fn_1_304A8();
        break;
    case 0x200:
        fn_1_EB080(0xB);
        break;
    }
}
/* fzgx:end fn_1_3B7D4 */

/* fzgx:begin fn_1_3C880 */
/* fn_1_3C880: block-private types (p0b) */
/* GamePlayer: see GamePlayer */
/* Obj3C30: see Obj3C30 */
/* GameSlotEntry: see GameSlotEntry */
/* GameSlotTable: see GameSlotTable */

static inline void fn_1_3C880_loop1(void)
{
    s32 k;
    s32 i;
    GamePlayer *p;
    for (i = 0; i < lbl_1_bss_3C30.unk_9; i++) {
        p = &lbl_1_bss_3C30.unk_D4[i];
        if (p->unk_E[lbl_1_bss_3C30.unk_A7] == 0xFF) {
            for (k = 0; k < lbl_1_bss_3C30.unk_9; k++) {
                if (i == lbl_1_bss_3C30.unk_E[k]) {
                    break;
                }
            }
            p->unk_E[lbl_1_bss_3C30.unk_A7] = k;
            p->unk_4C[lbl_1_bss_3C30.unk_A7] = 0;
            if (lbl_1_bss_3C30.unk_5 != 0) {
                if (k < 30) {
                    p->unk_9[lbl_1_bss_3C30.unk_A7] = lbl_1_rodata_DB38[k];
                } else {
                    p->unk_9[lbl_1_bss_3C30.unk_A7] = 0;
                }
            }
            p->unk_4 += p->unk_9[lbl_1_bss_3C30.unk_A7];
        }
    }
}

static inline void fn_1_3C880_loop2(void)
{
    s32 k;
    for (k = 0; k < lbl_1_bss_3C30.unk_9; k++) {
        lbl_1_bss_25BA8[lbl_1_bss_3C30.unk_E[k]] = k;
    }
    for (k = 0; k < lbl_1_bss_3C30.unk_9; k++) {
        lbl_1_bss_25BC8[k] = lbl_1_bss_3C30.unk_D4[k].unk_13[lbl_1_bss_3C30.unk_A7];
    }
}

void fn_1_3C880(void)
{
    s32 i;

    for (i = 0; i < 4; i++) {
        fn_1_156754(i);
    }
    fn_1_F7578();
    fn_1_A0D20();
    fn_1_435C(lbl_1_bss_25B88);
    fn_1_8DAB4();
    fn_1_A8F78();
    if (!(lbl_1_bss_3C30.unk_0 & 0x800)) {
        fn_1_3C880_loop1();
        fn_1_3C880_loop2();
        fn_1_2CBAC();
    }
    if (lbl_1_bss_25E6C != 0) {
        lbl_1_bss_25E70 = 1;
    }
    if (lbl_1_bss_25E70 != 0) {
        game_copy_names();
        lbl_1_bss_3C30.unk_1464 = 0;
        lbl_1_bss_3C30.unk_146C = 0;
        lbl_1_bss_3C30.unk_146D = 0;
        lbl_1_bss_3C30.unk_1470 = 0;
        lbl_1_bss_3C30.unk_146E = 1500;
        fn_1_1547FC();
        fn_1_C47B4();
        fn_1_435C(lbl_1_bss_25B88);
        if (lbl_1_bss_3C14 != 0) {
            fn_1_426C(lbl_1_bss_3C14);
            lbl_1_bss_3C14 = 0;
        }
        fn_1_435C(lbl_1_bss_25CA4);
        if (lbl_1_bss_3C18 != 0) {
            fn_1_426C(lbl_1_bss_3C18);
            lbl_1_bss_3C18 = 0;
        }
        fn_1_C6F80(0);
        game_stage_release();
        fn_1_412A0(2);
        fn_1_E35F0();
        fn_1_435C(lbl_1_bss_25B88);
        fn_1_426C(lbl_1_bss_25CB4);
        fn_1_426C(lbl_1_bss_25CB8);
        fn_1_426C(lbl_1_bss_25E64);
        fn_1_435C(lbl_1_bss_25CA4);
        fn_1_426C(lbl_1_bss_25CA8);
        fn_1_426C(lbl_1_bss_25CAC);
        fn_1_426C(lbl_1_bss_25CB0);
        fn_1_426C(lbl_1_bss_25CBC);
        fn_1_426C(lbl_1_bss_25CC0);
        fn_1_426C(lbl_1_bss_25CC4);
        fn_1_426C(lbl_1_bss_25E58);
        fn_1_426C(lbl_1_bss_25E5C);
        fn_1_426C(lbl_1_bss_25E60);
        fn_1_426C(lbl_1_bss_25E54);
    }
    if (lbl_1_bss_25E6C != 0) {
        lbl_1_bss_3C30.unk_A7++;
    }
    if (lbl_1_bss_25E88 != 0) {
        fn_1_435C(lbl_1_bss_25B88);
        if (lbl_1_data_5B88 != -1) {
            fn_1_426C(lbl_1_data_5B88);
            lbl_1_data_5B88 = -1;
        }
        fn_1_435C(lbl_1_bss_25CA4);
        if (lbl_1_data_5B8C[0] != -1) {
            fn_1_426C(lbl_1_data_5B8C[0]);
            lbl_1_data_5B8C[0] = -1;
        }
        fn_1_D1F88();
        lbl_1_bss_25E88 = 0;
    }
    lbl_1_bss_3C30.unk_0 &= ~0x01000000;
    if (lbl_1_bss_381F4 != 0) {
        lbl_1_bss_3C30.unk_0 |= 0x00100000;
    }
}
/* fzgx:end fn_1_3C880 */

/* fzgx:begin fn_1_3CDB0 */
/* fn_1_3CDB0: block-private types (p0b) */
/* Obj3C30: see Obj3C30 */

void fn_1_3CDB0(void) {
    fn_1_1280(0);
    if (lbl_1_bss_3C30.unk_5 != 5) {
        fn_1_D0790();
    }
    lbl_1_bss_3C30.unk_0 |= 0x2000;
    fn_1_435C(lbl_1_bss_25B88);
    if (lbl_1_bss_3C30.unk_0 & 0x800000) {
        if (lbl_1_bss_7EFD8.unk_0 != 0) {
            if (fn_1_F2F58() != 0) {
                fn_1_F37F4();
            }
            fn_1_426C(lbl_1_bss_7EFD8.unk_0);
            lbl_1_bss_7EFD8.unk_0 = 0;
        }
        fn_1_F2EDC();
    }
    lbl_1_bss_5104 = -1;
    game_set_pause_port();
    lbl_1_bss_26C28 = 0;
}
/* fzgx:end fn_1_3CDB0 */

/* fzgx:begin fn_1_3CE94 */
/* fn_1_3CE94: block-private types (p0b) */
/* GamePlayer: see GamePlayer */
/* Obj3C30: see Obj3C30 */
/* GameSlotEntry: see GameSlotEntry */
/* GameSlotTable: see GameSlotTable */

void fn_1_3CE94(void)
{
    u32 result;
    u32 flags;
    s32 ok;
    u32 j;
    s32 r;

    lbl_1_bss_25B9C = 0;
    if (lbl_1_bss_3C30.unk_BC != NULL) {
        result = lbl_1_bss_3C30.unk_BC(&lbl_1_bss_3C30);
        if (result & 4) {
            lbl_1_bss_25B9C = 1;
        }
        if (result & 2) {
            fn_1_304A8();
        }
        if (result & 1) {
            return;
        }
    }
    if (lbl_1_bss_3C30.unk_13F6 == 0) {
        if (++lbl_1_bss_26C28 > 300) {
            lbl_1_bss_26C28 = 300;
        }
        if (lbl_1_bss_26C28 >= 300 && fn_1_402D4() != 0 && lbl_1_bss_25BA0 == 0 &&
            lbl_1_bss_50E8 != 0x2D && lbl_1_bss_3C2A != 0x2D && fn_1_4C10() == 0 &&
            lbl_1_bss_25BA4 == 0) {
            game_start_gameover_event();
        }
        return;
    }
    if (lbl_1_bss_5104 == -1 && lbl_1_bss_26C28 == 0) {
        ok = 1;
        flags = 0x2028;
        if (lbl_1_bss_3C30.unk_5 != 5 && lbl_1_bss_3C30.unk_5 != 1) {
            flags |= 0x40;
        }
        for (j = 0; j < lbl_1_bss_3C30.unk_8; j++) {
            if (lbl_1_bss_50EC[j] != 0) {
                ok = 0;
                break;
            }
        }
        if (ok == 0) {
            return;
        }
        r = fn_1_2EBB8(flags, 1);
        lbl_1_data_5B70 = (f32)(450 - r);
        lbl_1_data_5B6C = 620.0f - lbl_1_bss_25C30 / 2.0f;
        lbl_1_bss_26C28 = 1;
    }
    if (lbl_1_bss_25BA0 != 0 || lbl_1_bss_25BA4 != 0) {
        return;
    }
    if (fn_1_EB248() != 0 || fn_1_154C84() != 0) {
        lbl_1_bss_3C30.unk_0 |= 2;
        return;
    }
    lbl_1_bss_3C30.unk_0 &= ~2;
    switch (lbl_1_bss_25BEA == 1 ? lbl_1_bss_25BEC : -2) {
    case 0x8:
        game_restart(0);
        break;
    case 0x20:
        game_goto_setting();
        break;
    case 0x40:
        if (lbl_1_bss_25BA0 != 0) {
            break;
        }
        lbl_1_bss_53F4 = 1;
        lbl_1_bss_8B3A0.unk_94 |= 0x20;
        fn_1_4A00(0, 0x1E, lbl_1_bss_5100);
        lbl_1_bss_6EAB4.unk_0 |= 0x2C;
        lbl_1_bss_25BA0 = 1;
        if (lbl_1_bss_3C30.unk_5 == 0) {
            lbl_1_data_5B84 = 0;
        }
        fn_1_8DBA4(0);
        break;
    case 0x80:
        game_restart(1);
        break;
    case 0x100:
        fn_1_F3BC0();
        fn_1_154CC4(0);
        fn_1_3B7D4_slot();
        break;
    case 0x2000:
        fn_1_304A8();
        break;
    }
}
/* fzgx:end fn_1_3CE94 */

/* fzgx:begin fn_1_3DB9C */
void fn_1_3DB9C(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        fn_1_156754(i);
    }
    fn_1_F7578();
    lbl_1_bss_3C30.unk_0 &= ~0x2000;
    fn_1_A8F78();
    if (lbl_1_bss_25E6C != 0) {
        lbl_1_bss_25E70 = 1;
    }
    if (lbl_1_bss_25E70 != 0) {
        game_copy_names();
        lbl_1_bss_3C30.unk_1464 = 0;
        lbl_1_bss_3C30.unk_146C = 0;
        lbl_1_bss_3C30.unk_146D = 0;
        lbl_1_bss_3C30.unk_1470 = 0;
        lbl_1_bss_3C30.unk_146E = 0x5DC;
        fn_1_1547FC();
        fn_1_C47B4();
        fn_1_435C(lbl_1_bss_25B88);
        if (lbl_1_bss_3C14 != 0) {
            fn_1_426C(lbl_1_bss_3C14);
            lbl_1_bss_3C14 = 0;
        }
        fn_1_435C(lbl_1_bss_25CA4);
        if (lbl_1_bss_3C18 != 0) {
            fn_1_426C(lbl_1_bss_3C18);
            lbl_1_bss_3C18 = 0;
        }
        fn_1_C6F80(0);
        game_stage_release();
        fn_1_412A0(2);
        fn_1_E35F0();
        fn_1_435C(lbl_1_bss_25B88);
        fn_1_426C(lbl_1_bss_25CB4);
        fn_1_426C(lbl_1_bss_25CB8);
        fn_1_426C(lbl_1_bss_25E64);
        fn_1_435C(lbl_1_bss_25CA4);
        fn_1_426C(lbl_1_bss_25CA8);
        fn_1_426C(lbl_1_bss_25CAC);
        fn_1_426C(lbl_1_bss_25CB0);
        fn_1_426C(lbl_1_bss_25CBC);
        fn_1_426C(lbl_1_bss_25CC0);
        fn_1_426C(lbl_1_bss_25CC4);
        fn_1_426C(lbl_1_bss_25E58);
        fn_1_426C(lbl_1_bss_25E5C);
        fn_1_426C(lbl_1_bss_25E60);
        fn_1_426C(lbl_1_bss_25E54);
    }
    if (lbl_1_bss_25E6C != 0) {
        lbl_1_bss_3C30.unk_A7++;
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
    fn_1_435C( (lbl_1_bss_25CA4));
    fn_1_4310(0x20000);
    fn_1_435C( (lbl_1_bss_25B88));
    fn_1_4310(0x2c3);

    fn_1_A1588(lbl_1_bss_6EAD0.unk_0->unk_0, 0x1e);
}
/* fzgx:end fn_1_3DDAC */

/* fzgx:begin fn_1_3DE80 */
/* fn_1_3DE80: block-private types (p0b) */
/* GamePlayer: see GamePlayer */
/* Obj3C30: see Obj3C30 */
/* GameSlotEntry: see GameSlotEntry */
/* GameSlotTable: see GameSlotTable */

#define FN_1_3DE80_CLAMP(x) ((x) < 0.0f ? 0.0f : ((x) > 1.0f ? 1.0f : (x)))

void fn_1_3DE80(void)
{
    FontDrawPacket packet;
    GameVec eye;
    GameVec at;
    GameVec up;
    f32 t;

    fn_1_98590();
    fn_1_59290();
    fn_1_3FC68(0);
    t = (s32)lbl_1_bss_26C28 / 600.0f;
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
    if ((s32)++lbl_1_bss_26C28 > 1200) {
        lbl_1_bss_26C28 = 1200;
    }

    packet = lbl_1_rodata_26F8;
    packet.image = 0x12;
    packet.x = 320.0f;
    packet.y = 240.0f;
    packet.scale_x = packet.scale_x * (640.0f / fn_1_48690(0x12));
    packet.scale_y = packet.scale_y * (480.0f / fn_1_486C4(packet.image));
    {
        GXColor color = {0x00, 0x00, 0x00, 0x00};

        *(GXColor *)packet.color = color;
    }
    packet.flags = 10;
    packet.alpha = FN_1_3DE80_CLAMP(0.25f * ((s32)lbl_1_bss_26C28 - 240) / 60.0f);
    packet.z = 60.0f;
    fn_1_4F734(&packet);

    packet = lbl_1_rodata_26F8;
    packet.image = 0x8A01;
    packet.x = 320.0f;
    packet.y = 240.0f;
    packet.scale_x *= 6.5f;
    packet.scale_y *= 3.0f;
    {
        GXColor color = {0x50, 0x00, 0x00, 0x00};

        *(GXColor *)packet.color = color;
    }
    packet.flags = 10;
    packet.alpha = FN_1_3DE80_CLAMP(0.25f * ((s32)lbl_1_bss_26C28 - 240) / 60.0f);
    packet.z = 50.0f;
    fn_1_4F734(&packet);

    packet = lbl_1_rodata_26F8;
    packet.image = 0x8A00;
    packet.x = 320.0f;
    packet.y = 240.0f;
    packet.flags = 10;
    packet.alpha = FN_1_3DE80_CLAMP(0.5f * ((s32)lbl_1_bss_26C28 - 60) / 60.0f);
    packet.z = 40.0f;
    fn_1_4F734(&packet);

    if (lbl_1_bss_25BA0 == 0 && lbl_1_bss_26C28 > 60 && fn_1_402D4() != 0) {
        fn_1_304A8();
    }
}
/* fzgx:end fn_1_3DE80 */

/* fzgx:begin fn_1_3E5D0 */
// Resets both state objects and advances the game initialization sequence.

void fn_1_3E5D0(void) {
    fn_1_435C( (lbl_1_bss_25B88));
    fn_1_4310(0);
    fn_1_435C( (lbl_1_bss_25CA4));
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

/* fzgx:begin fn_1_3E62C */
void fn_1_3E62C(void) {
    if (lbl_1_bss_25BA0 == 0) {
        lbl_1_bss_53F4 = 0xD;
        lbl_1_bss_6EAB4.unk_0 |= 0x2C;
        lbl_1_bss_25BA0 = 1;
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

/* fzgx:begin fn_1_3E6D8 */
/* fn_1_3E6D8: block-private types (p0b) */
/* GamePlayer: see GamePlayer */
/* Obj3C30: see Obj3C30 */
/* GameSlotEntry: see GameSlotEntry */
/* GameSlotTable: see GameSlotTable */

void fn_1_3E6D8(void)
{
    /* WARNING: compiler-diff device, not original code (carried from main): the no-op (s32) cast. Retail tests the
       loaded value two times (here and in the inlined fn_1_304A8). Without the cast MWCC drops the second test
       (5 words off). */
    if ((s32)lbl_1_bss_25BA0 == 0 && ((lbl_1_bss_D58.unk_8 >> 8) & 1)) {
        fn_1_304A8();
    }
}
/* fzgx:end fn_1_3E6D8 */

/* fzgx:begin fn_1_3EA70 */
void fn_1_3EA70(void) {
    fn_1_A8F78();
}
/* fzgx:end fn_1_3EA70 */

/* fzgx:begin fn_1_3EA90 */
void fn_1_3EA90(u8 count, u8 *name_src, u8 *code_src, u32 *value_src) {
    u8 slot = lbl_1_bss_3C00;
    s32 i;

    for (i = 0; i < count; i++) {
        lbl_1_bss_2625C[slot + i] = name_src[i];
        if (code_src == NULL || code_src[i] == 0xFF) {
            lbl_1_bss_523C[slot + i] = 0x10;
        } else {
            lbl_1_bss_523C[slot + i] = code_src[i];
        }
        if (value_src == NULL) {
            lbl_1_bss_2627C[slot + i] = 0;
        } else {
            lbl_1_bss_2627C[slot + i] = value_src[i];
        }
        lbl_1_bss_25C48[slot + i] = 50;
    }
    lbl_1_bss_26B7C = count;
}
/* fzgx:end fn_1_3EA90 */

/* fzgx:begin fn_1_3EB78 */
/* fn_1_3EB78: block-private types (p0b) */
/* RaceBuf: see RaceBuf */

void fn_1_3EB78(u8 count, u8 *names, u8 *codes, u32 *values) {
    s32 i;
    s32 n;

    n = 0;
    for (i = 0; n < count && i < 4; i++) {
        if (names[i] == 0xFF) {
            continue;
        }
        lbl_1_bss_2625C[n] = names[i];
        if (codes == NULL || codes[i] == 0xFF) {
            lbl_1_bss_523C[n] = 1;
        } else {
            lbl_1_bss_523C[n] = codes[i];
        }
        if (values == NULL) {
            lbl_1_bss_2627C[n] = 0;
        } else {
            lbl_1_bss_2627C[n] = values[i];
        }
        lbl_1_bss_25E98[n] = i;
        lbl_1_bss_25C48[n] = lbl_1_bss_8B3A0.unk_9F[i];
        n++;
    }
    lbl_1_bss_3C00 = n;
    lbl_1_bss_3C30.unk_8 = n;
}
/* fzgx:end fn_1_3EB78 */

/* fzgx:begin fn_1_3EC88 */
/* fn_1_3EC88: block-private types (p0b) */
/* RaceBuf: see RaceBuf */

void fn_1_3EC88(u8 count, GameEntrant *src) {
    s16 i;
    s16 n;

    n = 0;
    for (i = 0; n < count && i < 4; i++) {
        if (src[i].name == 0xFF) {
            continue;
        }
        lbl_1_bss_2625C[n] = src[i].name;
        if (src[i].letter == 0xFF) {
            lbl_1_bss_523C[n] = 1;
        } else {
            lbl_1_bss_523C[n] = src[i].letter;
        }
        lbl_1_bss_2627C[n] = 0;
        lbl_1_bss_25E98[n] = i;
        fn_80008BA8(&lbl_1_bss_5480[n].unk_4, &src[i], sizeof(GameEntrant));
        lbl_1_bss_53F8[n] = &lbl_1_bss_5480[n].unk_4;
        n++;
    }
    lbl_1_bss_3C00 = n;
    lbl_1_bss_3C30.unk_8 = n;
}
/* fzgx:end fn_1_3EC88 */

/* fzgx:begin fn_1_3ED8C */
/* fn_1_3ED8C: block-private types (p0b) */
/* Obj3C30: see Obj3C30 */

void fn_1_3ED8C(Obj3C30 *setup, u8 unk_4, u8 unk_1404, u8 course, u8 unk_7, u8 racers, u32 flags) {
    u32 i;

    if (setup == NULL) {
        setup = &lbl_1_bss_3C30;
    }
    setup->unk_0 = flags;
    setup->unk_4 = unk_4;
    setup->unk_1404 = unk_1404;
    setup->unk_5 = lbl_1_data_5B7C;
    if (lbl_1_data_5B7C == 1) {
        setup->unk_A6 = course;
        setup->unk_6 = 0;
    } else {
        setup->unk_A6 = 0xFF;
        setup->unk_6 = course;
    }
    setup->unk_7 = unk_7;
    setup->unk_9 = racers;
    setup->unk_8 = 0;
    setup->unk_1464 = 0;
    setup->unk_146C = 0;
    setup->unk_146D = 0;
    setup->unk_1470 = 0;
    setup->unk_146E = 1500;
    lbl_1_bss_26C5C = 0;
    /* retail stores one byte at 0x26B7C (stb), though symbols.txt types lbl_1_bss_26B7A as 2-byte data */
    lbl_1_bss_26B7C = 0;
    lbl_1_bss_3C00 = 0;
    lbl_1_bss_262F4 = 1;
    for (i = 0; i < 30; i++) {
        lbl_1_bss_2625C[i] = i;
        lbl_1_bss_523C[i] = 0x10;
        lbl_1_bss_2627C[i] = 0;
        lbl_1_bss_53F8[i] = NULL;
    }
    setup->unk_1471 = 0xFF;
    setup->unk_1472 = 0xFF;
}
/* fzgx:end fn_1_3ED8C */

/* fzgx:begin fn_1_3EF08 */
void fn_1_3EF08(u8 value) {
    lbl_1_bss_262F4 = value;
}
/* fzgx:end fn_1_3EF08 */

/* fzgx:begin fn_1_3EF14 */
static inline s16 current_mode(void) {
    return lbl_1_bss_960;
}

// Selects the appropriate buffer initialization based on the current mode.

void fn_1_3EF14(void *arg1) {
    if (lbl_1_bss_3C12 != 0 ||
        (u16)(current_mode() - 13) <= 1 ||
        current_mode() == 10 ||
        current_mode() == 16) {
        fn_80008BA8(arg1, &lbl_1_bss_3C30, sizeof(Obj3C30));
    } else {
        fn_80008BEC(arg1, (0), 0x14b8);
    }
}
/* fzgx:end fn_1_3EF14 */

/* fzgx:begin fn_1_3EF8C */
// Stores the value unless initialization has already occurred.

void fn_1_3EF8C(u8 value) {
    if (lbl_1_bss_3C12 == 0) {
        lbl_1_data_5B7C = value;
    }
}
/* fzgx:end fn_1_3EF8C */

/* fzgx:begin fn_1_3EFA8 */
// Reports whether the relevant state is active and enabled.

s32 fn_1_3EFA8(void) {
    s32 result = 0;

    if (lbl_1_bss_50F8 != 0 || (lbl_1_bss_3C30.unk_0 & 2) != 0 || lbl_1_bss_26B50 != 0) {
        if (lbl_1_bss_3C12 != 0) {
            result = 1;
        }
    }
    return result;
}
/* fzgx:end fn_1_3EFA8 */

/* fzgx:begin fn_1_3EFF0 */
void fn_1_3EFF0(void (*arg1)(struct Obj3C30 *), u8 arg2) {
    lbl_1_bss_25E74 = arg1;
    lbl_1_bss_3C10 = arg2;
    lbl_1_bss_3C11 = 1;
    lbl_1_bss_26C58 = 0;
    lbl_1_bss_26C64 = 0;
}
/* fzgx:end fn_1_3EFF0 */

/* fzgx:begin fn_1_3F02C */
void fn_1_3F02C(void (*arg1)(Obj3C30 *gs)) {
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
GameRaceRecord *fn_1_3F0D8(u32 index, f32 *value, u8 *flag) {
    u8 idx = index;
    *value = lbl_1_bss_26304[idx];
    *flag = lbl_1_bss_26B04[idx];
    return &lbl_1_bss_26314[idx];
}
/* fzgx:end fn_1_3F0D8 */

/* fzgx:begin fn_1_3F114 */
// Returns the current global status byte when the subsystem is enabled.

u8 fn_1_3F114(void) {
    if (lbl_1_bss_3C12 != 0) {
        return lbl_1_bss_3C30.unk_4;
    }
    return 0;
}
/* fzgx:end fn_1_3F114 */

/* fzgx:begin fn_1_3F13C */
u8 fn_1_3F13C(void) {
    if (lbl_1_bss_3C12 != 0) {
        return lbl_1_bss_3C30.unk_5;
    }
    return 0xff;
}
/* fzgx:end fn_1_3F13C */

/* fzgx:begin fn_1_3F164 */
// Reports whether the active state permits the current mode.

s32 fn_1_3F164(void) {
    s32 result = 0;

    if (lbl_1_bss_50F8 != 0 || (lbl_1_bss_3C30.unk_0 & 2) != 0 || lbl_1_bss_26B50 != 0) {
        if (lbl_1_bss_3C12 != 0) {
            result = 1;
        }
    }
    return result;
}
/* fzgx:end fn_1_3F164 */

/* fzgx:begin fn_1_3F1AC */
u32 fn_1_3F1AC(u32 arg0) {
    if (lbl_1_bss_3C12 == 0) {
        return 0;
    }
    return (lbl_1_bss_3C30.unk_0 & 2) ? 1 : 0;
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
    return lbl_1_bss_2625C[index & 0xff];
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
    GameEntrant *entry = lbl_1_bss_53F8[masked];

    if (entry != 0) {
        return entry->unk_B;
    }

    return lbl_1_bss_25C48[masked];
}
/* fzgx:end fn_1_3F264 */

/* fzgx:begin fn_1_3F2A0 */
void fn_1_3F2A0(void)
{
    s32 lim = !((fn_1_3F2A0_obj *)&lbl_1_bss_3C30)->unk_5 ? (s32)((fn_1_3F2A0_obj *)&lbl_1_bss_3C30)->unk_8 : ((fn_1_3F2A0_obj *)&lbl_1_bss_3C30)->unk_9;
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
        if (!((fn_1_3F2A0_obj *)&lbl_1_bss_3C30)->unk_5) {
            while (((fn_1_3F2A0_obj *)&lbl_1_bss_3C30)->ids[i] >= lim) {
                i++;
            }
        }
        id = ((fn_1_3F2A0_obj *)&lbl_1_bss_3C30)->ids[i];
        cnt = 0;
        p = &((fn_1_3F2A0_obj *)&lbl_1_bss_3C30)->rec[id];
        if (!((fn_1_3F2A0_obj *)&lbl_1_bss_3C30)->unk_5) {
            score = ((fn_1_3F2A0_obj *)&lbl_1_bss_3C30)->score[id];
            p->unk_4 = score;
            p->unk_9E = ((fn_1_3F2A0_obj *)&lbl_1_bss_3C30)->pair[id];
        } else {
            score = p->unk_4;
        }
        mode = ((fn_1_3F2A0_obj *)&lbl_1_bss_3C30)->unk_5;
        for (k = 0; k < ((fn_1_3F2A0_obj *)&lbl_1_bss_3C30)->unk_9; k++) {
            if (i == k) {
                continue;
            }
            kid = ((fn_1_3F2A0_obj *)&lbl_1_bss_3C30)->ids[k];
            if (!mode) {
                if (kid >= lim) {
                    continue;
                }
                other = ((fn_1_3F2A0_obj *)&lbl_1_bss_3C30)->score[kid];
            } else {
                other = ((fn_1_3F2A0_obj *)&lbl_1_bss_3C30)->rec[kid].unk_4;
            }
            if (score < other) {
                cnt++;
            } else if (score == other && i > k) {
                cnt++;
            }
        }
        ((fn_1_3F2A0_obj *)&lbl_1_bss_3C30)->ord[cnt] = id;
        p->unk_8 = cnt;
        if (!((fn_1_3F2A0_obj *)&lbl_1_bss_3C30)->unk_A7 && ((fn_1_3F2A0_obj *)&lbl_1_bss_3C30)->unk_5) {
            p->unk_83 = cnt;
        }
    }
}
/* fzgx:end fn_1_3F2A0 */

/* fzgx:begin fn_1_3F440 */
// Reports an out-of-range index and returns the corresponding limit when valid.

s32 fn_1_3F440(u8 index) {
    if (index > 0x1d) {
        OSPanic("game.c", 0x2654, "Error: Rank is wrong.\n");
    }

    if (lbl_1_bss_3C30.unk_8 > lbl_1_bss_3C30.unk_E[index]) {
        return lbl_1_bss_3C30.unk_E[index];
    }

    return -1;
}
/* fzgx:end fn_1_3F440 */

/* fzgx:begin fn_1_3F4B8 */
/* fn_1_3F4B8: block-private types (p0b) */
/* Obj3C30: see Obj3C30 */

void fn_1_3F4B8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5)
{
    lbl_1_bss_3C30.unk_13F8[0] = arg0 * 60;
    lbl_1_bss_3C30.unk_1402 = arg5;
    lbl_1_bss_3C30.unk_13F8[1] = arg1 * 60;
    lbl_1_bss_3C30.unk_13F8[2] = arg2 * 60;
    lbl_1_bss_3C30.unk_13F8[3] = arg3 * 60;
    lbl_1_bss_3C30.unk_13F8[4] = arg4 * 60;
    lbl_1_bss_26C5C = 1;
}
/* fzgx:end fn_1_3F4B8 */

/* fzgx:begin fn_1_3F4FC */
void fn_1_3F4FC(void) {
    s16 i;
    s32 mode;
    u32 flags;
    char buffer[0x20];
    char temp[0x20];

    fn_1_12AB38("vehicle/");
    fn_1_465D0("carcmntex.tpl", 1);

    i = 0;
    while (i < lbl_1_bss_3C30.unk_9) {
        flags = lbl_1_bss_25E9C[i].unk_C;
        mode = 0;
        if (flags & 0x100000) {
            mode = 1;
        }

        if (flags & 0xf0000000) {
            sprintf(buffer, "%s_p.arc.lz", fn_1_7F518(lbl_1_bss_25E9C[i].unk_2, temp, mode));
        } else {
            sprintf(buffer, "%s_e.arc.lz", fn_1_7F518(lbl_1_bss_25E9C[i].unk_2, temp, mode));
        }

        fn_1_465D0(buffer, 1);
        i++;
    }

    fn_1_12AB38("..");
}
/* fzgx:end fn_1_3F4FC */

/* fzgx:begin fn_1_3F5F8 */
static inline s8 game_one_player(void)
{
    return lbl_1_bss_3C30.unk_8 == 1;
}

static inline s32 game_car_lod_base(void)
{
    s32 lod = 4;
    s8 single;

    single = game_one_player();
    if (single) {
        lod = 0;
    }
    return lod;
}

void fn_1_3F5F8(void)
{
    s16 lod;
    s8 i;
    s16 j;
    s32 mode;
    s16 car;
    u32 name[16];
    s32 path[17];

    lod = game_car_lod_base();
    {
        s32 modes[5] = { 0x40000000, 0x40000000, 0x40000000, 0x20000000, 0x20000000 };

        mode = modes[lbl_1_bss_3C30.unk_8];
    }
    if (lbl_1_bss_960 == 10 || lbl_1_bss_960 == 12) {
        return;
    }
    for (i = 0; i < lbl_1_bss_3C30.unk_8; i++) {
        car = lbl_1_bss_2625C[i];
        if (car <= 40) {
            fn_1_465D0(fn_1_12D254(car, mode), 1);
            fn_80006E10("vehicle/");
            fn_80006E10(fn_1_7F518(car, path, 0));
            for (j = lod; j <= lod + 3; j++) {
                fn_1_465D0(fn_1_7F58C(car, name, j, 0), 1);
            }
            fn_80006E10("../../");
        }
    }
}
/* fzgx:end fn_1_3F5F8 */

/* fzgx:begin fn_1_3F75C */
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
    return lbl_1_bss_3C30.unk_A;
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
    lbl_1_bss_3C30.unk_146D = ((input / 5) >> 1);
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
        lbl_1_bss_960 == 0x000c) {
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_3F864 */

/* fzgx:begin fn_1_3F894 */
// Enables the associated game state and records the current mode.

void fn_1_3F894(void) {
    lbl_1_bss_53F4 = lbl_1_bss_3C30.unk_7;
    lbl_1_bss_25BA0 = 1;
    lbl_1_bss_26C2C = 1;
}
/* fzgx:end fn_1_3F894 */

/* fzgx:begin fn_1_3F8C0 */
u32 fn_1_3F8C0(void) {
    return lbl_1_bss_262F8;
}
/* fzgx:end fn_1_3F8C0 */

/* fzgx:begin fn_1_3F8D0 */
void fn_1_3F8D0(void) {
    lbl_1_bss_38204[0] = 0;
    lbl_1_bss_38204[1] = 0;
    lbl_1_bss_38204[2] = 0;
    lbl_1_bss_38204[3] = 0;
}
/* fzgx:end fn_1_3F8D0 */

/* fzgx:begin fn_1_3F8EC */
/* fn_1_3F8EC: block-private types (p0b) */
typedef struct {
    f32 x, y, z;
} Vec3_3F8EC;

/* WARNING: compiler-diff device, not original code (carried from main): `#pragma opt_propagation off` and the
   pointer local `fzgx_value`. Retail loads the three matrix floats in the order 8, 0x18, 0x28 and builds &vec (r3)
   before them; without the pair the first load is forwarded into its product (14 words, v/3F8EC_n1..n10.c). */
#pragma opt_propagation off

void fn_1_3F8EC(f32 arg0) {
    f32 *fzgx_value;
    s16 e;
    ObjA *a;
    u32 id;
    ObjB *b;
    s32 cnt;
    u16 tmp;
    s32 d;
    s16 xa;
    s16 ya;
    Vec3_3F8EC vec;
    f32 q2;
    f32 q1;

    if (camera_get_flags() == 0 && (s16)camera_get_status() == 1 && lbl_1_bss_3C2A < 42) {
        id = fn_1_5910();
        e = camera_get_entry_field_0x2((u8)id);
        if (e != -1) {
            a = (ObjA *)fn_1_86254(e);
            if (a != 0 && (a->unk_0 & 0x800) == 0) {
                b = (ObjB *)fn_1_8627C(e);
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
                        if (lbl_1_bss_38204[id] < 110) {
                            lbl_1_bss_38204[id] += 1;
                        }
                    } else if (lbl_1_bss_38204[id] != 0) {
                        lbl_1_bss_38204[id] -= 1;
                    }
                    tmp = lbl_1_bss_38204[id];
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
                        lbl_8006D7F4((0.0f), (lbl_801A66A0 % 15) / (14.0f), (0.0f));
                        lbl_8006DB74(lbl_801A6D00 + 0x60);
                        lbl_8006D7F4((0.0f), (-0.100000001f), (-2.0f));
                        mathutil_mtxA_rotate_y(ya);
                        mathutil_mtxA_rotate_x(xa);
                        fn_8006E294(&vec);
                        mathutil_mtxA_rotate_z((s16)-lbl_8006D24C(vec.x, vec.y));
                        fn_80072558();
                        if (cnt < 20) {
                            fn_1_55FF0(cnt / (20.0f));
                        }
                        fn_1_56018(1);
                        fn_1_560F0(0, (u32)(lbl_801A6D00 + 0x60));
                        fn_1_556B8(*(void **)((u8 *)(*(u32 **)((*(u32 *)((u8 *)lbl_1_bss_38460 + 8)) + 8)) + 0x108));
                        fn_1_56018(0);
                    }
                }
            }
        }
    }
}

#pragma opt_propagation reset
/* fzgx:end fn_1_3F8EC */

/* fzgx:begin fn_1_3FBF4 */
void fn_1_3FBF4(u32 arg0) {
    u32 v0;
    v0 = (lbl_1_bss_3C30.unk_0 & 0xFFFFFFFD);
    if ((s32)arg0 != 0) {
    v0 = (lbl_1_bss_3C30.unk_0 | 2);
    }
    lbl_1_bss_3C30.unk_0 = v0;
}
/* fzgx:end fn_1_3FBF4 */

/* fzgx:begin fn_1_3FC18 */
u16 fn_1_3FC18(void) {
    return lbl_1_bss_26C68;
}
/* fzgx:end fn_1_3FC18 */

/* fzgx:begin fn_1_3FC28 */
u32 fn_1_3FC28(void) {
    return lbl_1_bss_3C30.unk_0 & 0x00800000;
}
/* fzgx:end fn_1_3FC28 */

/* fzgx:begin fn_1_3FC38 */
u8 fn_1_3FC38(void) {
    return lbl_1_bss_3C12;
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

u8 fn_1_3FC9C(void) {
    return lbl_1_bss_8B3A0.unk_8;
}
/* fzgx:end fn_1_3FC9C */

/* fzgx:begin fn_1_3FCB0 */
void fn_1_3FCB0(s32 value) {
    if (value != 0) {
        lbl_1_bss_3C08 |= value;
    } else {
        lbl_1_bss_3C08 = 0;
    }
}
/* fzgx:end fn_1_3FCB0 */

/* fzgx:begin fn_1_3FCD4 */
void fn_1_3FCD4(u32 mask) {
    if (mask == 0) {
        lbl_1_data_5B80 = 0xffffffff;
    } else {
        lbl_1_data_5B80 &= ~mask;
    }
}
/* fzgx:end fn_1_3FCD4 */

/* fzgx:begin fn_1_3FCF8 */
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
    v1 = (v1 + 960);
    }
    v1 = 0x80000000;
    t0 = fn_800075AC(v1, 8192, 1);
    v1 = t0;
    return v1;
}
/* fzgx:end fn_1_3FCF8 */

/* fzgx:begin fn_1_3FDA8 */
void fn_1_3FDA8(u32 arg0, u32 arg1) {
    s32 condition;
    u32 value;

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
    fn_1_3F8C("ticket_control", fn_1_2DB50, &lbl_1_bss_5138, 30);
    fn_1_435C(arg1);
    fn_1_3F8C("disp_ticket_message", fn_1_2D888, &lbl_1_bss_5138, 30);
    fn_1_435C(value);
    lbl_1_bss_5138.unk_E2 = 1;
    fn_1_2D524(&lbl_1_bss_5138);

done:
    return;
}
/* fzgx:end fn_1_3FDA8 */

/* fzgx:begin fn_1_3FF90 */
void fn_1_3FF90(void) {
    u32 bss_25b88;
    u32 bss_25ca4;
    int flag;

    bss_25ca4 = lbl_1_bss_25CA4;
    bss_25b88 = lbl_1_bss_25B88;
    if (lbl_1_bss_5138.unk_0 != 0) {
        lbl_1_bss_5138.unk_E1 = 0;
    } else {
        if (lbl_1_bss_5138.unk_E3 == 0xff) {
            flag = 0;
        } else if (ghost_test_record_flag0(lbl_1_bss_3C30.unk_6) != 0) {
            flag = 0;
        } else {
            flag = 1;
        }
        if (flag != 0) {
            lbl_1_bss_5138.unk_E1 = 1;
        } else {
            if (lbl_1_bss_5138.unk_E5 == 0xff) {
                flag = 0;
            } else if (fn_1_F9D44(lbl_1_bss_5138.unk_E5 & 0xf) != 0) {
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
    fn_1_3F8C("ticket_control", fn_1_2DB50, &lbl_1_bss_5138, 30);
    fn_1_435C(bss_25ca4);
    fn_1_3F8C("disp_ticket_message", fn_1_2D888, &lbl_1_bss_5138, 30);
    bss_25b88 = fn_1_435C(bss_25b88);
    lbl_1_bss_5138.unk_E2 = 1;
    fn_1_2D524(&lbl_1_bss_5138);
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

/* fzgx:begin fn_1_402A4 */
s32 fn_1_402A4(u32 index) {
    static const s16 table[14] = {
        0xB5, 0xB6, 0xAD, 0xB3, 0xB8, 0xB2, 0xB1, 0xAE, 0xB4, 0xB9, 0xB0, 0xAF, 0xB7, -1,
    };

    return table[lbl_1_data_2B144[lbl_1_data_2B0D4[index]] - 1];
}
/* fzgx:end fn_1_402A4 */

/* fzgx:begin fn_1_402D4 */
int fn_1_402D4(void) {
    s32 i;

    if (lbl_1_bss_3C30.unk_8 != 0) {
        for (i = 0; i < lbl_1_bss_3C30.unk_8; i++) {
            if ((lbl_1_bss_9F8[lbl_1_bss_25E98[i]].unk_8 >> 8) & 1) {
                return 1;
            }
        }
    } else if ((lbl_1_bss_9F8[0].unk_8 >> 12) & 1) {
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_402D4 */

/* fzgx:begin fn_1_40354 */
int fn_1_40354(void) {
    s32 i;

    if (lbl_1_bss_3C30.unk_8 != 0) {
        for (i = 0; i < lbl_1_bss_3C30.unk_8; i++) {
            if ((lbl_1_bss_9F8[lbl_1_bss_25E98[i]].unk_8 >> 12) & 1) {
                return 1;
            }
        }
    } else if ((lbl_1_bss_9F8[0].unk_8 >> 12) & 1) {
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_40354 */

/* fzgx:begin fn_1_403D4 */
/* The colour step of the menu widget. Retail has it inlined in fn_1_40710. Its ten colour constants (.rodata
 * ED0..EF4) come before the constants of fn_1_403D4, so its place is here. */
static inline void game_widget_step_colors(Fn40710Object *self) {
    GXColor *other;

    self->enabled &= 1;
    if (self->enabled != 0) {
        GXColor selected = {0xFF, 0xF2, 0x00, 0xFF};

        self->unk_2C = selected;
        other = &self->unk_28;
    } else {
        GXColor selected = {0xFF, 0xF2, 0x00, 0xFF};

        self->unk_28 = selected;
        other = &self->unk_2C;
    }
    {
        GXColor limit = {0xFF, 0xFF, 0xFF, 0x96};

        if (other->r < limit.r - 0x14) {
            other->r += 0x14;
        } else {
            GXColor end = {0xFF, 0xFF, 0xFF, 0x96};

            other->r = end.r;
        }
    }
    {
        GXColor limit = {0xFF, 0xFF, 0xFF, 0x96};

        if (other->g < limit.g - 0x14) {
            other->g += 0x14;
        } else {
            GXColor end = {0xFF, 0xFF, 0xFF, 0x96};

            other->g = end.g;
        }
    }
    {
        GXColor limit = {0xFF, 0xFF, 0xFF, 0x96};

        if (other->b < limit.b - 0x14) {
            other->b += 0x14;
        } else {
            GXColor end = {0xFF, 0xFF, 0xFF, 0x96};

            other->b = end.b;
        }
    }
    {
        GXColor limit = {0xFF, 0xFF, 0xFF, 0x96};

        if (other->a > limit.a + 0x14) {
            other->a -= 0x14;
        } else {
            GXColor end = {0xFF, 0xFF, 0xFF, 0x96};

            other->a = end.a;
        }
    }
}

void fn_1_403D4(Fn40710Object *obj) {
    f32 h;
    f32 fade;
    f32 lineH;
    s32 i;
    char *text;

    fade = obj->unk_8;
    text = fn_1_15BA78(obj->text);
    fn_1_49410();
    fn_1_495FC();
    fn_1_4954C(obj->unk_C - 0.001f);
    fn_1_495C8(1);
    fn_1_49590(0.4f);
    fn_1_495B0(0x80000000);
    fn_1_494DC(0x2a);
    fn_1_4955C(0.75f, 0.75f * obj->unk_8);
    obj->unk_18 = (s32)(150.0f + fn_1_4B068(text));
    if (obj->unk_18 < 360.0f) {
        obj->unk_18 = 360.0f;
    }
    h = fn_1_4B090(text);
    lineH = 30.0f + h;
    h *= 0.3f;
    obj->unk_1C = 90.0f + lineH;
    {
        GXColor color = {0xFF, 0xFF, 0xFF, 0x00};

        fn_1_49514(&color);
    }
    fn_1_495A0(obj->unk_8);
    fn_1_496FC(obj->unk_10, h + ((obj->unk_14 - lineH) + (1.0f - fade) * lineH));
    fn_1_4A0D8(text);
    fn_1_496FC(obj->unk_10, h + ((obj->unk_14 - 10.0f) + 10.0f * (1.0f - fade)));
    for (i = 0; i < 2; i++) {
        char *labels[2] = {"YES", "NO"};
        GXColor color = (&obj->unk_28)[i];
        f32 alpha;

        fn_1_49514(&color);
        alpha = fade * ((&obj->unk_28)[i].a / 255.0f);
        if (alpha < 0.0f) {
            alpha = 0.0f;
        }
        fn_1_495A0(alpha);
        fn_1_496FC((obj->unk_10 - 90.0f) + (i * 180), h + (obj->unk_14 + 20.0f * fade));
        fn_1_4A0D8(fn_1_15BA78(labels[i]));
    }
}
/* fzgx:end fn_1_403D4 */

/* fzgx:begin fn_1_4068C */
void fn_1_4068C(Fn40710Object *obj) {
    fn_80008BEC(obj, 0, 0x30);
    obj->unk_C = 0.0006f;
    {
        GXColor color = {0xFF, 0xFF, 0xFF, 0x96};
        obj->unk_2C = color;
    }
    obj->unk_28 = obj->unk_2C;
    obj->unk_10 = 320.0f;
    obj->unk_14 = 240.0f;
    obj->unk_18 = 200.0f;
    obj->unk_1C = 200.0f;
    obj->flags |= 1;
}
/* fzgx:end fn_1_4068C */

/* fzgx:begin fn_1_40710 */
void fn_1_40710(Fn40710Object *obj) {
    switch (obj->state) {
    case 2:
        game_widget_step_colors(obj);
        break;
    case 0:
    case 1:
        break;
    default:
        return;
    }
    if (obj->enabled != obj->applied) {
        fn_1_A2DC4(0xA9011300);
        obj->applied = obj->enabled;
    }
    if (obj->flags & 2) {
        fn_1_A2DC4(0xA9011100);
        obj->flags &= ~3;
    } else if (obj->flags & 4) {
        fn_1_A2DC4(0xA9011000);
        obj->flags &= ~5;
    }
}
/* fzgx:end fn_1_40710 */

/* fzgx:begin fn_1_408E8 */
/* fn_1_408E8: block-private types (p0b) */
struct fn_1_408E8_lbl_1_rodata_BD8_408E8 {
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

void fn_1_408E8(Fn40710Object *obj) {
    f32 scale;
    s32 width;
    s32 height;
    s32 frameWidth;
    s32 frameHeight;
    FontDrawPacket packet;

    if (obj->flags & 1) {
        if (obj->unk_8 < 0.92f) {
            obj->unk_8 += 0.08f;
        } else {
            obj->unk_8 = 1.0f;
        }
    } else {
        if (obj->unk_8 > 0.08f) {
            obj->unk_8 -= 0.08f;
        } else {
            obj->unk_8 = 0.0f;
            return;
        }
    }
    scale = 1.1f * obj->unk_8;
    if (scale > 1.0f) {
        scale = 1.0f;
    }
    switch (obj->state) {
    case 1:
        if (obj->unk_20 != 0) {
            break;
        }
    case 0:
        width = obj->unk_18 * scale;
        height = obj->unk_1C * scale;
        break;
    case 2:
        fn_1_403D4(obj);
        width = obj->unk_18;
        height = obj->unk_1C * scale;
        break;
    default:
        return;
    }
    packet = lbl_1_rodata_26F8;
    packet.x = obj->unk_10;
    packet.y = obj->unk_14;
    packet.z = obj->unk_C;
    packet.flags = 10;
    packet.image = 2;
    packet.alpha = obj->unk_8;
    frameWidth = 3.0f * (18.0f * obj->unk_8);
    frameHeight = 3.0f * (45.0f * obj->unk_8);
    if (frameWidth > 18 || width > 18) {
        frameWidth = 18;
    }
    if (frameHeight > 45 || height > 45) {
        frameHeight = 45;
    }
    fn_1_50A90(&packet, frameWidth, frameHeight, width, height);
    {
        GXColor color = {0xFF, 0xFF, 0xFF, 0x00};

        fn_1_49514(&color);
    }
    fn_1_49614();
}
/* fzgx:end fn_1_408E8 */

/* fzgx:begin fn_1_40B14 */
u8 *fn_1_40B14(void) {
    return lbl_1_bss_26B54;
}
/* fzgx:end fn_1_40B14 */

/* fzgx:begin fn_1_40B20 */
s32 fn_1_40B20(void) {
    s32 i;
    s32 n;
    u8 a7;
    u8 min;
    u8 v;

    if (lbl_1_bss_3C30.unk_5 == 5) {
        return *(s8 *)(&lbl_1_bss_9C + 6);
    }
    if (lbl_1_bss_3C30.unk_5 != 1) {
        return -1;
    }
    a7 = lbl_1_bss_3C30.unk_A7;
    if (a7 == 0) {
        return -1;
    }
    n = lbl_1_bss_3C30.unk_9;
    min = lbl_1_bss_3C30.unk_8;
    for (i = 0; i < n; i++) {
        v = lbl_1_bss_3C30.unk_1394[i];
        if ((s32)v >= min) {
            if (lbl_1_bss_3C30.unk_D4[v].unk_E[a7] != 254) {
                return v;
            }
        }
    }
    return -1;
}
/* fzgx:end fn_1_40B20 */

/* fzgx:begin fn_1_40BB4 */
u8 fn_1_40BB4(void) {
    return (s8)lbl_1_bss_5104 != -1;
}
/* fzgx:end fn_1_40BB4 */

/* fzgx:begin fn_1_40BD4 */
void fn_1_40BD4(void) {
    lbl_1_bss_3820C = 0;
}
/* fzgx:end fn_1_40BD4 */

/* fzgx:begin fn_1_40BE4 */
typedef struct GameCaptureRect {
    s16 x;
    s16 y;
    s16 width;
    s16 height;
    s32 unk_8;
    s32 unk_C;
} GameCaptureRect;

void fn_1_40BE4(void) {
    u8 ok = 1;
    u32 n;
    void *buf;
    u8 sel;

    if (lbl_1_bss_960 == 2) {
        f32 r;

        if (fn_1_86254(0)->unk_6 > 0x29) {
            r = fn_1_84038(fn_1_868C0(0), 0, 1, 0.5f);
        } else {
            r = fn_1_84038(fn_1_868C0(0), 0, 0, 0.5f);
        }
        if (r < 80.0f || r > 400.0f) {
            ok = 0;
        }
    }
    if (lbl_1_bss_38210 == 0) {
        return;
    }
    {
        GameCaptureRect rect = {0, 0, 640, 480, 0, 1};

        sel = fn_1_76504(0x25, &rect, 0);
    }
    if (lbl_1_bss_3C1C == (void *)-1) {
        buf = lbl_801A63D0;
    } else {
        buf = lbl_1_bss_3C1C;
    }
    fn_1_7269C(sel, 0, buf);
    n = lbl_1_bss_38210 - 1;
    lbl_1_bss_38210 = n;
    if ((n < lbl_1_bss_38214 && ok) || n == 0) {
        fn_1_4030(fn_1_40D44);
    }
}
/* fzgx:end fn_1_40BE4 */

/* fzgx:begin fn_1_40D44 */
void fn_1_40D44(void) {
    u32 result;
    void *state;
    void *arg;

    result = fn_1_40EE4();
    state = lbl_1_bss_3C1C;
    if (state == (void *)-1) {
        lbl_1_bss_3C1C = NULL;
        arg = lbl_801A63D0;
    } else {
        arg = state;
    }

    ARQPostRequest(lbl_1_bss_38218, 0, 0, 1, (u32)arg, result,
                lbl_1_bss_26C34, 0);

    lbl_1_bss_3820C = lbl_1_bss_3820C + 1;
    if (lbl_1_bss_3820C > 6 || result >= 0x00f95fff) {
        lbl_1_bss_3820C = 6;
    }

    fn_1_4060();
}
/* fzgx:end fn_1_40D44 */

/* fzgx:begin fn_1_40E08 */
// Initializes the random-selection bounds and schedules the next callback.

void fn_1_40E08(u32 arg0) {
    u32 value;
    u32 half;
    u32 max;
    u32 remainder;

    if (lbl_1_bss_960 == 0x10) {
        lbl_1_bss_3C1C = (void *)-1;
    }

    lbl_1_bss_38210 = arg0;
    if (arg0 < 5) {
        lbl_1_bss_38210 = 5;
    }

    value = (lbl_801A63C0) * 0x676A4B6B + 0x33CB;
    lbl_801A63C0 = value;

    half = lbl_1_bss_38210 >> 1;
    max = lbl_1_bss_38210 - 5;
    remainder = ((value >> 16) & 0x7FFF) % half;
    lbl_1_bss_38214 = half + remainder;
    if (lbl_1_bss_38214 > max) {
        lbl_1_bss_38214 = max;
    }

    fn_1_3F8C("game_capture", fn_1_40BE4, 0, 1);
}
/* fzgx:end fn_1_40E08 */

/* fzgx:begin fn_1_40ED4 */
u8 fn_1_40ED4(void) {
    return lbl_1_bss_3820C;
}
/* fzgx:end fn_1_40ED4 */

/* fzgx:begin fn_1_40EE4 */
u32 fn_1_40EE4(void) {
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
    return lbl_1_bss_25E90;
}
/* fzgx:end fn_1_40F44 */
