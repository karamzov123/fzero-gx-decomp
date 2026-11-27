#include "types.h"
#include "sofdec/mpv.h"
#pragma opt_propagation off

/* --- rel/movie_module/fn_12_AB60.c --- */
extern u32 fn_12_A660(u32, u32);
extern u32 fn_12_CAB4(u32, u32);

struct fn_12_AB60_Copy80 { u32 a[20]; };

s32 fn_12_AB60(u32 arg0, u32 arg1) {
    u32 v0;
    u32 t0, t1;
    t0 = fn_12_CAB4(arg0, arg1);
    v0 = t0;
    if ((s32)t0 != 0) {
    v0 = 0;
    t1 = fn_12_A660(v0, (0xFF030000 + 524));
    v0 = t1;
    } else {
    *(struct fn_12_AB60_Copy80 *)arg1 = *(struct fn_12_AB60_Copy80 *)((u8 *)arg0 + 464);
    v0 = 0;
    }
    return v0;
}

/* --- rel/movie_module/fn_12_ABDC.c --- */
typedef struct Sig_fn_12_ABDC_MPVContext Sig_fn_12_ABDC_MPVContext;
typedef struct Sig_fn_12_ABDC_SJInterface Sig_fn_12_ABDC_SJInterface;
typedef struct Sig_fn_12_ABDC_SJ Sig_fn_12_ABDC_SJ;
typedef struct Sig_fn_12_ABDC_MPVDecoderFields {
 union { unsigned char padding_extent[168]; struct { unsigned char padding_field_1AC[28]; s32 field_1AC; } view_field_1AC; } fields;
} Sig_fn_12_ABDC_MPVDecoderFields;
typedef union Sig_fn_12_ABDC_MPVConditionState {
 union { unsigned char padding_extent[168]; struct { int conditions[17]; } view_conditions; struct { Sig_fn_12_ABDC_MPVDecoderFields decoder; } view_decoder; } fields;
} Sig_fn_12_ABDC_MPVConditionState;
typedef struct Sig_fn_12_ABDC_MPVErrorInfo {
 union { unsigned char padding_extent[20]; struct { unsigned char padding_field_0C[12]; int field_0C; } view_field_0C; struct { unsigned char padding_field_10[16]; int field_10; } view_field_10; } fields;
} Sig_fn_12_ABDC_MPVErrorInfo;
typedef struct Sig_fn_12_ABDC_SJCK {
 union { unsigned char padding_extent[8]; struct { unsigned char *data; } view_data; struct { unsigned char padding_len[4]; int len; } view_len; } fields;
} Sig_fn_12_ABDC_SJCK;
struct Sig_fn_12_ABDC_MPVContext {
 union {
 struct { unsigned char padding_chunk[4808]; Sig_fn_12_ABDC_SJCK chunk; } view_chunk;
 unsigned char padding_extent[4992];
 struct { unsigned char padding_condition_state[400]; Sig_fn_12_ABDC_MPVConditionState condition_state; } view_condition_state;
 struct { unsigned char padding_error_info[544]; Sig_fn_12_ABDC_MPVErrorInfo error_info; } view_error_info;
 struct { unsigned char padding_field_1300[4800]; s32 field_1300; } view_field_1300;
 struct { unsigned char padding_field_1304[4804]; s32 field_1304; } view_field_1304;
 struct { unsigned char padding_field_1324[4852]; s32 field_1324; } view_field_1324;
 } fields;
};
struct Sig_fn_12_ABDC_SJInterface {
 union {
 unsigned char padding_extent[48];
 struct { unsigned char padding_get_chunk[24]; void (*get_chunk)(Sig_fn_12_ABDC_SJ *, int, int, Sig_fn_12_ABDC_SJCK *); } view_get_chunk;
 struct { unsigned char padding_unget_chunk[28]; void (*unget_chunk)(Sig_fn_12_ABDC_SJ *, int, Sig_fn_12_ABDC_SJCK *); } view_unget_chunk;
 struct { unsigned char padding_put_chunk[32]; void (*put_chunk)(Sig_fn_12_ABDC_SJ *, int, Sig_fn_12_ABDC_SJCK *); } view_put_chunk;
 } fields;
};
struct Sig_fn_12_ABDC_SJ {
 union { unsigned char padding_extent[4]; struct { const Sig_fn_12_ABDC_SJInterface *interface; } view_interface; } fields;
};
typedef struct Sig_fn_12_9744_MovieState {
 u8 _pad10[0x10]; s32 field_10; s32 field_14; s32 field_18; s32 field_1c;
} Sig_fn_12_9744_MovieState;
typedef struct Sig_fn_12_9730_MovieModule {
 u8 _pad0[0x318]; u32 field_318; u32 field_31c; u32 field_320;
} Sig_fn_12_9730_MovieModule;
typedef u32 (*fn_12_ABDC_Fn0)(u32, u32, u32, u32);
extern void fn_12_9730(Sig_fn_12_9730_MovieModule *);
extern void fn_12_9744(Sig_fn_12_9744_MovieState *);
extern u32 fn_800589BC(Sig_fn_12_ABDC_SJCK *, s32, Sig_fn_12_ABDC_SJCK *, Sig_fn_12_ABDC_SJCK *);
void fn_12_ABDC(Sig_fn_12_ABDC_MPVContext *arg0, Sig_fn_12_ABDC_SJ *arg1, u32 arg2);

/* --- rel/movie_module/MPV_MoveChunk.c --- */
int MPV_MoveChunk(SJ *stream, int channel, int size);
